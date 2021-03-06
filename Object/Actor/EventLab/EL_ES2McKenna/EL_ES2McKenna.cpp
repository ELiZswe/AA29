// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_ES2McKenna/EL_ES2McKenna.h"
#include "AA29/Object/Actor/AGP_UseTrigger/DoorTrigger/DoorTrigger.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/AGP_Character_NPC.h"
#include "AA29/Object/Actor/Info/AGP_DumbEndPoint/AGP_DumbEndPoint.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/AGP_UseTrigger/AGP_UseTrigger.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/DecoMesh/DecoMesh.h"
#include "AA29/Object/Actor/AAGameplay/MarksmanTarget/MarksmanTarget.h"
#include "AA29/Object/Actor/DecoMesh/Mover/Mover.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/AAGameplay/TextDisplay/TextDisplay.h"
#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/StudentController/StudentController.h"
#include "AA29/Object/Actor/Info/Security/Security.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_ActivatedObjective/AGP_ESSObjective/AGP_CoopESSObjective/AGP_CoopESSObjective.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_M4A1_Rifle_Mod/PickupW_M4A1_Rifle_Mod.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_M9_Pistol/PickupW_M9_Pistol.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/TraceWeapon.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M4A1_Rifle_Mod/Weapon_M4A1_Rifle_Mod.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/PistolWeapon/Weapon_M9_Pistol/Weapon_M9_Pistol.h"

