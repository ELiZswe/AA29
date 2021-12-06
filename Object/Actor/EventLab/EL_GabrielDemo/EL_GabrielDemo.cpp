// All the original content belonged to the US Army


#include "AA29/Object/Actor/EventLab/EL_GabrielDemo/EL_GabrielDemo.h"

AEL_GabrielDemo::AEL_GabrielDemo()
{

}

/*
State TalkToSFTeam
{
	Function BeginState()
	{
		if (DidHearTeamDemo(0))
		{
			Team[0].Actor.EnableEyeTrack();
		}
		if (DidHearTeamDemo(1))
		{
			Team[1].Actor.EnableEyeTrack();
		}
		if (DidHearTeamDemo(7))
		{
			Team[7].Actor.EnableEyeTrack();
		}
		if (DidHearTeamDemo(2))
		{
			Team[2].Actor.EnableEyeTrack();
		}
		if (DidHearTeamDemo(3))
		{
			Team[3].Actor.EnableEyeTrack();
		}
		if (DidHearTeamDemo(4))
		{
			Team[4].Actor.EnableEyeTrack();
		}
		if (DidHearTeamDemo(5))
		{
			Team[5].Actor.EnableEyeTrack();
		}
		if (DidHearTeamDemo(6))
		{
			Team[6].Actor.EnableEyeTrack();
		}
	}
	Function StartDemo(uint8 TeamIndex)
	{
		PlayerLock(true,false);
		DisableTeamUseTriggers();
		DisableTeamVolTriggers();
	}
	Function FinishDemo(uint8 TeamIndex)
	{
		PlayerLock(false,false);
		SetTeamCode(TeamIndex);
		UpdateTeamUseTrigger(TeamIndex);
		UpdateMissionStatus();
		EnableTeamUseTriggers();
		EnableTeamVolTriggers();
		EnableCrosshair();
	}
	Function StartConversation(uint8 TeamIndex)
	{
		DisableTeamUseTriggers();
		DisableTeamVolTriggers();
		DisableCrosshair();
		Team[TeamIndex].Actor.EnableEyeTrack();
	}
	Function FinishConversation(uint8 TeamIndex)
	{
		PlayerLock(false,false);
		EnableTeamUseTriggers();
		EnableTeamVolTriggers();
		EnableCrosshair();
	}
	Function bool Timer_LSAnim(FName Name)
	{
		int32 i = 0;
		if (Name == 'SFLeader1')
		{
			FinishConversation(0);
			return true;
		}
		if (Name == 'SFLeader2')
		{
			FinishDemo(0);
			return true;
		}
		if (Name == 'SFCommander1')
		{
			FinishDemo(1);
			return true;
		}
		if (Name == 'SFSergeant1')
		{
			FinishDemo(7);
			return true;
		}
		if (Name == 'SFWeapons1')
		{
			FinishDemo(2);
			return true;
		}
		if (Name == 'SFEngineer1')
		{
			FinishDemo(3);
			return true;
		}
		if (Name == 'SFMedical1')
		{
			FinishDemo(4);
			return true;
		}
		if (Name == 'SFCommunications1')
		{
			FinishDemo(5);
			return true;
		}
		if (Name == 'SFIntelligence1')
		{
			FinishDemo(6);
			return true;
		}
		for (i=0; i<SFLeader_Idles.Length; i++)
		{
			if (Name == SFLeader_Idles[i])
			{
				FinishConversation(0);
			}
		}
		for (i=0; i<SFCommander_Idles.Length; i++)
		{
			if (Name == SFCommander_Idles[i])
			{
				FinishConversation(1);
			}
		}
		for (i=0; i<SFSergeant_Idles.Length; i++)
		{
			if (Name == SFSergeant_Idles[i])
			{
				FinishConversation(7);
			}
		}
		for (i=0; i<SFWeapons_Idles.Length; i++)
		{
			if (Name == SFWeapons_Idles[i])
			{
				FinishConversation(2);
			}
		}
		for (i=0; i<SFEngineer_Idles.Length; i++)
		{
			if (Name == SFEngineer_Idles[i])
			{
				FinishConversation(3);
			}
		}
		for (i=0; i<SFMedical_Idles.Length; i++)
		{
			if (Name == SFMedical_Idles[i])
			{
				FinishConversation(4);
			}
		}
		for (i=0; i<SFCommunications_Idles.Length; i++)
		{
			if (Name == SFCommunications_Idles[i])
			{
				FinishConversation(5);
			}
		}
		for (i=0; i<SFIntelligence_Idles.Length; i++)
		{
			if (Name == SFIntelligence_Idles[i])
			{
				FinishConversation(6);
			}
		}
		if (Name == 'SFIntelligence_Idle3')
		{
			PlayLSAnim('SFCommunications_Idle4',Team[5].Actor,1,512);
			Team[5].Actor.EnableEyeTrack();
		}
		if (Name == 'SFCommunications_Idle4')
		{
			PlayLSAnim('SFIntelligence_Idle4',Team[6].Actor,1,512);
		}
		return false;
	}
	Function LoadLevel(uint8 iLevel)
	{
		FString Team0 = "";
		FString Team1 = "";
		FString UIClass = "";
		FString Message = "";
		FString Map = "";
		if (CanEnterLevel(iLevel))
		{
			UIClass="AGP_Interface.AALoadLevelConfirmation";
			Message=Missions[iLevel].LoadMessage;
			Map=Missions[iLevel].MapName;
			Controller.ClientOpenMenu(UIClass,false,Message,Map);
			return;
		}
		if (PlayerIsQualified(iLevel))
		{
			Team0=GetTeamTitle(GetRequiredConversation(iLevel,0));
			Team1=GetTeamTitle(GetRequiredConversation(iLevel,1));
			PlayTip("Speak with the " $ Team0,"and the " $ Team1 $ " to enter this level",5);
		}
		else
		{
			PlayTip("You must complete the " $ GetRequiredTour(iLevel),"tour before you can enter this level",5);
		}
	}
	Function bool LevelTrigger_AVWID_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		LoadLevel(0);
		return true;
	}
	Function bool LevelTrigger_EANDE_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		LoadLevel(1);
		return true;
	}
	Function bool LevelTrigger_LANGUAGE_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		LoadLevel(2);
		return true;
	}
	Function bool LevelTrigger_SURVIVAL_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		LoadLevel(3);
		return true;
	}
	Function bool LevelTrigger_SFWEAPONS_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		LoadLevel(4);
		return true;
	}
	Function bool SF18A_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		if (DidHearTeamDemo(0))
		{
			StartConversation(0);
			PlayLSAnim(SFLeader_Idles[SFLeader_ConvIndex],Team[0].Actor,1,512);
			SFLeader_ConvIndex ++;
			if (SFLeader_ConvIndex >= SFLeader_Idles.Length)
			{
				SFLeader_ConvIndex=0;
			}
		}
		else
		{
			StartDemo(0);
			PlayLSAnim('SFLeader2',Team[0].Actor,1,512);
		}
		return Global.pos1(Trigger,Instigator);
	}
	Function bool SF180_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		if (DidHearTeamDemo(1))
		{
			StartConversation(1);
			PlayLSAnim(SFCommander_Idles[SFCommander_ConvIndex],Team[1].Actor,1,512);
			SFCommander_ConvIndex ++;
			if (SFCommander_ConvIndex >= SFCommander_Idles.Length)
			{
				SFCommander_ConvIndex=0;
			}
		}
		else
		{
			StartDemo(1);
			PlayLSAnim('SFCommander1',Team[1].Actor,1,512);
		}
		return Global.building5M16Target6(Trigger,Instigator);
	}
	Function bool SF18Z_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		if (DidHearTeamDemo(7))
		{
			StartConversation(7);
			PlayLSAnim(SFSergeant_Idles[SFSergeant_ConvIndex],Team[7].Actor,1,512);
			SFSergeant_ConvIndex ++;
			if (SFSergeant_ConvIndex >= SFSergeant_Idles.Length)
			{
				SFSergeant_ConvIndex=0;
			}
		}
		else
		{
			StartDemo(7);
			PlayLSAnim('SFSergeant1',Team[7].Actor,1,512);
		}
		return Global.building5M17Target1(Trigger,Instigator);
	}
	Function bool SF18B_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		if (DidHearTeamDemo(2))
		{
			StartConversation(2);
			PlayLSAnim(SFWeapons_Idles[SFWeapons_ConvIndex],Team[2].Actor,1,512);
			SFWeapons_ConvIndex ++;
			if (SFWeapons_ConvIndex >= SFWeapons_Idles.Length)
			{
				SFWeapons_ConvIndex=0;
			}
		}
		else
		{
			StartDemo(2);
			PlayLSAnim('SFWeapons1',Team[2].Actor,1,512);
		}
		return Global.A(Trigger,Instigator);
	}
	Function bool SF18C_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		if (DidHearTeamDemo(3))
		{
			StartConversation(3);
			PlayLSAnim(SFEngineer_Idles[SFEngineer_ConvIndex],Team[3].Actor,1,512);
			SFEngineer_ConvIndex ++;
			if (SFEngineer_ConvIndex >= SFEngineer_Idles.Length)
			{
				SFEngineer_ConvIndex=0;
			}
		}
		else
		{
			StartDemo(3);
			PlayLSAnim('SFEngineer1',Team[3].Actor,1,512);
		}
		return Global.building5M18Target1(Trigger,Instigator);
	}
	Function bool SF18D_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		if (DidHearTeamDemo(4))
		{
			StartConversation(4);
			PlayLSAnim(SFMedical_Idles[SFMedical_ConvIndex],Team[4].Actor,1,512);
			SFMedical_ConvIndex ++;
			if (SFMedical_ConvIndex >= SFMedical_Idles.Length)
			{
				SFMedical_ConvIndex=0;
			}
		}
		else
		{
			StartDemo(4);
			PlayLSAnim('SFMedical1',Team[4].Actor,1,512);
		}
		return Global.building5M18Target2(Trigger,Instigator);
	}
	Function bool SF18E_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		if (DidHearTeamDemo(5))
		{
			StartConversation(5);
			PlayLSAnim(SFCommunications_Idles[SFCommunications_ConvIndex],Team[5].Actor,1,512);
			SFCommunications_ConvIndex ++;
			if (SFCommunications_ConvIndex >= SFCommunications_Idles.Length)
			{
				SFCommunications_ConvIndex=0;
			}
		}
		else
		{
			StartDemo(5);
			PlayLSAnim('SFCommunications1',Team[5].Actor,1,512);
		}
		return Global.building5M25Target2(Trigger,Instigator);
	}
	Function bool SF18F_UsedBy(AGP_UseTrigger Trigger, Actor Instigator)
	{
		if (DidHearTeamDemo(6))
		{
			StartConversation(6);
			PlayLSAnim(SFIntelligence_Idles[SFIntelligence_ConvIndex],Team[6].Actor,1,512);
			SFIntelligence_ConvIndex ++;
			if (SFIntelligence_ConvIndex >= SFIntelligence_Idles.Length)
			{
				SFIntelligence_ConvIndex=0;
			}
		}
		else
		{
			StartDemo(6);
			PlayLSAnim('SFIntelligence1',Team[6].Actor,1,512);
		}
		return Global.building5M25Target1(Trigger,Instigator);
	}
Begin:
	FadeOutBlack(0.01);
	if (! DidHearTeamDemo(0))
	{
		PlayerLock(true,false);
		FadeInBlack(2);
		PlayTip("Welcome to Camp Mackall","Special Forces Training ",20);
		Sleep(2);
		PlayLSAnim('SFLeader1',Team[0].Actor,1,512);
	}
	else
	{
		FadeInBlack(2);
		PlayTip("Welcome to Camp Mackall","Special Forces Training ",20);
	}
}
*/
