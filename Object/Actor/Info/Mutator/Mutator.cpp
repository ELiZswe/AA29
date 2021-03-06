// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/Mutator/Mutator.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "AA29/Object/PlayInfo/PlayInfo.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"

AMutator::AMutator()
{
	IconMaterialName = "MutatorArt.nosym";
}

void AMutator::PreBeginPlay()
{
	/*
	if (!MutatorIsAllowed())
	{
		Destroy();
	}
	else
	{
		if (bAddToServerPackages)
		{
			AddToPackageMap();
		}
	}
	*/
}

bool AMutator::MutatorIsAllowed()
{
	//return ((!Level.IsDemoBuild()) || (Class == AMutator::StaticClass()));
	return false;    //FAKE   /ELiZ
}

void AMutator::Destroyed()
{
	AMutator* M = nullptr;
	/*
	if (Level.Game.BaseMutator == this)
	{
		Level.Game.BaseMutator = NextMutator;
	}
	else
	{
		M = Level.Game.BaseMutator;
		if (M != nullptr)
		{
			if (M.NextMutator == this)
			{
				M.NextMutator = NextMutator;
			}
			else
			{
				M = M.NextMutator;
			}
		}
	}
	Super::Destroyed();
	*/
}

void AMutator::Mutate(FString MutateString, APlayerController* Sender)
{
	/*
	if (NextMutator != nullptr)
	{
		NextMutator.Mutate(MutateString, Sender);
	}
	*/
}

void AMutator::ModifyLogin(FString& Portal, FString& Options)
{
	/*
	if (NextMutator != nullptr)
	{
		NextMutator.ModifyLogin(Portal, Options);
	}
	*/
}

void AMutator::NotifyLogout(AController* Exiting)
{
	/*
	if (NextMutator != nullptr)
	{
		NextMutator.NotifyLogout(Exiting);
	}
	*/
}

void AMutator::ModifyPlayer(APawn* Other)
{
	/*
	if (NextMutator != nullptr)
	{
		NextMutator.ModifyPlayer(Other);
	}
	*/
}

AWeapon* AMutator::GetDefaultWeapon()
{
	AWeapon* W = nullptr;
	/*
	if (NextMutator != nullptr)
	{
		W = NextMutator.GetDefaultWeapon();
		if (W == nullptr)
		{
			W = MyDefaultWeapon();
		}
	}
	else
	{
		W = MyDefaultWeapon();
	}
	*/
	return W;
}

AInventory* AMutator::GetInventoryClass(FString InventoryClassName)
{
	/*
	InventoryClassName = GetInventoryClassOverride(InventoryClassName);
	return class<Inventory>(DynamicLoadObject(InventoryClassName, Class'Class'));
	*/
	return nullptr;    //FAKE   ELiZ

}

FString AMutator::GetInventoryClassOverride(FString InventoryClassName)
{
	/*
	if (NextMutator != nullptr)
	{
		return NextMutator.GetInventoryClassOverride(InventoryClassName);
	}
	*/
	return InventoryClassName;
}

AWeapon* AMutator::MyDefaultWeapon()
{
	/*
	if ((DefaultWeapon == nullptr) && (DefaultWeaponName != ""))
	{
		DefaultWeapon = class<Weapon>(DynamicLoadObject(DefaultWeaponName, Class'Class'));
	}
	*/
	return DefaultWeapon;
}

void AMutator::AddMutator(AMutator* M)
{
	/*
	if (NextMutator == nullptr)
	{
		NextMutator = M;
	}
	else
	{
		NextMutator.AddMutator(M);
	}
	*/
}

FString AMutator::RecommendCombo(FString ComboName)
{
	return ComboName;
}

FString AMutator::NewRecommendCombo(FString ComboName, AaAIController* C)
{
	FString NewComboName = "";
	/*
	NewComboName = RecommendCombo(ComboName);
	if (NewComboName != ComboName)
	{
		return NewComboName;
	}
	if (NextMutator != nullptr)
	{
		return NextMutator.NewRecommendCombo(ComboName, C);
	}
	*/
	return ComboName;
}