AEL_ES2McKenna::AEL_ES2McKenna()
{
	aarReportDelay = 1.5;
	AmmoFadeTime = 2;
	TargetFlipModifier = 0.35;
	preTimerPause = 0.5;
	keepMovingIdleTime = 30;
	TotalES2ObjectinLevel = 21;
	
	GameSounds = {
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({ nullptr,"None",0 }),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/Instruction_01_Cue.Instruction_01_Cue'"), NULL, LOAD_None, NULL),"Instruction_01",0 }),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/Instruction_02_Cue.Instruction_02_Cue'"), NULL, LOAD_None, NULL),"Instruction_02", 0 }),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/Instruction_03_Cue.Instruction_03_Cue'"), NULL, LOAD_None, NULL),"Instruction_03", 0 }),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/Instruction_04_Cue.Instruction_04_Cue'"), NULL, LOAD_None, NULL),"Instruction_04", 0 }),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/Instruction_05_Cue.Instruction_05_Cue'"), NULL, LOAD_None, NULL),"Instruction_05", 0 }),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/Instruction_06_Cue.Instruction_06_Cue'"), NULL, LOAD_None, NULL),"Instruction_06", 0 }),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_AccuracyBad_Cue.AARGuy_AccuracyBad_Cue'"), NULL, LOAD_None, NULL),"AARGuy_AccuracyBad", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_AccuracyGood_Cue.AARGuy_AccuracyGood_Cue'"), NULL, LOAD_None, NULL),"AARGuy_AccuracyGood", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_AccuracyGreat_Cue.AARGuy_AccuracyGreat_Cue'"), NULL, LOAD_None, NULL),"AARGuy_AccuracyGreat", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_AccuracyOkay_Cue.AARGuy_AccuracyOkay_Cue'"), NULL, LOAD_None, NULL),"AARGuy_AccuracyOkay", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_ES2Bad_Cue.AARGuy_ES2Bad_Cue'"), NULL, LOAD_None, NULL),"AARGuy_ES2Bad", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_ES2Good_Cue.AARGuy_ES2Good_Cue'"), NULL, LOAD_None, NULL),"AARGuy_ES2Good", 0}),
		FGameSound({ nullptr,"None", 0 }),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_ES2Okay_Cue.AARGuy_ES2Okay_Cue'"), NULL, LOAD_None, NULL),"AARGuy_ES2Okay", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_FFSummaryBad_Cue.AARGuy_FFSummaryBad_Cue'"), NULL, LOAD_None, NULL),"AARGuy_FFSummaryBad", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_FFSummaryGood_Cue.AARGuy_FFSummaryGood_Cue'"), NULL, LOAD_None, NULL),"AARGuy_FFSummaryGood", 0}),
		FGameSound({ nullptr,"None", 0 }),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_FFSummaryOkay_Cue.AARGuy_FFSummaryOkay_Cue'"), NULL, LOAD_None, NULL),"AARGuy_FFSummaryOkay", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_GoGo_Cue.AARGuy_GoGo_Cue'"), NULL, LOAD_None, NULL),"AARGuy_GoGo", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_GoNoGoAmmo_Cue.AARGuy_GoNoGoAmmo_Cue'"), NULL, LOAD_None, NULL),"AARGuy_GoNoGoAmmo", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_GoNoGoScore_Cue.AARGuy_GoNoGoScore_Cue'"), NULL, LOAD_None, NULL),"AARGuy_GoNoGoScore", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_GoSoftGo_Cue.AARGuy_GoSoftGo_Cue'"), NULL, LOAD_None, NULL),"AARGuy_GoSoftGo", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_NotCompleted_Cue.AARGuy_NotCompleted_Cue'"), NULL, LOAD_None, NULL),"AARGuy_NotCompleted", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_SkillSummeryBad_Cue.AARGuy_SkillSummeryBad_Cue'"), NULL, LOAD_None, NULL),"AARGuy_SkillSummeryBad", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_SkillSummeryGood_Cue.AARGuy_SkillSummeryGood_Cue'"), NULL, LOAD_None, NULL),"AARGuy_SkillSummeryGood", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_SkillSummeryGreat_Cue.AARGuy_SkillSummeryGreat_Cue'"), NULL, LOAD_None, NULL),"AARGuy_SkillSummeryGreat", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_SkillSummeryOkay_Cue.AARGuy_SkillSummeryOkay_Cue'"), NULL, LOAD_None, NULL),"AARGuy_SkillSummeryOkay", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_SpeedBad_Cue.AARGuy_SpeedBad_Cue'"), NULL, LOAD_None, NULL),"AARGuy_SpeedBad", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_SpeedGood_Cue.AARGuy_SpeedGood_Cue'"), NULL, LOAD_None, NULL),"AARGuy_SpeedGood", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_SpeedGreat_Cue.AARGuy_SpeedGreat_Cue'"), NULL, LOAD_None, NULL),"AARGuy_SpeedGreat", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_SpeedOkay_Cue.AARGuy_SpeedOkay_Cue'"), NULL, LOAD_None, NULL),"AARGuy_SpeedOkay", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_DangerousEquipment01_Cue.RadioGuy_DangerousEquipment01_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_DangerousEquipment01", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_DangerousEquipment02_Cue.RadioGuy_DangerousEquipment02_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_DangerousEquipment02", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_DangerousEquipment03_Cue.RadioGuy_DangerousEquipment03_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_DangerousEquipment03", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_DangerousEquipment04_Cue.RadioGuy_DangerousEquipment04_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_DangerousEquipment04", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_IED_01_Cue.RadioGuy_IED_01_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_IED_01", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_IED_02_Cue.RadioGuy_IED_02_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_IED_02", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_IED_03_Cue.RadioGuy_IED_03_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_IED_03", 0}),
		FGameSound({ nullptr,"None", 0 }),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_Junk01_Cue.RadioGuy_Junk01_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_Junk01", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_Junk02_Cue.RadioGuy_Junk02_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_Junk02", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_Junk03_Cue.RadioGuy_Junk03_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_Junk03", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_Junk04_Cue.RadioGuy_Junk04_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_Junk04", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_Laptop01_Cue.RadioGuy_Laptop01_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_Laptop01", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_Laptop02_Cue.RadioGuy_Laptop02_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_Laptop02", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_Map01_Cue.RadioGuy_Map01_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_Map01", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_Map02_Cue.RadioGuy_Map02_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_Map02", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_Radio01_Cue.RadioGuy_Radio01_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_Radio01", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_Radio02_Cue.RadioGuy_Radio02_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_Radio02", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_TestObject01_Cue.RadioGuy_TestObject01_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_TestObject01", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_TestObject02_Cue.RadioGuy_TestObject02_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_TestObject02", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_TestObject03Report_Cue.RadioGuy_TestObject03Report_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_TestObject03Report", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_TestObject03Use_Cue.RadioGuy_TestObject03Use_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_TestObject03Use", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_TestObject04_Cue.RadioGuy_TestObject04_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_TestObject04", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_WeaponsCrate01_Cue.RadioGuy_WeaponsCrate01_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_WeaponsCrate01", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_WeaponsCrate02_Cue.RadioGuy_WeaponsCrate02_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_WeaponsCrate02", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_WeaponsCrate03_Cue.RadioGuy_WeaponsCrate03_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_WeaponsCrate03", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/RadioGuy_WeaponsCrate04_Cue.RadioGuy_WeaponsCrate04_Cue'"), NULL, LOAD_None, NULL),"RadioGuy_WeaponsCrate04", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/VoiceGuy_EndGate_Cue.VoiceGuy_EndGate_Cue'"), NULL, LOAD_None, NULL),"VoiceGuy_EndGate", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/VoiceGuy_HitFriendly_Cue.VoiceGuy_HitFriendly_Cue'"), NULL, LOAD_None, NULL),"VoiceGuy_HitFriendly", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/VoiceGuy_IntroMessage01_Cue.VoiceGuy_IntroMessage01_Cue'"), NULL, LOAD_None, NULL),"VoiceGuy_IntroMessage01", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/VoiceGuy_ROE_Violation_Cue.VoiceGuy_ROE_Violation_Cue'"), NULL, LOAD_None, NULL),"VoiceGuy_ROE_Violation", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/VoiceGuy_StartGate_Cue.VoiceGuy_StartGate_Cue'"), NULL, LOAD_None, NULL),"VoiceGuy_StartGate", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/VoiceGuy_TriggerIED01_Cue.VoiceGuy_TriggerIED01_Cue'"), NULL, LOAD_None, NULL),"VoiceGuy_TriggerIED01", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/VoiceGuy_TriggerIED02_Cue.VoiceGuy_TriggerIED02_Cue'"), NULL, LOAD_None, NULL),"VoiceGuy_TriggerIED02", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/VoiceGuy_TriggerIED03_Cue.VoiceGuy_TriggerIED03_Cue'"), NULL, LOAD_None, NULL),"VoiceGuy_TriggerIED03", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_error_Cue.m_error_Cue'"), NULL, LOAD_None, NULL),"m_error", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_hydraulic_Cue.m_hydraulic_Cue'"), NULL, LOAD_None, NULL),"m_hydraulic", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_ls0_Cue.m_ls0_Cue'"), NULL, LOAD_None, NULL),"m_ls0", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_ls2_Cue.m_ls2_Cue'"), NULL, LOAD_None, NULL),"m_ls2", 0}),
		FGameSound({LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_MOUT/cadre/m_ls3_Cue.m_ls3_Cue'"), NULL, LOAD_None, NULL),"m_ls3", 0})
	};

	LSAnims = {
		FLSAnim({"Instruction_01",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/Instruction_01_Cue.Instruction_01_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"Instruction_02",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/Instruction_02_Cue.Instruction_02_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"Instruction_03",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/Instruction_03_Cue.Instruction_03_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"Instruction_04",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/Instruction_04_Cue.Instruction_04_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"Instruction_05",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/Instruction_05_Cue.Instruction_05_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"Instruction_06",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/Instruction_06_Cue.Instruction_06_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"AARGuy_AccuracyBad",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_AccuracyBad_Cue.AARGuy_AccuracyBad_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"AARGuy_AccuracyGood",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_AccuracyGood_Cue.AARGuy_AccuracyGood_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"AARGuy_AccuracyGreat",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_AccuracyGreat_Cue.AARGuy_AccuracyGreat_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"AARGuy_AccuracyOkay",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_AccuracyOkay_Cue.AARGuy_AccuracyOkay_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"AARGuy_ES2Bad",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_ES2Bad_Cue.AARGuy_ES2Bad_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"AARGuy_ES2Good",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_ES2Good_Cue.AARGuy_ES2Good_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"AARGuy_ES2Okay",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_ES2Okay_Cue.AARGuy_ES2Okay_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"AARGuy_FFSummaryBad",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_FFSummaryBad_Cue.AARGuy_FFSummaryBad_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"AARGuy_FFSummaryGood",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_FFSummaryGood_Cue.AARGuy_FFSummaryGood_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"AARGuy_FFSummaryOkay",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_FFSummaryOkay_Cue.AARGuy_FFSummaryOkay_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"AARGuy_GoGo",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_GoGo_Cue.AARGuy_GoGo_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"AARGuy_GoNoGoAmmo",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_GoNoGoAmmo_Cue.AARGuy_GoNoGoAmmo_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"AARGuy_GoNoGoScore",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_GoNoGoScore_Cue.AARGuy_GoNoGoScore_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"AARGuy_GoSoftGo",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_GoSoftGo_Cue.AARGuy_GoSoftGo_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"AARGuy_NotCompleted",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_NotCompleted_Cue.AARGuy_NotCompleted_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"AARGuy_SkillSummeryBad",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_SkillSummeryBad_Cue.AARGuy_SkillSummeryBad_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"AARGuy_SkillSummeryGood",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_SkillSummeryGood_Cue.AARGuy_SkillSummeryGood_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"AARGuy_SkillSummeryGreat",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_SkillSummeryGreat_Cue.AARGuy_SkillSummeryGreat_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"AARGuy_SkillSummeryOkay",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_SkillSummeryOkay_Cue.AARGuy_SkillSummeryOkay_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"AARGuy_SpeedBad",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_SpeedBad_Cue.AARGuy_SpeedBad_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"AARGuy_SpeedGood",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_SpeedGood_Cue.AARGuy_SpeedGood_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"AARGuy_SpeedGreat",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_SpeedGreat_Cue.AARGuy_SpeedGreat_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({"AARGuy_SpeedOkay",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_ES2/Dialog/AARGuy_SpeedOkay_Cue.AARGuy_SpeedOkay_Cue'"), NULL, LOAD_None, NULL),{"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} })
	};
}

/*
State Briefing
{
	Function BeginState()
	{
		if (! bIntroed)
		{
			PlayGameSound("VoiceGuy_IntroMessage01",Player);
			PlayerLock(true,false);
		}
	}
	Function bool StartGateVO_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if ((! courseEntered) && PlayerHasWeapon(Cast<APawn>(Instigator)))
		{
			PlayGameSound("VoiceGuy_StartGate",Player);
			StartGateVO->DisableTrigger();
		}
		return true;
	}
	Function EndIntroVO()
	{
		if (! bIntroed)
		{
			PlayTip("Welcome to the ES2 Training Exercise.","See your Instructor for your mission briefing.",5);
		}
		bIntroed=true;
		SetCustomTimer(40,false,"CheckPlayerMove");
		PlayerLock(false,false);
		skipVOTrigger.HUDText="";
		skipVOTrigger.bDisabled=true;
		cadreAAR.LoopAnim("DrillIdle");
		cadreInstructor.LoopAnim("DrillIdle");
	}
	Function FinishCadreVO()
	{
		SetCustomTimer(20,false,"CheckPlayerMove");
		cadreUseTrigger1.bDisabled=false;
		cadreUseTrigger2.bDisabled=false;
		cadreUseTrigger1.HUDText=cadreUseTip1;
		cadreUseTrigger2.HUDText=cadreUseTip2;
		PlayerLock(false,false);
	}
	Function DoIntroLSVO(APawn* Target, FName LSAnim)
	{
		StopCustomTimer("CheckPlayerMove");
		PlayLSAnim(LSAnim,Target,1,512);
		PlayerLock(true,true);
		cadreUseTrigger1.bDisabled=false;
		cadreUseTrigger2.bDisabled=false;
		cadreUseTrigger1.HUDText="Skip Dialog";
		cadreUseTrigger2.HUDText="Skip Dialog";
	}
	Function bool cadreUseTrigger1_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		if (cadreAAR.IsPlayingLIPSincAnim())
		{
			cadreAAR->StopLIPSincAnim();
		}
		ChangeState("Instructions");
		return true;
	}
	Function bool cadreUseTrigger2_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		if (cadreInstructor.IsPlayingLIPSincAnim())
		{
			cadreInstructor->StopLIPSincAnim();
		}
		if (cadreAAR.IsPlayingLIPSincAnim())
		{
			cadreAAR->StopLIPSincAnim();
			FinishCadreVO();
		}
		else
		{
			DoIntroLSVO(cadreAAR,"AARGuy_NotCompleted");
		}
		return true;
	}
	Function bool skipVOTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		Player.StopSound(GetGameSound("VoiceGuy_IntroMessage01"));
		EndIntroVO();
		return true;
	}
	Function bool Timer_Sound(FName Name)
	{
		if (Name == "VoiceGuy_IntroMessage01")
		{
			EndIntroVO();
			return true;
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case "AARGuy_NotCompleted":
			FinishCadreVO();
			return true;
			default:
		}
	}
}
*/

/*
State Instructions
{
	Function bool cadreUseTrigger1_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		if (cadreInstructor.IsPlayingLIPSincAnim())
		{
			cadreInstructor->StopLIPSincAnim();
		}
		cadreUseTrigger1.HUDText=cadreUseTip1;
		ChangeState("Briefing");
		return true;
	}
	Function BeginState()
	{
		Log("I'm in Instructions BeginState()");
		cadreUseTrigger1.HUDText="Skip Dialog";
		Controller.LockPlayer(true,true);
		InstructorAnimNum=2;
		StopCustomTimer("CheckPlayerMove");
		PlayLSAnim("Instruction_02",cadreInstructor,1,512,,0.5);
	}
	Function NextInstructionVO()
	{
		FName instructionName = "";
		switch(InstructorAnimNum)
		{
			case 2:
			instructionName="Instruction_03";
			break;
			case 3:
			instructionName="Instruction_04";
			StartTimer("ShowReportDialog",6);
			StartTimer("ShowUseDialog",20);
			break;
			case 4:
			instructionName="Instruction_05";
			break;
			case 5:
			instructionName="Instruction_06";
			break;
			default:
		}
		PlayLSAnim(instructionName,cadreInstructor,1,512);
		InstructorAnimNum ++;
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "ShowReportDialog":
			PlayTip("To report an object: ","Press the (<ESSObjectiveReport>) Key",5);
			return true;
			case "ShowUseDialog":
			PlayTip("To use an object: ","Press the (<Action>) Key",5);
			return true;
			default:
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case "Instruction_01":
			case "Instruction_02":
			case "Instruction_03":
			case "Instruction_04":
			case "Instruction_05":
			NextInstructionVO();
			return true;
			case "Instruction_06":
			ChangeState("Briefing");
			cadreUseTrigger1.HUDText=cadreUseTip1;
			return true;
			default:
		}
	}
	Function EndState()
	{
		SetCustomTimer(20,false,"CheckPlayerMove");
		Controller.LockPlayer(false,false);
	}
}
*/

/*
State AAR
{
	Function BeginState()
	{
		Log("Do AAR Stuff now plz.");
	}
	Function bool cadreUseTrigger2_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		ChangeState("AARBriefing");
		return true;
	}
	Function bool sbUseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		Log("TODO: Get uploadStats stuff");
		uploadStats();
		return true;
	}
}
*/

/*
State AARBriefing
{
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "aarStart":
			aarES2ObjectsFound();
			return true;
			default:
			return Super::Timer_Timer(Name);
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case "AARGuy_ES2Bad":
			case "AARGuy_ES2Good":
			case "AARGuy_ES2Okay":
			aarOpforHit();
			return true;
			case "AARGuy_SkillSummeryBad":
			case "AARGuy_SkillSummeryGood":
			case "AARGuy_SkillSummeryGreat":
			case "AARGuy_SkillSummeryOkay":
			aarFriendlyHit();
			return true;
			case "AARGuy_FFSummaryBad":
			case "AARGuy_FFSummaryGood":
			case "AARGuy_FFSummaryOkay":
			aarAmmo();
			return true;
			case "AARGuy_AccuracyBad":
			case "AARGuy_AccuracyGood":
			case "AARGuy_AccuracyGreat":
			case "AARGuy_AccuracyOkay":
			aarTime();
			return true;
			case "AARGuy_SpeedBad":
			case "AARGuy_SpeedGood":
			case "AARGuy_SpeedGreat":
			case "AARGuy_SpeedOkay":
			aarTotalScore();
			return true;
			case "AARGuy_GoGo":
			case "AARGuy_GoNoGoScore":
			case "AARGuy_GoSoftGo":
			EndOfAAR();
			return true;
			default:
		}
	}
	Function bool aarES2ObjectsFound()
	{
		if (ES2objectsFound > 11)
		{
			aarAnimName="AARGuy_ES2Good";
		}
		else
		{
			if (ES2objectsFound >= 3)
			{
				aarAnimName="AARGuy_ES2Okay";
			}
			else
			{
				aarAnimName="AARGuy_ES2Bad";
			}
		}
		DebugLog(DEBUG_EventLab,"aarOpforHit:" + FString::FromInt(aarAnimName));
		PlayLSAnim(aarAnimName,cadreAAR,1,512,,aarReportDelay);
		PlayTip("Total ES2 Objects Found:" @ FString::FromInt(ES2objectsFound),"ES2 Found Score:" @ FString::FromInt(ES2Score),7);
		return true;
	}
	Function bool aarOpforHit()
	{
		if (opforHit >= 40)
		{
			aarAnimName="AARGuy_SkillSummeryGreat";
		}
		else
		{
			if (opforHit >= 25)
			{
				aarAnimName="AARGuy_SkillSummeryGood";
			}
			else
			{
				if (opforHit >= 10)
				{
					aarAnimName="AARGuy_SkillSummeryOkay";
				}
				else
				{
					aarAnimName="AARGuy_SkillSummeryBad";
				}
			}
		}
		DebugLog(DEBUG_EventLab,"aarOpforHit:" + FString::FromInt(aarAnimName));
		PlayLSAnim(aarAnimName,cadreAAR,1,512,,aarReportDelay);
		PlayTip("Total OPFOR Targets Hit:" @ FString::FromInt(opforHit),"OPFOR Hit Score:" @ FString::FromInt(opforHitScore),7);
		return true;
	}
	Function bool aarFriendlyHit()
	{
		FString FriendlyHitName = "";
		if (friendlyHit >= 3)
		{
			aarAnimName="AARGuy_FFSummaryBad";
		}
		else
		{
			if (friendlyHit >= 1)
			{
				aarAnimName="AARGuy_FFSummaryOkay";
			}
			else
			{
				aarAnimName="AARGuy_FFSummaryGood";
			}
		}
		DebugLog(DEBUG_EventLab,"aarFriendlyHit:" + FString::FromInt(aarAnimName));
		PlayLSAnim(aarAnimName,cadreAAR,1,512,,aarReportDelay);
		if (friendlyHit > 0)
		{
			FriendlyHitName="Friendly Casualty Penalties:";
		}
		else
		{
			FriendlyHitName="IFF Bonus:";
		}
		PlayTip("Total Friendly Targets Hit:" @ FString::FromInt(friendlyHit),FriendlyHitName @ FString::FromInt(friendlyHitScore),7);
		return true;
	}
	Function bool aarAmmo()
	{
		if (Accuracy == 1)
		{
			aarAnimName="AARGuy_AccuracyGreat";
		}
		else
		{
			if (Accuracy >= 0.85)
			{
				aarAnimName="AARGuy_AccuracyGood";
			}
			else
			{
				if (Accuracy >= 0.6)
				{
					aarAnimName="AARGuy_AccuracyOkay";
				}
				else
				{
					aarAnimName="AARGuy_AccuracyBad";
				}
			}
		}
		PlayLSAnim(aarAnimName,cadreAAR,1,512,,aarReportDelay);
		PlayTip("Overall Weapon Accuracy:" @ FString::FromInt(int((Accuracy * float(100)))) + "%","Weapon Accuracy Bonus:" @ FString::FromInt(accuracyScore),7);
		return true;
	}
	Function bool aarTime()
	{
		int32 totalHouseTime = 0;
		totalHouseTime=(600 - GetClockSeconds());
		if (totalHouseTime > 420)
		{
			aarAnimName="AARGuy_SpeedBad";
		}
		else
		{
			if (totalHouseTime > 300)
			{
				aarAnimName="AARGuy_SpeedOkay";
			}
			else
			{
				if (totalHouseTime > 150)
				{
					aarAnimName="AARGuy_SpeedGood";
				}
				else
				{
					aarAnimName="AARGuy_SpeedGreat";
				}
			}
		}
		DebugLog(DEBUG_EventLab,"aarTime:" + FString::FromInt(aarAnimName));
		Log("aarTime: " @ FString::FromInt(totalHouseTime));
		PlayLSAnim(aarAnimName,cadreAAR,1,512,,aarReportDelay);
		PlayTip("Total Time to Complete Training:" @ timeOverall,"Speed Bonus Score:" @ FString::FromInt(timeOverallScore),7);
		return true;
	}
	Function bool aarTotalScore()
	{
		if (TotalScore >= 15000)
		{
			aarAnimName="AARGuy_GoGo";
		}
		else
		{
			if (TotalScore >= 10000)
			{
				aarAnimName="AARGuy_GoSoftGo";
			}
			else
			{
				aarAnimName="AARGuy_GoNoGoScore";
			}
		}
		if (finalGo == "X")
		{
			PlayTip("Total Overall Score:" @ FString::FromInt(TotalScore),"You are a GO at this training",7);
		}
		else
		{
			PlayTip("Total Overall Score:" @ FString::FromInt(TotalScore),"You are a NO-GO at this training",7);
		}
		PlayLSAnim(aarAnimName,cadreAAR,1,512,,aarReportDelay);
		return true;
	}
	Function bool cadreUseTrigger2_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		ChangeState("AAR");
		if (cadreAAR.IsPlayingLIPSincAnim())
		{
			cadreAAR->StopLIPSincAnim();
		}
		return true;
	}
	Function EndOfAAR()
	{
		ChangeState("AAR");
	}
	Function BeginState()
	{
		StopCustomTimer("CheckPlayerMove");
		cadreUseTrigger2.HUDText="Skip AAR";
		Controller.LockPlayer(true,true);
		StartTimer("aarStart",1);
	}
	Function EndState()
	{
		PlayTip("Examine Scoreboard and review your","results to complete this training.",3);
		Controller.LockPlayer(false,false);
		cadreUseTrigger2.HUDText=cadreUseTipAAR;
	}
}
*/

/*
State OutOfAmmo
{
	Function BeginState()
	{
		StopCustomTimer("CheckPlayerMove");
		Player.SetLocation(aarLocation.Location);
		Player.Controller.SetRotation(aarLocation.Rotation);
		FadeInBlack(float(AmmoFadeTime));
		holsterweapon();
		RemoveWeapons();
		PlayTip("Soldier, You've expended your ammo prior to completing your training","You've failed to meet the minimum standard.",5);
		PlayerLock(true,true);
		PlayLSAnim("AARGuy_GoNoGoAmmo",cadreAAR,1,512,,aarReportDelay);
		cadreUseTrigger2.bActive=false;
		cadreUseTrigger2.HUDText="";
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case "AARGuy_GoNoGoAmmo":
			uploadStats();
			return true;
			default:
		}
	}
}
*/

/*
State building1Active
{
	Function bool Building1MT_Trigger02AB_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		building1M06Target1=MarksmanTarget(CaptureEvent("Building1Marker06Target01"));
		building1M06Target2=MarksmanTarget(CaptureEvent("Building1Marker06Target02"));
		building1M07Target1=MarksmanTarget(CaptureEvent("Building1Marker07Target01"));
		building1M07Target2=MarksmanTarget(CaptureEvent("Building1Marker07Target02"));
		building1M07Target3=MarksmanTarget(CaptureEvent("Building1Marker07Target03"));
		building1M07Target4=MarksmanTarget(CaptureEvent("Building1Marker07Target04"));
		building1M07Target5=MarksmanTarget(CaptureEvent("Building1Marker07Target05"));
		building1M07Target6=MarksmanTarget(CaptureEvent("Building1Marker07Target06"));
		StartTimer("room1Target1",(FMath::FRand() * TargetFlipModifier));
		StartTimer("room1Target2",(FMath::FRand() * TargetFlipModifier));
		StartTimer("room1Target3",(FMath::FRand() * TargetFlipModifier));
		StartTimer("room1Target4",(FMath::FRand() * TargetFlipModifier));
		StartTimer("room1Target5",(FMath::FRand() * TargetFlipModifier));
		StartTimer("room1Target6",(FMath::FRand() * TargetFlipModifier));
		StartTimer("room1Target7",(FMath::FRand() * TargetFlipModifier));
		StartTimer("room1Target8",(FMath::FRand() * TargetFlipModifier));
		StartTimer("room1Reset",4);
		building1MTTrigger01->DisableTrigger();
		UnCaptureEvent(building1MTTrigger01);
		return true;
	}
	Function bool Building1MT_Trigger06AB_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		StartTimer("room2Target1",(FMath::FRand() * TargetFlipModifier));
		StartTimer("room2Target2",(FMath::FRand() * TargetFlipModifier));
		StartTimer("room2Target3",(FMath::FRand() * TargetFlipModifier));
		StartTimer("room2Target4",(FMath::FRand() * TargetFlipModifier));
		StartTimer("room2Target5",(FMath::FRand() * TargetFlipModifier));
		StartTimer("room2Target6",(FMath::FRand() * TargetFlipModifier));
		StartTimer("room2Reset",4);
		building1MTTrigger03->DisableTrigger();
		UnCaptureEvent(building1MTTrigger03);
		return true;
	}
	Function bool Building1MT_Trigger02B_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		flipDoor1Targets();
		return true;
	}
	Function flipDoor1Targets()
	{
		if (! bbuilding1Door1Flipped)
		{
			bbuilding1Door1Flipped=true;
			StartTimer("Door1Target1",(FMath::FRand() * TargetFlipModifier));
			StartTimer("Door1Target2",(FMath::FRand() * TargetFlipModifier));
			StartTimer("Door1Target3",(FMath::FRand() * TargetFlipModifier));
			StartTimer("Door1Target4",(FMath::FRand() * TargetFlipModifier));
			StartTimer("Door1Target5",(FMath::FRand() * TargetFlipModifier));
			StartTimer("Door1Target6",(FMath::FRand() * TargetFlipModifier));
			StartTimer("door1Reset",4);
		}
	}
	Function flipDoor2Targets()
	{
		if (! bbuilding1Door2Flipped)
		{
			bbuilding1Door2Flipped=true;
			StartTimer("Door2Target1",(FMath::FRand() * TargetFlipModifier));
			StartTimer("Door2Target2",(FMath::FRand() * TargetFlipModifier));
			StartTimer("Door2Target3",(FMath::FRand() * TargetFlipModifier));
			StartTimer("Door2Target4",(FMath::FRand() * TargetFlipModifier));
			StartTimer("Door2Target5",(FMath::FRand() * TargetFlipModifier));
			StartTimer("door2Reset",4);
		}
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "Door1Target1":
			PlayGameSound("m_hydraulic",building1M01Target1);
			building1M01Target1.TriggerSelf();
			return true;
			case "Door1Target2":
			PlayGameSound("m_hydraulic",building1M01Target2);
			building1M01Target2.TriggerSelf();
			return true;
			case "Door1Target3":
			PlayGameSound("m_hydraulic",building1M01Target3);
			building1M01Target3.TriggerSelf();
			return true;
			case "Door1Target4":
			PlayGameSound("m_hydraulic",building1M02Target1);
			building1M02Target1.TriggerSelf();
			return true;
			case "Door1Target5":
			PlayGameSound("m_hydraulic",building1M02Target2);
			building1M02Target2.TriggerSelf();
			return true;
			case "Door1Target6":
			PlayGameSound("m_hydraulic",building1M03Target1);
			building1M03Target1.TriggerSelf();
			return true;
			case "Door2Target1":
			PlayGameSound("m_hydraulic",building1M01Target1);
			building1M01Target1.TriggerSelf();
			return true;
			case "Door2Target2":
			PlayGameSound("m_hydraulic",building1M04Target2);
			building1M04Target2.TriggerSelf();
			return true;
			case "Door2Target3":
			PlayGameSound("m_hydraulic",building1M04Target3);
			building1M04Target3.TriggerSelf();
			return true;
			case "Door2Target4":
			PlayGameSound("m_hydraulic",building1M05Target1);
			building1M05Target1.TriggerSelf();
			return true;
			case "Door2Target5":
			PlayGameSound("m_hydraulic",building1M05Target2);
			building1M05Target2.TriggerSelf();
			return true;
			case "room1Target1":
			PlayGameSound("m_hydraulic",building1M06Target1);
			building1M06Target1.TriggerSelf();
			return true;
			case "room1Target2":
			PlayGameSound("m_hydraulic",building1M06Target2);
			building1M06Target2.TriggerSelf();
			return true;
			case "room1Target3":
			PlayGameSound("m_hydraulic",building1M07Target1);
			building1M07Target1.TriggerSelf();
			return true;
			case "room1Target4":
			PlayGameSound("m_hydraulic",building1M07Target2);
			building1M07Target2.TriggerSelf();
			return true;
			case "room1Target5":
			PlayGameSound("m_hydraulic",building1M07Target3);
			building1M07Target3.TriggerSelf();
			case "room1Target6":
			PlayGameSound("m_hydraulic",building1M07Target4);
			building1M07Target4.TriggerSelf();
			return true;
			case "room1Target7":
			PlayGameSound("m_hydraulic",building1M07Target5);
			building1M07Target5.TriggerSelf();
			return true;
			case "room1Target8":
			PlayGameSound("m_hydraulic",building1M07Target6);
			building1M07Target6.TriggerSelf();
			return true;
			case "room2Target1":
			PlayGameSound("m_hydraulic",building1M08Target1);
			building1M08Target1.TriggerSelf();
			return true;
			case "room2Target2":
			PlayGameSound("m_hydraulic",building1M08Target2);
			building1M08Target2.TriggerSelf();
			return true;
			case "room2Target3":
			PlayGameSound("m_hydraulic",building1M08Target3);
			building1M08Target3.TriggerSelf();
			return true;
			case "room2Target4":
			PlayGameSound("m_hydraulic",building1M08Target4);
			building1M08Target4.TriggerSelf();
			return true;
			case "room2Target5":
			PlayGameSound("m_hydraulic",building1M08Target5);
			building1M08Target5.TriggerSelf();
			case "room2Target6":
			PlayGameSound("m_hydraulic",building1M08Target6);
			building1M08Target6.TriggerSelf();
			return true;
			case "door1Pause":
			flipDoor1Targets();
			return true;
			case "door2Pause":
			flipDoor2Targets();
			return true;
			case "door1Reset":
			building1M01Target1.ResetTarget(true);
			building1M01Target2.ResetTarget(true);
			building1M01Target3.ResetTarget(true);
			building1M02Target1.ResetTarget(true);
			building1M02Target2.ResetTarget(true);
			building1M03Target1.ResetTarget(true);
			return true;
			case "door2Reset":
			building1M04Target1.ResetTarget(true);
			building1M04Target2.ResetTarget(true);
			building1M04Target3.ResetTarget(true);
			building1M05Target1.ResetTarget(true);
			building1M05Target2.ResetTarget(true);
			return true;
			case "room1Reset":
			building1M06Target1.ResetTarget(true);
			building1M06Target2.ResetTarget(true);
			building1M07Target1.ResetTarget(true);
			building1M07Target2.ResetTarget(true);
			building1M07Target3.ResetTarget(true);
			building1M07Target4.ResetTarget(true);
			building1M07Target5.ResetTarget(true);
			building1M07Target6.ResetTarget(true);
			return true;
			case "room2Reset":
			building1M08Target1.ResetTarget(true);
			building1M08Target2.ResetTarget(true);
			building1M08Target3.ResetTarget(true);
			building1M08Target4.ResetTarget(true);
			building1M08Target5.ResetTarget(true);
			building1M08Target6.ResetTarget(true);
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		SetCustomTimer(keepMovingIdleTime,false,"CheckPlayerMove");
		building1M01Target1=MarksmanTarget(CaptureEvent("Building1Marker01Target01"));
		building1M01Target2=MarksmanTarget(CaptureEvent("Building1Marker01Target02"));
		building1M01Target3=MarksmanTarget(CaptureEvent("Building1Marker01Target03"));
		building1M02Target1=MarksmanTarget(CaptureEvent("Building1Marker02Target01"));
		building1M02Target2=MarksmanTarget(CaptureEvent("Building1Marker02Target02"));
		building1M03Target1=MarksmanTarget(CaptureEvent("Building1Marker03Target01"));
		building1M04Target1=MarksmanTarget(CaptureEvent("Building1Marker04Target01"));
		building1M04Target2=MarksmanTarget(CaptureEvent("Building1Marker04Target02"));
		building1M04Target3=MarksmanTarget(CaptureEvent("Building1Marker04Target03"));
		building1M05Target1=MarksmanTarget(CaptureEvent("Building1Marker05Target01"));
		building1M05Target2=MarksmanTarget(CaptureEvent("Building1Marker05Target02"));
		building1M08Target1=MarksmanTarget(CaptureEvent("Building1Marker08Target01"));
		building1M08Target2=MarksmanTarget(CaptureEvent("Building1Marker08Target02"));
		building1M08Target3=MarksmanTarget(CaptureEvent("Building1Marker08Target03"));
		building1M08Target4=MarksmanTarget(CaptureEvent("Building1Marker08Target04"));
		building1M08Target5=MarksmanTarget(CaptureEvent("Building1Marker08Target05"));
		building1M08Target6=MarksmanTarget(CaptureEvent("Building1Marker08Target06"));
		if (! building1MTTriggerCaptured)
		{
			building1MTTrigger01=TriggerVolume(CaptureEvent("Building1MT_Trigger02AB"));
			building1MTTrigger02=TriggerVolume(CaptureEvent("Building1MT_Trigger02B"));
			building1MTTrigger03=TriggerVolume(CaptureEvent("Building1MT_Trigger06AB"));
			building1MTTriggerCaptured=true;
		}
		opforRunningCount=0;
		if (door1Entered && (! bAllMTTriggersDisabled))
		{
			StartTimer("door1Pause",preTimerPause);
			building1M04Target1.bHidden=true;
			building1M04Target2.bHidden=true;
			building1M04Target3.bHidden=true;
			building1M05Target1.bHidden=true;
			building1M05Target2.bHidden=true;
		}
		if (door2Entered && (! bAllMTTriggersDisabled))
		{
			StartTimer("door2Pause",preTimerPause);
			building1M04Target1.bHidden=false;
			building1M04Target2.bHidden=false;
			building1M04Target3.bHidden=false;
			building1M05Target1.bHidden=false;
			building1M05Target2.bHidden=false;
		}
	}
	Event EndState()
	{
		building1M01Target1.ResetTarget(true);
		UnCaptureEvent(building1M01Target1);
		building1M01Target2.ResetTarget(true);
		UnCaptureEvent(building1M01Target2);
		building1M01Target3.ResetTarget(true);
		UnCaptureEvent(building1M01Target3);
		building1M02Target1.ResetTarget(true);
		UnCaptureEvent(building1M02Target1);
		building1M02Target2.ResetTarget(true);
		UnCaptureEvent(building1M02Target2);
		building1M03Target1.ResetTarget(true);
		UnCaptureEvent(building1M03Target1);
		building1M04Target1.ResetTarget(true);
		UnCaptureEvent(building1M04Target1);
		building1M04Target2.ResetTarget(true);
		UnCaptureEvent(building1M04Target2);
		building1M04Target3.ResetTarget(true);
		UnCaptureEvent(building1M04Target3);
		building1M05Target1.ResetTarget(true);
		UnCaptureEvent(building1M05Target1);
		building1M05Target2.ResetTarget(true);
		UnCaptureEvent(building1M05Target2);
		building1M06Target1.ResetTarget(true);
		UnCaptureEvent(building1M06Target1);
		building1M06Target2.ResetTarget(true);
		UnCaptureEvent(building1M06Target2);
		building1M07Target1.ResetTarget(true);
		UnCaptureEvent(building1M07Target1);
		building1M07Target2.ResetTarget(true);
		UnCaptureEvent(building1M07Target2);
		building1M07Target3.ResetTarget(true);
		UnCaptureEvent(building1M07Target3);
		building1M07Target4.ResetTarget(true);
		UnCaptureEvent(building1M07Target4);
		building1M07Target5.ResetTarget(true);
		UnCaptureEvent(building1M07Target5);
		building1M07Target6.ResetTarget(true);
		UnCaptureEvent(building1M07Target6);
		building1M08Target1.ResetTarget(true);
		UnCaptureEvent(building1M08Target1);
		building1M08Target2.ResetTarget(true);
		UnCaptureEvent(building1M08Target2);
		building1M08Target3.ResetTarget(true);
		UnCaptureEvent(building1M08Target3);
		building1M08Target4.ResetTarget(true);
		UnCaptureEvent(building1M08Target4);
		building1M08Target5.ResetTarget(true);
		UnCaptureEvent(building1M08Target5);
		building1M08Target6.ResetTarget(true);
		UnCaptureEvent(building1M08Target6);
	}
}
*/

/*
State Building1InActive extends building1Active
{
	Function BeginState()
	{
		door1Entered=false;
		door2Entered=false;
		ChangeState("NoBuildingActive");
	}
}
*/

/*
State Building2Active
{
	Function bool Building2MT_Trigger07B_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (door1Entered)
		{
			StartTimer("Trigger07B",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building2MTTrigger05);
		}
		return true;
	}
	Function Trigger07BFlip()
	{
		if (building2MTTrigger05.bActive)
		{
			building2M11Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M11Target1);
			building2M11Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M11Target2);
			building2M11Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M11Target3);
			building2M11Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M11Target4);
			building2M11Target5.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M11Target5);
			building2MTTrigger05->DisableTrigger();
			StartTimer("Trigger07BReset",4);
		}
	}
	Function Trigger07BReset()
	{
		building2M11Target1.ResetTarget(true);
		building2M11Target2.ResetTarget(true);
		building2M11Target3.ResetTarget(true);
		building2M11Target4.ResetTarget(true);
		building2M11Target5.ResetTarget(true);
	}
	Function bool Building2MT_Trigger08A_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (door1Entered)
		{
			StartTimer("Trigger08A",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building2MTTrigger06);
		}
		return true;
	}
	Function Trigger08AFlip()
	{
		if (building2MTTrigger06.bActive)
		{
			building2M12Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M12Target1);
			building2M12Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M12Target2);
			building2M12Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M12Target3);
			building2MTTrigger06->DisableTrigger();
			StartTimer("Trigger08AReset",4);
		}
	}
	Function Trigger08AReset()
	{
		building2M12Target1.ResetTarget(true);
		building2M12Target2.ResetTarget(true);
		building2M12Target3.ResetTarget(true);
	}
	Function bool Building2MT_Trigger09A_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (door1Entered)
		{
			StartTimer("Trigger09A",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building2MTTrigger07);
		}
		return true;
	}
	Function Trigger09AFlip()
	{
		if (building2MTTrigger07.bActive)
		{
			building2M13Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M13Target1);
			building2M13Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M13Target2);
			building2M13Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M13Target3);
			building2MTTrigger07->DisableTrigger();
			StartTimer("Trigger09AReset",4);
		}
	}
	Function Trigger09AReset()
	{
		building2M13Target1.ResetTarget(true);
		building2M13Target2.ResetTarget(true);
		building2M13Target3.ResetTarget(true);
	}
	Function bool Building2MT_Trigger10A_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (door1Entered)
		{
			StartTimer("Trigger10A",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building2MTTrigger08);
		}
		return true;
	}
	Function Trigger10AFlip()
	{
		if (building2MTTrigger08.bActive)
		{
			building2M14Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M14Target1);
			building2M14Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M14Target2);
			building2M14Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M14Target3);
			building2M14Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M14Target4);
			building2M14Target5.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M14Target5);
			building2MTTrigger08->DisableTrigger();
			StartTimer("Trigger10AReset",4);
		}
	}
	Function Trigger10AReset()
	{
		building2M14Target1.ResetTarget(true);
		building2M14Target2.ResetTarget(true);
		building2M14Target3.ResetTarget(true);
		building2M14Target4.ResetTarget(true);
		building2M14Target5.ResetTarget(true);
	}
	Function bool Building2MT_Trigger11A_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (door1Entered)
		{
			StartTimer("Trigger11A",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building2MTTrigger09);
		}
		return true;
	}
	Function Trigger11AFlip()
	{
		if (building2MTTrigger09.bActive)
		{
			building2M15Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M14Target1);
			building2MTTrigger09->DisableTrigger();
			StartTimer("Trigger11AReset",4);
		}
	}
	Function Trigger11AReset()
	{
		building2M15Target1.ResetTarget(true);
	}
	Function bool Building2MT_Trigger12A_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (door1Entered)
		{
			StartTimer("Trigger12A",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building2MTTrigger10);
		}
		return true;
	}
	Function Trigger12AFlip()
	{
		if (building2MTTrigger10.bActive)
		{
			building2M16Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M16Target1);
			building2M16Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M16Target2);
			building2M16Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M16Target3);
			building2M17Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M17Target1);
			building2M17Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M17Target2);
			building2M18Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M18Target1);
			building2M18Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M18Target2);
			building2M18Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M18Target3);
			building2MTTrigger10->DisableTrigger();
			StartTimer("Trigger12AReset",4);
		}
	}
	Function Trigger12AReset()
	{
		building2M16Target1.ResetTarget(true);
		building2M16Target2.ResetTarget(true);
		building2M16Target3.ResetTarget(true);
		building2M17Target1.ResetTarget(true);
		building2M17Target2.ResetTarget(true);
		building2M18Target1.ResetTarget(true);
		building2M18Target2.ResetTarget(true);
		building2M18Target3.ResetTarget(true);
	}
	Function bool Building2MT_Trigger05B_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (door2Entered)
		{
			StartTimer("Trigger05B",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building2MTTrigger04);
		}
		return true;
	}
	Function Trigger05BFlip()
	{
		if (building2MTTrigger04.bActive)
		{
			building2M09Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M09Target1);
			building2M09Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M09Target2);
			building2M09Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M09Target3);
			building2M09Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M09Target4);
			building2MTTrigger04->DisableTrigger();
			StartTimer("Trigger05BReset",4);
		}
	}
	Function Trigger05BReset()
	{
		building2M09Target1.ResetTarget(true);
		building2M09Target2.ResetTarget(true);
		building2M09Target3.ResetTarget(true);
		building2M09Target4.ResetTarget(true);
	}
	Function bool Building2MT_Trigger04B_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (door2Entered)
		{
			StartTimer("Trigger04B",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building2MTTrigger03);
		}
		return true;
	}
	Function Trigger04BFlip()
	{
		if (building2MTTrigger03.bActive)
		{
			building2M05Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M05Target1);
			building2M05Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M05Target2);
			building2M05Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M05Target3);
			building2M06Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M06Target1);
			building2M06Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M06Target2);
			building2M06Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M06Target3);
			building2M07Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M07Target1);
			building2M07Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M07Target2);
			building2M07Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M07Target3);
			building2M08Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M08Target1);
			building2M08Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M08Target2);
			building2MTTrigger03->DisableTrigger();
			StartTimer("Trigger04BReset",4);
		}
	}
	Function Trigger04BReset()
	{
		building2M05Target1.ResetTarget(true);
		building2M05Target2.ResetTarget(true);
		building2M05Target3.ResetTarget(true);
		building2M06Target1.ResetTarget(true);
		building2M06Target2.ResetTarget(true);
		building2M06Target3.ResetTarget(true);
		building2M07Target1.ResetTarget(true);
		building2M07Target2.ResetTarget(true);
		building2M07Target3.ResetTarget(true);
		building2M08Target1.ResetTarget(true);
		building2M08Target2.ResetTarget(true);
	}
	Function bool Building2MT_Trigger03B_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (door2Entered)
		{
			StartTimer("Trigger03B",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building2MTTrigger02);
		}
		return true;
	}
	Function Trigger03BFlip()
	{
		if (building2MTTrigger02.bActive)
		{
			building2M04Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M03Target1);
			building2M04Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M04Target2);
			building2M04Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M04Target3);
			building2M04Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M04Target4);
			building2M04Target5.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M04Target5);
			building2MTTrigger02->DisableTrigger();
			StartTimer("Trigger03bReset",4);
		}
	}
	Function Trigger03bReset()
	{
		building2M04Target1.ResetTarget(true);
		building2M04Target2.ResetTarget(true);
		building2M04Target3.ResetTarget(true);
		building2M04Target4.ResetTarget(true);
		building2M04Target5.ResetTarget(true);
	}
	Function bool Building2MT_Trigger02B_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (door2Entered)
		{
			StartTimer("Trigger02B",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building2MTTrigger01);
		}
		return true;
	}
	Function Trigger02BFlip()
	{
		if (building2MTTrigger01.bActive)
		{
			building2M03Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M03Target1);
			building2M03Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M03Target2);
			building2M03Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M03Target3);
			building2MTTrigger01->DisableTrigger();
			StartTimer("Trigger02BReset",4);
		}
	}
	Function Trigger02BReset()
	{
		building2M03Target1.ResetTarget(true);
		building2M03Target2.ResetTarget(true);
		building2M03Target3.ResetTarget(true);
	}
	Function flipDoor1Targets()
	{
		if (! bbuilding2Door1Flipped)
		{
			building2M10Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M10Target1);
			building2M10Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M10Target2);
			building2M10Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M10Target3);
			building2M10Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M10Target4);
			building2M10Target5.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M10Target5);
			building2M10Target6.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M10Target6);
			bbuilding2Door1Flipped=true;
			StartTimer("door1Reset",4);
		}
	}
	Function ResetDoor1Targets()
	{
		building2M10Target1.ResetTarget(true);
		building2M10Target2.ResetTarget(true);
		building2M10Target3.ResetTarget(true);
		building2M10Target4.ResetTarget(true);
		building2M10Target5.ResetTarget(true);
		building2M10Target6.ResetTarget(true);
	}
	Function flipDoor2Targets()
	{
		if (! bbuilding2Door2Flipped)
		{
			building2M01Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M01Target1);
			building2M02Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M02Target1);
			building2M02Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building2M02Target2);
			bbuilding2Door2Flipped=true;
			StartTimer("door2Reset",4);
		}
	}
	Function ResetDoor2Targets()
	{
		building2M01Target1.ResetTarget(true);
		building2M02Target1.ResetTarget(true);
		building2M02Target2.ResetTarget(true);
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "door1Pause":
			flipDoor1Targets();
			return true;
			case "door2Pause":
			flipDoor2Targets();
			return true;
			case "door1Reset":
			ResetDoor1Targets();
			return true;
			case "door2Reset":
			ResetDoor2Targets();
			return true;
			case "Trigger07B":
			Trigger07BFlip();
			return true;
			case "Trigger08A":
			Trigger08AFlip();
			return true;
			case "Trigger09A":
			Trigger09AFlip();
			return true;
			case "Trigger10A":
			Trigger10AFlip();
			return true;
			case "Trigge11A":
			Trigger11AFlip();
			return true;
			case "Trigger12A":
			Trigger12AFlip();
			return true;
			case "Trigger05B":
			Trigger05BFlip();
			return true;
			case "Trigger04B":
			Trigger04BFlip();
			return true;
			case "Trigger03B":
			Trigger03BFlip();
			return true;
			case "Trigger02B":
			Trigger02BFlip();
			return true;
			case "Trigger07BReset":
			Trigger07BReset();
			return true;
			case "Trigger08AReset":
			Trigger08AReset();
			return true;
			case "Trigger09AReset":
			Trigger09AReset();
			return true;
			case "Trigger10AReset":
			Trigger10AReset();
			return true;
			case "Trigge11AReset":
			Trigger11AReset();
			return true;
			case "Trigger12AReset":
			Trigger12AReset();
			return true;
			case "Trigger05BReset":
			Trigger05BReset();
			return true;
			case "Trigger04BReset":
			Trigger04BReset();
			return true;
			case "Trigger03bReset":
			Trigger03bReset();
			return true;
			case "Trigger02BReset":
			Trigger02BReset();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		building2M01Target1=MarksmanTarget(CaptureEvent("Building2Marker01Target01"));
		building2M02Target1=MarksmanTarget(CaptureEvent("Building2Marker02Target01"));
		building2M02Target2=MarksmanTarget(CaptureEvent("Building2Marker02Target02"));
		building2M03Target1=MarksmanTarget(CaptureEvent("Building2Marker03Target01"));
		building2M03Target2=MarksmanTarget(CaptureEvent("Building2Marker03Target02"));
		building2M03Target3=MarksmanTarget(CaptureEvent("Building2Marker03Target03"));
		building2M04Target1=MarksmanTarget(CaptureEvent("Building2Marker04Target01"));
		building2M04Target2=MarksmanTarget(CaptureEvent("Building2Marker04Target02"));
		building2M04Target3=MarksmanTarget(CaptureEvent("Building2Marker04Target03"));
		building2M04Target4=MarksmanTarget(CaptureEvent("Building2Marker04Target04"));
		building2M04Target5=MarksmanTarget(CaptureEvent("Building2Marker04Target05"));
		building2M05Target1=MarksmanTarget(CaptureEvent("Building2Marker05Target01"));
		building2M05Target2=MarksmanTarget(CaptureEvent("Building2Marker05Target02"));
		building2M05Target3=MarksmanTarget(CaptureEvent("Building2Marker05Target03"));
		building2M06Target1=MarksmanTarget(CaptureEvent("Building2Marker06Target01"));
		building2M06Target2=MarksmanTarget(CaptureEvent("Building2Marker06Target02"));
		building2M06Target3=MarksmanTarget(CaptureEvent("Building2Marker06Target03"));
		building2M07Target1=MarksmanTarget(CaptureEvent("Building2Marker07Target01"));
		building2M07Target2=MarksmanTarget(CaptureEvent("Building2Marker07Target02"));
		building2M07Target3=MarksmanTarget(CaptureEvent("Building2Marker07Target03"));
		building2M08Target1=MarksmanTarget(CaptureEvent("Building2Marker08Target01"));
		building2M08Target2=MarksmanTarget(CaptureEvent("Building2Marker08Target02"));
		building2M09Target1=MarksmanTarget(CaptureEvent("Building2Marker09Target01"));
		building2M09Target2=MarksmanTarget(CaptureEvent("Building2Marker09Target02"));
		building2M09Target3=MarksmanTarget(CaptureEvent("Building2Marker09Target03"));
		building2M09Target4=MarksmanTarget(CaptureEvent("Building2Marker09Target04"));
		building2M10Target1=MarksmanTarget(CaptureEvent("Building2Marker10Target01"));
		building2M10Target2=MarksmanTarget(CaptureEvent("Building2Marker10Target02"));
		building2M10Target3=MarksmanTarget(CaptureEvent("Building2Marker10Target03"));
		building2M10Target4=MarksmanTarget(CaptureEvent("Building2Marker10Target04"));
		building2M10Target5=MarksmanTarget(CaptureEvent("Building2Marker10Target05"));
		building2M10Target6=MarksmanTarget(CaptureEvent("Building2Marker10Target06"));
		building2M11Target1=MarksmanTarget(CaptureEvent("Building2Marker11Target01"));
		building2M11Target2=MarksmanTarget(CaptureEvent("Building2Marker11Target02"));
		building2M11Target3=MarksmanTarget(CaptureEvent("Building2Marker11Target03"));
		building2M11Target4=MarksmanTarget(CaptureEvent("Building2Marker11Target04"));
		building2M11Target5=MarksmanTarget(CaptureEvent("Building2Marker11Target05"));
		building2M12Target1=MarksmanTarget(CaptureEvent("Building2Marker12Target01"));
		building2M12Target2=MarksmanTarget(CaptureEvent("Building2Marker12Target02"));
		building2M12Target3=MarksmanTarget(CaptureEvent("Building2Marker12Target03"));
		building2M13Target1=MarksmanTarget(CaptureEvent("Building2Marker13Target01"));
		building2M13Target2=MarksmanTarget(CaptureEvent("Building2Marker13Target02"));
		building2M13Target3=MarksmanTarget(CaptureEvent("Building2Marker13Target03"));
		building2M14Target1=MarksmanTarget(CaptureEvent("Building2Marker14Target01"));
		building2M14Target2=MarksmanTarget(CaptureEvent("Building2Marker14Target02"));
		building2M14Target3=MarksmanTarget(CaptureEvent("Building2Marker14Target03"));
		building2M14Target4=MarksmanTarget(CaptureEvent("Building2Marker14Target04"));
		building2M14Target5=MarksmanTarget(CaptureEvent("Building2Marker14Target05"));
		building2M15Target1=MarksmanTarget(CaptureEvent("Building2Marker15Target01"));
		building2M16Target1=MarksmanTarget(CaptureEvent("Building2Marker16Target01"));
		building2M16Target2=MarksmanTarget(CaptureEvent("Building2Marker16Target02"));
		building2M16Target3=MarksmanTarget(CaptureEvent("Building2Marker16Target03"));
		building2M17Target1=MarksmanTarget(CaptureEvent("Building2Marker17Target01"));
		building2M17Target2=MarksmanTarget(CaptureEvent("Building2Marker17Target02"));
		building2M18Target1=MarksmanTarget(CaptureEvent("Building2Marker18Target01"));
		building2M18Target2=MarksmanTarget(CaptureEvent("Building2Marker18Target02"));
		building2M18Target3=MarksmanTarget(CaptureEvent("Building2Marker18Target03"));
		if (door1Entered && (! bAllMTTriggersDisabled))
		{
			StartTimer("door1Pause",preTimerPause);
			building2M01Target1.bHidden=true;
			building2M02Target1.bHidden=true;
			building2M02Target2.bHidden=true;
			building2M03Target1.bHidden=true;
			building2M03Target2.bHidden=true;
			building2M03Target3.bHidden=true;
			building2M04Target1.bHidden=true;
			building2M04Target2.bHidden=true;
			building2M04Target3.bHidden=true;
			building2M04Target4.bHidden=true;
			building2M04Target5.bHidden=true;
			building2M05Target1.bHidden=true;
			building2M05Target2.bHidden=true;
			building2M05Target3.bHidden=true;
			building2M06Target1.bHidden=true;
			building2M06Target2.bHidden=true;
			building2M06Target3.bHidden=true;
			building2M07Target1.bHidden=true;
			building2M07Target2.bHidden=true;
			building2M07Target3.bHidden=true;
			building2M08Target1.bHidden=true;
			building2M08Target2.bHidden=true;
			building2M09Target1.bHidden=true;
			building2M09Target2.bHidden=true;
			building2M09Target3.bHidden=true;
			building2M09Target4.bHidden=true;
			building2M10Target1.bHidden=false;
			building2M10Target2.bHidden=false;
			building2M10Target3.bHidden=false;
			building2M10Target4.bHidden=false;
			building2M10Target5.bHidden=false;
			building2M10Target6.bHidden=false;
			building2M11Target1.bHidden=false;
			building2M11Target2.bHidden=false;
			building2M11Target3.bHidden=false;
			building2M11Target4.bHidden=false;
			building2M11Target5.bHidden=false;
			building2M12Target1.bHidden=false;
			building2M12Target2.bHidden=false;
			building2M12Target3.bHidden=false;
			building2M13Target1.bHidden=false;
			building2M13Target2.bHidden=false;
			building2M13Target3.bHidden=false;
			building2M14Target1.bHidden=false;
			building2M14Target2.bHidden=false;
			building2M14Target3.bHidden=false;
			building2M14Target4.bHidden=false;
			building2M14Target5.bHidden=false;
			building2M15Target1.bHidden=false;
			building2M16Target1.bHidden=false;
			building2M16Target2.bHidden=false;
			building2M16Target3.bHidden=false;
			building2M17Target1.bHidden=false;
			building2M17Target2.bHidden=false;
			building2M18Target1.bHidden=false;
			building2M18Target2.bHidden=false;
			building2M18Target3.bHidden=false;
		}
		if (door2Entered && (! bAllMTTriggersDisabled))
		{
			StartTimer("door2Pause",preTimerPause);
			building2M10Target1.bHidden=true;
			building2M10Target2.bHidden=true;
			building2M10Target3.bHidden=true;
			building2M10Target4.bHidden=true;
			building2M10Target5.bHidden=true;
			building2M10Target6.bHidden=true;
			building2M11Target1.bHidden=true;
			building2M11Target2.bHidden=true;
			building2M11Target3.bHidden=true;
			building2M11Target4.bHidden=true;
			building2M11Target5.bHidden=true;
			building2M12Target1.bHidden=true;
			building2M12Target2.bHidden=true;
			building2M12Target3.bHidden=true;
			building2M13Target1.bHidden=true;
			building2M13Target2.bHidden=true;
			building2M13Target3.bHidden=true;
			building2M14Target1.bHidden=true;
			building2M14Target2.bHidden=true;
			building2M14Target3.bHidden=true;
			building2M14Target4.bHidden=true;
			building2M14Target5.bHidden=true;
			building2M15Target1.bHidden=true;
			building2M16Target1.bHidden=true;
			building2M16Target2.bHidden=true;
			building2M16Target3.bHidden=true;
			building2M17Target1.bHidden=true;
			building2M17Target2.bHidden=true;
			building2M18Target1.bHidden=true;
			building2M18Target2.bHidden=true;
			building2M18Target3.bHidden=true;
			building2M01Target1.bHidden=false;
			building2M02Target1.bHidden=false;
			building2M02Target2.bHidden=false;
			building2M03Target1.bHidden=false;
			building2M03Target2.bHidden=false;
			building2M03Target3.bHidden=false;
			building2M04Target1.bHidden=false;
			building2M04Target2.bHidden=false;
			building2M04Target3.bHidden=false;
			building2M04Target4.bHidden=false;
			building2M04Target5.bHidden=false;
			building2M05Target1.bHidden=false;
			building2M05Target2.bHidden=false;
			building2M05Target3.bHidden=false;
			building2M06Target1.bHidden=false;
			building2M06Target2.bHidden=false;
			building2M06Target3.bHidden=false;
			building2M07Target1.bHidden=false;
			building2M07Target2.bHidden=false;
			building2M07Target3.bHidden=false;
			building2M08Target1.bHidden=false;
			building2M08Target2.bHidden=false;
			building2M09Target1.bHidden=false;
			building2M09Target2.bHidden=false;
			building2M09Target3.bHidden=false;
			building2M09Target4.bHidden=false;
		}
		if (! building2MTTriggerCaptured)
		{
			building2MTTrigger01=TriggerVolume(CaptureEvent("Building2MT_Trigger02B"));
			building2MTTrigger02=TriggerVolume(CaptureEvent("Building2MT_Trigger03B"));
			building2MTTrigger03=TriggerVolume(CaptureEvent("Building2MT_Trigger04B"));
			building2MTTrigger04=TriggerVolume(CaptureEvent("Building2MT_Trigger05B"));
			building2MTTrigger05=TriggerVolume(CaptureEvent("Building2MT_Trigger07B"));
			building2MTTrigger06=TriggerVolume(CaptureEvent("Building2MT_Trigger08A"));
			building2MTTrigger07=TriggerVolume(CaptureEvent("Building2MT_Trigger09A"));
			building2MTTrigger08=TriggerVolume(CaptureEvent("Building2MT_Trigger10A"));
			building2MTTrigger09=TriggerVolume(CaptureEvent("Building2MT_Trigger11A"));
			building2MTTrigger10=TriggerVolume(CaptureEvent("Building2MT_Trigger12A"));
			building2MTTriggerCaptured=true;
		}
	}
}
*/

/*
State Building2InActive extends Building2Active
{
	Function BeginState()
	{
		door1Entered=false;
		door2Entered=false;
		ChangeState("NoBuildingActive");
	}
	Function resetCapturedTargets()
	{
		building2M10Target1.ResetTarget(true);
		UnCaptureEvent(building2M10Target1);
		building2M10Target2.ResetTarget(true);
		UnCaptureEvent(building2M10Target2);
		building2M10Target3.ResetTarget(true);
		UnCaptureEvent(building2M10Target3);
		building2M10Target4.ResetTarget(true);
		UnCaptureEvent(building2M10Target4);
		building2M10Target5.ResetTarget(true);
		UnCaptureEvent(building2M10Target5);
		building2M10Target6.ResetTarget(true);
		UnCaptureEvent(building2M10Target6);
		building2M01Target1.ResetTarget(true);
		UnCaptureEvent(building2M01Target1);
		building2M02Target1.ResetTarget(true);
		UnCaptureEvent(building2M02Target1);
		building2M02Target2.ResetTarget(true);
		UnCaptureEvent(building2M02Target2);
		building2M11Target1.ResetTarget(true);
		UnCaptureEvent(building2M11Target1);
		building2M11Target2.ResetTarget(true);
		UnCaptureEvent(building2M11Target2);
		building2M11Target3.ResetTarget(true);
		UnCaptureEvent(building2M11Target3);
		building2M11Target4.ResetTarget(true);
		UnCaptureEvent(building2M11Target4);
		building2M11Target5.ResetTarget(true);
		UnCaptureEvent(building2M11Target5);
		building2M12Target1.ResetTarget(true);
		UnCaptureEvent(building2M12Target1);
		building2M12Target2.ResetTarget(true);
		UnCaptureEvent(building2M12Target2);
		building2M12Target3.ResetTarget(true);
		UnCaptureEvent(building2M12Target3);
		building2M13Target1.ResetTarget(true);
		UnCaptureEvent(building2M13Target1);
		building2M13Target2.ResetTarget(true);
		UnCaptureEvent(building2M13Target2);
		building2M13Target3.ResetTarget(true);
		UnCaptureEvent(building2M13Target3);
		building2M14Target1.ResetTarget(true);
		UnCaptureEvent(building2M14Target1);
		building2M14Target2.ResetTarget(true);
		UnCaptureEvent(building2M14Target2);
		building2M14Target3.ResetTarget(true);
		UnCaptureEvent(building2M14Target3);
		building2M14Target2.ResetTarget(true);
		UnCaptureEvent(building2M14Target2);
		building2M14Target3.ResetTarget(true);
		UnCaptureEvent(building2M14Target3);
		building2M15Target1.ResetTarget(true);
		UnCaptureEvent(building2M15Target1);
		building2M16Target1.ResetTarget(true);
		UnCaptureEvent(building2M16Target1);
		building2M16Target2.ResetTarget(true);
		UnCaptureEvent(building2M16Target2);
		building2M16Target3.ResetTarget(true);
		UnCaptureEvent(building2M16Target3);
		building2M17Target1.ResetTarget(true);
		UnCaptureEvent(building2M17Target1);
		building2M17Target2.ResetTarget(true);
		UnCaptureEvent(building2M17Target2);
		building2M18Target1.ResetTarget(true);
		UnCaptureEvent(building2M18Target1);
		building2M18Target2.ResetTarget(true);
		UnCaptureEvent(building2M18Target2);
		building2M18Target3.ResetTarget(true);
		UnCaptureEvent(building2M18Target3);
		building2M09Target1.ResetTarget(true);
		UnCaptureEvent(building2M09Target1);
		building2M09Target2.ResetTarget(true);
		UnCaptureEvent(building2M09Target2);
		building2M09Target3.ResetTarget(true);
		UnCaptureEvent(building2M09Target3);
		building2M09Target4.ResetTarget(true);
		UnCaptureEvent(building2M09Target4);
		building2M05Target1.ResetTarget(true);
		UnCaptureEvent(building2M05Target1);
		building2M05Target2.ResetTarget(true);
		UnCaptureEvent(building2M05Target2);
		building2M05Target3.ResetTarget(true);
		UnCaptureEvent(building2M05Target3);
		building2M06Target1.ResetTarget(true);
		UnCaptureEvent(building2M06Target1);
		building2M06Target2.ResetTarget(true);
		UnCaptureEvent(building2M06Target2);
		building2M06Target3.ResetTarget(true);
		UnCaptureEvent(building2M06Target3);
		building2M07Target1.ResetTarget(true);
		UnCaptureEvent(building2M07Target1);
		building2M07Target2.ResetTarget(true);
		UnCaptureEvent(building2M07Target2);
		building2M07Target3.ResetTarget(true);
		UnCaptureEvent(building2M07Target3);
		building2M08Target1.ResetTarget(true);
		UnCaptureEvent(building2M08Target1);
		building2M08Target2.ResetTarget(true);
		UnCaptureEvent(building2M08Target2);
		building2M04Target1.ResetTarget(true);
		UnCaptureEvent(building2M04Target1);
		building2M04Target2.ResetTarget(true);
		UnCaptureEvent(building2M04Target2);
		building2M04Target3.ResetTarget(true);
		UnCaptureEvent(building2M04Target3);
		building2M04Target4.ResetTarget(true);
		UnCaptureEvent(building2M04Target4);
		building2M04Target5.ResetTarget(true);
		UnCaptureEvent(building2M04Target5);
		building2M03Target1.ResetTarget(true);
		UnCaptureEvent(building2M03Target1);
		building2M03Target2.ResetTarget(true);
		UnCaptureEvent(building2M03Target2);
		building2M03Target3.ResetTarget(true);
		UnCaptureEvent(building2M03Target3);
	}
}
*/

/*
State Building3Active
{
	Function bool Building3MT_Trigger03B_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (door2Entered)
		{
			building3MTTrigger01->DisableTrigger();
			Building3MT_Trigger06B_Enter(Trigger,Instigator);
		}
		return true;
	}
	Function bool Building3MT_Trigger02ABC_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		building3M03Target1=MarksmanTarget(CaptureEvent("Building3Marker03Target01"));
		building3M03Target2=MarksmanTarget(CaptureEvent("Building3Marker03Target02"));
		building3M03Target3=MarksmanTarget(CaptureEvent("Building3Marker03Target03"));
		building3M03Target4=MarksmanTarget(CaptureEvent("Building3Marker03Target04"));
		building3M03Target5=MarksmanTarget(CaptureEvent("Building3Marker03Target05"));
		StartTimer("Building3MT_Trigger02ABC_Flip",(FMath::FRand() * TargetFlipModifier));
		UnCaptureEvent(building3MTTrigger02);
		return true;
	}
	Function Building3MT_Trigger02ABC_Flip()
	{
		if (building3MTTrigger02.bActive)
		{
			building3M03Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M03Target1);
			building3M03Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M03Target2);
			building3M03Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M03Target3);
			building3M03Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M03Target4);
			building3M03Target5.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M03Target5);
			building3MTTrigger02->DisableTrigger();
			StartTimer("Building3MT_Trigger02ABC_Reset",4);
		}
	}
	Function Building3MT_Trigger02ABC_Reset()
	{
		building3M03Target1.ResetTarget(true);
		building3M03Target2.ResetTarget(true);
		building3M03Target3.ResetTarget(true);
		building3M03Target4.ResetTarget(true);
		building3M03Target5.ResetTarget(true);
	}
	Function bool Building3MT_Trigger03ABC_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		building3M04Target1=MarksmanTarget(CaptureEvent("Building3Marker04Target01"));
		building3M04Target2=MarksmanTarget(CaptureEvent("Building3Marker04Target02"));
		building3M04Target3=MarksmanTarget(CaptureEvent("Building3Marker04Target03"));
		StartTimer("Building3MT_Trigger03ABC_Flip",(FMath::FRand() * TargetFlipModifier));
		UnCaptureEvent(building3MTTrigger03);
		return true;
	}
	Function Building3MT_Trigger03ABC_Flip()
	{
		if (building3MTTrigger03.bActive)
		{
			building3M04Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M04Target1);
			building3M04Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M04Target2);
			building3M04Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M04Target3);
			building3MTTrigger03->DisableTrigger();
			StartTimer("Building3MT_Trigger03ABC_Reset",4);
		}
	}
	Function Building3MT_Trigger03ABC_Reset()
	{
		building3M04Target1.ResetTarget(true);
		building3M04Target2.ResetTarget(true);
		building3M04Target3.ResetTarget(true);
	}
	Function bool Building3MT_Trigger04B_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (door2Entered)
		{
			StartTimer("Building3MT_Trigger04B_Flip",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building3MTTrigger04);
		}
		return true;
	}
	Function Building3MT_Trigger04B_Flip()
	{
		if (building3MTTrigger04.bActive)
		{
			building3M05Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M05Target1);
			building3M05Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M05Target2);
			building3M06Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M06Target1);
			building3MTTrigger04->DisableTrigger();
			StartTimer("Building3MT_Trigger04B_Reset",4);
		}
	}
	Function Building3MT_Trigger04B_Reset()
	{
		building3M05Target1.ResetTarget(true);
		building3M05Target2.ResetTarget(true);
		building3M06Target1.ResetTarget(true);
	}
	Function bool Building3MT_Trigger05B_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (door2Entered)
		{
			StartTimer("Building3MT_Trigger05B_Flip",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building3MTTrigger05);
		}
		return true;
	}
	Function Building3MT_Trigger05B_Flip()
	{
		if (building3MTTrigger05.bActive)
		{
			building3M07Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M07Target1);
			building3M07Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M07Target2);
			building3M07Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M07Target3);
			building3M07Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M07Target4);
			building3M07Target5.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M07Target5);
			building3M07Target6.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M07Target6);
			building3M07Target7.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M07Target7);
			building3MTTrigger05->DisableTrigger();
			StartTimer("Building3MT_Trigger05B_Reset",4);
		}
	}
	Function Building3MT_Trigger05B_Reset()
	{
		building3M07Target1.ResetTarget(true);
		building3M07Target2.ResetTarget(true);
		building3M07Target3.ResetTarget(true);
		building3M07Target4.ResetTarget(true);
		building3M07Target5.ResetTarget(true);
		building3M07Target6.ResetTarget(true);
		building3M07Target7.ResetTarget(true);
	}
	Function bool Building3MT_Trigger06B_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (door1Entered)
		{
			StartTimer("Building3MT_Trigger06B_Flip",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building3MTTrigger06);
		}
		return true;
	}
	Function Building3MT_Trigger06B_Flip()
	{
		if (building3MTTrigger06.bActive)
		{
			building3M08Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M08Target1);
			building3M08Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M08Target2);
			building3M08Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M08Target3);
			building3M08Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M08Target4);
			building3M08Target5.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M08Target5);
			building3M08Target6.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M08Target6);
			building3M08Target7.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M08Target7);
			building3MTTrigger06->DisableTrigger();
			building3MTTrigger01->DisableTrigger();
			StartTimer("Building3MT_Trigger06B_Reset",4);
		}
	}
	Function Building3MT_Trigger06B_Reset()
	{
		building3M08Target1.ResetTarget(true);
		building3M08Target2.ResetTarget(true);
		building3M08Target3.ResetTarget(true);
		building3M08Target4.ResetTarget(true);
		building3M08Target5.ResetTarget(true);
		building3M08Target6.ResetTarget(true);
		building3M08Target7.ResetTarget(true);
	}
	Function bool Building3MT_Trigger07AB_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (door1Entered || door2Entered)
		{
			StartTimer("Building3MT_Trigger07AB_Flip",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building3MTTrigger07);
		}
		return true;
	}
	Function Building3MT_Trigger07AB_Flip()
	{
		if (building3MTTrigger07.bActive)
		{
			building3M09Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M09Target1);
			building3M10Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M10Target1);
			building3MTTrigger07->DisableTrigger();
			StartTimer("Building3MT_Trigger07AB_Reset",4);
		}
	}
	Function Building3MT_Trigger07AB_Reset()
	{
		building3M09Target1.ResetTarget(true);
		building3M10Target1.ResetTarget(true);
	}
	Function bool Building3MT_Trigger08AB_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (door1Entered || door2Entered)
		{
			StartTimer("door3Pause",(FMath::FRand() * TargetFlipModifier));
		}
		return true;
	}
	Function door3Flip()
	{
		if (! bbuilding3Door3Flipped)
		{
			building3M01Target1=MarksmanTarget(CaptureEvent("Building3Marker01Target01"));
			building3M01Target2=MarksmanTarget(CaptureEvent("Building3Marker01Target02"));
			building3M01Target3=MarksmanTarget(CaptureEvent("Building3Marker01Target03"));
			building3M01Target4=MarksmanTarget(CaptureEvent("Building3Marker01Target04"));
			building3M01Target5=MarksmanTarget(CaptureEvent("Building3Marker01Target05"));
			building3M02Target1=MarksmanTarget(CaptureEvent("Building3Marker02Target01"));
			building3M02Target2=MarksmanTarget(CaptureEvent("Building3Marker02Target02"));
			building3M02Target3=MarksmanTarget(CaptureEvent("Building3Marker02Target03"));
			building3M01Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M01Target1);
			building3M01Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M01Target2);
			building3M01Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M01Target3);
			building3M01Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M01Target4);
			building3M01Target5.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M01Target5);
			building3M02Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M02Target1);
			building3M02Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M02Target2);
			building3M02Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building3M02Target3);
			bbuilding3Door3Flipped=true;
			StartTimer("door3Reset",4);
		}
	}
	Function door3Reset()
	{
		building3M01Target1.ResetTarget(true);
		building3M01Target2.ResetTarget(true);
		building3M01Target3.ResetTarget(true);
		building3M01Target4.ResetTarget(true);
		building3M01Target5.ResetTarget(true);
		building3M02Target1.ResetTarget(true);
		building3M02Target2.ResetTarget(true);
		building3M02Target3.ResetTarget(true);
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "door3Pause":
			door3Flip();
			return true;
			case "door3Reset":
			door3Reset();
			return true;
			case "Building3MT_Trigger02ABC_Flip":
			Building3MT_Trigger02ABC_Flip();
			return true;
			case "Building3MT_Trigger02ABC_Reset":
			Building3MT_Trigger02ABC_Reset();
			return true;
			case "Building3MT_Trigger03ABC_Flip":
			Building3MT_Trigger03ABC_Flip();
			return true;
			case "Building3MT_Trigger03ABC_Reset":
			Building3MT_Trigger03ABC_Reset();
			return true;
			case "Building3MT_Trigger04B_Flip":
			Building3MT_Trigger04B_Flip();
			return true;
			case "Building3MT_Trigger04B_Reset":
			Building3MT_Trigger04B_Reset();
			return true;
			case "Building3MT_Trigger05B_Flip":
			Building3MT_Trigger05B_Flip();
			return true;
			case "Building3MT_Trigger05B_Reset":
			Building3MT_Trigger05B_Reset();
			return true;
			case "Building3MT_Trigger06B_Flip":
			Building3MT_Trigger06B_Flip();
			return true;
			case "Building3MT_Trigger06B_Reset":
			Building3MT_Trigger06B_Reset();
			return true;
			case "Building3MT_Trigger07AB_Flip":
			Building3MT_Trigger07AB_Flip();
			return true;
			case "Building3MT_Trigger07AB_Reset":
			Building3MT_Trigger07AB_Reset();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		building3M05Target1=MarksmanTarget(CaptureEvent("Building3Marker05Target01"));
		building3M05Target2=MarksmanTarget(CaptureEvent("Building3Marker05Target02"));
		building3M06Target1=MarksmanTarget(CaptureEvent("Building3Marker06Target01"));
		building3M07Target1=MarksmanTarget(CaptureEvent("Building3Marker07Target01"));
		building3M07Target2=MarksmanTarget(CaptureEvent("Building3Marker07Target02"));
		building3M07Target3=MarksmanTarget(CaptureEvent("Building3Marker07Target03"));
		building3M07Target4=MarksmanTarget(CaptureEvent("Building3Marker07Target04"));
		building3M07Target5=MarksmanTarget(CaptureEvent("Building3Marker07Target05"));
		building3M07Target6=MarksmanTarget(CaptureEvent("Building3Marker07Target06"));
		building3M07Target7=MarksmanTarget(CaptureEvent("Building3Marker07Target07"));
		building3M08Target1=MarksmanTarget(CaptureEvent("Building3Marker08Target01"));
		building3M08Target2=MarksmanTarget(CaptureEvent("Building3Marker08Target02"));
		building3M08Target3=MarksmanTarget(CaptureEvent("Building3Marker08Target03"));
		building3M08Target4=MarksmanTarget(CaptureEvent("Building3Marker08Target04"));
		building3M08Target5=MarksmanTarget(CaptureEvent("Building3Marker08Target05"));
		building3M08Target6=MarksmanTarget(CaptureEvent("Building3Marker08Target06"));
		building3M08Target7=MarksmanTarget(CaptureEvent("Building3Marker08Target07"));
		building3M09Target1=MarksmanTarget(CaptureEvent("Building3Marker09Target01"));
		building3M10Target1=MarksmanTarget(CaptureEvent("Building3Marker10Target01"));
		if (! building3MTTriggerCaptured)
		{
			building3MTTrigger01=TriggerVolume(CaptureEvent("Building3MT_Trigger03B"));
			building3MTTrigger02=TriggerVolume(CaptureEvent("Building3MT_Trigger02ABC"));
			building3MTTrigger03=TriggerVolume(CaptureEvent("Building3MT_Trigger03ABC"));
			building3MTTrigger04=TriggerVolume(CaptureEvent("Building3MT_Trigger04B"));
			building3MTTrigger05=TriggerVolume(CaptureEvent("Building3MT_Trigger05B"));
			building3MTTrigger06=TriggerVolume(CaptureEvent("Building3MT_Trigger06B"));
			building3MTTrigger07=TriggerVolume(CaptureEvent("Building3MT_Trigger07AB"));
			building3MTTrigger08=TriggerVolume(CaptureEvent("Building3MT_Trigger08AB"));
			building3MTTriggerCaptured=true;
		}
		if (door1Entered)
		{
			building3M05Target1.bHidden=true;
			building3M05Target2.bHidden=true;
			building3M06Target1.bHidden=true;
			building3M07Target1.bHidden=true;
			building3M07Target2.bHidden=true;
			building3M07Target3.bHidden=true;
			building3M07Target4.bHidden=true;
			building3M07Target5.bHidden=true;
			building3M07Target6.bHidden=true;
			building3M07Target7.bHidden=true;
			building3M08Target1.bHidden=false;
			building3M08Target2.bHidden=false;
			building3M08Target3.bHidden=false;
			building3M08Target4.bHidden=false;
			building3M08Target5.bHidden=false;
			building3M08Target6.bHidden=false;
			building3M08Target7.bHidden=false;
			building3M09Target1.bHidden=false;
			building3M10Target1.bHidden=false;
		}
		if (door2Entered)
		{
			building3M05Target1.bHidden=false;
			building3M05Target2.bHidden=false;
			building3M06Target1.bHidden=false;
			building3M07Target1.bHidden=false;
			building3M07Target2.bHidden=false;
			building3M07Target3.bHidden=false;
			building3M07Target4.bHidden=false;
			building3M07Target5.bHidden=false;
			building3M07Target6.bHidden=false;
			building3M07Target7.bHidden=false;
			building3M08Target1.bHidden=false;
			building3M08Target2.bHidden=false;
			building3M08Target3.bHidden=false;
			building3M08Target4.bHidden=false;
			building3M08Target5.bHidden=false;
			building3M08Target6.bHidden=false;
			building3M08Target7.bHidden=false;
			building3M09Target1.bHidden=false;
			building3M10Target1.bHidden=false;
		}
		if (door3Entered && (! bAllMTTriggersDisabled))
		{
			StartTimer("door3Pause",preTimerPause);
			building3M05Target1.bHidden=true;
			building3M05Target2.bHidden=true;
			building3M06Target1.bHidden=true;
			building3M07Target1.bHidden=true;
			building3M07Target2.bHidden=true;
			building3M07Target3.bHidden=true;
			building3M07Target4.bHidden=true;
			building3M07Target5.bHidden=true;
			building3M07Target6.bHidden=true;
			building3M07Target7.bHidden=true;
			building3M08Target1.bHidden=true;
			building3M08Target2.bHidden=true;
			building3M08Target3.bHidden=true;
			building3M08Target4.bHidden=true;
			building3M08Target5.bHidden=true;
			building3M08Target6.bHidden=true;
			building3M08Target7.bHidden=true;
			building3M09Target1.bHidden=true;
			building3M10Target1.bHidden=true;
		}
	}
}
*/

/*
State Building3InActive extends Building3Active
{
	Function BeginState()
	{
		door1Entered=false;
		door2Entered=false;
		door3Entered=false;
		building3M01Target1.ResetTarget(true);
		UnCaptureEvent(building3M01Target1);
		building3M01Target2.ResetTarget(true);
		UnCaptureEvent(building3M01Target2);
		building3M01Target3.ResetTarget(true);
		UnCaptureEvent(building3M01Target3);
		building3M01Target4.ResetTarget(true);
		UnCaptureEvent(building3M01Target4);
		building3M01Target5.ResetTarget(true);
		UnCaptureEvent(building3M01Target5);
		building3M02Target1.ResetTarget(true);
		UnCaptureEvent(building3M02Target1);
		building3M02Target2.ResetTarget(true);
		UnCaptureEvent(building3M02Target2);
		building3M02Target3.ResetTarget(true);
		UnCaptureEvent(building3M02Target3);
		building3M03Target1.ResetTarget(true);
		UnCaptureEvent(building3M03Target1);
		building3M03Target2.ResetTarget(true);
		UnCaptureEvent(building3M03Target2);
		building3M03Target3.ResetTarget(true);
		UnCaptureEvent(building3M03Target3);
		building3M03Target4.ResetTarget(true);
		UnCaptureEvent(building3M03Target4);
		building3M03Target5.ResetTarget(true);
		UnCaptureEvent(building3M03Target5);
		building3M04Target1.ResetTarget(true);
		UnCaptureEvent(building3M04Target1);
		building3M04Target2.ResetTarget(true);
		UnCaptureEvent(building3M04Target2);
		building3M04Target3.ResetTarget(true);
		UnCaptureEvent(building3M04Target3);
		building3M05Target1.ResetTarget(true);
		UnCaptureEvent(building3M05Target1);
		building3M05Target2.ResetTarget(true);
		UnCaptureEvent(building3M05Target2);
		building3M06Target1.ResetTarget(true);
		UnCaptureEvent(building3M06Target1);
		building3M07Target1.ResetTarget(true);
		UnCaptureEvent(building3M07Target1);
		building3M07Target2.ResetTarget(true);
		UnCaptureEvent(building3M07Target2);
		building3M07Target3.ResetTarget(true);
		UnCaptureEvent(building3M07Target3);
		building3M07Target4.ResetTarget(true);
		UnCaptureEvent(building3M07Target4);
		building3M07Target5.ResetTarget(true);
		UnCaptureEvent(building3M07Target5);
		building3M07Target6.ResetTarget(true);
		UnCaptureEvent(building3M07Target6);
		building3M07Target7.ResetTarget(true);
		UnCaptureEvent(building3M07Target7);
		building3M08Target1.ResetTarget(true);
		UnCaptureEvent(building3M08Target1);
		building3M08Target2.ResetTarget(true);
		UnCaptureEvent(building3M08Target2);
		building3M08Target3.ResetTarget(true);
		UnCaptureEvent(building3M08Target3);
		building3M08Target4.ResetTarget(true);
		UnCaptureEvent(building3M08Target4);
		building3M08Target5.ResetTarget(true);
		UnCaptureEvent(building3M08Target5);
		building3M08Target6.ResetTarget(true);
		UnCaptureEvent(building3M08Target6);
		building3M08Target7.ResetTarget(true);
		UnCaptureEvent(building3M08Target7);
		building3M09Target1.ResetTarget(true);
		UnCaptureEvent(building3M09Target1);
		building3M10Target1.ResetTarget(true);
		UnCaptureEvent(building3M10Target1);
		ChangeState("NoBuildingActive");
	}
}
*/

/*
State Building4Active
{
	Function bool Building4MT_Trigger02AB_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		building4M02Target1=MarksmanTarget(CaptureEvent("Building4Marker02Target01"));
		building4M02Target2=MarksmanTarget(CaptureEvent("Building4Marker02Target02"));
		building4M02Target3=MarksmanTarget(CaptureEvent("Building4Marker02Target03"));
		building4M02Target4=MarksmanTarget(CaptureEvent("Building4Marker02Target04"));
		building4M02Target5=MarksmanTarget(CaptureEvent("Building4Marker02Target05"));
		StartTimer("Building4MT_Trigger02AB_Flip",(FMath::FRand() * TargetFlipModifier));
		UnCaptureEvent(building4MTTrigger02);
		return true;
	}
	Function Building4MT_Trigger02AB_Flip()
	{
		if (building4MTTrigger02.bActive)
		{
			building4M02Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building4M02Target1);
			building4M02Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building4M02Target2);
			building4M02Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building4M02Target3);
			building4M02Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building4M02Target4);
			building4M02Target5.TriggerSelf();
			PlayGameSound("m_hydraulic",building4M02Target5);
			building4MTTrigger02->DisableTrigger();
			StartTimer("Building4MT_Trigger02AB_Reset",4);
		}
	}
	Function Building4MT_Trigger02AB_Reset()
	{
		building4M02Target1.ResetTarget(true);
		building4M02Target2.ResetTarget(true);
		building4M02Target3.ResetTarget(true);
		building4M02Target4.ResetTarget(true);
		building4M02Target5.ResetTarget(true);
	}
	Function bool Building4MT_Trigger03AB_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		building4M03Target1=MarksmanTarget(CaptureEvent("Building4Marker03Target01"));
		building4M03Target2=MarksmanTarget(CaptureEvent("Building4Marker03Target02"));
		building4M03Target3=MarksmanTarget(CaptureEvent("Building4Marker03Target03"));
		building4M03Target4=MarksmanTarget(CaptureEvent("Building4Marker03Target04"));
		StartTimer("Building4MT_Trigger03AB_Flip",(FMath::FRand() * TargetFlipModifier));
		UnCaptureEvent(building4MTTrigger03);
		return true;
	}
	Function Building4MT_Trigger03AB_Flip()
	{
		if (building4MTTrigger03.bActive)
		{
			building4M03Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building4M03Target1);
			building4M03Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building4M03Target2);
			building4M03Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building4M03Target3);
			building4M03Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building4M03Target4);
			building4MTTrigger03->DisableTrigger();
			StartTimer("Building4MT_Trigger03AB_Reset",4);
		}
	}
	Function Building4MT_Trigger03AB_Reset()
	{
		building4M03Target1.ResetTarget(true);
		building4M03Target2.ResetTarget(true);
		building4M03Target3.ResetTarget(true);
		building4M03Target4.ResetTarget(true);
	}
	Function bool Building4MT_Trigger04AB_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		building4M04Target1=MarksmanTarget(CaptureEvent("Building4Marker04Target01"));
		building4M04Target2=MarksmanTarget(CaptureEvent("Building4Marker04Target02"));
		building4M04Target3=MarksmanTarget(CaptureEvent("Building4Marker04Target03"));
		building4M04Target4=MarksmanTarget(CaptureEvent("Building4Marker04Target04"));
		building4M04Target5=MarksmanTarget(CaptureEvent("Building4Marker04Target05"));
		StartTimer("Building4MT_Trigger04AB_Flip",(FMath::FRand() * TargetFlipModifier));
		UnCaptureEvent(building4MTTrigger04);
		return true;
	}
	Function Building4MT_Trigger04AB_Flip()
	{
		if (building4MTTrigger04.bActive)
		{
			building4M04Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building4M04Target1);
			building4M04Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building4M04Target2);
			building4M04Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building4M04Target3);
			building4M04Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building4M04Target4);
			building4M04Target5.TriggerSelf();
			PlayGameSound("m_hydraulic",building4M04Target5);
			building4MTTrigger04->DisableTrigger();
			StartTimer("Building4MT_Trigger04AB_Reset",4);
		}
	}
	Function Building4MT_Trigger04AB_Reset()
	{
		building4M04Target1.ResetTarget(true);
		building4M04Target2.ResetTarget(true);
		building4M04Target3.ResetTarget(true);
		building4M04Target4.ResetTarget(true);
		building4M04Target5.ResetTarget(true);
	}
	Function doorTriggerFlip()
	{
		if (! bbuilding4DoorFlipped)
		{
			building4M01Target1=MarksmanTarget(CaptureEvent("Building4Marker01Target01"));
			building4M01Target2=MarksmanTarget(CaptureEvent("Building4Marker01Target02"));
			building4M01Target3=MarksmanTarget(CaptureEvent("Building4Marker01Target03"));
			building4M01Target4=MarksmanTarget(CaptureEvent("Building4Marker01Target04"));
			building4M01Target5=MarksmanTarget(CaptureEvent("Building4Marker01Target05"));
			building4M01Target6=MarksmanTarget(CaptureEvent("Building4Marker01Target06"));
			building4M01Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building4M01Target1);
			building4M01Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building4M01Target2);
			building4M01Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building4M01Target3);
			building4M01Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building4M01Target4);
			building4M01Target5.TriggerSelf();
			PlayGameSound("m_hydraulic",building4M01Target5);
			building4M01Target6.TriggerSelf();
			PlayGameSound("m_hydraulic",building4M01Target6);
			bbuilding4DoorFlipped=true;
			StartTimer("doorTriggerReset",4);
		}
	}
	Function doorTriggerReset()
	{
		building4M01Target1.ResetTarget(true);
		building4M01Target2.ResetTarget(true);
		building4M01Target3.ResetTarget(true);
		building4M01Target4.ResetTarget(true);
		building4M01Target5.ResetTarget(true);
		building4M01Target6.ResetTarget(true);
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "doorTriggerFlip":
			doorTriggerFlip();
			return true;
			case "doorTriggerReset":
			doorTriggerReset();
			return true;
			case "Building4MT_Trigger02AB_Flip":
			Building4MT_Trigger02AB_Flip();
			return true;
			case "Building4MT_Trigger02AB_Reset":
			Building4MT_Trigger02AB_Reset();
			return true;
			case "Building4MT_Trigger03AB_Flip":
			Building4MT_Trigger03AB_Flip();
			return true;
			case "Building4MT_Trigger03AB_Reset":
			Building4MT_Trigger03AB_Reset();
			return true;
			case "Building4MT_Trigger04AB_Flip":
			Building4MT_Trigger04AB_Flip();
			return true;
			case "Building4MT_Trigger04AB_Reset":
			Building4MT_Trigger04AB_Reset();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		if (! building4MTTriggerCaptured)
		{
			building4MTTrigger02=TriggerVolume(CaptureEvent("Building4MT_Trigger02AB"));
			building4MTTrigger03=TriggerVolume(CaptureEvent("Building4MT_Trigger03AB"));
			building4MTTrigger04=TriggerVolume(CaptureEvent("Building4MT_Trigger04AB"));
			building4MTTriggerCaptured=true;
		}
		if (! bAllMTTriggersDisabled)
		{
			StartTimer("doorTriggerFlip",preTimerPause);
		}
	}
}
*/

/*
State Building4InActive extends Building4Active
{
	Function BeginState()
	{
		building4M01Target1.ResetTarget(true);
		UnCaptureEvent(building4M01Target1);
		building4M01Target2.ResetTarget(true);
		UnCaptureEvent(building4M01Target2);
		building4M01Target3.ResetTarget(true);
		UnCaptureEvent(building4M01Target3);
		building4M01Target4.ResetTarget(true);
		UnCaptureEvent(building4M01Target4);
		building4M01Target5.ResetTarget(true);
		UnCaptureEvent(building4M01Target5);
		building4M01Target6.ResetTarget(true);
		UnCaptureEvent(building4M01Target6);
		building4M02Target1.ResetTarget(true);
		UnCaptureEvent(building4M02Target1);
		building4M02Target2.ResetTarget(true);
		UnCaptureEvent(building4M02Target2);
		building4M02Target3.ResetTarget(true);
		UnCaptureEvent(building4M02Target3);
		building4M02Target4.ResetTarget(true);
		UnCaptureEvent(building4M02Target4);
		building4M02Target5.ResetTarget(true);
		UnCaptureEvent(building4M02Target5);
		building4M03Target1.ResetTarget(true);
		UnCaptureEvent(building4M03Target1);
		building4M03Target2.ResetTarget(true);
		UnCaptureEvent(building4M03Target2);
		building4M03Target3.ResetTarget(true);
		UnCaptureEvent(building4M03Target3);
		building4M03Target4.ResetTarget(true);
		UnCaptureEvent(building4M03Target4);
		building4M04Target1.ResetTarget(true);
		UnCaptureEvent(building4M04Target1);
		building4M04Target2.ResetTarget(true);
		UnCaptureEvent(building4M04Target2);
		building4M04Target3.ResetTarget(true);
		UnCaptureEvent(building4M04Target3);
		building4M04Target4.ResetTarget(true);
		UnCaptureEvent(building4M04Target4);
		building4M04Target5.ResetTarget(true);
		UnCaptureEvent(building4M04Target5);
		ChangeState("NoBuildingActive");
	}
}
*/

/*
State Building5Active
{
	Function bool Building5MT_Trigger01A_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		StartTimer("Building5MT_Trigger01A_Flip",(FMath::FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger01);
		return true;
	}
	Function Building5MT_Trigger01A_Flip()
	{
		if (building5MTTrigger01.bActive)
		{
			building5M01Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M01Target1);
			building5M01Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M01Target2);
			building5MTTrigger01->DisableTrigger();
			StartTimer("Building5MT_Trigger01A_Reset",4);
		}
	}
	Function Building5MT_Trigger01A_Reset()
	{
		building5M01Target1.ResetTarget(true);
		building5M01Target2.ResetTarget(true);
	}
	Function bool Building5MT_Trigger02ABC_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (! door1Entered)
		{
			StartTimer("Building5MT_Trigger02ABC_Flip",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building5MTTrigger02);
		}
		return true;
	}
	Function Building5MT_Trigger02ABC_Flip()
	{
		if (building5MTTrigger02.bActive)
		{
			building5M02Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M02Target1);
			building5M02Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M02Target2);
			building5M02Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M02Target3);
			building5M02Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M02Target4);
			building5M02Target5.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M02Target5);
			building5M02Target6.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M02Target6);
			building5MTTrigger02->DisableTrigger();
			StartTimer("Building5MT_Trigger02ABC_Reset",4);
		}
	}
	Function Building5MT_Trigger02ABC_Reset()
	{
		building5M02Target1.ResetTarget(true);
		building5M02Target2.ResetTarget(true);
		building5M02Target3.ResetTarget(true);
		building5M02Target4.ResetTarget(true);
		building5M02Target5.ResetTarget(true);
		building5M02Target6.ResetTarget(true);
	}
	Function bool Building5MT_Trigger03ABC_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (! door1Entered)
		{
			StartTimer("Building5MT_Trigger03ABC_Flip",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building5MTTrigger03);
		}
		return true;
	}
	Function Building5MT_Trigger03ABC_Flip()
	{
		if (building5MTTrigger03.bActive)
		{
			building5M03Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M03Target1);
			building5M03Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M03Target2);
			building5M03Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M03Target3);
			building5M03Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M03Target4);
			building5M03Target5.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M03Target5);
			building5M03Target6.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M03Target6);
			building5MTTrigger03->DisableTrigger();
			StartTimer("Building5MT_Trigger03ABC_Reset",4);
		}
	}
	Function Building5MT_Trigger03ABC_Reset()
	{
		building5M03Target1.ResetTarget(true);
		building5M03Target2.ResetTarget(true);
		building5M03Target3.ResetTarget(true);
		building5M03Target4.ResetTarget(true);
		building5M03Target5.ResetTarget(true);
		building5M03Target6.ResetTarget(true);
	}
	Function bool Building5MT_Trigger04ABC_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (! door1Entered)
		{
			StartTimer("Building5MT_Trigger04ABC_Flip",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building5MTTrigger04);
		}
		return true;
	}
	Function Building5MT_Trigger04ABC_Flip()
	{
		if (building5MTTrigger04.bActive)
		{
			building5M04Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M04Target1);
			building5M04Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M04Target2);
			building5M04Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M04Target3);
			building5M04Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M04Target4);
			building5MTTrigger04->DisableTrigger();
			StartTimer("Building5MT_Trigger04ABC_Reset",4);
		}
	}
	Function Building5MT_Trigger04ABC_Reset()
	{
		building5M04Target1.ResetTarget(true);
		building5M04Target2.ResetTarget(true);
		building5M04Target3.ResetTarget(true);
		building5M04Target4.ResetTarget(true);
	}
	Function bool Building5MT_Trigger05ABC_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (! door1Entered)
		{
			StartTimer("Building5MT_Trigger05ABC_Flip",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building5MTTrigger05);
		}
		return true;
	}
	Function Building5MT_Trigger05ABC_Flip()
	{
		if (building5MTTrigger05.bActive)
		{
			building5M05Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M05Target1);
			building5M05Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M05Target2);
			building5M05Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M05Target3);
			building5M05Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M05Target4);
			building5M05Target5.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M05Target5);
			building5M05Target6.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M05Target6);
			building5M05Target7.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M05Target7);
			building5MTTrigger05->DisableTrigger();
			StartTimer("Building5MT_Trigger05ABC_Reset",4);
		}
	}
	Function Building5MT_Trigger05ABC_Reset()
	{
		building5M05Target1.ResetTarget(true);
		building5M05Target2.ResetTarget(true);
		building5M05Target3.ResetTarget(true);
		building5M05Target4.ResetTarget(true);
		building5M05Target5.ResetTarget(true);
		building5M05Target6.ResetTarget(true);
		building5M05Target7.ResetTarget(true);
	}
	Function bool Building5MT_Trigger06ABC_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (! door1Entered)
		{
			StartTimer("Building5MT_Trigger06ABC_Flip",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building5MTTrigger06);
		}
		return true;
	}
	Function Building5MT_Trigger06ABC_Flip()
	{
		if (building5MTTrigger06.bActive)
		{
			building5M06Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M06Target1);
			building5M06Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M06Target2);
			building5M06Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M06Target3);
			building5M06Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M06Target4);
			building5M06Target5.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M06Target5);
			building5MTTrigger06->DisableTrigger();
			StartTimer("Building5MT_Trigger06ABC_Reset",4);
		}
	}
	Function Building5MT_Trigger06ABC_Reset()
	{
		building5M06Target1.ResetTarget(true);
		building5M06Target2.ResetTarget(true);
		building5M06Target3.ResetTarget(true);
		building5M06Target4.ResetTarget(true);
		building5M06Target5.ResetTarget(true);
	}
	Function bool Building5MT_Trigger07ABC_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (! door1Entered)
		{
			StartTimer("Building5MT_Trigger07ABC_Flip",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building5MTTrigger07);
		}
		return true;
	}
	Function Building5MT_Trigger07ABC_Flip()
	{
		if (building5MTTrigger07.bActive)
		{
			building5M07Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M07Target1);
			building5M07Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M07Target2);
			building5M07Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M07Target3);
			building5M07Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M07Target4);
			building5MTTrigger07->DisableTrigger();
			StartTimer("Building5MT_Trigger07ABC_Reset",4);
		}
	}
	Function Building5MT_Trigger07ABC_Reset()
	{
		building5M07Target1.ResetTarget(true);
		building5M07Target2.ResetTarget(true);
		building5M07Target3.ResetTarget(true);
		building5M07Target4.ResetTarget(true);
	}
	Function bool Building5MT_Trigger08ABC_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (! door1Entered)
		{
			StartTimer("Building5MT_Trigger08ABC_Flip",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building5MTTrigger08);
		}
		return true;
	}
	Function Building5MT_Trigger08ABC_Flip()
	{
		if (building5MTTrigger08.bActive)
		{
			building5M08Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M08Target1);
			building5M08Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M08Target2);
			building5M08Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M08Target3);
			building5MTTrigger08->DisableTrigger();
			StartTimer("Building5MT_Trigger08ABC_Reset",4);
		}
	}
	Function Building5MT_Trigger08ABC_Reset()
	{
		building5M08Target1.ResetTarget(true);
		building5M08Target2.ResetTarget(true);
		building5M08Target3.ResetTarget(true);
	}
	Function bool Building5MT_Trigger09ABC_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (! door1Entered)
		{
			StartTimer("Building5MT_Trigger09ABC_Flip",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building5MTTrigger09);
		}
		return true;
	}
	Function Building5MT_Trigger09ABC_Flip()
	{
		if (building5MTTrigger09.bActive)
		{
			building5M09Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M09Target1);
			building5M09Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M09Target2);
			building5M09Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M09Target3);
			building5MTTrigger09->DisableTrigger();
			StartTimer("Building5MT_Trigger09ABC_Reset",4);
		}
	}
	Function Building5MT_Trigger09ABC_Reset()
	{
		building5M09Target1.ResetTarget(true);
		building5M09Target2.ResetTarget(true);
		building5M09Target3.ResetTarget(true);
	}
	Function bool Building5MT_Trigger10ABC_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (! door1Entered)
		{
			StartTimer("Building5MT_Trigger10ABC_Flip",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building5MTTrigger10);
		}
		return true;
	}
	Function Building5MT_Trigger10ABC_Flip()
	{
		if (building5MTTrigger10.bActive)
		{
			building5M10Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M10Target1);
			building5M10Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M10Target2);
			building5M10Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M10Target3);
			building5M10Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M10Target4);
			building5MTTrigger10->DisableTrigger();
			StartTimer("Building5MT_Trigger10ABC_Reset",4);
		}
	}
	Function Building5MT_Trigger10ABC_Reset()
	{
		building5M10Target1.ResetTarget(true);
		building5M10Target2.ResetTarget(true);
		building5M10Target3.ResetTarget(true);
		building5M10Target4.ResetTarget(true);
	}
	Function bool Building5MT_Trigger11ABC_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (! door1Entered)
		{
			if (building5MTTrigger11.bActive)
			{
				building5M11Target1=MarksmanTarget(CaptureEvent("building5Marker11Target01"));
				building5M11Target2=MarksmanTarget(CaptureEvent("building5Marker11Target02"));
				building5M11Target3=MarksmanTarget(CaptureEvent("building5Marker11Target03"));
				StartTimer("Building5MT_Trigger12ABCD_Flip",(FMath::FRand() * TargetFlipModifier));
			}
		}
		return true;
	}
	Function bool Building5MT_Trigger12ABCD_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (door1Entered)
		{
			StartTimer("Building5MT_Trigger12ABCD_Flip",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building5MTTrigger12);
		}
		return true;
	}
	Function Building5MT_Trigger12ABCD_Flip()
	{
		if (building5MTTrigger12.bActive)
		{
			building5M11Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M11Target1);
			building5M11Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M11Target2);
			building5M11Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M11Target3);
			UnCaptureEvent(building5MTTrigger11);
			building5MTTrigger11->DisableTrigger();
			building5MTTrigger12->DisableTrigger();
			StartTimer("Building5MT_Trigger12ABCD_Reset",4);
		}
	}
	Function Building5MT_Trigger12ABCD_Reset()
	{
		building5M11Target1.ResetTarget(true);
		building5M11Target2.ResetTarget(true);
		building5M11Target3.ResetTarget(true);
	}
	Function bool Building5MT_Trigger13ABCD_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		StartTimer("Building5MT_Trigger13ABCD_Flip",(FMath::FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger13);
		return true;
	}
	Function Building5MT_Trigger13ABCD_Flip()
	{
		if (building5MTTrigger13.bActive)
		{
			building5M12Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M12Target1);
			building5M12Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M12Target2);
			building5MTTrigger13->DisableTrigger();
			StartTimer("Building5MT_Trigger13ABCD_Reset",4);
		}
	}
	Function Building5MT_Trigger13ABCD_Reset()
	{
		building5M12Target1.ResetTarget(true);
		building5M12Target2.ResetTarget(true);
	}
	Function bool Building5MT_Trigger14ABCD_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		StartTimer("Building5MT_Trigger14ABCD_Flip",(FMath::FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger14);
		return true;
	}
	Function Building5MT_Trigger14ABCD_Flip()
	{
		if (building5MTTrigger14.bActive)
		{
			building5M13Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M13Target1);
			building5M13Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M13Target2);
			building5M13Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M13Target3);
			building5M13Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M13Target4);
			building5MTTrigger14->DisableTrigger();
			StartTimer("Building5MT_Trigger14ABCD_Reset",4);
		}
	}
	Function Building5MT_Trigger14ABCD_Reset()
	{
		building5M13Target1.ResetTarget(true);
		building5M13Target2.ResetTarget(true);
		building5M13Target3.ResetTarget(true);
		building5M13Target4.ResetTarget(true);
	}
	Function bool Building5MT_Trigger15ABCD_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		StartTimer("Building5MT_Trigger15ABCD_Flip",(FMath::FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger15);
		return true;
	}
	Function Building5MT_Trigger15ABCD_Flip()
	{
		if (building5MTTrigger15.bActive)
		{
			building5M14Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M14Target1);
			building5M14Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M14Target2);
			building5M14Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M14Target3);
			building5M14Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M14Target4);
			building5M14Target5.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M14Target5);
			building5M14Target6.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M14Target6);
			building5M14Target7.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M14Target7);
			building5M14Target8.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M14Target8);
			building5MTTrigger15->DisableTrigger();
			StartTimer("Building5MT_Trigger15ABCD_Reset",4);
		}
	}
	Function Building5MT_Trigger15ABCD_Reset()
	{
		building5M14Target1.ResetTarget(true);
		building5M14Target2.ResetTarget(true);
		building5M14Target3.ResetTarget(true);
		building5M14Target4.ResetTarget(true);
		building5M14Target5.ResetTarget(true);
		building5M14Target6.ResetTarget(true);
		building5M14Target7.ResetTarget(true);
		building5M14Target8.ResetTarget(true);
	}
	Function bool Building5MT_Trigger16ABCD_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		StartTimer("Building5MT_Trigger16ABCD_Flip",(FMath::FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger16);
		return true;
	}
	Function Building5MT_Trigger16ABCD_Flip()
	{
		if (building5MTTrigger16.bActive)
		{
			building5M15Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M15Target1);
			building5M15Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M15Target2);
			building5M15Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M15Target3);
			building5M15Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M15Target4);
			building5M15Target5.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M15Target5);
			building5MTTrigger16->DisableTrigger();
			StartTimer("Building5MT_Trigger16ABCD_Reset",4);
		}
	}
	Function Building5MT_Trigger16ABCD_Reset()
	{
		building5M15Target1.ResetTarget(true);
		building5M15Target2.ResetTarget(true);
		building5M15Target3.ResetTarget(true);
		building5M15Target4.ResetTarget(true);
		building5M15Target5.ResetTarget(true);
	}
	Function bool Building5MT_Trigger17ABCD_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		StartTimer("Building5MT_Trigger17ABCD_Flip",(FMath::FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger17);
		return true;
	}
	Function Building5MT_Trigger17ABCD_Flip()
	{
		if (building5MTTrigger17.bActive)
		{
			building5M16Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M16Target1);
			building5M16Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M16Target2);
			building5M16Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M16Target3);
			building5M16Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M16Target4);
			building5M16Target5.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M16Target5);
			building5M16Target6.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M16Target6);
			building5MTTrigger17->DisableTrigger();
			StartTimer("Building5MT_Trigger17ABCD_Reset",4);
		}
	}
	Function Building5MT_Trigger17ABCD_Reset()
	{
		building5M16Target1.ResetTarget(true);
		building5M16Target2.ResetTarget(true);
		building5M16Target3.ResetTarget(true);
		building5M16Target4.ResetTarget(true);
		building5M16Target5.ResetTarget(true);
		building5M16Target6.ResetTarget(true);
	}
	Function bool Building5MT_Trigger18ABCD_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		StartTimer("Building5MT_Trigger18ABCD_Flip",(FMath::FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger18);
		return true;
	}
	Function Building5MT_Trigger18ABCD_Flip()
	{
		if (building5MTTrigger18.bActive)
		{
			building5M17Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M17Target1);
			building5M17Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M17Target2);
			building5MTTrigger18->DisableTrigger();
			StartTimer("Building5MT_Trigger18ABCD_Reset",4);
		}
	}
	Function Building5MT_Trigger18ABCD_Reset()
	{
		building5M17Target1.ResetTarget(true);
		building5M17Target2.ResetTarget(true);
	}
	Function bool Building5MT_Trigger19ABCD_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		StartTimer("Building5MT_Trigger19ABCD_Flip",(FMath::FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger19);
		return true;
	}
	Function Building5MT_Trigger19ABCD_Flip()
	{
		if (building5MTTrigger19.bActive)
		{
			building5M18Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M18Target1);
			building5M18Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M18Target2);
			building5M18Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M18Target3);
			building5M18Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M18Target4);
			building5M18Target5.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M18Target5);
			building5MTTrigger19->DisableTrigger();
			StartTimer("Building5MT_Trigger19ABCD_Reset",4);
		}
	}
	Function Building5MT_Trigger19ABCD_Reset()
	{
		building5M18Target1.ResetTarget(true);
		building5M18Target2.ResetTarget(true);
		building5M18Target3.ResetTarget(true);
		building5M18Target4.ResetTarget(true);
		building5M18Target5.ResetTarget(true);
	}
	Function bool Building5MT_Trigger20ABCD_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		StartTimer("Building5MT_Trigger20ABCD_Flip",(FMath::FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger20);
		return true;
	}
	Function Building5MT_Trigger20ABCD_Flip()
	{
		if (building5MTTrigger20.bActive)
		{
			building5M19Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M19Target1);
			building5M19Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M19Target2);
			building5M19Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M19Target3);
			building5MTTrigger20->DisableTrigger();
			StartTimer("Building5MT_Trigger20ABCD_Reset",4);
		}
	}
	Function Building5MT_Trigger20ABCD_Reset()
	{
		building5M19Target1.ResetTarget(true);
		building5M19Target2.ResetTarget(true);
		building5M19Target3.ResetTarget(true);
	}
	Function bool Building5MT_Trigger21ABCD_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		StartTimer("Building5MT_Trigger21ABCD_Flip",(FMath::FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger21);
		return true;
	}
	Function Building5MT_Trigger21ABCD_Flip()
	{
		if (building5MTTrigger21.bActive)
		{
			building5M20Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M20Target1);
			building5M20Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M20Target2);
			building5M20Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M20Target3);
			building5MTTrigger21->DisableTrigger();
			StartTimer("Building5MT_Trigger21ABCD_Reset",4);
		}
	}
	Function Building5MT_Trigger21ABCD_Reset()
	{
		building5M20Target1.ResetTarget(true);
		building5M20Target2.ResetTarget(true);
		building5M20Target3.ResetTarget(true);
	}
	Function bool Building5MT_Trigger22ABCD_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		StartTimer("Building5MT_Trigger22ABCD_Flip",(FMath::FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger22);
		return true;
	}
	Function Building5MT_Trigger22ABCD_Flip()
	{
		if (building5MTTrigger22.bActive)
		{
			building5M21Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M21Target1);
			building5M21Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M21Target2);
			building5M21Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M21Target3);
			building5MTTrigger22->DisableTrigger();
			StartTimer("Building5MT_Trigger22ABCD_Reset",4);
		}
	}
	Function Building5MT_Trigger22ABCD_Reset()
	{
		building5M21Target1.ResetTarget(true);
		building5M21Target2.ResetTarget(true);
		building5M21Target3.ResetTarget(true);
	}
	Function bool Building5MT_Trigger23ABCD_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		StartTimer("Building5MT_Trigger23ABCD_Flip",(FMath::FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger23);
		return true;
	}
	Function Building5MT_Trigger23ABCD_Flip()
	{
		if (building5MTTrigger23.bActive)
		{
			building5M22Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M22Target1);
			building5M22Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M22Target2);
			building5M22Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M22Target3);
			building5MTTrigger23->DisableTrigger();
			StartTimer("Building5MT_Trigger23ABCD_Reset",4);
		}
	}
	Function Building5MT_Trigger23ABCD_Reset()
	{
		building5M22Target1.ResetTarget(true);
		building5M22Target2.ResetTarget(true);
		building5M22Target3.ResetTarget(true);
	}
	Function bool Building5MT_Trigger24ABCD_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		StartTimer("Building5MT_Trigger24ABCD_Flip",(FMath::FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger24);
		return true;
	}
	Function Building5MT_Trigger24ABCD_Flip()
	{
		if (building5MTTrigger24.bActive)
		{
			building5M23Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M23Target1);
			building5M23Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M23Target2);
			building5M23Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M23Target3);
			building5M23Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M23Target4);
			building5M23Target5.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M23Target5);
			building5MTTrigger24->DisableTrigger();
			StartTimer("Building5MT_Trigger24ABCD_Reset",4);
		}
	}
	Function Building5MT_Trigger24ABCD_Reset()
	{
		building5M23Target1.ResetTarget(true);
		building5M23Target2.ResetTarget(true);
		building5M23Target3.ResetTarget(true);
		building5M23Target4.ResetTarget(true);
		building5M23Target5.ResetTarget(true);
	}
	Function bool Building5MT_Trigger25ABCD_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		StartTimer("Building5MT_Trigger25ABCD_Flip",(FMath::FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger25);
		return true;
	}
	Function Building5MT_Trigger25ABCD_Flip()
	{
		if (building5MTTrigger25.bActive)
		{
			building5M24Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M24Target1);
			building5M24Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M24Target2);
			building5M24Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M24Target3);
			building5MTTrigger25->DisableTrigger();
			StartTimer("Building5MT_Trigger25ABCD_Reset",4);
		}
	}
	Function Building5MT_Trigger25ABCD_Reset()
	{
		building5M24Target1.ResetTarget(true);
		building5M24Target2.ResetTarget(true);
		building5M24Target3.ResetTarget(true);
	}
	Function bool Building5MT_Trigger26ABCD_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		StartTimer("Building5MT_Trigger26ABCD_Flip",(FMath::FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger26);
		return true;
	}
	Function Building5MT_Trigger26ABCD_Flip()
	{
		if (building5MTTrigger26.bActive)
		{
			building5M25Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M25Target1);
			building5M25Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M25Target2);
			building5M25Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M25Target3);
			building5MTTrigger26->DisableTrigger();
			StartTimer("Building5MT_Trigger26ABCD_Reset",4);
		}
	}
	Function Building5MT_Trigger26ABCD_Reset()
	{
		building5M25Target1.ResetTarget(true);
		building5M25Target2.ResetTarget(true);
		building5M25Target3.ResetTarget(true);
	}
	Function bool Building5MT_Trigger27ABCD_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		StartTimer("Building5MT_Trigger27ABCD_Flip",(FMath::FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger27);
		return true;
	}
	Function Building5MT_Trigger27ABCD_Flip()
	{
		if (building5MTTrigger27.bActive)
		{
			building5M26Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M26Target1);
			building5M26Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M26Target2);
			building5M26Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M26Target3);
			building5MTTrigger27->DisableTrigger();
			StartTimer("Building5MT_Trigger27ABCD_Reset",4);
		}
	}
	Function Building5MT_Trigger27ABCD_Reset()
	{
		building5M26Target1.ResetTarget(true);
		building5M26Target2.ResetTarget(true);
		building5M26Target3.ResetTarget(true);
	}
	Function bool Building5MT_Trigger28ABCD_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		StartTimer("Building5MT_Trigger28ABCD_Flip",(FMath::FRand() * TargetFlipModifier));
		UnCaptureEvent(building5MTTrigger28);
		return true;
	}
	Function Building5MT_Trigger28ABCD_Flip()
	{
		if (building5MTTrigger28.bActive)
		{
			building5M27Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M27Target1);
			building5M27Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M27Target2);
			building5M27Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building5M27Target3);
			building5MTTrigger28->DisableTrigger();
			StartTimer("Building5MT_Trigger28ABCD_Reset",4);
		}
	}
	Function Building5MT_Trigger28ABCD_Reset()
	{
		building5M27Target1.ResetTarget(true);
		building5M27Target2.ResetTarget(true);
		building5M27Target3.ResetTarget(true);
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "Building5MT_Trigger01A_Flip":
			Building5MT_Trigger01A_Flip();
			return true;
			case "Building5MT_Trigger01A_Reset":
			Building5MT_Trigger01A_Reset();
			return true;
			case "Building5MT_Trigger02ABC_Flip":
			Building5MT_Trigger02ABC_Flip();
			return true;
			case "Building5MT_Trigger02ABC_Reset":
			Building5MT_Trigger02ABC_Reset();
			return true;
			case "Building5MT_Trigger03ABC_Flip":
			Building5MT_Trigger03ABC_Flip();
			return true;
			case "Building5MT_Trigger03ABC_Reset":
			Building5MT_Trigger03ABC_Reset();
			return true;
			case "Building5MT_Trigger04ABC_Flip":
			Building5MT_Trigger04ABC_Flip();
			return true;
			case "Building5MT_Trigger04ABC_Reset":
			Building5MT_Trigger04ABC_Reset();
			return true;
			case "Building5MT_Trigger05ABC_Flip":
			Building5MT_Trigger05ABC_Flip();
			return true;
			case "Building5MT_Trigger05ABC_Reset":
			Building5MT_Trigger05ABC_Reset();
			return true;
			case "Building5MT_Trigger06ABC_Flip":
			Building5MT_Trigger06ABC_Flip();
			return true;
			case "Building5MT_Trigger06ABC_Reset":
			Building5MT_Trigger06ABC_Reset();
			return true;
			case "Building5MT_Trigger07ABC_Flip":
			Building5MT_Trigger07ABC_Flip();
			return true;
			case "Building5MT_Trigger07ABC_Reset":
			Building5MT_Trigger07ABC_Reset();
			return true;
			case "Building5MT_Trigger08ABC_Flip":
			Building5MT_Trigger08ABC_Flip();
			return true;
			case "Building5MT_Trigger08ABC_Reset":
			Building5MT_Trigger08ABC_Reset();
			return true;
			case "Building5MT_Trigger09ABC_Flip":
			Building5MT_Trigger09ABC_Flip();
			return true;
			case "Building5MT_Trigger09ABC_Reset":
			Building5MT_Trigger09ABC_Reset();
			return true;
			case "Building5MT_Trigger10ABC_Flip":
			Building5MT_Trigger10ABC_Flip();
			return true;
			case "Building5MT_Trigger10ABC_Reset":
			Building5MT_Trigger10ABC_Reset();
			return true;
			case "Building5MT_Trigger12ABCD_Flip":
			Building5MT_Trigger12ABCD_Flip();
			return true;
			case "Building5MT_Trigger12ABCD_Reset":
			Building5MT_Trigger12ABCD_Reset();
			return true;
			case "Building5MT_Trigger13ABCD_Flip":
			Building5MT_Trigger13ABCD_Flip();
			return true;
			case "Building5MT_Trigger13ABCD_Reset":
			Building5MT_Trigger13ABCD_Reset();
			return true;
			case "Building5MT_Trigger14ABCD_Flip":
			Building5MT_Trigger14ABCD_Flip();
			return true;
			case "Building5MT_Trigger14ABCD_Reset":
			Building5MT_Trigger14ABCD_Reset();
			return true;
			case "Building5MT_Trigger15ABCD_Flip":
			Building5MT_Trigger15ABCD_Flip();
			return true;
			case "Building5MT_Trigger15ABCD_Reset":
			Building5MT_Trigger15ABCD_Reset();
			return true;
			case "Building5MT_Trigger16ABCD_Flip":
			Building5MT_Trigger16ABCD_Flip();
			return true;
			case "Building5MT_Trigger16ABCD_Reset":
			Building5MT_Trigger16ABCD_Reset();
			return true;
			case "Building5MT_Trigger17ABCD_Flip":
			Building5MT_Trigger17ABCD_Flip();
			return true;
			case "Building5MT_Trigger17ABCD_Reset":
			Building5MT_Trigger17ABCD_Reset();
			return true;
			case "Building5MT_Trigger18ABCD_Flip":
			Building5MT_Trigger18ABCD_Flip();
			return true;
			case "Building5MT_Trigger18ABCD_Reset":
			Building5MT_Trigger18ABCD_Reset();
			return true;
			case "Building5MT_Trigger19ABCD_Flip":
			Building5MT_Trigger19ABCD_Flip();
			return true;
			case "Building5MT_Trigger19ABCD_Reset":
			Building5MT_Trigger19ABCD_Reset();
			return true;
			case "Building5MT_Trigger20ABCD_Flip":
			Building5MT_Trigger20ABCD_Flip();
			return true;
			case "Building5MT_Trigger20ABCD_Reset":
			Building5MT_Trigger20ABCD_Reset();
			return true;
			case "Building5MT_Trigger21ABCD_Flip":
			Building5MT_Trigger21ABCD_Flip();
			return true;
			case "Building5MT_Trigger21ABCD_Reset":
			Building5MT_Trigger21ABCD_Reset();
			return true;
			case "Building5MT_Trigger22ABCD_Flip":
			Building5MT_Trigger22ABCD_Flip();
			return true;
			case "Building5MT_Trigger22ABCD_Reset":
			Building5MT_Trigger22ABCD_Reset();
			return true;
			case "Building5MT_Trigger23ABCD_Flip":
			Building5MT_Trigger23ABCD_Flip();
			return true;
			case "Building5MT_Trigger23ABCD_Reset":
			Building5MT_Trigger23ABCD_Reset();
			return true;
			case "Building5MT_Trigger24ABCD_Flip":
			Building5MT_Trigger24ABCD_Flip();
			return true;
			case "Building5MT_Trigger24ABCD_Reset":
			Building5MT_Trigger24ABCD_Reset();
			return true;
			case "Building5MT_Trigger25ABCD_Flip":
			Building5MT_Trigger25ABCD_Flip();
			return true;
			case "Building5MT_Trigger25ABCD_Reset":
			Building5MT_Trigger25ABCD_Reset();
			return true;
			case "Building5MT_Trigger26ABCD_Flip":
			Building5MT_Trigger26ABCD_Flip();
			return true;
			case "Building5MT_Trigger26ABCD_Reset":
			Building5MT_Trigger26ABCD_Reset();
			return true;
			case "Building5MT_Trigger27ABCD_Flip":
			Building5MT_Trigger27ABCD_Flip();
			return true;
			case "Building5MT_Trigger27ABCD_Reset":
			Building5MT_Trigger27ABCD_Reset();
			return true;
			case "Building5MT_Trigger28ABCD_Flip":
			Building5MT_Trigger28ABCD_Flip();
			return true;
			case "Building5MT_Trigger28ABCD_Reset":
			Building5MT_Trigger28ABCD_Reset();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		building5M01Target1=MarksmanTarget(CaptureEvent("building5Marker01Target01"));
		building5M01Target2=MarksmanTarget(CaptureEvent("building5Marker01Target02"));
		building5M02Target1=MarksmanTarget(CaptureEvent("building5Marker02Target01"));
		building5M02Target2=MarksmanTarget(CaptureEvent("building5Marker02Target02"));
		building5M02Target3=MarksmanTarget(CaptureEvent("building5Marker02Target03"));
		building5M02Target4=MarksmanTarget(CaptureEvent("building5Marker02Target04"));
		building5M02Target5=MarksmanTarget(CaptureEvent("building5Marker02Target05"));
		building5M02Target6=MarksmanTarget(CaptureEvent("building5Marker02Target06"));
		building5M03Target1=MarksmanTarget(CaptureEvent("building5Marker03Target01"));
		building5M03Target2=MarksmanTarget(CaptureEvent("building5Marker03Target02"));
		building5M03Target3=MarksmanTarget(CaptureEvent("building5Marker03Target03"));
		building5M03Target4=MarksmanTarget(CaptureEvent("building5Marker03Target04"));
		building5M03Target5=MarksmanTarget(CaptureEvent("building5Marker03Target05"));
		building5M03Target6=MarksmanTarget(CaptureEvent("building5Marker03Target06"));
		building5M04Target1=MarksmanTarget(CaptureEvent("building5Marker04Target01"));
		building5M04Target2=MarksmanTarget(CaptureEvent("building5Marker04Target02"));
		building5M04Target3=MarksmanTarget(CaptureEvent("building5Marker04Target03"));
		building5M04Target4=MarksmanTarget(CaptureEvent("building5Marker04Target04"));
		building5M05Target1=MarksmanTarget(CaptureEvent("building5Marker05Target01"));
		building5M05Target2=MarksmanTarget(CaptureEvent("building5Marker05Target02"));
		building5M05Target3=MarksmanTarget(CaptureEvent("building5Marker05Target03"));
		building5M05Target4=MarksmanTarget(CaptureEvent("building5Marker05Target04"));
		building5M05Target5=MarksmanTarget(CaptureEvent("building5Marker05Target05"));
		building5M05Target6=MarksmanTarget(CaptureEvent("building5Marker05Target06"));
		building5M05Target7=MarksmanTarget(CaptureEvent("building5Marker05Target07"));
		building5M06Target1=MarksmanTarget(CaptureEvent("building5Marker06Target01"));
		building5M06Target2=MarksmanTarget(CaptureEvent("building5Marker06Target02"));
		building5M06Target3=MarksmanTarget(CaptureEvent("building5Marker06Target03"));
		building5M06Target4=MarksmanTarget(CaptureEvent("building5Marker06Target04"));
		building5M06Target5=MarksmanTarget(CaptureEvent("building5Marker06Target05"));
		building5M07Target1=MarksmanTarget(CaptureEvent("building5Marker07Target01"));
		building5M07Target2=MarksmanTarget(CaptureEvent("building5Marker07Target02"));
		building5M07Target3=MarksmanTarget(CaptureEvent("building5Marker07Target03"));
		building5M07Target4=MarksmanTarget(CaptureEvent("building5Marker07Target04"));
		building5M08Target1=MarksmanTarget(CaptureEvent("building5Marker08Target01"));
		building5M08Target2=MarksmanTarget(CaptureEvent("building5Marker08Target02"));
		building5M08Target3=MarksmanTarget(CaptureEvent("building5Marker08Target03"));
		building5M09Target1=MarksmanTarget(CaptureEvent("building5Marker09Target01"));
		building5M09Target2=MarksmanTarget(CaptureEvent("building5Marker09Target02"));
		building5M09Target3=MarksmanTarget(CaptureEvent("building5Marker09Target03"));
		building5M10Target1=MarksmanTarget(CaptureEvent("building5Marker10Target01"));
		building5M10Target2=MarksmanTarget(CaptureEvent("building5Marker10Target02"));
		building5M10Target3=MarksmanTarget(CaptureEvent("building5Marker10Target03"));
		building5M10Target4=MarksmanTarget(CaptureEvent("building5Marker10Target04"));
		building5M11Target1=MarksmanTarget(CaptureEvent("building5Marker11Target01"));
		building5M11Target2=MarksmanTarget(CaptureEvent("building5Marker11Target02"));
		building5M11Target3=MarksmanTarget(CaptureEvent("building5Marker11Target03"));
		building5M12Target1=MarksmanTarget(CaptureEvent("building5Marker12Target01"));
		building5M12Target2=MarksmanTarget(CaptureEvent("building5Marker12Target02"));
		building5M13Target1=MarksmanTarget(CaptureEvent("building5Marker13Target01"));
		building5M13Target2=MarksmanTarget(CaptureEvent("building5Marker13Target02"));
		building5M13Target3=MarksmanTarget(CaptureEvent("building5Marker13Target03"));
		building5M13Target4=MarksmanTarget(CaptureEvent("building5Marker13Target04"));
		building5M14Target1=MarksmanTarget(CaptureEvent("building5Marker14Target01"));
		building5M14Target2=MarksmanTarget(CaptureEvent("building5Marker14Target02"));
		building5M14Target3=MarksmanTarget(CaptureEvent("building5Marker14Target03"));
		building5M14Target4=MarksmanTarget(CaptureEvent("building5Marker14Target04"));
		building5M14Target5=MarksmanTarget(CaptureEvent("building5Marker14Target05"));
		building5M14Target6=MarksmanTarget(CaptureEvent("building5Marker14Target06"));
		building5M14Target7=MarksmanTarget(CaptureEvent("building5Marker14Target07"));
		building5M14Target8=MarksmanTarget(CaptureEvent("building5Marker14Target08"));
		building5M15Target1=MarksmanTarget(CaptureEvent("building5Marker15Target01"));
		building5M15Target2=MarksmanTarget(CaptureEvent("building5Marker15Target02"));
		building5M15Target3=MarksmanTarget(CaptureEvent("building5Marker15Target03"));
		building5M15Target4=MarksmanTarget(CaptureEvent("building5Marker15Target04"));
		building5M15Target5=MarksmanTarget(CaptureEvent("building5Marker15Target05"));
		building5M16Target1=MarksmanTarget(CaptureEvent("building5Marker16Target01"));
		building5M16Target2=MarksmanTarget(CaptureEvent("building5Marker16Target02"));
		building5M16Target3=MarksmanTarget(CaptureEvent("building5Marker16Target03"));
		building5M16Target4=MarksmanTarget(CaptureEvent("building5Marker16Target04"));
		building5M16Target5=MarksmanTarget(CaptureEvent("building5Marker16Target05"));
		building5M16Target6=MarksmanTarget(CaptureEvent("building5Marker16Target06"));
		building5M17Target1=MarksmanTarget(CaptureEvent("building5Marker17Target01"));
		building5M17Target2=MarksmanTarget(CaptureEvent("building5Marker17Target02"));
		building5M18Target1=MarksmanTarget(CaptureEvent("building5Marker18Target01"));
		building5M18Target2=MarksmanTarget(CaptureEvent("building5Marker18Target02"));
		building5M18Target3=MarksmanTarget(CaptureEvent("building5Marker18Target03"));
		building5M18Target4=MarksmanTarget(CaptureEvent("building5Marker18Target04"));
		building5M18Target5=MarksmanTarget(CaptureEvent("building5Marker18Target05"));
		building5M19Target1=MarksmanTarget(CaptureEvent("building5Marker19Target01"));
		building5M19Target2=MarksmanTarget(CaptureEvent("building5Marker19Target02"));
		building5M19Target3=MarksmanTarget(CaptureEvent("building5Marker19Target03"));
		building5M20Target1=MarksmanTarget(CaptureEvent("building5Marker20Target01"));
		building5M20Target2=MarksmanTarget(CaptureEvent("building5Marker20Target02"));
		building5M20Target3=MarksmanTarget(CaptureEvent("building5Marker20Target03"));
		building5M21Target1=MarksmanTarget(CaptureEvent("building5Marker21Target01"));
		building5M21Target2=MarksmanTarget(CaptureEvent("building5Marker21Target02"));
		building5M21Target3=MarksmanTarget(CaptureEvent("building5Marker21Target03"));
		building5M22Target1=MarksmanTarget(CaptureEvent("building5Marker22Target01"));
		building5M22Target2=MarksmanTarget(CaptureEvent("building5Marker22Target02"));
		building5M22Target3=MarksmanTarget(CaptureEvent("building5Marker22Target03"));
		building5M23Target1=MarksmanTarget(CaptureEvent("building5Marker23Target01"));
		building5M23Target2=MarksmanTarget(CaptureEvent("building5Marker23Target02"));
		building5M23Target3=MarksmanTarget(CaptureEvent("building5Marker23Target03"));
		building5M23Target4=MarksmanTarget(CaptureEvent("building5Marker23Target04"));
		building5M23Target5=MarksmanTarget(CaptureEvent("building5Marker23Target05"));
		building5M24Target1=MarksmanTarget(CaptureEvent("building5Marker24Target01"));
		building5M24Target2=MarksmanTarget(CaptureEvent("building5Marker24Target02"));
		building5M24Target3=MarksmanTarget(CaptureEvent("building5Marker24Target03"));
		building5M25Target1=MarksmanTarget(CaptureEvent("building5Marker25Target01"));
		building5M25Target2=MarksmanTarget(CaptureEvent("building5Marker25Target02"));
		building5M25Target3=MarksmanTarget(CaptureEvent("building5Marker25Target03"));
		building5M26Target1=MarksmanTarget(CaptureEvent("building5Marker26Target01"));
		building5M26Target2=MarksmanTarget(CaptureEvent("building5Marker26Target02"));
		building5M26Target3=MarksmanTarget(CaptureEvent("building5Marker26Target03"));
		building5M27Target1=MarksmanTarget(CaptureEvent("building5Marker27Target01"));
		building5M27Target2=MarksmanTarget(CaptureEvent("building5Marker27Target02"));
		building5M27Target3=MarksmanTarget(CaptureEvent("building5Marker27Target03"));
		if (door1Entered)
		{
			building5M02Target1.bHidden=true;
			building5M02Target2.bHidden=true;
			building5M02Target3.bHidden=true;
			building5M02Target4.bHidden=true;
			building5M02Target5.bHidden=true;
			building5M02Target6.bHidden=true;
			building5M03Target1.bHidden=true;
			building5M03Target2.bHidden=true;
			building5M03Target3.bHidden=true;
			building5M03Target4.bHidden=true;
			building5M03Target5.bHidden=true;
			building5M03Target6.bHidden=true;
			building5M04Target1.bHidden=true;
			building5M04Target2.bHidden=true;
			building5M04Target3.bHidden=true;
			building5M04Target4.bHidden=true;
			building5M05Target1.bHidden=true;
			building5M05Target2.bHidden=true;
			building5M05Target3.bHidden=true;
			building5M05Target4.bHidden=true;
			building5M05Target5.bHidden=true;
			building5M05Target6.bHidden=true;
			building5M05Target7.bHidden=true;
			building5M06Target1.bHidden=true;
			building5M06Target2.bHidden=true;
			building5M06Target3.bHidden=true;
			building5M06Target4.bHidden=true;
			building5M06Target5.bHidden=true;
			building5M07Target1.bHidden=true;
			building5M07Target2.bHidden=true;
			building5M07Target3.bHidden=true;
			building5M07Target4.bHidden=true;
			building5M08Target1.bHidden=true;
			building5M08Target2.bHidden=true;
			building5M08Target3.bHidden=true;
			building5M09Target1.bHidden=true;
			building5M09Target2.bHidden=true;
			building5M09Target3.bHidden=true;
			building5M10Target1.bHidden=true;
			building5M10Target2.bHidden=true;
			building5M10Target3.bHidden=true;
			building5M10Target4.bHidden=true;
		}
		else
		{
			building5M02Target1.bHidden=false;
			building5M02Target2.bHidden=false;
			building5M02Target3.bHidden=false;
			building5M02Target4.bHidden=false;
			building5M02Target5.bHidden=false;
			building5M02Target6.bHidden=false;
			building5M03Target1.bHidden=false;
			building5M03Target2.bHidden=false;
			building5M03Target3.bHidden=false;
			building5M03Target4.bHidden=false;
			building5M03Target5.bHidden=false;
			building5M03Target6.bHidden=false;
			building5M04Target1.bHidden=false;
			building5M04Target2.bHidden=false;
			building5M04Target3.bHidden=false;
			building5M04Target4.bHidden=false;
			building5M05Target1.bHidden=false;
			building5M05Target2.bHidden=false;
			building5M05Target3.bHidden=false;
			building5M05Target4.bHidden=false;
			building5M05Target5.bHidden=false;
			building5M05Target6.bHidden=false;
			building5M05Target7.bHidden=false;
			building5M06Target1.bHidden=false;
			building5M06Target2.bHidden=false;
			building5M06Target3.bHidden=false;
			building5M06Target4.bHidden=false;
			building5M06Target5.bHidden=false;
			building5M07Target1.bHidden=false;
			building5M07Target2.bHidden=false;
			building5M07Target3.bHidden=false;
			building5M07Target4.bHidden=false;
			building5M08Target1.bHidden=false;
			building5M08Target2.bHidden=false;
			building5M08Target3.bHidden=false;
			building5M09Target1.bHidden=false;
			building5M09Target2.bHidden=false;
			building5M09Target3.bHidden=false;
			building5M10Target1.bHidden=false;
			building5M10Target2.bHidden=false;
			building5M10Target3.bHidden=false;
			building5M10Target4.bHidden=false;
		}
		if (! building5MTTriggerCaptured)
		{
			building5MTTrigger01=TriggerVolume(CaptureEvent("Building5MT_Trigger01A"));
			building5MTTrigger02=TriggerVolume(CaptureEvent("Building5MT_Trigger02ABC"));
			building5MTTrigger03=TriggerVolume(CaptureEvent("Building5MT_Trigger03ABC"));
			building5MTTrigger04=TriggerVolume(CaptureEvent("Building5MT_Trigger04ABC"));
			building5MTTrigger05=TriggerVolume(CaptureEvent("Building5MT_Trigger05ABC"));
			building5MTTrigger06=TriggerVolume(CaptureEvent("Building5MT_Trigger06ABC"));
			building5MTTrigger07=TriggerVolume(CaptureEvent("Building5MT_Trigger07ABC"));
			building5MTTrigger08=TriggerVolume(CaptureEvent("Building5MT_Trigger08ABC"));
			building5MTTrigger09=TriggerVolume(CaptureEvent("Building5MT_Trigger09ABC"));
			building5MTTrigger10=TriggerVolume(CaptureEvent("Building5MT_Trigger10ABC"));
			building5MTTrigger11=TriggerVolume(CaptureEvent("Building5MT_Trigger11ABC"));
			building5MTTrigger12=TriggerVolume(CaptureEvent("Building5MT_Trigger12ABCD"));
			building5MTTrigger13=TriggerVolume(CaptureEvent("Building5MT_Trigger13ABCD"));
			building5MTTrigger14=TriggerVolume(CaptureEvent("Building5MT_Trigger14ABCD"));
			building5MTTrigger15=TriggerVolume(CaptureEvent("Building5MT_Trigger15ABCD"));
			building5MTTrigger16=TriggerVolume(CaptureEvent("Building5MT_Trigger16ABCD"));
			building5MTTrigger17=TriggerVolume(CaptureEvent("Building5MT_Trigger17ABCD"));
			building5MTTrigger18=TriggerVolume(CaptureEvent("Building5MT_Trigger18ABCD"));
			building5MTTrigger19=TriggerVolume(CaptureEvent("Building5MT_Trigger19ABCD"));
			building5MTTrigger20=TriggerVolume(CaptureEvent("Building5MT_Trigger20ABCD"));
			building5MTTrigger21=TriggerVolume(CaptureEvent("Building5MT_Trigger21ABCD"));
			building5MTTrigger22=TriggerVolume(CaptureEvent("Building5MT_Trigger22ABCD"));
			building5MTTrigger23=TriggerVolume(CaptureEvent("Building5MT_Trigger23ABCD"));
			building5MTTrigger24=TriggerVolume(CaptureEvent("Building5MT_Trigger24ABCD"));
			building5MTTrigger25=TriggerVolume(CaptureEvent("Building5MT_Trigger25ABCD"));
			building5MTTrigger26=TriggerVolume(CaptureEvent("Building5MT_Trigger26ABCD"));
			building5MTTrigger27=TriggerVolume(CaptureEvent("Building5MT_Trigger27ABCD"));
			building5MTTrigger28=TriggerVolume(CaptureEvent("Building5MT_Trigger28ABCD"));
			building5MTTriggerCaptured=true;
		}
	}
}
*/

/*
State Building5InActive extends Building5Active
{
	Function BeginState()
	{
		door1Entered=false;
		door2Entered=false;
		door3Entered=false;
		door4Entered=false;
		building5M01Target1.ResetTarget(true);
		UnCaptureEvent(building5M01Target1);
		building5M01Target2.ResetTarget(true);
		UnCaptureEvent(building5M01Target2);
		building5M02Target1.ResetTarget(true);
		UnCaptureEvent(building5M02Target1);
		building5M02Target2.ResetTarget(true);
		UnCaptureEvent(building5M02Target2);
		building5M02Target3.ResetTarget(true);
		UnCaptureEvent(building5M02Target3);
		building5M02Target4.ResetTarget(true);
		UnCaptureEvent(building5M02Target4);
		building5M02Target5.ResetTarget(true);
		UnCaptureEvent(building5M02Target5);
		building5M02Target6.ResetTarget(true);
		UnCaptureEvent(building5M02Target6);
		building5M03Target1.ResetTarget(true);
		UnCaptureEvent(building5M03Target1);
		building5M03Target2.ResetTarget(true);
		UnCaptureEvent(building5M03Target2);
		building5M03Target3.ResetTarget(true);
		UnCaptureEvent(building5M03Target3);
		building5M03Target4.ResetTarget(true);
		UnCaptureEvent(building5M03Target4);
		building5M03Target5.ResetTarget(true);
		UnCaptureEvent(building5M03Target5);
		building5M03Target6.ResetTarget(true);
		UnCaptureEvent(building5M03Target6);
		building5M04Target1.ResetTarget(true);
		UnCaptureEvent(building5M04Target1);
		building5M04Target2.ResetTarget(true);
		UnCaptureEvent(building5M04Target2);
		building5M04Target3.ResetTarget(true);
		UnCaptureEvent(building5M04Target3);
		building5M04Target4.ResetTarget(true);
		UnCaptureEvent(building5M04Target4);
		building5M05Target1.ResetTarget(true);
		UnCaptureEvent(building5M05Target1);
		building5M05Target2.ResetTarget(true);
		UnCaptureEvent(building5M05Target2);
		building5M05Target3.ResetTarget(true);
		UnCaptureEvent(building5M05Target3);
		building5M05Target4.ResetTarget(true);
		UnCaptureEvent(building5M05Target4);
		building5M05Target5.ResetTarget(true);
		UnCaptureEvent(building5M05Target5);
		building5M05Target6.ResetTarget(true);
		UnCaptureEvent(building5M05Target6);
		building5M05Target7.ResetTarget(true);
		UnCaptureEvent(building5M05Target7);
		building5M06Target1.ResetTarget(true);
		UnCaptureEvent(building5M06Target1);
		building5M06Target2.ResetTarget(true);
		UnCaptureEvent(building5M06Target2);
		building5M06Target3.ResetTarget(true);
		UnCaptureEvent(building5M06Target3);
		building5M06Target4.ResetTarget(true);
		UnCaptureEvent(building5M06Target4);
		building5M06Target5.ResetTarget(true);
		UnCaptureEvent(building5M06Target5);
		building5M07Target1.ResetTarget(true);
		UnCaptureEvent(building5M07Target1);
		building5M07Target2.ResetTarget(true);
		UnCaptureEvent(building5M07Target2);
		building5M07Target3.ResetTarget(true);
		UnCaptureEvent(building5M07Target3);
		building5M07Target4.ResetTarget(true);
		UnCaptureEvent(building5M07Target4);
		building5M08Target1.ResetTarget(true);
		UnCaptureEvent(building5M08Target1);
		building5M08Target2.ResetTarget(true);
		UnCaptureEvent(building5M08Target2);
		building5M08Target3.ResetTarget(true);
		UnCaptureEvent(building5M08Target3);
		building5M09Target1.ResetTarget(true);
		UnCaptureEvent(building5M09Target1);
		building5M09Target2.ResetTarget(true);
		UnCaptureEvent(building5M09Target2);
		building5M09Target3.ResetTarget(true);
		UnCaptureEvent(building5M09Target3);
		building5M10Target1.ResetTarget(true);
		UnCaptureEvent(building5M10Target1);
		building5M10Target2.ResetTarget(true);
		UnCaptureEvent(building5M10Target2);
		building5M10Target3.ResetTarget(true);
		UnCaptureEvent(building5M10Target3);
		building5M10Target4.ResetTarget(true);
		UnCaptureEvent(building5M10Target4);
		building5M11Target1.ResetTarget(true);
		UnCaptureEvent(building5M11Target1);
		building5M11Target2.ResetTarget(true);
		UnCaptureEvent(building5M11Target2);
		building5M11Target3.ResetTarget(true);
		UnCaptureEvent(building5M11Target3);
		building5M12Target1.ResetTarget(true);
		UnCaptureEvent(building5M12Target1);
		building5M12Target2.ResetTarget(true);
		UnCaptureEvent(building5M12Target2);
		building5M13Target1.ResetTarget(true);
		UnCaptureEvent(building5M13Target1);
		building5M13Target2.ResetTarget(true);
		UnCaptureEvent(building5M13Target2);
		building5M13Target3.ResetTarget(true);
		UnCaptureEvent(building5M13Target3);
		building5M13Target4.ResetTarget(true);
		UnCaptureEvent(building5M13Target4);
		building5M14Target1.ResetTarget(true);
		UnCaptureEvent(building5M14Target1);
		building5M14Target2.ResetTarget(true);
		UnCaptureEvent(building5M14Target2);
		building5M14Target3.ResetTarget(true);
		UnCaptureEvent(building5M14Target3);
		building5M14Target4.ResetTarget(true);
		UnCaptureEvent(building5M14Target4);
		building5M14Target5.ResetTarget(true);
		UnCaptureEvent(building5M14Target5);
		building5M14Target6.ResetTarget(true);
		UnCaptureEvent(building5M14Target6);
		building5M14Target7.ResetTarget(true);
		UnCaptureEvent(building5M14Target7);
		building5M14Target8.ResetTarget(true);
		UnCaptureEvent(building5M14Target8);
		building5M15Target1.ResetTarget(true);
		UnCaptureEvent(building5M15Target1);
		building5M15Target2.ResetTarget(true);
		UnCaptureEvent(building5M15Target2);
		building5M15Target3.ResetTarget(true);
		UnCaptureEvent(building5M15Target3);
		building5M15Target4.ResetTarget(true);
		UnCaptureEvent(building5M15Target4);
		building5M15Target5.ResetTarget(true);
		UnCaptureEvent(building5M15Target5);
		building5M16Target1.ResetTarget(true);
		UnCaptureEvent(building5M16Target1);
		building5M16Target2.ResetTarget(true);
		UnCaptureEvent(building5M16Target2);
		building5M16Target3.ResetTarget(true);
		UnCaptureEvent(building5M16Target3);
		building5M16Target4.ResetTarget(true);
		UnCaptureEvent(building5M16Target4);
		building5M16Target5.ResetTarget(true);
		UnCaptureEvent(building5M16Target5);
		building5M16Target6.ResetTarget(true);
		UnCaptureEvent(building5M16Target6);
		building5M17Target1.ResetTarget(true);
		UnCaptureEvent(building5M17Target1);
		building5M17Target2.ResetTarget(true);
		UnCaptureEvent(building5M17Target2);
		building5M18Target1.ResetTarget(true);
		UnCaptureEvent(building5M18Target1);
		building5M18Target2.ResetTarget(true);
		UnCaptureEvent(building5M18Target2);
		building5M18Target3.ResetTarget(true);
		UnCaptureEvent(building5M18Target3);
		building5M18Target4.ResetTarget(true);
		UnCaptureEvent(building5M18Target4);
		building5M18Target5.ResetTarget(true);
		UnCaptureEvent(building5M18Target5);
		building5M19Target1.ResetTarget(true);
		UnCaptureEvent(building5M19Target1);
		building5M19Target2.ResetTarget(true);
		UnCaptureEvent(building5M19Target2);
		building5M19Target3.ResetTarget(true);
		UnCaptureEvent(building5M19Target3);
		building5M20Target1.ResetTarget(true);
		UnCaptureEvent(building5M20Target1);
		building5M20Target2.ResetTarget(true);
		UnCaptureEvent(building5M20Target2);
		building5M20Target3.ResetTarget(true);
		UnCaptureEvent(building5M20Target3);
		building5M21Target1.ResetTarget(true);
		UnCaptureEvent(building5M21Target1);
		building5M21Target2.ResetTarget(true);
		UnCaptureEvent(building5M21Target2);
		building5M21Target3.ResetTarget(true);
		UnCaptureEvent(building5M21Target3);
		building5M22Target1.ResetTarget(true);
		UnCaptureEvent(building5M22Target1);
		building5M22Target2.ResetTarget(true);
		UnCaptureEvent(building5M22Target2);
		building5M22Target3.ResetTarget(true);
		UnCaptureEvent(building5M22Target3);
		building5M23Target1.ResetTarget(true);
		UnCaptureEvent(building5M23Target1);
		building5M23Target2.ResetTarget(true);
		UnCaptureEvent(building5M23Target2);
		building5M23Target3.ResetTarget(true);
		UnCaptureEvent(building5M23Target3);
		building5M23Target4.ResetTarget(true);
		UnCaptureEvent(building5M23Target4);
		building5M23Target5.ResetTarget(true);
		UnCaptureEvent(building5M23Target5);
		building5M24Target1.ResetTarget(true);
		UnCaptureEvent(building5M24Target1);
		building5M24Target2.ResetTarget(true);
		UnCaptureEvent(building5M24Target2);
		building5M24Target3.ResetTarget(true);
		UnCaptureEvent(building5M24Target3);
		building5M25Target1.ResetTarget(true);
		UnCaptureEvent(building5M25Target1);
		building5M25Target2.ResetTarget(true);
		UnCaptureEvent(building5M25Target2);
		building5M25Target3.ResetTarget(true);
		UnCaptureEvent(building5M25Target3);
		building5M26Target1.ResetTarget(true);
		UnCaptureEvent(building5M26Target1);
		building5M26Target2.ResetTarget(true);
		UnCaptureEvent(building5M26Target2);
		building5M26Target3.ResetTarget(true);
		UnCaptureEvent(building5M26Target3);
		building5M27Target1.ResetTarget(true);
		UnCaptureEvent(building5M27Target1);
		building5M27Target2.ResetTarget(true);
		UnCaptureEvent(building5M27Target2);
		building5M27Target3.ResetTarget(true);
		UnCaptureEvent(building5M27Target3);
		ChangeState("NoBuildingActive");
	}
}
*/

/*
State Building6Active
{
	Function bool Building6MT_Trigger01B_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (door1Entered)
		{
			StartTimer("Building6MT_Trigger01B_Flip",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building6MTTrigger01);
		}
		return true;
	}
	Function Building6MT_Trigger01B_Flip()
	{
		if (building6MTTrigger01.bActive)
		{
			building6M01Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M01Target1);
			building6M01Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M01Target2);
			building6M01Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M01Target3);
			building6M02Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M02Target1);
			building6M02Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M02Target2);
			building6M02Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M02Target3);
			building6M03Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M03Target1);
			building6M03Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M03Target2);
			building6M03Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M03Target3);
			building6M03Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M03Target4);
			building6M03Target5.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M03Target5);
			building6M03Target6.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M03Target6);
			building6M03Target7.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M03Target7);
			building6M04Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M04Target1);
			building6M04Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M04Target2);
			building6M04Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M04Target3);
			building6MTTrigger01->DisableTrigger();
			StartTimer("Building6MT_Trigger01B_Reset",4);
		}
	}
	Function Building6MT_Trigger01B_Reset()
	{
		building6M01Target1.ResetTarget(true);
		building6M01Target2.ResetTarget(true);
		building6M01Target3.ResetTarget(true);
		building6M02Target1.ResetTarget(true);
		building6M02Target2.ResetTarget(true);
		building6M02Target3.ResetTarget(true);
		building6M03Target1.ResetTarget(true);
		building6M03Target2.ResetTarget(true);
		building6M03Target3.ResetTarget(true);
		building6M03Target4.ResetTarget(true);
		building6M03Target5.ResetTarget(true);
		building6M03Target6.ResetTarget(true);
		building6M03Target7.ResetTarget(true);
		building6M04Target1.ResetTarget(true);
		building6M04Target2.ResetTarget(true);
		building6M04Target3.ResetTarget(true);
	}
	Function bool Building6MT_Trigger02B_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (door1Entered)
		{
			StartTimer("Building6MT_Trigger02B_Flip",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building6MTTrigger02);
		}
		return true;
	}
	Function Building6MT_Trigger02B_Flip()
	{
		if (building6MTTrigger02.bActive)
		{
			building6M05Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M05Target1);
			building6M05Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M05Target2);
			building6M05Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M05Target3);
			building6MTTrigger02->DisableTrigger();
			StartTimer("Building6MT_Trigger02B_Reset",4);
		}
	}
	Function Building6MT_Trigger02B_Reset()
	{
		building6M05Target1.ResetTarget(true);
		building6M05Target2.ResetTarget(true);
		building6M05Target3.ResetTarget(true);
	}
	Function bool Building6MT_Trigger03B_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (door1Entered)
		{
			StartTimer("Building6MT_Trigger03B_Flip",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building6MTTrigger03);
		}
		return true;
	}
	Function Building6MT_Trigger03B_Flip()
	{
		if (building6MTTrigger03.bActive)
		{
			building6M06Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M06Target1);
			building6M06Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M06Target2);
			building6M07Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M07Target1);
			building6M07Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M07Target2);
			building6M07Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M07Target3);
			building6MTTrigger03->DisableTrigger();
			StartTimer("Building6MT_Trigger03B_Reset",4);
		}
	}
	Function Building6MT_Trigger03B_Reset()
	{
		building6M06Target1.ResetTarget(true);
		building6M06Target2.ResetTarget(true);
		building6M07Target1.ResetTarget(true);
		building6M07Target2.ResetTarget(true);
		building6M07Target3.ResetTarget(true);
	}
	Function bool Building6MT_Trigger04B_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (door1Entered)
		{
			StartTimer("Building6MT_Trigger04B_Flip",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building6MTTrigger04);
		}
		return true;
	}
	Function Building6MT_Trigger04B_Flip()
	{
		if (building6MTTrigger04.bActive)
		{
			building6M08Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M08Target1);
			building6M08Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M08Target2);
			building6M08Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M08Target3);
			building6MTTrigger04->DisableTrigger();
			StartTimer("Building6MT_Trigger04B_Reset",4);
		}
	}
	Function Building6MT_Trigger04B_Reset()
	{
		building6M08Target1.ResetTarget(true);
		building6M08Target2.ResetTarget(true);
		building6M08Target3.ResetTarget(true);
	}
	Function bool Building6MT_Trigger05A_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (door2Entered)
		{
			StartTimer("Building6MT_Trigger05A_Flip",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building6MTTrigger05);
		}
		return true;
	}
	Function Building6MT_Trigger05A_Flip()
	{
		if (building6MTTrigger05.bActive)
		{
			building6M09Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M09Target1);
			building6M09Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M09Target2);
			building6M09Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M09Target3);
			building6M09Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M09Target4);
			building6M09Target5.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M09Target5);
			building6M10Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M10Target1);
			building6M10Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M10Target2);
			building6M11Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M11Target1);
			building6M11Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M11Target2);
			building6M12Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M12Target1);
			building6M12Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M12Target2);
			building6MTTrigger05->DisableTrigger();
			StartTimer("Building6MT_Trigger05A_Reset",4);
		}
	}
	Function Building6MT_Trigger05A_Reset()
	{
		building6M09Target1.ResetTarget(true);
		building6M09Target2.ResetTarget(true);
		building6M09Target3.ResetTarget(true);
		building6M09Target4.ResetTarget(true);
		building6M09Target5.ResetTarget(true);
		building6M10Target1.ResetTarget(true);
		building6M10Target2.ResetTarget(true);
		building6M11Target1.ResetTarget(true);
		building6M11Target2.ResetTarget(true);
		building6M12Target1.ResetTarget(true);
		building6M12Target2.ResetTarget(true);
	}
	Function bool Building6MT_Trigger06A_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (door2Entered)
		{
			StartTimer("Building6MT_Trigger06A_Flip",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building6MTTrigger06);
		}
		return true;
	}
	Function Building6MT_Trigger06A_Flip()
	{
		if (building6MTTrigger06.bActive)
		{
			building6M13Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M13Target1);
			building6M13Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M13Target2);
			building6M13Target3.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M13Target3);
			building6M13Target4.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M13Target4);
			building6M13Target5.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M13Target5);
			building6M13Target6.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M13Target6);
			building6MTTrigger06->DisableTrigger();
			StartTimer("Building6MT_Trigger06A_Reset",4);
		}
	}
	Function Building6MT_Trigger06A_Reset()
	{
		building6M13Target1.ResetTarget(true);
		building6M13Target2.ResetTarget(true);
		building6M13Target3.ResetTarget(true);
		building6M13Target4.ResetTarget(true);
		building6M13Target5.ResetTarget(true);
		building6M13Target6.ResetTarget(true);
	}
	Function bool Building6MT_Trigger07A_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (door2Entered)
		{
			StartTimer("Building6MT_Trigger07A_Flip",(FMath::FRand() * TargetFlipModifier));
			UnCaptureEvent(building6MTTrigger07);
		}
		return true;
	}
	Function Building6MT_Trigger07A_Flip()
	{
		if (building6MTTrigger07.bActive)
		{
			building6M14Target1.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M14Target1);
			building6M14Target2.TriggerSelf();
			PlayGameSound("m_hydraulic",building6M14Target2);
			building6MTTrigger07->DisableTrigger();
			StartTimer("Building6MT_Trigger07A_Reset",4);
		}
	}
	Function Building6MT_Trigger07A_Reset()
	{
		building6M14Target1.ResetTarget(true);
		building6M14Target2.ResetTarget(true);
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case "Building6MT_Trigger01B_Flip":
			Building6MT_Trigger01B_Flip();
			return true;
			case "Building6MT_Trigger01B_Reset":
			Building6MT_Trigger01B_Reset();
			return true;
			case "Building6MT_Trigger02B_Flip":
			Building6MT_Trigger02B_Flip();
			return true;
			case "Building6MT_Trigger02B_Reset":
			Building6MT_Trigger02B_Reset();
			return true;
			case "Building6MT_Trigger03B_Flip":
			Building6MT_Trigger03B_Flip();
			return true;
			case "Building6MT_Trigger03B_Reset":
			Building6MT_Trigger03B_Reset();
			return true;
			case "Building6MT_Trigger04B_Flip":
			Building6MT_Trigger04B_Flip();
			return true;
			case "Building6MT_Trigger04B_Reset":
			Building6MT_Trigger04B_Reset();
			return true;
			case "Building6MT_Trigger05A_Flip":
			Building6MT_Trigger05A_Flip();
			return true;
			case "Building6MT_Trigger05A_Reset":
			Building6MT_Trigger05A_Reset();
			return true;
			case "Building6MT_Trigger06A_Flip":
			Building6MT_Trigger06A_Flip();
			return true;
			case "Building6MT_Trigger06A_Reset":
			Building6MT_Trigger06A_Reset();
			return true;
			case "Building6MT_Trigger07A_Flip":
			Building6MT_Trigger07A_Flip();
			return true;
			case "Building6MT_Trigger07A_Reset":
			Building6MT_Trigger07A_Reset();
			return true;
			default:
			return Timer_Timer(Name);
		}
	}
	Function BeginState()
	{
		building6M01Target1=MarksmanTarget(CaptureEvent("building6Marker01Target01"));
		building6M01Target2=MarksmanTarget(CaptureEvent("building6Marker01Target02"));
		building6M01Target3=MarksmanTarget(CaptureEvent("building6Marker01Target03"));
		building6M02Target1=MarksmanTarget(CaptureEvent("building6Marker02Target01"));
		building6M02Target2=MarksmanTarget(CaptureEvent("building6Marker02Target02"));
		building6M02Target3=MarksmanTarget(CaptureEvent("building6Marker02Target03"));
		building6M03Target1=MarksmanTarget(CaptureEvent("building6Marker03Target01"));
		building6M03Target2=MarksmanTarget(CaptureEvent("building6Marker03Target02"));
		building6M03Target3=MarksmanTarget(CaptureEvent("building6Marker03Target03"));
		building6M03Target4=MarksmanTarget(CaptureEvent("building6Marker03Target04"));
		building6M03Target5=MarksmanTarget(CaptureEvent("building6Marker03Target05"));
		building6M03Target6=MarksmanTarget(CaptureEvent("building6Marker03Target06"));
		building6M03Target7=MarksmanTarget(CaptureEvent("building6Marker03Target07"));
		building6M04Target1=MarksmanTarget(CaptureEvent("building6Marker04Target01"));
		building6M04Target2=MarksmanTarget(CaptureEvent("building6Marker04Target02"));
		building6M04Target3=MarksmanTarget(CaptureEvent("building6Marker04Target03"));
		building6M05Target1=MarksmanTarget(CaptureEvent("building6Marker05Target01"));
		building6M05Target2=MarksmanTarget(CaptureEvent("building6Marker05Target02"));
		building6M05Target3=MarksmanTarget(CaptureEvent("building6Marker05Target03"));
		building6M06Target1=MarksmanTarget(CaptureEvent("building6Marker06Target01"));
		building6M06Target2=MarksmanTarget(CaptureEvent("building6Marker06Target02"));
		building6M07Target1=MarksmanTarget(CaptureEvent("building6Marker07Target01"));
		building6M07Target2=MarksmanTarget(CaptureEvent("building6Marker07Target02"));
		building6M07Target3=MarksmanTarget(CaptureEvent("building6Marker07Target03"));
		building6M08Target1=MarksmanTarget(CaptureEvent("building6Marker08Target01"));
		building6M08Target2=MarksmanTarget(CaptureEvent("building6Marker08Target02"));
		building6M08Target3=MarksmanTarget(CaptureEvent("building6Marker08Target03"));
		building6M09Target1=MarksmanTarget(CaptureEvent("building6Marker09Target01"));
		building6M09Target2=MarksmanTarget(CaptureEvent("building6Marker09Target02"));
		building6M09Target3=MarksmanTarget(CaptureEvent("building6Marker09Target03"));
		building6M09Target4=MarksmanTarget(CaptureEvent("building6Marker09Target04"));
		building6M09Target5=MarksmanTarget(CaptureEvent("building6Marker09Target05"));
		building6M10Target1=MarksmanTarget(CaptureEvent("building6Marker10Target01"));
		building6M10Target2=MarksmanTarget(CaptureEvent("building6Marker10Target02"));
		building6M11Target1=MarksmanTarget(CaptureEvent("building6Marker11Target01"));
		building6M11Target2=MarksmanTarget(CaptureEvent("building6Marker11Target02"));
		building6M12Target1=MarksmanTarget(CaptureEvent("building6Marker12Target01"));
		building6M12Target2=MarksmanTarget(CaptureEvent("building6Marker12Target02"));
		building6M13Target1=MarksmanTarget(CaptureEvent("building6Marker13Target01"));
		building6M13Target2=MarksmanTarget(CaptureEvent("building6Marker13Target02"));
		building6M13Target3=MarksmanTarget(CaptureEvent("building6Marker13Target03"));
		building6M13Target4=MarksmanTarget(CaptureEvent("building6Marker13Target04"));
		building6M13Target5=MarksmanTarget(CaptureEvent("building6Marker13Target05"));
		building6M13Target6=MarksmanTarget(CaptureEvent("building6Marker13Target06"));
		building6M14Target1=MarksmanTarget(CaptureEvent("building6Marker14Target01"));
		building6M14Target2=MarksmanTarget(CaptureEvent("building6Marker14Target02"));
		if (door1Entered)
		{
			building6M01Target1.bHidden=false;
			building6M01Target2.bHidden=false;
			building6M01Target3.bHidden=false;
			building6M02Target1.bHidden=false;
			building6M02Target2.bHidden=false;
			building6M02Target3.bHidden=false;
			building6M03Target1.bHidden=false;
			building6M03Target2.bHidden=false;
			building6M03Target3.bHidden=false;
			building6M03Target4.bHidden=false;
			building6M03Target5.bHidden=false;
			building6M03Target6.bHidden=false;
			building6M03Target7.bHidden=false;
			building6M04Target1.bHidden=false;
			building6M04Target2.bHidden=false;
			building6M04Target3.bHidden=false;
			building6M05Target1.bHidden=false;
			building6M05Target2.bHidden=false;
			building6M05Target3.bHidden=false;
			building6M06Target1.bHidden=false;
			building6M06Target2.bHidden=false;
			building6M07Target1.bHidden=false;
			building6M07Target2.bHidden=false;
			building6M07Target3.bHidden=false;
			building6M08Target1.bHidden=false;
			building6M08Target2.bHidden=false;
			building6M08Target3.bHidden=false;
			building6M09Target1.bHidden=true;
			building6M09Target2.bHidden=true;
			building6M09Target3.bHidden=true;
			building6M09Target4.bHidden=true;
			building6M09Target5.bHidden=true;
			building6M10Target1.bHidden=true;
			building6M10Target2.bHidden=true;
			building6M11Target1.bHidden=true;
			building6M11Target2.bHidden=true;
			building6M12Target1.bHidden=true;
			building6M12Target2.bHidden=true;
			building6M13Target1.bHidden=true;
			building6M13Target2.bHidden=true;
			building6M13Target3.bHidden=true;
			building6M13Target4.bHidden=true;
			building6M13Target5.bHidden=true;
			building6M13Target6.bHidden=true;
			building6M14Target1.bHidden=true;
			building6M14Target2.bHidden=true;
		}
		if (door2Entered)
		{
			building6M01Target1.bHidden=true;
			building6M01Target2.bHidden=true;
			building6M01Target3.bHidden=true;
			building6M02Target1.bHidden=true;
			building6M02Target2.bHidden=true;
			building6M02Target3.bHidden=true;
			building6M03Target1.bHidden=true;
			building6M03Target2.bHidden=true;
			building6M03Target3.bHidden=true;
			building6M03Target4.bHidden=true;
			building6M03Target5.bHidden=true;
			building6M03Target6.bHidden=true;
			building6M03Target7.bHidden=true;
			building6M04Target1.bHidden=true;
			building6M04Target2.bHidden=true;
			building6M04Target3.bHidden=true;
			building6M05Target1.bHidden=true;
			building6M05Target2.bHidden=true;
			building6M05Target3.bHidden=true;
			building6M06Target1.bHidden=true;
			building6M06Target2.bHidden=true;
			building6M07Target1.bHidden=true;
			building6M07Target2.bHidden=true;
			building6M07Target3.bHidden=true;
			building6M08Target1.bHidden=true;
			building6M08Target2.bHidden=true;
			building6M08Target3.bHidden=true;
			building6M09Target1.bHidden=false;
			building6M09Target2.bHidden=false;
			building6M09Target3.bHidden=false;
			building6M09Target4.bHidden=false;
			building6M09Target5.bHidden=false;
			building6M10Target1.bHidden=false;
			building6M10Target2.bHidden=false;
			building6M11Target1.bHidden=false;
			building6M11Target2.bHidden=false;
			building6M12Target1.bHidden=false;
			building6M12Target2.bHidden=false;
			building6M13Target1.bHidden=false;
			building6M13Target2.bHidden=false;
			building6M13Target3.bHidden=false;
			building6M13Target4.bHidden=false;
			building6M13Target5.bHidden=false;
			building6M13Target6.bHidden=false;
			building6M14Target1.bHidden=false;
			building6M14Target2.bHidden=false;
		}
		if (! building6MTTriggerCaptured)
		{
			building6MTTrigger01=TriggerVolume(CaptureEvent("Building6MT_Trigger01B"));
			building6MTTrigger02=TriggerVolume(CaptureEvent("Building6MT_Trigger02B"));
			building6MTTrigger03=TriggerVolume(CaptureEvent("Building6MT_Trigger03B"));
			building6MTTrigger04=TriggerVolume(CaptureEvent("Building6MT_Trigger04B"));
			building6MTTrigger05=TriggerVolume(CaptureEvent("Building6MT_Trigger05A"));
			building6MTTrigger06=TriggerVolume(CaptureEvent("Building6MT_Trigger06A"));
			building6MTTrigger07=TriggerVolume(CaptureEvent("Building6MT_Trigger07A"));
			building6MTTriggerCaptured=true;
		}
	}
}
*/

/*
State Building6InActive extends Building6Active
{
	Function BeginState()
	{
		door1Entered=false;
		door2Entered=false;
		building6M01Target1.ResetTarget(true);
		UnCaptureEvent(building6M01Target1);
		building6M01Target2.ResetTarget(true);
		UnCaptureEvent(building6M01Target2);
		building6M01Target3.ResetTarget(true);
		UnCaptureEvent(building6M01Target3);
		building6M02Target1.ResetTarget(true);
		UnCaptureEvent(building6M02Target1);
		building6M02Target2.ResetTarget(true);
		UnCaptureEvent(building6M02Target2);
		building6M02Target3.ResetTarget(true);
		UnCaptureEvent(building6M02Target3);
		building6M03Target1.ResetTarget(true);
		UnCaptureEvent(building6M03Target1);
		building6M03Target2.ResetTarget(true);
		UnCaptureEvent(building6M03Target2);
		building6M03Target3.ResetTarget(true);
		UnCaptureEvent(building6M03Target3);
		building6M03Target4.ResetTarget(true);
		UnCaptureEvent(building6M03Target4);
		building6M03Target5.ResetTarget(true);
		UnCaptureEvent(building6M03Target5);
		building6M03Target6.ResetTarget(true);
		UnCaptureEvent(building6M03Target6);
		building6M03Target7.ResetTarget(true);
		UnCaptureEvent(building6M03Target7);
		building6M04Target1.ResetTarget(true);
		UnCaptureEvent(building6M04Target1);
		building6M04Target2.ResetTarget(true);
		UnCaptureEvent(building6M04Target2);
		building6M04Target3.ResetTarget(true);
		UnCaptureEvent(building6M04Target3);
		building6M05Target1.ResetTarget(true);
		UnCaptureEvent(building6M05Target1);
		building6M05Target2.ResetTarget(true);
		UnCaptureEvent(building6M05Target2);
		building6M05Target3.ResetTarget(true);
		UnCaptureEvent(building6M05Target3);
		building6M06Target1.ResetTarget(true);
		UnCaptureEvent(building6M06Target1);
		building6M06Target2.ResetTarget(true);
		UnCaptureEvent(building6M06Target2);
		building6M07Target1.ResetTarget(true);
		UnCaptureEvent(building6M07Target1);
		building6M07Target2.ResetTarget(true);
		UnCaptureEvent(building6M07Target2);
		building6M07Target3.ResetTarget(true);
		UnCaptureEvent(building6M07Target3);
		building6M08Target1.ResetTarget(true);
		UnCaptureEvent(building6M08Target1);
		building6M08Target2.ResetTarget(true);
		UnCaptureEvent(building6M08Target2);
		building6M08Target3.ResetTarget(true);
		UnCaptureEvent(building6M08Target3);
		building6M09Target1.ResetTarget(true);
		UnCaptureEvent(building6M09Target1);
		building6M09Target2.ResetTarget(true);
		UnCaptureEvent(building6M09Target2);
		building6M09Target3.ResetTarget(true);
		UnCaptureEvent(building6M09Target3);
		building6M09Target4.ResetTarget(true);
		UnCaptureEvent(building6M09Target4);
		building6M09Target5.ResetTarget(true);
		UnCaptureEvent(building6M09Target5);
		building6M10Target1.ResetTarget(true);
		UnCaptureEvent(building6M10Target1);
		building6M10Target2.ResetTarget(true);
		UnCaptureEvent(building6M10Target2);
		building6M11Target1.ResetTarget(true);
		UnCaptureEvent(building6M11Target1);
		building6M11Target2.ResetTarget(true);
		UnCaptureEvent(building6M11Target2);
		building6M12Target1.ResetTarget(true);
		UnCaptureEvent(building6M12Target1);
		building6M12Target2.ResetTarget(true);
		UnCaptureEvent(building6M12Target2);
		building6M13Target1.ResetTarget(true);
		UnCaptureEvent(building6M13Target1);
		building6M13Target2.ResetTarget(true);
		UnCaptureEvent(building6M13Target2);
		building6M13Target3.ResetTarget(true);
		UnCaptureEvent(building6M13Target3);
		building6M13Target4.ResetTarget(true);
		UnCaptureEvent(building6M13Target4);
		building6M13Target5.ResetTarget(true);
		UnCaptureEvent(building6M13Target5);
		building6M13Target6.ResetTarget(true);
		UnCaptureEvent(building6M13Target6);
		building6M14Target1.ResetTarget(true);
		UnCaptureEvent(building6M14Target1);
		building6M14Target2.ResetTarget(true);
		UnCaptureEvent(building6M14Target2);
		ChangeState("NoBuildingActive");
	}
}
*/

/*
State NoBuildingActive
{
	Function BeginState()
	{
	}
}
*/

bool AEL_ES2McKenna::DecoMesh_Damaged(ADecoMesh* NotifyActor, AActor* aInstigator, FString Parms)
{
	return true;
}

bool AEL_ES2McKenna::Pawn_Custom(APawn* NotifyActor, AActor* aInstigator, FString Parms)
{
	return true;
}

bool AEL_ES2McKenna::AGP_Pawn_Custom(AAGP_Pawn* NotifyActor, AActor* aInstigator, FString Parms)
{
	return true;
}

bool AEL_ES2McKenna::AGP_Character_Custom(AAGP_Character* NotifyActor, AActor* aInstigator, FString Parms)
{
	return true;
}

bool AEL_ES2McKenna::AGP_Weapon_Throw(AAGP_Weapon* NotifyActor, AActor* aInstigator, FString Parms)
{
	return true;
}

bool AEL_ES2McKenna::Pickup_PickedUp(APickup* NotifyActor, AActor* aInstigator, FString Parms)
{
	AAGP_Weapon* weap = nullptr;
	APickup* pick = nullptr;
	FVector weapLocation = FVector(0, 0, 0);
	FRotator weapRotation = FRotator(0, 0, 0);
	/*
	SetCustomTimer(0.1, false, "doCantDrop");
	if (NotifyActor->IsA(APickupW_M9_Pistol::StaticClass()) || NotifyActor->IsA(APickupW_M4A1_Rifle_Mod::StaticClass()))
	{
		if (aInstigator->IsA(APawn::StaticClass()))
		{
			weap = Cast<AAGP_Weapon>(Cast<APawn>(aInstigator).FindInventoryType(AWeapon_M9_Pistol::StaticClass()));
			if (weap != nullptr)
			{
				weap.PickupClass = APickupW_M9_Pistol::StaticClass();
				weapLocation = w_m9.Location;
				weapRotation = w_m9.Rotation;
				pick = weap.DropFrom(weapLocation);
				pick.SetEventLab(this);
				pick.SetRotation(weapRotation);
				if (weap.PickupClass == nullptr)
				{
				}
				weap = Cast<AAGP_Weapon>(Cast<APawn>(aInstigator).FindInventoryType(AWeapon_M9_Pistol::StaticClass()));
			}
			weap = Cast<AAGP_Weapon>(Cast<APawn>(aInstigator).FindInventoryType(AWeapon_M4A1_Rifle_Mod::StaticClass()));
			if (weap != nullptr)
			{
				weap.PickupClass = APickupW_M4A1_Rifle_Mod::StaticClass();
				weapLocation = w_m4a1.Location;
				weapRotation = w_m4a1.Rotation;
				pick = weap.DropFrom(weapLocation);
				pick.SetEventLab(this);
				pick.SetRotation(weapRotation);
				if (weap.PickupClass == nullptr)
				{
				}
				weap = Cast<AAGP_Weapon>(Cast<APawn>(aInstigator).FindInventoryType(AWeapon_M4A1_Rifle_Mod::StaticClass()));
			}
			doorTrigger1.SetLocked(false);
		}
	}
	*/
	return true;
}

bool AEL_ES2McKenna::AGP_Weapon_Fire(AAGP_Weapon* NotifyActor, AActor* aInstigator, FString Parms)
{
	/*
	if (Parms == "FIRE")
	{
		if (NotifyActor->IsA(ATraceWeapon::StaticClass()))
		{
			roundsFired++;
			DebugLog(DEBUG_EventLab, "+++++++++++++++++ Rounds Fired:" @ FString::FromInt(roundsFired));
		}
		if (!bNoSecurityViolation)
		{
			SecurityViolation();
		}
	}
	else
	{
		if (((Parms == "FIREEMPTY") && (!NotifyActor.HasAmmo())) && bCanRunOutOfAmmo)
		{
			bCanRunOutOfAmmo = false;
			FadeOutBlack(float(AmmoFadeTime));
			SetCustomTimer(float(AmmoFadeTime), false, 'OutOfAmmoFadeIn');
		}
	}
	*/
	return true;
}

void AEL_ES2McKenna::doCantDrop()
{
	AAGP_Weapon* weap = nullptr;
	/*
	weap = Cast<AAGP_Weapon>(Player.FindInventoryType(AWeapon_M9_Pistol::StaticClass()));
	weap.PickupClass = nullptr;
	weap = Cast<AAGP_Weapon>(Player.FindInventoryType(AWeapon_M4A1_Rifle_Mod::StaticClass()));
	weap.PickupClass = nullptr;
	*/
}

bool AEL_ES2McKenna::AGP_Character_Died(AAGP_Character* NotifyActor, AController* aInstigator)
{
	/*
	FadeOut(0.5, true);
	SetCustomTimer(0.6, false, 'RestartLevel');
	*/
	return true;
}

void AEL_ES2McKenna::Leavenworth()
{
	//ConsoleCommand("open leavenworth");
}

bool AEL_ES2McKenna::Pawn_Damaged(APawn* NotifyActor, AController* aInstigator)
{
	/*
	FadeOut(0.5, true);
	SetCustomTimer(0.5, false, 'Leavenworth');
	*/
	return true;
}

void AEL_ES2McKenna::SecurityViolation()
{
	/*
	float Time = 0;
	if (bWarnedPlay)
	{
		return;
	}
	if (!bWarned)
	{
		PlayTip("Do not engage your weapons outside of the Training Area.", "This is your first and only warning", 4);
		Time = PlayGameSound('m_ls0', Player);
		SetCustomTimer(Time, false, 'SecurityViolationPart2');
		bWarned = true;
	}
	else
	{
		if (bLastViolation)
		{
			PlayerLock(true, false);
			PlayTip("Soldier, you have violated the rules of engagement for this exercise.", "You are a NO-GO and will have to restart this mission", 4);
			SetCustomTimer(PlayGameSound('m_ls3', Player), false, 'SecurityViolationPart2');
			Disable('SecurityViolation');
		}
	}
	bWarnedPlay = true;
	*/
}

void AEL_ES2McKenna::SecurityViolationPart2()
{
	if (bLastViolation)
	{
		FadeOut(0.5, true);
		//SetCustomTimer(0.5, false, 'RestartLevel');
	}
	bWarnedPlay = false;
	bLastViolation = true;
}

void AEL_ES2McKenna::JumpToAAR()
{
	/*
	PlayerLock(true, false);
	FadeOutBlack(float(AmmoFadeTime));
	SetCustomTimer(float(AmmoFadeTime), false, 'JumpToAARFadeIn');
	*/
}

void AEL_ES2McKenna::JumpToAARFadeIn()
{
	/*
	FadeInBlack(float(AmmoFadeTime));
	ChangeState('AAR');
	Player.SetLocation(aarLocation.Location);
	Player.Controller.SetRotation(aarLocation.Rotation);
	holsterweapon();
	RemoveWeapons();
	*/
}

void AEL_ES2McKenna::OutOfAmmoFadeIn()
{
	ChangeState("OutOfAmmo","");
}

void AEL_ES2McKenna::OutOfTime()
{
	if (bCanRunOutOfAmmo)
	{
		PlayerLock(true, false);
		PlayTip("Soldier, you have failed to meet the minimun standards for this training exercise.", "You are a NO-GO.", 4);
		FadeOut(5, true);
		//SetCustomTimer(5, false, 'RestartLevel');
	}
}

void AEL_ES2McKenna::PlayKeepMoving()
{
	//PlayGameSound('m_ls2', Player);
}

void AEL_ES2McKenna::CheckPlayerMove()
{
	/*
	if ((Player.Location == PlayerLocation) && (Player.Rotation == PlayerRotation))
	{
		if (bHaveNotMoved)
		{
			ConsoleCommand("disconnect");
		}
		else
		{
			bHaveNotMoved = true;
			PlayKeepMoving();
		}
	}
	else
	{
		PlayerLocation = Player.Location;
		PlayerRotation = Player.Rotation;
		bHaveNotMoved = false;
	}
	SetCustomTimer(20, false, 'CheckPlayerMove');
	*/
}

void AEL_ES2McKenna::PlayIEDDialog()
{
	//PlayGameSound('VoiceGuy_TriggerIED01', Player, , 1.5);
}

void AEL_ES2McKenna::RestartLevel()
{
	//ConsoleCommand("Reconnect");
}

void AEL_ES2McKenna::PreInit()
{
	/*
	aarLocation = Cast<AAGP_DumbEndPoint>(CaptureEvent('NoAmmoFadeTarget'));
	cadreUseTrigger1 = Cast<AAGP_UseTrigger>(CaptureEvent('cadreUseTrigger1'));
	cadreUseTrigger2 = Cast<AAGP_UseTrigger>(CaptureEvent('cadreUseTrigger2'));
	skipVOTrigger = Cast<AAGP_UseTrigger>(CaptureEvent('skipVOTrigger'));
	inspectUseTrigger = Cast<AAGP_UseTrigger>(CaptureEvent('inspectTargetUseTrigger'));
	sbUseTrigger = Cast<AAGP_UseTrigger>(CaptureEvent('sbUseTrigger'));
	startGate1 = Cast<AMover>(CaptureEvent('GateDoor1'));
	doorTrigger1 = Cast<ADoorTrigger>(CaptureEvent('doorTrigger1'));
	w_m4a1 = Cast<APickup>(CaptureEvent('w_m4a1'));
	w_m9 = Cast<APickup>(CaptureEvent('w_m9'));
	building1Trigger1 = Cast<ATriggerVolume>(CaptureEvent('ExitBuilding1Trigger01'));
	building1Trigger2 = Cast<ATriggerVolume>(CaptureEvent('EnterBuilding1Trigger01'));
	building1Trigger3 = Cast<ATriggerVolume>(CaptureEvent('ExitBuilding1Trigger02'));
	building1Trigger4 = Cast<ATriggerVolume>(CaptureEvent('EnterBuilding1Trigger02'));
	building2Trigger1 = Cast<ATriggerVolume>(CaptureEvent('ExitBuilding2Trigger01'));
	building2Trigger2 = Cast<ATriggerVolume>(CaptureEvent('EnterBuilding2Trigger01'));
	building2Trigger3 = Cast<ATriggerVolume>(CaptureEvent('ExitBuilding2Trigger02'));
	building2Trigger4 = Cast<ATriggerVolume>(CaptureEvent('EnterBuilding2Trigger02'));
	building3Trigger1 = Cast<ATriggerVolume>(CaptureEvent('ExitBuilding3Trigger01'));
	building3Trigger2 = Cast<ATriggerVolume>(CaptureEvent('EnterBuilding3Trigger01'));
	building3Trigger3 = Cast<ATriggerVolume>(CaptureEvent('ExitBuilding3Trigger02'));
	building3Trigger4 = Cast<ATriggerVolume>(CaptureEvent('EnterBuilding3Trigger02'));
	building3Trigger5 = Cast<ATriggerVolume>(CaptureEvent('ExitBuilding3Trigger03'));
	building3Trigger6 = Cast<ATriggerVolume>(CaptureEvent('EnterBuilding3Trigger03'));
	building4Trigger3 = Cast<ATriggerVolume>(CaptureEvent('ExitBuilding4Trigger02'));
	building4Trigger4 = Cast<ATriggerVolume>(CaptureEvent('EnterBuilding4Trigger02'));
	building4Trigger5 = Cast<ATriggerVolume>(CaptureEvent('ExitBuilding4Trigger03'));
	building4Trigger6 = Cast<ATriggerVolume>(CaptureEvent('EnterBuilding4Trigger03'));
	building5Trigger1 = Cast<ATriggerVolume>(CaptureEvent('ExitBuilding5Trigger01'));
	building5Trigger2 = Cast<ATriggerVolume>(CaptureEvent('EnterBuilding5Trigger01'));
	building5Trigger3 = Cast<ATriggerVolume>(CaptureEvent('ExitBuilding5Trigger02'));
	building5Trigger4 = Cast<ATriggerVolume>(CaptureEvent('EnterBuilding5Trigger02'));
	building5Trigger5 = Cast<ATriggerVolume>(CaptureEvent('ExitBuilding5Trigger03'));
	building5Trigger6 = Cast<ATriggerVolume>(CaptureEvent('EnterBuilding5Trigger03'));
	building5Trigger7 = Cast<ATriggerVolume>(CaptureEvent('ExitBuilding5Trigger04'));
	building5Trigger8 = Cast<ATriggerVolume>(CaptureEvent('EnterBuilding5Trigger04'));
	building6Trigger3 = Cast<ATriggerVolume>(CaptureEvent('ExitBuilding6Trigger02'));
	building6Trigger4 = Cast<ATriggerVolume>(CaptureEvent('EnterBuilding6Trigger02'));
	building6Trigger5 = Cast<ATriggerVolume>(CaptureEvent('ExitBuilding6Trigger03'));
	building6Trigger6 = Cast<ATriggerVolume>(CaptureEvent('EnterBuilding6Trigger03'));
	Objective01_lethal = Cast<ATrigger>(CaptureEvent('Objective01_c_moverb'));
	Objective02_lethal = Cast<ATrigger>(CaptureEvent('Objective02_c_moverb'));
	Objective04_lethal = Cast<ATrigger>(CaptureEvent('Objective04_c_moverb'));
	Objective05_lethal = Cast<ATrigger>(CaptureEvent('Objective05_c_moverb'));
	Objective06_lethal = Cast<ATrigger>(CaptureEvent('Objective06_c_moverb'));
	Objective07_lethal = Cast<ATrigger>(CaptureEvent('Objective07_c_moverb'));
	Objective08_lethal = Cast<ATrigger>(CaptureEvent('Objective08_c_moverb'));
	Objective09_lethal = Cast<ATrigger>(CaptureEvent('Objective09_c_moverb'));
	Objective10_lethal = Cast<ATrigger>(CaptureEvent('Objective10_c_moverb'));
	Objective11_lethal = Cast<ATrigger>(CaptureEvent('Objective11_c_moverb'));
	Objective12_lethal = Cast<ATrigger>(CaptureEvent('Objective12_c_moverb'));
	OutdoorIED01b_lethal = Cast<ATrigger>(CaptureEvent('OutdoorIED01b'));
	OutdoorIED02b_lethal = Cast<ATrigger>(CaptureEvent('OutdoorIED02b'));
	OutdoorIED03b_lethal = Cast<ATrigger>(CaptureEvent('OutdoorIED03b'));
	IEDObjective01 = Cast<AAGP_Objective>(CaptureEvent('ES2_Objective01_c'));
	IEDObjective02 = Cast<AAGP_Objective>(CaptureEvent('ES2_Objective02_c'));
	IEDObjective04 = Cast<AAGP_Objective>(CaptureEvent('ES2_Objective04_c'));
	IEDObjective05 = Cast<AAGP_Objective>(CaptureEvent('ES2_Objective05_c'));
	IEDObjective06 = Cast<AAGP_Objective>(CaptureEvent('ES2_Objective06_c'));
	IEDObjective07 = Cast<AAGP_Objective>(CaptureEvent('ES2_Objective07_c'));
	IEDObjective08 = Cast<AAGP_Objective>(CaptureEvent('ES2_Objective08_c'));
	IEDObjective09 = Cast<AAGP_Objective>(CaptureEvent('ES2_Objective09_c'));
	IEDObjective10 = Cast<AAGP_Objective>(CaptureEvent('ES2_Objective10_c'));
	IEDObjective11 = Cast<AAGP_Objective>(CaptureEvent('ES2_Objective11_c'));
	IEDObjective12 = Cast<AAGP_Objective>(CaptureEvent('ES2_Objective12_c'));
	triggerES2Objects = Cast<ATriggerVolume>(CaptureEvent('triggerES2Objects'));
	triggerAARUpdate = Cast<ATriggerVolume>(CaptureEvent('triggerAARUpdate'));
	StartGateVO = Cast<ATriggerVolume>(CaptureEvent('StartGateVO'));
	TextDisplay = Cast<ATextDisplay>(GetActor('aarDisplay'));
	cadreUseTip1 = cadreUseTrigger1.HUDText;
	cadreUseTip2 = cadreUseTrigger2.HUDText;
	inspectUseTip = inspectUseTrigger.HUDText;
	doCantTouch();
	*/
}

void AEL_ES2McKenna::flipDoor1Targets()
{
}

void AEL_ES2McKenna::flipDoor2Targets()
{
}

void AEL_ES2McKenna::PostPostInit()
{
	AHumanController* hcIter = nullptr;
	AAGP_CoopESSObjective* essIter = nullptr;
	/*
	UserName = Controller.UserName;
	dateToday = FString::FromInt(Level.Year) + "/";
	if (Level.Month < 10)
	{
		(dateToday += "0");
	}
	(dateToday += FString::FromInt(Level.Month) + "/");
	if (Level.Day < 10)
	{
		(dateToday += "0");
	}
	(dateToday += FString::FromInt(Level.Day));
	opforHit = 0;
	opforHitScore = 0;
	friendlyHit = 0;
	friendlyHitScore = 0;
	roundsFired = 0;
	Accuracy = 0;
	accuracyScore = 0;
	timeOverall = "00:00";
	timeOverallScore = 0;
	TotalScore = 0;
	finalNoGo = "";
	finalGo = "";
	ES2objectsFound = 0;
	ES2Score = 0;
	TextDisplay.SetValue('aTotalScore', FString::FromInt(TotalScore));
	TextDisplay.SetValue('aUserName', UserName);
	TextDisplay.SetValue('aDateToday', dateToday);
	TextDisplay.SetValue('aOpforHit', FString::FromInt(opforHit));
	TextDisplay.SetValue('aFriendlyHit', FString::FromInt(friendlyHit));
	TextDisplay.SetValue('aOpforHitScore', FString::FromInt(opforHitScore));
	TextDisplay.SetValue('aFriendlyHitScore', FString::FromInt(friendlyHitScore));
	TextDisplay.SetValue('aRoundsFired', FString::FromInt(int((Accuracy * float(100)))) + "%");
	TextDisplay.SetValue('aRoundsFiredScore', FString::FromInt(accuracyScore));
	TextDisplay.SetValue('aTimeOverall', timeOverall);
	TextDisplay.SetValue('aTimeOverallScore', FString::FromInt(timeOverallScore));
	TextDisplay.SetValue('aFinalGo', finalGo);
	TextDisplay.SetValue('aFinalNoGo', finalNoGo);
	TextDisplay.SetValue('aES2ObjectsTotal', FString::FromInt(ES2objectsFound));
	TextDisplay.SetValue('aES2ObjectsScore', FString::FromInt(ES2Score));
	cadreInstructor = AGP_Character_NPC(CaptureEvent('cadreInstructor', AAGP_Character_NPC::StaticClass()));
	cadreAAR = AGP_Character_NPC(CaptureEvent('cadreAAR', AAGP_Character_NPC::StaticClass()));
	cadreInstructor.SetCollisionSize(cadreInstructor.CollisionRadius, 41);
	cadreAAR.SetCollisionSize(cadreInstructor.CollisionRadius, 41);
	CapturePlayer();
	FadeIn(6, true);
	cadreInstructor.LoopAnim('DrillIdle');
	cadreAAR.LoopAnim('DrillIdle');
	doorTrigger1.SetLocked(true);
	PlayerLock(false, false);
	Controller.MPCheat_NVG();
	ForEach AllActors(AHumanController::StaticClass(), hcIter)
	{
		if (hcIter != nullptr)
		{
			hcIter.SetEventLab(this);
		}
	}
	ForEach AllActors(AAGP_CoopESSObjective::StaticClass(), essIter)
	{
		if (essIter != nullptr)
		{
			essIter.SetEventLab(this);
		}
	}
	SetCrossHairColor('Yellow');
	EnableCrosshair();
	ChangeState('Briefing');
	*/
}

void AEL_ES2McKenna::doCantTouch()
{
	APickup* CantTouch = nullptr;
	/*
	ForEach AllActors(APickup::StaticClass(), CantTouch)
	{
		if (CantTouch.Tag == 'CantTouchThis')
		{
			CantTouch.SetEventLab(this);
			CantTouch.InventoryType = nullptr;
		}
		else
		{
			if (CantTouch.Tag == 'PickupT_M84_Stun')
			{
				CantTouch.SetEventLab(this);
			}
		}
	}
	*/
}

void AEL_ES2McKenna::RemoveWeapons()
{
	/*
	if (Cast<AAGP_Pawn>(Controller.Pawn).FindInventoryType(AWeapon_M4A1_Rifle_Mod::StaticClass()) != nullptr)
	{
		sWeaponAtCompletion = "M4A1";
	}
	else
	{
		if (Cast<AAGP_Pawn>(Controller.Pawn).FindInventoryType(AWeapon_M9_Pistol::StaticClass()) != nullptr)
		{
			sWeaponAtCompletion = "M9";
		}
		else
		{
			sWeaponAtCompletion = "Unknown";
		}
	}
	Cast<AAGP_Pawn>(Controller.Pawn).EmptyInventory();
	*/
}

bool AEL_ES2McKenna::AGP_UseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	/*
	DebugLog(DEBUG_EventLab, "AGP Trigger: " + FString::FromInt(Trigger));
	switch (Trigger.Tag)
	{
	case 'cadreUseTrigger1':
		return cadreUseTrigger1_UsedBy(Trigger, aInstigator);
	case 'cadreUseTrigger2':
		return cadreUseTrigger2_UsedBy(Trigger, aInstigator);
	case 'skipVOTrigger':
		return skipVOTrigger_UsedBy(Trigger, aInstigator);
	case 'inspectTargetUseTrigger':
		return inspectUseTrigger_UsedBy(Trigger, aInstigator);
	case 'sbUseTrigger':
		return sbUseTrigger_UsedBy(Trigger, aInstigator);
	default:
		return true;
	}
	*/
	return false;    //FAKE   /EliZ
}

bool AEL_ES2McKenna::inspectUseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	//PlayTip("Study these enemy targets carefully.", "They're the only valid targets in the Training Course!", 4);
	return true;
}

bool AEL_ES2McKenna::DoorTrigger_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case 'doorTrigger1':
		return doorTrigger1_UsedBy(Trigger, aInstigator);
	default:
		return false;
	}
	*/
return false;   //FAKE   /ELIZ
}

