// All the original content belonged to the US Army

#include "AA29/Object/Actor/xProcMesh/xProcMesh.h"
#include "Components/BillboardComponent.h"
#include "Components/SceneComponent.h"

void AxProcMesh::LoadMesh()
{
	UMaterialInstance* Mat;

	if (!StaticMesh)
	{
		StaticMesh->SetStaticMesh(LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/Misc/fx_misc_sheet.fx_misc_sheet'"), NULL, LOAD_None, NULL));
	}
	if (OverrideMaterials.Num() > 0)
	{
		for (int i = 0; i < OverrideMaterials.Num(); i++)
		{
			Mat = OverrideMaterials[i];
			StaticMesh->SetMaterial(i, Mat);
		}
	}
}

void AxProcMesh::LoadEditorIcon()
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
		SpriteComponent->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
	}
#endif // WITH_EDITORONLY_DATA
}


// Sets default values
AxProcMesh::AxProcMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Dampening = 0.5;
	DampeningRange = { -4, 4 };
	MovementClamp = { -50,50 };
	ForceClamp = { -20,20 };
	ForceAttenuation = 1;
	Tension = 0.4;
	RestTension = 0.4;
	CheckCollision = true;
	Noise = 0.1;
	NoiseForce = { -1 ,1 };
	NoiseTimer = { 2 ,3 };
	//DrawType = 10;
	//bLightingVisibility = false;
	//bNoDelete = true;
	//CollisionRadius = 80;
	//CollisionHeight = 80;
	//bCollideActors = true;
	//bProjTarget = true;
	//bUseCylinderCollision = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform);


	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Emitter.S_Emitter'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}

// Called when the game starts or when spawned
void AxProcMesh::BeginPlay()
{
	Super::BeginPlay();
	LoadMesh();
}

// Called every frame
void AxProcMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

