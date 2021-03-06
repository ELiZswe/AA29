// All the original content belonged to the US Army

#include "AA29/Object/Actor/HUD/AGP_HUD/NPCPathBuilderHUD/NPCPathBuilderHUD.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/Actor/NPCPathNodeBuilder/NPCPathNodeBuilder.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCCoverPositionPathNode/NPCFirePositionPathNode/NPCFirePositionPathNode.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCWaypointPathNode.h"

ANPCPathBuilderHUD::ANPCPathBuilderHUD(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	colorTitle = FColor(0, 255, 255, 255);
	colorActiveOption = FColor(255, 255, 255, 255);
	colorInactiveOption = FColor(80, 80, 80, 255);
	colorMenuFlyover = FColor(255, 128, 255, 255);
	colorPathTestLeft = FColor(0, 0, 255, 255);
	colorPathTestMiddle = FColor(0, 255, 0, 255);
	colorPathTestRight = FColor(255, 0, 0, 255);
	aiLineTestLeftValid.SetNum(50);
	aiLineTestRightValid.SetNum(50);
	avMenuItems.SetNum(20);
	avMenuItemsDimensions.SetNum(20);
	asMenuIconDescriptions.SetNum(20);
	asMenuIconDescriptions = {
		"Cover Node",
		"Waypoint (must have patrol path set)",
		"Alamo Node",
		"Firing Position Node",
		"Rest Stop Node",
		"Camper Node",
		"Toggle Auto-drop Node Mode",
		"Drop NPC Grunt Start",
		"Drop NPC NCO Start",
		"Drop NPC Officer Start",
		"Drop NPC Commmando Start",
		"Drop NPC Spotter Start",
		"Drop NPC Civilian Start",
		"Open Path Node Builder File",
		"Save Path Node Builder File",
		"Start/Stop Patrol Path"
	};
	bShowPaths = true;
	//bProp = true;
}

static const int32 MAX_MENU_ICONS = 20;
static const int32 ICON_FILESAVE = 14;
static const int32 ICON_PATROLPATH = 15;
static const int32 ICON_CIVILIAN = 12;
static const int32 ICON_SPOTTER = 11;
static const int32 ICON_COMMANDO = 10;
static const int32 ICON_OFFICER = 9;
static const int32 ICON_NCO = 8;
static const int32 ICON_GRUNT = 7;
static const int32 ICON_FILEOPEN = 13;
static const int32 ICON_TOGGLEAUTODROP = 6;
static const int32 ICON_CAMPER = 5;
static const int32 ICON_RESTSTOP = 4;
static const int32 ICON_FIRINGPOSITION = 3;
static const int32 ICON_ALAMO = 2;
static const int32 ICON_WAYPOINT = 1;
static const int32 ICON_COVER = 0;

