// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/GUIMultiColumnList.h"
#include "ServerBrowserMCList.generated.h"

class UGUIStyles;
class UGUIComponent;
class UGUIController;

UCLASS()
class AA29_API UServerBrowserMCList : public UGUIMultiColumnList
{
	GENERATED_BODY()
public:
	UServerBrowserMCList();

	UPROPERTY(EditAnywhere, Category = "Style")						FString FavoritesStyleName;											//var(Style) string FavoritesStyleName;
	UPROPERTY(EditAnywhere, Category = "Style")						UGUIStyles* FavoritesStyle;											//var(Style) XInterface.GUIStyles FavoritesStyle;

	void InitComponent(UGUIController* InController, UGUIComponent* InOwner);
	void MyOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending);

};
