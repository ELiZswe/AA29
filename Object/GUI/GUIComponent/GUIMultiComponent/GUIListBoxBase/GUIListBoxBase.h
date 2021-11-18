// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMultiComponent.h"
#include "GUIListBoxBase.generated.h"

class UGUIScrollBarBase;
class UGUIListBase;
class UGUILabel;

UCLASS()
class AA29_API UGUIListBoxBase : public UGUIMultiComponent
{
	GENERATED_BODY()
public:
	UGUIListBoxBase();

	UPROPERTY(EditAnywhere)									bool bInitializeList;				//var() bool bInitializeList;
	UPROPERTY(EditAnywhere)									bool bSorted;						//var() bool bSorted;
	UPROPERTY(EditAnywhere)									bool bVisibleWhenEmpty;				//var() bool bVisibleWhenEmpty;
	UPROPERTY(EditAnywhere)									UGUIListBase* MyList;				//var() editconst GUIListBase MyList;
	UPROPERTY(EditAnywhere)									UGUIScrollBarBase* MyScrollBar;		//var() GUIScrollBarBase MyScrollBar;
	UPROPERTY(EditAnywhere)									FString DefaultListClass;			//var() string DefaultListClass;
	UPROPERTY(EditAnywhere)									FString OutlineStyleName;			//var() string OutlineStyleName;
	UPROPERTY(EditAnywhere)									FString SectionStyleName;			//var() string SectionStyleName;
	UPROPERTY(EditAnywhere)									FString SelectedStyleName;			//var() string SelectedStyleName;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InitBaseList(UGUIListBase* LocalList);
	void SetHint(FString NewHint);
	void InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender);
	void SetFriendlyLabel(UGUILabel* NewLabel);
};
