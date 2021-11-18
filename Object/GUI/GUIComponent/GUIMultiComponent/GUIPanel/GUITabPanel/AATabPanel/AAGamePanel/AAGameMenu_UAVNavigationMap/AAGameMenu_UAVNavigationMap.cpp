// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_UAVNavigationMap/AAGameMenu_UAVNavigationMap.h"

UAAGameMenu_UAVNavigationMap::UAAGameMenu_UAVNavigationMap()
{
	/*
	Begin Object Class=GUIImageButton Name=MapImage
		Image=Texture'T_AA2_Maps.Overhead.NoImage'
		ImageRenderStyle=1
		WinTop=0.05
		WinLeft=0.05
		WinWidth=0.68
		WinHeight=0.68
		OnClick=AAGameMenu_UAVNavigationMap.OnMapClick
		OnKeyEvent=MapImage.InternalOnKeyEvent
	End Object
	Begin Object Class=moEditBox Name=WaypointAltitudeEntryField
		CaptionWidth=0.3
		Caption="Waypoint Altitude:"
		OnCreateComponent=WaypointAltitudeEntryField.InternalOnCreateComponent
		IniOption="@Internal"
		Hint="Enter the desired altitude for this waypoint."
		WinTop=0.79
		WinLeft=0.05
		WinWidth=0.25
		WinHeight=0.05
		TabOrder=2
		bStandardized=False
		OnChange=AAGameMenu_UAVNavigationMap.InternalOnChange
	End Object
	Begin Object Class=moEditBox Name=WaypointSpeedEntryField
		CaptionWidth=0.3
		Caption="Waypoint Speed:"
		OnCreateComponent=WaypointSpeedEntryField.InternalOnCreateComponent
		IniOption="@Internal"
		Hint="Enter the desired speed for this waypoint"
		WinTop=0.79
		WinLeft=0.3
		WinWidth=0.25
		WinHeight=0.05
		TabOrder=2
		bStandardized=False
		OnChange=AAGameMenu_UAVNavigationMap.InternalOnChange
	End Object
	Begin Object Class=GUIButton Name=DeleteWaypointButton
		Caption="Delete Waypoint"
		MenuState=4
		StyleName="SquareMenuButton"
		Hint="Click here to delete the current waypoint."
		WinTop=0.79
		WinLeft=0.62
		WinWidth=0.13
		WinHeight=0.05
		TabOrder=14
		OnClick=AAGameMenu_UAVNavigationMap.ButtonClick
		OnKeyEvent=DeleteWaypointButton.InternalOnKeyEvent
	End Object
	Begin Object Class=GUIButton Name=ClearWaypointsButton
		Caption="Clear Waypoints"
		MenuState=4
		StyleName="SquareMenuButton"
		Hint="Click here to clear all of the waypoints."
		WinTop=0.79
		WinLeft=0.8
		WinWidth=0.17
		WinHeight=0.05
		TabOrder=14
		OnClick=AAGameMenu_UAVNavigationMap.ButtonClick
		OnKeyEvent=ClearWaypointsButton.InternalOnKeyEvent
	End Object
	Begin Object Class=GUIButton Name=SaveFlightPlanButton
		Caption="Save Flight Plan"
		MenuState=4
		StyleName="SquareMenuButton"
		Hint="Click here to save the flight plan."
		WinTop=0.85
		WinLeft=0.05
		WinWidth=0.15
		WinHeight=0.05
		TabOrder=14
		OnClick=AAGameMenu_UAVNavigationMap.ButtonClick
		OnKeyEvent=SaveFlightPlanButton.InternalOnKeyEvent
	End Object
	Begin Object Class=GUIButton Name=DiscardChangesButton
		Caption="Discard Changes"
		StyleName="SquareMenuButton"
		Hint="Click here to discard any changes to the flight plan."
		WinTop=0.85
		WinLeft=0.25
		WinWidth=0.15
		WinHeight=0.05
		TabOrder=14
		OnClick=AAGameMenu_UAVNavigationMap.ButtonClick
		OnKeyEvent=DiscardChangesButton.InternalOnKeyEvent
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
		Caption="UAV Flight Planner"
		TextAlign=1
		TextColor=(R=255,G=255,B=255,A=255)
		StyleName="TextLabel"
		WinTop=0.07
		WinLeft=0.25
		WinWidth=0.5
		WinHeight=0.05
	End Object
	Begin Object Class=GUILabel Name=DebugLabel
		TextColor=(R=255,G=255,B=255,A=255)
		StyleName="TextLabel"
		WinTop=0.25
		WinLeft=0.75
		WinWidth=0.9
		WinHeight=0.05
	End Object
	*/
	//texWaypointMarker = Texture'T_AA2_UI.Menu.box_check_plus';
	//i_Background = GUIImage'AGP_Interface.AAGameMenu_UAVNavigationMap.MyBackground';
	//i_Map = GUIImageButton'AGP_Interface.AAGameMenu_UAVNavigationMap.MapImage';
	//guilTitle = GUILabel'AGP_Interface.AAGameMenu_UAVNavigationMap.TitleLabel';
	//guilDebug = GUILabel'AGP_Interface.AAGameMenu_UAVNavigationMap.DebugLabel';
	//mebWaypointAltitude = moEditBox'AGP_Interface.AAGameMenu_UAVNavigationMap.WaypointAltitudeEntryField';
	//mebWaypointSpeed = moEditBox'AGP_Interface.AAGameMenu_UAVNavigationMap.WaypointSpeedEntryField';
	//guibSaveFlightPlan = GUIButton'AGP_Interface.AAGameMenu_UAVNavigationMap.SaveFlightPlanButton';
	//guibDeleteWaypoint = GUIButton'AGP_Interface.AAGameMenu_UAVNavigationMap.DeleteWaypointButton';
	//guibClearAllWaypoints = GUIButton'AGP_Interface.AAGameMenu_UAVNavigationMap.ClearWaypointsButton';
	//guibDiscardChanges = GUIButton'AGP_Interface.AAGameMenu_UAVNavigationMap.DiscardChangesButton';

}

