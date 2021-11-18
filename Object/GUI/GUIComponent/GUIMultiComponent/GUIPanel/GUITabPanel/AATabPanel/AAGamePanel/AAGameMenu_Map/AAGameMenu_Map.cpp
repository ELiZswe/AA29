// All the original content belonged to the US Army

#include "AAGameMenu_Map.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImageButton/GUIImageButton.h"


UAAGameMenu_Map::UAAGameMenu_Map()
{
	/*
	Begin Object Class=GUIImageButton Name=MapImage
		Image=Texture'T_AA2_Maps.Overhead.NoImage'
		ImageStyle=ISTY_Scaled
		ImageRenderStyle=1
		WinTop=0.06
		WinLeft=0.06
		WinWidth=0.7
		WinHeight=0.7
		OnClick=AAGameMenu_Map.ObjectivesClick
		OnKeyEvent=MapImage.InternalOnKeyEvent
	End Object
	Begin Object Class=GUIScrollTextBox Name=ObjectivesList
		CharDelay=0.0025
		EOLDelay=0.5
		TextAlign=2
		OnCreateComponent=ObjectivesList.InternalOnCreateComponent
		StyleName="SmallText"
		WinTop=0.1
		WinLeft=0.82
		WinWidth=0.15
		WinHeight=0.7
		TabOrder=1
		bBoundToParent=True
	End Object
	Begin Object Class=GUIImage Name=MyBackground
		Image=Texture'T_AA2_UI.Menu.backgroundfill'
		ImageStyle=ISTY_Stretched
		ImageRenderStyle=1
		WinTop=0.01
		WinLeft=0.01
		WinWidth=0.98
		WinHeight=0.89
		RenderWeight=0
		bBoundToParent=True
		bScaleToParent=True
	End Object
	Begin Object Class=GUIImage Name=BG1
		Image=Texture'T_AA2_UI.Menu.field_translucent'
		ImageStyle=ISTY_Stretched
		ImageRenderStyle=1
		WinTop=0.02
		WinLeft=0.02
		WinWidth=0.96
		WinHeight=0.87
	End Object
	Begin Object Class=GUILabel Name=ObjectivesLabel
		Caption="Objectives"
		TextAlign=2
		TextColor=(R=52,G=180,B=217,A=255)
		TextFont="AAFontMedium"
		WinTop=0.04
		WinLeft=0.82
		WinWidth=0.15
	End Object
	Begin Object Class=GUILabel Name=AuthorNameLabel
		Caption="Map created by US Army"
		TextColor=(R=128,G=128,B=128,A=255)
		TextFont="AAFontMedium"
		WinTop=0.84
		WinLeft=0.03
		WinWidth=0.4
	End Object
*/
	//i_Background = GUIImage'AGP_Interface.AAGameMenu_Map.MyBackground';
	//i_Objectives = GUIImage'AGP_Interface.AAGameMenu_Map.BG1';
	//i_Map = GUIImageButton'AGP_Interface.AAGameMenu_Map.MapImage';
	//l_Objectives = GUILabel'AGP_Interface.AAGameMenu_Map.ObjectivesLabel';
	//l_AuthorName = GUILabel'AGP_Interface.AAGameMenu_Map.AuthorNameLabel';
	//sb_ObjectivesList = GUIScrollTextBox'AGP_Interface.AAGameMenu_Map.ObjectivesList';
}

void UAAGameMenu_Map::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	__OnRendered__Delegate = OnDrawMapGrid;
	InitializeMap();
	InitializeObjectives();
	*/
}

bool UAAGameMenu_Map::NotifyLevelChange()
{
	/*
	InitializeMap();
	InitializeObjectives();
	*/
	return true;
}

void UAAGameMenu_Map::InitializeMap()
{
	/*
	if (Len(PlayerOwner().Level.Author) > 0)
	{
		l_AuthorName.Caption = "Map Created By " $ PlayerOwner().Level.Author;
	}
	else
	{
		l_AuthorName.Caption = "Map Created By AAPA";
	}
	ScalingMapImage = new () classClass'TexScaler';
	ScalingMapImage.Material = PlayerOwner().Level.RadarMapImage;
	ScalingMapImage.UScale = 1;
	ScalingMapImage.VScale = 1;
	ScalingMapImage.UOffset = 0;
	ScalingMapImage.VOffset = 0;
	RotatingMapImage = new () classClass'TexRotator';
	RotatingMapImage.Material = ScalingMapImage;
	RotatingMapImage.TexRotationType = 0;
	RotatingMapImage.Rotation = rot(0 16384 0);
	RotatingMapImage.UOffset = ScalingMapImage.Material.MaterialUSize() / 2;
	RotatingMapImage.VOffset = ScalingMapImage.Material.MaterialVSize() / 2;
	RotatingMapImage.OscillationRate = rot(0 0 0);
	RotatingMapImage.OscillationAmplitude = rot(0 0 0);
	RotatingMapImage.OscillationPhase = rot(0 0 0);
	i_Map.Image = RotatingMapImage;
	*/
}

void UAAGameMenu_Map::InitializeObjectives()
{
	/*
	local BaseObjective obj;
	local string Objectives;
	local string ObjectiveDescription;
	if (PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == 255)
	{
		Return;
	}
	ForEach PlayerOwner().DynamicActors(Class'BaseObjective', obj)
	{
		if (obj.IsA('AGP_Objective'))
		{
			ObjectiveDescription = obj.GetDescriptionByController(PlayerOwner());
			if (ObjectiveDescription != "")
			{
				if (Objectives != "")
				{
					Objectives $ = "||";
				}
				Objectives $ = ObjectiveDescription;
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
	/*
	local Object.Color colorGridLine;
	local int i;
	local float fpMapScaleX;
	local float fpMapScaleY;
	local float fpMapStartX;
	local float fpMapStartY;
	local float fpMapHeight;
	local float fpMapWidth;
	local float fpMapCenterX;
	local float fpMapCenterY;
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
		Canvas.DrawText("" $ HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridY + 100 - i);
		Canvas.SetPos(fpMapStartX + fpMapWidth + 4, fpMapStartY + i * fpMapScaleY - 5);
		Canvas.DrawText("" $ HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridY + 100 - i);
		Canvas.SetDrawColor(128, 128, 128, 64);
		Canvas.SetPos(fpMapStartX + i * fpMapScaleX, fpMapStartY);
		Canvas.DrawVertical(fpMapStartX + i * fpMapScaleX, fpMapHeight);
		Canvas.SetDrawColor(255, 255, 255);
		Canvas.SetPos(fpMapStartX + i * fpMapScaleX - 5, fpMapStartY - 15);
		Canvas.DrawText("" $ HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridX + i);
		Canvas.SetPos(fpMapStartX + i * fpMapScaleX - 5, fpMapStartY + fpMapHeight + 2);
		Canvas.DrawText("" $ HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridX + i);
		i += 10;
	}
	*/
}