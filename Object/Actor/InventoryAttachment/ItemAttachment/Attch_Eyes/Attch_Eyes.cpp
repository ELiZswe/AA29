// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Eyes/Attch_Eyes.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_Head/Attch_Head.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

AAttch_Eyes::AAttch_Eyes()
{
	ACUGogglesUp = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_Attachments/us-soldier/m_atta_us-soldier_goggles_ess1up.m_atta_us-soldier_goggles_ess1up'"), NULL, LOAD_None, NULL);
	ACUGogglesDown = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_Attachments/us-soldier/m_atta_us-soldier_goggles_ess1down.m_atta_us-soldier_goggles_ess1down'"), NULL, LOAD_None, NULL);
	GogglesDown = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-goggles_down.m-goggles_down'"), NULL, LOAD_None, NULL);
	GogglesUp = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-goggles_up.m-goggles_up'"), NULL, LOAD_None, NULL);
	OakleysBlue = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-sf/m-oakleys_blue.m-oakleys_blue'"), NULL, LOAD_None, NULL);
	OakleysGreen = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-sf/m-oakleys_green.m-oakleys_green'"), NULL, LOAD_None, NULL);
	OakleysGrey = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-sf/m-oakleys_grey.m-oakleys_grey'"), NULL, LOAD_None, NULL);
	OakleysRed = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-sf/m-oakleys_red.m-oakleys_red'"), NULL, LOAD_None, NULL);
	SFGogglesDown = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_Attachments/us-soldier/m_atta_us-soldier_goggles_ess1down.m_atta_us-soldier_goggles_ess1down'"), NULL, LOAD_None, NULL);
	SFGogglesUpBDU = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_Attachments/us-soldier/m_atta_us-soldier_goggles_ess1up.m_atta_us-soldier_goggles_ess1up'"), NULL, LOAD_None, NULL);
	SFGogglesUpCap = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_Attachments/us-soldier/m_atta_us_soldier_goggles_ess1_cap_up.m_atta_us_soldier_goggles_ess1_cap_up'"), NULL, LOAD_None, NULL);
	SFGogglesUpBoonie = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_Attachments/us-soldier/m_atta_us_soldier_goggles_ess1_boonie_up.m_atta_us_soldier_goggles_ess1_boonie_up'"), NULL, LOAD_None, NULL);
	AttachBone = "BN_HeadEnd";
}

bool AAttch_Eyes::HasNVG()
{
	/*
	if ((Cast<APawn>(Base).PlayerReplicationInfo == nullptr) || (Cast<APawn>(Base).PlayerReplicationInfo.Team == nullptr))
	{
		return false;
	}
	switch (Cast<APawn>(Base).PlayerReplicationInfo.Team.TeamIndex)
	{
	case 0:
		return Level.bTeam0HasNVGs;
	case 1:
		return Level.bTeam1HasNVGs;
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

UStaticMesh* AAttch_Eyes::GetSFStaticMesh()
{
	int32 Num = 0;
	int32 i = 0;
	AAttch_Head* H = nullptr;
	AAGP_Character* p = nullptr;
	/*
	p = Cast<AAGP_Character>(Base);
	for (i = 0; i < p->IA.Num(); i++)
	{
		H = Cast<AAttch_Head>(p->IA[i]);
		if (H != nullptr)
		{
		}
	}
	if (Level.GetLevelName() ~= "SFRecon")
	{
		Num = 3;
	}
	else
	{
		Num = 4;
	}
	switch (Rand(Num))
	{
	case 0:
		return nullptr;
	case 1:
		return GetSFGogglesUp();
	case 2:
		if ((H.StaticMesh == H.Default.SFBDUStaticMesh) || (H.StaticMesh == H.Default.SFBoonieStaticMesh))
		{
			return GetSFGogglesUp();
		}
		return SFGogglesDown;
	case 3:
		switch (Rand(4))
		{
		case 0:
			return OakleysBlue;
		case 1:
			return OakleysGreen;
		case 2:
			return OakleysGrey;
		case 3:
			return OakleysRed;
		default:
		default:
			return nullptr;
			return;
		}
	}
	*/
	return nullptr;    //FAKE   /ELiZ
}

UStaticMesh* AAttch_Eyes::GetStaticMesh(bool bFriendly)
{
	/*
	if ((Cast<APawn>(Base).PlayerReplicationInfo != nullptr) && Pawn(Base).PlayerReplicationInfo.bVIPPS)
	{
		return nullptr;
	}
	switch (Level.GetMesh(bFriendly))
	{
	case 6:
		if (Cast<AAGP_Pawn>(Base).bGuerrillaMesh)
		{
			return nullptr;
			break;
		}
		return GetSFStaticMesh();
		case 4:
		case 0:
			if (HasNVG())
			{
				return nullptr;
			}
			switch (Rand(3))
			{
			case 0:
				return ACUGogglesDown;
			case 1:
				return ACUGogglesUp;
			default:
				return nullptr;
			default:
				return nullptr;
			}
		}
	}
	*/
	return nullptr;    //FAKE   /ELiZ
}

UStaticMesh* AAttch_Eyes::GetSFGogglesUp()
{
	AAGP_Character* p = nullptr;
	int32 i = 0;
	AAttch_Head* H = nullptr;
	/*
	p = Cast<AAGP_Character>(Base);
	for (i = 0; i < p->IA.Num(); i++)
	{
		H = Cast<AAttch_Head>(p->IA[i]);
		if (H != nullptr)
		{
			if (H->StaticMesh == H->Default->SFBoonieStaticMesh)
			{
				return SFGogglesUpBoonie;
			}
			else
			{
				if (H.StaticMesh == H.Default.SFBDUStaticMesh)
				{
					return SFGogglesUpCap;
				}
				else
				{
					return SFGogglesUpBDU;
				}
			}
		}
	}
	*/
	return nullptr;
}

