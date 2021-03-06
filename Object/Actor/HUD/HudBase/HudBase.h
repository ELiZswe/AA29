// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/HUD/AA2_HUD.h"
#include "AA29/MyEnums.h"
#include "HudBase.generated.h"

UCLASS(Config = Game)
class AHudBase : public AAA2_HUD
{
	GENERATED_BODY()
public:
	AHudBase(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere)		int32					TeamIndex;						//var() transient int32 TeamIndex;
	UPROPERTY(EditAnywhere)		ERenderStyle			PassStyle;						//var() transient Actor.ERenderStyle PassStyle;
	UPROPERTY(EditAnywhere)		TArray<FHudLocalizedMessage>	LocalMessages;					//var() transient HudLocalizedMessage LocalMessages[8];
	UPROPERTY(EditAnywhere)		AActor*					VoteMenuClass;					//var() class<Actor> VoteMenuClass;
	UPROPERTY()					UMaterialInstance*		TargetMaterial;					//var Material TargetMaterial;
	UPROPERTY()					bool					bShowTargeting;					//var transient bool bShowTargeting;
	UPROPERTY()					FVector					TargetingLocation;				//var transient Vector TargetingLocation;
	UPROPERTY()					float					TargetingSize;					//var transient float TargetingSize;
	UPROPERTY(EditAnywhere)		FString					InstructionText;				//var() FString InstructionText;
	UPROPERTY(EditAnywhere)		FString					InstructionKeyText;				//var() FString InstructionKeyText;
	UPROPERTY(EditAnywhere)		float					InstructTextBorderX;			//var() float InstructTextBorderX;
	UPROPERTY(EditAnywhere)		float					InstructTextBorderY;			//var() float InstructTextBorderY;
	UPROPERTY(EditAnywhere)		float					InstrDelta;						//var() float InstrDelta;
	UPROPERTY(EditAnywhere)		float					InstrRate;						//var() float InstrRate;
	UPROPERTY(EditAnywhere)		FString					InstructionFontName;			//var() localized FString InstructionFontName;
	UPROPERTY(EditAnywhere)		UFont*					InstructionFontFont;			//var() Font InstructionFontFont;
	UPROPERTY()					bool					bUsingCustomHUDColor;			//var bool bUsingCustomHUDColor;
	UPROPERTY(EditAnywhere)		bool					DoCropping;						//var() bool DoCropping;
	UPROPERTY()					bool					bIsCinematic;					//var bool bIsCinematic;
	UPROPERTY()					uint8					FontsPrecached;					//var uint8 FontsPrecached;
	UPROPERTY(globalconfig)		bool					bHideWeaponName;				//var globalconfig bool bHideWeaponName;
	UPROPERTY(EditAnywhere)		float					CroppingAmount;					//var() float CroppingAmount;
	UPROPERTY(EditAnywhere)		UMaterialInstance*		CroppingMaterial;				//var() Material CroppingMaterial;
	UPROPERTY()					FString					LastWeaponName;					//var FString LastWeaponName;
	UPROPERTY()					float					WeaponDrawTimer;				//var float WeaponDrawTimer;
	UPROPERTY()					FColor					WeaponDrawColor;				//var Color WeaponDrawColor;
	UPROPERTY(EditAnywhere)		FString					Text;							//var() localized FString Text;
	UPROPERTY(EditAnywhere)		FString					LevelActionLoading;				//var() localized FString LevelActionLoading;
	UPROPERTY(EditAnywhere)		FString					LevelActionPaused;				//var() localized FString LevelActionPaused;
	UPROPERTY(EditAnywhere)		FString					LevelActionFontName;			//var() localized FString LevelActionFontName;
	UPROPERTY()					FString					WonMatchPrefix;					//var localized FString WonMatchPrefix;
	UPROPERTY()					FString					WonMatchPostFix;				//var localized FString WonMatchPostFix;
	UPROPERTY()					FString					WaitingToSpawn;					//var localized FString WaitingToSpawn;
	UPROPERTY()					FString					AtMenus;						//var localized FString AtMenus;
	UPROPERTY()					FString					YouveWonTheMatch;				//var localized FString YouveWonTheMatch;
	UPROPERTY()					FString					YouveLostTheMatch;				//var localized FString YouveLostTheMatch;
	UPROPERTY()					FString					NowViewing;						//var localized FString NowViewing;
	UPROPERTY()					FString					ScoreText;						//var localized FString ScoreText;
	UPROPERTY()					FString					InitialViewingString;			//var localized FString InitialViewingString;
	UPROPERTY()					UMaterialInstance*		LocationDot;					//var Material LocationDot;
	UPROPERTY()					TArray<FColor>					DamageFlash;					//var Color DamageFlash[4];
	UPROPERTY()					TArray<float>					DamageTime;						//var float DamageTime[4];
	UPROPERTY(EditAnywhere)		TArray<uint8>					Emphasized;						//var() uint8 Emphasized[4];
	UPROPERTY(EditAnywhere)		TArray<FSpriteWidget>	Crosshairs;						//var() TArray<SpriteWidget> Crosshairs;
	UPROPERTY(globalconfig)		FColor					CustomHUDColor;					//var globalconfig Color CustomHUDColor;
	UPROPERTY(globalconfig)		bool					bUseCustomWeaponCrosshairs;		//var globalconfig bool bUseCustomWeaponCrosshairs;

