// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_JavelinTraining/EL_JavelinTraining.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character.h"
#include "AA29/Object/Actor/AGP_Sound/AGP_Sound.h"
#include "AA29/Object/Actor/AGP_UseTrigger/AGP_UseTrigger.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_Vehicle.h"
#include "AA29/Object/Actor/SVehicleFactory/AGP_VehicleFactory/AGP_VehicleFactory.h"
#include "AA29/Object/Actor/Keypoint/AGP_Viewpoint/AGP_Viewpoint.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseProjectile.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_ACUBasicSoldier/NPC_ACUBasicSoldier.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/Teleporter/Teleporter.h"
#include "AA29/Object/Actor/AAGameplay/TextDisplay/TextDisplay.h"

AEL_JavelinTraining::AEL_JavelinTraining()
{
	LengthLFSignUpInstructor = {
		5.113,
		1
	};
	LengthBSTInstructor = {
		18.437,
		21.899,
		11.629,
		0.748,
		8.12,
		0.873,
		1.051,
		2.363,
		4.117,
		1.184,
		1.64,
		12.155,
		10.847,
		9.691,
		10.561,
		14.433,
		18.500999,
		3.358,
		2.667,
		4.54,
		12.471,
		15.822,
		18.322001,
		4.677,
		23.07,
		5.819,
		4,
		0.626,
		6.719,
		8.46,
		4.036,
		13.283,
		1.074
	};

	LengthTentInstructor = {
		2.481,
		8.34,
		1.408
	};

	LengthLFInstructor = {
		45.754002,
		6.934,
		9.166,
		6.41,
		9.103,
		7.54,
		5.482,
		7.523,
		5.03,
		5.073,
		5.996,
		6.627
	};

	LengthPlayerDiedNotLFSound = 2.782;
	LengthDelay = 1;
	LengthLFEcho = 2;
	BSTInstructorSound.SetNum(32);
	BSTInstructorSound[11] = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_11_Cue.S_Jave_Bst_Instructor_Vo_11_Cue'"), NULL, LOAD_None, NULL);
	BSTInstructorSound[12] = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_12_Cue.S_Jave_Bst_Instructor_Vo_12_Cue'"), NULL, LOAD_None, NULL);
	BSTInstructorSound[13] = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_13_Cue.S_Jave_Bst_Instructor_Vo_13_Cue'"), NULL, LOAD_None, NULL);
	BSTInstructorSound[15] = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_15_Cue.S_Jave_Bst_Instructor_Vo_15_Cue'"), NULL, LOAD_None, NULL);
	BSTInstructorSound[16] = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_16_Cue.S_Jave_Bst_Instructor_Vo_16_Cue'"), NULL, LOAD_None, NULL);
	BSTInstructorSound[17] = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_17_Cue.S_Jave_Bst_Instructor_Vo_17_Cue'"), NULL, LOAD_None, NULL);
	BSTInstructorSound[18] = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_18_Cue.S_Jave_Bst_Instructor_Vo_18_Cue'"), NULL, LOAD_None, NULL);
	BSTInstructorSound[19] = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_19_Cue.S_Jave_Bst_Instructor_Vo_19_Cue'"), NULL, LOAD_None, NULL);
	BSTInstructorSound[20] = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_20_Cue.S_Jave_Bst_Instructor_Vo_20_Cue'"), NULL, LOAD_None, NULL);
	BSTInstructorSound[21] = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_21_Cue.S_Jave_Bst_Instructor_Vo_21_Cue'"), NULL, LOAD_None, NULL);
	BSTInstructorSound[22] = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_22_Cue.S_Jave_Bst_Instructor_Vo_22_Cue'"), NULL, LOAD_None, NULL);
	BSTInstructorSound[23] = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_23_Cue.S_Jave_Bst_Instructor_Vo_23_Cue'"), NULL, LOAD_None, NULL);
	BSTInstructorSound[24] = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_24_Cue.S_Jave_Bst_Instructor_Vo_24_Cue'"), NULL, LOAD_None, NULL);
	BSTInstructorSound[25] = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_25_Cue.S_Jave_Bst_Instructor_Vo_25_Cue'"), NULL, LOAD_None, NULL);
	BSTInstructorSound[26] = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_26_Cue.S_Jave_Bst_Instructor_Vo_26_Cue'"), NULL, LOAD_None, NULL);
	BSTInstructorSound[27] = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_27_Cue.S_Jave_Bst_Instructor_Vo_27_Cue'"), NULL, LOAD_None, NULL);
	BSTInstructorSound[28] = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_28_Cue.S_Jave_Bst_Instructor_Vo_28_Cue'"), NULL, LOAD_None, NULL);
	BSTInstructorSound[29] = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_29_Cue.S_Jave_Bst_Instructor_Vo_29_Cue'"), NULL, LOAD_None, NULL);
	BSTInstructorSound[30] = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_30_Cue.S_Jave_Bst_Instructor_Vo_30_Cue'"), NULL, LOAD_None, NULL);
	BSTInstructorSound[31] = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_31_Cue.S_Jave_Bst_Instructor_Vo_31_Cue'"), NULL, LOAD_None, NULL);
	
	LFInstructorSound = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/LF_Instructor/S_Jave_Lf_Instructor_Vo_00_Cue.S_Jave_Lf_Instructor_Vo_00_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/LF_Instructor/S_Jave_Lf_Instructor_Vo_01_Cue.S_Jave_Lf_Instructor_Vo_01_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/LF_Instructor/S_Jave_Lf_Instructor_Vo_02_Cue.S_Jave_Lf_Instructor_Vo_02_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/LF_Instructor/S_Jave_Lf_Instructor_Vo_03_Cue.S_Jave_Lf_Instructor_Vo_03_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/LF_Instructor/S_Jave_Lf_Instructor_Vo_04_Cue.S_Jave_Lf_Instructor_Vo_04_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/LF_Instructor/S_Jave_LF_Instructor_Vo_05_Cue.S_Jave_LF_Instructor_Vo_05_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/LF_Instructor/S_Jave_LF_Instructor_Vo_06_Cue.S_Jave_LF_Instructor_Vo_06_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/LF_Instructor/S_Jave_Lf_Instructor_Vo_07_Cue.S_Jave_Lf_Instructor_Vo_07_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/LF_Instructor/S_Jave_Lf_Instructor_Vo_08_Cue.S_Jave_Lf_Instructor_Vo_08_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/LF_Instructor/S_Jave_Lf_Instructor_Vo_09_Cue.S_Jave_Lf_Instructor_Vo_09_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/LF_Instructor/S_Jave_Lf_Instructor_Vo_10_Cue.S_Jave_Lf_Instructor_Vo_10_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/LF_Instructor/S_Jave_Lf_Instructor_Vo_11_Cue.S_Jave_Lf_Instructor_Vo_11_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/misc/S_Jave_Misc_Airhorn_Cue.S_Jave_Misc_Airhorn_Cue'"), NULL, LOAD_None, NULL)
	};
	PlayerDiedNotLFSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/misc/S_Jave_Misc_Medic_Cue.S_Jave_Misc_Medic_Cue'"), NULL, LOAD_None, NULL);
	WelcomeSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/misc/S_Jave_Misc_Welcome_Cue.S_Jave_Misc_Welcome_Cue'"), NULL, LOAD_None, NULL);
	NumVirtualTargets = 3;
	VirtualCourseTimeLimit = 4;
	LFCourseTimeLimit = 10;
	LFInitialValidTargets = 10;
	LFInitialTubes = 10;
	LFSpeakerVolume = 1.5;
	LFSpeakerRadius = 400;
	bInTent = true;
	bFirstLock = true;
	MaxJavelinFlyoutTime = 10;
	PlayTipDisplayTime = 2;

	LSAnims = {
		FLSAnim({ "S_Jave_Bst_Instructor_Vo_00",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/Tent_Instructor/S_Jave_Tent_Instructor_Vo_00_Cue.S_Jave_Tent_Instructor_Vo_00_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "S_Jave_Bst_Instructor_Vo_01",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_01_Cue.S_Jave_Bst_Instructor_Vo_01_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "S_Jave_Bst_Instructor_Vo_02",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_02_Cue.S_Jave_Bst_Instructor_Vo_02_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "S_Jave_Bst_Instructor_Vo_03",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_03_Cue.S_Jave_Bst_Instructor_Vo_03_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "S_Jave_Bst_Instructor_Vo_04",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_04_Cue.S_Jave_Bst_Instructor_Vo_04_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "S_Jave_Bst_Instructor_Vo_05",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_05_Cue.S_Jave_Bst_Instructor_Vo_05_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "S_Jave_Bst_Instructor_Vo_06",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_06_Cue.S_Jave_Bst_Instructor_Vo_06_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "S_Jave_Bst_Instructor_Vo_07",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_07_Cue.S_Jave_Bst_Instructor_Vo_07_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "S_Jave_Bst_Instructor_Vo_08",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_08_Cue.S_Jave_Bst_Instructor_Vo_08_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "S_Jave_Bst_Instructor_Vo_09",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_09_Cue.S_Jave_Bst_Instructor_Vo_09_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "S_Jave_Bst_Instructor_Vo_10",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_10_Cue.S_Jave_Bst_Instructor_Vo_10_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "S_Jave_Bst_Instructor_Vo_13",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_13_Cue.S_Jave_Bst_Instructor_Vo_13_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "S_Jave_Bst_Instructor_Vo_30",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_30_Cue.S_Jave_Bst_Instructor_Vo_30_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "S_Jave_Bst_Instructor_Vo_32",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_32_Cue.S_Jave_Bst_Instructor_Vo_32_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "S_Jave_Tent_Instructor_Vo_00",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/Tent_Instructor/S_Jave_Tent_Instructor_Vo_00_Cue.S_Jave_Tent_Instructor_Vo_00_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "S_Jave_Tent_Instructor_Vo_01",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/Tent_Instructor/S_Jave_Tent_Instructor_Vo_01_Cue.S_Jave_Tent_Instructor_Vo_01_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "S_Jave_Tent_Instructor_Vo_02",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/Tent_Instructor/S_Jave_Tent_Instructor_Vo_02_Cue.S_Jave_Tent_Instructor_Vo_02_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "S_Jave_LF_SignUp_Vo_00",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/LF_SignUp/S_Jave_LF_SignUp_Vo_00_Cue.S_Jave_LF_SignUp_Vo_00_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "S_Jave_LF_SignUp_Vo_01",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/LF_SignUp/S_Jave_LF_SignUp_Vo_01_Cue.S_Jave_LF_SignUp_Vo_01_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "BST_Instructor_Sound_000",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/Tent_Instructor/S_Jave_Tent_Instructor_Vo_00_Cue.S_Jave_Tent_Instructor_Vo_00_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "BST_Instructor_Sound_001",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_01_Cue.S_Jave_Bst_Instructor_Vo_01_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "BST_Instructor_Sound_002",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_02_Cue.S_Jave_Bst_Instructor_Vo_02_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "BST_Instructor_Sound_003",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_03_Cue.S_Jave_Bst_Instructor_Vo_03_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "BST_Instructor_Sound_004",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_04_Cue.S_Jave_Bst_Instructor_Vo_04_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "BST_Instructor_Sound_005",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_05_Cue.S_Jave_Bst_Instructor_Vo_05_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "BST_Instructor_Sound_006",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_06_Cue.S_Jave_Bst_Instructor_Vo_06_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "BST_Instructor_Sound_007",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_07_Cue.S_Jave_Bst_Instructor_Vo_07_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "BST_Instructor_Sound_008",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_08_Cue.S_Jave_Bst_Instructor_Vo_08_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "BST_Instructor_Sound_009",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_09_Cue.S_Jave_Bst_Instructor_Vo_09_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "BST_Instructor_Sound_010",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_10_Cue.S_Jave_Bst_Instructor_Vo_10_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "BST_Instructor_Sound_013",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_13_Cue.S_Jave_Bst_Instructor_Vo_13_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "BST_Instructor_Sound_030",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_30_Cue.S_Jave_Bst_Instructor_Vo_30_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "BST_Instructor_Sound_032",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/BST_Instructor/S_Jave_Bst_Instructor_Vo_32_Cue.S_Jave_Bst_Instructor_Vo_32_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Tent_Instructor_00",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/Tent_Instructor/S_Jave_Tent_Instructor_Vo_00_Cue.S_Jave_Tent_Instructor_Vo_00_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Tent_Instructor_01",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/Tent_Instructor/S_Jave_Tent_Instructor_Vo_01_Cue.S_Jave_Tent_Instructor_Vo_01_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Tent_Instructor_02",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/Tent_Instructor/S_Jave_Tent_Instructor_Vo_02_Cue.S_Jave_Tent_Instructor_Vo_02_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Lf_SignUp_00",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/LF_SignUp/S_Jave_LF_SignUp_Vo_00_Cue.S_Jave_LF_SignUp_Vo_00_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Lf_SignUp_01",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_JavelinTraining/LF_SignUp/S_Jave_LF_SignUp_Vo_01_Cue.S_Jave_LF_SignUp_Vo_01_Cue'"), NULL, LOAD_None, NULL),{ "None","None","None","None","None","None","None","None","None","None" }, {0,0,0,0,0,0,0,0,0,0} })
	};
	bDebug = false;
}

