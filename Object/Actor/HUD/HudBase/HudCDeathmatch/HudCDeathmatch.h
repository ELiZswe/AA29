// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/HUD/HudBase/HudBase.h"
#include "AA29/AA29.h"
#include "HudCDeathmatch.generated.h"

class AWeapon;
class AAA2_PlayerState;
class ASceneManager;
class AGameReplicationInfo;
class AVoiceChatRoom;

UCLASS()
class AHudCDeathmatch : public AHudBase
{
	GENERATED_BODY()
public:
	AHudCDeathmatch(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere)		FDigitSet				DigitsBig;					//var() HudBase.DigitSet DigitsBig;
	UPROPERTY(EditAnywhere)		FDigitSet				DigitsBigPulse;				//var() HudBase.DigitSet DigitsBigPulse;
	UPROPERTY(EditAnywhere)		FSpriteWidget			AmmoIcon;					//var() HudBase.SpriteWidget AmmoIcon;
	UPROPERTY(EditAnywhere)		FNumericWidget			AdrenalineCount;			//var() HudBase.NumericWidget AdrenalineCount;
	UPROPERTY(EditAnywhere)		FNumericWidget			mySpread;					//var() HudBase.NumericWidget mySpread;
	UPROPERTY(EditAnywhere)		FNumericWidget			myRank;						//var() HudBase.NumericWidget myRank;
	UPROPERTY(EditAnywhere)		FNumericWidget			myScore;					//var() HudBase.NumericWidget myScore;
	UPROPERTY(EditAnywhere)		FNumericWidget			TimerHours;					//var() HudBase.NumericWidget TimerHours;
	UPROPERTY(EditAnywhere)		FNumericWidget			TimerMinutes;				//var() HudBase.NumericWidget TimerMinutes;
	UPROPERTY(EditAnywhere)		FNumericWidget			TimerSeconds;				//var() HudBase.NumericWidget TimerSeconds;
	UPROPERTY(EditAnywhere)		TArray<FSpriteWidget>	TimerDigitSpacer;			//var() HudBase.SpriteWidget TimerDigitSpacer[2];
	UPROPERTY(EditAnywhere)		FSpriteWidget			TimerIcon;					//var() HudBase.SpriteWidget TimerIcon;
	UPROPERTY(EditAnywhere)		FSpriteWidget			TimerBackground;			//var() HudBase.SpriteWidget TimerBackground;
	UPROPERTY(EditAnywhere)		FSpriteWidget			TimerBackgroundDisc;		//var() HudBase.SpriteWidget TimerBackgroundDisc;
	UPROPERTY(EditAnywhere)		UFont*					LevelActionFontFont;		//var() Font LevelActionFontFont;
	UPROPERTY(EditAnywhere)		FColor					LevelActionFontColor;		//var() Color LevelActionFontColor;
	UPROPERTY(EditAnywhere)		float					LevelActionPositionX;		//var() float LevelActionPositionX;
	UPROPERTY(EditAnywhere)		float					LevelActionPositionY;		//var() float LevelActionPositionY;
	UPROPERTY(EditAnywhere)		FNumericWidget			DigitsHealth;				//var() HudBase.NumericWidget DigitsHealth;
	UPROPERTY(EditAnywhere)		FNumericWidget			DigitsVehicleHealth;		//var() HudBase.NumericWidget DigitsVehicleHealth;
	UPROPERTY(EditAnywhere)		FNumericWidget			DigitsAmmo;					//var() HudBase.NumericWidget DigitsAmmo;
	UPROPERTY(EditAnywhere)		FNumericWidget			DigitsShield;				//var() HudBase.NumericWidget DigitsShield;
	UPROPERTY(EditAnywhere)		FNumericWidget			UDamageTime;				//var() HudBase.NumericWidget UDamageTime;
	UPROPERTY(EditAnywhere)		FSpriteWidget			UDamageIcon;				//var() HudBase.SpriteWidget UDamageIcon;
	UPROPERTY(EditAnywhere)		FSpriteWidget			AdrenalineIcon;				//var() HudBase.SpriteWidget AdrenalineIcon;
	UPROPERTY(EditAnywhere)		FSpriteWidget			AdrenalineBackground;		//var() HudBase.SpriteWidget AdrenalineBackground;
	UPROPERTY(EditAnywhere)		FSpriteWidget			AdrenalineBackgroundDisc;	//var() HudBase.SpriteWidget AdrenalineBackgroundDisc;
	UPROPERTY(EditAnywhere)		FSpriteWidget			AdrenalineAlert;			//var() HudBase.SpriteWidget AdrenalineAlert;
	UPROPERTY(EditAnywhere)		FSpriteWidget			MyScoreIcon;				//var() HudBase.SpriteWidget MyScoreIcon;
	UPROPERTY(EditAnywhere)		FSpriteWidget			MyScoreBackground;			//var() HudBase.SpriteWidget MyScoreBackground;
	UPROPERTY(EditAnywhere)		FSpriteWidget			HudHealthALERT;				//var() HudBase.SpriteWidget HudHealthALERT;
	UPROPERTY(EditAnywhere)		FSpriteWidget			HudVehicleHealthALERT;		//var() HudBase.SpriteWidget HudVehicleHealthALERT;
	UPROPERTY(EditAnywhere)		FSpriteWidget			HudAmmoALERT;				//var() HudBase.SpriteWidget HudAmmoALERT;
	UPROPERTY(EditAnywhere)		FSpriteWidget			HudBorderShield;			//var() HudBase.SpriteWidget HudBorderShield;
	UPROPERTY(EditAnywhere)		FSpriteWidget			HudBorderHealth;			//var() HudBase.SpriteWidget HudBorderHealth;
	UPROPERTY(EditAnywhere)		FSpriteWidget			HudBorderVehicleHealth;		//var() HudBase.SpriteWidget HudBorderVehicleHealth;
	UPROPERTY(EditAnywhere)		FSpriteWidget			HudBorderAmmo;				//var() HudBase.SpriteWidget HudBorderAmmo;
	UPROPERTY(EditAnywhere)		FSpriteWidget			HudBorderShieldIcon;		//var() HudBase.SpriteWidget HudBorderShieldIcon;
	UPROPERTY(EditAnywhere)		FSpriteWidget			HudBorderHealthIcon;		//var() HudBase.SpriteWidget HudBorderHealthIcon;
	UPROPERTY(EditAnywhere)		FSpriteWidget			HudBorderVehicleHealthIcon;	//var() HudBase.SpriteWidget HudBorderVehicleHealthIcon;
	UPROPERTY(EditAnywhere)		TArray<AWeapon*>		BaseWeapons;				//var() class<Weapon> BaseWeapons[9];
	UPROPERTY(EditAnywhere)		TArray<FSpriteWidget>	BarWeaponIcon;				//var() HudBase.SpriteWidget BarWeaponIcon[9];
	UPROPERTY(EditAnywhere)		TArray<FSpriteWidget>	BarAmmoIcon;				//var() HudBase.SpriteWidget BarAmmoIcon[9];
	UPROPERTY(EditAnywhere)		TArray<FSpriteWidget>	BarBorder;					//var() HudBase.SpriteWidget BarBorder[9];
	UPROPERTY(EditAnywhere)		TArray<FSpriteWidget>	BarBorderAmmoIndicator;		//var() HudBase.SpriteWidget BarBorderAmmoIndicator[9];
	UPROPERTY()					TArray<float>			BarBorderScaledPosition;	//var float BarBorderScaledPosition[9];
	UPROPERTY()					TArray<FWeaponState>	BarWeaponStates;			//var WeaponState BarWeaponStates[9];
	UPROPERTY(EditAnywhere)		int32					RechargeBar;				//var() HudBase.SpriteWidget RechargeBar;
	UPROPERTY()					bool					bDrawTimer;					//var bool bDrawTimer;
	UPROPERTY()					bool					TeamLinked;					//var bool TeamLinked;
	UPROPERTY(globalconfig)		int32					bShowMissingWeaponInfo;		//var globalconfig bool bShowMissingWeaponInfo;
	UPROPERTY()					int32					CurHealth;					//var int32 CurHealth;
	UPROPERTY()					int32					LastHealth;					//var int32 LastHealth;
	UPROPERTY()					int32					CurVehicleHealth;			//var int32 CurVehicleHealth;
	UPROPERTY()					int32					LastVehicleHealth;			//var int32 LastVehicleHealth;
	UPROPERTY()					int32					CurShield;					//var int32 CurShield;
	UPROPERTY()					int32					LastShield;					//var int32 LastShield;
	UPROPERTY()					int32					MaxShield;					//var int32 MaxShield;
	UPROPERTY()					int32					CurEnergy;					//var int32 CurEnergy;
	UPROPERTY()					int32					MaxEnergy;					//var int32 MaxEnergy;
	UPROPERTY()					int32					LastEnergy;					//var int32 LastEnergy;
	UPROPERTY()					float					LastDamagedHealth;			//var float LastDamagedHealth;
	UPROPERTY()					float					LastDamagedVehicleHealth;	//var float LastDamagedVehicleHealth;
	UPROPERTY()					float					ZoomToggleTime;				//var float ZoomToggleTime;
	UPROPERTY()					float					iSiFadeTimezeY;				//var float FadeTime;
	UPROPERTY(EditAnywhere)		float					MaxAmmoPrimary;				//var() float MaxAmmoPrimary;
	UPROPERTY(EditAnywhere)		float					CurAmmoPrimary;				//var() float CurAmmoPrimary;
	UPROPERTY(EditAnywhere)		float					LastAdrenalineTime;			//var() float LastAdrenalineTime;
	UPROPERTY()					int32					CurScore;					//var transient int32 CurScore;
	UPROPERTY()					int32					CurRank;					//var transient int32 CurRank;
	UPROPERTY()					int32					ScoreDiff;					//var transient int32 ScoreDiff;
	UPROPERTY()					int32					OldRemainingTime;			//var int32 OldRemainingTime;
	UPROPERTY()					TArray<FName>			CountDownName;				//var FName CountDownName[10];
	UPROPERTY()					TArray<FName>			LongCountName;				//var FName LongCountName[10];
	UPROPERTY(EditAnywhere)		TArray<int32>			BarWeaponIconAnim;			//var() int32 BarWeaponIconAnim[9];
	UPROPERTY(EditAnywhere)		FColor					HudColorRed;				//var() Color HudColorRed;
	UPROPERTY(EditAnywhere)		FColor					HudColorBlue;				//var() Color HudColorBlue;
	UPROPERTY(EditAnywhere)		FColor					HudColorBlack;				//var() Color HudColorBlack;
	UPROPERTY(EditAnywhere)		FColor					HudColorHighLight;			//var() Color HudColorHighLight;
	UPROPERTY(EditAnywhere)		FColor					HudColorNormal;				//var() Color HudColorNormal;
	UPROPERTY(EditAnywhere)		TArray<FColor>			HudColorTeam;				//var() Color HudColorTeam[2];
	UPROPERTY(globalconfig)		FColor					CustomHUDHighlightColor;	//var globalconfig Color CustomHUDHighlightColor;
	UPROPERTY()					AAA2_PlayerState*		NamedPlayer;				//var PlayerReplicationInfo NamedPlayer;
	UPROPERTY()					float					NameTime;					//var float NameTime;
	UPROPERTY()					UMaterialInstance*		Portrait;					//var Material Portrait;
	UPROPERTY()					float					PortraitTime;				//var float PortraitTime;
	UPROPERTY()					float					PortraitX;					//var float PortraitX;
	UPROPERTY()					TArray<ASceneManager*>	MySceneManagers;			//var TArray<SceneManager> MySceneManagers;
	UPROPERTY()					float					VehicleDrawTimer;			//var float VehicleDrawTimer;
	UPROPERTY()					APawn*					OldPawn;					//var Pawn OldPawn;
	UPROPERTY()					FString					VehicleName;				//var FString VehicleName;

