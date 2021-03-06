// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/AGP_Character_NPC.h"
#include "NPC_Actionable.generated.h"

class AAGP_Objective;

UCLASS()
class ANPC_Actionable : public AAGP_Character_NPC
{
	GENERATED_BODY()
public:
	ANPC_Actionable();

	UPROPERTY()					AAGP_Objective*			DamageObjective;		//var AAGP_Objective* DamageObjective;
	UPROPERTY()					int32					InitialKillHealth;		//var int32 InitialKillHealth;
	UPROPERTY(EditAnywhere)		bool					bNPCused;				//var() bool bNPCused;
	UPROPERTY(EditAnywhere)		int32					nNPCthinktime;			//var() int32 nNPCthinktime;
	UPROPERTY(EditAnywhere)		int32					nNPCusedtime;			//var() int32 nNPCusedtime;

	void PostBeginPlay();
	void ConfigureLinkDamage();
	//void TakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, Actor.BoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial);
	void UndoDeath();
	void MatchStarting();
	void PostNetBeginPlay();
	void DoAnimLoop();
	bool IsFriend(APawn* Other);
	void LoadSkinsAndMeshes();
	void SetSkinsAndMeshes();
	bool UsedBy(APawn* User);
	void Touch(AActor* Other);
};
