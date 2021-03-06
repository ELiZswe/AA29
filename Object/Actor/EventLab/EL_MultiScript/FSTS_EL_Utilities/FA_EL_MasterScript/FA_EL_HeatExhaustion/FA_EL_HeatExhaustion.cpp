// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FA_EL_MasterScript/FA_EL_HeatExhaustion/FA_EL_HeatExhaustion.h"
#include "AA29/Object/Actor/FSTS_FA_MedicalPickups/FA_CanteenPickup/FA_CanteenPickup.h"
#include "AA29/Object/Actor/FSTS_FA_MedicalPickups/FA_CanvasShadePickup/FA_CanvasShadePickup.h"
#include "AA29/Object/Actor/FSTS_FA_MedicalAttachment/FA_HeatExhaustionRuckSackAttachm/FA_HeatExhaustionRuckSackAttachm.h"
#include "AA29/Object/Actor/FSTS_FA_MedicalAttachment/FA_LeftBootAttachment/FA_LeftBootAttachment.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FA_NPC_HeatExhaustionMannequin.h"
#include "AA29/Object/Actor/FSTS_FA_MedicalAttachment/FA_RightBootAttachment/FA_RightBootAttachment.h"
#include "AA29/Object/Actor/FSTS_FA_MedicalPickups/FA_RucksackPickup/FA_RucksackPickup.h"
#include "AA29/Object/Actor/FSTS_HelpMarker/FSTS_HelpMarker.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_NPC_DrillSergeant.h"

AFA_EL_HeatExhaustion::AFA_EL_HeatExhaustion()
{
	bGetFirstCanteen = true;
	DrillSergeantTag = "FA_NPC_DS_Koch";
	StationObjectiveTag = "Station6Objective";
	StationBeginPointTag = "Station_6_Stand_Point";
	bStartFromDrillSergeantUse = true;
	bFadeMoveFromDrillSergeantUse = true;
	StationName = "Heat Exhaustion Treatment";
	HelpInfoList = {
		FHelpInfo({ "SetupShade",30,"Press the <Action> key on the canvas to","set up a makeshift shade","fa_station6_10",nullptr }),
		FHelpInfo({ "LooseClothing",30,"Press the <Action> key on the mannequin's shirt","and boots to loosen them","fa_station6_10",nullptr }),
		FHelpInfo({ "PickupCanteen",30,"Press the <Action> key on the marked canteen to pick it up","","fa_station6_10",nullptr }),
		FHelpInfo({ "PourWaterOnChest",30,"Press the <Action> key on the mannequin's chest to pour water on him","","fa_station6_10",nullptr }),
		FHelpInfo({ "GiveWaterToDrink",30,"Press the <Action> key on the mannequin's head to give him a drink","","fa_station6_10",nullptr }),
		FHelpInfo({ "PickupRucksack",30,"Press the <Action> key on the rucksack to pick it up","","fa_station6_10",nullptr }),
		FHelpInfo({ "RaiseLegs",30,"Press the <Action> key on the mannequin's legs to elevate them","","fa_station6_10",nullptr }),
	};
	bDormant = true;
	bMasterScript = false;
	bDoGeneralInit = false;
}

