// All the original content belonged to the US Army

#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_DestroyableObjective/AGP_DestroyableObjective.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameInfo.h"

AAGP_DestroyableObjective::AAGP_DestroyableObjective(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{
	DamageEventThreshold = 1;
	StartingHealth = 600;
	AccomplishMessage = "Objective destroyed.";
	FailedDefenseMessage = "Your team failed to defend the Objective.";
	AttackDescription = "Destroy the objective.";
	DefenseDescription = "Prevent the objective's destruction.";
	//CollisionRadius = 30;
	//CollisionHeight = 30;
	//bCollideActors = true;
	//bProjTarget = true;

	//Defined in Keypoint
	//RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	//StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	//StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void AAGP_DestroyableObjective::PostBeginPlay()
{
	
	Super::BeginPlay();
	Reset();
	bTakeTurns=false;
	//NotifyInstigatorActor = GetActorByTag(NotifyInstigatorOfActor);
}
void AAGP_DestroyableObjective::Reset()
{
	Super::Reset();
	Health=StartingHealth;
	AccumulatedDamage=0;
}
void AAGP_DestroyableObjective::SideReset()
{
	Super::SideReset();
	Health=StartingHealth;
	AccumulatedDamage=0;
}
float AAGP_DestroyableObjective::GetPercentComplete()
{
	float posheal = 0;
	float retval = 0;
	if (! IsEnabled() || StartingHealth == 0)
	{
		return 1;
	}
	posheal=Health;
	if (posheal < 0)
	{
		posheal=0;
	}
	retval=1 - posheal / StartingHealth;
	if (retval > 0.99)
	{
		retval=0.99;
	}
	return retval;
}

bool AAGP_DestroyableObjective::ShouldTakeDamage(UaDamageType* DamageType)
{
	int32 i = 0;
	if (bCheckDamageType)
	{
		for (i=0; i<DamageTypes.Num(); i++)
		{
			if (DamageType == DamageTypes[i])
			{
				return true;
			}
		}
		return false;
	}
	else
	{
		return true;
	}
}

/*
void AAGP_DestroyableObjective::TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType*  DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UTexture2D* HitMaterial)
{
		Log(Self + "." + Tag + " TakeDamage Enabled " + IsEnabled() + ", Damage: " + Damage + " damage type: " + DamageType + " accepted: " + ShouldTakeDamage(DamageType));
		if (Damage <= 0 || ! IsEnabled())
		{
			return;
		}
		if (ShouldTakeDamage(DamageType))
		{
			AccumulatedDamage += Damage;
			if (AccumulatedDamage >= DamageEventThreshold)
			{
				TriggerEvent(TakeDamageEvent,Self,instigatedBy);
				AccumulatedDamage=0;
			}
			Health -= Damage;
			if (Health <= 0)
			{
				TriggerEvent(DestroyEvent,Self,instigatedBy);
				AccomplishObjective(instigatedBy,KillerController);
			}
			SendPercentage(instigatedBy);
			if (NotifyInstigatorActor != nullptr)
			{
				iLastPercent=255;
				SendPercentage(NotifyInstigatorActor.Instigator);
			}
			if (Cast<AAGP_GameInfo>(GetGameMode()).IsTeamGame() && instigatedBy->IsA(AAGP_Pawn::StaticClass()) && ! CanTeamAttack(Cast<AAGP_Pawn>(instigatedBy).PlayerReplicationInfo.Team.TeamIndex))
			{
				AGP_GameInfo(GetGameMode()).RecordFriendlyFire(instigatedBy.PlayerReplicationInfo,None,Damage);
				if (Health < 0)
				{
					instigatedBy.PlayerReplicationInfo.PScoreFF(40);
				}
			}
		}
}
*/

void AAGP_DestroyableObjective::grenadeNotifier(AActor* Explosive, UaDamageType* DamageType, AController* KillerController)
{
	FVector HitLocation = FVector(0, 0, 0);
	FVector Momentum = FVector(0, 0, 0);
	if (bWatchForGrenades)
	{
		/*
		if (VSizeSquared((Explosive.Location - Location)) < (CollisionRadius * CollisionRadius))
		{
			TakeDamage(100, KillerController.Pawn, HitLocation, Momentum, DamageType, , KillerController);
		}
		*/
	}
}
