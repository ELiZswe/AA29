// All the original content belonged to the US Army

#include "AA29/Object/Actor/Screenplay/Screenplay.h"
#include "Components/BillboardComponent.h"
#include "AA29/Object/ScriptObject/Condition/Condition.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "AA29/Object/ScriptEvent/ScriptEvent.h"
#include "AA29/Object/ScriptScene/ScriptScene.h"
#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"
#include "AA29/AA2_WorldSettings.h"
#include "Engine/Canvas.h"

//#include "AA29/Object/Actor/Controller/PlayerController/PlayerController.h"

// Sets default values
AScreenplay::AScreenplay()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RememberedScenes.SetNum(10);
	_iCurScene = -1;

	//bHidden = true;
	//Texture = Texture'Engine.tAGP_Screenplay';

#if WITH_EDITORONLY_DATA
	ScreenplayRoot = CreateDefaultSubobject<USceneComponent>(TEXT("ScreenplayRoot"));
	RootComponent = ScreenplayRoot;

	SpriteComponent = CreateDefaultSubobject<UBillboardComponent>(TEXT("Sprite"));
	SpriteComponent->Sprite = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/tAGP_Screenplay.tAGP_Screenplay'"), NULL, LOAD_None, NULL);

	SpriteComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
	SpriteComponent->SetRelativeScale3D(FVector(2, 2, 2));
	SpriteComponent->SetRelativeLocation(FVector(0, 0, 150));
#endif // WITH_EDITORONLY_DATA	

}

/*
State RunScreenplay
{
	Function BeginState()
	{
		if (_bDebug)
		{
			Log("Screenplay::BeginState() - state RunScreenplay");
		}
	}
	Function EndState()
	{
		if (_bDebug)
		{
			Log("Screenplay::EndState() - state RunScreenplay");
		}
		GlobalEventsStart();
		SceneStart(0);
	}
Begin:
	Sleep(0);
	GotoState("None");
}
*/


void AScreenplay::BeginPlay()
{
	Super::BeginPlay();
}

void AScreenplay::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AScreenplay::SetRememberedScene(FName SceneName, int32 Index)
{
	if (Index >= 10)
	{
		UE_LOG(LogTemp, Log, TEXT("Screenplay::SetRememberedScene(): Error: Index out of range"));
		return;
	}
	else
	{
		RememberedScenes[Index] = SceneName;
		if (_bDebug)
		{
			//UE_LOG(LogTemp, Log, TEXT("Screenplay::SetRememberedScene(): %s set to index %d"), SceneName ,Index);
		}
	}
}

FName AScreenplay::GetRememberedScene(int32 Index)
{
	if (Index >= 10)
	{
		UE_LOG(LogTemp, Log, TEXT("ScreenPlay::GetRememberedScene(): Error: RememberedScene Index out of range, returning name ""None"""));
		return "None";
	}
	else
	{
		return RememberedScenes[Index];
	}
}

void AScreenplay::Destroyed()
{
	int32 aCounter = 0;
	Super::Destroyed();
	_HumanController = nullptr;
	for (aCounter = 0; aCounter < GlobalEvents.Num(); aCounter++)
	{
		GlobalEvents[aCounter]->Destroyed();
	}
	for (aCounter = 0; aCounter < Scenes.Num(); aCounter++)
	{
		Scenes[aCounter]->Destroyed();
	}
	GlobalEvents.Empty();
	Scenes.Empty();
}

void AScreenplay::Init()
{
}

void AScreenplay::Draw(UCanvas* Canvas)
{
}

void AScreenplay::SetActor(int32 Type, AActor* Actor)
{
}

void AScreenplay::SetGlobalEvents()
{
	if (_bGlobalEventsDone)
	{
		UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::SetGlobalEvents - called more than once!"));
		return;
	}
	_bGlobalEvents = true;
}

