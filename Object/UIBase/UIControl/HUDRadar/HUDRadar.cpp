// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/HUDRadar/HUDRadar.h"
#include "AA29/AA2_PlayerState.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/VehicleReplicationInfo/AGP_VehicleReplicationInfo/AGP_VehicleReplicationInfo.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassPrisoner/ClassPrisoner.h"
#include "AA29/Object/Actor/Brush/Volume/RadarImageVolume/RadarImageVolume.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_ActivatedObjective/AGP_ESSObjective/AGP_CoopESSObjective/AGP_CoopESSObjective.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"

UHUDRadar::UHUDRadar()
{
	ColorModifiedHitIndicatorImage.SetNum(4);
	RotatingHitIndicatorImage.SetNum(4);
	//MapImage = FinalBlend'T_AA2_MISC.misc.Misc_Grid_GreenF';
	HitIndicatorImage = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Overlays/hitindicator_Mat.hitindicator_Mat'"), NULL, LOAD_None, NULL);
	CompassImage = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Overlays/t_sai_overlays_compassring_Mat.t_sai_overlays_compassring_Mat'"), NULL, LOAD_None, NULL);
	CompassRotImage = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Overlays/t_sai_overlays_compassring_rot_Mat.t_sai_overlays_compassring_rot_Mat'"), NULL, LOAD_None, NULL);
	MaskImage = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Overlays/sai_mask_255_Mat.sai_mask_255_Mat'"), NULL, LOAD_None, NULL);
	MaskOpacity = 255;
	MaskImages = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Overlays/sai_mask_255_Mat.sai_mask_255_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Overlays/sai_mask_127_Mat.sai_mask_127_Mat'"), NULL, LOAD_None, NULL)
	};
	MaskOpacities = {
		255,
		127
	};
	FTLLetterOffsetY = 1;
	OneMinusFullSizeBlend = 1;
	BlinkDurationSeconds = 0.75;
	BlinkDelaySeconds = 0.7;
	BaseElementColor = FColor(255, 255, 255, 255);
	GreenColor = FColor(51, 153, 51, 255);
	YellowColor = FColor(0, 204, 255, 255);
	RedColor = FColor(0, 51, 204, 255);
	MedicColor = FColor(255, 255, 255, 255);
	PreBlendViewScale = 1;
	ViewScale = 1;
	bUpdateDrawPosition = true;
	SQLLinkedDrawColor = FColor(204, 204, 204, 255);
	FTLinkedDrawColor = FColor(204, 204, 204, 255);
	LinkedDrawColor = FColor(153, 153, 153, 0);
	UnLinkedDrawColor = FColor(153, 153, 153, 0);
	LinkedRingIcon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_linkring_commo_Mat.t_sai_icons_linkring_commo_Mat'"), NULL, LOAD_None, NULL);
	DeadPlayerIcon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_teammate_dead_Mat.t_sai_icons_teammate_dead_Mat'"), NULL, LOAD_None, NULL);
	TeammateIcon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_teammate_Mat.t_sai_icons_teammate_Mat'"), NULL, LOAD_None, NULL);
	PlayerIcon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_player_Mat.t_sai_icons_player_Mat'"), NULL, LOAD_None, NULL);
	LeaderIcon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_teammate_Mat.t_sai_icons_teammate_Mat'"), NULL, LOAD_None, NULL);
	SquadLeaderIcon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_squadleader_Mat.t_sai_icons_squadleader_Mat'"), NULL, LOAD_None, NULL);
	VIPIcon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_vip_Mat.t_sai_icons_vip_Mat'"), NULL, LOAD_None, NULL);
	POWIcon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_pow_Mat.t_sai_icons_pow_Mat'"), NULL, LOAD_None, NULL);
	PlayerBelowIcon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_teammate_location_below_Mat.t_sai_icons_teammate_location_below_Mat'"), NULL, LOAD_None, NULL);
	PlayerAboveIcon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_teammate_location_above_Mat.t_sai_icons_teammate_location_above_Mat'"), NULL, LOAD_None, NULL);
	PlayerArrow = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_vector_arrow_Mat.t_sai_icons_vector_arrow_Mat'"), NULL, LOAD_None, NULL);
	SquadLeaderArrow = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_squadleader_vector_Mat.t_sai_icons_squadleader_vector_Mat'"), NULL, LOAD_None, NULL);
	EnemyIcon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_enemy_spotted_Mat.t_sai_icons_enemy_spotted_Mat'"), NULL, LOAD_None, NULL);
	DeadEnemyIcon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_enemy_dead_Mat.t_sai_icons_enemy_dead_Mat'"), NULL, LOAD_None, NULL);
	VehicleIcon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_hmmwv_Mat.t_sai_icons_hmmwv_Mat'"), NULL, LOAD_None, NULL);
	MedicIcon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_medic_Mat.t_sai_icons_medic_Mat'"), NULL, LOAD_None, NULL);
	BleedingIcon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_bleeding_Mat.t_sai_icons_bleeding_Mat'"), NULL, LOAD_None, NULL);
	PrimaryObjectiveBelowIcon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_primary_location_below_Mat.t_sai_icons_objective_primary_location_below_Mat'"), NULL, LOAD_None, NULL);
	PrimaryObjectiveAboveIcon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_location_above_Mat.t_sai_icons_objective_location_above_Mat'"), NULL, LOAD_None, NULL);
	SecondaryObjectiveBelowIcon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_secondary_location_below_Mat.t_sai_icons_objective_secondary_location_below_Mat'"), NULL, LOAD_None, NULL);
	SecondaryObjectiveAboveIcon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_location_above_Mat.t_sai_icons_objective_location_above_Mat'"), NULL, LOAD_None, NULL);
	PrimaryObjectiveIcon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_primary_Mat.t_sai_icons_objective_primary_Mat'"), NULL, LOAD_None, NULL);
	PrimaryObjectiveAccomplished = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_primary_Mat.t_sai_icons_objective_primary_Mat'"), NULL, LOAD_None, NULL);
	PrimaryObjectiveFailed = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_primary_Mat.t_sai_icons_objective_primary_Mat'"), NULL, LOAD_None, NULL);
	SecondaryObjectiveIcon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_secondary_Mat.t_sai_icons_objective_secondary_Mat'"), NULL, LOAD_None, NULL);
	SecondaryObjectiveAccomplished = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_secondary_Mat.t_sai_icons_objective_secondary_Mat'"), NULL, LOAD_None, NULL);
	SecondaryObjectiveFailed = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_secondary_Mat.t_sai_icons_objective_secondary_Mat'"), NULL, LOAD_None, NULL);
	ESSIcon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_ES2/ES2_Objects/ES2_UXO_SAIicon_Mat.ES2_UXO_SAIicon_Mat'"), NULL, LOAD_None, NULL);
	ObjectiveLetters = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_a_Mat.t_sai_icons_objective_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_b_Mat.t_sai_icons_objective_b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_c_Mat.t_sai_icons_objective_c_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_d_Mat.t_sai_icons_objective_d_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_e_Mat.t_sai_icons_objective_e_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_f_Mat.t_sai_icons_objective_f_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_g_Mat.t_sai_icons_objective_g_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_h_Mat.t_sai_icons_objective_h_Mat'"), NULL, LOAD_None, NULL)
	};
	ObjectiveNumbers = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_0_Mat.t_sai_icons_objective_0_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_1_Mat.t_sai_icons_objective_1_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_2_Mat.t_sai_icons_objective_2_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_3_Mat.t_sai_icons_objective_3_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_4_Mat.t_sai_icons_objective_4_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_5_Mat.t_sai_icons_objective_5_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_6_Mat.t_sai_icons_objective_6_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_7_Mat.t_sai_icons_objective_7_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_8_Mat.t_sai_icons_objective_8_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_SAI/Icons/t_sai_icons_objective_9_Mat.t_sai_icons_objective_9_Mat'"), NULL, LOAD_None, NULL)
	};
	RingRadius = 1;
	CompassScaleOffset = 0.15;
	HitFadePerSecond = 1;
	BlendFadePerSecond = 1;
	ZoomTimeSeconds = 0.5;
	PlayerFadePerSecond = 255;
	DeadPlayerFadePerSecond = 64;
	SmoothFlashFadePerSecond = 1;
	HeightToDrawArrow = 150;
	CullRadius = 0.9;
	MaxZoomLevel = 1000;
	bShowFTLSiblings = true;
}

void UHUDRadar::StaticUpdatePrecacheMaterials(AAA2_WorldSettings* L)
{
	int32 i = 0;
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->MapImage);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->HitIndicatorImage);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->CompassImage);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->CompassRotImage);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->MaskImage);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->LinkedRingIcon);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->DeadPlayerIcon);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->TeammateIcon);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->PlayerIcon);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->LeaderIcon);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->SquadLeaderIcon);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->VIPIcon);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->POWIcon);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->PlayerBelowIcon);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->PlayerAboveIcon);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->PlayerArrow);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->SquadLeaderArrow);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->EnemyIcon);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->DeadEnemyIcon);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->VehicleIcon);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->MedicIcon);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->BleedingIcon);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->PrimaryObjectiveBelowIcon);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->PrimaryObjectiveAboveIcon);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->SecondaryObjectiveBelowIcon);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->SecondaryObjectiveAboveIcon);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->PrimaryObjectiveIcon);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->PrimaryObjectiveAccomplished);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->PrimaryObjectiveFailed);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->SecondaryObjectiveIcon);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->SecondaryObjectiveAccomplished);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->SecondaryObjectiveFailed);
	L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->ESSIcon);
	for (i = 0; i < GetDefault<UHUDRadar>()->ObjectiveLetters.Num(); i++)
	{
		L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->ObjectiveLetters[i]);
	}
	for (i = 0; i < GetDefault<UHUDRadar>()->ObjectiveNumbers.Num(); i++)
	{
		L->AddPrecacheMaterial(GetDefault<UHUDRadar>()->ObjectiveNumbers[i]);
	}
}

void UHUDRadar::Destroyed()
{
	bInitialized = false;
	MapImage = nullptr;
	HitIndicatorImage = nullptr;
	CompassImage = nullptr;
	CompassRotImage = nullptr;
	ScalingMapImage = nullptr;
	ScalingMaskImage = nullptr;
	RotatingCompassImage = nullptr;
	RotatingMapImage = nullptr;
	RotatingHitIndicatorImage[0] = nullptr;
	RotatingHitIndicatorImage[1] = nullptr;
	RotatingHitIndicatorImage[2] = nullptr;
	RotatingHitIndicatorImage[3] = nullptr;
	RotatableImages.Empty();
	ColorModifiedHitIndicatorImage[0] = nullptr;
	ColorModifiedHitIndicatorImage[1] = nullptr;
	ColorModifiedHitIndicatorImage[2] = nullptr;
	ColorModifiedHitIndicatorImage[3] = nullptr;
	MaskImage = nullptr;
	LinkedRingIcon = nullptr;
	DeadPlayerIcon = nullptr;
	TeammateIcon = nullptr;
	PlayerIcon = nullptr;
	LeaderIcon = nullptr;
	SquadLeaderIcon = nullptr;
	VIPIcon = nullptr;
	POWIcon = nullptr;
	PlayerBelowIcon = nullptr;
	PlayerAboveIcon = nullptr;
	PlayerArrow = nullptr;
	SquadLeaderArrow = nullptr;
	EnemyIcon = nullptr;
	DeadEnemyIcon = nullptr;
	VehicleIcon = nullptr;
	MedicIcon = nullptr;
	BleedingIcon = nullptr;
	PrimaryObjectiveBelowIcon = nullptr;
	PrimaryObjectiveAboveIcon = nullptr;
	SecondaryObjectiveBelowIcon = nullptr;
	SecondaryObjectiveAboveIcon = nullptr;
	PrimaryObjectiveIcon = nullptr;
	PrimaryObjectiveAccomplished = nullptr;
	PrimaryObjectiveFailed = nullptr;
	SecondaryObjectiveIcon = nullptr;
	SecondaryObjectiveAccomplished = nullptr;
	SecondaryObjectiveFailed = nullptr;
	ESSIcon = nullptr;
	ObjectiveLetters.Empty();
	ObjectiveNumbers.Empty();
	Super::Destroyed();
}

