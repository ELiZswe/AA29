// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/WeaponAttachment.h"
#include "AA29/Object/Actor/Inventory/Ammunition/Ammunition.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Pickup/WeaponPickup/WeaponPickup.h"

AWeapon::AWeapon()
{
	_AuxAmmoClips.SetNum(16);
	_AmmoClips.SetNum(16);
	bCanThrow             = true;
	AutoSwitchPriority    = 1;
	ShakeMag              = 300;
	ShakeTime             = 0.1;
	aimerror              = 550;
	AIRating              = 0.5;
	CurrentRating         = 0.5;
	TraceDist             = 10000;
	MaxRange              = 8000;
	DisplayFOV            = -1;
	MuzzleScale           = 1;
	FlashLength           = 0.1;
	FireAdjust            = 1;
	weaponType            = EWeaponType::WEAPON_Unknown;
	iNextMisFire          = -1;
	ShakeVert             = FVector(0.0f,0.0f,5.0f);
	ShakeSpeed            = FVector(100.0f,100.0f,100.0f); 
	MessageNoAmmo         = " has no ammo.";
	ReloadStanding3PAnim  = FName("StdLgRld");
	ReloadProne3PAnim     = FName("PrnLgRld");
	NameColor             = FColor(255, 255, 255, 255);
	PlayerViewOffset      = FVector(30, 0, -5);
	ItemName              = FString("Weapon");
	InventoryGroup        = 1;
	DrawType              = EDrawType::DT_Mesh;
	AttachmentClass       = { AWeaponAttachment::StaticClass() };
	//bReplicateInstigator = true
}

/*
State NormalFire
{
	Function CheckAnimating()
	{
		if (! IsAnimating())
		{
			Warn(string(this) + " stuck in NormalFire and not animating!");
		}
	}
	Function ServerFire(bool bNoAdjustAim, bool bRapid, bool bBreatheBonus)
	{
		bForceFire=true;
	}
	Function ServerAltFire()
	{
		bForceAltFire=true;
	}
	Function Fire(float F)
	{
	}
	Function AltFire(float F)
	{
	}
	Function AnimEnd(int32 Channel)
	{
		Finish();
		CheckAnimating();
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
	}
	Function EndState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "Weapon::EndState() - in state" @ FString::FromInt(GetStateName()));
		}
		StopFiringTime=GetWorld()->GetTimeSeconds();
	}
Begin:
	Sleep(0);
}
*/

/*
State Idle
{
	Function bool IsIdle()
	{
		return true;
	}
	simulated Function ForceReload()
	{
		ServerForceReload();
	}
	Function ServerForceReload()
	{
		if (AmmoType.HasAmmo())
		{
			GotoState("Reloading");
		}
	}
	simulated Function AnimEnd(int32 Channel)
	{
		PlayIdleAnim();
	}
	simulated Function bool PutDown()
	{
		GotoState("DownWeapon");
		return true;
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
	}
Begin:
	bPointing=false;
	if (NeedsToReload() && AmmoType.HasAmmo())
	{
		GotoState("Reloading");
	}
	if (! AmmoType.HasAmmo())
	{
		Instigator.Controller.SwitchToBestWeapon();
	}
	if (Instigator.PressingFire())
	{
		Fire(0);
	}
	if (Instigator.PressingAltFire())
	{
		AltFire(0);
	}
	PlayIdleAnim();
}
*/

/*
State Reloading
{
	Function ServerForceReload()
	{
	}
	Function ClientForceReload()
	{
	}
	Function Fire(float Value)
	{
	}
	Function AltFire(float Value)
	{
	}
	Function ServerFire(bool bNoAdjustAim, bool bRapid, bool bBreatheBonus)
	{
		bForceFire=true;
	}
	Function ServerAltFire()
	{
		bForceAltFire=true;
	}
	simulated Function bool PutDown()
	{
		bChangeWeapon=true;
		return true;
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		if (! bForceReload)
		{
			if (Role < 4)
			{
				ServerForceReload();
			}
			else
			{
				ClientForceReload();
			}
		}
		bForceReload=false;
		PlayReloading();
	}
	simulated Function AnimEnd(int32 Channel)
	{
		ReloadCount=Default.ReloadCount;
		if (Role < 4)
		{
			ClientFinish();
		}
		else
		{
			Finish();
		}
		CheckAnimating();
	}
	Function CheckAnimating()
	{
		if (! IsAnimating())
		{
			Warn(string(this) + " stuck in Reloading and not animating!");
		}
	}
}
*/

