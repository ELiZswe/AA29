// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_IRC/AABrowser_IRC.h"

UAABrowser_IRC::UAABrowser_IRC()
{
	/*
	Begin Object Class=GUITabControl Name=ChannelTabControl
		bDockPanels=True
		TabHeight=0.04
		WinTop=0.07
		WinLeft=0.01
		WinWidth=0.98
		WinHeight=0.92
		bAcceptsInput=True
		OnActivate=ChannelTabControl.InternalOnActivate
	End Object
	*/
	//c_Channel = GUITabControl'AGP_Interface.AABrowser_IRC.ChannelTabControl';
	SystemPageClass = "AGP_Interface.AAIRC_System";
	PublicChannelClass = "AGP_Interface.AAIRC_Channel";
	PrivateChannelClass = "AGP_Interface.AAIRC_Private";
	SystemLabel = "System";
	PanelCaption = "America's Army Internet Chat Client";
}


void UAABrowser_IRC::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	c_Channel.__OnChange__Delegate = TabChange;
	tp_System = AAIRC_System(c_Channel.AddTab(SystemLabel, SystemPageClass, , , true));
	tp_System.__OnDisconnect__Delegate = IRCDisconnected;
	tp_System.__NewChannelSelected__Delegate = SetCurrentChannel;
	*/
}

void UAABrowser_IRC::IRCDisconnected()
{
	/*
	local int32 i;
	i = (c_Channel.TabStack.Length - 1);
	if (i >= 0)
	{
		if ((c_Channel.TabStack[i] != None) && (c_Channel.TabStack[i].MyPanel != tp_System))
		{
			c_Channel.RemoveTab("", c_Channel.TabStack[i]);
		}
		(i);
	}
	*/
}

void UAABrowser_IRC::Closed(UGUIComponent* Sender, bool bCancelled)
{
	/*
	Super::Closed(Sender, bCancelled);
	tp_System.IRCClosed();
	*/
}

void UAABrowser_IRC::ShowPanel(bool bShow)
{
	/*
	Super::ShowPanel(bShow);
	if (bInit && bShow)
	{
		tp_System.SetCurrentChannel(-1);
		bInit = false;
	}
	*/
}

void UAABrowser_IRC::TabChange(UGUIComponent* Sender)
{
	/*
	local int32 i;
	local XInterface.GUITabButton TabButton;
	TabButton = GUITabButton(Sender);
	if ((TabButton == None) || (!Controller.bCurMenuInitialized))
	{
		return;
	}
	i = tp_System.FindPublicChannelIndex(TabButton.Caption, true);
	UpdateCurrentChannel(i);
	*/
}

void UAABrowser_IRC::SetCurrentChannel(int32 Index)
{
	/*
	local XInterface.GUITabButton But;
	local int32 i;
	if (Index == -1)
	{
		But = tp_System.MyButton;
	}
	else
	{
		i = c_Channel.TabIndex(tp_System.Channels[Index].ChannelName);
		if ((i >= 0) && (i < c_Channel.TabStack.Length))
		{
			But = c_Channel.TabStack[i];
		}
	}
	c_Channel.ActivateTab(But, true);
	*/
}

void UAABrowser_IRC::UpdateCurrentChannel(int32 Index)
{
	//tp_System.UpdateCurrentChannel(Index);
}

void UAABrowser_IRC::SetCloseCaption(FString NewName)
{
}

UAAIRC_Channel* UAABrowser_IRC::AddChannel(FString ChannelName, bool bPrivate)
{
	//return AAIRC_Channel(c_Channel.AddTab(ChannelName, Eval(bPrivate, PrivateChannelClass, PublicChannelClass)));
	return nullptr;      //FAKE   /ELiZ
}

bool UAABrowser_IRC::RemoveChannel(FString ChannelName)
{
	/*
	if ((ChannelName ~= SystemLabel) || (ChannelName == ""))
	{
		return false;
	}
	c_Channel.RemoveTab(ChannelName);
	*/
	return true;
}

void UAABrowser_IRC::JoinClicked()
{
	/*
	if (tp_System != None)
	{
		tp_System.ChangeCurrentNick();
	}
	*/
}

void UAABrowser_IRC::RefreshClicked()
{
	/*
	if (tp_System != None)
	{
		tp_System.Disconnect();
	}
	*/
}

bool UAABrowser_IRC::IsRefreshAvailable(FString& ButtonCaption)
{
	//return ((tp_System != None) && tp_System.DisconnectAvailable(ButtonCaption));
	return false;
}

bool UAABrowser_IRC::IsJoinAvailable(FString& ButtonCaption)
{
	//return ((tp_System != None) && tp_System.SetNickAvailable(ButtonCaption));
	return true;
}
