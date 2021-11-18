// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AATeamGamePanel/AAGameMenu_WeaponClass/AAGameMenu_WeaponClass.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/GUIMultiColumnListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UAAGameMenu_WeaponClass::UAAGameMenu_WeaponClass()
{
	UGUIMultiColumnListBox* UnassignedBox = NewObject<UGUIMultiColumnListBox>(UGUIMultiColumnListBox::StaticClass());
	UnassignedBox->DefaultListClass="AGP_Interface.AAUnassignedTeamList";
	UnassignedBox->bVisibleWhenEmpty=true;
	//UnassignedBox->OnCreateComponent=UnassignedBox.InternalOnCreateComponent;
	UnassignedBox->StyleName="RosterUnitText";
	UnassignedBox->WinTop=0.02;
	UnassignedBox->WinLeft=0.51;
	UnassignedBox->WinWidth=0.47;
	UnassignedBox->WinHeight=0.78;
	UnassignedBox->bBoundToParent=true;
	UnassignedBox->bScaleToParent=true;
	UGUIMultiColumnListBox* UnitBox = NewObject<UGUIMultiColumnListBox>(UGUIMultiColumnListBox::StaticClass());
	UnitBox->DefaultListClass="AGP_Interface.AAUnitGMCList";
	UnitBox->bVisibleWhenEmpty=true;
	//UnitBox->OnCreateComponent=UnitBox.InternalOnCreateComponent;
	UnitBox->StyleName="RosterUnitText";
	UnitBox->WinTop=0.02;
	UnitBox->WinLeft=0.02;
	UnitBox->WinWidth=0.47;
	UnitBox->WinHeight=0.78;
	UnitBox->bBoundToParent=true;
	UnitBox->bScaleToParent=true;
	UmoComboBox* WeaponCombo = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	WeaponCombo->bReadOnly=true;
	WeaponCombo->Caption="Loadout";
	//WeaponCombo->OnCreateComponent=WeaponCombo.InternalOnCreateComponent;
	WeaponCombo->Hint="Select the weapon mod set you wish to use.";
	WeaponCombo->WinTop=0.82;
	WeaponCombo->WinLeft=0.52;
	WeaponCombo->WinWidth=0.45;
	WeaponCombo->WinHeight=0.06;
	WeaponCombo->bBoundToParent=true;
	WeaponCombo->bScaleToParent=true;
	WeaponCombo->bStandardized=false;
	//WeaponCombo->OnChange=AAGameMenu_WeaponClass.InternalOnChangeSet;
	//WeaponCombo->OnLoadINI=AAGameMenu_WeaponClass.InternalOnLoadSet;
	UmoCheckBox* MedicCheck = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	MedicCheck->CaptionWidth=0.7;
	MedicCheck->Caption="Request Medic Class";
	//MedicCheck->OnCreateComponent=MedicCheck.InternalOnCreateComponent;
	MedicCheck->Hint="Click here to request the Medic class.";
	MedicCheck->WinTop=0.82;
	MedicCheck->WinLeft=0.03;
	MedicCheck->WinWidth=0.45;
	MedicCheck->WinHeight=0.06;
	MedicCheck->bBoundToParent=true;
	MedicCheck->bScaleToParent=true;
	MedicCheck->bStandardized=false;
	//MedicCheck->OnChange=AAGameMenu_WeaponClass.InternalOnChange;
	UGUIImage* MyBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//MyBackground->Image=Texture'T_AA2_UI.Menu.backgroundfill';
	MyBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	MyBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MyBackground->WinTop=0.01;
	MyBackground->WinLeft=0.01;
	MyBackground->WinWidth=0.98;
	MyBackground->WinHeight=0.89;
	MyBackground->RenderWeight=0;
	MyBackground->bBoundToParent=true;
	MyBackground->bScaleToParent=true;
	UGUIImage* PreferenceBack = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//PreferenceBack->Image=Texture'T_AA2_UI.Menu.field_translucent';
	PreferenceBack->ImageStyle = EImgStyle::ISTY_Stretched;
	PreferenceBack->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	PreferenceBack->WinTop=0.81;
	PreferenceBack->WinLeft=0.02;
	PreferenceBack->WinWidth=0.47;
	PreferenceBack->WinHeight=0.08;
	UGUIImage* LoadoutBack = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//LoadoutBack->Image=Texture'T_AA2_UI.Menu.field_translucent';
	LoadoutBack->ImageStyle = EImgStyle::ISTY_Stretched;
	LoadoutBack->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	LoadoutBack->WinTop=0.81;
	LoadoutBack->WinLeft=0.51;
	LoadoutBack->WinWidth=0.47;
	LoadoutBack->WinHeight=0.08;

	i_Background = MyBackground;
	i_PreferencePanel = PreferenceBack;
	i_LoadoutPanel = LoadoutBack;
	cb_Loadout = WeaponCombo;
	//ch_Medic = MedicCheck;
	lb_UnassignedTeam = UnassignedBox;
	lb_Unit = UnitBox;
	WarningString = "You will no longer be a medic because someone with a higher priority has selected it. Riflemen have the highest priority, fireteam leaders have the lowest priority, snipers and squad leaders cannot be medics at all.";
	QualifyString = "You must qualify as a medic before you can request the medic class.";
	WaitString = "You will automatically select this slot if it is still available when your timer runs out.";
	ChooseString = "You may choose your class when your timer runs out.  Priority is based on a combination of your honor and your current score.";
	lastTeam = 255;
	//OnPreDraw = AAGameMenu_WeaponClass.MyOnPreDraw;
}

