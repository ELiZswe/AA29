// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_CP_PunkBuster/AAGameMenu_CP_PunkBuster.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAGameMenu_CommandPost/AAGameMenu_CommandPost.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

UAAGameMenu_CP_PunkBuster::UAAGameMenu_CP_PunkBuster()
{
	UmoCheckBox* PBEnabledCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	PBEnabledCheckbox->CaptionWidth = 0.9;
	PBEnabledCheckbox->Caption = "Enable PunkBuster";
	//PBEnabledCheckbox->OnCreateComponent=PBEnabledCheckbox.InternalOnCreateComponent;
	PBEnabledCheckbox->IniOption = "@Internal";
	PBEnabledCheckbox->Hint = "Check this box to enable PunkBuster.";
	PBEnabledCheckbox->WinTop = 0.2;
	PBEnabledCheckbox->WinLeft = 0.05;
	PBEnabledCheckbox->WinWidth = 0.4;
	PBEnabledCheckbox->WinHeight = 0.06;
	PBEnabledCheckbox->TabOrder = 1;
	PBEnabledCheckbox->bStandardized = false;
	//PBEnabledCheckbox->OnChange=AAGameMenu_CP_PunkBuster.InternalOnChange;
	mchkbPBEnabled = PBEnabledCheckbox;
	
	sInstructions = "Use this to customize your PunkBuster settings.";
	WinHeight = 1;
}

void UAAGameMenu_CP_PunkBuster::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	gulInstructions->Caption = sInstructions;
}

void UAAGameMenu_CP_PunkBuster::InitializeDataFields()
{
	if (aagpCommandPost != nullptr)
	{
		Cast<AHumanController>(PlayerOwner())->RequestPBSetting(aagpCommandPost, "PunkBuster", "PBEnabled");
	}
}

bool UAAGameMenu_CP_PunkBuster::IsAdmin()
{
	//return PlayerOwner() != nullptr && PlayerOwner().PlayerReplicationInfo != nullptr && PlayerOwner().PlayerReplicationInfo.bAdmin;
	return false;    //FAKE   /ELiZ

}

bool UAAGameMenu_CP_PunkBuster::CanShowPanel()
{
	return true;
}

void UAAGameMenu_CP_PunkBuster::InternalOnChange(UGUIComponent* Sender)
{
	/*
	switch(Sender)
	{
			case mchkbPBEnabled:
				if (mchkbPBEnabled.IsChecked())
				{
					Cast<AHumanController>(PlayerOwner())->ConsoleCommand("admin pb_sv_enable");
					break;
				}
				Cast<AHumanController>(PlayerOwner())->ConsoleCommand("admin pb_sv_disable");
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
				mchkbPBEnabled.SetComponentValue(true);
			}
			else
			{
				mchkbPBEnabled.SetComponentValue(false);
			}
		}
	}
	*/
}
