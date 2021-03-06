// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseCivilianController/NPCBaseCivilianController.h"
#include "AA29/Object/Actor/NPCSpeechManager/NPCSpeechManager.h"
#include "AA29/Object/Actor/NPCConversationPack/NPCConversationPack.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/BaseObjective.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "AA29/Object/Actor/Keypoint/NPCItemOfInterest/NPCItemOfInterest.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/PathNode.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/ThrowWeaponPickup.h"
#include "AA29/Object/DamageType/AGP_DamageType/BleedDamage/BleedDamage.h"
#include "AA29/Object/Actor/EffectLocation/EffectLocation.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Brush/Volume/PhysicsVolume/LadderVolume/LadderVolume.h"
#include "AA29/Object/Actor/DecoMesh/Mover/Mover.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCDoorEntryPathNode/NPCDoorEntryPathNode.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCLadderPathNode/NPCLadderPathNode.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCPathNode.h"

ANPCBaseCivilianController::ANPCBaseCivilianController()
{
	asCivilianComments = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/J1_Date_Cue.J1_Date_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N1_Lunch_Cue.N1_Lunch_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N1_Movie_Cue.N1_Movie_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NMisc/N_Waiting_Cue.N_Waiting_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N1_Break_Cue.N1_Break_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N1_Lunch_Cue.N1_Lunch_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N1_Movie_Cue.N1_Movie_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N1_PX_Cue.N1_PX_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NConv/N1_Break_Cue.N1_Break_Cue'"), NULL, LOAD_None, NULL),
	};
	asCivilianGroans = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicField/Soldiers/Walter_Groan_Cue.Walter_Groan_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicField/Soldiers/Walter_Groan2_Cue.Walter_Groan2_Cue'"), NULL, LOAD_None, NULL)
	};
	asCivilianWarnings = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_LVL_MedicTraining/NMisc/J_YoureNot_Cue.J_YoureNot_Cue'"), NULL, LOAD_None, NULL)
	};
	asCivilianMaleInjured = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/Civilian/s_npc_civ_male_injury1_Cue.s_npc_civ_male_injury1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/Civilian/s_npc_civ_male_injury2_Cue.s_npc_civ_male_injury2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/Civilian/s_npc_civ_male_injury3_Cue.s_npc_civ_male_injury3_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/Civilian/s_npc_civ_male_injury4_Cue.s_npc_civ_male_injury4_Cue'"), NULL, LOAD_None, NULL)
	};
	asCivilianFemaleInjured = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/Civilian/s_npc_civ_female_injury1_Cue.s_npc_civ_female_injury1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/Civilian/s_npc_civ_female_injury2_Cue.s_npc_civ_female_injury2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/Civilian/s_npc_civ_female_injury3_Cue.s_npc_civ_female_injury3_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/Civilian/s_npc_civ_female_injury4_Cue.s_npc_civ_female_injury4_Cue'"), NULL, LOAD_None, NULL)
	};
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

	asoundDefFemaleSeePlayer = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_Hi_1_Cue.Amber_Hi_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_Hi_2_Cue.Amber_Hi_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_YouShouldntBeInHere_1_Cue.Amber_YouShouldntBeInHere_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_YouShouldntBeInHere_2_Cue.Amber_YouShouldntBeInHere_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_WhatDoYouWant_1_Cue.Amber_WhatDoYouWant_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_WhatDoYouWant_2_Cue.Amber_WhatDoYouWant_2_Cue'"), NULL, LOAD_None, NULL)
	};
	asoundDefFemaleCannotFollow = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_ItsImpossibleToGetThere_1_Cue.Amber_ItsImpossibleToGetThere_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_ItsImpossibleToGetThere_2_Cue.Amber_ItsImpossibleToGetThere_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_TheresNoWayToGetThere_1_Cue.Amber_TheresNoWayToGetThere_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_TheresNoWayToGetThere_2_Cue.Amber_TheresNoWayToGetThere_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_ICantGetThere_1_Cue.Amber_ICantGetThere_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_ICantGetThere_2_Cue.Amber_ICantGetThere_2_Cue'"), NULL, LOAD_None, NULL)
	};
	asoundDefFemaleWaitForNPC = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_WaitUp_1_Cue.Amber_WaitUp_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_WaitUp_2_Cue.Amber_WaitUp_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_WaitforMe_1_Cue.Amber_WaitforMe_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_WaitforMe_2_Cue.Amber_WaitforMe_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_HowMuchFarther_1_Cue.Amber_HowMuchFarther_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_HowMuchFarther_2_Cue.Amber_HowMuchFarther_2_Cue'"), NULL, LOAD_None, NULL),
	};
	asoundDefFemaleAcknowledgeOrderPositive = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_OK_1_Cue.Amber_OK_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_OK_2_Cue.Amber_OK_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_Sure_1_Cue.Amber_Sure_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_Sure_2_Cue.Amber_Sure_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_Fine_1_Cue.Amber_Fine_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_Fine_2_Cue.Amber_Fine_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_WhateverYouSay_1_Cue.Amber_WhateverYouSay_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_WhateverYouSay_2_Cue.Amber_WhateverYouSay_2_Cue'"), NULL, LOAD_None, NULL)
	};
	asoundDefFemaleAcknowledgeOrderNegative = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_ICantDoThat_1_Cue.Amber_ICantDoThat_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_ICantDoThat_2_Cue.Amber_ICantDoThat_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_IDontThinkSo_1_Cue.Amber_IDontThinkSo_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_IDontThinkSo_2_Cue.Amber_IDontThinkSo_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_No_1_Cue.Amber_No_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_No_2_Cue.Amber_No_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_ThatDoesntSoundLikeAGoodIdea_1_Cue.Amber_ThatDoesntSoundLikeAGoodIdea_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_ThatDoesntSoundLikeAGoodIdea_2_Cue.Amber_ThatDoesntSoundLikeAGoodIdea_2_Cue'"), NULL, LOAD_None, NULL)
	};
	asoundDefFemaleFrightened = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Amber_BeCarefulWithThat_1_Cue.Amber_BeCarefulWithThat_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Amber_BeCarefulWithThat_2_Cue.Amber_BeCarefulWithThat_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_LookOut_1_Cue.Amber_LookOut_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_LookOut_2_Cue.Amber_LookOut_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_StopShooting_1_Cue.Amber_StopShooting_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_StopShooting_2_Cue.Amber_StopShooting_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_DontShoot_1_Cue.Amber_DontShoot_1_Cue'"), NULL, LOAD_None, NULL)
	};
	asoundDefFemaleWounded = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_ImHitHelpMe_1_Cue.Amber_ImHitHelpMe_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/AmberCiv/Amber_GetMeADoctor_1_Cue.Amber_GetMeADoctor_1_Cue'"), NULL, LOAD_None, NULL)
	};
	asoundAltDefFemaleSeePlayer = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_Hi_1_Cue.Rae_Hi_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_Hi_2_Cue.Rae_Hi_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_YouShouldntBeInHere_1_Cue.Rae_YouShouldntBeInHere_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_YouShouldntBeInHere_2_Cue.Rae_YouShouldntBeInHere_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_WhatDoYouWant_1_Cue.Rae_WhatDoYouWant_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_WhatDoYouWant_2_Cue.Rae_WhatDoYouWant_2_Cue'"), NULL, LOAD_None, NULL),
	};
	asoundAltDefFemaleCannotFollow = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_ItsImpossibleToGetThere_1_Cue.Rae_ItsImpossibleToGetThere_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_ItsImpossibleToGetThere_2_Cue.Rae_ItsImpossibleToGetThere_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_TheresNoWayToGetThere_1_Cue.Rae_TheresNoWayToGetThere_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_TheresNoWayToGetThere_2_Cue.Rae_TheresNoWayToGetThere_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_ICantGetThere_1_Cue.Rae_ICantGetThere_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_ICantGetThere_2_Cue.Rae_ICantGetThere_2_Cue'"), NULL, LOAD_None, NULL)
	};
	asoundAltDefFemaleWaitForNPC = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_WaitUp_1_Cue.Rae_WaitUp_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_WaitUp_2_Cue.Rae_WaitUp_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_WaitforMe_1_Cue.Rae_WaitforMe_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_WaitforMe_2_Cue.Rae_WaitforMe_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_HowMuchFarther_1_Cue.Rae_HowMuchFarther_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_HowMuchFarther_2_Cue.Rae_HowMuchFarther_2_Cue'"), NULL, LOAD_None, NULL)
	};
	asoundAltDefFemaleAcknowledgeOrderPositive = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_OK_1_Cue.Rae_OK_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_OK_2_Cue.Rae_OK_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_Sure_1_Cue.Rae_Sure_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_Sure_2_Cue.Rae_Sure_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_Fine_1_Cue.Rae_Fine_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_Fine_2_Cue.Rae_Fine_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_WhateverYouSay_1_Cue.Rae_WhateverYouSay_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_WhateverYouSay_2_Cue.Rae_WhateverYouSay_2_Cue'"), NULL, LOAD_None, NULL)
	};
	asoundAltDefFemaleAcknowledgeOrderNegative = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_ICantDoThat_1_Cue.Rae_ICantDoThat_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_ICantDoThat_2_Cue.Rae_ICantDoThat_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_IDontThinkSo_1_Cue.Rae_IDontThinkSo_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_IDontThinkSo_2_Cue.Rae_IDontThinkSo_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_No_1_Cue.Rae_No_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_No_2_Cue.Rae_No_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_ThatDoesntSoundLikeAGoodIdea_1_Cue.Rae_ThatDoesntSoundLikeAGoodIdea_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_ThatDoesntSoundLikeAGoodIdea_2_Cue.Rae_ThatDoesntSoundLikeAGoodIdea_2_Cue'"), NULL, LOAD_None, NULL)
	};
	asoundAltDefFemaleFrightened = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_BeCarefulWithThat_1_Cue.Rae_BeCarefulWithThat_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_BeCarefulWithThat_2_Cue.Rae_BeCarefulWithThat_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_LookOut_1_Cue.Rae_LookOut_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_LookOut_2_Cue.Rae_LookOut_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_StopShooting_1_Cue.Rae_StopShooting_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_StopShooting_2_Cue.Rae_StopShooting_2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_DontShoot_1_Cue.Rae_DontShoot_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_DontShoot_2_Cue.Rae_DontShoot_2_Cue'"), NULL, LOAD_None, NULL)
	};
	asoundAltDefFemaleWounded = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_ImHitHelpMe_1_Cue.Rae_ImHitHelpMe_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_ImHitHelpMe_1_Cue.Rae_ImHitHelpMe_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_GetMeADoctor_1_Cue.Rae_GetMeADoctor_1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPCCiv/Rae_GetMeADoctor_2_Cue.Rae_GetMeADoctor_2_Cue'"), NULL, LOAD_None, NULL)
	};
}