void AScreenplay::EndGlobalEvents()
{
	_bGlobalEvents = false;
	_bGlobalEventsDone = true;
}
void AScreenplay::NewEvent()
{
	int32 Size;
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("Screenplay::NewEvent()"));
	}
	if (_bEvent)
	{
		UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::NewEvent - called without a previous EndEvent"));
		return;
	}
	_bEvent = true;
	if (_bGlobalEvents)
	{
		Size = GlobalEvents.Num();
		GlobalEvents[Size] = CreateNewEvent();
		GlobalEvents[Size]->SetParentScreenplay(this);
	}
	else
	{
		Size = Scenes.Num();
		if (Size == 0)
		{
			UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::NewEvent - no Scenes to add non global event to!"));
			return;
		}
		Scenes[Size - 1]->AddEvent(CreateNewEvent());
	}
}

void AScreenplay::EndEvent()
{
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("Screenplay::EndEvent()"));
	}
	if (!_bEvent)
	{
		UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::EndEvent - called without a previous NewEvent"));
		return;
	}
	_bEvent = false;
}

void AScreenplay::Event_ConditionsAnd()
{
	int32 Size;
	if (!_bEvent)
	{
		UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::Event_ConditionsAnd - called without a previous NewEvent"));
		return;
	}
	if (_bGlobalEvents)
	{
		Size = GlobalEvents.Num();
		if (Size == 0)
		{
			UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::Event_ConditionsAnd() - no events"));
		}
		if (!GlobalEvents[Size - 1]->SetConditionAnd())
		{
			UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::Event_ConditionsAnd() - FAILED!"));
		}
	}
	else
	{
		Size = Scenes.Num();
		if (Size == 0)
		{
			UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::Event_ConditionsAnd() - no Scenes to SetEventConditionAnd() event to!"));
			return;
		}
		if (!Scenes[Size - 1]->SetEventConditionAnd())
		{
			UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::Event_ConditionsAnd() - SetEventConditionAnd() FAILED!"));
		}
	}
}

void AScreenplay::Event_ConditionsOr()
{
	int32 Size;
	if (!_bEvent)
	{
		UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::Event_ConditionsOr - called without a previous NewEvent"));
		return;
	}
	if (_bGlobalEvents)
	{
		Size = GlobalEvents.Num();
		if (Size == 0)
		{
			UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::Event_ConditionsOr() - no events"));
		}
		if (!GlobalEvents[Size - 1]->SetConditionOr())
		{
			UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::Event_ConditionsOr() - FAILED!"));
		}
	}
	else
	{
		Size = Scenes.Num();
		if (Size == 0)
		{
			UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::Event_ConditionsOr() - no Scenes to SetEventConditionOr() event to!"));
			return;
		}
		if (!Scenes[Size - 1]->SetEventConditionOr())
		{
			UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::Event_ConditionsOr() - SetEventConditionOr() FAILED!"));
		}
	}
}

void AScreenplay::Event_RunOnceGlobal(bool Status)
{
	int32 Size;
	UE_LOG(LogTemp, Log, TEXT("Screenplay::Event_RunOnce()"));
	if (!_bEvent)
	{
		UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::Event_RunOnce() - called without a previous NewEvent"));
		return;
	}
	if (_bGlobalEvents)
	{
		Size = GlobalEvents.Num();
		if (Size == 0)
		{
			UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::Event_RunOnce() - no events"));
		}
		GlobalEvents[Size - 1]->SetRunOnceGlobal(Status);
	}
	else
	{
		Size = Scenes.Num();
		if (Size == 0)
		{
			UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::Event_RunOnce() - no Scenes to RunOnce() event to!"));
			return;
		}
		Scenes[Size - 1]->SetEventRunOnceGlobal(Status);
	}
}

void AScreenplay::Event_RunOncePerScene(bool Status)
{
	int32 Size;
	UE_LOG(LogTemp, Log, TEXT("Screenplay::Event_RunOnce()"));
	if (!_bEvent)
	{
		UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::Event_RunOnce() - called without a previous NewEvent"));
		return;
	}
	if (_bGlobalEvents)
	{
		Size = GlobalEvents.Num();
		if (Size == 0)
		{
			UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::Event_RunOnce() - no events"));
		}
		GlobalEvents[Size - 1]->SetRunOncePerScene(Status);
	}
	else
	{
		Size = Scenes.Num();
		if (Size == 0)
		{
			UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::Event_RunOnce() - no Scenes to RunOnce() event to!"));
			return;
		}
		Scenes[Size - 1]->SetEventRunOncePerScene(Status);
	}
}

