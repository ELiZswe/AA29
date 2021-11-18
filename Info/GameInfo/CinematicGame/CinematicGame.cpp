// All the original content belonged to the US Army


#include "AA29/Info/GameInfo/CinematicGame/CinematicGame.h"

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
	local Controller C;
	C = Level.ControllerList;
	if (C != None)
	{
		if (PlayerController(C) != None)
		{
			PlayerController(C).ClientOpenMenu(Class'GameEngine'.Default.MainMenuClass);
		}
		C = C.nextController;
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
	SetTimer(Level.TimeDilation, True);
	*/
}

void ACinematicGame::PostLogin(APlayerController* NewPlayer)
{
	/*
	if (NewPlayer.Player != None && NewPlayer.Player.Console != None)
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
	local PlayerController PC;
	PC = PlayerController(Exiting);
	if (PC != None && PC.Player != None && PC.Player.Console != None)
	{
		PC.Player.Console.TimeTooIdle = PC.Player.Console.Default.TimeTooIdle;
	}
	Logout(Exiting);
	*/
}