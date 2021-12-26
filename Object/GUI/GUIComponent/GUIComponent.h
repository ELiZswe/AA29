// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUI.h"
#include "AA29/AA29.h"
#include "GUIComponent.generated.h"

class UGUIController;
class UGUIStyles;
class UGUIToolTip;
class UGUIPage;
class UGUILabel;
class UGUIContextMenu;

UCLASS()
class UGUIComponent : public UGUI
{
	GENERATED_BODY()
public:
	UGUIComponent();

	UPROPERTY()														int32 OnDrawCount;									//var editconst int OnDrawCount;
	UPROPERTY()														int32 OnPreDrawCount;								//var editconst int OnPreDrawCount;
	UPROPERTY()														int32 OnRenderedCount;								//var editconst int OnRenderedCount;
	UPROPERTY()														int32 OnRenderCount;								//var editconst int OnRenderCount;
	UPROPERTY()														int32 DrawCount;									//var const editconst int DrawCount;
	UPROPERTY()														int32 PreDrawCount;									//var const editconst int PreDrawCount;
	UPROPERTY()														bool bUseDynamicBorderOffsets;						//var bool bUseDynamicBorderOffsets;
	UPROPERTY()														float DynamicBorderOffsets;							//var float DynamicBorderOffsets;
	UPROPERTY(EditAnywhere, Category = "Menu")						float StandardHeight;								//var(Menu) float StandardHeight;
	UPROPERTY(EditAnywhere, Category = "Menu")						bool bStandardized;									//var(Menu) bool bStandardized;
	UPROPERTY(EditAnywhere)											EParentScaleType ScalingType;						//var() EParentScaleType ScalingType;
	UPROPERTY(EditAnywhere)											EParentScaleType BoundingType;						//var() EParentScaleType BoundingType;
	UPROPERTY(EditAnywhere, Category = "State")						EClickSound OnClickSound;							//var(Style) EClickSound OnClickSound;
	UPROPERTY(EditAnywhere, Category = "State")						UGUIStyles* Style;									//var(Style) GUIStyles Style;
	UPROPERTY()														FColor WhiteColor;									//var const Object.Color WhiteColor;
	UPROPERTY(EditAnywhere)											UGUIToolTip* ToolTip;								//var() editconst GUIToolTip ToolTip;
	UPROPERTY(EditAnywhere)											UGUIContextMenu* ContextMenu;						//var() editconst GUIContextMenu ContextMenu;
	UPROPERTY()														float MouseOffset;									//var const float MouseOffset;
	UPROPERTY(EditAnywhere)											float TimerInterval;								//var() float TimerInterval;
	UPROPERTY(EditAnywhere)											float TimerCountdown;								//var() float TimerCountdown;
	UPROPERTY(EditAnywhere)											int32 TimerIndex;									//var() const editconst int TimerIndex;
	UPROPERTY(EditAnywhere)											bool bTimerRepeat;									//var() bool bTimerRepeat;
	UPROPERTY(EditAnywhere, Category = "Menu")						float ClientBounds;									//var(Menu) const editconst float ClientBounds;
	UPROPERTY(EditAnywhere, Category = "Menu")						float Bounds;										//var(Menu) const editconst float Bounds;
	UPROPERTY(EditAnywhere)											TArray<FVector> SizeFrame;							//var() const editconst array<Vector> SizeFrame;
	UPROPERTY(EditAnywhere)											TArray<FVector> MotionFrame;						//var() const editconst array<Vector> MotionFrame;
	UPROPERTY(EditAnywhere)											bool bSizing;										//var() const editconst bool bSizing;
	UPROPERTY(EditAnywhere)											bool bTravelling;									//var() const editconst bool bTravelling;
	UPROPERTY(EditAnywhere)											bool bAnimating;									//var() editconst bool bAnimating;
	UPROPERTY(EditAnywhere)											bool bPositioned;									//var() const editconst bool bPositioned;
	UPROPERTY()														bool bRequiresStyle;								//var const bool bRequiresStyle;
	UPROPERTY(EditAnywhere)											bool bNeverScale;									//var() bool bNeverScale;
	UPROPERTY(EditAnywhere)											bool bInit;											//var() bool bInit;
	UPROPERTY(EditAnywhere, Category = "State")						bool bPendingFocus;									//var(State) bool bPendingFocus;
	UPROPERTY(EditAnywhere)											bool bDropTarget;									//var() bool bDropTarget;
	UPROPERTY(EditAnywhere)											bool bDropSource;									//var() bool bDropSource;
	UPROPERTY(EditAnywhere)											bool bMouseOverSound;								//var() bool bMouseOverSound;
	UPROPERTY(EditAnywhere, Category = "State")						bool bRequireReleaseClick;							//var(State) bool bRequireReleaseClick;
	UPROPERTY(EditAnywhere, Category = "State")						bool bRepeatClick;									//var(State) bool bRepeatClick;
	UPROPERTY(EditAnywhere, Category = "State")						bool bNeverFocus;									//var(State) bool bNeverFocus;
	UPROPERTY(EditAnywhere, Category = "State")						bool bCaptureMouse;									//var(State) bool bCaptureMouse;
	UPROPERTY(EditAnywhere)											bool bCaptureTabs;									//var() bool bCaptureTabs;
	UPROPERTY(EditAnywhere, Category = "State")						bool bAcceptsInput;									//var(State) bool bAcceptsInput;
	UPROPERTY(EditAnywhere, Category = "State")						bool bVisible;										//var(State) bool bVisible;
	UPROPERTY(EditAnywhere, Category = "State")						bool bHasFocus;										//var(State) bool bHasFocus;
	UPROPERTY(EditAnywhere, Category = "Menu")						bool bScaleToParent;								//var(Menu) bool bScaleToParent;
	UPROPERTY(EditAnywhere, Category = "Menu")						bool bBoundToParent;								//var(Menu) bool bBoundToParent;
	UPROPERTY(EditAnywhere)											bool bFocusOnWatch;									//var() bool bFocusOnWatch;
	UPROPERTY(EditAnywhere, Category = "Menu")						bool bTabStop;										//var(Menu) bool bTabStop;
	UPROPERTY(EditAnywhere)											bool bDebugging;									//var() bool bDebugging;
	UPROPERTY(EditAnywhere)											int32 Tag;											//var() int Tag;
	UPROPERTY(EditAnywhere, Category = "Menu")						int32 TabOrder;										//var(Menu) int TabOrder;
	UPROPERTY(EditAnywhere, Category = "State")						int32 MouseCursorIndex;								//var(Style) int MouseCursorIndex;
	UPROPERTY(EditAnywhere)											float RenderWeight;									//var() float RenderWeight;
	UPROPERTY(EditAnywhere, Category = "Menu")						float WinHeight;									//var(Menu) float WinHeight;
	UPROPERTY(EditAnywhere, Category = "Menu")						float WinWidth;										//var(Menu) float WinWidth;
	UPROPERTY(EditAnywhere, Category = "Menu")						float WinLeft;										//var(Menu) float WinLeft;
	UPROPERTY(EditAnywhere, Category = "Menu")						float WinTop;										//var(Menu) float WinTop;
	UPROPERTY(EditAnywhere)											UGUILabel* FriendlyLabel;								//var() GUILabel FriendlyLabel;
	UPROPERTY(EditAnywhere)											FString Hint;										//var() localized string Hint;
	UPROPERTY(EditAnywhere, Category = "State")						FString StyleName;									//var(Style) string StyleName;
	UPROPERTY(EditAnywhere)											FString IniDefault;									//var() string IniDefault;
	UPROPERTY(EditAnywhere)											FString IniOption;									//var() string IniOption;
	UPROPERTY(EditAnywhere, Category = "State")						EFontScale FontScale;								//var(Style) GUI.eFontScale FontScale;
	UPROPERTY(EditAnywhere, Category = "State")						EFontScale DropState;								//var(State) GUI.eDropState DropState;
	UPROPERTY(EditAnywhere, Category = "State")						EMenuState LastMenuState;							//var(State) editconst GUI.eMenuState LastMenuState;
	UPROPERTY(EditAnywhere, Category = "State")						EMenuState MenuState;								//var(State) GUI.eMenuState MenuState;
	UPROPERTY(EditAnywhere, Category = "State")						UGUIComponent* FocusInstead;						//var(State) GUIComponent FocusInstead;
	UPROPERTY(EditAnywhere, Category = "Menu")						UGUIComponent* MenuOwner;							//var(Menu) editconst GUIComponent MenuOwner;
	UPROPERTY(EditAnywhere, Category = "Menu")						UGUIPage* PageOwner;								//var(Menu) editconst GUIPage PageOwner;

