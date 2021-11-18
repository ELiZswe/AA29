// All the original content belonged to the US Army

#include "AGP_TriggeredObjective.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"


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
	/*
		if (p.IsA('NPC_doctor') && bMustBeNPC)
		{
			Return True;
		}
		if (! CanAccomplish(p))
		{
			Return False;
		}
		if (MustBeClass != None && ! AGP_Pawn(p).TeamClass.IsA(MustBeClass.Name))
		{
			Return False;
		}
		if (MustHaveInInventory != None && p.FindInventoryType(MustHaveInInventory) == None)
		{
			Return False;
		}
		if (MustBeHolding != None && p.Weapon != None && ! p.Weapon.IsA(MustBeHolding.Name))
		{
			Return False;
		}
		Return True;
	*/
	return true;   //FAKE /ELiZ
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
	/*
		local Actor TempActor;
		local Pawn Pawn;
		if (! IsEnabled())
		{
			Return;
		}
		if (GetNetMode() == ENetMode::NM_Standalone)
		{
			Pawn=Pawn(Other);
			if (Pawn != None && Pawn.Controller.IsA('StudentController'))
			{
				if (EventLab != None)
				{
					EventLab.ActorNotify(Self,4,Pawn,"");
				}
			}
		}
		if (Other.IsA('Pawn') && CanAccomplish(Pawn(Other)))
		{
			if (Other.IsA('NPC_doctor'))
			{
				TempActor=Other;
				Other=NPC_doctor(Other).LastUsedBy;
			}
			if (fTimeToTrigger <= 0)
			{
				AccomplishObjective(Pawn(Other));
			}
			else
			{
				StoredInstigator=Pawn(Other);
				Other.EnterTrigger(Self);
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
		//Log(Self @ "AGP_TriggeredObjective::Trigger Setting StoredInstigator=" $ Instigator);
		StoredInstigator=_Instigator;
		//Other.EnterTrigger(Self);
		//GotoState('Counting');
	}
}



// Called every frame
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
