// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_MOUTPencil/Attch_MOUTPencil.h"

AAttch_MOUTPencil::AAttch_MOUTPencil()
{
	AttachBone  = "LHandObject";
	StaticMesh  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/PencilShoothouse.PencilShoothouse"), NULL, LOAD_None, NULL);
	DrawScale   = 0.5;
}