/*
State StartMission
{
	Function BeginState()
	{
		if (PassedBST())
		{
			SpawnLFSignupInstructor();
		}
		else
		{
			LiveFireSignUpTrigger.bDisabled=true;
			LiveFireSignUpTrigger.HUDText="";
		}
	}
Begin:
	FadeIn(2,true);
	PlayTip("Report directly to the Javelin training tent.","",(PlayTipDisplayTime + 3));
	Sleep(3);
	Player.PlaySound(WelcomeSound,0,1,,10000,,false);
	Sleep(5);
	PlayerLock(false,false);
	ChangeState("WalkingAround");
}
*/

/*
State WalkingAround
{
	Function BeginState()
	{
		if (! bPassedBST)
		{
			StartTimer("tmrIdleWarning",60,false);
		}
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "tmrTalktoTentInstructor")
		{
			PlayerLock(false,false);
			TentInstructorTrigger.HUDText=TentInstructorUseTip;
			return true;
		}
		if (Name == "tmrTalktoLFSignUp")
		{
			LiveFireSignUpTrigger.HUDText="";
			LiveFireSignUpTrigger.bDisabled=true;
			FadeOut(2,true);
			ChangeState("InitializeLF");
			return true;
		}
		if ((Name == "tmrIdleWarning") && (! bEnteredTent))
		{
			if (! bEnteredTent)
			{
				IdleWarn ++;
				if (IdleWarn >= 3)
				{
					Controller.ConsoleCommand("disconnect");
				}
				PlayTip("Report directly to the Javelin training tent.","",PlayTipDisplayTime);
				StartTimer("tmrIdleWarning",60,true);
			}
			else
			{
				StopTimer("tmrIdleWarning",0);
			}
		}
		return false;
	}
Begin:
	if (bDebug)
	{
		Log("AAGA in state Start");
	}
	Pickup_Javelin_BST_Tube(JTube).bCanPickUp=false;
	Pickup_Javelin_BST_CLU(BSTCLU).bCanPickUp=false;
}
*/

/*
State WelcomeBST
{
	Function BeginState()
	{
		PlayerLock(true,false);
		Player.ResetLean();
		Player.rBaseRotation.Pitch=Controller.Rotation.Pitch;
		Player.rBaseRotation.Yaw=Controller.Rotation.Yaw;
		Player.rBaseRotation.Roll=0;
		CaptureBSTVehicleFactories();
	}
Begin:
	BinkSound.SoundVolume=0;
	Controller.bDontLockAfterMisionComplete=true;
	Controller.RouteGoal=TentLockpoint;
	Controller.GotoState("MoveToForcedLocation");
	if (Controller.IsInState("MoveToForcedLocation"))
	{
		Sleep(0.25);
	}
	bInBST=true;
	if (bDebug)
	{
		Log("AAGA in begin of state WelcomeBST");
	}
	PlayLSAnim("S_Jave_Bst_Instructor_Vo_00",BST_Instructor,1,512);
	Sleep((LengthBSTInstructor[0] + LengthDelay));
	PlayLSAnim("S_Jave_Bst_Instructor_Vo_01",BST_Instructor,1,512);
	Sleep((LengthBSTInstructor[1] + LengthDelay));
	PlayLSAnim("S_Jave_Bst_Instructor_Vo_02",BST_Instructor,1,512);
	Sleep(LengthBSTInstructor[2]);
	PlayTip("Press <Action> to pick up the Javelin Tube.","",PlayTipDisplayTime);
	Pickup_Javelin_BST_Tube(JTube).bCanPickUp=true;
	ChangeState("WaitPickedJT");
}
*/

/*
State WaitPickedJT
{
	Function BeginState()
	{
		StartTimer("tmrPickedJT",10,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "tmrPickedJT")
		{
			PlayLSAnim("S_Jave_Bst_Instructor_Vo_03",BST_Instructor,1,512);
			PlayTip("Press <Action> to pick up the Javelin Tube.","",PlayTipDisplayTime);
			StartTimer("tmrPickedJT",10,true);
			return true;
		}
		return false;
	}
Begin:
	if (bDebug)
	{
		Log("AAGA in state WaitPickedJT");
	}
}
*/

/*
State PickedJT
{
Begin:
	if (bDebug)
	{
		Log("AAGA in PickedJT state");
	}
	USERJT=AGP_Weapon(CaptureEvent(Player.Weapon.Tag));
	Player.bCanSwapWeapons=false;
	PlayLSAnim("S_Jave_Bst_Instructor_Vo_04",BST_Instructor,1,512);
	Sleep((LengthBSTInstructor[4] + LengthDelay));
	PlayTip("Press <SwapHands> to shoulder the Javelin Tube.","",PlayTipDisplayTime);
	Player.bCanSwapWeapons=true;
	ChangeState("WaitShoulderedJT");
}
*/

/*
State WaitShoulderedJT
{
	Function BeginState()
	{
		StartTimer("tmrShoulderedJT",10,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "tmrShoulderedJT")
		{
			PlayLSAnim("S_Jave_Bst_Instructor_Vo_05",BST_Instructor,1,512);
			PlayTip("Press <SwapHands> to shoulder the Javelin Tube.","",PlayTipDisplayTime);
			StartTimer("tmrShoulderedJT",10,true);
			return true;
		}
		return false;
	}
Begin:
	if (bDebug)
	{
		Log("AAGA in state WaitShoulderedJT");
	}
}
*/

/*
State ShoulderedJT
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state ShoulderedJT");
	}
	Player.bCanSwapWeapons=false;
	PlayLSAnim("S_Jave_Bst_Instructor_Vo_06",BST_Instructor,1,512);
	Sleep(LengthBSTInstructor[6]);
	PlayTip("Press <Action> to pick up the CLU.","",PlayTipDisplayTime);
	Pickup_Javelin_BST_CLU(BSTCLU).bCanPickUp=true;
	ChangeState("WaitPickedCLU");
}
*/

/*
State WaitPickedCLU
{
	Function BeginState()
	{
		StartTimer("tmrPickedCLU",10,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "tmrPickedCLU")
		{
			PlayLSAnim("S_Jave_Bst_Instructor_Vo_07",BST_Instructor,1,512);
			PlayTip("Press <Action> to pick up the CLU.","",PlayTipDisplayTime);
			StartTimer("tmrPickedCLU",10,true);
			return true;
		}
		return false;
	}
Begin:
	if (bDebug)
	{
		Log("AAGA in state WaitPickedCLU");
	}
}
*/

/*
State PickedCLU
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state PickedCLU");
	}
	PCtoCLUWire1.bHidden=true;
	PCtoCLUWire1.ResetStaticFilterState();
	if (Player.getHandsInventory().IsA("WEAPON_Javelin"))
	{
		USERCLU=AGP_Weapon(CaptureEvent(Player.Weapon.Tag));
		Javelin_BST_CLU(USERCLU).bCanZoom=false;
		Controller.bNoReload=true;
		Javelin_BST_CLU(USERCLU).bCanFire=false;
		Javelin_BST_CLU(USERCLU).bCanSupport=false;
	}
	Javelin_BST_CLU(USERCLU).bCanSeek=false;
	PlayLSAnim("S_Jave_Bst_Instructor_Vo_08",BST_Instructor,1,512);
	Sleep((LengthBSTInstructor[8] + LengthDelay));
	PlayTip("Using the <SwapAltShoulder> key allows you to bring out the Javelin Tube.","Press <Binoculars> to take out or put away the CLU.",(2 * PlayTipDisplayTime));
	Player.bCanSwapWeapons=true;
	ChangeState("WaitCLUInHands");
}
*/

/*
State WaitCLUInHands
{
	Function BeginState()
	{
		StartTimer("tmrCLUInHands",5,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "tmrCLUInHands")
		{
			Player.bCanSwapWeapons=false;
			USERCLU=AGP_Weapon(CaptureEvent(Player.Weapon.Tag));
			if (((Javelin_BST_CLU(USERCLU) != nullptr) && USERCLU.IsInState("Idle")) && (Player.NextSwap == nullptr))
			{
				Javelin_BST_CLU(USERCLU).bCanZoom=false;
				Controller.bNoReload=true;
				StartTimer("tmrPostCLUInHands",3,true);
			}
			else
			{
				Player.bCanSwapWeapons=true;
				PlayTip("Press <Binoculars> to take out or put away the CLU.","",PlayTipDisplayTime);
				StartTimer("tmrCLUInHands",5,true);
			}
			return true;
		}
		if (Name == "tmrPostCLUInHands")
		{
			ChangeState("CLUInHands");
			return true;
		}
		return false;
	}
Begin:
	if (bDebug)
	{
		Log("AAGA in state WaitAwayCLU");
	}
}
*/

/*
State CLUInHands
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state CLUInHands");
	}
	Target1=AGP_Vehicle(CaptureEvent("T62A_JT_Target1"));
	Player.bCanSwapWeapons=false;
	PlayLSAnim("S_Jave_Bst_Instructor_Vo_10",BST_Instructor,1,512);
	Sleep((LengthBSTInstructor[10] + LengthDelay));
	PlayTip("Press <Zoom> to look through the Javelin sight.","",PlayTipDisplayTime);
	Javelin_BST_CLU(USERCLU).bCanZoom=true;
}
*/

/*
State CLUZooming
{
Begin:
	if (bDebug)
	{
		Log("AAGA CLUZooming State Enter");
	}
	Sleep(2);
	Player.PlaySound(BSTInstructorSound[11],0,1,,10000,,false);
	Sleep((LengthBSTInstructor[11] + LengthDelay));
	PlayTip("Press <NV> to cycle view modes.","",PlayTipDisplayTime);
	Javelin_BST_CLU(USERCLU).bCanCycle=true;
}
*/

/*
State CLUCycled
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state CLYCycled");
	}
	Javelin_BST_CLU(USERCLU).bCanCycle=false;
	Player.PlaySound(BSTInstructorSound[12],0,1,,10000,,false);
	Sleep(LengthBSTInstructor[12]);
	PlayTip("Press <Reload> to load the Javelin tube.","",PlayTipDisplayTime);
	Controller.bNoReload=false;
	ForcePlayerCrouch(true);
}
*/

/*
State WaitForCrouch
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state WaitForCrouch");
	}
}
*/

/*
State Crouched
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state Crouched");
	}
	if ((bUserCrouched && bBSTLoaded) && (! bJLoadedAndCrouchedOnce))
	{
		ChangeState("JLoadedAndCrouched");
	}
}
*/

/*
State WaitForReload
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state WaitForReload");
	}
}
*/

/*
State Reloaded
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state Reloaded");
	}
	Controller.bNoReload=true;
	if ((bBSTLoaded && bUserCrouched) && (! bJLoadedAndCrouchedOnce))
	{
		ChangeState("JLoadedAndCrouched");
	}
}
*/

/*
State JLoadedAndCrouched
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state JLoadedAndCrouched");
	}
	bJLoadedAndCrouchedOnce=true;
	PlayLSAnim("S_Jave_Bst_Instructor_Vo_13",BST_Instructor,1,512);
	Sleep((LengthBSTInstructor[13] + LengthDelay));
	Javelin_BST_CLU(USERCLU).bCanZoom=true;
	Javelin_BST_CLU(USERCLU).bCanSeek=false;
	PlayTip("Press <Zoom> to look through the Javelin sight.","",PlayTipDisplayTime);
}
*/