void UHUDRadar::ScaleControl(UCanvas* Canvas)
{
	Super::ScaleControl(Canvas);
	/*
	DrawOffset_MapImage							= ((float(GetDefault<UHUDRadar>MapImage.MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_HitIndicatorImage				= ((float(GetDefault<UHUDRadar>HitIndicatorImage->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_CompassImage						= ((float(GetDefault<UHUDRadar>CompassImage->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_CompassRotImage					= ((float(GetDefault<UHUDRadar>CompassRotImage->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_MaskImage						= ((float(GetDefault<UHUDRadar>MaskImage->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_DeadPlayerIcon					= ((float(GetDefault<UHUDRadar>DeadPlayerIcon->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_TeammateIcon						= ((float(GetDefault<UHUDRadar>TeammateIcon->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_PlayerIcon						= ((float(GetDefault<UHUDRadar>PlayerIcon->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_LeaderIcon						= ((float(GetDefault<UHUDRadar>LeaderIcon->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_SquadLeaderIcon					= ((float(GetDefault<UHUDRadar>SquadLeaderIcon->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_VIPIcon							= ((float(GetDefault<UHUDRadar>VIPIcon->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_POWIcon							= ((float(GetDefault<UHUDRadar>POWIcon->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_PlayerBelowIcon					= ((float(GetDefault<UHUDRadar>PlayerBelowIcon->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_PlayerAboveIcon					= ((float(GetDefault<UHUDRadar>PlayerAboveIcon->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_PlayerArrow						= ((float(GetDefault<UHUDRadar>PlayerArrow->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_SquadLeaderArrow					= ((float(GetDefault<UHUDRadar>SquadLeaderArrow->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_EnemyIcon						= ((float(GetDefault<UHUDRadar>EnemyIcon->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_DeadEnemyIcon					= ((float(GetDefault<UHUDRadar>DeadEnemyIcon->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_VehicleIcon						= ((float(GetDefault<UHUDRadar>VehicleIcon->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_MedicIcon						= ((float(GetDefault<UHUDRadar>MedicIcon->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_BleedingIcon						= ((float(GetDefault<UHUDRadar>BleedingIcon->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_PrimaryObjectiveBelowIcon		= ((float(GetDefault<UHUDRadar>PrimaryObjectiveBelowIcon->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_PrimaryObjectiveAboveIcon		= ((float(GetDefault<UHUDRadar>PrimaryObjectiveAboveIcon->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_SecondaryObjectiveBelowIcon		= ((float(GetDefault<UHUDRadar>SecondaryObjectiveBelowIcon->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_SecondaryObjectiveAboveIcon		= ((float(GetDefault<UHUDRadar>SecondaryObjectiveAboveIcon->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_PrimaryObjectiveIcon				= ((float(GetDefault<UHUDRadar>PrimaryObjectiveIcon->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_PrimaryObjectiveAccomplished		= ((float(GetDefault<UHUDRadar>PrimaryObjectiveAccomplished->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_PrimaryObjectiveFailed			= ((float(GetDefault<UHUDRadar>PrimaryObjectiveFailed->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_SecondaryObjectiveIcon			= ((float(GetDefault<UHUDRadar>SecondaryObjectiveIcon->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_SecondaryObjectiveAccomplished	= ((float(GetDefault<UHUDRadar>SecondaryObjectiveAccomplished->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_SecondaryObjectiveFailed			= ((float(GetDefault<UHUDRadar>SecondaryObjectiveFailed->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_ESSIcon							= ((float(GetDefault<UHUDRadar>ESSIcon->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_ObjectiveLetters					= ((float(GetDefault<UHUDRadar>ObjectiveLetters[0]->MaterialUSize()) / 2) * cFrame->fScaleX);
	DrawOffset_ObjectiveNumbers					= ((float(GetDefault<UHUDRadar>ObjectiveNumbers[0]->MaterialUSize()) / 2) * cFrame->fScaleX);
	*/
}

UMaterialInstance* UHUDRadar::GetRotatableImage()
{
	if (NextRotatableImageIndex < RotatableImages.Num())
	{
		//RotatableImages[NextRotatableImageIndex].Material = nullptr;
		//RotatableImages[NextRotatableImageIndex].Rotation = FRotator(0 0 0);
		//RotatableImages[NextRotatableImageIndex].UOffset = 0;
		//RotatableImages[NextRotatableImageIndex].VOffset = 0;
	}
	else
	{
		//RotatableImages[NextRotatableImageIndex] = new () Class'TexRotator';
		//RotatableImages[NextRotatableImageIndex].Material = nullptr;
		//RotatableImages[NextRotatableImageIndex].TexRotationType = 0;
		//RotatableImages[NextRotatableImageIndex].Rotation = FRotator(0 0 0);
		//RotatableImages[NextRotatableImageIndex].UOffset = 0;
		//RotatableImages[NextRotatableImageIndex].VOffset = 0;
		//RotatableImages[NextRotatableImageIndex].OscillationRate = FRotator(0 0 0);
		//RotatableImages[NextRotatableImageIndex].OscillationAmplitude = FRotator(0 0 0);
		//RotatableImages[NextRotatableImageIndex].OscillationPhase = FRotator(0 0 0);
	}
	return RotatableImages[NextRotatableImageIndex++];
}

void UHUDRadar::Initialize()
{
	int32 i = 0;
	myPawn = Cast<APawn>(cFrame->cActor);
	if (myPawn != nullptr)
	{
		//myPRI = cFrame->cHUD->PlayerOwner->PlayerReplicationInfo;
	}
	//myLevel = cFrame->cActor->Level;
	LoadMapImage();
	CalibrateImageToWorld();
	ReloadObjectives();
	for (i = 0; i < 4; i++)
	{
		/*
		RotatingHitIndicatorImage[i] = new () Class'TexRotator';
		RotatingHitIndicatorImage[i].Material = HitIndicatorImage;
		RotatingHitIndicatorImage[i].TexRotationType = 0;
		RotatingHitIndicatorImage[i].Rotation.Pitch = 0;
		RotatingHitIndicatorImage[i].Rotation.Yaw = i * 16384 + 8192;
		RotatingHitIndicatorImage[i].Rotation.Roll = 0;
		RotatingHitIndicatorImage[i].UOffset = HitIndicatorImage.MaterialUSize() / 2;
		RotatingHitIndicatorImage[i].VOffset = HitIndicatorImage.MaterialVSize() / 2;
		RotatingHitIndicatorImage[i].OscillationRate = FRotator(0 0 0);
		RotatingHitIndicatorImage[i].OscillationAmplitude = FRotator(0 0 0);
		RotatingHitIndicatorImage[i].OscillationPhase = FRotator(0 0 0);
		ColorModifiedHitIndicatorImage[i] = new () Class'ColorModifier';
		ColorModifiedHitIndicatorImage[i].Material = RotatingHitIndicatorImage[i];
		ColorModifiedHitIndicatorImage[i].Color.R = 255;
		ColorModifiedHitIndicatorImage[i].Color.G = 0;
		ColorModifiedHitIndicatorImage[i].Color.B = 0;
		ColorModifiedHitIndicatorImage[i].Color.A = 0;
		ColorModifiedHitIndicatorImage[i].RenderTwoSided = false;
		ColorModifiedHitIndicatorImage[i].AlphaBlend = false;
		*/
	}
	MyController = Cast<AHumanController>(cFrame->cHUD->PlayerOwner);
	if (MyController != nullptr)
	{
		MyController->RadarSetZoom(myLevel->RadarZoomLevels[0]);
		DesiredViewScale = FMath::Clamp(MyController->RadarZoom, 1.0f, 1000.0f);
		PreBlendViewScale =FMath::Clamp(MyController->RadarZoom, 1.0f, 1000.0f);
	}
	bInitialized = true;
}

void UHUDRadar::CalibrateImageToWorld()
{
	MapOffset = myLevel->RadarMapOffset;
	MapSize = myLevel->RadarMapSize;
}

void UHUDRadar::LoadMapImage()
{
	UMaterialInstance* NewMapImage = nullptr;
	UMaterialInstance* CombinedMapImage = nullptr;
	UMaterialInstance* BlendedMapImage = nullptr;
	if (myLevel->RadarMapImage != nullptr)
	{
		NewMapImage = myLevel->RadarMapImage;
	}
	if (NewMapImage == nullptr)
	{
		NewMapImage = GetDefault<UHUDRadar>()->MapImage;
	}
	/*
	RotatingCompassImage = new () Class'TexRotator';
	RotatingCompassImage.Material = CompassRotImage;
	RotatingCompassImage.TexRotationType = 0;
	RotatingCompassImage.Rotation = FRotator(0 0 0);
	RotatingCompassImage.UOffset = CompassRotImage.MaterialUSize() / 2;
	RotatingCompassImage.VOffset = CompassRotImage.MaterialVSize() / 2;
	RotatingCompassImage.OscillationRate = FRotator(0 0 0);
	RotatingCompassImage.OscillationAmplitude = FRotator(0 0 0);
	RotatingCompassImage.OscillationPhase = FRotator(0 0 0);
	ScalingMapImage = new () Class'TexScaler';
	ScalingMapImage.Material = NewMapImage;
	ScalingMapImage.UScale = 1;
	ScalingMapImage.VScale = 1;
	ScalingMapImage.UOffset = 0;
	ScalingMapImage.VOffset = 0;
	RotatingMapImage = new () Class'TexRotator';
	RotatingMapImage.Material = ScalingMapImage;
	RotatingMapImage.TexRotationType = 0;
	RotatingMapImage.Rotation = FRotator(0 0 0);
	RotatingMapImage.UOffset = ScalingMapImage.Material.MaterialUSize() / 2;
	RotatingMapImage.VOffset = ScalingMapImage.Material.MaterialVSize() / 2;
	RotatingMapImage.OscillationRate = FRotator(0 0 0);
	RotatingMapImage.OscillationAmplitude = FRotator(0 0 0);
	RotatingMapImage.OscillationPhase = FRotator(0 0 0);
	ScalingMaskImage = new () Class'TexScaler';
	ScalingMaskImage.Material = MaskImage;
	ScalingMaskImage.UScale = 1;
	ScalingMaskImage.VScale = 1;
	ScalingMaskImage.UOffset = 0;
	ScalingMaskImage.VOffset = 0;
	CombinedMapImage = new () Class'Combiner';
	CombinedMapImage.CombineOperation = 0;
	CombinedMapImage.AlphaOperation = 4;
	CombinedMapImage.Material1 = RotatingMapImage;
	CombinedMapImage.Material2 = ScalingMaskImage;
	CombinedMapImage.Mask = nullptr;
	CombinedMapImage.InvertMask = false;
	CombinedMapImage.Modulate2X = false;
	CombinedMapImage.Modulate4X = false;
	BlendedMapImage = new () Class'FinalBlend';
	BlendedMapImage.Material = CombinedMapImage;
	BlendedMapImage.FrameBufferBlending = 2;
	BlendedMapImage.ZWrite = true;
	BlendedMapImage.ZTest = true;
	BlendedMapImage.AlphaTest = false;
	BlendedMapImage.TwoSided = false;
	BlendedMapImage.AlphaRef = 0;
	MapImage = BlendedMapImage;
	*/
}

