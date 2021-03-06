// All the original content belonged to the US Army

#include "AA29/Object/Actor/HUD/HudBase/HudCDeathmatch/HudCDeathmatch.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"
#include "AA29/Object/Actor/Info/VoiceChatRoom/VoiceChatRoom.h"
#include "AA29/Object/Actor/Info/SceneManager/SceneManager.h"
#include "AA29/Object/CacheManager/CacheManager.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"

AHudCDeathmatch::AHudCDeathmatch(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	HudColorTeam.SetNum(2);
	BarWeaponIconAnim.SetNum(9);
	LongCountName.SetNum(10);
	CountDownName.SetNum(10);
	BarWeaponStates.SetNum(9);
	BarBorderScaledPosition.SetNum(9);
	BarBorderAmmoIndicator.SetNum(9);
	BarBorder.SetNum(9);
	BarAmmoIcon.SetNum(9);
	BarWeaponIcon.SetNum(9);
	BaseWeapons.SetNum(9);
	TimerDigitSpacer.SetNum(2);
	LevelActionFontColor = FColor(255, 255, 255, 255);
	LevelActionPositionX = 0.5;
	LevelActionPositionY = 0.25;

	BarBorderScaledPosition = { 0.32,0.36,0.4,0.44,0.48,0.521,0.561,0.601,0.641 };
	bShowMissingWeaponInfo = true;
	//FadeTime = 0.3;
	CountDownName = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
	LongCountName = { "5_minute_warning", "3_minutes_remain", "2_minutes_remain", "1_minute_remains", "30_seconds_remain", "20_seconds" };
	BarWeaponIconAnim = { 1 };
	HudColorRed = FColor(0, 0, 200, 255);
	HudColorBlue = FColor(200, 64, 50, 255);
	HudColorBlack = FColor(0, 0, 0, 255);
	HudColorHighLight = FColor(0, 160, 255, 255);
	HudColorNormal = FColor(255, 255, 255, 255);
	HudColorTeam = { FColor(0, 0, 200, 255), FColor(200, 64, 50, 255) };
	ConsoleMessagePosX = 0.005;
	ConsoleMessagePosY = 0.87;
}

void AHudCDeathmatch::GrowHUD()
{
	if (!bShowWeaponInfo)
	{
		bShowWeaponInfo = true;
	}
	else
	{
		if (!bShowPersonalInfo)
		{
			bShowPersonalInfo = true;
		}
		else
		{
			if (!bShowPoints)
			{
				bShowPoints = true;
			}
			else
			{
				if ((!bDrawTimer) && GetDefault<AHudCDeathmatch>()->bDrawTimer)
				{
					bDrawTimer = true;
				}
				else
				{
					if (!bShowWeaponBar)
					{
						bShowWeaponBar = true;
					}
					else
					{
						if (!bShowMissingWeaponInfo)
						{
							bShowMissingWeaponInfo = true;
						}
					}
				}
			}
		}
	}
	SaveConfig();
}

void AHudCDeathmatch::ShrinkHUD()
{
	if (bShowMissingWeaponInfo)
	{
		bShowMissingWeaponInfo = false;
	}
	else
	{
		if (bShowWeaponBar)
		{
			bShowWeaponBar = false;
		}
		else
		{
			if (bDrawTimer)
			{
				bDrawTimer = false;
			}
			else
			{
				if (bShowPoints)
				{
					bShowPoints = false;
				}
				else
				{
					if (bShowPersonalInfo)
					{
						bShowPersonalInfo = false;
					}
					else
					{
						if (bShowWeaponInfo)
						{
							bShowWeaponInfo = false;
						}
					}
				}
			}
		}
	}
	SaveConfig();
}

void AHudCDeathmatch::UpdatePrecacheMaterials()
{
	int32 i = 0;
	if (!bUseCustomWeaponCrosshairs)
	{
		return;
	}
	/*
	for (i = 0; i < Crosshairs.Num(); i++)
	{
		LeveL->AddPrecacheMaterial(Crosshairs[i].WidgetTexture);
	}
	*/
}

void AHudCDeathmatch::PostBeginPlay()
{
	ASceneManager* SM = nullptr;
	Super::PostBeginPlay();
	/*
	ForEach AllActors(ASceneManager::StaticClass(), SM)
	{
		MySceneManagers.Num() = (MySceneManagers.Num() + 1);
		MySceneManagers[(MySceneManagers.Num() - 1)] = SM;
	}
	*/
	if (CustomCrosshairsAllowed())
	{
		SetCustomCrosshairs();
	}
}