/*
State PlayerLookingThroughSight
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state PlayerLookingThroughSight");
	}
	Javelin_BST_CLU(USERCLU).bCanZoom=false;
	Sleep(2);
	Player.PlaySound(BSTInstructorSound[15],0,1,,10000,,false);
	Sleep(((1 + LengthBSTInstructor[15]) + LengthDelay));
	Player.PlaySound(BSTInstructorSound[16],0,1,,10000,,false);
	Sleep((LengthBSTInstructor[16] + LengthDelay));
	Javelin_BST_CLU(USERCLU).bCanSeek=true;
	Javelin_BST_CLU(USERCLU).bCanCycle=true;
	PlayTip("Click and hold  <AltFire> for two seconds while keeping the target centered.","",PlayTipDisplayTime);
}
*/

/*
State ForceMisFire
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state ForceMisFire");
	}
	Javelin_BST_CLU(USERCLU).bCanCycle=false;
	Sleep(LengthDelay);
	Player.PlaySound(BSTInstructorSound[29],0,1,,10000,,false);
	Sleep((LengthBSTInstructor[29] + LengthDelay));
	PlayTip("Press <Fixjam> to fix missile bit error.","",PlayTipDisplayTime);
	Javelin_BST_CLU(USERCLU).bCanFixJam=true;
	Javelin_BST_CLU(USERCLU).bCanSeek=false;
	ChangeState("WaitFixJam");
}
*/

/*
State WaitFixJam
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state WaitFixJam");
	}
}
*/

/*
State FixJamFixed
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state FixJamFixed");
	}
	Javelin_BST_CLU(USERCLU).bCanFixJam=false;
	Javelin_BST_CLU(USERCLU).bCanZoom=false;
	Sleep(2);
	PlayLSAnim("S_Jave_Bst_Instructor_Vo_30",BST_Instructor,1,512);
	Sleep((LengthBSTInstructor[30] + LengthDelay));
	PlayTip("Press <Zoom> to look through the Javelin sight.","",PlayTipDisplayTime);
	Javelin_BST_CLU(USERCLU).bCanZoom=true;
}
*/

/*
State PlayerLookingThroughSight2
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state PlayerLookingThroughSight2");
	}
	Javelin_BST_CLU(USERCLU).bCanZoom=false;
	Sleep(2);
	Player.PlaySound(BSTInstructorSound[31],0,1,,10000,,false);
	Sleep((LengthBSTInstructor[31] + LengthDelay));
	Javelin_BST_CLU(USERCLU).bCanSeek=true;
	Javelin_BST_CLU(USERCLU).bCanCycle=true;
	PlayTip("Click and hold  <AltFire> for two seconds while keeping the target centered.","",PlayTipDisplayTime);
}
*/

/*
State NoLock
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state NoLock");
	}
	if (! bLengthyLockVO)
	{
		PlayTip("You did not acquire a lock.","Please try again.",(LengthBSTInstructor[17] + LengthDelay));
		Javelin_BST_CLU(USERCLU).bTotalLock=true;
		Player.StopSound(BSTInstructorSound[17]);
		Player.StopSound(BSTInstructorSound[18]);
		Player.StopSound(BSTInstructorSound[19]);
		Player.PlaySound(BSTInstructorSound[17],0,1,,10000,,false);
		Sleep((LengthBSTInstructor[17] + LengthDelay));
		Javelin_BST_CLU(USERCLU).bTotalLock=false;
	}
	else
	{
		PlayTip("You did not acquire a lock.","Please try again.",PlayTipDisplayTime);
	}
}
*/

/*
State NoLock2
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state NoLock2");
	}
	if (! bLengthyLockVO)
	{
		PlayTip("You did not acquire a lock.","Please try again.",(LengthBSTInstructor[18] + LengthDelay));
		Javelin_BST_CLU(USERCLU).bTotalLock=true;
		Player.StopSound(BSTInstructorSound[17]);
		Player.StopSound(BSTInstructorSound[18]);
		Player.StopSound(BSTInstructorSound[19]);
		Player.PlaySound(BSTInstructorSound[18],0,1,,10000,,false);
		Sleep((LengthBSTInstructor[18] + LengthDelay));
		Javelin_BST_CLU(USERCLU).bTotalLock=false;
	}
	else
	{
		PlayTip("You did not acquire a lock.","Please try again.",PlayTipDisplayTime);
	}
}
*/

/*
State NoLock3
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state NoLock3");
	}
	if (! bLengthyLockVO)
	{
		PlayTip("You did not acquire a lock.","Please try again.",(LengthBSTInstructor[19] + LengthDelay));
		Javelin_BST_CLU(USERCLU).bTotalLock=true;
		Player.StopSound(BSTInstructorSound[17]);
		Player.StopSound(BSTInstructorSound[18]);
		Player.StopSound(BSTInstructorSound[19]);
		Player.PlaySound(BSTInstructorSound[19],0,1,,10000,,false);
		Sleep((LengthBSTInstructor[19] + LengthDelay));
		Javelin_BST_CLU(USERCLU).bTotalLock=false;
	}
	else
	{
		PlayTip("You did not acquire a lock.","Please try again.",PlayTipDisplayTime);
	}
}
*/

/*
State HasLock
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state HasLock");
	}
	bLengthyLockVO=true;
	StartTimer("tmrLengthyLockVO",(LengthBSTInstructor[20] + LengthDelay),false);
	Player.PlaySound(BSTInstructorSound[20],0,1,,10000,,false);
	Sleep(LengthBSTInstructor[20]);
	if (Javelin_BST_CLU(USERCLU).bLockedOn)
	{
		PlayTip("Click the <Fire> key to fire Javelin.","",PlayTipDisplayTime);
	}
	Javelin_BST_CLU(USERCLU).bCanFire=true;
}
*/

/*
State LostLock
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state LostLock");
	}
	PlayTip("You have lost the lock.","Please reacquire the lock",PlayTipDisplayTime);
}
*/

/*
State RegainedLock
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state RegainedLock");
	}
	if (! bLengthyLockVO)
	{
		PlayTip("Click the <Fire> key to fire Javelin.","",PlayTipDisplayTime);
		Javelin_BST_CLU(USERCLU).bCanFire=true;
	}
}
*/

/*
State T72Hit
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state T72Hit");
	}
	Javelin_BST_CLU(USERCLU).bCanSeek=false;
	Javelin_BST_CLU(USERCLU).bCanCycle=false;
	Player.PlaySound(BSTInstructorSound[21],0,1,,10000,,false);
	Sleep(LengthBSTInstructor[21]);
	FadeOut(2,true);
	TargetFactory2=AGP_VehicleFactory(CaptureEvent("VValidTargetFactory2"));
	Sleep(1);
	DestroyVT72Target(Target1);
	TargetFactory2.SpawnVehicle();
	Sleep(1);
	FadeIn(2,true);
	Javelin_BST_CLU(USERCLU).AmmoType.AmmoAmount=1;
	ChangeState("SettingUpSecondTarget");
}
*/

/*
State SettingUpSecondTarget
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state state SettingUpSecondTarget");
	}
	Javelin_BST_CLU(USERCLU).bDirectOnly=true;
	Player.PlaySound(BSTInstructorSound[22],0,1,,10000,,false);
	Sleep((LengthBSTInstructor[22] + LengthDelay));
	target2=AGP_Vehicle(CaptureEvent("T62A_JT_Target2"));
	Javelin_BST_CLU(USERCLU).bCanCycle=true;
	Javelin_BST_CLU(USERCLU).bCanSupport=true;
	Javelin_BST_CLU(USERCLU).bCanSeek=true;
	PlayTip("Press the <SupportedFire> key to toggle between top and direct attack modes.","",PlayTipDisplayTime);
}
*/

/*
State SecondT72Hit
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state SecondT72Hit");
	}
	Javelin_BST_CLU(USERCLU).bCanSeek=false;
	Javelin_BST_CLU(USERCLU).bCanCycle=false;
	Javelin_BST_CLU(USERCLU).bCanSupport=false;
	Javelin_BST_CLU(USERCLU).bDirectOnly=false;
	Player.PlaySound(BSTInstructorSound[23],0,1,,10000,,false);
	Sleep((LengthBSTInstructor[23] + LengthDelay));
	FadeOut(2,true);
	Sleep(2);
	DestroyVT72Target(target2);
	SpawnVirtualTargets();
	Sleep(3);
	CaptureVirtualTargets();
	Javelin_BST_CLU(USERCLU).bDirectFire=false;
	Javelin_BST_CLU(USERCLU).ToggleVision(false);
	Javelin_BST_CLU(USERCLU).myscope.fZoomMultiplier=4;
	Javelin_BST_CLU(USERCLU).myscope.iZoomFOV=0;
	Javelin_BST_CLU(USERCLU).bDisableNV=false;
	FadeIn(2,true);
	Player.PlaySound(BSTInstructorSound[24],0,1,,10000,,false);
	Sleep((LengthBSTInstructor[24] + LengthDelay));
	Javelin_BST_CLU(USERCLU).AmmoType.AmmoAmount=1;
	Javelin_BST_CLU(USERCLU).bCanSeek=true;
	Javelin_BST_CLU(USERCLU).bCanCycle=true;
	Javelin_BST_CLU(USERCLU).bCanSupport=true;
	bInVirtual=true;
	if (bDebug)
	{
		Log("AAGA changing bInVirtual to true, " $ string(bInVirtual));
	}
	ChangeState("PreStartVirtual");
	if (bDebug)
	{
		Log("AAGA after bInvirtual and ChangeState");
	}
}
*/

/*
State PreStartVirtual
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state PreStartVirtual");
	}
	ChangeState("StartVirtual");
}
*/

/*
State StartVirtual
{
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "VTimeLimitExceeded")
		{
			ChangeState("VFailTime");
			return true;
		}
		return false;
	}
Begin:
	if (bDebug)
	{
		Log("AAGA in state StartVirtual");
	}
	Javelin_BST_CLU(USERCLU).bCanSeek=true;
	Javelin_BST_CLU(USERCLU).bCanCycle=true;
	Javelin_BST_CLU(USERCLU).bCanSupport=true;
	Javelin_BST_CLU(USERCLU).bDirectFire=false;
	Javelin_BST_CLU(USERCLU).ToggleVision(false);
	Javelin_BST_CLU(USERCLU).myscope.fZoomMultiplier=4;
	Javelin_BST_CLU(USERCLU).myscope.iZoomFOV=0;
	Javelin_BST_CLU(USERCLU).bDisableNV=false;
	Controller.DesiredFOV=Javelin_BST_CLU(USERCLU).myscope.aZoomFOV[Javelin_BST_CLU(USERCLU).myscope.iZoomFOV];
	Controller.FovAngle=Controller.DesiredFOV;
	SetClockTimedV();
}
*/

/*
State VFailInvalid
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state VFailInvalid");
	}
	Javelin_BST_CLU(USERCLU).bCanSeek=false;
	Javelin_BST_CLU(USERCLU).bCanCycle=false;
	Javelin_BST_CLU(USERCLU).bCanSupport=false;
	Javelin_BST_CLU(USERCLU).CancelLock(false);
	Player.PlaySound(BSTInstructorSound[25],0,1,,10000,,false);
	Sleep((LengthBSTInstructor[25] + LengthDelay));
	FadeOut(2,true);
	Sleep(2);
	DestroyVirtualTargets();
	SpawnVirtualTargets();
	Sleep(3);
	CaptureVirtualTargets();
	FadeIn(2,true);
	Javelin_BST_CLU(USERCLU).AmmoType.AmmoAmount=1;
	ChangeState("StartVirtual");
}
*/

/*
State VFailTime
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state VFailTime");
	}
	Javelin_BST_CLU(USERCLU).bCanSeek=false;
	Javelin_BST_CLU(USERCLU).bCanCycle=false;
	Javelin_BST_CLU(USERCLU).bCanSupport=false;
	Javelin_BST_CLU(USERCLU).CancelLock(false);
	Player.PlaySound(BSTInstructorSound[26],0,1,,10000,,false);
	Sleep((LengthBSTInstructor[26] + LengthDelay));
	FadeOut(2,true);
	DestroyVirtualTargets();
	SpawnVirtualTargets();
	Sleep(3);
	CaptureVirtualTargets();
	FadeIn(2,true);
	Javelin_BST_CLU(USERCLU).AmmoType.AmmoAmount=1;
	ChangeState("StartVirtual");
}
*/

