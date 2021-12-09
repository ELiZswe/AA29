// All the original content belonged to the US Army


#include "AA29/Object/Actor/SVehicleFactory/SVehicleFactory.h"
#include "Components/BillboardComponent.h"

void ASVehicleFactory::LoadEditorIcon()
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
ASVehicleFactory::ASVehicleFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MaxVehicleCount = 1;
	//bHidden = true;
	//bNoDelete = true;
	//RemoteRole = 0;
	//Texture = Texture'Engine.S_KVehFact';
	//bDirectional = true;


	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_KVehFact.S_KVehFact'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();

}

// Called when the game starts or when spawned
void ASVehicleFactory::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASVehicleFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