void AScreenplay::Event_Repeats()
{
	if (!_bEvent)
	{
		UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::Event_Repeats - called without a previous NewEvent"));
		return;
	}
}

void AScreenplay::NewScene(FName scenetag)
{
	int32 Size = 0;
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("Screenplay::NewScene(%s)"), *scenetag.ToString());
	}
	if (_bScene)
	{
		UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::NewScene - called without a previous EndScene"));
		return;
	}
	_bScene = true;
	Size = Scenes.Num();
	Scenes[Size] = CreateNewScene();
	Scenes[Size]->SetTag(scenetag);
	Scenes[Size]->SetParentScreenplay(this);
}

void AScreenplay::EndScene()
{
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("Screenplay::EndScene()"));
	}
	if (!_bScene)
	{
		UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::EndScene - called without a previous NewScene"));
		return;
	}
	_bScene = false;
}

void AScreenplay::SceneInit_Start()
{
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("Screenplay::SceneInit_Start()"));
	}
	if (_bSceneInit)
	{
		UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::SceneInit_Start - called without a previous SceneInit_Finish"));
		return;
	}
	_bSceneInit = true;
}

void AScreenplay::SceneInit_Finish()
{
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("Screenplay::SceneInit_Finish()"));
	}
	if (!_bSceneInit)
	{
		UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::SceneInit_Finish - called without a previous SceneInit_Start"));
		return;
	}
	_bSceneInit = false;
}

void AScreenplay::SceneEnd_Start()
{
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("Screenplay::SceneEnd_Start()"));
	}
	if (_bSceneEnd)
	{
		UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::SceneEnd_Start - called without a previous SceneEnd_Finish"));
		return;
	}
	_bSceneEnd = true;
}

void AScreenplay::SceneEnd_Finish()
{
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("Screenplay::SceneEnd_Finish()"));
	}
	if (!_bSceneEnd)
	{
		UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::SceneEnd_Finish - called without a previous SceneEnd_Start"));
		return;
	}
	_bSceneEnd = false;
}

