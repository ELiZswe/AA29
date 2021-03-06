// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/PistolWeapon/PistolWeapon.h"
#include "AA29/Object/Actor/BaseScope/BaseScope.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"
#include "AA29/Object/Actor/Inventory/InvContainer/InvContainer.h"

APistolWeapon::APistolWeapon()
{
	fpWeaponThreatLevel   = 7;
	TraceDist             = 9000;
	weaponType            = EWeaponType::WEAPON_Pistol;
	ReloadStanding3PAnim  = FName("StdSmRld_E");
	iMisFire              = 1500;
}

/*
simulated State BusyDryFiring extends busy
{
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "AGP_Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		if (bSlideBack)
		{
			bHammerForward=false;
		}
		PlayDryFire();
		if (! bSlideBack)
		{
			bDryFired=true;
		}
		if (bDryFired)
		{
			bHammerForward=true;
		}
	}
}
*/

/*
simulated State BusyTempDown
{
	simulated Function bool IsTempBusy()
	{
		return true;
	}
	simulated Function Fire(float Value)
	{
		if (_bActive)
		{
			Global.AgentController(Value);
		}
	}
	simulated Function AltFire(float Value)
	{
		if (_bActive)
		{
			Global.actionFailed(Value);
		}
	}
	simulated Function Reload()
	{
		if (_bActive)
		{
			Global.npcbcNew();
		}
	}
	simulated Function ChangeFireMode()
	{
		if (_bActive)
		{
			Global._cHUDFrame();
		}
	}
	simulated Function FixJam()
	{
		if (_bActive)
		{
			Global.CommoLocalMessage();
		}
	}
	simulated Function SetSupported(bool newSupported)
	{
		if (_bActive)
		{
			Global.BrowserGSPY(newSupported);
		}
	}
	simulated Function bool CheckForNoReload()
	{
		if (_bActive)
		{
			return Global.iNode();
		}
		else
		{
			return false;
		}
	}
	simulated Function bool ShouldDrawCrosshair()
	{
		if (_bActive)
		{
			return Global.Cmd();
		}
		else
		{
			return false;
		}
	}
	simulated Function bool CanUseWeapon(int32 DesiredAction)
	{
		if (_bActive)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	simulated Function bool CanZoom()
	{
		if (_bActive)
		{
			return ((_Scope != nullptr) && (eROF != AuxROF));
		}
		else
		{
			return false;
		}
	}
	simulated Function PlayIdleAnim()
	{
		if (IsZoomed())
		{
			DebugLog(DEBUG_Inv,"in busy temp down IsZoomed");
			if (OutOfAmmo() && bSlideBack)
			{
				RunAnimation(IdleEmptyAnim,1,0.05,true);
			}
			else
			{
				if ((OutOfAmmo() && (! bSlideBack)) && bHammerForward)
				{
					RunAnimation(IdleHammerFWAnim,1,0.05,true);
				}
				else
				{
					RunAnimation(IdleAnim,1,0.05,true);
				}
			}
			return;
		}
		if (_bActive)
		{
			DebugLog(DEBUG_Inv,"in busy temp down _bactive");
			if (OutOfAmmo() && bSlideBack)
			{
				RunAnimation(GuardIdleEmpty,1,0.05,true);
			}
			else
			{
				if ((OutOfAmmo() && (! bSlideBack)) && bHammerForward)
				{
					RunAnimation(GuardIdleHammerFW,1,0.05,true);
				}
				else
				{
					RunAnimation(GuardIdle,1,0.05,true);
				}
			}
		}
	}
	simulated Function AnimEnd(int32 Channel)
	{
	}
	Function TempLowerWeapon(bool bActive)
	{
		if (_bActive && (! bActive))
		{
			Global.sclass_name(bActive);
		}
	}
	Function TempRaiseWeapon()
	{
		if (GetWorld()->GetNetMode() == NM_Client)
		{
			return;
		}
		GotoState("BusyTempRaising");
		if (GetWorld()->GetNetMode() == NM_DedicatedServer)
		{
			ClientGotoState("BusyTempRaising","None");
		}
	}
	simulated Function BeginState()
	{
		bool bSaveActive = false;
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "AGP_Weapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		bSaveActive=_bActive;
		Super::BeginState();
		_bActive=bSaveActive;
		PlayIdleAnim();
	}
	simulated Function EndState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "AGP_Weapon::EndState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::EndState();
	}
}
*/

