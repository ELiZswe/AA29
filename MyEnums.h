// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"


UENUM(BlueprintType)
enum class ENPCOrders2 : uint8
{
	/* 0 */ NPCOrder_Patrol															UMETA(DisplayName = "NPCOrder_Patrol"),
	/* 1 */ NPCOrder_Guard															UMETA(DisplayName = "NPCOrder_Guard"),
	/* 2 */ NPCOrder_Ambush															UMETA(DisplayName = "NPCOrder_Ambush"),
	/* 3 */ NPCOrder_UnloadPassengers												UMETA(DisplayName = "NPCOrder_UnloadPassengers"),
	/* 4 */ NPCOrder_PatrolAndUnload												UMETA(DisplayName = "NPCOrder_PatrolAndUnload"),
	/* 5 */ NPCOrder_AssaultLocation												UMETA(DisplayName = "NPCOrder_AssaultLocation")
};

UENUM(BlueprintType)
enum class EAmmoState : uint8
{
	/* 0 */ AMMSTATE_None														UMETA(DisplayName = "AMMSTATE_None "),
	/* 1 */ AMMSTATE_On															UMETA(DisplayName = "AMMSTATE_On"),
	/* 2 */ AMMSTATE_Off														UMETA(DisplayName = "AMMSTATE_Off")
};

UENUM(BlueprintType)
enum class ESequenceStep : uint8
{
	/* 0 */ SEQUENCE_Start														UMETA(DisplayName = "SEQUENCE_Start"),
	/* 1 */ SEQUENCE_Finish														UMETA(DisplayName = "SEQUENCE_Finish"),
	/* 2 */ SEQUENCE_OutOfOrder													UMETA(DisplayName = "SEQUENCE_OutOfOrder"),
	/* 3 */ SEQUENCE_InOrder													UMETA(DisplayName = "SEQUENCE_InOrder")
};



UENUM(BlueprintType)
enum class EExtendLength : uint8
{
	/* 0 */ ELEN_Long															UMETA(DisplayName = "ELEN_Long"),
	/* 1 */ ELEN_Medium															UMETA(DisplayName = "ELEN_Medium"),
	/* 2 */ ELEN_Short															UMETA(DisplayName = "ELEN_Short"),
};

UENUM(BlueprintType)
enum class EReserveCommand : uint8
{
	/* 0 */ NPCRC_FollowOrders													UMETA(DisplayName = "NPCRC_FollowOrders"),
	/* 1 */ NPCRC_GOTOTRIGGER													UMETA(DisplayName = "NPCRC_GOTOTRIGGER"),
	/* 2 */ NPCRC_GOTOOBJECTIVE													UMETA(DisplayName = "NPCRC_GOTOOBJECTIVE"),
};

UENUM(BlueprintType)
enum class EPatrolCommand : uint8
{
	/* 0 */ NPCPC_Resume														UMETA(DisplayName = "NPCPC_Resume"),
	/* 1 */ NPCPC_Start															UMETA(DisplayName = "NPCPC_Start"),
	/* 2 */ NPCPC_Fallback														UMETA(DisplayName = "NPCPC_Fallback"),
	/* 3 */ NPCPC_DefendArea													UMETA(DisplayName = "NPCPC_DefendArea"),
	/* 4 */ NPCPC_WatchInstigator												UMETA(DisplayName = "NPCPC_WatchInstigator"),
	/* 5 */ NPCPC_SpawnReserves													UMETA(DisplayName = "NPCPC_SpawnReserves"),
};



UENUM(BlueprintType)
enum class EFluidGridType : uint8
{
	/* 0 */ FGT_Square															UMETA(DisplayName = "FGT_Square"),
	/* 1 */ FGT_Hexagonal														UMETA(DisplayName = "FGT_Hexagonal")
};


UENUM(BlueprintType)
enum class EProjectorBlending : uint8
{
	/* 0 */ PB_None																UMETA(DisplayName = "PB_None"),
	/* 1 */ PB_Modulate															UMETA(DisplayName = "PB_Modulate"),
	/* 2 */ PB_AlphaBlend														UMETA(DisplayName = "PB_AlphaBlend"),
	/* 3 */ PB_Add																UMETA(DisplayName = "PB_Add")
};

UENUM(BlueprintType)
enum class EDoubleClickDir : uint8
{
	/* 0 */ DCLICK_None															UMETA(DisplayName = "DCLICK_None"),
	/* 1 */ DCLICK_Left															UMETA(DisplayName = "DCLICK_Left"),
	/* 2 */ DCLICK_Right														UMETA(DisplayName = "DCLICK_Right"),
	/* 3 */ DCLICK_Forward														UMETA(DisplayName = "DCLICK_Forward"),
	/* 4 */ DCLICK_Back															UMETA(DisplayName = "DCLICK_Back"),
	/* 5 */ DCLICK_Active														UMETA(DisplayName = "DCLICK_Active"),
	/* 6 */ DCLICK_Done															UMETA(DisplayName = "DCLICK_Done")
};


UENUM(BlueprintType)
enum class EBounceAxis : uint8
{
	/* 0 */ BA_WorldZAxis														UMETA(DisplayName = "BA_WorldZAxis"),
	/* 1 */ BA_WorldXAxis														UMETA(DisplayName = "BA_WorldXAxis"),
	/* 2 */ BA_WorldYAxis														UMETA(DisplayName = "BA_WorldYAxis"),
	/* 3 */ BA_LocalZAxis														UMETA(DisplayName = "BA_LocalZAxis"),
	/* 4 */ BA_LocalXAxis														UMETA(DisplayName = "BA_LocalXAxis"),
	/* 5 */ BA_LocalYAxis														UMETA(DisplayName = "BA_LocalYAxis")
};

UENUM(BlueprintType)
enum class EHelpMarkerDisplay : uint8
{
	/* 0 */ HMD_Standard														UMETA(DisplayName = "HMD_Standard"),
	/* 1 */ HMD_Custom															UMETA(DisplayName = "HMD_Custom")
};


UENUM(BlueprintType)
enum class EMusicTransition : uint8
{
	/* 0 */ MTRAN_None															UMETA(DisplayName = "MTRAN_None"),
	/* 1 */ MTRAN_Instant														UMETA(DisplayName = "MTRAN_Instant"),
	/* 2 */ MTRAN_Segue															UMETA(DisplayName = "MTRAN_Segue"),
	/* 3 */ MTRAN_Fade															UMETA(DisplayName = "MTRAN_Fade"),
	/* 4 */ MTRAN_FastFade														UMETA(DisplayName = "MTRAN_FastFade"),
	/* 5 */ MTRAN_SlowFade														UMETA(DisplayName = "MTRAN_SlowFade")
};

UENUM(BlueprintType)
enum class EScaleMode : uint8
{
	/* 0 */ SM_None																UMETA(DisplayName = "THA_Left"),
	/* 1 */ SM_Up																UMETA(DisplayName = "THA_Left"),
	/* 2 */ SM_Down																UMETA(DisplayName = "THA_Left"),
	/* 3 */ SM_Left																UMETA(DisplayName = "THA_Left"),
	/* 4 */ SM_Right															UMETA(DisplayName = "THA_Left")
};

UENUM(BlueprintType)
enum class ETextHorzAlignment : uint8
{
	/* 0 */ THA_Left															UMETA(DisplayName = "THA_Left"),
	/* 1 */ THA_Centered														UMETA(DisplayName = "THA_Centered"),
	/* 2 */ THA_Right															UMETA(DisplayName = "THA_Right")
};

UENUM(BlueprintType)
enum class EHingeType : uint8
{
	/* 0 */ HT_Normal															UMETA(DisplayName = "HT_Normal"),
	/* 1 */ HT_Springy															UMETA(DisplayName = "HT_Springy"),
	/* 2 */ HT_Motor															UMETA(DisplayName = "HT_Motor"),
	/* 3 */ HT_Controlled														UMETA(DisplayName = "HT_Controlled")
};

UENUM(BlueprintType)
enum class EeAnimationCommand : uint8
{
	/* 0 */ AC_PlayAnim															UMETA(DisplayName = "AC_PlayAnim"),
	/* 1 */ AC_LoopAnim															UMETA(DisplayName = "AC_LoopAnim"),
	/* 2 */ AC_TweenAnim														UMETA(DisplayName = "AC_TweenAnim"),
	/* 3 */ AC_StopAnimating													UMETA(DisplayName = "AC_StopAnimating"),
	/* 4 */ AC_FreezeAnimAt														UMETA(DisplayName = "AC_FreezeAnimAt"),
	/* 5 */ AC_ClearQueue														UMETA(DisplayName = "AC_ClearQueue")
};

UENUM(BlueprintType)
enum class EVar : uint8
{
	/* 0 */ EV_None																UMETA(DisplayName = "EV_None"),
	/* 1 */ EV_SET																UMETA(DisplayName = "EV_SET"),
	/* 2 */ EV_INC																UMETA(DisplayName = "EV_INC"),
	/* 3 */ EV_DEC																UMETA(DisplayName = "EV_DEC")
};


UENUM(BlueprintType)
enum class EeFontScale : uint8
{
	/* 0 */ FNS_Small															UMETA(DisplayName = "FNS_Small"),
	/* 1 */ FNS_Medium															UMETA(DisplayName = "FNS_Medium"),
	/* 2 */ FNS_Large															UMETA(DisplayName = "FNS_Large")
};

UENUM(BlueprintType)
enum class EBeamEndPointType : uint8
{
	/* 0 */ PTEP_Velocity															UMETA(DisplayName = "PTEP_Velocity"),
	/* 1 */ PTEP_Distance															UMETA(DisplayName = "PTEP_Distance"),
	/* 2 */ PTEP_Offset																UMETA(DisplayName = "PTEP_Offset"),
	/* 3 */ PTEP_Actor																UMETA(DisplayName = "PTEP_Actor"),
	/* 4 */ PTEP_TraceOffset														UMETA(DisplayName = "PTEP_TraceOffset"),
	/* 5 */ PTEP_OffsetAsAbsolute													UMETA(DisplayName = "PTEP_OffsetAsAbsolute"),
	/* 6 */ PTEP_DynamicDistance													UMETA(DisplayName = "PTEP_DynamicDistance"),
	/* 7 */ PTEP_RopeSegment														UMETA(DisplayName = "PTEP_RopeSegment")
};

UENUM(BlueprintType)
enum class EBeamRopeType : uint8
{
	/* 0 */ BRT_NOTROPE																UMETA(DisplayName = "BRT_NOTROPE"),
	/* 1 */ BRT_THINROPE															UMETA(DisplayName = "BRT_THINROPE"),
	/* 2 */ BRT_FASTROPE															UMETA(DisplayName = "BRT_FASTROPE")
};

UENUM(BlueprintType)
enum class EAbsoluteRotationSource : uint8
{
	/* 0 */ PARS_None																UMETA(DisplayName = "PARS_None"),
	/* 1 */ PARS_ActorOnly															UMETA(DisplayName = "PARS_ActorOnly"),
	/* 2 */ PARS_ActorPlusOffset													UMETA(DisplayName = "PARS_ActorPlusOffset")
};


UENUM(BlueprintType)
enum class EParticleDirectionUsage : uint8
{
	/* 0 */ PTDU_None																UMETA(DisplayName = "PTDU_None"),
	/* 1 */ PTDU_Up																	UMETA(DisplayName = "PTDU_Up"),
	/* 2 */ PTDU_Right																UMETA(DisplayName = "PTDU_Right"),
	/* 3 */ PTDU_Forward															UMETA(DisplayName = "PTDU_Forward"),
	/* 4 */ PTDU_Normal																UMETA(DisplayName = "PTDU_Normal"),
	/* 5 */ PTDU_UpAndNormal														UMETA(DisplayName = "PTDU_UpAndNormal"),
	/* 6 */ PTDU_RightAndNormal														UMETA(DisplayName = "PTDU_RightAndNormal"),
	/* 7 */ PTDU_Scale																UMETA(DisplayName = "PTDU_Scale")
};

UENUM(BlueprintType)
enum class ETrailLocation : uint8
{
	/* 0 */ PTTL_AttachedToParticle													UMETA(DisplayName = "PTTL_AttachedToParticle"),
	/* 1 */ PTTL_FollowEmitter														UMETA(DisplayName = "PTTL_FollowEmitter")
};
UENUM(BlueprintType)
enum class ETrailShadeType : uint8
{
	/* 0 */ PTTST_None																UMETA(DisplayName = "PTTST_None"),
	/* 1 */ PTTST_RandomStatic														UMETA(DisplayName = "PTTST_RandomStatic"),
	/* 2 */ PTTST_RandomDynamic														UMETA(DisplayName = "PTTST_RandomDynamic"),
	/* 3 */ PTTST_Linear															UMETA(DisplayName = "PTTST_Linear"),
	/* 4 */ PTTST_PointLife															UMETA(DisplayName = "PTTST_PointLife")
};


UENUM(BlueprintType)
enum class EParticleCollisionSound : uint8
{
	/* 0 */ PTSC_None															UMETA(DisplayName = "PTSC_None"),
	/* 1 */ PTSC_LinearGlobal													UMETA(DisplayName = "PTSC_LinearGlobal"),
	/* 2 */ PTSC_LinearLocal													UMETA(DisplayName = "PTSC_LinearLocal"),
	/* 3 */ PTSC_Random															UMETA(DisplayName = "PTSC_Random")
};

UENUM(BlueprintType)
enum class EParticleDrawStyle : uint8
{
	/* 0 */ PTDS_Regular														UMETA(DisplayName = "PTDS_Regular"),
	/* 1 */ PTDS_AlphaBlend														UMETA(DisplayName = "PTDS_AlphaBlend"),
	/* 2 */ PTDS_Modulated														UMETA(DisplayName = "PTDS_Modulated"),
	/* 3 */ PTDS_Translucent													UMETA(DisplayName = "PTDS_Translucent"),
	/* 4 */ PTDS_AlphaModulate_MightNotFogCorrectly								UMETA(DisplayName = "PTDS_AlphaModulate_MightNotFogCorrectly"),
	/* 5 */ PTDS_Darken															UMETA(DisplayName = "PTDS_Darken"),
	/* 6 */ PTDS_Brighten														UMETA(DisplayName = "PTDS_Brighten"),
};

UENUM(BlueprintType)
enum class EParticleCoordinateSystem : uint8
{
	/* 0 */ PTCS_Independent													UMETA(DisplayName = "PTCS_Independent"),
	/* 1 */ PTCS_Relative														UMETA(DisplayName = "PTCS_Relative"),
	/* 2 */ PTCS_Absolute														UMETA(DisplayName = "PTCS_Absolute")
};

UENUM(BlueprintType)
enum class EParticleRotationSource : uint8
{
	/* 0 */ PTRS_None														UMETA(DisplayName = "PTRS_None"),
	/* 1 */ PTRS_Actor														UMETA(DisplayName = "PTRS_Actor"),
	/* 2 */ PTRS_Offset														UMETA(DisplayName = "PTRS_Offset"),
	/* 3 */ PTRS_Normal														UMETA(DisplayName = "PTRS_Normal")
};

UENUM(BlueprintType)
enum class EParticleVelocityDirection : uint8
{
	/* 0 */ PTVD_None															UMETA(DisplayName = "PTVD_None"),
	/* 1 */ PTVD_StartPositionAndOwner											UMETA(DisplayName = "PTVD_StartPositionAndOwner"),
	/* 2 */ PTVD_OwnerAndStartPosition											UMETA(DisplayName = "PTVD_OwnerAndStartPosition"),
	/* 3 */ PTVD_AddRadial														UMETA(DisplayName = "PTVD_AddRadial")
};


UENUM(BlueprintType)
enum class EParticleStartLocationShape : uint8
{
	/* 0 */ PTLS_Box														UMETA(DisplayName = "PTLS_Box"),
	/* 1 */ PTLS_Sphere														UMETA(DisplayName = "PTLS_Sphere"),
	/* 2 */ PTLS_Polar														UMETA(DisplayName = "PTLS_Polar"),
	/* 3 */ PTLS_All														UMETA(DisplayName = "PTLS_All")
};

UENUM(BlueprintType)
enum class EParticleEffectAxis : uint8
{
	/* 0 */ PTEA_NegativeX															UMETA(DisplayName = "PTEA_NegativeX"),
	/* 1 */ PTEA_PositiveZ															UMETA(DisplayName = "PTEA_PositiveZ")
};
UENUM(BlueprintType)
enum class EParticleMeshSpawning : uint8
{
	/* 0 */ PTMS_None															UMETA(DisplayName = "PTMS_None"),
	/* 1 */ PTMS_Linear															UMETA(DisplayName = "PTMS_Linear"),
	/* 2 */ PTMS_Random															UMETA(DisplayName = "PTMS_Random")
};

UENUM(BlueprintType)
enum class ESkelLocationUpdate : uint8
{
	/* 0 */ PTSU_None															UMETA(DisplayName = "PTSU_None"),
	/* 1 */ PTSU_SpawnOffset													UMETA(DisplayName = "PTSU_SpawnOffset"),
	/* 2 */ PTSU_Location														UMETA(DisplayName = "PTSU_Location")
};

UENUM(BlueprintType)
enum class EAA2BlendMode : uint8
{
	/* 0 */ BM_MODULATE															UMETA(DisplayName = "BM_MODULATE"),
	/* 1 */ BM_MODULATE2X														UMETA(DisplayName = "BM_MODULATE2X"),
	/* 2 */ BM_MODULATE4X														UMETA(DisplayName = "BM_MODULATE4X"),
	/* 3 */ BM_ADD																UMETA(DisplayName = "BM_ADD"),
	/* 4 */ BM_ADDSIGNED														UMETA(DisplayName = "BM_ADDSIGNED"),
	/* 5 */ BM_ADDSIGNED2X														UMETA(DisplayName = "BM_ADDSIGNED2X"),
	/* 6 */ BM_SUBTRACT															UMETA(DisplayName = "BM_SUBTRACT"),
	/* 7 */ BM_ADDSMOOTH														UMETA(DisplayName = "BM_ADDSMOOTH"),
	/* 8 */ BM_BLENDDIFFUSEALPHA												UMETA(DisplayName = "BM_BLENDDIFFUSEALPHA"),
	/* 9 */ BM_BLENDTEXTUREALPHA												UMETA(DisplayName = "BM_BLENDTEXTUREALPHA"),
	/* 10 */ BM_BLENDFACTORALPHA												UMETA(DisplayName = "BM_BLENDFACTORALPHA"),
	/* 11 */ BM_BLENDTEXTUREALPHAPM												UMETA(DisplayName = "BM_BLENDTEXTUREALPHAPM"),
	/* 12 */ BM_BLENDCURRENTALPHA												UMETA(DisplayName = "BM_BLENDCURRENTALPHA"),
	/* 13 */ BM_PREMODULATE														UMETA(DisplayName = "BM_PREMODULATE"),
	/* 14 */ BM_MODULATEALPHA_ADDCOLOR											UMETA(DisplayName = "BM_MODULATEALPHA_ADDCOLOR"),
	/* 15 */ BM_MODULATEINVALPHA_ADDCOLOR										UMETA(DisplayName = "BM_MODULATEINVALPHA_ADDCOLOR"),
	/* 16 */ BM_MODULATEINVCOLOR_ADDALPHA										UMETA(DisplayName = "BM_MODULATEINVCOLOR_ADDALPHA"),
	/* 17 */ BM_HACK															UMETA(DisplayName = "BM_HACK")
};

UENUM(BlueprintType)
enum class ESetting : uint8
{
	/* 0 */ SETTING_None														UMETA(DisplayName = "SETTING_None"),
	/* 1 */ SETTING_Urban														UMETA(DisplayName = "SETTING_Urban"),
	/* 2 */ SETTING_Industrial													UMETA(DisplayName = "SETTING_Industrial"),
	/* 3 */ SETTING_Rural														UMETA(DisplayName = "SETTING_Rural"),
	/* 4 */ SETTING_Arctic														UMETA(DisplayName = "SETTING_Arctic"),
	/* 5 */ SETTING_Desert														UMETA(DisplayName = "SETTING_Desert"),
	/* 6 */ SETTING_Village														UMETA(DisplayName = "SETTING_Village"),
	/* 7 */ SETTING_Campground													UMETA(DisplayName = "SETTING_Campground")
};

UENUM(BlueprintType)
enum class EFormat : uint8
{
	/* 0 */ FORMAT_HTM														UMETA(DisplayName = "FORMAT_HTM"),
	/* 1 */ FORMAT_WIKI														UMETA(DisplayName = "FORMAT_WIKI"),
	/* 2 */ FORMAT_TXT														UMETA(DisplayName = "FORMAT_TXT")
};

UENUM(BlueprintType)
enum class ETimeSetting : uint8
{
	/* 0 */ TIME_None														UMETA(DisplayName = "TIME_None"),
	/* 1 */ TIME_Dawn														UMETA(DisplayName = "TIME_Dawn"),
	/* 2 */ TIME_Day														UMETA(DisplayName = "TIME_Day"),
	/* 3 */ TIME_Dusk														UMETA(DisplayName = "TIME_Dusk"),
	/* 4 */ TIME_Night														UMETA(DisplayName = "TIME_Night")
};

UENUM(BlueprintType)
enum class EWeatherSetting : uint8
{
	/* 0 */ WEATHER_None														UMETA(DisplayName = "WEATHER_None"),
	/* 1 */ WEATHER_Snowing														UMETA(DisplayName = "WEATHER_Snowing"),
	/* 2 */ WEATHER_Stormy														UMETA(DisplayName = "WEATHER_Stormy"),
	/* 3 */ WEATHER_Overcast													UMETA(DisplayName = "WEATHER_Overcast"),
	/* 4 */ WEATHER_Raining														UMETA(DisplayName = "WEATHER_Raining"),
	/* 5 */ WEATHER_Sunny														UMETA(DisplayName = "WEATHER_Sunny")
};

UENUM(BlueprintType)
enum class ESCIRequestState : uint8
{
	/* 0 */ SCIREQ_Nothing														UMETA(DisplayName = "SCIREQ_Nothing"),
	/* 1 */ SCIREQ_Opening														UMETA(DisplayName = "SCIREQ_Opening"),
	/* 2 */ SCIREQ_RequestingCount												UMETA(DisplayName = "SCIREQ_RequestingCount"),
	/* 3 */ SCIREQ_RequestingOneServer											UMETA(DisplayName = "SCIREQ_RequestingOneServer"),
	/* 4 */ SCIREQ_RequestingList												UMETA(DisplayName = "SCIREQ_RequestingList"),
	/* 5 */ SCIREQ_Closing														UMETA(DisplayName = "SCIREQ_Closing")
};

//EOrientation
UENUM(BlueprintType)
enum class EAA2Orientation : uint8
{
	/* 0 */ ORIENT_Vertical														UMETA(DisplayName = "ORIENT_Vertical"),
	/* 1 */ ORIENT_Horizontal													UMETA(DisplayName = "ORIENT_Horizontal")
};


UENUM(BlueprintType)
enum class EViewMutatorMode : uint8
{
	/* 0 */ VMM_AnyMutators														UMETA(DisplayName = "VMM_AnyMutators"),
	/* 1 */ VMM_NoMutators														UMETA(DisplayName = "VMM_NoMutators"),
	/* 2 */ VMM_ThisMutator														UMETA(DisplayName = "VMM_ThisMutator"),
	/* 3 */ VMM_NotThisMutator													UMETA(DisplayName = "VMM_NotThisMutator")
};

UENUM(BlueprintType)
enum class ETranslocServerView : uint8
{
	/* 0 */ TSV_Any																UMETA(DisplayName = "TSV_Any"),
	/* 1 */ TSV_OnlyTransloc													UMETA(DisplayName = "TSV_OnlyTransloc"),
	/* 2 */ TSV_NoTransloc														UMETA(DisplayName = "TSV_NoTransloc")
};

UENUM(BlueprintType)
enum class EWeaponStayServerView : uint8
{
	/* 0 */ WSSV_Any															UMETA(DisplayName = "WSSV_Any"),
	/* 1 */ WSSV_OnlyWeaponStay													UMETA(DisplayName = "WSSV_OnlyWeaponStay"),
	/* 2 */ WSSV_NoWeaponStay													UMETA(DisplayName = "WSSV_NoWeaponStay")
};

UENUM(BlueprintType)
enum class EStatsServerView : uint8
{
	/* 0 */ SSV_Any																UMETA(DisplayName = "SSV_Any"),
	/* 1 */ SSV_OnlyStatsEnabled												UMETA(DisplayName = "SSV_OnlyStatsEnabled"),
	/* 2 */ SSV_NoStatsEnabled													UMETA(DisplayName = "SSV_NoStatsEnabled")
};


UENUM(BlueprintType)
enum class ESpeechMenuState : uint8
{
	/* 0 */ SMS_Main													UMETA(DisplayName = "SMS_Main"),
	/* 1 */ SMS_VoiceChat												UMETA(DisplayName = "SMS_VoiceChat"),
	/* 2 */ SMS_Ack														UMETA(DisplayName = "SMS_Ack"),
	/* 3 */ SMS_FriendFire												UMETA(DisplayName = "SMS_FriendFire"),
	/* 4 */ SMS_Order													UMETA(DisplayName = "SMS_Order"),
	/* 5 */ SMS_Other													UMETA(DisplayName = "SMS_Other"),
	/* 6 */ SMS_Taunt													UMETA(DisplayName = "SMS_Taunt"),
	/* 7 */ SMS_TauntAnim												UMETA(DisplayName = "SMS_TauntAnim"),
	/* 8 */ SMS_PlayerSelect											UMETA(DisplayName = "SMS_PlayerSelect"),
	/* 9 */ SMS_VoiceChatChannel										UMETA(DisplayName = "SMS_VoiceChatChannel")
};

UENUM(BlueprintType)
enum class EVideoChangeType : uint8
{
	/* 0 */ VCT_Resolution												UMETA(DisplayName = "VCT_Resolution"),
	/* 1 */ VCT_FullScreen												UMETA(DisplayName = "VCT_FullScreen"),
	/* 2 */ VCT_Device													UMETA(DisplayName = "VCT_Device")
};