void UAAGameMenu_WeaponClass::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local HumanController HC;
	lb_UnassignedTeam.Header.bAcceptsInput = false;
	lb_Unit.Header.bAcceptsInput = false;
	Super::InitComponent(MyController, MyOwner);
	InitializeCombos();
	Team = AGP_TeamInfo(PlayerOwner().PlayerReplicationInfo.Team);
	SetTeam(Team);
	HC = HumanController(PlayerOwner());
	if (HC != None)
	{
		if (ch_Medic.IsChecked() && (!HC.PlayerReplicationInfo.bQualifiedMedic))
		{
			SetWarning(true, 1);
			ch_Medic.Checked(false);
		}
		ch_Medic.Checked(HC.PlayerReplicationInfo.bWantsMedic);
	}
	SetTimer(0.05, true);
	Timer();
	*/
}

void UAAGameMenu_WeaponClass::SetTeam(ATeamInfo* TI)
{
	/*
	Super::SetTeam(TI);
	if (AATeamList(lb_Unit.List) != None)
	{
		AATeamList(lb_Unit.List).SetTeam(TI);
	}
	if (AATeamList(lb_UnassignedTeam.List) != None)
	{
		AATeamList(lb_UnassignedTeam.List).SetTeam(TI);
	}
	*/
}

void UAAGameMenu_WeaponClass::Refresh()
{
	/*
	local HumanController HC;
	Team = AGP_TeamInfo(PlayerOwner().PlayerReplicationInfo.Team);
	SetTeam(Team);
	HC = HumanController(PlayerOwner());
	if (HC != None)
	{
		if (ch_Medic.IsChecked() && (!HC.PlayerReplicationInfo.bQualifiedMedic))
		{
			SetWarning(true, 1);
			ch_Medic.Checked(false);
		}
		ch_Medic.Checked(HC.PlayerReplicationInfo.bWantsMedic);
	}
	*/
}

void UAAGameMenu_WeaponClass::InitializeCombos()
{
	//InternalOnLoadSet(cb_Loadout, "");
}

