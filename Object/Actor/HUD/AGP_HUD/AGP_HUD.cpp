// All the original content belonged to the US Army

#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/MyEnums.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Brush/Volume/CommVolume/AA2_CommVolume.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/AA29.h"
#include "AA29/AA2_WorldSettings.h"
#include "AA29/AA2_GameState.h"
#include "AA29/AA2_PlayerState.h"
#include "GameFramework/PlayerController.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_M67_Frag.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_Smoke.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M84_Stun/Throw_M84_Stun.h"
#include "UObject/ConstructorHelpers.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/UdpLink/UdpBeacon/ClientBeaconReceiver/ClientBeaconReceiver.h"
#include "AA29/Object/Actor/ServerBrowserBase/GameSpyServerList/GameSpyServerList.h"
#include "AA29/Object/Actor/ServerBrowserBase/ServerBrowserBase.h"
#include "AA29/Object/Actor/ServerBrowserBase/ServerBrowserDBMBS/ServerBrowserDBMBS.h"
#include "AA29/Object/Actor/ServerBrowserBase/ServerBrowserSCI/ServerBrowserSCI.h"
#include "AA29/Object/UIBase/UIFrame/GameMenuFrame/GameMenuFrame.h"
#include "AA29/Object/UIBase/UIFrame/HUDFrame/HUDFrame.h"
#include "AA29/Object/I3DL2Listener/I3DL2Listener.h"
#include "AA29/Object/UIBase/UIFrame/MissionResultsFrame/MissionResultsFrame.h"
#include "AA29/Object/ScriptObject/ScriptObject.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/UIHUDPercentageBar/UIHUDPercentageBar.h"
#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoSquad/CommoSquad.h"
#include "AA29/Object/Actor/Info/LocalMessage/HealLocalMessage/HealLocalMessage.h"
#include "AA29/Object/Actor/Info/LocalMessage/ObjectiveGiveLocalMessage/ObjectiveGiveLocalMessage.h"
#include "AA29/Object/Actor/Info/LocalMessage/ObjLocalMessage/ObjLocalMessage.h"
#include "AA29/Object/Actor/Info/LocalMessage/TurretLocalMessage/TurretLocalMessage.h"
#include "AA29/Object/UIBase/UIControl/UIHUDCompass/UIHUDCompass.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDCommoInfo/HUDCommoInfo.h"
#include "AA29/Object/UIBase/UIFrame/MainMenuFrame/MainMenuFrame.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDCrosshair/HUDCrosshair.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/WorldSettings.h"
#include "Engine/Canvas.h"
#include "Engine/Console.h"
#include "AA29/Object/Actor/Keypoint/AGP_Viewpoint/AGP_Viewpoint.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/SVehicle.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"

static const int32 kHUDResX = 800;
static const int32 kHUDResY = 600;
static const int32 kConsoleSizeY = 240;
static const int32 kServerInfoX = 10;
static const int32 kServerInfoY = 10;
static const int32 kSpectateTextRightX = 10;
static const int32 kSpectateTextY = 25;
static const int32 kConsoleOffsetX = 35;
static const int32 kMessagePromptPosition = 1;										    // vertical position to draw message prompt, scaled off of 800x600
static const int32 kMessagePosition = 18;												// vertical position to start drawing messages, scaled by 800x600
static const int32 kMessagePromptPositionWithFocusDebug = 305;
static const int32 kMessagePositionWithFocusDebug = 320;
static const int32 kMessagePromptPositionWithTrainingWindow = 260;
static const int32 kMessagePositionWithFocusWithTrainingWindow = 275;
static const float kCMessageFade = 2.0f;												// time to start fading the message
static const float SHORTMESSAGE_DELAYTIME = 0.10f;

AAGP_HUD::AAGP_HUD(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	afpShortMessageLengthYL.SetNum(32);
	ShortColor.SetNum(32);
	ShortMessages.SetNum(32);
	_sCMessage.SetNum(2);
	// Set the crosshair texture
	//static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_01.hud_crosshair_01'"));			//Dot
	//static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_02.hud_crosshair_02'"));			//Cross
	//static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_03.hud_crosshair_03'"));			//Circle
	//static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_04.hud_crosshair_04'"));			//Circle with Cross
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_05.hud_crosshair_05'"));			//4 Lines
	//static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_06.hud_crosshair_06'"));			//3 lines
	//static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_07.hud_crosshair_07'"));
	//static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_08a.hud_crosshair_08a'"));
	//static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_09a.hud_crosshair_09a'"));
	//static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_10a.hud_crosshair_10a'"));
	//static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_11a.hud_crosshair_11a'"));
	CrosshairTex = CrosshairTexObj.Object;

	tFill = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_goal_fill_Mat.hud_goal_fill_Mat'"), NULL, LOAD_None, NULL);
	//FontInfoClass = "Gameplay.FontInfo";
	bShowHUD = true;
	bFirstTime = true;
	bMainMenuFirstTime = true;
	bShowSpectatorInfo = true;
	CustomHUDColor = FColor(0, 255, 0, 150);
	CustomHUDAlpha = 255;
	ServerBrowser = "AA Browser";
	MessagePromptColor = FColor(0, 255, 255, 255);
	tArmyBox = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_border_nofill.ui_hud_border_nofill'"), NULL, LOAD_None, NULL);
	RadarMaskIndex = 1;
	bRotateRadarAroundPlayer = true;
	HUDColor = FColor(0, 255, 0, 150);
	DefaultFontScale = 1.0f;
	//DetermineVersionLabel(false, false, false, false, false, false, false, false, false, false, false);
}


//native final Function int32 GetMouseX();
int32 AAGP_HUD::GetMouseX()
{
	return 0;    //FAKE   /ELiZ
}

//native final Function int32 GetMouseY();
int32 AAGP_HUD::GetMouseY()
{
	return 0;    //FAKE   /ELiZ
}

void AAGP_HUD::UpdatePrecacheMaterials()
{
	/*
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_bleeding_Mat.ui_hud_bleeding_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_bleeding_fb_Mat.ui_hud_bleeding_fb_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_walk_fast_Mat.hud_health_walk_fast_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_walk_Mat.hud_health_walk_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_walk_fill_Mat.hud_health_walk_fill_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_crouch_fast_Mat.hud_health_crouch_fast_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_crouch_Mat.hud_health_crouch_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_crouch_fill_Mat.hud_health_crouch_fill_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_prone_fast_Mat.hud_health_prone_fast_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_prone_Mat.hud_health_prone_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_prone_fill_Mat.hud_health_prone_fill_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_sprint_Mat.hud_health_sprint_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_sprint_fill_Mat.hud_health_sprint_fill_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_combateffect_meter_Mat.ui_hud_combateffect_meter_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_com_hand_Mat.hud_com_hand_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_com_whisper_Mat.hud_com_whisper_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_com_shout_Mat.hud_com_shout_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_com_radio_Mat.hud_com_radio_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_rank_ssg_Mat.hud_rank_ssg_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_com_global_Mat.hud_com_global_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_01_Mat.hud_crosshair_01_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_02_Mat.hud_crosshair_02_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_03_Mat.hud_crosshair_03_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_04_Mat.hud_crosshair_04_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_05_Mat.hud_crosshair_05_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_06_Mat.hud_crosshair_06_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_07_Mat.hud_crosshair_07_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_nav_bracket_Mat.hud_nav_bracket_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_rank_ssg_Mat.hud_rank_ssg_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_rank_sgt_Mat.hud_rank_sgt_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_rank_pvt_Mat.hud_rank_pvt_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_rank_indigenous_Mat.hud_rank_indigenous_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_rank_captain_Mat.hud_rank_captain_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_rank_staffsgt_1st_Mat.hud_rank_staffsgt_1st_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_rank_VIP_Mat.hud_rank_VIP_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_fireteam_a_Mat.hud_fireteam_a_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_fireteam_b_Mat.hud_fireteam_b_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_fireteam_c_Mat.hud_fireteam_c_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_fireteam_d_Mat.hud_fireteam_d_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_healing_Mat.ui_hud_healing_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_medpack_Mat.ui_hud_medpack_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_cem_stamina_meter_Mat.ui_hud_cem_stamina_meter_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_discard_Mat.hud_mode_discard_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_reload_Mat.hud_mode_reload_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_recharge_Mat.hud_mode_recharge_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_roll_Mat.hud_mode_roll_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_fixjam_Mat.hud_mode_fixjam_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_livegrenade_Mat.hud_mode_livegrenade_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_supported_Mat.hud_mode_supported_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_single_Mat.hud_mode_single_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_burst_Mat.hud_mode_burst_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_auto_Mat.hud_mode_auto_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_grenade_Mat.hud_mode_grenade_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_targeting_Mat.hud_mode_targeting_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_lockedon_Mat.hud_mode_lockedon_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_tooclose_Mat.hud_mode_tooclose_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_javelintube_Mat.hud_mode_javelintube_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_optics_BINOCS_m22_Mat.hud_optics_BINOCS_m22_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_optics_BINOCS_m24_Mat.hud_optics_BINOCS_m24_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_optics_BINOCS_tank_Mat.hud_optics_BINOCS_tank_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_optics_BINOCS_newt_Mat.hud_optics_BINOCS_newt_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_optics_CLU_Mat.hud_optics_CLU_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_db_Mat.hud_wpn_db_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_carriable_Mat.ui_hud_carriable_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_noncarriable_Mat.ui_hud_noncarriable_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_at4_Mat.hud_ammo_at4_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_javelin_Mat.hud_ammo_javelin_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_goal_fill_Mat.hud_goal_fill_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_border_nofill_Mat.ui_hud_border_nofill_Mat'"), NULL, LOAD_None, NULL));
	Level->AddPrecacheMaterial(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Overlays/fx_overlays_pain_Mat.fx_overlays_pain_Mat'"), NULL, LOAD_None, NULL));	*/
}

void AAGP_HUD::PrecacheFonts(UCanvas* C)
{
	/*
	C.Font = GetConsoleFont(C);
	C.SetPos(0, 0);
	C.DrawText("<>_Aa1");
	C.Font = GetFontSizeIndex(C, -2);
	C.SetPos(0, 0);
	C.DrawText("Aa1");
	C.Font = GetFontSizeIndex(C, -4);
	C.SetPos(0, 0);
	C.DrawText("Aa1");
	C.Font = GetFontSizeIndex(C, MessageFontOffset);
	C.SetPos(0, 0);
	C.DrawText("Aa1");
	C.Font = GetFontSizeIndex(C, (1 + MessageFontOffset));
	C.SetPos(0, 0);
	C.DrawText("Aa1");
	C.Font = GetFontSizeIndex(C, (2 + MessageFontOffset));
	C.SetPos(0, 0);
	C.DrawText("Aa1");
	C.Font = GetFontSizeIndex(C, (3 + MessageFontOffset));
	C.SetPos(0, 0);
	C.DrawText("Aa1");
	*/
}

void AAGP_HUD::UseSmallFont(UCanvas* C)
{

	if (Canvas->SizeX <= 800)
	{
		//Canvas->Font = SmallFont;
	}
	else
	{
		//Canvas->Font = MedFont;
	}
}

void AAGP_HUD::TournamentNotifyNewTeamCaptain()
{
}

void AAGP_HUD::TournamentNotifyOtherTeamReady()
{
}

void AAGP_HUD::TournamentNotifyNewTeamName()
{
}

void AAGP_HUD::TournamentNotifyNewWeaponClassLockState()
{

}
void AAGP_HUD::TournamentNotifyMyTeamReady()
{

}


