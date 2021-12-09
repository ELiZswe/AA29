// All the original content belonged to the US Army


#include "Proj_50Cal.h"
#include "AA29/Object/DamageType/CROWS_50CalDamage/CROWS_50CalDamage.h"

AProj_50Cal::AProj_50Cal(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//	MetalImpactEmitter = AProj_50Cal_MetalEffectEmitter::StaticClass();
	//	cTracerClass = ABaseTracerEmitter::StaticClass();
		//		\\DamageClasses =
		//		ArmorThreshold = Class'AGP_Inventory.Proj_40Gren'
	Speed             = 40000;
	Damage            = 150;
	MomentumTransfer  = 5000;
	MyDamageType      = UCROWS_50CalDamage::StaticClass();
	DrawType          = EDrawType::DT_None;
	DrawScale         = 1;
	CollisionRadius   = 1;
	CollisionHeight   = 1;
}