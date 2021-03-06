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
	asndLastSoundsPlayed.SetNum(20);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	sDescription = "Default Soldier Voice";
	//bHidden = true;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_NCPSpeechManager.S_NCPSpeechManager'"), NULL, LOAD_None, NULL);
	bCollideWhenPlacing = true;
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
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_concern2_Cue.s_npc_enemyvoice1_concern2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_concern3_Cue.s_npc_enemyvoice1_concern3_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_concern4_Cue.s_npc_enemyvoice1_concern4_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_concern5_Cue.s_npc_enemyvoice1_concern5_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_concern6_Cue.s_npc_enemyvoice1_concern6_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_concern7_Cue.s_npc_enemyvoice1_concern7_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_concern8_Cue.s_npc_enemyvoice1_concern8_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_concern9_Cue.s_npc_enemyvoice1_concern9_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_concern10_Cue.s_npc_enemyvoice1_concern10_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_concern11_Cue.s_npc_enemyvoice1_concern11_Cue'"), NULL, LOAD_None, NULL)
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
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_taunt10_Cue.s_npc_enemyvoice1_taunt10_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_taunt11_Cue.s_npc_enemyvoice1_taunt11_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_taunt12_Cue.s_npc_enemyvoice1_taunt12_Cue'"), NULL, LOAD_None, NULL)
	};
	asndMaleWoundedSounds = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_wounded1_Cue.s_npc_enemyvoice1_wounded1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_wounded2_Cue.s_npc_enemyvoice1_wounded2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_wounded3_Cue.s_npc_enemyvoice1_wounded3_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_wounded1a_Cue.s_npc_enemyvoice1_wounded1a_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_wounded1b_Cue.s_npc_enemyvoice1_wounded1b_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_wounded2a_Cue.s_npc_enemyvoice1_wounded2a_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_wounded2b_Cue.s_npc_enemyvoice1_wounded2b_Cue'"), NULL, LOAD_None, NULL)
	};
	asndMaleFriendWoundedSounds = {
	LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_allyhit1_Cue.s_npc_enemyvoice1_allyhit1_Cue'"), NULL, LOAD_None, NULL),
	LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_allyhit2_Cue.s_npc_enemyvoice1_allyhit2_Cue'"), NULL, LOAD_None, NULL),
	LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_allyhit3_Cue.s_npc_enemyvoice1_allyhit3_Cue'"), NULL, LOAD_None, NULL)
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
	LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_vehicle3_Cue.s_npc_enemyvoice1_vehicle3_Cue'"), NULL, LOAD_None, NULL)
	};
	asndMaleEnemySpottedSounds = {
	LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_spotted1_Cue.s_npc_enemyvoice1_spotted1_Cue'"), NULL, LOAD_None, NULL),
	LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_spotted2_Cue.s_npc_enemyvoice1_spotted2_Cue'"), NULL, LOAD_None, NULL),
	LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_spotted3_Cue.s_npc_enemyvoice1_spotted3_Cue'"), NULL, LOAD_None, NULL)
	};
	asndMaleWarningSounds = {
	LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_warning1_Cue.s_npc_enemyvoice1_warning1_Cue'"), NULL, LOAD_None, NULL),
	LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_warning2_Cue.s_npc_enemyvoice1_warning2_Cue'"), NULL, LOAD_None, NULL),
	LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_NPC/EnemyVoice1/s_npc_enemyvoice1_warning3_Cue.s_npc_enemyvoice1_warning3_Cue'"), NULL, LOAD_None, NULL)
	};

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Actor.S_Actor'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}


void ANPCSpeechManager::BeginPlay()
{
	Super::BeginPlay();
}


void ANPCSpeechManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANPCSpeechManager::PostBeginPlay()
{
	/*
	if (GetWorld()->GetNetMode() == NM_Standalone)
	{
		Log(string(this) + "PostBeginPlay() - saving configuration");
		SaveConfig();
	}
	*/
}

USoundBase* ANPCSpeechManager::GetRandomAttackingSounds(bool bIsMaleVoice)
{
	/*
	if (bIsMaleVoice)
	{
		if (asndMaleAttackingSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndMaleAttackingSounds[Rand(asndMaleAttackingSounds.Num())];
	}
	else
	{
		if (asndFemaleAttackingSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndFemaleAttackingSounds[Rand(asndFemaleAttackingSounds.Num())];
	}
	*/
	return nullptr;   //FAKE  /ELiZ
}

