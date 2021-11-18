// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/Settings_Tabs/AATab_DetailSettings/AATab_DetailSettings.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moSlider/moSlider.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UAATab_DetailSettings::UAATab_DetailSettings()
{
	UmoComboBox* RenderDeviceCombo = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	RenderDeviceCombo->ComponentJustification = EeTextAlign::TXTA_Left;
	RenderDeviceCombo->CaptionWidth=0.55;
	RenderDeviceCombo->Caption="Render Device";
	//RenderDeviceCombo->OnCreateComponent=RenderDeviceCombo.InternalOnCreateComponent;
	RenderDeviceCombo->IniOption="@Internal";
	RenderDeviceCombo->Hint="Alternate rendering devices may offer better performance on your machine.";
	RenderDeviceCombo->WinTop=0.08;
	RenderDeviceCombo->WinLeft=0.02;
	RenderDeviceCombo->WinWidth=0.45;
	RenderDeviceCombo->WinHeight=0.035;
	RenderDeviceCombo->TabOrder=0;
	RenderDeviceCombo->bBoundToParent=true;
	RenderDeviceCombo->bScaleToParent=true;
	//RenderDeviceCombo->OnChange=AATab_DetailSettings.InternalOnChange;
	//RenderDeviceCombo->OnLoadINI=AATab_DetailSettings.InternalOnLoadINI;
	UmoComboBox* VideoResolution = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	VideoResolution->bReadOnly=true;
	VideoResolution->CaptionWidth=0.55;
	VideoResolution->Caption="Resolution";
	//VideoResolution->OnCreateComponent=VideoResolution.InternalOnCreateComponent;
	VideoResolution->IniOption="@INTERNAL";
	VideoResolution->IniDefault="640x480";
	VideoResolution->Hint="Select the video resolution at which you wish to play.";
	VideoResolution->WinTop=0.13;
	VideoResolution->WinLeft=0.02;
	VideoResolution->WinWidth=0.45;
	VideoResolution->WinHeight=0.035;
	VideoResolution->TabOrder=1;
	//VideoResolution->OnChange=AATab_DetailSettings.InternalOnChange;
	//VideoResolution->OnLoadINI=AATab_DetailSettings.InternalOnLoadINI;
	UmoSlider* BrightnessSlider = NewObject<UmoSlider>(UmoSlider::StaticClass());
	BrightnessSlider->MaxValue=1;
	BrightnessSlider->SliderCaptionStyleName="";
	BrightnessSlider->CaptionWidth=0.55;
	BrightnessSlider->Caption="Brightness";
	//BrightnessSlider->OnCreateComponent=BrightnessSlider.InternalOnCreateComponent;
	BrightnessSlider->IniOption="@Internal";
	BrightnessSlider->IniDefault="0.8";
	BrightnessSlider->Hint="Use the slider to adjust the Brightness to suit your monitor.";
	BrightnessSlider->WinTop=0.18;
	BrightnessSlider->WinLeft=0.02;
	BrightnessSlider->WinWidth=0.45;
	BrightnessSlider->TabOrder=4;
	//BrightnessSlider->OnChange=AATab_DetailSettings.InternalOnChange;
	//BrightnessSlider->OnLoadINI=AATab_DetailSettings.InternalOnLoadINI;
	UmoSlider* GammaSlider = NewObject<UmoSlider>(UmoSlider::StaticClass());
	GammaSlider->MaxValue=1.5;
	GammaSlider->MinValue=0.5;
	GammaSlider->SliderCaptionStyleName="";
	GammaSlider->CaptionWidth=0.55;
	GammaSlider->Caption="Gamma";
	//GammaSlider->OnCreateComponent=GammaSlider.InternalOnCreateComponent;
	GammaSlider->IniOption="@Internal";
	GammaSlider->IniDefault="0.8";
	GammaSlider->Hint="Use the slider to adjust the Gamma to suit your monitor.";
	GammaSlider->WinTop=0.23;
	GammaSlider->WinLeft=0.02;
	GammaSlider->WinWidth=0.45;
	GammaSlider->TabOrder=5;
	//GammaSlider->OnChange=AATab_DetailSettings.InternalOnChange;
	//GammaSlider->OnLoadINI=AATab_DetailSettings.InternalOnLoadINI;
	UmoSlider* ContrastSlider = NewObject<UmoSlider>(UmoSlider::StaticClass());
	ContrastSlider->MaxValue=1;
	ContrastSlider->SliderCaptionStyleName="";
	ContrastSlider->CaptionWidth=0.55;
	ContrastSlider->Caption="Contrast";
	//ContrastSlider->OnCreateComponent=ContrastSlider.InternalOnCreateComponent;
	ContrastSlider->IniOption="@Internal";
	ContrastSlider->IniDefault="0.8";
	ContrastSlider->Hint="Use the slider to adjust the Contrast to suit your monitor.";
	ContrastSlider->WinTop=0.28;
	ContrastSlider->WinLeft=0.02;
	ContrastSlider->WinWidth=0.45;
	ContrastSlider->TabOrder=6;
	//ContrastSlider->OnChange=AATab_DetailSettings.InternalOnChange;
	//ContrastSlider->OnLoadINI=AATab_DetailSettings.InternalOnLoadINI;
	UmoCheckBox* VideoFullScreen = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	VideoFullScreen->ComponentJustification = EeTextAlign::TXTA_Left;
	VideoFullScreen->CaptionWidth=0.94;
	VideoFullScreen->Caption="Full Screen";
	//VideoFullScreen->OnCreateComponent=VideoFullScreen.InternalOnCreateComponent;
	VideoFullScreen->IniOption="@Internal";
	VideoFullScreen->IniDefault="True";
	VideoFullScreen->Hint="Check this box to run the game full screen.";
	VideoFullScreen->WinTop=0.33;
	VideoFullScreen->WinLeft=0.02;
	VideoFullScreen->WinWidth=0.45;
	VideoFullScreen->WinHeight=0.035;
	VideoFullScreen->TabOrder=3;
	VideoFullScreen->bStandardized=false;
	//VideoFullScreen->OnChange=AATab_DetailSettings.InternalOnChange;
	//VideoFullScreen->OnLoadINI=AATab_DetailSettings.InternalOnLoadINI;
	UmoCheckBox* DetailVSync = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	DetailVSync->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailVSync->CaptionWidth=0.94;
	DetailVSync->Caption="VSync";
	//DetailVSync->OnCreateComponent=DetailVSync.InternalOnCreateComponent;
	DetailVSync->IniOption="@Internal";
	DetailVSync->IniDefault="True";
	DetailVSync->Hint="Enables Vertical Sync to reduce visual artifacts such as tearing and shearing.";
	DetailVSync->WinTop=0.38;
	DetailVSync->WinLeft=0.02;
	DetailVSync->WinWidth=0.45;
	DetailVSync->WinHeight=0.035;
	DetailVSync->TabOrder=23;
	DetailVSync->bStandardized=false;
	//DetailVSync->OnChange=AATab_DetailSettings.InternalOnChange;
	//DetailVSync->OnLoadINI=AATab_DetailSettings.InternalOnLoadINI;
	UmoComboBox* DetailTextureDetail = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DetailTextureDetail->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailTextureDetail->CaptionWidth=0.65;
	DetailTextureDetail->Caption="Texture Detail";
	//DetailTextureDetail->OnCreateComponent=DetailTextureDetail.InternalOnCreateComponent;
	DetailTextureDetail->IniOption="@Internal";
	DetailTextureDetail->IniDefault="High";
	DetailTextureDetail->Hint="Changes how much world texture detail will be rendered.";
	DetailTextureDetail->WinTop=0.08;
	DetailTextureDetail->WinLeft=0.52;
	DetailTextureDetail->WinWidth=0.45;
	DetailTextureDetail->WinHeight=0.035;
	DetailTextureDetail->TabOrder=7;
	//DetailTextureDetail->OnChange=AATab_DetailSettings.InternalOnChange;
	//DetailTextureDetail->OnLoadINI=AATab_DetailSettings.InternalOnLoadINI;
	UmoComboBox* DetailCharacterDetail = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DetailCharacterDetail->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailCharacterDetail->CaptionWidth=0.65;
	DetailCharacterDetail->Caption="Character Detail";
	//DetailCharacterDetail->OnCreateComponent=DetailCharacterDetail.InternalOnCreateComponent;
	DetailCharacterDetail->IniOption="@Internal";
	DetailCharacterDetail->IniDefault="High";
	DetailCharacterDetail->Hint="Changes how much character detail will be rendered.";
	DetailCharacterDetail->WinTop=0.13;
	DetailCharacterDetail->WinLeft=0.52;
	DetailCharacterDetail->WinWidth=0.45;
	DetailCharacterDetail->WinHeight=0.035;
	DetailCharacterDetail->TabOrder=8;
	//DetailCharacterDetail->OnChange=AATab_DetailSettings.InternalOnChange;
	//DetailCharacterDetail->OnLoadINI=AATab_DetailSettings.InternalOnLoadINI;
	UmoComboBox* DetailWorldDetail = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DetailWorldDetail->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailWorldDetail->CaptionWidth=0.65;
	DetailWorldDetail->Caption="World Detail";
	//DetailWorldDetail->OnCreateComponent=DetailWorldDetail.InternalOnCreateComponent;
	DetailWorldDetail->IniOption="@Internal";
	DetailWorldDetail->IniDefault="High";
	DetailWorldDetail->Hint="Changes the level of detail used for optional geometry and effects.";
	DetailWorldDetail->WinTop=0.18;
	DetailWorldDetail->WinLeft=0.52;
	DetailWorldDetail->WinWidth=0.45;
	DetailWorldDetail->WinHeight=0.035;
	DetailWorldDetail->TabOrder=9;
	//DetailWorldDetail->OnChange=AATab_DetailSettings.InternalOnChange;
	//DetailWorldDetail->OnLoadINI=AATab_DetailSettings.InternalOnLoadINI;
	UmoComboBox* DetailPhysics = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DetailPhysics->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailPhysics->CaptionWidth=0.65;
	DetailPhysics->Caption="Physics Detail";
	//DetailPhysics->OnCreateComponent=DetailPhysics.InternalOnCreateComponent;
	DetailPhysics->IniOption="@Internal";
	DetailPhysics->IniDefault="High";
	DetailPhysics->Hint="Changes the physics simulation level of detail.";
	DetailPhysics->WinTop=0.23;
	DetailPhysics->WinLeft=0.52;
	DetailPhysics->WinWidth=0.45;
	DetailPhysics->WinHeight=0.035;
	DetailPhysics->TabOrder=10;
	//DetailPhysics->OnChange=AATab_DetailSettings.InternalOnChange;
	//DetailPhysics->OnLoadINI=AATab_DetailSettings.InternalOnLoadINI;
	UmoComboBox* MeshLOD = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	MeshLOD->ComponentJustification = EeTextAlign::TXTA_Left;
	MeshLOD->CaptionWidth=0.65;
	MeshLOD->Caption="Dynamic Mesh LOD";
	//MeshLOD->OnCreateComponent=MeshLOD.InternalOnCreateComponent;
	MeshLOD->IniOption="@Internal";
	MeshLOD->Hint="Adjusts how aggressively character and vehicle details are reduced at a distance.  Higher settings increase the distance at which details are reduced, possibly improving visual detail at a cost in performance";
	MeshLOD->WinTop=0.28;
	MeshLOD->WinLeft=0.52;
	MeshLOD->WinWidth=0.45;
	MeshLOD->WinHeight=0.035;
	MeshLOD->TabOrder=11;
	//MeshLOD->OnChange=AATab_DetailSettings.InternalOnChange;
	//MeshLOD->OnLoadINI=AATab_DetailSettings.InternalOnLoadINI;
	UmoComboBox* DetailDecalStay = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DetailDecalStay->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailDecalStay->CaptionWidth=0.65;
	DetailDecalStay->Caption="Decal Stay";
	//DetailDecalStay->OnCreateComponent=DetailDecalStay.InternalOnCreateComponent;
	DetailDecalStay->IniOption="@Internal";
	DetailDecalStay->IniDefault="Normal";
	DetailDecalStay->Hint="Changes how long weapon scarring effects stay around.";
	DetailDecalStay->WinTop=0.33;
	DetailDecalStay->WinLeft=0.52;
	DetailDecalStay->WinWidth=0.45;
	DetailDecalStay->WinHeight=0.035;
	DetailDecalStay->TabOrder=12;
	//DetailDecalStay->OnChange=AATab_DetailSettings.InternalOnChange;
	//DetailDecalStay->OnLoadINI=AATab_DetailSettings.InternalOnLoadINI;
	UmoComboBox* DetailCharacterShadows = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DetailCharacterShadows->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailCharacterShadows->CaptionWidth=0.65;
	DetailCharacterShadows->Caption="Character Shadows";
	//DetailCharacterShadows->OnCreateComponent=DetailCharacterShadows.InternalOnCreateComponent;
	DetailCharacterShadows->IniOption="@Internal";
	DetailCharacterShadows->Hint="Adjust the detail of character shadows.  'Blob' or 'None' recommended for low-performance PC's";
	DetailCharacterShadows->WinTop=0.38;
	DetailCharacterShadows->WinLeft=0.52;
	DetailCharacterShadows->WinWidth=0.45;
	DetailCharacterShadows->WinHeight=0.035;
	DetailCharacterShadows->TabOrder=13;
	//DetailCharacterShadows->OnChange=AATab_DetailSettings.InternalOnChange;
	//DetailCharacterShadows->OnLoadINI=AATab_DetailSettings.InternalOnLoadINI;
	UmoCheckBox* DetailDecals = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	DetailDecals->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailDecals->CaptionWidth=0.94;
	DetailDecals->Caption="Decals";
	//DetailDecals->OnCreateComponent=DetailDecals.InternalOnCreateComponent;
	DetailDecals->IniOption="@Internal";
	DetailDecals->IniDefault="True";
	DetailDecals->Hint="Enables weapon scarring effects.";
	DetailDecals->WinTop=0.43;
	DetailDecals->WinLeft=0.52;
	DetailDecals->WinWidth=0.45;
	DetailDecals->WinHeight=0.035;
	DetailDecals->TabOrder=14;
	DetailDecals->bStandardized=false;
	//DetailDecals->OnChange=AATab_DetailSettings.InternalOnChange;
	//DetailDecals->OnLoadINI=AATab_DetailSettings.InternalOnLoadINI;
	UmoCheckBox* DetailDynamicLighting = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	DetailDynamicLighting->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailDynamicLighting->CaptionWidth=0.94;
	DetailDynamicLighting->Caption="Dynamic Lighting";
	//DetailDynamicLighting->OnCreateComponent=DetailDynamicLighting.InternalOnCreateComponent;
	DetailDynamicLighting->IniOption="@Internal";
	DetailDynamicLighting->IniDefault="True";
	DetailDynamicLighting->Hint="Enables dynamic lights.";
	DetailDynamicLighting->WinTop=0.48;
	DetailDynamicLighting->WinLeft=0.52;
	DetailDynamicLighting->WinWidth=0.45;
	DetailDynamicLighting->WinHeight=0.035;
	DetailDynamicLighting->TabOrder=15;
	DetailDynamicLighting->bStandardized=false;
	//DetailDynamicLighting->OnChange=AATab_DetailSettings.InternalOnChange;
	//DetailDynamicLighting->OnLoadINI=AATab_DetailSettings.InternalOnLoadINI;
	UmoCheckBox* DetailDetailTextures = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	DetailDetailTextures->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailDetailTextures->CaptionWidth=0.94;
	DetailDetailTextures->Caption="Detail Textures";
	//DetailDetailTextures->OnCreateComponent=DetailDetailTextures.InternalOnCreateComponent;
	DetailDetailTextures->IniOption="@Internal";
	DetailDetailTextures->IniDefault="True";
	DetailDetailTextures->Hint="Enables detail textures.";
	DetailDetailTextures->WinTop=0.53;
	DetailDetailTextures->WinLeft=0.52;
	DetailDetailTextures->WinWidth=0.45;
	DetailDetailTextures->WinHeight=0.035;
	DetailDetailTextures->TabOrder=16;
	DetailDetailTextures->bStandardized=false;
	//DetailDetailTextures->OnChange=AATab_DetailSettings.InternalOnChange;
	//DetailDetailTextures->OnLoadINI=AATab_DetailSettings.InternalOnLoadINI;
	UmoCheckBox* DetailTrilinear = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	DetailTrilinear->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailTrilinear->CaptionWidth=0.94;
	DetailTrilinear->Caption="Trilinear Filtering";
	//DetailTrilinear->OnCreateComponent=DetailTrilinear.InternalOnCreateComponent;
	DetailTrilinear->IniOption="@Internal";
	DetailTrilinear->IniDefault="False";
	DetailTrilinear->Hint="Enables trilinear filtering, recommended for high-performance PCs.";
	DetailTrilinear->WinTop=0.63;
	DetailTrilinear->WinLeft=0.52;
	DetailTrilinear->WinWidth=0.45;
	DetailTrilinear->WinHeight=0.035;
	DetailTrilinear->TabOrder=18;
	DetailTrilinear->bStandardized=false;
	//DetailTrilinear->OnChange=AATab_DetailSettings.InternalOnChange;
	//DetailTrilinear->OnLoadINI=AATab_DetailSettings.InternalOnLoadINI;
	UmoCheckBox* DetailProjectors = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	DetailProjectors->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailProjectors->CaptionWidth=0.94;
	DetailProjectors->Caption="Projectors";
	//DetailProjectors->OnCreateComponent=DetailProjectors.InternalOnCreateComponent;
	DetailProjectors->IniOption="@Internal";
	DetailProjectors->IniDefault="True";
	DetailProjectors->Hint="Enables projectors.";
	DetailProjectors->WinTop=0.68;
	DetailProjectors->WinLeft=0.52;
	DetailProjectors->WinWidth=0.45;
	DetailProjectors->WinHeight=0.035;
	DetailProjectors->TabOrder=19;
	DetailProjectors->bStandardized=false;
	//DetailProjectors->OnChange=AATab_DetailSettings.InternalOnChange;
	//DetailProjectors->OnLoadINI=AATab_DetailSettings.InternalOnLoadINI;
	UGUIImage* GammaBar = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//GammaBar->Image=Texture'T_AAO_UI.Menu.GammaTest';
	GammaBar->ImageStyle = EImgStyle::ISTY_Scaled;
	GammaBar->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	GammaBar->WinTop=0.44;
	GammaBar->WinLeft=0.02;
	GammaBar->WinWidth=0.46;
	GammaBar->WinHeight=0.46;
	//GammaBar->OnChange=AATab_DetailSettings.InternalOnChange;
	
	//DisplayModes = { (800, 500),(800,  600),(1024, 640),(1024, 768), (1152, 768),(1152, 864),(1280, 800),(1280, 854),(1280, 960),(1280, 1024),(1600, 1024),(1600, 1200),(1680, 1050),(1920, 1200) };
	//DisplayModes = { FDisplayMode(800, 500),FDisplayMode(800,  600),FDisplayMode(1024, 640),FDisplayMode(1024, 768), FDisplayMode(1152, 768),FDisplayMode(1152, 864),FDisplayMode(1280, 800),FDisplayMode(1280, 854),FDisplayMode(1280, 960),FDisplayMode(1280, 1024),FDisplayMode(1600, 1024),FDisplayMode(1600, 1200),FDisplayMode(1680, 1050),FDisplayMode(1920, 1200) };

	BitDepthText = { "32-bit","32-bit" };
	DetailLevels = { "Lowest","Very Low","Lower","Low","Normal","High","Higher","Very High","Highest" };
	ShadowOptions = { "None", "Blob", "Full" };
	RenderModeText = { "Direct 3D","Software" };
	RenderMode = { "D3DDrv.D3DRenderDevice", "PixoDrv.PixoRenderDevice" };
	DisplayPromptMenu = "AGP_Interface.AAVideoChangeOK";
	i_GammaBar = GammaBar;
	co_Texture = DetailTextureDetail;
	co_Char = DetailCharacterDetail;
	co_World = DetailWorldDetail;
	co_Physics = DetailPhysics;
	co_Decal = DetailDecalStay;
	co_MeshLOD = MeshLOD;
	co_Resolution = VideoResolution;
	co_RenderDevice = RenderDeviceCombo;
	co_Shadows = DetailCharacterShadows;
	ch_Decals = DetailDecals;
	ch_DynLight = DetailDynamicLighting;
	ch_Textures = DetailDetailTextures;
	ch_Projectors = DetailProjectors;
	ch_Trilinear = DetailTrilinear;
	ch_FullScreen = VideoFullScreen;
	ch_VSync = DetailVSync;
	sl_Gamma = GammaSlider;
	sl_Brightness = BrightnessSlider;
	sl_Contrast = ContrastSlider;
	RelaunchQuestion = "The graphics mode has been successfully changed.  However, it will not take effect until the next time the game is started.  Would you like to restart America's Army right now?";
	InvalidSelectionText = "The selected custom resolution is reported to be incompatible with your machine.  In order to ensure maximum stability, it is recommended that you choose a compatible resolution from the 'Resolution' drop-down menu";
	PanelCaption = "Display";
	WinTop = 0.15;
	WinHeight = 0.74;
	//OnPreDraw = AATab_DetailSettings.InternalOnPreDraw;
}


