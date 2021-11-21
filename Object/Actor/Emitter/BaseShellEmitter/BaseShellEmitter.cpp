// All the original content belonged to the US Army


#include "BaseShellEmitter.h"

ABaseShellEmitter::ABaseShellEmitter()
{
	sWood = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingWood1.WeaponFX_Shells_CasingWood1"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingWood2.WeaponFX_Shells_CasingWood2"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingWood3.WeaponFX_Shells_CasingWood3"), NULL, LOAD_None, NULL)
	};
	sConcrete = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingConcrete1.WeaponFX_Shells_CasingConcrete1"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingConcrete2.WeaponFX_Shells_CasingConcrete2"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingConcrete3.WeaponFX_Shells_CasingConcrete3"), NULL, LOAD_None, NULL)
	};
	sMetal = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingMetal1.WeaponFX_Shells_CasingMetal1"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingMetal2.WeaponFX_Shells_CasingMetal2"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingMetal3.WeaponFX_Shells_CasingMetal3"), NULL, LOAD_None, NULL)
	};
	sWater = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingWater1.WeaponFX_Shells_CasingWater1"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingWater2.WeaponFX_Shells_CasingWater2"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingWater3.WeaponFX_Shells_CasingWater3"), NULL, LOAD_None, NULL)
	};
	sDirt = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingMuffled1.WeaponFX_Shells_CasingMuffled1"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingMuffled2.WeaponFX_Shells_CasingMuffled2"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingMuffled3.WeaponFX_Shells_CasingMuffled3"), NULL, LOAD_None, NULL)
	};

		fPitchModifier = 1;
	//Emitters(0) = MeshEmitter'AGP_Effects.BaseShellEmitter.MeshEmitter0'
	//	bNoDelete = false;
		//bTrailerSameRotation = true;
	//Physics = 10;
	//RemoteRole = 0;
	//Mass = 4;
	//bRenderAttachmentSeperately = true;
}