// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseCivilianController/NPCBaseCivilianController.h"

ANPCBaseCivilianController::ANPCBaseCivilianController()
{
	/*
	asCivilianComments(0) = Sound'S_AAO_LVL_MedicTraining.NConv.J1_Date'
		asCivilianComments(1) = Sound'S_AAO_LVL_MedicTraining.NConv.N1_Lunch'
		asCivilianComments(2) = Sound'S_AAO_LVL_MedicTraining.NConv.N1_Movie'
		asCivilianComments(3) = Sound'S_AAO_LVL_MedicTraining.NMisc.N_Waiting'
		asCivilianComments(4) = Sound'S_AAO_LVL_MedicTraining.NConv.N1_Break'
		asCivilianComments(5) = Sound'S_AAO_LVL_MedicTraining.NConv.N1_Lunch'
		asCivilianComments(6) = Sound'S_AAO_LVL_MedicTraining.NConv.N1_Movie'
		asCivilianComments(7) = Sound'S_AAO_LVL_MedicTraining.NConv.N1_PX'
		asCivilianComments(8) = Sound'S_AAO_LVL_MedicTraining.NConv.N1_Break'
		asCivilianGroans(0) = Sound'S_AAO_LVL_MedicField.Soldiers.Walter_Groan'
		asCivilianGroans(1) = Sound'S_AAO_LVL_MedicField.Soldiers.Walter_Groan2'
		asCivilianWarnings(0) = Sound'S_AAO_LVL_MedicTraining.NMisc.J_YoureNot'
		asCivilianMaleInjured(0) = Sound'S_AAO_NPC.Civilian.s_npc_civ_male_injury1'
		asCivilianMaleInjured(1) = Sound'S_AAO_NPC.Civilian.s_npc_civ_male_injury2'
		asCivilianMaleInjured(2) = Sound'S_AAO_NPC.Civilian.s_npc_civ_male_injury3'
		asCivilianMaleInjured(3) = Sound'S_AAO_NPC.Civilian.s_npc_civ_male_injury4'
		asCivilianFemaleInjured(0) = Sound'S_AAO_NPC.Civilian.s_npc_civ_female_injury1'
		asCivilianFemaleInjured(1) = Sound'S_AAO_NPC.Civilian.s_npc_civ_female_injury2'
		asCivilianFemaleInjured(2) = Sound'S_AAO_NPC.Civilian.s_npc_civ_female_injury3'
		asCivilianFemaleInjured(3) = Sound'S_AAO_NPC.Civilian.s_npc_civ_female_injury4'
		*/
	anameDefFemaleSeePlayer                   = {"Amber_Hi_1","Amber_Hi_2","Amber_YouShouldntBeInHere_1","Amber_YouShouldntBeInHere_2","Amber_WhatDoYouWant_1","Amber_WhatDoYouWant_2"};
	anameDefFemaleCannotFollow                = {"Amber_ItsImpossibleToGetThere_1","Amber_ItsImpossibleToGetThere_2","Amber_TheresNoWayToGetThere_1","Amber_TheresNoWayToGetThere_2","Amber_ICantGetThere_1","Amber_ICantGetThere_2"};
	anameDefFemaleWaitForNPC                  = {"Amber_WaitUp_1","Amber_WaitUp_2","Amber_WaitforMe_1","Amber_WaitforMe_2","Amber_HowMuchFarther_1","Amber_HowMuchFarther_2"};
	anameDefFemaleAcknowledgeOrderPositive    = {"Amber_OK_1","Amber_OK_2","Amber_Sure_1","Amber_Sure_2","Amber_Fine_1","Amber_Fine_2","Amber_WhateverYouSay_1","Amber_WhateverYouSay_2"};
	anameDefFemaleAcknowledgeOrderNegative    = {"Amber_ICantDoThat_1","Amber_ICantDoThat_2","Amber_IDontThinkSo_1","Amber_IDontThinkSo_2","Amber_No_1","Amber_No_2","Amber_ThatDoesntSoundLikeAGoodIdea_1","Amber_ThatDoesntSoundLikeAGoodIdea_2"};
	anameDefFemaleFrightened                  = {"Amber_BeCarefulWithThat_1","Amber_BeCarefulWithThat_2","Amber_LookOut_1","Amber_LookOut_2","Amber_StopShooting_1","Amber_StopShooting_2","Amber_DontShoot_1"};
	anameDefFemaleWounded                     = {"Amber_ImHitHelpMe_1","Amber_GetMeADoctor_1"};
	anameAltDefFemaleSeePlayer                = {"Rae_Hi_1","Rae_Hi_2","Rae_YouShouldntBeInHere_1","Rae_YouShouldntBeInHere_2","Rae_WhatDoYouWant_1","Rae_WhatDoYouWant_2"};
	anameAltDefFemaleCannotFollow             = {"Rae_ItsImpossibleToGetThere_1","Rae_ItsImpossibleToGetThere_2","Rae_TheresNoWayToGetThere_1","Rae_TheresNoWayToGetThere_2","Rae_ICantGetThere_1","Rae_ICantGetThere_2"};
	anameAltDefFemaleWaitForNPC               = {"Rae_WaitUp_1","Rae_WaitUp_2","Rae_WaitforMe_1","Rae_WaitforMe_2","Rae_HowMuchFarther_1","Rae_HowMuchFarther_2"};
	anameAltDefFemaleAcknowledgeOrderPositive = {"Rae_OK_1","Rae_OK_2","Rae_Sure_1","Rae_Sure_2","Rae_Fine_1","Rae_Fine_2","Rae_WhateverYouSay_1","Rae_WhateverYouSay_2"};
	anameAltDefFemaleAcknowledgeOrderNegative = {"Rae_ICantDoThat_1","Rae_ICantDoThat_2","Rae_IDontThinkSo_1","Rae_IDontThinkSo_2","Rae_No_1","Rae_No_2","Rae_ThatDoesntSoundLikeAGoodIdea_1","Rae_ThatDoesntSoundLikeAGoodIdea_2"};
	anameAltDefFemaleFrightened               = {"Rae_BeCarefulWithThat_1","Rae_BeCarefulWithThat_2","Rae_LookOut_1","Rae_LookOut_2","Rae_StopShooting_1","Rae_StopShooting_2","Rae_DontShoot_1","Rae_DontShoot_2"};
	anameAltDefFemaleWounded                  = {"Rae_ImHitHelpMe_1","Rae_ImHitHelpMe_1","Rae_GetMeADoctor_1","Rae_GetMeADoctor_2"};

		/*
		asoundDefFemaleSeePlayer(0) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_Hi_1'
		asoundDefFemaleSeePlayer(1) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_Hi_2'
		asoundDefFemaleSeePlayer(2) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_YouShouldntBeInHere_1'
		asoundDefFemaleSeePlayer(3) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_YouShouldntBeInHere_2'
		asoundDefFemaleSeePlayer(4) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_WhatDoYouWant_1'
		asoundDefFemaleSeePlayer(5) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_WhatDoYouWant_2'
		asoundDefFemaleCannotFollow(0) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_ItsImpossibleToGetThere_1'
		asoundDefFemaleCannotFollow(1) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_ItsImpossibleToGetThere_2'
		asoundDefFemaleCannotFollow(2) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_TheresNoWayToGetThere_1'
		asoundDefFemaleCannotFollow(3) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_TheresNoWayToGetThere_2'
		asoundDefFemaleCannotFollow(4) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_ICantGetThere_1'
		asoundDefFemaleCannotFollow(5) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_ICantGetThere_2'
		asoundDefFemaleWaitForNPC(0) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_WaitUp_1'
		asoundDefFemaleWaitForNPC(1) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_WaitUp_2'
		asoundDefFemaleWaitForNPC(2) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_WaitforMe_1'
		asoundDefFemaleWaitForNPC(3) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_WaitforMe_2'
		asoundDefFemaleWaitForNPC(4) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_HowMuchFarther_1'
		asoundDefFemaleWaitForNPC(5) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_HowMuchFarther_2'
		asoundDefFemaleAcknowledgeOrderPositive(0) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_OK_1'
		asoundDefFemaleAcknowledgeOrderPositive(1) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_OK_2'
		asoundDefFemaleAcknowledgeOrderPositive(2) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_Sure_1'
		asoundDefFemaleAcknowledgeOrderPositive(3) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_Sure_2'
		asoundDefFemaleAcknowledgeOrderPositive(4) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_Fine_1'
		asoundDefFemaleAcknowledgeOrderPositive(5) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_Fine_2'
		asoundDefFemaleAcknowledgeOrderPositive(6) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_WhateverYouSay_1'
		asoundDefFemaleAcknowledgeOrderPositive(7) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_WhateverYouSay_2'
		asoundDefFemaleAcknowledgeOrderNegative(0) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_ICantDoThat_1'
		asoundDefFemaleAcknowledgeOrderNegative(1) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_ICantDoThat_2'
		asoundDefFemaleAcknowledgeOrderNegative(2) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_IDontThinkSo_1'
		asoundDefFemaleAcknowledgeOrderNegative(3) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_IDontThinkSo_2'
		asoundDefFemaleAcknowledgeOrderNegative(4) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_No_1'
		asoundDefFemaleAcknowledgeOrderNegative(5) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_No_2'
		asoundDefFemaleAcknowledgeOrderNegative(6) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_ThatDoesntSoundLikeAGoodIdea_1'
		asoundDefFemaleAcknowledgeOrderNegative(7) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_ThatDoesntSoundLikeAGoodIdea_2'
		asoundDefFemaleFrightened(0) = Sound'S_AAO_NPCCiv.Amber_BeCarefulWithThat_1'
		asoundDefFemaleFrightened(1) = Sound'S_AAO_NPCCiv.Amber_BeCarefulWithThat_2'
		asoundDefFemaleFrightened(2) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_LookOut_1'
		asoundDefFemaleFrightened(3) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_LookOut_2'
		asoundDefFemaleFrightened(4) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_StopShooting_1'
		asoundDefFemaleFrightened(5) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_StopShooting_2'
		asoundDefFemaleFrightened(6) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_DontShoot_1'
		asoundDefFemaleWounded(0) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_ImHitHelpMe_1'
		asoundDefFemaleWounded(1) = Sound'S_AAO_NPCCiv.AmberCiv.Amber_GetMeADoctor_1'
		asoundAltDefFemaleSeePlayer(0) = Sound'S_AAO_NPCCiv.Rae_Hi_1'
		asoundAltDefFemaleSeePlayer(1) = Sound'S_AAO_NPCCiv.Rae_Hi_2'
		asoundAltDefFemaleSeePlayer(2) = Sound'S_AAO_NPCCiv.Rae_YouShouldntBeInHere_1'
		asoundAltDefFemaleSeePlayer(3) = Sound'S_AAO_NPCCiv.Rae_YouShouldntBeInHere_2'
		asoundAltDefFemaleSeePlayer(4) = Sound'S_AAO_NPCCiv.Rae_WhatDoYouWant_1'
		asoundAltDefFemaleSeePlayer(5) = Sound'S_AAO_NPCCiv.Rae_WhatDoYouWant_2'
		asoundAltDefFemaleCannotFollow(0) = Sound'S_AAO_NPCCiv.Rae_ItsImpossibleToGetThere_1'
		asoundAltDefFemaleCannotFollow(1) = Sound'S_AAO_NPCCiv.Rae_ItsImpossibleToGetThere_2'
		asoundAltDefFemaleCannotFollow(2) = Sound'S_AAO_NPCCiv.Rae_TheresNoWayToGetThere_1'
		asoundAltDefFemaleCannotFollow(3) = Sound'S_AAO_NPCCiv.Rae_TheresNoWayToGetThere_2'
		asoundAltDefFemaleCannotFollow(4) = Sound'S_AAO_NPCCiv.Rae_ICantGetThere_1'
		asoundAltDefFemaleCannotFollow(5) = Sound'S_AAO_NPCCiv.Rae_ICantGetThere_2'
		asoundAltDefFemaleWaitForNPC(0) = Sound'S_AAO_NPCCiv.Rae_WaitUp_1'
		asoundAltDefFemaleWaitForNPC(1) = Sound'S_AAO_NPCCiv.Rae_WaitUp_2'
		asoundAltDefFemaleWaitForNPC(2) = Sound'S_AAO_NPCCiv.Rae_WaitforMe_1'
		asoundAltDefFemaleWaitForNPC(3) = Sound'S_AAO_NPCCiv.Rae_WaitforMe_2'
		asoundAltDefFemaleWaitForNPC(4) = Sound'S_AAO_NPCCiv.Rae_HowMuchFarther_1'
		asoundAltDefFemaleWaitForNPC(5) = Sound'S_AAO_NPCCiv.Rae_HowMuchFarther_2'
		asoundAltDefFemaleAcknowledgeOrderPositive(0) = Sound'S_AAO_NPCCiv.Rae_OK_1'
		asoundAltDefFemaleAcknowledgeOrderPositive(1) = Sound'S_AAO_NPCCiv.Rae_OK_2'
		asoundAltDefFemaleAcknowledgeOrderPositive(2) = Sound'S_AAO_NPCCiv.Rae_Sure_1'
		asoundAltDefFemaleAcknowledgeOrderPositive(3) = Sound'S_AAO_NPCCiv.Rae_Sure_2'
		asoundAltDefFemaleAcknowledgeOrderPositive(4) = Sound'S_AAO_NPCCiv.Rae_Fine_1'
		asoundAltDefFemaleAcknowledgeOrderPositive(5) = Sound'S_AAO_NPCCiv.Rae_Fine_2'
		asoundAltDefFemaleAcknowledgeOrderPositive(6) = Sound'S_AAO_NPCCiv.Rae_WhateverYouSay_1'
		asoundAltDefFemaleAcknowledgeOrderPositive(7) = Sound'S_AAO_NPCCiv.Rae_WhateverYouSay_2'
		asoundAltDefFemaleAcknowledgeOrderNegative(0) = Sound'S_AAO_NPCCiv.Rae_ICantDoThat_1'
		asoundAltDefFemaleAcknowledgeOrderNegative(1) = Sound'S_AAO_NPCCiv.Rae_ICantDoThat_2'
		asoundAltDefFemaleAcknowledgeOrderNegative(2) = Sound'S_AAO_NPCCiv.Rae_IDontThinkSo_1'
		asoundAltDefFemaleAcknowledgeOrderNegative(3) = Sound'S_AAO_NPCCiv.Rae_IDontThinkSo_2'
		asoundAltDefFemaleAcknowledgeOrderNegative(4) = Sound'S_AAO_NPCCiv.Rae_No_1'
		asoundAltDefFemaleAcknowledgeOrderNegative(5) = Sound'S_AAO_NPCCiv.Rae_No_2'
		asoundAltDefFemaleAcknowledgeOrderNegative(6) = Sound'S_AAO_NPCCiv.Rae_ThatDoesntSoundLikeAGoodIdea_1'
		asoundAltDefFemaleAcknowledgeOrderNegative(7) = Sound'S_AAO_NPCCiv.Rae_ThatDoesntSoundLikeAGoodIdea_2'
		asoundAltDefFemaleFrightened(0) = Sound'S_AAO_NPCCiv.Rae_BeCarefulWithThat_1'
		asoundAltDefFemaleFrightened(1) = Sound'S_AAO_NPCCiv.Rae_BeCarefulWithThat_2'
		asoundAltDefFemaleFrightened(2) = Sound'S_AAO_NPCCiv.Rae_LookOut_1'
		asoundAltDefFemaleFrightened(3) = Sound'S_AAO_NPCCiv.Rae_LookOut_2'
		asoundAltDefFemaleFrightened(4) = Sound'S_AAO_NPCCiv.Rae_StopShooting_1'
		asoundAltDefFemaleFrightened(5) = Sound'S_AAO_NPCCiv.Rae_StopShooting_2'
		asoundAltDefFemaleFrightened(6) = Sound'S_AAO_NPCCiv.Rae_DontShoot_1'
		asoundAltDefFemaleFrightened(7) = Sound'S_AAO_NPCCiv.Rae_DontShoot_2'
		asoundAltDefFemaleWounded(0) = Sound'S_AAO_NPCCiv.Rae_ImHitHelpMe_1'
		asoundAltDefFemaleWounded(1) = Sound'S_AAO_NPCCiv.Rae_ImHitHelpMe_1'
		asoundAltDefFemaleWounded(2) = Sound'S_AAO_NPCCiv.Rae_GetMeADoctor_1'
		asoundAltDefFemaleWounded(3) = Sound'S_AAO_NPCCiv.Rae_GetMeADoctor_2'
	*/
}