bool AHudCDeathmatch::CustomCrosshairsAllowed()
{
	return true;
}

bool AHudCDeathmatch::CustomCrosshairColorAllowed()
{
	return true;
}

bool AHudCDeathmatch::CustomHUDColorAllowed()
{
	return true;
}

void AHudCDeathmatch::SetCustomCrosshairs()
{
	int32 i = 0;
	TArray<FCrosshairRecord> CustomCrosshairs = {};
	/*
	UCacheManager::StaticClass().GetCrosshairList(CustomCrosshairs);
	Crosshairs.Num() = CustomCrosshairs.Num();
	for (i = 0; i < CustomCrosshairs.Num(); i++)
	{
		Crosshairs[i].WidgetTexture = CustomCrosshairs[i].CrosshairTexture;
		Crosshairs[i].TextureCoords.X1 = 0;
		Crosshairs[i].TextureCoords.X2 = 64;
		Crosshairs[i].TextureCoords.Y1 = 0;
		Crosshairs[i].TextureCoords.Y2 = 64;
		Crosshairs[i].TextureScale = 0.75;
		Crosshairs[i].DrawPivot = 8;
		Crosshairs[i].PosX = 0.5;
		Crosshairs[i].PosY = 0.5;
		Crosshairs[i].OffsetX = 0;
		Crosshairs[i].OffsetY = 0;
		Crosshairs[i].ScaleMode = 0;
		Crosshairs[i].Scale = 1;
		Crosshairs[i].RenderStyle = 6;
	}
	if (CustomCrosshairColorAllowed())
	{
		SetCustomCrosshairColors();
	}
	*/
}

void AHudCDeathmatch::SetCustomCrosshairColors()
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

void AHudCDeathmatch::SetCustomHUDColor()
{
	/*
	if ((!CustomHUDColorAllowed()) || ((((CustomHUDColor.R == 0) && (CustomHUDColor.G == 0)) && (CustomHUDColor.B == 0)) && (CustomHUDColor.A == 0)))
	{
		CustomHUDColor = HudColorBlack;
		CustomHUDColor.A = 0;
		HudColorRed = HudColorTeam[0];
		HudColorBlue = HudColorTeam[1];
		bUsingCustomHUDColor = false;
		return;
	}
	*/
	bUsingCustomHUDColor = true;
	HudColorRed = CustomHUDColor;
	HudColorBlue = CustomHUDColor;
}

void AHudCDeathmatch::CheckCountdown(AGameReplicationInfo* GRI)
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
			PlayerOwner.PlayStatusAnnouncement(LongCountName[0], 1, true);
		}
		else
		{
			if (OldRemainingTime == 180)
			{
				PlayerOwner.PlayStatusAnnouncement(LongCountName[1], 1, true);
			}
			else
			{
				if (OldRemainingTime == 120)
				{
					PlayerOwner.PlayStatusAnnouncement(LongCountName[2], 1, true);
				}
				else
				{
					if (OldRemainingTime == 60)
					{
						PlayerOwner.PlayStatusAnnouncement(LongCountName[3], 1, true);
					}
				}
			}
		}
		return;
	}
	if (OldRemainingTime == 30)
	{
		PlayerOwner.PlayStatusAnnouncement(LongCountName[4], 1, true);
	}
	else
	{
		if (OldRemainingTime == 20)
		{
			PlayerOwner.PlayStatusAnnouncement(LongCountName[5], 1, true);
		}
		else
		{
			if ((OldRemainingTime <= 10) && (OldRemainingTime > 0))
			{
				PlayerOwner.PlayStatusAnnouncement(CountDownName[(OldRemainingTime - 1)], 1, true);
			}
		}
	}
	*/
}

void AHudCDeathmatch::Tick(float DeltaTime)
{
	UMaterialInstance* NewPortrait = nullptr;
	Super::Tick(DeltaTime);
	/*
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
	*/
}

void AHudCDeathmatch::UpdateHUD()
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
	CalculateHealth();
	CalculateAmmo();
	CalculateShield();
	CalculateEnergy();
	CalculateScore();
	DigitsHealth.Value = CurHealth;
	DigitsVehicleHealth.Value = CurVehicleHealth;
	DigitsAmmo.Value = int(CurAmmoPrimary);
	DigitsShield.Value = CurShield;
	AdrenalineCount.Value = CurEnergy;
	myScore.Value = CurScore;
	Super::UpdateHUD();
	*/
}

