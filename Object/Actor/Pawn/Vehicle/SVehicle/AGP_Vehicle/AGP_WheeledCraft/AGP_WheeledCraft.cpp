// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_WheeledCraft.h"
#include "AA29/Object/Actor/Info/AnnouncerVoice/AnnouncerVoice.h"
#include "AA29/Object/Actor/Light/HeadlightCorona/BrakelightCorona/BrakelightCorona.h"
#include "AA29/Object/Actor/Emitter/DieselSmoke/DieselSmoke.h"
#include "AA29/Object/Actor/Emitter/DustCloudEffect/DustCloudEffect.h"
#include "AA29/Object/SVehicleWheel/SVehicleWheel.h"
#include "Engine/Canvas.h"

AAGP_WheeledCraft::AAGP_WheeledCraft()
{
	BrakeLight.SetNum(2);
	BrakeLightOffset.SetNum(2);
	GearRatios.SetNum(8);
	dieselCoeffs.SetNum(6);
	dieselCoeffs[0] = 0;
	dieselCoeffs[1] = 1;
	dieselCoeffs[2] = 0.4;
	dieselCoeffs[3] = 1;
	dieselCoeffs[4] = 0.2;
	dieselCoeffs[5] = 0;
	NumForwardGears = 4; 
	MinAirControlDamping = 0.1;
	//bCanFlip = true;
	//CenterSpringRangePitch = 5000;
	//CenterSpringRangeRoll = 5000;
}

void AAGP_WheeledCraft::StopwatchStart()
{
	if (GetNetMode() != ENetMode::NM_Standalone)
	{
		return;
	}
	bStopwatchRunning = !bStopwatchRunning;
}

void AAGP_WheeledCraft::StopwatchReset()
{
	if (GetNetMode() != ENetMode::NM_Standalone)
	{
		return;
	}
	StopwatchTime = 0;
	bStopwatchPending = false;
	StopwatchStartSpeed = 0;
	StopwatchStopSpeed = 0;
}

void AAGP_WheeledCraft::StopwatchSet(float EndSpeed, float StartSpeed)
{
	if (GetNetMode() != ENetMode::NM_Standalone)
	{
		return;
	}
	if (bStopwatchRunning)
	{
		bStopwatchRunning = false;
		StopwatchTime = 0;
	}
	bStopwatchPending = true;
	StopwatchStartSpeed = StartSpeed;
	StopwatchStopSpeed = EndSpeed;
}

void AAGP_WheeledCraft::DisplayVehicleDebug(UCanvas* Canvas, float &YL, float &YPos)
{
	/*
	int32 i = 0;
	DisplayVehicleDebug(Canvas, YL, YPos);
	Canvas.SetDrawColor(255, 0, 0);
	Canvas.DrawText("Stopwatch: " + StopwatchTime);
	YPos += YL;
	Canvas.SetDrawColor(255, 255, 255);
	Canvas.SetPos(0, YPos);
	Canvas.DrawText("Gear: " + Gear + "    CarMPH: " + CarMPH);
	YPos += YL;
	Canvas.SetPos(0, YPos);
	Canvas.DrawText("EngineRPM: " + EngineRPM);
	YPos += YL;
	Canvas.SetPos(0, YPos);
	Canvas.DrawText("IdleRPM: " + IdleRPM);
	YPos += YL;
	Canvas.SetPos(0, YPos);
	Canvas.DrawText("EngineInertia: " + EngineInertia);
	YPos += YL;
	Canvas.SetDrawColor(0, 255, 0);
	Canvas.SetPos(0, YPos);
	Canvas.DrawText("-------------Wheels-------------:");
	YPos += YL;
	for (i = 0; i < Wheels.Num(); i++)
	{
		Canvas.SetPos(0, YPos);
		Canvas.DrawText(Wheels[i]->Name);
		YPos += YL;
		Canvas.SetPos(0, YPos);
		Canvas.DrawText("SpinVel: " + Wheels[i]->SpinVel);
		YPos += YL;
		Canvas.SetPos(0, YPos);
		Canvas.DrawText("DriveForce: " + Wheels[i]->DriveForce);
		YPos += YL;
		Canvas.SetPos(0, YPos);
		Canvas.DrawText("LongSlip: " + Wheels[i]->LongSlip);
		YPos += YL;
		Canvas.SetPos(0, YPos);
		Canvas.DrawText("LatSlip: " + Wheels[i]->LatSlip);
		YPos += YL;
	}
	*/
}
void AAGP_WheeledCraft::PostNetBeginPlay()
{
	int32 i = 0;
	FCoords WheelCoords = FCoords({});
	NumPoweredWheels = 0;
	/*
	Dust.Num() = Wheels.Num();
	for (i = 0; i < Wheels.Num(); i++)
	{
		NumPoweredWheels += 1;
		if (GetNetMode() != ENetMode::NM_DedicatedServer)
		{
			if (Dust[i] == nullptr)
			{
				WheelCoords = GetBoneCoords(Wheels[i]->BoneName);
				Dust[i] = Spawn('DustCloudEffect', this, , WheelCoords.Origin + FVector(0 0 - 1) * Wheels[i]->WheelRadius >> Rotation);
				Dust[i].SetBase(this);
			}
		}
	}
	*/
	Super::PostNetBeginPlay();
}
void AAGP_WheeledCraft::PrecacheAnnouncer(AAnnouncerVoice* V, bool bRewardSounds)
{
}

