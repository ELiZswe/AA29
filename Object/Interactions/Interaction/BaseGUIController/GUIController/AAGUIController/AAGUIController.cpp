// All the original content belonged to the US Army

#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/AAGUIController/AAGUIController.h"
#include "AA29/Object/GUI/GUIFont/AAFontMenu/AAFontMenu.h"
#include "AA29/Object/GUI/GUIFont/AAFontDefault/AAFontDefault.h"
#include "AA29/Object/GUI/GUIFont/AAFontLarge/AAFontLarge.h"
#include "AA29/Object/GUI/GUIFont/AAFontHeader/AAFontHeader.h"
#include "AA29/Object/GUI/GUIFont/AAFontSmall/AAFontSmall.h"
#include "AA29/Object/GUI/GUIFont/AAFontMidGame/AAFontMidGame.h"
#include "AA29/Object/GUI/GUIFont/AAFontSmallHeader/AAFontSmallHeader.h"
#include "AA29/Object/GUI/GUIFont/AAFontServerList/AAFontServerList.h"
#include "AA29/Object/GUI/GUIFont/AAFontIRC/AAFontIRC.h"
#include "AA29/Object/GUI/GUIFont/AAFontEntryPageButton/AAFontEntryPageButton.h"
#include "AA29/Object/GUI/GUIFont/AAFontMainMenuButton/AAFontMainMenuButton.h"
#include "AA29/Object/GUI/GUIFont/AAFontMainMenu/AAFontMainMenu.h"
#include "AA29/Object/GUI/GUIFont/AAFontMedium/AAFontMedium.h"
#include "AA29/Object/GUI/GUIFont/AAFontButton/AAFontButton.h"
#include "AA29/Object/GUI/GUIFont/AAFontLabel/AAFontLabel.h"
#include "AA29/Object/GUI/GUIFont/AAFontPanelButton/AAFontPanelButton.h"
#include "AA29/Object/GUI/GUIFont/NMLFontSmallHeader/NMLFontSmallHeader.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/HttpLink/HttpLink.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/FloatingWindow.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/GUIPage.h"
#include "AA29/Object/Interactions/Interaction/Interaction.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AADeploymentDetailsSubPanel/AADeploy_Details_UserCreated/AADeploy_Details_UserCreated.h"
#include "AA29/Object/GUI/GUIStyles/GUIStyles.h"
#include "AA29/Object/HttpLinkItem/HttpLinkItem.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAGameMenu/AAGameMenu.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAMainMenu/AAMainMenu.h"