void AHudCDeathmatch::DrawVehicleName(UCanvas* C)
{
	float XL = 0;
	float YL = 0;
	float Fade = 0;
	if (bHideWeaponName)
	{
		return;
	}
	/*
	if (VehicleDrawTimer > GetWorld()->GetTimeSeconds())
	{
		C.Font = GetMediumFontFor(C);
		C.DrawColor = WhiteColor;
		Fade = (VehicleDrawTimer - GetWorld()->GetTimeSeconds());
		if (Fade <= 1)
		{
			C.DrawColor.A = uint8((float(255) * Fade));
		}
		C.StrLen(VehicleName, XL, YL);
		C.SetPos(((C.ClipX / 2) - (XL / 2)), ((C.ClipY * 0.8) - YL));
		C.DrawText(VehicleName);
	}
	if ((PawnOwner != PlayerOwner.Pawn) || (PawnOwner == OldPawn))
	{
		return;
	}
	OldPawn = PawnOwner;
	if (Cast<AVehicle>(PawnOwner) == nullptr)
	{
		VehicleDrawTimer = FMin(VehicleDrawTimer, (GetWorld()->GetTimeSeconds() + 1));
	}
	else
	{
		VehicleName = Vehicle(PawnOwner).VehicleNameString;
		VehicleDrawTimer = (GetWorld()->GetTimeSeconds() + 1.5);
	}
	*/
}

void AHudCDeathmatch::DrawAdrenaline(UCanvas* C)
{
	/*
	if (!PlayerOwner.bAdrenalineEnabled)
	{
		return;
	}
	DrawSpriteWidget(C, AdrenalineBackground);
	DrawSpriteWidget(C, AdrenalineBackgroundDisc);
	if (CurEnergy == MaxEnergy)
	{
		DrawSpriteWidget(C, AdrenalineAlert);
		AdrenalineAlert.Tints[TeamIndex] = HudColorHighLight;
	}
	DrawSpriteWidget(C, AdrenalineIcon);
	DrawNumericWidget(C, AdrenalineCount, DigitsBig);
	if (CurEnergy > LastEnergy)
	{
		LastAdrenalineTime = GetWorld()->GetTimeSeconds();
	}
	LastEnergy = CurEnergy;
	DrawHUDAnimWidget(AdrenalineIcon, Default.AdrenalineIcon.TextureScale, LastAdrenalineTime, 0.6, 0.6);
	AdrenalineBackground.Tints[TeamIndex] = HudColorBlack;
	AdrenalineBackground.Tints[TeamIndex].A = 150;
	*/
}

void AHudCDeathmatch::DrawTimer(UCanvas* C)
{
	/*
	AGameReplicationInfo* GRI = nullptr;
	int32 minutes = 0;
	int32 hours = 0;
	int32 Seconds = 0;
	GRI = PlayerOwner.GameReplicationInfo;
	if (GRI.TimeLimit != 0)
	{
		Seconds = GRI.RemainingTime;
	}
	else
	{
		Seconds = GRI.ElapsedTime;
	}
	TimerBackground.Tints[TeamIndex] = HudColorBlack;
	TimerBackground.Tints[TeamIndex].A = 150;
	DrawSpriteWidget(C, TimerBackground);
	DrawSpriteWidget(C, TimerBackgroundDisc);
	DrawSpriteWidget(C, TimerIcon);
	TimerMinutes.OffsetX = (Default.TimerMinutes.OffsetX - 80);
	TimerSeconds.OffsetX = (Default.TimerSeconds.OffsetX - 80);
	TimerDigitSpacer[0].OffsetX = Default.TimerDigitSpacer[0].OffsetX;
	TimerDigitSpacer[1].OffsetX = Default.TimerDigitSpacer[1].OffsetX;
	if (Seconds > 3600)
	{
		hours = (Seconds / 3600);
		(Seconds -= (hours * 3600));
		DrawNumericWidget(C, TimerHours, DigitsBig);
		TimerHours.Value = hours;
		if (hours > 9)
		{
			TimerMinutes.OffsetX = Default.TimerMinutes.OffsetX;
			TimerSeconds.OffsetX = Default.TimerSeconds.OffsetX;
		}
		else
		{
			TimerMinutes.OffsetX = (Default.TimerMinutes.OffsetX - 40);
			TimerSeconds.OffsetX = (Default.TimerSeconds.OffsetX - 40);
			TimerDigitSpacer[0].OffsetX = (Default.TimerDigitSpacer[0].OffsetX - 32);
			TimerDigitSpacer[1].OffsetX = (Default.TimerDigitSpacer[1].OffsetX - 32);
		}
		DrawSpriteWidget(C, TimerDigitSpacer[0]);
	}
	DrawSpriteWidget(C, TimerDigitSpacer[1]);
	minutes = (Seconds / 60);
	(Seconds -= (minutes * 60));
	TimerMinutes.Value = FMath::Min(minutes, 60);
	TimerSeconds.Value = FMath::Min(Seconds, 60);
	DrawNumericWidget(C, TimerMinutes, DigitsBig);
	DrawNumericWidget(C, TimerSeconds, DigitsBig);
	*/
}

