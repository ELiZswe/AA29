// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_SPPanelBase/Tab_SPProfileLoad/Tab_SPProfileLoad.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/GUIListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UTab_SPProfileLoad::UTab_SPProfileLoad()
{
	UmoEditBox* moebMatches = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	moebMatches->bReadOnly = true;
	moebMatches->LabelJustification = EeTextAlign::TXTA_Right;
	moebMatches->CaptionWidth = 0.55;
	moebMatches->Caption = "Matches: ";
	moebMatches->LabelFont = "UT2SmallFont";
	moebMatches->LabelColor = FColor(255, 255, 255, 255);
	//moebMatches->OnCreateComponent=moebMatches.InternalOnCreateComponent;
	moebMatches->Hint = "Number of matches played by this character";
	moebMatches->WinTop = 0.667852;
	moebMatches->WinLeft = 0.49536;
	moebMatches->WinWidth = 0.49375;
	moebMatches->WinHeight = 0.06;
	UmoEditBox* moebWins = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	moebWins->bReadOnly = true;
	moebWins->LabelJustification = EeTextAlign::TXTA_Right;
	moebWins->CaptionWidth = 0.55;
	moebWins->Caption = "Wins: ";
	moebWins->LabelFont = "UT2SmallFont";
	moebWins->LabelColor = FColor(255, 255, 255, 255);
	//moebWins->OnCreateComponent=moebWins.InternalOnCreateComponent;
	moebWins->Hint = "Number of matches won by this character";
	moebWins->WinTop = 0.597135;
	moebWins->WinLeft = 0.495315;
	moebWins->WinWidth = 0.493751;
	moebWins->WinHeight = 0.06;
	UGUIButton* btnNew = NewObject<UGUIButton>(UGUIButton::StaticClass());
	btnNew->Caption = "NEW PROFILE";
	btnNew->Hint = "Go to the profile creation menu";
	btnNew->WinTop = 0.925;
	btnNew->WinLeft = 0.66125;
	btnNew->WinWidth = 0.2;
	btnNew->WinHeight = 0.075;
	//btnNew->OnClick=Tab_SPProfileLoad.NewProfileClick;
	//btnNew->OnKeyEvent=btnNew.InternalOnKeyEvent;
	UGUIButton* btnLoad = NewObject<UGUIButton>(UGUIButton::StaticClass());
	btnLoad->Caption = "LOAD PROFILE";
	btnLoad->Hint = "Load the selected profile";
	btnLoad->WinTop = 0.925;
	btnLoad->WinLeft = 0.4125;
	btnLoad->WinWidth = 0.2;
	btnLoad->WinHeight = 0.075;
	//btnLoad->OnClick=Tab_SPProfileLoad.LoadClick;
	//btnLoad->OnKeyEvent=btnLoad.InternalOnKeyEvent;
	UGUIButton* btnDelete = NewObject<UGUIButton>(UGUIButton::StaticClass());
	btnDelete->Caption = "DELETE PROFILE";
	btnDelete->Hint = "Delete the currently selected profile";
	btnDelete->WinTop = 0.925;
	btnDelete->WinLeft = 0.14125;
	btnDelete->WinWidth = 0.21875;
	btnDelete->WinHeight = 0.075;
	//btnDelete->OnClick=Tab_SPProfileLoad.DeleteClick;
	//btnDelete->OnKeyEvent=btnDelete.InternalOnKeyEvent;
	UmoEditBox* moebGoals = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	moebGoals->bReadOnly = true;
	moebGoals->LabelJustification = EeTextAlign::TXTA_Right;
	moebGoals->CaptionWidth = 0.55;
	moebGoals->Caption = "Goals: ";
	moebGoals->LabelFont = "UT2SmallFont";
	moebGoals->LabelColor = FColor(255, 255, 255, 255);
	//moebGoals->OnCreateComponent=moebGoals.InternalOnCreateComponent;
	moebGoals->Hint = "Number of goals scored by this character";
	moebGoals->WinTop = 0.528632;
	moebGoals->WinLeft = 0.49536;
	moebGoals->WinWidth = 0.49375;
	moebGoals->WinHeight = 0.06;
	UmoEditBox* moebDeaths = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	moebDeaths->bReadOnly = true;
	moebDeaths->LabelJustification = EeTextAlign::TXTA_Right;
	moebDeaths->CaptionWidth = 0.55;
	moebDeaths->Caption = "Deaths: ";
	moebDeaths->LabelFont = "UT2SmallFont";
	moebDeaths->LabelColor = FColor(255, 255, 255, 255);
	//moebDeaths->OnCreateComponent=moebDeaths.InternalOnCreateComponent;
	moebDeaths->Hint = "Number of times this character has died";
	moebDeaths->WinTop = 0.458684;
	moebDeaths->WinLeft = 0.49536;
	moebDeaths->WinWidth = 0.49375;
	moebDeaths->WinHeight = 0.06;
	UmoEditBox* moebKills = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	moebKills->bReadOnly = true;
	moebKills->LabelJustification = EeTextAlign::TXTA_Right;
	moebKills->CaptionWidth = 0.55;
	moebKills->Caption = "Kills: ";
	moebKills->LabelFont = "UT2SmallFont";
	moebKills->LabelColor = FColor(255, 255, 255, 255);
	//moebKills->OnCreateComponent=moebKills.InternalOnCreateComponent;
	moebKills->Hint = "Number of kills by this character";
	moebKills->WinTop = 0.391236;
	moebKills->WinLeft = 0.49536;
	moebKills->WinWidth = 0.49375;
	moebKills->WinHeight = 0.06;
	UmoEditBox* moebDifficulty = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	moebDifficulty->bReadOnly = true;
	moebDifficulty->LabelJustification = EeTextAlign::TXTA_Right;
	moebDifficulty->CaptionWidth = 0.55;
	moebDifficulty->Caption = "Difficulty: ";
	moebDifficulty->LabelFont = "UT2SmallFont";
	moebDifficulty->LabelColor = FColor(255, 255, 255, 255);
	//moebDifficulty->OnCreateComponent=moebDifficulty.InternalOnCreateComponent;
	moebDifficulty->Hint = "Difficulty rating of this tournament";
	moebDifficulty->WinTop = 0.280038;
	moebDifficulty->WinLeft = 0.49536;
	moebDifficulty->WinWidth = 0.49375;
	moebDifficulty->WinHeight = 0.06;
	UmoEditBox* moebTeamName = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	moebTeamName->bReadOnly = true;
	moebTeamName->LabelJustification = EeTextAlign::TXTA_Right;
	moebTeamName->CaptionWidth = 0.55;
	moebTeamName->Caption = "Team Name: ";
	moebTeamName->LabelFont = "UT2SmallFont";
	moebTeamName->LabelColor = FColor(255, 255, 255, 255);
	//moebTeamName->OnCreateComponent=moebTeamName.InternalOnCreateComponent;
	moebTeamName->Hint = "The name of your team";
	moebTeamName->WinTop = 0.21259;
	moebTeamName->WinLeft = 0.49536;
	moebTeamName->WinWidth = 0.49375;
	moebTeamName->WinHeight = 0.06;
	UmoEditBox* moebPlayerName = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	moebPlayerName->bReadOnly = true;
	moebPlayerName->LabelJustification = EeTextAlign::TXTA_Right;
	moebPlayerName->CaptionWidth = 0.55;
	moebPlayerName->Caption = "Player Name: ";
	moebPlayerName->LabelFont = "UT2SmallFont";
	moebPlayerName->LabelColor = FColor(255, 255, 255, 255);
	//moebPlayerName->OnCreateComponent=moebPlayerName.InternalOnCreateComponent;
	moebPlayerName->Hint = "Your character's name";
	moebPlayerName->WinTop = 0.143847;
	moebPlayerName->WinLeft = 0.49536;
	moebPlayerName->WinWidth = 0.49375;
	moebPlayerName->WinHeight = 0.06;
	UGUIListBox* lboxProfile = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	//lboxProfile->OnCreateComponent=lboxProfile.InternalOnCreateComponent;
	lboxProfile->Hint = "Select a profile";
	lboxProfile->WinTop = 0.131667;
	lboxProfile->WinLeft = 0.330562;
	lboxProfile->WinWidth = 0.264609;
	lboxProfile->WinHeight = 0.610624;
	//lboxProfile->OnChange=Tab_SPProfileLoad.InternalOnChange;
	UGUIImage* imageSkinBack = NewObject<UGUIImage>(UGUIImage::StaticClass());
	imageSkinBack->ImageStyle = EImgStyle::ISTY_Stretched;
	imageSkinBack->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	imageSkinBack->WinTop = 0.158646;
	imageSkinBack->WinLeft = 0.171195;
	imageSkinBack->WinWidth = 0.1383;
	imageSkinBack->WinHeight = 0.51;
	UGUIImage* imagePlayerSkin = NewObject<UGUIImage>(UGUIImage::StaticClass());
	imagePlayerSkin->ImageStyle = EImgStyle::ISTY_Scaled;
	imagePlayerSkin->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	imagePlayerSkin->Hint = "Your character's appearance";
	imagePlayerSkin->WinTop = 0.162552;
	imagePlayerSkin->WinLeft = 0.173148;
	imagePlayerSkin->WinWidth = 0.1333;
	imagePlayerSkin->WinHeight = 0.5;
	UGUIImage* imageTeamSymbol = NewObject<UGUIImage>(UGUIImage::StaticClass());
	imageTeamSymbol->ImageStyle = EImgStyle::ISTY_Scaled;
	imageTeamSymbol->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	imageTeamSymbol->Hint = "Your team's symbol";
	imageTeamSymbol->WinTop = 0.2625;
	imageTeamSymbol->WinLeft = 0.016538;
	imageTeamSymbol->WinWidth = 0.15;
	imageTeamSymbol->WinHeight = 0.2778;
	UGUIImage* SPPLDataBox = NewObject<UGUIImage>(UGUIImage::StaticClass());
	SPPLDataBox->ImageColor = FColor(255, 255, 255, 160);
	SPPLDataBox->ImageStyle = EImgStyle::ISTY_Stretched;
	SPPLDataBox->WinTop = 0.13125;
	SPPLDataBox->WinLeft = 0.601563;
	SPPLDataBox->WinWidth = 0.393751;
	SPPLDataBox->WinHeight = 0.61375;
	UGUIImage* SPPLImageBox = NewObject<UGUIImage>(UGUIImage::StaticClass());
	SPPLImageBox->ImageColor = FColor(255, 255, 255, 160);
	SPPLImageBox->ImageStyle = EImgStyle::ISTY_Stretched;
	SPPLImageBox->WinTop = 0.13125;
	SPPLImageBox->WinLeft = 0.006251;
	SPPLImageBox->WinWidth = 0.318752;
	SPPLImageBox->WinHeight = 0.612187;
	UGUILabel* SPPLLblStats = NewObject<UGUILabel>(UGUILabel::StaticClass());
	SPPLLblStats->Caption = "PROFILE STATS";
	SPPLLblStats->TextAlign = ETextAlign::TXTA_Center;
	SPPLLblStats->TextColor = FColor(255, 255, 255, 255);
	SPPLLblStats->TextFont = "UT2SmallFont";
	SPPLLblStats->WinTop = 0.734586;
	SPPLLblStats->WinLeft = 0.592186;
	SPPLLblStats->WinWidth = 0.4;
	SPPLLblStats->WinHeight = 0.1;
	UGUILabel* SPPLLblProfiles = NewObject<UGUILabel>(UGUILabel::StaticClass());
	SPPLLblProfiles->Caption = "PROFILE LISTING";
	SPPLLblProfiles->TextAlign = ETextAlign::TXTA_Center;
	SPPLLblProfiles->TextColor = FColor(255, 255, 255, 255);
	SPPLLblProfiles->TextFont = "UT2SmallFont";
	SPPLLblProfiles->WinTop = 0.730417;
	SPPLLblProfiles->WinLeft = 0.264062;
	SPPLLblProfiles->WinWidth = 0.4;
	SPPLLblProfiles->WinHeight = 0.1;
	UGUIImage* symbolBack = NewObject<UGUIImage>(UGUIImage::StaticClass());
	symbolBack->ImageStyle = EImgStyle::ISTY_Stretched;
	symbolBack->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	symbolBack->WinTop = 0.265417;
	symbolBack->WinLeft = 0.015922;
	symbolBack->WinWidth = 0.149042;
	symbolBack->WinHeight = 0.273672;
	Difficulties = { "Novice","Average","Experienced","Skilled","Adept","Masterful","Inhuman","Godlike" };
	NumDifficulties = 8;
	DeleteMessage = "You are about to delete the profile for '%prof%'||Are you sure you want to delete this profile?";
	Controls = { btnNew,lboxProfile,moebPlayerName,moebTeamName,moebDifficulty,moebKills,moebDeaths,moebGoals,imagePlayerSkin,imageSkinBack,imageTeamSymbol,btnDelete,btnLoad,SPPLDataBox,SPPLImageBox,SPPLLblStats,SPPLLblProfiles,symbolBack,moebWins,moebMatches };
	WinTop = 0.15;
	WinHeight = 0.77;
}

