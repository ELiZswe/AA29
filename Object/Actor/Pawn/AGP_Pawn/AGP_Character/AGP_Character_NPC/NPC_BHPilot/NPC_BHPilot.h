// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/AGP_Character_NPC.h"
#include "NPC_BHPilot.generated.h"

class AAGP_Objective;
UCLASS()
class ANPC_BHPilot : public AAGP_Character_NPC
{
	GENERATED_BODY()
public:
	ANPC_BHPilot();

	UPROPERTY()			AAGP_Objective*		DamageObjective;		//var AAGP_Objective* DamageObjective;
	UPROPERTY()			int32				InitialKillHealth;		//var int32 InitialKillHealth;
	UPROPERTY()			FVector				vStartLocation;			//var Vector vStartLocation;
	UPROPERTY()			FRotator			vStartRotation;			//var Rotator vStartRotation;

	void SetAnimAction(FName NewAction);
	void SetLoopingAnimAction(FName NewAction);
	void PostBeginPlay();
	void ConfigureLinkDamage();
	//void TakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial);
	void UndoDeath();
	void MatchStarting();
	void PostNetBeginPlay();
	void DoAnimLoop();
	bool IsFriend(APawn* Other);
	void Touch(AActor* Other);
	void LoadSkinsAndMeshes();
	void SetSkinsAndMeshes();
	void ActivateLinkedObjective(APawn* User);
	bool UsedBy(APawn* User);
	void AnimateRunning();
	void AnimateWalking();
};
