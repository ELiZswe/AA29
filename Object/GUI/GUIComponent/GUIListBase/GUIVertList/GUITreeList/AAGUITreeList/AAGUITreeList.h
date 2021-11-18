// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUITreeList/GUITreeList.h"
#include "AAGUITreeList.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAAGUITreeList : public UGUITreeList
{
	GENERATED_BODY()
public:
	UAAGUITreeList();


	UPROPERTY()										FString				ItemStyleName;					//var string ItemStyleName;
	UPROPERTY(EditAnywhere, Category = "Style")		UGUIStyles*			ItemStyle;						//var(Style) XInterface.GUIStyles ItemStyle;
	UPROPERTY()										FString				CategoryStyleName;				//var string CategoryStyleName;
	UPROPERTY(EditAnywhere, Category = "Style")		UGUIStyles*			CategoryStyle;					//var(Style) XInterface.GUIStyles CategoryStyle;
	UPROPERTY()										UMaterialInstance*	ExpandedIcon;					//var Material ExpandedIcon;
	UPROPERTY()										UMaterialInstance*	CollapsedIcon;					//var Material CollapsedIcon;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool IsToggleClick(int32 idx);
	float MyGetItemHeight(UCanvas* C);
	void MyOnDrawItem(UCanvas* Canvas, int32 Item, float X, float Y, float W, float HT, bool bSelected, bool bPending);
};
