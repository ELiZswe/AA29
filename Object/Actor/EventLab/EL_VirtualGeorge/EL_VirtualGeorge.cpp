// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_VirtualGeorge/EL_VirtualGeorge.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_NPC/NPC_VirtualGeorge/NPC_VirtualGeorge.h"

AEL_VirtualGeorge::AEL_VirtualGeorge()
{

}

/*
State George
{
Begin:
	VG.LoopAnim("GeorgeIdle");
	Sleep(1);
	Sleep(1);
	VG.PlayLIPSincAnim("GeorgeAnnounce3");
	Sleep(30);
	FadeOut(3,true);
}
*/

void AEL_VirtualGeorge::PreInit()
{
	//VG = NPC_VirtualGeorge(GetActorByTag("NPC_VirtualGeorge"));
}

void AEL_VirtualGeorge::Init()
{
}

void AEL_VirtualGeorge::PostInit()
{
}

void AEL_VirtualGeorge::PostPostInit()
{
	TriggerGroup("VirtualGeorge");
	ChangeState("George","");
}
