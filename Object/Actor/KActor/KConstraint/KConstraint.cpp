// All the original content belonged to the US Army


#include "AA29/Object/Actor/KActor/KConstraint/KConstraint.h"

AKConstraint::AKConstraint()
{
	bKDisableCollision = true;
	KPriAxis1 = FVector(1, 0, 0);
	KSecAxis1 = FVector(0, 1, 0);
	KPriAxis2 = FVector(1, 0, 0);
	KSecAxis2 = FVector(0, 1, 0);
	//DrawType = DT_Sprite;
	//bHidden = true;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_KConstraint.S_KConstraint'"), NULL, LOAD_None, NULL);
	//bCollideActors = false;
	//bBlockActors = false;
	//bProjTarget = false;
	//bBlockKarma = false;
}

//native Function KUpdateConstraintParams();
void AKConstraint::KUpdateConstraintParams()
{

}

//native final Function KGetConstraintForce(Vector& Force);
void AKConstraint::KGetConstraintForce(FVector& Force)
{

}

//native final Function KGetConstraintTorque(Vector& Torque);
void AKConstraint::KGetConstraintTorque(FVector& Torque)
{

}

void AKConstraint::KForceExceed(float forceMag)
{
}
