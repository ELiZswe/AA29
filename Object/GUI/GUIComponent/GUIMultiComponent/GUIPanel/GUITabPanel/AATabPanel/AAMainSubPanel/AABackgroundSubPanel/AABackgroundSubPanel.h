// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AAMainSubPanel.h"
#include "AABackgroundSubPanel.generated.h"

class UGUIImage;
class UGUIBorder;
class UGUILabel;

UCLASS()
class AA29_API UAABackgroundSubPanel : public UAAMainSubPanel
{
	GENERATED_BODY()
public:
	UAABackgroundSubPanel();

	UPROPERTY(EditAnywhere)			UGUIImage*						i_Background;				//var() automated XInterface.GUIImage i_Background;
	UPROPERTY(EditAnywhere)			UGUIBorder*						h_Header;					//var() automated XInterface.GUIBorder h_Header;
	UPROPERTY(EditAnywhere)			UGUIImage*						i_NMLStatusIcon;			//var() automated XInterface.GUIImage i_NMLStatusIcon;
	UPROPERTY(EditAnywhere)			UGUILabel*						l_NMLStatusText;			//var() automated XInterface.GUILabel l_NMLStatusText;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
};
