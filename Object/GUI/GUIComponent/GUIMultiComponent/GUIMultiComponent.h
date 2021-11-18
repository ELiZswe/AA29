// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "GUIMultiComponent.generated.h"

class UGUIContextMenu;
class UGUIComponent;
class UGUIController;

/**
 * 
 */
UCLASS()
class AA29_API UGUIMultiComponent : public UGUIComponent
{
	GENERATED_BODY()
public:
	UGUIMultiComponent();

	UPROPERTY(EditAnywhere)								bool					bAlwaysAutomate;					//var() bool bAlwaysAutomate;
	UPROPERTY(EditAnywhere, Category = "State")			bool					bDrawFocusedLast;					//var(State) bool bDrawFocusedLast;
	UPROPERTY(EditAnywhere)								bool					bOldStyleMenus;						//var() bool bOldStyleMenus;
	UPROPERTY(EditAnywhere)								bool					PropagateVisibility;				//var() bool PropagateVisibility;
	UPROPERTY(EditAnywhere)								int32					AnimationCount;						//var() editconst int AnimationCount;
	UPROPERTY(EditAnywhere, Category = "Menu")			TArray<UGUIComponent*>	Components;							//var(Menu) editconstarray array<GUIComponent> Components;
	UPROPERTY(EditAnywhere, Category = "State")			UGUIComponent*			FocusedControl;						//var(State) editconst GUIComponent FocusedControl;
	UPROPERTY(EditAnywhere, Category = "Menu")			TArray<UGUIComponent*>	Controls;							//var(Menu) array<GUIComponent> Controls;

	bool HandleContextMenuOpen(UGUIComponent* Sender, UGUIContextMenu* Menu, UGUIComponent* ContextMenuOwner);
	bool HandleContextMenuClose(UGUIContextMenu* Sender);
	bool NotifyContextSelect(UGUIContextMenu* Sender, int32 ClickIndex);
	void OnCreateComponent(UGUIComponent* NewComponent, UGUIComponent* Sender);
	void InitializeControls();
	void RemapComponents();
	void FindComponentIndex(UGUIComponent* Who);
	void InternalOnShow();
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void AddComponent(FString ComponentClass, bool SkipRemap);
	UGUIComponent* InsertComponent(UGUIComponent* NewComp, int32 Index, bool SkipRemap);
	UGUIComponent* AppendComponent(UGUIComponent* NewComp, bool SkipRemap);
	bool RemoveComponent(UGUIComponent* Comp, bool SkipRemap);
	void SetFocusInstead(UGUIComponent* InFocusComp);
	void SetFocus(UGUIComponent* Who);
	void LoseFocus(UGUIComponent* Sender);
	bool CanAcceptFocus();
	bool FocusFirst(UGUIComponent* Sender);
	bool FocusLast(UGUIComponent* Sender);
	bool NextControl(UGUIComponent* Sender);
	bool PrevControl(UGUIComponent* Sender);
	void EnableMe();
	void DisableMe();
	void SetVisibility(bool bIsVisible);
	void Opened(UGUIComponent* Sender);
	void Closed(UGUIComponent* Sender, bool bCancelled);
	void Free();
	void BeginAnimation(UGUIComponent* Animating);
	void EndAnimation(UGUIComponent* Animating, EAnimationType Type);
	void LevelChanged();
	void CenterMouse();
	void DebugTabOrder();
	void CheckInvalidTabOrder();
	void CheckDuplicateTabOrder();
};
