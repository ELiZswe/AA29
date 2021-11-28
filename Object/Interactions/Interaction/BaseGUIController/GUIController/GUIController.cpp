// All the original content belonged to the US Army

#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIFont/UT2MenuFont/UT2MenuFont.h"
#include "AA29/Object/GUI/GUIFont/UT2DefaultFont/UT2DefaultFont.h"
#include "AA29/Object/GUI/GUIFont/UT2LargeFont/UT2LargeFont.h"
#include "AA29/Object/GUI/GUIFont/UT2HeaderFont/UT2HeaderFont.h"
#include "AA29/Object/GUI/GUIFont/UT2SmallFont/UT2SmallFont.h"
#include "AA29/Object/GUI/GUIFont/UT2MidGameFont/UT2MidGameFont.h"
#include "AA29/Object/GUI/GUIFont/UT2SmallHeaderFont/UT2SmallHeaderFont.h"
#include "AA29/Object/GUI/GUIFont/UT2ServerListFont/UT2ServerListFont.h"
#include "AA29/Object/GUI/GUIFont/UT2IRCFont/UT2IRCFont.h"

UGUIController::UGUIController()
{
	UUT2MenuFont* GUIMenuFont = NewObject<UUT2MenuFont>(UUT2MenuFont::StaticClass());
	UUT2DefaultFont* GUIDefaultFont = NewObject<UUT2DefaultFont>(UUT2DefaultFont::StaticClass());
	UUT2LargeFont* GUILargeFont = NewObject<UUT2LargeFont>(UUT2LargeFont::StaticClass());
	UUT2HeaderFont* GUIHeaderFont = NewObject<UUT2HeaderFont>(UUT2HeaderFont::StaticClass());
	UUT2SmallFont* GUISmallFont = NewObject<UUT2SmallFont>(UUT2SmallFont::StaticClass());
	UUT2MidGameFont* GUIMidGameFont = NewObject<UUT2MidGameFont>(UUT2MidGameFont::StaticClass());
	UUT2SmallHeaderFont* GUISmallHeaderFont = NewObject<UUT2SmallHeaderFont>(UUT2SmallHeaderFont::StaticClass());
	UUT2ServerListFont* GUIServerListFont = NewObject<UUT2ServerListFont>(UUT2ServerListFont::StaticClass());
	UUT2IRCFont* GUIIRCFont = NewObject<UUT2IRCFont>(UUT2IRCFont::StaticClass());
	FONT_NUM = 9;
	STYLE_NUM = 30;
	CURSOR_NUM = 7;
	
	MouseCursorOffset = { FVector(0, 0, 0),FVector(0.5, 0.5, 0),FVector(0.5, 0.5, 0),FVector(0.5, 0.5, 0),FVector(0.5, 0.5, 0),FVector(0.5, 0.5, 0),FVector(0, 0, 0) };
	FontStack = {
		GUIMenuFont,
		GUIDefaultFont,
		GUILargeFont,
		GUIHeaderFont,
		GUISmallFont,
		GUIMidGameFont,
		GUISmallHeaderFont,
		GUIServerListFont,
		GUIIRCFont
	};
	MouseCursors = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/MouseCursor_Mat.MouseCursor_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/SplitterCursor_Mat.SplitterCursor_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/SplitterCursor_Mat.SplitterCursor_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/SplitterCursorVert_Mat.SplitterCursorVert_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/SplitterCursor_Mat.SplitterCursor_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/SplitterCursor_Mat.SplitterCursor_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/MouseCursor_Mat.MouseCursor_Mat'"), NULL, LOAD_None, NULL)
	};
	DefaultStyleNames = {
		"XInterface.STY_RoundButton",
		"XInterface.STY_RoundScaledButton",
		"XInterface.STY_SquareButton",
		"XInterface.STY_ListBox",
		"XInterface.STY_ScrollZone",
		"XInterface.STY_TextButton",
		"XInterface.STY_Page",
		"XInterface.STY_Header",
		"XInterface.STY_Footer",
		"XInterface.STY_TabButton",
		"XInterface.STY_CharButton",
		"XInterface.STY_ArrowLeft",
		"XInterface.STY_ArrowRight",
		"XInterface.STY_ServerBrowserGrid",
		"XInterface.STY_NoBackground",
		"XInterface.STY_ServerBrowserGridHeader",
		"XInterface.STY_SliderCaption",
		"XInterface.STY_LadderButton",
		"XInterface.STY_LadderButtonHi",
		"XInterface.STY_LadderButtonActive",
		"XInterface.STY_BindBox",
		"XInterface.STY_SquareBar",
		"XInterface.STY_MidGameButton",
		"XInterface.STY_TextLabel",
		"XInterface.STY_ComboListBox",
		"XInterface.STY_SquareMenuButton",
		"XInterface.STY_IRCText",
		"XInterface.STY_IRCEntry",
		"XInterface.STY_ListSelection",
		"XInterface.STY_EditBox",
	};
	DesignModeHints = {
		FDesignModeHint({ " Key","                                Description" }),
		FDesignModeHint({ " (F1)","                                View this help screen" }),
		FDesignModeHint({ " Ctrl + Alt + D","                      Toggles design mode" }),
		FDesignModeHint({ " Ctrl + Alt + E","                      Toggles property editor mode" }),
		FDesignModeHint({ " [Ctrl +] H","                          Toggles active/focused info" }),
		FDesignModeHint({ " [Ctrl +] I","                          Toggle interactive mode" }),
		FDesignModeHint({ " [Ctrl +] P","                          Toggles full MenuOwner chains for active/focused" }),
		FDesignModeHint({ " [Ctrl +] C","                          Copy MoveControl position to clipboard" }),
		FDesignModeHint({ " [Ctrl +] X","                          Export MoveControl to clipboard" }),
		FDesignModeHint({ " [Ctrl +] U","                          Refresh the property window in the designer" }),
		FDesignModeHint({ " [Ctrl +] Up/Down/Left/Right","         Reposition MoveControl using arrow keys" }),
		FDesignModeHint({ " [Ctrl +] +/-","                        Resize MoveControl vertically" }),
		FDesignModeHint({ " [Ctrl +] Num+/Num-","                  Resize selected component horizontally" }),
		FDesignModeHint({ " [Ctrl +] WheelUp","                    Set MoveControl to MoveControl's menuowner" }),
		FDesignModeHint({ " [Ctrl +] WheenDown","                  Set MoveControl to MoveControl's focused control" }),
		FDesignModeHint({ " [(Ctrl + Alt) +] MouseX/Y+LMouse","    Reposition MoveControl using mouse" }),
		FDesignModeHint({ " (Shift)","                             Hides all design mode indicators" }),
		FDesignModeHint({ " (Ctrl + Alt)","                        View focus chain" }),
		FDesignModeHint({ " [Ctrl +] Tab","                        Select new MoveControl" }),
		FDesignModeHint({ " [Ctrl +] LMouse","                     Select new MoveControl" }),
	};

	MenuMouseSens = 1.25;
	DblClickWindow = 0.5;
	ButtonRepeatDelay = 0.25;
	FastCursorStep = 1;
	CursorStep = 1;
	DesignerMenu = "GUIDesigner.PropertyManager";
	bModulateStackedMenus = true;
	bHighlightCurrent = true;
	bCurMenuInitialized = true;
	QuestionMenuClass = "XInterface.GUIQuestionPage";
}

