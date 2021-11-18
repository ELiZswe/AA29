// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_InstantActionMain/Tab_InstantActionMain.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/GUIListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moNumericEdit/moNumericEdit.h"

UTab_InstantActionMain::UTab_InstantActionMain()
{
	UmoCheckBox* IAMain_UseCustomBots = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	IAMain_UseCustomBots->ComponentJustification = EeTextAlign::TXTA_Left;
	IAMain_UseCustomBots->CaptionWidth = 0.9;
	IAMain_UseCustomBots->Caption = "Use Custom Bots";
	//IAMain_UseCustomBots->OnCreateComponent=IAMain_UseCustomBots.InternalOnCreateComponent;
	IAMain_UseCustomBots->Hint = "When enabled, you may use the Bot tab to choose bots to play with.";
	IAMain_UseCustomBots->WinTop = 0.849531;
	IAMain_UseCustomBots->WinLeft = 0.038476;
	IAMain_UseCustomBots->WinWidth = 0.45;
	IAMain_UseCustomBots->WinHeight = 0.06;
	//IAMain_UseCustomBots->OnChange=Tab_InstantActionMain.ChangeCustomBots;
	UmoCheckBox* IAMain_UseMapBots = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	IAMain_UseMapBots->ComponentJustification = EeTextAlign::TXTA_Left;
	IAMain_UseMapBots->CaptionWidth = 0.9;
	IAMain_UseMapBots->Caption = "Use Map Bot Count";
	//IAMain_UseMapBots->OnCreateComponent=IAMain_UseMapBots.InternalOnCreateComponent;
	IAMain_UseMapBots->Hint = "When enabled, an appropriate number of bots for the map will be used.";
	IAMain_UseMapBots->WinTop = 0.769531;
	IAMain_UseMapBots->WinLeft = 0.038476;
	IAMain_UseMapBots->WinWidth = 0.45;
	IAMain_UseMapBots->WinHeight = 0.06;
	//IAMain_UseMapBots->OnChange=Tab_InstantActionMain.ChangeMapBots;
	UmoComboBox* IAMain_BotSkill = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	IAMain_BotSkill->Caption = "Bot Skill";
	//IAMain_BotSkill->OnCreateComponent=IAMain_BotSkill.InternalOnCreateComponent;
	IAMain_BotSkill->Hint = "Choose the skill of the bots you wish to play with.";
	IAMain_BotSkill->WinTop = 0.689531;
	IAMain_BotSkill->WinLeft = 0.038476;
	IAMain_BotSkill->WinWidth = 0.45;
	IAMain_BotSkill->WinHeight = 0.06;
	//IAMain_BotSkill->OnChange=Tab_InstantActionMain.BotSkillChanged;
	UGUIScrollTextBox* IAMain_MapScroll = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	IAMain_MapScroll->CharDelay = 0.0025;
	IAMain_MapScroll->EOLDelay = 0.5;
	//IAMain_MapScroll->OnCreateComponent=IAMain_MapScroll.InternalOnCreateComponent;
	IAMain_MapScroll->WinTop = 0.689325;
	IAMain_MapScroll->WinLeft = 0.534569;
	IAMain_MapScroll->WinWidth = 0.435;
	IAMain_MapScroll->WinHeight = 0.3;
	IAMain_MapScroll->bNeverFocus = true;
	UGUIListBox* IAMain_MapList = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	IAMain_MapList->bVisibleWhenEmpty = true;
	//IAMain_MapList->OnCreateComponent=IAMain_MapList.InternalOnCreateComponent;
	IAMain_MapList->StyleName = "SquareButton";
	IAMain_MapList->Hint = "Select the map to play";
	IAMain_MapList->WinTop = 0.161406;
	IAMain_MapList->WinLeft = 0.021641;
	IAMain_MapList->WinWidth = 0.478984;
	IAMain_MapList->WinHeight = 0.463633;
	UmoComboBox* IAMain_GameType = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	IAMain_GameType->ComponentJustification = EeTextAlign::TXTA_Left;
	IAMain_GameType->CaptionWidth = 0.3;
	IAMain_GameType->Caption = "Game Type:";
	//IAMain_GameType->OnCreateComponent=IAMain_GameType.InternalOnCreateComponent;
	IAMain_GameType->Hint = "Select the type of game you wish to play.";
	IAMain_GameType->WinTop = 0.047917;
	IAMain_GameType->WinLeft = 0.25;
	IAMain_GameType->WinHeight = 0.06;
	//IAMain_GameType->OnChange=Tab_InstantActionMain.GameTypeChanged;
	UmoNumericEdit* IAMain_BotCount = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	IAMain_BotCount->MinValue = 0;
	IAMain_BotCount->MaxValue = 16;
	IAMain_BotCount->Caption = "Number of Bots";
	//IAMain_BotCount->OnCreateComponent=IAMain_BotCount.InternalOnCreateComponent;
	IAMain_BotCount->Hint = "Choose the number of bots you wish to play with.";
	IAMain_BotCount->WinTop = 0.919531;
	IAMain_BotCount->WinLeft = 0.038476;
	IAMain_BotCount->WinWidth = 0.45;
	IAMain_BotCount->WinHeight = 0.06;
	UGUIImage* IAMainBK1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//IAMainBK1->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	IAMainBK1->ImageColor = FColor(255, 255, 255, 160);
	IAMainBK1->ImageStyle = EImgStyle::ISTY_Stretched;
	IAMainBK1->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	IAMainBK1->WinTop = 0.024687;
	IAMainBK1->WinLeft = 0.021641;
	IAMainBK1->WinWidth = 0.9575;
	IAMainBK1->WinHeight = 0.107188;
	UGUIImage* IAMain_MapImage = NewObject<UGUIImage>(UGUIImage::StaticClass());
	IAMain_MapImage->ImageStyle = EImgStyle::ISTY_Scaled;
	IAMain_MapImage->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	IAMain_MapImage->WinTop = 0.163489;
	IAMain_MapImage->WinLeft = 0.531796;
	IAMain_MapImage->WinWidth = 0.44375;
	IAMain_MapImage->WinHeight = 0.405312;
	UGUIImage* IAMainBK3 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//IAMainBK3->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	IAMainBK3->ImageColor = FColor(255, 255, 255, 160);
	IAMainBK3->ImageStyle = EImgStyle::ISTY_Stretched;
	IAMainBK3->WinTop = 0.650469;
	IAMainBK3->WinLeft = 0.020742;
	IAMainBK3->WinWidth = 0.480469;
	IAMainBK3->WinHeight = 0.348633;
	UGUIImage* IAMainBK2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	IAMainBK2->ImageColor = FColor(255, 255, 255, 160);
	IAMainBK2->ImageStyle = EImgStyle::ISTY_Stretched;
	IAMainBK2->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	IAMainBK2->WinTop = 0.161406;
	IAMainBK2->WinLeft = 0.527891;
	IAMainBK2->WinWidth = 0.45;
	IAMainBK2->WinHeight = 0.41;
	UGUIImage* IAMain_DescBack = NewObject<UGUIImage>(UGUIImage::StaticClass());
	IAMain_DescBack->ImageColor = FColor(255, 255, 255, 160);
	IAMain_DescBack->ImageStyle = EImgStyle::ISTY_Stretched;
	IAMain_DescBack->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	IAMain_DescBack->WinTop = 0.591354;
	IAMain_DescBack->WinLeft = 0.527891;
	IAMain_DescBack->WinWidth = 0.45;
	IAMain_DescBack->WinHeight = 0.41;
	UGUILabel* IAMain_MapName = NewObject<UGUILabel>(UGUILabel::StaticClass());
	IAMain_MapName->Caption = "Testing";
	IAMain_MapName->TextAlign = ETextAlign::TXTA_Center;
	IAMain_MapName->TextColor = FColor(0, 180, 220, 255);
	IAMain_MapName->TextFont = "UT2HeaderFont";
	IAMain_MapName->WinTop = 0.596822;
	IAMain_MapName->WinLeft = 0.562304;
	IAMain_MapName->WinWidth = 0.382813;
	IAMain_MapName->WinHeight = 32;
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

	DifficultyLevels = { "Novice","Average","Experienced","Skilled","Adept","Masterful","Inhuman","Godlike" };
	MessageNoInfo = "No information available!";
	Controls = { IAMainBK1,IAMain_BotCount,IAMain_GameType,IAMain_MapList,IAMain_MapImage,IAMain_MapScroll,IAMainBK3,IAMain_BotSkill,IAMain_UseMapBots,IAMain_UseCustomBots,IAMainBK2,IAMain_DescBack,IAMain_MapName,IAMain_MapAuthor,IAMain_MapPlayers };
	WinTop = 0.15;
	WinHeight = 0.77;
}


