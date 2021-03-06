// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_RealHero/NPC_RealHero.h"
#include "AA29/Object/Actor/RealHeroIcon/RealHeroIcon.h"
#include "AA29/Object/Actor/RealHeroAwarenessCylinder/RealHeroAwarenessCylinder.h"
#include "AA29/Object/Actor/RealHeroFadeInCylinder/RealHeroFadeInCylinder.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCRecruiterController/NPCRealHeroController/NPCRealHeroController.h"

ANPC_RealHero::ANPC_RealHero()
{
	DrawScale = 1.15;
}


void ANPC_RealHero::PostBeginPlay()
{
	Super::PostBeginPlay();
	AttachRealHeroIcon();
	AttachAwarenessCylinders();
	AddDefaultInventory();
	LoadSkinsAndMeshes();
}

void ANPC_RealHero::PossessedBy(AController* C)
{
	ANPCRealHeroController* RHC = nullptr;
	Super::PossessedBy(C);
	RHC = Cast<ANPCRealHeroController>(C);
	if (RHC != nullptr)
	{
		RHC->RHI = RHI;
		RHAC->RHController = RHC;
		RHFIC->RHController = RHC;
		RHC->MissionID = MissionID;
	}
}

void ANPC_RealHero::AttachRealHeroIcon()
{
	FBoneOffset BO;
	/*
	RHI = Spawn(ARealHeroIcon::StaticClass());
	if (RHI != nullptr)
	{
		RHI->bHidden = false;
		RHI->SetDrawScale(1);
		BO->VOffset = FVector(0, -56, 2);
		BO->ROffset->Roll = -16384;
		BO->nBone = "Pelvis";
		AttachToBoneOffset(RHI, BO);
	}
	*/
}

void ANPC_RealHero::AttachAwarenessCylinders()
{
	//RHAC = Spawn(ARealHeroAwarenessCylinder::StaticClass());
	if (RHAC != nullptr)
	{
		//AttachToBone(RHAC, "Pelvis");
	}
	//RHFIC = Spawn(ARealHeroFadeInCylinder::StaticClass());
	if (RHFIC != nullptr)
	{
		//AttachToBone(RHFIC, "Pelvis");
	}
}

void ANPC_RealHero::AnimateRunning()
{
}

void ANPC_RealHero::AnimateStanding()
{
}

void ANPC_RealHero::PlayLanding()
{
}
