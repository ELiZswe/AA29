// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/MaplistEditor/MaplistEditor.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUISectionBackground/GUISectionBackground.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUISectionBackground/AltSectionBackground/AltSectionBackground.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUITreeListBox/GUITreeListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIComboBox/GUIComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"

UMaplistEditor::UMaplistEditor()
{
	UGUISectionBackground* ActiveBackground = NewObject<UGUISectionBackground>(UGUISectionBackground::StaticClass());
	ActiveBackground->bFillClient = true;
	ActiveBackground->Caption = "Active Maps";
	ActiveBackground->WinTop = 0.261835;
	ActiveBackground->WinLeft = 0.511243;
	ActiveBackground->WinWidth = 0.465432;
	ActiveBackground->WinHeight = 0.564917;
	ActiveBackground->bBoundToParent = true;
	ActiveBackground->bScaleToParent = true;
	//ActiveBackground->OnPreDraw=ActiveBackground.InternalPreDraw;
	UAltSectionBackground* MapListSectionBackground = NewObject<UAltSectionBackground>(UAltSectionBackground::StaticClass());
	MapListSectionBackground->WinTop = 0.055162;
	MapListSectionBackground->WinLeft = 0.023646;
	MapListSectionBackground->WinWidth = 0.9431;
	MapListSectionBackground->WinHeight = 0.190595;
	//MapListSectionBackground->OnPreDraw=MapListSectionBackground.InternalPreDraw;
	UGUISectionBackground* InactiveBackground = NewObject<UGUISectionBackground>(UGUISectionBackground::StaticClass());
	InactiveBackground->bFillClient = true;
	InactiveBackground->Caption = "Inactive Maps";
	InactiveBackground->WinTop = 0.261835;
	InactiveBackground->WinLeft = 0.034914;
	InactiveBackground->WinWidth = 0.465432;
	InactiveBackground->WinHeight = 0.564917;
	InactiveBackground->bBoundToParent = true;
	InactiveBackground->bScaleToParent = true;
	//InactiveBackground->OnPreDraw=InactiveBackground.InternalPreDraw;
	UGUIComboBox* SelectMaplistCombo = NewObject<UGUIComboBox>(UGUIComboBox::StaticClass());
	SelectMaplistCombo->bReadOnly = true;
	SelectMaplistCombo->Hint = "Load a existing custom maplist";
	SelectMaplistCombo->WinTop = 0.109808;
	SelectMaplistCombo->WinLeft = 0.47155;
	SelectMaplistCombo->WinWidth = 0.441384;
	SelectMaplistCombo->WinHeight = 0.045083;
	SelectMaplistCombo->TabOrder = 0;
	//SelectMaplistCombo->OnChange=MaplistEditor.MaplistSelectChange;
	//SelectMaplistCombo->OnKeyEvent=SelectMaplistCombo.InternalOnKeyEvent;
	UGUIButton* NewMaplistButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	NewMaplistButton->Caption = "NEW";
	NewMaplistButton->bAutoSize = true;
	NewMaplistButton->Hint = "Create a new custom maplist";
	NewMaplistButton->WinTop = 0.102551;
	NewMaplistButton->WinLeft = 0.060671;
	NewMaplistButton->WinWidth = 0.12302;
	NewMaplistButton->WinHeight = 0.056312;
	NewMaplistButton->TabOrder = 1;
	//NewMaplistButton->OnClick=MaplistEditor.CustomMaplistClick;
	//NewMaplistButton->OnKeyEvent=NewMaplistButton.InternalOnKeyEvent;
	UGUIButton* RenameMaplistButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	RenameMaplistButton->Caption = "RENAME";
	RenameMaplistButton->bAutoSize = true;
	RenameMaplistButton->Hint = "Rename the currently selected maplist";
	RenameMaplistButton->WinTop = 0.102551;
	RenameMaplistButton->WinLeft = 0.189348;
	RenameMaplistButton->WinWidth = 0.12302;
	RenameMaplistButton->WinHeight = 0.056312;
	RenameMaplistButton->TabOrder = 2;
	//RenameMaplistButton->OnClick=MaplistEditor.CustomMaplistClick;
	//RenameMaplistButton->OnKeyEvent=RenameMaplistButton.InternalOnKeyEvent;
	UGUIButton* DeleteMaplistButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	DeleteMaplistButton->Caption = "DELETE";
	DeleteMaplistButton->bAutoSize = true;
	DeleteMaplistButton->Hint = "Delete the currently selected maplist.  If this is the last maplist for this gametype, a new default maplist will be generated.";
	DeleteMaplistButton->WinTop = 0.102551;
	DeleteMaplistButton->WinLeft = 0.318024;
	DeleteMaplistButton->WinWidth = 0.12302;
	DeleteMaplistButton->WinHeight = 0.056312;
	DeleteMaplistButton->TabOrder = 3;
	//DeleteMaplistButton->OnPreDraw=MaplistEditor.ButtonPreDraw;
	//DeleteMaplistButton->OnClick=MaplistEditor.CustomMaplistClick;
	//DeleteMaplistButton->OnKeyEvent=DeleteMaplistButton.InternalOnKeyEvent;
	UGUITreeListBox* InactiveMaps = NewObject<UGUITreeListBox>(UGUITreeListBox::StaticClass());
	InactiveMaps->bVisibleWhenEmpty = true;
	InactiveMaps->bSorted = true;
	//InactiveMaps->OnCreateComponent=InactiveMaps.InternalOnCreateComponent;
	InactiveMaps->WinTop = 0.138078;
	InactiveMaps->WinLeft = 0.113794;
	InactiveMaps->WinWidth = 0.380394;
	InactiveMaps->WinHeight = 0.662671;
	InactiveMaps->TabOrder = 4;
	UGUIButton* AddAllButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	AddAllButton->Caption = "Add All";
	AddAllButton->Hint = "Add all maps to your map list";
	AddAllButton->WinTop = 0.852538;
	AddAllButton->WinLeft = 0.045006;
	AddAllButton->WinWidth = 0.190232;
	AddAllButton->WinHeight = 0.056312;
	AddAllButton->TabOrder = 5;
	AddAllButton->bScaleToParent = true;
	AddAllButton->OnClickSound = EClickSound::CS_Up;
	//AddAllButton->OnClick=MaplistEditor.ModifyMapList;
	//AddAllButton->OnKeyEvent=AddAllButton.InternalOnKeyEvent;
	UGUIButton* AddButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	AddButton->Caption = "Add";
	AddButton->Hint = "Add the selected maps to your map list";
	AddButton->WinTop = 0.852538;
	AddButton->WinLeft = 0.263743;
	AddButton->WinWidth = 0.203807;
	AddButton->WinHeight = 0.056312;
	AddButton->TabOrder = 6;
	AddButton->bScaleToParent = true;
	AddButton->bRepeatClick = true;
	AddButton->OnClickSound = EClickSound::CS_Up;
	//AddButton->OnClick=MaplistEditor.ModifyMapList;
	//AddButton->OnKeyEvent=AddButton.InternalOnKeyEvent;
	UGUITreeListBox* ActiveMaps = NewObject<UGUITreeListBox>(UGUITreeListBox::StaticClass());
	ActiveMaps->bVisibleWhenEmpty = true;
	//ActiveMaps->OnCreateComponent=ActiveMaps.InternalOnCreateComponent;
	ActiveMaps->WinTop = 0.108021;
	ActiveMaps->WinLeft = 0.605861;
	ActiveMaps->WinWidth = 0.368359;
	ActiveMaps->TabOrder = 7;
	UGUIButton* MoveDownButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MoveDownButton->Caption = "Down";
	MoveDownButton->Hint = "Move this map lower down in the list";
	MoveDownButton->WinTop = 0.852538;
	MoveDownButton->WinLeft = 0.543747;
	MoveDownButton->WinWidth = 0.191554;
	MoveDownButton->WinHeight = 0.056312;
	MoveDownButton->TabOrder = 8;
	MoveDownButton->bScaleToParent = true;
	MoveDownButton->bRepeatClick = true;
	MoveDownButton->OnClickSound = EClickSound::CS_Down;
	//MoveDownButton->OnClick=MaplistEditor.ModifyMapList;
	//MoveDownButton->OnKeyEvent=MoveDownButton.InternalOnKeyEvent;
	UGUIButton* MoveUpButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MoveUpButton->Caption = "Up";
	MoveUpButton->Hint = "Move this map higher up in the list";
	MoveUpButton->WinTop = 0.852538;
	MoveUpButton->WinLeft = 0.772577;
	MoveUpButton->WinWidth = 0.191554;
	MoveUpButton->WinHeight = 0.056312;
	MoveUpButton->TabOrder = 9;
	MoveUpButton->bScaleToParent = true;
	MoveUpButton->bRepeatClick = true;
	MoveUpButton->OnClickSound = EClickSound::CS_Up;
	//MoveUpButton->OnClick=MaplistEditor.ModifyMapList;
	//MoveUpButton->OnKeyEvent=MoveUpButton.InternalOnKeyEvent;
	UGUIButton* RemoveButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	RemoveButton->Caption = "Remove";
	//RemoveButton->ZeroSizeSize;
	RemoveButton->Hint = "Remove the selected maps from your map list";
	RemoveButton->WinTop = 0.898111;
	RemoveButton->WinLeft = 0.543747;
	RemoveButton->WinWidth = 0.191554;
	RemoveButton->WinHeight = 0.056312;
	RemoveButton->TabOrder = 10;
	RemoveButton->bScaleToParent = true;
	RemoveButton->bRepeatClick = true;
	RemoveButton->OnClickSound = EClickSound::CS_Down;
	//RemoveButton->OnClick=MaplistEditor.ModifyMapList;
	//RemoveButton->OnKeyEvent=RemoveButton.InternalOnKeyEvent;
	UGUIButton* RemoveAllButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	RemoveAllButton->Caption = "Remove All";
	RemoveAllButton->Hint = "Remove all maps from your map list";
	RemoveAllButton->WinTop = 0.898111;
	RemoveAllButton->WinLeft = 0.772577;
	RemoveAllButton->WinWidth = 0.191554;
	RemoveAllButton->WinHeight = 0.056312;
	RemoveAllButton->TabOrder = 11;
	RemoveAllButton->bScaleToParent = true;
	RemoveAllButton->OnClickSound = EClickSound::CS_Down;
	//RemoveAllButton->OnClick=MaplistEditor.ModifyMapList;
	//RemoveAllButton->OnKeyEvent=RemoveAllButton.InternalOnKeyEvent;
	lb_ActiveMaps = ActiveMaps;
	lb_AllMaps = InactiveMaps;
	b_Add = AddButton;
	b_AddAll = AddAllButton;
	b_Remove = RemoveButton;
	b_RemoveAll = RemoveAllButton;
	b_MoveUp = MoveUpButton;
	b_MoveDown = MoveDownButton;
	b_New = NewMaplistButton;
	b_Delete = DeleteMaplistButton;
	b_Rename = RenameMaplistButton;
	co_Maplist = SelectMaplistCombo;
	sb_MapList = MapListSectionBackground;
	sb_Avail = InactiveBackground;
	sb_Active = ActiveBackground;

	InvalidMaplistClassText = "Could not create new custom maplist %name% because %game% has an invalid maplist class: '%mapclass%'!";
	NewMaplistPageCaption = "Create custom maplist";
	MaplistEditCaption = "Maplist name: ";
	RenameMaplistPageCaption = "Rename maplist";
	LinkText = "Link Setup";
	AutoSelectText = "Random";
	BonusVehicles = " (Bonus Vehicles)";
	WindowName = "Maplist Configuration";
	MinPageWidth = 0.930313;
	MinPageHeight = 0.931305;
	bResizeWidthAllowed = false;
	bResizeHeightAllowed = false;
	DefaultLeft = 0.038125;
	DefaultTop = 0.02168;
	DefaultWidth = 0.930313;
	DefaultHeight = 0.931305;
	bCaptureInput = true;
	InactiveFadeColor = FColor(80, 80, 80, 255);
	WinTop = 0.02168;
	WinLeft = 0.038125;
	WinWidth = 0.930313;
	WinHeight = 0.931305;
}

