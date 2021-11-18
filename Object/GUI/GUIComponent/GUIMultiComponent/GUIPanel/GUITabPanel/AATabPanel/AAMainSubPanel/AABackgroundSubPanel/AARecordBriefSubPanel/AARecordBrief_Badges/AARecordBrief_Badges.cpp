// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AARecordBriefSubPanel/AARecordBrief_Badges/AARecordBrief_Badges.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImageButton/GUIImageButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/AAGUILabel/AAGUILabel.h"

UAARecordBrief_Badges::UAARecordBrief_Badges()
{
	UGUIImageButton* RifleBadge = NewObject<UGUIImageButton>(UGUIImageButton::StaticClass());
	RifleBadge->ImageStyle = EImgStyle::ISTY_Scaled;
	RifleBadge->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	RifleBadge->Hint="Basic Rifle Marksmanship Qualification Training";
	RifleBadge->WinTop=0.1;
	RifleBadge->WinLeft=0.02;
	RifleBadge->WinWidth=0.3;
	RifleBadge->WinHeight=0.3;
	RifleBadge->RenderWeight=0.99999;
	RifleBadge->bBoundToParent=true;
	RifleBadge->bScaleToParent=true;
	//RifleBadge->OnClick=AARecordBrief_Badges.BadgeClick;
	//RifleBadge->OnKeyEvent=RifleBadge.InternalOnKeyEvent;
	UGUIImageButton* CombatMedicBadge = NewObject<UGUIImageButton>(UGUIImageButton::StaticClass());
	CombatMedicBadge->ImageStyle = EImgStyle::ISTY_Scaled;
	CombatMedicBadge->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	CombatMedicBadge->Hint="Army MOS 68W Expert Field Medic First Aid and Combat Lifesaving Training";
	CombatMedicBadge->WinTop=0.1;
	CombatMedicBadge->WinLeft=0.34;
	CombatMedicBadge->WinWidth=0.3;
	CombatMedicBadge->WinHeight=0.3;
	CombatMedicBadge->RenderWeight=1;
	CombatMedicBadge->bBoundToParent=true;
	CombatMedicBadge->bScaleToParent=true;
	//CombatMedicBadge->OnClick=AARecordBrief_Badges.BadgeClick;
	//CombatMedicBadge->OnKeyEvent=CombatMedicBadge.InternalOnKeyEvent;
	UGUIImageButton* AirborneBadge = NewObject<UGUIImageButton>(UGUIImageButton::StaticClass());
	AirborneBadge->ImageStyle = EImgStyle::ISTY_Scaled;
	AirborneBadge->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	AirborneBadge->Hint="Jump School Training at Fort Benning, Georgia awards the Jump Wings, Red Beret and Airborne Tab";
	AirborneBadge->WinTop=0.1;
	AirborneBadge->WinLeft=0.66;
	AirborneBadge->WinWidth=0.3;
	AirborneBadge->WinHeight=0.3;
	AirborneBadge->bBoundToParent=true;
	AirborneBadge->bScaleToParent=true;
	//AirborneBadge->OnClick=AARecordBrief_Badges.BadgeClick;
	//AirborneBadge->OnKeyEvent=AirborneBadge.InternalOnKeyEvent;
	UGUIImageButton* DriverBadge = NewObject<UGUIImageButton>(UGUIImageButton::StaticClass());
	DriverBadge->ImageStyle = EImgStyle::ISTY_Scaled;
	DriverBadge->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	DriverBadge->Hint="CROWS Equipped Up-Armored HMMWV Driving and Gunnery Qualification Training";
	DriverBadge->WinTop=0.5;
	DriverBadge->WinLeft=0.02;
	DriverBadge->WinWidth=0.3;
	DriverBadge->WinHeight=0.3;
	//DriverBadge->OnClick=AARecordBrief_Badges.BadgeClick;
	//DriverBadge->OnKeyEvent=DriverBadge.InternalOnKeyEvent;
	UGUIImageButton* ExpertInfantryBadge = NewObject<UGUIImageButton>(UGUIImageButton::StaticClass());
	ExpertInfantryBadge->ImageStyle = EImgStyle::ISTY_Scaled;
	ExpertInfantryBadge->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	ExpertInfantryBadge->Hint="Javelin Qualification Training will award the Expert Infantry Badge, the culmination of your Infantry experience";
	ExpertInfantryBadge->WinTop=0.59;
	ExpertInfantryBadge->WinLeft=0.29;
	ExpertInfantryBadge->WinWidth=0.4;
	ExpertInfantryBadge->WinHeight=0.1;
	ExpertInfantryBadge->bBoundToParent=true;
	ExpertInfantryBadge->bScaleToParent=true;
	//ExpertInfantryBadge->OnClick=AARecordBrief_Badges.BadgeClick;
	//ExpertInfantryBadge->OnKeyEvent=ExpertInfantryBadge.InternalOnKeyEvent;
	UGUIImageButton* SFBadge = NewObject<UGUIImageButton>(UGUIImageButton::StaticClass());
	SFBadge->ImageStyle = EImgStyle::ISTY_Scaled;
	SFBadge->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	SFBadge->Hint="Earning the Green Beret represents completion of the Army's most elite Training and skill qualifications";
	SFBadge->WinTop=0.5;
	SFBadge->WinLeft=0.66;
	SFBadge->WinWidth=0.3;
	SFBadge->WinHeight=0.3;
	SFBadge->bBoundToParent=true;
	SFBadge->bScaleToParent=true;
	//SFBadge->OnClick=AARecordBrief_Badges.BadgeClick;
	//SFBadge->OnKeyEvent=SFBadge.InternalOnKeyEvent;
	UAAGUILabel* XPLabel = NewObject<UAAGUILabel>(UAAGUILabel::StaticClass());
	XPLabel->TextAlign = ETextAlign::TXTA_Center;
	XPLabel->TextColor=FColor(141, 191, 152, 255);
	XPLabel->TextFont="AAFontMedium";
	XPLabel->bMultiLine=true;
	XPLabel->WinTop=0.07;
	XPLabel->WinLeft=0.02;
	XPLabel->WinWidth=0.96;
	XPLabel->WinHeight=0.1;
	XPLabel->RenderWeight=0.6;
	XPLabel->bBoundToParent=true;
	XPLabel->bScaleToParent=true;
	UAAGUILabel* ToGoLabel = NewObject<UAAGUILabel>(UAAGUILabel::StaticClass());
	ToGoLabel->TextAlign = ETextAlign::TXTA_Center;
	ToGoLabel->TextColor=FColor(141, 191, 152, 255);
	ToGoLabel->TextFont="AAFontMedium";
	ToGoLabel->bMultiLine=true;
	ToGoLabel->WinTop=0.1;
	ToGoLabel->WinLeft=0.02;
	ToGoLabel->WinWidth=0.96;
	ToGoLabel->WinHeight=0.1;
	ToGoLabel->RenderWeight=0.6;
	ToGoLabel->bBoundToParent=true;
	ToGoLabel->bScaleToParent=true;
	UGUILabel* RifleLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	RifleLabel->TextAlign = ETextAlign::TXTA_Center;
	RifleLabel->TextColor=FColor(141, 191, 152, 255);
	RifleLabel->TextFont="AAFontMedium";
	RifleLabel->bMultiLine=true;
	RifleLabel->WinTop=0.375;
	RifleLabel->WinLeft=0.02;
	RifleLabel->WinWidth=0.3;
	RifleLabel->WinHeight=0.2;
	RifleLabel->RenderWeight=0.9999;
	RifleLabel->bBoundToParent=true;
	RifleLabel->bScaleToParent=true;
	UGUILabel* CombatMedicLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	CombatMedicLabel->TextAlign = ETextAlign::TXTA_Center;
	CombatMedicLabel->TextColor=FColor(141, 191, 152, 255);
	CombatMedicLabel->TextFont="AAFontMedium";
	CombatMedicLabel->bMultiLine=true;
	CombatMedicLabel->WinTop=0.375;
	CombatMedicLabel->WinLeft=0.34;
	CombatMedicLabel->WinWidth=0.3;
	CombatMedicLabel->WinHeight=0.2;
	CombatMedicLabel->RenderWeight=0.9999;
	CombatMedicLabel->bBoundToParent=true;
	CombatMedicLabel->bScaleToParent=true;
	UGUILabel* AirborneLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	AirborneLabel->TextAlign = ETextAlign::TXTA_Center;
	AirborneLabel->TextColor=FColor(141, 191, 152, 255);
	AirborneLabel->TextFont="AAFontMedium";
	AirborneLabel->bMultiLine=true;
	AirborneLabel->WinTop=0.375;
	AirborneLabel->WinLeft=0.66;
	AirborneLabel->WinWidth=0.3;
	AirborneLabel->WinHeight=0.2;
	AirborneLabel->RenderWeight=0.9999;
	AirborneLabel->bBoundToParent=true;
	AirborneLabel->bScaleToParent=true;
	UGUILabel* DriverLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DriverLabel->TextAlign = ETextAlign::TXTA_Center;
	DriverLabel->TextColor=FColor(141, 191, 152, 255);
	DriverLabel->TextFont="AAFontMedium";
	DriverLabel->bMultiLine=true;
	DriverLabel->WinTop=0.775;
	DriverLabel->WinLeft=0.02;
	DriverLabel->WinWidth=0.3;
	DriverLabel->WinHeight=0.2;
	DriverLabel->RenderWeight=0.9999;
	DriverLabel->bBoundToParent=true;
	DriverLabel->bScaleToParent=true;
	UGUILabel* ExpertInfantryLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	ExpertInfantryLabel->TextAlign = ETextAlign::TXTA_Center;
	ExpertInfantryLabel->TextColor=FColor(141, 191, 152, 255);
	ExpertInfantryLabel->TextFont="AAFontMedium";
	ExpertInfantryLabel->bMultiLine=true;
	ExpertInfantryLabel->WinTop=0.775;
	ExpertInfantryLabel->WinLeft=0.34;
	ExpertInfantryLabel->WinWidth=0.3;
	ExpertInfantryLabel->WinHeight=0.2;
	ExpertInfantryLabel->RenderWeight=0.9999;
	ExpertInfantryLabel->bBoundToParent=true;
	ExpertInfantryLabel->bScaleToParent=true;
	UGUILabel* SFLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	SFLabel->TextAlign = ETextAlign::TXTA_Center;
	SFLabel->TextColor=FColor(141, 191, 152, 255);
	SFLabel->TextFont="AAFontMedium";
	SFLabel->bMultiLine=true;
	SFLabel->WinTop=0.775;
	SFLabel->WinLeft=0.66;
	SFLabel->WinWidth=0.3;
	SFLabel->WinHeight=0.07;
	SFLabel->RenderWeight=0.9999;
	SFLabel->bBoundToParent=true;
	SFLabel->bScaleToParent=true;
	
	lXPLabel = XPLabel;
	lTogo = ToGoLabel;
	ibRifleBadge = RifleBadge;
	lRifleLabel = RifleLabel;
	ibExpertInfantryBadge = ExpertInfantryBadge;
	lExpertInfantryLabel = ExpertInfantryLabel;
	ibDriverBadge = DriverBadge;
	lDriverLabel = DriverLabel;
	ibCombatMedicBadge = CombatMedicBadge;
	lCombatMedicLabel = CombatMedicLabel;
	ibAirborneBadge = AirborneBadge;
	lAirborneLabel = AirborneLabel;
	ibSFBadge = SFBadge;
	lSFLabel = SFLabel;
	DefaultPanelText = "Badges";
	LoggedInPanelText = "Badges for ";
	PanelCaption = "Badges for %UserName%";

}

