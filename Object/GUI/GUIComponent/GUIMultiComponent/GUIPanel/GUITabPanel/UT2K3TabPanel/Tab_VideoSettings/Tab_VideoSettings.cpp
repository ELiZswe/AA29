// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_VideoSettings/Tab_VideoSettings.h"
#include "AA29/Object/GUI/GUIComponent/GUISlider/GUISlider.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UTab_VideoSettings::UTab_VideoSettings()
{
	UGUISlider* GammaSlider = NewObject<UGUISlider>(UGUISlider::StaticClass());
	GammaSlider->MinValue = 0.5;
	GammaSlider->MaxValue = 2.5;
	GammaSlider->IniOption = "ini:Engine.Engine.ViewportManager Gamma";
	GammaSlider->IniDefault = "0.8";
	GammaSlider->Hint = "Use the slider to adjust the Gamma to suit your monitor.";
	GammaSlider->WinTop = 0.402345;
	GammaSlider->WinLeft = 0.0625;
	GammaSlider->WinWidth = 0.25;
	//GammaSlider->OnClick=GammaSlider.InternalOnClick;
	//GammaSlider->OnMousePressed=GammaSlider.InternalOnMousePressed;
	//GammaSlider->OnMouseRelease=GammaSlider.InternalOnMouseRelease;
	//GammaSlider->OnKeyEvent=GammaSlider.InternalOnKeyEvent;
	//GammaSlider->OnCapturedMouseMove=GammaSlider.InternalCapturedMouseMove;
	UGUISlider* BrightnessSlider = NewObject<UGUISlider>(UGUISlider::StaticClass());
	BrightnessSlider->MaxValue = 1;
	BrightnessSlider->IniOption = "ini:Engine.Engine.ViewportManager Brightness";
	BrightnessSlider->IniDefault = "0.8";
	BrightnessSlider->Hint = "Use the slider to adjust the Brightness to suit your monitor.";
	BrightnessSlider->WinTop = 0.623699;
	BrightnessSlider->WinLeft = 0.0625;
	BrightnessSlider->WinWidth = 0.25;
	//BrightnessSlider->OnClick=BrightnessSlider.InternalOnClick;
	//BrightnessSlider->OnMousePressed=BrightnessSlider.InternalOnMousePressed;
	//BrightnessSlider->OnMouseRelease=BrightnessSlider.InternalOnMouseRelease;
	//BrightnessSlider->OnKeyEvent=BrightnessSlider.InternalOnKeyEvent;
	//BrightnessSlider->OnCapturedMouseMove=BrightnessSlider.InternalCapturedMouseMove;
	UGUISlider* ContrastSlider = NewObject<UGUISlider>(UGUISlider::StaticClass());
	ContrastSlider->MaxValue = 1;
	ContrastSlider->IniOption = "ini:Engine.Engine.ViewportManager Contrast";
	ContrastSlider->IniDefault = "0.8";
	ContrastSlider->Hint = "Use the slider to adjust the Contrast to suit your monitor.";
	ContrastSlider->WinTop = 0.851565;
	ContrastSlider->WinLeft = 0.0625;
	ContrastSlider->WinWidth = 0.25;
	//ContrastSlider->OnClick=ContrastSlider.InternalOnClick;
	//ContrastSlider->OnMousePressed=ContrastSlider.InternalOnMousePressed;
	//ContrastSlider->OnMouseRelease=ContrastSlider.InternalOnMouseRelease;
	//ContrastSlider->OnKeyEvent=ContrastSlider.InternalOnKeyEvent;
	//ContrastSlider->OnCapturedMouseMove=ContrastSlider.InternalCapturedMouseMove;
	UGUIButton* VideoRight = NewObject<UGUIButton>(UGUIButton::StaticClass());
	VideoRight->StyleName = "ArrowRight";
	VideoRight->WinTop = 0.573959;
	VideoRight->WinLeft = 0.864063;
	VideoRight->WinWidth = 0.043555;
	VideoRight->WinHeight = 0.084414;
	VideoRight->bVisible = false;
	VideoRight->bNeverFocus = true;
	VideoRight->bRepeatClick = true;
	//VideoRight->OnClick=Tab_VideoSettings.InternalOnClick;
	//VideoRight->OnKeyEvent=VideoRight.InternalOnKeyEvent;
	UGUIButton* VideoLeft = NewObject<UGUIButton>(UGUIButton::StaticClass());
	VideoLeft->StyleName = "ArrowLeft";
	VideoLeft->WinTop = 0.573959;
	VideoLeft->WinLeft = 0.397656;
	VideoLeft->WinWidth = 0.043555;
	VideoLeft->WinHeight = 0.084414;
	VideoLeft->bVisible = false;
	VideoLeft->bNeverFocus = true;
	VideoLeft->bRepeatClick = true;
	//VideoLeft->OnClick=Tab_VideoSettings.InternalOnClick;
	//VideoLeft->OnKeyEvent=VideoLeft.InternalOnKeyEvent;
	UGUIButton* VideoApply = NewObject<UGUIButton>(UGUIButton::StaticClass());
	VideoApply->Caption = "Apply Changes";
	VideoApply->Hint = "Apply all changes to your video settings.";
	VideoApply->WinTop = 0.152345;
	VideoApply->WinLeft = 0.667226;
	VideoApply->WinWidth = 0.25;
	VideoApply->WinHeight = 0.05;
	VideoApply->bVisible = false;
	//VideoApply->OnClick=Tab_VideoSettings.ApplyChanges;
	//VideoApply->OnKeyEvent=VideoApply.InternalOnKeyEvent;
	UmoCheckBox* VideoFullScreen = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	VideoFullScreen->ComponentJustification = EeTextAlign::TXTA_Left;
	VideoFullScreen->CaptionWidth = 0.375;
	VideoFullScreen->Caption = "Full Screen";
	//VideoFullScreen->OnCreateComponent=VideoFullScreen.InternalOnCreateComponent;
	VideoFullScreen->IniOption = "@Internal";
	VideoFullScreen->IniDefault = "True";
	VideoFullScreen->Hint = "Check this box to run the game full screen.";
	VideoFullScreen->WinTop = 0.047396;
	VideoFullScreen->WinLeft = 0.667226;
	VideoFullScreen->WinWidth = 0.35;
	VideoFullScreen->WinHeight = 0.04;
	//VideoFullScreen->OnLoadINI=Tab_VideoSettings.InternalOnLoadINI;
	//VideoFullScreen->OnSaveINI=Tab_VideoSettings.InternalOnSaveINI;
	UmoComboBox* VideoColorDepth = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	VideoColorDepth->CaptionWidth = 0.375;
	VideoColorDepth->Caption = "Color Depth";
	//VideoColorDepth->OnCreateComponent=VideoColorDepth.InternalOnCreateComponent;
	VideoColorDepth->IniOption = "@Internal";
	VideoColorDepth->IniDefault = "false";
	VideoColorDepth->Hint = "Select the maximum number of colors to display at one time.";
	VideoColorDepth->WinTop = 0.152345;
	VideoColorDepth->WinLeft = 0.121484;
	VideoColorDepth->WinWidth = 0.39;
	VideoColorDepth->WinHeight = 0.05;
	//VideoColorDepth->OnLoadINI=Tab_VideoSettings.InternalOnLoadINI;
	//VideoColorDepth->OnSaveINI=Tab_VideoSettings.InternalOnSaveINI;
	UmoComboBox* VideoResolution = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	VideoResolution->bReadOnly = true;
	VideoResolution->CaptionWidth = 0.375;
	VideoResolution->Caption = "Resolution";
	//VideoResolution->OnCreateComponent=VideoResolution.InternalOnCreateComponent;
	VideoResolution->IniOption = "@INTERNAL";
	VideoResolution->IniDefault = "640x480";
	VideoResolution->Hint = "Select the video resolution at which you wish to play.";
	VideoResolution->WinTop = 0.047396;
	VideoResolution->WinLeft = 0.124258;
	VideoResolution->WinWidth = 0.39;
	VideoResolution->WinHeight = 0.05;
	//VideoResolution->OnLoadINI=Tab_VideoSettings.InternalOnLoadINI;
	//VideoResolution->OnSaveINI=Tab_VideoSettings.InternalOnSaveINI;
	UGUIImage* GammaBK = NewObject<UGUIImage>(UGUIImage::StaticClass());
	GammaBK->ImageColor = FColor(255, 255, 255, 160);
	GammaBK->ImageStyle = EImgStyle::ISTY_Stretched;
	GammaBK->WinTop = 0.280365;
	GammaBK->WinLeft = 0.021641;
	GammaBK->WinWidth = 0.9575;
	GammaBK->WinHeight = 0.697273;
	UGUILabel* GammaLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	GammaLabel->Caption = "Gamma";
	GammaLabel->TextAlign = ETextAlign::TXTA_Center;
	GammaLabel->TextColor = FColor(255, 255, 255, 255);
	GammaLabel->StyleName = "TextLabel";
	GammaLabel->WinTop = 0.341146;
	GammaLabel->WinLeft = 0.060547;
	GammaLabel->WinWidth = 0.25;
	GammaLabel->WinHeight = 32;
	UGUILabel* BrightnessLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	BrightnessLabel->Caption = "Brightness";
	BrightnessLabel->TextAlign = ETextAlign::TXTA_Center;
	BrightnessLabel->TextColor = FColor(255, 255, 255, 255);
	BrightnessLabel->StyleName = "TextLabel";
	BrightnessLabel->WinTop = 0.55599;
	BrightnessLabel->WinLeft = 0.061524;
	BrightnessLabel->WinWidth = 0.25;
	BrightnessLabel->WinHeight = 32;
	UGUILabel* ContrastLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	ContrastLabel->Caption = "Contrast";
	ContrastLabel->TextAlign = ETextAlign::TXTA_Center;
	ContrastLabel->TextColor = FColor(255, 255, 255, 255);
	ContrastLabel->StyleName = "TextLabel";
	ContrastLabel->WinTop = 0.790365;
	ContrastLabel->WinLeft = 0.05957;
	ContrastLabel->WinWidth = 0.25;
	ContrastLabel->WinHeight = 32;
	UGUIImage* GammaBar = NewObject<UGUIImage>(UGUIImage::StaticClass());
	GammaBar->WinTop = 0.377604;
	GammaBar->WinLeft = 0.454102;
	GammaBar->WinWidth = 0.4;
	GammaBar->WinHeight = 0.5;
	UGUILabel* BrightDesc1 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	BrightDesc1->Caption = "Adjust the Gamma Setting so that the";
	BrightDesc1->TextAlign = ETextAlign::TXTA_Center;
	BrightDesc1->TextColor = FColor(0, 200, 230, 255);
	BrightDesc1->WinTop = 0.8;
	BrightDesc1->WinLeft = 0.151367;
	BrightDesc1->WinHeight = 32;
	BrightDesc1->bVisible = false;
	UGUILabel* BrightDesc2 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	BrightDesc2->Caption = "Square is completely black.";
	BrightDesc2->TextAlign = ETextAlign::TXTA_Center;
	BrightDesc2->TextColor = FColor(0, 200, 230, 255);
	BrightDesc2->WinTop = 0.87;
	BrightDesc2->WinLeft = 0.136719;
	BrightDesc2->WinHeight = 32;
	BrightDesc2->bVisible = false;

	DisplayModes = { FDisplayMode({320, 240}),FDisplayMode({512, 384}),FDisplayMode({640, 480}),FDisplayMode({720, 480}),FDisplayMode({800, 500}),FDisplayMode({800, 600}),FDisplayMode({896, 600}),FDisplayMode({1024, 640}),FDisplayMode({1024, 768}),FDisplayMode({1152, 864}),FDisplayMode({1280, 800}),FDisplayMode({1280, 854}),FDisplayMode({1280, 960}),FDisplayMode({1280, 1024}),FDisplayMode({1440, 900}),FDisplayMode({1600, 1200}),FDisplayMode({1680, 1050}),FDisplayMode({1920, 1200}),FDisplayMode({2560, 1600})};
	BitDepthText = { "16-bit Color","32-bit Color" };
	Controls = { VideoResolution,VideoColorDepth,VideoFullScreen,VideoApply,GammaBK,GammaLabel,GammaSlider,BrightnessLabel,BrightnessSlider,ContrastLabel,ContrastSlider,GammaBar,BrightDesc1,BrightDesc2,VideoLeft,VideoRight };
	WinTop = 0.15;
	WinHeight = 0.74;
}

