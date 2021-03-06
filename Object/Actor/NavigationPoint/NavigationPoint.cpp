// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "Components/BillboardComponent.h"
#include "AA29/Object/Actor/DebugNavigation/DebugNavigation.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/ReachSpec/ReachSpec.h"

void ANavigationPoint::LoadEditorIcon()
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
ANavigationPoint::ANavigationPoint()
{
	BaseDist.SetNum(2);
	BaseVisible.SetNum(2);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bPropagatesSound = true;
	bMayCausePain = true;
	BaseDist = { 1000000, 1000000 };
	ScoutExtentMultiplier = 1;
	CrouchCost = 1000000;
	CrawlCost = 1000000;
	//bStatic = true;
	//bHidden = true;
	//bNoDelete = true;
	
	bCollideWhenPlacing = true;
	//SoundVolume = 0;
	//CollisionRadius = 40;
	//CollisionHeight = 50;
	//bDirectional = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_NavP.S_NavP'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}


void ANavigationPoint::BeginPlay()
{
	Super::BeginPlay();
	
}


void ANavigationPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANavigationPoint::PostBeginPlay()
{
	/*
		FVector HitLocation;
		FVector HitNormal;
		FVector End;
		int32 i = 0;
		ExtraCost=Max(ExtraCost,0);
		for (i=0; i<PathList.Num(); i++)
		{
			MaxPathSize.X=FMax(MaxPathSize.X,PathList[i].CollisionRadius);
			MaxPathSize.Z=FMax(MaxPathSize.Z,PathList[i].CollisionHeight);
		}
		MaxPathSize.Y=MaxPathSize.X;
		PostBeginPlay();
		End=Location;
		End.Z -= 1024;
		Trace(HitLocation,HitNormal,End,Location,true);
		vFloor=HitLocation;
		vFloor.Z += 16;
		if (bCrouchOnly || bCrawlOnly)
		{
			bQuerySpecialCost=true;
		}
	*/
}
/*
int32 ANavigationPoint::SpecialCost(APawn* Seeker, UReachSpec* Path)
{
		if (bCrouchOnly && ! Seeker.bIsCrouched)
		{
			return CrouchCost;
		}
		else
		{
			if (bCrawlOnly && ! Seeker.bIsProne)
			{
				return CrawlCost;
			}
			else
			{
				return 0;
			}
		}
}
*/

void ANavigationPoint::SetBaseDistance(int32 BaseNum)
{
}
void ANavigationPoint::SetBaseVisibility(int32 BaseNum)
{
	ANavigationPoint* N = nullptr;
	BaseVisible[BaseNum]=1;
	/*
	for (N=Level.NavigationPointList; N!=nullptr; N=N->nextNavigationPoint)
	{
		if ((N.BaseVisible[BaseNum] == 0) && FastTrace((N.Location + ((float(88) - (2 * N.CollisionHeight)) * FVector(0,0,1))),(Location + ((float(88) - (2 * N.CollisionHeight)) * FVector(0,0,1)))))
		{
			N.BaseVisible[BaseNum]=1;
		}
	}
	*/
}
bool ANavigationPoint::Accept(AActor* Incoming, AActor* Source)
{
	/*
		taken=Incoming.SetLocation(Location);
		if (taken)
		{
			Incoming.Velocity=FVector(0,0,0);
			Incoming.SetRotation(Rotation);
		}
		Incoming.PlayTeleportEffect(true,false);
		TriggerEvent(Event,Self,Pawn(Incoming));
		return taken;
	*/
	return false;   //FALSE  //ELiZ
}
float ANavigationPoint::DetourWeight(APawn* Other, float PathWeight)
{
	return 0;    //FAKE //ELiZ
}
bool ANavigationPoint::SuggestMovePreparation(APawn* Other)
{
	return false;
}
bool ANavigationPoint::ProceedWithMove(APawn* Other)
{
	return true;
}
void ANavigationPoint::MoverOpened()
{
}
void ANavigationPoint::MoverClosed()
{
}
void ANavigationPoint::PlayerToucherDied(APawn* p)
{
}
FVector ANavigationPoint::GetStartLocation()
{
	return GetActorLocation();
}
FRotator ANavigationPoint::GetStartRotation()
{
	return GetActorRotation();
}
void ANavigationPoint::DebugNavMarker(bool bShowMarker, bool bFinalGoalMarker)
{
	/*
		if (dnpcnDebugNavigationMarker == nullptr)
		{
			if (! bShowMarker)
			{
				return;
			}
			dnpcnDebugNavigationMarker=Spawn('DebugNavigation');
			dnpcnDebugNavigationMarker->HUDText=Self + "." + Tag;
			dnpcnDebugNavigationMarker->SetOwner(this);
			dnpcnDebugNavigationMarker->Skins[0]=Texture;
		}
		if (dnpcnDebugNavigationMarker != nullptr)
		{
			dnpcnDebugNavigationMarker->SetLocation(Location);
			dnpcnDebugNavigationMarker->bHidden=! bShowMarker;
			if (bShowMarker)
			{
				if (bFinalGoalMarker)
				{
					dnpcnDebugNavigationMarker->SetDrawScale3D(FVector(0.15 0.15 0.15));
					dnpcnDebugNavigationMarker->RotationRate.Yaw=16384;
				}
				else
				{
					dnpcnDebugNavigationMarker->SetDrawScale3D(FVector(0.075 0.075 0.075));
					dnpcnDebugNavigationMarker->RotationRate.Yaw=4096;
				}
			}
		}
	*/
}
AActor* ANavigationPoint::SpecialHandling(APawn* Other)
{
	return nullptr;
}

