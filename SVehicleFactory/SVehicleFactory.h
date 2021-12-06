// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SVehicleFactory.generated.h"

class ANavigationPoint;
class USceneComponent;
class UBillboardComponent;

UCLASS()
class AA29_API ASVehicleFactory : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASVehicleFactory();

	UPROPERTY()														ANavigationPoint* myMarker;								//var NavigationPoint myMarker;
	UPROPERTY()														int32 VehicleCount;										//var int VehicleCount;
	UPROPERTY(EditAnywhere)											int32 MaxVehicleCount;									//var() int MaxVehicleCount;
	//UPROPERTY(EditAnywhere)											int32 VehicleClass;									//var() class<Vehicle> VehicleClass;


	UPROPERTY(EditAnywhere)											USceneComponent* Root;
	UPROPERTY()														UTexture2D* Texture;
	UPROPERTY()														UBillboardComponent* SpriteComponent;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void LoadEditorIcon();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