UENUM(BlueprintType)
enum class EepbWinMode : uint8
{
	/* 0 */ MODE_Compact												UMETA(DisplayName = "MODE_Compact"),
	/* 1 */ MODE_PlayList												UMETA(DisplayName = "MODE_PlayList"),
	/* 2 */ MODE_Manager												UMETA(DisplayName = "MODE_Manager")
};

UENUM(BlueprintType)
enum class EFavoritesAction : uint8
{
	/* 0 */ FAVORITES_Add												UMETA(DisplayName = "FAVORITES_Add"),
	/* 1 */ FAVORITES_Remove											UMETA(DisplayName = "FAVORITES_Remove")
};


UENUM(BlueprintType)
enum class EAwayMode : uint8
{
	/* 0 */ AM_None														UMETA(DisplayName = "AM_None"),
	/* 1 */ AM_Server													UMETA(DisplayName = "AM_Server"),
	/* 2 */ AM_InstantAction											UMETA(DisplayName = "AM_InstantAction"),
	/* 3 */ AM_Menus													UMETA(DisplayName = "AM_Menus")
};

UENUM(BlueprintType)
enum class EGUISplitterType : uint8
{
	/* 0 */ SPLIT_Vertical												UMETA(DisplayName = "SPLIT_Vertical"),
	/* 1 */ SPLIT_Horizontal											UMETA(DisplayName = "SPLIT_Horizontal")
};


UENUM(BlueprintType)
enum class EeCellAlign : uint8
{
	/* 0 */ CA_TopRight													UMETA(DisplayName = "CA_TopRight"),
	/* 1 */ CA_TopCenter												UMETA(DisplayName = "CA_TopCenter"),
	/* 2 */ CA_TopLeft													UMETA(DisplayName = "CA_TopLeft"),
	/* 3 */ CA_MiddleRight												UMETA(DisplayName = "CA_MiddleRight"),
	/* 4 */ CA_Centered													UMETA(DisplayName = "CA_Centered"),
	/* 5 */ CA_MiddleLeft												UMETA(DisplayName = "CA_MiddleLeft"),
	/* 6 */ CA_BottomRight												UMETA(DisplayName = "CA_BottomRight"),
	/* 7 */ CA_BottomCenter												UMETA(DisplayName = "CA_BottomCenter"),
	/* 8 */ CA_BottomLeft												UMETA(DisplayName = "CA_BottomLeft")
};

UENUM(BlueprintType)
enum class EClientToMaster : uint8
{
	/* 0 */ CTM_Query													UMETA(DisplayName = "CTM_Query"),
	/* 1 */ CTM_GetMOTD													UMETA(DisplayName = "CTM_GetMOTD"),
	/* 2 */ CTM_QueryUpgrade											UMETA(DisplayName = "CTM_QueryUpgrade"),
	/* 3 */ CTM_GetModMOTD												UMETA(DisplayName = "CTM_GetModMOTD"),
	/* 4 */ CTM_GetOwnageList											UMETA(DisplayName = "CTM_GetOwnageList"),
};

UENUM(BlueprintType)
enum class EQueryType : uint8
{
	/* 0 */ QT_Equals													UMETA(DisplayName = "QT_Equals"),
	/* 1 */ QT_NotEquals												UMETA(DisplayName = "QT_NotEquals"),
	/* 2 */ QT_LessThan													UMETA(DisplayName = "QT_LessThan"),
	/* 3 */ QT_LessThanEquals											UMETA(DisplayName = "QT_LessThanEquals"),
	/* 4 */ QT_GreaterThan												UMETA(DisplayName = "QT_GreaterThan"),
	/* 5 */ QT_GreaterThanEquals										UMETA(DisplayName = "QT_GreaterThanEquals"),
	/* 6 */ QT_Disabled													UMETA(DisplayName = "QT_Disabled")
};

UENUM(BlueprintType)
enum class EMOTDResponse : uint8
{
	/* 0 */ MR_MOTD														UMETA(DisplayName = "MR_MOTD"),
	/* 1 */ MR_MandatoryUpgrade											UMETA(DisplayName = "MR_MandatoryUpgrade"),
	/* 2 */ MR_OptionalUpgrade											UMETA(DisplayName = "MR_OptionalUpgrade"),
	/* 3 */ MR_NewServer												UMETA(DisplayName = "MR_NewServer"),
	/* 4 */ MR_IniSetting												UMETA(DisplayName = "MR_IniSetting"),
	/* 5 */ MR_Command													UMETA(DisplayName = "MR_Command")
};

UENUM(BlueprintType)
enum class EDataType : uint8
{
	/* 0 */ DT_Unique													UMETA(DisplayName = "DT_Unique"),
	/* 1 */ DT_Ranged													UMETA(DisplayName = "DT_Ranged"),
	/* 2 */ DT_Multiple													UMETA(DisplayName = "DT_Multiple")
};


UENUM(BlueprintType)
enum class EFavoritesDisplayMode : uint8
{
	/* 0 */ EFDM_FavoriteServers										UMETA(DisplayName = "EFDM_FavoriteServers"),
	/* 1 */ EFDM_BattleBuddies											UMETA(DisplayName = "EFDM_BattleBuddies")
};

UENUM(BlueprintType)
enum class EPingCause : uint8
{
	/* 0 */ PC_Unknown													UMETA(DisplayName = "PC_Unknown"),
	/* 1 */ PC_Clicked													UMETA(DisplayName = "PC_Clicked"),
	/* 2 */ PC_AutoPing													UMETA(DisplayName = "PC_AutoPing"),
	/* 3 */ PC_LANBroadcast												UMETA(DisplayName = "PC_LANBroadcast")
};

UENUM(BlueprintType)
enum class EQueryInterfaceCommand : uint8
{
	/* 0 */ QI_Ping														UMETA(DisplayName = "QI_Ping"),
	/* 1 */ QI_Rules													UMETA(DisplayName = "QI_Rules"),
	/* 2 */ QI_Players													UMETA(DisplayName = "QI_Players"),
	/* 3 */ QI_RulesAndPlayers											UMETA(DisplayName = "QI_RulesAndPlayers"),
	/* 4 */ QI_SmallPing												UMETA(DisplayName = "QI_SmallPing")
};

UENUM(BlueprintType)
enum class EResponseInfo : uint8
{
	/* 0 */ RI_AuthenticationFailed										UMETA(DisplayName = "RI_AuthenticationFailed"),
	/* 0 */ RI_ConnectionFailed											UMETA(DisplayName = "RI_ConnectionFailed"),
	/* 0 */ RI_ConnectionTimeout										UMETA(DisplayName = "RI_ConnectionTimeout"),
	/* 0 */ RI_Success													UMETA(DisplayName = "RI_Success"),
	/* 0 */ RI_MustUpgrade												UMETA(DisplayName = "RI_MustUpgrade"),
	/* 0 */ RI_DevClient												UMETA(DisplayName = "RI_DevClient"),
	/* 0 */ RI_BadClient												UMETA(DisplayName = "RI_BadClient"),
	/* 0 */ RI_BannedClient												UMETA(DisplayName = "RI_BannedClient")
};

UENUM(BlueprintType)
enum class EePageAlign : uint8
{
	/* 0 */ PGA_None													UMETA(DisplayName = "PGA_None"),
	/* 1 */ PGA_Client													UMETA(DisplayName = "PGA_Client"),
	/* 2 */ PGA_Left													UMETA(DisplayName = "PGA_Left"),
	/* 3 */ PGA_Right													UMETA(DisplayName = "PGA_Right"),
	/* 4 */ PGA_Top														UMETA(DisplayName = "PGA_Top"),
	/* 5 */ PGA_Bottom													UMETA(DisplayName = "PGA_Bottom")
};

UENUM(BlueprintType)
enum class EeCellStyle : uint8
{
	/* 0 */ CELL_FixedSize												UMETA(DisplayName = "CELL_FixedSize"),
	/* 1 */ CELL_FixedCount												UMETA(DisplayName = "CELL_FixedCount")
};


UENUM(BlueprintType)
enum class EListMode : uint8
{
	/* 0 */ MyTeamIcons													UMETA(DisplayName = "MyTeamIcons"),
	/* 1 */ OppTeamIcons												UMETA(DisplayName = "OppTeamIcons")
};


UENUM(BlueprintType)
enum class EeScrollState : uint8
{
	/* 0 */ STS_None													UMETA(DisplayName = "STS_None"),
	/* 1 */ STS_Initial													UMETA(DisplayName = "STS_Initial"),
	/* 2 */ STS_Char													UMETA(DisplayName = "STS_Char"),
	/* 3 */ STS_EOL														UMETA(DisplayName = "STS_EOL"),
	/* 4 */ STS_Repeat													UMETA(DisplayName = "STS_Repeat")
};

UENUM(BlueprintType)
enum class EeTextAlign : uint8
{
	/* 0 */ TXTA_Left													UMETA(DisplayName = "TXTA_Left"),
	/* 1 */ TXTA_Center													UMETA(DisplayName = "TXTA_Center"),
	/* 2 */ TXTA_Right													UMETA(DisplayName = "TXTA_Right")
};

UENUM(BlueprintType)
enum class ETextAlign : uint8
{
	/* 0 */ TXTA_Left													UMETA(DisplayName = "TXTA_Left"),
	/* 1 */ TXTA_Center													UMETA(DisplayName = "TXTA_Center"),
	/* 2 */ TXTA_Right													UMETA(DisplayName = "TXTA_Right")
};




UENUM(BlueprintType)
enum class EBulletImpactType : uint8
{
	/* 0 */ BT_Impact													UMETA(DisplayName = "BT_Impact"),
	/* 1 */ BT_Exit														UMETA(DisplayName = "BT_Exit"),
	/* 2 */ BT_Ricochet													UMETA(DisplayName = "BT_Ricochet")
};


UENUM(BlueprintType)
enum class EeShifterState : uint8
{
	/* 0 */ SS_Park														UMETA(DisplayName = "SS_Park"),
	/* 1 */ SS_Drive													UMETA(DisplayName = "SS_Drive"),
	/* 2 */ SS_Reverse													UMETA(DisplayName = "SS_Reverse")
};


UENUM(BlueprintType)
enum class EDieselPuffState : uint8
{
	/* 0 */ Off															UMETA(DisplayName = "Off"),
	/* 1 */ VehicleStarted												UMETA(DisplayName = "VehicleStarted"),
	/* 2 */ Idling														UMETA(DisplayName = "Idling"),
	/* 3 */ ThrottlePunched												UMETA(DisplayName = "ThrottlePunched"),
	/* 4 */ SlowSpeed													UMETA(DisplayName = "SlowSpeed"),
	/* 5 */ HighSpeed													UMETA(DisplayName = "HighSpeed")
};



UENUM(BlueprintType)
enum class EJoinChatResult : uint8
{
	/* 0 */ JCR_Invalid													UMETA(DisplayName = "JCR_Invalid"),
	/* 1 */ JCR_Member													UMETA(DisplayName = "JCR_Member"),
	/* 2 */ JCR_NeedPassword											UMETA(DisplayName = "JCR_NeedPassword"),
	/* 3 */ JCR_WrongPassword											UMETA(DisplayName = "JCR_WrongPassword"),
	/* 4 */ JCR_Banned													UMETA(DisplayName = "JCR_Banned"),
	/* 5 */ JCR_Full													UMETA(DisplayName = "JCR_Full"),
	/* 6 */ JCR_NotAllowed												UMETA(DisplayName = "JCR_NotAllowed"),
	/* 7 */ JCR_Success													UMETA(DisplayName = "JCR_Success")
};


UENUM(BlueprintType)
enum class ESST_Mode : uint8
{
	/* 0 */ ESST_SkipToNextLine											UMETA(DisplayName = "ESST_SkipToNextLine")
};


UENUM(BlueprintType)
enum class EBoneEditViewType : uint8
{
	/* 0 */ VT_CylindersAndCaps											UMETA(DisplayName = "VT_CylindersAndCaps"),
	/* 1 */ VT_Damage													UMETA(DisplayName = "VT_Damage"),
	/* 2 */ VT_Region													UMETA(DisplayName = "VT_Region")
};


UENUM(BlueprintType)
enum class EJumpType : uint8
{
	/* 0 */ JUMP_Normal													UMETA(DisplayName = "JUMP_Normal"),
	/* 1 */ JUMP_Double													UMETA(DisplayName = "JUMP_Double"),
	/* 2 */ JUMP_DodgeLeft												UMETA(DisplayName = "JUMP_DodgeLeft"),
	/* 3 */ JUMP_DodgeRight												UMETA(DisplayName = "JUMP_DodgeRight")
};


UENUM(BlueprintType)
enum class EAlertnessType : uint8
{
	/* 0 */ ALERTNESS_IgnoreAll											UMETA(DisplayName = "ALERTNESS_IgnoreAll"),
	/* 1 */ ALERTNESS_IgnoreEnemies										UMETA(DisplayName = "ALERTNESS_IgnoreEnemies"),
	/* 2 */ ALERTNESS_StayOnScript										UMETA(DisplayName = "ALERTNESS_StayOnScript"),
	/* 3 */ ALERTNESS_LeaveScriptForCombat								UMETA(DisplayName = "ALERTNESS_LeaveScriptForCombat")
};

UENUM(BlueprintType)
enum class EFileType : uint8
{
	/* 0 */ FILE_None													UMETA(DisplayName = "FILE_None"),
	/* 1 */ FILE_Directory												UMETA(DisplayName = "FILE_Directory"),
	/* 2 */ FILE_Log													UMETA(DisplayName = "FILE_Log"),
	/* 3 */ FILE_Ini													UMETA(DisplayName = "FILE_Ini"),
	/* 4 */ FILE_Stream													UMETA(DisplayName = "FILE_Stream"),
	/* 5 */ FILE_Playlist												UMETA(DisplayName = "FILE_Playlist"),
	/* 6 */ FILE_Music													UMETA(DisplayName = "FILE_Music"),
	/* 7 */ FILE_Map													UMETA(DisplayName = "FILE_Map"),
	/* 8 */ FILE_Texture												UMETA(DisplayName = "FILE_Texture"),
	/* 9 */ FILE_Animation												UMETA(DisplayName = "FILE_Animation"),
	/*10 */ FILE_Static													UMETA(DisplayName = "FILE_Static"),
	/*11 */ FILE_XML													UMETA(DisplayName = "FILE_XML"),
	/*12 */ FILE_HTML													UMETA(DisplayName = "FILE_HTML"),
	/*13 */ FILE_Sound													UMETA(DisplayName = "FILE_Sound"),
	/*14 */ FILE_Demo													UMETA(DisplayName = "FILE_Demo"),
	/*15 */ FILE_DivX													UMETA(DisplayName = "FILE_DivX")
};

UENUM(BlueprintType)
enum class EStreamPlaylistType : uint8
{
	/* 0 */ SPT_None													UMETA(DisplayName = "SPT_None"),
	/* 0 */ SPT_M3U														UMETA(DisplayName = "SPT_M3U"),
	/* 0 */ SPT_PLS														UMETA(DisplayName = "SPT_PLS"),
	/* 0 */ SPT_B4S														UMETA(DisplayName = "SPT_B4S")
};


UENUM(BlueprintType)
enum class EAA2_Axis : uint8
{
	/* 0 */ AXIS_X														UMETA(DisplayName = "AXIS_X"),
	/* 1 */ AXIS_Y														UMETA(DisplayName = "AXIS_Y"),
	/* 2 */ AXIS_Z														UMETA(DisplayName = "AXIS_Z")
};


UENUM(BlueprintType)
enum class EVehicleSteerType : uint8
{
	/* 0 */ VST_Fixed													UMETA(DisplayName = "VST_Fixed"),
	/* 1 */ VST_Steered													UMETA(DisplayName = "VST_Steered"),
	/* 2 */ VST_Inverted												UMETA(DisplayName = "VST_Inverted")
};

UENUM(BlueprintType)
enum class EDisplayType : uint8
{
	/* 0 */ DTYPE_None													UMETA(DisplayName = "DTYPE_None"),
	/* 1 */ DTYPE_Active												UMETA(DisplayName = "DTYPE_Active"),
	/* 2 */ DTYPE_Fading												UMETA(DisplayName = "DTYPE_Fading")
};

UENUM(BlueprintType)
enum class EMeshOwnerType : uint8
{
	/* 0 */ MO_Vehicle													UMETA(DisplayName = "MO_Vehicle"),
	/* 1 */ MO_VehiclePosition											UMETA(DisplayName = "MO_VehiclePosition"),
	/* 2 */ MO_VehiclePositionWeapon									UMETA(DisplayName = "MO_VehiclePositionWeapon"),
	/* 3 */ MO_AttachedActor											UMETA(DisplayName = "MO_AttachedActor")
};

UENUM(BlueprintType)
enum class ELaserBaseType : uint8
{
	/* 0 */ BASETYPE_BaseWeaponMod										UMETA(DisplayName = "BASETYPE_BaseWeaponMod"),
	/* 1 */ BASETYPE_BaseWeaponAttachment								UMETA(DisplayName = "BASETYPE_BaseWeaponAttachment"),
	/* 2 */ BASETYPE_AGP_Pawn											UMETA(DisplayName = "BASETYPE_AGP_Pawn")
};

UENUM(BlueprintType)
enum class EAgentGoal : uint8
{
	/* 0 */ GOAL_None													UMETA(DisplayName = "GOAL_None"),
	/* 1 */ GOAL_Attrit													UMETA(DisplayName = "GOAL_Attrit"),
	/* 2 */ GOAL_Survive												UMETA(DisplayName = "GOAL_Survive"),
	/* 3 */ GOAL_Orders													UMETA(DisplayName = "GOAL_Orders"),
	/* 4 */ GOAL_Attack													UMETA(DisplayName = "GOAL_Attack"),
	/* 5 */ GOAL_Defend													UMETA(DisplayName = "GOAL_Defend"),
	/* 6 */ GOAL_Recon													UMETA(DisplayName = "GOAL_Recon"),
	/* 7 */ GOAL_Improve												UMETA(DisplayName = "GOAL_Improve"),
	/* 8 */ GOAL_AttackX												UMETA(DisplayName = "GOAL_AttackX"),
	/* 9 */ GOAL_Patrol													UMETA(DisplayName = "GOAL_Patrol")
};


UENUM(BlueprintType)
enum class EAction : uint8
{
	/* 0 */ m_None														UMETA(DisplayName = "m_None"),
	/* 1 */ m_Suppress													UMETA(DisplayName = "m_Suppress"),
	/* 2 */ m_Attack													UMETA(DisplayName = "m_Attack"),
	/* 3 */ m_Idle														UMETA(DisplayName = "m_Idle"),
	/* 4 */ m_Patrol													UMETA(DisplayName = "m_Patrol"),
	/* 5 */ m_MovementToward											UMETA(DisplayName = "m_MovementToward"),
	/* 6 */ m_MovementTo												UMETA(DisplayName = "m_MovementTo"),
	/* 7 */ m_Wander													UMETA(DisplayName = "m_Wander"),
	/* 8 */ m_Flee														UMETA(DisplayName = "m_Flee"),
	/* 9 */ m_FixJam													UMETA(DisplayName = "m_FixJam"),
	/*10 */ m_Reload													UMETA(DisplayName = "m_Reload"),
	/*11 */ m_Recovery													UMETA(DisplayName = "m_Recovery"),
	/*12 */ m_TakeCover													UMETA(DisplayName = "m_TakeCover"),
	/*13 */ m_Charge													UMETA(DisplayName = "m_Charge"),
	/*14 */ m_Wait														UMETA(DisplayName = "m_Wait")
};


UENUM(BlueprintType)
enum class eBodyPanelDamageType : uint8
{
	/* 0 */ BPDT_Projectile												UMETA(DisplayName = "BPDT_Projectile"),
	/* 1 */ BPDT_Explosion												UMETA(DisplayName = "BPDT_Explosion"),
	/* 2 */ BPDT_Collision												UMETA(DisplayName = "BPDT_Collision")
};

UENUM(BlueprintType)
enum class ECameraEffect_PipelineLocation : uint8
{
	/* 0 */ CEPL_BeforeHUD												UMETA(DisplayName = "CEPL_BeforeHUD"),
	/* 1 */ CEPL_AfterHUD												UMETA(DisplayName = "CEPL_AfterHUD")
};

UENUM(BlueprintType)
enum class ESAStatus : uint8
{
	/* 0 */ SASTATUS_Waiting											UMETA(DisplayName = "SASTATUS_Waiting"),
	/* 1 */ SASTATUS_Running											UMETA(DisplayName = "SASTATUS_Running"),
	/* 2 */ SASTATUS_Ending												UMETA(DisplayName = "SASTATUS_Ending"),
	/* 3 */ SASTATUS_Expired											UMETA(DisplayName = "SASTATUS_Expired")
};


UENUM(BlueprintType)
enum class EPathStyle : uint8
{
	/* 0 */ PATHSTYLE_Linear											UMETA(DisplayName = "PATHSTYLE_Linear"),
	/* 1 */ PATHSTYLE_Bezier											UMETA(DisplayName = "PATHSTYLE_Bezier")
};

UENUM(BlueprintType)
enum class ECamOrientation : uint8
{
	/* 0 */ CAMORIENT_None												UMETA(DisplayName = "CAMORIENT_None"),
	/* 1 */ CAMORIENT_LookAtActor										UMETA(DisplayName = "CAMORIENT_LookAtActor"),
	/* 2 */ CAMORIENT_FacePath											UMETA(DisplayName = "CAMORIENT_FacePath"),
	/* 3 */ CAMORIENT_Interpolate										UMETA(DisplayName = "CAMORIENT_Interpolate"),
	/* 4 */ CAMORIENT_Dolly												UMETA(DisplayName = "CAMORIENT_Dolly"),
};



UENUM(BlueprintType)
enum class EAffect : uint8
{
	/* 0 */ AFFECT_ViewportCamera										UMETA(DisplayName = "AFFECT_ViewportCamera"),
	/* 1 */ AFFECT_Actor							 					UMETA(DisplayName = "AFFECT_Actor")
};


UENUM(BlueprintType)
enum class EDudeType : uint8
{
	/* 0 */ DT_Dignan							 						UMETA(DisplayName = "DT_Dignan"),
	/* 1 */ DT_Phil							 							UMETA(DisplayName = "DT_Phil"),
	/* 2 */ DT_Jason							 						UMETA(DisplayName = "DT_Jason"),
	/* 3 */ DT_Jerry							 						UMETA(DisplayName = "DT_Jerry")
};

UENUM(BlueprintType)
enum class EAlertLevel : uint8
{
	/* 0 */ AL_Low							 							UMETA(DisplayName = "AL_Low"),
	/* 1 */ AL_Medium							 						UMETA(DisplayName = "AL_Medium"),
	/* 2 */ AL_High							 							UMETA(DisplayName = "AL_High")
};


UENUM(BlueprintType)
enum class EAPriority : uint8
{
	/* 0 */ AP_Normal							 						UMETA(DisplayName = "AP_Normal"),
	/* 1 */ AP_NoDuplicates							 					UMETA(DisplayName = "AP_NoDuplicates"),
	/* 2 */ AP_InstantPlay							 					UMETA(DisplayName = "AP_InstantPlay"),
	/* 3 */ AP_InstantOrQueueSwitch										UMETA(DisplayName = "AP_InstantOrQueueSwitch")
};


UENUM(BlueprintType)
enum class EProcMeshType : uint8
{
	/* 0 */ PMT_Water							 						UMETA(DisplayName = "PMT_Water"),
	/* 1 */ PMT_Deform							 						UMETA(DisplayName = "PMT_Deform")
};

UENUM(BlueprintType)
enum class EEventType : uint8
{
	/* 0 */ ET_None							 							UMETA(DisplayName = "ET_None"),
	/* 1 */ ET_UsedBy							 						UMETA(DisplayName = "ET_UsedBy"),
	/* 2 */ ET_PickedUp							 						UMETA(DisplayName = "ET_PickedUp"),
	/* 3 */ ET_Dropped							 						UMETA(DisplayName = "ET_Dropped"),
	/* 4 */ ET_Trigger							 						UMETA(DisplayName = "ET_Trigger"),
	/* 5 */ ET_UnTrigger							 					UMETA(DisplayName = "ET_UnTrigger"),
	/* 6 */ ET_Enter							 						UMETA(DisplayName = "ET_Enter"),
	/* 7 */ ET_Exit							 							UMETA(DisplayName = "ET_Exit"),
	/* 8 */ ET_Damaged							 						UMETA(DisplayName = "ET_Damaged"),
	/* 9 */ ET_Destroyed							 					UMETA(DisplayName = "ET_Destroyed"),
	/* 10*/ ET_Explode							 						UMETA(DisplayName = "ET_Explode"),
	/* 11*/ ET_Died							 							UMETA(DisplayName = "ET_Died"),
	/* 12*/ ET_LSAnimEnd							 					UMETA(DisplayName = "ET_LSAnimEnd"),
	/* 13*/ ET_SceneStart							 					UMETA(DisplayName = "ET_SceneStart"),
	/* 14*/ ET_SceneEnd							 						UMETA(DisplayName = "ET_SceneEnd"),
	/* 15*/ ET_PointReached							 					UMETA(DisplayName = "ET_PointReached"),
	/* 16*/ ET_HttpGet							 						UMETA(DisplayName = "ET_HttpGet"),
	/* 17*/ ET_Fire							 							UMETA(DisplayName = "ET_Fire"),
	/* 18*/ ET_TraceHit							 						UMETA(DisplayName = "ET_TraceHit"),
	/* 19*/ ET_Throw							 						UMETA(DisplayName = "ET_Throw"),
	/* 20*/ ET_WeaponJam							 					UMETA(DisplayName = "ET_WeaponJam"),
	/* 21*/ ET_WeaponEmpty							 					UMETA(DisplayName = "ET_WeaponEmpty"),
	/* 22*/ ET_FirstDraw							 					UMETA(DisplayName = "ET_FirstDraw"),
	/* 23*/ ET_VehicleWeaponFire							 			UMETA(DisplayName = "ET_VehicleWeaponFire"),
	/* 24*/ ET_VehicleSpawned							 				UMETA(DisplayName = "ET_VehicleSpawned"),
	/* 25*/ ET_VehicleEnter							 					UMETA(DisplayName = "ET_VehicleEnter"),
	/* 26*/ ET_VehicleExit							 					UMETA(DisplayName = "ET_VehicleExit"),
	/* 27*/ ET_VehicleAt							 					UMETA(DisplayName = "ET_VehicleAt"),
	/* 28*/ ET_VehicleDied							 					UMETA(DisplayName = "ET_VehicleDied"),
	/* 29*/ ET_TMDispatchComplete							 			UMETA(DisplayName = "ET_TMDispatchComplete"),
	/* 30*/ ET_ELCheat							 						UMETA(DisplayName = "ET_ELCheat"),
	/* 31*/ ET_Custom							 						UMETA(DisplayName = "ET_Custom")
};