//const DoCounter = 1;

bool UGUIController::OnNeedRawKeyPress(uint8 NewKey)
{
	return false;    //FAKE   /ELiZ
}

void UGUIController::AddBuddy(FString NewBuddyName)
{
}

//native Event GUIFont GetMenuFont(FString FontName);
UGUIFont* UGUIController::GetMenuFont(FString FontName)
{
	return nullptr;    //FAKE   /ELiZ
}

//native Event GUIStyles GetStyle(FString StyleName, EeFontScale& FontScale);
UGUIStyles* UGUIController::GetStyle(FString StyleName, EeFontScale& FontScale)
{
	return nullptr;    //FAKE   /ELiZ
}

//native final Function FString GetCurrentRes();
FString UGUIController::GetCurrentRes()
{
	return "FAKE";    //FAKE   /ELiZ
}

//native final Function bool SetRenderDevice(FString NewRenderDevice);
bool UGUIController::SetRenderDevice(FString NewRenderDevice)
{
	return false;    //FAKE   /ELiZ
}

//native final Function ResetDesigner();
void UGUIController::ResetDesigner()
{

}

//native final Function ResetInput();
void UGUIController::ResetInput()
{

}

//native final Function GetProfileList(FString Prefix, TArray<FString>& ProfileList);
void UGUIController::GetProfileList(FString Prefix, TArray<FString>& ProfileList)
{

}

//native final Function ResetKeyboard();
void UGUIController::ResetKeyboard()
{

}

//native final Function GetOGGList(TArray<FString>& OGGFiles);
void UGUIController::GetOGGList(TArray<FString>& OGGFiles)
{

}

//native final Function PlayInterfaceSound(EClickSound SoundType);
void UGUIController::PlayInterfaceSound(EClickSound SoundType)
{

}

//native final Function SetMoveControl(UGUIComponent* C);
void UGUIController::SetMoveControl(UGUIComponent* C)
{

}

//native Function Profile(FString ProfileName);
void UGUIController::Profile(FString ProfileName)
{

}

//native Function GetDEMList(TArray<FString>& DEMFiles);
void UGUIController::GetDEMList(TArray<FString>& DEMFiles)
{

}

//native Function bool GetDEMHeader(FString DemoName, FString& MapName, FString& GameType, int32& ScoreLimit, int32& TimeLimit, int32& ClientSide, FString& RecordedBy, FString& TimeStamp, FString& ReqPackages);
bool UGUIController::GetDEMHeader(FString DemoName, FString& MapName, FString& aGameType, int32& ScoreLimit, int32& TimeLimit, int32& ClientSide, FString& RecordedBy, FString& TimeStamp, FString& ReqPackages)
{
	return false;    //FAKE   /ELiZ
}

//native Function GetOwnageList(TArray<int32>& RLevel, TArray<FString>& MNames, TArray<FString>& mDesc, TArray<FString>& mURL);
void UGUIController::GetOwnageList(TArray<int32>& RLevel, TArray<FString>& MNames, TArray<FString>& mDesc, TArray<FString>& mURL)
{

}