void UTab_InstantActionMain::OnChangeGameType()
{
}

void UTab_InstantActionMain::OnChangeCustomBots()
{
}

void UTab_InstantActionMain::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	FString Entry = "";
	FString Desc = "";
	int32 Index = 0;
	Super::InitComponent(MyController, MyOwner);
	MyBotCount = moNumericEdit(Controls[1]);
	MyGameCombo = moComboBox(Controls[2]);
	MyMapList = GUIListBox(Controls[3]);
	MyMapImage = GUIImage(Controls[4]);
	MyMapScroll = GUIScrollTextBox(Controls[5]);
	MyBotSkill = moComboBox(Controls[7]);
	MyUseMapBots = moCheckBox(Controls[8]);
	MyUseCustomBots = moCheckBox(Controls[9]);
	MyMapName = GUILabel(Controls[12]);
	MyMapList.List.__OnChange__Delegate = MapListChange;
	MyMapList.List.__OnDblClick__Delegate = MapListDblClick;
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
	ReadMapList(GetMapPrefix());
	if ((LastMap == "") || (MyMapList.List.Find(LastMap) == ""))
	{
		MyMapList.List.SetIndex(0);
	}
	ReadMapInfo(MyMapList.List.Get());
	for (Index = 0; Index < 8; Index++)
	{
		MyBotSkill.addItem(DifficultyLevels[Index]);
	}
	MyBotSkill.ReadOnly(true);
	MyBotSkill.SetIndex(LastBotSkill);
	MyBotCount.SetValue(LastBotCount);
	MyUseCustomBots.Checked(LastUseCustomBots);
	MyUseMapBots.Checked(LastUseMapBots);
	if (LastUseMapBots)
	{
		MyUseCustomBots.Checked(false);
		MyUseCustomBots.MenuStateChange(4);
		MyBotCount.MenuStateChange(4);
	}
	else
	{
		MyUseCustomBots.MenuStateChange(0);
		if (LastUseCustomBots)
		{
			MyBotCount.MenuStateChange(4);
		}
		else
		{
			MyBotCount.MenuStateChange(0);
		}
	}
	*/
}

