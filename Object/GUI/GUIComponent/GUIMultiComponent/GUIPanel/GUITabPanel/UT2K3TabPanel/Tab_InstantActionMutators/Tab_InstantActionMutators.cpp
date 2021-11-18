// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_InstantActionMutators/Tab_InstantActionMutators.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/GUIListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UTab_InstantActionMutators::UTab_InstantActionMutators()
{
	UGUIButton* IAMutatorClear = NewObject<UGUIButton>(UGUIButton::StaticClass());
	IAMutatorClear->Caption = "Remove All";
	IAMutatorClear->Hint = "Removes all mutators from the list of mutators to play with.";
	IAMutatorClear->WinTop = 0.360259;
	IAMutatorClear->WinLeft = 0.425;
	IAMutatorClear->WinWidth = 0.145;
	IAMutatorClear->WinHeight = 0.05;
	IAMutatorClear->OnClickSound = EClickSound::CS_Down;
	//IAMutatorClear->OnClick=Tab_InstantActionMutators.RemoveAllMutators;
	//IAMutatorClear->OnKeyEvent=IAMutatorClear.InternalOnKeyEvent;
	UGUIButton* IAMutatorAll = NewObject<UGUIButton>(UGUIButton::StaticClass());
	IAMutatorAll->Caption = "Add All";
	IAMutatorAll->Hint = "Adds all mutators to the list of mutators to play with.";
	IAMutatorAll->WinTop = 0.259218;
	IAMutatorAll->WinLeft = 0.425;
	IAMutatorAll->WinWidth = 0.145;
	IAMutatorAll->WinHeight = 0.05;
	IAMutatorAll->OnClickSound = EClickSound::CS_Up;
	//IAMutatorAll->OnClick=Tab_InstantActionMutators.AddAllMutators;
	//IAMutatorAll->OnKeyEvent=IAMutatorAll.InternalOnKeyEvent;
	UGUIButton* IAMutatorRemove = NewObject<UGUIButton>(UGUIButton::StaticClass());
	IAMutatorRemove->Caption = "Remove";
	IAMutatorRemove->Hint = "Removes the selection from the list of mutators to play with.";
	IAMutatorRemove->WinTop = 0.424322;
	IAMutatorRemove->WinLeft = 0.425;
	IAMutatorRemove->WinWidth = 0.145;
	IAMutatorRemove->WinHeight = 0.05;
	IAMutatorRemove->OnClickSound = EClickSound::CS_Down;
	//IAMutatorRemove->OnClick=Tab_InstantActionMutators.RemoveMutator;
	//IAMutatorRemove->OnKeyEvent=IAMutatorRemove.InternalOnKeyEvent;
	UGUIButton* IAMutatorAdd = NewObject<UGUIButton>(UGUIButton::StaticClass());
	IAMutatorAdd->Caption = "Add";
	IAMutatorAdd->Hint = "Adds the selection to the list of mutators to play with.";
	IAMutatorAdd->WinTop = 0.194114;
	IAMutatorAdd->WinLeft = 0.425;
	IAMutatorAdd->WinWidth = 0.145;
	IAMutatorAdd->WinHeight = 0.05;
	IAMutatorAdd->OnClickSound = EClickSound::CS_Up;
	//IAMutatorAdd->OnClick=Tab_InstantActionMutators.AddMutator;
	//IAMutatorAdd->OnKeyEvent=IAMutatorAdd.InternalOnKeyEvent;
	UGUIButton* IAMutatorConfig = NewObject<UGUIButton>(UGUIButton::StaticClass());
	IAMutatorConfig->Caption = "Configure Mutator";
	IAMutatorConfig->Hint = "Configure the selected mutator";
	IAMutatorConfig->WinTop = 0.93349;
	IAMutatorConfig->WinLeft = 0.729492;
	IAMutatorConfig->WinWidth = 0.239063;
	IAMutatorConfig->WinHeight = 0.054648;
	IAMutatorConfig->bVisible = false;
	//IAMutatorConfig->OnClick=Tab_InstantActionMutators.MutConfigClick;
	//IAMutatorConfig->OnKeyEvent=IAMutatorConfig.InternalOnKeyEvent;
	UGUIScrollTextBox* IAMutatorScroll = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	IAMutatorScroll->CharDelay = 0.0025;
	IAMutatorScroll->EOLDelay = 0.5;
	//IAMutatorScroll->OnCreateComponent=IAMutatorScroll.InternalOnCreateComponent;
	IAMutatorScroll->WinTop = 0.645834;
	IAMutatorScroll->WinLeft = 0.025976;
	IAMutatorScroll->WinWidth = 0.942969;
	IAMutatorScroll->WinHeight = 0.283007;
	IAMutatorScroll->bNeverFocus = true;
	UGUIListBox* IAMutatorSelectedList = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	IAMutatorSelectedList->bVisibleWhenEmpty = true;
	//IAMutatorSelectedList->OnCreateComponent=IAMutatorSelectedList.InternalOnCreateComponent;
	IAMutatorSelectedList->StyleName = "SquareButton";
	IAMutatorSelectedList->Hint = "These are the mutators you will play with.";
	IAMutatorSelectedList->WinTop = 0.083281;
	IAMutatorSelectedList->WinLeft = 0.584376;
	IAMutatorSelectedList->WinWidth = 0.368359;
	IAMutatorSelectedList->WinHeight = 0.502696;
	//IAMutatorSelectedList->OnChange=Tab_InstantActionMutators.ListChange;
	UGUIListBox* IAMutatorAvailList = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	IAMutatorAvailList->bVisibleWhenEmpty = true;
	//IAMutatorAvailList->OnCreateComponent=IAMutatorAvailList.InternalOnCreateComponent;
	IAMutatorAvailList->StyleName = "SquareButton";
	IAMutatorAvailList->Hint = "These are the available mutators.";
	IAMutatorAvailList->WinTop = 0.083281;
	IAMutatorAvailList->WinLeft = 0.041406;
	IAMutatorAvailList->WinWidth = 0.368359;
	IAMutatorAvailList->WinHeight = 0.502696;
	//IAMutatorAvailList->OnChange=Tab_InstantActionMutators.ListChange;
	UGUIImage* IAMutatorBK1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//IAMutatorBK1->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	IAMutatorBK1->ImageColor = FColor(255, 255, 255, 160);
	IAMutatorBK1->ImageStyle = EImgStyle::ISTY_Stretched;
	IAMutatorBK1->WinTop = 0.630156;
	IAMutatorBK1->WinLeft = 0.016758;
	IAMutatorBK1->WinWidth = 0.962383;
	IAMutatorBK1->WinHeight = 0.37086;
	UGUILabel* IAMutatorAvilLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	IAMutatorAvilLabel->Caption = "Available Mutators";
	IAMutatorAvilLabel->TextColor = FColor(255, 255, 255, 255);
	IAMutatorAvilLabel->WinTop = 0.015885;
	IAMutatorAvilLabel->WinLeft = 0.049022;
	IAMutatorAvilLabel->WinWidth = 0.5;
	IAMutatorAvilLabel->WinHeight = 32;
	UGUILabel* IAMutatorSelectedLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	IAMutatorSelectedLabel->Caption = "Active Mutators";
	IAMutatorSelectedLabel->TextColor = FColor(255, 255, 255, 255);
	IAMutatorSelectedLabel->WinTop = 0.015885;
	IAMutatorSelectedLabel->WinLeft = 0.592383;
	IAMutatorSelectedLabel->WinWidth = 0.5;
	IAMutatorSelectedLabel->WinHeight = 32;

	Controls = { IAMutatorBK1,IAMutatorAvailList,IAMutatorSelectedList,IAMutatorScroll,IAMutatorConfig,IAMutatorAdd,IAMutatorRemove,IAMutatorAll,IAMutatorClear,IAMutatorAvilLabel,IAMutatorSelectedLabel };
	WinTop = 0.15;
	WinHeight = 0.77;
}