//native Function SaveOwnageList(TArray<eOwnageMap> Maps);
void UGUIController::SaveOwnageList(TArray<FeOwnageMap> Maps)
{

}

//native final Function GetWeaponList(TArray<AWeapon* >& WeaponClass, TArray<FString>& WeaponDesc);
void UGUIController::GetWeaponList(TArray<AWeapon*>& WeaponClass, TArray<FString>& WeaponDesc)
{

}

//native final Function GetMapList(FString Prefix, UGUIList* List, bool bDecoText);
void UGUIController::GetMapList(FString Prefix, UGUIList* List, bool bDecoText)
{

}

//native Function LaunchURL(FString URL);
void UGUIController::LaunchURL(FString URL)
{

}

//native Function bool CheckFirewall();
bool UGUIController::CheckFirewall()
{
	return false;    //FAKE   /EliZ
}

//native Function bool AuthroizeFirewall();
bool UGUIController::AuthroizeFirewall()
{
	return false;    //FAKE   /EliZ
}

//native Function bool CheckForECE();
bool UGUIController::CheckForECE()
{
	return false;    //FAKE   /EliZ
}


FString UGUIController::LoadDecoText(FString PackageName, FString DecoTextName)
{
	return "";
}

void UGUIController::GetTeamSymbolList(TArray<FString>& SymbolNames, bool bNoSinglePlayer)
{
	//Class'CacheManager'.GetTeamSymbolList(SymbolNames, bNoSinglePlayer);
}

UGUIPage* UGUIController::TopPage()
{
	return ActivePage;
}

void UGUIController::InitializeController()
{
	/*
	int32 i = 0;
	local UGUIStyles*  NewStyleClass;
	PrecachePlayerRecords();
	for (i = 0; i < DefaultStyleNames.Length; i++)
	{
		NewStyleClass = UGUIStyles*(DynamicLoadObject(DefaultStyleNames[i], Class'Class'));
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
		NewStyleClass = UGUIStyles*(DynamicLoadObject(StyleNames[i], Class'Class'));
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
	Class'CacheManager'.InitCache();
	bECEEdition = CheckForECE();
	*/
}

void UGUIController::PrecachePlayerRecords()
{
}

bool UGUIController::RegisterStyle(UGUIStyles*  StyleClass, bool bTemporary)
{
	/*
	local GUIStyles NewStyle;
	int32 i = 0;
	int32 Index = 0;
	Index = -1;
	if (StyleClass != None)
	{
		for (i = 0; i < StyleStack.Length; i++)
		{
			if (StyleStack[i].Class == StyleClass)
			{
				Log("Style already registered '" $ string(StyleClass) $ "'");
				return true;
			}
			if (StyleStack[i].KeyName == StyleClass.Default.KeyName)
			{
				Index = i;
			}
		}
		NewStyle = new (None) classStyleClass;
		if (NewStyle != None)
		{
			if (Index < 0)
			{
				StyleStack[StyleStack.Length] = NewStyle;
			}
			else
			{
				if (bModAuthor)
				{
					Log("Replacing Style" @ StyleStack[Index].KeyName @ "with" @ string(NewStyle), 'ModAuthor');
				}
				StyleStack[Index].Controller = None;
				StyleStack[Index] = NewStyle;
			}
			NewStyle.Controller = Self;
			NewStyle.Initialize();
			NewStyle.bTemporary = bTemporary;
			return true;
		}
	}
	*/
	return false;
}

UGUIComponent* UGUIController::AddComponentClass(FString ClassName)
{
	int32 i = 0;
	UGUIComponent* Cls = nullptr;
	/*
	for (i = 0; i < RegisteredClasses.Length; i++)
	{
		if (string(RegisteredClasses[i]) ~= ClassName)
		{
			return RegisteredClasses[i];
		}
	}
	Cls = class<GUIComponent>(DynamicLoadObject(ClassName, Class'Class'));
	if (Cls != None)
	{
		RegisteredClasses[RegisteredClasses.Length] = Cls;
	}
	*/
	return Cls;
}

UGUIPage* UGUIController::FindPersistentMenuByName(FString MenuClass)
{
	/*
	int32 i = 0;
	if (MenuClass == "")
	{
		return None;
	}
	for (i = 0; i < PersistentStack.Length; i++)
	{
		if (MenuClass ~= string(PersistentStack[i].Class))
		{
			return PersistentStack[i];
		}
	}
	*/
	return nullptr;
}

int32 UGUIController::FindMenuIndexByName(FString MenuClass)
{
	/*
	int32 i = 0;
	if (MenuClass == "")
	{
		return -1;
	}
	for (i = 0; i < MenuStack.Length; i++)
	{
		if (MenuClass ~= string(MenuStack[i].Class))
		{
			return i;
		}
	}
	*/
	return -1;
}

int32 UGUIController::FindMenuIndex(UGUIPage* Menu)
{
	/*
	int32 i = 0;
	if (Menu == None)
	{
		return -1;
	}
	for (i = 0; i < MenuStack.Length; i++)
	{
		if (MenuStack[i] == Menu)
		{
			return i;
		}
	}
	*/
	return -1;
}

