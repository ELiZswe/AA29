// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_GabrielDemo/EL_GabrielDemo.h"
#include "AA29/AA29.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/AGP_PlayerStart.h"
#include "AA29/Object/Actor/AGP_UseTrigger/AGP_UseTrigger.h"
#include "AA29/Object/Actor/AAGameplay/EEBlackHawk/EEBlackHawk.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/NPC_Ambient/NPC_Ambient.h"
#include "AA29/Object/Actor/Info/SceneManager/SceneManager.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/NPC_SpecialForces/NPC_SpecialForces.h"
#include "AA29/Object/Actor/EffectLocation/EffectLocation.h"

AEL_GabrielDemo::AEL_GabrielDemo()
{
	SFLeader_Idles = {
		"SFLeader_Idle1",
		"SFLeader_Idle2",
		"SFLeader_Idle3",
		"SFLeader_Idle4"
	};
	SFCommander_Idles = {
		"SFCommander_Idle1",
		"SFCommander_Idle2",
		"SFCommander_Idle3",
		"SFCommander_Idle4"
	};
	SFSergeant_Idles = {
		"SFSergeant1_Idle1",
		"SFSergeant1_Idle2",
		"SFSergeant1_Idle3"
	};
	SFWeapons_Idles = {
		"SFWeapons_Idle1",
		"SFWeapons_Idle2"
	};
	SFEngineer_Idles = {
		"SFEngineer_Idle1",
		"SFEngineer_Idle2",
		"SFEngineer_Idle3"
	};
	SFMedical_Idles = {
		"SFMedical_Idle1",
		"SFMedical_Idle2",
		"SFMedical_idle3",
		"SFMedical_Idle4"
	};
	SFCommunications_Idles = {
		"SFCommunications_Idle1",
		"SFCommunications_Idle3",
		"SFCommunications_Idle5"
	};
	SFIntelligence_Idles = {
		"SFIntelligence_Idle1",
		"SFIntelligence_Idle2",
		"SFIntelligence_Idle3"
	};
	Team = {
		FTeamMember({ "SFLeader",			nullptr,"SFLeader_Trigger",			nullptr,"UseTrigger_SFLeader",			nullptr,"Talk to the 18A Team Leader",				"Hear about the 18A MOS",-21957}),
		FTeamMember({ "SFCommander",		nullptr,"SFCommander_Trigger",		nullptr,"UseTrigger_SFCommander",		nullptr,"Talk to the 180 Warrant Officer",			"Hear about the 180 MOS",24871 }),
		FTeamMember({ "SFWeapons",			nullptr,"SFWeapons_Trigger",		nullptr,"UseTrigger_SFWeapons",			nullptr,"Talk to the 18B Weapons Sergeant",			"Hear about the 18B MOS",9032 }),
		FTeamMember({ "SFEngineer",			nullptr,"SFEngineer_Trigger",		nullptr,"UseTrigger_SFEngineer",		nullptr,"Talk to the 18C Engineering Sergeant",		"Hear about the 18C MOS",20142 }),
		FTeamMember({ "SFMedical",			nullptr,"SFMedical_Trigger",		nullptr,"UseTrigger_SFMedical",			nullptr,"Talk to the 18D Medical Sergeant",			"Hear about the 18D MOS",-32113 }),
		FTeamMember({ "SFCommunications",	nullptr,"SFCommunications_Trigger",	nullptr,"UseTrigger_SFCommunications",	nullptr,"Talk to the 18E Communications Sergeant",	"Hear about the 18E MOS",-3423 }),
		FTeamMember({ "SFIntelligence",		nullptr,"SFIntelligence_Trigger",	nullptr,"UseTrigger_SFIntelligence",	nullptr,"Talk to the 18F Intelligence Sergeant",	"Hear about the 18F MOS",25719 }),
		FTeamMember({ "SFSergeant",			nullptr,"SFSergeant_Trigger",		nullptr,"UseTrigger_SFSergeant",		nullptr,"Talk to the 18Z Operations Sergeant",		"Hear about the 18Z MOS",-8701 })
	};

	LevelImages = {
		//FLevelTex({ Shader'T_AA2_CampMackall.3DUI.UI_AVWID',Shader'T_AA2_CampMackall.3DUI.UI_AVWID_Status',Texture'T_AA2_Maps.LevelShots.Map_levelshot_SF_AVWID',Texture'T_AA2_Maps.LevelShots.Map_levelshot_SF_AVWID_g'}),
		//FLevelTex({ Shader'T_AA2_CampMackall.3DUI.UI_EandE',Shader'T_AA2_CampMackall.3DUI.UI_EandE_Status',Texture'T_AA2_Maps.LevelShots.Map_levelshot_SF_EscapeandEvade',Texture'T_AA2_Maps.LevelShots.Map_levelshot_SF_EscapeandEvade_g' }),
		//FLevelTex({ Shader'T_AA2_CampMackall.3DUI.UI_Language',Shader'T_AA2_CampMackall.3DUI.UI_Language_Status',Texture'T_AA2_Maps.LevelShots.Map_levelshot_Language',Texture'T_AA2_Maps.LevelShots.Map_levelshot_Language_g' }),
		//FLevelTex({ Shader'T_AA2_CampMackall.3DUI.UI_Survival',Shader'T_AA2_CampMackall.3DUI.UI_Survival_Status',Texture'T_AA2_Maps.LevelShots.Map_levelshot_Survival',Texture'T_AA2_Maps.LevelShots.Map_levelshot_Survival_g' }),
		//FLevelTex({ Shader'T_AA2_CampMackall.3DUI.UI_SFWeapons',Shader'T_AA2_CampMackall.3DUI.UI_SFWeapons_Status',Texture'T_AA2_Maps.LevelShots.Map_levelshot_SFWeapons',Texture'T_AA2_Maps.LevelShots.Map_levelshot_SFWeapons_g' })
	};
	StatusImages = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_CampMackall/3DUI/UI_NotAvailable_Mat.UI_NotAvailable_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_CampMackall/3DUI/UI_Invisible_Mat.UI_Invisible_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_CampMackall/3DUI/UI_Completed_Mat.UI_Completed_Mat'"), NULL, LOAD_None, NULL)
	};
	Missions = {
		FMissionInfo({ 10,0,"Load Aircraft, Vehicle, Weapon ID?","sf_avwid" }),
		FMissionInfo({ 10,1,"Load Escape and Evade?","eande" }),
		FMissionInfo({ 13,0,"Load Language Training?","camp_mackall_language" }),
		FMissionInfo({ 13,1,"Load Survival Training?","camp_mackall_survival" }),
		FMissionInfo({ 13,2,"Load SF Weapons Training?","sf_weapons" })
	};
	LevelTriggers = {

		FLevelTrigger({"LevelTrigger_AVWID",nullptr,"AVWID (Not Available)","Enter AVWID Training","Train in AVWID again"}),
		FLevelTrigger({ "LevelTrigger_EANDE",nullptr,"Escape and Evade (Not Available)","Enter Escape and Evade Training","Train in Escape and Evade again" }),
		FLevelTrigger({ "LevelTrigger_LANGUAGE",nullptr,"Language (Not Available)","Enter Language Training","Train in Language again" }),
		FLevelTrigger({ "LevelTrigger_SURVIVAL",nullptr,"Survival (Not Available)","Enter Survival Training","Train in Survival again" }),
		FLevelTrigger({ "LevelTrigger_SFWEAPONS",nullptr,"SF Weapons (Not Available)","Enter SF Weapons Training","Train in SF Weapons Again" })
	};
	HeliPaths = {
		FHeliPath({ "BHPathA",nullptr,false}),
		FHeliPath({ "BHPathB",nullptr,false }),
		FHeliPath({ "BHPathC",nullptr,false })
	};
	SodaGuySound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/SodaGuy/vendkicker1_Cue.vendkicker1_Cue'"), NULL, LOAD_None, NULL);

	LSAnims = {
		FLSAnim({ "SFLeader1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFLeader1_Cue.SFLeader1_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFLeader2",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFLeader2_Cue.SFLeader2_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFLeader_GetClass",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFLeader_GetClass_Cue.SFLeader_GetClass_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFLeader_Idle1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFLeader_Idle1_Cue.SFLeader_Idle1_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFLeader_Idle2",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFLeader_Idle2_Cue.SFLeader_Idle2_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFLeader_Idle3",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFLeader_Idle3_Cue.SFLeader_Idle3_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFLeader_Idle4",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFLeader_Idle4_Cue.SFLeader_Idle4_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFCommander1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFCommander1_Cue.SFCommander1_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFCommander_Idle1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFCommander_Idle1_Cue.SFCommander_Idle1_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFCommander_Idle2",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFCommander_Idle2_Cue.SFCommander_Idle2_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFCommander_Idle3",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFCommander_Idle3_Cue.SFCommander_Idle3_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFCommander_Idle4",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFCommander_Idle4_Cue.SFCommander_Idle4_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFSergeant1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFSergeant1_Cue.SFSergeant1_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFSergeant1_Idle1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFSergeant1_Idle1_Cue.SFSergeant1_Idle1_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFSergeant1_Idle2",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFSergeant1_Idle2_Cue.SFSergeant1_Idle2_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFSergeant1_Idle3",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFSergeant1_Idle3_Cue.SFSergeant1_Idle3_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFWeapons1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFWeapons1_Cue.SFWeapons1_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFWeapons_Idle1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFWeapons_Idle1_Cue.SFWeapons_Idle1_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFWeapons_Idle2",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFWeapons_Idle2_Cue.SFWeapons_Idle2_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFEngineer1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFEngineer1_Cue.SFEngineer1_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFEngineer_Idle1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFEngineer_Idle1_Cue.SFEngineer_Idle1_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFEngineer_Idle2",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFEngineer_Idle2_Cue.SFEngineer_Idle2_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFEngineer_Idle3",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFEngineer_Idle3_Cue.SFEngineer_Idle3_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFMedical1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFMedical1_Cue.SFMedical1_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFMedical_Idle1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFMedical_Idle1_Cue.SFMedical_Idle1_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFMedical_Idle2",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFMedical_Idle2_Cue.SFMedical_idle2_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFMedical_idle3",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFMedical_idle3_Cue.SFMedical_idle3_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFMedical_Idle4",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFMedical_Idle4_Cue.SFMedical_Idle4_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFCommunications1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFCommunications1_Cue.SFCommunications1_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFCommunications_Idle1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFCommunications_Idle1_Cue.SFCommunications_Idle1_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFCommunications_Idle3",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFCommunications_Idle3_Cue.SFCommunications_Idle3_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFCommunications_Idle4",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFCommunications_Idle4_Cue.SFCommunications_Idle4_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFCommunications_Idle5",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFCommunications_Idle5_Cue.SFCommunications_Idle5_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFIntelligence1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFIntelligence1_Cue.SFIntelligence1_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFIntelligence_Idle1",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFIntelligence_Idle1_Cue.SFIntelligence_Idle1_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFIntelligence_Idle2",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFIntelligence_Idle2_Cue.SFIntelligence_Idle2_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFIntelligence_Idle3",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFIntelligence_Idle3_Cue.SFIntelligence_Idle3_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "SFIntelligence_Idle4",LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/GabrielDemo/SFIntelligence_Idle4_Cue.SFIntelligence_Idle4_Cue'"), NULL, LOAD_None, NULL), { "None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} })
	};
}

