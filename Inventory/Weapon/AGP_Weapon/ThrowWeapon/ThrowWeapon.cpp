// All the original content belonged to the US Army


#include "ThrowWeapon.h"

AThrowWeapon::AThrowWeapon()
{
	_fMinFuseTime      = 4;
	_fAddFuseTime      = 1.5;
	PullSound          = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_Pull.WeaponsUS_Grenades_Pull"), NULL, LOAD_None, NULL);
	PullLowSound       = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_Lowpull.WeaponsUS_Grenades_Lowpull"), NULL, LOAD_None, NULL);
	PopSpoonSound      = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_Spoonpop.WeaponsUS_Grenades_Spoonpop"), NULL, LOAD_None, NULL);
	//cExplosionEmitter = Aem_bt_grenexplosion::StaticClass();
	//cExplosionDecal = Ade_bt_grenimpact::StaticClass();
	_fThrowSpeed       = 1145;
	_fThrowTime        = 0.2;
	_fTossSpeed        = 600;
	_fTossTime         = 0.2;
	InvGrenadeIndex    = 255;
	_bCanBeMiles       = false;
	SingleFire         = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_Throw.WeaponsUS_Grenades_Throw"), NULL, LOAD_None, NULL);
	SelectChargeSound  = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_SelectNew.WeaponsUS_Grenades_SelectNew"), NULL, LOAD_None, NULL);
	SelectSound        = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_SelectNew.WeaponsUS_Grenades_SelectNew"), NULL, LOAD_None, NULL);
	DisplayFOV         = 50;
	_bLarge            = false;
	bVirtualInventory  = true;
	PlayerViewOffset   = FVector(3, 75, -3);
	InitialState       = FName("Idle");
}



