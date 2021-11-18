// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_ServerListPageBase/AABrowser_ServerListPageMS.h"

UAABrowser_ServerListPageMS::UAABrowser_ServerListPageMS()
{
	PanelCaption = "Server Browser : Internet";
}

void UAABrowser_ServerListPageMS::ShowPanel(bool bShow)
{
	//Super::ShowPanel(bShow);
}

void UAABrowser_ServerListPageMS::Refresh()
{
	//Super::Refresh();
}

void UAABrowser_ServerListPageMS::ResetQueryClient(AServerQueryClient* Client)
{
	/*
	Super::ResetQueryClient(Client);
	if (MasterServerClient(Client) != None)
	{
		MasterServerClient(Client).Query.Length = 0;
	}
	*/
}

void UAABrowser_ServerListPageMS::BindQueryClient(AServerQueryClient* Client)
{
	/*
	Super::BindQueryClient(Client);
	if (MasterServerClient(Client) != None)
	{
		MasterServerClient(Client).__OnQueryFinished__Delegate = QueryComplete;
		MasterServerClient(Client).__OnReceivedServer__Delegate = li_Server.MyOnReceivedServer;
	}
	*/
}

void UAABrowser_ServerListPageMS::QueryComplete(EResponseInfo ResponseInfo, int32 Info)
{
	/*
	li_Server.MyQueryFinished(ResponseInfo, Info);
	switch (ResponseInfo)
	{
	case 3:
		break;
	case 0:
		break;
	case 1:
		li_Server.FakeFinished();
		break;
	case 2:
		li_Server.FakeFinished();
		break;
	case 4:
		break;
	default:
	}
	*/
}

void UAABrowser_ServerListPageMS::ReceivedPingInfo(int32 ServerID, EPingCause PingCause, FServerResponseLine S)
{
	/*
	li_Server.MyReceivedPingInfo(ServerID, PingCause, S);
	if (PingCause == 2)
	{
		UpdateStatusPingCount();
	}
	*/
}

void UAABrowser_ServerListPageMS::ReceivedPingTimeout(int32 ListID, EPingCause PingCause)
{
	/*
	li_Server.MyPingTimeout(ListID, PingCause);
	if (PingCause == 2)
	{
		UpdateStatusPingCount();
	}
	*/
}