/*
State TalkToSFTeam
{
	Function BeginState()
	{
		if (DidHearTeamDemo(0))
		{
			Team[0].Actor.EnableEyeTrack();
		}
		if (DidHearTeamDemo(1))
		{
			Team[1].Actor.EnableEyeTrack();
		}
		if (DidHearTeamDemo(7))
		{
			Team[7].Actor.EnableEyeTrack();
		}
		if (DidHearTeamDemo(2))
		{
			Team[2].Actor.EnableEyeTrack();
		}
		if (DidHearTeamDemo(3))
		{
			Team[3].Actor.EnableEyeTrack();
		}
		if (DidHearTeamDemo(4))
		{
			Team[4].Actor.EnableEyeTrack();
		}
		if (DidHearTeamDemo(5))
		{
			Team[5].Actor.EnableEyeTrack();
		}
		if (DidHearTeamDemo(6))
		{
			Team[6].Actor.EnableEyeTrack();
		}
	}
	Function StartDemo(uint8 TeamIndex)
	{
		PlayerLock(true,false);
		DisableTeamUseTriggers();
		DisableTeamVolTriggers();
	}
	Function FinishDemo(uint8 TeamIndex)
	{
		PlayerLock(false,false);
		SetTeamCode(TeamIndex);
		UpdateTeamUseTrigger(TeamIndex);
		UpdateMissionStatus();
		EnableTeamUseTriggers();
		EnableTeamVolTriggers();
		EnableCrosshair();
	}
	Function StartConversation(uint8 TeamIndex)
	{
		DisableTeamUseTriggers();
		DisableTeamVolTriggers();
		DisableCrosshair();
		Team[TeamIndex].Actor.EnableEyeTrack();
	}
	Function FinishConversation(uint8 TeamIndex)
	{
		PlayerLock(false,false);
		EnableTeamUseTriggers();
		EnableTeamVolTriggers();
		EnableCrosshair();
	}
	Function bool Timer_LSAnim(FName Name)
	{
		int32 i = 0;
		if (Name == "SFLeader1")
		{
			FinishConversation(0);
			return true;
		}
		if (Name == "SFLeader2")
		{
			FinishDemo(0);
			return true;
		}
		if (Name == "SFCommander1")
		{
			FinishDemo(1);
			return true;
		}
		if (Name == "SFSergeant1")
		{
			FinishDemo(7);
			return true;
		}
		if (Name == "SFWeapons1")
		{
			FinishDemo(2);
			return true;
		}
		if (Name == "SFEngineer1")
		{
			FinishDemo(3);
			return true;
		}
		if (Name == "SFMedical1")
		{
			FinishDemo(4);
			return true;
		}
		if (Name == "SFCommunications1")
		{
			FinishDemo(5);
			return true;
		}
		if (Name == "SFIntelligence1")
		{
			FinishDemo(6);
			return true;
		}
		for (i=0; i<SFLeader_Idles.Num(); i++)
		{
			if (Name == SFLeader_Idles[i])
			{
				FinishConversation(0);
			}
		}
		for (i=0; i<SFCommander_Idles.Num(); i++)
		{
			if (Name == SFCommander_Idles[i])
			{
				FinishConversation(1);
			}
		}
		for (i=0; i<SFSergeant_Idles.Num(); i++)
		{
			if (Name == SFSergeant_Idles[i])
			{
				FinishConversation(7);
			}
		}
		for (i=0; i<SFWeapons_Idles.Num(); i++)
		{
			if (Name == SFWeapons_Idles[i])
			{
				FinishConversation(2);
			}
		}
		for (i=0; i<SFEngineer_Idles.Num(); i++)
		{
			if (Name == SFEngineer_Idles[i])
			{
				FinishConversation(3);
			}
		}
		for (i=0; i<SFMedical_Idles.Num(); i++)
		{
			if (Name == SFMedical_Idles[i])
			{
				FinishConversation(4);
			}
		}
		for (i=0; i<SFCommunications_Idles.Num(); i++)
		{
			if (Name == SFCommunications_Idles[i])
			{
				FinishConversation(5);
			}
		}
		for (i=0; i<SFIntelligence_Idles.Num(); i++)
		{
			if (Name == SFIntelligence_Idles[i])
			{
				FinishConversation(6);
			}
		}
		if (Name == "SFIntelligence_Idle3")
		{
			PlayLSAnim("SFCommunications_Idle4",Team[5].Actor,1,512);
			Team[5].Actor.EnableEyeTrack();
		}
		if (Name == "SFCommunications_Idle4")
		{
			PlayLSAnim("SFIntelligence_Idle4",Team[6].Actor,1,512);
		}
		return false;
	}
	Function LoadLevel(uint8 iLevel)
	{
		FString Team0 = "";
		FString Team1 = "";
		FString UIClass = "";
		FString Message = "";
		FString Map = "";
		if (CanEnterLevel(iLevel))
		{
			UIClass="AGP_Interface.AALoadLevelConfirmation";
			Message=Missions[iLevel].LoadMessage;
			Map=Missions[iLevel].MapName;
			Controller.ClientOpenMenu(UIClass,false,Message,Map);
			return;
		}
		if (PlayerIsQualified(iLevel))
		{
			Team0=GetTeamTitle(GetRequiredConversation(iLevel,0));
			Team1=GetTeamTitle(GetRequiredConversation(iLevel,1));
			PlayTip("Speak with the " + Team0,"and the " + Team1 + " to enter this level",5);
		}
		else
		{
			PlayTip("You must complete the " + GetRequiredTour(iLevel),"tour before you can enter this level",5);
		}
	}
	Function bool LevelTrigger_AVWID_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		LoadLevel(0);
		return true;
	}
	Function bool LevelTrigger_EANDE_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		LoadLevel(1);
		return true;
	}
	Function bool LevelTrigger_LANGUAGE_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		LoadLevel(2);
		return true;
	}
	Function bool LevelTrigger_SURVIVAL_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		LoadLevel(3);
		return true;
	}
	Function bool LevelTrigger_SFWEAPONS_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		LoadLevel(4);
		return true;
	}
	Function bool SF18A_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		if (DidHearTeamDemo(0))
		{
			StartConversation(0);
			PlayLSAnim(SFLeader_Idles[SFLeader_ConvIndex],Team[0].Actor,1,512);
			SFLeader_ConvIndex ++;
			if (SFLeader_ConvIndex >= SFLeader_Idles.Num())
			{
				SFLeader_ConvIndex=0;
			}
		}
		else
		{
			StartDemo(0);
			PlayLSAnim("SFLeader2",Team[0].Actor,1,512);
		}
		return Global.pos1(Trigger,Instigator);
	}
	Function bool SF180_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		if (DidHearTeamDemo(1))
		{
			StartConversation(1);
			PlayLSAnim(SFCommander_Idles[SFCommander_ConvIndex],Team[1].Actor,1,512);
			SFCommander_ConvIndex ++;
			if (SFCommander_ConvIndex >= SFCommander_Idles.Num())
			{
				SFCommander_ConvIndex=0;
			}
		}
		else
		{
			StartDemo(1);
			PlayLSAnim("SFCommander1",Team[1].Actor,1,512);
		}
		return Global.building5M16Target6(Trigger,Instigator);
	}
	Function bool SF18Z_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		if (DidHearTeamDemo(7))
		{
			StartConversation(7);
			PlayLSAnim(SFSergeant_Idles[SFSergeant_ConvIndex],Team[7].Actor,1,512);
			SFSergeant_ConvIndex ++;
			if (SFSergeant_ConvIndex >= SFSergeant_Idles.Num())
			{
				SFSergeant_ConvIndex=0;
			}
		}
		else
		{
			StartDemo(7);
			PlayLSAnim("SFSergeant1",Team[7].Actor,1,512);
		}
		return Global.building5M17Target1(Trigger,Instigator);
	}
	Function bool SF18B_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		if (DidHearTeamDemo(2))
		{
			StartConversation(2);
			PlayLSAnim(SFWeapons_Idles[SFWeapons_ConvIndex],Team[2].Actor,1,512);
			SFWeapons_ConvIndex ++;
			if (SFWeapons_ConvIndex >= SFWeapons_Idles.Num())
			{
				SFWeapons_ConvIndex=0;
			}
		}
		else
		{
			StartDemo(2);
			PlayLSAnim("SFWeapons1",Team[2].Actor,1,512);
		}
		return Global.A(Trigger,Instigator);
	}
	Function bool SF18C_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		if (DidHearTeamDemo(3))
		{
			StartConversation(3);
			PlayLSAnim(SFEngineer_Idles[SFEngineer_ConvIndex],Team[3].Actor,1,512);
			SFEngineer_ConvIndex ++;
			if (SFEngineer_ConvIndex >= SFEngineer_Idles.Num())
			{
				SFEngineer_ConvIndex=0;
			}
		}
		else
		{
			StartDemo(3);
			PlayLSAnim("SFEngineer1",Team[3].Actor,1,512);
		}
		return Global.building5M18Target1(Trigger,Instigator);
	}
	Function bool SF18D_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		if (DidHearTeamDemo(4))
		{
			StartConversation(4);
			PlayLSAnim(SFMedical_Idles[SFMedical_ConvIndex],Team[4].Actor,1,512);
			SFMedical_ConvIndex ++;
			if (SFMedical_ConvIndex >= SFMedical_Idles.Num())
			{
				SFMedical_ConvIndex=0;
			}
		}
		else
		{
			StartDemo(4);
			PlayLSAnim("SFMedical1",Team[4].Actor,1,512);
		}
		return Global.building5M18Target2(Trigger,Instigator);
	}
	Function bool SF18E_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		if (DidHearTeamDemo(5))
		{
			StartConversation(5);
			PlayLSAnim(SFCommunications_Idles[SFCommunications_ConvIndex],Team[5].Actor,1,512);
			SFCommunications_ConvIndex ++;
			if (SFCommunications_ConvIndex >= SFCommunications_Idles.Num())
			{
				SFCommunications_ConvIndex=0;
			}
		}
		else
		{
			StartDemo(5);
			PlayLSAnim("SFCommunications1",Team[5].Actor,1,512);
		}
		return Global.building5M25Target2(Trigger,Instigator);
	}
	Function bool SF18F_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		if (DidHearTeamDemo(6))
		{
			StartConversation(6);
			PlayLSAnim(SFIntelligence_Idles[SFIntelligence_ConvIndex],Team[6].Actor,1,512);
			SFIntelligence_ConvIndex ++;
			if (SFIntelligence_ConvIndex >= SFIntelligence_Idles.Num())
			{
				SFIntelligence_ConvIndex=0;
			}
		}
		else
		{
			StartDemo(6);
			PlayLSAnim("SFIntelligence1",Team[6].Actor,1,512);
		}
		return Global.building5M25Target1(Trigger,Instigator);
	}
Begin:
	FadeOutBlack(0.01);
	if (! DidHearTeamDemo(0))
	{
		PlayerLock(true,false);
		FadeInBlack(2);
		PlayTip("Welcome to Camp Mackall","Special Forces Training ",20);
		Sleep(2);
		PlayLSAnim("SFLeader1",Team[0].Actor,1,512);
	}
	else
	{
		FadeInBlack(2);
		PlayTip("Welcome to Camp Mackall","Special Forces Training ",20);
	}
}
*/