/*
State VPass
{
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "tmrCheckGUI")
		{
			if (bReadyForOpportunity)
			{
				ChangeState("Opportunity");
				return true;
			}
			else
			{
				StartTimer("tmrCheckGUI",1.5,true);
			}
		}
		return false;
	}
Begin:
	if (bDebug)
	{
		Log("AAGA in state VPass");
	}
	SpawnLFSignupInstructor();
	if (bDebug)
	{
		Log("Showing Javelin");
	}
	Javelin_Assembled.bHidden=false;
	Javelin_Assembled.ResetStaticFilterState();
	PCtoCLUWire2.bHidden=false;
	PCtoCLUWire2.ResetStaticFilterState();
	Player.PlaySound(BSTInstructorSound[27],0,1,,10000,,false);
	Sleep((LengthBSTInstructor[27] + LengthDelay));
	bInVirtual=false;
	bPassedBST=true;
	uploadStatsBST();
	StartTimer("tmrCheckGUI",1,true);
}
*/

/*
State DelayAndCloseSaveAndContinue
{
Begin:
	Sleep(2);
	Controller.ClientCloseMenu(true,false);
	GotoState("Opportunity");
}
*/

/*
State Opportunity
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state Opportunity");
	}
	Player.PlaySound(BSTInstructorSound[28],0,1,,10000,,false);
	Sleep((LengthBSTInstructor[28] + LengthDelay));
	Javelin_BST_CLU(USERCLU).bCanDrop=true;
	BinkSound.SoundVolume=BinkVolume;
	PlayTip("Press the <ThrowWeapon> key to drop the BST.","",PlayTipDisplayTime);
}
*/

/*
State BSTThrown
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state BSTThrown");
	}
	bInBST=false;
	PlayerLock(false,false);
	BST_Instructor_Trigger.SetCollision(false,false);
	Controller.bNoReload=false;
	ChangeState("WalkingAround");
}
*/

/*
State InitializeLF
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state InitializeLF");
	}
	CaptureLFTargets();
	ChangeState("WelcomeLF");
}
*/

/*
State WelcomeLF
{
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "LFInstructorIntro")
		{
			ChangeState("CountdownLF");
			return true;
		}
		return false;
	}
Begin:
	if (bDebug)
	{
		Log("AAGA in state WelcomeLF");
	}
	Player.SetLocation(LiveFireLockpoint.Location);
	Controller.SetRotation(LiveFireLockpoint.Rotation);
	Player.LimitRotation(false);
	bInTent=false;
	FadeIn(2,true);
	PlayerLock(true,false);
	Sleep(LengthDelay);
	LFSkipIntroTrigger.SetCollision(true,false);
	LFSkipIntroTrigger.bDisabled=false;
	LFSkipIntroTrigger.HUDText=LFSkipIntroUseTip;
	Speaker_LF01.PlaySound(LFInstructorSound[0],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF02.PlaySound(LFInstructorSound[0],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF03.PlaySound(LFInstructorSound[0],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF04.PlaySound(LFInstructorSound[0],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF05.PlaySound(LFInstructorSound[0],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	StartTimer("LFInstructorIntro",(LengthLFInstructor[0] - float(LengthLFEcho)),false);
}
*/

/*
State CountdownLF
{
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "LFInstructorOutro")
		{
			ChangeState("StartLF");
			return true;
		}
		return false;
	}
Begin:
	LFSkipIntroTrigger.SetCollision(false,false);
	LFSkipIntroTrigger.bDisabled=true;
	LFSkipIntroTrigger.HUDText="";
	Speaker_LF01.StopSound(LFInstructorSound[0]);
	Speaker_LF02.StopSound(LFInstructorSound[0]);
	Speaker_LF03.StopSound(LFInstructorSound[0]);
	Speaker_LF04.StopSound(LFInstructorSound[0]);
	Speaker_LF05.StopSound(LFInstructorSound[0]);
	Speaker_LF01.PlaySound(LFInstructorSound[1],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF02.PlaySound(LFInstructorSound[1],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF03.PlaySound(LFInstructorSound[1],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF04.PlaySound(LFInstructorSound[1],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF05.PlaySound(LFInstructorSound[1],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	StartTimer("LFInstructorOutro",(LengthLFInstructor[1] - float(LengthLFEcho)),false);
}
*/

/*
State StartLF
{
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "LFCheckOutofTubes")
		{
			if (LFValidTargetsHit < LFInitialValidTargets)
			{
				ChangeState("LFOutofTubes");
			}
			return true;
		}
		if (Name == "LFTimeLimitExceeded")
		{
			ChangeState("LFFailTime");
			return true;
		}
		if (Name == "CaptureLFCLU")
		{
			USERCLU=AGP_Weapon(CaptureEvent(Player.Weapon.Tag));
			return true;
		}
		if (Name == "LFEncouragement")
		{
			PlayLFEncouragement();
		}
		return false;
	}
Begin:
	Speaker_LF01.PlaySound(LFInstructorSound[12],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF02.PlaySound(LFInstructorSound[12],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF03.PlaySound(LFInstructorSound[12],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF04.PlaySound(LFInstructorSound[12],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF05.PlaySound(LFInstructorSound[12],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	PlayerLock(false,false);
	SetClockTimedLF();
	bInLF=true;
	Pickup_Javelin_LF_CLU(LFCLU).bCanPickUp=true;
}
*/

/*
State LFFailOutsideZone
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state LFFailOutsideZone");
	}
	Javelin_LF_CLU(USERCLU).bCanFire=false;
	bFailLFZone=true;
	PlayerLock(true,true);
	LFStopTime=Level.TimeSeconds;
	LFTimeTotal=GetClockTime();
	StopClock();
	Sleep(1);
	Speaker_LF01.PlaySound(LFInstructorSound[2],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF02.PlaySound(LFInstructorSound[2],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF03.PlaySound(LFInstructorSound[2],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF04.PlaySound(LFInstructorSound[2],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF05.PlaySound(LFInstructorSound[2],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Sleep((LengthLFInstructor[1] - float(LengthLFEcho)));
	aarScoreboard();
}
*/

/*
State LFFailTime
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state LFFailTime");
	}
	Javelin_LF_CLU(USERCLU).bTotalLock=true;
	PlayerLock(true,true);
	LFStopTime=Level.TimeSeconds;
	LFTimeTotal=GetClockTime();
	StopClock();
	Speaker_LF01.PlaySound(LFInstructorSound[3],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF02.PlaySound(LFInstructorSound[3],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF03.PlaySound(LFInstructorSound[3],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF04.PlaySound(LFInstructorSound[3],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF05.PlaySound(LFInstructorSound[3],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Sleep((LengthLFInstructor[2] + LengthDelay));
	aarScoreboard();
}
*/

/*
State LFOutofTubes
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state LFOutofTubes");
	}
	Javelin_LF_CLU(USERCLU).bCanFire=false;
	PlayerLock(true,true);
	LFStopTime=Level.TimeSeconds;
	LFTimeTotal=GetClockTime();
	StopClock();
	Speaker_LF01.PlaySound(LFInstructorSound[4],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF02.PlaySound(LFInstructorSound[4],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF03.PlaySound(LFInstructorSound[4],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF04.PlaySound(LFInstructorSound[4],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF05.PlaySound(LFInstructorSound[4],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Sleep((LengthLFInstructor[3] + LengthDelay));
	aarScoreboard();
}
*/

/*
State LFComplete
{
Begin:
	if (bDebug)
	{
		Log("AAGA in state LFComplete");
	}
	PlayerLock(true,true);
	LFStopTime=Level.TimeSeconds;
	LFTimeTotal=GetClockTime();
	StopClock();
	Speaker_LF01.PlaySound(LFInstructorSound[5],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF02.PlaySound(LFInstructorSound[5],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF03.PlaySound(LFInstructorSound[5],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF04.PlaySound(LFInstructorSound[5],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF05.PlaySound(LFInstructorSound[5],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Sleep((LengthLFInstructor[4] + LengthDelay));
	FadeOut(2,true);
	FadeIn(2,true);
	bInLF=false;
	aarScoreboard();
}
*/

/*
State PlayerDiedInLF
{
Begin:
	Sleep(LengthDelay);
	Speaker_LF01.PlaySound(LFInstructorSound[11],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF02.PlaySound(LFInstructorSound[11],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF03.PlaySound(LFInstructorSound[11],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF04.PlaySound(LFInstructorSound[11],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Speaker_LF05.PlaySound(LFInstructorSound[11],0,LFSpeakerVolume,,LFSpeakerRadius,,true);
	Sleep((LengthLFInstructor[10] - float(LengthLFEcho)));
	DisplayMissionCompleteOther("t_aao_ui.uniform.t_ui_uniform_pin_branch_infantry","You have been injured.","Would you like to restart the training?",128,128,7,"None","AGP_Interface.AAMissionCompletePageJavelinTraining_Died");
}
*/

/*
State PlayerDiedNotInLF
{
Begin:
	Player.PlaySound(PlayerDiedNotLFSound,0,1,,10000,,false);
	Sleep(LengthPlayerDiedNotLFSound);
	DisplayMissionCompleteOther("t_aao_ui.uniform.t_ui_uniform_pin_branch_infantry","You have been injured.","Would you like to restart the training?",128,128,7,"None","AGP_Interface.AAMissionCompletePageJavelinTraining_Died");
}
*/

/*
State Cheater
{
	simulated Function BeginState()
	{
		if (Tent_Instructor.IsPlayingLIPSincAnim())
		{
			Tent_Instructor.StopLIPSincAnim();
		}
		if (BST_Instructor.IsPlayingLIPSincAnim())
		{
			BST_Instructor.StopLIPSincAnim();
		}
		if (LFSignUp_Instructor.IsPlayingLIPSincAnim())
		{
			LFSignUp_Instructor.StopLIPSincAnim();
		}
		if (Controller != nullptr)
		{
			DisplayMissionCompleteOther("t_aao_ui.uniform.t_ui_uniform_pin_branch_infantry","You Cheated","Would you like to try again?",128,128,7,"None","AGP_Interface.AAMissionCompletePageJavelinTraining_LF");
		}
	}
}
*/

void AEL_JavelinTraining::PreInit()
{
	/*
	BSTCLU = Pickup(CaptureEvent('BSTCLU'));
	JTube = Pickup(CaptureEvent('JTube'));
	LFCLU = Pickup(CaptureEvent('LFCLU'));
	Javelin_Assembled = StaticMeshActor(GetActor('Javelin_Assembled'));
	PCtoCLUWire1 = StaticMeshActor(GetActor('PCtoCLUWire1'));
	PCtoCLUWire2 = StaticMeshActor(GetActor('PCtoCLUWire2'));
	TVolumeLF01 = TriggerVolume(CaptureEvent('TVolumeLF01'));
	TVolumeLF02 = TriggerVolume(CaptureEvent('TVolumeLF02'));
	TVolumeLF03 = TriggerVolume(CaptureEvent('TVolumeLF03'));
	TVolumeLF04 = TriggerVolume(CaptureEvent('TVolumeLF04'));
	TVolumeLF05 = TriggerVolume(CaptureEvent('TVolumeLF05'));
	TVolumeLFTargets02 = TriggerVolume(CaptureEvent('TVolumeLFTargets02'));
	TVolumeLFTargets03 = TriggerVolume(CaptureEvent('TVolumeLFTargets03'));
	TVolumeLFTargets04 = TriggerVolume(CaptureEvent('TVolumeLFTargets04'));
	TVolumeLFTargets05 = TriggerVolume(CaptureEvent('TVolumeLFTargets05'));
	LFSkipIntroTrigger = AGP_UseTrigger(CaptureEvent('LFSkipIntroTrigger'));
	sbUseTrigger = AGP_UseTrigger(CaptureEvent('sbUseTrigger'));
	aarDisplay = TextDisplay(GetActor('aarDisplay'));
	BST_Instructor_Trigger = AGP_UseTrigger(CaptureEvent('BST_Instructor_Trigger'));
	TentInstructorTrigger = AGP_UseTrigger(CaptureEvent('TentInstructorTrigger'));
	LiveFireSignUpTrigger = AGP_UseTrigger(CaptureEvent('LiveFireSignUpTrigger'));
	TentInstructorUseTip = TentInstructorTrigger.HUDText;
	LiveFireSignUpUseTip = LiveFireSignUpTrigger.HUDText;
	LFSkipIntroUseTip = LFSkipIntroTrigger.HUDText;
	BST_Instructor_Volume = TriggerVolume(CaptureEvent('BST_Instructor_Volume'));
	Tent_Instructor_Volume = TriggerVolume(CaptureEvent('Tent_Instructor_Volume'));
	TentVolume = TriggerVolume(CaptureEvent('TentVolume'));
	TentLockpoint = Teleporter(GetActor('TentLockpoint'));
	BSTRangeLockpoint = AGP_Viewpoint(GetActor('BSTRangeLockpoint'));
	LiveFireLockpoint = Teleporter(GetActor('LiveFireLockpoint'));
	ScoreboardLockpoint = Teleporter(GetActor('ScoreboardLockpoint'));
	Speaker_LF01 = AGP_Sound(GetActor('Speaker_LF01'));
	Speaker_LF02 = AGP_Sound(GetActor('Speaker_LF02'));
	Speaker_LF03 = AGP_Sound(GetActor('Speaker_LF03'));
	Speaker_LF04 = AGP_Sound(GetActor('Speaker_LF04'));
	Speaker_LF05 = AGP_Sound(GetActor('Speaker_LF05'));
	BinkSound = AGP_Sound(GetActor('JavelinTrainingNarration'));
	BinkVolume = BinkSound.SoundVolume;
	*/
}

