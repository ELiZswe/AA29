// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIPanel.h"
#include "GUITabPanel.generated.h"

class UGUITabButton;

UCLASS()
class AA29_API UGUITabPanel : public UGUIPanel
{
	GENERATED_BODY()
public:
	UGUITabPanel();


	UPROPERTY(EditAnywhere, Category = "Panel")			FString					PanelCaption;					//var(Panel) localized FString PanelCaption;
	UPROPERTY(EditAnywhere, Category = "Panel")			bool					bFillHeight;					//var(Panel) bool bFillHeight;
	UPROPERTY(EditAnywhere, Category = "Panel")			float					FadeInTime;						//var(Panel) float FadeInTime;
	UPROPERTY()											UGUITabButton*			MyButton;						//var noexport GUITabButton MyButton;


	void Refresh();
	void InitPanel();
	void OnDestroyPanel(bool bCancelled);
	void Free();
	void ShowPanel(bool bShow);
	bool CanShowPanel();
	
};