/*
State Active
{
	Function Fire(float Value)
	{
	}
	Function AltFire(float Value)
	{
	}
	Function ServerFire(bool bNoAdjustAim, bool bRapid, bool bBreatheBonus)
	{
		bForceFire=true;
	}
	Function ServerAltFire()
	{
		bForceAltFire=true;
	}
	simulated Function bool PutDown()
	{
		FName Anim = "";
		float frame = 0;
		float Rate = 0;
		GetAnimParams(0,Anim,frame,Rate);
		if (bWeaponUp || (frame < 0.75))
		{
			GotoState("DownWeapon");
		}
		else
		{
			bChangeWeapon=true;
		}
		return true;
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Instigator=Pawn(GetOwner());
		bForceFire=false;
		bForceAltFire=false;
		bWeaponUp=false;
		bChangeWeapon=false;
	}
	simulated Function EndState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "Weapon::EndState() - in state" @ FString::FromInt(GetStateName()));
		}
		bForceFire=false;
		bForceAltFire=false;
	}
	simulated Function AnimEnd(int32 Channel)
	{
		if (bChangeWeapon)
		{
			GotoState("DownWeapon");
		}
		if (Owner == nullptr)
		{
			Log(string(this) + " no owner");
			Global.GlobalEvents(0);
			GotoState("None");
		}
		else
		{
			if (bWeaponUp)
			{
				if (GetRemoteRole() == ENetRole::ROLE_MAX)
				{
					Finish();
				}
				else
				{
					ClientFinish();
				}
			}
			else
			{
				PlayPostSelect();
				bWeaponUp=true;
			}
		}
		CheckAnimating();
	}
	Function CheckAnimating()
	{
		if (! IsAnimating())
		{
			Warn(string(this) + " stuck in Active and not animating!");
		}
	}
}
*/

/*
State DownWeapon
{
	Function Fire(float Value)
	{
	}
	Function AltFire(float Value)
	{
	}
	Function ServerFire(bool bNoAdjustAim, bool bRapid, bool bBreatheBonus)
	{
	}
	Function ServerAltFire()
	{
	}
	simulated Function bool PutDown()
	{
		return true;
	}
	simulated Function AnimEnd(int32 Channel)
	{
		Cast<APawn>(GetOwner())->ChangedWeapon();
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		bChangeWeapon=false;
		bMuzzleFlash=false;
		TweenDown();
	}
}
*/

/*
State ClientFiring
{
	Function Fire(float Value)
	{
	}
	Function AltFire(float Value)
	{
	}
	simulated Function AnimEnd(int32 Channel)
	{
		ClientFinish();
		CheckAnimating();
	}
	Function CheckAnimating()
	{
		if (! IsAnimating())
		{
			Warn(string(this) + " stuck in ClientFiring and not animating!");
		}
	}
	simulated Function EndState()
	{
		AmbientSound=nullptr;
		if (RepeatFire() && (! bPendingDelete))
		{
			ServerStopFiring();
		}
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
	}
}
*/

void AWeapon::BeginPlay()
{
	Super::BeginPlay();
}

bool AWeapon::CanCombatRoll(bool bActual)
{
	return false;			//Fake /ELiZ
}

bool AWeapon::CanSprint()
{
	return false;			//Fake /ELiZ
}

bool AWeapon::IsBusy()
{
	return false;
}

bool AWeapon::CanUseWeapon(int32 DesiredAction)
{
	return true;
}

bool AWeapon::IsTempBusy()
{
	return false;
}

bool AWeapon::IsCrawling()
{
	return false;
}

bool AWeapon::ShouldDrawCrosshair()
{
	return true;
}

void AWeapon::ClientBringUp()
{
}
void AWeapon::ClientPutDown()
{
}
void AWeapon::OwnerRecieved()
{
}
void AWeapon::DiscardShell()
{
}
bool AWeapon::ShouldDoDelayedEject()
{
	return false;
}
void AWeapon::UpdateCurrentAmmoRounds(bool bRoundInBreech)
{
}
void AWeapon::SetAltFireNotified(bool bNotify)
{
}

bool AWeapon::IsAltFireNotified()
{
	return false;
}

void AWeapon::SetFastMove(bool fast)
{
}

void AWeapon::SetSupported(bool newSupported)
{
}

void AWeapon::SetGuerrillaWeapon(bool newGuerrillaWeap)
{
}

void AWeapon::FailedSupported()
{
}

bool AWeapon::IsSupported()
{
	return bIsSupported;
}

FRotator AWeapon::CalcZoomWander()
{
	return FRotator(0, 0, 0);    //FAKE  /EliZ
}

UMaterialInstance* AWeapon::GetSupportIcon()
{
	if (tSupportIcon == nullptr)
	{
		return IconMaterial;
	}
	else
	{
		return tSupportIcon;
	}
}

void AWeapon::StartCrawling()
{
}

void AWeapon::StopCrawling()
{
}

bool AWeapon::IsSuppressed()
{
	return false;
}

void AWeapon::ToggleSuppressor()
{
}

void AWeapon::ToggleLeftRail()
{
}

void AWeapon::ToggleRightRail()
{
}

bool AWeapon::ShouldBreatheCycle()
{
	return false;     //FAKE /ELiZ
}

bool AWeapon::IsZoomed()
{
	return false;
}

float AWeapon::GetZoomMultiplier()
{
	return 1.0f;
}

