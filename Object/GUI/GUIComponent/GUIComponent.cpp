// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UGUIComponent::UGUIComponent()
{
	FontScale = EFontScale::FNS_Medium;
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
		//Log("OnPreDraw called" @ OnPreDrawCount @ "times: " $ GetMenuPath());
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
		//Log("OnDraw called" @ OnDrawCount @ "times: " $ GetMenuPath());
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
		//Log("OnRender called" @ OnRenderCount @ "times: " $ GetMenuPath());
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

bool UGUIComponent::OnBeginTooltip()
{
	/*
	if (ToolTip != nullptr)
	{
		return ToolTip->EnterArea();
	}
	else
	{
		if (MenuOwner != nullptr)
		{
			Return MenuOwner.OnBeginTooltip();
		}
	}
	return nullptr;
	*/
	return false;    //FAKE   /ELiZ
}
bool UGUIComponent::OnEndTooltip()
{
	/*
	if (ToolTip != nullptr)
	{
		Return ToolTip.LeaveArea();
	}
	else
	{
		if (MenuOwner != nullptr)
		{
			Return MenuOwner.OnEndTooltip();
		}
	}
	return true;
	*/

	return false;    //FAKE   /ELiZ
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

void UGUIComponent::OnSaveINI(UGUIComponent* Sender)
{
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
void UGUIComponent::PlayerOwner()
{
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
void UGUIComponent::ActualLeft(float Val, bool bForce)
{
}

//native(823) final Function ActualTop(float Val, bool bForce);
void UGUIComponent::ActualTop(float Val, bool bForce)
{
}

//native(824) final Function RelativeLeft(float RealLeft, bool bForce);
void UGUIComponent::RelativeLeft(float RealLeft, bool bForce)
{
}

//native(825) final Function RelativeTop(float RealTop, bool bForce);
void UGUIComponent::RelativeTop(float RealTop, bool bForce)
{
}

//native(826) final Function RelativeWidth(float RealWidth, bool bForce);
void UGUIComponent::RelativeWidth(float RealWidth, bool bForce)
{
}

//native(827) final Function RelativeHeight(float RealHeight, bool bForce);
void UGUIComponent::RelativeHeight(float RealHeight, bool bForce)
{
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
	/*
	if (bDebugging && Controller == None || Controller.bModAuthor)
	{
		Log(Name $ ".SetPosition( " $ NewLeft $ "," @ NewTop $ "," @ NewWidth $ "," @ NewHeight $ "," @ bForceRelative, 'ModAuthor');
	}
	if (bForceRelative)
	{
		WinLeft = RelativeLeft(NewLeft);
		WinTop = RelativeTop(NewTop);
		WinWidth = RelativeWidth(NewWidth);
		WinHeight = RelativeHeight(NewHeight);
	}
	else
	{
		WinLeft = NewLeft;
		WinTop = NewTop;
		WinWidth = NewWidth;
		WinHeight = NewHeight;
	}
	if (bDebugging && bForceRelative && Controller == None || Controller.bModAuthor)
	{
		Log(Name @ "SetPosition() Current L:" $ WinLeft $ "(" $ Bounds[0] $ ") T:" $ WinTop $ "(" $ Bounds[1] $ ") W:" $ WinWidth $ "(" $ Bounds[0] + Bounds[2] $ ") H:" $ WinHeight $ "(" $ Bounds[1] + Bounds[3] $ ")", 'ModAuthor');
	}
	*/
}

FString UGUIComponent::AdditionalDebugString()
{
	return "";
}
void UGUIComponent::Timer()
{
	//OnTimer(Self);
}
void UGUIComponent::Opened(UGUIComponent* Sender)
{
	LoadINI();
	/*
	if (ToolTip != None)
	{
		ToolTip.InitComponent(Controller, Self);
		SetToolTipText(Hint);
	}
	*/
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
	//PageOwner = nullptr;
	//Controller = nullptr;
	FocusInstead = nullptr;
	//FriendlyLabel = nullptr;
	//Style = nullptr;
	/*
	if (ToolTip != nullptr)
	{
		ToolTip->Free();
	}
	ToolTip = nullptr;
	*/
}
FString UGUIComponent::LoadINI()
{
	/*
	local string S;
	if (PlayerOwner() == None || IniOption == "")
	{
		Return "";
	}
	if (IniOption ~= "@Internal")
	{
		OnLoadINI(Self, "");
		Return "";
	}
	S = PlayerOwner().ConsoleCommand("get" @ IniOption);
	if (S == "")
	{
		S = IniDefault;
	}
	OnLoadINI(Self, S);
	Return S;
	*/
	return "";		//FAKE  /EliZ
}
void UGUIComponent::SaveINI(FString Value)
{
	/*
	if (PlayerOwner() == nullptr)
	{
		return;
	}
	OnSaveINI(this);
	*/
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
	/*
	if (MenuState != 1)
	{
		LastMenuState = MenuState;
	}
	bPendingFocus = False;
	MenuState = NewState;
	Switch(MenuState)
	{
			case 2:
				if (!bNeverFocus)
				{
					bHasFocus = true;
					break;
				}
				MenuState = 0;
			case 0:
				bHasFocus = False;
				if (LastMenuState != 0 && LastMenuState != 4)
				{
					OnDeActivate();
				}
				break;
			case 1:
				if (bFocusOnWatch)
				{
					SetFocus(None);
					Return;
				}
				OnWatch();
				break;
			case 4:
				if (Controller.ActiveControl == Self)
				{
					Controller.ActiveControl = None;
				}
				if (Controller.FocusedControl == Self)
				{
					LoseFocus(None);
				}
				break;
			default:
	}
	if (FriendlyLabel != None)
	{
		FriendlyLabel.MenuState = MenuState;
	}
	*/
}
bool UGUIComponent::IsMultiSelect()
{
	/*
	if (Controller == nullptr)
	{
		return false;
	}
	return bDropSource&& DropState != EDropState::DRP_Source && Controller->CtrlPressed && OnMultiSelect(this);
	*/

	return false;		//FAKE    /ELiZ
}
void UGUIComponent::DropStateChange(EDropState NewState)
{
	/*
	if (Controller == None)
	{
		Return;
	}
	Switch(NewState)
	{
			case 0:
				if (Controller.DropTarget == Self)
				{
					OnDragLeave(Self);
					Controller.DropTarget = None;
					if (Controller.DropSource == Self)
					{
						Return;
					}
					break;
				}
				if (Controller.DropSource == Self)
				{
					UpdateOffset(0, 0, 0, 0);
					Controller.DropSource = None;
				}
	}
	GOTO JL01D6;
		case 1:
			if (!OnBeginDrag(Self))
			{
				Return;
			}
			Controller.DropSource = Self;
			Controller.PlayInterfaceSound(5);
			GOTO JL01D6;
		case 2:
			Controller.DropTarget = Self;
			if (DropState == 0)
			{
				OnDragEnter(Self);
			}
			GOTO JL01D6;
		case 3:
			Controller.PlayInterfaceSound(3);
			if (Controller.DropSource != None)
			{
				Controller.DropSource.OnEndDrag(Self, true);
			}
			Controller.DropTarget = None;
			NewState = 0;
			GOTO JL01D6;
		case 4:
			Controller.PlayInterfaceSound(4);
			if (Controller.DropSource != None)
			{
				Controller.DropSource.OnEndDrag(Self, false);
			}
			Controller.DropTarget = None;
			NewState = 0;
			GOTO JL01D6;
		default:
		JL01D6:
			DropState = NewState;

	*/
}
void UGUIComponent::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Controller = MyController;
	MenuOwner = MyOwner;
	PageOwner = OwnerPage();
	if (Style == nullptr)
	{
		Style = Controller->GetStyle(StyleName, FontScale);
	}
	*/
}
bool UGUIComponent::IsInBounds()
{
	//return Controller->MouseX >= Bounds[0] && Controller->MouseX <= Bounds[2] && Controller->MouseY >= Bounds[1] && Controller->MouseY <= Bounds[3];

	return false;   //FAKE /ELiZ
}
bool UGUIComponent::IsInClientBounds()
{
	//return Controller->MouseX >= ClientBounds[0] && Controller->MouseX <= ClientBounds[2] && Controller->MouseY >= ClientBounds[1] && Controller->MouseY <= ClientBounds[3];

	return false;   //FAKE /ELiZ
}
bool UGUIComponent::CanAcceptFocus()
{
	return MenuState != EMenuState::MSAT_Disabled && bVisible && !bNeverFocus;
}
void UGUIComponent::SetFocus(UGUIComponent* Who)
{
	/*
	if (Who == None)
	{
		if (bNeverFocus)
		{
			if (FocusInstead != None)
			{
				FocusInstead.SetFocus(Who);
			}
			Return;
		}
		bPendingFocus = true;
		if (Controller.FocusedControl != None)
		{
			if (Controller.FocusedControl == Self)
			{
				Return;
			}
			else
			{
				Controller.FocusedControl.LoseFocus(Self);
			}
		}
		MenuStateChange(2);
		Controller.FocusedControl = Self;
		OnActivate();
	}
	else
	{
		MenuStateChange(2);
	}
	if (MenuOwner != None)
	{
		MenuOwner.SetFocus(Self);
	}
	*/
}
void UGUIComponent::LoseFocus(UGUIComponent* Sender)
{
	/*
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
	*/
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
	/*
	local PlayerController PC;
	local float MidX;
	local float MidY;
	PC = PlayerOwner();
	if (PC != None)
	{
		MidX = ActualLeft() + ActualWidth() / 2;
		MidY = ActualTop() + ActualHeight() / 2;
		PC.ConsoleCommand("SETMOUSE" @ MidX @ MidY);
	}
	*/
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
/*
void UGUIComponent::SetFriendlyLabel(UGUILabel* NewLabel)
{
	FriendlyLabel = NewLabel;
}
*/
void UGUIComponent::SetHint(FString NewHint)
{
	Hint = NewHint;
	SetToolTipText(Hint);
}
void UGUIComponent::SetToolTipText(FString NewToolTipText)
{
	/*
	if (ToolTip != None)
	{
		ToolTip.SetTip(NewToolTipText);
	}
	*/
}

/*
void UGUIComponent::SetTooltip(UGUIToolTip* InTooltip)
{
	if (ToolTip != None)
	{
		ToolTip.LeaveArea();
	}
	ToolTip = InTooltip;
	if (ToolTip != None)
	{
		ToolTip.InitComponent(Controller, Self);
	}
}
*/
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
	/*
	if (Controller != None && Controller.CtrlPressed)
	{
		if (bLose)
		{
			if (Who == None)
			{
				Log(Name @ "losing focus chain down");
			}
			else
			{
				Log(Name @ "losing focus of" @ Who);
			}
		}
		else
		{
			if (Who == None)
			{
				Log(Name @ "sending focus chain down");
			}
			else
			{
				Log(Name @ "setting focus to" @ Who);
			}
		}
	}
	*/
}
void UGUIComponent::DebugFocusPosition(UGUIComponent* Who, bool Last)
{
	return;
	//Below isnt run anyway
	/*
	if (Controller.CtrlPressed)
	{
		if (Last)
		{
			if (Who == None)
			{
				Log(Name @ "FocusLast going down");
			}
			else
			{
				Log(Name @ "FocusLast call from" @ Who);
			}
		}
		else
		{
			if (Who == None)
			{
				Log(Name @ "FocusFirst going down");
			}
			else
			{
				Log(Name @ "FocusFirst call from" @ Who);
			}
		}
	}
	*/
}
/*
UGUIPage* UGUIComponent::OwnerPage()
{
	local GUIComponent C;
	if (PageOwner != None)
	{
		Return PageOwner;
	}
	C = Self;
	if (C != None)
	{
		if (GUIPage(C) != None)
		{
			Return GUIPage(C);
		}
		C = C.MenuOwner;
	}
	Warn("OwnerPage not found!");
	Return None;
}
*/
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
	/*
	local int i;
	i = MotionFrame.Length;
	MotionFrame.Length = i + 1;
	MotionFrame[i].X = NewLeft;
	MotionFrame[i].Y = NewTop;
	MotionFrame[i].Z = Time;
	if (i < 1)
	{
		BeginAnimation(Self);
	}
	*/
}
void UGUIComponent::Resize(float NewWidth, float NewHeight, float Time)
{
	/*
	local int i;
	i = SizeFrame.Length;
	SizeFrame.Length = i + 1;
	SizeFrame[i].X = NewWidth;
	SizeFrame[i].Y = NewHeight;
	SizeFrame[i].Z = Time;
	if (i < 1)
	{
		BeginAnimation(Self);
	}
	*/
}
void UGUIComponent::DAnimate(float NewLeft, float NewTop, float NewWidth, float NewHeight, float PositionTime, float DimensionTime)
{
	Animate(NewLeft, NewTop, PositionTime);
	Resize(NewWidth, NewHeight, DimensionTime);
}
void UGUIComponent::KillAnimation()
{
	/*
	if (MotionFrame.Length > 0)
	{
		MotionFrame.remove(0, MotionFrame.Length);
		EndAnimation(Self, 0);
	}
	if (SizeFrame.Length > 0)
	{
		SizeFrame.remove(0, SizeFrame.Length);
		EndAnimation(Self, 1);
	}
	*/
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
	/*
	if (ToolTip != nullptr)
	{
		ToolTip->Free();
	}
	*/
}
void UGUIComponent::DebugTabOrder()
{
}
