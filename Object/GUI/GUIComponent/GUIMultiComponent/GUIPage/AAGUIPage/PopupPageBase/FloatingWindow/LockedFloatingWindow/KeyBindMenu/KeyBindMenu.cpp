// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LockedFloatingWindow/KeyBindMenu/KeyBindMenu.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/GUIMultiColumnListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UKeyBindMenu::UKeyBindMenu()
{
	AllKeys.SetNum(256);

	UGUIImage* BindBk = NewObject<UGUIImage>(UGUIImage::StaticClass());
	BindBk->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/backgroundfil_Mat.backgroundfil_Mat'"), NULL, LOAD_None, NULL);
	BindBk->ImageStyle = EImgStyle::ISTY_Stretched;
	BindBk->WinTop = 0.057552;
	BindBk->WinLeft = 0.031397;
	BindBk->WinWidth = 0.937207;
	BindBk->WinHeight = 0.808281;
	BindBk->bBoundToParent = true;
	BindBk->bScaleToParent = true;
	UGUIMultiColumnListBox* BindListBox = NewObject<UGUIMultiColumnListBox>(UGUIMultiColumnListBox::StaticClass());
	BindListBox->HeaderColumnPerc = { 0.45,0.15,0.15,0.15 };
	//BindListBox->OnCreateComponent=KeyBindMenu.InternalOnCreateComponent;
	BindListBox->StyleName = "ListEntry";
	BindListBox->WinTop = 0.085586;
	BindListBox->WinLeft = 0.043604;
	BindListBox->WinWidth = 0.911572;
	BindListBox->WinHeight = 0.705742;
	BindListBox->TabOrder = 0;
	BindListBox->bBoundToParent = true;
	BindListBox->bScaleToParent = true;
	UGUILabel* HintLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	HintLabel->TextAlign = ETextAlign::TXTA_Center;
	HintLabel->bMultiLine = true;
	HintLabel->VertAlign = ETextAlign::TXTA_Center;
	HintLabel->FontScale = EFontScale::FNS_Small;
	HintLabel->StyleName = "textLabel";
	HintLabel->WinTop = 0.872222;
	HintLabel->WinLeft = 0.032813;
	HintLabel->WinWidth = 0.520313;
	HintLabel->WinHeight = 0.085;
	HintLabel->bBoundToParent = true;
	HintLabel->bScaleToParent = true;
	SectionStyleName = "ListSection";
	lb_Binds = BindListBox;
	i_Bk = BindBk;
	l_Hint = HintLabel;
	Headings = { "","Key 1","Key 2","Speech" };
	SectionLabelMargin = 10;
	CloseCaption = "CLOSE";
	ResetCaption = "RESET";
	ClearCaption = "Press '%backspace%' to unbind %keybind% from %keyname%.";
	ActionText = "{%keybinds%} - currently bound to this key.";
	sb_Main = nullptr;
	DefaultLeft = 0.1;
	DefaultTop = 0.05;
	DefaultWidth = 0.8;
	DefaultHeight = 0.9;
	//FadedIn = KeyBindMenu.OnFadeIn;
	WinTop = 0.05;
	WinLeft = 0.1;
	WinWidth = 0.8;
	WinHeight = 0.9;
}

void UKeyBindMenu::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	t_WindowTitle.SetCaption(PageCaption);
	li_Binds = lb_Binds.List;
	SectionStyle = Controller.GetStyle(SectionStyleName, li_Binds.FontScale);
	InitializeBindingsArray();
	Initialize();
	b_OK.Caption = CloseCaption;
	b_Cancel.Caption = ResetCaption;
	*/
}

void UKeyBindMenu::InitializeBindingsArray()
{
	/*
	int32 i = 0;
	for (i = 0; i < 255; i++)
	{
		AllKeys[i].KeyNumber = i;
		Controller.KeyNameFromIndex(byte(i), AllKeys[i].KeyName, AllKeys[i].LocalizedKeyName);
	}
	*/
}

void UKeyBindMenu::Initialize()
{
	LoadCommands();
	MapBindings();
}

