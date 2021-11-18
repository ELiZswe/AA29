// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_Page.h"

UBrowser_Page::UBrowser_Page()
{
	StartQueryString = "Querying Master Server";
	AuthFailString = "Authentication Failed";
	ConnFailString = "Connection Failed - Retrying";
	ConnTimeoutString = "Connection Timed Out";
	QueryCompleteString = "Query Complete!";
	RefreshCompleteString = "Refresh Complete!";
	ReadyString = "Ready";
	bFillHeight = true;
	WinTop = 0.15;
	WinHeight = 0.85;
}

void UBrowser_Page::OnCloseBrowser()
{
}
