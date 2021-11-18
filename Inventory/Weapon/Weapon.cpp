// All the original content belonged to the US Army


#include "Weapon.h"
#include "AA29/InventoryAttachment/WeaponAttachment/WeaponAttachment.h"
#include "AA29/Inventory/Ammunition/Ammunition.h"

AWeapon::AWeapon()
{
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
	//bReplicateInstigator = True
}


void AWeapon::BeginPlay()
{
	Super::BeginPlay();
}


void AWeapon::CanCombatRoll(bool bActual)
{
}
bool AWeapon::CanSprint()
{
	return false;			//Fake /ELiZ
}
bool AWeapon::IsBusy()
{
	return false;
}
bool AWeapon::CanUseWeapon(int DesiredAction)
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

void AWeapon::CalcZoomWander()
{
}

void AWeapon::GetSupportIcon()
{
	/*
		if (tSupportIcon == NULL)
		{
			Return Texture(IconMaterial);
		}
		else
		{
			Return tSupportIcon;
		}
	*/
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
void AWeapon::GetUpperBodyReadyAnim()
{
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
void AWeapon::IsFiring()
{
	/*
	Return Instigator != None && Instigator.Controller != None && Instigator.Controller.bFire != 0 || Instigator.Controller.bAltFire != 0;
	*/
}
void AWeapon::AdjustPlayerDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* DamageType)
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
	/*
		GotoState('Reloading');
	*/
}
/*
void AWeapon::DisplayDebug(UCanvas* Canvas, float YL, float YPos)
{
		local string t;
		local name Anim;
		local float frame;
		local float Rate;
		Canvas.SetDrawColor(0,255,0);
		Canvas.DrawText("WEAPON " $ GetItemName(Self));
		YPos += YL;
		Canvas.SetPos(4,YPos);
		t="     STATE: " $ GetStateName() $ " Timer: " $ TimerCounter;
		if (Default.ReloadCount > 0)
		{
			t=t $ " Reload Count: " $ ReloadCount;
		}
		Canvas.DrawText(t,False);
		YPos += YL;
		Canvas.SetPos(4,YPos);
		if (DrawType == 8)
		{
			Canvas.DrawText("     StaticMesh " $ StaticMesh $ " AmbientSound " $ AmbientSound,False);
		}
		else
		{
			Canvas.DrawText("     Mesh " $ Mesh $ " AmbientSound " $ AmbientSound,False);
		}
		YPos += YL;
		Canvas.SetPos(4,YPos);
		if (Mesh != None)
		{
			GetAnimParams(0,Anim,frame,Rate);
			t="     AnimSequence " $ Anim $ " Frame " $ frame $ " Rate " $ Rate;
			if (bAnimByOwner)
			{
				t=t $ " Anim by Owner";
			}
			Canvas.DrawText(t,False);
			YPos += YL;
			Canvas.SetPos(4,YPos);
		}
		if (GetCurrentAmmoType() == None)
		{
			Canvas.DrawText("ERROR - NO AMMUNITION");
			YPos += YL;
			Canvas.SetPos(4,YPos);
		}
		else
		{
			GetCurrentAmmoType().DisplayDebug(Canvas,YL,YPos);
		}
}
*/

