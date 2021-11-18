// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/AARealHeroRibbonDisplay/AARealHeroRibbonDisplay.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAARealHeroRibbonDisplay::UAARealHeroRibbonDisplay()
{
	UGUIImage* RibbonImage = NewObject<UGUIImage>(UGUIImage::StaticClass());
	RibbonImage->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/backgroundfil_Mat.backgroundfil_Mat'"), NULL, LOAD_None, NULL);
	RibbonImage->ImageStyle = EImgStyle::ISTY_Scaled;
	RibbonImage->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	RibbonImage->RenderWeight = 0.5;
	RibbonImage->bBoundToParent = true;
	RibbonImage->bScaleToParent = true;
	UGUIButton* CloseButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	CloseButton->Caption = "Close";
	CloseButton->StyleName = "SquareMenuButton";
	CloseButton->Hint = "Close this window";
	CloseButton->WinTop = 0.9;
	CloseButton->WinLeft = 0.43;
	CloseButton->WinWidth = 0.14;
	CloseButton->WinHeight = 0.07;
	CloseButton->RenderWeight = 0.6;
	CloseButton->bBoundToParent = true;
	CloseButton->bScaleToParent = true;
	//CloseButton->OnClick=AARealHeroRibbonDisplay.InternalButtonClick;
	//CloseButton->OnKeyEvent=CloseButton.InternalOnKeyEvent;
	UGUILabel* HeaderLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	HeaderLabel->TextAlign = ETextAlign::TXTA_Center;
	HeaderLabel->TextColor = FColor(137, 185, 147, 255);
	HeaderLabel->TextFont = "AAFontMedium";
	HeaderLabel->WinTop = 0.04;
	HeaderLabel->WinHeight = 0.08;
	HeaderLabel->RenderWeight = 0.6;
	HeaderLabel->bBoundToParent = true;
	HeaderLabel->bScaleToParent = true;

	Ribbons = {
		FRibbon({ "Afghanistan Campaign", "Afghanistan Campaign", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_Afghanistan_Mat.T_UI_Uniform_Ribbon_Afghanistan_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({ "Afghanistan Campaign (ARROW)", "Afghanistan Campaign", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_Afghanistan_Arrow_Mat.T_UI_Uniform_Ribbon_Afghanistan_Arrow_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({ "Armed Forces Expeditionary", "Armed Forces Expeditionary", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_ArmedForcesExp_Mat.T_UI_Uniform_Ribbon_ArmedForcesExp_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({ "Armed Forces Service", "Armed Forces Service", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_ArmedForcesService_Mat.T_UI_Uniform_Ribbon_ArmedForcesService_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({ "Army Achievement", "Army Achievement", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_ArmyAchievement_Mat.T_UI_Uniform_Ribbon_ArmyAchievement_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({ "Army Achievement (1 OAK)", "Army Achievement", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_ArmyAchievement_1oak_Mat.T_UI_Uniform_Ribbon_ArmyAchievement_1oak_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({ "Army Achievement (1 SILVER OAK)", "Army Achievement", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_ArmyAchievement_1Soak_Mat.T_UI_Uniform_Ribbon_ArmyAchievement_1Soak_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({ "Army Achievement (3 OAK)", "Army Achievement", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_ArmyAchievement_3oak_Mat.T_UI_Uniform_Ribbon_ArmyAchievement_3oak_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"", "", nullptr}),
		FRibbon({"Army Commendation", "Army Commendation", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_ArmyCommendation_Mat.T_UI_Uniform_Ribbon_ArmyCommendation_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Army Commendation (2 OAK)", "Army Commendation", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_ArmyCommendation_2oak_Mat.T_UI_Uniform_Ribbon_ArmyCommendation_2oak_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Army Commendation (3 OAK)", "Army Commendation", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_ArmyCommendation_3oak_Mat.T_UI_Uniform_Ribbon_ArmyCommendation_3oak_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Army Commendation (VALOR)", "Army Commendation", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_ArmyCommendation_V_Mat.T_UI_Uniform_Ribbon_ArmyCommendation_V_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Army Commendation (VALOR, 1 OAK)", "Army Commendation", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_ArmyCommendation_V_1oak_Mat.T_UI_Uniform_Ribbon_ArmyCommendation_V_1oak_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Army Good Conduct", "Army Good Conduct", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_ArmyGoodConduct_Mat.T_UI_Uniform_Ribbon_ArmyGoodConduct_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Army Good Conduct (2 OAK)", "Army Good Conduct", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_ArmyGoodConduct_2oak_Mat.T_UI_Uniform_Ribbon_ArmyGoodConduct_2oak_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Army Service", "Army Service", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_ArmyService_Mat.T_UI_Uniform_Ribbon_ArmyService_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Bronze Star", "Bronze Star", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_BronzeStar_Mat.T_UI_Uniform_Ribbon_BronzeStar_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Bronze Star (VALOR)", "Bronze Star", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_BronzeStar_V_Mat.T_UI_Uniform_Ribbon_BronzeStar_V_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Meritorious Service", "Meritorious Service", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_DefenseMeritService_Mat.T_UI_Uniform_Ribbon_DefenseMeritService_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Global War on Terror Expeditionary", "Global War on Terror Expeditionary", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_GlobalWarTerrorExp_Mat.T_UI_Uniform_Ribbon_GlobalWarTerrorExp_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Global War on Terror Service", "Global War on Terror Service", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_GlobalWarTerrorServ_Mat.T_UI_Uniform_Ribbon_GlobalWarTerrorServ_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Good Conduct (BAR)", "Good Conduct", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_GoodConduct_Bar_Mat.T_UI_Uniform_Ribbon_GoodConduct_Bar_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Humanitarian Service", "Humanitarian Service", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_HumanitarianService_Mat.T_UI_Uniform_Ribbon_HumanitarianService_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Iraq Campaign", "Iraq Campaign", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_Iraq_Mat.T_UI_Uniform_Ribbon_Iraq_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Joint Service Achievement", "Joint Service Achievement", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_JointServiceAchievement_Mat.T_UI_Uniform_Ribbon_JointServiceAchievement_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Joint Service Commendation", "Joint Service Commendation", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_JointServiceCOM_Mat.T_UI_Uniform_Ribbon_JointServiceCOM_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Korean Service", "Korean Service", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_KoreanService_Mat.T_UI_Uniform_Ribbon_KoreanService_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Kosovo Campaign", "Kosovo Campaign", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_KosovoCampaign_Mat.T_UI_Uniform_Ribbon_KosovoCampaign_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Legion of Merit", "Legion of Merit", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_LegionMerit_Mat.T_UI_Uniform_Ribbon_LegionMerit_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Multinational Force & Observers", "Multinational Force & Observers", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_MultinationalForceOb_Mat.T_UI_Uniform_Ribbon_MultinationalForceOb_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"National Defense Service", "National Defense Service", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_NationalDefenseService_Mat.T_UI_Uniform_Ribbon_NationalDefenseService_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"National Defense Service (1 OAK)", "National Defense Service", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_NationalDefenseService_1oak_Mat.T_UI_Uniform_Ribbon_NationalDefenseService_1oak_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"National Defense Service (STAR)", "National Defense Service", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_NationalDefenseService_StarBronze_Mat.T_UI_Uniform_Ribbon_NationalDefenseService_StarBronze_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"NATO Kosovo", "NATO Kosovo", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_NATO_Kosovo_Mat.T_UI_Uniform_Ribbon_NATO_Kosovo_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"NCO Professional Development", "NCO Professional Development", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_NCOProfDev_Mat.T_UI_Uniform_Ribbon_NCOProfDev_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"", "", nullptr}),
		FRibbon({"NCO Professional Development (3)", "NCO Professional Development", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_NCOProfDev_three_Mat.T_UI_Uniform_Ribbon_NCOProfDev_three_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Overseas Service", "Overseas Service", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_OverseasService_Mat.T_UI_Uniform_Ribbon_OverseasService_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Overseas Service (TWO)", "Overseas Service", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_OverseasService_two_Mat.T_UI_Uniform_Ribbon_OverseasService_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Purple Heart", "Purple Heart", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_PurpleHeart_Mat.T_UI_Uniform_Ribbon_PurpleHeart_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Reserve Components Overseas Training (TWO)", "Reserve Components Overseas Training", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_ReserveComponents_OverseasTraining_two_Mat.T_UI_Uniform_Ribbon_ReserveComponents_OverseasTraining_two_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Silver Star", "Silver Star", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_SilverStar_Mat.T_UI_Uniform_Ribbon_SilverStar_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Southwest Asia Service", "Southwest Asia Service", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_SouthwestAsia_Mat.T_UI_Uniform_Ribbon_SouthwestAsia_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"State Emergency (2 OAK)", "State Emergency", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_StateEmergency_2oaks_Mat.T_UI_Uniform_Ribbon_StateEmergency_2oaks_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"United Nations", "United Nations", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_UnitedNations_Mat.T_UI_Uniform_Ribbon_UnitedNations_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"United Nations Haiti", "United Nations Haiti", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_UN_Haiti_Mat.T_UI_Uniform_Ribbon_UN_Haiti_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Army Reserve Components Achievement", "Army Reserve Components Achievement", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_ReserveComponents_Achievement_Mat.T_UI_Uniform_Ribbon_ReserveComponents_Achievement_Mat'"), NULL, LOAD_None, NULL)}),
		FRibbon({"Korean Defense Service", "Korean Defense Service", LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Uniform/T_UI_Uniform_Ribbon_KoreanDefenseService_Mat.T_UI_Uniform_Ribbon_KoreanDefenseService_Mat'"), NULL, LOAD_None, NULL)})
	};

	i_MyRibbons = { RibbonImage,RibbonImage,RibbonImage,RibbonImage,RibbonImage,RibbonImage,RibbonImage,RibbonImage,RibbonImage,RibbonImage,RibbonImage,RibbonImage,RibbonImage,RibbonImage,RibbonImage,RibbonImage };
	b_Close = CloseButton;
	l_Header = HeaderLabel;
	RibbonSpacingX = 0.05;
	RibbonSpacingY = 0.025;
	RibbonStartY = 0.13;
	RibbonWidth = 0.26;
	RibbonHeight = 0.13;
	RibbonHeaderText = "Ribbon Display for %RealHeroName%";
	//OnOpen = AARealHeroRibbonDisplay.InternalOnOpen;
	WinTop = 0.1;
	WinLeft = 0.13;
	WinWidth = 0.74;
	WinHeight = 0.8;
}

void UAARealHeroRibbonDisplay::HandleParameters(FString Param1, FString Param2)
{
	/*
	MyRealHeroStatsClass = class<AARealHeroStats>(DynamicLoadObject(Param1, Class'Class'));
	l_Header.Caption = Repl(RibbonHeaderText, "%RealHeroName%", MyRealHeroStatsClass.Default.HeroNameAndRank);
	*/
}

int32 UAARealHeroRibbonDisplay::FindRibbonIndex(FString RibbonToFind)
{
	/*
	int32 i = 0;
	for (i = 0; i < Ribbons.Length; i++)
	{
		if (RibbonToFind == Ribbons[i].RibbonName)
		{
			return i;
		}
	}
	*/
	return -1;
}

void UAARealHeroRibbonDisplay::InternalOnOpen()
{
	/*
	int32 i = 0;
	int32 j = 0;
	int32 RibbonCount = 0;
	int32 RowRibbonCount = 0;
	int32 TempRibbonIndex = 0;
	float XL = 0;
	float YL = 0;
	float LocalWinWidth = 0;
	YL = RibbonStartY;
	for (i = 0; i < MyRealHeroStatsClass.Default.RibbonRows.Length; i++)
	{
		RowRibbonCount = 0;
		for (TempRibbonIndex = FindRibbonIndex(MyRealHeroStatsClass.Default.RibbonRows[i].RibbonName1); TempRibbonIndex >= 0; i_MyRibbons[(RibbonCount + )
		{
			i_MyRibbons[(RibbonCount + RowRibbonCount)].Image = Ribbons[TempRibbonIndex].RibbonImage;
		}
		for (TempRibbonIndex = FindRibbonIndex(MyRealHeroStatsClass.Default.RibbonRows[i].RibbonName2); TempRibbonIndex >= 0; i_MyRibbons[(RibbonCount + )
		{
			i_MyRibbons[(RibbonCount + RowRibbonCount)].Image = Ribbons[TempRibbonIndex].RibbonImage;
		}
		for (TempRibbonIndex = FindRibbonIndex(MyRealHeroStatsClass.Default.RibbonRows[i].RibbonName3); TempRibbonIndex >= 0; i_MyRibbons[(RibbonCount + )
		{
			i_MyRibbons[(RibbonCount + RowRibbonCount)].Image = Ribbons[TempRibbonIndex].RibbonImage;
		}
		LocalWinWidth = (RibbonWidth / (ActualWidth() / ActualHeight()));
			XL = (0.5 - (((float(RowRibbonCount) * LocalWinWidth) + (float((RowRibbonCount - 1)) * RibbonSpacingX)) / 2));
			for (j = 0; j < RowRibbonCount; j++)
			{
				i_MyRibbons[(RibbonCount + j)].WinWidth = LocalWinWidth;
					i_MyRibbons[(RibbonCount + j)].WinHeight = RibbonHeight;
					i_MyRibbons[(RibbonCount + j)].WinLeft = XL;
					i_MyRibbons[(RibbonCount + j)].WinTop = YL;
				XL += (LocalWinWidth + RibbonSpacingX);
			}
		YL += (RibbonHeight + RibbonSpacingY);
		RibbonCount += RowRibbonCount;
	}
	for (i = RibbonCount; i < 16; i++)
	{
		i_MyRibbons[i].bVisible = false;
	}
	*/
}

bool UAARealHeroRibbonDisplay::InternalButtonClick(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case b_Close:
		Controller.CloseMenu();
		return true;
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}