void AAGP_HUD::DetermineVersionLabel(bool bCheat, bool bDev, bool bBeta, bool bLeased, bool bOfficial, bool bNATO, bool bTournament, bool bUltimateArena, bool bIsAuthorized, bool bExploreTheArmyServer, bool bAllowForceclassing)
{
	FString cheat;
	FString tournament;
	FString Debug;
	FString sSubTinyVersion;
	
	if (bCheat)
	{
		cheat = "(Cheats) ";
	}
	if (bTournament)
	{
		if(GetWorld())
		{
			if (GetWorld()->GetGameState() != NULL)
			{
				tournament = "(Tournament - " + Cast<AAA2_GameState>(GetWorld()->GetGameState())->sTournamentState + ")";
			}
		}
	}
	if (bExploreTheArmyServer)
	{
		if (bOfficial)
		{
			sServerMode = "(Official Explorer Server - No HONOR Gained) ";
		}
		else
		{
			sServerMode = "(Unauthorized Explorer Server) ";
		}
	}
	else
	{
		if (bDev)
		{
			sServerMode = "(Dev Server) ";
		}
		else
		{
			if (bBeta)
			{
				sServerMode = "(Beta Server) ";
			}
			else
			{
				if (bNATO)
				{
					sServerMode = "(Europe Server) ";
				}
				else
				{
					if (bLeased)
					{
						if (bOfficial)
						{
							sServerMode = "(Leased-Official Server) ";
						}
						else
						{
							sServerMode = "(Leased Server) ";
						}
					}
					else
					{
						if (bOfficial)
						{
							sServerMode = "(Official Server) ";
						}
						else
						{
							if (bIsAuthorized)
							{
								sServerMode = "(Authorized Server) ";
							}
							else
							{
								sServerMode = "(Unauthorized Server) ";
							}
						}
					}
				}
			}
		}
	}
	//if (IsDebugBuild())
	//{
	//	Debug = "(DEBUG) ";
	//}
	if (bAllowForceclassing)
	{
		sServerMode = FString("(FC Allowed) ") + sServerMode;
	}

	sSubTinyVersion = FString::FromInt(GetVersionAGPTiny());
	if (GetVersionAGPSubTiny() > 0)
	{
		sSubTinyVersion = sSubTinyVersion + FString(".");
		if (GetVersionAGPSubTiny() < 10)
		{
			sSubTinyVersion = sSubTinyVersion + FString("0");
		}
		sSubTinyVersion = sSubTinyVersion + FString::FromInt(GetVersionAGPSubTiny());
	}
	_sVersionInfo = FString::FromInt(GetVersionAGPMajor()) + "." + FString::FromInt(GetVersionAGPMinor()) + FString(".") + sSubTinyVersion;
	
	//if (PlayerOwner.GetNetMode() != ENetMode::NM_Standalone)
	if (GetNetMode() != ENetMode::NM_Standalone)
	{
		if(Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
		{
			_sVersionInfo = cheat + tournament + sServerMode + " (Coop) " + Debug + _sVersionInfo;
		}
		else
		{
			_sVersionInfo = cheat + tournament + sServerMode + Debug + _sVersionInfo;
		}
	}
	else
	{
		_sVersionInfo = "Offline " + Debug + _sVersionInfo;
	}
	
	switch (GetNetMode())
	{
		case ENetMode::NM_Standalone:
		{
			_sVersionInfo += " NM_Standalone";
			break;
		}
		case ENetMode::NM_DedicatedServer:
		{
			_sVersionInfo += " NM_DedicatedServer";
			break;
		}
		case ENetMode::NM_ListenServer:
		{
			_sVersionInfo += " NM_ListenServer";
			break;
		}
		case ENetMode::NM_Client:
		{
			_sVersionInfo += " NM_Client";
			break;
		}
	}
	
}

bool AAGP_HUD::AllowFade()
{
	if (bShowMainMenu)
	{
		return false;	//Don't allow a fade if I'm looking at the menu
	}
	return true;
}

void AAGP_HUD::SetHUDActor()
{
	if (_cHUDFrame != nullptr)
	{
		_cHUDFrame->SetHUDActor();
	}
}

void AAGP_HUD::FreeHUDActor()
{
	if (_cHUDFrame == nullptr)
	{
		_cHUDFrame->FreeHUDActor();
	}
}


UUIControl* AAGP_HUD::GetHUDControl(int32 Id)
{
	if (_cHUDFrame == nullptr)
	{
		return nullptr;
	}
	//_cHUDFrame->cActor = PlayerOwner->Pawn;
	return _cHUDFrame->GetControl(Id);
	return false;   //FAKE   /ELiZ
}

UObject* AAGP_HUD::CreateUIObject(FString ObjectName)
{
	UObject* myObject = nullptr;
	UObject* cObject = nullptr;
	//cObject = class<Object>(DynamicLoadObject(ObjectName, Class'Class'));
	//myObject = new (None) classcObject;
	return myObject;
}

void AAGP_HUD::Destroyed()
{
	if (gmFrame != nullptr)
	{
		gmFrame->Destroyed();
		gmFrame = nullptr;
	}
	if (mmFrame != nullptr)
	{
		mmFrame->Destroyed();
		mmFrame = nullptr;
	}
	if (mrFrame != nullptr)
	{
		mrFrame->Destroyed();
		mrFrame = nullptr;
	}
	if (_cHUDFrame != nullptr)
	{
		_cHUDFrame->Destroyed();
		_cHUDFrame = nullptr;
	}
	PawnOwner = nullptr;
	SavedZoneEffect = nullptr;
	_MissionResultTarget = nullptr;
	if (ClientBeacon != nullptr)
	{
		ClientBeacon->Destroy();
		ClientBeacon = nullptr;
	}
	BrowserGSPY = nullptr;
	BrowserSCI = nullptr;
	BrowserDBMBS = nullptr;
	Super::Destroyed();
}

void AAGP_HUD::PostRender_Stage1(UCanvas* C)
{
	/*
	AHumanController* HC = nullptr;
	if (bBRoll)
	{
		return;
	}
	if ((Canvas == nullptr) || (PlayerOwner == nullptr))
	{
		return;
	}
	Super::PostRender_Stage1(Canvas);
	if (Level.LevelAction == 1)
	{
		CloseAllMenus();
	}
	bMenuVisible = bShowMainMenu;
	HC = HumanController(PlayerOwner);
	if (HC != nullptr)
	{
		HC.RenderOverlays_Stage1(Canvas);
	}
	*/
}

void AAGP_HUD::PostRender_Stage2(UCanvas* C)
{
	float FocusTargetOffset = 0;
	/*
	if (((Canvas == nullptr) || (PlayerOwner == nullptr)) || (Cast<AHumanController>(PlayerOwner) == nullptr))
	{
		return;
	}
	HumanController(PlayerOwner).RenderOverlays_Stage2(Canvas);
	HumanController(PlayerOwner).PostRender(Canvas);
	if ((Level.TimeSeconds - LastVoiceGainTime) < 0.333)
	{
		DisplayVoiceGain(Canvas);
	}
	if (((bShowCoords && (PlayerOwner.Pawn != nullptr)) && (Level != nullptr)) && (_cHUDFrame != nullptr))
	{
		Canvas.Font = _cHUDFrame.Fonts[1];
		Canvas.Style = ERenderStyle.STY_Alpha;
		Canvas.DrawColor = ConsoleColor;
		Canvas.SetPos(4, (Canvas.ClipY - float(96)));
		Canvas.DrawText("Location: " + FString::FromInt(PlayerOwner.Pawn.Location) + " MapName: " + Level.GetLevelName(), false);
	}
	if (bPortalDebugView && (PlayerOwner.FocusTarget != nullptr))
	{
		if (DebugSceneDistanceOverride != 0)
		{
			FocusTargetOffset = DebugSceneDistanceOverride;
		}
		else
		{
			if (PlayerOwner.FocusTarget->IsA(ASVehicle::StaticClass()))
			{
				FocusTargetOffset = 1024;
			}
			else
			{
				if (PlayerOwner.FocusTarget->IsA(AAGP_MortarRangeDestroyableObjective::StaticClass()))
				{
					FocusTargetOffset = 1500;
				}
				else
				{
					FocusTargetOffset = 128;
				}
			}
		}
		CirclingRotation = PlayerOwner.FocusTarget.Rotation;
		(CirclingRotation.Pitch -= 8000);
		if (PlayerOwner.FocusTarget->IsA(AAGP_MortarRangeDestroyableObjective::StaticClass()))
		{
			DebugSceneSizeX = 0.25;
			DebugSceneSizeY = 0.4;
			DebugSceneXLocation = 0;
			DebugSceneYLocation = 0;
			CirclingRotation.Yaw = (int((Level.TimeSeconds * float(65536))) / 40);
		}
		else
		{
			CirclingRotation.Yaw = (int((Level.TimeSeconds * float(65536))) / 10);
		}
		Canvas.DrawPortal(int((float(Canvas.SizeX) * DebugSceneXLocation)), int((float(Canvas.SizeY) * DebugSceneYLocation)), int((float(Canvas.SizeX) * DebugSceneSizeX)), int((float(Canvas.SizeY) * DebugSceneSizeY)), Self, (PlayerOwner.FocusTarget.Location - (FocusTargetOffset * Vector(CirclingRotation))), CirclingRotation, DebugSceneFOV, false);
	}
	PostRender_Stage2_DrawConsole(Canvas);
	*/
}

void AAGP_HUD::DrawConsole(UCanvas* C)
{
	float mesX = 0;
	float mesY = 0;
	float fpCharHeight = 0;
	float fpCharWidth = 0;
	float fpCalculatedConsoleWidth = 0;
	int32 oldstyle = 0;
	int32 textheight = 0;
	int32 Height = 0;
	int32 fullscreenoffset = 0;
	if (PlayerOwner != nullptr)
	{
		UseSmallFont(Canvas);
		textheight = int(GetTextHeight(Canvas));
		/*
		oldstyle = Canvas.Style;
		Canvas.Style = ERenderStyle.STY_Alpha;
		if (PlayerOwner.Player != nullptr)
		{
			if (PlayerOwner.Player.bFullScreen)
			{
				fullscreenoffset = 8;
			}
			else
			{
				fullscreenoffset = 0;
			}
		}
		if (PlayerConsole != nullptr)
		{
			if ((PlayerConsole.bTyping && (!PlayerConsole.bTypeOnly)) && (!_bUIConsole))
			{
				Height = int((((float(Canvas.SizeY) - (float(240) * _cHUDFrame.fScaleY)) + 6) - float(fullscreenoffset)));
				if (Height < (((textheight * 32) + 6) - fullscreenoffset))
				{
					Height = (((textheight * 32) + 6) - fullscreenoffset);
				}
				if (_cHUDFrame != nullptr)
				{
					(Height += int((float((GetMessagePosition() - GetMessagePromptPosition())) * _cHUDFrame.fScaleY)));
					Canvas.SetPos(0, 0);
					if ((PlayerOwner.Player != nullptr) && (PlayerOwner.Player.Console != nullptr))
					{
						PlayerOwner.Player.Console.Font = SmallFont;
						if (bPortalDebugView && (!bShowDebugInfo))
						{
							Canvas.SetPos(0, float(GetMessagePromptPosition()));
							Canvas.DrawTile(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/AGP/Icons/Fade_Mat.Fade_Mat'"), NULL, LOAD_None, NULL), (GetConsoleMessageOffsetX(Canvas) + (float(Canvas.SizeX) * (fpConsoleWidthPercent + 0.02))), float(Height), 200, 0, 1, 1);
						}
						else
						{
							if (fpConsoleWidthPercent == 0)
							{
								Canvas.DrawTile(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/AGP/Icons/Fade_Mat.Fade_Mat'"), NULL, LOAD_None, NULL), ((GetConsoleMessageOffsetX(Canvas) + (float(PlayerOwner.Player.Console.64) * (PlayerOwner.Player.Console.GetTextWidth("XXXX") / 4))) + GetTextWidth(Canvas)), float(Height), 200, 0, 1, 1);
							}
							else
							{
								Canvas.DrawTile(LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/AGP/Icons/Fade_Mat.Fade_Mat'"), NULL, LOAD_None, NULL), (GetConsoleMessageOffsetX(Canvas) + (float(Canvas.SizeX) * (fpConsoleWidthPercent + 0.02))), float(Height), 200, 0, 1, 1);
							}
						}
					}
				}
			}
		}
		Canvas.Style = uint8(oldstyle);
		*/
	}
	if (!bMenuVisible)
	{
		if (!_bUIConsole)
		{
			UseSmallFont(Canvas);
			DisplayMessages(Canvas);
			UseSmallFont(Canvas);
			if (PlayerConsole != nullptr)
			{
				/*
				Canvas.StrLen(PlayerConsole.TypedStr, mesX, mesY);
				Canvas.StrLen("X", fpCharHeight, fpCharWidth);
				if (fpConsoleWidthPercent != 0)
				{
					fpCalculatedConsoleWidth = ((float(Canvas.SizeX) * fpConsoleWidthPercent) - (fpCharWidth / 2));
				}
				else
				{
					fpCalculatedConsoleWidth = 380;
				}
				if (((Left(PlayerConsole.TypedStr, 5) ~= "start") || (Left(PlayerConsole.TypedStr, 4) ~= "open")) || (Left(PlayerConsole.TypedStr, 7) ~= "connec"))
				{
					fpCalculatedConsoleWidth = 1000;
				}
				if (mesX >= fpCalculatedConsoleWidth)
				{
					PlayerConsole.TypedStr = Left(PlayerConsole.TypedStr, (Len(PlayerConsole.TypedStr) - 1));
					Canvas.StrLen(PlayerConsole.TypedStr, mesX, mesY);
				}
				if (PlayerConsole.bTyping)
				{
					DrawTypingPrompt(Canvas, PlayerConsole.TypedStr, PlayerConsole.TypedStrPos);
				}
				*/
			}
		}
	}
	DisplayMessages(C);
}


void AAGP_HUD::PostRender_Stage2_DrawConsole(UCanvas* C)
{
	float XPos = 0;
	float YPos = 0;
	FPlane OldModulate = FPlane({});
	FColor OldColor = FColor(0, 0, 0, 0);
	/*
	if (((Canvas == nullptr) || (PlayerOwner == nullptr)) || (Cast<AHumanController>(PlayerOwner) == nullptr))
	{
		return;
	}
	if (bBRoll)
	{
		return;
	}
	if (ShouldDisplayMOTD())
	{
		BuildMOTD();
	}
	OldModulate = Canvas.ColorModulate;
	OldColor = Canvas.DrawColor;
	if ((PlayerOwner != nullptr) && (PlayerOwner.GameReplicationInfo != nullptr))
	{
		CheckCountdown(PlayerOwner.GameReplicationInfo);
	}
	if (PawnOwner != nullptr)
	{
		if ((PlayerOwner != nullptr) && (PlayerOwner.bDemoOwner || ((GetWorld()->GetNetMode() == NM_Client) && (PlayerOwner.Pawn != PawnOwner))))
		{
			PawnOwner.GetDemoRecordingWeapon();
		}
	}
	if (((PlayerConsole == nullptr) && (PlayerOwner != nullptr)) && (PlayerOwner.Player != nullptr))
	{
		PlayerConsole = PlayerOwner.Player.Console;
	}
	if (bShowDebugInfo)
	{
		Canvas.Font = GetConsoleFont(Canvas);
		Canvas.Style = ERenderStyle.STY_Alpha;
		Canvas.DrawColor = ConsoleColor;
		YPos = 0;
		if (((((LowSpamDebugInfo && (PlayerOwner.FocusTarget != nullptr)) && PlayerOwner.FocusTarget->IsA(APawn::StaticClass())) && (Cast<APawn>(PlayerOwner.FocusTarget).Controller != nullptr)) && (!PlayerOwner.FocusTarget->IsA(AVehicle::StaticClass()))) && (Cast<ANPCBaseController>(Cast<APawn>(PlayerOwner.FocusTarget).Controller) != nullptr))
		{
			NPCBaseController(Cast<APawn>(PlayerOwner.FocusTarget).Controller).DisplayDebugNoSpam(this, Canvas, XPos, YPos, LowSpamDebugInfoTextColor);
		}
		else
		{
			if (PlayerOwner.FocusTarget != nullptr)
			{
				PlayerOwner.FocusTarget.DisplayDebug(Canvas, XPos, YPos);
			}
			else
			{
				PlayerOwner.ViewTarget.DisplayDebug(Canvas, XPos, YPos);
			}
		}
	}
	DrawHUD(Canvas);
	DrawConsole(Canvas);
	if (bMenuVisible)
	{
		return;
	}
	bHideCenterMessages = DrawLevelAction(Canvas);
	if (((PlayerOwner != nullptr) && (!bHideCenterMessages)) && (PlayerOwner.ProgressTimeOut > Level.TimeSeconds))
	{
		DisplayProgressMessages(Canvas);
	}
	if (bBadConnectionAlert)
	{
		DisplayBadConnectionAlert(Canvas);
	}
	if (((TextureMovie != nullptr) && (TextureMovie.Movie != nullptr)) && TextureMovie.Movie.IsPlaying())
	{
		if (TexMovieTranslucent)
		{
			Canvas.Style = ERenderStyle.STY_Translucent;
		}
		else
		{
			Canvas.Style = ERenderStyle.STY_Normal;
		}
		Canvas.SetDrawColor(255, 255, 255);
		Canvas.SetPos((TexMovieLeft * float(Canvas.SizeX)), (TexMovieTop * float(Canvas.SizeY)));
		Canvas.DrawTile(TextureMovie, ((TexMovieRight - TexMovieLeft) * float(Canvas.SizeX)), ((TexMovieBottom - TexMovieTop) * float(Canvas.SizeY)), 0, 0, float(TextureMovie.Movie.GetWidth()), float(TextureMovie.Movie.GetHeight()));
	}
	Canvas.ColorModulate = OldModulate;
	Canvas.DrawColor = OldColor;
	*/
}

void AAGP_HUD::WorldSpaceOverlays()
{
	int32 iNode = 0;
	FColor clrCurrentRouteCache = FColor(0, 0, 0, 0);
	/*
	Super::WorldSpaceOverlays();
	if (((bPortalDebugView && (PlayerOwner.FocusTarget != nullptr)) && PlayerOwner.FocusTarget->IsA(APawn::StaticClass())) && (Cast<APawn>(PlayerOwner.FocusTarget).Controller != nullptr))
	{
		clrCurrentRouteCache = Class'Canvas'.MakeColor(255, 128, 128);
		for (iNode = 0; iNode < 62; iNode++)
		{
			if (Cast<APawn>(PlayerOwner.FocusTarget).Controller.RouteCache[iNode] == nullptr)
			{
			}
			if (iNode == 0)
			{
				Draw3DLine(Cast<APawn>(PlayerOwner.FocusTarget)->GetActorLocation(), Pawn(PlayerOwner.FocusTarget).Controller.RouteCache[iNode]->GetActorLocation(), clrCurrentRouteCache);
			}
			else
			{
				Draw3DLine(Cast<APawn>(PlayerOwner.FocusTarget).Controller.RouteCache[(iNode - 1)]->GetActorLocation(), Pawn(PlayerOwner.FocusTarget).Controller.RouteCache[iNode]->GetActorLocation(), clrCurrentRouteCache);
			}
		}
	}
	*/
}

void AAGP_HUD::SetMissionResultTarget(UScriptObject* so)
{
	_MissionResultTarget = so;
}

void AAGP_HUD::CreateFrame()
{
	if (gmFrame == nullptr)
	{
		gmFrame = Cast<UGameMenuFrame>(CreateUIObject("AGP.GameMenuFrame"));
		gmFrame->Create(this);
	}
	if (mmFrame == nullptr)
	{
		mmFrame = Cast<UMainMenuFrame>(CreateUIObject("AGP.MainMenuFrame"));
		mmFrame->Create(this);
	}
	if (mrFrame == nullptr)
	{
		mrFrame = Cast<UMissionResultsFrame>(CreateUIObject("AGP.MissionResultsFrame"));
		mrFrame->Create(this);
	}
	if (_cHUDFrame == nullptr)
	{
		_cHUDFrame = Cast<UHUDFrame>(CreateUIObject("AGP.HUDFrame"));
		_cHUDFrame->CreateHUDFrame(this, PlayerOwner);
	}
	if (ClientBeacon == nullptr)
	{
		//ClientBeacon = Spawn(Class'IpDrv.ClientBeaconReceiver', this);
	}
}

void AAGP_HUD::FillListBox()
{
	FString sString = "";
	int32 i = 0;
	i = 0;
	/*
	sString = GetMapName("", "", 0);
	if ((sString != "") && (i < 64))
	{
		sString = GetMapName("", sString, 1);
		i++;
	}
	*/
}

bool AAGP_HUD::FrameOverride()
{
	/*
	if ((Level != nullptr) && (Level.LevelAction == 0))
	{
		if (Level.Pauser != nullptr)
		{
			return true;
		}
	}
	if (((PlayerConsole != nullptr) && PlayerConsole.bTyping) && (! _bUIConsole))
	{
		return true;
	}
	*/
	return false;
}

void AAGP_HUD::DisablePlayer()
{
	if (PlayerOwner != nullptr)
	{
		/*
		PlayerOwner.bFire=0;
		if (PlayerOwner.Player != nullptr)
		{
			PlayerOwner.Player.bDetachMouse=true;
			PlayerOwner.Player.bShowWindowsMouse=true;
		}
		*/
	}
}

void AAGP_HUD::EnablePlayer()
{
	if (PlayerOwner != nullptr)
	{
		if (PlayerOwner->Player != nullptr)
		{
			/*
			PlayerOwner.Player.bDetachMouse = false;
			PlayerOwner.Player.bShowWindowsMouse = false;
			*/
		}
		/*
		if (PlayerOwner->PlayerReplicationInfo != nullptr)
		{
			if (!PlayerOwner.PlayerReplicationInfo.bReadyToPlay)
			{
				Cast<AHumanController>(PlayerOwner).ServerEnablePlayer();
			}
		}
		*/
	}
}

void AAGP_HUD::SetConsoleWidth(FString sNewWidthPercent)
{
	float fpNewWidthPercent = 0;
	/*
	Log("NewWidthPercent: \"" + sNewWidthPercent + "\" length: " + FString::FromInt(Len(sNewWidthPercent)));
	if (sNewWidthPercent ~= "Reset")
	{
		fpNewWidthPercent = 0;
	}
	else
	{
		fpNewWidthPercent = float(sNewWidthPercent);
	}
	if (Len(sNewWidthPercent) == 0)
	{
		if (fpConsoleWidthPercent != 0)
		{
			HumanController(PlayerOwner).ClientMessage("You can restore the default console width using 'SetConsoleWidth Reset'");
			HumanController(PlayerOwner).ClientMessage("Current console width is  " + FString::FromInt(int((fpConsoleWidthPercent * 100))) + "%");
		}
		else
		{
			HumanController(PlayerOwner).ClientMessage("Console width currently set to default");
		}
		return;
	}
	if ((fpNewWidthPercent >= 25) && (fpNewWidthPercent < 100))
	{
		fpConsoleWidthPercent = (fpNewWidthPercent / 100);
	}
	else
	{
		if (fpNewWidthPercent == 0)
		{
			fpConsoleWidthPercent = 0;
		}
	}
	SaveConfig();
	if (fpConsoleWidthPercent == 0)
	{
		HumanController(PlayerOwner).ClientMessage("Console width currently set to default");
	}
	else
	{
		HumanController(PlayerOwner).ClientMessage("You can restore the default console width using 'SetConsoleWidth Reset'");
		HumanController(PlayerOwner).ClientMessage("Console width set to  " + FString::FromInt(int((fpConsoleWidthPercent * 100))) + "%");
	}
	*/
}

void AAGP_HUD::OLD_ShowScores()
{
	if (!bShowMainMenu)
	{
		//Super::OLD_ShowScores();
	}
}

void AAGP_HUD::ShowScores()
{
	if (Cast<AHumanController>(PlayerOwner) != nullptr)
	{
		Cast<AHumanController>(PlayerOwner)->ShowScores("");
	}
}

void AAGP_HUD::OpenGameMenu()
{
	if (gmFrame != nullptr)
	{
		if (FrameOverride())
		{
			return;
		}
		bShowGameMenu = true;
		DisablePlayer();
		if (PlayerOwner != nullptr)
		{
			//PlayerOwner->MenuLock(true);
		}
	}
}
void AAGP_HUD::CloseGameMenu()
{
	if (bShowGameMenu == true)
	{
		gmFrame->Hide();
		bShowGameMenu = false;
		EnablePlayer();
		if (PlayerOwner != nullptr)
		{
			//PlayerOwner->MenuLock(false);
		}
		if (_bUIConsole)
		{
			_bUIConsole = false;
			/*
			if (PlayerConsole->bTyping)
			{
				PlayerConsole->GotoState("None");
			}
			*/
		}
	}
}
void AAGP_HUD::ToggleAGPGameMenu()
{
	//PlayerOwner->ClientCloseMenu(true);
	if (bShowGameMenu)
	{
		CloseGameMenu();
	}
	else
	{
		CloseAllMenus();
		OpenGameMenu();
	}
}
void AAGP_HUD::ToggleAGPMainMenu()
{

}
void AAGP_HUD::CloseAllMenus()
{
	CloseGameMenu();
	CloseMainMenu();
	CloseMissionResults();
	bShowScores = false;
}
void AAGP_HUD::OpenMainMenu()
{
	return;
}
void AAGP_HUD::CloseMainMenu()
{
	/*
	if (bShowMainMenu == true)
	{
		if ((iDesiredXRes < 800) || (iDesiredYRes < 600))
		{
			PlayerConsole.ConsoleCommand("setres " + FString::FromInt(iDesiredXRes) + "x" + FString::FromInt(iDesiredYRes));
		}
		mmFrame.Hide();
		PlayerConsole.MenuClosed();
		bShowMainMenu=false;
		if (ClientBeacon != nullptr)
		{
			ClientBeacon.StopBeacon();
		}
		Region.Zone.ZoneEffect=SavedZoneEffect;
		if (PlayerOwner != nullptr)
		{
			if (! (Level.sLevelName ~= "entry"))
			{
				PlayerOwner.SetPause(false);
			}
			PlayerOwner.MenuLock(false);
		}
	}
	*/
}
void AAGP_HUD::OpenMissionResults()
{
	/*
	if (mrFrame != nullptr)
	{
		if (FrameOverride())
		{
			return;
		}
		bShowMissionResults=true;
		DisablePlayer();
		if (PlayerOwner != nullptr)
		{
			PlayerOwner.MenuLock(true);
		}
	}
	*/
}
void AAGP_HUD::CloseMissionResults()
{
	/*
	if (bShowMissionResults == true)
	{
		mrFrame.Hide();
		bShowMissionResults=false;
		EnablePlayer();
		if (_MissionResultTarget != nullptr)
		{
			_MissionResultTarget.Notify();
		}
		if (PlayerOwner != nullptr)
		{
			PlayerOwner.MenuLock(false);
		}
	}
	*/
}
void AAGP_HUD::OpenMap(FString sMap)
{
	/*
	if (sMap != "")
	{
		CloseGameMenu();
		PawnOwner.ConsoleCommand("start " + sMap);
	}
	*/
}
void AAGP_HUD::SpawnItem(FString Item)
{
	/*
	if (Item != "")
	{
		PlayerOwner.ConsoleCommand("summon " + Item);
	}
	*/
}
bool AAGP_HUD::KeyType(int32 Key)
{
	/*
	if (PlayerOwner.Player.Console != nullptr)
	{
		if (PlayerOwner.Player.Console.IsInState("Typing"))
		{
			return false;
		}
	}
	if (bShowMainMenu)
	{
		return mmFrame.KeyType(Key);
	}
	if (bShowGameMenu)
	{
		return gmFrame.KeyType(Key);
	}
	*/
	return false;
}

bool AAGP_HUD::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	bool bCommoActive = false;
	bool bTargetActive = false;
	/*
	if ((Key >= 48) && (Key <= 57))
	{
		if (EventLab != nullptr)
		{
			EventLab.ActorNotify(this, 31, nullptr, "KeyPress," + FString::FromInt(Key));
		}
	}
	if (PlayerOwner->Player->Console != nullptr)
	{
		if (PlayerOwner->Player->Console->IsInState("Typing"))
		{
			return false;
		}
	}
	*/
	SetHUDActor();
	bCommoActive = Cast<UHUDCommoInfo>(GetHUDControl(13))->ShowingMessages();
	FreeHUDActor();
	if ((PlayerOwner != nullptr) && bCommoActive)
	{
		if ((Key >= 48) && (Key <= 57))
		{
			if (Action == 1)
			{
				Cast<AHumanController>(PlayerOwner)->CommoSendMessage((Key - 48));
			}
			return true;
		}
	}
	SetHUDActor();
	bTargetActive = Cast<UUIHUDCompass>(GetHUDControl(5))->IsSettingTarget();
	FreeHUDActor();
	if ((PlayerOwner != nullptr) && bTargetActive)
	{
		if ((Key >= 65) && (Key <= 90))
		{
			if (Action == 1)
			{
				//ScreenPrint("HC called with" @ FString::FromInt(Key));
				//Cast<AHumanController>(PlayerOwner)->ServerSetSquadTarget(Cast<AHumanController>(PlayerOwner)->PlayerReplicationInfo->Team>Team-TeamIndex, uint8((Key - 65)));
				//Cast<AHumanController>(PlayerOwner)->CommoSend(class'AGP.CommoSquad', 18);
				SetHUDActor();
				Cast<UUIHUDCompass>(GetHUDControl(5))->SetTarget(false);
				FreeHUDActor();
			}
			return true;
		}
	}
	if (bShowMissionResults)
	{
		if (Key == 1)
		{
			mrFrame->ProcessKeyEvent(Key, Action, Delta);
			if (Action == 1)
			{
				bMouseClick = true;
			}
			if (Action == 3)
			{
				bMouseClick = false;
			}
			return true;
		}
		else
		{
			return mrFrame->ProcessKeyEvent(Key, Action, Delta);
		}
	}
	if (bShowMainMenu)
	{
		if (Key == 1)
		{
			mmFrame->ProcessKeyEvent(Key, Action, Delta);
			if (Action == 1)
			{
				bMouseClick = true;
			}
			if (Action == 3)
			{
				bMouseClick = false;
			}
			return true;
		}
		else
		{
			return mmFrame->ProcessKeyEvent(Key, Action, Delta);
		}
	}
	if (bShowGameMenu)
	{
		if (Key == 1)
		{
			gmFrame->ProcessKeyEvent(Key, Action, Delta);
			if (Action == 1)
			{
				bMouseClick = true;
			}
			if (Action == 3)
			{
				bMouseClick = false;
			}
			return true;
		}
		else
		{
			return gmFrame->ProcessKeyEvent(Key, Action, Delta);
		}
	}
	return false;
}