bool AEL_ES2McKenna::triggerES2Objects_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	if (!courseEntered)
	{
		courseEntered = true;
		StartClock(600, true);
		doorTrigger1.Close();
		ChangeState('NoBuildingActive');
		TriggerEvent('es2training_startobjective', this, Player);
		bNoSecurityViolation = true;
		bCanRunOutOfAmmo = true;
		SetCustomTimer((10 * float(60)), false, 'OutOfTime');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::triggerAARUpdate_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	if (courseEntered)
	{
		holsterweapon();
		RemoveWeapons();
		//StopCustomTimer("CheckPlayerMove");
		//StopCustomTimer("OutOfTime");
		doorTrigger1->Close();
		doorTrigger1->SetLocked(true);
		aarScoreboard();
		ChangeState("AAR","");
	}
	return true;
}

bool AEL_ES2McKenna::StartGateVO_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::PlayerHasWeapon(APawn* aPlayer)
{
	/*
	if (aPlayer.FindInventoryType(ATraceWeapon::StaticClass()) != nullptr)
	{
		return true;
	}
	*/
	return false;
}

bool AEL_ES2McKenna::doorTrigger1_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator)
{
	APickup* CantTouch = nullptr;
	/*
	if (GetStateName() == 'Briefing')
	{
		ForEach AllActors(APickup::StaticClass(), CantTouch)
		{
			if ((CantTouch.Tag == 'w_m4a1') || (CantTouch.Tag == 'w_m9'))
			{
				CantTouch.InventoryType = nullptr;
			}
		}
	}
	*/
	return true;
}

