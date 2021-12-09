// All the original content belonged to the US Army


#include "AA29/Object/Actor/AGP_Sound/AGP_Sound.h"
#include "Components/BillboardComponent.h"

void AAGP_Sound::LoadEditorIcon()
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
AAGP_Sound::AAGP_Sound()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//bHidden = true;
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
	//bBlockBulletTraces = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/Engine/AGP_Sound.AGP_Sound'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}

// Called when the game starts or when spawned
void AAGP_Sound::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAGP_Sound::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AAGP_Sound::Start()
{
	_bValid = true;
	//_timer = GetSoundDuration(_Sound);
	if (_TargetPawn == nullptr)
	{
		//if (Level.debugScreenplay)
		//{
		//	Log("AGP_Sound::Start() " $ Tag $ " by " $ Self);
		//}
		//PlayOwnedSound(_Sound, SoundSlot, 1, , 100000, , false);
	}
	else
	{
		//if (Level.debugScreenplay)
		//{
		//	Log("AGP_Sound::Start() " $ Tag $ " by " $ _TargetPawn);
		//}
		//_TargetPawn->PlayOwnedSound(_Sound, SoundSlot, 1, , 100000, , false);
	}
	//SetTimer(_timer, false);
}
void AAGP_Sound::Finish()
{
	_bValid = false;
}
void AAGP_Sound::Timer()
{
	
	//if (_bValid && _Target != nullptr)
	//{
	//	_Target->Notify();
	//}
}
