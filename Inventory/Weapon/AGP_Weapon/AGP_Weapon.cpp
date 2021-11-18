// All the original content belonged to the US Army

#include "AGP_Weapon.h"
#include "AA29/Inventory/Ammunition/Ammunition.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/BaseScope/BaseScope.h"

AAGP_Weapon::AAGP_Weapon()
{
	BaseAccuracyModifier			= 0.1;
	BaseRecoilModifier				= 0.1;
	_fShotNoise						= 1;
	_fHitNoise						= 0.5;
	_bCanBeMiles					= true;
	_bWeaponAlreadyRaised			= true;
	ProneFireOffset					= FVector(25, 0, 0);
	ShotsToStartRecoilBlend			= 3;
	ShotsForMaxRecoil				= 7;
	DryFireSound					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/General/WeaponsUS_General_DryFire.WeaponsUS_General_DryFire"), NULL, LOAD_None, NULL);
	FireAnims						= { "Fire", "FireB", "FireC" };
	SupportedFireAnims				= { "SupportedFire","SupportedFireB","SupportedFireC" };
	ZoomFireAnims					= { "ZoomFire","ZoomFireB","ZoomFireC" };
	SupportedZoomFireAnims			= { "SupportedZoomFire","SupportedZoomFireB","SupportedZoomFireC" };
	AuxZoomFireAnims				= { "ReflexFire","ReflexFireB","ReflexFireC" };
	AuxSupportedZoomFireAnims		= {"SupportedReflexFire","SupportedReflexFireB","SupportedReflexFireC"};
	ReloadEmptyAnim					= FName("Reload");
	ReloadFullAnim					= FName ("Reload");
	ProneReloadEmptyAnim			= FName("SupportedReload");
	ProneReloadFullAnim				= FName("SupportedReload");
	ZoomIdleAnim					= { FName("ZoomStill") };
	SupportedZoomIdleAnim			= FName("SupportedZoomStill");
	AuxZoomIdleAnim					= FName("ReflexStill");
	AuxSupportedZoomIdleAnim		= FName("SupportedReflexStill");
	AuxZoomInAnim					= FName("ReflexIn");
	AuxZoomOutAnim					= FName("ReflexOut");
	AuxSupportedZoomInAnim			= FName("SupportedReflexIn");
	AuxSupportedZoomOutAnim			= FName("SupportedReflexOut");
	AuxfZoomAnimFOV					= 25;
	FiringTweenTime					= 0.01;
	MaxClips						= 16;
	bWpnRecoil						= true;
	bWpnAccuracy					= true;
	_FPMuzzleFlashOffset.VOffset	= FVector(0, 179.901123046875, 0);
	_FPMuzzleFlashOffset.ROffset	= FRotator(0,0,0);
	_FPMuzzleFlashOffset.nBone		= "Muzzle";
	_sMILESBoxScale					= FVector( 1, 1, 1);
	_sBlankPlugScale				= FVector(1, 1, 1);
	iNextGrenadeType				= -1;
	num_mods						= -1;
	WM_Default						= { "NoMod","NoMod","NoMod","NoMod","NoMod" };
	bAllowsPlusOneLoading			= true;
	AutoFiringRate					= 2;
	SingleFiringRate				= 2;
	weapmFov						= 24;
	BurstPendingShots				= 2;
	AutoPendingShots				= 2;
	GlobalRecoilScaler				= 1.45;
	TraceAccuracy					= 1;
	TraceDist						= 18000;
	DisplayFOV						= 55;
	MuzzleScale						= 1.4;
	FlashOffsetY					= 0.32;
	FlashOffsetX					= 0.255;
	FlashLength						= 0.023;
	MuzzleFlashSize					= 256;
	bDrawMuzzleFlash				= true;
	MuzzleFlashStyle				= ERenderStyle::STY_Translucent;
	_ZoomDirInfo.MeanDirection		= FVector(0, 0, 0);
	_ZoomDirInfo.bPitch				= 1;
	_ZoomDirInfo.PitchMean			= 0;
	_ZoomDirInfo.PitchMaxDeviation	= 0.9;
	_ZoomDirInfo.PitchFalloff		= 1;
	_ZoomDirInfo.bYaw				= 1;
	_ZoomDirInfo.YawMean			= 0;
	_ZoomDirInfo.YawMaxDeviation	= 3.5;
	_ZoomDirInfo.YawFalloff			= 1;
	_ZoomDirInfo.bRoll				= 0;
	_ZoomDirInfo.RollMean			= 0;
	_ZoomDirInfo.RollMaxDeviation	= 0;
	_ZoomDirInfo.RollFalloff		= 0;
	_ZoomDirInfo.SpeedMean			= 0;
	_ZoomDirInfo.SpeedMaxDeviation	= 0;
	_ZoomDirInfo.SpeedFalloff		= 0;
	_ZoomDirInfo.Base				= FRotator(0, 0, 0);
	rSupportedLimit					= FRotator(38.4521484375, 29.9981689453125, 0);
	vZoomAnimOffset					= FVector(16, -43, -225);
	fZoomAnimFOV					= 10;
	fZoomAnimTime					= 0.19;
	eROF							= RateofFire::ROF_Single;
	bMisFire						= true;
	PlayerViewOffset				= FVector( 3,  75, -125);
	BobDamping						= 0.5;
	DrawScale						= 0.5;
}