/*
State WalkingPatrol
{
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
		Super::NotifyPlayerPawnInSight(pawnSeen);
		PlayRandomLipSynch(anameSeePlayer);
	}
	Event bool NotifyBump(Actor Other)
	{
		PlayRandomLipSynch(anameSeePlayer);
		if (((NPCPathNode(pnCurrentNodeLeadingToPathNode) != None) && NPCPathNode(pnCurrentNodeLeadingToPathNode).bNarrowPassageway) || ((pnCurrentPathNode != None) && pnCurrentPathNode.bNarrowPassageway))
		{
			if (IsLocationInFront(Other.Location))
			{
				bAscendingNodeDirection=(! bAscendingNodeDirection);
				FindNextPatrolPathNode();
				GotoState("ReturnToPatrol");
				return true;
			}
		}
		else
		{
			return Super::NotifyBump(Other);
		}
	}
	Function Timer()
	{
		Super::Timer();
		if ((Level.TimeSeconds > (fpTimeOfLastPawnSeen + 5)) && (Focus != pnCurrentPathNode))
		{
			Focus=pnCurrentPathNode;
		}
	}
	Function NotifyNPCSeen(Pawn Seen)
	{
		if (fpNPCMaxVisualRange == 0)
		{
			return;
		}
		if (Abs(VSize((Seen.Location - Pawn.Location))) > float(150))
		{
			return;
		}
		if ((Seen != pawnLastSeen) && ((fpTimeOfLastPawnSeen == 0) || (Level.TimeSeconds > (fpTimeOfLastPawnSeen + float(30)))))
		{
			NPCLog(string(Self.Tag) $ " NPC seen - " $ string(Seen) $ "." $ string(Seen.Tag) $ " checking for conversation packs");
			pawnLastSeen=Seen;
			fpTimeOfLastPawnSeen=Level.TimeSeconds;
			if (DetermineConversationPackAvailable(Seen))
			{
				NPCChangeState("NPCTalkToNPC");
			}
		}
	}
	Function ArrivedAtPathnode()
	{
		local AGP_Pawn agpNPC;
		Super::ArrivedAtPathnode();
		if (fpNPCMaxVisualRange == 0)
		{
			return;
		}
		ForEach RadiusActors(class'AGP.AGP_Pawn',agpNPC,150,Pawn.Location)
		{
			NPCLog("Found potential pawn in 3 meter range");
			if ((! agpNPC.IsHumanControlled()) && (agpNPC != Pawn))
			{
				NPCLog("Found NPC pawn");
				fpTimeToTurnBackAround=0;
				NotifyNPCSeen(agpNPC);
			}
			else
			{
			}
		}
	}
}
*/