void AEL_JavelinTraining::PostPostInit()
{
	/*
	Super::PostPostInit();
	Player.SetEventLab(this);
	CaptureController();
	BST_Instructor = NPC_ACUBasicSoldier(GetActor('BST_Instructor'));
	Tent_Instructor = NPC_ACUBasicSoldier(GetActor('Tent_Instructor'));
	LFSignUp_Instructor = NPC_ACUBasicSoldier(GetActor('LFSignUp_Instructor'));
	LFSignUp_Instructor.SetCollision(false, false, false);
	LFSignUp_Instructor.bHidden = true;
	BST_Instructor_Trigger.SetCollision(true);
	TentInstructorTrigger.SetCollision(true);
	LiveFireSignUpTrigger.SetCollision(true);
	Javelin_Assembled.bHidden = true;
	Javelin_Assembled.ResetStaticFilterState();
	PCtoCLUWire2.bHidden = true;
	PCtoCLUWire2.ResetStaticFilterState();
	if (bDebug)
	{
		Log("Hiding Javelin");
	}
	ChangeState('StartMission');
	*/
}

bool AEL_JavelinTraining::TriggerVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case 'BST_Instructor_Volume':
		return BST_Instructor_Volume_Enter(Trigger, Instigator);
	case 'Tent_Instructor_Volume':
		return Tent_Instructor_Volume_Enter(Trigger, Instigator);
	case 'TVolumeLF01':
		return TVolumeLF_Enter(Trigger, Instigator);
	case 'TVolumeLF02':
		return TVolumeLF_Enter(Trigger, Instigator);
	case 'TVolumeLF03':
		return TVolumeLF_Enter(Trigger, Instigator);
	case 'TVolumeLF04':
		return TVolumeLF_Enter(Trigger, Instigator);
	case 'TVolumeLF05':
		return TVolumeLF_Enter(Trigger, Instigator);
	case 'TVolumeLFTargets02':
		return TVolumeLFTargets_Enter(Trigger, Instigator);
	case 'TVolumeLFTargets03':
		return TVolumeLFTargets_Enter(Trigger, Instigator);
	case 'TVolumeLFTargets04':
		return TVolumeLFTargets_Enter(Trigger, Instigator);
	case 'TVolumeLFTargets05':
		return TVolumeLFTargets_Enter(Trigger, Instigator);
	case 'TentVolume':
		return TentVolume_Enter(Trigger, Instigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /EliZ
}

bool AEL_JavelinTraining::TriggerVolume_Exit(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case 'TVolumeLF01':
		return TVolumeLF_Exit(Trigger, Instigator);
	case 'TVolumeLF02':
		return TVolumeLF_Exit(Trigger, Instigator);
	case 'TVolumeLF03':
		return TVolumeLF_Exit(Trigger, Instigator);
	case 'TVolumeLF04':
		return TVolumeLF_Exit(Trigger, Instigator);
	case 'TVolumeLF05':
		return TVolumeLF_Exit(Trigger, Instigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /EliZ
}

bool AEL_JavelinTraining::TentVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	bEnteredTent = true;
	TentVolume.bActive = false;
	*/
	return true;
}

bool AEL_JavelinTraining::TVolumeLF_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	if (bDebug)
	{
		Log("AAGA TVolumeLF_Enter");
	}
	bLFInSafeZone = true;
	*/
	return true;
}

bool AEL_JavelinTraining::TVolumeLF_Exit(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	if (bDebug)
	{
		Log("AAGA TVolumeLF_Exit");
	}
	bLFInSafeZone = false;
	*/
	return true;
}

bool AEL_JavelinTraining::TVolumeLFTargets_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	if (bDebug)
	{
		Log("AAGA TVolumeLFTargets_Enter");
	}
	switch (Trigger.Tag)
	{
	case 'TVolumeLFTargets02':
	case 'TVolumeLFTargets03':
	case 'TVolumeLFTargets04':
	case 'TVolumeLFTargets05':
		StartLFGroup(Trigger);
		return true;
	default:
		return true;
	}
	*/
	return false;    //FAKE   /EliZ
}

bool AEL_JavelinTraining::Tent_Instructor_Volume_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	//PlayTip("Talk to SSG Wood about Javelin Training", "", PlayTipDisplayTime);
	//Tent_Instructor_Volume.bActive = false;
	return true;
}

bool AEL_JavelinTraining::BST_Instructor_Volume_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	//PlayTip("Talk to SFC Schafer for BST Training", "", PlayTipDisplayTime);
	//BST_Instructor_Volume.bActive = false;
	return true;
}

bool AEL_JavelinTraining::AGP_UseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case 'BST_Instructor_Trigger':
		return BST_Instructor_Trigger_UsedBy(Trigger, Instigator);
	case 'sbUseTrigger':
		return sbUseTrigger_UsedBy(Trigger, Instigator);
	case 'TentInstructorTrigger':
		return TentInstructorTrigger_UsedBy(Trigger, Instigator);
	case 'LiveFireSignUpTrigger':
		return LiveFireSignUpTrigger_UsedBy(Trigger, Instigator);
	case 'LFSkipIntroTrigger':
		return LFSkipIntroTrigger_UsedBy(Trigger, Instigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /EliZ
}

bool AEL_JavelinTraining::BST_Instructor_Trigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	/*
	if (Player.bIsProne || Player.bIsCrouched)
	{
		PlayLSAnim('S_Jave_Bst_Instructor_Vo_32', BST_Instructor, 1, 512);
	}
	else
	{
		BST_Instructor_Trigger.bActive = false;
		BST_Instructor_Trigger.SetCollision(false, false);
		BST_Instructor_Trigger.HUDText = "";
		BST_Instructor_Volume.bActive = false;
		Player.ShouldStand(true);
		ChangeState('WelcomeBST');
		return true;
	}
	*/
	return false;    //FAKE   /EliZ
}

bool AEL_JavelinTraining::sbUseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	uploadStatsLF();
	return true;
}

bool AEL_JavelinTraining::TentInstructorTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	/*
	if (Player.bIsProne || Player.bIsCrouched)
	{
		PlayLSAnim('S_Jave_Tent_Instructor_Vo_02', Tent_Instructor, 1, 512);
	}
	else
	{
		if (Tent_Instructor.IsPlayingLIPSincAnim())
		{
			Tent_Instructor.StopLIPSincAnim();
			PlayerLock(false, false);
			TentInstructorTrigger.HUDText = TentInstructorUseTip;
		}
		else
		{
			bEnteredTent = true;
			PlayerLock(true, false);
			if (PassedBST())
			{
				StartTimer('tmrTalktoTentInstructor', LengthTentInstructor[1], false);
				PlayLSAnim('S_Jave_Tent_Instructor_Vo_01', Tent_Instructor, 1, 512);
			}
			else
			{
				StartTimer('tmrTalktoTentInstructor', LengthTentInstructor[0], false);
				PlayLSAnim('S_Jave_Tent_Instructor_Vo_00', Tent_Instructor, 1, 512);
			}
			TentInstructorTrigger.HUDText = "Skip Dialog";
		}
	}
	*/
	return true;
}

bool AEL_JavelinTraining::LiveFireSignUpTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	/*
	if (Player.bIsProne || Player.bIsCrouched)
	{
		PlayLSAnim('S_Jave_LF_SignUp_Vo_01', LFSignUp_Instructor, 1, 512);
	}
	else
	{
		if (LFSignUp_Instructor.IsPlayingLIPSincAnim())
		{
			LFSignUp_Instructor.StopLIPSincAnim();
			PlayerLock(false, false);
			LiveFireSignUpTrigger.HUDText = LiveFireSignUpUseTip;
			StopTimer('tmrTalktoLFSignUp', 0);
		}
		else
		{
			LiveFireSignUpTrigger.HUDText = "Cancel Sign Up";
			PlayerLock(true, false);
			StartTimer('tmrTalktoLFSignUp', (LengthLFSignUpInstructor[0] + LengthDelay), false);
			PlayLSAnim('S_Jave_LF_SignUp_Vo_00', LFSignUp_Instructor, 1, 512);
		}
	}
	*/
	return true;
}

bool AEL_JavelinTraining::LFSkipIntroTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	//StopTimer('LFInstructorIntro', 0);
	//ChangeState('CountdownLF');
	return true;
}

bool AEL_JavelinTraining::Timer_Timer(FName Name)
{
	if (Name == "tmrLengthyLockVO")
	{
		bLengthyLockVO = false;
	}
	return false;
}

void AEL_JavelinTraining::SetClock()
{
	//StartClock(, false);
}

void AEL_JavelinTraining::SetClockTimedV()
{
	//StartClock(int((VirtualCourseTimeLimit * float(60))), true);
	//StartTimer('VTimeLimitExceeded', (VirtualCourseTimeLimit * float(60)), false);
}

void AEL_JavelinTraining::SetClockTimedLF()
{
	/*
	StartClock(int((LFCourseTimeLimit * float(60))), true);
	StartTimer('LFTimeLimitExceeded', (LFCourseTimeLimit * float(60)), false);
	LFStartTime = Level.TimeSeconds;
	if (bDebug)
	{
		Log("AAGA LFStartTime is : " $ string(LFStartTime));
	}
	*/
}

int32 AEL_JavelinTraining::GetClockSeconds()
{
	//return int(((LFCourseTimeLimit * float(60)) - float(Level.Game.GameReplicationInfo.RemainingTime)));
	return 0;    //FAKE   /ELiZ
}

bool AEL_JavelinTraining::aarScoreboard()
{
	/*
	FString LFDateToday = "";
	ClearClock();
	Javelin_LF_CLU(USERCLU).bTotalLock = false;
	Player.bCanSwapWeapons = false;
	if (Player.getHandsInventory().IsA('WEAPON_Javelin'))
	{
		Javelin_LF_CLU(USERCLU).UnZoom();
		Javelin_LF_CLU(USERCLU).DropFrom(Player.Location);
	}
	ForcePlayerCrouch(true);
	FadeOut(2, true);
	Player.SetLocation(ScoreboardLockpoint.Location);
	Controller.SetRotation(ScoreboardLockpoint.Rotation);
	FadeIn(2, true);
	PlayerLock(true, true);
	if (!bFailLFZone)
	{
		if ((LFStopTime - LFStartTime) < float(240))
		{
			LFTimeScore = 1000;
		}
		else
		{
			LFTimeScore = int((float(1000) - (Log10(((((LFStopTime - LFStartTime) - 240) / (360 / 99)) + 1)) * 400)));
		}
		if (LFValidTargetsHit < LFInitialValidTargets)
		{
			LFTimeScore = Clamp(LFTimeScore, 0, 300);
		}
		LFValidScore = (LFValidTargetsHit * 300);
		LFInvalidScore = (LFInvalidTargetsHit * -400);
		LFAccuracyScore = LFAccuracy;
		LFTubeScore = (((LFValidTargetsHit * 100) * LFValidTargetsHit) / LFTubesUsed);
		LFFinalScore = ((((LFValidScore + LFInvalidScore) + LFTimeScore) + LFAccuracyScore) + LFTubeScore);
	}
	else
	{
		LFTimeScore = 0;
		LFValidScore = 0;
		LFInvalidScore = 0;
		LFAccuracyScore = 0;
		LFTubeScore = 0;
		LFFinalScore = 0;
	}
	LFDateToday = string(Level.Year) $ "/";
	if (Level.Month < 10)
	{
		(LFDateToday $ = "0");
	}
	(LFDateToday $ = string(Level.Month) $ "/");
	if (Level.Day < 10)
	{
		(LFDateToday $ = "0");
	}
	(LFDateToday $ = string(Level.Day));
	aarDisplay.SetValue('aDateToday', LFDateToday);
	aarDisplay.SetValue('aUserName', Controller.UserName);
	aarDisplay.SetValue('aLiveFireVtHit', string(LFValidTargetsHit));
	aarDisplay.SetValue('aLiveFireVtScore', string(LFValidScore));
	aarDisplay.SetValue('aLiveFireItHit', string(LFInvalidTargetsHit));
	aarDisplay.SetValue('aLiveFireItScore', string(LFInvalidScore));
	aarDisplay.SetValue('aTubesUsed', string(LFTubesUsed));
	aarDisplay.SetValue('aTubesUsedScore', string(LFTubeScore));
	aarDisplay.SetValue('aAccuracyScore', string(LFAccuracyScore));
	aarDisplay.SetValue('aTime', LFTimeTotal);
	aarDisplay.SetValue('aTimeScore', string(LFTimeScore));
	aarDisplay.SetValue('aFinalScore', string(LFFinalScore));
	*/
	return true;
}

