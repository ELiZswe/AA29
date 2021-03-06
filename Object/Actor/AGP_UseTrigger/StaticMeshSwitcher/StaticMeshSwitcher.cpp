// All the original content belonged to the US Army

#include "AA29/Object/Actor/AGP_UseTrigger/StaticMeshSwitcher/StaticMeshSwitcher.h"

AStaticMeshSwitcher::AStaticMeshSwitcher()
{
	//bHidden = false;
}

void AStaticMeshSwitcher::BeginPlay()
{
	if (Meshes.Num() == 0)
	{
		return;
	}
	SetMesh(StartMesh);
	if (StartMesh == 0)
	{
		CurrentMesh++;
	}
}

bool AStaticMeshSwitcher::UsedBy(APawn* User)
{
	if (Super::UsedBy(User))
	{
		return SwitchMesh();
	}
	else
	{
		return false;
	}
}

bool AStaticMeshSwitcher::SwitchMesh()
{
	if (Meshes.Num() == 0)
	{
		return false;
	}
	if ((CurrentMesh >= Meshes.Num()) || (CurrentMesh < 0))
	{
		CurrentMesh = 0;
		SetMesh(CurrentMesh);
	}
	else
	{
		SetMesh(CurrentMesh);
	}
	CurrentMesh++;
	return true;
}

void AStaticMeshSwitcher::SetMesh(int32 Index)
{
	if ((CurrentMesh >= Meshes.Num()) || (CurrentMesh < 0))
	{
		//Log("StaticMeshSwitcher::SwitchMesh(): Error: Index out of range");
	}
	else
	{
		//SetStaticMesh(Meshes[Index]);
	}
}