void ANPCPathBuilderHUD::DrawHUD()
{
	float fpFeatureVerticalOffset = 0;
	/*
	if (!bShowHUD)
	{
		Super::DrawHUD(Canvas);
		return;
	}
	if (npcpnbActivePathBuilder == nullptr)
	{
		Super::DrawHUD(Canvas);
		return;
	}
	if (npcpnbActivePathBuilder.bBusyLoading)
	{
		return;
	}
	if (npcpnbActivePathBuilder.scOwner == nullptr)
	{
		Super::DrawHUD(Canvas);
		return;
	}
	if (!npcpnbActivePathBuilder.bEnabledPathBuilding)
	{
		Super::DrawHUD(Canvas);
		return;
	}
	DrawHUDText(Canvas, "NPC Path Builder Enabled", 1, 0.02, colorTitle, 2);
	if (npcpnbActivePathBuilder.scOwner.Player.bShowWindowsMouse)
	{
		DrawHUDText(Canvas, "Click on Option To Edit Features", 1, 0.04, colorTitle, 2);
	}
	if (npcpnbActivePathBuilder.bInAutoDropMode)
	{
		DrawHUDText(Canvas, "Auto Node Drop Enabled", 1, 0.06, colorTitle, 2);
		DrawHUDText(Canvas, "AltFire suspends auto node dropping or to use items", 0.5, 0.92, colorTitle, 1);
	}
	if (npcpnbActivePathBuilder.iWaypointIndex > 0)
	{
		DrawHUDText(Canvas, "Active Patrol Path Next Tag: " + npcpnbActivePathBuilder.sWaypointNavTag + "-" + FString::FromInt(npcpnbActivePathBuilder.iWaypointIndex), 1, 0.08, colorTitle, 2);
	}
	if (npcpnbActivePathBuilder.scOwner.bNPCPBForceDrop == 1)
	{
		DrawHUDText(Canvas, "Drop Override Enabled", 1, 0.1, colorTitle, 2);
	}
	if ((npcpnbActivePathBuilder.npcpnNodeBeingDeleted != nullptr) && ((GetWorld()->GetTimeSeconds() - npcpnbActivePathBuilder.fpTimeSinceDeleteRequest) < 5))
	{
		fpFeatureVerticalOffset = 0.35;
		DrawHUDText(Canvas, "Ready to delete node: " + FString::FromInt(npcpnbActivePathBuilder.npcpnNodeBeingDeleted) + " (Tag: " + FString::FromInt(npcpnbActivePathBuilder.npcpnNodeBeingDeleted.Tag) + ")", 0.5, fpFeatureVerticalOffset, colorTitle, 1);
		(fpFeatureVerticalOffset += 0.02);
		DrawHUDText(Canvas, "Delete times out in: " + FString::FromInt((5 - (GetWorld()->GetTimeSeconds() - npcpnbActivePathBuilder.fpTimeSinceDeleteRequest))) + " Seconds", 0.5, fpFeatureVerticalOffset, colorTitle, 1);
	}
	if ((npcpnbActivePathBuilder.npcpsBeingDeleted != nullptr) && ((GetWorld()->GetTimeSeconds() - npcpnbActivePathBuilder.fpTimeSinceDeleteRequest) < 5))
	{
		fpFeatureVerticalOffset = 0.35;
		DrawHUDText(Canvas, "Ready to delete NPC player start: " + FString::FromInt(npcpnbActivePathBuilder.npcpsBeingDeleted) + " (Tag: " + FString::FromInt(npcpnbActivePathBuilder.npcpsBeingDeleted.Tag) + ")", 0.5, fpFeatureVerticalOffset, colorTitle, 1);
		(fpFeatureVerticalOffset += 0.02);
		DrawHUDText(Canvas, "Delete times out in: " + FString::FromInt((5 - (GetWorld()->GetTimeSeconds() - npcpnbActivePathBuilder.fpTimeSinceDeleteRequest))) + " Seconds", 0.5, fpFeatureVerticalOffset, colorTitle, 1);
	}
	if (npcpnbActivePathBuilder.fpTimeSinceResetPathsRequest > 0)
	{
		fpFeatureVerticalOffset = 0.35;
		DrawHUDText(Canvas, "Ready to reset all path nodes.  Preset reset again to complete operation.", 0.5, fpFeatureVerticalOffset, colorTitle, 1);
		(fpFeatureVerticalOffset += 0.02);
		DrawHUDText(Canvas, "Reset all paths times out in : " + FString::FromInt((5 - (GetWorld()->GetTimeSeconds() - npcpnbActivePathBuilder.fpTimeSinceResetPathsRequest))) + " Seconds", 0.5, fpFeatureVerticalOffset, colorTitle, 1);
	}
	fpFeatureVerticalOffset = 0.2;
	DrawHUDText(Canvas, "Node Count: " + FString::FromInt(npcpnbActivePathBuilder.anpcpnPathNodes.Num()), 1, fpFeatureVerticalOffset, colorTitle, 2);
	(fpFeatureVerticalOffset += 0.02);
	if (npcpnbActivePathBuilder.npcpnNodeBeingEdited != nullptr)
	{
		if (npcpnbActivePathBuilder.npcpnNodeBeingEdited->IsA(ANPCWaypointPathNode::StaticClass()))
		{
			if (InStr(string(npcpnbActivePathBuilder.npcpnNodeBeingEdited.Tag), "-") != -1)
			{
				DrawHUDText(Canvas, "Current Waypoint: " + FString::FromInt(npcpnbActivePathBuilder.npcpnNodeBeingEdited) + " (tag: " + FString::FromInt(npcpnbActivePathBuilder.npcpnNodeBeingEdited.Tag) + ")", 1, fpFeatureVerticalOffset, colorTitle, 2);
			}
			else
			{
				DrawHUDText(Canvas, "Current Waypoint Is Invalid: " + FString::FromInt(npcpnbActivePathBuilder.npcpnNodeBeingEdited) + " (tag: " + FString::FromInt(npcpnbActivePathBuilder.npcpnNodeBeingEdited.Tag) + ")", 1, fpFeatureVerticalOffset, colorTitle, 2);
			}
		}
		else
		{
			DrawHUDText(Canvas, "Current Node: " + FString::FromInt(npcpnbActivePathBuilder.npcpnNodeBeingEdited), 1, fpFeatureVerticalOffset, colorTitle, 2);
		}
		if (npcpnbActivePathBuilder.npcpnNodeLastEdited != nullptr)
		{
			(fpFeatureVerticalOffset += 0.02);
			DrawHUDText(Canvas, "Last Node For Connections: " + FString::FromInt(npcpnbActivePathBuilder.npcpnNodeLastEdited), 1, fpFeatureVerticalOffset, colorTitle, 2);
		}
	}
	else
	{
		if (npcpnbActivePathBuilder.npcpsBeingEdited != nullptr)
		{
			if (Len(npcpnbActivePathBuilder.npcpsBeingEdited.sNPCWaypointTag) > 0)
			{
				DrawHUDText(Canvas, "Current Player Start: " + FString::FromInt(npcpnbActivePathBuilder.npcpsBeingEdited) + " (NavTag: " + npcpnbActivePathBuilder.npcpsBeingEdited.sNPCWaypointTag + ")", 1, fpFeatureVerticalOffset, colorTitle, 2);
			}
			else
			{
				DrawHUDText(Canvas, "Current Player Start: " + FString::FromInt(npcpnbActivePathBuilder.npcpsBeingEdited) + " (No NavTag)", 1, fpFeatureVerticalOffset, colorTitle, 2);
			}
		}
		else
		{
			DrawHUDText(Canvas, "Current Nodes: None", 1, fpFeatureVerticalOffset, colorTitle, 2);
		}
	}
	(fpFeatureVerticalOffset += 0.02);
	if (npcpnbActivePathBuilder.npcpnNodeBeingEdited != nullptr)
	{
		if (npcpnbActivePathBuilder.npcpnNodeBeingEdited->IsA(ANPCFirePositionPathNode::StaticClass()))
		{
			if (Cast<ANPCFirePositionPathNode>(npcpnbActivePathBuilder.npcpnNodeBeingEdited).bCrouchHere)
			{
				DrawHUDText(Canvas, "Crouch for Cover", 1, fpFeatureVerticalOffset, colorTitle, 2);
				(fpFeatureVerticalOffset += 0.02);
			}
			if (Cast<ANPCFirePositionPathNode>(npcpnbActivePathBuilder.npcpnNodeBeingEdited).bProneHere)
			{
				DrawHUDText(Canvas, "Prone for Cover", 1, fpFeatureVerticalOffset, colorTitle, 2);
				(fpFeatureVerticalOffset += 0.02);
			}
			if (Cast<ANPCFirePositionPathNode>(npcpnbActivePathBuilder.npcpnNodeBeingEdited).bShootWhileCrouched)
			{
				DrawHUDText(Canvas, "Shoot Crouched", 1, fpFeatureVerticalOffset, colorTitle, 2);
				(fpFeatureVerticalOffset += 0.02);
			}
			if (Cast<ANPCFirePositionPathNode>(npcpnbActivePathBuilder.npcpnNodeBeingEdited).bShootWhileProne)
			{
				DrawHUDText(Canvas, "Shoot Prone", 1, fpFeatureVerticalOffset, colorTitle, 2);
				(fpFeatureVerticalOffset += 0.02);
			}
			if (Cast<ANPCFirePositionPathNode>(npcpnbActivePathBuilder.npcpnNodeBeingEdited).bShouldLeanRightToShoot)
			{
				DrawHUDText(Canvas, "Shoot Lean Right", 1, fpFeatureVerticalOffset, colorTitle, 2);
				(fpFeatureVerticalOffset += 0.02);
			}
			if (Cast<ANPCFirePositionPathNode>(npcpnbActivePathBuilder.npcpnNodeBeingEdited).bShouldLeanLeftToShoot)
			{
				DrawHUDText(Canvas, "Shoot Lean Left", 1, fpFeatureVerticalOffset, colorTitle, 2);
				(fpFeatureVerticalOffset += 0.02);
			}
			if (Cast<ANPCFirePositionPathNode>(npcpnbActivePathBuilder.npcpnNodeBeingEdited).bCanUseGrenades)
			{
				DrawHUDText(Canvas, "Can Use Grenades", 1, fpFeatureVerticalOffset, colorTitle, 2);
				(fpFeatureVerticalOffset += 0.02);
			}
		}
	}
	DrawIconMenu(Canvas);
	Super::DrawHUD();
	*/
}

