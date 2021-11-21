// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "UT2BadCDKeyMsg.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUT2BadCDKeyMsg : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UUT2BadCDKeyMsg();

	UPROPERTY()				bool		bIgnoreEsc;				//var bool bIgnoreEsc;
	UPROPERTY()				FString		LeaveMPButtonText;		//var localized FString LeaveMPButtonText;
	UPROPERTY()				FString		LeaveSPButtonText;		//var localized FString LeaveSPButtonText;
	UPROPERTY()				float		ButtonWidth;			//var float ButtonWidth;
	UPROPERTY()				float		ButtonHeight;			//var float ButtonHeight;
	UPROPERTY()				float		ButtonHGap;				//var float ButtonHGap;
	UPROPERTY()				float		ButtonVGap;				//var float ButtonVGap;
	UPROPERTY()				float		BarHeight;				//var float BarHeight;
	UPROPERTY()				float		BarVPos;				//var float BarVPos;

	bool InternalOnClick(UGUIComponent* Sender);
};