void UTab_SPProfileLoad::InitComponent(UGUIController* pMyController, UGUIComponent* MyOwner)
{
	/*
	local GameProfile GP;
	Super::InitComponent(pMyController, MyOwner);
	butNew = GUIButton(Controls[0]);
	lbProfiles = GUIListBox(Controls[1]);
	lbProfiles.List.__OnDblClick__Delegate = DoubleClickList;
	ebPlayerName = moEditBox(Controls[2]);
	ebTeamName = moEditBox(Controls[3]);
	ebDifficulty = moEditBox(Controls[4]);
	ebKills = moEditBox(Controls[5]);
	ebDeaths = moEditBox(Controls[6]);
	ebGoals = moEditBox(Controls[7]);
	imgPlayerSkin = GUIImage(Controls[8]);
	imgTeamSymbol = GUIImage(Controls[10]);
	ebWins = moEditBox(Controls[18]);
	ebMatches = moEditBox(Controls[19]);
	GP = GetProfile();
	if (GP != None)
	{
		lbProfiles.List.Find(GP.PackageName);
		ProfileUpdated();
		if (LadderButton(GP.NextMatchObject) != None)
		{
			if (LadderButton(GP.NextMatchObject).LadderIndex > 0)
			{
				MyTabControl().ActivateTabByName(class'XInterface.UT2SinglePlayerMain'.Default.TabNameLadder, true);
			}
			else
			{
				MyTabControl().ActivateTabByName(class'XInterface.UT2SinglePlayerMain'.Default.TabNameQualification, true);
			}
		}
	}
	UpdateList();
	*/
}