static const int32 SF18Z = 7;
static const int32 SF18F = 6;
static const int32 SF18E = 5;
static const int32 SF18D = 4;
static const int32 SF18C = 3;
static const int32 SF18B = 2;
static const int32 SF180 = 1;
static const int32 SF18A = 0;
static const int32 LEVEL_SFWEAPONS = 4;
static const int32 LEVEL_SURVIVAL = 3;
static const int32 LEVEL_LANGUAGE = 2;
static const int32 LEVEL_EANDE = 1;
static const int32 LEVEL_AVWID = 0;
static const int32 TEX_GRAY = 1;
static const int32 TEX_COLOR = 0;
static const int32 ST_COMPLETED = 2;
static const int32 ST_AVAILABLE = 1;
static const int32 ST_NOTAVAILABLE = 0;
static const int32 GABRIELDEMOACTORS = 8;

bool AEL_GabrielDemo::AGP_UseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case 'UseTrigger_SFLeader':
		return SF18A_UsedBy(Trigger, aInstigator);
	case 'UseTrigger_SFCommander':
		return SF180_UsedBy(Trigger, aInstigator);
	case 'UseTrigger_SFSergeant':
		return SF18Z_UsedBy(Trigger, aInstigator);
	case 'UseTrigger_SFWeapons':
		return SF18B_UsedBy(Trigger, aInstigator);
	case 'UseTrigger_SFEngineer':
		return SF18C_UsedBy(Trigger, aInstigator);
	case 'UseTrigger_SFMedical':
		return SF18D_UsedBy(Trigger, aInstigator);
	case 'UseTrigger_SFCommunications':
		return SF18E_UsedBy(Trigger, aInstigator);
	case 'UseTrigger_SFIntelligence':
		return SF18F_UsedBy(Trigger, aInstigator);
	case 'LevelTrigger_AVWID':
		return LevelTrigger_AVWID_UsedBy(Trigger, aInstigator);
	case 'LevelTrigger_EANDE':
		return LevelTrigger_EANDE_UsedBy(Trigger, aInstigator);
	case 'LevelTrigger_LANGUAGE':
		return LevelTrigger_LANGUAGE_UsedBy(Trigger, aInstigator);
	case 'LevelTrigger_SURVIVAL':
		return LevelTrigger_SURVIVAL_UsedBy(Trigger, aInstigator);
	case 'LevelTrigger_SFWEAPONS':
		return LevelTrigger_SFWEAPONS_UsedBy(Trigger, aInstigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_GabrielDemo::SF18A_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return TeamUse(0);
}

