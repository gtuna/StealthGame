// Fill out your copyright notice in the Description page of Project Settings.
#include "FPSObjectiveActor.h"

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "FPSCharacter.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AFPSObjectiveActor::AFPSObjectiveActor()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly); // only detect overlap, but don't react
	SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore); // ignore all collision responses
	SphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap); // only react to overlap with pawns !
	SphereComp->SetupAttachment(MeshComp);

	SetReplicates(true);
	
}

// Called when the game starts or when spawned
void AFPSObjectiveActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFPSObjectiveActor::PlayEffects()
{
	UGameplayStatics::SpawnEmitterAtLocation( this, PickupFX, GetActorLocation());
}

void AFPSObjectiveActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	PlayEffects();

	if (HasAuthority())
	{
		AFPSCharacter* MyCharacter = Cast<AFPSCharacter>(OtherActor); //any number of actors can overlap, so we need to cast to our pawn/character
		if (MyCharacter)
		{
			// when this variable sets, all the other clients receive the change. we set it to replicated and add GetLifetimeReplicatedProps func 
			MyCharacter->bIsCarryingObjective = true;

			Destroy();
		}		
	}
}

