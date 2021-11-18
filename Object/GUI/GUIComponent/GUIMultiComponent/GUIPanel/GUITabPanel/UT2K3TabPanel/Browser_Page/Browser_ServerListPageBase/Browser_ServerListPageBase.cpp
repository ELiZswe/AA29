// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_ServerListPageBase/Browser_ServerListPageBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/Browser_RulesList/Browser_RulesList.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/Browser_PlayersList/Browser_PlayersList.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/Browser_ServersList/Browser_ServersList.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/GUIMultiColumnListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUITitleBar/GUITitleBar.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUISplitter/GUISplitter.h"

UBrowser_ServerListPageBase::UBrowser_ServerListPageBase()
{
	UBrowser_RulesList* TheRulesList = NewObject<UBrowser_RulesList>(UBrowser_RulesList::StaticClass());
	//TheRulesList->OnPreDraw=TheRulesList.InternalOnPreDraw;
	//TheRulesList->OnClick=TheRulesList.InternalOnClick;
	//TheRulesList->OnRightClick=TheRulesList.InternalOnRightClick;
	//TheRulesList->OnMousePressed=TheRulesList.InternalOnMousePressed;
	//TheRulesList->OnMouseRelease=TheRulesList.InternalOnMouseRelease;
	//TheRulesList->OnKeyEvent=TheRulesList.InternalOnKeyEvent;
	//TheRulesList->OnBeginDrag=TheRulesList.InternalOnBeginDrag;
	//TheRulesList->OnEndDrag=TheRulesList.InternalOnEndDrag;
	//TheRulesList->OnDragDrop=TheRulesList.InternalOnDragDrop;
	//TheRulesList->OnDragEnter=TheRulesList.InternalOnDragEnter;
	//TheRulesList->OnDragLeave=TheRulesList.InternalOnDragLeave;
	//TheRulesList->OnDragOver=TheRulesList.InternalOnDragOver;
	UBrowser_PlayersList* ThePlayersList = NewObject<UBrowser_PlayersList>(UBrowser_PlayersList::StaticClass());
	//ThePlayersList->OnPreDraw=ThePlayersList.InternalOnPreDraw;
	//ThePlayersList->OnClick=ThePlayersList.InternalOnClick;
	//ThePlayersList->OnRightClick=ThePlayersList.InternalOnRightClick;
	//ThePlayersList->OnMousePressed=ThePlayersList.InternalOnMousePressed;
	//ThePlayersList->OnMouseRelease=ThePlayersList.InternalOnMouseRelease;
	//ThePlayersList->OnKeyEvent=ThePlayersList.InternalOnKeyEvent;
	//ThePlayersList->OnBeginDrag=ThePlayersList.InternalOnBeginDrag;
	//ThePlayersList->OnEndDrag=ThePlayersList.InternalOnEndDrag;
	//ThePlayersList->OnDragDrop=ThePlayersList.InternalOnDragDrop;
	//ThePlayersList->OnDragEnter=ThePlayersList.InternalOnDragEnter;
	//ThePlayersList->OnDragLeave=ThePlayersList.InternalOnDragLeave;
	//ThePlayersList->OnDragOver=ThePlayersList.InternalOnDragOver;
	UBrowser_ServersList* TheServersList = NewObject<UBrowser_ServersList>(UBrowser_ServersList::StaticClass());
	//TheServersList->OnPreDraw=TheServersList.InternalOnPreDraw;
	//TheServersList->OnClick=TheServersList.InternalOnClick;
	//TheServersList->OnRightClick=TheServersList.InternalOnRightClick;
	//TheServersList->OnMousePressed=TheServersList.InternalOnMousePressed;
	//TheServersList->OnMouseRelease=TheServersList.InternalOnMouseRelease;
	//TheServersList->OnKeyEvent=TheServersList.InternalOnKeyEvent;
	//TheServersList->OnBeginDrag=TheServersList.InternalOnBeginDrag;
	//TheServersList->OnEndDrag=TheServersList.InternalOnEndDrag;
	//TheServersList->OnDragDrop=TheServersList.InternalOnDragDrop;
	//TheServersList->OnDragEnter=TheServersList.InternalOnDragEnter;
	//TheServersList->OnDragLeave=TheServersList.InternalOnDragLeave;
	//TheServersList->OnDragOver=TheServersList.InternalOnDragOver;
	UGUIButton* UtilButtonB = NewObject<UGUIButton>(UGUIButton::StaticClass());
	UtilButtonB->StyleName="SquareMenuButton";
	UtilButtonB->WinTop=0.5;
	UtilButtonB->WinLeft=0.8;
	UtilButtonB->WinWidth=0.2;
	UtilButtonB->WinHeight=0.5;
	//UtilButtonB->OnKeyEvent=UtilButtonB.InternalOnKeyEvent;
	UGUIButton* UtilButtonA = NewObject<UGUIButton>(UGUIButton::StaticClass());
	UtilButtonA->StyleName="SquareMenuButton";
	UtilButtonA->WinTop=0.5;
	UtilButtonA->WinLeft=0.6;
	UtilButtonA->WinWidth=0.2;
	UtilButtonA->WinHeight=0.5;
	//UtilButtonA->OnKeyEvent=UtilButtonA.InternalOnKeyEvent;
	UGUIButton* AddFavoriteButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	AddFavoriteButton->Caption="ADD FAVORITE";
	AddFavoriteButton->StyleName="SquareMenuButton";
	AddFavoriteButton->WinLeft=0.8;
	AddFavoriteButton->WinWidth=0.2;
	AddFavoriteButton->WinHeight=0.5;
	//AddFavoriteButton->OnKeyEvent=AddFavoriteButton.InternalOnKeyEvent;
	UGUIButton* SpectateButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SpectateButton->Caption="SPECTATE";
	SpectateButton->StyleName="SquareMenuButton";
	SpectateButton->WinLeft=0.6;
	SpectateButton->WinWidth=0.2;
	SpectateButton->WinHeight=0.5;
	//SpectateButton->OnKeyEvent=SpectateButton.InternalOnKeyEvent;
	UGUIButton* JoinButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	JoinButton->Caption="JOIN";
	JoinButton->StyleName="SquareMenuButton";
	JoinButton->WinLeft=0.4;
	JoinButton->WinWidth=0.2;
	JoinButton->WinHeight=0.5;
	//JoinButton->OnKeyEvent=JoinButton.InternalOnKeyEvent;
	UGUIButton* RefreshButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	RefreshButton->Caption="REFRESH LIST";
	RefreshButton->StyleName="SquareMenuButton";
	RefreshButton->WinLeft=0.2;
	RefreshButton->WinWidth=0.2;
	RefreshButton->WinHeight=0.5;
	//RefreshButton->OnKeyEvent=RefreshButton.InternalOnKeyEvent;
	UGUIButton* BackButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	BackButton->Caption="BACK";
	BackButton->StyleName="SquareMenuButton";
	BackButton->WinWidth=0.2;
	BackButton->WinHeight=0.5;
	//BackButton->OnKeyEvent=BackButton.InternalOnKeyEvent;
	UGUIMultiColumnListBox* RulesListBox = NewObject<UGUIMultiColumnListBox>(UGUIMultiColumnListBox::StaticClass());
	RulesListBox->bVisibleWhenEmpty=true;
	RulesListBox->Controls = { TheRulesList };
	//RulesListBox->OnCreateComponent=RulesListBox.InternalOnCreateComponent;
	RulesListBox->StyleName="ServerBrowserGrid";
	RulesListBox->WinHeight=1;
	UGUIMultiColumnListBox* PlayersListBox = NewObject<UGUIMultiColumnListBox>(UGUIMultiColumnListBox::StaticClass());
	PlayersListBox->bVisibleWhenEmpty=true;
	PlayersListBox->Controls = { ThePlayersList };
	//PlayersListBox->OnCreateComponent=PlayersListBox.InternalOnCreateComponent;
	PlayersListBox->StyleName="ServerBrowserGrid";
	PlayersListBox->WinHeight=1;
	UGUIMultiColumnListBox* ServersListBox = NewObject<UGUIMultiColumnListBox>(UGUIMultiColumnListBox::StaticClass());
	ServersListBox->bVisibleWhenEmpty=true;
	ServersListBox->Controls = { TheServersList };
	//ServersListBox->OnCreateComponent=ServersListBox.InternalOnCreateComponent;
	ServersListBox->StyleName="ServerBrowserGrid";
	ServersListBox->WinHeight=1;
	UGUIPanel* ServersPanel = NewObject<UGUIPanel>(UGUIPanel::StaticClass());
	ServersPanel->Controls = { ServersListBox };
	UGUIPanel* RulesPanel = NewObject<UGUIPanel>(UGUIPanel::StaticClass());
	RulesPanel->Controls = { RulesListBox };
	UGUIPanel* PlayersPanel = NewObject<UGUIPanel>(UGUIPanel::StaticClass());
	PlayersPanel->Controls = { PlayersListBox };
	UGUISplitter* DetailsSplitter = NewObject<UGUISplitter>(UGUISplitter::StaticClass());
	DetailsSplitter->SplitOrientation = EGUISplitterType::SPLIT_Horizontal;
	//DetailsSplitter->Background=Texture'Engine.DefaultTexture';
	DetailsSplitter->Controls = { RulesPanel,PlayersPanel };
	DetailsSplitter->WinHeight=1;
	UGUISplitter* MainSplitter = NewObject<UGUISplitter>(UGUISplitter::StaticClass());
	MainSplitter->Controls = { ServersPanel,DetailsSplitter };
	MainSplitter->WinHeight=0.9;
	UGUITitleBar* MyStatus = NewObject<UGUITitleBar>(UGUITitleBar::StaticClass());
	MyStatus->bUseTextHeight=false;
	MyStatus->Justification = EeTextAlign::TXTA_Left;
	MyStatus->StyleName="SquareBar";
	MyStatus->WinTop=0.5;
	MyStatus->WinWidth=0.6;
	MyStatus->WinHeight=0.5;
	UGUIPanel* FooterPanel = NewObject<UGUIPanel>(UGUIPanel::StaticClass());
	FooterPanel->Controls = { BackButton,RefreshButton,JoinButton,SpectateButton,AddFavoriteButton,MyStatus,UtilButtonA,UtilButtonB };
	FooterPanel->WinTop=0.9;
	FooterPanel->WinHeight=0.1;
	
	Controls = { MainSplitter,FooterPanel };
}