UAAGUIController::UAAGUIController()
{
	UAAFontMenu* GUIAAFontMenu = NewObject<UAAFontMenu>(UAAFontMenu::StaticClass());
	UAAFontDefault* GUIAAFontDefault = NewObject<UAAFontDefault>(UAAFontDefault::StaticClass());
	UAAFontLarge* GUIAAFontLarge = NewObject<UAAFontLarge>(UAAFontLarge::StaticClass());
	UAAFontHeader* GUIAAFontHeader = NewObject<UAAFontHeader>(UAAFontHeader::StaticClass());
	UAAFontSmall* GUIAAFontSmall = NewObject<UAAFontSmall>(UAAFontSmall::StaticClass());
	UAAFontMidGame* GUIAAFontMidGame = NewObject<UAAFontMidGame>(UAAFontMidGame::StaticClass());
	UAAFontSmallHeader* GUIAAFontSmallHeader = NewObject<UAAFontSmallHeader>(UAAFontSmallHeader::StaticClass());
	UAAFontServerList* GUIAAFontServerList = NewObject<UAAFontServerList>(UAAFontServerList::StaticClass());
	UAAFontIRC* GUIAAFontIRC = NewObject<UAAFontIRC>(UAAFontIRC::StaticClass());
	UAAFontEntryPageButton* GUIAAFontEntryPageButton = NewObject<UAAFontEntryPageButton>(UAAFontEntryPageButton::StaticClass());
	UAAFontMainMenuButton* GUIAAFontMainMenuButton = NewObject<UAAFontMainMenuButton>(UAAFontMainMenuButton::StaticClass());
	UAAFontMainMenu* GUIAAFontMainMenu = NewObject<UAAFontMainMenu>(UAAFontMainMenu::StaticClass());
	UAAFontMedium* GUIAAFontMedium = NewObject<UAAFontMedium>(UAAFontMedium::StaticClass());
	UAAFontButton* GUIAAFontButton = NewObject<UAAFontButton>(UAAFontButton::StaticClass());
	UAAFontLabel* GUIAAFontLabel = NewObject<UAAFontLabel>(UAAFontLabel::StaticClass());
	UAAFontPanelButton* GUIAAFontPanelButton = NewObject<UAAFontPanelButton>(UAAFontPanelButton::StaticClass());
	UNMLFontSmallHeader* GUINMLFontSmallHeader = NewObject<UNMLFontSmallHeader>(UNMLFontSmallHeader::StaticClass());

	MainMenuPanelOptions= {"RECORD BRIEF","TRAINING","DEPLOYMENT","REAL HEROES","INSTANT ACTION","WEAPON MODS","AA BROWSER","SETTINGS","SUPPORT"};
	Server = "dms1.americasarmy.com";
	Port = 80;
	FONT_NUM = 17;
	STYLE_NUM = 110;
	CURSOR_NUM = 8;
	FontStack.SetNum(17);
	FontStack[0] = GUIAAFontMenu;
	FontStack[1] = GUIAAFontDefault;
	FontStack[2] = GUIAAFontLarge;
	FontStack[3] = GUIAAFontHeader;
	FontStack[4] = GUIAAFontSmall;
	FontStack[5] = GUIAAFontMidGame;
	FontStack[6] = GUIAAFontSmallHeader;
	FontStack[7] = GUIAAFontServerList;
	FontStack[8] = GUIAAFontIRC;
	FontStack[9] = GUIAAFontEntryPageButton;
	FontStack[10] = GUIAAFontMainMenuButton;
	FontStack[11] = GUIAAFontMainMenu;
	FontStack[12] = GUIAAFontMedium;
	FontStack[13] = GUIAAFontButton;
	FontStack[14] = GUIAAFontLabel;
	FontStack[15] = GUIAAFontPanelButton;
	FontStack[16] = GUINMLFontSmallHeader;
	
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
	ImageList(0) = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_check_selected_Mat.box_check_selected_Mat'"), NULL, LOAD_None, NULL)
	ImageList(1) = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/slider_bar_Mat.slider_bar_Mat'"), NULL, LOAD_None, NULL)
	ImageList(2) = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_arrow_left_Mat.scroll_arrow_left_Mat'"), NULL, LOAD_None, NULL)
	ImageList(3) = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_arrow_right_Mat.scroll_arrow_right_Mat'"), NULL, LOAD_None, NULL)
	ImageList(4) = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_check_plus_Mat.box_check_plus_Mat'"), NULL, LOAD_None, NULL)
	ImageList(5) = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_check_minus_Mat.box_check_minus_Mat'"), NULL, LOAD_None, NULL)
	ImageList(6) = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_arrow_up_Mat.scroll_arrow_up_Mat'"), NULL, LOAD_None, NULL)
	ImageList(7) = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_arrow_down_Mat.scroll_arrow_down_Mat'"), NULL, LOAD_None, NULL);
	*/

	DefaultStyleNames.SetNum(110);
	DefaultStyleNames[0] = "AGP_Interface.STY_AARoundButton";
	DefaultStyleNames[1] = "AGP_Interface.STY_AARoundScaledButton";
	DefaultStyleNames[2] = "AGP_Interface.STY_AASquareButton";
	DefaultStyleNames[3] = "AGP_Interface.STY_AAListBox";
	DefaultStyleNames[4] = "AGP_Interface.STY_AAScrollZone";
	DefaultStyleNames[5] = "AGP_Interface.STY_AATextButton";
	DefaultStyleNames[6] = "AGP_Interface.STY_AAPage";
	DefaultStyleNames[7] = "AGP_Interface.STY_AAHeader";
	DefaultStyleNames[8] = "AGP_Interface.STY_AAFooter";
	DefaultStyleNames[9] = "AGP_Interface.STY_AATabButton";
	DefaultStyleNames[10] = "AGP_Interface.STY_AACharButton";
	DefaultStyleNames[11] = "AGP_Interface.STY_AAArrowLeft";
	DefaultStyleNames[12] = "AGP_Interface.STY_AAArrowRight";
	DefaultStyleNames[13] = "AGP_Interface.STY_AAServerBrowserGrid";
	DefaultStyleNames[14] = "AGP_Interface.STY_AANoBackground";
	DefaultStyleNames[15] = "AGP_Interface.STY_AAServerBrowserGridHeader";
	DefaultStyleNames[16] = "AGP_Interface.STY_AASliderCaption";
	DefaultStyleNames[17] = "AGP_Interface.STY_AABindBox";
	DefaultStyleNames[18] = "AGP_Interface.STY_AASquareBar";
	DefaultStyleNames[19] = "AGP_Interface.STY_AAMidGameButton";
	DefaultStyleNames[20] = "AGP_Interface.STY_AATextLabel";
	DefaultStyleNames[21] = "AGP_Interface.STY_AAComboListBox";
	DefaultStyleNames[22] = "AGP_Interface.STY_AASquareMenuButton";
	DefaultStyleNames[23] = "AGP_Interface.STY_AAIRCText";
	DefaultStyleNames[24] = "AGP_Interface.STY_AAIRCEntry";
	DefaultStyleNames[25] = "AGP_Interface.STY_AABrowserButton";
	DefaultStyleNames[26] = "AGP_Interface.STY_AAContextMenu";
	DefaultStyleNames[27] = "AGP_Interface.STY_AAServerListContextMenu";
	DefaultStyleNames[28] = "AGP_Interface.STY_AAListSelection";
	DefaultStyleNames[29] = "AGP_Interface.STY_AATabBackground";
	DefaultStyleNames[30] = "AGP_Interface.STY_AABrowserListSel";
	DefaultStyleNames[31] = "AGP_Interface.STY_AAEditBox";
	DefaultStyleNames[32] = "AGP_Interface.STY_AACheckBox";
	DefaultStyleNames[33] = "AGP_Interface.STY_AACheckBoxCheck";
	DefaultStyleNames[34] = "AGP_Interface.STY_AASliderKnob";
	DefaultStyleNames[35] = "AGP_Interface.STY_AABottomTabButton";
	DefaultStyleNames[36] = "AGP_Interface.STY_AAListSection";
	DefaultStyleNames[37] = "AGP_Interface.STY_AAItemOutline";
	DefaultStyleNames[38] = "AGP_Interface.STY_AAListHighlight";
	DefaultStyleNames[39] = "AGP_Interface.STY_AAMouseOver";
	DefaultStyleNames[40] = "AGP_Interface.STY_AASliderBar";
	DefaultStyleNames[41] = "AGP_Interface.STY_AADarkTextLabel";
	DefaultStyleNames[42] = "AGP_Interface.STY_AATextButtonEffect";
	DefaultStyleNames[43] = "AGP_Interface.STY_AAArrowRightDbl";
	DefaultStyleNames[44] = "AGP_Interface.STY_AAArrowLeftDbl";
	DefaultStyleNames[45] = "AGP_Interface.STY_AAFooterButton";
	DefaultStyleNames[46] = "AGP_Interface.STY_AASectionHeaderText";
	DefaultStyleNames[47] = "AGP_Interface.STY_AAComboButton";
	DefaultStyleNames[48] = "AGP_Interface.STY_AAVertUpButton";
	DefaultStyleNames[49] = "AGP_Interface.STY_AAVertDownButton";
	DefaultStyleNames[50] = "AGP_Interface.STY_AAVertGrip";
	DefaultStyleNames[51] = "AGP_Interface.STY_AASpinner";
	DefaultStyleNames[52] = "AGP_Interface.STY_AASectionHeaderTop";
	DefaultStyleNames[53] = "AGP_Interface.STY_AASectionHeaderBar";
	DefaultStyleNames[54] = "AGP_Interface.STY_AACloseButton";
	DefaultStyleNames[55] = "AGP_Interface.STY_AACoolScroll";
	DefaultStyleNames[56] = "AGP_Interface.STY_AAAltComboButton";
	DefaultStyleNames[57] = "AGP_Interface.STY_AAEntryButton";
	DefaultStyleNames[58] = "AGP_Interface.STY_AAMainMenuButton";
	DefaultStyleNames[59] = "AGP_Interface.STY_AAMainMenuLabel";
	DefaultStyleNames[60] = "AGP_Interface.STY_AAGameMenuButton";
	DefaultStyleNames[61] = "AGP_Interface.STY_AASubMenuButton";
	DefaultStyleNames[62] = "AGP_Interface.STY_AAScoreboardHeader";
	DefaultStyleNames[63] = "AGP_Interface.STY_AAUnitBox";
	DefaultStyleNames[64] = "AGP_Interface.STY_AAWeaponModButton";
	DefaultStyleNames[65] = "AGP_Interface.STY_AASmallText";
	DefaultStyleNames[66] = "AGP_Interface.STY_AAMediumText";
	DefaultStyleNames[67] = "AGP_Interface.STY_AALargeText";
	DefaultStyleNames[68] = "AGP_Interface.STY_AAHintBox";
	DefaultStyleNames[69] = "AGP_Interface.STY_AABackBox";
	DefaultStyleNames[70] = "AGP_Interface.STY_AASlider";
	DefaultStyleNames[71] = "AGP_Interface.STY_AASliderBack";
	DefaultStyleNames[72] = "AGP_Interface.STY_AAControlSelector";
	DefaultStyleNames[73] = "AGP_Interface.STY_AAControlsBox";
	DefaultStyleNames[74] = "AGP_Interface.STY_AALinkButton";
	DefaultStyleNames[75] = "AGP_Interface.STY_AALightTextLabel";
	DefaultStyleNames[76] = "AGP_Interface.STY_AAVertTabButton";
	DefaultStyleNames[77] = "AGP_Interface.STY_AARadioButton";
	DefaultStyleNames[78] = "AGP_Interface.STY_AAButton";
	DefaultStyleNames[79] = "AGP_Interface.STY_AAButtonSelected";
	DefaultStyleNames[80] = "AGP_Interface.STY_AAImageBorder";
	DefaultStyleNames[81] = "AGP_Interface.STY_AAImageBorderSelected";
	DefaultStyleNames[82] = "AGP_Interface.STY_AAListEntry";
	DefaultStyleNames[83] = "AGP_Interface.STY_AASupportLabelText";
	DefaultStyleNames[84] = "AGP_Interface.STY_AAScoreboardUnitText";
	DefaultStyleNames[85] = "AGP_Interface.STY_AARosterUnitText";
	DefaultStyleNames[86] = "AGP_Interface.STY_AAMoviePlayerButtonPlay";
	DefaultStyleNames[87] = "AGP_Interface.STY_AAMoviePlayerButtonPause";
	DefaultStyleNames[88] = "AGP_Interface.STY_AAMoviePlayerButtonStop";
	DefaultStyleNames[89] = "AGP_Interface.STY_AAMoviePlayerButtonRewind";
	DefaultStyleNames[90] = "AGP_Interface.STY_AAMoviePlayerButtonForward";
	DefaultStyleNames[91] = "AGP_Interface.STY_AAMoviePlayerButtonClose";
	DefaultStyleNames[92] = "AGP_Interface.STY_AAMoviePlayer_Scrubber";
	DefaultStyleNames[93] = "AGP_Interface.STY_AAMoviePlayer_ScrubberKnob";
	DefaultStyleNames[94] = "AGP_Interface.STY_AAMoviePlayer_Volume";
	DefaultStyleNames[95] = "AGP_Interface.STY_AAMoviePlayer_VolumeKnob";
	DefaultStyleNames[96] = "AGP_Interface.STY_AAGUITreeListItem";
	DefaultStyleNames[97] = "AGP_Interface.STY_AAGUITreeListCategory";
	DefaultStyleNames[98] = "AGP_Interface.STY_AAGUITreeListSelected";
	DefaultStyleNames[99] = "AGP_Interface.STY_AANMLPanel";
	DefaultStyleNames[100] = "AGP_Interface.STY_AABrowserListFavorite";
	DefaultStyleNames[101] = "AGP_Interface.STY_NMLMediumText";
	DefaultStyleNames[102] = "AGP_Interface.STY_NMLGrayText";
	DefaultStyleNames[103] = "AGP_Interface.STY_NMLHeader";
	DefaultStyleNames[104] = "AGP_Interface.STY_AATreeAndExclusiveList";
	DefaultStyleNames[105] = "AGP_Interface.STY_NMLSmallText";
	DefaultStyleNames[106] = "AGP_Interface.STY_NMLIndentText";
	DefaultStyleNames[107] = "AGP_Interface.STY_NMLCaptionText";
	DefaultStyleNames[108] = "AGP_Interface.STY_NMLTinyText";
	DefaultStyleNames[109] = "AGP_Interface.STY_AAEyeCatcherSquareButton";

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
	CloseAll(true,false);
	if (MenuStack.Num() == 0)
	{
		OpenMenu(GetMainMenuClass(),"","");
	}
}