void UTab_SPProfileLoad::InitPanel()
{
	/*
	Super::InitPanel();
	MyButton.Hint = class'XInterface.UT2SinglePlayerMain'.Default.TabHintProfileLoad;
	UT2SinglePlayerMain(MyButton.MenuOwner.MenuOwner).ResetTitleBar(MyButton);
	*/
}

void UTab_SPProfileLoad::OnProfileUpdated()
{
	UpdateList();
}

void UTab_SPProfileLoad::UpdateList()
{
	/*
	local TArray<FString> profilenames;
	int32 i = 0;
	local GameProfile GP;
	Controller.GetProfileList("", profilenames);
	lbProfiles.List.Clear();
	for (i = 0; i < profilenames.Length; i++)
	{
		lbProfiles.List.Add(profilenames[i]);
	}
	GP = GetProfile();
	if (GP != None)
	{
		lbProfiles.List.Find(GP.PackageName);
	}
	*/
	UpdateStats();
}

void UTab_SPProfileLoad::UpdateStats()
{
}

bool UTab_SPProfileLoad::LoadClick(UGUIComponent* Sender)
{
	/*
	local class<GameProfile>  profileclass;
	FString ProfileName = "";
	local GameProfile GP;
	ProfileName = lbProfiles.List.Get();
	profileclass = class<GameProfile>(DynamicLoadObject("xGame.UT2003GameProfile", Class'Class'));
	GP = PlayerOwner().Level.Game.LoadDataObject(profileclass, "GameProfile", ProfileName);
	if (GP != None)
	{
		PlayerOwner().Level.Game.CurrentGameProfile = GP;
		GP.Initialize(PlayerOwner().Level.Game, ProfileName);
		if (GP.ladderrung[1] >= 0)
		{
			MyTabControl().ActivateTabByName(class'XInterface.UT2SinglePlayerMain'.Default.TabNameLadder, true);
		}
		else
		{
			MyTabControl().ActivateTabByName(class'XInterface.UT2SinglePlayerMain'.Default.TabNameQualification, true);
		}
		ProfileUpdated();
	}
	*/
	return true;
}