void UMaplistEditor::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	li_Active = lb_ActiveMaps.List;
	li_Avail = lb_AllMaps.List;
	if (li_Avail != None)
	{
		li_Avail.__OnDblClick__Delegate = ModifyMapList;
		li_Avail.__OnDragDrop__Delegate = RemoveDragDrop;
		li_Avail.AddLinkObject(b_Add, true);
		li_Avail.bSorted = true;
		li_Avail.__CheckLinkedObjects__Delegate = InternalCheckLinkedObj;
	}
	if (li_Active != None)
	{
		li_Active.__OnDblClick__Delegate = ModifyMapList;
		li_Active.__OnDragDrop__Delegate = AddDragDrop;
		li_Active.AddLinkObject(b_Remove, true);
		li_Active.AddLinkObject(b_MoveUp, true);
		li_Active.AddLinkObject(b_MoveDown, true);
		li_Active.bSorted = false;
		li_Active.__CheckLinkedObjects__Delegate = InternalCheckLinkedObj;
		li_Active.bGroupItems = false;
	}
	sb_Avail.ManageComponent(lb_AllMaps);
	sb_Active.ManageComponent(lb_ActiveMaps);
	co_Maplist.List.bInitializeList = false;
	SetupSizingCaption();
	*/
}

void UMaplistEditor::SetupSizingCaption()
{
	/*
	FString str = "";
	str = b_New.Caption;
	if (Len(b_Rename.Caption) > Len(str))
	{
		str = b_Rename.Caption;
	}
	if (Len(b_Delete.Caption) > Len(str))
	{
		str = b_Delete.Caption;
	}
	b_New.SizingCaption = str;
	b_Rename.SizingCaption = str;
	b_Delete.SizingCaption = str;
	*/
}