UENUM(BlueprintType)
enum class EActorType : uint8
{
	/* 0 */ ACTOR_None							 						UMETA(DisplayName = "ACTOR_None"),
	/* 1 */ ACTOR_AllActors							 					UMETA(DisplayName = "ACTOR_AllActors"),
	/* 2 */ ACTOR_PawnsOnly							 					UMETA(DisplayName = "ACTOR_PawnsOnly"),
	/* 3 */ ACTOR_PlayersOnly							 				UMETA(DisplayName = "ACTOR_PlayersOnly"),
	/* 4 */ ACTOR_SpecificActors										UMETA(DisplayName = "ACTOR_SpecificActors")
};


UENUM(BlueprintType)
enum class EFontType : uint8
{
	/* 0 */ FT_Courier							 						UMETA(DisplayName = "FT_Courier"),
	/* 1 */ FT_LED							 							UMETA(DisplayName = "FT_LED")
};

UENUM(BlueprintType)
enum class ESoundOcclusion : uint8
{
	/* 0 */ OCCLUSION_Default							 				UMETA(DisplayName = "OCCLUSION_Default"),
	/* 1 */ OCCLUSION_None								 				UMETA(DisplayName = "OCCLUSION_None"),
	/* 2 */ OCCLUSION_BSP								 				UMETA(DisplayName = "OCCLUSION_BSP"),
	/* 3 */ OCCLUSION_StaticMeshes						 				UMETA(DisplayName = "OCCLUSION_StaticMeshes")
};

UENUM(BlueprintType)
enum class EQualificationState : uint8
{
	/* 0 */ QS_None								 						UMETA(DisplayName = "QS_None"),
	/* 1 */ QS_Practicing								 				UMETA(DisplayName = "QS_Practicing"),
	/* 2 */ QS_Qualifying								 				UMETA(DisplayName = "QS_Qualifying"),
	/* 3 */ QS_Passed								 					UMETA(DisplayName = "QS_Passed"),
	/* 4 */ QS_Failed								 					UMETA(DisplayName = "QS_Failed")
};

UENUM(BlueprintType)
enum class ESmokeGrenadeStatus : uint8
{
	/* 0 */ SGS_None								 					UMETA(DisplayName = "SGS_None"),
	/* 1 */ SGS_PlayerHolding								 			UMETA(DisplayName = "SGS_PlayerHolding"),
	/* 2 */ SGS_Thrown								 					UMETA(DisplayName = "SGS_Thrown")
};

UENUM(BlueprintType)
enum class EMedicalItemState : uint8
{
	/* 0 */ MIS_None								 					UMETA(DisplayName = "MIS_None"),
	/* 1 */ MIS_WaitingForPickup										UMETA(DisplayName = "MIS_WaitingForPickup"),
	/* 2 */ MIS_PickedUp								 				UMETA(DisplayName = "MIS_PickedUp"),
	/* 3 */ MIS_Applied								 					UMETA(DisplayName = "MIS_Applied")
};

UENUM(BlueprintType)
enum class EAlertLanguage : uint8
{
	/* 0 */ LANG_Bluefor								 				UMETA(DisplayName = "LANG_Bluefor"),
	/* 1 */ LANG_Opfor								 					UMETA(DisplayName = "LANG_Opfor")
};

UENUM(BlueprintType)
enum class EPlayerPosture : uint8
{
	/* 0 */ P_Prone								 						UMETA(DisplayName = "P_Prone"),
	/* 1 */ P_Crouching								 					UMETA(DisplayName = "P_Crouching"),
	/* 2 */ P_Standing								 					UMETA(DisplayName = "P_Standing")
};



UENUM(BlueprintType)
enum class ETimerType : uint8
{
	/* 0 */ TT_Timer								 					UMETA(DisplayName = "TT_Timer"),
	/* 1 */ TT_Sound								 					UMETA(DisplayName = "TT_Sound"),
	/* 2 */ TT_Anim								 						UMETA(DisplayName = "TT_Anim"),
	/* 3 */ TT_LSAnim								 					UMETA(DisplayName = "TT_LSAnim"),
	/* 4 */ TT_Fade								 						UMETA(DisplayName = "TT_Fade"),
	/* 5 */ TT_Custom								 					UMETA(DisplayName = "TT_Custom")
};

UENUM(BlueprintType)
enum class ETrackType : uint8
{
	/* 0 */ TT_None								 						UMETA(DisplayName = "TT_None"),
	/* 1 */ TT_Player								 					UMETA(DisplayName = "TT_Player"),
	/* 2 */ TT_ActorByTag								 				UMETA(DisplayName = "TT_ActorByTag")
};

UENUM(BlueprintType)
enum class EWeatherType : uint8
{
	/* 0 */ WT_Rain								 						UMETA(DisplayName = "WT_Rain"),
	/* 1 */ WT_Snow								 						UMETA(DisplayName = "WT_Snow"),
	/* 2 */ WT_Dust								 						UMETA(DisplayName = "WT_Dust")
};


UENUM(BlueprintType)
enum class ELockType : uint8
{
	/* 0 */ LT_None								 						UMETA(DisplayName = "LT_None"),
	/* 1 */ LT_TriggerToggle											UMETA(DisplayName = "LT_TriggerToggle"),
	/* 2 */ LT_TriggerControl											UMETA(DisplayName = "LT_TriggerControl")
};

UENUM(BlueprintType)
enum class ETriggerTriggerType : uint8
{
	/* 0 */ TT_Normal								 					UMETA(DisplayName = "TT_Normal"),
	/* 1 */ TT_Random								 					UMETA(DisplayName = "TT_Random"),
	/* 2 */ TT_Sequence								 					UMETA(DisplayName = "TT_Sequence")
};

UENUM(BlueprintType)
enum class EStartType : uint8
{
	/* 0 */ ST_None								 						UMETA(DisplayName = "ST_None"),
	/* 1 */ ST_SetOnStartup								 				UMETA(DisplayName = "ST_SetOnStartup"),
	/* 2 */ ST_UnSetOnStartup								 			UMETA(DisplayName = "ST_UnSetOnStartup")
};

UENUM(BlueprintType)
enum class ELadderClimbSound : uint8
{
	/* 0 */ CSOUND_Metal								 				UMETA(DisplayName = "CSOUND_Metal"),
	/* 1 */ CSOUND_Wood								 					UMETA(DisplayName = "CSOUND_Wood")
};

UENUM(BlueprintType)
enum class ENodeType : uint8
{
	/* 0 */ NT_Normal								 					UMETA(DisplayName = "NT_Normal"),
	/* 1 */ NT_Cover													UMETA(DisplayName = "NT_Cover"),
	/* 2 */ NT_Guard													UMETA(DisplayName = "NT_Guard"),
	/* 3 */ NT_Avoid													UMETA(DisplayName = "NT_Avoid")
};

UENUM(BlueprintType)
enum class EMentalStateAdjustor : uint8
{
	/* 0 */ msaBulletBuzz												UMETA(DisplayName = "msaBulletBuzz"),
	/* 1 */ msaUnknownMovementSound										UMETA(DisplayName = "msaUnknownMovementSound"),
	/* 2 */ msaEnemyInfantrySpotted										UMETA(DisplayName = "msaEnemyInfantrySpotted"),
	/* 3 */ msaEnemyRocketeerSpotted									UMETA(DisplayName = "msaEnemyRocketeerSpotted"),
	/* 4 */ msaEnemyVehicleSpotted										UMETA(DisplayName = "msaEnemyVehicleSpotted"),
	/* 5 */ msaFriendSpotted											UMETA(DisplayName = "msaFriendSpotted"),
	/* 6 */ msaFriendlyVehicleSpotted									UMETA(DisplayName = "msaFriendlyVehicleSpotted"),
	/* 7 */ msaWounded													UMETA(DisplayName = "msaWounded"),
	/* 8 */ msaGrenadeSpotted											UMETA(DisplayName = "msaGrenadeSpotted"),
	/* 9 */ msaGrenadeExploded											UMETA(DisplayName = "msaGrenadeExploded"),
	/* 10*/ msaGrenadeHeard												UMETA(DisplayName = "msaGrenadeHeard"),
	/* 11*/ msaFriendlyKilled											UMETA(DisplayName = "msaFriendlyKilled"),
	/* 12*/ msaEnemyKilled												UMETA(DisplayName = "msaEnemyKilled"),
	/* 13*/ msaQuietTimeRecovery										UMETA(DisplayName = "msaQuietTimeRecovery"),
	/* 14*/ msaQuietTimeRecoveryUnderCover								UMETA(DisplayName = "msaQuietTimeRecoveryUnderCover")
};
UENUM(BlueprintType)
enum class ETravelSpeed : uint8
{
	/* 0 */ TSCrawl														UMETA(DisplayName = "TSCrawl"),
	/* 1 */ TSCrouch													UMETA(DisplayName = "TSCrouch"),
	/* 2 */ TSWalk														UMETA(DisplayName = "TSWalk"),
	/* 3 */ TSRun														UMETA(DisplayName = "TSRun")
};




UENUM(BlueprintType)
enum class ENPCTacticalOrders : uint8
{
	/* 0 */ NPCTO_CeaseFire												UMETA(DisplayName = "NPCTO_CeaseFire"),
	/* 1 */ NPCTO_HoldFire												UMETA(DisplayName = "NPCTO_HoldFire"),
	/* 2 */ NPCTO_ControlledFire										UMETA(DisplayName = "NPCTO_ControlledFire"),
	/* 3 */ NPCTO_FreeFire												UMETA(DisplayName = "NPCTO_FreeFire")
};

UENUM(BlueprintType)
enum class ENPCOrders : uint8
{
	/* 0 */ NPCOrder_Patrol												UMETA(DisplayName = "NPCOrder_Patrol"),
	/* 1 */ NPCOrder_Guard												UMETA(DisplayName = "NPCOrder_Guard"),
	/* 2 */ NPCOrder_Ambush												UMETA(DisplayName = "NPCOrder_Ambush"),
	/* 3 */ NPCOrder_Harass												UMETA(DisplayName = "NPCOrder_Harass"),
	/* 4 */ NPCOrder_Assault											UMETA(DisplayName = "NPCOrder_Assault"),
};

UENUM(BlueprintType)
enum class ENPCVisionAbility : uint8
{
	/* 0 */	Vision_Custom												UMETA(DisplayName = "Vision_Custom"),
	/* 1 */ Vision_Perfect												UMETA(DisplayName = "Vision_Perfect"),
	/* 2 */ Vision_Excellent											UMETA(DisplayName = "Vision_Excellent"),
	/* 3 */ Vision_Superior												UMETA(DisplayName = "Vision_Superior"),
	/* 4 */ Vision_Good													UMETA(DisplayName = "Vision_Good"),
	/* 5 */ Vision_Average												UMETA(DisplayName = "Vision_Average"),
	/* 6 */ Vision_Poor													UMETA(DisplayName = "Vision_Poor"),
	/* 7 */ Vision_Bad													UMETA(DisplayName = "Vision_Bad"),
	/* 8 */ Vision_Blind												UMETA(DisplayName = "Vision_Blind")
};

UENUM(BlueprintType)
enum class ETargetType : uint8
{
	/* 0 */ TT_BlueFor													UMETA(DisplayName = "TT_BlueFor"),
	/* 1 */ TT_OpFor													UMETA(DisplayName = "TT_OpFor"),
	/* 2 */ TT_Indig													UMETA(DisplayName = "TT_Indig"),
	/* 3 */ TT_Civ														UMETA(DisplayName = "TT_Civ")
};

UENUM(BlueprintType)
enum class EPostureSetting : uint8
{
	/* 0 */ PS_UNCHANGED												UMETA(DisplayName = "PS_UNCHANGED"),
	/* 1 */ PS_STAND													UMETA(DisplayName = "PS_STAND"),
	/* 2 */ PS_CROUCH													UMETA(DisplayName = "PS_CROUCH"),
	/* 3 */ PS_PRONE													UMETA(DisplayName = "PS_PRONE")
};

UENUM(BlueprintType)
enum class EVoiceType : uint8
{
	/* 0 */ VT_None														UMETA(DisplayName = "VT_None"),
	/* 1 */ VT_Leader													UMETA(DisplayName = "VT_Leader"),
	/* 2 */ VT_Commander												UMETA(DisplayName = "VT_Commander"),
	/* 3 */ VT_Sergeant													UMETA(DisplayName = "VT_Sergeant"),
	/* 4 */ VT_Weapons													UMETA(DisplayName = "VT_Weapons"),
	/* 5 */ VT_Engineer													UMETA(DisplayName = "VT_Engineer"),
	/* 6 */ VT_Medical													UMETA(DisplayName = "VT_Medical"),
	/* 7 */ VT_Communication											UMETA(DisplayName = "VT_Communication"),
	/* 8 */ VT_Intelligence												UMETA(DisplayName = "VT_Intelligence"),
	/* 9 */ VT_StudentVendingMachine									UMETA(DisplayName = "VT_StudentVendingMachine"),
	/* 10*/ VT_Sarg														UMETA(DisplayName = "VT_Sarg"),
};


UENUM(BlueprintType)
enum class EAnimateType : uint8
{
	/* 0 */ ANIMATE_None												UMETA(DisplayName = "ANIMATE_None"),
	/* 1 */ ANIMATE_Talk												UMETA(DisplayName = "ANIMATE_Talk"),
	/* 2 */ ANIMATE_TalkHands											UMETA(DisplayName = "ANIMATE_TalkHands"),
	/* 3 */ ANIMATE_TalkHandsRandom										UMETA(DisplayName = "ANIMATE_TalkHandsRandom"),
	/* 4 */ ANIMATE_DrillIdle											UMETA(DisplayName = "ANIMATE_DrillIdle")
};



UENUM(BlueprintType)
enum class ESoundSlot : uint8
{
	/* 0 */ SLOT_None													UMETA(DisplayName = "SLOT_None"),
	/* 1 */ SLOT_Misc													UMETA(DisplayName = "SLOT_Misc"),
	/* 2 */ SLOT_Pain													UMETA(DisplayName = "SLOT_Pain"),
	/* 3 */ SLOT_Interact												UMETA(DisplayName = "SLOT_Interact"),
	/* 4 */ SLOT_Ambient												UMETA(DisplayName = "SLOT_Ambient"),
	/* 5 */ SLOT_Talk													UMETA(DisplayName = "SLOT_Talk"),
	/* 6 */ SLOT_Interface												UMETA(DisplayName = "SLOT_Interface")
};


UENUM(BlueprintType)
enum class EComparison : uint8
{
	/* 0 */ EC_None														UMETA(DisplayName = "EC_None"),
	/* 1 */ EC_EQ														UMETA(DisplayName = "EC_EQ"),
	/* 2 */ EC_NEQ														UMETA(DisplayName = "EC_NEQ"),
	/* 3 */ EC_GT														UMETA(DisplayName = "EC_GT"),
	/* 4 */ EC_GTE														UMETA(DisplayName = "EC_GTE"),
	/* 5 */ EC_LT														UMETA(DisplayName = "EC_LT"),
	/* 6 */ EC_LTE														UMETA(DisplayName = "EC_LTE")
};


UENUM(BlueprintType)
enum class EDisplayState : uint8
{
	/* 0 */ DS_Delay													UMETA(DisplayName = "DS_Delay"),
	/* 0 */ DS_Visibility												UMETA(DisplayName = "DS_Visibility"),
	/* 0 */ DS_Stopped													UMETA(DisplayName = "DS_Stopped")
};

UENUM(BlueprintType)
enum class EClickSound : uint8
{
	/* 0 */ CS_None														UMETA(DisplayName = "CS_None"),
	/* 1 */ CS_Click													UMETA(DisplayName = "CS_Click"),
	/* 2 */ CS_Edit														UMETA(DisplayName = "CS_Edit"),
	/* 3 */ CS_Up														UMETA(DisplayName = "CS_Up"),
	/* 4 */ CS_Down														UMETA(DisplayName = "CS_Down"),
	/* 5 */ CS_Drag														UMETA(DisplayName = "CS_Drag"),
	/* 6 */ CS_Fade														UMETA(DisplayName = "CS_Fade"),
	/* 7 */ CS_Hover													UMETA(DisplayName = "CS_Hover"),
	/* 8 */ CS_Slide													UMETA(DisplayName = "CS_Slide")
};

UENUM(BlueprintType)
enum class EParentScaleType : uint8
{
	/* 0 */ SCALE_All													UMETA(DisplayName = "SCALE_All"),
	/* 1 */ SCALE_X														UMETA(DisplayName = "SCALE_X"),
	/* 2 */ SCALE_Y														UMETA(DisplayName = "SCALE_Y")
};