void UHUDRadar::ReloadObjectives()
{
	AAGP_Objective* ObjIterator = nullptr;
	ObjectiveList.Empty();
	/*
	ForEach cFrame->cActor.DynamicActors(AAGP_Objective::StaticClass(), ObjIterator)
	{
		ObjectiveList[ObjectiveList.Num()] = ObjIterator;
	}
	*/
}

void UHUDRadar::DoTick()
{
	float DeltaTime = 0;
	if (myLevel != nullptr)
	{
		if (LastTickTime == 0)
		{
			LastTickTime = GetWorld()->GetTimeSeconds();
		}
		DeltaTime = GetWorld()->GetTimeSeconds() - LastTickTime;
		if (!bEveryOtherTick)
		{
			LastTickTime = GetWorld()->GetTimeSeconds();
			Tick(DeltaTime);
		}
		bEveryOtherTick = !bEveryOtherTick;
	}
	else
	{
		LastTickTime = 0;
	}
}

void UHUDRadar::Tick(float DeltaTime)
{
	int32 i = 0;
	ATeamInfo* MyTeam = nullptr;
	AAA2_PlayerState* TeammatePRI = nullptr;
	AAGP_Pawn* MyAGP_Pawn = nullptr;
	AAGP_HUD* MyAGP_HUD = nullptr;
	float ActualDesiredViewScale = 0;
	myPawn = Cast<APawn>(cFrame->cActor);
	if (MyController == nullptr)
	{
		return;
	}
	if (!bInitialized || myPawn == nullptr)
	{
		return;
	}
	MyAGP_Pawn = Cast<AAGP_Pawn>(myPawn);
	if (MyAGP_Pawn == nullptr && Cast<AVehicle>(myPawn) != nullptr)
	{
		MyAGP_Pawn = Cast<AAGP_Pawn>(Cast<AVehicle>(myPawn)->Driver);
	}
	if (MyAGP_Pawn != nullptr)
	{
		for (i = 0; i < 4; i++)
		{
			if (MyAGP_Pawn->HitQuadrants[i] > 0)
			{
				MyAGP_Pawn->HitQuadrants[i] = FMath::Clamp(MyAGP_Pawn->HitQuadrants[i] - HitFadePerSecond * DeltaTime, 0.0f, 1.0f);
			}
			if (MyAGP_Pawn->FixedHitQuadrants[i] > 0)
			{
				MyAGP_Pawn->FixedHitQuadrants[i] = FMath::Clamp(MyAGP_Pawn->FixedHitQuadrants[i] - HitFadePerSecond * DeltaTime, 0.0f, 1.0f);
			}
			MyAGP_HUD = Cast<AAGP_HUD>(MyController->MyHUD);
			if (MyAGP_HUD != nullptr)
			{
				if (MyAGP_HUD->bRotateRadarAroundPlayer)
				{
					//ColorModifiedHitIndicatorImage[i]->Color.A = MyAGP_Pawn->HitQuadrants[i] * 255;
				}
				else
				{
					//ColorModifiedHitIndicatorImage[i]->Color.A = MyAGP_Pawn->FixedHitQuadrants[i] * 255;
				}
			}
		}
	}
	if (MyController->bFullsizeRadar)
	{
		if (FullSizeBlend < 1)
		{
			FullSizeBlend = FMath::Min(FullSizeBlend + 3 - FullSizeBlend * 2 * BlendFadePerSecond * DeltaTime, 1.0f);
			OneMinusFullSizeBlend = 1 - FullSizeBlend;
			bUpdateDrawPosition = true;
		}
		else
		{
			OneMinusFullSizeBlend = 0;
		}
	}
	else
	{
		if (FullSizeBlend > 0)
		{
			FullSizeBlend = FMath::Max(FullSizeBlend - 1 + FullSizeBlend * 2 * BlendFadePerSecond * DeltaTime, 0.0f);
			OneMinusFullSizeBlend = 1 - FullSizeBlend;
			bUpdateDrawPosition = true;
		}
		else
		{
			OneMinusFullSizeBlend = 1;
		}
	}
	if (myPRI->VehicleReplicationInfo != nullptr)
	{
		if (myLevel->RadarZoomLevels.Num() > 0)
		{
			if (myLevel->RadarZoomLevels[0] >= 1)
			{
				ActualDesiredViewScale = FMath::Clamp((myLevel->RadarMapSize / (myLevel->RadarZoomLevels[0] * 52.200001f)), 1.0f, 1000.0f);
			}
			else
			{
				ActualDesiredViewScale = 1;
			}
		}
		else
		{
			ActualDesiredViewScale = 1;
		}
	}
	else
	{
		ActualDesiredViewScale = DesiredViewScale;
	}
	if (ActualDesiredViewScale != PreBlendViewScale)
	{
		if (ActualDesiredViewScale != LastDesiredViewScale)
		{
			LastDesiredViewScale = ActualDesiredViewScale;
			LastStartViewScale = PreBlendViewScale;
		}
		if (ActualDesiredViewScale > PreBlendViewScale)
		{
			//PreBlendViewScale += ((FMath::Abs((ActualDesiredViewScale - LastStartViewScale)) * (1 / ZoomTimeSeconds)) * DeltaTime);
			if (PreBlendViewScale > ActualDesiredViewScale)
			{
				PreBlendViewScale = ActualDesiredViewScale;
			}
		}
		else
		{
			//PreBlendViewScale -= ((FMath::Abs((ActualDesiredViewScale - LastStartViewScale)) * (1 / ZoomTimeSeconds)) * DeltaTime);
			if (PreBlendViewScale < ActualDesiredViewScale)
			{
				PreBlendViewScale = ActualDesiredViewScale;
			}
		}
		//FMath::Clamp(PreBlendViewScale, 1.0f, MaxZoomLevel);
	}
	ViewScale = PreBlendViewScale * OneMinusFullSizeBlend + FullSizeBlend;
	if (bSmoothFlashFading)
	{
		SmoothFlashBlend -= SmoothFlashFadePerSecond * DeltaTime;
	}
	else
	{
		SmoothFlashBlend += SmoothFlashFadePerSecond * DeltaTime;
	}
	if (SmoothFlashBlend >= 1)
	{
		SmoothFlashBlend = 1;
		bSmoothFlashFading = true;
	}
	else
	{
		if (SmoothFlashBlend <= 0)
		{
			SmoothFlashBlend = 0;
			bSmoothFlashFading = false;
		}
	}
	BaseDrawScale = 0.32;
	MyTeam = myPRI->Team;
	if (MyTeam != nullptr)
	{
		for (i = 0; i < MyTeam->NumRequestSlots; i++)
		{
			TeammatePRI = MyTeam->ActualList_Player[i];
			if (TeammatePRI != nullptr)
			{
				if (TeammatePRI->bVisibleLastTick)
				{
					if (TeammatePRI->RadarDrawOpacity < 255)
					{
						TeammatePRI->RadarDrawOpacity = FMath::Min(TeammatePRI->RadarDrawOpacity + PlayerFadePerSecond * DeltaTime, 255.0f);
					}
				}
				else
				{
					if (TeammatePRI->RadarDrawOpacity > 0)
					{
						if (TeammatePRI->bDead || TeammatePRI->bOutOfLives)
						{
							TeammatePRI->RadarDrawOpacity = FMath::Max(TeammatePRI->RadarDrawOpacity - DeadPlayerFadePerSecond * DeltaTime, 0.0f);
						}
						else
						{
							TeammatePRI->RadarDrawOpacity = FMath::Max(TeammatePRI->RadarDrawOpacity - PlayerFadePerSecond * DeltaTime, 0.0f);
						}
					}
				}
			}
		}
	}
	else
	{
		//if (myLevel->NetMode == 0)
		//{
		//	myPRI->RadarDrawOpacity = 255;
		//}
	}
}

void UHUDRadar::RefreshViewParameters()
{
	AAGP_HUD* MyAGP_HUD = nullptr;
	FVector StartTrace = FVector(0,0,0);
	FRotator CameraRotation = FRotator(0,0,0);
	AActor* TestActor = nullptr;
	/*
	ViewCenter = WorldToMapCoords(myPawn.Location) * OneMinusFullSizeBlend;
	DesiredViewScale =FMath::Clamp(MyController->RadarZoom, 1, 1000);
	MyAGP_HUD = Cast<AAGP_HUD>(MyController->MyHUD);
	if (MyAGP_HUD.bRotateRadarAroundPlayer)
	{
		RotatingCompassImage.Material = CompassRotImage;
		MyController->PlayerCalcView(TestActor, StartTrace, CameraRotation);
		ViewRotation.Yaw = Normalize(CameraRotation).Yaw * OneMinusFullSizeBlend + 16384;
	}
	else
	{
		RotatingCompassImage.Material = CompassImage;
		ViewRotation.Yaw = 16384;
	}
	if (MyAGP_HUD != nullptr && MyAGP_HUD.RadarMaskIndex < MaskOpacities.Num() && MaskOpacities[MyAGP_HUD.RadarMaskIndex] != MaskOpacity)
	{
		MaskImage = MaskImages[MyAGP_HUD.RadarMaskIndex];
		ScalingMaskImage.Material = MaskImage;
		MaskOpacity = MaskOpacities[MyAGP_HUD.RadarMaskIndex];
	}
	MaskScale = FullSizeBlend * 0.8 + 1;
	ScalingMaskImage.UScale = MaskScale;
	ScalingMaskImage.VScale = MaskScale;
	ScalingMaskImage.UOffset = ScalingMaskImage.Material.MaterialUSize() - ScalingMaskImage.Material.MaterialUSize() / MaskScale / 2;
	ScalingMaskImage.VOffset = ScalingMaskImage.UOffset;
	if (bUpdateDrawPosition)
	{
		DrawPosition.X = 130 * cFrame->fScaleX + cFrame->offset.X;
		DrawPosition.Y = 30 * cFrame->fScaleY + cFrame->offset.Y;
		DrawPosition.W = 540 * cFrame->fScaleX;
		DrawPosition.H = 540 * cFrame->fScaleY;
		DrawPosition.X = _ScaledPos.X * OneMinusFullSizeBlend + DrawPosition.X * FullSizeBlend;
		DrawPosition.Y = _ScaledPos.Y * OneMinusFullSizeBlend + DrawPosition.Y * FullSizeBlend;
		DrawPosition.W = _ScaledPos.W * OneMinusFullSizeBlend + DrawPosition.W * FullSizeBlend;
		DrawPosition.H = _ScaledPos.H * OneMinusFullSizeBlend + DrawPosition.H * FullSizeBlend;
	}
	ScaledCullRadius = DrawPosition.W / 2 * CullRadius * MaskScale;
	*/
}

