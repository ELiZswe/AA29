// All the original content belonged to the US Army

#include "AA29/Object/Actor/HUD/HudBase/HudBDeathMatch/HudBDeathMatch.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"
#include "AA29/Object/Actor/Info/SceneManager/SceneManager.h"
#include "AA29/Object/CacheManager/CacheManager.h"
#include "Engine/Canvas.h"

AHudBDeathMatch::AHudBDeathMatch(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	LongCount.SetNum(6);
	CountDown.SetNum(10);
	Pulse.SetNum(5);
	growTrace.SetNum(4);
	growScale.SetNum(4);
	accumData.SetNum(4);
	Adrenaline.SetNum(5);
	ScoreBg.SetNum(4);
	BaseWeapons.SetNum(9);
	WeaponBarIcon.SetNum(9);
	WeaponBarTrim.SetNum(9);
	WeaponBarTint.SetNum(9);
	WeaponBarAmmoFill.SetNum(9);
	RHud2.SetNum(4);
	RHud1.SetNum(4);
	LHud2.SetNum(4);
	LHud1.SetNum(4);
	LevelActionFontColor = FColor(255, 255, 255, 255);
	LevelActionPositionX = 0.5;
	LevelActionPositionY = 0.25;
	CurrentWeaponPositionX = 0.845;
	CurrentWeaponPositionY = 0.9;
	LogoScaleX = 0.25;
	LogoScaleY = 0.25;
	LogoPosX = 0.49;
	LogoPosY = 0.15;
	OldHUDScale = 1;
	ConsoleMessagePosX = 0.005;
	ConsoleMessagePosY = 0.825;
}

static const int32 WEAPON_BAR_SIZE = 9;

void AHudBDeathMatch::UpdatePrecacheMaterials()
{
}

void AHudBDeathMatch::PostBeginPlay()
{
	ASceneManager* SM = nullptr;
	Super::PostBeginPlay();
	/*
	ForEach AllActors(ASceneManager::StaticClass(), SM)
	{
		MySceneManagers.Num() = (MySceneManagers.Num() + 1);
		MySceneManagers[(MySceneManagers.Num() - 1)] = SM;
	}
	if (CustomCrosshairsAllowed())
	{
		SetCustomCrosshairs();
	}
	*/
}

bool AHudBDeathMatch::CustomCrosshairsAllowed()
{
	return true;
}

bool AHudBDeathMatch::CustomCrosshairColorAllowed()
{
	return true;
}

bool AHudBDeathMatch::CustomHUDColorAllowed()
{
	return true;
}

void AHudBDeathMatch::SetCustomCrosshairs()
{
	int32 i = 0;
	TArray<FCrosshairRecord> CustomCrosshairs = {};
	//UCacheManager::StaticClass().GetCrosshairList(CustomCrosshairs);
	/*
	Crosshairs.Num() = CustomCrosshairs.Num();
	for (i = 0; i < CustomCrosshairs.Num(); i++)
	{
		Crosshairs[i]->WidgetTexture = CustomCrosshairs[i].CrosshairTexture;
		Crosshairs[i]->TextureCoords.X1 = 0;
		Crosshairs[i]->TextureCoords.X2 = 64;
		Crosshairs[i]->TextureCoords.Y1 = 0;
		Crosshairs[i]->TextureCoords.Y2 = 64;
		Crosshairs[i]->TextureScale = 0.75;
		Crosshairs[i]->DrawPivot = 8;
		Crosshairs[i]->PosX = 0.5;
		Crosshairs[i]->PosY = 0.5;
		Crosshairs[i]->OffsetX = 0;
		Crosshairs[i]->OffsetY = 0;
		Crosshairs[i]->ScaleMode = 0;
		Crosshairs[i]->Scale = 1;
		Crosshairs[i]->RenderStyle = 6;
	}
	*/
	if (CustomCrosshairColorAllowed())
	{
		SetCustomCrosshairColors();
	}
}

void AHudBDeathMatch::SetCustomCrosshairColors()
{
	int32 i = 0;
	int32 j = 0;
	/*
	for (i = 0; i < Crosshairs.Num(); i++)
	{
		for (j = 0; j < 2; j++)
		{
			Crosshairs[i].Tints[j] = CrossHairColor;
		}
	}
	*/
}

