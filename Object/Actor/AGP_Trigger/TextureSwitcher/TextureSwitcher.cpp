// All the original content belonged to the US Army

#include "AA29/Object/Actor/AGP_Trigger/TextureSwitcher/TextureSwitcher.h"

ATextureSwitcher::ATextureSwitcher()
{
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP_Gameplay/S_TextureSwitcher.S_TextureSwitcher'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();

}

void ATextureSwitcher::BeginPlay()
{
	/*
	CurrentMaterial = StartMaterialIndex;
	if (MaterialList[CurrentMaterial] != nullptr)
	{
		FinalBlendMaterial.Material = MaterialList[CurrentMaterial];
	}
	else
	{
		ListIsEmpty = true;
		Log("TextureSwitcher::BeginPlay(): ERROR: Material List is empty, or StartIndex is None");
	}
	*/
}
void ATextureSwitcher::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	if (ListIsEmpty)
	{
		Log("TextureSwitcher::Trigger(): ERROR: Material List is empty, or StartIndex is None");
		return;
	}
	if (CurrentMaterial < MaterialList.Num() - 1)
	{
		CurrentMaterial++;
	}
	else
	{
		CurrentMaterial = 0;
	}
	if (MaterialList[CurrentMaterial] != nullptr)
	{
		FinalBlendMaterial.Material = MaterialList[CurrentMaterial];
	}
	*/
}
