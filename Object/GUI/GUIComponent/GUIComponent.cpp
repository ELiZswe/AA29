// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/GUIPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIContextMenu/GUIContextMenu.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIStyles/GUIStyles.h"
#include "AA29/Object/GUI/GUIComponent/GUIToolTip/GUIToolTip.h"
#include "Engine/Canvas.h"

UGUIComponent::UGUIComponent()
{
	DynamicBorderOffsets.SetNum(4);
	MouseOffset.SetNum(4);
	ClientBounds.SetNum(4);
	Bounds.SetNum(4);
	FontScale = EeFontScale::FNS_Medium;
	WinWidth = 1;
	RenderWeight = 0.5;
	TabOrder = -1;
	Tag = -1;
	bVisible = true;
	bInit = true;
	TimerIndex = -1;
	WhiteColor = FColor(244, 237, 253, 255);
}

void UGUIComponent::OnArrival(UGUIComponent* Sender, EAnimationType Type)
{
}

void UGUIComponent::OnEndAnimation(UGUIComponent* Sender, EAnimationType Type)
{
}

bool UGUIComponent::OnPreDraw(UCanvas* Canvas)
{
	if (0 < 1)
	{
		return false;
	}
	OnPreDrawCount++;
	if (OnPreDrawCount > 0)
	{
		//Log("OnPreDraw called" @ OnPreDrawCount @ "times: " + GetMenuPath());
	}
	return false;
}

bool UGUIComponent::OnDraw(UCanvas* Canvas)
{
	if (0 < 1)
	{
		return false;
	}
	OnDrawCount++;
	if (OnDrawCount > 0)
	{
		//Log("OnDraw called" @ OnDrawCount @ "times: " + GetMenuPath());
	}
	return false;
}

void UGUIComponent::OnRender(UCanvas* Canvas)
{
	if (0 < 1)
	{
		return;
	}
	OnRenderCount++;
	if (OnRenderCount > 0)
	{
		//Log("OnRender called" @ OnRenderCount @ "times: " + GetMenuPath());
	}
}

void UGUIComponent::OnRendered(UCanvas* Canvas)
{
	if (0 < 1)
	{
		return;
	}
	OnRenderedCount++;
	if (OnRenderedCount > 0)
	{
		//Log("OnRendered called" @ OnRenderedCount @ "times:" @ GetMenuPath());
	}
}

void UGUIComponent::OnActivate()
{
}

void UGUIComponent::OnDeActivate()
{
}

void UGUIComponent::OnWatch()
{
}

void UGUIComponent::OnHitTest(float MouseX, float MouseY)
{
}

void UGUIComponent::OnMessage(FString Msg, float MsgLife)
{
}

void UGUIComponent::OnHide()
{
}

void UGUIComponent::OnShow()
{
}

UGUIToolTip* UGUIComponent::OnBeginTooltip()
{
	if (ToolTip != nullptr)
	{
		return ToolTip->EnterArea();
	}
	else
	{
		if (MenuOwner != nullptr)
		{
			return MenuOwner->OnBeginTooltip();
		}
	}
	return nullptr;
}

bool UGUIComponent::OnEndTooltip()
{
	if (ToolTip != nullptr)
	{
		return ToolTip->LeaveArea();
	}
	else
	{
		if (MenuOwner != nullptr)
		{
			return MenuOwner->OnEndTooltip();
		}
	}
	return true;
}

void UGUIComponent::OnInvalidate(UGUIComponent* Who)
{
}

bool UGUIComponent::OnHover(UGUIComponent* Sender)
{
	return false;
}

void UGUIComponent::OnClick(UGUIComponent* Sender)
{
}

void UGUIComponent::OnDblClick(UGUIComponent* Sender)
{
}

void UGUIComponent::OnRightClick(UGUIComponent* Sender)
{
}

void UGUIComponent::OnMousePressed(UGUIComponent* Sender, bool bRepeat)
{
}

void UGUIComponent::OnMouseRelease(UGUIComponent* Sender)
{
}

void UGUIComponent::OnTimer(UGUIComponent* Sender)
{
}

void UGUIComponent::OnChange(UGUIComponent* Sender)
{
}

bool UGUIComponent::OnKeyType(uint8 &Key, FString Unicode)
{
	return false;
}

bool UGUIComponent::OnKeyEvent(uint8 &Key, uint8 &State, float Delta)
{
	return false;
}

