// All the original content belonged to the US Army

#include "AA29/Object/Actor/AGP_LocationList/AGP_LocationList.h"
#include "Components/BillboardComponent.h"
#include "AA29/Object/Actor/AGP_Location/AGP_Location.h"

void AAGP_LocationList::LoadEditorIcon()
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
AAGP_LocationList::AAGP_LocationList()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//bHidden = true;
	
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Actor.S_Actor'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}


void AAGP_LocationList::BeginPlay()
{
	Super::BeginPlay();
	
}


void AAGP_LocationList::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAGP_LocationList::PreBeginPlay()
{
	int32 Size = 0;
	int32 size2 = 0;
	int32 cur = 0;
	AAGP_Location* loc = nullptr;
	/*
	Size = Locations.Num();
	for (cur = 0; cur < Size; cur++)
	{
		loc = GetLocationByTag(Locations[cur]);
		if (loc != nullptr)
		{
			size2 = LocationList.Num();
			LocationList[size2] = loc;
		}
	}
	*/
}

AAGP_Location* AAGP_LocationList::GetRandomLocation()
{
	int32 Size = 0;
	/*
	Size = LocationList.Num();
	if (Size > 0)
	{
		Size--;
		return LocationList[Rand(Size)];
	}
	*/
	return nullptr;
}

AAGP_Location* AAGP_LocationList::GetLocationByTag(FName Tag)
{
	AAGP_Location* A = nullptr;
	/*
	if (Tag != "None")
	{
		ForEach AllActors(AAGP_Location::StaticClass(), A, Tag)
		{
			if (Tag == A.Tag)
			{
				return A;
			}
		}
	}
	*/
	A = nullptr;
	return A;
}
