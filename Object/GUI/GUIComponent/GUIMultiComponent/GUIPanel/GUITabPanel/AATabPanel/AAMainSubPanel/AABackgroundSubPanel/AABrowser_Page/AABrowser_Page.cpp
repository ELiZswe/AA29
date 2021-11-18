// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_Page.h"

UAABrowser_Page::UAABrowser_Page()
{
	MustUpgradeString = "Upgrade available. Please refresh the News page.";
	QueryCompleteString = "Query Complete!";
	StartQueryString = "Querying Master Server";
	AuthFailString = "Authentication Failed";
	ConnFailString = "Connection Failed";
	ConnTimeoutString = "Connection Timed Out";
	RetryString = " - Retrying";
	ReadyString = "Ready";
	BackCaption = "BACK";
	RefreshCaption = "REFRESH";
	JoinCaption = "JOIN";
	SpectateCaption = "SPECTATE";
	FilterCaption = "FILTERS";
	UnspecifiedNetworkError = "There was an unknown error while attempting to connect to the network.";
	IconKeyCaption = "ICON KEY";
}


void UAABrowser_Page::OnOpenConnection(int32 Count)
{
}

void UAABrowser_Page::OnCloseConnection(int32 Count)
{
}

void UAABrowser_Page::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	if (AAServerBrowser(MyOwner.MenuOwner) != None)
	{
		Browser = AAServerBrowser(MyOwner.MenuOwner);
		t_Footer = AABrowser_Footer(Browser.t_Footer);
	}
	Super::InitComponent(MyController, MyOwner);
	CurrentFooterCaption = ReadyString;
	*/
}

void UAABrowser_Page::Opened(UGUIComponent* Sender)
{
	/*
	if ((Browser == None) && (AAServerBrowser(Sender) != None))
	{
		Browser = AAServerBrowser(Sender);
		t_Footer = AABrowser_Footer(Browser.t_Footer);
	}
	Super::Opened(Sender);
	*/
}

void UAABrowser_Page::ShowPanel(bool bShow)
{
	/*
	Super::ShowPanel(bShow);
	if (bShow)
	{
	}
	*/
}

bool UAABrowser_Page::InternalOnRightClick(UGUIComponent* Sender)
{
	return false;
}

void UAABrowser_Page::QueryComplete(EResponseInfo ResponseInfo, int32 Info)
{
}

void UAABrowser_Page::ReceivedPingInfo(int32 ServerID, EPingCause PingCause, FServerResponseLine S)
{
}

void UAABrowser_Page::ReceivedPingTimeout(int32 ListID, EPingCause PingCause)
{
}

void UAABrowser_Page::AddQueryTerm(FString Key, FString Value, EQueryType QueryType)
{
	/*
	local MasterServerClient.QueryData QD;
	local int32 i;
	for (i = 0; i < Browser.Uplink().Query.Length; i++)
	{
		QD = Browser.Uplink().Query[i];
		if (((QD.Key ~= Key) && (QD.Value ~= Value)) && (QD.QueryType == QueryType))
		{
			return;
		}
	}
	QD.Key = Key;
	QD.Value = Value;
	QD.QueryType = QueryType;
	Browser.Uplink().Query[i] = QD;
	*/
}

void UAABrowser_Page::ResetQueryClient(AServerQueryClient* Client)
{
	/*
	if (Client == None)
	{
		return;
	}
	Client.CancelPings();
	BindQueryClient(Client);
	SetFooterCaption(ReadyString);
	*/
}

void UAABrowser_Page::BindQueryClient(AServerQueryClient* Client)
{
	/*
	if (Client == None)
	{
		return;
	}
	Client.__OnReceivedPingInfo__Delegate = ReceivedPingInfo;
	Client.__OnPingTimeout__Delegate = ReceivedPingTimeout;
	*/
}

void UAABrowser_Page::CloseMSConnection()
{
	/*
	if (Browser != None)
	{
		Browser.Uplink().CancelPings();
		Browser.Uplink().Stop();
	}
	*/
}

void UAABrowser_Page::CloseSBConnection()
{
}

void UAABrowser_Page::RefreshFooter(UAABrowser_Page* page, FString bPerButtonSizes)
{
}

void UAABrowser_Page::SetFooterCaption(FString NewCaption, bool bAppend)
{
	/*
	local XInterface.GUITabControl TC;
	if (t_Footer == None)
	{
		return;
	}
	TC = GUITabControl(MenuOwner);
	if (TC.PendingTab != None)
	{
		if (TC.PendingTab != MyButton)
		{
			return;
		}
	}
	else
	{
		if (TC.ActiveTab != MyButton)
		{
			return;
		}
	}
	if (t_Footer == None)
	{
		t_Footer = AABrowser_Footer(Browser.t_Footer);
	}
	if (bAppend)
	{
		NewCaption = t_Footer.t_StatusBar.GetCaption() $ NewCaption;
	}
	t_Footer.t_StatusBar.SetCaption(NewCaption);
	CurrentFooterCaption = t_Footer.t_StatusBar.Caption;
	*/
}