//const RENDERMODECOUNT = 2;


void UAATab_DetailSettings::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	InitializeCombos();
	SetupPositions();
	*/
}

void UAATab_DetailSettings::Opened(UGUIComponent* Sender)
{
	/*
	Super::Opened(Sender);
	CheckSupportedResolutions();
	*/
}

void UAATab_DetailSettings::ShowPanel(bool bShow)
{
	/*
	Super::ShowPanel(bShow);
	if (bShow)
	{
		CheckSliders();
	}
	*/
}

void UAATab_DetailSettings::InitializeCombos()
{
	/*
	int32 i = 0;
	local TArray<GUIListElem> Options;
	for (i = 0; i < Components.Length; i++)
	{
		if (moComboBox(Components[i]) != None)
		{
			GetComboOptions(moComboBox(Components[i]), Options);
			moComboBox(Components[i]).MyComboBox.List.Elements = Options;
			moComboBox(Components[i]).MyComboBox.List.ItemCount = Options.Length;
			moComboBox(Components[i]).ReadOnly(true);
		}
	}
	co_Texture.MyComboBox.MaxVisibleItems = 9;
	co_Char.MyComboBox.MaxVisibleItems = 9;
	*/
}

void UAATab_DetailSettings::CheckSliders()
{
	/*
	if (bFullScreen || (!PlatformIsWindows()))
	{
		EnableComponent(sl_Gamma);
		EnableComponent(sl_Contrast);
		EnableComponent(sl_Brightness);
	}
	else
	{
		DisableComponent(sl_Gamma);
		DisableComponent(sl_Contrast);
		DisableComponent(sl_Brightness);
	}
	*/
}