void UHUDRadar::UpdatePanValues()
{
	UMaterialInstance* NewMapImage = nullptr;
	float DrawSize_Map = 0;
	float DrawOffset_Map = 0;
	/*
	DrawSize_Map = ScalingMapImage.Material.MaterialUSize();
	DrawOffset_Map = DrawSize_Map / 2;
	ScalingMapImage.UScale = ViewScale;
	ScalingMapImage.VScale = ViewScale;
	ScalingMapImage.UOffset = ViewCenter.X * DrawOffset_Map + DrawSize_Map - DrawSize_Map / ViewScale / 2;
	ScalingMapImage.VOffset = ViewCenter.Y * DrawOffset_Map + DrawSize_Map - DrawSize_Map / ViewScale / 2;
	if (myPawn != nullptr)
	{
		NewMapImage = ARadarImageVolume::StaticClass().GetBestRadarImage(myPawn);
		if (NewMapImage == nullptr)
		{
			if (myLevel->RadarMapImage != nullptr)
			{
				NewMapImage = myLevel->RadarMapImage;
			}
			if (NewMapImage == nullptr)
			{
				NewMapImage = GetDefault<UHUDRadar>()->MapImage;
			}
		}
		ScalingMapImage.Material = NewMapImage;
		RotatingMapImage.UOffset = NewMapImage.MaterialUSize() / 2;
		RotatingMapImage.VOffset = NewMapImage.MaterialVSize() / 2;
	}
	RotatingMapImage.Rotation = ViewRotation;
	RotatingCompassImage.Rotation = ViewRotation;
	RotatingCompassImage.Rotation.Yaw -= 16384;
	CenterOfRadarScreenCoords.X = DrawPosition.X + DrawPosition.W / 2;
	CenterOfRadarScreenCoords.Y = DrawPosition.Y + DrawPosition.H / 2;
	CenterOfRadarScreenCoords.Z = 0;
	*/
}

FVector UHUDRadar::WorldToMapCoords(FVector VectorInWorldCoords)
{
	FVector Result = FVector(0,0,0);
	Result.X=((VectorInWorldCoords.X - MapOffset.X) / MapSize);
	Result.Y=((VectorInWorldCoords.Y - MapOffset.Y) / MapSize);
	Result.Z=VectorInWorldCoords.Z;
	return Result;
}

FVector UHUDRadar::MapToScreenCoords(FVector VectorInMapCoords)
{
	float PixelsPerMapCoordUnit = 0;
	PixelsPerMapCoordUnit = ((float(DrawPosition.W) * ViewScale) / 2);
	VectorInMapCoords = (ViewCenter - VectorInMapCoords);
	(VectorInMapCoords *= PixelsPerMapCoordUnit);
	//VectorInMapCoords = (-(VectorInMapCoords << Normalize(ViewRotation)));
	(VectorInMapCoords.X += (float(DrawPosition.X) + (float(DrawPosition.W) / 2)));
	(VectorInMapCoords.Y += (float(DrawPosition.Y) + (float(DrawPosition.H) / 2)));
	return VectorInMapCoords;
}

void UHUDRadar::CullRadarElement(FVector &DrawLoc, float &DrawScale)
{
	FVector LocVector = FVector(0,0,0);
	float DistanceFromCenter = 0;
	float NewDistanceFromCenter = 0;
	if (DrawLoc == CenterOfRadarScreenCoords)
	{
		return;
	}
	LocVector = DrawLoc - CenterOfRadarScreenCoords;
	//DistanceFromCenter = VSize(LocVector);
	if (DistanceFromCenter > ScaledCullRadius || DrawLoc.X < DrawPosition.X || DrawLoc.X > DrawPosition.X + DrawPosition.W || DrawLoc.Y < DrawPosition.Y || DrawLoc.Y > DrawPosition.Y + DrawPosition.H)
	{
		if (MaskScale > 1)
		{
			//DrawLoc = CenterOfRadarScreenCoords + Normal(LocVector) * ScaledCullRadius;
			if (DrawLoc.X < DrawPosition.X)
			{
				DrawLoc.X = DrawPosition.X;
			}
			else
			{
				if (DrawLoc.X > DrawPosition.X + DrawPosition.W)
				{
					DrawLoc.X = DrawPosition.X + DrawPosition.W;
				}
			}
			if (DrawLoc.Y < DrawPosition.Y)
			{
				DrawLoc.Y = DrawPosition.Y;
			}
			else
			{
				if (DrawLoc.Y > DrawPosition.Y + DrawPosition.H)
				{
					DrawLoc.Y = DrawPosition.Y + DrawPosition.H;
				}
			}
		}
		else
		{
			//DrawLoc = CenterOfRadarScreenCoords + Normal(LocVector) * ScaledCullRadius;
		}
		//NewDistanceFromCenter = VSize(DrawLoc - CenterOfRadarScreenCoords);
		//DrawScale = DrawScale * FMath:Max(1 - DistanceFromCenter - NewDistanceFromCenter / NewDistanceFromCenter, 0.75f);
	}
}

bool UHUDRadar::ShouldShowRadar()
{
	//return myLevel->bShowRadarMap && !MyController->bHUDHideRadar && !MyController->GameReplicationInfo.bHUDHideRadar&& ARadarImageVolume::StaticClass().ShouldDisableRadar(myPawn) == false;
	return true;      //FAKE   /ELiZ
}

void UHUDRadar::Draw(UCanvas* C)
{
	ATeamInfo* MyTeam = nullptr;
	int32 MyTeamListID = 0;
	if (!bInitialized)
	{
		Initialize();
		if (!bInitialized)
		{
			return;
		}
	}
	BaseElementColor = GreenColor;
	NextRotatableImageIndex = 0;
	DoTick();
	myPawn = Cast<APawn>(cFrame->cActor);
	/*
	if (myPawn == nullptr || myPawn->bIsDead)
	{
		return;
	}
	*/
	MyController = Cast<AHumanController>(cFrame->cHUD->PlayerOwner);
	//myPRI = cFrame->cHUD->PlayerOwner->PlayerReplicationInfo;
	if (MyController == nullptr)
	{
		return;
	}
	MyController->bRadarIsVisible = ShouldShowRadar();
	if (!MyController->bRadarIsVisible)
	{
		return;
	}
	MySQLPRI = myPRI->GetSquadLeader();
	MyFTLPRI = myPRI->GetFTLeader();
	RefreshViewParameters();
	MyTeam = myPRI->Team;
	if (MyTeam != nullptr)
	{
		for (MyTeamListID = 0; MyTeamListID < MyTeam->NumRequestSlots; MyTeamListID++)
		{
			if (MyTeam->ActualList_Player[MyTeamListID] == myPRI)
			{
			}
		}
	}
	else
	{
		MyTeamListID = 0;
	}
	UpdatePanValues();
	DrawRadarBG(C);
	DrawHitIndicator(C);
	DrawVehicles(C);
	DrawTeam(C);
	DrawObjectives(C);
	DrawEnemies(C);
	DrawSpottedESS(C);
	if (ShouldDrawPlayer(myPRI, MyTeamListID))
	{
		myPRI->bVisibleLastTick = true;
		DrawPlayer(C, myPRI, 0, ((myPRI->LinkedTo & (~(1 << MyTeamListID))) != 0));
	}
	DrawRadarFrame(C);
	DrawVehicleNames(C);
	DrawTeamNames(C);
}

void UHUDRadar::DrawRadarBG(UCanvas* C)
{
	/*
	C->SetPos(DrawPosition.X, DrawPosition.Y);
	C->SetDrawColor(255, 255, 255, 255);
	C->DrawTile(MapImage, DrawPosition.W, DrawPosition.H, 0, 0, MapImage.MaterialUSize(), MapImage.MaterialVSize());
	C->DrawColor = cFrame->cHUD->HUDColor;
	*/
}

void UHUDRadar::DrawTeam(UCanvas* C)
{
	int32 i = 0;
	ATeamInfo* MyTeam = nullptr;
	AAA2_PlayerState* TeammatePRI = nullptr;
	MyTeam = myPRI->Team;
	if (MyTeam == nullptr)
	{
		return;
	}
	if (myPRI->bCallForMedic)
	{
		for (i = 0; i < MyTeam->NumRequestSlots; i++)
		{
			TeammatePRI = MyTeam->ActualList_Player[i];
			if (TeammatePRI != nullptr && TeammatePRI->bIsMedic)
			{
				if (ShouldDrawPlayer(TeammatePRI, i))
				{
					TeammatePRI->bVisibleLastTick = true;
					DrawPlayer(C, TeammatePRI, i, ((myPRI->LinkedTo & (1 << i)) != 0));
				}
				else
				{
					TeammatePRI->bVisibleLastTick = false;
					DrawPlayer(C, TeammatePRI, i, ((myPRI->LinkedTo & (1 << i)) != 0));
				}
			}
		}
	}
	for (i = 0; i < MyTeam->NumRequestSlots; i++)
	{
		TeammatePRI = MyTeam->ActualList_Player[i];
		if (TeammatePRI != nullptr && TeammatePRI != myPRI && !myPRI->bCallForMedic && TeammatePRI->bIsMedic)
		{
			if (ShouldDrawPlayer(TeammatePRI, i))
			{
				TeammatePRI->bVisibleLastTick = true;
				DrawPlayer(C, TeammatePRI, i, ((myPRI->LinkedTo & (1 << i)) != 0));
			}
			else
			{
				TeammatePRI->bVisibleLastTick = false;
				DrawPlayer(C, TeammatePRI, i, ((myPRI->LinkedTo & (1 << i)) != 0));
			}
		}
	}
}

bool UHUDRadar::ShouldDrawPlayer(AAA2_PlayerState* PRI, int32 TeamListID)
{
	ATeamInfo* MyTeam = nullptr;
	AAA2_PlayerState* FTLPRI = nullptr;
	if (PRI->VehicleReplicationInfo != nullptr)
	{
		return false;
	}
	/*
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		return true;
	}
	*/
	if (PRI == myPRI)
	{
		return true;
	}
	if (myPRI != nullptr)
	{
		MyTeam = myPRI->Team;
	}
	if (MyTeam == nullptr)
	{
		return false;
	}
	if (PRI == nullptr || PRI->IsSpectator() || PRI->IsOnlyASpectator() || PRI->bWaitingPlayer || PRI->bDead || PRI->bOutOfLives)
	{
		return false;
	}
	if (myPRI == MySQLPRI)
	{
		return true;
	}
	if (myPRI->bCallForMedic && PRI->bIsMedic)
	{
		return true;
	}
	if (PRI->bVIPPS)
	{
		return true;
	}
	/*
	if (PRI->requiredClass == AClassPrisoner::StaticClass())
	{
		return true;
	}
	*/
	if (myPRI->bIsMedic && PRI->bCallForMedic)
	{
		return true;
	}
	if (PRI != nullptr)
	{
		FTLPRI = PRI->GetFTLeader();
	}
	if (PRI->FT == myPRI->FT && PRI->LinkedToFTLeader)
	{
		return true;
	}
	if ((myPRI->LinkedTo & (1 << TeamListID)) == 0)
	{
		if (PRI != MySQLPRI && PRI != MyFTLPRI)
		{
			if (myPRI != FTLPRI || PRI->FT != myPRI->FT)
			{
				if (!bShowFTLSiblings || myPRI != FTLPRI || PRI != FTLPRI)
				{
					return false;
				}
			}
		}
	}
	return true;
}

