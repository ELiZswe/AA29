// All the original content belonged to the US Army


#include "AGP_DeployChute.h"
#include "Components/BillboardComponent.h"
#include "Components/CapsuleComponent.h"

void AAGP_DeployChute::LoadEditorIcon()
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
AAGP_DeployChute::AAGP_DeployChute()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//bHidden = true;
	//CollisionRadius = 40;
	//CollisionHeight = 40;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->InitCapsuleSize(100.0f, 200.0f);
	Capsule->SetCollisionEnabled(ECollisionEnabled::QueryOnly); // We want overlaps.
	Capsule->SetupAttachment(Root);

	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Actor.S_Actor'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();

}

// Called when the game starts or when spawned
void AAGP_DeployChute::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAGP_DeployChute::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAGP_DeployChute::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	EventInstigator->UpdateParachute(1);
	*/
}