// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/PopupPageBase.h"
#include "FloatingWindow.generated.h"

class UGUIHeader;
class UGUIButton;

UCLASS()
class AA29_API UFloatingWindow : public UPopupPageBase
{
	GENERATED_BODY()
public:
	UFloatingWindow();

	UPROPERTY(EditAnywhere)				UGUIHeader*		t_WindowTitle;				//var() automated XInterface.GUIHeader t_WindowTitle;
	UPROPERTY(EditAnywhere)				UGUIButton*		b_ExitButton;				//var() XInterface.GUIButton b_ExitButton;
	UPROPERTY(EditAnywhere)				FString			WindowName;					//var() localized FString WindowName;
	UPROPERTY(EditAnywhere)				float			MinPageWidth;				//var() float MinPageWidth;
	UPROPERTY(EditAnywhere)				float			MinPageHeight;				//var() float MinPageHeight;
	UPROPERTY(EditAnywhere)				float			MaxPageHeight;				//var() float MaxPageHeight;
	UPROPERTY(EditAnywhere)				float			MaxPageWidth;				//var() float MaxPageWidth;
	UPROPERTY(EditAnywhere)				bool			bResizeWidthAllowed;		//var() editconst bool bResizeWidthAllowed;
	UPROPERTY(EditAnywhere)				bool			bResizeHeightAllowed;		//var() editconst bool bResizeHeightAllowed;
	UPROPERTY(EditAnywhere)				bool			bResizing;					//var() editconst bool bResizing;
	UPROPERTY(EditAnywhere)				bool			bMoveAllowed;				//var() editconst bool bMoveAllowed;
	UPROPERTY(EditAnywhere)				bool			bMoving;					//var() editconst bool bMoving;
	UPROPERTY(EditAnywhere)				bool			TSizing;					//var() editconst bool TSizing;
	UPROPERTY(EditAnywhere)				bool			RSizing;					//var() editconst bool RSizing;
	UPROPERTY(EditAnywhere)				bool			LSizing;					//var() editconst bool LSizing;
	UPROPERTY(EditAnywhere)				bool			BtSizing;					//var() editconst bool BtSizing;
	UPROPERTY(EditAnywhere)				bool			TLSizing;					//var() editconst bool TLSizing;
	UPROPERTY(EditAnywhere)				bool			TRSizing;					//var() editconst bool TRSizing;
	UPROPERTY(EditAnywhere)				bool			BRSizing;					//var() editconst bool BRSizing;
	UPROPERTY(EditAnywhere)				bool			BLSizing;					//var() editconst bool BLSizing;
	UPROPERTY(EditAnywhere)				float			DefaultLeft;				//var() config float DefaultLeft;
	UPROPERTY(EditAnywhere)				float			DefaultTop;					//var() config float DefaultTop;
	UPROPERTY(EditAnywhere)				float			DefaultWidth;				//var() config float DefaultWidth;
	UPROPERTY(EditAnywhere)				float			DefaultHeight;				//var() config float DefaultHeight;
	UPROPERTY(EditAnywhere)				int32			HeaderMouseCursorIndex;		//var() int32 HeaderMouseCursorIndex;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool AlignFrame(UCanvas* C);
	void AddSystemMenu();
	bool SystemMenuPreDraw(UCanvas* Canvas);
	void CheckBounds();
	void SetDefaultPosition();
	void InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender);
	void SetFocus(UGUIComponent* Who);
	void FloatingMousePressed(UGUIComponent* Sender, bool bRepeat);
	void FloatingMouseRelease(UGUIComponent* Sender);
	void SaveCurrentPosition();
	bool FloatingHover(UGUIComponent* Sender);
	void SetPanelPosition(UCanvas* C);
	bool FloatingPreDraw(UCanvas* C);
	void FloatingRendered(UCanvas* C);
	void ResolutionChanged(int32 ResX, int32 ResY);
	void ResizedBoth();
	void ResizedWidth();
	void ResizedHeight();
	bool ResizeAllowed();
	bool HoveringLeftBorder();
	bool HoveringRightBorder();
	bool HoveringTopBorder();
	bool HoveringBottomBorder();
	bool HoveringTopLeft();
	bool HoveringBottomLeft();
	bool XButtonClicked(UGUIComponent* Sender);
	void SetMouseCursorIndex(int32 NewIndex);
};
