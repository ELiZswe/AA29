// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_SPPanelBase/Tab_SPPanelBase.h"
#include "AA29/Object/GameProfile/GameProfile.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/GUITabControl.h"

UTab_SPPanelBase::UTab_SPPanelBase()
{

}

void UTab_SPPanelBase::OnProfileUpdated()
{
}

void UTab_SPPanelBase::OnMatchUpdated(int32 iLadder, int32 iMatch)
{
}

UGameProfile* UTab_SPPanelBase::GetProfile()
{
	//return PlayerOwner().Level.Game.CurrentGameProfile;
	return nullptr;    //FAKE   /ELiZ
}

UGUITabControl* UTab_SPPanelBase::MyTabControl()
{
	/*
	if ((MyButton != nullptr) && (MyButton.MenuOwner != nullptr))
	{
		return Cast<UGUITabControl>(MyButton.MenuOwner);
	}
	if ((MenuOwner != nullptr) && MenuOwner->isA(UGUITabControl::StaticClass()))
	{
		return Cast<UGUITabControl>(MenuOwner);
	}
	*/
	return nullptr;
}

void UTab_SPPanelBase::ProfileUpdated()
{
	UGUITabControl* TC = nullptr;
	int32 i = 0;
	TC = MyTabControl();
	/*
	if (TC != nullptr)
	{
		for (i = 0; i < TC.Controls.Num(); i++)
		{
			if (Tab_SPPanelBase(TC.Controls[i]) != nullptr)
			{
				Tab_SPPanelBase(TC.Controls[i]).OnProfileUpdated();
			}
		}
	}
	UT2SinglePlayerMain(MyTabControl().MenuOwner).ProfileUpdated();
	*/
}

void UTab_SPPanelBase::MatchUpdated(int32 iLadder, int32 iMatch)
{
	UGUITabControl* TC = nullptr;
	int32 i = 0;
	TC = MyTabControl();
	/*
	if (TC != nullptr)
	{
		for (i = 0; i < TC.Controls.Num(); i++)
		{
			if (Tab_SPPanelBase(TC.Controls[i]) != nullptr)
			{
				Tab_SPPanelBase(TC.Controls[i]).OnMatchUpdated(iLadder, iMatch);
			}
		}
	}
	*/
}
