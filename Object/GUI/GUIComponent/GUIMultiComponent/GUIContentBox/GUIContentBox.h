// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMultiComponent.h"
#include "GUIContentBox.generated.h"

class UGUIContentPanel;
class UGUIScrollBarBase;
class UGUIContentBoxHeader;
class UGUIComponent;

UCLASS()
class AA29_API UGUIContentBox : public UGUIMultiComponent
{
	GENERATED_BODY()
public:
	UGUIContentBox();

	UPROPERTY(EditAnywhere)			TArray<float>							ColumnWidths;			//var() array<float> ColumnWidths;
	UPROPERTY(EditAnywhere)			TArray<FString>							ColumnHeadings;			//var() array<String> ColumnHeadings;
	UPROPERTY(EditAnywhere)			float									SideGaps;				//var() float SideGaps;
	UPROPERTY(EditAnywhere)			bool									bNoScrollBar;			//var() bool bNoScrollBar;
	UPROPERTY(EditAnywhere)			bool									bScaleItemsToWidth;		//var() bool bScaleItemsToWidth;
	UPROPERTY(EditAnywhere)			bool									bCenterItems;			//var() bool bCenterItems;
	UPROPERTY(EditAnywhere)			float									ItemSpacing;			//var() float ItemSpacing;
	UPROPERTY()						UGUIContentPanel*						MyPanel;				//var GUIContentPanel MyPanel;
	UPROPERTY(EditAnywhere)			FString									DefaultPanelClass;		//var() string DefaultPanelClass;
	UPROPERTY(EditAnywhere)			UGUIScrollBarBase*						MyScrollBar;			//var() XInterface.GUIScrollBarBase MyScrollBar;
	UPROPERTY(EditAnywhere)			UGUIContentBoxHeader*					MyHeader;				//var() GUIContentBoxHeader MyHeader;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void addItem(FString NewClass);
	void AppendItem(UGUIComponent* NewComp);
	void InsertItem(UGUIComponent* NewComp, int idx);
	void RemoveItem(UGUIComponent* Comp);
	void RemoveAllComponents();
};
