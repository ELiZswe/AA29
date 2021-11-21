// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_UAVNavigationMap/AAGameMenu_UAVNavigationMap.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImageButton/GUIImageButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"

UAAGameMenu_UAVNavigationMap::UAAGameMenu_UAVNavigationMap()
{
	UGUIImageButton* MapImage = NewObject<UGUIImageButton>(UGUIImageButton::StaticClass());
	MapImage->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Maps/Overhead/NoImag_Mat.NoImag_Mat'"), NULL, LOAD_None, NULL);
	MapImage->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MapImage->WinTop = 0.05;
	MapImage->WinLeft = 0.05;
	MapImage->WinWidth = 0.68;
	MapImage->WinHeight = 0.68;
	//MapImage->OnClick=AAGameMenu_UAVNavigationMap.OnMapClick;
	//MapImage->OnKeyEvent=MapImage.InternalOnKeyEvent;
	UmoEditBox* WaypointAltitudeEntryField = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	WaypointAltitudeEntryField->CaptionWidth = 0.3;
	WaypointAltitudeEntryField->Caption = "Waypoint Altitude:";
	//WaypointAltitudeEntryField->OnCreateComponent=WaypointAltitudeEntryField.InternalOnCreateComponent;
	WaypointAltitudeEntryField->IniOption = "@Internal";
	WaypointAltitudeEntryField->Hint = "Enter the desired altitude for this waypoint.";
	WaypointAltitudeEntryField->WinTop = 0.79;
	WaypointAltitudeEntryField->WinLeft = 0.05;
	WaypointAltitudeEntryField->WinWidth = 0.25;
	WaypointAltitudeEntryField->WinHeight = 0.05;
	WaypointAltitudeEntryField->TabOrder = 2;
	WaypointAltitudeEntryField->bStandardized = false;
	//WaypointAltitudeEntryField->OnChange=AAGameMenu_UAVNavigationMap.InternalOnChange;
	UmoEditBox* WaypointSpeedEntryField = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	WaypointSpeedEntryField->CaptionWidth = 0.3;
	WaypointSpeedEntryField->Caption = "Waypoint Speed:";
	//WaypointSpeedEntryField->OnCreateComponent=WaypointSpeedEntryField.InternalOnCreateComponent;
	WaypointSpeedEntryField->IniOption = "@Internal";
	WaypointSpeedEntryField->Hint = "Enter the desired speed for this waypoint";
	WaypointSpeedEntryField->WinTop = 0.79;
	WaypointSpeedEntryField->WinLeft = 0.3;
	WaypointSpeedEntryField->WinWidth = 0.25;
	WaypointSpeedEntryField->WinHeight = 0.05;
	WaypointSpeedEntryField->TabOrder = 2;
	WaypointSpeedEntryField->bStandardized = false;
	//WaypointSpeedEntryField->OnChange=AAGameMenu_UAVNavigationMap.InternalOnChange;
	UGUIButton* DeleteWaypointButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	DeleteWaypointButton->Caption = "Delete Waypoint";
	DeleteWaypointButton->MenuState = EMenuState::MSAT_Disabled;
	DeleteWaypointButton->StyleName = "SquareMenuButton";
	DeleteWaypointButton->Hint = "Click here to delete the current waypoint.";
	DeleteWaypointButton->WinTop = 0.79;
	DeleteWaypointButton->WinLeft = 0.62;
	DeleteWaypointButton->WinWidth = 0.13;
	DeleteWaypointButton->WinHeight = 0.05;
	DeleteWaypointButton->TabOrder = 14;
	//DeleteWaypointButton->OnClick=AAGameMenu_UAVNavigationMap.ButtonClick;
	//DeleteWaypointButton->OnKeyEvent=DeleteWaypointButton.InternalOnKeyEvent;
	UGUIButton* ClearWaypointsButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ClearWaypointsButton->Caption = "Clear Waypoints";
	ClearWaypointsButton->MenuState = EMenuState::MSAT_Disabled;
	ClearWaypointsButton->StyleName = "SquareMenuButton";
	ClearWaypointsButton->Hint = "Click here to clear all of the waypoints.";
	ClearWaypointsButton->WinTop = 0.79;
	ClearWaypointsButton->WinLeft = 0.8;
	ClearWaypointsButton->WinWidth = 0.17;
	ClearWaypointsButton->WinHeight = 0.05;
	ClearWaypointsButton->TabOrder = 14;
	//ClearWaypointsButton->OnClick=AAGameMenu_UAVNavigationMap.ButtonClick;
	//ClearWaypointsButton->OnKeyEvent=ClearWaypointsButton.InternalOnKeyEvent;
	UGUIButton* SaveFlightPlanButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SaveFlightPlanButton->Caption = "Save Flight Plan";
	SaveFlightPlanButton->MenuState = EMenuState::MSAT_Disabled;
	SaveFlightPlanButton->StyleName = "SquareMenuButton";
	SaveFlightPlanButton->Hint = "Click here to save the flight plan.";
	SaveFlightPlanButton->WinTop = 0.85;
	SaveFlightPlanButton->WinLeft = 0.05;
	SaveFlightPlanButton->WinWidth = 0.15;
	SaveFlightPlanButton->WinHeight = 0.05;
	SaveFlightPlanButton->TabOrder = 14;
	//SaveFlightPlanButton->OnClick=AAGameMenu_UAVNavigationMap.ButtonClick;
	//SaveFlightPlanButton->OnKeyEvent=SaveFlightPlanButton.InternalOnKeyEvent;
	UGUIButton* DiscardChangesButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	DiscardChangesButton->Caption = "Discard Changes";
	DiscardChangesButton->StyleName = "SquareMenuButton";
	DiscardChangesButton->Hint = "Click here to discard any changes to the flight plan.";
	DiscardChangesButton->WinTop = 0.85;
	DiscardChangesButton->WinLeft = 0.25;
	DiscardChangesButton->WinWidth = 0.15;
	DiscardChangesButton->WinHeight = 0.05;
	DiscardChangesButton->TabOrder = 14;
	//DiscardChangesButton->OnClick=AAGameMenu_UAVNavigationMap.ButtonClick;
	//DiscardChangesButton->OnKeyEvent=DiscardChangesButton.InternalOnKeyEvent;
	UGUIImage* MyBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MyBackground->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/backgroundfil_Mat.backgroundfil_Mat'"), NULL, LOAD_None, NULL);
	MyBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	MyBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MyBackground->WinTop = 0.01;
	MyBackground->WinLeft = 0.01;
	MyBackground->WinWidth = 0.98;
	MyBackground->WinHeight = 0.89;
	MyBackground->RenderWeight = 0;
	MyBackground->bBoundToParent = true;
	MyBackground->bScaleToParent = true;
	UGUILabel* TitleLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TitleLabel->Caption = "UAV Flight Planner";
	TitleLabel->TextAlign = ETextAlign::TXTA_Center;
	TitleLabel->TextColor = FColor(255, 255, 255, 255);
	TitleLabel->StyleName = "TextLabel";
	TitleLabel->WinTop = 0.07;
	TitleLabel->WinLeft = 0.25;
	TitleLabel->WinWidth = 0.5;
	TitleLabel->WinHeight = 0.05;
	UGUILabel* DebugLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DebugLabel->TextColor = FColor(255, 255, 255, 255);
	DebugLabel->StyleName = "TextLabel";
	DebugLabel->WinTop = 0.25;
	DebugLabel->WinLeft = 0.75;
	DebugLabel->WinWidth = 0.9;
	DebugLabel->WinHeight = 0.05;
	texWaypointMarker = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_check_plus_Mat.box_check_plus_Mat'"), NULL, LOAD_None, NULL);
	i_Background = MyBackground;
	i_Map = MapImage;
	guilTitle = TitleLabel;
	guilDebug = DebugLabel;
	mebWaypointAltitude = WaypointAltitudeEntryField;
	mebWaypointSpeed = WaypointSpeedEntryField;
	guibSaveFlightPlan = SaveFlightPlanButton;
	guibDeleteWaypoint = DeleteWaypointButton;
	guibClearAllWaypoints = ClearWaypointsButton;
	guibDiscardChanges = DiscardChangesButton;

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
