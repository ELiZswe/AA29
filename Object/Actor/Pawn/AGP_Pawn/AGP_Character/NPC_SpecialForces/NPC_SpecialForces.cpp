// All the original content belonged to the US Army


#include "NPC_SpecialForces.h"

ANPC_SpecialForces::ANPC_SpecialForces()
{
	NPC_DamageOn           = true;
	bStaticSkinsAndMeshes  = true;
	KillHealth             = 100;
	AnimRate               = 1;
	bCleanUp               = false;
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/SoldierM_Infantry_ClassB.SoldierM_Infantry_ClassB"), NULL, LOAD_None, NULL);
	LoadMesh();


	
	
	LeaderLipsinc.SetNum(LEADER_IDLE_SAY);
	CommanderLipsinc.SetNum(COMMANDER_IDLE_SAY);
	SergeantLipsinc.SetNum(SERGEANT_IDLE_SAY);
	WeaponsLipsinc.SetNum(WEAPONS_IDLE_SAY);
	EngineerLipsinc.SetNum(ENGINEER_IDLE_SAY);
	MedicalLipsinc.SetNum(MEDICAL_IDLE_SAY);
	CommunicationLipsinc.SetNum(COMMUNICATION_IDLE_SAY);
	IntelligenceLipsinc.SetNum(INTELLIGENCE_IDLE_SAY);
	StudentVendingMachineLipsinc.SetNum(STUDENT_VENDING_MACHINE_IDLE_SAY);
	SargGoToClassLipsinc.SetNum(SARG_GO_TO_CLASS_IDLE_SAY);
	SargGetInTruckLipsinc.SetNum(SARG_GET_IN_TRUCK_IDLE_SAY);

	LeaderSound.SetNum(LEADER_IDLE_SAY);
	CommanderSound.SetNum(COMMANDER_IDLE_SAY);
	SergeantSound.SetNum(SERGEANT_IDLE_SAY);
	WeaponsSound.SetNum(WEAPONS_IDLE_SAY);
	EngineerSound.SetNum(ENGINEER_IDLE_SAY);
	MedicalSound.SetNum(MEDICAL_IDLE_SAY);
	CommunicationSound.SetNum(COMMUNICATION_IDLE_SAY);
	IntelligenceSound.SetNum(INTELLIGENCE_IDLE_SAY);
}

/*
State DrillIdle
{
Begin:
	LoopAnim('DrillIdle',1,0);
	Sleep(0.05);
	EyeTrack();
	JL'Loop'
;
}
State DrillTalk
{
Begin:
	Sleep(0.05);
	EyeTrack();
	if (fLastUsedTime > Level.TimeSeconds)
	{
		LoopAnim('DrillTalk');
		JL'Loop'
;
	}
	GotoState('DrillIdle','Begin');
}
State DrillTalkHands
{
Begin:
	PlayAnim('DrillHandsTransition',1,1);
	Sleep(0.05);
	EyeTrack();
	if (fLastUsedTime > Level.TimeSeconds)
	{
		LoopAnim('DrillTalkHands');
		JL'Loop'
;
	}
	PlayAnim('DrillHandsTransitionBack',1,1);
	Sleep(0.5);
	GotoState('DrillIdle','Begin');
}
State DrillTalkHandsRandom
{
Begin:
	Sleep(0.1);
	if (fTalkHandsRandomTimer > Level.TimeSeconds)
	{
		LoopAnim('DrillTalkHands',1,0.1);
		JL'HANDS'
;
	}
	fTalkHandsRandomTimer=((Level.TimeSeconds + 3) + (FRand() * 3));
	PlayAnim('DrillHandsTransitionBack',1,0.3);
	Sleep(0.5);
	Sleep(0.05);
	EyeTrack();
	if (fLastUsedTime > Level.TimeSeconds)
	{
		if (((FRand() > 0.8) && (fTalkHandsRandomTimer < Level.TimeSeconds)) && (fLastUsedTime > (Level.TimeSeconds + 6)))
		{
			fTalkHandsRandomTimer=((Level.TimeSeconds + 4) + (FRand() * 3));
			PlayAnim('DrillHandsTransition',1,0.3);
			Sleep(0.5);
			JL'HANDS'
;
		}
		else
		{
			LoopAnim('DrillTalk',1,0.3);
		}
		JL'Loop'
;
	}
	Sleep(0.1);
	GotoState('DrillIdle','Begin');
}
*/

void ANPC_SpecialForces::PossessedBy(AController* C)
{
	
}
void ANPC_SpecialForces::BeginPlay()
{

}
