// All the original content belonged to the US Army

#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_ActivatedObjective/AGP_ESSObjective/AGP_CoopESSObjective/AGP_CoopESSObjective.h"
#include "AA29/Object/Actor/StaticMeshActor/FlagMeshActor/FlagMeshActor.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

AAGP_CoopESSObjective::AAGP_CoopESSObjective(const FObjectInitializer& objectInitializer) :Super(objectInitializer)
{
	sndESSCompleteGoodProcedure = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_ESSAudio/S2RadioMessages/S2ESSObjectiveTakenProperly.S2ESSObjectiveTakenProperly"), NULL, LOAD_None, NULL);
	sndESSCompleteBadProcedure = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_ESSAudio/S2RadioMessages/S2ESSObjectiveTakenBadProcedure.S2ESSObjectiveTakenBadProcedure"), NULL, LOAD_None, NULL);
	sndS2ResponseToReportingObject = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_ESSAudio/S2RadioMessages/S2AcknowledgeMapFound.S2AcknowledgeMapFound"), NULL, LOAD_None, NULL);
	sS2AcknowledgedObjectUsed = "S2 Radios: Roger your intel report.  Use this intel to locate and complete this new object.  Sierra Two, out.";
	fObserveDistance = 200;
	fReportDistance = 300;
	sS2ResponseToReportingObject = "S2 Radios: This is Sierra Two, roger your unknown object.  Identify the object and report back with your findings.  Exercise extreme caution. Out.";
	sndS2ResponseToReportingObject = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_ESSAudio/S2RadioMessages/S2AcknowledgeFoundItem.S2AcknowledgeFoundItem"), NULL, LOAD_None, NULL);
	bUseable = true;
	fDialogLength = 8;
	stResponseToUsingUnuseableObject = "Leave this Object alone and move on.";
	stNoReportResponseToUsingUnuseableObject = "You can not use this item.";
	stReprimandForUsingAndNotReportingPopUp = "It would have been wise to radio (<ESSObjectiveReport>) this in before looking inside.";
	stReprimandForUsingAndNotReportingConsole = "Proper procedure is to report (<ESSObjectiveReport>) items like this to your squad leader before examining them.";
	NextReportInSeconds = 1;
	//RemoteRole = 2;
	//bBlockBulletTraces = true;
}