/*
State NPCTalkToPlayer
{
	Function NotifyItemOfInterestFound(NPCItemOfInterest npcioi)
	{
	}
	Function Timer()
	{
		Global.pnCurrentNodeLeadingToPathNode();
		if (Level.TimeSeconds > fpTimeToTurnBackAround)
		{
			fpTimeToTurnBackAround=0;
			Focus=pnCurrentPathNode;
			NPCChangeState("ReturnToPatrol");
		}
	}
Begin:
	fpTimeToTurnBackAround=(Level.TimeSeconds + (FRand() * 5));
	StopMovement();
	Focus=pawnLastSeen;
	bRotateToDesired=true;
}
*/

/*
State PawnStartsAsDummy
{
	Event NotifyPlayerPawnWatchingMe(Pawn pawnSeen)
	{
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, Pawn pawnHeard)
	{
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AGP_Weapon agpwWeaponHeard, Vector vSoundLocation)
	{
	}
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
		PlayRandomLipSynch(anameSeePlayer);
		Super::NotifyPlayerPawnInSight(pawnSeen);
	}
	Function NotifyGrenadeLanded(ThrowWeaponPickup twpGrenade)
	{
	}
	Function NotifyItemOfInterestFound(NPCItemOfInterest npcioi)
	{
	}
}
*/