void UHUDRadar::DrawPlayer(UCanvas* C, AAA2_PlayerState* PRI, int32 TeamListID, bool bLinkedTo)
{
	FVector DrawLocation = FVector(0, 0, 0);
	float PlayerDrawScale = 0;
	float NullDrawScale = 0;
	float DistanceZ = 0;
	ATeamInfo* MyTeam = nullptr;
	AAA2_PlayerState* FTLPRI = nullptr;
	FColor PlayerColor = FColor(0, 0, 0, 0);
	bool bDrawBleedingIcon = false;
	bool bDrawMedicIcon = false;
	bool bPlayerBlinked = false;
	float DrawOffset_LinkedRingIcon = 0;
	float DrawSize_LinkedRingIcon = 0;
	float DrawScale_LinkedRingIcon = 0;
	int32 HeightState = 0;
	FVector StartTrace = FVector(0, 0, 0);
	FRotator CameraRotation = FRotator(0, 0, 0);
	AActor* TestActor = nullptr;
	/*
	UTexRotator* RotatableImage = nullptr;
	if ((PRI == nullptr) || ((PRI->RadarDrawOpacity <= 0) && (PRI->bDead || PRI->bOutOfLives)))
	{
		return;
	}
	if (myPRI != nullptr)
	{
		MyTeam = myPRI->Team;
	}
	if ((PRI != nullptr) && (PRI->Team != nullptr))
	{
		FTLPRI = PRI->GetFTLeader();
	}
	DrawLocation = WorldToMapCoords(PRI->GetPawnLocation());
	DrawLocation = MapToScreenCoords(DrawLocation);
	DrawLocation.Z = 0;
	NullDrawScale = 1;
	PlayerDrawScale = BaseDrawScale;
	if (PRI == MySQLPRI)
	{
		(PlayerDrawScale *= 1.25);
	}
	PlayerColor = BaseElementColor;
	if ((PRI == MySQLPRI) && (!((myLevel->NetMode == NM_Standalone) || (PRI->Team == nullptr))))
	{
		PlayerColor = YellowColor;
	}
	PlayerColor.A = uint8(PRI->RadarDrawOpacity);
	bDrawMedicIcon = ((myPRI->bCallForMedic && PRI->bIsMedic) && (myPRI != PRI));
	bDrawBleedingIcon = ((myPRI->bIsMedic || (PRI == myPRI)) && PRI->bCallForMedic);
	if (((myPRI != MySQLPRI) && (PRI != MySQLPRI)) && (PRI->FT != myPRI->FT))
	{
		(PlayerColor.R /= 2);
		(PlayerColor.G /= 2);
		(PlayerColor.B /= 2);
	}
	if (bDrawMedicIcon || bDrawBleedingIcon)
	{
		CullRadarElement(DrawLocation, NullDrawScale);
	}
	else
	{
		CullRadarElement(DrawLocation, PlayerDrawScale);
	}
	if (PRI->bDead || PRI->bOutOfLives)
	{
		C->DrawColor = RedColor;
		C->DrawColor.A = PlayerColor.A;
		C->SetPos((DrawLocation.X - (PlayerDrawScale * DrawOffset_DeadPlayerIcon)), (DrawLocation.Y - (PlayerDrawScale * DrawOffset_DeadPlayerIcon)));
		C->DrawTileScaled(DeadPlayerIcon, (PlayerDrawScale * cFrame->fScaleX), (PlayerDrawScale * cFrame->fScaleX));
		C->DrawColor = cFrame->cHUD->HUDColor;
		return;
	}
	DrawOffset_LinkedRingIcon = (((PlayerDrawScale * (float(LinkedRingIcon.MaterialUSize()) / 2)) + RingRadius) * cFrame->fScaleX);
	DrawSize_LinkedRingIcon = (((PlayerDrawScale * float(LinkedRingIcon.MaterialUSize())) + (2 * RingRadius)) * cFrame->fScaleX);
	DrawScale_LinkedRingIcon = (cFrame->fScaleX * (PlayerDrawScale + ((2 * RingRadius) / float(LinkedRingIcon.MaterialUSize()))));
	bPlayerBlinked = DrawPRIBlink(C, YellowColor, (DrawLocation.X - DrawOffset_LinkedRingIcon), (DrawLocation.Y - DrawOffset_LinkedRingIcon), DrawSize_LinkedRingIcon, DrawSize_LinkedRingIcon, PRI);
	if (PRI->RadarDrawOpacity <= 0)
	{
		return;
	}
	if ((myLevel->NetMode == NM_Standalone) || (PRI->Team == nullptr))
	{
		GOTO JL0729;
	}
	if (bLinkedTo)
	{
		if (PRI->LinkedToSquadLeader || (PRI == MySQLPRI))
		{
			C->DrawColor = SQLLinkedDrawColor;
		}
		else
		{
			if (PRI->LinkedToFTLeader || (PRI == FTLPRI))
			{
				C->DrawColor = FTLinkedDrawColor;
			}
			else
			{
				if ((PRI->LinkedTo & (~(1 << TeamListID))) != 0)
				{
					C->DrawColor = LinkedDrawColor;
				}
				else
				{
					C->DrawColor = UnLinkedDrawColor;
				}
			}
		}
		if (C.DrawColor.A != 0)
		{
			C->DrawColor.A = PlayerColor.A;
		}
		C->SetPos((DrawLocation.X - DrawOffset_LinkedRingIcon), (DrawLocation.Y - DrawOffset_LinkedRingIcon));
		C->DrawTileScaled(LinkedRingIcon, DrawScale_LinkedRingIcon, DrawScale_LinkedRingIcon);
	}
	else
	{
		if (PRI == MySQLPRI)
		{
			C->DrawColor = SQLLinkedDrawColor;
		}
		else
		{
			if (PRI == FTLPRI)
			{
				C->DrawColor = FTLinkedDrawColor;
			}
			else
			{
				C->DrawColor = UnLinkedDrawColor;
			}
		}
		if (C.DrawColor.A != 0)
		{
			C->DrawColor.A = PlayerColor.A;
		}
		C->SetPos((DrawLocation.X - DrawOffset_LinkedRingIcon), (DrawLocation.Y - DrawOffset_LinkedRingIcon));
		C->DrawTileScaled(LinkedRingIcon, DrawScale_LinkedRingIcon, DrawScale_LinkedRingIcon);
	JL0729:
	}
	DistanceZ = float((myPRI->LocationZ - PRI->LocationZ));
	HeightState = 0;
	if (DistanceZ >= HeightToDrawArrow)
	{
		HeightState = 1;
	}
	else
	{
		if (DistanceZ <= (-HeightToDrawArrow))
		{
			HeightState = 2;
		}
	}
	RotatableImage = GetRotatableImage();
	if (PRI == myPRI)
	{
		MyController->PlayerCalcView(TestActor, StartTrace, CameraRotation);
		RotatableImage.Rotation.Yaw = (ViewRotation.Yaw - (Normalize(CameraRotation).Yaw + 16384));
	}
	else
	{
		RotatableImage.Rotation.Yaw = (ViewRotation.Yaw - (PRI->GetPawnYaw() + 16384));
	}
	C->DrawColor = PlayerColor;
	if (bDrawBleedingIcon)
	{
		C->DrawColor.R = uint8(((float(C.DrawColor.R) * (1 - SmoothFlashBlend)) + (float(RedColor.R) * SmoothFlashBlend)));
		C->DrawColor.G = uint8(((float(C.DrawColor.G) * (1 - SmoothFlashBlend)) + (float(RedColor.G) * SmoothFlashBlend)));
		C->DrawColor.B = uint8(((float(C.DrawColor.B) * (1 - SmoothFlashBlend)) + (float(RedColor.B) * SmoothFlashBlend)));
	}
	if ((myLevel->NetMode == NM_Standalone) || (PRI->Team == nullptr))
	{
		RotatableImage.Material = PlayerArrow;
		RotatableImage.UOffset = (DrawOffset_PlayerArrow / cFrame->fScaleX);
		RotatableImage.VOffset = (DrawOffset_PlayerArrow / cFrame->fScaleX);
		C->SetPos((DrawLocation.X - (PlayerDrawScale * DrawOffset_PlayerArrow)), (DrawLocation.Y - (PlayerDrawScale * DrawOffset_PlayerArrow)));
		C->DrawTileScaled(RotatableImage, (PlayerDrawScale * cFrame->fScaleX), (PlayerDrawScale * cFrame->fScaleX));
	}
	else
	{
		if (PRI == MySQLPRI)
		{
			RotatableImage.Rotation.Yaw = (ViewRotation.Yaw - (PRI->GetPawnYaw() + 16384));
			RotatableImage.Material = SquadLeaderArrow;
			RotatableImage.UOffset = (DrawOffset_SquadLeaderArrow / cFrame->fScaleX);
			RotatableImage.VOffset = (DrawOffset_SquadLeaderArrow / cFrame->fScaleX);
			C->SetPos((DrawLocation.X - (PlayerDrawScale * DrawOffset_SquadLeaderArrow)), (DrawLocation.Y - (PlayerDrawScale * DrawOffset_SquadLeaderArrow)));
			C->DrawTileScaled(RotatableImage, (PlayerDrawScale * cFrame->fScaleX), (PlayerDrawScale * cFrame->fScaleX));
		}
		else
		{
			RotatableImage.Material = PlayerArrow;
			RotatableImage.UOffset = (DrawOffset_PlayerArrow / cFrame->fScaleX);
			RotatableImage.VOffset = (DrawOffset_PlayerArrow / cFrame->fScaleX);
			C->SetPos((DrawLocation.X - (PlayerDrawScale * DrawOffset_PlayerArrow)), (DrawLocation.Y - (PlayerDrawScale * DrawOffset_PlayerArrow)));
			C->DrawTileScaled(RotatableImage, (PlayerDrawScale * cFrame->fScaleX), (PlayerDrawScale * cFrame->fScaleX));
		}
	}
	C->DrawColor = PlayerColor;
	if (bDrawBleedingIcon)
	{
		C->DrawColor.R = uint8(((float(C.DrawColor.R) * (1 - SmoothFlashBlend)) + (float(RedColor.R) * SmoothFlashBlend)));
		C->DrawColor.G = uint8(((float(C.DrawColor.G) * (1 - SmoothFlashBlend)) + (float(RedColor.G) * SmoothFlashBlend)));
		C->DrawColor.B = uint8(((float(C.DrawColor.B) * (1 - SmoothFlashBlend)) + (float(RedColor.B) * SmoothFlashBlend)));
	}
	if ((myLevel->NetMode == NM_Standalone) || (PRI->Team == nullptr))
	{
		C->SetPos((DrawLocation.X - (PlayerDrawScale * DrawOffset_PlayerIcon)), (DrawLocation.Y - (PlayerDrawScale * DrawOffset_PlayerIcon)));
		C->DrawTileScaled(PlayerIcon, (PlayerDrawScale * cFrame->fScaleX), (PlayerDrawScale * cFrame->fScaleX));
	}
	else
	{
		if (((HeightState > 0) && MyController->bRadarShowPlayerInfo) && MyController->bRadarShowPlayerInfoElevation)
		{
			if (HeightState == 1)
			{
				C->SetPos((DrawLocation.X - (PlayerDrawScale * DrawOffset_PlayerBelowIcon)), (DrawLocation.Y - (PlayerDrawScale * DrawOffset_PlayerBelowIcon)));
				C->DrawTileScaled(PlayerBelowIcon, (PlayerDrawScale * cFrame->fScaleX), (PlayerDrawScale * cFrame->fScaleX));
			}
			else
			{
				C->SetPos((DrawLocation.X - (PlayerDrawScale * DrawOffset_PlayerAboveIcon)), (DrawLocation.Y - (PlayerDrawScale * DrawOffset_PlayerAboveIcon)));
				C->DrawTileScaled(PlayerAboveIcon, (PlayerDrawScale * cFrame->fScaleX), (PlayerDrawScale * cFrame->fScaleX));
			}
		}
		else
		{
			if (bDrawMedicIcon)
			{
				C->SetDrawColor(255, 255, 255, 255);
				C->SetPos((DrawLocation.X - (PlayerDrawScale * DrawOffset_MedicIcon)), (DrawLocation.Y - (PlayerDrawScale * DrawOffset_MedicIcon)));
				C->DrawTileScaled(MedicIcon, (PlayerDrawScale * cFrame->fScaleX), (PlayerDrawScale * cFrame->fScaleX));
			}
			else
			{
				if (PRI->bVIPPS)
				{
					C->SetPos((DrawLocation.X - (PlayerDrawScale * DrawOffset_VIPIcon)), (DrawLocation.Y - (PlayerDrawScale * DrawOffset_VIPIcon)));
					C->DrawTileScaled(VIPIcon, (PlayerDrawScale * cFrame->fScaleX), (PlayerDrawScale * cFrame->fScaleX));
				}
				else
				{
					if (PRI->requiredClass == AClassPrisoner::StaticClass())
					{
						C->SetPos((DrawLocation.X - (PlayerDrawScale * DrawOffset_POWIcon)), (DrawLocation.Y - (PlayerDrawScale * DrawOffset_POWIcon)));
						C->DrawTileScaled(POWIcon, (PlayerDrawScale * cFrame->fScaleX), (PlayerDrawScale * cFrame->fScaleX));
					}
					else
					{
						if (PRI == MySQLPRI)
						{
							C->SetPos((DrawLocation.X - (PlayerDrawScale * DrawOffset_SquadLeaderIcon)), (DrawLocation.Y - (PlayerDrawScale * DrawOffset_SquadLeaderIcon)));
							C->DrawTileScaled(SquadLeaderIcon, (PlayerDrawScale * cFrame->fScaleX), (PlayerDrawScale * cFrame->fScaleX));
						}
						else
						{
							if (PRI == FTLPRI)
							{
								C->SetPos((DrawLocation.X - (PlayerDrawScale * DrawOffset_LeaderIcon)), (DrawLocation.Y - (PlayerDrawScale * DrawOffset_LeaderIcon)));
								C->DrawTileScaled(LeaderIcon, (PlayerDrawScale * cFrame->fScaleX), (PlayerDrawScale * cFrame->fScaleX));
								C->SetPos((DrawLocation.X - (PlayerDrawScale * DrawOffset_ObjectiveLetters)), (DrawLocation.Y - (PlayerDrawScale * (DrawOffset_ObjectiveLetters - (FTLLetterOffsetY * cFrame->fScaleX)))));
								C->DrawTileScaled(ObjectiveLetters[PRI->FT], (PlayerDrawScale * cFrame->fScaleX), (PlayerDrawScale * cFrame->fScaleX));
							}
							else
							{
								if (PRI == myPRI)
								{
									C->SetPos((DrawLocation.X - (PlayerDrawScale * DrawOffset_PlayerIcon)), (DrawLocation.Y - (PlayerDrawScale * DrawOffset_PlayerIcon)));
									C->DrawTileScaled(PlayerIcon, (PlayerDrawScale * cFrame->fScaleX), (PlayerDrawScale * cFrame->fScaleX));
								}
								else
								{
									C->SetPos((DrawLocation.X - (PlayerDrawScale * DrawOffset_TeammateIcon)), (DrawLocation.Y - (PlayerDrawScale * DrawOffset_TeammateIcon)));
									C->DrawTileScaled(TeammateIcon, (PlayerDrawScale * cFrame->fScaleX), (PlayerDrawScale * cFrame->fScaleX));
								}
							}
						}
					}
				}
			}
		}
	}
	C->DrawColor = cFrame->cHUD->HUDColor;
	*/
}

