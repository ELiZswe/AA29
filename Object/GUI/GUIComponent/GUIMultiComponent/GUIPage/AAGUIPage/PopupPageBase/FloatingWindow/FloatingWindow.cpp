// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/FloatingWindow.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUITitleBar/GUIHeader/GUIHeader.h"

UFloatingWindow::UFloatingWindow()
{
	UGUIHeader* TitleBar = NewObject<UGUIHeader>(UGUIHeader::StaticClass());
	TitleBar->bUseTextHeight = true;
	TitleBar->WinHeight = 0.04375;
	TitleBar->RenderWeight = 0.1;
	TitleBar->bBoundToParent = true;
	TitleBar->bScaleToParent = true;
	TitleBar->bAcceptsInput = true;
	TitleBar->bNeverFocus = false;
	TitleBar->ScalingType = EParentScaleType::SCALE_X;
	//TitleBar->OnMousePressed=FloatingWindow.FloatingMousePressed;
	//TitleBar->OnMouseRelease=FloatingWindow.FloatingMouseRelease;
	t_WindowTitle = TitleBar;
	MinPageWidth = 0.1;
	MinPageHeight = 0.1;
	MaxPageHeight = 1;
	MaxPageWidth = 1;
	bResizeWidthAllowed = true;
	bResizeHeightAllowed = true;
	bMoveAllowed = true;
	DefaultLeft = 0.2;
	DefaultTop = 0.2;
	DefaultWidth = 0.6;
	DefaultHeight = 0.6;
	HeaderMouseCursorIndex = 1;
	bCaptureInput = false;
	InactiveFadeColor = FColor(255, 255, 255, 255);
	//OnCreateComponent = FloatingWindow.InternalOnCreateComponent;
	//OnPreDraw = FloatingWindow.FloatingPreDraw;
	//OnRendered = FloatingWindow.FloatingRendered;
	//OnHover = FloatingWindow.FloatingHover;
	//OnMousePressed = FloatingWindow.FloatingMousePressed;
	//OnMouseRelease = FloatingWindow.FloatingMouseRelease;
}

void UFloatingWindow::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	t_WindowTitle.SetCaption(WindowName);
	if (bMoveAllowed)
	{
		t_WindowTitle.bAcceptsInput = true;
		t_WindowTitle.MouseCursorIndex = HeaderMouseCursorIndex;
	}
	AddSystemMenu();
	i_FrameBG.__OnPreDraw__Delegate = AlignFrame;
	*/
}

bool UFloatingWindow::AlignFrame(UCanvas* C)
{
	/*
	i_FrameBG.WinHeight = i_FrameBG.RelativeHeight((ActualHeight() - (t_WindowTitle.ActualHeight() * 0.5)));
	i_FrameBG.WinTop = i_FrameBG.RelativeTop((ActualTop() + (t_WindowTitle.ActualHeight() * 0.5)));
	*/
	return bInit;
}

void UFloatingWindow::AddSystemMenu()
{
	/*
	local GUI.eFontScale tFontScale;
	b_ExitButton = GUIButton(t_WindowTitle.AddComponent("XInterface.GUIButton"));
	b_ExitButton.Style = Controller.GetStyle("CloseButton", tFontScale);
	b_ExitButton.__OnClick__Delegate = XButtonClicked;
	b_ExitButton.bNeverFocus = true;
	b_ExitButton.FocusInstead = t_WindowTitle;
	b_ExitButton.RenderWeight = 1;
	b_ExitButton.bScaleToParent = false;
	b_ExitButton.__OnPreDraw__Delegate = SystemMenuPreDraw;
	b_ExitButton.bRepeatClick = false;
	*/
}

bool UFloatingWindow::SystemMenuPreDraw(UCanvas* Canvas)
{
	//b_ExitButton.SetPosition((t_WindowTitle.ActualLeft() + (t_WindowTitle.ActualWidth() - float(35))), t_WindowTitle.ActualTop(), 24, 24, true);
	return true;
}

void UFloatingWindow::CheckBounds()
{
	/*
	float AH = 0;
	float AW = 0;
	float AL = 0;
	float At = 0;
	AW = FClamp(ActualWidth(), 0, float(Controller.ResX));
	AH = FClamp(ActualHeight(), 0, float(Controller.ResY));
	At = FClamp(ActualTop(), 0, (float(Controller.ResY) - AH));
	AL = FClamp(ActualLeft(), 0, (float(Controller.ResX) - AW));
	SetPosition(AL, At, AW, AH, true);
	*/
}