void AAGP_CoopESSObjective::Reset()
{
	/*
		local Mover moverIterator;
		int32 i;
		local AGP.AGP_Objective agpobjIterator;
		local array<AGP_Objective> aagpoFoundLinkedObjectives;
		Reset();
		bPlayerRadioedObectiveInfo=False;
		bOnRadar=False;
		fpTimeUntilESSInvestigateRadioCompletes=0;
		if(moverLinkedToUnlock.Num() > 0)
		{
			moverLinkedToUnlock.remove(0,moverLinkedToUnlock.Num());
		}
		if(nameLinkedMoverToUnlock != "None" && nameLinkedMoverToUnlock != "None")
		{
			ForEach AllActors(Class'Mover',moverIterator,nameLinkedMoverToUnlock)
			{
				moverLinkedToUnlock.insert(0,1);
				moverLinkedToUnlock[0]=moverIterator;
			}
		}
		if(agpoLinkedObjective.Num() > 0)
		{
			agpoLinkedObjective.remove(0,agpoLinkedObjective.Num());
			for(i=0; i<agpoLinkedObjective.Num(); i++)
			{
				agpoLinkedObjective[i].ObjectiveOnCompass=1;
				agpoLinkedObjective[i].bDisabled=true;
				agpoLinkedObjective[i].bHidden=true;
			}
		}
		Self.bHidden=False;
		Self.bDisabled=False;
		Self.SetCollision(True,True);
		if(nameLinkedObjectiveToActivate != "None" && nameLinkedObjectiveToActivate != "None")
		{
			ForEach AllActors(Class'AGP_Objective',agpobjIterator,nameLinkedObjectiveToActivate)
			{
				if(! ClassIsChildOf(agpobjIterator.Class,'AGP_ESSObjective'))
				{
				}
				else
				{
					aagpoFoundLinkedObjectives.insert(0,1);
					aagpoFoundLinkedObjectives[0]=agpobjIterator;
					aagpoFoundLinkedObjectives[0].ObjectiveOnCompass=agpobjIterator.1;
					aagpoFoundLinkedObjectives[0].bDisabled=true;
				}
			}
		}
		if(aagpoFoundLinkedObjectives.Num() > 0)
		{
			agpoLinkedObjective.insert(0,1);
			agpoLinkedObjective[0]=aagpoFoundLinkedObjectives[Rand(aagpoFoundLinkedObjectives.Num())];
		}
	*/
}
void AAGP_CoopESSObjective::AccomplishObjective(APawn* _Instigator, AController* Killer)
{
	int32 iObjective = 0;
	int32 i = 0;
	AController* ctrlIterator = nullptr;
	if (bDisabled)
	{
		return;
	}
	/*
	if (!bUseable)
	{
		Log("Repremand incoming");
		if (!bPlayerRadioedObectiveInfo)
		{
			HumanController(Instigator.Controller).ClientESSNotifyAdminMessage(stNoReportResponseToUsingUnuseableObject);
		}
		else
		{
			HumanController(Instigator.Controller).ClientESSNotifyAdminMessage(stResponseToUsingUnuseableObject);
		}
		return;
	}
	if ((!bUseOnReport) && ((bPlayerRadioedObectiveInfo && (fpTimeUntilESSInvestigateRadioCompletes > 0)) && (fpTimeUntilESSInvestigateRadioCompletes > Level.TimeSeconds)))
	{
		if (HumanController(Instigator.Controller) != nullptr)
		{
			HumanController(Instigator.Controller).ClientMessage("You must wait for the S2's instructions to finish.");
		}
		StopCounting();
		return;
	}
	bDisabled = true;
	ObjectiveOnCompass = 1;
	HUDText = "";
	hcInstigator = HumanController(Instigator.Controller);
	if (bShowEnemysOnRadar && (fShowEnemyTime > 2))
	{
		AGP_TeamInfo(Instigator.GetTeam()).AlertTeamToEnemyLocations(fShowEnemyTime);
	}
	if ((HumanController(Instigator.Controller).PlayerReplicationInfo != nullptr) && (HumanController(Instigator.Controller).PlayerReplicationInfo.Team != nullptr))
	{
		for (ctrlIterator = Level.ControllerList; ctrlIterator != nullptr; ctrlIterator = ctrlIterator.nextController)
		{
			if (ctrlIterator == Instigator.Controller)
			{
			}
			if (((Level.Game.Stats != nullptr) && (HumanController(ctrlIterator) != nullptr)) && (HumanController(ctrlIterator).PlayerStatsIndex >= 0))
			{
				Level.Game.Stats.PlayerStats[HumanController(ctrlIterator).PlayerStatsIndex].StatEvent_ESSObjectExaminedByOtherPlayer();
			}
		}
		if (bPlayerRadioedObectiveInfo)
		{
			if (((Level.Game.Stats != nullptr) && (HumanController(Instigator.Controller) != nullptr)) && (HumanController(Instigator.Controller).PlayerStatsIndex >= 0))
			{
				Level.Game.Stats.PlayerStats[HumanController(Instigator.Controller).PlayerStatsIndex].StatEvent_ESSPostRadioExaminedObject();
			}
			HumanController(Instigator.Controller).ClientNotifyAdminMessage(sActivationMessage);
			Level.Game.BroadcastHandler.BroadcastTeamByIndex(byte(HumanController(Instigator.Controller).PlayerReplicationInfo.Team.TeamIndex), sActivatedRadioMessage, "ReportESSObjective");
			SetCustomTimer((1.5 + (FMath::FRand() * 3)), false, "RadioCoopContentAcknowledgement");
		}
		else
		{
			if (((Level.Game.Stats != nullptr) && (HumanController(Instigator.Controller) != nullptr)) && (HumanController(Instigator.Controller).PlayerStatsIndex >= 0))
			{
				Level.Game.Stats.PlayerStats[HumanController(Instigator.Controller).PlayerStatsIndex].StatEvent_ESSNoRadioExaminedObject();
			}
			HumanController(Instigator.Controller).ClientESSNotifyAdminMessage(stReprimandForUsingAndNotReportingPopUp);
			HumanController(Instigator.Controller).ClientESSConsoleMessage(stReprimandForUsingAndNotReportingConsole);
			HumanController(Instigator.Controller).ClientESSSpotted(Location.X, Location.Y, Location.Z, bDangerous);
		}
	}
	else
	{
		if (bPlayerRadioedObectiveInfo)
		{
			HumanController(Instigator.Controller).ClientNotifyAdminMessage(sActivationMessage);
			HumanController(Instigator.Controller).ClientMessage(HumanController(Instigator.Controller).UserName $ " Radios: " $ sActivatedRadioMessage);
			SetCustomTimer((1.5 + (FMath::FRand() * 3)), false, "RadioCoopContentAcknowledgement");
			if (((HumanController(Instigator.Controller).EventLab != nullptr) && (!bDummyTrainingObject)) && (!spBeenAccountedFor))
			{
				EventLab.EL_ES2ObjectFound(Score_AssaultHelper);
				spBeenAccountedFor = true;
			}
		}
		else
		{
			HumanController(Instigator.Controller).ClientESSNotifyAdminMessage(stReprimandForUsingAndNotReportingPopUp);
			HumanController(Instigator.Controller).ClientESSConsoleMessage(stReprimandForUsingAndNotReportingConsole);
			HumanController(Instigator.Controller).ClientESSSpotted(Location.X, Location.Y, Location.Z, bDangerous);
		}
	}
	if (agpoLinkedObjective.Num() > 0)
	{
		for (iObjective = 0; iObjective < agpoLinkedObjective.Num(); iObjective++)
		{
			agpoLinkedObjective[iObjective].DefenseDescription = "";
			agpoLinkedObjective[iObjective].bDisabled = false;
			agpoLinkedObjective[iObjective].bHidden = false;
			agpoLinkedObjective[iObjective].FailedDefenseMessage = "";
			if ((HumanController(Instigator.Controller).PlayerReplicationInfo != nullptr) && (HumanController(Instigator.Controller).PlayerReplicationInfo.Team != nullptr))
			{
				agpoLinkedObjective[iObjective].AttackTeam = byte(HumanController(Instigator.Controller).PlayerReplicationInfo.Team.TeamIndex);
				if (bPlayerRadioedObectiveInfo)
				{
					agpoLinkedObjective[iObjective].bPlayerRadioedObectiveInfo = false;
					agpoLinkedObjective[iObjective].bESSObjectiveCompleteSoundPlayerOnly = false;
					agpoLinkedObjective[iObjective].sndESSObjectiveCompletionAcknowledgement = sndESSCompleteGoodProcedure;
					agpoLinkedObjective[iObjective].pawnMustBeUsedBy = nullptr;
					agpoLinkedObjective[iObjective].Score_AssaultPlayer = Score_AssaultPlayer;
					agpoLinkedObjective[iObjective].Score_AssaultTeam = Score_AssaultTeam;
					agpoLinkedObjective[iObjective].Score_AssaultHelper = Score_AssaultHelper;
					if (HumanController(Instigator.Controller).PlayerReplicationInfo.Team.TeamIndex == 0)
					{
						agpoLinkedObjective[iObjective].ObjectiveOnCompass = agpoLinkedObjective[iObjective].4;
					}
					else
					{
						agpoLinkedObjective[iObjective].ObjectiveOnCompass = agpoLinkedObjective[iObjective].5;
					}
				}
				else
				{
					agpoLinkedObjective[iObjective].bPlayerRadioedObectiveInfo = false;
					agpoLinkedObjective[iObjective].bESSObjectiveCompleteSoundPlayerOnly = true;
					agpoLinkedObjective[iObjective].sndESSObjectiveCompletionAcknowledgement = sndESSCompleteBadProcedure;
					agpoLinkedObjective[iObjective].Score_AssaultPlayer = 0;
					agpoLinkedObjective[iObjective].Score_AssaultTeam = Score_AssaultTeam;
					agpoLinkedObjective[iObjective].Score_AssaultHelper = Score_AssaultHelper;
					agpoLinkedObjective[iObjective].pawnMustBeUsedBy = Instigator;
					agpoLinkedObjective[iObjective].ObjectiveOnCompass = agpoLinkedObjective[iObjective].6;
				}
			}
			else
			{
				agpoLinkedObjective[iObjective].ObjectiveOnCompass = agpoLinkedObjective[iObjective].0;
				agpoLinkedObjective[iObjective].AttackTeam = 0;
				agpoLinkedObjective[iObjective].bDisabled = false;
				agpoLinkedObjective[iObjective].bHidden = false;
			}
		}
	}
	NotifySequenceChildren();
	if (UseEventName != "None")
	{
		HumanController(Instigator.Controller).TriggerClientEvent(UseEventName);
	}
	if (moverLinkedToUnlock.Num() > 0)
	{
		if (Level.Game.IsOnTeam(Instigator.Controller, 0))
		{
			for (i = 0; i < moverLinkedToUnlock.Num(); i++)
			{
				if (((moverLinkedToUnlock[i].LockingStyle == 0) || (moverLinkedToUnlock[i].LockingStyle == 1)) || (moverLinkedToUnlock[i].LockingStyle == 3))
				{
				}
				if (moverLinkedToUnlock[i].LockingStyle == 2)
				{
					moverLinkedToUnlock[i].LockingStyle = 0;
					moverLinkedToUnlock[i].InitialLockingStyle = 0;
				}
				else
				{
					moverLinkedToUnlock[i].LockingStyle = 1;
					moverLinkedToUnlock[i].InitialLockingStyle = 1;
				}
			}
		}
		else
		{
			if (Level.Game.IsOnTeam(Instigator.Controller, 1))
			{
				for (i = 0; i < moverLinkedToUnlock.Num(); i++)
				{
					if (((moverLinkedToUnlock[i].LockingStyle == 0) || (moverLinkedToUnlock[i].LockingStyle == 2)) || (moverLinkedToUnlock[i].LockingStyle == 3))
					{
					}
					if (moverLinkedToUnlock[i].LockingStyle == 1)
					{
						moverLinkedToUnlock[i].LockingStyle = 0;
						moverLinkedToUnlock[i].InitialLockingStyle = 0;
					}
					else
					{
						moverLinkedToUnlock[i].LockingStyle = 2;
						moverLinkedToUnlock[i].InitialLockingStyle = 2;
					}
				}
			}
		}
	}
	HumanController(Instigator.Controller).LockPlayer(false, false);
	HumanController(Instigator.Controller).SetDelayReport(NextReportInSeconds);
	*/
}