void UTab_InstantActionMutators::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	FString t = "";
	FString M = "";
	Super::InitComponent(MyController, MyOwner);
	MyAvailMutators = GUIListBox(Controls[1]);
	MyAvailMutators.List.__OnDblClick__Delegate = AvailDBLClick;
	MySelectedMutators = GUIListBox(Controls[2]);
	MySelectedMutators.List.__OnDblClick__Delegate = SelectedDBLClick;
	MyDescBox = GUIScrollTextBox(Controls[3]);
	if (PlayerOwner().Level.IsDemoBuild())
	{
		i = 0;
	}
	if (MyAvailMutators.List.ItemCount > 0)
	{
		MyDescBox.SetContent(MyAvailMutators.List.GetExtra());
		MutConfigMenu = GetMutatorConfigMenu(MyAvailMutators.List.Get());
	}
	else
	{
		if (MySelectedMutators.List.ItemCount > 0)
		{
			MyDescBox.SetContent(MySelectedMutators.List.GetExtra());
			MutConfigMenu = GetMutatorConfigMenu(MySelectedMutators.List.Get());
		}
		else
		{
			MyDescBox.SetContent("None");
		}
	}
	if (MutConfigMenu == "")
	{
		Controls[4].bVisible = false;
	}
	else
	{
		Controls[4].bVisible = true;
	}
	M = LastActiveMutators;
	t = NextMutatorInString(M);
	if (t != "")
	{
		SelectMutator(t);
		t = NextMutatorInString(M);
	}
	*/
}

FString UTab_InstantActionMutators::Play()
{

	FString URL = "";
	FString t = "";
	int32 i = 0;
	/*
	for (i = 0; i < MySelectedMutators.ItemCount(); i++)
	{
		t = ResolveMutator(MySelectedMutators.List.getItemAtIndex(i));
		if (t != "")
		{
			if (URL != "")
			{
				URL = URL $ "," $ t;
			}
			else
			{
				URL = t;
			}
		}
	}
	if (URL != "")
	{
		LastActiveMutators = URL;
		URL = "?Mutator=" $ URL;
	}
	else
	{
		LastActiveMutators = "";
	}
	SaveConfig();
	*/
	return URL;
}

