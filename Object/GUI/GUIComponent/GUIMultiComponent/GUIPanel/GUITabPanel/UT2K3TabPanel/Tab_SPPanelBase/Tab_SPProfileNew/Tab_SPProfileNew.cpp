// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_SPPanelBase/Tab_SPProfileNew/Tab_SPProfileNew.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIEditBox/GUIEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUICircularList/GUICharacterList/GUICharacterListTeam/GUICharacterListTeam.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIGFXButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIComboBox/GUIComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImageList/GUIImageList.h"

UTab_SPProfileNew::UTab_SPProfileNew()
{
	UGUICharacterListTeam* clistPlayerSkins = NewObject<UGUICharacterListTeam>(UGUICharacterListTeam::StaticClass());
	clistPlayerSkins->FixedItemsPerPage = 1;
	clistPlayerSkins->StyleName = "CharButton";
	clistPlayerSkins->Hint = "Your character's appearance, use arrow keys to change";
	clistPlayerSkins->WinTop = 0.117917;
	clistPlayerSkins->WinLeft = 0.083462;
	clistPlayerSkins->WinWidth = 0.124694;
	clistPlayerSkins->WinHeight = 0.5;
	//clistPlayerSkins->OnClick=clistPlayerSkins.InternalOnClick;
	//clistPlayerSkins->OnRightClick=clistPlayerSkins.InternalOnRightClick;
	//clistPlayerSkins->OnMousePressed=clistPlayerSkins.InternalOnMousePressed;
	//clistPlayerSkins->OnMouseRelease=clistPlayerSkins.InternalOnMouseRelease;
	//clistPlayerSkins->OnKeyEvent=clistPlayerSkins.InternalOnKeyEvent;
	//clistPlayerSkins->OnBeginDrag=clistPlayerSkins.InternalOnBeginDrag;
	//clistPlayerSkins->OnEndDrag=clistPlayerSkins.InternalOnEndDrag;
	//clistPlayerSkins->OnDragDrop=clistPlayerSkins.InternalOnDragDrop;
	//clistPlayerSkins->OnDragEnter=clistPlayerSkins.InternalOnDragEnter;
	//clistPlayerSkins->OnDragLeave=clistPlayerSkins.InternalOnDragLeave;
	//clistPlayerSkins->OnDragOver=clistPlayerSkins.InternalOnDragOver;
	UGUIEditBox* ebTeamEdit = NewObject<UGUIEditBox>(UGUIEditBox::StaticClass());
	ebTeamEdit->TextStr = "TeamName";
	ebTeamEdit->AllowedCharSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	//ebTeamEdit->OnActivate=ebTeamEdit.InternalActivate;
	//ebTeamEdit->OnDeActivate=ebTeamEdit.InternalDeactivate;
	//ebTeamEdit->OnKeyType=ebTeamEdit.InternalOnKeyType;
	//ebTeamEdit->OnKeyEvent=ebTeamEdit.InternalOnKeyEvent;
	UGUIEditBox* ebNameEdit = NewObject<UGUIEditBox>(UGUIEditBox::StaticClass());
	ebNameEdit->TextStr = "PlayerName";
	ebNameEdit->AllowedCharSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	//ebNameEdit->OnActivate=ebNameEdit.InternalActivate;
	//ebNameEdit->OnDeActivate=ebNameEdit.InternalDeactivate;
	//ebNameEdit->OnKeyType=ebNameEdit.InternalOnKeyType;
	//ebNameEdit->OnKeyEvent=ebNameEdit.InternalOnKeyEvent;
	UGUIGFXButton* btnNextSymbol = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	btnNextSymbol->Position = EIconPosition::ICP_Scaled;
	btnNextSymbol->Hint = "Selects a new symbol for your team";
	btnNextSymbol->WinTop = 0.64;
	btnNextSymbol->WinLeft = 0.389375;
	btnNextSymbol->WinWidth = 0.08;
	btnNextSymbol->WinHeight = 0.08;
	btnNextSymbol->bNeverFocus = true;
	//btnNextSymbol->OnClick=Tab_SPProfileNew.NextSymbol;
	//btnNextSymbol->OnKeyEvent=btnNextSymbol.InternalOnKeyEvent;
	UGUIGFXButton* btnPrevSymbol = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	btnPrevSymbol->Position = EIconPosition::ICP_Scaled;
	btnPrevSymbol->Hint = "Selects a new symbol for your team";
	btnPrevSymbol->WinTop = 0.64;
	btnPrevSymbol->WinLeft = 0.29875;
	btnPrevSymbol->WinWidth = 0.08;
	btnPrevSymbol->WinHeight = 0.08;
	btnPrevSymbol->bNeverFocus = true;
	//btnPrevSymbol->OnClick=Tab_SPProfileNew.PrevSymbol;
	//btnPrevSymbol->OnKeyEvent=btnPrevSymbol.InternalOnKeyEvent;
	UGUIGFXButton* btnNextSkin = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	btnNextSkin->Position = EIconPosition::ICP_Scaled;
	btnNextSkin->Hint = "Selects a new appearance for your character";
	btnNextSkin->WinTop = 0.64;
	btnNextSkin->WinLeft = 0.172187;
	btnNextSkin->WinWidth = 0.08;
	btnNextSkin->WinHeight = 0.08;
	btnNextSkin->bNeverFocus = true;
	//btnNextSkin->OnClick=Tab_SPProfileNew.NextSkin;
	//btnNextSkin->OnKeyEvent=btnNextSkin.InternalOnKeyEvent;
	UGUIGFXButton* btnPrevSkin = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	btnPrevSkin->Position = EIconPosition::ICP_Scaled;
	btnPrevSkin->Hint = "Selects a new appearance for your character";
	btnPrevSkin->WinTop = 0.64;
	btnPrevSkin->WinLeft = 0.08;
	btnPrevSkin->WinWidth = 0.08;
	btnPrevSkin->WinHeight = 0.08;
	btnPrevSkin->bNeverFocus = true;
	//btnPrevSkin->OnClick=Tab_SPProfileNew.PrevSkin;
	//btnPrevSkin->OnKeyEvent=btnPrevSkin.InternalOnKeyEvent;
	UGUIButton* btnSaveProfile = NewObject<UGUIButton>(UGUIButton::StaticClass());
	btnSaveProfile->Caption = "CREATE PROFILE";
	btnSaveProfile->Hint = "Create a profile with these settings";
	btnSaveProfile->WinTop = 0.925;
	btnSaveProfile->WinLeft = 0.74406;
	btnSaveProfile->WinWidth = 0.223438;
	btnSaveProfile->WinHeight = 0.075;
	//btnSaveProfile->OnClick=Tab_SPProfileNew.CreateClick;
	//btnSaveProfile->OnKeyEvent=btnSaveProfile.InternalOnKeyEvent;
	UGUIButton* btnDefaults = NewObject<UGUIButton>(UGUIButton::StaticClass());
	btnDefaults->Caption = "SET TO DEFAULTS";
	btnDefaults->Hint = "Set this profile back to default values";
	btnDefaults->WinTop = 0.925;
	btnDefaults->WinLeft = 0.3675;
	btnDefaults->WinWidth = 0.232813;
	btnDefaults->WinHeight = 0.075;
	//btnDefaults->OnClick=Tab_SPProfileNew.DefaultsClick;
	//btnDefaults->OnKeyEvent=btnDefaults.InternalOnKeyEvent;
	UGUIButton* btnBack = NewObject<UGUIButton>(UGUIButton::StaticClass());
	btnBack->Caption = "BACK";
	btnBack->Hint = "Return to previous menu";
	btnBack->WinTop = 0.925;
	btnBack->WinLeft = 0.028125;
	btnBack->WinWidth = 0.2;
	btnBack->WinHeight = 0.075;
	//btnBack->OnClick=Tab_SPProfileNew.BackClick;
	//btnBack->OnKeyEvent=btnBack.InternalOnKeyEvent;
	UmoComboBox* mocbDifficulty = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	mocbDifficulty->bVerticalLayout = true;
	mocbDifficulty->Caption = "Difficulty: ";
	mocbDifficulty->LabelFont = "UT2SmallFont";
	mocbDifficulty->LabelColor = FColor(255, 255, 255, 255);
	//mocbDifficulty->MyComponent = GUIComboBox'XInterface.Tab_SPProfileNew.cbDifficulty';
	//mocbDifficulty->OnCreateComponent=mocbDifficulty.InternalOnCreateComponent;
	mocbDifficulty->Hint = "Customize your challenge";
	mocbDifficulty->WinTop = 0.568803;
	mocbDifficulty->WinLeft = 0.553125;
	mocbDifficulty->WinWidth = 0.345;
	mocbDifficulty->WinHeight = 0.1225;
	UGUIComboBox* cbDifficulty = NewObject<UGUIComboBox>(UGUIComboBox::StaticClass());
	cbDifficulty->bReadOnly = true;
	//cbDifficulty->OnKeyEvent=cbDifficulty.InternalOnKeyEvent;
	UmoEditBox* moebTeamName = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	moebTeamName->bVerticalLayout = true;
	moebTeamName->Caption = "Team Name: ";
	moebTeamName->LabelFont = "UT2SmallFont";
	moebTeamName->LabelColor = FColor(255, 255, 255, 255);
	//moebTeamName->MyComponent = GUIEditBox'XInterface.Tab_SPProfileNew.ebTeamEdit';
	//moebTeamName->OnCreateComponent=moebTeamName.InternalOnCreateComponent;
	moebTeamName->Hint = "The name of your team";
	moebTeamName->WinTop = 0.428007;
	moebTeamName->WinLeft = 0.553125;
	moebTeamName->WinWidth = 0.345;
	moebTeamName->WinHeight = 0.1225;
	UmoEditBox* moebPlayerName = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	moebPlayerName->bVerticalLayout = true;
	moebPlayerName->Caption = "Player Name: ";
	moebPlayerName->LabelFont = "UT2SmallFont";
	moebPlayerName->LabelColor = FColor(255, 255, 255, 255);
	//moebPlayerName->MyComponent = GUIEditBox'XInterface.Tab_SPProfileNew.ebNameEdit';
	//moebPlayerName->OnCreateComponent=moebPlayerName.InternalOnCreateComponent;
	moebPlayerName->Hint = "Your character's name";
	moebPlayerName->WinTop = 0.286087;
	moebPlayerName->WinLeft = 0.553125;
	moebPlayerName->WinWidth = 0.345;
	moebPlayerName->WinHeight = 0.1225;
	UGUIImage* imgEditsBack = NewObject<UGUIImage>(UGUIImage::StaticClass());
	imgEditsBack->ImageStyle = EImgStyle::ISTY_Stretched;
	imgEditsBack->WinTop = 0.073;
	imgEditsBack->WinLeft = 0.504375;
	imgEditsBack->WinWidth = 0.444304;
	imgEditsBack->WinHeight = 0.77;
	imgEditsBack->bNeverFocus = true;
	UGUIImageList* ilTeamSymbols = NewObject<UGUIImageList>(UGUIImageList::StaticClass());
	ilTeamSymbols->bWrap = true;
	ilTeamSymbols->ImageStyle = EImgStyle::ISTY_Justified;
	ilTeamSymbols->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	ilTeamSymbols->ImageAlign = EImgAlign::IMGA_Center;
	ilTeamSymbols->Hint = "Your team's symbol; use arrow keys to change";
	ilTeamSymbols->WinTop = 0.137175;
	ilTeamSymbols->WinLeft = 0.303972;
	ilTeamSymbols->WinWidth = 0.167212;
	ilTeamSymbols->WinHeight = 0.5;
	UGUIImage* imgSkinsBack = NewObject<UGUIImage>(UGUIImage::StaticClass());
	imgSkinsBack->ImageStyle = EImgStyle::ISTY_Stretched;
	imgSkinsBack->WinTop = 0.073;
	imgSkinsBack->WinLeft = 0.055938;
	imgSkinsBack->WinWidth = 0.215;
	imgSkinsBack->WinHeight = 0.77;
	imgSkinsBack->bNeverFocus = true;
	UGUIImage* imgSymbolsBack = NewObject<UGUIImage>(UGUIImage::StaticClass());
	imgSymbolsBack->ImageStyle = EImgStyle::ISTY_Stretched;
	imgSymbolsBack->WinTop = 0.073;
	imgSymbolsBack->WinLeft = 0.280243;
	imgSymbolsBack->WinWidth = 0.215;
	imgSymbolsBack->WinHeight = 0.77;
	imgSymbolsBack->bNeverFocus = true;
	UGUILabel* lblTeamSymbol = NewObject<UGUILabel>(UGUILabel::StaticClass());
	lblTeamSymbol->Caption = "Select|Team Symbol";
	lblTeamSymbol->TextAlign = ETextAlign::TXTA_Center;
	lblTeamSymbol->TextColor = FColor(255, 255, 255, 255);
	lblTeamSymbol->TextFont = "UT2SmallFont";
	lblTeamSymbol->bMultiLine = true;
	lblTeamSymbol->WinTop = 0.724583;
	lblTeamSymbol->WinLeft = 0.284375;
	lblTeamSymbol->WinWidth = 0.2;
	lblTeamSymbol->WinHeight = 0.1;
	UGUILabel* lblCharacter = NewObject<UGUILabel>(UGUILabel::StaticClass());
	lblCharacter->Caption = "Select|Character";
	lblCharacter->TextAlign = ETextAlign::TXTA_Center;
	lblCharacter->TextColor = FColor(255, 255, 255, 255);
	lblCharacter->TextFont = "UT2SmallFont";
	lblCharacter->bMultiLine = true;
	lblCharacter->WinTop = 0.724583;
	lblCharacter->WinLeft = 0.064062;
	lblCharacter->WinWidth = 0.2;
	lblCharacter->WinHeight = 0.1;
	UGUIImage* portraitBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	portraitBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	portraitBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	portraitBackground->WinTop = 0.110469;
	portraitBackground->WinLeft = 0.094141;
	portraitBackground->WinWidth = 0.14668;
	portraitBackground->WinHeight = 0.506094;
	portraitBackground->bVisible = false;
	UGUIImage* symbolBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	symbolBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	symbolBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	symbolBackground->WinTop = 0.237865;
	symbolBackground->WinLeft = 0.296196;
	symbolBackground->WinWidth = 0.179101;
	symbolBackground->WinHeight = 0.297265;
	DefaultName = "Player";
	DefaultTeamName = "Team";
	DefaultCharacter = "Gorge";
	TeamSymbolPrefix = "TeamSymbols_UT2003.sym";
	DefaultTeamSymbol = 1;
	Err_ProfileExists = "Profile with name %prof% already exists!";
	Err_CantCreateProfile = "Profile creation failed.";
	Controls = { btnSaveProfile,imgEditsBack,moebPlayerName,moebTeamName,mocbDifficulty,imgSkinsBack,clistPlayerSkins,btnPrevSkin,btnNextSkin,imgSymbolsBack,ilTeamSymbols,btnPrevSymbol,btnNextSymbol,btnBack,btnDefaults,lblCharacter,lblTeamSymbol,symbolBackground,portraitBackground };
	WinTop = 0.15;
	WinHeight = 0.77;
}

