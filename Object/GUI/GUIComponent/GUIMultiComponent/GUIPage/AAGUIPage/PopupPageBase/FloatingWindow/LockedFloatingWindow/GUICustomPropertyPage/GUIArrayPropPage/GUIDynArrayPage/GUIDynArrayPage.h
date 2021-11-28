// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LockedFloatingWindow/GUICustomPropertyPage/GUIArrayPropPage/GUIArrayPropPage.h"
#include "GUIDynArrayPage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUIDynArrayPage : public UGUIArrayPropPage
{
	GENERATED_BODY()
public:
	UGUIDynArrayPage();

	UPROPERTY(EditAnywhere)					TArray<FArrayControl>		ArrayButton;				//var() TArray<ArrayControl> ArrayButton;
	UPROPERTY(EditAnywhere)					FString						SizingCaption;				//var() FString SizingCaption;
	UPROPERTY(EditAnywhere)					FString						NewText;					//var() localized FString NewText;
	UPROPERTY(EditAnywhere)					FString						RemoveText;					//var() localized FString RemoveText;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InitializeList();
	FArrayControl AddButton(int32 Index);
	void Clear();
	void UpdateButtons();
	void SetElementState(int32 Index, bool bNewOn, bool bRemoveOn);
	void SetElementCaption(int32 ButtonArrayIndex, int32 ListElementIndex);
	bool InternalOnClick(UGUIComponent* Sender);
	void InternalOnAdjustTop(UGUIComponent* Sender);
	bool FloatingPreDraw(UCanvas* C);
};
