// All the original content belonged to the US Army


#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/AAGUIController/AAGUIController.h"



UAAGUIController::UAAGUIController()
{
	MainMenuPanelOptions= {"RECORD BRIEF","TRAINING","DEPLOYMENT","REAL HEROES","INSTANT ACTION","WEAPON MODS","AA BROWSER","SETTINGS","SUPPORT"};
	Server = "dms1.americasarmy.com";
	Port = 80;
	FONT_NUM = 17;
	STYLE_NUM = 110;
	CURSOR_NUM = 8;
	/*
	FontStack(0) = AAFontMenu'AGP_Interface.AAGUIController.GUIAAFontMenu'
	FontStack(1) = AAFontDefault'AGP_Interface.AAGUIController.GUIAAFontDefault'
	FontStack(2) = AAFontLarge'AGP_Interface.AAGUIController.GUIAAFontLarge'
	FontStack(3) = AAFontHeader'AGP_Interface.AAGUIController.GUIAAFontHeader'
	FontStack(4) = AAFontSmall'AGP_Interface.AAGUIController.GUIAAFontSmall'
	FontStack(5) = AAFontMidGame'AGP_Interface.AAGUIController.GUIAAFontMidGame'
	FontStack(6) = AAFontSmallHeader'AGP_Interface.AAGUIController.GUIAAFontSmallHeader'
	FontStack(7) = AAFontServerList'AGP_Interface.AAGUIController.GUIAAFontServerList'
	FontStack(8) = AAFontIRC'AGP_Interface.AAGUIController.GUIAAFontIRC'
	FontStack(9) = AAFontEntryPageButton'AGP_Interface.AAGUIController.GUIAAFontEntryPageButton'
	FontStack(10) = AAFontMainMenuButton'AGP_Interface.AAGUIController.GUIAAFontMainMenuButton'
	FontStack(11) = AAFontMainMenu'AGP_Interface.AAGUIController.GUIAAFontMainMenu'
	FontStack(12) = AAFontMedium'AGP_Interface.AAGUIController.GUIAAFontMedium'
	FontStack(13) = AAFontButton'AGP_Interface.AAGUIController.GUIAAFontButton'
	FontStack(14) = AAFontLabel'AGP_Interface.AAGUIController.GUIAAFontLabel'
	FontStack(15) = AAFontPanelButton'AGP_Interface.AAGUIController.GUIAAFontPanelButton'
	FontStack(16) = NMLFontSmallHeader'AGP_Interface.AAGUIController.GUINMLFontSmallHeader'
	*/
	MouseCursors =
	{
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/cursor_Mat.cursor_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/sizer_all_Mat.sizer_all_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/sizer_NESW_Mat.sizer_NESW_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/sizer_vertical_Mat.sizer_vertical_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/sizer_NWSE_Mat.sizer_NWSE_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/sizer_horiz_Mat.sizer_horiz_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/busy_Mat.busy_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/link_Mat.link_Mat'"), NULL, LOAD_None, NULL)
	};
	
	/*
	ImageList(0) = Texture'T_AA2_UI.Menu.box_check_selected'
	ImageList(1) = Texture'T_AA2_UI.Menu.slider_bar'
	ImageList(2) = Texture'T_AA2_UI.Menu.scroll_arrow_left'
	ImageList(3) = Texture'T_AA2_UI.Menu.scroll_arrow_right'
	ImageList(4) = Texture'T_AA2_UI.Menu.box_check_plus'
	ImageList(5) = Texture'T_AA2_UI.Menu.box_check_minus'
	ImageList(6) = Texture'T_AA2_UI.Menu.scroll_arrow_up'
	ImageList(7) = Texture'T_AA2_UI.Menu.scroll_arrow_down'
	*/
	/*
	DefaultStyleNames(0) = "AGP_Interface.STY_AARoundButton"
	DefaultStyleNames(1) = "AGP_Interface.STY_AARoundScaledButton"
	DefaultStyleNames(2) = "AGP_Interface.STY_AASquareButton"
	DefaultStyleNames(3) = "AGP_Interface.STY_AAListBox"
	DefaultStyleNames(4) = "AGP_Interface.STY_AAScrollZone"
	DefaultStyleNames(5) = "AGP_Interface.STY_AATextButton"
	DefaultStyleNames(6) = "AGP_Interface.STY_AAPage"
	DefaultStyleNames(7) = "AGP_Interface.STY_AAHeader"
	DefaultStyleNames(8) = "AGP_Interface.STY_AAFooter"
	DefaultStyleNames(9) = "AGP_Interface.STY_AATabButton"
	DefaultStyleNames(10) = "AGP_Interface.STY_AACharButton"
	DefaultStyleNames(11) = "AGP_Interface.STY_AAArrowLeft"
	DefaultStyleNames(12) = "AGP_Interface.STY_AAArrowRight"
	DefaultStyleNames(13) = "AGP_Interface.STY_AAServerBrowserGrid"
	DefaultStyleNames(14) = "AGP_Interface.STY_AANoBackground"
	DefaultStyleNames(15) = "AGP_Interface.STY_AAServerBrowserGridHeader"
	DefaultStyleNames(16) = "AGP_Interface.STY_AASliderCaption"
	DefaultStyleNames(17) = "AGP_Interface.STY_AABindBox"
	DefaultStyleNames(18) = "AGP_Interface.STY_AASquareBar"
	DefaultStyleNames(19) = "AGP_Interface.STY_AAMidGameButton"
	DefaultStyleNames(20) = "AGP_Interface.STY_AATextLabel"
	DefaultStyleNames(21) = "AGP_Interface.STY_AAComboListBox"
	DefaultStyleNames(22) = "AGP_Interface.STY_AASquareMenuButton"
	DefaultStyleNames(23) = "AGP_Interface.STY_AAIRCText"
	DefaultStyleNames(24) = "AGP_Interface.STY_AAIRCEntry"
	DefaultStyleNames(25) = "AGP_Interface.STY_AABrowserButton"
	DefaultStyleNames(26) = "AGP_Interface.STY_AAContextMenu"
	DefaultStyleNames(27) = "AGP_Interface.STY_AAServerListContextMenu"
	DefaultStyleNames(28) = "AGP_Interface.STY_AAListSelection"
	DefaultStyleNames(29) = "AGP_Interface.STY_AATabBackground"
	DefaultStyleNames(30) = "AGP_Interface.STY_AABrowserListSel"
	DefaultStyleNames(31) = "AGP_Interface.STY_AAEditBox"
	DefaultStyleNames(32) = "AGP_Interface.STY_AACheckBox"
	DefaultStyleNames(33) = "AGP_Interface.STY_AACheckBoxCheck"
	DefaultStyleNames(34) = "AGP_Interface.STY_AASliderKnob"
	DefaultStyleNames(35) = "AGP_Interface.STY_AABottomTabButton"
	DefaultStyleNames(36) = "AGP_Interface.STY_AAListSection"
	DefaultStyleNames(37) = "AGP_Interface.STY_AAItemOutline"
	DefaultStyleNames(38) = "AGP_Interface.STY_AAListHighlight"
	DefaultStyleNames(39) = "AGP_Interface.STY_AAMouseOver"
	DefaultStyleNames(40) = "AGP_Interface.STY_AASliderBar"
	DefaultStyleNames(41) = "AGP_Interface.STY_AADarkTextLabel"
	DefaultStyleNames(42) = "AGP_Interface.STY_AATextButtonEffect"
	DefaultStyleNames(43) = "AGP_Interface.STY_AAArrowRightDbl"
	DefaultStyleNames(44) = "AGP_Interface.STY_AAArrowLeftDbl"
	DefaultStyleNames(45) = "AGP_Interface.STY_AAFooterButton"
	DefaultStyleNames(46) = "AGP_Interface.STY_AASectionHeaderText"
	DefaultStyleNames(47) = "AGP_Interface.STY_AAComboButton"
	DefaultStyleNames(48) = "AGP_Interface.STY_AAVertUpButton"
	DefaultStyleNames(49) = "AGP_Interface.STY_AAVertDownButton"
	DefaultStyleNames(50) = "AGP_Interface.STY_AAVertGrip"
	DefaultStyleNames(51) = "AGP_Interface.STY_AASpinner"
	DefaultStyleNames(52) = "AGP_Interface.STY_AASectionHeaderTop"
	DefaultStyleNames(53) = "AGP_Interface.STY_AASectionHeaderBar"
	DefaultStyleNames(54) = "AGP_Interface.STY_AACloseButton"
	DefaultStyleNames(55) = "AGP_Interface.STY_AACoolScroll"
	DefaultStyleNames(56) = "AGP_Interface.STY_AAAltComboButton"
	DefaultStyleNames(57) = "AGP_Interface.STY_AAEntryButton"
	DefaultStyleNames(58) = "AGP_Interface.STY_AAMainMenuButton"
	DefaultStyleNames(59) = "AGP_Interface.STY_AAMainMenuLabel"
	DefaultStyleNames(60) = "AGP_Interface.STY_AAGameMenuButton"
	DefaultStyleNames(61) = "AGP_Interface.STY_AASubMenuButton"
	DefaultStyleNames(62) = "AGP_Interface.STY_AAScoreboardHeader"
	DefaultStyleNames(63) = "AGP_Interface.STY_AAUnitBox"
	DefaultStyleNames(64) = "AGP_Interface.STY_AAWeaponModButton"
	DefaultStyleNames(65) = "AGP_Interface.STY_AASmallText"
	DefaultStyleNames(66) = "AGP_Interface.STY_AAMediumText"
	DefaultStyleNames(67) = "AGP_Interface.STY_AALargeText"
	DefaultStyleNames(68) = "AGP_Interface.STY_AAHintBox"
	DefaultStyleNames(69) = "AGP_Interface.STY_AABackBox"
	DefaultStyleNames(70) = "AGP_Interface.STY_AASlider"
	DefaultStyleNames(71) = "AGP_Interface.STY_AASliderBack"
	DefaultStyleNames(72) = "AGP_Interface.STY_AAControlSelector"
	DefaultStyleNames(73) = "AGP_Interface.STY_AAControlsBox"
	DefaultStyleNames(74) = "AGP_Interface.STY_AALinkButton"
	DefaultStyleNames(75) = "AGP_Interface.STY_AALightTextLabel"
	DefaultStyleNames(76) = "AGP_Interface.STY_AAVertTabButton"
	DefaultStyleNames(77) = "AGP_Interface.STY_AARadioButton"
	DefaultStyleNames(78) = "AGP_Interface.STY_AAButton"
	DefaultStyleNames(79) = "AGP_Interface.STY_AAButtonSelected"
	DefaultStyleNames(80) = "AGP_Interface.STY_AAImageBorder"
	DefaultStyleNames(81) = "AGP_Interface.STY_AAImageBorderSelected"
	DefaultStyleNames(82) = "AGP_Interface.STY_AAListEntry"
	DefaultStyleNames(83) = "AGP_Interface.STY_AASupportLabelText"
	DefaultStyleNames(84) = "AGP_Interface.STY_AAScoreboardUnitText"
	DefaultStyleNames(85) = "AGP_Interface.STY_AARosterUnitText"
	DefaultStyleNames(86) = "AGP_Interface.STY_AAMoviePlayerButtonPlay"
	DefaultStyleNames(87) = "AGP_Interface.STY_AAMoviePlayerButtonPause"
	DefaultStyleNames(88) = "AGP_Interface.STY_AAMoviePlayerButtonStop"
	DefaultStyleNames(89) = "AGP_Interface.STY_AAMoviePlayerButtonRewind"
	DefaultStyleNames(90) = "AGP_Interface.STY_AAMoviePlayerButtonForward"
	DefaultStyleNames(91) = "AGP_Interface.STY_AAMoviePlayerButtonClose"
	DefaultStyleNames(92) = "AGP_Interface.STY_AAMoviePlayer_Scrubber"
	DefaultStyleNames(93) = "AGP_Interface.STY_AAMoviePlayer_ScrubberKnob"
	DefaultStyleNames(94) = "AGP_Interface.STY_AAMoviePlayer_Volume"
	DefaultStyleNames(95) = "AGP_Interface.STY_AAMoviePlayer_VolumeKnob"
	DefaultStyleNames(96) = "AGP_Interface.STY_AAGUITreeListItem"
	DefaultStyleNames(97) = "AGP_Interface.STY_AAGUITreeListCategory"
	DefaultStyleNames(98) = "AGP_Interface.STY_AAGUITreeListSelected"
	DefaultStyleNames(99) = "AGP_Interface.STY_AANMLPanel"
	DefaultStyleNames(100) = "AGP_Interface.STY_AABrowserListFavorite"
	DefaultStyleNames(101) = "AGP_Interface.STY_NMLMediumText"
	DefaultStyleNames(102) = "AGP_Interface.STY_NMLGrayText"
	DefaultStyleNames(103) = "AGP_Interface.STY_NMLHeader"
	DefaultStyleNames(104) = "AGP_Interface.STY_AATreeAndExclusiveList"
	DefaultStyleNames(105) = "AGP_Interface.STY_NMLSmallText"
	DefaultStyleNames(106) = "AGP_Interface.STY_NMLIndentText"
	DefaultStyleNames(107) = "AGP_Interface.STY_NMLCaptionText"
	DefaultStyleNames(108) = "AGP_Interface.STY_NMLTinyText"
	DefaultStyleNames(109) = "AGP_Interface.STY_AAEyeCatcherSquareButton"
	*/

	ClickSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_UI/Generic/ClickDown_Cue.ClickDown_Cue'"), NULL, LOAD_None, NULL);
	WhiteBorder = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/AGP_Interface/Menu/T_UI_MENU_WhiteBorder_Mat.T_UI_MENU_WhiteBorder_Mat'"), NULL, LOAD_None, NULL);

	//RequestDataMenu = "AGP_Interface.AAGetDataMenu"
	//ArrayPropertyMenu = "AGP_Interface.GUIArrayPropPage"
	//DynArrayPropertyMenu = "AGP_Interface.GUIDynArrayPage"
	//FilterMenu = "AGP_Interface.AAFilterPage"
	//FilterMenuGamespy = "AGP_Interface.AAFilterPageGamespy"
	//EditFavoriteMenu = "AGP_Interface.EditFavoritePage"

	//MainMenuOptions(0) = "AGP_Interface.AAEntryPage"
	//MainMenuOptions(1) = "AGP_Interface.AALoginPage"
	//MainMenuOptions(2) = "AGP_Interface.AAPreLoginPage"
	//MainMenuOptions(3) = "AGP_Interface.AAPostLoginPage"
	//MainMenuOptions(4) = "AGP_Interface.AAMainMenu"
	//MainMenuOptions(5) = "AGP_Interface.AAQuitPage"
	//MainMenuOptions(6) = "AGP_Interface.AAExitPage"
	//MainMenuOptions(7) = "AGP_Interface.AALogoutPage"

	bFixedMouseSize = true;
	//NetworkMsgMenu = "AGP_Interface.AANetworkStatusMsg"
	//QuestionMenuClass = "AGP_Interface.AAQuestionPage"
}



