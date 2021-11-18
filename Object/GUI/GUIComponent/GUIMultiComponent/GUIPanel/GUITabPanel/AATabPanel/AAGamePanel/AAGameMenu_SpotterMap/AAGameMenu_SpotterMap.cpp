// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_SpotterMap/AAGameMenu_SpotterMap.h"

UAAGameMenu_SpotterMap::UAAGameMenu_SpotterMap()
{
	/*
	Begin Object Class=GUIImageButton Name=MapImage
		Image=Texture'T_AA2_Maps.Overhead.NoImage'
		ImageStyle=ISTY_Scaled
		ImageRenderStyle=1
		WinTop=0.05
		WinLeft=0.05
		WinWidth=0.675
		WinHeight=0.75
		OnKeyEvent=MapImage.InternalOnKeyEvent
	End Object
	Begin Object Class=moNumericEdit Name=SpotterGridXNumericEditBox
		CaptionWidth=0.45
		Caption="Target X:"
		OnCreateComponent=SpotterGridXNumericEditBox.InternalOnCreateComponent
		IniOption="@Internal"
		Hint="Enter the target grid location."
		WinTop=0.15
		WinLeft=0.76
		WinWidth=0.22
		WinHeight=0.06
		TabOrder=2
		bStandardized=False
		OnChange=AAGameMenu_SpotterMap.InternalOnChange
	End Object
	Begin Object Class=moNumericEdit Name=SpotterGridYNumericEditBox
		CaptionWidth=0.45
		Caption="Target Y:"
		OnCreateComponent=SpotterGridYNumericEditBox.InternalOnCreateComponent
		IniOption="@Internal"
		Hint="Enter the target grid location."
		WinTop=0.23
		WinLeft=0.76
		WinWidth=0.22
		WinHeight=0.06
		TabOrder=2
		bStandardized=False
		OnChange=AAGameMenu_SpotterMap.InternalOnChange
	End Object
	Begin Object Class=moComboBox Name=MissionTypeComboBox
		bReadOnly=True
		CaptionWidth=0.4
		Caption="Mission:"
		OnCreateComponent=MissionTypeComboBox.InternalOnCreateComponent
		IniOption="@Internal"
		StyleName="STY_AAComboListBox"
		Hint="Select the type of mission you would like to call in."
		WinTop=0.31
		WinLeft=0.76
		WinWidth=0.22
		WinHeight=0.06
		TabOrder=8
		bStandardized=False
		OnChange=AAGameMenu_SpotterMap.InternalOnChange
	End Object
	Begin Object Class=moComboBox Name=TargetTypeComboBox
		bReadOnly=True
		CaptionWidth=0.4
		Caption="TGT-Type:"
		OnCreateComponent=TargetTypeComboBox.InternalOnCreateComponent
		IniOption="@Internal"
		StyleName="STY_AAComboListBox"
		Hint="Select the type of target."
		WinTop=0.38
		WinLeft=0.76
		WinWidth=0.22
		WinHeight=0.06
		TabOrder=8
		bStandardized=False
		OnChange=AAGameMenu_SpotterMap.InternalOnChange
	End Object
	Begin Object Class=GUIButton Name=GridFireMissionButton
		Caption="Call For Fire"
		MenuState=4
		StyleName="SquareMenuButton"
		Hint="Click here to make call for fire using entered grid reference."
		WinTop=0.46
		WinLeft=0.76
		WinWidth=0.15
		WinHeight=0.06
		TabOrder=14
		OnClick=AAGameMenu_SpotterMap.ButtonClick
		OnKeyEvent=GridFireMissionButton.InternalOnKeyEvent
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
	Begin Object Class=GUILabel Name=TitleLabel
		Caption="Reference Chart"
		TextAlign=1
		TextColor=(R=52,G=180,B=217,A=255)
		TextFont="AAFontMedium"
		WinTop=0.07
		WinLeft=0.76
		WinWidth=0.22
		WinHeight=0.05
	End Object
	Begin Object Class=GUILabel Name=DebugLabel
		TextColor=(R=255,G=255,B=255,A=255)
		StyleName="TextLabel"
		WinTop=0.8
		WinLeft=0.75
		WinWidth=0.9
		WinHeight=0.05
	End Object
	*/

	//i_Background = GUIImage'AGP_Interface.AAGameMenu_SpotterMap.MyBackground';
	//i_Map = GUIImageButton'AGP_Interface.AAGameMenu_SpotterMap.MapImage';
	//guilTitle = GUILabel'AGP_Interface.AAGameMenu_SpotterMap.TitleLabel';
	//guilDebug = GUILabel'AGP_Interface.AAGameMenu_SpotterMap.DebugLabel';
	//mneGridX = moNumericEdit'AGP_Interface.AAGameMenu_SpotterMap.SpotterGridXNumericEditBox';
	//mneGridY = moNumericEdit'AGP_Interface.AAGameMenu_SpotterMap.SpotterGridYNumericEditBox';
	//guibGridFireMission = GUIButton'AGP_Interface.AAGameMenu_SpotterMap.GridFireMissionButton';
	//mcbMissionType = moComboBox'AGP_Interface.AAGameMenu_SpotterMap.MissionTypeComboBox';
	//mcbTargetType = moComboBox'AGP_Interface.AAGameMenu_SpotterMap.TargetTypeComboBox';
}