void AHudCDeathmatch::DrawUDamage(UCanvas* C)
{
}

void AHudCDeathmatch::UpdateRankAndSpread(UCanvas* C)
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
		DrawSpriteWidget(C, MyScoreBackground);
		MyScoreBackground.Tints[TeamIndex] = HudColorBlack;
		MyScoreBackground.Tints[TeamIndex].A = 150;
		DrawNumericWidget(C, myScore, DigitsBig);
		if (C.ClipX >= float(640))
		{
			DrawNumericWidget(C, mySpread, DigitsBig);
		}
		DrawNumericWidget(C, myRank, DigitsBig);
	}
	*/
}

void AHudCDeathmatch::CalculateHealth()
{
	LastHealth = CurHealth;
	/*
	if (Cast<AVehicle>(PawnOwner) != nullptr)
	{
		if (Cast<AVehicle>(PawnOwner).Driver != nullptr)
		{
			CurHealth = Vehicle(PawnOwner).Driver.Health;
		}
		LastVehicleHealth = CurVehicleHealth;
		CurVehicleHealth = PawnOwner.Health;
	}
	else
	{
		CurHealth = PawnOwner.Health;
		CurVehicleHealth = 0;
	}
	*/
}

void AHudCDeathmatch::CalculateShield()
{
}

void AHudCDeathmatch::CalculateEnergy()
{
	/*
	if (PawnOwner.Controller == nullptr)
	{
		MaxEnergy = int(PlayerOwner.AdrenalineMax);
		CurEnergy = Clamp(int(PlayerOwner.Adrenaline), 0, MaxEnergy);
	}
	else
	{
		MaxEnergy = int(PawnOwner.Controller.AdrenalineMax);
		CurEnergy = Clamp(int(PawnOwner.Controller.Adrenaline), 0, MaxEnergy);
	}
	*/
}

void AHudCDeathmatch::CalculateAmmo()
{
	MaxAmmoPrimary = 1;
	CurAmmoPrimary = 1;
}

void AHudCDeathmatch::CalculateScore()
{
	ScoreDiff = CurScore;
}

FString AHudCDeathmatch::GetScoreText()
{
	return ScoreText;
}

FString AHudCDeathmatch::GetScoreValue(AAA2_PlayerState* PRI)
{
	return "";
}

FString AHudCDeathmatch::GetScoreTagLine()
{
	return InitialViewingString;
}

FColor AHudCDeathmatch::GetTeamColor(uint8 TeamNum)
{
	if (TeamNum == 1)
	{
		return GetDefault<AHudCDeathmatch>()->HudColorTeam[1];
	}
	else
	{
		return GetDefault<AHudCDeathmatch>()->HudColorTeam[0];
	}
}

bool AHudCDeathmatch::IsInCinematic()
{
	int32 i = 0;
	/*
	if (MySceneManagers.Num() > 0)
	{
		for (i = 0; i < MySceneManagers.Num(); i++)
		{
			if (MySceneManagers[i].bIsRunning)
			{
				return true;
			}
		}
	}
	*/
	return false;
}

void AHudCDeathmatch::DrawSpectatingHud(UCanvas* C)
{
}

FString AHudCDeathmatch::GetInfoString()
{
	FString InfoString = "";
	return InfoString;
}