void AAGP_CoopESSObjective::ActivateFromRadio(AHumanController* _Instigator)
{
	int32 iObjective = 0;
	AController* ctrlIterator = nullptr;
	bDisabled = true;
	ObjectiveOnCompass = EObjectiveOnCompass::ONCOMPASS_NotOnCompass;
	/*
	HUDText = "";
	hcInstigator = Instigator;
	if ((Instigator.PlayerReplicationInfo != nullptr) && (Instigator.PlayerReplicationInfo.Team != nullptr))
	{
		for (ctrlIterator = Level.ControllerList; ctrlIterator != nullptr; ctrlIterator = ctrlIterator.nextController)
		{
			if (ctrlIterator == Instigator)
			{
			}
			if (((Level.Game.Stats != nullptr) && (HumanController(ctrlIterator) != nullptr)) && (HumanController(ctrlIterator).PlayerStatsIndex >= 0))
			{
				Level.Game.Stats.PlayerStats[HumanController(ctrlIterator).PlayerStatsIndex].StatEvent_ESSObjectExaminedByOtherPlayer();
			}
		}
		if (((Level.Game.Stats != nullptr) && (Instigator != nullptr)) && (Instigator.PlayerStatsIndex >= 0))
		{
			Level.Game.Stats.PlayerStats[Instigator.PlayerStatsIndex].StatEvent_ESSPostRadioExaminedObject();
		}
	}
	else
	{
		if (((Instigator.EventLab != nullptr) && (!bDummyTrainingObject)) && (!spBeenAccountedFor))
		{
			EventLab.EL_ES2ObjectFound(Score_AssaultPlayer);
			spBeenAccountedFor = true;
		}
	}
	if (agpoLinkedObjective.Num() > 0)
	{
		for (iObjective = 0; iObjective < agpoLinkedObjective.Num(); iObjective++)
		{
			agpoLinkedObjective[iObjective].DefenseDescription = "";
			agpoLinkedObjective[iObjective].bDisabled = false;
			agpoLinkedObjective[iObjective].bHidden = false;
			agpoLinkedObjective[iObjective].FailedDefenseMessage = "";
			if ((Instigator.PlayerReplicationInfo != nullptr) && (Instigator.PlayerReplicationInfo.Team != nullptr))
			{
				agpoLinkedObjective[iObjective].AttackTeam = byte(Instigator.PlayerReplicationInfo.Team.TeamIndex);
				agpoLinkedObjective[iObjective].bPlayerRadioedObectiveInfo = false;
				agpoLinkedObjective[iObjective].bESSObjectiveCompleteSoundPlayerOnly = false;
				agpoLinkedObjective[iObjective].sndESSObjectiveCompletionAcknowledgement = sndESSCompleteGoodProcedure;
				agpoLinkedObjective[iObjective].pawnMustBeUsedBy = nullptr;
				agpoLinkedObjective[iObjective].Score_AssaultPlayer = Score_AssaultPlayer;
				agpoLinkedObjective[iObjective].Score_AssaultTeam = Score_AssaultTeam;
				agpoLinkedObjective[iObjective].Score_AssaultHelper = Score_AssaultHelper;
				if (Instigator.PlayerReplicationInfo.Team.TeamIndex == 0)
				{
					agpoLinkedObjective[iObjective].ObjectiveOnCompass = agpoLinkedObjective[iObjective].4;
				}
				else
				{
					agpoLinkedObjective[iObjective].ObjectiveOnCompass = agpoLinkedObjective[iObjective].5;
				}
			}
			else
			{
				agpoLinkedObjective[iObjective].ObjectiveOnCompass = agpoLinkedObjective[iObjective].0;
				agpoLinkedObjective[iObjective].AttackTeam = 0;
			}
		}
	}
	if (UseEventName != "None")
	{
		Instigator.TriggerClientEvent(UseEventName);
	}
	Instigator.SetDelayReport(NextReportInSeconds);
	*/
}
void AAGP_CoopESSObjective::RadioCoopContentAcknowledgement()
{
	/*
		hcInstigator.ClientCoopESSRadioInvestigateOrder(sndS2AcknowledgedObjectUsed);
		if(GetNetMode() == ENetMode::NM_Standalone)
		{
			hcInstigator.ClientMessage(sS2AcknowledgedObjectUsed);
		}
		else
		{
			Level.Game.BroadcastHandler.BroadcastTeamByIndex(HumanController(Instigator.Controller).PlayerReplicationInfo.Team.TeamIndex,sS2AcknowledgedObjectUsed,'ReportESSObjective');
		}
	*/
}
float AAGP_CoopESSObjective::getReportDistance()
{
	return fReportDistance;
}

