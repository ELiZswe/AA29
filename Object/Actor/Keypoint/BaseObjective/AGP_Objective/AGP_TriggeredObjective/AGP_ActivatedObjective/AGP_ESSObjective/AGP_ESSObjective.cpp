// All the original content belonged to the US Army


#include "AGP_ESSObjective.h"

AAGP_ESSObjective::AAGP_ESSObjective(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{
	sActivatedRadioMessage					= "I have examined the odd package and the location is ";
	sndESSObjectiveCompleteGoodProcedure	= LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_ESSAudio/S2RadioMessages/S2ESSObjectiveTakenProperly.S2ESSObjectiveTakenProperly"), NULL, LOAD_None, NULL);
	sndESSObjectiveCompleteBadProcedure		= LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_ESSAudio/S2RadioMessages/S2ESSObjectiveTakenBadProcedure.S2ESSObjectiveTakenBadProcedure"), NULL, LOAD_None, NULL);
	sndESSObjectiveRadioAcknowledgement		= LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_ESSAudio/S2RadioMessages/S2AcknowledgeMapFound.S2AcknowledgeMapFound"), NULL, LOAD_None, NULL);
	sDiscoveredRadioMessage					= "I have discovered something odd.  There's a package which doesn't look like it belongs here.";
	//bProp = true;
}

void AAGP_ESSObjective::BeginPlay()
{
	Super::BeginPlay();
	/*
		Reset();
	*/
}
void AAGP_ESSObjective::GetDescriptionByController(AController* listener)
{
	/*
		Return "";
	*/
}
void AAGP_ESSObjective::Reset()
{
	/*
		local Mover moverIterator;
		local AGP.AGP_Objective agpobjIterator;
		local array<AGP_Objective> aagpoFoundLinkedObjectives;
		Reset();
		bPlayerRadioedObectiveInfo=False;
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
		}
		ForEach AllActors(Class'AGP_Objective',agpobjIterator,nameLinkedObjectiveToActivate)
		{
			if(agpobjIterator.IsA('AGP_ESSObjective'))
			{
			}
			else
			{
				aagpoFoundLinkedObjectives.insert(0,1);
				aagpoFoundLinkedObjectives[0]=agpobjIterator;
				aagpoFoundLinkedObjectives[0].ObjectiveOnCompass=agpobjIterator.1;
				aagpoFoundLinkedObjectives[0].bDisabled=True;
				aagpoFoundLinkedObjectives[0].bHidden=True;
			}
		}
		if(aagpoFoundLinkedObjectives.Length > 0)
		{
			agpoLinkedObjective.insert(0,1);
			agpoLinkedObjective[0]=aagpoFoundLinkedObjectives[Rand(aagpoFoundLinkedObjectives.Length)];
		}
		else
		{
			Log(Self $ "." $ Tag $ " is misconfigured and has no linked objectives");
		}
	*/
}
void AAGP_ESSObjective::AccomplishObjective(APawn* _Instigator, AController* Killer)
{
	/*
		local int iMover;
		local int iObjective;
		local Controller ctrlIterator;
		if(bDisabled)
		{
			Return;
		}
		if(bPlayerRadioedObectiveInfo && fpTimeUntilESSInvestigateRadioCompletes > 0 && fpTimeUntilESSInvestigateRadioCompletes > GetWorld()->GetTimeSeconds())
		{
			if(HumanController(Instigator.Controller) != None)
			{
				HumanController(Instigator.Controller).ClientMessage("You must wait for the S2's instructions to finish.");
			}
			Return;
		}
		if(bPlayerRadioedObectiveInfo && ctrlrESSReporter != None && ctrlrESSReporter.PlayerReplicationInfo.Team.TeamIndex != Instigator.Controller.PlayerReplicationInfo.Team.TeamIndex)
		{
			Return;
		}
		if(moverLinkedToUnlock.Length > 0)
		{
			for(iMover=0; iMover<moverLinkedToUnlock.Length; iMover++)
			{
				moverLinkedToUnlock[iMover].bUseControl=False;
			}
		}
		bDisabled=True;
		ObjectiveOnCompass=1;
		HUDText="";
		if(agpoLinkedObjective.Length > 0)
		{
			hcInstigator=HumanController(Instigator.Controller);
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
					SetCustomTimer(1.5 + FRand() * 3,False,'RadioContentAcknowledgement');
				}
				else
				{
					if(Level.Game.Stats != None && HumanController(Instigator.Controller) != None && HumanController(Instigator.Controller).PlayerStatsIndex >= 0)
					{
						Level.Game.Stats.PlayerStats[HumanController(Instigator.Controller).PlayerStatsIndex].StatEvent_ESSNoRadioExaminedObject();
					}
					HumanController(Instigator.Controller).ClientESSNotifyAdminMessage(sActivationMessage $ "  It would have been wise to radio(<ESSObjectiveReport>) this in  before looking inside.");
					HumanController(Instigator.Controller).ClientESSConsoleMessage("Proper procedure is to report(<ESSObjectiveReport>) items like this to your company commander or squad leader before examining them.");
				}
			}
			else
			{
				if(bPlayerRadioedObectiveInfo)
				{
					HumanController(Instigator.Controller).ClientNotifyAdminMessage(sActivationMessage);
					HumanController(Instigator.Controller).ClientMessage(HumanController(Instigator.Controller).UserName $ " Radios: " $ sActivatedRadioMessage);
					SetCustomTimer(1.5 + FRand() * 3,False,'RadioContentAcknowledgement');
				}
				else
				{
					HumanController(Instigator.Controller).ClientESSNotifyAdminMessage(sActivationMessage $ "  It would have been wise to radio(<ESSObjectiveReport>) this in before looking inside.");
					HumanController(Instigator.Controller).ClientESSConsoleMessage("Proper procedure is to report(<ESSObjectiveReport>) items like this to your squad leader before examining them.");
				}
			}
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
						agpoLinkedObjective[iObjective].bPlayerRadioedObectiveInfo=True;
						agpoLinkedObjective[iObjective].bESSObjectiveCompleteSoundPlayerOnly=False;
						agpoLinkedObjective[iObjective].sndESSObjectiveCompletionAcknowledgement=sndESSObjectiveCompleteGoodProcedure;
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
						agpoLinkedObjective[iObjective].sndESSObjectiveCompletionAcknowledgement=sndESSObjectiveCompleteBadProcedure;
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
				}
			}
		}
	*/
}
void AAGP_ESSObjective::RadioContentAcknowledgement()
{
	/*
		hcInstigator.ClientESSRadioInvestigateOrder(sndESSObjectiveRadioAcknowledgement);
	*/
}
void AAGP_ESSObjective::RadioActivationOfObject(AHumanController* HC)
{
}
void AAGP_ESSObjective::ReplaceCommandString(FString Text)
{
	/*
		local int pos1;
		local int pos2;
		local string ActionKey;
		local string TempStr;
		local string FinalStr;
		pos1=InStr(Text,"<");
		pos2=InStr(Text,">");
		if(pos1 < 0 && pos2 < 0)
		{
			Return Text;
		}
		if(pos1 >= 0 && pos2 >= 0)
		{
			TempStr=Left(Text,pos1);
			ActionKey=Left(Text,pos2);
			ActionKey=Right(ActionKey,Len(ActionKey) - pos1 + 1);
			TempStr=TempStr $ GetCommandKey(ActionKey);
			Text=Right(Text,Len(Text) - pos2 + 1);
			FinalStr=FinalStr $ TempStr;
			pos1=InStr(Text,"<");
			pos2=InStr(Text,">");
		}
		FinalStr=FinalStr $ Text;
		Return FinalStr;
	*/
}
void AAGP_ESSObjective::GetCommandKey(FString cmdname)
{
	/*
		local Console Console;
		local string cmdkeyname;
		local Interactions.EInputKey cmdkey;
		local int Count;
		local string retval;
		Console=hcInstigator.Player.Console;
		retval="<";
		cmdkeyname="";
		Count=0;
		if(Console.GetCommandKey(cmdname,cmdkey,cmdkeyname,Count))
		{
			if(Count > 0)
			{
				retval=retval $ " or ";
			}
			retval=retval $ Caps(cmdkeyname);
			Count ++;
		}
		if(retval == "")
		{
			Return "ERROR!";
		}
		Return retval $ ">";
	*/
}
