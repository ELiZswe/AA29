// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/LargeWindow.h"

ULargeWindow::ULargeWindow()
{
	bResizeWidthAllowed = false;
	bResizeHeightAllowed = false;
	bMoveAllowed = false;
	bCaptureInput = true;
	bRequire640x480 = true;
	InactiveFadeColor = FColor(60, 60, 60, 255);
	//OnCreateComponent = None.None;
	WinTop = 0.2;
	WinLeft = 0.2;
	WinWidth = 0.6;
	WinHeight = 0.6;
}