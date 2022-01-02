// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Parachute/Attch_Parachute.h"

AAttch_Parachute::AAttch_Parachute()
{
	sParachuteOpenSound       = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Airborne/Parachute/parachuteopen.parachuteopen"), NULL, LOAD_None, NULL);
	sParachuteFlutterSound    = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Airborne/Parachute/parachutefluttering.parachutefluttering"), NULL, LOAD_None, NULL);
	sParachuteCollapseSound   = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Airborne/Parachute/parachuteopen.parachuteopen"), NULL, LOAD_None, NULL);
	bStartScaleDeploy         = true;
	PrevAnimState             = 255;
	DrawType                  = EDrawType::DT_StaticMesh;
	bOrientOnSlope            = true;
	//bReplicateInstigator = true;
	Mesh                      = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_Objects/Parachute.Parachute"), NULL, LOAD_None, NULL);
	RelativeRotation          = FRotator(-90, 0, 0);
	DrawScale3D               = FVector(1, 1, 1);
	//bCollideActors = true;
	//bCollideWorld = true;
}

/*
State PendingCCSPA
{
	simulated Function Timer()
	{
		if (Pawn(Owner) != nullptr)
		{
			CreateClientSideParachuteAttachments();
		}
	}
	simulated Function BeginState()
	{
		SetTimer(0.05,true);
	}
	simulated Function EndState()
	{
		SetTimer(0,false);
	}
}
*/