/*
State WalkingPatrol
{
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
		Super::NotifyPlayerPawnInSight(pawnSeen);
		PlayRandomLipSynch(anameSeePlayer);
	}
	Event bool NotifyBump(AActor* Other)
	{
		PlayRandomLipSynch(anameSeePlayer);
		if (((Cast<ANPCPathNode>(pnCurrentNodeLeadingToPathNode) != nullptr) && NPCPathNode(pnCurrentNodeLeadingToPathNode).bNarrowPassageway) || ((pnCurrentPathNode != nullptr) && pnCurrentPathNode.bNarrowPassageway))
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
		if ((GetWorld()->GetTimeSeconds() > (fpTimeOfLastPawnSeen + 5)) && (Focus != pnCurrentPathNode))
		{
			Focus=pnCurrentPathNode;
		}
	}
	Function NotifyNPCSeen(APawn* Seen)
	{
		if (fpNPCMaxVisualRange == 0)
		{
			return;
		}
		if (FMath::Abs(VSize((Seen.Location - Pawn.Location))) > float(150))
		{
			return;
		}
		if ((Seen != pawnLastSeen) && ((fpTimeOfLastPawnSeen == 0) || (GetWorld()->GetTimeSeconds() > (fpTimeOfLastPawnSeen + float(30)))))
		{
			NPCLog(string(Self.Tag) + " NPC seen - " + FString::FromInt(Seen) + "." + FString::FromInt(Seen.Tag) + " checking for conversation packs");
			pawnLastSeen=Seen;
			fpTimeOfLastPawnSeen=GetWorld()->GetTimeSeconds();
			if (DetermineConversationPackAvailable(Seen))
			{
				NPCChangeState("NPCTalkToNPC");
			}
		}
	}
	Function ArrivedAtPathnode()
	{
		AAGP_Pawn* agpNPC = nullptr;
		Super::ArrivedAtPathnode();
		if (fpNPCMaxVisualRange == 0)
		{
			return;
		}
		ForEach RadiusActors(AAGP_Pawn::StaticClass(),agpNPC,150,Pawn.Location)
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
	Function NotifyItemOfInterestFound(ANPCItemOfInterest* npcioi)
	{
	}
	Function Timer()
	{
		Global.pnCurrentNodeLeadingToPathNode();
		if (GetWorld()->GetTimeSeconds() > fpTimeToTurnBackAround)
		{
			fpTimeToTurnBackAround=0;
			Focus=pnCurrentPathNode;
			NPCChangeState("ReturnToPatrol");
		}
	}
Begin:
	fpTimeToTurnBackAround=(GetWorld()->GetTimeSeconds() + (FMath::FRand() * 5));
	StopMovement();
	Focus=pawnLastSeen;
	bRotateToDesired=true;
}
*/

/*
State PawnStartsAsDummy
{
	Event NotifyPlayerPawnWatchingMe(APawn* pawnSeen)
	{
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
	{
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, Vector vSoundLocation)
	{
	}
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
		PlayRandomLipSynch(anameSeePlayer);
		Super::NotifyPlayerPawnInSight(pawnSeen);
	}
	Function NotifyGrenadeLanded(AThrowWeaponPickup* twpGrenade)
	{
	}
	Function NotifyItemOfInterestFound(ANPCItemOfInterest* npcioi)
	{
	}
}
*/

/*
State NPCTalkToNPC
{
	Function NotifyItemOfInterestFound(ANPCItemOfInterest* npcioi)
	{
	}
	Function NotifyNPCSeen(APawn* Seen)
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
	Function NotifyConversationPackStart(ANPCConversationPack* npccpNew)
	{
		npccpCurrentConversation=npccpNew;
	}
	Function NotifyConversationPackEnded(ANPCConversationPack* npccpJustEnded)
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
		if (anpccpConversations.Num() > 0)
		{
			for (iConvPackToUse=0; iConvPackToUse<anpccpConversations.Num(); iConvPackToUse++)
			{
				if (anpccpConversations[iConvPackToUse].IsPawnMemberOfConversation(pawnLastSeen))
				{
					anpccpConversations[iConvPackToUse].NPCStartConversation(this);
					bBusyPlayConversationPack=true;
					fpTimeToTurnBackAround=0;
					if (pawnLastSeen->IsA(ANPCBaseCivilianController::StaticClass()))
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
		if ((fpEndTimeForViewingItemOfInterest > 0) && (GetWorld()->GetTimeSeconds() > fpEndTimeForViewingItemOfInterest))
		{
			NPCLog("Hit end of item of interest time");
			NPCChangeState("WalkingPatrol");
		}
	}
	Function float PlayOIOAnimation()
	{
		float fpOIOAnimLength = 0;
		if (string(Cast<ANPCItemOfInterest>(Focus).nameNPCAnimation) != "None")
		{
			NPCLog("OIO animation: \"" + FString::FromInt(Cast<ANPCItemOfInterest>(Focus).nameNPCAnimation) + "\"");
			fpOIOAnimLength=PlayCustomAnimation(Cast<ANPCItemOfInterest>(Focus).nameNPCAnimation);
			NPCLog("Animation length: " + FString::FromInt(fpOIOAnimLength));
			return fpOIOAnimLength;
		}
	}
Begin:
	fpEndTimeForViewingItemOfInterest=0;
	if (Focus->IsA(ANPCItemOfInterest::StaticClass()))
	{
		FinishRotation();
		MoveTo(Focus->GetActorLocation(),Focus,true);
		NPCLog("Arrived at IOI");
		fpEndTimeForViewingItemOfInterest=GetWorld()->GetTimeSeconds();
		(fpEndTimeForViewingItemOfInterest += PlayOIOAnimation());
		if (Cast<ANPCItemOfInterest>(Focus).sndToPlay != nullptr)
		{
			Sleep(PlayCustomSound(Cast<ANPCItemOfInterest>(Focus).sndToPlay));
		}
		Sleep(Cast<ANPCItemOfInterest>(Focus).fpTimeToWaitHere);
	}
	NPCLog("Done setting up looking at item of interest, current time " + FString::FromInt(GetWorld()->GetTimeSeconds()) + " end time: " + FString::FromInt(fpEndTimeForViewingItemOfInterest));
}
*/

