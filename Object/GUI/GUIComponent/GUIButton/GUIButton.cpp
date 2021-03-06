// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIToolTip/GUIToolTip.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/GUI/GUIStyles/GUIStyles.h"

UGUIButton::UGUIButton()
{
	UGUIToolTip* GUIButtonToolTip = NewObject<UGUIToolTip>(UGUIToolTip::StaticClass());

	CaptionAlign = ETextAlign::TXTA_Center;
	AutoSizePadding = { 0.125000f,0.0f };
	bAutoShrink = true;
	StyleName = "SquareButton";
	WinHeight = 0.04;
	bTabStop = true;
	bAcceptsInput = true;
	bCaptureMouse = true;
	ToolTip = GUIButtonToolTip;
	StandardHeight = 0.04;
	//__OnKeyEvent__Delegate = "GUIButton.InternalOnKeyEvent";
}

void UGUIButton::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	EeFontScale X = EeFontScale::FNS_Small;
	Super::InitComponent(MyController, MyOwner);
	if (CaptionEffectStyleName != "")
	{
		CaptionEffectStyle = Controller->GetStyle(CaptionEffectStyleName, X);
	}
}

bool UGUIButton::InternalOnKeyEvent(uint8 &Key, uint8 &State, float Delta)
{
	if (Key == 13 || Key == 32 && State == 1)
	{
		OnClick(this);
		return true;
	}
	return false;
}