/*
State NPCTalkToNPC
{
	Function NotifyItemOfInterestFound(NPCItemOfInterest npcioi)
	{
	}
	Function NotifyNPCSeen(Pawn Seen)
	{
	}
	Function EndState()
	{
		bBusyPlayConversationPack=false;
	}
	Function BeginState()
	{
	}
	Function Timer()
	{
		Global.pnCurrentNodeLeadingToPathNode();
	}
	Function NotifyConversationPackStart(NPCConversationPack npccpNew)
	{
		npccpCurrentConversation=npccpNew;
	}
	Function NotifyConversationPackEnded(NPCConversationPack npccpJustEnded)
	{
		NPCLog("Conversation just ended");
		bBusyPlayConversationPack=false;
		fpTimeToTurnBackAround=0;
		Focus=pnCurrentPathNode;
		NPCChangeState("ReturnToPatrol");
	}
	Function DetermineConversationPack()
	{
		int32 iConvPackToUse = 0;
		if (anpccpConversations.Length > 0)
		{
			for (iConvPackToUse=0; iConvPackToUse<anpccpConversations.Length; iConvPackToUse++)
			{
				if (anpccpConversations[iConvPackToUse].IsPawnMemberOfConversation(pawnLastSeen))
				{
					anpccpConversations[iConvPackToUse].NPCStartConversation(Self);
					bBusyPlayConversationPack=true;
					fpTimeToTurnBackAround=0;
					if (pawnLastSeen.IsA("NPCBaseCivilianController"))
					{
						NPCBaseCivilianController(pawnLastSeen.Controller).NPCChangeState("NPCTalkToNPC","AlreadyInConversation");
					}
					return;
				}
			}
		}
	}
Begin:
	NPCLog("Begin entered");
	StopMovement();
	Focus=pawnLastSeen;
	bRotateToDesired=true;
	if (! bBusyPlayConversationPack)
	{
		DetermineConversationPack();
	}
	NPCLog("Already in conversation");
	StopMovement();
	Focus=pawnLastSeen;
	bRotateToDesired=true;
}
*/