/*
State LiveGrenade
{
	Event bool NotifyBump(AActor* Other)
	{
		if (((Cast<ANPCPathNode>(pnCurrentNodeOnPathToCover) != nullptr) && NPCPathNode(pnCurrentNodeOnPathToCover).bNarrowPassageway) && IsLocationInFront(Other.Location))
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
	Function NotifyNPCSeen(APawn* Seen)
	{
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, Vector vSoundLocation)
	{
		if (FMath::Abs(VSize((agpwWeaponHeard.Location - Pawn.Location))) < float(2500))
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
		fpChance=FMath::FRand();
		fpTime=0;
		if (fpChance > 0.7)
		{
			fpTime=PlayCustomAnimation("WinceScaredA",false,((FMath::FRand() * 0.3) + 0.9));
		}
		if ((fpChance > 0.3) && (fpTime == 0))
		{
			fpTime=PlayCustomAnimation("WinceScaredB",false,((FMath::FRand() * 0.3) + 0.9));
		}
		if (fpTime == 0)
		{
			fpTime=PlayCustomAnimation("StdPanic",false,((FMath::FRand() * 0.3) + 0.9));
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
	Function NotifyItemOfInterestFound(ANPCItemOfInterest* npcioi)
	{
	}
	Function NotifyAnotherPawnDied(ANPCBaseController* npcpc)
	{
	}
	Event NotifyPlayerPawnWatchingMe(APawn* pawnSeen)
	{
	}
	Function NotifyBuzzedByBullet(AActor* aShooter)
	{
	}
	Function NotifyNPCSeen(APawn* Seen)
	{
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, Vector vSoundLocation)
	{
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
	{
	}
	Function AdjustConfidenceByTime()
	{
	}
	Function NotifyGrenadeLanded(AThrowWeaponPickup* twpGrenade)
	{
	}
	Function NotifyTakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, class<DamageType>  DamageType, FBoneInfo Bone)
	{
	}
	Event bool NotifyBump(AActor* Other)
	{
	}
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
	}
	Function bool NearWall(float walldist)
	{
	}
	Event EnemyNotVisible()
	{
	}
	Function SeePlayer(APawn* Seen)
	{
	}
	Function KilledBy(APawn* EventInstigator)
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
	Focus=nullptr;
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
	Function NotifyItemOfInterestFound(ANPCItemOfInterest* npcioi)
	{
	}
	Function NotifyNPCSeen(APawn* Seen)
	{
	}
	Function AdjustConfidenceByTime()
	{
		float fpUpdateDeltaTime = 0;
		fpUpdateDeltaTime=10;
		if (GetWorld()->GetTimeSeconds() > (fpTimeLastNervousnessChange + fpUpdateDeltaTime))
		{
			IncreaseConfidence(14);
			fpTimeLastNervousnessChange=GetWorld()->GetTimeSeconds();
			NPCLog("Adjusting confidence level to: " + FString::FromInt(GetConfidenceLevel()));
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
		NPCLog("Request to change state out of cowering for civilian to " + FString::FromInt(nmState));
		NPCChangeState(nmState,nmLabel);
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, Vector vSoundLocation)
	{
		if (FMath::Abs(VSize((agpwWeaponHeard.Location - Pawn.Location))) < float(2500))
		{
			IncreaseNervousness(0);
			IncreaseNervousness(0);
			IncreaseNervousness(0);
			IncreaseNervousness(0);
		}
	}
	Function NotifyBuzzedByBullet(AActor* aShooter)
	{
		if (anameFrightened.Num() > 0)
		{
			PlayRandomLipSynch(anameFrightened);
		}
		if ((GetWorld()->GetTimeSeconds() - fpTimeEnteredCover) > 9)
		{
			Log("Selecting new cover, this one is bad");
			NPCChangeState("LiveGrenade","Begin");
		}
	}
	Function BeginState()
	{
		NPCLog("Civilian Cowering state entered");
		Super::BeginState();
		SetConfidenceLevel((-60 - (float(10) + (FMath::FRand() * float(20)))));
		NPCLog("Current confidence on panic entry: " + FString::FromInt(GetConfidenceLevel()));
	}
Begin:
	fpTimeEnteredCover=GetWorld()->GetTimeSeconds();
	fpTimeLastNervousnessChange=GetWorld()->GetTimeSeconds();
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
	Function NotifyNPCSeen(APawn* Seen)
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
	Event NotifyPlayerPawnWatchingMe(APawn* pawnSeen)
	{
	}
	Function NotifyBuzzedByBullet(AActor* aShooter)
	{
		if (((Cast<AAGP_Pawn>(aShooter) != nullptr) && (Cast<AHumanController>(Cast<AAGP_Pawn>(aShooter).Controller) != nullptr)) && (Cast<AHumanController>(Cast<AAGP_Pawn>(aShooter).Controller).PlayerReplicationInfo.Team.TeamIndex == iFollowingTeam))
		{
			return;
		}
		Global.YPos(aShooter);
	}
	Event bool NotifyBump(AActor* Other)
	{
		if ((pnFollowingPathNode != nullptr) && (Other == pawnToFollow))
		{
			MoveTimer=-1;
			StopMovement();
			return true;
		}
		return Global.fpTimeToEndLastInterrupt(Other);
	}
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
		if ((Pawn.PhysicsVolume != nullptr) && Pawn.PhysicsVolume->IsA(ALadderVolume::StaticClass()))
		{
			Log("Hit wall while on ladder: " + FString::FromInt(Wall));
			MoveTimer=-1;
			StopMovement();
			return true;
		}
		if (Wall->IsA(AMover::StaticClass()))
		{
			if (Cast<AMover>(Wall).bNotADoor)
			{
				NPCPathLog(string(this) + "." + FString::FromInt(Tag) + " hit a non-door mover: " + FString::FromInt(Wall) + " Normal: " + FString::FromInt(HitNormal) + " at location " + FString::FromInt(Pawn.Location));
				return false;
			}
			else
			{
				if (Cast<AMover>(Wall).bClosed)
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
			if (RouteCache[iNode] == nullptr)
			{
				return false;
			}
			if ((RouteCache[iNode] != pnFollowingPathNode) && RouteCache[iNode]->IsA(ANPCLadderPathNode::StaticClass()))
			{
				return true;
			}
		}
		return false;
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, Vector vSoundLocation)
	{
		if (((Cast<AAGP_Pawn>(agpwWeaponHeard.Owner) != nullptr) && (Cast<AHumanController>(Cast<AAGP_Pawn>(agpwWeaponHeard.Owner).Controller) != nullptr)) && (Cast<AHumanController>(Cast<AAGP_Pawn>(agpwWeaponHeard.Owner).Controller).PlayerReplicationInfo.Team.TeamIndex == iFollowingTeam))
		{
			return;
		}
	}
Begin:
	if (pawnToFollow == nullptr)
	{
		Focus=nullptr;
		Cast<AAGP_Pawn>(Pawn)->bEyeTrack=false;
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
		if (GetWorld()->GetTimeSeconds() > (fpTimeOfLastFollowSpeech + float(10)))
		{
			fpTimeOfLastFollowSpeech=GetWorld()->GetTimeSeconds();
			if (anameWaitForNPC.Num() > 0)
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
	if ((pawnToFollow.PhysicsVolume != nullptr) && pawnToFollow.PhysicsVolume->IsA(ALadderVolume::StaticClass()))
	{
		Sleep(0.5);
		JL"Begin"
;
	}
	pnFollowingPathNode=PathNode(FindPathToward(pawnToFollow,true));
	if (pnFollowingPathNode == nullptr)
	{
		if (Pawn.LineOfSightTo(pawnToFollow))
		{
			MoveToward(pawnToFollow,pawnToFollow,100,false,((pawnToFollow.bIsWalking || pawnToFollow.bIsProne) || pawnToFollow.bIsCrouched));
			Sleep(0.5);
			JL"Begin"
;
		}
		Sleep(1);
		if ((pawnToFollow.PhysicsVolume != nullptr) && pawnToFollow.PhysicsVolume->IsA(ALadderVolume::StaticClass()))
		{
			if (anameCannotFollow.Num() > 0)
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
			pawnToFollow=nullptr;
		}
		JL"Begin"
;
	}
	if (! ((pawnToFollow.PhysicsVolume != nullptr) && pawnToFollow.PhysicsVolume->IsA(ALadderVolume::StaticClass())))
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
	if (pnFollowingPathNode->IsA(ANPCDoorEntryPathNode::StaticClass()))
	{
		if ((FindDoor(Cast<ANPCDoorEntryPathNode>(pnFollowingPathNode)) != nullptr) && FindDoor(Cast<ANPCDoorEntryPathNode>(pnFollowingPathNode)).bClosed)
		{
			StopMovement();
			if (OpenDoor(Cast<ANPCDoorEntryPathNode>(pnFollowingPathNode)))
			{
				Sleep(0.1);
				if ((mLastDoorOpened != nullptr) && mLastDoorOpened.bOpening)
				{
					Sleep(mLastDoorOpened.MoveTime);
					NPCLog("Door done moving (probably): " + FString::FromInt(mLastDoorOpened));
				}
			}
		}
	}
	else
	{
		if (pnFollowingPathNode->IsA(ANPCLadderPathNode::StaticClass()))
		{
			if (Cast<ANPCLadderPathNode>(pnFollowingPathNode).bNearLadderTop)
			{
				if (! ((Pawn.PhysicsVolume != nullptr) && Pawn.PhysicsVolume->IsA(ALadderVolume::StaticClass())))
				{
					StopMovement();
					lvLadderEntry=GetNearbyLadderVolume(pnFollowingPathNode);
					Cast<AAGP_Pawn>(Pawn)->ClimbLadder(lvLadderEntry);
					Sleep(0.25);
				}
			}
			else
			{
				if (Cast<ANPCLadderPathNode>(pnFollowingPathNode).bNearLadderBase)
				{
					if ((Pawn.PhysicsVolume != nullptr) && Pawn.PhysicsVolume->IsA(ALadderVolume::StaticClass()))
					{
						Cast<AAGP_Pawn>(Pawn)->EndClimbLadder(nullptr);
					}
					else
					{
						lvLadderEntry=GetNearbyLadderVolume(pnFollowingPathNode);
						Cast<AAGP_Pawn>(Pawn)->ClimbLadder(lvLadderEntry);
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
	Function NotifyItemOfInterestFound(ANPCItemOfInterest* npcioi)
	{
	}
	Function NotifyAnotherPawnDied(ANPCBaseController* npcpc)
	{
	}
	Event NotifyPlayerPawnWatchingMe(APawn* pawnSeen)
	{
	}
	Function NotifyBuzzedByBullet(AActor* aShooter)
	{
	}
	Function NotifyNPCSeen(APawn* Seen)
	{
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, Vector vSoundLocation)
	{
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
	{
	}
	Function AdjustConfidenceByTime()
	{
	}
	Function NotifyGrenadeLanded(AThrowWeaponPickup* twpGrenade)
	{
	}
	Event bool NotifyBump(AActor* Other)
	{
	}
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
	}
	Function bool NearWall(float walldist)
	{
	}
	Event EnemyNotVisible()
	{
	}
	Function SeePlayer(APawn* Seen)
	{
	}
	Function KilledBy(APawn* EventInstigator)
	{
	}
	Function EndState()
	{
		Cast<AAGP_Pawn>(Pawn)->nmNPCIdleAnim="None";
	}
	Function bool UsedBy(APawn* User)
	{
		return false;
	}
	Function NotifyTakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, class<DamageType>  DamageType, FBoneInfo Bone)
	{
		if (bStartsInjured)
		{
			return;
		}
		Global.NPCSpeechManager(Damage,instigatedBy,HitLocation,DamageType,Bone);
	}
	simulated Function PlayLoopingAnimation()
	{
		Cast<AAGP_Pawn>(Pawn)->nmNPCIdleAnim=nameInitialInjuredAnimation;
		if (GetWorld()->GetNetMode() == NM_Standalone)
		{
			Pawn.LoopAnim(nameInitialInjuredAnimation,1,0.2,1);
		}
		else
		{
			Pawn.SetLoopingAnimAction(nameInitialInjuredAnimation);
		}
	}
	Event NotifyPlayerPawnInSight(APawn* pawnSeen)
	{
		if ((! bPreHealingAudioPlayed) && (asndPreHealingAudio.Num() > 0))
		{
			if (VSize((pawnSeen.Location - Pawn.Location)) < fpDistanceToTriggerPreHealingAudio)
			{
				PlayCustomSound(asndPreHealingAudio[Rand(asndPreHealingAudio.Num())]);
				bPreHealingAudioPlayed=true;
			}
		}
	}
	Function NotifyPlayerHealedNPC(AAGP_Pawn* agpHealer)
	{
		if (bStartsInjured)
		{
			Log("Injured objective healed, prepping to do post-heal actions, healed by " + FString::FromInt(agpHealer));
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
	Cast<AAGP_Pawn>(Pawn)->bEyeTrack=false;
	Focus=nullptr;
	if (bStartsInjured)
	{
		bShouldFollowUser=true;
		Pawn.Health=70;
		bHealedByPlayer=false;
	}
	bNPCCanBeHealed=true;
	HUDText=sNPCName + " (injured)";
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
	Function NotifyItemOfInterestFound(ANPCItemOfInterest* npcioi)
	{
	}
	Function NotifyAnotherPawnDied(ANPCBaseController* npcpc)
	{
	}
	Event NotifyPlayerPawnWatchingMe(APawn* pawnSeen)
	{
	}
	Function NotifyBuzzedByBullet(AActor* aShooter)
	{
	}
	Function NotifyNPCSeen(APawn* Seen)
	{
	}
	Function NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, Vector vSoundLocation)
	{
	}
	Function NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
	{
	}
	Function NotifyGrenadeLanded(AThrowWeaponPickup* twpGrenade)
	{
	}
	Event bool NotifyBump(AActor* Other)
	{
	}
	Event bool NotifyHitWall(Vector HitNormal, AActor* Wall)
	{
	}
	Function bool NearWall(float walldist)
	{
	}
	Event EnemyNotVisible()
	{
	}
	Function SeePlayer(APawn* Seen)
	{
	}
	Function KilledBy(APawn* EventInstigator)
	{
	}
	Function TriggerHealingEvent()
	{
		ABaseObjective* boIterator = nullptr;
		ForEach AllActors(ABaseObjective::StaticClass(),boIterator,namePostHealedEvent)
		{
		}
		boIterator.Trigger(Pawn,pawnWhoHealed);
	}
Begin:
	if (asndPostHealingAudio.Num() > 0)
	{
		PlayCustomSound(asndPostHealingAudio[Rand(asndPostHealingAudio.Num())]);
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
	Log("Healed by " + FString::FromInt(pawnWhoHealed) + ", ordering to follow");
	if ((pawnWhoHealed != nullptr) && (Cast<AHumanController>(pawnWhoHealed.Controller) != nullptr))
	{
		CommandCivilian(Cast<AHumanController>(pawnWhoHealed.Controller),"Follow");
	}
	else
	{
		NPCChangeState("FindCover");
		Log("pawn who healed is gone, no one to follow, running for cover");
	}
}
*/

