// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AARecordBriefSubPanel/AARecordBriefSubPanel.h"

UAARecordBriefSubPanel::UAARecordBriefSubPanel()
{
	MAX_CONNECTION_ATTEMPTS = 3;
}

void UAARecordBriefSubPanel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	UpdateHeaderWithUserName();
	ResultCode = 0;
	*/
}

void UAARecordBriefSubPanel::ShowPanel(bool bShow)
{
	/*
	Super::ShowPanel(bShow);
	UpdateHeaderWithUserName();
	*/
}

void UAARecordBriefSubPanel::UpdateHeaderWithUserName()
{
	/*
	if (AAGUIController(Controller).bLoggedIn)
	{
		if (InStr(Class'AGP.HumanController'.Default.UserName, ",") == -1)
		{
			h_Header.SetCaption(LoggedInPanelText $ HumanController(PlayerOwner()).UserName);
		}
		else
		{
			h_Header.SetCaption(LoggedInPanelText $ HumanController(PlayerOwner()).sSavedUserName);
		}
	}
	else
	{
		h_Header.SetCaption(DefaultPanelText);
	}
	*/
}

void UAARecordBriefSubPanel::InternalOnGetRecordBriefComplete(int32 Result, FRecordBriefStruct Brief)
{
	/*
	ResultCode = Result;
	if (ResultCode != 1)
	{
		if (RecordBriefAttempts <= MAX_CONNECTION_ATTEMPTS)
		{
			RequestRecordBrief();
		}
		else
		{
			ProcessRecordBriefError();
		}
	}
	else
	{
		RecordBrief = Brief;
		ProcessRecordBriefData();
	}
	*/
}

void UAARecordBriefSubPanel::RequestRecordBrief()
{
	/*
	local DBAuth.GetRecordBriefRequestAdapter Adapter;
	local Actor SpawningActor;
	local HumanController HC;
	SpawningActor = FindActor();
	if ((SpawningActor != None) && AAGUIController(Controller).bLoggedIn)
	{
		RecordBriefAttempts++;
		Adapter = SpawningActor.Spawn(Class'DBAuth.GetRecordBriefRequestAdapter');
		Adapter.__dOnGetRecordBriefComplete__Delegate = InternalOnGetRecordBriefComplete;
		HC = HumanController(PlayerOwner());
		HC.ClientRefreshDistributionHistory();
		Adapter.Request(HC.UserName, HumanController(PlayerOwner()).UserPassword, Class'IpDrv.InternetLink'.GetLocalIPAsString(), HC.DistributionHistory);
	}
	*/
}

void UAARecordBriefSubPanel::ProcessRecordBriefData()
{
}

void UAARecordBriefSubPanel::ProcessRecordBriefError()
{
}

int32 UAARecordBriefSubPanel::CalculateExperience(int32 CurrentHonor)
{
	switch (CurrentHonor)
	{
		case  0:	return 0;
		case  1:	return 500;
		case  2:	return 1000;
		case  3:	return 1500;
		case  4:	return 2000;
		case  5:	return 2500;
		case  6:	return 3000;
		case  7:	return 3500;
		case  8:	return 4000;
		case  9:	return 4500;
		case  10:	return 5000;
		case  11:	return 6000;
		case  12:	return 7000;
		case  13:	return 8000;
		case  14:	return 9000;
		case  15:	return 10000;
		case  16:	return 11000;
		case  17:	return 12000;
		case  18:	return 13000;
		case  19:	return 14000;
		case  20:	return 15000;
		case  21:	return 17500;
		case  22:	return 20000;
		case  23:	return 22500;
		case  24:	return 25000;
		case  25:	return 27500;
		case  26:	return 30000;
		case  27:	return 32500;
		case  28:	return 35000;
		case  29:	return 37500;
		case  30:	return 40000;
		case  31:	return 44000;
		case  32:	return 48000;
		case  33:	return 52000;
		case  34:	return 56000;
		case  35:	return 60000;
		case  36:	return 64000;
		case  37:	return 68000;
		case  38:	return 72000;
		case  39:	return 76000;
		case  40:	return 80000;
		case  41:	return 86000;
		case  42:	return 92000;
		case  43:	return 98000;
		case  44:	return 104000;
		case  45:	return 110000;
		case  46:	return 116000;
		case  47:	return 122000;
		case  48:	return 128000;
		case  49:	return 134000;
		case  50:	return 140000;
		case  51:	return 149000;
		case  52:	return 158000;
		case  53:	return 167000;
		case  54:	return 176000;
		case  55:	return 185000;
		case  56:	return 194000;
		case  57:	return 203000;
		case  58:	return 212000;
		case  59:	return 221000;
		case  60:	return 230000;
		case  61:	return 243000;
		case  62:	return 256000;
		case  63:	return 269000;
		case  64:	return 282000;
		case  65:	return 295000;
		case  66:	return 308000;
		case  67:	return 321000;
		case  68:	return 334000;
		case  69:	return 347000;
		case  70:	return 360000;
		case  71:	return 383000;
		case  72:	return 406000;
		case  73:	return 429000;
		case  74:	return 452000;
		case  75:	return 475000;
		case  76:	return 498000;
		case  77:	return 521000;
		case  78:	return 544000;
		case  79:	return 567000;
		case  80:	return 590000;
		case  81:	return 633000;
		case  82:	return 676000;
		case  83:	return 719000;
		case  84:	return 762000;
		case  85:	return 805000;
		case  86:	return 848000;
		case  87:	return 891000;
		case  88:	return 934000;
		case  89:	return 977000;
		case  90:	return 1020000;
		case  91:	return 1103000;
		case  92:	return 1186000;
		case  93:	return 1269000;
		case  94:	return 1352000;
		case  95:	return 1435000;
		case  96:	return 1518000;
		case  97:	return 1601000;
		case  98:	return 1684000;
		case  99:	return 1767000;
		case  100:	return 1850000;
	default:
		return 0;
	}

}

int32 UAARecordBriefSubPanel::CalculateExperienceNeeded(int32 CurrentExperience, int32 CurrentHonor)
{
	//return (CalculateExperience((CurrentHonor + 1)) - CurrentExperience);
	return -1;    //FAKE   /ELiZ
}

AActor* UAARecordBriefSubPanel::FindActor()
{
	/*
	local Actor SomeActor;
	ForEach AllObjects(Class'Actor', SomeActor)
	{
		return SomeActor;
	}
	*/
	return nullptr;
}