UENUM(BlueprintType)
enum class EInputKey : uint8
{
	/* 000 */ IK_None													UMETA(DisplayName = "IK_None"),
	/* 001 */ IK_LeftMouse												UMETA(DisplayName = "IK_LeftMouse"),
	/* 002 */ IK_RightMouse												UMETA(DisplayName = "IK_RightMouse"),
	/* 003 */ IK_Cancel													UMETA(DisplayName = "IK_Cancel"),
	/* 004 */ IK_MiddleMouse											UMETA(DisplayName = "IK_MiddleMouse"),
	/* 005 */ IK_Unknown05												UMETA(DisplayName = "IK_Unknown05"),
	/* 006 */ IK_Unknown06												UMETA(DisplayName = "IK_Unknown06"),
	/* 007 */ IK_Unknown07												UMETA(DisplayName = "IK_Unknown07"),
	/* 008 */ IK_Backspace												UMETA(DisplayName = "IK_Backspace"),
	/* 009 */ IK_Tab													UMETA(DisplayName = "IK_Tab"),
	/* 010 */ IK_Unknown0A												UMETA(DisplayName = "IK_Unknown0A"),
	/* 011 */ IK_Unknown0B												UMETA(DisplayName = "IK_Unknown0B"),
	/* 012 */ IK_Unknown0C												UMETA(DisplayName = "IK_Unknown0C"),
	/* 013 */ IK_Enter													UMETA(DisplayName = "IK_Enter"),
	/* 014 */ IK_Unknown0E												UMETA(DisplayName = "IK_Unknown0E"),
	/* 015 */ IK_Unknown0F												UMETA(DisplayName = "IK_Unknown0F"),
	/* 016 */ IK_Shift													UMETA(DisplayName = "IK_Shift"),
	/* 017 */ IK_Ctrl													UMETA(DisplayName = "IK_Ctrl"),
	/* 018 */ IK_Alt													UMETA(DisplayName = "IK_Alt"),
	/* 019 */ IK_Pause													UMETA(DisplayName = "IK_Pause"),
	/* 020 */ IK_CapsLock												UMETA(DisplayName = "IK_CapsLock"),
	/* 021 */ IK_Unknown15												UMETA(DisplayName = "IK_Unknown15"),
	/* 022 */ IK_Unknown16												UMETA(DisplayName = "IK_Unknown16"),
	/* 023 */ IK_Unknown17												UMETA(DisplayName = "IK_Unknown17"),
	/* 024 */ IK_Unknown18												UMETA(DisplayName = "IK_Unknown18"),
	/* 025 */ IK_Unknown19												UMETA(DisplayName = "IK_Unknown19"),
	/* 026 */ IK_Unknown1A												UMETA(DisplayName = "IK_Unknown1A"),
	/* 027 */ IK_Escape													UMETA(DisplayName = "IK_Escape"),
	/* 028 */ IK_Unknown1C												UMETA(DisplayName = "IK_Unknown1C"),
	/* 029 */ IK_Unknown1D												UMETA(DisplayName = "IK_Unknown1D"),
	/* 030 */ IK_Unknown1E												UMETA(DisplayName = "IK_Unknown1E"),
	/* 031 */ IK_Unknown1F												UMETA(DisplayName = "IK_Unknown1F"),
	/* 032 */ IK_Space													UMETA(DisplayName = "IK_Space"),
	/* 033 */ IK_PageUp													UMETA(DisplayName = "IK_PageUp"),
	/* 034 */ IK_PageDown												UMETA(DisplayName = "IK_PageDown"),
	/* 035 */ IK_End													UMETA(DisplayName = "IK_End"),
	/* 036 */ IK_Home													UMETA(DisplayName = "IK_Home"),
	/* 037 */ IK_Left													UMETA(DisplayName = "IK_Left"),
	/* 038 */ IK_Up														UMETA(DisplayName = "IK_Up"),
	/* 039 */ IK_Right													UMETA(DisplayName = "IK_Right"),
	/* 040 */ IK_Down													UMETA(DisplayName = "IK_Down"),
	/* 041 */ IK_Select													UMETA(DisplayName = "IK_Select"),
	/* 042 */ IK_Print													UMETA(DisplayName = "IK_Print"),
	/* 043 */ IK_Execute												UMETA(DisplayName = "IK_Execute"),
	/* 044 */ IK_PrintScrn												UMETA(DisplayName = "IK_PrintScrn"),
	/* 045 */ IK_Insert													UMETA(DisplayName = "IK_Insert"),
	/* 046 */ IK_Delete													UMETA(DisplayName = "IK_Delete"),
	/* 047 */ IK_Help													UMETA(DisplayName = "IK_Help"),
	/* 048 */ IK_0														UMETA(DisplayName = "IK_0"),
	/* 049 */ IK_1														UMETA(DisplayName = "IK_1"),
	/* 050 */ IK_2														UMETA(DisplayName = "IK_2"),
	/* 051 */ IK_3														UMETA(DisplayName = "IK_3"),
	/* 052 */ IK_4														UMETA(DisplayName = "IK_4"),
	/* 053 */ IK_5														UMETA(DisplayName = "IK_5"),
	/* 054 */ IK_6														UMETA(DisplayName = "IK_6"),
	/* 055 */ IK_7														UMETA(DisplayName = "IK_7"),
	/* 056 */ IK_8														UMETA(DisplayName = "IK_8"),
	/* 057 */ IK_9														UMETA(DisplayName = "IK_9"),
	/* 058 */ IK_Unknown3A												UMETA(DisplayName = "IK_Unknown3A"),
	/* 059 */ IK_Unknown3B												UMETA(DisplayName = "IK_Unknown3B"),
	/* 060 */ IK_Unknown3C												UMETA(DisplayName = "IK_Unknown3C"),
	/* 061 */ IK_Unknown3D												UMETA(DisplayName = "IK_Unknown3D"),
	/* 062 */ IK_Unknown3E												UMETA(DisplayName = "IK_Unknown3E"),
	/* 063 */ IK_Unknown3F												UMETA(DisplayName = "IK_Unknown3F"),
	/* 064 */ IK_Unknown40												UMETA(DisplayName = "IK_Unknown40"),
	/* 065 */ IK_A														UMETA(DisplayName = "IK_A"),
	/* 066 */ IK_B														UMETA(DisplayName = "IK_B"),
	/* 067 */ IK_C														UMETA(DisplayName = "IK_C"),
	/* 068 */ IK_D														UMETA(DisplayName = "IK_D"),
	/* 069 */ IK_E														UMETA(DisplayName = "IK_E"),
	/* 070 */ IK_F														UMETA(DisplayName = "IK_F"),
	/* 071 */ IK_G														UMETA(DisplayName = "IK_G"),
	/* 072 */ IK_H														UMETA(DisplayName = "IK_H"),
	/* 073 */ IK_I														UMETA(DisplayName = "IK_I"),
	/* 074 */ IK_J														UMETA(DisplayName = "IK_J"),
	/* 075 */ IK_K														UMETA(DisplayName = "IK_K"),
	/* 076 */ IK_L														UMETA(DisplayName = "IK_L"),
	/* 077 */ IK_M														UMETA(DisplayName = "IK_M"),
	/* 078 */ IK_N														UMETA(DisplayName = "IK_N"),
	/* 079 */ IK_O														UMETA(DisplayName = "IK_O"),
	/* 080 */ IK_P														UMETA(DisplayName = "IK_P"),
	/* 081 */ IK_Q														UMETA(DisplayName = "IK_Q"),
	/* 082 */ IK_R														UMETA(DisplayName = "IK_R"),
	/* 083 */ IK_S														UMETA(DisplayName = "IK_S"),
	/* 084 */ IK_T														UMETA(DisplayName = "IK_T"),
	/* 085 */ IK_U														UMETA(DisplayName = "IK_U"),
	/* 086 */ IK_V														UMETA(DisplayName = "IK_V"),
	/* 087 */ IK_W														UMETA(DisplayName = "IK_W"),
	/* 088 */ IK_X														UMETA(DisplayName = "IK_X"),
	/* 089 */ IK_Y														UMETA(DisplayName = "IK_Y"),
	/* 090 */ IK_Z														UMETA(DisplayName = "IK_Z"),
	/* 091 */ IK_Unknown5B												UMETA(DisplayName = "IK_Unknown5B"),
	/* 092 */ IK_Unknown5C												UMETA(DisplayName = "IK_Unknown5C"),
	/* 093 */ IK_Unknown5D												UMETA(DisplayName = "IK_Unknown5D"),
	/* 094 */ IK_Unknown5E												UMETA(DisplayName = "IK_Unknown5E"),
	/* 095 */ IK_Unknown5F												UMETA(DisplayName = "IK_Unknown5F"),
	/* 096 */ IK_NumPad0												UMETA(DisplayName = "IK_NumPad0"),
	/* 097 */ IK_NumPad1												UMETA(DisplayName = "IK_NumPad1"),
	/* 098 */ IK_NumPad2												UMETA(DisplayName = "IK_NumPad2"),
	/* 099 */ IK_NumPad3												UMETA(DisplayName = "IK_NumPad3"),
	/* 100 */ IK_NumPad4												UMETA(DisplayName = "IK_NumPad4"),
	/* 101 */ IK_NumPad5												UMETA(DisplayName = "IK_NumPad5"),
	/* 102 */ IK_NumPad6												UMETA(DisplayName = "IK_NumPad6"),
	/* 103 */ IK_NumPad7												UMETA(DisplayName = "IK_NumPad7"),
	/* 104 */ IK_NumPad8												UMETA(DisplayName = "IK_NumPad8"),
	/* 105 */ IK_NumPad9												UMETA(DisplayName = "IK_NumPad9"),
	/* 106 */ IK_GreyStar												UMETA(DisplayName = "IK_GreyStar"),
	/* 107 */ IK_GreyPlus												UMETA(DisplayName = "IK_GreyPlus"),
	/* 108 */ IK_Separator												UMETA(DisplayName = "IK_Separator"),
	/* 109 */ IK_GreyMinus												UMETA(DisplayName = "IK_GreyMinus"),
	/* 110 */ IK_NumPadPeriod											UMETA(DisplayName = "IK_NumPadPeriod"),
	/* 111 */ IK_GreySlash												UMETA(DisplayName = "IK_GreySlash"),
	/* 112 */ IK_F1														UMETA(DisplayName = "IK_F1"),
	/* 113 */ IK_F2														UMETA(DisplayName = "IK_F2"),
	/* 114 */ IK_F3														UMETA(DisplayName = "IK_F3"),
	/* 115 */ IK_F4														UMETA(DisplayName = "IK_F4"),
	/* 116 */ IK_F5														UMETA(DisplayName = "IK_F5"),
	/* 117 */ IK_F6														UMETA(DisplayName = "IK_F6"),
	/* 118 */ IK_F7														UMETA(DisplayName = "IK_F7"),
	/* 119 */ IK_F8														UMETA(DisplayName = "IK_F8"),
	/* 120 */ IK_F9														UMETA(DisplayName = "IK_F9"),
	/* 121 */ IK_F10													UMETA(DisplayName = "IK_F10"),
	/* 122 */ IK_F11													UMETA(DisplayName = "IK_F11"),
	/* 123 */ IK_F12													UMETA(DisplayName = "IK_F12"),
	/* 124 */ IK_F13													UMETA(DisplayName = "IK_F13"),
	/* 125 */ IK_F14													UMETA(DisplayName = "IK_F14"),
	/* 126 */ IK_F15													UMETA(DisplayName = "IK_F15"),
	/* 127 */ IK_F16													UMETA(DisplayName = "IK_F16"),
	/* 128 */ IK_F17													UMETA(DisplayName = "IK_F17"),
	/* 129 */ IK_F18													UMETA(DisplayName = "IK_F18"),
	/* 130 */ IK_F19													UMETA(DisplayName = "IK_F19"),
	/* 131 */ IK_F20													UMETA(DisplayName = "IK_F20"),
	/* 132 */ IK_F21													UMETA(DisplayName = "IK_F21"),
	/* 133 */ IK_F22													UMETA(DisplayName = "IK_F22"),
	/* 134 */ IK_F23													UMETA(DisplayName = "IK_F23"),
	/* 135 */ IK_F24													UMETA(DisplayName = "IK_F24"),
	/* 136 */ IK_Unknown88												UMETA(DisplayName = "IK_Unknown88"),
	/* 137 */ IK_Unknown89												UMETA(DisplayName = "IK_Unknown89"),
	/* 138 */ IK_Unknown8A												UMETA(DisplayName = "IK_Unknown8A"),
	/* 139 */ IK_Unknown8B												UMETA(DisplayName = "IK_Unknown8B"),
	/* 140 */ IK_Unknown8C												UMETA(DisplayName = "IK_Unknown8C"),
	/* 141 */ IK_Unknown8D												UMETA(DisplayName = "IK_Unknown8D"),
	/* 142 */ IK_Unknown8E												UMETA(DisplayName = "IK_Unknown8E"),
	/* 143 */ IK_Unknown8F												UMETA(DisplayName = "IK_Unknown8F"),
	/* 144 */ IK_NumLock												UMETA(DisplayName = "IK_NumLock"),
	/* 145 */ IK_ScrollLock												UMETA(DisplayName = "IK_ScrollLock"),
	/* 146 */ IK_TRACKIR_PITCHUP										UMETA(DisplayName = "IK_TRACKIR_PITCHUP"),
	/* 147 */ IK_TRACKIR_PITCHDOWN										UMETA(DisplayName = "IK_TRACKIR_PITCHDOWN"),
	/* 148 */ IK_TRACKIR_YAWRIGHT										UMETA(DisplayName = "IK_TRACKIR_YAWRIGHT"),
	/* 149 */ IK_TRACKIR_YAWLEFT										UMETA(DisplayName = "IK_TRACKIR_YAWLEFT"),
	/* 150 */ IK_TRACKIR_ROLLRIGHT										UMETA(DisplayName = "IK_TRACKIR_ROLLRIGHT"),
	/* 151 */ IK_TRACKIR_ROLLLEFT										UMETA(DisplayName = "IK_TRACKIR_ROLLLEFT"),
	/* 152 */ IK_TRACKIR_MOVEUP											UMETA(DisplayName = "IK_TRACKIR_MOVEUP"),
	/* 153 */ IK_TRACKIR_MOVEDOWN										UMETA(DisplayName = "IK_TRACKIR_MOVEDOWN"),
	/* 154 */ IK_TRACKIR_MOVELEFT										UMETA(DisplayName = "IK_TRACKIR_MOVELEFT"),
	/* 155 */ IK_TRACKIR_MOVERIGHT										UMETA(DisplayName = "IK_TRACKIR_MOVERIGHT"),
	/* 156 */ IK_TRACKIR_MOVEFORWARD									UMETA(DisplayName = "IK_TRACKIR_MOVEFORWARD"),
	/* 157 */ IK_TRACKIR_MOVEBACKWARD									UMETA(DisplayName = "IK_TRACKIR_MOVEBACKWARD"),
	/* 158 */ IK_Unknown9E												UMETA(DisplayName = "IK_Unknown9E"),
	/* 159 */ IK_Unknown9F												UMETA(DisplayName = "IK_Unknown9F"),
	/* 160 */ IK_LShift													UMETA(DisplayName = "IK_LShift"),
	/* 161 */ IK_RShift													UMETA(DisplayName = "IK_RShift"),
	/* 162 */ IK_LControl												UMETA(DisplayName = "IK_LControl"),
	/* 163 */ IK_RControl												UMETA(DisplayName = "IK_RControl"),
	/* 164 */ IK_UnknownA4												UMETA(DisplayName = "IK_UnknownA4"),
	/* 165 */ IK_UnknownA5												UMETA(DisplayName = "IK_UnknownA5"),
	/* 166 */ IK_UnknownA6												UMETA(DisplayName = "IK_UnknownA6"),
	/* 167 */ IK_UnknownA7												UMETA(DisplayName = "IK_UnknownA7"),
	/* 168 */ IK_UnknownA8												UMETA(DisplayName = "IK_UnknownA8"),
	/* 169 */ IK_UnknownA9												UMETA(DisplayName = "IK_UnknownA9"),
	/* 170 */ IK_UnknownAA												UMETA(DisplayName = "IK_UnknownAA"),
	/* 171 */ IK_UnknownAB												UMETA(DisplayName = "IK_UnknownAB"),
	/* 172 */ IK_UnknownAC												UMETA(DisplayName = "IK_UnknownAC"),
	/* 173 */ IK_UnknownAD												UMETA(DisplayName = "IK_UnknownAD"),
	/* 174 */ IK_UnknownAE												UMETA(DisplayName = "IK_UnknownAE"),
	/* 175 */ IK_UnknownAF												UMETA(DisplayName = "IK_UnknownAF"),
	/* 176 */ IK_UnknownB0												UMETA(DisplayName = "IK_UnknownB0"),
	/* 177 */ IK_UnknownB1												UMETA(DisplayName = "IK_UnknownB1"),
	/* 178 */ IK_UnknownB2												UMETA(DisplayName = "IK_UnknownB2"),
	/* 179 */ IK_UnknownB3												UMETA(DisplayName = "IK_UnknownB3"),
	/* 180 */ IK_UnknownB4												UMETA(DisplayName = "IK_UnknownB4"),
	/* 181 */ IK_UnknownB5												UMETA(DisplayName = "IK_UnknownB5"),
	/* 182 */ IK_UnknownB6												UMETA(DisplayName = "IK_UnknownB6"),
	/* 183 */ IK_UnknownB7												UMETA(DisplayName = "IK_UnknownB7"),
	/* 184 */ IK_UnknownB8												UMETA(DisplayName = "IK_UnknownB8"),
	/* 185 */ IK_Unicode												UMETA(DisplayName = "IK_Unicode"),
	/* 186 */ IK_Semicolon												UMETA(DisplayName = "IK_Semicolon"),
	/* 187 */ IK_Equals													UMETA(DisplayName = "IK_Equals"),
	/* 188 */ IK_Comma													UMETA(DisplayName = "IK_Comma"),
	/* 189 */ IK_Minus													UMETA(DisplayName = "IK_Minus"),
	/* 190 */ IK_Period													UMETA(DisplayName = "IK_Period"),
	/* 191 */ IK_Slash													UMETA(DisplayName = "IK_Slash"),
	/* 192 */ IK_Tilde													UMETA(DisplayName = "IK_Tilde"),
	/* 193 */ IK_Mouse4													UMETA(DisplayName = "IK_Mouse4"),
	/* 194 */ IK_Mouse5													UMETA(DisplayName = "IK_Mouse5"),
	/* 195 */ IK_Mouse6													UMETA(DisplayName = "IK_Mouse6"),
	/* 196 */ IK_Mouse7													UMETA(DisplayName = "IK_Mouse7"),
	/* 197 */ IK_Mouse8													UMETA(DisplayName = "IK_Mouse8"),
	/* 198 */ IK_UnknownC6												UMETA(DisplayName = "IK_UnknownC6"),
	/* 199 */ IK_UnknownC7												UMETA(DisplayName = "IK_UnknownC7"),
	/* 200 */ IK_Joy1													UMETA(DisplayName = "IK_Joy1"),
	/* 201 */ IK_Joy2													UMETA(DisplayName = "IK_Joy2"),
	/* 202 */ IK_Joy3													UMETA(DisplayName = "IK_Joy3"),
	/* 203 */ IK_Joy4													UMETA(DisplayName = "IK_Joy4"),
	/* 204 */ IK_Joy5													UMETA(DisplayName = "IK_Joy5"),
	/* 205 */ IK_Joy6													UMETA(DisplayName = "IK_Joy6"),
	/* 206 */ IK_Joy7													UMETA(DisplayName = "IK_Joy7"),
	/* 207 */ IK_Joy8													UMETA(DisplayName = "IK_Joy8"),
	/* 208 */ IK_Joy9													UMETA(DisplayName = "IK_Joy9"),
	/* 209 */ IK_Joy10													UMETA(DisplayName = "IK_Joy10"),
	/* 210 */ IK_Joy11													UMETA(DisplayName = "IK_Joy11"),
	/* 211 */ IK_Joy12													UMETA(DisplayName = "IK_Joy12"),
	/* 212 */ IK_Joy13													UMETA(DisplayName = "IK_Joy13"),
	/* 213 */ IK_Joy14													UMETA(DisplayName = "IK_Joy14"),
	/* 214 */ IK_Joy15													UMETA(DisplayName = "IK_Joy15"),
	/* 215 */ IK_Joy16													UMETA(DisplayName = "IK_Joy16"),
	/* 216 */ IK_UnknownD8												UMETA(DisplayName = "IK_UnknownD8"),
	/* 217 */ IK_UnknownD9												UMETA(DisplayName = "IK_UnknownD9"),
	/* 218 */ IK_UnknownDA												UMETA(DisplayName = "IK_UnknownDA"),
	/* 219 */ IK_LeftBracket											UMETA(DisplayName = "IK_LeftBracket"),
	/* 220 */ IK_Backslash												UMETA(DisplayName = "IK_Backslash"),
	/* 221 */ IK_RightBracket											UMETA(DisplayName = "IK_RightBracket"),
	/* 222 */ IK_SingleQuote											UMETA(DisplayName = "IK_SingleQuote"),
	/* 223 */ IK_UnknownDF												UMETA(DisplayName = "IK_UnknownDF"),
	/* 224 */ IK_UnknownE0												UMETA(DisplayName = "IK_UnknownE0"),
	/* 225 */ IK_UnknownE1												UMETA(DisplayName = "IK_UnknownE1"),
	/* 226 */ IK_UnknownE2												UMETA(DisplayName = "IK_UnknownE2"),
	/* 227 */ IK_UnknownE3												UMETA(DisplayName = "IK_UnknownE3"),
	/* 228 */ IK_MouseX													UMETA(DisplayName = "IK_MouseX"),
	/* 229 */ IK_MouseY													UMETA(DisplayName = "IK_MouseY"),
	/* 230 */ IK_MouseZ													UMETA(DisplayName = "IK_MouseZ"),
	/* 231 */ IK_MouseW													UMETA(DisplayName = "IK_MouseW"),
	/* 232 */ IK_JoyU													UMETA(DisplayName = "IK_JoyU"),
	/* 233 */ IK_JoyV													UMETA(DisplayName = "IK_JoyV"),
	/* 234 */ IK_JoySlider1												UMETA(DisplayName = "IK_JoySlider1"),
	/* 235 */ IK_JoySlider2												UMETA(DisplayName = "IK_JoySlider2"),
	/* 236 */ IK_MouseWheelUp											UMETA(DisplayName = "IK_MouseWheelUp"),
	/* 237 */ IK_MouseWheelDown											UMETA(DisplayName = "IK_MouseWheelDown"),
	/* 238 */ IK_Unknown10E												UMETA(DisplayName = "IK_Unknown10E"),
	/* 239 */ UK_Unknown10F												UMETA(DisplayName = "UK_Unknown10F"),
	/* 240 */ IK_JoyX													UMETA(DisplayName = "IK_JoyX"),
	/* 241 */ IK_JoyY													UMETA(DisplayName = "IK_JoyY"),
	/* 242 */ IK_JoyZ													UMETA(DisplayName = "IK_JoyZ"),
	/* 243 */ IK_JoyR													UMETA(DisplayName = "IK_JoyR"),
	/* 244 */ IK_UnknownF4												UMETA(DisplayName = "IK_UnknownF4"),
	/* 245 */ IK_UnknownF5												UMETA(DisplayName = "IK_UnknownF5"),
	/* 246 */ IK_Attn													UMETA(DisplayName = "IK_Attn"),
	/* 247 */ IK_CrSel													UMETA(DisplayName = "IK_CrSel"),
	/* 248 */ IK_ExSel													UMETA(DisplayName = "IK_ExSel"),
	/* 249 */ IK_ErEof													UMETA(DisplayName = "IK_ErEof"),
	/* 250 */ IK_Play													UMETA(DisplayName = "IK_Play"),
	/* 251 */ IK_Zoom													UMETA(DisplayName = "IK_Zoom"),
	/* 252 */ IK_NoName													UMETA(DisplayName = "IK_NoName"),
	/* 253 */ IK_PA1													UMETA(DisplayName = "IK_PA1"),
	/* 254 */ IK_OEMClear												UMETA(DisplayName = "IK_OEMClear"),

};

UENUM(BlueprintType)
enum class EStreamFinishReason : uint8
{
	/* 0 */ STREAMFINISH_EOF											UMETA(DisplayName = "STREAMFINISH_EOF"),
	/* 1 */ STREAMFINISH_Error											UMETA(DisplayName = "STREAMFINISH_Error"),
};
UENUM(BlueprintType)
enum class EInputAction : uint8
{
	/* 0 */ IST_None													UMETA(DisplayName = "IST_None"),
	/* 1 */ IST_Press													UMETA(DisplayName = "IST_Press"),
	/* 2 */ IST_Hold													UMETA(DisplayName = "IST_Hold"),
	/* 3 */ IST_Release													UMETA(DisplayName = "IST_Release"),
	/* 4 */ IST_Axis													UMETA(DisplayName = "IST_Axis")
};

UENUM(BlueprintType)
enum class EMenuState : uint8
{
	/* 0 */ MSAT_Blurry													UMETA(DisplayName = "MSAT_Blurry"),
	/* 1 */ MSAT_Watched												UMETA(DisplayName = "MSAT_Watched"),
	/* 2 */ MSAT_Focused												UMETA(DisplayName = "MSAT_Focused"),
	/* 3 */ MSAT_Pressed												UMETA(DisplayName = "MSAT_Pressed"),
	/* 4 */ MSAT_Disabled												UMETA(DisplayName = "MSAT_Disabled")
};

UENUM(BlueprintType)
enum class EImgStyle : uint8
{
	/* 0 */ ISTY_Normal													UMETA(DisplayName = "ISTY_Normal"),
	/* 1 */ ISTY_Stretched												UMETA(DisplayName = "ISTY_Stretched"),
	/* 2 */ ISTY_Scaled													UMETA(DisplayName = "ISTY_Scaled"),
	/* 3 */ ISTY_Bound													UMETA(DisplayName = "ISTY_Bound"),
	/* 4 */ ISTY_Justified												UMETA(DisplayName = "ISTY_Justified"),
	/* 5 */ ISTY_PartialScaled											UMETA(DisplayName = "ISTY_PartialScaled"),
	/* 6 */ ISTY_Tiled													UMETA(DisplayName = "ISTY_Tiled")
};

UENUM(BlueprintType)
enum class EMenuRenderStyle : uint8
{
	/* 0 */ MSTY_None													UMETA(DisplayName = "MSTY_None"),
	/* 1 */ MSTY_Normal													UMETA(DisplayName = "MSTY_Normal"),
	/* 2 */ MSTY_Masked													UMETA(DisplayName = "MSTY_Masked"),
	/* 3 */ MSTY_Translucent											UMETA(DisplayName = "MSTY_Translucent"),
	/* 4 */ MSTY_Modulated												UMETA(DisplayName = "MSTY_Modulated"),
	/* 5 */ MSTY_Alpha													UMETA(DisplayName = "MSTY_Alpha"),
	/* 6 */ MSTY_Additive												UMETA(DisplayName = "MSTY_Additive"),
	/* 7 */ MSTY_Subtractive											UMETA(DisplayName = "MSTY_Subtractive"),
	/* 8 */ MSTY_Particle												UMETA(DisplayName = "MSTY_Particle"),
	/* 9 */ MSTY_AlphaZ													UMETA(DisplayName = "MSTY_AlphaZ")
};

UENUM(BlueprintType)
enum class EAnimationType : uint8
{
	/* 0 */ AT_Position													UMETA(DisplayName = "AT_Position"),
	/* 1 */ AT_Dimension												UMETA(DisplayName = "AT_Dimension")
};

UENUM(BlueprintType)
enum class EDropState : uint8
{
	/* 0 */ DRP_None													UMETA(DisplayName = "DRP_None"),
	/* 1 */ DRP_Source													UMETA(DisplayName = "DRP_Source"),
	/* 2 */ DRP_Target													UMETA(DisplayName = "DRP_Target"),
	/* 3 */ DRP_Accept													UMETA(DisplayName = "DRP_Accept"),
	/* 4 */ DRP_Reject													UMETA(DisplayName = "DRP_Reject")
};

UENUM(BlueprintType)
enum class ECellStyle : uint8
{
	/* 0 */ CELL_FixedSize												UMETA(DisplayName = "CELL_FixedSize"),
	/* 1 */ CELL_FixedCount												UMETA(DisplayName = "CELL_FixedCount")
};

UENUM(BlueprintType)
enum class ETextCase : uint8
{
	/* 0 */ TXTC_None													UMETA(DisplayName = "TXTC_None"),
	/* 1 */ TXTC_Upper													UMETA(DisplayName = "TXTC_Upper"),
	/* 2 */ TXTC_Lower													UMETA(DisplayName = "TXTC_Lower")
};

UENUM(BlueprintType)
enum class EImgAlign : uint8
{
	/* 0 */ IMGA_TopLeft												UMETA(DisplayName = "IMGA_TopLeft"),
	/* 1 */ IMGA_Center													UMETA(DisplayName = "IMGA_Center"),
	/* 2 */ IMGA_BottomRight											UMETA(DisplayName = "IMGA_BottomRight")
};

UENUM(BlueprintType)
enum class EIconPosition : uint8
{
	/* 0 */ ICP_Normal													UMETA(DisplayName = "ICP_Normal"),
	/* 1 */ ICP_Center													UMETA(DisplayName = "ICP_Center"),
	/* 2 */ ICP_Scaled													UMETA(DisplayName = "ICP_Scaled"),
	/* 3 */ ICP_Stretched												UMETA(DisplayName = "ICP_Stretched"),
	/* 4 */ ICP_Bound													UMETA(DisplayName = "ICP_Bound")
};

UENUM(BlueprintType)
enum class EPageAlign : uint8
{
	/* 0 */ PGA_None													UMETA(DisplayName = "PGA_None"),
	/* 1 */ PGA_Client													UMETA(DisplayName = "PGA_Client"),
	/* 2 */ PGA_Left													UMETA(DisplayName = "PGA_Left"),
	/* 3 */ PGA_Right													UMETA(DisplayName = "PGA_Right"),
	/* 4 */ PGA_Top														UMETA(DisplayName = "PGA_Top"),
	/* 5 */ PGA_Bottom													UMETA(DisplayName = "PGA_Bottom")
};

UENUM(BlueprintType)
enum class EeDrawDirection : uint8
{
	/* 0 */ DRD_LeftToRight												UMETA(DisplayName = "DRD_LeftToRight"),
	/* 1 */ DRD_RightToLeft												UMETA(DisplayName = "DRD_RightToLeft"),
	/* 2 */ DRD_TopToBottom												UMETA(DisplayName = "DRD_TopToBottom"),
	/* 3 */ DRD_BottomToTop												UMETA(DisplayName = "DRD_BottomToTop")
};

UENUM(BlueprintType)
enum class EEditMask : uint8
{
	/* 0 */ EDM_None													UMETA(DisplayName = "EDM_None"),
	/* 1 */ EDM_Alpha													UMETA(DisplayName = "EDM_Alpha"),
	/* 2 */ EDM_Numeric													UMETA(DisplayName = "EDM_Numeric")
};

UENUM(BlueprintType)
enum class ELinkState : uint8
{
	/* 0 */ STATE_Initialized											UMETA(DisplayName = "STATE_Initialized"),
	/* 1 */ STATE_Ready													UMETA(DisplayName = "STATE_Ready"),
	/* 2 */ STATE_Listening												UMETA(DisplayName = "STATE_Listening"),
	/* 3 */ STATE_Connecting											UMETA(DisplayName = "STATE_Connecting"),
	/* 4 */ STATE_Connected												UMETA(DisplayName = "STATE_Connected"),
	/* 5 */ STATE_ListenClosePending									UMETA(DisplayName = "STATE_ListenClosePending"),
	/* 6 */ STATE_ConnectClosePending									UMETA(DisplayName = "STATE_ConnectClosePending"),
	/* 7 */ STATE_ListenClosing											UMETA(DisplayName = "STATE_ListenClosing"),
	/* 8 */ STATE_ConnectClosing										UMETA(DisplayName = "STATE_ConnectClosing")
};

UENUM(BlueprintType)
enum class EDrawPivot : uint8
{
	/* 0 */ DP_UpperLeft												UMETA(DisplayName = "DP_UpperLeft"),
	/* 1 */ DP_UpperMiddle												UMETA(DisplayName = "DP_UpperMiddle"),
	/* 2 */ DP_UpperRight												UMETA(DisplayName = "DP_UpperRight"),
	/* 3 */ DP_MiddleRight												UMETA(DisplayName = "DP_MiddleRight"),
	/* 4 */ DP_LowerRight												UMETA(DisplayName = "DP_LowerRight"),
	/* 5 */ DP_LowerMiddle												UMETA(DisplayName = "DP_LowerMiddle"),
	/* 6 */ DP_LowerLeft												UMETA(DisplayName = "DP_LowerLeft"),
	/* 7 */ DP_MiddleLeft												UMETA(DisplayName = "DP_MiddleLeft"),
	/* 8 */ DP_MiddleMiddle												UMETA(DisplayName = "DP_MiddleMiddle")
};

UENUM(BlueprintType)
enum class EStackMode : uint8
{
	/* 0 */ SM_None														UMETA(DisplayName = "SM_None"),
	/* 1 */ SM_Up														UMETA(DisplayName = "SM_Up"),
	/* 2 */ SM_Down														UMETA(DisplayName = "SM_Down")
};

UENUM(BlueprintType)
enum class EPlayerPos : uint8
{
	/* 0 */ POS_Auto													UMETA(DisplayName = "POS_Auto"),
	/* 1 */ POS_Defense													UMETA(DisplayName = "POS_Defense"),
	/* 2 */ POS_Offense													UMETA(DisplayName = "POS_Offense"),
	/* 3 */ POS_Roam													UMETA(DisplayName = "POS_Roam"),
	/* 4 */ POS_Supporting												UMETA(DisplayName = "POS_Supporting")
};

UENUM(BlueprintType)
enum class EPhysics : uint8
{
	/* 0 */ PHYS_None													UMETA(DisplayName = "PHYS_None"),
	/* 1 */ PHYS_Walking												UMETA(DisplayName = "PHYS_Walking"),
	/* 2 */ PHYS_Falling												UMETA(DisplayName = "PHYS_Falling"),
	/* 3 */ PHYS_Swimming												UMETA(DisplayName = "PHYS_Swimming"),
	/* 4 */ PHYS_Flying													UMETA(DisplayName = "PHYS_Flying"),
	/* 5 */ PHYS_Rotating												UMETA(DisplayName = "PHYS_Rotating"),
	/* 6 */ PHYS_Projectile												UMETA(DisplayName = "PHYS_Projectile"),
	/* 7 */ PHYS_Interpolating											UMETA(DisplayName = "PHYS_Interpolating"),
	/* 8 */ PHYS_MovingBrush											UMETA(DisplayName = "PHYS_MovingBrush"),
	/* 9 */ PHYS_Spider													UMETA(DisplayName = "PHYS_Spider"),
	/*10 */ PHYS_Trailer												UMETA(DisplayName = "PHYS_Trailer"),
	/*11 */ PHYS_Ladder													UMETA(DisplayName = "PHYS_Ladder"),
	/*12 */ PHYS_RootMotion												UMETA(DisplayName = "PHYS_RootMotion"),
	/*13 */ PHYS_Karma													UMETA(DisplayName = "PHYS_Karma"),
	/*14 */ PHYS_KarmaRagDoll											UMETA(DisplayName = "PHYS_KarmaRagDoll"),
	/*15 */ PHYS_Hovering												UMETA(DisplayName = "PHYS_Hovering"),
	/*16 */ PHYS_CinMotion												UMETA(DisplayName = "PHYS_CinMotion"),
	/*17 */ PHYS_Parachute												UMETA(DisplayName = "PHYS_Parachute")
};


