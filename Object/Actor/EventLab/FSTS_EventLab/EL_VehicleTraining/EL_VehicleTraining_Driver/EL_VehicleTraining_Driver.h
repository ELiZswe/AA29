// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/FSTS_EventLab/EL_VehicleTraining/EL_VehicleTraining.h"
#include "EL_VehicleTraining_Driver.generated.h"

class AFSTS_Objective;
class AVehicle;
class UFSTS_PlayerHint;

/**
 * 
 */
UCLASS()
class AA29_API AEL_VehicleTraining_Driver : public AEL_VehicleTraining
{
	GENERATED_BODY()
public:
	AEL_VehicleTraining_Driver();

	UPROPERTY()						bool bShoutRandomly;								//var bool bShoutRandomly;
	UPROPERTY()						int32 NextCheckpoint;								//var int32 NextCheckpoint;
	UPROPERTY()						int32 LastCheckpoint;								//var int32 LastCheckpoint;
	UPROPERTY()						FString CheckpointString1;							//var localized FString CheckpointString1;
	UPROPERTY()						FString CheckpointString2;							//var localized FString CheckpointString2;
	UPROPERTY()						bool bPlayerInVehicle;								//var bool bPlayerInVehicle;
	UPROPERTY()						float VehicleStuckTime;								//var float VehicleStuckTime;
	UPROPERTY()						FString RestartMessage;								//var FString RestartMessage;
	UPROPERTY(EditAnywhere)			FName StaticGunnerVehicleTag;						//var() FName StaticGunnerVehicleTag;
	UPROPERTY(EditAnywhere)			FName MobileGunnerVehicleTag;						//var() FName MobileGunnerVehicleTag;
	UPROPERTY()						AVehicle* StaticGunnerVehicle;						//var Vehicle StaticGunnerVehicle;
	UPROPERTY()						AVehicle* MobileGunnerVehicle;						//var Vehicle MobileGunnerVehicle;
	UPROPERTY()						UFSTS_PlayerHint* UseInstructorHint;				//var FSTS_PlayerHint UseInstructorHint;
	UPROPERTY()						UFSTS_PlayerHint* EnterTheVehicleHint;				//var FSTS_PlayerHint EnterTheVehicleHint;
	UPROPERTY()						UFSTS_PlayerHint* UseTheSeatbeltHint;				//var FSTS_PlayerHint UseTheSeatbeltHint;
	UPROPERTY()						UFSTS_PlayerHint* StartTheCarHint;					//var FSTS_PlayerHint StartTheCarHint;
	UPROPERTY()						UFSTS_PlayerHint* LookInTheMirrorHint;				//var FSTS_PlayerHint LookInTheMirrorHint;
	UPROPERTY()						UFSTS_PlayerHint* ShiftGearsHint;					//var FSTS_PlayerHint ShiftGearsHint;
	UPROPERTY()						UFSTS_PlayerHint* MoveForwardHint;					//var FSTS_PlayerHint MoveForwardHint;
	UPROPERTY()						UFSTS_PlayerHint* SteeringHint;						//var FSTS_PlayerHint SteeringHint;
	UPROPERTY()						UFSTS_PlayerHint* SpeedRangeHint;					//var FSTS_PlayerHint SpeedRangeHint;
	UPROPERTY()						UFSTS_PlayerHint* VehicleStuckHint;					//var FSTS_PlayerHint VehicleStuckHint;
	UPROPERTY()						UFSTS_PlayerHint* VehicleTippingHint;				//var FSTS_PlayerHint VehicleTippingHint;
	UPROPERTY()						UFSTS_PlayerHint* VehicleDisabledHint;				//var FSTS_PlayerHint VehicleDisabledHint;
	UPROPERTY()						AFSTS_Objective* Checkpoint0Objective;				//var FSTS_Objective Checkpoint0Objective;
	UPROPERTY()						AFSTS_Objective* Checkpoint1Objective;				//var FSTS_Objective Checkpoint1Objective;
	UPROPERTY()						AFSTS_Objective* Checkpoint2Objective;				//var FSTS_Objective Checkpoint2Objective;
	UPROPERTY()						AFSTS_Objective* FinishObjective;					//var FSTS_Objective FinishObjective;

	void PostPostInit();
	void RestartLevel();
	void Leavenworth();
	bool AGP_NPC_Died(AAGP_NPC* NotifyActor, AController* Instigator);
	bool AGP_Character_Died(AAGP_Character* NotifyActor, AController* Instigator);
	bool Pawn_Died(APawn* NotifyActor, AController* Instigator);
	bool ActorNotify(AActor* NotifyActor, EEventType Event, AActor* Instigator, FString Parms);
	bool AGP_NPC_Damaged(AAGP_NPC* NotifyActor, AController* Instigator);
	bool Pawn_Damaged(APawn* NotifyActor, AController* Instigator);
	bool AGP_Vehicle_Spawned(AAGP_VehicleFactory* SpawningFactory, AAGP_Vehicle* NewVehicle, FString Parms);
	bool SetupStaticGunnerVehicle(AVehicle* NewVehicle);
	bool SetupMobileGunnerVehicle(AVehicle* NewVehicle);
	void HandlePassResults();
	void InitHintDelegates();
	bool IsUseInstructorHintAppropriate();
	bool IsUseInstructorHintSatisfied();
	bool IsUseTheSeatbeltHintAppropriate();
	bool IsUseTheSeatbeltHintSatisfied();
	bool IsEnterTheVehicleHintAppropriate();
	bool IsEnterTheVehicleHintSatisfied();
	bool IsStartTheCarHintAppropriate();
	bool IsStartTheCarHintSatisfied();
	bool IsShiftGearsHintAppropriate();
	bool IsShiftGearsHintSatisfied();
	bool IsLookInTheMirrorHintAppropriate();
	bool IsLookInTheMirrorHintSatisfied();
	bool IsSpeedRangeHintAppropriate();
	bool IsSpeedRangeHintSatisfied();
	bool IsVehicleStuckHintAppropriate();
	bool IsVehicleStuckHintSatisfied();
	bool IsVehicleTippingHintAppropriate();
	bool IsVehicleTippingHintSatisfied();
	bool IsVehicleDisabledHintAppropriate();
	bool IsVehicleDisabledHintSatisfied();
};
