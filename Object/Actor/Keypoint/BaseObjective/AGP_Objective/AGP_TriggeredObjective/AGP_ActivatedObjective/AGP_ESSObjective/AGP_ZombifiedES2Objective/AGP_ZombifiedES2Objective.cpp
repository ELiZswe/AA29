// All the original content belonged to the US Army

#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_ActivatedObjective/AGP_ESSObjective/AGP_ZombifiedES2Objective/AGP_ZombifiedES2Objective.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/DecoMesh/Mover/Mover.h"

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
	AMover* moverIterator = nullptr;
	AAGP_Objective* agpobjIterator = nullptr;
	TArray<AAGP_Objective*> aagpoFoundLinkedObjectives = {};
	bFirstObjectFound = true;
	bPlayerRadioedObectiveInfo = false;
	fpTimeUntilESSInvestigateRadioCompletes = 0;
	/*
	if (moverLinkedToUnlock.Num() > 0)
	{
		moverLinkedToUnlock.RemoveAt(0, moverLinkedToUnlock.Num());
	}
	if ((nameLinkedMoverToUnlock != "None") && (nameLinkedMoverToUnlock != "None"))
	{
		ForEach AllActors(AMover::StaticClass(), moverIterator, nameLinkedMoverToUnlock)
		{
			moverLinkedToUnlock.insert(0, 1);
			moverLinkedToUnlock[0] = moverIterator;
		}
	}
	if (agpoLinkedObjective.Num() > 0)
	{
		agpoLinkedObjective.RemoveAt(0, agpoLinkedObjective.Num());
	}
	ForEach AllActors(AAGP_Objective::StaticClass(), agpobjIterator, nameLinkedObjectiveToActivate)
	{
		if (agpobjIterator->IsA(AAGP_ZombifiedES2Objective::StaticClass()))
		{
			continue;
		}
		aagpoFoundLinkedObjectives.insert(0, 1);
		aagpoFoundLinkedObjectives[0] = agpobjIterator;
		aagpoFoundLinkedObjectives[0].ObjectiveOnCompass = agpobjIterator.1;
		aagpoFoundLinkedObjectives[0].bDisabled = true;
		aagpoFoundLinkedObjectives[0].bHidden = true;
	}
	if (aagpoFoundLinkedObjectives.Num() > 0)
	{
		agpoLinkedObjective.insert(0, 1);
		agpoLinkedObjective[0] = aagpoFoundLinkedObjectives[Rand(aagpoFoundLinkedObjectives.Num())];
	}
	else
	{
		Log(string(this) + "." + FString::FromInt(Tag) + " is misconfigured and has no linked objectives");
	}
	*/
}