//const MINSYMBOL = 1;
//const MAXSYMBOL = 22;

void UTab_SPProfileNew::InitComponent(UGUIController* pMyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	ePlayerName = GUIEditBox(GUIMenuOption(Controls[2]).MyComponent);
	ePlayerName.MaxWidth = 16;
	ePlayerName.bConvertSpaces = true;
	ePlayerName.__OnClick__Delegate = PlayerOnClick;
	eTeamName = GUIEditBox(GUIMenuOption(Controls[3]).MyComponent);
	eTeamName.MaxWidth = 16;
	eTeamName.__OnClick__Delegate = PlayerOnClick;
	cDifficulty = GUIComboBox(GUIMenuOption(Controls[4]).MyComponent);
	clPlayerSkins = GUICharacterListTeam(Controls[6]);
	iTeamSymbols = GUIImageList(Controls[10]);
	Super::InitComponent(pMyController, MyOwner);
	if (!class'XInterface.Tab_PlayerSettings'.Default.bUnlocked)
	{
		clPlayerSkins.InitListExclusive("UNLOCK", "DUP");
	}
	else
	{
		clPlayerSkins.InitListExclusive("DUP");
	}
	Controls[5].FocusInstead = clPlayerSkins;
	Controls[7].FocusInstead = clPlayerSkins;
	Controls[8].FocusInstead = clPlayerSkins;
	Controls[9].FocusInstead = iTeamSymbols;
	Controls[11].FocusInstead = iTeamSymbols;
	Controls[12].FocusInstead = iTeamSymbols;
	for (i = 0; i<class'XInterface.Tab_SPProfileLoad'.Default.NumDifficulties; i++)
	{
		cDifficulty.addItem(class'XInterface.Tab_SPProfileLoad'.Default.Difficulties[i]);
	}
	cDifficulty.ReadOnly(true);
	LoadSymbols();
	ClearStats();
	*/
}

