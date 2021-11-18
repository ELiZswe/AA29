// All the original content belonged to the US Army


#include "AGP_CoopESSObjective.h"

AAGP_CoopESSObjective::AAGP_CoopESSObjective(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
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
		local int i;
		local AGP.AGP_Objective agpobjIterator;
		local array<AGP_Objective> aagpoFoundLinkedObjectives;
		Reset();
		bPlayerRadioedObectiveInfo=False;
		bOnRadar=False;
		fpTimeUntilESSInvestigateRadioCompletes=0;
		if(moverLinkedToUnlock.Length > 0)
		{
			moverLinkedToUnlock.remove(0,moverLinkedToUnlock.Length);
		}
		if(nameLinkedMoverToUnlock != 'None' && nameLinkedMoverToUnlock != 'None')
		{
			ForEach AllActors(Class'Mover',moverIterator,nameLinkedMoverToUnlock)
			{
				moverLinkedToUnlock.insert(0,1);
				moverLinkedToUnlock[0]=moverIterator;
			}
		}
		if(agpoLinkedObjective.Length > 0)
		{
			agpoLinkedObjective.remove(0,agpoLinkedObjective.Length);
			for(i=0; i<agpoLinkedObjective.Length; i++)
			{
				agpoLinkedObjective[i].ObjectiveOnCompass=1;
				agpoLinkedObjective[i].bDisabled=True;
				agpoLinkedObjective[i].bHidden=True;
			}
		}
		Self.bHidden=False;
		Self.bDisabled=False;
		Self.SetCollision(True,True);
		if(nameLinkedObjectiveToActivate != 'None' && nameLinkedObjectiveToActivate != 'None')
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
					aagpoFoundLinkedObjectives[0].bDisabled=True;
				}
			}
		}
		if(aagpoFoundLinkedObjectives.Length > 0)
		{
			agpoLinkedObjective.insert(0,1);
			agpoLinkedObjective[0]=aagpoFoundLinkedObjectives[Rand(aagpoFoundLinkedObjectives.Length)];
		}
	*/
}
void AAGP_CoopESSObjective::AccomplishObjective(APawn* _Instigator, AController* Killer)
{
	/*
		local int iObjective;
		local int i;
		local Controller ctrlIterator;
		if(bDisabled)
		{
			Return;
		}
		if(! bUseable)
		{
			Log("Repremand incoming");
			if(! bPlayerRadioedObectiveInfo)
			{
				HumanController(Instigator.Controller).ClientESSNotifyAdminMessage(stNoReportResponseToUsingUnuseableObject);
			}
			else
			{
				HumanController(Instigator.Controller).ClientESSNotifyAdminMessage(stResponseToUsingUnuseableObject);
			}
			Return;
		}
		if(! bUseOnReport && bPlayerRadioedObectiveInfo && fpTimeUntilESSInvestigateRadioCompletes > 0 && fpTimeUntilESSInvestigateRadioCompletes > GetWorld()->GetTimeSeconds())
		{
			if(HumanController(Instigator.Controller) != None)
			{
				HumanController(Instigator.Controller).ClientMessage("You must wait for the S2's instructions to finish.");
			}
			StopCounting();
			Return;
		}
		bDisabled=True;
		ObjectiveOnCompass=1;
		HUDText="";
		hcInstigator=HumanController(Instigator.Controller);
		if(bShowEnemysOnRadar && fShowEnemyTime > 2)
		{
			AGP_TeamInfo(Instigator.GetTeam()).AlertTeamToEnemyLocations(fShowEnemyTime);
		}
		if(HumanController(Instigator.Controller).PlayerReplicationInfo != None && HumanController(Instigator.Controller).PlayerReplicationInfo.Team != None)
		{
			ctrlIterator=Level.ControllerList;
			if(ctrlIterator != None)
			{
				if(ctrlIterator == Instigator.Controller)
				{
				}
				if(Level.Game.Stats != None && HumanController(ctrlIterator) != None && HumanController(ctrlIterator).PlayerStatsIndex >= 0)
				{
					Level.Game.Stats.PlayerStats[HumanController(ctrlIterator).PlayerStatsIndex].StatEvent_ESSObjectExaminedByOtherPlayer();
				}
				ctrlIterator=ctrlIterator.nextController;
			}
			if(bPlayerRadioedObectiveInfo)
			{
				if(Level.Game.Stats != None && HumanController(Instigator.Controller) != None && HumanController(Instigator.Controller).PlayerStatsIndex >= 0)
				{
					Level.Game.Stats.PlayerStats[HumanController(Instigator.Controller).PlayerStatsIndex].StatEvent_ESSPostRadioExaminedObject();
				}
				HumanController(Instigator.Controller).ClientNotifyAdminMessage(sActivationMessage);
				Level.Game.BroadcastHandler.BroadcastTeamByIndex(HumanController(Instigator.Controller).PlayerReplicationInfo.Team.TeamIndex,sActivatedRadioMessage,'ReportESSObjective');
				SetCustomTimer(1.5 + FRand() * 3,False,'RadioCoopContentAcknowledgement');
			}
			else
			{
				if(Level.Game.Stats != None && HumanController(Instigator.Controller) != None && HumanController(Instigator.Controller).PlayerStatsIndex >= 0)
				{
					Level.Game.Stats.PlayerStats[HumanController(Instigator.Controller).PlayerStatsIndex].StatEvent_ESSNoRadioExaminedObject();
				}
				HumanController(Instigator.Controller).ClientESSNotifyAdminMessage(stReprimandForUsingAndNotReportingPopUp);
				HumanController(Instigator.Controller).ClientESSConsoleMessage(stReprimandForUsingAndNotReportingConsole);
				HumanController(Instigator.Controller).ClientESSSpotted(Location.X,Location.Y,Location.Z,bDangerous);
			}
		}
		else
		{
			if(bPlayerRadioedObectiveInfo)
			{
				HumanController(Instigator.Controller).ClientNotifyAdminMessage(sActivationMessage);
				HumanController(Instigator.Controller).ClientMessage(HumanController(Instigator.Controller).UserName $ " Radios: " $ sActivatedRadioMessage);
				SetCustomTimer(1.5 + FRand() * 3,False,'RadioCoopContentAcknowledgement');
				if(HumanController(Instigator.Controller).EventLab != None && ! bDummyTrainingObject && ! spBeenAccountedFor)
				{
					EventLab.EL_ES2ObjectFound(Score_AssaultHelper);
					spBeenAccountedFor=True;
				}
			}
			else
			{
				HumanController(Instigator.Controller).ClientESSNotifyAdminMessage(stReprimandForUsingAndNotReportingPopUp);
				HumanController(Instigator.Controller).ClientESSConsoleMessage(stReprimandForUsingAndNotReportingConsole);
				HumanController(Instigator.Controller).ClientESSSpotted(Location.X,Location.Y,Location.Z,bDangerous);
			}
		}
		if(agpoLinkedObjective.Length > 0)
		{
			for(iObjective=0; iObjective<agpoLinkedObjective.Length; iObjective++)
			{
				agpoLinkedObjective[iObjective].DefenseDescription="";
				agpoLinkedObjective[iObjective].bDisabled=False;
				agpoLinkedObjective[iObjective].bHidden=False;
				agpoLinkedObjective[iObjective].FailedDefenseMessage="";
				if(HumanController(Instigator.Controller).PlayerReplicationInfo != None && HumanController(Instigator.Controller).PlayerReplicationInfo.Team != None)
				{
					agpoLinkedObjective[iObjective].AttackTeam=HumanController(Instigator.Controller).PlayerReplicationInfo.Team.TeamIndex;
					if(bPlayerRadioedObectiveInfo)
					{
						agpoLinkedObjective[iObjective].bPlayerRadioedObectiveInfo=False;
						agpoLinkedObjective[iObjective].bESSObjectiveCompleteSoundPlayerOnly=False;
						agpoLinkedObjective[iObjective].sndESSObjectiveCompletionAcknowledgement=sndESSCompleteGoodProcedure;
						agpoLinkedObjective[iObjective].pawnMustBeUsedBy=None;
						agpoLinkedObjective[iObjective].Score_AssaultPlayer=Score_AssaultPlayer;
						agpoLinkedObjective[iObjective].Score_AssaultTeam=Score_AssaultTeam;
						agpoLinkedObjective[iObjective].Score_AssaultHelper=Score_AssaultHelper;
						if(HumanController(Instigator.Controller).PlayerReplicationInfo.Team.TeamIndex == 0)
						{
							agpoLinkedObjective[iObjective].ObjectiveOnCompass=agpoLinkedObjective[iObjective].4;
						}
						else
						{
							agpoLinkedObjective[iObjective].ObjectiveOnCompass=agpoLinkedObjective[iObjective].5;
						}
					}
					else
					{
						agpoLinkedObjective[iObjective].bPlayerRadioedObectiveInfo=False;
						agpoLinkedObjective[iObjective].bESSObjectiveCompleteSoundPlayerOnly=True;
						agpoLinkedObjective[iObjective].sndESSObjectiveCompletionAcknowledgement=sndESSCompleteBadProcedure;
						agpoLinkedObjective[iObjective].Score_AssaultPlayer=0;
						agpoLinkedObjective[iObjective].Score_AssaultTeam=Score_AssaultTeam;
						agpoLinkedObjective[iObjective].Score_AssaultHelper=Score_AssaultHelper;
						agpoLinkedObjective[iObjective].pawnMustBeUsedBy=Instigator;
						agpoLinkedObjective[iObjective].ObjectiveOnCompass=agpoLinkedObjective[iObjective].6;
					}
				}
				else
				{
					agpoLinkedObjective[iObjective].ObjectiveOnCompass=agpoLinkedObjective[iObjective].0;
					agpoLinkedObjective[iObjective].AttackTeam=0;
					agpoLinkedObjective[iObjective].bDisabled=False;
					agpoLinkedObjective[iObjective].bHidden=False;
				}
			}
		}
		NotifySequenceChildren();
		if(UseEventName != 'None')
		{
			HumanController(Instigator.Controller).TriggerClientEvent(UseEventName);
		}
		if(moverLinkedToUnlock.Length > 0)
		{
			if(Level.Game.IsOnTeam(Instigator.Controller,0))
			{
				for(i=0; i<moverLinkedToUnlock.Length; i++)
				{
					if(moverLinkedToUnlock[i].LockingStyle == 0 || moverLinkedToUnlock[i].LockingStyle == 1 || moverLinkedToUnlock[i].LockingStyle == 3)
					{
					}
					if(moverLinkedToUnlock[i].LockingStyle == 2)
					{
						moverLinkedToUnlock[i].LockingStyle=0;
						moverLinkedToUnlock[i].InitialLockingStyle=0;
					}
					else
					{
						moverLinkedToUnlock[i].LockingStyle=1;
						moverLinkedToUnlock[i].InitialLockingStyle=1;
					}
				}
			}
			else
			{
				if(Level.Game.IsOnTeam(Instigator.Controller,1))
				{
					for(i=0; i<moverLinkedToUnlock.Length; i++)
					{
						if(moverLinkedToUnlock[i].LockingStyle == 0 || moverLinkedToUnlock[i].LockingStyle == 2 || moverLinkedToUnlock[i].LockingStyle == 3)
						{
						}
						if(moverLinkedToUnlock[i].LockingStyle == 1)
						{
							moverLinkedToUnlock[i].LockingStyle=0;
							moverLinkedToUnlock[i].InitialLockingStyle=0;
						}
						else
						{
							moverLinkedToUnlock[i].LockingStyle=2;
							moverLinkedToUnlock[i].InitialLockingStyle=2;
						}
					}
				}
			}
		}
		HumanController(Instigator.Controller).LockPlayer(False,False);
		HumanController(Instigator.Controller).SetDelayReport(NextReportInSeconds);
	*/
}
void AAGP_CoopESSObjective::ActivateFromRadio(AHumanController* _Instigator)
{
	/*
		local int iObjective;
		local Controller ctrlIterator;
		bDisabled=True;
		ObjectiveOnCompass=1;
		HUDText="";
		hcInstigator=Instigator;
		if(Instigator.PlayerReplicationInfo != None && Instigator.PlayerReplicationInfo.Team != None)
		{
			ctrlIterator=Level.ControllerList;
			if(ctrlIterator != None)
			{
				if(ctrlIterator == Instigator)
				{
				}
				if(Level.Game.Stats != None && HumanController(ctrlIterator) != None && HumanController(ctrlIterator).PlayerStatsIndex >= 0)
				{
					Level.Game.Stats.PlayerStats[HumanController(ctrlIterator).PlayerStatsIndex].StatEvent_ESSObjectExaminedByOtherPlayer();
				}
				ctrlIterator=ctrlIterator.nextController;
			}
			if(Level.Game.Stats != None && Instigator != None && Instigator.PlayerStatsIndex >= 0)
			{
				Level.Game.Stats.PlayerStats[Instigator.PlayerStatsIndex].StatEvent_ESSPostRadioExaminedObject();
			}
		}
		else
		{
			if(Instigator.EventLab != None && ! bDummyTrainingObject && ! spBeenAccountedFor)
			{
				EventLab.EL_ES2ObjectFound(Score_AssaultPlayer);
				spBeenAccountedFor=True;
			}
		}
		if(agpoLinkedObjective.Length > 0)
		{
			for(iObjective=0; iObjective<agpoLinkedObjective.Length; iObjective++)
			{
				agpoLinkedObjective[iObjective].DefenseDescription="";
				agpoLinkedObjective[iObjective].bDisabled=False;
				agpoLinkedObjective[iObjective].bHidden=False;
				agpoLinkedObjective[iObjective].FailedDefenseMessage="";
				if(Instigator.PlayerReplicationInfo != None && Instigator.PlayerReplicationInfo.Team != None)
				{
					agpoLinkedObjective[iObjective].AttackTeam=Instigator.PlayerReplicationInfo.Team.TeamIndex;
					agpoLinkedObjective[iObjective].bPlayerRadioedObectiveInfo=False;
					agpoLinkedObjective[iObjective].bESSObjectiveCompleteSoundPlayerOnly=False;
					agpoLinkedObjective[iObjective].sndESSObjectiveCompletionAcknowledgement=sndESSCompleteGoodProcedure;
					agpoLinkedObjective[iObjective].pawnMustBeUsedBy=None;
					agpoLinkedObjective[iObjective].Score_AssaultPlayer=Score_AssaultPlayer;
					agpoLinkedObjective[iObjective].Score_AssaultTeam=Score_AssaultTeam;
					agpoLinkedObjective[iObjective].Score_AssaultHelper=Score_AssaultHelper;
					if(Instigator.PlayerReplicationInfo.Team.TeamIndex == 0)
					{
						agpoLinkedObjective[iObjective].ObjectiveOnCompass=agpoLinkedObjective[iObjective].4;
					}
					else
					{
						agpoLinkedObjective[iObjective].ObjectiveOnCompass=agpoLinkedObjective[iObjective].5;
					}
				}
				else
				{
					agpoLinkedObjective[iObjective].ObjectiveOnCompass=agpoLinkedObjective[iObjective].0;
					agpoLinkedObjective[iObjective].AttackTeam=0;
				}
			}
		}
		if(UseEventName != 'None')
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
void AAGP_CoopESSObjective::getReportDistance()
{
	/*
		Return fReportDistance;
	*/
}
void AAGP_CoopESSObjective::getObserveDistance()
{
	/*
		Return fObserveDistance;
	*/
}
void AAGP_CoopESSObjective::getDangerDistance()
{
	/*
		Return fDangerDistance;
	*/
}
void AAGP_CoopESSObjective::isDangerous()
{
	/*
		Return bDangerous;
	*/
}
void AAGP_CoopESSObjective::isReportable()
{
	/*
		Return bReportable;
	*/
}
void AAGP_CoopESSObjective::isOnRadar()
{
	/*
		Return bOnRadar;
	*/
}
void AAGP_CoopESSObjective::isUseable()
{
	/*
		Return bUseable;
	*/
}
void AAGP_CoopESSObjective::getAcknowledgeVO()
{
	/*
		Return sndS2ResponseToReportingObject;
	*/
}
void AAGP_CoopESSObjective::getAcknowledgeText()
{
	/*
		Return sS2ResponseToReportingObject;
	*/
}
void AAGP_CoopESSObjective::getFlagTag()
{
	/*
		Return FlagTag;
	*/
}
void AAGP_CoopESSObjective::getFlagReference()
{
	/*
		Return FlagReference;
	*/
}
void AAGP_CoopESSObjective::getDialogLength()
{
	/*
		Return fDialogLength;
	*/
}
void AAGP_CoopESSObjective::getReportEventName()
{
	/*
		Return ReportEventName;
	*/
}
void AAGP_CoopESSObjective::isDummyTrainingObject()
{
	/*
		Return bDummyTrainingObject;
	*/
}
void AAGP_CoopESSObjective::getBecomeActiveEvent()
{
	/*
		Return BecomeActiveEvent;
	*/
}
void AAGP_CoopESSObjective::isUseOnReport()
{
	/*
		Return bUseOnReport;
	*/
}
void AAGP_CoopESSObjective::MakeESSObjectAppearOnRadar()
{
	/*
		if(! bOnRadar)
		{
			bOnRadar=True;
		}
	*/
}
void AAGP_CoopESSObjective::MakeES2ObjectiveReportable()
{
	/*
		if(! bReportable)
		{
			bReportable=True;
		}
	*/
}
void AAGP_CoopESSObjective::ShouldTakeDamage(UaDamageType* DamageType)
{
	/*
		local int i;
		for(i=0; i<RecieveDamageTypes.Length; i++)
		{
			if(DamageType == RecieveDamageTypes[i] || ClassIsChildOf(DamageType,RecieveDamageTypes[i]))
			{
				Return True;
			}
		}
		Return False;
	*/
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
						bHidden=True;
						bDisabled=True;
						SetCollision(False,False,False);
					}
					else
					{
						bDisabled=True;
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
				bHidden=True;
				bDisabled=True;
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
