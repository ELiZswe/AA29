// All the original content belonged to the US Army


#include "AA29/Object/Actor/AGP_UseTrigger/AGP_UseTrigger.h"

void AAGP_UseTrigger::LoadMesh()
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


void AAGP_UseTrigger::LoadEditorIcon()
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
AAGP_UseTrigger::AAGP_UseTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bActive = true;
	//StaticMesh = StaticMesh'M_AA2_FX.misc.fx_misc_sheet';
	//bHidden = true;
	//bWorldGeometry = true;
	
	//CollisionRadius = 16;
	//CollisionHeight = 16;
	//bCollideActors = true;
	//bBlockNonZeroExtentTraces = false;
	//bUseCylinderCollision = true;
	//bBlockBulletTraces = false;
	//bBlockCoronaTraces = false;
	//bEdShouldSnap = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->InitCapsuleSize(100.0f, 200.0f);
	Capsule->SetCollisionEnabled(ECollisionEnabled::QueryOnly); // We want overlaps.
	Capsule->SetupAttachment(Root);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform);
	
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_AA2_UseTrigger.S_AA2_UseTrigger'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();	
	LoadMesh();
}

// Called when the game starts or when spawned
void AAGP_UseTrigger::BeginPlay()
{
	Super::BeginPlay();
	LoadMesh();
}

// Called every frame
void AAGP_UseTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

