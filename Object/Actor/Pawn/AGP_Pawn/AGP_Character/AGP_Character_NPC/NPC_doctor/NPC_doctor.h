// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/AGP_Character_NPC.h"
#include "NPC_doctor.generated.h"

class AAGP_Objective;
UCLASS()
class ANPC_doctor : public AAGP_Character_NPC
{
	GENERATED_BODY()
public:
	ANPC_doctor();

	UPROPERTY(EditAnywhere)			bool				NPC_DamageOn;			//var() bool NPC_DamageOn;
	UPROPERTY()						AAGP_Objective*		DamageObjective;		//var AAGP_Objective* DamageObjective;
	UPROPERTY()						int32				InitialKillHealth;		//var int32 InitialKillHealth;
	UPROPERTY(EditAnywhere)			bool				bNPCused;				//var() bool bNPCused;
	UPROPERTY(EditAnywhere)			int32				nNPCthinktime;			//var() int32 nNPCthinktime;
	UPROPERTY(EditAnywhere)			int32				nNPCusedtime;			//var() int32 nNPCusedtime;
	UPROPERTY()						APawn*				LastUsedBy;				//var APawn* LastUsedBy;
	UPROPERTY()						FVector				vStartLocation;			//var Vector vStartLocation;
	UPROPERTY()						FRotator			vStartRotation;			//var Rotator vStartRotation;

	void PostBeginPlay();
	//void TakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial)
	void UndoDeath();
	void MatchStarting();
	void PostNetBeginPlay();
	void DoAnimLoop();
	bool IsFriend(APawn* Other);
	bool UsedBy(APawn* User);
	void Touch(AActor* Other);
};
