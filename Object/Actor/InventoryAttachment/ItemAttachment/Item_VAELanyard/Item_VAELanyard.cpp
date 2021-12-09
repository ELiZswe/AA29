// All the original content belonged to the US Army


#include "Item_VAELanyard.h"

AItem_VAELanyard::AItem_VAELanyard()
{
	AttachBone   = "RHandObject";
	StaticMesh   = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Equipment/Name_Plaque/m_equi_VAE_lanyard.m_equi_VAE_lanyard"), NULL, LOAD_None, NULL);
	//bHidden      = true;
	DrawScale    = 0.5;
	DrawScale3D  = FVector(125, 125, 125);
}