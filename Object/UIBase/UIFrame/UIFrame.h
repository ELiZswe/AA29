// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIBase.h"
#include "UIFrame.generated.h"

class UUIScreen;
class UUIControl;
class UUIInvSlotBase;
class AInvContainer;
class UUIInvDef;
class UUIMouse;
class AInventory;
class UFont;
class UUIInvList;
class AClientBeaconReceiver;
class AServerBrowserBase;
class UUIListItems;
class AAA2_HUD;

UCLASS()
class UUIFrame : public UUIBase
{
	GENERATED_BODY()
public:
	UUIFrame();

	UPROPERTY()		bool			bTestA;					//var bool bTestA;
	UPROPERTY()		bool			_bToolTipActive;		//var bool _bToolTipActive;
	UPROPERTY()		FPoint			_ScaledToolTipLoc;		//var UIBase.Point _ScaledToolTipLoc;
	UPROPERTY()		FPoint			_ToolTipLoc;			//var UIBase.Point _ToolTipLoc;
	UPROPERTY()		FPoint			offset;					//var UIBase.Point offset;
	UPROPERTY()		TArray<UFont*>	Fonts;					//var Font Fonts;
	UPROPERTY()		float			fScaleY;				//var float fScaleY;
	UPROPERTY()		float			fScaleX;				//var float fScaleX;
	UPROPERTY()		int32			_iOldSizeY;				//var int _iOldSizeY;
	UPROPERTY()		int32			_iOldSizeX;				//var int _iOldSizeX;
	UPROPERTY()		UUIControl*		_cMouseOver;			//var UIControl _cMouseOver;
	UPROPERTY()		FInvProperties	_InvItem;				//var UIBase.InvProperties _InvItem;
	UPROPERTY()		int32			_iInvSlot;				//var int _iInvSlot;
	UPROPERTY()		UUIInvSlotBase* _cInvList;				//var UIInvSlotBase _cInvList;
	UPROPERTY()		AInvContainer*	_cInvContainer;			//var InvContainer _cInvContainer;
	UPROPERTY()		AInventory*		_cInvItem;				//var Inventory _cInvItem;
	UPROPERTY()		bool			_bMessageBoxVisible;	//var bool _bMessageBoxVisible;
	UPROPERTY()		bool			_bMessageBox;			//var bool _bMessageBox;
	UPROPERTY()		UUIScreen*		cMessageBox;			//var UIScreen cMessageBox;
	UPROPERTY()		AActor*			cActor;					//var Actor cActor;
	UPROPERTY()		UUIInvDef*		cInvDef;				//var UIInvDef cInvDef;
	UPROPERTY()		AAA2_HUD*		cHUD;					//var HUD cHUD;
	UPROPERTY()		UUIMouse*		cMouse;					//var UIMouse cMouse;
	UPROPERTY()		UUIControl*		cFocus;					//var UIControl cFocus;
	UPROPERTY()		UUIScreen*		cSubScreen;				//var UIScreen cSubScreen;
	UPROPERTY()		UUIScreen*		cTitleScreen;			//var UIScreen cTitleScreen;
	UPROPERTY()		UUIScreen*		cStaticScreen;			//var UIScreen cStaticScreen;
	UPROPERTY()		UUIScreen*		cActiveScreen;			//var UIScreen cActiveScreen;
	UPROPERTY()		UUIScreen*		cScreenList;			//var UIScreen cScreenList;

	void Destroyed();
	void SetMouse(int32 mX, int32 mY);
	void ScaleControls(UCanvas* Canvas);
	void Create(AAA2_HUD* pHUD);
	bool KeyType(int32 Key);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void Notify(int32 pUIEvent);
	UUIListItems* CreateUIListItems(FString ListItemsName);
	UUIInvList* CreateUIInvList(FString ListName);
	UUIControl* CreateUIControl(FString ControlName);
	UUIMouse* CreateUIMouse(FString MouseName);
	void AddMouse(FString szMouse, int32 pX, int32 pY, int32 pW, int32 pH, FString szTex);
	void SetFocus(UUIControl* Control);
	void SetupFonts();
	UFont* GetLargeFont();
	UFont* GetProperSizeFont(UCanvas* Canvas);
	UFont* GetProperSizeFontPrivate(UCanvas* Canvas);
	void DumpScreenLog();
	void UILog(FString S);
	UUIScreen* CreateUIScreen(FString ScreenName);
	void AddScreen(int32 pID, FString Title);
	UUIScreen* GetScreen(int32 Id);
	void SetActiveScreen(int32 Id);
	void SetActiveScreen2(int32 Id);
	UUIScreen* GetActiveScreen();
	void ResetActiveScreen();
	UUIScreen* GetLastScreen();
	void AddScreenToTail(UUIScreen* screen);
	void AddStaticScreen(int32 Id);
	void RemoveStaticScreen();
	void SetTitleScreen(int32 Id);
	void RemoveTitleScreen();
	void SetSubScreen(int32 Id);
	void RemoveSubScreen();
	void SetItemID(int32 Item);
	int32 GetItemID();
	int32 GetItemSize();
	void SetItem(UUIInvSlotBase* List, int32 Slot, int32 Item);
	AInventory* GetHeldItem();
	AInvContainer* GetHeldContainer();
	void SetHeldItem(AInventory* Item);
	void SetHeldContainer(AInvContainer* container);
	void DropHeldItem();
	void ReloadWeapon();
	void Hide();
	void EnableControl(int32 Id, bool State);
	FPoint GetToolTipLocation();
	void SetToolTipLocation(FPoint pLoc);
	bool SetMouseOver(UUIControl* Control);
	float GetLastDrawTime();
	void AddMessageBox();
	UUIScreen* GetMessageBox();
	void OpenMessageBox();
	void CloseMessageBox();
	void SetMouseBusy(bool busy);
	bool IsMouseBusyDrawing();
	void PlayMenuSoundSpecific(USoundBase* Sound);
	AClientBeaconReceiver* GetClientBeacon();
	AServerBrowserBase* GetCurrentServerBrowser();
	void RunConsoleCommand(FString comm);
	void OpenQuickLan(FString serveraddr);
	void UnbindKey(int32 Key, FString Command);
	void SetResolution(int32 X, int32 Y);
	int32 GetDesiredX();
	int32 GetDesiredY();
	void SetSkinTone();
	void SetGameSpyPos(int32 pos);
	int32 GetGameSpyPos();
	void UpdateGameSpyPos(int32 pos);
	void ConnectToGameSpyServer(int32 Index);
	void SetSettingsValue(FString Value);
};
