// All the original content belonged to the US Army


#include "AA29/Object/Actor/EventLab/EL_GabrielGoArmy/EL_GabrielGoArmy.h"

AEL_GabrielGoArmy::AEL_GabrielGoArmy()
{
}

/*
State GetHttp
{
	Function BeginState()
	{
	}
	Function EndState()
	{
	}
	Function bool HttpGet_HttpGet(IpDrv.HttpGet MyHttp, Actor Instigator, FString Parms)
	{
		switch(Parms)
		{
			case "Closed":
			DebugHttp();
			WriteLinks();
			ChangeState('GetLinks');
			return true;
			default:
			return false;
		}
	}
	Function DebugHttp()
	{
		int32 i = 0;
		Log("---------------------");
		Log("REQUESTED TEXT");
		Log("---------------------");
		for (i=0; i<_Http.RequestedText.Length; i++)
		{
			Log(_Http.RequestedText[i]);
		}
		Log("---------------------");
	}
Begin:
	_Http=EstablishHttp();
	if (_Http != None)
	{
		_Http.RequestText("boomstick.com","/ezekiel/gabrielgoarmy.txt");
	}
	else
	{
		Log("EL_GabrielGoArmy: State " $ string(GetCurrentState()) $ ": _Http Is None");
	}
	Sleep(5);
	Log("EL_GabrielGoArmy: State " $ string(GetCurrentState()) $ ": _Http Timed Out");
	DestroyHttp();
	_HttpError=true;
	ChangeState('BeginSomething');
}
State GetLinks
{
	Function BeginState()
	{
	}
	Function EndState()
	{
	}
Begin:
	_Links=ParseLinks();
	if (_Links != None)
	{
		ChangeState('AssignLinks');
	}
	else
	{
		Log("EL_GabrielGoArmy: State " $ string(GetCurrentState()) $ ": _Links Is None");
		ChangeState('BeginRecruiter');
	}
}
State AssignLinks
{
	Function BeginState()
	{
	}
	Function EndState()
	{
	}
	Function DebugLinks()
	{
		int32 i = 0;
		Log("---------------------");
		Log("SECTIONS LENGTH: " $ string(_Links.Sections.Length));
		for (i=0; i<_Links.Sections.Length; i++)
		{
			Log("---------------------");
			Log(_Links.Sections[i].Header);
			Log(_Links.Sections[i].Id);
			Log(_Links.Sections[i].Display);
			Log(_Links.Sections[i].Caption);
			Log(_Links.Sections[i].URL);
		}
	}
	Function bool IsIndexError(int32 Index)
	{
		return (Index < 0);
	}
	Function PutLinks()
	{
		int32 i = 0;
		int32 SI = 0;
		for (i=0; i<URLTriggers.Length; i++)
		{
			if (URLTriggers[i].bDynamicLink)
			{
				SI=_Links.GetIDIndex(URLTriggers[i].DynamicLinkName);
				if (! IsIndexError(SI))
				{
					URLTriggers[i].HUDText=_Links.Sections[SI].Display;
					URLTriggers[i].Caption=_Links.Sections[SI].Caption;
					URLTriggers[i].URL=_Links.Sections[SI].URL;
				}
			}
		}
	}
Begin:
	PutLinks();
	Sleep(1);
	DebugLinks();
	ChangeState('BeginSomething');
}
State BeginSomething
{
}
*/