void UTab_InstantActionMain::SelectGameType(FString aGameType)
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

FString UTab_InstantActionMain::Play()
{
	/*
	LastBotCount = MyBotCount.GetValue();
	SaveConfig();
	return "?Difficulty=" $ string(LastBotSkill) $ "?bAutoNumBots=" $ string(LastUseMapBots) $ "?NumBots=" $ string(LastBotCount);
	*/
	return "FAKE";    //FAKE   /ELiZ
}

FString UTab_InstantActionMain::ParseDescStr(FString DescStr, int32 Index)
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

FString UTab_InstantActionMain::GetMapPrefix()
{
	//return ParseDescStr(MyGameCombo.GetExtra(), 1);
	return "FAKE";    //FAKE   /ELiZ
}

FString UTab_InstantActionMain::GetRulesClass()
{
	//return ParseDescStr(MyGameCombo.GetExtra(), 3);
	return "FAKE";    //FAKE   /ELiZ
}

FString UTab_InstantActionMain::GetMapListClass()
{
	//return ParseDescStr(MyGameCombo.GetExtra(), 4);
	return "FAKE";    //FAKE   /ELiZ
}

bool UTab_InstantActionMain::GetIsTeamGame()
{
	//return bool(ParseDescStr(MyGameCombo.GetExtra(), 5));
	return false;    //FAKE   /ELiZ
}

