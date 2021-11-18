// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LockedFloatingWindow/AADemo2AVI/AADemo2AVI.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moSlider/moSlider.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAADemo2AVI::UAADemo2AVI()
{
	UmoEditBox* ebFilename = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	ebFilename->Caption = "Filename: ";
	//ebFilename->OnCreateComponent=ebFilename.InternalOnCreateComponent;
	ebFilename->Hint = "The name of the AVI file to create";
	ebFilename->WinTop = 0.091667;
	ebFilename->WinLeft = 0.089063;
	ebFilename->WinWidth = 0.895312;
	ebFilename->WinHeight = 0.098438;
	ebFilename->bBoundToParent = true;
	ebFilename->bScaleToParent = true;
	UmoComboBox* coResolution = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	coResolution->ComponentJustification = EeTextAlign::TXTA_Left;
	coResolution->Caption = "Resolution";
	//coResolution->OnCreateComponent=coResolution.InternalOnCreateComponent;
	coResolution->Hint = "The resolution of the final movie.";
	coResolution->WinTop = 0.079339;
	coResolution->WinLeft = 0.03125;
	coResolution->WinHeight = 0.06;
	coResolution->TabOrder = 0;
	UmoSlider* soQuality = NewObject<UmoSlider>(UmoSlider::StaticClass());
	soQuality->MaxValue = 1;
	soQuality->SliderCaptionStyleName = "TextLabel";
	soQuality->Caption = "Quality";
	//soQuality->OnCreateComponent=soQuality.InternalOnCreateComponent;
	soQuality->Hint = "The quality level of the compression used";
	soQuality->WinTop = 0.107618;
	soQuality->WinLeft = 0.345313;
	soQuality->WinWidth = 0.598438;
	soQuality->WinHeight = 0.0375;
	soQuality->TabOrder = 0;
	soQuality->bBoundToParent = true;
	soQuality->bScaleToParent = true;
	UGUILabel* lbSavePos = NewObject<UGUILabel>(UGUILabel::StaticClass());
	lbSavePos->Caption = "AVI's saved to ..\\UserMovies";
	lbSavePos->TextAlign = ETextAlign::TXTA_Center;
	lbSavePos->StyleName = "ServerBrowserGrid";
	lbSavePos->WinTop = 0.715625;
	lbSavePos->WinLeft = 0.117857;
	lbSavePos->WinWidth = 0.764286;
	lbSavePos->WinHeight = 0.061864;
	lbSavePos->bBoundToParent = true;
	lbSavePos->bScaleToParent = true;
	lb_SavePos = lbSavePos;
	eb_Filename = ebFilename;
	co_Resolution = coResolution;
	so_Quality = soQuality;
	WindowName = "Output to AVI...";
	DefaultLeft = 0.15;
	DefaultTop = 0.25;
	DefaultWidth = 0.7;
	DefaultHeight = 0.5;
	WinTop = 0.25;
	WinLeft = 0.15;
	WinWidth = 0.7;
	WinHeight = 0.5;

}

void UAADemo2AVI::InitComponent(UGUIController* aController, UGUIComponent* Owner)
{
	/*
	Super::InitComponent(aController, Owner);
	sb_Main.bFillClient = true;
	sb_Main.TopPadding = 0.05;
	sb_Main.SetPosition(0.03375, 0.1, 0.650859, 0.344726);
	sb_Main.ManageComponent(eb_Filename);
	sb_Main.ManageComponent(co_Resolution);
	sb_Main.ManageComponent(so_Quality);
	co_Resolution.addItem("160x120");
	co_Resolution.addItem("320x240");
	co_Resolution.addItem("640x480");
	co_Resolution.addItem("800x600");
	co_Resolution.addItem("1280x720");
	co_Resolution.SetIndex(1);
	so_Quality.SetValue(1);
	b_OK.__OnClick__Delegate = OkClick;
	*/
}

void UAADemo2AVI::HandleParameters(FString Param1, FString Param2)
{
	/*
	FString S = "";
	int32 p = 0;
	DemoName = Param1;
	p = InStr(Caps(Param1), ".DEMO4");
	if (p >= 0)
	{
		S = Left(Param1, p);
	}
	else
	{
		S = Param1;
	}
	S = S $ ".AVI";
	eb_Filename.SetText(S);
	*/
}

bool UAADemo2AVI::OkClick(UGUIComponent* Sender)
{
	/*
	FString S = "";
	int32 p = 0;
	int32 X = 0;
	int32 Y = 0;
	S = Caps(co_Resolution.GetText());
	p = InStr(S, "X");
	X = 320;
	Y = 240;
	if (p >= 0)
	{
		X = int(Left(S, p));
		Y = int(Right(S, ((Len(S) - p) - 1)));
	}
	PlayerOwner().ConsoleCommand("demodump DEMO=" $ DemoName @ "FILENAME=" $ eb_Filename.GetText() @ "QUALITY=" $ string(so_Quality.GetValue()) @ "FPS=30 Width=" $ string(X) @ "Height=" $ string(Y));
	*/
	return true;
}
