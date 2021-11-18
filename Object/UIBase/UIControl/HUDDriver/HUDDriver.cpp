// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/HUDDriver/HUDDriver.h"

UHUDDriver::UHUDDriver()
{
	//SpeedometerBKG = Texture'T_AAO_UI.HUD.t_ui_HUD_HMMWV_speedometer_bkg';
	//SpeedometerNeedle = Texture'T_AAO_UI.HUD.t_ui_HUD_HMMWV_speedometer_needle';
	//GearshiftPark = Texture'T_AAO_UI.HUD.t_ui_HUD_HMMWV_gearshift1_park';
	//GearshiftDrive = Texture'T_AAO_UI.HUD.t_ui_HUD_HMMWV_gearshift1_drive';
	//GearshiftReverse = Texture'T_AAO_UI.HUD.t_ui_HUD_HMMWV_gearshift1_reverse';
	//GearshiftHi = Texture'T_AAO_UI.HUD.t_ui_HUD_HMMWV_gearshift2_hi';
	//GearshiftLo = Texture'T_AAO_UI.HUD.t_ui_HUD_HMMWV_gearshift2_lo';
	//SeatbeltOn = Texture'T_AAO_UI.HUD.t_ui_HUD_HMMWV_seatbelt_on';
	//SeatbeltOff = Texture'T_AAO_UI.HUD.t_ui_HUD_HMMWV_seatbelt_off';
	SpeedometerX = 231;
	SpeedometerY = 472;
	SpeedometerW = 167;
	SpeedometerH = 167;
	DriveGearX = 417;
	DriveGearY = 554;
	DriveGearW = 128;
	DriveGearH = 64;
	TransmissionX = 538;
	TransmissionY = 543;
	TransmissionW = 64;
	TransmissionH = 64;
	SeatbeltX = 717;
	SeatbeltY = 495;
	SeatbeltW = 128;
	SeatbeltH = 32;
	MaxMPH = 62.137001;
	MaxSpeedometerRotation = -22205;
	NeedleInterpolationRate = 1;
}

void UHUDDriver::Destroyed()
{
	/*
	Super::Destroyed();
	RotatingSpeedometerNeedle = None;
	SpeedometerBKG = None;
	SpeedometerNeedle = None;
	GearshiftPark = None;
	GearshiftDrive = None;
	GearshiftReverse = None;
	GearshiftHi = None;
	GearshiftLo = None;
	SeatbeltOn = None;
	SeatbeltOff = None;
	*/
}
void UHUDDriver::CreateTexture()
{
	/*
	CreateTexture();
	RotatingSpeedometerNeedle = new () classClass'TexRotator';
	RotatingSpeedometerNeedle.Material = Default.SpeedometerNeedle;
	RotatingSpeedometerNeedle.TexRotationType = 0;
	RotatingSpeedometerNeedle.Rotation = rot(0 0 0);
	RotatingSpeedometerNeedle.UOffset = Default.SpeedometerNeedle.MaterialUSize() / 2;
	RotatingSpeedometerNeedle.VOffset = Default.SpeedometerNeedle.MaterialVSize() / 2;
	RotatingSpeedometerNeedle.OscillationRate = rot(0 0 0);
	RotatingSpeedometerNeedle.OscillationAmplitude = rot(0 0 0);
	RotatingSpeedometerNeedle.OscillationPhase = rot(0 0 0);
	*/
}
void UHUDDriver::Tick(float DeltaTime)
{
	/*
	if (CurrentSpeedometerRotation < DesiredSpeedometerRotation)
	{
		CurrentSpeedometerRotation += NeedleInterpolationRate * DeltaTime;
		CurrentSpeedometerRotation = FClamp(CurrentSpeedometerRotation, 0, DesiredSpeedometerRotation);
	}
	else
	{
		if (CurrentSpeedometerRotation > DesiredSpeedometerRotation)
		{
			CurrentSpeedometerRotation -= NeedleInterpolationRate * DeltaTime;
			CurrentSpeedometerRotation = FClamp(CurrentSpeedometerRotation, DesiredSpeedometerRotation, 1);
		}
	}
	RotatingSpeedometerNeedle.Rotation.Yaw = CurrentSpeedometerRotation * -MaxSpeedometerRotation;
	*/
}
void UHUDDriver::Draw(UCanvas* Canvas)
{
	/*
	local CROWS_HMMWV MyVehicle;
	local HMMWV_Passenger MyPassenger;
	local float DeltaTime;
	MyVehicle = CROWS_HMMWV(cFrame.cActor);
	if (MyVehicle != None)
	{
		DesiredSpeedometerRotation = FClamp(MyVehicle.CarMPH / MaxMPH, 0, 1);
		if (MyVehicle.Level != None)
		{
			if (LastTimeStamp == 0)
			{
				LastTimeStamp = MyVehicle.Level.TimeSeconds;
				CurrentSpeedometerRotation = DesiredSpeedometerRotation;
			}
			DeltaTime = MyVehicle.Level.TimeSeconds - LastTimeStamp;
			Tick(DeltaTime);
			LastTimeStamp = MyVehicle.Level.TimeSeconds;
		}
		DrawSpeedometer(Canvas, MyVehicle);
		DrawDriveGear(Canvas, MyVehicle);
		DrawTransmission(Canvas, MyVehicle);
		DrawSeatbelt(Canvas, MyVehicle);
	}
	else
	{
		MyPassenger = HMMWV_Passenger(cFrame.cActor);
		if (MyPassenger != None && !MyPassenger.IsA('HMMWV_RunningBoardPassengerLB') && !MyPassenger.IsA('HMMWV_RunningBoardPassengerLF') && !MyPassenger.IsA('HMMWV_RunningBoardPassengerRB') && !MyPassenger.IsA('HMMWV_RunningBoardPassengerRF'))
		{
			DrawSeatbelt(Canvas, MyPassenger);
		}
		LastTimeStamp = 0;
	}
	*/
}
/*
void UHUDDriver::DrawSpeedometer(UCanvas* Canvas, ACROWS_HMMWV* MyVehicle)
{
	Canvas.SetPos(SpeedometerX * cFrame.fScaleX, SpeedometerY * cFrame.fScaleY);
	Canvas.DrawTile(SpeedometerBKG, SpeedometerW * cFrame.fScaleX, SpeedometerH * cFrame.fScaleY, 0, 0, SpeedometerBKG.MaterialUSize(), SpeedometerBKG.MaterialVSize());
	Canvas.SetPos(SpeedometerX * cFrame.fScaleX, SpeedometerY * cFrame.fScaleY);
	Canvas.DrawTile(RotatingSpeedometerNeedle, SpeedometerW * cFrame.fScaleX, SpeedometerH * cFrame.fScaleY, 0, 0, RotatingSpeedometerNeedle.MaterialUSize(), RotatingSpeedometerNeedle.MaterialVSize());
}
*/

