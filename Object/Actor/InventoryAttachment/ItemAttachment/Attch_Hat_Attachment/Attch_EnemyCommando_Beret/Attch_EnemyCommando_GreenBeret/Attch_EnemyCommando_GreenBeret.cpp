// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_EnemyCommando_Beret/Attch_EnemyCommando_GreenBeret/Attch_EnemyCommando_GreenBeret.h"

AAttch_EnemyCommando_GreenBeret::AAttch_EnemyCommando_GreenBeret()
{
	Skins = {
				  Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstance'/Game/AmericasArmy/Textures/T_AAO_NPC_Skins/iraq_soliders/iraq_buret_green_Mat.iraq_buret_green_Mat'")))
	};
}
