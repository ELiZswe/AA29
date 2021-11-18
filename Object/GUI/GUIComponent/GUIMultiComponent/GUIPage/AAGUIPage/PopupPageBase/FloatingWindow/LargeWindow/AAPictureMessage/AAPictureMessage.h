// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/LargeWindow.h"
#include "AAPictureMessage.generated.h"

class UGUIImage;
class UGUIButton;
class UGUILabel;

UCLASS()
class AA29_API UAAPictureMessage : public ULargeWindow
{
	GENERATED_BODY()
public:
	UAAPictureMessage();

	UPROPERTY(EditAnywhere)		UGUIImage*		imgPictureBg;		//var() automated XInterface.GUIImage imgPictureBg;
	UPROPERTY(EditAnywhere)		UGUIImage*		imgPicture;			//var() automated XInterface.GUIImage imgPicture;
	UPROPERTY(EditAnywhere)		UGUIButton*		btnOK;				//var() automated XInterface.GUIButton btnOK;
	UPROPERTY(EditAnywhere)		UGUILabel*		lblTitle;			//var() automated XInterface.GUILabel lblTitle;

	bool btnOkOnClick(UGUIComponent* Sender);
	void HandleParameters(FString Param1, FString Param2);
};