bool APistolWeapon::CanTraceMore(ABaseWeaponAttachment* BA, int num_traces)
{
	return false;
}
void APistolWeapon::AltFire(float Value)
{
}
void APistolWeapon::DoChangeFireMode()
{
}
void APistolWeapon::ChangeFireMode()
{
}
EUpperBodyAnim APistolWeapon::GetUpperBodyLowerAnim()
{
	return EUpperBodyAnim::UBANIM_PISTOL_Lower;
}
EUpperBodyAnim APistolWeapon::GetUpperBodyRaiseAnim()
{
	return EUpperBodyAnim::UBANIM_PISTOL_Raise;
}
EUpperBodyAnim APistolWeapon::GetUpperBodyReadyAnim()
{
	return EUpperBodyAnim::UBANIM_PISTOL_Ready;
}

AInvContainer* APistolWeapon::GetSwapContainer()
{
	return Cast<AAGP_Pawn>(GetInstigator())->getInvContainerHolster();
}

/*
// ======================================================================================
// AGP function - ShouldUse3dSights. Overrides AGP_Weapon::SHouldUse3dSights
// Used as a way to tell if the weapon, the scope, and the player should be allowed to use
// 3d sights. Overriden here because pistols should always use 3d sights.
// Created by:  Ramm 09/18/03
// ======================================================================================
*/
bool APistolWeapon::ShouldUse3dSights()
{
	return _Scope != NULL && Cast<ABaseScope>(_Scope)->b3dSights && bCanUse3dSights;
}

/* =================================================================================== *
* AGP function DryFire()
*	Dry fire doesn't do anything but play a sound. If this is being called on a client,
*	tell the server so that it can play the sound as well.
*	Added functionality to tell if weapon has been DryFired - Ramm
* last modified by: Ramm 08/11/03
* =================================================================================== */
void APistolWeapon::DryFire()
{
	if(GetNetMode() == ENetMode::NM_Client)
	{
		ServerDryFire();
	}
	//GotoState('BusyDryFiring');
}
void APistolWeapon::PlayDryFire()
{
	/*
		if (! bHammerForward && ! bDryFired && ! bSlideBack)
		{
			RunAnimation(FireEmptyFirstAnim,1);
		}
		else
		{
			if (! bSlideBack)
			{
				RunAnimation(FireEmptyAnim,1);
			}
		}
		PlayWeaponSound(DryFireSound,EnemyWeaponClass.Default.DryFireSound);
		if (bSlideBack)
		{
			GotoState('Idle');
		}
	*/
}
void APistolWeapon::PlayIdleAnim()
{
	/*
		if (Cast<ABaseWeaponAttachment>(ThirdPersonActor) != nullptr)
		{
			BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(this);
		}
		if (OutOfAmmo() && bSlideBack)
		{
			RunAnimation(IdleEmptyAnim,1,0.05,true);
		}
		else
		{
			if (OutOfAmmo() && ! bSlideBack && bHammerForward)
			{
				RunAnimation(IdleHammerFWAnim,1,0.05,true);
			}
			else
			{
				RunAnimation(IdleAnim,1,0.05,true);
			}
		}
	*/
}