/*
simulated State ActiveExecute
{
	simulated Function BeginState()
	{
		Log("Beginning ActiveExecute state for " + FString::FromInt(this));
		ActivatePlayerBlocking(GetPlayerBlockingVolume("Station6_StartBlock"));
		ActivatePlayerBlocking(GetPlayerBlockingVolume("Station6_EndBlock"));
		ForceDrawPlayerCrosshair(true);
	}
	simulated Function NotifyFadeMoveStart(FName PlayerMoveName)
	{
		SetDrillSergeantParams(false,false,false);
	}
	simulated Function NotifyFadeMoveMiddle(FName PlayerMoveName)
	{
		SetPlayerWeapon(false,true);
		DeactivateHelpMarker(HelpMarker);
	}
	simulated Function NotifyFadeMoveEnd(FName PlayerMoveName)
	{
		PlayerLock(false,false);
		ForcePlayerCrouch(true);
		PlayerLock(true,false);
		PlayTip("Station 6 - Heat Exhaustion Treatment","",5);
		PlayLSAnim("fa_station6_1",DrillSergeant);
	}
	simulated Function LMouseClickEvent()
	{
	}
	simulated Function bool Timer_LSAnim(FName LSName)
	{
		Log(string(this) + " Timer_LSAnim called for " + FString::FromInt(LSName));
		switch(LSName)
		{
			case "fa_station6_1":
			PlayLSAnim("fa_station6_3",DrillSergeant);
			return true;
			case "fa_station6_2":
			return true;
			case "fa_station6_3":
			PlayTip("Press the <Action> key on the canvas to","set up a makeshift shade.",4);
			StartHelpTimer(0,true);
			SetHelpMarker(HelpMarker,CanvasShadePickup->GetActorLocation(),HelpMarkerSmallOffset,true);
			CanvasShadeState=1;
			CanvasShadePickup.bUseActionIcon=true;
			return true;
			case "fa_station6_4":
			return true;
			case "fa_station6_5":
			PlayTip("Press the <Action> key on the mannequin's shirt","and boots to loosen them.",4);
			StartHelpTimer(1,true);
			RightBootState=2;
			LeftBootState=2;
			ShirtState=2;
			SetHelpMarker(ExtraHelpMarker1,HeatExhaustionMannequin.GetBoneCoords("RFoot").Origin,HelpMarkerSmallOffset,true);
			SetHelpMarker(ExtraHelpMarker2,HeatExhaustionMannequin.GetBoneCoords("LFoot").Origin,HelpMarkerSmallOffset,true);
			SetHelpMarker(HelpMarker,HeatExhaustionMannequin.GetBoneCoords("Spine02").Origin,(HelpMarkerSmallOffset + FVector(0,0,10)),true);
			return true;
			case "fa_station6_6":
			PlayTip("Press the <Action> key on the marked canteen to pick it up.","",4);
			StartHelpTimer(2,true);
			Canteen1State=1;
			SetHelpMarker(HelpMarker,Canteen1->GetActorLocation(),HelpMarkerSmallOffset,true);
			Canteen1.bUseActionIcon=true;
			return true;
			case "fa_station6_7":
			PlayTip("Press the <Action> key on the marked canteen to pick it up.","",4);
			StartHelpTimer(2,true);
			Canteen2State=1;
			SetHelpMarker(HelpMarker,Canteen2->GetActorLocation(),HelpMarkerSmallOffset,true);
			Canteen2.bUseActionIcon=true;
			return true;
			case "fa_station6_8":
			PlayTip("Press the <Action> key on the rucksack to pick it up.","",4);
			StartHelpTimer(5,true);
			RucksackState=1;
			SetHelpMarker(HelpMarker,RucksackPickup->GetActorLocation(),HelpMarkerSmallOffset,true);
			RucksackPickup.bUseActionIcon=true;
			return true;
			case "fa_station6_9":
			StationCompleted();
			return true;
			case "fa_station6_10":
			break;
			default:
		}
		return false;
	}
	simulated Function StationCompleted()
	{
		PlayTip("Station 6 - Heat Exhaustion Treatment Completed","",6);
		LogStationEnd(this,true);
		bStationComplete=true;
		PlayerLock(true,true);
		StationObjective.SetDisabled(true);
		MissionComplete();
	}
	simulated Function bool Timer_Timer(FName TimerName)
	{
		HandleHelpTimerEvent(TimerName);
		switch(TimerName)
		{
			case "DrinkWaterEnd":
			PlayLSAnim("fa_station6_2",DrillSergeant);
			break;
			default:
		}
		return true;
	}
	simulated Function ActorProximityAlert(AActor* ProximityActor, FName AlertTag)
	{
	}
	simulated Function MannequinTrace(AActor* HitActor, FBoneInfo HitBone)
	{
		AFA_NPC_HeatExhaustionMannequin* Mannequin = nullptr;
		if (((HitActor == nullptr) || (! HitActor->IsA(AFA_NPC_HeatExhaustionMannequin::StaticClass()))) || (HitBone.HitBone == 0))
		{
			Log("Unable to run MannequinTrace(), improper parameters");
			return;
		}
		Mannequin=FA_NPC_HeatExhaustionMannequin(HitActor);
		Log("HitBone is " + HitBone.Name + " and BoneRegion is " + FString::FromInt(GetEnum(Enum'Core.Object.EBoneRegion',HitBone.BoneRegion)));
		switch(HitBone.BoneRegion)
		{
			case 1:
			if (Canteen2State == 2)
			{
				StopHelpTimer();
				GiveMannequinADrink();
				Canteen2State=3;
				DeactivateHelpMarker(HelpMarker);
			}
			break;
			case 2:
			case 3:
			if (ShirtState == 2)
			{
				Mannequin.SwitchChestTextures();
				ShirtState=3;
				DeactivateHelpMarker(HelpMarker);
				if (AllClothesLoosened())
				{
					FinishedLooseningClothes();
				}
			}
			if (Canteen1State == 2)
			{
				StopHelpTimer();
				PourWaterOnMannequin();
				Mannequin.SwitchChestTextures2();
				Canteen1State=3;
				DeactivateHelpMarker(HelpMarker);
			}
			break;
			case 4:
			case 5:
			break;
			case 6:
			case 7:
			if (LeftBootState == 2)
			{
				LeftBootState=3;
				Mannequin.LeftBoot.SwitchToAltStaticMesh();
				DeactivateHelpMarker(ExtraHelpMarker2);
				if (AllClothesLoosened())
				{
					FinishedLooseningClothes();
				}
			}
			if (bElevateLegs)
			{
				ElevateLegs();
				DeactivateHelpMarker(HelpMarker);
				DeactivateHelpMarker(ExtraHelpMarker1);
			}
			break;
			case 8:
			case 9:
			break;
			case 10:
			case 11:
			if (RightBootState == 2)
			{
				RightBootState=3;
				Mannequin.RightBoot.SwitchToAltStaticMesh();
				DeactivateHelpMarker(ExtraHelpMarker1);
				if (AllClothesLoosened())
				{
					FinishedLooseningClothes();
				}
			}
			if (bElevateLegs)
			{
				ElevateLegs();
				DeactivateHelpMarker(HelpMarker);
				DeactivateHelpMarker(ExtraHelpMarker1);
			}
			break;
			case 0:
			break;
			default:
		}
	}
	simulated Function HandleMedPickup(AActor* HitActor)
	{
		if ((HitActor == CanvasShadePickup) && (CanvasShadeState == 1))
		{
			CanvasShadeState=3;
			CanvasShadePickup.DisablePickup();
			DeactivateHelpMarker(HelpMarker);
			StopHelpTimer();
			PlayLSAnim("fa_station6_5",DrillSergeant);
		}
		if ((HitActor == Canteen1) || (HitActor == Canteen2))
		{
			HandleCanteenPickup(HitActor);
		}
		if ((HitActor == RucksackPickup) && (RucksackState == 1))
		{
			RucksackState=2;
			RucksackPickup.DisablePickup();
			PlayTip("Press the <Action> key on the mannequin's legs to elevate them.","",4);
			StopHelpTimer();
			StartHelpTimer(6,true);
			SetHelpMarker(HelpMarker,HeatExhaustionMannequin.GetBoneCoords("RLegLow").Origin,HelpMarkerSmallOffset,true);
			SetHelpMarker(ExtraHelpMarker1,HeatExhaustionMannequin.GetBoneCoords("LLegLow").Origin,HelpMarkerSmallOffset,true);
			bElevateLegs=true;
		}
	}
	simulated Function ElevateLegs()
	{
		StopHelpTimer();
		bElevateLegs=false;
		HeatExhaustionMannequin.RaiseLegs();
		RucksackState=3;
	}
	simulated Function HandleCanteenPickup(AActor* HitActor)
	{
		if ((HitActor == Canteen1) && (Canteen1State == 1))
		{
			Canteen1.DisablePickup();
			DeactivateHelpMarker(HelpMarker);
			Canteen1State=2;
			PlayTip("Press the <Action> key on the mannequin's chest to pour water on him.","",5);
			StopHelpTimer();
			StartHelpTimer(3,true);
			SetHelpMarker(HelpMarker,HeatExhaustionMannequin.GetBoneCoords("Spine02").Origin,(HelpMarkerSmallOffset + FVector(0,0,10)),true);
		}
		if ((HitActor == Canteen2) && (Canteen2State == 1))
		{
			Canteen2.DisablePickup();
			DeactivateHelpMarker(HelpMarker);
			Canteen2State=2;
			PlayTip("Press the <Action> key on the mannequin's head to give him a drink.","",5);
			StopHelpTimer();
			StartHelpTimer(4,true);
			SetHelpMarker(HelpMarker,HeatExhaustionMannequin.GetBoneCoords("head").Origin,HelpMarkerSmallOffset,true);
		}
	}
	simulated Function SpawnRuckSack()
	{
		RuckSackAttachment=Spawn(class'FSTS.FA_HeatExhaustionRuckSackAttachment');
		if (RuckSackAttachment != nullptr)
		{
			HeatExhaustionMannequin.AttachToBone(RuckSackAttachment,"Pelvis");
			RuckSackAttachment.SetRotation(GetBoneRotation("Pelvis"));
		}
		PlayTip("The mannequin's legs are elevated.","",4);
		PlayLSAnim("fa_station6_9",DrillSergeant);
	}
	simulated Function PourWaterOnMannequin()
	{
		bGetFirstCanteen=false;
		PlayTip("Water is poured onto the mannequin.","",4);
		PlayLSAnim("fa_station6_7",DrillSergeant);
	}
	simulated Function GiveMannequinADrink()
	{
		PlayTip("The mannequin drinks","(or would if he could...).",4);
		PlayLSAnim("fa_station6_8",DrillSergeant);
	}
	simulated Function bool AllClothesLoosened()
	{
		return (((ShirtState == 3) && (LeftBootState == 3)) && (RightBootState == 3));
	}
	simulated Function FinishedLooseningClothes()
	{
		PlayTip("The mannequin's clothing is loosened.","",4);
		StopHelpTimer();
		PlayLSAnim("fa_station6_6",DrillSergeant);
	}
	simulated Function EndState()
	{
		SetPlayerWeapon(true,false);
		ForceDrawPlayerCrosshair(false);
		Log("Ending ActiveExecute state for " + FString::FromInt(this));
	}
}
*/

