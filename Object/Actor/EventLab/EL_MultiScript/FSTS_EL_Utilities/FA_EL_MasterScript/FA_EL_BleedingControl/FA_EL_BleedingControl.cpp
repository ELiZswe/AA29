// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FA_EL_MasterScript/FA_EL_BleedingControl/FA_EL_BleedingControl.h"
#include "AA29/Object/Actor/FSTS_FA_MedicalAttachment/FA_CATAttachment/FA_CATAttachment.h"
#include "AA29/Object/Actor/FSTS_FA_MedicalPickups/FA_CATPickup/FA_CATPickup.h"
#include "AA29/Object/Actor/FSTS_FA_MedicalAttachment/FA_ETDAttachment/FA_ETDAttachment.h"
#include "AA29/Object/Actor/FSTS_FA_MedicalPickups/FA_ETDPickup/FA_ETDPickup.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FA_NPC_ControlBleedingMannequin.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FA_NPC_TraumaDressingMannequin.h"
#include "AA29/Object/Actor/FSTS_FA_MedicalAttachment/FA_RuckSackAttachment/FA_RuckSackAttachment.h"
#include "AA29/Object/Actor/FSTS_FA_MedicalPickups/FA_RucksackPickup/FA_RucksackPickup.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_NPC_DrillSergeant.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/DSController/DSController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FA_NPC_DS_Kelly.h"
#include <AA29/Object/Actor/Controller/AIController/ScriptedController/DSController/DSController.h>