void APistolWeapon::PlayFiring()
{
	int32 Num = 0;
	float Rate = 0;
	SetupMuzzleFlash();
	/*
		if (Cast<ABaseWeaponAttachment>(ThirdPersonActor) != nullptr)
		{
			BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(this);
		}
		if (IsSuppressed())
		{
			PlayWeaponSound(GetFireSound(),GetEnemyFireSound(),0.9,125);
		}
		else
		{
			PlayWeaponSound(GetFireSound(),GetEnemyFireSound(),0.9,400);
		}
		Rate=0.5 + 0.5 * FireAdjust;
		if (OutOfAmmo())
		{
			RunAnimation(FireLastShotAnim,1,0.05);
			bSlideBack=true;
		}
		else
		{
			if (DrawType == 2 && HasAnim('FireB'))
			{
				if (HasAnim('FireC'))
				{
					Num=Rand(3);
				}
				else
				{
					Num=Rand(2);
				}
			}
			else
			{
				Num=1;
			}
			RunAnimation(FireAnims[Num],0.5 + 0.5 * FireAdjust,0.05);
		}
		HandleRecoil();
	*/
}
void APistolWeapon::PlayReloading()
{
	/*
		if (Cast<ABaseWeaponAttachment>(ThirdPersonActor) != nullptr)
		{
			BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(this);
		}
		if (OutOfAmmo())
		{
			if (bSlideBack)
			{
				RunAnimation(ReloadAnim,1,0.05);
				if (! bUseAnimNotifySounds)
				{
					PlayWeaponSound(ReloadSound,EnemyWeaponClass.Default.ReloadSound);
				}
			}
			else
			{
				if (bHammerForward)
				{
					RunAnimation(ReloadEmptyHFAnim,1,0.05);
					bHammerForward=false;
					if (! bUseAnimNotifySounds)
					{
						PlayWeaponSound(ReloadEmptyHmrBkSound,EnemyWeaponClass.Default.ReloadSound);
					}
				}
				else
				{
					RunAnimation(ReloadEmptyHBAnim,1,0.05);
					if (! bUseAnimNotifySounds)
					{
						PlayWeaponSound(ReloadEmptyHmrBkSound,EnemyWeaponClass.Default.ReloadSound);
					}
				}
			}
		}
		else
		{
			RunAnimation(FullReloadAnim,1,0.05);
			if (! bUseAnimNotifySounds)
			{
				PlayWeaponSound(ReloadFullSound,EnemyWeaponClass.Default.ReloadSound);
			}
		}
		bDryFired=false;
		bSlideBack=false;
	*/
}
void APistolWeapon::PlaySelect()
{
	/*
		int32 initradius;
		if (Cast<ABaseWeaponAttachment>(ThirdPersonActor) != nullptr)
		{
			BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(this);
		}
		if (! IsAnimating() || ! AnimIsInGroup(0,'Select') || ! AnimIsInGroup(0,'SelectNew') && ! IsZoomed())
		{
			if (_bActive)
			{
				if (HasAnim(GuardUp))
				{
					if (bSlideBack)
					{
						RunAnimation(GuardUpEmpty,1);
					}
					else
					{
						if (bHammerForward)
						{
							RunAnimation(GuardUpHammerFW,1);
						}
						else
						{
							RunAnimation(GuardUp,1);
						}
					}
				}
				else
				{
					RunAnimation(SelectAnim,1);
					bDryFired=false;
				}
			}
			else
			{
				if (! _bCharged && HasAnim(SelectNewAnim))
				{
					_bCharged=true;
					RunAnimation(SelectNewAnim,1);
					bHammerForward=false;
					bDryFired=false;
					if (GetNetMode() == ENetMode::NM_Client)
					{
						initradius=1000000;
					}
					else
					{
						initradius=60;
					}
					if (! bUseAnimNotifySounds)
					{
						PlayWeaponSound(SelectChargeSound,EnemyWeaponClass.Default.SelectChargeSound,,initradius);
					}
				}
				else
				{
					RunAnimation(SelectAnim,1);
					if (! bUseAnimNotifySounds)
					{
						PlayWeaponSound(SelectSound,EnemyWeaponClass.Default.SelectSound);
					}
					bHammerForward=false;
					bDryFired=false;
				}
			}
		}
		else
		{
			if (IsZoomed())
			{
				PlayIdleAnim();
			}
		}
	*/
}

