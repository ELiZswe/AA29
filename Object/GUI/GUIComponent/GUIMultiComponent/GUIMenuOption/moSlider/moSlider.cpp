// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moSlider/moSlider.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUISlider/GUISlider.h"

UmoSlider::UmoSlider()
{
	SliderStyleName = "SliderKnob";
	SliderCaptionStyleName = "SliderCaption";
	SliderBarStyleName = "SliderBar";
	ComponentClassName = "XInterface.GUISlider";
}

void UmoSlider::InitComponent(UGUIController* InController, UGUIComponent* InOwner)
{
	/*
	Super::InitComponent(InController, InOwner);
	SetReadOnly(bValueReadOnly);
	*/
}

void UmoSlider::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender)
{
	/*
	if (Cast<UGUISlider>(NewComp) != nullptr)
	{
		MySlider = GUISlider(NewComp);
		MySlider.MinValue = MinValue;
		MySlider.MaxValue = MaxValue;
		MySlider.bIntSlider = bIntSlider;
		MySlider.StyleName = SliderStyleName;
		MySlider.CaptionStyleName = SliderCaptionStyleName;
		MySlider.BarStyleName = SliderBarStyleName;
	}
	Super::InternalOnCreateComponent(NewComp, Sender);
	*/
}

void UmoSlider::SetComponentValue(FString NewValue, bool bNoChange)
{
	/*
	if (bNoChange)
	{
		bIgnoreChange = true;
	}
	SetValue(float(NewValue));
	bIgnoreChange = false;
	*/
}

FString UmoSlider::GetComponentValue()
{
	//return FString::FromInt(GetValue());
	return "FAKE";    //FAKE   /ELiZ
}

void UmoSlider::Adjust(float Amount)
{
	/*
	if (MySlider != nullptr)
	{
		MySlider.Adjust(Amount);
	}
	*/
}

void UmoSlider::SetValue(float NewV)
{
	/*
	if (MySlider != nullptr)
	{
		Value = MySlider.SetValue(NewV);
	}
	*/
}

float UmoSlider::GetValue()
{
	/*
	if (MySlider != nullptr)
	{
		return MySlider.Value;
	}
	*/
	return 0;
}

void UmoSlider::Setup(float MinV, float MaxV, bool bInt)
{
	/*
	MinValue = MinV;
	MaxValue = MaxV;
	bIntSlider = bInt;
	if (MySlider != nullptr)
	{
		MySlider.MinValue = MinValue;
		MySlider.MaxValue = MaxValue;
		MySlider.bIntSlider = bIntSlider;
	}
	*/
}

void UmoSlider::InternalOnChange(UGUIComponent* Sender)
{
	/*
	Value = MySlider.Value;
	Super::InternalOnChange(Sender);
	*/
}

void UmoSlider::SetReadOnly(bool B)
{
	/*
	Super::SetReadOnly(B);
	MySlider.SetReadOnly(B);
	*/
}
