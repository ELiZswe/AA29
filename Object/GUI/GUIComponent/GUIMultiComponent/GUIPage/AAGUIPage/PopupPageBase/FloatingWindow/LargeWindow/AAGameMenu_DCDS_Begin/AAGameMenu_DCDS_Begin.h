// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/LargeWindow.h"
#include "AAGameMenu_DCDS_Begin.generated.h"

class UAAGUILabel;
class UGUIButton;

UCLASS()
class AA29_API UAAGameMenu_DCDS_Begin : public ULargeWindow
{
	GENERATED_BODY()
public:
	UAAGameMenu_DCDS_Begin();

	UPROPERTY(EditAnywhere)		UAAGUILabel*	l_Heading;			//var() automated AAGUILabel l_Heading;
	UPROPERTY(EditAnywhere)		UAAGUILabel*	l_Caption;			//var() automated AAGUILabel l_Caption;
	UPROPERTY(EditAnywhere)		UGUIButton*		b_Download;			//var() automated XInterface.GUIButton b_Download;
	UPROPERTY(EditAnywhere)		UGUIButton*		b_Cancel;			//var() automated XInterface.GUIButton b_Cancel;
	UPROPERTY(EditAnywhere)		UGUIButton*		b_OK;				//var() automated XInterface.GUIButton b_OK;
	UPROPERTY(EditAnywhere)		int32			AssetIndex;			//var int32 AssetIndex;
	UPROPERTY(EditAnywhere)		FString			AssetFullName;		//var FString AssetFullName;

	void HandleParameters(FString Param1, FString Param2);
	void Download();
	bool InternalOnClick(UGUIComponent* Sender);

};
