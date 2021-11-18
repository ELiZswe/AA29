// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_MultiplayerHostMain/Tab_MultiplayerHostMain.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/GUIListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"

UTab_MultiplayerHostMain::UTab_MultiplayerHostMain()
{
	UGUIListBox* MPHostListCurMapList = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	MPHostListCurMapList->bVisibleWhenEmpty = true;
	//MPHostListCurMapList->OnCreateComponent=MPHostListCurMapList.InternalOnCreateComponent;
	MPHostListCurMapList->StyleName = "SquareButton";
	MPHostListCurMapList->Hint = "Select the map to play";
	MPHostListCurMapList->WinTop = 0.604115;
	MPHostListCurMapList->WinLeft = 0.57461;
	MPHostListCurMapList->WinWidth = 0.391796;
	MPHostListCurMapList->WinHeight = 0.386486;
	//MPHostListCurMapList->OnChange=Tab_MultiplayerHostMain.MapListChange;
	UGUIButton* MPHostListDown = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MPHostListDown->Caption = "Down";
	MPHostListDown->Hint = "Move this map lower down in the list";
	MPHostListDown->WinTop = 0.932135;
	MPHostListDown->WinLeft = 0.433203;
	MPHostListDown->WinWidth = 0.123828;
	MPHostListDown->WinHeight = 0.05;
	MPHostListDown->OnClickSound = EClickSound::CS_Down;
	//MPHostListDown->OnClick=Tab_MultiplayerHostMain.MapDown;
	//MPHostListDown->OnKeyEvent=MPHostListDown.InternalOnKeyEvent;
	UGUIButton* MPHostListClear = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MPHostListClear->Caption = "Remove All";
	MPHostListClear->Hint = "Remove all maps from your map list";
	MPHostListClear->WinTop = 0.808697;
	MPHostListClear->WinLeft = 0.433203;
	MPHostListClear->WinWidth = 0.123828;
	MPHostListClear->WinHeight = 0.05;
	MPHostListClear->OnClickSound = EClickSound::CS_Down;
	//MPHostListClear->OnClick=Tab_MultiplayerHostMain.MapClear;
	//MPHostListClear->OnKeyEvent=MPHostListClear.InternalOnKeyEvent;
	UGUIButton* MPHostListAll = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MPHostListAll->Caption = "Add All";
	MPHostListAll->Hint = "Add all maps to your map list";
	MPHostListAll->WinTop = 0.733697;
	MPHostListAll->WinLeft = 0.433203;
	MPHostListAll->WinWidth = 0.123828;
	MPHostListAll->WinHeight = 0.05;
	MPHostListAll->OnClickSound = EClickSound::CS_Up;
	//MPHostListAll->OnClick=Tab_MultiplayerHostMain.MapAll;
	//MPHostListAll->OnKeyEvent=MPHostListAll.InternalOnKeyEvent;
	UGUIButton* MPHostListUp = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MPHostListUp->Caption = "Up";
	MPHostListUp->Hint = "Move this map higher up in the list";
	MPHostListUp->WinTop = 0.610259;
	MPHostListUp->WinLeft = 0.433203;
	MPHostListUp->WinWidth = 0.123828;
	MPHostListUp->WinHeight = 0.05;
	MPHostListUp->OnClickSound = EClickSound::CS_Up;
	//MPHostListUp->OnClick=Tab_MultiplayerHostMain.MapUp;
	//MPHostListUp->OnKeyEvent=MPHostListUp.InternalOnKeyEvent;
	UGUIButton* MPHostListRemove = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MPHostListRemove->Caption = "Remove";
	MPHostListRemove->Hint = "Remove this map from your map list";
	MPHostListRemove->WinTop = 0.862864;
	MPHostListRemove->WinLeft = 0.433203;
	MPHostListRemove->WinWidth = 0.123828;
	MPHostListRemove->WinHeight = 0.05;
	MPHostListRemove->OnClickSound = EClickSound::CS_Down;
	//MPHostListRemove->OnClick=Tab_MultiplayerHostMain.MapRemove;
	//MPHostListRemove->OnKeyEvent=MPHostListRemove.InternalOnKeyEvent;
	UGUIButton* MPHostListAdd = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MPHostListAdd->Caption = "Add";
	MPHostListAdd->Hint = "Add this map to your map list";
	MPHostListAdd->WinTop = 0.67953;
	MPHostListAdd->WinLeft = 0.433203;
	MPHostListAdd->WinWidth = 0.123828;
	MPHostListAdd->WinHeight = 0.05;
	MPHostListAdd->OnClickSound = EClickSound::CS_Up;
	//MPHostListAdd->OnClick=Tab_MultiplayerHostMain.MapAdd;
	//MPHostListAdd->OnKeyEvent=MPHostListAdd.InternalOnKeyEvent;
	UGUIListBox* MPHostListFullMapList = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	MPHostListFullMapList->bVisibleWhenEmpty = true;
	//MPHostListFullMapList->OnCreateComponent=MPHostListFullMapList.InternalOnCreateComponent;
	MPHostListFullMapList->StyleName = "SquareButton";
	MPHostListFullMapList->Hint = "Select the map to play";
	MPHostListFullMapList->WinTop = 0.604115;
	MPHostListFullMapList->WinLeft = 0.021875;
	MPHostListFullMapList->WinWidth = 0.392773;
	MPHostListFullMapList->WinHeight = 0.386486;
	//MPHostListFullMapList->OnChange=Tab_MultiplayerHostMain.MapListChange;
	UGUIScrollTextBox* MPHosT_AA2_Mapscroll = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	MPHosT_AA2_Mapscroll->CharDelay = 0.0025;
	MPHosT_AA2_Mapscroll->EOLDelay = 0.5;
	//MPHosT_AA2_Mapscroll->OnCreateComponent=MPHosT_AA2_Mapscroll.InternalOnCreateComponent;
	MPHosT_AA2_Mapscroll->WinTop = 0.255209;
	MPHosT_AA2_Mapscroll->WinLeft = 0.030859;
	MPHosT_AA2_Mapscroll->WinWidth = 0.430274;
	MPHosT_AA2_Mapscroll->WinHeight = 0.302539;
	UmoComboBox* MPHost_GameType = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	MPHost_GameType->ComponentJustification = EeTextAlign::TXTA_Left;
	MPHost_GameType->CaptionWidth = 0.3;
	MPHost_GameType->Caption = "Game Type:";
	//MPHost_GameType->OnCreateComponent=MPHost_GameType.InternalOnCreateComponent;
	MPHost_GameType->Hint = "Select the type of game you wish to play.";
	MPHost_GameType->WinTop = 0.047917;
	MPHost_GameType->WinLeft = 0.25;
	MPHost_GameType->WinHeight = 0.06;
	//MPHost_GameType->OnChange=Tab_MultiplayerHostMain.GameTypeChanged;
	UGUIImage* MPHostBK1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MPHostBK1->ImageColor = FColor(255, 255, 255, 160);
	MPHostBK1->ImageStyle = EImgStyle::ISTY_Stretched;
	MPHostBK1->WinTop = 0.024687;
	MPHostBK1->WinLeft = 0.016758;
	MPHostBK1->WinWidth = 0.9575;
	MPHostBK1->WinHeight = 0.107188;
	UGUIImage* MPHostBK2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MPHostBK2->ImageColor = FColor(255, 255, 255, 160);
	MPHostBK2->ImageStyle = EImgStyle::ISTY_Stretched;
	MPHostBK2->WinTop = 0.160885;
	MPHostBK2->WinLeft = 0.022695;
	MPHostBK2->WinWidth = 0.451172;
	MPHostBK2->WinHeight = 0.416016;
	UGUIImage* MPHost_MapImage = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MPHost_MapImage->ImageStyle = EImgStyle::ISTY_Scaled;
	MPHost_MapImage->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MPHost_MapImage->WinTop = 0.165573;
	MPHost_MapImage->WinLeft = 0.518984;
	MPHost_MapImage->WinWidth = 0.444063;
	MPHost_MapImage->WinHeight = 0.406562;
	UGUIImage* MPHostBK3 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MPHostBK3->ImageColor = FColor(255, 255, 255, 160);
	MPHostBK3->ImageStyle = EImgStyle::ISTY_Stretched;
	MPHostBK3->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MPHostBK3->WinTop = 0.160104;
	MPHostBK3->WinLeft = 0.515781;
	MPHostBK3->WinWidth = 0.450664;
	MPHostBK3->WinHeight = 0.416758;
	UGUILabel* MPHostMapName = NewObject<UGUILabel>(UGUILabel::StaticClass());
	MPHostMapName->Caption = "Testing";
	MPHostMapName->TextAlign = ETextAlign::TXTA_Center;
	MPHostMapName->TextColor = FColor(0, 180, 220, 255);
	MPHostMapName->TextFont = "UT2HeaderFont";
	MPHostMapName->WinTop = 0.175468;
	MPHostMapName->WinLeft = 0.057617;
	MPHostMapName->WinWidth = 0.382813;
	MPHostMapName->WinHeight = 32;
	UGUILabel* IAMain_MapAuthor = NewObject<UGUILabel>(UGUILabel::StaticClass());
	IAMain_MapAuthor->Caption = "Testing";
	IAMain_MapAuthor->TextAlign = ETextAlign::TXTA_Center;
	IAMain_MapAuthor->TextColor = FColor(255, 255, 255, 255);
	IAMain_MapAuthor->TextFont = "UT2SmallHeaderFont";
	IAMain_MapAuthor->WinTop = 0.471822;
	IAMain_MapAuthor->WinLeft = 0.531054;
	IAMain_MapAuthor->WinWidth = 0.445313;
	IAMain_MapAuthor->WinHeight = 17;
	UGUILabel* IAMain_MapPlayers = NewObject<UGUILabel>(UGUILabel::StaticClass());
	IAMain_MapPlayers->Caption = "Best for 4 to 8 players";
	IAMain_MapPlayers->TextAlign = ETextAlign::TXTA_Center;
	IAMain_MapPlayers->TextColor = FColor(255, 255, 255, 255);
	IAMain_MapPlayers->TextFont = "UT2SmallHeaderFont";
	IAMain_MapPlayers->WinTop = 0.513489;
	IAMain_MapPlayers->WinLeft = 0.531054;
	IAMain_MapPlayers->WinWidth = 0.445313;
	IAMain_MapPlayers->WinHeight = 17;

	MessageNoInfo = "No information available!";
	Controls = { MPHostBK1,MPHostBK2,MPHost_GameType,MPHost_MapImage,MPHosT_AA2_Mapscroll,MPHostBK3,MPHostListFullMapList,MPHostListAdd,MPHostListRemove,MPHostListUp,MPHostListAll,MPHostListClear,MPHostListDown,MPHostListCurMapList,MPHostMapName,IAMain_MapAuthor,IAMain_MapPlayers };
	WinTop = 0.15;
	WinHeight = 0.77;

}


