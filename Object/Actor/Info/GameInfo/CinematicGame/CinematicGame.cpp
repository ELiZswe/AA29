// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/GameInfo/CinematicGame/CinematicGame.h"

ACinematicGame::ACinematicGame()
{
	HUDType = "AGP_Game.CinematicHud";
	PlayerControllerClassName = "AGP_Game.CinematicPlayer";
}

void ACinematicGame::PostBeginPlay()
{
	/*
	PostBeginPlay();
	if (Level.Title ~= "End Game")
	{
		Tag = 'BackToMenu';
	}
	*/
}

void ACinematicGame::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	AController* C = nullptr;
	for (C=Level.ControllerList; C!=nullptr; C=C->nextController)
	{
		if (Cast<APlayerController>(C) != nullptr)
		{
			Cast<APlayerController>(C).ClientOpenMenu(Class'GameEngine'.Default.MainMenuClass);
		}
	}
	*/
}

void ACinematicGame::AddDefaultInventory(APawn* PlayerPawn)
{
	return;
}

void ACinematicGame::SetGameSpeed(float t)
{
	/*
	GameSpeed = 1;
	Level.TimeDilation = 1;
	SetTimer(Level.TimeDilation, true);
	*/
}

void ACinematicGame::PostLogin(APlayerController* NewPlayer)
{
	/*
	if (NewPlayer.Player != nullptr && NewPlayer.Player.Console != nullptr)
	{
		NewPlayer.Player.Console.TimeTooIdle = 0;
	}
	PostLogin(NewPlayer);
	TriggerEvent('StartGame', NewPlayer, NewPlayer.Pawn);
	*/
}

void ACinematicGame::Logout(AController* Exiting)
{
	/*
	APlayerController* PC = nullptr;
	PC = Cast<APlayerController>(Exiting);
	if (PC != nullptr && PC.Player != nullptr && PC.Player.Console != nullptr)
	{
		PC.Player.Console.TimeTooIdle = PC.Player.Console.Default.TimeTooIdle;
	}
	Logout(Exiting);
	*/
}
