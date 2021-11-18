// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/AABrowser_FilterListPage/AABrowser_FilterListPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiOptionListBox/GUIMultiOptionListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UAABrowser_FilterListPage::UAABrowser_FilterListPage()
{
	UGUIButton* bCancel = NewObject<UGUIButton>(UGUIButton::StaticClass());
	bCancel->Caption = "Cancel";
	bCancel->WinTop = 0.82;
	bCancel->WinLeft = 0.610001;
	bCancel->WinWidth = 0.16875;
	bCancel->WinHeight = 0.05;
	//bCancel->OnClick=AABrowser_FilterListPage.CancelClick;
	//bCancel->OnKeyEvent=bCancel.InternalOnKeyEvent;
	UGUIButton* bOk = NewObject<UGUIButton>(UGUIButton::StaticClass());
	bOk->Caption = "OK";
	bOk->WinTop = 0.77;
	bOk->WinLeft = 0.610001;
	bOk->WinWidth = 0.16875;
	bOk->WinHeight = 0.05;
	//bOk->OnClick=AABrowser_FilterListPage.OkClick;
	//bOk->OnKeyEvent=bOk.InternalOnKeyEvent;
	UGUIMultiOptionListBox* lbFilters = NewObject<UGUIMultiOptionListBox>(UGUIMultiOptionListBox::StaticClass());
	//lbFilters->OnCreateComponent=lbFilters.InternalOnCreateComponent;
	lbFilters->WinTop = 0.103281;
	lbFilters->WinLeft = 0.262656;
	lbFilters->WinWidth = 0.343359;
	lbFilters->WinHeight = 0.766448;
	UGUIImage* Bg = NewObject<UGUIImage>(UGUIImage::StaticClass());
	Bg->WinTop = 0.103281;
	Bg->WinLeft = 0.262656;
	Bg->WinWidth = 0.343359;
	Bg->WinHeight = 0.766448;
	i_Background = Bg;
	b_OK = bOk;
	b_Cancel = bCancel;
	lb_Filters = lbFilters;
	CantRemove = "You can not remove the default filter";
	WindowName = "Select Filters";
	WinTop = 0.046667;
	WinLeft = 0.2375;
	WinWidth = 0.56875;
	WinHeight = 0.875001;
}

void UAABrowser_FilterListPage::InitComponent(UGUIController* MyC, UGUIComponent* MyO)
{
	/*
	Super::InitComponent(MyC, MyO);
	li_Filters = lb_Filters.List;
	li_Filters.ItemScaling = 0.04;
	li_Filters.ItemPadding = 0.3;
	li_Filters.__OnChange__Delegate = FilterChange;
	InitFilterList();
	b_ExitButton.__OnClick__Delegate = CancelClick;
	*/
}

void UAABrowser_FilterListPage::InitFilterList()
{
}

void UAABrowser_FilterListPage::FilterChange(UGUIComponent* Sender)
{
}

bool UAABrowser_FilterListPage::OkClick(UGUIComponent* Sender)
{
	//Controller.CloseMenu(true);
	return true;
}

bool UAABrowser_FilterListPage::CancelClick(UGUIComponent* Sender)
{
	//Controller.CloseMenu(true);
	return true;
}