void UTab_SPProfileNew::InitPanel()
{
	/*
	Super::InitPanel();
	MyButton.Hint = class'XInterface.UT2SinglePlayerMain'.Default.TabHintProfileNew;
	UT2SinglePlayerMain(MyButton.MenuOwner.MenuOwner).ChangeHint(MyButton.Hint);
	UT2SinglePlayerMain(MyButton.MenuOwner.MenuOwner).ResetTitleBar(MyButton);
	*/
}

bool UTab_SPProfileNew::PlayerOnClick(UGUIComponent* Sender)
{
	/*
	if (Sender == ePlayerName)
	{
		if (ePlayerName.TextStr == DefaultName)
		{
			ePlayerName.TextStr = "";
		}
	}
	else
	{
		if (Sender == eTeamName)
		{
			if (eTeamName.TextStr == DefaultTeamName)
			{
				eTeamName.TextStr = "";
			}
		}
	}
	return OnClick(Sender);
	*/
	return false;     //FAKE   /ELiZ
}

FString UTab_SPProfileNew::GetTeamSymbolName(int32 idx)
{
	//return TeamSymbolPrefix $ Right("0" $ string(idx), 2);
	return "FAKE";     //FAKE   /ELiZ
}

FString UTab_SPProfileNew::CurrentTeamSymbolName()
{
	//return string(iTeamSymbols.Image);
	return "FAKE";     //FAKE   /ELiZ
}

