// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VehicleEntryPoint.generated.h"

UCLASS()
class UVehicleEntryPoint : public UObject
{
	GENERATED_BODY()
public:
	UVehicleEntryPoint();

	UPROPERTY(EditAnywhere)			bool			bDriverEntry;
	UPROPERTY(EditAnywhere)			FName			EntryBone;
	UPROPERTY(EditAnywhere)			float			EntryRadius;
	UPROPERTY(EditAnywhere)			TArray<int32>	PositionIndex;
	UPROPERTY(EditAnywhere)			FName			EntryAnim;
	UPROPERTY(EditAnywhere)			FName			DoorAnim;
	UPROPERTY(EditAnywhere)			FName			ExitAnim;
	UPROPERTY()						FName			DoorBone;
	UPROPERTY()						FName			DoorBoneDS1;
	UPROPERTY()						FName			DoorBoneDS2;
	UPROPERTY()						int32			DoorOpenAngle;
	UPROPERTY()						int32			DoorAngle;
	UPROPERTY()						bool			DoorOpen;
	UPROPERTY()						FVector			EntryPosOffset;
	UPROPERTY()						FRotator		EntryRotOffset;
};
