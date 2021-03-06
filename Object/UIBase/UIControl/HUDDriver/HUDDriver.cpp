// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/HUDDriver/HUDDriver.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/CROWS_HMMWV/CROWS_HMMWV.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/HMMWV_Passenger.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/HMMWV_RunningBoardPassenger/HMMWV_RunningBoardPassengerLB/HMMWV_RunningBoardPassengerLB.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/HMMWV_RunningBoardPassenger/HMMWV_RunningBoardPassengerLF/HMMWV_RunningBoardPassengerLF.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/HMMWV_RunningBoardPassenger/HMMWV_RunningBoardPassengerRB/HMMWV_RunningBoardPassengerRB.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/HMMWV_RunningBoardPassenger/HMMWV_RunningBoardPassengerRF/HMMWV_RunningBoardPassengerRF.h"

UHUDDriver::UHUDDriver()
{
	SpeedometerBKG = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/t_ui_HUD_HMMWV_speedometer_bkg_Mat.t_ui_HUD_HMMWV_speedometer_bkg_Mat'"), NULL, LOAD_None, NULL);
	SpeedometerNeedle = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/t_ui_HUD_HMMWV_speedometer_needle_Mat.t_ui_HUD_HMMWV_speedometer_needle_Mat'"), NULL, LOAD_None, NULL);
	GearshiftPark = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/t_ui_HUD_HMMWV_gearshift1_park_Mat.t_ui_HUD_HMMWV_gearshift1_park_Mat'"), NULL, LOAD_None, NULL);
	GearshiftDrive = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/t_ui_HUD_HMMWV_gearshift1_drive_Mat.t_ui_HUD_HMMWV_gearshift1_drive_Mat'"), NULL, LOAD_None, NULL);
	GearshiftReverse = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/t_ui_HUD_HMMWV_gearshift1_reverse_Mat.t_ui_HUD_HMMWV_gearshift1_reverse_Mat'"), NULL, LOAD_None, NULL);
	GearshiftHi = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/t_ui_HUD_HMMWV_gearshift2_hi_Mat.t_ui_HUD_HMMWV_gearshift2_hi_Mat'"), NULL, LOAD_None, NULL);
	GearshiftLo = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/t_ui_HUD_HMMWV_gearshift2_lo_Mat.t_ui_HUD_HMMWV_gearshift2_lo_Mat'"), NULL, LOAD_None, NULL);
	SeatbeltOn = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/t_ui_HUD_HMMWV_seatbelt_on_Mat.t_ui_HUD_HMMWV_seatbelt_on_Mat'"), NULL, LOAD_None, NULL);
	SeatbeltOff = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/t_ui_HUD_HMMWV_seatbelt_off_Mat.t_ui_HUD_HMMWV_seatbelt_off_Mat'"), NULL, LOAD_None, NULL);
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
	Super::Destroyed();
	RotatingSpeedometerNeedle = nullptr;
	SpeedometerBKG = nullptr;
	SpeedometerNeedle = nullptr;
	GearshiftPark = nullptr;
	GearshiftDrive = nullptr;
	GearshiftReverse = nullptr;
	GearshiftHi = nullptr;
	GearshiftLo = nullptr;
	SeatbeltOn = nullptr;
	SeatbeltOff = nullptr;
}
void UHUDDriver::CreateTexture()
{
	Super::CreateTexture();
	/*
	RotatingSpeedometerNeedle = new () Class'TexRotator';
	RotatingSpeedometerNeedle.Material = Default.SpeedometerNeedle;
	RotatingSpeedometerNeedle.TexRotationType = 0;
	RotatingSpeedometerNeedle.Rotation = FRotator(0 0 0);
	RotatingSpeedometerNeedle.UOffset = Default.SpeedometerNeedle.MaterialUSize() / 2;
	RotatingSpeedometerNeedle.VOffset = Default.SpeedometerNeedle.MaterialVSize() / 2;
	RotatingSpeedometerNeedle.OscillationRate = FRotator(0 0 0);
	RotatingSpeedometerNeedle.OscillationAmplitude = FRotator(0 0 0);
	RotatingSpeedometerNeedle.OscillationPhase = FRotator(0 0 0);
	*/
}

void UHUDDriver::Tick(float DeltaTime)
{
	if (CurrentSpeedometerRotation < DesiredSpeedometerRotation)
	{
		CurrentSpeedometerRotation += NeedleInterpolationRate * DeltaTime;
		CurrentSpeedometerRotation =FMath::Clamp(CurrentSpeedometerRotation, 0.0f, DesiredSpeedometerRotation);
	}
	else
	{
		if (CurrentSpeedometerRotation > DesiredSpeedometerRotation)
		{
			CurrentSpeedometerRotation -= NeedleInterpolationRate * DeltaTime;
			CurrentSpeedometerRotation =FMath::Clamp(CurrentSpeedometerRotation, DesiredSpeedometerRotation, 1.0f);
		}
	}
	//RotatingSpeedometerNeedle->Rotation->Yaw = CurrentSpeedometerRotation * -MaxSpeedometerRotation;
}