void AAGP_HUD::ConsoleOpened()
{
	/*
	if (PlayerConsole->bTyping && !_bUIConsole)
	{
		CloseGameMenu();
		CloseMainMenu();
	}
	*/
}

void AAGP_HUD::DrawMenu(UCanvas* C)
{
	float mX = 0;
	float mY = 0;
	float aX = 0;
	float aY = 0;
	bool mC = false;
	float XL = 0;
	float YL = 0;
	/*
	mX = PlayerOwner.Player.WindowsMouseX;
	mY = PlayerOwner.Player.WindowsMouseY;
	mC = PlayerOwner.Player.bWindowsMouseAvailable;
	aX = PlayerOwner.aMouseX;
	aY = PlayerOwner.aMouseY;
	if (Level.LevelAction == 0)
	{
		if (Level.Pauser != nullptr)
	}
	{
	}
	if (bShowGameMenu)
	{
		if (gmFrame != nullptr)
		{
			Canvas.bNoNightVision = true;
			gmFrame.SetMouse(int(mX), int(mY));
			gmFrame.Draw(Canvas);
			Canvas.bNoNightVision = false;
		}
	}
	else
	{
		if (bShowMainMenu)
		{
			if (mmFrame != nullptr)
			{
				Canvas.bNoNightVision = true;
				mmFrame.SetMouse(int(mX), int(mY));
				mmFrame.Draw(Canvas);
				Canvas.bNoNightVision = false;
			}
		}
		else
		{
			if (bShowMissionResults)
			{
				if (mrFrame != nullptr)
				{
					Canvas.bNoNightVision = true;
					mrFrame.SetMouse(int(mX), int(mY));
					mrFrame.Draw(Canvas);
					Canvas.bNoNightVision = false;
				}
			}
		}
	}
	if (((PawnOwner != nullptr) && (Cast<AAGP_Pawn>(PawnOwner) != nullptr)) && AGP_Pawn(PawnOwner).angleEditor)
	{
		Canvas.SetDrawColor(255, 255, 255, 255);
		Canvas.TextSize(_sVersionInfo, XL, YL);
		DrawAngleEditor(Canvas);
	}
	if (bShowHUD || bShowVersion)
	{
		Canvas.SetClip(float(Canvas.SizeX), float(Canvas.SizeY));
		Canvas.SetDrawColor(255, 255, 255, 255);
		if ((PlayerOwner.GetWorld()->GetNetMode() != NM_Standalone) && HumanController(PlayerOwner).TournamentIsTournament())
		{
			_sVersionInfo = "(Tournament - " + PlayerOwner.GameReplicationInfo.sTournamentState + ") " + sServerMode + " " + FString::FromInt(GetVersionAGPMajor()) + "." + FString::FromInt(GetVersionAGPMinor()) + "." + FString::FromInt(GetVersionAGPTiny()) + "." + FString::FromInt(GetVersionAGPSubTiny());
		}
		Canvas.TextSize(_sVersionInfo, XL, YL);
		Canvas.SetPos(((float(Canvas.SizeX) - XL) - (float(10) * (float(Canvas.SizeX) / 800))), (10 / 2));
		Canvas.DrawText(_sVersionInfo);
	}
	if (bShowLogo)
	{
	}
	*/
}

