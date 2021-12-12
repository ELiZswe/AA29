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
			ChangeState("GetLinks");
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
	ChangeState("BeginSomething");
}
*/

/*
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
		ChangeState("AssignLinks");
	}
	else
	{
		Log("EL_GabrielGoArmy: State " $ string(GetCurrentState()) $ ": _Links Is None");
		ChangeState("BeginRecruiter");
	}
}
*/

/*
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
	ChangeState("BeginSomething");
}
*/

/*
State BeginSomething
{
}
*/

static const float HTTPTIMEOUT = 5.0;

ALinksParser* AEL_GabrielGoArmy::GetLinksParser()
{
	return _Links;
}

bool AEL_GabrielGoArmy::TriggerVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case 'GoArmyGuy_Trigger':
		return GoArmyGuy_Trigger_Enter(Trigger, Instigator);
	default:
		return false;
	}
	*/
	return false; //FAKE   /ELiZ
}

bool AEL_GabrielGoArmy::GoArmyGuy_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	//Log("GoArmyGuy_Trigger_Enter");
	return true;
}

bool AEL_GabrielGoArmy::TriggerVolume_Exit(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case 'GoArmyGuy_Trigger':
		return GoArmyGuy_Trigger_Exit(Trigger, Instigator);
	default:
		return false;
	}
	*/
	return false; //FAKE   /ELiZ
}

bool AEL_GabrielGoArmy::GoArmyGuy_Trigger_Exit(ATriggerVolume* Trigger, AActor* aInstigator)
{
	//Log("GoArmyGuy_Trigger_Exit");
	return true;
}

bool AEL_GabrielGoArmy::AGP_UseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case 'Trigger_GOARMY':
		return Trigger_GOARMY_UsedBy(Trigger, Instigator);
	case 'UseTrigger_GoArmyGuy':
		return GoArmyGuy_UsedBy(Trigger, Instigator);
	default:
		return false;
	}
	*/
	return false; //FAKE   /ELiZ
}

bool AEL_GabrielGoArmy::Trigger_GOARMY_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	//Log("Trigger_GOARMY_UsedBy");
	return true;
}

bool AEL_GabrielGoArmy::GoArmyGuy_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	//Log("GoArmyGuy_UsedBy");
	//Controller.ClientOpenMenu("AGP_Interface.AAGabrielGoArmyLinks", false, string(Self), "");
	return true;
}

void AEL_GabrielGoArmy::PreInit()
{
	//GoArmyGuy = NPC_SpecialForces(GetActor('GoArmyGuy'));
	//GoArmyGuy_Trigger = TriggerVolume(CaptureEvent('GoArmyGuy_Trigger'));
	//UseTrigger_GoArmyGuy = AGP_UseTrigger(CaptureEvent('UseTrigger_GoArmyGuy'));
	//Trigger_GOARMY = AGP_UseTrigger(CaptureEvent('Trigger_GOARMY'));
}

void AEL_GabrielGoArmy::Init()
{
}

void AEL_GabrielGoArmy::PostInit()
{
}

void AEL_GabrielGoArmy::PostPostInit()
{
	//ChangeState('GetHttp');
}

void AEL_GabrielGoArmy::DestroyHttp()
{
	/*
	if (_Http != nullptr)
	{
		_Http->HardClose();
		_Http->Destroy();
		_Http = nullptr;
	}
	*/
}

AHttpGet* AEL_GabrielGoArmy::EstablishHttp()
{
	/*
	local IpDrv.HttpGet MyHttp;
	MyHttp = Spawn(Class'IpDrv.HttpGet');
	if (MyHttp != None)
	{
		Log("EL_GabrielGoArmy::EstablishTCP(): HttpGet Spawned");
		MyHttp.SetEventLab(Self);
		return MyHttp;
	}
	else
	{
		Log("EL_GabrielGoArmy::EstablishTCP(): HttpGet spawn failed");
		return None;
	}
	*/

	return nullptr;   //FAKE    /ELiZ
}

ALinksParser* AEL_GabrielGoArmy::ParseLinks()
{
	/*
	local LinksParser MyLinks;
	MyLinks = Spawn(class'AGP_Script.LinksParser');
	if (MyLinks != None)
	{
		MyLinks.Init(GetBaseDir() $ "GabrielGoArmy.txt");
		return MyLinks;
	}
	else
	{
		Log("EL_GabrielGoArmy::GetLinks(): LinksParser spawn failed");
		return None;
	}
	*/

	return nullptr;    //FAKE   /ELiZ
}

void AEL_GabrielGoArmy::WriteLinks()
{
	/*
	bool FileSuccess = false;
	int32 i = 0;
	if (_Http.RequestedText.Length == 0)
	{
		Log("EL_GabrielGoArmy::WriteLinks(): Error: RequestedText is empty: No links to write");
		return;
	}
	FileSuccess = FOpenWrite(GetBaseDir() $ "GabrielGoArmy.txt");
	if (FileSuccess)
	{
		for (i = 0; i < _Http.RequestedText.Length; i++)
		{
			FWrite(_Http.RequestedText[i]);
		}
	}
	else
	{
		Log("EL_GabrielGoArmy::WriteLinks(): File Error");
		return;
	}
	FileSuccess = FClose();
	if (FileSuccess)
	{
		Log("EL_GabrielGoArmy::WriteLinks(): Links Written Successfully");
		return;
	}
	else
	{
		Log("EL_GabrielGoArmy::WriteLinks(): File Error");
		return;
	}
	*/
}

bool AEL_GabrielGoArmy::Timer_Timer(FName Name)
{
	return false;
}

void AEL_GabrielGoArmy::Destroyed()
{
	/*
	if (_Http != None)
	{
		_Http.HardClose();
		_Http.Destroy();
		_Http = None;
	}
	if (_Links != None)
	{
		_Links.Destroy();
		_Links = None;
	}
	*/
}