void AThrowWeapon::Destroyed()
{
	Super::Destroyed();
	PullSound=NULL;
	PullLowSound= NULL;
	BoomSound= NULL;
	PopSpoonSound= NULL;
	InstigatorController= NULL;
	_PickupPtr= NULL;
}
EUpperBodyAnim AThrowWeapon::GetUpperBodyLowerAnim()
{
	return EUpperBodyAnim::UBANIM_GREN_LowerGn;
}
EUpperBodyAnim AThrowWeapon::GetUpperBodyRaiseAnim()
{
	return EUpperBodyAnim::UBANIM_GREN_RaiseGn;
}
EUpperBodyAnim AThrowWeapon::GetUpperBodyReadyAnim()
{
	return EUpperBodyAnim::UBANIM_GREN_Ready;
}
void AThrowWeapon::Reload()
{
}
void AThrowWeapon::FixJam()
{
}
void AThrowWeapon::InitFor(AInventory* Inv)
{
}
void AThrowWeapon::SpawnAmmoFor(AAGP_Weapon* OldW, AAmmunition* oldA)
{
}
void AThrowWeapon::SpawnAndAttachMILESGear()
{
}
void AThrowWeapon::TempLowerWeapon(bool bActive)
{
	/*
		if (! IsLostSpoon() && ! IsPinPulled())
		{
			TempLowerWeapon(bActive);
		}
	*/
}
bool AThrowWeapon::IsPinPulled()
{
	return _bPulledPin;
}
bool AThrowWeapon::isHandsOnly()
{
	return IsPinPulled();
}
bool AThrowWeapon::IsLostSpoon()
{
	return _bLostSpoon;
}
bool AThrowWeapon::IsTossNotThrow()
{
	return _bTossNotThrow;
}
void AThrowWeapon::SetFuseTime(float Time)
{
	_FuseTime=Time;
	_FuseCounter=0;
}
void AThrowWeapon::Tick(float DeltaTime)
{
	if (_FuseTime > 0)
	{
		_FuseCounter += DeltaTime;
		if (_FuseCounter > _FuseTime)
		{
			BlowUp();
		}
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
		{
			UE_LOG(LogTemp, Log, TEXT("FUSECOUNTER %d TIME %d"), _FuseCounter, _FuseTime);
		}
	}
}
void AThrowWeapon::RecountAmmo()
{
	AmmoMagCount=0;
}
bool AThrowWeapon::ShouldDrawCrosshair()
{
	return false;
}
void AThrowWeapon::HandleLive(APawn* NewInstigator)
{
	//Instigator=NewInstigator;
	_bPulledPin=true;
	_bLostSpoon=true;
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
	{
		FString ObjectName = GetOwner()->GetName();
		UE_LOG(LogTemp, Log, TEXT("The %s is live!  Careful!"), *ObjectName);
	}
}
void AThrowWeapon::Finish()
{
	/*
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugWeaponState)
		{
			Log(Self @ "ThrowWeapon::Finish - Instigator" @ Instigator @ "Controller" @ Instigator.Controller);
		}
		if (Instigator == None || Instigator.Controller == None)
		{
			GotoState('None');
			Return;
		}
		if (_bLostSpoon)
		{
			GotoState('PickedUpLive');
		}
		else
		{
			GotoState('Idle');
		}
	*/
}
void AThrowWeapon::ClientFinish()
{
	/*
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugWeaponState)
		{
			Log(Self @ "ThrowWeapon::ClientFinish - Instigator" @ Instigator @ "Controller" @ Instigator.Controller);
		}
		if (Instigator == None || Instigator.Controller == None)
		{
			GotoState('None');
			Return;
		}
		if (_bLostSpoon)
		{
			GotoState('PickedUpLive');
		}
		else
		{
			GotoState('Idle');
		}
	*/
}
void AThrowWeapon::Fire(float Value)
{
	/*
		if (Instigator != None)
		{
			if (Instigator.Controller != None)
			{
				Log("----- " $ Instigator.Controller $ ".Location = " $ Instigator.Controller.Location $ " -----");
				if (PlayerController(Instigator.Controller) != None)
				{
					Log("----- " $ Instigator.Controller $ ".ViewTarget = " $ PlayerController(Instigator.Controller).ViewTarget $ " -----");
				}
			}
			Log("----- " $ Instigator $ ".Location = " $ Instigator.Location $ " -----");
		}
		*/
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
		{
			FString ObjectName = GetOwner()->GetName();
			UE_LOG(LogTemp, Log, TEXT("%s ThrowWeapon:Global::Fire"), *ObjectName);
		}
		/*
		if (AGP_Pawn(Instigator) != None && AGP_Pawn(Instigator)._FireMonitor != None)
		{
			AGP_Pawn(Instigator)._FireMonitor.Notify();
		}
		if (Instigator != None && Instigator.bIsSprinting || Instigator.bWantsToSprint)
		{
			Return;
		}
		ServerFire();
		if (GetNetMode() == ENetMode::NM_Client)
		{
			GotoState('PulledPin');
		}
	*/
}
void AThrowWeapon::ServerFire(bool bNoAdjustAim, bool bRapid, bool bBreatheBonus)
{
		UE_LOG(LogTemp, Warning, TEXT("ThrowWeapon::ServerFire()"));
		/*
		if (Instigator != None)
		{
			if (Instigator.Controller != None)
			{
				Log("----- " $ Instigator.Controller $ ".Location = " $ Instigator.Controller.Location $ " -----");
				if (PlayerController(Instigator.Controller) != None)
				{
					Log("----- " $ Instigator.Controller $ ".ViewTarget = " $ PlayerController(Instigator.Controller).ViewTarget $ " -----");
				}
			}
			Log("----- " $ Instigator $ ".Location = " $ Instigator.Location $ " -----");
		}
		if (Instigator != None && Instigator.bIsSprinting || Instigator.bWantsToSprint)
		{
			Return;
		}
		GotoState('PulledPin');
	*/
}
void AThrowWeapon::ServerThrow()
{
	/*
		local PlayerController PC;
		if (Instigator == None || Instigator.isDead())
		{
			DebugLog(DEBUG_Gren,"ThrowWeapon::ServerThrow()	Instigator is dead. Dropping should handle this.");
			Return;
		}
		_bPulledPin=True;
		GotoState('BusyFiring');
		PC=PlayerController(Instigator.Controller);
		if (Level.Game.Stats != None && PC != None && PC.PlayerStatsIndex >= 0)
		{
			Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredGrenade();
		}
	*/
}
void AThrowWeapon::DoChangeFireMode()
{
	_bTossNotThrow=! _bTossNotThrow;
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
	{
		UE_LOG(LogTemp, Log, TEXT("ThrowWeapon::DoChangeFireMode %s"), _bTossNotThrow ? TEXT("true") : TEXT("false"));
	}
}
void AThrowWeapon::PlayChangeFireMode()
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
	{
		UE_LOG(LogTemp, Log, TEXT("ThrowWeapon::PlayChangeFireMode Live %s Toss %s"),_bLostSpoon ? TEXT("true") : TEXT("false"), _bTossNotThrow ? TEXT("true") : TEXT("false"));
	}
	if (_bLostSpoon)
	{
		if (! _bTossNotThrow)
		{
			//RunAnimation('LiveHighToLow',1);
		}
		else
		{
			//RunAnimation('LiveLowToHigh',1);
		}
	}
	else
	{
		if (! _bTossNotThrow)
		{
			//RunAnimation('HighToLow',1);
		}
		else
		{
			//RunAnimation('LowToHigh',1);
		}
	}
}
void AThrowWeapon::BlowUp()
{
	/*
		local FVector HitLocation;
		local Actor HitActor;
		local GrenadeHelper GH;
		if (Level.Game.bGameEnded)
		{
			Return;
		}
		if (_PickupPtr != None)
		{
			HitActor=_PickupPtr;
			HitLocation=_PickupPtr.Location;
		}
		else
		{
			if (Instigator != None)
			{
				HitActor=Instigator;
				if (Instigator.bIsProne && Instigator.FrontAuxCyl != None)
				{
					HitLocation=Instigator.FrontAuxCyl.Location;
				}
				else
				{
					HitLocation=Instigator.GetBoneCoords('WeaponBone').Origin;
				}
			}
			else
			{
				DebugLog(DEBUG_Warn,"ThrowWeapon::BlowUp()	No Pickup/No Instigator. Don't know where to blow up!");
				GotoState('DestroyWeapon');
				Return;
			}
		}
		GH=Level.GetGrenadeHelper();
		GH.GrenHurtRadius(HitActor,HitLocation,_fDamageRadius,_fKillRadius,_fDamage,MyDamageType,FragDamageType,_fMomentum,DamageClasses,InstigatorController);
		GH.GrenadeEffects(HitActor,HitLocation,_fDamageRadius,_fKillRadius,_fEffectDuration,_fMaxAudIntensity,_fMaxVisIntensity);
		if (_PickupPtr != None)
		{
			_PickupPtr._bBlewUp=True;
		}
		else
		{
			if (cExplosionEmitter != None)
			{
				Spawn(cExplosionEmitter,,,HitLocation,rot(16384 0 0));
			}
			if (cExplosionDecal != None)
			{
				Spawn(cExplosionDecal,,,HitLocation,vect(0 0 -1));
			}
			PlaySound(BoomSound,3,1,True,1500,,True);
		}
		MakeNoise(_fHitNoise);
		_bBlewUp=True;
		_FuseTime=0;
		if (_PickupPtr == None)
		{
			if (cSmokeEmitter != None)
			{
				if (ThirdPersonActor != None)
				{
					ThirdPersonActor.Destroy();
					ThirdPersonActor=None;
				}
				SpawnPickup(True);
				_PickupPtr._bBlewUp=True;
				Instigator.TakeDamage(10,Instigator,Instigator.Location,vect(0 0 0),Class'Burned',,,Self);
			}
			if (Instigator.Weapon == Self)
			{
				Instigator.GrenadeThrow3p(Instigator.1);
				Instigator.DeleteInventory(Self);
				Instigator.PendingWeapon=None;
				Instigator.ChangedWeapon();
				if (GetNetMode() == ENetMode::NM_DedicatedServer)
				{
					ClientBlowUp();
				}
			}
		}
		GotoState('DestroyWeapon');
	*/
}
void AThrowWeapon::ClientBlowUp()
{
	/*
		_bBlewUp=True;
		Instigator.GrenadeThrow3p(Instigator.1);
	*/
}
void AThrowWeapon::GetFireStart(FVector X, FVector Y, FVector Z)
{
	//Return Instigator.EyePosition();
}
void AThrowWeapon::SpawnPickup(bool bDrop, AThrowWeaponPickup* SetPickupPtr)
{
	/*
		local FVector StartLoc;
		local FVector X;
		local FVector Y;
		local FVector Z;
		local float fpAdjustedThrowSpeed;
		local Object.Rotator rotTemp;
		if (Owner != None && AGP_Pawn(Owner) != None && AGP_Pawn(Owner).EventLab != None && EventLab == None)
		{
			EventLab=AGP_Pawn(Owner).EventLab;
		}
		if (_PickupPtr != None)
		{
			Return;
		}
		DebugLog(DEBUG_Gren,Self @ "ThrowWeapon:Thrown::SpawnPickup bDrop" @ bDrop @ "SetPickupPtr" @ SetPickupPtr);
		if (Instigator.Controller != None && Instigator.Controller.IsA('NPCBaseSoldierController'))
		{
			rotTemp=Instigator.GetViewRotation();
			rotTemp.Pitch=NPCBaseSoldierController(Instigator.Controller).GetGrenadePitch();
			GetAxes(rotTemp,X,Y,Z);
			DebugLog(DEBUG_Gren,Self @ "ThrowWeapon:Thrown::SpawnPickup for NPC rotation: (PRY): " $ rotTemp.Pitch $ "," $ rotTemp.Roll $ "," $ rotTemp.Yaw);
		}
		else
		{
			DebugLog(DEBUG_Gren,Self @ "ThrowWeapon:Thrown::SpawnPickup rotation: (PRY): " $ Instigator.GetViewRotation().Pitch $ "," $ Instigator.GetViewRotation().Roll $ "," $ Instigator.GetViewRotation().Yaw);
			GetAxes(Instigator.GetViewRotation(),X,Y,Z);
		}
		DebugLog(DEBUG_Gren,Self @ "ThrowWeapon:Thrown::SpawnPickup Instigator is: " $ Instigator);
		DebugLog(DEBUG_Gren,Self @ "ThrowWeapon:Thrown::SpawnPickup Axes/rotation: " $ X $ "," $ Y $ "," $ Z);
		if (Instigator.Controller != None && Instigator.Controller.IsA('NPCBaseController'))
		{
			StartLoc=MakeVect(Instigator.Location.X,Instigator.Location.Y,Instigator.Location.Z + 48);
			DebugLog(DEBUG_Gren,Self @ "ThrowWeapon:Thrown::SpawnPickup StartLoc set to instigator (pawn) location");
		}
		else
		{
			StartLoc=GetFireStart(X,Y,Z);
		}
		DebugLog(DEBUG_Gren,Self @ "ThrowWeapon:Thrown::SpawnPickup PickupClass: " $ PickupClass);
		DebugLog(DEBUG_Gren,Self @ "ThrowWeapon:Thrown::SpawnPickup Start location: " $ StartLoc.X $ "," $ StartLoc.Y $ "," $ StartLoc.Z);
		if (SetPickupPtr == None)
		{
			_PickupPtr=ThrowWeaponPickup(Spawn(PickupClass,Self,'None',StartLoc));
			_PickupPtr.bShowThreatenedNodes=bShowThreatenedNodes;
		}
		else
		{
			_PickupPtr=SetPickupPtr;
		}
		DebugLog(DEBUG_Gren,"ThrowWeapon::SpawnPickup() - Pickupptr is: " $ _PickupPtr);
		if (_PickupPtr != None)
		{
			_PickupPtr.InitDroppedPickupFor(Self);
			_PickupPtr.bAlwaysRelevant=True;
		}
		fpAdjustedThrowSpeed=_fThrowSpeed;
		if (Instigator.Controller != None && Instigator.Controller.IsA('NPCBaseController'))
		{
			fpAdjustedThrowSpeed += FRand() * 100;
		}
		if (EventLab != None)
		{
			_PickupPtr.SetEventLab(EventLab);
		}
		if (bDrop)
		{
			_PickupPtr.Velocity=VRand() * 200;
		}
		else
		{
			if (_bTossNotThrow)
			{
				_PickupPtr.Velocity=X * _fTossSpeed;
			}
			else
			{
				_PickupPtr.Velocity=X * fpAdjustedThrowSpeed;
			}
		}
		DebugLog(DEBUG_Gren,Self @ "ThrowWeapon::SpawnPickup Ptr" @ _PickupPtr @ "Vel" @ _PickupPtr.Velocity);
		if (_PickupPtr != None)
		{
			_PickupPtr.SetWeapon(Self);
			_PickupPtr.RandSpin(100000);
			if (Instigator.bIsCrouched)
			{
				_PickupPtr.Velocity *= 0.95;
			}
			else
			{
				if (Instigator.bIsProne)
				{
					_PickupPtr.Velocity *= 0.85;
				}
			}
		}
		DebugLog(DEBUG_Gren,Self @ "ThrowWeapon::SpawnPickup PulledPin" @ _bPulledPin @ "BlewUp" @ _bBlewUp @ "LostSpoon" @ _bLostSpoon);
		if (_bPulledPin && ! _bBlewUp && ! _bLostSpoon)
		{
			SetFuseTime(_fMinFuseTime + _fAddFuseTime * FRand());
			PlayOwnedSound(PopSpoonSound,1,0.5,False,60,,True,False);
		}
		if (_bPulledPin && Instigator.isDead())
		{
			SetFuseTime(_fMinFuseTime + _fAddFuseTime * FRand());
			PlayOwnedSound(PopSpoonSound,1,0.5,False,60,,True,False);
		}
		SetOwner(None);
	*/
}
void AThrowWeapon::TweenDown()
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
			if (_bPulledPin)
			{
				if (_bTossNotThrow)
				{
					RunAnimation('LiveLowDown',1,0.05);
				}
				else
				{
					RunAnimation('LiveDown',1,0.05);
				}
			}
			else
			{
				if (_bTossNotThrow)
				{
					RunAnimation('LowDown',1,0.05);
				}
				else
				{
					RunAnimation('Down',1,0.05);
				}
			}
		}
	*/
}
void AThrowWeapon::PlaySelect()
{
	/*
		local int RandNum;
		local name OutSeqName;
		local float OutAnimFrame;
		local float OutAnimRate;
		GetAnimParams(0,OutSeqName,OutAnimFrame,OutAnimRate);
		if (! IsAnimating() && ! AnimIsInGroup(0,'Select'))
		{
			if (_bPulledPin)
			{
				RunAnimation('LiveSelect',1);
			}
			else
			{
				if (_bTossNotThrow)
				{
					RunAnimation('LowSelect',1);
				}
				else
				{
					if (HasAnim('SelectB'))
					{
						RandNum=Rand(2);
						if (RandNum == 1)
						{
							RunAnimation('Select',1);
						}
						else
						{
							RunAnimation('SelectB',1);
						}
					}
					else
					{
						RunAnimation('Select',1);
					}
				}
			}
			PlayOwnedSound(SelectSound,1,0.5,False,60,,True,False);
		}
		else
		{
			if (IsAnimating() && OutSeqName == 'Still')
			{
				if (_bPulledPin)
				{
					RunAnimation('LiveSelect',1);
				}
				else
				{
					if (HasAnim('SelectB'))
					{
						RandNum=Rand(2);
						if (RandNum == 1)
						{
							RunAnimation('Select',1);
						}
						else
						{
							RunAnimation('SelectB',1);
						}
					}
					else
					{
						RunAnimation('Select',1);
					}
				}
				PlayOwnedSound(SelectSound,1,0.5,False,60,,True,False);
			}
		}
	*/
}
void AThrowWeapon::PlayIdleAnim()
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
	{
		UE_LOG(LogTemp, Log, TEXT("ThrowWeapon::PlayIdleAnim Toss %s Live %s"), _bTossNotThrow ? TEXT("true") : TEXT("false"), _bPulledPin ? TEXT("true") : TEXT("false"));
	}
	if (_bTossNotThrow)
	{
		if (_bPulledPin)
		{
			//RunAnimation('LiveLowStill',1,0.05,True);
		}
		else
		{
			//RunAnimation('LowIdle',1,0.05,True);
		}
	}
	else
	{
		if (_bPulledPin)
		{
			//RunAnimation('LiveStill',1,0.05,True);
		}
		else
		{
			//RunAnimation('Idle',1,0.05,True);
		}
	}
}
void AThrowWeapon::PlayFiring()
{
	/*
		if (AGP_Pawn(Instigator) != None)
		{
			AGP_Pawn(Instigator).NotifyThrow(Self,"THROWN");
		}
		if (_bTossNotThrow)
		{
			PlayAnim('LowFire');
			SetTimer(_fTossTime,False);
		}
		else
		{
			PlayAnim('Fire');
			SetTimer(_fThrowTime,False);
		}
		PlayOwnedSound(SingleFire,1,0.5,False,60,,True,False);
		if (_bTossNotThrow)
		{
			Instigator.GrenadeThrow3p(Instigator.8);
		}
		else
		{
			Instigator.GrenadeThrow3p(Instigator.7);
		}
	*/
}
void AThrowWeapon::StartCrawling()
{
	if (IsPinPulled())
	{
		return;
	}
	Super::StartCrawling();
}