UENUM(BlueprintType)
enum class EQualificationRecordBriefTypes : uint8
{
	/* 0 */ EQRBT_RifleMarksmanship										UMETA(DisplayName = "EQRBT_RifleMarksmanship"),
	/* 1 */ EQRBT_Grenade												UMETA(DisplayName = "EQRBT_Grenade"),
	/* 2 */ EQRBT_Driver												UMETA(DisplayName = "EQRBT_Driver"),
	/* 3 */ EMAX_QUALIFICATION_RECORD_BRIEF_TYPE						UMETA(DisplayName = "EMAX_QUALIFICATION_RECORD_BRIEF_TYPE"),
};

UENUM(BlueprintType)
enum class EWeaponRecordBriefTypes : uint8
{
	/* 0 */ EWRBT_AssaultRifle											UMETA(DisplayName = "EWRBT_AssaultRifle"),
	/* 1 */ EWRBT_Pistol												UMETA(DisplayName = "EWRBT_Pistol"),
	/* 2 */ EWRBT_MachineGun											UMETA(DisplayName = "EWRBT_MachineGun"),
	/* 3 */ EWRBT_SniperRifle											UMETA(DisplayName = "EWRBT_SniperRifle"),
	/* 4 */ EWRBT_Rocket												UMETA(DisplayName = "EWRBT_Rocket"),
	/* 5 */ EWRBT_Grenade												UMETA(DisplayName = "EWRBT_Grenade"),
	/* 6 */ EMAX_WEAPON_RECORD_BRIEF_TYPE								UMETA(DisplayName = "EMAX_WEAPON_RECORD_BRIEF_TYPE"),
};


UENUM(BlueprintType)
enum class EGameSpyUpdateType : uint8
{
	/* 0 */ GAMESPY_UPDATE_LIST									UMETA(DisplayName = "GAMESPY_UPDATE_LIST"),
	/* 1 */ GAMESPY_REFRESH_LIST								UMETA(DisplayName = "GAMESPY_REFRESH_LIST"),
	/* 2 */ GAMESPY_REFRESH_SELECTED							UMETA(DisplayName = "GAMESPY_REFRESH_SELECTED"),
	/* 3 */ GAMESPY_SORT_BY_COLUMN								UMETA(DisplayName = "GAMESPY_SORT_BY_COLUMN")
};

UENUM(BlueprintType)
enum class ELinkMode : uint8
{
	/* 0 */ MODE_Text											UMETA(DisplayName = "MODE_Text"),
	/* 1 */ MODE_Line											UMETA(DisplayName = "MODE_Line"),
	/* 2 */ MODE_Binary											UMETA(DisplayName = "MODE_Binary")
};

UENUM(BlueprintType)
enum class ELineMode : uint8
{
	/* 0 */ LMODE_auto											UMETA(DisplayName = "LMODE_auto"),
	/* 1 */ LMODE_DOS											UMETA(DisplayName = "LMODE_DOS"),
	/* 2 */ LMODE_UNIX											UMETA(DisplayName = "LMODE_UNIX"),
	/* 3 */ LMODE_MAC											UMETA(DisplayName = "LMODE_MAC")
};


UENUM(BlueprintType)
enum class EReceiveMode : uint8
{
	/* 0 */ RMODE_Manual										UMETA(DisplayName = "RMODE_Manual"),
	/* 1 */ RMODE_Event											UMETA(DisplayName = "RMODE_Event")
};


UENUM(BlueprintType)
enum class EHeartbeatType : uint8
{
	/* 0 */ HB_QueryInterface									UMETA(DisplayName = "HB_QueryInterface"),
	/* 1 */ HB_GamePort											UMETA(DisplayName = "HB_GamePort"),
	/* 2 */ HB_GamespyQueryPort									UMETA(DisplayName = "HB_GamespyQueryPort")
};

UENUM(BlueprintType)
enum class EMasterToServer : uint8
{
	/* 0 */ MTS_ClientChallenge									UMETA(DisplayName = "MTS_ClientChallenge"),
	/* 1 */ MTS_ClientAuthFailed								UMETA(DisplayName = "MTS_ClientAuthFailed"),
	/* 2 */ MTS_Shutdown										UMETA(DisplayName = "MTS_Shutdown"),
	/* 3 */ MTS_MatchID											UMETA(DisplayName = "MTS_MatchID"),
	/* 4 */ MTS_MD5Update										UMETA(DisplayName = "MTS_MD5Update"),
	/* 5 */ MTS_UpdateOption									UMETA(DisplayName = "MTS_UpdateOption"),
	/* 6 */ MTS_CheckOption										UMETA(DisplayName = "MTS_CheckOption"),
	/* 7 */ MTS_ClientMD5Fail									UMETA(DisplayName = "MTS_ClientMD5Fail"),
	/* 8 */ MTS_ClientBanned									UMETA(DisplayName = "MTS_ClientBanned"),
	/* 9 */ MTS_ClientDupKey									UMETA(DisplayName = "MTS_ClientDupKey")
};

UENUM(BlueprintType)
enum class EServerToMaster : uint8
{
	/* 0 */ STM_ClientResponse									UMETA(DisplayName = "STM_ClientResponse"),
	/* 1 */ STM_GameState										UMETA(DisplayName = "STM_GameState"),
	/* 2 */ STM_Stats											UMETA(DisplayName = "STM_Stats"),
	/* 3 */ STM_ClientDisconnectFailed							UMETA(DisplayName = "STM_ClientDisconnectFailed"),
	/* 4 */ STM_MD5Version										UMETA(DisplayName = "STM_MD5Version"),
	/* 5 */ STM_CheckOptionReply								UMETA(DisplayName = "STM_CheckOptionReply")
};



UENUM(BlueprintType)
enum class ESCIQRState : uint8
 {
	/* 0 */ SCIQR_Nothing								UMETA(DisplayName = "SCIQR_Nothing"),
	/* 1 */ SCIQR_Opening								UMETA(DisplayName = "SCIQR_Opening"),
	/* 2 */ SCIQR_Registering							UMETA(DisplayName = "SCIQR_Registering"),
	/* 3 */ SCIQR_SendingHeartbeat						UMETA(DisplayName = "SCIQR_SendingHeartbeat"),
	/* 4 */ SCIQR_Closing								UMETA(DisplayName = "SCIQR_Closing"),
	/* 5 */ SCIQR_Waiting								UMETA(DisplayName = "SCIQR_Waiting")
};


UENUM(BlueprintType)
enum class EPlayInfoType : uint8
{
	/* 0 */	PIT_Check									UMETA(DisplayName = "PIT_Check"),
	/* 1 */	PIT_Select									UMETA(DisplayName = "PIT_Select"),
	/* 2 */	PIT_Text									UMETA(DisplayName = "PIT_Text"),
	/* 3 */	PIT_Custom									UMETA(DisplayName = "PIT_Custom")
};



UENUM(BlueprintType)
enum class EBanType : uint8
{
	/* 0 */	BanType_PlayerName							UMETA(DisplayName = "BanType_PlayerName"),
	/* 1 */	BanType_PlayerIP							UMETA(DisplayName = "BanType_PlayerIP"),
	/* 2 */	BanType_PlayerMAC							UMETA(DisplayName = "BanType_PlayerMAC"),
	/* 3 */	BanType_PBGUID								UMETA(DisplayName = "BanType_PBGUID"),
	/* 4 */	BanType_Unknown								UMETA(DisplayName = "BanType_Unknown")
};

UENUM(BlueprintType)
enum class EPlayerRole : uint8
{
	/* 0 */	PROLE_None									UMETA(DisplayName = "PROLE_None"),
	/* 1 */	PROLE_Soldier								UMETA(DisplayName = "PROLE_Soldier"),
	/* 2 */ PROLE_FTL									UMETA(DisplayName = "PROLE_FTL"),
	/* 3 */ PROLE_SQL									UMETA(DisplayName = "PROLE_SQL")
};

UENUM(BlueprintType)
enum class ELinkedState : uint8
{
	/* 0 */	LINKED_None									UMETA(DisplayName = "LINKED_None"),
	/* 1 */	LINKED_Soldier								UMETA(DisplayName = "LINKED_Soldier"),
	/* 2 */ LINKED_FTL									UMETA(DisplayName = "LINKED_FTL"),
	/* 3 */ LINKED_SQL									UMETA(DisplayName = "LINKED_SQL"),
	/* 4 */ LINKED_SQL_AND_FTL							UMETA(DisplayName = "LINKED_SQL_AND_FTL")
};

UENUM(BlueprintType)
enum class ECommandoHeadGear : uint8
{
	/* 0 */	Commando_None								UMETA(DisplayName = "Commando_None"),
	/* 1 */	Commando_Cap								UMETA(DisplayName = "Commando_Cap"),
	/* 2 */ Commando_Beret								UMETA(DisplayName = "Commando_Beret"),
	/* 3 */ Commando_Beret_Green						UMETA(DisplayName = "Commando_Beret_Green"),
	/* 4 */ Commando_Headband							UMETA(DisplayName = "Commando_Headband"),
	/* 5 */ Commando_Helmet								UMETA(DisplayName = "Commando_Helmet")
};

UENUM(BlueprintType)
enum class ESoldierHeadGear : uint8
{
	/* 0 */	SoldierHeadgear_Random						UMETA(DisplayName = "SoldierHeadgear_Random"),
	/* 1 */	SoldierHeadgear_None						UMETA(DisplayName = "SoldierHeadgear_None"),
	/* 2 */	SoldierHeadgear_WatchCap					UMETA(DisplayName = "SoldierHeadgear_WatchCap"),
	/* 3 */	SoldierHeadgear_WatchCap_Black				UMETA(DisplayName = "SoldierHeadgear_WatchCap_Black"),
	/* 4 */	SoldierHeadgear_Beret						UMETA(DisplayName = "SoldierHeadgear_Beret"),
	/* 5 */	SoldierHeadgear_Beanie						UMETA(DisplayName = "SoldierHeadgear_Beanie"),
	/* 6 */	SoldierHeadgear_Helmet						UMETA(DisplayName = "SoldierHeadgear_Helmet"),
	/* 7 */	SoldierHeadgear_PatrolCap					UMETA(DisplayName = "SoldierHeadgear_PatrolCap"),
	/* 8 */	SoldierHeadgear_PatrolCap_Black				UMETA(DisplayName = "SoldierHeadgear_PatrolCap_Black"),
	/* 9 */	SoldierHeadgear_JungleHat					UMETA(DisplayName = "SoldierHeadgear_JungleHat"),
	/*10 */	SoldierHeadgear_JungleHat_Black				UMETA(DisplayName = "SoldierHeadgear_JungleHat_Black")
};

UENUM(BlueprintType)
enum class ESoldierBackpack : uint8
{
	/* 0 */	SoldierBackpack_None						UMETA(DisplayName = "SoldierBackpack_None"),
	/* 1 */	SoldierBackpack_Standard					UMETA(DisplayName = "SoldierBackpack_Standard"),
	/* 2 */ SoldierBackpack_RPG							UMETA(DisplayName = "SoldierBackpack_RPG"),
	/* 3 */ SoldierBackpack_Radio						UMETA(DisplayName = "SoldierBackpack_Radio")
};

UENUM(BlueprintType)
enum class EReinforcementCommand : uint8
{
	/* 0 */	NPCRC_FollowOrders							UMETA(DisplayName = "NPCRC_FollowOrders"),
	/* 1 */	NPCRC_HeadForObjective						UMETA(DisplayName = "NPCRC_HeadForObjective"),
	/* 2 */ NPCRC_HeadToTaggedActor						UMETA(DisplayName = "NPCRC_HeadToTaggedActor")
};

UENUM(BlueprintType)
enum class ECivMeshType : uint8
{
	/* 0 */	CivMeshType_Standard						UMETA(DisplayName = "CivMeshType_Standard"),
	/* 1 */	CivMeshType_Custom							UMETA(DisplayName = "CivMeshType_Custom"),
	/* 2 */ CivMeshType_A								UMETA(DisplayName = "CivMeshType_A"),
	/* 3 */ CivMeshType_B								UMETA(DisplayName = "CivMeshType_B")
};

UENUM(BlueprintType)
enum class ESoldierHeadGearACU : uint8
{
	/* 0 */	SoldierHeadgear_None						UMETA(DisplayName = "SoldierHeadgear_None"),
	/* 1 */	SoldierHeadgear_BDUCap						UMETA(DisplayName = "SoldierHeadgear_BDUCap"),
	/* 2 */ SoldierHeadgear_BDUCapSgt					UMETA(DisplayName = "SoldierHeadgear_BDUCapSgt"),
	/* 3 */ SoldierHeadgear_Beret						UMETA(DisplayName = "SoldierHeadgear_Beret"),
	/* 4 */ SoldierHeadgear_Helmet						UMETA(DisplayName = "SoldierHeadgear_Helmet"),
	/* 5 */ SoldierHeadgear_DesertCap					UMETA(DisplayName = "SoldierHeadgear_DesertCap")
};

UENUM(BlueprintType)
enum class ESoldierShirt : uint8
{
	/* 0 */	SoldierShirt_Custom							UMETA(DisplayName = "SoldierShirt_Custom"),
	/* 1 */	SoldierShirt_RandomNamed					UMETA(DisplayName = "SoldierShirt_RandomNamed"),
	/* 2 */ SoldierShirt_VestAndMolle					UMETA(DisplayName = "SoldierShirt_VestAndMolle"),
	/* 3 */ SoldierShirt_SFVest							UMETA(DisplayName = "SoldierShirt_SFVest"),
	/* 4 */ SoldierShirt_MeshDefault					UMETA(DisplayName = "SoldierShirt_MeshDefault")
};

UENUM(BlueprintType)
enum class ESoldierHands : uint8
{
	/* 0 */	SoldierHands_Custom							UMETA(DisplayName = "SoldierHands_Custom"),
	/* 1 */	SoldierHands_MatchFace						UMETA(DisplayName = "SoldierHands_MatchFace"),
	/* 2 */ SoldierHands_SFGloves						UMETA(DisplayName = "SoldierHands_SFGloves"),
	/* 3 */ SoldierHands_ArticBlackGloves				UMETA(DisplayName = "SoldierHands_ArticBlackGloves"),
	/* 4 */ SoldierHands_ArticDesertGloves				UMETA(DisplayName = "SoldierHands_ArticDesertGloves"),
	/* 5 */ SoldierHands_ArticForestGloves				UMETA(DisplayName = "SoldierHands_ArticForestGloves"),
	/* 6 */ SoldierHands_MeshDefault					UMETA(DisplayName = "SoldierHands_MeshDefault")
};

UENUM(BlueprintType)
enum class ESoldierPants : uint8
{
	/* 0 */	SoldierPants_Custom							UMETA(DisplayName = "SoldierPants_Custom"),
	/* 1 */	SoldierPants_Infantry						UMETA(DisplayName = "SoldierPants_Infantry"),
	/* 2 */ SoldierPants_SF								UMETA(DisplayName = "SoldierPants_SF"),
	/* 3 */ SoldierPants_MeshDefault					UMETA(DisplayName = "SoldierPants_MeshDefault")
};


UENUM(BlueprintType)
enum class ESoldierFace : uint8
{
	/* 0 */	SoldierFace_Custom							UMETA(DisplayName = "SoldierFace_Custom"),
	/* 1 */	SoldierFace_RandomInf						UMETA(DisplayName = "SoldierFace_RandomInf"),
	/* 2 */ SoldierFace_RandomInfWithCamo				UMETA(DisplayName = "SoldierFace_RandomInfWithCamo"),
	/* 3 */ SoldierFace_RandomSF						UMETA(DisplayName = "SoldierFace_RandomSF"),
	/* 4 */ SoldierFace_MeshDefault						UMETA(DisplayName = "SoldierFace_MeshDefault")
};




UENUM(BlueprintType)
enum class ETriggerType : uint8
{
	/* 0 */	TT_PlayerProximity						UMETA(DisplayName = "TT_PlayerProximity"),
	/* 1 */	TT_PawnProximity						UMETA(DisplayName = "TT_PawnProximity"),
	/* 2 */ TT_ClassProximity						UMETA(DisplayName = "TT_ClassProximity"),
	/* 3 */ TT_AnyProximity							UMETA(DisplayName = "TT_AnyProximity"),
	/* 4 */ TT_Shoot								UMETA(DisplayName = "TT_Shoot"),
	/* 5 */ TT_HumanPlayerProximity					UMETA(DisplayName = "TT_HumanPlayerProximity"),
	/* 6 */ TT_LivePlayerProximity					UMETA(DisplayName = "TT_LivePlayerProximity")

};

UENUM(BlueprintType)
enum class ELockingStyle : uint8
{
	/* 0 */	LS_Any									UMETA(DisplayName = "LS_Any"),
	/* 1 */	LS_TeamZero								UMETA(DisplayName = "LS_TeamZero"),
	/* 2 */ LS_TeamOne								UMETA(DisplayName = "LS_TeamOne"),
	/* 3 */ LS_Damaged								UMETA(DisplayName = "LS_Damaged"),
	/* 4 */ LS_LockedForAll							UMETA(DisplayName = "LS_LockedForAll")
};


UENUM(BlueprintType)
enum class EMoverEncroachType : uint8
{
	/* 0 */	ME_StopWhenEncroach						UMETA(DisplayName = "ME_StopWhenEncroach"),
	/* 1 */	ME_ReturnWhenEncroach					UMETA(DisplayName = "ME_ReturnWhenEncroach"),
	/* 2 */ ME_CrushWhenEncroach					UMETA(DisplayName = "ME_CrushWhenEncroach"),
	/* 3 */ ME_IgnoreWhenEncroach					UMETA(DisplayName = "ME_IgnoreWhenEncroach")
};

UENUM(BlueprintType)
enum class EMoverGlideType : uint8
{
	/* 0 */	MV_MoveByTime							UMETA(DisplayName = "MV_MoveByTime"),
	/* 1 */	MV_GlideByTime							UMETA(DisplayName = "MV_GlideByTime")
};


UENUM(BlueprintType)
enum class EBumpType : uint8
{
	/* 0 */	BT_PlayerBump							UMETA(DisplayName = "BT_PlayerBump"),
	/* 1 */	BT_PawnBump								UMETA(DisplayName = "BT_PawnBump"),
	/* 2 */ BT_AnyBump								UMETA(DisplayName = "BT_AnyBump")
};



UENUM(BlueprintType)
enum class ELockingSide : uint8
{
	/* 0 */	SIDE_Both								UMETA(DisplayName = "SIDE_Both"),
	/* 1 */	SIDE_A									UMETA(DisplayName = "SIDE_A"),
	/* 2 */ SIDE_B									UMETA(DisplayName = "SIDE_B")
};


UENUM(BlueprintType)
enum class EServerScoreMode : uint8
{
	/* 0 */	SSM_On									UMETA(DisplayName = "SSM_On"),
	/* 1 */	SSM_Off									UMETA(DisplayName = "SSM_Off"),
	/* 2 */ SSM_Round								UMETA(DisplayName = "SSM_Round"),
	/* 3 */ SSM_Match								UMETA(DisplayName = "SSM_Match")
};

UENUM(BlueprintType)
enum class EFlagState : uint8
{
	/* 0 */	FLAG_Home								UMETA(DisplayName = "FLAG_Home"),
	/* 1 */	FLAG_HeldFriendly						UMETA(DisplayName = "FLAG_HeldFriendly"),
	/* 2 */ FLAG_HeldEnemy							UMETA(DisplayName = "FLAG_HeldEnemy"),
	/* 2 */ FLAG_Down								UMETA(DisplayName = "FLAG_Down")
};

UENUM(BlueprintType)
enum class EWeaponSkinSet : uint8
{
	/* 0 */	WSKINS_Default							UMETA(DisplayName = "WSKINS_Default"),
	/* 1 */	WSKINS_Desert							UMETA(DisplayName = "WSKINS_Desert"),
	/* 2 */ WSKINS_Arctic							UMETA(DisplayName = "WSKINS_Arctic")
};

UENUM(BlueprintType)
enum class ELevelAction : uint8
{
	/* 0 */	LEVACT_None								UMETA(DisplayName = "LEVACT_None"),
	/* 1 */	LEVACT_Loading							UMETA(DisplayName = "LEVACT_Loading"),
	/* 2 */ LEVACT_Saving							UMETA(DisplayName = "LEVACT_Saving"),
	/* 3 */ LEVACT_Connecting						UMETA(DisplayName = "LEVACT_Connecting"),
	/* 4 */ LEVACT_Precaching						UMETA(DisplayName = "LEVACT_Precaching")
};

UENUM(BlueprintType)
enum class ESkinSet : uint8
{
	/* 0 */	SKINS_Forest							UMETA(DisplayName = "SKINS_Forest"),
	/* 1 */	SKINS_Desert							UMETA(DisplayName = "SKINS_Desert"),
	/* 2 */ SKINS_OpFor								UMETA(DisplayName = "SKINS_OpFor"),
	/* 3 */ SKINS_DesOp								UMETA(DisplayName = "SKINS_DesOp"),
	/* 4 */ SKINS_Arctic							UMETA(DisplayName = "SKINS_Arctic"),
	/* 5 */ SKINS_IBCT								UMETA(DisplayName = "SKINS_IBCT"),
	/* 6 */ SKINS_ArcOpFor							UMETA(DisplayName = "SKINS_ArcOpFor"),
	/* 7 */ SKINS_Training							UMETA(DisplayName = "SKINS_Training"),
	/* 8 */ SKINS_CivOp								UMETA(DisplayName = "SKINS_CivOp"),
	/* 9 */ SKINS_OpInfantry						UMETA(DisplayName = "SKINS_OpInfantry"),
	/* 10*/ SKINS_SF_Arctic							UMETA(DisplayName = "SKINS_SF_Arctic")
};


UENUM(BlueprintType)
enum class EMesh : uint8
{
	/* 0 */	MESH_Soldier							UMETA(DisplayName = "MESH_Soldier"),
	/* 1 */	MESH_DesOp								UMETA(DisplayName = "MESH_DesOp"),
	/* 2 */ MESH_Arctic								UMETA(DisplayName = "MESH_Arctic"),
	/* 3 */ MESH_OPFOR								UMETA(DisplayName = "MESH_OPFOR"),
	/* 4 */ MESH_IBCT								UMETA(DisplayName = "MESH_IBCT"),
	/* 5 */ MESH_CivOp								UMETA(DisplayName = "MESH_CivOp"),
	/* 6 */ MESH_SF									UMETA(DisplayName = "MESH_SF"),
	/* 7 */ MESH_OpInfantry							UMETA(DisplayName = "MESH_OpInfantry"),
	/* 8 */ MESH_ArcOpFor							UMETA(DisplayName = "MESH_ArcOpFor"),
	/* 9 */ MESH_SF_Arctic							UMETA(DisplayName = "MESH_SF_Arctic")
};




UENUM(BlueprintType)
enum class EDefaultBinoc : uint8
{
	/* 0 */	BINOC_M22								UMETA(DisplayName = "BINOC_M22"),
	/* 1 */	BINOC_M24								UMETA(DisplayName = "BINOC_M24"),
	/* 2 */ BINOC_Tank								UMETA(DisplayName = "BINOC_Tank"),
	/* 3 */ BINOC_Newt								UMETA(DisplayName = "BINOC_Newt"),
	/* 4 */ BINOC_VIPER								UMETA(DisplayName = "BINOC_VIPER")
}; 

UENUM(BlueprintType)
enum class EMeshLODDetailLevel : uint8
{
	/* 0 */	MDL_Low									UMETA(DisplayName = "MDL_Low"),
	/* 1 */	MDL_Medium								UMETA(DisplayName = "MDL_Medium"),
	/* 2 */ MDL_High								UMETA(DisplayName = "MDL_High"),
	/* 3 */ MDL_Ultra								UMETA(DisplayName = "MDL_Ultra")
};

UENUM(BlueprintType)
enum class EPhysicsDetailLevel : uint8
{
	/* 0 */	PDL_Low									UMETA(DisplayName = "PDL_Low"),
	/* 1 */	PDL_Medium								UMETA(DisplayName = "PDL_Medium"),
	/* 2 */ PDL_High								UMETA(DisplayName = "PDL_High")
};
UENUM(BlueprintType)

enum class EShadowDetail : uint8
{
	/* 0 */	SHADOW_None								UMETA(DisplayName = "SHADOW_None"),
	/* 1 */	SHADOW_Blob								UMETA(DisplayName = "SHADOW_Blob"),
	/* 2 */ SHADOW_Detail							UMETA(DisplayName = "SHADOW_Detail")
};

UENUM(BlueprintType)
enum class ExParticleTypes : uint8
{
	/* 0 */	PT_Sprite								UMETA(DisplayName = "PT_Sprite"),
	/* 1 */	PT_Stream								UMETA(DisplayName = "PT_Stream"),
	/* 2 */ PT_Line									UMETA(DisplayName = "PT_Line"),
	/* 3 */ PT_Disc									UMETA(DisplayName = "PT_Disc"),
	/* 4 */ PT_Mesh									UMETA(DisplayName = "PT_Mesh"),
	/* 4 */ PT_Branch								UMETA(DisplayName = "PT_Branch"),
	/* 4 */ PT_Beam									UMETA(DisplayName = "PT_Beam")

};

UENUM(BlueprintType)
enum class ExSpawningTypes : uint8
{
	/* 0 */	ST_Sphere								UMETA(DisplayName = "ST_Sphere"),
	/* 1 */	ST_Line									UMETA(DisplayName = "ST_Line"),
	/* 2 */ ST_Disc									UMETA(DisplayName = "ST_Disc"),
	/* 3 */ ST_Cylinder								UMETA(DisplayName = "ST_Cylinder"),
	/* 4 */ ST_AimedSphere							UMETA(DisplayName = "ST_AimedSphere"),
	/* 5 */ ST_StaticMesh							UMETA(DisplayName = "ST_StaticMesh"),
	/* 6 */ ST_Explode								UMETA(DisplayName = "ST_Explode"),
	/* 7 */ ST_ExplodeRing							UMETA(DisplayName = "ST_ExplodeRing"),
	/* 8 */ ST_OwnerSkeleton						UMETA(DisplayName = "ST_OwnerSkeleton"),
	/* 9 */ ST_Test									UMETA(DisplayName = "ST_Test")
};