void AAGP_Weapon::InterpolateZoomView(bool moveToZoomed)
{

}
void AAGP_Weapon::Strawberry ()
{
	ServerJamit();
}
/*
void AAGP_Weapon::DisplayDebug (UCanvas* Canvas, float YL, float YPos)
{
	
	DisplayDebug(Canvas,YL,YPos);
	YPos += YL;
	Canvas.SetPos(4,YPos);
	Canvas.DrawText("bActive" @ _bActive,False);
}
*/
void AAGP_Weapon::ClientGotoState (FName NewState, FName NewLabel)
{
	/*
	if (NewState == 'BusyTempRaising' && IsInState('BusyReloading'))
	{
		Return;
	}
	else
	{
		GotoState(NewState,NewLabel);
	}
	*/
}
/*
void AAGP_Weapon::StaticPrecache (LevelInfo L)
{
	if (Default.AmmoName != None && Default.AmmoName.Default.IconMaterial != None)
	{
		L.AddPrecacheMaterial(Default.AmmoName.Default.IconMaterial);
	}
	StaticPrecache(L);
}
*/
void AAGP_Weapon::PreBeginPlay ()
{
	/*
	PreBeginPlay();
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		Return;
	}
	if (_FPMuzzleFlashClass != None)
	{
		NormalMuzzleFlashEmitter=BaseMuzzleFlashEmitter(Spawn(_FPMuzzleFlashClass,Self));
		_FPMuzzleFlashEmitter=NormalMuzzleFlashEmitter;
		if (_FPMuzzleFlashEmitter != None)
		{
			AttachToBoneOffset(_FPMuzzleFlashEmitter,_FPMuzzleFlashOffset);
		}
	}
	*/
}
void AAGP_Weapon::PostBeginPlay ()
{
	/*
	PostBeginPlay();
	if (PickupClass != None)
	{
		EnemyWeaponClass=class<AGP_Weapon>(PickupClass.Default.EnemyPickupClass.Default.InventoryType);
	}
	if (EnemyWeaponClass == None)
	{
		EnemyWeaponClass=Class;
	}
	if (IsA('ThrowWeapon') && ! IsA('Throw_M83_Smoke'))
	{
		StatWeaponType=1;
	}
	else
	{
		if (IsA('RocketWeapon'))
		{
			StatWeaponType=2;
		}
		else
		{
			if (IsA('PistolWeapon'))
			{
				StatWeaponType=3;
			}
			else
			{
				if (IsA('SniperRifle'))
				{
					StatWeaponType=4;
				}
				else
				{
					if (IsA('Weapon_M249_SAW') || IsA('Weapon_RPK_SAW') || IsA('Weapon_M2_HMG') || IsA('Weapon_BTR_HMG'))
					{
						StatWeaponType=5;
					}
					else
					{
						if (IsA('Weapon_M16A2_Rifle') || IsA('Weapon_AK47_Rifle'))
						{
							StatWeaponType=6;
						}
					}
				}
			}
		}
	}
	*/
}
void AAGP_Weapon::Destroyed ()
{
	Super::Destroyed();
	
	if (AmmoType != NULL)
	{
		AmmoType->Destroy();
		AmmoType=NULL;
	}
	if (AuxAmmoType != NULL)
	{
		AuxAmmoType->Destroy();
		AuxAmmoType=NULL;
	}
	if (_Scope != NULL)
	{
		//_Scope->Destroy();
		_Scope=NULL;
	}
	
	if (NormalMuzzleFlashEmitter != NULL)
	{
		//NormalMuzzleFlashEmitter->Destroy();
		NormalMuzzleFlashEmitter= NULL;
	}
	if (AuxMuzzleFlashEmitter != NULL)
	{
		//AuxMuzzleFlashEmitter->Destroy();
		AuxMuzzleFlashEmitter= NULL;
	}
	if (SuppressedMuzzleFlashEmitter != NULL)
	{
		//SuppressedMuzzleFlashEmitter->Destroy();
		SuppressedMuzzleFlashEmitter= NULL;
	}
	_FPMuzzleFlashEmitter= NULL;
	if (BlankPlug != NULL)
	{
		BlankPlug->Destroy();
		BlankPlug= NULL;
	}
	if (MILESBox != NULL)
	{
		MILESBox->Destroy();
		MILESBox= NULL;
	}
	if (AmmoRoundList != NULL)
	{
		//AmmoRoundList->Destroy();
		AmmoRoundList= NULL;
	}
	if (AuxAmmoRoundList != NULL)
	{
		//AuxAmmoRoundList->Destroy();
		AuxAmmoRoundList= NULL;
	}
	if (SpecialAmmoRoundList != NULL)
	{
		//SpecialAmmoRoundList->Destroy();
		SpecialAmmoRoundList= NULL;
	}
	if(GetNetMode() != ENetMode::NM_Client)
	{
		if (WeaponModList != NULL)
		{
			WeaponModList->Destroy();
			WeaponModList=NULL;
		}
	}
	//_AmmoMonitor=NULL;
	//_JammedMonitor=NULL;
	
}
void AAGP_Weapon::BeginPlay ()
{
	Super::BeginPlay();
	if (iMisFire <= 0)
	{
		bMisFire=false;
	}
	if (bMisFire)
	{
		CalcNextMisFire();
	}
	//GotoState('Idle');
}
bool AAGP_Weapon::ShouldUse3dSights ()
{
	//return _Scope != NULL && _Scope->b3dSights && bCanUse3dSights;
	return (_Scope != NULL && Cast<ABaseScope>(_Scope)->b3dSights && bCanUse3dSights); // Scope and weapon allow 3d sights
}
void AAGP_Weapon::Get3dScopeLocation ()
{
	//Return Instigator.EyePosition();
}
void AAGP_Weapon::Get3dScopeRotation ()
{
	/*
	local FRotator Rot;
	local int mypitch;
	local int myroll;
	if (IsZoomed())
	{
		Rot=Instigator.GetViewRotation();
		Return Rot;
	}
	else
	{
		Rot=GetBoneRotation('Muzzle');
		mypitch=Rot.Roll;
		myroll=Rot.Pitch;
		Rot.Pitch=mypitch;
		Rot.Roll=myroll;
		Rot.Pitch += 16384;
		Rot.Roll += 32768;
		Rot.Yaw -= 16384;
		Return Rot;
	}
	*/
}
void AAGP_Weapon::ServerJamit ()
{
	iNextMisFire=0;
}
void AAGP_Weapon::AttachToPawn (APawn* p)
{
	/*
	local WeaponAttachment WA;
	AttachToPawn(p);
	WA=WeaponAttachment(ThirdPersonActor);
	if (WA != None)
	{
		WA.AdjustAttachmentFor(Self);
	}
	*/
}
void AAGP_Weapon::GetFireStart (FVector X, FVector Y, FVector Z)
{
	/*
	if (Instigator != None)
	{
		if (! Instigator.IsHumanControlled())
		{
			Return NPC_GetFireStart(X,Y,Z);
		}
		if (Instigator.bIsProne)
		{
			Return Instigator.EyePosition() + ProneFireOffset.X * X + ProneFireOffset.Y * Y + ProneFireOffset.Z * Z;
		}
		else
		{
			Return Instigator.EyePosition() + FireOffset.X * X + FireOffset.Y * Y + FireOffset.Z * Z;
		}
	}
	Return X;
	*/
}
void AAGP_Weapon::NPC_GetFireStart (FVector X, FVector Y, FVector Z)
{
	/*
	local FVector V;
	if (Instigator != None)
	{
		V=Instigator.EyePosition();
	}
	Return V;
	*/
}
void AAGP_Weapon::RenderOverlays (UCanvas* Canvas, bool bWeaponAndAttachmentsOnly)
{
	/*
	local PlayerController PlayerOwner;
	local float ScaledFlash;
	local FRotator Rot;
	if (Instigator != None && Instigator.Controller != None)
	{
		PlayerOwner=PlayerController(Instigator.Controller);
	}
	if (PlayerOwner == None)
	{
		Return;
	}
	if (PlayerOwner.bBehindView == False && bWeaponAndAttachmentsOnly == true)
	{
		if (! IsZoomed() || ShouldUse3dSights())
		{
			if (Instigator == None)
			{
				Return;
			}
			if (bMuzzleFlash && bDrawMuzzleFlash && MFTexture != None)
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
					Canvas.SetPos(0.5 * Canvas.ClipX - ScaledFlash + Canvas.ClipX * FlashOffsetX,0.5 * Canvas.ClipY - ScaledFlash + Canvas.ClipY * FlashOffsetY);
					DrawMuzzleFlash(Canvas);
				}
			}
			else
			{
				bSetFlashTime=False;
			}
			SetLocation(Instigator.CalcDrawOffset(Self));
			Rot=Instigator.GetViewRotation();
			if (IsInState('Crawling'))
			{
				Rot.Pitch=Instigator.FrontFloorRotation.Pitch;
			}
			SetRotation(Rot);
			Canvas.DrawActor(Self,False,True,DisplayFOV);
		}
		if (_Scope != None)
		{
			_Scope.RenderOverlays(Canvas,bWeaponAndAttachmentsOnly);
		}
	}
	*/
}
/*
void AAGP_Weapon::RenderTexture (ScriptedTexture Tex)
{
	local FRotator Rot;
	Rot=Instigator.GetViewRotation();
	Rot.Roll += 16355;
	if (Owner != None && Instigator != None && Tex != None)
	{
		Tex.DrawPortal(0,0,Tex.USize,Tex.VSize,Owner,Instigator.EyePosition(),Rot,weapmFov);
	}
}
*/
void AAGP_Weapon::AdjustAim (bool bBreatheBonus)
{
	/*
	local FRotator Dir;
	local float mod;
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugWeaponAcc)
	{
		DebugLog(DEBUG_Inv,"AdjustAim" @ Instigator @ Instigator.Controller.bPerfectAccuracy @ bWpnAccuracy);
	}
	if (Instigator == None || Instigator.Controller.bPerfectAccuracy || ! bWpnAccuracy)
	{
		Dir=rot(0 0 0);
		if (_Scope != None && _Scope.bUseAimAdjust && IsZoomed())
		{
			Dir += _Scope.GetAimAdjustment();
			Dir.Pitch += CurrentElevation;
		}
		Return Dir;
	}
	mod=Instigator.CE_MeterValue;
	if (bBreatheBonus && IsZoomed())
	{
		mod *= 1.15;
	}
	mod=FMax(1 - mod,BaseAccuracyModifier);
	Dir=CalcRotation(_AccuracyDirInfo) * mod * GetWeightedAim();
	if (IsZoomed())
	{
		Dir.Pitch += CurrentElevation;
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugWeaponAcc)
	{
		Dir=Normalize(Dir);
		DebugLog(DEBUG_Inv,"Weapon Accuracy Mod" @ mod @ "Adjusted Rotator" @ Dir @ "PitchDeg" @ Dir.Pitch / 182 @ "YawDeg" @ Dir.Yaw / 182);
	}
	if (_Scope != None && _Scope.bUseAimAdjust && IsZoomed())
	{
		Return Dir + _Scope.GetAimAdjustment();
	}
	else
	{
		Return Dir;
	}
	*/
}
void AAGP_Weapon::GetWeightedAim ()
{
	/*
	local float randomAimMod;
	if (! AGP_Pawn(Instigator).bNewAccuracy)
	{
		Return 1;
	}
	randomAimMod=FRand();
	if (randomAimMod < 0.1)
	{
		Return 1;
	}
	else
	{
		if (randomAimMod < 0.2)
		{
			Return 0.75;
		}
		else
		{
			if (randomAimMod < 0.3)
			{
				Return 0.5;
			}
			else
			{
				if (randomAimMod < 0.4)
				{
					Return 0.35;
				}
				else
				{
					if (randomAimMod < 0.5)
					{
						Return 0.3;
					}
					else
					{
						if (randomAimMod < 0.6)
						{
							Return 0.25;
						}
						else
						{
							if (randomAimMod < 0.7)
							{
								Return 0.2;
							}
							else
							{
								if (! IsZoomed())
								{
									Return 0.2;
								}
								else
								{
									if (randomAimMod < 0.8)
									{
										Return 0.15;
									}
									else
									{
										if (randomAimMod < 0.9)
										{
											Return 0.1;
										}
										else
										{
											Return 0.05;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	*/
}
void AAGP_Weapon::ServerFire (bool bNoAdjustAim, bool bRapid, bool bBreatheBonus)
{
	/*
	if (Instigator == None || Owner != None && Owner != Instigator)
	{
		DebugLog(DEBUG_Error,"AGP_Weapon::ServerFire() Trap: Got here with Instigator(" @ Instigator @ ") Owner(" @ Owner @ ")");
		Return;
	}
	else
	{
		if (Instigator != None && Instigator.isDead())
		{
			DebugLog(DEBUG_Warn,"AGP_Weapon::ServerFire() Weapon(" @ Self @ ") Instigator(" @ Instigator @ ") Instigator is dead. Ignore fire request.");
			Return;
		}
	}
	if (GetCurrentAmmoType() == None && Pawn(Owner) != None)
	{
		GiveAmmo(Pawn(Owner));
	}
	if (GetCurrentAmmoType() != None && GetCurrentAmmoType().HasAmmo())
	{
		if (! bNoAdjustAim)
		{
			AdjustedAim=AdjustAim(bBreatheBonus);
		}
		iNextMisFire --;
		if (bMisFireOnRapid)
		{
			CheckRapidMisfire(bRapid);
		}
		if (bMisFire && iNextMisFire <= 0)
		{
			CalcNextMisFire();
			HandleMisFire();
		}
		else
		{
			if (IsInState('BusyFiring'))
			{
				BeginState();
			}
			else
			{
				if (! IsInState('BusyTempLowering'))
				{
					GotoState('BusyFiring');
				}
			}
		}
	}
	else
	{
		DebugLog(DEBUG_Inv,"AGP_Weapon::ServerFire() Got here with no ammo! " @ Self);
	}
	*/
}
void AAGP_Weapon::NPC_ServerFire (bool bNoAdjustAim, bool bRapid, bool bBreatheBonus, APawn* Enemy, float Value)
{
	/*
	NPC_SetEnemy(Enemy);
	NPC_SetValue(Value);
	if (GetCurrentAmmoType() == None)
	{
		GiveAmmo(Pawn(Owner));
	}
	if (GetCurrentAmmoType().HasAmmo())
	{
		if (! bNoAdjustAim)
		{
			AdjustedAim=AdjustAim(bBreatheBonus);
		}
		iNextMisFire --;
		if (bMisFireOnRapid)
		{
			CheckRapidMisfire(bRapid);
		}
		if (bMisFire && iNextMisFire <= 0)
		{
			CalcNextMisFire();
			HandleMisFire();
		}
		else
		{
			if (IsInState('NPC_BusyFiring'))
			{
				BeginState();
			}
			else
			{
				GotoState('NPC_BusyFiring');
			}
		}
	}
	*/
}
void AAGP_Weapon::LocalFire ()
{
	/*
	bPointing=True;
	PlayFiring();
	*/
}
void AAGP_Weapon::NPC_LocalFire ()
{
	/*
	bPointing=True;
	NPC_PlayFiring();
	*/
}
void AAGP_Weapon::ProjectileBackBlast (FVector Forward, FVector Right, FVector Up)
{
	/*
	local FVector StartOffset;
	local float Scale;
	local FVector vVec;
	local Pawn p;
	local float fLen;
	local Actor Hit;
	local FVector HitLoc;
	local FVector HitNorm;
	Forward *= -1;
	Forward=Normal(Forward);
	StartOffset=Instigator.Location;
	ForEach CollidingActors(Class'Pawn',p,BackBlastRadius,StartOffset)
	{
		if (p != Instigator)
		{
			Hit=p.Trace(HitLoc,HitNorm,Instigator.Location,p.Location,True);
			if (Hit == Instigator)
			{
				vVec=p.Location - StartOffset;
				fLen=VSizeSquared(vVec);
				vVec=Normal(vVec);
				if (Forward Dot vVec > BackBlastCone && fLen < BackBlastRadius * BackBlastRadius)
				{
					Scale=1 - fLen / BackBlastRadius * BackBlastRadius;
					p.TakeDamage(BackBlastDamage * Scale,Instigator,vect(0 0 0),vect(0 0 0),RadiusDamageType,,Instigator.Controller,Self);
				}
			}
		}
	}
	*/
}
void AAGP_Weapon::ProjectileFire ()
{
	/*
	local PlayerController PC;
	local FVector Start;
	local FVector X;
	local FVector Y;
	local FVector Z;
	local Ammunition CurrentAmmoType;
	Owner.MakeNoise(1,Self);
	GetAxes(GetFireRot(),X,Y,Z);
	Start=GetFireStart(X,Y,Z);
	CurrentAmmoType=GetCurrentAmmoType();
	_Projectile=CurrentAmmoType.SpawnProjectile(Start,X);
	PC=PlayerController(Instigator.Controller);
	if (Level.Game.Stats != None && PC != None && PC.PlayerStatsIndex >= 0)
	{
		if (StatWeaponType == 1 || CurrentAmmoType.IsA('Ammo_40mm_1_Gren') || CurrentAmmoType.IsA('AmmoRound_Flare_Gren'))
		{
			Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredGrenade();
		}
		else
		{
			if (StatWeaponType == 2)
			{
				Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredRocket();
			}
			else
			{
				if (StatWeaponType == 3)
				{
					Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredPistol();
				}
				else
				{
					if (StatWeaponType == 4)
					{
						Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredSniperRifle();
					}
					else
					{
						if (StatWeaponType == 5)
						{
							Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredMachineGun();
						}
						else
						{
							if (StatWeaponType == 6)
							{
								Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredAssaultRifle();
							}
						}
					}
				}
			}
		}
	}
	if (bHasBackBlast)
	{
		ProjectileBackBlast(X,Y,Z);
	}
	*/
}
void AAGP_Weapon::NPC_ProjectileFire ()
{
	/*
	local FVector StartPos;
	local FVector EndPos;
	local FVector D;
	StartPos=Instigator.Location;
	if (Instigator.bIsProne)
	{
		StartPos.Z += Instigator.ProneEyeHeight;
	}
	else
	{
		if (Instigator.bIsCrouched)
		{
			StartPos.Z += Instigator.CrouchEyeHeight;
		}
		else
		{
			StartPos.Z += Instigator.BaseEyeHeight;
		}
	}
	EndPos=dEnemy.Location;
	D=EndPos - StartPos;
	_Projectile=GetCurrentAmmoType().SpawnProjectile(StartPos,D);
	*/
}
void AAGP_Weapon::TraceFire (float Accuracy, float YOffset, float ZOffset)
{
	/*
	local FVector StartTrace;
	local FVector X;
	local FVector Y;
	local FVector Z;
	local BaseWeaponAttachment BA;
	local int total_traces;
	local PlayerController PC;
	if (Instigator != None && Instigator.bIsDead)
	{
		Log("Dead guy trying to shoot - discarding");
		Return;
	}
	Owner.MakeNoise(1,Self);
	GetAxes(GetFireRot(),X,Y,Z);
	StartTrace=GetFireStart(X,Y,Z);
	BA=BaseWeaponAttachment(ThirdPersonActor);
	VtoPV(StartTrace,BA.BulletTrace[0]);
	GetCurrentAmmoType().UseBullet(StartTrace,X);
	BA=BaseWeaponAttachment(ThirdPersonActor);
	if (BA != None)
	{
		total_traces=DoTrace(BA.GetSource(),StartTrace,X,TraceDist,1,0,BA);
	}
	PC=PlayerController(Instigator.Controller);
	if (Level.Game.Stats != None && PC != None && PC.PlayerStatsIndex >= 0)
	{
		if (StatWeaponType == 5)
		{
			Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredMachineGun();
		}
		else
		{
			if (StatWeaponType == 6)
			{
				Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredAssaultRifle();
			}
			else
			{
				if (StatWeaponType == 3)
				{
					Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredPistol();
				}
				else
				{
					if (StatWeaponType == 1)
					{
						Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredGrenade();
					}
					else
					{
						if (StatWeaponType == 4)
						{
							Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredSniperRifle();
						}
						else
						{
							if (StatWeaponType == 2)
							{
								Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredRocket();
							}
						}
					}
				}
			}
		}
	}
	DebugLog(DEBUG_Bullet,"AGP_Weapon::TraceFire() Did (" @ total_traces @ ") total traces");
	if (Level.GamePlayMode != 1 && BA != None)
	{
		BA.TraceCount ++;
		if (GetNetMode() == ENetMode::NM_Standalone)
		{
			BA.ThirdPersonTrace();
		}
	}
	DebugLog(DEBUG_Bullet,"-----------------------------");
	*/
}
void AAGP_Weapon::GetFireRot ()
{
	/*
	local FRotator R;
	if (Instigator != None)
	{
		R=Instigator.GetViewRotation() + AdjustedAim;
	}
	Return R;
	*/
}
void AAGP_Weapon::NPC_TraceFire (float Accuracy, float YOffset, float ZOffset)
{
	/*
	local FVector StartTrace;
	local FVector X;
	local FVector Y;
	local FVector Z;
	local FRotator OwnerRot;
	local BaseWeaponAttachment BA;
	local int total_traces;
	local FVector StartPos;
	local FVector EndPos;
	local float Right;
	local float Up;
	local FVector D;
	local FVector AimOffset;
	if (Owner != None)
	{
		Owner.MakeNoise(1);
	}
	if (Instigator.isDead())
	{
		OwnerRot=Instigator.GetViewRotation() + AdjustedAim;
		GetAxes(OwnerRot,X,Y,Z);
		StartTrace=GetFireStart(X,Y,Z);
	}
	BA=BaseWeaponAttachment(ThirdPersonActor);
	VtoPV(StartTrace,BA.BulletTrace[0]);
	GetCurrentAmmoType().UseBullet(StartTrace,X);
	StartPos=Instigator.Location;
	if (Instigator.bIsProne)
	{
		StartPos.Z += Instigator.ProneEyeHeight;
	}
	else
	{
		if (Instigator.bIsCrouched)
		{
			StartPos.Z += Instigator.CrouchEyeHeight;
		}
		else
		{
			StartPos.Z += Instigator.BaseEyeHeight;
		}
	}
	if (dEnemy != None)
	{
		EndPos=dEnemy.Location;
	}
	AimOffset.X=0;
	if (dValue == 0)
	{
		Right=FRand() * 64 - 32;
		Up=FRand() * 32;
		if (Right > 0)
		{
			AimOffset.Y=Right + dEnemy.CollisionRadius * 2;
		}
		else
		{
			AimOffset.Y=Right - dEnemy.CollisionRadius * 2;
		}
		if (dEnemy.bIsProne)
		{
			Up += dEnemy.ProneEyeHeight;
		}
		else
		{
			if (dEnemy.bIsCrouched)
			{
				Up += dEnemy.CrouchEyeHeight;
			}
			else
			{
				Up += dEnemy.BaseEyeHeight;
			}
		}
		AimOffset.Z=Up;
	}
	else
	{
		if (dEnemy.bIsProne)
		{
			Up += dEnemy.ProneEyeHeight;
			Up -= FRand() * 8;
		}
		else
		{
			if (dEnemy.bIsCrouched)
			{
				Up += dEnemy.CrouchEyeHeight;
				Up -= FRand() * 16;
			}
			else
			{
				Up += dEnemy.BaseEyeHeight;
				Up -= FRand() * 24;
			}
		}
		AimOffset.Z=Up;
	}
	EndPos += AimOffset;
	D=EndPos - StartPos;
	total_traces=NPC_DoTrace(Instigator,StartPos,D,TraceDist,1,0,BA);
	DebugLog(DEBUG_Bullet,"AGP_Weapon::TraceFire()	Did (" @ total_traces @ ") total traces");
	if (Level.GamePlayMode != 1)
	{
		BA.TraceCount ++;
		if (GetNetMode() == ENetMode::NM_Standalone)
		{
			BA.ThirdPersonTrace();
		}
	}
	DebugLog(DEBUG_Bullet,"-----------------------------");
	*/
}
void AAGP_Weapon::GetPenetrationPercent (AActor* A, UTexture2D* M)
{
	/*
	if (A != None && A.fPenetrationOverridePercent != 0)
	{
		Return A.fPenetrationOverridePercent;
	}
	if (M != None)
	{
		Return M.GetPercentPenetration();
	}
	Return 0;
	*/
}
void AAGP_Weapon::GetRicochetThreshold (AActor* A, UTexture2D* M)
{
	/*
	if (A != None && A.fRicochetOverrideThreshold != 0)
	{
		Return A.fRicochetOverrideThreshold;
	}
	if (M != None)
	{
		Return M.GetRicochetThreshold();
	}
	Return 0;
	*/
}
void AAGP_Weapon::GetRicochetDirection (FVector TraceDirection, FVector HitNormal, float CosTheta)
{
	/*
	TraceDirection=MirrorVectorByNormal(TraceDirection,HitNormal);
	TraceDirection -= 0.5 * CosTheta * HitNormal;
	TraceDirection += 0.5 * CosTheta * VRand();
	Return Normal(TraceDirection);
	*/
}
void AAGP_Weapon::GetPenetrateDirection (FVector TraceDirection, float fStrength)
{
	/*
	TraceDirection += 0.5 * 1 - fStrength * VRand();
	Return Normal(TraceDirection);
	*/
}
void AAGP_Weapon::GetPenetrateStrength (AActor* TraceFrom, FVector StartTrace, FVector EndTrace, float fStrength)
{
	/*
	local Actor.BoneInfo HitBone;
	local Material HitMaterial;
	local FVector HitLocation;
	local FVector HitNormal;
	local float penDepth;
	TraceFrom.BoneTrace(HitLocation,HitNormal,EndTrace,StartTrace,HitMaterial,HitBone,True);
	penDepth=VSize(EndTrace - HitLocation);
	if (HitMaterial != None)
	{
		penDepth *= 1 - HitMaterial.GetPercentPenetration();
	}
	else
	{
		penDepth *= 1 - GetPenetrationPercent(TraceFrom,HitMaterial);
	}
	fStrength *= 1 - penDepth / 256;
	Return fStrength;
	*/
}
void AAGP_Weapon::CanTraceMore(ABaseWeaponAttachment* BA, int32 num_traces)
{
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsMILES())
	{
		Return False;
	}
	else
	{
		Return num_traces < BA.GetMaxBulletTraces();
	}
	*/
}
void AAGP_Weapon::DoTrace (AActor* TraceFrom, FVector StartTrace, FVector TraceDirection, float fTraceDistance, float fStrength, int32 num_traces, ABaseWeaponAttachment* BA, bool btestdepth)
{
	/*
	local Actor HitActor;
	local Actor.BoneInfo HitBone;
	local Material HitMaterial;
	local FVector HitLocation;
	local FVector HitNormal;
	local float CosTheta;
	local bool bDidRicochet;
	local FVector EndTrace;
	local FVector Unused1;
	local FVector Unused2;
	local int total_traces;
	num_traces ++;
	EndTrace=StartTrace + fTraceDistance * TraceDirection;
	TraceFrom.bUseCollisionStaticMesh=True;
	HitActor=TraceFrom.BoneTrace(HitLocation,HitNormal,EndTrace,StartTrace,HitMaterial,HitBone,True);
	TraceFrom.bUseCollisionStaticMesh=False;
	if (HitActor == None)
	{
		Return 0;
	}
	AGP_Pawn(Instigator).NotifyTrace(Self,HitActor,"");
	if (HitActor == Instigator)
	{
		DebugLog(DEBUG_Bullet,"AGP_Weapon::DoTrace() Don't ever hit yourself");
		Return 0;
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame && GetNetMode() != ENetMode::NM_Client)
	{
		if (Instigator != None && Instigator.Controller != None && Instigator.Controller.IsA('PlayerController'))
		{
			MakeNoise(1,Self,True,HitLocation);
		}
	}
	if (btestdepth && TraceFrom.fPenetrationOverridePercent != 0)
	{
		fStrength=GetPenetrateStrength(HitActor,HitLocation,StartTrace,fStrength);
		if (fStrength < 0.1)
		{
			Return 0;
		}
	}
	VtoPV(HitLocation,BA.BulletTrace[num_traces]);
	BA.SetBulletImpactType(num_traces,0);
	GetCurrentAmmoType().ProcessTraceHit(Self,StartTrace,TraceDirection,HitActor,HitBone,HitLocation,HitNormal,HitMaterial,TraceDirection,Unused1,Unused2,fStrength);
	BA=BaseWeaponAttachment(ThirdPersonActor);
	if (BA == None)
	{
		Return 1;
	}
	if (CanTraceMore(BA,num_traces))
	{
		if (HitActor.bWorldGeometry || HitActor.bBulletRicochet)
		{
			CosTheta=Abs(- HitNormal Dot TraceDirection);
			if (CosTheta < GetRicochetThreshold(HitActor,HitMaterial) * FRand())
			{
				fStrength *= 0.9;
				TraceDirection=GetRicochetDirection(TraceDirection,HitNormal,CosTheta);
				fTraceDistance -= VSize(StartTrace - HitLocation);
				fTraceDistance *= fStrength;
				BA.SetBulletImpactType(num_traces,2);
				total_traces=DoTrace(HitActor,HitLocation,TraceDirection,fTraceDistance,fStrength,num_traces,BA,False);
				bDidRicochet=True;
			}
		}
		if (HitActor.bBulletPenetration && ! bDidRicochet)
		{
			fStrength *= GetPenetrationPercent(HitActor,HitMaterial);
			if (fStrength > 0.1)
			{
				DebugLog(DEBUG_Bullet,"AGP_Weapon::DoTrace() Penetrate! " $ fStrength);
				TraceDirection=GetPenetrateDirection(TraceDirection,fStrength);
				fTraceDistance -= VSize(StartTrace - HitLocation);
				fTraceDistance *= fStrength;
				BA.SetBulletImpactType(num_traces,1);
				total_traces=DoTrace(HitActor,HitLocation,TraceDirection,fTraceDistance,fStrength,num_traces,BA,True);
			}
			else
			{
				DebugLog(DEBUG_Bullet,"AGP_Weapon::DoTrace() Didn't penetrate " $ fStrength @ num_traces);
			}
		}
	}
	Return total_traces + 1;
	*/
}
void AAGP_Weapon::NPC_DoTrace (AActor* TraceFrom, FVector StartTrace, FVector TraceDirection, float fTraceDistance, float fStrength, int32 num_traces, ABaseWeaponAttachment* BA, bool btestdepth)
{
	/*
	local Actor HitActor;
	local Actor.BoneInfo HitBone;
	local Material HitMaterial;
	local FVector HitLocation;
	local FVector HitNormal;
	local float CosTheta;
	local bool bDidRicochet;
	local FVector EndTrace;
	local FVector Unused1;
	local FVector Unused2;
	local int total_traces;
	num_traces ++;
	EndTrace=StartTrace + fTraceDistance * TraceDirection;
	HitActor=TraceFrom.BoneTrace(HitLocation,HitNormal,EndTrace,StartTrace,HitMaterial,HitBone,True);
	if (HitActor == None)
	{
		Return 0;
	}
	if (btestdepth && TraceFrom.fPenetrationOverridePercent != 0)
	{
		fStrength=GetPenetrateStrength(HitActor,HitLocation,StartTrace,fStrength);
		if (fStrength < 0.1)
		{
			Return 0;
		}
	}
	VtoPV(HitLocation,BA.BulletTrace[num_traces]);
	BA.SetBulletImpactType(num_traces,0);
	GetCurrentAmmoType().NPC_ProcessTraceHit(Self,StartTrace,TraceDirection,HitActor,HitBone,HitLocation,HitNormal,HitMaterial,TraceDirection,Unused1,Unused2,fStrength);
	if (CanTraceMore(BA,num_traces))
	{
		if (HitActor.bWorldGeometry || HitActor.bBulletRicochet)
		{
			CosTheta=Abs(- HitNormal Dot TraceDirection);
			if (CosTheta < GetRicochetThreshold(HitActor,HitMaterial) * FRand())
			{
				fStrength *= 0.9;
				TraceDirection=GetRicochetDirection(TraceDirection,HitNormal,CosTheta);
				fTraceDistance -= VSize(StartTrace - HitLocation);
				fTraceDistance *= fStrength;
				BA.SetBulletImpactType(num_traces,2);
				total_traces=NPC_DoTrace(HitActor,HitLocation,TraceDirection,fTraceDistance,fStrength,num_traces,BA,False);
				bDidRicochet=True;
			}
		}
		if (HitActor.bBulletPenetration && ! bDidRicochet)
		{
			fStrength *= GetPenetrationPercent(HitActor,HitMaterial);
			if (fStrength > 0.1)
			{
				DebugLog(DEBUG_Bullet,"AGP_Weapon::DoTrace() Penetrate! " $ fStrength);
				TraceDirection=GetPenetrateDirection(TraceDirection,fStrength);
				fTraceDistance -= VSize(StartTrace - HitLocation);
				fTraceDistance *= fStrength;
				BA.SetBulletImpactType(num_traces,1);
				total_traces=NPC_DoTrace(HitActor,HitLocation,TraceDirection,fTraceDistance,fStrength,num_traces,BA,True);
			}
			else
			{
				DebugLog(DEBUG_Bullet,"AGP_Weapon::DoTrace() Didn't penetrate " $ fStrength @ num_traces);
			}
		}
	}
	Return total_traces + 1;
	*/
}
void AAGP_Weapon::RepeatFire ()
{
	//Return eROF == 3;
}
void AAGP_Weapon::CheckRapidMisfire (bool bRapid)
{
	/*
	if (! bRapid && RapidFireShots > -1)
	{
		if (Level.debugMisFire)
		{
			DebugLog(DEBUG_Bullet,"AGP_Weapon::CheckRapidMisfire bRapid == FALSE RapidFireShots" @ RapidFireShots @ "RapidFireShotsNeeded" @ RapidFireShotsNeeded);
		}
		if (RapidFireShots < RapidFireShotsNeeded)
		{
			if (RapidMisFireRand < RapidMisFirePct)
			{
				if (Level.debugMisFire)
				{
					DebugLog(DEBUG_Bullet,"AGP_Weapon::CheckRapidMisfire JAM!" @ RapidMisFirePct @ "RapidMisFireRand" @ RapidMisFireRand);
				}
				iNextMisFire=0;
			}
			else
			{
				CalcNextMisFire();
			}
		}
		RapidFireShots=-1;
	}
	else
	{
		RapidFireShots ++;
		if (Level.debugMisFire)
		{
			DebugLog(DEBUG_Bullet,"AGP_Weapon::CheckRapidMisfire RapidFireShots" @ RapidFireShots);
		}
	}
	*/
}
void AAGP_Weapon::CalcNextMisFire ()
{
	/*
	local int iNoMisfire;
	iNoMisfire=Clamp(iMisFire * 0.01,2,100);
	iNextMisFire=Rand(iMisFire - iNoMisfire) + iNoMisfire;
	RapidMisFireRand=FRand();
	ClientSendNextMisFire(iNextMisFire,RapidMisFireRand);
	if (Level.debugMisFire)
	{
		DebugLog(DEBUG_Bullet,"CALC iNextMisFire" @ iNextMisFire @ "RapidMisFireRand" @ RapidMisFireRand);
	}
	*/
}
void AAGP_Weapon::ClientSendNextMisFire (int32 NextW, float Rand)
{
	/*
	iNextMisFire=NextW;
	RapidMisFireRand=Rand;
	if (Level.debugMisFire)
	{
		DebugLog(DEBUG_Bullet,"SET iNextMisFire" @ iNextMisFire @ "RapidMisFireRand" @ RapidMisFireRand);
	}
	*/
}
void AAGP_Weapon::ServerRequestMisFireInfo ()
{
	/*
	if (Level.debugMisFire)
	{
		DebugLog(DEBUG_Bullet,"AGP_Weapon::ServerRequestMisFireInfo");
	}
	ClientSendNextMisFire(iNextMisFire,RapidMisFireRand);
	*/
}
void AAGP_Weapon::HandleMisFire ()
{
	/*
	if (Level.debugMisFire)
	{
		DebugLog(DEBUG_Bullet,"--------- MisFire ----------");
	}
	iPendingShots=0;
	bIsJammed=True;
	if (Level.debugMisFire)
	{
		DebugLog(DEBUG_Bullet,"Normal MisFire");
	}
	ClientHandleMisfire();
	GotoState('Jammed');
	*/
}
void AAGP_Weapon::ClientHandleMisfire ()
{
	/*
	bIsJammed=True;
	GotoState('Jammed');
	NotifyJammed();
	*/
}
void AAGP_Weapon::IncreaseElevation ()
{
	/*
	if (Elevation.Length == 0)
	{
		Return;
	}
	if (ElevationIndex + 1 < Elevation.Length)
	{
		ElevationIndex ++;
	}
	ServerSetElevation(ElevationIndex);
	if (GetNetMode() == ENetMode::NM_Client && IsInState('Idle'))
	{
		ClientFinish();
	}
	*/
}
void AAGP_Weapon::DecreaseElevation ()
{
	/*
	if (Elevation.Length == 0)
	{
		Return;
	}
	if (ElevationIndex != 0)
	{
		ElevationIndex --;
	}
	ServerSetElevation(ElevationIndex);
	if (GetNetMode() == ENetMode::NM_Client && IsInState('Idle'))
	{
		ClientFinish();
	}
	*/
}
void AAGP_Weapon::ZeroElevation ()
{
	/*
	if (Elevation.Length == 0)
	{
		Return;
	}
	ElevationIndex=Default.ElevationIndex;
	ServerSetElevation(ElevationIndex);
	if (GetNetMode() == ENetMode::NM_Client && IsInState('Idle'))
	{
		ClientFinish();
	}
	*/
}
void AAGP_Weapon::ServerSetElevation (int32 NewElevation)
{
	/*
	CurrentElevation=Elevation[NewElevation];
	if (IsInState('Idle'))
	{
		Finish();
	}
	*/
}
void AAGP_Weapon::SetGuerrillaWeapon (bool newGuerrillaWeap)
{
	/*
	if (GetNetMode() != ENetMode::NM_Client)
	{
		bGuerrillaWeapon=newGuerrillaWeap;
	}
	EnemyWeaponClass=Class;
	*/
}
void AAGP_Weapon::AttachToBack ()
{
	//AttachToBone(ThirdPersonActor,'LShoulder');
}
void AAGP_Weapon::GiveTo (APawn* Other, APickup* Pickup)
{
	/*
	if (AmmoType != None)
	{
		AmmoType.Instigator=Other;
	}
	if (AuxAmmoType != None)
	{
		AuxAmmoType.Instigator=Other;
	}
	if (Pickup != None && Pickup.EventLab != None)
	{
		SetEventLab(Pickup.EventLab);
	}
	Other.AddInventory(Self);
	bUnZoomASAP=False;
	bInZoom=False;
	bTossedOut=False;
	Instigator=Other;
	LoadWeaponMods();
	SetupModAttachments();
	GiveAmmo(None);
	SetTeamOwner();
	sleeve_tag=GetSleeve(True);
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		SetupClientWeapon();
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		SpawnAndAttachScope();
	}
	*/
}
void AAGP_Weapon::SpawnAndAttachScope ()
{
	/*
	if (_cScopeClass != None)
	{
		_Scope=Spawn(_cScopeClass,Self);
		if (_Scope.DrawType != 0)
		{
			AttachToBone(_Scope,'Muzzle');
		}
	}
	*/
}
void AAGP_Weapon::OwnerRecieved ()
{
	//ServerRequestMisFireInfo();
}
void AAGP_Weapon::IsLegalMod (ABaseWeaponMod* cmod)
{
	/*
	local int i;
	for (i=0; i<Default.LegalModList.Length; i++)
	{
		if (Default.LegalModList[i] == cmod)
		{
			Return True;
		}
	}
	Return False;
	*/
}
void AAGP_Weapon::LoadWeaponMods ()
{
	/*
	local int i;
	local BaseWeaponMod WM;
	local string nameWM;
	if (bAlreadyLoadedMods)
	{
		Return;
	}
	if (! bLoadModsFromPickup)
	{
		for (i=0; i<6; i++)
		{
			nameWM=GetWeaponModName(i);
			if (WM_Default[i] ~= "NoMod" || nameWM ~= WM_Default[i])
			{
			}
			CreateWeaponMod(nameWM,i);
		}
	}
	LoadDefaultMods();
	num_mods=0;
	WM=WeaponModList;
	if (WM != None)
	{
		num_mods ++;
		WM=WM.NextWeaponMod;
	}
	bAlreadyLoadedMods=True;
	*/
}
void AAGP_Weapon::SetupModAttachments ()
{
	/*
	if (ThirdPersonActor != None)
	{
		BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(Self);
		BaseWeaponAttachment(ThirdPersonActor).SpawnModAttachments(Self);
	}
	*/
}
void AAGP_Weapon::GetWeaponModName (int32 i)
{
/*
	local string nameWM;
	local AGP_Pawn p;
	local HumanController HC;
	p=AGP_Pawn(Owner);
	if (p == None || p.TeamClass == None)
	{
		Return "";
	}
	nameWM=p.TeamClass.WM_Override[i];
	if (nameWM == "")
	{
		HC=HumanController(p.Controller);
		if (HC == None)
		{
			Return "";
		}
		else
		{
			nameWM=HC.WM_Slot[i];
		}
	}
	Return nameWM;
*/
}
void AAGP_Weapon::LoadDefaultMods ()
{
	/*
	local BaseWeaponMod WM;
	local byte SlotFull;
	local int i;
	WM=WeaponModList;
	if (WM != None)
	{
		SlotFull[WM.ModSlot]=1;
		WM=WM.NextWeaponMod;
	}
	for (i=0; i<6; i++)
	{
		if (WM_Default[i] ~= "NoMod" || SlotFull[i] == 1)
		{
		}
		CreateWeaponMod(WM_Default[i],i);
	}
	*/
}
void AAGP_Weapon::CreateWeaponMod (FString nameWM, int32 Slot)
{
	/*
	local class<BaseWeaponMod>  classWM;
	local BaseWeaponMod WM;
	if (nameWM == "" || nameWM ~= "none")
	{
		Return;
	}
	classWM=class<BaseWeaponMod>(DynamicLoadObject(nameWM,Class'Class'));
	WM=Spawn(classWM,Owner);
	if (WM == None)
	{
		DebugLog(DEBUG_Warn,"AGP_Weapon::CreateWeaponMod()	Unknown mod (" @ nameWM @ ")");
		Return;
	}
	if (WM.AttachToWeapon(Self,Slot))
	{
		AddWeaponMod(WM);
	}
	else
	{
		DebugLog(DEBUG_Inv,"AGP_Weapon::CreateWeaponMod() Can't attach!" @ WM);
		WM.Destroy();
	}
	*/
}
void AAGP_Weapon::AddWeaponMod (ABaseWeaponMod* WM)
{
	/*
	if (WeaponModList == None)
	{
		WeaponModList=WM;
	}
	else
	{
		WM.NextWeaponMod=WeaponModList;
		WeaponModList=WM;
	}
	*/
}
void AAGP_Weapon::NotifyWeaponModAnimations (FName Sequence, float Rate, float TweenTime, bool bLoop)
{
	/*
	local BaseWeaponMod WM;
	WM=WeaponModList;
	if (WM != None)
	{
		WM.NotifyWeaponAnimation(Sequence,Rate,TweenTime,bLoop);
		WM=WM.NextWeaponMod;
	}
	*/
}
void AAGP_Weapon::NotifyWeaponModZoom ()
{
	/*
	local BaseWeaponMod WM;
	WM=WeaponModList;
	if (WM != None)
	{
		WM.NotifyWeaponZoom(IsZoomed());
		WM=WM.NextWeaponMod;
	}
	*/
}
void AAGP_Weapon::UpdateCurrentAmmoRounds (bool bRoundInBreech)
{
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		Return;
	}
	if (GetCurrentAmmoType() == AmmoType)
	{
		if (AmmoRoundList != None)
		{
			AmmoRoundList.bRoundInBreech=bRoundInBreech;
			AmmoRoundList.AdjustAmmoRound(AmmoType.AmmoAmount);
		}
	}
	else
	{
		if (AuxAmmoRoundList != None)
		{
			AuxAmmoRoundList.AdjustAmmoRound(AuxAmmoType.AmmoAmount);
		}
	}
	*/
}
void AAGP_Weapon::SpawnSingleAmmoRound (bool bAux, int32 ammo_id, bool bSpecial)
{
	/*
	local BaseAmmoRound Ar;
	local class<BaseAmmoRound>  ARClass;
	if (bAux)
	{
		ARClass=AuxAmmoRoundClass;
	}
	else
	{
		if (bSpecial)
		{
			ARClass=SpecialAmmoRoundClass;
		}
		else
		{
			ARClass=AmmoRoundClass;
		}
	}
	Ar=Spawn(ARClass,Instigator);
	Ar.SetAmmoID(ammo_id);
	AttachToBone(Ar,Ar.GetBoneNameForAmmoAttach(bAux,bSpecial));
	Ar.SetDrawScale(DrawScale);
	Return Ar;
	*/
}
void AAGP_Weapon::SpawnAndAttachAmmoRounds ()
{
	/*
	local BaseAmmoRound Ar;
	local int i;
	if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer() && AmmoRoundClass != None && AmmoRoundList == None)
	{
		AmmoRoundList=SpawnSingleAmmoRound(False,1);
		Ar=AmmoRoundList;
		for (i=2; i<=NumAmmoRounds; i++)
		{
			Ar.NextAmmoRound=SpawnSingleAmmoRound(False,i);
			Ar=Ar.NextAmmoRound;
		}
		AmmoRoundList.AdjustAmmoRound(AmmoType.AmmoAmount);
	}
	if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer() && AuxAmmoRoundClass != None && AuxAmmoRoundList == None)
	{
		AuxAmmoRoundList=SpawnSingleAmmoRound(True,1);
		Ar=AuxAmmoRoundList;
		for (i=2; i<=NumAuxAmmoRound; i++)
		{
			Ar.NextAmmoRound=SpawnSingleAmmoRound(True,i);
			Ar=Ar.NextAmmoRound;
		}
		AuxAmmoRoundList.AdjustAmmoRound(AuxAmmoType.AmmoAmount);
	}
	if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer() && SpecialAmmoRoundClass != None && SpecialAmmoRoundList == None)
	{
		SpecialAmmoRoundList=SpawnSingleAmmoRound(False,1,True);
		Ar=SpecialAmmoRoundList;
		for (i=2; i<=NumSpecialAmmoRounds; i++)
		{
			Ar.NextAmmoRound=SpawnSingleAmmoRound(False,i,True);
			Ar=Ar.NextAmmoRound;
		}
		SpecialAmmoRoundList.AdjustSpecialAmmoRounds(False);
	}
	*/
}
void AAGP_Weapon::SpawnAndAttachMILESGear ()
{
	/*
	local class<Actor>  aClass;
	if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer() && Level.GamePlayMode == 1)
	{
		if (BlankPlug == None)
		{
			aClass=class<Actor>(DynamicLoadObject("AGP_Inventory.WAttch_BlankPlug_1P",Class'Class'));
			BlankPlug=Spawn(aClass,Instigator);
		}
		AttachToBone(BlankPlug,'Muzzle');
		BlankPlug.SetDrawScale3D(_sBlankPlugScale);
		if (MILESBox == None)
		{
			aClass=class<Actor>(DynamicLoadObject("AGP_Inventory.WAttch_MILESBox_1P",Class'Class'));
			MILESBox=Spawn(aClass,Instigator);
		}
		AttachToBone(MILESBox,'Muzzle');
		MILESBox.SetRelativeLocation(_vMILESBoxOffset);
		MILESBox.SetDrawScale3D(_sMILESBoxScale);
	}
	*/
}
void AAGP_Weapon::IsReplicationComplete ()
{
	/*
	local BaseWeaponMod WM;
	local int found_mods;
	if (Pawn(Owner) == None)
	{
		Return False;
	}
	if (sleeve_tag == "")
	{
		Return False;
	}
	if (GetCurrentAmmoType() == None && AmmoName != None)
	{
		Return False;
	}
	WM=WeaponModList;
	if (WM != None)
	{
		found_mods ++;
		WM=WM.NextWeaponMod;
	}
	Return num_mods == found_mods;
	*/
}
void AAGP_Weapon::NotifyReplicationComplete ()
{
	/*
	SetupClientWeapon();
	ServerNotifyReplicationComplete();
	*/
}
void AAGP_Weapon::SetupClientWeapon ()
{
	/*
	Instigator=Pawn(Owner);
	SpawnAndAttachAmmoRounds();
	SpawnAndAttachMILESGear();
	SetWeaponSkins();
	SpawnMuzzleFlash();
	SpawnAndAttachScope();
	UpdateCurrentAmmoRounds();
	if (ThirdPersonActor != None)
	{
		BaseWeaponAttachment(ThirdPersonActor).InitializeShellEmitter();
	}
	if (bBusyRaiseWeaponPending)
	{
		GotoState('BusyRaisingWeapon');
		bBusyRaiseWeaponPending=False;
	}
	*/
}
void AAGP_Weapon::SpawnMuzzleFlash ()
{
	/*
	if (_FPAuxMuzzleFlashClass != None)
	{
		AuxMuzzleFlashEmitter=BaseMuzzleFlashEmitter(Spawn(_FPAuxMuzzleFlashClass,Self));
	}
	if (_FPSuppressedMuzzleFlashClass != None)
	{
		SuppressedMuzzleFlashEmitter=BaseMuzzleFlashEmitter(Spawn(_FPSuppressedMuzzleFlashClass,Self));
	}
	*/
}
void AAGP_Weapon::SetWeaponSkins ()
{
	/*
	local BaseWeaponMod WM;
	Level.SetActorLevelSkin(Self,True);
	WM=WeaponModList;
	if (WM != None)
	{
		Level.SetActorLevelSkin(WM,True);
		WM=WM.NextWeaponMod;
	}
	*/
}
void AAGP_Weapon::GetActorLevelSkin (int32 Index, UTexture2D* old_material, FString level_tag)
{
	/*
	Switch(Index)
	{
		case 0:
		if (Index >= Instigator.Skins.Length)
		{
			Return GetActorLevelSkin(Index,old_material,level_tag);
			break;
		}
		if (Instigator.Skins.Length > 2)
		{
			Return Instigator.Skins[2] $ special_tag $ "_1P";
			break;
		}
		Return old_material;
	}
	case 1:
	if (Right(AGP_Pawn(Instigator).Mesh,3) ~= "ACU")
	{
		Return "T_AA2_Skins.weapon.skn_weap_camosleeve_new_frst";
	}
	else
	{
		Return "T_AA2_Skins.weapon.skn_weap_camosleeve" $ special_tag $ "_" $ sleeve_tag;
	}
	default:
	Return GetActorLevelSkin(Index,old_material,level_tag);
	*/
}
void AAGP_Weapon::GetSleeve (bool bFriendly)
{
	/*
	if (Instigator != None && Instigator.PlayerReplicationInfo != None && Instigator.PlayerReplicationInfo.bGuerrillaPS)
	{
		Return "Green";
	}
	Switch(Level.GetSkinSet(bFriendly))
	{
		case 5:
		case 7:
		case 0:
		Return "Frst";
		case 1:
		Return "Dsrt";
		case 10:
		case 4:
		Return "Arctic";
		default:
		Return "INVALID";
	}
	*/
}
void AAGP_Weapon::GiveAmmo (APawn* p)
{
	/*
	if (p != None)
	{
		Return;
	}
	if (AmmoName == None)
	{
		Return;
	}
	if (AmmoType == None)
	{
		AmmoType=Spawn(AmmoName,Instigator);
		if (AmmoType != None)
		{
			AmmoType.AmmoAmount=PickupAmmoCount;
			AmmoType.Instigator=Instigator;
			AmmoType.GotoState('None');
		}
	}
	if (AuxAmmoType == None)
	{
		AuxAmmoType=Spawn(AuxAmmoName,Instigator);
		if (AuxAmmoType != None)
		{
			AuxAmmoType.AmmoAmount=AuxPickupAmmoCount;
			AuxAmmoType.Instigator=Instigator;
			AuxAmmoType.GotoState('None');
		}
	}
	*/
}
void AAGP_Weapon::RecountAmmo ()
{
	
	int32 i;
	AmmoMagCount=0;
	for (i=0; i<16; i++)
	{
		if (_AmmoClips[i] > 0)
		{
			AmmoMagCount ++;
		}
	}
	AuxAmmoMagCount=0;
	if (AuxAmmoType != NULL)
	{
		for (i=0; i<16; i++)
		{
			if (_AuxAmmoClips[i] > 0)
			{
				AuxAmmoMagCount ++;
			}
		}
	}
	
}
void AAGP_Weapon::TravelPostAccept ()
{
	/*
	if (Pawn(Owner) == None)
	{
		Return;
	}
	if (AuxAmmoName != None)
	{
		AuxAmmoType=Ammunition(Pawn(Owner).FindInventoryType(AuxAmmoName));
		if (AuxAmmoType == None)
		{
			AuxAmmoType=Spawn(AuxAmmoName);
			Pawn(Owner).AddInventory(AuxAmmoType);
			AuxAmmoType.AmmoAmount=AuxPickupAmmoCount;
			AuxAmmoType.GotoState('None');
		}
	}
	TravelPostAccept();
	*/
}
void AAGP_Weapon::GetPendingShots ()
{
	/*
	Switch(eROF)
	{
		case 2:
		Return BurstPendingShots;
		case 3:
		Return AutoPendingShots;
		default:
		Return 0;
	}
	*/
}
void AAGP_Weapon::Fire (float Value)
{
	/*
	local bool bRapid;
	local bool bAdjust;
	local bool bBreatheBonus;
	if (Instigator == None)
	{
		Log("---- ERROR ----");
		Log("Fire requested with instigator None");
		Return;
	}
	if (Instigator.Controller != None && Instigator.Controller.IsInState('DelayedStart'))
	{
		Return;
	}
	bRapid=Value != 0;
	bBreatheBonus=Abs(Instigator.fZoomCycle) < 0.2 * Instigator.CE_MeterValue;
	if (! AGP_Pawn(Instigator).AllowAnimFiring() && eROF == 2 && GetPendingShots() <= 0 && Instigator.UpperBodyAnim != 6 && Instigator.UpperBodyAnim != 40 && Instigator.UpperBodyAnim != 69 && Instigator.UpperBodyAnim != 74 && Instigator.UpperBodyAnim != 34 && Instigator.UpperBodyAnim != 26 && Instigator.UpperBodyAnim != 30)
	{
		Return;
	}
	if (Instigator.Physics == 2)
	{
		iPendingShots=0;
		AutoPendingShots=0;
		Return;
	}
	if (iPendingShots <= 0)
	{
		if (eROF != 3 || ConsecutiveShots <= AutoPendingShots)
		{
			bAdjust=True;
			iPendingShots=GetPendingShots();
		}
	}
	else
	{
		if (eROF == 3)
		{
			bAdjust=True;
		}
		iPendingShots --;
	}
	if (GetCurrentAmmoType() != None && ! GetCurrentAmmoType().HasAmmo() || IsJammed())
	{
		DryFire();
		if (AGP_Pawn(Instigator) != None)
		{
			if (IsJammed())
			{
				if (AGP_Pawn(Instigator) != None)
				{
					AGP_Pawn(Instigator).NotifyFire(Self,"FIREJAMMED");
				}
			}
			else
			{
				if (AGP_Pawn(Instigator) != None)
				{
					AGP_Pawn(Instigator).NotifyFire(Self,"FIREEMPTY");
				}
			}
		}
		Return;
	}
	if (AGP_Pawn(Instigator) != None)
	{
		AGP_Pawn(Instigator).NotifyFire(Self,"FIRE");
	}
	if (AGP_Pawn(Instigator) != None && AGP_Pawn(Instigator)._FireMonitor != None)
	{
		AGP_Pawn(Instigator)._FireMonitor.Notify();
	}
	ServerFire(! bAdjust,bRapid,bBreatheBonus);
	if (Role < 4)
	{
		iNextMisFire --;
		if (bMisFireOnRapid)
		{
			CheckRapidMisfire(bRapid);
		}
		if (! bMisFire || iNextMisFire > 0)
		{
			GotoState('BusyFiring');
		}
	}
	*/
}
void AAGP_Weapon::NPC_Fire (float Value, APawn* Enemy)
{
	/*
	local bool bRapid;
	local bool bAdjust;
	local bool bBreatheBonus;
	bRapid=Value != 0;
	bBreatheBonus=Abs(Instigator.fZoomCycle) < 0.2 * Instigator.CE_MeterValue;
	if (iPendingShots <= 0)
	{
		bAdjust=True;
		iPendingShots=GetPendingShots();
	}
	else
	{
		iPendingShots --;
	}
	if (Instigator == None)
	{
		Return;
	}
	if (GetCurrentAmmoType() != None && ! GetCurrentAmmoType().HasAmmo())
	{
		if (Level.debugShoot)
		{
			DebugLog(DEBUG_Inv,"AGP_Weapon::Fire() - Has no ammo");
		}
		DryFire();
		Return;
	}
	if (AGP_Pawn(Instigator) != None && AGP_Pawn(Instigator)._FireMonitor != None)
	{
		AGP_Pawn(Instigator)._FireMonitor.Notify();
	}
	ServerFire(! bAdjust,bRapid,bBreatheBonus);
	if (Instigator.Controller != None && HumanController(Instigator.Controller) != None && HumanController(Instigator.Controller).bPrintShootDebug)
	{
		HumanController(Instigator.Controller).PrintShoot();
	}
	if (Role < 4)
	{
		iNextMisFire --;
		if (bMisFireOnRapid)
		{
			CheckRapidMisfire(bRapid);
		}
		if (! bMisFire || iNextMisFire > 0)
		{
			GotoState('BusyFiring');
		}
		else
		{
			if (Level.debugMisFire)
			{
				DebugLog(DEBUG_Bullet,"PREDICTED MISFIRE" @ bMisFire @ iNextMisFire);
			}
		}
	}
	*/
}
void AAGP_Weapon::AltFire (float Value)
{
	//ChangeFireMode();
}
void AAGP_Weapon::StartCrawling ()
{
	/*
	if (Instigator == None || Instigator.bIsWalking)
	{
		Return;
	}
	if (Instigator.Controller != None)
	{
		Instigator.Controller.StopFiring();
	}
	GotoState('InCrawling');
	*/
}
void AAGP_Weapon::StopCrawling ()
{
}
void AAGP_Weapon::SetSupported (bool newSupported)
{
	/*
	if (newSupported == IsSupported())
	{
		Return;
	}
	ServerSetSupported(newSupported);
	if (GetNetMode() == ENetMode::NM_Client)
	{
		bIsSupported=! bIsSupported;
		GotoState('BusySupporting');
	}
	*/
}
void AAGP_Weapon::ServerSetSupported (bool newSupported)
{
	/*
	bIsSupported=! bIsSupported;
	GotoState('BusySupporting');
	*/
}
void AAGP_Weapon::ServerNotifyReplicationComplete ()
{
	/*
	if (bBusyRaiseWeaponPending)
	{
		GotoState('BusyRaisingWeapon');
		bBusyRaiseWeaponPending=False;
	}
	*/
}
void AAGP_Weapon::ChangeFireMode ()
{
	/*
	if (eROF == AuxROF)
	{
		ChangeAuxMode(2);
		Return;
	}
	ServerChangeFireMode();
	if (GetNetMode() == ENetMode::NM_Client)
	{
		GotoState('BusyChangingFireMode');
	}
	*/
}
void AAGP_Weapon::ServerChangeFireMode ()
{
	//GotoState('BusyChangingFireMode');
}
void AAGP_Weapon::FixJam ()
{
	/*
	if (GetCurrentAmmoType().AmmoAmount == 0 || eROF == AuxROF)
	{
		Return;
	}
	ServerFixJam();
	if (GetNetMode() == ENetMode::NM_Client)
	{
		GotoState('BusyFixingJam');
	}
	*/
}
void AAGP_Weapon::ServerFixJam ()
{
	//GotoState('BusyFixingJam');
}
void AAGP_Weapon::Reload ()
{
	/*
	if (Instigator != None && Instigator.Controller != None && HumanController(Instigator.Controller) != None && HumanController(Instigator.Controller).IsInState('None'))
	{
		Return;
	}
	GotoState('BusyReloading');
	*/
}
void AAGP_Weapon::TempLowerWeapon (bool bActive)
{
	/*
	if (GetNetMode() == ENetMode::NM_Client)
	{
		Return;
	}
	_bActive=bActive;
	GotoState('BusyTempLowering');
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		ClientTempLowerWeapon(_bActive);
	}
	*/
}
void AAGP_Weapon::ClientTempLowerWeapon (bool bActive)
{
	/*
	_bActive=bActive;
	GotoState('BusyTempLowering');
	*/
}
void AAGP_Weapon::TempRaiseWeapon ()
{
}
void AAGP_Weapon::GuardWeapon ()
{
	//GuardTimer=1;
}
void AAGP_Weapon::GetSuppressor ()
{
	/*
	local BaseWeaponMod WM;
	WM=WeaponModList;
	if (WM != None)
	{
		if (WM.IsSuppressor())
		{
			Return WM;
		}
		WM=WM.NextWeaponMod;
	}
	Return None;
	*/
}
void AAGP_Weapon::IsSuppressed ()
{
	//Return bSuppressorOn;
}
void AAGP_Weapon::ToggleSuppressor ()
{
	/*
	if (GetSuppressor() != None)
	{
		ServerToggleSuppressor();
		if (GetNetMode() == ENetMode::NM_Client)
		{
			GotoState('BusySuppressor');
		}
	}
	*/
}
void AAGP_Weapon::ServerToggleSuppressor ()
{
	//GotoState('BusySuppressor');
}
void AAGP_Weapon::DoSuppressor (bool bNewSuppressor)
{
	/*
	bSuppressorOn=bNewSuppressor;
	if (bSuppressorOn)
	{
		_FPMuzzleFlashEmitter=SuppressedMuzzleFlashEmitter;
		if (_FPMuzzleFlashEmitter != None)
		{
			AttachToBoneOffset(_FPMuzzleFlashEmitter,_FPSuppressedMuzzleFlashOffset);
		}
	}
	else
	{
		_FPMuzzleFlashEmitter=NormalMuzzleFlashEmitter;
		if (_FPMuzzleFlashEmitter != None)
		{
			AttachToBoneOffset(_FPMuzzleFlashEmitter,_FPMuzzleFlashOffset);
		}
	}
	*/
}
void AAGP_Weapon::PlaySuppressor ()
{
	/*
	if (IsSuppressed())
	{
		if (IsSupported())
		{
			RunAnimation('SupportedSuppressorOn',1);
		}
		else
		{
			RunAnimation('SuppressorOn',1);
		}
		PlayWeaponSound(SuppressorOnSound,EnemyWeaponClass.Default.SuppressorOnSound);
	}
	else
	{
		if (IsSupported())
		{
			RunAnimation('SupportedSuppressorOff',1);
		}
		else
		{
			RunAnimation('SuppressorOff',1);
		}
		PlayWeaponSound(SuppressorOffSound,EnemyWeaponClass.Default.SuppressorOffSound);
	}
	*/
}
void AAGP_Weapon::ToggleLeftRail ()
{
	/*
	local BaseWeaponMod WM;
	WM=WeaponModList;
	if (WM != None)
	{
		if (WM.AttachmentBone == 'RailLT')
		{
			WM.Toggle();
			Return;
		}
		WM=WM.NextWeaponMod;
	}
	*/
}
void AAGP_Weapon::ToggleRightRail ()
{
	/*
	local BaseWeaponMod WM;
	WM=WeaponModList;
	if (WM != None)
	{
		if (WM.AttachmentBone == 'RailRT')
		{
			WM.Toggle();
			Return;
		}
		WM=WM.NextWeaponMod;
	}
	*/
}
void AAGP_Weapon::CanZoom ()
{
	//Return False;
}
void AAGP_Weapon::CalcZoomWander ()
{
	//Return CalcRotation(_ZoomDirInfo);
}
void AAGP_Weapon::CycleZoom ()
{
	/*
	if (_Scope != None && Instigator != None && Instigator.Controller != None)
	{
		_Scope.CycleZoom(PlayerController(Instigator.Controller));
	}
	*/
}
void AAGP_Weapon::ToggleZoom ()
{
	/*
	if (Level.debugZoom)
	{
		DebugLog(DEBUG_Inv,"AGP_Weapon::ToggleZoom urrent weapon state is " $ GetStateName());
	}
	if (CanZoom())
	{
		ServerZoom(! IsZoomed());
		if (GetNetMode() == ENetMode::NM_Client)
		{
			DoZoom(! IsZoomed());
		}
	}
	*/
}
void AAGP_Weapon::ForceUnzoom (bool bForce)
{
	/*
	if (Level.debugZoom)
	{
		DebugLog(DEBUG_Inv,"AGP_Weapon::ForceUnzoom " $ CanZoom() @ IsZoomed());
	}
	if (CanZoom() && IsZoomed())
	{
		ServerZoom(False);
		if (GetNetMode() == ENetMode::NM_Client)
		{
			DoZoom(False);
		}
	}
	else
	{
		if (bForce)
		{
			bUnZoomASAP=True;
		}
	}
	*/
}
void AAGP_Weapon::ServerZoom (bool bNewZoomDir)
{
	/*
	if (Level.debugZoom)
	{
		DebugLog(DEBUG_Inv,"AGP_Weapon::ServerZoom");
	}
	DoZoom(bNewZoomDir);
	*/
}
void AAGP_Weapon::DoZoom (bool DoZoomDir)
{
	/*
	bZoomDir=DoZoomDir;
	if (Level.debugZoom)
	{
		DebugLog(DEBUG_Inv,"AGP_Weapon::DoZoom Current weapon state is " $ GetStateName());
	}
	if (GetNetMode() != ENetMode::NM_Client && Instigator != None)
	{
		Instigator.SetZoomed(DoZoomDir);
	}
	GotoState('BusyZooming');
	*/
}
void AAGP_Weapon::UnZoom ()
{
	/*
	local PlayerController PC;
	if (_Scope == None)
	{
		Return;
	}
	if (Level.debugZoom)
	{
		DebugLog(DEBUG_Inv,"AGP_Weapon::UnZoom");
	}
	if (Instigator != None)
	{
		if (GetNetMode() != ENetMode::NM_Client)
		{
			Instigator.SetZoomed(False);
		}
		if (GetNetMode() != ENetMode::NM_DedicatedServer && Instigator.Controller != None && Instigator.Controller.IsA('HumanController') && HumanController(Instigator.Controller).bAutoWalkZoom)
		{
			Instigator.SetWalking(HumanController(Instigator.Controller).bSavedWalkingState);
		}
		if (Instigator.Controller != None && Instigator.Controller.IsA('PlayerController'))
		{
			PC=PlayerController(Instigator.Controller);
			if (PC != None)
			{
				PC.CalcSoundDampening();
				_Scope.UnZoom(PC);
			}
		}
		else
		{
			if (Instigator.Controller != None && Instigator.IsA('AIController'))
			{
				if (_Scope != None)
				{
					_Scope.GotoState('None');
				}
			}
		}
	}
	NotifyWeaponModZoom();
	*/
}
void AAGP_Weapon::Zoom ()
{
	/*
	local PlayerController PC;
	if (_Scope == None)
	{
		Return;
	}
	if (Level.debugZoom)
	{
		DebugLog(DEBUG_Inv,"AGP_Weapon::Zoom");
	}
	if (Instigator != None && Instigator.Controller != None && Instigator.Controller.IsA('PlayerController'))
	{
		PC=PlayerController(Instigator.Controller);
		if (PC != None)
		{
			PC.CalcSoundDampening();
			_Scope.Zoom(PC);
		}
	}
	else
	{
		if (Instigator.Controller != None && Instigator.IsA('AIController'))
		{
			if (_Scope != None)
			{
				_Scope.GotoState('Zoomed');
			}
		}
	}
	NotifyWeaponModZoom();
	*/
}
bool AAGP_Weapon::IsZoomed ()
{
	return _Scope != NULL && Cast<ABaseScope>(_Scope)->IsZoomed();
}
bool AAGP_Weapon::ShouldBreatheCycle ()
{
	return IsZoomed();
}
float AAGP_Weapon::GetZoomMultiplier ()
{
	if (IsZoomed() && _Scope != NULL)
	{
		return Cast<ABaseScope>(_Scope)->GetZoomMultiplier();
	}
	else
	{
		return 1.0f;
	}
}
bool AAGP_Weapon::IsCharged ()
{
	return true;
}
bool AAGP_Weapon::IsJammed ()
{
	return (bIsJammed && eROF != RateofFire::ROF_SingleGren);
}
bool AAGP_Weapon::IsOpFor ()
{
	return bWeaponIsOpFor;
}
void AAGP_Weapon::Finish ()
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugWeaponState)
	{
		//DebugLog(DEBUG_Inv,Self @ "AGP_Weapon::Finish - Instigator" @ Instigator @ "Controller" @ Instigator.Controller);
	}
	/*
	if (Instigator == None || Instigator.Controller == None)
	{
		GotoState('None');
		Return;
	}
	GotoState('Idle');
	*/
}
void AAGP_Weapon::ClientFinish ()
{
	
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugWeaponState)
	{
		//DebugLog(DEBUG_Inv,Self @ "AGP_Weapon::ClientFinish - Instigator" @ Instigator @ "Controller" @ Instigator.Controller);
	}
	/*
	if (Instigator == nullptr || Instigator.Controller == nullptr)
	{
		GotoState('None');
		return;
	}
	GotoState('Idle');
	*/
}
void AAGP_Weapon::Tick (float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bPendingChangeWeapon)
	{
		if (PendingChangeWeaponTimeStamp < GetWorld()->GetTimeSeconds())
		{
			bPendingChangeWeapon=false;
		}
	}
	if (GuardTimer > 0)
	{
		GuardTimer -= DeltaTime;
	}
	else
	{
		/*
		if (Instigator != None && ! IsBusy() && ! Instigator.bIsProne)
		{
			Switch(Instigator.UpperBodyAnim)
			{
				case 69:
				case 74:
				case 6:
				case 26:
				case 30:
				case 34:
				case 40:
				TempLowerWeapon(True);
				default:
			}
		}
		*/
	}
}
bool AAGP_Weapon::CanUseWeapon(int32 DesiredAction)
{
	switch(DesiredAction)
	{
		case WEAPON_ACTION_DROP:
			return !IsSupported();
		case WEAPON_ACTION_RELOAD:
			return !CheckForNoReload();
		case WEAPON_ACTION_SUPPORT:
			return !bPendingChangeWeapon;
		default:
			return true;
	}
}
bool AAGP_Weapon::CanSprint ()
{
	//Return ! IsBusy() || AnimIsInGroup(0,'Crawling');
	return false;   //Fake /ELiZ
}
void AAGP_Weapon::CanCombatRoll(bool bActual)
{
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		Return True;
	}
	else
	{
		Return ! IsBusy() || AnimIsInGroup(0,'Crawling');
	}
	*/
}
EUpperBodyAnim AAGP_Weapon::GetUpperBodyLowerAnim ()
{
	return EUpperBodyAnim::UBANIM_WEAP_LowerLg;
}
EUpperBodyAnim AAGP_Weapon::GetUpperBodyRaiseAnim()
{
	return EUpperBodyAnim::UBANIM_WEAP_RaiseLg;
}
EUpperBodyAnim AAGP_Weapon::GetUpperBodyReadyAnim()
{
	return EUpperBodyAnim::UBANIM_NONE_Large;
}
AInventory* AAGP_Weapon::GetSwapContainer ()
{
	if (Cast<AAGP_Pawn>(GetInstigator()) != NULL)
	{
		return Cast<AAGP_Pawn>(GetInstigator())->getInvContainerShoulder();
	}
	return NULL;
}
void AAGP_Weapon::ForceTempRaiseWeapon ()
{
	/*
	if (GetNetMode() == ENetMode::NM_Client)
	{
		Return;
	}
	GotoState('BusyTempRaising');
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		ClientGotoState('BusyTempRaising','None');
	}
	*/
}
bool AAGP_Weapon::IsBusy()
{
	return false;
}