void UTab_VideoSettings::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	Super::InitComponent(MyController, MyOwner);
	for (i = 0; i < Controls.Length; i++)
	{
		Controls[i].__OnChange__Delegate = InternalOnChange;
	}
	moComboBox(Controls[1]).addItem(BitDepthText[0]);
	moComboBox(Controls[1]).addItem(BitDepthText[1]);
	moComboBox(Controls[1]).ReadOnly(true);
	CheckSupportedResolutions();
	Controls[6].FriendlyLabel = GUILabel(Controls[5]);
	Controls[8].FriendlyLabel = GUILabel(Controls[7]);
	Controls[10].FriendlyLabel = GUILabel(Controls[9]);
	*/
}

void UTab_VideoSettings::CheckSupportedResolutions()
{
	/*
	int32 HighestRes = 0;
	int32 Index = 0;
	int32 BitDepth = 0;
	FString CurrentSelection = "";
	CurrentSelection = moComboBox(Controls[0]).MyComboBox.Edit.GetText();
	if (moComboBox(Controls[0]).ItemCount() > 0)
	{
		moComboBox(Controls[0]).RemoveItem(0, moComboBox(Controls[0]).ItemCount());
	}
	if (moComboBox(Controls[1]).GetText() == BitDepthText[0])
	{
		BitDepth = 16;
	}
	else
	{
		BitDepth = 32;
	}
	if (!moCheckBox(Controls[2]).IsChecked())
	{
		HighestRes = 0;
		for (Index = 0; Index < 19; Index++)
		{
			if (PlayerOwner().ConsoleCommand("SupportedResolution" $ " WIDTH=" $ string(DisplayModes[Index].Width) $ " HEIGHT=" $ string(DisplayModes[Index].Height) $ " BITDEPTH=" $ string(BitDepth)) == "1")
			{
				HighestRes = Index;
			}
		}
		for (Index = 0; Index <= HighestRes; Index++)
		{
			moComboBox(Controls[0]).addItem(string(DisplayModes[Index].Width) $ "x" $ string(DisplayModes[Index].Height));
		}
	}
	else
	{
		for (Index = 0; Index < 19; Index++)
		{
			if (PlayerOwner().ConsoleCommand("SupportedResolution" $ " WIDTH=" $ string(DisplayModes[Index].Width) $ " HEIGHT=" $ string(DisplayModes[Index].Height) $ " BITDEPTH=" $ string(BitDepth)) == "1")
			{
				moComboBox(Controls[0]).addItem(string(DisplayModes[Index].Width) $ "x" $ string(DisplayModes[Index].Height));
			}
		}
	}
	moComboBox(Controls[0]).SetText(CurrentSelection);
	*/
}