/*
State LookAtItemOfInterest
{
	Function EndState()
	{
		if (Pawn.IsAnimating())
		{
			Pawn.StopAnimating();
		}
		Stand();
		Super::EndState();
	}
	Function Timer()
	{
		Global.pnCurrentNodeLeadingToPathNode();
		if ((fpEndTimeForViewingItemOfInterest > 0) && (Level.TimeSeconds > fpEndTimeForViewingItemOfInterest))
		{
			NPCLog("Hit end of item of interest time");
			NPCChangeState("WalkingPatrol");
		}
	}
	Function float PlayOIOAnimation()
	{
		float fpOIOAnimLength = 0;
		if (string(NPCItemOfInterest(Focus).nameNPCAnimation) != "None")
		{
			NPCLog("OIO animation: \"" $ string(NPCItemOfInterest(Focus).nameNPCAnimation) $ "\"");
			fpOIOAnimLength=PlayCustomAnimation(NPCItemOfInterest(Focus).nameNPCAnimation);
			NPCLog("Animation length: " $ string(fpOIOAnimLength));
			return fpOIOAnimLength;
		}
	}
Begin:
	fpEndTimeForViewingItemOfInterest=0;
	if (Focus.IsA("NPCItemOfInterest"))
	{
		FinishRotation();
		MoveTo(Focus.Location,Focus,true);
		NPCLog("Arrived at IOI");
		fpEndTimeForViewingItemOfInterest=Level.TimeSeconds;
		(fpEndTimeForViewingItemOfInterest += PlayOIOAnimation());
		if (NPCItemOfInterest(Focus).sndToPlay != None)
		{
			Sleep(PlayCustomSound(NPCItemOfInterest(Focus).sndToPlay));
		}
		Sleep(NPCItemOfInterest(Focus).fpTimeToWaitHere);
	}
	NPCLog("Done setting up looking at item of interest, current time " $ string(Level.TimeSeconds) $ " end time: " $ string(fpEndTimeForViewingItemOfInterest));
}
*/

/*
State LiveGrenade
{
	Event bool NotifyBump(Actor Other)
	{
		if (((NPCPathNode(pnCurrentNodeOnPathToCover) != None) && NPCPathNode(pnCurrentNodeOnPathToCover).bNarrowPassageway) && IsLocationInFront(Other.Location))
		{
			Super::NotifyBump(Other);
			GotoState(GetStateName());
			return true;
		}
		else
		{
			return Super::NotifyBump(Other);
		}
	}
}
*/

/*
State Panic
{
	Function EndState()
	{
		if (Pawn.IsAnimating())
		{
			Pawn.StopAnimating();
		}
		Stand();
		Super::EndState();
	}
	Function NotifyNPCSeen(Pawn Seen)
	{
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AGP_Weapon agpwWeaponHeard, Vector vSoundLocation)
	{
		if (Abs(VSize((agpwWeaponHeard.Location - Pawn.Location))) < float(2500))
		{
			IncreaseNervousness(0);
			IncreaseNervousness(0);
			IncreaseNervousness(0);
			IncreaseNervousness(0);
		}
	}
	Function InitialPanicResponse()
	{
	}
	Function FName GetCoverState()
	{
		return "Cowering";
	}
	Function InCoverAction()
	{
		NPCLog("InCoverAction() - default action - stop and crouch");
		StopMovement();
		Crouch();
	}
Begin:
	if (Pawn.HasAnim("StdPanic"))
	{
		Sleep(PlayCustomAnimation("StdPanic"));
	}
	JL"Panic"
;
}
*/

/*
State FlashBanged
{
	Function FlashBangEffectEnded()
	{
		GotoState("Panic");
	}
	Function float PerformFlashedAnimation()
	{
		float fpChance = 0;
		float fpTime = 0;
		fpChance=FRand();
		fpTime=0;
		if (fpChance > 0.7)
		{
			fpTime=PlayCustomAnimation("WinceScaredA",false,((FRand() * 0.3) + 0.9));
		}
		if ((fpChance > 0.3) && (fpTime == 0))
		{
			fpTime=PlayCustomAnimation("WinceScaredB",false,((FRand() * 0.3) + 0.9));
		}
		if (fpTime == 0)
		{
			fpTime=PlayCustomAnimation("StdPanic",false,((FRand() * 0.3) + 0.9));
		}
		return fpTime;
	}
	Function float PrepForFlashing()
	{
		PlayRandomLipSynch(anameFrightened);
		return 0;
	}
	Function float PlayFinalAnimation()
	{
		return 0;
	}
}
*/

/*
State FindCoverTheBeInjured extends FindCover
{
	Function InCoverAction()
	{
		Super::InCoverAction();
		GotoState("InjuredWaitingForHealing");
	}
}
*/

/*
State injured
{
	Function NotifyItemOfInterestFound(NPCItemOfInterest npcioi)
	{
	}
	Function NotifyAnotherPawnDied(NPCBaseController npcpc)
	{
	}
	Event NotifyPlayerPawnWatchingMe(Pawn pawnSeen)
	{
	}
	Function NotifyBuzzedByBullet(Actor aShooter)
	{
	}
	Function NotifyNPCSeen(Pawn Seen)
	{
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AGP_Weapon agpwWeaponHeard, Vector vSoundLocation)
	{
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, Pawn pawnHeard)
	{
	}
	Function AdjustConfidenceByTime()
	{
	}
	Function NotifyGrenadeLanded(ThrowWeaponPickup twpGrenade)
	{
	}
	Function NotifyTakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, class<DamageType>  DamageType, Actor.BoneInfo Bone)
	{
	}
	Event bool NotifyBump(Actor Other)
	{
	}
	Event bool NotifyHitWall(Vector HitNormal, Actor Wall)
	{
	}
	Function bool NearWall(float walldist)
	{
	}
	Event EnemyNotVisible()
	{
	}
	Function SeePlayer(Pawn Seen)
	{
	}
	Function KilledBy(Pawn EventInstigator)
	{
	}
	Function BeginState()
	{
	}
	Function EndState()
	{
		NPCLog("Leaving injured state ");
		Pawn.SetCollision(true,true,true);
	}
Begin:
	NPCLog("Injured entered for NPC");
	Focus=None;
	Disable("AnimEnd");
	if (! IsInState("InjuredWaitingForHealing"))
	{
		StopMovement();
		Sleep(PlayCustomAnimation("StdPanic"));
	}
}
*/

