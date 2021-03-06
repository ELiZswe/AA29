// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_Map/AAGameMenu_Map.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImageButton/GUIImageButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/BaseObjective.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"

UAAGameMenu_Map::UAAGameMenu_Map()
{
	UGUIImageButton* MapImage = NewObject<UGUIImageButton>(UGUIImageButton::StaticClass());
	MapImage->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Maps/Overhead/NoImage_Mat.NoImage_Mat'"), NULL, LOAD_None, NULL);
	MapImage->ImageStyle = EImgStyle::ISTY_Scaled;
	MapImage->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MapImage->WinTop = 0.06;
	MapImage->WinLeft = 0.06;
	MapImage->WinWidth = 0.7;
	MapImage->WinHeight = 0.7;
	//MapImage->OnClick=AAGameMenu_Map.ObjectivesClick;
	//MapImage->OnKeyEvent=MapImage.InternalOnKeyEvent;
	UGUIScrollTextBox* ObjectivesList = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	ObjectivesList->CharDelay = 0.0025;
	ObjectivesList->EOLDelay = 0.5;
	ObjectivesList->TextAlign = EeTextAlign::TXTA_Right;
	//ObjectivesList->OnCreateComponent=ObjectivesList.InternalOnCreateComponent;
	ObjectivesList->StyleName = "SmallText";
	ObjectivesList->WinTop = 0.1;
	ObjectivesList->WinLeft = 0.82;
	ObjectivesList->WinWidth = 0.15;
	ObjectivesList->WinHeight = 0.7;
	ObjectivesList->TabOrder = 1;
	ObjectivesList->bBoundToParent = true;
	UGUIImage* MyBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MyBackground->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/backgroundfill_Mat.backgroundfill_Mat'"), NULL, LOAD_None, NULL);
	MyBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	MyBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MyBackground->WinTop = 0.01;
	MyBackground->WinLeft = 0.01;
	MyBackground->WinWidth = 0.98;
	MyBackground->WinHeight = 0.89;
	MyBackground->RenderWeight = 0;
	MyBackground->bBoundToParent = true;
	MyBackground->bScaleToParent = true;
	UGUIImage* BG1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	BG1->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);
	BG1->ImageStyle = EImgStyle::ISTY_Stretched;
	BG1->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	BG1->WinTop = 0.02;
	BG1->WinLeft = 0.02;
	BG1->WinWidth = 0.96;
	BG1->WinHeight = 0.87;
	UGUILabel* ObjectivesLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	ObjectivesLabel->Caption = "Objectives";
	ObjectivesLabel->TextAlign = ETextAlign::TXTA_Right;
	ObjectivesLabel->TextColor = FColor(52, 180, 217, 255);
	ObjectivesLabel->TextFont = "AAFontMedium";
	ObjectivesLabel->WinTop = 0.04;
	ObjectivesLabel->WinLeft = 0.82;
	ObjectivesLabel->WinWidth = 0.15;
	UGUILabel* AuthorNameLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	AuthorNameLabel->Caption = "Map created by US Army";
	AuthorNameLabel->TextColor = FColor(128, 128, 128, 255);
	AuthorNameLabel->TextFont = "AAFontMedium";
	AuthorNameLabel->WinTop = 0.84;
	AuthorNameLabel->WinLeft = 0.03;
	AuthorNameLabel->WinWidth = 0.4;
	i_Background = MyBackground;
	i_Objectives = BG1;
	i_Map = MapImage;
	l_Objectives = ObjectivesLabel;
	l_AuthorName = AuthorNameLabel;
	sb_ObjectivesList = ObjectivesList;
}

void UAAGameMenu_Map::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	//__OnRendered__Delegate = OnDrawMapGrid;
	InitializeMap();
	InitializeObjectives();
}

bool UAAGameMenu_Map::NotifyLevelChange()
{
	InitializeMap();
	InitializeObjectives();
	return true;
}

void UAAGameMenu_Map::InitializeMap()
{
	/*
	if (Len(PlayerOwner().Level.Author) > 0)
	{
		l_AuthorName.Caption = "Map Created By " + PlayerOwner().Level.Author;
	}
	else
	{
		l_AuthorName.Caption = "Map Created By AAPA";
	}
	ScalingMapImage = new () Class'TexScaler';
	ScalingMapImage.Material = PlayerOwner().Level.RadarMapImage;
	ScalingMapImage.UScale = 1;
	ScalingMapImage.VScale = 1;
	ScalingMapImage.UOffset = 0;
	ScalingMapImage.VOffset = 0;
	RotatingMapImage = new () Class'TexRotator';
	RotatingMapImage.Material = ScalingMapImage;
	RotatingMapImage.TexRotationType = 0;
	RotatingMapImage.Rotation = FRotator(0 16384 0);
	RotatingMapImage.UOffset = ScalingMapImage.Material.MaterialUSize() / 2;
	RotatingMapImage.VOffset = ScalingMapImage.Material.MaterialVSize() / 2;
	RotatingMapImage.OscillationRate = FRotator(0 0 0);
	RotatingMapImage.OscillationAmplitude = FRotator(0 0 0);
	RotatingMapImage.OscillationPhase = FRotator(0 0 0);
	i_Map.Image = RotatingMapImage;
	*/
}