void AWeapon::CycleZoom()
{
}
void AWeapon::ToggleZoom()
{
}
void AWeapon::UnZoom()
{
}
void AWeapon::ForceUnzoom(bool bForce)
{
}
void AWeapon::Zoom()
{
}
void AWeapon::ScopeAdjust(bool Vertical, bool increase)
{
}
void AWeapon::ZeroScope()
{
}
void AWeapon::FixJam()
{
}
void AWeapon::ServerFixJam()
{
}
void AWeapon::ChangeFireMode()
{
}
void AWeapon::ServerChangeFireMode()
{
}
void AWeapon::Reload()
{
}
bool AWeapon::ShouldRenderWeapon()
{
	return false;
}
float AWeapon::GetSoundDampening()
{
	return 1;
}
void AWeapon::GuardWeapon()
{
}
void AWeapon::TempLowerWeapon(bool bActive)
{
}
void AWeapon::ClientTempLowerWeapon(bool bActive)
{
}
void AWeapon::TempRaiseWeapon()
{
}
EUpperBodyAnim AWeapon::GetUpperBodyReadyAnim()
{
	return EUpperBodyAnim::UBANIM_NONE;
}
bool AWeapon::CheckJavelinTube()
{
	return false;
}
void AWeapon::NV()
{
}
void AWeapon::SetbTubeAttached(bool Tube)
{
}
bool AWeapon::CanLean()
{
	return true;
}
void AWeapon::AdjustAmmoRound()
{
}

float AWeapon::RangedAttackTime()
{
	return 0.0f;
}

bool AWeapon::RecommendRangedAttack()
{
	return false;
}

bool AWeapon::SplashDamage()
{
	return AmmoType->bSplashDamage;
}

float AWeapon::GetDamageRadius()
{
	return AmmoType->GetDamageRadius();
}

bool AWeapon::FocusOnLeader(bool bLeaderFiring)
{
	return false;
}

float AWeapon::RefireRate()
{
	return AmmoType->RefireRate;
}

bool AWeapon::RecommendSplashDamage()
{
	return AmmoType->bRecommendSplashDamage;
}
void AWeapon::FireHack(uint8 Mode)
{
}

bool AWeapon::IsFiring()
{
	//return Instigator != nullptr && Instigator.Controller != nullptr && Instigator.Controller.bFire != 0 || Instigator.Controller.bAltFire != 0;
	return false;    //FAKE   /ELiZ
}
void AWeapon::AdjustPlayerDamage(int32& Damage, APawn* instigatedBy, FVector HitLocation, FVector& Momentum, UaDamageType* DamageType)
{
}
void AWeapon::IncrementFlashCount()
{
}
void AWeapon::ForceReload()
{
}
void AWeapon::ServerForceReload()
{
	bForceReload=true;
}
void AWeapon::ClientForceReload()
{
	bForceReload=true;
	//GotoState('Reloading');
}

void AWeapon::DisplayDebug(class UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	FString t = "";
	FName Anim = "";
	float frame = 0;
	float Rate = 0;
	/*
	Canvas.SetDrawColor(0,255,0);
	Canvas.DrawText("WEAPON " + GetItemName(this));
	YPos += YL;
	Canvas.SetPos(4,YPos);
	t="     STATE: " + GetStateName() + " Timer: " + TimerCounter;
	if (Default.ReloadCount > 0)
	{
		t=t + " Reload Count: " + ReloadCount;
	}
	Canvas.DrawText(t,false);
	YPos += YL;
	Canvas.SetPos(4,YPos);
	if (DrawType == 8)
	{
		Canvas.DrawText("     StaticMesh " + StaticMesh + " AmbientSound " + AmbientSound,false);
	}
	else
	{
		Canvas.DrawText("     Mesh " + Mesh + " AmbientSound " + AmbientSound,false);
	}
	YPos += YL;
	Canvas.SetPos(4,YPos);
	if (Mesh != nullptr)
	{
		GetAnimParams(0,Anim,frame,Rate);
		t="     AnimSequence " + Anim + " Frame " + frame + " Rate " + Rate;
		if (bAnimByOwner)
		{
			t=t + " Anim by Owner";
		}
		Canvas.DrawText(t,false);
		YPos += YL;
		Canvas.SetPos(4,YPos);
	}
	if (GetCurrentAmmoType() == nullptr)
	{
		Canvas.DrawText("ERROR - NO AMMUNITION");
		YPos += YL;
		Canvas.SetPos(4,YPos);
	}
	else
	{
		GetCurrentAmmoType().DisplayDebug(Canvas,YL,YPos);
	}
	*/
}

void AWeapon::AttachToBack()
{
}

void AWeapon::TravelPostAccept()
{
	Super::TravelPostAccept();
	if (Cast<APawn>(GetOwner()) == nullptr)
	{
		return;
	}
	if (AmmoName != nullptr)
	{
		//AmmoType = Cast<AAmmunition>(Cast<APawn>(GetOwner())->FindInventoryType(AmmoName));
		if (AmmoType == nullptr)
		{
			//AmmoType=Spawn(AmmoName);
			//Cast<APawn>(GetOwner())->AddInventory(AmmoType);
			AmmoType->AmmoAmount=PickupAmmoCount;
			//AmmoType->GotoState("None");
		}
	}
	/*
	if (Cast<APawn>(GetOwner())->Weapon == this)
	{
		BringUp();
	}
	else
	{
		//GotoState("None");
	}
	*/
}

void AWeapon::SetAITarget(AActor* t)
{
}

void AWeapon::Destroyed()
{
	Super::Destroyed();
	/*
	if (Cast<APawn>(GetOwner()) != nullptr && Pawn(GetOwner())->Weapon == this)
	{
		Cast<APawn>(GetOwner())->Weapon=nullptr;
	}
	*/
}

