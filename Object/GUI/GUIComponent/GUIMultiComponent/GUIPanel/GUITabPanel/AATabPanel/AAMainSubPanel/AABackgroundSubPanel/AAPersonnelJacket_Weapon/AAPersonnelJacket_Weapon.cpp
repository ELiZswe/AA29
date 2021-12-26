// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AAPersonnelJacket_Weapon/AAPersonnelJacket_Weapon.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAPersonnelJacket_Weapon::UAAPersonnelJacket_Weapon()
{
	UGUIImage* WeaponLayer = NewObject<UGUIImage>(UGUIImage::StaticClass());
	WeaponLayer->ImageStyle = EImgStyle::ISTY_Scaled;
	WeaponLayer->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	WeaponLayer->WinTop = 0.0715;
	WeaponLayer->WinLeft = 0.035;
	WeaponLayer->WinWidth = 0.935;
	WeaponLayer->WinHeight = 0.335;
	WeaponLayer->RenderWeight = 0.15;
	UmoComboBox* SetCombo = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	SetCombo->bReadOnly = true;
	SetCombo->CaptionWidth = 0.26;
	SetCombo->Caption = "Set";
	//SetCombo->OnCreateComponent=SetCombo.InternalOnCreateComponent;
	SetCombo->IniOption = "@Internal";
	SetCombo->Hint = "Select the Weapon Mod Set.";
	SetCombo->WinTop = 0.425;
	SetCombo->WinLeft = 0.52;
	SetCombo->WinWidth = 0.45;
	SetCombo->WinHeight = 0.053476;
	SetCombo->TabOrder = 3;
	SetCombo->bStandardized = false;
	//SetCombo->OnChange=AAPersonnelJacket_Weapon.InternalOnChange;
	//SetCombo->OnLoadINI=AAPersonnelJacket_Weapon.InternalOnLoadINI;
	UmoComboBox* TopRailCombo = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	TopRailCombo->bReadOnly = true;
	TopRailCombo->CaptionWidth = 0.26;
	TopRailCombo->Caption = "Top";
	//TopRailCombo->OnCreateComponent=TopRailCombo.InternalOnCreateComponent;
	TopRailCombo->IniOption = "@Internal";
	TopRailCombo->Hint = "Set the mod for the Top Rail.";
	TopRailCombo->WinTop = 0.55;
	TopRailCombo->WinLeft = 0.52;
	TopRailCombo->WinWidth = 0.45;
	TopRailCombo->WinHeight = 0.053476;
	TopRailCombo->TabOrder = 4;
	TopRailCombo->bStandardized = false;
	//TopRailCombo->OnChange=AAPersonnelJacket_Weapon.InternalOnChange;
	//TopRailCombo->OnLoadINI=AAPersonnelJacket_Weapon.InternalOnLoadINI;
	UmoComboBox* FrontRailCombo = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	FrontRailCombo->bReadOnly = true;
	FrontRailCombo->CaptionWidth = 0.26;
	FrontRailCombo->Caption = "Front";
	//FrontRailCombo->OnCreateComponent=FrontRailCombo.InternalOnCreateComponent;
	FrontRailCombo->IniOption = "@Internal";
	FrontRailCombo->Hint = "Set the mod for the Front Rail.";
	FrontRailCombo->WinTop = 0.61;
	FrontRailCombo->WinLeft = 0.52;
	FrontRailCombo->WinWidth = 0.45;
	FrontRailCombo->WinHeight = 0.053476;
	FrontRailCombo->TabOrder = 5;
	FrontRailCombo->bStandardized = false;
	//FrontRailCombo->OnChange=AAPersonnelJacket_Weapon.InternalOnChange;
	//FrontRailCombo->OnLoadINI=AAPersonnelJacket_Weapon.InternalOnLoadINI;
	UmoComboBox* BottomRailCombo = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	BottomRailCombo->bReadOnly = true;
	BottomRailCombo->CaptionWidth = 0.26;
	BottomRailCombo->Caption = "Bottom";
	//BottomRailCombo->OnCreateComponent=BottomRailCombo.InternalOnCreateComponent;
	BottomRailCombo->IniOption = "@Internal";
	BottomRailCombo->Hint = "Set the mod for the Bottom Rail.";
	BottomRailCombo->WinTop = 0.67;
	BottomRailCombo->WinLeft = 0.52;
	BottomRailCombo->WinWidth = 0.45;
	BottomRailCombo->WinHeight = 0.053476;
	BottomRailCombo->TabOrder = 8;
	BottomRailCombo->bStandardized = false;
	//BottomRailCombo->OnChange=AAPersonnelJacket_Weapon.InternalOnChange;
	//BottomRailCombo->OnLoadINI=AAPersonnelJacket_Weapon.InternalOnLoadINI;
	UmoComboBox* BarrelCombo = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	BarrelCombo->bReadOnly = true;
	BarrelCombo->CaptionWidth = 0.26;
	BarrelCombo->Caption = "Barrel";
	//BarrelCombo->OnCreateComponent=BarrelCombo.InternalOnCreateComponent;
	BarrelCombo->IniOption = "@Internal";
	BarrelCombo->Hint = "Set the mod for the barrel.";
	BarrelCombo->WinTop = 0.7735;
	BarrelCombo->WinLeft = 0.52;
	BarrelCombo->WinWidth = 0.45;
	BarrelCombo->WinHeight = 0.053476;
	BarrelCombo->TabOrder = 9;
	BarrelCombo->bStandardized = false;
	//BarrelCombo->OnChange=AAPersonnelJacket_Weapon.InternalOnChange;
	//BarrelCombo->OnLoadINI=AAPersonnelJacket_Weapon.InternalOnLoadINI;
	UGUIScrollTextBox* WeaponDescription = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	WeaponDescription->bNoTeletype = true;
	WeaponDescription->bVisibleWhenEmpty = true;
	//WeaponDescription->OnCreateComponent=WeaponDescription.InternalOnCreateComponent;
	WeaponDescription->FontScale = EFontScale::FNS_Small;
	WeaponDescription->StyleName = "SmallText";
	WeaponDescription->WinTop = 0.435;
	WeaponDescription->WinLeft = 0.025;
	WeaponDescription->WinWidth = 0.45;
	WeaponDescription->WinHeight = 0.46;
	WeaponDescription->RenderWeight = 0.51;
	WeaponDescription->TabOrder = 10;
	WeaponDescription->bAcceptsInput = false;
	WeaponDescription->bNeverFocus = true;
	UGUIButton* WeaponModInfoButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	WeaponModInfoButton->Caption = "Mod Info";
	WeaponModInfoButton->FontScale = EFontScale::FNS_Small;
	WeaponModInfoButton->Hint = "Press to find out more about the current weapon mod.";
	WeaponModInfoButton->WinTop = 0.8585;
	WeaponModInfoButton->WinLeft = 0.67;
	WeaponModInfoButton->WinWidth = 0.16;
	WeaponModInfoButton->WinHeight = 0.036;
	WeaponModInfoButton->TabOrder = 11;
	//WeaponModInfoButton->OnClick=AAPersonnelJacket_Weapon.InternalOnClick;
	//WeaponModInfoButton->OnKeyEvent=WeaponModInfoButton.InternalOnKeyEvent;
	UGUIImage* detailBK1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	detailBK1->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	detailBK1->ImageStyle = EImgStyle::ISTY_Stretched;
	detailBK1->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	detailBK1->WinTop = 0.07;
	detailBK1->WinLeft = 0.01;
	detailBK1->WinWidth = 0.98;
	detailBK1->WinHeight = 0.34;
	detailBK1->RenderWeight = 0.01;
	UGUIImage* detailBK2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	detailBK2->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	detailBK2->ImageStyle = EImgStyle::ISTY_Stretched;
	detailBK2->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	detailBK2->WinTop = 0.42;
	detailBK2->WinLeft = 0.01;
	detailBK2->WinWidth = 0.48;
	detailBK2->WinHeight = 0.49;
	detailBK2->RenderWeight = 0.01;
	UGUIImage* detailBK3 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	detailBK3->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	detailBK3->ImageStyle = EImgStyle::ISTY_Stretched;
	detailBK3->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	detailBK3->WinTop = 0.42;
	detailBK3->WinLeft = 0.51;
	detailBK3->WinWidth = 0.48;
	detailBK3->WinHeight = 0.066;
	detailBK3->RenderWeight = 0.01;
	UGUIImage* detailBK4 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	detailBK4->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	detailBK4->ImageStyle = EImgStyle::ISTY_Stretched;
	detailBK4->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	detailBK4->WinTop = 0.491;
	detailBK4->WinLeft = 0.51;
	detailBK4->WinWidth = 0.48;
	detailBK4->WinHeight = 0.27;
	detailBK4->RenderWeight = 0.01;
	UGUIImage* detailBK5 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	detailBK5->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	detailBK5->ImageStyle = EImgStyle::ISTY_Stretched;
	detailBK5->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	detailBK5->WinTop = 0.7685;
	detailBK5->WinLeft = 0.51;
	detailBK5->WinWidth = 0.48;
	detailBK5->WinHeight = 0.066;
	detailBK5->RenderWeight = 0.01;
	UGUIImage* detailBK6 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	detailBK6->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	detailBK6->ImageStyle = EImgStyle::ISTY_Stretched;
	detailBK6->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	detailBK6->WinTop = 0.843;
	detailBK6->WinLeft = 0.51;
	detailBK6->WinWidth = 0.48;
	detailBK6->WinHeight = 0.066;
	detailBK6->RenderWeight = 0.01;
	UGUIImage* WeaponBK = NewObject<UGUIImage>(UGUIImage::StaticClass());
	WeaponBK->ImageStyle = EImgStyle::ISTY_Scaled;
	WeaponBK->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	WeaponBK->WinTop = 0.02;
	WeaponBK->WinLeft = 0.02;
	WeaponBK->WinWidth = 0.46;
	WeaponBK->WinHeight = 0.38;
	WeaponBK->RenderWeight = 0.05;
	UGUIImage* WeaponBase = NewObject<UGUIImage>(UGUIImage::StaticClass());
	WeaponBase->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/m4mod/m4mod_main1_Mat.m4mod_main1_Mat'"), NULL, LOAD_None, NULL);
	WeaponBase->ImageStyle = EImgStyle::ISTY_Scaled;
	WeaponBase->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	WeaponBase->WinTop = 0.0725;
	WeaponBase->WinLeft = 0.0125;
	WeaponBase->WinWidth = 0.975;
	WeaponBase->WinHeight = 0.335;
	UGUIImage* mod = NewObject<UGUIImage>(UGUIImage::StaticClass());
	mod->ImageStyle = EImgStyle::ISTY_Scaled;
	mod->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	mod->WinTop = 0.2;
	mod->WinLeft = 0.72;
	mod->WinWidth = 0.24;
	mod->WinHeight = 0.2;
	mod->RenderWeight = 0.15;
	UGUILabel* RailLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	RailLabel->Caption = "Rails";
	RailLabel->TextAlign = ETextAlign::TXTA_Center;
	RailLabel->StyleName = "TextLabel";
	RailLabel->WinTop = 0.492;
	RailLabel->WinLeft = 0.51;
	RailLabel->WinWidth = 0.48;
	RailLabel->WinHeight = 0.053476;
	
	co_Set = SetCombo;
	co_TopRail = TopRailCombo;
	co_FrontRail = FrontRailCombo;
	co_BottomRail = BottomRailCombo;
	co_Barrel = BarrelCombo;
	i_BG1 = detailBK1;
	i_BG2 = detailBK2;
	i_BG3 = detailBK3;
	i_BG4 = detailBK4;
	i_BG5 = detailBK5;
	i_BG6 = detailBK6;
	i_WeaponBK = WeaponBK;
	i_WeaponBase = WeaponBase;
	i_Mod = mod;
	i_WeaponLayer = { WeaponLayer,WeaponLayer, WeaponLayer,WeaponLayer,WeaponLayer,WeaponLayer };
	lb_Weapons = WeaponDescription;
	b_WeaponModInfo = WeaponModInfoButton;
	l_Rails = RailLabel;
	//CurrentWeapon = Weapon_M4A1_Rifle_Mod;
	Teams = { "U.S. Army", "Enemy" };
	Skins = { "Black","Desert","Arctic" };
	SkinTags = {"none", "des", "arc"};
	HiddenText = "Hidden";
	LoadingText = "...Loading Weapons...";
	PanelCaption = "M4A1 Weapon Modification";
	//OnRendered = AAPersonnelJacket_Weapon.InternalDraw;
	//OnDeActivate = AAPersonnelJacket_Weapon.InternalDeactivate;
}