void AHudBDeathMatch::SetCustomHUDColor()
{
	int32 i = 0;
	int32 j = 0;
	/*
	if ((((CustomHUDColor.R == 0) && (CustomHUDColor.G == 0)) && (CustomHUDColor.B == 0)) && (CustomHUDColor.A == 0))
	{
		return;
	}
	bUsingCustomHUDColor = true;
	for (j = 0; j < 2; j++)
	{
		ReloadingTeamTint.Tints[j] = CustomHUDColor;
		UDamageTeamTint.Tints[j] = CustomHUDColor;
		for (i = 1; i < 3; i++)
		{
			LHud1[i].Tints[j] = CustomHUDColor;
			LHud2[i].Tints[j] = CustomHUDColor;
			RHud1[i].Tints[j] = CustomHUDColor;
			RHud2[i].Tints[j] = CustomHUDColor;
			Adrenaline[i].Tints[j] = CustomHUDColor;
			ScoreBg[i].Tints[j] = CustomHUDColor;
		}
		for (i = 0; i < 9; i++)
		{
			WeaponBarTint[i].Tints[j] = CustomHUDColor;
		}
	}
	*/
}

void AHudBDeathMatch::CheckCountdown(AGameReplicationInfo* GRI)
{
	/*
	if ((((GRI == nullptr) || (GRI.RemainingTime == 0)) || (GRI.RemainingTime == OldRemainingTime)) || (GRI.Winner != nullptr))
	{
		return;
	}
	OldRemainingTime = GRI.RemainingTime;
	if (OldRemainingTime > 300)
	{
		return;
	}
	if (OldRemainingTime > 30)
	{
		if (OldRemainingTime == 300)
		{
			PlayerOwner.PlayAnnouncement(LongCount[0], 1, true);
		}
		else
		{
			if (OldRemainingTime == 180)
			{
				PlayerOwner.PlayAnnouncement(LongCount[1], 1, true);
			}
			else
			{
				if (OldRemainingTime == 120)
				{
					PlayerOwner.PlayAnnouncement(LongCount[2], 1, true);
				}
				else
				{
					if (OldRemainingTime == 60)
					{
						PlayerOwner.PlayAnnouncement(LongCount[3], 1, true);
					}
				}
			}
		}
		return;
	}
	if (OldRemainingTime == 30)
	{
		PlayerOwner.PlayAnnouncement(LongCount[4], 1, true);
	}
	else
	{
		if (OldRemainingTime == 20)
		{
			PlayerOwner.PlayAnnouncement(LongCount[5], 1, true);
		}
		else
		{
			if ((OldRemainingTime <= 10) && (OldRemainingTime > 0))
			{
				PlayerOwner.PlayAnnouncement(CountDown[(OldRemainingTime - 1)], 1, true);
			}
		}
	}
	*/
}

void AHudBDeathMatch::Tick(float DeltaTime)
{
	/*
	UMaterialInstance* NewPortrait;
	Super::Tick(DeltaTime);
	if (((GetWorld()->GetTimeSeconds() - LastPlayerIDTalkingTime) < 0.1) && (PlayerOwner.GameReplicationInfo != nullptr))
	{
		if ((PortraitPRI == nullptr) || (PortraitPRI.PlayerID != LastPlayerIDTalking))
		{
			PortraitPRI = PlayerOwner.GameReplicationInfo.FindPlayerByID(LastPlayerIDTalking);
			if (PortraitPRI != nullptr)
			{
				NewPortrait = PortraitPRI.GetPortrait();
				if (NewPortrait != nullptr)
				{
					if (Portrait == nullptr)
					{
						PortraitX = 1;
					}
					Portrait = NewPortrait;
					PortraitTime = (GetWorld()->GetTimeSeconds() + 3);
				}
			}
		}
		else
		{
			PortraitTime = (GetWorld()->GetTimeSeconds() + 0.2);
		}
	}
	else
	{
		LastPlayerIDTalking = 0;
	}
	if ((PortraitTime - GetWorld()->GetTimeSeconds()) > 0)
	{
		PortraitX = FMax(0, (PortraitX - (3 * DeltaTime)));
	}
	else
	{
		if (Portrait != nullptr)
		{
			PortraitX = FMin(1, (PortraitX + (3 * DeltaTime)));
			if (PortraitX == 1)
			{
				Portrait = nullptr;
				PortraitPRI = nullptr;
			}
		}
	}
	pulseNumber(0, HealthCount, 0.26, 0.05, DeltaTime, 0.25, 0, 255, CurHealth, LastHealth);
	pulseNumber(1, ShieldCount, 0.26, 0.05, DeltaTime, 0.25, 0, 255, CurShield, LastShield);
	ArmorPulse(DeltaTime, 255, 0, ShieldIconGlow, TeamIndex, 250);
	if (CurHealth < float(50))
	{
		LowHealth(DeltaTime, 255, 0, LHud2[3], TeamIndex, 1000);
	}
	else
	{
		LHud2[3].Tints[TeamIndex].A = 50;
	}
	if (CurHealth < float(25))
	{
		pulseWidget(DeltaTime, 255, 0, HealthIcon, TeamIndex, 2, 2000);
	}
	else
	{
		HealthIcon.Tints[TeamIndex].A = 255;
	}
	if (AdrenalineReady)
	{
		pulseWidget(DeltaTime, 255, 0, Adrenaline[4], TeamIndex, 2, 1000);
	}
	else
	{
		Adrenaline[4].Tints[TeamIndex].A = 0;
	}
	*/
}