	void UpdateHUD();
	void DrawHudPassA(UCanvas* C);
	void DrawHudPassB(UCanvas* C);
	void DrawHudPassC(UCanvas* C);
	void DrawHudPassD(UCanvas* C);
	void PrecacheFonts(UCanvas* C);
	void PostBeginPlay();
	bool CustomHUDColorAllowed();
	void SetCustomHUDColor();
	void DisplayHit(FVector HitDir, int32 Damage, UaDamageType* DamageType);
	void DrawDamageIndicators(UCanvas* C);
	void Tick(float DeltaTime);
	void DrawHeadShotSphere();
	void DrawHUD();
	void DrawSpriteWidget(UCanvas* C, FSpriteWidget& W);
	void DrawFNumericWidget(UCanvas* C, FNumericWidget& W, FDigitSet& D);
	void ClearMessage(FHudLocalizedMessage& M);
	void Message(AAA2_PlayerState* PRI, FString Msg, FName MsgType);
	void LocalizedMessage(ULocalMessage* Message, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString CriticalString);
	FColor GetTeamColor(uint8 TeamNum);
	void GetLocalStatsScreen();
	void LayoutMessage(FHudLocalizedMessage& Message, UCanvas* C);
	void GetScreenCoords(float PosX, float PosY, float& ScreenX, float& ScreenY, FHudLocalizedMessage& Message, UCanvas* C);
	void DrawMessage(UCanvas* C, int32 i, float PosX, float PosY, float& dx, float& dy);
	void DisplayLocalMessages(UCanvas* C);
	void CreateKeyMenus();
	void Draw2DLocationDot(UCanvas* C, FVector loc, float OffsetX, float OffsetY, float ScaleX, float ScaleY);
	void SetTargeting(bool bShow, FVector TargetLocation, float Size);
	void DrawTargeting(UCanvas* C);
	void SetCropping(bool Active);
	void DrawInstructionGfx(UCanvas* C);
	void DrawInstructionText(UCanvas* C);
	void DrawInstructionKeyText(UCanvas* C);
	void SetInstructionText(FString Text);
	void SetInstructionKeyText(FString Text);
	UFont* LoadInstructionFont();
	void DrawWeaponName(UCanvas* C);
	void DrawVehicleName(UCanvas* C);
	void DrawCinematicHUD(UCanvas* C);
	void DrawIntroSubtitles(UCanvas* C);
};
