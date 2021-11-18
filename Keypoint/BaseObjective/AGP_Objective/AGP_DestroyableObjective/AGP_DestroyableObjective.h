// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AGP_DestroyableObjective.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_DestroyableObjective : public AAGP_Objective
{
	GENERATED_BODY()
public:
	AAGP_DestroyableObjective(const FObjectInitializer& objectInitializer);

	
	UPROPERTY()																AActor* NotifyInstigatorActor;				//var Actor NotifyInstigatorActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								AActor* NotifyInstigatorOfActor;			//var() name NotifyInstigatorOfActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								bool bWatchForGrenades;						//var() bool bWatchForGrenades;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageType")	TArray<UDamageType*> DamageTypes;			//var(DamageType) array<class<DamageType> > DamageTypes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageType")	bool bCheckDamageType;						//var(DamageType) bool bCheckDamageType;
	UPROPERTY()																int32 Health;								//var int Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								int32 StartingHealth;						//var() int StartingHealth;
	UPROPERTY()																int32 AccumulatedDamage;					//var int AccumulatedDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								FName DestroyEvent;							//var() name DestroyEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								int32 DamageEventThreshold;					//var() int DamageEventThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								FName TakeDamageEvent;						//var() name TakeDamageEvent;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)								UStaticMeshComponent* StaticMesh;

	void BeginPlay();
	void Reset();
	void SideReset();
	virtual float GetPercentComplete() override;
	void ShouldTakeDamage(UaDamageType* DamageType);
	
	//void TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType*  DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UTexture2D* HitMaterial);
	void grenadeNotifier(AActor* Explosive, UaDamageType* DamageType, AController* KillerController);

};
