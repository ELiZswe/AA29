// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_CP_PunkBuster/AAGameMenu_CP_PunkBuster.h"

UAAGameMenu_CP_PunkBuster::UAAGameMenu_CP_PunkBuster()
{
	//mchkbPBEnabled = moCheckBox'AGP_Interface.AAGameMenu_CP_PunkBuster.PBEnabledCheckbox';
	sInstructions = "Use this to customize your PunkBuster settings.";
	WinHeight = 1;
}

void UAAGameMenu_CP_PunkBuster::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	gulInstructions.Caption = sInstructions;
	*/
}

void UAAGameMenu_CP_PunkBuster::InitializeDataFields()
{
	/*
	if (aagpCommandPost != None)
	{
		HumanController(PlayerOwner()).RequestPBSetting(aagpCommandPost, "PunkBuster", "PBEnabled");
	}
	*/
}

bool UAAGameMenu_CP_PunkBuster::IsAdmin()
{
	//Return PlayerOwner() != None && PlayerOwner().PlayerReplicationInfo != None && PlayerOwner().PlayerReplicationInfo.bAdmin;
	return false;    //FAKE   /ELiZ

}

bool UAAGameMenu_CP_PunkBuster::CanShowPanel()
{
	return true;
}

void UAAGameMenu_CP_PunkBuster::InternalOnChange(UGUIComponent* Sender)
{
	/*
	Switch(Sender)
	{
			case mchkbPBEnabled:
				if (mchkbPBEnabled.IsChecked())
				{
					HumanController(PlayerOwner()).ConsoleCommand("admin pb_sv_enable");
					break;
				}
				HumanController(PlayerOwner()).ConsoleCommand("admin pb_sv_disable");
	}
	GOTO JL0079;
		default:
		JL0079:
		*/
}

void UAAGameMenu_CP_PunkBuster::NotifyCustomParameters(FString sParam1, FString sParam2, FString sParam3)
{
	/*
	if (sParam1 ~= "INIEntry")
	{
		if (sParam2 ~= "PBEnabled")
		{
			if (sParam3 ~= "1")
			{
				mchkbPBEnabled.SetComponentValue(True);
			}
			else
			{
				mchkbPBEnabled.SetComponentValue(False);
			}
		}
	}
	*/
}
