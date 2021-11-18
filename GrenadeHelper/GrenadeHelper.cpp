// All the original content belonged to the US Army

#include "AA29/GrenadeHelper/GrenadeHelper.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AGrenadeHelper::AGrenadeHelper()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PawnBones = { "head","RArmUp","LArmUp","Spine02","RLegUp","LLegUp"};
	ActorOffsets = { {1,1}, {1,0}, {1, -1}, {0, 1}, {0, 0}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1} };
	//DrawType = 0
	//RemoteRole = 0
}

// Called when the game starts or when spawned
void AGrenadeHelper::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGrenadeHelper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AGrenadeHelper::GrenadeEffects(AActor* Grenade, FVector ExplosionLocation, float fDamageRadius, float fKillRadius, float fEffectDuration, float fMaxAudIntensity, float fMaxVisIntensity)
{
	/*
		local float VisIntensity;
		local float AudIntensity;
		local float dist;
		local float DistRatio;
		local float ViewDotFlash;
		local Pawn p;
		local Actor A;
		local FVector Eye;
		local FVector PlayerHead;
		local FVector PlayerBody;
		local FVector PlayerFeet;
		if (fMaxAudIntensity == 0 && fMaxVisIntensity == 0)
		{
			Return;
		}
		if (Grenade != None && Grenade.EventLab != None)
		{
			Grenade.EventLab.ActorNotify(Grenade,10);
		}
		ForEach CollidingActors('Actor',A,fDamageRadius,ExplosionLocation)
		{
			if (A.IsA('DamageDetector'))
			{
				A.ActorNotify(Self,0,None,"FLASHEFFECT," $ 1 - VSize(A.Location - ExplosionLocation) / fDamageRadius $ "," $ Grenade.Class);
			}
			else
			{
				p=Pawn(A);
				if (p != None && p.Controller != None && p.IsHumanControlled() || p.Controller.IsA('AIController') && ! p.bHidden)
				{
					VisIntensity=fMaxVisIntensity;
					AudIntensity=fMaxAudIntensity;
					Eye=p.EyePosition();
					dist=VSize(Eye - ExplosionLocation);
					if (dist > fKillRadius - p.CollisionRadius)
					{
						DistRatio=1 - FMax(0,dist - p.CollisionRadius - fKillRadius / fDamageRadius - fKillRadius);
						VisIntensity *= DistRatio;
						AudIntensity *= DistRatio;
					}
					if (! p.FastTrace(ExplosionLocation,Eye) && VSize(ExplosionLocation - p.Location) > p.CollisionRadius)
					{
						VisIntensity *= 0.15;
						AudIntensity *= 0.3;
					}
					if (VisIntensity > 0)
					{
						ViewDotFlash= Vector(p.GetViewRotation()) Dot Normal(Eye - ExplosionLocation);
						if (ViewDotFlash > -0.5)
						{
							VisIntensity *= 0.5 + 0.5 * 1 - ViewDotFlash / 1.5;
						}
					}
					if (! Grenade.Region.Zone.bIndoorZone)
					{
						if (! Level.bNighttimeMission)
						{
							VisIntensity *= 0.65;
						}
						AudIntensity *= 0.65;
					}
					if (! p.Region.Zone.bIndoorZone)
					{
						if (! Level.bNighttimeMission)
						{
							VisIntensity *= 0.65;
						}
						AudIntensity *= 0.65;
					}
					PlayerBody=p.Location;
					if (p.bIsProne && p.FrontAuxCyl != None && p.BackAuxCyl != None)
					{
						PlayerHead=p.FrontAuxCyl.Location;
						PlayerFeet=p.BackAuxCyl.Location;
					}
					else
					{
						PlayerHead=PlayerBody;
						PlayerHead.Z += p.CollisionHeight;
						PlayerFeet=PlayerBody;
						PlayerFeet.Z -= p.CollisionHeight;
					}
					if (! FastTrace(ExplosionLocation,PlayerHead) && ! FastTrace(ExplosionLocation,PlayerBody) && ! FastTrace(ExplosionLocation,PlayerFeet))
					{
						VisIntensity=0;
						AudIntensity *= 0.66;
					}
					DebugLog(DEBUG_Gren,"GrenadeHelper::GrenadeEffects()	" $ p @ AudIntensity @ VisIntensity @ fEffectDuration);
					if (AudIntensity > 0.1 || VisIntensity > 0.1)
					{
						p.CombatEffectivenessEvent(2,FMax(VisIntensity,AudIntensity));
						if (VisIntensity > 0.1)
						{
							if (p.Controller != None)
							{
								if (p.Controller.IsA('AIController'))
								{
									AIController(p.Controller).NotifyFlashBanged(fEffectDuration,VisIntensity * 1.5,AudIntensity * 1.25);
								}
								else
								{
									PlayerController(p.Controller).FlashBanged(fEffectDuration,VisIntensity * 1.5,AudIntensity * 1.25);
								}
							}
						}
						else
						{
							if (p.Controller != None && p.IsA('PlayerController'))
							{
								PlayerController(p.Controller).Grenaded(fEffectDuration,AudIntensity);
							}
						}
					}
				}
			}
		}
	*/
}

