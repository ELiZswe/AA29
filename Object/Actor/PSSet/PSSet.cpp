// All the original content belonged to the US Army


#include "PSSet.h"

// Sets default values
APSSet::APSSet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Actor.S_Actor'"), NULL, LOAD_None, NULL);

	LoadEditorIcon();
	//this->SetActorScale3D(FVector(2, 2, 2));
}

// Called when the game starts or when spawned
void APSSet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APSSet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




void APSSet::LoadEditorIcon()
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
	}
#endif // WITH_EDITORONLY_DATA
}