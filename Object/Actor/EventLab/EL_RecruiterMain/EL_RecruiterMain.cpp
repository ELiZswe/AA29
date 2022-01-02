// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_RecruiterMain/EL_RecruiterMain.h"

AEL_RecruiterMain::AEL_RecruiterMain()
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
	Function bool HttpGet_HttpGet(IpDrv.HttpGet* MyHttp, AActor* Instigator, FString Parms)
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
	if (_Http != nullptr)
	{
		_Http.RequestText("boomstick.com","/ezekiel/RecruiterGoArmy.txt");
	}
	else
	{
		Log("EL_RecruiterMain: State " $ string(GetCurrentState()) $ ": _Http Is None");
	}
	Sleep(10);
	Log("EL_RecruiterMain: State " $ string(GetCurrentState()) $ ": _Http Timed Out");
	DestroyHttp();
	_HttpError=true;
	ChangeState("GetLinks");
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
	if (_Links != nullptr)
	{
		ChangeState("AssignLinks");
	}
	else
	{
		Log("EL_RecruiterMain: State " $ string(GetCurrentState()) $ ": _Links Is None");
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
	ChangeState("BeginRecruiter");
}
*/

/*
State BeginRecruiter
{
}
*/

bool AEL_RecruiterMain::TriggerVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case "VolumeBuilding":
		return VolumeBuilding_Enter(Trigger, Instigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_RecruiterMain::TriggerVolume_Exit(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case "VolumeBuilding":
		return VolumeBuilding_Exit(Trigger, Instigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

void AEL_RecruiterMain::PreInit()
{
	/*
	local AGP_Gameplay.TriggerURL t;
	VolumeBuilding = TriggerVolume(CaptureEvent("VolumeBuilding"));
	ForEach AllActors(Class'AGP_Gameplay.TriggerURL', t)
	{
		URLTriggers[URLTriggers.Length] = t;
	}
	*/
}

void AEL_RecruiterMain::Init()
{
}

void AEL_RecruiterMain::PostInit()
{
}

void AEL_RecruiterMain::PostPostInit()
{
	/*
	Player.ClientSetViewRotation(GetActorRotation("AGP_PlayerStart"));
	ChangeState("GetHttp");
	*/
}

void AEL_RecruiterMain::DestroyHttp()
{
	/*
	if (_Http != None)
	{
		_Http.HardClose();
		_Http.Destroy();
		_Http = nullptr;
	}
	*/
}

AHttpGet* AEL_RecruiterMain::EstablishHttp()
{
	/*
	local IpDrv.HttpGet MyHttp;
	MyHttp = Spawn(Class'IpDrv.HttpGet');
	if (MyHttp != None)
	{
		Log("EL_RecruiterMain::EstablishTCP(): HttpGet Spawned");
		MyHttp.SetEventLab(Self);
		return MyHttp;
	}
	else
	{
		Log("EL_RecruiterMain::EstablishTCP(): HttpGet spawn failed");
		return None;
	}
	*/
	return nullptr;    //FAKE   /ELiZ
}

ALinksParser* AEL_RecruiterMain::ParseLinks()
{
	/*
	local LinksParser MyLinks;
	MyLinks = Spawn(class'AGP_Script.LinksParser');
	if (MyLinks != None)
	{
		MyLinks.Init(GetBaseDir() $ "RecruiterGoArmy.txt");
		return MyLinks;
	}
	else
	{
		Log("EL_RecruiterMain::GetLinks(): LinksParser spawn failed");
		return None;
	}
	*/
	return nullptr;    //FAKE   /EliZ
}

void AEL_RecruiterMain::WriteLinks()
{
	/*
	bool FileSuccess = false;
	int32 i = 0;
	if (_Http.RequestedText.Length == 0)
	{
		Log("EL_RecruiterMain::WriteLinks(): Error: RequestedText is empty: No links to write");
		return;
	}
	FileSuccess = FOpenWrite(GetBaseDir() $ "RecruiterGoArmy.txt");
	if (FileSuccess)
	{
		for (i = 0; i < _Http.RequestedText.Length; i++)
		{
			FWrite(_Http.RequestedText[i]);
		}
	}
	else
	{
		Log("EL_RecruiterMain::WriteLinks(): File Error");
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

bool AEL_RecruiterMain::Timer_Timer(FName Name)
{
	return false;
}

bool AEL_RecruiterMain::VolumeBuilding_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	EnableCrosshair();
	return true;
}

bool AEL_RecruiterMain::VolumeBuilding_Exit(ATriggerVolume* Trigger, AActor* aInstigator)
{
	DisableCrosshair();
	return true;
}

void AEL_RecruiterMain::Destroyed()
{
	/*
	if (_Http != None)
	{
		_Http.HardClose();
		_Http.Destroy();
		_Http = nullptr;
	}
	if (_Links != None)
	{
		_Links.Destroy();
		_Links = nullptr;
	}
	*/
}
