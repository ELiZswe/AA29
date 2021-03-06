// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/BaseGUIController.h"
#include "AA29/AA29.h"
#include "AA29/MyEnums.h"
#include "GUIController.generated.h"

class UGUIComponent;
class UGUIToolTip;
class UGUIContextMenu;
class UGUIComponent;
class UGUIPage;
class UGUIStyles;
class UGUIFont;
class UGUIList;
class AWeapon;
class UGUIQuestionPage; 

class UGUIQuestionPage;
UCLASS(Config=Game)
class UGUIController : public UBaseGUIController
{
	GENERATED_BODY()
public:
	UGUIController();

	UPROPERTY()											bool bECEEdition;									//var bool bECEEdition;
	UPROPERTY()											TArray<UGUIComponent*> RegisteredClasses;			//var array<class<GUIComponent> > RegisteredClasses;
	UPROPERTY()											TArray<EInputKey> KeyDown;							//var const byte KeyDown;
	UPROPERTY()											bool bFixedMouseSize;								//var config bool bFixedMouseSize;
	UPROPERTY()											float LastRenderTime;								//var float LastRenderTime;
	UPROPERTY()											float RenderDelta;									//var float RenderDelta;
	UPROPERTY()											bool bSnapCursor;									//var bool bSnapCursor;
	UPROPERTY()											bool bIgnoreUntilPress;								//var bool bIgnoreUntilPress;
	UPROPERTY()											bool bForceMouseCheck;								//var bool bForceMouseCheck;
	UPROPERTY()											bool bCurMenuInitialized;							//var bool bCurMenuInitialized;
	UPROPERTY()											bool MainNotWanted;									//var bool MainNotWanted;
	UPROPERTY(globalconfig)								bool bDrawFullPaths;								//var globalconfig bool bDrawFullPaths;
	UPROPERTY(globalconfig)								bool bHighlightCurrent;								//var globalconfig bool bHighlightCurrent;
	UPROPERTY()											bool bInteractiveMode;								//var bool bInteractiveMode;
	UPROPERTY(globalconfig)								bool bDesignMode;									//var globalconfig bool bDesignMode;
	UPROPERTY(globalconfig)								bool bExpertMode;									//var globalconfig bool bExpertMode;
	UPROPERTY(globalconfig)								bool bModAuthor;									//var globalconfig bool bModAuthor;
	UPROPERTY(globalconfig)								bool bAutoRefreshBrowser;							//var globalconfig bool bAutoRefreshBrowser;
	UPROPERTY(globalconfig)								bool bDesignModeToolTips;							//var globalconfig bool bDesignModeToolTips;
	UPROPERTY(globalconfig)								bool bNoToolTips;									//var globalconfig bool bNoToolTips;
	UPROPERTY(globalconfig)								bool bQuietMenu;									//var globalconfig bool bQuietMenu;
	UPROPERTY()											bool bModulateStackedMenus;							//var bool bModulateStackedMenus;
	UPROPERTY()											bool CtrlPressed;									//var bool CtrlPressed;
	UPROPERTY()											bool AltPressed;									//var bool AltPressed;
	UPROPERTY()											bool ShiftPressed;									//var bool ShiftPressed;
	UPROPERTY()											bool bIgnoreNextRelease;							//var bool bIgnoreNextRelease;
	UPROPERTY()											uint8 RepeatKey;									//var byte RepeatKey;
	UPROPERTY(globalconfig)								FString DesignerMenu;								//var globalconfig string DesignerMenu;
	UPROPERTY()											TArray<FString> MainMenuOptions;					//var TArray<FString> MainMenuOptions;
	UPROPERTY(config)									FString EditFavoriteMenu;							//var config string EditFavoriteMenu;
	UPROPERTY(config)									FString MatchSetupMenu;								//var config string MatchSetupMenu;
	UPROPERTY(config)									FString KickVotingMenu;								//var config string KickVotingMenu;
	UPROPERTY(config)									FString MapVotingMenu;								//var config string MapVotingMenu;
	UPROPERTY(config)									FString FilterMenuGamespy;							//var config string FilterMenuGamespy;
	UPROPERTY(config)									FString FilterMenu;									//var config string FilterMenu;
	UPROPERTY(config)									FString DynArrayPropertyMenu;						//var config string DynArrayPropertyMenu;
	UPROPERTY(config)									FString ArrayPropertyMenu;							//var config string ArrayPropertyMenu;
	UPROPERTY(config)									FString RequestDataMenu;							//var config string RequestDataMenu;
	UPROPERTY()											FString LastGameType;								//var transient string LastGameType;
	UPROPERTY()											FString GameResolution;								//var string GameResolution;
	UPROPERTY()											UMaterialInstance* WhiteBorder;						//var Material WhiteBorder;
	UPROPERTY()											UGUIToolTip* MouseOver;								//var GUIToolTip MouseOver;
	UPROPERTY()											UGUIContextMenu* ContextMenu;						//var GUIContextMenu ContextMenu;
	UPROPERTY()											UGUIComponent* DropTarget;							//var GUIComponent DropTarget;
	UPROPERTY()											UGUIComponent* DropSource;							//var GUIComponent DropSource;
	UPROPERTY()											UGUIComponent* MoveControl;							//var GUIComponent MoveControl;
	UPROPERTY()											UGUIComponent* SkipControl;							//var GUIComponent SkipControl;
	UPROPERTY()											UGUIComponent* ActiveControl;						//var GUIComponent ActiveControl;
	UPROPERTY()											UGUIComponent* FocusedControl;						//var GUIComponent FocusedControl;
	UPROPERTY()											UGUIPage* ActivePage;									//var GUIPage ActivePage;
	UPROPERTY()											USoundBase* FadeSound;									//var Sound FadeSound;
	UPROPERTY()											USoundBase* DragSound;									//var Sound DragSound;
	UPROPERTY()											USoundBase* DownSound;									//var Sound DownSound;
	UPROPERTY()											USoundBase* UpSound;									//var Sound UpSound;
	UPROPERTY()											USoundBase* EditSound;									//var Sound EditSound;
	UPROPERTY()											USoundBase* ClickSound;									//var Sound ClickSound;
	UPROPERTY()											USoundBase* MouseOverSound;								//var Sound MouseOverSound;
	UPROPERTY()											Fpointer Designer;									//var const transient pointer Designer;
	UPROPERTY()											int32 CursorStep;									//var int CursorStep;
	UPROPERTY()											int32 LastClickY;									//var int LastClickY;
	UPROPERTY()											int32 LastClickX;									//var int LastClickX;
	UPROPERTY()											int32 ResY;											//var const int ResY;
	UPROPERTY()											int32 ResX;											//var const int ResX;
	UPROPERTY()											int32 FastCursorStep;								//var int FastCursorStep;
	UPROPERTY(globalconfig)								int32 MaxSimultaneousPings;							//var globalconfig int MaxSimultaneousPings;
	UPROPERTY()											float FastCursorFade;								//var float FastCursorFade;
	UPROPERTY()											float CursorFade;									//var float CursorFade;
	UPROPERTY()											float RepeatTime;									//var float RepeatTime;
	UPROPERTY()											float RepeatDelta;									//var float RepeatDelta;
	UPROPERTY()											float ButtonRepeatDelay;							//var float ButtonRepeatDelay;
	UPROPERTY()											float LastClickTime;								//var float LastClickTime;
	UPROPERTY()											float DblClickWindow;								//var float DblClickWindow;
	UPROPERTY()											float LastMouseY;									//var float LastMouseY;
	UPROPERTY()											float LastMouseX;									//var float LastMouseX;
	UPROPERTY()											float MouseY;										//var float MouseY;
	UPROPERTY()											float MouseX;										//var float MouseX;
	UPROPERTY(config)									float MenuMouseSens;								//var config float MenuMouseSens;
	UPROPERTY()											TArray<FDesignModeHint> DesignModeHints;			//var array<DesignModeHint> DesignModeHints;
	UPROPERTY()											TArray<FRestoreMenuItem> RestoreMenus;				//var array<RestoreMenuItem> RestoreMenus;
	UPROPERTY(config)									TArray<FAutoLoadMenu> AutoLoad;						//var config array<AutoLoadMenu> AutoLoad;
	UPROPERTY()											TArray<FString> StyleNames;							//var TArray<FString> StyleNames;
	UPROPERTY()											TArray<FString> DefaultStyleNames;					//var TArray<FString> DefaultStyleNames;
	UPROPERTY()											TArray<UMaterialInstance*> ImageList;				//var array<Material> ImageList;
	UPROPERTY()											TArray<UMaterialInstance*> MouseCursors;			//var array<Material> MouseCursors;
	UPROPERTY()											TArray<UGUIStyles*> StyleStack;						//var array<GUIStyles> StyleStack;
	UPROPERTY()											TArray<UGUIFont*> FontStack;							//var array<GUIFont> FontStack;
	UPROPERTY()											TArray<UGUIPage*> PersistentStack;					//var array<GUIPage> PersistentStack;
	UPROPERTY()											TArray<UGUIPage*> MenuStack;							//var array<GUIPage> MenuStack;
	UPROPERTY()											TArray<FVector> MouseCursorOffset;					//var array<Vector> MouseCursorOffset;
	UPROPERTY()											FFloatBox MouseCursorBounds;							//var const Object.FloatBox MouseCursorBounds;
	UPROPERTY()											TArray<FProfileStruct> Profilers;					//var array<ProfileStruct> Profilers;
	UPROPERTY()											int32 CURSOR_NUM;									//var const int CURSOR_NUM;
	UPROPERTY()											int32 STYLE_NUM;									//var const int STYLE_NUM;
	UPROPERTY()											int32 FONT_NUM;										//var const int FONT_NUM;