void AAGP_WheeledCraft::Destroyed()
{
	int32 i = 0;
	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		for (i = 0; i < Dust.Num(); i++)
		{
			if (Dust[i] != nullptr)
			{
				Dust[i]->Destroy();
			}
		}
		if (bMakeBrakeLights)
		{
			if (BrakeLight[0] != nullptr)
			{
				BrakeLight[0]->Destroy();
			}
			if (BrakeLight[1] != nullptr)
			{
				BrakeLight[1]->Destroy();
			}
		}
	}
	Dust.Empty();
	Super::Destroyed();
}

bool AAGP_WheeledCraft::KUpdateState(FKRigidBodyState &NewState)
{
	/*
	if (Role == 4 || !bNewCarState)
	{
		return false;
	}
	NewState = ChassisState;
	bNewCarState = false;
	*/
	return true;
}

void AAGP_WheeledCraft::updatePuff()
{
	float Speed = 0;
	bool stateChanged = false;
	stateChanged = false;
	/*
	switch(puffState)
	{
			case 0:
				if (bDriving)
				{
					puffState = 1;
					stateChanged = true;
				}
				break;
			case 1:
				if (GetWorld()->GetTimeSeconds() - puffStateStartTime > 4)
				{
					puffState = 2;
					stateChanged = true;
				}
				break;
			case 2:
				if (Throttle != 0)
				{
					puffState = 3;
					stateChanged = true;
				}
				break;
			case 3:
				if (GetWorld()->GetTimeSeconds() - puffStateStartTime > 2)
				{
					if (Throttle == 0)
					{
						puffState = 2;
					}
					else
					{
						puffState = 4;
					}
					stateChanged = true;
				}
				GOTO JL017B;
			case 4:
				Speed = Abs(VSize(Velocity));
				if (Speed < 5 && Throttle == 0)
				{
					puffState = 2;
					stateChanged = true;
				}
				else
				{
					if (Speed > 350)
					{
						puffState = 5;
						stateChanged = true;
					}
				}
				GOTO JL017B;
			case 5:
				Speed = Abs(VSize(Velocity));
				if (Speed < 350)
				{
					puffState = 4;
					stateChanged = true;
				}
				GOTO JL017B;
			default:
			JL017B:
	}
	if (stateChanged)
	{
		puffStateStartTime = GetWorld()->GetTimeSeconds();
		if (dieselPuff != nullptr)
		{
			dieselPuff.updatePuff(dieselCoeffs[puffState]);
		}
	}
	*/
}

void AAGP_WheeledCraft::SVehicleUpdateParams()
{
	int32 i = 0;
	Super::SVehicleUpdateParams();
	for (i = 0; i < Wheels.Num(); i++)
	{
		Wheels[i]->Softness = WheelSoftness;
		Wheels[i]->PenScale = WheelPenScale;
		Wheels[i]->PenOffset = WheelPenOffset;
		Wheels[i]->LongSlip = WheelLongSlip;
		Wheels[i]->LatSlipFunc = WheelLatSlipFunc;
		Wheels[i]->Restitution = WheelRestitution;
		Wheels[i]->Adhesion = WheelAdhesion;
		Wheels[i]->WheelInertia = WheelInertia;
		Wheels[i]->LongFrictionFunc = WheelLongFrictionFunc;
		Wheels[i]->HandbrakeFrictionFactor = WheelHandbrakeFriction;
		Wheels[i]->HandbrakeSlipFactor = WheelHandbrakeSlip;
		Wheels[i]->SuspensionTravel = WheelSuspensionTravel;
		Wheels[i]->SuspensionOffset = WheelSuspensionOffset;
		Wheels[i]->SuspensionMaxRenderTravel = WheelSuspensionMaxRenderTravel;
	}
	if (GetNetMode() != ENetMode::NM_DedicatedServer && bMakeBrakeLights)
	{
		for (i = 0; i < 2; i++)
		{
			if (BrakeLight[i] != nullptr)
			{
				//BrakeLight[i]->SetBase(nullptr);
				//BrakeLight[i]->SetLocation(Location + BrakeLightOffset[i] >> Rotation);
				//BrakeLight[i]->SetBase(this);
				//BrakeLight[i]->SetRelativeRotation(FRotator(0 32768 0));
				//BrakeLight[i]->Skins[0] = BrakeLightMaterial;
			}
		}
	}
}

