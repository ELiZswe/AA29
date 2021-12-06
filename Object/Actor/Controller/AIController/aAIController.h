// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Controller.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/AA29.h"

#include "AA29/Inventory/Weapon/Weapon.h"
#include "aAIController.generated.h"

class AAIScript;
class ANavigationPoint;
class AMover;
class AReachSpec;

UCLASS()
class AA29_API AaAIController : public AController
{
	GENERATED_BODY()
public:

	AaAIController();

	UPROPERTY()										float Skill;						//var float Skill;
	UPROPERTY()										AAIScript* MyScript;				//var AIScript MyScript;
	UPROPERTY()										bool bPlannedJump;					//var bool bPlannedJump;
	UPROPERTY()										bool bAdjustFromWalls;				//var bool bAdjustFromWalls;
	UPROPERTY()										bool bHunting;						//var bool bHunting;

	//from Controller
	UPROPERTY()										bool bAdvancedTactics;				//var bool bAdvancedTactics;
	UPROPERTY()										bool bSlowerZAcquire;				//var bool bSlowerZAcquire;
	UPROPERTY()										bool bProp;							//var bool bProp;

	void WaitToSeeEnemy();
	void NotifyFlashBanged(float Duration, float VisIntensity, float AudIntensity);
	void PreBeginPlay();
	void Reset();
	float RateWeapon(AWeapon* W);
	void Trigger(AActor* Other, APawn* EventInstigator);
	void WeaponFireAgain(float RefireRate, bool bFinishedFire);
	void TriggerScript(AActor* Other, APawn* EventInstigator);
	//void DisplayDebug (UCanvas Canvas, float YL, float YPos);
	int32 AdjustDesireFor(APickup* p);
	void GetFacingDirection();
	void AdjustView(float DeltaTime);
	void SetOrders(FName NewOrders, AController* OrderGiver);
	void GetOrderObject();
	void GetOrders();
	void PrepareForMove(ANavigationPoint* Goal, AReachSpec* Path);
	void WaitForMover(AMover* M);
	void MoverFinished();
	void UnderLift(AMover* M);
	bool PriorityObjective();
	void Startle(AActor* A);
	void NotifyBuzzedByBullet(AActor* aShooter);
	void NotifyTakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, UaDamageType DamageType, FBoneInfo Bone);
	void RestartNPC();

	//From Controller:
	float Desireability(APickup* p);
};