/* ======================================================================================
 * AGP Function getMyType
 *
 * Returns the weapon's type (in terms of EContactSpecialWeapons enum in Actor).
 *
 * input:	none
 * output: EContactSpecialWeapons - the type of the weapon
 * effects: none
 * notes:   only implemented for weapons current 28 November 2001
 * last modified by: dnback
 * ======================================================================================
 */
EContactSpecialWeapons AAGP_Weapon::getMyType()
{
	return Type;
}
void AAGP_Weapon::SetFastMove (bool fast)
{
}
void AAGP_Weapon::ShouldDrawCrosshair ()
{
	/*
	local BaseWeaponMod WM;
	if (IsZoomed() && ! bDebugSights)
	{
		Return False;
	}
	WM=WeaponModList;
	if (WM != None)
	{
		if (WM.IsA('WeaponMod_Anpeq5_Laser'))
		{
			Return False;
		}
		WM=WM.NextWeaponMod;
	}
	return true;
	*/
}

/*
 // ======================================================================================
 // AGP function - GetROFString
 // Gets the string name of the eROF enumerator for printout on the HUD
 // output:	String label of the firing mode
 // last modified by:  superville 03/13/02
 // ======================================================================================
*/

FString AAGP_Weapon::getROFString()
{
	switch(eROF)
	{
		case RateofFire::ROF_Single:			return "Single";
		case RateofFire::ROF_Burst:				return "Burst";
		case RateofFire::ROF_Auto:				return "Auto";
		case RateofFire::ROF_SingleGren:		return "Grenade - Single";
		default:								return "";
	}
}

