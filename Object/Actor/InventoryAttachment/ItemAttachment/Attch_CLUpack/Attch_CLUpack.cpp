// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_CLUpack/Attch_CLUpack.h"

AAttch_CLUpack::AAttch_CLUpack()
{
	EnemyStaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_Armory/Javelin/CluPouch.CluPouch'"), NULL, LOAD_None, NULL);
	FriendlyStaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_Armory/Javelin/CluPouch.CluPouch'"), NULL, LOAD_None, NULL);
	RelativeRotation = FRotator(32000, 0, 1500);
}

void AAttch_CLUpack::SetUpCLUPack(APawn* p)
{
	/*
	Instigator = p;
	if (p != nullptr)
	{
		if (p.HasBone("LUtilityR"))
		{
			p.SetBoneScale(0, 0, "LUtilityR");
		}
		if (p.HasBone("ButtPouch"))
		{
			p.SetBoneScale(1, 0.01, "ButtPouch");
		}
		p.AttachToBone(this, "ButtPouch");
		SetRelativeLocation(RelativeLocation);
		SetRelativeRotation(RelativeRotation);
		NotifyBaseChange();
	}
	else
	{
		Destroy();
	}
	*/
}

void AAttch_CLUpack::RemoveCLUPack()
{
	/*
	if (Instigator != nullptr)
	{
		DetachFromBone(Instigator);
		Instigator.SetBoneScale(0);
		Instigator.SetBoneScale(1);
	}
	Destroy();
	*/
}
