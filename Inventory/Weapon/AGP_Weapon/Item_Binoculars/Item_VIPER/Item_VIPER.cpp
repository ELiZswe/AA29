// All the original content belonged to the US Army


#include "Item_VIPER.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/Attch_VIPER/Attch_VIPER.h"
#include "AA29/BaseScope/Scope_VIPER.h"

AItem_VIPER::AItem_VIPER()
{
		//SupportClass = Class'AGP_Gameplay.F18AirStrike'
	TraceRange          = 18000;
	PaintDuration       = 1.2;
	TAGFireForce        = "TAGFireA";
	TAGMarkForce        = "TAGFireB";
	TAGAquiredForce     = "TAGAquire";
	InvBinocularsIndex  = 5;
	_cScopeClass        = AScope_VIPER::StaticClass();
	fWeight             = 0.85;
	AttachmentClass     = { AAttch_VIPER::StaticClass() };
	IconMaterial        = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_binocs_VIPIR.hud_binocs_VIPIR"), NULL, LOAD_None, NULL);
	ItemName            = "Vector IV-Binocular Laser Range Finder";
}

/*
State Paint
{
	Function Rotator AdjustAim(bool bBreatheBonus)
	{
		FRotator Result = FRotator(0,0,0);
		return Result;
	}
	Function BeginState()
	{
		if (Role == 4)
		{
			bInitialMark=true;
			bValidMark=false;
			MarkTime=Level.TimeSeconds;
			SetTimer(0.25,true);
		}
	}
	Function Timer()
	{
		bDoHit=true;
	}
	Function Tick(float dt)
	{
		if (Instigator.PressingFire() && (! Instigator.bIsDead))
		{
			ModeTick(dt);
		}
		else
		{
			StopFiring();
		}
	}
	Function ModeTick(float dt)
	{
		FVector StartTrace = FVector(0,0,0);
		FVector EndTrace = FVector(0,0,0);
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		FVector HitLocation = FVector(0,0,0);
		FVector HitNormal = FVector(0,0,0);
		local Actor Other;
		FRotator Aim = FRotator(0,0,0);
		bool bEngageTarget = false;
		bIsFiring=Instigator.PressingFire();
		if (! bIsFiring)
		{
			StopFiring();
		}
		GetViewAxes(X,Y,Z);
		StartTrace=((Instigator.Location + Instigator.EyePosition()) + (X * Instigator.CollisionRadius));
		Aim=Instigator.AdjustAim(AmmoType,StartTrace,int(aimerror));
		X= Vector(Aim);
		EndTrace=(StartTrace + (TraceRange * X));
		Other=Trace(HitLocation,HitNormal,EndTrace,StartTrace,true);
		if ((Other != None) && (Other != Instigator))
		{
			if (bDoHit)
			{
				bValidMark=false;
				if (Other.bWorldGeometry)
				{
					if (VSize((HitLocation - MarkLocation)) < 50)
					{
						Instigator.MakeNoise(3);
						if ((Level.TimeSeconds - MarkTime) > 0.3)
						{
							bEngageTarget=((Level.TimeSeconds - MarkTime) > PaintDuration);
							if (Support == None)
							{
								Support=CheckMark(HitLocation,bEngageTarget);
							}
							if ((Support != None) && Support.CheckMark(Instigator,HitLocation,bEngageTarget))
							{
								if (Support.IsFiring())
								{
									StopFiring();
								}
								else
								{
									bValidMark=true;
									if (! bMarkStarted)
									{
										bMarkStarted=true;
									}
								}
							}
							else
							{
								MarkTime=Level.TimeSeconds;
								bValidMark=false;
								bMarkStarted=false;
							}
						}
					}
					else
					{
						bAlreadyMarked=true;
						MarkTime=Level.TimeSeconds;
						MarkLocation=HitLocation;
						bValidMark=false;
						bMarkStarted=false;
					}
				}
				else
				{
					MarkTime=Level.TimeSeconds;
					bValidMark=false;
					bMarkStarted=false;
				}
				bDoHit=false;
			}
			EndEffect=HitLocation;
		}
		else
		{
			EndEffect=EndTrace;
		}
	}
	Function StopFiring()
	{
		bMarkStarted=false;
		GotoState('None');
	}
	Function EndState()
	{
		bAlreadyMarked=false;
		SetTimer(0,false);
	}
}
*/