AFA_EL_BleedingControl::AFA_EL_BleedingControl()
{
	DrillSergeantTag = "FA_NPC_DS_Kelly";
	StationObjectiveTag = "Station3Objective";
	StationBeginPointTag = "Station3_Stand_Point1";
	bAcceptDrillSergeantUse = true;
	bStartFromDrillSergeantUse = true;
	bFadeMoveFromDrillSergeantUse = true;
	StationName = "Control Bleeding";
	HelpInfoList = {
		FHelpInfo({ "CATPickupMsg",30,"Press the <Action> key on the CAT to pick it up","","fa_station5_19",nullptr}),
		FHelpInfo({ "CATApplicationMsg",30,"Press the <Action> key on the mannequin's","arm to apply the CAT to the forearm","fa_station5_19",nullptr }),
		FHelpInfo({ "None",0,"","","None",nullptr }),
		FHelpInfo({ "MarkForehead",30,"Press the <Action> key on the mannequin's","head to write a \"T\"","fa_station5_19",nullptr }),
		FHelpInfo({ "ETDPickupMsg",30,"Press the <Action> key on the ETD to pick it up","","fa_station5_19",nullptr }),
		FHelpInfo({ "ETDApplicationMsg",30,"Press the <Action> key on the","mannequin's leg to apply the ETD","fa_station5_19",nullptr }),
		FHelpInfo({ "RucksackPickupMsg",30,"Press the <Action> key on the rucksack to pick it up","","fa_station5_19",nullptr }),
		FHelpInfo({ "RucksackApplicationMsg",30,"Press the <Action> key on the mannequin's left","leg to raise it and apply pressure","fa_station5_19",nullptr })
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
		ActivatePlayerBlocking(GetPlayerBlockingVolume("Station3_StartBlock"));
		ActivatePlayerBlocking(GetPlayerBlockingVolume("Station3_EndBlock"));
		ForceDrawPlayerCrosshair(true);
	}
	simulated Function NotifyFadeMoveStart(FName PlayerMoveName)
	{
		if (PlayerMoveName == "Station3_Stand_Point1")
		{
			SetDrillSergeantParams(false,false,false);
		}
	}
	simulated Function NotifyFadeMoveMiddle(FName PlayerMoveName)
	{
		if (PlayerMoveName == "Station3_Stand_Point1")
		{
			Cast<ADSController>(DrillSergeant.Controller).Walk();
			Cast<ADSController>(DrillSergeant.Controller).MoveToPoint("Station_5_Instruction_1");
			Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
			SetPlayerWeapon(false,true);
			DeactivateHelpMarker(HelpMarker);
		}
	}
	simulated Function NotifyFadeMoveEnd(FName PlayerMoveName)
	{
		if (PlayerMoveName == "Station3_Stand_Point1")
		{
			PlayerLock(false,false);
			ForcePlayerCrouch(true);
			PlayerLock(true,false);
			PlayTip("Station 3 - Control Bleeding","",5);
			PlayLSAnim("fa_station5_1",DrillSergeant);
		}
		else
		{
			if (PlayerMoveName == "Station3_Stand_Point2")
			{
				PlayerLock(false,false);
				ForcePlayerCrouch(true);
				PlayerLock(true,false);
				PlayLSAnim("fa_station5_12",DrillSergeant);
			}
		}
	}
	simulated Function bool Timer_LSAnim(FName LSName)
	{
		Log(string(this) + " Timer_LSAnim called for " + FString::FromInt(LSName));
		switch(LSName)
		{
			case "fa_station5_1":
			PlayLSAnim("fa_station5_2",DrillSergeant);
			return true;
			case "fa_station5_2":
			PlayLSAnim("fa_station5_3",DrillSergeant);
			return true;
			case "fa_station5_3":
			PlayTip("Press the <Action> key on the CAT to pick it up.","",5);
			StartHelpTimer(0,true);
			SetHelpMarker(HelpMarker,CATPickup->GetActorLocation(),HelpMarkerSmallOffset,true);
			CATState=1;
			CATPickup.bUseActionIcon=true;
			return true;
			case "fa_station5_4":
			return true;
			case "fa_station5_5":
			return true;
			case "fa_station5_6":
			PlayTip("Press the <Action> key on the mannequin's","arm to apply the CAT to the forearm.",6);
			StartHelpTimer(1,true);
			SetHelpMarker(HelpMarker,AmputatedMannequin.GetBoneCoords("RHand").Origin,HelpMarkerSmallOffset,true);
			bApplyCAT=true;
			return true;
			case "fa_station5_7":
			return true;
			case "fa_station5_8":
			return true;
			case "fa_station5_9":
			return true;
			case "fa_station5_10":
			PlayTip("Press the <Action> key on the mannequin's","head to write a \"T\".",4);
			StartHelpTimer(3,true);
			SetHelpMarker(HelpMarker,AmputatedMannequin.GetBoneCoords("head").Origin,HelpMarkerSmallOffset,true);
			bSwapCATHeadTexture=true;
			return true;
			case "fa_station5_11":
			FadeMoveStart(GetActorByTag("Station3_Stand_Point2"),Self);
			Cast<ADSController>(DrillSergeant.Controller).Walk();
			Cast<ADSController>(DrillSergeant.Controller).MoveToPoint("Station_5_Instruction_2");
			Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
			return true;
			case "fa_station5_12":
			PlayTip("Press the <Action> key on the ETD to pick it up.","",5);
			StartHelpTimer(4,true);
			SetHelpMarker(HelpMarker,ETDPickup->GetActorLocation(),HelpMarkerSmallOffset,true);
			ETDState=1;
			ETDPickup.bUseActionIcon=true;
			return true;
			case "fa_station5_13":
			return true;
			case "fa_station5_14":
			return true;
			case "fa_station5_15":
			return true;
			case "fa_station5_16":
			PlayTip("Press the <Action> key on the rucksack to pick it up.","",4);
			StartHelpTimer(6,true);
			SetHelpMarker(HelpMarker,RucksackPickup->GetActorLocation(),HelpMarkerSmallOffset,true);
			RucksackState=1;
			RucksackPickup.bUseActionIcon=true;
			return true;
			case "fa_station5_17":
			StationCompleted();
			return true;
			default:
			return false;
		}
	}
	simulated Function StationCompleted()
	{
		PlayTip("Station 3 - Control Bleeding Complete","",6);
		FAMasterScript.DeactivatePlayerBlocking(GetPlayerBlockingVolume("Station3_EndBlock"));
		LogStationEnd(this,true);
		bStationComplete=true;
		StationObjective.SetDisabled(true);
		SetHelpMarker(DirectionMarker,GetActorByTag("ToStation4")->GetActorLocation(),HelpMarkerLargeOffset,true,true);
		SetHelpMarkerRotation(DirectionMarker,GetActorByTag("ToStation4").Rotation);
		PlayerLock(false,false);
		ForcePlayerCrouch(false);
		Cast<ADSController>(DrillSergeant.Controller).WaitForTimer(10);
		Cast<ADSController>(DrillSergeant.Controller).MoveToPoint("Station_5_Block_Return");
		Cast<ADSController>(DrillSergeant.Controller).TurnTowardPlayer();
	}
	simulated Function bool Timer_Timer(FName TimerName)
	{
		HandleHelpTimerEvent(TimerName);
		return true;
	}
	simulated Function ActorProximityAlert(AActor* ProximityActor, FName AlertTag)
	{
		if (ProximityActor == GetActorByTag("Station3_Stand_Point1"))
		{
			GOTO JL002D;
		}
		if (ProximityActor == GetActorByTag("Station3_Stand_Point2"))
JL002D:
		{
		}
	}
	simulated Function MannequinTrace(AActor* HitActor, FBoneInfo HitBone)
	{
		if (((HitActor == nullptr) || (HitBone.HitBone == 0)) || ((! HitActor->IsA(AFA_NPC_ControlBleedingMannequin::StaticClass())) && (! HitActor->IsA(AFA_NPC_TraumaDressingMannequin::StaticClass()))))
		{
			Log("Unable to run MannequinTrace(), improper parameters");
			return;
		}
		Log("HitBone is " + HitBone.Name + " and BoneRegion is " + FString::FromInt(GetEnum(Enum'Core.Object.EBoneRegion',HitBone.BoneRegion)));
		if (Cast<AFA_NPC_ControlBleedingMannequin>(HitActor) != nullptr)
		{
			switch(HitBone.BoneRegion)
			{
				case 1:
				if (bSwapCATHeadTexture)
				{
					StopHelpTimer();
					bSwapCATHeadTexture=false;
					FA_NPC_ControlBleedingMannequin(HitActor).SwitchHeadTextures();
					DeactivateHelpMarker(HelpMarker);
					PlayLSAnim("fa_station5_11",DrillSergeant);
				}
				break;
				case 2:
				case 3:
				break;
				case 4:
				case 5:
				break;
				case 6:
				case 7:
				break;
				case 8:
				case 9:
				if ((CATState == 2) && bApplyCAT)
				{
					StopHelpTimer();
					CATState=3;
					bApplyCAT=false;
					CATAttachment=Spawn(AFA_CATAttachment::StaticClass());
					if (CATAttachment != nullptr)
					{
						HitActor.AttachToBone(CATAttachment,"RArmLow");
						CATAttachment.SetRotation(GetBoneRotation("RArmLow"));
					}
					DeactivateHelpMarker(HelpMarker);
					PlayLSAnim("fa_station5_10",DrillSergeant);
				}
				break;
				case 10:
				case 11:
				break;
				case 0:
				break;
				default:
			}
		}
		else
		{
			if (Cast<AFA_NPC_TraumaDressingMannequin>(HitActor) != nullptr)
			{
				switch(HitBone.BoneRegion)
				{
					case 1:
					break;
					case 2:
					case 3:
					break;
					case 4:
					case 5:
					break;
					case 6:
					case 7:
					if (ETDState == 2)
					{
						ETDState=3;
						ETDAttachment=Spawn(AFA_ETDAttachment::StaticClass());
						if (ETDAttachment != nullptr)
						{
							HitActor.AttachToBone(ETDAttachment,"LLegUp");
							ETDAttachment.SetRotation(GetBoneRotation("LLegUp"));
						}
						DeactivateHelpMarker(HelpMarker);
						StopHelpTimer();
						PlayLSAnim("fa_station5_16",DrillSergeant);
					}
					if (bRaiseTraumaMannequinLeftLeg)
					{
						RucksackState=3;
						bRaiseTraumaMannequinLeftLeg=false;
						FA_NPC_TraumaDressingMannequin(HitActor).RaiseLeftLeg();
						DeactivateHelpMarker(HelpMarker);
						StopHelpTimer();
						PlayLSAnim("fa_station5_17",DrillSergeant);
					}
					break;
					case 8:
					case 9:
					break;
					case 10:
					case 11:
					break;
					case 0:
					break;
					default:
				}
			}
		}
	}
	simulated Function HandleMedPickup(AActor* HitActor)
	{
		FVector offset = FVector(0,0,0);
		if ((HitActor == CATPickup) && (CATState == 1))
		{
			CATState=2;
			CATPickup.DisablePickup();
			PlayTip("CAT picked up.","",3);
			StopHelpTimer();
			DeactivateHelpMarker(HelpMarker);
			PlayLSAnim("fa_station5_6",DrillSergeant);
		}
		if ((HitActor == ETDPickup) && (ETDState == 1))
		{
			ETDState=2;
			ETDPickup.DisablePickup();
			offset=(TraumaMannequin.GetBoneCoords("LLegHigh").Origin - TraumaMannequin.GetBoneCoords("LLegLow").Origin);
			(offset /= 2);
			SetHelpMarker(HelpMarker,(TraumaMannequin.GetBoneCoords("LLegLow").Origin + offset),HelpMarkerSmallOffset,true);
			PlayTip("Press the <Action> key on the","mannequin's leg to apply the ETD.",7);
			StopHelpTimer();
			StartHelpTimer(5,true);
		}
		if ((HitActor == RucksackPickup) && (RucksackState == 1))
		{
			RucksackState=2;
			RucksackPickup.DisablePickup();
			offset=(TraumaMannequin.GetBoneCoords("LLegHigh").Origin - TraumaMannequin.GetBoneCoords("LLegLow").Origin);
			(offset /= 2);
			SetHelpMarker(HelpMarker,(TraumaMannequin.GetBoneCoords("LLegLow").Origin + offset),HelpMarkerSmallOffset,true);
			PlayTip("Press the <Action> key on the mannequin's left","leg to raise it and apply pressure.",5);
			StopHelpTimer();
			StartHelpTimer(7,true);
			bRaiseTraumaMannequinLeftLeg=true;
		}
	}
	simulated Function SpawnRuckSack()
	{
		RuckSackAttachment=Spawn(AFA_RuckSackAttachment::StaticClass());
		if (RuckSackAttachment != nullptr)
		{
			TraumaMannequin.AttachToBone(RuckSackAttachment,"Pelvis");
			RuckSackAttachment.SetRotation(GetBoneRotation("Pelvis"));
		}
	}
	simulated Function EndState()
	{
		SetPlayerWeapon(true,false);
		DeactivateHelpMarker(HelpMarker);
		DeactivateHelpMarker(DirectionMarker);
		DeactivateLocationMarker(LocationMarker);
		ForceDrawPlayerCrosshair(false);
		Log("Ending ActiveExecute state for " + FString::FromInt(this));
	}
}
*/

