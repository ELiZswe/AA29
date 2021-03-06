// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_Head/Attch_Head.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

AAttch_Head::AAttch_Head()
{
	SFBDUStaticMesh     = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-sf/m_hat_bdu.m_hat_bdu'"), NULL, LOAD_None, NULL);
	SFBoonieStaticMesh  = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-sf/m_hat_boonie.m_hat_boonie'"), NULL, LOAD_None, NULL);
	SFStaticMesh        = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-sf/m-helmet_sf.m-helmet_sf'"), NULL, LOAD_None, NULL);
	MILESStaticMesh     = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-helmet_miles.m-helmet_miles'"), NULL, LOAD_None, NULL);
	ScarfStaticMesh     = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/op-DesOp/m-scarfB.m-scarfB'"), NULL, LOAD_None, NULL);
	CapStaticMesh       = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/op-DesOp/m-opfor_cap.m-opfor_cap'"), NULL, LOAD_None, NULL);
	GuerrillaHelmetMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-USguerrilla_Helmet.m-USguerrilla_Helmet'"), NULL, LOAD_None, NULL);
	ACUHelmet           = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_Attachments/us-soldier/m_atta_us-soldier_michhelmet1a.m_atta_us-soldier_michhelmet1a'"), NULL, LOAD_None, NULL);
	ArcticMichHelmet    = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_Attachments/us-soldier/m_atta_us-soldier_michhelmet1b.m_atta_us-soldier_michhelmet1b'"), NULL, LOAD_None, NULL);
	FriendlyStaticMesh  = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-helmet.m-helmet'"), NULL, LOAD_None, NULL);
}

UStaticMesh* AAttch_Head::GetStaticMesh(bool bFriendly)
{
	/*
	if (Level.GamePlayMode == GM_MILES)
	{
		return MILESStaticMesh;
	}
	if (Level.GetMesh((!bFriendly)) == 6)
	{
		return nullptr;
	}
	if ((Cast<APawn>(Base).PlayerReplicationInfo != nullptr) && Pawn(Base).PlayerReplicationInfo.bVIPPS)
	{
		return nullptr;
	}
	switch (Level.GetMesh(bFriendly))
	{
	case 6:
		if (Cast<AAGP_Pawn>(Base).bGuerrillaMesh)
		{
			return GuerrillaHelmetMesh;
			break;
		}
		switch (Rand(3))
		{
		case 0:
		case 1:
			return SFBDUStaticMesh;
		case 2:
			return SFBoonieStaticMesh;
		default:
		}
	case 0:
		if (Cast<AAGP_Pawn>(Base).bGuerrillaMesh)
		{
			return GuerrillaHelmetMesh;
			break;
		}
		return ACUHelmet;
	}
	case 4:
	case 2:
	case 9:
		if (Cast<AAGP_Pawn>(Base).bGuerrillaMesh)
		{
			return GuerrillaHelmetMesh;
		}
		else
		{
			return ArcticMichHelmet;
		}
	case 5:
		switch (Rand(2))
		{
		case 0:
			return ScarfStaticMesh;
		default:
			return nullptr;
		case 7:
			return CapStaticMesh;
		default:
			return nullptr;
		}
	}
	*/
	return nullptr;  //FAKE   /EliZ
}
