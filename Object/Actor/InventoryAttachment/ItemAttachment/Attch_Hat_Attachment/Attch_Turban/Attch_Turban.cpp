// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_Turban/Attch_Turban.h"

AAttch_Turban::AAttch_Turban()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/op-DesOp/m-turbin.m-turbin"), NULL, LOAD_None, NULL);
}