void UTab_SPProfileNew::LoadSymbols()
{
	/*
	int32 i = 0;
	local Material M;
	local TArray<FString> SymbolNames;
	Controller.GetTeamSymbolList(SymbolNames, true);
	for (i = 0; i < SymbolNames.Length; i++)
	{
		M = Material(DynamicLoadObject(SymbolNames[i], Class'Material'));
		iTeamSymbols.AddMaterial(string(i), M);
	}
	*/
}

void UTab_SPProfileNew::ClearStats()
{
	/*
	ePlayerName.TextStr = DefaultName;
	eTeamName.TextStr = DefaultTeamName;
	cDifficulty.SetText(class'XInterface.Tab_SPProfileLoad'.Default.Difficulties[1]);
	clPlayerSkins.Find(DefaultCharacter);
	iTeamSymbols.FirstImage();
	*/
}

bool UTab_SPProfileNew::CreateClick(UGUIComponent* Sender)
{
	/*
	local class<GameProfile>  profileclass;
	FString ProfileName = "";
	local GameProfile GP;
	local GUIQuestionPage page;
	local TArray<FString> profilenames;
	int32 i = 0;
	bool bFileExists = false;
	if (ePlayerName.TextStr == "")
	{
		ePlayerName.TextStr = DefaultName;
	}
	if (eTeamName.TextStr == "")
	{
		eTeamName.TextStr = DefaultTeamName;
	}
	ProfileName = ePlayerName.TextStr;
	profileclass = class<GameProfile>(DynamicLoadObject("xGame.UT2003GameProfile", Class'Class'));
	GP = PlayerOwner().Level.Game.LoadDataObject(profileclass, "GameProfile", ProfileName);
	if (GP != None)
	{
		GP = nullptr;
		bFileExists = false;
		Controller.GetProfileList("", profilenames);
		i = 0;
		if (i < profilenames.Length)
		{
			if (profilenames[i] ~= ProfileName)
			{
				bFileExists = true;
			}
			else
			{
				i++;
			}
		}
		if (bFileExists)
		{
			if (Controller.OpenMenu("XInterface.GUIQuestionPage"))
			{
				page = GUIQuestionPage(Controller.ActivePage);
				page.SetupQuestion(page.Replace(Err_ProfileExists, "prof", Caps(ProfileName)), 1, 1);
			}
			return true;
		}
	}
	GP = PlayerOwner().Level.Game.CreateDataObject(profileclass, "GameProfile", ProfileName);
	if (GP != None)
	{
		GP.PlayerName = ePlayerName.TextStr;
		GP.TeamName = eTeamName.TextStr;
		GP.TeamSymbolName = string(iTeamSymbols.Image);
		GP.PlayerCharacter = clPlayerSkins.GetName();
		GP.BaseDifficulty = float(cDifficulty.Index);
		PlayerOwner().Level.Game.CurrentGameProfile = GP;
		GP.Initialize(PlayerOwner().Level.Game, ProfileName);
		PlayerOwner().Level.Game.CurrentGameProfile.bInLadderGame = true;
		if (!PlayerOwner().Level.Game.SavePackage(ProfileName))
		{
			Log("SINGLEPLAYER couldn't save profile package!");
		}
		GUITabControl(MyButton.MenuOwner).ReplaceTab(MyButton, class'XInterface.UT2SinglePlayerMain'.Default.TabNameProfileLoad, "xInterface.Tab_SPProfileLoad", , , true);
		GUITabControl(MyButton.MenuOwner).ActivateTabByName(class'XInterface.UT2SinglePlayerMain'.Default.TabNameQualification, true);
		ProfileUpdated();
		PlayerOwner().ConsoleCommand("START ut2-intro.ut2?quickstart=true?TeamScreen=False?savegame=" $ ProfileName);
		Controller.CloseAll(false);
	}
	else
	{
		if (Controller.OpenMenu("XInterface.GUIQuestionPage"))
		{
			page = GUIQuestionPage(Controller.ActivePage);
			page.SetupQuestion(Err_CantCreateProfile, 1, 1);
		}
		return true;
	}
	*/
	return true;
}

bool UTab_SPProfileNew::PrevSkin(UGUIComponent* Sender)
{
	//clPlayerSkins.ScrollLeft();
	return true;
}

bool UTab_SPProfileNew::NextSkin(UGUIComponent* Sender)
{
	//clPlayerSkins.ScrollRight();
	return true;
}

bool UTab_SPProfileNew::PrevSymbol(UGUIComponent* Sender)
{
	//iTeamSymbols.PrevImage();
	return true;
}

bool UTab_SPProfileNew::NextSymbol(UGUIComponent* Sender)
{
	//iTeamSymbols.NextImage();
	return true;
}

bool UTab_SPProfileNew::BackClick(UGUIComponent* Sender)
{
	/*
	local TArray<FString> profilenames;
	Controller.GetProfileList("", profilenames);
	if (profilenames.Length == 0)
	{
		Controller.CloseMenu();
	}
	GUITabControl(MyButton.MenuOwner).ReplaceTab(MyButton, class'XInterface.UT2SinglePlayerMain'.Default.TabNameProfileLoad, "xInterface.Tab_SPProfileLoad", , , true);
	*/
	return true;
}

bool UTab_SPProfileNew::DefaultsClick(UGUIComponent* Sender)
{
	//ClearStats();
	return true;
}