int32 UGUIController::FindPersistentMenuIndex(UGUIPage* Menu)
{
	/*
	int32 i = 0;
	if (Menu == None)
	{
		return -1;
	}
	for (i = 0; i < PersistentStack.Length; i++)
	{
		if (Menu == PersistentStack[i])
		{
			return i;
		}
	}
	*/
	return -1;
}

UGUIPage* UGUIController::FindPersistentMenuByClass(UGUIPage* PageClass)
{
	/*
	int32 i = 0;
	if (PageClass == None)
	{
		return None;
	}
	for (i = 0; i < PersistentStack.Length; i++)
	{
		if (ClassIsChildOf(PersistentStack[i].Class, PageClass))
		{
			return PersistentStack[i];
		}
	}
	*/
	return nullptr;
}

UGUIPage* UGUIController::FindMenuByClass(UGUIPage* PageClass)
{
	/*
	int32 i = 0;
	if (PageClass == None)
	{
		return None;
	}
	for (i = 0; i < MenuStack.Length; i++)
	{
		if (ClassIsChildOf(MenuStack[i].Class, PageClass))
		{
			return MenuStack[i];
		}
	}
	*/
	return nullptr;
}

UGUIPage* UGUIController::CreateMenu(FString NewMenuName)
{
	/*
	local class<GUIPage>  NewMenuClass;
	local UGUIPage* NewMenu;
	int32 i = 0;
	if (NewMenuName ~= "XInterface.UT2MainMenu")
	{
		NewMenuName = GetMainMenuClass();
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
				return None;
			}
			else
			{
				if (NewMenuClass.Default.bPersistent)
				{
					i = PersistentStack.Length;
					PersistentStack.Length = (i + 1);
					PersistentStack[i] = NewMenu;
				}
			}
		}
		bCurMenuInitialized = false;
		return NewMenu;
	}
	Log("Could not DLO menu '" $ NewMenuName $ "'");
	*/
	return nullptr;
}

bool UGUIController::OpenMenu(FString NewMenuName, FString Param1, FString Param2)
{
	/*
	local UGUIPage* NewMenu;
	if (bModAuthor)
	{
		Log(string(Class) @ "OpenMenu [" $ NewMenuName $ "] (" $ Param1 $ ") (" $ Param2 $ ")", 'ModAuthor');
	}
	if (ActivePage != None)
	{
		if (!ActivePage.AllowOpen(NewMenuName))
		{
			return false;
		}
	}
	if ((!bCurMenuInitialized) && (MenuStack.Length > 0))
	{
		if (bModAuthor)
		{
			Log("Cannot open menu until menu initialization is complete!", 'ModAuthor');
		}
		return false;
	}
	NewMenu = CreateMenu(NewMenuName);
	if (NewMenu != None)
	{
		if (FindMenuIndex(NewMenu) != -1)
		{
			bCurMenuInitialized = true;
			return false;
		}
		NewMenu.ParentPage = ActivePage;
		ResetFocus();
		PushMenu(MenuStack.Length, NewMenu, Param1, Param2);
		if (NewMenu.bDisconnectOnOpen)
		{
			ConsoleCommand("DISCONNECT");
		}
		return true;
	}
	Log("Could not open menu" @ NewMenuName);
	*/
	return false;
}

void UGUIController::AutoLoadMenus()
{
	/*
	local UGUIPage* NewMenu;
	int32 i = 0;
	Super::AutoLoadMenus();
	for (i = 0; i < AutoLoad.Length; i++)
	{
		NewMenu = CreateMenu(AutoLoad[i].MenuClassName);
		if (NewMenu == None)
		{
			Log("Could not auto-load" @ AutoLoad[i].MenuClassName);
		}
		else
		{
			if (AutoLoad[i].bPreInitialize)
			{
				NewMenu.InitComponent(Self, None);
			}
		}
	}
	*/
}

bool UGUIController::ReplaceMenu(FString NewMenuName, FString Param1, FString Param2, bool bCancelled)
{
	/*
	local UGUIPage* NewMenu;
	if ((ActivePage == None) || (MenuStack.Length == 0))
	{
		return OpenMenu(NewMenuName, Param1, Param2);
	}
	if (bModAuthor)
	{
		Log(string(Class) @ "ReplaceMenu [" $ NewMenuName $ "]  (" $ Param1 $ ")  (" $ Param2 $ ")", 'ModAuthor');
	}
	if ((!bCurMenuInitialized) && (MenuStack.Length > 0))
	{
		if (bModAuthor)
		{
			Log("Cannot replace menu until menu initialization is complete!", 'ModAuthor');
		}
		return false;
	}
	NewMenu = CreateMenu(NewMenuName);
	if (NewMenu != None)
	{
		NewMenu.ParentPage = ActivePage.ParentPage;
		ResetFocus();
		PopMenu(-1, ActivePage, bCancelled);
		PushMenu((MenuStack.Length - 1), NewMenu, Param1, Param2);
		return true;
	}
	*/
	return false;
}