void UKeyBindMenu::InternalOnCloseSetBind(bool bCancelled)
{
	/*
	FString BindPhrase = "";
	if (!bCancelled)
	{
		BindPhrase = AAGetDataMenu(Controller.ActivePage).ed_Data.GetText();
		SetSpeechBind(Bindings[NewIndex].Alias, BindPhrase);
	}
	NewIndex = -1;
	NewSubIndex = -1;
	*/
}

FString UKeyBindMenu::GetSpeechBind(FString Alias)
{
	/*
	local HumanController HC;
	HC = HumanController(PlayerOwner());
	if (HC != None)
	{
		return HC.GetSRBind(Alias);
	}
	*/
	return "";
}

bool UKeyBindMenu::SetSpeechBind(FString Alias, FString BindPhrase)
{
	/*
	local HumanController HC;
	HC = HumanController(PlayerOwner());
	if (HC != None)
	{
		if (HC.SetSRBind(Alias, BindPhrase))
		{
			return true;
		}
		else
		{
			Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Cannot Bind Phrase", "Phrase is already in use.");
		}
	}
	*/
	return false;
}

void UKeyBindMenu::ResetSpeechBinds()
{
	/*
	local HumanController HC;
	HC = HumanController(PlayerOwner());
	if (HC != None)
	{
		HC.ResetGrammar();
	}
	*/
}

void UKeyBindMenu::SaveSpeechBinds()
{
	/*
	local HumanController HC;
	HC = HumanController(PlayerOwner());
	if (HC != None)
	{
		HC.SaveSRBinds();
		HC.SetGrammar();
	}
	*/
}

void UKeyBindMenu::LoadCommands()
{
	//ClearBindings();
}

void UKeyBindMenu::MapBindings()
{
	/*
	int32 i = 0;
	int32 BindingIndex = 0;
	FString Alias = "";
	for (i = 1; i < 255; i++)
	{
		if (Controller.GetCurrentBind(AllKeys[i].KeyName, Alias))
		{
			BindingIndex = FindAliasIndex(Alias);
			if (BindingIndex != -1)
			{
				BindKeyToAlias(BindingIndex, i);
			}
		}
	}
	*/
}

void UKeyBindMenu::CreateAliasMapping(FString Command, FString FriendlyName, bool bSectionLabel)
{
	/*
	int32 At = 0;
	At = Bindings.Length;
	Bindings.Length = (Bindings.Length + 1);
	Bindings[At].bIsSectionLabel = bSectionLabel;
	Bindings[At].KeyLabel = FriendlyName;
	Bindings[At].Alias = Command;
	li_Binds.AddedItem();
	*/
}

void UKeyBindMenu::BindKeyToAlias(int32 BindIndex, int32 KeyIndex)
{
	/*
	int32 i = 0;
	if (!ValidBindIndex(BindIndex))
	{
		return;
	}
	if (!ValidKeyIndex(KeyIndex))
	{
		return;
	}
	for (i = 0; i < Bindings[BindIndex].BoundKeys.Length; i++)
	{
		if (Bindings[BindIndex].BoundKeys[i] == KeyIndex)
		{
			return;
		}
		if (Class'GameInfo'.GetBindWeight(byte(Bindings[BindIndex].BoundKeys[i])) < Class'GameInfo'.GetBindWeight(byte(KeyIndex)))
		{
		}
	}
	Bindings[BindIndex].BoundKeys.insert(i, 1);
	Bindings[BindIndex].BoundKeys[i] = KeyIndex;
	*/
}

void UKeyBindMenu::ClearBindings()
{
	/*
	Bindings.remove(0, Bindings.Length);
	li_Binds.Clear();
	*/
}

void UKeyBindMenu::SetKeyBind(int32 Index, int32 SubIndex, uint8 NewKey)
{
	/*
	if (!ValidBindIndex(Index))
	{
		return;
	}
	if ((SubIndex < Bindings[Index].BoundKeys.Length) && (Bindings[Index].BoundKeys[SubIndex] == NewKey))
	{
		return;
	}
	RemoveAllOccurance(NewKey);
	RemoveExistingKey(Index, SubIndex);
	if (Controller.SetKeyBind(AllKeys[NewKey].KeyName, Bindings[Index].Alias))
	{
		BindKeyToAlias(Index, NewKey);
	}
	li_Binds.UpdatedItem(Index);
	*/
}