void ANPCPathBuilderHUD::DrawIconMenu(UCanvas* C)
{
	float fpIconVertPosition = 0;
	int32 iMenuIconMouseOver = 0;
	fpIconVertPosition = 0.25;
	/*
	DrawHUDMenuIcon(C, Texture'AGP.S_PNodeCover', 0, fpIconVertPosition, 0);
	(fpIconVertPosition += 0.05);
	DrawHUDMenuIcon(C, Texture'AGP.S_PNodeWaypoint', 0, fpIconVertPosition, 1);
	(fpIconVertPosition += 0.05);
	DrawHUDMenuIcon(C, Texture'AGP.S_PNodeAlamo', 0, fpIconVertPosition, 2);
	(fpIconVertPosition += 0.05);
	DrawHUDMenuIcon(C, Texture'AGP.S_PNodeFiring', 0, fpIconVertPosition, 3);
	(fpIconVertPosition += 0.05);
	DrawHUDMenuIcon(C, Texture'AGP.S_PNodeRest', 0, fpIconVertPosition, 4);
	(fpIconVertPosition += 0.05);
	DrawHUDMenuIcon(C, Texture'AGP.S_PNodeCamper', 0, fpIconVertPosition, 5);
	(fpIconVertPosition += 0.05);
	DrawHUDMenuIcon(C, Texture'AGP.S_ToggleAutoDrop', 0, fpIconVertPosition, 6);
	(fpIconVertPosition += 0.05);
	DrawHUDMenuIcon(C, Texture'AGP.S_PSTagPNBFileOpen', 0, fpIconVertPosition, 13);
	fpIconVertPosition = 0.25;
	DrawHUDMenuIcon(C, Texture'AGP.S_PSTagGrunt', 0.05, fpIconVertPosition, 7);
	(fpIconVertPosition += 0.05);
	DrawHUDMenuIcon(C, Texture'AGP.S_PSTagNCO', 0.05, fpIconVertPosition, 8);
	(fpIconVertPosition += 0.05);
	DrawHUDMenuIcon(C, Texture'AGP.S_PSTagOfficer', 0.05, fpIconVertPosition, 9);
	(fpIconVertPosition += 0.05);
	DrawHUDMenuIcon(C, Texture'AGP.S_PSTagCommando', 0.05, fpIconVertPosition, 10);
	(fpIconVertPosition += 0.05);
	(fpIconVertPosition += 0.05);
	DrawHUDMenuIcon(C, Texture'AGP.S_PSTagCivilian', 0.05, fpIconVertPosition, 12);
	(fpIconVertPosition += 0.05);
	DrawHUDMenuIcon(C, Texture'AGP.S_PSTagStartStopPatrol', 0.05, fpIconVertPosition, 15);
	(fpIconVertPosition += 0.05);
	DrawHUDMenuIcon(C, Texture'AGP.S_PSTagPNBFileSave', 0.05, fpIconVertPosition, 14);
	if (npcpnbActivePathBuilder.scOwner.Player.bShowWindowsMouse)
	{
		iMenuIconMouseOver = DetermineIconIndexClicked(npcpnbActivePathBuilder.GetMouseX(), npcpnbActivePathBuilder.GetMouseY());
		if (iMenuIconMouseOver >= 0)
		{
			if (Len(asMenuIconDescriptions[iMenuIconMouseOver]) > 0)
			{
				DrawHUDTextUnscaled(C, asMenuIconDescriptions[iMenuIconMouseOver], (avMenuItemsDimensions[iMenuIconMouseOver].X + float(20)), (avMenuItems[iMenuIconMouseOver].Y + float(10)), colorMenuFlyover);
			}
		}
	}
	*/
}

