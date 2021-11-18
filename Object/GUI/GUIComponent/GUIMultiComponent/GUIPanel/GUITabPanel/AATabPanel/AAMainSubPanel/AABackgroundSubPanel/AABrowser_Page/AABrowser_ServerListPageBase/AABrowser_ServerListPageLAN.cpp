// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_ServerListPageBase/AABrowser_ServerListPageLAN.h"

UAABrowser_ServerListPageLAN::UAABrowser_ServerListPageLAN()
{
	ConnectLAN = true;
	PanelCaption = "Server Browser : LAN";

}

void UAABrowser_ServerListPageLAN::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	CheckFilterButton(true);
	*/
}

void UAABrowser_ServerListPageLAN::Opened(UGUIComponent* Sender)
{
	/*
	Super::Opened(Sender);
	if ((!bInit) && bVisible)
	{
		SetTimer(10, true);
	}
	*/
}

void UAABrowser_ServerListPageLAN::ShowPanel(bool bShow)
{
	/*
	Super::ShowPanel(bShow);
	if (bShow)
	{
		SetTimer(10, true);
		bInit = false;
	}
	else
	{
		KillTimer();
	}
	*/
}

void UAABrowser_ServerListPageLAN::Timer()
{
	/*
	Super::Timer();
	RefreshList();
	*/
}

void UAABrowser_ServerListPageLAN::Refresh()
{
	/*
	Super::Refresh();
	ResetQueryClient(GetClient());
	RefreshList();
	*/
}

void UAABrowser_ServerListPageLAN::RefreshList()
{
	/*
	local FString S;
	CancelPings();
	S = li_Server.Get();
	if ((S == "") || (!Divide(S, ":", StoredIP, StoredPort)))
	{
		StoredIP = "";
		StoredPort = "";
	}
	RefreshSBList();
	li_Server.Clear();
	GetClient().BroadcastPingRequest();
	*/
}

void UAABrowser_ServerListPageLAN::ReceivedPingInfo(int32 ServerID, EPingCause PingCause, FServerResponseLine S)
{
}

void UAABrowser_ServerListPageLAN::CancelPings()
{
	/*
	if (HasClient())
	{
		LQC.CancelPings();
	}
	*/
}

void UAABrowser_ServerListPageLAN::PingServer(int32 ListID, EPingCause PingCause, FServerResponseLine S)
{
	//GetClient().PingServer(ListID, PingCause, S.IP, S.QueryPort, 3, S);
}

void UAABrowser_ServerListPageLAN::UpdateStatusPingCount()
{
}

bool UAABrowser_ServerListPageLAN::HasClient()
{
	//return (LQC != nullptr);
	return false;    //FAKE   /ELiZ
}
/*
ALANQueryClient* UAABrowser_ServerListPageLAN::GetClient()
{
	local int32 i;
	if (LQC == None)
	{
		LQC = PlayerOwner().Level.Spawn(Class'ALANQueryClient*');
		Log(string(Name) @ "Spawning new LAN query client '" $ string(LQC) $ "'");
		if ((LQC != None) && LQC.NetworkError())
		{
			do
			{
				Log(string(Name) @ "- Network error in query client - retrying  " $ string(i));
				LQC.Destroy();
				LQC = PlayerOwner().Spawn(Class'ALANQueryClient*');
			}
			until(((!LQC.NetworkError()) || ((++i) < 10)));
			if (i >= 10)
			{
				ShowNetworkError();
				return None;
			}
		}
	}
	return LQC;
}
*/

void UAABrowser_ServerListPageLAN::OnDestroyPanel(bool bCancelled)
{
	/*
	Super::OnDestroyPanel(bCancelled);
	ClearQueryClient();
	*/
}

void UAABrowser_ServerListPageLAN::LevelChanged()
{
	/*
	Super::LevelChanged();
	ClearQueryClient();
	*/
}

void UAABrowser_ServerListPageLAN::Free()
{
	/*
	Super::Free();
	ClearQueryClient();
	*/
}

void UAABrowser_ServerListPageLAN::ClearQueryClient()
{
	/*
	if (LQC != None)
	{
		Log(string(Name) @ "Destroying LAN query client '" $ string(LQC) $ "'");
		LQC.CancelPings();
		LQC.Destroy();
		LQC = None;
	}
	*/
}

void UAABrowser_ServerListPageLAN::NetworkErrorClosed(bool bCancelled)
{
	/*
	if (!bCancelled)
	{
		GetClient();
	}
	*/
}

void UAABrowser_ServerListPageLAN::CheckFilterButton(bool Available)
{
	//DisableComponent(b_Filter);
}

void UAABrowser_ServerListPageLAN::RefreshSBList()
{
	/*
	local FString sFilterString;
	local IpDrv.ServerBrowserBase sbBase;
	AGP_HUD(HumanController(PlayerOwner()).myHUD).LanServerBrowser = true;
	sbBase = AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser(true);
	if (sbBase == None)
	{
		return;
	}
	sbBase.__OnReceivedServer__Delegate = li_Server.MyOnReceivedSB;
	sbBase.SetPublic(false);
	sbBase.SetFilter(sFilterString);
	sbBase.UpdateServerList();
	*/
}