bool UHUDRadar::DrawBlink(UCanvas* C, FColor BlinkColor, float PositionX, float PositionY, float SizeX, float SizeY, float StartTime, float EndTime)
{
	float CurrentStartTime = 0;
	float CurrentEndTime = 0;
	float BlinkBlend = 0;
	float HalfOffsetX = 0;
	float HalfOffsetY = 0;
	uint8 DrawAlpha = 0;
	if (!MyController->bShowRadarBlinking)
	{
		return false;
	}
	EndTime = ((StartTime + (float(int(((EndTime - StartTime) / BlinkDelaySeconds))) * BlinkDelaySeconds)) + BlinkDurationSeconds);
	if (GetWorld()->GetTimeSeconds() >= EndTime)
	{
		return false;
	}
	CurrentStartTime = StartTime;
	CurrentEndTime = (StartTime + BlinkDurationSeconds);
	if ((CurrentStartTime + BlinkDurationSeconds) < EndTime)
	{
		if ((GetWorld()->GetTimeSeconds() >= CurrentStartTime) && (GetWorld()->GetTimeSeconds() < CurrentEndTime))
		{
			BlinkBlend = ((GetWorld()->GetTimeSeconds() - CurrentStartTime) / (CurrentEndTime - CurrentStartTime));
			HalfOffsetX = (10 * BlinkBlend);
			HalfOffsetY = (10 * BlinkBlend);
			DrawAlpha = uint8(((1 - BlinkBlend) * 255));
			//C->DrawColor = BlinkColor;
			//C->DrawColor.A = DrawAlpha;
			//C->SetPos((PositionX - HalfOffsetX), (PositionY - HalfOffsetY));
			//C->DrawTile(LinkedRingIcon, (SizeX + (2 * HalfOffsetX)), (SizeY + (2 * HalfOffsetY)), 0, 0, float(LinkedRingIcon.MaterialUSize()), float(LinkedRingIcon.MaterialVSize()));
		}
		CurrentStartTime += BlinkDelaySeconds;
		CurrentEndTime += BlinkDelaySeconds;
	}
	//C->DrawColor = cFrame->cHUD->HUDColor;
	return true;
}

bool UHUDRadar::DrawPRIBlink(UCanvas* C, FColor BlinkColor, float PositionX, float PositionY, float SizeX, float SizeY, AAA2_PlayerState* PRI)
{
	if (!MyController->bShowRadarBlinking)
	{
		return false;
	}
	if (PRI->RadarBlinkStartTime != PRI->LastRadarBlinkStartTime)
	{
		PRI->BlinkLatency = GetWorld()->GetTimeSeconds() - PRI->RadarBlinkStartTime;
		PRI->LastRadarBlinkStartTime = PRI->RadarBlinkStartTime;
	}
	if (PRI->RadarBlinkEndTime != PRI->LastRadarBlinkEndTime)
	{
		PRI->LastRadarBlinkEndTime = PRI->RadarBlinkEndTime;
	}
	return DrawBlink(C, BlinkColor, PositionX, PositionY, SizeX, SizeY, PRI->LastRadarBlinkStartTime + PRI->BlinkLatency, PRI->LastRadarBlinkEndTime + PRI->BlinkLatency);
}

bool UHUDRadar::DrawObjectiveBlink(UCanvas* C, FColor BlinkColor, float PositionX, float PositionY, float SizeX, float SizeY, AAGP_Objective* obj)
{
	if (!MyController->bShowRadarBlinking)
	{
		return false;
	}
	if (myPRI->Team->TeamIndex == 0)
	{
		if (obj->RadarBlinkStartTime != obj->LastRadarBlinkStartTime)
		{
			obj->BlinkLatency = GetWorld()->GetTimeSeconds() - obj->RadarBlinkStartTime;
			obj->LastRadarBlinkStartTime = obj->RadarBlinkStartTime;
		}
		if (obj->RadarBlinkEndTime != obj->LastRadarBlinkEndTime)
		{
			obj->LastRadarBlinkEndTime = obj->RadarBlinkEndTime;
		}
		return DrawBlink(C, BlinkColor, PositionX, PositionY, SizeX, SizeY, obj->LastRadarBlinkStartTime + obj->BlinkLatency, obj->LastRadarBlinkEndTime + obj->BlinkLatency);
	}
	else
	{
		if (myPRI->Team->TeamIndex == 1)
		{
			if (obj->RadarBlinkStartTime1 != obj->LastRadarBlinkStartTime)
			{
				obj->BlinkLatency = GetWorld()->GetTimeSeconds() - obj->RadarBlinkStartTime1;
				obj->LastRadarBlinkStartTime = obj->RadarBlinkStartTime1;
			}
			if (obj->RadarBlinkEndTime1 != obj->LastRadarBlinkEndTime)
			{
				obj->LastRadarBlinkEndTime = obj->RadarBlinkEndTime1;
			}
			return DrawBlink(C, BlinkColor, PositionX, PositionY, SizeX, SizeY, obj->LastRadarBlinkStartTime + obj->BlinkLatency, obj->LastRadarBlinkEndTime + obj->BlinkLatency);
		}
	}
	return false;    //FAKE   /EliZ
}