void AWeapon::GiveTo(APawn* Other, APickup* Pickup)
{
	Super::GiveTo(Other, Pickup);
	bTossedOut=false;
	//Instigator=Other;
	GiveAmmo(Other);
	ClientWeaponSet(true);
}

void AWeapon::RenderOverlays(UCanvas* Canvas, bool bWeaponAndAttachmentsOnly)
{
	FRotator newRot = FRotator(0,0,0);
	bool bPlayerOwner = false;
	int32 hand = 0;
	APlayerController* PlayerOwner = nullptr;
	float ScaledFlash = 0;
	/*
	if (bWeaponAndAttachmentsOnly == false)
	{
		DrawCrossHair(Canvas);
	}
	if (Instigator == nullptr)
	{
		return;
	}
	PlayerOwner=Cast<APlayerController>(Instigator.Controller);
	if (PlayerOwner != nullptr)
	{
		bPlayerOwner=true;
		hand=PlayerOwner.Handedness;
		if (hand == 2)
		{
			return;
		}
	}
	if (bMuzzleFlash && bDrawMuzzleFlash && MFTexture != nullptr)
	{
		if (bWeaponAndAttachmentsOnly == false)
		{
			if (! bSetFlashTime)
			{
				bSetFlashTime=true;
				FlashTime=GetWorld()->GetTimeSeconds() + FlashLength;
			}
			else
			{
				if (FlashTime < GetWorld()->GetTimeSeconds())
				{
					bMuzzleFlash=false;
				}
			}
			if (bMuzzleFlash)
			{
				ScaledFlash=0.5 * MuzzleFlashSize * MuzzleScale * Canvas.ClipX / 640;
				Canvas.SetPos(0.5 * Canvas.ClipX - ScaledFlash + Canvas.ClipX * hand * FlashOffsetX,0.5 * Canvas.ClipY - ScaledFlash + Canvas.ClipY * FlashOffsetY);
				DrawMuzzleFlash(Canvas);
			}
		}
	}
	else
	{
		bSetFlashTime=false;
	}
	if (bWeaponAndAttachmentsOnly == true)
	{
		SetActorLocation(Instigator.Location + Instigator.CalcDrawOffset(this));
		newRot=Instigator.GetViewRotation();
		if (hand == 0)
		{
			newRot.Roll=2 * Default.Rotation.Roll;
		}
		else
		{
			newRot.Roll=Default.Rotation.Roll * hand;
		}
		SetActorRotation(newRot);
		Canvas.DrawActor(this,false,False,DisplayFOV);
	}
	*/
}
void AWeapon::DrawCrossHair(UCanvas* Canvas)
{
	float XLength = 0;
	/*
	if (CrossHair == nullptr)
	{
		return;
	}
	XLength=32;
	Canvas.bNoSmooth=false;
	Canvas.SetPos(0.503 * Canvas.ClipX - XLength,0.504 * Canvas.ClipY - XLength);
	Canvas.Style=3;
	Canvas.SetDrawColor(255,255,255);
	Canvas.DrawTile(CrossHair,XLength,XLength,0,0,32,32);
	Canvas.bNoSmooth=true;
	Canvas.Style=Style;
	*/
}
void AWeapon::DrawMuzzleFlash(UCanvas* Canvas)
{
	float Scale = 0;
	float ULength = 0;
	float VLength = 0;
	float UStart = 0;
	float VStart = 0;
	/*
	Scale=MuzzleScale * Canvas.ClipX / 640;
	Canvas.Style=3;
	ULength=MFTexture.USize;
	if (FMath::FRand() < 0.5)
	{
		UStart=ULength;
		ULength=-1 * ULength;
	}
	VLength=MFTexture.VSize;
	if (FMath::FRand() < 0.5)
	{
		VStart=VLength;
		VLength=-1 * VLength;
	}
	Canvas.DrawTile(MFTexture,Scale * MFTexture.USize,Scale * MFTexture.VSize,UStart,VStart,ULength,VLength);
	Canvas.Style=1;
	*/
}

bool AWeapon::CanAttack(AActor* Other)
{
	float MaxDist = 0;
	float CheckDist = 0;
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	FVector projStart = FVector(0,0,0);
	AActor* HitActor = nullptr;
	/*
	if (Instigator == nullptr || Instigator.Controller == nullptr)
	{
		return false;
	}
	MaxDist=MaxRange;
	if (AmmoType.bInstantHit)
	{
		MaxDist=TraceDist;
	}
	if (VSize(Instigator.Location - Other.Location) > MaxDist)
	{
		return false;
	}
	if (! Instigator.Controller.LineOfSightTo(Other))
	{
		return false;
	}
	GetAxes(Instigator.Controller.Rotation,X,Y,Z);
	projStart=GetFireStart(X,Y,Z);
	Log("CanAttack()");
	if (AmmoType.bInstantHit)
	{
		HitActor=Trace(HitLocation,HitNormal,Other.Location + Other.CollisionHeight * FVector(0 0 0.7),projStart,true);
	}
	else
	{
		CheckDist=FClamp(AmmoType.ProjectileClass.Default.Speed,600,VSize(Other.Location - Location));
		HitActor=Trace(HitLocation,HitNormal,projStart + CheckDist * Normal(Other.Location + Other.CollisionHeight * FVector(0 0 0.7) - Location),projStart,true);
	}
	if (HitActor == nullptr || HitActor == Other || Pawn(HitActor) != nullptr && ! Instigator.Controller.SameTeamAs(Cast<APawn>(HitActor).Controller))
	{
		return true;
	}
	*/
	return false;
}

