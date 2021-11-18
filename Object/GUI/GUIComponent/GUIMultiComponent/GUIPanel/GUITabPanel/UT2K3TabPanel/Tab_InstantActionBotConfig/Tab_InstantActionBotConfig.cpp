// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_InstantActionBotConfig/Tab_InstantActionBotConfig.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUICircularList/GUICharacterList/GUICharacterList.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/GUIListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIScrollButtonBase/GUIHorzScrollButton/GUIHorzScrollButton.h"

UTab_InstantActionBotConfig::UTab_InstantActionBotConfig()
{
	UGUICharacterList* IABotConfigCharList = NewObject<UGUICharacterList>(UGUICharacterList::StaticClass());
	IABotConfigCharList->StyleName = "CharButton";
	IABotConfigCharList->Hint = "Select a bot to add to a team";
	IABotConfigCharList->WinTop = 0.689897;
	IABotConfigCharList->WinLeft = 0.13789;
	IABotConfigCharList->WinWidth = 0.724609;
	IABotConfigCharList->WinHeight = 0.236758;
	//IABotConfigCharList->OnClick=IABotConfigCharList.InternalOnClick;
	//IABotConfigCharList->OnRightClick=IABotConfigCharList.InternalOnRightClick;
	//IABotConfigCharList->OnMousePressed=IABotConfigCharList.InternalOnMousePressed;
	//IABotConfigCharList->OnMouseRelease=IABotConfigCharList.InternalOnMouseRelease;
	//IABotConfigCharList->OnChange=Tab_InstantActionBotConfig.CharListChange;
	//IABotConfigCharList->OnKeyEvent=IABotConfigCharList.InternalOnKeyEvent;
	//IABotConfigCharList->OnBeginDrag=IABotConfigCharList.InternalOnBeginDrag;
	//IABotConfigCharList->OnEndDrag=IABotConfigCharList.InternalOnEndDrag;
	//IABotConfigCharList->OnDragDrop=IABotConfigCharList.InternalOnDragDrop;
	//IABotConfigCharList->OnDragEnter=IABotConfigCharList.InternalOnDragEnter;
	//IABotConfigCharList->OnDragLeave=IABotConfigCharList.InternalOnDragLeave;
	//IABotConfigCharList->OnDragOver=IABotConfigCharList.InternalOnDragOver;
	UGUIButton* IABotConfigDoConfig = NewObject<UGUIButton>(UGUIButton::StaticClass());
	IABotConfigDoConfig->Caption = "Customize";
	IABotConfigDoConfig->Hint = "Change the AI attributes for this bot";
	IABotConfigDoConfig->WinTop = 0.951199;
	IABotConfigDoConfig->WinLeft = 0.491993;
	IABotConfigDoConfig->WinWidth = 0.239063;
	IABotConfigDoConfig->WinHeight = 0.049765;
	//IABotConfigDoConfig->OnClick=Tab_InstantActionBotConfig.BotConfigClick;
	//IABotConfigDoConfig->OnKeyEvent=IABotConfigDoConfig.InternalOnKeyEvent;
	UGUIButton* BotRight = NewObject<UGUIButton>(UGUIButton::StaticClass());
	BotRight->StyleName = "ArrowRight";
	BotRight->WinTop = 0.775783;
	BotRight->WinLeft = 0.845899;
	BotRight->WinWidth = 0.043555;
	BotRight->WinHeight = 0.084414;
	BotRight->bNeverFocus = true;
	BotRight->bRepeatClick = true;
	//BotRight->OnClick=Tab_InstantActionBotConfig.InternalOnClick;
	//BotRight->OnKeyEvent=BotRight.InternalOnKeyEvent;
	UGUIButton* BotLeft = NewObject<UGUIButton>(UGUIButton::StaticClass());
	BotLeft->StyleName = "ArrowLeft";
	BotLeft->WinTop = 0.775783;
	BotLeft->WinLeft = 0.108203;
	BotLeft->WinWidth = 0.043555;
	BotLeft->WinHeight = 0.084414;
	BotLeft->bNeverFocus = true;
	BotLeft->bRepeatClick = true;
	//BotLeft->OnClick=Tab_InstantActionBotConfig.InternalOnClick;
	//BotLeft->OnKeyEvent=BotLeft.InternalOnKeyEvent;
	UGUIButton* IABotConfigConfig = NewObject<UGUIButton>(UGUIButton::StaticClass());
	IABotConfigConfig->Caption = "More Info";
	IABotConfigConfig->Hint = "Find out more info on this bot";
	IABotConfigConfig->WinTop = 0.951199;
	IABotConfigConfig->WinLeft = 0.249806;
	IABotConfigConfig->WinWidth = 0.239063;
	IABotConfigConfig->WinHeight = 0.049765;
	//IABotConfigConfig->OnClick=Tab_InstantActionBotConfig.BotInfoClick;
	//IABotConfigConfig->OnKeyEvent=IABotConfigConfig.InternalOnKeyEvent;
	UGUIListBox* IABotConfigBlueList = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	IABotConfigBlueList->bVisibleWhenEmpty = true;
	//IABotConfigBlueList->OnCreateComponent=IABotConfigBlueList.InternalOnCreateComponent;
	IABotConfigBlueList->StyleName = "SquareButton";
	IABotConfigBlueList->Hint = "The Blue Team's Roster.";
	IABotConfigBlueList->WinTop = 0.115833;
	IABotConfigBlueList->WinLeft = 0.647853;
	IABotConfigBlueList->WinWidth = 0.324414;
	IABotConfigBlueList->WinHeight = 0.463633;
	//IABotConfigBlueList->OnChange=Tab_InstantActionBotConfig.ListChange;
	UGUIHorzScrollButton* IABotConfigBlueRemove = NewObject<UGUIHorzScrollButton>(UGUIHorzScrollButton::StaticClass());
	IABotConfigBlueRemove->LeftButton = true;
	IABotConfigBlueRemove->Hint = "Remove Bot from Blue Team";
	IABotConfigBlueRemove->WinTop = 0.358073;
	IABotConfigBlueRemove->WinLeft = 0.577344;
	IABotConfigBlueRemove->WinWidth = 0.064648;
	IABotConfigBlueRemove->WinHeight = 0.079297;
	//IABotConfigBlueRemove->OnClick=Tab_InstantActionBotConfig.BlueClickRemove;
	//IABotConfigBlueRemove->OnKeyEvent=IABotConfigBlueRemove.InternalOnKeyEvent;
	UGUIHorzScrollButton* IABotConfigBlueAdd = NewObject<UGUIHorzScrollButton>(UGUIHorzScrollButton::StaticClass());
	IABotConfigBlueAdd->Hint = "Add Bot to Blue Team";
	IABotConfigBlueAdd->WinTop = 0.208334;
	IABotConfigBlueAdd->WinLeft = 0.577344;
	IABotConfigBlueAdd->WinWidth = 0.064648;
	IABotConfigBlueAdd->WinHeight = 0.079297;
	//IABotConfigBlueAdd->OnClick=Tab_InstantActionBotConfig.BlueClickAdd;
	//IABotConfigBlueAdd->OnKeyEvent=IABotConfigBlueAdd.InternalOnKeyEvent;
	UGUIHorzScrollButton* IABotConfigRedRemove = NewObject<UGUIHorzScrollButton>(UGUIHorzScrollButton::StaticClass());
	IABotConfigRedRemove->Hint = "Remove Bot from Red Team";
	IABotConfigRedRemove->WinTop = 0.358073;
	IABotConfigRedRemove->WinLeft = 0.357617;
	IABotConfigRedRemove->WinWidth = 0.064648;
	IABotConfigRedRemove->WinHeight = 0.079297;
	//IABotConfigRedRemove->OnClick=Tab_InstantActionBotConfig.RedClickRemove;
	//IABotConfigRedRemove->OnKeyEvent=IABotConfigRedRemove.InternalOnKeyEvent;
	UGUIHorzScrollButton* IABotConfigRedAdd = NewObject<UGUIHorzScrollButton>(UGUIHorzScrollButton::StaticClass());
	IABotConfigRedAdd->LeftButton = true;
	IABotConfigRedAdd->Hint = "Add Bot to Red Team";
	IABotConfigRedAdd->WinTop = 0.208334;
	IABotConfigRedAdd->WinLeft = 0.357617;
	IABotConfigRedAdd->WinWidth = 0.064648;
	IABotConfigRedAdd->WinHeight = 0.079297;
	//IABotConfigRedAdd->OnClick=Tab_InstantActionBotConfig.RedClickAdd;
	//IABotConfigRedAdd->OnKeyEvent=IABotConfigRedAdd.InternalOnKeyEvent;
	UGUIListBox* IABotConfigRedList = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	IABotConfigRedList->bVisibleWhenEmpty = true;
	//IABotConfigRedList->OnCreateComponent=IABotConfigRedList.InternalOnCreateComponent;
	IABotConfigRedList->StyleName = "SquareButton";
	IABotConfigRedList->Hint = "The Red Team's Roster.";
	IABotConfigRedList->WinTop = 0.115833;
	IABotConfigRedList->WinLeft = 0.026758;
	IABotConfigRedList->WinWidth = 0.324414;
	IABotConfigRedList->WinHeight = 0.458751;
	//IABotConfigRedList->OnChange=Tab_InstantActionBotConfig.ListChange;
	UGUIImage* IABotConfigBK1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//IABotConfigBK1->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	IABotConfigBK1->ImageColor = FColor(255, 255, 255, 160);
	IABotConfigBK1->ImageStyle = EImgStyle::ISTY_Stretched;
	IABotConfigBK1->WinTop = 0.630156;
	IABotConfigBK1->WinLeft = 0.016758;
	IABotConfigBK1->WinWidth = 0.962383;
	IABotConfigBK1->WinHeight = 0.37086;
	IABotConfigBK1->bVisible = false;
	UGUIImage* IABotConfigPortrait = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//IABotConfigPortrait->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	IABotConfigPortrait->ImageStyle = EImgStyle::ISTY_Scaled;
	IABotConfigPortrait->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	IABotConfigPortrait->WinTop = 0.119166;
	IABotConfigPortrait->WinLeft = 0.440547;
	IABotConfigPortrait->WinWidth = 0.118711;
	IABotConfigPortrait->WinHeight = 0.451251;
	UGUIImage* IABotConfigPortraitBorder = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//IABotConfigPortraitBorder->Image=Texture'InterfaceContent.Menu.BorderBoxA1';
	IABotConfigPortraitBorder->ImageStyle = EImgStyle::ISTY_Stretched;
	IABotConfigPortraitBorder->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	IABotConfigPortraitBorder->WinTop = 0.115833;
	IABotConfigPortraitBorder->WinLeft = 0.438047;
	IABotConfigPortraitBorder->WinWidth = 0.123711;
	IABotConfigPortraitBorder->WinHeight = 0.458751;
	UGUILabel* IABotConfigName = NewObject<UGUILabel>(UGUILabel::StaticClass());
	IABotConfigName->TextAlign = ETextAlign::TXTA_Center;
	IABotConfigName->TextColor = FColor(0, 180, 220, 255);
	IABotConfigName->TextFont = "UT2HeaderFont";
	IABotConfigName->WinTop = 0.58177;
	IABotConfigName->WinHeight = 0.13;
	UGUILabel* IABotConfigRedName = NewObject<UGUILabel>(UGUILabel::StaticClass());
	IABotConfigRedName->Caption = "Red Team";
	IABotConfigRedName->TextColor = FColor(0, 0, 255, 255);
	IABotConfigRedName->WinTop = 0.027082;
	IABotConfigRedName->WinLeft = 0.039063;
	IABotConfigRedName->WinWidth = 0.25;
	IABotConfigRedName->WinHeight = 0.13;
	UGUILabel* IABotConfigBlueName = NewObject<UGUILabel>(UGUILabel::StaticClass());
	IABotConfigBlueName->Caption = "Blue Team";
	IABotConfigBlueName->TextColor = FColor(255, 0, 0, 255);
	IABotConfigBlueName->WinTop = 0.027082;
	IABotConfigBlueName->WinLeft = 0.655862;
	IABotConfigBlueName->WinWidth = 0.25;
	IABotConfigBlueName->WinHeight = 0.13;
	UGUILabel* IABotConfigDMName = NewObject<UGUILabel>(UGUILabel::StaticClass());
	IABotConfigDMName->Caption = "Deathmatch";
	IABotConfigDMName->TextColor = FColor(0, 0, 255, 255);
	IABotConfigDMName->WinTop = 0.032552;
	IABotConfigDMName->WinLeft = 0.039063;
	IABotConfigDMName->WinWidth = 0.25;
	IABotConfigDMName->WinHeight = 0.13;
	IABotConfigDMName->bVisible = false;

	Controls = { IABotConfigBK1,IABotConfigRedList,IABotConfigRedAdd,IABotConfigRedRemove,IABotConfigPortrait,IABotConfigPortraitBorder,IABotConfigBlueAdd,IABotConfigBlueRemove,IABotConfigBlueList,IABotConfigCharList,IABotConfigConfig,IABotConfigName,IABotConfigRedName,IABotConfigBlueName,IABotConfigDMName,BotLeft,BotRight,IABotConfigDoConfig };
	WinTop = 0.15;
	WinHeight = 0.77;
}

