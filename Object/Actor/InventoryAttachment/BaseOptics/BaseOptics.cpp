// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/BaseOptics/BaseOptics.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

void ABaseOptics::BeginPlay()
{
	Super::BeginPlay();

}

// Sets default values
ABaseOptics::ABaseOptics()
{
	Icon = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_optics_NVG7D.hud_optics_NVG7D"), NULL, LOAD_None, NULL);
}

/*
 // ======================================================================================
 // AGP function - Toggle
 // Toggles this device on/off.
 // last modified by:  superville 03/15/02
 // ======================================================================================
*/

void ABaseOptics::Toggle()
{
	if (IsActive())
	{
		Deactivate();
	}
	else
	{
		Activate();
	}
}

/*
 // ======================================================================================
 // AGP function - Activate
 // Activates optics by setting bIsActive to true
 // last modified by:  superville 03/18/02
 // ======================================================================================
*/
void ABaseOptics::Activate()
{
	//if (!bIsActive)
	//{
	//	bIsActive = true;
	//	StatusChanged();
	//}
}

/*
 // ======================================================================================
 // AGP function - Deactivate
 // Activates optics by setting bIsActive to true
 // last modified by:  superville 03/18/02
 // ======================================================================================
*/
void ABaseOptics::Deactivate()
{
	if (bIsActive)
	{
		bIsActive = false;
		StatusChanged();
	}
}

void ABaseOptics::CleanUp()
{

}

/*
 // ======================================================================================
 // AGP function - StatusChanged
 // Handles effects of activating/deactivating these optics. Should be overridden in child
 // classes
 // last modified by:  superville 03/18/02
 // ======================================================================================
*/
void ABaseOptics::StatusChanged()
{
	if (GetOwner()->IsA(AAGP_Pawn::StaticClass()))
	{
		Cast<AAGP_Pawn>(GetOwner())->NotifyOpticsStatusChangingTo(bIsActive);
	}

}

/*
 // ======================================================================================
 // AGP function - IsActive
 // Tells if this device is currently active
 // output:	bool TRUE if the device is on, false otherwise
 // last modified by:  superville 03/15/02
 // ======================================================================================
*/
bool ABaseOptics::IsActive()
{
	return bIsActive;
}

void ABaseOptics::DoAttachStuffWhichShouldBeDoneInInventory()
{

}

void ABaseOptics::NotifyBRoll(bool bRoll)
{

}