//return percent of full ammo(0 to 1 range)
float AWeapon::AmmoStatus()
{
	return AmmoType->AmmoAmount / AmmoType->MaxAmmo;
}
bool AWeapon::HasAmmo()
{
	return AmmoType->HasAmmo();
}
bool AWeapon::SplashJump()
{
	return false;
}
float AWeapon::GetRating()
{
	return RateSelf();
}
float AWeapon::RateSelf()
{
	/*
	if (! HasAmmo())
	{
		CurrentRating=-2;
	}
	else
	{
		if (Instigator.Controller == nullptr)
		{
			return 0;
		}
		else
		{
			CurrentRating=Instigator.Controller.RateWeapon(this);
		}
	}
	return CurrentRating;
	*/
	return 0.0;    //This is not the value, ELiZ
}
float AWeapon::GetAIRating()
{
	return AIRating;
}
float AWeapon::SuggestAttackStyle()
{
	return 0.0f;
}
float AWeapon::SuggestDefenseStyle()
{
	return 0.0f;
}
void AWeapon::ClientWeaponEvent(FName EventType)
{
}

bool AWeapon::HandlePickupQuery(APickup* Item)
{
	int32 OldAmmo = 0;
	int32 NewAmmo = 0;
	APawn* p = nullptr;
	/*
	if (Item.InventoryType == Class)
	{
		if (Cast<AWeaponPickup>(Item).bWeaponStay && Item.Inventory == nullptr || Item.Inventory.bTossedOut)
		{
			return true;
		}
		p=Pawn(GetOwner());
		if (AmmoType != nullptr)
		{
			OldAmmo=AmmoType.AmmoAmount;
			if (Item.Inventory != nullptr)
			{
				NewAmmo=Weapon(Item.Inventory).PickupAmmoCount;
			}
			else
			{
				NewAmmo=class<Weapon>(Item.InventoryType).Default.PickupAmmoCount;
			}
			if (AmmoType.AddAmmo(NewAmmo) && OldAmmo == 0 && p.Weapon.Class != Item.InventoryType)
			{
				ClientWeaponSet(true);
			}
		}
		Item.AnnouncePickup(Cast<APawn>(GetOwner()));
		return true;
	}
	if (Inventory == nullptr)
	{
		return false;
	}
	return Inventory.HandlePickupQuery(Item);
	*/
	return false;    //FAKE  /ELiZ
}

void AWeapon::SetHand(float hand)
{
}

void AWeapon::GetViewAxes(FVector& XAxis, FVector& YAxis, FVector& ZAxis)
{
	/*
	if (Instigator.Controller == nullptr)
	{
		GetAxes(Instigator.Rotation,XAxis,YAxis,ZAxis);
	}
	else
	{
		GetAxes(Instigator.Controller.Rotation,XAxis,YAxis,ZAxis);
	}
	*/
}

AWeapon* AWeapon::WeaponChange(uint8 F, bool bSilent)
{
	AWeapon* newWeapon = nullptr;
	/*
	if (InventoryGroup == F)
	{
		if (! AmmoType.HasAmmo())
		{
			if (Inventory == nullptr)
			{
				newWeapon=nullptr;
			}
			else
			{
				newWeapon=Inventory.WeaponChange(F,bSilent);
			}
			if (newWeapon == nullptr && Instigator.IsHumanControlled())
			{
				Instigator.ClientMessage(ItemName + MessageNoAmmo);
			}
			return newWeapon;
		}
		else
		{
			return this;
		}
	}
	else
	{
		if (Inventory == nullptr)
		{
			return nullptr;
		}
		else
		{
			return Inventory.WeaponChange(F,bSilent);
		}
	}
	*/
	return nullptr;    //FAKE  /ELiZ
}