void AAGP_HUD::DrawAngleEditor(UCanvas* C)
{
	int32 OffsetX = 0;
	int32 OffsetY = 0;
	OffsetY = 310;
	OffsetX = -300;
	/*
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
	Canvas.DrawText("How to use:");
	OffsetY = 320;
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
	Canvas.DrawText("P = change pitch");
	OffsetY = 330;
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
	Canvas.DrawText("C = change yaw");
	OffsetY = 340;
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
	Canvas.DrawText("R = change roll");
	OffsetY = 350;
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
	Canvas.DrawText("J = next bone");
	OffsetY = 360;
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
	Canvas.DrawText("Space = change direction");
	Canvas.SetDrawColor(95, 255, 95, 255);
	OffsetY = 420;
	OffsetX = -300;
	if ((Cast<AAGP_Pawn>(PawnOwner).boneaxis >= 0) && (Cast<AAGP_Pawn>(PawnOwner).boneaxis <= 2))
	{
		Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
		Canvas.DrawText("--- Changing Body Set ---");
	}
	OffsetX = -50;
	if ((Cast<AAGP_Pawn>(PawnOwner).boneaxis >= 3) && (Cast<AAGP_Pawn>(PawnOwner).boneaxis <= 5))
	{
		Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
		Canvas.DrawText("--- Changing Right Arm Set ---");
	}
	OffsetX = 200;
	if (Cast<AAGP_Pawn>(PawnOwner).boneaxis >= 6)
	{
		Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
		Canvas.DrawText("--- Changing Left Arm Set ---");
	}
	Canvas.SetDrawColor(255, 255, 255, 255);
	if (Cast<AAGP_Pawn>(PawnOwner).boneaxis == 0)
	{
		OffsetY = 438;
		OffsetX = -210;
		Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
		Canvas.DrawText(">");
		OffsetY = (438 + 15);
		OffsetX = -210;
		Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
		Canvas.DrawText(">");
		OffsetY = (438 + 30);
		OffsetX = -210;
		Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
		Canvas.DrawText(">");
	}
	else
	{
		if (Cast<AAGP_Pawn>(PawnOwner).boneaxis == 1)
		{
			OffsetY = (438 + 45);
			OffsetX = -210;
			Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
			Canvas.DrawText(">");
			OffsetY = (438 + 60);
			OffsetX = -210;
			Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
			Canvas.DrawText(">");
			OffsetY = (438 + 75);
			OffsetX = -210;
			Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
			Canvas.DrawText(">");
		}
		else
		{
			if (Cast<AAGP_Pawn>(PawnOwner).boneaxis == 2)
			{
				OffsetY = (438 + 90);
				OffsetX = -210;
				Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
				Canvas.DrawText(">");
				OffsetY = (438 + 105);
				OffsetX = -210;
				Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
				Canvas.DrawText(">");
				OffsetY = (438 + 120);
				OffsetX = -210;
				Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
				Canvas.DrawText(">");
			}
			else
			{
				if (Cast<AAGP_Pawn>(PawnOwner).boneaxis == 3)
				{
					OffsetY = 438;
					OffsetX = 40;
					Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
					Canvas.DrawText(">");
					OffsetY = (438 + 15);
					OffsetX = 40;
					Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
					Canvas.DrawText(">");
					OffsetY = (438 + 30);
					OffsetX = 40;
					Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
					Canvas.DrawText(">");
				}
				else
				{
					if (Cast<AAGP_Pawn>(PawnOwner).boneaxis == 4)
					{
						OffsetY = (438 + 45);
						OffsetX = 40;
						Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
						Canvas.DrawText(">");
						OffsetY = (438 + 60);
						OffsetX = 40;
						Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
						Canvas.DrawText(">");
						OffsetY = (438 + 75);
						OffsetX = 40;
						Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
						Canvas.DrawText(">");
					}
					else
					{
						if (Cast<AAGP_Pawn>(PawnOwner).boneaxis == 5)
						{
							OffsetY = (438 + 90);
							OffsetX = 40;
							Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
							Canvas.DrawText(">");
							OffsetY = (438 + 105);
							OffsetX = 40;
							Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
							Canvas.DrawText(">");
							OffsetY = (438 + 120);
							OffsetX = 40;
							Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
							Canvas.DrawText(">");
						}
						else
						{
							if (Cast<AAGP_Pawn>(PawnOwner).boneaxis == 6)
							{
								OffsetY = 438;
								OffsetX = 90;
								Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
								Canvas.DrawText(">");
								OffsetY = (438 + 15);
								OffsetX = 90;
								Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
								Canvas.DrawText(">");
								OffsetY = (438 + 30);
								OffsetX = 90;
								Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
								Canvas.DrawText(">");
							}
							else
							{
								if (Cast<AAGP_Pawn>(PawnOwner).boneaxis == 7)
								{
									OffsetY = (438 + 45);
									OffsetX = 90;
									Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
									Canvas.DrawText(">");
									OffsetY = (438 + 60);
									OffsetX = 90;
									Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
									Canvas.DrawText(">");
									OffsetY = (438 + 75);
									OffsetX = 90;
									Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
									Canvas.DrawText(">");
								}
								else
								{
									OffsetY = (438 + 90);
									OffsetX = 90;
									Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
									Canvas.DrawText(">");
									OffsetY = (438 + 105);
									OffsetX = 90;
									Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
									Canvas.DrawText(">");
									OffsetY = (438 + 120);
									OffsetX = 90;
									Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), float(OffsetY));
									Canvas.DrawText(">");
								}
							}
						}
					}
				}
			}
		}
	}
	OffsetY = 438;
	OffsetX = -200;
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (0 + float(OffsetY)));
	Canvas.DrawText("Pitch Spine01 = ");
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (15 + float(OffsetY)));
	Canvas.DrawText("Yaw   Spine01 = ");
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (30 + float(OffsetY)));
	Canvas.DrawText("Roll  Spine01 = ");
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (45 + float(OffsetY)));
	Canvas.DrawText("Pitch Spine02    = ");
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (60 + float(OffsetY)));
	Canvas.DrawText("Yaw   Spine02    = ");
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (75 + float(OffsetY)));
	Canvas.DrawText("Roll  Spine02    = ");
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (90 + float(OffsetY)));
	Canvas.DrawText("Pitch Head    = ");
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (105 + float(OffsetY)));
	Canvas.DrawText("Yaw   Head    = ");
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (120 + float(OffsetY)));
	Canvas.DrawText("Roll  Head    = ");
	OffsetX = 50;
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (0 + float(OffsetY)));
	Canvas.DrawText("Pitch RArmUp  = ");
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (15 + float(OffsetY)));
	Canvas.DrawText("Yaw   RArmUp  = ");
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (30 + float(OffsetY)));
	Canvas.DrawText("Roll  RArmUp  = ");
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (45 + float(OffsetY)));
	Canvas.DrawText("Pitch RArmLow = ");
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (60 + float(OffsetY)));
	Canvas.DrawText("Yaw   RArmLow = ");
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (75 + float(OffsetY)));
	Canvas.DrawText("Roll  RArmLow = ");
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (90 + float(OffsetY)));
	Canvas.DrawText("Pitch RHand   = ");
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (105 + float(OffsetY)));
	Canvas.DrawText("Yaw   RHand   = ");
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (120 + float(OffsetY)));
	Canvas.DrawText("Roll  RHand   = ");
	OffsetX = 300;
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (0 + float(OffsetY)));
	Canvas.DrawText("Pitch LArmUp  = ");
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (15 + float(OffsetY)));
	Canvas.DrawText("Yaw   RArmUp  = ");
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (30 + float(OffsetY)));
	Canvas.DrawText("Roll  LArmUp  = ");
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (45 + float(OffsetY)));
	Canvas.DrawText("Pitch LArmLow = ");
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (60 + float(OffsetY)));
	Canvas.DrawText("Yaw   LArmLow = ");
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (75 + float(OffsetY)));
	Canvas.DrawText("Roll  LArmLow = ");
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (90 + float(OffsetY)));
	Canvas.DrawText("Pitch LHand   = ");
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (105 + float(OffsetY)));
	Canvas.DrawText("Yaw   LHand   = ");
	Canvas.SetPos(float((((Canvas.SizeX / 2) - 150) + OffsetX)), (120 + float(OffsetY)));
	Canvas.DrawText("Roll  LHand   = ");
	Canvas.SetDrawColor(200, 200, 255, 255);
	OffsetX = -200;
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (0 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s1boneangle1P));
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (15 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s1boneangle1Y));
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (30 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s1boneangle1R));
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (45 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s1boneangle2P));
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (60 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s1boneangle2Y));
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (75 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s1boneangle2R));
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (90 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s1boneangle3P));
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (105 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s1boneangle3Y));
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (120 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s1boneangle3R));
	OffsetX = 50;
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (0 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s2boneangle1P));
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (15 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s2boneangle1Y));
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (30 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s2boneangle1R));
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (45 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s2boneangle2P));
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (60 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s2boneangle2Y));
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (75 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s2boneangle2R));
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (90 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s2boneangle3P));
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (105 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s2boneangle3Y));
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (120 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s2boneangle3R));
	OffsetX = 300;
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (0 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s3boneangle1P));
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (15 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s3boneangle1Y));
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (30 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s3boneangle1R));
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (45 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s3boneangle2P));
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (60 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s3boneangle2Y));
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (75 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s3boneangle2R));
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (90 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s3boneangle3P));
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (105 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s3boneangle3Y));
	Canvas.SetPos(float(((Canvas.SizeX / 2) + OffsetX)), (120 + float(OffsetY)));
	Canvas.DrawText(string(Cast<AAGP_Pawn>(PawnOwner).s3boneangle3R));
	*/
}

void AAGP_HUD::HideHUD()
{
	bHideHUD = true;
}

void AAGP_HUD::ShowHud()
{
	bHideHUD = false;
}

void AAGP_HUD::PostBeginPlay()
{
	int32 i = 0;
	/*
	Super::PostBeginPlay();
	SetTimer(1, true);
	PlayerOwner = Cast<APlayerController>(Owner);
	SmallFont = Font(DynamicLoadObject("T_AA2_Fonts.Arial8", Class'Font'));
	MedFont = Font(DynamicLoadObject("T_AA2_Fonts.Arial10", Class'Font'));
	BigFont = MedFont;
	LargeFont = MedFont;
	ProgressFontFont = MedFont;
	for (i = 0; i < 9; i++)
	{
		FontArrayFonts[i] = MedFont;
	}
	DetermineVersionLabel(false, false, false, false, false, false, false, false, false, false, false);
	if (GetWorld()->GetNetMode() != NM_DedicatedServer)
	{
		Log("AGP_HUD::PostBeginPlay() - Creating HUD framework");
		CreateFrame();
	}
	PMessage = Level.PMessage;
	*/
}

void AAGP_HUD::HUDSetup(UCanvas* C)
{
	oldclipx = Canvas->ClipX;
	PawnOwner = Cast<AAGP_Pawn>(GetOwningPawn());
	//C.Reset();
	//C.SpaceX = 0
}

void AAGP_HUD::PlayStartupMessage(uint8 Stage)
{
	//ScreenPrint("AGP_HUD::PlayStartupMessage()	" + FString::FromInt(Stage));
}

float AAGP_HUD::GetConsoleMessageOffsetX(UCanvas* C)
{
	return (4 + (float(35) * (float(Canvas->SizeX) / 800)));
}

void AAGP_HUD::DisplayMOTD()
{
	/*
	LastMOTDDisplaySeconds = PlayerOwner.GameReplicationInfo.MOTDDisplaySeconds;
	PlayerOwner.SetProgressTime(float(LastMOTDDisplaySeconds));
	*/
}