void UAAPersonnelJacket_Weapon::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	FString Directory = "";
	FString File = "";
	Super::InitComponent(MyController, MyOwner);
	InitializeCombos();
	Directory = GetBaseDir() $ "Descriptions\\";
	File = "Weapon_M4A1.txt";
	if (AAGUIController(Controller) != None)
	{
		lb_Weapons.SetContent(AAGUIController(Controller).LoadTextFromFile(Directory $ File));
	}
	*/
}

void UAAPersonnelJacket_Weapon::InitializeCombos()
{
}

void UAAPersonnelJacket_Weapon::IntializeWeapons()
{
	/*
	local AAGenericMessageBox page;
	if (Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "", LoadingText))
	{
		page = AAGenericMessageBox(Controller.ActivePage);
		page.RemoveComponent(page.b_OK);
		page.RemoveComponent(page.l_Text);
		page.l_Text2.FontScale = 2;
		page.l_Text2.WinHeight = 1;
		page.l_Text2.WinTop = 0;
		page.l_Text2.bBoundToParent = true;
		page.l_Text2.bScaleToParent = true;
		page.l_Text2.VertAlign = 1;
		page.l_Text2.TextAlign = 1;
		page.bRenderWorld = false;
		page.__OnRendered__Delegate = ReallyInitializeWeapons;
	}
	*/
}