FString UTab_InstantActionMutators::ResolveMutator(FString FriendlyName)
{
	return "";
}

FString UTab_InstantActionMutators::GetMutatorConfigMenu(FString FriendlyName)
{
	return "";
}

FString UTab_InstantActionMutators::NextMutatorInString(FString& mut)
{
	FString t = "";
	int32 p = 0;
	/*
	if (mut == "")
	{
		return "";
	}
	p = InStr(mut, ",");
	if (p < 0)
	{
		t = mut;
		mut = "";
	}
	else
	{
		t = Left(mut, p);
		mut = Right(mut, ((Len(mut) - p) - 1));
	}
	*/
	return t;
}

void UTab_InstantActionMutators::SelectMutator(FString mutClass)
{
}

bool UTab_InstantActionMutators::AvailDBLClick(UGUIComponent* Sender)
{
	//AddMutator(Sender);
	return true;
}

bool UTab_InstantActionMutators::SelectedDBLClick(UGUIComponent* Sender)
{
	//RemoveMutator(Sender);
	return true;
}

bool UTab_InstantActionMutators::MutConfigClick(UGUIComponent* Sender)
{
	/*
	if (MutConfigMenu == "")
	{
		return true;
	}
	Log("Launch: " $ MutConfigMenu);
	Controller.OpenMenu(MutConfigMenu);
	*/
	return true;
}

void UTab_InstantActionMutators::ListChange(UGUIComponent* Sender)
{
	/*
	FString NewDesc = "";
	if (Sender == MyAvailMutators)
	{
		NewDesc = MyAvailMutators.List.GetExtra();
		MutConfigMenu = GetMutatorConfigMenu(MyAvailMutators.List.Get());
	}
	else
	{
		if (Sender == MySelectedMutators)
		{
			NewDesc = MySelectedMutators.List.GetExtra();
			MutConfigMenu = GetMutatorConfigMenu(MySelectedMutators.List.Get());
		}
		else
		{
			NewDesc = "";
		}
	}
	if (NewDesc != "")
	{
		MyDescBox.SetContent(NewDesc);
	}
	if (MutConfigMenu == "")
	{
		Controls[4].bVisible = false;
	}
	else
	{
		Controls[4].bVisible = true;
	}
	*/
}

FString UTab_InstantActionMutators::GetGroupFor(FString FriendlyName)
{
	return "";
}

bool UTab_InstantActionMutators::AddMutator(UGUIComponent* Sender)
{
	/*
	int32 Index = 0;
	int32 i = 0;
	FString gname = "";
	Index = MyAvailMutators.List.Index;
	if (Index < 0)
	{
		return true;
	}
	gname = GetGroupFor(MyAvailMutators.List.Get());
	if (gname != "")
	{
		i = 0;
		if (i < MySelectedMutators.List.ItemCount)
		{
			if (GetGroupFor(MySelectedMutators.List.getItemAtIndex(i)) ~= gname)
			{
				MyAvailMutators.List.Add(MySelectedMutators.List.getItemAtIndex(i), , MySelectedMutators.List.GetExtraAtIndex(i));
				MySelectedMutators.List.Remove(i, 1);
			}
			else
			{
				i++;
			}
		}
	}
	MySelectedMutators.List.Add(MyAvailMutators.List.Get(), , MyAvailMutators.List.GetExtra());
	MyAvailMutators.List.Remove(Index, 1);
	MyAvailMutators.List.SortList();
	MySelectedMutators.List.SortList();
	*/
	return true;
}

bool UTab_InstantActionMutators::RemoveMutator(UGUIComponent* Sender)
{
	/*
	int32 Index = 0;
	Index = MySelectedMutators.List.Index;
	if (Index < 0)
	{
		return true;
	}
	MyAvailMutators.List.Add(MySelectedMutators.List.Get(), , MySelectedMutators.List.GetExtra());
	MySelectedMutators.List.Remove(Index, 1);
	MyAvailMutators.List.SortList();
	MySelectedMutators.List.SortList();
	*/
	return true;
}

bool UTab_InstantActionMutators::AddAllMutators(UGUIComponent* Sender)
{
	/*
	if (MyAvailMutators.ItemCount() <= 0)
	{
		return true;
	}
	MySelectedMutators.List.LoadFrom(MyAvailMutators.List, false);
	MyAvailMutators.List.Clear();
	*/
	return false;     //FAKE   /ELiZ
}

bool UTab_InstantActionMutators::RemoveAllMutators(UGUIComponent* Sender)
{
	/*
	if (MySelectedMutators.ItemCount() <= 0)
	{
		return true;
	}
	MyAvailMutators.List.LoadFrom(MySelectedMutators.List, false);
	MySelectedMutators.List.Clear();
	*/
	return false;     //FAKE   /ELiZ

}