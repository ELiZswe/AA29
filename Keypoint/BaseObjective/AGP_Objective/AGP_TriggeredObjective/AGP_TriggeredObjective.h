// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/BillboardComponent.h"
#include "Components/CapsuleComponent.h."
#include "Components/SphereComponent.h."


#include "AA29/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AGP_TriggeredObjective.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_TriggeredObjective : public AAGP_Objective
{
	GENERATED_BODY()
public:
	AAGP_TriggeredObjective(const FObjectInitializer& objectInitializer);

	UPROPERTY()										APawn* StoredInstigator;							//var Pawn StoredInstigator;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FName RescueTargetTag;								//var() name RescueTargetTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bMustBeNPC;									//var() bool bMustBeNPC;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TSubclassOf<class AInventory> MustBeHolding;		//var() class<Inventory> MustBeHolding;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TSubclassOf<class AInventory> MustHaveInInventory;	//var() class<Inventory> MustHaveInInventory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float fTimeToTrigger;								//var() float fTimeToTrigger;


	void Reset();
	void SideReset();
	virtual float GetPercentComplete() override;
	bool CanAccomplish(APawn* p);
	void UnTrigger(AActor* Other, APawn* _Instigator);
	void UnTouch(AActor* Other);
	void Touch(AActor* Other);
	void Trigger(AActor* Other, APawn* _Instigator);

	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// Sprite Component
	//class UBillboardComponent* SpriteComponent;

	// Capsule Component
	UPROPERTY(VisibleAnywhere)		class UCapsuleComponent* Capsule;
	
	/** sphere component */
	//UPROPERTY(VisibleAnywhere)		class USphereComponent* Sphere1;

	void ToggleLight();

	UFUNCTION()				void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()				void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