bool UGUIComponent::OnDesignModeKeyEvent(EInputKey Key, EInputAction State)
{
	return false;
}

bool UGUIComponent::OnCapturedMouseMove(float deltaX, float deltaY)
{
	return false;
}

void UGUIComponent::OnLoadINI(UGUIComponent* Sender, FString S)
{
}

FString UGUIComponent::OnSaveINI(UGUIComponent* Sender)
{
	return "FAKE";    //FAKE   /EliZ
}

bool UGUIComponent::OnMultiSelect(UGUIComponent* Sender)
{
	return true;
}

bool UGUIComponent::OnBeginDrag(UGUIComponent* Sender)
{
	return bDropSource;
}

void UGUIComponent::OnEndDrag(UGUIComponent* Sender, bool bAccepted)
{
}

bool UGUIComponent::OnDragDrop(UGUIComponent* Sender)
{
	return false;
}

void UGUIComponent::OnDragEnter(UGUIComponent* Sender)
{
}

void UGUIComponent::OnDragLeave(UGUIComponent* Sender)
{
}

void UGUIComponent::OnDragOver(UGUIComponent* Sender)
{
}

//native(812) final Function PlayerOwner();
APlayerController* UGUIComponent::PlayerOwner()
{
	return nullptr;	
}

//native(813) final Function SetTimer(float Interval, bool bRepeat);
void UGUIComponent::SetTimer(float Interval, bool bRepeat)
{
}

//native(814) final Function KillTimer();
void UGUIComponent::KillTimer()
{
}

//native(815) final Function AutoPosition(array<GUIComponent> Components, float LeftBound, float UpperBound, float RightBound, float LowerBound, float LeftPad, float UpperPad, float RightPad, float LowerPad, int NumberOfColumns, float ColumnPadding);
void UGUIComponent::AutoPosition(TArray<UGUIComponent*> Components, float LeftBound, float UpperBound, float RightBound, float LowerBound, float LeftPad, float UpperPad, float RightPad, float LowerPad, int32 NumberOfColumns, float ColumnPadding)
{
}

//native(816) final Function AutoPositionOn(array<GUIComponent> Components, GUIComponent frame, float LeftPadPerc, float UpperPadPerc, float RightPadPerc, float LowerPadPerc, int NumberOfColumns, float ColumnPadding);
void UGUIComponent::AutoPositionOn(TArray<UGUIComponent*> Components, UGUIComponent* frame, float LeftPadPerc, float UpperPadPerc, float RightPadPerc, float LowerPadPerc, int32 NumberOfColumns, float ColumnPadding)
{
}

//native(817) final Function UpdateOffset(float PosX, float PosY, float PosW, float PosH);
void UGUIComponent::UpdateOffset(float PosX, float PosY, float PosW, float PosH)
{
}

//native(820) final Function ActualWidth(float Val, bool bForce);
float UGUIComponent::ActualWidth(float Val, bool bForce)
{
	return 0;  //FAKE  /ELiZ
}

//native(821) final Function ActualHeight(float Val, bool bForce);
float UGUIComponent::ActualHeight(float Val, bool bForce)
{
	return 0;  //FAKE  /ELiZ
}

//native(822) final Function ActualLeft(float Val, bool bForce);
float UGUIComponent::ActualLeft(float Val, bool bForce)
{
	return 0;  //FAKE  /ELiZ
}

//native(823) final Function ActualTop(float Val, bool bForce);
float UGUIComponent::ActualTop(float Val, bool bForce)
{
	return 0;  //FAKE  /ELiZ
}

//native(824) final Function RelativeLeft(float RealLeft, bool bForce);
float UGUIComponent::RelativeLeft(float RealLeft, bool bForce)
{
	return 0;  //FAKE  /ELiZ
}

//native(825) final Function RelativeTop(float RealTop, bool bForce);
float UGUIComponent::RelativeTop(float RealTop, bool bForce)
{
	return 0;  //FAKE  /ELiZ
}

//native(826) final Function RelativeWidth(float RealWidth, bool bForce);
float UGUIComponent::RelativeWidth(float RealWidth, bool bForce)
{
	return 0;  //FAKE  /ELiZ
}

//native(827) final Function RelativeHeight(float RealHeight, bool bForce);
float UGUIComponent::RelativeHeight(float RealHeight, bool bForce)
{
	return 0;  //FAKE  /ELiZ
}

//native(828) final Function GetMenuPath();
void UGUIComponent::GetMenuPath()
{
}