AWeapon* AWeapon::PrevWeapon(AWeapon* CurrentChoice, AWeapon* CurrentWeapon)
{
	/*
	if (AmmoType.HasAmmo())
	{
		if (CurrentChoice == nullptr)
		{
			if (CurrentWeapon != Self)
			{
				CurrentChoice=Self;
			}
		}
		else
		{
			if (InventoryGroup == CurrentChoice.InventoryGroup)
			{
				if (InventoryGroup == CurrentWeapon.InventoryGroup)
				{
					if (GroupOffset < CurrentWeapon.GroupOffset && GroupOffset > CurrentChoice.GroupOffset)
					{
						CurrentChoice=Self;
					}
				}
				else
				{
					if (GroupOffset > CurrentChoice.GroupOffset)
					{
						CurrentChoice=Self;
					}
				}
			}
			else
			{
				if (InventoryGroup > CurrentChoice.InventoryGroup)
				{
					if (InventoryGroup < CurrentWeapon.InventoryGroup || CurrentChoice.InventoryGroup > CurrentWeapon.InventoryGroup)
					{
						CurrentChoice=Self;
					}
				}
				else
				{
					if (CurrentChoice.InventoryGroup > CurrentWeapon.InventoryGroup && InventoryGroup < CurrentWeapon.InventoryGroup)
					{
						CurrentChoice=Self;
					}
				}
			}
		}
	}
	if (Inventory == nullptr)
	{
		return CurrentChoice;
	}
	else
	{
		return Inventory.PrevWeapon(CurrentChoice,CurrentWeapon);
	}
	*/
	return nullptr;    //FAKE  /ELiZ
}
AWeapon* AWeapon::NextWeapon(AWeapon* CurrentChoice, AWeapon* CurrentWeapon)
{
	/*
	if (AmmoType.HasAmmo())
	{
		if (CurrentChoice == nullptr)
		{
			if (CurrentWeapon != Self)
			{
				CurrentChoice=Self;
			}
		}
		else
		{
			if (InventoryGroup == CurrentChoice.InventoryGroup)
			{
				if (InventoryGroup == CurrentWeapon.InventoryGroup)
				{
					if (GroupOffset > CurrentWeapon.GroupOffset && GroupOffset < CurrentChoice.GroupOffset)
					{
						CurrentChoice=Self;
					}
				}
				else
				{
					if (GroupOffset < CurrentChoice.GroupOffset)
					{
						CurrentChoice=Self;
					}
				}
			}
			else
			{
				if (InventoryGroup < CurrentChoice.InventoryGroup)
				{
					if (InventoryGroup > CurrentWeapon.InventoryGroup || CurrentChoice.InventoryGroup < CurrentWeapon.InventoryGroup)
					{
						CurrentChoice=Self;
					}
				}
				else
				{
					if (CurrentChoice.InventoryGroup < CurrentWeapon.InventoryGroup && InventoryGroup > CurrentWeapon.InventoryGroup)
					{
						CurrentChoice=Self;
					}
				}
			}
		}
	}
	if (Inventory == nullptr)
	{
		return CurrentChoice;
	}
	else
	{
		return Inventory.NextWeapon(CurrentChoice,CurrentWeapon);
	}
	*/
	return nullptr;    //FAKE  /ELiZ
}

void AWeapon::AnimEnd(int32 Channel)
{
	if (GetNetMode() == ENetMode::NM_Client)
	{
		PlayIdleAnim();
	}
}
void AWeapon::GiveAmmo(APawn* Other)
{
	/*
	if (AmmoName == nullptr)
	{
		return;
	}
	AmmoType=Cast<AAmmunition>(Other.FindInventoryType(AmmoName));
	if (AmmoType != nullptr)
	{
		AmmoType.AddAmmo(PickupAmmoCount);
	}
	else
	{
		AmmoType=Spawn(AmmoName);
		Other.AddInventory(AmmoType);
		AmmoType.AmmoAmount=PickupAmmoCount;
	}
	*/
}

float AWeapon::SwitchPriority()
{
	/*
	if (! Instigator.IsHumanControlled())
	{
		return RateSelf();
	}
	else
	{
		if (! AmmoType.HasAmmo())
		{
			if (Cast<APawn>(GetOwner())->Weapon == this)
			{
				return -0.5;
			}
			else
			{
				return -1;
			}
		}
		else
		{
			return Default.AutoSwitchPriority;
		}
	}
	*/
	return 0;   //FAKE  /ELiZ
}

void AWeapon::ClientWeaponSet(bool bOptionalSet)
{
}

AWeapon* AWeapon::RecommendWeapon(float& rating)
{
	AWeapon* Recommended = nullptr;
	float oldRating =0 ;
	/*
	if (Instigator.IsHumanControlled())
	{
		rating=SwitchPriority();
	}
	else
	{
		rating=RateSelf();
		if (Self == Instigator.Weapon && Instigator.Controller.Enemy != nullptr && AmmoType.HasAmmo())
		{
			rating += 0.21;
		}
		rating += Instigator.Controller.WeaponPreference(this);
	}
	if (Inventory != nullptr)
	{
		Recommended=Inventory.RecommendWeapon(oldRating);
		if (Recommended != nullptr && oldRating > rating)
		{
			rating=oldRating;
			return Recommended;
		}
	}
	*/
	return this;
}

APickup* AWeapon::DropFrom(FVector StartLocation, bool bAttach)
{
	/*
	AIRating=Default.AIRating;
	bMuzzleFlash=false;
	if (AmmoType != nullptr)
	{
		PickupAmmoCount=AmmoType.AmmoAmount;
	}
	return DropFrom(StartLocation,bAttach);
	*/
	return nullptr;    //FAKE   /ELiZ
}

