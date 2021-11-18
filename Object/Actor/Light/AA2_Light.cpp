// All the original content belonged to the US Army


#include "AA29/Object/Actor/Light/AA2_Light.h"
#include "Components/BillboardComponent.h"

void AAA2_Light::LoadEditorIcon()
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


AAA2_Light::AAA2_Light()
{
	MaxCoronaSize = 1000;
	//LightType = 1;
	//LightSaturation = 255;
	//LightBrightness = 64;
	//LightRadius = 64;
	//LightPeriod = 32;
	//LightCone = 128;
	//bActorShadows = true;
	//bStatic = true;
	//bHidden = true;
	//bNoDelete = true;
	//Texture = Texture'Engine.S_Light';
	//bMovable = false;
	//CollisionRadius = 24;
	//CollisionHeight = 24;
	//bBlockCoronaTraces = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Light.S_Light'"), NULL, LOAD_None, NULL);


	LoadEditorIcon();

}