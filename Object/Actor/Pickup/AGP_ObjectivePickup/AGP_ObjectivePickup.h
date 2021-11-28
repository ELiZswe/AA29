// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AGP_ObjectivePickup.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_ObjectivePickup : public APickup
{
	GENERATED_BODY()
public:
	AAGP_ObjectivePickup();

	
	UPROPERTY()																		bool bInactiveForRound;						//var bool bInactiveForRound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										bool bHideOnRoundInactive;					//var() bool bHideOnRoundInactive;
	UPROPERTY()																		uint8 LastHolderTeamIndex;					//var byte LastHolderTeamIndex;
	UPROPERTY()																		FRotator OriginalRotation;					//var Object.Rotator OriginalRotation;
	UPROPERTY()																		FVector OriginalPrePivot;					//var FVector OriginalPrePivot;
	UPROPERTY()																		FVector OriginalLocation;					//var FVector OriginalLocation;
	UPROPERTY()																		bool bPickupMoved;							//var bool bPickupMoved;
	UPROPERTY()																		bool bStartingLocAndRotSaved;				//var bool bStartingLocAndRotSaved;
	UPROPERTY()																		bool bBroadcastPickupMsgs;					//var bool bBroadcastPickupMsgs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										FString FallBackDropMsg;					//var() localized string FallBackDropMsg;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										FString OPFORDropMsg;						//var() localized string OPFORDropMsg;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										FString USDropMsg;							//var() localized string USDropMsg;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										FString OPFORPickupMsg;						//var() localized string OPFORPickupMsg;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										FString USPickupMsg;						//var() localized string USPickupMsg;
	UPROPERTY()																		bool bWaitingFirstPickup;					//var bool bWaitingFirstPickup;
	UPROPERTY()																		bool bDisplayTargetingInfo;					//var bool bDisplayTargetingInfo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										UStaticMesh* AttachmentEnemyStaticMesh;		//var() StaticMesh AttachmentEnemyStaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										UStaticMesh* AttachmentFriendlyStaticMesh;	//var() StaticMesh AttachmentFriendlyStaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										UStaticMesh* EnemyStaticMesh;				//var() StaticMesh EnemyStaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										UStaticMesh* FriendlyStaticMesh;			//var() StaticMesh FriendlyStaticMesh;
	UPROPERTY()																		AAGP_ObjectivePickup* PlacedPickup;			//var AGP_ObjectivePickup PlacedPickup;
	UPROPERTY()																		AAGP_Objective* Objective;					//var AGP_Objective Objective;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryObjective")	FName InventoryTag;							//var(InventoryObjective) name InventoryTag;


	virtual void BeginPlay() override;

	void PostBeginPlay();
	void Destroyed();
	void SetupCopy(AInventory* Copy, APawn* Other);
	void SetInactiveForRound(bool bInactive);
	void SetInactive(bool new_inactive);
	void SpawnCopy(APawn* Other, bool bRealInventory);
	void BroadcastDropMessages(APawn* LastHolder);
	void BroadcastPickupMessages(APawn* NewHolder);
	void InitDroppedPickupFor(AInventory* Inv, bool bFreeze);
	void SetPlacedPickup(AAGP_ObjectivePickup* new_placed_pickup);
	void setObjective(AAGP_Objective* new_objective);
	void SetTeamOwner(uint8 new_team_owner);
	void RegisterSelfWithObjective();
	void ResetPickupLocation();
	void CheckPickupLocation();
	void MatchEnding();
	void PostNetBeginPlay();
	void MatchStarting();
	bool MaybeSetStaticMesh();

};