/*
State Cowering
{
	Function NotifyItemOfInterestFound(NPCItemOfInterest npcioi)
	{
	}
	Function NotifyNPCSeen(Pawn Seen)
	{
	}
	Function AdjustConfidenceByTime()
	{
		float fpUpdateDeltaTime = 0;
		fpUpdateDeltaTime=10;
		if (Level.TimeSeconds > (fpTimeLastNervousnessChange + fpUpdateDeltaTime))
		{
			IncreaseConfidence(14);
			fpTimeLastNervousnessChange=Level.TimeSeconds;
			NPCLog("Adjusting confidence level to: " $ string(GetConfidenceLevel()));
		}
	}
	Function InitialPostureChange()
	{
	}
	Function InitialAnimation()
	{
		if (! Pawn.bIsCrouched)
		{
			Crouch();
			return;
		}
		PlayCustomAnimation("StdPanic");
	}
	Function NPCChangeState(FName nmState, FName nmLabel)
	{
		NPCLog("Request to change state out of cowering for civilian to " $ string(nmState));
		NPCChangeState(nmState,nmLabel);
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AGP_Weapon agpwWeaponHeard, Vector vSoundLocation)
	{
		if (Abs(VSize((agpwWeaponHeard.Location - Pawn.Location))) < float(2500))
		{
			IncreaseNervousness(0);
			IncreaseNervousness(0);
			IncreaseNervousness(0);
			IncreaseNervousness(0);
		}
	}
	Function NotifyBuzzedByBullet(Actor aShooter)
	{
		if (anameFrightened.Length > 0)
		{
			PlayRandomLipSynch(anameFrightened);
		}
		if ((Level.TimeSeconds - fpTimeEnteredCover) > 9)
		{
			Log("Selecting new cover, this one is bad");
			NPCChangeState("LiveGrenade","Begin");
		}
	}
	Function BeginState()
	{
		NPCLog("Civilian Cowering state entered");
		Super::BeginState();
		SetConfidenceLevel((-60 - (float(10) + (FRand() * float(20)))));
		NPCLog("Current confidence on panic entry: " $ string(GetConfidenceLevel()));
	}
Begin:
	fpTimeEnteredCover=Level.TimeSeconds;
	fpTimeLastNervousnessChange=Level.TimeSeconds;
	NPCLog("Entering Cowering state");
	StopMovement();
	InitialPostureChange();
	NPCLog("Trying to play 'panic' animation to put civilian into cowering position");
	InitialAnimation();
}
*/

/*
State InCover
{
	Function NotifyNPCSeen(Pawn Seen)
	{
	}
	Function BeginState()
	{
		NPCChangeState("Cowering");
	}
}
*/

