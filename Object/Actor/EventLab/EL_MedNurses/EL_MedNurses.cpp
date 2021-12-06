// All the original content belonged to the US Army


#include "AA29/Object/Actor/EventLab/EL_MedNurses/EL_MedNurses.h"

AEL_MedNurses::AEL_MedNurses()
{

}

/*
State Idle
{
	Function BeginState()
	{
	}
	Function EndState()
	{
	}
	Function bool JoanneTrigger_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		switch(JoanneUseCount)
		{
			case 0:
			PlayLSAnim('J_YoureNot',Joanne,0.75,512);
			JoanneUseCount ++;
			return true;
			case 1:
			PlayLSAnim('J_Class',Joanne,0.75,512);
			JoanneUseCount ++;
			return true;
			case 2:
			PlayLSAnim('J_ThatGuy',Joanne,0.75,512);
			JoanneUseCount ++;
			return true;
			case 3:
			PlayLSAnim('J_Boyfriend',Joanne,0.75,512);
			JoanneUseCount=0;
			return true;
			default:
			return true;
		}
	}
	Function bool NicholeTrigger_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		switch(NicholeUseCount)
		{
			case 0:
			PlayLSAnim('N_Waiting',Nichole,0.75,512);
			NicholeUseCount ++;
			return true;
			case 1:
			PlayLSAnim('N_Class',Nichole,0.75,512);
			NicholeUseCount ++;
			return true;
			case 2:
			PlayLSAnim('N_Help',Nichole,0.75,512);
			NicholeUseCount ++;
			return true;
			case 3:
			PlayLSAnim('N_Married',Nichole,0.75,512);
			NicholeUseCount ++;
			return true;
			case 4:
			PlayLSAnim('N_Busy',Nichole,0.75,512);
			NicholeUseCount=0;
			return true;
			default:
			return true;
		}
	}
	Function bool NurseConvVolume_Enter(AGP_Gameplay.TriggerVolume Trigger, Actor Instigator)
	{
		switch(ConversationCount)
		{
			case 0:
			ConversationCount ++;
			ChangeState('Date');
			return true;
			case 1:
			ConversationCount ++;
			ChangeState('Groceries');
			return true;
			case 2:
			ConversationCount ++;
			ChangeState('Macho');
			return true;
			case 3:
			ConversationCount ++;
			ChangeState('Break');
			return true;
			case 4:
			ConversationCount ++;
			ChangeState('Housing');
			return true;
			case 5:
			ConversationCount ++;
			ChangeState('Lunch');
			return true;
			case 6:
			ConversationCount ++;
			ChangeState('Movie');
			return true;
			case 7:
			ConversationCount ++;
			ChangeState('PCS');
			return true;
			case 8:
			ConversationCount=0;
			ChangeState('pX');
			return true;
			default:
			return true;
		}
	}
}
State Date
{
	Function BeginState()
	{
		UnCaptureEventGroup('NurseConvVolume');
		StartTimer('Date_Start',0.5,false);
	}
	Function EndState()
	{
		CaptureEventGroup('NurseConvVolume');
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'Date_Start':
			Date_Start();
			return true;
			case 'Date_PT2':
			Date_PT2();
			return true;
			case 'Date_End':
			Date_End();
			return true;
			default:
			return false;
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case 'J1_Date':
			StartTimer('Date_PT2',0.5,false);
			return true;
			case 'N2_Date':
			StartTimer('Date_End',0.1);
			return true;
			default:
			return false;
		}
	}
	Function Date_Start()
	{
		PlayLSAnim('J1_Date',Joanne,0.75,512);
	}
	Function Date_PT2()
	{
		PlayLSAnim('N2_Date',Nichole,0.75,512);
	}
	Function Date_End()
	{
		ChangeState('Idle');
	}
}
State Groceries
{
	Function BeginState()
	{
		UnCaptureEventGroup('NurseConvVolume');
		StartTimer('Groceries_Start',0.5);
	}
	Function EndState()
	{
		CaptureEventGroup('NurseConvVolume');
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'Groceries_Start':
			Groceries_Start();
			return true;
			case 'Groceries_PT2':
			Groceries_PT2();
			return true;
			case 'Groceries_End':
			Groceries_End();
			return true;
			default:
			return false;
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case 'J1_Groceries':
			StartTimer('Groceries_PT2',0.5,false);
			return true;
			case 'N2_Groceries':
			StartTimer('Groceries_End',0.1,false);
			return true;
			default:
			return false;
		}
	}
	Function Groceries_Start()
	{
		PlayLSAnim('J1_Groceries',Joanne,0.75,512);
	}
	Function Groceries_PT2()
	{
		PlayLSAnim('N2_Groceries',Nichole,0.75,512);
	}
	Function Groceries_End()
	{
		ChangeState('Idle');
	}
}
State Macho
{
	Function BeginState()
	{
		UnCaptureEventGroup('NurseConvVolume');
		StartTimer('Macho_Start',0.5);
	}
	Function EndState()
	{
		CaptureEventGroup('NurseConvVolume');
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'Macho_Start':
			Macho_Start();
			return true;
			case 'Macho_PT2':
			Macho_PT2();
			return true;
			case 'Macho_End':
			Macho_End();
			return true;
			default:
			return false;
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case 'J1_Macho':
			StartTimer('Macho_PT2',0.5,false);
			return true;
			case 'N2_Macho':
			StartTimer('Macho_End',0.1,false);
			return true;
			default:
			return false;
		}
	}
	Function Macho_Start()
	{
		PlayLSAnim('J1_Macho',Nichole,0.75,512);
	}
	Function Macho_PT2()
	{
		PlayLSAnim('N2_Macho',Joanne,0.75,512);
	}
	Function Macho_End()
	{
		ChangeState('Idle');
	}
}
State Break
{
	Function BeginState()
	{
		UnCaptureEventGroup('NurseConvVolume');
		StartTimer('Break_Start',0.5);
	}
	Function EndState()
	{
		CaptureEventGroup('NurseConvVolume');
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'Break_Start':
			Break_Start();
			return true;
			case 'Break_PT2':
			Break_PT2();
			return true;
			case 'Break_End':
			Break_End();
			return true;
			default:
			return false;
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case 'N1_Break':
			StartTimer('Break_PT2',0.5,false);
			return true;
			case 'J2_Break':
			StartTimer('Break_End',0.1,false);
			return true;
			default:
			return false;
		}
	}
	Function Break_Start()
	{
		PlayLSAnim('N1_Break',Nichole,0.75,512);
	}
	Function Break_PT2()
	{
		PlayLSAnim('J2_Break',Joanne,0.75,512);
	}
	Function Break_End()
	{
		ChangeState('Idle');
	}
}
State Housing
{
	Function BeginState()
	{
		UnCaptureEventGroup('NurseConvVolume');
		StartTimer('Housing_Start',0.5);
	}
	Function EndState()
	{
		CaptureEventGroup('NurseConvVolume');
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'Housing_Start':
			Housing_Start();
			return true;
			case 'Housing_PT2':
			Housing_PT2();
			return true;
			case 'Housing_End':
			Housing_End();
			return true;
			default:
			return false;
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case 'N1_Housing':
			StartTimer('Housing_PT2',0.5,false);
			return true;
			case 'J2_Housing':
			StartTimer('Housing_End',0.1,false);
			return true;
			default:
			return false;
		}
	}
	Function Housing_Start()
	{
		PlayLSAnim('N1_Housing',Nichole,0.75,512);
	}
	Function Housing_PT2()
	{
		PlayLSAnim('J2_Housing',Joanne,0.75,512);
	}
	Function Housing_End()
	{
		ChangeState('Idle');
	}
}
State Lunch
{
	Function BeginState()
	{
		UnCaptureEventGroup('NurseConvVolume');
		StartTimer('Lunch_Start',0.5);
	}
	Function EndState()
	{
		CaptureEventGroup('NurseConvVolume');
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'Lunch_Start':
			Lunch_Start();
			return true;
			case 'Lunch_PT2':
			Lunch_PT2();
			return true;
			case 'Lunch_End':
			Lunch_End();
			return true;
			default:
			return false;
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case 'N1_Lunch':
			StartTimer('Lunch_PT2',0.5,false);
			return true;
			case 'J2_Lunch':
			StartTimer('Lunch_End',0.1,false);
			return true;
			default:
			return false;
		}
	}
	Function Lunch_Start()
	{
		PlayLSAnim('N1_Lunch',Nichole,0.75,512);
	}
	Function Lunch_PT2()
	{
		PlayLSAnim('J2_Lunch',Joanne,0.75,512);
	}
	Function Lunch_End()
	{
		ChangeState('Idle');
	}
}
State Movie
{
	Function BeginState()
	{
		UnCaptureEventGroup('NurseConvVolume');
		StartTimer('Movie_Start',0.5);
	}
	Function EndState()
	{
		CaptureEventGroup('NurseConvVolume');
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'Movie_Start':
			Movie_Start();
			return true;
			case 'Movie_PT2':
			Movie_PT2();
			return true;
			case 'Movie_End':
			Movie_End();
			return true;
			default:
			return false;
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case 'N1_Movie':
			StartTimer('Movie_PT2',0.5,false);
			return true;
			case 'J2_Movie':
			StartTimer('Movie_End',0.1,false);
			return true;
			default:
			return false;
		}
	}
	Function Movie_Start()
	{
		PlayLSAnim('N1_Movie',Nichole,0.75,512);
	}
	Function Movie_PT2()
	{
		PlayLSAnim('J2_Movie',Joanne,0.75,512);
	}
	Function Movie_End()
	{
		ChangeState('Idle');
	}
}
State PCS
{
	Function BeginState()
	{
		UnCaptureEventGroup('NurseConvVolume');
		StartTimer('PCS_Start',0.5);
	}
	Function EndState()
	{
		CaptureEventGroup('NurseConvVolume');
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'PCS_Start':
			PCS_Start();
			return true;
			case 'PCS_PT2':
			PCS_PT2();
			return true;
			case 'PCS_End':
			PCS_End();
			return true;
			default:
			return false;
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case 'N1_PCS':
			StartTimer('PCS_PT2',0.5,false);
			return true;
			case 'J2_PCS':
			StartTimer('PCS_End',0.1,false);
			return true;
			default:
			return false;
		}
	}
	Function PCS_Start()
	{
		PlayLSAnim('N1_PCS',Nichole,0.75,512);
	}
	Function PCS_PT2()
	{
		PlayLSAnim('J2_PCS',Joanne,0.75,512);
	}
	Function PCS_End()
	{
		ChangeState('Idle');
	}
}
State pX
{
	Function BeginState()
	{
		UnCaptureEventGroup('NurseConvVolume');
		StartTimer('PX_Start',0.5);
	}
	Function EndState()
	{
		CaptureEventGroup('NurseConvVolume');
	}
	Function bool Timer_Timer(FName Name)
	{
		switch(Name)
		{
			case 'PX_Start':
			PX_Start();
			return true;
			case 'PX_PT2':
			PX_PT2();
			return true;
			case 'PX_End':
			PX_End();
			return true;
			default:
			return false;
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		switch(Name)
		{
			case 'N1_PX':
			StartTimer('PX_PT2',0.5,false);
			return true;
			case 'J2_PX':
			StartTimer('PX_End',0.1,false);
			return true;
			default:
			return false;
		}
	}
	Function PX_Start()
	{
		PlayLSAnim('N1_PX',Nichole,0.75,512);
	}
	Function PX_PT2()
	{
		PlayLSAnim('J2_PX',Joanne,0.75,512);
	}
	Function PX_End()
	{
		ChangeState('Idle');
	}
}
*/
