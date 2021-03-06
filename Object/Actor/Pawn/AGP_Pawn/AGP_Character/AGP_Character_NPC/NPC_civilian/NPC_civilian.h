// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/AGP_Character_NPC.h"
#include "NPC_civilian.generated.h"

class AAGP_Objective;
UCLASS()
class ANPC_civilian : public AAGP_Character_NPC
{
	GENERATED_BODY()
public:
	ANPC_civilian();

	UPROPERTY(EditAnywhere)			bool NPC_DamageOn;							//var() bool NPC_DamageOn;
	UPROPERTY()						AAGP_Objective* DamageObjective;			//var AGP_Objective DamageObjective;
	UPROPERTY()						int32 InitialKillHealth;					//var int32 InitialKillHealth;
	UPROPERTY(EditAnywhere)			bool bNPCused;								//var() bool bNPCused;
	UPROPERTY(EditAnywhere)			int32 nNPCthinktime;						//var() int32 nNPCthinktime;
	UPROPERTY(EditAnywhere)			int32 nNPCusedtime;							//var() int32 nNPCusedtime;
	UPROPERTY()						APawn* LastUsedBy;							//var Pawn LastUsedBy;
	UPROPERTY()						FVector vStartLocation;						//var Vector vStartLocation;
	UPROPERTY()						FRotator vStartRotation;					//var Rotator vStartRotation;
	UPROPERTY()						bool bDestroying;							//var bool bDestroying;

	void BeginPlay();
	void PostBeginPlay();
	void ConfigureLinkDamage();
	//void TakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, Controller KillerController, Actor ResponsibleActor, Material HitMaterial);
	void UndoDeath();
	void MatchStarting();
	void PostNetBeginPlay();
	void DoAnimLoop();
	bool IsFriend(APawn* Other);
	void LoadSkinsAndMeshes();
	void SetSkinsAndMeshes();
	//bool UsedBy(APawn* User);
	void Touch(AActor* Other);
	void AnimateRunning();
	void AnimateSprinting();
	void AnimateCrouchWalking();
	void AnimateWalking();
};
