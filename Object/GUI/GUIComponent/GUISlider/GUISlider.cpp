// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUISlider/GUISlider.h"
#include "AA29/Object/GUI/GUIComponent/GUIToolTip/GUIToolTip.h"

UGUISlider::UGUISlider()
{
	UGUIToolTip* GUISliderToolTip = NewObject<UGUIToolTip>(UGUIToolTip::StaticClass());
	MaxValue = 100;
	bShowMarker = true;
	bShowValueTooltip = true;
	CaptionStyleName = "SliderCaption";
	BarStyleName = "SliderBar";
	StyleName = "SliderKnob";
	WinHeight = 0.03;
	bTabStop = true;
	bAcceptsInput = true;
	bCaptureMouse = true;
	bRequireReleaseClick = true;
	bRequiresStyle = true;
	ToolTip = GUISliderToolTip;
	OnClickSound = EClickSound::CS_Click;

	//OnClick = GUISlider.InternalOnClick;
	//OnMousePressed = GUISlider.InternalOnMousePressed;
	//OnMouseRelease = GUISlider.InternalOnMouseRelease;
	//OnKeyEvent = GUISlider.InternalOnKeyEvent;
	//OnCapturedMouseMove = GUISlider.InternalCapturedMouseMove;

}



bool UGUISlider::OnPreDrawCaption(float& X, float& Y, float& XL, float& YL, EeTextAlign& Justification)
{
	return false;    //FAKE   /ELiZ
}

FString UGUISlider::OnDrawCaption()
{
	/*
	if (bIntSlider)
	{
		return "(" $ string(int(Value)) $ Eval(bDrawPercentSign, " %", "") $ ")";
	}
	
	return "(" $ string(Value) $ Eval(bDrawPercentSign, " %", "") $ ")";
	*/
	return "FAKE";   //FAKE   /ELiZ
}

void UGUISlider::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	CaptionStyle = Controller.GetStyle(CaptionStyleName, FontScale);
	BarStyle = Controller.GetStyle(BarStyleName, FontScale);
	*/
}

bool UGUISlider::InternalCapturedMouseMove(float deltaX, float deltaY)
{
	/*
	float Perc = 0;
	if (bReadOnly)
	{
		return true;
	}
	if ((Controller.MouseX >= Bounds[0]) && (Controller.MouseX <= Bounds[2]))
	{
		Perc = FClamp(((Controller.MouseX - (ActualLeft() + (MarkerWidth / 2))) / (ActualWidth() - MarkerWidth)), 0, 1);
		Value = (((MaxValue - MinValue) * Perc) + MinValue);
		if (bIntSlider)
		{
			Value = Round(Value);
		}
	}
	else
	{
		if (Controller.MouseX < Bounds[0])
		{
			Value = MinValue;
		}
		else
		{
			if (Controller.MouseX > Bounds[2])
			{
				Value = MaxValue;
			}
		}
	}
	Value = FClamp(Value, MinValue, MaxValue);
	if (bShowValueTooltip)
	{
		ToolTip.SetTip(GetValueString());
	}
	*/
	return true;
}

bool UGUISlider::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if (bReadOnly)
	{
		return false;
	}
	if ((Key == 37) && (State == 1))
	{
		if (bIntSlider)
		{
			Adjust(-1);
		}
		else
		{
			Adjust(-0.01);
		}
		return true;
	}
	if ((Key == 39) && (State == 1))
	{
		if (bIntSlider)
		{
			Adjust(1);
		}
		else
		{
			Adjust(0.01);
		}
		return true;
	}
	*/
	return false;
}

float UGUISlider::SetValue(float NewValue)
{
	/*
	Value = FClamp(NewValue, MinValue, MaxValue);
	if (bIntSlider)
	{
		Value = Round(Value);
	}
	return Value;
	*/
	return 0;    //FAKE   /ELiZ
}

void UGUISlider::Adjust(float Amount)
{
	/*
	float Perc = 0;
	Perc = ((Value - MinValue) / (MaxValue - MinValue));
	(Perc += Amount);
	Perc = FClamp(Perc, 0, 1);
	Value = FClamp((((MaxValue - MinValue) * Perc) + MinValue), MinValue, MaxValue);
	OnChange(Self);
	*/
}

bool UGUISlider::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (bShowValueTooltip)
	{
		RevertTooltipToNormal();
	}
	OnChange(Self);
	*/
	return true;
}

void UGUISlider::InternalOnMousePressed(UGUIComponent* Sender, bool RepeatClick)
{
	/*
	if (bShowValueTooltip)
	{
		ModifyTooltipForDragging();
	}
	InternalCapturedMouseMove(0, 0);
	*/
}

void UGUISlider::InternalOnMouseRelease(UGUIComponent* Sender)
{
	//InternalCapturedMouseMove(0, 0);
}

void UGUISlider::SetReadOnly(bool B)
{
	bReadOnly = B;
}

float UGUISlider::GetMarkerPosition()
{
	/*
	float Perc = 0;
	Perc = ((Value - MinValue) / (MaxValue - MinValue));
	return (ActualLeft() + ((ActualWidth() - MarkerWidth) * Perc));
	*/

	return 0;   //FAKE   /ELiZ
}

void UGUISlider::CenterMouse()
{
	/*
	if (PlayerOwner() != None)
	{
		PlayerOwner().ConsoleCommand("SETMOUSE" @ string(GetMarkerPosition()) @ string((ActualTop() + (ActualHeight() / 2))));
	}
	*/
}

FString UGUISlider::GetValueString()
{
	FString ValueStr = "";
	/*
	if (bIntSlider)
	{
		ValueStr = string(int(Value));
	}
	else
	{
		ValueStr = string(Value);
	}
	if (bDrawPercentSign)
	{
		(ValueStr @ = "%");
	}
	*/
	return ValueStr;
}

void UGUISlider::ModifyTooltipForDragging()
{
	/*
	ToolTip.bTrackMouse = true;
	ToolTip.bTrackInput = false;
	ToolTip.bMultiLine = false;
	ToolTip.__HideToolTip__Delegate = HideToolTip;
	ToolTip.__LeaveArea__Delegate = ToolTipLeaveArea;
	SetToolTipText(GetValueString());
	ShowToolTip();
	*/
}

void UGUISlider::RevertTooltipToNormal()
{
	/*
	ToolTip.bTrackMouse = ToolTip.Default.bTrackMouse;
	ToolTip.bTrackInput = ToolTip.Default.bTrackInput;
	ToolTip.bMultiLine = ToolTip.Default.bMultiLine;
	ToolTip.__HideToolTip__Delegate = None;
	ToolTip.__LeaveArea__Delegate = None;
	ToolTip.LeaveArea();
	SetToolTipText(Hint);
	*/
}

void UGUISlider::ShowToolTip()
{
	/*
	Controller.MouseOver = ToolTip.InternalEnterArea();
	ToolTip.SetVisibility(true);
	*/
}

void UGUISlider::HideToolTip()
{
	/*
	if (MenuState != 3)
	{
		Log("HideToolTip  MenuState:" $ string(GetEnum(Enum'XInterface.GUI.eMenuState', MenuState)));
		ToolTip.SetVisibility(false);
	}
	*/
}

bool UGUISlider::ToolTipLeaveArea()
{
	return false;
}