void UAAGameMenu_UAVNavigationMap::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super.InitComponent(MyController, MyOwner);
	InitializeMap();
	*/
}

bool UAAGameMenu_UAVNavigationMap::NotifyLevelChange()
{
	//InitializeMap();
	return true;
}

void UAAGameMenu_UAVNavigationMap::InitializeMap()
{
	/*
	local int32 iWP;
	if (awpWaypoints.Length > 0)
	{
		awpWaypoints.remove(0, awpWaypoints.Length);
	}
	HumanController(PlayerOwner()).vehUAV = HumanController(PlayerOwner()).UAVFindViewUAV();
	Log("Found " $ string(NPCBaseRavenController(HumanController(PlayerOwner()).vehUAV.Controller).auavfpwpWaypoints.Length) $ " waypoints from vehicle");
	if (NPCBaseRavenController(HumanController(PlayerOwner()).vehUAV.Controller).auavfpwpWaypoints.Length > 0)
	{
		awpWaypoints.insert(0, NPCBaseRavenController(HumanController(PlayerOwner()).vehUAV.Controller).auavfpwpWaypoints.Length);
		for (iWP = 0; iWP < NPCBaseRavenController(HumanController(PlayerOwner()).vehUAV.Controller).auavfpwpWaypoints.Length; iWP++)
		{
			Log("Copying wp " $ string(iWP) $ " at location " $ string(NPCBaseRavenController(HumanController(PlayerOwner()).vehUAV.Controller).auavfpwpWaypoints[iWP].vLocation));
			awpWaypoints[iWP].vLocation = NPCBaseRavenController(HumanController(PlayerOwner()).vehUAV.Controller).auavfpwpWaypoints[iWP].vLocation;
			awpWaypoints[iWP].fpHeight = NPCBaseRavenController(HumanController(PlayerOwner()).vehUAV.Controller).auavfpwpWaypoints[iWP].fpAltitude;
			awpWaypoints[iWP].fpSpeed = NPCBaseRavenController(HumanController(PlayerOwner()).vehUAV.Controller).auavfpwpWaypoints[iWP].fpSpeed;
		}
	}
	Log("Vertical offset for grid reference: " $ string(HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridY));
	__OnRendered__Delegate = OnDrawMapGrid;
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
	*/
}

FVector UAAGameMenu_UAVNavigationMap::ConvertWorldToRotatedMapCoordinates(FVector vWorld)
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
	return FVector(0, 0, 0);       //FAKE    /ELiZ
}