bool UKeyBindMenu::BeginRawInput(UGUIComponent* Sender)
{
	/*
	int32 Index = 0;
	int32 SubIndex = 0;
	if (MouseOnCol1())
	{
		SubIndex = 0;
	}
	else
	{
		if (MouseOnCol2())
		{
			SubIndex = 1;
		}
		else
		{
			if (MouseOnCol3())
			{
				SubIndex = 2;
				Index = li_Binds.CurrentListId();
				NewIndex = Index;
				NewSubIndex = SubIndex;
				if (Controller.OpenMenu("AGP_Interface.AAGetDataMenu", "Enter Word or Phrase to Bind to", ""))
				{
					AAGetDataMenu(Controller.ActivePage).ed_Data.SetText(GetSpeechBind(Bindings[Index].Alias));
					Controller.ActivePage.__OnClose__Delegate = InternalOnCloseSetBind;
				}
				return true;
			}
			else
			{
				return true;
			}
		}
	}
	Index = li_Binds.CurrentListId();
	if (ValidBindIndex(Index) && Bindings[Index].bIsSectionLabel)
	{
		return true;
	}
	bPendingRawInput = true;
	UpdateHint(Index);
	NewIndex = Index;
	NewSubIndex = SubIndex;
	Controller.__OnNeedRawKeyPress__Delegate = RawKey;
	Controller.Master.bRequireRawJoystick = true;
	PlayerOwner().ClientPlaySound(Controller.EditSound);
	PlayerOwner().ConsoleCommand("toggleime 0");
	*/
	return true;
}

bool UKeyBindMenu::RawKey(uint8 NewKey)
{
	/*
	SetKeyBind(NewIndex, NewSubIndex, NewKey);
	NewSubIndex = -1;
	UpdateHint(NewIndex);
	NewIndex = -1;
	bPendingRawInput = false;
	Controller.__OnNeedRawKeyPress__Delegate = nullptr;
	Controller.Master.bRequireRawJoystick = false;
	PlayerOwner().ClientPlaySound(Controller.ClickSound);
	*/
	return true;
}

void UKeyBindMenu::Closed(UGUIComponent* Sender, bool bCancelled)
{
	/*
	if (bPendingRawInput)
	{
		bPendingRawInput = false;
		Controller.__OnNeedRawKeyPress__Delegate = nullptr;
		Controller.Master.bRequireRawJoystick = false;
	}
	*/
}

FString UKeyBindMenu::GetCurrentKeyBind(int32 BindIndex, int32 SubIndex)
{
	/*
	if (!ValidBindIndex(BindIndex))
	{
		return "";
	}
	if (Bindings[BindIndex].bIsSectionLabel)
	{
		return "";
	}
	if ((BindIndex == NewIndex) && (SubIndex == NewSubIndex))
	{
		return "???";
	}
	if (SubIndex == 2)
	{
		return GetSpeechBind(Bindings[BindIndex].Alias);
	}
	if (SubIndex >= Bindings[BindIndex].BoundKeys.Length)
	{
		return "";
	}
	return AllKeys[Bindings[BindIndex].BoundKeys[SubIndex]].LocalizedKeyName;
	*/
	return "FAKE";    //FAKE   /ELIZ
}

FString UKeyBindMenu::ListGetSortString(int32 Index)
{
	/*
	switch (li_Binds.SortColumn)
	{
	case 0:
		return Bindings[Index].KeyLabel;
	case 1:
		return GetCurrentKeyBind(Index, 0);
	case 2:
		return GetCurrentKeyBind(Index, 1);
	default:
		return "";
	}
	*/
	return "FAKE";    //FAKE   /ELIZ
}

