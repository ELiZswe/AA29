// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LockedFloatingWindow/LockedFloatingWindow.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUISectionBackground/AltSectionBackground/AltSectionBackground.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"

ULockedFloatingWindow::ULockedFloatingWindow()
{
	UAltSectionBackground* InternalFrameImage = NewObject<UAltSectionBackground>(UAltSectionBackground::StaticClass());
	InternalFrameImage->WinTop = 0.075;
	InternalFrameImage->WinLeft = 0.04;
	InternalFrameImage->WinWidth = 0.675859;
	InternalFrameImage->WinHeight = 0.550976;
	//InternalFrameImage->OnPreDraw=InternalFrameImage.InternalPreDraw;
	UGUIButton* LockedCancelButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	LockedCancelButton->Caption = "Cancel";
	LockedCancelButton->bAutoShrink = false;
	LockedCancelButton->WinTop = 0.872397;
	LockedCancelButton->WinLeft = 0.512695;
	LockedCancelButton->WinWidth = 0.159649;
	LockedCancelButton->TabOrder = 99;
	LockedCancelButton->bBoundToParent = true;
	//LockedCancelButton->OnClick=LockedFloatingWindow.InternalOnClick;
	//LockedCancelButton->OnKeyEvent=LockedCancelButton.InternalOnKeyEvent;
	UGUIButton* LockedOKButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	LockedOKButton->Caption = "OK";
	LockedOKButton->bAutoShrink = false;
	LockedOKButton->WinTop = 0.872397;
	LockedOKButton->WinLeft = 0.742188;
	LockedOKButton->WinWidth = 0.159649;
	LockedOKButton->TabOrder = 100;
	LockedOKButton->bBoundToParent = true;
	//LockedOKButton->OnClick=LockedFloatingWindow.InternalOnClick;
	//LockedOKButton->OnKeyEvent=LockedOKButton.InternalOnKeyEvent;
	sb_Main = InternalFrameImage;
	b_Cancel = LockedCancelButton;
	b_OK = LockedOKButton;
	EdgeBorder = { 16,24,16,24 };
	bResizeWidthAllowed = false;
	bResizeHeightAllowed = false;
	DefaultLeft = 0.125;
	DefaultTop = 0.15;
	DefaultWidth = 0.74;
	DefaultHeight = 0.7;
	bCaptureInput = true;
	InactiveFadeColor = FColor(60, 60, 60, 255);
	WinTop = 0.15;
	WinLeft = 0.125;
	WinWidth = 0.74;
	WinHeight = 0.7;
}

void ULockedFloatingWindow::InitComponent(UGUIController* InController, UGUIComponent* InOwner)
{
	/*
	Super::InitComponent(InController, InOwner);
	if (SubCaption != "")
	{
		sb_Main.Caption = SubCaption;
	}
	AlignButtons();
	*/
}

void ULockedFloatingWindow::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender)
{
	/*
	if (Sender == Self)
	{
		NewComp.bBoundToParent = true;
	}
	else
	{
		Super::InternalOnCreateComponent(NewComp, Sender);
	}
	*/
}

bool ULockedFloatingWindow::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (Sender == b_OK)
	{
		Controller.CloseMenu(false);
		return true;
	}
	if (Sender == b_Cancel)
	{
		Controller.CloseMenu(true);
		return true;
	}
	*/
	return false;
}

void ULockedFloatingWindow::AlignButtons()
{
	/*
	float X = 0;
	float Y = 0;
	float Xs = 0;
	float Ys = 0;
	float WIP = 0;
	float HIP = 0;
	WIP = ActualWidth();
	HIP = ActualHeight();
	Xs = (b_OK.ActualWidth() * 0.1);
	Ys = (b_OK.ActualHeight() * 0.1);
	X = ((1 - ((b_OK.ActualWidth() + Xs) / WIP)) - (EdgeBorder[2] / WIP));
	Y = ((1 - ((b_OK.ActualHeight() + Ys) / HIP)) - (EdgeBorder[3] / WIP));
	b_OK.WinLeft = X;
	b_OK.WinTop = Y;
	X = ((1 - (((b_OK.ActualWidth() + b_Cancel.ActualWidth()) + Xs) / WIP)) - (EdgeBorder[2] / WIP));
	b_Cancel.WinLeft = X;
	b_Cancel.WinTop = Y;
	*/
}
