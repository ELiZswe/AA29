// All the original content belonged to the US Army

#include "AA29/Object/Actor/AAGameplay/AAGameplay.h"
#include "Components/BillboardComponent.h"

void AAAGameplay::LoadMesh()
{
	//UMaterialInstance* Mat;

	if (!StaticMesh)
	{
		StaticMesh->SetStaticMesh(LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/Misc/fx_misc_sheet.fx_misc_sheet'"), NULL, LOAD_None, NULL));
	}
	/*
	if (OverrideMaterials.Num() > 0)
	{
		for (int32 i = 0; i < OverrideMaterials.Num(); i++)
		{
			Mat = OverrideMaterials[i];
			StaticMesh->SetMaterial(i, Mat);
		}
	}
	*/
}

void AAAGameplay::LoadEditorIcon()
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
AAAGameplay::AAAGameplay()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//DrawType = 2;
	//bUseDynamicLights = true;
	//bShadowCast = true;
	//CollisionHeight = 49;
	//bCollideActors = true;
	//bCollideWorld = true;
	//bBlockActors = true;
	//bBlockPlayers = true;
	//bProjTarget = true;
	//bUseCylinderCollision = true;
	//bDirectional = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	if (StaticMesh)
	{
		StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	}

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	if (SkeletalMesh)
	{
		SkeletalMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	}

	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Actor.S_Actor'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}


void AAAGameplay::BeginPlay()
{
	Super::BeginPlay();
	
}


void AAAGameplay::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAAGameplay::PostBeginPlay()
{
	//Super::PostBeginPlay();
	SetAttachments();
}
void AAAGameplay::SetAttachments()
{
	int32 i = 0;
	AActor* Item = nullptr;
	/*
	for (i=0; i<Attachments.Num(); i++)
	{
		Item=Spawn(Attachments[i].Attachment);
		if (Item != nullptr)
		{
			AttachToBone(Item,Attachments[i].Bone);
		}
		else
		{
			Log("AAGameplay::SetAttachments(): ERROR: Couldn't Spawn Item: " + FString::FromInt(Attachments[i].Attachment) + " for actor: " + FString::FromInt(this));
		}
		else
		{
			Item.SetRelativeLocation(Attachments[i].LocationOffset);
			Item.SetRelativeRotation(Attachments[i].RotationOffset);
			if (Attachments[i].bUseParentScale)
			{
				Item.SetDrawScale(Self.DrawScale);
			}
			else
			{
				if (Attachments[i].Scale == 0)
				{
					Item.SetDrawScale(1);
				}
				else
				{
					Item.SetDrawScale(Attachments[i].Scale);
				}
			}
		}
	}
	for (i=0; i<TagAttachments.Num(); i++)
	{
		if (TagAttachments[i].ActorTag != "None")
		{
			Item=GetActorByTag(TagAttachments[i].ActorTag);
			if (Item != nullptr)
			{
				Item.SetBase(this);
			}
			else
			{
				Log("AAGameplay::SetAttachments(): ERROR: Couldn't find actor with tag: " + FString::FromInt(TagAttachments[i].ActorTag) + " for actor: " + FString::FromInt(this));
			}
			else
			{
			}
			else
			{
				Log("AAGameplay::SetAttachments(): ERROR: Name is None for actor: " + FString::FromInt(this));
			}
		}
	}
	*/
}