void UAARecordBrief_Badges::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	ibRifleBadge.ToolTip.MaxWidth = 0.5;
	ibExpertInfantryBadge.ToolTip.MaxWidth = 0.5;
	ibDriverBadge.ToolTip.MaxWidth = 0.5;
	ibCombatMedicBadge.ToolTip.MaxWidth = 0.5;
	ibAirborneBadge.ToolTip.MaxWidth = 0.5;
	ibSFBadge.ToolTip.MaxWidth = 0.5;
	*/
}

void UAARecordBrief_Badges::Opened(UGUIComponent* Sender)
{
	/*
	local PlayerReplicationInfo PRI;
	int32 Grade = 0;
	local LevelInfo PL;
	PRI = PlayerOwner().PlayerReplicationInfo;
	PL = PlayerOwner().Level;
	if (PRI == None)
	{
		return;
	}
	Grade = PlayerOwner().iRifleRangeRating;
	if (AAGUIController(Controller).bLoggedIn)
	{
		lXPLabel.Caption = "XP / HONOR (Multiplayer/Co-Op): " $ string(PRI.GetHonor());
		lTogo.Caption = "XP Required for next HONOR: " $ string(CalculateExperienceNeeded(PRI.GetExperience(), PRI.GetHonor()));
		iRifleQualification = RifleQualification();
		iExpertInfantryQualification = EIBQualification();
		iDriverQualification = DriverQualification();
		iCombatMedicQualification = MedicQualification();
		iAirborneQualification = AirborneQualification();
		iSFQualification = SFQualification();
	}
	else
	{
		lXPLabel.Caption = "Please log in to view your badges.";
		lTogo.Caption = "";
		iRifleQualification = 0;
		iExpertInfantryQualification = 0;
		iDriverQualification = 0;
		iCombatMedicQualification = 0;
		iAirborneQualification = 0;
		iSFQualification = 0;
	}
	CreateBadges();
	*/
}