void ANPCBaseCivilianController::DisplayDebugNoSpam(AAGP_HUD* AGPHUD, UCanvas* Canvas, float& YL, float& YPos, FColor NewColor)
{
	FString t = "";
	float XL = 0;
	float fpVisionCone = 0;
	int32 iNode = 0;
	/*
	Canvas.Style = ERenderStyle.STY_Normal;
	Canvas.StrLen("TEST", XL, YL);
	YPos = (YPos + YL);
	Canvas.SetPos(4, YPos);
	Canvas.SetDrawColor(NewColor.R, NewColor.G, NewColor.B);
	t = GetDebugName();
	if (bDeleteMe)
	{
		t = t + " DELETED (bDeleteMe == true)";
	}
	Canvas.DrawText(t, false);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.SetDrawColor(255, 255, 0);
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText(string(this) + "." + FString::FromInt(Tag) + " State: " + FString::FromInt(GetStateName()));
	if (Pawn != nullptr)
	{
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Ground Speed: " + FString::FromInt(Pawn.GroundSpeed) + " run speed: " + FString::FromInt(Cast<AAGP_Pawn>(Pawn)->fRunSpeed) + " Penalty: " + FString::FromInt(Cast<AAGP_Pawn>(Pawn)->fSpeedPenalty) + " AdvancedTactics: " + FString::FromInt(bAdvancedTactics) + "  Shoot from hip: " + FString::FromInt(Pawn.bIsHipShooting) + " BlindFire L/R: " + FString::FromInt(Pawn.bIsFiringBlindlyLeft) + "," + FString::FromInt(Pawn.bIsFiringBlindlyRight));
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Iswalking: " + FString::FromInt(Pawn.bIsWalking) + " Crouched: " + FString::FromInt(Pawn.bIsCrouched) + "  Sprint: " + FString::FromInt(Pawn.bIsSprinting) + " Wants sprint: " + FString::FromInt(Pawn.bWantsToSprint));
	}
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Confidence: " + FString::FromInt(GetConfidenceLevel()) + "  Current focus: " + FString::FromInt(Focus));
	if (IsInState("FlashBanged"))
	{
		fpVisionCone = (GetMaxVisionCone() - ((GetMaxVisionCone() * ((fpFlashBangedEndTime - GetWorld()->GetTimeSeconds()) / fpFlashBangDuration)) * fpFlashBangedVisualIntensity));
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Flashbang duration: " + FString::FromInt(fpFlashBangDuration) + ", Time Left: " + FString::FromInt((fpFlashBangedEndTime - GetWorld()->GetTimeSeconds())) + ", Intensity: " + FString::FromInt(fpFlashBangedVisualIntensity));
	}
	else
	{
		fpVisionCone = GetMaxVisionCone();
	}
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Health: " + FString::FromInt(Pawn.Health));
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Vision Cone: " + FString::FromInt(fpVisionCone));
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Vision Range: " + FString::FromInt(fpNPCMaxVisualRange));
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Last Sound Heard: " + FString::FromInt(aLastActorHeard));
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Current path node location: " + FString::FromInt(pnCurrentLocation));
	if (pnCurrentPathNode != nullptr)
	{
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Current destination node: " + FString::FromInt(pnCurrentPathNode) + " (tag: " + FString::FromInt(pnCurrentPathNode.Tag) + ")");
	}
	if (pawnToFollow != nullptr)
	{
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Following pawn: " + FString::FromInt(pawnToFollow) + " distance: " + FString::FromInt(VSize((pawnToFollow.Location - Pawn.Location))) + " max allowed " + FString::FromInt(fpFollowDistance) + " follow node: " + FString::FromInt(pnFollowingPathNode));
	}
	YPos += YL;
	Canvas.SetPos(4, YPos);
	if (pnCurrentLocation != nullptr)
	{
		Canvas.DrawText("Current node: " + FString::FromInt(pnCurrentLocation) + " (tag: " + FString::FromInt(pnCurrentLocation.Tag) + ")");
	}
	else
	{
		Canvas.DrawText("AI traveling");
	}
	YPos += YL;
	Canvas.SetPos(4, YPos);
	if (Len(sDebugStatus) > 0)
	{
		Canvas.DrawText("Debug Status: " + sDebugStatus);
	}
	YPos += YL;
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Initial wounded animation: " + FString::FromInt(nameInitialInjuredAnimation) + "  current pawn idle anim: " + FString::FromInt(Cast<AAGP_Pawn>(Pawn)->nmNPCIdleAnim));
	for (iNode = 0; iNode < 62; iNode++)
	{
		if (RouteCache[iNode] == nullptr)
		{
		}
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("RouteCache[ " + FString::FromInt(iNode) + "] " + FString::FromInt(RouteCache[iNode].Location.X) + ", " + FString::FromInt(RouteCache[iNode].Location.Y) + ", " + FString::FromInt(RouteCache[iNode].Location.Z));
	}
	*/
}