bool AMutator::ReplaceWith(AActor* Other, FString aClassName)
{
	AActor* A = nullptr;
	AActor* aClass = nullptr;
	/*
	if (aClassName == "")
	{
		return true;
	}
	aClass = class<Actor>(DynamicLoadObject(aClassName, Class'Class'));
	if (aClass != nullptr)
	{
		A = Spawn(aClass, Other.Owner, Other.Tag, Other->GetActorLocation(), Other.Rotation);
	}
	if (Other->IsA(APickup::StaticClass()))
	{
		if (Cast<APickup>(Other).myMarker != nullptr)
		{
		 Cast<APickup>(Other).myMarker.markedItem = Cast<APickup>(A);
			if (Cast<APickup>(A) != nullptr)
			{
				Cast<APickup>(A).myMarker = Cast<APickup>(Other).myMarker;
				A.SetLocation((A.Location + ((A.CollisionHeight - Other.CollisionHeight) * FVector(0, 0, 1))));
			}
			Cast<APickup>(Other).myMarker = nullptr;
		}
		else
		{
			if (A->IsA(APickup::StaticClass()))
			{
				Cast<APickup>(A).RespawnTime = 0;
			}
		}
	}
	if (A != nullptr)
	{
		A.Event = Other.Event;
		A.Tag = Other.Tag;
		return true;
	}
	*/
	return false;
}

bool AMutator::AlwaysKeep(AActor* Other)
{
	/*
	if (NextMutator != nullptr)
	{
		return NextMutator.AlwaysKeep(Other);
	}
	*/
	return false;
}

bool AMutator::IsRelevant(AActor* Other, uint8& bSuperRelevant)
{
	bool bResult = false;
	/*
	bResult = CheckReplacement(Other, bSuperRelevant);
	if (bResult && (NextMutator != nullptr))
	{
		bResult = NextMutator.IsRelevant(Other, bSuperRelevant);
	}
	*/
	return bResult;
}

bool AMutator::CheckRelevance(AActor* Other)
{
	bool bResult = false;
	/*
	uint8 bSuperRelevant = 0;
	if (AlwaysKeep(Other))
	{
		return true;
	}
	bResult = IsRelevant(Other, bSuperRelevant);
	*/
	return bResult;
}

bool AMutator::CheckReplacement(AActor* Other, uint8& bSuperRelevant)
{
	return true;
}

void AMutator::PlayerChangedClass(AController* aPlayer)
{
	/*
	if (NextMutator != nullptr)
	{
		NextMutator.PlayerChangedClass(aPlayer);
	}
	*/
}

void AMutator::GetServerDetails(FServerResponseLine& ServerState)
{
	/*
	int32 i = 0;
	i = ServerState.ServerInfo.Num();
	ServerState.ServerInfo.Num() = (i + 1);
	ServerState.ServerInfo[i].Key = "Mutator";
	ServerState.ServerInfo[i].Value = GetHumanReadableName();
	*/
}

void AMutator::GetServerPlayers(FServerResponseLine& ServerState)
{
}

FString AMutator::ParseChatPercVar(AController* Who, FString Cmd)
{
	/*
	if (NextMutator != nullptr)
	{
		Cmd = NextMutator.ParseChatPercVar(Who, Cmd);
	}
	*/
	return Cmd;
}

void AMutator::MutatorFillPlayInfo(UPlayInfo* PlayInfo)
{
	/*
	FillPlayInfo(PlayInfo);
	if (NextMutator != nullptr)
	{
		NextMutator.MutatorFillPlayInfo(PlayInfo);
	}
	*/
}

bool AMutator::OverrideDownload(FString PlayerIP, FString PlayerID, FString PlayerURL, FString& RedirectURL)
{
	/*
	if (NextMutator != nullptr)
	{
		return NextMutator.OverrideDownload(PlayerIP, PlayerID, PlayerURL, RedirectURL);
	}
	*/
	return true;
}

void AMutator::ServerTraveling(FString URL, bool bItems)
{
	/*
	if (NextMutator != nullptr)
	{
		NextMutator.ServerTraveling(URL, bItems);
	}
	*/
}

bool AMutator::CanEnterVehicle(AVehicle* V, APawn* p)
{
	/*
	if (NextMutator != nullptr)
	{
		return NextMutator.CanEnterVehicle(V, p);
	}
	*/
	return true;
}

void AMutator::DriverEnteredVehicle(AVehicle* V, APawn* p)
{
	/*
	if (NextMutator != nullptr)
	{
		NextMutator.DriverEnteredVehicle(V, p);
	}
	*/
}

bool AMutator::CanLeaveVehicle(AVehicle* V, APawn* p)
{
	/*
	if (NextMutator != nullptr)
	{
		return NextMutator.CanLeaveVehicle(V, p);
	}
	*/
	return true;
}

void AMutator::DriverLeftVehicle(AVehicle* V, APawn* p)
{
	/*
	if (NextMutator != nullptr)
	{
		NextMutator.DriverLeftVehicle(V, p);
	}
	*/
}