void UTab_MultiplayerHostMain::OnChangeGameType()
{
}

void UTab_MultiplayerHostMain::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	FString Entry = "";
	FString Desc = "";
	int32 Index = 0;
	Super::InitComponent(MyController, MyOwner);
	MyGameCombo = moComboBox(Controls[2]);
	MyMapImage = GUIImage(Controls[3]);
	MyMapScroll = GUIScrollTextBox(Controls[4]);
	MyFullMapList = GUIListBox(Controls[6]);
	MyFullMapList.List.__OnDblClick__Delegate = MapAdd;
	MyCurMapList = GUIListBox(Controls[13]);
	MyCurMapList.List.__OnDblClick__Delegate = MapRemove;
	MyMapName = GUILabel(Controls[14]);
	Index = 0;
	PlayerOwner().GetNextIntDesc("GameInfo", Index, Entry, Desc);
	if (Entry != "")
	{
		Desc = Entry $ "|" $ Desc;
		if (!(PlayerOwner().Level.IsDemoBuild() && (InStr(Desc, "xDoubleDom") >= 0)))
		{
			MyGameCombo.addItem(ParseDescStr(Desc, 2), , Desc);
		}
		Index++;
		PlayerOwner().GetNextIntDesc("GameInfo", Index, Entry, Desc);
	}
	MyGameCombo.MyComboBox.List.SortList();
	SelectGameType(LastGameType);
	MyGameCombo.ReadOnly(true);
	ReadMapList(GetMapPrefix(), GetMapListClass());
	if ((LastMap == "") || (MyFullMapList.List.Find(LastMap) == ""))
	{
		MyFullMapList.List.SetIndex(0);
	}
	Entry = MyFullMapList.List.Get();
	if (Entry == "")
	{
		Entry = MyCurMapList.List.getItemAtIndex(0);
	}
	if (Entry != "")
	{
		ReadMapInfo(Entry);
	}
	*/
}