bool UAAGUIController::SetFocusTo(UFloatingWindow* Menu)
{
	int32 i = 0;
	if (ActivePage == Menu)
	{
		return true;
	}
	for (i = 0; i < MenuStack.Num(); i++)
	{
		if (Cast<UFloatingWindow>(MenuStack[i]) == nullptr)
		{
		}
		if (MenuStack[i] == Menu)
		{
			if (i + 1 < MenuStack.Num())
			{
				MenuStack[i + 1]->ParentPage = Menu->ParentPage;
				//Menu->ParentPage = MenuStack[MenuStack.Num() - 1];
			}
			MenuStack[MenuStack.Num()] = Menu;
			MenuStack.RemoveAt(i, 1);
			ActivePage = Menu;
			return true;
		}
	}
	return false;
}

void UAAGUIController::ReceivedToursText(FString Filename, FString TextChunk)
{
	UAADeploy_Details_UserCreated* aadduc = nullptr;
	int32 BufferHead = 0;
	FString Buffer = "";
	/*
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
		ForceUnloadFile(GetBaseDir() + "tours.ini");
		if (ViewportOwner.Actor.Level != nullptr)
		{
			ViewportOwner.Actor.Level.LoadTourInfo();
		}
		ForEach('AADeploy_Details_UserCreated', aadduc)
		{
		}
		if (aadduc != nullptr)
		{
			aadduc.PopulateComboBox();
		}
	}
	bReceivedNewTours = true;
	*/
}