bool AEL_GabrielDemo::SF180_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return TeamUse(1);
}

bool AEL_GabrielDemo::SF18Z_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return TeamUse(7);
}

bool AEL_GabrielDemo::SF18B_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return TeamUse(2);
}

bool AEL_GabrielDemo::SF18C_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return TeamUse(3);
}

bool AEL_GabrielDemo::SF18D_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return TeamUse(4);
}

bool AEL_GabrielDemo::SF18E_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return TeamUse(5);
}

bool AEL_GabrielDemo::SF18F_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return TeamUse(6);
}

bool AEL_GabrielDemo::LevelTrigger_AVWID_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return LevelTriggerUse(0);
}

bool AEL_GabrielDemo::LevelTrigger_EANDE_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return LevelTriggerUse(1);
}

bool AEL_GabrielDemo::LevelTrigger_LANGUAGE_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return LevelTriggerUse(2);
}

bool AEL_GabrielDemo::LevelTrigger_SURVIVAL_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return LevelTriggerUse(3);
}

bool AEL_GabrielDemo::LevelTrigger_SFWEAPONS_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return LevelTriggerUse(4);
}

bool AEL_GabrielDemo::TriggerVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case 'SFLeader_Trigger':
		return SF18A_Trigger_Enter(Trigger, aInstigator);
	case 'SFCommander_Trigger':
		return SF180_Trigger_Enter(Trigger, aInstigator);
	case 'SFSergeant_Trigger':
		return SF18Z_Trigger_Enter(Trigger, aInstigator);
	case 'SFWeapons_Trigger':
		return SF18B_Trigger_Enter(Trigger, aInstigator);
	case 'SFEngineer_Trigger':
		return SF18C_Trigger_Enter(Trigger, aInstigator);
	case 'SFMedical_Trigger':
		return SF18D_Trigger_Enter(Trigger, aInstigator);
	case 'SFCommunications_Trigger':
		return SF18E_Trigger_Enter(Trigger, aInstigator);
	case 'SFIntelligence_Trigger':
		return SF18F_Trigger_Enter(Trigger, aInstigator);
	case 'SodaGuy_Trigger':
		return SodaGuy_Trigger_Enter(Trigger, aInstigator);
	case 'OutOfBounds':
		return OutOfBounds_Trigger_Enter(Trigger, aInstigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_GabrielDemo::SF18A_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return TeamTriggerEnter(0);
}