bool UAAGameMenu_WeaponClass::MyOnPreDraw(UCanvas* C)
{
	/*
	FString WeaponString = "";
	local HumanController HC;
	HC = HumanController(PlayerOwner());
	if (((HC != None) && (HC.PlayerReplicationInfo != None)) && (HC.PlayerReplicationInfo.myPawn != None))
	{
		if (HC.PlayerReplicationInfo.myPawn.Weapon != None)
		{
			WeaponString = HC.PlayerReplicationInfo.myPawn.Weapon.ItemName;
		}
	}
	if (WeaponString != "")
	{
		cb_Loadout.MyLabel.Caption = "Loadout" $ " (" $ WeaponString $ ")";
	}
	else
	{
		cb_Loadout.MyLabel.Caption = "Weapon Loadout";
	}
	*/
	return true;
}

bool UAAGameMenu_WeaponClass::CanShowPanel()
{
	/*
	local PlayerController PC;
	PC = PlayerOwner();
	if (((PC.PlayerReplicationInfo != None) && (PC.PlayerReplicationInfo.Team != None)) && ((PC.PlayerReplicationInfo.Team.TeamIndex != 255) || ((PC.PlayerReplicationInfo.DesiredTeam != 255) && (PC.GameReplicationInfo.Teams[PC.PlayerReplicationInfo.DesiredTeam].Size < PC.GameReplicationInfo.Teams[PC.PlayerReplicationInfo.DesiredTeam].MaxSize))))
	{
		return true;
	}
	*/
	return false;
}

void UAAGameMenu_WeaponClass::Timer()
{
	/*
	if (((PlayerOwner() != None) && (PlayerOwner().PlayerReplicationInfo != None)) && (PlayerOwner().PlayerReplicationInfo.Team != None))
	{
		if (PlayerOwner().PlayerReplicationInfo.Team.TeamIndex != lastTeam)
		{
			Refresh();
		}
		lastTeam = PlayerOwner().PlayerReplicationInfo.Team.TeamIndex;
	}
	*/
}

void UAAGameMenu_WeaponClass::SetWarning(bool abVisible, uint8 Message)
{
}

void UAAGameMenu_WeaponClass::VerifyMedic(bool bWants)
{
}

void UAAGameMenu_WeaponClass::InternalOnChange(UGUIComponent* Sender)
{
	/*
	local HumanController HC;
	switch (Sender)
	{
	case ch_Medic:
		HC = HumanController(PlayerOwner());
		if (HC != None)
		{
			if (ch_Medic.IsChecked() && (!HC.PlayerReplicationInfo.bQualifiedMedic))
			{
				SetWarning(true, 1);
				ch_Medic.Checked(false);
			}
			HC.RequestMedic(ch_Medic.IsChecked());
		}
		break;
	default:
		break;
	}
	*/
}

void UAAGameMenu_WeaponClass::ShowPanel(bool bShow)
{
	/*
	Super::ShowPanel(bShow);
	Refresh();
	*/
}

void UAAGameMenu_WeaponClass::InternalOnLoadSet(UGUIComponent* Sender, FString S)
{
	/*
	int32 i = 0;
	if (Sender == cb_Loadout)
	{
		cb_Loadout.ResetComponent();
		if (HumanController(PlayerOwner()) != None)
		{
			for (i = 0; i < 5; i++)
			{
				cb_Loadout.addItem(HumanController(PlayerOwner()).GetIndexName(i));
			}
		}
		cb_Loadout.SetIndex(HumanController(PlayerOwner()).GetCurrentIndex());
	}
	*/
}

void UAAGameMenu_WeaponClass::InternalOnChangeSet(UGUIComponent* Sender)
{
	/*
	if (Sender == cb_Loadout)
	{
		if (HumanController(PlayerOwner()) != None)
		{
			HumanController(PlayerOwner()).SetIndex(cb_Loadout.GetIndex());
			HumanController(PlayerOwner()).SetIndexName(cb_Loadout.GetIndex(), cb_Loadout.GetText());
		}
	}
	*/
}