void ANPCPathBuilderHUD::WorldSpaceOverlays()
{
	FVector vTestLocation = FVector(0, 0, 0);
	FVector vStartLocation = FVector(0, 0, 0);
	FVector vOffsetRight = FVector(0, 0, 0);
	FVector vOffsetLeft = FVector(0, 0, 0);
	FRotator rotToLastNodeLeft = FRotator(0, 0, 0);
	FRotator rotToLastNodeRight = FRotator(0, 0, 0);
	int32 iLineTest = 0;
	FVector vCollisionHeightOffset = FVector(0, 0, 0);
	int32 iForcedPaths = 0;
	ANavigationPoint* npForcedPathDestination = nullptr;
	/*
	Super::WorldSpaceOverlays();
	vCollisionHeightOffset = FVector(0, 0, 40);
	if (npcpnbActivePathBuilder.bInAutoDropMode && (npcpnbActivePathBuilder.npcpnLastDroppedPathNode != nullptr))
	{
		rotToLastNodeRight = rotator((npcpnbActivePathBuilder.scOwner.Pawn.Location - npcpnbActivePathBuilder.npcpnLastDroppedPathNode.Location));
		rotToLastNodeRight.Yaw += 16384;
		rotToLastNodeLeft = rotator((npcpnbActivePathBuilder.scOwner.Pawn.Location - npcpnbActivePathBuilder.npcpnLastDroppedPathNode.Location));
		rotToLastNodeLeft.Yaw -= 16384;
		iLineTest = 0;
		if (float(iLineTest) < (npcpnbActivePathBuilder.scOwner.Pawn.CollisionRadius + float(10)))
		{
			vOffsetRight = (Vector(Normalize(rotToLastNodeRight)) * float(iLineTest));
			vOffsetLeft = (Vector(Normalize(rotToLastNodeLeft)) * float(iLineTest));
			vTestLocation = (npcpnbActivePathBuilder.npcpnLastDroppedPathNode.Location + vOffsetRight);
			vStartLocation = (npcpnbActivePathBuilder.scOwner.Pawn.Location + vOffsetRight);
			vStartLocation -= vCollisionHeightOffset;
			vTestLocation -= vCollisionHeightOffset;
			if (aiLineTestRightValid[(iLineTest / 2)] == 1)
			{
				Draw3DLine(vStartLocation, vTestLocation, Class'Canvas'.MakeColor(0, uint8((255 - iLineTest)), 0, 64));
			}
			else
			{
				Draw3DLine(vStartLocation, vTestLocation, Class'Canvas'.MakeColor(255, 0, 0, 64));
			}
			vTestLocation = (npcpnbActivePathBuilder.npcpnLastDroppedPathNode.Location + vOffsetLeft);
			vStartLocation = (npcpnbActivePathBuilder.scOwner.Pawn.Location + vOffsetLeft);
			vStartLocation -= vCollisionHeightOffset;
			vTestLocation -= vCollisionHeightOffset;
			if (aiLineTestLeftValid[(iLineTest / 2)] == 1)
			{
				Draw3DLine(vStartLocation, vTestLocation, Class'Canvas'.MakeColor(0, 0, uint8((255 - iLineTest)), 64));
			}
			else
			{
				Draw3DLine(vStartLocation, vTestLocation, Class'Canvas'.MakeColor(255, 0, 0, 64));
			}
			iLineTest++;
		}
	}
	if (npcpnbActivePathBuilder.npcpnNodeBeingEdited != nullptr)
	{
		if ((npCachedForcedPathsSourceNode != npcpnbActivePathBuilder.npcpnNodeBeingEdited) || (npcpnbActivePathBuilder.npcpnNodeBeingEdited.ForcedPaths.Num() != anpCachedForcedPathNodes.Num()))
		{
			npCachedForcedPathsSourceNode = npcpnbActivePathBuilder.npcpnNodeBeingEdited;
			anpCachedForcedPathNodes.RemoveAt(0, anpCachedForcedPathNodes.Num());
			for (iForcedPaths = 0; iForcedPaths < npcpnbActivePathBuilder.npcpnNodeBeingEdited.ForcedPaths.Num(); iForcedPaths++)
			{
				npForcedPathDestination = GetNavigationPointFromName(npcpnbActivePathBuilder.npcpnNodeBeingEdited.ForcedPaths[iForcedPaths]);
				if (npForcedPathDestination != nullptr)
				{
					anpCachedForcedPathNodes.insert(0, 1);
					anpCachedForcedPathNodes[0] = npForcedPathDestination;
				}
			}
		}
		for (iForcedPaths = 0; iForcedPaths < anpCachedForcedPathNodes.Num(); iForcedPaths++)
		{
			Draw3DLine(npcpnbActivePathBuilder.npcpnNodeBeingEdited->GetActorLocation(), anpCachedForcedPathNodes[iForcedPaths]->GetActorLocation(), Class'Canvas'.MakeColor(0, 255, 255));
		}
	}
	*/
}