void UMaplistEditor::Initialize(AMaplistManager* InHandler)
{
	/*
	MapHandler = InHandler;
	if (InitGameType())
	{
		ReloadAvailable();
		RefreshMaplistNames();
	}
	*/
}

bool UMaplistEditor::InitGameType()
{
	/*
	int32 i = 0;
	local TArray<CacheManager.GameRecord> Games;
	Class'CacheManager'.GetGameTypeList(Games);
	i = 0;
	if (i < Games.Length)
	{
		if (Games[i].ClassName ~= Controller.LastGameType)
		{
			CurrentGameType = Games[i];
			GameIndex = MapHandler.GetGameIndex(CurrentGameType.ClassName);
		}
		else
		{
			i++;
		}
	}
	return (i < Games.Length);
	*/
	return false;    //FAKE    /ELiZ
}

bool UMaplistEditor::OrigONSMap(FString MapName)
{
	return false;
}

void UMaplistEditor::ReloadAvailable()
{
}

void UMaplistEditor::ReloadActive()
{
	/*
	int32 i = 0;
	local TArray<FString> NewActiveMaps;
	li_Active.bNotify = false;
	li_Avail.bNotify = false;
	li_Active.Clear();
	RecordIndex = MapHandler.GetRecordIndex(GameIndex, co_Maplist.GetText());
	NewActiveMaps = MapHandler.GetMapList(GameIndex, RecordIndex);
	for (i = 0; i < NewActiveMaps.Length; i++)
	{
		AddMap(NewActiveMaps[i]);
	}
	li_Active.bNotify = true;
	li_Avail.bNotify = true;
	*/
}