void AAGP_HUD::DrawHUD()
{
	FString myLocation;
	uint8 myPriority;
	FString myMapName;
	FString myHealth;
	float textWidth = 0;
	float textHeight = 0;
	int32 padding = 30;
	int32 myRow = 0;
	TArray<AActor*> TheActors;
	Super::DrawHUD();

	// Draw very simple crosshair
	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition((Center.X - (CrosshairTex->GetSurfaceWidth() * 0.5)), (Center.Y - (CrosshairTex->GetSurfaceHeight() * 0.5f)));
	// draw the crosshair
	FCanvasTileItem TileItem(CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::Yellow);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(TileItem);


	//DrawArmyBox(Canvas, 0, 0, 16, 16);

	AAGP_Pawn* myPawn = Cast<AAGP_Pawn>(GetOwningPawn());
	//Draw Server Type
	myRow = 0;
	DetermineVersionLabel(false, true, false, false, false, false, false, false, false, false, false);
	GetTextSize(_sVersionInfo, textWidth, textHeight, UE4Font);
	DrawText(
		_sVersionInfo,
		FLinearColor(1, 1, 1, 1),
		(Canvas->ClipX - (textWidth * 2) - padding),					//Width   (X)
		(myRow * textHeight * 2) + padding,								//Height  (Y)
		UE4Font,
		DefaultFontScale * 2,
		false		//scale position of message with HUD scale
	);

	HUDSetup(Canvas);

	//Draw Map Name
	myRow += 1;
	myMapName = Cast<AAA2_WorldSettings>(GetWorld()->GetWorldSettings())->Title;
	if (myMapName != "")
	{
		GetTextSize(myMapName, textWidth, textHeight, UE4Font);
		DrawText(
			myMapName,
			FLinearColor(0, 1, 0, 1),
			(Canvas->ClipX - (textWidth * 2) - padding),					//Width   (X)
			(myRow * textHeight * 2) + padding,							//Height  (Y)
			UE4Font,
			DefaultFontScale * 2,
			false		//scale position of message with HUD scale
		);
	}

	//Draw Location
	myRow += 1;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAA2_CommVolume::StaticClass(), TheActors);
	myLocation = "Unknown";
	myPriority = 0;
	APlayerController* myController = GetOwningPlayerController();

	for (auto& currentActor : TheActors)
	{
		if (currentActor->IsA(AAA2_CommVolume::StaticClass()))
		{
			TArray<AActor*> HumansInZone;
			Cast<AAA2_CommVolume>(currentActor)->GetOverlappingActors(HumansInZone, TSubclassOf<AAGP_Pawn>());
			for (int32 i = 0; i < HumansInZone.Num(); i++)
			{
				if (HumansInZone[i] == myPawn)
				{
					if (Cast<AAA2_CommVolume>(currentActor)->Priority >= myPriority)
					{
						myLocation = Cast<AAA2_CommVolume>(currentActor)->Location;
						myPriority = Cast<AAA2_CommVolume>(currentActor)->Priority;
					}
				}
			}
		}
	}

	GetTextSize(myLocation, textWidth, textHeight, UE4Font);
	DrawText(
		myLocation,
		FLinearColor(0, 1, 0, 1),
		(Canvas->ClipX - (textWidth * 2) - padding),									//Width   (X)
		(myRow * textHeight * 2) + padding,													//Height  (Y)
		UE4Font,
		DefaultFontScale * 2,
		false		//scale position of message with HUD scale
	);
	myRow += 1;

	if (GetWorld())
	{
		if (myPawn)
		{
			myHealth = "Health: " + myPawn->GetHealthString();
			GetTextSize(myHealth, textWidth, textHeight, UE4Font);
			DrawText(
				myHealth,
				FLinearColor(0, 1, 0, 1),
				(Canvas->ClipX - (textWidth * 2) - padding),							//Width   (X)
				(myRow * textHeight * 2) + padding,										//Height  (Y)
				UE4Font,
				DefaultFontScale * 2,
				false		//scale position of message with HUD scale
			);
			myRow += 1;

			APlayerState* PS = myPawn->GetPlayerState();
			if (PS)
			{
				int32 NumberFrags = 0;
				int32 NumberSmokes = 0;
				int32 NumberFlashes = 0;
				FString MyFrags = "";
				FString MySmokes = "";
				FString MyFlashes = "";
				TArray<TSubclassOf<AInventory>> Local_Inventory = Cast<AAA2_PlayerState>(PS)->My_Pawn_Inventory;

				for (TSubclassOf<AInventory> ThisInv : Local_Inventory)
				{
					if (ThisInv->IsChildOf(AThrow_M67_Frag::StaticClass()))
					{
						NumberFrags += 1;
					}
					if (ThisInv->IsChildOf(AThrow_M83_Smoke::StaticClass()))
					{
						NumberSmokes += 1;
					}
					if (ThisInv->IsChildOf(AThrow_M84_Stun::StaticClass()))
					{
						NumberFlashes += 1;
					}
				}

				MyFrags = "Frags: " + FString::FromInt(NumberFrags);
				MySmokes = "Smokes: " + FString::FromInt(NumberSmokes);
				MyFlashes = "Flashes: " + FString::FromInt(NumberFlashes);

				GetTextSize(MyFrags, textWidth, textHeight, UE4Font);
				DrawText(
					MyFrags,
					FLinearColor(0, 1, 0, 1),
					(Canvas->ClipX - (textWidth * 2) - padding),							//Width   (X)
					(myRow * textHeight * 2) + padding,										//Height  (Y)
					UE4Font,
					DefaultFontScale * 2,
					false		//scale position of message with HUD scale
				);
				myRow += 1;

				GetTextSize(MySmokes, textWidth, textHeight, UE4Font);
				DrawText(
					MySmokes,
					FLinearColor(0, 1, 0, 1),
					(Canvas->ClipX - (textWidth * 2) - padding),							//Width   (X)
					(myRow * textHeight * 2) + padding,										//Height  (Y)
					UE4Font,
					DefaultFontScale * 2,
					false		//scale position of message with HUD scale
				);
				myRow += 1;

				GetTextSize(MyFlashes, textWidth, textHeight, UE4Font);
				DrawText(
					MyFlashes,
					FLinearColor(0, 1, 0, 1),
					(Canvas->ClipX - (textWidth * 2) - padding),							//Width   (X)
					(myRow * textHeight * 2) + padding,										//Height  (Y)
					UE4Font,
					DefaultFontScale * 2,
					false		//scale position of message with HUD scale
				);
				myRow += 1;
			}
			AAA2_GameState* GS = Cast<AAA2_GameState>(GetWorld()->GetGameState());
			/*
			if (GS != nullptr)
			{
				TArray<APlayerState *> player_array = GS->PlayerArray;
				for (int32 b = 0; b < player_array.Num(); b++)
				{
					AAA2_PlayerState* ThePlayerState = Cast<AAA2_PlayerState>(player_array[b]);
					FColor drawColor = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f).ToFColor(true);
					FVector OutSpawnPosition = FVector(0, 0, 100);

					FString theText = "Name: ";
					if (ThePlayerState->GetPawn() != nullptr)
					{
						theText = theText.Append(ThePlayerState->GetPawn()->GetName());
					}
					else
					{
						theText = theText.Append("None");
					}
					theText = theText.Append("\n Ping: ");
					theText = theText.Append(FString::FromInt(ThePlayerState->GetPing()));
					theText = theText.Append("\n State: ");
					theText = theText.Append(ThePlayerState->MyState);
					theText = theText.Append("\n TeamID: ");
					theText = theText.Append(FString::FromInt(ThePlayerState->TeamID));
					theText = theText.Append("\n SpawnClass: ");
					theText = theText.Append(ThePlayerState->SpawnClass->GetName());
					theText = theText.Append("\n WeaponClass: ");
					if (ThePlayerState->CurrentWeapon != nullptr)
					{
						theText = theText.Append(ThePlayerState->CurrentWeapon->GetName());
					}
					else
					{
						theText = theText.Append("None");
					}

					if (ThePlayerState->GetPawn() != nullptr)
					{
						theText = theText.Append("\n Pawnb:bIsProne: ");
						theText = theText.Append(Cast<AAGP_Pawn>(ThePlayerState->GetPawn())->bIsProne ? "True" : "False");
						theText = theText.Append("\n Pawnb:bIsCrouched: ");
						theText = theText.Append(Cast<AAGP_Pawn>(ThePlayerState->GetPawn())->bIsCrouched2 ? "True" : "False");
					}
					theText = theText.Append("\n bVIPPS: ");
					theText = theText.Append(FString::FromInt(ThePlayerState->bVIPPS));
					theText = theText.Append("\n bSpecialForcesPS: ");
					theText = theText.Append(FString::FromInt(ThePlayerState->bSpecialForcesPS));
					theText = theText.Append("\n bGuerrillaPS: ");
					theText = theText.Append(FString::FromInt(ThePlayerState->bGuerrillaPS));

					if (ThePlayerState->GetPawn() != nullptr)
					{
						DrawDebugString(GetWorld(), OutSpawnPosition, theText, (ThePlayerState->GetPawn()), drawColor, 0.0f, true);
					}
				}
			}
			*/
		}
	}



	//Here is the Real One    //ELIZ
	/*
	float XL = 0;
	float YL = 0;
	FString Message = "";
	FString message2 = "";
	FColor OldColor = FColor(0,0,0,0);
	AActor* ViewTargetActor = nullptr;
	HUDSetup(Canvas);
	if (_cHUDFrame != nullptr)
	{
		Canvas.Font=_cHUDFrame.GetProperSizeFont(Canvas);
	}
	else
	{
		UseSmallFont(Canvas);
	}
	if (bFirstTime)
	{
		iDesiredXRes=Canvas.SizeX;
		iDesiredYRes=Canvas.SizeY;
		SetCrosshair(Cast<AHumanController>(PlayerOwner).HUDCrosshair);
		bFirstTime=false;
	}
	if (DrawPMessage(Canvas))
	{
		return;
	}
	if (bHideHUD || (Level.sLevelName ~= "entry"))
	{
		return;
	}
	if (PlayerOwner != nullptr)
	{
		if (bUsingCustomHUDColor)
		{
			SetHUDColor(CustomHUDColor);
		}
		SetAlpha(byte(CustomHUDAlpha));
	}
	Canvas.SetDrawColor(255,255,255,255);
	Canvas.SetClip(float(oldclipx),Canvas.ClipY);
	if (bShowScores)
	{
		if (ScoreBoard != nullptr)
		{
			CloseGameMenu();
			CloseMissionResults();
			ScoreBoard.OwnerHUD=Self;
			ScoreBoard.ShowScores(Canvas);
		}
	}
	if ((Cast<AHumanController>(PlayerOwner).StartupStage == 9) && (GetWorld()->GetNetMode() == NM_Client))
	{
		if (bShowSpectatorInfo)
		{
			Canvas.SetPos(0,0);
			Message="Viewing from:  ";
			ViewTargetActor=Cast<AHumanController>(PlayerOwner).ViewTarget;
			if (ViewTargetActor == nullptr)
			{
				Message=Message + "No target.";
			}
			else
			{
				if (ViewTargetActor->IsA(AVehicle::StaticClass()) && (Cast<AVehicle>(ViewTargetActor).Driver != nullptr))
				{
					if (Cast<APawn>(ViewTargetActor).PlayerReplicationInfo != nullptr)
					{
						Message=Message + Pawn(ViewTargetActor).PlayerReplicationInfo.PlayerName @ "(" @ Vehicle(ViewTargetActor).Driver.GetHealthString() @ ")";
					}
					else
					{
						if (Level.GamePlayMode == GM_MILES)
						{
							Message=Message + "\"Corpse\"";
						}
						else
						{
							Message=Message + "Corpse";
						}
					}
				}
				else
				{
					if (ViewTargetActor->IsA(APawn::StaticClass()))
					{
						if (Cast<APawn>(ViewTargetActor).PlayerReplicationInfo != nullptr)
						{
							Message=Message + Pawn(ViewTargetActor).PlayerReplicationInfo.PlayerName @ "(" @ Pawn(ViewTargetActor).GetHealthString() @ ")";
						}
						else
						{
							if (Cast<APawn>(ViewTargetActor).Health > 0)
							{
								Message=Message + ViewTargetActor.HUDText;
							}
							else
							{
								if (Level.GamePlayMode == GM_MILES)
								{
									Message=Message + "\"Corpse\"";
								}
								else
								{
									Message=Message + "Corpse";
								}
							}
						}
					}
					else
					{
						if (ViewTargetActor->IsA(APlayerController::StaticClass()))
						{
							if (Cast<APlayerController>(ViewTargetActor).PlayerReplicationInfo != nullptr)
							{
								Message=Message + PlayerController(ViewTargetActor).PlayerReplicationInfo.PlayerName;
							}
							else
							{
								if (Level.GamePlayMode == GM_MILES)
								{
									Message=Message + "\"Corpse\"";
								}
								else
								{
									Message=Message + "Corpse";
								}
							}
						}
						else
						{
							if (ViewTargetActor->IsA(AAGP_Viewpoint::StaticClass()))
							{
								Message=Message + AGP_Viewpoint(ViewTargetActor).Description;
							}
						}
					}
				}
			}
			message2="Spectate mode:  ";
			switch(PlayerOwner.ViewPreference)
			{
				case 0:
				message2=message2 + "Players and Viewpoints";
				break;
				case 1:
				message2=message2 + "Players Only";
				if (Cast<AHumanController>(PlayerOwner).IsSpectatePlayersOnly())
				{
					message2=message2 + " (Server Enforced)";
				}
				break;
				case 3:
				message2=message2 + "Bodies Only";
				break;
				case 2:
				default:
				message2=message2 + "Scenic Viewpoints";
				break;
			}
			Canvas.SetDrawColor(255,255,255,255);
			Canvas.TextSize(Message,XL,YL);
			Canvas.SetPos(((float(Canvas.SizeX) - (float(10) * (float(Canvas.SizeX) / 800))) - XL),(25 * (float(Canvas.SizeY) / 600)));
			Canvas.DrawText(Message);
			Canvas.TextSize(message2,XL,YL);
			Canvas.SetPos(((float(Canvas.SizeX) - (float(10) * (float(Canvas.SizeX) / 800))) - XL),((25 * (float(Canvas.SizeY) / 600)) + YL));
			Canvas.DrawText(message2);
			fSpectateTextOffset=((25 * (float(Canvas.SizeY) / 600)) + (YL * 2));
		}
		else
		{
			fSpectateTextOffset=0;
		}
		switch(Cast<AHumanController>(PlayerOwner).bIdleWarning)
		{
			case 1:
			DisplayCenteredMessage(0.1,"IDLE WARNING","If you are Idle for 1 more round, you will be auto-kicked");
			break;
			case 2:
			DisplayCenteredMessage(0.1,"IDLE WARNING","Press FIRE to avoid being auto-kicked");
			break;
			default:
		}
	}
	else
	{
		fSpectateTextOffset=0;
	}
	Canvas.Style = ERenderStyle.STY_Normal;
	if ((PlayerOwner.GameReplicationInfo != nullptr) && (LastMOTDDisplaySeconds != PlayerOwner.GameReplicationInfo.MOTDDisplaySeconds))
	{
		DisplayMOTD();
	}
	OldColor=Canvas.DrawColor;
	Canvas.SetDrawColor(255,255,255,255);
	if (((! bShowGameMenu) && (! bShowMainMenu)) && (! bShowMissionResults))
	{
		if (bShowHUD)
		{
			if (_cHUDFrame != nullptr)
			{
				Canvas.bNoNightVision=true;
				if (PlayerOwner.IsInState("BaseSpectating"))
				{
					if (bShowObjectives)
					{
						Canvas.DrawColor=HUDColor;
						Canvas.Style = ERenderStyle.STY_Alpha;
						SetHUDActor();
						UIHUDCompass(_cHUDFrame.GetControl(5)).DrawObjectiveList(Canvas);
						FreeHUDActor();
					}
				}
				else
				{
					if (PlayerOwner.IsInState("Manning_Turret"))
					{
						Canvas.DrawColor=HUDColor;
						SetHUDActor();
						UIHUDPercentageBar(GetHUDControl(22)).Draw(Canvas);
						UIHUDPercentageBar(GetHUDControl(20)).Draw(Canvas);
						FreeHUDActor();
					}
					else
					{
						if ((((((PlayerOwner.Pawn != nullptr) && (! PlayerOwner.IsInState("GameEnded"))) && (! PlayerOwner.Pawn.IsInState("Dying"))) && (! PlayerOwner.IsInState("Dead"))) && (! PlayerOwner.IsInState("RoundEnded"))) && (! PlayerOwner.IsInState("PlayerWaiting")))
						{
							Canvas.SetDrawColor(255,255,255,255);
							if (((Canvas != nullptr) && (_cHUDFrame != nullptr)) && (_cHUDFrame.cHUD != nullptr))
							{
								_cHUDFrame.Draw(Canvas);
							}
						}
					}
				}
				Canvas.bNoNightVision=false;
			}
		}
		if (((LongMessage != "") || (_sCMessage[0] != "")) || (_sCMessage[1] != ""))
		{
			if (Level.TimeSeconds < (_fCMessageTimeout + 2))
			{
				DrawCenteredMessages(Canvas);
			}
			else
			{
				if (Level.TimeSeconds < (LongMessageTimeout + 2))
				{
					DrawCenteredLongMessage(Canvas);
				}
			}
		}
	}
	DrawMenu(Canvas);
	Canvas.DrawColor=OldColor;
	*/
}

