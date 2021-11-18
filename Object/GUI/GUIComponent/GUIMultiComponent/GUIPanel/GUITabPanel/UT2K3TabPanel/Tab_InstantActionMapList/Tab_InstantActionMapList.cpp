// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_InstantActionMapList/Tab_InstantActionMapList.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/GUIListBox.h"

UTab_InstantActionMapList::UTab_InstantActionMapList()
{
	UGUIButton* IAMapListDown = NewObject<UGUIButton>(UGUIButton::StaticClass());
	IAMapListDown->Caption = "Down";
	IAMapListDown->Hint = "Move this map lower down in the list";
	IAMapListDown->WinTop = 0.779531;
	IAMapListDown->WinLeft = 0.425;
	IAMapListDown->WinWidth = 0.145;
	IAMapListDown->WinHeight = 0.05;
	IAMapListDown->OnClickSound = EClickSound::CS_Down;
	//IAMapListDown->OnClick=Tab_InstantActionMapList.MapDown;
	//IAMapListDown->OnKeyEvent=IAMapListDown.InternalOnKeyEvent;
	UGUIButton* IAMapListUp = NewObject<UGUIButton>(UGUIButton::StaticClass());
	IAMapListUp->Caption = "Up";
	IAMapListUp->Hint = "Move this map higher up in the list";
	IAMapListUp->WinTop = 0.121978;
	IAMapListUp->WinLeft = 0.425;
	IAMapListUp->WinWidth = 0.145;
	IAMapListUp->WinHeight = 0.05;
	IAMapListUp->OnClickSound = EClickSound::CS_Up;
	//IAMapListUp->OnClick=Tab_InstantActionMapList.MapUp;
	//IAMapListUp->OnKeyEvent=IAMapListUp.InternalOnKeyEvent;
	UGUIButton* IAMapListClear = NewObject<UGUIButton>(UGUIButton::StaticClass());
	IAMapListClear->Caption = "Remove All";
	IAMapListClear->Hint = "Remove all maps from your map list";
	IAMapListClear->WinTop = 0.558176;
	IAMapListClear->WinLeft = 0.425;
	IAMapListClear->WinWidth = 0.145;
	IAMapListClear->WinHeight = 0.05;
	IAMapListClear->OnClickSound = EClickSound::CS_Down;
	//IAMapListClear->OnClick=Tab_InstantActionMapList.MapClear;
	//IAMapListClear->OnKeyEvent=IAMapListClear.InternalOnKeyEvent;
	UGUIButton* IAMapListAll = NewObject<UGUIButton>(UGUIButton::StaticClass());
	IAMapListAll->Caption = "Add All";
	IAMapListAll->Hint = "Add all maps to your map list";
	IAMapListAll->WinTop = 0.388905;
	IAMapListAll->WinLeft = 0.425;
	IAMapListAll->WinWidth = 0.145;
	IAMapListAll->WinHeight = 0.05;
	IAMapListAll->OnClickSound = EClickSound::CS_Up;
	//IAMapListAll->OnClick=Tab_InstantActionMapList.MapAll;
	//IAMapListAll->OnKeyEvent=IAMapListAll.InternalOnKeyEvent;
	UGUIButton* IAMapListRemove = NewObject<UGUIButton>(UGUIButton::StaticClass());
	IAMapListRemove->Caption = "Remove";
	IAMapListRemove->Hint = "Remove this map from your map list";
	IAMapListRemove->WinTop = 0.493072;
	IAMapListRemove->WinLeft = 0.425;
	IAMapListRemove->WinWidth = 0.145;
	IAMapListRemove->WinHeight = 0.05;
	IAMapListRemove->OnClickSound = EClickSound::CS_Down;
	//IAMapListRemove->OnClick=Tab_InstantActionMapList.MapRemove;
	//IAMapListRemove->OnKeyEvent=IAMapListRemove.InternalOnKeyEvent;
	UGUIButton* IAMapListAdd = NewObject<UGUIButton>(UGUIButton::StaticClass());
	IAMapListAdd->Caption = "Add";
	IAMapListAdd->Hint = "Add this map to your map list";
	IAMapListAdd->WinTop = 0.323801;
	IAMapListAdd->WinLeft = 0.425;
	IAMapListAdd->WinWidth = 0.145;
	IAMapListAdd->WinHeight = 0.05;
	IAMapListAdd->OnClickSound = EClickSound::CS_Up;
	//IAMapListAdd->OnClick=Tab_InstantActionMapList.MapAdd;
	//IAMapListAdd->OnKeyEvent=IAMapListAdd.InternalOnKeyEvent;
	UGUIListBox* IAMapListCurMapList = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	IAMapListCurMapList->bVisibleWhenEmpty = true;
	//IAMapListCurMapList->OnCreateComponent=IAMapListCurMapList.InternalOnCreateComponent;
	IAMapListCurMapList->StyleName = "SquareButton";
	IAMapListCurMapList->Hint = "Selected maps";
	IAMapListCurMapList->WinTop = 0.083281;
	IAMapListCurMapList->WinLeft = 0.584376;
	IAMapListCurMapList->WinWidth = 0.368359;
	IAMapListCurMapList->WinHeight = 0.783942;
	UGUIListBox* IAMapListFullMapList = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	IAMapListFullMapList->bVisibleWhenEmpty = true;
	//IAMapListFullMapList->OnCreateComponent=IAMapListFullMapList.InternalOnCreateComponent;
	IAMapListFullMapList->StyleName = "SquareButton";
	IAMapListFullMapList->Hint = "Available maps";
	IAMapListFullMapList->WinTop = 0.083281;
	IAMapListFullMapList->WinLeft = 0.041406;
	IAMapListFullMapList->WinWidth = 0.368359;
	IAMapListFullMapList->WinHeight = 0.783942;
	UGUILabel* IAMapListAvilLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	IAMapListAvilLabel->Caption = "Available Map List";
	IAMapListAvilLabel->TextColor = FColor(255, 255, 255, 255);
	IAMapListAvilLabel->WinTop = 0.015885;
	IAMapListAvilLabel->WinLeft = 0.049022;
	IAMapListAvilLabel->WinWidth = 0.5;
	IAMapListAvilLabel->WinHeight = 32;
	UGUILabel* IAMapListSelectedLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	IAMapListSelectedLabel->Caption = "Selected Map List";
	IAMapListSelectedLabel->TextColor = FColor(255, 255, 255, 255);
	IAMapListSelectedLabel->WinTop = 0.015885;
	IAMapListSelectedLabel->WinLeft = 0.592383;
	IAMapListSelectedLabel->WinWidth = 0.5;
	IAMapListSelectedLabel->WinHeight = 32;

	Controls = { IAMapListFullMapList,IAMapListCurMapList,IAMapListAdd,IAMapListRemove,IAMapListAll,IAMapListClear,IAMapListUp,IAMapListDown,IAMapListAvilLabel,IAMapListSelectedLabel };
	WinTop = 0.15;
	WinHeight = 0.77;
}

