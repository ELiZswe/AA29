// All the original content belonged to the US Army

#include "BaseProjectile.h"

ABaseProjectile::ABaseProjectile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	fWindFactor    = 1;
	fAtmoFactor    = 1;
	idTeamOwner    = 255;
	Speed          = 7000;
	MaxSpeed       = 100000;
	DrawType       = EDrawType::DT_None;
	LifeSpan       = 10;
	//bUseCollisionStaticMesh = true;
}

/*
auto State Flying
{
	simulated Function PhysicsVolumeChange(PhysicsVolume NewVolume)
	{
		if (! NewVolume.bWaterVolume)
		{
			return;
		}
		Velocity=(0.6 * Velocity);
	}
	simulated Function HitWall(Vector HitNormal, Actor Wall)
	{
		local DecoMesh DM;
		if (Role == 4)
		{
			if (Mover(Wall) != None)
			{
				Wall.TakeDamage(int(Damage),Instigator,Location,(MomentumTransfer * Normal(Velocity)),MyDamageType,,,Self);
			}
			MakeNoise(1);
		}
		if ((Wall != None) && Wall.IsA("DecoMesh"))
		{
			DM=DecoMesh(Wall);
			if (DM.bInstantGrenBreak && (DM.DamageHealth > 0))
			{
				DM.TakeDamage((DM.InitialDamageHealth * 1000),Instigator,DM.Location,vect(0,0,0),None,,,Self);
				return;
			}
		}
		FindCollide(Wall,1);
	}
	simulated Function Landed(Vector HitNormal)
	{
		FindCollide(None,2);
	}
	simulated Function FindCollide(Actor CAct, ECollisionType CType)
	{
		FVector HitLoc = FVector(0,0,0);
		FVector HitNorm = FVector(0,0,0);
		local Material HitMaterial;
		int32 PolyFlags = 0;
		StopTrail();
		Trace(HitLoc,HitNorm,(Location + (Velocity * float(1000))),Location,true,vect(0,0,0),HitMaterial,PolyFlags);
		if (PFlag_DeleteProjectiles(PolyFlags))
		{
			Destroy();
		}
		else
		{
			Collision(CAct,HitLoc,HitNorm,HitMaterial,CType);
		}
	}
	simulated Function ProcessTouch(Actor Other, Vector HitLocation)
	{
		FVector HitNormal = FVector(0,0,0);
		if (Other == None)
		{
			return;
		}
		HitNormal=Normal((HitLocation - Other.Location));
		StopTrail();
		Collision(Other,HitLocation,HitNormal,Other.Texture,3);
	}
}
*/

