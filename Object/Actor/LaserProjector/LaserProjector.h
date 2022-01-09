// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/MyEnums.h"
#include "LaserProjector.generated.h"

class ADynamicProjector;

UCLASS()
class ALaserProjector : public AActor
{
	GENERATED_BODY()
	
public:	
	ALaserProjector();

	UPROPERTY()										ADynamicProjector* LasProj; 		//var DynamicProjector LasProj;
	UPROPERTY()										UMaterialInstance* LasTexture; 			//var Material LasTexture;
	UPROPERTY()										ELaserBaseType BaseType; 				//var ELaserBaseType BaseType;
	UPROPERTY()										bool bIsOn; 							//var bool bIsOn

	void Destroyed();
	void CreateLaserProjector();
	void TurnOn(AActor* ActorToAttachTo);
	void TurnOff();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
