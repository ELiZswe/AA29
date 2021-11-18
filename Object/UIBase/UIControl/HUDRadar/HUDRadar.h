// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "HUDRadar.generated.h"

class AHumanController;

/**
 * 
 */
UCLASS()
class AA29_API UHUDRadar : public UUIControl
{
	GENERATED_BODY()
public:
	UHUDRadar();

	UPROPERTY()										bool bEveryOtherTick;									//var bool bEveryOtherTick;
	UPROPERTY()										float LastTickTime;										//var float LastTickTime;
	UPROPERTY()										bool bShowFTLSiblings;									//var bool bShowFTLSiblings;
	UPROPERTY()										AAA2_PlayerState* MyFTLPRI;								//var PlayerReplicationInfo MyFTLPRI;
	UPROPERTY()										AAA2_PlayerState* MySQLPRI;								//var PlayerReplicationInfo MySQLPRI;
	UPROPERTY()										TArray<AAGP_Objective*> ObjectiveList;					//var array<AGP_Objective> ObjectiveList;
	UPROPERTY()										float DrawOffset_ESSIcon;								//var float DrawOffset_ESSIcon;
	UPROPERTY()										float DrawOffset_ObjectiveNumbers;						//var float DrawOffset_ObjectiveNumbers;
	UPROPERTY()										float DrawOffset_ObjectiveLetters;						//var float DrawOffset_ObjectiveLetters;
	UPROPERTY()										float DrawOffset_SecondaryObjectiveFailed;				//var float DrawOffset_SecondaryObjectiveFailed;
	UPROPERTY()										float DrawOffset_SecondaryObjectiveAccomplished;		//var float DrawOffset_SecondaryObjectiveAccomplished;
	UPROPERTY()										float DrawOffset_SecondaryObjectiveIcon;				//var float DrawOffset_SecondaryObjectiveIcon;
	UPROPERTY()										float DrawOffset_PrimaryObjectiveFailed;				//var float DrawOffset_PrimaryObjectiveFailed;
	UPROPERTY()										float DrawOffset_PrimaryObjectiveAccomplished;			//var float DrawOffset_PrimaryObjectiveAccomplished;
	UPROPERTY()										float DrawOffset_PrimaryObjectiveIcon;					//var float DrawOffset_PrimaryObjectiveIcon;
	UPROPERTY()										float DrawOffset_SecondaryObjectiveAboveIcon;			//var float DrawOffset_SecondaryObjectiveAboveIcon;
	UPROPERTY()										float DrawOffset_SecondaryObjectiveBelowIcon;			//var float DrawOffset_SecondaryObjectiveBelowIcon;
	UPROPERTY()										float DrawOffset_PrimaryObjectiveAboveIcon;				//var float DrawOffset_PrimaryObjectiveAboveIcon;
	UPROPERTY()										float DrawOffset_PrimaryObjectiveBelowIcon;				//var float DrawOffset_PrimaryObjectiveBelowIcon;
	UPROPERTY()										float DrawOffset_BleedingIcon;							//var float DrawOffset_BleedingIcon;
	UPROPERTY()										float DrawOffset_MedicIcon;								//var float DrawOffset_MedicIcon;
	UPROPERTY()										float DrawOffset_VehicleIcon;							//var float DrawOffset_VehicleIcon;
	UPROPERTY()										float DrawOffset_DeadEnemyIcon;							//var float DrawOffset_DeadEnemyIcon;
	UPROPERTY()										float DrawOffset_EnemyIcon;								//var float DrawOffset_EnemyIcon;
	UPROPERTY()										float DrawOffset_SquadLeaderArrow;						//var float DrawOffset_SquadLeaderArrow;
	UPROPERTY()										float DrawOffset_PlayerArrow;							//var float DrawOffset_PlayerArrow;
	UPROPERTY()										float DrawOffset_PlayerAboveIcon;						//var float DrawOffset_PlayerAboveIcon;
	UPROPERTY()										float DrawOffset_PlayerBelowIcon;						//var float DrawOffset_PlayerBelowIcon;
	UPROPERTY()										float DrawOffset_POWIcon;								//var float DrawOffset_POWIcon;
	UPROPERTY()										float DrawOffset_VIPIcon;								//var float DrawOffset_VIPIcon;
	UPROPERTY()										float DrawOffset_SquadLeaderIcon;						//var float DrawOffset_SquadLeaderIcon;
	UPROPERTY()										float DrawOffset_LeaderIcon;							//var float DrawOffset_LeaderIcon;
	UPROPERTY()										float DrawOffset_PlayerIcon;							//var float DrawOffset_PlayerIcon;
	UPROPERTY()										float DrawOffset_TeammateIcon;							//var float DrawOffset_TeammateIcon;
	UPROPERTY()										float DrawOffset_DeadPlayerIcon;						//var float DrawOffset_DeadPlayerIcon;
	UPROPERTY()										float DrawOffset_MaskImage;								//var float DrawOffset_MaskImage;
	UPROPERTY()										float DrawOffset_HitIndicatorImage;						//var float DrawOffset_HitIndicatorImage;
	UPROPERTY()										float DrawOffset_MapImage;								//var float DrawOffset_MapImage;
	UPROPERTY()										float DrawOffset_CompassRotImage;						//var float DrawOffset_CompassRotImage;
	UPROPERTY()										float DrawOffset_CompassImage;							//var float DrawOffset_CompassImage;
	UPROPERTY()										float MaxZoomLevel;										//var float MaxZoomLevel;
	UPROPERTY()										float CullRadius;										//var float CullRadius;
	UPROPERTY()										float HeightToDrawArrow;								//var float HeightToDrawArrow;
	UPROPERTY()										float SmoothFlashFadePerSecond;							//var float SmoothFlashFadePerSecond;
	UPROPERTY()										float DeadPlayerFadePerSecond;							//var float DeadPlayerFadePerSecond;
	UPROPERTY()										float PlayerFadePerSecond;								//var float PlayerFadePerSecond;
	UPROPERTY()										float ZoomTimeSeconds;									//var float ZoomTimeSeconds;
	UPROPERTY()										float BlendFadePerSecond;								//var float BlendFadePerSecond;
	UPROPERTY()										float HitFadePerSecond;									//var float HitFadePerSecond;
	UPROPERTY()										float CompassScaleOffset;								//var float CompassScaleOffset;
	UPROPERTY()										float RingRadius;										//var float RingRadius;
	UPROPERTY()										float BaseDrawScale;									//var float BaseDrawScale;
	UPROPERTY()										TArray<UMaterialInstance*> ObjectiveNumbers;			//var array<Material> ObjectiveNumbers;
	UPROPERTY()										TArray<UMaterialInstance*> ObjectiveLetters;			//var array<Material> ObjectiveLetters;
	UPROPERTY()										UMaterialInstance* ESSIcon;								//var Material ESSIcon;
	UPROPERTY()										UMaterialInstance* SecondaryObjectiveFailed;			//var Material SecondaryObjectiveFailed;
	UPROPERTY()										UMaterialInstance* SecondaryObjectiveAccomplished;		//var Material SecondaryObjectiveAccomplished;
	UPROPERTY()										UMaterialInstance* SecondaryObjectiveIcon;				//var Material SecondaryObjectiveIcon;
	UPROPERTY()										UMaterialInstance* PrimaryObjectiveFailed;				//var Material PrimaryObjectiveFailed;
	UPROPERTY()										UMaterialInstance* PrimaryObjectiveAccomplished;		//var Material PrimaryObjectiveAccomplished;
	UPROPERTY()										UMaterialInstance* PrimaryObjectiveIcon;				//var Material PrimaryObjectiveIcon;
	UPROPERTY()										UMaterialInstance* SecondaryObjectiveAboveIcon;			//var Material SecondaryObjectiveAboveIcon;
	UPROPERTY()										UMaterialInstance* SecondaryObjectiveBelowIcon;			//var Material SecondaryObjectiveBelowIcon;
	UPROPERTY()										UMaterialInstance* PrimaryObjectiveAboveIcon;			//var Material PrimaryObjectiveAboveIcon;
	UPROPERTY()										UMaterialInstance* PrimaryObjectiveBelowIcon;			//var Material PrimaryObjectiveBelowIcon;
	UPROPERTY()										UMaterialInstance* BleedingIcon;						//var Material BleedingIcon;
	UPROPERTY()										UMaterialInstance* MedicIcon;							//var Material MedicIcon;
	UPROPERTY()										UMaterialInstance* VehicleIcon;							//var Material VehicleIcon;
	UPROPERTY()										UMaterialInstance* DeadEnemyIcon;						//var Material DeadEnemyIcon;
	UPROPERTY()										UMaterialInstance* EnemyIcon;							//var Material EnemyIcon;
	UPROPERTY()										UMaterialInstance* SquadLeaderArrow;					//var Material SquadLeaderArrow;
	UPROPERTY()										UMaterialInstance* PlayerArrow;							//var Material PlayerArrow;
	UPROPERTY()										UMaterialInstance* PlayerAboveIcon;						//var Material PlayerAboveIcon;
	UPROPERTY()										UMaterialInstance* PlayerBelowIcon;						//var Material PlayerBelowIcon;
	UPROPERTY()										UMaterialInstance* POWIcon;								//var Material POWIcon;
	UPROPERTY()										UMaterialInstance* VIPIcon;								//var Material VIPIcon;
	UPROPERTY()										UMaterialInstance* SquadLeaderIcon;						//var Material SquadLeaderIcon;
	UPROPERTY()										UMaterialInstance* LeaderIcon;							//var Material LeaderIcon;
	UPROPERTY()										UMaterialInstance* PlayerIcon;							//var Material PlayerIcon;
	UPROPERTY()										UMaterialInstance* TeammateIcon;						//var Material TeammateIcon;
	UPROPERTY()										UMaterialInstance* DeadPlayerIcon;						//var Material DeadPlayerIcon;
	UPROPERTY()										UMaterialInstance* LinkedRingIcon;						//var Material LinkedRingIcon;
	UPROPERTY()										FColor UnLinkedDrawColor;								//var Object.Color UnLinkedDrawColor;
	UPROPERTY()										FColor LinkedDrawColor;									//var Object.Color LinkedDrawColor;
	UPROPERTY()										FColor FTLinkedDrawColor;								//var Object.Color FTLinkedDrawColor;
	UPROPERTY()										FColor SQLLinkedDrawColor;								//var Object.Color SQLLinkedDrawColor;
	UPROPERTY()										float ScaledCullRadius;									//var float ScaledCullRadius;
	UPROPERTY()										float MaskScale;										//var float MaskScale;
	UPROPERTY()										bool bUpdateDrawPosition;								//var bool bUpdateDrawPosition;
	UPROPERTY()										FPosition DrawPosition;									//var UIBase.Position DrawPosition;
	UPROPERTY()										FRotator ViewRotation;									//var Object.Rotator ViewRotation;
	UPROPERTY()										float LastStartViewScale;								//var float LastStartViewScale;
	UPROPERTY()										float LastDesiredViewScale;								//var float LastDesiredViewScale;
	UPROPERTY()										float ViewScale;										//var float ViewScale;
	UPROPERTY()										float PreBlendViewScale;								//var float PreBlendViewScale;
	UPROPERTY()										float DesiredViewScale;									//var float DesiredViewScale;
	UPROPERTY()										FVector CenterOfRadarScreenCoords;						//var Object.Vector CenterOfRadarScreenCoords;
	UPROPERTY()										FVector ViewCenter;										//var Object.Vector ViewCenter;
	UPROPERTY()										float MapSize;											//var float MapSize;
	UPROPERTY()										FVector MapOffset;										//var Object.Vector MapOffset;
	UPROPERTY()										FColor MedicColor;										//var Object.Color MedicColor;
	UPROPERTY()										FColor RedColor;										//var Object.Color RedColor;
	UPROPERTY()										FColor YellowColor;										//var Object.Color YellowColor;
	UPROPERTY()										FColor GreenColor;										//var Object.Color GreenColor;
	UPROPERTY()										FColor BaseElementColor;								//var Object.Color BaseElementColor;
	UPROPERTY()										float BlinkDelaySeconds;								//var float BlinkDelaySeconds;
	UPROPERTY()										float BlinkDurationSeconds;								//var float BlinkDurationSeconds;
	UPROPERTY()										bool bSmoothFlashFading;								//var bool bSmoothFlashFading;
	UPROPERTY()										float SmoothFlashBlend;									//var float SmoothFlashBlend;
	UPROPERTY()										float OneMinusFullSizeBlend;							//var float OneMinusFullSizeBlend;
	UPROPERTY()										float FullSizeBlend;									//var float FullSizeBlend;
	UPROPERTY()										float FTLLetterOffsetY;									//var float FTLLetterOffsetY;
	UPROPERTY()										bool bInitialized;										//var bool bInitialized;
	UPROPERTY()										TArray<int32> MaskOpacities;							//var array<int> MaskOpacities;
	UPROPERTY()										TArray<UMaterialInstance*> MaskImages;					//var array<Material> MaskImages;
	UPROPERTY()										int32 MaskOpacity;										//var int MaskOpacity;
	UPROPERTY()										UMaterialInstance* MaskImage;							//var Material MaskImage;
	UPROPERTY()										TArray<UMaterialInstance*> RotatableImages;				//var array<TexRotator> RotatableImages;
	UPROPERTY()										int32 NextRotatableImageIndex;							//var int NextRotatableImageIndex;
	UPROPERTY()										UMaterialInstance* ColorModifiedHitIndicatorImage;		//var ColorModifier ColorModifiedHitIndicatorImage;
	UPROPERTY()										UMaterialInstance* RotatingHitIndicatorImage;			//var TexRotator RotatingHitIndicatorImage;
	UPROPERTY()										UMaterialInstance* RotatingMapImage;					//var TexRotator RotatingMapImage;
	UPROPERTY()										UMaterialInstance* RotatingCompassImage;				//var TexRotator RotatingCompassImage;
	UPROPERTY()										UMaterialInstance* ScalingMaskImage;					//var TexScaler ScalingMaskImage;
	UPROPERTY()										UMaterialInstance* ScalingMapImage;						//var TexScaler ScalingMapImage;
	UPROPERTY()										UMaterialInstance* CompassRotImage;						//var Material CompassRotImage;
	UPROPERTY()										UMaterialInstance* CompassImage;						//var Material CompassImage;
	UPROPERTY()										UMaterialInstance* HitIndicatorImage;					//var Material HitIndicatorImage;
	UPROPERTY()										UMaterialInstance* MapImage;							//var Material MapImage;
	UPROPERTY()										AAA2_WorldSettings* myLevel;							//var LevelInfo myLevel;
	UPROPERTY()										APawn* myPawn;											//var Pawn myPawn;
	UPROPERTY()										AHumanController* MyController;							//var AGP.HumanController MyController;
	UPROPERTY()										AAA2_PlayerState* myPRI;								//var PlayerReplicationInfo myPRI;

