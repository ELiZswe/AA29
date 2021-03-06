// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "GUIContextMenu.generated.h"

class UGUIStyles;
UCLASS()
class UGUIContextMenu : public UGUIComponent
{
	GENERATED_BODY()
public:
	UGUIContextMenu();

	UPROPERTY()				int32				ItemHeight;				//var int ItemHeight;
	UPROPERTY()				UGUIStyles*			SelectionStyle;			//var GUIStyles SelectionStyle;
	UPROPERTY()				FString				SelectionStyleName;		//var string SelectionStyleName;
	UPROPERTY()				int32				ItemIndex;				//var int ItemIndex;
	UPROPERTY()				TArray<FString>		ContextItems;			//var localized TArray<FString> ContextItems;

	void OnOpen(UGUIContextMenu* Sender);
	void OnClose(UGUIContextMenu* Sender);
	void OnSelect(UGUIContextMenu* Sender, int32 ClickIndex);
	void OnContextHitTest(float MouseX, float MouseY);
	int32 addItem(FString NewItem);
	int32 InsertItem(FString NewItem, int32 Index);
	bool RemoveItemByName(FString ItemName);
	bool RemoveItemByIndex(int32 Index);
	bool ReplaceItem(int32 Index, FString NewItem);
};
