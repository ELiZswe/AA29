// All the original content belonged to the US Army


#include "AA29/Object/Actor/NPCSpeechManager/NPCSpeechManager.h"
#include "Components/BillboardComponent.h"

void ANPCSpeechManager::LoadEditorIcon()
{

#if WITH_EDITORONLY_DATA
	bool UBillboardComponentExists = false;

	TArray<UObject*> ObjectArray;
	GetDefaultSubobjects(ObjectArray);
	for (UObject* ThisObject : ObjectArray)
	{
		if (ThisObject->GetName() == "Sprite")
		{
			if (Texture != NULL)
			{
				SpriteComponent = Cast<UBillboardComponent>(ThisObject);
				SpriteComponent->Sprite = Texture;
				UBillboardComponentExists = true;
			}
		}
	}
	if (!UBillboardComponentExists)
	{
		SpriteComponent = CreateDefaultSubobject<UBillboardComponent>(TEXT("Sprite"));
		SpriteComponent->Sprite = Texture;
		SpriteComponent->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
		SpriteComponent->SetWorldScale3D(FVector(4, 4, 4));
	}
#endif // WITH_EDITORONLY_DATA
}
// Sets default values
ANPCSpeechManager::ANPCSpeechManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	sDescription = "Default Soldier Voice";

	asndMaleIdleSounds = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_idle1_Cue.s_npc_enemyvoice1_idle1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_idle2_Cue.s_npc_enemyvoice1_idle2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_idle3_Cue.s_npc_enemyvoice1_idle3_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_idle4_Cue.s_npc_enemyvoice1_idle4_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_idle5_Cue.s_npc_enemyvoice1_idle5_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_idle6_Cue.s_npc_enemyvoice1_idle6_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_idle7_Cue.s_npc_enemyvoice1_idle7_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_idle8_Cue.s_npc_enemyvoice1_idle8_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_idle9_Cue.s_npc_enemyvoice1_idle9_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_idle10_Cue.s_npc_enemyvoice1_idle10_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_idle11_Cue.s_npc_enemyvoice1_idle11_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_idle12_Cue.s_npc_enemyvoice1_idle12_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_idle13_Cue.s_npc_enemyvoice1_idle13_Cue'"), NULL, LOAD_None, NULL)
	};

	asndMaleAttackingSounds = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_attack1_Cue.s_npc_enemyvoice1_attack1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_attack2_Cue.s_npc_enemyvoice1_attack2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_attack3_Cue.s_npc_enemyvoice1_attack3_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_attack4_Cue.s_npc_enemyvoice1_attack4_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_attack5_Cue.s_npc_enemyvoice1_attack5_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_attack6_Cue.s_npc_enemyvoice1_attack6_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_attack7_Cue.s_npc_enemyvoice1_attack7_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_attack8_Cue.s_npc_enemyvoice1_attack8_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_attack9_Cue.s_npc_enemyvoice1_attack9_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_attack10_Cue.s_npc_enemyvoice1_attack10_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_attack11_Cue.s_npc_enemyvoice1_attack11_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_attack12_Cue.s_npc_enemyvoice1_attack12_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_attack13_Cue.s_npc_enemyvoice1_attack13_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_attack14_Cue.s_npc_enemyvoice1_attack14_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_attack8b_Cue.s_npc_enemyvoice1_attack8b_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_attack8c_Cue.s_npc_enemyvoice1_attack8c_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_attack9b_Cue.s_npc_enemyvoice1_attack9b_Cue'"), NULL, LOAD_None, NULL)
	};

	asndMaleConcernedSounds = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_concern1_Cue.s_npc_enemyvoice1_concern1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_concern2_Cue.s_npc_enemyvoice2_concern1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_concern3_Cue.s_npc_enemyvoice3_concern1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_concern4_Cue.s_npc_enemyvoice4_concern1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_concern5_Cue.s_npc_enemyvoice5_concern1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_concern6_Cue.s_npc_enemyvoice6_concern1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_concern7_Cue.s_npc_enemyvoice7_concern1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_concern8_Cue.s_npc_enemyvoice8_concern1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_concern9_Cue.s_npc_enemyvoice9_concern1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_concern10_Cue.s_npc_enemyvoice10_concern1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_concern11_Cue.s_npc_enemyvoice11_concern1_Cue'"), NULL, LOAD_None, NULL)
	};
	
	asndMaleAngrySounds = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_angry1_Cue.s_npc_enemyvoice1_angry1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_angry2_Cue.s_npc_enemyvoice1_angry2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_angry3_Cue.s_npc_enemyvoice1_angry3_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_angry4_Cue.s_npc_enemyvoice1_angry4_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_angry5_Cue.s_npc_enemyvoice1_angry5_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_angry6_Cue.s_npc_enemyvoice1_angry6_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_angry7_Cue.s_npc_enemyvoice1_angry7_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_angry8_Cue.s_npc_enemyvoice1_angry8_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_angry9_Cue.s_npc_enemyvoice1_angry9_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_angry10_Cue.s_npc_enemyvoice1_angry10_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_angry11_Cue.s_npc_enemyvoice1_angry11_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_angry12_Cue.s_npc_enemyvoice1_angry12_Cue'"), NULL, LOAD_None, NULL)
	};

	asndMaleTerrifiedSounds = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_panic1_Cue.s_npc_enemyvoice1_panic1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_panic2_Cue.s_npc_enemyvoice1_panic2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_panic3_Cue.s_npc_enemyvoice1_panic3_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_panic4_Cue.s_npc_enemyvoice1_panic4_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_panic5_Cue.s_npc_enemyvoice1_panic5_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_panic6_Cue.s_npc_enemyvoice1_panic6_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_panic7_Cue.s_npc_enemyvoice1_panic7_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_panic8_Cue.s_npc_enemyvoice1_panic8_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_panic9_Cue.s_npc_enemyvoice1_panic9_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_panic10_Cue.s_npc_enemyvoice1_panic10_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_panic11_Cue.s_npc_enemyvoice1_panic11_Cue'"), NULL, LOAD_None, NULL)
	};

	asndMaleInjuredSounds = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_injury1_Cue.s_npc_enemyvoice1_injury1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_injury2_Cue.s_npc_enemyvoice1_injury2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_injury3_Cue.s_npc_enemyvoice1_injury3_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_injury4_Cue.s_npc_enemyvoice1_injury4_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_injury5_Cue.s_npc_enemyvoice1_injury5_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_injury6_Cue.s_npc_enemyvoice1_injury6_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_injury7_Cue.s_npc_enemyvoice1_injury7_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_injury8_Cue.s_npc_enemyvoice1_injury8_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_injury9_Cue.s_npc_enemyvoice1_injury9_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_injury10_Cue.s_npc_enemyvoice1_injury10_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_injury11_Cue.s_npc_enemyvoice1_injury11_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_injury12_Cue.s_npc_enemyvoice1_injury12_Cue'"), NULL, LOAD_None, NULL)
	};
	asndMaleTauntSounds = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_taunt1_Cue.s_npc_enemyvoice1_taunt1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_taunt2_Cue.s_npc_enemyvoice1_taunt2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_taunt3_Cue.s_npc_enemyvoice1_taunt3_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_taunt4_Cue.s_npc_enemyvoice1_taunt4_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_taunt5_Cue.s_npc_enemyvoice1_taunt5_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_taunt6_Cue.s_npc_enemyvoice1_taunt6_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_taunt7_Cue.s_npc_enemyvoice1_taunt7_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_taunt8_Cue.s_npc_enemyvoice1_taunt8_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_taunt9_Cue.s_npc_enemyvoice1_taunt9_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_taunt10_Cue.s_npc_enemyvoice1_taunt10_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_taunt11_Cue.s_npc_enemyvoice1_taunt11_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_taunt12_Cue.s_npc_enemyvoice1_taunt12_Cue'"), NULL, LOAD_None, NULL)
	};

	asndMaleWoundedSounds = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC.EnemyVoice1.s_npc_enemyvoice1_wounded1_Cue.s_npc_enemyvoice1_wounded1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC.EnemyVoice1.s_npc_enemyvoice1_wounded2_Cue.s_npc_enemyvoice1_wounded2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC.EnemyVoice1.s_npc_enemyvoice1_wounded3_Cue.s_npc_enemyvoice1_wounded3_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC.EnemyVoice1.s_npc_enemyvoice1_wounded1a_Cue.s_npc_enemyvoice1_wounded1a_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC.EnemyVoice1.s_npc_enemyvoice1_wounded1b_Cue.s_npc_enemyvoice1_wounded1b_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC.EnemyVoice1.s_npc_enemyvoice1_wounded2a_Cue.s_npc_enemyvoice1_wounded2a_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC.EnemyVoice1.s_npc_enemyvoice1_wounded2b_Cue.s_npc_enemyvoice1_wounded2b_Cue'"), NULL, LOAD_None, NULL)
	};
	asndMaleFriendWoundedSounds = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC.EnemyVoice1.s_npc_enemyvoice1_allyhit1_Cue.s_npc_enemyvoice1_allyhit1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC.EnemyVoice1.s_npc_enemyvoice1_allyhit2_Cue.s_npc_enemyvoice1_allyhit2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC.EnemyVoice1.s_npc_enemyvoice1_allyhit3_Cue.s_npc_enemyvoice1_allyhit3_Cue'"), NULL, LOAD_None, NULL)
	};

	asndMaleGrenadeSounds = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_grenade1_Cue.s_npc_enemyvoice1_grenade1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_grenade2_Cue.s_npc_enemyvoice1_grenade2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_grenade3_Cue.s_npc_enemyvoice1_grenade3_Cue'"), NULL, LOAD_None, NULL)
	};

	asndMaleSurrenderSounds = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_surrender1_Cue.s_npc_enemyvoice1_surrender1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_surrender2_Cue.s_npc_enemyvoice1_surrender2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_surrender3_Cue.s_npc_enemyvoice1_surrender3_Cue'"), NULL, LOAD_None, NULL)

	};
	asndMaleVehicleSpottedSounds = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_vehicle1_Cue.s_npc_enemyvoice1_vehicle1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_vehicle2_Cue.s_npc_enemyvoice1_vehicle2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_vehicle3_Cue.s_npc_enemyvoice1_vehicle3_Cue'"), NULL, LOAD_None, NULL),
	};
	asndMaleEnemySpottedSounds = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_spotted1_Cue.s_npc_enemyvoice1_spotted1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_spotted2_Cue.s_npc_enemyvoice1_spotted2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_spotted3_Cue.s_npc_enemyvoice1_spotted3_Cue'"), NULL, LOAD_None, NULL)
	};
	asndMaleWarningSounds = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_warning1'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice2/s_npc_enemyvoice1_warning2'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice3/s_npc_enemyvoice1_warning3'"), NULL, LOAD_None, NULL)
	};

	//bHidden = true;
	//Texture = Texture'AGP.S_NCPSpeechManager';
	//bCollideWhenPlacing = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Actor.S_Actor'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();

}

// Called when the game starts or when spawned
void ANPCSpeechManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPCSpeechManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