bool AScreenplay::CanAddCondition()
{
	if (_bEvent)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool AScreenplay::AddCondition(UCondition* con)
{
	int32 Size = 0;
	if (_bEvent)
	{
		if (_bGlobalEvents)
		{
			Size = GlobalEvents.Num();
			if (Size == 0)
			{
				UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::AddCondition - no GlobalEvents!"));
				return false;
			}
			return GlobalEvents[Size - 1]->AddCondition(con);
		}
		else
		{
			Size = Scenes.Num();
			if (Size == 0)
			{
				UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::AddCondition - no Scenes!"));
				return false;
			}
			return Scenes[Size - 1]->AddEventCondition(con);
		}
	}
	return false;
}

void AScreenplay::Condition(FString szCon, FString szParams)
{
	UCondition* con = nullptr;
	if (_bDebug)
	{
		//UE_LOG(LogTemp, Log, TEXT("Screenplay::Condtion(" + szCon + ", " + szParams + ")"));
	}
	if (CanAddCondition())
	{
		con = CreateNewCondition(szCon);
		if (con == nullptr)
		{
			if (_bDebug)
			{
				UE_LOG(LogTemp, Log, TEXT("Screenplay::Condtion() failed in call to CreateNewCondition()"));
			}
			_bBroken = true;
		}
		else
		{
			/*
			if (Level.Game.IsMultiPlayer() && !con->bSupportsMP)
			{
				UE_LOG(LogTemp, Log, TEXT("Screenplay::Condition  attempted to include non-multiplayer-condition in multiplayer game."));
				_bBroken = true;
				return;
			}
			con->SetParentScreenplay(this);
			*/
			con->SetParamString(szParams);
			if (con->GetNumParams() != con->GetNumParamsDefined())
			{
				if (_bDebug)
				{
					//UE_LOG(LogTemp, Log, TEXT("Wrong number of parameters. Defined: " + con.GetNumParamsDefined() + " Actual: " + con.GetNumParams()));
				}
				_bBroken = true;
			}
			if (!con->ProcessParams())
			{
				if (_bDebug)
				{
					//UE_LOG(LogTemp, Log, TEXT("ProcessParams failed for " + con.Class + " : " + szParams));
				}
				_bBroken = true;
			}
			if (!AddCondition(con))
			{
				if (_bDebug)
				{
					UE_LOG(LogTemp, Log, TEXT("Screenplay::Condtion() failed in call to AddCondition()"));
				}
				_bBroken = true;
			}
		}
	}
	else
	{
		if (_bDebug)
		{
			UE_LOG(LogTemp, Log, TEXT("Screenplay::Condtion() failed in call to CanAddCondition()"));
		}
		_bBroken = true;
	}
}

bool AScreenplay::CanAddDirection()
{
	int32 myCounter;
	myCounter = 0;
	if (_bSceneInit)
	{
		myCounter++;
	}
	if (_bSceneEnd)
	{
		myCounter++;
	}
	if (_bEvent)
	{
		myCounter++;
	}
	return myCounter == 1;
}

bool AScreenplay::AddDirection(UDirection* Dir)
{
	int32 Size = 0;
	if (_bSceneInit)
	{
		Size = Scenes.Num();
		if (Size == 0)
		{
			UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::AddDirection - no Scenes!"));
			return false;
		}
		return Scenes[Size - 1]->AddInitDirection(Dir);
	}
	if (_bSceneEnd)
	{
		Size = Scenes.Num();
		if (Size == 0)
		{
			UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::AddDirection - no Scenes!"));
			return false;
		}
		return Scenes[Size - 1]->AddEndDirection(Dir);
	}
	if (_bEvent)
	{
		if (_bGlobalEvents)
		{
			Size = GlobalEvents.Num();
			if (Size == 0)
			{
				UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::AddDirection - no GlobalEvents!"));
				return false;
			}
			return GlobalEvents[Size - 1]->AddDirection(Dir);
		}
		else
		{
			Size = Scenes.Num();
			if (Size == 0)
			{
				UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::AddDirection - no Scenes!"));
				return false;
			}
			return Scenes[Size - 1]->AddEventDirection(Dir);
		}
	}
	return false;
}

void AScreenplay::Direction(FString szDir, FString szParams, FName DummyName)
{
	UDirection* Dir = nullptr;
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("Screenplay::Direction(%s, %s)"), *szDir, *szParams);
	}
	if (CanAddDirection())
	{
		Dir = CreateNewDirection(szDir);
		if (Dir == nullptr)
		{
			if (_bDebug)
			{
				UE_LOG(LogTemp, Log, TEXT("Screenplay::Direction() failed in call to CreateNewDirection()"));
			}
			_bBroken = true;
		}
		else
		{
			/*
			if (Level.Game.IsMultiPlayer() && !Dir->bSupportsMP)
			{
				UE_LOG(LogTemp, Log, TEXT("Screenplay::Direction  attempted to include non-multiplayer-direction in multiplayer game."));
				_bBroken = true;
				return;
			}
			*/
			Dir->SetParentScreenplay(this);
			Dir->SetParamString(szParams);
			if (Dir->GetNumParams() != Dir->GetNumParamsDefined())
			{
				if (_bDebug)
				{
					//UE_LOG(LogTemp, Log, TEXT("Wrong number of parameters. Defined: " + Dir->GetNumParamsDefined() + " Actual: " + Dir->GetNumParams());
				}
				_bBroken = true;
			}
			if (!Dir->ProcessParams())
			{
				if (_bDebug)
				{
					//UE_LOG(LogTemp, Log, TEXT("ProcessParams failed for " + Dir.Class + " : " + szParams));
				}
				_bBroken = true;
			}
			if (!AddDirection(Dir))
			{
				if (_bDebug)
				{
					UE_LOG(LogTemp, Log, TEXT("Screenplay::Direction() failed in call to AddDirection()"));
				}
				_bBroken = true;
			}
		}
	}
	else
	{
		if (_bDebug)
		{
			UE_LOG(LogTemp, Log, TEXT("Screenplay::Direction() failed in call to CanAddDirection()"));
		}
		_bBroken = true;
	}
}

void AScreenplay::PostBeginPlay()
{
	//Super::PostBeginPlay();
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugScreenplay)
	{
		_bDebug = true;
	}
	_bReady = true;
}