void UAAPersonnelJacket_Weapon::ReallyInitializeWeapons(UCanvas* C)
{
	/*
	if (Controller.ActivePage.Tag != 55)
	{
		Controller.ActivePage.Tag = 55;
		return;
	}
	if (Controller.ActivePage != PageOwner)
	{
		Controller.CloseMenu(true);
	}
	FocusFirst(None);
	UpdateCurrentWeapon();
	*/
}

void UAAPersonnelJacket_Weapon::ShowPanel(bool bShow)
{
	/*
	Super::ShowPanel(bShow);
	if (bShow)
	{
		if (bInit)
		{
			bInit = false;
		}
	}
	*/
}

void UAAPersonnelJacket_Weapon::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	switch (Sender)
	{
	case co_Set:
		LoadSet();
		break;
	case co_TopRail:
		LoadMod(co_TopRail, "0");
		break;
	case co_FrontRail:
		LoadMod(co_FrontRail, "1");
		break;
	case co_BottomRail:
		LoadMod(co_BottomRail, "4");
		break;
	case co_Barrel:
		LoadMod(co_Barrel, "5");
		break;
	case lb_Weapons:
		break;
	case lb_Mods:
		break;
	default:
		break;
	}
	*/
}

void UAAPersonnelJacket_Weapon::InternalOnChange(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case co_Set:
		SetChanged();
		break;
	case co_TopRail:
		ModChanged(co_TopRail, "0");
		break;
	case co_FrontRail:
		ModChanged(co_FrontRail, "1");
		break;
	case co_BottomRail:
		ModChanged(co_BottomRail, "4");
		break;
	case co_Barrel:
		ModChanged(co_Barrel, "5");
		break;
	case lb_Weapons:
		break;
	case lb_Mods:
		break;
	default:
		break;
	}
	*/
}

