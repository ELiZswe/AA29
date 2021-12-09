// All the original content belonged to the US Army


#include "AA29/Object/Actor/AGP_Trigger/AGP_Trigger.h"


void AAGP_Trigger::LoadEditorIcon()
{

#if WITH_EDITORONLY_DATA
	bool UBillboardComponentExists = false;

	TArray<UObject*> ObjectArray;
	GetDefaultSubobjects(ObjectArray);
	for (UObject* ThisObject : ObjectArray)
	{
		if (ThisObject->GetName() == "Sprite")
		{
			if (Texture != NULL)
			{
				SpriteComponent = Cast<UBillboardComponent>(ThisObject);
				SpriteComponent->Sprite = Texture;
				UBillboardComponentExists = true;
			}
		}
	}
	if (!UBillboardComponentExists)
	{
		SpriteComponent = CreateDefaultSubobject<UBillboardComponent>(TEXT("Sprite"));
		SpriteComponent->Sprite = Texture;
		SpriteComponent->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
		SpriteComponent->SetWorldScale3D(FVector(4, 4, 4));
	}
#endif // WITH_EDITORONLY_DATA
}



// Sets default values
AAGP_Trigger::AAGP_Trigger()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->InitCapsuleSize(100.0f, 200.0f);
	Capsule->SetCollisionEnabled(ECollisionEnabled::QueryOnly); // We want overlaps.
	Capsule->SetupAttachment(Root);


	//bActive = true;
	//bHidden = true;
	//CollisionRadius = 40;
	//CollisionHeight = 40;
	//bCollideActors = true;

	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/Engine/AGP_Trigger.AGP_Trigger'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}

// Called when the game starts or when spawned
void AAGP_Trigger::BeginPlay()
{
	Super::BeginPlay();
	if (Capsule)
	{
		Capsule->OnComponentBeginOverlap.AddDynamic(this, &AAGP_Trigger::BeginOverlap);
		Capsule->OnComponentEndOverlap.AddDynamic(this, &AAGP_Trigger::OnOverlapEnd);
	}
	

}

// Called every frame
void AAGP_Trigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AAGP_Trigger::SetActive(bool Active)
{
	bActive = Active;
}
void AAGP_Trigger::Touch(AActor* Other)
{
	if (bActive)
	{
	/*
		Other.EnterTrigger(Self);
		if (EventLab != None)
		{
			if (AGP_Pawn(Other) != None)
			{
				if (AGP_Pawn(Other).Controller.IsA('HumanController'))
				{
					EventLab.ActorNotify(Self, 4, Pawn(Other));
				}
			}
		}
	*/
	}
}
void AAGP_Trigger::UnTouch(AActor* Other)
{
	/*
	Other.ExitTrigger(Self);
	if (bActive)
	{
		if (EventLab != None)
		{
			if (AGP_Pawn(Other) != None)
			{
				if (AGP_Pawn(Other).Controller.IsA('HumanController'))
				{
					EventLab.ActorNotify(Self, 5, Pawn(Other));
				}
			}
		}
	}
	*/
}
void AAGP_Trigger::Trigger(AActor* Other, APawn* EventInstigator)
{
	if (bActive)
	{
	/*
		ScreenPrint("Other" @ Other @ "Inst" @ EventInstigator);
		EventInstigator.EnterTrigger(Self);
	*/
	}
}
void AAGP_Trigger::UnTrigger(AActor* Other, APawn* EventInstigator)
{
	/*
	EventInstigator.ExitTrigger(Self);
	*/
}


void AAGP_Trigger::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
		bActive = !bActive;
	// Overlap
}



void AAGP_Trigger::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	bActive = !bActive;
}