void ANPCBaseCivilianController::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	if (YL < 8)
	{
		YL = 10;
	}
	/*
	(YPos += YL);
	Canvas.SetPos(4, YPos);
	Canvas.DrawText(string(this) + "." + FString::FromInt(Tag) + " State: " + FString::FromInt(GetStateName()));
	if (Pawn != nullptr)
	{
		(YPos += YL);
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Ground Speed: " + FString::FromInt(Pawn.GroundSpeed) + " run speed: " + FString::FromInt(Cast<AAGP_Pawn>(Pawn)->fRunSpeed) + " Penalty: " + FString::FromInt(Cast<AAGP_Pawn>(Pawn)->fSpeedPenalty) + " AdvancedTactics: " + FString::FromInt(bAdvancedTactics) + "  Shoot from hip: " + FString::FromInt(Pawn.bIsHipShooting) + " BlindFire L/R: " + FString::FromInt(Pawn.bIsFiringBlindlyLeft) + "," + FString::FromInt(Pawn.bIsFiringBlindlyRight));
		(YPos += YL);
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Iswalking: " + FString::FromInt(Pawn.bIsWalking) + " Crouched: " + FString::FromInt(Pawn.bIsCrouched) + "  Sprint: " + FString::FromInt(Pawn.bIsSprinting) + " Wants sprint: " + FString::FromInt(Pawn.bWantsToSprint));
	}
	(YPos += YL);
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Confidence: " + FString::FromInt(GetConfidenceLevel()) + "  Current focus: " + FString::FromInt(Focus));
	(YPos += YL);
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Health: " + FString::FromInt(Pawn.Health));
	(YPos += YL);
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Vision Range: " + FString::FromInt(fpNPCMaxVisualRange));
	(YPos += YL);
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Last Sound Heard: " + FString::FromInt(aLastActorHeard));
	(YPos += YL);
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Current path node location: " + FString::FromInt(pnCurrentLocation));
	if (pnCurrentPathNode != nullptr)
	{
		(YPos += YL);
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Current destination node: " + FString::FromInt(pnCurrentPathNode) + " (tag: " + FString::FromInt(pnCurrentPathNode.Tag) + ")");
	}
	if (pawnToFollow != nullptr)
	{
		(YPos += YL);
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Following pawn: " + FString::FromInt(pawnToFollow) + " distance: " + FString::FromInt(VSize((pawnToFollow.Location - Pawn.Location))) + " max allowed " + FString::FromInt(fpFollowDistance) + " follow node: " + FString::FromInt(pnFollowingPathNode));
	}
	(YPos += YL);
	Canvas.SetPos(4, YPos);
	if (pnCurrentLocation != nullptr)
	{
		Canvas.DrawText("Current node: " + FString::FromInt(pnCurrentLocation) + " (tag: " + FString::FromInt(pnCurrentLocation.Tag) + ")");
	}
	else
	{
		Canvas.DrawText("AI traveling or dummy");
	}
	*/
}

void ANPCBaseCivilianController::NPCChangeState(FName nmState, FName nmLabel)
{
	if (nmState != "Dead")
	{
		/*
		if ((((nmState == "FlashBanged") || (GetStateName() == "FlashBanged")) && (GetWorld()->GetTimeSeconds() < fpFlashBangedEndTime)) && ((!bStartsInjured) || bHealedByPlayer))
		{
			if (nmState == "FlashBanged")
			{
				NPCLog("Switching to flashbanged");
				GotoState(nmState, nmLabel);
			}
			NPCLog("Flashbanged pawn trying to change state from Flashbanged state - discarding");
			return;
		}
		if (GetStateName() == "injured")
		{
			return;
		}
		*/
	}
	if (((GetStateName() == "InjuredWaitingForHealing") && (nmState != "Dead")) && (!bHealedByPlayer))
	{
		return;
	}
	Super::NPCChangeState(nmState, nmLabel);
}

