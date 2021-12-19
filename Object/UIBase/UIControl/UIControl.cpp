// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"

UUIControl::UUIControl()
{
	_bEnabled = true;
}

void UUIControl::Create(UUIFrame* frame, UUIScreen* screen, int32 pID, int32 pUIEvent, int32 pParams)
{
	bControlInitialized = false;
	cFrame = frame;
	cScreen = screen;
	_iUIEvent = pUIEvent;
	_iID = pID;
	_iParams = pParams;
	_bAllowScaling = frame->_bAllowScaling;
	CreateTexture();
	ProcessParams();
}

void UUIControl::Destroyed()
{
	bControlInitialized = false;
	_bEnabled = false;
	cFrame = nullptr;
	cScreen = nullptr;
	cNextControl = nullptr;
	cPrevControl = nullptr;
	cParentControl = nullptr;
}
void UUIControl::CreateTexture()
{
}
void UUIControl::ProcessParams()
{
}
void UUIControl::Focus(bool bFocus)
{
	if (_bCanHaveFocus)
	{
		_bFocus = bFocus;
	}
}
bool UUIControl::HasFocus()
{
	return _bFocus;
}
void UUIControl::CreateUIControl(FString ControlName)
{
	/*
	local UIControl myControl;
	local class<UIControl>  cUIControl;
	cUIControl = class<UIControl>(DynamicLoadObject(ControlName, Class'Class'));
	myControl = new (None) classcUIControl;
	return myControl;
	*/
}
void UUIControl::ScaleControl(UCanvas* Canvas)
{
	if (_bAllowScaling)
	{
		//_ScaledPos.X = _Pos.X * cFrame->fScaleX + cFrame->offset->X;
		//_ScaledPos.Y = _Pos.Y * cFrame->fScaleY + cFrame->offset->Y;
		//_ScaledPos.W = _Pos.W * cFrame->fScaleX;
		//_ScaledPos.H = _Pos.H * cFrame->fScaleY;
	}
	else
	{
		//_ScaledPos.X = _Pos.X + cFrame->offset.X;
		//_ScaledPos.Y = _Pos.Y + cFrame->offset.Y;
		//_ScaledPos.W = _Pos.W;
		//_ScaledPos.H = _Pos.H;
	}
}
void UUIControl::MouseMove(int32 mX, int32 mY)
{
}
void UUIControl::NotifyParent(float Value)
{
	cParentControl->ChildMessage(Value);
}
void UUIControl::ChildMessage(float Value)
{
}
void UUIControl::SetParent(UUIControl* Control)
{
	cParentControl = Control;
}
void UUIControl::SetAllowScaling(bool Scaling)
{
	_bAllowScaling = Scaling;
}
bool UUIControl::GetAllowScaling()
{
	return _bAllowScaling;
}
void UUIControl::SetEnabled(bool Enabled)
{
	_bEnabled = Enabled;
}
bool UUIControl::IsEnabled()
{
	return _bEnabled;
}
void UUIControl::SetTooltip(FString sToolTip)
{
	_sToolTip = sToolTip;
}
FString UUIControl::GetToolTip()
{
	return _sToolTip;
}
void UUIControl::SetGroupID(int32 Id)
{
	_iGroup = Id;
}
int32 UUIControl::GetGroupID()
{
	return _iGroup;
}
void UUIControl::Select(bool State)
{
}
void UUIControl::IsSelected()
{
}
void UUIControl::Tick(float DeltaTime)
{
}