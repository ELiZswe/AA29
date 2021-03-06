// All the original content belonged to the US Army

#include "AA29/Object/Actor/xEmitter/xEmitter.h"
#include "Components/BillboardComponent.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"

void AxEmitter::LoadEditorIcon()
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
AxEmitter::AxEmitter()
{
	mMeshNodes.SetNum(8);
	mColorRange.SetNum(2);
	mSizeRange.SetNum(2);
	mSpinRange.SetNum(2);
	mMassRange.SetNum(2);
	mSpeedRange.SetNum(2);
	mRegenRange.SetNum(2);
	mLifeRange.SetNum(2);
	mDelayRange.SetNum(2);
	mRegenOffTime.SetNum(2);
	mRegenOnTime.SetNum(2);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mRegen = true;
	mStartParticles = 1;
	mMaxParticles = 50;
	mLifeRange = { 4,4 };
	mRegenRange = { 1, 1 };
	bSuspendWhenNotVisible = true;
	mSpawnVecB = FVector(0, 0, 5);
	mSpeedRange = { 40, 40 };
	mAirResistance = 0.4;
	mSizeRange = { 10, 10 };
	mColorRange = { FColor(255, 255, 255, 255), FColor(255, 255, 255, 255) };
	mAttenuate = true;
	mAttenKa = 0.2f;
	mAttenKb = 1.0f;
	mNumTileColumns = 1;
	mNumTileRows = 1;
	mColElasticity = 0.5;
	bCallPreSpawn = true;
	//LightEffect = 21;
	//DrawType = 10;
	//bAcceptsProjectors = false;
	bNetTemporary = true;
	//RemoteRole = 0;
	//Texture = Texture'Engine.S_Emitter';
	//Skins(0) = Texture'Engine.S_Emitter';
	//bUnlit = true;
	//bGameRelevant = true;
	//CollisionRadius = 0;
	//CollisionHeight = 0;
	//bNotOnDedServer = true;
	//bDirectional = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Emitter.S_Emitter'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}


void AxEmitter::BeginPlay()
{
	Super::BeginPlay();
	
}


void AxEmitter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AxEmitter::CollisionSound()
{
}
void AxEmitter::PreSpawned()
{
	/*
		if (! Level.bStartup)
		{
			bSuspendWhenNotVisible=false;
			if (Level.bDropDetail && mMaxParticles > 5 && mParticleType == 0 || mParticleType == 4 || mParticleType == 2)
			{
				mMaxParticles=mMaxParticles * 0.65;
				mRegenRange[0] *= 0.8;
				mRegenRange[1] *= 0.8;
				mStartParticles=0.65 * mStartParticles;
			}
		}
	*/
}

void AxEmitter::ClampToMaxParticles(float InPart)
{
	//return FMin(InPart,mStartParticles);
}
void AxEmitter::Trigger(AActor* Other, APawn* EventInstigator)
{
	//mRegenPause=! mRegenPause;
}
void AxEmitter::UpdatePrecacheMaterials()
{
	/*
		if (mPosColorMapXY != nullptr)
		{
			LeveL->AddPrecacheMaterial(mPosColorMapXY);
		}
		if (mPosColorMapXZ != nullptr)
		{
			LeveL->AddPrecacheMaterial(mPosColorMapXZ);
		}
		if (mLifeColorMap != nullptr)
		{
			LeveL->AddPrecacheMaterial(mLifeColorMap);
		}
		UpdatePrecacheMaterials();
	*/
}

void AxEmitter::PrecacheContent(ALevelInfo* Level)
{
	/*
	if (Default.mPosColorMapXY != nullptr)
	{
		LeveL->AddPrecacheMaterial(Default.mPosColorMapXY);
	}
	if (Default.mPosColorMapXZ != nullptr)
	{
		LeveL->AddPrecacheMaterial(Default.mPosColorMapXZ);
	}
	if (Default.mLifeColorMap != nullptr)
	{
		LeveL->AddPrecacheMaterial(Default.mLifeColorMap);
	}
	if (Default.Skins.Num() > 0)
	{
		LeveL->AddPrecacheMaterial(Default.Skins[0]);
	}
	*/
}
