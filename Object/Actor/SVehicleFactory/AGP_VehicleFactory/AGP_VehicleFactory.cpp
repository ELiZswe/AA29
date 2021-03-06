// All the original content belonged to the US Army

#include "AA29/Object/Actor/SVehicleFactory/AGP_VehicleFactory/AGP_VehicleFactory.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"

AAGP_VehicleFactory::AAGP_VehicleFactory()
{
	RespawnTime = 15;
	PreSpawnEffectTime = 2;
	SpawnedVehicleTag = "AGP_FactoryBuiltVehicle";
	//DrawType = 2;
	//NV_AmbientGlow = 253;
}

void AAGP_VehicleFactory::BeginPlay()
{
	SpawnVehicle();
}


void AAGP_VehicleFactory::PostBeginPlay()
{
	//Super::PostBeginPlay();
	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		//VehicleClass->StaticPrecache(Level);
	}
}

void AAGP_VehicleFactory::UpdatePrecacheMaterials()
{
	//VehicleClass->StaticPrecache(Level);
}

void AAGP_VehicleFactory::PostNetBeginPlay()
{
	//Super::PostNetBeginPlay();
	Activate(0);
}

void AAGP_VehicleFactory::Activate(uint8 t)
{
	if ((!bNeverActivate) && ((!bActive) || (TeamNum != t)))
	{
		TeamNum = t;
		bActive = true;
		bPreSpawn = true;
		Timer();
	}
}

void AAGP_VehicleFactory::Deactivate()
{
	bActive = false;
}

void AAGP_VehicleFactory::VehicleDestroyed(AVehicle* V)
{
	Super::VehicleDestroyed(V);
	/*
	if (GetGameMode()->bWaitingToStartMatch)
	{
		Timer();
	}
	else
	{
		if (RespawnTime >= 0)
		{
			bPreSpawn = true;
			SetTimer((RespawnTime - PreSpawnEffectTime), false);
		}
	}
	*/
}

void AAGP_VehicleFactory::SpawnVehicle()
{
	APawn* p = nullptr;
	bool bBlocked = false;
	/*
	if (Role < 4)
	{
		return;
	}
	*/

	/*
	ForEach CollidingActors(Class'Pawn', p, (VehicleClass.Default.CollisionRadius * 1.25))
	{
		bBlocked = true;
	}
	*/
	if (bBlocked)
	{
		//SetTimer(1, false);
	}
	else
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = GetInstigator();
		FVector myLocation = GetActorLocation();

		//Mine:
		LastSpawned = GetWorld()->SpawnActor<AVehicle>(VehicleClass, myLocation, GetActorRotation(), SpawnParams);
	
		//Org:
		//LastSpawned = Spawn(VehicleClass, , SpawnedVehicleTag, GetActorLocation(), GetActorRotation());

		if (LastSpawned != nullptr)
		{
			VehicleCount++;
			/*
			LastSpawned->SetTeamNum(byte(TeamNum));
			LastSpawned->Event = Tag;
			LastSpawned->ParentFactory = this;
			LastSpawned->NV_AmbientGlow = NV_AmbientGlow;
			if (EventLab != nullptr)
			{
				EventLab.ActorNotify(this, 24, LastSpawned);
			}
			*/
		}
	}
}

bool AAGP_VehicleFactory::ValidateSpawnLocation(float Radius)
{
	APawn* p = nullptr;
	/*
	ForEach CollidingActors(Class'Pawn', p, Radius)
	{
		return false;
	}
	*/
	return true;
}

void AAGP_VehicleFactory::SpawnBuildEffect()
{
	FRotator YawRot = FRotator(0, 0, 0);
	YawRot = GetActorRotation();
	YawRot.Roll = 0;
	YawRot.Pitch = 0;
}

void AAGP_VehicleFactory::Timer()
{
	/*
	if ((bActive && GetGameMode()->bAllowVehicles) && (VehicleCount < MaxVehicleCount))
	{
		if (bPreSpawn && (PreSpawnEffectTime > 0))
		{
			bPreSpawn = false;
			//SetTimer(PreSpawnEffectTime, false);
		}
		else
		{
			SpawnVehicle();
		}
	}
	*/
}


void AAGP_VehicleFactory::Trigger(AActor* Other, APawn* EventInstigator)
{
}