//native(829) final Function SpecialHit(bool bForce);
void UGUIComponent::SpecialHit(bool bForce)
{
}

void UGUIComponent::ResolutionChanged(int32 ResX, int32 ResY)
{
}
void UGUIComponent::SetPosition(float NewLeft, float NewTop, float NewWidth, float NewHeight, bool bForceRelative)
{
	if (bDebugging && Controller == nullptr || Controller->bModAuthor)
	{
		//Log(Name + ".SetPosition( " + NewLeft + "," @ NewTop + "," @ NewWidth + "," @ NewHeight + "," @ bForceRelative, 'ModAuthor');
	}
	if (bForceRelative)
	{
		WinLeft = RelativeLeft(NewLeft,false);
		WinTop = RelativeTop(NewTop,false);
		WinWidth = RelativeWidth(NewWidth,false);
		WinHeight = RelativeHeight(NewHeight,false);
	}
	else
	{
		WinLeft = NewLeft;
		WinTop = NewTop;
		WinWidth = NewWidth;
		WinHeight = NewHeight;
	}
	if (bDebugging && bForceRelative && Controller == nullptr || Controller->bModAuthor)
	{
		//Log(Name @ "SetPosition() Current L:" + WinLeft + "(" + Bounds[0] + ") T:" + WinTop + "(" + Bounds[1] + ") W:" + WinWidth + "(" + Bounds[0] + Bounds[2] + ") H:" + WinHeight + "(" + Bounds[1] + Bounds[3] + ")", 'ModAuthor');
	}
}

FString UGUIComponent::AdditionalDebugString()
{
	return "";
}

void UGUIComponent::Timer()
{
	OnTimer(this);
}

void UGUIComponent::Opened(UGUIComponent* Sender)
{
	LoadINI();
	if (ToolTip != nullptr)
	{
		ToolTip->InitComponent(Controller, this);
		SetToolTipText(Hint);
	}
}

void UGUIComponent::Closed(UGUIComponent* Sender, bool bCancelled)
{
	if (!bCancelled)
	{
		SaveINI("");
	}
}
void UGUIComponent::Free()
{
	
	MenuOwner = nullptr;
	PageOwner = nullptr;
	Controller = nullptr;
	FocusInstead = nullptr;
	FriendlyLabel = nullptr;
	Style = nullptr;
	if (ToolTip != nullptr)
	{
		ToolTip->Free();
	}
	ToolTip = nullptr;
}

FString UGUIComponent::LoadINI()
{
	FString S = "";
	if (PlayerOwner() == nullptr || IniOption == "")
	{
		return "";
	}
	if (IniOption.Compare("@Internal", ESearchCase::IgnoreCase))
	{
		OnLoadINI(this, "");
		return "";
	}
	//S = PlayerOwner().ConsoleCommand("get" @ IniOption);
	if (S == "")
	{
		S = IniDefault;
	}
	//OnLoadINI(this, S);
	return S;
}

void UGUIComponent::SaveINI(FString Value)
{
	if (PlayerOwner() == nullptr)
	{
		return;
	}
	OnSaveINI(this);
}

FString UGUIComponent::StripColorCodes(FString InString)
{
	int32 p;
	InString.FindChar(TCHAR(27), p);
	while (p >= 0)
	{
		InString.RemoveAt(p, 4);
		InString.FindChar(TCHAR(27), p);;
	}
	return InString;
}

FString UGUIComponent::MakeColorCode(FColor NewColor)
{
	FString OutColor = "";
	if (NewColor.R == 0)
	{
		NewColor.R = 1;
	}
	if (NewColor.G == 0)
	{
		NewColor.G = 1;
	}
	if (NewColor.B == 0)
	{
		NewColor.B = 1;
	}

	OutColor.AppendChar(TCHAR(27));
	OutColor.AppendChar(TCHAR(NewColor.R));
	OutColor.AppendChar(TCHAR(NewColor.G));
	OutColor.AppendChar(TCHAR(NewColor.B));
	return OutColor;
}