void UGUIController::PushMenu(int32 Index, UGUIPage* NewMenu, FString Param1, FString Param2)
{
	/*
	if (NewMenu == None)
	{
		Log("Call to GUIController.PushMenu() with invalid NewMenu!!!");
		return;
	}
	SetControllerStatus(true);
	if (Index >= 0)
	{
		MenuStack[Index] = NewMenu;
		ActivePage = NewMenu;
	}
	CloseOverlays();
	ResetInput();
	if (NewMenu.Controller == None)
	{
		NewMenu.InitComponent(Self, None);
	}
	NewMenu.CheckResolution(false, Self);
	NewMenu.Opened(NewMenu);
	NewMenu.MenuState = 2;
	NewMenu.PlayOpenSound();
	bCurMenuInitialized = true;
	NewMenu.HandleParameters(Param1, Param2);
	bForceMouseCheck = true;
	NewMenu.OnOpen();
	*/
}

void UGUIController::PopMenu(int32 Index, UGUIPage* CurMenu, bool bCancelled)
{
	/*
	CloseOverlays();
	CurMenu.Closed(CurMenu, bCancelled);
	if (((Index >= 0) && ((Index + 1) < MenuStack.Length)) && (MenuStack[(Index + 1)] != None))
	{
		MenuStack[(Index + 1)].ParentPage = CurMenu.ParentPage;
	}
	CurMenu.ParentPage = None;
	CurMenu.Free();
	if (Index < 0)
	{
		return;
	}
	if ((Index >= MenuStack.Length) || (MenuStack[Index] != CurMenu))
	{
		Index = FindMenuIndex(CurMenu);
	}
	if ((Index >= 0) && (Index < MenuStack.Length))
	{
		MenuStack.remove(Index, 1);
	}
	*/
}

bool UGUIController::RemoveMenuAt(int32 Index, bool bCancelled)
{
	/*
	if ((Index < 0) || (Index >= MenuStack.Length))
	{
		return false;
	}
	return RemoveMenu(MenuStack[Index], bCancelled);
	*/
	return false;    //FAKE  /ELiZ
}

bool UGUIController::RemoveMenu(UGUIPage* Menu, bool bCancelled)
{
	/*
	if (MenuStack.Length == 0)
	{
		return false;
	}
	if ((Menu == None) || (Menu == ActivePage))
	{
		return CloseMenu(bCancelled);
	}
	if (bModAuthor)
	{
		Log(string(Class) @ "RemoveMenu [" $ string(Menu.Name) $ "]", 'ModAuthor');
	}
	if (!bCurMenuInitialized)
	{
		if (bModAuthor)
		{
			Log("Cannot remove menu until initialization is complete!", 'ModAuthor');
		}
		return false;
	}
	if (!Menu.OnCanClose(bCancelled))
	{
		return false;
	}
	ResetInput();
	Menu.PlayCloseSound();
	PopMenu(FindMenuIndex(Menu), Menu, bCancelled);
	if (MenuStack.Length == 0)
	{
		if ((!Menu.bAllowedAsLast) && (!MainNotWanted))
		{
			return OpenMenu(GetMainMenuClass());
		}
		ActivePage = None;
		SetControllerStatus(false);
	}
	VerifyStack();
	bForceMouseCheck = true;
	*/
	return true;
}

bool UGUIController::CloseMenu(bool bCancelled)
{
	/*
	if ((MenuStack.Length == 0) || (ActivePage == None))
	{
		return false;
	}
	if (bModAuthor)
	{
		Log(string(Class) @ "CloseMenu [" $ string(ActivePage.Name) $ "]", 'ModAuthor');
	}
	if (!bCurMenuInitialized)
	{
		if (bModAuthor)
		{
			Log("Cannot close menu until initialization is complete!", 'ModAuthor');
		}
		return false;
	}
	if (!ActivePage.OnCanClose(bCancelled))
	{
		return false;
	}
	ResetInput();
	ActivePage.PlayCloseSound();
	PopMenu(FindMenuIndex(ActivePage), ActivePage, bCancelled);
	ActivePage.CheckResolution(true, Self);
	bCurMenuInitialized = false;
	if (MenuStack.Length > 0)
	{
		ActivePage = MenuStack[(MenuStack.Length - 1)];
		ActivePage.MenuState = 2;
		ResetFocus();
		ActivePage.FocusFirst(None);
		if (!ActivePage.bNeverFocus)
		{
			ActivePage.OnActivate();
		}
	}
	else
	{
		if ((!ActivePage.bAllowedAsLast) && (!MainNotWanted))
		{
			ActivePage = None;
			return OpenMenu(GetMainMenuClass());
		}
		ActivePage = None;
		SetControllerStatus(false);
	}
	bCurMenuInitialized = true;
	if (ActivePage != None)
	{
		ActivePage.OnReOpen();
	}
	bForceMouseCheck = true;
	*/
	return true;
}

void UGUIController::CloseAll(bool bCancel, bool bForced)
{
	/*
	int32 i = 0;
	if (bModAuthor)
	{
		Log(string(Name) @ "CloseAll bCancel:" $ string(bCancel) @ "Forced:" $ string(bForced) @ "(Currently" @ string(MenuStack.Length) @ "menus open)", 'ModAuthor');
		for (i = 0; i < MenuStack.Length; i++)
		{
			if (MenuStack[i] == None)
			{
				Log("   Menu[" $ string(i) $ "]: None", 'ModAuthor');
			}
			else
			{
				Log("   Menu[" $ string(i) $ "]:" $ string(MenuStack[i].Name), 'ModAuthor');
			}
		}
	}
	if (bForced)
	{
		MainNotWanted = true;
	}
	if (MenuStack.Length > 0)
	{
		SaveRestorePages();
	}
	if (MenuStack.Length >= 0)
	{
		CloseMenu(bCancel);
	}
	MainNotWanted = false;
	for (i = (MenuStack.Length - 1); i >= 0; i--)
	{
		PopMenu(i, MenuStack[i], bCancel);
	}
	if (GameResolution != "")
	{
		Console(Master.Console).DelayedConsoleCommand("SETRES" @ GameResolution);
		GameResolution = "";
	}
	ActivePage = None;
	SetControllerStatus(false);
	*/
}

