// All the original content belonged to the US Army


#include "NPCPlayerStart.h"
#include "AA29/Controller/AIController/NPCBaseController/NPCBaseController.h"


ANPCPlayerStart::ANPCPlayerStart()
{
	bCanDelaySpawn = true;
		//ControllerClass = class'AGP.NPCBaseController'

	//ControllerClass = ANPCBaseController::StaticClass();

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
	if (meshPawn != nullptr)
	{
		SkeletalMesh->SetSkeletalMesh(meshPawn);
	}
	/*
		local NPCPlayerStart npcPSIter;
		local array<NPCPlayerStart> npcPSSimilarTagArray;
		local int inpcBCSpawner;
		local int iSetCounter;
		BeginPlay();
		if (bRandomGroupSpawn && nRandomGroupTag != 'None')
		{
			ForEach AllActors('NPCPlayerStart',npcPSIter)
			{
				if (nRandomGroupTag == npcPSIter.nRandomGroupTag)
				{
					npcPSSimilarTagArray.insert (0,1);
					npcPSSimilarTagArray[0]=npcPSIter;
				}
			}
			if (npcPSSimilarTagArray.Length > 0)
			{
				inpcBCSpawner=Rand(npcPSSimilarTagArray.Length);
			}
			for (iSetCounter=0; iSetCounter<npcPSSimilarTagArray.Length; iSetCounter++)
			{
				npcPSSimilarTagArray[iSetCounter].bGroupSpawnFieldHolder=npcPSSimilarTagArray[iSetCounter].bRandomGroupSpawn;
				if (iSetCounter == inpcBCSpawner)
				{
					npcPSSimilarTagArray[iSetCounter].bMustSpawn=True;
					npcPSSimilarTagArray[iSetCounter].bRandomGroupSpawn=False;
				}
				else
				{
					npcPSSimilarTagArray[iSetCounter].bMustSpawn=False;
					npcPSSimilarTagArray[iSetCounter].bRandomGroupSpawn=False;
					npcPSSimilarTagArray[iSetCounter].bSpawnable=False;
				}
			}
		}
	*/
}



void ANPCPlayerStart::DebugNavMarker(bool bShowMarker, bool bFinalGoalMarker)
{
	/*
		if (dnpcnDebugNavigationMarker == None)
		{
			if (! bShowMarker)
			{
				Return;
			}
			dnpcnDebugNavigationMarker=Spawn('DebugNPCNavigation');
			dnpcnDebugNavigationMarker.HUDText=Self $ "." $ Tag;
			dnpcnDebugNavigationMarker.SetOwner(Self);
			dnpcnDebugNavigationMarker.Skins[0]=Texture;
		}
		if (dnpcnDebugNavigationMarker != None)
		{
			dnpcnDebugNavigationMarker.SetLocation(Location);
			dnpcnDebugNavigationMarker.bHidden=! bShowMarker;
			if (bShowMarker)
			{
				if (bFinalGoalMarker)
				{
					dnpcnDebugNavigationMarker.SetDrawScale3D(vect(0.15 0.15 0.15));
					dnpcnDebugNavigationMarker.RotationRate.Yaw=16384;
				}
				else
				{
					dnpcnDebugNavigationMarker.SetDrawScale3D(vect(0.075 0.075 0.075));
					dnpcnDebugNavigationMarker.RotationRate.Yaw=4096;
				}
			}
		}
	*/
}
void ANPCPlayerStart::Reset()
{
	Super::Reset();
	bEnabled=false;
	bRandomGroupSpawn=bGroupSpawnFieldHolder;
}

