// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/HUDRadar/HUDRadar.h"

UHUDRadar::UHUDRadar()
{
	//MapImage = FinalBlend'T_AA2_MISC.misc.Misc_Grid_GreenF';
	//HitIndicatorImage = Texture'T_AAO_SAI.Overlays.hitindicator';
	//CompassImage = Texture'T_AAO_SAI.Overlays.t_sai_overlays_compassring';
	//CompassRotImage = Texture'T_AAO_SAI.Overlays.t_sai_overlays_compassring_rot';
	//MaskImage = Texture'T_AAO_SAI.Overlays.sai_mask_255';
	MaskOpacity = 255;
	//MaskImages[0] = Texture'T_AAO_SAI.Overlays.sai_mask_255';
	//MaskImages[1] = Texture'T_AAO_SAI.Overlays.sai_mask_127';
	//MaskOpacities(0) = 255;
	//MaskOpacities(1) = 127;
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
	//LinkedRingIcon = Texture'T_AAO_SAI.Icons.t_sai_icons_linkring_commo';
	//DeadPlayerIcon = Texture'T_AAO_SAI.Icons.t_sai_icons_teammate_dead';
	//TeammateIcon = Texture'T_AAO_SAI.Icons.t_sai_icons_teammate';
	//PlayerIcon = Texture'T_AAO_SAI.Icons.t_sai_icons_player';
	//LeaderIcon = Texture'T_AAO_SAI.Icons.t_sai_icons_teammate';
	//SquadLeaderIcon = Texture'T_AAO_SAI.Icons.t_sai_icons_squadleader';
	//VIPIcon = Texture'T_AAO_SAI.Icons.t_sai_icons_vip';
	//POWIcon = Texture'T_AAO_SAI.Icons.t_sai_icons_pow';
	//PlayerBelowIcon = Texture'T_AAO_SAI.Icons.t_sai_icons_teammate_location_below';
	//PlayerAboveIcon = Texture'T_AAO_SAI.Icons.t_sai_icons_teammate_location_above';
	//PlayerArrow = Texture'T_AAO_SAI.Icons.t_sai_icons_vector_arrow';
	//SquadLeaderArrow = Texture'T_AAO_SAI.Icons.t_sai_icons_squadleader_vector';
	//EnemyIcon = Texture'T_AAO_SAI.Icons.t_sai_icons_enemy_spotted';
	//DeadEnemyIcon = Texture'T_AAO_SAI.Icons.t_sai_icons_enemy_dead';
	//VehicleIcon = Texture'T_AAO_SAI.Icons.t_sai_icons_hmmwv';
	//MedicIcon = Texture'T_AAO_SAI.Icons.t_sai_icons_medic';
	//BleedingIcon = Texture'T_AAO_SAI.Icons.t_sai_icons_bleeding';
	//PrimaryObjectiveBelowIcon = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_primary_location_below';
	//PrimaryObjectiveAboveIcon = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_location_above';
	//SecondaryObjectiveBelowIcon = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_secondary_location_below';
	//SecondaryObjectiveAboveIcon = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_location_above';
	//PrimaryObjectiveIcon = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_primary';
	//PrimaryObjectiveAccomplished = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_primary';
	//PrimaryObjectiveFailed = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_primary';
	//SecondaryObjectiveIcon = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_secondary';
	//SecondaryObjectiveAccomplished = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_secondary';
	//SecondaryObjectiveFailed = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_secondary';
	//ESSIcon = Texture'T_AA2_ES2.ES2_Objects.ES2_UXO_SAIicon';
		
	//ObjectiveLetters(0) = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_a';
	//ObjectiveLetters(1) = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_b';
	//ObjectiveLetters(2) = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_c';
	//ObjectiveLetters(3) = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_d';
	//ObjectiveLetters(4) = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_e';
	//ObjectiveLetters(5) = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_f';
	//ObjectiveLetters(6) = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_g';
	//ObjectiveLetters(7) = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_h';
		
	//ObjectiveNumbers(0) = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_0';
	//ObjectiveNumbers(1) = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_1';
	//ObjectiveNumbers(2) = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_2';
	//ObjectiveNumbers(3) = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_3';
	//ObjectiveNumbers(4) = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_4';
	//ObjectiveNumbers(5) = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_5';
	//ObjectiveNumbers(6) = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_6';
	//ObjectiveNumbers(7) = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_7';
	//ObjectiveNumbers(8) = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_8';
	//ObjectiveNumbers(9) = Texture'T_AAO_SAI.Icons.t_sai_icons_objective_9';
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
	/*
	local int i;
	L.AddPrecacheMaterial(Default.MapImage);
	L.AddPrecacheMaterial(Default.HitIndicatorImage);
	L.AddPrecacheMaterial(Default.CompassImage);
	L.AddPrecacheMaterial(Default.CompassRotImage);
	L.AddPrecacheMaterial(Default.MaskImage);
	L.AddPrecacheMaterial(Default.LinkedRingIcon);
	L.AddPrecacheMaterial(Default.DeadPlayerIcon);
	L.AddPrecacheMaterial(Default.TeammateIcon);
	L.AddPrecacheMaterial(Default.PlayerIcon);
	L.AddPrecacheMaterial(Default.LeaderIcon);
	L.AddPrecacheMaterial(Default.SquadLeaderIcon);
	L.AddPrecacheMaterial(Default.VIPIcon);
	L.AddPrecacheMaterial(Default.POWIcon);
	L.AddPrecacheMaterial(Default.PlayerBelowIcon);
	L.AddPrecacheMaterial(Default.PlayerAboveIcon);
	L.AddPrecacheMaterial(Default.PlayerArrow);
	L.AddPrecacheMaterial(Default.SquadLeaderArrow);
	L.AddPrecacheMaterial(Default.EnemyIcon);
	L.AddPrecacheMaterial(Default.DeadEnemyIcon);
	L.AddPrecacheMaterial(Default.VehicleIcon);
	L.AddPrecacheMaterial(Default.MedicIcon);
	L.AddPrecacheMaterial(Default.BleedingIcon);
	L.AddPrecacheMaterial(Default.PrimaryObjectiveBelowIcon);
	L.AddPrecacheMaterial(Default.PrimaryObjectiveAboveIcon);
	L.AddPrecacheMaterial(Default.SecondaryObjectiveBelowIcon);
	L.AddPrecacheMaterial(Default.SecondaryObjectiveAboveIcon);
	L.AddPrecacheMaterial(Default.PrimaryObjectiveIcon);
	L.AddPrecacheMaterial(Default.PrimaryObjectiveAccomplished);
	L.AddPrecacheMaterial(Default.PrimaryObjectiveFailed);
	L.AddPrecacheMaterial(Default.SecondaryObjectiveIcon);
	L.AddPrecacheMaterial(Default.SecondaryObjectiveAccomplished);
	L.AddPrecacheMaterial(Default.SecondaryObjectiveFailed);
	L.AddPrecacheMaterial(Default.ESSIcon);
	for (i = 0; i < Default.ObjectiveLetters.Length; i++)
	{
		L.AddPrecacheMaterial(Default.ObjectiveLetters[i]);
	}
	for (i = 0; i < Default.ObjectiveNumbers.Length; i++)
	{
		L.AddPrecacheMaterial(Default.ObjectiveNumbers[i]);
	}
	*/
}
void UHUDRadar::Destroyed()
{
	/*
	bInitialized = False;
	MapImage = None;
	HitIndicatorImage = None;
	CompassImage = None;
	CompassRotImage = None;
	ScalingMapImage = None;
	ScalingMaskImage = None;
	RotatingCompassImage = None;
	RotatingMapImage = None;
	RotatingHitIndicatorImage[0] = None;
	RotatingHitIndicatorImage[1] = None;
	RotatingHitIndicatorImage[2] = None;
	RotatingHitIndicatorImage[3] = None;
	RotatableImages.remove(0, RotatableImages.Length);
	ColorModifiedHitIndicatorImage[0] = None;
	ColorModifiedHitIndicatorImage[1] = None;
	ColorModifiedHitIndicatorImage[2] = None;
	ColorModifiedHitIndicatorImage[3] = None;
	MaskImage = None;
	LinkedRingIcon = None;
	DeadPlayerIcon = None;
	TeammateIcon = None;
	PlayerIcon = None;
	LeaderIcon = None;
	SquadLeaderIcon = None;
	VIPIcon = None;
	POWIcon = None;
	PlayerBelowIcon = None;
	PlayerAboveIcon = None;
	PlayerArrow = None;
	SquadLeaderArrow = None;
	EnemyIcon = None;
	DeadEnemyIcon = None;
	VehicleIcon = None;
	MedicIcon = None;
	BleedingIcon = None;
	PrimaryObjectiveBelowIcon = None;
	PrimaryObjectiveAboveIcon = None;
	SecondaryObjectiveBelowIcon = None;
	SecondaryObjectiveAboveIcon = None;
	PrimaryObjectiveIcon = None;
	PrimaryObjectiveAccomplished = None;
	PrimaryObjectiveFailed = None;
	SecondaryObjectiveIcon = None;
	SecondaryObjectiveAccomplished = None;
	SecondaryObjectiveFailed = None;
	ESSIcon = None;
	ObjectiveLetters.remove(0, ObjectiveLetters.Length);
	ObjectiveNumbers.remove(0, ObjectiveNumbers.Length);
	Destroyed();
	*/
}
void UHUDRadar::ScaleControl(UCanvas* Canvas)
{
	/*
	ScaleControl(Canvas);
	DrawOffset_MapImage = Default.MapImage.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_HitIndicatorImage = Default.HitIndicatorImage.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_CompassImage = Default.CompassImage.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_CompassRotImage = Default.CompassRotImage.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_MaskImage = Default.MaskImage.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_DeadPlayerIcon = Default.DeadPlayerIcon.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_TeammateIcon = Default.TeammateIcon.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_PlayerIcon = Default.PlayerIcon.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_LeaderIcon = Default.LeaderIcon.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_SquadLeaderIcon = Default.SquadLeaderIcon.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_VIPIcon = Default.VIPIcon.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_POWIcon = Default.POWIcon.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_PlayerBelowIcon = Default.PlayerBelowIcon.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_PlayerAboveIcon = Default.PlayerAboveIcon.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_PlayerArrow = Default.PlayerArrow.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_SquadLeaderArrow = Default.SquadLeaderArrow.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_EnemyIcon = Default.EnemyIcon.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_DeadEnemyIcon = Default.DeadEnemyIcon.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_VehicleIcon = Default.VehicleIcon.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_MedicIcon = Default.MedicIcon.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_BleedingIcon = Default.BleedingIcon.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_PrimaryObjectiveBelowIcon = Default.PrimaryObjectiveBelowIcon.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_PrimaryObjectiveAboveIcon = Default.PrimaryObjectiveAboveIcon.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_SecondaryObjectiveBelowIcon = Default.SecondaryObjectiveBelowIcon.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_SecondaryObjectiveAboveIcon = Default.SecondaryObjectiveAboveIcon.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_PrimaryObjectiveIcon = Default.PrimaryObjectiveIcon.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_PrimaryObjectiveAccomplished = Default.PrimaryObjectiveAccomplished.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_PrimaryObjectiveFailed = Default.PrimaryObjectiveFailed.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_SecondaryObjectiveIcon = Default.SecondaryObjectiveIcon.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_SecondaryObjectiveAccomplished = Default.SecondaryObjectiveAccomplished.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_SecondaryObjectiveFailed = Default.SecondaryObjectiveFailed.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_ESSIcon = Default.ESSIcon.MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_ObjectiveLetters = Default.ObjectiveLetters[0].MaterialUSize() / 2 * cFrame.fScaleX;
	DrawOffset_ObjectiveNumbers = Default.ObjectiveNumbers[0].MaterialUSize() / 2 * cFrame.fScaleX;
	*/
}
void UHUDRadar::GetRotatableImage()
{
	/*
	if (NextRotatableImageIndex < RotatableImages.Length)
	{
		RotatableImages[NextRotatableImageIndex].Material = None;
		RotatableImages[NextRotatableImageIndex].Rotation = rot(0 0 0);
		RotatableImages[NextRotatableImageIndex].UOffset = 0;
		RotatableImages[NextRotatableImageIndex].VOffset = 0;
	}
	else
	{
		RotatableImages[NextRotatableImageIndex] = new () classClass'TexRotator';
		RotatableImages[NextRotatableImageIndex].Material = None;
		RotatableImages[NextRotatableImageIndex].TexRotationType = 0;
		RotatableImages[NextRotatableImageIndex].Rotation = rot(0 0 0);
		RotatableImages[NextRotatableImageIndex].UOffset = 0;
		RotatableImages[NextRotatableImageIndex].VOffset = 0;
		RotatableImages[NextRotatableImageIndex].OscillationRate = rot(0 0 0);
		RotatableImages[NextRotatableImageIndex].OscillationAmplitude = rot(0 0 0);
		RotatableImages[NextRotatableImageIndex].OscillationPhase = rot(0 0 0);
	}
	Return RotatableImages[NextRotatableImageIndex++];
	*/
}
void UHUDRadar::Initialize()
{
	/*
	local int i;
	myPawn = Pawn(cFrame.cActor);
	if (myPawn != None)
	{
		myPRI = cFrame.cHUD.PlayerOwner.PlayerReplicationInfo;
	}
	myLevel = cFrame.cActor.Level;
	LoadMapImage();
	CalibrateImageToWorld();
	ReloadObjectives();
	for (i = 0; i < 4; i++)
	{
		RotatingHitIndicatorImage[i] = new () classClass'TexRotator';
		RotatingHitIndicatorImage[i].Material = HitIndicatorImage;
		RotatingHitIndicatorImage[i].TexRotationType = 0;
		RotatingHitIndicatorImage[i].Rotation.Pitch = 0;
		RotatingHitIndicatorImage[i].Rotation.Yaw = i * 16384 + 8192;
		RotatingHitIndicatorImage[i].Rotation.Roll = 0;
		RotatingHitIndicatorImage[i].UOffset = HitIndicatorImage.MaterialUSize() / 2;
		RotatingHitIndicatorImage[i].VOffset = HitIndicatorImage.MaterialVSize() / 2;
		RotatingHitIndicatorImage[i].OscillationRate = rot(0 0 0);
		RotatingHitIndicatorImage[i].OscillationAmplitude = rot(0 0 0);
		RotatingHitIndicatorImage[i].OscillationPhase = rot(0 0 0);
		ColorModifiedHitIndicatorImage[i] = new () classClass'ColorModifier';
		ColorModifiedHitIndicatorImage[i].Material = RotatingHitIndicatorImage[i];
		ColorModifiedHitIndicatorImage[i].Color.R = 255;
		ColorModifiedHitIndicatorImage[i].Color.G = 0;
		ColorModifiedHitIndicatorImage[i].Color.B = 0;
		ColorModifiedHitIndicatorImage[i].Color.A = 0;
		ColorModifiedHitIndicatorImage[i].RenderTwoSided = False;
		ColorModifiedHitIndicatorImage[i].AlphaBlend = False;
	}
	MyController = HumanController(cFrame.cHUD.PlayerOwner);
	if (MyController != None)
	{
		MyController.RadarSetZoom(myLevel.RadarZoomLevels[0]);
		DesiredViewScale = FClamp(MyController.RadarZoom, 1, 1000);
		PreBlendViewScale = FClamp(MyController.RadarZoom, 1, 1000);
	}
	bInitialized = true;
	*/
}
void UHUDRadar::CalibrateImageToWorld()
{
	/*
	MapOffset = myLevel.RadarMapOffset;
	MapSize = myLevel.RadarMapSize;
	*/
}
void UHUDRadar::LoadMapImage()
{
	/*
	local Material NewMapImage;
	local Combiner CombinedMapImage;
	local FinalBlend BlendedMapImage;
	if (myLevel.RadarMapImage != None)
	{
		NewMapImage = myLevel.RadarMapImage;
	}
	if (NewMapImage == None)
	{
		NewMapImage = Default.MapImage;
	}
	RotatingCompassImage = new () classClass'TexRotator';
	RotatingCompassImage.Material = CompassRotImage;
	RotatingCompassImage.TexRotationType = 0;
	RotatingCompassImage.Rotation = rot(0 0 0);
	RotatingCompassImage.UOffset = CompassRotImage.MaterialUSize() / 2;
	RotatingCompassImage.VOffset = CompassRotImage.MaterialVSize() / 2;
	RotatingCompassImage.OscillationRate = rot(0 0 0);
	RotatingCompassImage.OscillationAmplitude = rot(0 0 0);
	RotatingCompassImage.OscillationPhase = rot(0 0 0);
	ScalingMapImage = new () classClass'TexScaler';
	ScalingMapImage.Material = NewMapImage;
	ScalingMapImage.UScale = 1;
	ScalingMapImage.VScale = 1;
	ScalingMapImage.UOffset = 0;
	ScalingMapImage.VOffset = 0;
	RotatingMapImage = new () classClass'TexRotator';
	RotatingMapImage.Material = ScalingMapImage;
	RotatingMapImage.TexRotationType = 0;
	RotatingMapImage.Rotation = rot(0 0 0);
	RotatingMapImage.UOffset = ScalingMapImage.Material.MaterialUSize() / 2;
	RotatingMapImage.VOffset = ScalingMapImage.Material.MaterialVSize() / 2;
	RotatingMapImage.OscillationRate = rot(0 0 0);
	RotatingMapImage.OscillationAmplitude = rot(0 0 0);
	RotatingMapImage.OscillationPhase = rot(0 0 0);
	ScalingMaskImage = new () classClass'TexScaler';
	ScalingMaskImage.Material = MaskImage;
	ScalingMaskImage.UScale = 1;
	ScalingMaskImage.VScale = 1;
	ScalingMaskImage.UOffset = 0;
	ScalingMaskImage.VOffset = 0;
	CombinedMapImage = new () classClass'Combiner';
	CombinedMapImage.CombineOperation = 0;
	CombinedMapImage.AlphaOperation = 4;
	CombinedMapImage.Material1 = RotatingMapImage;
	CombinedMapImage.Material2 = ScalingMaskImage;
	CombinedMapImage.Mask = None;
	CombinedMapImage.InvertMask = False;
	CombinedMapImage.Modulate2X = False;
	CombinedMapImage.Modulate4X = False;
	BlendedMapImage = new () classClass'FinalBlend';
	BlendedMapImage.Material = CombinedMapImage;
	BlendedMapImage.FrameBufferBlending = 2;
	BlendedMapImage.ZWrite = true;
	BlendedMapImage.ZTest = true;
	BlendedMapImage.AlphaTest = False;
	BlendedMapImage.TwoSided = False;
	BlendedMapImage.AlphaRef = 0;
	MapImage = BlendedMapImage;
	*/
}
void UHUDRadar::ReloadObjectives()
{
	/*
	local AGP.AGP_Objective ObjIterator;
	ObjectiveList.remove(0, ObjectiveList.Length);
	ForEach cFrame.cActor.DynamicActors(Class'AGP_Objective', ObjIterator)
	{
		ObjectiveList[ObjectiveList.Length] = ObjIterator;
	}
	*/
}
void UHUDRadar::DoTick()
{
	/*
	local float DeltaTime;
	if (myLevel != None)
	{
		if (LastTickTime == 0)
		{
			LastTickTime = myLevel.TimeSeconds;
		}
		DeltaTime = myLevel.TimeSeconds - LastTickTime;
		if (!bEveryOtherTick)
		{
			LastTickTime = myLevel.TimeSeconds;
			Tick(DeltaTime);
		}
		bEveryOtherTick = !bEveryOtherTick;
	}
	else
	{
		LastTickTime = 0;
	}
	*/
}