void UMaplistEditor::RefreshMaplistNames(FString CurrentMaplist)
{
	/*
	int32 i = 0;
	int32 Index = 0;
	int32 Current = 0;
	local TArray<FString> Ar;
	Index = MapHandler.GetGameIndex(CurrentGameType.ClassName);
	Ar = MapHandler.GetMapListNames(Index);
	Current = MapHandler.GetRecordIndex(Index, CurrentMaplist);
	if (Current == -1)
	{
		Current = MapHandler.GetActiveList(Index);
	}
	co_Maplist.List.bNotify = false;
	co_Maplist.List.Clear();
	for (i = 0; i < Ar.Length; i++)
	{
		co_Maplist.addItem(Ar[i]);
	}
	co_Maplist.List.bNotify = true;
	CurrentMaplist = MapHandler.GetMapListTitle(Index, Current);
	co_Maplist.SetText(CurrentMaplist, true);
	*/
}

void UMaplistEditor::Closed(UGUIComponent* Sender, bool bCancelled)
{
	//Super::Closed(Sender, bCancelled);
}

bool UMaplistEditor::AddMap(FString MapName)
{
	return true;
}

bool UMaplistEditor::RemoveMap()
{
	/*
	int32 i = 0;
	local TArray<GUITreeNode> PendingElements;
	if (!li_Active.IsValid())
	{
		return false;
	}
	li_Active.bNotify = false;
	PendingElements = li_Active.GetPendingElements(true);
	for (i = 0; i < PendingElements.Length; i++)
	{
		if (li_Active.ValidSelection())
		{
			li_Active.RemoveElement(PendingElements[i], , true);
			MapHandler.RemoveMap(GameIndex, RecordIndex, PendingElements[i].Value);
		}
	}
	li_Active.bNotify = true;
	li_Active.ClearPendingElements();
	li_Active.SetIndex(li_Active.Index);
	*/
	return true;
}