void UTab_SPProfileLoad::DeleteConfirm(uint8 bButton)
{
	/*
	FString ProfileName = "";
	if (bButton == 16)
	{
		ProfileName = lbProfiles.List.Get();
		if ((GetProfile() != None) && (GetProfile().PackageName == ProfileName))
		{
			PlayerOwner().Level.Game.CurrentGameProfile = None;
		}
		if (!PlayerOwner().Level.Game.DeletePackage(ProfileName))
		{
			Log("SINGLEPLAYER Tab_SPProfileLoad::ButtonClick() failed to delete GameProfile " $ ProfileName);
		}
		ProfileUpdated();
		UpdateList();
	}
	*/
}

bool UTab_SPProfileLoad::DeleteClick(UGUIComponent* Sender)
{
	/*
	local GUIQuestionPage page;
	FString ProfileName = "";
	if (Controller.OpenMenu("XInterface.GUIQuestionPage"))
	{
		ProfileName = lbProfiles.List.Get();
		page = GUIQuestionPage(Controller.TopPage());
		page.SetupQuestion(page.Replace(DeleteMessage, "prof", Caps(ProfileName)), 48, 32);
		page.__OnButtonClick__Delegate = DeleteConfirm;
	}
	*/
	return true;
}

bool UTab_SPProfileLoad::NewProfileClick(UGUIComponent* Sender)
{
	//GUITabControl(MyButton.MenuOwner).ReplaceTab(MyButton, class'XInterface.UT2SinglePlayerMain'.Default.TabNameProfileNew, "xInterface.Tab_SPProfileNew", , , true);
	return true;
}

void UTab_SPProfileLoad::InternalOnChange(UGUIComponent* Sender)
{
	//UpdateStats();
}

bool UTab_SPProfileLoad::DoubleClickList(UGUIComponent* Sender)
{
	return LoadClick(Sender);
}

void UTab_SPProfileLoad::ShowPanel(bool bShow)
{
	/*
	Super::ShowPanel(bShow);
	if (bShow)
	{
		if (lbProfiles.List.ItemCount == 0)
		{
			UpdateStats();
			NewProfileClick(butNew);
			return;
		}
	}
	*/
}