float AAGP_CoopESSObjective::getObserveDistance()
{
	return fObserveDistance;
}

float AAGP_CoopESSObjective::getDangerDistance()
{
	return fDangerDistance;
}

bool AAGP_CoopESSObjective::isDangerous()
{
	return bDangerous;
}

bool AAGP_CoopESSObjective::isReportable()
{
	return bReportable;
}

bool AAGP_CoopESSObjective::isOnRadar()
{
	return bOnRadar;
}

bool AAGP_CoopESSObjective::isUseable()
{
	return bUseable;
}

USoundBase* AAGP_CoopESSObjective::getAcknowledgeVO()
{
	return sndS2ResponseToReportingObject;
}

FString AAGP_CoopESSObjective::getAcknowledgeText()
{
	return sS2ResponseToReportingObject;
}

FName AAGP_CoopESSObjective::getFlagTag()
{
	return FlagTag;
}

AFlagMeshActor* AAGP_CoopESSObjective::getFlagReference()
{
	return FlagReference;
}

float AAGP_CoopESSObjective::getDialogLength()
{
	return fDialogLength;
}

FName AAGP_CoopESSObjective::getReportEventName()
{
	return ReportEventName;
}

bool AAGP_CoopESSObjective::isDummyTrainingObject()
{
	return bDummyTrainingObject;
}