void UHUDRadar::DrawObjectives(UCanvas* C)
{
	int32 i = 0;
	FVector DrawLocation = FVector(0, 0, 0);
	float DistanceZ = 0;
	ATeamInfo* MyTeam = nullptr;
	float ObjDrawScale = 0;
	bool bObjectiveBlinked = false;
	bool bIsInstantWin = false;
	float DrawOffset_LinkedRingIcon = 0;
	float DrawSize_LinkedRingIcon = 0;
	float DrawScale_LinkedRingIcon = 0;
	FColor ObjectiveColor = FColor(0, 0, 0, 0);
	/*
	for (i = 0; i < ObjectiveList.Num(); i++)
	{
		if (ObjectiveList[i]->IsA(AAGP_CoopESSObjective::StaticClass()))
		{
			if (!ObjectiveList[i].isOnRadar())
			{
			}
		}
		else
		{
			else
			{
			if (!ObjectiveList[i].IsOnCompass(MyController))
			{
			}
			}
			else
			{
			bIsInstantWin = ObjectiveList[i].IsInstantWin();
			DrawLocation = WorldToMapCoords(ObjectiveList[i].GetCompassLocation());
			DrawLocation = MapToScreenCoords(DrawLocation);
			DrawLocation.Z = 0;
			ObjDrawScale = FMin((BaseDrawScale * 1.5), 1);
			CullRadarElement(DrawLocation, ObjDrawScale);
			DrawOffset_LinkedRingIcon = (((ObjDrawScale * (float(LinkedRingIcon.MaterialUSize()) / 2)) + RingRadius) * cFrame->fScaleX);
			DrawSize_LinkedRingIcon = (((ObjDrawScale * float(LinkedRingIcon.MaterialUSize())) + (2 * RingRadius)) * cFrame->fScaleX);
			DrawScale_LinkedRingIcon = (cFrame->fScaleX * (ObjDrawScale + ((2 * RingRadius) / float(LinkedRingIcon.MaterialUSize()))));
			MyTeam = myPRI->Team;
			if ((MyTeam != nullptr) && ObjectiveList[i].IsSquadTarget(MyTeam->TeamIndex))
			{
				bObjectiveBlinked = DrawObjectiveBlink(C, YellowColor, (DrawLocation.X - DrawOffset_LinkedRingIcon), (DrawLocation.Y - DrawOffset_LinkedRingIcon), DrawSize_LinkedRingIcon, DrawSize_LinkedRingIcon, ObjectiveList[i]);
			}
			if (ObjectiveList[i].AccomplishedBy == 255)
			{
				ObjectiveColor = YellowColor;
			}
			else
			{
				if (MyTeam != nullptr)
				{
					if (ObjectiveList[i].AccomplishedBy == MyTeam->TeamIndex)
					{
						ObjectiveColor = GreenColor;
					}
					else
					{
						ObjectiveColor = RedColor;
					}
				}
				else
				{
					ObjectiveColor = YellowColor;
				}
			}
			if (ObjectiveList[i]->IsA(AAGP_CoopESSObjective::StaticClass()))
			{
				ObjectiveColor = RedColor;
			}
			ObjectiveColor.A = 255;
			C->DrawColor = ObjectiveColor;
			DistanceZ = (float(myPRI->LocationZ) - ObjectiveList[i].GetCompassLocation().Z);
			if (DistanceZ >= HeightToDrawArrow)
			{
				if (bIsInstantWin)
				{
					C->SetPos((DrawLocation.X - (ObjDrawScale * DrawOffset_PrimaryObjectiveBelowIcon)), (DrawLocation.Y - (ObjDrawScale * DrawOffset_PrimaryObjectiveBelowIcon)));
					C->DrawTileScaled(PrimaryObjectiveBelowIcon, (ObjDrawScale * cFrame->fScaleX), (ObjDrawScale * cFrame->fScaleX));
				}
				else
				{
					C->SetPos((DrawLocation.X - (ObjDrawScale * DrawOffset_SecondaryObjectiveBelowIcon)), (DrawLocation.Y - (ObjDrawScale * DrawOffset_SecondaryObjectiveBelowIcon)));
					C->DrawTileScaled(SecondaryObjectiveBelowIcon, (ObjDrawScale * cFrame->fScaleX), (ObjDrawScale * cFrame->fScaleX));
				}
			}
			else
			{
				if (DistanceZ <= (-HeightToDrawArrow))
				{
					if (bIsInstantWin)
					{
						C->SetPos((DrawLocation.X - (ObjDrawScale * DrawOffset_PrimaryObjectiveAboveIcon)), (DrawLocation.Y - (ObjDrawScale * DrawOffset_PrimaryObjectiveAboveIcon)));
						C->DrawTileScaled(PrimaryObjectiveAboveIcon, (ObjDrawScale * cFrame->fScaleX), (ObjDrawScale * cFrame->fScaleX));
					}
					else
					{
						C->SetPos((DrawLocation.X - (ObjDrawScale * DrawOffset_SecondaryObjectiveAboveIcon)), (DrawLocation.Y - (ObjDrawScale * DrawOffset_SecondaryObjectiveAboveIcon)));
						C->DrawTileScaled(SecondaryObjectiveAboveIcon, (ObjDrawScale * cFrame->fScaleX), (ObjDrawScale * cFrame->fScaleX));
					}
				}
			}
			if (ObjectiveList[i]->IsA(AAGP_CoopESSObjective::StaticClass()))
			{
				ObjDrawScale = FMin(BaseDrawScale, 1);
				C->SetPos((DrawLocation.X - (ObjDrawScale * DrawOffset_PrimaryObjectiveIcon)), (DrawLocation.Y - (ObjDrawScale * DrawOffset_PrimaryObjectiveIcon)));
				C->DrawTileScaled(ESSIcon, (ObjDrawScale * cFrame->fScaleX), (ObjDrawScale * cFrame->fScaleX));
			}
			else
			{
				if (ObjectiveList[i].AccomplishedBy == 255)
				{
					if (bIsInstantWin)
					{
						C->SetPos((DrawLocation.X - (ObjDrawScale * DrawOffset_PrimaryObjectiveIcon)), (DrawLocation.Y - (ObjDrawScale * DrawOffset_PrimaryObjectiveIcon)));
						C->DrawTileScaled(PrimaryObjectiveIcon, (ObjDrawScale * cFrame->fScaleX), (ObjDrawScale * cFrame->fScaleX));
					}
					else
					{
						C->SetPos((DrawLocation.X - (ObjDrawScale * DrawOffset_SecondaryObjectiveIcon)), (DrawLocation.Y - (ObjDrawScale * DrawOffset_SecondaryObjectiveIcon)));
						C->DrawTileScaled(SecondaryObjectiveIcon, (ObjDrawScale * cFrame->fScaleX), (ObjDrawScale * cFrame->fScaleX));
					}
				}
				else
				{
					if (MyTeam != nullptr)
					{
						if (ObjectiveList[i].AccomplishedBy == MyTeam->TeamIndex)
						{
							if (bIsInstantWin)
							{
								C->SetPos((DrawLocation.X - (ObjDrawScale * DrawOffset_PrimaryObjectiveAccomplished)), (DrawLocation.Y - (ObjDrawScale * DrawOffset_PrimaryObjectiveAccomplished)));
								C->DrawTileScaled(PrimaryObjectiveAccomplished, (ObjDrawScale * cFrame->fScaleX), (ObjDrawScale * cFrame->fScaleX));
							}
							else
							{
								C->SetPos((DrawLocation.X - (ObjDrawScale * DrawOffset_SecondaryObjectiveAccomplished)), (DrawLocation.Y - (ObjDrawScale * DrawOffset_SecondaryObjectiveAccomplished)));
								C->DrawTileScaled(SecondaryObjectiveAccomplished, (ObjDrawScale * cFrame->fScaleX), (ObjDrawScale * cFrame->fScaleX));
							}
						}
						else
						{
							if (bIsInstantWin)
							{
								C->SetPos((DrawLocation.X - (ObjDrawScale * DrawOffset_PrimaryObjectiveFailed)), (DrawLocation.Y - (ObjDrawScale * DrawOffset_PrimaryObjectiveFailed)));
								C->DrawTileScaled(PrimaryObjectiveFailed, (ObjDrawScale * cFrame->fScaleX), (ObjDrawScale * cFrame->fScaleX));
							}
							else
							{
								C->SetPos((DrawLocation.X - (ObjDrawScale * DrawOffset_SecondaryObjectiveFailed)), (DrawLocation.Y - (ObjDrawScale * DrawOffset_SecondaryObjectiveFailed)));
								C->DrawTileScaled(SecondaryObjectiveFailed, (ObjDrawScale * cFrame->fScaleX), (ObjDrawScale * cFrame->fScaleX));
							}
						}
					}
				}
			}
			if ((ObjectiveList[i].HUDLetter < ObjectiveLetters.Num()) && (!ObjectiveList[i]->IsA(AAGP_CoopESSObjective::StaticClass())))
			{
				C->SetPos((DrawLocation.X - (ObjDrawScale * DrawOffset_ObjectiveLetters)), (DrawLocation.Y - (ObjDrawScale * DrawOffset_ObjectiveLetters)));
				C->DrawTileScaled(ObjectiveLetters[ObjectiveList[i].HUDLetter], (ObjDrawScale * cFrame->fScaleX), (ObjDrawScale * cFrame->fScaleX));
			}
			}
		}
	}
	C->DrawColor = cFrame->cHUD->HUDColor;
	*/
}

void UHUDRadar::DrawVehicleNames(UCanvas* C)
{
	int32 i = 0;
	int32 V = 0;
	UFont* oldfont = nullptr;
	AAGP_VehicleReplicationInfo* VRI = nullptr;
	int32 PassengerCount = 0;
	AAA2_PlayerState* DriverPRI = nullptr;
	AAA2_PlayerState* GunnerPRI = nullptr;
	TArray<AAA2_PlayerState*> Passengers ={};
	FVector DrawLocation = FVector(0,0,0);
	float XL = 0;
	float YL = 0;
	float XPos = 0;
	float YPos = 0;
	float TotalNameHeight = 0;
	float VehicleDrawScale = 0;
	if (!MyController->bRadarShowPlayerInfo && MyController->bRadarShowPlayerInfoNames || myLevel == nullptr || myLevel->GRI == nullptr)
	{
		return;
	}
	//oldfont = C->Font;
	//cFrame->cHUD->UseSmallFont(C);
	C->DrawColor = cFrame->cHUD->HUDColor;
	C->DrawColor.A = 255;
	for (V = 0; V < myLevel->GRI->VRIArray.Num(); V++)
	{
		VRI = Cast<AAGP_VehicleReplicationInfo>(myLevel->GRI->VRIArray[V]);
		if (VRI != nullptr && VRI->IsPlayerDriveable())
		{
			PassengerCount = VRI->GetPassengerCount();
			if (PassengerCount > 0)
			{
				Passengers = VRI->GetPassengers();
				DriverPRI = VRI->GetDriver();
				GunnerPRI = VRI->GetGunner();
				DrawLocation = WorldToMapCoords(VRI->GetVehiclePosition());
				DrawLocation = MapToScreenCoords(DrawLocation);
				DrawLocation.Z = 0;
				VehicleDrawScale = FMath::Min(BaseDrawScale * 1.5f, 1.0f);
				CullRadarElement(DrawLocation, VehicleDrawScale);
				//C->TextSize(Passengers[0].PlayerName, XL, YL);
				TotalNameHeight = YL * PassengerCount;
				XPos = DrawLocation.X + VehicleDrawScale * DrawOffset_VehicleIcon;
				YPos = DrawLocation.Y - TotalNameHeight / 2;
				if (DriverPRI != nullptr)
				{
					//C->SetPos(XPos, YPos);
					//C->DrawText("(D)" @ DriverPRI->PlayerName);
					YPos += YL;
				}
				if (GunnerPRI != nullptr)
				{
					//C->SetPos(XPos, YPos);
					//C->DrawText("(G)" @ GunnerPRI->PlayerName);
					YPos += YL;
				}
				for (i = 0; i < PassengerCount; i++)
				{
					if (Passengers[i] != DriverPRI && Passengers[i] != GunnerPRI)
					{
						//C->SetPos(XPos, YPos);
						//C->DrawText(Passengers[i].PlayerName);
						YPos += YL;
					}
				}
			}
		}
	}
	//C->Font = oldfont;
	//C->DrawColor = cFrame->cHUD->HUDColor;
}

void UHUDRadar::DrawVehicles(UCanvas* C)
{
	int32 V = 0;
	AAGP_VehicleReplicationInfo* VRI = nullptr;
	if (myLevel != nullptr && myLevel->GRI != nullptr)
	{
		for (V = 0; V < myLevel->GRI->VRIArray.Num(); V++)
		{
			VRI = Cast<AAGP_VehicleReplicationInfo>(myLevel->GRI->VRIArray[V]);
			if (VRI != nullptr && VRI->IsPlayerDriveable())
			{
				DrawVehicle(C, VRI->GetVehiclePosition(), VRI->GetVehicleRotation().Yaw, VRI->GetVehicleNumber(), VRI->IsVehicleDisabled());
			}
		}
	}
}