bool UKeyBindMenu::ListOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if ((Key == 8) && (State == 1))
	{
		if (MouseOnCol1())
		{
			RemoveExistingKey(li_Binds.CurrentListId(), 0);
		}
		else
		{
			if (MouseOnCol2())
			{
				RemoveExistingKey(li_Binds.CurrentListId(), 1);
			}
			else
			{
				if (MouseOnCol3())
				{
					SetSpeechBind(Bindings[li_Binds.CurrentListId()].Alias);
				}
			}
		}
		return true;
	}
	if (State != 3)
	{
		return li_Binds.InternalOnKeyEvent(Key, State, Delta);
	}
	if (Key == 13)
	{
		BeginRawInput(None);
		return true;
	}
	return li_Binds.InternalOnKeyEvent(Key, State, Delta);
	*/
	return false;    //FAKE   /ELIZ
}

void UKeyBindMenu::ListTrack(UGUIComponent* Sender, int32 LastIndex)
{
	/*
	int32 Index = 0;
	int32 oldIndex = 0;
	if ((LastIndex >= 0) && (LastIndex < li_Binds.ItemCount))
	{
		oldIndex = li_Binds.SortData[LastIndex].SortItem;
		Index = li_Binds.CurrentListId();
		if (ValidBindIndex(Index) && Bindings[Index].bIsSectionLabel)
		{
			SearchDown(oldIndex);
		}
		if (!bPendingRawInput)
		{
			UpdateHint(Index);
		}
	}
	*/
}

void UKeyBindMenu::SearchUp(int32 oldIndex)
{
	/*
	int32 cindex = 0;
	cindex = li_Binds.CurrentListId();
	if ((cindex > 0) && (cindex < Bindings.Length))
	{
		if (!Bindings[cindex].bIsSectionLabel)
		{
			li_Binds.SetIndex(cindex);
			return;
		}
		(cindex);
	}
	li_Binds.SetIndex(oldIndex);
	*/
}

void UKeyBindMenu::SearchDown(int32 oldIndex)
{
	/*
	int32 cindex = 0;
	cindex = li_Binds.CurrentListId();
	if ((cindex > 0) && (cindex < Bindings.Length))
	{
		if (!Bindings[cindex].bIsSectionLabel)
		{
			li_Binds.SetIndex(cindex);
			return;
		}
		cindex++;
	}
	li_Binds.SetIndex(oldIndex);
	*/
}

void UKeyBindMenu::RemoveExistingKey(int32 Index, int32 SubIndex)
{
	/*
	int32 KeyIndex = 0;
	if (!ValidBindIndex(Index))
	{
		return;
	}
	if ((SubIndex >= Bindings[Index].BoundKeys.Length) || (Bindings[Index].BoundKeys[SubIndex] < 0))
	{
		return;
	}
	KeyIndex = Bindings[Index].BoundKeys[SubIndex];
	Bindings[Index].BoundKeys.remove(SubIndex, 1);
	Controller.SetKeyBind(AllKeys[KeyIndex].KeyName, "");
	*/
}

void UKeyBindMenu::RemoveAllOccurance(uint8 NewKey)
{
	/*
	int32 i = 0;
	int32 j = 0;
	for (i = 0; i < Bindings.Length; i++)
	{
		j = 0;
		if (j < Bindings[i].BoundKeys.Length)
		{
			if (Bindings[i].BoundKeys[j] == NewKey)
			{
				RemoveExistingKey(i, j);
			}
			else
			{
				j++;
			}
		}
	}
	*/
}

void UKeyBindMenu::UpdateHint(int32 BindIndex)
{
	/*
	int32 i = 0;
	FString str = "";
	FString CurrentBindName = "";
	if ((!ValidBindIndex(BindIndex)) || Bindings[BindIndex].bIsSectionLabel)
	{
		if ((!ValidBindIndex((BindIndex + 1))) || Bindings[(BindIndex + 1)].bIsSectionLabel)
		{
			Log("INVALID INVALID INVALID");
			l_Hint.Caption = "";
			return;
		}
		BindIndex++;
	}
	if (Bindings[BindIndex].BoundKeys.Length > 0)
	{
		if (bPendingRawInput)
		{
			for (i = 0; i < Bindings[BindIndex].BoundKeys.Length; i++)
			{
				if (str != "")
				{
					str $ = ",";
				}
				str $ = GetCurrentKeyBind(BindIndex, i);
			}
			if (str == "")
			{
				l_Hint.Caption = "";
			}
			else
			{
				l_Hint.Caption = Repl(ActionText, "%keybinds%", str);
			}
			return;
		}
		else
		{
			if (MouseOnCol2())
			{
				i = 1;
			}
			CurrentBindName = GetCurrentKeyBind(BindIndex, i);
			if (CurrentBindName == "")
			{
			}
			str = Repl(Repl(ClearCaption, "%backspace%", AllKeys[8].LocalizedKeyName), "%keybind%", CurrentBindName);
			l_Hint.Caption = Repl(str, "%keyname%", Bindings[BindIndex].KeyLabel);
		}
	}
	else
	{
		l_Hint.Caption = "";
	}
	*/
}