bool UAAPersonnelJacket_Weapon::InternalOnClick(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case b_WeaponInfo:
		InfoClicked(Sender);
		break;
	case b_WeaponModInfo:
		InfoClicked(Sender);
		break;
	default:
	}
	*/
	return true;
}

void UAAPersonnelJacket_Weapon::InternalDraw(UCanvas* Canvas)
{
	/*
	FVector CamPos = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	FRotator CamRot = FRotator(0, 0, 0);
	Canvas.GetCameraLocation(CamPos, CamRot);
	GetAxes(CamRot, X, Y, Z);
	*/
}

void UAAPersonnelJacket_Weapon::Opened(UGUIComponent* Sender)
{
	/*
	Super::Opened(Sender);
	ResetModOverlay(0);
	ResetModOverlay(1);
	ResetModOverlay(4);
	ResetModOverlay(5);
	CurrentWeaponMod = GetWeaponModClass(0);
	UpdateCurrentWeaponMod();
	SetModImages(0, CurrentWeaponMod.Default.ModImage, CurrentWeaponMod.Default.ModImageOverlay);
	*/
}

void UAAPersonnelJacket_Weapon::Closed(UGUIComponent* Sender, bool bCancelled)
{
	//Super::Closed(Sender, bCancelled);
	//HideSpinnyWeaponAndMod();
}

