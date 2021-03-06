// All the original content belonged to the US Army

#include "AA29/Object/Actor/AGP_ItemList/AGP_ItemList.h"
#include "Components/BillboardComponent.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"

void AAGP_ItemList::LoadEditorIcon()
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
AAGP_ItemList::AAGP_ItemList()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Actor.S_Actor'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
	//bHidden = true;
}


void AAGP_ItemList::BeginPlay()
{
	Super::BeginPlay();
}


void AAGP_ItemList::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAGP_ItemList::PreBeginPlay()
{
	int32 Position = 0;
	int32 quantity = 0;
	int32 Size = 0;
	int32 i = 0;
	Position = 0;
	quantity = 0;
	/*
	if (Position < 6)
	{
		quantity = GetItemQuantity(Position);
		for (i = 0; i < quantity; i++)
		{
			Size = ItemArray.Num();
			ItemArray[Size] = Position;
		}
		Position++;
	}
	*/
}

int32 AAGP_ItemList::GetNumItems()
{
	//return ItemArray.Num();
	return 0;    //FAKE   /ELiZ
}

AInventory* AAGP_ItemList::GetItem(int32 Index)
{
	AInventory* Item = nullptr;
	Item = MakeItem(GetItemString(ItemArray[Index]));
	return Item;
}

FString AAGP_ItemList::GetItemString(int32 Index)
{
	FString ItemName = "";
	/*
	switch (Index)
	{
	case 0:
		ItemName = "AGP_Inventory.M16A2";
		break;
	case 1:
		ItemName = "AGP_Inventory.M249";
		break;
	case 2:
		ItemName = "AGP_Inventory.Ammo_556mm_30_Mag";
		break;
	case 3:
		ItemName = "AGP_Inventory.Ammo_556mm_200_Drum";
		break;
	case 4:
		ItemName = "AGP_Inventory.Ammo_556mm_20_Mag";
		break;
	case 5:
		ItemName = "AGP_Inventory.M16A2Trainer";
		break;
	default:
		ItemName = "";
	}
	*/
	return ItemName;
}

int32 AAGP_ItemList::GetItemQuantity(int32 Index)
{
	int32 quantity = 0;
	/*
	switch (Index)
	{
	case 0:
		quantity = weap_M16A2_Qty;
		break;
	case 1:
		quantity = weap_M249_Qty;
		break;
	case 2:
		quantity = ammo_556_30_Qty;
		break;
	case 3:
		quantity = ammo_556_200_Qty;
		break;
	case 4:
		quantity = ammo_556_20_Qty;
		break;
	case 5:
		quantity = weap_M16A2Trainer_Qty;
		break;
	default:
		quantity = 0;
	}
	*/
	return quantity;
}

AInventory* AAGP_ItemList::MakeItem(FString ClassName)
{
	AInventory* Item = nullptr;
	AInventory* itemclass = nullptr;
	/*
	if (ClassName == "")
	{
		Item = nullptr;
	}
	else
	{
		itemclass = class<Inventory>(DynamicLoadObject(ClassName, Class'Class'));
		Item = Spawn(itemclass);
	}
	*/
	return Item;
}