int32 AAGP_HUD::GetMessagePromptPosition()
{
	if (bPortalDebugView)
	{
		if (bShowDebugInfo)
		{
			return 305;
		}
		else
		{
			return 260;
		}
	}
	else
	{
		return 1;
	}
}

int32 AAGP_HUD::GetMessagePosition()
{
	if (bPortalDebugView)
	{
		if (bShowDebugInfo)
		{
			return 320;
		}
		else
		{
			return 275;
		}
	}
	else
	{
		return 18;
	}
}

void AAGP_HUD::LocalizedMessage(ULocalMessage* Message, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString CriticalString)
{
	UUIHUDPercentageBar* PBar = nullptr;
	/*
	if (!Message.Default.bIsSpecial)
	{
		SetHUDActor();
		if (ClassIsChildOf(Message, AObjLocalMessage::StaticClass()))
		{
			PBar = UIHUDPercentageBar(GetHUDControl(20));
		}
		else
		{
			if (ClassIsChildOf(Message, AHealLocalMessage::StaticClass()))
			{
				PBar = UIHUDPercentageBar(GetHUDControl(21));
			}
			else
			{
				if (ClassIsChildOf(Message, ATurretLocalMessage::StaticClass()))
				{
					PBar = UIHUDPercentageBar(GetHUDControl(22));
				}
				else
				{
					if (ClassIsChildOf(Message, AObjectiveGiveLocalMessage::StaticClass()))
					{
						PBar = UIHUDPercentageBar(GetHUDControl(23));
					}
				}
			}
		}
		if (PBar != nullptr)
		{
			PBar.SetEndTime((GetWorld()->GetTimeSeconds() + float(Message.Default.Lifetime)));
			PBar.SetFillPercentage(float(Switch));
		}
		FreeHUDActor();
	}
	*/
}

void AAGP_HUD::DrawTypingPrompt(UCanvas* C, FString Text, int32 pos)
{
	UFont* oldfont = nullptr;
	/*
	oldfont = Canvas.Font;
	UseSmallFont(Canvas);
	Canvas->DrawColor = MessagePromptColor;
	Canvas->DrawColor.A = 255;  // always need to see this for safety's sake, so force alpha 255
	Canvas.SetPos(4, GetMessagePromptPosition() * Canvas->SizeX / 600);

	// agp [edc] MERGE3236: Changed this to reflect changes in HUD.uc and draw the cursor position correctly
	Canvas.DrawTextClipped("(>"@Left(Text, Pos) + chr(4) + Eval(Pos < Len(Text), Mid(Text, Pos), "_"), true);
	Canvas.Font = oldfont;
	*/
}
float AAGP_HUD::GetTextHeight(UCanvas* C)
{
	float XL = 0;
	float YL = 0;
	//Canvas.StrLen("TEST0", XL, YL);
	return YL;
}

float AAGP_HUD::GetTextWidth(UCanvas* C)
{
	float XL = 0;
	float YL = 0;
	//Canvas.StrLen("XXXX", XL, YL);
	return (XL / 4);
}

void AAGP_HUD::ReWrapMessages(UConsole* MyConsole, UCanvas* MyCanvas)
{
	/*
	int32 i = 0;
	if (LastSizeX == Canvas->SizeX)
	{
		return;
	}
	for (i = 0; i < 64; i++)
	{
	//	MyConsole.MsgText[i] = MyConsole.WrapMessage(MyConsole.MsgText[i]);
	}
	LastSizeX = Canvas->SizeX;
	*/
}
void AAGP_HUD::DisplayMessages(UCanvas* Ca)
{
	int32 i = 0;
	int32 j = 0;
	int32 YPos = 0;
	int32 NLn = 0;
	int32 ii = 0;
	float XL = 0;
	float YL = 0;
	UConsole* C = nullptr;
	int32 textheight = 0;
	int32 localoldclipx = 0;
	int32 boxstart = 0;
	 TArray<FString> WrappedLines ={};
	bool bShowingMessages = false;
	bool bRecalcMessagePositions = false;
	if (!bShowHUD)
	{
		return;
	}
	/*
	if (((((PlayerOwner == nullptr) || (PlayerOwner.Player == nullptr)) || (PlayerOwner.Player.Console == nullptr)) || (PlayerConsole == nullptr)) || (Canvas == nullptr))
	{
		return;
	}
	SetHUDActor();
	bShowingMessages = HUDCommoInfo(GetHUDControl(13)).ShowingMessages();
	FreeHUDActor();
	if (bShowingMessages)
	{
		return;
	}
	UseSmallFont(Canvas);
	textheight = int(GetTextHeight(Canvas));
	NLn = (int(((float(Canvas.SizeY) - (float(240) * _cHUDFrame.fScaleY)) + 4)) / textheight);
	if ((!PlayerConsole.bTyping) || PlayerConsole.bTypeOnly)
	{
		NLn = 4;
	}
	else
	{
		NLn = 31;
	}
	C = PlayerConsole;
	C.CanvasSizeX = float(Canvas.SizeX);
	if ((Level.TimeSeconds - fpTimeSinceMessagesRebuilt) > 0.25)
	{
		j = C.TopLine;
		i = 0;
		fpTimeSinceMessagesRebuilt = Level.TimeSeconds;
		bRecalcMessagePositions = true;
		ReWrapMessages(C, Canvas);
		if (i < NLn)
		{
			if (PlayerConsole.bTyping)
			{
				if (C.MsgText[j] == "")
				{
					ShortMessages[i++] = "";
				}
				else
				{
					Split(C.MsgText[j], "|", WrappedLines);
					ii = 0;
					if ((i < NLn) && (ii < WrappedLines.Length))
					{
						ShortMessages[i] = WrappedLines[ii];
						ShortColor[i] = C.GetTextColor(j);
						i++;
						(++ii);
					}
				}
			}
			else
			{
				if (C.MessageIsCurrent(j))
				{
					if (C.MsgText[j] == "")
					{
						ShortMessages[i++] = "";
					}
					else
					{
						Split(C.MsgText[j], "|", WrappedLines);
						ii = 0;
						if ((i < NLn) && (ii < WrappedLines.Length))
						{
							ShortMessages[i] = WrappedLines[ii];
							ShortColor[i] = C.GetTextColor(j);
							i++;
							(++ii);
						}
					}
				}
				else
				{
					ShortMessages[i++] = "";
				}
			}
			j--;
			if (j < 0)
			{
				j = 63;
			}
		}
	}
	localoldclipx = int(Canvas.ClipX);
	Canvas.ClipX = (float(Canvas.SizeX) * 0.75);
	YPos = int((float(GetMessagePosition()) * _cHUDFrame.fScaleY));
	boxstart = YPos;
	i = 0;
	if (i < NLn)
	{
		if (ShortMessages[i] != "")
		{
			if (bRecalcMessagePositions)
			{
				Canvas.StrLen(ShortMessages[i], XL, afpShortMessageLengthYL[i]);
			}
			YL = afpShortMessageLengthYL[i];
			if (YPos < ((boxstart + (textheight * NLn)) - 4))
			{
				if (((ShortColor[i].R == 0) && (ShortColor[i].G == 0)) && (ShortColor[i].B == 0))
				{
					ShortColor[i] = HUDColor;
				}
				Canvas.DrawColor = ShortColor[i];
				if (ShortColor[i].A < 130)
				{
					Canvas.DrawColor.A = 130;
				}
				Canvas.SetPos(GetConsoleMessageOffsetX(Canvas), float(YPos));
				Canvas.DrawTextClipped(ShortMessages[i], false);
				(YPos += int(YL));
			}
			else
			{
			}
		}
		else
		{
			i++;
		}
	}
	Canvas.ClipX = float(localoldclipx);
	*/
}

void AAGP_HUD::SetCrosshair(int32 C)
{
	SetHUDActor();
	Cast<UHUDCrosshair>(GetHUDControl(10))->SetCrosshair(C);
	FreeHUDActor();
}

void AAGP_HUD::NextCrosshair()
{
	SetHUDActor();
	Cast<UHUDCrosshair>(GetHUDControl(10))->NextCrosshair();
	FreeHUDActor();
}

void AAGP_HUD::SetHue(uint8 H)
{
	float Brightness = 0;
	FVector HueV = FVector(0, 0, 0);
	FVector oneV = FVector(0, 0, 0);
	FVector RGBV = FVector(0, 0, 0);
	if (H < 0)
	{
		H = 0;
	}
	if (H > 255)
	{
		H = 255;
	}
	iPrevHUDColor = H;
	oneV.X = 1;
	oneV.Y = 1;
	oneV.Z = 1;
	Brightness = 1.4 / 255;
	Brightness *= 0.7 / 0.01 + FMath::Sqrt(Brightness);
	Brightness = FMath::Clamp(Brightness, 0.0f, 1.0f);
	if (H < 86)
	{
		HueV.X = 85 - H / 85;
		HueV.Y = H - 0 / 85;
		HueV.Z = 0;
	}
	else
	{
		if (H < 171)
		{
			HueV.X = 0;
			HueV.Y = 170 - H / 85;
			HueV.Z = H - 85 / 85;
		}
		else
		{
			HueV.X = H - 170 / 85;
			HueV.Y = 0;
			HueV.Z = 255 - H / 84;
		}
	}
	RGBV = HueV + 1 / 255 * oneV - HueV * Brightness;
	RGBV *= 255;
	HUDColor.R = RGBV.X;
	HUDColor.G = RGBV.Y;
	HUDColor.B = RGBV.Z;
}

void AAGP_HUD::SetAlpha(uint8 A)
{
	if (A <= 0)
	{
		A = 1;
	}
	else
	{
		if (A > 255)
		{
			A = 255;
		}
	}
	iPrevHUDAlpha = A;
	HUDColor.A = A;
}

/* =================================================================================== *
* AGP function DrawPMessage()
*	Prints an annoying message permanently on the screen. For cheaters.
*
* input: Canvas
* last modified by: cmb
* =================================================================================== */
bool AAGP_HUD::DrawPMessage(UCanvas* C)
{
	int32 i = 0;
	int32 Lines = 0;
	TArray<FString> Line = { "","","","","","","","","","" };
	float XL = 0;
	float YL = 0;
	float YCenter = 0;
	float XCenter = 0;
	float midline = 0;
	float Xsize = 0;
	float Ysize = 0;
	/*
	switch(PMessage)
	{
			case 0:
				return false;
			default:
				Line[Lines] = "WARNING: Your game installation is corrupted or altered. Do not ";
				Lines++;
				Line[Lines] = "continue to play on Official servers with these files.";
				Lines++;
				Line[Lines] = "Run cleaner.exe from the System directory of your game installation.";
				Lines++;
				Line[Lines] = "If you continue to receive this warning, uninstall the game";
				Lines++;
				Line[Lines] = "and reinstall from the original installer.";
				Lines++;
				Line[Lines] = "Continued use of corrupted or altered files may result in your ";
				Lines++;
				Line[Lines] = "account being disabled.";
				Lines++;
				switch(PMessage)
				{
			case 2:
				Line[Lines] = "This is your second warning.";
				Lines++;
				break;
			case 3:
				Line[Lines] = "You have been warned multiple times.";
				Lines++;
				break;
			default:
				}
			}
		Canvas.Font = _cHUDFrame.Fonts[3];
		for (i = 0; i < Lines; i++)
		{
			Canvas.TextSize(Line[i], XL, YL);
			Xsize = FMax(Xsize, XL);
		}
		Ysize = Lines * YL;
		Canvas.TextSize("XXX", XL, YL);
		Xsize += XL;
		Ysize += YL;
		YCenter = Canvas.SizeY / 2;
		XCenter = Canvas.SizeX / 2;
		Canvas.SetPos(XCenter - Xsize / 2, YCenter - Ysize / 2);
		Canvas.SetDrawColor(255, 255, 255, 100);
		Canvas.DrawTile(tFill, Xsize, Ysize, 0, 0, tFill.USize, tFill.VSize);
		Canvas.SetDrawColor(225, 225, 225, 0);
		midline = Lines / 2;
		for (i = 0; i < Lines; i++)
		{
			Canvas.TextSize(Line[i], XL, YL);
			Canvas.SetPos(XCenter - XL / 2, YCenter + i - midline * YL);
			Canvas.DrawText(Line[i]);
		}
		*/
		return true;
}

// draw the centered messages, with a gel and box a la Army of One sytlin's
// capps
void AAGP_HUD::DrawCenteredMessages(UCanvas* C)
{
	UFont* oldfont = nullptr;
	float XL = 0;
	float XL2 = 0;
	float YL = 0;
	float YL2 = 0;
	float boxw = 0;
	float boxh = 0;
	float yposn = 0;
	int32 fadelvl = 0;
	float StartX = 0;
	float StartY = 0;
	if (bDisableNotificationMessages)
	{
		return;
	}
	/*
	oldfont = Canvas.Font;
	Canvas.bCenter = true;
	Canvas.Style = 6;
	Canvas.Font = _cHUDFrame.Fonts[3];
	Canvas.TextSize(_sCMessage[0], XL, YL);
	Canvas.TextSize(_sCMessage[1], XL2, YL2);
	if (FMax(XL, XL2) > Canvas.ClipX * 0.66)
	{
		Canvas.Font = _cHUDFrame.Fonts[1];
		Canvas.TextSize(_sCMessage[0], XL, YL);
		Canvas.TextSize(_sCMessage[1], XL2, YL2);
	}
	if (_fCMessageTimeout > GetWorld()->GetTimeSeconds)
	{
		fadelvl = 255;
	}
	else
	{
		fadelvl = _fCMessageTimeout + 2 - GetWorld()->GetTimeSeconds() * 255 / 2;
		if (fadelvl <= 0)
		{
			fadelvl = 1;
		}
	}
	boxw = FMax(XL, XL2) * 1.1;
	boxh = YL * 2 + YL2;
	yposn = Canvas.SizeY * 0.64;
	Canvas.SetPos(Canvas.SizeX - boxw / 2, yposn - YL / 2);
	if (fadelvl < 200)
	{
		Canvas.SetDrawColor(255, 255, 255, fadelvl / 2 + 1);
	}
	else
	{
		Canvas.SetDrawColor(255, 255, 255, 100);
	}
	Canvas.DrawTile(tFill, boxw, boxh, 0, 0, tFill.USize, tFill.VSize);
	Canvas.DrawColor = HUDColor;
	Canvas.DrawColor.A = fadelvl;
	StartX = Canvas.SizeX - boxw / 2;
	StartY = yposn - YL / 2;
	DrawArmyBox(Canvas, StartX, StartY, boxw, boxh);
	Canvas.SetDrawColor(225, 225, 225, fadelvl);
	Canvas.TextSize("test", XL, YL);
	Canvas.SetPos(0, yposn);
	Canvas.DrawText(_sCMessage[0]);
	Canvas.SetPos(0, yposn + YL);
	Canvas.DrawText(_sCMessage[1]);
	Canvas.bCenter = false;
	Canvas.Font = oldfont;
	*/
}

