// All the original content belonged to the US Army
// =====================================================================
// AGP class Screenplay
// author: mpr
// =====================================================================
// this is the main class of the scripting system
// screenplay is a subclass of actor so it can use the actor functions like AllActor
// so the classes it owns don't need to do that
//
// =====================================================================

/*
//	Screenplay is the main class of the scripting system.
//	Level designers would subclass this this and override the Init() function with their scenes, events, etc.
//  LD's would only use the functions provided to them in this class.  They do not worry about any other classes.
//	When LD's need new conditions/directions, a condition/direction subclass would need to be created in
//	addition to a Dir_/Cond_ function in this class.  Also any special new objects may need to also be created
//	mainly for conditions.  (See AGP_Timer and AGP_Sound)  The Actor class now has a SetTarget() function which
//	takes a ScriptObject (or more specifically a subclass of Condition) and you would call the ScriptObject's
//	Notify() function to tell it that the condition has been met.
*/

/*
//	The Screenplay is started by AGP_GameInfo in its s PostBeginPlay function.  It searches the level for any
//	objects that are screenplays and calls the Trigger() function.  It only calls the first one; subsequent
//  screenplays are ignored.  The Trigger function calls the Init()
//	function which creates the screen play and then jumps to the RunScreenplay state.  This state is there
//	to give a break since there was a glitch with sounds not being triggered in the first scene.  The state
//	will end after a Sleep(0) and then the GlobalEvents and first Scene are started.
*/

/*
//  Only certain conditions and directions are allowed in Multiplayer; they have their bSupportMP flag set
//  to true.  (It is false by default.)  If a screenplay in a multiplayer game that contains a scriptobject
//  that doesn't support multiplay, the screenplay is considered broken.
*/


// SCREENPLAY

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Screenplay.generated.h"

class UCondition;
class UDirection;
class UBillboardComponent;
class USceneComponent;
class UScriptEvent;
class UScriptScene;

UCLASS()
class AA29_API AScreenplay : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScreenplay();

	UPROPERTY(EditAnywhere)							TArray<UScriptEvent*> GlobalEvents;				//var() array<ScriptEvent> GlobalEvents;			// may not need this
	UPROPERTY(EditAnywhere)							TArray<UScriptScene*> Scenes;						//var() array<ScriptScene> Scenes;
	UPROPERTY()										bool _bGlobalEvents;							//var bool _bGlobalEvents;							// bool to state that we are in the process of creating a global event
	UPROPERTY()										bool _bGlobalEventsDone;						//var bool _bGlobalEventsDone;						// bool to make sure we dont create global events in more than one place
	UPROPERTY()										bool _bEvent;									//var bool _bEvent;									// bool to state that we are in the process of creating an event
	UPROPERTY()										bool _bScene;									//var bool _bScene;									// bool to state that we are in the process of creating a scene
	UPROPERTY()										bool _bSceneInit;								//var bool _bSceneInit;								// bool to state that we are in the process of creating a scene init
	UPROPERTY()										bool _bSceneEnd;								//var bool _bSceneEnd;								// bool to start that we are in the process of creating a scene end
	UPROPERTY()										bool _bReady;									//var bool _bReady;									// ready bool to allow starting of screenplay
	UPROPERTY()										int32 _iCurScene;								//var int _iCurScene;								// current scene

	UPROPERTY()										APlayerController* _HumanController;			//var PlayerController _HumanController;			// we need this to act out functions on the player in single player mode

	UPROPERTY()										bool _bDebug;									//var bool _bDebug;									// log
	UPROPERTY()										bool _bBroken;									//var bool _bBroken;								// this flag gets set if the script is broken to prevent running it

	UPROPERTY()										bool bPlayerCheated;							//var bool bPlayerCheated;							// Don't let a player authorize if they cheated.
	UPROPERTY()										TArray<FName> RememberedScenes;					//var name RememberedScenes;						// List of scenes that can be "remembered" and recalled.

	UPROPERTY()										UBillboardComponent* SpriteComponent;
	UPROPERTY()										USceneComponent* ScreenplayRoot;

	void SetRememberedScene(FName SceneName, int32 Index);
	void GetRememberedScene(int32 Index);
	void Destroyed();
	void Init();
	void Draw(UCanvas* Canvas);
	void SetActor(int32 Type, AActor* Actor);
	void SetGlobalEvents();
	void EndGlobalEvents();
	void NewEvent();
	void EndEvent();
	void Event_ConditionsAnd();
	void Event_ConditionsOr();
	void Event_RunOnceGlobal(bool Status);
	void Event_RunOncePerScene(bool Status);
	void Event_Repeats();
	void NewScene(FName scenetag);
	void EndScene();
	void SceneInit_Start();
	void SceneInit_Finish();
	void SceneEnd_Start();
	void SceneEnd_Finish();
	bool CanAddCondition();
	void AddCondition(UCondition* con);
	void Condition(FString szCon, FString szParams);
	bool CanAddDirection();
	void AddDirection(UDirection* Dir);
	void Direction(FString szDir, FString szParams, FName DummyName);
	void PostBeginPlay();
	void Trigger(AActor* Other, APawn* EventInstigator);
	void SceneStart(int32 Id);
	void SceneFinish(int32 Id);
	void SceneEnd();
	void SceneRestart();
	void SceneJump(FName Tag);
	void SceneStop();
	void CreateNewEvent();
	void CreateNewScene();
	void CreateNewDirection(FString Dir);
	void CreateNewCondition(FString con);
	void SetDebug(bool Debug);
	void DumpScreenplay();
	void GlobalEventsStart();
	APlayerController* GetHumanController();
	AController* GetControllerList();
	//void DisplayDebug(UCanvas* Canvas, float &YL, float &YPos);
	void NotifyCheated();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



};