void AHudBDeathMatch::pulseWidget(float DeltaTime, float Max, float Min, FSpriteWidget& Sprite, int32 tIndex, int32 PIndex, float pRate)
{
	float accum = 0;
	/*
	accum = (DeltaTime * pRate);
	if (float(Sprite.Tints[tIndex].A) < Min)
	{
		(accumData[PIndex] += accum);
	}
	else
	{
		(accumData[PIndex] -= accum);
	}
	if (accumData[PIndex] < Min)
	{
		accumData[PIndex] = Max;
	}
	Sprite.Tints[tIndex].A = uint8(accumData[PIndex]);
	*/
}

void AHudBDeathMatch::pulseNumber(int32 gIndex, FNumericWidget& number, float nScale, float growSpeed, float DeltaTime, float oScale, float test1, float test2, float first, float Last)
{
	float growAccum = 0;
	/*
	growAccum = (DeltaTime * growSpeed);
	testLerp = (test1 + ((DeltaTime * 2) * (test2 - test1)));
	if (Growing)
	{
		(growScale[gIndex] -= growAccum);
		(growTrace[gIndex] += testLerp);
		if (growTrace[gIndex] > float(255))
		{
			growTrace[gIndex] = 255;
		}
		if (first < Last)
		{
			growTrace[gIndex] = 0;
			growScale[gIndex] = nScale;
		}
		if (growScale[gIndex] < oScale)
		{
			growScale[gIndex] = oScale;
		}
		if ((growScale[gIndex] < oScale) && (growTrace[gIndex] == float(255)))
		{
			Growing = false;
		}
		number.Tints[TeamIndex].B = uint8(growTrace[gIndex]);
		number.TextureScale = growScale[gIndex];
	}
	else
	{
		if (first < Last)
		{
			growTrace[gIndex] = 0;
			growScale[gIndex] = nScale;
			Growing = true;
		}
		else
		{
			growScale[gIndex] = oScale;
		}
	}
	*/
}

void AHudBDeathMatch::ArmorPulse(float DeltaTime, float Max, float Min, FSpriteWidget& Sprite, int32 tIndex, float pRate)
{
	/*
	int32 accum = 0;
	accum = int((DeltaTime * pRate));
	if (ArmorGlow)
	{
		(pulseArmorIcon += float(accum));
	}
	else
	{
		(pulseArmorIcon -= float(accum));
	}
	if (pulseArmorIcon <= Min)
	{
		pulseArmorIcon = Min;
		ArmorGlow = true;
	}
	else
	{
		if (pulseArmorIcon >= Max)
		{
			pulseArmorIcon = Max;
			ArmorGlow = false;
		}
	}
	Sprite.Tints[tIndex].A = uint8(pulseArmorIcon);
	Sprite.Tints[tIndex].B = uint8(pulseArmorIcon);
	*/
}

void AHudBDeathMatch::LowHealth(float DeltaTime, float Max, float Min, FSpriteWidget& Sprite, int32 tIndex, float pRate)
{
	int32 accum = 0;
	/*
	accum = int((DeltaTime * pRate));
	if (LowHealthPulse)
	{
		(pulseHealthIcon += float(accum));
	}
	else
	{
		(pulseHealthIcon -= float(accum));
	}
	if (pulseHealthIcon <= Min)
	{
		pulseHealthIcon = Min;
		LowHealthPulse = true;
	}
	else
	{
		if (pulseHealthIcon >= Max)
		{
			pulseHealthIcon = Max;
			LowHealthPulse = false;
		}
	}
	Sprite.Tints[tIndex].A = uint8(pulseHealthIcon);
	*/
}