void ANPCBaseCivilianController::BeginPlay()
{
	Super::BeginPlay();
	NPCLog("NPCBaseCivilianController.BeginPlay() entered");
}

void ANPCBaseCivilianController::InitializePawn()
{
	int32 iVoice = 0;
	Super::InitializePawn();
	/*
	Pawn->bStopAtLedges = true;
	Pawn->bCanJump = false;
	if (string(Pawn.Mesh) ~= "A_AA2_CharactersCiv.DocF_Nurse")
	{
		bMaleVoice = false;
	}
	if (!bMaleVoice)
	{
		if (anameCannotFollow.Num() == 0)
		{
			if (FMath::FRand() > 0.5)
			{
				anameCannotFollow.insert(0, anameDefFemaleCannotFollow.Num());
				for (iVoice = 0; iVoice < anameDefFemaleCannotFollow.Num(); iVoice++)
				{
					anameCannotFollow[iVoice] = anameDefFemaleCannotFollow[iVoice];
				}
				anameWaitForNPC.insert(0, anameDefFemaleWaitForNPC.Num());
				for (iVoice = 0; iVoice < anameDefFemaleWaitForNPC.Num(); iVoice++)
				{
					anameWaitForNPC[iVoice] = anameDefFemaleWaitForNPC[iVoice];
				}
				anameAcknowledgeOrderPositive.insert(0, anameDefFemaleAcknowledgeOrderPositive.Num());
				for (iVoice = 0; iVoice < anameDefFemaleAcknowledgeOrderPositive.Num(); iVoice++)
				{
					anameAcknowledgeOrderPositive[iVoice] = anameDefFemaleAcknowledgeOrderPositive[iVoice];
				}
				anameAcknowledgeOrderNegative.insert(0, anameDefFemaleAcknowledgeOrderNegative.Num());
				for (iVoice = 0; iVoice < anameDefFemaleAcknowledgeOrderNegative.Num(); iVoice++)
				{
					anameAcknowledgeOrderNegative[iVoice] = anameDefFemaleAcknowledgeOrderNegative[iVoice];
				}
				anameFrightened.insert(0, anameDefFemaleFrightened.Num());
				for (iVoice = 0; iVoice < anameDefFemaleFrightened.Num(); iVoice++)
				{
					anameFrightened[iVoice] = anameDefFemaleFrightened[iVoice];
				}
				anameWounded.insert(0, anameDefFemaleWounded.Num());
				for (iVoice = 0; iVoice < anameDefFemaleWounded.Num(); iVoice++)
				{
					anameWounded[iVoice] = anameDefFemaleWounded[iVoice];
				}
				anameSeePlayer.insert(0, anameDefFemaleSeePlayer.Num());
				for (iVoice = 0; iVoice < anameDefFemaleSeePlayer.Num(); iVoice++)
				{
					anameSeePlayer[iVoice] = anameDefFemaleSeePlayer[iVoice];
				}
			}
			else
			{
				anameCannotFollow.insert(0, anameAltDefFemaleCannotFollow.Num());
				for (iVoice = 0; iVoice < anameAltDefFemaleCannotFollow.Num(); iVoice++)
				{
					anameCannotFollow[iVoice] = anameAltDefFemaleCannotFollow[iVoice];
				}
				anameWaitForNPC.insert(0, anameAltDefFemaleWaitForNPC.Num());
				for (iVoice = 0; iVoice < anameAltDefFemaleWaitForNPC.Num(); iVoice++)
				{
					anameWaitForNPC[iVoice] = anameAltDefFemaleWaitForNPC[iVoice];
				}
				anameAcknowledgeOrderPositive.insert(0, anameAltDefFemaleAcknowledgeOrderPositive.Num());
				for (iVoice = 0; iVoice < anameAltDefFemaleAcknowledgeOrderPositive.Num(); iVoice++)
				{
					anameAcknowledgeOrderPositive[iVoice] = anameAltDefFemaleAcknowledgeOrderPositive[iVoice];
				}
				anameAcknowledgeOrderNegative.insert(0, anameAltDefFemaleAcknowledgeOrderNegative.Num());
				for (iVoice = 0; iVoice < anameAltDefFemaleAcknowledgeOrderNegative.Num(); iVoice++)
				{
					anameAcknowledgeOrderNegative[iVoice] = anameAltDefFemaleAcknowledgeOrderNegative[iVoice];
				}
				anameFrightened.insert(0, anameAltDefFemaleFrightened.Num());
				for (iVoice = 0; iVoice < anameAltDefFemaleFrightened.Num(); iVoice++)
				{
					anameFrightened[iVoice] = anameAltDefFemaleFrightened[iVoice];
				}
				anameWounded.insert(0, anameAltDefFemaleWounded.Num());
				for (iVoice = 0; iVoice < anameAltDefFemaleWounded.Num(); iVoice++)
				{
					anameWounded[iVoice] = anameAltDefFemaleWounded[iVoice];
				}
				anameSeePlayer.insert(0, anameAltDefFemaleSeePlayer.Num());
				for (iVoice = 0; iVoice < anameAltDefFemaleSeePlayer.Num(); iVoice++)
				{
					anameSeePlayer[iVoice] = anameAltDefFemaleSeePlayer[iVoice];
				}
			}
		}
	}
	*/
}

/*
void ANPCBaseCivilianController::Possess(APawn* aPawn)
{
	Super::Possess(aPawn);
}
*/

void ANPCBaseCivilianController::Start()
{
	ANPCConversationPack* npccpIterator = nullptr;
	ANPCSpeechManager* npcsmgrIterator = nullptr;
	FBoneOffset BO;
	AActor* actObjectiveIterator = nullptr;
	/*
	Disable("SeeMonster");
	Super::Start();
	ForEach AllActors(ANPCConversationPack::StaticClass(), npccpIterator)
	{
		NPCLog("Found conversation " + FString::FromInt(npccpIterator.Tag) + " which has owned by flag of: " + FString::FromInt(npccpIterator.bConversationPackOwnedByNPC));
		NPCLog("NPC tag: " + FString::FromInt(Tag) + ", pawn tag: " + FString::FromInt(Pawn.Tag));
		if (npccpIterator.bConversationPackOwnedByNPC)
		{
			if (npccpIterator.IsPawnNameMemberOfConversation(string(Pawn.Tag)))
			{
				NPCLog("Adding conversation " + FString::FromInt(npccpIterator.Tag) + " to list for NPC " + FString::FromInt(Tag));
				anpccpConversations.insert(0, 1);
				anpccpConversations[0] = npccpIterator;
				npccpIterator.CachePawnsForConversationEntry();
				Enable("SeeMonster");
			}
		}
	}
	ForEach AllActors(ANPCSpeechManager::StaticClass(), npcsmgrIterator)
	{
		if (!npcsmgrIterator.bCivilianVoice)
		{
			continue;
		}
		if (npcsmgrIterator.iVoiceIndex == iVoiceIndex)
		{
			NPCLog("Found speech set for voice " + FString::FromInt(npcsmgrIterator.iVoiceIndex) + " (" + npcsmgrIterator.sDescription + ")");
			npcsmgrVoice = npcsmgrIterator;
		}
		else
		{
		}
	}
	if (bTriggerLinkedToObjective && (TriggerToActivate != "None"))
	{
		BO.VOffset = FVector(-33, -56, 2);
		BO.ROffset.Roll = -16384;
		BO.nBone = "Pelvis";
		ForEach AllActors(Class'Actor', actObjectiveIterator, TriggerToActivate)
		{
			actObjectiveIterator.SetCollision(false, false, false);
			Cast<AAGP_Pawn>(Pawn)->AttachToBoneOffset(actObjectiveIterator, BO);
		}
	}
	if (bStartsInjured)
	{
		NPCChangeState("InjuredWaitingForHealing");
	}
	*/
}

bool ANPCBaseCivilianController::DetermineConversationPackAvailable(APawn* pawnSeen)
{
	int32 iConvPackToUse = 0;
	if (anpccpConversations.Num() > 0)
	{
		for (iConvPackToUse = 0; iConvPackToUse < anpccpConversations.Num(); iConvPackToUse++)
		{
			if (anpccpConversations[iConvPackToUse]->IsPawnMemberOfConversation(pawnSeen))
			{
				//NPCLog("Conversation pack found for use with pawn: " + FString::FromInt(pawnSeen.Tag));
				return true;
			}
		}
	}
	return false;
}