void UGUIComponent::MenuStateChange(EMenuState NewState)
{
	if (MenuState != EMenuState::MSAT_Watched)
	{
		LastMenuState = MenuState;
	}
	bPendingFocus = false;
	MenuState = NewState;
	switch(MenuState)
	{
		case EMenuState::MSAT_Focused:
			if (!bNeverFocus)
			{
				bHasFocus = true;
				break;
			}
			MenuState = EMenuState::MSAT_Blurry;
		case EMenuState::MSAT_Blurry:
			bHasFocus = false;
			if (LastMenuState != EMenuState::MSAT_Blurry && LastMenuState != EMenuState::MSAT_Disabled)
			{
				OnDeActivate();
			}
			break;
		case EMenuState::MSAT_Watched:
			if (bFocusOnWatch)
			{
				SetFocus(nullptr);
				return;
			}
			OnWatch();
			break;
		case EMenuState::MSAT_Disabled:
			if (Controller->ActiveControl == this)
			{
				Controller->ActiveControl = nullptr;
			}
			if (Controller->FocusedControl == this)
			{
				LoseFocus(nullptr);
			}
			break;
		default:
			break;
	}
	if (FriendlyLabel != nullptr)
	{
		FriendlyLabel->MenuState = MenuState;
	}
}

bool UGUIComponent::IsMultiSelect()
{
	if (Controller == nullptr)
	{
		return false;
	}
	return bDropSource&& DropState != EDropState::DRP_Source && Controller->CtrlPressed && OnMultiSelect(this);
}

void UGUIComponent::DropStateChange(EDropState NewState)
{
	if (Controller == nullptr)
	{
		return;
	}
	switch (NewState)
	{
		case EDropState::DRP_None:
			if (Controller->DropTarget == this)
			{
				OnDragLeave(this);
				Controller->DropTarget = nullptr;
				if (Controller->DropSource == this)
				{
					return;
				}
				break;
			}
			if (Controller->DropSource == this)
			{
				UpdateOffset(0, 0, 0, 0);
				Controller->DropSource = nullptr;
			}
			break;
		case EDropState::DRP_Source:
			if (!OnBeginDrag(this))
			{
				return;
			}
			Controller->DropSource = this;
			Controller->PlayInterfaceSound(EClickSound::CS_Drag);
			break;
		case EDropState::DRP_Target:
			Controller->DropTarget = this;
			if (DropState == EDropState::DRP_None)
			{
				OnDragEnter(this);
			}
			break;
		case EDropState::DRP_Accept:
			Controller->PlayInterfaceSound(EClickSound::CS_Up);
			if (Controller->DropSource != nullptr)
			{
				Controller->DropSource->OnEndDrag(this, true);
			}
			Controller->DropTarget = nullptr;
			NewState = EDropState::DRP_None;
			break;
		case EDropState::DRP_Reject:
			Controller->PlayInterfaceSound(EClickSound::CS_Down);
			if (Controller->DropSource != nullptr)
			{
				Controller->DropSource->OnEndDrag(this, false);
			}
			Controller->DropTarget = nullptr;
			NewState = EDropState::DRP_None;
			break;
		default:
			break;
	}
	DropState = NewState;
}

void UGUIComponent::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Controller = MyController;
	MenuOwner = MyOwner;
	PageOwner = OwnerPage();
	if (Style == nullptr)
	{
		Style = Controller->GetStyle(StyleName, FontScale);
	}
}

bool UGUIComponent::IsInBounds()
{
	return Controller->MouseX >= Bounds[0] && Controller->MouseX <= Bounds[2] && Controller->MouseY >= Bounds[1] && Controller->MouseY <= Bounds[3];
}

bool UGUIComponent::IsInClientBounds()
{
	return Controller->MouseX >= ClientBounds[0] && Controller->MouseX <= ClientBounds[2] && Controller->MouseY >= ClientBounds[1] && Controller->MouseY <= ClientBounds[3];
}

bool UGUIComponent::CanAcceptFocus()
{
	return MenuState != EMenuState::MSAT_Disabled && bVisible && !bNeverFocus;
}

void UGUIComponent::SetFocus(UGUIComponent* Who)
{
	if (Who == nullptr)
	{
		if (bNeverFocus)
		{
			if (FocusInstead != nullptr)
			{
				FocusInstead->SetFocus(Who);
			}
			return;
		}
		bPendingFocus = true;
		if (Controller->FocusedControl != nullptr)
		{
			if (Controller->FocusedControl == this)
			{
				return;
			}
			else
			{
				Controller->FocusedControl->LoseFocus(this);
			}
		}
		MenuStateChange(EMenuState::MSAT_Focused);
		Controller->FocusedControl = this;
		OnActivate();
	}
	else
	{
		MenuStateChange(EMenuState::MSAT_Focused);
	}
	if (MenuOwner != nullptr)
	{
		MenuOwner->SetFocus(this);
	}
}