void ANPCPlayerStart::PostBeginPlay()
{
	/*
		local class<AGP_Weapon>  agpw;
		agpw=class<AGP_Weapon>(DynamicLoadObject("AGP_Inventory.Weapon_NPC_RPG7_rocket",Class'Class'));
		if (agpw != None && agpw.Default.PickupClass != None)
		{
			agpw.Default.PickupClass.StaticPrecache(Level);
		}
		if (! namePrimaryWeapon ~= "None")
		{
			agpw=class<AGP_Weapon>(DynamicLoadObject(namePrimaryWeapon,Class'Class'));
			if (agpw != None && agpw.Default.PickupClass != None)
			{
				agpw.Default.PickupClass.StaticPrecache(Level);
			}
		}
		if (! nameSecondaryWeapon ~= "None")
		{
			agpw=class<AGP_Weapon>(DynamicLoadObject(nameSecondaryWeapon,Class'Class'));
			if (agpw != None && agpw.Default.PickupClass != None)
			{
				agpw.Default.PickupClass.StaticPrecache(Level);
			}
		}
		if (Len(sPrimaryWeaponDefaultClass) > 0)
		{
			agpw=class<AGP_Weapon>(DynamicLoadObject(sPrimaryWeaponDefaultClass,Class'Class'));
			if (agpw != None && agpw.Default.PickupClass != None)
			{
				agpw.Default.PickupClass.StaticPrecache(Level);
			}
		}
		if (Len(sSecondaryWeaponDefaultClass) > 0)
		{
			agpw=class<AGP_Weapon>(DynamicLoadObject(sSecondaryWeaponDefaultClass,Class'Class'));
			if (agpw != None && agpw.Default.PickupClass != None)
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
			//Log("Warning!!! No Pawn defined for " $ Self $ " - Not creating a Pawn or Controller!");
			return nullptr;
		}
		if (! ShouldUseStartSpot())
		{
			return nullptr;
		}
		if (bDebugInit)
		{
			//Log("");
			//Log("");
			//Log("");
			//Log("*******************");
			//Log(Self $ " Creating new controller for pawn at start spot: " $ ControllerClass $ " with pawn class: " $ GetPawnSpawnClass());
			//Log("*******************");
		}
		/*
		npcbcNew=Spawn(ControllerClass);

		if (npcbcNew == None)
		{
			Log("** WARNING ** " $ Self $ " Failure creating controller for tag """ $ Tag $ """ using class """ $ ControllerClass $ """");
			Return None;
		}
		npcbcNew.npcpsPlayerStart=Self;
		if (bDebugInit)
		{
			Log("Controller created: " $ npcbcNew);
		}
		if (bDebugInit)
		{
			if (bStartAndSpawnAtRandomNode)
			{
				Log("Creating new pawn at random waypoint node, class: " $ GetPawnSpawnClass());
			}
			else
			{
				Log("Creating new pawn at start spot: " $ GetPawnSpawnClass());
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
			Log("Pathnode waypoint tag is now: " $ npcbcNew.sNPCWaypointTag);
		}
		npcbcNew.PreloadPathNodeList();
		if (bDebugInit)
		{
			if (bStartAndSpawnAtRandomNode)
			{
				Log("Will find random pathnode from " $ npcbcNew.apnPathNodesForPatrol.Length $ " possible nodes");
			}
		}
		iInitialStartingPathNodeIndex=iStartingPathNodeIndex;
		if (agpPawnNew == None)
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
							Log(Tag $ " trying random node " $ iStartingPathNodeIndex);
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
						if (NPCWaypointPathNode(GetRequestedPathNode(npcbcNew,iStartingPathNodeIndex)).bNeverRandomSpawnHere || GetRequestedPathNode(npcbcNew,iStartingPathNodeIndex).IsA('NPCDoorEntryPathNode'))
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
								Log(Self $ " - waypoint tag: " $ sNPCWaypointTag $ " using node: " $ GetRequestedPathNode(npcbcNew,iStartingPathNodeIndex).Tag);
							}
							agpPawnNew=Spawn(GetPawnSpawnClass(),,,GetRequestedPathNode(npcbcNew,iStartingPathNodeIndex).Location,GetRequestedPathNode(npcbcNew,iStartingPathNodeIndex).Rotation,bSpawnAsReserve && bVehiclePassenger);
							if (agpPawnNew != None)
							{
								if (! IsA('NPCPlayerStartCommando') && ! IsA('NPCPlayerStartCivilian') && npcaiccCombatController != None)
								{
									if (GetRequestedPathNode(npcbcNew,iStartingPathNodeIndex).IsA('NPCCamperFirePositionPathNode') && npcaiccCombatController.GetSquadRandomAmbushSet(iPlatoonID,iSquadID) == 0 && NPCCamperFirePositionPathNode(GetRequestedPathNode(npcbcNew,iStartingPathNodeIndex)).iSquadAmbushSet > 0)
									{
										npcaiccCombatController.SetSquadRandomAmbushSet(iPlatoonID,iSquadID,NPCCamperFirePositionPathNode(GetRequestedPathNode(npcbcNew,iStartingPathNodeIndex)).iSquadAmbushSet);
									}
								}
								if (bDebugInit)
								{
									Log(Tag $ " got a good spawn at random location ( " $ iStartingPathNodeIndex $ ") of node " $ GetRequestedPathNode(npcbcNew,iStartingPathNodeIndex));
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
		if (agpPawnNew == None)
		{
			Log("** WARNING ** " $ Self $ " failure creating pawn """ $ GetPawnSpawnClass() $ """ for tag: """ $ Tag $ """");
			Return None;
		}
		if (iStartingPathNodeIndex >= npcbcNew.apnPathNodesForPatrol.Length)
		{
			if (bAutoReversePath)
			{
				iStartingPathNodeIndex=npcbcNew.apnPathNodesForPatrol.Length - 1;
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
			Log("Pawn created: " $ agpPawnNew);
		}
		if (agpPawnNew == None)
		{
			npcbcNew.Destroy();
			Return None;
		}
		if (bDebugInit)
		{
			Log("Pawn being created, bStartAsDummyPawn: " $ bStartAsDummyPawn);
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
		if (nameInitAnimSequence != 'None')
		{
			agpPawnNew.AnimSequence=nameInitAnimSequence;
		}
		if (anpcassNPCIdleAnimations.Length > 0)
		{
			npcbcNew.anpcassNPCIdleAnimations.insert (0,anpcassNPCIdleAnimations.Length);
			for (iAnim=0; iAnim<anpcassNPCIdleAnimations.Length; iAnim++)
			{
				npcbcNew.anpcassNPCIdleAnimations[iAnim].animStart=anpcassNPCIdleAnimations[iAnim].animStart;
				npcbcNew.anpcassNPCIdleAnimations[iAnim].animMiddle=anpcassNPCIdleAnimations[iAnim].animMiddle;
				npcbcNew.anpcassNPCIdleAnimations[iAnim].AnimEnd=anpcassNPCIdleAnimations[iAnim].AnimEnd;
				npcbcNew.anpcassNPCIdleAnimations[iAnim].bShoulderWeaponFirst=anpcassNPCIdleAnimations[iAnim].bShoulderWeaponFirst;
			}
		}
		npcbcNew.bTrainingCadre=bTrainingCadre;
		if (AGP_GameInfo(Level.Game).fpAIDifficultyLevelMentalStateModifer > 0)
		{
			npcbcNew.iNPCInitialMentalState=iNPCInitialMentalState * AGP_GameInfo(Level.Game).fpAIDifficultyLevelMentalStateModifer;
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
		if (AGP_GameInfo(Level.Game).fpAIDifficultyLevelHearingModifer > 0)
		{
			npcbcNew.fpNPCHearingRadius=fpNPCHearingRadius * AGP_GameInfo(Level.Game).fpAIDifficultyLevelHearingModifer;
		}
		else
		{
			npcbcNew.fpNPCHearingRadius=fpNPCHearingRadius;
		}
		npcbcNew.fpNPCVisionConeAngle=fpNPCVisionConeAngle;
		npcbcNew.fpMaxDistanceForGuardWandering=fpMaxDistanceForGuardWandering;
		Switch(enpcvaVisionAbility)
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
			Log("Configured sight range to " $ npcbcNew.fpNPCMaxVisualRange $ " based on sight option: " $ enpcvaVisionAbility);
		}
		npcbcNew.bSupportItemOfInterestSearch=bSupportItemOfInterestSearch;
		npcbcNew.fpItemOfInterestSearchRange=fpItemOfInterestSearchRange;
		if (AGP_GameInfo(Level.Game).fpAIDifficultyLevelVisionModifer > 0)
		{
			npcbcNew.fpNPCMaxVisualRange *= AGP_GameInfo(Level.Game).fpAIDifficultyLevelVisionModifer;
		}
		if (npcbcNew.fpNPCMaxVisualRange > Level.DistanceFogStart && ! bIgnoreFogDistance)
		{
			npcbcNew.fpNPCMaxVisualRange=Level.DistanceFogStart;
		}
		npcbcNew.bNPCSpeaksEnglish=bNPCSpeaksEnglish;
		npcbcNew.bNPCCanBeHealed=bNPCCanBeHealed;
		if (AGP_GameInfo(Level.Game).fpAIDifficultyLevelWeaponAccModifer > 0)
		{
			npcbcNew.fpNPCWeaponAccuracy=fpNPCWeaponAccuracy * AGP_GameInfo(Level.Game).fpAIDifficultyLevelWeaponAccModifer;
			if (npcbcNew.fpNPCWeaponAccuracy > 100)
			{
				npcbcNew.fpNPCWeaponAccuracy=100;
			}
		}
		else
		{
			npcbcNew.fpNPCWeaponAccuracy=fpNPCWeaponAccuracy;
		}
		if (AGP_GameInfo(Level.Game).fpAIDifficultyLevelExperienceModifer > 0)
		{
			npcbcNew.fNPCExperience=fNPCExperience * AGP_GameInfo(Level.Game).fpAIDifficultyLevelExperienceModifer;
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
		if (npcbcNew.IsA('NPCBaseSoldierController'))
		{
			NPCBaseSoldierController(npcbcNew).iSecondaryWeaponReloads=iSecondaryWeaponReloads;
		}
		npcbcNew->i203Rounds=i203Rounds;
		npcbcNew->bHasBinoculars=bHasBinoculars;
		if (AGP_GameInfo(Level.Game).fpAIDifficultyLevelMortarSkillModifer > 0)
		{
			npcbcNew.fpMortarRequestSkill=fpMortarRequestSkill * AGP_GameInfo(Level.Game).fpAIDifficultyLevelMortarSkillModifer;
			if (npcbcNew.fpMortarRequestSkill > 100)
			{
				npcbcNew.fpMortarRequestSkill=100;
			}
		}
		else
		{
			npcbcNew.fpMortarRequestSkill=fpMortarRequestSkill;
		}
		if (AGP_GameInfo(Level.Game).fpAIDifficultyLevelWeaponRangeModifer > 0)
		{
			npcbcNew.fpNPCWeaponEffectiveRange=fpNPCWeaponEffectiveRange * AGP_GameInfo(Level.Game).fpAIDifficultyLevelWeaponRangeModifer;
		}
		else
		{
			npcbcNew.fpNPCWeaponEffectiveRange=fpNPCWeaponEffectiveRange;
		}
		if (namePrimaryWeapon == None && ! bNoDefaultWeapons && Len(sPrimaryWeaponDefaultClass) > 0)
		{
			npcbcNew.namePrimaryWeapon=class<AGP_Weapon>(DynamicLoadObject(sPrimaryWeaponDefaultClass,Class'Class'));
		}
		else
		{
			npcbcNew.namePrimaryWeapon=namePrimaryWeapon;
		}
		if (nameSecondaryWeapon == None && ! bNoDefaultWeapons && Len(sSecondaryWeaponDefaultClass) > 0)
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
		if (aoAttachments.Length > 0)
		{
			npcbcNew.aoAttachments.insert (0,aoAttachments.Length);
			for (iAttach=0; iAttach<aoAttachments.Length; iAttach++)
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
		npcbcNew.anpccpConversations.insert (0,anpccpConversationList.Length);
		for (iConv=0; iConv<anpccpConversationList.Length; iConv++)
		{
			npcbcNew.anpccpConversations[iConv]=anpccpConversationList[iConv];
			npcbcNew.anpccpConversations[iConv].bConversationPackOwnedByNPC=True;
		}
		if (PawnTag != 'None')
		{
			agpPawnNew.Tag=PawnTag;
		}
		else
		{
			agpPawnNew.Tag=Tag;
		}
		if (ControllerTag != 'None')
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
			Switch(GetPawnSpawnClass())
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
		if (asndIdleRandomAudio.Length > 0)
		{
			npcbcNew.asndIdleRandomAudio.insert (0,asndIdleRandomAudio.Length);
			for (iSound=0; iSound<asndIdleRandomAudio.Length; iSound++)
			{
				npcbcNew.asndIdleRandomAudio[iSound]=asndIdleRandomAudio[iSound];
			}
		}
		npcbcNew.bUseLipSynch=bUseLipSynch;
		if (anameIdleRandomLipSyncAudio.Length > 0)
		{
			npcbcNew.anameIdleRandomLipSyncAudio.insert (0,anameIdleRandomLipSyncAudio.Length);
			for (iSound=0; iSound<anameIdleRandomLipSyncAudio.Length; iSound++)
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
			Log("Telling controller " $ npcbcNew $ " to possess pawn: " $ agpPawnNew);
		}
		npcbcNew.Possess(agpPawnNew);
		if (npcbcNew.IsA('NPCBaseSoldierController'))
		{
			RegisterControllerWithAICC(NPCBaseSoldierController(npcbcNew),npcpnStartingPathNode);
			NPCBaseSoldierController(npcbcNew).fpBOPMajorAdvantageThreshold=fpBOPMajorAdvantageThreshold;
			NPCBaseSoldierController(npcbcNew).fpBOPMinorAdvantageThreshold=fpBOPMinorAdvantageThreshold;
			NPCBaseSoldierController(npcbcNew).fpBOPMinorDisadvantageThreshold=fpBOPMinorDisadvantageThreshold;
			NPCBaseSoldierController(npcbcNew).fpBOPMajorDisadvantageThreshold=fpBOPMajorDisadvantageThreshold;
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
			//agpPawnNew->SetCollision(True,True,True);
		}
		if (bSpawnAsReserve)
		{
			//npcbcNew->Start();
		}
		
		if (bDebugInit)
		{
			//Log("Block Karma: " $ agpPawnNew.bBlockKarma);
		}
		return npcbcNew;
}
void ANPCPlayerStart::FindAICC()
{
	/*
		local NPCAICombatController npcaiccIterator;
		if (npcaiccCombatController != None)
		{
			Return;
		}
		ForEach AllActors('NPCAICombatController',npcaiccIterator)
		{
			if (bDebugInit)
			{
				Log("Found AICC for team " $ npcaiccIterator.iTeamID $ ", need team " $ iNPCTeamID);
			}
			if (npcaiccIterator.iTeamID == iNPCTeamID)
			{
				if (! npcaiccIterator.bDisableCombatController)
				{
					if (bDebugInit)
					{
						Log(Self $ " Located combat controller!");
					}
					npcaiccCombatController=npcaiccIterator;
					Return;
				}
			}
		}
	*/
}