int32 UGUIController::Count()
{
	//return MenuStack.Length;
	return 0;     //FAKE   /ELiZ
}

void UGUIController::SaveRestorePages()
{
	/*
	int32 i = 0;
	FString Param1 = "";
	FString Param2 = "";
	FString MenuClass = "";
	RestoreMenus.remove(0, RestoreMenus.Length);
	for (i = (MenuStack.Length - 1); i >= 0; i--)
	{
		if (MenuStack[i] != None)
		{
			if (MenuStack[i].bRestorable)
			{
				MenuClass = string(MenuStack[i].Class);
				Param1 = "";
				Param2 = "";
				if (MenuStack[i].GetRestoreParams(Param1, Param2))
				{
					RestoreMenus.insert(0, 1);
					RestoreMenus[0].MenuClassName = MenuClass;
					RestoreMenus[0].Param1 = Param1;
					RestoreMenus[0].Param2 = Param2;
				}
			}
		}
	}
	*/
}

void UGUIController::PerformRestore()
{
	/*
	int32 i = 0;
	int32 idx = 0;
	if (bModAuthor)
	{
		Log("Restoring previously open menus (" $ string(RestoreMenus.Length) $ " menus to restore)", 'ModAuthor');
	}
	for (i = 0; i < RestoreMenus.Length; i++)
	{
		idx = FindMenuIndexByName(RestoreMenus[i].MenuClassName);
		if (idx == -1)
		{
			OpenMenu(RestoreMenus[i].MenuClassName, RestoreMenus[i].Param1, RestoreMenus[i].Param2);
		}
	}
	RestoreMenus.remove(0, RestoreMenus.Length);
	*/
}

void UGUIController::SetControllerStatus(bool On)
{
	/*
	bool bWasActive = false;
	if (((bActive && (!On)) && (ViewportOwner != None)) && (ViewportOwner.Actor != None))
	{
		ViewportOwner.Actor.UnPressButtons();
	}
	bWasActive = bActive;
	bActive = On;
	bVisible = On;
	bRequiresTick = On;
	if (((bActive && (!bWasActive)) && (ViewportOwner != None)) && (ViewportOwner.Actor != None))
	{
		ViewportOwner.Actor.UnPressButtons();
	}
	ViewportOwner.bShowWindowsMouse = (On && ViewportOwner.bWindowsMouseAvailable);
	if (On)
	{
		bIgnoreUntilPress = true;
	}
	else
	{
		ResetDesigner();
		ViewportOwner.Actor.ConsoleCommand("toggleime 0");
	}
	PurgeComponentClasses();
	*/
}

void UGUIController::ChangeFocus(UGUIComponent* Who)
{
	/*
	if (Who != None)
	{
		Who.SetFocus(None);
	}
	*/
}

void UGUIController::ResetFocus()
{
	/*
	MoveControl = None;
	if (ActiveControl != None)
	{
		ActiveControl.MenuStateChange(0);
		ActiveControl = None;
	}
	if (FocusedControl != None)
	{
		FocusedControl.LoseFocus(None);
	}
	RepeatKey = 0;
	RepeatTime = 0;
	*/
}

void UGUIController::MoveFocused(UGUIComponent* C, int32 bmLeft, int32 bmTop, int32 bmWidth, int32 bmHeight, float ClipX, float ClipY, float Val)
{
	/*
	if (C.bScaleToParent && (C.MenuOwner != None))
	{
		ClipX = C.MenuOwner.ActualWidth();
		ClipY = C.MenuOwner.ActualHeight();
	}
	if (bmLeft != 0)
	{
		if (((C.WinLeft < 2) && (C.WinLeft > -2)) && (!C.bNeverScale))
		{
			(C.WinLeft += ((Val / ClipX) * float(bmLeft)));
		}
		else
		{
			(C.WinLeft += (Val * float(bmLeft)));
		}
	}
	if (bmTop != 0)
	{
		if (((C.WinTop < 2) && (C.WinTop > -2)) && (!C.bNeverScale))
		{
			(C.WinTop += ((Val / ClipY) * float(bmTop)));
		}
		else
		{
			(C.WinTop += (Val * float(bmTop)));
		}
	}
	if (bmWidth != 0)
	{
		if (((C.WinWidth < 2) && (C.WinWidth > -2)) && (!C.bNeverScale))
		{
			(C.WinWidth += ((Val / ClipX) * float(bmWidth)));
		}
		else
		{
			(C.WinWidth += (Val * float(bmWidth)));
		}
	}
	if (bmHeight != 0)
	{
		if (C.WinHeight <= 2)
		{
			(C.WinHeight += ((Val / ClipX) * float(bmHeight)));
		}
		else
		{
			(C.WinHeight += (Val * float(bmHeight)));
		}
	}
	*/
}