void UFloatingWindow::SetDefaultPosition()
{
	/*
	float RH = 0;
	float RW = 0;
	if (!bPositioned)
	{
		return;
	}
	bInit = false;
	if (!bResizeWidthAllowed)
	{
		DefaultWidth = WinWidth;
	}
	if (!bResizeHeightAllowed)
	{
		DefaultHeight = WinHeight;
	}
	if (!bMoveAllowed)
	{
		DefaultLeft = WinLeft;
		DefaultTop = WinTop;
	}
	RW = FClamp(RelativeWidth(DefaultWidth), RelativeWidth(MinPageWidth), RelativeWidth(MaxPageWidth));
	RH = FClamp(RelativeHeight(DefaultHeight), RelativeHeight(MinPageHeight), RelativeHeight(MaxPageHeight));
	SetPosition(FClamp(RelativeLeft(DefaultLeft), 0, (RelativeLeft(float(Controller.ResX)) - RW)), FClamp(RelativeTop(DefaultTop), 0, (RelativeTop(float(Controller.ResY)) - RH)), RW, RH);
	*/
}

void UFloatingWindow::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender)
{
	/*
	if (Sender == Self)
	{
		NewComp.bBoundToParent = true;
		NewComp.bScaleToParent = true;
		if ((!bResizeHeightAllowed) && bResizeWidthAllowed)
		{
			NewComp.ScalingType = 1;
		}
		else
		{
			if ((!bResizeWidthAllowed) && bResizeHeightAllowed)
			{
				NewComp.ScalingType = 2;
			}
		}
	}
	*/
}

void UFloatingWindow::SetFocus(UGUIComponent* Who)
{
	/*
	if (AAGUIController(Controller) != None)
	{
		AAGUIController(Controller).SetFocusTo(Self);
	}
	Super::SetFocus(Who);
	*/
}

void UFloatingWindow::FloatingMousePressed(UGUIComponent* Sender, bool bRepeat)
{
	/*
	if ((Controller == None) || bRepeat)
	{
		return;
	}
	TSizing = (bResizeHeightAllowed && HoveringTopBorder());
	RSizing = (bResizeWidthAllowed && HoveringRightBorder());
	LSizing = (bResizeWidthAllowed && HoveringLeftBorder());
	BtSizing = (bResizeHeightAllowed && HoveringBottomBorder());
	bMoving = ((bMoveAllowed && (Controller.ActiveControl == t_WindowTitle)) && (!(((TSizing || RSizing) || BtSizing) || LSizing)));
	if (TSizing)
	{
		if (RSizing || LSizing)
		{
			TRSizing = RSizing;
			TLSizing = LSizing;
			TSizing = false;
			RSizing = false;
			LSizing = false;
		}
	}
	else
	{
		if (BtSizing)
		{
			if (RSizing || LSizing)
			{
				BRSizing = RSizing;
				BLSizing = LSizing;
				BtSizing = false;
				RSizing = false;
				LSizing = false;
			}
		}
	}
	if (bMoving)
	{
		SetMouseCursorIndex(1);
		UpdateOffset(ClientBounds[0], ClientBounds[1], ClientBounds[2], ClientBounds[3]);
	}
	bResizing = ((((((((bMoving || TSizing) || TRSizing) || RSizing) || BRSizing) || BtSizing) || BLSizing) || LSizing) || TLSizing);
	bCaptureMouse = bResizing;
	t_WindowTitle.bCaptureMouse = bCaptureMouse;
	*/
}

void UFloatingWindow::FloatingMouseRelease(UGUIComponent* Sender)
{
	/*
	bool bSave = false;
	bSave = bCaptureMouse;
	bResizing = false;
	bCaptureMouse = false;
	t_WindowTitle.bCaptureMouse = false;
	if (bMoving)
	{
		SetPosition((Controller.MouseX - MouseOffset[0]), (Controller.MouseY - MouseOffset[1]), WinWidth, WinHeight, true);
		CheckBounds();
	}
	bMoving = false;
	TSizing = false;
	BtSizing = false;
	RSizing = false;
	LSizing = false;
	TLSizing = false;
	BLSizing = false;
	TRSizing = false;
	BRSizing = false;
	SetMouseCursorIndex(Default.MouseCursorIndex);
	UpdateOffset(-1, -1, -1, -1);
	if (bSave)
	{
		SaveCurrentPosition();
	}
	*/
}

void UFloatingWindow::SaveCurrentPosition()
{
	/*
	DefaultLeft = WinLeft;
	DefaultTop = WinTop;
	DefaultWidth = WinWidth;
	DefaultHeight = WinHeight;
	SaveConfig();
	*/
}

