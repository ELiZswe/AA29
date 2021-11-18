// All the original content belonged to the US Army


#include "Attch_Turban.h"

AAttch_Turban::AAttch_Turban()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/op-DesOp/m-turbin.m-turbin"), NULL, LOAD_None, NULL);
}