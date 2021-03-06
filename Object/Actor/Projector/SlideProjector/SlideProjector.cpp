// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projector/SlideProjector/SlideProjector.h"

ASlideProjector::ASlideProjector()
{
	SlideProjectorHelp.SetNum(10);
	SlideProjectorHelp = {
		"Switches materials when triggered",
		"Only upports Single player currently",
		"",
		"[MaterialList] The list of materials to switch between",
		"[StartMaterialIndex] The index of the material to start with"
	};
	bProjectOnUnlit = true;
	bDynamicAttach = true;
	//bStatic = false;
	//Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/S_SlideProjector_Mat.S_SlideProjector_Mat'"), NULL, LOAD_None, NULL);
}

bool ASlideProjector::SetCurrentMaterial(int32 Index)
{
	/*
	if ((Index < MaterialList.Num()) && (Index >= 0))
	{
		CurrentMaterial = Index;
		DetachProjector(true);
		ProjTexture = MaterialList[CurrentMaterial];
		if (ProjTexture != nullptr)
		{
			AttachProjector();
		}
		return true;
	}
	else
	{
		if (Index < 0)
		{
			DetachProjector(true);
		}
		else
		{
			Log("SlideProjector::SetCurrentMaterial(): Error: Index out of range");
			return false;
		}
	}
	DetachProjector(true);
	ProjTexture = MaterialList[CurrentMaterial];
	if (ProjTexture != nullptr)
	{
		AttachProjector();
	}
	*/
	return true;
}

void ASlideProjector::BeginPlay()
{
	CurrentMaterial = StartMaterialIndex;
	if (MaterialList[CurrentMaterial] != nullptr)
	{
		ProjTexture = MaterialList[CurrentMaterial];
	}
	else
	{
		ListIsEmpty = true;
		//Log("TextureSwitcher::BeginPlay(): ERROR: Material List is empty, or StartIndex is None");
	}
}

void ASlideProjector::Trigger(AActor* Other, APawn* EventInstigator)
{
	if (ListIsEmpty)
	{
		//Log("TextureSwitcher::Trigger(): ERROR: Material List is empty, or StartIndex is None");
		return;
	}
	/*
	if (CurrentMaterial < (MaterialList.Num() - 1))
	{
		CurrentMaterial++;
	}
	else
	{
		CurrentMaterial = 0;
	}
	*/
	DetachProjector(true);
	ProjTexture = MaterialList[CurrentMaterial];
	if (ProjTexture != nullptr)
	{
		AttachProjector(0);
	}
}

void ASlideProjector::UnTrigger(AActor* Other, APawn* EventInstigator)
{
	DetachProjector(true);
}
