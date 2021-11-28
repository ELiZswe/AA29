// All the original content belonged to the US Army


#include "AGP_PlayerStart.h"
#include "EngineGlobals.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/BillboardComponent.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

/*
void AAGP_PlayerStart::SetClass()
{
	UWorld* World = GetWorld();
	APlayerController* PController =			GetWorld()->GetFirstPlayerController();

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("This is an on screen message!, Player%dStart"), 1));
}
*/

void AAGP_PlayerStart::LoadEditorIcon() 
{
#if WITH_EDITORONLY_DATA
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
			}
		}
	}
#endif // WITH_EDITORONLY_DATA
}

AAGP_PlayerStart::AAGP_PlayerStart(const FObjectInitializer& ObjectInitializer)	: Super(ObjectInitializer)
{
	RemoveClassInventory.SetNum(16);
	AddedInventory.SetNum(16);
	Removed.SetNum(16);
	LoadEditorIcon();
	
}


void AAGP_PlayerStart::PostBeginPlay()
{
	int32 i;
	FString Equip;
	//AInventory* Inv;
	for (i = 0; i < 32; i++)
	{
		/*
		Equip = SpawnClass.Default.ClassEquipment[i];
		//Equip = GetDefault<ASoldierClass>()->ClassEquipment[i];
		if (Equip == "")
		{
		}
		Inv = class<Inventory>(DynamicLoadObject(Equip, Class'Class'));
		if (Inv.Default.PickupClass != NULL)
		{
			//Inv.Default.PickupClass.StaticPrecache(Level);
		}
		*/
	}
	//PostBeginPlay();
}


void AAGP_PlayerStart::BeginPlay()
{
	Super::BeginPlay();
	uint8 i;
	for (i = 0; i < 16; i++)
	{
		if (RemoveClassInventory[i] != NULL)
		{
			RemoveNum = i + 1;
		}
	}
	PostBeginPlay();
}

bool AAGP_PlayerStart::ShouldSetInitialParaState()
{
	return (InitialParaState != EInitialParaState::PARA_Default);
}

uint8 AAGP_PlayerStart::GetInitialParaState()
{
	
	switch (InitialParaState)
	{
	case EInitialParaState::PARA_Deploy:		return PARACHUTE_ATTACH_DEPLOY;
	case EInitialParaState::PARA_Idle:			return PARACHUTE_ATTACH_IDLE;
	case EInitialParaState::PARA_Collapse:		return PARACHUTE_ATTACH_COLLAPSE;
	case EInitialParaState::PARA_Ground:		return PARACHUTE_ATTACH_GROUND;
	case EInitialParaState::PARA_Flare:			return PARACHUTE_ATTACH_FLARE;
	case EInitialParaState::PARA_Premature:		return PARACHUTE_ATTACH_PREMATURE;
	case EInitialParaState::PARA_Rig:			return PARACHUTE_ATTACH_RIG;
	default:
		return 0;
	}
}
/* =================================================================================== *
 * AGP function SkipInventory()
 *	Check and see if we should skip an inventory item.
 *
 * input:	AddName - the name of an inventory item
 * output:	bool	- true - skip it
 *					  false - don't skip it
 * effects:
 * notes:
 * last modified by: cmb
 * =================================================================================== */

bool AAGP_PlayerStart::SkipInventory(FString AddName)
{
	uint8 i;
	TSubclassOf<AInventory> AddClass;
	if (AddName == "" || AddName == "None")
	{
		return true;
	}
	if (RemoveNum <= 0)
	{
		return false;
	}
	//AddClass = class<Inventory>(DynamicLoadObject(AddName, Class'Class'));

	if (AddClass == NULL)
	{
		return true;
	}
	for (i = 0; i < RemoveNum; i++)
	{
		if (Removed[i] == 0 && RemoveClassInventory[i] == AddClass)
		{
			Removed[i] = 1;
			return true;
		}
	}
	return false;
}





TSubclassOf <class ASoldierClass> AAGP_PlayerStart::GetSpawnClass()
{
	return SpawnClass;
}

int32 AAGP_PlayerStart::GetInitialHealth()
{
	return nInitialHealth;
}

float AAGP_PlayerStart::GetScore()
{
	return fBaseScore;
}

bool AAGP_PlayerStart::CanSpawn()
{
	return bEnabled && MaxSpawns > _NumSpawned;
}

int32 AAGP_PlayerStart::NumSpawnsRemaining()
{
	return MaxSpawns - _NumSpawned;
}

int32 AAGP_PlayerStart::NumSpawnsUsed()
{
	return _NumSpawned;
}

uint8 AAGP_PlayerStart::GetTeamID()
{
	return TeamNumber;
}

bool AAGP_PlayerStart::IsEnabled()
{	
	return bEnabled;
}

void AAGP_PlayerStart::UsePlayerStart()
{
	_NumSpawned++;
}

uint8 AAGP_PlayerStart::getFT()
{
	return uint8(0);
}

FString AAGP_PlayerStart::toString()
{
	FString retval = "";
	//retval = retval $ "AGP_PlayerStart "$self$"\n";
	//retval = retval $ "spawnclass = "$SpawnClass$"\n";
	//retval = retval $ "bEnabled = "$bEnabled$"\n";
	//retval = retval $ "score = "$fBaseScore$"\n";
	//retval = retval $ "maxspawn = "$MaxSpawns$"\n";
	//retval = retval $ "timesused = "$_NumSpawned$"\n";
	//return retval;

	return "ToString";
}

void AAGP_PlayerStart::FindNewStartIndex(APSSet* UseSet)
{
}

FVector AAGP_PlayerStart::GetStartLocation()
{
	return FVector(1, 2, 3);
}

FRotator AAGP_PlayerStart::GetStartRotation()
{
	return FRotator(10, 20, 30);
}