bool AEL_GabrielDemo::SF180_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return TeamTriggerEnter(1);
}

bool AEL_GabrielDemo::SF18Z_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return TeamTriggerEnter(7);
}

bool AEL_GabrielDemo::SF18B_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return TeamTriggerEnter(2);
}

bool AEL_GabrielDemo::SF18C_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return TeamTriggerEnter(3);
}

bool AEL_GabrielDemo::SF18D_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return TeamTriggerEnter(4);
}

bool AEL_GabrielDemo::SF18E_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return TeamTriggerEnter(5);
}

bool AEL_GabrielDemo::SF18F_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return TeamTriggerEnter(6);
}

bool AEL_GabrielDemo::TriggerVolume_Exit(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case 'SFLeader_Trigger':
		return SF18A_Trigger_Exit(Trigger, aInstigator);
	case 'SFCommander_Trigger':
		return SF180_Trigger_Exit(Trigger, aInstigator);
	case 'SFSergeant_Trigger':
		return SF18Z_Trigger_Exit(Trigger, aInstigator);
	case 'SFWeapons_Trigger':
		return SF18B_Trigger_Exit(Trigger, aInstigator);
	case 'SFEngineer_Trigger':
		return SF18C_Trigger_Exit(Trigger, aInstigator);
	case 'SFMedical_Trigger':
		return SF18D_Trigger_Exit(Trigger, aInstigator);
	case 'SFCommunications_Trigger':
		return SF18E_Trigger_Exit(Trigger, aInstigator);
	case 'SFIntelligence_Trigger':
		return SF18F_Trigger_Exit(Trigger, aInstigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_GabrielDemo::SF18A_Trigger_Exit(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return TeamTriggerExit(0);
}

bool AEL_GabrielDemo::SF180_Trigger_Exit(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return TeamTriggerExit(1);
}

bool AEL_GabrielDemo::SF18Z_Trigger_Exit(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return TeamTriggerExit(7);
}

bool AEL_GabrielDemo::SF18B_Trigger_Exit(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return TeamTriggerExit(2);
}

bool AEL_GabrielDemo::SF18C_Trigger_Exit(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return TeamTriggerExit(3);
}

bool AEL_GabrielDemo::SF18D_Trigger_Exit(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return TeamTriggerExit(4);
}

bool AEL_GabrielDemo::SF18E_Trigger_Exit(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return TeamTriggerExit(5);
}

bool AEL_GabrielDemo::SF18F_Trigger_Exit(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return TeamTriggerExit(6);
}

bool AEL_GabrielDemo::SceneManager_SceneStart(ASceneManager* NotifyActor, AActor* aInstigator, FString Parms)
{
	bBlackHawkBusy = true;
	ChopperDoFadeUp(2);
	return true;
}

bool AEL_GabrielDemo::SceneManager_SceneEnd(ASceneManager* NotifyActor, AActor* aInstigator, FString Parms)
{
	bBlackHawkBusy = false;
	ChopperDoFadeDown(4);
	//StartTimer('ChopperFlyBy', 5);
	return true;
}

bool AEL_GabrielDemo::TeamTriggerEnter(int32 TeamIndex)
{
	//Team[TeamIndex].UseTrigger.SetActive(true);
	return true;
}

bool AEL_GabrielDemo::TeamTriggerExit(int32 TeamIndex)
{
	//Team[TeamIndex].UseTrigger.SetActive(false);
	return true;
}

bool AEL_GabrielDemo::TeamUse(int32 TeamIndex)
{
	return true;
}

bool AEL_GabrielDemo::LevelTriggerUse(int32 iLevel)
{
	return true;
}

void AEL_GabrielDemo::PreInit()
{
	/*
	int32 i = 0;
	int32 j = 0;
	for (i = 0; i < Team.Num(); i++)
	{
		Team[i].Actor = Cast<ANPC_SpecialForces>(CaptureEvent(Team[i].ActorTag));
		Team[i].VolTrigger = Cast<ATriggerVolume>(CaptureEvent(Team[i].VolTriggerTag));
		Team[i].UseTrigger = Cast<AAGP_UseTrigger>(CaptureEvent(Team[i].UseTriggerTag));
	}
	for (i = 0; i < LevelTriggers.Num(); i++)
	{
		LevelTriggers[i].Trigger = Cast<AAGP_UseTrigger>(CaptureEvent(LevelTriggers[i].Tag));
	}
	for (i = 0; i < HeliPaths.Num(); i++)
	{
		HeliPaths[i].Path = SceneManager(CaptureEvent(HeliPaths[i].Name));
		for (j = 0; j < HeliPaths[i].Path.Actions.Num(); j++)
		{
			CaptureEvent(HeliPaths[i].Path.Actions[j].IntPoint.Tag);
		}
	}
	blackhawk = EEBlackHawk(GetActor('blackhawk'));
	CaptureEventGroup('OutOfBounds');
	PlayerStartLocation = AGP_PlayerStart(GetActor('PlayerStartLocation'));
	SodaMachine = Cast<ANPC_Ambient>(GetActor('SodaMachine'));
	SodaGuy_Trigger = Cast<ATriggerVolume>(CaptureEvent('SodaGuy_Trigger'));
	SodaGuy = Cast<ANPC_Ambient>(CaptureEvent('SodaGuy'));
	*/
}

void AEL_GabrielDemo::Init()
{
}

void AEL_GabrielDemo::PostInit()
{
}

void AEL_GabrielDemo::PostPostInit()
{
	bHack = false;
	UpdateMissionStatus();
	InitTeamTriggers();
	InitChopper();
	ClearClock();
	EnableCrosshair();
	//SodaGuy.LoopAnim('vending_idle1');
	//StartTimer('UpdateMissionStatus', 2, true);
	//StartTimer('ChopperFlyBy', 5);
	//ChangeState('TalkToSFTeam');
}

void AEL_GabrielDemo::EventLabTick(float DeltaTime)
{
	/*
	if (ChopperSound.bFadeUp)
	{
		FadeChopperSoundUp(DeltaTime);
	}
	if (ChopperSound.bFadeDown)
	{
		FadeChopperSoundDown(DeltaTime);
	}
	*/
}

void AEL_GabrielDemo::ChopperDoFadeUp(float Time)
{
	//blackhawk.SoundVolume = 0;
	//ChopperSound.FadeTime = Time;
	//ChopperSound.bFadeUp = true;
	//ChopperSound.bFadeDown = false;
}

void AEL_GabrielDemo::ChopperDoFadeDown(float Time)
{
	//blackhawk.SoundVolume = uint8(ChopperSound.StartVolume);
	//ChopperSound.FadeTime = Time;
	//ChopperSound.bFadeUp = false;
	//ChopperSound.bFadeDown = true;
}

void AEL_GabrielDemo::FadeChopperSoundUp(float DeltaTime)
{
	/*
	if (float(blackhawk.SoundVolume) == ChopperSound.StartVolume)
	{
		ChopperSound.bFadeUp = false;
		return;
	}
	(ChopperSound.Volume += (DeltaTime * (ChopperSound.StartVolume / ChopperSound.FadeTime)));
	ChopperSound.Volume = float(Min(int(ChopperSound.Volume), int(ChopperSound.StartVolume)));
	blackhawk.SoundVolume = uint8(ChopperSound.Volume);
	*/
}

void AEL_GabrielDemo::FadeChopperSoundDown(float DeltaTime)
{
	/*
	if (blackhawk.SoundVolume == 0)
	{
		ChopperSound.bFadeDown = false;
		return;
	}
	(ChopperSound.Volume -= (DeltaTime * (ChopperSound.StartVolume / ChopperSound.FadeTime)));
	ChopperSound.Volume = float(Max(int(ChopperSound.Volume), 0));
	blackhawk.SoundVolume = uint8(ChopperSound.Volume);
	*/
}

void AEL_GabrielDemo::InitChopper()
{
	/*
	blackhawk.ResetAnims();
	blackhawk.SetChopperSound('exterior');
	ChopperSound.StartVolume = 128;
	blackhawk.SoundVolume = 0;
	*/
}

void AEL_GabrielDemo::ChopperFlyBy()
{
	//TriggerEvent(ChooseHeliPath(), None, Player);
}

FName AEL_GabrielDemo::ChooseHeliPath()
{
	/*
	int32 Count = 0;
	int32 Num = 0;
	Num = Rand(HeliPaths.Num());
	if (HeliPaths[Num].bFlown)
	{
		if (Count >= HeliPaths.Num())
		{
			ResetHeliPaths();
			Count = 0;
		}
		Count++;
		Num = Rand(HeliPaths.Num());
	}
	HeliPaths[Num].bFlown = true;
	return HeliPaths[Num].Name;
	*/
	return "FAKE";    //FAKE   /ELiZ
}

void AEL_GabrielDemo::ResetHeliPaths()
{
	/*
	int32 i = 0;
	for (i = 0; i < HeliPaths.Num(); i++)
	{
		HeliPaths[i].bFlown = false;
	}
	*/
}

void AEL_GabrielDemo::UpdateTeamUseTrigger(uint8 TeamIndex)
{
	/*
	if (DidHearTeamDemo(TeamIndex))
	{
		Team[TeamIndex].UseTrigger.SetHUDText(Team[TeamIndex].TalkText);
	}
	else
	{
		Team[TeamIndex].UseTrigger.SetHUDText(Team[TeamIndex].MOSText);
	}
	*/
}

void AEL_GabrielDemo::InitTeamTriggers()
{
	int32 i = 0;
	/*
	DisableTeamUseTriggers();
	EnableTeamVolTriggers();
	for (i = 0; i < Team.Num(); i++)
	{
		UpdateTeamUseTrigger(byte(i));
	}
	*/
}

void AEL_GabrielDemo::UpdateMissionStatus()
{
	int32 i = 0;
	/*
	for (i = 0; i < Missions.Num(); i++)
	{
		SetLevelStatus(byte(i), GetMissionStatus(byte(i)));
	}
	*/
}

uint8 AEL_GabrielDemo::GetMissionStatus(uint8 iLevel)
{
	int32 iStatus = 0;
	/*
	iStatus = Level.GetMissionStatus(Missions[iLevel].Tour, Missions[iLevel].Mission);
	switch (iStatus)
	{
	case -1:
		return 0;
	case 0:
		if (DidHearLevelDemos(iLevel))
		{
			return 1;
			break;
		}
		return 0;
	}
	case 1:
		if (DidHearLevelDemos(iLevel))
		{
			return 2;
		}
		else
		{
			return 0;
		}
	default:
		return 0;
	*/

	return 0;    //FAKE   /ELiZ
}

bool AEL_GabrielDemo::CanEnterLevel(uint8 iLevel)
{
	//return (GetMissionStatus(iLevel) != 0);
	return false;    //FAKE   /ELiZ
}

bool AEL_GabrielDemo::PlayerIsQualified(uint8 iLevel)
{
	int32 iStatus = 0;
	/*
	iStatus = Level.GetMissionStatus(Missions[iLevel].Tour, Missions[iLevel].Mission);
	switch (iStatus)
	{
	case -1:
		return false;
	case 0:
		return true;
	case 1:
		return true;
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

FString AEL_GabrielDemo::GetRequiredTour(uint8 iLevel)
{
	int32 iTour = 0;
	/*
	iTour = Level.GetTourDependency(Missions[iLevel].Tour);
	if (iTour >= 0)
	{
		return Level.GetTourName(iTour);
	}
	else
	{
		Log("EL_GabrielDemo::GetRequiredTour(): Error: Invalid Tour returned");
	}
	*/
	return "FAKE";    //FAKE   /ELiZ
}

int32 AEL_GabrielDemo::GetRequiredConversation(uint8 iLevel, uint8 iMemberIndex)
{
	TArray<int32> Members = { 0,0 };
	switch (iLevel)
	{
	case 0:
		Members[0] = 0;
		Members[1] = 1;
		break;
	case 1:
		Members[0] = 0;
		Members[1] = 1;
		break;
	case 2:
		Members[0] = 5;
		Members[1] = 6;
		break;
	case 3:
		Members[0] = 4;
		Members[1] = 7;
		break;
	case 4:
		Members[0] = 2;
		Members[1] = 3;
		break;
	default:
		return 0;
	}
	if ((iMemberIndex >= 0) && (iMemberIndex <= 1))
	{
		return Members[iMemberIndex];
	}
	else
	{
		return 0;
	}
}

FString AEL_GabrielDemo::GetTeamTitle(int32 TeamIndex)
{
	switch (TeamIndex)
	{
	case 0:
		return "Team Commander (18 Alpha)";
	case 1:
		return "Asst Detachment Commander (180)";
	case 7:
		return "Operations Sergeant (18 Zulu)";
	case 2:
		return "Weapons Sergeant (18 Bravo)";
	case 3:
		return "Engineering Sergeant (18 Charlie)";
	case 4:
		return "Medical Sergeant (18 Delta)";
	case 5:
		return "Communications Sergeant (18 Echo)";
	case 6:
		return "Intelligence Sergeant (18 Fox)";
	default:
		return "";
	}
}

bool AEL_GabrielDemo::DidHearTeamDemo(int32 TeamIndex)
{
	/*
	switch (TeamIndex)
	{
	case 0:
		return (SF572 == (GetMachineID() + Team[TeamIndex].offset));
	case 1:
		return (SF324 == (GetMachineID() + Team[TeamIndex].offset));
	case 7:
		return (SF468 == (GetMachineID() + Team[TeamIndex].offset));
	case 2:
		return (SF292 == (GetMachineID() + Team[TeamIndex].offset));
	case 3:
		return (SF624 == (GetMachineID() + Team[TeamIndex].offset));
	case 4:
		return (SF843 == (GetMachineID() + Team[TeamIndex].offset));
	case 5:
		return (SF132 == (GetMachineID() + Team[TeamIndex].offset));
	case 6:
		return (SF785 == (GetMachineID() + Team[TeamIndex].offset));
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_GabrielDemo::DidHearLevelDemos(uint8 iLevel)
{
	/*
	switch (iLevel)
	{
	case 0:
		return (((Team[0].offset + GetMachineID()) == GetTeamCode(0)) && ((Team[1].offset + GetMachineID()) == GetTeamCode(1)));
	case 1:
		return (((Team[0].offset + GetMachineID()) == GetTeamCode(0)) && ((Team[1].offset + GetMachineID()) == GetTeamCode(1)));
	case 2:
		return (((Team[5].offset + GetMachineID()) == GetTeamCode(5)) && ((Team[6].offset + GetMachineID()) == GetTeamCode(6)));
	case 3:
		return (((Team[4].offset + GetMachineID()) == GetTeamCode(4)) && ((Team[7].offset + GetMachineID()) == GetTeamCode(7)));
	case 4:
		return (((Team[2].offset + GetMachineID()) == GetTeamCode(2)) && ((Team[3].offset + GetMachineID()) == GetTeamCode(3)));
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_GabrielDemo::SodaGuy_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	AActor* SoundActor = nullptr;
	/*
	UnCaptureEvent(SodaGuy_Trigger);
	SodaGuy.PlayAnim('vending_attack');
	SodaMachine.PlayAnim('vending_attack');
	StartTimer('SodaMachineEnd', 55.299999, false);
	if (SodaGuySound != nullptr)
	{
		SoundActor = Spawn(AEffectLocation::StaticClass(), , , SodaGuy.Location);
		SoundActor.LifeSpan = GetSoundDuration(SodaGuySound);
		SoundActor.PlaySound(SodaGuySound, 0, 1, , , , false);
	}
	*/
	return true;
}

bool AEL_GabrielDemo::OutOfBounds_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	FName CurrentState = "";
	FadeOutBlack(2);
	PlayerLock(true, false);
	CurrentState = GetCurrentState();
	if (CurrentState == 'TalkToSFTeam')
	{
		StartTimer('OutOfBounds_Gabriel', 2);
		return true;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_GabrielDemo::Timer_Timer(FName Name)
{
	if (Name == "UpdateMissionStatus")
	{
		UpdateMissionStatus();
		return true;
	}
	if (Name == "ChopperFlyBy")
	{
		ChopperFlyBy();
		return true;
	}
	if (Name == "SodaMachineEnd")
	{
		//SodaGuy.LoopAnim("vending_idle2");
		return true;
	}
	if (Name == "OutOfBounds_Gabriel")
	{
		//Player.SetLocation(PlayerStartLocation.Location);
		//Controller.SetRotation(PlayerStartLocation.Rotation);
		//PlayerLock(false, false);
		//FadeInBlack(2);
		return true;
	}
	return false;
}

void AEL_GabrielDemo::DisableTeamUseTriggers()
{
	int32 i = 0;
	/*
	for (i = 0; i < Team.Num(); i++)
	{
		Team[i].UseTrigger.SetActive(false);
	}
	*/
}

void AEL_GabrielDemo::EnableTeamUseTriggers()
{
	int32 i = 0;
	/*
	for (i = 0; i < Team.Num(); i++)
	{
		Team[i].UseTrigger.SetActive(true);
	}
	*/
}

void AEL_GabrielDemo::DisableTeamVolTriggers()
{
	int32 i = 0;
	/*
	for (i = 0; i < Team.Num(); i++)
	{
		Team[i].VolTrigger.SetActive(false);
	}
	*/
}

void AEL_GabrielDemo::EnableTeamVolTriggers()
{
	int32 i = 0;
	/*
	for (i = 0; i < Team.Num(); i++)
	{
		Team[i].VolTrigger.SetActive(true);
	}
	*/
}

void AEL_GabrielDemo::SetLevelStatus(uint8 iLevel, uint8 Status)
{
	/*
	if ((((iLevel >= 0) && (iLevel < LevelImages.Num())) && (Status >= 0)) && (Status < StatusImages.Num()))
	{
		switch (Status)
		{
		case 0:
			LevelTriggers[iLevel].Trigger.SetActive(true);
			LevelTriggers[iLevel].Trigger.SetHUDText(LevelTriggers[iLevel].MSG_NotAvailable);
			LevelImages[iLevel].Image.Diffuse = LevelImages[iLevel].ImageDisabled;
			LevelImages[iLevel].Status.Diffuse = StatusImages[Status];
			LevelImages[iLevel].Status.Opacity = StatusImages[Status];
			return;
		case 1:
			LevelTriggers[iLevel].Trigger.SetActive(true);
			LevelTriggers[iLevel].Trigger.SetHUDText(LevelTriggers[iLevel].MSG_Available);
			LevelImages[iLevel].Image.Diffuse = LevelImages[iLevel].ImageEnabled;
			LevelImages[iLevel].Status.Diffuse = StatusImages[Status];
			LevelImages[iLevel].Status.Opacity = StatusImages[Status];
			return;
		case 2:
			LevelTriggers[iLevel].Trigger.SetActive(true);
			LevelTriggers[iLevel].Trigger.SetHUDText(LevelTriggers[iLevel].MSG_Completed);
			LevelImages[iLevel].Image.Diffuse = LevelImages[iLevel].ImageEnabled;
			LevelImages[iLevel].Status.Diffuse = StatusImages[Status];
			LevelImages[iLevel].Status.Opacity = StatusImages[Status];
			return;
		default:
			break;
		}
		Log("EL_GabrielDemo::SetLevelStatus(): Error: Level or Status indices invalid");
	}
	*/
}

int32 AEL_GabrielDemo::GetTeamCode(int32 TeamIndex)
{
	switch (TeamIndex)
	{
	case 0:
		return SF572;
	case 1:
		return SF324;
	case 7:
		return SF468;
	case 2:
		return SF292;
	case 3:
		return SF624;
	case 4:
		return SF843;
	case 5:
		return SF132;
	case 6:
		return SF785;
	default:
		return 0;
	}
}

void AEL_GabrielDemo::SetTeamCode(int32 TeamIndex)
{
	/*
	switch (TeamIndex)
	{
	case 0:
		SF572 = (GetMachineID() + Team[0].offset);
		break;
	case 1:
		SF324 = (GetMachineID() + Team[1].offset);
		break;
	case 7:
		SF468 = (GetMachineID() + Team[7].offset);
		break;
	case 2:
		SF292 = (GetMachineID() + Team[2].offset);
		break;
	case 3:
		SF624 = (GetMachineID() + Team[3].offset);
		break;
	case 4:
		SF843 = (GetMachineID() + Team[4].offset);
		break;
	case 5:
		SF132 = (GetMachineID() + Team[5].offset);
		break;
	case 6:
		SF785 = (GetMachineID() + Team[6].offset);
		break;
	default:
		return;
	}
	SaveConfig();
	*/
}

FRotator AEL_GabrielDemo::RandLookRotation()
{
	//return FRotator(0, (Rand(32768) * 2), 0);
	return FRotator(0, 0, 0);    //FAKE   /ELiZ
}

void AEL_GabrielDemo::StopLipSincAnims()
{
	APawn* p = nullptr;
	/*
	ForEach AllActors(Class'Pawn', p)
	{
		p->StopLIPSincAnim();
	}
	*/
}