bool UFloatingWindow::FloatingHover(UGUIComponent* Sender)
{
	/*
	if (!ResizeAllowed())
	{
		return false;
	}
	if (bCaptureMouse)
	{
		return true;
	}
	if ((bResizeHeightAllowed && bResizeWidthAllowed) && ((BLSizing || TRSizing) || HoveringBottomLeft()))
	{
		SetMouseCursorIndex(2);
	}
	else
	{
		if ((bResizeHeightAllowed && bResizeWidthAllowed) && ((TLSizing || BRSizing) || HoveringTopLeft()))
		{
			SetMouseCursorIndex(4);
		}
		else
		{
			if (bResizeHeightAllowed && (((TSizing || BtSizing) || HoveringTopBorder()) || HoveringBottomBorder()))
			{
				SetMouseCursorIndex(3);
			}
			else
			{
				if (bResizeWidthAllowed && (((LSizing || RSizing) || HoveringLeftBorder()) || HoveringRightBorder()))
				{
					SetMouseCursorIndex(5);
				}
				else
				{
					SetMouseCursorIndex(Default.MouseCursorIndex);
				}
			}
		}
	}
	*/
	return true;
}

void UFloatingWindow::SetPanelPosition(UCanvas* C)
{
}

bool UFloatingWindow::FloatingPreDraw(UCanvas* C)
{
	 /*
	float OldW = 0;
	float OldH = 0;
	float DiffX = 0;
	float DiffY = 0;
	float AW = 0;
	float At = 0;
	float AH = 0;
	float AL = 0;
	InternalOnPreDraw(C);
	if (bInit)
	{
		SetDefaultPosition();
	}
	if ((!bCaptureMouse) || bMoving)
	{
		return false;
	}
	SetPanelPosition(C);
	AL = ActualLeft();
	At = ActualTop();
	AW = ActualWidth();
	AH = ActualHeight();
	OldH = AH;
	OldW = AW;
	if (TLSizing)
	{
		DiffX = (Controller.MouseX - AL);
		DiffY = (Controller.MouseY - At);
		WinWidth = RelativeWidth(FClamp((AW - DiffX), ActualWidth(MinPageWidth), ActualWidth(MaxPageWidth)));
		WinHeight = RelativeHeight(FClamp((AH - DiffY), ActualHeight(MinPageHeight), ActualHeight(MaxPageHeight)));
		SetPosition(((AL + OldW) - ActualWidth()), ((At + OldH) - ActualHeight()), WinWidth, WinHeight, true);
		ResizedBoth();
		return true;
	}
	if (TRSizing)
	{
		DiffX = (Controller.MouseX - (AL + AW));
		DiffY = (Controller.MouseY - At);
		WinHeight = RelativeHeight(FClamp((AH - DiffY), ActualHeight(MinPageHeight), ActualHeight(MaxPageHeight)));
		SetPosition(WinLeft, ((At + OldH) - ActualHeight()), FClamp((AW + DiffX), ActualWidth(MinPageWidth), ActualWidth(MaxPageWidth)), WinHeight, true);
		ResizedBoth();
		return true;
	}
	if (BLSizing)
	{
		DiffX = (Controller.MouseX - AL);
		DiffY = (Controller.MouseY - (At + AH));
		WinWidth = RelativeWidth(FClamp((AW - DiffX), ActualWidth(MinPageWidth), ActualWidth(MaxPageWidth)));
		SetPosition(((AL + OldW) - ActualWidth()), WinTop, WinWidth, FClamp((AH + DiffY), ActualHeight(MinPageHeight), ActualHeight(MaxPageHeight)), true);
		ResizedBoth();
		return true;
	}
	if (BRSizing)
	{
		DiffX = (Controller.MouseX - (AL + AW));
		DiffY = (Controller.MouseY - (At + AH));
		SetPosition(WinLeft, WinTop, FClamp((AW + DiffX), ActualWidth(MinPageWidth), ActualWidth(MaxPageWidth)), FClamp((AH + DiffY), ActualHeight(MinPageHeight), ActualHeight(MaxPageHeight)), true);
		ResizedBoth();
		return true;
	}
	if (TSizing)
	{
		DiffY = (Controller.MouseY - At);
		WinHeight = RelativeHeight(FClamp((AH - DiffY), ActualHeight(MinPageHeight), ActualHeight(MaxPageHeight)));
		SetPosition(WinLeft, ((At + OldH) - ActualHeight()), WinWidth, WinHeight, true);
		ResizedHeight();
		return true;
	}
	if (LSizing)
	{
		DiffX = (Controller.MouseX - AL);
		WinWidth = RelativeWidth(FClamp((AW - DiffX), ActualWidth(MinPageWidth), ActualWidth(MaxPageWidth)));
		SetPosition(((AL + OldW) - ActualWidth()), WinTop, WinWidth, WinHeight, true);
		ResizedWidth();
		return true;
	}
	if (RSizing)
	{
		DiffX = (Controller.MouseX - (AL + AW));
		SetPosition(WinLeft, WinTop, FClamp((AW + DiffX), ActualWidth(MinPageWidth), ActualWidth(MaxPageWidth)), WinHeight, true);
		ResizedWidth();
		return true;
	}
	if (BtSizing)
	{
		DiffY = (Controller.MouseY - (At + AH));
		SetPosition(WinLeft, WinTop, WinWidth, FClamp((AH + DiffY), ActualHeight(MinPageHeight), ActualHeight(MaxPageHeight)), true);
		ResizedHeight();
		return true;
	}
	*/
	return false;
}