void AScreenplay::Trigger(AActor* Other, APawn* EventInstigator)
{
	if (_bReady)
	{
		_bReady = false;
		if (_bDebug)
		{
			//Log("Screenplay::Trigger() - got PlayerController: " + Other);
		}
		/*
		if (!Level.Game.IsMultiPlayer())
		{
			_HumanController = Cast<APlayerController>(Other);
		}
		else
		{
			_HumanController = nullptr;
		}
		*/
		Init();
		DumpScreenplay();
		if (_bBroken)
		{
			UE_LOG(LogTemp, Log, TEXT("**** SCREENPLAY IS BROKEN!! ****"));
		}
		else
		{
			//GotoState('RunScreenplay');
		}
	}
}
void AScreenplay::SceneStart(int32 Id)
{
	int32 Size = 0;
	if (Id < 0)
	{
		if (_bDebug)
		{
			UE_LOG(LogTemp, Log, TEXT("Screenplay::SceneStart() - cannot start an id of %d"), Id);
		}
		return;
	}
	if (_iCurScene != -1)
	{
		SceneFinish(_iCurScene);
	}
	Size = Scenes.Num();
	if (Id < Size)
	{
		_iCurScene = Id;
		if (_HumanController != nullptr)
		{
			if (_bDebug)
			{
				//_HumanController->ScreenPrint("SceneStart(" + Scenes[_iCurScene]->_Tag + ")");
			}
		}
		if (_bDebug)
		{
			//UE_LOG(LogTemp, Log, TEXT("**>Screenplay::SceneStart(" + Id + ") " + Scenes[_iCurScene]._Tag));
		}
		Scenes[_iCurScene]->SceneStart();
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::SceneStart() - invalid id"));
	}
}

void AScreenplay::SceneFinish(int32 Id)
{
	int32 Size = 0;
	if (Id < 0)
	{
		if (_bDebug)
		{
			UE_LOG(LogTemp, Log, TEXT("Screenplay::SceneStart() - cannot start an id of %d"), Id);
		}
		return;
	}
	if (Id != _iCurScene)
	{
		UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::SceneFinish() - trying to finish a scene that is not the current scene!"));
	}
	Size = Scenes.Num();
	if (Id < Size)
	{
		if (_HumanController != nullptr)
		{
			if (_bDebug)
			{
				//_HumanController->ScreenPrint("SceneFinish(" + Scenes[_iCurScene]->_Tag + ")");
			}
		}
		if (_bDebug)
		{
			UE_LOG(LogTemp, Log, TEXT("**<Screenplay::SceneFinish(%d) &s"),Id, *Scenes[_iCurScene]->_Tag.ToString());
		}
		Scenes[Id]->SceneFinish();
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("ERROR Screenplay::SceneFinish() - invalid id"));
	}
	_iCurScene = -1;
}

void AScreenplay::SceneEnd()
{
	int32 nextscene;
	int32 Size;
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("Screenplay::SceneEnd()"));
	}
	nextscene = _iCurScene + 1;
	SceneFinish(_iCurScene);
	Size = Scenes.Num();
	if (nextscene < Size)
	{
		SceneStart(nextscene);
	}
}

void AScreenplay::SceneRestart()
{
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("Screenplay::SceneRestart()"));
	}
	SceneStart(_iCurScene);
}

void AScreenplay::SceneJump(FName Tag)
{
	int32 Id = 0;
	int32 Size = 0;
	int32 Scene = 0;
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("Screenplay::SceneJump(%s)"), *Tag.ToString());
	}
	Id = -1;
	Size = Scenes.Num();
	for (Scene = 0; Scene < Size; Scene++)
	{
		if (Tag == Scenes[Scene]->GetTag())
		{
			Id = Scene;
		}
	}
	if (Id == -1)
	{
		if (_bDebug)
		{
			//UE_LOG(LogTemp, Log, TEXT("Screenplay::SceneJump(" + Tag + ") - scene with tag not found!");
		}
	}
	else
	{
		SceneStart(Id);
	}
}

void AScreenplay::SceneStop()
{
	int32 Temp;
	Temp = _iCurScene;
	SceneFinish(_iCurScene);
	_iCurScene = Temp;
}

UScriptEvent* AScreenplay::CreateNewEvent()
{
	UScriptEvent* myEvent = nullptr;
	UScriptEvent* cEvent = nullptr;
	/*
	cEvent = class<ScriptEvent>(DynamicLoadObject("Engine.ScriptEvent", Class'Class'));
	myEvent = new (None) classcEvent;
	*/
	return myEvent;
}

