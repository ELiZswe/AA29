// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/HUD/HudBase/HudBase.h"
#include "HudBDeathMatch.generated.h"

class AWeapon;
class ASceneManager;
class AGameReplicationInfo;

UCLASS()
class AHudBDeathMatch : public AHudBase
{
	GENERATED_BODY()
public:
	AHudBDeathMatch(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere)		FDigitSet				DigitsBig;						//var() HudBase.DigitSet DigitsBig;
	UPROPERTY(EditAnywhere)		TArray<FSpriteWidget>	LHud1;							//var() HudBase.SpriteWidget LHud1[4];
	UPROPERTY(EditAnywhere)		TArray<FSpriteWidget>	LHud2;							//var() HudBase.SpriteWidget LHud2[4];
	UPROPERTY(EditAnywhere)		TArray<FSpriteWidget>	RHud1;							//var() HudBase.SpriteWidget RHud1[4];
	UPROPERTY(EditAnywhere)		TArray<FSpriteWidget>	RHud2;							//var() HudBase.SpriteWidget RHud2[4];
	UPROPERTY(EditAnywhere)		TArray<FSpriteWidget>	WeaponBarAmmoFill;				//var() HudBase.SpriteWidget WeaponBarAmmoFill[9];
	UPROPERTY(EditAnywhere)		TArray<FSpriteWidget>	WeaponBarTint;					//var() HudBase.SpriteWidget WeaponBarTint[9];
	UPROPERTY(EditAnywhere)		TArray<FSpriteWidget>	WeaponBarTrim;					//var() HudBase.SpriteWidget WeaponBarTrim[9];
	UPROPERTY(EditAnywhere)		TArray<FSpriteWidget>	WeaponBarIcon;					//var() HudBase.SpriteWidget WeaponBarIcon[9];
	UPROPERTY(EditAnywhere)		TArray<AWeapon*>		BaseWeapons;					//var() class<Weapon> BaseWeapons[9];
	UPROPERTY(EditAnywhere)		FSpriteWidget			AmmoIcon;						//var() HudBase.SpriteWidget AmmoIcon;
	UPROPERTY(EditAnywhere)		TArray<FSpriteWidget>	ScoreBg;						//var() HudBase.SpriteWidget ScoreBg[4];
	UPROPERTY(EditAnywhere)		TArray<FSpriteWidget>	Adrenaline;						//var() HudBase.SpriteWidget Adrenaline[5];
	UPROPERTY(EditAnywhere)		FSpriteWidget			HealthIcon;						//var() HudBase.SpriteWidget HealthIcon;
	UPROPERTY(EditAnywhere)		FNumericWidget			AdrenalineCount;				//var() HudBase.NumericWidget AdrenalineCount;
	UPROPERTY(EditAnywhere)		FNumericWidget			ComboCount;						//var() HudBase.NumericWidget ComboCount;
	UPROPERTY(EditAnywhere)		FNumericWidget			HealthCount;					//var() HudBase.NumericWidget HealthCount;
	UPROPERTY(EditAnywhere)		FNumericWidget			AmmoCount;						//var() HudBase.NumericWidget AmmoCount;
	UPROPERTY(EditAnywhere)		FNumericWidget			ShieldCount;					//var() HudBase.NumericWidget ShieldCount;
	UPROPERTY(EditAnywhere)		FNumericWidget			mySpread;						//var() HudBase.NumericWidget mySpread;
	UPROPERTY(EditAnywhere)		FNumericWidget			myRank;							//var() HudBase.NumericWidget myRank;
	UPROPERTY(EditAnywhere)		FNumericWidget			myScore;						//var() HudBase.NumericWidget myScore;
	UPROPERTY(EditAnywhere)		FSpriteWidget			ShieldIconGlow;					//var() HudBase.SpriteWidget ShieldIconGlow;
	UPROPERTY(EditAnywhere)		FSpriteWidget			ShieldIcon;						//var() HudBase.SpriteWidget ShieldIcon;
	UPROPERTY(EditAnywhere)		FSpriteWidget			AdrenalineIcon;					//var() HudBase.SpriteWidget AdrenalineIcon;
	UPROPERTY(EditAnywhere)		FSpriteWidget			ReloadingTeamTint;				//var() HudBase.SpriteWidget ReloadingTeamTint;
	UPROPERTY(EditAnywhere)		FSpriteWidget			ReloadingTrim;					//var() HudBase.SpriteWidget ReloadingTrim;
	UPROPERTY(EditAnywhere)		FSpriteWidget			ReloadingFill;					//var() HudBase.SpriteWidget ReloadingFill;
	UPROPERTY(EditAnywhere)		FSpriteWidget			UDamageTeamTint;				//var() HudBase.SpriteWidget UDamageTeamTint;
	UPROPERTY(EditAnywhere)		FSpriteWidget			UDamageTrim;					//var() HudBase.SpriteWidget UDamageTrim;
	UPROPERTY(EditAnywhere)		FSpriteWidget			UDamageFill;					//var() HudBase.SpriteWidget UDamageFill;
	UPROPERTY(EditAnywhere)		UFont*					LevelActionFontFont;			//var() Font LevelActionFontFont;
	UPROPERTY(EditAnywhere)		FColor					LevelActionFontColor;			//var() Color LevelActionFontColor;
	UPROPERTY(EditAnywhere)		float					LevelActionPositionX;			//var() float LevelActionPositionX;
	UPROPERTY(EditAnywhere)		float					LevelActionPositionY;			//var() float LevelActionPositionY;
	UPROPERTY(EditAnywhere)		float					CurrentWeaponPositionX;			//var() float CurrentWeaponPositionX;
	UPROPERTY(EditAnywhere)		float					CurrentWeaponPositionY;			//var() float CurrentWeaponPositionY;
	UPROPERTY(EditAnywhere)		UMaterialInstance*		LogoTexture;					//var() Texture LogoTexture;
	UPROPERTY(EditAnywhere)		float					LogoScaleX;						//var() float LogoScaleX;
	UPROPERTY(EditAnywhere)		float					LogoScaleY;						//var() float LogoScaleY;
	UPROPERTY(EditAnywhere)		float					LogoPosX;						//var() float LogoPosX;
	UPROPERTY(EditAnywhere)		float					LogoPosY;						//var() float LogoPosY;
	UPROPERTY(EditAnywhere)		float					testLerp;						//var() float testLerp;
	UPROPERTY(EditAnywhere)		float					comboTime;						//var() float comboTime;
	UPROPERTY(EditAnywhere)		TArray<float>			accumData;						//var() float accumData[4];
	UPROPERTY(EditAnywhere)		TArray<float>			growScale;						//var() float growScale[4];
	UPROPERTY(EditAnywhere)		TArray<float>			growTrace;						//var() float growTrace[4];
	UPROPERTY(EditAnywhere)		TArray<int32>			Pulse;							//var() int32 Pulse[5];
	UPROPERTY(EditAnywhere)		bool					ArmorGlow;						//var() bool ArmorGlow;
	UPROPERTY(EditAnywhere)		bool					Displaying;						//var() bool Displaying;
	UPROPERTY(EditAnywhere)		bool					Growing;						//var() bool Growing;
	UPROPERTY(EditAnywhere)		bool					LowHealthPulse;					//var() bool LowHealthPulse;
	UPROPERTY(EditAnywhere)		bool					TeamLinked;						//var() bool TeamLinked;
	UPROPERTY(EditAnywhere)		bool					AdrenalineReady;				//var() bool AdrenalineReady;
	UPROPERTY(EditAnywhere)		bool					bRealSmallWeaponBar;			//var bool bRealSmallWeaponBar;
	UPROPERTY(EditAnywhere)		float					OldHUDScale;					//var float OldHUDScale;
	UPROPERTY(EditAnywhere)		float					TransRechargeAmount;			//var() float TransRechargeAmount;
	UPROPERTY(EditAnywhere)		float					CurHealth;						//var transient float CurHealth;
	UPROPERTY(EditAnywhere)		float					LastHealth;						//var transient float LastHealth;
	UPROPERTY(EditAnywhere)		float					CurShield;						//var transient float CurShield;
	UPROPERTY(EditAnywhere)		float					LastShield;						//var transient float LastShield;
	UPROPERTY(EditAnywhere)		float					CurEnergy;						//var transient float CurEnergy;
	UPROPERTY(EditAnywhere)		float					CurAmmoPrimary;					//var transient float CurAmmoPrimary;
	UPROPERTY(EditAnywhere)		float					pulseHealthIcon;				//var transient float pulseHealthIcon;
	UPROPERTY(EditAnywhere)		float					pulseArmorIcon;					//var transient float pulseArmorIcon;
	UPROPERTY(EditAnywhere)		float					MaxShield;						//var transient float MaxShield;
	UPROPERTY(EditAnywhere)		float					MaxEnergy;						//var transient float MaxEnergy;
	UPROPERTY(EditAnywhere)		int32					MaxAmmoPrimary;					//var transient float MaxAmmoPrimary;
	UPROPERTY(EditAnywhere)		int32					CurScore;						//var transient int32 CurScore;
	UPROPERTY(EditAnywhere)		int32					CurRank;						//var transient int32 CurRank;
	UPROPERTY(EditAnywhere)		int32					ScoreDiff;						//var transient int32 ScoreDiff;
	UPROPERTY(EditAnywhere)		int32					OldRemainingTime;				//var int32 OldRemainingTime;
	UPROPERTY(EditAnywhere)		TArray<USoundBase*>		CountDown;						//var Sound CountDown[10];
	UPROPERTY(EditAnywhere)		TArray<USoundBase*>		LongCount;						//var Sound LongCount[6];
	UPROPERTY(EditAnywhere)		AAA2_PlayerState*		NamedPlayer;					//var PlayerReplicationInfo NamedPlayer;
	UPROPERTY(EditAnywhere)		float					NameTime;						//var float NameTime;
	UPROPERTY(EditAnywhere)		UMaterialInstance*		Portrait;						//var Material Portrait;
	UPROPERTY(EditAnywhere)		float					PortraitTime;					//var float PortraitTime;
	UPROPERTY(EditAnywhere)		float					PortraitX;						//var float PortraitX;
	UPROPERTY(EditAnywhere)		TArray<ASceneManager*>	MySceneManagers;				//var TArray<SceneManager> MySceneManagers;


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
	void pulseWidget(float DeltaTime, float Max, float Min, FSpriteWidget& Sprite, int32 tIndex, int32 PIndex, float pRate);
	void pulseNumber(int32 gIndex, FNumericWidget& number, float nScale, float growSpeed, float DeltaTime, float oScale, float test1, float test2, float first, float Last);
	void ArmorPulse(float DeltaTime, float Max, float Min, FSpriteWidget& Sprite, int32 tIndex, float pRate);
	void LowHealth(float DeltaTime, float Max, float Min, FSpriteWidget& Sprite, int32 tIndex, float pRate);
	void UpdateRankAndSpread(UCanvas* C);
	void CalculateHealth();
	void CalculateShield();
	void CalculateEnergy();
	void CalculateAmmo();
	void CalculateScore();
	FString GetScoreText();
	FString GetScoreValue(AAA2_PlayerState* PRI);
	FString GetScoreTagLine();
	void DrawSpectatingHud(UCanvas* C);
	FString GetInfoString();
	void DrawCrossHair(UCanvas* C);
	void DrawEnemyName(UCanvas* C);
	void DisplayEnemyName(UCanvas* C, AAA2_PlayerState* PRI);
	void SetSmallWeaponBar();
	void SetHUDScale();
	void DisplayVoiceGain(UCanvas* C);
	void DrawHudPassA(UCanvas* C);
	void ShowPointBarTop(UCanvas* C);
	void ShowPointBarBottom(UCanvas* C);
	void DrawHudPassC(UCanvas* C);
	void DrawWeaponBar(UCanvas* C);
	void UpdateHUD();
	bool DrawLevelAction(UCanvas* C);
	void DisplayPortrait(AAA2_PlayerState* PRI);
	void Message(AAA2_PlayerState* PRI, FString Msg, FName MsgType);
	UFont* LoadLevelActionFont();
};
