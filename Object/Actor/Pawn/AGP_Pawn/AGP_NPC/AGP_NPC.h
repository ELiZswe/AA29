// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/AA29.h"
#include "AGP_NPC.generated.h"

UCLASS()
class AAGP_NPC : public AAGP_Pawn
{
	GENERATED_BODY()
public:
	AAGP_NPC();

	UPROPERTY()					FRotator				OldRotation1;			//var Object.Rotator OldRotation1;
	UPROPERTY()					bool					bInitialized;			//var bool bInitialized;
	UPROPERTY(EditAnywhere)		TArray<FAttachObject>	Attachments;			//var() array<AttachObject> Attachments;

	void MatchStarting();
	void DoAnimLoop();
	void PostBeginPlay();
	void InitPlayerRefs();
	FRotator LookRotation(FVector LookActorLoc, FVector TargetActorLoc);
	float infront(FVector vec, APawn* me);
	void SetAttachments();
	//void TakeDamage(int32 Damage, Pawn instigatedBy, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, optional FBoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial);
};