void UTab_InstantActionMapList::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	MyFullMapList = GUIListBox(Controls[0]);
	MyCurMapList = GUIListBox(Controls[1]);
	*/
}

FString UTab_InstantActionMapList::Play()
{
	return "";
}

void UTab_InstantActionMapList::ReadMapList(FString MapPrefix, FString MapListClass)
{
}

bool UTab_InstantActionMapList::MapAdd(UGUIComponent* Sender)
{
	/*
	if ((MyFullMapList.ItemCount() == 0) || (MyFullMapList.List.Index < 0))
	{
		return true;
	}
	MyCurMapList.List.Add(MyFullMapList.List.Get());
	MyFullMapList.List.Remove(MyFullMapList.List.Index, 1);
	*/
	return true;
}

bool UTab_InstantActionMapList::MapRemove(UGUIComponent* Sender)
{
	/*
	if ((MyCurMapList.ItemCount() == 0) || (MyCurMapList.List.Index < 0))
	{
		return true;
	}
	MyFullMapList.List.Add(MyCurMapList.List.Get());
	MyCurMapList.List.Remove(MyCurMapList.List.Index, 1);
	*/
	return true;
}

bool UTab_InstantActionMapList::MapAll(UGUIComponent* Sender)
{
	/*
	if (MyFullMapList.ItemCount() == 0)
	{
		return true;
	}
	MyCurMapList.List.LoadFrom(MyFullMapList.List, false);
	MyFullMapList.List.Clear();
	*/
	return true;
}

bool UTab_InstantActionMapList::MapClear(UGUIComponent* Sender)
{
	/*
	if (MyCurMapList.ItemCount() == 0)
	{
		return true;
	}
	MyFullMapList.List.LoadFrom(MyCurMapList.List, false);
	MyCurMapList.List.Clear();
	*/
	return true;
}

bool UTab_InstantActionMapList::MapUp(UGUIComponent* Sender)
{
	/*
	int32 Index = 0;
	if ((MyCurMapList.ItemCount() == 0) || (MyCurMapList.List.Index < 0))
	{
		return true;
	}
	Index = MyCurMapList.List.Index;
	if (Index > 0)
	{
		MyCurMapList.List.Swap(Index, (Index - 1));
		MyCurMapList.List.Index = (Index - 1);
	}
	*/
	return true;
}

bool UTab_InstantActionMapList::MapDown(UGUIComponent* Sender)
{
	/*
	int32 Index = 0;
	if ((MyCurMapList.ItemCount() == 0) || (MyCurMapList.List.Index < 0))
	{
		return true;
	}
	Index = MyCurMapList.List.Index;
	if (Index < (MyCurMapList.ItemCount() - 1))
	{
		MyCurMapList.List.Swap(Index, (Index + 1));
		MyCurMapList.List.Index = (Index + 1);
	}
	*/
	return true;
}