void UHUDRadar::Tick(float DeltaTime)
{
	/*
	local int i;
	local TeamInfo MyTeam;
	local PlayerReplicationInfo TeammatePRI;
	local AGP.AGP_Pawn MyAGP_Pawn;
	local AGP.AGP_HUD MyAGP_HUD;
	local float ActualDesiredViewScale;
	myPawn = Pawn(cFrame.cActor);
	if (MyController == None)
	{
		Return;
	}
	if (!bInitialized || myPawn == None)
	{
		Return;
	}
	MyAGP_Pawn = AGP_Pawn(myPawn);
	if (MyAGP_Pawn == None && Vehicle(myPawn) != None)
	{
		MyAGP_Pawn = AGP_Pawn(Vehicle(myPawn).Driver);
	}
	if (MyAGP_Pawn != None)
	{
		for (i = 0; i < 4; i++)
		{
			if (MyAGP_Pawn.HitQuadrants[i] > 0)
			{
				MyAGP_Pawn.HitQuadrants[i] = FClamp(MyAGP_Pawn.HitQuadrants[i] - HitFadePerSecond * DeltaTime, 0, 1);
			}
			if (MyAGP_Pawn.FixedHitQuadrants[i] > 0)
			{
				MyAGP_Pawn.FixedHitQuadrants[i] = FClamp(MyAGP_Pawn.FixedHitQuadrants[i] - HitFadePerSecond * DeltaTime, 0, 1);
			}
			MyAGP_HUD = AGP_HUD(MyController.myHUD);
			if (MyAGP_HUD != None)
			{
				if (MyAGP_HUD.bRotateRadarAroundPlayer)
				{
					ColorModifiedHitIndicatorImage[i].Color.A = MyAGP_Pawn.HitQuadrants[i] * 255;
				}
				else
				{
					ColorModifiedHitIndicatorImage[i].Color.A = MyAGP_Pawn.FixedHitQuadrants[i] * 255;
				}
			}
		}
	}
	if (MyController.bFullsizeRadar)
	{
		if (FullSizeBlend < 1)
		{
			FullSizeBlend = FMin(FullSizeBlend + 3 - FullSizeBlend * 2 * BlendFadePerSecond * DeltaTime, 1);
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
			FullSizeBlend = FMax(FullSizeBlend - 1 + FullSizeBlend * 2 * BlendFadePerSecond * DeltaTime, 0);
			OneMinusFullSizeBlend = 1 - FullSizeBlend;
			bUpdateDrawPosition = true;
		}
		else
		{
			OneMinusFullSizeBlend = 1;
		}
	}
	if (myPRI.VehicleReplicationInfo != None)
	{
		if (myLevel.RadarZoomLevels.Length > 0)
		{
			if (myLevel.RadarZoomLevels[0] >= 1)
			{
				ActualDesiredViewScale = FClamp(myLevel.RadarMapSize / myLevel.RadarZoomLevels[0] * 52.200001, 1, 1000);
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
			PreBlendViewScale += Abs(ActualDesiredViewScale - LastStartViewScale) * 1 / ZoomTimeSeconds * DeltaTime;
			if (PreBlendViewScale > ActualDesiredViewScale)
			{
				PreBlendViewScale = ActualDesiredViewScale;
			}
		}
		else
		{
			PreBlendViewScale -= Abs(ActualDesiredViewScale - LastStartViewScale) * 1 / ZoomTimeSeconds * DeltaTime;
			if (PreBlendViewScale < ActualDesiredViewScale)
			{
				PreBlendViewScale = ActualDesiredViewScale;
			}
		}
		FClamp(PreBlendViewScale, 1, MaxZoomLevel);
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
			bSmoothFlashFading = False;
		}
	}
	BaseDrawScale = 0.32;
	MyTeam = myPRI.Team;
	if (MyTeam != None)
	{
		for (i = 0; i < MyTeam.NumRequestSlots; i++)
		{
			TeammatePRI = MyTeam.ActualList_Player[i];
			if (TeammatePRI != None)
			{
				if (TeammatePRI.bVisibleLastTick)
				{
					if (TeammatePRI.RadarDrawOpacity < 255)
					{
						TeammatePRI.RadarDrawOpacity = FMin(TeammatePRI.RadarDrawOpacity + PlayerFadePerSecond * DeltaTime, 255);
					}
				}
				else
				{
					if (TeammatePRI.RadarDrawOpacity > 0)
					{
						if (TeammatePRI.bDead || TeammatePRI.bOutOfLives)
						{
							TeammatePRI.RadarDrawOpacity = FMax(TeammatePRI.RadarDrawOpacity - DeadPlayerFadePerSecond * DeltaTime, 0);
						}
						else
						{
							TeammatePRI.RadarDrawOpacity = FMax(TeammatePRI.RadarDrawOpacity - PlayerFadePerSecond * DeltaTime, 0);
						}
					}
				}
			}
		}
	}
	else
	{
		if (myLevel.NetMode == 0)
		{
			myPRI.RadarDrawOpacity = 255;
		}
	}
	*/
}
void UHUDRadar::RefreshViewParameters()
{
	/*
	local AGP.AGP_HUD MyAGP_HUD;
	local FVector StartTrace;
	local Object.Rotator CameraRotation;
	local Actor TestActor;
	ViewCenter = WorldToMapCoords(myPawn.Location) * OneMinusFullSizeBlend;
	DesiredViewScale = FClamp(MyController.RadarZoom, 1, 1000);
	MyAGP_HUD = AGP_HUD(MyController.myHUD);
	if (MyAGP_HUD.bRotateRadarAroundPlayer)
	{
		RotatingCompassImage.Material = CompassRotImage;
		MyController.PlayerCalcView(TestActor, StartTrace, CameraRotation);
		ViewRotation.Yaw = Normalize(CameraRotation).Yaw * OneMinusFullSizeBlend + 16384;
	}
	else
	{
		RotatingCompassImage.Material = CompassImage;
		ViewRotation.Yaw = 16384;
	}
	if (MyAGP_HUD != None && MyAGP_HUD.RadarMaskIndex < MaskOpacities.Length && MaskOpacities[MyAGP_HUD.RadarMaskIndex] != MaskOpacity)
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
		DrawPosition.X = 130 * cFrame.fScaleX + cFrame.offset.X;
		DrawPosition.Y = 30 * cFrame.fScaleY + cFrame.offset.Y;
		DrawPosition.W = 540 * cFrame.fScaleX;
		DrawPosition.H = 540 * cFrame.fScaleY;
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
	/*
	local Material NewMapImage;
	local float DrawSize_Map;
	local float DrawOffset_Map;
	DrawSize_Map = ScalingMapImage.Material.MaterialUSize();
	DrawOffset_Map = DrawSize_Map / 2;
	ScalingMapImage.UScale = ViewScale;
	ScalingMapImage.VScale = ViewScale;
	ScalingMapImage.UOffset = ViewCenter.X * DrawOffset_Map + DrawSize_Map - DrawSize_Map / ViewScale / 2;
	ScalingMapImage.VOffset = ViewCenter.Y * DrawOffset_Map + DrawSize_Map - DrawSize_Map / ViewScale / 2;
	if (myPawn != None)
	{
		NewMapImage = Class'RadarImageVolume'.GetBestRadarImage(myPawn);
		if (NewMapImage == None)
		{
			if (myLevel.RadarMapImage != None)
			{
				NewMapImage = myLevel.RadarMapImage;
			}
			if (NewMapImage == None)
			{
				NewMapImage = Default.MapImage;
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
void UHUDRadar::WorldToMapCoords(FVector VectorInWorldCoords)
{
	/*
	local FVector Result;
	Result.X = VectorInWorldCoords.X - MapOffset.X / MapSize;
	Result.Y = VectorInWorldCoords.Y - MapOffset.Y / MapSize;
	Result.Z = VectorInWorldCoords.Z;
	Return Result;
	*/
}
void UHUDRadar::MapToScreenCoords(FVector VectorInMapCoords)
{
	/*
	local float PixelsPerMapCoordUnit;
	PixelsPerMapCoordUnit = DrawPosition.W * ViewScale / 2;
	VectorInMapCoords = ViewCenter - VectorInMapCoords;
	VectorInMapCoords *= PixelsPerMapCoordUnit;
	VectorInMapCoords = -VectorInMapCoords << Normalize(ViewRotation);
	VectorInMapCoords.X += DrawPosition.X + DrawPosition.W / 2;
	VectorInMapCoords.Y += DrawPosition.Y + DrawPosition.H / 2;
	Return VectorInMapCoords;
	*/
}
void UHUDRadar::CullRadarElement(FVector &DrawLoc, float &DrawScale)
{
	/*
	local FVector LocVector;
	local float DistanceFromCenter;
	local float NewDistanceFromCenter;
	if (DrawLoc == CenterOfRadarScreenCoords)
	{
		Return;
	}
	LocVector = DrawLoc - CenterOfRadarScreenCoords;
	DistanceFromCenter = VSize(LocVector);
	if (DistanceFromCenter > ScaledCullRadius || DrawLoc.X < DrawPosition.X || DrawLoc.X > DrawPosition.X + DrawPosition.W || DrawLoc.Y < DrawPosition.Y || DrawLoc.Y > DrawPosition.Y + DrawPosition.H)
	{
		if (MaskScale > 1)
		{
			DrawLoc = CenterOfRadarScreenCoords + Normal(LocVector) * ScaledCullRadius;
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
			DrawLoc = CenterOfRadarScreenCoords + Normal(LocVector) * ScaledCullRadius;
		}
		NewDistanceFromCenter = VSize(DrawLoc - CenterOfRadarScreenCoords);
		DrawScale = DrawScale * FMax(1 - DistanceFromCenter - NewDistanceFromCenter / NewDistanceFromCenter, 0.75);
	}
	*/
}
bool UHUDRadar::ShouldShowRadar()
{
	//Return myLevel.bShowRadarMap && !MyController.bHUDHideRadar && !MyController.GameReplicationInfo.bHUDHideRadar&& Class'RadarImageVolume'.ShouldDisableRadar(myPawn) == False;
	return true;      //FAKE   /ELiZ
}
void UHUDRadar::Draw(UCanvas* C)
{
	/*
	local TeamInfo MyTeam;
	local int MyTeamListID;
	if (!bInitialized)
	{
		Initialize();
		if (!bInitialized)
		{
			Return;
		}
	}
	BaseElementColor = GreenColor;
	NextRotatableImageIndex = 0;
	DoTick();
	myPawn = Pawn(cFrame.cActor);
	if (myPawn == None || myPawn.bIsDead)
	{
		Return;
	}
	MyController = HumanController(cFrame.cHUD.PlayerOwner);
	myPRI = cFrame.cHUD.PlayerOwner.PlayerReplicationInfo;
	if (MyController == None)
	{
		Return;
	}
	MyController.bRadarIsVisible = ShouldShowRadar();
	if (!MyController.bRadarIsVisible)
	{
		Return;
	}
	MySQLPRI = myPRI.GetSquadLeader();
	MyFTLPRI = myPRI.GetFTLeader();
	RefreshViewParameters();
	MyTeam = myPRI.Team;
	if (MyTeam != None)
	{
		for (MyTeamListID = 0; MyTeamListID < MyTeam.NumRequestSlots; MyTeamListID++)
		{
			if (MyTeam.ActualList_Player[MyTeamListID] == myPRI)
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
		myPRI.bVisibleLastTick = true;
		DrawPlayer(C, myPRI, 0, myPRI.LinkedTo & ~1 << MyTeamListID != 0);
	}
	DrawRadarFrame(C);
	DrawVehicleNames(C);
	DrawTeamNames(C);
	*/
}
void UHUDRadar::DrawRadarBG(UCanvas* C)
{
	/*
	C.SetPos(DrawPosition.X, DrawPosition.Y);
	C.SetDrawColor(255, 255, 255, 255);
	C.DrawTile(MapImage, DrawPosition.W, DrawPosition.H, 0, 0, MapImage.MaterialUSize(), MapImage.MaterialVSize());
	C.DrawColor = cFrame.cHUD.HUDColor;
	*/
}
void UHUDRadar::DrawTeam(UCanvas* C)
{
	/*
	local int i;
	local TeamInfo MyTeam;
	local PlayerReplicationInfo TeammatePRI;
	MyTeam = myPRI.Team;
	if (MyTeam == None)
	{
		Return;
	}
	if (myPRI.bCallForMedic)
	{
		for (i = 0; i < MyTeam.NumRequestSlots; i++)
		{
			TeammatePRI = MyTeam.ActualList_Player[i];
			if (TeammatePRI != None && TeammatePRI.bIsMedic)
			{
				if (ShouldDrawPlayer(TeammatePRI, i))
				{
					TeammatePRI.bVisibleLastTick = true;
					DrawPlayer(C, TeammatePRI, i, myPRI.LinkedTo & 1 << i != 0);
				}
				else
				{
					TeammatePRI.bVisibleLastTick = False;
					DrawPlayer(C, TeammatePRI, i, myPRI.LinkedTo & 1 << i != 0);
				}
			}
		}
	}
	for (i = 0; i < MyTeam.NumRequestSlots; i++)
	{
		TeammatePRI = MyTeam.ActualList_Player[i];
		if (TeammatePRI != None && TeammatePRI != myPRI && !myPRI.bCallForMedic && TeammatePRI.bIsMedic)
		{
			if (ShouldDrawPlayer(TeammatePRI, i))
			{
				TeammatePRI.bVisibleLastTick = true;
				DrawPlayer(C, TeammatePRI, i, myPRI.LinkedTo & 1 << i != 0);
			}
			else
			{
				TeammatePRI.bVisibleLastTick = False;
				DrawPlayer(C, TeammatePRI, i, myPRI.LinkedTo & 1 << i != 0);
			}
		}
	}
	*/
}
bool UHUDRadar::ShouldDrawPlayer(AAA2_PlayerState* PRI, int32 TeamListID)
{
	/*
	local TeamInfo MyTeam;
	local PlayerReplicationInfo FTLPRI;
	if (PRI.VehicleReplicationInfo != None)
	{
		Return False;
	}
	if (myLevel.NetMode == 0)
	{
		Return True;
	}
	if (PRI == myPRI)
	{
		Return True;
	}
	if (myPRI != None)
	{
		MyTeam = myPRI.Team;
	}
	if (MyTeam == None)
	{
		Return False;
	}
	if (PRI == None || PRI.bIsSpectator || PRI.bOnlySpectator || PRI.bWaitingPlayer || PRI.bDead || PRI.bOutOfLives)
	{
		Return False;
	}
	if (myPRI == MySQLPRI)
	{
		Return True;
	}
	if (myPRI.bCallForMedic && PRI.bIsMedic)
	{
		Return True;
	}
	if (PRI.bVIPPS)
	{
		Return True;
	}
	if (PRI.requiredClass == Class'ClassPrisoner')
	{
		Return True;
	}
	if (myPRI.bIsMedic && PRI.bCallForMedic)
	{
		Return True;
	}
	if (PRI != None)
	{
		FTLPRI = PRI.GetFTLeader();
	}
	if (PRI.FT == myPRI.FT && PRI.LinkedToFTLeader)
	{
		Return True;
	}
	if (myPRI.LinkedTo & 1 << TeamListID == 0)
	{
		if (PRI != MySQLPRI && PRI != MyFTLPRI)
		{
			if (myPRI != FTLPRI || PRI.FT != myPRI.FT)
			{
				if (!bShowFTLSiblings || myPRI != FTLPRI || PRI != FTLPRI)
				{
					Return False;
				}
			}
		}
	}
	*/
	return true;
}
void UHUDRadar::DrawPlayer(UCanvas* C, AAA2_PlayerState* PRI, int32 TeamListID, bool bLinkedTo)
{
	/*
	local FVector DrawLocation;
	local float PlayerDrawScale;
	local float NullDrawScale;
	local float DistanceZ;
	local TeamInfo MyTeam;
	local PlayerReplicationInfo FTLPRI;
	local FColor PlayerColor;
	local bool bDrawBleedingIcon;
	local bool bDrawMedicIcon;
	local bool bPlayerBlinked;
	local float DrawOffset_LinkedRingIcon;
	local float DrawSize_LinkedRingIcon;
	local float DrawScale_LinkedRingIcon;
	local TexRotator RotatableImage;
	local int HeightState;
	local FVector StartTrace;
	local Object.Rotator CameraRotation;
	local Actor TestActor;
	if (PRI == None || PRI.RadarDrawOpacity <= 0 && PRI.bDead || PRI.bOutOfLives)
	{
		Return;
	}
	if (myPRI != None)
	{
		MyTeam = myPRI.Team;
	}
	if (PRI != None && PRI.Team != None)
	{
		FTLPRI = PRI.GetFTLeader();
	}
	DrawLocation = WorldToMapCoords(PRI.GetPawnLocation());
	DrawLocation = MapToScreenCoords(DrawLocation);
	DrawLocation.Z = 0;
	NullDrawScale = 1;
	PlayerDrawScale = BaseDrawScale;
	if (PRI == MySQLPRI)
	{
		PlayerDrawScale *= 1.25;
	}
	PlayerColor = BaseElementColor;
	if (PRI == MySQLPRI && !myLevel.NetMode == 0 || PRI.Team == None)
	{
		PlayerColor = YellowColor;
	}
	PlayerColor.A = PRI.RadarDrawOpacity;
	bDrawMedicIcon = myPRI.bCallForMedic && PRI.bIsMedic && myPRI != PRI;
	bDrawBleedingIcon = myPRI.bIsMedic || PRI == myPRI && PRI.bCallForMedic;
	if (myPRI != MySQLPRI && PRI != MySQLPRI && PRI.FT != myPRI.FT)
	{
		PlayerColor.R /= 2;
		PlayerColor.G /= 2;
		PlayerColor.B /= 2;
	}
	if (bDrawMedicIcon || bDrawBleedingIcon)
	{
		CullRadarElement(DrawLocation, NullDrawScale);
	}
	else
	{
		CullRadarElement(DrawLocation, PlayerDrawScale);
	}
	if (PRI.bDead || PRI.bOutOfLives)
	{
		C.DrawColor = RedColor;
		C.DrawColor.A = PlayerColor.A;
		C.SetPos(DrawLocation.X - PlayerDrawScale * DrawOffset_DeadPlayerIcon, DrawLocation.Y - PlayerDrawScale * DrawOffset_DeadPlayerIcon);
		C.DrawTileScaled(DeadPlayerIcon, PlayerDrawScale * cFrame.fScaleX, PlayerDrawScale * cFrame.fScaleX);
		C.DrawColor = cFrame.cHUD.HUDColor;
		Return;
	}
	DrawOffset_LinkedRingIcon = PlayerDrawScale * LinkedRingIcon.MaterialUSize() / 2 + RingRadius * cFrame.fScaleX;
	DrawSize_LinkedRingIcon = PlayerDrawScale * LinkedRingIcon.MaterialUSize() + 2 * RingRadius * cFrame.fScaleX;
	DrawScale_LinkedRingIcon = cFrame.fScaleX * PlayerDrawScale + 2 * RingRadius / LinkedRingIcon.MaterialUSize();
	bPlayerBlinked = DrawPRIBlink(C, YellowColor, DrawLocation.X - DrawOffset_LinkedRingIcon, DrawLocation.Y - DrawOffset_LinkedRingIcon, DrawSize_LinkedRingIcon, DrawSize_LinkedRingIcon, PRI);
	if (PRI.RadarDrawOpacity <= 0)
	{
		Return;
	}
	if (myLevel.NetMode == 0 || PRI.Team == None)
	{
		GOTO JL0729;
	}
	if (bLinkedTo)
	{
		if (PRI.LinkedToSquadLeader || PRI == MySQLPRI)
		{
			C.DrawColor = SQLLinkedDrawColor;
		}
		else
		{
			if (PRI.LinkedToFTLeader || PRI == FTLPRI)
			{
				C.DrawColor = FTLinkedDrawColor;
			}
			else
			{
				if (PRI.LinkedTo & ~1 << TeamListID != 0)
				{
					C.DrawColor = LinkedDrawColor;
				}
				else
				{
					C.DrawColor = UnLinkedDrawColor;
				}
			}
		}
		if (C.DrawColor.A != 0)
		{
			C.DrawColor.A = PlayerColor.A;
		}
		C.SetPos(DrawLocation.X - DrawOffset_LinkedRingIcon, DrawLocation.Y - DrawOffset_LinkedRingIcon);
		C.DrawTileScaled(LinkedRingIcon, DrawScale_LinkedRingIcon, DrawScale_LinkedRingIcon);
	}
	else
	{
		if (PRI == MySQLPRI)
		{
			C.DrawColor = SQLLinkedDrawColor;
		}
		else
		{
			if (PRI == FTLPRI)
			{
				C.DrawColor = FTLinkedDrawColor;
			}
			else
			{
				C.DrawColor = UnLinkedDrawColor;
			}
		}
		if (C.DrawColor.A != 0)
		{
			C.DrawColor.A = PlayerColor.A;
		}
		C.SetPos(DrawLocation.X - DrawOffset_LinkedRingIcon, DrawLocation.Y - DrawOffset_LinkedRingIcon);
		C.DrawTileScaled(LinkedRingIcon, DrawScale_LinkedRingIcon, DrawScale_LinkedRingIcon);
	JL0729:
	}
	DistanceZ = myPRI.LocationZ - PRI.LocationZ;
	HeightState = 0;
	if (DistanceZ >= HeightToDrawArrow)
	{
		HeightState = 1;
	}
	else
	{
		if (DistanceZ <= -HeightToDrawArrow)
		{
			HeightState = 2;
		}
	}
	RotatableImage = GetRotatableImage();
	if (PRI == myPRI)
	{
		MyController.PlayerCalcView(TestActor, StartTrace, CameraRotation);
		RotatableImage.Rotation.Yaw = ViewRotation.Yaw - Normalize(CameraRotation).Yaw + 16384;
	}
	else
	{
		RotatableImage.Rotation.Yaw = ViewRotation.Yaw - PRI.GetPawnYaw() + 16384;
	}
	C.DrawColor = PlayerColor;
	if (bDrawBleedingIcon)
	{
		C.DrawColor.R = C.DrawColor.R * 1 - SmoothFlashBlend + RedColor.R * SmoothFlashBlend;
		C.DrawColor.G = C.DrawColor.G * 1 - SmoothFlashBlend + RedColor.G * SmoothFlashBlend;
		C.DrawColor.B = C.DrawColor.B * 1 - SmoothFlashBlend + RedColor.B * SmoothFlashBlend;
	}
	if (myLevel.NetMode == 0 || PRI.Team == None)
	{
		RotatableImage.Material = PlayerArrow;
		RotatableImage.UOffset = DrawOffset_PlayerArrow / cFrame.fScaleX;
		RotatableImage.VOffset = DrawOffset_PlayerArrow / cFrame.fScaleX;
		C.SetPos(DrawLocation.X - PlayerDrawScale * DrawOffset_PlayerArrow, DrawLocation.Y - PlayerDrawScale * DrawOffset_PlayerArrow);
		C.DrawTileScaled(RotatableImage, PlayerDrawScale * cFrame.fScaleX, PlayerDrawScale * cFrame.fScaleX);
	}
	else
	{
		if (PRI == MySQLPRI)
		{
			RotatableImage.Rotation.Yaw = ViewRotation.Yaw - PRI.GetPawnYaw() + 16384;
			RotatableImage.Material = SquadLeaderArrow;
			RotatableImage.UOffset = DrawOffset_SquadLeaderArrow / cFrame.fScaleX;
			RotatableImage.VOffset = DrawOffset_SquadLeaderArrow / cFrame.fScaleX;
			C.SetPos(DrawLocation.X - PlayerDrawScale * DrawOffset_SquadLeaderArrow, DrawLocation.Y - PlayerDrawScale * DrawOffset_SquadLeaderArrow);
			C.DrawTileScaled(RotatableImage, PlayerDrawScale * cFrame.fScaleX, PlayerDrawScale * cFrame.fScaleX);
		}
		else
		{
			RotatableImage.Material = PlayerArrow;
			RotatableImage.UOffset = DrawOffset_PlayerArrow / cFrame.fScaleX;
			RotatableImage.VOffset = DrawOffset_PlayerArrow / cFrame.fScaleX;
			C.SetPos(DrawLocation.X - PlayerDrawScale * DrawOffset_PlayerArrow, DrawLocation.Y - PlayerDrawScale * DrawOffset_PlayerArrow);
			C.DrawTileScaled(RotatableImage, PlayerDrawScale * cFrame.fScaleX, PlayerDrawScale * cFrame.fScaleX);
		}
	}
	C.DrawColor = PlayerColor;
	if (bDrawBleedingIcon)
	{
		C.DrawColor.R = C.DrawColor.R * 1 - SmoothFlashBlend + RedColor.R * SmoothFlashBlend;
		C.DrawColor.G = C.DrawColor.G * 1 - SmoothFlashBlend + RedColor.G * SmoothFlashBlend;
		C.DrawColor.B = C.DrawColor.B * 1 - SmoothFlashBlend + RedColor.B * SmoothFlashBlend;
	}
	if (myLevel.NetMode == 0 || PRI.Team == None)
	{
		C.SetPos(DrawLocation.X - PlayerDrawScale * DrawOffset_PlayerIcon, DrawLocation.Y - PlayerDrawScale * DrawOffset_PlayerIcon);
		C.DrawTileScaled(PlayerIcon, PlayerDrawScale * cFrame.fScaleX, PlayerDrawScale * cFrame.fScaleX);
	}
	else
	{
		if (HeightState > 0 && MyController.bRadarShowPlayerInfo && MyController.bRadarShowPlayerInfoElevation)
		{
			if (HeightState == 1)
			{
				C.SetPos(DrawLocation.X - PlayerDrawScale * DrawOffset_PlayerBelowIcon, DrawLocation.Y - PlayerDrawScale * DrawOffset_PlayerBelowIcon);
				C.DrawTileScaled(PlayerBelowIcon, PlayerDrawScale * cFrame.fScaleX, PlayerDrawScale * cFrame.fScaleX);
			}
			else
			{
				C.SetPos(DrawLocation.X - PlayerDrawScale * DrawOffset_PlayerAboveIcon, DrawLocation.Y - PlayerDrawScale * DrawOffset_PlayerAboveIcon);
				C.DrawTileScaled(PlayerAboveIcon, PlayerDrawScale * cFrame.fScaleX, PlayerDrawScale * cFrame.fScaleX);
			}
		}
		else
		{
			if (bDrawMedicIcon)
			{
				C.SetDrawColor(255, 255, 255, 255);
				C.SetPos(DrawLocation.X - PlayerDrawScale * DrawOffset_MedicIcon, DrawLocation.Y - PlayerDrawScale * DrawOffset_MedicIcon);
				C.DrawTileScaled(MedicIcon, PlayerDrawScale * cFrame.fScaleX, PlayerDrawScale * cFrame.fScaleX);
			}
			else
			{
				if (PRI.bVIPPS)
				{
					C.SetPos(DrawLocation.X - PlayerDrawScale * DrawOffset_VIPIcon, DrawLocation.Y - PlayerDrawScale * DrawOffset_VIPIcon);
					C.DrawTileScaled(VIPIcon, PlayerDrawScale * cFrame.fScaleX, PlayerDrawScale * cFrame.fScaleX);
				}
				else
				{
					if (PRI.requiredClass == Class'ClassPrisoner')
					{
						C.SetPos(DrawLocation.X - PlayerDrawScale * DrawOffset_POWIcon, DrawLocation.Y - PlayerDrawScale * DrawOffset_POWIcon);
						C.DrawTileScaled(POWIcon, PlayerDrawScale * cFrame.fScaleX, PlayerDrawScale * cFrame.fScaleX);
					}
					else
					{
						if (PRI == MySQLPRI)
						{
							C.SetPos(DrawLocation.X - PlayerDrawScale * DrawOffset_SquadLeaderIcon, DrawLocation.Y - PlayerDrawScale * DrawOffset_SquadLeaderIcon);
							C.DrawTileScaled(SquadLeaderIcon, PlayerDrawScale * cFrame.fScaleX, PlayerDrawScale * cFrame.fScaleX);
						}
						else
						{
							if (PRI == FTLPRI)
							{
								C.SetPos(DrawLocation.X - PlayerDrawScale * DrawOffset_LeaderIcon, DrawLocation.Y - PlayerDrawScale * DrawOffset_LeaderIcon);
								C.DrawTileScaled(LeaderIcon, PlayerDrawScale * cFrame.fScaleX, PlayerDrawScale * cFrame.fScaleX);
								C.SetPos(DrawLocation.X - PlayerDrawScale * DrawOffset_ObjectiveLetters, DrawLocation.Y - PlayerDrawScale * DrawOffset_ObjectiveLetters - FTLLetterOffsetY * cFrame.fScaleX);
								C.DrawTileScaled(ObjectiveLetters[PRI.FT], PlayerDrawScale * cFrame.fScaleX, PlayerDrawScale * cFrame.fScaleX);
							}
							else
							{
								if (PRI == myPRI)
								{
									C.SetPos(DrawLocation.X - PlayerDrawScale * DrawOffset_PlayerIcon, DrawLocation.Y - PlayerDrawScale * DrawOffset_PlayerIcon);
									C.DrawTileScaled(PlayerIcon, PlayerDrawScale * cFrame.fScaleX, PlayerDrawScale * cFrame.fScaleX);
								}
								else
								{
									C.SetPos(DrawLocation.X - PlayerDrawScale * DrawOffset_TeammateIcon, DrawLocation.Y - PlayerDrawScale * DrawOffset_TeammateIcon);
									C.DrawTileScaled(TeammateIcon, PlayerDrawScale * cFrame.fScaleX, PlayerDrawScale * cFrame.fScaleX);
								}
							}
						}
					}
				}
			}
		}
	}
	C.DrawColor = cFrame.cHUD.HUDColor;
	*/
}
bool UHUDRadar::DrawBlink(UCanvas* C, FColor BlinkColor, float PositionX, float PositionY, float SizeX, float SizeY, float StartTime, float EndTime)
{
	/*
	local float CurrentStartTime;
	local float CurrentEndTime;
	local float BlinkBlend;
	local float HalfOffsetX;
	local float HalfOffsetY;
	local byte DrawAlpha;
	if (!MyController.bShowRadarBlinking)
	{
		Return False;
	}
	EndTime = StartTime + EndTime - StartTime / BlinkDelaySeconds * BlinkDelaySeconds + BlinkDurationSeconds;
	if (myLevel.TimeSeconds >= EndTime)
	{
		Return False;
	}
	CurrentStartTime = StartTime;
	CurrentEndTime = StartTime + BlinkDurationSeconds;
	if (CurrentStartTime + BlinkDurationSeconds < EndTime)
	{
		if (myLevel.TimeSeconds >= CurrentStartTime && myLevel.TimeSeconds < CurrentEndTime)
		{
			BlinkBlend = myLevel.TimeSeconds - CurrentStartTime / CurrentEndTime - CurrentStartTime;
			HalfOffsetX = 10 * BlinkBlend;
			HalfOffsetY = 10 * BlinkBlend;
			DrawAlpha = 1 - BlinkBlend * 255;
			C.DrawColor = BlinkColor;
			C.DrawColor.A = DrawAlpha;
			C.SetPos(PositionX - HalfOffsetX, PositionY - HalfOffsetY);
			C.DrawTile(LinkedRingIcon, SizeX + 2 * HalfOffsetX, SizeY + 2 * HalfOffsetY, 0, 0, LinkedRingIcon.MaterialUSize(), LinkedRingIcon.MaterialVSize());
		}
		CurrentStartTime += BlinkDelaySeconds;
		CurrentEndTime += BlinkDelaySeconds;
	}
	C.DrawColor = cFrame.cHUD.HUDColor;
	*/
	return true;
}
void UHUDRadar::DrawPRIBlink(UCanvas* C, FColor BlinkColor, float PositionX, float PositionY, float SizeX, float SizeY, AAA2_PlayerState* PRI)
{
	/*
	if (!MyController.bShowRadarBlinking)
	{
		Return False;
	}
	if (PRI.RadarBlinkStartTime != PRI.LastRadarBlinkStartTime)
	{
		PRI.BlinkLatency = myLevel.TimeSeconds - PRI.RadarBlinkStartTime;
		PRI.LastRadarBlinkStartTime = PRI.RadarBlinkStartTime;
	}
	if (PRI.RadarBlinkEndTime != PRI.LastRadarBlinkEndTime)
	{
		PRI.LastRadarBlinkEndTime = PRI.RadarBlinkEndTime;
	}
	Return DrawBlink(C, BlinkColor, PositionX, PositionY, SizeX, SizeY, PRI.LastRadarBlinkStartTime + PRI.BlinkLatency, PRI.LastRadarBlinkEndTime + PRI.BlinkLatency);
	*/
}
void UHUDRadar::DrawObjectiveBlink(UCanvas* C, FColor BlinkColor, float PositionX, float PositionY, float SizeX, float SizeY, AAGP_Objective* obj)
{
	/*
	if (!MyController.bShowRadarBlinking)
	{
		Return False;
	}
	if (myPRI.Team.TeamIndex == 0)
	{
		if (obj.RadarBlinkStartTime != obj.LastRadarBlinkStartTime)
		{
			obj.BlinkLatency = myLevel.TimeSeconds - obj.RadarBlinkStartTime;
			obj.LastRadarBlinkStartTime = obj.RadarBlinkStartTime;
		}
		if (obj.RadarBlinkEndTime != obj.LastRadarBlinkEndTime)
		{
			obj.LastRadarBlinkEndTime = obj.RadarBlinkEndTime;
		}
		Return DrawBlink(C, BlinkColor, PositionX, PositionY, SizeX, SizeY, obj.LastRadarBlinkStartTime + obj.BlinkLatency, obj.LastRadarBlinkEndTime + obj.BlinkLatency);
	}
	else
	{
		if (myPRI.Team.TeamIndex == 1)
		{
			if (obj.RadarBlinkStartTime1 != obj.LastRadarBlinkStartTime)
			{
				obj.BlinkLatency = myLevel.TimeSeconds - obj.RadarBlinkStartTime1;
				obj.LastRadarBlinkStartTime = obj.RadarBlinkStartTime1;
			}
			if (obj.RadarBlinkEndTime1 != obj.LastRadarBlinkEndTime)
			{
				obj.LastRadarBlinkEndTime = obj.RadarBlinkEndTime1;
			}
			Return DrawBlink(C, BlinkColor, PositionX, PositionY, SizeX, SizeY, obj.LastRadarBlinkStartTime + obj.BlinkLatency, obj.LastRadarBlinkEndTime + obj.BlinkLatency);
		}
	}
	*/
}
void UHUDRadar::DrawObjectives(UCanvas* C)
{
	/*
	local int i;
	local FVector DrawLocation;
	local float DistanceZ;
	local TeamInfo MyTeam;
	local float ObjDrawScale;
	local bool bObjectiveBlinked;
	local bool bIsInstantWin;
	local float DrawOffset_LinkedRingIcon;
	local float DrawSize_LinkedRingIcon;
	local float DrawScale_LinkedRingIcon;
	local FColor ObjectiveColor;
	for (i = 0; i < ObjectiveList.Length; i++)
	{
		if (ObjectiveList[i].IsA('AGP_CoopESSObjective'))
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
				ObjDrawScale = FMin(BaseDrawScale * 1.5, 1);
				CullRadarElement(DrawLocation, ObjDrawScale);
				DrawOffset_LinkedRingIcon = ObjDrawScale * LinkedRingIcon.MaterialUSize() / 2 + RingRadius * cFrame.fScaleX;
				DrawSize_LinkedRingIcon = ObjDrawScale * LinkedRingIcon.MaterialUSize() + 2 * RingRadius * cFrame.fScaleX;
				DrawScale_LinkedRingIcon = cFrame.fScaleX * ObjDrawScale + 2 * RingRadius / LinkedRingIcon.MaterialUSize();
				MyTeam = myPRI.Team;
				if (MyTeam != None && ObjectiveList[i].IsSquadTarget(MyTeam.TeamIndex))
				{
					bObjectiveBlinked = DrawObjectiveBlink(C, YellowColor, DrawLocation.X - DrawOffset_LinkedRingIcon, DrawLocation.Y - DrawOffset_LinkedRingIcon, DrawSize_LinkedRingIcon, DrawSize_LinkedRingIcon, ObjectiveList[i]);
				}
				if (ObjectiveList[i].AccomplishedBy == 255)
				{
					ObjectiveColor = YellowColor;
				}
				else
				{
					if (MyTeam != None)
					{
						if (ObjectiveList[i].AccomplishedBy == MyTeam.TeamIndex)
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
				if (ObjectiveList[i].IsA('AGP_CoopESSObjective'))
				{
					ObjectiveColor = RedColor;
				}
				ObjectiveColor.A = 255;
				C.DrawColor = ObjectiveColor;
				DistanceZ = myPRI.LocationZ - ObjectiveList[i].GetCompassLocation().Z;
				if (DistanceZ >= HeightToDrawArrow)
				{
					if (bIsInstantWin)
					{
						C.SetPos(DrawLocation.X - ObjDrawScale * DrawOffset_PrimaryObjectiveBelowIcon, DrawLocation.Y - ObjDrawScale * DrawOffset_PrimaryObjectiveBelowIcon);
						C.DrawTileScaled(PrimaryObjectiveBelowIcon, ObjDrawScale * cFrame.fScaleX, ObjDrawScale * cFrame.fScaleX);
					}
					else
					{
						C.SetPos(DrawLocation.X - ObjDrawScale * DrawOffset_SecondaryObjectiveBelowIcon, DrawLocation.Y - ObjDrawScale * DrawOffset_SecondaryObjectiveBelowIcon);
						C.DrawTileScaled(SecondaryObjectiveBelowIcon, ObjDrawScale * cFrame.fScaleX, ObjDrawScale * cFrame.fScaleX);
					}
				}
				else
				{
					if (DistanceZ <= -HeightToDrawArrow)
					{
						if (bIsInstantWin)
						{
							C.SetPos(DrawLocation.X - ObjDrawScale * DrawOffset_PrimaryObjectiveAboveIcon, DrawLocation.Y - ObjDrawScale * DrawOffset_PrimaryObjectiveAboveIcon);
							C.DrawTileScaled(PrimaryObjectiveAboveIcon, ObjDrawScale * cFrame.fScaleX, ObjDrawScale * cFrame.fScaleX);
						}
						else
						{
							C.SetPos(DrawLocation.X - ObjDrawScale * DrawOffset_SecondaryObjectiveAboveIcon, DrawLocation.Y - ObjDrawScale * DrawOffset_SecondaryObjectiveAboveIcon);
							C.DrawTileScaled(SecondaryObjectiveAboveIcon, ObjDrawScale * cFrame.fScaleX, ObjDrawScale * cFrame.fScaleX);
						}
					}
				}
				if (ObjectiveList[i].IsA('AGP_CoopESSObjective'))
				{
					ObjDrawScale = FMin(BaseDrawScale, 1);
					C.SetPos(DrawLocation.X - ObjDrawScale * DrawOffset_PrimaryObjectiveIcon, DrawLocation.Y - ObjDrawScale * DrawOffset_PrimaryObjectiveIcon);
					C.DrawTileScaled(ESSIcon, ObjDrawScale * cFrame.fScaleX, ObjDrawScale * cFrame.fScaleX);
				}
				else
				{
					if (ObjectiveList[i].AccomplishedBy == 255)
					{
						if (bIsInstantWin)
						{
							C.SetPos(DrawLocation.X - ObjDrawScale * DrawOffset_PrimaryObjectiveIcon, DrawLocation.Y - ObjDrawScale * DrawOffset_PrimaryObjectiveIcon);
							C.DrawTileScaled(PrimaryObjectiveIcon, ObjDrawScale * cFrame.fScaleX, ObjDrawScale * cFrame.fScaleX);
						}
						else
						{
							C.SetPos(DrawLocation.X - ObjDrawScale * DrawOffset_SecondaryObjectiveIcon, DrawLocation.Y - ObjDrawScale * DrawOffset_SecondaryObjectiveIcon);
							C.DrawTileScaled(SecondaryObjectiveIcon, ObjDrawScale * cFrame.fScaleX, ObjDrawScale * cFrame.fScaleX);
						}
					}
					else
					{
						if (MyTeam != None)
						{
							if (ObjectiveList[i].AccomplishedBy == MyTeam.TeamIndex)
							{
								if (bIsInstantWin)
								{
									C.SetPos(DrawLocation.X - ObjDrawScale * DrawOffset_PrimaryObjectiveAccomplished, DrawLocation.Y - ObjDrawScale * DrawOffset_PrimaryObjectiveAccomplished);
									C.DrawTileScaled(PrimaryObjectiveAccomplished, ObjDrawScale * cFrame.fScaleX, ObjDrawScale * cFrame.fScaleX);
								}
								else
								{
									C.SetPos(DrawLocation.X - ObjDrawScale * DrawOffset_SecondaryObjectiveAccomplished, DrawLocation.Y - ObjDrawScale * DrawOffset_SecondaryObjectiveAccomplished);
									C.DrawTileScaled(SecondaryObjectiveAccomplished, ObjDrawScale * cFrame.fScaleX, ObjDrawScale * cFrame.fScaleX);
								}
							}
							else
							{
								if (bIsInstantWin)
								{
									C.SetPos(DrawLocation.X - ObjDrawScale * DrawOffset_PrimaryObjectiveFailed, DrawLocation.Y - ObjDrawScale * DrawOffset_PrimaryObjectiveFailed);
									C.DrawTileScaled(PrimaryObjectiveFailed, ObjDrawScale * cFrame.fScaleX, ObjDrawScale * cFrame.fScaleX);
								}
								else
								{
									C.SetPos(DrawLocation.X - ObjDrawScale * DrawOffset_SecondaryObjectiveFailed, DrawLocation.Y - ObjDrawScale * DrawOffset_SecondaryObjectiveFailed);
									C.DrawTileScaled(SecondaryObjectiveFailed, ObjDrawScale * cFrame.fScaleX, ObjDrawScale * cFrame.fScaleX);
								}
							}
						}
					}
				}
				if (ObjectiveList[i].HUDLetter < ObjectiveLetters.Length && !ObjectiveList[i].IsA('AGP_CoopESSObjective'))
				{
					C.SetPos(DrawLocation.X - ObjDrawScale * DrawOffset_ObjectiveLetters, DrawLocation.Y - ObjDrawScale * DrawOffset_ObjectiveLetters);
					C.DrawTileScaled(ObjectiveLetters[ObjectiveList[i].HUDLetter], ObjDrawScale * cFrame.fScaleX, ObjDrawScale * cFrame.fScaleX);
				}
				}
		}
	}
	C.DrawColor = cFrame.cHUD.HUDColor;
	*/
}
void UHUDRadar::DrawVehicleNames(UCanvas* C)
{
	/*
	local int i;
	local int V;
	local Font oldfont;
	local AGP.AGP_VehicleReplicationInfo VRI;
	local int PassengerCount;
	local PlayerReplicationInfo DriverPRI;
	local PlayerReplicationInfo GunnerPRI;
	local array<PlayerReplicationInfo> Passengers;
	local FVector DrawLocation;
	local float XL;
	local float YL;
	local float XPos;
	local float YPos;
	local float TotalNameHeight;
	local float VehicleDrawScale;
	if (!MyController.bRadarShowPlayerInfo && MyController.bRadarShowPlayerInfoNames || myLevel == None || myLevel.GRI == None)
	{
		Return;
	}
	oldfont = C.Font;
	cFrame.cHUD.UseSmallFont(C);
	C.DrawColor = cFrame.cHUD.HUDColor;
	C.DrawColor.A = 255;
	for (V = 0; V < myLevel.GRI.VRIArray.Length; V++)
	{
		VRI = AGP_VehicleReplicationInfo(myLevel.GRI.VRIArray[V]);
		if (VRI != None && VRI.IsPlayerDriveable())
		{
			PassengerCount = VRI.GetPassengerCount();
			if (PassengerCount > 0)
			{
				Passengers = VRI.GetPassengers();
				DriverPRI = VRI.GetDriver();
				GunnerPRI = VRI.GetGunner();
				DrawLocation = WorldToMapCoords(VRI.GetVehiclePosition());
				DrawLocation = MapToScreenCoords(DrawLocation);
				DrawLocation.Z = 0;
				VehicleDrawScale = FMin(BaseDrawScale * 1.5, 1);
				CullRadarElement(DrawLocation, VehicleDrawScale);
				C.TextSize(Passengers[0].PlayerName, XL, YL);
				TotalNameHeight = YL * PassengerCount;
				XPos = DrawLocation.X + VehicleDrawScale * DrawOffset_VehicleIcon;
				YPos = DrawLocation.Y - TotalNameHeight / 2;
				if (DriverPRI != None)
				{
					C.SetPos(XPos, YPos);
					C.DrawText("(D)" @ DriverPRI.PlayerName);
					YPos += YL;
				}
				if (GunnerPRI != None)
				{
					C.SetPos(XPos, YPos);
					C.DrawText("(G)" @ GunnerPRI.PlayerName);
					YPos += YL;
				}
				for (i = 0; i < PassengerCount; i++)
				{
					if (Passengers[i] != DriverPRI && Passengers[i] != GunnerPRI)
					{
						C.SetPos(XPos, YPos);
						C.DrawText(Passengers[i].PlayerName);
						YPos += YL;
					}
				}
			}
		}
	}
	C.Font = oldfont;
	C.DrawColor = cFrame.cHUD.HUDColor;
	*/
}
void UHUDRadar::DrawVehicles(UCanvas* C)
{
	/*
	local int V;
	local AGP.AGP_VehicleReplicationInfo VRI;
	if (myLevel != None && myLevel.GRI != None)
	{
		for (V = 0; V < myLevel.GRI.VRIArray.Length; V++)
		{
			VRI = AGP_VehicleReplicationInfo(myLevel.GRI.VRIArray[V]);
			if (VRI != None && VRI.IsPlayerDriveable())
			{
				DrawVehicle(C, VRI.GetVehiclePosition(), VRI.GetVehicleRotation().Yaw, VRI.GetVehicleNumber(), VRI.IsVehicleDisabled());
			}
		}
	}
	*/
}
void UHUDRadar::DrawVehicle(UCanvas* C, FVector vLocation, float VYaw, int32 VehicleNumber, bool bIsDead)
{
	/*
	local float VehicleDrawScale;
	local FVector DrawLocation;
	local TexRotator MyRotatingTexture;
	DrawLocation = WorldToMapCoords(vLocation);
	DrawLocation = MapToScreenCoords(DrawLocation);
	DrawLocation.Z = 0;
	VehicleDrawScale = FMin(BaseDrawScale * 1.5, 1);
	CullRadarElement(DrawLocation, VehicleDrawScale);
	MyRotatingTexture[0] = GetRotatableImage();
	MyRotatingTexture[1] = GetRotatableImage();
	MyRotatingTexture[0].Rotation.Yaw = ViewRotation.Yaw - VYaw + 16384;
	MyRotatingTexture[0].Material = VehicleIcon;
	MyRotatingTexture[0].UOffset = DrawOffset_VehicleIcon / cFrame.fScaleX;
	MyRotatingTexture[0].VOffset = DrawOffset_VehicleIcon / cFrame.fScaleX;
	if (!bIsDead)
	{
		C.DrawColor = BaseElementColor;
	}
	else
	{
		C.DrawColor = RedColor;
	}
	C.DrawColor.A = 255;
	C.SetPos(DrawLocation.X - VehicleDrawScale * DrawOffset_VehicleIcon, DrawLocation.Y - VehicleDrawScale * DrawOffset_VehicleIcon);
	C.DrawTileScaled(MyRotatingTexture[0], VehicleDrawScale * cFrame.fScaleX, VehicleDrawScale * cFrame.fScaleX);
	if (!bIsDead && VehicleNumber >= 0)
	{
		MyRotatingTexture[1].Rotation.Yaw = ViewRotation.Yaw - VYaw + 16384;
		MyRotatingTexture[1].Material = ObjectiveNumbers[VehicleNumber];
		MyRotatingTexture[1].UOffset = DrawOffset_ObjectiveNumbers / cFrame.fScaleX;
		MyRotatingTexture[1].VOffset = DrawOffset_ObjectiveNumbers / cFrame.fScaleX;
		C.DrawColor = BaseElementColor;
		C.DrawColor.A = 255;
		C.SetPos(DrawLocation.X - VehicleDrawScale * DrawOffset_ObjectiveNumbers, DrawLocation.Y - VehicleDrawScale * DrawOffset_ObjectiveNumbers);
		C.DrawTileScaled(MyRotatingTexture[1], VehicleDrawScale * cFrame.fScaleX, VehicleDrawScale * cFrame.fScaleX);
	}
	C.DrawColor = cFrame.cHUD.HUDColor;
	*/
}
void UHUDRadar::DrawEnemies(UCanvas* C)
{
	/*
	local int i;
	local HumanController.EnemySpottedData EnemySpotted;
	local FVector DrawLocation;
	local float EnemyDrawScale;
	local float FadeOutBlend;
	MyController.ClearOldEnemiesSpotted();
	for (i = 0; i < MyController.EnemiesSpotted.Length; i++)
	{
		EnemySpotted = MyController.EnemiesSpotted[i];
		DrawLocation = WorldToMapCoords(EnemySpotted.SpottedLocation);
		DrawLocation = MapToScreenCoords(DrawLocation);
		DrawLocation.Z = 0;
		EnemyDrawScale = FMin(BaseDrawScale, 1);
		CullRadarElement(DrawLocation, EnemyDrawScale);
		FadeOutBlend = 1 - myLevel.TimeSeconds - EnemySpotted.TimeSpottedSeconds / EnemySpotted.LifeSpan;
		FadeOutBlend = FClamp(FadeOutBlend * 2, 0, 1);
		DrawBlink(C, RedColor, DrawLocation.X - DrawOffset_EnemyIcon * EnemyDrawScale, DrawLocation.Y - DrawOffset_EnemyIcon * EnemyDrawScale, EnemyIcon.MaterialUSize() * EnemyDrawScale * cFrame.fScaleX, EnemyIcon.MaterialVSize() * EnemyDrawScale * cFrame.fScaleX, EnemySpotted.BlinkStartTime, EnemySpotted.BlinkEndTime);
		C.DrawColor = RedColor;
		C.DrawColor.A = FadeOutBlend * 255;
		C.SetPos(DrawLocation.X - EnemyDrawScale * DrawOffset_EnemyIcon, DrawLocation.Y - EnemyDrawScale * DrawOffset_EnemyIcon);
		C.DrawTileScaled(EnemyIcon, EnemyDrawScale * cFrame.fScaleX, EnemyDrawScale * cFrame.fScaleX);
	}
	C.DrawColor = cFrame.cHUD.HUDColor;
	*/
}
void UHUDRadar::DrawSpottedESS(UCanvas* C)
{
	/*
	local int i;
	local HumanController.ESSObjectData ESSObjectSpotted;
	local FVector DrawLocation;
	local float IconDrawScale;
	local float FadeOutBlend;
	local FColor cLethality;
	MyController.ClearOldNonLethalESSSpotted();
	for (i = 0; i < MyController.FoundESSObject.Length; i++)
	{
		ESSObjectSpotted = MyController.FoundESSObject[i];
		DrawLocation = WorldToMapCoords(ESSObjectSpotted.SpottedLocation);
		DrawLocation = MapToScreenCoords(DrawLocation);
		DrawLocation.Z = 0;
		IconDrawScale = FMin(BaseDrawScale, 1);
		CullRadarElement(DrawLocation, IconDrawScale);
		if (!ESSObjectSpotted.bLethal)
		{
			FadeOutBlend = 1 - myLevel.TimeSeconds - ESSObjectSpotted.TimeSpottedSeconds / ESSObjectSpotted.LifeSpan;
			FadeOutBlend = FClamp(FadeOutBlend * 2, 0, 1);
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
		DrawBlink(C, cLethality, DrawLocation.X - DrawOffset_ESSIcon * IconDrawScale, DrawLocation.Y - DrawOffset_ESSIcon * IconDrawScale, ESSIcon.MaterialUSize() * IconDrawScale * cFrame.fScaleX + 5, ESSIcon.MaterialVSize() * IconDrawScale * cFrame.fScaleX + 5, ESSObjectSpotted.BlinkStartTime, ESSObjectSpotted.BlinkEndTime);
		C.DrawColor = cLethality;
		C.DrawColor.A = FadeOutBlend * 255;
		C.SetPos(DrawLocation.X - IconDrawScale * DrawOffset_ESSIcon, DrawLocation.Y - IconDrawScale * DrawOffset_ESSIcon);
		C.DrawTileScaled(ESSIcon, IconDrawScale * cFrame.fScaleX, IconDrawScale * cFrame.fScaleX);
	}
	C.DrawColor = cFrame.cHUD.HUDColor;
	*/
}
void UHUDRadar::DrawHitIndicator(UCanvas* C)
{
	/*
	local int i;
	local byte HitOpacity;
	HitOpacity = MaskOpacity * OneMinusFullSizeBlend;
	C.SetDrawColor(255, 255, 255, HitOpacity);
	C.DrawColor.A = HitOpacity;
	for (i = 0; i < 4; i++)
	{
		if (ColorModifiedHitIndicatorImage[i].Color.A > 0)
		{
			C.SetPos(DrawPosition.X, DrawPosition.Y);
			C.DrawTile(ColorModifiedHitIndicatorImage[i], DrawPosition.W, DrawPosition.H, 0, 0, ColorModifiedHitIndicatorImage[i].Material.MaterialUSize(), ColorModifiedHitIndicatorImage[i].Material.MaterialUSize());
		}
	}
	C.DrawColor = cFrame.cHUD.HUDColor;
	*/
}
void UHUDRadar::DrawRadarFrame(UCanvas* C)
{
	/*
	local int AlphaValue;
	AlphaValue = FMax(0, MaskOpacity * OneMinusFullSizeBlend * OneMinusFullSizeBlend * OneMinusFullSizeBlend);
	if (AlphaValue <= 0)
	{
		Return;
	}
	C.DrawColor = cFrame.cHUD.HUDColor;
	C.DrawColor.A = AlphaValue;
	C.SetPos(DrawPosition.X - DrawPosition.W * CompassScaleOffset / 2, DrawPosition.Y - DrawPosition.H * CompassScaleOffset / 2);
	C.DrawTile(RotatingCompassImage, DrawPosition.W * 1 + CompassScaleOffset, DrawPosition.H * 1 + CompassScaleOffset, 0, 0, RotatingCompassImage.Material.MaterialUSize(), RotatingCompassImage.Material.MaterialVSize());
	C.DrawColor = cFrame.cHUD.HUDColor;
	*/
}
void UHUDRadar::DrawTeamNames(UCanvas* C)
{
	/*
	local int i;
	local TeamInfo MyTeam;
	local PlayerReplicationInfo TeammatePRI;
	MyTeam = myPRI.Team;
	if (MyTeam == None)
	{
		Return;
	}
	if (!MyController.bRadarShowPlayerInfo && MyController.bRadarShowPlayerInfoNames)
	{
		Return;
	}
	for (i = 0; i < MyTeam.NumRequestSlots; i++)
	{
		TeammatePRI = MyTeam.ActualList_Player[i];
		if (TeammatePRI != None && TeammatePRI != myPRI)
		{
			if (ShouldDrawPlayer(TeammatePRI, i))
			{
				DrawPlayerName(C, TeammatePRI, i, myPRI.LinkedTo & 1 << i != 0);
			}
			else
			{
				DrawPlayerName(C, TeammatePRI, i, myPRI.LinkedTo & 1 << i != 0);
			}
		}
	}
	*/
}
void UHUDRadar::DrawPlayerName(UCanvas* C, AAA2_PlayerState* PRI, int32 TeamListID, bool bLinkedTo)
{
	/*
	local FVector DrawLocation;
	local float TextDrawScale;
	local PlayerReplicationInfo FTLPRI;
	local FColor PlayerColor;
	local bool bDrawBleedingIcon;
	local Font oldfont;
	local float XL;
	local float YL;
	if (!MyController.bRadarShowPlayerInfo && MyController.bRadarShowPlayerInfoNames)
	{
		Return;
	}
	if (PRI != None && PRI.Team != None)
	{
		FTLPRI = PRI.GetFTLeader();
	}
	DrawLocation = WorldToMapCoords(PRI.GetPawnLocation());
	DrawLocation = MapToScreenCoords(DrawLocation);
	DrawLocation.Z = 0;
	TextDrawScale = BaseDrawScale;
	PlayerColor = cFrame.cHUD.HUDColor;
	PlayerColor.A = PRI.RadarDrawOpacity;
	CullRadarElement(DrawLocation, TextDrawScale);
	bDrawBleedingIcon = myPRI.bIsMedic && PRI.bCallForMedic;
	C.DrawColor = PlayerColor;
	oldfont = C.Font;
	cFrame.cHUD.UseSmallFont(C);
	C.TextSize(PRI.PlayerName, XL, YL);
	C.SetPos(DrawLocation.X + TextDrawScale * DrawOffset_PlayerIcon, DrawLocation.Y - YL / 2);
	C.DrawText(PRI.PlayerName);
	C.Font = oldfont;
	C.DrawColor = cFrame.cHUD.HUDColor;
	*/
}