void UAAPersonnelJacket_Weapon::InternalDeactivate()
{
	//HideSpinnyWeaponAndMod();
}

void UAAPersonnelJacket_Weapon::Free()
{
	//Super::Free();
}

void UAAPersonnelJacket_Weapon::Refresh()
{
}

void UAAPersonnelJacket_Weapon::SaveSettings()
{
}

void UAAPersonnelJacket_Weapon::WeaponsInitialized()
{
}

void UAAPersonnelJacket_Weapon::LoadSet()
{
	/*
	int32 i = 0;
	if (HumanController(PlayerOwner()) == nullptr)
	{
		return;
	}
	co_Set.ResetComponent();
	for (i = 0; i < 5; i++)
	{
		co_Set.addItem(HumanController(PlayerOwner()).GetIndexName(i));
	}
	co_Set.SetIndex(HumanController(PlayerOwner()).GetCurrentIndex());
	*/
}

void UAAPersonnelJacket_Weapon::SetChanged()
{
	/*
	if (HumanController(PlayerOwner()) == nullptr)
	{
		return;
	}
	bLoadingSet = true;
	HumanController(PlayerOwner()).SetIndex(co_Set.GetIndex());
	HumanController(PlayerOwner()).SetIndexName(co_Set.GetIndex(), co_Set.GetText());
	RefreshMods();
	AttachModsToWeapon();
	CurrentWeaponMod = GetWeaponModClass(0);
	UpdateCurrentWeaponMod();
	SetModImages(0, CurrentWeaponMod.Default.ModImage, CurrentWeaponMod.Default.ModImageOverlay);
	bLoadingSet = false;
	*/
}

void UAAPersonnelJacket_Weapon::LoadMod(UGUIComponent* Sender, FString S)
{
	/*
	int32 Slot = 0;
	int32 i = 0;
	local XInterface.moComboBox Box;
	FString default_mod = "";
	local class<BaseWeaponMod>  BWM;
	local HumanController HC;
	Box = moComboBox(Sender);
	if (Box == nullptr)
	{
		return;
	}
	Box.ResetComponent();
	RefreshMods();
	HC = HumanController(PlayerOwner());
	Slot = int(S);
	if ((Slot >= 0) && (Slot <= 5))
	{
		BWM = class<BaseWeaponMod>(DynamicLoadObject(CurrentWeapon.Default.WM_Default[Slot], Class'Class', true));
	}
	if (BWM == nullptr)
	{
		default_mod = "None";
	}
	else
	{
		default_mod = BWM.GetModName();
	}
	Box.addItem(default_mod);
	for (i = 0; i < CurrentWeapon.Default.LegalModList.Length; i++)
	{
		BWM = CurrentWeapon.Default.LegalModList[i];
		if (BWM.Default.ValidSlot[Slot] == 1)
		{
			if (BWM.GetModName() != default_mod)
			{
				Box.addItem(BWM.GetModName());
			}
		}
	}
	if (BWM != None)
	{
		CurrentWeaponMod = BWM;
	}
	UpdateCurrentWeaponMod();
	RefreshMods();
	*/
}

