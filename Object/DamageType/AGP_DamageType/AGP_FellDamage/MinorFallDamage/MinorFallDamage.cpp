// All the original content belonged to the US Army

#include "AA29/Object/DamageType/AGP_DamageType/AGP_FellDamage/MinorFallDamage/MinorFallDamage.h"

UMinorFallDamage::UMinorFallDamage()
{
	PawnDamageSounds     = { LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Movement/human_movement_oomph.human_movement_oomph"), NULL, LOAD_None, NULL) };
	LowGoreDamageSounds  = { LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Human/Movement/human_movement_oomph.human_movement_oomph"), NULL, LOAD_None, NULL) };
}