bool UGUIController::HasMouseMoved(float ErrorMargin)
{
	//return ((Abs((MouseX - LastMouseX)) > Abs(ErrorMargin)) || (Abs((MouseY - LastMouseY)) > Abs(ErrorMargin)));
	return false;    //FAKE   /EliZ
}

bool UGUIController::CanShowHints()
{
	/*
	if (bNoToolTips)
	{
		return false;
	}
	if ((ActivePage != None) && ActivePage.bCaptureMouse)
	{
		return false;
	}
	if ((DropSource != None) || (DropTarget != None))
	{
		return false;
	}
	if (((!bDesignModeToolTips) && bDesignMode) && bHighlightCurrent)
	{
		return false;
	}
	*/
	return true;
}

bool UGUIController::NeedsMenuResolution()
{
	/*
	int32 i = 0;
	for (i = (MenuStack.Length - 1); i >= 0; i--)
	{
		if ((MenuStack[i] != None) && MenuStack[i].bRequire640x480)
		{
			return true;
		}
		if (!MenuStack[i].bRenderWorld)
		{
		}
	}
	*/
	return false;
}

void UGUIController::SetRequiredGameResolution(FString GameRes)
{
	GameResolution = GameRes;
}

void UGUIController::NotifyLevelChange()
{
	/*
	int32 i = 0;
	if (bModAuthor)
	{
		Log(string(Class) @ "NotifyLevelChange()", 'ModAuthor');
	}
	ResetDesigner();
	if (((bActive && (ViewportOwner.Actor != None)) && (ViewportOwner.Actor.Level != None)) && ViewportOwner.Actor.Level.IsPendingConnection())
	{
		SaveRestorePages();
	}
	i = (MenuStack.Length - 1);
	if ((i >= 0) && (MenuStack.Length != 0))
	{
		if (MenuStack[i] != None)
		{
			if (MenuStack[i].bPersistent)
			{
			}
			if (MenuStack[i].NotifyLevelChange())
			{
				RemoveMenu(MenuStack[i], true);
			}
		}
		i--;
	}
	for (i = (PersistentStack.Length - 1); i >= 0; i--)
	{
		if ((PersistentStack[i] != None) && PersistentStack[i].NotifyLevelChange())
		{
			if (PersistentStack[i].IsOpen())
			{
				RemoveMenu(PersistentStack[i], true);
			}
			else
			{
				PersistentStack[i].Free();
			}
			if (!PersistentStack[i].bPersistent)
			{
				PersistentStack.remove(i, 1);
			}
		}
	}
	PurgeObjectReferences();
	VerifyStack();
	if (MenuStack.Length > 0)
	{
		RestoreMenus.remove(0, RestoreMenus.Length);
	}
	*/
}

void UGUIController::CloseOverlays()
{
	/*
	MouseOver = None;
	ContextMenu = None;
	*/
}

void UGUIController::VerifyStack()
{
	/*
	int32 i = 0;
	for (i = 0; i < MenuStack.Length; i++)
	{
		if ((MenuStack[i] == None) || ((MenuStack[i].Controller == None) && bCurMenuInitialized))
		{
			MenuStack.remove(i--, 1);
		}
		else
		{
			if (i > 0)
			{
				MenuStack[i].ParentPage = MenuStack[(i - 1)];
			}
		}
	}
	ConsolidateMenus();
	*/
}

void UGUIController::PurgeObjectReferences()
{
	/*
	local UGUIStyles*  OriginalStyle;
	int32 i = 0;
	for (i = 0; i < STYLE_NUM; i++)
	{
		if (StyleStack[i] == None)
		{
			OriginalStyle = UGUIStyles*(DynamicLoadObject(DefaultStyleNames[i], Class'Class'));
			if (!RegisterStyle(OriginalStyle))
			{
				Log("Could not restore default style " $ string(i) $ " (" $ DefaultStyleNames[i] $ ")");
			}
		}
		else
		{
			if (StyleStack[i].bTemporary)
			{
				OriginalStyle = UGUIStyles*(DynamicLoadObject(DefaultStyleNames[i], Class'Class'));
				if (!RegisterStyle(OriginalStyle))
				{
					Log("Could not restore default style " $ string(i) $ " (" $ DefaultStyleNames[i] $ ")");
					StyleStack[i] = None;
				}
			}
		}
	}
	if (StyleStack.Length > STYLE_NUM)
	{
		StyleStack.remove(STYLE_NUM, (StyleStack.Length - STYLE_NUM));
	}
	if (FontStack.Length > FONT_NUM)
	{
		FontStack.remove(FONT_NUM, (FontStack.Length - FONT_NUM));
	}
	if (MouseCursors.Length > CURSOR_NUM)
	{
		MouseCursors.remove(CURSOR_NUM, (MouseCursors.Length - CURSOR_NUM));
	}
	PurgeComponentClasses();
	*/
}

void UGUIController::PurgeComponentClasses()
{
}

