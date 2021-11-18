// All the original content belonged to the US Army


#include "xEmitter.h"
#include "Components/BillboardComponent.h"

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

// Called when the game starts or when spawned
void AxEmitter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
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
			bSuspendWhenNotVisible=False;
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
	/*
		Return FMin(InPart,mStartParticles);
	*/
}
void AxEmitter::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
		mRegenPause=! mRegenPause;
	*/
}
void AxEmitter::UpdatePrecacheMaterials()
{
	/*
		if (mPosColorMapXY != None)
		{
			Level.AddPrecacheMaterial(mPosColorMapXY);
		}
		if (mPosColorMapXZ != None)
		{
			Level.AddPrecacheMaterial(mPosColorMapXZ);
		}
		if (mLifeColorMap != None)
		{
			Level.AddPrecacheMaterial(mLifeColorMap);
		}
		UpdatePrecacheMaterials();
	*/
}
/*
void AxEmitter::PrecacheContent (LevelInfo Level)
{
	if (Default.mPosColorMapXY != None)
	{
		Level.AddPrecacheMaterial(Default.mPosColorMapXY);
	}
	if (Default.mPosColorMapXZ != None)
	{
		Level.AddPrecacheMaterial(Default.mPosColorMapXZ);
	}
	if (Default.mLifeColorMap != None)
	{
		Level.AddPrecacheMaterial(Default.mLifeColorMap);
	}
	if (Default.Skins.Length > 0)
	{
		Level.AddPrecacheMaterial(Default.Skins[0]);
	}
}
*/
