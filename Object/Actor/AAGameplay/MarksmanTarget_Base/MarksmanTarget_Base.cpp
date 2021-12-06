// All the original content belonged to the US Army


#include "AA29/Object/Actor/AAGameplay/MarksmanTarget_Base/MarksmanTarget_Base.h"

AMarksmanTarget_Base::AMarksmanTarget_Base()
{
	DrawType = EDrawType::DT_StaticMesh;
		//StaticMesh = StaticMesh'M_AA2_Equipment.Targets.eqp2_targets_tbox1a'

	if (StaticMesh)
	{
		StaticMesh->SetStaticMesh(LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_gguy1a.eqp2_targets_gguy1a'")));
	}
		//bShadowCast = False;
		//CollisionRadius = 1;
		//CollisionHeight = 1;
		//bCollideWorld = False;
		//bUseCylinderCollision = False;
}