ANavigationPoint* ANPCPathBuilderHUD::GetNavigationPointFromName(FName nameToFind)
{
	int32 iNode = 0;
	/*
	for (iNode = 0; iNode < npcpnbActivePathBuilder.anpcpnPathNodes.Num(); iNode++)
	{
		if (npcpnbActivePathBuilder.anpcpnPathNodes[iNode].Name == nameToFind)
		{
			return npcpnbActivePathBuilder.anpcpnPathNodes[iNode];
		}
	}
	*/
	return nullptr;
}

void ANPCPathBuilderHUD::DrawHUDText(UCanvas* C, FString sText, float fpScaledX, float fpScaledY, FColor colorText, ETextHorzAlignment thaAlignment)
{
	float fpTextWidth = 0;
	float fpTextHeight = 0;
	/*
	C.TextSize(sText, fpTextWidth, fpTextHeight);
	C.DrawColor = colorText;
	switch (thaAlignment)
	{
	case 1:
		C.SetPos(((float(C.SizeX) * fpScaledX) - (fpTextWidth / 2)), (float(C.SizeX) * fpScaledY));
		break;
	case 0:
		C.SetPos((float(C.SizeX) * fpScaledX), (float(C.SizeX) * fpScaledY));
		break;
	case 2:
		C.SetPos(((float(C.SizeX) * fpScaledX) - fpTextWidth), (float(C.SizeX) * fpScaledY));
		break;
	default:
		break;
	}
	C.DrawText(sText);
	*/
}

