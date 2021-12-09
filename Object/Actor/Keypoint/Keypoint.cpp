// All the original content belonged to the US Army


#include "Keypoint.h"
#include "Components/BillboardComponent.h"
#include "Components/SceneComponent.h"


void AKeypoint::LoadEditorIcon()
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
		SpriteComponent->SetWorldScale3D(FVector(2, 2, 2));
		SpriteComponent->AttachToComponent(KeyPointRoot, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
	}
#endif // WITH_EDITORONLY_DATA
}


// Sets default values
AKeypoint::AKeypoint(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//bStatic = true;
	//bHidden = true;
	//SoundVolume = 0;
	//CollisionRadius = 10;
	//CollisionHeight = 10;
	KeyPointRoot = CreateDefaultSubobject<USceneComponent>(TEXT("KeyPointRoot"));
	RootComponent = KeyPointRoot;

	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Keypoint.S_Keypoint'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}

// Called when the game starts or when spawned
void AKeypoint::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AKeypoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AKeypoint::SetTarget(UScriptObject* Target)
{
	//_Target = Target;
}