void UHUDRadar::DrawVehicle(UCanvas* C, FVector vLocation, float VYaw, int32 VehicleNumber, bool bIsDead)
{
	float VehicleDrawScale = 0;
	FVector DrawLocation = FVector(0,0,0);
	UMaterialInstance* MyRotatingTexture = nullptr;
	DrawLocation = WorldToMapCoords(vLocation);
	DrawLocation = MapToScreenCoords(DrawLocation);
	DrawLocation.Z = 0;
	VehicleDrawScale = FMath::Min(BaseDrawScale * 1.5f, 1.0f);
	CullRadarElement(DrawLocation, VehicleDrawScale);
	//MyRotatingTexture[0] = GetRotatableImage();
	//MyRotatingTexture[1] = GetRotatableImage();
	//MyRotatingTexture[0].Rotation.Yaw = ViewRotation.Yaw - VYaw + 16384;
	//MyRotatingTexture[0].Material = VehicleIcon;
	//MyRotatingTexture[0].UOffset = DrawOffset_VehicleIcon / cFrame->fScaleX;
	//MyRotatingTexture[0].VOffset = DrawOffset_VehicleIcon / cFrame->fScaleX;
	if (!bIsDead)
	{
		C->DrawColor = BaseElementColor;
	}
	else
	{
		C->DrawColor = RedColor;
	}
	//C->DrawColor.A = 255;
	//C->SetPos(DrawLocation.X - VehicleDrawScale * DrawOffset_VehicleIcon, DrawLocation.Y - VehicleDrawScale * DrawOffset_VehicleIcon);
	//C->DrawTileScaled(MyRotatingTexture[0], VehicleDrawScale * cFrame->fScaleX, VehicleDrawScale * cFrame->fScaleX);
	if (!bIsDead && VehicleNumber >= 0)
	{
		//MyRotatingTexture[1].Rotation.Yaw = ViewRotation.Yaw - VYaw + 16384;
		//MyRotatingTexture[1].Material = ObjectiveNumbers[VehicleNumber];
		//MyRotatingTexture[1].UOffset = DrawOffset_ObjectiveNumbers / cFrame->fScaleX;
		//MyRotatingTexture[1].VOffset = DrawOffset_ObjectiveNumbers / cFrame->fScaleX;
		//C->DrawColor = BaseElementColor;
		//C->DrawColor.A = 255;
		//C->SetPos(DrawLocation.X - VehicleDrawScale * DrawOffset_ObjectiveNumbers, DrawLocation.Y - VehicleDrawScale * DrawOffset_ObjectiveNumbers);
		//C->DrawTileScaled(MyRotatingTexture[1], VehicleDrawScale * cFrame->fScaleX, VehicleDrawScale * cFrame->fScaleX);
	}
	C->DrawColor = cFrame->cHUD->HUDColor;
}

void UHUDRadar::DrawEnemies(UCanvas* C)
{
	int32 i = 0;
	FEnemySpottedData EnemySpotted = FEnemySpottedData({});
	FVector DrawLocation = FVector(0,0,0);
	float EnemyDrawScale = 0;
	float FadeOutBlend = 0;
	MyController->ClearOldEnemiesSpotted();
	for (i = 0; i < MyController->EnemiesSpotted.Num(); i++)
	{
		EnemySpotted = MyController->EnemiesSpotted[i];
		DrawLocation = WorldToMapCoords(EnemySpotted.SpottedLocation);
		DrawLocation = MapToScreenCoords(DrawLocation);
		DrawLocation.Z = 0;
		EnemyDrawScale = FMath::Min(BaseDrawScale, 1.0f);
		CullRadarElement(DrawLocation, EnemyDrawScale);
		//FadeOutBlend = 1 - GetWorld()->GetTimeSeconds() - EnemySpotted.TimeSpottedSeconds / EnemySpotted.LifeSpan;
		FadeOutBlend = FMath::Clamp(FadeOutBlend * 2, 0.0f, 1.0f);
		//DrawBlink(C, RedColor, DrawLocation.X - DrawOffset_EnemyIcon * EnemyDrawScale, DrawLocation.Y - DrawOffset_EnemyIcon * EnemyDrawScale, EnemyIcon.MaterialUSize() * EnemyDrawScale * cFrame->fScaleX, EnemyIcon.MaterialVSize() * EnemyDrawScale * cFrame->fScaleX, EnemySpotted.BlinkStartTime, EnemySpotted.BlinkEndTime);
		//C->DrawColor = RedColor;
		//C->DrawColor.A = FadeOutBlend * 255;
		//C->SetPos(DrawLocation.X - EnemyDrawScale * DrawOffset_EnemyIcon, DrawLocation.Y - EnemyDrawScale * DrawOffset_EnemyIcon);
		//C->DrawTileScaled(EnemyIcon, EnemyDrawScale * cFrame->fScaleX, EnemyDrawScale * cFrame->fScaleX);
	}
	C->DrawColor = cFrame->cHUD->HUDColor;
}

void UHUDRadar::DrawSpottedESS(UCanvas* C)
{
	int32 i = 0;
	FESSObjectData ESSObjectSpotted = FESSObjectData({});
	FVector DrawLocation = FVector(0,0,0);
	float IconDrawScale = 0;
	float FadeOutBlend = 0;
	FColor cLethality = FColor(0,0,0,0);
	MyController->ClearOldNonLethalESSSpotted();
	for (i = 0; i < MyController->FoundESSObject.Num(); i++)
	{
		ESSObjectSpotted = MyController->FoundESSObject[i];
		DrawLocation = WorldToMapCoords(ESSObjectSpotted.SpottedLocation);
		DrawLocation = MapToScreenCoords(DrawLocation);
		DrawLocation.Z = 0;
		IconDrawScale = FMath::Min(BaseDrawScale, 1.0f);
		CullRadarElement(DrawLocation, IconDrawScale);
		if (!ESSObjectSpotted.bLethal)
		{
			//FadeOutBlend = 1 - GetWorld()->GetTimeSeconds() - ESSObjectSpotted.TimeSpottedSeconds / ESSObjectSpotted.LifeSpan;
			//FadeOutBlend =FMath::Clamp(FadeOutBlend * 2, 0, 1);
		}
		else
		{
			FadeOutBlend = 1;
		}
		if (ESSObjectSpotted.bLethal)
		{
			cLethality = RedColor;
		}
		else
		{
			cLethality = YellowColor;
		}
		//DrawBlink(C, cLethality, DrawLocation.X - DrawOffset_ESSIcon * IconDrawScale, DrawLocation.Y - DrawOffset_ESSIcon * IconDrawScale, ESSIcon.MaterialUSize() * IconDrawScale * cFrame->fScaleX + 5, ESSIcon.MaterialVSize() * IconDrawScale * cFrame->fScaleX + 5, ESSObjectSpotted.BlinkStartTime, ESSObjectSpotted.BlinkEndTime);
		//C->DrawColor = cLethality;
		//C->DrawColor.A = FadeOutBlend * 255;
		//C->SetPos(DrawLocation.X - IconDrawScale * DrawOffset_ESSIcon, DrawLocation.Y - IconDrawScale * DrawOffset_ESSIcon);
		//C->DrawTileScaled(ESSIcon, IconDrawScale * cFrame->fScaleX, IconDrawScale * cFrame->fScaleX);
	}
	C->DrawColor = cFrame->cHUD->HUDColor;
}

void UHUDRadar::DrawHitIndicator(UCanvas* C)
{
	int32 i = 0;
	uint8 HitOpacity = 0;
	HitOpacity = MaskOpacity * OneMinusFullSizeBlend;
	C->SetDrawColor(255, 255, 255, HitOpacity);
	C->DrawColor.A = HitOpacity;
	for (i = 0; i < 4; i++)
	{
		/*
		if (ColorModifiedHitIndicatorImage[i]->Color.A > 0)
		{
			//C->SetPos(DrawPosition.X, DrawPosition.Y);
			//C->DrawTile(ColorModifiedHitIndicatorImage[i], DrawPosition.W, DrawPosition.H, 0, 0, ColorModifiedHitIndicatorImage[i].Material.MaterialUSize(), ColorModifiedHitIndicatorImage[i].Material.MaterialUSize());
		}
		*/
	}
	C->DrawColor = cFrame->cHUD->HUDColor;
}

void UHUDRadar::DrawRadarFrame(UCanvas* C)
{
	int32 AlphaValue = 0;
	AlphaValue = FMath::Max(0.0f, MaskOpacity * OneMinusFullSizeBlend * OneMinusFullSizeBlend * OneMinusFullSizeBlend);
	if (AlphaValue <= 0)
	{
		return;
	}
	C->DrawColor = cFrame->cHUD->HUDColor;
	C->DrawColor.A = AlphaValue;
	//C->SetPos(DrawPosition.X - DrawPosition.W * CompassScaleOffset / 2, DrawPosition.Y - DrawPosition.H * CompassScaleOffset / 2);
	//C->DrawTile(RotatingCompassImage, DrawPosition.W * 1 + CompassScaleOffset, DrawPosition.H * 1 + CompassScaleOffset, 0, 0, RotatingCompassImage.Material.MaterialUSize(), RotatingCompassImage.Material.MaterialVSize());
	C->DrawColor = cFrame->cHUD->HUDColor;
}

void UHUDRadar::DrawTeamNames(UCanvas* C)
{
	int32 i = 0;
	ATeamInfo* MyTeam = nullptr;
	AAA2_PlayerState* TeammatePRI = nullptr;
	MyTeam = myPRI->Team;
	if (MyTeam == nullptr)
	{
		return;
	}
	if (!MyController->bRadarShowPlayerInfo && MyController->bRadarShowPlayerInfoNames)
	{
		return;
	}
	for (i = 0; i < MyTeam->NumRequestSlots; i++)
	{
		TeammatePRI = MyTeam->ActualList_Player[i];
		if (TeammatePRI != nullptr && TeammatePRI != myPRI)
		{
			if (ShouldDrawPlayer(TeammatePRI, i))
			{
				DrawPlayerName(C, TeammatePRI, i, ((myPRI->LinkedTo & (1 << i)) != 0));
			}
			else
			{
				DrawPlayerName(C, TeammatePRI, i, ((myPRI->LinkedTo & (1 << i)) != 0));
			}
		}
	}
}

void UHUDRadar::DrawPlayerName(UCanvas* C, AAA2_PlayerState* PRI, int32 TeamListID, bool bLinkedTo)
{
	FVector DrawLocation = FVector(0,0,0);
	float TextDrawScale = 0;
	AAA2_PlayerState* FTLPRI = nullptr;
	FColor PlayerColor = FColor(0,0,0,0);
	bool bDrawBleedingIcon = false;
	UFont* oldfont = nullptr;
	float XL = 0;
	float YL = 0;
	if (!MyController->bRadarShowPlayerInfo && MyController->bRadarShowPlayerInfoNames)
	{
		return;
	}
	if (PRI != nullptr && PRI->Team != nullptr)
	{
		FTLPRI = PRI->GetFTLeader();
	}
	DrawLocation = WorldToMapCoords(PRI->GetPawnLocation());
	DrawLocation = MapToScreenCoords(DrawLocation);
	DrawLocation.Z = 0;
	TextDrawScale = BaseDrawScale;
	PlayerColor = cFrame->cHUD->HUDColor;
	PlayerColor.A = PRI->RadarDrawOpacity;
	CullRadarElement(DrawLocation, TextDrawScale);
	bDrawBleedingIcon = myPRI->bIsMedic && PRI->bCallForMedic;
	C->DrawColor = PlayerColor;
	//oldfont = C.Font;
	//cFrame->cHUD->UseSmallFont(C);
	//C->TextSize(PRI->PlayerName, XL, YL);
	//C->SetPos(DrawLocation.X + TextDrawScale * DrawOffset_PlayerIcon, DrawLocation.Y - YL / 2);
	//C->DrawText(PRI->PlayerName);
	//C->Font = oldfont;
	//C->DrawColor = cFrame->cHUD->HUDColor;
}