void UAAGameMenu_Map::InitializeObjectives()
{
	ABaseObjective* obj = nullptr;
	FString Objectives = "";
	FString ObjectiveDescription = "";
	/*
	if (PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == 255)
	{
		return;
	}
	ForEach PlayerOwner().DynamicActors(ABaseObjective::StaticClass(), obj)
	{
		if (obj->IsA(AAGP_Objective::StaticClass()))
		{
			ObjectiveDescription = obj.GetDescriptionByController(PlayerOwner());
			if (ObjectiveDescription != "")
			{
				if (Objectives != "")
				{
					Objectives += "||";
				}
				Objectives += ObjectiveDescription;
			}
		}
	}
	sb_ObjectivesList.SetContent(Objectives);
	*/
}

bool UAAGameMenu_Map::ObjectivesClick(UGUIComponent* Sender)
{
	//if (Sender == i_Map)
	//{
	//}
	return true;
}

void UAAGameMenu_Map::OnDrawMapGrid(UCanvas* Canvas)
{
	FColor colorGridLine = FColor(0,0,0,0);
	int32 i = 0;
	float fpMapScaleX = 0;
	float fpMapScaleY = 0;
	float fpMapStartX = 0;
	float fpMapStartY = 0;
	float fpMapHeight = 0;
	float fpMapWidth = 0;
	float fpMapCenterX = 0;
	float fpMapCenterY = 0;
	/*
	fpMapStartX = i_Map.WinLeft * Canvas.SizeX;
	fpMapStartY = i_Map.WinTop * Canvas.SizeY + 0.05 * Canvas.SizeY;
	fpMapHeight = i_Map.iScreenBottom - i_Map.iScreenTop;
	fpMapWidth = i_Map.iScreenRight - i_Map.iScreenLeft;
	fpMapCenterX = PlayerOwner().Level.RadarMapOffset.X - PlayerOwner().Level.RadarMapSize / 2;
	fpMapCenterY = PlayerOwner().Level.RadarMapOffset.Y - PlayerOwner().Level.RadarMapSize / 2;
	fpMapScaleY = fpMapHeight / 100;
	fpMapScaleX = fpMapWidth / 100;
	Canvas.SetDrawColor(255, 255, 255, 192);
	Canvas.SetPos(fpMapStartX, fpMapStartY);
	Canvas.DrawHorizontal(fpMapStartY, fpMapWidth);
	Canvas.DrawHorizontal(fpMapStartY + fpMapHeight, fpMapWidth);
	Canvas.DrawVertical(fpMapStartX, fpMapHeight);
	Canvas.DrawVertical(fpMapStartX + fpMapWidth, fpMapHeight);
	colorGridLine = Class'Canvas'.MakeColor(255, 255, 255);
	i = 10;
	if (i <= 90)
	{
		if (i * fpMapScaleY > i_Map.Image.MaterialVSize())
		{
		}
		Canvas.SetDrawColor(128, 128, 128, 64);
		Canvas.SetPos(fpMapStartX, fpMapStartY + i * fpMapScaleY);
		Canvas.DrawHorizontal(fpMapStartY + i * fpMapScaleY, fpMapWidth);
		Canvas.SetDrawColor(255, 255, 255);
		Canvas.SetPos(fpMapStartX - 25, fpMapStartY + i * fpMapScaleY - 5);
		Canvas.DrawText("" + Cast<AHumanController>(PlayerOwner())->GameReplicationInfo.iSpotterBaseGridY + 100 - i);
		Canvas.SetPos(fpMapStartX + fpMapWidth + 4, fpMapStartY + i * fpMapScaleY - 5);
		Canvas.DrawText("" + Cast<AHumanController>(PlayerOwner())->GameReplicationInfo.iSpotterBaseGridY + 100 - i);
		Canvas.SetDrawColor(128, 128, 128, 64);
		Canvas.SetPos(fpMapStartX + i * fpMapScaleX, fpMapStartY);
		Canvas.DrawVertical(fpMapStartX + i * fpMapScaleX, fpMapHeight);
		Canvas.SetDrawColor(255, 255, 255);
		Canvas.SetPos(fpMapStartX + i * fpMapScaleX - 5, fpMapStartY - 15);
		Canvas.DrawText("" + Cast<AHumanController>(PlayerOwner())->GameReplicationInfo.iSpotterBaseGridX + i);
		Canvas.SetPos(fpMapStartX + i * fpMapScaleX - 5, fpMapStartY + fpMapHeight + 2);
		Canvas.DrawText("" + Cast<AHumanController>(PlayerOwner())->GameReplicationInfo.iSpotterBaseGridX + i);
		i += 10;
	}
	*/
}
