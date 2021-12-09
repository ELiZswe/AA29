// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/FSTS_EventLab/EL_VehicleTraining/EL_VehicleTraining.h"
#include "EL_VehicleTraining_Gunner.generated.h"

class ATargetManager;
class ACROWS_HMMWV_Gunner;
class UFSTS_PlayerHint;
class AAGP_VehicleNode;

UCLASS()
class AEL_VehicleTraining_Gunner : public AEL_VehicleTraining
{
	GENERATED_BODY()
public:
	AEL_VehicleTraining_Gunner();

	UPROPERTY()						bool bPlayerInCrows;									//var bool bPlayerInCrows;
	UPROPERTY()						ATargetManager* StationaryTargetManager;				//var AGP_Gameplay.TargetManager StationaryTargetManager;
	UPROPERTY()						ATargetManager* MobileTargetManager;					//var AGP_Gameplay.TargetManager MobileTargetManager;
	UPROPERTY()						ACROWS_HMMWV_Gunner* TrainingVehicle;					//var CROWS_HMMWV_Gunner TrainingVehicle;
	UPROPERTY()						AActor* tower;											//var AActor* tower;
	UPROPERTY()						int32 ShotsFired;										//var int32 ShotsFired;
	UPROPERTY()						float lastCommentMade;									//var float lastCommentMade;
	UPROPERTY()						int32 finalScore;										//var int32 finalScore;
	UPROPERTY()						bool bCheckAim;											//var bool bCheckAim;
	UPROPERTY()						bool bPointingAtRange;									//var bool bPointingAtRange;
	UPROPERTY()						FVector RangeStart;										//var Vector RangeStart;
	UPROPERTY()						FVector RangeBounds;									//var Vector RangeBounds;
	UPROPERTY()						FVector RangeBoundsPerp;								//var Vector RangeBoundsPerp;
	UPROPERTY()						int32 WarningNumber;									//var int32 WarningNumber;
	UPROPERTY()						float LastWarningTime;									//var float LastWarningTime;
	UPROPERTY()						UMaterialInstance* Movie;								//var MovieTexture Movie;
	UPROPERTY()						float MovieWidth;										//var float MovieWidth;
	UPROPERTY()						float MovieHeight;										//var float MovieHeight;
	UPROPERTY()						UFSTS_PlayerHint* EnterTheVehicleHint;					//var FSTS_PlayerHint EnterTheVehicleHint;
	UPROPERTY()						UFSTS_PlayerHint* UseTheSeatbeltHint;					//var FSTS_PlayerHint UseTheSeatbeltHint;
	UPROPERTY()						UFSTS_PlayerHint* ActivateCROWSHint;					//var FSTS_PlayerHint ActivateCROWSHint;
	UPROPERTY()						UFSTS_PlayerHint* ZoomHint;								//var FSTS_PlayerHint ZoomHint;
	UPROPERTY()						UFSTS_PlayerHint* LaserHint;							//var FSTS_PlayerHint LaserHint;
	UPROPERTY()						UFSTS_PlayerHint* FireHint;								//var FSTS_PlayerHint FireHint;
	UPROPERTY()						UFSTS_PlayerHint* UseInstructorHint;					//var FSTS_PlayerHint UseInstructorHint;
	UPROPERTY()						bool bTalkedToFrank;									//var bool bTalkedToFrank;
	UPROPERTY()						FString MovieMessage;									//var FString MovieMessage;
	UPROPERTY()						float TargetStartTime;									//var float TargetStartTime;
	UPROPERTY()						float HoverTimeToShowHint;								//var float HoverTimeToShowHint;
	UPROPERTY()						bool bHovering;											//var bool bHovering;
	UPROPERTY()						APathNode* EntryPoint;									//var PathNode EntryPoint;
	UPROPERTY()						TArray<FTargetInfo> TargetInfos;						//var TargetInfo TargetInfos[9];


	void PostInit();
	void AssignSgt();
	AAGP_VehicleNode* GetVehicleNode(FName nodeTag);
	void AssignTrainingVehicle();
	bool AGP_Vehicle_Spawned(AAGP_VehicleFactory* SpawningFactory, AAGP_Vehicle* NewVehicle, FString Parms);
	bool VehiclePosition_Entered(AVehiclePosition* Position, AActor* Controller, FString Parms);
	bool VehiclePosition_Exited(AVehiclePosition* Position, AActor* Controller, FString Parms);
	void GetInVehicle();
	void SetPath(FName startTag, FName endTag);
	void StartDriving(bool startWithNext);
	bool Vehicle_At(AAGP_Vehicle* Vehicle, AActor* Controller, FString NavigationTag);
	void RetryCourse();
	void Timer();
	void SetRange(FName boundsTag);
	bool PointingAtRange();
	bool VehicleWeapon_Fire(AVehicleWeapon* NotifyActor, AActor* Instigator, FString Parms);
	bool AGP_NPC_Damaged(AAGP_NPC* NotifyActor, AController* Instigator);
	bool AGP_NPC_Died(AAGP_NPC* NotifyActor, AController* Instigator);
	bool CloseToFrank();
	bool HasTalkedToFrank();
	bool CloseToVehicle();
	bool InCrows();
	bool IsCrowsActive();
	bool IsWearingSeatbelt();
	bool AtStationaryRange();
	bool AimingAtTarget();
	bool HasLased();
	bool HasZoomed();
	void SetUpHints();
};