bool AWeapon::RepeatFire()
{
	return bRapidFire;
}
void AWeapon::ServerStopFiring()
{
	//StopFiringTime=GetWorld()->GetTimeSeconds();
}
void AWeapon::ServerRapidFire()
{
	/*
	ServerFire();
	if (IsInState('NormalFire'))
	{
		StopFiringTime=GetWorld()->GetTimeSeconds() + 0.6;
	}
	*/
}
void AWeapon::ServerFire(bool bNoAdjustAim, bool bRapid, bool bBreatheBonus)
{
	/*
	if (AmmoType == nullptr)
	{
		Log("WARNING " + this + " HAS NO AMMO!!!");
		GiveAmmo(Cast<APawn>(GetOwner()));
	}
	if (AmmoType.HasAmmo())
	{
		GotoState('NormalFire');
		ReloadCount --;
		if (AmmoType.bInstantHit)
		{
			TraceFire(TraceAccuracy,0,0);
		}
		else
		{
			ProjectileFire();
		}
		LocalFire();
	}
	*/
}
void AWeapon::Fire(float Value)
{
	/*
	if (! AmmoType->HasAmmo())
	{
		return;
	}
	if (! RepeatFire())
	{
		ServerFire();
	}
	else
	{
		if (StopFiringTime < GetWorld()->GetTimeSeconds + 0.3)
		{
			StopFiringTime= GetWorld()->GetTimeSeconds + 0.6;
			ServerRapidFire();
		}
	}
	if (Role < 4)
	{
		ReloadCount --;
		LocalFire();
		//GotoState('ClientFiring');
	}
	*/
}
void AWeapon::NPC_Fire(float Value, APawn* Enemy)
{
	/*
	bRapidFire=false;
	if (! AmmoType.HasAmmo())
	{
		return;
	}
	if (! RepeatFire())
	{
		ServerFire();
	}
	else
	{
		if (StopFiringTime < GetWorld()->GetTimeSeconds() + 0.3)
		{
			StopFiringTime=GetWorld()->GetTimeSeconds() + 0.6;
			ServerRapidFire();
		}
	}
	if (Role < 4)
	{
		ReloadCount --;
		LocalFire();
		GotoState('ClientFiring');
	}
	*/
}
void AWeapon::LocalFire()
{
}
void AWeapon::ServerAltFire()
{
	/*
	if (! IsInState('Idle'))
	{
		GotoState('Idle');
	}
	*/
}
void AWeapon::AltFire(float Value)
{
	/*
	if (! IsInState('Idle'))
	{
		GotoState('Idle');
	}
	ServerAltFire();
	*/
}
void AWeapon::PlayFiring()
{
}
FVector AWeapon::GetFireStart(FVector X, FVector Y, FVector Z)
{
	//return Instigator.Location + Instigator.EyePosition() + FireOffset.X * X + FireOffset.Y * Y + FireOffset.Z * Z;
	return FVector(0, 0, 0);    //FAKE   /ELiZ
}
void AWeapon::ProjectileFire()
{
	FVector Start = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	/*
	Owner.MakeNoise(1);
	GetAxes(Instigator.GetViewRotation(),X,Y,Z);
	Log("Projectile Fire()");
	Start=GetFireStart(X,Y,Z);
	AdjustedAim=Instigator.AdjustAim(AmmoType,Start,aimerror);
	_Projectile=AmmoType.SpawnProjectile(Start,AdjustedAim);
	*/
}
void AWeapon::NPC_ProjectileFire()
{
	FVector Start = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0,0,0);
	/*
	Owner.MakeNoise(1);
	GetAxes(Instigator.GetViewRotation(),X,Y,Z);
	Log("NPC_Projectile Fire()");
	Start=GetFireStart(X,Y,Z);
	AdjustedAim=Instigator.AdjustAim(AmmoType,Start,aimerror);
	_Projectile=AmmoType.SpawnProjectile(Start,AdjustedAim);
	*/
}

void AWeapon::TraceFire(float Accuracy, float YOffset, float ZOffset)
{
}

bool AWeapon::NeedsToReload()
{
	return bForceReload || GetDefault<AWeapon>()->ReloadCount > 0 && ReloadCount == 0;
}

bool AWeapon::BotFire(bool bFinished, FName FiringMode)
{
	/*
	if (! bFinished && ! IsIdle())
	{
		return false;
	}
	Instigator.Controller.bFire=1;
	Instigator.Controller.bAltFire=0;
	if (! RepeatFire())
	{
		Global.BroadcastHandler();
	}
	else
	{
		if (StopFiringTime < GetWorld()->GetTimeSeconds() + 0.3)
		{
			StopFiringTime=GetWorld()->GetTimeSeconds() + 0.6;
			Global.str();
		}
	}
	*/
	return true;
}
bool AWeapon::IsIdle()
{
	return false;
}

