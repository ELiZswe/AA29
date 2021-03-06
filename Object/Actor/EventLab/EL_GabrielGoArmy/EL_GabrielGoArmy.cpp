// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_GabrielGoArmy/EL_GabrielGoArmy.h"
#include "AA29/Object/Actor/AGP_UseTrigger/AGP_UseTrigger.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/HttpGet/HttpGet.h"
#include "AA29/Object/Actor/LinksParser/LinksParser.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/NPC_SpecialForces/NPC_SpecialForces.h"

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
		for (i=0; i<_Http.RequestedText.Num(); i++)
		{
			Log(_Http.RequestedText[i]);
		}
		Log("---------------------");
	}
Begin:
	_Http=EstablishHttp();
	if (_Http != nullptr)
	{
		_Http.RequestText("boomstick.com","/ezekiel/gabrielgoarmy.txt");
	}
	else
	{
		Log("EL_GabrielGoArmy: State " + FString::FromInt(GetCurrentState()) + ": _Http Is None");
	}
	Sleep(5);
	Log("EL_GabrielGoArmy: State " + FString::FromInt(GetCurrentState()) + ": _Http Timed Out");
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
	if (_Links != nullptr)
	{
		ChangeState("AssignLinks");
	}
	else
	{
		Log("EL_GabrielGoArmy: State " + FString::FromInt(GetCurrentState()) + ": _Links Is None");
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
		Log("SECTIONS LENGTH: " + FString::FromInt(_Links.Sections.Num()));
		for (i=0; i<_Links.Sections.Num(); i++)
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
		for (i=0; i<URLTriggers.Num(); i++)
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
	//Controller.ClientOpenMenu("AGP_Interface.AAGabrielGoArmyLinks", false, FString::FromInt(this), "");
	return true;
}

void AEL_GabrielGoArmy::PreInit()
{
	//GoArmyGuy = Cast<ANPC_SpecialForces>(GetActor('GoArmyGuy'));
	//GoArmyGuy_Trigger = Cast<ATriggerVolume>(CaptureEvent('GoArmyGuy_Trigger'));
	//UseTrigger_GoArmyGuy = Cast<AAGP_UseTrigger>(CaptureEvent('UseTrigger_GoArmyGuy'));
	//Trigger_GOARMY = Cast<AAGP_UseTrigger>(CaptureEvent('Trigger_GOARMY'));
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
	AHttpGet* MyHttp = nullptr;
	/*
	MyHttp = Spawn(AHttpGet::StaticClass());
	if (MyHttp != nullptr)
	{
		Log("EL_GabrielGoArmy::EstablishTCP(): HttpGet Spawned");
		MyHttp.SetEventLab(this);
		return MyHttp;
	}
	else
	{
		Log("EL_GabrielGoArmy::EstablishTCP(): HttpGet spawn failed");
		return nullptr;
	}
	*/

	return nullptr;   //FAKE    /ELiZ
}

ALinksParser* AEL_GabrielGoArmy::ParseLinks()
{
	ALinksParser* MyLinks = nullptr;
	/*
	MyLinks = Spawn(ALinksParser::StaticClass());
	if (MyLinks != nullptr)
	{
		MyLinks.Init(GetBaseDir() + "GabrielGoArmy.txt");
		return MyLinks;
	}
	else
	{
		Log("EL_GabrielGoArmy::GetLinks(): LinksParser spawn failed");
		return nullptr;
	}
	*/

	return nullptr;    //FAKE   /ELiZ
}

void AEL_GabrielGoArmy::WriteLinks()
{
	/*
	bool FileSuccess = false;
	int32 i = 0;
	if (_Http.RequestedText.Num() == 0)
	{
		Log("EL_GabrielGoArmy::WriteLinks(): Error: RequestedText is empty: No links to write");
		return;
	}
	FileSuccess = FOpenWrite(GetBaseDir() + "GabrielGoArmy.txt");
	if (FileSuccess)
	{
		for (i = 0; i < _Http.RequestedText.Num(); i++)
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
	if (_Http != nullptr)
	{
		_Http.HardClose();
		_Http.Destroy();
		_Http = nullptr;
	}
	if (_Links != nullptr)
	{
		_Links.Destroy();
		_Links = nullptr;
	}
	*/
}
