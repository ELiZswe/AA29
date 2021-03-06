// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBasePreCrewedVehicleController/NPCBasePreCrewedVehicleControlle.h"
#include "NPCPackbotVehicleController.generated.h"

class ARoadPathNode;

class AAGP_HUD;
class AAGP_Weapon;
class APathNode;
class AThrowWeaponPickup;
UCLASS()
class ANPCPackbotVehicleController : public ANPCBasePreCrewedVehicleControlle
{
	GENERATED_BODY()
public:
	ANPCPackbotVehicleController();

	UPROPERTY()			TArray<FName>			nameArmPositions;							//var TArray<FName> nameArmPositions;
	UPROPERTY()			int32					iCurrentArmPosition;							//var int32 iCurrentArmPosition;

	void AdjustStateByConfidenceLevel();
	void DisplayDebug(UCanvas* C, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos);
	void DisplayDebugNoSpam(AAGP_HUD* AGPHUD, UCanvas* C, float& YL, float& YPos, FColor NewColor);
	void Start();
	void InitVehicle();
	APathNode* GetPathnodeByTagString(FString sTag);
	void PreloadPathNodeList();
	void NotifyEnemyGrenadeClose(AThrowWeaponPickup* twpGrenade);
	void NotifyFlashBanged(float Duration, float VisIntensity, float AudIntensity);
	void NotifyEnemyVehicleSpotted(FVector vLocation);
	ARoadPathNode* FindNextDrivingPatrolPathNode();
	//void Possess(APawn* aPawn);
	//void UnPossess();
	void NotifyTrigger(AActor* Other, APawn* EventInstigator);
	void NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, FVector vSoundLocation);
	void NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard);
	void ChangeOrders(int32 iNewOrders);
	void ForceMoveTo(FName DestinationTag);
	void Timer_CheckEmptyVehicleLocations();
	void ArmMovementTimer();
	float DirectionToGoal(FVector vLocGoal);
	FVector GetAvoidanceLocation();
	void DebugDumpRoute();
	void NPCLog(FString sLogText);
	void DebugMarkNextNode(APathNode* pnNext);
};