UENUM(BlueprintType)
enum class EAttenFunc : uint8
{
	/* 0 */	ATF_LerpInOut							UMETA(DisplayName = "ATF_LerpInOut"),
	/* 1 */	ATF_ExpInOut							UMETA(DisplayName = "ATF_ExpInOut"),
	/* 2 */ ATF_SmoothStep							UMETA(DisplayName = "ATF_SmoothStep"),
	/* 3 */ ATF_Pulse								UMETA(DisplayName = "ATF_Pulse"),
	/* 4 */ ATF_Random								UMETA(DisplayName = "ATF_Random"),
	/* 5 */ ATF_None								UMETA(DisplayName = "ATF_None")
};

UENUM(BlueprintType)
enum class EViewPreference : uint8
{
	/* 0 */	VIEW_Any								UMETA(DisplayName = "VIEW_Any"),
	/* 1 */	VIEW_PlayersOnly						UMETA(DisplayName = "VIEW_PlayersOnly"),
	/* 2 */ VIEW_ViewpointsOnly						UMETA(DisplayName = "VIEW_ViewpointsOnly"),
	/* 3 */ VIEW_Bodies								UMETA(DisplayName = "VIEW_Bodies"),
	/* 4 */ VIEW_AdminFreecam						UMETA(DisplayName = "VIEW_AdminFreecam")
	
};

UENUM(BlueprintType)
enum class EBoneRegion : uint8
{
	/* 0 */	BR_NONE									UMETA(DisplayName = "BR_NONE"),
	/* 1 */	BR_Head									UMETA(DisplayName = "BR_Head"),
	/* 2 */	BR_Upper_Torso							UMETA(DisplayName = "BR_Upper_Torso"),
	/* 3 */	BR_Lower_Torso							UMETA(DisplayName = "BR_Lower_Torso"),
	/* 4 */	BR_Left_Arm								UMETA(DisplayName = "BR_Left_Arm"),
	/* 5 */	BR_Left_Hand							UMETA(DisplayName = "BR_Left_Hand"),
	/* 6 */	BR_Left_Leg								UMETA(DisplayName = "BR_Left_Leg"),
	/* 7 */	BR_Left_Foot							UMETA(DisplayName = "BR_Left_Foot"),
	/* 8 */	BR_Right_Arm							UMETA(DisplayName = "BR_Right_Arm"),
	/* 9 */	BR_Right_Hand							UMETA(DisplayName = "BR_Right_Hand"),
	/* 10*/	BR_Right_Leg							UMETA(DisplayName = "BR_Right_Leg"),
	/* 11*/	BR_Right_Foot							UMETA(DisplayName = "BR_Right_Foot")
};


UENUM(BlueprintType)
enum class EGameplayModes : uint8
{
	/* 0 */	GM_Normal								UMETA(DisplayName = "GM_Normal"),
	/* 1 */	GM_MILES								UMETA(DisplayName = "GM_MILES"),
	/* 2 */ GM_Simunition							UMETA(DisplayName = "GM_Simunition")
};

UENUM(BlueprintType)
enum class EDebugTag : uint8
{
	/* 0 */	DEBUG_Default						UMETA(DisplayName = "DEBUG_Default"),
	/* 1 */	DEBUG_Warn							UMETA(DisplayName = "DEBUG_Warn"),
	/* 2 */	DEBUG_Error							UMETA(DisplayName = "DEBUG_Error"),
	/* 3 */	DEBUG_Always						UMETA(DisplayName = "DEBUG_Always"),
	/* 4 */	DEBUG_Network						UMETA(DisplayName = "DEBUG_Network"),
	/* 5 */	DEBUG_Server						UMETA(DisplayName = "DEBUG_Server"),
	/* 6 */	DEBUG_Client						UMETA(DisplayName = "DEBUG_Client"),
	/* 7 */	DEBUG_Standalone					UMETA(DisplayName = "DEBUG_Standalone"),
	/* 8 */	DEBUG_AI							UMETA(DisplayName = "DEBUG_AI"),
	/* 9 */	DEBUG_InvAI							UMETA(DisplayName = "DEBUG_InvAI"),
	/* 10*/	DEBUG_Char							UMETA(DisplayName = "DEBUG_Char"),
	/* 11*/	DEBUG_Door							UMETA(DisplayName = "DEBUG_Door"),
	/* 12*/	DEBUG_Break							UMETA(DisplayName = "DEBUG_Break"),
	/* 13*/	DEBUG_Skin							UMETA(DisplayName = "DEBUG_Skin"),
	/* 14*/	DEBUG_Multi							UMETA(DisplayName = "DEBUG_Multi"),
	/* 15*/	DEBUG_Trig							UMETA(DisplayName = "DEBUG_Trig"),
	/* 16*/	DEBUG_NetClean						UMETA(DisplayName = "DEBUG_NetClean"),
	/* 17*/	DEBUG_HUD							UMETA(DisplayName = "DEBUG_HUD"),
	/* 18*/	DEBUG_Inv							UMETA(DisplayName = "DEBUG_Inv"),
	/* 19*/	DEBUG_Spec							UMETA(DisplayName = "DEBUG_Spec"),
	/* 20*/	DEBUG_Auth							UMETA(DisplayName = "DEBUG_Auth"),
	/* 21*/	DEBUG_Team							UMETA(DisplayName = "DEBUG_Team"),
	/* 22*/	DEBUG_Anim							UMETA(DisplayName = "DEBUG_Anim"),
	/* 23*/	DEBUG_Gren							UMETA(DisplayName = "DEBUG_Gren"),
	/* 24*/	DEBUG_Bullet						UMETA(DisplayName = "DEBUG_Bullet"),
	/* 25*/	DEBUG_Karma							UMETA(DisplayName = "DEBUG_Karma"),
	/* 26*/	DEBUG_EventLab						UMETA(DisplayName = "DEBUG_EventLab"),
	/* 27*/	DEBUG_Tournament					UMETA(DisplayName = "DEBUG_Tournament"),
	/* 28*/	DEBUG_Security						UMETA(DisplayName = "DEBUG_Security"),
	/* 29*/	DEBUG_Scoring						UMETA(DisplayName = "DEBUG_Scoring"),
	/* 30*/	DEBUG_Stats							UMETA(DisplayName = "DEBUG_Stats"),
	/* 31*/	DEBUG_DCDS							UMETA(DisplayName = "DEBUG_DCDS"),
	/* 32*/	DEBUG_Vehicle						UMETA(DisplayName = "DEBUG_Vehicle"),
	/* 33*/	DEBUG_AIVehicle						UMETA(DisplayName = "DEBUG_AIVehicle"),
	/* 34*/	DEBUG_AIMortar						UMETA(DisplayName = "DEBUG_AIMortar"),
	/* 35*/	DEBUG_AISpawn						UMETA(DisplayName = "DEBUG_AISpawn"),
	/* 36*/	DEBUG_Login							UMETA(DisplayName = "DEBUG_Login"),
	/* 37*/	DEBUG_PlayerSpawn					UMETA(DisplayName = "DEBUG_PlayerSpawn"),
	/* 38*/	DEBUG_AIPathing						UMETA(DisplayName = "DEBUG_AIPathing"),
	/* 39*/	DEBUG_CoOpScoring					UMETA(DisplayName = "DEBUG_CoOpScoring"),
	/* 40*/	DEBUG_Input							UMETA(DisplayName = "DEBUG_Input"),
	/* 41*/	DEBUG_Last							UMETA(DisplayName = "DEBUG_Last")
};

UENUM(BlueprintType)
enum class EGameSpyCompareMode : uint8
{	
	/* 0 */	SORT_INT									UMETA(DisplayName = "SORT_INT"),
	/* 1 */	SORT_FLOAT									UMETA(DisplayName = "SORT_FLOAT"),
	/* 2 */ SORT_STR_SENSITIVE							UMETA(DisplayName = "SORT_STR_SENSITIVE"),
	/* 3 */ SORT_STR_INSENSITIVE						UMETA(DisplayName = "SORT_STR_INSENSITIVE")
};

UENUM(BlueprintType)
enum class EStartupStage : uint8
{
	/* 0 */	STAGE_Connecting							UMETA(DisplayName = "STAGE_Connecting"),
	/* 1 */	STAGE_Authorizing							UMETA(DisplayName = "STAGE_Authorizing"),
	/* 2 */ STAGE_WaitingForNextMatch					UMETA(DisplayName = "STAGE_WaitingForNextMatch"),
	/* 3 */ STAGE_WaitForEnoughPlayers					UMETA(DisplayName = "STAGE_WaitForEnoughPlayers"),
	/* 4 */ STAGE_WaitForReadyPlayers					UMETA(DisplayName = "STAGE_WaitForReadyPlayers"),
	/* 5 */ STAGE_Starting								UMETA(DisplayName = "STAGE_Starting"),
	/* 6 */ STAGE_MatchInProgress						UMETA(DisplayName = "STAGE_MatchInProgress"),
	/* 7 */ STAGE_CanRespawn							UMETA(DisplayName = "STAGE_CanRespawn"),
	/* 8 */ STAGE_Dead									UMETA(DisplayName = "STAGE_Dead"),
	/* 9 */ STAGE_Spectator								UMETA(DisplayName = "STAGE_Spectator"),
	/*10 */ STAGE_MatchOver								UMETA(DisplayName = "STAGE_MatchOver"),
	/*11 */ STAGE_Autobalance							UMETA(DisplayName = "STAGE_Autobalance"),
	/*12 */ STAGE_LostConnection						UMETA(DisplayName = "STAGE_LostConnection")
};

UENUM(BlueprintType)
enum class EForceGameplayMode : uint8
{
	/* 0 */	FORCE_None									UMETA(DisplayName = "FORCE_None"),
	/* 1 */	FORCE_Normal								UMETA(DisplayName = "FORCE_Normal"),
	/* 2 */ FORCE_MILES									UMETA(DisplayName = "FORCE_MILES"),
	/* 3 */ FORCE_Simunition							UMETA(DisplayName = "FORCE_Simunition")
};

UENUM(BlueprintType)
enum class EScopeDetail : uint8
{
	/* 0 */	SCOPEDETAIL_High							UMETA(DisplayName = "SCOPEDETAIL_High"),
	/* 1 */	SCOPEDETAIL_Normal							UMETA(DisplayName = "SCOPEDETAIL_Normal"),
	/* 2 */ SCOPEDETAIL_Low								UMETA(DisplayName = "SCOPEDETAIL_Low"),
	/* 3 */ SCOPEDETAIL_VeryLow							UMETA(DisplayName = "SCOPEDETAIL_VeryLow")
};

UENUM(BlueprintType)
enum class ESkinPreference : uint8
{
	/* 0 */	SKINPREF_None								UMETA(DisplayName = "SKINPREF_None"),
	/* 1 */	SKINPREF_Caucasian							UMETA(DisplayName = "SKINPREF_Caucasian"),
	/* 2 */ SKINPREF_African							UMETA(DisplayName = "SKINPREF_African"),
	/* 3 */ SKINPREF_Latino								UMETA(DisplayName = "SKINPREF_Latino")
};

UENUM(BlueprintType)
enum class ESwapType : uint8
{
	/* 0 */	SType_None									UMETA(DisplayName = "SType_None"),
	/* 1 */	SType_Hands									UMETA(DisplayName = "SType_Hands"),
	/* 2 */ SType_AltShoulder							UMETA(DisplayName = "SType_AltShoulder"),
	/* 3 */ SType_Hip									UMETA(DisplayName = "SType_Hip"),
	/* 4 */ SType_Pistol								UMETA(DisplayName = "SType_Pistol"),
	/* 5 */ SType_Frag									UMETA(DisplayName = "SType_Frag"),
	/* 6 */ SType_Smoke									UMETA(DisplayName = "SType_Smoke"),
	/* 7 */ SType_Flash									UMETA(DisplayName = "SType_Flash"),
	/* 8 */ SType_Incendiary							UMETA(DisplayName = "SType_Incendiary"),
	/* 9 */ SType_PDM									UMETA(DisplayName = "SType_PDM"),
	/*10 */ SType_DoorBreacher							UMETA(DisplayName = "SType_DoorBreacher"),
	/*11 */ SType_GreenSmoke							UMETA(DisplayName = "SType_GreenSmoke")
};

UENUM(BlueprintType)
enum class EEndGameViewpoint : uint8
{
	/* 0 */	EEGV_None									UMETA(DisplayName = "EEGV_None"),
	/* 1 */	EEGV_Always									UMETA(DisplayName = "EEGV_Always"),
	/* 2 */ EEGV_Team0Won								UMETA(DisplayName = "EEGV_Team0Won"),
	/* 3 */ EEGV_Team1Won								UMETA(DisplayName = "EEGV_Team1Won"),
	/* 4 */ EEGV_NoTeamWon								UMETA(DisplayName = "EEGV_NoTeamWon")
};



UENUM(BlueprintType)
enum class ERenderStyle : uint8
{
	/* 0 */	STY_None									UMETA(DisplayName = "STY_None"),
	/* 1 */	STY_Normal									UMETA(DisplayName = "STY_Normal"),
	/* 2 */ STY_Masked									UMETA(DisplayName = "STY_Masked"),
	/* 3 */ STY_Translucent								UMETA(DisplayName = "STY_Translucent"),
	/* 4 */ STY_Modulated								UMETA(DisplayName = "STY_Modulated"),
	/* 5 */ STY_TrueModulated							UMETA(DisplayName = "STY_TrueModulated"),
	/* 6 */ STY_Alpha									UMETA(DisplayName = "STY_Alpha"),
	/* 7 */ STY_Additive								UMETA(DisplayName = "STY_Additive"),
	/* 8 */ STY_Subtractive								UMETA(DisplayName = "STY_Subtractive"),
	/* 9 */ STY_Particle								UMETA(DisplayName = "STY_Particle"),
	/*10 */ STY_AlphaZ									UMETA(DisplayName = "STY_AlphaZ")
};

UENUM(BlueprintType)
enum class ESkinColor : uint8
{
	/* 0 */	SKINCOLOR_NotSet							UMETA(DisplayName = "SKINCOLOR_NotSet"),
	/* 1 */	SKINCOLOR_Caucasian							UMETA(DisplayName = "SKINCOLOR_Caucasian"),
	/* 2 */ SKINCOLOR_African							UMETA(DisplayName = "SKINCOLOR_African"),
	/* 3 */ SKINCOLOR_Latino							UMETA(DisplayName = "SKINCOLOR_Latino")
};


UENUM(BlueprintType)
enum class EObjectiveOnCompass : uint8
{
	/* 0 */	ONCOMPASS_Normal							UMETA(DisplayName = "ONCOMPASS_Normal"),
	/* 1 */	ONCOMPASS_NotOnCompass						UMETA(DisplayName = "ONCOMPASS_NotOnCompass"),
	/* 2 */ ONCOMPASS_Team0Only							UMETA(DisplayName = "ONCOMPASS_Team0Only"),
	/* 3 */ ONCOMPASS_Team1Only							UMETA(DisplayName = "ONCOMPASS_Team1Only"),
	/* 4 */ ONCOMPASS_ObjEnabledTeam0Only				UMETA(DisplayName = "ONCOMPASS_ObjEnabledTeam0Only"),
	/* 5 */ ONCOMPASS_ObjEnabledTeam1Only				UMETA(DisplayName = "ONCOMPASS_ObjEnabledTeam1Only"),
	/* 6 */ ONCOMPASS_InstigatorOnly					UMETA(DisplayName = "ONCOMPASS_InstigatorOnly")
};

UENUM(BlueprintType)
enum class EGameDo : uint8
{
	/* 0 */	GAMEDO_Nothing								UMETA(DisplayName = "GAMEDO_Nothing"),
	/* 1 */	GAMEDO_NoScore								UMETA(DisplayName = "GAMEDO_NoScore"),
	/* 2 */ GAMEDO_TieGame_BothLose						UMETA(DisplayName = "GAMEDO_TieGame_BothLose"),
	/* 3 */ GAMEDO_OtherTeamWin							UMETA(DisplayName = "GAMEDO_OtherTeamWin"),
	/* 4 */ GAMEDO_InstigatorTeamWin					UMETA(DisplayName = "GAMEDO_InstigatorTeamWin"),
	/* 5 */ GAMEDO_InstigatorTeamLose_OtherTeamNoScore	UMETA(DisplayName = "GAMEDO_InstigatorTeamLose_OtherTeamNoScore")
};

UENUM(BlueprintType)
enum class EActivateOn : uint8
{
	/* 0 */	ACTON_AllParents         UMETA(DisplayName = "ACTON_AllParents"),
	/* 1 */	ACTON_AnyParent          UMETA(DisplayName = "ACTON_AnyParent"),
	/* 2 */ ACTON_SameTeam           UMETA(DisplayName = "ACTON_SameTeam")
};

UENUM(BlueprintType)
enum class ECompassVisibilityCarried : uint8
{
	/* 0 */	CarriedVisibility_FriendlyOnly         UMETA(DisplayName = "CarriedVisibility_FriendlyOnly"),
	/* 1 */	CarriedVisibility_EnemyOnly            UMETA(DisplayName = "CarriedVisibility_EnemyOnly"),
	/* 2 */ CarriedVisibility_Normal               UMETA(DisplayName = "CarriedVisibility_Normal"),
	/* 3 */	CarriedVisibility_NotOnCompass         UMETA(DisplayName = "CarriedVisibility_NotOnCompass")
};

UENUM(BlueprintType)
enum class ECompassVisibilityDropped : uint8
{
	/* 0 */	DroppedVisibility_Normal            UMETA(DisplayName = "DroppedVisibility_Normal"),
	/* 1 */	DroppedVisibility_NotOnCompass      UMETA(DisplayName = "DroppedVisibility_NotOnCompass"),
	/* 2 */ DroppedVisibility_Team0Only         UMETA(DisplayName = "DroppedVisibility_Team0Only"),
	/* 3 */	DroppedVisibility_Team1Only         UMETA(DisplayName = "DroppedVisibility_Team1Only"),
	/* 4 */	DroppedVisibility_FriendlyOnly      UMETA(DisplayName = "DroppedVisibility_FriendlyOnly"),
	/* 5 */	DroppedVisibility_EnemyOnly         UMETA(DisplayName = "DroppedVisibility_EnemyOnly")
};

UENUM(BlueprintType)
enum class EUpperBodyAnim : uint8
{
	/*  0 */	UBANIM_NONE                        UMETA(DisplayName = "UBANIM_NONE"),
	/*  1 */	UBANIM_NONE_Empty                  UMETA(DisplayName = "UBANIM_NONE_Empty"),
	/*  2 */	UBANIM_NONE_Large                  UMETA(DisplayName = "UBANIM_NONE_Large"),
	/*  3 */	UBANIM_WEAP_Reload                 UMETA(DisplayName = "UBANIM_WEAP_Reload"),
	/*  4 */	UBANIM_WEAP_RaiseLg                UMETA(DisplayName = "UBANIM_WEAP_RaiseLg"),
	/*  5 */	UBANIM_WEAP_LowerLg                UMETA(DisplayName = "UBANIM_WEAP_LowerLg"),
	/*  6 */	UBANIM_WEAP_Guard                  UMETA(DisplayName = "UBANIM_WEAP_Guard"),
	/*  7 */	UBANIM_GREN_Throwing_Over          UMETA(DisplayName = "UBANIM_GREN_Throwing_Over"),
	/*  8 */	UBANIM_GREN_Throwing_Under         UMETA(DisplayName = "UBANIM_GREN_Throwing_Under"),
	/*  9 */	UBANIM_GREN_PullingPin             UMETA(DisplayName = "UBANIM_GREN_PullingPin"),
	/* 10 */	UBANIM_GREN_RaiseGn                UMETA(DisplayName = "UBANIM_GREN_RaiseGn"),
	/* 11 */	UBANIM_GREN_LowerGn                UMETA(DisplayName = "UBANIM_GREN_LowerGn"),
	/* 12 */	UBANIM_GREN_Ready                  UMETA(DisplayName = "UBANIM_GREN_Ready"),
	/* 13 */	UBANIM_Breacher_USDeploy           UMETA(DisplayName = "UBANIM_Breacher_USDeploy"),
	/* 14 */	UBANIM_Breacher_USDeploy_Close     UMETA(DisplayName = "UBANIM_Breacher_USDeploy_Close"),
	/* 15 */	UBANIM_Breacher_OPFORDeploy        UMETA(DisplayName = "UBANIM_Breacher_OPFORDeploy"),
	/* 16 */	UBANIM_Breacher_OPFORDeploy_Close  UMETA(DisplayName = "UBANIM_Breacher_OPFORDeploy_Close"),
	/* 17 */	UBANIM_BINOC_RaiseBn               UMETA(DisplayName = "UBANIM_BINOC_RaiseBn"),
	/* 18 */	UBANIM_BINOC_RaiseZoom             UMETA(DisplayName = "UBANIM_BINOC_RaiseZoom"),
	/* 19 */	UBANIM_BINOC_LowerZoom             UMETA(DisplayName = "UBANIM_BINOC_LowerZoom"),
	/* 20 */	UBANIM_BINOC_LowerBn               UMETA(DisplayName = "UBANIM_BINOC_LowerBn"),
	/* 21 */	UBANIM_BINOC_Ready                 UMETA(DisplayName = "UBANIM_BINOC_Ready"),
	/* 22 */	UBANIM_BINOC_ReadyZoom             UMETA(DisplayName = "UBANIM_BINOC_ReadyZoom"),
	/* 23 */	UBANIM_RPG_RaiseRPG                UMETA(DisplayName = "UBANIM_RPG_RaiseRPG"),
	/* 24 */	UBANIM_RPG_LowerRPG                UMETA(DisplayName = "UBANIM_RPG_LowerRPG"),
	/* 25 */	UBANIM_RPG_Ready                   UMETA(DisplayName = "UBANIM_RPG_Ready"),
	/* 26 */	UBANIM_RPG_Guard                   UMETA(DisplayName = "UBANIM_RPG_Guard"),
	/* 27 */	UBANIM_RPG_RaiseRPG_NS             UMETA(DisplayName = "UBANIM_RPG_RaiseRPG_NS"),
	/* 28 */	UBANIM_RPG_LowerRPG_NS             UMETA(DisplayName = "UBANIM_RPG_LowerRPG_NS"),
	/* 29 */	UBANIM_RPG_Ready_NS                UMETA(DisplayName = "UBANIM_RPG_Ready_NS"),
	/* 30 */	UBANIM_RPG_Guard_NS                UMETA(DisplayName = "UBANIM_RPG_Guard_NS"),
	/* 31 */	UBANIM_AT4_RaiseAT4                UMETA(DisplayName = "UBANIM_AT4_RaiseAT4"),
	/* 32 */	UBANIM_AT4_LowerAT4                UMETA(DisplayName = "UBANIM_AT4_LowerAT4"),
	/* 33 */	UBANIM_AT4_Ready                   UMETA(DisplayName = "UBANIM_AT4_Ready"),
	/* 34 */	UBANIM_AT4_Guard                   UMETA(DisplayName = "UBANIM_AT4_Guard"),
	/* 35 */	UBANIM_BDM_RaiseBDM                UMETA(DisplayName = "UBANIM_BDM_RaiseBDM"),
	/* 36 */	UBANIM_BDM_LowerBDM                UMETA(DisplayName = "UBANIM_BDM_LowerBDM"),
	/* 37 */	UBANIM_PISTOL_Raise                UMETA(DisplayName = "UBANIM_PISTOL_Raise"),
	/* 38 */	UBANIM_PISTOL_Lower                UMETA(DisplayName = "UBANIM_PISTOL_Lower"),
	/* 39 */	UBANIM_PISTOL_Ready                UMETA(DisplayName = "UBANIM_PISTOL_Ready"),
	/* 40 */	UBANIM_PISTOL_Guard                UMETA(DisplayName = "UBANIM_PISTOL_Guard"),
	/* 41 */	UBANIM_HAND_MoveOut                UMETA(DisplayName = "UBANIM_HAND_MoveOut"),
	/* 42 */	UBANIM_HAND_Hold                   UMETA(DisplayName = "UBANIM_HAND_Hold"),
	/* 43 */	UBANIM_HAND_TakeCover              UMETA(DisplayName = "UBANIM_HAND_TakeCover"),
	/* 44 */	UBANIM_HAND_PointFwd               UMETA(DisplayName = "UBANIM_HAND_PointFwd"),
	/* 45 */	UBANIM_HAND_Ready                  UMETA(DisplayName = "UBANIM_HAND_Ready"),
	/* 46 */	UBANIM_HAND_DoubleTime             UMETA(DisplayName = "UBANIM_HAND_DoubleTime"),
	/* 47 */	UBANIM_HAND_Affirm                 UMETA(DisplayName = "UBANIM_HAND_Affirm"),
	/* 48 */	UBANIM_HAND_Neg                    UMETA(DisplayName = "UBANIM_HAND_Neg"),
	/* 49 */	UBANIM_HAND_MoveOutGn              UMETA(DisplayName = "UBANIM_HAND_MoveOutGn"),
	/* 50 */	UBANIM_HAND_HoldGn                 UMETA(DisplayName = "UBANIM_HAND_HoldGn"),
	/* 51 */	UBANIM_HAND_TakeCoverGn            UMETA(DisplayName = "UBANIM_HAND_TakeCoverGn"),
	/* 52 */	UBANIM_HAND_PointFwdGn             UMETA(DisplayName = "UBANIM_HAND_PointFwdGn"),
	/* 53 */	UBANIM_HAND_ReadyGn                UMETA(DisplayName = "UBANIM_HAND_ReadyGn"),
	/* 54 */	UBANIM_HAND_DoubleTimeGn           UMETA(DisplayName = "UBANIM_HAND_DoubleTimeGn"),
	/* 55 */	UBANIM_HAND_AffirmGn               UMETA(DisplayName = "UBANIM_HAND_AffirmGn"),
	/* 56 */	UBANIM_HAND_NegGn                  UMETA(DisplayName = "UBANIM_HAND_NegGn"),
	/* 57 */	UBANIM_HAND_MoveOutSm              UMETA(DisplayName = "UBANIM_HAND_MoveOutSm"),
	/* 58 */	UBANIM_HAND_HoldSm                 UMETA(DisplayName = "UBANIM_HAND_HoldSm"),
	/* 59 */	UBANIM_HAND_TakeCoverSm            UMETA(DisplayName = "UBANIM_HAND_TakeCoverSm"),
	/* 60 */	UBANIM_HAND_PointFwdSm             UMETA(DisplayName = "UBANIM_HAND_PointFwdSm"),
	/* 61 */	UBANIM_HAND_ReadySm                UMETA(DisplayName = "UBANIM_HAND_ReadySm"),
	/* 62 */	UBANIM_HAND_DoubleTimeSm           UMETA(DisplayName = "UBANIM_HAND_DoubleTimeSm"),
	/* 63 */	UBANIM_HAND_AffirmSm               UMETA(DisplayName = "UBANIM_HAND_AffirmSm"),
	/* 64 */	UBANIM_HAND_NegSm                  UMETA(DisplayName = "UBANIM_HAND_NegSm"),
	/* 65 */	UBANIM_Jav_RaiseJav                UMETA(DisplayName = "UBANIM_Jav_RaiseJav"),
	/* 66 */	UBANIM_Jav_LowerJav                UMETA(DisplayName = "UBANIM_Jav_LowerJav"),
	/* 67 */	UBANIM_Jav_Ready                   UMETA(DisplayName = "UBANIM_Jav_Ready"),
	/* 68 */	UBANIM_Jav_ReadyZoom               UMETA(DisplayName = "UBANIM_Jav_ReadyZoom"),
	/* 69 */	UBANIM_Jav_Guard                   UMETA(DisplayName = "UBANIM_Jav_Guard"),
	/* 70 */	UBANIM_Jav_RaiseZoom               UMETA(DisplayName = "UBANIM_Jav_RaiseZoom"),
	/* 71 */	UBANIM_Jav_LowerZoom               UMETA(DisplayName = "UBANIM_Jav_LowerZoom"),
	/* 72 */	UBANIM_TUBE_Raise                  UMETA(DisplayName = "UBANIM_TUBE_Raise"),
	/* 73 */	UBANIM_TUBE_Lower                  UMETA(DisplayName = "UBANIM_TUBE_Lower"),
	/* 74 */	UBANIM_TUBE_Guard                  UMETA(DisplayName = "UBANIM_TUBE_Guard"),
	/* 75 */	UBANIM_TUBE_Ready                  UMETA(DisplayName = "UBANIM_TUBE_Ready")
};

