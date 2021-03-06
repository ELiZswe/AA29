// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "FSTS_PlayerController.generated.h"

class AFSTS_EL_Utilities;

UCLASS()
class AFSTS_PlayerController : public AHumanController
{
	GENERATED_BODY()
public:
	AFSTS_PlayerController();

	UPROPERTY()					bool					bUsedCheats;			//var bool bUsedCheats;
	UPROPERTY()					AFSTS_EL_Utilities*		MasterScript;			//var FSTS_EL_Utilities MasterScript;
	UPROPERTY()					bool					bDebugScripts;			//var bool bDebugScripts;
	UPROPERTY()					float					UseTraceDistance;		//var float UseTraceDistance;
	UPROPERTY()					bool					bAllowThrowWeapon;		//var bool bAllowThrowWeapon;

	void PostBeginPlay();
	void SetMasterScriptEventLab();
	void ThrowWeapon();
	void Fire(float F);
	void Action();
	void LeanLeft();
	void LeanRight();
	void UseTrace();
	void MannequinTrace(AActor* HitActor, FBoneInfo HitBone);
	void MedicalPickupTrace(AActor* HitActor);
	void DrillSergeantUsed(AActor* Sarge);
	void DevMode(bool bSet);
	bool IsUsingCheats();
	void MPCheat(FString cheat);
};
