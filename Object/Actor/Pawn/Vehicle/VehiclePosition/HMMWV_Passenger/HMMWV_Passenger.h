// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/VehiclePosition.h"
#include "HMMWV_Passenger.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AHMMWV_Passenger : public AVehiclePosition
{
	GENERATED_BODY()
public:
	AHMMWV_Passenger();

	UPROPERTY()						FRotator			ViewRotationOffset;								//var Object.Rotator ViewRotationOffset;
	UPROPERTY()						UStaticMesh*		SeatBeltOffMesh;								//var StaticMesh SeatBeltOffMesh;
	UPROPERTY()						UStaticMesh*		SeatBeltOnMesh;									//var StaticMesh SeatBeltOnMesh;
	//UPROPERTY()						ABodyPanel*			Seatbelt;									//var AGP.BodyPanel Seatbelt;
	//UPROPERTY()						AAnimManager*		AnimManagerClass;									//var class<AnimManager> AnimManagerClass;


	void PostBeginPlay();
	void MakeMeASeatbelt();
	void Destroyed();
	void LeanLeft(bool bFullLeft);
	void LeanRight(bool bFullRight);
	void KDriverEnter(APawn* p);
	void KDriverLeave(bool bForceLeave);
	void SetDriverHiddenAttachments();
	void ServerSetSeatbelt();
	void ServerRemoveSeatbelt();
	void SpecialCalcFirstPersonView(APlayerController* PC, AActor*& ViewActor, FVector& CameraLocation, FRotator& CameraRotation);
	void SpecialSetFirstPersonViewRotation(APlayerController* PC, FRotator CameraRotation);
	bool SpecialCalcView(AActor*& ViewActor, FVector& CameraLocation, FRotator& CameraRotation);

};
