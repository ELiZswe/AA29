// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_Page.h"
#include "AA29/Object/Actor/Info/MasterServerLink/ServerQueryClient/ServerQueryClient.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUIFooter/ButtonFooter/AABrowser_Footer/AABrowser_Footer.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AAServerBrowser/AAServerBrowser.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/Actor/Info/MasterServerLink/ServerQueryClient/MasterServerClient/MasterServerClient.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/GUIPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/GUITabControl.h"

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
	if (Cast<UAAServerBrowser>(MyOwner.MenuOwner) != nullptr)
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
	if ((Browser == nullptr) && (Cast<UAAServerBrowser>(Sender) != nullptr))
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
	FQueryData QD;
	/*
	int32 i = 0;
	for (i = 0; i < Browser.Uplink().Query.Num(); i++)
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
	if (Client == nullptr)
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
	if (Client == nullptr)
	{
		return;
	}
	Client.__OnReceivedPingInfo__Delegate = ReceivedPingInfo;
	Client.__OnPingTimeout__Delegate = ReceivedPingTimeout;
	*/
}

void UAABrowser_Page::CloseMSConnection()
{
	if (Browser != nullptr)
	{
		Browser->Uplink()->CancelPings();
		Browser->Uplink()->Stop();
	}
}

void UAABrowser_Page::CloseSBConnection()
{
}

void UAABrowser_Page::RefreshFooter(UAABrowser_Page* page, FString bPerButtonSizes)
{
}

void UAABrowser_Page::SetFooterCaption(FString NewCaption, bool bAppend)
{
	UGUITabControl* TC = nullptr;
	/*
	if (t_Footer == nullptr)
	{
		return;
	}
	TC = Cast<UGUITabControl>(MenuOwner);
	if (TC.PendingTab != nullptr)
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
	if (t_Footer == nullptr)
	{
		t_Footer = AABrowser_Footer(Browser.t_Footer);
	}
	if (bAppend)
	{
		NewCaption = t_Footer.t_StatusBar.GetCaption() + NewCaption;
	}
	t_Footer.t_StatusBar.SetCaption(NewCaption);
	CurrentFooterCaption = t_Footer.t_StatusBar.Caption;
	*/
}

void UAABrowser_Page::SetJoinCaption(FString NewCaption, bool bAppend)
{
	/*
	if ((t_Footer == nullptr) || (t_Footer.b_Join == nullptr))
	{
		return;
	}
	if (bAppend)
	{
		NewCaption = t_Footer.b_Join.Caption + NewCaption;
	}
	t_Footer.b_Join.Caption = NewCaption;
	*/
}

void UAABrowser_Page::SetSpectateCaption(FString NewCaption, bool bAppend)
{
	/*
	if ((t_Footer == nullptr) || (t_Footer.b_Spectate == nullptr))
	{
		return;
	}
	if (bAppend)
	{
		NewCaption = t_Footer.b_Spectate.Caption + NewCaption;
	}
	t_Footer.b_Spectate.Caption = NewCaption;
	*/
}

void UAABrowser_Page::SetRefreshCaption(FString NewCaption, bool bAppend)
{
	/*
	if ((t_Footer == nullptr) || (t_Footer.b_Refresh == nullptr))
	{
		return;
	}
	if (bAppend)
	{
		NewCaption = t_Footer.b_Refresh.Caption + NewCaption;
	}
	t_Footer.b_Refresh.Caption = NewCaption;
	*/
}

void UAABrowser_Page::CheckJoinButton(bool Available)
{
	/*
	if ((t_Footer == nullptr) || (t_Footer.b_Join == nullptr))
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
	if ((t_Footer == nullptr) || (t_Footer.b_Spectate == nullptr))
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
	if ((t_Footer == nullptr) || (t_Footer.b_Refresh == nullptr))
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
	UGUIPage* page = nullptr;
	/*
	if (ErrorMsg == "")
	{
		ErrorMsg = UnspecifiedNetworkError;
	}
	page = Controller.ShowQuestionDialog(ErrorMsg, 68, 64);
	if (page != nullptr)
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
	if ((t_Footer == nullptr) || (t_Footer.b_IconKey == nullptr))
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