float AEL_JavelinTraining::Log10(float A)
{
	//return (Loge(A) / Loge(10));
	return 0;    //FAKE   /ELiZ
}

bool AEL_JavelinTraining::uploadStatsLF()
{
	/*
	local Security secLocalSecurity;
	local class<Security>  scLocalSecurityClass;
	local TArray<FString> asMD5ForMap;
	local TArray<FString> asMD5ForScript;
	FString sMD5ForMap = "";
	FString sMD5ForScript = "";
	DebugLog(DEBUG_EventLab, "uploadStats:");
	if (StudentController(Controller).bUsedCheats)
	{
		DisplayMissionCompleteOther("t_aao_ui.uniform.t_ui_uniform_pin_branch_infantry", "Javelin LF Training Complete", "Would you like to try again?", 128, 128, 7, "None", "AGP_Interface.AAMissionCompletePageJavelinTraining_LF");
		return false;
	}
	Controller.ResetAuthExtraMissionData();
	if (LFFinalScore > 0)
	{
		Controller.AddAuthExtraMissionData("1");
	}
	else
	{
		Controller.AddAuthExtraMissionData("0");
	}
	Controller.AddAuthExtraMissionData("" $ string(LFValidTargetsHit));
	Controller.AddAuthExtraMissionData("" $ string(LFValidScore));
	Controller.AddAuthExtraMissionData("" $ string(LFInvalidTargetsHit));
	Controller.AddAuthExtraMissionData("" $ string(LFInvalidScore));
	Controller.AddAuthExtraMissionData("" $ string(LFTubesUsed));
	Controller.AddAuthExtraMissionData("" $ string(LFTubeScore));
	Controller.AddAuthExtraMissionData("" $ string(LFAccuracyScore));
	Controller.AddAuthExtraMissionData("" $ LFTimeTotal);
	Controller.AddAuthExtraMissionData("" $ string(LFTimeScore));
	Controller.AddAuthExtraMissionData("" $ string(LFFinalScore));
	StudentController(Controller).SetAuthMissionPassFlag(true);
	scLocalSecurityClass = class<Security>(DynamicLoadObject("Engine.Security", Class'Class'));
	if (scLocalSecurityClass != nullptr)
	{
		secLocalSecurity = Spawn(scLocalSecurityClass, Controller);
		if (secLocalSecurity != nullptr)
		{
			secLocalSecurity.LocalPerform(2, "../Maps/JavelinTraining.aao", "", asMD5ForMap);
			secLocalSecurity.LocalPerform(2, "../System/AGP_Script.u", "", asMD5ForScript);
			sMD5ForMap = asMD5ForMap[0];
			sMD5ForScript = asMD5ForScript[0];
		}
	}
	Controller.AddAuthExtraMissionData(sMD5ForMap);
	Controller.AddAuthExtraMissionData(sMD5ForScript);
	Controller.AddAuthExtraMissionData("LiveFireScores");
	DisplayMissionCompleteOther("t_aao_ui.uniform.t_ui_uniform_pin_branch_infantry", "Javelin LF Training Complete", "Would you like to save your results to your Personnel Jacket?", 128, 128, 7, "None", "AGP_Interface.AAMissionCompletePageJavelinTraining_LF");
	*/
	return true;
}

bool AEL_JavelinTraining::uploadStatsBST()
{
	/*
	local Security secLocalSecurity;
	local class<Security>  scLocalSecurityClass;
	local TArray<FString> asMD5ForMap;
	local TArray<FString> asMD5ForScript;
	FString sMD5ForMap = "";
	FString sMD5ForScript = "";
	DebugLog(DEBUG_EventLab, "uploadStats:");
	if (StudentController(Controller).bUsedCheats)
	{
		DisplayMissionCompleteOther("t_aao_ui.uniform.t_ui_uniform_pin_branch_infantry", "Javelin BST Training Complete", "Would you like to try again?", 128, 128, 7, "None", "AGP_Interface.AAMissionCompletePageJavelinTraining_BST");
		return false;
	}
	Controller.ResetAuthExtraMissionData();
	Controller.AddAuthExtraMissionData("1");
	Controller.AddAuthExtraMissionData("" $ string(LFValidTargetsHit));
	Controller.AddAuthExtraMissionData("" $ string(LFValidScore));
	Controller.AddAuthExtraMissionData("" $ string(LFInvalidTargetsHit));
	Controller.AddAuthExtraMissionData("" $ string(LFInvalidScore));
	Controller.AddAuthExtraMissionData("" $ string(LFTubesUsed));
	Controller.AddAuthExtraMissionData("" $ string(LFTubeScore));
	Controller.AddAuthExtraMissionData("" $ string(LFAccuracyScore));
	Controller.AddAuthExtraMissionData("" $ LFTimeTotal);
	Controller.AddAuthExtraMissionData("" $ string(LFTimeScore));
	Controller.AddAuthExtraMissionData("" $ string(LFFinalScore));
	Controller.SetAuthMissionPassFlag(true);
	scLocalSecurityClass = class<Security>(DynamicLoadObject("Engine.Security", Class'Class'));
	if (scLocalSecurityClass != nullptr)
	{
		secLocalSecurity = Spawn(scLocalSecurityClass, Controller);
		if (secLocalSecurity != nullptr)
		{
			secLocalSecurity.LocalPerform(2, "../Maps/JavelinTraining.aao", "", asMD5ForMap);
			secLocalSecurity.LocalPerform(2, "../System/AGP_Script.u", "", asMD5ForScript);
			sMD5ForMap = asMD5ForMap[0];
			sMD5ForScript = asMD5ForScript[0];
		}
	}
	Controller.AddAuthExtraMissionData(sMD5ForMap);
	Controller.AddAuthExtraMissionData(sMD5ForScript);
	Controller.AddAuthExtraMissionData("BSTTraining");
	DisplayMissionCompleteOther("t_aao_ui.uniform.t_ui_uniform_pin_branch_infantry", "Javelin BST Training Complete", "Would you like to save your results to your Personnel Jacket?", 128, 128, 7, "None", "AGP_Interface.AAMissionCompletePageJavelinTraining_BST");
	*/
	return true;
}

bool AEL_JavelinTraining::AGP_Character_Died(AAGP_Character* NotifyActor, AController* aInstigator)
{
	/*
	if (bInLF)
	{
		ChangeState('PlayerDiedInLF');
	}
	else
	{
		ChangeState('PlayerDiedNotInLF');
	}
	*/
	return true;
}

bool AEL_JavelinTraining::Pickup_PickedUp(APickup* NotifyActor, AActor* aInstigator, FString Parms)
{
	/*
	if (Parms == "PickedJT")
	{
		ChangeState('PickedJT');
	}
	if (Parms == "PickedCLU")
	{
		ChangeState('PickedCLU');
	}
	if (Parms == "PickedLFCLU")
	{
		StartTimer('CaptureLFCLU', 2, false);
	}
	if (Parms == "ShoulderedJT")
	{
		ChangeState('ShoulderedJT');
	}
	if (Parms == "CLUInHands")
	{
		ChangeState('CLUInHands');
	}
	if (Parms == "CLUUnZooming")
	{
		ChangeState('CLUUnZooming');
	}
	if (Parms == "CLUCycled")
	{
		ChangeState('CLUCycled');
	}
	if (Parms == "JLoadedAndCrouched")
	{
		ChangeState('JLoadedAndCrouched');
	}
	if (Parms == "PlayerLookingThroughSight")
	{
		ChangeState('PlayerLookingThroughSight');
	}
	if (Parms == "ForceMisFire")
	{
		ChangeState('ForceMisFire');
	}
	if (Parms == "NoLock")
	{
		ChangeState('NoLock');
	}
	if (Parms == "NoLock2")
	{
		ChangeState('NoLock2');
	}
	if (Parms == "NoLock3")
	{
		ChangeState('NoLock3');
	}
	if (Parms == "HasLock")
	{
		ChangeState('HasLock');
	}
	if (Parms == "LostLock")
	{
		ChangeState('LostLock');
	}
	if (Parms == "RegainedLock")
	{
		ChangeState('RegainedLock');
	}
	if (Parms == "T72Hit")
	{
		ChangeState('T72Hit');
	}
	if (Parms == "SecondT72Hit")
	{
		ChangeState('SecondT72Hit');
	}
	*/
	return true;
}

bool AEL_JavelinTraining::AGP_Character_Custom(AAGP_Character* NotifyActor, AActor* aInstigator, FString Parms)
{
	/*
	if (bInBST && (Parms == "CROUCHMODE,False"))
	{
		bUserCrouched = false;
		ChangeState('WaitForCrouch');
	}
	if (bInBST && (Parms == "CROUCHMODE,True"))
	{
		bUserCrouched = true;
		ChangeState('Crouched');
	}
	if (Parms == "PickedJT")
	{
		ChangeState('PickedJT');
	}
	if (Parms == "ShoulderedJT")
	{
		ChangeState('ShoulderedJT');
	}
	if (Parms == "PickedCLU")
	{
		ChangeState('PickedCLU');
	}
	if (Parms == "CLUInHands")
	{
		ChangeState('CLUInHands');
	}
	if (Parms == "CLUUnZooming")
	{
		ChangeState('CLUUnZooming');
	}
	if (Parms == "CLUCycled")
	{
		ChangeState('CLUCycled');
	}
	if (Parms == "JLoadedAndCrouched")
	{
		ChangeState('JLoadedAndCrouched');
	}
	if (Parms == "PlayerLookingThroughSight")
	{
		ChangeState('PlayerLookingThroughSight');
	}
	if (Parms == "ForceMisFire")
	{
		ChangeState('ForceMisFire');
	}
	if (Parms == "NoLock")
	{
		ChangeState('NoLock');
	}
	if (Parms == "NoLock2")
	{
		ChangeState('NoLock2');
	}
	if (Parms == "NoLock3")
	{
		ChangeState('NoLock3');
	}
	if (Parms == "HasLock")
	{
		ChangeState('HasLock');
	}
	if (Parms == "LostLock")
	{
		ChangeState('LostLock');
	}
	if (Parms == "RegainedLock")
	{
		ChangeState('RegainedLock');
	}
	if (Parms == "T72Hit")
	{
		ChangeState('T72Hit');
	}
	if (Parms == "SecondT72Hit")
	{
		ChangeState('SecondT72Hit');
	}
	*/
	return true;
}

