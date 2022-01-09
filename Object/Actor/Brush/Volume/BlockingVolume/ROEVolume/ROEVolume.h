// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Brush/Volume/AA2_Volume.h"
#include "ROEVolume.generated.h"

class AAGP_Objective;

UCLASS()
class AROEVolume : public AAA2_Volume
{
	GENERATED_BODY()
public:

	AROEVolume();

	UPROPERTY()														AAGP_Objective* DamageObjective;				//var AGP_Objective DamageObjective;
	UPROPERTY(EditAnywhere, Category = "LinkDamage")				FString sTextToDisplay;							//var(LinkDamage) string sTextToDisplay;
	UPROPERTY(EditAnywhere, Category = "LinkDamage")				float DamageMultiplier;							//var(LinkDamage) float DamageMultiplier;
	UPROPERTY(EditAnywhere, Category = "LinkDamage")				int32 DefaultDamage;							//var(LinkDamage) int DefaultDamage;
	UPROPERTY(EditAnywhere, Category = "LinkDamage")				int32 KillHealth;								//var(LinkDamage) int KillHealth;
	UPROPERTY(EditAnywhere, Category = "LinkDamage")				FName KillEvent;								//var(LinkDamage) name KillEvent;
	UPROPERTY(EditAnywhere, Category = "LinkDamage")				FName DamageTag;								//var(LinkDamage) name DamageTag;
	UPROPERTY(EditAnywhere, Category = "LinkDamage")				FName DamageEvent;								//var(LinkDamage) name DamageEvent;

	//From BlockingVolume
	UPROPERTY(EditAnywhere)											TArray<AActor*> BlockedClasses;			//var() array<class<Actor> > BlockedClasses;
	UPROPERTY(EditAnywhere)											bool bClassBlocker;						//var() bool bClassBlocker;
	UPROPERTY(EditAnywhere)											bool bClampFluid;						//var() bool bClampFluid;


	void PostBeginPlay();
	void ConfigureLinkDamage();
	//void TakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, Controller KillerController, Actor ResponsibleActor, Material HitMaterial);

};
