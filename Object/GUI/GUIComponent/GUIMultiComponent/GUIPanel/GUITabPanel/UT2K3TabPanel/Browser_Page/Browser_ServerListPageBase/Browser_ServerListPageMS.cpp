// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_ServerListPageBase/Browser_ServerListPageMS.h"
#include "AA29/Object/Actor/Info/MasterServerLink/ServerQueryClient/MasterServerClient/MasterServerClient.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/Actor/Info/MasterServerLink/ServerQueryClient/MasterServerClient/MasterServerClient.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/Browser_ServersList/Browser_ServersList.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUITitleBar/GUITitleBar.h"

UBrowser_ServerListPageMS::UBrowser_ServerListPageMS()
{
	QueryFinHead = "Query Complete! Received: ";
	QueryFinTail = " Servers";
	PingRecvString = "Pinging Servers";
	MustUpgradeString = "Upgrade available. Please refresh the News page.";
	RefreshFinHead = "Pinging Complete! ";
	RefreshFinMid = " Servers, ";
	RefreshFinTail = " Players";
	RePingServersCaption = "RE-PING LIST";
	RefreshCaption = "REFRESH LIST";
}

void UBrowser_ServerListPageMS::AddQueryTerm(FString Key, FString aGameType, EQueryType QueryType)
{
	FQueryData QD;
	int32 i = 0;
	QD.Key = Key;
	QD.Value = aGameType;
	QD.QueryType = QueryType;
	//MSC->Add(QD);
}

void UBrowser_ServerListPageMS::RefreshList()
{
	int32 dotPos = 0;
	FString tmpString = "";
	MyServersList->Clear();
	MSC->Query.Empty();
	/*
	AddQueryTerm("gametype", GameType, 0);
	if (Browser.bOnlyShowStandard)
	{
		AddQueryTerm("standard", "true", 0);
	}
	if (Browser.bOnlyShowNonPassword)
	{
		AddQueryTerm("password", "false", 0);
	}
	if (Browser.bDontShowFull)
	{
		AddQueryTerm("freespace", "0", 4);
	}
	if (Browser.bDontShowEmpty)
	{
		AddQueryTerm("currentplayers", "0", 4);
	}
	if (Browser.StatsServerView == 1)
	{
		AddQueryTerm("stats", "true", 0);
	}
	else
	{
		if (Browser.StatsServerView == 2)
		{
			AddQueryTerm("stats", "false", 0);
		}
	}
	dotPos = InStr(Browser.DesiredMutator, ".");
	if (dotPos < 0)
	{
		tmpString = Browser.DesiredMutator;
	}
	else
	{
		tmpString = Mid(Browser.DesiredMutator, (dotPos + 1));
	}
	if (Browser.ViewMutatorMode == 1)
	{
		AddQueryTerm("mutator", "", 0);
	}
	else
	{
		if ((Browser.ViewMutatorMode == 2) && (tmpString != ""))
		{
			AddQueryTerm("mutator", tmpString, 0);
		}
		else
		{
			if ((Browser.ViewMutatorMode == 3) && (tmpString != ""))
			{
				AddQueryTerm("mutator", tmpString, 1);
			}
		}
	}
	dotPos = InStr(Browser.DesiredMutator2, ".");
	if (dotPos < 0)
	{
		tmpString = Browser.DesiredMutator2;
	}
	else
	{
		tmpString = Mid(Browser.DesiredMutator2, (dotPos + 1));
	}
	if (Browser.ViewMutatorMode != 0)
	{
		if ((Browser.ViewMutator2Mode == 2) && (tmpString != ""))
		{
			AddQueryTerm("mutator", tmpString, 0);
		}
		else
		{
			if ((Browser.ViewMutator2Mode == 3) && (tmpString != ""))
			{
				AddQueryTerm("mutator", tmpString, 1);
			}
		}
	}
	if (Browser.bDontShowWithBots)
	{
		AddQueryTerm("nobots", "true", 0);
	}
	if (Browser.WeaponStayServerView == 1)
	{
		AddQueryTerm("weaponstay", "true", 0);
	}
	else
	{
		if (Browser.WeaponStayServerView == 2)
		{
			AddQueryTerm("weaponstay", "false", 0);
		}
	}
	if (Browser.TranslocServerView == 1)
	{
		AddQueryTerm("transloc", "true", 0);
	}
	else
	{
		if (Browser.TranslocServerView == 2)
		{
			AddQueryTerm("transloc", "false", 0);
		}
	}
	if (((Browser.MinGamespeed != 0) || (Browser.MaxGamespeed != 200)) && (Browser.MaxGamespeed >= Browser.MinGamespeed))
	{
		AddQueryTerm("gamespeed", FString::FromInt((float(Browser.MinGamespeed) / 100)), 5);
		AddQueryTerm("gamespeed", FString::FromInt((float(Browser.MaxGamespeed) / 100)), 3);
	}
	if (Browser.CustomQuery != "")
	{
		tmpString = Left(Browser.CustomQuery, 32);
		AddQueryTerm("custom", tmpString, 0);
	}
	MSC.StartQuery(0);
	StatusBar.SetCaption(StartQueryString);
	*/
}

