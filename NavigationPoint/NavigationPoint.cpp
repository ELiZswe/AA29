// All the original content belonged to the US Army


#include "NavigationPoint.h"
#include "Components/BillboardComponent.h"

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

// Called when the game starts or when spawned
void ANavigationPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
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
		int32 i;
		ExtraCost=Max(ExtraCost,0);
		for (i=0; i<PathList.Length; i++)
		{
			MaxPathSize.X=FMax(MaxPathSize.X,PathList[i].CollisionRadius);
			MaxPathSize.Z=FMax(MaxPathSize.Z,PathList[i].CollisionHeight);
		}
		MaxPathSize.Y=MaxPathSize.X;
		PostBeginPlay();
		End=Location;
		End.Z -= 1024;
		Trace(HitLocation,HitNormal,End,Location,True);
		vFloor=HitLocation;
		vFloor.Z += 16;
		if (bCrouchOnly || bCrawlOnly)
		{
			bQuerySpecialCost=True;
		}
	*/
}
/*
int32 ANavigationPoint::SpecialCost(APawn* Seeker, AReachSpec* Path)
{
		if (bCrouchOnly && ! Seeker.bIsCrouched)
		{
			Return CrouchCost;
		}
		else
		{
			if (bCrawlOnly && ! Seeker.bIsProne)
			{
				Return CrawlCost;
			}
			else
			{
				Return 0;
			}
		}
}
*/

void ANavigationPoint::SetBaseDistance(int32 BaseNum)
{
}
void ANavigationPoint::SetBaseVisibility(int32 BaseNum)
{
	/*
		ANavigationPoint* N;
		BaseVisible[BaseNum]=1;
		N=Level.NavigationPointList;
		if (N != nullptr)
		{
			if (N->BaseVisible[BaseNum] == 0 && FastTrace(N->GetActorLocation + 88 - 2 * N->CollisionHeight * vect(0 0 1),Location + 88 - 2 * N->CollisionHeight * vect(0 0 1)))
			{
				N.BaseVisible[BaseNum]=1;
			}
			N=N->nextNavigationPoint;
		}
	*/
}
bool ANavigationPoint::Accept(AActor* Incoming, AActor* Source)
{
	/*
		taken=Incoming.SetLocation(Location);
		if (taken)
		{
			Incoming.Velocity=vect(0 0 0);
			Incoming.SetRotation(Rotation);
		}
		Incoming.PlayTeleportEffect(True,False);
		TriggerEvent(Event,Self,Pawn(Incoming));
		Return taken;
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
		if (dnpcnDebugNavigationMarker == None)
		{
			if (! bShowMarker)
			{
				Return;
			}
			dnpcnDebugNavigationMarker=Spawn('DebugNavigation');
			dnpcnDebugNavigationMarker.HUDText=Self $ "." $ Tag;
			dnpcnDebugNavigationMarker.SetOwner(Self);
			dnpcnDebugNavigationMarker.Skins[0]=Texture;
		}
		if (dnpcnDebugNavigationMarker != None)
		{
			dnpcnDebugNavigationMarker.SetLocation(Location);
			dnpcnDebugNavigationMarker.bHidden=! bShowMarker;
			if (bShowMarker)
			{
				if (bFinalGoalMarker)
				{
					dnpcnDebugNavigationMarker.SetDrawScale3D(vect(0.15 0.15 0.15));
					dnpcnDebugNavigationMarker.RotationRate.Yaw=16384;
				}
				else
				{
					dnpcnDebugNavigationMarker.SetDrawScale3D(vect(0.075 0.075 0.075));
					dnpcnDebugNavigationMarker.RotationRate.Yaw=4096;
				}
			}
		}
	*/
}
AActor* ANavigationPoint::SpecialHandling(APawn* Other)
{
	return nullptr;
}

