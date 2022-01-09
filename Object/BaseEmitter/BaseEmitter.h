// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseEmitter.generated.h"

class UaDamageType;

UCLASS()
class UBaseEmitter : public UObject
{
	GENERATED_BODY()
public:
	UBaseEmitter();

	UPROPERTY(EditAnywhere, Category = "Fade")					bool bFadeOnCollide;					//var(Fade) bool bFadeOnCollide;
	UPROPERTY(EditAnywhere, Category = "Rendering")				int32 MinFramesBeforeDeath;				//var(Rendering) int MinFramesBeforeDeath;
	UPROPERTY(EditAnywhere, Category = "Damage")				float fDamageMomentum;					//var(Damage) float fDamageMomentum;
	UPROPERTY(EditAnywhere, Category = "Damage")				int32 iDamageAmount;					//var(Damage) int iDamageAmount;
	UPROPERTY(EditAnywhere, Category = "Damage")				UaDamageType* cDamageType;				//var(Damage) class<DamageType> cDamageType;
	UPROPERTY(EditAnywhere, Category = "Wind")					float fWindFactor;						//var(Wind) float fWindFactor;
	UPROPERTY(EditAnywhere, Category = "MuzzleFlash")			int32 iFlashSpawnCount;					//var(MuzzleFlash) int iFlashSpawnCount;
};
