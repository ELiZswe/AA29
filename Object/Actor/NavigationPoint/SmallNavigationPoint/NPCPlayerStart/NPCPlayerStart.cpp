// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStart.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCBaseSoldierController.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCPathNode.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/NPCAICombatController/NPCAICombatController.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/PathNode.h"
#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameInfo.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCCoverPositionPathNode/NPCFirePositionPathNode/NPCCamperFirePositionPathNode/NPCCamperFirePositionPathNode.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCDoorEntryPathNode/NPCDoorEntryPathNode.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCWaypointPathNode.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStartCivilian/NPCPlayerStartCivilian.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStartSoldier/NPCPlayerStartCommando/NPCPlayerStartCommando.h"

ANPCPlayerStart::ANPCPlayerStart()
{
	bCanDelaySpawn = true;
	//ControllerClass = ANPCBaseController::StaticClass()
	nameInitAnimSequence = "StdNo";
	iNPCInitialMentalState = 10;
	iNPCLeadershipMentalStateRange = 2500;
	iNPCTeamID = 2;
	fpNPCHearingRadius = 500;
	fpNPCVisionConeAngle = 16384;
	fpNPCMaxVisualRange = 2500;
	fpItemOfInterestSearchRange = 250;
	enpcvaVisionAbility = ENPCVisionAbility::Vision_Average;
	bMaleVoice = true;
	sRHExternalLinkTitle = "Launch an external link in your web browser?";
	sRHExternalLinkCaption = "Congratulations, for visiting the Real Heroes web site you'll earn an XP Bonus: +3%|This is a one-time bonus and you must be logged in with a valid, active account";
	KillHealth = 100;
	enptoTacticalOrders = ENPCTacticalOrders::NPCTO_ControlledFire;
	bAscendingNodeDirection = true;
	bLikesToCloseDoorBehindSelf = true;
	fpChanceOfSpawning = 100;
	fpTurnRate = 18000;
	bSpawnable = true;
	fpNPCWeaponEffectiveRange = 1500;
	RagdollOverride = "SoldierM";
	fpPawnScale = 1.125;
	RagInvInertia = 4;
	RagShootStrength = 10000;
	RagSpinScale = 13;
	RagProneProjectileScale = 0.35;
	fpBOPMajorAdvantageThreshold = 2;
	fpBOPMinorAdvantageThreshold = 1.5;
	fpBOPMinorDisadvantageThreshold = -1.5;
	fpBOPMajorDisadvantageThreshold = -2;
	bNoAutoConnect = true;
	bForcedOnly = true;

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMesh->SetupAttachment(RootComponent);

	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_PSTagGrunt.S_PSTagGrunt'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}

void ANPCPlayerStart::BeginPlay()
{
	ANPCPlayerStart* npcPSIter = nullptr;
	TArray<ANPCPlayerStart> npcPSSimilarTagArray = {};
	int32 inpcBCSpawner = 0;
	int32 iSetCounter = 0;
	Super::BeginPlay();
	if (meshPawn != nullptr)
	{
		SkeletalMesh->SetSkeletalMesh(meshPawn);
	}
	if (bRandomGroupSpawn && nRandomGroupTag != "None")
	{
		/*
		ForEach AllActors('NPCPlayerStart',npcPSIter)
		{
			if (nRandomGroupTag == npcPSIter.nRandomGroupTag)
			{
				npcPSSimilarTagArray.insert (0,1);
				npcPSSimilarTagArray[0]=npcPSIter;
			}
		}
		if (npcPSSimilarTagArray.Num() > 0)
		{
			inpcBCSpawner=Rand(npcPSSimilarTagArray.Num());
		}
		for (iSetCounter=0; iSetCounter<npcPSSimilarTagArray.Num(); iSetCounter++)
		{
			npcPSSimilarTagArray[iSetCounter].bGroupSpawnFieldHolder=npcPSSimilarTagArray[iSetCounter].bRandomGroupSpawn;
			if (iSetCounter == inpcBCSpawner)
			{
				npcPSSimilarTagArray[iSetCounter].bMustSpawn=true;
				npcPSSimilarTagArray[iSetCounter].bRandomGroupSpawn=false;
			}
			else
			{
				npcPSSimilarTagArray[iSetCounter].bMustSpawn=false;
				npcPSSimilarTagArray[iSetCounter].bRandomGroupSpawn=false;
				npcPSSimilarTagArray[iSetCounter].bSpawnable=false;
			}
		}
		*/
	}
}

void ANPCPlayerStart::DebugNavMarker(bool bShowMarker, bool bFinalGoalMarker)
{
	if (dnpcnDebugNavigationMarker == nullptr)
	{
		if (! bShowMarker)
		{
			return;
		}
		//dnpcnDebugNavigationMarker=Spawn('DebugNPCNavigation');
		//dnpcnDebugNavigationMarker->HUDText=this + "." + Tag;
		//dnpcnDebugNavigationMarker->SetOwner(this);
		//dnpcnDebugNavigationMarker->Skins[0]=Texture;
	}
	if (dnpcnDebugNavigationMarker != nullptr)
	{
		//dnpcnDebugNavigationMarker->SetActorLocation(GetActorLocation());
		//dnpcnDebugNavigationMarker->bHidden=! bShowMarker;
		if (bShowMarker)
		{
			if (bFinalGoalMarker)
			{
				//dnpcnDebugNavigationMarker->SetDrawScale3D(FVector(0.15,0.15,0.15));
				//dnpcnDebugNavigationMarker->RotationRate.Yaw=16384;
			}
			else
			{
				//dnpcnDebugNavigationMarker->SetDrawScale3D(FVector(0.075,0.075,0.075));
				//dnpcnDebugNavigationMarker->RotationRate.Yaw=4096;
			}
		}
	}
}

void ANPCPlayerStart::Reset()
{
	Super::Reset();
	bEnabled=false;
	bRandomGroupSpawn=bGroupSpawnFieldHolder;
}

void ANPCPlayerStart::PostBeginPlay()
{
	AAGP_Weapon* agpw = nullptr;
	/*
	agpw=class<AGP_Weapon>(DynamicLoadObject("AGP_Inventory.Weapon_NPC_RPG7_rocket",Class'Class'));
	if (agpw != nullptr && agpw.Default.PickupClass != nullptr)
	{
		agpw.Default.PickupClass.StaticPrecache(Level);
	}
	if (! namePrimaryWeapon ~= "None")
	{
		agpw=class<AGP_Weapon>(DynamicLoadObject(namePrimaryWeapon,Class'Class'));
		if (agpw != nullptr && agpw.Default.PickupClass != nullptr)
		{
			agpw.Default.PickupClass.StaticPrecache(Level);
		}
	}
	if (! nameSecondaryWeapon ~= "None")
	{
		agpw=class<AGP_Weapon>(DynamicLoadObject(nameSecondaryWeapon,Class'Class'));
		if (agpw != nullptr && agpw.Default.PickupClass != nullptr)
		{
			agpw.Default.PickupClass.StaticPrecache(Level);
		}
	}
	if (Len(sPrimaryWeaponDefaultClass) > 0)
	{
		agpw=class<AGP_Weapon>(DynamicLoadObject(sPrimaryWeaponDefaultClass,Class'Class'));
		if (agpw != nullptr && agpw.Default.PickupClass != nullptr)
		{
			agpw.Default.PickupClass.StaticPrecache(Level);
		}
	}
	if (Len(sSecondaryWeaponDefaultClass) > 0)
	{
		agpw=class<AGP_Weapon>(DynamicLoadObject(sSecondaryWeaponDefaultClass,Class'Class'));
		if (agpw != nullptr && agpw.Default.PickupClass != nullptr)
		{
			agpw.Default.PickupClass.StaticPrecache(Level);
		}
	}
	Super::PostBeginPlay();
	*/
}

bool ANPCPlayerStart::ShouldUseStartSpot()
{
	if (bMustSpawn)
	{
		return true;
	}
	if (FMath::FRand() * 100 <= fpChanceOfSpawning)
	{
		return true;
	}
	return false;
}

void ANPCPlayerStart::CustomCreation(ANPCBaseController* npbcController, AAGP_Pawn* agpPawn)
{
}

ANPCBaseController* ANPCPlayerStart::CreateNPC(bool bOverrideLocation, FVector vOverrideLocation, FRotator rotOverride, bool bDebugNow)
{
	
		ANPCBaseController* npcbcNew=nullptr;
		AAGP_Pawn* agpPawnNew = nullptr;
		int32 iAttach = 0;
		int32 iConv = 0;
		int32 iAnim = 0;
		int32 iSound = 0;
		int32 iSpawnAttempts = 0;
		int32 iInitialStartingPathNodeIndex = 0;
		if (bDebugNow)
		{
			bDebugInit=bDebugNow;
		}
		FindAICC();
		if (GetPawnSpawnClass() == nullptr)
		{
			//Log("Warning!!! No Pawn defined for " + this + " - Not creating a Pawn or Controller!");
			return nullptr;
		}
		if (! ShouldUseStartSpot())
		{
			return nullptr;
		}
		if (bDebugInit)
		{
			UE_LOG(LogTemp, Log, TEXT(""));
			UE_LOG(LogTemp, Log, TEXT(""));
			UE_LOG(LogTemp, Log, TEXT(""));
			UE_LOG(LogTemp, Log, TEXT("*******************"));
			//UE_LOG(LogTemp, Log, TEXT(" Creating new controller for pawn at start spot: " + ControllerClass + " with pawn class: " + GetPawnSpawnClass());
			UE_LOG(LogTemp, Log, TEXT("*******************"));
		}
		/*
		npcbcNew=Spawn(ControllerClass);

		if (npcbcNew == nullptr)
		{
			Log("** WARNING ** " + this + " Failure creating controller for tag """ + Tag + """ using class """ + ControllerClass + """");
			return nullptr;
		}
		npcbcNew.npcpsPlayerStart=Self;
		if (bDebugInit)
		{
			Log("Controller created: " + npcbcNew);
		}
		if (bDebugInit)
		{
			if (bStartAndSpawnAtRandomNode)
			{
				Log("Creating new pawn at random waypoint node, class: " + GetPawnSpawnClass());
			}
			else
			{
				Log("Creating new pawn at start spot: " + GetPawnSpawnClass());
			}
		}
		npcbcNew.bDebugPath=bDebugPath;
		if (Len(sNPCWaypointTag) > 0)
		{
			npcbcNew.sNPCWaypointTag=sNPCWaypointTag;
		}
		else
		{
			npcbcNew.sNPCWaypointTag=Tag;
		}
		if (bDebugInit)
		{
			Log("Pathnode waypoint tag is now: " + npcbcNew.sNPCWaypointTag);
		}
		npcbcNew.PreloadPathNodeList();
		if (bDebugInit)
		{
			if (bStartAndSpawnAtRandomNode)
			{
				Log("Will find random pathnode from " + npcbcNew.apnPathNodesForPatrol.Num() + " possible nodes");
			}
		}
		iInitialStartingPathNodeIndex=iStartingPathNodeIndex;
		if (agpPawnNew == nullptr)
		{
			if (bStartAndSpawnAtRandomNode)
			{
				if (iSpawnAttempts ++ > GetPathNodeCount(npcbcNew))
				{
					if (bDebugInit)
					{
						Log("unable to spawn at random node location, using player start location as fall-back");
					}
					agpPawnNew=Spawn(GetPawnSpawnClass(),,,Location,Rotation,bSpawnAsReserve && bVehiclePassenger);
				}
				else
				{
					if (enpcoPrimaryOrders == 2)
					{
						iStartingPathNodeIndex=Rand(GetPathNodeCount(npcbcNew));
					}
					else
					{
						iStartingPathNodeIndex=Rand(GetPathNodeCount(npcbcNew) + 1);
						if (bDebugInit)
						{
							Log(Tag + " trying random node " + iStartingPathNodeIndex);
						}
						if (iStartingPathNodeIndex == GetPathNodeCount(npcbcNew))
						{
							if (bDebugInit)
							{
								Log("Randomly using actual player start location");
							}
							agpPawnNew=Spawn(GetPawnSpawnClass(),,,Location,Rotation,bSpawnAsReserve && bVehiclePassenger);
							iStartingPathNodeIndex=iInitialStartingPathNodeIndex;
						}
					}
					else
					{
						if (Cast<ANPCWaypointPathNode>(GetRequestedPathNode(npcbcNew,iStartingPathNodeIndex)).bNeverRandomSpawnHere || GetRequestedPathNode(npcbcNew,iStartingPathNodeIndex)->IsA(ANPCDoorEntryPathNode::StaticClass()))
						{
							if (bDebugInit)
							{
								Log("Blocked pathnode being skipped for random spawn");
							}
						}
						else
						{
							if (bDebugInit)
							{
								Log(Self + " - waypoint tag: " + sNPCWaypointTag + " using node: " + GetRequestedPathNode(npcbcNew,iStartingPathNodeIndex).Tag);
							}
							agpPawnNew=Spawn(GetPawnSpawnClass(),,,GetRequestedPathNode(npcbcNew,iStartingPathNodeIndex)->GetActorLocation(),GetRequestedPathNode(npcbcNew,iStartingPathNodeIndex).Rotation,bSpawnAsReserve && bVehiclePassenger);
							if (agpPawnNew != nullptr)
							{
								if (! IsA('NPCPlayerStartCommando') && ! IsA('NPCPlayerStartCivilian') && npcaiccCombatController != nullptr)
								{
									if (GetRequestedPathNode(npcbcNew,iStartingPathNodeIndex)->IsA(ANPCCamperFirePositionPathNode::StaticClass()) && npcaiccCombatController.GetSquadRandomAmbushSet(iPlatoonID,iSquadID) == 0 && Cast<ANPCCamperFirePositionPathNode>(GetRequestedPathNode(npcbcNew,iStartingPathNodeIndex)).iSquadAmbushSet > 0)
									{
										npcaiccCombatController.SetSquadRandomAmbushSet(iPlatoonID,iSquadID,NPCCamperFirePositionPathNode(GetRequestedPathNode(npcbcNew,iStartingPathNodeIndex)).iSquadAmbushSet);
									}
								}
								if (bDebugInit)
								{
									Log(Tag + " got a good spawn at random location ( " + iStartingPathNodeIndex + ") of node " + GetRequestedPathNode(npcbcNew,iStartingPathNodeIndex));
								}
								iStartingPathNodeIndex ++;
							}
							else
							{
							}
							if (bOverrideLocation)
							{
								agpPawnNew=Spawn(GetPawnSpawnClass(),,,vOverrideLocation,rotOverride,bSpawnAsReserve && bVehiclePassenger || bTrainingCadre);
							}
							else
							{
								agpPawnNew=Spawn(GetPawnSpawnClass(),,,Location,Rotation,bSpawnAsReserve && bVehiclePassenger || bTrainingCadre);
							}
						}
					}
				}
			}
		}
		if (agpPawnNew == nullptr)
		{
			Log("** WARNING ** " + this + " failure creating pawn """ + GetPawnSpawnClass() + """ for tag: """ + Tag + """");
			return nullptr;
		}
		if (iStartingPathNodeIndex >= npcbcNew.apnPathNodesForPatrol.Num())
		{
			if (bAutoReversePath)
			{
				iStartingPathNodeIndex=npcbcNew.apnPathNodesForPatrol.Num() - 1;
			}
			else
			{
				iStartingPathNodeIndex=1;
			}
		}
		if (bUseRandomStartingNode && ! bStartAndSpawnAtRandomNode)
		{
			iStartingPathNodeIndex=Rand(GetPathNodeCount(npcbcNew) - 1) + 1;
		}
		if (bDebugInit)
		{
			Log("Pawn created: " + agpPawnNew);
		}
		if (agpPawnNew == nullptr)
		{
			npcbcNew.Destroy();
			return nullptr;
		}
		if (bDebugInit)
		{
			Log("Pawn being created, bStartAsDummyPawn: " + bStartAsDummyPawn);
		}
		npcbcNew.bStartAsDummyPawn=bStartAsDummyPawn;
		npcbcNew.bDummyPawnLoopIdleAnim=bDummyPawnLoopIdleAnim;
		npcbcNew.bDummyPawnIgnoreAllEvents=bDummyPawnIgnoreAllEvents;
		npcbcNew.fpAnimFreezeTime=fpAnimFreezeTime;
		npcbcNew.AnimSequence=AnimSequence;
		npcbcNew.AnimRate=AnimRate;
		npcbcNew.AnimTime=AnimTime;
		npcbcNew.AnimChannel=AnimChannel;
		npcbcNew.EventLab=EventLab;
		npcbcNew.Tag=Tag;
		if (nameInitAnimSequence != "None")
		{
			agpPawnNew.AnimSequence=nameInitAnimSequence;
		}
		if (anpcassNPCIdleAnimations.Num() > 0)
		{
			npcbcNew.anpcassNPCIdleAnimations.insert (0,anpcassNPCIdleAnimations.Num());
			for (iAnim=0; iAnim<anpcassNPCIdleAnimations.Num(); iAnim++)
			{
				npcbcNew.anpcassNPCIdleAnimations[iAnim].animStart=anpcassNPCIdleAnimations[iAnim].animStart;
				npcbcNew.anpcassNPCIdleAnimations[iAnim].animMiddle=anpcassNPCIdleAnimations[iAnim].animMiddle;
				npcbcNew.anpcassNPCIdleAnimations[iAnim].AnimEnd=anpcassNPCIdleAnimations[iAnim].AnimEnd;
				npcbcNew.anpcassNPCIdleAnimations[iAnim].bShoulderWeaponFirst=anpcassNPCIdleAnimations[iAnim].bShoulderWeaponFirst;
			}
		}
		npcbcNew.bTrainingCadre=bTrainingCadre;
		if (Cast<AAGP_GameInfo>(GetGameMode()).fpAIDifficultyLevelMentalStateModifer > 0)
		{
			npcbcNew.iNPCInitialMentalState=iNPCInitialMentalState * Cast<AAGP_GameInfo>(GetGameMode()).fpAIDifficultyLevelMentalStateModifer;
			if (npcbcNew.iNPCInitialMentalState > 99)
			{
				npcbcNew.iNPCInitialMentalState=99;
			}
		}
		else
		{
			npcbcNew.iNPCInitialMentalState=iNPCInitialMentalState;
		}
		npcbcNew.iNPCLeadershipMentalStateBonus=iNPCLeadershipMentalStateBonus;
		npcbcNew.iNPCLeadershipMentalStateRange=iNPCLeadershipMentalStateRange;
		npcbcNew.iNPCTeamID=iNPCTeamID;
		if (Cast<AAGP_GameInfo>(GetGameMode()).fpAIDifficultyLevelHearingModifer > 0)
		{
			npcbcNew.fpNPCHearingRadius=fpNPCHearingRadius * Cast<AAGP_GameInfo>(GetGameMode()).fpAIDifficultyLevelHearingModifer;
		}
		else
		{
			npcbcNew.fpNPCHearingRadius=fpNPCHearingRadius;
		}
		npcbcNew.fpNPCVisionConeAngle=fpNPCVisionConeAngle;
		npcbcNew.fpMaxDistanceForGuardWandering=fpMaxDistanceForGuardWandering;
		switch(enpcvaVisionAbility)
		{
			case 1:
			npcbcNew.fpNPCMaxVisualRange=1000 * 50;
			break;
			case 2:
			npcbcNew.fpNPCMaxVisualRange=900 * 50;
			break;
			case 3:
			npcbcNew.fpNPCMaxVisualRange=800 * 50;
			break;
			case 4:
			npcbcNew.fpNPCMaxVisualRange=700 * 50;
			break;
			case 5:
			npcbcNew.fpNPCMaxVisualRange=550 * 50;
			break;
			case 6:
			npcbcNew.fpNPCMaxVisualRange=400 * 50;
			break;
			case 7:
			npcbcNew.fpNPCMaxVisualRange=200 * 50;
			break;
			case 8:
			npcbcNew.fpNPCMaxVisualRange=10 * 50;
			break;
			case 0:
			npcbcNew.fpNPCMaxVisualRange=fpNPCMaxVisualRange;
			break;
			default:
		}
		if (bDebugCombat)
		{
			Log("Configured sight range to " + npcbcNew.fpNPCMaxVisualRange + " based on sight option: " + enpcvaVisionAbility);
		}
		npcbcNew.bSupportItemOfInterestSearch=bSupportItemOfInterestSearch;
		npcbcNew.fpItemOfInterestSearchRange=fpItemOfInterestSearchRange;
		if (Cast<AAGP_GameInfo>(GetGameMode()).fpAIDifficultyLevelVisionModifer > 0)
		{
			npcbcNew.fpNPCMaxVisualRange *= Cast<AAGP_GameInfo>(GetGameMode()).fpAIDifficultyLevelVisionModifer;
		}
		if (npcbcNew.fpNPCMaxVisualRange > Level.DistanceFogStart && ! bIgnoreFogDistance)
		{
			npcbcNew.fpNPCMaxVisualRange=Level.DistanceFogStart;
		}
		npcbcNew.bNPCSpeaksEnglish=bNPCSpeaksEnglish;
		npcbcNew.bNPCCanBeHealed=bNPCCanBeHealed;
		if (Cast<AAGP_GameInfo>(GetGameMode()).fpAIDifficultyLevelWeaponAccModifer > 0)
		{
			npcbcNew.fpNPCWeaponAccuracy=fpNPCWeaponAccuracy * Cast<AAGP_GameInfo>(GetGameMode()).fpAIDifficultyLevelWeaponAccModifer;
			if (npcbcNew.fpNPCWeaponAccuracy > 100)
			{
				npcbcNew.fpNPCWeaponAccuracy=100;
			}
		}
		else
		{
			npcbcNew.fpNPCWeaponAccuracy=fpNPCWeaponAccuracy;
		}
		if (Cast<AAGP_GameInfo>(GetGameMode()).fpAIDifficultyLevelExperienceModifer > 0)
		{
			npcbcNew.fNPCExperience=fNPCExperience * Cast<AAGP_GameInfo>(GetGameMode()).fpAIDifficultyLevelExperienceModifer;
			if (npcbcNew.fNPCExperience > 100)
			{
				npcbcNew.fNPCExperience=100;
			}
		}
		else
		{
			npcbcNew.fNPCExperience=fNPCExperience;
		}
		npcbcNew->fNPCLikesToCrouch=fNPCLikesToCrouch;
		npcbcNew->iMinThreatLevel=iMinThreatLevel;
		npcbcNew->bMaleVoice=bMaleVoice;
		npcbcNew->iVoiceIndex=iVoiceIndex;
		npcbcNew->fpVoicePitch=fpVoicePitch;
		npcbcNew->sMovieToPlayOnUse=sMovieToPlayOnUse;
		npcbcNew->sMOSMovieToPlayOnUse=sMOSMovieToPlayOnUse;
		npcbcNew->sndAudioToPlayOnUse=sndAudioToPlayOnUse;
		npcbcNew->iMovieToPlayOnUseFramerate=iMovieToPlayOnUseFramerate;
		npcbcNew->iMOSMovieToPlayOnUseFramerate=iMOSMovieToPlayOnUseFramerate;
		npcbcNew->sMovieTitleForPlayOnUse=sMovieTitleForPlayOnUse;
		npcbcNew->sMovieCaption=sMovieCaption;
		npcbcNew->sMOSMovieTitleForPlayOnUse=sMOSMovieTitleForPlayOnUse;
		npcbcNew->sMOSMovieCaption=sMOSMovieCaption;
		npcbcNew->sRHExternalLinkTitle=sRHExternalLinkTitle;
		npcbcNew->sRHExternalLinkCaption=sRHExternalLinkCaption;
		npcbcNew->fpVolumeMovieToPlayOnUse=fpVolumeMovieToPlayOnUse;
		npcbcNew->sRHModalText=sRHModalText;
		npcbcNew->bUseResumePatrolStartTrigger=bUseResumePatrolStartTrigger;
		npcbcNew->bUsePatrolStartTrigger=bUsePatrolStartTrigger;
		npcbcNew->iStartingPathNodeIndex=iStartingPathNodeIndex;
		npcbcNew->bScanWhenStopped=bScanWhenStopped;
		npcbcNew->fChanceOfStoppingAtNode=fChanceOfStoppingAtNode;
		npcbcNew->bAscendingNodeDirection=bAscendingNodeDirection;
		npcbcNew->bAutoReversePath=bAutoReversePath;
		npcbcNew->fpTurnRate=fpTurnRate;
		npcbcNew->fpRunAnimRate=fpRunAnimRate;
		npcbcNew->bDebugMode=bDebugMode;
		npcbcNew->bDebugPath=bDebugPath;
		npcbcNew->bDebugSenses=bDebugSenses;
		npcbcNew->bDebugCombat=bDebugCombat;
		npcbcNew->bCaptureToActiveLinkedObjective=bCaptureToActiveLinkedObjective;
		npcbcNew->bLikesToCloseDoorBehindSelf=bLikesToCloseDoorBehindSelf;
		npcbcNew->iFragGrenadeCount=iFragGrenadeCount;
		npcbcNew->iSmokeGrenadeCount=iSmokeGrenadeCount;
		npcbcNew->iFlashGrenadeCount=iFlashGrenadeCount;
		npcbcNew->iRPGCount=iRPGCount;
		npcbcNew->iPrimaryWeaponReloads=iPrimaryWeaponReloads;
		if (npcbcNew->IsA(ANPCBaseSoldierController::StaticClass()))
		{
			Cast<ANPCBaseSoldierController>(npcbcNew).iSecondaryWeaponReloads=iSecondaryWeaponReloads;
		}
		npcbcNew->i203Rounds=i203Rounds;
		npcbcNew->bHasBinoculars=bHasBinoculars;
		if (Cast<AAGP_GameInfo>(GetGameMode()).fpAIDifficultyLevelMortarSkillModifer > 0)
		{
			npcbcNew.fpMortarRequestSkill=fpMortarRequestSkill * Cast<AAGP_GameInfo>(GetGameMode()).fpAIDifficultyLevelMortarSkillModifer;
			if (npcbcNew.fpMortarRequestSkill > 100)
			{
				npcbcNew.fpMortarRequestSkill=100;
			}
		}
		else
		{
			npcbcNew.fpMortarRequestSkill=fpMortarRequestSkill;
		}
		if (Cast<AAGP_GameInfo>(GetGameMode()).fpAIDifficultyLevelWeaponRangeModifer > 0)
		{
			npcbcNew.fpNPCWeaponEffectiveRange=fpNPCWeaponEffectiveRange * Cast<AAGP_GameInfo>(GetGameMode()).fpAIDifficultyLevelWeaponRangeModifer;
		}
		else
		{
			npcbcNew.fpNPCWeaponEffectiveRange=fpNPCWeaponEffectiveRange;
		}
		if (namePrimaryWeapon == nullptr && ! bNoDefaultWeapons && Len(sPrimaryWeaponDefaultClass) > 0)
		{
			npcbcNew.namePrimaryWeapon=class<AGP_Weapon>(DynamicLoadObject(sPrimaryWeaponDefaultClass,Class'Class'));
		}
		else
		{
			npcbcNew.namePrimaryWeapon=namePrimaryWeapon;
		}
		if (nameSecondaryWeapon == nullptr && ! bNoDefaultWeapons && Len(sSecondaryWeaponDefaultClass) > 0)
		{
			npcbcNew.nameSecondaryWeapon=class<AGP_Weapon>(DynamicLoadObject(sSecondaryWeaponDefaultClass,Class'Class'));
		}
		else
		{
			npcbcNew.nameSecondaryWeapon=nameSecondaryWeapon;
		}
		npcbcNew->iSquadID=iSquadID;
		npcbcNew->iFireteamID=iFireteamID;
		npcbcNew->iPlatoonID=iPlatoonID;
		if (aoAttachments.Num() > 0)
		{
			npcbcNew.aoAttachments.insert (0,aoAttachments.Num());
			for (iAttach=0; iAttach<aoAttachments.Num(); iAttach++)
			{
				npcbcNew.aoAttachments[iAttach].Attachment=aoAttachments[iAttach].Attachment;
				npcbcNew.aoAttachments[iAttach].Bone=aoAttachments[iAttach].Bone;
				npcbcNew.aoAttachments[iAttach].LocationOffset=aoAttachments[iAttach].LocationOffset;
				npcbcNew.aoAttachments[iAttach].RotationOffset=aoAttachments[iAttach].RotationOffset;
				npcbcNew.aoAttachments[iAttach].bUseParentScale=aoAttachments[iAttach].bUseParentScale;
				npcbcNew.aoAttachments[iAttach].Scale=aoAttachments[iAttach].Scale;
			}
		}
		*/

		switch(enpcoPrimaryOrders)
		{
			case ENPCOrders::NPCOrder_Guard:
				npcbcNew->iNPCPrimaryOrders = 1;
				break;
			case ENPCOrders::NPCOrder_Ambush:
				npcbcNew->iNPCPrimaryOrders = 2;
				break;
			case ENPCOrders::NPCOrder_Harass:
				npcbcNew->iNPCPrimaryOrders = 5;
				break;
			case ENPCOrders::NPCOrder_Assault:
				npcbcNew->iNPCPrimaryOrders = 9;
				break;
			case ENPCOrders::NPCOrder_Patrol:
				npcbcNew->iNPCPrimaryOrders = 0;
				break;
			default:
				npcbcNew->iNPCPrimaryOrders = 0;
				break;
		}

		//npcbcNew.fpDelayedInitialOrderExecutionTime=fpDelayedInitialOrderExecutionTime;

		switch(enptoTacticalOrders)
		{
			case ENPCTacticalOrders::NPCTO_CeaseFire:
				npcbcNew->iNPCTacticalOrders=100;
				break;
			case ENPCTacticalOrders::NPCTO_HoldFire:
				npcbcNew->iNPCTacticalOrders=200;
				break;
			case ENPCTacticalOrders::NPCTO_ControlledFire:
				npcbcNew->iNPCTacticalOrders=300;
				break;
			case ENPCTacticalOrders::NPCTO_FreeFire:
				npcbcNew->iNPCTacticalOrders=400;
				break;
			default:
				npcbcNew->iNPCTacticalOrders=100;
				break;
		}

		/*
		npcbcNew.anpccpConversations.insert (0,anpccpConversationList.Num());
		for (iConv=0; iConv<anpccpConversationList.Num(); iConv++)
		{
			npcbcNew.anpccpConversations[iConv]=anpccpConversationList[iConv];
			npcbcNew.anpccpConversations[iConv].bConversationPackOwnedByNPC=true;
		}
		if (PawnTag != "None")
		{
			agpPawnNew.Tag=PawnTag;
		}
		else
		{
			agpPawnNew.Tag=Tag;
		}
		if (ControllerTag != "None")
		{
			npcbcNew.Tag=ControllerTag;
		}
		else
		{
			npcbcNew.Tag=Tag;
		}
		agpPawnNew.SoundRadius=160;
		agpPawnNew.HUDText=HUDText;
		if (Len(HUDText) > 0)
		{
			npcbcNew.sNPCName=HUDText;
		}
		else
		{
			switch(GetPawnSpawnClass())
			{
				case "AGP_Characters.NPC_ISoldier":
				case "AGP_Characters.NPC_ISoldierGrunt":
				case "AGP_Characters.NPC_ISoldierGruntA":
				case "AGP_Characters.NPC_ISoldierGruntB":
				npcbcNew.sNPCName="Enemy Soldier";
				break;
				case "AGP_Characters.NPC_ISoldierNCO":
				npcbcNew.sNPCName="Enemy NCO";
				break;
				case "AGP_Characters.NPC_ISoldierOfficer":
				npcbcNew.sNPCName="Enemy Officer";
				break;
				case "AGP_Characters.NPC_EnemyCommando":
				npcbcNew.sNPCName="Enemy Commando";
				break;
				case "AGP_Characters.NPC_ISoldierSpotter":
				npcbcNew.sNPCName="Enemy Spotter";
				break;
				case "AGP_Characters.NPC_Civilian":
				default:
				npcbcNew.sNPCName="Non-Combatant";
				break;
			}
		}
		npcbcNew.bEnableUseToActivateTrigger=bEnableUseToActivateTrigger;
		npcbcNew.TriggerToActivate=TriggerToActivate;
		npcbcNew.bTriggerLinkedToObjective=bTriggerLinkedToObjective;
		npcbcNew.iNPCHealthLevelToTrigger=iNPCHealthLevelToTrigger;
		npcbcNew.ReportedEvent=ReportedEvent;
		npcbcNew.iReportEventDistance=iReportEventDistance;
		npcbcNew.bReportableCivi=bReportableCivi;
		npcbcNew.fpAudioFullVolumeRadius=fpAudioFullVolumeRadius;
		if (asndIdleRandomAudio.Num() > 0)
		{
			npcbcNew.asndIdleRandomAudio.insert (0,asndIdleRandomAudio.Num());
			for (iSound=0; iSound<asndIdleRandomAudio.Num(); iSound++)
			{
				npcbcNew.asndIdleRandomAudio[iSound]=asndIdleRandomAudio[iSound];
			}
		}
		npcbcNew.bUseLipSynch=bUseLipSynch;
		if (anameIdleRandomLipSyncAudio.Num() > 0)
		{
			npcbcNew.anameIdleRandomLipSyncAudio.insert (0,anameIdleRandomLipSyncAudio.Num());
			for (iSound=0; iSound<anameIdleRandomLipSyncAudio.Num(); iSound++)
			{
				npcbcNew.anameIdleRandomLipSyncAudio[iSound]=anameIdleRandomLipSyncAudio[iSound];
			}
		}
		npcbcNew.bPlayOnPlayerSight=bPlayOnPlayerSight;
		npcbcNew.fpAudioTriggerRangeToPlayerUU=fpAudioTriggerRangeToPlayerUU;
		npcbcNew.fpUnmanagedAudioMinDelayTime=fpUnmanagedAudioMinDelayTime;
		agpPawnNew.SetDrawScale(fpPawnScale);
		npcbcNew.bUseFastSprint=bUseFastSprint;
		ConfigurePawn(npcbcNew,agpPawnNew);
		CustomCreation(npcbcNew,agpPawnNew);
		if (bDebugInit)
		{
			Log("Telling controller " + npcbcNew + " to possess pawn: " + agpPawnNew);
		}
		npcbcNew.Possess(agpPawnNew);
		if (npcbcNew->IsA(ANPCBaseSoldierController::StaticClass()))
		{
			RegisterControllerWithAICC(Cast<ANPCBaseSoldierController>(npcbcNew),npcpnStartingPathNode);
			Cast<ANPCBaseSoldierController>(npcbcNew).fpBOPMajorAdvantageThreshold=fpBOPMajorAdvantageThreshold;
			Cast<ANPCBaseSoldierController>(npcbcNew).fpBOPMinorAdvantageThreshold=fpBOPMinorAdvantageThreshold;
			Cast<ANPCBaseSoldierController>(npcbcNew).fpBOPMinorDisadvantageThreshold=fpBOPMinorDisadvantageThreshold;
			Cast<ANPCBaseSoldierController>(npcbcNew).fpBOPMajorDisadvantageThreshold=fpBOPMajorDisadvantageThreshold;
		}
		npcbcNew.StartSpot=Self;
		agpPawnNew.bIgnoresFog=bIgnoreFogDistance;
		if (agpPawnNew.SightRadius < npcbcNew.fpNPCMaxVisualRange)
		{
			agpPawnNew.SightRadius=npcbcNew.fpNPCMaxVisualRange;
		}
		*/
		if (! bVehiclePassenger)
		{
			//agpPawnNew->SetCollision(true,True,true);
		}
		if (bSpawnAsReserve)
		{
			//npcbcNew->Start();
		}
		
		if (bDebugInit)
		{
			//Log("Block Karma: " + agpPawnNew.bBlockKarma);
		}
		return npcbcNew;
}

void ANPCPlayerStart::FindAICC()
{
	ANPCAICombatController* npcaiccIterator = nullptr;
	if (npcaiccCombatController != nullptr)
	{
		return;
	}
	/*
	ForEach AllActors('NPCAICombatController',npcaiccIterator)
	{
		if (bDebugInit)
		{
			Log("Found AICC for team " + npcaiccIterator.iTeamID + ", need team " + iNPCTeamID);
		}
		if (npcaiccIterator.iTeamID == iNPCTeamID)
		{
			if (! npcaiccIterator.bDisableCombatController)
			{
				if (bDebugInit)
				{
					Log(Self + " Located combat controller!");
				}
				npcaiccCombatController=npcaiccIterator;
				return;
			}
		}
	}
	*/
}

void ANPCPlayerStart::RegisterControllerWithAICC(ANPCBaseSoldierController* npcbc, ANPCPathNode* npcpnStart)
{
	FindAICC();
	if (npcaiccCombatController != nullptr)
	{
		if (bDebugInit)
		{
			//Log(npcbc + " Registered with combat controller!");
		}
		npcaiccCombatController->RegisterWithCombatController(npcbc);
	}
}

void ANPCPlayerStart::ConfigurePawn(ANPCBaseController* npbcController, AAGP_Pawn* agpPawnNew)
{
	if (bUserSetSkin)
	{
		if (setPants != nullptr)
		{
			agpPawnNew->Skins[0]=setPants;
			agpPawnNew->Skins[1]=setShirt;
			agpPawnNew->Skins[2]=setHands;
			agpPawnNew->Skins[3]=setFace;
		}
		if (meshPawn != nullptr)
		{
			//agpPawnNew->LinkMesh(meshPawn,true);
		}
		if (bDebugInit)
		{
			//Log("Setting NPC " + Tag + " to mesh: " + meshPawn);
		}
	}
	agpPawnNew->RagdollOverride=RagdollOverride;
	agpPawnNew->RagdollLifeSpan=RagdollLifeSpan;
	agpPawnNew->RagInvInertia=RagInvInertia;
	agpPawnNew->RagDeathVel=RagDeathVel;
	agpPawnNew->RagShootStrength=RagShootStrength;
	agpPawnNew->RagSpinScale=RagSpinScale;
	agpPawnNew->RagDeathUpKick=RagDeathUpKick;
	agpPawnNew->RagProneProjectileScale=RagProneProjectileScale;
	agpPawnNew->bNPCDisableSkinSwapping=true;
	//agpPawnNew->bSeesThroughDecomeshes=bSeesThroughDecomeshes;
}

AAGP_Pawn* ANPCPlayerStart::GetPawnSpawnClass()
{
	return PawnSpawnClass;
}

int32 ANPCPlayerStart::GetPathNodeCount(ANPCBaseController* npcbc)
{
	/*
		int32 iNodeIndex;
		int32 iTotalCamperNodesFound;
		FindAICC();
		if (npcbc->IsA(ANPCBaseSoldierController::StaticClass()) && enpcoPrimaryOrders == 2)
		{
			if (bDebugInit)
			{
				Log(Self + "." + sNPCWaypointTag + " has ambush orders with firing nodes: " + Cast<ANPCBaseSoldierController>(npcbc).anpcfppnFiringPositions.Num());
			}
			for (iNodeIndex=0; iNodeIndex<NPCBaseSoldierController(npcbc).anpcfppnFiringPositions.Num(); iNodeIndex++)
			{
				if (bDebugInit)
				{
					Log(Self + "." + sNPCWaypointTag + " testing node " + iNodeIndex + ": " + Cast<ANPCBaseSoldierController>(npcbc).anpcfppnFiringPositions[iNodeIndex].Tag + " - " + Cast<ANPCBaseSoldierController>(npcbc).anpcfppnFiringPositions[iNodeIndex]);
				}
				if (Cast<ANPCBaseSoldierController>(npcbc).anpcfppnFiringPositions[iNodeIndex]->IsA(ANPCCamperFirePositionPathNode::StaticClass()) && Cast<ANPCCamperFirePositionPathNode>(Cast<ANPCBaseSoldierController>(npcbc).anpcfppnFiringPositions[iNodeIndex]).Tag ~= sNPCWaypointTag)
				{
					if (bDebugInit)
					{
						Log(Self + "." + sNPCWaypointTag + " looking for ambush set " + npcaiccCombatController.GetSquadRandomAmbushSet(iPlatoonID,iSquadID) + ", found " + Cast<ANPCCamperFirePositionPathNode>(Cast<ANPCBaseSoldierController>(npcbc).anpcfppnFiringPositions[iNodeIndex]).iSquadAmbushSet);
					}
					if (! IsA('NPCPlayerStartCommando') && ! IsA('NPCPlayerStartCivilian') && npcaiccCombatController != nullptr && npcaiccCombatController.GetSquadRandomAmbushSet(iPlatoonID,iSquadID) > 0 && npcaiccCombatController.GetSquadRandomAmbushSet(iPlatoonID,iSquadID) != Cast<ANPCCamperFirePositionPathNode>(Cast<ANPCBaseSoldierController>(npcbc).anpcfppnFiringPositions[iNodeIndex]).iSquadAmbushSet)
					{
					}
					if (bDebugInit)
					{
						Log(Self + "." + Tag + " found non-ambush set firing position tagged" + Cast<ANPCBaseSoldierController>(npcbc).anpcfppnFiringPositions[iNodeIndex]);
					}
					iTotalCamperNodesFound ++;
				}
			}
			if (iTotalCamperNodesFound > 0)
			{
				if (bDebugInit)
				{
					Log(Self + "." + Tag + " Found at least one tagged camper node: " + iTotalCamperNodesFound);
				}
				bCamperNodesFound=true;
				return iTotalCamperNodesFound;
			}
			return Cast<ANPCBaseSoldierController>(npcbc).anpcfppnFiringPositions.Num();
		}
		else
		{
			return npcbc.apnPathNodesForPatrol.Num();
		}
	*/
	return 0;     //FAKE   /ELiZ
}

APathNode* ANPCPlayerStart::GetRequestedPathNode(ANPCBaseController* npcbc, int32 iPathNodeIndex)
{
	int32 iNodeIndex = 0;
	int32 iTotalCamperNodesFound = 0;
	if (npcbc->IsA(ANPCBaseSoldierController::StaticClass()) && enpcoPrimaryOrders == ENPCOrders::NPCOrder_Ambush)
	{
		if (bCamperNodesFound)
		{
			for (iNodeIndex=0; iNodeIndex<Cast<ANPCBaseSoldierController>(npcbc)->anpcfppnFiringPositions.Num(); iNodeIndex++)
			{
				/*
				if (Cast<ANPCBaseSoldierController>(npcbc)->anpcfppnFiringPositions[iNodeIndex]->IsA(ANPCCamperFirePositionPathNode::StaticClass()) && Cast<ANPCCamperFirePositionPathNode>(Cast<ANPCBaseSoldierController>(npcbc)->anpcfppnFiringPositions[iNodeIndex]).Tag.Compare(sNPCWaypointTag,ESearchCase::IgnoreCase))
				{
					if (! IsA(ANPCPlayerStartCommando::StaticClass()) && ! IsA(ANPCPlayerStartCivilian::StaticClass()) && npcaiccCombatController != nullptr && npcaiccCombatController.GetSquadRandomAmbushSet(iPlatoonID,iSquadID) > 0 && npcaiccCombatController.GetSquadRandomAmbushSet(iPlatoonID,iSquadID) != Cast<ANPCCamperFirePositionPathNode>(Cast<ANPCBaseSoldierController>(npcbc)->anpcfppnFiringPositions[iNodeIndex]).iSquadAmbushSet)
					{
					}
					if (bDebugInit)
					{
						//Log(Self + ".GetRequestedPathNode() - found a potential ambush location " + Cast<ANPCBaseSoldierController>(npcbc).anpcfppnFiringPositions[iNodeIndex]);
					}
					if (iTotalCamperNodesFound ++== iPathNodeIndex)
					{
						return Cast<ANPCBaseSoldierController>(npcbc)->anpcfppnFiringPositions[iNodeIndex];
					}
				}
				*/
			}
		}
		return Cast<ANPCBaseSoldierController>(npcbc)->anpcfppnFiringPositions[iPathNodeIndex];
	}
	else
	{
		return npcbc->apnPathNodesForPatrol[iPathNodeIndex];
	}
	return nullptr;    //FAKE   /EliZ
}

void ANPCPlayerStart::SetInitialPrimaryOrders(int32 iOrderIndex)
{
	switch(iOrderIndex)
	{
		case 0:
			enpcoPrimaryOrders = ENPCOrders::NPCOrder_Patrol;
			break;
		case 1:
			enpcoPrimaryOrders = ENPCOrders::NPCOrder_Guard;
			break;
		case 2:
			enpcoPrimaryOrders = ENPCOrders::NPCOrder_Ambush;
			break;
		case 3:
			enpcoPrimaryOrders = ENPCOrders::NPCOrder_Harass;
			break;
		default:
			break;
	}
}