USoundBase* ANPCSpeechManager::GetRandomInjuredSounds(bool bIsMaleVoice)
{
	/*
	if (bIsMaleVoice)
	{
		if (asndMaleInjuredSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndMaleInjuredSounds[Rand(asndMaleInjuredSounds.Num())];
	}
	else
	{
		if (asndFemaleInjuredSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndFemaleInjuredSounds[Rand(asndFemaleInjuredSounds.Num())];
	}
	*/
	return nullptr;   //FAKE  /ELiZ
}

USoundBase* ANPCSpeechManager::GetRandomTerrifiedSounds(bool bIsMaleVoice)
{
	/*
	if (bIsMaleVoice)
	{
		if (asndMaleTerrifiedSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndMaleTerrifiedSounds[Rand(asndMaleTerrifiedSounds.Num())];
	}
	else
	{
		if (asndFemaleTerrifiedSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndFemaleTerrifiedSounds[Rand(asndFemaleTerrifiedSounds.Num())];
	}
	*/
	return nullptr;   //FAKE  /ELiZ
}

USoundBase* ANPCSpeechManager::GetRandomAngrySounds(bool bIsMaleVoice)
{
	/*
	if (bIsMaleVoice)
	{
		if (asndMaleAngrySounds.Num() == 0)
		{
			return nullptr;
		}
		return asndMaleAngrySounds[Rand(asndMaleAngrySounds.Num())];
	}
	else
	{
		if (asndFemaleAngrySounds.Num() == 0)
		{
			return nullptr;
		}
		return asndFemaleAngrySounds[Rand(asndFemaleAngrySounds.Num())];
	}
	*/
	return nullptr;   //FAKE  /ELiZ
}

USoundBase* ANPCSpeechManager::GetRandomIdleSounds(bool bIsMaleVoice)
{
	/*
	if (bIsMaleVoice)
	{
		if (asndMaleIdleSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndMaleIdleSounds[Rand(asndMaleIdleSounds.Num())];
	}
	else
	{
		if (asndFemaleIdleSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndFemaleIdleSounds[Rand(asndFemaleIdleSounds.Num())];
	}
	*/
	return nullptr;   //FAKE  /ELiZ
}

USoundBase* ANPCSpeechManager::GetRandomConcernedSounds(bool bIsMaleVoice)
{
	/*
	if (bIsMaleVoice)
	{
		if (asndMaleConcernedSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndMaleConcernedSounds[Rand(asndMaleConcernedSounds.Num())];
	}
	else
	{
		if (asndFemaleConcernedSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndFemaleConcernedSounds[Rand(asndFemaleConcernedSounds.Num())];
	}
	*/
	return nullptr;   //FAKE  /ELiZ
}

USoundBase* ANPCSpeechManager::GetRandomTauntSounds(bool bIsMaleVoice)
{
	/*
	if (bIsMaleVoice)
	{
		if (asndMaleTauntSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndMaleTauntSounds[Rand(asndMaleTauntSounds.Num())];
	}
	else
	{
		if (asndFemaleTauntSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndFemaleTauntSounds[Rand(asndFemaleTauntSounds.Num())];
	}
	*/
	return nullptr;   //FAKE  /ELiZ
}

USoundBase* ANPCSpeechManager::GetRandomWoundedSounds(bool bIsMaleVoice)
{
	/*
	if (bIsMaleVoice)
	{
		if (asndMaleWoundedSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndMaleWoundedSounds[Rand(asndMaleWoundedSounds.Num())];
	}
	else
	{
		if (asndFemaleWoundedSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndFemaleWoundedSounds[Rand(asndFemaleWoundedSounds.Num())];
	}
	*/
	return nullptr;   //FAKE  /ELiZ
}

USoundBase* ANPCSpeechManager::GetRandomFriendWoundedSounds(bool bIsMaleVoice)
{
	/*
	if (bIsMaleVoice)
	{
		if (asndMaleFriendWoundedSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndMaleFriendWoundedSounds[Rand(asndMaleFriendWoundedSounds.Num())];
	}
	else
	{
		if (asndFemaleFriendWoundedSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndFemaleFriendWoundedSounds[Rand(asndFemaleFriendWoundedSounds.Num())];
	}
	*/
	return nullptr;   //FAKE  /ELiZ
}