void UAAGUIController::InitializeController()
{
	int32 i = 0;
	UGUIStyles* NewStyleClass = nullptr;
	UGUIPage* NewMenu = nullptr;
	AActor* SpawningActor = nullptr;
	UHttpLinkItem* RequestedItem = nullptr;
	/*
	PrecachePlayerRecords();
	if (GlobalNMLQueue == nullptr)
	{
		ForEach(Class'Actor', SpawningActor)
		{
		}
		if (SpawningActor != nullptr)
		{
			GlobalNMLQueue = SpawningActor.Spawn(AHttpLink::StaticClass());
		}
	}
	if (GlobalNMLQueue != nullptr)
	{
		GlobalNMLQueue.SetHost(Server, Port);
		GlobalNMLQueue.SetLocalFilePath(".");
		RequestedItem = GlobalNMLQueue.RequestText("/tours.ini");
		RequestedItem.__OnReceivedText__Delegate = ReceivedToursText;
	}
	for (i = 0; i < DefaultStyleNames.Num(); i++)
	{
		NewStyleClass = class<GUIStyles>(DynamicLoadObject(DefaultStyleNames[i], Class'Class'));
		if (NewStyleClass != nullptr)
		{
			if (!RegisterStyle(NewStyleClass))
			{
				Log("Could not create requested style" @ DefaultStyleNames[i]);
			}
		}
	}
	for (i = 0; i < StyleNames.Num(); i++)
	{
		NewStyleClass = class<GUIStyles>(DynamicLoadObject(StyleNames[i], Class'Class'));
		if (NewStyleClass != nullptr)
		{
			if (!RegisterStyle(NewStyleClass))
			{
				Log("Could not create requested style" @ StyleNames[i]);
			}
		}
	}
	for (i = 0; i < FontStack.Num(); i++)
	{
		FontStack[i].Controller = this;
	}
	NewMenu = CreateMenu("AGP_Interface.AAMainMenu");
	if (NewMenu != nullptr)
	{
		NewMenu.InitComponent(this, nullptr);
	}
	*/
}