void ANPCBaseCivilianController::NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, FVector vSoundLocation)
{
	/*
	NPCLog("heard weapon noise: " + FString::FromInt(agpwWeaponHeard) + " at range of " + FString::FromInt(FMath::Abs(VSize((agpwWeaponHeard.Location - Pawn.Location)))));
	if (FMath::Abs(VSize((agpwWeaponHeard.Location - Pawn.Location))) < float(2500))
	{
		IncreaseNervousness(0);
		IncreaseNervousness(0);
		IncreaseNervousness(0);
		IncreaseNervousness(0);
		if ((FMath::Abs(VSize((agpwWeaponHeard.Location - Pawn.Location))) < float(500)) || (((FMath::FRand() > 0.75) && (!IsInState("Panic"))) && (!IsInState("injured"))))
		{
			NPCChangeState("Panic", "ReactToPanic");
		}
	}
	*/
}

void ANPCBaseCivilianController::NPCTriggerEvent(FName nmEvent, APawn* pawnInstigator)
{
	AActor* actIterator = nullptr;
	/*
	ForEach DynamicActors(Class'Actor', actIterator, nmEvent)
	{
		actIterator.Trigger(Pawn, pawnInstigator);
	}
	*/
}

void ANPCBaseCivilianController::NotifyBuzzedByBullet(AActor* aShooter)
{
	AController* ctrlIterator = nullptr;
	/*
	NPCLog("Buzzed by bullet, confidence: " + FString::FromInt(GetConfidenceLevel()));
	if (anameFrightened.Num() > 0)
	{
		PlayRandomLipSynch(anameFrightened);
	}
	if (BuzzedEvent != "None")
	{
		NPCTriggerEvent(BuzzedEvent, Pawn(aShooter));
	}
	SetConfidenceLevel(-60);
	IncreaseNervousness(0);
	IncreaseNervousness(0);
	IncreaseNervousness(0);
	IncreaseNervousness(0);
	for (ctrlIterator = Level.ControllerList; ctrlIterator != nullptr; ctrlIterator = ctrlIterator.nextController)
	{
		if (!ctrlIterator->IsA(ANPCBaseCivilianController::StaticClass()))
		{
		}
		if (Pawn.LineOfSightTo(Cast<ANPCBaseCivilianController>(ctrlIterator).Pawn))
		{
			if (Cast<ANPCBaseCivilianController>(ctrlIterator).GetConfidenceLevel() > float(-60))
			{
				NPCBaseCivilianController(ctrlIterator).SetConfidenceLevel(-60);
				NPCBaseCivilianController(ctrlIterator).IncreaseNervousness(0);
				NPCBaseCivilianController(ctrlIterator).IncreaseNervousness(0);
				NPCBaseCivilianController(ctrlIterator).IncreaseNervousness(0);
				NPCBaseCivilianController(ctrlIterator).IncreaseNervousness(0);
				NPCBaseCivilianController(ctrlIterator).GotoState("Panic");
			}
		}
	}
	if (!bStartAsDummyPawn)
	{
		NPCChangeState("Panic");
	}
	else
	{
		NPCChangeState("Cowering");
	}
	*/
}

void ANPCBaseCivilianController::NotifyPlayerPawnInSight(APawn* pawnSeen)
{
	PlayRandomLipSynch(anameSeePlayer,false);
	Super::NotifyPlayerPawnInSight(pawnSeen);
	if (SeePlayerEvent != "None")
	{
		NPCTriggerEvent(SeePlayerEvent, pawnSeen);
	}
}

void ANPCBaseCivilianController::NotifyPlayerPawnWatchingMe(APawn* pawnSeen)
{
	int32 iNerveCount = 0;
	int32 iThreatRating = 0;
	NPCLog("Saw a player!");
	pawnLastSeen = pawnSeen;
	/*
	fpTimeOfLastPawnSeen = GetWorld()->GetTimeSeconds();
	if ((GetWorld()->GetTimeSeconds() > fpTimeToTurnBackAround) && (!bBusyPlayConversationPack))
	{
		NPCLog("Saw player, telling them some verbal text");
		StopMovement();
		Focus = pawnSeen;
		bRotateToDesired = true;
		NPCChangeState("NPCTalkToPlayer");
	}
	iThreatRating = int(EvaluateEnemyThreat(pawnSeen, true));
	for (iNerveCount = 0; iNerveCount < iThreatRating; iNerveCount++)
	{
		IncreaseNervousness(2);
	}
	*/
}

void ANPCBaseCivilianController::NotifyItemOfInterestFound(ANPCItemOfInterest* npcioi)
{
	StopMovement();
	Focus = npcioi;
	//bRotateToDesired = true;
	NPCChangeState("LookAtItemOfInterest","");
}

void ANPCBaseCivilianController::NotifyTakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, UaDamageType* DamageType, FBoneInfo Bone)
{
	/*
	if (Pawn.Health <= 0)
	{
		return;
	}
	if (WoundedEvent != "None")
	{
		NPCTriggerEvent(WoundedEvent, instigatedBy);
	}
	NPCLog("NotifyTakeDamage: " + FString::FromInt(DamageType) + " Damage: " + FString::FromInt(Damage) + ", Pawn Health now: " + FString::FromInt(Pawn.Health));
	if (((DamageType == ABleedDamage::StaticClass()) && (Pawn.Health < 35)) && (Pawn.Health > 0))
	{
		if (bMaleVoice)
		{
			CivilianGroan(0);
		}
		if (bNPCCanBeHealed)
		{
			NPCLog("Would play Help Me message here");
		}
		return;
	}
	if (!IsInState("InjuredWaitingForHealing"))
	{
		if ((Pawn.Health - Damage) > 0)
		{
			actThreat = instigatedBy;
			SetConfidenceLevel((-90 - 5));
			if (anameWounded.Num() > 0)
			{
				PlayRandomLipSynch(anameWounded, true);
			}
			else
			{
				if (bMaleVoice)
				{
					PlayCustomSound(asCivilianMaleInjured[Rand(asCivilianMaleInjured.Num())]);
				}
				else
				{
					PlayCustomSound(asCivilianFemaleInjured[Rand(asCivilianFemaleInjured.Num())]);
				}
			}
			StopMovement();
			if ((nameInitialInjuredAnimation == "None") || (nameInitialInjuredAnimation == "None"))
			{
				if (Pawn.HasAnim("wounded03_hurt_idle"))
				{
					nameInitialInjuredAnimation = "wounded03_hurt_idle";
				}
				else
				{
					if (Pawn.HasAnim("wounded02_hurt_idle"))
					{
						nameInitialInjuredAnimation = "wounded02_hurt_idle";
					}
					else
					{
						if (Pawn.HasAnim("CrhPanicF"))
						{
							nameInitialInjuredAnimation = "CrhPanicF";
						}
						else
						{
							if (Pawn.HasAnim("StdPanic"))
							{
								nameInitialInjuredAnimation = "StdPanic";
							}
							else
							{
								nameInitialInjuredAnimation = "PrnNo";
							}
						}
					}
				}
			}
			GotoState("FindCoverTheBeInjured");
		}
	}
	*/
}

void ANPCBaseCivilianController::Reset()
{
	Super::Reset();
	//Enemy = nullptr;
}

float ANPCBaseCivilianController::CivilianSay(int32 iSoundIndex)
{
	AActor* SoundActor = nullptr;
	/*
	SoundActor = Spawn(AEffectLocation::StaticClass(), , , Pawn.Location);
	SoundActor.LifeSpan = GetSoundDuration(asCivilianComments[iSoundIndex]);
	SoundActor.PlaySound(asCivilianComments[iSoundIndex], 0, 1, , , , false);
	*/
	return asCivilianComments[iSoundIndex]->Duration;
}

float ANPCBaseCivilianController::CivilianWarning(int32 iSoundIndex)
{
	AActor* SoundActor = nullptr;
	/*
	SoundActor = Spawn(AEffectLocation::StaticClass(), , , Pawn.Location);
	SoundActor.LifeSpan = GetSoundDuration(asCivilianWarnings[iSoundIndex]);
	SoundActor.PlaySound(asCivilianWarnings[iSoundIndex], 0, 1, , , , false);
	*/
	return asCivilianWarnings[iSoundIndex]->Duration;
}