void ANPCPathBuilderHUD::DrawHUDTextUnscaled(UCanvas* C, FString sText, float fpX, float fpY, FColor colorText)
{
	float fpTextWidth = 0;
	float fpTextHeight = 0;
	/*
	C.TextSize(sText, fpTextWidth, fpTextHeight);
	C.DrawColor = colorText;
	C.SetPos(fpX, fpY);
	C.DrawText(sText);
	*/
}

void ANPCPathBuilderHUD::DrawHUDMenuIcon(UCanvas* C, UMaterialInstance* txtToDraw, float fpScaledX, float fpScaledY, int32 iMenuItemIndex)
{
	/*
	C.SetPos((float(C.SizeX) * fpScaledX), (float(C.SizeY) * fpScaledY));
	avMenuItems[iMenuItemIndex].X = (float(C.SizeX) * fpScaledX);
	avMenuItems[iMenuItemIndex].Y = (float(C.SizeY) * fpScaledY);
	avMenuItemsDimensions[iMenuItemIndex].X = (avMenuItems[iMenuItemIndex].X + (float(txtToDraw.USize) * 0.5));
	avMenuItemsDimensions[iMenuItemIndex].Y = (avMenuItems[iMenuItemIndex].Y + (float(txtToDraw.VSize) * 0.5));
	C.DrawIcon(txtToDraw, 0.5);
	*/
}

int32 ANPCPathBuilderHUD::DetermineIconIndexClicked(int32 ix, int32 iY)
{
	int32 iIconIndex = 0;
	/*
	for (iIconIndex = 0; iIconIndex < 20; iIconIndex++)
	{
		if ((((float(ix) >= avMenuItems[iIconIndex].X) && (float(iY) >= avMenuItems[iIconIndex].Y)) && (float(ix) < avMenuItemsDimensions[iIconIndex].X)) && (float(iY) < avMenuItemsDimensions[iIconIndex].Y))
		{
			return iIconIndex;
		}
	}
	*/
	return -1;
}