void UAAGUIController::PrecachePlayerRecords()
{
}

UGUIPage* UAAGUIController::CreateMenu(FString NewMenuName)
{
	UGUIPage* NewMenuClass = nullptr;
	UGUIPage* NewMenu = nullptr;
	int32 i = 0;
	if (NewMenuName.Compare("AGP_Interface.AAMainMenu",ESearchCase::IgnoreCase))
	{
		NewMenuName = GetMainMenuClass();
	}
	if (NewMenuName.Compare("AGP_Interface.AAEntryPage",ESearchCase::IgnoreCase))
	{
		for (i = 0; i < MenuStack.Num(); i++)
		{
			if (MenuStack[i]->IsA(UAAMainMenu::StaticClass()))
			{
				return nullptr;
			}
		}
	}
	if (NewMenuName.Compare("AGP_Interface.AAGameMenu",ESearchCase::IgnoreCase))
	{
		if (MenuStack.Num() > 0)
		{
			for (i = 0; i < MenuStack.Num(); i++)
			{
				if (MenuStack[i]->IsA(UAAGameMenu::StaticClass()))
				{
					return nullptr;
				}
			}
			CloseAll(true,false);
		}
	}
	/*
	NewMenuClass = class<GUIPage>(AddComponentClass(NewMenuName));
	if (NewMenuClass != nullptr)
	{	
		if (NewMenuClass.Default.bPersistent)
		{
			i = 0;
			if (i < PersistentStack.Num())
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
		if (NewMenu == nullptr)
		{
			NewMenu = new (nullptr) classNewMenuClass;
			if (NewMenu == nullptr)
			{
				Log("Could not create requested menu" @ NewMenuName);
				return nullptr;
			}
			else
			{
				if (NewMenuClass.Default.bPersistent)
				{
					i = PersistentStack.Num();
					PersistentStack.Num() = (i + 1);
					PersistentStack[i] = NewMenu;
				}
			}
		}
		bCurMenuInitialized = false;
		return NewMenu;
	}
	Log("Could not DLO menu '" + NewMenuName + "'");
	*/
	return nullptr;
}

