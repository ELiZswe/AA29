// All the original content belonged to the US Army

#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_ActivatedObjective/AGP_ESSObjective/AGP_ZombifiedES2Objective/AGP_ZombifiedES2Objective.h"

AAGP_ZombifiedES2Objective::AAGP_ZombifiedES2Objective(const FObjectInitializer& objectInitializer)	:Super(objectInitializer)
{
	fObserveDistance	= 200;
	fReportDistance		= 300;
	fDangerDistance		= 100;
}

void AAGP_ZombifiedES2Objective::BeginPlay()
{
	Super::BeginPlay();
	Reset();
}

FString AAGP_ZombifiedES2Objective::GetDescriptionByController(AController* listener)
{
	return "";
}

void AAGP_ZombifiedES2Objective::Reset()
{
	/*
	local Mover moverIterator;
	local AGP_Objective agpobjIterator;
	local TArray<AGP_Objective> aagpoFoundLinkedObjectives;
	bFirstObjectFound = true;
	bPlayerRadioedObectiveInfo = false;
	fpTimeUntilESSInvestigateRadioCompletes = 0;
	if (moverLinkedToUnlock.Length > 0)
	{
		moverLinkedToUnlock.remove(0, moverLinkedToUnlock.Length);
	}
	if ((nameLinkedMoverToUnlock != "None") && (nameLinkedMoverToUnlock != "None"))
	{
		ForEach AllActors(Class'Mover', moverIterator, nameLinkedMoverToUnlock)
		{
			moverLinkedToUnlock.insert(0, 1);
			moverLinkedToUnlock[0] = moverIterator;
		}
	}
	if (agpoLinkedObjective.Length > 0)
	{
		agpoLinkedObjective.remove(0, agpoLinkedObjective.Length);
	}
	ForEach AllActors(Class'AGP.AGP_Objective', agpobjIterator, nameLinkedObjectiveToActivate)
	{
		if (agpobjIterator.IsA("AGP_ZombifiedES2Objective"))
		{
			continue;
		}
		aagpoFoundLinkedObjectives.insert(0, 1);
		aagpoFoundLinkedObjectives[0] = agpobjIterator;
		aagpoFoundLinkedObjectives[0].ObjectiveOnCompass = agpobjIterator.1;
		aagpoFoundLinkedObjectives[0].bDisabled = true;
		aagpoFoundLinkedObjectives[0].bHidden = true;
	}
	if (aagpoFoundLinkedObjectives.Length > 0)
	{
		agpoLinkedObjective.insert(0, 1);
		agpoLinkedObjective[0] = aagpoFoundLinkedObjectives[Rand(aagpoFoundLinkedObjectives.Length)];
	}
	else
	{
		Log(string(Self) $ "." $ string(Tag) $ " is misconfigured and has no linked objectives");
	}
	*/
}