	void GrowHUD();
	void ShrinkHUD();
	void UpdatePrecacheMaterials();
	void PostBeginPlay();
	bool CustomCrosshairsAllowed();
	bool CustomCrosshairColorAllowed();
	bool CustomHUDColorAllowed();
	void SetCustomCrosshairs();
	void SetCustomCrosshairColors();
	void SetCustomHUDColor();
	void CheckCountdown(AGameReplicationInfo* GRI);
	void Tick(float DeltaTime);
	void UpdateHUD();
	void DrawVehicleName(UCanvas* C);
	void DrawAdrenaline(UCanvas* C);
	void DrawTimer(UCanvas* C);
	void DrawUDamage(UCanvas* C);
	void UpdateRankAndSpread(UCanvas* C);
	void CalculateHealth();
	void CalculateShield();
	void CalculateEnergy();
	void CalculateAmmo();
	void CalculateScore();
	FString GetScoreText();
	FString GetScoreValue(AAA2_PlayerState* PRI);
	FString GetScoreTagLine();
	FColor GetTeamColor(uint8 TeamNum);
	bool IsInCinematic();
	void DrawSpectatingHud(UCanvas* C);
	FString GetInfoString();
	void DrawHUDAnimDigit(FNumericWidget& HUDPiece, float DefaultScale, float PickUPTime, float AnimTime, FColor DefaultColor, FColor colorHighlight);
	void DrawHUDAnimWidget(FSpriteWidget& HUDPiece, float DefaultScale, float PickUPTime, float AnimTime, float AnimScale);
	void DrawCrossHair(UCanvas* C);
	void DrawEnemyName(UCanvas* C);
	void DisplayEnemyName(UCanvas* C, AAA2_PlayerState* PRI);
	void FadeZoom();
	void ZoomFadeOut(UCanvas* C);
	void DisplayVoiceGain(UCanvas* C);
	void DrawHudPassA(UCanvas* C);
	void DrawHudPassC(UCanvas* C);
	void ShowReloadingPulse(float hold);
	void DrawChargeBar(UCanvas* C);
	void DrawVehicleChargeBar(UCanvas* C);
	void DrawWeaponBar(UCanvas* C);
	bool DrawLevelAction(UCanvas* C);
	void DisplayPortrait(AAA2_PlayerState* PRI);
	UFont* LoadLevelActionFont();
};