/* =================================================================================== *
 * AGP function GetBreatheMultiplier()
 *	Lighter weapons (<5kg) have smaller breathe cycles.
 *
 * output:	float - multiplier to apply to the breathe cycle
 * last modified by: cmb
 * =================================================================================== */

float AAGP_Weapon::GetBreatheMultiplier()
{
	if (fWeight >= 5)
	{
		return 1;
	}
	else
	{
		return (fWeight + 1.0) / 6.0;	//range [0.16 , 1.0]
	}
}

/*
 // ======================================================================================
 // AGP function - AmmoStatus (Overrides Weapon)
 // Returns the percentage of ammo left in the gun for the ammotype currently being used
 // output: float [0,1] percentage of ammo left in the gun related to it's max count
 // last modified by:  superville 03/15/02
 // ======================================================================================
*/
void AAGP_Weapon::AmmoStatus ()
{
	/*
	if (GetCurrentAmmoType() != None)
	{
		Return GetCurrentAmmoType().AmmoAmount / GetCurrentAmmoType().MaxAmmo;
	}
	return 0;
	*/
}

/*
 // ======================================================================================
 // AGP function - HasAmmo (Overrides Weapon)
 // Determines if weapon currently has ammo based on the current ammotype
 // output:	bool true if the weapon has ammo in it, false otherwise
 // last modified by:  superville 03/15/02
 // ======================================================================================
*/
void AAGP_Weapon::HasAmmo ()
{
	/*
	local int i;
	if (GetCurrentAmmoType() != None)
	{
		if (GetCurrentAmmoType().HasAmmo())
		{
			Return True;
		}
	}
	for (i=0; i<16; i++)
	{
		if (GetClipCount(i) > 0)
		{
			Return True;
		}
	}
	return false;
	*/
}
void AAGP_Weapon::NotifyOutOfAmmo ()
{
	/*
	if (_AmmoMonitor != None)
	{
		_AmmoMonitor.update();
	}
	if (Instigator.EventLab != None)
	{
		Instigator.EventLab.ActorNotify(Self,21,Instigator,"WeaponOutOfAmmo");
	}
	*/
}
void AAGP_Weapon::GetAmmoMonitor ()
{
	//Return _AmmoMonitor;
}
/*
void AAGP_Weapon::SetAmmoMonitor (ScriptObject sobj)
{
	_AmmoMonitor=sobj;
}
*/
void AAGP_Weapon::NotifyJammed ()
{
	/*
	if (_JammedMonitor != None)
	{
		_JammedMonitor.update();
	}
	if (Instigator.EventLab != None)
	{
		Instigator.EventLab.ActorNotify(Self,20,Instigator,"WeaponJammed");
	}
	*/
}