	void StaticUpdatePrecacheMaterials(AAA2_WorldSettings* L);
	void Destroyed();
	void ScaleControl(UCanvas* Canvas);
	void GetRotatableImage();
	void Initialize();
	void CalibrateImageToWorld();
	void LoadMapImage();
	void ReloadObjectives();
	void DoTick();
	void Tick(float DeltaTime);
	void RefreshViewParameters();
	void UpdatePanValues();
	void WorldToMapCoords(FVector VectorInWorldCoords);
	void MapToScreenCoords(FVector VectorInMapCoords);
	void CullRadarElement(FVector& DrawLoc, float& DrawScale);
	bool ShouldShowRadar();
	void Draw(UCanvas* C);
	void DrawRadarBG(UCanvas* C);
	void DrawTeam(UCanvas* C);
	bool ShouldDrawPlayer(AAA2_PlayerState* PRI, int32 TeamListID);
	void DrawPlayer(UCanvas* C, AAA2_PlayerState* PRI, int32 TeamListID, bool bLinkedTo);
	bool DrawBlink(UCanvas* C, FColor BlinkColor, float PositionX, float PositionY, float SizeX, float SizeY, float StartTime, float EndTime);
	void DrawPRIBlink(UCanvas* C, FColor BlinkColor, float PositionX, float PositionY, float SizeX, float SizeY, AAA2_PlayerState* PRI);
	void DrawObjectiveBlink(UCanvas* C, FColor BlinkColor, float PositionX, float PositionY, float SizeX, float SizeY, AAGP_Objective* obj);
	void DrawObjectives(UCanvas* C);
	void DrawVehicleNames(UCanvas* C);
	void DrawVehicles(UCanvas* C);
	void DrawVehicle(UCanvas* C, FVector vLocation, float VYaw, int32 VehicleNumber, bool bIsDead);
	void DrawEnemies(UCanvas* C);
	void DrawSpottedESS(UCanvas* C);
	void DrawHitIndicator(UCanvas* C);
	void DrawRadarFrame(UCanvas* C);
	void DrawTeamNames(UCanvas* C);
	void DrawPlayerName(UCanvas* C, AAA2_PlayerState* PRI, int32 TeamListID, bool bLinkedTo);

};