UScriptScene* AScreenplay::CreateNewScene()
{
	UScriptScene* myScene = nullptr;
	UScriptScene* cScene = nullptr;
	/*
	cScene = class<ScriptScene>(DynamicLoadObject("Engine.ScriptScene", Class'Class'));
	myScene = new (None) classcScene;
	*/
	return myScene;
}

UDirection* AScreenplay::CreateNewDirection(FString Dir)
{
	UDirection* myDirection = nullptr;
	UDirection* cDirection = nullptr;
	/*
	cDirection = class<Direction>(DynamicLoadObject(Dir, Class'Class'));
	myDirection = new (None) classcDirection;
	*/
	return myDirection;
}

UCondition* AScreenplay::CreateNewCondition(FString con)
{
	UCondition* myCondition = nullptr;
	UCondition* cCondition = nullptr;
	/*
	cCondition = class<Condition>(DynamicLoadObject(con, Class'Class'));
	myCondition = new (None) classcCondition;
	*/
	return myCondition;
}

void AScreenplay::SetDebug(bool Debug)
{
	int32 Size = 0;
	int32 cur = 0;
	_bDebug = Debug;
	Size = GlobalEvents.Num();
	for (cur = 0; cur < Size; cur++)
	{
		GlobalEvents[cur]->SetDebug(Debug);
	}
	Size = Scenes.Num();
	for (cur = 0; cur < Size; cur++)
	{
		Scenes[cur]->SetDebug(Debug);
	}
}

void AScreenplay::DumpScreenplay()
{
	int32 Size = 0;
	int32 cur = 0;
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("**** Screenplay::DumpScreenplay() START ****"));
	}
	Size = GlobalEvents.Num();
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("GlobalEvents: %d"), Size);
	}
	for (cur = 0; cur < Size; cur++)
	{
		if (_bDebug)
		{
			//UE_LOG(LogTemp, Log, TEXT("GlobalEvents[" + cur + "] is a " + GlobalEvents[cur].Class);
		}
		GlobalEvents[cur]->DumpEvent();
	}
	Size = Scenes.Num();
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT(" "));
		UE_LOG(LogTemp, Log, TEXT("Scenes: %d"),Size);
	}
	for (cur = 0; cur < Size; cur++)
	{
		if (_bDebug)
		{
			//UE_LOG(LogTemp, Log, TEXT("Scenes[" + cur + "] is a " + Scenes[cur].Class + " with tag '" + Scenes[cur]._Tag + "'");
		}
		Scenes[cur]->DumpScene();
		if (_bDebug)
		{
			UE_LOG(LogTemp, Log, TEXT(" "));
		}
	}
	UE_LOG(LogTemp, Log, TEXT("**** Screenplay::DumpScreenplay() FINISH ****"));
}

void AScreenplay::GlobalEventsStart()
{
	int32 Size = 0;
	int32 cur = 0;
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("Screenplay::GlobalEventsStart()"));
	}
	Size = GlobalEvents.Num();
	for (cur = 0; cur < Size; cur++)
	{
		GlobalEvents[cur]->EventStart();
	}
}

APlayerController* AScreenplay::GetHumanController()
{
	return _HumanController;
}

AController* AScreenplay::GetControllerList()
{
	/*
	if (Level.Game.IsMultiPlayer())
	{
		return Level.ControllerList;
	}
	else
	{
		return GetHumanController();
	}
	*/
	return (Cast<AController>(GetHumanController()));    //FAKE   /ELiZ
}

void AScreenplay::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	if (_iCurScene == -1)
	{
		//Canvas->DrawText("SCREENPLAY:  NO CURRENT SCENE");
	}
	else
	{
		//Canvas->DrawText("SCREENPLAY:  Scene """ + Scenes[_iCurScene]._Tag + """");
	}
	YPos += YL;
	//Canvas->SetPos(4, YPos);
}

void AScreenplay::NotifyCheated()
{
	UE_LOG(LogTemp, Log, TEXT("ScreenPlay::NotifyCheated()	Player cheated!"));
	bPlayerCheated = true;
}