void ANPCPlayerStart::RegisterControllerWithAICC(ANPCBaseSoldierController* npcbc, ANPCPathNode* npcpnStart)
{
	/*
		FindAICC();
		if (npcaiccCombatController != None)
		{
			if (bDebugInit)
			{
				Log(npcbc $ " Registered with combat controller!");
			}
			npcaiccCombatController.RegisterWithCombatController(npcbc);
		}
	*/
}


void ANPCPlayerStart::ConfigurePawn(ANPCBaseController* npbcController, AAGP_Pawn* agpPawnNew)
{
	/*
		if (bUserSetSkin)
		{
			if (setPants != None)
			{
				agpPawnNew.Skins[0]=setPants;
				agpPawnNew.Skins[1]=setShirt;
				agpPawnNew.Skins[2]=setHands;
				agpPawnNew.Skins[3]=setFace;
			}
			if (meshPawn != None)
			{
				agpPawnNew.LinkMesh(meshPawn,True);
			}
			if (bDebugInit)
			{
				Log("Setting NPC " $ Tag $ " to mesh: " $ meshPawn);
			}
		}
		agpPawnNew.RagdollOverride=RagdollOverride;
		agpPawnNew.RagdollLifeSpan=RagdollLifeSpan;
		agpPawnNew.RagInvInertia=RagInvInertia;
		agpPawnNew.RagDeathVel=RagDeathVel;
		agpPawnNew.RagShootStrength=RagShootStrength;
		agpPawnNew.RagSpinScale=RagSpinScale;
		agpPawnNew.RagDeathUpKick=RagDeathUpKick;
		agpPawnNew.RagProneProjectileScale=RagProneProjectileScale;
		agpPawnNew.bNPCDisableSkinSwapping=True;
		agpPawnNew.bSeesThroughDecomeshes=bSeesThroughDecomeshes;
	*/
}
AAGP_Pawn* ANPCPlayerStart::GetPawnSpawnClass()
{
	return PawnSpawnClass;
}
void ANPCPlayerStart::GetPathNodeCount(ANPCBaseController* npcbc)
{
	/*
		local int iNodeIndex;
		local int iTotalCamperNodesFound;
		FindAICC();
		if (npcbc.IsA('NPCBaseSoldierController') && enpcoPrimaryOrders == 2)
		{
			if (bDebugInit)
			{
				Log(Self $ "." $ sNPCWaypointTag $ " has ambush orders with firing nodes: " $ NPCBaseSoldierController(npcbc).anpcfppnFiringPositions.Length);
			}
			for (iNodeIndex=0; iNodeIndex<NPCBaseSoldierController(npcbc).anpcfppnFiringPositions.Length; iNodeIndex++)
			{
				if (bDebugInit)
				{
					Log(Self $ "." $ sNPCWaypointTag $ " testing node " $ iNodeIndex $ ": " $ NPCBaseSoldierController(npcbc).anpcfppnFiringPositions[iNodeIndex].Tag $ " - " $ NPCBaseSoldierController(npcbc).anpcfppnFiringPositions[iNodeIndex]);
				}
				if (NPCBaseSoldierController(npcbc).anpcfppnFiringPositions[iNodeIndex].IsA('NPCCamperFirePositionPathNode') && NPCCamperFirePositionPathNode(NPCBaseSoldierController(npcbc).anpcfppnFiringPositions[iNodeIndex]).Tag ~= sNPCWaypointTag)
				{
					if (bDebugInit)
					{
						Log(Self $ "." $ sNPCWaypointTag $ " looking for ambush set " $ npcaiccCombatController.GetSquadRandomAmbushSet(iPlatoonID,iSquadID) $ ", found " $ NPCCamperFirePositionPathNode(NPCBaseSoldierController(npcbc).anpcfppnFiringPositions[iNodeIndex]).iSquadAmbushSet);
					}
					if (! IsA('NPCPlayerStartCommando') && ! IsA('NPCPlayerStartCivilian') && npcaiccCombatController != None && npcaiccCombatController.GetSquadRandomAmbushSet(iPlatoonID,iSquadID) > 0 && npcaiccCombatController.GetSquadRandomAmbushSet(iPlatoonID,iSquadID) != NPCCamperFirePositionPathNode(NPCBaseSoldierController(npcbc).anpcfppnFiringPositions[iNodeIndex]).iSquadAmbushSet)
					{
					}
					if (bDebugInit)
					{
						Log(Self $ "." $ Tag $ " found non-ambush set firing position tagged" $ NPCBaseSoldierController(npcbc).anpcfppnFiringPositions[iNodeIndex]);
					}
					iTotalCamperNodesFound ++;
				}
			}
			if (iTotalCamperNodesFound > 0)
			{
				if (bDebugInit)
				{
					Log(Self $ "." $ Tag $ " Found at least one tagged camper node: " $ iTotalCamperNodesFound);
				}
				bCamperNodesFound=True;
				Return iTotalCamperNodesFound;
			}
			Return NPCBaseSoldierController(npcbc).anpcfppnFiringPositions.Length;
		}
		else
		{
			Return npcbc.apnPathNodesForPatrol.Length;
		}
	*/
}
void ANPCPlayerStart::GetRequestedPathNode(ANPCBaseController* npcbc, int32 iPathNodeIndex)
{
	/*
		local int iNodeIndex;
		local int iTotalCamperNodesFound;
		if (npcbc.IsA('NPCBaseSoldierController') && enpcoPrimaryOrders == 2)
		{
			if (bCamperNodesFound)
			{
				for (iNodeIndex=0; iNodeIndex<NPCBaseSoldierController(npcbc).anpcfppnFiringPositions.Length; iNodeIndex++)
				{
					if (NPCBaseSoldierController(npcbc).anpcfppnFiringPositions[iNodeIndex].IsA('NPCCamperFirePositionPathNode') && NPCCamperFirePositionPathNode(NPCBaseSoldierController(npcbc).anpcfppnFiringPositions[iNodeIndex]).Tag ~= sNPCWaypointTag)
					{
						if (! IsA('NPCPlayerStartCommando') && ! IsA('NPCPlayerStartCivilian') && npcaiccCombatController != None && npcaiccCombatController.GetSquadRandomAmbushSet(iPlatoonID,iSquadID) > 0 && npcaiccCombatController.GetSquadRandomAmbushSet(iPlatoonID,iSquadID) != NPCCamperFirePositionPathNode(NPCBaseSoldierController(npcbc).anpcfppnFiringPositions[iNodeIndex]).iSquadAmbushSet)
						{
						}
						if (bDebugInit)
						{
							Log(Self $ ".GetRequestedPathNode() - found a potential ambush location " $ NPCBaseSoldierController(npcbc).anpcfppnFiringPositions[iNodeIndex]);
						}
						if (iTotalCamperNodesFound ++ == iPathNodeIndex)
						{
							Return NPCBaseSoldierController(npcbc).anpcfppnFiringPositions[iNodeIndex];
						}
					}
				}
			}
			Return NPCBaseSoldierController(npcbc).anpcfppnFiringPositions[iPathNodeIndex];
		}
		else
		{
			Return npcbc.apnPathNodesForPatrol[iPathNodeIndex];
		}
	*/
}
void ANPCPlayerStart::SetInitialPrimaryOrders(int32 iOrderIndex)
{
	/*
		Switch(iOrderIndex)
		{
			case 0:
			enpcoPrimaryOrders=0;
			break;
			case 1:
			enpcoPrimaryOrders=1;
			break;
			case 2:
			enpcoPrimaryOrders=2;
			break;
			case 3:
			enpcoPrimaryOrders=3;
			break;
			default:
		}
	*/
}