void AAGP_Weapon::GetJammedMonitor ()
{
	//Return _JammedMonitor;
}
/*
void AAGP_Weapon::SetJammedMonitor (ScriptObject sobj)
{
	//_JammedMonitor=sobj;
}
*/
void AAGP_Weapon::BringUp ()
{
	/*
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		ClientBringUp();
	}
	if (IsReplicationComplete())
	{
		GotoState('BusyRaisingWeapon');
	}
	else
	{
		bBusyRaiseWeaponPending=True;
	}
	*/
}
void AAGP_Weapon::ClientBringUp()
{
	/*
	if (IsReplicationComplete())
	{
		GotoState('BusyRaisingWeapon');
	}
	else
	{
		bBusyRaiseWeaponPending=True;
	}
	*/
}
bool AAGP_Weapon::PutDown()
{
	if(GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		ClientPutDown();
	}
	bChangeWeapon=true;
	//GotoState('BusyLoweringWeapon');
	return true;
}
void AAGP_Weapon::ClientPutDown ()
{
	bChangeWeapon=true;
	/*
	GotoState('BusyLoweringWeapon');
	*/
}
void AAGP_Weapon::DoChangeFireMode()
{
	switch(eROF)
	{
		case RateofFire::ROF_Single:		eROF = RateofFire::ROF_Burst;			break;
		case RateofFire::ROF_Burst:			eROF = RateofFire::ROF_Auto;			break;
		case RateofFire::ROF_Auto:			eROF = RateofFire::ROF_Single;			break;
		default:																	break;
	}
}
void AAGP_Weapon::DoChangeFireModeAux ()
{
	LastROF=eROF;
	eROF=AuxROF;
}
void AAGP_Weapon::DoChangeFireModeLast ()
{
	eROF=LastROF;
}
void AAGP_Weapon::DoFixJam ()
{
	/*
	if (bIsRuined)
	{
		Return;
	}
	if (Instigator != None && Instigator.Controller != None && Instigator.IsHumanControlled())
	{
		Instigator.Controller.StopFiring();
	}
	bIsJammed=False;
	*/
}
void AAGP_Weapon::DoSupported ()
{
	/*
	if (Instigator != None)
	{
		Instigator.LockMovement(bIsSupported);
		Instigator.LimitRotation(bIsSupported);
	}
	if (BaseWeaponAttachment(ThirdPersonActor) != None)
	{
		BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(Self);
	}
	*/
}
void AAGP_Weapon::GetSoundActor ()
{
//	return this;
}
void AAGP_Weapon::PlayWeaponSound (USoundBase* pSound, USoundBase* esound, float Volume, float Radius)
{
	if (Volume == 0)
	{
		Volume=0.5;
	}
	if (Radius == 0)
	{
		Radius=60;
	}
	/*
	if (Instigator == Level.GetClientPawn())
	{
		GetSoundActor().PlaySound(pSound,0,Volume,true,Radius,1,false,true);
	}
	else
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsMILES())
		{
			esound=pSound;
		}
		if (Instigator != None && Instigator.Controller != None && Instigator.Controller.IsA('AIController'))
		{
			esound=pSound;
		}
		GetSoundActor().PlayOwnedSound(pSound,0,Volume,false,Radius,1,true,false,esound,idTeamOwner);
	}
	*/
}
void AAGP_Weapon::ServerDryFire ()
{
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		DryFire();
	}
	*/
}
void AAGP_Weapon::DryFire ()
{
	/*
	if (GetNetMode() == ENetMode::NM_Client)
	{
		ServerDryFire();
	}
	PlayDryFire();
	*/
}
void AAGP_Weapon::PlayDryFire ()
{
	//PlayWeaponSound(DryFireSound,EnemyWeaponClass.Default.DryFireSound);
}
void AAGP_Weapon::AnimEnd (int Channel)
{
	//GotoState('Idle');
}
void AAGP_Weapon::PlayIdleAnim ()
{
	/*
	if (IsSupported())
	{
		if (IsZoomed() && ShouldUse3dSights())
		{
			if (_Scope != None && _Scope.bAux3dSights && HasAnim(AuxSupportedZoomIdleAnim))
			{
				RunAnimation(AuxSupportedZoomIdleAnim,1,0.05,True);
			}
			else
			{
				if (HasAnim(SupportedZoomIdleAnim))
				{
					RunAnimation(SupportedZoomIdleAnim,1,0.05,True);
				}
			}
		}
		else
		{
			RunAnimation('SupportedStill',1,0.05,True);
		}
	}
	else
	{
		if (IsZoomed() && ShouldUse3dSights())
		{
			if (_Scope != None && _Scope.bAux3dSights && HasAnim(AuxZoomIdleAnim))
			{
				RunAnimation(AuxZoomIdleAnim,1,0.05,True);
			}
			else
			{
				if (HasAnim(ZoomIdleAnim[ElevationIndex]))
				{
					RunAnimation(ZoomIdleAnim[ElevationIndex],1,0.05,True);
				}
			}
		}
		else
		{
			if (HasAnim('Still'))
			{
				RunAnimation('Still',1,0.05,True);
			}
			else
			{
				RunAnimation('Idle',1,0.05,True);
			}
		}
	}
	*/
}
void AAGP_Weapon::GetAnimActor ()
{
	//return this;
}
void AAGP_Weapon::RunAnimation (FName Sequence, float Rate, float TweenTime, bool bLoop)
{
	
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugWeaponAcc)
	{
		UE_LOG(LogTemp, Warning, TEXT("entered runanimation()"));
	}

	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		if (bLoop)
		{
			if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugWeaponAcc)
			{
				UE_LOG(LogTemp, Warning, TEXT("TweenTime = %d"), TweenTime);
			}
			//GetAnimActor().LoopAnim(Sequence,Rate,TweenTime);
		}
		else
		{
			//DebugLog(DEBUG_Inv,"Weapon animation '" $ Sequence $ "' for weapon " $ Self $ " lasts for " $ GetAnimActor().GetAnimDuration(Sequence,Rate));
			if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugWeaponAcc)
			{
				UE_LOG(LogTemp, Warning, TEXT("TweenTime = %d"),TweenTime);
			}
			//GetAnimActor().PlayAnim(Sequence,Rate,TweenTime);
		}
		NotifyWeaponModAnimations(Sequence,Rate,TweenTime,bLoop);
	}
	else
	{
		//AnimTimerDuration=GetAnimActor().GetAnimDuration(Sequence,Rate) + TweenTime;
	}
	NotifyWeaponAttachmentAnimations(Sequence,Rate,TweenTime,bLoop);
}
void AAGP_Weapon::NotifyWeaponAttachmentAnimations (FName Sequence, float Rate, float TweenTime, bool bLoop)
{
	/*
	local BaseWeaponAttachment BWA;
	BWA=BaseWeaponAttachment(ThirdPersonActor);
	if (BWA != None && BWA != GetAnimActor())
	{
		BWA.NotifyWeaponAnimation(Sequence,Rate,TweenTime,bLoop);
	}
	*/
}
void AAGP_Weapon::GetFireSound ()
{
	/*
	if (Region.Zone.bIndoorZone)
	{
		if (eROF == 4)
		{
			Return AuxSingleFire;
		}
		else
		{
			if (bSuppressorOn)
			{
				if (SuppressedSingleFire != None)
				{
					Return SuppressedSingleFire;
				}
			}
		}
		Return SingleFire;
	}
	else
	{
		if (eROF == 4)
		{
			Return AuxOutdoorSingleFire;
		}
		else
		{
			if (bSuppressorOn)
			{
				if (SuppressedOutdoorSingleFire != None)
				{
					Return SuppressedOutdoorSingleFire;
				}
			}
		}
		Return OutdoorSingleFire;
	}
	*/
}
void AAGP_Weapon::GetEnemyFireSound ()
{
	/*
	if (Region.Zone.bIndoorZone)
	{
		if (eROF == 4)
		{
			Return EnemyWeaponClass.Default.AuxSingleFire;
		}
		else
		{
			if (bSuppressorOn)
			{
				if (EnemyWeaponClass.Default.SuppressedSingleFire != None)
				{
					Return EnemyWeaponClass.Default.SuppressedSingleFire;
				}
			}
		}
		Return EnemyWeaponClass.Default.SingleFire;
	}
	else
	{
		if (eROF == 4)
		{
			Return EnemyWeaponClass.Default.AuxOutdoorSingleFire;
		}
		else
		{
			if (bSuppressorOn)
			{
				if (EnemyWeaponClass.Default.SuppressedOutdoorSingleFire != None)
				{
					Return EnemyWeaponClass.Default.SuppressedOutdoorSingleFire;
				}
			}
		}
		Return EnemyWeaponClass.Default.OutdoorSingleFire;
	}
	*/
}
void AAGP_Weapon::GetSpecialFireAnim (FName SpecialAnimName)
{
}
void AAGP_Weapon::PlayFiring ()
{
	/*
	local int Num;
	local float Rate;
	local name special_anim;
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
	if (GetSpecialFireAnim(special_anim))
	{
		RunAnimation(special_anim,Rate,FiringTweenTime);
	}
	else
	{
		if (IsSupported())
		{
			if (DrawType == 2 && ShouldUse3dSights() && IsZoomed())
			{
				if (_Scope.bAux3dSights)
				{
					if (DrawType == 2 && HasAnim(AuxSupportedZoomFireAnims[1]))
					{
						if (HasAnim(AuxSupportedZoomFireAnims[2]))
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
					if (HasAnim(AuxSupportedZoomFireAnims[Num]))
					{
						RunAnimation(AuxSupportedZoomFireAnims[Num],0.5 + 0.5 * FireAdjust,FiringTweenTime);
					}
					else
					{
						RunAnimation(SupportedFireAnims[Num],0.5 + 0.5 * FireAdjust,FiringTweenTime);
					}
				}
				else
				{
					if (DrawType == 2 && HasAnim(SupportedZoomFireAnims[1]))
					{
						if (HasAnim(SupportedZoomFireAnims[2]))
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
					if (HasAnim(SupportedZoomFireAnims[Num]))
					{
						RunAnimation(SupportedZoomFireAnims[Num],0.5 + 0.5 * FireAdjust,FiringTweenTime);
					}
					else
					{
						RunAnimation(SupportedFireAnims[Num],0.5 + 0.5 * FireAdjust,FiringTweenTime);
					}
				}
			}
			else
			{
				if (DrawType == 2 && HasAnim('SupportedFireB'))
				{
					if (HasAnim('SupportedFireC'))
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
				RunAnimation(SupportedFireAnims[Num],0.5 + 0.5 * FireAdjust,FiringTweenTime);
			}
		}
		else
		{
			if (DrawType == 2 && ShouldUse3dSights() && IsZoomed())
			{
				if (_Scope.bAux3dSights)
				{
					if (DrawType == 2 && HasAnim(AuxZoomFireAnims[1]))
					{
						if (HasAnim(AuxZoomFireAnims[2]))
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
					if (HasAnim(AuxZoomFireAnims[Num]))
					{
						RunAnimation(AuxZoomFireAnims[Num],0.5 + 0.5 * FireAdjust,FiringTweenTime);
					}
					else
					{
						RunAnimation(FireAnims[Num],0.5 + 0.5 * FireAdjust,FiringTweenTime);
					}
				}
				else
				{
					if (DrawType == 2 && HasAnim(ZoomFireAnims[1]))
					{
						if (HasAnim(ZoomFireAnims[2]))
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
					if (HasAnim(ZoomFireAnims[Num]))
					{
						RunAnimation(ZoomFireAnims[Num],0.5 + 0.5 * FireAdjust,FiringTweenTime);
					}
					else
					{
						RunAnimation(FireAnims[Num],0.5 + 0.5 * FireAdjust,FiringTweenTime);
					}
				}
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
				RunAnimation(FireAnims[Num],0.5 + 0.5 * FireAdjust,FiringTweenTime);
			}
		}
	}
	HandleRecoil();
	*/
}
void AAGP_Weapon::HandleRecoil ()
{
	FRotator Recoil;
	float RecoilAlpha=0;
	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		if (bWpnRecoil)
		{
			/*
			if (Instigator != nullptr)
			{
				ConsecutiveShots ++;
				if (bUseAutoRecoil && eROF == 3 || eROF == 2 && ConsecutiveShots >= ShotsToStartRecoilBlend)
				{
					RecoilAlpha=FClamp(ConsecutiveShots - ShotsToStartRecoilBlend - 1 / ShotsForMaxRecoil - ShotsToStartRecoilBlend - 1,0,1);
					Recoil=1 - RecoilAlpha * CalcRotation(_RecoilDirInfo) + RecoilAlpha * CalcRotation(_AutoRecoilDirInfo);
				}
				else
				{
					Recoil=CalcRotation(_RecoilDirInfo);
				}
				if (AGP_Pawn(Instigator).bNewAccuracy)
				{
					Recoil=Recoil * FMax(1 - Instigator.CE_MeterValue,BaseRecoilModifier) * GlobalRecoilScaler;
				}
				else
				{
					Recoil=Recoil * FMax(1 - Instigator.CE_MeterValue,BaseRecoilModifier);
				}
				Instigator.SetViewRotation(Recoil + Instigator.GetViewRotation());
			}
			*/
		}
	}
}
void AAGP_Weapon::NPC_PlayFiring ()
{
	/*
	local int Num;
	local float Rate;
	local name special_anim;
	SetupMuzzleFlash();
	if (IsSuppressed())
	{
		PlayWeaponSound(GetFireSound(),GetEnemyFireSound(),0.9,125);
	}
	else
	{
		PlayWeaponSound(GetFireSound(),GetEnemyFireSound(),0.9,400);
	}
	Rate=0.5 + 0.5 * FireAdjust;
	if (GetSpecialFireAnim(special_anim))
	{
		RunAnimation(special_anim,Rate,0.05);
	}
	else
	{
		if (IsSupported())
		{
			if (HasAnim('SupportedFireB'))
			{
				if (HasAnim('SupportedFireC'))
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
			RunAnimation(SupportedFireAnims[Num],0.5 + 0.5 * FireAdjust,0.05);
		}
		else
		{
			if (HasAnim('FireB'))
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
	}
	HandleRecoil();
	*/
}
void AAGP_Weapon::PlayReloading ()
{
	/*
	local float fpReloadRate;
	fpReloadRate=1.4;
	if (BaseWeaponAttachment(ThirdPersonActor) != None)
	{
		BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(Self);
	}
	if (eROF == AuxROF)
	{
		if (GetAuxAmmoType() != None && GetAuxAmmoType().IsA('Ammo_30mm_1_Gren') || GetAuxAmmoType().IsA('Ammo_40mm_1_Gren') || GetAuxAmmoType().IsA('Ammo_40mm_1_Gren_Mod'))
		{
			fpReloadRate=1;
		}
		if (HasAnim('ReloadEmpty'))
		{
			RunAnimation('ReloadEmpty',fpReloadRate,0.05);
		}
		else
		{
			RunAnimation('Reload',fpReloadRate,0.05);
		}
		if (ShouldDoDelayedEject())
		{
			DiscardShell();
		}
		if (! bUseAnimNotifySounds)
		{
			PlayWeaponSound(AltReloadSound,EnemyWeaponClass.Default.AltReloadSound);
		}
	}
	else
	{
		if (IsSupported())
		{
			if (GetCurrentAmmoType() != None && GetCurrentAmmoType().HasAmmo())
			{
				RunAnimation(ProneReloadFullAnim,fpReloadRate);
				if (! bUseAnimNotifySounds)
				{
					PlayWeaponSound(ProneReloadFullSound,EnemyWeaponClass.Default.ProneReloadFullSound);
				}
			}
			else
			{
				RunAnimation(ProneReloadEmptyAnim,fpReloadRate);
				if (! bUseAnimNotifySounds)
				{
					PlayWeaponSound(ProneReloadSound,EnemyWeaponClass.Default.ReloadSound);
				}
			}
		}
		else
		{
			if (GetCurrentAmmoType() != None && GetCurrentAmmoType().HasAmmo())
			{
				RunAnimation(ReloadFullAnim,fpReloadRate);
				if (! bUseAnimNotifySounds)
				{
					if (ReloadFullSound != None)
					{
						PlayWeaponSound(ReloadFullSound,EnemyWeaponClass.Default.ReloadFullSound);
					}
					else
					{
						PlayWeaponSound(ReloadSound,EnemyWeaponClass.Default.ReloadSound);
					}
				}
			}
			else
			{
				RunAnimation(ReloadEmptyAnim,fpReloadRate);
				if (! bUseAnimNotifySounds)
				{
					PlayWeaponSound(ReloadSound,EnemyWeaponClass.Default.ReloadSound);
				}
			}
		}
	}
	*/
}
void AAGP_Weapon::PlayChangeFireMode ()
{
	/*
	Switch(NewAuxMode)
	{
		case 0:
		if (IsSupported())
		{
			if (ShouldUse3dSights() && IsZoomed())
			{
				if (_Scope != None && _Scope.bAux3dSights)
				{
					RunAnimation(AuxSupportedZoomFireAnims[0],0.5);
					break;
				}
				RunAnimation(SupportedZoomFireAnims[0],0.5);
			}
		}
		else
		{
			if (eROF == 1)
			{
				RunAnimation('SupportedChangeFireMode',1);
			}
			else
			{
				RunAnimation('SupportedChangeFireModeBack',1);
			}
		}
	}
	else
	{
		if (ShouldUse3dSights() && IsZoomed())
		{
			if (_Scope != None && _Scope.bAux3dSights)
			{
				RunAnimation(AuxZoomFireAnims[0],0.5);
			}
			else
			{
				RunAnimation(ZoomFireAnims[0],0.5);
			}
		}
		else
		{
			if (eROF == 1)
			{
				RunAnimation('ChangeFireMode',1);
			}
			else
			{
				RunAnimation('ChangeFireModeBack',1);
			}
		}
	}
	GOTO JL017A;
	case 1:
	SelectAuxFireMode();
	RunAnimation('Swap',1);
	GOTO JL017A;
	case 2:
	SelectNormalMode();
	RunAnimation('Swapback',1);
	GOTO JL017A;
	default:
JL017A:
	PlayWeaponSound(ChangeFireSound,EnemyWeaponClass.Default.ChangeFireSound);
	*/
}
void AAGP_Weapon::PlayFixJam ()
{
	/*
	local float fpFixJamRate;
	fpFixJamRate=1.4;
	if (BaseWeaponAttachment(ThirdPersonActor) != None)
	{
		BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(Self);
	}
	if (IsSupported())
	{
		RunAnimation('SupportedFixJam',fpFixJamRate,0.05);
		PlayWeaponSound(ProneFixJamSound,EnemyWeaponClass.Default.ProneFixJamSound);
	}
	else
	{
		RunAnimation('FixJam',fpFixJamRate,0.05);
		PlayWeaponSound(FixJamSound,EnemyWeaponClass.Default.FixJamSound);
	}
	*/
}
void AAGP_Weapon::PlaySupporting ()
{
	/*
	local float fpSupportedRate;
	fpSupportedRate=1.4;
	DoSupported();
	if (IsSupported())
	{
		RunAnimation('Supported',fpSupportedRate,0.05);
		PlayWeaponSound(SupportingSound,EnemyWeaponClass.Default.SupportingSound);
	}
	else
	{
		RunAnimation('Unsupported',fpSupportedRate,0.05);
		PlayWeaponSound(UnSupportingSound,EnemyWeaponClass.Default.UnSupportingSound);
	}
	*/
}
void AAGP_Weapon::PlaySelect ()
{
	/*
	local int initradius;
	local float fpDropRaiseRate;
	fpDropRaiseRate=1.4;
	if (BaseWeaponAttachment(ThirdPersonActor) != None)
	{
		BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(Self);
	}
	if (IsZoomed() && ShouldUse3dSights())
	{
		PlayIdleAnim();
	}
	else
	{
		if (! IsAnimating() || ! AnimIsInGroup(0,'Select') || ! AnimIsInGroup(0,'SelectNew'))
		{
			if (_bActive)
			{
				if (HasAnim('Raise'))
				{
					RunAnimation('Raise',fpDropRaiseRate);
				}
				else
				{
					RunAnimation('Select',fpDropRaiseRate);
				}
			}
			else
			{
				if (! _bCharged && HasAnim('SelectNew'))
				{
					if (Instigator != None && Instigator.bIsSprinting)
					{
						Instigator.StopSprint();
					}
					_bCharged=True;
					RunAnimation('SelectNew',1);
					if (GetNetMode() == ENetMode::NM_Client)
					{
						initradius=1000000;
					}
					else
					{
						initradius=60;
					}
					PlayWeaponSound(SelectChargeSound,EnemyWeaponClass.Default.SelectChargeSound,,initradius);
				}
				else
				{
					RunAnimation('Select',fpDropRaiseRate);
					PlayWeaponSound(SelectSound,EnemyWeaponClass.Default.SelectSound);
				}
			}
		}
	}
	*/
}
void AAGP_Weapon::TweenDown ()
{
	/*
	local name SeqName;
	local float AnimFrame;
	local float AnimRate;
	local float fpDropAnimRate;
	fpDropAnimRate=1.3;
	GetAnimParams(0,SeqName,AnimFrame,AnimRate);
	if (IsAnimating() && AnimIsInGroup(0,'Select') || AnimIsInGroup(0,'SelectNew'))
	{
		TweenAnim(SeqName,AnimFrame * 0.4);
	}
	else
	{
		if (_bActive)
		{
			if (HasAnim('Drop'))
			{
				RunAnimation('Drop',fpDropAnimRate);
			}
			else
			{
				RunAnimation('Down',fpDropAnimRate);
			}
		}
		else
		{
			PlayWeaponSound(SelectSound,EnemyWeaponClass.Default.SelectSound);
			if (SeqName == 'Drop' || SeqName == 'DropStill')
			{
				RunAnimation('LowDown',fpDropAnimRate);
			}
			else
			{
				RunAnimation('Down',fpDropAnimRate);
			}
		}
	}
	*/
}
void AAGP_Weapon::PlayHighCrawlIn ()
{
	/*
	if (_bTossNotThrow)
	{
		RunAnimation('LowHighCrawlIn',1);
	}
	else
	{
		RunAnimation('HighCrawlIn',1);
	}
	*/
}
void AAGP_Weapon::PlayCrawl ()
{
	/*
	if (Instigator != None && Instigator.bIsWalking)
	{
		GotoState('OutCrawling');
	}
	else
	{
		RunAnimation('HighCrawl',1,,True);
	}
	*/
}
void AAGP_Weapon::PlayHighCrawlOut ()
{
	/*
	if (_bTossNotThrow)
	{
		RunAnimation('LowHighCrawlOut',1);
	}
	else
	{
		RunAnimation('HighCrawlOut',1);
	}
	*/
}
void AAGP_Weapon::SetupAuxWeaponMesh (USkeletalMesh* new_mesh, USkeletalMesh* new_aux_mesh)
{
	/*
	NrmFireMesh=new_mesh;
	AuxFireMesh=new_aux_mesh;
	if (NrmFireMesh != None)
	{
		LinkMesh(new_mesh);
		RunAnimation('SelectNew',1);
	}
	*/
}
void AAGP_Weapon::SetupAuxAmmoRound (ABaseAmmoRound* new_aux_round, int32 new_num_aux)
{
	/*
	AuxAmmoRoundClass=new_aux_round;
	NumAuxAmmoRound=new_num_aux;
	*/
}
void AAGP_Weapon::SetupAuxAmmo (AAmmunition* new_aux_ammo, int32 new_aux_pcount)
{
	/*
	AuxAmmoName=new_aux_ammo;
	AuxROF=4;
	AuxPickupAmmoCount=new_aux_pcount;
	*/
}
void AAGP_Weapon::SetupAuxMuzzleFlash (AEmitter* new_muzzle, FBoneOffset new_offset)
{
	/*
	_FPAuxMuzzleFlashClass=new_muzzle;
	_FPAuxMuzzleFlashOffset=new_offset;
	*/
}
void AAGP_Weapon::SetupAuxSounds (USoundBase* new_fire, USoundBase* new_outdoor_fire, USoundBase* new_reload)
{
	/*
	AuxSingleFire=new_fire;
	AuxOutdoorSingleFire=new_outdoor_fire;
	AltReloadSound=new_reload;
	*/
}
void AAGP_Weapon::SelectAuxFireMode ()
{
	/*
	LinkMesh(AuxFireMesh);
	_FPMuzzleFlashEmitter=AuxMuzzleFlashEmitter;
	if (_FPMuzzleFlashEmitter != None)
	{
		AttachToBoneOffset(_FPMuzzleFlashEmitter,_FPAuxMuzzleFlashOffset);
	}
	*/
}
void AAGP_Weapon::SelectNormalMode ()
{
	/*
	LinkMesh(NrmFireMesh);
	DoSuppressor(bSuppressorOn);
	*/
}
void AAGP_Weapon::FailedSupported ()
{
	/*
	if (AuxROF != 0)
	{
		if (! IsBusy() || IsTempBusy())
		{
			if (eROF == AuxROF)
			{
				ChangeAuxMode(2);
			}
			else
			{
				ChangeAuxMode(1);
			}
		}
	}
	*/
}
void AAGP_Weapon::ChangeAuxMode (ENewAuxMode new_mode)
{
	/*
	NewAuxMode=new_mode;
	ServerChangeAuxMode(NewAuxMode);
	if (GetNetMode() == ENetMode::NM_Client)
	{
		GotoState('BusyChangingFireMode');
	}
	*/
}
void AAGP_Weapon::ServerChangeAuxMode (ENewAuxMode new_mode)
{
	/*
	NewAuxMode=new_mode;
	GotoState('BusyChangingFireMode');
	*/
}
void AAGP_Weapon::UpdateSpecialAttachment (bool bRenderAttachment)
{
}
void AAGP_Weapon::SetupMuzzleFlash ()
{
	/*
	local int i;
	local int Count;
	local HumanController HC;
	local bool bFirstPerson;
	if (Owner != None && Pawn(Owner) != None)
	{
		HC=HumanController(Pawn(Owner).Controller);
	}
	if (HC != None)
	{
		bFirstPerson=! HC.bBehindView && Pawn(Owner) != None && HC.ViewTarget == Pawn(Owner);
	}
	else
	{
		bFirstPerson=False;
	}
	IncrementFlashCount();
	if (! IsZoomed() || ShouldUse3dSights() && bFirstPerson)
	{
		if (_FPMuzzleFlashClass == None)
		{
			bMuzzleFlash=True;
			bSetFlashTime=False;
		}
		else
		{
			if (_FPMuzzleFlashEmitter != None)
			{
				Count=_FPMuzzleFlashEmitter.EmitterCount();
				for (i=0; i<Count; i++)
				{
					_FPMuzzleFlashEmitter.Emitters[i].SpawnParticle(_FPMuzzleFlashEmitter.Emitters[i].iFlashSpawnCount);
				}
				_FPMuzzleFlashEmitter.DynamicFlash();
			}
		}
	}
	else
	{
		if (IsZoomed() && ! ShouldUse3dSights() && bFirstPerson)
		{
			if (_FPMuzzleFlashClass == None)
			{
				bMuzzleFlash=True;
				bSetFlashTime=False;
			}
			else
			{
				if (_FPMuzzleFlashEmitter != None)
				{
					_FPMuzzleFlashEmitter.DynamicFlash();
				}
			}
		}
	}
	*/
}
void AAGP_Weapon::IncrementFlashCount ()
{
	/*
	local BaseWeaponAttachment BA;
	FlashCount=FlashCount + 1 % 254;
	BA=BaseWeaponAttachment(ThirdPersonActor);
	if (BA != None)
	{
		Switch(eROF)
		{
			case 1:
			BA.FiringMode='ROF_Single';
			break;
			case 2:
			BA.FiringMode='ROF_Burst';
			break;
			case 3:
			BA.FiringMode='ROF_Auto';
			break;
			case 4:
			BA.FiringMode='ROF_SingleGren';
			break;
			default:
		}
		BA.FlashCount=FlashCount;
		BA.ThirdPersonEffects();
	}
	else
	{
		DebugLog(DEBUG_Warn,"AGP_Weapon::IncrementFlashCount()	Could not find BaseWeaponAttachment " $ ThirdPersonActor);
	}
	*/
}
void AAGP_Weapon::NotifyAddAmmo (AAmmunition* NewAmmo)
{
	if ((NewAmmo != NULL) && (NewAmmo->GetClass() == AuxAmmoName) && (Cast<AAmmunition>(NewAmmo)->AmmoAmount > 0))
	//if ((newAmmo.class == AuxAmmoName) && (newAmmo.AmmoAmount > 0))
	{
		AuxAmmoMagCount ++;
	}
	Super::NotifyAddAmmo(NewAmmo);
}
void AAGP_Weapon::NotifyDeleteAmmo (AAmmunition* OldAmmo)
{
	
	if ((OldAmmo != NULL) && (OldAmmo->GetClass() == AuxAmmoName))
	{
		AuxAmmoMagCount --;
	}
	Super::NotifyDeleteAmmo(OldAmmo);
}
void AAGP_Weapon::WeaponDisabled ()
{
	/*
	if (bIsRuined || bIsJammed || GetCurrentAmmoType() != None && GetCurrentAmmoType().AmmoAmount <= 0)
	{
		Return True;
	}
	Return False;
	*/
}
int32 AAGP_Weapon::GetMinimumRange()
{
	return 0;
}
int32 AAGP_Weapon::GetOptimalRange ()
{
	return 500;
}
int32 AAGP_Weapon::GetMaximumRange ()
{
	return 4800;
}
TSubclassOf<AAmmunition> AAGP_Weapon::GetCurrentAmmoName ()
{
	if (eROF == AuxROF)
	{
		return AuxAmmoName;
	}
	else
	{
		return AmmoName;
	}
}
AAmmunition* AAGP_Weapon::GetCurrentAmmoType ()
{
	
	if (eROF == AuxROF)
	{
		return AuxAmmoType;
	}
	else
	{
		return AmmoType;
	}
	
}
void AAGP_Weapon::SetCurrentAmmoType (AAmmunition* newAmmoType)
{
	/*
	if (eROF == AuxROF)
	{
		AuxAmmoType=newAmmoType;
	}
	else
	{
		AmmoType=newAmmoType;
	}
	*/
}
void AAGP_Weapon::SetCurrentAmmoName (AAmmunition* newAmmoName)
{
	/*
	if (eROF == AuxROF)
	{
		AuxAmmoName=newAmmoName;
	}
	else
	{
		AmmoName=newAmmoName;
	}
	*/
}
TSubclassOf<AAmmunition> AAGP_Weapon::GetAuxAmmoName ()
{
	return AuxAmmoName;
}
AAmmunition* AAGP_Weapon::GetAuxAmmoType ()
{
	return AuxAmmoType;
}