/*
State FollowPlayer
{
	Event NotifyPlayerPawnWatchingMe(Pawn pawnSeen)
	{
	}
	Function NotifyBuzzedByBullet(Actor aShooter)
	{
		if (((AGP_Pawn(aShooter) != None) && (HumanController(AGP_Pawn(aShooter).Controller) != None)) && (HumanController(AGP_Pawn(aShooter).Controller).PlayerReplicationInfo.Team.TeamIndex == iFollowingTeam))
		{
			return;
		}
		Global.YPos(aShooter);
	}
	Event bool NotifyBump(Actor Other)
	{
		if ((pnFollowingPathNode != None) && (Other == pawnToFollow))
		{
			MoveTimer=-1;
			StopMovement();
			return true;
		}
		return Global.fpTimeToEndLastInterrupt(Other);
	}
	Event bool NotifyHitWall(Vector HitNormal, Actor Wall)
	{
		if ((Pawn.PhysicsVolume != None) && Pawn.PhysicsVolume.IsA("LadderVolume"))
		{
			Log("Hit wall while on ladder: " $ string(Wall));
			MoveTimer=-1;
			StopMovement();
			return true;
		}
		if (Wall.IsA("Mover"))
		{
			if (Mover(Wall).bNotADoor)
			{
				NPCPathLog(string(Self) $ "." $ string(Tag) $ " hit a non-door mover: " $ string(Wall) $ " Normal: " $ string(HitNormal) $ " at location " $ string(Pawn.Location));
				return false;
			}
			else
			{
				if (Mover(Wall).bClosed)
				{
					Mover(Wall).Instigator=Pawn;
					Mover(Wall).ReallyOpen();
					GotoState("FollowPlayer","WaitForOpeningDoor");
					return true;
				}
			}
			return false;
		}
		else
		{
			return Global.pos(HitNormal,Wall);
		}
	}
	Function bool DoesRouteUseLadder()
	{
		int32 iNode = 0;
		for (iNode=0; iNode<62; iNode++)
		{
			if (RouteCache[iNode] == None)
			{
				return false;
			}
			if ((RouteCache[iNode] != pnFollowingPathNode) && RouteCache[iNode].IsA("NPCLadderPathNode"))
			{
				return true;
			}
		}
		return false;
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AGP_Weapon agpwWeaponHeard, Vector vSoundLocation)
	{
		if (((AGP_Pawn(agpwWeaponHeard.Owner) != None) && (HumanController(AGP_Pawn(agpwWeaponHeard.Owner).Controller) != None)) && (HumanController(AGP_Pawn(agpwWeaponHeard.Owner).Controller).PlayerReplicationInfo.Team.TeamIndex == iFollowingTeam))
		{
			return;
		}
	}
Begin:
	if (pawnToFollow == None)
	{
		Focus=None;
		AGP_Pawn(Pawn).bEyeTrack=false;
		NPCChangeState("PawnStartsAsDummy");
		JL"End"
;
	}
	if (VSize((pawnToFollow.Location - Pawn.Location)) < fpFollowDistance)
	{
		if (pawnToFollow.bIsProne)
		{
			Prone();
		}
		else
		{
			if (pawnToFollow.bIsCrouched)
			{
				Crouch();
			}
			else
			{
				Stand();
			}
		}
		StopMovement();
		Sleep(0.5);
		JL"Begin"
;
	}
	if (VSize((pawnToFollow.Location - Pawn.Location)) > (fpFollowDistance * 5))
	{
		if (Level.TimeSeconds > (fpTimeOfLastFollowSpeech + float(10)))
		{
			fpTimeOfLastFollowSpeech=Level.TimeSeconds;
			if (anameWaitForNPC.Length > 0)
			{
				PlayRandomLipSynch(anameWaitForNPC);
			}
			else
			{
				if (bMaleVoice)
				{
					NPCSay(1,true,true);
				}
			}
		}
	}
	if ((pawnToFollow.PhysicsVolume != None) && pawnToFollow.PhysicsVolume.IsA("LadderVolume"))
	{
		Sleep(0.5);
		JL"Begin"
;
	}
	pnFollowingPathNode=PathNode(FindPathToward(pawnToFollow,true));
	if (pnFollowingPathNode == None)
	{
		if (Pawn.LineOfSightTo(pawnToFollow))
		{
			MoveToward(pawnToFollow,pawnToFollow,100,false,((pawnToFollow.bIsWalking || pawnToFollow.bIsProne) || pawnToFollow.bIsCrouched));
			Sleep(0.5);
			JL"Begin"
;
		}
		Sleep(1);
		if ((pawnToFollow.PhysicsVolume != None) && pawnToFollow.PhysicsVolume.IsA("LadderVolume"))
		{
			if (anameCannotFollow.Length > 0)
			{
				PlayRandomLipSynch(anameCannotFollow);
			}
			else
			{
				if (bMaleVoice)
				{
					NPCSay(8,true,true);
				}
			}
			pawnToFollow=None;
		}
		JL"Begin"
;
	}
	if (! ((pawnToFollow.PhysicsVolume != None) && pawnToFollow.PhysicsVolume.IsA("LadderVolume")))
	{
		if (pawnToFollow.bIsProne)
		{
			Prone();
		}
		else
		{
			if (pawnToFollow.bIsCrouched)
			{
				Crouch();
			}
			else
			{
				Stand();
			}
		}
		Run();
	}
	DebugMarkNextNode(pnFollowingPathNode);
	MoveToward(pnFollowingPathNode,pnFollowingPathNode,,false,((pawnToFollow.bIsWalking || pawnToFollow.bIsProne) || pawnToFollow.bIsCrouched));
	if (pnFollowingPathNode.IsA("NPCDoorEntryPathNode"))
	{
		if ((FindDoor(NPCDoorEntryPathNode(pnFollowingPathNode)) != None) && FindDoor(NPCDoorEntryPathNode(pnFollowingPathNode)).bClosed)
		{
			StopMovement();
			if (OpenDoor(NPCDoorEntryPathNode(pnFollowingPathNode)))
			{
				Sleep(0.1);
				if ((mLastDoorOpened != None) && mLastDoorOpened.bOpening)
				{
					Sleep(mLastDoorOpened.MoveTime);
					NPCLog("Door done moving (probably): " $ string(mLastDoorOpened));
				}
			}
		}
	}
	else
	{
		if (pnFollowingPathNode.IsA("NPCLadderPathNode"))
		{
			if (NPCLadderPathNode(pnFollowingPathNode).bNearLadderTop)
			{
				if (! ((Pawn.PhysicsVolume != None) && Pawn.PhysicsVolume.IsA("LadderVolume")))
				{
					StopMovement();
					lvLadderEntry=GetNearbyLadderVolume(pnFollowingPathNode);
					AGP_Pawn(Pawn).ClimbLadder(lvLadderEntry);
					Sleep(0.25);
				}
			}
			else
			{
				if (NPCLadderPathNode(pnFollowingPathNode).bNearLadderBase)
				{
					if ((Pawn.PhysicsVolume != None) && Pawn.PhysicsVolume.IsA("LadderVolume"))
					{
						AGP_Pawn(Pawn).EndClimbLadder(None);
					}
					else
					{
						lvLadderEntry=GetNearbyLadderVolume(pnFollowingPathNode);
						AGP_Pawn(Pawn).ClimbLadder(lvLadderEntry);
					}
				}
			}
		}
	}
	Sleep(0);
	JL"Begin"
;
	Sleep(2.5);
	JL"Begin"
;
}
*/