void UGUIController::ConsolidateMenus()
{
	/*
	int32 i = 0;
	int32 j = 0;
	for (i = (MenuStack.Length - 1); i >= 0; i--)
	{
		j = 0;
		if (j < i)
		{
			if (MenuStack[i].Class == MenuStack[j].Class)
			{
				MenuStack[(j + 1)].ParentPage = MenuStack[j].ParentPage;
				MenuStack.remove(j, 1);
			}
			else
			{
				j++;
			}
		}
	}
	*/
}

void UGUIController::Validate()
{
}

//native static final Function FString GetMainMenuClass();
FString UGUIController::GetMainMenuClass()
{
	return "FAKE";    //FAKE   /EliZ
}

FString UGUIController::GetSinglePlayerPage()
{
	return "FAKE";    //FAKE   /EliZ
}

FString UGUIController::GetServerBrowserPage()
{
	return "FAKE";    //FAKE   /EliZ
}

FString UGUIController::GetMultiplayerPage()
{
	return "FAKE";    //FAKE   /EliZ
}

FString UGUIController::GetInstantActionPage()
{
	return "FAKE";    //FAKE   /EliZ
}

FString UGUIController::GetModPage()
{
	return "FAKE";    //FAKE   /EliZ
}

FString UGUIController::GetSettingsPage()
{
	return "FAKE";    //FAKE   /EliZ
}

FString UGUIController::GetQuitPage()
{
	return "FAKE";    //FAKE   /EliZ
}

bool UGUIController::SetKeyBind(FString BindKeyName, FString BindKeyValue)
{
	//ViewportOwner.Actor.ConsoleCommand("set Input" @ BindKeyName @ BindKeyValue);
	return true;
}

bool UGUIController::KeyNameFromIndex(uint8 iKey, FString& KeyName, FString& LocalizedKeyName)
{
	/*
	KeyName = ViewportOwner.Actor.ConsoleCommand("KEYNAME" @ string(iKey));
	LocalizedKeyName = ViewportOwner.Actor.ConsoleCommand("LOCALIZEDKEYNAME" @ string(iKey));
	return (KeyName != "");
	*/
	return false;    //FAKE   /EliZ

}

bool UGUIController::GetCurrentBind(FString BindKeyName, FString& BindKeyValue)
{
	/*
	if (BindKeyName != "")
	{
		BindKeyValue = ViewportOwner.Actor.ConsoleCommand("KEYBINDING" @ BindKeyName);
		return (BindKeyValue != "");
	}
	*/
	return false;
}

bool UGUIController::GetAssignedKeys(FString BindAlias, TArray<FString>& BindKeyNames, TArray<FString>& LocalizedBindKeyNames)
{
	/*
	int32 i = 0;
	int32 iKey = 0;
	FString S = "";
	BindKeyNames.Length = 0;
	LocalizedBindKeyNames.Length = 0;
	S = ViewportOwner.Actor.ConsoleCommand("BINDINGTOKEY" @ "\"" $ BindAlias $ "\"");
	if (S != "")
	{
		Split(S, ",", BindKeyNames);
		for (i = 0; i < BindKeyNames.Length; i++)
		{
			iKey = int(ViewportOwner.Actor.ConsoleCommand("KEYNUMBER" @ BindKeyNames[i]));
			if (iKey != -1)
			{
				LocalizedBindKeyNames[i] = ViewportOwner.Actor.ConsoleCommand("LOCALIZEDKEYNAME" @ string(iKey));
			}
		}
	}
	return (BindKeyNames.Length > 0);
	*/
	return false;    //FAKE   /EliZ
}

bool UGUIController::SearchBinds(FString BindAliasMask, TArray<FString>& BindAliases)
{
	/*
	FString S = "";
	BindAliases.Length = 0;
	S = ViewportOwner.Actor.ConsoleCommand("FINDKEYBINDS" @ "\"" $ BindAliasMask $ "\"");
	if (S != "")
	{
		Split(S, ",", BindAliases);
	}
	return (BindAliases.Length > 0);
	*/
	return false;    //FAKE   /EliZ
}

bool UGUIController::KeyPressed(EInputKey iKey)
{
	//return (KeyDown[iKey] != 0);
	return false;    //FAKE   /EliZ
}

UGUIQuestionPage* UGUIController::ShowQuestionDialog(FString Question, uint8 Buttons, uint8 defButton)
{
	/*
	local GUIQuestionPage QPage;
	if (Buttons == 0)
	{
		Buttons = 1;
	}
	if (OpenMenu(QuestionMenuClass))
	{
		QPage = GUIQuestionPage(TopPage());
		QPage.SetupQuestion(Question, Buttons, defButton);
		return QPage;
	}
	*/
	return nullptr;
}

int32 UGUIController::GetMenuStackSize()
{
	//return MenuStack.Length;
	return 0;    //FAKE   /EliZ
}

bool UGUIController::RefreshMenus()
{
	/*
	int32 i = 0;
	local class<Object>  tmpClass;
	tmpClass = class<Object>(DynamicLoadObject("AGP_Interface.AAGameMenu", Class'Class'));
	for (i = (PersistentStack.Length - 1); i >= 0; i--)
	{
		if ((!PersistentStack[i].bPersistent) || (PersistentStack[i].Class == tmpClass))
		{
			PersistentStack.remove(i, 1);
		}
	}
	*/
	return true;
}