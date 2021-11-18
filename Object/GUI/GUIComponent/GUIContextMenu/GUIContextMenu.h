// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "GUIContextMenu.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUIContextMenu : public UGUIComponent
{
	GENERATED_BODY()
public:
	UGUIContextMenu();


	UPROPERTY()										int32 ItemHeight;							//var int ItemHeight;
	UPROPERTY()										UGUIStyles* SelectionStyle;					//var GUIStyles SelectionStyle;
	UPROPERTY()										FString SelectionStyleName;					//var string SelectionStyleName;
	UPROPERTY()										int32 ItemIndex;							//var int ItemIndex;
	UPROPERTY()										TArray<FString> ContextItems;				//var localized array<String> ContextItems;


	void OnOpen(UGUIContextMenu* Sender);
	void OnClose(UGUIContextMenu* Sender);
	void OnSelect(UGUIContextMenu* Sender, int32 ClickIndex);
	void OnContextHitTest(float MouseX, float MouseY);
	void addItem(FString NewItem);
	void InsertItem(FString NewItem, int32 Index);
	void RemoveItemByName(FString ItemName);
	void RemoveItemByIndex(int32 Index);
	void ReplaceItem(int32 Index, FString NewItem);

};
