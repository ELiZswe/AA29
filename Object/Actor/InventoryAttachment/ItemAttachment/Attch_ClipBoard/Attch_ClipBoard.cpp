// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_ClipBoard/Attch_ClipBoard.h"

AAttch_ClipBoard::AAttch_ClipBoard()
{
	AttachBone  = "RHandObject";
	StaticMesh  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Equipment/medical/eqp2_med_clipboard.eqp2_med_clipboard"), NULL, LOAD_None, NULL);
	DrawScale   = 0.5;
}
