// All the original content belonged to the US Army

#include "AA29/Object/ScriptScene/ScriptScene.h"
#include "AA29/Object/Actor/Screenplay/Screenplay.h"
#include "AA29/Object/ScriptObject/Condition/Condition.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "AA29/Object/ScriptEvent/ScriptEvent.h"

UScriptScene::UScriptScene()
{

}

void UScriptScene::Destroyed()
{
	/*
	int32 Counter;
	_ParentScreenplay = nullptr;
	for (Counter = 0; Counter < InitDirs.Num(); Counter++)
	{
		InitDirs[Counter].Destroyed();
	}
	for (Counter = 0; Counter < Events.Num(); Counter++)
	{
		Events[Counter].Destroyed();
	}
	for (Counter = 0; Counter < EndDirs.Num(); Counter++)
	{
		EndDirs[Counter].Destroyed();
	}
	InitDirs.RemoveAt(0, InitDirs.Num());
	Events.RemoveAt(0, Events.Num());
	EndDirs.RemoveAt(0, EndDirs.Num());
	*/
}
void UScriptScene::SceneStart()
{
	/*
	if (_bDebug)
	{
		Log("Scene::SceneStart() - calling EventsStart()");
	}
	_bFinished = false;
	EventsStart();
	if (_bDebug)
	{
		Log("Scene::SceneStart() - calling RunInitDirs()");
	}
	RunInitDirs();
	*/
}
void UScriptScene::SceneFinish()
{
	/*
	_bFinished = true;
	EventsFinish();
	RunEndDirs();
	*/
}
void UScriptScene::EventsStart()
{
	/*
	int32 Size;
	int32 cur;
	Size = Events.Num();
	for (cur = 0; cur < Size; cur++)
	{
		Events[cur].EventStart();
	}
	*/
}
void UScriptScene::EventsFinish()
{
	/*
	int32 Size;
	int32 cur;
	Size = Events.Num();
	for (cur = 0; cur < Size; cur++)
	{
		Events[cur].EventFinish();
	}
	*/
}
void UScriptScene::RunInitDirs()
{
	/*
	int32 Size;
	int32 cur;
	Size = InitDirs.Num();
	for (cur = 0; cur < Size; cur++)
	{
		if (!_bFinished)
		{
			InitDirs[cur].Start();
		}
	}
	*/
}
void UScriptScene::RunEndDirs()
{
	/*
	int32 Size;
	int32 cur;
	Size = EndDirs.Num();
	for (cur = 0; cur < Size; cur++)
	{
		EndDirs[cur].Start();
	}
	*/
}

bool UScriptScene::AddEvent(UScriptEvent* sEvent)
{
	/*
	int32 Size;
	Size = Events.Num();
	Events[Size] = sEvent;
	Events[Size].SetParentScreenplay(_ParentScreenplay);
	*/
	return true;
}

bool UScriptScene::AddInitDirection(UDirection* Dir)
{
	/*
	int32 Size;
	Size = InitDirs.Num();
	InitDirs[Size] = Dir;
	InitDirs[Size].SetParentScreenplay(_ParentScreenplay);
	*/
	return true;
}

bool UScriptScene::AddEndDirection(UDirection* Dir)
{
	/*
	int32 Size;
	Size = EndDirs.Num();
	EndDirs[Size] = Dir;
	EndDirs[Size].SetParentScreenplay(_ParentScreenplay);
	*/
	return true;
}

bool UScriptScene::AddEventCondition(UCondition* con)
{
	/*
	int32 Size;
	Size = Events.Num();
	if (Size == 0)
	{
		Log("ERROR Scene::AddEventCondition - no events!");
		return false;
	}
	return Events[Size - 1].AddCondition(con);
	*/
	return false;     //FAKE   /EliZ
}

bool UScriptScene::AddEventDirection(UDirection* Dir)
{
	/*
	int32 Size;
	Size = Events.Num();
	if (Size == 0)
	{
		Log("ERROR Scene::AddEventDirection - no events!");
		return false;
	}
	return Events[Size - 1].AddDirection(Dir);
	*/
	return false;     //FAKE   /EliZ
}

bool UScriptScene::SetEventConditionAnd()
{
	/*
	int32 Size;
	Size = Events.Num();
	if (Size == 0)
	{
		Log("ERROR Scene::SetEventConditionAnd - no events!");
		return false;
	}
	return Events[Size - 1].SetConditionAnd();
	*/
	return false;     //FAKE   /EliZ
}

bool UScriptScene::SetEventConditionOr()
{
	/*
	int32 Size;
	Size = Events.Num();
	if (Size == 0)
	{
		Log("ERROR Scene::SetEventConditionOr - no events!");
		return false;
	}
	return Events[Size - 1].SetConditionOr();
	*/
	return false;     //FAKE   /EliZ
}

void UScriptScene::SetEventRunOnceGlobal(bool Status)
{
	/*
	int32 Size;
	Size = Events.Num();
	if (Size == 0)
	{
		Log("ERROR Scene::SetEventRunOnceGlobal - no events!");
		return;
	}
	Events[Size - 1].SetRunOnceGlobal(Status);
	*/
}
void UScriptScene::SetEventRunOncePerScene(bool Status)
{
	/*
	int32 Size;
	Size = Events.Num();
	if (Size == 0)
	{
		Log("ERROR Scene::SetEventRunOncePerScene - no events!");
		return;
	}
	Events[Size - 1].SetRunOncePerScene(Status);
	*/
}
void UScriptScene::SetTag(FName Tag)
{
	_Tag = Tag;
}

FName UScriptScene::GetTag()
{
	return _Tag;
}

void UScriptScene::SetParentScreenplay(AScreenplay* Parent)
{
	_ParentScreenplay = Parent;
}

void UScriptScene::SetDebug(bool Debug)
{
	/*
	int32 Size;
	int32 cur;
	_bDebug = Debug;
	Size = InitDirs.Num();
	for (cur = 0; cur < Size; cur++)
	{
		InitDirs[cur].SetDebug(Debug);
	}
	Size = Events.Num();
	for (cur = 0; cur < Size; cur++)
	{
		Events[cur].SetDebug(Debug);
	}
	Size = EndDirs.Num();
	for (cur = 0; cur < Size; cur++)
	{
		EndDirs[cur].SetDebug(Debug);
	}
	*/
}

void UScriptScene::DumpScene()
{
	/*
	int32 Size;
	int32 cur;
	Size = InitDirs.Num();
	if (_bDebug)
	{
		Log("  InitDirs: " + Size);
	}
	for (cur = 0; cur < Size; cur++)
	{
		if (_bDebug)
		{
			Log("    InitDirs[" + cur + "] is a " + InitDirs[cur].Class);
		}
	}
	Size = Events.Num();
	if (_bDebug)
	{
		Log("  Events: " + Size);
	}
	for (cur = 0; cur < Size; cur++)
	{
		if (_bDebug)
		{
			Log("  Events[" + cur + "] is a " + Events[cur].Class);
		}
		Events[cur].DumpEvent();
	}
	Size = EndDirs.Num();
	if (_bDebug)
	{
		Log("  EndDirs: " + Size);
	}
	for (cur = 0; cur < Size; cur++)
	{
		if (_bDebug)
		{
			Log("    EndDirs[" + cur + "] is a " + EndDirs[cur].Class);
		}
	}
	*/
}