float ANPCBaseCivilianController::CivilianGroan(int32 iSoundIndex)
{
	AActor* SoundActor = nullptr;
	/*
	SoundActor = Spawn(AEffectLocation::StaticClass(), , , Pawn.Location);
	SoundActor->LifeSpan = GetSoundDuration(asCivilianGroans[iSoundIndex]);
	SoundActor->PlaySound(asCivilianGroans[iSoundIndex], 0, 1, , , , false);
	*/
	return asCivilianGroans[iSoundIndex]->Duration;
}

void ANPCBaseCivilianController::NotifyAnotherPawnDied(ANPCBaseController* npcpc)
{
	/*
	if (LineOfSightTo(npcpc.Pawn) || (VSize((npcpc.Location - Location)) <= fpNPCHearingRadius))
	{
		PlayRandomLipSynch(anameFrightened);
		NPCLog("Saw friendly death, trying to run for cover");
		NPCChangeState("LiveGrenade");
	}
	*/
}

void ANPCBaseCivilianController::NotifyAnotherPawnTookDamage(APawn* pInstigator, ANPCBaseController* anpcbcDamaged)
{
	/*
	if (LineOfSightTo(anpcbcDamaged.Pawn) || (VSize((anpcbcDamaged.Location - Location)) <= fpNPCHearingRadius))
	{
		PlayRandomLipSynch(anameFrightened);
		NPCLog("Saw friendly injury, trying to run for cover");
		NPCChangeState("LiveGrenade");
	}
	*/
}

FString ANPCBaseCivilianController::CommandCivilian(AHumanController* hcPlayer, FString sCmd)
{
	/*
	NPCLog("Player " + FString::FromInt(hcPlayer) + " commanding me to " + sCmd);
	if (bMustBeHealedToCommand && (!bHealedByPlayer))
	{
		return "You must heal this person before they can follow your instructions.";
	}
	switch (sCmd)
	{
	case "TakeCover":
		AcknowledgeOrder();
		NPCChangeState("FindCover");
		return "";
	case "GetDown":
		AcknowledgeOrder();
		Prone();
		return "";
	case "MoveAlong":
		AcknowledgeOrder();
		NPCChangeState("ReturnToPatrol");
		return "";
	case "Follow":
		if (!bShouldFollowUser)
		{
			if (anameAcknowledgeOrderNegative.Num() > 0)
			{
				PlayRandomLipSynch(anameAcknowledgeOrderNegative);
				break;
			}
			if (bMaleVoice)
			{
				NPCSay(8, true, true);
			}
		}
		return "Pawn doesn't want to follow you.";
	}
	AcknowledgeOrder();
	pawnToFollow = hcPlayer.Pawn;
	iFollowingTeam = Cast<AHumanController>(pawnToFollow.Controller).PlayerReplicationInfo.Team.TeamIndex;
	Focus = pawnToFollow;
	Cast<AAGP_Pawn>(Pawn)->bEyeTrack = true;
	NPCChangeState("FollowPlayer");
	return "";
	case "StopFollow":
		if (pawnToFollow == nullptr)
		{
			if (anameAcknowledgeOrderNegative.Num() > 0)
			{
				PlayRandomLipSynch(anameAcknowledgeOrderNegative);
			}
			else
			{
				if (bMaleVoice)
				{
					NPCSay(8, true, true);
				}
			}
		}
		AcknowledgeOrder();
		StopMovement();
		Crouch();
		pawnToFollow = nullptr;
		iFollowingTeam = -1;
		return "";
	default:
		return "Valid Commands: Follow, StopFollow, TakeCover, GetDown, MoveAlong";
	}
	*/
	return "FAKE";    //FAKE  /ELiZ
}

void ANPCBaseCivilianController::AcknowledgeOrder()
{
	if (OrderAcknowledgement != "None")
	{
		NPCTriggerEvent(OrderAcknowledgement, pawnToFollow);
	}
	if (anameAcknowledgeOrderPositive.Num() > 0)
	{
		PlayRandomLipSynch(anameAcknowledgeOrderPositive,false);
	}
	else
	{
		if (bMaleVoice)
		{
			NPCSay(23, true, true);
		}
	}
}

void ANPCBaseCivilianController::NotifyPlayerHealedNPC(AAGP_Pawn* agpHealer)
{
	pawnWhoHealed = agpHealer;
	/*
	if (Pawn.Health > 0)
	{
		GotoState("Cower");
	}
	*/
}

void ANPCBaseCivilianController::PlayRandomLipSynch(TArray<FName> anameLipSynchs, bool bCutDelayTime)
{
	int32 iLSIndex = 0;
	USoundBase* soundToPlay = nullptr;
	/*
	if (bCutDelayTime)
	{
		if (GetWorld()->GetTimeSeconds() < fpNextWoundedAudioAllowedTime)
		{
			return;
		}
		fpNextWoundedAudioAllowedTime = ((GetWorld()->GetTimeSeconds() + float(15)) + (FMath::FRand() * 5));
	}
	else
	{
		if (GetWorld()->GetTimeSeconds() < fpNextAudioAllowedTime)
		{
			return;
		}
		fpNextAudioAllowedTime = ((GetWorld()->GetTimeSeconds() + fpMinTimeBetweenAudio) + (FMath::FRand() * 5));
	}
	if (anameLipSynchs.Num() == 0)
	{
		return;
	}
	iLSIndex = Rand(anameLipSynchs.Num());
	if (GetWorld()->GetNetMode() == NM_Standalone)
	{
		Pawn.PlayLIPSincAnim(anameLipSynchs[iLSIndex], 1, 256, 1);
	}
	else
	{
		switch (anameLipSynchs[0])
		{
		case anameDefFemaleSeePlayer[0]:
			soundToPlay = asoundDefFemaleSeePlayer[iLSIndex];
			break;
		case anameDefFemaleCannotFollow[0]:
			soundToPlay = asoundDefFemaleCannotFollow[iLSIndex];
			break;
		case anameDefFemaleWaitForNPC[0]:
			soundToPlay = asoundDefFemaleWaitForNPC[iLSIndex];
			break;
		case anameDefFemaleAcknowledgeOrderPositive[0]:
			soundToPlay = asoundDefFemaleAcknowledgeOrderPositive[iLSIndex];
			break;
		case anameDefFemaleAcknowledgeOrderNegative[0]:
			soundToPlay = asoundDefFemaleAcknowledgeOrderNegative[iLSIndex];
			break;
		case anameDefFemaleFrightened[0]:
			soundToPlay = asoundDefFemaleFrightened[iLSIndex];
			break;
		case anameDefFemaleWounded[0]:
			soundToPlay = asoundDefFemaleWounded[iLSIndex];
			break;
		case anameAltDefFemaleSeePlayer[0]:
			soundToPlay = asoundAltDefFemaleSeePlayer[iLSIndex];
			break;
		case anameAltDefFemaleCannotFollow[0]:
			soundToPlay = asoundAltDefFemaleCannotFollow[iLSIndex];
			break;
		case anameAltDefFemaleWaitForNPC[0]:
			soundToPlay = asoundAltDefFemaleWaitForNPC[iLSIndex];
			break;
		case anameAltDefFemaleAcknowledgeOrderPositive[0]:
			soundToPlay = asoundAltDefFemaleAcknowledgeOrderPositive[iLSIndex];
			break;
		case anameAltDefFemaleAcknowledgeOrderNegative[0]:
			soundToPlay = asoundAltDefFemaleAcknowledgeOrderNegative[iLSIndex];
			break;
		case anameAltDefFemaleFrightened[0]:
			soundToPlay = asoundAltDefFemaleFrightened[iLSIndex];
			break;
		case anameAltDefFemaleWounded[0]:
			soundToPlay = asoundAltDefFemaleWounded[iLSIndex];
			break;
		default:
			Log("Can't find equivalent sound for lipsinc");
			break;
		}
		Pawn.PlaySound(soundToPlay, 0, 1, , 300, 1, true);
	}
	*/
}

int32 ANPCBaseCivilianController::getReportNPCDistance()
{
	return iReportEventDistance;
}
