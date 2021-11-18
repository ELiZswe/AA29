// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GUI.generated.h"

class UGUIController;

UCLASS()
class AA29_API UGUI : public UObject
{
	GENERATED_BODY()
public:
		UGUI();

		UPROPERTY()											UGUIController* Controller;						//var GUIController Controller;		// Callback to the GUIController running the show
		UPROPERTY()											FPlane SaveModulation;							//var Object.Plane SaveModulation;
		UPROPERTY()											float SaveX;									//var float SaveX;
		UPROPERTY()											float SaveY;									//var float SaveY;
		UPROPERTY()											FColor SaveColor;								//var Object.Color SaveColor;
		UPROPERTY()											UFont* SaveFont;								//var Font SaveFont;
		UPROPERTY()											uint8 SaveStyle;								//var byte SaveStyle;

		bool IsDigit(FString Test, bool bAllowDecimal); 
		FString JoinArray(TArray<FString> StringArray, FString Delim, bool bIgnoreBlanks);
		void Profile(FString ProfileName);
		void GetModList(TArray<FString>& ModDirs, TArray<FString>& ModTitles);
		void GetModValue(FString ModDir, FString ModKey);
		void GetModLogo(FString ModDir);

};