FString UTab_InstantActionMain::GetGameClass()
{
	//return ParseDescStr(MyGameCombo.GetExtra(), 0);
	return "FAKE";    //FAKE   /ELiZ
}

void UTab_InstantActionMain::ReadMapList(FString MapPrefix)
{
	/*
	MyMapList.List.Clear();
	Controller.GetMapList(MapPrefix, MyMapList.List);
	MyMapList.List.SortList();
	MyMapList.List.SetIndex(0);
	*/
}

void UTab_InstantActionMain::ReadMapInfo(FString MapName)
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
	else
	{
		MyMapName.Caption = MapName;
	}
	MyMapImage.Image = Material(DynamicLoadObject(MapName $ ".Screenshot", Class'Material'));
	if (MyMapImage.Image == None)
	{
	}
	p = InStr(MapName, "-");
	if (p < 0)
	{
		mName = MapName;
	}
	else
	{
		mName = Right(MapName, ((Len(MapName) - p) - 1));
	}
	GUILabel(Controls[14]).Caption = "" $ string(L.IdealPlayerCountMin) @ "-" @ string(L.IdealPlayerCountMax) @ "players";
	mDesc = Controller.LoadDecoText("XMaps", mName);
	if (mDesc == "")
	{
		mDesc = L.Description;
	}
	else
	{
		GUILabel(Controls[13]).Caption = "";
		MyMapScroll.SetContent(mDesc);
		return;
	}
	if (mDesc == "")
	{
		mDesc = MessageNoInfo;
	}
	if (L.Author != "")
	{
		GUILabel(Controls[13]).Caption = "Author:" @ L.Author;
	}
	else
	{
		GUILabel(Controls[13]).Caption = "";
	}
	MyMapScroll.SetContent(mDesc);
	*/
}

void UTab_InstantActionMain::GameTypeChanged(UGUIComponent* Sender)
{
	/*
	FString Desc = "";
	if (!Controller.bCurMenuInitialized)
	{
		return;
	}
	Desc = MyGameCombo.GetExtra();
	ReadMapList(ParseDescStr(Desc, 1));
	LastGameType = ParseDescStr(Desc, 0);
	SaveConfig();
	OnChangeGameType();
	*/
}

void UTab_InstantActionMain::MapListChange(UGUIComponent* Sender)
{
	/*
	if (!Controller.bCurMenuInitialized)
	{
		return;
	}
	LastMap = MyMapList.List.Get();
	SaveConfig();
	ReadMapInfo(LastMap);
	*/
}

void UTab_InstantActionMain::BotSkillChanged(UGUIComponent* Sender)
{
	/*
	if (!Controller.bCurMenuInitialized)
	{
		return;
	}
	LastBotSkill = MyBotSkill.GetIndex();
	SaveConfig();
	*/
}

void UTab_InstantActionMain::ChangeMapBots(UGUIComponent* Sender)
{
	/*
	if (!Controller.bCurMenuInitialized)
	{
		return;
	}
	LastUseMapBots = MyUseMapBots.IsChecked();
	SaveConfig();
	if (LastUseMapBots)
	{
		MyUseCustomBots.Checked(false);
		MyUseCustomBots.MenuStateChange(4);
		MyBotCount.MenuStateChange(4);
	}
	else
	{
		MyUseCustomBots.MenuStateChange(0);
		MyBotCount.MenuStateChange(0);
	}
	*/
}

void UTab_InstantActionMain::ChangeCustomBots(UGUIComponent* Sender)
{
	/*
	if (!Controller.bCurMenuInitialized)
	{
		return;
	}
	LastUseCustomBots = MyUseCustomBots.IsChecked();
	SaveConfig();
	if (LastUseCustomBots)
	{
		MyBotCount.MenuStateChange(4);
	}
	else
	{
		MyBotCount.MenuStateChange(0);
	}
	OnChangeCustomBots();
	*/
}

bool UTab_InstantActionMain::MapListDblClick(UGUIComponent* Sender)
{
	//UT2InstantActionPage(Controller.ActivePage).PlayButtonClick(Self);
	return true;
}