void UAATab_DetailSettings::SetupPositions()
{
}

void UAATab_DetailSettings::CheckSupportedResolutions()
{
	/*
	int32 i = 0;
	int32 Index = 0;
	int32 BitDepth = 0;
	FString CurrentSelection = "";
	FString str = "";
	FString W = "";
	FString H = "";
	FString WH = "";
	bool bStandard = false;
	bool bSupported = false;
	bool bOldIgnoreChange = false;
	local PlayerController PC;
	PC = PlayerOwner();
	if (PC == None)
	{
		return;
	}
	CurrentSelection = co_Resolution.GetText();
	bOldIgnoreChange = bIgnoreChange;
	bIgnoreChange = true;
	BitDepth = 32;
	for (i = 0; i < 17; i++)
	{
		W = string(DisplayModes[i].Width);
		H = string(DisplayModes[i].Height);
		WH = W $ "x" $ H;
		str = "SUPPORTEDRESOLUTION WIDTH=" $ W @ "HEIGHT=" $ H @ "BITDEPTH=" $ string(BitDepth);
		if (CurrentSelection ~= WH)
		{
			bStandard = true;
		}
		Index = co_Resolution.FindIndex(WH);
		bSupported = bool(PC.ConsoleCommand(str));
		if ((!bSupported) && co_Resolution.MyComboBox.List.IsValidIndex(Index))
		{
			co_Resolution.RemoveItem(Index, 1);
		}
		else
		{
			if (bSupported && (!co_Resolution.MyComboBox.List.IsValidIndex(Index)))
			{
				AddNewResolution(WH);
			}
		}
	}
	if (!bStandard)
	{
		Divide(CurrentSelection, "x", W, H);
		str = "SUPPORTEDRESOLUTION WIDTH=" $ W @ "HEIGHT=" $ H @ "BITDEPTH=" $ string(BitDepth);
		bSupported = bool(PC.ConsoleCommand(str));
		if (!bSupported)
		{
			Index = co_Resolution.FindIndex(CurrentSelection);
			bInvalidRes = true;
		}
	}
	CheckSliders();
	co_Resolution.SetText(CurrentSelection);
	bIgnoreChange = bOldIgnoreChange;
	*/
}