void AFA_EL_HeatExhaustion::PostBeginPlay()
{
	Super::PostBeginPlay();
	DoReferenceLinking();
	CreateMarkers();
}

void AFA_EL_HeatExhaustion::DoReferenceLinking()
{
	AActor* SearchActor = nullptr;
	/*
	ForEach AllActors(Class'Actor', SearchActor)
	{
		if (SearchActor.Tag == "FA_CanvasShadePickup")
		{
			CanvasShadePickup = FA_CanvasShadePickup(SearchActor);
		}
		if (SearchActor.Tag == "Cantene1")
		{
			Canteen1 = FA_CanteenPickup(SearchActor);
		}
		if (SearchActor.Tag == "Cantene2")
		{
			Canteen2 = FA_CanteenPickup(SearchActor);
		}
		if (SearchActor.Tag == "FA_NPC_HeatExhaustionMannequin")
		{
			HeatExhaustionMannequin = FA_NPC_HeatExhaustionMannequin(SearchActor);
			HeatExhaustionMannequin.HE_EL_Lab = this;
		}
		if (SearchActor.Tag == "Heat_RucksackPickup")
		{
			RucksackPickup = FA_RucksackPickup(SearchActor);
		}
	}
	*/
	Super::DoReferenceLinking();
}

void AFA_EL_HeatExhaustion::Destroyed()
{
	if (ExtraHelpMarker1 != nullptr)
	{
		ExtraHelpMarker1->Destroy();
	}
	if (ExtraHelpMarker2 != nullptr)
	{
		ExtraHelpMarker2->Destroy();
	}
	if (RuckSackAttachment != nullptr)
	{
		RuckSackAttachment->Destroyed();
	}
	Super::Destroyed();
}

