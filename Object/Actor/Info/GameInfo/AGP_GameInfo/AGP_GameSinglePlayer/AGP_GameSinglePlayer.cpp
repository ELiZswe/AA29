// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameSinglePlayer/AGP_GameSinglePlayer.h"
#include "AA29/Object/Actor/AI_Primitive/AI_Interface/AI_Interface.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

AAGP_GameSinglePlayer::AAGP_GameSinglePlayer()
{
	PlayerControllerClassName = "AGP.StudentController";
	GameName = "AGP Game - Single Player";
}

void AAGP_GameSinglePlayer::PreBeginPlay()
{
	//Super::PreBeginPlay();
	SetupAI();
}

void AAGP_GameSinglePlayer::PostBeginPlay()
{
	AController* C = nullptr;
	/*
	if ("" + FString::FromInt(Level) ~= "Entry.LevelInfo0")
	{
		for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
		{
			if (Cast<AHumanController>(C) != nullptr)
			{
				Cast<AHumanController>(C).DoFade(false,true,0);
			}
		}
	}
	*/
}

void AAGP_GameSinglePlayer::StartMatch()
{
	AController* C = nullptr;
	Super::StartMatch();
	/*
	if ("" + FString::FromInt(Level) ~= "Entry.LevelInfo0")
	{
		if ("" + FString::FromInt(Class'GameEngine'.Default.GPendingLevel) ~= "None")
		{
			for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
			{
				if (Cast<AHumanController>(C) != nullptr)
				{
					Cast<AHumanController>(C).DoFade(false,true,0);
				}
			}
			SetTimer(0.1,false);
			bEntryLevelinitialized=false;
		}
	}
	*/
}

void AAGP_GameSinglePlayer::Timer()
{
	AController* C = nullptr;
	if (bEntryLevelinitialized)
	{
		return;
	}
	bEntryLevelinitialized=true;
	/*
	for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
	{
		if (Cast<AHumanController>(C) != nullptr)
		{
			Cast<AHumanController>(C).EntryLevelSimulatedScreenplay();
		}
	}
	*/
}

void AAGP_GameSinglePlayer::SetupAI()
{
	AAI_Interface* local_interface = nullptr;
	AAI_Interface* interface_class = nullptr;
	/*
	if (!Level.allowAI)
	{
		return;
	}
	interface_class = class<AI_Interface>(DynamicLoadObject("AGP_AI.AI_Overlord", Class'Class'));
	local_interface = Spawn(interface_class, this);
	if (local_interface == nullptr)
	{
		GOTO JL0077;
	}
	AI_global = local_interface;
	AI_global.Init();
JL0077:
*/
}

AActor* AAGP_GameSinglePlayer::GetDefaultTeamClass()
{
	//return class<Actor>(DynamicLoadObject("AGP_Characters.ClassRecruit", Class'Class'));
	return nullptr;    //FAKE   /ELiZ
}