bool UKeyBindMenu::MouseOnCol1()
{
	/*
	float CellLeft = 0;
	float CellWidth = 0;
	li_Binds.GetCellLeftWidth(1, CellLeft, CellWidth);
	return ((Controller.MouseX >= CellLeft) && (Controller.MouseX <= (CellLeft + CellWidth)));
	*/
	return false;   //FAKE   /ELiZ
}

bool UKeyBindMenu::MouseOnCol2()
{
	/*
	float CellLeft = 0;
	float CellWidth = 0;
	li_Binds.GetCellLeftWidth(2, CellLeft, CellWidth);
	return ((Controller.MouseX >= CellLeft) && (Controller.MouseX <= (CellLeft + CellWidth)));
	*/
	return false;   //FAKE   /ELiZ
}

bool UKeyBindMenu::MouseOnCol3()
{
	/*
	float CellLeft = 0;
	float CellWidth = 0;
	li_Binds.GetCellLeftWidth(3, CellLeft, CellWidth);
	return ((Controller.MouseX >= CellLeft) && (Controller.MouseX <= (CellLeft + CellWidth)));
	*/
	return false;   //FAKE   /ELiZ
}

bool UKeyBindMenu::ValidBindIndex(int32 Index)
{
	//return ((Index >= 0) && (Index < Bindings.Length));
	return false;   //FAKE   /ELiZ
}

bool UKeyBindMenu::ValidKeyIndex(int32 Index)
{
	//return ((Index >= 0) && (Index < 255));
	return false;   //FAKE   /ELiZ
}

int32 UKeyBindMenu::FindAliasIndex(FString Alias)
{
	/*
	int32 i = 0;
	for (i = 0; i < Bindings.Length; i++)
	{
		if (Bindings[i].Alias ~= Alias)
		{
			return i;
		}
	}
	*/
	return -1;
}

void UKeyBindMenu::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender)
{
	/*
	local XInterface.GUIMultiColumnList L;
	int32 i = 0;
	if (GUIMultiColumnListBox(Sender) != None)
	{
		L = GUIMultiColumnList(NewComp);
		if (L != None)
		{
			for (i = 0; i < 4; i++)
			{
				L.ColumnHeadings[i] = Headings[i];
			}
			L.__OnKeyEvent__Delegate = ListOnKeyEvent;
			L.__OnDrawItem__Delegate = DrawBinding;
			L.__GetSortString__Delegate = ListGetSortString;
			L.ExpandLastColumn = true;
			L.SortColumn = -1;
			L.bHotTrack = true;
			L.__OnClick__Delegate = BeginRawInput;
			L.__OnTrack__Delegate = ListTrack;
		}
		GUIMultiColumnListBox(Sender).InternalOnCreateComponent(NewComp, Sender);
	}
	Super::InternalOnCreateComponent(NewComp, Sender);
	*/
}

