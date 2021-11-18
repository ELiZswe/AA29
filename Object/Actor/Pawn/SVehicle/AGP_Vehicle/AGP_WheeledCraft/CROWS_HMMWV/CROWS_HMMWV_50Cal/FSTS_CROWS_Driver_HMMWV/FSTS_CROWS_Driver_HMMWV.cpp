// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/SVehicle/AGP_Vehicle/AGP_WheeledCraft/CROWS_HMMWV/CROWS_HMMWV_50Cal/FSTS_CROWS_Driver_HMMWV/FSTS_CROWS_Driver_HMMWV.h"

AFSTS_CROWS_Driver_HMMWV::AFSTS_CROWS_Driver_HMMWV()
{
	bEnableChangePosition = false;
}


bool AFSTS_CROWS_Driver_HMMWV::PanelUsedBy(APawn* User, int32 Id)
{
	/*
	if (User.IsHumanControlled())
	{
		if (Id == PANEL_Collision_Dashboard && User == Self)
		{
			Ignition();
			Return True;
		}
		else
		{
			if (bEntryLocked)
			{
				Return True;
			}
			else
			{
				if (Id == PANEL_Collision_Door_LF || Id == PANEL_Collision_Door_RF || Id == PANEL_Collision_Door_RB || Id == PANEL_Collision_Door_LB)
				{
					Return DoDoor(User, Self, Positions[3]);
				}
			}
		}
	}
	*/
	return false;
}

bool AFSTS_CROWS_Driver_HMMWV::TryToDrive(APawn* p)
{
	/*
	Log("TryToDrive called, bEntryLocked= " $ bEntryLocked, 'FSTS_CROWS_Driver_HMMWV');
	if (bEntryLocked)
	{
		Return False;
	}
	else
	{
		if (SuperTryToDrive(p))
		{
			Return True;
		}
		Return False;
	}
	*/
	return false;    //FAKE    /ELiZ
}

bool AFSTS_CROWS_Driver_HMMWV::SuperTryToDrive(APawn* p)
{
	/*
	if (FlipTimeLeft > 0)
	{
		Return False;
	}
	if (NeedsFlip())
	{
		Flip(Vector(p.Rotation), 1);
		Return False;
	}
	Return TryToDrive(p);
	*/
	return false;    //FAKE    /ELiZ
}

void AFSTS_CROWS_Driver_HMMWV::Touch(AActor* Other)
{
	/*
	Touch(Other);
	if (Controller != None)
	{
		Controller.Touch(Other);
	}
	*/
}

void AFSTS_CROWS_Driver_HMMWV::AttachBodyPanels()
{
	/*
	local int i;
	local int j;
	AttachBodyPanels();
	for (i = 0; i < 52; i++)
	{
		BodyPanels[i].ExteriorHintText = "";
		for (j = 0; j < 8; j++)
		{
			BodyPanels[i].PassengerHintText[j] = "";
		}
	}
	*/
}

void AFSTS_CROWS_Driver_HMMWV::ShiftDriveGearsUp()
{
	bHasShiftedGears = true;
	Super::ShiftDriveGearsUp();
}

void AFSTS_CROWS_Driver_HMMWV::ShiftDriveGearsDown()
{
	bHasShiftedGears = true;
	Super::ShiftDriveGearsDown();
}

void AFSTS_CROWS_Driver_HMMWV::ShiftHiLoGears()
{
	bHasChangedSpeed = true;
	Super::ShiftHiLoGears();
}

void AFSTS_CROWS_Driver_HMMWV::LookRearViewLeft()
{
	bHasLookedInMirror = true;
	Super::LookRearViewLeft();
}

void AFSTS_CROWS_Driver_HMMWV::LookRearViewRight()
{
	bHasLookedInMirror = true;
	Super::LookRearViewRight();
}

void AFSTS_CROWS_Driver_HMMWV::Horn()
{
	bHasSoundedHorn = true;
	Super::Horn();
}

void AFSTS_CROWS_Driver_HMMWV::TakeImpactDamage(float AccelMag)
{
	/*
	Log("Take Impact Damage...", 'FSTS_CROWS_Driver_HMMWV');
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self, 8);
	}
	TakeImpactDamage(AccelMag);
	*/
}

void AFSTS_CROWS_Driver_HMMWV::ResetUserFlags()
{
	bEntryLocked = false;
	bEnableChangePosition = false;
	bHasShiftedGears = false;
	bHasChangedSpeed = false;
	bHasLookedInMirror = false;
	bHasSoundedHorn = false;
}