bool UAATab_DetailSettings::InternalOnPreDraw(UCanvas* C)
{
	/*
	if ((Controller.ActivePage == PageOwner) && bInvalidRes)
	{
		bInvalidRes = false;
		Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "", InvalidSelectionText);
	}
	*/
	return false;
}

void UAATab_DetailSettings::ResolutionChanged(int32 NewX, int32 NewY)
{
	/*
	if (!bIgnoreResNotice)
	{
		if (Controller.ActivePage == PageOwner)
		{
			PageOwner.CheckResolution(false, Controller);
		}
		Refresh();
	}
	*/
}

void UAATab_DetailSettings::Refresh()
{
	/*
	InternalOnLoadINI(co_Resolution, "");
	InternalOnLoadINI(ch_FullScreen, "");
	CheckSupportedResolutions();
	*/
}

int32 UAATab_DetailSettings::AddNewResolution(FString NewDisplayMode)
{
	int32 i = 0;
	int32 ItemW = 0;
	int32 ItemH = 0;
	int32 InWidth = 0;
	int32 InHeight = 0;
	bool bTemp = false;
	FString str = "";
	FString StrW = "";
	FString StrH = "";
	/*
	bTemp = bIgnoreChange;
	bIgnoreChange = true;
	i = co_Resolution.FindIndex(NewDisplayMode);
	if (i >= 0)
	{
		bIgnoreChange = bTemp;
		return i;
	}
	Divide(NewDisplayMode, "x", StrW, StrH);
	InWidth = int(StrW);
	InHeight = int(StrH);
	i = 0;
	if (i < co_Resolution.ItemCount())
	{
		str = co_Resolution.GetItem(i);
		Divide(str, "x", StrW, StrH);
		ItemW = int(StrW);
		ItemH = int(StrH);
		if (ItemW == InWidth)
		{
			if (ItemH > InHeight)
			{
			}
		}
		else
		{
	else
	{
		if (ItemW > InWidth)
		{
		}
	}
	else
	{
		i++;
	}
		}
	}
	if (i == co_Resolution.ItemCount())
	{
		co_Resolution.addItem(NewDisplayMode);
	}
	else
	{
		co_Resolution.MyComboBox.List.Insert(i, NewDisplayMode);
	}
	bIgnoreChange = bTemp;
	*/
	return i;
}

