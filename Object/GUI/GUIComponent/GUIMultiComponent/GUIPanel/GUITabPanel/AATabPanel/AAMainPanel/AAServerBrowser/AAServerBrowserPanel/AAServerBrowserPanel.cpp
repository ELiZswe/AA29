// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AAServerBrowser/AAServerBrowserPanel/AAServerBrowserPanel.h"

UAAServerBrowserPanel::UAAServerBrowserPanel()
{

}



void UAAServerBrowserPanel::CheckPlayerOptions()
{
	/*
	Super::CheckPlayerOptions();
	CheckPunkBusterNotice();
	*/
}

void UAAServerBrowserPanel::CheckPunkBusterNotice()
{
	/*
	local FString sFile;
	local FString sSection;
	local FString sKey;
	local int32 PBNotice;
	local int32 PBEnabled;
	sFile = GetBaseDir() $ "ArmyOps.ini";
	sSection = "FirstRun";
	sKey = "PBNotice";
	PBNotice = GetPrivateProfileInt(sFile, sSection, sKey);
	PBEnabled = PlayerOwner().Level.PBIsEnabled();
	if (PBNotice != 1)
	{
		if (PBNotice != 99)
		{
			SetPrivateProfileInt(1, sFile, sSection, sKey);
		}
		if (PBEnabled != 1)
		{
		}
	}
	*/
}

bool UAAServerBrowserPanel::InternetOptionsConfirm(uint8 ButtonMask)
{
	//return Super::InternetOptionsConfirm(ButtonMask);
	return false;   //FAKE   /ELiZ
}

