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

void ANPC_SpecialForces::PossessedBy(AController* C)
{
	
}
void ANPC_SpecialForces::BeginPlay()
{

}
