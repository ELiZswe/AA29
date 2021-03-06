// All the original content belonged to the US Army

#include "AA29/Object/Actor/FSTS_FA_MedicalPickups/FA_CanvasShadePickup/FA_CanvasShadePickup.h"
#include "AA29/Object/Actor/Projector/Projector.h"

AFA_CanvasShadePickup::AFA_CanvasShadePickup()
{
	AltStaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_FirstAid/Hydration/Shade_Hanging.Shade_Hanging'"), NULL, LOAD_None, NULL);
	//StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_FirstAid/Hydration/Shade_Ground.Shade_Ground'"), NULL, LOAD_None, NULL);
	//CollisionRadius = 22;
}

void AFA_CanvasShadePickup::PostBeginPlay()
{
	AProjector* SearchActor = nullptr;
	//Super::PostBeginPlay();
	/*
	ForEach AllActors(AProjector::StaticClass(), SearchActor, "Canvas_Shade_Projector")
	{
		if (SearchActor != nullptr)
		{
			ShadowProjector = SearchActor;
			ShadowProjector.DetachProjector(true);
		}
	}
	*/
}

void AFA_CanvasShadePickup::SwitchToAltStaticMesh()
{
	//SetStaticMesh(AltStaticMesh);
}

void AFA_CanvasShadePickup::SwitchToOriginalStaticMesh()
{
	//SetStaticMesh(StaticMesh);
}

void AFA_CanvasShadePickup::DisablePickup()
{
	Super::DisablePickup();
	//bHidden = false;
	SwitchToAltStaticMesh();
	//ShadowProjector->AttachProjector();
}

void AFA_CanvasShadePickup::ActivatePickup()
{
	Super::ActivatePickup();
	SwitchToOriginalStaticMesh();
	//ShadowProjector->DetachProjector(true);
}