void UAAPersonnelJacket_Weapon::ModChanged(UGUIComponent* Sender, FString S)
{
	/*
	int32 Slot = 0;
	int32 i = 0;
	int32 j = 0;
	FString mod_text = "";
	local XInterface.moComboBox Box;
	local XInterface.moComboBox OtherBox;
	local class<BaseWeaponMod>  BWM;
	Box = moComboBox(Sender);
	if (Box == nullptr)
	{
		return;
	}
	i = 0;
	if (i < CurrentWeapon.Default.LegalModList.Length)
	{
		BWM = CurrentWeapon.Default.LegalModList[i];
		if (BWM.GetModName() == Box.GetText())
		{
			mod_text = string(BWM);
		}
		else
		{
			i++;
		}
	}
	for (i = 0; i < BWM.Default.ExclusiveModsList.Length; i++)
	{
		for (j = 0; j < Controls.Length; j++)
		{
			OtherBox = moComboBox(Controls[j]);
			if (OtherBox == nullptr)
			{
			}
			if (BWM.Default.ExclusiveModsList[i].GetModName() == OtherBox.GetText())
			{
				OtherBox.SetIndex(0);
			}
		}
	}
	if (BWM != None)
	{
		CurrentWeaponMod = BWM;
	}
	UpdateCurrentWeaponMod();
	Slot = int(S);
	if ((HumanController(PlayerOwner()) != None) && (!bLoadingSet))
	{
		HumanController(PlayerOwner()).SetWeapon(string(CurrentWeapon));
		HumanController(PlayerOwner()).SetMod(Slot, mod_text);
	}
	AttachModsToWeapon();
	SetModImages(int(S), CurrentWeaponMod.Default.ModImage, CurrentWeaponMod.Default.ModImageOverlay);
	*/
}

void UAAPersonnelJacket_Weapon::SetModImages(int32 Slot, UMaterialInstance* Image, UMaterialInstance* Overlay)
{
	/*
	i_Mod.Image = Image;
	if ((Slot == 4) && (Overlay == Texture'T_AA2_UI.m4mod.m4mod_heatupper'))
	{
		i_WeaponLayer[Slot].Image = Texture'T_AA2_UI.m4mod.m4mod_heatlower';
	}
	else
	{
		i_WeaponLayer[Slot].Image = Overlay;
	}
	*/
}

bool UAAPersonnelJacket_Weapon::InfoClicked(UGUIComponent* Sender)
{
	/*
	UpdateCurrentWeaponMod();
	switch (Sender)
	{
	case b_WeaponInfo:
		break;
	case b_WeaponModInfo:
		UpdateCurrentWeaponMod();
		if (CurrentWeaponMod == nullptr)
		{
			return false;
		}
		if ((CurrentWeaponMod.GetModName() ~= "") || (CurrentWeaponMod.GetModName() ~= "NONE"))
		{
			return false;
		}
		Controller.OpenMenu("AGP_Interface.InfoPageBase", , CurrentWeaponMod.GetModName());
		break;
	default:
	}
	*/
	return true;
}

