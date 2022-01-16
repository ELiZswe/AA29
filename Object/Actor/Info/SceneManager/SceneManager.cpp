// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/SceneManager/SceneManager.h"
#include "AA29/Object/Actor/Keypoint/InterpolationPoint/InterpolationPoint.h"
#include "AA29/Object/Actor/Keypoint/AIScript/AIScript.h"

ASceneManager::ASceneManager()
{
	bHideHUD = true;
	//Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/S_SceneManager_Mat.S_SceneManager_Mat'"), NULL, LOAD_None, NULL);
}

//native Function float GetTotalSceneTime();
float ASceneManager::GetTotalSceneTime()
{
	return 0;     //FAKE   /ELiZ
};

//native Function AbortScene();
void ASceneManager::AbortScene()
{
};

void ASceneManager::BeginPlay()
{
	Super::BeginPlay();
	/*
	if ((Affect == 1) && (AffectedActor == nullptr))
	{
		Log("SceneManager : Affected actor is NULL!");
	}
	TotalSceneTime = GetTotalSceneTime();
	*/
	bIsRunning = false;
	bIsSceneStarted = false;
}

void ASceneManager::Trigger(AActor* Other, APawn* EventInstigator)
{
	bEndSceneNow = false;
	bIsRunning = true;
	bIsSceneStarted = false;
	//Disable("Trigger");
}

void ASceneManager::SceneStarted()
{
	AController* p = nullptr;
	AAIScript* S = nullptr;
	/*
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(Self, ET_SceneEnd, None);
	}
	Viewer = nullptr;
	if (Affect == 1)
	{
		Viewer = AffectedActor;
	}
	else
	{
		p = Level.ControllerList;
		if (p != nullptr)
		{
			if (p.IsA("PlayerController"))
			{
				Viewer = p;
				OldPawn = PlayerController(Viewer).Pawn;
				if (OldPawn != nullptr)
				{
					OldPawn.Velocity = FVector(0, 0, 0);
					OldPawn.Acceleration = FVector(0, 0, 0);
					PlayerController(Viewer).UnPossess();
					if (PlayerScriptTag != "None")
					{
						ForEach DynamicActors(AAIScript::StaticClass(), S, PlayerScriptTag)
						{
						}
						if (S != nullptr)
						{
							S.TakeOver(OldPawn);
						}
					}
				}
				PlayerController(Viewer).bViewingMatineeCinematic = true;
				PlayerController(Viewer).StartInterpolation();
				PlayerController(Viewer).myHUD.bHideHUD = bHideHUD;
			}
			else
			{
				p = p.nextController;
			}
		}
	}
	Viewer.StartInterpolation();
	TriggerEvent(EventStart, this, None);
	Level.Game.SceneStarted(Self, None);
	*/
}

void ASceneManager::SceneEnded()
{
	bIsSceneStarted = false;
	/*
	if (bEndSceneNow)
	{
		if (EventLab != nullptr)
		{
			EventLab.ActorNotify(Self, ET_PointReached, None, "EARLY");
		}
	}
	else
	{
		if (EventLab != nullptr)
		{
			EventLab.ActorNotify(Self, ET_PointReached, None);
		}
	}
	if (Affect == 0)
	{
		if (PlayerController(Viewer) != nullptr)
		{
			if (OldPawn != nullptr)
			{
				PlayerController(Viewer).Possess(OldPawn);
			}
			PlayerController(Viewer).bViewingMatineeCinematic = false;
			PlayerController(Viewer).bInterpolating = false;
			PlayerController(Viewer).myHUD.bHideHUD = false;
		}
	}
	Viewer.FinishedInterpolation();
	Enable("Trigger");
	bEndSceneNow = false;
	TriggerEvent(EventEnd, this, None);
	Level.Game.SceneEnded(Self, None);
	*/
}

void ASceneManager::PointReached(AInterpolationPoint* Point)
{
	/*
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(Self, ET_HttpGet, None, string(Point.Tag));
	}
	*/
}

void ASceneManager::EndScene()
{
	bEndSceneNow = true;
}

void ASceneManager::StartScene()
{
	bEndSceneNow = false;
	bIsRunning = true;
	bIsSceneStarted = false;
	//Disable("Trigger");
}