UENUM(BlueprintType)
enum class EFullBodyAnim : uint8
{
	/* 0 */	FBANIM_NONE           UMETA(DisplayName = "FBANIM_NONE"),
	/* 1 */	FBANIM_ROLL_Right     UMETA(DisplayName = "FBANIM_ROLL_Right"),
	/* 2 */	FBANIM_ROLL_Left      UMETA(DisplayName = "FBANIM_ROLL_Left"),
	/* 3 */	FBANIM_PARACHUTE_Jump UMETA(DisplayName = "FBANIM_PARACHUTE_Jump"),
	/* 4 */	FBANIM_PARACHUTE_Idle UMETA(DisplayName = "FBANIM_PARACHUTE_Idle"),
	/* 5 */	FBANIM_PLF_Pass       UMETA(DisplayName = "FBANIM_PLF_Pass"),
	/* 6 */	FBANIM_PLF_Fail       UMETA(DisplayName = "FBANIM_PLF_Fail"),
	/* 7 */	FBANIM_DIVE_Forward   UMETA(DisplayName = "FBANIM_DIVE_Forward")
};

UENUM(BlueprintType)
enum class ETeam : uint8
{
	/* 0 */	TEAM_UnAssigned   UMETA(DisplayName = "TEAM_UnAssigned"),
	/* 1 */	TEAM_US1          UMETA(DisplayName = "TEAM_US1"),
	/* 2 */	TEAM_US2          UMETA(DisplayName = "TEAM_US2"),
	/* 3 */	TEAM_ArmedNeutral UMETA(DisplayName = "TEAM_ArmedNeutral"),
	/* 4 */	TEAM_NonCombatant UMETA(DisplayName = "TEAM_NonCombatant"),
	/* 5 */	TEAM_OpForce1     UMETA(DisplayName = "TEAM_OpForce1"),
	/* 6 */	TEAM_OpForce2     UMETA(DisplayName = "TEAM_OpForce2")
};

UENUM(BlueprintType)
enum class EDeathAnim : uint8
{
	DEATH_None              UMETA(DisplayName = "DEATH_None"),
	DEATH_PrnKillMiles      UMETA(DisplayName = "DEATH_PrnKillMiles"),
	DEATH_CrhKillMiles      UMETA(DisplayName = "DEATH_CrhKillMiles"),
	DEATH_StdKillMiles      UMETA(DisplayName = "DEATH_StdKillMiles"),
	DEATH_StdKillMilesB     UMETA(DisplayName = "DEATH_StdKillMilesB"),
	DEATH_FlyingKillFwd     UMETA(DisplayName = "DEATH_FlyingKillFwd"),
	DEATH_FlyingKillFwdB    UMETA(DisplayName = "DEATH_FlyingKillFwdB"),
	DEATH_FlyingKillFwdLand UMETA(DisplayName = "DEATH_FlyingKillFwdLand"),
	DEATH_FlyingKillBk      UMETA(DisplayName = "DEATH_FlyingKillBk"),
	DEATH_FlyingKillBkB     UMETA(DisplayName = "DEATH_FlyingKillBkB"),
	DEATH_FlyingKillBkLand  UMETA(DisplayName = "DEATH_FlyingKillBkLand"),
	DEATH_StdKillHdFw       UMETA(DisplayName = "DEATH_StdKillHdFw"),
	DEATH_StdKillChst       UMETA(DisplayName = "DEATH_StdKillChst"),
	DEATH_StdKillChstSpin   UMETA(DisplayName = "DEATH_StdKillChstSpin"),
	DEATH_StdKillLt         UMETA(DisplayName = "DEATH_StdKillLt"),
	DEATH_StdKillRt         UMETA(DisplayName = "DEATH_StdKillRt"),
	DEATH_StdKillBk         UMETA(DisplayName = "DEATH_StdKillBk"),
	DEATH_CrhKillHd         UMETA(DisplayName = "DEATH_CrhKillHd"),
	DEATH_CrhKillChstSpin   UMETA(DisplayName = "DEATH_CrhKillChstSpin"),
	DEATH_CrhKillLt         UMETA(DisplayName = "DEATH_CrhKillLt"),
	DEATH_CrhKillRt         UMETA(DisplayName = "DEATH_CrhKillRt"),
	DEATH_CrhKillBack       UMETA(DisplayName = "DEATH_CrhKillBack"),
	DEATH_PrnKillHd         UMETA(DisplayName = "DEATH_PrnKillHd"),
	DEATH_ParachuteDead     UMETA(DisplayName = "DEATH_ParachuteDead"),
	DEATH_PLFDead           UMETA(DisplayName = "DEATH_PLFDead"),
	DEATH_PLFMilesDead      UMETA(DisplayName = "DEATH_PLFMilesDead")
};

UENUM(BlueprintType)
enum class ECombatEffectEvent : uint8
{
	/* 0 */	CE_EVENT_BULLETWHIP    UMETA(DisplayName = "CE_EVENT_BULLETWHIP"),
	/* 1 */	CE_EVENT_BULLETCRACK   UMETA(DisplayName = "CE_EVENT_BULLETCRACK"),
	/* 2 */	CE_EVENT_FLASHBANG     UMETA(DisplayName = "CE_EVENT_FLASHBANG"),
	/* 3 */	CE_EVENT_EXPLOSION     UMETA(DisplayName = "CE_EVENT_EXPLOSION"),
	/* 4 */	CE_EVENT_SPRINT        UMETA(DisplayName = "CE_EVENT_SPRINT"),
	/* 5 */	CE_EVENT_JUMP          UMETA(DisplayName = "CE_EVENT_JUMP"),
	/* 6 */	CE_EVENT_DIVE          UMETA(DisplayName = "CE_EVENT_DIVE"),
	/* 7 */	CE_EVENT_OBJECTIVE     UMETA(DisplayName = "CE_EVENT_OBJECTIVE"),
	/* 8 */	CE_EVENT_SUPPORTING    UMETA(DisplayName = "CE_EVENT_SUPPORTING"),
	/* 9 */	CE_EVENT_CLIMBING      UMETA(DisplayName = "CE_EVENT_CLIMBING"),
	/*10 */	CE_EVENT_INJURY        UMETA(DisplayName = "CE_EVENT_INJURY"),
	/*11 */	CE_EVENT_BLEEDING      UMETA(DisplayName = "CE_EVENT_BLEEDING")
};

UENUM(BlueprintType)
enum class ECommoType : uint8
{
	/* 0 */	COMMOTYPE_Hand     UMETA(DisplayName = "COMMOTYPE_Hand"),
	/* 1 */	COMMOTYPE_Whisper  UMETA(DisplayName = "COMMOTYPE_Whisper"),
	/* 2 */	COMMOTYPE_Shout    UMETA(DisplayName = "COMMOTYPE_Shout"),
	/* 3 */	COMMOTYPE_Radio    UMETA(DisplayName = "COMMOTYPE_Radio"),
	/* 4 */	COMMOTYPE_Squad    UMETA(DisplayName = "COMMOTYPE_Squad"),
	/* 5 */	COMMOTYPE_Global   UMETA(DisplayName = "COMMOTYPE_Global")
};

UENUM(BlueprintType)
enum class EHealthCondition : uint8
{
	/* 0 */	HC_GREEN   UMETA(DisplayName = "HC_GREEN"),
	/* 1 */	HC_YELLOW  UMETA(DisplayName = "HC_YELLOW"),
	/* 2 */	HC_RED     UMETA(DisplayName = "HC_RED"),
	/* 3 */	HC_DEAD    UMETA(DisplayName = "HC_DEAD")
};

UENUM(BlueprintType)
enum class EWoundSeverity : uint8
{
	/* 0 */	WS_NotWounded  UMETA(DisplayName = "WS_NotWounded"),
	/* 1 */	WS_Treated     UMETA(DisplayName = "WS_Treated"),
	/* 2 */	WS_Minor       UMETA(DisplayName = "WS_Minor"),
	/* 3 */	WS_Moderate    UMETA(DisplayName = "WS_Moderate"),
	/* 4 */	WS_Urgent      UMETA(DisplayName = "WS_Urgent"),
	/* 5 */	WS_Critical    UMETA(DisplayName = "WS_Critical")
};

UENUM(BlueprintType)
enum class EATypes : uint8
{
	/* 0 */	NPC_none     UMETA(DisplayName = "NPC_none"),
	/* 1 */	NPC_civilian UMETA(DisplayName = "NPC_civilian"),
	/* 2 */	NPC_soldier  UMETA(DisplayName = "NPC_soldier"),
	/* 3 */	NPC_doctor   UMETA(DisplayName = "NPC_doctor"),
	/* 4 */	NPC_pilot    UMETA(DisplayName = "NPC_pilot"),
	/* 5 */	NPC_friendly UMETA(DisplayName = "NPC_friendly"),
	/* 6 */	NPC_squad    UMETA(DisplayName = "NPC_squad")
};

UENUM(BlueprintType)
enum class ERole : uint8
{
	/* 0 */	STARTROLE_UnitFollower   UMETA(DisplayName = "STARTROLE_UnitFollower"),
	/* 1 */	STARTROLE_UnitLeader     UMETA(DisplayName = "STARTROLE_UnitLeader")
};

UENUM(BlueprintType)
enum class ERank : uint8
{
	/* 0 */	RANK_UnAssigned   UMETA(DisplayName = "RANK_UnAssigned"),
	/* 1 */	RANK_E1_PVT       UMETA(DisplayName = "RANK_E1_PVT"),
	/* 2 */	RANK_E2_PV2       UMETA(DisplayName = "RANK_E2_PV2"),
	/* 3 */	RANK_E3_PFC       UMETA(DisplayName = "RANK_E3_PFC"),
	/* 4 */	RANK_E4_SPC       UMETA(DisplayName = "RANK_E4_SPC"),
	/* 5 */	RANK_E4_CPL       UMETA(DisplayName = "RANK_E4_CPL"),
	/* 6 */	RANK_E5_SGT       UMETA(DisplayName = "RANK_E5_SGT"),
	/* 7 */	RANK_E6_SSG       UMETA(DisplayName = "RANK_E6_SSG"),
	/* 8 */	RANK_E7_SFC       UMETA(DisplayName = "RANK_E7_SFC"),
	/* 9 */	RANK_E8_MSG       UMETA(DisplayName = "RANK_E8_MSG"),
	/* 10*/	RANK_E8_1SG       UMETA(DisplayName = "RANK_E8_1SG"),
	/* 11*/	RANK_E9_SMG       UMETA(DisplayName = "RANK_E9_SMG"),
	/* 12*/	RANK_E9_CSM       UMETA(DisplayName = "RANK_E9_CSM"),
	/* 13*/	RANK_E9_SMA       UMETA(DisplayName = "RANK_E9_SMA")
};

UENUM(BlueprintType)
enum class ESoldierRole : uint8
{
	/* 0 */	ROLE_None          UMETA(DisplayName = "ROLE_None"),
	/* 1 */	ROLE_SquadLeader   UMETA(DisplayName = "ROLE_SquadLeader"),
	/* 2 */	ROLE_FTLeader      UMETA(DisplayName = "ROLE_FTLeader"),
	/* 3 */	ROLE_FTMember      UMETA(DisplayName = "ROLE_FTMember"),
	/* 4 */	ROLE_GroupLeader   UMETA(DisplayName = "ROLE_GroupLeader"),
	/* 5 */	ROLE_GroupFollower UMETA(DisplayName = "ROLE_GroupFollower"),
	/* 6 */	ROLE_Error         UMETA(DisplayName = "ROLE_Error")
};

UENUM(BlueprintType)
enum class EInitialParaState : uint8
{
	/* 0 */	PARA_Default     UMETA(DisplayName = "PARA_Default"),
	/* 1 */	PARA_Deploy      UMETA(DisplayName = "PARA_Deploy"),
	/* 2 */ PARA_Idle        UMETA(DisplayName = "PARA_Idle"),
	/* 3 */	PARA_Collapse    UMETA(DisplayName = "PARA_Collapse"),
	/* 4 */	PARA_Ground      UMETA(DisplayName = "PARA_Ground"),
	/* 5 */	PARA_Flare       UMETA(DisplayName = "PARA_Flare"),
	/* 6 */	PARA_Premature   UMETA(DisplayName = "PARA_Premature"),
	/* 7 */	PARA_Rig         UMETA(DisplayName = "PARA_Rig")
};

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EFireTeam : uint8
{
	FTEAM_None    UMETA(DisplayName = "FTEAM_None"),
	FTEAM_Alpha   UMETA(DisplayName = "FTEAM_Alpha"),
	FTEAM_Bravo   UMETA(DisplayName = "FTEAM_Bravo"),
	FTEAM_Charlie UMETA(DisplayName = "FTEAM_Charlie"),
	FTEAM_Delta   UMETA(DisplayName = "FTEAM_Delta")
};

UENUM(BlueprintType)
enum class ELightEffect : uint8
{
/* 0 */	LE_None                   UMETA(DisplayName = "LE_None"),
/* 1 */	LE_TorchWaver             UMETA(DisplayName = "LE_TorchWaver"),
/* 2 */ LE_FireWaver              UMETA(DisplayName = "LE_FireWaver"),
/* 3 */	LE_WateryShimmer          UMETA(DisplayName = "LE_WateryShimmer"),
/* 4 */	LE_Searchlight            UMETA(DisplayName = "LE_Searchlight"),
/* 5 */	LE_SlowWave               UMETA(DisplayName = "LE_SlowWave"),
/* 6 */	LE_FastWave               UMETA(DisplayName = "LE_FastWave"),
/* 7 */	LE_CloudCast              UMETA(DisplayName = "LE_CloudCast"),
/* 8 */	LE_StaticSpot             UMETA(DisplayName = "LE_StaticSpot"),
/* 9 */	LE_Shock                  UMETA(DisplayName = "LE_Shock"),
/* 10*/	LE_Disco                  UMETA(DisplayName = "LE_Disco"),
/* 11*/	LE_Warp                   UMETA(DisplayName = "LE_Warp"),
/* 12*/	LE_Spotlight              UMETA(DisplayName = "LE_Spotlight"),
/* 13*/	LE_NonIncidence           UMETA(DisplayName = "LE_NonIncidence"),
/* 14*/	LE_Shell                  UMETA(DisplayName = "LE_Shell"),
/* 15*/	LE_OmniBumpMap            UMETA(DisplayName = "LE_OmniBumpMap"),
/* 16*/	LE_Interference           UMETA(DisplayName = "LE_Interference"),
/* 17*/	LE_Cylinder               UMETA(DisplayName = "LE_Cylinder"),
/* 18*/	LE_Rotor                  UMETA(DisplayName = "LE_Rotorn"),
/* 19*/	LE_Negative               UMETA(DisplayName = "LE_Negative"),
/* 20*/	LE_Sunlight               UMETA(DisplayName = "LE_Sunlight"),
/* 21*/ LE_QuadraticNonIncidence  UMETA(DisplayName = "LE_QuadraticNonIncidence")
};

UENUM(BlueprintType)
enum class ELightType : uint8
{
	/* 0 */	LT_None                UMETA(DisplayName = "LT_None"),
	/* 1 */	LT_Steady              UMETA(DisplayName = "LT_Steady"),
	/* 2 */ LT_Pulse               UMETA(DisplayName = "LT_Pulse"),
	/* 3 */	LT_Blink               UMETA(DisplayName = "LT_Blink"),
	/* 4 */	LT_Flicker             UMETA(DisplayName = "LT_Flicker"),
	/* 5 */	LT_Strobe              UMETA(DisplayName = "LT_Strobe"),
	/* 6 */	LT_BackdropLight       UMETA(DisplayName = "LT_BackdropLight"),
	/* 7 */	LT_SubtlePulse         UMETA(DisplayName = "LT_SubtlePulse"),
	/* 8 */	LT_TexturePaletteOnce  UMETA(DisplayName = "LT_TexturePaletteOnce"),
	/* 9 */	LT_TexturePaletteLoop  UMETA(DisplayName = "LT_TexturePaletteLoop"),
	/* 10*/	LT_FadeOut             UMETA(DisplayName = "LT_FadeOut")
};

UENUM(BlueprintType)
enum class EDrawType : uint8
{
	DT_None           UMETA(DisplayName = "DT_None"),
	DT_Sprite         UMETA(DisplayName = "DT_Sprite"),
	DT_Mesh           UMETA(DisplayName = "DT_Mesh"),
	DT_Brush          UMETA(DisplayName = "DT_Brush"),
	DT_RopeSprite     UMETA(DisplayName = "DT_RopeSprite"),
	DT_VerticalSprite UMETA(DisplayName = "DT_VerticalSprite"),
	DT_Terraform      UMETA(DisplayName = "DT_Terraform"),
	DT_SpriteAnimOnce UMETA(DisplayName = "DT_SpriteAnimOnce"),
	DT_StaticMesh     UMETA(DisplayName = "DT_StaticMesh"),
	DT_DrawType       UMETA(DisplayName = "DT_DrawType"),
	DT_Particle       UMETA(DisplayName = "DT_Particle"),
	DT_AntiPortal     UMETA(DisplayName = "DT_AntiPortal"),
	DT_FluidSurface   UMETA(DisplayName = "DT_FluidSurface")
};

UENUM(BlueprintType)
enum class EAmmoType : uint8
{
	AMMO_None              UMETA(DisplayName = "AMMO_None"),
	AMMO_Explosion         UMETA(DisplayName = "AMMO_Explosion"),
	AMMO_Frag              UMETA(DisplayName = "AMMO_Frag"),
	AMMO_GrenadeImpact     UMETA(DisplayName = "AMMO_GrenadeImpact"),
	AMMO_GrenadeExplosion  UMETA(DisplayName = "AMMO_GrenadeExplosion"),
	AMMO_127Sniper         UMETA(DisplayName = "AMMO_127Sniper"),
	AMMO_127HMG            UMETA(DisplayName = "AMMO_127HMG"),
	AMMO_545mm             UMETA(DisplayName = "AMMO_545mm"),
	AMMO_556mm             UMETA(DisplayName = "AMMO_556mm"),
	AMMO_762mm             UMETA(DisplayName = "AMMO_762mm"),
	AMMO_762Sniper         UMETA(DisplayName = "AMMO_762Sniper"),
	AMMO_Shot00            UMETA(DisplayName = "AMMO_Shot00"),
	AMMO_LargeArms         UMETA(DisplayName = "AMMO_LargeArms"),
	AMMO_SmallArms         UMETA(DisplayName = "AMMO_SmallArms"),
	AMMO_Rocket            UMETA(DisplayName = "AMMO_Rocket"),
	AMMO_Incendiary        UMETA(DisplayName = "AMMO_Incendiary"),
	AMMO_9x19mm            UMETA(DisplayName = "AMMO_9x19mm"),
	AMMO_BreacherExplosion UMETA(DisplayName = "AMMO_BreacherExplosion"),
	AMMO_50Cal             UMETA(DisplayName = "AMMO_50Cal")
};

UENUM(BlueprintType)
enum class ECollisionType : uint8
{
	CT_None       UMETA(DisplayName = "CT_None"),
	CT_HitWall    UMETA(DisplayName = "CT_HitWall"),
	CT_Landed     UMETA(DisplayName = "CT_Landed"),
	CT_Touch      UMETA(DisplayName = "CT_Touch")
};

UENUM(BlueprintType)
enum class EProjectileState : uint8
{
	PROJ_Flying     UMETA(DisplayName = "PROJ_Flying"),
	PROJ_BlowUp     UMETA(DisplayName = "PROJ_BlowUp"),
	PROJ_Dud        UMETA(DisplayName = "PROJ_Dud")
};

UENUM(BlueprintType)
enum class ENewAuxMode : uint8
{
	NEWMODE_NoChange        UMETA(DisplayName = "NEWMODE_NoChange"),
	NEWMODE_SwitchToAux     UMETA(DisplayName = "NEWMODE_SwitchToAux"),
	NEWMODE_SwitchToNormal  UMETA(DisplayName = "NEWMODE_SwitchToNormal")
};

UENUM(BlueprintType)
enum class ERateofFire : uint8
{
	/* 0 */	ROF_None        UMETA(DisplayName = "ROF_None"),
	/* 1 */ ROF_Single      UMETA(DisplayName = "ROF_Single"),
	/* 2 */ ROF_Burst       UMETA(DisplayName = "ROF_Burst"),
	/* 3 */ ROF_Auto        UMETA(DisplayName = "ROF_Auto"),
	/* 4 */ ROF_SingleGren  UMETA(DisplayName = "ROF_SingleGren")
};

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
/* 0 */	WEAPON_None     UMETA(DisplayName = "WEAPON_None"),
/* 1 */	WEAPON_Unknown  UMETA(DisplayName = "WEAPON_Unknown"),
/* 2 */ WEAPON_Rifle    UMETA(DisplayName = "WEAPON_Rifle"),
/* 3 */ WEAPON_SAW      UMETA(DisplayName = "WEAPON_SAW"),
/* 4 */ WEAPON_Sniper   UMETA(DisplayName = "WEAPON_Sniper"),
/* 5 */ WEAPON_HMG      UMETA(DisplayName = "WEAPON_HMG"),
/* 6 */ WEAPON_Gren     UMETA(DisplayName = "WEAPON_Gren"),
/* 7 */ WEAPON_Rocket   UMETA(DisplayName = "WEAPON_Rocket"),
/* 8 */ WEAPON_Javelin  UMETA(DisplayName = "WEAPON_Javelin"),
/* 9 */ WEAPON_Pistol   UMETA(DisplayName = "WEAPON_Pistol")
};

UENUM(BlueprintType)
enum class EWeaponClientState : uint8
{
	WCS_None         UMETA(DisplayName = "WCS_None"),
	WCS_Hidden       UMETA(DisplayName = "WCS_Hidden"),
	WCS_BringUp      UMETA(DisplayName = "WCS_BringUp"),
	WCS_PutDown      UMETA(DisplayName = "WCS_PutDown"),
	WCS_ReadyToFire  UMETA(DisplayName = "WCS_ReadyToFire")
};

UENUM(BlueprintType)
enum class EContactSize : uint8
{
	SIZE_Unknown   UMETA(DisplayName = "SIZE_Unknown"),
	SIZE_Single    UMETA(DisplayName = "SIZE_Single"),
	SIZE_Fireteam  UMETA(DisplayName = "SIZE_Fireteam"),
	SIZE_Squad     UMETA(DisplayName = "SIZE_Squad"),
	SIZE_Platoon   UMETA(DisplayName = "SIZE_Platoon"),
	SIZE_Company   UMETA(DisplayName = "SIZE_Company"),
	SIZE_Battalion UMETA(DisplayName = "SIZE_Battalion")
};

UENUM(BlueprintType)
enum class EContactGoal : uint8
{
	GOAL_Unknown UMETA(DisplayName = "GOAL_Unknown"),
	GOAL_Attack  UMETA(DisplayName = "GOAL_Attack"),
	GOAL_Defend  UMETA(DisplayName = "GOAL_Defend"),
	GOAL_GoTo    UMETA(DisplayName = "GOAL_GoTo"),
	GOAL_Avoid   UMETA(DisplayName = "GOAL_Avoid"),
	GOAL_Flee    UMETA(DisplayName = "GOAL_Flee"),
	GOAL_Hold    UMETA(DisplayName = "GOAL_Hold")
};

