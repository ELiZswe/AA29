// All the original content belonged to the US Army

#include "AA29/Object/Actor/Keypoint/Marker/CubeMapMaker/CubeMapMaker.h"
#include "AA29/Object/Actor/MultiTimer/MultiTimer.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

ACubeMapMaker::ACubeMapMaker(const FObjectInitializer& objectInitializer) : Super(objectInitializer)
{
	Resolution = 1024;
	//Texture = Texture'Engine.S_Actor'
	//bCanTeleport = false;
	//CollisionRadius = 22;
	//CollisionHeight = 49;
}

void ACubeMapMaker::BeginPlay()
{
	Super::BeginPlay();
	//mT = Spawn(AMultiTimer::StaticClass());
	if (mT != nullptr)
	{
		mT->SetTimerHost(this);
	}
}

void ACubeMapMaker::Begin(uint8 Index)
{
	if (Index == 0)
	{
		mT->StartTimer("Begin", 1, false);
	}
	else
	{
		mT->StartTimer("SwitchRes", 0.1, false);
		mT->StartTimer("BeginSimple", 3, false);
		//SetRotation(GetRotationFromIndex(Index));
	}
}

FRotator ACubeMapMaker::GetRotationFromIndex(uint8 Index)
{
	//Log("CubeMapMaker::GetRotationFromIndex(): Index is: " + Index);
	switch(Index)
	{
		case 1:
			return FRotator(0, 0, 0);
		case 2:
			return FRotator(0, 16384, 0);
		case 3:
			return FRotator(0, 32768, 0);
		case 4:
			return FRotator(0, 49152, 0);
		case 5:
			return FRotator(-16384, 0, 0);
		case 6:
			return FRotator(16384, 0, 0);
		default:
			return FRotator(0, 0, 0);
	}
	return FRotator(0, 0, 0);
}

void ACubeMapMaker::DestroyOnFinish(bool bDoDestroy)
{
	bDestroy = bDoDestroy;
}

void ACubeMapMaker::Destroyed()
{
	mT->Destroy();
	mT = nullptr;
}

void ACubeMapMaker::TimerNotify(FName TimerName, AMultiTimer* NotifyTimer)
{
	/*
	switch(TimerName)
	{
			case 'BeginSimple':
				Player.bHidden = true;
				Player.SetCollision(false, false, false);
				Controller.ClientSetViewTarget2(this);
				Controller.AGPHUD(false);
				Controller.SetFOV(90);
				Log("CubeMapMaker::TimerNotify(): Ready");
				return;
			case 'SwitchRes':
				if (Controller.Player.bFullScreen)
				{
					Controller.ConsoleCommand("ToggleFullScreen");
				}
				Controller.ConsoleCommand("SetRes " + Resolution + "x" + Resolution);
				return;
			case 'Destroy':
				if (bDestroy)
				{
					Destroy();
				}
				return;
			case 'Begin':
				Player.bHidden = true;
				Controller.ClientSetViewTarget2(this);
				SetActorRotation(FRotator(0, 0, 0));
				Controller.AGPHUD(false);
				Controller.SetFOV(90);
				mT.StartTimer('SetRes', 2, false);
				break;
			case 'SetRes':
				if (Controller.Player.bFullScreen)
				{
					Controller.ConsoleCommand("ToggleFullScreen");
				}
				Controller.ConsoleCommand("SetRes " + Resolution + "x" + Resolution);
				mT.StartTimer('Shots', 5);
				break;
			case 'Shots':
				NextShot();
				break;
			case 'Done':
				Controller.ClientSetViewTarget2(Player);
				Controller.AGPHUD(true);
				Controller.SetFOV(85);
				Player.bHidden = false;
				if (bDestroy)
				{
					Destroy();
				}
				break;
			default:
	}
	*/
}

void ACubeMapMaker::NextShot()
{
	/*
	switch(RotIndex)
	{
			case 0:
				Controller.ConsoleCommand("Shot");
				SetActorRotation(FRotator(0, 16384, 0));
				mT.StartTimer('Shots', 3, false);
				break;
			case 1:
				Controller.ConsoleCommand("Shot");
				SetActorRotation(FRotator(0, 32768, 0));
				mT.StartTimer('Shots', 3, false);
				break;
			case 2:
				Controller.ConsoleCommand("Shot");
				SetActorRotation(FRotator(0, 49152, 0));
				mT.StartTimer('Shots', 3, false);
				break;
			case 3:
				Controller.ConsoleCommand("Shot");
				SetActorRotation(FRotator(-16384, 0, 0));
				mT.StartTimer('Shots', 3, false);
				break;
			case 4:
				Controller.ConsoleCommand("Shot");
				SetActorRotation(FRotator(16384, 0, 0));
				mT.StartTimer('Shots', 3, false);
				break;
			case 5:
				Controller.ConsoleCommand("Shot");
				mT.StartTimer('Done', 3, false);
			default:
	}
	RotIndex++;
	*/
}

void ACubeMapMaker::Tick(float DeltaTime)
{
	if (!bInit)
	{
		bInit = true;
		//Player = Cast<AAGP_Pawn>(Level.GetClientPawn());
		//Controller = Cast<AHumanController>(Player.Controller);
		return;
	}
}
