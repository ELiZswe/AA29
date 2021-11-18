// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIFont/AAFontEntryPageButton/AAFontEntryPageButton.h"

UAAFontEntryPageButton::UAAFontEntryPageButton()
{
	KeyName = "AAFontEntryPageButton";
	//FontArrayNames =
	MaxValue = 10;
	MinValue = 1;
	CaptionWidth = 0.6;
	Caption = "Voice Chat Volume";
	//__OnCreateComponent__Delegate = "VoiceVolume.InternalOnCreateComponent";
	IniOption = "@Internal";
	Hint = "Adjusts the volume of other players' voice chat communication.";
	WinTop = 0.142484;
	WinLeft = 0.518507;
	WinWidth = 0.408907;
	RenderWeight = 1.04;
	TabOrder = 0;
	bStandardized = false;
	//__OnChange__Delegate = "VoiceChatConfig.InternalOnChange"
	//__OnLoadINI__Delegate = "VoiceChatConfig.InternalOnLoadINI"
}