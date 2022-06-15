// Gülsen TUNA
// UE4 Version 4.7
#include "LightSwitchButtonActor.h"

#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"



// Sets default values
ALightSwitchButtonActor::ALightSwitchButtonActor()
{
	LightIntensity = 3000.0f;

	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Point Light"));
	PointLight->Intensity = LightIntensity;
	PointLight->SetVisibility(true);
	RootComponent = PointLight;

	LightSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Light Sphere Component"));
	LightSphere->InitSphereRadius(300.0f);
	LightSphere->SetCollisionProfileName(TEXT("Trigger"));
	LightSphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore); // Ignore collision with pawns
	LightSphere->SetupAttachment(RootComponent);
}

void ALightSwitchButtonActor::ToggleLight()
{
	PointLight->ToggleVisibility();
}
