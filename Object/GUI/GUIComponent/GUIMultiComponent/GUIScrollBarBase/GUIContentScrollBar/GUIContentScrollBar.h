// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIScrollBarBase/GUIScrollBarBase.h"
#include "GUIContentScrollBar.generated.h"

class UGUIContentPanel;

UCLASS()
class AA29_API UGUIContentScrollBar : public UGUIScrollBarBase
{
	GENERATED_BODY()
public:
	UGUIContentScrollBar();

	UPROPERTY()						UGUIContentPanel*			MyPanel;						//var GUIContentPanel MyPanel;
	UPROPERTY(EditAnywhere)			float						StepPct;						//var() float StepPct;
	UPROPERTY(EditAnywhere)			float						BigStepPct;						//var() float BigStepPct;

	void SetList(UGUIListBase* List);
	void UpdateGripPosition(float NewPos);
	void MovePanelBy(float Pct);
	void WheelUp();
	void WheelDown();
	void AlignThumb();
	void ZoneClick(float Delta);
	void GripPressed(UGUIComponent* Sender, bool IsRepeat);
	bool GripPreDraw(UGUIComponent* Sender);
};