void UTab_InstantActionBotConfig::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	MyRedTeam = GUIListBox(Controls[1]);
	MyBlueTeam = GUIListBox(Controls[8]);
	MyPortrait = GUIImage(Controls[4]);
	MyBotList = GUICharacterList(Controls[9]);
	MyBotMaker = GUIButton(Controls[10]);
	MyBotName = GUILabel(Controls[11]);
	MyPortrait.Image = MyBotList.GetPortrait();
	MyBotName.Caption = MyBotList.GetName();
	*/
}

void UTab_InstantActionBotConfig::ShowPanel(bool bShow)
{
	/*
	Super::ShowPanel(bShow);
	if (bShow)
	{
		bPlaySounds = true;
	}
	else
	{
		bPlaySounds = false;
	}
	*/
}

void UTab_InstantActionBotConfig::SetupBotLists(bool bIsTeam)
{
}

FString UTab_InstantActionBotConfig::Play()
{
	return "";
}

void UTab_InstantActionBotConfig::CharListChange(UGUIComponent* Sender)
{
	/*
	local Sound NameSound;
	MyPortrait.Image = MyBotList.GetPortrait();
	MyBotName.Caption = MyBotList.GetName();
	if (bPlaySounds)
	{
		NameSound = MyBotList.GetSound();
		PlayerOwner().ClientPlaySound(NameSound, , , 6);
	}
	*/
}

