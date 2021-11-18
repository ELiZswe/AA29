// All the original content belonged to the US Army


#include "AA29/Object/ScriptScene/ScriptScene.h"

UScriptScene::UScriptScene()
{

}

void UScriptScene::Destroyed()
{
	/*
	local int Counter;
	_ParentScreenplay = None;
	for (Counter = 0; Counter < InitDirs.Length; Counter++)
	{
		InitDirs[Counter].Destroyed();
	}
	for (Counter = 0; Counter < Events.Length; Counter++)
	{
		Events[Counter].Destroyed();
	}
	for (Counter = 0; Counter < EndDirs.Length; Counter++)
	{
		EndDirs[Counter].Destroyed();
	}
	InitDirs.remove(0, InitDirs.Length);
	Events.remove(0, Events.Length);
	EndDirs.remove(0, EndDirs.Length);
	*/
}
void UScriptScene::SceneStart()
{
	/*
	if (_bDebug)
	{
		Log("Scene::SceneStart() - calling EventsStart()");
	}
	_bFinished = False;
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
	local int Size;
	local int cur;
	Size = Events.Length;
	for (cur = 0; cur < Size; cur++)
	{
		Events[cur].EventStart();
	}
	*/
}
void UScriptScene::EventsFinish()
{
	/*
	local int Size;
	local int cur;
	Size = Events.Length;
	for (cur = 0; cur < Size; cur++)
	{
		Events[cur].EventFinish();
	}
	*/
}
void UScriptScene::RunInitDirs()
{
	/*
	local int Size;
	local int cur;
	Size = InitDirs.Length;
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
	local int Size;
	local int cur;
	Size = EndDirs.Length;
	for (cur = 0; cur < Size; cur++)
	{
		EndDirs[cur].Start();
	}
	*/
}
/*
void UScriptScene::AddEvent(UScriptEvent* sEvent)
{
	local int Size;
	Size = Events.Length;
	Events[Size] = sEvent;
	Events[Size].SetParentScreenplay(_ParentScreenplay);
	Return True;
}
	*/
void UScriptScene::AddInitDirection(UDirection* Dir)
{
	/*
	local int Size;
	Size = InitDirs.Length;
	InitDirs[Size] = Dir;
	InitDirs[Size].SetParentScreenplay(_ParentScreenplay);
	Return True;
	*/
}
void UScriptScene::AddEndDirection(UDirection* Dir)
{
	/*
	local int Size;
	Size = EndDirs.Length;
	EndDirs[Size] = Dir;
	EndDirs[Size].SetParentScreenplay(_ParentScreenplay);
	Return True;
	*/
}
void UScriptScene::AddEventCondition(UCondition* con)
{
	/*
	local int Size;
	Size = Events.Length;
	if (Size == 0)
	{
		Log("ERROR Scene::AddEventCondition - no events!");
		Return False;
	}
	Return Events[Size - 1].AddCondition(con);
	*/
}
void UScriptScene::AddEventDirection(UDirection* Dir)
{
	/*
	local int Size;
	Size = Events.Length;
	if (Size == 0)
	{
		Log("ERROR Scene::AddEventDirection - no events!");
		Return False;
	}
	Return Events[Size - 1].AddDirection(Dir);
	*/
}
void UScriptScene::SetEventConditionAnd()
{
	/*
	local int Size;
	Size = Events.Length;
	if (Size == 0)
	{
		Log("ERROR Scene::SetEventConditionAnd - no events!");
		Return False;
	}
	Return Events[Size - 1].SetConditionAnd();
	*/
}
void UScriptScene::SetEventConditionOr()
{
	/*
	local int Size;
	Size = Events.Length;
	if (Size == 0)
	{
		Log("ERROR Scene::SetEventConditionOr - no events!");
		Return False;
	}
	Return Events[Size - 1].SetConditionOr();
	*/
}
void UScriptScene::SetEventRunOnceGlobal(bool Status)
{
	/*
	local int Size;
	Size = Events.Length;
	if (Size == 0)
	{
		Log("ERROR Scene::SetEventRunOnceGlobal - no events!");
		Return;
	}
	Events[Size - 1].SetRunOnceGlobal(Status);
	*/
}
void UScriptScene::SetEventRunOncePerScene(bool Status)
{
	/*
	local int Size;
	Size = Events.Length;
	if (Size == 0)
	{
		Log("ERROR Scene::SetEventRunOncePerScene - no events!");
		Return;
	}
	Events[Size - 1].SetRunOncePerScene(Status);
	*/
}
void UScriptScene::SetTag(FName Tag)
{
	_Tag = Tag;
}
void UScriptScene::GetTag()
{
	//Return _Tag;
}
/*
void UScriptScene::SetParentScreenplay(UScreenplay* Parent)
{
	//_ParentScreenplay = Parent;
}
*/
void UScriptScene::SetDebug(bool Debug)
{
	/*
	local int Size;
	local int cur;
	_bDebug = Debug;
	Size = InitDirs.Length;
	for (cur = 0; cur < Size; cur++)
	{
		InitDirs[cur].SetDebug(Debug);
	}
	Size = Events.Length;
	for (cur = 0; cur < Size; cur++)
	{
		Events[cur].SetDebug(Debug);
	}
	Size = EndDirs.Length;
	for (cur = 0; cur < Size; cur++)
	{
		EndDirs[cur].SetDebug(Debug);
	}
	*/
}
void UScriptScene::DumpScene()
{
	/*
	local int Size;
	local int cur;
	Size = InitDirs.Length;
	if (_bDebug)
	{
		Log("  InitDirs: " $ Size);
	}
	for (cur = 0; cur < Size; cur++)
	{
		if (_bDebug)
		{
			Log("    InitDirs[" $ cur $ "] is a " $ InitDirs[cur].Class);
		}
	}
	Size = Events.Length;
	if (_bDebug)
	{
		Log("  Events: " $ Size);
	}
	for (cur = 0; cur < Size; cur++)
	{
		if (_bDebug)
		{
			Log("  Events[" $ cur $ "] is a " $ Events[cur].Class);
		}
		Events[cur].DumpEvent();
	}
	Size = EndDirs.Length;
	if (_bDebug)
	{
		Log("  EndDirs: " $ Size);
	}
	for (cur = 0; cur < Size; cur++)
	{
		if (_bDebug)
		{
			Log("    EndDirs[" $ cur $ "] is a " $ EndDirs[cur].Class);
		}
	}
	*/
}