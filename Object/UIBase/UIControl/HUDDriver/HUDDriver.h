// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "HUDDriver.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UHUDDriver : public UUIControl
{
	GENERATED_BODY()
public:
	UHUDDriver();

	UPROPERTY()										float LastTimeStamp;							//var float LastTimeStamp;
	UPROPERTY()										float NeedleInterpolationRate;					//var float NeedleInterpolationRate;
	UPROPERTY()										float DesiredSpeedometerRotation;				//var float DesiredSpeedometerRotation;
	UPROPERTY()										float CurrentSpeedometerRotation;				//var float CurrentSpeedometerRotation;
	UPROPERTY()										int32 MaxSpeedometerRotation;					//var int MaxSpeedometerRotation;
	UPROPERTY()										float MaxMPH;									//var float MaxMPH;
	UPROPERTY()										int32 SeatbeltH;								//var int SeatbeltH;
	UPROPERTY()										int32 SeatbeltW;								//var int SeatbeltW;
	UPROPERTY()										int32 SeatbeltY;								//var int SeatbeltY;
	UPROPERTY()										int32 SeatbeltX;								//var int SeatbeltX;
	UPROPERTY()										int32 TransmissionH;							//var int TransmissionH;
	UPROPERTY()										int32 TransmissionW;							//var int TransmissionW;
	UPROPERTY()										int32 TransmissionY;							//var int TransmissionY;
	UPROPERTY()										int32 TransmissionX;							//var int TransmissionX;
	UPROPERTY()										int32 DriveGearH;								//var int DriveGearH;
	UPROPERTY()										int32 DriveGearW;								//var int DriveGearW;
	UPROPERTY()										int32 DriveGearY;								//var int DriveGearY;
	UPROPERTY()										int32 DriveGearX;								//var int DriveGearX;
	UPROPERTY()										int32 SpeedometerH;								//var int SpeedometerH;
	UPROPERTY()										int32 SpeedometerW;								//var int SpeedometerW;
	UPROPERTY()										int32 SpeedometerY;								//var int SpeedometerY;
	UPROPERTY()										int32 SpeedometerX;								//var int SpeedometerX;
	UPROPERTY()										UMaterialInstance* SeatbeltOff;					//var Material SeatbeltOff;
	UPROPERTY()										UMaterialInstance* SeatbeltOn;					//var Material SeatbeltOn;
	UPROPERTY()										UMaterialInstance* GearshiftLo;					//var Material GearshiftLo;
	UPROPERTY()										UMaterialInstance* GearshiftHi;					//var Material GearshiftHi;
	UPROPERTY()										UMaterialInstance* GearshiftReverse;			//var Material GearshiftReverse;
	UPROPERTY()										UMaterialInstance* GearshiftDrive;				//var Material GearshiftDrive;
	UPROPERTY()										UMaterialInstance* GearshiftPark;				//var Material GearshiftPark;
	UPROPERTY()										UMaterialInstance* SpeedometerNeedle;			//var Material SpeedometerNeedle;
	UPROPERTY()										UMaterialInstance* SpeedometerBKG;				//var Material SpeedometerBKG;
	UPROPERTY()										UMaterialInstance* RotatingSpeedometerNeedle;	//var TexRotator RotatingSpeedometerNeedle;


	void Destroyed();
	void CreateTexture();
	void Tick(float DeltaTime);
	void Draw(UCanvas* Canvas);
	//void DrawSpeedometer(UCanvas* Canvas, ACROWS_HMMWV* MyVehicle);
	//void DrawDriveGear(UCanvas* Canvas, ACROWS_HMMWV* MyVehicle);
	//void DrawTransmission(UCanvas* Canvas, ACROWS_HMMWV* MyVehicle);
	//void DrawSeatbelt(UCanvas* Canvas, AVehicle* MyVehicle);

};
