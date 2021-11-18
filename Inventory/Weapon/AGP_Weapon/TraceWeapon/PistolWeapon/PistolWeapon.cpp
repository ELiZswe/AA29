// All the original content belonged to the US Army


#include "PistolWeapon.h"
#include "AA29/BaseScope/BaseScope.h"

APistolWeapon::APistolWeapon()
{
	fpWeaponThreatLevel   = 7;
	TraceDist             = 9000;
	weaponType            = EWeaponType::WEAPON_Pistol;
	ReloadStanding3PAnim  = FName("StdSmRld_E");
	iMisFire              = 1500;
}



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
void APistolWeapon::GetSwapContainer()
{
	//Return AGP_Pawn(Instigator).getInvContainerHolster();
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
		if (BaseWeaponAttachment(ThirdPersonActor) != None)
		{
			BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(Self);
		}
		if (OutOfAmmo() && bSlideBack)
		{
			RunAnimation(IdleEmptyAnim,1,0.05,True);
		}
		else
		{
			if (OutOfAmmo() && ! bSlideBack && bHammerForward)
			{
				RunAnimation(IdleHammerFWAnim,1,0.05,True);
			}
			else
			{
				RunAnimation(IdleAnim,1,0.05,True);
			}
		}
	*/
}
void APistolWeapon::PlayFiring()
{
	/*
		local int Num;
		local float Rate;
		SetupMuzzleFlash();
		if (BaseWeaponAttachment(ThirdPersonActor) != None)
		{
			BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(Self);
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
			bSlideBack=True;
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
		if (BaseWeaponAttachment(ThirdPersonActor) != None)
		{
			BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(Self);
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
					bHammerForward=False;
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
		bDryFired=False;
		bSlideBack=False;
	*/
}
void APistolWeapon::PlaySelect()
{
	/*
		local int initradius;
		if (BaseWeaponAttachment(ThirdPersonActor) != None)
		{
			BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(Self);
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
					bDryFired=False;
				}
			}
			else
			{
				if (! _bCharged && HasAnim(SelectNewAnim))
				{
					_bCharged=True;
					RunAnimation(SelectNewAnim,1);
					bHammerForward=False;
					bDryFired=False;
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
					bHammerForward=False;
					bDryFired=False;
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
	/*
		local name SeqName;
		local float AnimFrame;
		local float AnimRate;
		if (BaseWeaponAttachment(ThirdPersonActor) != None)
		{
			BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(Self);
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
					bSlideBack=False;
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
				bSlideBack=False;
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
	/*
		local FVector X;
		local FVector Y;
		local FVector Z;
		if (Instigator != None && Instigator.bIsWalking)
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
					RunAnimation(CrawlEmptyAnim,1,,True);
				}
				else
				{
					if (bHammerForward)
					{
						RunAnimation(CrawlEmptyHFAnim,1,,True);
					}
					else
					{
						RunAnimation(CrawlAnim,1,,True);
					}
				}
			}
			else
			{
				if (bSlideBack)
				{
					RunAnimation(CrawlBackEmptyAnim,1,,True);
				}
				else
				{
					if (bHammerForward)
					{
						RunAnimation(CrawlBackEmptyHFAnim,1,,True);
					}
					else
					{
						RunAnimation(CrawlBackAnim,1,,True);
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