bool AEL_ES2McKenna::cadreUseTrigger1_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::cadreUseTrigger2_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::sbUseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return true;
}

void AEL_ES2McKenna::holsterweapon()
{
	//Weapon(Player.getHandsInventory()).PutDown();
}

bool AEL_ES2McKenna::Timer_Timer(FName Name)
{
	//return Super::Timer_Timer(Name);
	return false;   //FAKE   /EliZ
}

bool AEL_ES2McKenna::Timer_Sound(FName Name)
{
	return true;
}

bool AEL_ES2McKenna::aarScoreboard()
{
	/*
	int32 totalCourseTime = 0;
	float timeScoreRatio = 0;
	StopClock();
	roundsRemaining = (90 - roundsFired);
	Accuracy = (float(opforHit) / float(roundsFired));
	if ((Accuracy > 0.5) && (Accuracy <= 0.6))
	{
		accuracyScore = 200;
	}
	else
	{
		if ((Accuracy > 0.6) && (Accuracy <= 0.7))
		{
			accuracyScore = 400;
		}
		else
		{
			if ((Accuracy > 0.7) && (Accuracy <= 0.8))
			{
				accuracyScore = 600;
			}
			else
			{
				if ((Accuracy > 0.8) && (Accuracy <= 0.9))
				{
					accuracyScore = 800;
				}
				else
				{
					if ((Accuracy > 0.9) && (Accuracy < 1))
					{
						accuracyScore = 1000;
					}
					else
					{
						if (Accuracy == 1)
						{
							accuracyScore = 1500;
						}
						else
						{
							accuracyScore = 0;
						}
					}
				}
			}
		}
	}
	totalCourseTime = (600 - GetClockSeconds());
	timeOverall = FormatTime(float(totalCourseTime));
	if (totalCourseTime < 420)
	{
		timeScoreRatio = ((420 - float(totalCourseTime)) / float(420));
		timeOverallScore = int((float(5000) * timeScoreRatio));
	}
	else
	{
		if (totalCourseTime >= 420)
		{
			timeScoreRatio = (float((totalCourseTime - 420)) / float((600 - 420)));
			timeOverallScore = int((float(-3000) * timeScoreRatio));
		}
		else
		{
			timeOverallScore = 0;
		}
	}
	if (friendlyHit == 0)
	{
		friendlyHitScore = 1000;
	}
	TotalScore = ((((opforHitScore + friendlyHitScore) + accuracyScore) + timeOverallScore) + ES2Score);
	if (TotalScore >= 10000)
	{
		finalGo = "X";
		finalNoGo = "";
	}
	else
	{
		finalNoGo = "X";
		finalGo = "";
	}
	TextDisplay.SetValue('aTotalScore', FString::FromInt(TotalScore));
	TextDisplay.SetValue('aUserName', UserName);
	TextDisplay.SetValue('aDateToday', dateToday);
	TextDisplay.SetValue('aOpforHit', FString::FromInt(opforHit));
	TextDisplay.SetValue('aFriendlyHit', FString::FromInt(friendlyHit));
	TextDisplay.SetValue('aOpforHitScore', FString::FromInt(opforHitScore));
	TextDisplay.SetValue('aFriendlyHitScore', FString::FromInt(friendlyHitScore));
	TextDisplay.SetValue('aRoundsFired', FString::FromInt(int((Accuracy * float(100)))) + "%");
	TextDisplay.SetValue('aRoundsFiredScore', FString::FromInt(accuracyScore));
	TextDisplay.SetValue('aTimeOverall', timeOverall);
	TextDisplay.SetValue('aTimeOverallScore', FString::FromInt(timeOverallScore));
	TextDisplay.SetValue('aFinalGo', finalGo);
	TextDisplay.SetValue('aFinalNoGo', finalNoGo);
	TextDisplay.SetValue('aES2ObjectsTotal', FString::FromInt(ES2objectsFound));
	TextDisplay.SetValue('aES2ObjectsScore', FString::FromInt(ES2Score));
	*/
	return true;
}