void AAGP_ZombifiedES2Objective::AccomplishObjective(APawn* aInstigator, AController* Killer)
{
	int32 iMover = 0;
	int32 iObjective = 0;
	AController* ctrlIterator = nullptr;
	if (bDisabled)
	{
		return;
	}
	/*
	if (((bPlayerRadioedObectiveInfo && (fpTimeUntilESSInvestigateRadioCompletes > 0)) && (fpTimeUntilESSInvestigateRadioCompletes > GetWorld()->GetTimeSeconds())) || (!bFirstObjectFound))
	{
		if (Cast<AHumanController>(Instigator.Controller) != nullptr)
		{
			Cast<AHumanController>(Instigator.Controller).ClientMessage("You must wait for the S2's instructions to finish.");
		}
		return;
	}
	Log("Trying to keep the other side from using an ES2 Object.");
	if ((bPlayerRadioedObectiveInfo && (ctrlrESSReporter != nullptr)) && (ctrlrESSReporter.PlayerReplicationInfo.Team.TeamIndex != Instigator.Controller.PlayerReplicationInfo.Team.TeamIndex))
	{
		Log("ES2 objective owned by the other team");
		return;
	}
	Log("Activation message: " + sActivationMessage);
	if (moverLinkedToUnlock.Num() > 0)
	{
		for (iMover = 0; iMover < moverLinkedToUnlock.Num(); iMover++)
		{
			Log("Activating linked mover: " + FString::FromInt(moverLinkedToUnlock[iMover]));
			moverLinkedToUnlock[iMover].bUseControl = false;
		}
	}
	bDisabled = true;
	ObjectiveOnCompass = 1;
	HUDText = "";
	if (agpoLinkedObjective.Num() > 0)
	{
		hcInstigator = Cast<AHumanController>(Instigator.Controller);
		if ((Cast<AHumanController>(Instigator.Controller).PlayerReplicationInfo != nullptr) && (Cast<AHumanController>(Instigator.Controller).PlayerReplicationInfo.Team != nullptr))
		{
			for (ctrlIterator = Level.ControllerList; ctrlIterator != nullptr; ctrlIterator = ctrlIterator.nextController)
			{
				if (ctrlIterator == Instigator.Controller)
				{
				}
				if (((Level.Game.Stats != nullptr) && (Cast<AHumanController>(ctrlIterator) != nullptr)) && (Cast<AHumanController>(ctrlIterator).PlayerStatsIndex >= 0))
				{
					Level.Game.Stats.PlayerStats[HumanController(ctrlIterator).PlayerStatsIndex].StatEvent_ESSObjectExaminedByOtherPlayer();
				}
			}
			if (bPlayerRadioedObectiveInfo)
			{
				if (((Level.Game.Stats != nullptr) && (Cast<AHumanController>(Instigator.Controller) != nullptr)) && (Cast<AHumanController>(Instigator.Controller).PlayerStatsIndex >= 0))
				{
					Level.Game.Stats.PlayerStats[HumanController(Instigator.Controller).PlayerStatsIndex].StatEvent_ESSPostRadioExaminedObject();
				}
				Cast<AHumanController>(Instigator.Controller).ClientNotifyAdminMessage(sActivationMessage);
				Level.Game.BroadcastHandler.BroadcastTeamByIndex(byte(Cast<AHumanController>(Instigator.Controller).PlayerReplicationInfo.Team.TeamIndex), sActivatedRadioMessage, "ReportESSObjective");
				SetCustomTimer((1.5 + (FMath::FRand() * 3)), false, "RadioContentAcknowledgement");
			}
			else
			{
				if (((Level.Game.Stats != nullptr) && (Cast<AHumanController>(Instigator.Controller) != nullptr)) && (Cast<AHumanController>(Instigator.Controller).PlayerStatsIndex >= 0))
				{
					Level.Game.Stats.PlayerStats[HumanController(Instigator.Controller).PlayerStatsIndex].StatEvent_ESSNoRadioExaminedObject();
				}
				Cast<AHumanController>(Instigator.Controller).ClientESSNotifyAdminMessage(sActivationMessage + "  It would have been wise to radio (<ESSObjectiveReport>) this in  before looking inside.");
				Cast<AHumanController>(Instigator.Controller).ClientESSConsoleMessage("Proper procedure is to report (<ESSObjectiveReport>) items like this to your company commander or squad leader before examining them.");
			}
		}
		else
		{
			if (bPlayerRadioedObectiveInfo)
			{
				Cast<AHumanController>(Instigator.Controller).ClientNotifyAdminMessage(sActivationMessage);
				Cast<AHumanController>(Instigator.Controller).ClientMessage(Cast<AHumanController>(Instigator.Controller).UserName + " Radios: " + sActivatedRadioMessage);
				SetCustomTimer((1.5 + (FMath::FRand() * 3)), false, "RadioContentAcknowledgement");
			}
			else
			{
				Cast<AHumanController>(Instigator.Controller).ClientESSNotifyAdminMessage(sActivationMessage + "  It would have been wise to radio (<ESSObjectiveReport>) this in before looking inside.");
				Cast<AHumanController>(Instigator.Controller).ClientESSConsoleMessage("Proper procedure is to report (<ESSObjectiveReport>) items like this to your squad leader before examining them.");
			}
		}
		for (iObjective = 0; iObjective < agpoLinkedObjective.Num(); iObjective++)
		{
			Log("Activating linked objective: " + FString::FromInt(agpoLinkedObjective[iObjective]));
			Log("Activated radio message: " + sActivatedRadioMessage);
			agpoLinkedObjective[iObjective].DefenseDescription = "";
			agpoLinkedObjective[iObjective].bDisabled = false;
			agpoLinkedObjective[iObjective].bHidden = false;
			agpoLinkedObjective[iObjective].FailedDefenseMessage = "";
			if ((Cast<AHumanController>(Instigator.Controller).PlayerReplicationInfo != nullptr) && (Cast<AHumanController>(Instigator.Controller).PlayerReplicationInfo.Team != nullptr))
			{
				agpoLinkedObjective[iObjective].AttackTeam = uint8(Cast<AHumanController>(Instigator.Controller).PlayerReplicationInfo.Team.TeamIndex);
				if (bPlayerRadioedObectiveInfo)
				{
					agpoLinkedObjective[iObjective].bPlayerRadioedObectiveInfo = true;
					agpoLinkedObjective[iObjective].bESSObjectiveCompleteSoundPlayerOnly = false;
					agpoLinkedObjective[iObjective].sndESSObjectiveCompletionAcknowledgement = sndESSObjectiveCompleteGoodProcedure;
					agpoLinkedObjective[iObjective].pawnMustBeUsedBy = nullptr;
					agpoLinkedObjective[iObjective].Score_AssaultPlayer = Score_AssaultPlayer;
					agpoLinkedObjective[iObjective].Score_AssaultTeam = Score_AssaultTeam;
					agpoLinkedObjective[iObjective].Score_AssaultHelper = Score_AssaultHelper;
					if (Cast<AHumanController>(Instigator.Controller).PlayerReplicationInfo.Team.TeamIndex == 0)
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
					agpoLinkedObjective[iObjective].pawnMustBeUsedBy = Instigator;
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
