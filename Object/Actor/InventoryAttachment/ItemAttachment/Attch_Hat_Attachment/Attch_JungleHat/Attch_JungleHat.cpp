// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_JungleHat/Attch_JungleHat.h"
#include "AA29/AA2_WorldSettings.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

AAttch_JungleHat::AAttch_JungleHat()
{
	ArcticStaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-helmet.m-helmet'"), NULL, LOAD_None, NULL);
	SFBoonieStaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-sf/m_hat_boonie.m_hat_boonie'"), NULL, LOAD_None, NULL);
	GuerrillaHelmetMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-USguerrilla_Helmet.m-USguerrilla_Helmet'"), NULL, LOAD_None, NULL);
	FriendlyStaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-jungle_hat.m-jungle_hat'"), NULL, LOAD_None, NULL);
}

UStaticMesh* AAttch_JungleHat::GetStaticMesh(bool bFriendly)
{
	switch (Cast<AAA2_WorldSettings>(GetWorldSettings())->GetSkinSet(bFriendly))
	{
		case ESkinSet::SKINS_Training:
		case ESkinSet::SKINS_Forest:
		case ESkinSet::SKINS_Desert:
		case ESkinSet::SKINS_IBCT:
			if (Cast<AAA2_WorldSettings>(GetWorldSettings())->GetMesh(bFriendly) == EMesh::MESH_SF)
			{
				if (Cast<AAGP_Pawn>(Base)->bGuerrillaMesh)
				{
					return GuerrillaHelmetMesh;
					break;
				}
				return SFBoonieStaticMesh;
			}
			else
			{
				return FriendlyStaticMesh;
			}
		case ESkinSet::SKINS_Arctic:
		case ESkinSet::SKINS_SF_Arctic:
			return ArcticStaticMesh;
		default:
			return nullptr;
	}
}