void AAGP_ZombifiedES2Objective::AccomplishObjective(APawn* aInstigator, AController* Killer)
{
	int32 iMover = 0;
	int32 iObjective = 0;
	/*
	local Controller ctrlIterator;
	if (bDisabled)
	{
		return;
	}
	if (((bPlayerRadioedObectiveInfo && (fpTimeUntilESSInvestigateRadioCompletes > 0)) && (fpTimeUntilESSInvestigateRadioCompletes > Level.TimeSeconds)) || (!bFirstObjectFound))
	{
		if (HumanController(aInstigator.Controller) != nullptr)
		{
			HumanController(aInstigator.Controller).ClientMessage("You must wait for the S2's instructions to finish.");
		}
		return;
	}
	Log("Trying to keep the other side from using an ES2 Object.");
	if ((bPlayerRadioedObectiveInfo && (ctrlrESSReporter != nullptr)) && (ctrlrESSReporter.PlayerReplicationInfo.Team.TeamIndex != aInstigator.Controller.PlayerReplicationInfo.Team.TeamIndex))
	{
		Log("ES2 objective owned by the other team");
		return;
	}
	Log("Activation message: " $ sActivationMessage);
	if (moverLinkedToUnlock.Length > 0)
	{
		for (iMover = 0; iMover < moverLinkedToUnlock.Length; iMover++)
		{
			Log("Activating linked mover: " $ string(moverLinkedToUnlock[iMover]));
			moverLinkedToUnlock[iMover].bUseControl = false;
		}
	}
	bDisabled = true;
	ObjectiveOnCompass = 1;
	HUDText = "";
	if (agpoLinkedObjective.Length > 0)
	{
		hcInstigator = HumanController(aInstigator.Controller);
		if ((HumanController(aInstigator.Controller).PlayerReplicationInfo != nullptr) && (HumanController(aInstigator.Controller).PlayerReplicationInfo.Team != nullptr))
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
				if (((Level.Game.Stats != nullptr) && (HumanController(aInstigator.Controller) != nullptr)) && (HumanController(aInstigator.Controller).PlayerStatsIndex >= 0))
				{
					Level.Game.Stats.PlayerStats[HumanController(aInstigator.Controller).PlayerStatsIndex].StatEvent_ESSPostRadioExaminedObject();
				}
				HumanController(aInstigator.Controller).ClientNotifyAdminMessage(sActivationMessage);
				Level.Game.BroadcastHandler.BroadcastTeamByIndex(byte(HumanController(aInstigator.Controller).PlayerReplicationInfo.Team.TeamIndex), sActivatedRadioMessage, "ReportESSObjective");
				SetCustomTimer((1.5 + (FRand() * 3)), false, "RadioContentAcknowledgement");
			}
			else
			{
				if (((Level.Game.Stats != nullptr) && (HumanController(aInstigator.Controller) != nullptr)) && (HumanController(aInstigator.Controller).PlayerStatsIndex >= 0))
				{
					Level.Game.Stats.PlayerStats[HumanController(aInstigator.Controller).PlayerStatsIndex].StatEvent_ESSNoRadioExaminedObject();
				}
				HumanController(aInstigator.Controller).ClientESSNotifyAdminMessage(sActivationMessage $ "  It would have been wise to radio (<ESSObjectiveReport>) this in  before looking inside.");
				HumanController(aInstigator.Controller).ClientESSConsoleMessage("Proper procedure is to report (<ESSObjectiveReport>) items like this to your company commander or squad leader before examining them.");
			}
		}
		else
		{
			if (bPlayerRadioedObectiveInfo)
			{
				HumanController(aInstigator.Controller).ClientNotifyAdminMessage(sActivationMessage);
				HumanController(aInstigator.Controller).ClientMessage(HumanController(aInstigator.Controller).UserName $ " Radios: " $ sActivatedRadioMessage);
				SetCustomTimer((1.5 + (FRand() * 3)), false, "RadioContentAcknowledgement");
			}
			else
			{
				HumanController(aInstigator.Controller).ClientESSNotifyAdminMessage(sActivationMessage $ "  It would have been wise to radio (<ESSObjectiveReport>) this in before looking inside.");
				HumanController(aInstigator.Controller).ClientESSConsoleMessage("Proper procedure is to report (<ESSObjectiveReport>) items like this to your squad leader before examining them.");
			}
		}
		for (iObjective = 0; iObjective < agpoLinkedObjective.Length; iObjective++)
		{
			Log("Activating linked objective: " $ string(agpoLinkedObjective[iObjective]));
			Log("Activated radio message: " $ sActivatedRadioMessage);
			agpoLinkedObjective[iObjective].DefenseDescription = "";
			agpoLinkedObjective[iObjective].bDisabled = false;
			agpoLinkedObjective[iObjective].bHidden = false;
			agpoLinkedObjective[iObjective].FailedDefenseMessage = "";
			if ((HumanController(aInstigator.Controller).PlayerReplicationInfo != nullptr) && (HumanController(aInstigator.Controller).PlayerReplicationInfo.Team != nullptr))
			{
				agpoLinkedObjective[iObjective].AttackTeam = byte(HumanController(aInstigator.Controller).PlayerReplicationInfo.Team.TeamIndex);
				if (bPlayerRadioedObectiveInfo)
				{
					agpoLinkedObjective[iObjective].bPlayerRadioedObectiveInfo = true;
					agpoLinkedObjective[iObjective].bESSObjectiveCompleteSoundPlayerOnly = false;
					agpoLinkedObjective[iObjective].sndESSObjectiveCompletionAcknowledgement = sndESSObjectiveCompleteGoodProcedure;
					agpoLinkedObjective[iObjective].pawnMustBeUsedBy = nullptr;
					agpoLinkedObjective[iObjective].Score_AssaultPlayer = Score_AssaultPlayer;
					agpoLinkedObjective[iObjective].Score_AssaultTeam = Score_AssaultTeam;
					agpoLinkedObjective[iObjective].Score_AssaultHelper = Score_AssaultHelper;
					if (HumanController(aInstigator.Controller).PlayerReplicationInfo.Team.TeamIndex == 0)
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
					agpoLinkedObjective[iObjective].sndESSObjectiveCompletionAcknowledgement = sndESSObjectiveCompleteBadProcedure;
					agpoLinkedObjective[iObjective].Score_AssaultPlayer = 0;
					agpoLinkedObjective[iObjective].Score_AssaultTeam = Score_AssaultTeam;
					agpoLinkedObjective[iObjective].Score_AssaultHelper = Score_AssaultHelper;
					agpoLinkedObjective[iObjective].pawnMustBeUsedBy = aInstigator;
					agpoLinkedObjective[iObjective].ObjectiveOnCompass = agpoLinkedObjective[iObjective].6;
				}
			}
			else
			{
				agpoLinkedObjective[iObjective].ObjectiveOnCompass = agpoLinkedObjective[iObjective].0;
				agpoLinkedObjective[iObjective].AttackTeam = 0;
			}
		}
	}
	*/
	bFirstObjectFound = false;
}

void AAGP_ZombifiedES2Objective::RadioContentAcknowledgement()
{
	//hcInstigator->ClientESSRadioInvestigateOrder(sndESSObjectiveRadioAcknowledgement);
}

void AAGP_ZombifiedES2Objective::RadioActivationOfObject(AHumanController* HC)
{
}