int32 UAARecordBrief_Badges::RifleQualification()
{
	/*
	int32 Grade = 0;
	if (AAGUIController(Controller).bLoggedIn)
	{
		Grade = PlayerOwner().iRifleRangeRating;
		if ((Grade >= 24) && (Grade <= 28))
		{
			return 2;
		}
		else
		{
			if ((Grade >= 29) && (Grade <= 35))
			{
				return 3;
			}
			else
			{
				if ((Grade >= 36) && (Grade <= 40))
				{
					return 4;
				}
			}
		}
		if (Grade < 24)
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}
	*/
	return 1;   //FAKE    /ELiZ
}

int32 UAARecordBrief_Badges::BCTQualification()
{
	/*
	if (AAGUIController(Controller).bLoggedIn)
	{
		if ((PlayerOwner().iCompleted[1] & 15) == 15)
		{
			return 2;
		}
		else
		{
			if (PlayerOwner().Level.CanPlayerPlayMissionPrivate(PlayerOwner(), 0, 0))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}
	*/
	return 1;   //FAKE    /ELiZ
}

int32 UAARecordBrief_Badges::AdvMarksmanQualification()
{
	/*
	if (AAGUIController(Controller).bLoggedIn)
	{
		if (PlayerOwner().iCompleted[5] > 0)
		{
			return 2;
		}
		else
		{
			if (PlayerOwner().Level.CanPlayerPlayMissionPrivate(PlayerOwner(), 4, 0))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}
	*/
	return 1;   //FAKE    /ELiZ
}