//agp [cmb] Moved this here from Actor.uc [2/20/2003]
/* ======================================================================================
* AGP function - GrenHurtRadius
* Does traces for each actor to head loc and feet to see if they could be hit and adds a
* randomization to see if they can be hit (the more points exposed the more likely)
* input:	float DamageAmount - Damage at ground zero
*			float DamageRadius - Max radius of damage
*			class DamageType   - Type of damage inflicted
*			float Momentum	   - Momentum transfered from center of the blast
* Vector ExplosionLocation - Center of the blast
* notes: NOT simulated because random numbers have to be determined on server
* last modified by:  superville 03/06/02
* =================================================================================== */
void AGrenadeHelper::GrenHurtRadius(AActor* Grenade, FVector ExplosionLocation, float DamageRadius, float KillRadius, float DamageAmount, UDamageType* ExplosionDamageType, UDamageType* FragDamageType, float Momentum, TArray<AActor> DamageClassList, AController* KillerController)
{
	/*
		local Pawn Killer;
		local Actor Victim;
		local Pawn PawnVictim;
		local float damageScale;
		local float dist;
		local float ExposurePct;
		local float HitPct;
		local float ExposureRand;
		local float HitRand;
		local FVector Dir;
		local class<DamageType>  DamageClass;
		local FVector vMomentum;
		local int Index;
		local DecoMesh DM;
		DamageClassList[DamageClassList.Length]=class<Actor>(DynamicLoadObject("AGP_Vehicles.CROWS_Base",Class'Class'));
		DamageClassList[DamageClassList.Length]=class<Actor>(DynamicLoadObject("AGP_Gameplay.AGP_CoopESSObjective",Class'Class'));
		if (Grenade != None && ExplosionDamageType != None && KillerController != None)
		{
			Level.Game.grenadeNotifier(Grenade,ExplosionDamageType,KillerController);
		}
		if (bHurtEntry)
		{
			Return;
		}
		if (KillerController != None)
		{
			Killer=KillerController.Pawn;
		}
		if (Killer == None && Grenade != None)
		{
			Killer=Grenade.Instigator;
		}
		if (EventLab != None)
		{
			EventLab.ActorNotify(Grenade,8,Killer,"Grenade_Explode");
		}
		DebugLog(DEBUG_Gren,"GrenadeHelper::GrenHurtRadius()	==================================");
		DebugLog(DEBUG_Gren,"GrenadeHelper::GrenHurtRadius()	" @ Grenade $ ExplosionLocation);
		bHurtEntry=True;
		TurnPickupsOff();
		DM=DecoMesh(Grenade);
		bHasNotDamagedDeco=True;
		if (DM != None)
		{
			Dir=DM.Location - ExplosionLocation;
			dist=FMax(1,VSize(Dir));
			Dir=Dir / dist;
			ExposurePct=GetExposureTrace(DM,Grenade,ExplosionLocation,dist);
			if (dist < KillRadius)
			{
				DamageClass=ExplosionDamageType;
				damageScale=1;
				vMomentum.Z=Momentum * ExposurePct;
				ExposurePct=FMin(ExposurePct * 2,1);
			}
			else
			{
				DamageClass=FragDamageType;
				damageScale=1 - FMax(0,dist - KillRadius / DamageRadius - KillRadius);
			}
			vMomentum += damageScale * Momentum * Dir;
			if (bHasNotDamagedDeco)
			{
				bHasNotDamagedDeco=False;
				DM.TakeDamage(FMax(0,damageScale * DamageAmount * ExposurePct),Killer,DM.Location - 0.5 * DM.CollisionHeight + DM.CollisionRadius * Dir,vMomentum,DamageClass,,KillerController,Grenade);
			}
		}
		else
		{
			if (Grenade != None)
			{
				for (Index=0; Index<DamageClassList.Length; Index++)
				{
					if (DamageClassList[Index] == None)
					{
					}
					DebugLog(DEBUG_Gren,"GrenadeHelper::GrenHurtRadius()	-------------------------------");
					DebugLog(DEBUG_Gren,"GrenadeHelper::GrenHurtRadius()	Looking for " $ DamageClassList[Index]);
					ForEach RadiusActors(DamageClassList[Index],Victim,DamageRadius,ExplosionLocation)
					{
						if (Victim.Role == 4 && ! Victim.bHidden || Victim.IsA('AGP_MortarRangeDestroyableObjective'))
						{
							DebugLog(DEBUG_Gren,"GrenadeHelper::GrenHurtRadius()	Found Victim " $ Victim);
							if (Victim.IsA('Vehicle'))
							{
								if (Vehicle(Victim).TakeRadiusDamage(DamageAmount,Killer,ExplosionLocation,Momentum,ExplosionDamageType,DamageRadius))
								{
								}
							}
							else
							{
								if (Pawn(Victim) != None && Pawn(Victim).Controller == None && Pawn(Victim).DrivenVehicle != None)
								{
								}
								else
								{
									HitPct=0;
									ExposurePct=0;
									HitRand=0;
									ExposureRand=0;
									Dir=Victim.Location - ExplosionLocation;
									dist=FMax(1,VSize(Dir));
									Dir=Dir / dist;
									PawnVictim=Pawn(Victim);
									if (PawnVictim != None)
									{
										ExposurePct=GetExposureBoneTrace(PawnVictim,Grenade,ExplosionLocation);
										if (PawnVictim.IsHumanControlled())
										{
											if (dist < DamageRadius / 2)
											{
												PawnVictim.CombatEffectivenessEvent(3);
											}
											PlayerController(PawnVictim.Controller).GrenadeExploded(2,1 - FMax(0,dist - Victim.CollisionRadius - 240 / DamageRadius));
										}
									}
									else
									{
										ExposurePct=GetExposureTrace(Victim,Grenade,ExplosionLocation,dist);
									}
									if (ExposurePct > 0)
									{
										if (dist < KillRadius)
										{
											DamageClass=ExplosionDamageType;
											damageScale=1;
											vMomentum.Z=Momentum * ExposurePct;
											ExposurePct=FMin(ExposurePct * 2,1);
										}
										else
										{
											DamageClass=FragDamageType;
											damageScale=1 - FMax(0,dist - KillRadius / DamageRadius - KillRadius);
										}
										if (damageScale == 1 || FRand() < damageScale * ExposurePct || damageScale > DamageClass.Default.MinFragDamageScale)
										{
											vMomentum += damageScale * Momentum * Dir;
											DM=DecoMesh(Victim);
											if (DM != None)
											{
												if (bHasNotDamagedDeco)
												{
													bHasNotDamagedDeco=False;
													Victim.TakeDamage(FMax(0,damageScale * DamageAmount * ExposurePct),Killer,Victim.Location - 0.5 * Victim.CollisionHeight + Victim.CollisionRadius * Dir,vMomentum,DamageClass,,KillerController,Grenade);
												}
											}
											else
											{
												Victim.TakeDamage(FMax(0,damageScale * DamageAmount * ExposurePct),Killer,Victim.Location - 0.5 * Victim.CollisionHeight + Victim.CollisionRadius * Dir,vMomentum,DamageClass,,KillerController,Grenade);
											}
											DebugLog(DEBUG_Gren,"GrenadeHelper::GrenHurtRadius()	Victim(" @ Victim @ ") ExposurePct(" @ ExposurePct @ ") ExposureRand(" @ ExposureRand @ ") HitPct(" @ HitPct @ ") HitRand(" @ HitRand @ ") Distance(" @ dist @ ") Damage(" @ damageScale * DamageAmount @ ")");
										}
										else
										{
											DebugLog(DEBUG_Gren,"GrenadeHelper::GrenHurtRadius()	Random Reject - tested against" @ ExposurePct * damageScale $ " from " @ ExposurePct @ damageScale);
										}
									}
									else
									{
										DebugLog(DEBUG_Gren,"GrenadeHelper::GrenHurtRadius()	Victim has no exposure - HL(" $ ExplosionLocation $ ") VL(" $ Victim.Location $ ")");
									}
								}
							}
						}
					}
				}
			}
		}
		bHurtEntry=False;
		TurnPickupsOn();
	*/
}