UENUM(BlueprintType)
enum class EContactSpecialWeapons : uint8
{
	SPEC_Unknown       UMETA(DisplayName = "TYPE_Unknown"),
	SPEC_None          UMETA(DisplayName = "TYPE_Infantry"),
	SPEC_SmallArms     UMETA(DisplayName = "SPEC_SmallArms"),
	SPEC_Antipersonnel UMETA(DisplayName = "SPEC_Antipersonnel"),
	SPEC_Antitank      UMETA(DisplayName = "SPEC_Antitank"),
	SPEC_Antiair       UMETA(DisplayName = "SPEC_Antiair")
};

UENUM(BlueprintType)
enum class EContactType : uint8
{
	TYPE_Unknown      UMETA(DisplayName = "TYPE_Unknown"),
	TYPE_Infantry     UMETA(DisplayName = "TYPE_Infantry"),
	TYPE_RotaryWing   UMETA(DisplayName = "TYPE_RotaryWing"),
	TYPE_FixedWing    UMETA(DisplayName = "TYPE_FixedWing"),
	TYPE_Emplacement  UMETA(DisplayName = "TYPE_Emplacement")
};

UENUM(BlueprintType)
enum class EContactAwareness : uint8
{
	AWARE_Unknown  UMETA(DisplayName = "AWARE_Unknown"),
	AWARE_Unaware  UMETA(DisplayName = "AWARE_Unaware"),
	AWARE_Aware    UMETA(DisplayName = "AWARE_Aware"),
	AWARE_Hear     UMETA(DisplayName = "AWARE_Hear"),
	AWARE_See      UMETA(DisplayName = "AWARE_See"),
	AWARE_Shoot    UMETA(DisplayName = "AWARE_Shoot")
};

UENUM(BlueprintType)
enum class EStatWeaponType : uint8
{
	WEAP_None          UMETA(DisplayName = "WEAP_None"),
	WEAP_Grenade       UMETA(DisplayName = "WEAP_Grenade"),
	WEAP_Rocket        UMETA(DisplayName = "WEAP_Rocket"),
	WEAP_Pistol        UMETA(DisplayName = "WEAP_Pistol"),
	WEAP_SniperRifle   UMETA(DisplayName = "WEAP_SniperRifle"),
	WEAP_MachineGun    UMETA(DisplayName = "WEAP_MachineGun"),
	WEAP_AssaultRifle  UMETA(DisplayName = "WEAP_AssaultRifle")
};

UENUM(BlueprintType)
enum class ESuppressorState : uint8
{
	SUPSTATE_None    UMETA(DisplayName = "SUPSTATE_None"),
	SUPSTATE_On      UMETA(DisplayName = "SUPSTATE_On"),
	SUPSTATE_Off     UMETA(DisplayName = "SUPSTATE_Off")
};

UENUM(BlueprintType)
enum class EGameState : uint8
{
	GS_MatchInProgress			UMETA(DisplayName = "GS_MatchInProgress"),
	GS_MatchOver				UMETA(DisplayName = "GS_MatchOver"),
	GS_TournamentStartup		UMETA(DisplayName = "GS_TournamentStartup"),
	GS_StartMatchCountdown		UMETA(DisplayName = "GS_StartMatchCountdown"),
	GS_WarmupCountdown			UMETA(DisplayName = "GS_WarmupCountdown")
};

static const uint8 NUM_WMSLOTS = 6;
static const uint8 WMSLOT_BARREL = 5;
static const uint8 WMSLOT_BOTTOM = 4;
static const uint8 WMSLOT_RIGHT = 3;
static const uint8 WMSLOT_LEFT = 2;
static const uint8 WMSLOT_TOP = 1;
static const uint8 WMSLOT_MAIN_RAIL = 0;
static const uint8 ANIM_CHANNEL_SPLITANIMS = 15;
static const uint8 ANIM_CHANNEL_TRANSITIONS = 13;
static const uint8 ANIM_CHANNEL_BASE = 0;
static const uint8 WEAPON_ACTION_RIGHT_RAIL = 10;
static const uint8 WEAPON_ACTION_LEFT_RAIL = 9;
static const uint8 WEAPON_ACTION_SUPPRESOR = 8;
static const uint8 WEAPON_ACTION_DROP = 7;
static const uint8 WEAPON_ACTION_ZOOM = 6;
static const uint8 WEAPON_ACTION_SUPPORT = 5;
static const uint8 WEAPON_ACTION_CHANGEFIREMODE = 4;
static const uint8 WEAPON_ACTION_RELOAD = 3;
static const uint8 WEAPON_ACTION_FIXJAM = 2;
static const uint8 WEAPON_ACTION_ALTFIRE = 1;
static const uint8 WEAPON_ACTION_FIRE = 0;
static const uint8 FORCE_ANIM_REPLICATION = 128;
static const uint8 ROCKET_ATTACH_AMMOROUND = 16;
static const uint8 WEAPON_ATTACH_DONTSWAP = 8;
static const uint8 WEAPON_ATTACH_SUPPRESSOR = 4;
static const uint8 WEAPON_ATTACH_SUPPORTED = 2;
static const uint8 WEAPON_ATTACH_INHAND = 1;
static const uint8 PARACHUTE_ATTACH_RIG = 7;
static const uint8 PARACHUTE_ATTACH_PREMATURE = 6;
static const uint8 PARACHUTE_ATTACH_FLARE = 5;
static const uint8 PARACHUTE_ATTACH_GROUND = 4;
static const uint8 PARACHUTE_ATTACH_COLLAPSE = 3;
static const uint8 PARACHUTE_ATTACH_IDLE = 2;
static const uint8 PARACHUTE_ATTACH_DEPLOY = 1;
static const uint8 PARACHUTE_ATTACH_NONE = 0;
static const float MAXPRONESTEPHEIGHT = 20.0;
static const float MINFLOORZ = 0.7;
static const float MAXSTEPHEIGHT = 30.0;
static const FString GameType = "AAO";
static const float HEARTBEAT_DELAY = 60.0;
static const int32 UpdateRate = 60;
static const int32 UnknownPingTime = 9999;
static const int32 QBTN_YesNoCancel = 50;
static const int32 QBTN_YesNo = 48;
static const int32 QBTN_AbortRetry = 68;
static const int32 QBTN_OkCancel = 3;
static const int32 QBTN_Ignore = 128;
static const int32 QBTN_Abort = 64;
static const int32 QBTN_No = 32;
static const int32 QBTN_Yes = 16;
static const int32 QBTN_Continue = 8;
static const int32 QBTN_Retry = 4;
static const int32 QBTN_Cancel = 2;
static const int32 QBTN_Ok = 1;
static const int32 Counter = 0;
static const int32 DoCounter = 1;
static const int32 SNIPERTOUR = 4;
static const int32 kItemNone = -1;
static const int32 kStateMax = 4;
static const int32 kStateDisabled = 3;
static const int32 kStateClick = 2;
static const int32 kStateOver = 1;
static const int32 kStateNormal = 0;
static const int32 kBorderAlpha = 1;
static const int32 kBorderHollow = 0;
static const int32 kQuick = 4;
static const int32 kSizeBody = 2;
static const int32 kSizeLarge = 1;
static const int32 kSizeSmall = 0;
static const int32 kScrollH = 2;
static const int32 kScrollV = 1;
static const int32 F_Test = 8;
static const int32 F_Arial14 = 7;
static const int32 F_WebLink = 6;
static const int32 F_SuperExtraLarge = 5;
static const int32 F_ExtraLarge = 4;
static const int32 F_LargeBold = 3;
static const int32 F_Large = 2;
static const int32 F_Bold = 1;
static const int32 F_Normal = 0;

static const int32 UIE_None = 0;
static const int32 UIE_Training = 1;
static const int32 UIE_MPMain = 2;
static const int32 UIE_QuickMP = 3;
static const int32 UIE_Settings = 4;
static const int32 UIE_Credits = 5;
static const int32 UIE_Quit = 6;
static const int32 UIE_MainMenu = 7;
static const int32 UIE_ConfirmQuit = 8;
static const int32 UIE_GoArmy = 9;
static const int32 UIE_ArmyOps = 10;
static const int32 UIE_ParentalLink = 11;
static const int32 UIE_OnlineHelp = 13;
static const int32 UIE_Resume = 14;
static const int32 UIE_CreditsArmy = 15;
static const int32 UIE_Disconnect = 16;
static const int32 UIE_ParentalControl = 17;
static const int32 UIE_Maximize = 21;
static const int32 UIE_Close = 22;
static const int32 UIE_GettingStarted = 30;
static const int32 UIE_GettingStartedPrev = 31;
static const int32 UIE_GettingStartedNext = 32;
static const int32 UIE_MissionSelect = 100;
static const int32 UIE_TourPrev = 104;
static const int32 UIE_TourNext = 105;
static const int32 UIE_MissionPrev = 106;
static const int32 UIE_MissionNext = 107;
static const int32 UIE_TourBriefSelect = 110;
static const int32 UIE_TourBriefBack = 113;
static const int32 UIE_TourBriefPrevPage = 111;
static const int32 UIE_TourBriefNextPage = 112;
static const int32 UIE_HistoryBrief = 120;
static const int32 UIE_HistoryBriefPrevPage = 121;
static const int32 UIE_HistoryBriefNextPage = 122;
static const int32 UIE_MissionBrief = 130;
static const int32 UIE_MissionBriefPrevPage = 131;
static const int32 UIE_MissionBriefNextPage = 132;
static const int32 UIE_PlayMission = 140;
static const int32 UIE_CreateAccount = 200;
static const int32 UIE_Login = 201;
static const int32 UIE_ServerBrowser = 202;
static const int32 UIE_LoginExit = 203;
static const int32 UIE_GameSpyArcade = 204;
static const int32 UIE_TestAccount = 205;
static const int32 UIE_ServerBrowserSCI = 206;
static const int32 UIE_ParentAccept = 325;
static const int32 UIE_SettingsControls = 400;
static const int32 UIE_ControlsViewSettings = 410;
static const int32 UIE_ControlsMovement = 411;
static const int32 UIE_ControlsCombat = 412;
static const int32 UIE_ControlsComm = 413;
static const int32 UIE_ControlsMisc = 414;
static const int32 UIE_SettingsVideo = 420;
static const int32 UIE_SettingsVideoAdvanced = 421;
static const int32 UIE_SettingsVideoDecals = 422;
static const int32 UIE_SettingsAudio = 430;
static const int32 UIE_SettingsHUD = 440;
static const int32 UIE_SettingsWeaponMod = 450;
static const int32 UIE_RefreshWeaponMod = 451;
static const int32 UIE_ResetDefaultsAll = 550;
static const int32 UIE_ResetDefaultsView = 551;
static const int32 UIE_ResetDefaultsMovement = 552;
static const int32 UIE_ResetDefaultsCombat = 553;
static const int32 UIE_ResetDefaultsMisc = 554;
static const int32 UIE_AcceptSkinTone = 555;
static const int32 UIE_ResetDefaultsComm = 556;
static const int32 UIE_ResetDefaultVideo = 560;
static const int32 UIE_AcceptNewVideo = 561;
static const int32 UIE_ResetDefaultVideoAdvanced = 562;
static const int32 UIE_AcceptNewVideoAdvanced = 563;
static const int32 UIE_ResetDefaultVideoDecals = 564;
static const int32 UIE_AcceptNewVideoDecals = 565;
static const int32 UIE_ResetDefaultAudio = 570;
static const int32 UIE_AcceptNewAudio = 571;
static const int32 UIE_ResetDefaultHUD = 580;
static const int32 UIE_UpdateServerList = 800;
static const int32 UIE_RefreshServerList = 801;
static const int32 UIE_EditFilters = 802;
static const int32 UIE_RefreshSelected = 803;
static const int32 UIE_PrevPlayerList = 804;
static const int32 UIE_NextPlayerList = 805;
static const int32 UIE_SortOfficial = 810;
static const int32 UIE_SortMiles = 811;
static const int32 UIE_SortPassword = 812;
static const int32 UIE_SortFavorite = 813;
static const int32 UIE_SortServerName = 814;
static const int32 UIE_SortPlayers = 815;
static const int32 UIE_SortPing = 816;
static const int32 UIE_SortTour = 817;
static const int32 UIE_SortMapName = 818;
static const int32 UIE_JoinServer = 850;
static const int32 UIE_HomeLANLeasing = 851;
static const int32 UIE_SCILeasing = 852;
static const int32 UIE_MsgBoxYes = 1000;
static const int32 UIE_MsgBoxNo = 1001;
static const int32 SID_Main = 0;
static const int32 SID_Training = 1;
static const int32 SID_MPMain = 2;
static const int32 SID_QuickMP = 3;
static const int32 SID_Settings = 4;
static const int32 SID_Credits = 5;
static const int32 SID_CreditsArmy = 6;
static const int32 SID_ParentalControl = 7;
static const int32 SID_Obstacle = 10;
static const int32 SID_RifleRange = 11;
static const int32 SID_GettingStarted = 30;
static const int32 SID_Obs1 = 31;
static const int32 SID_Obs2 = 32;
static const int32 SID_Obs3 = 33;
static const int32 SID_Obs4 = 34;
static const int32 SID_Obs5 = 35;
static const int32 SID_RR1 = 41;
static const int32 SID_RR2 = 42;
static const int32 SID_RR3 = 43;
static const int32 SID_RR4 = 44;
static const int32 SID_RR5 = 45;
static const int32 SID_MissionSelect = 100;
static const int32 SID_TourBrief = 101;
static const int32 SID_HistoryBrief = 102;
static const int32 SID_MissionBriefSP = 103;
static const int32 SID_MissionBriefMP = 104;
static const int32 SID_Login = 201;
static const int32 SID_ServerBrowser = 202;
static const int32 SID_FilterEditor = 203;
static const int32 SID_SettingsControls = 400;
static const int32 SID_ControlsViewSettings = 410;
static const int32 SID_ControlsMovement = 411;
static const int32 SID_ControlsCombat = 412;
static const int32 SID_ControlsComm = 413;
static const int32 SID_ControlsMisc = 414;
static const int32 SID_SettingsVideo = 420;
static const int32 SID_SettingsVideoAdvanced = 421;
static const int32 SID_SettingsVideoDecals = 422;
static const int32 SID_SettingsAudio = 430;
static const int32 SID_SettingsHUD = 440;
static const int32 SID_SettingsWeaponMod = 450;
static const int32 SID_StaticMainMenu = 666;
static const int32 SID_TitleMainMenu = 700;
static const int32 SID_TitleSettings = 701;
static const int32 SID_TitleTraining = 702;
static const int32 SID_TitleObstacle = 703;
static const int32 SID_TitleRifleRange = 704;
static const int32 SID_SubMainMenu = 800;
static const int32 SID_SubSettings = 801;
static const int32 SID_SubTraining = 802;
static const int32 SID_SubObstacle = 803;
static const int32 SID_SubRifleRange = 804;
static const int32 ID_None = 0;
static const int32 ID_Training = 1;
static const int32 ID_MPMain = 2;
static const int32 ID_QuickMP = 3;
static const int32 ID_Settings = 4;
static const int32 ID_Credits = 5;
static const int32 ID_Quit = 6;
static const int32 ID_Resume = 7;
static const int32 ID_CreditsArmy = 8;
static const int32 ID_ParentalControl = 9;
static const int32 ID_Controls = 10;
static const int32 ID_Video = 11;
static const int32 ID_Audio = 12;
static const int32 ID_MainMenu = 14;
static const int32 ID_GoArmy = 15;
static const int32 ID_ArmyOps = 16;
static const int32 ID_Disconnect = 17;
static const int32 ID_GettingStartedText = 20;
static const int32 ID_GettingStartedPrev = 21;
static const int32 ID_GettingStartedNext = 22;
static const int32 ID_SettingsControls = 400;
static const int32 ID_ControlsViewSettings = 410;
static const int32 ID_ControlsMovement = 411;
static const int32 ID_ControlsCombat = 412;
static const int32 ID_ControlsMisc = 413;
static const int32 ID_SettingsVideo = 420;
static const int32 ID_SettingsVideoAdvanced = 421;
static const int32 ID_SettingsVideoDecals = 422;
static const int32 ID_SettingsAudio = 430;
static const int32 ID_SettingsHUD = 440;
static const int32 ID_SettingsWeaponMod = 450;
static const int32 ID_ScrollingCredits = 600;
static const int32 ID_Obstacle = 20;
static const int32 ID_RifleRange = 21;
static const int32 ID_RecruiterChat = 108;
static const int32 ID_GoArmyWebsite = 109;
static const int32 ID_EmailRecruiter = 110;
static const int32 ID_ArmyGameWebsite = 111;
static const int32 ID_Back = 98;
static const int32 ID_Border = 99;
static const int32 ID_MainBackground = 100;
static const int32 ID_MissionSelect = 100;
static const int32 ID_ILDTours = 102;
static const int32 ID_ILDMissions = 103;
static const int32 ID_TourPrev = 104;
static const int32 ID_TourNext = 105;
static const int32 ID_MissionPrev = 106;
static const int32 ID_MissionNext = 107;
static const int32 ID_TourBrief = 110;
static const int32 ID_TourBriefPrevPage = 111;
static const int32 ID_TourBriefNextPage = 112;
static const int32 ID_HistoryBrief = 120;
static const int32 ID_HistoryBriefPrevPage = 121;
static const int32 ID_HistoryBriefNextPage = 122;
static const int32 ID_MissionBriefSP = 130;
static const int32 ID_MissionBriefPrevPage = 131;
static const int32 ID_MissionBriefNextPage = 132;
static const int32 ID_MissionBriefTeam0 = 150;
static const int32 ID_MissionBriefTeam1 = 160;
static const int32 ID_TourPage = 161;
static const int32 ID_CreateAccount = 200;
static const int32 ID_Login = 201;
static const int32 ID_ServerBrowser = 202;
static const int32 ID_MapName = 203;
static const int32 ID_Status = 204;
static const int32 ID_TestAccount = 205;
static const int32 ID_UserName = 300;
static const int32 ID_Password = 301;
static const int32 ID_News1 = 302;
static const int32 ID_News2 = 303;
static const int32 ID_News3 = 304;
static const int32 ID_News4 = 305;
static const int32 ID_ParentPassword = 320;
static const int32 ID_LanguageFilter = 321;
static const int32 ID_NoBlood = 322;
static const int32 ID_MilesOnly = 323;
static const int32 ID_NoSniper = 324;
static const int32 ID_ParentAccept = 325;
static const int32 ID_ParentStatus1 = 326;
static const int32 ID_ParentStatus2 = 327;
static const int32 ID_ParentPassword2 = 328;
static const int32 ID_RunWalk = 500;
static const int32 ID_MoveForward = 501;
static const int32 ID_MoveBackward = 502;
static const int32 ID_StepLeft = 503;
static const int32 ID_StepRight = 504;
static const int32 ID_Jump = 505;
static const int32 ID_Crouch = 506;
static const int32 ID_Prone = 507;
static const int32 ID_TurnLeft = 508;
static const int32 ID_TurnRight = 509;
static const int32 ID_SideStepTurn = 510;
static const int32 ID_MantleActivate = 511;
static const int32 ID_MouseLook = 512;
static const int32 ID_LookUp = 513;
static const int32 ID_LookDown = 514;
static const int32 ID_CenterView = 515;
static const int32 ID_MouseSensitivity = 516;
static const int32 ID_Fire = 517;
static const int32 ID_ChangeFireMode = 518;
static const int32 ID_SupportedFire = 519;
static const int32 ID_ZoomWeapon = 520;
static const int32 ID_ReloadWeapon = 521;
static const int32 ID_ClearJam = 522;
static const int32 ID_SwapHands = 523;
static const int32 ID_DropWeapon = 524;
static const int32 ID_SwapAltShoulder = 525;
static const int32 ID_SetSquadTarget = 526;
static const int32 ID_GrenadeFrag = 527;
static const int32 ID_GrenadeSmoke = 528;
static const int32 ID_GrenadeFlash = 529;
static const int32 ID_GrenadeInc = 905;
static const int32 ID_Communication = 530;
static const int32 ID_NightVision = 531;
static const int32 ID_Binoculars = 900;
static const int32 ID_Chat = 532;
static const int32 ID_ChatTeam = 533;
static const int32 ID_ReportIn = 901;
static const int32 ID_VoteKick = 902;
static const int32 ID_CallMedic = 903;
static const int32 ID_Pause = 534;
static const int32 ID_Screenshot = 535;
static const int32 ID_InvertMouse = 536;
static const int32 ID_LeanLeft = 537;
static const int32 ID_LeanRight = 538;
static const int32 ID_CommoRadio = 539;
static const int32 ID_CommoSquadRadio = 540;
static const int32 ID_CommoGlobal = 541;
static const int32 ID_CommoHand = 542;
static const int32 ID_CommoWhisper = 543;
static const int32 ID_CommoShout = 544;
static const int32 ID_LeanToggle = 545;
static const int32 ID_AutoSwapFromGrenade = 546;
static const int32 ID_Sprint = 547;
static const int32 ID_ResetDefaultsAll = 550;
static const int32 ID_ResetDefaultsView = 551;
static const int32 ID_ResetDefaultsMovement = 552;
static const int32 ID_ResetDefaultsCombat = 553;
static const int32 ID_ResetDefaultsMisc = 554;
static const int32 ID_ResetDefaultsComm = 555;
static const int32 ID_ResetDefaultVideo = 560;
static const int32 ID_AcceptNewVideo = 561;
static const int32 ID_ResetDefaultVideoAdvanced = 562;
static const int32 ID_AcceptNewVideoAdvanced = 563;
static const int32 ID_ResetDefaultVideoDecals = 564;
static const int32 ID_AcceptNewVideoDecals = 565;
static const int32 ID_ResetDefaultAudio = 570;
static const int32 ID_AcceptNewAudio = 571;
static const int32 ID_ResetDefaultHUD = 580;
static const int32 ID_ReduceMouseLag = 600;
static const int32 ID_UsePrecaching = 601;
static const int32 ID_UseTrilinear = 602;
static const int32 ID_UseTripleBuffering = 603;
static const int32 ID_UseCubemaps = 604;
static const int32 ID_UseCompressedLightmaps = 605;
static const int32 ID_VideoGamma = 610;
static const int32 ID_VideoContrast = 611;
static const int32 ID_VideoBrightness = 612;
static const int32 ID_VideoMode = 613;
static const int32 ID_VideoHUDColor = 615;
static const int32 ID_VideoHUDAlpha = 616;
static const int32 ID_VideoHUDCrosshair = 617;
static const int32 ID_VideoStartFullScreen = 618;
static const int32 ID_AudioSoundVolume = 620;
static const int32 ID_AudioUseEAX = 622;
static const int32 ID_AudioReverseStereo = 623;
static const int32 ID_NoClientSideEffects = 624;
static const int32 ID_HUDHideAmmoCount = 630;
static const int32 ID_HUDHideWeaponStatus = 631;
static const int32 ID_HUDHideWeapon = 632;
static const int32 ID_HUDHideGrenades = 633;
static const int32 ID_HUDHideHealth = 634;
static const int32 ID_HUDHideCombatEffect = 635;
static const int32 ID_HUDHideOptics = 636;
static const int32 ID_HUDHideCompass = 637;
static const int32 ID_HUDHideTimer = 638;
static const int32 ID_TextureDetailInterface = 640;
static const int32 ID_TextureDetailTerrain = 641;
static const int32 ID_TextureDetailWeaponSkin = 642;
static const int32 ID_TextureDetailPlayerSkin = 643;
static const int32 ID_TextureDetailWorld = 644;
static const int32 ID_TextureDetailRenderMap = 645;
static const int32 ID_TextureDetailLightmap = 646;
static const int32 ID_KeepDecals = 650;
static const int32 ID_KeepDecoDecals = 651;
static const int32 ID_FadeDecoDecals = 652;
static const int32 ID_WM_MainRail = 680;
static const int32 ID_WM_TopRail = 681;
static const int32 ID_WM_LeftRail = 682;
static const int32 ID_WM_RightRail = 683;
static const int32 ID_WM_Bottom = 684;
static const int32 ID_WM_Barrel = 685;
static const int32 ID_WM_Index = 686;
static const int32 ID_SkinToneNone = 700;
static const int32 ID_SkinToneLight = 701;
static const int32 ID_SkinToneMed = 702;
static const int32 ID_SkinToneDark = 703;
static const int32 ID_UpdateServerList = 800;
static const int32 ID_RefreshServerList = 801;
static const int32 ID_EditFilters = 802;
static const int32 ID_RefreshSelected = 803;
static const int32 ID_ServerScrollbar = 804;
static const int32 ID_ServerPassword = 805;
static const int32 ID_GameSpyLogo = 806;
static const int32 ID_AndromedaLogo = 807;
static const int32 ID_SortOfficial = 810;
static const int32 ID_SortMiles = 811;
static const int32 ID_SortPassword = 812;
static const int32 ID_SortFavorite = 813;
static const int32 ID_SortServerName = 814;
static const int32 ID_SortPlayers = 815;
static const int32 ID_SortPing = 816;
static const int32 ID_SortTour = 817;
static const int32 ID_SortMapName = 818;
static const int32 ID_CBOfficial = 820;
static const int32 ID_CBFavorites = 821;
static const int32 ID_CBMiles = 822;
static const int32 ID_CBPassword = 823;
static const int32 ID_CBTour = 824;
static const int32 ID_CBMission = 825;
static const int32 ID_CBROELimit = 826;
static const int32 ID_CBServerPing = 827;
static const int32 ID_CBPlayerPing = 828;
static const int32 ID_CBAutoSort = 829;
static const int32 ID_EBFilterName = 830;
static const int32 ID_ServerListDisplay = 850;
static const int32 ID_MsgBoxText = 1000;
static const int32 ID_MsgBoxYes = 1001;
static const int32 ID_MsgBoxNo = 1002;
static const int32 GID_SoundQuality = 1;
static const int32 GID_ColorDepth = 2;
static const int32 GID_TextureDetail = 3;
static const int32 GID_SkinTone = 4;
static const int32 kSortNone = 0;
static const int32 kSortServer = 1;
static const int32 kSortPlayers = 2;
static const int32 kSortPing = 3;
static const int32 kSortTour = 4;
static const int32 kSortMapName = 5;
static const int32 kBrowser_None = 0;
static const int32 kBrowser_GameSpy = 1;
static const int32 kBrowser_SCI = 2;


class MyEnums
{
public:
	MyEnums();
	~MyEnums();
};