void AHudBDeathMatch::UpdateRankAndSpread(UCanvas* C)
{
	int32 i = 0;
	/*
	if ((ScoreBoard == nullptr) || (!ScoreBoard.UpdateGRI()))
	{
		return;
	}
	i = 0;
	if (i < PlayerOwner.GameReplicationInfo.PRIArray.Num())
	{
		if (PawnOwnerPRI == PlayerOwner.GameReplicationInfo.PRIArray[i])
		{
			myRank.Value = (i + 1);
		}
		else
		{
			i++;
		}
	}
	if (bShowPoints)
	{
		DrawNumericWidget(C, myScore, DigitsBig);
		if (C.ClipX >= float(640))
		{
			DrawNumericWidget(C, mySpread, DigitsBig);
		}
		DrawNumericWidget(C, myRank, DigitsBig);
	}
	if (myRank.Value > 9)
	{
		myRank.TextureScale = 0.12;
		myRank.OffsetX = 240;
		myRank.OffsetY = 90;
	}
	else
	{
		myRank.TextureScale = 0.18;
		myRank.OffsetX = 150;
		myRank.OffsetY = 40;
	}
	*/
}

void AHudBDeathMatch::CalculateHealth()
{
	LastHealth = CurHealth;
	//CurHealth = float(PawnOwner.Health);
}

void AHudBDeathMatch::CalculateShield()
{
	LastShield = CurShield;
}

void AHudBDeathMatch::CalculateEnergy()
{
	/*
	if (PawnOwner.Controller == nullptr)
	{
		MaxEnergy = PlayerOwner.AdrenalineMax;
		CurEnergy = float(Clamp(int(PlayerOwner.Adrenaline), 0, int(MaxEnergy)));
	}
	else
	{
		MaxEnergy = PawnOwner.Controller.AdrenalineMax;
		CurEnergy = float(Clamp(int(PawnOwner.Controller.Adrenaline), 0, int(MaxEnergy)));
	}
	AdrenalineCount.Value = int(CurEnergy);
	*/
}

void AHudBDeathMatch::CalculateAmmo()
{
	MaxAmmoPrimary = 1;
	CurAmmoPrimary = 1;
}

void AHudBDeathMatch::CalculateScore()
{
	ScoreDiff = CurScore;
}

FString AHudBDeathMatch::GetScoreText()
{
	return ScoreText;
}

FString AHudBDeathMatch::GetScoreValue(AAA2_PlayerState* PRI)
{
	return "";
}

FString AHudBDeathMatch::GetScoreTagLine()
{
	return InitialViewingString;
}

void AHudBDeathMatch::DrawSpectatingHud(UCanvas* C)
{
}

FString AHudBDeathMatch::GetInfoString()
{
	FString InfoString = "";
	return InfoString;
}

void AHudBDeathMatch::DrawCrossHair(UCanvas* C)
{
}

void AHudBDeathMatch::DrawEnemyName(UCanvas* C)
{
	AActor* HitActor = nullptr;
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector ViewPos = FVector(0, 0, 0);
	/*
	if ((PlayerOwner.bBehindView || bNoEnemyNames) || (PawnOwner.Controller == nullptr))
	{
		return;
	}
	ViewPos = (PawnOwner.Location + (PawnOwner.BaseEyeHeight * FVector(0, 0, 1)));
	HitActor = Trace(HitLocation, HitNormal, (ViewPos + (float(1200) * Vector(PawnOwner.Controller.Rotation))), ViewPos, true);
	if ((((Cast<APawn>(HitActor) != nullptr) && (Cast<APawn>(HitActor).PlayerReplicationInfo != nullptr)) && (HitActor != PawnOwner)) && ((PawnOwner.PlayerReplicationInfo.Team == nullptr) || (PawnOwner.PlayerReplicationInfo.Team != Cast<APawn>(HitActor).PlayerReplicationInfo.Team)))
	{
		if ((NamedPlayer != Cast<APawn>(HitActor).PlayerReplicationInfo) || ((GetWorld()->GetTimeSeconds() - NameTime) > 0.5))
		{
			DisplayEnemyName(C, Pawn(HitActor).PlayerReplicationInfo);
			NameTime = GetWorld()->GetTimeSeconds();
		}
		NamedPlayer = Cast<APawn>(HitActor).PlayerReplicationInfo;
	}
	*/
}

void AHudBDeathMatch::DisplayEnemyName(UCanvas* C, AAA2_PlayerState* PRI)
{
}