void UBrowser_ServerListPageBase::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	if (!bInitialized)
	{
		MyServersList = Browser_ServersList(GUIMultiColumnListBox(GUIPanel(GUISplitter(Controls[0]).Controls[0]).Controls[0]).Controls[0]);
		MyServersList.MyPage = Self;
		MyServersList.MyRulesList = Browser_RulesList(GUIMultiColumnListBox(GUIPanel(GUISplitter(GUISplitter(Controls[0]).Controls[1]).Controls[0]).Controls[0]).Controls[0]);
		MyServersList.MyPlayersList = Browser_PlayersList(GUIMultiColumnListBox(GUIPanel(GUISplitter(GUISplitter(Controls[0]).Controls[1]).Controls[1]).Controls[0]).Controls[0]);
		MyServersList.MyRulesList.MyPage = Self;
		MyServersList.MyRulesList.MyServersList = MyServersList;
		MyServersList.MyPlayersList.MyPage = Self;
		MyServersList.MyPlayersList.MyServersList = MyServersList;
		StatusBar = GUITitleBar(GUIPanel(Controls[1]).Controls[5]);
	}
	StatusBar.SetCaption(ReadyString);
	Super::InitComponent(MyController, MyOwner);
	if (!bInitialized)
	{
		GUIButton(GUIPanel(Controls[1]).Controls[0]).__OnClick__Delegate = BackClick;
		GUIButton(GUIPanel(Controls[1]).Controls[1]).__OnClick__Delegate = RefreshClick;
		GUIButton(GUIPanel(Controls[1]).Controls[2]).__OnClick__Delegate = JoinClick;
		GUIButton(GUIPanel(Controls[1]).Controls[3]).__OnClick__Delegate = SpectateClick;
		GUIButton(GUIPanel(Controls[1]).Controls[4]).__OnClick__Delegate = AddFavoriteClick;
	}
	bInitialized = true;
	*/
}

void UBrowser_ServerListPageBase::RefreshList()
{
}

void UBrowser_ServerListPageBase::PingServer(int32 i, EPingCause PingCause, FServerResponseLine S)
{
}

void UBrowser_ServerListPageBase::CancelPings()
{
}

bool UBrowser_ServerListPageBase::BackClick(UGUIComponent* Sender)
{
	//Controller.CloseMenu(true);
	return true;
}

bool UBrowser_ServerListPageBase::RefreshClick(UGUIComponent* Sender)
{
	//RefreshList();
	return true;
}

bool UBrowser_ServerListPageBase::JoinClick(UGUIComponent* Sender)
{
	//MyServersList.Connect(false);
	return true;
}

bool UBrowser_ServerListPageBase::SpectateClick(UGUIComponent* Sender)
{
	//MyServersList.Connect(true);
	return true;
}

bool UBrowser_ServerListPageBase::AddFavoriteClick(UGUIComponent* Sender)
{
	//MyServersList.AddFavorite(Browser);
	return true;
}