void UKeyBindMenu::DrawBinding(UCanvas* Canvas, int32 Item, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	/*
	float CellLeft = 0;
	float CellWidth = 0;
	local XInterface.GUIStyles DStyle;
	int32 i = 0;
	int32 SavedOffset[4] = 0;
	Canvas.Style = ERenderStyle.STY_Normal;
	Item = li_Binds.SortData[Item].SortItem;
	if (!ValidBindIndex(Item))
	{
		return;
	}
	if (Bindings[Item].bIsSectionLabel)
	{
		li_Binds.GetCellLeftWidth(0, CellLeft, CellWidth);
		Canvas.SetPos((CellLeft + 3), Y);
		Canvas.DrawColor = SectionStyle.ImgColors[li_Binds.MenuState];
		Canvas.DrawTile(Controller.DefaultPens[0], (W - 6), H, 0, 0, 32, 32);
		SectionStyle.DrawText(Canvas, li_Binds.MenuState, (CellLeft + SectionLabelMargin), Y, CellWidth, H, 0, Bindings[Item].KeyLabel, li_Binds.FontScale);
		return;
	}
	if (bPendingRawInput)
	{
		bSelected = ((Item - li_Binds.Top) == NewIndex);
	}
	if (bSelected)
	{
		DStyle = li_Binds.SelectedStyle;
	}
	else
	{
		DStyle = li_Binds.Style;
	}
	for (i = 0; i < 4; i++)
	{
		SavedOffset[i] = DStyle.BorderOffsets[i];
		DStyle.BorderOffsets[i] = class'AGP_Interface.STY_AAListSelection'.Default.BorderOffsets[i];
	}
	if (bSelected && (!bPendingRawInput))
	{
		DStyle.Draw(Canvas, li_Binds.MenuState, (X + float(DStyle.BorderOffsets[0])), Y, (W - float(DStyle.BorderOffsets[2])), H);
	}
	li_Binds.GetCellLeftWidth(0, CellLeft, CellWidth);
	DStyle.DrawText(Canvas, li_Binds.MenuState, CellLeft, Y, (CellWidth - float(DStyle.BorderOffsets[2])), H, 1, Bindings[Item].KeyLabel, li_Binds.FontScale);
	li_Binds.GetCellLeftWidth(1, CellLeft, CellWidth);
	if ((bPendingRawInput && bSelected) && (NewSubIndex == 0))
	{
		DStyle.Draw(Canvas, li_Binds.MenuState, CellLeft, Y, (CellWidth - float(DStyle.BorderOffsets[2])), H);
	}
	DStyle.DrawText(Canvas, li_Binds.MenuState, CellLeft, Y, (CellWidth - float(DStyle.BorderOffsets[2])), H, 1, GetCurrentKeyBind(Item, 0), li_Binds.FontScale);
	li_Binds.GetCellLeftWidth(2, CellLeft, CellWidth);
	if ((bPendingRawInput && bSelected) && (NewSubIndex == 1))
	{
		DStyle.Draw(Canvas, li_Binds.MenuState, CellLeft, Y, (CellWidth - float(DStyle.BorderOffsets[2])), H);
	}
	DStyle.DrawText(Canvas, li_Binds.MenuState, CellLeft, Y, (CellWidth - float(DStyle.BorderOffsets[2])), H, 1, GetCurrentKeyBind(Item, 1), li_Binds.FontScale);
	li_Binds.GetCellLeftWidth(3, CellLeft, CellWidth);
	if ((bPendingRawInput && bSelected) && (NewSubIndex == 2))
	{
		DStyle.Draw(Canvas, li_Binds.MenuState, CellLeft, Y, (CellWidth - float(DStyle.BorderOffsets[2])), H);
	}
	DStyle.DrawText(Canvas, li_Binds.MenuState, CellLeft, Y, (CellWidth - float(DStyle.BorderOffsets[2])), H, 1, GetCurrentKeyBind(Item, 2), li_Binds.FontScale);
	for (i = 0; i < 4; i++)
	{
		DStyle.BorderOffsets[i] = SavedOffset[i];
	}
	*/
}

bool UKeyBindMenu::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (Sender == b_OK)
	{
		SaveSpeechBinds();
		Controller.CloseMenu(false);
		return true;
	}
	else
	{
		if (Sender == b_Cancel)
		{
			Controller.ResetKeyboard();
			ResetSpeechBinds();
			Initialize();
		}
	}
	*/
	return false;   //FAKE   /ELiZ

}

void UKeyBindMenu::OnFadeIn()
{
	Initialize();
}