bool UAAGUIController::OpenMenu(FString NewMenuName, FString Param1, FString Param2)
{
	UGUIPage* NewMenu = nullptr;
	/*
	if (bModAuthor)
	{
		Log(Class @ "OpenMenu [" + NewMenuName + "] (" + Param1 + ") (" + Param2 + ")", 'ModAuthor');
	}
	if (ActivePage != nullptr)
	{
		if (!ActivePage.AllowOpen(NewMenuName))
		{
			return false;
		}
	}
	if (!bCurMenuInitialized && MenuStack.Num() > 0)
	{
		if (bModAuthor)
		{
			Log("Cannot open menu until menu initialization is complete!", 'ModAuthor');
		}
		return false;
	}
	NewMenu = CreateMenu(NewMenuName);
	if (NewMenu != nullptr)
	{
		if (FindMenuIndex(NewMenu) != -1)
		{
			NewMenu.HandleParameters(Param1, Param2);
			bCurMenuInitialized = true;
			return false;
		}
		NewMenu.ParentPage = ActivePage;
		ResetFocus();
		PushMenu(MenuStack.Num(), NewMenu, Param1, Param2);
		if (NewMenu.bDisconnectOnOpen)
		{
			ConsoleCommand("DISCONNECT");
		}
		ConsoleCommand("consoleclose");
		return true;
	}
	Log("Could not open menu" @ NewMenuName);
	return false;
	*/

	return false;   //FAKE  /ELiZ
}

