// All the original content belonged to the US Army


#include "AA29/Object/Actor/xWeatherEffect/xWeatherEffect.h"


void AxWeatherEffect::LoadEditorIcon()
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
AxWeatherEffect::AxWeatherEffect()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WeatherType = EWeatherType::WT_Snow;
	numParticles = 1024;
	deviation = 0.4;
	maxPclEyeDist = 590;
	numCols = 4;
	numRows = 4;
	spawnVel = FVector(0, 0, -1);
	Position.X = { -300.000000, 300.000000 };
	Position.Y = { -300.000000, 300.000000};
	Position.Z = {-100.000000, 300.000000};
	Speed = { 100.0f, 200.0f };
	Life = { 3.0f, 4.0f };
	Size = { 4.0f, 5.0f };
	//DrawType = 10;
	//bNoDelete = true;
	//RemoteRole = 2;
	//DrawScale = 4;
	//Style = 3;
	//bUnlit = true;
	//bGameRelevant = true;


	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Actor.S_Actor'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();

}

// Called when the game starts or when spawned
void AxWeatherEffect::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AxWeatherEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

