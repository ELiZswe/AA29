// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AGP_DestroyableObjective.generated.h"

class UaDamageType;

UCLASS()
class AAGP_DestroyableObjective : public AAGP_Objective
{
	GENERATED_BODY()
public:
	AAGP_DestroyableObjective(const FObjectInitializer& objectInitializer);
	
	UPROPERTY()											AActor* NotifyInstigatorActor;				//var Actor NotifyInstigatorActor;
	UPROPERTY(EditAnywhere)								AActor* NotifyInstigatorOfActor;			//var() name NotifyInstigatorOfActor;
	UPROPERTY(EditAnywhere)								bool bWatchForGrenades;						//var() bool bWatchForGrenades;
	UPROPERTY(EditAnywhere, Category = "DamageType")	TArray<UaDamageType*> DamageTypes;			//var(DamageType) array<class<DamageType> > DamageTypes;
	UPROPERTY(EditAnywhere, Category = "DamageType")	bool bCheckDamageType;						//var(DamageType) bool bCheckDamageType;
	UPROPERTY()											int32 Health;								//var int Health;
	UPROPERTY(EditAnywhere)								int32 StartingHealth;						//var() int StartingHealth;
	UPROPERTY()											int32 AccumulatedDamage;					//var int AccumulatedDamage;
	UPROPERTY(EditAnywhere)								FName DestroyEvent;							//var() name DestroyEvent;
	UPROPERTY(EditAnywhere)								int32 DamageEventThreshold;					//var() int DamageEventThreshold;
	UPROPERTY(EditAnywhere)								FName TakeDamageEvent;						//var() name TakeDamageEvent;
	// UPROPERTY(EditAnywhere)								UStaticMeshComponent* StaticMesh;

	void PostBeginPlay();
	void Reset();
	void SideReset();
	virtual float GetPercentComplete() override;
	bool ShouldTakeDamage(UaDamageType* DamageType);
	//void TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType*  DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UTexture2D* HitMaterial);
	void grenadeNotifier(AActor* Explosive, UaDamageType* DamageType, AController* KillerController);
};