void UAAGameMenu_SpotterMap::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super.InitComponent(MyController, MyOwner);
	__OnRendered__Delegate = OnDrawMapGrid;
	InitializeMap();
	*/
}

bool UAAGameMenu_SpotterMap::NotifyLevelChange()
{
	InitializeMap();
	return true;
}

void UAAGameMenu_SpotterMap::InitializeMap()
{
	/*
	ScalingMapImage = new () classClass'TexScaler';
	ScalingMapImage.Material = PlayerOwner().Level.RadarMapImage;
	ScalingMapImage.UScale = 1;
	ScalingMapImage.VScale = 1;
	ScalingMapImage.UOffset = 0;
	ScalingMapImage.VOffset = 0;
	RotatingMapImage = new () classClass'TexRotator';
	RotatingMapImage.Material = ScalingMapImage;
	RotatingMapImage.TexRotationType = 0;
	RotatingMapImage.Rotation = rot(0, 16384, 0);
	RotatingMapImage.UOffset = (float(ScalingMapImage.Material.MaterialUSize()) / 2);
	RotatingMapImage.VOffset = (float(ScalingMapImage.Material.MaterialVSize()) / 2);
	RotatingMapImage.OscillationRate = rot(0, 0, 0);
	RotatingMapImage.OscillationAmplitude = rot(0, 0, 0);
	RotatingMapImage.OscillationPhase = rot(0, 0, 0);
	i_Map.Image = RotatingMapImage;
	mcbMissionType.MyComboBox.List.Insert(0, "Suppress", , "SUPPRESS");
	mcbMissionType.MyComboBox.List.Insert(1, "Smoke", , "SMOKE");
	mcbMissionType.MyComboBox.List.Insert(2, "Training", , "TRAINING");
	mcbMissionType.MyComboBox.Edit.bReadOnly = true;
	mcbTargetType.MyComboBox.List.Insert(0, "Infantry", , "Infantry");
	mcbTargetType.MyComboBox.List.Insert(1, "Vehicles", , "Vehicles");
	mcbTargetType.MyComboBox.Edit.bReadOnly = true;
	mneGridX.MyNumericEdit.MinValue = (0 + HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridX);
	mneGridX.MyNumericEdit.MaxValue = (100 + HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridX);
	mneGridX.SetComponentValue(string((mneGridX.MyNumericEdit.MinValue + 50)));
	mneGridY.MyNumericEdit.MinValue = (0 + HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridY);
	mneGridY.MyNumericEdit.MaxValue = (100 + HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridY);
	mneGridY.SetComponentValue(string((mneGridY.MyNumericEdit.MinValue + 50)));
	*/
}

FVector UAAGameMenu_SpotterMap::ConvertWorldToRotatedMapCoordinates(FVector vWorld)
{
	/*
	if ((vWorld.X >= 0) && (vWorld.Y <= 0))
	{
		(vWorld.Y *= -1);
		return vWorld;
	}
	if ((vWorld.X >= 0) && (vWorld.Y > 0))
	{
		(vWorld.X *= float(-1));
		return vWorld;
	}
	if ((vWorld.X <= 0) && (vWorld.Y > 0))
	{
		(vWorld.Y *= float(-1));
		return vWorld;
	}
	if ((vWorld.X <= 0) && (vWorld.Y <= 0))
	{
		(vWorld.X *= float(-1));
		return vWorld;
	}
	*/
	return vWorld;     //FAKE   /ELiZ
}