FString UTab_MultiplayerHostMain::Play()
{
	return "";
}

FString UTab_MultiplayerHostMain::ParseDescStr(FString DescStr, int32 Index)
{
	/*
	FString Temp = "";
	int32 p = 0;
	int32 i = 0;
	i = 0;
	if (DescStr != "")
	{
		p = InStr(DescStr, "|");
		if (p < 0)
		{
			Temp = DescStr;
			DescStr = "";
		}
		else
		{
			Temp = Left(DescStr, p);
			DescStr = Right(DescStr, ((Len(DescStr) - p) - 1));
		}
		if (i == Index)
		{
			return Temp;
		}
		i++;
	}
	*/
	return "FAKE";    //FAKE   /ELiZ
}

FString UTab_MultiplayerHostMain::GetMapPrefix()
{
	//return ParseDescStr(MyGameCombo.GetExtra(), 1);
	return "FAKE";    //FAKE   /ELiZ
}

FString UTab_MultiplayerHostMain::GetRulesClass()
{
	//return ParseDescStr(MyGameCombo.GetExtra(), 3);
	return "FAKE";    //FAKE   /ELiZ
}

bool UTab_MultiplayerHostMain::GetIsTeamGame()
{
	//return bool(ParseDescStr(MyGameCombo.GetExtra(), 5));
	return false;    //FAKE   /ELiZ
}

