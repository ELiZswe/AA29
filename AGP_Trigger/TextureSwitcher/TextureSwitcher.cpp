// All the original content belonged to the US Army


#include "AA29/AGP_Trigger/TextureSwitcher/TextureSwitcher.h"

ATextureSwitcher::ATextureSwitcher()
{
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP_Gameplay/S_TextureSwitcher.S_TextureSwitcher'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();

}

void ATextureSwitcher::BeginPlay()
{
	/*
	CurrentMaterial = StartMaterialIndex;
	if (MaterialList[CurrentMaterial] != None)
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
		Return;
	}
	if (CurrentMaterial < MaterialList.Length - 1)
	{
		CurrentMaterial++;
	}
	else
	{
		CurrentMaterial = 0;
	}
	if (MaterialList[CurrentMaterial] != None)
	{
		FinalBlendMaterial.Material = MaterialList[CurrentMaterial];
	}
	*/
}