void AHudBDeathMatch::SetSmallWeaponBar()
{
	int32 i = 0;
	bRealSmallWeaponBar = bSmallWeaponBar;
	if (bSmallWeaponBar)
	{
		/*
		LHud1[0].TextureCoords.Y2 = 893;
		LHud1[1].TextureCoords.Y2 = 893;
		LHud1[0].PosY = 0.89;
		LHud1[1].PosY = 0.89;
		LHud1[0].TextureScale = 0.25;
		LHud1[1].TextureScale = 0.25;
		LHud2[1].PosY = 0.88;
		LHud2[0].PosY = 0.88;
		LHud1[3].PosY = 0.88;
		LHud2[3].PosY = 0.88;
		HealthIcon.PosY = 0.88;
		HealthCount.PosY = 0.88;
		LHud2[1].PosX = -0.03;
		LHud2[0].PosX = -0.03;
		LHud1[3].PosX = -0.03;
		LHud2[3].PosX = -0.03;
		HealthIcon.PosX = -0.03;
		HealthCount.PosX = -0.03;
		UDamageTrim.TextureScale = 0.27;
		UDamageTeamTint.TextureScale = 0.27;
		UDamageFill.TextureScale = 0.27;
		UDamageTrim.PosX = -0.005;
		UDamageTeamTint.PosX = -0.005;
		UDamageFill.PosX = -0.005;
		UDamageTrim.PosY = 0.88;
		UDamageTeamTint.PosY = 0.88;
		UDamageFill.PosY = 0.88;
		RHud1[0].TextureCoords.Y2 = 893;
		RHud1[1].TextureCoords.Y2 = 893;
		RHud1[0].PosY = 0.89;
		RHud1[1].PosY = 0.89;
		RHud1[0].TextureScale = 0.25;
		RHud1[1].TextureScale = 0.25;
		RHud2[1].PosY = 0.88;
		RHud2[0].PosY = 0.88;
		RHud1[3].PosY = 0.88;
		RHud2[3].PosY = 0.88;
		AmmoIcon.PosY = 0.88;
		AmmoCount.PosY = 0.88;
		RHud2[1].PosX = 1.03;
		RHud2[0].PosX = 1.03;
		RHud1[3].PosX = 1.03;
		RHud2[3].PosX = 1.03;
		AmmoIcon.PosX = 1.03;
		AmmoCount.PosX = 1.03;
		ReloadingTrim.TextureScale = 0.27;
		ReloadingTeamTint.TextureScale = 0.27;
		ReloadingFill.TextureScale = 0.27;
		ReloadingTrim.PosX = 1.005;
		ReloadingTeamTint.PosX = 1.005;
		ReloadingFill.PosX = 1.005;
		ReloadingTrim.PosY = 0.88;
		ReloadingTeamTint.PosY = 0.88;
		ReloadingFill.PosY = 0.88;
		*/
	}
	else
	{
		/*
		for (i = 0; i < 4; i++)
		{
			LHud1[i].PosX = Default.LHud1[i].PosX;
			LHud1[i].PosY = Default.LHud1[i].PosY;
			LHud2[i].PosX = Default.LHud2[i].PosX;
			LHud2[i].PosY = Default.LHud2[i].PosY;
			RHud1[i].PosX = Default.RHud1[i].PosX;
			RHud1[i].PosY = Default.RHud1[i].PosY;
			RHud2[i].PosX = Default.RHud2[i].PosX;
			RHud2[i].PosY = Default.RHud2[i].PosY;
			ShieldCount.PosY = Default.ShieldCount.PosY;
			ShieldIcon.PosY = Default.ShieldIcon.PosY;
			ShieldIconGlow.PosY = Default.ShieldIconGlow.PosY;
		}
		LHud1[0].TextureScale = Default.LHud1[0].TextureScale;
		LHud1[0].TextureCoords = Default.LHud1[0].TextureCoords;
		RHud1[0].TextureScale = Default.RHud1[0].TextureScale;
		RHud1[0].TextureCoords = Default.RHud1[0].TextureCoords;
		LHud1[1].TextureScale = Default.LHud1[1].TextureScale;
		LHud1[1].TextureCoords = Default.LHud1[1].TextureCoords;
		RHud1[1].TextureScale = Default.RHud1[1].TextureScale;
		RHud1[1].TextureCoords = Default.RHud1[1].TextureCoords;
		HealthIcon.PosY = Default.HealthIcon.PosY;
		HealthCount.PosY = Default.HealthCount.PosY;
		HealthIcon.PosX = Default.HealthIcon.PosX;
		HealthCount.PosX = Default.HealthCount.PosX;
		UDamageTrim.TextureScale = Default.UDamageTrim.TextureScale;
		UDamageTeamTint.TextureScale = Default.UDamageTeamTint.TextureScale;
		UDamageFill.TextureScale = Default.UDamageFill.TextureScale;
		UDamageTrim.PosX = Default.UDamageTrim.PosX;
		UDamageTeamTint.PosX = Default.UDamageTeamTint.PosX;
		UDamageFill.PosX = Default.UDamageFill.PosX;
		UDamageTrim.PosY = Default.UDamageTrim.PosY;
		UDamageTeamTint.PosY = Default.UDamageTeamTint.PosY;
		UDamageFill.PosY = Default.UDamageFill.PosY;
		AmmoIcon.PosY = Default.AmmoIcon.PosY;
		AmmoCount.PosY = Default.AmmoCount.PosY;
		AmmoIcon.PosX = Default.AmmoIcon.PosX;
		AmmoCount.PosX = Default.AmmoCount.PosX;
		ReloadingTrim.TextureScale = Default.ReloadingTrim.TextureScale;
		ReloadingTeamTint.TextureScale = Default.ReloadingTeamTint.TextureScale;
		ReloadingFill.TextureScale = Default.ReloadingFill.TextureScale;
		ReloadingTrim.PosX = Default.ReloadingTrim.PosX;
		ReloadingTeamTint.PosX = Default.ReloadingTeamTint.PosX;
		ReloadingFill.PosX = Default.ReloadingFill.PosX;
		ReloadingTrim.PosY = Default.ReloadingTrim.PosY;
		ReloadingTeamTint.PosY = Default.ReloadingTeamTint.PosY;
		ReloadingFill.PosY = Default.ReloadingFill.PosY;
		*/
	}
	SetHUDScale();
}

