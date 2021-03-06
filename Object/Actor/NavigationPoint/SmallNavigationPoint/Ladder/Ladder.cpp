// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/Ladder/Ladder.h"
#include "AA29/Object/Actor/Brush/Volume/PhysicsVolume/LadderVolume/LadderVolume.h"

ALadder::ALadder()
{
	bSpecialMove = true;
	bNotBased = true;
	//Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/S_Ladder_Mat.S_Ladder_Mat'"), NULL, LOAD_None, NULL);
	//CollisionRadius = 35;
}

bool ALadder::SuggestMovePreparation(APawn* Other)
{
	if (MyLadder == nullptr)
	{
		return false;
	}
	if (!MyLadder->InUse(Other))
	{
		//MyLadder.PendingClimber = Other;
		return false;
	}
	//Other.Controller.bPreparingMove = true;
	//Other.Acceleration = FVector(0, 0, 0);
	return true;
}