int32 UAARecordBrief_Badges::EIBQualification()
{
	/*
	if (AAGUIController(Controller).bLoggedIn)
	{
		if ((PlayerOwner().iCompleted[14] & 1) == 1)
		{
			return 2;
		}
		else
		{
			if (PlayerOwner().Level.CanPlayerPlayMissionPrivate(PlayerOwner(), 13, 0))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}
	*/
	return 1;   //FAKE    /ELiZ
}

int32 UAARecordBrief_Badges::DriverQualification()
{
	/*
	if (AAGUIController(Controller).bLoggedIn)
	{
		if ((PlayerOwner().iCompleted[14] & 6) == 6)
		{
			return 2;
		}
		else
		{
			if (PlayerOwner().Level.CanPlayerPlayMissionPrivate(PlayerOwner(), 13, 1))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}
	*/
	return 1;   //FAKE    /ELiZ
}

int32 UAARecordBrief_Badges::MedicQualification()
{
	/*
	if (AAGUIController(Controller).bLoggedIn)
	{
		if (PlayerOwner().iCompleted[10] == 15)
		{
			return 2;
		}
		else
		{
			if (PlayerOwner().Level.CanPlayerPlayMissionPrivate(PlayerOwner(), 9, 0))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}
	*/
	return 1;   //FAKE    /ELiZ
}