void AHudBDeathMatch::SetHUDScale()
{
	int32 i = 0;
	float NewPosX = 0;
	float NewPosY = 0;
	OldHUDScale = HudScale;
	/*
	if (bSmallWeaponBar)
	{
		HudScale *= 0.67;
		NewPosY = (Default.WeaponBarTint[0].PosY + ((1 - HudScale) * 0.043));
	}
	else
	{
		NewPosY = Default.WeaponBarTint[0].PosY;
	}
	for (i = 0; i < 9; i++)
	{
		NewPosX = ((0.5 * (1 - HudScale)) + (HudScale * Default.WeaponBarAmmoFill[i].PosX));
		WeaponBarAmmoFill[i].PosX = NewPosX;
		WeaponBarTint[i].PosX = NewPosX;
		WeaponBarTrim[i].PosX = NewPosX;
		WeaponBarIcon[i].PosX = NewPosX;
		WeaponBarAmmoFill[i].PosY = (NewPosY + (0.043 * HudScale));
		WeaponBarTint[i].PosY = NewPosY;
		WeaponBarTrim[i].PosY = NewPosY;
		WeaponBarIcon[i].PosY = NewPosY;
	}
	*/
	HudScale = OldHUDScale;
}

void AHudBDeathMatch::DisplayVoiceGain(UCanvas* C)
{
	UMaterialInstance* Tex = nullptr;
	float VoiceGain = 0;
	float PosY = 0;
	float BlockSize = 0;
	int32 i = 0;
	/*
	BlockSize = ((8192 / C.ClipX) * HudScale);
	Tex = Texture'Engine.WhiteSquareTexture';
	PosY = (C.ClipY * 0.375);
	VoiceGain = ((1 - float((3 * FMath::Min(int((GetWorld()->GetTimeSeconds() - LastVoiceGainTime)), int(0.3333))))) * LastVoiceGain);
	for (i = 0; i < 10; i++)
	{
		if (VoiceGain > (0.1 * float(i)))
		{
			C.SetPos((0.5 * BlockSize), PosY);
			C.SetDrawColor(byte((28.299999 * float(i))), uint8((float(255) - (28.299999 * float(i)))), 0, 255);
			C.DrawTile(Tex, BlockSize, BlockSize, 0, 0, float(Tex.USize), float(Tex.VSize));
			PosY -= (1.2 * BlockSize);
		}
	}
	*/
}

void AHudBDeathMatch::DrawHudPassA(UCanvas* C)
{
}

