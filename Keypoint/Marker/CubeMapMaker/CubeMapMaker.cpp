// All the original content belonged to the US Army


#include "AA29/Keypoint/Marker/CubeMapMaker/CubeMapMaker.h"

ACubeMapMaker::ACubeMapMaker(const FObjectInitializer& objectInitializer)
	: Super(objectInitializer)
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
	/*
	mT = Spawn(Class'MultiTimer');
	if (mT != None)
	{
		mT.SetTimerHost(Self);
	}
	*/
}
void ACubeMapMaker::Begin(uint8 Index)
{
	/*
	if (Index == 0)
	{
		mT.StartTimer('Begin', 1, false);
	}
	else
	{
		mT.StartTimer('SwitchRes', 0.1, false);
		mT.StartTimer('BeginSimple', 3, false);
		SetRotation(GetRotationFromIndex(Index));
	}
	*/
}
void ACubeMapMaker::GetRotationFromIndex(uint8 Index)
{
	/*
	Log("CubeMapMaker::GetRotationFromIndex(): Index is: " $ Index);
	Switch(Index)
	{
			case 1:
				Return MakeRot(0, 0, 0);
			case 2:
				Return MakeRot(0, 16384, 0);
			case 3:
				Return MakeRot(0, 32768, 0);
			case 4:
				Return MakeRot(0, 49152, 0);
			case 5:
				Return MakeRot(-16384, 0, 0);
			case 6:
				Return MakeRot(16384, 0, 0);
			default:
				Return MakeRot(0, 0, 0);
	}
	*/
}
void ACubeMapMaker::DestroyOnFinish(bool bDoDestroy)
{
	bDestroy = bDoDestroy;
}
void ACubeMapMaker::Destroyed()
{
	/*
	mT.Destroy();
	mT = None;
	*/
}
/*
void ACubeMapMaker::TimerNotify(FName TimerName, MultiTimer NotifyTimer)
{
	Switch(TimerName)
	{
			case 'BeginSimple':
				Player.bHidden = true;
				Player.SetCollision(False, False, false);
				Controller.ClientSetViewTarget2(Self);
				Controller.AGPHUD(False);
				Controller.SetFOV(90);
				Log("CubeMapMaker::TimerNotify(): Ready");
				Return;
			case 'SwitchRes':
				if (Controller.Player.bFullScreen)
				{
					Controller.ConsoleCommand("ToggleFullScreen");
				}
				Controller.ConsoleCommand("SetRes " $ Resolution $ "x" $ Resolution);
				Return;
			case 'Destroy':
				if (bDestroy)
				{
					Destroy();
				}
				Return;
			case 'Begin':
				Player.bHidden = true;
				Controller.ClientSetViewTarget2(Self);
				SetRotation(MakeRot(0, 0, 0));
				Controller.AGPHUD(False);
				Controller.SetFOV(90);
				mT.StartTimer('SetRes', 2, false);
				break;
			case 'SetRes':
				if (Controller.Player.bFullScreen)
				{
					Controller.ConsoleCommand("ToggleFullScreen");
				}
				Controller.ConsoleCommand("SetRes " $ Resolution $ "x" $ Resolution);
				mT.StartTimer('Shots', 5);
				break;
			case 'Shots':
				NextShot();
				break;
			case 'Done':
				Controller.ClientSetViewTarget2(Player);
				Controller.AGPHUD(True);
				Controller.SetFOV(85);
				Player.bHidden = False;
				if (bDestroy)
				{
					Destroy();
				}
				break;
			default:
	}
}
*/
void ACubeMapMaker::NextShot()
{
	/*
	Switch(RotIndex)
	{
			case 0:
				Controller.ConsoleCommand("Shot");
				SetRotation(MakeRot(0, 16384, 0));
				mT.StartTimer('Shots', 3, false);
				break;
			case 1:
				Controller.ConsoleCommand("Shot");
				SetRotation(MakeRot(0, 32768, 0));
				mT.StartTimer('Shots', 3, false);
				break;
			case 2:
				Controller.ConsoleCommand("Shot");
				SetRotation(MakeRot(0, 49152, 0));
				mT.StartTimer('Shots', 3, false);
				break;
			case 3:
				Controller.ConsoleCommand("Shot");
				SetRotation(MakeRot(-16384, 0, 0));
				mT.StartTimer('Shots', 3, false);
				break;
			case 4:
				Controller.ConsoleCommand("Shot");
				SetRotation(MakeRot(16384, 0, 0));
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
	/*
	if (!bInit)
	{
		bInit = true;
		Player = AGP_Pawn(Level.GetClientPawn());
		Controller = HumanController(Player.Controller);
		Return;
	}
	*/
}
