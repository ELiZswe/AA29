// All the original content belonged to the US Army


#include "DecoMesh.h"
#include "Kismet/GameplayStatics.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/BaseObjective.h"

// Sets default values
ADecoMesh::ADecoMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	NumFrags = 10;
	FragSize = 1;
	KillHealth = 100;
	InitialDamageHealth = -1;
	InitialDestroyHealth = -1;
	//DrawType = 8;
	//bWorldGeometry = true;
	bAlwaysRelevant = true;
	//bOnlyDirtyReplication = true;
	//bShadowCast = true;
	//CollisionRadius = 1;
	//CollisionHeight = 1;
	//bCollideActors = true;
	//bBlockActors = true;
	//bBlockPlayers = true;
	//bEdShouldSnap = true;

	DecoRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DecoRoot"));
	RootComponent = DecoRoot;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	
	if(StaticMesh)
	{
		StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
		if (GetLocalRole() == ROLE_Authority)
		{
			StaticMesh->SetNetAddressable(); // Make DSO components net addressable
			StaticMesh->SetIsReplicated(true); // Enable replication by default
		}
	}

	RotatingMovement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovement"));
	RotatingMovement->RotationRate = FRotator(0, 0, 0);
	RotatingMovement->PivotTranslation = FVector(0, 0, 0);
}

// Called when the game starts or when spawned
void ADecoMesh::BeginPlay()
{
	Super::BeginPlay();
	if (GetLocalRole() == ROLE_Authority)
	{
		SetReplicates(true);
	}
}