void AHudBDeathMatch::ShowPointBarTop(UCanvas* C)
{
	if (bShowPoints)
	{
		//DrawSpriteWidget(C, ScoreBg[0]);
		//DrawSpriteWidget(C, ScoreBg[3]);
	}
}

void AHudBDeathMatch::ShowPointBarBottom(UCanvas* C)
{
	if (bShowPoints)
	{
		//DrawSpriteWidget(C, ScoreBg[2]);
		//DrawSpriteWidget(C, ScoreBg[1]);
	}
}

void AHudBDeathMatch::DrawHudPassC(UCanvas* C)
{
	float PortraitWidth = 0;
	float PortraitHeight = 0;
	float XL = 0;
	float YL = 0;
	float Abbrev = 0;
	float SmallH = 0;
	float NameWidth = 0;
	FString PortraitString = "";
	/*
	if (bShowPortrait && (Portrait != nullptr))
	{
		PortraitWidth = (0.125 * C.ClipY);
		PortraitHeight = (1.5 * PortraitWidth);
		C.DrawColor = WhiteColor;
		C.SetPos((((-PortraitWidth) * PortraitX) + (0.025 * PortraitWidth)), ((0.5 * (C.ClipY - PortraitHeight)) + (0.025 * PortraitHeight)));
		C.DrawTile(Portrait, PortraitWidth, PortraitHeight, 0, 0, 256, 384);
		C.SetPos(((-PortraitWidth) * PortraitX), (0.5 * (C.ClipY - PortraitHeight)));
		C.Font = GetFontSizeIndex(C, -2);
		PortraitString = PortraitPRI.PlayerName;
		C.StrLen(PortraitString, XL, YL);
		if (XL > PortraitWidth)
		{
			C.Font = GetFontSizeIndex(C, -4);
			C.StrLen(PortraitString, XL, YL);
			if (XL > PortraitWidth)
			{
				Abbrev = ((float(Len(PortraitString)) * PortraitWidth) / XL);
				PortraitString = Left(PortraitString, int(Abbrev));
				C.StrLen(PortraitString, XL, YL);
			}
		}
		C.DrawColor = C.MakeColor(160, 160, 160);
		C.SetPos((((-PortraitWidth) * PortraitX) + (0.025 * PortraitWidth)), ((0.5 * (C.ClipY - PortraitHeight)) + (0.025 * PortraitHeight)));
		C.DrawColor = WhiteColor;
		C.SetPos(((-PortraitWidth) * PortraitX), (0.5 * (C.ClipY - PortraitHeight)));
		C.DrawColor = WhiteColor;
		C.SetPos((((C.ClipY / float(256)) - (PortraitWidth * PortraitX)) + (0.5 * (PortraitWidth - XL))), ((0.5 * (C.ClipY + PortraitHeight)) + (0.06 * PortraitHeight)));
		if (PortraitPRI != nullptr)
		{
			if (PortraitPRI.Team != nullptr)
			{
				if (PortraitPRI.Team.TeamIndex == 0)
				{
					C.DrawColor = RedColor;
				}
				else
				{
					C.DrawColor = TurqColor;
				}
			}
			C.DrawText(PortraitString, true);
		}
	}
	ShowPointBarTop(C);
	if (bShowPersonalInfo)
	{
		DrawSpriteWidget(C, Adrenaline[0]);
		DrawSpriteWidget(C, Adrenaline[3]);
		DrawSpriteWidget(C, Adrenaline[4]);
		DrawNumericWidget(C, AdrenalineCount, DigitsBig);
		DrawSpriteWidget(C, AdrenalineIcon);
		DrawSpriteWidget(C, HealthIcon);
		if (ShieldCount.Value > 0)
		{
			DrawSpriteWidget(C, ShieldIcon);
			DrawNumericWidget(C, ShieldCount, DigitsBig);
		}
		DrawNumericWidget(C, HealthCount, DigitsBig);
	}
	UpdateRankAndSpread(C);
	if (((PawnOwner != PlayerOwner.Pawn) && (PawnOwner != nullptr)) && (PawnOwner.PlayerReplicationInfo != nullptr))
	{
		C.Font = GetMediumFontFor(C);
		C.SetDrawColor(255, 255, 0, 255);
		C.StrLen(PawnOwner.PlayerReplicationInfo.PlayerName, NameWidth, SmallH);
		NameWidth = FMax(NameWidth, (0.15 * C.ClipX));
		if (C.ClipX >= float(640))
		{
			C.Font = GetConsoleFont(C);
			C.StrLen("W", XL, SmallH);
			C.SetPos((((79 * C.ClipX) / float(80)) - NameWidth), (C.ClipY * 0.68));
			C.DrawText(NowViewing, false);
		}
		C.Font = GetMediumFontFor(C);
		C.SetPos((((79 * C.ClipX) / float(80)) - NameWidth), ((C.ClipY * 0.68) + SmallH));
		C.DrawText(PawnOwner.PlayerReplicationInfo.PlayerName, false);
	}
	*/
	DrawCrossHair(C);
}

