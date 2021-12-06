// All the original content belonged to the US Army


#include "AA29/Object/Actor/EventLab/EL_SFWeapons_Range/EL_SFWeapons_Range.h"

AEL_SFWeapons_Range::AEL_SFWeapons_Range()
{

}

/*
State Waiting
{
	Function BeginState()
	{
	}
	Function bool AGP_UseTrigger_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		switch(Trigger.Tag)
		{
			case 'PracticeCadreTrigger':
			return Practice_UsedBy(Trigger,Instigator);
			ChangeState('Practice_Intro');
			break;
			case 'RifleCadreTrigger':
			return Rifle_UsedBy(Trigger,Instigator);
			ChangeState('Rifle_Intro');
			break;
			case 'GrenadeCadreTrigger':
			return Grenade_UsedBy(Trigger,Instigator);
			ChangeState('Grenade_Intro');
			break;
			case 'RocketCadreTrigger':
			return Rocket_UsedBy(Trigger,Instigator);
			ChangeState('Rocket_Intro');
			break;
			default:
			return false;
		}
	}
	Function bool TriggerVolume_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		switch(Trigger.Tag)
		{
			case 'PracticeChallengeVolume':
			return PracticeChallengeVolume_Enter(Trigger,Instigator);
			break;
			case 'RifleChallengeVolume':
			break;
			case 'GrenadeChallengeVolume':
			break;
			case 'RocketChallengeVolume':
			break;
			default:
			return false;
		}
		return true;
	}
Begin:
	if (! LevelStarted)
	{
		LevelStarted=true;
		FadeIn(5,true);
	}
	Sleep(4);
	PlayTip("Walk to any station and talk to the Cadre","to begin the training.",10);
}
State Practice_Intro
{
	Function BeginState()
	{
		PlayTip("Welcome to the Practice Station.","This is a fun one!",10);
	}
	Function bool TriggerVolume_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		switch(Trigger.Tag)
		{
			case 'Practice_Downrange':
			return DownrangeVolume_Enter(Trigger,Instigator);
			break;
			case 'Practice_Leaving':
			return LeavingVolume_Enter(Trigger,Instigator);
			break;
			default:
			return false;
		}
		return true;
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'Downrange')
		{
			PlayTip("Practice Station Ended...","Bummer.",2);
			ChangeState('Waiting');
			return true;
		}
		else
		{
			if (Name == 'Leaving')
			{
				PlayTip("Practice Station Ended...","Bummer.",2);
				ChangeState('Waiting');
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
State Practice_Start
{
	Function BeginState()
	{
		PlayTip("Walk to any station and talk to the Cadre","to begin the training.",10);
	}
}
State Practice_End
{
	Function BeginState()
	{
		PlayTip("Walk to any station and talk to the Cadre","to begin the training.",10);
	}
}
State Rifle_Intro
{
	Function BeginState()
	{
		PlayTip("Welcome to the Rifle Station.","This is a fun one!",10);
	}
	Function bool TriggerVolume_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		switch(Trigger.Tag)
		{
			case 'Rifle_Downrange':
			return DownrangeVolume_Enter(Trigger,Instigator);
			break;
			case 'Rifle_Leaving':
			return LeavingVolume_Enter(Trigger,Instigator);
			break;
			default:
			return false;
		}
		return true;
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'Downrange')
		{
			PlayTip("Rifle Station Ended...","Bummer.",2);
			ChangeState('Waiting');
			return true;
		}
		else
		{
			if (Name == 'Leaving')
			{
				PlayTip("Rifle Station Ended...","Bummer.",2);
				ChangeState('Waiting');
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
State Rifle_Start
{
	Function BeginState()
	{
		PlayTip("Walk to any station and talk to the Cadre","to begin the training.",10);
	}
}
State Rifle_End
{
	Function BeginState()
	{
		PlayTip("Walk to any station and talk to the Cadre","to begin the training.",10);
	}
}
State Grenade_Intro
{
	Function BeginState()
	{
		PlayTip("Welcome to the Grenade Station.","This is a fun one!",10);
	}
	Function bool TriggerVolume_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		switch(Trigger.Tag)
		{
			case 'Grenade_Downrange':
			return DownrangeVolume_Enter(Trigger,Instigator);
			break;
			case 'Grenade_Leaving':
			return LeavingVolume_Enter(Trigger,Instigator);
			break;
			default:
			return false;
		}
		return true;
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'Downrange')
		{
			PlayTip("Grenade Station Ended...","Bummer.",2);
			ChangeState('Waiting');
			return true;
		}
		else
		{
			if (Name == 'Leaving')
			{
				PlayTip("Grenade Station Ended...","Bummer.",2);
				ChangeState('Waiting');
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
State Grenade_Start
{
	Function BeginState()
	{
		PlayTip("Walk to any station and talk to the Cadre","to begin the training.",10);
	}
}
State Grenade_End
{
	Function BeginState()
	{
		PlayTip("Walk to any station and talk to the Cadre","to begin the training.",10);
	}
}
State Rocket_Intro
{
	Function BeginState()
	{
		PlayTip("Welcome to the Rocket Station.","This is a fun one!",10);
	}
	Function bool TriggerVolume_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		switch(Trigger.Tag)
		{
			case 'Rocket_Downrange':
			return DownrangeVolume_Enter(Trigger,Instigator);
			break;
			case 'Rocket_Leaving':
			return LeavingVolume_Enter(Trigger,Instigator);
			break;
			default:
			return false;
		}
		return true;
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == 'Downrange')
		{
			PlayTip("Rocket Station Ended...","Bummer.",2);
			ChangeState('Waiting');
			return true;
		}
		else
		{
			if (Name == 'Leaving')
			{
				PlayTip("Rocket Station Ended...","Bummer.",2);
				ChangeState('Waiting');
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
State Rocket_Start
{
	Function BeginState()
	{
		PlayTip("Walk to any station and talk to the Cadre","to begin the training.",10);
	}
}
State Rocket_End
{
	Function BeginState()
	{
		PlayTip("Walk to any station and talk to the Cadre","to begin the training.",10);
	}
}
*/