void AWeapon::AttachToBack()
{
}
void AWeapon::TravelPostAccept()
{
	/*
		TravelPostAccept();
		if (Pawn(Owner) == None)
		{
			Return;
		}
		if (AmmoName != None)
		{
			AmmoType=Ammunition(Pawn(Owner).FindInventoryType(AmmoName));
			if (AmmoType == None)
			{
				AmmoType=Spawn(AmmoName);
				Pawn(Owner).AddInventory(AmmoType);
				AmmoType.AmmoAmount=PickupAmmoCount;
				AmmoType.GotoState('None');
			}
		}
		if (Self == Pawn(Owner).Weapon)
		{
			BringUp();
		}
		else
		{
			GotoState('None');
		}
	*/
}
void AWeapon::SetAITarget(AActor* t)
{
}
/*
void AWeapon::Destroyed()
{
	Super::Destroyed();
		if (Pawn(Owner) != None && Pawn(Owner).Weapon == Self)
		{
			Pawn(Owner).Weapon=None;
		}
}
*/
void AWeapon::GiveTo(APawn* Other, APickup* Pickup)
{
	/*
		GiveTo(Other);
		bTossedOut=False;
		Instigator=Other;
		GiveAmmo(Other);
		ClientWeaponSet(True);
	*/
}
void AWeapon::RenderOverlays(UCanvas* Canvas, bool bWeaponAndAttachmentsOnly)
{
	/*
		local Object.Rotator newRot;
		local bool bPlayerOwner;
		local int hand;
		local PlayerController PlayerOwner;
		local float ScaledFlash;
		if (bWeaponAndAttachmentsOnly == false)
		{
			DrawCrossHair(Canvas);
		}
		if (Instigator == None)
		{
			Return;
		}
		PlayerOwner=PlayerController(Instigator.Controller);
		if (PlayerOwner != None)
		{
			bPlayerOwner=True;
			hand=PlayerOwner.Handedness;
			if (hand == 2)
			{
				Return;
			}
		}
		if (bMuzzleFlash && bDrawMuzzleFlash && MFTexture != None)
		{
			if (bWeaponAndAttachmentsOnly == false)
			{
				if (! bSetFlashTime)
				{
					bSetFlashTime=True;
					FlashTime=GetWorld()->GetTimeSeconds() + FlashLength;
				}
				else
				{
					if (FlashTime < GetWorld()->GetTimeSeconds())
					{
						bMuzzleFlash=False;
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
			bSetFlashTime=False;
		}
		if (bWeaponAndAttachmentsOnly == true)
		{
			SetLocation(Instigator.Location + Instigator.CalcDrawOffset(Self));
			newRot=Instigator.GetViewRotation();
			if (hand == 0)
			{
				newRot.Roll=2 * Default.Rotation.Roll;
			}
			else
			{
				newRot.Roll=Default.Rotation.Roll * hand;
			}
			SetRotation(newRot);
			Canvas.DrawActor(Self,False,False,DisplayFOV);
		}

	*/
}
void AWeapon::DrawCrossHair(UCanvas* Canvas)
{
	/*
		local float XLength;
		if (CrossHair == None)
		{
			Return;
		}
		XLength=32;
		Canvas.bNoSmooth=False;
		Canvas.SetPos(0.503 * Canvas.ClipX - XLength,0.504 * Canvas.ClipY - XLength);
		Canvas.Style=3;
		Canvas.SetDrawColor(255,255,255);
		Canvas.DrawTile(CrossHair,XLength,XLength,0,0,32,32);
		Canvas.bNoSmooth=True;
		Canvas.Style=Style;
	*/
}
void AWeapon::DrawMuzzleFlash(UCanvas* Canvas)
{
	/*
		local float Scale;
		local float ULength;
		local float VLength;
		local float UStart;
		local float VStart;
		Scale=MuzzleScale * Canvas.ClipX / 640;
		Canvas.Style=3;
		ULength=MFTexture.USize;
		if (FRand() < 0.5)
		{
			UStart=ULength;
			ULength=-1 * ULength;
		}
		VLength=MFTexture.VSize;
		if (FRand() < 0.5)
		{
			VStart=VLength;
			VLength=-1 * VLength;
		}
		Canvas.DrawTile(MFTexture,Scale * MFTexture.USize,Scale * MFTexture.VSize,UStart,VStart,ULength,VLength);
		Canvas.Style=1;
	*/
}
void AWeapon::CanAttack(AActor* Other)
{
	/*
		local float MaxDist;
		local float CheckDist;
		local FVector HitLocation;
		local FVector HitNormal;
		local FVector X;
		local FVector Y;
		local FVector Z;
		local FVector projStart;
		local Actor HitActor;
		if (Instigator == None || Instigator.Controller == None)
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
			HitActor=Trace(HitLocation,HitNormal,Other.Location + Other.CollisionHeight * vect(0 0 0.7),projStart,True);
		}
		else
		{
			CheckDist=FClamp(AmmoType.ProjectileClass.Default.Speed,600,VSize(Other.Location - Location));
			HitActor=Trace(HitLocation,HitNormal,projStart + CheckDist * Normal(Other.Location + Other.CollisionHeight * vect(0 0 0.7) - Location),projStart,True);
		}
		if (HitActor == None || HitActor == Other || Pawn(HitActor) != None && ! Instigator.Controller.SameTeamAs(Pawn(HitActor).Controller))
		{
			return true;
		}
		return false;
	*/
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
			if (Instigator.Controller == None)
			{
				Return 0;
			}
			else
			{
				CurrentRating=Instigator.Controller.RateWeapon(Self);
			}
		}
		Return CurrentRating;
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
void AWeapon::HandlePickupQuery(APickup* Item)
{
	/*
		local int OldAmmo;
		local int NewAmmo;
		local Pawn p;
		if (Item.InventoryType == Class)
		{
			if (WeaponPickup(Item).bWeaponStay && Item.Inventory == None || Item.Inventory.bTossedOut)
			{
				return true;
			}
			p=Pawn(Owner);
			if (AmmoType != None)
			{
				OldAmmo=AmmoType.AmmoAmount;
				if (Item.Inventory != None)
				{
					NewAmmo=Weapon(Item.Inventory).PickupAmmoCount;
				}
				else
				{
					NewAmmo=class<Weapon>(Item.InventoryType).Default.PickupAmmoCount;
				}
				if (AmmoType.AddAmmo(NewAmmo) && OldAmmo == 0 && p.Weapon.Class != Item.InventoryType)
				{
					ClientWeaponSet(True);
				}
			}
			Item.AnnouncePickup(Pawn(Owner));
			return true;
		}
		if (Inventory == None)
		{
			return false;
		}
		Return Inventory.HandlePickupQuery(Item);
	*/
}
void AWeapon::SetHand(float hand)
{
}
void AWeapon::GetViewAxes(FVector XAxis, FVector YAxis, FVector ZAxis)
{
	/*
		if (Instigator.Controller == None)
		{
			GetAxes(Instigator.Rotation,XAxis,YAxis,ZAxis);
		}
		else
		{
			GetAxes(Instigator.Controller.Rotation,XAxis,YAxis,ZAxis);
		}
	*/
}
void AWeapon::WeaponChange(uint8 F, bool bSilent)
{
	/*
		local Weapon newWeapon;
		if (InventoryGroup == F)
		{
			if (! AmmoType.HasAmmo())
			{
				if (Inventory == None)
				{
					newWeapon=None;
				}
				else
				{
					newWeapon=Inventory.WeaponChange(F,bSilent);
				}
				if (newWeapon == None && Instigator.IsHumanControlled())
				{
					Instigator.ClientMessage(ItemName $ MessageNoAmmo);
				}
				Return newWeapon;
			}
			else
			{
				Return Self;
			}
		}
		else
		{
			if (Inventory == None)
			{
				Return None;
			}
			else
			{
				Return Inventory.WeaponChange(F,bSilent);
			}
		}
	*/
}
void AWeapon::PrevWeapon(AWeapon* CurrentChoice, AWeapon* CurrentWeapon)
{
	/*
		if (AmmoType.HasAmmo())
		{
			if (CurrentChoice == None)
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
		if (Inventory == None)
		{
			Return CurrentChoice;
		}
		else
		{
			Return Inventory.PrevWeapon(CurrentChoice,CurrentWeapon);
		}
	*/
}
void AWeapon::NextWeapon(AWeapon* CurrentChoice, AWeapon* CurrentWeapon)
{
	/*
		if (AmmoType.HasAmmo())
		{
			if (CurrentChoice == None)
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
		if (Inventory == None)
		{
			Return CurrentChoice;
		}
		else
		{
			Return Inventory.NextWeapon(CurrentChoice,CurrentWeapon);
		}
	*/
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
		if (AmmoName == None)
		{
			Return;
		}
		AmmoType=Ammunition(Other.FindInventoryType(AmmoName));
		if (AmmoType != None)
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
void AWeapon::SwitchPriority()
{
	/*
		if (! Instigator.IsHumanControlled())
		{
			Return RateSelf();
		}
		else
		{
			if (! AmmoType.HasAmmo())
			{
				if (Pawn(Owner).Weapon == Self)
				{
					Return -0.5;
				}
				else
				{
					Return -1;
				}
			}
			else
			{
				Return Default.AutoSwitchPriority;
			}
		}
	*/
}
void AWeapon::ClientWeaponSet(bool bOptionalSet)
{
}
void AWeapon::RecommendWeapon(float rating)
{
	/*
		local Weapon Recommended;
		local float oldRating;
		if (Instigator.IsHumanControlled())
		{
			rating=SwitchPriority();
		}
		else
		{
			rating=RateSelf();
			if (Self == Instigator.Weapon && Instigator.Controller.Enemy != None && AmmoType.HasAmmo())
			{
				rating += 0.21;
			}
			rating += Instigator.Controller.WeaponPreference(Self);
		}
		if (Inventory != None)
		{
			Recommended=Inventory.RecommendWeapon(oldRating);
			if (Recommended != None && oldRating > rating)
			{
				rating=oldRating;
				Return Recommended;
			}
		}
		Return Self;
	*/
}
void AWeapon::DropFrom(FVector StartLocation, bool bAttach)
{
	/*
		AIRating=Default.AIRating;
		bMuzzleFlash=False;
		if (AmmoType != None)
		{
			PickupAmmoCount=AmmoType.AmmoAmount;
		}
		Return DropFrom(StartLocation,bAttach);
	*/
}
bool AWeapon::RepeatFire()
{
	return bRapidFire;
}
void AWeapon::ServerStopFiring()
{
	/*
	StopFiringTime=GetWorld()->GetTimeSeconds();
	*/
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
		if (AmmoType == None)
		{
			Log("WARNING " $ Self $ " HAS NO AMMO!!!");
			GiveAmmo(Pawn(Owner));
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
		bRapidFire=False;
		if (! AmmoType.HasAmmo())
		{
			Return;
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
void AWeapon::GetFireStart(FVector X, FVector Y, FVector Z)
{
	/*
	Return Instigator.Location + Instigator.EyePosition() + FireOffset.X * X + FireOffset.Y * Y + FireOffset.Z * Z;
	*/
}
void AWeapon::ProjectileFire()
{
	/*
		local FVector Start;
		local FVector X;
		local FVector Y;
		local FVector Z;
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
	/*
		local FVector Start;
		local FVector X;
		local FVector Y;
		local FVector Z;
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
void AWeapon::NeedsToReload()
{
	/*
	Return bForceReload || Default.ReloadCount > 0 && ReloadCount == 0;
	*/
}
void AWeapon::BotFire(bool bFinished, FName FiringMode)
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
		return true;
	*/
}
bool AWeapon::IsIdle()
{
	return false;
}
void AWeapon::Finish()
{
	/*
		local bool bForce;
		local bool bForceAlt;
		if (NeedsToReload() && AmmoType.HasAmmo())
		{
			GotoState('Reloading');
			Return;
		}
		bForce=bForceFire;
		bForceAlt=bForceAltFire;
		bForceFire=False;
		bForceAltFire=False;
		if (bChangeWeapon)
		{
			GotoState('DownWeapon');
			Return;
		}
		if (Instigator == None || Instigator.Controller == None)
		{
			GotoState('None');
			Return;
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
				Return;
			}
			if (AIController(Instigator.Controller) != None)
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
				Return;
			}
		}
		if (! AmmoType.HasAmmo() && Instigator.IsLocallyControlled())
		{
			SwitchToWeaponWithAmmo();
			Return;
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
			Return;
		}
		else
		{
			GotoState('Idle');
		}
	*/
}
void AWeapon::CauseAltFire()
{
	/*
	Global.InventoryAttachment();
	*/
}
void AWeapon::ClientFinish()
{
	/*
		if (Instigator == None || Instigator.Controller == None)
		{
			GotoState('None');
			Return;
		}
		if (NeedsToReload() && AmmoType.HasAmmo())
		{
			GotoState('Reloading');
			Return;
		}
		if (! AmmoType.HasAmmo())
		{
			Instigator.Controller.SwitchToBestWeapon();
			if (! bChangeWeapon)
			{
				PlayIdleAnim();
				GotoState('Idle');
				Return;
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
			SetHand(PlayerController(Instigator.Controller).Handedness);
		}
		bWeaponUp=False;
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
	/*
		local name Anim;
		local float frame;
		local float Rate;
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
	/*
	AnimEnd(0);
	*/
}
void AWeapon::PlaySelect()
{
	/*
		bForceFire=False;
		bForceAltFire=False;
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
void AWeapon::ProjectileCalcView(AActor* ViewActor, FVector CameraLocation, FRotator CameraRotation)
{
}