void UFloatingWindow::FloatingRendered(UCanvas* C)
{
	/*
	if (!bMoving)
	{
		return;
	}
	C.SetPos(FClamp((Controller.MouseX - MouseOffset[0]), 0, (float(Controller.ResX) - ActualWidth())), FClamp((Controller.MouseY - MouseOffset[1]), 0, (float(Controller.ResY) - ActualHeight())));
	C.SetDrawColor(255, 255, 255, 255);
	C.DrawTileStretched(Controller.WhiteBorder, ActualWidth(), ActualHeight());
	*/
}

void UFloatingWindow::ResolutionChanged(int32 ResX, int32 ResY)
{
	/*
	bInit = true;
	Super::ResolutionChanged(ResX, ResY);
	*/
}

void UFloatingWindow::ResizedBoth()
{
}

void UFloatingWindow::ResizedWidth()
{
}

void UFloatingWindow::ResizedHeight()
{
}

bool UFloatingWindow::ResizeAllowed()
{
	//return (bResizeHeightAllowed || bResizeWidthAllowed);
	return false;    //FAKE   /ELiZ
}

bool UFloatingWindow::HoveringLeftBorder()
{
	/*
	if (Controller == None)
	{
		return false;
	}
	return ((Controller.MouseX > (Bounds[0] - 5)) && (Controller.MouseX < (Bounds[0] + 5)));
	*/
	return false;    //FAKE   /ELiZ
}

bool UFloatingWindow::HoveringRightBorder()
{
	/*
	if (Controller == None)
	{
		return false;
	}
	return ((Controller.MouseX > (Bounds[2] - 5)) && (Controller.MouseX < (Bounds[2] + 5)));
	*/
	return false;    //FAKE   /ELiZ
}

bool UFloatingWindow::HoveringTopBorder()
{
	/*
	if (Controller == None)
	{
		return false;
	}
	return ((Controller.MouseY > (Bounds[1] - 5)) && (Controller.MouseY < (Bounds[1] + 5)));
	*/
	return false;    //FAKE   /ELiZ
}

bool UFloatingWindow::HoveringBottomBorder()
{
	/*
	if (Controller == None)
	{
		return false;
	}
	return ((Controller.MouseY > (Bounds[3] - 5)) && (Controller.MouseY < (Bounds[3] + 5)));
	*/
	return false;    //FAKE   /ELiZ
}

bool UFloatingWindow::HoveringTopLeft()
{
	//return ((HoveringLeftBorder() && HoveringTopBorder()) || (HoveringRightBorder() && HoveringBottomBorder()));
	return false;    //FAKE   /ELiZ
}

bool UFloatingWindow::HoveringBottomLeft()
{
	//return ((HoveringRightBorder() && HoveringTopBorder()) || (HoveringLeftBorder() && HoveringBottomBorder()));
	return false;    //FAKE   /ELiZ
}

bool UFloatingWindow::XButtonClicked(UGUIComponent* Sender)
{
	//Controller.CloseMenu(false);
	return true;
}

void UFloatingWindow::SetMouseCursorIndex(int32 NewIndex)
{
	/*
	MouseCursorIndex = NewIndex;
	if (MouseCursorIndex == Default.MouseCursorIndex)
	{
		t_WindowTitle.MouseCursorIndex = HeaderMouseCursorIndex;
	}
	else
	{
		t_WindowTitle.MouseCursorIndex = NewIndex;
	}
	*/
}