void AAGP_HUD::DrawCenteredLongMessage(UCanvas* C)
{
	float XL = 0;
	float YL = 0;
	float BiggestStringWidth = 0;
	float TotalMessageHeight = 0;
	float boxw = 0;
	float boxh = 0;
	float yposn = 0;
	float StartX = 0;
	float StartY = 0;
	float CurY = 0;
	UFont* oldfont = nullptr;
	TArray<FString> split_msg ={};
	int32 i = 0;
	int32 fadelvl = 0;
	bool fForceMultiLine = false;
	if (bDisableNotificationMessages)
	{
		return;
	}
	/*
	oldfont = Canvas.Font;
	Canvas.bCenter = true;
	Canvas.Style = 6;
	if (LongMessageFont != nullptr)
	{
		Canvas.Font = LongMessageFont;
	}
	else
	{
		Canvas.Font = _cHUDFrame.Fonts[3];
	}
	if (InStr(LongMessage, "|") != -1)
	{
		fForceMultiLine = true;
	}
	else
	{
		fForceMultiLine = false;
		Canvas.TextSize(LongMessage, XL, YL);
	}
	if (fForceMultiLine || XL > Canvas.ClipX * 0.66)
	{
		Canvas.WrapStringToArray(LongMessage, split_msg, Canvas.ClipX * 0.66);
		if (split_msg.Num() > 3 && LongMessageFont == nullptr)
		{
			Canvas.Font = _cHUDFrame.Fonts[1];
			Canvas.TextSize(LongMessage, XL, YL);
			if (XL > Canvas.ClipX * 0.66)
			{
				split_msg.Num() = 0;
				Canvas.WrapStringToArray(LongMessage, split_msg, Canvas.ClipX * 0.66);
			}
		}
	}
	else
	{
		split_msg.Num() = 1;
		split_msg[0] = LongMessage;
	}
	BiggestStringWidth = 0;
	TotalMessageHeight = 0;
	for (i = 0; i < split_msg.Num(); i++)
	{
		Canvas.TextSize(split_msg[i], XL, YL);
		if (XL > BiggestStringWidth)
		{
			BiggestStringWidth = XL;
		}
		TotalMessageHeight += YL;
	}
	if (LongMessageTimeout > GetWorld()->GetTimeSeconds)
	{
		fadelvl = 255;
	}
	else
	{
		fadelvl = LongMessageTimeout + 2 - GetWorld()->GetTimeSeconds() * 255 / 2;
		if (fadelvl <= 0)
		{
			fadelvl = 1;
		}
	}
	boxw = BiggestStringWidth * 1.1;
	boxh = TotalMessageHeight + YL;
	yposn = Canvas.SizeY * 0.64;
	StartX = Canvas.SizeX - boxw / 2;
	StartY = yposn - YL / 2;
	Canvas.SetPos(StartX, StartY);
	if (fadelvl < 200)
	{
		Canvas.SetDrawColor(255, 255, 255, fadelvl / 2 + 1);
	}
	else
	{
		Canvas.SetDrawColor(255, 255, 255, 100);
	}
	Canvas.DrawTile(tFill, boxw, boxh, 0, 0, tFill.USize, tFill.VSize);
	Canvas.DrawColor = HUDColor;
	Canvas.DrawColor.A = fadelvl;
	DrawArmyBox(Canvas, StartX, StartY, boxw, boxh);
	Canvas.SetDrawColor(225, 225, 225, fadelvl);
	CurY = yposn;
	for (i = 0; i < split_msg.Num(); i++)
	{
		Canvas.SetPos(0, CurY);
		Canvas.DrawText(split_msg[i]);
		Canvas.TextSize(split_msg[i], XL, YL);
		CurY += YL;
	}
	Canvas.bCenter = false;
	Canvas.Font = oldfont;
*/
}

void AAGP_HUD::DisplayCenteredMessage(float Time, FString Message, FString message2)
{
	if (bDisableNotificationMessages)
	{
		return;
	}
	if (PMessage == 0)
	{
		_sCMessage[0] = Message;
		_sCMessage[1] = message2;
		_fCMessageTimeout = (GetWorld()->GetTimeSeconds()) + Time;
	}
}

void AAGP_HUD::DisplayCenteredMessageLong(float Time, FString in_message, UFont* F)
{
	if (bDisableNotificationMessages)
	{
		return;
	}
	if (PMessage == 0)
	{
		LongMessage = in_message;
		LongMessageTimeout = GetWorld()->GetTimeSeconds() + Time;
		LongMessageFont = F;
	}
}

void AAGP_HUD::DrawArmyBox(UCanvas* C, float StartX, float StartY, float boxw, float boxh)
{
	bool bSmooth = false;
	bSmooth = false;
	if (boxw >= 0 && boxh >= 0)
	{
		bSmooth = Canvas->bNoSmooth;
		Canvas->bNoSmooth= true;

		FCanvasTileItem WhiteBox = FCanvasTileItem(FVector2D(StartX, StartY), tArmyBox->Resource, FVector2D(1, 1), FLinearColor(1.0f, 1.0f, 1.0f));
		Canvas->DrawItem(WhiteBox);




		/*
		Canvas->SetPos(StartX, StartY);
		Canvas->DrawTile(tArmyBox, 16, 16, 0, 0, 16, 16);
		Canvas->SetPos(StartX + 16, StartY);
		Canvas->DrawTile(tArmyBox, boxw - 32, 16, 16, 0, 16, 16);
		Canvas->SetPos(StartX + boxw - 16, StartY);
		Canvas->DrawTile(tArmyBox, 16, 16, 32, 0, 16, 16);
		Canvas->SetPos(StartX, StartY + 16);
		Canvas->DrawTile(tArmyBox, 16, boxh - 32, 0, 16, 16, 16);
		Canvas->SetPos(StartX + 16, StartY + 16);
		Canvas->DrawTile(tArmyBox, boxw - 32, boxh - 32, 16, 16, 16, 16);
		Canvas->SetPos(StartX + boxw - 16, StartY + 16);
		Canvas->DrawTile(tArmyBox, 16, boxh - 32, 32, 16, 16, 16);
		Canvas->SetPos(StartX, StartY + boxh - 16);
		Canvas->DrawTile(tArmyBox, 16, 16, 0, 32, 16, 16);
		Canvas->SetPos(StartX + 16, StartY + boxh - 16);
		Canvas->DrawTile(tArmyBox, boxw - 32, 16, 16, 32, 16, 16);
		Canvas->SetPos(StartX + boxw - 16, StartY + boxh - 16);
		Canvas->DrawTile(tArmyBox, 16, 16, 32, 32, 16, 16);
		*/
		Canvas->bNoSmooth = bSmooth;
	}
	
}
void AAGP_HUD::DrawArmyLine(UCanvas* C, float StartX, float StartY, float boxw)
{
	
	bool bSmooth;
	if (boxw >= 0)
	{
		bSmooth = Canvas->bNoSmooth;
		Canvas->bNoSmooth = true;
		//Canvas->SetPos(StartX, StartY);
		//Canvas->DrawTile(tArmyBox, boxw, 16, 16, 0, 16, 16);
		Canvas->bNoSmooth = bSmooth;
	}
}

void AAGP_HUD::ToggleClassSelect()
{
	/*
	PlayerOwner.ClientCloseMenu(true);
	if (gmFrame == NULL || bShowMainMenu)
	{
		return;
	}
	if (bShowGameMenu && gmFrame.GetActiveScreen().GetID() == 3)
	{
		CloseGameMenu();
		return;
	}
	gmFrame.RefreshClassSelect();
	gmFrame.SetActiveScreen(3);
	CloseAllMenus();
	OpenGameMenu();
	*/
}
void AAGP_HUD::ToggleTeamSelect()
{
	/*
	PlayerOwner.ClientCloseMenu(true);
	if (gmFrame == nullptr || bShowMainMenu)
	{
		return;
	}
	if (bShowGameMenu && gmFrame.GetActiveScreen().GetID() == 1)
	{
		CloseGameMenu();
		return;
	}
	gmFrame.RefreshClassSelect();
	gmFrame.SetActiveScreen(1);
	CloseAllMenus();
	OpenGameMenu();
	*/
}
void AAGP_HUD::ToggleServerAdmin()
{
	/*
	PlayerOwner.ClientCloseMenu(true);
	if (gmFrame == nullptr || bShowMainMenu)
	{
		return;
	}
	if (bShowGameMenu && gmFrame.GetActiveScreen().GetID() == 7)
	{
		CloseGameMenu();
		return;
	}
	gmFrame.SetActiveScreen(7);
	CloseAllMenus();
	OpenGameMenu();
	_bUIConsole = true;
	*/
}

void AAGP_HUD::OpenTeamSelect()
{
	/*
	PlayerOwner.ClientCloseMenu(true);
	if (gmFrame != nullptr)
	{
		if (bShowMainMenu)
		{
			CloseMainMenu();
		}
		gmFrame.SetActiveScreen(1);
		OpenGameMenu();
	}
	*/
}
void AAGP_HUD::OpenClassSelect()
{
	/*
	PlayerOwner.ClientCloseMenu(true);
	if (gmFrame != nullptr)
	{
		gmFrame.RefreshClassSelect();
		gmFrame.SetActiveScreen(3);
		OpenGameMenu();
	}
	*/
}

void AAGP_HUD::ToggleLogin()
{
	/*
	if (gmFrame != nullptr)
	{
		if (bShowGameMenu)
		{
			CloseGameMenu();
		}
		else
		{
			gmFrame.SetActiveScreen(4);
			CloseAllMenus();
			gmFrame.RefreshLoginScreen();
			OpenGameMenu();
		}
	}
	*/
}

void AAGP_HUD::SetLoginStatus(int32 iStatus, FString sStatus, FString sNavMsg)
{
	/*
	if (gmFrame != nullptr)
	{
		if (bShowGameMenu)
		{
			gmFrame.SetLoginStatus(iStatus, sStatus, sNavMsg);
		}
	}
	if (mmFrame != nullptr)
	{
		if (bShowMainMenu)
		{
			mmFrame.SetLoginStatus(iStatus, sStatus, sNavMsg);
		}
	}
	OnSetLoginStatus(iStatus, sStatus, sNavMsg);
	*/
}

void AAGP_HUD::OnSetLoginStatus(int32 iStatus, FString sStatus, FString sNavMsg)
{
}
void AAGP_HUD::OpenMissionSuccess(FString Texture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene, bool bCheater)
{
	/*
	if (gmFrame != NULL)
	{
		gmFrame.SetActiveScreen(5);
		CloseAllMenus();
		gmFrame.SetMissionSuccessScreen(Texture, Text, text2, USize, VSize, RenderStyle, replayscene, bCheater);
		gmFrame.RefreshLoginScreen();
		OpenGameMenu();
	}
	*/
}

void AAGP_HUD::OpenMissionFailure(FString Texture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene)
{
	/*
	if (gmFrame != nullptr)
	{
		gmFrame.SetActiveScreen(6);
		CloseAllMenus();
		gmFrame.SetMissionFailureScreen(Texture, Text, text2, USize, VSize, RenderStyle, replayscene);
		gmFrame.RefreshLoginScreen();
		OpenGameMenu();
	}
	*/
}

void AAGP_HUD::OpenLandNavScore(FString text1, FString text2, FString text3, FString text4, FString text5, FString text6, FString text7, FString text8, bool bCheater)
{
	/*
	if (gmFrame != nullptr)
	{
		gmFrame.SetActiveScreen(8);
		CloseAllMenus();
		gmFrame.SetLandNavScoreScreen(text1, text2, text3, text4, text5, text6, text7, text8, bCheater);
		gmFrame.RefreshLoginScreen();
		OpenGameMenu();
	}
	*/
}

void AAGP_HUD::RefreshTourMissionDisplays()
{
	/*
	if (mmFrame != NULL)
	{
		mmFrame.RefreshTourMissionDisplays();
	}
	*/
}

void AAGP_HUD::GameSpyTest()
{
}

int32 AAGP_HUD::GetServerBrowserAsInt()
{
	if (ServerBrowser != "gamespy" || LanServerBrowser)
	{
		return 1;
	}
	else
	{
		if (ServerBrowser != "AA Browser")
		{
			return 3;
		}
		else
		{
			return 3;
		}
	}
}

AServerBrowserBase* AAGP_HUD::GetCurrentServerBrowser(bool IsLAN)
{
	int32 iBrowser = 0;
	/*
	iBrowser = GetServerBrowserAsInt();
	if (iBrowser == 1 || IsLAN)
	{
		if (BrowserGSPY == nullptr)
		{
			BrowserGSPY = Spawn(AGameSpyServerList::StaticClass());
			BrowserGSPY.SetOwner(this);
		}
		return BrowserGSPY;
	}
	else
	{
		if (iBrowser == 2)
		{
			if (BrowserSCI == nullptr)
			{
				BrowserSCI = Spawn(AServerBrowserSCI::StaticClass());
				BrowserSCI.SetOwner(this);
			}
			return BrowserSCI;
		}
		else
		{
			if (iBrowser == 3)
			{
				if (BrowserDBMBS == nullptr)
				{
					BrowserDBMBS = Spawn(AServerBrowserDBMBS::StaticClass(), this);
				}
				return BrowserDBMBS;
			}
		}
	}
	*/
	return nullptr;
}

void AAGP_HUD::ServerBrowserUpdateList()
{
	int32 iBrowser = 0;
	/*
	iBrowser = GetServerBrowserAsInt();
	if (iBrowser == 1)
	{
		if (BrowserGSPY == nullptr)
		{
			BrowserGSPY = Spawn(AGameSpyServerList::StaticClass());
			BrowserGSPY.SetOwner(this);
		}
		BrowserGSPY.UpdateServerList();
	}
	else
	{
		if (iBrowser == 2)
		{
			if (BrowserSCI == nullptr)
			{
				BrowserSCI = Spawn(AServerBrowserSCI::StaticClass());
				BrowserSCI.SetOwner(this);
			}
			BrowserSCI.UpdateServerList();
		}
		else
		{
			if (iBrowser == 3)
			{
				if (BrowserDBMBS == nullptr)
				{
					BrowserDBMBS = Spawn(AServerBrowserDBMBS::StaticClass(), this);
				}
				BrowserDBMBS.UpdateServerList();
			}
		}
	}
	*/
}

