// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "UT2StatusMsg.generated.h"

class UGUIComponent;
class UGUIController;
UCLASS()
class UUT2StatusMsg : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UUT2StatusMsg();

	UPROPERTY()					bool				bIgnoreEsc;			//var bool bIgnoreEsc;
	UPROPERTY()					float				ButtonWidth;		//var float ButtonWidth;
	UPROPERTY()					float				ButtonHeight;		//var float ButtonHeight;
	UPROPERTY()					float				ButtonHGap;			//var float ButtonHGap;
	UPROPERTY()					float				ButtonVGap;			//var float ButtonVGap;
	UPROPERTY()					float				BarHeight;			//var float BarHeight;
	UPROPERTY()					float				BarVPos;			//var float BarVPos;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalOnClick(UGUIComponent* Sender);
	void HandleParameters(FString Param1, FString Param2);
};