void UAATab_DetailSettings::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	bool A = false;
	bool B = false;
	int32 i = 0;
	local PlayerController PC;
	FString TempStr = "";
	PC = PlayerOwner();
	if (PC == None)
	{
		return;
	}
	switch (Sender)
	{
	case co_Texture:
		S = GetGUIString(PC.ConsoleCommand("get ini:Engine.Engine.ViewportManager TextureDetailWorld"));
		iTexture = co_Texture.FindIndex(S);
		iTextureD = iTexture;
		co_Texture.SilentSetIndex(iTexture);
		break;
	case co_Char:
		S = GetGUIString(PC.ConsoleCommand("get ini:Engine.Engine.ViewportManager TextureDetailPlayerSkin"));
		iChar = co_Char.FindIndex(S);
		iCharD = iChar;
		co_Char.SilentSetIndex(iChar);
		break;
	case co_World:
		A = bool(PC.ConsoleCommand("get ini:Engine.Engine.RenderDevice HighDetailActors"));
		B = bool(PC.ConsoleCommand("get ini:Engine.Engine.RenderDevice SuperHighDetailActors"));
		if (B)
		{
			iWorld = 5;
		}
		else
		{
			if (A)
			{
				iWorld = 4;
			}
			else
			{
				iWorld = 3;
			}
		}
		iWorldD = iWorld;
		i = co_World.FindIndex(DetailLevels[iWorld]);
		if (i != -1)
		{
			co_World.SilentSetIndex(i);
		}
		GOTO JL0C84;
	case co_MeshLOD:
		switch (Class'LevelInfo'.Default.MeshLODDetailLevel)
		{
		case 0:
			iMeshLOD = 3;
			break;
		case 1:
			iMeshLOD = 4;
			break;
		case 2:
			iMeshLOD = 5;
			break;
		case 3:
			iMeshLOD = 8;
			break;
		default:
		}
		iMeshLODD = iMeshLOD;
		i = co_MeshLOD.FindIndex(DetailLevels[iMeshLOD]);
		if (i != -1)
		{
			co_MeshLOD.SilentSetIndex(i);
		}
		GOTO JL0C84;
	case co_Physics:
		if (Class'LevelInfo'.Default.PhysicsDetailLevel == 1)
		{
			iPhys = 4;
			i = co_Physics.FindIndex(DetailLevels[4]);
			if (i != -1)
			{
				co_Physics.SilentSetIndex(i);
			}
		}
		else
		{
			iPhys = 5;
			i = co_Physics.FindIndex(DetailLevels[5]);
			if (i != -1)
			{
				co_Physics.SilentSetIndex(i);
			}
		}
		iPhysD = iPhys;
		GOTO JL0C84;
	case co_Decal:
		iDecal = int(Class'LevelInfo'.Default.DecalStayScale);
		iDecalD = iDecal;
		co_Decal.SilentSetIndex(iDecal);
		GOTO JL0C84;
	case co_Resolution:
		if (Controller.GameResolution != "")
		{
			sRes = Controller.GameResolution;
		}
		else
		{
			sRes = Controller.GetCurrentRes();
		}
		sResD = sRes;
		iColDepth = 0;
		iColDepthD = iColDepth;
		i = AddNewResolution(sRes);
		if ((i >= 0) && (i < co_Resolution.ItemCount()))
		{
			co_Resolution.SilentSetIndex(i);
		}
		GOTO JL0C84;
	case co_RenderDevice:
		sRenDev = GetNativeClassName("Engine.Engine.RenderDevice");
		sRenDevD = sRenDev;
		co_RenderDevice.SetComponentValue(sRenDev, true);
		GOTO JL0C84;
	case co_Shadows:
		TempStr = GetNativeClassName("Engine.Engine.RenderDevice");
		switch (Class'LevelInfo'.Default.ShadowDetail)
		{
		case 0:
			iShadow = 0;
			break;
		case 1:
			iShadow = 1;
			break;
		case 2:
			iShadow = 2;
			break;
		default:
		}
		iShadowD = iShadow;
		co_Shadows.SilentSetIndex(iShadow);
		GOTO JL0C84;
	case ch_DynLight:
		bDynLight = (!bool(PC.ConsoleCommand("get ini:Engine.Engine.ViewportManager NoDynamicLights")));
		bDynLightD = bDynLight;
		ch_DynLight.SetComponentValue(string(bDynLight), true);
		GOTO JL0C84;
	case ch_FullScreen:
		bFullScreen = bool(PC.ConsoleCommand("ISFULLSCREEN"));
		bFullScreenD = bFullScreen;
		moCheckBox(Sender).SetComponentValue(string(bFullScreen), true);
		GOTO JL0C84;
	case ch_Trilinear:
		bTrilin = bool(PC.ConsoleCommand("get ini:Engine.Engine.RenderDevice UseTrilinear"));
		bTrilinD = bTrilin;
		ch_Trilinear.SetComponentValue(string(bTrilin), true);
		GOTO JL0C84;
	case ch_Projectors:
		bProj = bool(PC.ConsoleCommand("get ini:Engine.Engine.ViewportManager Projectors"));
		bProjD = bProj;
		ch_Projectors.SetComponentValue(string(bProj), true);
		GOTO JL0C84;
	case ch_DecoLayers:
		bFol = bool(PC.ConsoleCommand("get ini:Engine.Engine.ViewportManager DecoLayers"));
		bFolD = bFol;
		ch_DecoLayers.SetComponentValue(string(bFol), true);
		GOTO JL0C84;
	case ch_Textures:
		bTexture = bool(PC.ConsoleCommand("get ini:Engine.Engine.RenderDevice DetailTextures"));
		bTextureD = bTexture;
		ch_Textures.SetComponentValue(string(bTexture), true);
		GOTO JL0C84;
	case ch_Coronas:
		bCorona = bool(PC.ConsoleCommand("get ini:Engine.Engine.ViewportManager Coronas"));
		bCoronaD = bCorona;
		ch_Coronas.SetComponentValue(string(bCorona), true);
		GOTO JL0C84;
	case ch_Decals:
		bDecal = bool(PC.ConsoleCommand("get ini:Engine.Engine.ViewportManager Decals"));
		bDecalD = bDecal;
		ch_Decals.SetComponentValue(string(bDecal), true);
		UpdateDecalStay();
		GOTO JL0C84;
	case sl_Gamma:
		fGamma = float(PC.ConsoleCommand("get ini:Engine.Engine.ViewportManager Gamma"));
		sl_Gamma.SetComponentValue(string(fGamma), true);
		GOTO JL0C84;
	case sl_Brightness:
		fBright = float(PC.ConsoleCommand("get ini:Engine.Engine.ViewportManager Brightness"));
		sl_Brightness.SetComponentValue(string(fBright), true);
		GOTO JL0C84;
	case sl_Contrast:
		fContrast = float(PC.ConsoleCommand("get ini:Engine.Engine.ViewportManager Contrast"));
		sl_Contrast.SetComponentValue(string(fContrast), true);
		GOTO JL0C84;
	case ch_Weather:
		bWeather = bool(PC.ConsoleCommand("get ini:Engine.Engine.ViewportManager WeatherEffects"));
		bWeatherD = bWeather;
		ch_Weather.SetComponentValue(string(bWeather), true);
		GOTO JL0C84;
	case sl_DistanceLOD:
		fDistance = float(PC.ConsoleCommand("get ini:Engine.Engine.ViewportManager DrawDistanceLOD"));
		fDistanceD = fDistance;
		sl_DistanceLOD.SetComponentValue(string(fDistance), true);
		GOTO JL0C84;
	case ch_VSync:
		bVSync = bool(PC.ConsoleCommand("get ini:Engine.Engine.RenderDevice UseVSync"));
		bVSyncD = bVSync;
		ch_VSync.SetComponentValue(string(bVSync), true);
		GOTO JL0C84;
	default:
		Log(string(Name) @ "Unknown component calling LoadINI:" $ GUIMenuOption(Sender).Caption);
		GUIMenuOption(Sender).SetComponentValue(S, true);
	JL0C84:
	}
	*/
}

void UAATab_DetailSettings::ResetClicked()
{
	/*
	int32 i = 0;
	Super::ResetClicked();
	Class'LevelInfo'.ResetConfig("MeshLODDetailLevel");
	Class'LevelInfo'.ResetConfig("PhysicsDetailLevel");
	Class'LevelInfo'.ResetConfig("DecalStayScale");
	Class'LevelInfo'.ResetConfig("ShadowDetail");
	ResetViewport();
	ResetRenderDevice();
	for (i = 0; i < Components.Length; i++)
	{
		Components[i].LoadINI();
	}
	*/
}

void UAATab_DetailSettings::ResetViewport()
{
	/*
	local class<Client>  ViewportClass;
	ViewportClass = class<Client>(DynamicLoadObject(GetNativeClassName("Engine.Engine.ViewportManager"), Class'Class'));
	ViewportClass.ResetConfig("WindowedViewportX");
	ViewportClass.ResetConfig("WindowedViewportY");
	ViewportClass.ResetConfig("FullscreenViewportX");
	ViewportClass.ResetConfig("FullscreenViewportY");
	ViewportClass.ResetConfig("Brightness");
	ViewportClass.ResetConfig("Contrast");
	ViewportClass.ResetConfig("Gamma");
	ViewportClass.ResetConfig("StartupFullScreen");
	ViewportClass.ResetConfig("NoLighting");
	ViewportClass.ResetConfig("MinDesiredFrameRate");
	ViewportClass.ResetConfig("Decals");
	ViewportClass.ResetConfig("Coronas");
	ViewportClass.ResetConfig("DecoLayers");
	ViewportClass.ResetConfig("Projectors");
	ViewportClass.ResetConfig("NoDynamicLights");
	ViewportClass.ResetConfig("ReportDynamicUploads");
	ViewportClass.ResetConfig("TextureDetailInterface");
	ViewportClass.ResetConfig("TextureDetailTerrain");
	ViewportClass.ResetConfig("TextureDetailWeaponSkin");
	ViewportClass.ResetConfig("TextureDetailPlayerSkin");
	ViewportClass.ResetConfig("TextureDetailWorld");
	ViewportClass.ResetConfig("TextureDetailRendermap");
	ViewportClass.ResetConfig("TextureDetailLightmap");
	ViewportClass.ResetConfig("NoFractalAnim");
	ViewportClass.ResetConfig("WeatherEffects");
	ViewportClass.ResetConfig("DrawDistanceLOD");
	*/
}