void AFA_EL_HeatExhaustion::CreateMarkers()
{
	Super::CreateMarkers();
	/*
	ExtraHelpMarker1 = Spawn(AFSTS_HelpMarker::StaticClass(), this);
	ExtraHelpMarker1.DeactivateMarker();
	ExtraHelpMarker2 = Spawn(AFSTS_HelpMarker::StaticClass(), this);
	ExtraHelpMarker2.DeactivateMarker();
	*/
}

void AFA_EL_HeatExhaustion::PrepareStation()
{
	/*
	MoveDSKochToStation6();
	SetDrillSergeantParams(true, true, true);
	SetHelpMarker(HelpMarker, DrillSergeant->GetActorLocation(), HelpMarkerLargeOffset, true, true);
	*/
}

void AFA_EL_HeatExhaustion::AssignDrillSergeants(AFSTS_NPC_DrillSergeant* Sergeant)
{
	/*
	DS_Koch = FA_NPC_DS_Koch(Sergeant);
	SetHelpLSActor(DS_Koch);
	Sergeant.EventLab = this;
	*/
}

void AFA_EL_HeatExhaustion::FFDrillSergeantScold()
{
	//DrillSergeant->StopLIPSincAnim();
	StopTimerByType(ETimerType::TT_LSAnim);
	StopTimerByType(ETimerType::TT_Timer);
	PlayLSAnim("fa_StagingArea_5", DrillSergeant,0,0,0,0);
	PlayTip("Watch your aim soldier!", "", 4);
	ForceLevelReset();
}