bool UTab_InstantActionBotConfig::RedClickAdd(UGUIComponent* Sender)
{
	/*
	if (MyRedTeam.ItemCount() < 16)
	{
		bIgnoreListChange = true;
		MyRedTeam.List.Add(MyBotName.Caption);
	}
	*/
	return true;
}

bool UTab_InstantActionBotConfig::BlueClickAdd(UGUIComponent* Sender)
{
	/*
	if (MyBlueTeam.ItemCount() < 16)
	{
		bIgnoreListChange = true;
		MyBlueTeam.List.Add(MyBotName.Caption);
	}
	*/
	return true;
}

bool UTab_InstantActionBotConfig::RedClickRemove(UGUIComponent* Sender)
{
	/*
	int32 Index = 0;
	if (MyRedTeam.ItemCount() == 0)
	{
		return true;
	}
	Index = MyRedTeam.List.Index;
	if (Index < 0)
	{
		return true;
	}
	bIgnoreListChange = true;
	MyRedTeam.List.Remove(Index, 1);
	if (Index < MyRedTeam.List.ItemCount)
	{
		MyRedTeam.List.SetIndex(Index);
	}
	*/
	return true;
}

bool UTab_InstantActionBotConfig::BlueClickRemove(UGUIComponent* Sender)
{
	/*
	int32 Index = 0;
	if (MyBlueTeam.ItemCount() == 0)
	{
		return true;
	}
	Index = MyBlueTeam.List.Index;
	if (Index < 0)
	{
		return true;
	}
	bIgnoreListChange = true;
	MyBlueTeam.List.Remove(Index, 1);
	if (Index < MyBlueTeam.List.ItemCount)
	{
		MyBlueTeam.List.SetIndex(Index);
	}
	*/
	return true;
}

void UTab_InstantActionBotConfig::ListChange(UGUIComponent* Sender)
{
	/*
	local GUIListBox Who;
	FString WhoName = "";
	if (bIgnoreListChange)
	{
		bIgnoreListChange = false;
		return;
	}
	Who = GUIListBox(Sender);
	if (Who == None)
	{
		return;
	}
	WhoName = Who.List.Get();
	if (WhoName != "")
	{
		MyBotList.Find(WhoName);
	}
	*/
}

bool UTab_InstantActionBotConfig::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (Sender == Controls[15])
	{
		MyBotList.PgUp();
	}
	else
	{
		if (Sender == Controls[16])
		{
			MyBotList.PgDown();
		}
	}
	*/
	return true;
}

bool UTab_InstantActionBotConfig::BotInfoClick(UGUIComponent* Sender)
{
	return true;
}

bool UTab_InstantActionBotConfig::BotConfigClick(UGUIComponent* Sender)
{
	return true;
}