bool AEL_ES2McKenna::Trigger_Entered(ATrigger* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case 'Objective01_c_moverb':
		return Objective01_lethal_Enter(Trigger, aInstigator);
	case 'Objective02_c_moverb':
		return Objective02_lethal_Enter(Trigger, aInstigator);
	case 'Objective04_c_moverb':
		return Objective04_lethal_Enter(Trigger, aInstigator);
	case 'Objective05_c_moverb':
		return Objective05_lethal_Enter(Trigger, aInstigator);
	case 'Objective06_c_moverb':
		return Objective06_lethal_Enter(Trigger, aInstigator);
	case 'Objective07_c_moverb':
		return Objective07_lethal_Enter(Trigger, aInstigator);
	case 'Objective08_c_moverb':
		return Objective08_lethal_Enter(Trigger, aInstigator);
	case 'Objective09_c_moverb':
		return Objective09_lethal_Enter(Trigger, aInstigator);
	case 'Objective10_c_moverb':
		return Objective10_lethal_Enter(Trigger, aInstigator);
	case 'Objective11_c_moverb':
		return Objective11_lethal_Enter(Trigger, aInstigator);
	case 'Objective12_c_moverb':
		return Objective12_lethal_Enter(Trigger, aInstigator);
	case 'OutdoorIED01b':
		return OutdoorIED01b_lethal_Enter(Trigger, aInstigator);
	case 'OutdoorIED02b':
		return OutdoorIED02b_lethal_Enter(Trigger, aInstigator);
	case 'OutdoorIED03b':
		return OutdoorIED03b_lethal_Enter(Trigger, aInstigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /EliZ
}

bool AEL_ES2McKenna::TriggerVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case 'ExitBuilding1Trigger01':
		return building1Trigger1_Enter(Trigger, aInstigator);
	case 'EnterBuilding1Trigger01':
		return building1Trigger2_Enter(Trigger, aInstigator);
	case 'ExitBuilding1Trigger02':
		return building1Trigger3_Enter(Trigger, aInstigator);
	case 'EnterBuilding1Trigger02':
		return building1Trigger4_Enter(Trigger, aInstigator);
	case 'ExitBuilding2Trigger01':
		return building2Trigger1_Enter(Trigger, aInstigator);
	case 'EnterBuilding2Trigger01':
		return building2Trigger2_Enter(Trigger, aInstigator);
	case 'ExitBuilding2Trigger02':
		return building2Trigger3_Enter(Trigger, aInstigator);
	case 'EnterBuilding2Trigger02':
		return building2Trigger4_Enter(Trigger, aInstigator);
	case 'ExitBuilding3Trigger01':
		return building3Trigger1_Enter(Trigger, aInstigator);
	case 'EnterBuilding3Trigger01':
		return building3Trigger2_Enter(Trigger, aInstigator);
	case 'ExitBuilding3Trigger02':
		return building3Trigger3_Enter(Trigger, aInstigator);
	case 'EnterBuilding3Trigger02':
		return building3Trigger4_Enter(Trigger, aInstigator);
	case 'ExitBuilding3Trigger03':
		return building3Trigger5_Enter(Trigger, aInstigator);
	case 'EnterBuilding3Trigger03':
		return building3Trigger6_Enter(Trigger, aInstigator);
	case 'ExitBuilding4Trigger02':
		return building4Trigger3_Enter(Trigger, aInstigator);
	case 'EnterBuilding4Trigger02':
		return building4Trigger4_Enter(Trigger, aInstigator);
	case 'ExitBuilding4Trigger03':
		return building4Trigger5_Enter(Trigger, aInstigator);
	case 'EnterBuilding4Trigger03':
		return building4Trigger6_Enter(Trigger, aInstigator);
	case 'ExitBuilding5Trigger01':
		return building5Trigger1_Enter(Trigger, aInstigator);
	case 'EnterBuilding5Trigger01':
		return building5Trigger2_Enter(Trigger, aInstigator);
	case 'ExitBuilding5Trigger02':
		return building5Trigger3_Enter(Trigger, aInstigator);
	case 'EnterBuilding5Trigger02':
		return building5Trigger4_Enter(Trigger, aInstigator);
	case 'ExitBuilding5Trigger03':
		return building5Trigger5_Enter(Trigger, aInstigator);
	case 'EnterBuilding5Trigger03':
		return building5Trigger6_Enter(Trigger, aInstigator);
	case 'ExitBuilding5Trigger04':
		return building5Trigger7_Enter(Trigger, aInstigator);
	case 'EnterBuilding5Trigger04':
		return building5Trigger8_Enter(Trigger, aInstigator);
	case 'ExitBuilding6Trigger02':
		return building6Trigger3_Enter(Trigger, aInstigator);
	case 'EnterBuilding6Trigger02':
		return building6Trigger4_Enter(Trigger, aInstigator);
	case 'ExitBuilding6Trigger03':
		return building6Trigger5_Enter(Trigger, aInstigator);
	case 'EnterBuilding6Trigger03':
		return building6Trigger6_Enter(Trigger, aInstigator);
	case 'Building1MT_Trigger02AB':
		return Building1MT_Trigger02AB_Enter(Trigger, aInstigator);
	case 'Building1MT_Trigger06AB':
		return Building1MT_Trigger06AB_Enter(Trigger, aInstigator);
	case 'Building1MT_Trigger02B':
		return Building1MT_Trigger02B_Enter(Trigger, aInstigator);
	case 'Building2MT_Trigger07B':
		return Building2MT_Trigger07B_Enter(Trigger, aInstigator);
	case 'Building2MT_Trigger08A':
		return Building2MT_Trigger08A_Enter(Trigger, aInstigator);
	case 'Building2MT_Trigger09A':
		return Building2MT_Trigger09A_Enter(Trigger, aInstigator);
	case 'Building2MT_Trigger10A':
		return Building2MT_Trigger10A_Enter(Trigger, aInstigator);
	case 'Building2MT_Trigger11A':
		return Building2MT_Trigger11A_Enter(Trigger, aInstigator);
	case 'Building2MT_Trigger12A':
		return Building2MT_Trigger12A_Enter(Trigger, aInstigator);
	case 'Building2MT_Trigger05B':
		return Building2MT_Trigger05B_Enter(Trigger, aInstigator);
	case 'Building2MT_Trigger04B':
		return Building2MT_Trigger04B_Enter(Trigger, aInstigator);
	case 'Building2MT_Trigger03B':
		return Building2MT_Trigger03B_Enter(Trigger, aInstigator);
	case 'Building2MT_Trigger02B':
		return Building2MT_Trigger02B_Enter(Trigger, aInstigator);
	case 'Building3MT_Trigger02ABC':
		return Building3MT_Trigger02ABC_Enter(Trigger, aInstigator);
	case 'Building3MT_Trigger03B':
		return Building3MT_Trigger03B_Enter(Trigger, aInstigator);
	case 'Building3MT_Trigger03ABC':
		return Building3MT_Trigger03ABC_Enter(Trigger, aInstigator);
	case 'Building3MT_Trigger04B':
		return Building3MT_Trigger04B_Enter(Trigger, aInstigator);
	case 'Building3MT_Trigger05B':
		return Building3MT_Trigger05B_Enter(Trigger, aInstigator);
	case 'Building3MT_Trigger06B':
		return Building3MT_Trigger06B_Enter(Trigger, aInstigator);
	case 'Building3MT_Trigger07AB':
		return Building3MT_Trigger07AB_Enter(Trigger, aInstigator);
	case 'Building3MT_Trigger08AB':
		return Building3MT_Trigger08AB_Enter(Trigger, aInstigator);
	case 'Building4MT_Trigger02AB':
		return Building4MT_Trigger02AB_Enter(Trigger, aInstigator);
	case 'Building4MT_Trigger03AB':
		return Building4MT_Trigger03AB_Enter(Trigger, aInstigator);
	case 'Building4MT_Trigger04AB':
		return Building4MT_Trigger04AB_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger01A':
		return Building5MT_Trigger01A_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger02ABC':
		return Building5MT_Trigger02ABC_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger03ABC':
		return Building5MT_Trigger03ABC_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger04ABC':
		return Building5MT_Trigger04ABC_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger05ABC':
		return Building5MT_Trigger05ABC_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger06ABC':
		return Building5MT_Trigger06ABC_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger07ABC':
		return Building5MT_Trigger07ABC_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger08ABC':
		return Building5MT_Trigger08ABC_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger09ABC':
		return Building5MT_Trigger09ABC_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger10ABC':
		return Building5MT_Trigger10ABC_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger11ABC':
		return Building5MT_Trigger11ABC_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger12ABCD':
		return Building5MT_Trigger12ABCD_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger13ABCD':
		return Building5MT_Trigger13ABCD_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger14ABCD':
		return Building5MT_Trigger14ABCD_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger15ABCD':
		return Building5MT_Trigger15ABCD_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger16ABCD':
		return Building5MT_Trigger16ABCD_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger17ABCD':
		return Building5MT_Trigger17ABCD_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger18ABCD':
		return Building5MT_Trigger18ABCD_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger19ABCD':
		return Building5MT_Trigger19ABCD_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger20ABCD':
		return Building5MT_Trigger20ABCD_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger21ABCD':
		return Building5MT_Trigger21ABCD_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger22ABCD':
		return Building5MT_Trigger22ABCD_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger23ABCD':
		return Building5MT_Trigger23ABCD_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger24ABCD':
		return Building5MT_Trigger24ABCD_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger25ABCD':
		return Building5MT_Trigger25ABCD_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger26ABCD':
		return Building5MT_Trigger26ABCD_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger27ABCD':
		return Building5MT_Trigger27ABCD_Enter(Trigger, aInstigator);
	case 'Building5MT_Trigger28ABCD':
		return Building5MT_Trigger28ABCD_Enter(Trigger, aInstigator);
	case 'Building6MT_Trigger01B':
		return Building6MT_Trigger01B_Enter(Trigger, aInstigator);
	case 'Building6MT_Trigger02B':
		return Building6MT_Trigger02B_Enter(Trigger, aInstigator);
	case 'Building6MT_Trigger03B':
		return Building6MT_Trigger03B_Enter(Trigger, aInstigator);
	case 'Building6MT_Trigger04B':
		return Building6MT_Trigger04B_Enter(Trigger, aInstigator);
	case 'Building6MT_Trigger05A':
		return Building6MT_Trigger05A_Enter(Trigger, aInstigator);
	case 'Building6MT_Trigger06A':
		return Building6MT_Trigger06A_Enter(Trigger, aInstigator);
	case 'Building6MT_Trigger07A':
		return Building6MT_Trigger07A_Enter(Trigger, aInstigator);
	case 'triggerES2Objects':
		return triggerES2Objects_Enter(Trigger, aInstigator);
	case 'triggerAARUpdate':
		return triggerAARUpdate_Enter(Trigger, aInstigator);
	case 'StartGateVO':
		return StartGateVO_Enter(Trigger, aInstigator);
	default:
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool AEL_ES2McKenna::building1Trigger1_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if (CurrentState == 'building1Active')
	{
		ChangeState('Building1InActive');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building1Trigger2_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if ((CurrentState == 'Building1InActive') || (CurrentState == 'NoBuildingActive'))
	{
		door1Entered = true;
		ChangeState('building1Active');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building1Trigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if (CurrentState == 'building1Active')
	{
		ChangeState('Building1InActive');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building1Trigger4_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if ((CurrentState == 'Building1InActive') || (CurrentState == 'NoBuildingActive'))
	{
		door2Entered = true;
		ChangeState('building1Active');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building2Trigger1_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if (CurrentState == 'Building2Active')
	{
		ChangeState('Building2InActive');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building2Trigger2_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if ((CurrentState == 'Building2InActive') || (CurrentState == 'NoBuildingActive'))
	{
		door1Entered = true;
		ChangeState('Building2Active');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building2Trigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if (CurrentState == 'Building2Active')
	{
		ChangeState('Building2InActive');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building2Trigger4_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if ((CurrentState == 'Building2InActive') || (CurrentState == 'NoBuildingActive'))
	{
		door2Entered = true;
		ChangeState('Building2Active');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building2Trigger5_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if (CurrentState == 'Building2Active')
	{
		ChangeState('Building2InActive');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building2Trigger6_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if ((CurrentState == 'Building2InActive') || (CurrentState == 'NoBuildingActive'))
	{
		door3Entered = true;
		ChangeState('Building2Active');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building3Trigger1_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if (CurrentState == 'Building3Active')
	{
		ChangeState('Building3InActive');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building3Trigger2_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if ((CurrentState == 'Building3InActive') || (CurrentState == 'NoBuildingActive'))
	{
		door1Entered = true;
		ChangeState('Building3Active');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building3Trigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if (CurrentState == 'Building3Active')
	{
		ChangeState('Building3InActive');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building3Trigger4_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if ((CurrentState == 'Building3InActive') || (CurrentState == 'NoBuildingActive'))
	{
		door2Entered = true;
		ChangeState('Building3Active');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building3Trigger5_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if (CurrentState == 'Building3Active')
	{
		ChangeState('Building3InActive');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building3Trigger6_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if ((CurrentState == 'Building3InActive') || (CurrentState == 'NoBuildingActive'))
	{
		door3Entered = true;
		ChangeState('Building3Active');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building4Trigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if (CurrentState == 'Building4Active')
	{
		ChangeState('Building4InActive');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building4Trigger4_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if ((CurrentState == 'Building4InActive') || (CurrentState == 'NoBuildingActive'))
	{
		door1Entered = true;
		ChangeState('Building4Active');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building4Trigger5_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if (CurrentState == 'Building4Active')
	{
		ChangeState('Building4InActive');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building4Trigger6_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if ((CurrentState == 'Building4InActive') || (CurrentState == 'NoBuildingActive'))
	{
		door2Entered = true;
		ChangeState('Building4Active');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building5Trigger1_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if (CurrentState == 'Building5Active')
	{
		ChangeState('Building5InActive');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building5Trigger2_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if ((CurrentState == 'Building5InActive') || (CurrentState == 'NoBuildingActive'))
	{
		door1Entered = true;
		ChangeState('Building5Active');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building5Trigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if (CurrentState == 'Building5Active')
	{
		ChangeState('Building5InActive');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building5Trigger4_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if ((CurrentState == 'Building5InActive') || (CurrentState == 'NoBuildingActive'))
	{
		door2Entered = true;
		ChangeState('Building5Active');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building5Trigger5_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if (CurrentState == 'Building5Active')
	{
		ChangeState('Building5InActive');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building5Trigger6_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if ((CurrentState == 'Building5InActive') || (CurrentState == 'NoBuildingActive'))
	{
		door3Entered = true;
		ChangeState('Building5Active');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building5Trigger7_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if (CurrentState == 'Building5Active')
	{
		ChangeState('Building5InActive');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building5Trigger8_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if ((CurrentState == 'Building5InActive') || (CurrentState == 'NoBuildingActive'))
	{
		door4Entered = true;
		ChangeState('Building5Active');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building6Trigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if (CurrentState == 'Building6Active')
	{
		ChangeState('Building6InActive');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building6Trigger4_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if ((CurrentState == 'Building6InActive') || (CurrentState == 'NoBuildingActive'))
	{
		door1Entered = true;
		ChangeState('Building6Active');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building6Trigger5_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if (CurrentState == 'Building6Active')
	{
		ChangeState('Building6InActive');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building6Trigger6_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	CurrentState = GetStateName();
	if ((CurrentState == 'Building6InActive') || (CurrentState == 'NoBuildingActive'))
	{
		door2Entered = true;
		ChangeState('Building6Active');
	}
	*/
	return true;
}

bool AEL_ES2McKenna::building6Trigger7_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	FName CurrentState = "";
	//CurrentState = GetStateName();
	if (CurrentState == "Building6Active")
	{
		ChangeState("Building6InActive","");
	}
	return true;
}

bool AEL_ES2McKenna::building6Trigger8_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	FName CurrentState = "";
	//CurrentState = GetStateName();
	if ((CurrentState == "Building6InActive") || (CurrentState == "NoBuildingActive"))
	{
		door3Entered = true;
		ChangeState("Building6Active","");
	}
	return true;
}

bool AEL_ES2McKenna::Building1MT_Trigger02AB_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building1MT_Trigger06AB_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building1MT_Trigger02B_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building2MT_Trigger07B_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building2MT_Trigger08A_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building2MT_Trigger09A_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building2MT_Trigger10A_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building2MT_Trigger11A_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building2MT_Trigger12A_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building2MT_Trigger05B_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building2MT_Trigger04B_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building2MT_Trigger03B_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building2MT_Trigger02B_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building3MT_Trigger02ABC_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building3MT_Trigger03B_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building3MT_Trigger03ABC_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building3MT_Trigger04B_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building3MT_Trigger05B_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building3MT_Trigger06B_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building3MT_Trigger07AB_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building3MT_Trigger08AB_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building4MT_Trigger02AB_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building4MT_Trigger03AB_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building4MT_Trigger04AB_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger01A_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger02ABC_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger03ABC_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger04ABC_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger05ABC_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger06ABC_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger07ABC_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger08ABC_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger09ABC_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger10ABC_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger11ABC_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger12ABCD_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger13ABCD_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger14ABCD_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger15ABCD_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger16ABCD_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger17ABCD_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger18ABCD_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger19ABCD_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger20ABCD_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger21ABCD_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger22ABCD_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger23ABCD_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger24ABCD_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger25ABCD_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger26ABCD_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger27ABCD_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building5MT_Trigger28ABCD_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building6MT_Trigger01B_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building6MT_Trigger02B_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building6MT_Trigger03B_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building6MT_Trigger04B_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building6MT_Trigger05A_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building6MT_Trigger06A_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Building6MT_Trigger07A_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::skipVOTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return true;
}

bool AEL_ES2McKenna::Objective01_lethal_Enter(ATrigger* Trigger, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("Objective01_lethal_Enter()"));
	if (!bIndoorIEDTriggered)
	{
		//SetCustomTimer(5.5, false, 'PlayIEDDialog');
		PlayTip("You have lost 500 points from your ES2 Score", "Be more careful when working around dangerous items", 8);
		(ES2Score -= 500);
		//PlayerController(Cast<APawn>(aInstigator).Controller).FlashBanged(5, 1, 1);
		bIndoorIEDTriggered = true;
		DisableAllMTTriggers();
	}
	return true;
}

bool AEL_ES2McKenna::Objective02_lethal_Enter(ATrigger* Trigger, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("Objective02_lethal_Enter()"));
	if (!bIndoorIEDTriggered)
	{
		//SetCustomTimer(5.5, false, 'PlayIEDDialog');
		PlayTip("You have lost 500 points from your ES2 Score", "Be more careful when working around dangerous items", 8);
		(ES2Score -= 500);
		//PlayerController(Cast<APawn>(aInstigator).Controller).FlashBanged(5, 1, 1);
		bIndoorIEDTriggered = true;
		DisableAllMTTriggers();
	}
	return true;
}

bool AEL_ES2McKenna::Objective04_lethal_Enter(ATrigger* Trigger, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("Objective04_lethal_Enter()"));
	if (!bIndoorIEDTriggered)
	{
		//SetCustomTimer(5.5, false, 'PlayIEDDialog');
		PlayTip("You have lost 500 points from your ES2 Score", "Be more careful when working around dangerous items", 8);
		(ES2Score -= 500);
		//PlayerController(Cast<APawn>(aInstigator).Controller).FlashBanged(5, 1, 1);
		bIndoorIEDTriggered = true;
		DisableAllMTTriggers();
	}
	return true;
}

bool AEL_ES2McKenna::Objective05_lethal_Enter(ATrigger* Trigger, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("Objective05_lethal_Enter()"));
	if (!bIndoorIEDTriggered)
	{
		//SetCustomTimer(5.5, false, 'PlayIEDDialog');
		PlayTip("You have lost 500 points from your ES2 Score", "Be more careful when working around dangerous items", 8);
		(ES2Score -= 500);
		//PlayerController(Cast<APawn>(aInstigator).Controller).FlashBanged(5, 1, 1);
		bIndoorIEDTriggered = true;
		DisableAllMTTriggers();
	}
	return true;
}

bool AEL_ES2McKenna::Objective06_lethal_Enter(ATrigger* Trigger, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("Objective06_lethal_Enter()"));
	if (!bIndoorIEDTriggered)
	{
		//SetCustomTimer(5.5, false, 'PlayIEDDialog');
		PlayTip("You have lost 500 points from your ES2 Score", "Be more careful when working around dangerous items", 8);
		(ES2Score -= 500);
		//PlayerController(Cast<APawn>(aInstigator).Controller).FlashBanged(5, 1, 1);
		bIndoorIEDTriggered = true;
		DisableAllMTTriggers();
	}
	return true;
}

bool AEL_ES2McKenna::Objective07_lethal_Enter(ATrigger* Trigger, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("Objective07_lethal_Enter()"));
	if (!bIndoorIEDTriggered)
	{
		//SetCustomTimer(5, false, 'PlayIEDDialog');
		PlayTip("You have lost 500 points from your ES2 Score", "Be more careful when working around dangerous items", 8);
		(ES2Score -= 500);
		//PlayerController(Cast<APawn>(aInstigator).Controller).FlashBanged(5, 1, 1);
		bIndoorIEDTriggered = true;
		DisableAllMTTriggers();
	}
	return true;
}

bool AEL_ES2McKenna::Objective08_lethal_Enter(ATrigger* Trigger, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("Objective08_lethal_Enter()"));
	if (!bIndoorIEDTriggered)
	{
		//SetCustomTimer(5.5, false, 'PlayIEDDialog');
		PlayTip("You have lost 500 points from your ES2 Score", "Be more careful when working around dangerous items", 8);
		(ES2Score -= 500);
		//PlayerController(Cast<APawn>(aInstigator).Controller).FlashBanged(5, 1, 1);
		bIndoorIEDTriggered = true;
		DisableAllMTTriggers();
	}
	return true;
}

bool AEL_ES2McKenna::Objective09_lethal_Enter(ATrigger* Trigger, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("Objective09_lethal_Enter()"));
	if (!bIndoorIEDTriggered)
	{
		//SetCustomTimer(5.5, false, 'PlayIEDDialog');
		PlayTip("You have lost 500 points from your ES2 Score", "Be more careful when working around dangerous items", 8);
		(ES2Score -= 500);
		//PlayerController(Cast<APawn>(aInstigator).Controller).FlashBanged(5, 1, 1);
		bIndoorIEDTriggered = true;
		DisableAllMTTriggers();
	}
	return true;
}

bool AEL_ES2McKenna::Objective10_lethal_Enter(ATrigger* Trigger, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("Objective10_lethal_Enter()"));
	if (!bIndoorIEDTriggered)
	{
		//SetCustomTimer(5.5, false, 'PlayIEDDialog');
		PlayTip("You have lost 500 points from your ES2 Score", "Be more careful when working around dangerous items", 8);
		(ES2Score -= 500);
		//PlayerController(Cast<APawn>(aInstigator).Controller).FlashBanged(5, 1, 1);
		bIndoorIEDTriggered = true;
		DisableAllMTTriggers();
	}
	return true;
}

bool AEL_ES2McKenna::Objective11_lethal_Enter(ATrigger* Trigger, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("Objective11_lethal_Enter()"));
	if (!bIndoorIEDTriggered)
	{
		//SetCustomTimer(5.5, false, 'PlayIEDDialog');
		PlayTip("You have lost 500 points from your ES2 Score", "Be more careful when working around dangerous items", 8);
		(ES2Score -= 500);
		//PlayerController(Cast<APawn>(aInstigator).Controller).FlashBanged(5, 1, 1);
		bIndoorIEDTriggered = true;
		DisableAllMTTriggers();
	}
	return true;
}

bool AEL_ES2McKenna::Objective12_lethal_Enter(ATrigger* Trigger, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("Objective12_lethal_Enter()"));
	if (!bOutdoorIEDTriggered)
	{
		//SetCustomTimer(5.5, false, 'PlayIEDDialog');
		PlayTip("You have lost 500 points from your ES2 Score", "Be more careful when working around dangerous items", 8);
		(ES2Score -= 500);
		//PlayerController(Cast<APawn>(aInstigator).Controller).FlashBanged(5, 1, 1);
		bOutdoorIEDTriggered = true;
		DisableAllMTTriggers();
	}
	return true;
}

bool AEL_ES2McKenna::OutdoorIED01b_lethal_Enter(ATrigger* Trigger, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("OutdoorIED01b_lethal_Enter()"));
	if (!bOutdoorIEDTriggered)
	{
		//SetCustomTimer(5.5, false, 'PlayIEDDialog');
		PlayTip("You have lost 500 points from your ES2 Score", "Be more careful when working around dangerous items", 8);
		(ES2Score -= 500);
		//PlayerController(Cast<APawn>(aInstigator).Controller).FlashBanged(5, 1, 1);
		bOutdoorIEDTriggered = true;
	}
	return true;
}

bool AEL_ES2McKenna::OutdoorIED02b_lethal_Enter(ATrigger* Trigger, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("OutdoorIED02b_lethal_Enter()"));
	if (!bOutdoorIEDTriggered)
	{
		//SetCustomTimer(5.5, false, 'PlayIEDDialog');
		PlayTip("You have lost 500 points from your ES2 Score", "Be more careful when working around dangerous items", 8);
		(ES2Score -= 500);
		//PlayerController(Cast<APawn>(aInstigator).Controller).FlashBanged(5, 1, 1);
		bOutdoorIEDTriggered = true;
	}
	return true;
}

bool AEL_ES2McKenna::OutdoorIED03b_lethal_Enter(ATrigger* Trigger, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("OutdoorIED03b_lethal_Enter()"));
	if (!bOutdoorIEDTriggered)
	{
		//SetCustomTimer(5.5, false, 'PlayIEDDialog');
		PlayTip("You have lost 500 points from your ES2 Score", "Be more careful when working around dangerous items", 8);
		(ES2Score -= 500);
		//PlayerController(Cast<APawn>(aInstigator).Controller).FlashBanged(5, 1, 1);
		bOutdoorIEDTriggered = true;
	}
	return true;
}

bool AEL_ES2McKenna::AGP_Objective_Trigger(AAGP_Objective* NotifyActor, AActor* aInstigator)
{
	/*
	Log("NotifyActor.Tag = " + FString::FromInt(NotifyActor.Tag));
	switch (NotifyActor.Tag)
	{
	case 'ES2_Objective01_c':
		return IEDObjective01_Triggered(NotifyActor, aInstigator);
	case 'ES2_Objective02_c':
		return IEDObjective02_Triggered(NotifyActor, aInstigator);
	case 'ES2_Objective04_c':
		return IEDObjective04_Triggered(NotifyActor, aInstigator);
	case 'ES2_Objective05_c':
		return IEDObjective05_Triggered(NotifyActor, aInstigator);
	case 'ES2_Objective06_c':
		return IEDObjective06_Triggered(NotifyActor, aInstigator);
	case 'ES2_Objective07_c':
		return IEDObjective07_Triggered(NotifyActor, aInstigator);
	case 'ES2_Objective08_c':
		return IEDObjective08_Triggered(NotifyActor, aInstigator);
	case 'ES2_Objective09_c':
		return IEDObjective09_Triggered(NotifyActor, aInstigator);
	case 'ES2_Objective10_c':
		return IEDObjective10_Triggered(NotifyActor, aInstigator);
	case 'ES2_Objective11_c':
		return IEDObjective11_Triggered(NotifyActor, aInstigator);
	case 'ES2_Objective12_c':
		return IEDObjective12_Triggered(NotifyActor, aInstigator);
	default:
		return true;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_ES2McKenna::IEDObjective01_Triggered(AAGP_Objective* NotifyActor, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("IEDObjective01_Triggered"));
	DisableAllMTTriggers();
	return true;
}

bool AEL_ES2McKenna::IEDObjective02_Triggered(AAGP_Objective* NotifyActor, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("IEDObjective02_Triggered"));
	DisableAllMTTriggers();
	return true;
}

bool AEL_ES2McKenna::IEDObjective04_Triggered(AAGP_Objective* NotifyActor, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("IEDObjective04_Triggered"));
	DisableAllMTTriggers();
	return true;
}

bool AEL_ES2McKenna::IEDObjective05_Triggered(AAGP_Objective* NotifyActor, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("IEDObjective05_Triggered"));
	DisableAllMTTriggers();
	return true;
}

bool AEL_ES2McKenna::IEDObjective06_Triggered(AAGP_Objective* NotifyActor, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("IEDObjective06_Triggered"));
	DisableAllMTTriggers();
	return true;
}

bool AEL_ES2McKenna::IEDObjective07_Triggered(AAGP_Objective* NotifyActor, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("IEDObjective07_Triggered"));
	DisableAllMTTriggers();
	return true;
}

bool AEL_ES2McKenna::IEDObjective08_Triggered(AAGP_Objective* NotifyActor, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("IEDObjective08_Triggered"));
	DisableAllMTTriggers();
	return true;
}

bool AEL_ES2McKenna::IEDObjective09_Triggered(AAGP_Objective* NotifyActor, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("IEDObjective09_Triggered"));
	DisableAllMTTriggers();
	return true;
}

bool AEL_ES2McKenna::IEDObjective10_Triggered(AAGP_Objective* NotifyActor, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("IEDObjective10_Triggered"));
	DisableAllMTTriggers();
	return true;
}

bool AEL_ES2McKenna::IEDObjective11_Triggered(AAGP_Objective* NotifyActor, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("IEDObjective11_Triggered"));
	DisableAllMTTriggers();
	return true;
}

bool AEL_ES2McKenna::IEDObjective12_Triggered(AAGP_Objective* NotifyActor, AActor* aInstigator)
{
	UE_LOG(LogTemp, Log, TEXT("IEDObjective12_Triggered"));
	DisableAllMTTriggers();
	return true;
}

void AEL_ES2McKenna::DisableAllMTTriggers()
{
	building1MTTrigger01 = Cast<ATriggerVolume>(CaptureEvent("Building1MT_Trigger02AB",nullptr));
	//building1MTTrigger01->DisableTrigger();
	UnCaptureEvent(building1MTTrigger01);
	building1MTTrigger02 = Cast<ATriggerVolume>(CaptureEvent("Building1MT_Trigger02B",nullptr));
	//building1MTTrigger02->DisableTrigger();
	UnCaptureEvent(building1MTTrigger02);
	building1MTTrigger03 = Cast<ATriggerVolume>(CaptureEvent("Building1MT_Trigger06AB",nullptr));
	//building1MTTrigger03->DisableTrigger();
	UnCaptureEvent(building1MTTrigger03);
	building2MTTrigger01 = Cast<ATriggerVolume>(CaptureEvent("Building2MT_Trigger02B",nullptr));
	//building2MTTrigger01->DisableTrigger();
	UnCaptureEvent(building2MTTrigger01);
	building2MTTrigger02 = Cast<ATriggerVolume>(CaptureEvent("Building2MT_Trigger03B",nullptr));
	//building2MTTrigger02->DisableTrigger();
	UnCaptureEvent(building2MTTrigger02);
	building2MTTrigger03 = Cast<ATriggerVolume>(CaptureEvent("Building2MT_Trigger04B",nullptr));
	//building2MTTrigger03->DisableTrigger();
	UnCaptureEvent(building2MTTrigger03);
	building2MTTrigger04 = Cast<ATriggerVolume>(CaptureEvent("Building2MT_Trigger05B",nullptr));
	//building2MTTrigger04->DisableTrigger();
	UnCaptureEvent(building2MTTrigger04);
	building2MTTrigger05 = Cast<ATriggerVolume>(CaptureEvent("Building2MT_Trigger07B",nullptr));
	//building2MTTrigger05->DisableTrigger();
	UnCaptureEvent(building2MTTrigger05);
	building2MTTrigger06 = Cast<ATriggerVolume>(CaptureEvent("Building2MT_Trigger08A",nullptr));
	//building2MTTrigger06->DisableTrigger();
	UnCaptureEvent(building2MTTrigger06);
	building2MTTrigger07 = Cast<ATriggerVolume>(CaptureEvent("Building2MT_Trigger09A",nullptr));
	//building2MTTrigger07->DisableTrigger();
	UnCaptureEvent(building2MTTrigger07);
	building2MTTrigger08 = Cast<ATriggerVolume>(CaptureEvent("Building2MT_Trigger10A",nullptr));
	//building2MTTrigger08->DisableTrigger();
	UnCaptureEvent(building2MTTrigger08);
	building2MTTrigger09 = Cast<ATriggerVolume>(CaptureEvent("Building2MT_Trigger11A",nullptr));
	//building2MTTrigger09->DisableTrigger();
	UnCaptureEvent(building2MTTrigger09);
	building2MTTrigger10 = Cast<ATriggerVolume>(CaptureEvent("Building2MT_Trigger12A",nullptr));
	//building2MTTrigger10->DisableTrigger();
	UnCaptureEvent(building2MTTrigger10);
	building3MTTrigger01 = Cast<ATriggerVolume>(CaptureEvent("Building3MT_Trigger03B",nullptr));
	//building3MTTrigger01->DisableTrigger();
	UnCaptureEvent(building3MTTrigger01);
	building3MTTrigger02 = Cast<ATriggerVolume>(CaptureEvent("Building3MT_Trigger02ABC",nullptr));
	//building3MTTrigger02->DisableTrigger();
	UnCaptureEvent(building3MTTrigger02);
	building3MTTrigger03 = Cast<ATriggerVolume>(CaptureEvent("Building3MT_Trigger03ABC",nullptr));
	//building3MTTrigger03->DisableTrigger();
	UnCaptureEvent(building3MTTrigger03);
	building3MTTrigger04 = Cast<ATriggerVolume>(CaptureEvent("Building3MT_Trigger04B",nullptr));
	//building3MTTrigger04->DisableTrigger();
	UnCaptureEvent(building3MTTrigger04);
	building3MTTrigger05 = Cast<ATriggerVolume>(CaptureEvent("Building3MT_Trigger05B",nullptr));
	//building3MTTrigger05->DisableTrigger();
	UnCaptureEvent(building3MTTrigger05);
	building3MTTrigger06 = Cast<ATriggerVolume>(CaptureEvent("Building3MT_Trigger06B",nullptr));
	//building3MTTrigger06->DisableTrigger();
	UnCaptureEvent(building3MTTrigger06);
	building3MTTrigger07 = Cast<ATriggerVolume>(CaptureEvent("Building3MT_Trigger07AB",nullptr));
	//building3MTTrigger07->DisableTrigger();
	UnCaptureEvent(building3MTTrigger07);
	building3MTTrigger08 = Cast<ATriggerVolume>(CaptureEvent("Building3MT_Trigger08AB",nullptr));
	//building3MTTrigger08->DisableTrigger();
	UnCaptureEvent(building3MTTrigger08);
	building4MTTrigger02 = Cast<ATriggerVolume>(CaptureEvent("Building4MT_Trigger02AB",nullptr));
	//building4MTTrigger02->DisableTrigger();
	UnCaptureEvent(building4MTTrigger02);
	building4MTTrigger03 = Cast<ATriggerVolume>(CaptureEvent("Building4MT_Trigger03AB",nullptr));
	//building4MTTrigger03->DisableTrigger();
	UnCaptureEvent(building4MTTrigger03);
	building4MTTrigger04 = Cast<ATriggerVolume>(CaptureEvent("Building4MT_Trigger04AB",nullptr));
	//building4MTTrigger04->DisableTrigger();
	UnCaptureEvent(building4MTTrigger04);
	building5MTTrigger01 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger01A",nullptr));
	//building5MTTrigger01->DisableTrigger();
	UnCaptureEvent(building5MTTrigger01);
	building5MTTrigger02 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger02ABC",nullptr));
	//building5MTTrigger02->DisableTrigger();
	UnCaptureEvent(building5MTTrigger02);
	building5MTTrigger03 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger03ABC",nullptr));
	//building5MTTrigger03->DisableTrigger();
	UnCaptureEvent(building5MTTrigger03);
	building5MTTrigger04 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger04ABC",nullptr));
	//building5MTTrigger04->DisableTrigger();
	UnCaptureEvent(building5MTTrigger04);
	building5MTTrigger05 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger05ABC",nullptr));
	//building5MTTrigger05->DisableTrigger();
	UnCaptureEvent(building5MTTrigger05);
	building5MTTrigger06 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger06ABC",nullptr));
	//building5MTTrigger06->DisableTrigger();
	UnCaptureEvent(building5MTTrigger06);
	building5MTTrigger07 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger07ABC",nullptr));
	//building5MTTrigger07->DisableTrigger();
	UnCaptureEvent(building5MTTrigger07);
	building5MTTrigger08 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger08ABC",nullptr));
	//building5MTTrigger08->DisableTrigger();
	UnCaptureEvent(building5MTTrigger08);
	building5MTTrigger09 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger09ABC",nullptr));
	//building5MTTrigger09->DisableTrigger();
	UnCaptureEvent(building5MTTrigger09);
	building5MTTrigger10 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger10ABC",nullptr));
	//building5MTTrigger10->DisableTrigger();
	UnCaptureEvent(building5MTTrigger10);
	building5MTTrigger11 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger11ABC",nullptr));
	//building5MTTrigger11->DisableTrigger();
	UnCaptureEvent(building5MTTrigger11);
	building5MTTrigger12 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger12ABCD",nullptr));
	//building5MTTrigger12->DisableTrigger();
	UnCaptureEvent(building5MTTrigger12);
	building5MTTrigger13 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger13ABCD",nullptr));
	//building5MTTrigger13->DisableTrigger();
	UnCaptureEvent(building5MTTrigger13);
	building5MTTrigger14 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger14ABCD",nullptr));
	//building5MTTrigger14->DisableTrigger();
	UnCaptureEvent(building5MTTrigger14);
	building5MTTrigger15 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger15ABCD",nullptr));
	//building5MTTrigger15->DisableTrigger();
	UnCaptureEvent(building5MTTrigger15);
	building5MTTrigger16 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger16ABCD",nullptr));
	//building5MTTrigger16->DisableTrigger();
	UnCaptureEvent(building5MTTrigger16);
	building5MTTrigger17 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger17ABCD",nullptr));
	//building5MTTrigger17->DisableTrigger();
	UnCaptureEvent(building5MTTrigger17);
	building5MTTrigger18 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger18ABCD",nullptr));
	//building5MTTrigger18->DisableTrigger();
	UnCaptureEvent(building5MTTrigger18);
	building5MTTrigger19 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger19ABCD",nullptr));
	//building5MTTrigger19->DisableTrigger();
	UnCaptureEvent(building5MTTrigger19);
	building5MTTrigger20 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger20ABCD",nullptr));
	//building5MTTrigger20->DisableTrigger();
	UnCaptureEvent(building5MTTrigger20);
	building5MTTrigger21 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger21ABCD",nullptr));
	//building5MTTrigger21->DisableTrigger();
	UnCaptureEvent(building5MTTrigger21);
	building5MTTrigger22 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger22ABCD",nullptr));
	//building5MTTrigger22->DisableTrigger();
	UnCaptureEvent(building5MTTrigger22);
	building5MTTrigger23 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger23ABCD",nullptr));
	//building5MTTrigger23->DisableTrigger();
	UnCaptureEvent(building5MTTrigger23);
	building5MTTrigger24 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger24ABCD",nullptr));
	//building5MTTrigger24->DisableTrigger();
	UnCaptureEvent(building5MTTrigger24);
	building5MTTrigger25 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger25ABCD",nullptr));
	//building5MTTrigger25->DisableTrigger();
	UnCaptureEvent(building5MTTrigger25);
	building5MTTrigger26 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger26ABCD",nullptr));
	//building5MTTrigger26->DisableTrigger();
	UnCaptureEvent(building5MTTrigger26);
	building5MTTrigger27 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger27ABCD", nullptr));
	//building5MTTrigger27->DisableTrigger();
	UnCaptureEvent(building5MTTrigger27);
	building5MTTrigger28 = Cast<ATriggerVolume>(CaptureEvent("Building5MT_Trigger28ABCD", nullptr));
	//building5MTTrigger28->DisableTrigger();
	UnCaptureEvent(building5MTTrigger28);
	building6MTTrigger01 = Cast<ATriggerVolume>(CaptureEvent("Building6MT_Trigger01B", nullptr));
	//building6MTTrigger01->DisableTrigger();
	UnCaptureEvent(building6MTTrigger01);
	building6MTTrigger02 = Cast<ATriggerVolume>(CaptureEvent("Building6MT_Trigger02B",nullptr));
	//building6MTTrigger02->DisableTrigger();
	UnCaptureEvent(building6MTTrigger02);
	building6MTTrigger03 = Cast<ATriggerVolume>(CaptureEvent("Building6MT_Trigger03B", nullptr));
	//building6MTTrigger03->DisableTrigger();
	UnCaptureEvent(building6MTTrigger03);
	building6MTTrigger04 = Cast<ATriggerVolume>(CaptureEvent("Building6MT_Trigger04B", nullptr));
	//building6MTTrigger04->DisableTrigger();
	UnCaptureEvent(building6MTTrigger04);
	building6MTTrigger05 = Cast<ATriggerVolume>(CaptureEvent("Building6MT_Trigger05A", nullptr));
	//building6MTTrigger05->DisableTrigger();
	UnCaptureEvent(building6MTTrigger05);
	building6MTTrigger06 = Cast<ATriggerVolume>(CaptureEvent("Building6MT_Trigger06A", nullptr));
	//building6MTTrigger06->DisableTrigger();
	UnCaptureEvent(building6MTTrigger06);
	building6MTTrigger07 = Cast<ATriggerVolume>(CaptureEvent("Building6MT_Trigger07A", nullptr));
	//building6MTTrigger07->DisableTrigger();
	UnCaptureEvent(building6MTTrigger07);
	bAllMTTriggersDisabled = true;
}

bool AEL_ES2McKenna::MarksmanTarget_Damaged(AMarksmanTarget* NotifyActor, AActor* aInstigator, FString Parms)
{
	int32 targetVal = 0;
	/*
	ParseParms(Parms);
	if (NotifyActor.TargetType == 1)
	{
		if ((ParmList[1] == "A") && NotifyActor.bTriggered)
		{
			opforHit++;
			(opforHitScore += 100);
			targetA++;
			opforRunningCount++;
			NotifyActor.ResetTarget(true);
			UnCaptureEvent(NotifyActor);
		}
		else
		{
			if ((ParmList[1] == "B") && NotifyActor.bTriggered)
			{
				opforHit++;
				(opforHitScore += 70);
				targetB++;
				opforRunningCount++;
				NotifyActor.ResetTarget(true);
				UnCaptureEvent(NotifyActor);
			}
			else
			{
				if ((ParmList[1] == "C") && NotifyActor.bTriggered)
				{
					opforHit++;
					(opforHitScore += 50);
					targetC++;
					opforRunningCount++;
					NotifyActor.ResetTarget(true);
					UnCaptureEvent(NotifyActor);
				}
			}
		}
	}
	else
	{
		if (NotifyActor.bTriggered)
		{
			friendlyHit++;
			(friendlyHitScore -= 60);
			if (!bSecondFriendlyHit)
			{
				PlayGameSound('VoiceGuy_HitFriendly', NotifyActor);
				bSecondFriendlyHit = true;
			}
			else
			{
				PlayGameSound('m_error', NotifyActor);
			}
			NotifyActor.ResetTarget(true);
			UnCaptureEvent(NotifyActor);
		}
	}
	DebugLog(DEBUG_EventLab, "<<<<< ");
	DebugLog(DEBUG_EventLab, ">>>>> Target:" @ FString::FromInt(NotifyActor) @ "| Type:" @ FString::FromInt(NotifyActor.TargetType) @ "| Target Part:" @ ParmList[1]);
	DebugLog(DEBUG_EventLab, ">>>>> Value for this hit:" @ FString::FromInt(targetVal));
	DebugLog(DEBUG_EventLab, ">>>>> Total Target A:" @ FString::FromInt(targetA) @ "| Target B:" @ FString::FromInt(targetB) @ "| Target C:" @ FString::FromInt(targetC));
	DebugLog(DEBUG_EventLab, ">>>>> Enemy Hit:" @ FString::FromInt(opforHit) @ "| Friendly Hit:" @ FString::FromInt(friendlyHit));
	DebugLog(DEBUG_EventLab, ">>>>> Total Enemy Score:" @ FString::FromInt(opforHitScore) @ "| Friendly Score:" @ FString::FromInt(friendlyHitScore));
	DebugLog(DEBUG_EventLab, ">>>>> Enemy Running Count: " @ FString::FromInt(opforRunningCount));
	DebugLog(DEBUG_EventLab, ">>>>> Time Remaining Total: " @ FString::FromInt(timeKeeper));
	DebugLog(DEBUG_EventLab, "<<<<< ");
	*/
	return true;
}

bool AEL_ES2McKenna::uploadStats()
{
	ASecurity* secLocalSecurity = nullptr;
	ASecurity* scLocalSecurityClass = nullptr;
	TArray<FString> asMD5ForMap = {};
	TArray<FString> asMD5ForScript = {};
	FString sMD5ForMap = "";
	FString sMD5ForScript = "";
	/*
	DebugLog(DEBUG_EventLab, "uploadStats:");
	if (Cast<AStudentController>(Controller)->bUsedCheats)
	{
		DisplayMissionCompleteOther("T_AA2_UI.tour_icons.hud_menu_touricon_SF", "ES2 Training Course Complete", "Would you like to try again?", 128, 128, 7, "None", "AGP_Interface.AAMissionCompletePageSFMOUT");
		return false;
	}
	Controller.ResetAuthExtraMissionData();
	Controller.AddAuthExtraMissionData(sWeaponAtCompletion);
	Controller.AddAuthExtraMissionData("" + FString::FromInt(TotalScore));
	Controller.AddAuthExtraMissionData("" + FString::FromInt(ES2Score));
	Controller.AddAuthExtraMissionData("" + FString::FromInt(ES2objectsFound));
	Controller.AddAuthExtraMissionData("" + FString::FromInt(opforHit));
	Controller.AddAuthExtraMissionData("" + FString::FromInt(friendlyHit));
	Controller.AddAuthExtraMissionData("" + FString::FromInt(opforHitScore));
	Controller.AddAuthExtraMissionData("" + FString::FromInt(friendlyHitScore));
	Controller.AddAuthExtraMissionData("" + FString::FromInt(roundsFired));
	Controller.AddAuthExtraMissionData("" + FString::FromInt(accuracyScore));
	Controller.AddAuthExtraMissionData("" + timeOverall);
	Controller.AddAuthExtraMissionData("" + FString::FromInt(timeOverallScore));
	if (finalGo == "X")
	{
		Cast<AStudentController>(Controller)->SetAuthMissionPassFlag(true);
	}
	else
	{
		Cast<AStudentController>(Controller)->SetAuthMissionPassFlag(false);
	}
	scLocalSecurityClass = class<Security>(DynamicLoadObject("Engine.Security", Class'Class'));
	if (scLocalSecurityClass != nullptr)
	{
		secLocalSecurity = Spawn(scLocalSecurityClass, Controller);
		if (secLocalSecurity != nullptr)
		{
			secLocalSecurity.LocalPerform(2, "../Maps/ES2McKenna.aao", "", asMD5ForMap);
			secLocalSecurity.LocalPerform(2, "../System/AGP_Script.u", "", asMD5ForScript);
			sMD5ForMap = asMD5ForMap[0];
			sMD5ForScript = asMD5ForScript[0];
		}
	}
	Controller.AddAuthExtraMissionData(sMD5ForMap);
	Controller.AddAuthExtraMissionData(sMD5ForScript);
	DisplayMissionCompleteOther("T_AA2_UI.tour_icons.hud_menu_touricon_SF", "ES2 Training Course Complete", "Would you like to save your results to your Personnel Jacket?", 128, 128, 7, "None", "AGP_Interface.AAMissionCompletePageSFMOUT");
	*/
	return true;
}

void AEL_ES2McKenna::EL_ES2ObjectFound(int32 Score)
{
	/*
	(ES2Score += Score);
	(++ES2objectsFound);
	*/
}