/* =================================================================================== *
 * AGP function GetClipCount()
 *	Get the round count at the specified index for the current ammo type.
 *	If bAuxAmmo is true, get the round count for AuxAmmo
 *
 * input:	clip		- The clip index
 *			bAuxAmmo	- If true, get AuxAmmoClip
 *
 * output:	byte		- The round count
 * last modified by: cmb
 * =================================================================================== */
int32 AAGP_Weapon::GetClipCount (uint8 clip, bool bAuxAmmo)
{
	if (GetCurrentAmmoType() == AuxAmmoType || bAuxAmmo)
	{
		return _AuxAmmoClips[clip];
	}
	else
	{
		return _AmmoClips[clip];
	}
}

/* =================================================================================== *
 * AGP function SetClipCount()
 *	Set the round count at the specified clip index to the specified amount.
 *	By default, set it for the current ammo type, unless bAuxAmmo is used, in which
 *	case always set the auxAmmo.
 *
 * input:	clip		- The clip index
 *			count		- The number of rounds to set
 *			bAuxAmmo	- If true, always set AuxAmmoClip
 *
 * effects:	Sets a member of one of the clip arrays.
 * notes:
 * last modified by: cmb
 * =================================================================================== */
void AAGP_Weapon::SetClipCount (uint8 clip, int32 Count, bool bAuxAmmo)
{
	if (GetCurrentAmmoType() == AuxAmmoType || bAuxAmmo)
	{
		_AuxAmmoClips[clip]=Count;
	}
	else
	{
		_AmmoClips[clip]=Count;
	}
}

