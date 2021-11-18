// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_ServerListPageBase/Browser_ServerListPageFavorites.h"

UBrowser_ServerListPageFavorites::UBrowser_ServerListPageFavorites()
{
	RemoveFavoriteCaption = "REMOVE FAVORITE";
	AddIPCaption = "ADD IP";
	RePingCaption = "RE-PING LIST";
}

void UBrowser_ServerListPageFavorites::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	local GameInfo.ServerResponseLine Server;
	Super::InitComponent(MyController, MyOwner);
	Browser.__OnAddFavorite__Delegate = MyAddFavorite;
	if (SQC == None)
	{
		SQC = PlayerOwner().Level.Spawn(Class'IpDrv.ServerQueryClient');
		SQC.__OnReceivedPingInfo__Delegate = MyServersList.MyReceivedPingInfo;
		SQC.__OnPingTimeout__Delegate = MyServersList.MyPingTimeout;
	}
	MyServersList.Clear();
	for (i = 0; i < Default.Favorites.Length; i++)
	{
		FavoriteToServer(i, Server);
		MyServersList.MyOnReceivedServer(Server);
	}
	GUIButton(GUIPanel(Controls[1]).Controls[1]).Caption = RePingCaption;
	GUIButton(GUIPanel(Controls[1]).Controls[4]).__OnClick__Delegate = RemoveFavoriteClick;
	GUIButton(GUIPanel(Controls[1]).Controls[4]).Caption = RemoveFavoriteCaption;
	GUIButton(GUIPanel(Controls[1]).Controls[7]).__OnClick__Delegate = AddIPClick;
	GUIButton(GUIPanel(Controls[1]).Controls[7]).Caption = AddIPCaption;
	GUIButton(GUIPanel(Controls[1]).Controls[6]).bVisible = false;
	StatusBar.WinWidth = 0.8;
	MyServersList.InitColumnPerc[0] = 0;
	MyServersList.InitColumnPerc[1] = 0.47;
	MyServersList.InitColumnPerc[2] = 0.25;
	MyServersList.InitColumnPerc[3] = 0.13;
	MyServersList.InitColumnPerc[4] = 0.15;
	*/
}

bool UBrowser_ServerListPageFavorites::AddIPClick(UGUIComponent* Sender)
{
	/*
	if (Controller.OpenMenu("xinterface.Browser_OpenIP"))
	{
		Browser_OpenIP(Controller.TopPage()).MyFavoritesPage = Self;
	}
	*/
	return true;
}

void UBrowser_ServerListPageFavorites::RefreshList()
{
	//MyServersList.InvalidatePings();
	//MyServersList.AutopingServers();
}

void UBrowser_ServerListPageFavorites::ShowPanel(bool bShow)
{
	/*
	Super::ShowPanel(bShow);
	if (bShow)
	{
		Log(MyButton.Caption $ ": Resuming pings");
		MyServersList.AutopingServers();
	}
	else
	{
		Log(MyButton.Caption $ ": Cancelling pings");
		MyServersList.StopPings();
	}
	*/
}

void UBrowser_ServerListPageFavorites::CancelPings()
{
	//SQC.CancelPings();
}

void UBrowser_ServerListPageFavorites::OnCloseBrowser()
{
	/*
	if (SQC != None)
	{
		SaveFavorites();
		SQC.CancelPings();
		SQC.Destroy();
		SQC = None;
	}
	*/
}

void UBrowser_ServerListPageFavorites::PingServer(int32 ListID, EPingCause PingCause, FServerResponseLine S)
{
	/*
	if (PingCause == 1)
	{
		SQC.PingServer(ListID, PingCause, S.IP, S.QueryPort, 3, S);
	}
	else
	{
		SQC.PingServer(ListID, PingCause, S.IP, S.QueryPort, 0, S);
	}
	*/
}

bool UBrowser_ServerListPageFavorites::RemoveFavoriteClick(UGUIComponent* Sender)
{
	/*
	int32 i = 0;
	i = MyServersList.RemoveCurrentServer();
	if (i >= 0)
	{
		Default.Favorites.remove(i, 1);
		SaveFavorites();
	}
	*/
	return true;
}

void UBrowser_ServerListPageFavorites::SaveFavorites()
{
	/*
	int32 i = 0;
	Default.Favorites.Length = MyServersList.Servers.Length;
	for (i = 0; i < MyServersList.Servers.Length; i++)
	{
		Default.Favorites[i].ServerID = MyServersList.Servers[i].ServerID;
		Default.Favorites[i].IP = MyServersList.Servers[i].IP;
		Default.Favorites[i].Port = MyServersList.Servers[i].Port;
		Default.Favorites[i].QueryPort = MyServersList.Servers[i].QueryPort;
		Default.Favorites[i].ServerName = MyServersList.Servers[i].ServerName;
	}
	StaticSaveConfig();
	*/
}

void UBrowser_ServerListPageFavorites::FavoriteToServer(int32 i, FServerResponseLine& Server)
{
	/*
	Server.ServerID = Default.Favorites[i].ServerID;
	Server.IP = Default.Favorites[i].IP;
	Server.Port = Default.Favorites[i].Port;
	Server.QueryPort = Default.Favorites[i].QueryPort;
	Server.ServerName = Default.Favorites[i].ServerName;
	*/
}

void UBrowser_ServerListPageFavorites::MyAddFavorite(FServerResponseLine Server)
{
	/*
	int32 i = 0;
	for (i = 0; i < Default.Favorites.Length; i++)
	{
		if ((Default.Favorites[i].IP == Server.IP) && (Default.Favorites[i].Port == Server.Port))
		{
			return;
		}
	}
	MyServersList.MyOnReceivedServer(Server);
	SaveFavorites();
	*/
}

void UBrowser_ServerListPageFavorites::StaticAddFavorite(FString IPString, int32 Port, int32 QueryPort)
{
	/*
	int32 numFavorites = 0;
	Log("StaticAddFavorite:" @ IPString @ string(Port) @ string(QueryPort));
	numFavorites = Default.Favorites.Length;
	Default.Favorites.Length = (numFavorites + 1);
	Default.Favorites[numFavorites].IP = IPString;
	Default.Favorites[numFavorites].Port = Port;
	Default.Favorites[numFavorites].QueryPort = QueryPort;
	Default.Favorites[numFavorites].ServerName = "Unknown";
	StaticSaveConfig();
	*/
}