// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "UT2VideoChangeOK.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUT2VideoChangeOK : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UUT2VideoChangeOK();

	UPROPERTY()					int32				Count;						//var int32 Count;
	UPROPERTY()					FString				OrigRes;					//var FString OrigRes;
	UPROPERTY()					FString				RestoreTextPre;				//var localized FString RestoreTextPre;
	UPROPERTY()					FString				RestoreTextPost;			//var localized FString RestoreTextPost;
	UPROPERTY()					FString				RestoreTextSingular;		//var localized FString RestoreTextSingular;

	void Timer();
	void Execute(FString DesiredRes);
	void StartTimer();
	bool InternalOnClick(UGUIComponent* Sender);
};