/*
void UHUDDriver::DrawDriveGear(UCanvas* Canvas, ACROWS_HMMWV* MyVehicle)
{
	Canvas.SetPos(DriveGearX * cFrame.fScaleX, DriveGearY * cFrame.fScaleY);
	Switch(MyVehicle.Shifter)
	{
			case 0:
				Canvas.DrawTile(GearshiftPark, DriveGearW * cFrame.fScaleX, DriveGearH * cFrame.fScaleY, 0, 0, GearshiftPark.MaterialUSize(), GearshiftPark.MaterialVSize());
				break;
			case 1:
				Canvas.DrawTile(GearshiftDrive, DriveGearW * cFrame.fScaleX, DriveGearH * cFrame.fScaleY, 0, 0, GearshiftDrive.MaterialUSize(), GearshiftDrive.MaterialVSize());
				break;
			case 2:
				Canvas.DrawTile(GearshiftReverse, DriveGearW * cFrame.fScaleX, DriveGearH * cFrame.fScaleY, 0, 0, GearshiftReverse.MaterialUSize(), GearshiftReverse.MaterialVSize());
				break;
			default:
	}
}
*/

/*
void UHUDDriver::DrawTransmission(UCanvas* Canvas, ACROWS_HMMWV* MyVehicle)
{
	Canvas.SetPos(TransmissionX * cFrame.fScaleX, TransmissionY * cFrame.fScaleY);
	if (MyVehicle.bIsInHighGear)
	{
		Canvas.DrawTile(GearshiftHi, TransmissionW * cFrame.fScaleX, TransmissionH * cFrame.fScaleY, 0, 0, GearshiftHi.MaterialUSize(), GearshiftHi.MaterialVSize());
	}
	else
	{
		Canvas.DrawTile(GearshiftLo, TransmissionW * cFrame.fScaleX, TransmissionH * cFrame.fScaleY, 0, 0, GearshiftLo.MaterialUSize(), GearshiftLo.MaterialVSize());
	}
}
*/

/*
void UHUDDriver::DrawSeatbelt(UCanvas* Canvas, AVehicle* MyVehicle)
{
	local Object.Color OldColor;
	Canvas.SetPos(SeatbeltX * cFrame.fScaleX, SeatbeltY * cFrame.fScaleY);
	if (MyVehicle.bWearingSeatbelt)
	{
		Canvas.DrawTile(SeatbeltOn, SeatbeltW * cFrame.fScaleX, SeatbeltH * cFrame.fScaleY, 0, 0, SeatbeltOn.MaterialUSize(), SeatbeltOn.MaterialVSize());
	}
	else
	{
		OldColor = Canvas.DrawColor;
		Canvas.SetDrawColor(255, Canvas.DrawColor.G, Canvas.DrawColor.B, Canvas.DrawColor.A);
		Canvas.DrawTile(SeatbeltOff, SeatbeltW * cFrame.fScaleX, SeatbeltH * cFrame.fScaleY, 0, 0, SeatbeltOff.MaterialUSize(), SeatbeltOff.MaterialVSize());
		Canvas.DrawColor = OldColor;
	}
}
	*/