void APistolWeapon::TweenDown()
{
	FName SeqName = "";
	float AnimFrame = 0;
	float AnimRate = 0;
	/*
		if (Cast<ABaseWeaponAttachment>(ThirdPersonActor) != nullptr)
		{
			BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(this);
		}
		GetAnimParams(0,SeqName,AnimFrame,AnimRate);
		if (IsAnimating() && AnimIsInGroup(0,SelectAnim) || AnimIsInGroup(0,SelectNewAnim))
		{
			TweenAnim(SeqName,AnimFrame * 0.4);
		}
		else
		{
			if (_bActive)
			{
				if (HasAnim(GuardDown))
				{
					if (bSlideBack)
					{
						RunAnimation(GuardDownEmpty,1);
					}
					else
					{
						if (bHammerForward)
						{
							RunAnimation(GuardDownHammerFW,1);
						}
						else
						{
							RunAnimation(GuardDown,1);
						}
					}
				}
				else
				{
					RunAnimation(PutAwayAnim,1);
					bSlideBack=false;
				}
			}
			else
			{
				PlayWeaponSound(SelectSound,EnemyWeaponClass.Default.SelectSound);
				if (SeqName == GuardIdleEmpty)
				{
					RunAnimation(PutAwayLowEmptyAnim,1);
				}
				else
				{
					if (SeqName == GuardIdleHammerFW)
					{
						RunAnimation(PutAwayLowHFAnim,1);
					}
					else
					{
						if (SeqName == GuardIdle)
						{
							RunAnimation(PutAwayLowAnim,1);
						}
						else
						{
							if (bSlideBack)
							{
								RunAnimation(PutAwayEmptyAnim,1);
							}
							else
							{
								if (bHammerForward)
								{
									RunAnimation(PutAwayEmptyHFAnim,1);
								}
								else
								{
									RunAnimation(PutAwayAnim,1);
								}
							}
						}
					}
				}
				bSlideBack=false;
			}
		}
	*/
}
void APistolWeapon::PlayHighCrawlIn()
{
	/*
		if (bSlideBack)
		{
			RunAnimation(CrawlInEmptyAnim,1);
		}
		else
		{
			if (bHammerForward)
			{
				RunAnimation(CrawlInEmptyHFAnim,1);
			}
			else
			{
				RunAnimation(CrawlInAnim,1);
			}
		}
	*/
}

void APistolWeapon::PlayCrawl()
{
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0,0,0);
	/*
	if (Instigator != nullptr && Instigator.bIsWalking)
	{
		GotoState('OutCrawling');
	}
	else
	{
		GetAxes(Instigator.Rotation,X,Y,Z);
		if (Instigator.Velocity Dot X > 0)
		{
			if (bSlideBack)
			{
				RunAnimation(CrawlEmptyAnim,1,,true);
			}
			else
			{
				if (bHammerForward)
				{
					RunAnimation(CrawlEmptyHFAnim,1,,true);
				}
				else
				{
					RunAnimation(CrawlAnim,1,,true);
				}
			}
		}
		else
		{
			if (bSlideBack)
			{
				RunAnimation(CrawlBackEmptyAnim,1,,true);
			}
			else
			{
				if (bHammerForward)
				{
					RunAnimation(CrawlBackEmptyHFAnim,1,,true);
				}
				else
				{
					RunAnimation(CrawlBackAnim,1,,true);
				}
			}
		}
	}
	*/
}
void APistolWeapon::PlayHighCrawlOut()
{
	/*
		if (bSlideBack)
		{
			RunAnimation(CrawlOutEmptyAnim,1);
		}
		else
		{
			if (bHammerForward)
			{
				RunAnimation(CrawlOutEmptyHFAnim,1);
			}
			else
			{
				RunAnimation(CrawlOutAnim,1);
			}
		}
	*/
}