void UTab_VideoSettings::Refresh()
{
	/*
	InternalOnLoadINI(Controls[0], "");
	InternalOnLoadINI(Controls[1], "");
	InternalOnLoadINI(Controls[2], "");
	*/
}

void UTab_VideoSettings::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	FString Temp = "";
	if (Sender == Controls[0])
	{
		if (Controller.GameResolution != "")
		{
			moComboBox(Controls[0]).SetText(Controller.GameResolution);
		}
		else
		{
			moComboBox(Controls[0]).SetText(Controller.GetCurrentRes());
		}
	}
	if (Sender == Controls[1])
	{
		if (PlayerOwner().ConsoleCommand("get ini:Engine.Engine.RenderDevice Use16bit") ~= "true")
		{
			moComboBox(Sender).SetText(BitDepthText[0]);
		}
		else
		{
			moComboBox(Sender).SetText(BitDepthText[1]);
		}
		CheckSupportedResolutions();
	}
	else
	{
		if (Sender == Controls[2])
		{
			Temp = Sender.PlayerOwner().ConsoleCommand("ISFULLSCREEN");
			moCheckBox(Sender).Checked(bool(Temp));
			CheckSupportedResolutions();
		}
	}
	*/
}

FString UTab_VideoSettings::InternalOnSaveINI(UGUIComponent* Sender)
{
	return "FAKE";    //FAKE    /ELiZ
}