bool AEL_JavelinTraining::AGP_Weapon_Custom(AAGP_Weapon* NotifyActor, AActor* aInstigator, FString Parms)
{
	/*
	if ((Parms == "ShoulderedJT") && (!bJTShouldered))
	{
		bJTShouldered = true;
		ChangeState('ShoulderedJT');
	}
	if (Parms == "CLUJamFixed")
	{
		ChangeState('FixJamFixed');
	}
	if ((Parms == "CLUCycled") && (!bCLUCycled))
	{
		bCLUCycled = true;
		ChangeState('CLUCycled');
	}
	if ((Parms == "RELOAD,False") && (!bBSTReloadedOnce))
	{
		bBSTLoaded = false;
		ChangeState('WaitForReload');
	}
	if ((Parms == "RELOAD,True") && (!bBSTReloadedOnce))
	{
		bBSTReloadedOnce = true;
		bBSTLoaded = true;
		ChangeState('Reloaded');
	}
	if (Parms == "CLUUnZooming")
	{
		if (bDebug)
		{
			Log("AAGA parms CLUUnZooming");
		}
		SetLocationTent();
	}
	if (Parms == "CLUZooming")
	{
		if (bDebug)
		{
			Log("AAGA parms CLUZooming");
		}
		if (IsInState('CLUInHands'))
		{
			Javelin_BST_CLU(USERCLU).bCanZoom = false;
			ChangeState('CLUZooming');
		}
		else
		{
			if (IsInState('JLoadedAndCrouched'))
			{
				Javelin_BST_CLU(USERCLU).bCanZoom = false;
				ChangeState('PlayerLookingThroughSight');
			}
			else
			{
				if (IsInState('FixJamFixed'))
				{
					Javelin_BST_CLU(USERCLU).bCanZoom = false;
					ChangeState('PlayerLookingThroughSight2');
				}
			}
		}
	}
	if ((!bInVirtual) && (Parms == "ForceMisFire"))
	{
		ChangeState('ForceMisFire');
	}
	if ((!bInVirtual) && (Parms == "NoLock"))
	{
		if (NumNoLock == 0)
		{
			ChangeState('NoLock');
		}
		else
		{
			if (NumNoLock == 1)
			{
				ChangeState('NoLock2');
			}
			else
			{
				if (NumNoLock == 2)
				{
					ChangeState('NoLock3');
				}
			}
		}
		NumNoLock++;
	}
	if ((!bInVirtual) && (Parms == "HasLock"))
	{
		if (bFirstLock)
		{
			ChangeState('HasLock');
			bFirstLock = false;
		}
		else
		{
			ChangeState('RegainedLock');
		}
	}
	if ((!bInVirtual) && (Parms == "LostLock"))
	{
		ChangeState('LostLock');
	}
	if (Parms == "BSTThrown")
	{
		SetLocationTent();
		Player.LimitRotation(false);
		Player.bCanSwapWeapons = true;
		ChangeState('BSTThrown');
	}
	if (Parms == "LFFired")
	{
		LFTubesUsed++;
		if (CheckInSafeFireZone())
		{
			if (LFTubesUsed == LFInitialTubes)
			{
				Javelin_LF_CLU(USERCLU).bCanFire = false;
			}
		}
		else
		{
			ChangeState('LFFailOutsideZone');
		}
	}
	*/
	return true;
}

bool AEL_JavelinTraining::BaseProjectile_Explode(ABaseProjectile* Projectile, AActor* aInstigator, FString Parms)
{
	/*
	if (bInLF && (LFTubesUsed == LFInitialTubes))
	{
		StartTimer('LFCheckOutofTubes', 1, false);
	}
	else
	{
		if (IsInState('StartVirtual'))
		{
			if (bDebug)
			{
				Log("AAGA target destroyed");
			}
			if (NumVirtualTargetsHit < NumVirtualTargets)
			{
				Javelin_BST_CLU(USERCLU).AmmoType.AmmoAmount = 1;
			}
		}
	}
	*/
	return true;
}

bool AEL_JavelinTraining::AGP_Vehicle_Died(AAGP_Vehicle* Vehicle, AActor* aController, FString Parms)
{
	/*
	float Accuracy = 0;
	if (bDebug)
	{
		Log("AAGA calling AGP_Vehicle_Died");
	}
	if (Parms == "AGPVehicleDied")
	{
		if (Vehicle.IsA('T62A'))
		{
			if (bDebug)
			{
				Log("AAGA calling AGP_Vehicle_Custom, parms is T72Hit");
			}
			if (Vehicle.Tag == 'T62A_JT_Target1')
			{
				ChangeState('T72Hit');
			}
			else
			{
				if (Vehicle.Tag == 'T62A_JT_Target2')
				{
					ChangeState('SecondT72Hit');
				}
				else
				{
					if (IsInState('StartVirtual'))
					{
						if (bDebug)
						{
							Log("AAGA target destroyed");
						}
						NumVirtualTargetsHit++;
						Vehicle.ValidJavelinTarget = 0;
						if (NumVirtualTargetsHit >= NumVirtualTargets)
						{
							ClearClock();
							ChangeState('VPass');
						}
					}
					else
					{
						if (bInLF)
						{
							if (bDebug)
							{
								Log("AAGA in bInLF, destroyed T62");
							}
							if (Vehicle.fJavelinAccuracy < float(15000))
							{
								Accuracy = 200;
							}
							else
							{
								if (Vehicle.fJavelinAccuracy > float(25000))
								{
									Accuracy = 0;
								}
								else
								{
									Accuracy = (100 + ((float(25000) - Vehicle.fJavelinAccuracy) * 0.01));
								}
							}
							(LFAccuracy += Clamp(int(Accuracy), 0, 200));
							if (bDebug)
							{
								Log("Total LFAccuracy =" @ string(LFAccuracy), 'PICA');
							}
							LFValidTargetsHit++;
							if (LFValidTargetsHit >= LFInitialValidTargets)
							{
								ChangeState('LFComplete');
							}
							else
							{
								if (IsInState('StartLF') && (LFTubesUsed < LFInitialTubes))
								{
									switch (LFValidTargetsHit)
									{
									case 2:
										CurrentLFEncouragement = LFInstructorSound[6];
										StartTimer('LFEncouragement', 2, false);
										break;
									case 4:
										CurrentLFEncouragement = LFInstructorSound[7];
										StartTimer('LFEncouragement', 2, false);
										break;
									case 6:
										CurrentLFEncouragement = LFInstructorSound[8];
										StartTimer('LFEncouragement', 2, false);
										break;
									case 8:
										CurrentLFEncouragement = LFInstructorSound[9];
										StartTimer('LFEncouragement', 2, false);
										break;
									case 9:
										CurrentLFEncouragement = LFInstructorSound[10];
										StartTimer('LFEncouragement', 2, false);
										break;
									default:
									}
								}
							}
						}
					}
				}
			}
		}
		if (Vehicle.IsA('Technical'))
		{
			if (bInVirtual)
			{
				if (bDebug)
				{
					Log("AAGA in bInVirtual, changing state");
				}
				ChangeState('VFailInvalid');
			}
			else
			{
				if (bInLF)
				{
					if (bDebug)
					{
						Log("AAGA in bInLF, destroyed Technical");
					}
					LFInvalidTargetsHit++;
				}
			}
		}
	}
	*/
	return true;
}

void AEL_JavelinTraining::EventLabNotifyCheat()
{
	if ((!bAllowCheats) && bDebug)
	{
		//GotoState('Cheater');
	}
}

void AEL_JavelinTraining::CaptureBSTVehicleFactories()
{
	/*
	local AGP_Vehicles.AGP_VehicleFactory Factory;
	ForEach AllActors(Class'AGP_Vehicles.AGP_VehicleFactory', Factory, 'BSTInvalidFactory')
	{
		BSTInvalidFactory.insert(BSTInvalidFactory.Num(), 1);
		BSTInvalidFactory[(BSTInvalidFactory.Num() - 1)] = Factory;
	}
	ForEach AllActors(Class'AGP_Vehicles.AGP_VehicleFactory', Factory, 'BSTValidFactory')
	{
		BSTValidFactory.insert(BSTValidFactory.Num(), 1);
		BSTValidFactory[(BSTValidFactory.Num() - 1)] = Factory;
	}
	if (bDebug)
	{
		Log(string(BSTInvalidFactory.Num()) $ " invalid factories and " $ string(BSTValidFactory.Num()) $ " valid factories for the BST");
	}
	*/
}

void AEL_JavelinTraining::SpawnVirtualTargets()
{
	int32 i = 0;
	int32 nextfactory = 0;
	/*
	NumVirtualTargetsHit = 0;
	for (i = 0; i < NumVirtualTargets; i++)
	{
		nextfactory = Rand(BSTInvalidFactory.Num());
		if (BSTInvalidFactory[nextfactory].LastSpawned != nullptr)
		{
			if (bDebug)
			{
				Log(string(BSTInvalidFactory[nextfactory]) $ " has a vehicle, skipping");
			}
			nextfactory = Rand(BSTInvalidFactory.Num());
		}
		BSTInvalidFactory[nextfactory].SpawnedVehicleTag = 'BSTInvalidTarget';
		BSTInvalidFactory[nextfactory].SpawnVehicle();
		if (bDebug)
		{
			Log("BST Invalid Factory " $ string(BSTInvalidFactory[nextfactory]) $ " selected, vehicle retagged " $ string(BSTInvalidFactory[nextfactory].SpawnedVehicleTag));
		}
	}
	for (i = 0; i < NumVirtualTargets; i++)
	{
		nextfactory = Rand(BSTValidFactory.Num());
		if (BSTValidFactory[nextfactory].LastSpawned != nullptr)
		{
			if (bDebug)
			{
				Log(string(BSTValidFactory[nextfactory]) $ " has a vehicle, skipping");
			}
			nextfactory = Rand(BSTValidFactory.Num());
		}
		BSTValidFactory[nextfactory].SpawnedVehicleTag = 'BSTValidTarget';
		BSTValidFactory[nextfactory].SpawnVehicle();
		if (bDebug)
		{
			Log("BST Valid Factory " $ string(BSTValidFactory[nextfactory]) $ " selected, vehicle retagged " $ string(BSTValidFactory[nextfactory].SpawnedVehicleTag));
		}
	}
	*/
}

void AEL_JavelinTraining::CaptureVirtualTargets()
{
	/*
	int32 Valid = 0;
	int32 Invalid = 0;
	local AAGP_Vehicle* Target;
	local HelpIcon Icon;
	if ((Valid < 3) && (Invalid < 3))
	{
		ForEach AllActors(Class'AGP_Vehicles.AGP_Vehicle', Target, 'BSTValidTarget')
		{
			if (Target.EventLab != Self)
			{
				Target.SetEventLab(this);
				if (bDebug)
				{
					Log("Captured " $ string(Target));
				}
				if (bDebug && bHelpIcon)
				{
					Icon = Spawn(class'AGP_Script.HelpIcon');
					Icon.SetHelpIcon(Target, vect(0, 0, 1000), 200);
				}
				Valid++;
			}
		}
		ForEach AllActors(Class'AGP_Vehicles.AGP_Vehicle', Target, 'BSTInvalidTarget')
		{
			if (Target.EventLab != Self)
			{
				Target.SetEventLab(this);
				if (bDebug)
				{
					Log("Captured " $ string(Target));
				}
				if (bDebug && bHelpIcon)
				{
					Icon = Spawn(class'AGP_Script.HelpIcon');
					Icon.SetHelpIcon(Target, vect(0, 0, 1000), 200);
				}
				Invalid++;
			}
		}
	}
	*/
}

void AEL_JavelinTraining::DestroyVT72Target(AAGP_Vehicle* tank)
{
	/*
	local Emitter E;
	tank.Destroy();
	ForEach AllActors(Class'Emitter', E)
	{
		if (E.Tag != 'Level')
		{
			E.Destroy();
		}
	}
	*/
}

void AEL_JavelinTraining::DestroyVirtualTargets()
{
	/*
	local Emitter E;
	local HelpIcon Icon;
	local AAGP_Vehicle* Target;
	ForEach AllActors(Class'AGP_Vehicles.AGP_Vehicle', Target, 'BSTInvalidTarget')
	{
		AGP_VehicleFactory(Target.ParentFactory).LastSpawned = nullptr;
		Target.Destroy();
	}
	ForEach AllActors(Class'AGP_Vehicles.AGP_Vehicle', Target, 'BSTValidTarget')
	{
		AGP_VehicleFactory(Target.ParentFactory).LastSpawned = nullptr;
		Target.Destroy();
	}
	ForEach AllActors(Class'Emitter', E)
	{
		if (E.Tag != 'Level')
		{
			E.Destroy();
		}
	}
	ForEach AllActors(class'AGP_Script.HelpIcon', Icon)
	{
		Icon.Destroy();
	}
	*/
}

bool AEL_JavelinTraining::PassedBST()
{
	if (bDebug)
	{
		//Log("Auth is saying " $ string(Level.DidPlayerCompleteNewMission(Controller)) $ " on mission completion");
	}
	//return ((Level.DidPlayerCompleteNewMission(Controller) == 0) || bPassedBST);

	return false;    //FAKE   /ELiZ
}

bool AEL_JavelinTraining::CheckInSafeFireZone()
{
	return bLFInSafeZone;
}