void UAATab_DetailSettings::ResetRenderDevice()
{
	/*
	local class<RenderDevice>  RenderClass;
	if (!(sRenDev ~= sRenDevD))
	{
		Controller.SetRenderDevice(sRenDevD);
	}
	RenderClass = class<RenderDevice>(DynamicLoadObject(sRenDevD, Class'Class'));
	RenderClass.ResetConfig("DetailTextures");
	RenderClass.ResetConfig("HighDetailActors");
	RenderClass.ResetConfig("SuperHighDetailActors");
	RenderClass.ResetConfig("UsePrecaching");
	RenderClass.ResetConfig("UseTrilinear");
	RenderClass.ResetConfig("UseTripleBuffering");
	RenderClass.ResetConfig("UseHardwareTL");
	RenderClass.ResetConfig("UseHardwareVS");
	RenderClass.ResetConfig("UseCubemaps");
	RenderClass.ResetConfig("DesiredRefreshRate");
	RenderClass.ResetConfig("UseCompressedLightmaps");
	RenderClass.ResetConfig("UseStencil");
	RenderClass.ResetConfig("Use16bit");
	RenderClass.ResetConfig("Use16bitTextures");
	RenderClass.ResetConfig("MaxPixelShaderVersion");
	RenderClass.ResetConfig("UseVSync");
	RenderClass.ResetConfig("LevelOfAnisotropy");
	RenderClass.ResetConfig("DetailTexMipBias");
	RenderClass.ResetConfig("DefaultTexMipBias");
	RenderClass.ResetConfig("UseNPatches");
	RenderClass.ResetConfig("TesselationFactor");
	RenderClass.ResetConfig("CheckForOverflow");
	RenderClass.ResetConfig("AvoidHitches");
	RenderClass.ResetConfig("OverrideDesktopRefreshRate");
	*/
}

void UAATab_DetailSettings::SaveSettings()
{
	/*
	FString t = "";
	FString V = "";
	FString str = "";
	local PlayerController PC;
	bool bUnreal = false;
	bool bLevel = false;
	Super::SaveSettings();
	PC = PlayerOwner();
	if (sRenDev != sRenDevD)
	{
		if (Controller.SetRenderDevice(sRenDev))
		{
			sRenDevD = sRenDev;
		}
	}
	if (iTexture != iTextureD)
	{
		t = "set ini:Engine.Engine.ViewportManager TextureDetail";
		str = DetailLevels[iTexture];
		V = GetConfigString(str);
		PC.ConsoleCommand(t $ "Terrain" @ V);
		PC.ConsoleCommand(t $ "World" @ V);
		PC.ConsoleCommand(t $ "Rendermap" @ V);
		PC.ConsoleCommand(t $ "Lightmap" @ V);
		PC.ConsoleCommand("flush");
		iTextureD = iTexture;
	}
	if (iChar != iCharD)
	{
		t = "set ini:Engine.Engine.ViewportManager TextureDetail";
		str = DetailLevels[iChar];
		V = GetConfigString(str);
		PC.ConsoleCommand(t $ "WeaponSkin" @ V);
		PC.ConsoleCommand(t $ "PlayerSkin" @ V);
		PC.ConsoleCommand("flush");
		iCharD = iChar;
	}
	if (iWorld != iWorldD)
	{
		str = DetailLevels[iWorld];
		V = GetConfigString(str);
		switch (iWorld)
		{
		case 3:
			PC.ConsoleCommand("set ini:Engine.Engine.RenderDevice HighDetailActors False");
			PC.ConsoleCommand("set ini:Engine.Engine.RenderDevice SuperHighDetailActors False");
			PC.Level.DetailChange(0);
			break;
		case 4:
			PC.ConsoleCommand("set ini:Engine.Engine.RenderDevice HighDetailActors True");
			PC.ConsoleCommand("set ini:Engine.Engine.RenderDevice SuperHighDetailActors False");
			PC.Level.DetailChange(1);
			break;
		case 5:
			PC.ConsoleCommand("set ini:Engine.Engine.RenderDevice HighDetailActors True");
			PC.ConsoleCommand("set ini:Engine.Engine.RenderDevice SuperHighDetailActors True");
			PC.Level.DetailChange(2);
			break;
		default:
		}
		iWorldD = iWorld;
	}
	if (iMeshLOD != iMeshLODD)
	{
		switch (iMeshLOD)
		{
		case 3:
			Class'LevelInfo'.Default.MeshLODDetailLevel = 0;
			PC.Level.MeshLODDetailLevel = 0;
			break;
		case 4:
			Class'LevelInfo'.Default.MeshLODDetailLevel = 1;
			PC.Level.MeshLODDetailLevel = 1;
			break;
		case 5:
			Class'LevelInfo'.Default.MeshLODDetailLevel = 2;
			PC.Level.MeshLODDetailLevel = 2;
			break;
		case 8:
			Class'LevelInfo'.Default.MeshLODDetailLevel = 3;
			PC.Level.MeshLODDetailLevel = 3;
			break;
		default:
		}
		iMeshLODD = iMeshLOD;
		bLevel = true;
	}
	if (iPhys != iPhysD)
	{
		switch (iPhys)
		{
		case 3:
			Class'LevelInfo'.Default.PhysicsDetailLevel = 0;
			PC.Level.PhysicsDetailLevel = 0;
			break;
		case 4:
			Class'LevelInfo'.Default.PhysicsDetailLevel = 1;
			PC.Level.PhysicsDetailLevel = 1;
			break;
		case 5:
			Class'LevelInfo'.Default.PhysicsDetailLevel = 2;
			PC.Level.PhysicsDetailLevel = 2;
			break;
		default:
		}
		iPhysD = iPhys;
		bLevel = true;
	}
	if (iShadow != iShadowD)
	{
		switch (iShadow)
		{
		case 0:
			if (PC.Level != None)
			{
				PC.Level.ShadowDetail = 0;
			}
			Class'LevelInfo'.Default.ShadowDetail = 0;
			break;
		case 1:
			if (PC.Level != None)
			{
				PC.Level.ShadowDetail = 1;
			}
			Class'LevelInfo'.Default.ShadowDetail = 1;
			break;
		case 2:
			if (PC.Level != None)
			{
				PC.Level.ShadowDetail = 2;
			}
			Class'LevelInfo'.Default.ShadowDetail = 2;
			break;
		default:
		}
		iShadowD = iShadow;
		bUnreal = true;
		bLevel = true;
	}
	if (Class'Vehicle'.Default.bVehicleShadows != (iShadow > 0))
	{
		Class'Vehicle'.Default.bVehicleShadows = (iShadow > 0);
		Class'Vehicle'.StaticSaveConfig();
	}
	if (bDynLight != bDynLightD)
	{
		PC.ConsoleCommand("set ini:Engine.Engine.ViewportManager NoDynamicLights" @ string((!bDynLight)));
		bDynLightD = bDynLight;
	}
	if (iDecal != iDecalD)
	{
		if (PC.Level != None)
		{
			PC.Level.DecalStayScale = float(iDecal);
		}
		Class'LevelInfo'.Default.DecalStayScale = float(iDecal);
		iDecalD = iDecal;
		bLevel = true;
	}
	if (bTrilin != bTrilinD)
	{
		PC.ConsoleCommand("set ini:Engine.Engine.RenderDevice UseTrilinear" @ string(bTrilin));
		bTrilinD = bTrilin;
	}
	if (bFol != bFolD)
	{
		PC.ConsoleCommand("set ini:Engine.Engine.ViewportManager DecoLayers" @ string(bFol));
		bFolD = bFol;
	}
	if (bProj != bProjD)
	{
		PC.ConsoleCommand("set ini:Engine.Engine.ViewportManager Projectors" @ string(bProj));
		bProjD = bProj;
	}
	if (bTexture != bTextureD)
	{
		PC.ConsoleCommand("set ini:Engine.Engine.RenderDevice DetailTextures" @ string(bTexture));
		bTextureD = bTexture;
	}
	if (bCorona != bCoronaD)
	{
		PC.ConsoleCommand("set ini:Engine.Engine.ViewportManager Coronas" @ string(bCorona));
		bCoronaD = bCorona;
	}
	if (bDecal != bDecalD)
	{
		PC.ConsoleCommand("set ini:Engine.Engine.ViewportManager Decals" @ string(bDecal));
		bDecalD = bDecal;
	}
	if (bWeather != bWeatherD)
	{
		PC.ConsoleCommand("set ini:Engine.Engine.ViewportManager WeatherEffects" @ string(bWeather));
		bWeatherD = bWeather;
	}
	if (fDistance != fDistanceD)
	{
		PC.ConsoleCommand("set ini:Engine.Engine.ViewportManager DrawDistanceLOD" @ string(fDistance));
		PC.Level.UpdateDistanceFogLOD(fDistance);
		fDistanceD = fDistance;
	}
	if (bVSync != bVSyncD)
	{
		PC.ConsoleCommand("set ini:Engine.Engine.RenderDevice UseVSync" @ string(bVSync));
		bVSyncD = bVSync;
	}
	if (bUnreal)
	{
		if ((PC.Pawn != None) && (AGP_Pawn(PC.Pawn) != None))
		{
			AGP_Pawn(PC.Pawn).SaveConfig();
		}
		else
		{
			Class'AGP.AGP_Pawn'.StaticSaveConfig();
		}
	}
	if (bLevel)
	{
		if (PC.Level != None)
		{
			PC.Level.SaveConfig();
		}
		else
		{
			Class'LevelInfo'.StaticSaveConfig();
		}
	}
	*/
}