	bool OnNeedRawKeyPress(uint8 NewKey);
	void AddBuddy(FString NewBuddyName);
	UGUIFont* GetMenuFont(FString FontName);
	UGUIStyles* GetStyle(FString StyleName, EeFontScale& FontScale);
	FString GetCurrentRes();
	bool SetRenderDevice(FString NewRenderDevice);
	void ResetDesigner();
	void ResetInput();
	void GetProfileList(FString Prefix, TArray<FString>& ProfileList);
	void ResetKeyboard();
	void GetOGGList(TArray<FString>& OGGFiles);
	void PlayInterfaceSound(EClickSound SoundType);
	void SetMoveControl(UGUIComponent* C);
	void Profile(FString ProfileName);
	void GetDEMList(TArray<FString>& DEMFiles);
	bool GetDEMHeader(FString DemoName, FString& MapName, FString& GameType, int32& ScoreLimit, int32& TimeLimit, int32& ClientSide, FString& RecordedBy, FString& TimeStamp, FString& ReqPackages);
	void GetOwnageList(TArray<int32>& RLevel, TArray<FString>& MNames, TArray<FString>& mDesc, TArray<FString>& mURL);
	void SaveOwnageList(TArray<FeOwnageMap> Maps);
	void GetWeaponList(TArray<AWeapon*>& WeaponClass, TArray<FString>& WeaponDesc);
	void GetMapList(FString Prefix, UGUIList* List, bool bDecoText);
	void LaunchURL(FString URL);
	bool CheckFirewall();
	bool AuthroizeFirewall();
	bool CheckForECE();
	FString LoadDecoText(FString PackageName, FString DecoTextName);
	void GetTeamSymbolList(TArray<FString>& SymbolNames, bool bNoSinglePlayer);
	UGUIPage* TopPage();
	void InitializeController();
	void PrecachePlayerRecords();
	bool RegisterStyle(UGUIStyles* StyleClass, bool bTemporary);
	UGUIComponent* AddComponentClass(FString ClassName);
	UGUIPage* FindPersistentMenuByName(FString MenuClass);
	int32 FindMenuIndexByName(FString MenuClass);
	int32 FindMenuIndex(UGUIPage* Menu);
	int32 FindPersistentMenuIndex(UGUIPage* Menu);
	UGUIPage* FindPersistentMenuByClass(UGUIPage* PageClass);
	UGUIPage* FindMenuByClass(UGUIPage* PageClass);
	UGUIPage* CreateMenu(FString NewMenuName);
	bool OpenMenu(FString NewMenuName, FString Param1, FString Param2);
	void AutoLoadMenus();
	bool ReplaceMenu(FString NewMenuName, FString Param1, FString Param2, bool bCancelled);
	void PushMenu(int32 Index, UGUIPage* NewMenu, FString Param1, FString Param2);
	void PopMenu(int32 Index, UGUIPage* CurMenu, bool bCancelled);
	bool RemoveMenuAt(int32 Index, bool bCancelled);
	bool RemoveMenu(UGUIPage* Menu, bool bCancelled);
	bool CloseMenu(bool bCancelled);
	void CloseAll(bool bCancel, bool bForced);
	int32 Count();
	void SaveRestorePages();
	void PerformRestore();
	void SetControllerStatus(bool On);
	void ChangeFocus(UGUIComponent* Who);
	void ResetFocus();
	void MoveFocused(UGUIComponent* C, int32 bmLeft, int32 bmTop, int32 bmWidth, int32 bmHeight, float ClipX, float ClipY, float Val);
	bool HasMouseMoved(float ErrorMargin);
	bool CanShowHints();
	bool NeedsMenuResolution();
	void SetRequiredGameResolution(FString GameRes);
	void NotifyLevelChange();
	void CloseOverlays();
	void VerifyStack();
	void PurgeObjectReferences();
	void PurgeComponentClasses();
	void ConsolidateMenus();
	void Validate();
	FString GetMainMenuClass();
	FString GetSinglePlayerPage();
	FString GetServerBrowserPage();
	FString GetMultiplayerPage();
	FString GetInstantActionPage();
	FString GetModPage();
	FString GetSettingsPage();
	FString GetQuitPage();
	bool SetKeyBind(FString BindKeyName, FString BindKeyValue);
	bool KeyNameFromIndex(uint8 iKey, FString& KeyName, FString& LocalizedKeyName);
	bool GetCurrentBind(FString BindKeyName, FString& BindKeyValue);
	bool GetAssignedKeys(FString BindAlias, TArray<FString>& BindKeyNames, TArray<FString>& LocalizedBindKeyNames);
	bool SearchBinds(FString BindAliasMask, TArray<FString>& BindAliases);
	bool KeyPressed(EInputKey iKey);
	UGUIQuestionPage* ShowQuestionDialog(FString Question, uint8 Buttons, uint8 defButton);
	int32 GetMenuStackSize();
	bool RefreshMenus();
};