void ADecoMesh::PostBeginPlay()
{
		TArray<AActor*> BOS;
		ABaseObjective* BO;

		//Super::PostBeginPlay();

		InitialDestroyHealth=DestroyHealth;
		InitialDamageHealth=DamageHealth;
		InitialKillHealth=KillHealth;
		InitialStaticMesh=StaticMesh->GetStaticMesh();
		bInitialBreachable=bBreachable;
		bInitialDisplayTargetingInfo=bDisplayTargetingInfo;
		ClientsVerifyMesh(0);
		if (bDisplayTargetingInfo && DamageTypes.Num() > 0)
		{
			DisplayDamageType=DamageTypes[0];
		}
		if (DamageTag != NAME_None && DamageTag != NAME_None)
		{
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABaseObjective::StaticClass(), BOS);
			for (int32 i = 0; i < BOS.Num(); i++)
			{
				BO = Cast<ABaseObjective>(BOS[i]);
				if (BO->DamageTag == DamageTag)
				{
					if (DamageObjective == nullptr)
					{
						DamageObjective=BO;
					}
					else
					{
						UE_LOG(LogTemp, Log, TEXT("DecoMesh::PostBeginPlay()	Already have a DamageObjective! %s %s"), BO, DamageObjective);
					}
				}
			}
			if (DamageObjective == nullptr)
			{
				//UE_LOG(LogTemp, Log, TEXT("DecoMesh::PostBeginPlay()	Could not find DamageObjective for DamageTag %s"), DamageTag);
			}
		}
	
}
void ADecoMesh::Reset()
{
	//DebugLog(DEBUG_Door,"DecoMesh::Reset()	" $ Self $ " is setting to " $ InitialStaticMesh $ " from " $ StaticMesh);
	//SetDrawType(8);
	//SetCollision(true,true,true);
	DamageHealth=InitialDamageHealth;
	DestroyHealth=InitialDestroyHealth;
	KillHealth=InitialKillHealth;
	StaticMesh->SetStaticMesh(InitialStaticMesh);
	bBreachable=bInitialBreachable;
	bDisplayTargetingInfo=bInitialDisplayTargetingInfo;
	ClientsVerifyMesh(1);
	//Super::Reset();
}
void ADecoMesh::ClientsVerifyMesh(float fAgain)
{
	if (bUseEnemyMeshes)
	{
		VerifyMeshCount ++;
		if (fAgain > 0)
		{
			bTimerDoVerify=true;
			//SetTimer(fAgain,false);
		}
	}
}
void ADecoMesh::Timer()
{
	if (bTimerDoVerify)
	{
		ClientsVerifyMesh(0);
		bTimerDoVerify=false;
	}
}
void ADecoMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
		if (GetNetMode() != ENetMode::NM_Client)
		{
			Disable('Tick');
		}
		else
		{
			if (Level.GetClient() != None)
			{
				VerifyMesh();
				Disable('Tick');
			}
		}
	*/
}
void ADecoMesh::PostNetBeginPlay()
{
	//Super::PostNetBeginPlay();
	VerifyMesh();
}
void ADecoMesh::VerifyMesh()
{
	/*
		local PlayerReplicationInfo Client;
		local byte ClientTeam;
		if (! bUseEnemyMeshes || GetNetMode() != ENetMode::NM_Client)
		{
			Return;
		}
		Client=Level.GetClient();
		if (Client == None)
		{
			Enable('Tick');
			Return;
		}
		else
		{
			if (Client.Team == None)
			{
				ClientTeam=255;
			}
			else
			{
				ClientTeam=Client.Team.TeamIndex;
			}
		}
		if (bDamageable || bDestroyable)
		{
			if (ClientTeam != FriendlyTeam)
			{
				if (StaticMesh == InitialStaticMesh)
				{
					SetStaticMesh(EnemyStaticMesh);
				}
				else
				{
					if (StaticMesh == DamagedMesh)
					{
						SetStaticMesh(EnemyDamagedMesh);
					}
					else
					{
						if (StaticMesh == DestroyedMesh)
						{
							SetStaticMesh(EnemyDestroyedMesh);
						}
						else
						{
							if (StaticMesh != EnemyStaticMesh && StaticMesh != EnemyDamagedMesh)
							{
								DebugLog(DEBUG_Warn,"DecoMesh::VerifyMesh()	Don't know what to do with " @ StaticMesh);
							}
						}
					}
				}
			}
			else
			{
				if (StaticMesh == EnemyStaticMesh)
				{
					SetStaticMesh(InitialStaticMesh);
				}
				else
				{
					if (StaticMesh == EnemyDamagedMesh)
					{
						SetStaticMesh(DamagedMesh);
					}
					else
					{
						if (StaticMesh == EnemyDestroyedMesh)
						{
							SetStaticMesh(DestroyedMesh);
						}
						else
						{
							if (StaticMesh != InitialStaticMesh && StaticMesh != DamagedMesh)
							{
								DebugLog(DEBUG_Warn,"DecoMesh::VerifyMesh()	Don't know what to do with " @ StaticMesh);
							}
						}
					}
				}
			}
		}
	*/
}
bool ADecoMesh::IsDamaged()
{
	if (bDamageable || bBreachable && DamageHealth < 0)
	{
		return true;
	}
	return false;
}
bool ADecoMesh::ShouldTakeDamage(UaDamageType* DamageType)
{
	int32 i;
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
bool ADecoMesh::ShouldDisplayDamageType(UaDamageType* ForDamageType)
{
	if (bDisplayTargetingInfo && DisplayDamageType != nullptr)
	{
		return ForDamageType == DisplayDamageType;
	}
	else
	{
		return false;
	}
}

bool ADecoMesh::ShouldTakeDamage(float Damage, FDamageEvent const& _DamageEvent, AController* EventInstigator, AActor* DamageCauser) const
{
	/*
	if ((GetLocalRole() < ROLE_Authority) || !bCanBeDamaged || ! GetWorld()->GetAuthGameMode() || (Damage == 0.f))
	{
		return false;
	}
	*/
	return true;
}

float ADecoMesh::TakeDamage(float Damage, FDamageEvent const& _DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{

	if (GetLocalRole() < ROLE_Authority)
	{
		UE_LOG(LogTemp, Warning, TEXT("Client Call"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Server Call"));
	}

	if (!ShouldTakeDamage(Damage, _DamageEvent, EventInstigator, DamageCauser))
	{
		return 0.f;
	}
	if (DamageHealth - Damage)
	{
		//Destroy();
		StaticMesh->SetStaticMesh(DestroyedMesh);
	}
	else
	{
		DamageHealth -= Damage;

	}
	// do not modify damage parameters after this
	
	return Damage;
}


/*
void ADecoMesh::TakeDamage (int32 NDamage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* DamageType, FBoneInfo Bone, AController* KillerController, optional Actor ResponsibleActor, Material HitMaterial)
{
	if (! ShouldTakeDamage(DamageType))
	{
		if (EventLab != None)
		{
			EventLab.ActorNotify(Self,8,instigatedBy,"NODAMAGE," $ NDamage $ "," $ DamageType);
		}
		Return;
	}
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self,8,instigatedBy,"DAMAGE," $ NDamage $ "," $ DamageType);
	}
	if (DamageObjective != None)
	{
		if (bDamageable)
		{
			DamageObjective.NotifyLinkDecoDamage(instigatedBy,DamagePoints);
		}
		else
		{
			if (bDestroyable)
			{
				DamageObjective.NotifyLinkDecoDamage(instigatedBy,DestroyPoints);
			}
			else
			{
				DamageObjective.NotifyLinkDamage(instigatedBy,NDamage);
			}
		}
		DamageObjective.TakeDamage(NDamage,instigatedBy,HitLocation,Momentum,DamageType,Bone,KillerController,ResponsibleActor);
	}
	if (KillHealth >= 0)
	{
		KillHealth -= NDamage;
		if (KillHealth <= 0)
		{
			TriggerEvent(DestroyEvent,Self,instigatedBy);
			if (DamageObjective != None)
			{
				DamageObjective.NotifyLinkKill(instigatedBy);
			}
		}
	}
	Instigator=instigatedBy;
	if (Instigator != None)
	{
		MakeNoise(1);
	}
	if (bDestroyable && DestroyHealth >= 0)
	{
		DebugLog(DEBUG_Break,"DecoMesh::TakeDamage()	" $ DestroyHealth @ NDamage);
		DestroyHealth -= NDamage;
		if (DestroyHealth <= 0)
		{
			FragMomentum=Momentum;
			DebugLog(DEBUG_Break,"DecoMesh::TakeDamage()	Playing " $ DestroySound);
			TriggerEvent(DestroyEvent,Self,Instigator);
			PlaySound(DestroySound);
			DecoDestroyed();
			Return;
		}
	}
	HandleBreachDamage(NDamage);
	if (bPushable)
	{
		SetPhysics(2);
		Momentum.Z=-1000;
		Velocity=Momentum / Mass;
	}
}
*/
void ADecoMesh::HandleBreachDamage(int32 NDamage)
{
	/*
		if (bDamageable || bDestroyable || bBreachable && DamageHealth >= 0 || DestroyHealth >= 0)
		{
			if (bDamageable)
			{
				DamageHealth -= NDamage;
			}
			else
			{
				if (bDestroyable)
				{
					DestroyHealth -= NDamage;
				}
			}
			if (bDamageable && DamageHealth <= 0 || bDestroyable && DestroyHealth <= 0)
			{
				bDisplayTargetingInfo=False;
				DebugLog(DEBUG_Break,"DecoMesh::HandleBreachDamage()	Playing " $ DamageSound);
				if (bDamageable)
				{
					TriggerEvent(DamageEvent,Self,Instigator);
					PlaySound(DamageSound);
					SetStaticMesh(DamagedMesh);
				}
				else
				{
					if (bDestroyable)
					{
						TriggerEvent(DestroyEvent,Self,Instigator);
						PlaySound(DestroySound);
						SetStaticMesh(DestroyedMesh);
					}
				}
				ClientsVerifyMesh(0);
			}
		}
	*/
}
void ADecoMesh::DecoDestroyed()
{
	/*
		local int i;
		local Fragment S;
		SetDrawType(0);
		SetCollision(False,False,False);
		if (GetNetMode() != ENetMode::NM_DedicatedServer && ! PhysicsVolume.bDestructive && NumFrags > 0 && FragType != None)
		{
			DebugLog(DEBUG_Break,"DecoMesh::Destroyed()	" $ CollisionRadius);
			for (i=0; i<NumFrags; i++)
			{
				S=Spawn(FragType,Owner,,Location + 1 * VRand());
				S.CalcVelocity(FragMomentum);
				if (FragSkin != None)
				{
					S.Skins[0]=FragSkin;
				}
				S.SetDrawScale(FragSize * 1 + FRand());
			}
		}
		if (bReallyDestroy)
		{
			Destroyed();
		}
	*/
}
void ADecoMesh::Bump(AActor* Other)
{
	/*
		local float Speed;
		local float OldZ;
		if (bPushable && Pawn(Other) != None && Other.Mass > 40)
		{
			OldZ=Velocity.Z;
			Speed=VSize(Other.Velocity);
			Velocity=Other.Velocity * FMin(120,20 + Speed) / Speed;
			if (Physics == 0)
			{
				Velocity.Z=25;
				if (! bPushSoundPlaying)
				{
					PlaySound(PushSound,1,0.25);
					bPushSoundPlaying=True;
				}
			}
			else
			{
				Velocity.Z=OldZ;
			}
			SetPhysics(2);
			SetTimer(0.3,False);
			Instigator=Pawn(Other);
		}
	*/
}



void ADecoMesh::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{

	Super::GetLifetimeReplicatedProps(OutLifetimeProps);


	DOREPLIFETIME(ADecoMesh, bBreachable);
	DOREPLIFETIME(ADecoMesh, VerifyMeshCount);
	DOREPLIFETIME(ADecoMesh, InitialStaticMesh);
	DOREPLIFETIME(ADecoMesh, FriendlyTeam);
	DOREPLIFETIME(ADecoMesh, EnemyStaticMesh);
	DOREPLIFETIME(ADecoMesh, EnemyDestroyedMesh);
	DOREPLIFETIME(ADecoMesh, EnemyDamagedMesh);
	DOREPLIFETIME(ADecoMesh, DisplayDamageType);
	DOREPLIFETIME(ADecoMesh, DestroyHealth);
	DOREPLIFETIME(ADecoMesh, DestroyedMesh);
	DOREPLIFETIME(ADecoMesh, DamageHealth);
	DOREPLIFETIME(ADecoMesh, DamagedMesh);
	DOREPLIFETIME(ADecoMesh, bUseEnemyMeshes);
	DOREPLIFETIME(ADecoMesh, bReallyDestroy);
	DOREPLIFETIME(ADecoMesh, bInstantGrenBreak);
	DOREPLIFETIME(ADecoMesh, bDisplayTargetingInfo);
	DOREPLIFETIME(ADecoMesh, bDestroyable);
	DOREPLIFETIME(ADecoMesh, bDamageable);
	DOREPLIFETIME(ADecoMesh, StaticMesh);
	DOREPLIFETIME(ADecoMesh, DecoRoot);
	DOREPLIFETIME(ADecoMesh, RotatingMovement);
}


