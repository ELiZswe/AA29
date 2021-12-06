// All the original content belonged to the US Army

#include "AA29/Object/Actor/AAGameplay/MarksmanTarget/MarksmanTarget.h"
#include "AA29/MyStructs.h"
#include "AA29/Mover/DynamicMover/DynamicMover.h"
#include "AA29/Object/Actor/AAGameplay/MarksmanTarget_Base/MarksmanTarget_Base.h"
#include "AA29/Object/Actor/AAGameplay/MarksmanTarget_Part/MarksmanTarget_Part.h"
#include "AA29/AA29.h"
AMarksmanTarget::AMarksmanTarget()
{
	MeshesBlueFor.SetNum(3);

	
	MeshesBlueFor[0].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_gguy1a.eqp2_targets_gguy1a'"));
	MeshesBlueFor[0].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesBlueFor[0].Z1Scale = 1;
	MeshesBlueFor[0].Z1Scale3D = FVector(1, 1, 1);
	MeshesBlueFor[0].Z1Offset = FVector(-3, 0, -16);
	MeshesBlueFor[0].Z1Rotation = FRotator(0, 0, 0);
	MeshesBlueFor[0].Z1ID = "B";
	MeshesBlueFor[0].Z2Scale = 0.5;
	MeshesBlueFor[0].Z2Scale3D = FVector(1, 1, 1);
	MeshesBlueFor[0].Z2Offset = FVector(-4, 0, -16);
	MeshesBlueFor[0].Z2Rotation = FRotator(0,0, 0);
	MeshesBlueFor[0].Z2ID = "A";


	MeshesBlueFor[1].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_gguy2a.eqp2_targets_gguy2a'"));
	MeshesBlueFor[1].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesBlueFor[1].Z1Scale = 1;
	MeshesBlueFor[1].Z1Scale3D = FVector(1, 1, 1);
	MeshesBlueFor[1].Z1Offset = FVector(-3, 0, -16);
	MeshesBlueFor[1].Z1Rotation = FRotator(0, 0, 0);
	MeshesBlueFor[1].Z1ID = "B";
	MeshesBlueFor[1].Z2Scale = 0.5;
	MeshesBlueFor[1].Z2Scale3D = FVector(1, 1, 1);
	MeshesBlueFor[1].Z2Offset = FVector(-4, 0, -16);
	MeshesBlueFor[1].Z2Rotation = FRotator(0, 0, 0);
	MeshesBlueFor[1].Z2ID = "A";


	MeshesBlueFor[2].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_gguy4a.eqp2_targets_gguy4a'"));
	MeshesBlueFor[2].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesBlueFor[2].Z1Scale = 1;
	MeshesBlueFor[2].Z1Scale3D = FVector(1, 1, 1);
	MeshesBlueFor[2].Z1Offset = FVector(-3, 0, -16);
	MeshesBlueFor[2].Z1Rotation = FRotator(0, 0, 0);
	MeshesBlueFor[2].Z1ID = "B";
	MeshesBlueFor[2].Z2Scale = 0.5;
	MeshesBlueFor[2].Z2Scale3D = FVector(1, 1, 1);
	MeshesBlueFor[2].Z2Offset = FVector(-4, 0, -16);
	MeshesBlueFor[2].Z2Rotation = FRotator(0, 0, 0);
	MeshesBlueFor[2].Z2ID = "A";

	MeshesCiv.SetNum(8);

	MeshesCiv[0].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_gguy7a.eqp2_targets_gguy7a'"));
	MeshesCiv[0].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesCiv[0].Z1Scale = 1;
	MeshesCiv[0].Z1Scale3D = FVector(1, 1, 1);
	MeshesCiv[0].Z1Offset = FVector(-3, 0, -16);
	MeshesCiv[0].Z1Rotation = FRotator(0, 0, 0);
	MeshesCiv[0].Z1ID = "B";
	MeshesCiv[0].Z2Scale = 0.5;
	MeshesCiv[0].Z2Scale3D = FVector(1, 1, 1);
	MeshesCiv[0].Z2Offset = FVector(-4, 0, -16);
	MeshesCiv[0].Z2Rotation = FRotator(0, 0, 0);
	MeshesCiv[0].Z2ID = "A";

	MeshesCiv[1].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_gguy8a.eqp2_targets_gguy8a'"));
	MeshesCiv[1].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesCiv[1].Z1Scale = 1;
	MeshesCiv[1].Z1Scale3D = FVector(1, 1, 1);
	MeshesCiv[1].Z1Offset = FVector(-3, 0, -16);
	MeshesCiv[1].Z1Rotation = FRotator(0, 0, 0);
	MeshesCiv[1].Z1ID = "B";
	MeshesCiv[1].Z2Scale = 0.5;
	MeshesCiv[1].Z2Scale3D = FVector(1, 1, 1);
	MeshesCiv[1].Z2Offset = FVector(-4, 0, -16);
	MeshesCiv[1].Z2Rotation = FRotator(0, 0, 0);
	MeshesCiv[1].Z2ID = "A";

	MeshesCiv[2].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_gguy9a.eqp2_targets_gguy9a'"));
	MeshesCiv[2].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesCiv[2].Z1Scale = 1;
	MeshesCiv[2].Z1Scale3D = FVector(1, 1, 1);
	MeshesCiv[2].Z1Offset = FVector(-3, 0, -16);
	MeshesCiv[2].Z1Rotation = FRotator(0, 0, 0);
	MeshesCiv[2].Z1ID = "B";
	MeshesCiv[2].Z2Scale = 0.5;
	MeshesCiv[2].Z2Scale3D = FVector(1, 1, 1);
	MeshesCiv[2].Z2Offset = FVector(-4, 0, -16);
	MeshesCiv[2].Z2Rotation = FRotator(0, 0, 0);
	MeshesCiv[2].Z2ID = "A";

	MeshesCiv[3].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_gguy10a.eqp2_targets_gguy10a'"));
	MeshesCiv[3].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesCiv[3].Z1Scale = 1;
	MeshesCiv[3].Z1Scale3D = FVector(1, 1, 1);
	MeshesCiv[3].Z1Offset = FVector(-3, 0, -16);
	MeshesCiv[3].Z1Rotation = FRotator(0, 0, 0);
	MeshesCiv[3].Z1ID = "B";
	MeshesCiv[3].Z2Scale = 0.5;
	MeshesCiv[3].Z2Scale3D = FVector(1, 1, 1);
	MeshesCiv[3].Z2Offset = FVector(-4, 0, -16);
	MeshesCiv[3].Z2Rotation = FRotator(0, 0, 0);
	MeshesCiv[3].Z2ID = "A";

	MeshesCiv[4].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_gguy11a.eqp2_targets_gguy11a'"));
	MeshesCiv[4].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesCiv[4].Z1Scale = 1;
	MeshesCiv[4].Z1Scale3D = FVector(1, 1, 1);
	MeshesCiv[4].Z1Offset = FVector(-3, 0, -16);
	MeshesCiv[4].Z1Rotation = FRotator(0, 0, 0);
	MeshesCiv[4].Z1ID = "B";
	MeshesCiv[4].Z2Scale = 0.5;
	MeshesCiv[4].Z2Scale3D = FVector(1, 1, 1);
	MeshesCiv[4].Z2Offset = FVector(-4, 0, -16);
	MeshesCiv[4].Z2Rotation = FRotator(0, 0, 0);
	MeshesCiv[4].Z2ID = "A";

	MeshesCiv[5].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_gguy12a.eqp2_targets_gguy12a'"));
	MeshesCiv[5].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesCiv[5].Z1Scale = 1;
	MeshesCiv[5].Z1Scale3D = FVector(1, 1, 1);
	MeshesCiv[5].Z1Offset = FVector(-3, 0, -16);
	MeshesCiv[5].Z1Rotation = FRotator(0, 0, 0);
	MeshesCiv[5].Z1ID = "B";
	MeshesCiv[5].Z2Scale = 0.5;
	MeshesCiv[5].Z2Scale3D = FVector(1, 1, 1);
	MeshesCiv[5].Z2Offset = FVector(-4, 0, -16);
	MeshesCiv[5].Z2Rotation = FRotator(0, 0, 0);
	MeshesCiv[5].Z2ID = "A";

	MeshesCiv[6].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_gguy13a.eqp2_targets_gguy13a'"));
	MeshesCiv[6].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesCiv[6].Z1Scale = 1;
	MeshesCiv[6].Z1Scale3D = FVector(1, 1, 1);
	MeshesCiv[6].Z1Offset = FVector(-3, 0, -16);
	MeshesCiv[6].Z1Rotation = FRotator(0, 0, 0);
	MeshesCiv[6].Z1ID = "B";
	MeshesCiv[6].Z2Scale = 0.5;
	MeshesCiv[6].Z2Scale3D = FVector(1, 1, 1);
	MeshesCiv[6].Z2Offset = FVector(-4, 0, -16);
	MeshesCiv[6].Z2Rotation = FRotator(0, 0, 0);
	MeshesCiv[6].Z2ID = "A";

	MeshesCiv[7].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_gguy14a.eqp2_targets_gguy14a'"));
	MeshesCiv[7].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesCiv[7].Z1Scale = 1;
	MeshesCiv[7].Z1Scale3D = FVector(1, 1, 1);
	MeshesCiv[7].Z1Offset = FVector(-3, 0, -16);
	MeshesCiv[7].Z1Rotation = FRotator(0, 0, 0);
	MeshesCiv[7].Z1ID = "B";
	MeshesCiv[7].Z2Scale = 0.5;
	MeshesCiv[7].Z2Scale3D = FVector(1, 1, 1);
	MeshesCiv[7].Z2Offset = FVector(-4, 0, -16);
	MeshesCiv[7].Z2Rotation = FRotator(0, 0, 0);
	MeshesCiv[7].Z2ID = "A";



	MeshesIndig.SetNum(3);
	MeshesIndig[0].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_gguy3a.eqp2_targets_gguy3a'"));
	MeshesIndig[0].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesIndig[0].Z1Scale = 1;
	MeshesIndig[0].Z1Scale3D = FVector(1, 1, 1);
	MeshesIndig[0].Z1Offset = FVector(-3, 0, -16);
	MeshesIndig[0].Z1Rotation = FRotator(0, 0, 0);
	MeshesIndig[0].Z1ID = "B";
	MeshesIndig[0].Z2Scale = 0.5;
	MeshesIndig[0].Z2Scale3D = FVector(1, 1, 1);
	MeshesIndig[0].Z2Offset = FVector(-4, 0, -16);
	MeshesIndig[0].Z2Rotation = FRotator(0, 0, 0);
	MeshesIndig[0].Z2ID = "A";

	MeshesIndig[1].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_gguy5a.eqp2_targets_gguy5a'"));
	MeshesIndig[1].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesIndig[1].Z1Scale = 1;
	MeshesIndig[1].Z1Scale3D = FVector(1, 1, 1);
	MeshesIndig[1].Z1Offset = FVector(-3, 0, -16);
	MeshesIndig[1].Z1Rotation = FRotator(0, 0, 0);
	MeshesIndig[1].Z1ID = "B";
	MeshesIndig[1].Z2Scale = 0.5;
	MeshesIndig[1].Z2Scale3D = FVector(1, 1, 1);
	MeshesIndig[1].Z2Offset = FVector(-4, 0, -16);
	MeshesIndig[1].Z2Rotation = FRotator(0, 0, 0);
	MeshesIndig[1].Z2ID = "A";

	MeshesIndig[2].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_gguy6a.eqp2_targets_gguy6a'"));
	MeshesIndig[2].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesIndig[2].Z1Scale = 1;
	MeshesIndig[2].Z1Scale3D = FVector(1, 1, 1);
	MeshesIndig[2].Z1Offset = FVector(-3, 0, -16);
	MeshesIndig[2].Z1Rotation = FRotator(0, 0, 0);
	MeshesIndig[2].Z1ID = "B";
	MeshesIndig[2].Z2Scale = 0.5;
	MeshesIndig[2].Z2Scale3D = FVector(1, 1, 1);
	MeshesIndig[2].Z2Offset = FVector(-4, 0, -16);
	MeshesIndig[2].Z2Rotation = FRotator(0, 0, 0);
	MeshesIndig[2].Z2ID = "A";




	MeshesOpFor.SetNum(12);

	MeshesOpFor[0].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_opguy1a.eqp2_targets_opguy1a'"));
	MeshesOpFor[0].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesOpFor[0].Z1Scale = 1;
	MeshesOpFor[0].Z1Scale3D = FVector(1, 1, 1);
	MeshesOpFor[0].Z1Offset = FVector(-3, 0, -16);
	MeshesOpFor[0].Z1Rotation = FRotator(0, 0, 0);
	MeshesOpFor[0].Z1ID = "B";
	MeshesOpFor[0].Z2Scale = 0.5;
	MeshesOpFor[0].Z2Scale3D = FVector(1, 1, 1);
	MeshesOpFor[0].Z2Offset = FVector(-4, 0, -16);
	MeshesOpFor[0].Z2Rotation = FRotator(0, 0, 0);
	MeshesOpFor[0].Z2ID = "A";

	MeshesOpFor[1].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_gguy7a.eqp2_targets_gguy7a'"));
	MeshesOpFor[1].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesOpFor[1].Z1Scale = 1;
	MeshesOpFor[1].Z1Scale3D = FVector(1, 1, 1);
	MeshesOpFor[1].Z1Offset = FVector(-3, 0, -16);
	MeshesOpFor[1].Z1Rotation = FRotator(0, 0, 0);
	MeshesOpFor[1].Z1ID = "B";
	MeshesOpFor[1].Z2Scale = 0.5;
	MeshesOpFor[1].Z2Scale3D = FVector(1, 1, 1);
	MeshesOpFor[1].Z2Offset = FVector(-4, 0, -16);
	MeshesOpFor[1].Z2Rotation = FRotator(0, 0, 0);
	MeshesOpFor[1].Z2ID = "A";

	MeshesOpFor[2].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_opguy2a.eqp2_targets_opguy2a'"));
	MeshesOpFor[2].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesOpFor[2].Z1Scale = 1;
	MeshesOpFor[2].Z1Scale3D = FVector(1, 1, 1);
	MeshesOpFor[2].Z1Offset = FVector(-3, 0, -16);
	MeshesOpFor[2].Z1Rotation = FRotator(0, 0, 0);
	MeshesOpFor[2].Z1ID = "B";
	MeshesOpFor[2].Z2Scale = 0.5;
	MeshesOpFor[2].Z2Scale3D = FVector(1, 1, 1);
	MeshesOpFor[2].Z2Offset = FVector(-4, 0, -16);
	MeshesOpFor[2].Z2Rotation = FRotator(0, 0, 0);
	MeshesOpFor[2].Z2ID = "A";

	MeshesOpFor[3].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_opguy4a.eqp2_targets_opguy4a'"));
	MeshesOpFor[3].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesOpFor[3].Z1Scale = 1;
	MeshesOpFor[3].Z1Scale3D = FVector(1, 1, 1);
	MeshesOpFor[3].Z1Offset = FVector(-3, 0, -16);
	MeshesOpFor[3].Z1Rotation = FRotator(0, 0, 0);
	MeshesOpFor[3].Z1ID = "B";
	MeshesOpFor[3].Z2Scale = 0.5;
	MeshesOpFor[3].Z2Scale3D = FVector(1, 1, 1);
	MeshesOpFor[3].Z2Offset = FVector(-4, 0, -16);
	MeshesOpFor[3].Z2Rotation = FRotator(0, 0, 0);
	MeshesOpFor[3].Z2ID = "A";

	MeshesOpFor[4].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_opguy5a.eqp2_targets_opguy5a'"));
	MeshesOpFor[4].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesOpFor[4].Z1Scale = 1;
	MeshesOpFor[4].Z1Scale3D = FVector(1, 1, 1);
	MeshesOpFor[4].Z1Offset = FVector(-3, 0, -16);
	MeshesOpFor[4].Z1Rotation = FRotator(0, 0, 0);
	MeshesOpFor[4].Z1ID = "B";
	MeshesOpFor[4].Z2Scale = 0.5;
	MeshesOpFor[4].Z2Scale3D = FVector(1, 1, 1);
	MeshesOpFor[4].Z2Offset = FVector(-4, 0, -16);
	MeshesOpFor[4].Z2Rotation = FRotator(0, 0, 0);
	MeshesOpFor[4].Z2ID = "A";

	MeshesOpFor[5].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_opguy6a.eqp2_targets_opguy6a'"));
	MeshesOpFor[5].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesOpFor[5].Z1Scale = 1;
	MeshesOpFor[5].Z1Scale3D = FVector(1, 1, 1);
	MeshesOpFor[5].Z1Offset = FVector(-3, 0, -16);
	MeshesOpFor[5].Z1Rotation = FRotator(0, 0, 0);
	MeshesOpFor[5].Z1ID = "B";
	MeshesOpFor[5].Z2Scale = 0.5;
	MeshesOpFor[5].Z2Scale3D = FVector(1, 1, 1);
	MeshesOpFor[5].Z2Offset = FVector(-4, 0, -16);
	MeshesOpFor[5].Z2Rotation = FRotator(0, 0, 0);
	MeshesOpFor[5].Z2ID = "A";

	MeshesOpFor[6].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_opguy7a.eqp2_targets_opguy7a'"));
	MeshesOpFor[6].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesOpFor[6].Z1Scale = 1;
	MeshesOpFor[6].Z1Scale3D = FVector(1, 1, 1);
	MeshesOpFor[6].Z1Offset = FVector(-3, 0, -16);
	MeshesOpFor[6].Z1Rotation = FRotator(0, 0, 0);
	MeshesOpFor[6].Z1ID = "B";
	MeshesOpFor[6].Z2Scale = 0.5;
	MeshesOpFor[6].Z2Scale3D = FVector(1, 1, 1);
	MeshesOpFor[6].Z2Offset = FVector(-4, 0, -16);
	MeshesOpFor[6].Z2Rotation = FRotator(0, 0, 0);
	MeshesOpFor[6].Z2ID = "A";

	MeshesOpFor[7].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_opguy8a.eqp2_targets_opguy8a'"));
	MeshesOpFor[7].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesOpFor[7].Z1Scale = 1;
	MeshesOpFor[7].Z1Scale3D = FVector(1, 1, 1);
	MeshesOpFor[7].Z1Offset = FVector(-3, 0, -16);
	MeshesOpFor[7].Z1Rotation = FRotator(0, 0, 0);
	MeshesOpFor[7].Z1ID = "B";
	MeshesOpFor[7].Z2Scale = 0.5;
	MeshesOpFor[7].Z2Scale3D = FVector(1, 1, 1);
	MeshesOpFor[7].Z2Offset = FVector(-4, 0, -16);
	MeshesOpFor[7].Z2Rotation = FRotator(0, 0, 0);
	MeshesOpFor[7].Z2ID = "A";

	MeshesOpFor[8].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_opguy9a.eqp2_targets_opguy9a'"));
	MeshesOpFor[8].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesOpFor[8].Z1Scale = 1;
	MeshesOpFor[8].Z1Scale3D = FVector(1, 1, 1);
	MeshesOpFor[8].Z1Offset = FVector(-3, 0, -16);
	MeshesOpFor[8].Z1Rotation = FRotator(0, 0, 0);
	MeshesOpFor[8].Z1ID = "B";
	MeshesOpFor[8].Z2Scale = 0.5;
	MeshesOpFor[8].Z2Scale3D = FVector(1, 1, 1);
	MeshesOpFor[8].Z2Offset = FVector(-4, 0, -16);
	MeshesOpFor[8].Z2Rotation = FRotator(0, 0, 0);
	MeshesOpFor[8].Z2ID = "A";

	MeshesOpFor[9].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_opguy10a.eqp2_targets_opguy10a'"));
	MeshesOpFor[9].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesOpFor[9].Z1Scale = 1;
	MeshesOpFor[9].Z1Scale3D = FVector(1, 1, 1);
	MeshesOpFor[9].Z1Offset = FVector(-3, 0, -16);
	MeshesOpFor[9].Z1Rotation = FRotator(0, 0, 0);
	MeshesOpFor[9].Z1ID = "B";
	MeshesOpFor[9].Z2Scale = 0.5;
	MeshesOpFor[9].Z2Scale3D = FVector(1, 1, 1);
	MeshesOpFor[9].Z2Offset = FVector(-4, 0, -16);
	MeshesOpFor[9].Z2Rotation = FRotator(0, 0, 0);
	MeshesOpFor[9].Z2ID = "A";

	MeshesOpFor[10].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_opguy11a.eqp2_targets_opguy11a'"));
	MeshesOpFor[10].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesOpFor[10].Z1Scale = 1;
	MeshesOpFor[10].Z1Scale3D = FVector(1, 1, 1);
	MeshesOpFor[10].Z1Offset = FVector(-3, 0, -16);
	MeshesOpFor[10].Z1Rotation = FRotator(0, 0, 0);
	MeshesOpFor[10].Z1ID = "B";
	MeshesOpFor[10].Z2Scale = 0.5;
	MeshesOpFor[10].Z2Scale3D = FVector(1, 1, 1);
	MeshesOpFor[10].Z2Offset = FVector(-4, 0, -16);
	MeshesOpFor[10].Z2Rotation = FRotator(0, 0, 0);
	MeshesOpFor[10].Z2ID = "A";

	MeshesOpFor[11].StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_opguy12a.eqp2_targets_opguy12a'"));
	MeshesOpFor[11].ZoneMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_tzone1a.eqp2_targets_tzone1a'"));
	MeshesOpFor[11].Z1Scale = 1;
	MeshesOpFor[11].Z1Scale3D = FVector(1, 1, 1);
	MeshesOpFor[11].Z1Offset = FVector(-3, 0, -16);
	MeshesOpFor[11].Z1Rotation = FRotator(0, 0, 0);
	MeshesOpFor[11].Z1ID = "B";
	MeshesOpFor[11].Z2Scale = 0.5;
	MeshesOpFor[11].Z2Scale3D = FVector(1, 1, 1);
	MeshesOpFor[11].Z2Offset = FVector(-4, 0, -16);
	MeshesOpFor[11].Z2Rotation = FRotator(0, 0, 0);
	MeshesOpFor[11].Z2ID = "A";



	TargetType = ETargetType::TT_OpFor;
	ZoneID = "C";
	MoverState = "TriggerToggle";
	MoveTime = 1;



	DrawType = EDrawType::DT_StaticMesh;
	
	//bShadowCast = false;
	//bStaticLighting = true;
	//CollisionRadius = 1;
	//CollisionHeight = 1;
	
	SetActorEnableCollision(false);				//bCollideWorld = false;
	
	


	//bUseCylinderCollision = false;



	if (StaticMesh)
	{
		StaticMesh->SetStaticMesh(LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_opguy1a.eqp2_targets_opguy1a'"), NULL, LOAD_None, NULL));
	}
}



void AMarksmanTarget::PreBeginPlay()
{
}
void AMarksmanTarget::BeginPlay()
{
	PostBeginPlay();  //Mine ELIZ
}
void AMarksmanTarget::PostBeginPlay()
{
	
	if (bRandomizeType)
	{
		SetRandomType();
	}
	if (bRandomizeMesh)
	{
		SetRandomMesh();
	}
	else
	{
		SetMesh(DefaultMeshIndex);
	}
	
	UWorld* const World = GetWorld();

	if (bMoveOnTrigger)
	{
		//MoveActor = Spawn('DynamicMover');
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			//SpawnParams.Instigator = Instigator;
			AActor* const SpawningObject = World->SpawnActor<AActor>(ADynamicMover::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
			MoveActor = Cast<ADynamicMover>(SpawningObject);
		}
		if (MoveActor == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("MarksmanTarget::PostBeginPlay(): Error: Couldn't spawn DynamicMover"));
			return;
		}
	}
	if (bCreateBase)
	{
		//MagicBox = Spawn('MarksmanTarget_Base');

		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			//SpawnParams.Instigator = Instigator;
			AActor* const SpawningObject = World->SpawnActor<AActor>(AMarksmanTarget_Base::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
			MagicBox = Cast<AMarksmanTarget_Base>(SpawningObject);

		}



		if (MagicBox == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("MarksmanTarget::CreateBase(): Could not spawn MarksmanTarget_Base"));
		}
	}


	
	if (bRandomizeLocation)
	{
		RandomizeLocation();
	}
	else
	{
		InitBase();
		InitMover();
	}
	if (bCreateZones)
	{
		CreateZones();
	}
	
}
void AMarksmanTarget::InitMover()
{
	
	if (!bMoveOnTrigger)
	{
		return;
	}
	/*
	SetBase(None);
	MoveActor.SetLocation(Location);
	MoveActor.SetRotation(Rotation);
	MoveActor.BasePos = Location;
	MoveActor.BaseRot = Rotation;
	MoveActor.MoverEncroachType = 3;
	MoveActor.MoverGlideType = 1;
	MoveActor.MoveTime = MoveTime;
	MoveActor.SetKeyPos(0, MakeVect(0, 0, 0));
	MoveActor.SetKeyPos(1, LocationOffset);
	MoveActor.SetKeyRot(0, MakeRot(0, 0, 0));
	MoveActor.SetKeyRot(1, RotationOffset);
	MoveActor.GotoState(MoverState);
	SetBase(MoveActor);
	*/
}
void AMarksmanTarget::InitBase()
{
	/*
	local FVector HitNormal;
	local FVector HitLocation;
	local bool bBlockZero;
	if (!bCreateBase)
	{
		Return;
	}
	bBlockZero = bBlockZeroExtentTraces;
	Trace(HitLocation, HitNormal, Location + MakeVect(0, 0, -8192), Location);
	bBlockZeroExtentTraces = bBlockZero;
	HitLocation.X = Location.X;
	HitLocation.Y = Location.Y;
	MagicBox.SetLocation(HitLocation);
	*/
}
void AMarksmanTarget::RandomizeLocation()
{
	
	TArray<AMarksmanTarget*> Targets;
	TArray<AActor*> Locations;
	AActor* A;
	
	if (RandomLocationTag == "None")
	{
		//Log(Tag $ " MarksmanTarget::RandomizeLocation(): Error: RandomLocationTag is 'None'");
		return;
	}

	//for (TObjectIterator<AMarksmanTarget> Itr; Itr; ++Itr)
	for (TActorIterator<AMarksmanTarget> Itr(GetWorld()); Itr; ++Itr)
	{
		Targets.Add(*Itr);
	}
	for (TActorIterator<AActor> Ac(GetWorld()); Ac; ++Ac)
	{
		A = *Ac;
		if (A->Tags.Contains(RandomLocationTag))
		{
			if (!LocationIsTaken(Targets, A))
			{
				Locations.Add(A);
			}
		}
	}

	if (Locations.Num() > 0)
	{
		int32 index= FMath::RandRange(0, Locations.Num() - 1);
		//int32 index = 0;
		A = Locations[index];
		SetActorLocation(A->GetActorLocation());
		SetActorRotation(A->GetActorRotation());
	}
	else
	{
		//Log(Tag $ " MarksmanTarget::RandomizeLocation(): Error: No Locations available");
	}
	InitMover();
	InitBase();
	
}
bool AMarksmanTarget::LocationIsTaken(TArray<AMarksmanTarget*> Targets, AActor* L)
{
	
	int32 i;
	for (i = 0; i < Targets.Num()-1; i++)
	{
		if (Targets[i]->GetActorLocation() == L->GetActorLocation())
		{
			return true;
		}
	}
	return false;
}
void AMarksmanTarget::Trigger(AActor* Other, APawn* EventInstigator)
{
	
	if (bTriggerOnce && bTriggered)
	{
		return;
	}
	bTriggered = true;
	if (MoveActor != nullptr)
	{
		//MoveActor->Trigger(Other, EventInstigator);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("MarksmanTarget::Trigger(): MoveActor is None"));
	}
	
}
void AMarksmanTarget::TriggerSelf()
{
	
	if (bTriggerOnce && bTriggered)
	{
		return;
	}
	bTriggered = true;
	if (MoveActor != nullptr)
	{
		//MoveActor->Trigger(this, Level.GetClientPawn());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("MarksmanTarget::Trigger(): MoveActor is None"));
	}
	
}
void AMarksmanTarget::TriggerMover()
{
	
	if (MoveActor != nullptr)
	{
		//MoveActor->Trigger(this, Level.GetClientPawn());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("MarksmanTarget::TriggerMover(): MoveActor is None"));
	}
	
}
void AMarksmanTarget::ResetTarget(bool bResetMover)
{
	bTriggered = false;
	if (bResetMover && MoveActor != nullptr && MoveActor->KeyNum != 0)
	{
		TriggerMover();
	}
}
void AMarksmanTarget::CreateZones()
{
	
	UWorld* const World = GetWorld();
	if (World)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		AActor* const SpawningObject = World->SpawnActor<AActor>(AMarksmanTarget_Part::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
		Zone1 = Cast<AMarksmanTarget_Part>(SpawningObject);
	}

	if (Zone1 == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("MarksmanTarget::CreateZones(): Error: Couldn't spawn Zone1"));
		return;
	}
	//Zone1->SetStaticMesh(MyTarget.ZoneMesh);
	//Zone1->SetRotation(Rotation + MyTarget.Z1Rotation);
	//Zone1->SetLocation(Location);
	//Zone1->SetDrawScale(MyTarget.Z1Scale);
	//Zone1->SetDrawScale3D(MyTarget.Z1Scale3D);
	//Zone1->PrePivot = MyTarget.Z1Offset;
	//Zone1->SetBase(this);
	Zone1->SetMarksmanTarget(this);
	Zone1->SetZoneID("B");
	if (!bShowZoneB)
	{
		Zone1->SetActorHiddenInGame(true);
	}
	
	if (World)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		AActor* const SpawningObject = World->SpawnActor<AActor>(AMarksmanTarget_Part::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
		Zone2 = Cast<AMarksmanTarget_Part>(SpawningObject);
	}

	if (Zone2 == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("MarksmanTarget::CreateZones(): Error: Couldn't spawn Zone2"));
		return;
	}
	//Zone2->SetStaticMesh(MyTarget.ZoneMesh);
	//Zone2->SetRotation(Rotation + MyTarget.Z2Rotation);
	//Zone2->SetLocation(Location);
	//Zone2->SetDrawScale(MyTarget.Z2Scale);
	//Zone2->SetDrawScale3D(MyTarget.Z2Scale3D);
	//Zone2->PrePivot = MyTarget.Z2Offset * 1 / MyTarget.Z2Scale;
	//Zone2->SetBase(this);
	Zone2->SetMarksmanTarget(this);
	Zone2->SetZoneID("A");
	if (!bShowZoneA)
	{
		//Zone2->bHidden = true;
		Zone2->SetActorHiddenInGame(true);
	}
	if (bDoubleSidedZones)
	{
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			AActor* const SpawningObject = World->SpawnActor<AActor>(AMarksmanTarget_Part::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
			Zone3 = Cast<AMarksmanTarget_Part>(SpawningObject);
		}
		if (Zone3 == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("MarksmanTarget::CreateZones(): Error: Couldn't spawn Zone3"));
			return;
		}
		//Zone3->SetStaticMesh(MyTarget.ZoneMesh);
		//Zone3->SetRotation(Rotation + MyTarget.Z1Rotation);
		//Zone3->SetLocation(Location);
		//Zone3->SetDrawScale(MyTarget.Z1Scale);
		//Zone3->SetDrawScale3D(MyTarget.Z1Scale3D);
		//Zone3->PrePivot = MyTarget.Z1Offset + vect(4 0 0);
		//Zone3->SetBase(this);
		Zone3->SetMarksmanTarget(this);
		Zone3->SetZoneID("B");
		if (!bShowZoneB)
		{
			Zone3->SetActorHiddenInGame(true);
		}
		
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			AActor* const SpawningObject = World->SpawnActor<AActor>(AMarksmanTarget_Part::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
			Zone4 = Cast<AMarksmanTarget_Part>(SpawningObject);
		}
		if (Zone4 == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("MarksmanTarget::CreateZones(): Error: Couldn't spawn Zone4"));
			return;
		}
		//Zone4->SetStaticMesh(MyTarget.ZoneMesh);
		//Zone4->SetRotation(Rotation + MyTarget.Z1Rotation);
		//Zone4->SetLocation(Location);
		//Zone4->SetDrawScale(MyTarget.Z2Scale);
		//Zone4->SetDrawScale3D(MyTarget.Z2Scale3D);
		//Zone4->PrePivot = MyTarget.Z2Offset + vect(6 0 0) * 1 / MyTarget.Z2Scale;
		//Zone4->SetBase(this);
		Zone4->SetMarksmanTarget(this);
		Zone4->SetZoneID("A");
		if (!bShowZoneA)
		{
			Zone4->SetActorHiddenInGame(true);
		}
	}
	
}
void AMarksmanTarget::SetTargetType(ETargetType Type)
{
	TargetType = Type;
}
void AMarksmanTarget::SetNewTarget(ETargetType Type)
{
	SetTargetType(Type);
	SetRandomMesh();
}
void AMarksmanTarget::SetRandomTarget()
{
	SetRandomType();
	SetRandomMesh();
}
void AMarksmanTarget::SetRandomType()
{
	switch(FMath::RandRange(0,4))
	{
		case 0:
			TargetType = ETargetType::TT_BlueFor;
			break;
		case 1:
			TargetType = ETargetType::TT_OpFor;
			break;
		case 2:
			TargetType = ETargetType::TT_Indig;
			break;
		case 3:
			TargetType = ETargetType::TT_Civ;
			break;
		default:
			TargetType = ETargetType::TT_Civ;
	}
}
void AMarksmanTarget::SetRandomMesh()
{
	int32 Index;
	switch(TargetType)
	{
		case ETargetType::TT_BlueFor:
			Index = FMath::RandRange(0,MeshesBlueFor.Num()-1);
			MyTarget = MeshesBlueFor[Index];
			break;
		case ETargetType::TT_OpFor:
			Index = FMath::RandRange(0, MeshesOpFor.Num()-1);
			MyTarget = MeshesOpFor[Index];
			break;
		case ETargetType::TT_Indig:
			Index = FMath::RandRange(0, MeshesIndig.Num()-1);
			MyTarget = MeshesIndig[Index];
			break;
		case ETargetType::TT_Civ:
			Index = FMath::RandRange(0, MeshesCiv.Num()-1);
			MyTarget = MeshesCiv[Index];
			break;
		default:
			Index = FMath::RandRange(0, MeshesCiv.Num()-1);
			MyTarget = MeshesCiv[Index];
	}
	if (StaticMesh)
	{
		if(MyTarget.StaticMesh)
		{
			StaticMesh->SetStaticMesh(MyTarget.StaticMesh);
		}
	}
}

