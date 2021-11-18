// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMultiComponent.h"
#include "GUITabControl.generated.h"

class UGUITabButton;
class UGUIStyles;
class UGUIBorder;
class UGUITabPanel;

UCLASS()
class AA29_API UGUITabControl : public UGUIMultiComponent
{
	GENERATED_BODY()
public:
	UGUITabControl();

	UPROPERTY(EditAnywhere)									bool					bFillSpace;					//var() bool bFillSpace;
	UPROPERTY(EditAnywhere)									bool					bDockPanels;				//var() bool bDockPanels;
	UPROPERTY(EditAnywhere)									bool					bDrawTabAbove;				//var() bool bDrawTabAbove;
	UPROPERTY(EditAnywhere)									bool					bFillBackground;			//var() bool bFillBackground;
	UPROPERTY(EditAnywhere)									FColor					FillColor;					//var() Color FillColor;
	UPROPERTY(EditAnywhere)									float					FadeInTime;					//var() float FadeInTime;
	UPROPERTY(EditAnywhere)									float					TabHeight;					//var() float TabHeight;
	UPROPERTY(EditAnywhere)									FString					BackgroundStyleName;		//var() FString BackgroundStyleName;
	UPROPERTY(EditAnywhere)									UMaterialInstance*		BackgroundImage;			//var() Material BackgroundImage;
	UPROPERTY(EditAnywhere)									TArray<UGUITabButton*>	TabStack;					//var() editconst noexport TArray<GUITabButton> TabStack;
	UPROPERTY(EditAnywhere)									UGUITabButton*			ActiveTab;					//var() editconst noexport GUITabButton ActiveTab;
	UPROPERTY(EditAnywhere)									UGUITabButton*			PendingTab;					//var() editconst noexport GUITabButton PendingTab;
	UPROPERTY(EditAnywhere)									UGUIStyles*				BackgroundStyle;			//var() editconst noexport GUIStyles BackgroundStyle;
	UPROPERTY(EditAnywhere)									UGUIBorder*				MyFooter;					//var() editconst noexport GUIBorder MyFooter;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Opened(UGUIComponent* Sender);
	void Closed(UGUIComponent* Sender, bool bCancelled);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
	UGUITabPanel* AddTabItem(FGUITabItem Item);
	UGUITabPanel* AddTab(FString InCaption, FString PanelClass, UGUITabPanel* ExistingPanel, FString InHint, bool bForceActive);
	UGUITabPanel* InsertTab(int32 pos, FString Caption, FString PanelClass, UGUITabPanel* ExistingPanel, FString InHint, bool bForceActive);
	UGUITabPanel* ReplaceTab(UGUITabButton* Which, FString Caption, FString PanelClass, UGUITabPanel* ExistingPanel, FString InHint, bool bForceActive);
	void RemoveTab(FString Caption, UGUITabButton* Who);
	bool LostActiveTab();
	void MakeTabActive(UGUITabButton* Who);
	bool ActivateTab(UGUITabButton* Who, bool bFocusPanel);
	bool ActivateTabByName(FString tabname, bool bFocusPanel);
	bool ActivateTabByPanel(UGUITabPanel* Panel, bool bFocusPanel);
	bool InternalTabClick(UGUIComponent* Sender);
	bool NextPage();
	bool PrevPage();
	bool NextControl(UGUIComponent* Sender);
	bool PrevControl(UGUIComponent* Sender);
	int32 TabIndex(FString tabname);
	UGUITabPanel* FindPanelClass(UGUITabPanel* PanelClass);
	UGUITabPanel* BorrowPanel(FString Caption);
	void SetVisibility(bool bIsVisible);
	void InternalOnActivate();
	bool FocusFirst(UGUIComponent* Sender);
	bool FocusLast(UGUIComponent* Sender);
	void CenterMouse();
	void Free();
	void LevelChanged();

};
