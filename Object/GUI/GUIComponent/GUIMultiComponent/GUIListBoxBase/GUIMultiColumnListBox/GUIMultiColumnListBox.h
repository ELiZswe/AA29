// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBoxBase.h"
#include "GUIMultiColumnListBox.generated.h"

class UGUIMultiColumnList;
class UGUIMultiColumnListHeader;
class UGUIListBase;

UCLASS()
class AA29_API UGUIMultiColumnListBox : public UGUIListBoxBase
{
	GENERATED_BODY()
public:
	UGUIMultiColumnListBox();

	UPROPERTY(EditAnywhere)								bool							bFullHeightStyle;			//var() bool bFullHeightStyle;
	UPROPERTY(EditAnywhere)								TArray<FString>					ColumnHeadings;				//var() localized array<String> ColumnHeadings;
	UPROPERTY(EditAnywhere)								TArray<float>					HeaderColumnPerc;			//var() array<float> HeaderColumnPerc;
	UPROPERTY(EditAnywhere)								UGUIMultiColumnList*			List;						//var() editconst GUIMultiColumnList List;
	UPROPERTY(EditAnywhere)								bool							bDisplayHeader;				//var() bool bDisplayHeader;
	UPROPERTY(EditAnywhere)								UGUIMultiColumnListHeader*		Header;						//var() GUIMultiColumnListHeader Header;


	void InitBaseList(UGUIListBase* LocalList);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender);
	void InternalOnColumnSized(int32 Column);
	
};
