// All the original content belonged to the US Army


#include "Triggers.h"


// Sets default values
ATriggers::ATriggers()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->InitCapsuleSize(100.0f, 200.0f);
	Capsule->SetCollisionEnabled(ECollisionEnabled::QueryOnly); // We want overlaps.
	Capsule->SetupAttachment(RootComponent);

#if WITH_EDITORONLY_DATA
	SpriteComponent = CreateDefaultSubobject<UBillboardComponent>(TEXT("Sprite"));
	SpriteComponent->Sprite = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Trigger.S_Trigger'"), NULL, LOAD_None, NULL);
	SpriteComponent->AttachToComponent(Capsule, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);


#endif // WITH_EDITORONLY_DATA



	//bHidden = true;
	//RemoteRole = 0;
	//CollisionRadius = 40;
	//CollisionHeight = 40;
	//bCollideActors = true;
}

// Called when the game starts or when spawned
void ATriggers::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATriggers::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