//agp [cmb] Helper for GetExposureTrace() [4/22/2004]
void AGrenadeHelper::CheckMinDistance(FVector v1, FVector v2, float& MinDistance)
{
	float size_squared;
	size_squared= UKismetMathLibrary::VSizeSquared(v1 - v2);			//agp [cmb] Avoid Sqrt() if possible [4/22/2004]
	if (size_squared < MinDistance * MinDistance)
	{
		//DebugLog(DEBUG_Gren,"GrenadeHelper::CheckMinDistance()	Found a smaller distance(" @ Sqrt(size_squared) @ ") was(" @ MinDistance @ ")");
		MinDistance=FMath::Sqrt(size_squared);
	}
}

bool AGrenadeHelper::ExposureTrace(AActor* Victim, AActor* Grenade, FVector Start, FVector End)
{
	/*
		AActor* Hit;
		AActor* HitTwo;
		FVector HitLoc;
		FVector HitNorm;
		FVector HitLocA;
		FVector Temp;
		bool bBreachDamage;
		if (Victim != nullptr && Victim.IsA('Mover'))
		{
			Hit=Victim.Trace(HitLoc,HitNorm,End,Start,false);
		}
		else
		{
			Hit=Victim.Trace(HitLoc,HitNorm,Victim.GetActorLocation(),Grenade.GetActorLocation(),false);
		}
		if (Hit != nullptr)
		{
			if (BaseObjective(Hit) != nullptr && Hit.IsA('AGP_Objective'))
			{
				if (BaseObjective(Hit).HandleGrenadeDamage())
				{
					return true;
				}
			}
		}
		if (Hit != nullptr && Victim.IsA('Pawn') && Hit.IsA('Pawn') || Hit.IsA('Mover') && Mover(Hit).IsDamaged() && HitTwo != Victim)
		{
			Temp=Start;
			Hit=Hit.Trace(HitLocA,HitNorm,Victim.GetActorLocation(),HitLoc,true);
			if (Hit != nullptr && Hit.IsA('AuxCollisionCylinder'))
			{
				Hit=Hit.GetOwner();
			}
			if (Hit == Victim)
			{
				bBreachDamage=true;
			}
		}
		//DebugLog(DEBUG_Gren,"GrenadeHelper::ExposureTrace()	" $ Hit @ Grenade @ Victim);
		return Hit == nullptr || Hit == Grenade || bBreachDamage;
	*/
	return false;		//FAKE ELiZ
}
float AGrenadeHelper::GetExposureTrace(AActor* Victim, AActor* Grenade, FVector ExplosionLoc, float& MinDistance)
{
	/*
		if (Victim.DrawType == 8 && ! Victim.bUseCylinderCollision)
		{
			return GetExposureBBoxTrace(Victim,Grenade,ExplosionLoc,MinDistance);
		}
		else
		{
			return GetExposureCylinderTrace(Victim,Grenade,ExplosionLoc,MinDistance);
		}
	*/
	return 0;		//FAKE ELiZ
}
float AGrenadeHelper::GetExposureBBoxTrace(AActor* Victim, AActor* Grenade, FVector ExplosionLoc, float& MinDistance)
{
	/*
	int32 num_i;
	int32 num_j;
	int32 num_k;
	int32 i;
	int32 j;
	int32 k;
	FBox BBox;
	FVector Test;
	FVector Min;
	FVector Max;
	FVector Mid;
	FVector Delta;
	float X;
	float Y;
	float Z;
	int32 num_hits;

	BBox=Victim.GetBoundingBox();

	Delta=BBox.Max - BBox.Min;
	Mid=BBox.Max + BBox.Min / 2;
	Min=BBox.Min + Delta * 0.05;
	Max=BBox.Max - Delta * 0.05;
	if (FMath::Abs(Delta.X) < 128)
	{
		num_i=2;
	}
	else
	{
		num_i=3;
	}
	if (FMath::Abs(Delta.Y) < 128)
	{
		num_j=2;
	}
	else
	{
		num_j=3;
	}
	if (FMath::Abs(Delta.Z) < 128)
	{
		num_k=2;
	}
	else
	{
		num_k=3;
	}
	for (i=0; i<num_i; i++)
	{
		switch(i)
		{
			case 0:
				X=Min.X;
				break;
			case 1:
				X=Max.X;
				break;
			case 2:
				X=Mid.X;
				break;
			default:
		}
		for (j=0; j<num_j; j++)
		{
			switch(j)
			{
				case 0:
					Y=Min.Y;
					break;
				case 1:
					Y=Max.Y;
					break;
				case 2:
					Y=Mid.Y;
					break;
				default:
			}
			for (k=0; k<num_k; k++)
			{
				switch(k)
				{
					case 0:
						Z=Min.Z;
						break;
					case 1:
						Z=Max.Z;
						break;
					case 2:
						Z=Mid.Z;
						break;
					default:
				}
				Test= FMath::MakeVect(X,Y,Z);
				if (ExposureTrace(Victim,Grenade,Test,ExplosionLoc))
				{
					CheckMinDistance(ExplosionLoc,Test,MinDistance);
					num_hits ++;
				}
			}
		}
	}
	return num_hits / num_i * num_j * num_k;
	*/
	return 0;		//FAKE ELiZ
}
FVector AGrenadeHelper::GetOffset(FTestOffset Off, FVector Location, FVector H, FVector V)
{
	return Location;
}
float AGrenadeHelper::GetExposureCylinderTrace(AActor* Victim, AActor* Grenade, FVector ExplosionLoc, float& MinDistance)
{
	/*
		FVector X;
		FVector Y;
		FVector Z;
		FVector HOffset;
		FVector VOffset;
		int32 i;
		float fTotalExposure;
		float fEachExposure;
		FVector Test;

		GetAxes(Victim.GetActorLocation() - ExplosionLoc,X,Y,Z);
		VOffset=Z * Victim.CollisionHeight * 0.98;
		HOffset=Y * Victim.CollisionRadius * 0.98;
		fEachExposure=1 / ActorOffsets.Max();
		for (i=0; i<ActorOffsets.Max(); i++)
		{
			Test=GetOffset(ActorOffsets[i],Victim.GetActorLocation(),HOffset,VOffset);
			if (ExposureTrace(Victim,Grenade,Test,ExplosionLoc))
			{
				CheckMinDistance(ExplosionLoc,Test,MinDistance);
				fTotalExposure += fEachExposure;
			}
		}
		return fTotalExposure;
	*/
	return 0;		//FAKE ELiZ
}
float AGrenadeHelper::GetExposureBoneTrace(APawn* Victim, AActor* Grenade, FVector ExplosionLoc)
{
	/*
		int32 i;
		float fTotalExposure;
		float fEachExposure;
		FVector Test;
		fEachExposure=1 / PawnBones.Max();
		for (i=0; i<PawnBones.Max(); i++)
		{
			Test=Victim.GetBoneCoords(PawnBones[i]).Origin;
			if (ExposureTrace(Victim,Grenade,Test,ExplosionLoc))
			{
				fTotalExposure += fEachExposure;
			}
		}
		return fTotalExposure;
	*/
	return 0;		//FAKE ELiZ
}
void AGrenadeHelper::TurnPickupsOn()
{
	APickup* p;
	p = Cast<AAA2_WorldSettings>(GetWorldSettings())->PickupList;
	if (p != nullptr)
	{
		//p.bBlockZeroExtentTraces=true;
		//p=p.Next;
	}
}
void AGrenadeHelper::TurnPickupsOff()
{
	APickup* p;
	p= Cast<AAA2_WorldSettings>(GetWorldSettings())->PickupList;
	if (p != nullptr)
	{
		//p.bBlockZeroExtentTraces=false;
		//p=p.Next;
	}
}