FName AAGP_CoopESSObjective::getBecomeActiveEvent()
{
	return BecomeActiveEvent;
}

bool AAGP_CoopESSObjective::isUseOnReport()
{
	return bUseOnReport;
}

void AAGP_CoopESSObjective::MakeESSObjectAppearOnRadar()
{
	if(! bOnRadar)
	{
		bOnRadar=true;
	}
}

void AAGP_CoopESSObjective::MakeES2ObjectiveReportable()
{
	if(! bReportable)
	{
		bReportable=true;
	}
}

bool AAGP_CoopESSObjective::ShouldTakeDamage(UaDamageType* DamageType)
{
	int32 i = 0;
	for (i = 0; i < RecieveDamageTypes.Num(); i++)
	{
		/*
		if ((DamageType == RecieveDamageTypes[i]) || ClassIsChildOf(DamageType, RecieveDamageTypes[i]))
		{
			return true;
		}
		*/
	}
	return false;

}

/*
void AAGP_CoopESSObjective::TakeDamage(int32 Damage, APawn* EventInstigator, FVector HitLocation, FVector Momentum, UaDamageType* DamageType, BoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, AMaterial HitMaterial)
{
		if(ShouldTakeDamage(DamageType))
		{
			if(bDestroyable)
			{
				DestroyHealth -= Damage;
				if(DestroyHealth <= 0)
				{
					TriggerEvent(DestroyEvent,Self,Instigator);
					PlaySound(ExplosionSound,,1,,5000);
					Spawn(ExplosionEmitterClass);
					if(bHideOnDestroy)
					{
						bHidden=true;
						bDisabled=true;
						SetCollision(False,False,False);
					}
					else
					{
						bDisabled=true;
					}
				}
			}
		}
}
*/
void AAGP_CoopESSObjective::Trigger(AActor* Other, APawn* _Instigator)
{
	/*
		if(bDetonateOnTrigger && ! bHidden && ! bDisabled)
		{
			RadiusDamage(fDamageAmount,fDamageRadius,Class'ExplosionDamage',0,Location);
			PlaySound(ExplosionSound,,1,,5000);
			Spawn(ExplosionEmitterClass);
			if(bHideOnDestroy)
			{
				bHidden=true;
				bDisabled=true;
				SetCollision(False,False,False);
			}
			else
			{
				bDisabled=False;
			}
		}
	*/
}
void AAGP_CoopESSObjective::RadiusDamage(float DamageAmount, float DamageRadius, UaDamageType* DamageType, float Momentum, FVector HitLocation, float KillRadius)
{
	/*
		local Pawn Victim;
		local float damageScale;
		local float dist;
		local FVector Dir;
		local float HitDamage;
		ForEach AllActors(Class'Pawn',Victim)
		{
			if(Victim.Role == 4 && ! Victim.bHidden)
			{
				Dir=Victim.Location - Location;
				dist=FMax(1,VSize(Dir));
				if(dist <= 0)
				{
				}
				else
				{
					Dir=Dir / dist;
					damageScale=1 - FMax(0,dist - Victim.CollisionRadius / DamageRadius + 100);
					HitDamage=damageScale * DamageAmount;
					if(HitDamage <= 0)
					{
					}
					else
					{
						Victim.TakeDamage(damageScale * DamageAmount,Instigator,Victim.Location,damageScale * Momentum * Dir,DamageType);
					}
				}
			}
		}
	*/
}