void AWeapon::Finish()
{
	bool bForce = false;
	bool bForceAlt = false;
	/*
	if (NeedsToReload() && AmmoType.HasAmmo())
	{
		GotoState('Reloading');
		return;
	}
	bForce=bForceFire;
	bForceAlt=bForceAltFire;
	bForceFire=false;
	bForceAltFire=false;
	if (bChangeWeapon)
	{
		GotoState('DownWeapon');
		return;
	}
	if (Instigator == nullptr || Instigator.Controller == nullptr)
	{
		GotoState("None");
		return;
	}
	if (! Instigator.IsHumanControlled())
	{
		if (! AmmoType.HasAmmo())
		{
			Instigator.Controller.SwitchToBestWeapon();
			if (bChangeWeapon)
			{
				GotoState('DownWeapon');
			}
			else
			{
				GotoState('Idle');
			}
			return;
		}
		if (Cast<AAIController>(Instigator.Controller) != nullptr)
		{
			if (! AIController(Instigator.Controller).WeaponFireAgain(AmmoType.RefireRate,True))
			{
				if (bChangeWeapon)
				{
					GotoState('DownWeapon');
				}
				else
				{
					GotoState('Idle');
				}
			}
			return;
		}
	}
	if (! AmmoType.HasAmmo() && Instigator.IsLocallyControlled())
	{
		SwitchToWeaponWithAmmo();
		return;
	}
	if (Instigator.Weapon != Self)
	{
		GotoState('Idle');
	}
	else
	{
		if (StopFiringTime > GetWorld()->GetTimeSeconds() || bForce || Instigator.PressingFire())
		{
			Global.BroadcastHandler();
		}
		else
		{
			if (bForceAlt || Instigator.PressingAltFire())
			{
				CauseAltFire();
			}
			else
			{
				GotoState('Idle');
			}
		}
	}
	*/
}
void AWeapon::SwitchToWeaponWithAmmo()
{
	/*
	Instigator.Controller.SwitchToBestWeapon();
	if (bChangeWeapon)
	{
		GotoState('DownWeapon');
		return;
	}
	else
	{
		GotoState('Idle');
	}
	*/
}
void AWeapon::CauseAltFire()
{
	//Global.InventoryAttachment();
}
void AWeapon::ClientFinish()
{
	/*
	if (Instigator == nullptr || Instigator.Controller == nullptr)
	{
		GotoState("None");
		return;
	}
	if (NeedsToReload() && AmmoType.HasAmmo())
	{
		GotoState('Reloading');
		return;
	}
	if (! AmmoType.HasAmmo())
	{
		Instigator.Controller.SwitchToBestWeapon();
		if (! bChangeWeapon)
		{
			PlayIdleAnim();
			GotoState('Idle');
			return;
		}
	}
	if (bChangeWeapon)
	{
		GotoState('DownWeapon');
	}
	else
	{
		if (Instigator.PressingFire())
		{
			Global.CollisionRadius(0);
		}
		else
		{
			if (Instigator.PressingAltFire())
			{
				Global._bDebug(0);
			}
			else
			{
				PlayIdleAnim();
				GotoState('Idle');
			}
		}
	}
	*/
}

void AWeapon::CheckAnimating()
{
}

void AWeapon::ImmediateStopFire()
{
}

void AWeapon::BringUp()
{
	/*
	if (Instigator.IsHumanControlled())
	{
		SetHand(Cast<APlayerController>(Instigator.Controller).Handedness);
	}
	bWeaponUp=false;
	PlaySelect();
	GotoState('Active');
	*/
}
bool AWeapon::PutDown()
{
	bChangeWeapon=true;
	return true;
}
void AWeapon::TweenDown()
{
	FName Anim = "";
	float frame = 0;
	float Rate = 0;
	/*
	if (IsAnimating() && AnimIsInGroup(0,'Select'))
	{
		GetAnimParams(0,Anim,frame,Rate);
		TweenAnim(Anim,frame * 0.4);
	}
	else
	{
		PlayAnim('Down',1,0.05);
	}
	*/
}
void AWeapon::PlayReloading()
{
	//AnimEnd(0);
}
void AWeapon::PlaySelect()
{
	bForceFire = false;
	bForceAltFire = false;
	/*
	if (! IsAnimating() || ! AnimIsInGroup(0,'Select'))
	{
		PlayAnim('Select',1,0);
	}
	Owner.PlaySound(SelectSound,1,1);
	*/
}
void AWeapon::PlayPostSelect()
{
	/*
	GotoState('Idle');
	AnimEnd(0);
	*/
}

void AWeapon::PlayIdleAnim()
{
}

TSubclassOf<class AAmmunition> AWeapon::GetCurrentAmmoName()
{
	return AmmoName;
}

// ======================================================================================
// AGP function - GetCurrentAmmoType
// Returns the current pointer for inventory ammunition - getter function to allow for 
// auxillary ammo types
// output:	Ammunition current inventory ammunition object being used
// last modified by:  superville 02/07/02
// ======================================================================================
AAmmunition* AWeapon::GetCurrentAmmoType()
{
	return AmmoType;
}

void AWeapon::SetCurrentAmmoType(AAmmunition* newAmmoType)
{
	//AmmoType=newAmmoType;
}

void AWeapon::SetCurrentAmmoName(AAmmunition* newAmmoName)
{
	////AmmoName=newAmmoName;
}

void AWeapon::NotifyAddAmmo(AAmmunition* NewAmmo)
{
	
	if (NewAmmo->GetClass() == AmmoName && NewAmmo->AmmoAmount > 0)
	{
		AmmoMagCount ++;
	}
	
}

void AWeapon::NotifyDeleteAmmo(AAmmunition* OldAmmo)
{
	/*
	if (OldAmmo.Class == AmmoName)
	{
		AmmoMagCount --;
	}
	*/
}
void AWeapon::RecountAmmo()
{
}

int32 AWeapon::GetClipCount(uint8 clip, bool bAuxAmmo)
{
	return 0;
}

bool AWeapon::CheckForNoReload()
{
	return false;   //Fake ELiZ
}

uint8 AWeapon::GetBestClip()
{
	return 0;
}

void AWeapon::ReloadClip(uint8 newclip)
{
}

bool AWeapon::ShowProjectileView()
{
	return false;
}

void AWeapon::ProjectileCalcView(AActor*& ViewActor, FVector& CameraLocation, FRotator& CameraRotation)
{
}