void UAATab_DetailSettings::InternalOnChange(UGUIComponent* Sender)
{
	/*
	FString str = "";
	bool bGoingUp = false;
	int32 i = 0;
	Super::InternalOnChange(Sender);
	if (bIgnoreChange)
	{
		return;
	}
	switch (Sender)
	{
	case co_Resolution:
		sRes = co_Resolution.GetText();
		if (bFullScreen)
		{
			str = "f";
			break;
		}
		str = "w";
	}
	if (Controller.OpenMenu(DisplayPromptMenu))
	{
		bIgnoreResNotice = true;
		AAVideoChangeOK(Controller.ActivePage).__OnClose__Delegate = VideoChangeClose;
		AAVideoChangeOK(Controller.ActivePage).Execute(sRes $ "x" $ Left(BitDepthText[iColDepth], 2) $ str);
	}
	GOTO JL0774;
	case ch_FullScreen:
		bFullScreen = ch_FullScreen.IsChecked();
		if (bFullScreen)
		{
			str = "f";
		}
		else
		{
			str = "w";
		}
		if (Controller.OpenMenu(DisplayPromptMenu))
		{
			bIgnoreResNotice = true;
			AAVideoChangeOK(Controller.ActivePage).__OnClose__Delegate = VideoChangeClose;
			AAVideoChangeOK(Controller.ActivePage).Execute(sRes $ "x" $ Left(BitDepthText[iColDepth], 2) $ str);
		}
		GOTO JL0774;
	case co_RenderDevice:
		sRenDev = co_RenderDevice.GetExtra();
		if ((sRenDev != sRenDevD) && Controller.OpenMenu(Controller.QuestionMenuClass))
		{
			GUIQuestionPage(Controller.ActivePage).SetupQuestion(RelaunchQuestion, 50, 2);
			GUIQuestionPage(Controller.ActivePage).__NewOnButtonClick__Delegate = RenderDeviceClick;
		}
		GOTO JL0774;
	case co_Texture:
		i = co_Texture.GetIndex();
		bGoingUp = ((i > iTexture) && (i != iTextureD));
		iTexture = i;
		GOTO JL0774;
	case co_Char:
		i = co_Char.GetIndex();
		bGoingUp = ((i > iChar) && (i != iCharD));
		iChar = i;
		GOTO JL0774;
	case co_World:
		str = co_World.GetText();
		i = GetDetailIndex(str);
		bGoingUp = ((i > iWorld) && (i != iWorldD));
		iWorld = i;
		GOTO JL0774;
	case co_MeshLOD:
		str = co_MeshLOD.GetText();
		i = GetDetailIndex(str);
		bGoingUp = ((i > iMeshLOD) && (i != iMeshLODD));
		iMeshLOD = i;
		GOTO JL0774;
	case co_Physics:
		str = co_Physics.GetText();
		i = GetDetailIndex(str);
		bGoingUp = ((i > iPhys) && (i != iPhysD));
		iPhys = i;
		GOTO JL0774;
	case co_Decal:
		iDecal = co_Decal.GetIndex();
		GOTO JL0774;
	case co_Shadows:
		i = co_Shadows.GetIndex();
		bGoingUp = ((i > iShadow) && (i != iShadowD));
		iShadow = i;
		GOTO JL0774;
	case ch_DynLight:
		bDynLight = ch_DynLight.IsChecked();
		bGoingUp = (bDynLight && (bDynLight != bDynLightD));
		GOTO JL0774;
	case ch_Trilinear:
		bTrilin = ch_Trilinear.IsChecked();
		bGoingUp = (bTrilin && (bTrilin != bTrilinD));
		GOTO JL0774;
	case ch_Projectors:
		bProj = ch_Projectors.IsChecked();
		bGoingUp = (bProj && (bProjD != bProj));
		GOTO JL0774;
	case ch_DecoLayers:
		bFol = ch_DecoLayers.IsChecked();
		bGoingUp = (bFol && (bFol != bFolD));
		GOTO JL0774;
	case ch_Textures:
		bTexture = ch_Textures.IsChecked();
		bGoingUp = (bTexture && (bTexture != bTextureD));
		GOTO JL0774;
	case ch_Coronas:
		bCorona = ch_Coronas.IsChecked();
		bGoingUp = (bCorona && (bCorona != bCoronaD));
		GOTO JL0774;
	case ch_Decals:
		bDecal = ch_Decals.IsChecked();
		bGoingUp = (bDecal && (bDecal != bDecalD));
		UpdateDecalStay();
		GOTO JL0774;
	case sl_Gamma:
		fGamma = sl_Gamma.GetValue();
		PlayerOwner().ConsoleCommand("GAMMA" @ string(fGamma));
		GOTO JL0774;
	case sl_Brightness:
		fBright = sl_Brightness.GetValue();
		PlayerOwner().ConsoleCommand("BRIGHTNESS" @ string(fBright));
		GOTO JL0774;
	case sl_Contrast:
		fContrast = sl_Contrast.GetValue();
		PlayerOwner().ConsoleCommand("CONTRAST" @ string(fContrast));
		GOTO JL0774;
	case sl_DistanceLOD:
		fDistance = sl_DistanceLOD.GetValue();
		GOTO JL0774;
	case ch_Weather:
		bWeather = ch_Weather.IsChecked();
		bGoingUp = (bWeather && (bWeather != bWeatherD));
		GOTO JL0774;
	case ch_VSync:
		bVSync = ch_VSync.IsChecked();
		GOTO JL0774;
	default:
	JL0774:
		if (bGoingUp)
		{
			ShowPerformanceWarning();
		}
		SaveSettings();
	}
	*/
}