int32 UAARecordBrief_Badges::AirborneQualification()
{
	/*
	if (AAGUIController(Controller).bLoggedIn)
	{
		if (PlayerOwner().iCompleted[6] == 3)
		{
			return 2;
		}
		else
		{
			if (PlayerOwner().Level.CanPlayerPlayMissionPrivate(PlayerOwner(), 5, 0))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}
	*/
	return 1;   //FAKE    /ELiZ
}

int32 UAARecordBrief_Badges::SFQualification()
{
	/*
	if (AAGUIController(Controller).bLoggedIn)
	{
		if (PlayerOwner().iCompleted[11] == 3)
		{
			return 2;
		}
		else
		{
			if (PlayerOwner().Level.CanPlayerPlayMissionPrivate(PlayerOwner(), 10, 0))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}
	*/
	return 1;   //FAKE    /ELiZ
}

void UAARecordBrief_Badges::CreateBadges()
{
	/*
	FString sTextureName = "";
	FString sCaption = "";
	local PlayerReplicationInfo PRI;
	PRI = PlayerOwner().PlayerReplicationInfo;
	if (PRI == None)
	{
		return;
	}
	switch (iRifleQualification)
	{
	case 0:
		sTextureName = "T_AAO_UI.RecordBrief.t_ui_badges_sharpshooter_gray";
		sCaption = "Rifle Marksmanship (BRM)|Not Available";
		break;
	case 1:
		sTextureName = "T_AAO_UI.RecordBrief.t_ui_badges_sharpshooter_green";
		sCaption = "Rifle Marksmanship (BRM)|Training Available";
		break;
	case 2:
		sTextureName = "T_AAO_UI.RecordBrief.t_ui_badges_marksman_rifle_metal";
		sCaption = "Marksman Badge|Qualified";
		break;
	case 3:
		sTextureName = "T_AAO_UI.RecordBrief.t_ui_badges_sharpshooter_rifle_metal";
		sCaption = "Sharpshooter Badge|Qualified";
		break;
	case 4:
		sTextureName = "T_AAO_UI.RecordBrief.t_ui_badges_expert_rifle_metal";
		sCaption = "Expert Badge|Qualified";
		break;
	default:
		break;
	}
	ibRifleBadge.Image = Texture(DynamicLoadObject(sTextureName, Class'Texture'));
	lRifleLabel.Caption = sCaption;
	switch (iExpertInfantryQualification)
	{
	case 0:
		sTextureName = "T_AAO_UI.RecordBrief.t_ui_badges_eib_gray";
		sCaption = "Advanced Infantry (Javelin)|Not Available";
		break;
	case 1:
		sTextureName = "T_AAO_UI.RecordBrief.t_ui_badges_eib_green";
		sCaption = "Advanced Infantry (Javelin)|Training Available";
		break;
	case 2:
		sTextureName = "T_AAO_UI.RecordBrief.t_ui_badges_eib_metal";
		sCaption = "Expert Infantryman Badge (EIB)|Qualified";
		break;
	default:
		break;
	}
	ibExpertInfantryBadge.Image = Texture(DynamicLoadObject(sTextureName, Class'Texture'));
	lExpertInfantryLabel.Caption = sCaption;
	switch (iDriverQualification)
	{
	case 0:
		sTextureName = "T_AAO_UI.RecordBrief.t_ui_badges_driver_gray";
		sCaption = "CROWS HMMWV Driving/Gunnery|Not Available";
		break;
	case 1:
		sTextureName = "T_AAO_UI.RecordBrief.t_ui_badges_driver_green";
		sCaption = "CROWS HMMWV Driving/Gunnery|Training Available";
		break;
	case 2:
		sTextureName = "T_AAO_UI.RecordBrief.t_ui_badges_driver_metal";
		sCaption = "Expert Driver Badge|Qualified";
		break;
	default:
		break;
	}
	ibDriverBadge.Image = Texture(DynamicLoadObject(sTextureName, Class'Texture'));
	lDriverLabel.Caption = sCaption;
	switch (iCombatMedicQualification)
	{
	case 0:
		sTextureName = "T_AAO_UI.RecordBrief.t_ui_badges_medic_gray";
		sCaption = "Expert Field Medic|Not Available";
		break;
	case 1:
		sTextureName = "T_AAO_UI.RecordBrief.t_ui_badges_medic_green";
		sCaption = "Expert Field Medic|Training Available";
		break;
	case 2:
		sTextureName = "T_AAO_UI.RecordBrief.t_ui_badges_medic_metal";
		sCaption = "Expert Field Medical Badge|Qualified";
		break;
	default:
		break;
	}
	ibCombatMedicBadge.Image = Texture(DynamicLoadObject(sTextureName, Class'Texture'));
	lCombatMedicLabel.Caption = sCaption;
	switch (iAirborneQualification)
	{
	case 0:
		sTextureName = "T_AAO_UI.RecordBrief.t_ui_badges_airborne_gray";
		sCaption = "Airborne School|Not Available";
		break;
	case 1:
		sTextureName = "T_AAO_UI.RecordBrief.t_ui_badges_airborne_green";
		sCaption = "Airborne School|Training Available";
		break;
	case 2:
		sTextureName = "T_AAO_UI.RecordBrief.t_ui_badges_airborne_metal";
		sCaption = "Airborne Jump Wings|Qualified";
		break;
	default:
		break;
	}
	ibAirborneBadge.Image = Texture(DynamicLoadObject(sTextureName, Class'Texture'));
	lAirborneLabel.Caption = sCaption;
	switch (iSFQualification)
	{
	case 0:
		sTextureName = "T_AAO_UI.RecordBrief.t_ui_badges_sfcrest_gray";
		sCaption = "Special Forces|Not Available";
		break;
	case 1:
		sTextureName = "T_AAO_UI.RecordBrief.t_ui_badges_sfcrest_green";
		sCaption = "Special Forces|Training Available";
		break;
	case 2:
		sTextureName = "T_AAO_UI.RecordBrief.t_ui_badges_sfcrest_metal";
		sCaption = "SF Regimental Crest|Qualified";
		break;
	default:
		break;
	}
	ibSFBadge.Image = Texture(DynamicLoadObject(sTextureName, Class'Texture'));
	lSFLabel.Caption = sCaption;
	*/
}