void UAAGUIController::Validate()
{
	if (GetDefault<UAAGUIController>()->MainMenuOptions.Num() < 8)
	{
		//ResetConfig();
	}
}

FString UAAGUIController::GetEntryPage()
{
	Validate();
	return GetDefault<UAAGUIController>()->MainMenuOptions[0];
}

FString UAAGUIController::GetLoginPage()
{
	Validate();
	return GetDefault<UAAGUIController>()->MainMenuOptions[1];
}

FString UAAGUIController::GetPreLoginPage()
{
	Validate();
	return GetDefault<UAAGUIController>()->MainMenuOptions[2];
}

FString UAAGUIController::GetPostLoginPage()
{
	Validate();
	return GetDefault<UAAGUIController>()->MainMenuOptions[3];
}

FString UAAGUIController::GetMainMenuPage()
{
	Validate();
	return GetDefault<UAAGUIController>()->MainMenuOptions[4];
}

FString UAAGUIController::GetQuitPage()
{
	Validate();
	return GetDefault<UAAGUIController>()->MainMenuOptions[5];
}

FString UAAGUIController::GetExitPage()
{
	Validate();
	return GetDefault<UAAGUIController>()->MainMenuOptions[6];
}

FString UAAGUIController::GetLogoutPage()
{
	Validate();
	return GetDefault<UAAGUIController>()->MainMenuOptions[7];
}

UGUIComponent* UAAGUIController::AddComponentClass(FString ClassName)
{
	int32 i = 0;
	UGUIComponent* Cls = nullptr;
	/*
	for (i = 0; i < RegisteredClasses.Num(); i++)
	{
		if (RegisteredClasses[i] ~= ClassName)
		{
			return RegisteredClasses[i];
		}
	}
	Cls = class<GUIComponent>(DynamicLoadObject(ClassName, Class'Class'));
	if (Cls != nullptr)
	{
		RegisteredClasses[RegisteredClasses.Num()] = Cls;
	}
	*/
	return Cls;
}

void UAAGUIController::PurgeComponentClasses()
{
	/*
	if (RegisteredClasses.Num() > 0)
	{
		RegisteredClasses.RemoveAt(0, RegisteredClasses.Num());
	}
	PurgeComponentClasses();
	*/
}

void UAAGUIController::ValidatePanels()
{
	if (GetDefault<UAAGUIController>()->MainMenuPanelOptions.Num() < 9)
	{
		//ResetConfig();
	}
}

FString UAAGUIController::GetPersonnelJacketPanel()
{
	Validate();
	return GetDefault<UAAGUIController>()->MainMenuPanelOptions[0];
}

FString UAAGUIController::GetRecordBriefPanel()
{
	Validate();
	return GetDefault<UAAGUIController>()->MainMenuPanelOptions[0];
}

FString UAAGUIController::GetTrainingPanel()
{
	Validate();
	return GetDefault<UAAGUIController>()->MainMenuPanelOptions[1];
}

FString UAAGUIController::GetDeploymentPanel()
{
	Validate();
	return GetDefault<UAAGUIController>()->MainMenuPanelOptions[2];
}

