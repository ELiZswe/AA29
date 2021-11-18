// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAGetDataMenu/AABrowser_OpenIP/AABrowser_OpenIP.h"
#include "EditFavoritePage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UEditFavoritePage : public UAABrowser_OpenIP
{
	GENERATED_BODY()
public:
	UEditFavoritePage();

	UPROPERTY(EditAnywhere)		UGUILabel*			l_name;				//var() automated XInterface.GUILabel l_name;
	UPROPERTY(EditAnywhere)		FServerResponseLine	Server;				//var GameInfo.ServerResponseLine Server;
	UPROPERTY(EditAnywhere)		FString				UnknownText;				//var localized FString UnknownText;


	void HandleParameters(FString ServerIP, FString ServerName);
	void ApplyURL(FString URL);

};