bool UAARecordBrief_Badges::BadgeClick(UGUIComponent* Sender)
{
	/*
	local AAMainMenu aamm;
	local AATrainingPanel aatp;
	local AATraining_Details aatd;
	int32 NewComboBoxIndex = 0;
	FString TrainingName = "";
	int32 TourID = 0;
	int32 MissionID = 0;
	switch (Sender)
	{
	case ibRifleBadge:
		TourID = 0;
		MissionID = 0;
		break;
	case ibCombatMedicBadge:
		TourID = 9;
		MissionID = 0;
		break;
	case ibAirborneBadge:
		TourID = 5;
		MissionID = 0;
		break;
	case ibDriverBadge:
		TourID = 13;
		MissionID = 1;
		break;
	case ibExpertInfantryBadge:
		TourID = 13;
		MissionID = 0;
		break;
	case ibSFBadge:
		TourID = 10;
		MissionID = 0;
		break;
	default:
	}
	TrainingName = PlayerOwner().Level.GetTourMissionTitle(TourID, MissionID);
	aamm = AAMainMenu(PageOwner);
	if (aamm != None)
	{
		aatp = AATrainingPanel(aamm.c_Tab.BorrowPanel("TRAINING"));
		if (aatp != None)
		{
			aatp.c_Tabs.ActivateTabByName("Details", true);
			aatd = AATraining_Details(aatp.c_Tabs.BorrowPanel("Details"));
			NewComboBoxIndex = aatd.co_Tour.FindIndex(TrainingName, false);
			if (NewComboBoxIndex >= 0)
			{
				aatd.co_Tour.SetIndex(NewComboBoxIndex);
			}
			if (aatd != None)
			{
				SetFocus(aatd);
				Controller.ReplaceMenu("AGP_Interface.AAMainMenu", "TRAINING");
			}
		}
	}
	*/
	return false;
}