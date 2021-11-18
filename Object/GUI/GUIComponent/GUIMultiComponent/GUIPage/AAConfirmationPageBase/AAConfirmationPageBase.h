// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/GUIPage.h"
#include "AAConfirmationPageBase.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAAConfirmationPageBase : public UGUIPage
{
	GENERATED_BODY()
public:
	UAAConfirmationPageBase();

	UPROPERTY()						FString					ConfirmCaption;				//var FString ConfirmCaption;
	UPROPERTY()						FString					DenyCaption;				//var FString DenyCaption;
	UPROPERTY()						FString					DescriptionCaption;			//var FString DescriptionCaption;
	UPROPERTY()						bool					bConfirmOnly;				//var bool bConfirmOnly;
	UPROPERTY()						bool					bDenyOnly;					//var bool bDenyOnly;
	UPROPERTY()						float					leftSpace;					//var float leftSpace;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void HandleParameters(FString Param1, FString Param2);
	bool ClickYes(UGUIComponent* Sender);
	bool ClickNo(UGUIComponent* Sender);
};