void AFA_EL_BleedingControl::PostBeginPlay()
{
	Super::PostBeginPlay();
	DoReferenceLinking();
}

void AFA_EL_BleedingControl::PostPostInit()
{
	Super::PostPostInit();
	SetHelpMarker(HelpMarker, DrillSergeant->GetActorLocation(), HelpMarkerLargeOffset, true, true);
}

void AFA_EL_BleedingControl::DoReferenceLinking()
{
	AActor* SearchActor = nullptr;
	/*
	ForEach AllActors(Class'Actor', SearchActor)
	{
		if (SearchActor.Tag == "FA_CATPickup")
		{
			CATPickup = FA_CATPickup(SearchActor);
		}
		if (SearchActor.Tag == "FA_ETDPickup")
		{
			ETDPickup = FA_ETDPickup(SearchActor);
		}
		if (SearchActor.Tag == "FA_NPC_TraumaDressingMannequin")
		{
			TraumaMannequin = FA_NPC_TraumaDressingMannequin(SearchActor);
			TraumaMannequin.BC_EL_Lab = this;
		}
		if (SearchActor.Tag == "FA_NPC_ControlBleedingMannequin")
		{
			AmputatedMannequin = FA_NPC_ControlBleedingMannequin(SearchActor);
		}
		if (SearchActor.Tag == "Splint_RucksackPickup")
		{
			RucksackPickup = FA_RucksackPickup(SearchActor);
		}
	}
	*/
	Super::DoReferenceLinking();
}