/*
State InjuredWaitingForHealing
{
	Function NotifyItemOfInterestFound(NPCItemOfInterest npcioi)
	{
	}
	Function NotifyAnotherPawnDied(NPCBaseController npcpc)
	{
	}
	Event NotifyPlayerPawnWatchingMe(Pawn pawnSeen)
	{
	}
	Function NotifyBuzzedByBullet(Actor aShooter)
	{
	}
	Function NotifyNPCSeen(Pawn Seen)
	{
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AGP_Weapon agpwWeaponHeard, Vector vSoundLocation)
	{
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, Pawn pawnHeard)
	{
	}
	Function AdjustConfidenceByTime()
	{
	}
	Function NotifyGrenadeLanded(ThrowWeaponPickup twpGrenade)
	{
	}
	Event bool NotifyBump(Actor Other)
	{
	}
	Event bool NotifyHitWall(Vector HitNormal, Actor Wall)
	{
	}
	Function bool NearWall(float walldist)
	{
	}
	Event EnemyNotVisible()
	{
	}
	Function SeePlayer(Pawn Seen)
	{
	}
	Function KilledBy(Pawn EventInstigator)
	{
	}
	Function EndState()
	{
		AGP_Pawn(Pawn).nmNPCIdleAnim="None";
	}
	Function bool UsedBy(Pawn User)
	{
		return false;
	}
	Function NotifyTakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, class<DamageType>  DamageType, Actor.BoneInfo Bone)
	{
		if (bStartsInjured)
		{
			return;
		}
		Global.NPCSpeechManager(Damage,instigatedBy,HitLocation,DamageType,Bone);
	}
	simulated Function PlayLoopingAnimation()
	{
		AGP_Pawn(Pawn).nmNPCIdleAnim=nameInitialInjuredAnimation;
		if (Level.NetMode == NM_Standalone)
		{
			Pawn.LoopAnim(nameInitialInjuredAnimation,1,0.2,1);
		}
		else
		{
			Pawn.SetLoopingAnimAction(nameInitialInjuredAnimation);
		}
	}
	Event NotifyPlayerPawnInSight(Pawn pawnSeen)
	{
		if ((! bPreHealingAudioPlayed) && (asndPreHealingAudio.Length > 0))
		{
			if (VSize((pawnSeen.Location - Pawn.Location)) < fpDistanceToTriggerPreHealingAudio)
			{
				PlayCustomSound(asndPreHealingAudio[Rand(asndPreHealingAudio.Length)]);
				bPreHealingAudioPlayed=true;
			}
		}
	}
	Function NotifyPlayerHealedNPC(AGP_Pawn agpHealer)
	{
		if (bStartsInjured)
		{
			Log("Injured objective healed, prepping to do post-heal actions, healed by " $ string(agpHealer));
			pawnWhoHealed=agpHealer;
			pawnToFollow=agpHealer;
			bHealedByPlayer=true;
			bNPCCanBeHealed=false;
			NPCChangeState("PostHealingState");
		}
		else
		{
			Stand();
			GotoState("FindCover");
		}
	}
Begin:
	sDebugStatus="Wounded, waiting for healing";
	AGP_Pawn(Pawn).bEyeTrack=false;
	Focus=None;
	if (bStartsInjured)
	{
		bShouldFollowUser=true;
		Pawn.Health=70;
		bHealedByPlayer=false;
	}
	bNPCCanBeHealed=true;
	HUDText=sNPCName $ " (injured)";
	PlayLoopingAnimation();
	nameInitialInjuredAnimation="None";
	sDebugStatus="Wounded, waiting for healing in animated state";
	JL"End"
;
}
*/

/*
State PostHealingState
{
	Function AdjustConfidenceByTime()
	{
	}
	Function NotifyItemOfInterestFound(NPCItemOfInterest npcioi)
	{
	}
	Function NotifyAnotherPawnDied(NPCBaseController npcpc)
	{
	}
	Event NotifyPlayerPawnWatchingMe(Pawn pawnSeen)
	{
	}
	Function NotifyBuzzedByBullet(Actor aShooter)
	{
	}
	Function NotifyNPCSeen(Pawn Seen)
	{
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AGP_Weapon agpwWeaponHeard, Vector vSoundLocation)
	{
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, Pawn pawnHeard)
	{
	}
	Function NotifyGrenadeLanded(ThrowWeaponPickup twpGrenade)
	{
	}
	Event bool NotifyBump(Actor Other)
	{
	}
	Event bool NotifyHitWall(Vector HitNormal, Actor Wall)
	{
	}
	Function bool NearWall(float walldist)
	{
	}
	Event EnemyNotVisible()
	{
	}
	Function SeePlayer(Pawn Seen)
	{
	}
	Function KilledBy(Pawn EventInstigator)
	{
	}
	Function TriggerHealingEvent()
	{
		local BaseObjective boIterator;
		ForEach AllActors(Class'BaseObjective',boIterator,namePostHealedEvent)
		{
		}
		boIterator.Trigger(Pawn,pawnWhoHealed);
	}
Begin:
	if (asndPostHealingAudio.Length > 0)
	{
		PlayCustomSound(asndPostHealingAudio[Rand(asndPostHealingAudio.Length)]);
	}
	Pawn.StopAnimating(false);
	if (bStandAfterHealing)
	{
		Crouch();
		Sleep(0.5);
	}
	Sleep(fpAnimationDelayAfterHealing);
	if (namePostHealingAnimation != "None")
	{
		Sleep(PlayCustomAnimation(namePostHealingAnimation));
		Pawn.ChangeAnimation();
	}
	if (namePostHealedEvent != "None")
	{
		TriggerHealingEvent();
	}
	HUDText=sNPCName;
	bShouldFollowUser=true;
	Log("Healed by " $ string(pawnWhoHealed) $ ", ordering to follow");
	if ((pawnWhoHealed != None) && (HumanController(pawnWhoHealed.Controller) != None))
	{
		CommandCivilian(HumanController(pawnWhoHealed.Controller),"Follow");
	}
	else
	{
		NPCChangeState("FindCover");
		Log("pawn who healed is gone, no one to follow, running for cover");
	}
}
*/