bool UMaplistEditor::ButtonPreDraw(UCanvas* C)
{
	/*
	float X = 0;
	float W = 0;
	float BW = 0;
	float L = 0;
	W = ((sb_MapList.ActualWidth() - sb_MapList.ImageOffset[0]) - sb_MapList.ImageOffset[2]);
	X = (W - sb_MapList.ImageOffset[2]);
	BW = (((b_New.ActualWidth() + b_Rename.ActualWidth()) + b_Delete.ActualWidth()) + 6);
	L = (X - BW);
	b_New.WinLeft = L;
	(L += (b_New.ActualWidth() + 3));
	b_Rename.WinLeft = L;
	(L += (b_Rename.ActualWidth() + 3));
	b_Delete.WinLeft = L;
	b_New.WinTop = 0.180846;
	b_Rename.WinTop = 0.180846;
	b_Delete.WinTop = 0.180846;
	co_Maplist.WinLeft = (sb_MapList.ActualLeft() + sb_MapList.ImageOffset[0]);
	co_Maplist.WinTop = 0.125467;
	co_Maplist.WinWidth = 0.802485;
	W = ((sb_Avail.WinWidth / 2) - (sb_Avail.WinWidth * 0.02));
	b_AddAll.WinLeft = sb_Avail.WinLeft;
	b_AddAll.WinWidth = W;
	b_Add.WinLeft = ((sb_Avail.WinLeft + sb_Avail.WinWidth) - W);
	b_Add.WinWidth = W;
	W = ((sb_Active.WinWidth / 2) - (sb_Active.WinWidth * 0.02));
	b_MoveUp.WinLeft = sb_Active.WinLeft;
	b_MoveUp.WinWidth = W;
	b_Remove.WinLeft = sb_Active.WinLeft;
	b_Remove.WinWidth = W;
	b_MoveDown.WinLeft = ((sb_Active.WinLeft + sb_Active.WinWidth) - W);
	b_MoveDown.WinWidth = W;
	b_RemoveAll.WinLeft = ((sb_Active.WinLeft + sb_Active.WinWidth) - W);
	b_RemoveAll.WinWidth = W;
	*/
	return false;
}

void UMaplistEditor::RenameMaplist(bool bCancelled)
{
	/*
	FString str = "";
	str = Controller.ActivePage.GetDataString();
	if ((!bCancelled) && (str != ""))
	{
		UpdateCustomMaplist(str);
		RefreshMaplistNames(str);
	}
	*/
}

