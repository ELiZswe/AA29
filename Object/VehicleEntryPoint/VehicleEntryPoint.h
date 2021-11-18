// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VehicleEntryPoint.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UVehicleEntryPoint : public UObject
{
	GENERATED_BODY()
public:
	UVehicleEntryPoint();

	UPROPERTY()										FRotator EntryRotOffset;			//var Object.Rotator EntryRotOffset;
	UPROPERTY()										FVector EntryPosOffset;				//var Object.Vector EntryPosOffset;
	UPROPERTY()										bool DoorOpen;						//var bool DoorOpen;
	UPROPERTY()										int32 DoorAngle;					//var int DoorAngle;
	UPROPERTY()										int32 DoorOpenAngle;				//var int DoorOpenAngle;
	UPROPERTY()										FName DoorBoneDS2;					//var name DoorBoneDS2;
	UPROPERTY()										FName DoorBoneDS1;					//var name DoorBoneDS1;
	UPROPERTY()										FName DoorBone;						//var name DoorBone;
	UPROPERTY(EditAnywhere)							FName ExitAnim;						//var() name ExitAnim;
	UPROPERTY(EditAnywhere)							FName DoorAnim;						//var() name DoorAnim;
	UPROPERTY(EditAnywhere)							FName EntryAnim;					//var() name EntryAnim;
	UPROPERTY(EditAnywhere)							TArray<int32> PositionIndex;		//var() array<int> PositionIndex;
	UPROPERTY(EditAnywhere)							float EntryRadius;					//var() float EntryRadius;
	UPROPERTY(EditAnywhere)							FName EntryBone;					//var() name EntryBone;
	UPROPERTY(EditAnywhere)							bool bDriverEntry;					//var() bool bDriverEntry;
};
