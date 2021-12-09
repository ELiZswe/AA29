// All the original content belonged to the US Army


#include "Attch_CommandoKnife.h"

AAttch_CommandoKnife::AAttch_CommandoKnife()
{
	AttachBone        = "RChestGear";
	StaticMesh        = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Attachments/Op4/m_AAO_bowie.m_AAO_bowie"), NULL, LOAD_None, NULL);
	RelativeLocation  = FVector(0, -3, -1);
	RelativeRotation  = FRotator(0, 0, -87.890625);
}