void AFA_EL_BleedingControl::Reset()
{
	SetDrillSergeantParams(true, true, true);
	bDormant = true;
	PlayerLock(false, false);
	//StationObjective->SetDisabled(false);
	StopHelpTimer(0);
	//Player.SetLocation(GetActorByTag("Station5_Start").Location);
	//Controller.SetRotation(GetActorByTag("Station5_Start").Rotation);
	CATState = EMedicalItemState::MIS_None;
	ETDState = EMedicalItemState::MIS_None;
	RucksackState = EMedicalItemState::MIS_None;
	CATPickup->ActivatePickup();
	ETDPickup->ActivatePickup();
	RucksackPickup->ActivatePickup();
	if (Player->bIsCrouched)
	{
		//Controller->Crouching();
	}
	else
	{
		if (Player->bIsProne)
		{
			//Controller->Crawling();
		}
	}
	Cast<ADSController>(DrillSergeant->Controller)->Walk();
	Cast<ADSController>(DrillSergeant->Controller)->MoveToPoint("Station_5_Instruction_3");
	Cast<ADSController>(DrillSergeant->Controller)->TurnTowardPlayer();
	SetHelpMarker(HelpMarker, DrillSergeant->GetActorLocation(), HelpMarkerLargeOffset, true, true);
	Super::Reset();
}

