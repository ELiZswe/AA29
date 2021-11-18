// All the original content belonged to the US Army


#include "AA29/AGP_Location/AGP_Location.h"
#include "Components/BillboardComponent.h"

// Sets default values
AAGP_Location::AAGP_Location()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//bHidden = true;
	//Texture = Texture'T_AA2_Editor.Engine.AGP_Location';
	//bDirectional = true;


#if WITH_EDITORONLY_DATA
	LRoot = CreateDefaultSubobject<USceneComponent>(TEXT("LRoot"));
	RootComponent = LRoot;

	SpriteComponent = CreateDefaultSubobject<UBillboardComponent>(TEXT("Sprite"));
	SpriteComponent->Sprite = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/Engine/AGP_Location.AGP_Location'"), NULL, LOAD_None, NULL);

	SpriteComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
	SpriteComponent->SetRelativeScale3D(FVector(2, 2, 2));
	SpriteComponent->SetRelativeLocation(FVector(0, 0, 150));
#endif // WITH_EDITORONLY_DATA	

}

// Called when the game starts or when spawned
void AAGP_Location::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAGP_Location::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Start(AActor* Actor)
{
	/*
	local Pawn p;
	if (Level.debugScreenplay)
	{
		Log("AGP_Location::Start() " $ Actor);
	}
	if (Actor != None)
	{
		if (Actor.IsA('Controller'))
		{
			Actor.SetLocation(Location);
			Actor.SetRotation(Rotation);
			Controller(Actor).ClientSetLocation(Location, Rotation);
			p = Controller(Actor).Pawn;
			Switch(Posture)
			{
					case 1:
						p.ShouldStand();
						break;
					case 2:
						p.ShouldCrouch(True);
						break;
					case 3:
						p.ShouldProne(True);
						break;
					default:
			}
			p.SetWalking(bIsWalking);
		}
		else
		{
			if (Actor.IsA('Pawn'))
			{
				Actor.SetLocation(Location);
				Actor.SetRotation(Rotation);
				p = Pawn(Actor);
				p.ClientSetLocation(Location, Rotation);
				Switch(Posture)
				{
					case 1:
						p.ShouldStand();
						break;
					case 2:
						p.ShouldCrouch(True);
						break;
					case 3:
						p.ShouldProne(True);
						break;
					default:
				}
				p.SetWalking(bIsWalking);
			}
			else
			{
				Actor.SetLocation(Location);
				Actor.SetRotation(Rotation);
			}
		}
	}
	*/
}
