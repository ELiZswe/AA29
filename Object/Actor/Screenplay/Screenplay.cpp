// All the original content belonged to the US Army

#include "AA29/Object/Actor/Screenplay/Screenplay.h"
#include "Components/BillboardComponent.h"
#include "AA29/Object/ScriptObject/Condition/Condition.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "AA29/Object/ScriptEvent/ScriptEvent.h"
#include "AA29/Object/ScriptScene/ScriptScene.h"

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

	  //     

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
	/*
	if (Index >= 10)
	{
		Log("Screenplay::SetRememberedScene(): Error: Index out of range");
		return;
	}
	else
	{
		RememberedScenes[Index] = SceneName;
		if (_bDebug)
		{
			Log("Screenplay::SetRememberedScene(): " $ SceneName $ " set to index " $ Index);
		}
	}
	*/
}

FName AScreenplay::GetRememberedScene(int32 Index)
{
	if (Index >= 10)
	{
		//Log("ScreenPlay::GetRememberedScene(): Error: RememberedScene Index out of range, returning name "None"");
		return "None";
	}
	else
	{
		return RememberedScenes[Index];
	}
}

void AScreenplay::Destroyed()
{
	/*
	int32 Counter;
	Super::Destroyed();
	_HumanController = nullptr;
	for (Counter = 0; Counter < GlobalEvents.Num(); Counter++)
	{
		GlobalEvents[Counter].Destroyed();
	}
	for (Counter = 0; Counter < Scenes.Num(); Counter++)
	{
		Scenes[Counter].Destroyed();
	}
	GlobalEvents.remove(0, GlobalEvents.Num());
	Scenes.remove(0, Scenes.Num());
	*/
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
	/*
	if (_bGlobalEventsDone)
	{
		Log("ERROR Screenplay::SetGlobalEvents - called more than once!");
		return;
	}
	*/

	_bGlobalEvents = true;
}
void AScreenplay::EndGlobalEvents()
{
	_bGlobalEvents = false;
	_bGlobalEventsDone = true;
}
void AScreenplay::NewEvent()
{
	/*
	int32 Size;
	if (_bDebug)
	{
		Log("Screenplay::NewEvent()");
	}
	if (_bEvent)
	{
		Log("ERROR Screenplay::NewEvent - called without a previous EndEvent");
		return;
	}
	_bEvent = true;
	if (_bGlobalEvents)
	{
		Size = GlobalEvents.Num();
		GlobalEvents[Size] = CreateNewEvent();
		GlobalEvents[Size].SetParentScreenplay(this);
	}
	else
	{
		Size = Scenes.Num();
		if (Size == 0)
		{
			Log("ERROR Screenplay::NewEvent - no Scenes to add non global event to!");
			return;
		}
		Scenes[Size - 1].AddEvent(CreateNewEvent());
	}
	*/
}
void AScreenplay::EndEvent()
{
	if (_bDebug)
	{
		//Log("Screenplay::EndEvent()");
	}
	if (!_bEvent)
	{
		//Log("ERROR Screenplay::EndEvent - called without a previous NewEvent");
		return;
	}
	_bEvent = false;
}
void AScreenplay::Event_ConditionsAnd()
{
	/*
	int32 Size;
	if (!_bEvent)
	{
		Log("ERROR Screenplay::Event_ConditionsAnd - called without a previous NewEvent");
		return;
	}
	if (_bGlobalEvents)
	{
		Size = GlobalEvents.Num();
		if (Size == 0)
		{
			Log("ERROR Screenplay::Event_ConditionsAnd() - no events");
		}
		if (!GlobalEvents[Size - 1].SetConditionAnd())
		{
			Log("ERROR Screenplay::Event_ConditionsAnd() - FAILED!");
		}
	}
	else
	{
		Size = Scenes.Num();
		if (Size == 0)
		{
			Log("ERROR Screenplay::Event_ConditionsAnd() - no Scenes to SetEventConditionAnd() event to!");
			return;
		}
		if (!Scenes[Size - 1].SetEventConditionAnd())
		{
			Log("ERROR Screenplay::Event_ConditionsAnd() - SetEventConditionAnd() FAILED!");
		}
	}
	*/
}
void AScreenplay::Event_ConditionsOr()
{
	/*
	int32 Size;
	if (!_bEvent)
	{
		Log("ERROR Screenplay::Event_ConditionsOr - called without a previous NewEvent");
		return;
	}
	if (_bGlobalEvents)
	{
		Size = GlobalEvents.Num();
		if (Size == 0)
		{
			Log("ERROR Screenplay::Event_ConditionsOr() - no events");
		}
		if (!GlobalEvents[Size - 1].SetConditionOr())
		{
			Log("ERROR Screenplay::Event_ConditionsOr() - FAILED!");
		}
	}
	else
	{
		Size = Scenes.Num();
		if (Size == 0)
		{
			Log("ERROR Screenplay::Event_ConditionsOr() - no Scenes to SetEventConditionOr() event to!");
			return;
		}
		if (!Scenes[Size - 1].SetEventConditionOr())
		{
			Log("ERROR Screenplay::Event_ConditionsOr() - SetEventConditionOr() FAILED!");
		}
	}
	*/
}
void AScreenplay::Event_RunOnceGlobal(bool Status)
{
	/*
	int32 Size;
	Log("Screenplay::Event_RunOnce()");
	if (!_bEvent)
	{
		Log("ERROR Screenplay::Event_RunOnce() - called without a previous NewEvent");
		return;
	}
	if (_bGlobalEvents)
	{
		Size = GlobalEvents.Num();
		if (Size == 0)
		{
			Log("ERROR Screenplay::Event_RunOnce() - no events");
		}
		GlobalEvents[Size - 1].SetRunOnceGlobal(Status);
	}
	else
	{
		Size = Scenes.Num();
		if (Size == 0)
		{
			Log("ERROR Screenplay::Event_RunOnce() - no Scenes to RunOnce() event to!");
			return;
		}
		Scenes[Size - 1].SetEventRunOnceGlobal(Status);
	}
	*/
}
void AScreenplay::Event_RunOncePerScene(bool Status)
{
	/*
	int32 Size;
	Log("Screenplay::Event_RunOnce()");
	if (!_bEvent)
	{
		Log("ERROR Screenplay::Event_RunOnce() - called without a previous NewEvent");
		return;
	}
	if (_bGlobalEvents)
	{
		Size = GlobalEvents.Num();
		if (Size == 0)
		{
			Log("ERROR Screenplay::Event_RunOnce() - no events");
		}
		GlobalEvents[Size - 1].SetRunOncePerScene(Status);
	}
	else
	{
		Size = Scenes.Num();
		if (Size == 0)
		{
			Log("ERROR Screenplay::Event_RunOnce() - no Scenes to RunOnce() event to!");
			return;
		}
		Scenes[Size - 1].SetEventRunOncePerScene(Status);
	}
	*/
}
void AScreenplay::Event_Repeats()
{
	if (!_bEvent)
	{
		//Log("ERROR Screenplay::Event_Repeats - called without a previous NewEvent");
		return;
	}
}
void AScreenplay::NewScene(FName scenetag)
{
	/*
	int32 Size;
	if (_bDebug)
	{
		Log("Screenplay::NewScene(" $ scenetag $ ")");
	}
	if (_bScene)
	{
		Log("ERROR Screenplay::NewScene - called without a previous EndScene");
		return;
	}
	_bScene = true;
	Size = Scenes.Num();
	Scenes[Size] = CreateNewScene();
	Scenes[Size].SetTag(scenetag);
	Scenes[Size].SetParentScreenplay(this);
	*/
}
void AScreenplay::EndScene()
{
	if (_bDebug)
	{
		//Log("Screenplay::EndScene()");
	}
	if (!_bScene)
	{
		//Log("ERROR Screenplay::EndScene - called without a previous NewScene");
		return;
	}
	_bScene = false;
}
void AScreenplay::SceneInit_Start()
{
	if (_bDebug)
	{
		//Log("Screenplay::SceneInit_Start()");
	}
	if (_bSceneInit)
	{
		//Log("ERROR Screenplay::SceneInit_Start - called without a previous SceneInit_Finish");
		return;
	}
	_bSceneInit = true;
}
void AScreenplay::SceneInit_Finish()
{
	if (_bDebug)
	{
		//Log("Screenplay::SceneInit_Finish()");
	}
	if (!_bSceneInit)
	{
		//Log("ERROR Screenplay::SceneInit_Finish - called without a previous SceneInit_Start");
		return;
	}
	_bSceneInit = false;
}
void AScreenplay::SceneEnd_Start()
{
	if (_bDebug)
	{
		//Log("Screenplay::SceneEnd_Start()");
	}
	if (_bSceneEnd)
	{
		//Log("ERROR Screenplay::SceneEnd_Start - called without a previous SceneEnd_Finish");
		return;
	}
	_bSceneEnd = true;
}
void AScreenplay::SceneEnd_Finish()
{
	if (_bDebug)
	{
		//Log("Screenplay::SceneEnd_Finish()");
	}
	if (!_bSceneEnd)
	{
		//Log("ERROR Screenplay::SceneEnd_Finish - called without a previous SceneEnd_Start");
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
	/*
	int32 Size;
	if (_bEvent)
	{
		if (_bGlobalEvents)
		{
			Size = GlobalEvents.Num();
			if (Size == 0)
			{
				Log("ERROR Screenplay::AddCondition - no GlobalEvents!");
				return false;
			}
			return GlobalEvents[Size - 1].AddCondition(con);
		}
		else
		{
			Size = Scenes.Num();
			if (Size == 0)
			{
				Log("ERROR Screenplay::AddCondition - no Scenes!");
				return false;
			}
			return Scenes[Size - 1].AddEventCondition(con);
		}
	}
	*/
	return false;    //FAKE   /ELiZ
}

void AScreenplay::Condition(FString szCon, FString szParams)
{
	/*
	local Condition con;
	if (_bDebug)
	{
		Log("Screenplay::Condtion(" $ szCon $ ", " $ szParams $ ")");
	}
	if (CanAddCondition())
	{
		con = CreateNewCondition(szCon);
		if (con == nullptr)
		{
			if (_bDebug)
			{
				Log("Screenplay::Condtion() failed in call to CreateNewCondition()");
			}
			_bBroken = true;
		}
		else
		{
			if (Level.Game.IsMultiPlayer() && !con.bSupportsMP)
			{
				Log("Screenplay::Condition  attempted to include non-multiplayer-condition in multiplayer game.");
				_bBroken = true;
				return;
			}
			con.SetParentScreenplay(this);
			con.SetParamString(szParams);
			if (con.GetNumParams() != con.GetNumParamsDefined())
			{
				if (_bDebug)
				{
					Log("Wrong number of parameters. Defined: " $ con.GetNumParamsDefined() $ " Actual: " $ con.GetNumParams());
				}
				_bBroken = true;
			}
			if (!con.ProcessParams())
			{
				if (_bDebug)
				{
					Log("ProcessParams failed for " $ con.Class $ " : " $ szParams);
				}
				_bBroken = true;
			}
			if (!AddCondition(con))
			{
				if (_bDebug)
				{
					Log("Screenplay::Condtion() failed in call to AddCondition()");
				}
				_bBroken = true;
			}
		}
	}
	else
	{
		if (_bDebug)
		{
			Log("Screenplay::Condtion() failed in call to CanAddCondition()");
		}
		_bBroken = true;
	}
	*/
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
	/*
	int32 Size;
	if (_bSceneInit)
	{
		Size = Scenes.Num();
		if (Size == 0)
		{
			Log("ERROR Screenplay::AddDirection - no Scenes!");
			return false;
		}
		return Scenes[Size - 1].AddInitDirection(Dir);
	}
	if (_bSceneEnd)
	{
		Size = Scenes.Num();
		if (Size == 0)
		{
			Log("ERROR Screenplay::AddDirection - no Scenes!");
			return false;
		}
		return Scenes[Size - 1].AddEndDirection(Dir);
	}
	if (_bEvent)
	{
		if (_bGlobalEvents)
		{
			Size = GlobalEvents.Num();
			if (Size == 0)
			{
				Log("ERROR Screenplay::AddDirection - no GlobalEvents!");
				return false;
			}
			return GlobalEvents[Size - 1].AddDirection(Dir);
		}
		else
		{
			Size = Scenes.Num();
			if (Size == 0)
			{
				Log("ERROR Screenplay::AddDirection - no Scenes!");
				return false;
			}
			return Scenes[Size - 1].AddEventDirection(Dir);
		}
	}
	*/
	return false;     //FAKE   /EliZ
}

void AScreenplay::Direction(FString szDir, FString szParams, FName DummyName)
{
	/*
	local Direction Dir;
	if (_bDebug)
	{
		Log("Screenplay::Direction(" $ szDir $ ", " $ szParams $ ")");
	}
	if (CanAddDirection())
	{
		Dir = CreateNewDirection(szDir);
		if (Dir == nullptr)
		{
			if (_bDebug)
			{
				Log("Screenplay::Direction() failed in call to CreateNewDirection()");
			}
			_bBroken = true;
		}
		else
		{
			if (Level.Game.IsMultiPlayer() && !Dir.bSupportsMP)
			{
				Log("Screenplay::Direction  attempted to include non-multiplayer-direction in multiplayer game.");
				_bBroken = true;
				return;
			}
			Dir.SetParentScreenplay(this);
			Dir.SetParamString(szParams);
			if (Dir.GetNumParams() != Dir.GetNumParamsDefined())
			{
				if (_bDebug)
				{
					Log("Wrong number of parameters. Defined: " $ Dir.GetNumParamsDefined() $ " Actual: " $ Dir.GetNumParams());
				}
				_bBroken = true;
			}
			if (!Dir.ProcessParams())
			{
				if (_bDebug)
				{
					Log("ProcessParams failed for " $ Dir.Class $ " : " $ szParams);
				}
				_bBroken = true;
			}
			if (!AddDirection(Dir))
			{
				if (_bDebug)
				{
					Log("Screenplay::Direction() failed in call to AddDirection()");
				}
				_bBroken = true;
			}
		}
	}
	else
	{
		if (_bDebug)
		{
			Log("Screenplay::Direction() failed in call to CanAddDirection()");
		}
		_bBroken = true;
	}
	*/
}
void AScreenplay::PostBeginPlay()
{
	//Super::PostBeginPlay();
	
	//if (Level.debugScreenplay)
	//{
	//	_bDebug = true;
	//}
	_bReady = true;
}
void AScreenplay::Trigger(AActor* Other, APawn* EventInstigator)
{
	if (_bReady)
	{
		_bReady = false;
		if (_bDebug)
		{
			//Log("Screenplay::Trigger() - got PlayerController: " $ Other);
		}
		//if (!Level.Game.IsMultiPlayer())
		//{
		//	_HumanController = PlayerController(Other);
		//}
		//else
		//{
		//	_HumanController = nullptr;
		//}
		Init();
		DumpScreenplay();
		if (_bBroken)
		{
			//Log("**** SCREENPLAY IS BROKEN!! ****");
		}
		else
		{
			//GotoState('RunScreenplay');
		}
	}
}
void AScreenplay::SceneStart(int32 Id)
{
	/*
	int32 Size;
	if (Id < 0)
	{
		if (_bDebug)
		{
			Log("Screenplay::SceneStart() - cannot start an id of " $ Id);
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
				_HumanController.ScreenPrint("SceneStart(" $ Scenes[_iCurScene]._Tag $ ")");
			}
		}
		if (_bDebug)
		{
			Log("**>Screenplay::SceneStart(" $ Id $ ") " $ Scenes[_iCurScene]._Tag);
		}
		Scenes[_iCurScene].SceneStart();
	}
	else
	{
		Log("ERROR Screenplay::SceneStart() - invalid id");
	}
	*/
}
void AScreenplay::SceneFinish(int32 Id)
{
	/*
	int32 Size;
	if (Id < 0)
	{
		if (_bDebug)
		{
			Log("Screenplay::SceneStart() - cannot start an id of " $ Id);
		}
		return;
	}
	if (Id != _iCurScene)
	{
		Log("ERROR Screenplay::SceneFinish() - trying to finish a scene that is not the current scene!");
	}
	Size = Scenes.Num();
	if (Id < Size)
	{
		if (_HumanController != nullptr)
		{
			if (_bDebug)
			{
				_HumanController.ScreenPrint("SceneFinish(" $ Scenes[_iCurScene]._Tag $ ")");
			}
		}
		if (_bDebug)
		{
			Log("**<Screenplay::SceneFinish(" $ Id $ ") " $ Scenes[_iCurScene]._Tag);
		}
		Scenes[Id].SceneFinish();
	}
	else
	{
		Log("ERROR Screenplay::SceneFinish() - invalid id");
	}
	_iCurScene = -1;
	*/
}
void AScreenplay::SceneEnd()
{
	/*
	int32 nextscene;
	int32 Size;
	if (_bDebug)
	{
		Log("Screenplay::SceneEnd()");
	}
	nextscene = _iCurScene + 1;
	SceneFinish(_iCurScene);
	Size = Scenes.Num();
	if (nextscene < Size)
	{
		SceneStart(nextscene);
	}
	*/
}
void AScreenplay::SceneRestart()
{
	if (_bDebug)
	{
		//Log("Screenplay::SceneRestart()");
	}
	SceneStart(_iCurScene);
}
void AScreenplay::SceneJump(FName Tag)
{
	/*
	int32 Id;
	int32 Size;
	int32 Scene;
	if (_bDebug)
	{
		Log("Screenplay::SceneJump(" $ Tag $ ")");
	}
	Id = -1;
	Size = Scenes.Num();
	for (Scene = 0; Scene < Size; Scene++)
	{
		if (Tag == Scenes[Scene].GetTag())
		{
			Id = Scene;
		}
	}
	if (Id == -1)
	{
		if (_bDebug)
		{
			Log("Screenplay::SceneJump(" $ Tag $ ") - scene with tag not found!");
		}
	}
	else
	{
		SceneStart(Id);
	}
	*/
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
	/*
	int32 Size;
	int32 cur;
	_bDebug = Debug;
	Size = GlobalEvents.Num();
	for (cur = 0; cur < Size; cur++)
	{
		GlobalEvents[cur].SetDebug(Debug);
	}
	Size = Scenes.Num();
	for (cur = 0; cur < Size; cur++)
	{
		Scenes[cur].SetDebug(Debug);
	}
	*/
}
void AScreenplay::DumpScreenplay()
{
	/*
	int32 Size;
	int32 cur;
	if (_bDebug)
	{
		Log("**** Screenplay::DumpScreenplay() START ****");
	}
	Size = GlobalEvents.Num();
	if (_bDebug)
	{
		Log("GlobalEvents: " $ Size);
	}
	for (cur = 0; cur < Size; cur++)
	{
		if (_bDebug)
		{
			Log("GlobalEvents[" $ cur $ "] is a " $ GlobalEvents[cur].Class);
		}
		GlobalEvents[cur].DumpEvent();
	}
	Size = Scenes.Num();
	if (_bDebug)
	{
		Log(" ");
		Log("Scenes: " $ Size);
	}
	for (cur = 0; cur < Size; cur++)
	{
		if (_bDebug)
		{
			Log("Scenes[" $ cur $ "] is a " $ Scenes[cur].Class $ " with tag '" $ Scenes[cur]._Tag $ "'");
		}
		Scenes[cur].DumpScene();
		if (_bDebug)
		{
			Log(" ");
		}
	}
	Log("**** Screenplay::DumpScreenplay() FINISH ****");
	*/
}
void AScreenplay::GlobalEventsStart()
{
	/*
	int32 Size;
	int32 cur;
	if (_bDebug)
	{
		Log("Screenplay::GlobalEventsStart()");
	}
	Size = GlobalEvents.Num();
	for (cur = 0; cur < Size; cur++)
	{
		GlobalEvents[cur].EventStart();
	}
	*/
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
	/*
	if (_iCurScene == -1)
	{
		Canvas.DrawText("SCREENPLAY:  NO CURRENT SCENE");
	}
	else
	{
		Canvas.DrawText("SCREENPLAY:  Scene """ $ Scenes[_iCurScene]._Tag $ """");
	}
	YPos += YL;
	Canvas.SetPos(4, YPos);
	*/
}

void AScreenplay::NotifyCheated()
{
	//DebugLog(DEBUG_Warn, "ScreenPlay::NotifyCheated()	Player cheated!");
	bPlayerCheated = true;
}