void UAABrowser_Page::SetJoinCaption(FString NewCaption, bool bAppend)
{
	/*
	if ((t_Footer == None) || (t_Footer.b_Join == None))
	{
		return;
	}
	if (bAppend)
	{
		NewCaption = t_Footer.b_Join.Caption $ NewCaption;
	}
	t_Footer.b_Join.Caption = NewCaption;
	*/
}

void UAABrowser_Page::SetSpectateCaption(FString NewCaption, bool bAppend)
{
	/*
	if ((t_Footer == None) || (t_Footer.b_Spectate == None))
	{
		return;
	}
	if (bAppend)
	{
		NewCaption = t_Footer.b_Spectate.Caption $ NewCaption;
	}
	t_Footer.b_Spectate.Caption = NewCaption;
	*/
}

void UAABrowser_Page::SetRefreshCaption(FString NewCaption, bool bAppend)
{
	/*
	if ((t_Footer == None) || (t_Footer.b_Refresh == None))
	{
		return;
	}
	if (bAppend)
	{
		NewCaption = t_Footer.b_Refresh.Caption $ NewCaption;
	}
	t_Footer.b_Refresh.Caption = NewCaption;
	*/
}

void UAABrowser_Page::CheckJoinButton(bool Available)
{
	/*
	if ((t_Footer == None) || (t_Footer.b_Join == None))
	{
		return;
	}
	if (Available)
	{
		EnableComponent(t_Footer.b_Join);
	}
	else
	{
		DisableComponent(t_Footer.b_Join);
	}
	*/
}

void UAABrowser_Page::CheckSpectateButton(bool Available)
{
	/*
	if ((t_Footer == None) || (t_Footer.b_Spectate == None))
	{
		return;
	}
	if (Available)
	{
		EnableComponent(t_Footer.b_Spectate);
	}
	else
	{
		DisableComponent(t_Footer.b_Spectate);
	}
	*/
}

void UAABrowser_Page::CheckRefreshButton(bool Available)
{
	/*
	if ((t_Footer == None) || (t_Footer.b_Refresh == None))
	{
		return;
	}
	if (Available)
	{
		EnableComponent(t_Footer.b_Refresh);
	}
	else
	{
		DisableComponent(t_Footer.b_Refresh);
	}
	*/
}

void UAABrowser_Page::JoinClicked()
{
}

void UAABrowser_Page::SpectateClicked()
{
}

void UAABrowser_Page::FilterClicked()
{
}

void UAABrowser_Page::RefreshClicked()
{
	Refresh();
}

bool UAABrowser_Page::IsRefreshAvailable(FString& ButtonCaption)
{
	//ButtonCaption = RefreshCaption;
	return true;
}

bool UAABrowser_Page::IsSpectateAvailable(FString& ButtonCaption)
{
	//ButtonCaption = SpectateCaption;
	return true;
}

bool UAABrowser_Page::IsJoinAvailable(FString& ButtonCaption)
{
	//ButtonCaption = JoinCaption;
	return true;
}

bool UAABrowser_Page::IsFilterAvailable(FString& ButtonCaption)
{
	//ButtonCaption = FilterCaption;
	return true;
}

void UAABrowser_Page::ShowNetworkError(FString ErrorMsg)
{
	/*
	local XInterface.GUIPage page;
	if (ErrorMsg == "")
	{
		ErrorMsg = UnspecifiedNetworkError;
	}
	page = Controller.ShowQuestionDialog(ErrorMsg, 68, 64);
	if (page != None)
	{
		page.__OnClose__Delegate = NetworkErrorClosed;
	}
	*/
}

void UAABrowser_Page::NetworkErrorClosed(bool bCancelled)
{
}

void UAABrowser_Page::CheckFilterButton(bool Available)
{
}

void UAABrowser_Page::CheckIconKeyButton(bool Available)
{
	/*
	if ((t_Footer == None) || (t_Footer.b_IconKey == None))
	{
		return;
	}
	if (Available)
	{
		EnableComponent(t_Footer.b_IconKey);
	}
	else
	{
		DisableComponent(t_Footer.b_IconKey);
	}
	*/
}

void UAABrowser_Page::IconKeyClicked()
{
}

bool UAABrowser_Page::IsIconKeyAvailable(FString& ButtonCaption)
{
	//ButtonCaption = IconKeyCaption;
	return true;
}