FString UTab_MultiplayerHostMain::GetMapListClass()
{
	//return ParseDescStr(MyGameCombo.GetExtra(), 4);
	return "FAKE";    //FAKE   /ELiZ
}

FString UTab_MultiplayerHostMain::GetGameClass()
{
	//return ParseDescStr(MyGameCombo.GetExtra(), 0);
	return "FAKE";    //FAKE   /ELiZ
}

void UTab_MultiplayerHostMain::ReadMapInfo(FString MapName)
{
	/*
	local LevelSummary L;
	FString mName = "";
	FString mDesc = "";
	int32 p = 0;
	if (MapName == "")
	{
		return;
	}
	L = LevelSummary(DynamicLoadObject(MapName $ ".LevelSummary", Class'LevelSummary'));
	if (L != None)
	{
		MyMapName.Caption = L.Title;
	}
	MyMapImage.Image = Material(DynamicLoadObject(MapName $ ".Screenshot", Class'Material'));
	p = InStr(MapName, "-");
	if (p < 0)
	{
		mName = MapName;
	}
	else
	{
		mName = Right(MapName, ((Len(MapName) - p) - 1));
	}
	if (L != None)
	{
		GUILabel(Controls[16]).Caption = "" $ string(L.IdealPlayerCountMin) @ "-" @ string(L.IdealPlayerCountMax) @ "players";
	}
	else
	{
		GUILabel(Controls[16]).Caption = "";
	}
	mDesc = Controller.LoadDecoText("XMaps", mName);
	if (mDesc == "")
	{
		if (L != None)
		{
			mDesc = L.Description;
		}
		else
		{
			mDesc = "No Description Available!";
		}
	}
	else
	{
		GUILabel(Controls[15]).Caption = "";
		MyMapScroll.SetContent(mDesc);
		return;
	}
	if (mDesc == "")
	{
		mDesc = MessageNoInfo;
	}
	if ((L != None) && (L.Author != ""))
	{
		GUILabel(Controls[15]).Caption = "Author:" @ L.Author;
	}
	else
	{
		GUILabel(Controls[15]).Caption = "";
	}
	MyMapScroll.SetContent(mDesc);
	*/
}