void UMaplistEditor::CreateNewMaplist(bool bCancelled)
{
	/*
	FString str = "";
	FString Warning = "";
	local TArray<FString> Ar;
	str = Controller.ActivePage.GetDataString();
	if ((!bCancelled) && (str != ""))
	{
		if (MapHandler.GetDefaultMaps(CurrentGameType.MapListClassName, Ar) && (Ar.Length > 0))
		{
			RecordIndex = MapHandler.AddList(CurrentGameType.ClassName, str, Ar);
			RefreshMaplistNames(str);
		}
		else
		{
			Warning = Repl(InvalidMaplistClassText, "%name%", str);
			Warning = Repl(Warning, "%game%", CurrentGameType.ClassName);
			Warning = Repl(Warning, "%mapclass%", CurrentGameType.MapListClassName);
			Warn(Warning);
		}
	}
	*/
}

 bool UMaplistEditor::ModifyMapList(UGUIComponent* Sender)
{
	 /*
	int32 Index = 0;
	int32 NewIndex = 0;
	FString str = "";
	if ((Sender == lb_AllMaps) || (Sender == li_Avail))
	{
		if (li_Avail.ValidSelection())
		{
			AddMap();
		}
		else
		{
			li_Avail.InternalDblClick(li_Avail);
		}
		return true;
	}
	if ((Sender == lb_ActiveMaps) || (Sender == li_Active))
	{
		if (li_Active.ValidSelection())
		{
			RemoveMap();
		}
		else
		{
			li_Active.InternalDblClick(li_Active);
		}
		return true;
	}
	if (GUIButton(Sender) == None)
	{
		return false;
	}
	switch (Sender)
	{
	case b_Add:
		return AddMap();
	case b_AddAll:
		if (lb_AllMaps.ItemCount() == 0)
		{
			return true;
		}
		li_Avail.bNotify = false;
		li_Active.bNotify = false;
		Index = 0;
		if (Index < li_Avail.ItemCount)
		{
			if (li_Avail.ValidSelectionAt(Index))
			{
				li_Avail.SilentSetIndex(Index);
				AddMap();
			}
			Index++;
			break;
		}
		li_Avail.bNotify = true;
		li_Active.bNotify = true;
		return true;
	case b_Remove:
		return RemoveMap();
	case b_RemoveAll:
		if (lb_ActiveMaps.ItemCount() == 0)
		{
			return true;
		}
		li_Avail.bNotify = false;
		li_Active.bNotify = false;
		for (Index = 0; Index < li_Active.ItemCount; Index++)
		{
			if (li_Active.ValidSelectionAt(Index))
			{
				MapHandler.RemoveMap(GameIndex, RecordIndex, li_Active.GetValueAtIndex(Index));
			}
		}
		li_Active.Clear();
		li_Avail.bNotify = true;
		li_Active.bNotify = true;
		return true;
	case b_MoveUp:
		if (!li_Active.IsValid())
		{
			return true;
		}
		Index = li_Active.Index;
		str = li_Active.GetValue();
		if ((Index > 0) && li_Active.Swap(Index, (Index - 1)))
		{
			NewIndex = li_Active.FindIndexByValue(str);
			li_Active.SetIndex(NewIndex);
			MapHandler.ShiftMap(GameIndex, RecordIndex, str, -1);
		}
		return true;
	case b_MoveDown:
		if (!li_Active.IsValid())
		{
			return true;
		}
		Index = li_Active.Index;
		str = li_Active.GetValue();
		if ((Index < (li_Active.ItemCount - 1)) && li_Active.Swap(Index, (Index + 1)))
		{
			NewIndex = li_Active.FindIndexByValue(str);
			li_Active.SetIndex(NewIndex);
			MapHandler.ShiftMap(GameIndex, RecordIndex, str, 1);
		}
		return true;
	default:
		return false;
	}
	*/
	return false;    //FAKE    /ELiZ
}

bool UMaplistEditor::CustomMaplistClick(UGUIComponent* Sender)
{
	/*
	FString str = "";
	switch (Sender)
	{
	case b_New:
		if (Controller.OpenMenu(Controller.RequestDataMenu, NewMaplistPageCaption, MaplistEditCaption))
		{
			Controller.ActivePage.__OnClose__Delegate = CreateNewMaplist;
		}
		break;
	case b_Delete:
		RecordIndex = MapHandler.RemoveList(GameIndex, RecordIndex);
		str = MapHandler.GetMapListTitle(GameIndex, RecordIndex);
		RefreshMaplistNames(str);
		ReloadAvailable();
		ReloadActive();
		break;
	case b_Rename:
		if (Controller.OpenMenu(Controller.RequestDataMenu, RenameMaplistPageCaption, MaplistEditCaption))
		{
			Controller.ActivePage.SetDataString(co_Maplist.Get());
			Controller.ActivePage.__OnClose__Delegate = RenameMaplist;
		}
		break;
	default:
	}
	*/
	return true;
}

void UMaplistEditor::MaplistSelectChange(UGUIComponent* Sender)
{
	//ReloadActive();
}