void AFA_EL_HeatExhaustion::Reset()
{
	/*
	SetDrillSergeantParams(true, true, true);
	StopHelpTimer();
	StationObjective.SetDisabled(false);
	Player.SetLocation(GetActorByTag("Station6_Start").Location);
	Controller.SetRotation(GetActorByTag("Station6_Start").Rotation);
	ShirtState = 0;
	RightBootState = 0;
	LeftBootState = 0;
	CanvasShadeState = 0;
	Canteen1State = 0;
	Canteen2State = 0;
	RucksackState = 0;
	CanvasShadePickup.ActivatePickup();
	Canteen1.ActivatePickup();
	Canteen2.ActivatePickup();
	RucksackPickup.ActivatePickup();
	if (RuckSackAttachment != nullptr)
	{
		RuckSackAttachment.Destroy();
	}
	SetHelpMarker(HelpMarker, DrillSergeant->GetActorLocation(), HelpMarkerLargeOffset, true, true);
	*/
	Super::Reset();
}

bool AFA_EL_HeatExhaustion::AllClothesLoosened()
{
	return false;
}

void AFA_EL_HeatExhaustion::FinishedLooseningClothes()
{
}

void AFA_EL_HeatExhaustion::PourWaterOnMannequin()
{
}

void AFA_EL_HeatExhaustion::GiveMannequinADrink()
{
}

void AFA_EL_HeatExhaustion::HandleCanteenPickup(AActor* HitActor)
{
}

void AFA_EL_HeatExhaustion::SpawnRuckSack()
{
}

void AFA_EL_HeatExhaustion::ElevateLegs()
{
}
