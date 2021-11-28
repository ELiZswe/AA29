// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/CROWS_HMMWV/CROWS_HMMWV_50Cal/CROWS_HMMWV_Gunner/CROWS_HMMWV_Gunner.h"

ACROWS_HMMWV_Gunner::ACROWS_HMMWV_Gunner()
{
	//		\\PositionTypes =
}

void ACROWS_HMMWV_Gunner::AttachBodyPanels()
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

bool ACROWS_HMMWV_Gunner::PanelUsedBy(APawn* User, int32 Id)
{
	/*
	if (User.IsHumanControlled())
	{
		if (Id == PANEL_Collision_CROWS_Interface && User == Positions[0])
		{
			CROWS_Gunner(Positions[0]).ActivateCrows();
			Return True;
		}
		else
		{
			if (Id == PANEL_Collision_Door_LB && !bDoorsLocked)
			{
				Return DoDoor(User, Positions[0], Positions[4]);
			}
		}
	}
	*/
	return false;
}

bool ACROWS_HMMWV_Gunner::TryToDrive(APawn* p)
{
	/*
	if (TryToDrive(p))
	{
		if (!p.IsHumanControlled())
		{
			Ignition();
		}
		Return True;
	}
	*/
	return false;
}

void ACROWS_HMMWV_Gunner::Touch(AActor* Other)
{
	/*
	Touch(Other);
	if (Controller != None && Other != LastTouch)
	{
		Controller.Touch(Other);
		LastTouch = Other;
	}
	*/
}