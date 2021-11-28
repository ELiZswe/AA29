// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/Mutator/Mutator.h"

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
	//return ((!Level.IsDemoBuild()) || (Class == Class'Mutator'));
	return false;    //FAKE   /ELiZ
}

void AMutator::Destroyed()
{
	/*
	local Mutator M;
	if (Level.Game.BaseMutator == Self)
	{
		Level.Game.BaseMutator = NextMutator;
	}
	else
	{
		M = Level.Game.BaseMutator;
		if (M != None)
		{
			if (M.NextMutator == Self)
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
	if (NextMutator != None)
	{
		NextMutator.Mutate(MutateString, Sender);
	}
	*/
}

void AMutator::ModifyLogin(FString& Portal, FString& Options)
{
	/*
	if (NextMutator != None)
	{
		NextMutator.ModifyLogin(Portal, Options);
	}
	*/
}

void AMutator::NotifyLogout(AController* Exiting)
{
	/*
	if (NextMutator != None)
	{
		NextMutator.NotifyLogout(Exiting);
	}
	*/
}

void AMutator::ModifyPlayer(APawn* Other)
{
	/*
	if (NextMutator != None)
	{
		NextMutator.ModifyPlayer(Other);
	}
	*/
}

AWeapon* AMutator::GetDefaultWeapon()
{
	AWeapon* W = nullptr;
	/*
	if (NextMutator != None)
	{
		W = NextMutator.GetDefaultWeapon();
		if (W == None)
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
	if (NextMutator != None)
	{
		return NextMutator.GetInventoryClassOverride(InventoryClassName);
	}
	*/
	return InventoryClassName;
}

AWeapon* AMutator::MyDefaultWeapon()
{
	/*
	if ((DefaultWeapon == None) && (DefaultWeaponName != ""))
	{
		DefaultWeapon = class<Weapon>(DynamicLoadObject(DefaultWeaponName, Class'Class'));
	}
	*/
	return DefaultWeapon;
}

void AMutator::AddMutator(AMutator* M)
{
	/*
	if (NextMutator == None)
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
	if (NextMutator != None)
	{
		return NextMutator.NewRecommendCombo(ComboName, C);
	}
	*/
	return ComboName;
}

bool AMutator::ReplaceWith(AActor* Other, FString aClassName)
{
	/*
	local Actor A;
	local class<Actor>  aClass;
	if (aClassName == "")
	{
		return true;
	}
	aClass = class<Actor>(DynamicLoadObject(aClassName, Class'Class'));
	if (aClass != None)
	{
		A = Spawn(aClass, Other.Owner, Other.Tag, Other.Location, Other.Rotation);
	}
	if (Other.IsA('Pickup'))
	{
		if (Pickup(Other).myMarker != None)
		{
			Pickup(Other).myMarker.markedItem = Pickup(A);
			if (Pickup(A) != None)
			{
				Pickup(A).myMarker = Pickup(Other).myMarker;
				A.SetLocation((A.Location + ((A.CollisionHeight - Other.CollisionHeight) * vect(0, 0, 1))));
			}
			Pickup(Other).myMarker = None;
		}
		else
		{
			if (A.IsA('Pickup'))
			{
				Pickup(A).RespawnTime = 0;
			}
		}
	}
	if (A != None)
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
	if (NextMutator != None)
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
	if (bResult && (NextMutator != None))
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
	if (NextMutator != None)
	{
		NextMutator.PlayerChangedClass(aPlayer);
	}
	*/
}

void AMutator::GetServerDetails(FServerResponseLine& ServerState)
{
	/*
	int32 i = 0;
	i = ServerState.ServerInfo.Length;
	ServerState.ServerInfo.Length = (i + 1);
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
	if (NextMutator != None)
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
	if (NextMutator != None)
	{
		NextMutator.MutatorFillPlayInfo(PlayInfo);
	}
	*/
}

bool AMutator::OverrideDownload(FString PlayerIP, FString PlayerID, FString PlayerURL, FString& RedirectURL)
{
	/*
	if (NextMutator != None)
	{
		return NextMutator.OverrideDownload(PlayerIP, PlayerID, PlayerURL, RedirectURL);
	}
	*/
	return true;
}

void AMutator::ServerTraveling(FString URL, bool bItems)
{
	/*
	if (NextMutator != None)
	{
		NextMutator.ServerTraveling(URL, bItems);
	}
	*/
}

bool AMutator::CanEnterVehicle(AVehicle* V, APawn* p)
{
	/*
	if (NextMutator != None)
	{
		return NextMutator.CanEnterVehicle(V, p);
	}
	*/
	return true;
}

void AMutator::DriverEnteredVehicle(AVehicle* V, APawn* p)
{
	/*
	if (NextMutator != None)
	{
		NextMutator.DriverEnteredVehicle(V, p);
	}
	*/
}

bool AMutator::CanLeaveVehicle(AVehicle* V, APawn* p)
{
	/*
	if (NextMutator != None)
	{
		return NextMutator.CanLeaveVehicle(V, p);
	}
	*/
	return true;
}

void AMutator::DriverLeftVehicle(AVehicle* V, APawn* p)
{
	/*
	if (NextMutator != None)
	{
		NextMutator.DriverLeftVehicle(V, p);
	}
	*/
}