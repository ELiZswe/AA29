// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "GUIMultiColumnListHeader.generated.h"

class UGUIStyles;
class UGUIMultiColumnList;
class UGUIController;
class UGUIComponent;

/**
 * 
 */
UCLASS()
class AA29_API UGUIMultiColumnListHeader : public UGUIComponent
{
	GENERATED_BODY()
public:
	UGUIMultiColumnListHeader();

	UPROPERTY()											bool bDrawHeaderBar;									//var bool bDrawHeaderBar;
	UPROPERTY()											FString BarStyleName;									//var string BarStyleName;
	UPROPERTY()											UGUIStyles* BarStyle;									//var GUIStyles BarStyle;
	UPROPERTY(EditAnywhere)								int32 ClickingCol;										//var() const editconst int ClickingCol;
	UPROPERTY(EditAnywhere)								int32 SizingCol;										//var() const editconst int SizingCol;
	UPROPERTY(EditAnywhere)								UGUIMultiColumnList* MyList;							//var() GUIMultiColumnList MyList;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
};