void AEL_JavelinTraining::PlayLFEncouragement()
{
	/*
	Speaker_LF01.PlaySound(CurrentLFEncouragement, 0, LFSpeakerVolume, , LFSpeakerRadius, , true);
	Speaker_LF02.PlaySound(CurrentLFEncouragement, 0, LFSpeakerVolume, , LFSpeakerRadius, , true);
	Speaker_LF03.PlaySound(CurrentLFEncouragement, 0, LFSpeakerVolume, , LFSpeakerRadius, , true);
	Speaker_LF04.PlaySound(CurrentLFEncouragement, 0, LFSpeakerVolume, , LFSpeakerRadius, , true);
	Speaker_LF05.PlaySound(CurrentLFEncouragement, 0, LFSpeakerVolume, , LFSpeakerRadius, , true);
	*/
}

void AEL_JavelinTraining::SpawnLFSignupInstructor()
{
	/*
	LFSignUp_Instructor.bBlockActors = true;
	LFSignUp_Instructor.SetCollision(true, true, true);
	LFSignUp_Instructor.bHidden = false;
	LiveFireSignUpTrigger.bDisabled = false;
	LiveFireSignUpTrigger.HUDText = LiveFireSignUpUseTip;
	*/
}

void AEL_JavelinTraining::SpawnLFTargets()
{
	/*
	local NPCVehicleStart npcvs;
	ForEach AllActors(Class'AGP.NPCVehicleStart', npcvs)
	{
		npcvs.fpChanceOfSpawning = 100;
		npcvs.CreateNPC();
	}
	*/
}

void AEL_JavelinTraining::CaptureLFTargets()
{
	/*
	local AAGP_Vehicle* Target;
	int32 rnd = 0;
	bool bCaptured = false;
	ForEach AllActors(Class'AGP_Vehicles.AGP_Vehicle', Target, 'LFValidTarget')
	{
		bCaptured = false;
		if ((!bCaptured) && Target.Controller.IsInState('InitializeVehicle'))
		{
			rnd = Rand(4);
			if (((LFTargetGroup[rnd].ValidTarget.Num() < 2) && (rnd < 3)) || ((LFTargetGroup[rnd].ValidTarget.Num() < 1) && (rnd == 3)))
			{
				bCaptured = true;
				LFTargetGroup[rnd].ValidTarget.insert(0, 1);
				LFTargetGroup[rnd].ValidTarget[0] = Target;
				LFTargetGroup[rnd].ValidTarget[0].SetEventLab(this);
				if (bDebug)
				{
					Log("ValidTarget " $ string(Target) $ " captured in group " $ string(rnd) $ " and event lab is " $ string(LFTargetGroup[rnd].ValidTarget[0].EventLab));
				}
			}
		}
		if ((!Target.Controller.IsInState('InitializeVehicle')) && (Target.EventLab == nullptr))
		{
			Target.SetEventLab(this);
			if (bDebug)
			{
				Log("ValidTarget " $ string(Target) $ " is auto-start and has event lab " $ string(Target.EventLab));
			}
		}
	}
	ForEach AllActors(Class'AGP_Vehicles.AGP_Vehicle', Target, 'LFInvalidTarget')
	{
		bCaptured = false;
		if ((!bCaptured) && Target.Controller.IsInState('InitializeVehicle'))
		{
			rnd = Rand(4);
			if (LFTargetGroup[rnd].InvalidTarget.Num() < 2)
			{
				bCaptured = true;
				LFTargetGroup[rnd].InvalidTarget.insert(0, 1);
				LFTargetGroup[rnd].InvalidTarget[0] = Target;
				LFTargetGroup[rnd].InvalidTarget[0].SetEventLab(this);
				if (bDebug)
				{
					Log("InalidTarget " $ string(LFTargetGroup[rnd].InvalidTarget[0]) $ " captured in group " $ string(rnd) $ " and event lab is " $ string(LFTargetGroup[rnd].InvalidTarget[0].EventLab));
				}
			}
		}
		if ((!Target.Controller.IsInState('InitializeVehicle')) && (Target.EventLab == nullptr))
		{
			Target.SetEventLab(this);
			if (bDebug)
			{
				Log("InvalidTarget " $ string(Target) $ " is auto-start and has event lab " $ string(Target.EventLab));
			}
		}
	}
	*/
}

void AEL_JavelinTraining::StartLFGroup(ATriggerVolume* Trigger)
{
	/*
	int32 i = 0;
	int32 grp = 0;
	local HelpIcon Icon;
	if (!Trigger.bActive)
	{
		return;
	}
	switch (Trigger.Tag)
	{
	case 'TVolumeLFTargets02':
		grp = 0;
		break;
	case 'TVolumeLFTargets03':
		grp = 1;
		break;
	case 'TVolumeLFTargets04':
		grp = 2;
		break;
	case 'TVolumeLFTargets05':
		grp = 3;
		break;
	default:
	}
	for (i = 0; i < LFTargetGroup[grp].ValidTarget.Num(); i++)
	{
		if (LFTargetGroup[grp].ValidTarget[i] != nullptr)
		{
			NPCBasePreCrewedVehicleController(LFTargetGroup[grp].ValidTarget[i].Controller).NotifyTrigger(None, None);
			if (bDebug)
			{
				Log("Starting to move Group " $ string(grp) $ " ValidTarget (" $ string(LFTargetGroup[grp].ValidTarget[i]) $ ") " $ string(i) $ " at " $ string(LFTargetGroup[grp].ValidTarget[i].Location));
			}
			if (bDebug && bHelpIcon)
			{
				Icon = Spawn(class'AGP_Script.HelpIcon');
				Icon.SetHelpIcon(LFTargetGroup[grp].ValidTarget[i], vect(0, 0, 1000), 200);
			}
		}
	}
	for (i = 0; i < LFTargetGroup[grp].InvalidTarget.Num(); i++)
	{
		if (LFTargetGroup[grp].InvalidTarget[i] != nullptr)
		{
			NPCBasePreCrewedVehicleController(LFTargetGroup[grp].InvalidTarget[i].Controller).NotifyTrigger(None, None);
			if (bDebug)
			{
				Log("Starting to move Group " $ string(grp) $ " InvalidTarget (" $ string(LFTargetGroup[grp].InvalidTarget[i]) $ ") " $ string(i) $ " at " $ string(LFTargetGroup[grp].InvalidTarget[i].Location));
			}
			if (bDebug && bHelpIcon)
			{
				Icon = Spawn(class'AGP_Script.HelpIcon');
				Icon.SetHelpIcon(LFTargetGroup[grp].InvalidTarget[i], vect(0, 0, 1000), 200);
			}
		}
	}
	Trigger.bActive = false;
	*/
}

void AEL_JavelinTraining::EventLabTick(float DeltaTime)
{
	/*
	if (Javelin_BST_CLU(USERCLU) != nullptr)
	{
		if (Javelin_BST_CLU(USERCLU).IsZoomed() && Javelin_BST_CLU(USERCLU).bToggled)
		{
			Player.SetLocation(BSTRangeLockpoint.Location);
			Controller.SetRotation(BSTRangeLockpoint.Rotation);
			Player.rBaseRotation.Pitch = Controller.Rotation.Pitch;
			Player.rBaseRotation.Yaw = Controller.Rotation.Yaw;
			Player.rBaseRotation.Roll = 0;
			Player.rRotationLimits = rot(2000, 10000, 0);
			Player.LimitRotation(true);
			Javelin_BST_CLU(USERCLU).bToggled = false;
			bInTent = false;
		}
	}
	if (bInTent)
	{
		BST_Instructor.EyeTrack();
		Tent_Instructor.EyeTrack();
		LFSignUp_Instructor.EyeTrack();
	}
	*/
}

void AEL_JavelinTraining::SetLocationTent()
{
	/*
	FVector Adjust = FVector(0, 0, 0);
	Adjust.Z = 100;
	Player.SetLocation((TentLockpoint.Location - Adjust));
	Controller.SetRotation(TentLockpoint.Rotation);
	bInTent = true;
	*/
}

void AEL_JavelinTraining::ForcePlayerCrouch(bool bCrouch)
{
	/*
	bool bOldLockMovement = false;
	bool bOldLockRotation = false;
	bOldLockMovement = Controller.GetLockMovement();
	bOldLockRotation = Controller.GetLockRotation();
	PlayerLock(false, false);
	if (bCrouch)
	{
		if (!Player.bIsCrouched)
		{
			Controller.Crouching();
		}
	}
	else
	{
		if ((!Player.bIsCrouched) && (!Player.bIsProne))
		{
		}
		if (Player.bIsCrouched)
		{
			Controller.Crouching();
		}
		else
		{
			if (Player.bIsProne)
			{
				Controller.Crawling();
			}
		}
	}
	PlayerLock(bOldLockMovement, bOldLockRotation);
	*/
}

bool AEL_JavelinTraining::ELCheat(FString cheat)
{
	/*
	local AGP_Vehicles.AGP_VehicleFactory Factory;
	local AAGP_Vehicle* Target;
	local HelpIcon Icon;
	if (!bDebug)
	{
		return false;
	}
	switch (cheat)
	{
	case "lfscore":
		aarDisplay.SetValue('aDateToday', "2006/07/16");
		aarDisplay.SetValue('aUserName', "LampreyGuy");
		aarDisplay.SetValue('aLiveFireVtHit', string(10));
		aarDisplay.SetValue('aLiveFireVtScore', string(435));
		aarDisplay.SetValue('aLiveFireItHit', string(2));
		aarDisplay.SetValue('aLiveFireItScore', string(-30));
		aarDisplay.SetValue('aTubesUsed', string(10));
		aarDisplay.SetValue('aTubesUsedScore', string(975));
		aarDisplay.SetValue('aAccuracyScore', string(1972));
		aarDisplay.SetValue('aTime', "08:59");
		aarDisplay.SetValue('aTimeScore', string(150));
		aarDisplay.SetValue('aFinalScore', string(1875));
		return true;
	case "bstpass":
		SpawnLFSignupInstructor();
		Javelin_Assembled.bHidden = false;
		Javelin_Assembled.ResetStaticFilterState();
		PCtoCLUWire2.bHidden = false;
		PCtoCLUWire2.ResetStaticFilterState();
		bPassedBST = true;
		return true;
	case "bstnotfail":
		if (IsInState('StartVirtual'))
		{
			ChangeState('VPass');
		}
		return true;
	case "bstfail":
		if (IsInState('StartVirtual'))
		{
			ChangeState('VFailTime');
		}
		return true;
	case "bstfind":
		if (IsInState('StartVirtual'))
		{
			ForEach AllActors(Class'AGP_Vehicles.AGP_Vehicle', Target, 'BSTInvalidTarget')
			{
				Icon = Spawn(class'AGP_Script.HelpIcon');
				Icon.SetHelpIcon(Target, vect(0, 0, 1000), 200);
			}
			ForEach AllActors(Class'AGP_Vehicles.AGP_Vehicle', Target, 'BSTValidTarget')
			{
				Icon = Spawn(class'AGP_Script.HelpIcon');
				Icon.SetHelpIcon(Target, vect(0, 0, 1000), 200);
			}
		}
		return true;
	case "rotlimit":
		Player.LimitRotation((!Player.bLimitRotation));
		return true;
	case "spawninv":
		ForEach AllActors(Class'AGP_Vehicles.AGP_VehicleFactory', Factory, 'BSTInvalidFactory')
		{
			Factory.SpawnedVehicleTag = 'TestingBSTTargets';
			Factory.SpawnVehicle();
		}
		return true;
	case "spawnval":
		ForEach AllActors(Class'AGP_Vehicles.AGP_VehicleFactory', Factory, 'BSTValidFactory')
		{
			Factory.SpawnedVehicleTag = 'TestingBSTTargets';
			Factory.SpawnVehicle();
		}
		return true;
	case "killv":
		ForEach AllActors(Class'AGP_Vehicles.AGP_Vehicle', Target, 'TestingBSTTargets')
		{
			Target.Destroy();
		}
		return true;
	case "goodcheat":
		bAllowCheats = true;
		return true;
	case "icon":
		bHelpIcon = true;
		return true;
	case "dolf":
		GotoState('InitializeLF');
		return true;
	default:
	}
	*/
	return false;    //FAKE   /ELiZ
}

void AEL_JavelinTraining::CloseSaveAndContinueMenu()
{
	//GotoState('DelayAndCloseSaveAndContinue');
}
