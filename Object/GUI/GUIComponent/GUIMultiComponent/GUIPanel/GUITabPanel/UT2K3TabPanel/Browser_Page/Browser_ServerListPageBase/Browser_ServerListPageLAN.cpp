// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_ServerListPageBase/Browser_ServerListPageLAN.h"
#include "AA29/Object/Actor/Info/MasterServerLink/ServerQueryClient/LANQueryClient/LANQueryClient.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIPanel.h"

UBrowser_ServerListPageLAN::UBrowser_ServerListPageLAN()
{
	ConnectLAN = true;
}

void UBrowser_ServerListPageLAN::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	Cast<UGUIButton>(Cast<UGUIPanel>(Controls[1]).Controls[6]).bVisible = false;
	Cast<UGUIButton>(Cast<UGUIPanel>(Controls[1]).Controls[7]).bVisible = false;
	StatusBar.WinWidth = 1;
	if (LQC == nullptr)
	{
		LQC = PlayerOwner().Level.Spawn(ALANQueryClient::StaticClass());
		LQC.__OnReceivedPingInfo__Delegate = MyReceivedPingInfo;
		LQC.__OnPingTimeout__Delegate = MyServersList.MyPingTimeout;
	}
	MyServersList.InitColumnPerc[0] = 0;
	MyServersList.InitColumnPerc[1] = 0.47;
	MyServersList.InitColumnPerc[2] = 0.25;
	MyServersList.InitColumnPerc[3] = 0.13;
	MyServersList.InitColumnPerc[4] = 0.15;
	RefreshList();
	*/
}

void UBrowser_ServerListPageLAN::OnCloseBrowser()
{
	/*
	if (LQC != nullptr)
	{
		LQC->Destroy();
		LQC = nullptr;
	}
	*/
}

void UBrowser_ServerListPageLAN::MyReceivedPingInfo(int32 ServerID, EPingCause PingCause, FServerResponseLine S)
{
	/*
	int32 i = 0;
	if (ServerID < 0)
	{
		for (i = 0; i < MyServersList.Servers.Num(); i++)
		{
			if ((MyServersList.Servers[i].IP == S.IP) && (MyServersList.Servers[i].Port == S.Port))
			{
				return;
			}
		}
		MyServersList.MyOnReceivedServer(S);
	}
	else
	{
		MyServersList.MyReceivedPingInfo(ServerID, PingCause, S);
	}
	*/
}

void UBrowser_ServerListPageLAN::PingServer(int32 ListID, EPingCause PingCause, FServerResponseLine S)
{
	//LQC.PingServer(ListID, PingCause, S.IP, S.QueryPort, 3, S);
}

void UBrowser_ServerListPageLAN::CancelPings()
{
	//LQC.CancelPings();
}

void UBrowser_ServerListPageLAN::RefreshList()
{
	/*
	MyServersList.Clear();
	CancelPings();
	LQC.BroadcastPingRequest();
	*/
}