void AAGP_HUD::ServerBrowserRefreshList()
{
	int32 iBrowser = 0;
	/*
	iBrowser = GetServerBrowserAsInt();
	if (iBrowser == 1)
	{
		if (BrowserGSPY == nullptr)
		{
			BrowserGSPY = Spawn(AGameSpyServerList::StaticClass());
			BrowserGSPY.SetOwner(this);
		}
		BrowserGSPY.RefreshServerList();
	}
	else
	{
		if (iBrowser == 2)
		{
			if (BrowserSCI == nullptr)
			{
				BrowserSCI = Spawn(AServerBrowserSCI::StaticClass());
				BrowserSCI.SetOwner(this);
			}
			BrowserSCI.RefreshServerList();
		}
		else
		{
			if (iBrowser == 3)
			{
				if (BrowserDBMBS == nullptr)
				{
					BrowserDBMBS = Spawn(AServerBrowserDBMBS::StaticClass(), this);
				}
				BrowserDBMBS.RefreshServerList();
			}
		}
	}
	*/
}
void AAGP_HUD::ConnectToGameSpyServer(int32 Index, FString sPassword, bool bSpectatorOnly)
{
	FGameSpyServerItem Item;
	FString sAddress = "";
	FString sVersion = "";
	AServerBrowserBase* sbBase = nullptr;
	int32 iBrowser = 0;
	FString sURL = "";
	/*
	iBrowser = GetServerBrowserAsInt();
	if (iBrowser == 1)
	{
		if (BrowserGSPY == nullptr)
		{
			return;
		}
		else
		{
			sbBase = BrowserGSPY;
		}
	}
	else
	{
		if (iBrowser == 2)
		{
			if (BrowserSCI == nullptr)
			{
				return;
			}
			else
			{
				sbBase = BrowserSCI;
			}
		}
	}
	if (sbBase == nullptr)
	{
		return;
	}
	sbBase.GetSpecificServer(Index, Item);
	if (Item.bValid == 0)
	{
		return;
	}
	sAddress = sbBase.IpAddrToString(Item.IP, Item.Port);
	sVersion = GetVersionAGPMajor() + "." + GetVersionAGPMinor() + "." + GetVersionAGPTiny() + "." + GetVersionAGPSubTiny();
	if (Item.GameVer != sVersion)
	{
		return;
	}
	if (GetMilesOnly() && Item.bMiles == 0)
	{
		mmFrame.MessageBox("MILES Only", 0, "", "OK");
		return;
	}
	if (Item.bPassword == 1 && sPassword == "")
	{
		mmFrame.MessageBox("Enter Password", 0, "", "OK");
		return;
	}
	sURL = sAddress;
	if (sPassword != "")
	{
		sURL += "?password=" + sPassword;
	}
	if (bSpectatorOnly)
	{
		sURL += "?SpectatorOnly=1";
	}
	PlayerOwner.ConsoleCommand("disconnect");
	CloseMainMenu();
	PlayerOwner.ConsoleCommand("start " + sURL);
	*/
}

void AAGP_HUD::ConnectToServer(int32 Index, FString sPassword, bool bSpectatorOnly)
{
	FGameSpyServerItem Item;
	FString sAddress = "";
	FString sVersion = "";
	AServerBrowserBase* sbBase = nullptr;
	int32 iBrowser = 0;
	FString sURL = "";
	/*
	iBrowser = GetServerBrowserAsInt();
	if (iBrowser == 1)
	{
		if (BrowserGSPY == nullptr)
		{
			return;
		}
		else
		{
			sbBase = BrowserGSPY;
		}
	}
	else
	{
		if (iBrowser == 2)
		{
			if (BrowserSCI == nullptr)
			{
				return;
			}
			else
			{
				sbBase = BrowserSCI;
			}
		}
	}
	if (sbBase == nullptr)
	{
		return;
	}
	sbBase.GetSpecificServer(Index, Item);
	if (Item.bValid == 0)
	{
		return;
	}
	sAddress = sbBase.IpAddrToString(Item.IP, Item.Port);
	sVersion = GetVersionAGPMajor() + "." + GetVersionAGPMinor() + "." + GetVersionAGPTiny() + "." + GetVersionAGPSubTiny();
	if (Item.GameVer != sVersion)
	{
		return;
	}
	if (GetMilesOnly() && Item.bMiles == 0)
	{
		mmFrame.MessageBox("MILES Only", 0, "", "OK");
		return;
	}
	if (Item.bPassword == 1 && sPassword == "")
	{
		mmFrame.MessageBox("Enter Password", 0, "", "OK");
		return;
	}
	sURL = sAddress;
	if (sPassword != "")
	{
		sURL += "?password=" + sPassword;
	}
	if (bSpectatorOnly)
	{
		sURL += "?SpectatorOnly=1";
	}
	PlayerOwner.ConsoleCommand("disconnect");
	CloseMainMenu();
	PlayerOwner.ConsoleCommand("start " + sURL);
	*/
}

void AAGP_HUD::SortServers(FString sField, bool bAscending, EGameSpyCompareMode eType)
{	
	int32 iBrowser = 0;
	AServerBrowserBase* sbBase = nullptr;
	/*
	iBrowser = GetServerBrowserAsInt();
	if (iBrowser == 1)
	{
		if (BrowserGSPY == nullptr)
		{
			return;
		}
		else
		{
			sbBase = BrowserGSPY;
		}
	}
	else
	{
		if (iBrowser == 2)
		{
			if (BrowserSCI == nullptr)
			{
				return;
			}
			else
			{
				sbBase = BrowserSCI;
			}
		}
	}
	if (sbBase == nullptr)
	{
		return;
	}
	if (sbBase.GetNumServers() == 0)
	{
		return;
	}
	sbBase.SortServers(sField, bAscending, eType);
	*/
}

void AAGP_HUD::RefreshSelectedServer(int32 Index)
{
	int32 iBrowser = 0;
	AServerBrowserBase* sbBase = nullptr;
	/*
	iBrowser = GetServerBrowserAsInt();
	if (iBrowser == 1)
	{
		if (BrowserGSPY == nullptr)
		{
			return;
		}
		else
		{
			sbBase = BrowserGSPY;
		}
	}
	else
	{
		if (iBrowser == 2)
		{
			if (BrowserSCI == nullptr)
			{
				return;
			}
			else
			{
				sbBase = BrowserSCI;
			}
		}
	}
	if (sbBase == nullptr)
	{
		return;
	}
	if (sbBase.GetNumServers() == 0)
	{
		return;
	}
	sbBase.RefreshSpecificServer(Index);
	*/
}

void AAGP_HUD::SetServerBrowserFilter(FString sFilter)
{
	int32 iBrowser = 0;
	iBrowser = GetServerBrowserAsInt();
	/*
	if (iBrowser == 1)
	{
		if (BrowserGSPY == nullptr)
		{
			BrowserGSPY = Spawn(AGameSpyServerList::StaticClass());
			BrowserGSPY.SetOwner(this);
		}
		BrowserGSPY.SetFilter(sFilter);
	}
	else
	{
		if (iBrowser == 2)
		{
			if (BrowserSCI == nullptr)
			{
				BrowserSCI = Spawn(AServerBrowserSCI::StaticClass());
				BrowserSCI.SetOwner(this);
			}
			BrowserSCI.SetFilter(sFilter);
		}
		else
		{
			if (iBrowser == 3)
			{
				if (BrowserDBMBS == nullptr)
				{
					BrowserDBMBS = Spawn(AServerBrowserDBMBS::StaticClass(), this);
				}
				BrowserDBMBS.SetFilter(sFilter);
			}
		}
	}
	*/
}

void AAGP_HUD::QueryServerListReply(int32 Index, FString Section, FString Setting, FString Value, int32 Type)
{
	if (gmFrame != nullptr)
	{
		gmFrame->QueryServerListReply(Index, Section, Setting, Value, Type);
	}
}

void AAGP_HUD::SetServerSettingReply(int32 Index, FString Value)
{
	if (gmFrame != nullptr)
	{
		gmFrame->SetServerSettingReply(Index, Value);
	}
}

bool AAGP_HUD::GetAutoSort()
{
	bool breturn = false;
	if (PlayerOwner != nullptr)
	{
		breturn = Cast<AHumanController>(PlayerOwner)->bAutoSortServerList;
	}
	else
	{
		breturn = false;
	}
	return breturn;
}

void AAGP_HUD::SetHUDColor(FColor NewColor)
{
	cPrevHUDColor = HUDColor;
	HUDColor.R = NewColor.R;
	HUDColor.G = NewColor.G;
	HUDColor.B = NewColor.B;
}

void AAGP_HUD::ShowCoords()
{
	/*
	Log("Player Group: " + PlayerOwner.PlayerReplicationInfo._Group + " Authorized server: " + Cast<AAA2_WorldSettings>(GetWorldSettings())->IsAuthorizedServer());
	if (PlayerOwner.PlayerReplicationInfo._Group != 1 && PlayerOwner.PlayerReplicationInfo._Group != 20 && PlayerOwner.PlayerReplicationInfo._Group != 4 && Cast<AHumanController>(PlayerOwner).bServerRequiresAuthorization)
	{
		Cast<AHumanController>(PlayerOwner).ClientMessage("Command not supported");
		return;
	}
	bShowCoords = !bShowCoords;
	if (bShowCoords)
	{
		Log("* ShowCoords: Location: " + PlayerOwner.Pawn.Location + " Rotation: " + PlayerOwner.Pawn.Rotation);
	}
	*/
}

void AAGP_HUD::ToggleBRoll()
{
	bBRoll = !bBRoll;
	//AGP_Pawn(Cast<AHumanController>(PlayerOwner).Pawn).GetOpticsDevice().NotifyBRoll(bBRoll);
}

void AAGP_HUD::DisplayVoiceGain(UCanvas* C)
{
	UMaterialInstance* Tex = nullptr;
	float VoiceGain = 0;
	float PosY = 0;
	float BlockSize = 0;
	float XL = 0;
	float YL = 0;
	int32 i = 0;
	FString ActiveName = "";
	/*
	BlockSize = 8192 / C.ClipX * HudScale;
	Tex = Texture'WhiteSquareTexture';
	PosY = C.ClipY * 0.375;
	VoiceGain = 1 - 3 * FMath::Min(GetWorld()->GetTimeSeconds() - LastVoiceGainTime, 0.3333) * LastVoiceGain;
	for (i = 0; i < 10; i++)
	{
		if (VoiceGain > 0.1 * i)
		{
			C.SetPos(0.5 * BlockSize, PosY);
			C.SetDrawColor(28.299999 * i, 255 - 28.299999 * i, 0, 255);
			C.DrawTile(Tex, BlockSize, BlockSize, 0, 0, Tex.USize, Tex.VSize);
			PosY -= 1.2 * BlockSize;
		}
	}
	if (PlayerOwner != nullptr && PlayerOwner.ActiveRoom != nullptr)
	{
		ActiveName = PlayerOwner.ActiveRoom.GetTitle();
	}
	if (ActiveName != "")
	{
		ActiveName = "(" @ ActiveName @ ")";
		C.Font = GetFontSizeIndex(C, -2);
		C.StrLen(ActiveName, XL, YL);
		if (XL > 0.125 * C.ClipY)
		{
			C.Font = GetFontSizeIndex(C, -4);
			C.StrLen(ActiveName, XL, YL);
		}
		C.SetPos(BlockSize * 2, C.ClipY * 0.375 + BlockSize - YL);
		C.DrawColor = C.MakeColor(160, 160, 160);
		if (PlayerOwner != nullptr && PlayerOwner.PlayerReplicationInfo != nullptr)
		{
			if (PlayerOwner.PlayerReplicationInfo.Team != nullptr)
			{
				if (PlayerOwner.PlayerReplicationInfo.Team.TeamIndex == 0)
				{
					C.DrawColor = RedColor;
				}
				else
				{
					C.DrawColor = TurqColor;
				}
			}
		}
		C.DrawText(ActiveName);
	}
	*/
}

void AAGP_HUD::ShowDebug(FName aDebugType)
{
	/*
	if ((PlayerOwner == nullptr) || (PlayerOwner.PlayerReplicationInfo == nullptr))
	{
		return;
	}
	if ((((PlayerOwner.PlayerReplicationInfo._Group != 1) && (PlayerOwner.PlayerReplicationInfo._Group != 20)) && (PlayerOwner.PlayerReplicationInfo._Group != 4)) && Cast<AHumanController>(PlayerOwner).bServerRequiresAuthorization)
	{
		Cast<AHumanController>(PlayerOwner).ClientMessage("Command not supported");
		return;
	}
	bShowDebugInfo = (!bShowDebugInfo);
	*/
}

void AAGP_HUD::BuildMOTD()
{
	int32 i = 0;
	int32 C = 0;
	int32 p = 0;
	FString S = "";
	FString t = "";
	/*
	if (bBuiltMOTD || PlayerOwner == NULL || PlayerOwner.GameReplicationInfo == nullptr)
	{
		return;
	}
	bBuiltMOTD = true;
	PlayerOwner.SetProgressTime(6);
	C = 0;
	t[0] = PlayerOwner.GameReplicationInfo.MOTDLine1;
	t[1] = PlayerOwner.GameReplicationInfo.MOTDLine2;
	t[2] = PlayerOwner.GameReplicationInfo.MOTDLine3;
	t[3] = PlayerOwner.GameReplicationInfo.MOTDLine4;
	Log("MOTD1: " + PlayerOwner.GameReplicationInfo.MOTDLine1);
	Log("MOTD2: " + PlayerOwner.GameReplicationInfo.MOTDLine2);
	Log("MOTD3: " + PlayerOwner.GameReplicationInfo.MOTDLine3);
	Log("MOTD4: " + PlayerOwner.GameReplicationInfo.MOTDLine4);
	for (i = 0; i < 4; i++)
	{
		p = InStr(t[i], "|");
		if (p >= 0)
		{
			S = Left(t[i], p);
			MOTD[C] = S;
			C++;
			if (C == 4)
			{
				return;
			}
			t[i] = Right(t[i], Len(t[i]) - p - 1);
			p = InStr(t[i], "|");
		}
		MOTD[C] = t[i];
		Log("MOTD[" + C + "] is: " + MOTD[C]);
		C++;
		if (C == 4)
		{
			return;
		}
	}
	*/
}

int32 AAGP_HUD::GetVersionAGPMajor()
{
	return 2;
}

int32 AAGP_HUD::GetVersionAGPMinor()
{
	return 9;
}

int32 AAGP_HUD::GetVersionAGPTiny()
{
	return 0;
};

int32 AAGP_HUD::GetVersionAGPSubTiny()
{
	return 0;
}