void UAAGameMenu_SpotterMap::OnDrawMapGrid(UCanvas* Canvas)
{
	/*
	local Color colorGridLine;
	local int32 i;
	local float fpNormalizedY;
	local float fpNormalizedX;
	local float fpMapScaleX;
	local float fpMapScaleY;
	local float fpMapStartX;
	local float fpMapStartY;
	local float fpMapHeight;
	local float fpMapWidth;
	local float fpMapCenterX;
	local float fpMapCenterY;
	local float fpCursorLocationX;
	local float fpCursorLocationY;
	fpMapStartX = (i_Map.WinLeft * float(Canvas.SizeX));
	fpMapStartY = ((i_Map.WinTop * float(Canvas.SizeY)) + (0.05 * float(Canvas.SizeY)));
	fpMapHeight = float((i_Map.iScreenBottom - i_Map.iScreenTop));
	fpMapWidth = float((i_Map.iScreenRight - i_Map.iScreenLeft));
	fpMapCenterX = (PlayerOwner().Level.RadarMapOffset.X - (PlayerOwner().Level.RadarMapSize / 2));
	fpMapCenterY = (PlayerOwner().Level.RadarMapOffset.Y - (PlayerOwner().Level.RadarMapSize / 2));
	fpMapScaleY = (fpMapHeight / 100);
	fpMapScaleX = (fpMapWidth / 100);
	Canvas.SetDrawColor(255, 255, 255, 192);
	Canvas.SetPos(fpMapStartX, fpMapStartY);
	Canvas.DrawHorizontal(fpMapStartY, fpMapWidth);
	Canvas.DrawHorizontal((fpMapStartY + fpMapHeight), fpMapWidth);
	Canvas.DrawVertical(fpMapStartX, fpMapHeight);
	Canvas.DrawVertical((fpMapStartX + fpMapWidth), fpMapHeight);
	colorGridLine = Class'Canvas'.MakeColor(255, 255, 255);
	i = 10;
	if (i <= 90)
	{
		if ((float(i) * fpMapScaleY) > float(i_Map.Image.MaterialVSize()))
		{
		}
		Canvas.SetDrawColor(128, 128, 128, 64);
		Canvas.SetPos(fpMapStartX, (fpMapStartY + (float(i) * fpMapScaleY)));
		Canvas.DrawHorizontal((fpMapStartY + (float(i) * fpMapScaleY)), fpMapWidth);
		Canvas.SetDrawColor(220, 220, 220);
		Canvas.SetPos((fpMapStartX - float(25)), ((fpMapStartY + (float(i) * fpMapScaleY)) - 5));
		Canvas.DrawText("" $ string((HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridY + (100 - i))));
		Canvas.SetPos(((fpMapStartX + fpMapWidth) + 4), ((fpMapStartY + (float(i) * fpMapScaleY)) - 5));
		Canvas.DrawText("" $ string((HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridY + (100 - i))));
		Canvas.SetDrawColor(128, 128, 128, 64);
		Canvas.SetPos((fpMapStartX + (float(i) * fpMapScaleX)), fpMapStartY);
		Canvas.DrawVertical((fpMapStartX + (float(i) * fpMapScaleX)), fpMapHeight);
		Canvas.SetDrawColor(220, 220, 220);
		Canvas.SetPos(((fpMapStartX + (float(i) * fpMapScaleX)) - 5), (fpMapStartY - float(15)));
		Canvas.DrawText("" $ string((HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridX + i)));
		Canvas.SetPos(((fpMapStartX + (float(i) * fpMapScaleX)) - 5), ((fpMapStartY + fpMapHeight) + 2));
		Canvas.DrawText("" $ string((HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridX + i)));
		(i += 10);
	}
	Canvas.SetDrawColor(128, 0, 0, 255);
	fpNormalizedX = (float(mneGridX.GetComponentValue()) + float(HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridX));
	fpNormalizedY = ((100 - float(mneGridY.GetComponentValue())) + float(HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridY));
	fpCursorLocationX = (fpMapStartX + (fpNormalizedX * fpMapScaleX));
	fpCursorLocationY = (fpMapStartY + (fpNormalizedY * fpMapScaleY));
	Canvas.SetPos(fpCursorLocationX, (fpCursorLocationY - (fpMapHeight * 0.05)));
	Canvas.DrawVertical(fpCursorLocationX, (fpMapHeight * 0.1));
	Canvas.SetPos((fpCursorLocationX - (fpMapWidth * 0.05)), fpCursorLocationY);
	Canvas.DrawHorizontal(fpCursorLocationY, (fpMapWidth * 0.1));
	*/
}

bool UAAGameMenu_SpotterMap::ButtonClick(UGUIComponent* Sender)
{
	/*
	local FString sCFFCommand;
	Switch(Sender)
	{
		case guibGridFireMission:
			sCFFCommand = "CallForFireGrid " $ mneGridX.GetComponentValue() $ " " $ mneGridY.GetComponentValue() $ " " $ mcbMissionType.GetExtra() $ " " $ mcbTargetType.GetExtra();
			HumanController(PlayerOwner()).ConsoleCommand(sCFFCommand);
			HumanController(PlayerOwner()).ClientCloseMenu(true);
			break;
		default:
	}
	*/
	return true;
}

void UAAGameMenu_SpotterMap::InternalOnChange(UGUIComponent* Sender)
{
	/*
	switch(Sender)
	{
		case mcbMissionType:
		case mcbTargetType:
		case mneGridX:
		case mneGridY:
			guibGridFireMission.EnableMe();
			break;
		default:
	}
	*/
}
