// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_ServerListPageBase/AABrowser_ServerListPageLAN.h"
#include "AA29/Object/Actor/Info/MasterServerLink/ServerQueryClient/LANQueryClient/LANQueryClient.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/Actor/ServerBrowserBase/ServerBrowserBase.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

UAABrowser_ServerListPageLAN::UAABrowser_ServerListPageLAN()
{
	ConnectLAN = true;
	PanelCaption = "Server Browser : LAN";

}

void UAABrowser_ServerListPageLAN::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	CheckFilterButton(true);
}

void UAABrowser_ServerListPageLAN::Opened(UGUIComponent* Sender)
{
	Super::Opened(Sender);
	if ((!bInit) && bVisible)
	{
		SetTimer(10, true);
	}
}

void UAABrowser_ServerListPageLAN::ShowPanel(bool bShow)
{
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
}

void UAABrowser_ServerListPageLAN::Timer()
{
	Super::Timer();
	RefreshList();
}

void UAABrowser_ServerListPageLAN::Refresh()
{
	Super::Refresh();
	ResetQueryClient(GetClient());
	RefreshList();
}

void UAABrowser_ServerListPageLAN::RefreshList()
{
	FString S = "";
	/*
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
	if (HasClient())
	{
		LQC->CancelPings();
	}
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
	return (LQC != nullptr);
}

ALANQueryClient* UAABrowser_ServerListPageLAN::GetClient()
{
	int32 i = 0;
	if (LQC == nullptr)
	{
		/*
		LQC = PlayerOwner().Level.Spawn(Class'ALANQueryClient*');
		Log(string(Name) @ "Spawning new LAN query client '" + FString::FromInt(LQC) + "'");
		if ((LQC != nullptr) && LQC.NetworkError())
		{
			do
			{
				Log(string(Name) @ "- Network error in query client - retrying  " + FString::FromInt(i));
				LQC.Destroy();
				LQC = PlayerOwner().Spawn(Class'ALANQueryClient*');
			}
			until(((!LQC.NetworkError()) || ((++i) < 10)));
			if (i >= 10)
			{
				ShowNetworkError();
				return nullptr;
			}
		}
		*/
	}
	return LQC;
}

void UAABrowser_ServerListPageLAN::OnDestroyPanel(bool bCancelled)
{
	Super::OnDestroyPanel(bCancelled);
	ClearQueryClient();
}

void UAABrowser_ServerListPageLAN::LevelChanged()
{
	Super::LevelChanged();
	ClearQueryClient();
}

void UAABrowser_ServerListPageLAN::Free()
{
	Super::Free();
	ClearQueryClient();
}

void UAABrowser_ServerListPageLAN::ClearQueryClient()
{
	if (LQC != nullptr)
	{
		//Log(string(Name) @ "Destroying LAN query client '" + LQC + "'");
		LQC->CancelPings();
		LQC->Destroy();
		LQC = nullptr;
	}
}

void UAABrowser_ServerListPageLAN::NetworkErrorClosed(bool bCancelled)
{
	if (!bCancelled)
	{
		GetClient();
	}
}

void UAABrowser_ServerListPageLAN::CheckFilterButton(bool Available)
{
	//DisableComponent(b_Filter);
}

void UAABrowser_ServerListPageLAN::RefreshSBList()
{
	FString sFilterString = "";
	AServerBrowserBase* sbBase = nullptr;
	/*
	Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD).LanServerBrowser = true;
	sbBase = Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD).GetCurrentServerBrowser(true);
	if (sbBase == nullptr)
	{
		return;
	}
	sbBase.__OnReceivedServer__Delegate = li_Server.MyOnReceivedSB;
	sbBase.SetPublic(false);
	sbBase.SetFilter(sFilterString);
	sbBase.UpdateServerList();
	*/
}