	void OnArrival(UGUIComponent* Sender, EAnimationType Type);
	void OnEndAnimation(UGUIComponent* Sender, EAnimationType Type);
	bool OnPreDraw(UCanvas* Canvas);
	bool OnDraw(UCanvas* Canvas);
	void OnRender(UCanvas* Canvas);
	void OnRendered(UCanvas* Canvas);
	void OnActivate();
	void OnDeActivate();
	void OnWatch();
	void OnHitTest(float MouseX, float MouseY);
	void OnMessage(FString Msg, float MsgLife);
	void OnHide();
	void OnShow();
	bool OnBeginTooltip();
	bool OnEndTooltip();
	void OnInvalidate(UGUIComponent* Who);
	bool OnHover(UGUIComponent* Sender);
	void OnClick(UGUIComponent* Sender);
	void OnDblClick(UGUIComponent* Sender);
	void OnRightClick(UGUIComponent* Sender);
	void OnMousePressed(UGUIComponent* Sender, bool bRepeat);
	void OnMouseRelease(UGUIComponent* Sender);
	void OnTimer(UGUIComponent* Sender);
	void OnChange(UGUIComponent* Sender);
	bool OnKeyType(uint8& Key, FString Unicode);
	bool OnKeyEvent(uint8& Key, uint8& State, float Delta);
	bool OnDesignModeKeyEvent(EInputKey Key, EInputAction State);
	bool OnCapturedMouseMove(float deltaX, float deltaY);
	void OnLoadINI(UGUIComponent* Sender, FString S);
	FString OnSaveINI(UGUIComponent* Sender);
	bool OnMultiSelect(UGUIComponent* Sender);
	bool OnBeginDrag(UGUIComponent* Sender);
	void OnEndDrag(UGUIComponent* Sender, bool bAccepted);
	bool OnDragDrop(UGUIComponent* Sender);
	void OnDragEnter(UGUIComponent* Sender);
	void OnDragLeave(UGUIComponent* Sender);
	void OnDragOver(UGUIComponent* Sender);
	void PlayerOwner();
	void SetTimer(float Interval, bool bRepeat);
	void KillTimer();
	void AutoPosition(TArray<UGUIComponent*> Components, float LeftBound, float UpperBound, float RightBound, float LowerBound, float LeftPad, float UpperPad, float RightPad, float LowerPad, int32 NumberOfColumns, float ColumnPadding);
	void AutoPositionOn(TArray<UGUIComponent*> Components, UGUIComponent* frame, float LeftPadPerc, float UpperPadPerc, float RightPadPerc, float LowerPadPerc, int32 NumberOfColumns, float ColumnPadding);
	void UpdateOffset(float PosX, float PosY, float PosW, float PosH);
	float ActualWidth(float Val, bool bForce);
	float ActualHeight(float Val, bool bForce);
	void ActualLeft(float Val, bool bForce);
	void ActualTop(float Val, bool bForce);
	void RelativeLeft(float RealLeft, bool bForce);
	void RelativeTop(float RealTop, bool bForce);
	void RelativeWidth(float RealWidth, bool bForce);
	void RelativeHeight(float RealHeight, bool bForce);
	void GetMenuPath();
	void SpecialHit(bool bForce);
	void ResolutionChanged(int32 ResX, int32 ResY);
	void SetPosition(float NewLeft, float NewTop, float NewWidth, float NewHeight, bool bForceRelative);
	FString AdditionalDebugString();
	void Timer();
	void Opened(UGUIComponent* Sender);
	void Closed(UGUIComponent* Sender, bool bCancelled);
	void Free();
	FString LoadINI();
	void SaveINI(FString Value);
	FString StripColorCodes(FString InString);
	FString MakeColorCode(FColor NewColor);
	void MenuStateChange(EMenuState NewState);
	bool IsMultiSelect();
	void DropStateChange(EDropState NewState);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool IsInBounds();
	bool IsInClientBounds();
	bool CanAcceptFocus();
	void SetFocus(UGUIComponent* Who);
	void LoseFocus(UGUIComponent* Sender);
	bool FocusFirst(UGUIComponent* Sender);
	bool FocusLast(UGUIComponent* Sender);
	bool NextControl(UGUIComponent* Sender);
	bool PrevControl(UGUIComponent* Sender);
	bool NextPage();
	bool PrevPage();
	void FillOwner();
	void SetVisibility(bool bIsVisible);
	void CenterMouse();
	void Hide();
	void Show();
	void SetFocusInstead(UGUIComponent* InFocusComp);
	//void SetFriendlyLabel(UGUILabel* NewLabel);
	void SetHint(FString NewHint);
	void SetToolTipText(FString NewToolTipText);
	//void SetTooltip(UGUIToolTip* InTooltip);
	void PadLeft(FString &Src, int32 StrLen, FString PadStr);
	void PadRight(FString &Src, int32 StrLen, FString PadStr);
	void DebugFocus(UGUIComponent* Who, bool bLose);
	void DebugFocusPosition(UGUIComponent* Who, bool Last);
	UGUIPage* OwnerPage();
	void BeginAnimation(UGUIComponent* Animating);
	void EndAnimation(UGUIComponent* Animating, EAnimationType Type);
	void Animate(float NewLeft, float NewTop, float Time);
	void Resize(float NewWidth, float NewHeight, float Time);
	void DAnimate(float NewLeft, float NewTop, float NewWidth, float NewHeight, float PositionTime, float DimensionTime);
	void KillAnimation();
	void EnableComponent(UGUIComponent* Comp);
	void DisableComponent(UGUIComponent* Comp);
	void EnableMe();
	void DisableMe();
	void LevelChanged();
	void DebugTabOrder();

};