void UHUDDriver::Draw(UCanvas* Canvas)
{
	ACROWS_HMMWV* MyVehicle = nullptr;
	AHMMWV_Passenger* MyPassenger = nullptr;
	float DeltaTime = 0;
	MyVehicle = Cast<ACROWS_HMMWV>(cFrame->cActor);
	if (MyVehicle != nullptr)
	{
		DesiredSpeedometerRotation =FMath::Clamp(MyVehicle->CarMPH / MaxMPH, 0.0f, 1.0f);
		/*
		if (MyVehicle->Level != nullptr)
		{
			if (LastTimeStamp == 0)
			{
				LastTimeStamp = MyVehicle->GetWorld()->GetTimeSeconds();
				CurrentSpeedometerRotation = DesiredSpeedometerRotation;
			}
			DeltaTime = MyVehicle->GetWorld()->GetTimeSeconds() - LastTimeStamp;
			Tick(DeltaTime);
			LastTimeStamp = MyVehicle->GetWorld()->GetTimeSeconds();
		}
		*/
		DrawSpeedometer(Canvas, MyVehicle);
		DrawDriveGear(Canvas, MyVehicle);
		DrawTransmission(Canvas, MyVehicle);
		DrawSeatbelt(Canvas, MyVehicle);
	}
	else
	{
		MyPassenger = Cast<AHMMWV_Passenger>(cFrame->cActor);
		if (MyPassenger != nullptr && !MyPassenger->IsA(AHMMWV_RunningBoardPassengerLB::StaticClass()) && !MyPassenger->IsA(AHMMWV_RunningBoardPassengerLF::StaticClass()) && !MyPassenger->IsA(AHMMWV_RunningBoardPassengerRB::StaticClass()) && !MyPassenger->IsA(AHMMWV_RunningBoardPassengerRF::StaticClass()))
		{
			DrawSeatbelt(Canvas, MyPassenger);
		}
		LastTimeStamp = 0;
	}
}

void UHUDDriver::DrawSpeedometer(UCanvas* Canvas, ACROWS_HMMWV* MyVehicle)
{
	//Canvas.SetPos(SpeedometerX * cFrame->fScaleX, SpeedometerY * cFrame->fScaleY);
	//Canvas.DrawTile(SpeedometerBKG, SpeedometerW * cFrame->fScaleX, SpeedometerH * cFrame->fScaleY, 0, 0, SpeedometerBKG.MaterialUSize(), SpeedometerBKG.MaterialVSize());
	//Canvas.SetPos(SpeedometerX * cFrame->fScaleX, SpeedometerY * cFrame->fScaleY);
	//Canvas.DrawTile(RotatingSpeedometerNeedle, SpeedometerW * cFrame->fScaleX, SpeedometerH * cFrame->fScaleY, 0, 0, RotatingSpeedometerNeedle.MaterialUSize(), RotatingSpeedometerNeedle.MaterialVSize());
}

void UHUDDriver::DrawDriveGear(UCanvas* Canvas, ACROWS_HMMWV* MyVehicle)
{
	//Canvas.SetPos(DriveGearX * cFrame->fScaleX, DriveGearY * cFrame->fScaleY);
	switch(MyVehicle->Shifter)
	{
		case EeShifterState::SS_Park:
			//Canvas.DrawTile(GearshiftPark, DriveGearW * cFrame->fScaleX, DriveGearH * cFrame->fScaleY, 0, 0, GearshiftPark.MaterialUSize(), GearshiftPark.MaterialVSize());
			break;
		case EeShifterState::SS_Drive:
			//Canvas.DrawTile(GearshiftDrive, DriveGearW * cFrame->fScaleX, DriveGearH * cFrame->fScaleY, 0, 0, GearshiftDrive.MaterialUSize(), GearshiftDrive.MaterialVSize());
			break;
		case EeShifterState::SS_Reverse:
			//Canvas.DrawTile(GearshiftReverse, DriveGearW * cFrame->fScaleX, DriveGearH * cFrame->fScaleY, 0, 0, GearshiftReverse.MaterialUSize(), GearshiftReverse.MaterialVSize());
			break;
		default:
			break;
	}
}

void UHUDDriver::DrawTransmission(UCanvas* Canvas, ACROWS_HMMWV* MyVehicle)
{
	//Canvas.SetPos(TransmissionX * cFrame->fScaleX, TransmissionY * cFrame->fScaleY);
	if (MyVehicle->bIsInHighGear)
	{
		//Canvas.DrawTile(GearshiftHi, TransmissionW * cFrame->fScaleX, TransmissionH * cFrame->fScaleY, 0, 0, GearshiftHi.MaterialUSize(), GearshiftHi.MaterialVSize());
	}
	else
	{
		//Canvas.DrawTile(GearshiftLo, TransmissionW * cFrame->fScaleX, TransmissionH * cFrame->fScaleY, 0, 0, GearshiftLo.MaterialUSize(), GearshiftLo.MaterialVSize());
	}
}

void UHUDDriver::DrawSeatbelt(UCanvas* Canvas, AVehicle* MyVehicle)
{
	FColor OldColor = FColor(0,0,0,0);
	//Canvas.SetPos(SeatbeltX * cFrame->fScaleX, SeatbeltY * cFrame->fScaleY);
	if (MyVehicle->bWearingSeatbelt)
	{
		//Canvas.DrawTile(SeatbeltOn, SeatbeltW * cFrame->fScaleX, SeatbeltH * cFrame->fScaleY, 0, 0, SeatbeltOn.MaterialUSize(), SeatbeltOn.MaterialVSize());
	}
	else
	{
		//OldColor = Canvas.DrawColor;
		//Canvas.SetDrawColor(255, Canvas.DrawColor.G, Canvas.DrawColor.B, Canvas.DrawColor.A);
		//Canvas.DrawTile(SeatbeltOff, SeatbeltW * cFrame->fScaleX, SeatbeltH * cFrame->fScaleY, 0, 0, SeatbeltOff.MaterialUSize(), SeatbeltOff.MaterialVSize());
		//Canvas.DrawColor = OldColor;
	}
}