void AAGP_WheeledCraft::DrivingStatusChanged()
{
	int32 i = 0;
	FVector ExhaustLoc = FVector(0,0,0);
	Super::DrivingStatusChanged();
	/*
	if (bDriving && GetNetMode() != ENetMode::NM_DedicatedServer && !bDropDetail)
	{
		if (bHasExhaust)
		{
			ExhaustLoc = GetBoneCoords(ExhaustBone).Origin;
			dieselPuff = Spawn('DieselSmoke', this, , ExhaustLoc);
			dieselPuff.SetBase(this);
		}
		if (bMakeBrakeLights)
		{
			for (i = 0; i < 2; i++)
			{
				if (BrakeLight[i] == nullptr)
				{
					BrakeLight[i] = Spawn('BrakelightCorona', this, , Location + BrakeLightOffset[i] >> Rotation);
					BrakeLight[i].SetBase(this);
					BrakeLight[i].SetRelativeRotation(FRotator(0 32768 0));
					BrakeLight[i].Skins[0] = BrakeLightMaterial;
				}
			}
		}
	}
	else
	{
		if (GetNetMode() != ENetMode::NM_DedicatedServer)
		{
			for (i = 0; i < Dust.Num(); i++)
			{
				Dust[i].disableEffect();
			}
			if (bHasExhaust)
			{
				if (dieselPuff != nullptr)
				{
					dieselPuff.Destroy();
				}
				puffState = 0;
			}
			if (bMakeBrakeLights)
			{
				for (i = 0; i < 2; i++)
				{
					if (BrakeLight[i] != nullptr)
					{
						BrakeLight[i].Destroy();
					}
				}
			}
		}
		TurnDamping = 0;
	}
	*/
}

void AAGP_WheeledCraft::Tick(float dt)
{
	int32 i = 0;
	Super::Tick(dt);
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		if (bStopwatchRunning)
		{
			if (StopwatchStopSpeed > 0 && CarMPH > StopwatchStopSpeed)
			{
				bStopwatchRunning = false;
				StopwatchStartSpeed = 0;
				StopwatchStopSpeed = 0;
			}
			else
			{
				StopwatchTime += dt;
			}
		}
		else
		{
			if (bStopwatchPending && CarMPH > StopwatchStartSpeed + 0.1)
			{
				bStopwatchPending = false;
				bStopwatchRunning = true;
			}
		}
	}
	if (GetNetMode() != ENetMode::NM_DedicatedServer && !bDropDetail)
	{
		for (i = 0; i < Dust.Num(); i++)
		{
			if (Dust[i] != nullptr)
			{
				//Dust[i]->UpdateDust(Wheels[i], GetBoneCoords(Wheels[i]->BoneName), VSize(Velocity));
			}
		}
		if (bHasExhaust)
		{
			updatePuff();
		}
		if (bMakeBrakeLights)
		{
			for (i = 0; i < 2; i++)
			{
				if (BrakeLight[i] != nullptr)
				{
					BrakeLight[i]->bCorona = true;
				}
			}
			for (i = 0; i < 2; i++)
			{
				if (BrakeLight[i] != nullptr)
				{
					BrakeLight[i]->UpdateBrakelightState(OutputBrake, Gear);
				}
			}
		}
	}
	TurnDamping = GetDefault<AAGP_WheeledCraft>()->TurnDamping;
}

float AAGP_WheeledCraft::ImpactDamageModifier()
{
	float multiplier = 0;
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	/*
	GetAxes(Rotation, X, Y, Z);
	if ((ImpactInfo.impactNorm Dot Z) > 0)
	{
		multiplier = (1 - (ImpactInfo.impactNorm Dot Z));
	}
	else
	{
		multiplier = 1;
	}
	*/
	return (Super::ImpactDamageModifier() * multiplier);
}

int32 AAGP_WheeledCraft::LimitPitch(int32 Pitch)
{
	return Super::LimitPitch(Pitch);
}