bool UMaplistEditor::AddDragDrop(UGUIComponent* Sender)
{
	/*
	local TArray<GUITreeNode> Ar;
	int32 i = 0;
	int32 idx = 0;
	if (Sender == li_Active)
	{
		idx = li_Active.DropIndex;
		if (!li_Active.IsValidIndex(idx))
		{
			idx = li_Active.ItemCount;
		}
		if (Controller.DropSource == li_Avail)
		{
			Ar = li_Avail.GetPendingElements();
		}
		else
		{
			if (Controller.DropSource == li_Active)
			{
				Ar = li_Active.GetPendingElements();
				for (i = 0; i < Ar.Length; i++)
				{
					if (Ar[i].Value == "")
					{
					}
					MapHandler.RemoveMap(GameIndex, RecordIndex, Ar[i].Value);
					li_Active.RemoveElement(Ar[i]);
				}
			}
		}
		i = (Ar.Length - 1);
		if (i >= 0)
		{
			if (Ar[i].Value == "")
			{
				Ar.remove(i, 1);
			}
			else
			{
				MapHandler.InsertMap(GameIndex, RecordIndex, Ar[i].Value, idx);
			}
			i;
		}
		li_Active.InternalOnDragDrop(li_Active);
		return true;
	}
	*/
	return false;
}

bool UMaplistEditor::RemoveDragDrop(UGUIComponent* Sender)
{
	/*
	local TArray<GUITreeNode> Ar;
	int32 i = 0;
	if (Sender == li_Avail)
	{
		if (Controller.DropSource != li_Active)
		{
			return false;
		}
		Ar = li_Active.GetPendingElements();
		for (i = 0; i < Ar.Length; i++)
		{
			if (Ar[i].Value == "")
			{
			}
			MapHandler.RemoveMap(GameIndex, RecordIndex, Ar[i].Value);
		}
		return li_Avail.InternalOnDragDrop(Sender);
	}
	*/
	return false;
}

void UMaplistEditor::AddMapOption(FString MapName, FString OptionName, FString Value)
{
}

void UMaplistEditor::InternalCheckLinkedObj(UGUIListBase* List)
{
	/*
	if (List.IsValid())
	{
		List.EnableLinkedObjects();
	}
	else
	{
		List.DisableLinkedObjects();
	}
	if (li_Avail.ItemCount > 0)
	{
		EnableComponent(b_AddAll);
	}
	else
	{
		DisableComponent(b_AddAll);
	}
	if (li_Active.ItemCount > 0)
	{
		EnableComponent(b_RemoveAll);
	}
	else
	{
		DisableComponent(b_RemoveAll);
	}
	if (li_Active.Index == 0)
	{
		DisableComponent(b_MoveUp);
	}
	else
	{
		if (li_Active.Index == (li_Active.ItemCount - 1))
		{
			DisableComponent(b_MoveDown);
		}
	}
	*/
}

void UMaplistEditor::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender)
{
	/*
	if ((moButton(Sender) != None) && (GUILabel(NewComp) != None))
	{
		GUILabel(NewComp).TextColor = WhiteColor;
		moButton(Sender).InternalOnCreateComponent(NewComp, Sender);
	}
	Super::InternalOnCreateComponent(NewComp, Sender);
	*/
}

void UMaplistEditor::StoreMaplists()
{
	/*
	int32 i = 0;
	int32 idx = 0;
	MapHandler.ApplyMapList(GameIndex, RecordIndex);
	for (i = 0; i < co_Maplist.ItemCount(); i++)
	{
		idx = MapHandler.GetRecordIndex(GameIndex, co_Maplist.List.getItemAtIndex(i));
		if (idx != RecordIndex)
		{
			MapHandler.SaveMapList(GameIndex, idx);
		}
	}
	*/
}

void UMaplistEditor::UpdateCustomMaplist(FString NewName)
{
	/*
	if (NewName != "")
	{
		RecordIndex = MapHandler.RenameList(GameIndex, RecordIndex, NewName);
	}
	MapHandler.SaveMapList(GameIndex, RecordIndex);
	*/
}

FString UMaplistEditor::GetMapPrefix()
{
	//return CurrentGameType.MapPrefix;
	return "FAKE";    //FAKE   /ELiZ
}

FString UMaplistEditor::GetMapListClass()
{
	//return CurrentGameType.MapListClassName;
	return "FAKE";    //FAKE   /ELiZ
}

int32 UMaplistEditor::FindCacheRecordIndex(FString MapName)
{
	/*
	int32 i = 0;
	for (i = 0; i < Maps.Length; i++)
	{
		if (Maps[i].MapName == MapName)
		{
			return i;
		}
	}
	*/
	return -1;
}

void UMaplistEditor::Free()
{
	/*
	MapHandler = None;
	Super::Free();
	*/
}