// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/MyEnums.h"
#include "LaserProjector.generated.h"

UCLASS()
class AA29_API ALaserProjector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaserProjector();


	//UPROPERTY()										ADynamicProjector* LasProj; 		//var DynamicProjector LasProj;
	UPROPERTY()										UMaterialInstance* LasTexture; 			//var Material LasTexture;
	UPROPERTY()										ELaserBaseType BaseType; 				//var ELaserBaseType BaseType;
	UPROPERTY()										bool bIsOn; 							//var bool bIsOn

	void Destroyed();
	void CreateLaserProjector();
	void TurnOn(AActor* ActorToAttachTo);
	void TurnOff();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