void UAAGameMenu_UAVNavigationMap::OnDrawMapGrid(UCanvas* Canvas)
{
	/*
	local Color colorGridLine;
	local int32 i;
	local int32 iWaypoint;
	local Vector vWPImageMapLocation;
	fpMapStartX = (i_Map.WinLeft * float(Canvas.SizeX));
	fpMapStartY = ((i_Map.WinTop * float(Canvas.SizeY)) + (0.05 * float(Canvas.SizeY)));
	fpMapHeight = float((i_Map.iScreenBottom - i_Map.iScreenTop));
	fpMapWidth = float((i_Map.iScreenRight - i_Map.iScreenLeft));
	fpMapScaleY = (fpMapHeight / 100);
	fpMapScaleX = (fpMapWidth / 100);
	fpWidthHeightRatio = (fpMapWidth / fpMapHeight);
	Canvas.SetDrawColor(255, 255, 0, 255);
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
		Canvas.SetPos((fpMapStartX - float(25)), ((fpMapStartY + (float(i) * fpMapScaleY)) - 5));
		Canvas.DrawText("" $ string((HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridY + (100 - i))));
		Canvas.SetPos(((fpMapStartX + fpMapWidth) + 4), ((fpMapStartY + (float(i) * fpMapScaleY)) - 5));
		Canvas.DrawText("" $ string((HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridY + (100 - i))));
		Canvas.SetDrawColor(128, 128, 128, 64);
		Canvas.SetPos((fpMapStartX + (float(i) * fpMapScaleX)), fpMapStartY);
		Canvas.DrawVertical((fpMapStartX + (float(i) * fpMapScaleX)), fpMapHeight);
		Canvas.SetPos(((fpMapStartX + (float(i) * fpMapScaleX)) - 5), (fpMapStartY - float(15)));
		Canvas.DrawText("" $ string((HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridX + i)));
		Canvas.SetPos(((fpMapStartX + (float(i) * fpMapScaleX)) - 5), ((fpMapStartY + fpMapHeight) + 2));
		Canvas.DrawText("" $ string((HumanController(PlayerOwner()).GameReplicationInfo.iSpotterBaseGridX + i)));
		i += 10;
	}
	Canvas.SetDrawColor(255, 255, 255, 128);
	for (iWaypoint = 0; iWaypoint < awpWaypoints.Length; iWaypoint++)
	{
		Log("Draw WP " $ string(iWaypoint));
		vWPImageMapLocation = WorldToMap(awpWaypoints[iWaypoint].vLocation);
		Log("location " $ string(vWPImageMapLocation.X) $ ", " $ string(vWPImageMapLocation.Y));
		Canvas.SetPos((vWPImageMapLocation.X + float(20)), vWPImageMapLocation.Y);
		Canvas.DrawText("Waypoint: " $ string((iWaypoint + 1)));
		Canvas.SetPos((vWPImageMapLocation.X + float(20)), (vWPImageMapLocation.Y + float(10)));
		Canvas.DrawText("Spd: " $ string(int((awpWaypoints[iWaypoint].fpSpeed / 24))));
		Canvas.SetPos((vWPImageMapLocation.X + float(20)), (vWPImageMapLocation.Y + float(20)));
		Canvas.DrawText("Alt: " $ string(int((awpWaypoints[iWaypoint].fpHeight / 16.708))) $ " ft.");
		Canvas.SetPos(vWPImageMapLocation.X, vWPImageMapLocation.Y);
		Canvas.DrawIcon(texWaypointMarker, 0.5);
	}
	*/
}

FVector UAAGameMenu_UAVNavigationMap::WorldToMap(FVector vWorldLoc)
{
	FVector vResult=FVector(0,0,0);
	/*
	local float fpPercentWorldMap;
	local float fpWorldMapSize;
	
	local Vector vTopLeftWorld;
	(vWorldLoc.X += PlayerOwner().Level.RadarMapSize);
	(vWorldLoc.Y += PlayerOwner().Level.RadarMapSize);
	fpWorldMapSize = (PlayerOwner().Level.RadarMapSize * 2);
	fpPercentWorldMap = ((vWorldLoc.X - vTopLeftWorld.X) / fpWorldMapSize);
	vResult.X = (fpPercentWorldMap * fpMapWidth);
	fpPercentWorldMap = ((vWorldLoc.Y - vTopLeftWorld.Y) / fpWorldMapSize);
	vResult.Y = (fpPercentWorldMap * fpMapHeight);
	(vResult.Y *= fpWidthHeightRatio);
	*/
	return vResult;
}

float UAAGameMenu_UAVNavigationMap::MapToWorldLocX(float fpX)
{
	/*
	local float fpMapPercent;
	fpMapPercent = ((fpX - fpMapStartX) / fpMapWidth);
	return ((fpMapPercent * PlayerOwner().Level.RadarMapSize) - PlayerOwner().Level.RadarMapOffset.X);
	*/
	return 0;   //FAKE   /ELiZ
}

float UAAGameMenu_UAVNavigationMap::MapToWorldLocY(float fpY)
{
	/*
	local float fpMapPercent;
	fpMapPercent = ((fpY - fpMapStartY) / fpMapHeight);
	return ((fpMapPercent * PlayerOwner().Level.RadarMapSize) - PlayerOwner().Level.RadarMapOffset.Y);
	*/
	return 0;   //FAKE   /ELiZ
}

bool UAAGameMenu_UAVNavigationMap::ButtonClick(UGUIComponent* Sender)
{
	/*
	Switch(Sender)
	{
		case guibSaveFlightPlan:
			HumanController(PlayerOwner()).ClientCloseMenu(true);
			break;
		default:
	}
	*/
	return true;
}

void UAAGameMenu_UAVNavigationMap::InternalOnChange(UGUIComponent* Sender)
{
	/*
	Switch(Sender)
	{
		case mebWaypointAltitude:
			break;
		case mebWaypointSpeed:
			break;
		default:
	}
	*/
}

bool UAAGameMenu_UAVNavigationMap::OnMapClick(UGUIComponent* Sender)
{
	/*
	Log("Map size: " $ string(PlayerOwner().Level.RadarMapSize) $ "  offset: " $ string(PlayerOwner().Level.RadarMapOffset.X) $ ", " $ string(PlayerOwner().Level.RadarMapOffset.Y));
	Log("Mouse clicked at " $ string(Controller.MouseX) $ ", " $ string(Controller.MouseY) $ " map location " $ string(MapToWorldLocX(Controller.MouseX)) $ ", " $ string(MapToWorldLocX(Controller.MouseY)));
	*/
	return true;
}