void AFA_EL_BleedingControl::FFDrillSergeantScold()
{
	//DrillSergeant->StopLIPSincAnim();
	StopTimerByType(ETimerType::TT_LSAnim);
	StopTimerByType(ETimerType::TT_Timer);
	PlayLSAnim("fa_station5_21", DrillSergeant,0,0,0,0);
	PlayTip("Watch your aim soldier!", "", 4);
	ForceLevelReset();
}

void AFA_EL_BleedingControl::DrillSergeantMoveOn(AFSTS_NPC_DrillSergeant* Sergeant)
{
	if (FMath::Rand() %2 == 0)
	{
		PlayLSAnim("fa_station5_18", Sergeant,0,0,0,0);
	}
	else
	{
		PlayLSAnim("fa_station5_24", Sergeant,0,0,0,0);
	}
}

void AFA_EL_BleedingControl::Destroyed()
{
	TraumaMannequin = nullptr;
	AmputatedMannequin = nullptr;
	CATPickup = nullptr;
	ETDPickup = nullptr;
	Super::Destroyed();
}

void AFA_EL_BleedingControl::AssignDrillSergeants(AFSTS_NPC_DrillSergeant* Sergeant)
{
	DS_Kelly = Cast<AFA_NPC_DS_Kelly>(Sergeant);
	SetHelpLSActor(DrillSergeant,false,0);
	//Sergeant->EventLab = this;
	SetDrillSergeantParams(true, true, true);
}

void AFA_EL_BleedingControl::SpawnRuckSack()
{
}