void AHudCDeathmatch::DrawHUDAnimDigit(FNumericWidget& HUDPiece, float DefaultScale, float PickUPTime, float AnimTime, FColor DefaultColor, FColor colorHighlight)
{
	/*
	if (PickUPTime > (GetWorld()->GetTimeSeconds() - AnimTime))
	{
		HUDPiece.Tints[TeamIndex].R = uint8((float(colorHighlight.R) + (float((DefaultColor.R - colorHighlight.R)) * (GetWorld()->GetTimeSeconds() - PickUPTime))));
		HUDPiece.Tints[TeamIndex].B = uint8((float(colorHighlight.B) + (float((DefaultColor.B - colorHighlight.B)) * (GetWorld()->GetTimeSeconds() - PickUPTime))));
		HUDPiece.Tints[TeamIndex].G = uint8((float(colorHighlight.G) + (float((DefaultColor.G - colorHighlight.G)) * (GetWorld()->GetTimeSeconds() - PickUPTime))));
	}
	else
	{
		HUDPiece.Tints[TeamIndex] = DefaultColor;
	}
	*/
}

void AHudCDeathmatch::DrawHUDAnimWidget(FSpriteWidget& HUDPiece, float DefaultScale, float PickUPTime, float AnimTime, float AnimScale)
{
	/*
	if (PickUPTime > (GetWorld()->GetTimeSeconds() - AnimTime))
	{
		if (PickUPTime > (GetWorld()->GetTimeSeconds() - (AnimTime / 2)))
		{
			HUDPiece.TextureScale = (DefaultScale * (1 + (AnimScale * (GetWorld()->GetTimeSeconds() - PickUPTime))));
		}
		else
		{
			HUDPiece.TextureScale = (DefaultScale * (1 + (AnimScale * ((PickUPTime + AnimTime) - GetWorld()->GetTimeSeconds()))));
		}
	}
	else
	{
		HUDPiece.TextureScale = DefaultScale;
	}
	*/
}

void AHudCDeathmatch::DrawCrossHair(UCanvas* C)
{
	float NormalScale = 0;
	int32 i = 0;
	int32 CurrentCrosshair = 0;
	float OldScale = 0;
	float OldW = 0;
	float CurrentCrosshairScale = 0;
	FColor CurrentCrosshairColor = FColor(0, 0, 0, 0);
	FSpriteWidget CHtexture = FSpriteWidget({});
	/*
	if (PawnOwner->bSpecialCrosshair)
	{
		PawnOwner->SpecialDrawCrosshair(C);
		return;
	}
	if (!bCrosshairShow)
	{
		return;
	}
	CurrentCrosshair = Clamp(CurrentCrosshair, 0, (Crosshairs.Num() - 1));
	NormalScale = Crosshairs[CurrentCrosshair].TextureScale;
	if (CHtexture.WidgetTexture == nullptr)
	{
		CHtexture = Crosshairs[CurrentCrosshair];
	}
	CHtexture.TextureScale *= (0.5 * CurrentCrosshairScale);
	for (i = 0; i < 2; i++)
	{
		CHtexture.Tints[i] = CurrentCrosshairColor;
	}
	if (LastPickupTime > (GetWorld()->GetTimeSeconds() - 0.4))
	{
		if (LastPickupTime > (GetWorld()->GetTimeSeconds() - 0.2))
		{
			CHtexture.TextureScale *= (1 + (5 * (GetWorld()->GetTimeSeconds() - LastPickupTime)));
		}
		else
		{
			CHtexture.TextureScale *= (1 + (5 * ((LastPickupTime + 0.4) - GetWorld()->GetTimeSeconds())));
		}
	}
	OldScale = HudScale;
	HudScale = 1;
	OldW = C.ColorModulate.W;
	C.ColorModulate.W = 1;
	DrawSpriteWidget(C, CHtexture);
	C.ColorModulate.W = OldW;
	HudScale = OldScale;
	CHtexture.TextureScale = NormalScale;
	DrawEnemyName(C);
	*/
}

void AHudCDeathmatch::DrawEnemyName(UCanvas* C)
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

void AHudCDeathmatch::DisplayEnemyName(UCanvas* C, AAA2_PlayerState* PRI)
{
}

void AHudCDeathmatch::FadeZoom()
{
}

void AHudCDeathmatch::ZoomFadeOut(UCanvas* C)
{
	float FadeValue = 0;
	/*
	if ((GetWorld()->GetTimeSeconds() - ZoomToggleTime) >= FadeTime)
	{
		return;
	}
	if (ZoomToggleTime > GetWorld()->GetTimeSeconds())
	{
		ZoomToggleTime = GetWorld()->GetTimeSeconds();
	}
	FadeValue = (255 * (1 - ((GetWorld()->GetTimeSeconds() - ZoomToggleTime) / FadeTime)));
	C.DrawColor.A = uint8(FadeValue);
	C.Style = 6;
	C.SetPos(0, 0);
	C.DrawTile(Texture'Engine.BlackTexture', float(C.SizeX), float(C.SizeY), 0, 0, 16, 16);
	*/
}

