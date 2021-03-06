// All the original content belonged to the US Army

#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_TriggeredObjective.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_doctor/NPC_doctor.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/StudentController/StudentController.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))

AAGP_TriggeredObjective::AAGP_TriggeredObjective(const FObjectInitializer& objectInitializer) 
	:Super(objectInitializer)
{
	//CollisionRadius = 40;
	//CollisionHeight = 40;
	//bCollideActors = true;
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->InitCapsuleSize(100.0f, 200.0f);
	Capsule->SetCollisionEnabled(ECollisionEnabled::QueryOnly); // We want overlaps.
	//Capsule->SetCollisionProfileName("Pawn"); // We want to be on the "Pawn" collision channel
	//Capsule->SetGenerateOverlapEvents(true);
	//RootComponent = Capsule;
	Capsule->SetupAttachment(RootComponent);

#if WITH_EDITORONLY_DATA
	if (!SpriteComponent)
	{
		SpriteComponent = CreateDefaultSubobject<UBillboardComponent>(TEXT("Sprite"));
	}
	
	SpriteComponent->Sprite = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/Engine/AGP_Objective.AGP_Objective'"), NULL, LOAD_None, NULL);
	SpriteComponent->AttachToComponent(Capsule, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
#endif // WITH_EDITORONLY_DATA	

//	OnActorBeginOverlap.AddDynamic(this, &AAGP_TriggeredObjective::OnOverlap);

}

/*
State Counting
{
	Function float GetPercentComplete()
	{
		if (! IsEnabled())
		{
			return 1;
		}
		if (fTimeToTrigger == 0)
		{
			return 0;
		}
		return (TimerCounter / fTimeToTrigger);
	}
	Function UnTrigger(AActor* Other, APawn* Instigator)
	{
		StopCounting();
	}
	Function UnTouch(AActor* Other)
	{
		StopCounting();
	}
	Function StopCounting()
	{
		APawn* LocalStoreInstigator = nullptr;
		LocalStoreInstigator=StoredInstigator;
		StoredInstigator.ExitTrigger(this);
		iLastPercent=0;
		SendPercentage(LocalStoreInstigator);
		GotoState("None");
	}
	Function PawnDied(APawn* p)
	{
		APlayerController* PC = nullptr;
		Log(string(this) + "." + FString::FromInt(GetStateName()) + ".PawnDied() instigator: " + FString::FromInt(StoredInstigator) + " health: " + FString::FromInt(StoredInstigator.Health) + " is dead: " + FString::FromInt(StoredInstigator.bIsDead));
		if (p == StoredInstigator)
		{
			PC=Cast<APlayerController>(p.Controller);
			if (((Level.Game.Stats != nullptr) && (PC != nullptr)) && (PC.PlayerStatsIndex >= 0))
			{
				Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ObjectiveDeath();
			}
			UnTouch(p);
		}
	}
	Function Tick(float Delta)
	{
		SendPercentage(StoredInstigator);
	}
	Function Timer()
	{
		if ((StoredInstigator != nullptr) && (StoredInstigator.Health > 0))
		{
			AccomplishObjective(StoredInstigator);
			SendPercentage(StoredInstigator);
		}
		GotoState("None");
	}
	Function BeginState()
	{
		SetTimer(fTimeToTrigger,false);
		SendPercentage(StoredInstigator);
		Cast<AAGP_Pawn>(StoredInstigator).SetCurrentTrigger(this);
	}
	Function EndState()
	{
		Cast<AAGP_Pawn>(StoredInstigator).SetCurrentTrigger(nullptr);
	}
}
*/

void AAGP_TriggeredObjective::Reset()
{
	//APawn* p;
	Super::Reset();
	if (StoredInstigator != NULL && Cast<AAGP_Pawn>(StoredInstigator)->bUsingObjective)
	{
		Cast<AAGP_Pawn>(StoredInstigator)->bUsingObjective=false;
	}
	StoredInstigator=NULL;
	/*
	SetTimer(0,false);
	ForEach TouchingActors(Class'Pawn',p)
	{
		Touch(p);
	}
	*/
}
void AAGP_TriggeredObjective::SideReset()
{
	//APawn* p;
	Super::SideReset();
	if (Cast<AAGP_Pawn>(StoredInstigator) != NULL && Cast<AAGP_Pawn>(StoredInstigator)->bUsingObjective)
	{
		Cast<AAGP_Pawn>(StoredInstigator)->bUsingObjective=false;
	}
	StoredInstigator=NULL;
	/*
	SetTimer(0,false);
	ForEach TouchingActors(Class'Pawn',p)
	{
		Touch(p);
	}
	*/
}
float AAGP_TriggeredObjective::GetPercentComplete()
{
	if (! IsEnabled())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool AAGP_TriggeredObjective::CanAccomplish(APawn* p)
{
	if (p->IsA(ANPC_doctor::StaticClass()) && bMustBeNPC)
	{
		return true;
	}
	if (! CanAccomplish(p))
	{
		return false;
	}
	/*
	if (MustBeClass != nullptr && ! Cast<AAGP_Pawn>(p)->TeamClass->IsA(MustBeClass.Name))
	{
		return false;
	}
	if (MustHaveInInventory != nullptr && p->FindInventoryType(MustHaveInInventory) == nullptr)
	{
		return false;
	}
	if (MustBeHolding != nullptr && p->Weapon != nullptr && ! p->Weapon->IsA(MustBeHolding.Name))
	{
		return false;
	}
	*/
	return true;
}

void AAGP_TriggeredObjective::UnTrigger(AActor* Other, APawn* _Instigator)
{
}

void AAGP_TriggeredObjective::UnTouch(AActor* Other)
{
}

void AAGP_TriggeredObjective::Touch(AActor* Other)
{
	UE_LOG(LogTemp, Warning, TEXT("Touched"));
	AActor* TempActor = nullptr;
	APawn* Pawn = nullptr;
	if (!IsEnabled())
	{
		return;
	}
	/*
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		Pawn=Pawn(Other);
		if (Pawn != nullptr && Pawn.Controller->IsA(AStudentController::StaticClass()))
		{
			if (EventLab != nullptr)
			{
				EventLab.ActorNotify(this,4,Pawn,"");
			}
		}
	}
	if (Other->IsA(APawn::StaticClass()) && CanAccomplish(Cast<APawn>(Other)))
	{
		if (Other->IsA(ANPC_doctor::StaticClass))
		{
			TempActor=Other;
			Other=NPC_doctor(Other).LastUsedBy;
		}
		if (fTimeToTrigger <= 0)
		{
			AccomplishObjective(Cast<APawn>(Other));
		}
		else
		{
			StoredInstigator=Pawn(Other);
			Other.EnterTrigger(this);
			GotoState('Counting');
		}
	}
	*/
}

void AAGP_TriggeredObjective::Trigger(AActor* Other, APawn* _Instigator)
{
	UE_LOG(LogTemp, Warning, TEXT("Trigger"));
	if (! IsEnabled())
	{
		return;
	}
	if (! CanAccomplish(_Instigator))
	{
		return;
	}
	if (fTimeToTrigger <= 0)
	{
		//AccomplishObjective(_Instigator);
	}
	else
	{
		//Log(Self @ "AGP_TriggeredObjective::Trigger Setting StoredInstigator=" + Instigator);
		StoredInstigator=_Instigator;
		//Other.EnterTrigger(this);
		//GotoState('Counting');
	}
}


void AAGP_TriggeredObjective::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAGP_TriggeredObjective::BeginPlay()
{
	Super::BeginPlay();
	
	if (Capsule)
	{
		Capsule->OnComponentBeginOverlap.RemoveDynamic(this, &AAGP_TriggeredObjective::OnOverlapBegin);
		Capsule->OnComponentEndOverlap.RemoveDynamic(this, &AAGP_TriggeredObjective::OnOverlapEnd);
		Capsule->OnComponentBeginOverlap.AddDynamic(this, &AAGP_TriggeredObjective::OnOverlapBegin);
		Capsule->OnComponentEndOverlap.AddDynamic(this, &AAGP_TriggeredObjective::OnOverlapEnd);
	}
	
	//this->OnActorBeginOverlap.AddDynamic(this, &AAGP_TriggeredObjective::OnOverlap);
}

void AAGP_TriggeredObjective::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Begin Overlap"));
	
}

void AAGP_TriggeredObjective::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("End Overlap"));
}