/* =================================================================================== *
 * AGP function GetBestClip()
 *	Return the index of the clip of the current ammo type with the most rounds in it.
 *
 * input:	byte	- The index
 * last modified by: cmb
 * =================================================================================== */
void AAGP_Weapon::GetBestClip ()
{
	/*
	local int i;
	local int best_index;
	local int best_count;
	local int this_count;
	best_index=0;
	best_count=GetClipCount(0);
	for (i=1; i<16; i++)
	{
		this_count=GetClipCount(i);
		if (this_count > best_count)
		{
			best_index=i;
			best_count=this_count;
		}
	}
	Return best_index;
	*/
}
bool AAGP_Weapon::CheckForNoReload ()
{
	/*
	local int i;
	if (SingleShotWeapon())
	{
		Return True;
	}
	if (eROF == 4 && ! OutOfAmmo())
	{
		Return True;
	}
	if (GetCurrentAmmoType() != None && GetCurrentAmmoType().ProjectileClass != None && GetCurrentAmmoType().AmmoAmount == GetCurrentAmmoType().MaxAmmo)
	{
		Return True;
	}
	for (i=0; i<16; i++)
	{
		if (GetClipCount(i) > 0)
		{
			Return False;
		}
	}
	Return True;
	*/
	return true;  //FAKE   /ELiZ
}
bool AAGP_Weapon::OutOfAmmo()
{
	if (GetCurrentAmmoType() != NULL && GetCurrentAmmoType()->HasAmmo())
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool AAGP_Weapon::SingleShotWeapon()
{
	return false;
}
void AAGP_Weapon::ReloadClip(uint8 newclip)
{
	/*
	local int Swap;
	local Ammunition my_ammo;
	my_ammo=GetCurrentAmmoType();
	if (my_ammo != None)
	{
		Swap=my_ammo.AmmoAmount;
		my_ammo.AmmoAmount=GetClipCount(newclip);
		if (Swap > 0 && bAllowsPlusOneLoading)
		{
			Swap -= 1;
			my_ammo.AmmoAmount += 1;
		}
		SetClipCount(newclip,Swap);
		RecountAmmo();
	}
	*/
}
void AAGP_Weapon::AddClip (AAmmunition* AmmoClass)
{
/*
	local int i;
	DebugLog(DEBUG_Inv,"AGP_Weapon::AddClip()	" $ AmmoClass @ AmmoName @ AuxAmmoName);
	if (AmmoClass == None)
	{
		Return False;
	}
	else
	{
		if (AmmoClass == AmmoName)
		{
			if (AmmoMagCount < MaxClips)
			{
				for (i=0; i<16; i++)
				{
					if (GetClipCount(i) <= 0)
					{
						SetClipCount(i,AmmoClass.Default.AmmoAmount);
						AmmoMagCount ++;
						Return True;
					}
				}
			}
			else
			{
				Return False;
			}
		}
		else
		{
			if (AmmoClass == AuxAmmoName)
			{
				if (AuxAmmoMagCount < MaxClips)
				{
					for (i=0; i<16; i++)
					{
						if (GetClipCount(i,True) <= 0)
						{
							SetClipCount(i,AmmoClass.Default.AmmoAmount,True);
							AuxAmmoMagCount ++;
							Return True;
						}
					}
				}
				else
				{
					Return False;
				}
			}
			else
			{
				Return False;
			}
		}
	}
	*/
}

bool AAGP_Weapon::ValidAmmo(TSubclassOf<AAmmunition> AmmoClass)
{
	
	if (AmmoClass == NULL)
	{
		return false;
	}
	else
	{
		if (AmmoClass == AmmoName && AmmoMagCount < MaxClips)
		{
			return true;
		}
		else
		{
			if (AmmoClass == AuxAmmoName && AmmoMagCount < MaxClips)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
void AAGP_Weapon::SpawnAmmoFor (AAGP_Weapon* OldW, AAmmunition* oldA)
{
/*
	local Ammunition newA;
	if (oldA.Class == OldW.AmmoName)
	{
		newA=Spawn(AmmoName,Self);
	}
	else
	{
		if (oldA.Class == OldW.AuxAmmoName && AuxAmmoName != None)
		{
			newA=Spawn(AuxAmmoName,Self);
		}
		else
		{
			DebugLog(DEBUG_Warn,"AGP_Weapon::SpawnWeaponFor()	Unable to spawn for " $ Self @ OldW @ oldA);
			Return None;
		}
	}
	newA.AmmoAmount=Min(oldA.AmmoAmount,newA.MaxAmmo);
	Return newA;
*/
}
bool AAGP_Weapon::IsLegalROF(RateofFire testROF)
{
	RateofFire storeROF;
	bool bIsLegal = false;
	bool bKeepChecking;
	if (testROF == AuxROF)
	{
		return true;
	}
	storeROF=eROF;
	bKeepChecking=true;
	if (bKeepChecking)
	{
		DoChangeFireMode();
		if (eROF == storeROF)
		{
			bKeepChecking=false;
		}
		if (eROF == testROF)
		{
			bIsLegal=true;
		}
	}
	eROF=storeROF;
	return bIsLegal;
}
void AAGP_Weapon::CopyROF(AAGP_Weapon* W)
{
	RateofFire newROF;
	if (W == NULL)
	{
		return;
	}
	newROF=W->eROF;
	if (IsLegalROF(newROF))
	{
		eROF=newROF;
	}
	else
	{
		switch(newROF)
		{
		case RateofFire::ROF_Burst:
			newROF= RateofFire::ROF_Auto;
			break;
		case RateofFire::ROF_Auto:
			newROF= RateofFire::ROF_Burst;
			break;
		default:
			break;
		}
		if (IsLegalROF(newROF))
		{
			eROF=newROF;
		}
		else
		{
			//eROF=Default->eROF;
			eROF= Cast<AAGP_Weapon>(this)->eROF;   //First try to get a Default Value
		}
	}
}
void AAGP_Weapon::InitFor(AInventory* Inv)
{
/*
	local int i;
	local AGP_Weapon W;
	local bool bDoAux;
	W=AGP_Weapon(Inv);
	if (W == None)
	{
		Return;
	}
	bGuerrillaWeapon=W.bGuerrillaWeapon;
	CopyROF(W);
	CopyWeaponMods(W);
	if (AmmoType != None)
	{
		AmmoType.Destroy();
	}
	if (W != None && W.AmmoType != None)
	{
		AmmoType=SpawnAmmoFor(W,W.AmmoType);
	}
	if (AuxAmmoName != None)
	{
		if (AuxAmmoType != None)
		{
			AuxAmmoType.Destroy();
		}
		if (W.AuxAmmoType != None)
		{
			AuxAmmoType=SpawnAmmoFor(W,W.AuxAmmoType);
			bDoAux=True;
		}
	}
	for (i=0; i<16; i++)
	{
		_AmmoClips[i]=GetClipCountAllowed(W._AmmoClips[i],AmmoName);
		if (bDoAux)
		{
			_AuxAmmoClips[i]=GetClipCountAllowed(W._AuxAmmoClips[i],AuxAmmoName);
		}
	}
*/
}
void AAGP_Weapon::CopyWeaponMods (AAGP_Weapon* W)
{
	/*
		local BaseWeaponMod WM;
		local int i;
		local bool bEnemyMods;
		if (W == None)
		{
			Return;
		}
		bEnemyMods=W.EnemyWeaponClass == Default.Class && ! bGuerrillaWeapon;
		for (i=0; i<6; i++)
		{
			WM_Default[i]="NoMod";
		}
		WM=W.WeaponModList;
		if (WM != None)
		{
			if (bEnemyMods)
			{
				WM_Default[WM.ModSlot]=WM.EnemyModClass;
			}
			else
			{
				WM_Default[WM.ModSlot]=WM.Class;
			}
			WM=WM.NextWeaponMod;
		}
		bSuppressorOn=W.IsSuppressed();
		if (Default.bSuppressorOn)
		{
			bSuppressorOn=True;
		}
		bLoadModsFromPickup=True;
		LoadWeaponMods();
		*/
}
int32 AAGP_Weapon::GetClipCountAllowed (int32 new_clip, AAmmunition* test_ammo)
{
	//return Min(new_clip,test_ammo->Default->MaxAmmo);
	return 0;   //Fake /ELiZ
}
void AAGP_Weapon::FixRuinedJam ()
{
	bIsJammed=false;
	bIsRuined=false;
}
void AAGP_Weapon::NPC_SetEnemy (APawn* Enemy)
{
	dEnemy=Enemy;
}
APawn* AAGP_Weapon::NPC_GetEnemy()
{
	return dEnemy;
}
void AAGP_Weapon::NPC_SetValue (float Value)
{
	dValue=Value;
}
void AAGP_Weapon::MatchEnding ()
{
	Destroy();
}



