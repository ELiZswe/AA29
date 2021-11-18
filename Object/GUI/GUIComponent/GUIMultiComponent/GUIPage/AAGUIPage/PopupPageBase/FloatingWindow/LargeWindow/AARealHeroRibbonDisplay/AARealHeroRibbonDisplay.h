// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/LargeWindow.h"
#include "AA29/AA29.h"
#include "AARealHeroRibbonDisplay.generated.h"

class UAARealHeroStats;
class UGUIImage;
class UGUIButton;
class UGUILabel;

UCLASS()
class AA29_API UAARealHeroRibbonDisplay : public ULargeWindow
{
	GENERATED_BODY()
public:
	UAARealHeroRibbonDisplay();

	UPROPERTY()					TArray<FRibbon>		Ribbons;				//var TArray<Ribbon> Ribbons;
	UPROPERTY()					UAARealHeroStats*	MyRealHeroStatsClass;	//var class<AARealHeroStats> MyRealHeroStatsClass;
	UPROPERTY(EditAnywhere)		TArray<UGUIImage*>	i_MyRibbons;			//var() automated XInterface.GUIImage i_MyRibbons[16];
	UPROPERTY(EditAnywhere)		UGUIButton*			b_Close;				//var() automated XInterface.GUIButton b_Close;
	UPROPERTY(EditAnywhere)		UGUILabel*			l_Header;				//var() automated XInterface.GUILabel l_Header;
	UPROPERTY()					float				RibbonSpacingX;			//var float RibbonSpacingX;
	UPROPERTY()					float				RibbonSpacingY;			//var float RibbonSpacingY;
	UPROPERTY()					float				RibbonStartY;			//var float RibbonStartY;
	UPROPERTY()					float				RibbonWidth;			//var float RibbonWidth;
	UPROPERTY()					float				RibbonHeight;			//var float RibbonHeight;
	UPROPERTY()					FString				RibbonHeaderText;		//var FString RibbonHeaderText;

	void HandleParameters(FString Param1, FString Param2);
	int32 FindRibbonIndex(FString RibbonToFind);
	void InternalOnOpen();
	bool InternalButtonClick(UGUIComponent* Sender);
};