void AHudBDeathMatch::DrawWeaponBar(UCanvas* C)
{
}

void AHudBDeathMatch::UpdateHUD()
{
	/*
	if ((PawnOwnerPRI != nullptr) && (PawnOwnerPRI.Team != nullptr))
	{
		TeamIndex = Clamp(PawnOwnerPRI.Team.TeamIndex, 0, 1);
	}
	else
	{
		TeamIndex = 1;
	}
	CalculateScore();
	CalculateHealth();
	HealthCount.Value = int(CurHealth);
	HealthIcon.Tints[TeamIndex].R = uint8((float(255) - (float(255) *FMath::Clamp((CurHealth / float(100)), 0, 1))));
	HealthIcon.Tints[TeamIndex].G = 0;
	HealthIcon.Tints[TeamIndex].B = 255;
	CalculateShield();
	ShieldCount.Value = int(CurShield);
	CalculateEnergy();
	AdrenalineReady = (CurEnergy == MaxEnergy);
	CalculateAmmo();
	AmmoCount.Value = int(CurAmmoPrimary);
	if (!TeamLinked)
	{
		RHud2[3].Tints[TeamIndex].R = uint8((float(255) - (float(255) *FMath::Clamp((CurAmmoPrimary / MaxAmmoPrimary), 0, 1))));
		RHud2[3].Tints[TeamIndex].G = uint8((float(255) *FMath::Clamp((CurAmmoPrimary / MaxAmmoPrimary), 0, 1)));
		RHud2[3].Tints[TeamIndex].B = 0;
	}
	Super::UpdateHUD();
	*/
}

bool AHudBDeathMatch::DrawLevelAction(UCanvas* C)
{
	FString LevelActionText = "";
	FPlane OldModulate = FPlane({});
	/*
	if ((Level.LevelAction == 0) && (Level.Pauser != nullptr))
	{
		LevelActionText = LevelActionPaused;
	}
	else
	{
		if ((Level.LevelAction == 1) || (Level.LevelAction == 4))
		{
			LevelActionText = LevelActionLoading;
		}
		else
		{
			LevelActionText = "";
		}
	}
	if (LevelActionText == "")
	{
		return false;
	}
	C.Font = LoadLevelActionFont();
	C.DrawColor = LevelActionFontColor;
	C.Style = 6;
	OldModulate = C.ColorModulate;
	C.ColorModulate = C.Default.ColorModulate;
	C.DrawScreenText(LevelActionText, LevelActionPositionX, LevelActionPositionY, 8);
	C.ColorModulate = OldModulate;
	*/
	return true;
}

void AHudBDeathMatch::DisplayPortrait(AAA2_PlayerState* PRI)
{
	UMaterialInstance* NewPortrait = nullptr;
	if (LastPlayerIDTalking > 0)
	{
		return;
	}
	//NewPortrait = PRI.GetPortrait();
	if (NewPortrait == nullptr)
	{
		return;
	}
	if (Portrait == nullptr)
	{
		PortraitX = 1;
	}
	Portrait = NewPortrait;
	//PortraitTime = (GetWorld()->GetTimeSeconds() + 3);
	PortraitPRI = PRI;
}

void AHudBDeathMatch::Message(AAA2_PlayerState* PRI, FString Msg, FName MsgType)
{
	//Super::Message(PRI, Msg, MsgType);
	if (((PRI != nullptr) && (MsgType == "Say")) || (MsgType == "TeamSay"))
	{
		DisplayPortrait(PRI);
	}
}

UFont* AHudBDeathMatch::LoadLevelActionFont()
{
	if (LevelActionFontFont == nullptr)
	{
		//LevelActionFontFont = Font(DynamicLoadObject(LevelActionFontName, Class'Font'));
		if (LevelActionFontFont == nullptr)
		{
			//Log("Warning: " + FString::FromInt(this) + " Couldn't dynamically load font " + LevelActionFontName);
		}
	}
	return LevelActionFontFont;
}