void UGUIComponent::LoseFocus(UGUIComponent* Sender)
{
	if (Controller != nullptr)
	{
		Controller->FocusedControl = nullptr;
	}
	if (MenuState != EMenuState::MSAT_Disabled)
	{
		MenuStateChange(EMenuState::MSAT_Blurry);
	}
	if (MenuOwner != nullptr)
	{
		MenuOwner->LoseFocus(this);
	}
}

bool UGUIComponent::FocusFirst(UGUIComponent* Sender)
{
	if (!bTabStop || !CanAcceptFocus())
	{
		return false;
	}
	SetFocus(nullptr);
	return true;
}

bool UGUIComponent::FocusLast(UGUIComponent* Sender)
{
	if (!bTabStop || !CanAcceptFocus())
	{
		return false;
	}
	SetFocus(nullptr);
	return true;
}

bool UGUIComponent::NextControl(UGUIComponent* Sender)
{
	if (MenuOwner != nullptr)
	{
		return MenuOwner->NextControl(this);
	}
	return false;
}

bool UGUIComponent::PrevControl(UGUIComponent* Sender)
{
	if (MenuOwner != nullptr)
	{
		return MenuOwner->PrevControl(this);
	}
	return false;
}

bool UGUIComponent::NextPage()
{
	if (MenuOwner != nullptr)
	{
		return MenuOwner->NextPage();
	}
	return false;
}

bool UGUIComponent::PrevPage()
{
	if (MenuOwner != nullptr)
	{
		return MenuOwner->PrevPage();
	}
	return false;
}

void UGUIComponent::FillOwner()
{
	WinLeft = 0;
	WinTop = 0;
	WinWidth = 1;
	WinHeight = 1;
	bScaleToParent = true;
	bBoundToParent = true;
}

void UGUIComponent::SetVisibility(bool bIsVisible)
{
	bVisible = bIsVisible;
	if (bVisible)
	{
		OnShow();
	}
	else
	{
		OnHide();
	}
}

void UGUIComponent::CenterMouse()
{
	APlayerController* PC = nullptr;
	float MidX = 0;
	float MidY = 0;
	PC = PlayerOwner();
	if (PC != nullptr)
	{
		MidX = ActualLeft(0,false) + ActualWidth(0,false) / 2;
		MidY = ActualTop(0,false) + ActualHeight(0,false) / 2;
		//PC->ConsoleCommand("SETMOUSE" @ MidX @ MidY);
	}
}
void UGUIComponent::Hide()
{
	SetVisibility(false);
}

void UGUIComponent::Show()
{
	SetVisibility(true);
}

void UGUIComponent::SetFocusInstead(UGUIComponent* InFocusComp)
{
	if (InFocusComp != nullptr)
	{
		bNeverFocus = true;
	}
	FocusInstead = InFocusComp;
}

void UGUIComponent::SetFriendlyLabel(UGUILabel* NewLabel)
{
	FriendlyLabel = NewLabel;
}

void UGUIComponent::SetHint(FString NewHint)
{
	Hint = NewHint;
	SetToolTipText(Hint);
}

void UGUIComponent::SetToolTipText(FString NewToolTipText)
{
	if (ToolTip != nullptr)
	{
		ToolTip->SetTip(NewToolTipText);
	}
}

void UGUIComponent::SetTooltip(UGUIToolTip* InTooltip)
{
	if (ToolTip != nullptr)
	{
		ToolTip->LeaveArea();
	}
	ToolTip = InTooltip;
	if (ToolTip != nullptr)
	{
		ToolTip->InitComponent(Controller, this);
	}
}

void UGUIComponent::PadLeft(FString &Src, int32 StrLen, FString PadStr)
{
	if (PadStr == "")
	{
		PadStr = " ";
	}
	if (Src.Len() < StrLen)
	{
		Src = PadStr + Src;
	}
}

void UGUIComponent::PadRight(FString &Src, int32 StrLen, FString PadStr)
{
	if (PadStr == "")
	{
		PadStr = " ";
	}
	if (Src.Len() < StrLen)
	{
		Src = Src + PadStr;
	}
}