bool UAATab_DetailSettings::RenderDeviceClick(uint8 Btn)
{
	/*
	switch (Btn)
	{
	case 16:
		SaveSettings();
		Console(Controller.Master.Console).DelayedConsoleCommand("relaunch");
		break;
	case 2:
		sRenDev = sRenDevD;
		co_RenderDevice.Find(sRenDev);
		co_RenderDevice.SetComponentValue(sRenDev, true);
		break;
	default:
	}
	*/
	return true;
}

void UAATab_DetailSettings::VideoChangeClose(bool bCancelled)
{
	/*
	bool bTemp = false;
	FString NewX = "";
	FString NewY = "";
	Divide(sRes, "x", NewX, NewY);
	if (bCancelled)
	{
		bTemp = bIgnoreChange;
		bIgnoreChange = true;
		co_Resolution.LoadINI();
		ch_FullScreen.LoadINI();
		bIgnoreChange = bTemp;
	}
	else
	{
		if ((int(NewX) < 640) || (int(NewY) < 480))
		{
			Controller.GameResolution = NewX $ "x" $ NewY;
		}
		else
		{
			Controller.GameResolution = "";
		}
		iColDepthD = iColDepth;
		sResD = sRes;
		if (bFullScreen != bFullScreenD)
		{
			PlayerOwner().ConsoleCommand("set ini:Engine.Engine.ViewportManager StartupFullScreen" @ string(bFullScreen));
			bFullScreenD = bFullScreen;
		}
	}
	CheckSliders();
	bIgnoreResNotice = false;
	*/
}

int32 UAATab_DetailSettings::GetDetailIndex(FString DetailString)
{
	/*
	int32 i = 0;
	for (i = 0; i < 9; i++)
	{
		if (DetailString == DetailLevels[i])
		{
			return i;
		}
	}
	*/
	return 0;
}

FString UAATab_DetailSettings::GetGUIString(FString ConfigString)
{
	/*
	switch (ConfigString)
	{
	case "UltraLow":
		return DetailLevels[0];
	case "VeryLow":
		return DetailLevels[1];
	case "Low":
		return DetailLevels[2];
	case "Lower":
		return DetailLevels[3];
	case "Normal":
		return DetailLevels[4];
	case "Higher":
		return DetailLevels[5];
	case "High":
		return DetailLevels[6];
	case "VeryHigh":
		return DetailLevels[7];
	case "UltraHigh":
		return DetailLevels[8];
	default:
		return "";
	}
	*/
	return "FAKE";     //FAKE   /ELiZ
}

FString UAATab_DetailSettings::GetConfigString(FString DetailString)
{
	/*
	switch (DetailString)
	{
	case DetailLevels[0]:
		return "UltraLow";
	case DetailLevels[1]:
		return "VeryLow";
	case DetailLevels[2]:
		return "Low";
	case DetailLevels[3]:
		return "Lower";
	case DetailLevels[4]:
		return "Normal";
	case DetailLevels[5]:
		return "Higher";
	case DetailLevels[6]:
		return "High";
	case DetailLevels[7]:
		return "VeryHigh";
	case DetailLevels[8]:
		return "UltraHigh";
	default:
		return "";
	}
	*/
	return "FAKE";     //FAKE   /ELiZ
}

void UAATab_DetailSettings::GetComboOptions(UmoComboBox* Combo, TArray<FGUIListElem>& Ar)
{
	/*
	int32 i = 0;
	FString TempStr = "";
	Ar.remove(0, Ar.Length);
	if (Combo == None)
	{
		return;
	}
	switch (Combo)
	{
	case co_Texture:
	case co_Char:
		i = 0;
		if (i < 9)
		{
			Ar.Length = (Ar.Length + 1);
			Ar[i].Item = DetailLevels[i];
			i++;
			break;
		}
		GOTO JL0468;
	case co_Physics:
		Ar.Length = 2;
		Ar[0].Item = DetailLevels[4];
		Ar[1].Item = DetailLevels[5];
		GOTO JL0468;
	case co_World:
	case co_Decal:
		Ar.Length = 3;
		Ar[0].Item = DetailLevels[3];
		Ar[1].Item = DetailLevels[4];
		Ar[2].Item = DetailLevels[5];
		GOTO JL0468;
	case co_Resolution:
		Ar.Length = 17;
		for (i = 0; i < Ar.Length; i++)
		{
			Ar[i].Item = string(DisplayModes[i].Width) $ "x" $ string(DisplayModes[i].Height);
		}
		GOTO JL0468;
	case co_RenderDevice:
		if (PlatformIsWindows() && PlatformIs64Bit())
		{
			Ar.Length = 2;
			Ar[0].Item = RenderModeText[0] @ "9";
			Ar[0].ExtraStrData = "D3D9Drv.D3D9RenderDevice";
			Ar[1].Item = "OpenGL";
			Ar[1].ExtraStrData = "OpenGLDrv.OpenGLRenderDevice";
		}
		else
		{
			if (PlatformIsMacOS())
			{
				Ar.Length = 1;
				Ar[0].Item = "OpenGL";
				Ar[0].ExtraStrData = "OpenGLDrv.OpenGLRenderDevice";
			}
			else
			{
				if (PlatformIsUnix())
				{
					Ar.Length = 1;
					Ar[0].Item = "OpenGL";
					Ar[0].ExtraStrData = "OpenGLDrv.OpenGLRenderDevice";
					if (!PlatformIs64Bit())
					{
						Ar.Length = 2;
						Ar[1].Item = RenderModeText[1];
						Ar[1].ExtraStrData = "PixoDrv.PixoRenderDevice";
					}
				}
				else
				{
					Ar.Length = 1;
					for (i = 0; i < 1; i++)
					{
						Ar[i].Item = RenderModeText[i];
						Ar[i].ExtraStrData = RenderMode[i];
					}
				}
			}
		}
		GOTO JL0468;
	case co_Shadows:
		TempStr = GetNativeClassName("Engine.Engine.RenderDevice");
		Ar.Length = 3;
		for (i = 0; i < 3; i++)
		{
			Ar[i].Item = ShadowOptions[i];
		}
		GOTO JL0468;
	case co_MeshLOD:
		Ar.Length = 4;
		Ar[0].Item = DetailLevels[3];
		Ar[1].Item = DetailLevels[4];
		Ar[2].Item = DetailLevels[5];
		Ar[3].Item = DetailLevels[8];
		GOTO JL0468;
	default:
	JL0468:
	}
	*/
}

void UAATab_DetailSettings::UpdateDecalStay()
{
	/*
	if (ch_Decals.IsChecked())
	{
		EnableComponent(co_Decal);
	}
	else
	{
		DisableComponent(co_Decal);
	}
	*/
}