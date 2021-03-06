// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_WheeledCraft.h"
#include "CROWS_HMMWV_PlanB.generated.h"

class AVehicle;
class ALevelInfo;

UCLASS()
class ACROWS_HMMWV_PlanB : public AAGP_WheeledCraft
{
	GENERATED_BODY()
public:
	ACROWS_HMMWV_PlanB();

	UPROPERTY()						FName	CameraBone;						//var name CameraBone;
	UPROPERTY()						bool	bDriverWearingSeatbelt;			//var bool bDriverWearingSeatbelt;

	void PostNetBeginPlay();
	void FixBoneRotations();
	void ClientKDriverEnter(APlayerController* PC);
	void ClientKDriverLeave(APlayerController* PC);
	AVehicle* FindEntryVehicle(APawn* p);
	bool UsedBy(APawn* User);
	void SpecialCalcFirstPersonView(APlayerController* PC, AActor*& ViewActor, FVector& CameraLocation, FRotator& CameraRotation);
	bool SpecialCalcView(AActor*& ViewActor, FVector& CameraLocation, FRotator& CameraRotation);
	void Seatbelt();
	void ShiftDriveGears();
	void ShiftHiLoGears();
	void LookRearViewLeft();
	void LookRearViewRight();
	void Horn();
	void ToggleCalcView();
	APawn* CheckForHeadShot(FVector loc, FVector ray, float AdditionalScale);
	void SetActiveWeapon(int32 i);
	void StaticPrecache(ALevelInfo* L);
	void UpdatePrecacheStaticMeshes();
	void UpdatePrecacheMaterials();
	void DisplayVehicleDebug(UCanvas* Canvas, float& YL, float& YPos);
	void DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos);
};
