// All the original content belonged to the US Army


#include "AA29/Object/Actor/Screenplay/Screenplay.h"
#include "Components/BillboardComponent.h"

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

// Called when the game starts or when spawned
void AScreenplay::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AScreenplay::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



/*
State RunScreenplay
{
	void EndState()
	{
		if (_bDebug)
		{
			Log("Screenplay::EndState() - state RunScreenplay");
		}
		GlobalEventsStart();
		SceneStart(0);
	}
	void BeginState()
	{
		if (_bDebug)
		{
			Log("Screenplay::BeginState() - state RunScreenplay");
		}
	}
}
*/

void AScreenplay::SetRememberedScene(FName SceneName, int32 Index)
{
	/*
	if (Index >= 10)
	{
		Log("Screenplay::SetRememberedScene(): Error: Index out of range");
		Return;
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
void AScreenplay::GetRememberedScene(int32 Index)
{
	/*
	if (Index >= 10)
	{
		Log("ScreenPlay::GetRememberedScene(): Error: RememberedScene Index out of range, returning name 'None'");
		Return 'None';
	}
	else
	{
		Return RememberedScenes[Index];
	}
	*/
}
void AScreenplay::Destroyed()
{
	/*
	local int Counter;
	Super::Destroyed();
	_HumanController = None;
	for (Counter = 0; Counter < GlobalEvents.Length; Counter++)
	{
		GlobalEvents[Counter].Destroyed();
	}
	for (Counter = 0; Counter < Scenes.Length; Counter++)
	{
		Scenes[Counter].Destroyed();
	}
	GlobalEvents.remove(0, GlobalEvents.Length);
	Scenes.remove(0, Scenes.Length);
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
		Return;
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
	local int Size;
	if (_bDebug)
	{
		Log("Screenplay::NewEvent()");
	}
	if (_bEvent)
	{
		Log("ERROR Screenplay::NewEvent - called without a previous EndEvent");
		Return;
	}
	_bEvent = true;
	if (_bGlobalEvents)
	{
		Size = GlobalEvents.Length;
		GlobalEvents[Size] = CreateNewEvent();
		GlobalEvents[Size].SetParentScreenplay(Self);
	}
	else
	{
		Size = Scenes.Length;
		if (Size == 0)
		{
			Log("ERROR Screenplay::NewEvent - no Scenes to add non global event to!");
			Return;
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
	local int Size;
	if (!_bEvent)
	{
		Log("ERROR Screenplay::Event_ConditionsAnd - called without a previous NewEvent");
		Return;
	}
	if (_bGlobalEvents)
	{
		Size = GlobalEvents.Length;
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
		Size = Scenes.Length;
		if (Size == 0)
		{
			Log("ERROR Screenplay::Event_ConditionsAnd() - no Scenes to SetEventConditionAnd() event to!");
			Return;
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
	local int Size;
	if (!_bEvent)
	{
		Log("ERROR Screenplay::Event_ConditionsOr - called without a previous NewEvent");
		Return;
	}
	if (_bGlobalEvents)
	{
		Size = GlobalEvents.Length;
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
		Size = Scenes.Length;
		if (Size == 0)
		{
			Log("ERROR Screenplay::Event_ConditionsOr() - no Scenes to SetEventConditionOr() event to!");
			Return;
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
	local int Size;
	Log("Screenplay::Event_RunOnce()");
	if (!_bEvent)
	{
		Log("ERROR Screenplay::Event_RunOnce() - called without a previous NewEvent");
		Return;
	}
	if (_bGlobalEvents)
	{
		Size = GlobalEvents.Length;
		if (Size == 0)
		{
			Log("ERROR Screenplay::Event_RunOnce() - no events");
		}
		GlobalEvents[Size - 1].SetRunOnceGlobal(Status);
	}
	else
	{
		Size = Scenes.Length;
		if (Size == 0)
		{
			Log("ERROR Screenplay::Event_RunOnce() - no Scenes to RunOnce() event to!");
			Return;
		}
		Scenes[Size - 1].SetEventRunOnceGlobal(Status);
	}
	*/
}
void AScreenplay::Event_RunOncePerScene(bool Status)
{
	/*
	local int Size;
	Log("Screenplay::Event_RunOnce()");
	if (!_bEvent)
	{
		Log("ERROR Screenplay::Event_RunOnce() - called without a previous NewEvent");
		Return;
	}
	if (_bGlobalEvents)
	{
		Size = GlobalEvents.Length;
		if (Size == 0)
		{
			Log("ERROR Screenplay::Event_RunOnce() - no events");
		}
		GlobalEvents[Size - 1].SetRunOncePerScene(Status);
	}
	else
	{
		Size = Scenes.Length;
		if (Size == 0)
		{
			Log("ERROR Screenplay::Event_RunOnce() - no Scenes to RunOnce() event to!");
			Return;
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
	local int Size;
	if (_bDebug)
	{
		Log("Screenplay::NewScene(" $ scenetag $ ")");
	}
	if (_bScene)
	{
		Log("ERROR Screenplay::NewScene - called without a previous EndScene");
		Return;
	}
	_bScene = true;
	Size = Scenes.Length;
	Scenes[Size] = CreateNewScene();
	Scenes[Size].SetTag(scenetag);
	Scenes[Size].SetParentScreenplay(Self);
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
void AScreenplay::AddCondition(UCondition* con)
{
	/*
	local int Size;
	if (_bEvent)
	{
		if (_bGlobalEvents)
		{
			Size = GlobalEvents.Length;
			if (Size == 0)
			{
				Log("ERROR Screenplay::AddCondition - no GlobalEvents!");
				Return False;
			}
			Return GlobalEvents[Size - 1].AddCondition(con);
		}
		else
		{
			Size = Scenes.Length;
			if (Size == 0)
			{
				Log("ERROR Screenplay::AddCondition - no Scenes!");
				Return False;
			}
			Return Scenes[Size - 1].AddEventCondition(con);
		}
	}
	*/
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
		if (con == None)
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
				Return;
			}
			con.SetParentScreenplay(Self);
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
void AScreenplay::AddDirection(UDirection* Dir)
{
	/*
	local int Size;
	if (_bSceneInit)
	{
		Size = Scenes.Length;
		if (Size == 0)
		{
			Log("ERROR Screenplay::AddDirection - no Scenes!");
			Return False;
		}
		Return Scenes[Size - 1].AddInitDirection(Dir);
	}
	if (_bSceneEnd)
	{
		Size = Scenes.Length;
		if (Size == 0)
		{
			Log("ERROR Screenplay::AddDirection - no Scenes!");
			Return False;
		}
		Return Scenes[Size - 1].AddEndDirection(Dir);
	}
	if (_bEvent)
	{
		if (_bGlobalEvents)
		{
			Size = GlobalEvents.Length;
			if (Size == 0)
			{
				Log("ERROR Screenplay::AddDirection - no GlobalEvents!");
				Return False;
			}
			Return GlobalEvents[Size - 1].AddDirection(Dir);
		}
		else
		{
			Size = Scenes.Length;
			if (Size == 0)
			{
				Log("ERROR Screenplay::AddDirection - no Scenes!");
				Return False;
			}
			Return Scenes[Size - 1].AddEventDirection(Dir);
		}
	}
	*/
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
		if (Dir == None)
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
				Return;
			}
			Dir.SetParentScreenplay(Self);
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
	local int Size;
	if (Id < 0)
	{
		if (_bDebug)
		{
			Log("Screenplay::SceneStart() - cannot start an id of " $ Id);
		}
		Return;
	}
	if (_iCurScene != -1)
	{
		SceneFinish(_iCurScene);
	}
	Size = Scenes.Length;
	if (Id < Size)
	{
		_iCurScene = Id;
		if (_HumanController != None)
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
	local int Size;
	if (Id < 0)
	{
		if (_bDebug)
		{
			Log("Screenplay::SceneStart() - cannot start an id of " $ Id);
		}
		Return;
	}
	if (Id != _iCurScene)
	{
		Log("ERROR Screenplay::SceneFinish() - trying to finish a scene that is not the current scene!");
	}
	Size = Scenes.Length;
	if (Id < Size)
	{
		if (_HumanController != None)
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
	local int nextscene;
	local int Size;
	if (_bDebug)
	{
		Log("Screenplay::SceneEnd()");
	}
	nextscene = _iCurScene + 1;
	SceneFinish(_iCurScene);
	Size = Scenes.Length;
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
	local int Id;
	local int Size;
	local int Scene;
	if (_bDebug)
	{
		Log("Screenplay::SceneJump(" $ Tag $ ")");
	}
	Id = -1;
	Size = Scenes.Length;
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
void AScreenplay::CreateNewEvent()
{
	/*
	local ScriptEvent myEvent;
	local class<ScriptEvent>  cEvent;
	cEvent = class<ScriptEvent>(DynamicLoadObject("Engine.ScriptEvent", Class'Class'));
	myEvent = new (None) classcEvent;
	Return myEvent;
	*/
}
void AScreenplay::CreateNewScene()
{
	/*
	local ScriptScene myScene;
	local class<ScriptScene>  cScene;
	cScene = class<ScriptScene>(DynamicLoadObject("Engine.ScriptScene", Class'Class'));
	myScene = new (None) classcScene;
	Return myScene;
	*/
}
void AScreenplay::CreateNewDirection(FString Dir)
{
	/*
	local Direction myDirection;
	local class<Direction>  cDirection;
	cDirection = class<Direction>(DynamicLoadObject(Dir, Class'Class'));
	myDirection = new (None) classcDirection;
	Return myDirection;
	*/
}
void AScreenplay::CreateNewCondition(FString con)
{
	/*
	local Condition myCondition;
	local class<Condition>  cCondition;
	cCondition = class<Condition>(DynamicLoadObject(con, Class'Class'));
	myCondition = new (None) classcCondition;
	Return myCondition;
	*/
}
void AScreenplay::SetDebug(bool Debug)
{
	/*
	local int Size;
	local int cur;
	_bDebug = Debug;
	Size = GlobalEvents.Length;
	for (cur = 0; cur < Size; cur++)
	{
		GlobalEvents[cur].SetDebug(Debug);
	}
	Size = Scenes.Length;
	for (cur = 0; cur < Size; cur++)
	{
		Scenes[cur].SetDebug(Debug);
	}
	*/
}
void AScreenplay::DumpScreenplay()
{
	/*
	local int Size;
	local int cur;
	if (_bDebug)
	{
		Log("**** Screenplay::DumpScreenplay() START ****");
	}
	Size = GlobalEvents.Length;
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
	Size = Scenes.Length;
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
	local int Size;
	local int cur;
	if (_bDebug)
	{
		Log("Screenplay::GlobalEventsStart()");
	}
	Size = GlobalEvents.Length;
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
/*
void AScreenplay::DisplayDebug(UCanvas* Canvas, float &YL, float &YPos)
{
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
}
*/
void AScreenplay::NotifyCheated()
{
	//DebugLog(DEBUG_Warn, "ScreenPlay::NotifyCheated()	Player cheated!");
	bPlayerCheated = true;
}


