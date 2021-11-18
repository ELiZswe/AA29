// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAGUIPage.h"
#include "AAIntroMoviePage.generated.h"

class UGUIImageButton;

UCLASS()
class AA29_API UAAIntroMoviePage : public UAAGUIPage
{
	GENERATED_BODY()
public:
	UAAIntroMoviePage();

	UPROPERTY(EditAnywhere)		UGUIImageButton*	iIntroMovie;				//var() automated GUIImageButton iIntroMovie;
	UPROPERTY()					bool				bAllowClose;				//var bool bAllowClose;
	UPROPERTY()					FString				EntryPage;					//var FString EntryPage;
	UPROPERTY()					UMaterialInstance*	MovieToPlay;				//var MovieTexture MovieToPlay;
	UPROPERTY()					bool				bForceClose;				//var bool bForceClose;
	UPROPERTY()					bool				bPlayedOnce;				//var bool bPlayedOnce;

	void InternalOnOpen();
	bool internalKeyEvent(uint8& Key, uint8& State, float Delta);
	bool InternalOnClick(UGUIComponent* Sender);
	bool CanClose(bool bCancelled);
	void InternalOnClose(bool bCanceled);
	void Timer();
	void MovieCleanup();

};
