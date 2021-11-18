// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBoxBase.h"
#include "GUIScrollTextBox.generated.h"

class GUIScrollText;
class UGUIListBase;
class UGUIScrollText;

UCLASS()
class AA29_API UGUIScrollTextBox : public UGUIListBoxBase
{
	GENERATED_BODY()
public:
	UGUIScrollTextBox();

	UPROPERTY(EditAnywhere)									FString COMMA;							//var() string COMMA;
	UPROPERTY(EditAnywhere)									FString ESC;							//var() string ESC;
	UPROPERTY(EditAnywhere, Category = "GUIScrollText")		FString Separator;						//var(GUIScrollText) string Separator;
	UPROPERTY(EditAnywhere, Category = "GUIScrollText")		EeTextAlign TextAlign;					//var(GUIScrollText) GUI.eTextAlign TextAlign;
	UPROPERTY(EditAnywhere, Category = "GUIScrollText")		float RepeatDelay;						//var(GUIScrollText) float RepeatDelay;
	UPROPERTY(EditAnywhere, Category = "GUIScrollText")		float EOLDelay;							//var(GUIScrollText) float EOLDelay;
	UPROPERTY(EditAnywhere, Category = "GUIScrollText")		float CharDelay;						//var(GUIScrollText) float CharDelay;
	UPROPERTY(EditAnywhere, Category = "GUIScrollText")		float InitialDelay;						//var(GUIScrollText) float InitialDelay;
	UPROPERTY(EditAnywhere, Category = "GUIScrollText")		bool bStripColors;						//var(GUIScrollText) bool bStripColors;
	UPROPERTY(EditAnywhere, Category = "GUIScrollText")		bool bNoTeletype;						//var(GUIScrollText) bool bNoTeletype;
	UPROPERTY(EditAnywhere, Category = "GUIScrollText")		bool bRepeat;							//var(GUIScrollText) bool bRepeat;
	UPROPERTY(EditAnywhere)									UGUIScrollText* MyScrollText;			//var GUIScrollText MyScrollText;

	void Created();
	void InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender);
	void InitBaseList(UGUIListBase* LocalList);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetContent(FString NewContent, FString sep);
	void Restart();
	void Stop();
	void InternalOnAdjustTop(UGUIComponent* Sender);
	bool IsNumber(FString Num);
	FString StripColors(FString MyString);
	void AddText(FString NewText);

};
