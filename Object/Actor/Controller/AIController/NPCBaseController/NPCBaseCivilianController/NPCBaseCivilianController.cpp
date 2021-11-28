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