void UBrowser_ServerListPageMS::ShowPanel(bool bShow)
{
	Super::ShowPanel(bShow);
	if (bShow)
	{
		if (!bStarted)
		{
			//Log(MyButton.Caption + ": Initial refresh");
			RefreshList();
			bStarted = true;
		}
		else
		{
			//Log(MyButton.Caption + ": Resuming pings");
			MyServersList->AutopingServers();
		}
	}
	else
	{
		//Log(MyButton.Caption + ": Cancelling pings");
		MyServersList->StopPings();
	}
}

void UBrowser_ServerListPageMS::OnCloseBrowser()
{
	if (MSC != nullptr)
	{
		MSC->CancelPings();
		MSC->Destroy();
		MSC = nullptr;
	}
}

void UBrowser_ServerListPageMS::PingServer(int32 ListID, EPingCause PingCause, FServerResponseLine S)
{
	if (PingCause == EPingCause::PC_Clicked)
	{
		MSC->PingServer(ListID, PingCause, S.IP, S.QueryPort, EQueryInterfaceCommand::QI_RulesAndPlayers, S);
	}
	else
	{
		MSC->PingServer(ListID, PingCause, S.IP, S.QueryPort, EQueryInterfaceCommand::QI_Ping, S);
	}
}

void UBrowser_ServerListPageMS::CancelPings()
{
	MSC->CancelPings();
}

void UBrowser_ServerListPageMS::UpdateStatusPingCount()
{
	/*
	if (MyServersList.NumReceivedPings < MyServersList.Servers.Num())
	{
		StatusBar.SetCaption(PingRecvString @ "(" + FString::FromInt(MyServersList.NumReceivedPings) + "/" + FString::FromInt(MyServersList.Servers.Num()) + ")");
	}
	else
	{
		StatusBar.SetCaption(RefreshFinHead @ FString::FromInt(MyServersList.Servers.Num()) @ RefreshFinMid @ FString::FromInt(MyServersList.NumPlayers) @ RefreshFinTail);
	}
	*/
}

void UBrowser_ServerListPageMS::MyReceivedPingInfo(int32 ServerID, EPingCause PingCause, FServerResponseLine S)
{
	MyServersList->MyReceivedPingInfo(ServerID, PingCause, S);
	if (PingCause == EPingCause::PC_AutoPing)
	{
		UpdateStatusPingCount();
	}
}

void UBrowser_ServerListPageMS::MyPingTimeout(int32 ListID, EPingCause PingCause)
{
	MyServersList->MyPingTimeout(ListID, PingCause);
	if (PingCause == EPingCause::PC_AutoPing)
	{
		UpdateStatusPingCount();
	}
}

void UBrowser_ServerListPageMS::MyQueryFinished(EResponseInfo ResponseInfo, int32 Info)
{
	/*
	MyServersList.MyQueryFinished(ResponseInfo, Info);
	switch (ResponseInfo)
	{
	case 3:
		StatusBar.SetCaption(QueryFinHead + FString::FromInt(MSC.ResultCount) + QueryFinTail);
		break;
	case 0:
		StatusBar.SetCaption(AuthFailString);
		break;
	case 1:
		StatusBar.SetCaption(ConnFailString);
		break;
	case 2:
		StatusBar.SetCaption(ConnTimeoutString);
		break;
	case 4:
		StatusBar.SetCaption(MustUpgradeString);
		break;
	default:
	}
	*/
}

bool UBrowser_ServerListPageMS::MyRePing(UGUIComponent* Sender)
{
	MyServersList->RePingServers();
	return true;
}

bool UBrowser_ServerListPageMS::MyRefreshClick(UGUIComponent* Sender)
{
	RefreshClick(Sender);
	return true;
}

void UBrowser_ServerListPageMS::InitComponent(UGUIController* C, UGUIComponent* O)
{
	Super::InitComponent(C, O);
	if (MSC == nullptr)
	{
		//MSC = PlayerOwner().Level.Spawn(AMasterServerClient::StaticClass());
		//MSC->__OnReceivedServer__Delegate = MyServersList.MyOnReceivedServer;
		//MSC->__OnQueryFinished__Delegate = MyQueryFinished;
		//MSC->__OnReceivedPingInfo__Delegate = MyReceivedPingInfo;
		//MSC->__OnPingTimeout__Delegate = MyPingTimeout;
	}
	StatusBar->WinWidth = 0.8;
	Cast<UGUIButton>(Cast<UGUIPanel>(Controls[1])->Controls[6])->bVisible = false;
	Cast<UGUIButton>(Cast<UGUIPanel>(Controls[1])->Controls[1])->Caption = RePingServersCaption;
	//Cast<UGUIButton>(Cast<UGUIPanel>(Controls[1])->Controls[1])->__OnClick__Delegate = MyRePing;
	Cast<UGUIButton>(Cast<UGUIPanel>(Controls[1])->Controls[7])->Caption = RefreshCaption;
	//Cast<UGUIButton>(Cast<UGUIPanel>(Controls[1])->Controls[7])->__OnClick__Delegate = MyRefreshClick;
}