void UTab_VideoSettings::InternalOnChange(UGUIComponent* Sender)
{
	/*
	if (!Controller.bCurMenuInitialized)
	{
		return;
	}
	if (((Sender == Controls[0]) || (Sender == Controls[1])) || (Sender == Controls[2]))
	{
		Controls[3].bVisible = true;
		if (Sender != Controls[0])
		{
			CheckSupportedResolutions();
		}
	}
	else
	{
		if (Sender == Controls[6])
		{
			PlayerOwner().ConsoleCommand("GAMMA" @ string(GUISlider(Controls[6]).Value));
		}
		else
		{
			if (Sender == Controls[8])
			{
				PlayerOwner().ConsoleCommand("BRIGHTNESS" @ string(GUISlider(Controls[8]).Value));
			}
			else
			{
				if (Sender == Controls[10])
				{
					PlayerOwner().ConsoleCommand("CONTRAST" @ string(GUISlider(Controls[10]).Value));
				}
			}
		}
	}
	*/
}

bool UTab_VideoSettings::ApplyChanges(UGUIComponent* Sender)
{
	/*
	FString DesiredRes = "";
	DesiredRes = moComboBox(Controls[0]).MyComboBox.Edit.GetText();
	if (moComboBox(Controls[1]).GetText() == BitDepthText[0])
	{
		DesiredRes = DesiredRes $ "x16";
	}
	else
	{
		DesiredRes = DesiredRes $ "x32";
	}
	if (moCheckBox(Controls[2]).IsChecked())
	{
		DesiredRes = DesiredRes $ "f";
	}
	else
	{
		DesiredRes = DesiredRes $ "w";
	}
	Controls[3].bVisible = false;
	if (Controller.OpenMenu("xinterface.UT2VideoChangeOK"))
	{
		UT2VideoChangeOK(Controller.TopPage()).Execute(DesiredRes);
	}
	*/
	return true;
}

bool UTab_VideoSettings::InternalOnClick(UGUIComponent* Sender)
{
	/*
	ShowSShot = (!ShowSShot);
	Controls[12].bVisible = (!ShowSShot);
	Controls[13].bVisible = (!ShowSShot);
	*/
	return true;
}