//native Function LaunchURL(string URL);
void UAAGUIController::LaunchURL(FString URL)
{

}

void UAAGUIController::ReturnToMainMenu()
{
	/*
	CloseAll(True);
	if (MenuStack.Length == 0)
	{
		OpenMenu(GetMainMenuClass());
	}
	*/
}
/*
void UAAGUIController::SetFocusTo(FloatingWindow Menu)
{
	local int i;
	if (ActivePage == Menu)
	{
		Return True;
	}
	for (i = 0; i < MenuStack.Length; i++)
	{
		if (FloatingWindow(MenuStack[i]) == None)
		{
		}
		if (MenuStack[i] == Menu)
		{
			if (i + 1 < MenuStack.Length)
			{
				MenuStack[i + 1].ParentPage = Menu.ParentPage;
				Menu.ParentPage = MenuStack[MenuStack.Length - 1];
			}
			MenuStack[MenuStack.Length] = Menu;
			MenuStack.remove(i, 1);
			ActivePage = Menu;
			Return True;
		}
	}
	Return False;
}
*/
void UAAGUIController::ReceivedToursText(FString Filename, FString TextChunk)
{
	/*
	local AADeploy_Details_UserCreated aadduc;
	local int BufferHead;
	local string Buffer;
	if (FOpenWrite("tours.ini"))
	{
		BufferHead = 0;
		if (BufferHead <= Len(TextChunk))
		{
			Buffer = Mid(TextChunk, BufferHead, 768);
			FWrite(Buffer);
			BufferHead += 768;
		}
		FClose();
		ForceUnloadFile("tours.ini");
		ForceUnloadFile(GetBaseDir() $ "tours.ini");
		if (ViewportOwner.Actor.Level != None)
		{
			ViewportOwner.Actor.Level.LoadTourInfo();
		}
		ForEach('AADeploy_Details_UserCreated', aadduc)
		{
		}
		if (aadduc != None)
		{
			aadduc.PopulateComboBox();
		}
	}
	bReceivedNewTours = true;
	*/
}
void UAAGUIController::InitializeController()
{
	/*
	local int i;
	local class<XInterface.GUIStyles>  NewStyleClass;
	local XInterface.GUIPage NewMenu;
	local Actor SpawningActor;
	local IpDrv.HttpLinkItem RequestedItem;
	PrecachePlayerRecords();
	if (GlobalNMLQueue == None)
	{
		ForEach(Class'Actor', SpawningActor)
		{
		}
		if (SpawningActor != None)
		{
			GlobalNMLQueue = SpawningActor.Spawn(Class'HttpLink');
		}
	}
	if (GlobalNMLQueue != None)
	{
		GlobalNMLQueue.SetHost(Server, Port);
		GlobalNMLQueue.SetLocalFilePath(".");
		RequestedItem = GlobalNMLQueue.RequestText("/tours.ini");
		RequestedItem.__OnReceivedText__Delegate = ReceivedToursText;
	}
	for (i = 0; i < DefaultStyleNames.Length; i++)
	{
		NewStyleClass = class<GUIStyles>(DynamicLoadObject(DefaultStyleNames[i], Class'Class'));
		if (NewStyleClass != None)
		{
			if (!RegisterStyle(NewStyleClass))
			{
				Log("Could not create requested style" @ DefaultStyleNames[i]);
			}
		}
	}
	for (i = 0; i < StyleNames.Length; i++)
	{
		NewStyleClass = class<GUIStyles>(DynamicLoadObject(StyleNames[i], Class'Class'));
		if (NewStyleClass != None)
		{
			if (!RegisterStyle(NewStyleClass))
			{
				Log("Could not create requested style" @ StyleNames[i]);
			}
		}
	}
	for (i = 0; i < FontStack.Length; i++)
	{
		FontStack[i].Controller = Self;
	}
	NewMenu = CreateMenu("AGP_Interface.AAMainMenu");
	if (NewMenu != None)
	{
		NewMenu.InitComponent(Self, None);
	}
	*/
}
void UAAGUIController::PrecachePlayerRecords()
{
}
/*
UGUIPage* UAAGUIController::CreateMenu(FString NewMenuName)
{
	local class<XInterface.GUIPage>  NewMenuClass;
	local XInterface.GUIPage NewMenu;
	local int i;
	if (NewMenuName ~= "AGP_Interface.AAMainMenu")
	{
		NewMenuName = GetMainMenuClass();
	}
	if (NewMenuName ~= "AGP_Interface.AAEntryPage")
	{
		for (i = 0; i < MenuStack.Length; i++)
		{
			if (MenuStack[i].IsA('AAMainMenu'))
			{
				Return None;
			}
		}
	}
	if (NewMenuName ~= "AGP_Interface.AAGameMenu")
	{
		if (MenuStack.Length > 0)
		{
			for (i = 0; i < MenuStack.Length; i++)
			{
				if (MenuStack[i].IsA('AAGameMenu'))
				{
					Return None;
				}
			}
			CloseAll(True);
		}
	}
	NewMenuClass = class<GUIPage>(AddComponentClass(NewMenuName));
	if (NewMenuClass != None)
	{
		if (NewMenuClass.Default.bPersistent)
		{
			i = 0;
			if (i < PersistentStack.Length)
			{
				if (PersistentStack[i].Class == NewMenuClass)
				{
					NewMenu = PersistentStack[i];
				}
				else
				{
					i++;
				}
			}
		}
		if (NewMenu == None)
		{
			NewMenu = new (None) classNewMenuClass;
			if (NewMenu == None)
			{
				Log("Could not create requested menu" @ NewMenuName);
				Return None;
			}
			else
			{
				if (NewMenuClass.Default.bPersistent)
				{
					i = PersistentStack.Length;
					PersistentStack.Length = i + 1;
					PersistentStack[i] = NewMenu;
				}
			}
		}
		bCurMenuInitialized = False;
		Return NewMenu;
	}
	Log("Could not DLO menu '" $ NewMenuName $ "'");
	Return None;
}
*/
bool UAAGUIController::OpenMenu(FString NewMenuName, FString Param1, FString Param2)
{
	/*
	local XInterface.GUIPage NewMenu;
	if (bModAuthor)
	{
		Log(Class @ "OpenMenu [" $ NewMenuName $ "] (" $ Param1 $ ") (" $ Param2 $ ")", 'ModAuthor');
	}
	if (ActivePage != None)
	{
		if (!ActivePage.AllowOpen(NewMenuName))
		{
			Return False;
		}
	}
	if (!bCurMenuInitialized && MenuStack.Length > 0)
	{
		if (bModAuthor)
		{
			Log("Cannot open menu until menu initialization is complete!", 'ModAuthor');
		}
		Return False;
	}
	NewMenu = CreateMenu(NewMenuName);
	if (NewMenu != None)
	{
		if (FindMenuIndex(NewMenu) != -1)
		{
			NewMenu.HandleParameters(Param1, Param2);
			bCurMenuInitialized = true;
			Return False;
		}
		NewMenu.ParentPage = ActivePage;
		ResetFocus();
		PushMenu(MenuStack.Length, NewMenu, Param1, Param2);
		if (NewMenu.bDisconnectOnOpen)
		{
			ConsoleCommand("DISCONNECT");
		}
		ConsoleCommand("consoleclose");
		Return True;
	}
	Log("Could not open menu" @ NewMenuName);
	Return False;
	*/

	return false;   //FAKE  /ELiZ
}
void UAAGUIController::Validate()
{
	/*
	if (Default.MainMenuOptions.Length < 8)
	{
		ResetConfig();
	}
	*/
}
void UAAGUIController::GetEntryPage()
{
	/*
	Validate();
	Return Default.MainMenuOptions[0];
	*/
}
void UAAGUIController::GetLoginPage()
{
	/*
	Validate();
	Return Default.MainMenuOptions[1];
	*/
}
void UAAGUIController::GetPreLoginPage()
{
	/*
	Validate();
	Return Default.MainMenuOptions[2];
	*/
}
void UAAGUIController::GetPostLoginPage()
{
	/*
	Validate();
	Return Default.MainMenuOptions[3];
	*/
}
void UAAGUIController::GetMainMenuPage()
{
	/*
	Validate();
	Return Default.MainMenuOptions[4];
	*/
}
void UAAGUIController::GetQuitPage()
{
	/*
	Validate();
	Return Default.MainMenuOptions[5];
	*/
}
void UAAGUIController::GetExitPage()
{
	/*
	Validate();
	Return Default.MainMenuOptions[6];
	*/
}
void UAAGUIController::GetLogoutPage()
{
	/*
	Validate();
	Return Default.MainMenuOptions[7];
	*/
}
void UAAGUIController::AddComponentClass(FString ClassName)
{
	/*
	local int i;
	local class<UGUIComponent*>  Cls;
	for (i = 0; i < RegisteredClasses.Length; i++)
	{
		if (RegisteredClasses[i] ~= ClassName)
		{
			Return RegisteredClasses[i];
		}
	}
	Cls = class<GUIComponent>(DynamicLoadObject(ClassName, Class'Class'));
	if (Cls != None)
	{
		RegisteredClasses[RegisteredClasses.Length] = Cls;
	}
	Return Cls;
	*/
}
void UAAGUIController::PurgeComponentClasses()
{
	/*
	if (RegisteredClasses.Length > 0)
	{
		RegisteredClasses.remove(0, RegisteredClasses.Length);
	}
	PurgeComponentClasses();
	*/
}
void UAAGUIController::ValidatePanels()
{
	/*
	if (Default.MainMenuPanelOptions.Length < 9)
	{
		ResetConfig();
	}
	*/
}
void UAAGUIController::GetPersonnelJacketPanel()
{
	/*
	Validate();
	Return Default.MainMenuPanelOptions[0];
	*/
}
void UAAGUIController::GetRecordBriefPanel()
{
	/*
	Validate();
	Return Default.MainMenuPanelOptions[0];
	*/
}
void UAAGUIController::GetTrainingPanel()
{
	/*
	Validate();
	Return Default.MainMenuPanelOptions[1];
	*/
}
void UAAGUIController::GetDeploymentPanel()
{
	/*
	Validate();
	Return Default.MainMenuPanelOptions[2];
	*/
}
void UAAGUIController::GetMultiplayerPanel()
{
	/*
	Validate();
	Return Default.MainMenuPanelOptions[2];
	*/
}
void UAAGUIController::GetServerBrowserPanel()
{
	/*
	Validate();
	Return Default.MainMenuPanelOptions[6];
	*/
}
void UAAGUIController::GetRealHeroesPanel()
{
	/*
	Validate();
	Return Default.MainMenuPanelOptions[3];
	*/
}
void UAAGUIController::GetExplorePanel()
{
	/*
	Validate();
	Return Default.MainMenuPanelOptions[4];
	*/
}
void UAAGUIController::GetWeaponsPanel()
{
	/*
	Validate();
	Return Default.MainMenuPanelOptions[5];
	*/
}
void UAAGUIController::GetSettingsPanel()
{
	/*
	Validate();
	Return Default.MainMenuPanelOptions[7];
	*/
}
void UAAGUIController::GetSupportPanel()
{
	/*
	Validate();
	Return Default.MainMenuPanelOptions[8];
	*/
}
void UAAGUIController::GetParentalControlsPanel()
{
	/*
	Validate();
	Return Default.MainMenuPanelOptions[7];
	*/
}
void UAAGUIController::GetCreditsPanel()
{
	/*
	Validate();
	Return Default.MainMenuPanelOptions[6];
	*/
}
void UAAGUIController::GetExitPanel()
{
	/*
	Validate();
	Return Default.MainMenuPanelOptions[8];
	*/
}
void UAAGUIController::GetQuitPanel()
{
	/*
	Validate();
	Return Default.MainMenuPanelOptions[8];
	*/
}
bool UAAGUIController::LoggedIn()
{
	return true;
}
void UAAGUIController::EnableMenus(bool bEnable)
{
	bNativeEvents = bEnable;
}
FString UAAGUIController::URLDivider()
{
	return "!DIVIDER!";
}
void UAAGUIController::OpenExternalLink(FString RealURL, FString Description, FString DisplayURL)
{
	/*
	if (DisplayURL != "")
	{
		OpenMenu("AGP_Interface.AAExternalLinkPage", RealURL $ URLDivider() $ DisplayURL, Description);
	}
	else
	{
		OpenMenu("AGP_Interface.AAExternalLinkPage", RealURL, Description);
	}
	*/
}
void UAAGUIController::ReplaceExternalLink(FString RealURL, FString Description, FString DisplayURL)
{
	/*
	if (DisplayURL != "")
	{
		ReplaceMenu("AGP_Interface.AAExternalLinkPage", RealURL $ URLDivider() $ DisplayURL, Description);
	}
	else
	{
		ReplaceMenu("AGP_Interface.AAExternalLinkPage", RealURL, Description);
	}
	*/
}
void UAAGUIController::InteractionChanged(UInteraction* Changed, bool bOpen)
{
	/*
	if (Changed.IsA('Console'))
	{
		if (bOpen)
		{
			if (bActive)
			{
				bWaitForConsole = true;
				EnableMenus(False);
			}
		}
		else
		{
			if (bWaitForConsole)
			{
				EnableMenus(True);
				bWaitForConsole = False;
			}
		}
	}
	*/
}
void UAAGUIController::LoadTextFromFile(FString Filename)
{
	/*
	local string Line;
	local string S;
	if (FOpen(Filename))
	{
		if (FReadLine(Line))
		{
			S = S $ "|" $ Line;
		}
		FClose();
	}
	else
	{
		S = "Could not load file|" $ Filename;
	}
	Return S;
	*/
}
void UAAGUIController::NotifyDCDSDownload(FString AssetName)
{
	/*
	OpenMenu("AGP_Interface.AAGameMenu_DCDS_Begin", , AssetName);
	*/
}
void UAAGUIController::NotifyLevelChange()
{
	/*
	local int i;
	for (i = PersistentStack.Length - 1; i >= 0; i--)
	{
		if (!PersistentStack[i].bPersistent || PersistentStack[i].Class == 'AAGameMenu')
		{
			PersistentStack.remove(i, 1);
		}
	}
	NotifyLevelChange();
	*/
}