USoundBase* ANPCSpeechManager::GetRandomGrenadeSounds(bool bIsMaleVoice)
{
	/*
	if (bIsMaleVoice)
	{
		if (asndMaleGrenadeSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndMaleGrenadeSounds[Rand(asndMaleGrenadeSounds.Num())];
	}
	else
	{
		if (asndFemaleGrenadeSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndFemaleGrenadeSounds[Rand(asndFemaleGrenadeSounds.Num())];
	}
	*/
	return nullptr;   //FAKE  /ELiZ
}

USoundBase* ANPCSpeechManager::GetRandomFriendDownSounds(bool bIsMaleVoice)
{
	/*
	if (bIsMaleVoice)
	{
		if (asndMaleFriendDownSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndMaleFriendDownSounds[Rand(asndMaleFriendDownSounds.Num())];
	}
	else
	{
		if (asndFemaleFriendDownSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndFemaleFriendDownSounds[Rand(asndFemaleFriendDownSounds.Num())];
	}
	*/
	return nullptr;   //FAKE  /ELiZ
}

USoundBase* ANPCSpeechManager::GetRandomSurrenderSounds(bool bIsMaleVoice)
{
	/*
	if (bIsMaleVoice)
	{
		if (asndMaleSurrenderSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndMaleSurrenderSounds[Rand(asndMaleSurrenderSounds.Num())];
	}
	else
	{
		if (asndFemaleSurrenderSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndFemaleSurrenderSounds[Rand(asndFemaleSurrenderSounds.Num())];
	}
	*/
	return nullptr;   //FAKE  /ELiZ
}

USoundBase* ANPCSpeechManager::GetRandomVehicleSpottedSounds(bool bIsMaleVoice)
{
	/*
	if (bIsMaleVoice)
	{
		if (asndMaleVehicleSpottedSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndMaleVehicleSpottedSounds[Rand(asndMaleVehicleSpottedSounds.Num())];
	}
	else
	{
		if (asndFemaleVehicleSpottedSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndFemaleVehicleSpottedSounds[Rand(asndFemaleVehicleSpottedSounds.Num())];
	}
	*/
	return nullptr;   //FAKE  /ELiZ
}

USoundBase* ANPCSpeechManager::GetRandomEnemySpottedSounds(bool bIsMaleVoice)
{
	/*
	if (bIsMaleVoice)
	{
		if (asndMaleEnemySpottedSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndMaleEnemySpottedSounds[Rand(asndMaleEnemySpottedSounds.Num())];
	}
	else
	{
		if (asndFemaleEnemySpottedSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndFemaleEnemySpottedSounds[Rand(asndFemaleEnemySpottedSounds.Num())];
	}
	*/
	return nullptr;   //FAKE  /ELiZ
}

USoundBase* ANPCSpeechManager::GetRandomWarningSounds(bool bIsMaleVoice)
{
	/*
	if (bIsMaleVoice)
	{
		if (asndMaleWarningSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndMaleWarningSounds[Rand(asndMaleWarningSounds.Num())];
	}
	else
	{
		if (asndFemaleWarningSounds.Num() == 0)
		{
			return nullptr;
		}
		return asndFemaleWarningSounds[Rand(asndFemaleWarningSounds.Num())];
	}
	*/
	return nullptr;   //FAKE  /ELiZ
}

bool ANPCSpeechManager::AddSoundToSoundHistory(USoundBase* Snd)
{
	/*
	int32 iSound = 0;
	for (iSound = 0; iSound < 20; iSound++)
	{
		if (asndLastSoundsPlayed[iSoundEntryIndexForTracking] == Snd)
		{
			return false;
		}
	}
	asndLastSoundsPlayed[iSoundEntryIndexForTracking] = Snd;
	if (iSoundEntryIndexForTracking < (20 - 1))
	{
		iSoundEntryIndexForTracking++;
	}
	else
	{
		iSoundEntryIndexForTracking = 0;
	}
	*/
	return true;
}