void AHudCDeathmatch::DisplayVoiceGain(UCanvas* C)
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
	if ((PlayerOwner != nullptr) && (PlayerOwner.ActiveRoom != nullptr))
	{
		ActiveName = PlayerOwner.ActiveRoom.GetTitle();
	}
	if (ActiveName != "")
	{
		ActiveName = "(" @ ActiveName @ ")";
		C.Font = GetFontSizeIndex(C, -2);
		C.StrLen(ActiveName, XL, YL);
		if (XL > (0.125 * C.ClipY))
		{
			C.Font = GetFontSizeIndex(C, -4);
			C.StrLen(ActiveName, XL, YL);
		}
		C.SetPos((BlockSize * 2), (((C.ClipY * 0.375) + BlockSize) - YL));
		C.DrawColor = C.MakeColor(160, 160, 160);
		if ((PlayerOwner != nullptr) && (PlayerOwner.PlayerReplicationInfo != nullptr))
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

void AHudCDeathmatch::DrawHudPassA(UCanvas* C)
{
	APawn* RealPawnOwner = nullptr;
	ZoomFadeOut(C);
	/*
	if (PawnOwner != nullptr)
	{
		if (bShowWeaponInfo && (PawnOwner.Weapon != nullptr))
		{
			DrawSpriteWidget(C, HudBorderAmmo);
		}
		if (bShowWeaponBar && (PawnOwner.Weapon != nullptr))
		{
			DrawWeaponBar(C);
		}
		if (bShowPersonalInfo)
		{
			if ((Cast<AVehicle>(PawnOwner) != nullptr) && (Cast<AVehicle>(PawnOwner).Driver != nullptr))
			{
				if (Cast<AVehicle>(PawnOwner).bShowChargingBar)
				{
					DrawVehicleChargeBar(C);
				}
				RealPawnOwner = PawnOwner;
				PawnOwner = Vehicle(PawnOwner).Driver;
			}
			DrawHUDAnimWidget(HudBorderHealthIcon, Default.HudBorderHealthIcon.TextureScale, LastHealthPickupTime, 0.6, 0.6);
			DrawSpriteWidget(C, HudBorderHealth);
			if ((float(CurHealth) / PawnOwner.HealthMax) < 0.26)
			{
				HudHealthALERT.Tints[TeamIndex] = HudColorTeam[TeamIndex];
				DrawSpriteWidget(C, HudHealthALERT);
			}
			else
			{
				HudBorderHealthIcon.WidgetTexture = Default.HudBorderHealth.WidgetTexture;
			}
			DrawSpriteWidget(C, HudBorderHealthIcon);
			if (CurHealth < LastHealth)
			{
				LastDamagedHealth = GetWorld()->GetTimeSeconds();
			}
			DrawHUDAnimDigit(DigitsHealth, Default.DigitsHealth.TextureScale, LastDamagedHealth, 0.8, Default.DigitsHealth.Tints[TeamIndex], HudColorHighLight);
			DrawNumericWidget(C, DigitsHealth, DigitsBig);
			if (CurHealth > 999)
			{
				DigitsHealth.OffsetX = 220;
				DigitsHealth.OffsetY = -35;
				DigitsHealth.TextureScale = 0.39;
			}
			else
			{
				DigitsHealth.OffsetX = Default.DigitsHealth.OffsetX;
				DigitsHealth.OffsetY = Default.DigitsHealth.OffsetY;
				DigitsHealth.TextureScale = Default.DigitsHealth.TextureScale;
			}
			if (RealPawnOwner != nullptr)
			{
				PawnOwner = RealPawnOwner;
				DrawSpriteWidget(C, HudBorderVehicleHealth);
				if ((float(CurVehicleHealth) / PawnOwner.HealthMax) < 0.26)
				{
					HudVehicleHealthALERT.Tints[TeamIndex] = HudColorTeam[TeamIndex];
					DrawSpriteWidget(C, HudVehicleHealthALERT);
				}
				else
				{
					HudBorderVehicleHealthIcon.WidgetTexture = Default.HudBorderVehicleHealth.WidgetTexture;
				}
				DrawSpriteWidget(C, HudBorderVehicleHealthIcon);
				if (CurVehicleHealth < LastVehicleHealth)
				{
					LastDamagedVehicleHealth = GetWorld()->GetTimeSeconds();
				}
				DrawHUDAnimDigit(DigitsVehicleHealth, Default.DigitsVehicleHealth.TextureScale, LastDamagedVehicleHealth, 0.8, Default.DigitsVehicleHealth.Tints[TeamIndex], HudColorHighLight);
				DrawNumericWidget(C, DigitsVehicleHealth, DigitsBig);
				if (CurVehicleHealth > 999)
				{
					DigitsVehicleHealth.OffsetX = 220;
					DigitsVehicleHealth.OffsetY = -35;
					DigitsVehicleHealth.TextureScale = 0.39;
				}
				else
				{
					DigitsVehicleHealth.OffsetX = Default.DigitsVehicleHealth.OffsetX;
					DigitsVehicleHealth.OffsetY = Default.DigitsVehicleHealth.OffsetY;
					DigitsVehicleHealth.TextureScale = Default.DigitsVehicleHealth.TextureScale;
				}
			}
			DrawAdrenaline(C);
		}
	}
	UpdateRankAndSpread(C);
	DrawUDamage(C);
	if (bDrawTimer)
	{
		DrawTimer(C);
	}
	HudBorderShield.Tints[0] = HudColorRed;
	HudBorderShield.Tints[1] = HudColorBlue;
	HudBorderHealth.Tints[0] = HudColorRed;
	HudBorderHealth.Tints[1] = HudColorBlue;
	HudBorderVehicleHealth.Tints[0] = HudColorRed;
	HudBorderVehicleHealth.Tints[1] = HudColorBlue;
	HudBorderAmmo.Tints[0] = HudColorRed;
	HudBorderAmmo.Tints[1] = HudColorBlue;
	if (bShowPersonalInfo && (CurShield > 0))
	{
		DrawSpriteWidget(C, HudBorderShield);
		DrawSpriteWidget(C, HudBorderShieldIcon);
		DrawNumericWidget(C, DigitsShield, DigitsBig);
		DrawHUDAnimWidget(HudBorderShieldIcon, Default.HudBorderShieldIcon.TextureScale, LastArmorPickupTime, 0.6, 0.6);
	}
	if ((GetWorld()->GetTimeSeconds() - LastVoiceGainTime) < 0.333)
	{
		DisplayVoiceGain(C);
	}
	DisplayLocalMessages(C);
	*/
}

void AHudCDeathmatch::DrawHudPassC(UCanvas* C)
{
	AVoiceChatRoom* VCR = nullptr;
	float PortraitWidth = 0;
	float PortraitHeight = 0;
	float X = 0;
	float Y = 0;
	float XL = 0;
	float YL = 0;
	float Abbrev = 0;
	float SmallH = 0;
	float NameWidth = 0;
	FString PortraitString = "";
	/*
	if ((bShowPortrait || (bShowPortraitVC && ((GetWorld()->GetTimeSeconds() - LastPlayerIDTalkingTime) < 2))) && (Portrait != nullptr))
	{
		PortraitWidth = (0.125 * C.ClipY);
		PortraitHeight = (1.5 * PortraitWidth);
		C.DrawColor = WhiteColor;
		C.SetPos((((-PortraitWidth) * PortraitX) + (0.025 * PortraitWidth)), ((0.5 * (C.ClipY - PortraitHeight)) + (0.025 * PortraitHeight)));
		C.DrawTile(Portrait, PortraitWidth, PortraitHeight, 0, 0, 256, 384);
		C.SetPos(((-PortraitWidth) * PortraitX), (0.5 * (C.ClipY - PortraitHeight)));
		C.Font = GetFontSizeIndex(C, -2);
		if (PortraitPRI != nullptr)
		{
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
		}
		C.DrawColor = C.MakeColor(160, 160, 160);
		C.SetPos((((-PortraitWidth) * PortraitX) + (0.025 * PortraitWidth)), ((0.5 * (C.ClipY - PortraitHeight)) + (0.025 * PortraitHeight)));
		C.DrawColor = WhiteColor;
		C.SetPos(((-PortraitWidth) * PortraitX), (0.5 * (C.ClipY - PortraitHeight)));
		C.DrawColor = WhiteColor;
		X = ((C.ClipY / float(256)) - (PortraitWidth * PortraitX));
		Y = ((0.5 * (C.ClipY + PortraitHeight)) + (0.06 * PortraitHeight));
		C.SetPos((X + (0.5 * (PortraitWidth - XL))), Y);
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
			if ((((GetWorld()->GetTimeSeconds() - LastPlayerIDTalkingTime) < 2) && (PortraitPRI.ActiveChannel != -1)) && (PlayerOwner.VoiceReplicationInfo != nullptr))
			{
				VCR = PlayerOwner.VoiceReplicationInfo.GetChannelAt(PortraitPRI.ActiveChannel);
				if (VCR != nullptr)
				{
					PortraitString = "(" @ VCR.GetTitle() @ ")";
					C.StrLen(PortraitString, XL, YL);
					if (PortraitX == 0)
					{
						C.SetPos(float(Max(0, int((X + (0.5 * (PortraitWidth - XL)))))), (Y + YL));
					}
					else
					{
						C.SetPos((X + (0.5 * (PortraitWidth - XL))), (Y + YL));
					}
					C.DrawText(PortraitString);
				}
			}
		}
	}
	if (((PawnOwner != PlayerOwner.Pawn) && (PawnOwner != nullptr)) && (PawnOwner.AAA2_PlayerState* != nullptr))
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
	DrawCrossHair(C);
	*/
}

void AHudCDeathmatch::ShowReloadingPulse(float hold)
{
}

void AHudCDeathmatch::DrawChargeBar(UCanvas* C)
{
	float ScaleFactor = 0;
	/*
	ScaleFactor = ((HudScale * 0.135) * C.ClipX);
	C.Style = 6;
	if (((PawnOwner.PlayerReplicationInfo == nullptr) || (PawnOwner.PlayerReplicationInfo.Team == nullptr)) || (PawnOwner.PlayerReplicationInfo.Team.TeamIndex == 1))
	{
		C.DrawColor = HudColorBlue;
	}
	else
	{
		C.DrawColor = HudColorRed;
	}
	C.SetPos(((C.ClipX - ScaleFactor) - ((0.0011 * HudScale) * C.ClipX)), ((1 - (0.0975 * HudScale)) * C.ClipY));
	if (RechargeBar.Scale > 0)
	{
		DrawSpriteWidget(C, RechargeBar);
		ShowReloadingPulse(RechargeBar.Scale);
	}
	*/
}

void AHudCDeathmatch::DrawVehicleChargeBar(UCanvas* C)
{
	float ScaleFactor = 0;

	/*
	ScaleFactor = ((HudScale * 0.135) * C.ClipX);
	C.Style = 6;
	if (((PawnOwner.PlayerReplicationInfo == nullptr) || (PawnOwner.PlayerReplicationInfo.Team == nullptr)) || (PawnOwner.PlayerReplicationInfo.Team.TeamIndex == 1))
	{
		C.DrawColor = HudColorBlue;
	}
	else
	{
		C.DrawColor = HudColorRed;
	}
	C.SetPos(((C.ClipX - ScaleFactor) - ((0.0011 * HudScale) * C.ClipX)), ((1 - (0.0975 * HudScale)) * C.ClipY));
	DrawSpriteWidget(C, RechargeBar);
	RechargeBar.Scale = Vehicle(PawnOwner).ChargeBar();
	ShowReloadingPulse(RechargeBar.Scale);
	*/
}

void AHudCDeathmatch::DrawWeaponBar(UCanvas* C)
{
}

bool AHudCDeathmatch::DrawLevelAction(UCanvas* C)
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

void AHudCDeathmatch::DisplayPortrait(AAA2_PlayerState* PRI)
{
	/*
	UMaterialInstance* NewPortrait;
	if (LastPlayerIDTalking > 0)
	{
		return;
	}
	NewPortrait = PRI.GetPortrait();
	if (NewPortrait == nullptr)
	{
		return;
	}
	if (Portrait == nullptr)
	{
		PortraitX = 1;
	}
	Portrait = NewPortrait;
	PortraitTime = (GetWorld()->GetTimeSeconds() + 3);
	PortraitPRI = PRI;
	*/
}

UFont* AHudCDeathmatch::LoadLevelActionFont()
{
	if (LevelActionFontFont == nullptr)
	{
		/*
		LevelActionFontFont = Font(DynamicLoadObject(LevelActionFontName, Class'Font'));
		if (LevelActionFontFont == nullptr)
		{
			Log("Warning: " + FString::FromInt(this) + " Couldn't dynamically load font " + LevelActionFontName);
		}
		*/
	}
	return LevelActionFontFont;
}
