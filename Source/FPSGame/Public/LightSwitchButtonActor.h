// Gülsen TUNA
// UE4 Version 4.7

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LightSwitchButtonActor.generated.h"

UCLASS()
class FPSGAME_API ALightSwitchButtonActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALightSwitchButtonActor();

	// declare point light component
	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
	class UPointLightComponent* PointLight;

	// declare sphere component
	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
	class USphereComponent* LightSphere;

	// declare light intensity variable
	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
	float LightIntensity;

	// declare ToggleLight function
	UFUNCTION(BlueprintCallable, Category = "Light Switch")
	void ToggleLight();

};
