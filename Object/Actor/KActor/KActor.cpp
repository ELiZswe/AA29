// All the original content belonged to the US Army

#include "AA29/Object/Actor/KActor/KActor.h"
#include "Components/BillboardComponent.h"

void AKActor::LoadEditorIcon()
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

void AKActor::LoadMesh()
{
	UMaterialInstance* Mat;

	if (!StaticMesh)
	{
		StaticMesh->SetStaticMesh(LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/Misc/fx_misc_sheet.fx_misc_sheet'"), NULL, LOAD_None, NULL));
	}
	if (OverrideMaterials.Num() > 0)
	{
		for (int32 i = 0; i < OverrideMaterials.Num(); i++)
		{
			Mat = OverrideMaterials[i];
			StaticMesh->SetMaterial(i, Mat);
		}
	}
}

// Sets default values
AKActor::AKActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bKTakeShot = true;
	//DrawType = 8;
	//bNoDelete = true;
	//Physics = 13;
	//RemoteRole = 0;
	//CollisionRadius = 1;
	//CollisionHeight = 1;
	//bCollideActors = true;
	//bBlockActors = true;
	//bProjTarget = true;
	//bBlockKarma = true;
	//bEdShouldSnap = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform);
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Actor.S_Actor'"), NULL, LOAD_None, NULL);

	LoadEditorIcon();
	LoadMesh();
}


void AKActor::BeginPlay()
{
	Super::BeginPlay();
	
}


void AKActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/*
void AKActor::TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType  DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial)
{
	FVector ApplyImpulse = FVector(0,0,0);
	if (bKTakeShot && DamageType.Default.KDamageImpulse > 0)
	{
		if (VSize(Momentum) < 0.001)
		{
			return;
		}
		ApplyImpulse = Normal(Momentum) * DamageType.Default.KDamageImpulse;
		KAddImpulse(ApplyImpulse, HitLocation);
	}
}
*/

void AKActor::Trigger(AActor* Other, APawn* EventInstigator)
{
	//KWake();
}

void AKActor::KImpact(AActor* Other, FVector pos, FVector impactVel, FVector impactNorm)
{
	int32 numSounds = 0;
	int32 SoundNum = 0;
	/*
	if (GetWorld()->GetTimeSeconds() > LastImpactTime + ImpactInterval)
	{
		numSounds = ImpactSounds.Num();
		if (numSounds > 0)
		{
			SoundNum = Rand(numSounds);
			PlaySound(ImpactSounds[SoundNum], 4, ImpactVolume);
		}
		if (ImpactEffect != nullptr && EffectIsRelevant(pos, false))
		{
			if (bOrientImpactEffect)
			{
				Spawn(ImpactEffect, this, , pos, impactVel);
			}
			else
			{
				Spawn(ImpactEffect, this, , pos);
			}
		}
		LastImpactTime = GetWorld()->GetTimeSeconds();
	}
	*/
}