void UAAPersonnelJacket_Weapon::UpdateCurrentWeapon()
{
	/*
	local class<InventoryAttachment>  attachClass;
	if (CurrentWeapon != None)
	{
		if (HumanController(PlayerOwner()) != None)
		{
			HumanController(PlayerOwner()).SetWeapon(string(CurrentWeapon));
		}
		if (Team == 0)
		{
			attachClass = CurrentWeapon.Default.AttachmentClass;
		}
		else
		{
			attachClass = CurrentWeapon.Default.PickupClass.Default.EnemyPickupClass.Default.InventoryType.Default.AttachmentClass;
		}
		if (attachClass != None)
	}
	{
	}
	RefreshMods();
	AttachModsToWeapon();
	i_WeaponBase.Image = CurrentWeapon.Default.WeaponImage;
	*/
}

void UAAPersonnelJacket_Weapon::UpdateCurrentWeaponMod()
{
	/*
	local class<BaseModAttachment>  attachClass;
	if (CurrentWeaponMod != None)
	{
		attachClass = CurrentWeaponMod.GetModAttachment();
		if (attachClass != None)
	}
	{
	}
	*/
}

void UAAPersonnelJacket_Weapon::AttachModsToWeapon()
{
	/*
	int32 i = 0;
	local class<BaseWeaponMod>  BWM;
	local class<BaseModAttachment>  BMA;
	local HumanController HC;
	if (PlayerOwner() == nullptr)
	{
		return;
	}
	HC = HumanController(PlayerOwner());
	for (i = 0; i < 6; i++)
	{
		if (HC != None)
		{
			BWM = class<BaseWeaponMod>(DynamicLoadObject(HC.WM_Slot[i], Class'Class', true));
		}
		if (BWM != None)
		{
			BMA = BWM.GetModAttachment();
			if (BMA != None)
		}
		{
		}
	}
	*/
}

int32 UAAPersonnelJacket_Weapon::GetModIndex(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case co_TopRail:
		return 0;
		break;
	case co_FrontRail:
		return 1;
		break;
	case co_BottomRail:
		return 4;
		break;
	case co_Barrel:
		return 5;
		break;
	default:
	}
	*/
	return -1;
}

void UAAPersonnelJacket_Weapon::RefreshMods()
{
	/*
	co_TopRail.SetIndex(co_TopRail.FindIndex(GetModDescription(0), true));
	co_FrontRail.SetIndex(co_FrontRail.FindIndex(GetModDescription(1), true));
	co_BottomRail.SetIndex(co_BottomRail.FindIndex(GetModDescription(4), true));
	co_Barrel.SetIndex(co_Barrel.FindIndex(GetModDescription(5), true));
	*/
}

ABaseWeaponMod* UAAPersonnelJacket_Weapon::GetWeaponModClass(int32 slot_index)
{
	ABaseWeaponMod* BWM = nullptr;
	/*
	AHumanController* HC = nullptr;
	HC = HumanController(PlayerOwner());
	BWM = class<BaseWeaponMod>(DynamicLoadObject(HC.WM_Slot[slot_index], Class'Class', true));
	if (BWM == nullptr)
	{
		BWM = class<BaseWeaponMod>(DynamicLoadObject(CurrentWeapon.Default.WM_Default[slot_index], Class'Class'));
	}
	*/
	return BWM;
}

FString UAAPersonnelJacket_Weapon::GetModDescription(int32 slot_index)
{
	/*
	local class<BaseWeaponMod>  BWM;
	if ((slot_index < 0) || (slot_index > 5))
	{
		return "INVALID SLOT";
	}
	BWM = GetWeaponModClass(slot_index);
	return BWM.GetModName();
	*/
	return "FAKE";     //FAKE   /ELiZ
}

void UAAPersonnelJacket_Weapon::ResetModOverlay(int32 slot_index)
{
	/*
	local class<BaseWeaponMod>  BWM;
	if ((slot_index < 0) || (slot_index > 5))
	{
		return;
	}
	BWM = GetWeaponModClass(slot_index);
	SetModImages(slot_index, BWM.Default.ModImage, BWM.Default.ModImageOverlay);
	*/
}

void UAAPersonnelJacket_Weapon::HideSpinnyWeaponAndMod()
{
}