FString UAAGUIController::GetMultiplayerPanel()
{
	Validate();
	return GetDefault<UAAGUIController>()->MainMenuPanelOptions[2];
}

FString UAAGUIController::GetServerBrowserPanel()
{
	Validate();
	return GetDefault<UAAGUIController>()->MainMenuPanelOptions[6];
}

FString UAAGUIController::GetRealHeroesPanel()
{
	Validate();
	return GetDefault<UAAGUIController>()->MainMenuPanelOptions[3];
}

FString UAAGUIController::GetExplorePanel()
{
	Validate();
	return GetDefault<UAAGUIController>()->MainMenuPanelOptions[4];
}

FString UAAGUIController::GetWeaponsPanel()
{
	Validate();
	return GetDefault<UAAGUIController>()->MainMenuPanelOptions[5];
}

FString UAAGUIController::GetSettingsPanel()
{
	Validate();
	return GetDefault<UAAGUIController>()->MainMenuPanelOptions[7];
}

FString UAAGUIController::GetSupportPanel()
{
	Validate();
	return GetDefault<UAAGUIController>()->MainMenuPanelOptions[8];
}

FString UAAGUIController::GetParentalControlsPanel()
{
	Validate();
	return GetDefault<UAAGUIController>()->MainMenuPanelOptions[7];
}

FString UAAGUIController::GetCreditsPanel()
{
	Validate();
	return GetDefault<UAAGUIController>()->MainMenuPanelOptions[6];
}

FString UAAGUIController::GetExitPanel()
{
	Validate();
	return GetDefault<UAAGUIController>()->MainMenuPanelOptions[8];
}

FString UAAGUIController::GetQuitPanel()
{
	Validate();
	return GetDefault<UAAGUIController>()->MainMenuPanelOptions[8];
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
	if (DisplayURL != "")
	{
		//OpenMenu("AGP_Interface.AAExternalLinkPage", RealURL + URLDivider() + DisplayURL, Description);
	}
	else
	{
		//OpenMenu("AGP_Interface.AAExternalLinkPage", RealURL, Description);
	}
}

void UAAGUIController::ReplaceExternalLink(FString RealURL, FString Description, FString DisplayURL)
{
	if (DisplayURL != "")
	{
		//ReplaceMenu("AGP_Interface.AAExternalLinkPage", RealURL + URLDivider() + DisplayURL, Description);
	}
	else
	{
		//ReplaceMenu("AGP_Interface.AAExternalLinkPage", RealURL, Description);
	}
}

void UAAGUIController::InteractionChanged(UInteraction* Changed, bool bOpen)
{
	/*
	if (Changed->IsA(UConsole::StaticClass()))
	{
		if (bOpen)
		{
			if (bActive)
			{
				bWaitForConsole = true;
				EnableMenus(false);
			}
		}
		else
		{
			if (bWaitForConsole)
			{
				EnableMenus(true);
				bWaitForConsole = false;
			}
		}
	}
	*/
}

FString UAAGUIController::LoadTextFromFile(FString Filename)
{
	FString Line = "";
	FString S = "";
	/*
	if (FOpen(Filename))
	{
		if (FReadLine(Line))
		{
			S = S + "|" + Line;
		}
		FClose();
	}
	else
	{
		S = "Could not load file|" + Filename;
	}
	*/
	return S;
}

void UAAGUIController::NotifyDCDSDownload(FString AssetName)
{
	//OpenMenu("AGP_Interface.AAGameMenu_DCDS_Begin", , AssetName);
}

void UAAGUIController::NotifyLevelChange()
{
	/*
	int32 i = 0;
	for (i = PersistentStack.Num() - 1; i >= 0; i--)
	{
		if (!PersistentStack[i].bPersistent || PersistentStack[i].Class == 'AAGameMenu')
		{
			PersistentStack.RemoveAt(i, 1);
		}
	}
	NotifyLevelChange();
	*/
}
