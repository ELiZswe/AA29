// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/LargeWindow.h"
#include "AABrowser_FilterListPage.generated.h"

class UGUIImage;
class UGUIButton;
class UGUIMultiOptionListBox;
class UGUIMultiOptionList;
class UBrowserFilters;

UCLASS()
class AA29_API UAABrowser_FilterListPage : public ULargeWindow
{
	GENERATED_BODY()
public:
	UAABrowser_FilterListPage();

	UPROPERTY(EditAnywhere)		UGUIImage*					i_Background;	//var() automated XInterface.GUIImage i_Background;
	UPROPERTY(EditAnywhere)		UGUIButton*					b_Create;		//var() automated XInterface.GUIButton b_Create;
	UPROPERTY(EditAnywhere)		UGUIButton*					b_Remove;		//var() automated XInterface.GUIButton b_Remove;
	UPROPERTY(EditAnywhere)		UGUIButton*					b_Edit;			//var() automated XInterface.GUIButton b_Edit;
	UPROPERTY(EditAnywhere)		UGUIButton*					b_OK;			//var() automated XInterface.GUIButton b_OK;
	UPROPERTY(EditAnywhere)		UGUIButton*					b_Cancel;		//var() automated XInterface.GUIButton b_Cancel;
	UPROPERTY(EditAnywhere)		UGUIMultiOptionListBox*		lb_Filters;		//var() automated XInterface.GUIMultiOptionListBox lb_Filters;
	UPROPERTY(EditAnywhere)		UGUIMultiOptionList*		li_Filters;		//var XInterface.GUIMultiOptionList li_Filters;
	UPROPERTY()					UBrowserFilters*			FM;				//var BrowserFilters FM;
	UPROPERTY()					FString						CantRemove;		//var localized FString CantRemove;

	void InitComponent(UGUIController* MyC, UGUIComponent* MyO);
	void InitFilterList();
	void FilterChange(UGUIComponent* Sender);
	bool OkClick(UGUIComponent* Sender);
	bool CancelClick(UGUIComponent* Sender);
};
