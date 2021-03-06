// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_ServerListPageBase/Browser_ServerListPageBuddy.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/Browser_BuddyList/Browser_BuddyList.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/GUIMultiColumnListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUISplitter/GUISplitter.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/Browser_ServersList/Browser_ServersList.h"
#include "AA29/Object/Actor/Info/MasterServerLink/ServerQueryClient/MasterServerClient/MasterServerClient.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUITitleBar/GUITitleBar.h"

UBrowser_ServerListPageBuddy::UBrowser_ServerListPageBuddy()
{
	UBrowser_BuddyList* TheBuddyList = NewObject<UBrowser_BuddyList>(UBrowser_BuddyList::StaticClass());
	//TheBuddyList->OnPreDraw=TheBuddyList.InternalOnPreDraw;
	//TheBuddyList->OnClick=TheBuddyList.InternalOnClick;
	//TheBuddyList->OnRightClick=TheBuddyList.InternalOnRightClick;
	//TheBuddyList->OnMousePressed=TheBuddyList.InternalOnMousePressed;
	//TheBuddyList->OnMouseRelease=TheBuddyList.InternalOnMouseRelease;
	//TheBuddyList->OnKeyEvent=TheBuddyList.InternalOnKeyEvent;
	//TheBuddyList->OnBeginDrag=TheBuddyList.InternalOnBeginDrag;
	//TheBuddyList->OnEndDrag=TheBuddyList.InternalOnEndDrag;
	//TheBuddyList->OnDragDrop=TheBuddyList.InternalOnDragDrop;
	//TheBuddyList->OnDragEnter=TheBuddyList.InternalOnDragEnter;
	//TheBuddyList->OnDragLeave=TheBuddyList.InternalOnDragLeave;
	//TheBuddyList->OnDragOver=TheBuddyList.InternalOnDragOver;
	UGUIMultiColumnListBox* BuddyListBox = NewObject<UGUIMultiColumnListBox>(UGUIMultiColumnListBox::StaticClass());
	BuddyListBox->bVisibleWhenEmpty=true;
	BuddyListBox->Controls = { TheBuddyList };
	//BuddyListBox->OnCreateComponent=BuddyListBox.InternalOnCreateComponent;
	BuddyListBox->StyleName="ServerBrowserGrid";
	BuddyListBox->WinHeight=1;
	UGUIPanel* BuddyPanel = NewObject<UGUIPanel>(UGUIPanel::StaticClass());
	BuddyPanel->Controls = { BuddyListBox };
	UGUISplitter* BuddySplitter = NewObject<UGUISplitter>(UGUISplitter::StaticClass());
	BuddySplitter->SplitOrientation = EGUISplitterType::SPLIT_Horizontal;
	BuddySplitter->SplitPosition=0.25;
	//BuddySplitter->Background=Texture'Engine.DefaultTexture';
	BuddySplitter->Controls = { BuddyPanel };
	BuddySplitter->WinHeight=1;
	BuddySplitter->bBoundToParent=true;
	BuddySplitter->bScaleToParent=true;

	BudSplit = BuddySplitter;
	AddBuddyCaption = "ADD BUDDY";
	RemoveBuddyCaption = "REMOVE BUDDY";
}

void UBrowser_ServerListPageBuddy::InitComponent(UGUIController* C, UGUIComponent* O)
{
	Super::InitComponent(C, O);
	if (!BuddyInitialized)
	{
		MainSplit = Cast<UGUISplitter>(Controls[0]);
		BudSplit->Controls[1] = MainSplit->Controls[0];
		MainSplit->Controls[0] = BudSplit;
		BudSplit->InitComponent(C, MainSplit);
	}
	MyBuddyList = Cast<UBrowser_BuddyList>(Cast<UGUIMultiColumnListBox>(Cast<UGUIPanel>(BudSplit->Controls[0])->Controls[0])->Controls[0]);
	MyBuddyList->MyBuddyPage = this;
	MyBuddyList->ItemCount = Buddies.Num();
	MyServersList->InitColumnPerc[0] = 0.1;
	MyServersList->InitColumnPerc[1] = 0.25;
	MyServersList->InitColumnPerc[2] = 0.15;
	MyServersList->InitColumnPerc[3] = 0.125;
	MyServersList->InitColumnPerc[4] = 0.125;
	//Cast<UGUIButton>(Cast<UGUIPanel>(Controls[1])->Controls[6])->__OnClick__Delegate = MyRefreshClick;
	Cast<UGUIButton>(Cast<UGUIPanel>(Controls[1])->Controls[6])->Caption = RefreshCaption;
	Cast<UGUIButton>(Cast<UGUIPanel>(Controls[1])->Controls[6])->bVisible = true;
	//Cast<UGUIButton>(Cast<UGUIPanel>(Controls[1])->Controls[7])->__OnClick__Delegate = AddBuddyClick;
	Cast<UGUIButton>(Cast<UGUIPanel>(Controls[1])->Controls[7])->Caption = AddBuddyCaption;
	//Cast<UGUIButton>(Cast<UGUIPanel>(Controls[1])->Controls[4])->__OnClick__Delegate = RemoveBuddyClick;
	Cast<UGUIButton>(Cast<UGUIPanel>(Controls[1])->Controls[4])->Caption = RemoveBuddyCaption;
	StatusBar->WinWidth = 0.6;
	BuddyInitialized = true;
}

bool UBrowser_ServerListPageBuddy::MyRefreshClick(UGUIComponent* Sender)
{
	Super::MyRefreshClick(Sender);
	return true;
}

void UBrowser_ServerListPageBuddy::RefreshList()
{
	int32 i = 0;
	FQueryData QD = FQueryData({});
	MyServersList->Clear();
	i = Buddies.Num();
	MSC->Query.SetNum(i);
	for (i = 0; i < Buddies.Num(); i++)
	{
		QD.Key = "buddy";
		QD.Value = Buddies[i];
		QD.QueryType = EQueryType::QT_Equals;
		MSC->Query[i] = QD;
	}
	MSC->StartQuery(EClientToMaster::CTM_Query);
	StatusBar->SetCaption(StartQueryString);
	SetTimer(0, false);
}

bool UBrowser_ServerListPageBuddy::AddBuddyClick(UGUIComponent* Sender)
{
	/*
	if (Controller.OpenMenu("xinterface.Browser_AddBuddy"))
	{
		Browser_AddBuddy(Controller.TopPage()).MyBuddyPage = this;
	}
	*/
	return true;
}

bool UBrowser_ServerListPageBuddy::RemoveBuddyClick(UGUIComponent* Sender)
{
	/*
	if ((MyBuddyList.Index < 0) || (MyBuddyList.Index >= Buddies.Num()))
	{
		return true;
	}
	Buddies.RemoveAt(MyBuddyList.Index, 1);
	MyBuddyList.ItemCount = Buddies.Num();
	SaveConfig();
	*/
	return true;
}
