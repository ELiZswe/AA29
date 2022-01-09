// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/Item_Binoculars/Item_VIPER/Item_VIPER.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/Attch_VIPER/Attch_VIPER.h"
#include "AA29/Object/Actor/BaseScope/Scope_VIPER/Scope_VIPER.h"
#include "AA29/Object/Actor/CallForSupport/CallForSupport.h"

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
	IconMaterial		= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_binocs_VIPIR_Mat.hud_binocs_VIPIR_Mat'"), NULL, LOAD_None, NULL);
	ItemName            = "Vector IV-Binocular Laser Range Finder";
}

/*
simulated State Targeting extends Idle
{
	simulated Function Tick(float DeltaTime)
	{
		FVector StartTrace = FVector(0,0,0);
		FVector EndTrace = FVector(0,0,0);
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		FVector HitLocation = FVector(0,0,0);
		FVector HitNormal = FVector(0,0,0);
		AActor* Other = nullptr;
		bool bEngageTarget = false;
		Super::Tick(DeltaTime);
		bIsFiring=Instigator.PressingFire();
		if (! bIsFiring)
		{
			StopFiring();
		}
		GetAxes(Instigator.GetViewRotation(),X,Y,Z);
		StartTrace=Instigator.EyePosition();
		(StartTrace += (Instigator.CollisionRadius * X));
		EndTrace=(StartTrace + (TraceRange * X));
		Other=Trace(HitLocation,HitNormal,EndTrace,StartTrace,true);
		if ((Other != nullptr) && (Other != Instigator))
		{
			TargetLocation=HitLocation;
			TraceTarget=Other;
			bValidMark=false;
			if (VSize((HitLocation - MarkLocation)) < 50)
			{
				Instigator.MakeNoise(3);
				if ((Level.TimeSeconds - MarkTime) > 0.3)
				{
					bEngageTarget=((Level.TimeSeconds - MarkTime) > PaintDuration);
					if (Support == nullptr)
					{
						Support=CheckMark(HitLocation,bEngageTarget);
					}
					if ((Support != nullptr) && Support.CheckMark(Instigator,HitLocation,bEngageTarget))
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
							if (bEngageTarget)
							{
								GotoState("LockedOn");
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
			EndEffect=HitLocation;
		}
		else
		{
			EndEffect=EndTrace;
		}
	}
	simulated Function Fire(float Value)
	{
	}
	simulated Function BeginState()
	{
		MarkTime=Level.TimeSeconds;
		SetTimer(0.25,true);
	}
	simulated Function EndState()
	{
		Super::EndState();
		bAlreadyMarked=false;
		SetTimer(0,false);
		bDoHit=false;
	}
	simulated Function Timer()
	{
		bDoHit=true;
	}
	simulated Function StopFiring()
	{
		bMarkStarted=false;
		GotoState("Idle");
	}
Begin:
	if (Level.IsServer())
	{
		ClientGotoState("Targeting","None");
	}
}
*/

/*
simulated State LockedOn extends Idle
{
	simulated Function Tick(float DeltaTime)
	{
		FVector StartTrace = FVector(0,0,0);
		FVector EndTrace = FVector(0,0,0);
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		FVector HitLocation = FVector(0,0,0);
		FVector HitNormal = FVector(0,0,0);
		AActor* Other = nullptr;
		Super::Tick(DeltaTime);
		GetAxes(Instigator.GetViewRotation(),X,Y,Z);
		StartTrace=Instigator.EyePosition();
		(StartTrace += (Instigator.CollisionRadius * X));
		EndTrace=(StartTrace + (TraceRange * X));
		Other=Trace(HitLocation,HitNormal,EndTrace,StartTrace,true);
		if ((Other != nullptr) && (Other != TraceTarget))
		{
			TraceTarget=Other;
			TargetLocation=HitLocation;
			TargetNormal=HitNormal;
			GotoState("Targeting");
		}
		else
		{
			EndEffect=EndTrace;
		}
	}
	simulated Function Fire(float Value)
	{
		if (HumanController(Instigator.Controller) != nullptr)
		{
			HumanController(Instigator.Controller).CallForSupport(TargetLocation,TargetNormal);
		}
		if (Level.NetMode == NM_Client)
		{
			if (Support.bReady)
			{
				GotoState("Idle");
			}
		}
		else
		{
			if (Level.NetMode == NM_Standalone)
			{
				if (Support.bFiring)
				{
					GotoState("Idle");
				}
			}
		}
	}
	simulated Function EndState()
	{
		Super::EndState();
		TargetLocation=vect(0,0,0);
	}
	simulated Function Timer()
	{
	}
Begin:
	if (Level.IsServer())
	{
		ClientGotoState("LockedOn","None");
	}
}
*/

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
		AActor* Other = nullptr;
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
		if ((Other != nullptr) && (Other != Instigator))
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
							if (Support == nullptr)
							{
								Support=CheckMark(HitLocation,bEngageTarget);
							}
							if ((Support != nullptr) && Support.CheckMark(Instigator,HitLocation,bEngageTarget))
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
		GotoState("None");
	}
	Function EndState()
	{
		bAlreadyMarked=false;
		SetTimer(0,false);
	}
}
*/

void AItem_VIPER::Fire(float Value)
{
	if (IsZoomed())
	{
		/*
		if (IsInState("Targeting") || IsInState("LockedOn"))
		{
			GotoState("Idle");
		}
		else
		{
			GotoState("Targeting");
		}
		*/
	}
}

bool AItem_VIPER::CheckTarget()
{
	return true;
}

bool AItem_VIPER::ValidSupport()
{
	//return (Instigator.Controller.PlayerReplicationInfo.Team.TeamIndex == FirstStrike.TeamNumber);
	return false;     //FAKE   /ELiZ
}

ACallForSupport* AItem_VIPER::CheckMark(FVector aMarkLocation, bool bFire)
{
	if (FirstStrike != nullptr)
	{
		return FirstStrike;
	}
	/*
	ForEach DynamicActors(Class'AGP.CallForSupport', FirstStrike)
	{
		if (FirstStrike.IsA(SupportClass.Name) && ValidSupport())
		{
			return FirstStrike;
		}
	}
	FirstStrike = Spawn(SupportClass, , , (Location + vect(0, 0, 2000)));
	*/
	return FirstStrike;
}

void AItem_VIPER::DestroyEffects()
{
}

void AItem_VIPER::DoFireEffect()
{
}

void AItem_VIPER::ModeHoldFire()
{
	//GotoState("Paint");
}

FVector AItem_VIPER::GetFireStart(FVector X, FVector Y, FVector Z)
{
	//return ((Instigator.Location + Instigator.EyePosition()) + (X * Instigator.CollisionRadius));
	return FVector(0, 0, 0);    //FAKE   /ELiZ
}

float AItem_VIPER::MaxRange()
{
	return TraceRange;
}
