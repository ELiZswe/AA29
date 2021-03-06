// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character.h"
#include "NPC_Ambient.generated.h"

class AAGP_Objective;
UCLASS()
class ANPC_Ambient : public AAGP_Character
{
	GENERATED_BODY()
public:
	ANPC_Ambient();

	UPROPERTY(EditAnywhere)				int32			nNPCusedtime;					//var() int nNPCusedtime;
	UPROPERTY(EditAnywhere)				int32			nNPCthinktime;					//var() int nNPCthinktime;
	UPROPERTY(EditAnywhere)				bool			bNPCused;						//var() bool bNPCused;
	UPROPERTY(EditAnywhere)				bool			bPlayDyingAnimation;			//var() bool bPlayDyingAnimation;
	UPROPERTY(EditAnywhere)				bool			bUseKarmaDeathAnimation;		//var() bool bUseKarmaDeathAnimation;
	UPROPERTY()							int32			InitialKillHealth;				//var int InitialKillHealth;
	UPROPERTY()							AAGP_Objective*	DamageObjective;				//var AGP.AGP_Objective DamageObjective;

	void PossessedBy(AController* C);
	void BeginPlay();

	void PostBeginPlay();
	void ConfigureLinkDamage();
	//void TakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial);
	void UndoDeath();
	void MatchStarting();
	void PostNetBeginPlay();
	void DoAnimLoop();
	bool IsFriend(APawn* Other);
	void LoadSkinsAndMeshes();
	void SetSkinsAndMeshes();
	bool UsedBy(APawn* User);
	void Touch(AActor* Other);
	void MatchEnding();
};