void UTab_MultiplayerHostMain::ReadMapList(FString MapPrefix, FString MapListClass)
{
}

bool UTab_MultiplayerHostMain::MapAdd(UGUIComponent* Sender)
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

bool UTab_MultiplayerHostMain::MapRemove(UGUIComponent* Sender)
{
	/*
	if ((MyCurMapList.ItemCount() == 0) || (MyCurMapList.List.Index < 0))
	{
		return true;
	}
	MyFullMapList.List.Add(MyCurMapList.List.Get());
	MyFullMapList.List.SortList();
	MyCurMapList.List.Remove(MyCurMapList.List.Index, 1);
	MapListChange(MyFullMapList);
	*/
	return true;
}

bool UTab_MultiplayerHostMain::MapAll(UGUIComponent* Sender)
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

bool UTab_MultiplayerHostMain::MapClear(UGUIComponent* Sender)
{
	/*
	if (MyCurMapList.ItemCount() == 0)
	{
		return true;
	}
	MyFullMapList.List.LoadFrom(MyCurMapList.List, false);
	MyCurMapList.List.Clear();
	MapListChange(MyFullMapList);
	*/
	return true;
}

bool UTab_MultiplayerHostMain::MapUp(UGUIComponent* Sender)
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

bool UTab_MultiplayerHostMain::MapDown(UGUIComponent* Sender)
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

void UTab_MultiplayerHostMain::GameTypeChanged(UGUIComponent* Sender)
{
	/*
	FString Desc = "";
	if (!Controller.bCurMenuInitialized)
	{
		return;
	}
	Desc = MyGameCombo.GetExtra();
	ReadMapList(GetMapPrefix(), GetMapListClass());
	LastGameType = ParseDescStr(Desc, 0);
	SaveConfig();
	OnChangeGameType();
	*/
}

void UTab_MultiplayerHostMain::MapListChange(UGUIComponent* Sender)
{
	/*
	FString Map = "";
	if (!Controller.bCurMenuInitialized)
	{
		return;
	}
	Map = GUIListBox(Sender).List.Get();
	if (Map == "")
	{
		return;
	}
	else
	{
		LastMap = Map;
	}
	SaveConfig();
	ReadMapInfo(LastMap);
	*/
}

void UTab_MultiplayerHostMain::SelectGameType(FString aGameType)
{
	/*
	int32 i = 0;
	local GUIList List;
	FString Desc = "";
	List = MyGameCombo.MyComboBox.List;
	for (i = 0; i < List.Elements.Length; i++)
	{
		Desc = List.GetExtraAtIndex(i);
		if (ParseDescStr(Desc, 0) ~= aGameType)
		{
			List.Index = i;
			MyGameCombo.SetText(ParseDescStr(Desc, 2));
			return;
		}
	}
	*/
}