void UGUIComponent::DebugFocus(UGUIComponent* Who, bool bLose)
{
	return;
	//Below isnt run anyway
	if (Controller != nullptr && Controller->CtrlPressed)
	{
		if (bLose)
		{
			if (Who == nullptr)
			{
				//Log(Name @ "losing focus chain down");
			}
			else
			{
				//Log(Name @ "losing focus of" @ Who);
			}
		}
		else
		{
			if (Who == nullptr)
			{
				//Log(Name @ "sending focus chain down");
			}
			else
			{
				//Log(Name @ "setting focus to" @ Who);
			}
		}
	}
}

void UGUIComponent::DebugFocusPosition(UGUIComponent* Who, bool Last)
{
	return;
	//Below isnt run anyway
	if (Controller->CtrlPressed)
	{
		if (Last)
		{
			if (Who == nullptr)
			{
				//Log(Name @ "FocusLast going down");
			}
			else
			{
				//Log(Name @ "FocusLast call from" @ Who);
			}
		}
		else
		{
			if (Who == nullptr)
			{
				//Log(Name @ "FocusFirst going down");
			}
			else
			{
				//Log(Name @ "FocusFirst call from" @ Who);
			}
		}
	}
}

UGUIPage* UGUIComponent::OwnerPage()
{
	UGUIComponent* C = nullptr;
	if (PageOwner != nullptr)
	{
		return PageOwner;
	}
	for (C=this; C!=nullptr; C=C->MenuOwner)
	{
		if (Cast<UGUIPage>(C) != nullptr)
		{
			return Cast<UGUIPage>(C);
		}
	}
	//Warn("OwnerPage not found!");
	return nullptr;
}

void UGUIComponent::BeginAnimation(UGUIComponent* Animating)
{
	bAnimating = true;
	if (MenuOwner != nullptr)
	{
		MenuOwner->BeginAnimation(Animating);
	}
}

void UGUIComponent::EndAnimation(UGUIComponent* Animating, EAnimationType Type)
{
	bAnimating = false;
	if (MenuOwner != nullptr)
	{
		MenuOwner->EndAnimation(Animating, Type);
	}
	if (Animating == this)
	{
		OnEndAnimation(Animating, Type);
	}
}

void UGUIComponent::Animate(float NewLeft, float NewTop, float Time)
{
	int32 i = 0;
	i = MotionFrame.Num();
	MotionFrame.SetNum(i + 1);
	MotionFrame[i].X = NewLeft;
	MotionFrame[i].Y = NewTop;
	MotionFrame[i].Z = Time;
	if (i < 1)
	{
		BeginAnimation(this);
	}
}

void UGUIComponent::Resize(float NewWidth, float NewHeight, float Time)
{
	int32 i = 0;
	i = SizeFrame.Num();
	SizeFrame.SetNum(i + 1);
	SizeFrame[i].X = NewWidth;
	SizeFrame[i].Y = NewHeight;
	SizeFrame[i].Z = Time;
	if (i < 1)
	{
		BeginAnimation(this);
	}
}

void UGUIComponent::DAnimate(float NewLeft, float NewTop, float NewWidth, float NewHeight, float PositionTime, float DimensionTime)
{
	Animate(NewLeft, NewTop, PositionTime);
	Resize(NewWidth, NewHeight, DimensionTime);
}

void UGUIComponent::KillAnimation()
{
	if (MotionFrame.Num() > 0)
	{
		MotionFrame.RemoveAt(0, MotionFrame.Num());
		EndAnimation(this, EAnimationType::AT_Position);
	}
	if (SizeFrame.Num() > 0)
	{
		SizeFrame.RemoveAt(0, SizeFrame.Num());
		EndAnimation(this, EAnimationType::AT_Dimension);
	}
}

void UGUIComponent::EnableComponent(UGUIComponent* Comp)
{
	if (Comp == nullptr)
	{
		return;
	}
	Comp->EnableMe();
}

void UGUIComponent::DisableComponent(UGUIComponent* Comp)
{
	if (Comp == nullptr)
	{
		return;
	}
	Comp->DisableMe();
}

void UGUIComponent::EnableMe()
{
	if (MenuState != EMenuState::MSAT_Disabled)
	{
		return;
	}
	MenuStateChange(EMenuState::MSAT_Blurry);
}

void UGUIComponent::DisableMe()
{
	if (MenuState == EMenuState::MSAT_Disabled)
	{
		return;
	}
	MenuStateChange(EMenuState::MSAT_Disabled);
}

void UGUIComponent::LevelChanged()
{
	if (ToolTip != nullptr)
	{
		ToolTip->Free();
	}
}

void UGUIComponent::DebugTabOrder()
{
}