void AMarksmanTarget::SetMesh(int32 Index)
{
	
	switch(TargetType)
	{
		case ETargetType::TT_BlueFor:
			MyTarget = MeshesBlueFor[Index];
			break;
		case ETargetType::TT_OpFor:
			MyTarget = MeshesOpFor[Index];
			break;
		case ETargetType::TT_Indig:
			MyTarget = MeshesIndig[Index];
			break;
		case ETargetType::TT_Civ:
			MyTarget = MeshesCiv[Index];
			break;
		default:
			MyTarget = MeshesCiv[Index];
	}
	if (StaticMesh)
	{
		if (MyTarget.StaticMesh)
		{
			StaticMesh->SetStaticMesh(MyTarget.StaticMesh);
		}
	}
}
/*
void AMarksmanTarget::TakeDamage(int Damage, Pawn EventInstigator, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
{
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self, 8, EventInstigator, GetEnum(Enum'ETargetType', TargetType) $ "," $ ZoneID);
	}
	if (bShootToTrigger)
	{
		Trigger(Self, EventInstigator);
	}
}
*/

/*
void AMarksmanTarget::NotifyDamaged(int Damage, Pawn EventInstigator, class<DamageType>  DamageType, string Id)
{
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self, 8, EventInstigator, GetEnum(Enum'ETargetType', TargetType) $ "," $ Id);
	}
	if (bShootToTrigger)
	{
		Trigger(Self, EventInstigator);
	}
}
*/

