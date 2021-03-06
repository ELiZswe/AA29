// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_CampMackall_Language/EL_CampMackall_Language.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/AGP_Location/AGP_Location.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/AGP_Trigger/AGP_Trigger.h"
#include "AA29/Object/Actor/AGP_UseTrigger/AGP_UseTrigger.h"
#include "AA29/Object/Actor/AGP_UseTrigger/DoorTrigger/DoorTrigger.h"
#include "AA29/Object/Actor/MedExam/MedExam.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_NPC/NPC_MedInstructor/NPC_MedInstructor.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_NPC/NPC_MedStudent/NPC_MedStudent.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Projector/SlideProjector/SlideProjector.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/StudentController/StudentController.h"
#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoShout/CommoShout.h"
#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoTestAnswers/CommoTestAnswers.h"
#include "AA29/Object/Actor/EffectLocation/EffectLocation.h"
#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoLocalMessage.h"

AEL_CampMackall_Language::AEL_CampMackall_Language()
{
	LSAnims = {
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Cue.Guy1_Cue'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} })
	};
}

/*
State ResetLevel
{
	Function BeginState()
	{
		StartTimer("reloadLevel",5,false);
		FadeOut(2,true);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "reloadLevel")
		{
			ResetLipsincAnim();
			Player.SetLocation(GetActorLocation("PlayerStartLocation"));
			Controller.SetRotation(GetActorRotation("PlayerStartLocation"));
			FadeIn(2,true);
			PlayTip("Locate the Class Room","Language course",5);
			ChangeState("EnterClass");
		}
		return Super::Timer_Timer(Name);
	}
}
*/

/*
State EnterAudioLab
{
	Function BeginState()
	{
		if (bEnteredAudioLab == false)
		{
			bEnteredAudioLab=true;
			PlayLSAnim("SFInstructor02_Greeting",InstructorTwo,1,512);
			PlayerLock(true,false);
			StartTimer("audioLabMessageOneTimer",5,false);
			StartTimer("audioLabMessageTwoTimer",20,false);
			StartTimer("audioLabMessageThreeTimer",30,false);
		}
	}
	Function bool SeatTriggerTwo_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		UnCaptureEvent(SeatTriggerTwo);
		if (TalkedToInstructor && bHeadPhonesOn)
		{
			Log("Inside Talked and HEADPHONES so practice should be starting and player sat down!@!@!@!@!@!@");
			headphones.bHidden=true;
			Cast<AStudentController>(Controller)->bForceSit=true;
			StartTimer("audioLabSatDown",1,false);
			HidePlayer();
			PlayerLock(true,true);
		}
		else
		{
			Cast<AStudentController>(Controller)->bForceSit=false;
			PlayerLock(false,false);
		}
		return true;
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor02_Greeting")
		{
			PlayerLock(false,false);
			TalkedToInstructor=true;
			PlayTip("Take a seat at","Cubicle B-3",5);
		}
		return true;
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "audioLabMessageOneTimer")
		{
			PlayTip("Locate cubicle B-3","and take a seat",5);
		}
		if (Name == "audioLabMessageTwoTimer")
		{
			PlayTip("The practice portion of the test","will begin in 15 seconds",5);
		}
		if (Name == "audioLabMessageThreeTimer")
		{
			PlayTip("Remember to pickup your headphones","off the counter",5);
		}
		if (Name == "audioLabSatDown")
		{
			Log("@#@#@# INSIDE AUDIOLABSATDOWN @#@#@#");
			PlayTip("Your practice test questions are being prepared","",5);
			StartTimer("audioLabUsedHeadPhones",5,false);
		}
		else
		{
			if (Name == "audioLabUsedHeadPhones")
			{
				PlayTip("When finished with practice","press the 0 key",3);
				ChangeState("AudioPractice");
			}
		}
		return GlobalTimer(Name);
	}
	Function bool AGP_Hud_Custom(AAGP_HUD* NotifyActor, AActor* Instigator, FString Parms)
	{
		int32 Key = 0;
		ParseParms(Parms);
		if (fRepeatQuestionTime > GetWorld()->GetTimeSeconds())
		{
			return false;
		}
		if (Cast<AStudentController>(Controller)->IsSeated() == false)
		{
			return false;
		}
		if (ParmList[0] == "KeyPress")
		{
			Key=int(ParmList[1]);
			fRepeatQuestionTime=(GetWorld()->GetTimeSeconds() + 1.5);
			if ((Key >= 48) && (Key <= 57))
			{
				Level.bEnableCommo=false;
				if (Key == 48)
				{
					bStartTest=true;
					ChangeState("AudioLabTest");
				}
				else
				{
					if (Key == 57)
					{
						Level.bEnableCommo=true;
						PrepareQuestion();
					}
					else
					{
						bNextQuestion=true;
						DisplayCorrectAnswer(Key);
						UpdateTestAnswers(-1);
						LastQuestion=0;
					}
				}
				return true;
			}
		}
		return false;
	}
}
*/

/*
State AudioPractice extends EnterAudioLab
{
Begin:
	Sleep(1);
	Cast<AStudentController>(Controller)->bForceSit=true;
	HidePlayer();
	PlayerLock(true,true);
	bNextQuestion=false;
	PrepareQuestion();
	Sleep(0.1);
	if (Cast<AStudentController>(Controller)->IsSeated())
	{
		Level.bEnableCommo=true;
	}
	else
	{
		Level.bEnableCommo=false;
	}
	if (bStartTest)
	{
		JL"End"
;
	}
	else
	{
		if (bNextQuestion)
		{
			JL"Begin"
;
		}
		else
		{
			JL"Loop"
;
		}
	}
}
*/

/*
State AudioLabTest
{
	Function BeginState()
	{
		PlayTip("Testing will begin","in 5 seconds",3);
		UpdateCorrectAnswersFromLecture();
		PlayLSAnim("SFInstructor02_Exam",NPC_AudioLabStudent01_07,1,512);
		StartTimer("audiolabteststarttimer",20,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "audiolabteststarttimer")
		{
			Controller.GotoState("SFClassTwoTesting");
		}
		return GlobalTimer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor02_Exam")
		{
			ChangeState("BeginTest");
		}
		return true;
	}
}
*/

/*
State EnterClass
{
	Function BeginState()
	{
		StartTimer("EnterClass_GlobalTimer",30,false);
		bClassEntered=false;
		PlayTip("Locate the Class Room","Language course",10);
	}
	Function bool ClassVolumeOne_Enter(AGP_Gameplay.TriggerVolume* Trigger, AActor* Instigator)
	{
		if (DoorTriggerOne.IsOpen())
		{
			DoorTriggerOne.ToggleOpen();
		}
		StopTimer("EnterClass_GlobalTimer",0);
		bClassEntered=true;
		UnCaptureEvent(ClassVolumeOne);
		PlayLSAnim("SFInstructor_WelcomeToClass",InstructorOne,1,512);
		PlayTip("Talk to people in your class by pressing","the <action> key while facing somebody",5);
		ChangeState("inClass");
		return true;
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "EnterClass_GlobalTimer")
		{
			if (bClassEntered == false)
			{
				PlayTip("Hurry the class","is about to begin",3);
				return true;
			}
		}
		return GlobalTimer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		return true;
	}
}
*/

/*
State inClass
{
	Function BeginState()
	{
		StartTimer("tmrBeginClass",20,false);
	}
	Function EndState()
	{
	}
	Function bool InstructorTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		if (InstructorUseCount == 0)
		{
			PlayLSAnim("SFInstructor_TakeYourSeat",InstructorOne,1,512);
			InstructorUseCount ++;
			return true;
		}
		if (InstructorUseCount <= 2)
		{
			PlayLSAnim("SFInstructor_TakeYourSeat",InstructorOne,1,512);
			InstructorUseCount ++;
			return true;
		}
		return true;
	}
	Function bool SeatTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		UnCaptureEvent(SeatTriggerOne);
		StartTimer("tmrSatDown",1,false);
		PlayTip("When the lecture ends, you can exit your chair","by pressing the <jump> key",5);
		return true;
	}
	Function bool SeatVolumeOne_Trigger(AGP_Gameplay.AGP_Trigger* Trigger, AActor* Instigator)
	{
		UnCaptureEvent(SeatVolumeOne);
		ReCaptureEvent(Controller);
		PlayTip("To enter your chair, face it and press the <action> key","",5);
		return true;
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == "tmrBeginClass") || (Name == "tmrSatDown"))
		{
			StopTimer("tmrBeginClass",0);
			StopTimer("tmrSatDown",0);
			ChangeState("LetsGetStarted");
			return true;
		}
		return GlobalTimer(Name);
	}
}
*/

/*
State LetsGetStarted
{
	Function BeginState()
	{
		InstructorOne.PlayAnim("podiumidle",1,3);
		PlayLSAnim("SFInstructor_Introduction",InstructorOne,1,512);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Introduction")
		{
			ChangeState("TimeToSit");
			return true;
		}
		return false;
	}
}
*/

/*
State TimeToSit
{
	Function BeginState()
	{
		ReCaptureEvent(SeatTriggerOne);
		StartTimer("tmrSitDown",1,false);
		StartTimer("TimeToSit_Start",0.01,false);
	}
	Function bool SeatTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		ChangeState("BeginLecture");
		return true;
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "TimeToSit_Start")
		{
			if (Cast<AStudentController>(Controller)->IsSeated())
			{
				ChangeState("BeginLecture");
			}
			return true;
		}
		if (Name == "tmrSitDown")
		{
			PlayLSAnim("SFInstructor_TakeYourSeat",InstructorOne,1,512);
			StartTimer("tmrSitDown2",5,false);
			return true;
		}
		if (Name == "tmrSitDown2")
		{
			PlayLSAnim("SFInstructor_TakeYourSeat",InstructorOne,1,512);
			StartTimer("tmrSitDown3",10,false);
			return true;
		}
		if (Name == "tmrSitDown3")
		{
			PlayLSAnim("SFInstructor_TakeYourSeat",InstructorOne,1,512);
			StartTimer("tmrSitDown4",5,false);
			return true;
		}
		if (Name == "tmrSitDown4")
		{
			ChangeState("Busted");
			return true;
		}
		return GlobalTimer(Name);
	}
}
*/

/*
State Lecture
{
	Function BeginState()
	{
		ReCaptureEvent(SeatTriggerOne);
		ReCaptureEvent(Controller);
		BeginSlide();
	}
	Function BeginSlide()
	{
	}
	Function bool SeatTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		StopTimer("tmrOutOfChair",0);
		ReCaptureEvent(Controller);
		return true;
	}
	Function bool StudentController_Custom(AStudentController* SC, AActor* Instigator, FString Parms)
	{
		Log("Parms " + Parms);
		if (Parms == "EXITCHAIR")
		{
			UnCaptureEvent(Controller);
			StartTimer("tmrOutOfChair",1,false);
			return true;
		}
		if (Parms == "CHEATING")
		{
			return true;
		}
		return false;
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "tmrOutOfChair")
		{
			ChangeState(RecallState(1));
			return true;
		}
		return GlobalTimer(Name);
	}
}
*/

/*
State BeginLecture extends Lecture
{
	Function BeginState()
	{
		StartTimer("tmrBeginLecture",1,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "tmrBeginLecture")
		{
			ChangeState("InstructorTalk1");
			return true;
		}
		return Super::Timer_Timer(Name);
	}
}
*/

/*
State InstructorTalk1 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("InstructorTalk1_Start",1,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "InstructorTalk1_Start")
		{
			InstructorOne.LoopAnim("podiumidle",1,2);
			PlayLSAnim("SFInstructor_TwentyEightWords",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_TwentyEightWords")
		{
			ChangeState("InstructorTalk2");
			return true;
		}
	}
}
*/

/*
State InstructorTalk2 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(1);
		StartTimer("InstructorTalk2_Start",2,false);
		StudentsTakeNotes();
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "InstructorTalk2_Start")
		{
			PlayLSAnim("SFInstructor_Line01",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Line01")
		{
			ChangeState("Instructor2Front1");
			return true;
		}
	}
}
*/

/*
State Instructor2Front1 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("Instructor2Front1_Start",6,false);
		StartTimer("Instructor2Front1_StartLine",3,false);
		InstructorOne.PlayAnim("podium2front",1,1);
		StudentsIdle();
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Instructor2Front1_Start")
		{
			InstructorOne.LoopAnim("frontidle",1,1);
			return true;
		}
		else
		{
			if (Name == "Instructor2Front1_StartLine")
			{
				PlayLSAnim("SFInstructor_Line01A",InstructorOne,1,512);
				return true;
			}
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Line01A")
		{
			ChangeState("Question1");
			return true;
		}
	}
}
*/

/*
State Question1 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("Question1_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Question1_Start")
		{
			PlayLSAnim("SFInstructor_Stoeti",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Stoeti")
		{
			StudentsRaiseHands(1);
			InstructorOne.PlayAnim("questionPwait",1,2);
			ChangeState("WaitForAnswer1");
			return true;
		}
	}
}
*/

/*
State WaitForAnswer1 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("WaitForAnswer1_Start",7,false);
		UpdateTestAnswers(5);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "WaitForAnswer1_Start")
		{
			UpdateTestAnswers(-1);
			InstructorOne.PlayAnim("questionPincorrect",1,2);
			PlayLSAnim("SFInstructor_InCorrect03",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Correct02")
		{
			ChangeState("Question2");
			return true;
		}
		if (Name == "SFInstructor_InCorrect03")
		{
			ChangeState("StudentAnswer1");
			return true;
		}
	}
	Function bool AGP_Hud_Custom(AAGP_HUD* NotifyActor, AActor* Instigator, FString Parms)
	{
		int32 Key = 0;
		ParseParms(Parms);
		if (ParmList[0] == "KeyPress")
		{
			Key=int(ParmList[1]);
			Log("AGP_Hud_Custom " + FString::FromInt(Key));
			UpdateTestAnswers(-1);
			if (Key == theCorrectAnswerIs)
			{
				InstructorOne.PlayAnim("questionPcorrect",1,2);
				PlayLSAnim("SFInstructor_Correct02",InstructorOne,1,512);
				CorrectCounter ++;
				bAnswer8=true;
				PlayerAnswered=true;
				StudentsLowerHands(1);
			}
			else
			{
				InstructorOne.PlayAnim("questionPincorrect",1,2);
				PlayLSAnim("SFInstructor_InCorrect03",InstructorOne,1,512);
				PlayerAnswered=false;
				StopTimer("WaitForAnswer1_Start",0);
			}
			return true;
		}
		return false;
	}
}
*/

/*
State StudentAnswer1 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("StudentAnswer1_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == "StudentAnswer1_Start") && (! PlayerAnswered))
		{
			StudentsLowerHands(1);
			PlayLSAnim("SFStudent01_Answer01",Student01,1,512);
			StudentAnswer(1);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFStudent01_Answer01")
		{
			StudentReturnsToIdle(1);
			ChangeState("TeacherAnswer1");
			return true;
		}
	}
}
*/

/*
State TeacherAnswer1 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("TeacherAnswer1_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == "TeacherAnswer1_Start") && (! PlayerAnswered))
		{
			InstructorOne.PlayAnim("questionPcorrect",1,2);
			PlayLSAnim("SFInstructor_Correct01",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Correct01")
		{
			ChangeState("Question2");
			return true;
		}
	}
}
*/

/*
State Question2 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("Question2_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Question2_Start")
		{
			PlayLSAnim("SFInstructor_Koperti",InstructorOne,1,512);
			InstructorOne.PlayAnim("questionPwait",1,2);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Koperti")
		{
			StudentsRaiseHands(4);
			InstructorOne.LoopAnim("frontidle",1,2);
			ChangeState("WaitForAnswer2");
			return true;
		}
	}
}
*/

/*
State WaitForAnswer2 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("WaitForAnswer2_Start",5,false);
		UpdateTestAnswers(0);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "WaitForAnswer2_Start")
		{
			UpdateTestAnswers(-1);
			InstructorOne.PlayAnim("questionPincorrect",1,2);
			PlayLSAnim("SFInstructor_InCorrect03",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Correct02")
		{
			ChangeState("Question3");
			return true;
		}
		if (Name == "SFInstructor_InCorrect03")
		{
			ChangeState("StudentAnswer2");
			return true;
		}
	}
	Function bool AGP_Hud_Custom(AAGP_HUD* NotifyActor, AActor* Instigator, FString Parms)
	{
		int32 Key = 0;
		ParseParms(Parms);
		if (ParmList[0] == "KeyPress")
		{
			Key=int(ParmList[1]);
			Log("AGP_Hud_Custom " + FString::FromInt(Key));
			UpdateTestAnswers(-1);
			if (Key == theCorrectAnswerIs)
			{
				InstructorOne.PlayAnim("questionPcorrect",1,2);
				PlayLSAnim("SFInstructor_Correct02",InstructorOne,1,512);
				CorrectCounter ++;
				bAnswer15=true;
				PlayerAnswered=true;
				StudentsLowerHands(4);
			}
			else
			{
				InstructorOne.PlayAnim("questionPincorrect",1,2);
				PlayLSAnim("SFInstructor_InCorrect03",InstructorOne,1,512);
				PlayerAnswered=false;
				StopTimer("WaitForAnswer2_Start",0);
			}
			return true;
		}
		return false;
	}
}
*/

/*
State StudentAnswer2 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StudentsLowerHands(4);
		PlayLSAnim("SFStudent01_Answer01",Student01,1,512);
		StudentAnswer(4);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFStudent01_Answer01")
		{
			StudentReturnsToIdle(4);
			ChangeState("TeacherAnswer2");
			return true;
		}
	}
}
*/

/*
State TeacherAnswer2 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("TeacherAnswer2_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == "TeacherAnswer2_Start") && (! PlayerAnswered))
		{
			InstructorOne.PlayAnim("questionPcorrect",1,2);
			PlayLSAnim("SFInstructor_Correct01",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Correct01")
		{
			ChangeState("Question3");
			return true;
		}
	}
}
*/

/*
State Question3 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("Question3_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Question3_Start")
		{
			PlayLSAnim("SFInstructor_ZashitenitiMiya",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_ZashitenitiMiya")
		{
			StudentsRaiseHands(2);
			InstructorOne.LoopAnim("frontidle",1,2);
			ChangeState("WaitForAnswer3");
			return true;
		}
	}
}
*/

/*
State WaitForAnswer3 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("WaitForAnswer3_Start",5,false);
		UpdateTestAnswers(6);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "WaitForAnswer3_Start")
		{
			UpdateTestAnswers(-1);
			InstructorOne.PlayAnim("questionPincorrect",1,2);
			PlayLSAnim("SFInstructor_InCorrect03",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Correct02")
		{
			ChangeState("Instructor2Podium1");
			return true;
		}
		if (Name == "SFInstructor_InCorrect03")
		{
			ChangeState("StudentAnswer3");
			return true;
		}
	}
	Function bool AGP_Hud_Custom(AAGP_HUD* NotifyActor, AActor* Instigator, FString Parms)
	{
		int32 Key = 0;
		ParseParms(Parms);
		if (ParmList[0] == "KeyPress")
		{
			Key=int(ParmList[1]);
			Log("AGP_Hud_Custom " + FString::FromInt(Key));
			UpdateTestAnswers(-1);
			if (Key == theCorrectAnswerIs)
			{
				InstructorOne.PlayAnim("questionPcorrect",1,2);
				PlayLSAnim("SFInstructor_Correct02",InstructorOne,1,512);
				CorrectCounter ++;
				PlayerAnswered=true;
				StudentsLowerHands(2);
			}
			else
			{
				InstructorOne.PlayAnim("questionPincorrect",1,2);
				PlayLSAnim("SFInstructor_InCorrect03",InstructorOne,1,512);
				PlayerAnswered=false;
				StopTimer("WaitForAnswer3_Start",0);
			}
			return true;
		}
		return false;
	}
}
*/

/*
State StudentAnswer3 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StudentsLowerHands(2);
		PlayLSAnim("SFStudent02_Answer01",Student02,1,512);
		StudentAnswer(2);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFStudent02_Answer01")
		{
			StudentReturnsToIdle(2);
			ChangeState("TeacherAnswer3");
			return true;
		}
	}
}
*/

/*
State TeacherAnswer3 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("TeacherAnswer3_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == "TeacherAnswer3_Start") && (! PlayerAnswered))
		{
			InstructorOne.PlayAnim("questionPcorrect",1,2);
			PlayLSAnim("SFInstructor_Correct04",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Correct04")
		{
			ChangeState("Instructor2Podium1");
			return true;
		}
	}
}
*/

/*
State Instructor2Podium1
{
	Function BeginState()
	{
		InstructorOne.PlayAnim("front2podium",1,1);
		StartTimer("Instructor2Podium1",6,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Instructor2Podium1")
		{
			InstructorOne.LoopAnim("podiumidle",1,1);
			ChangeState("InstructorTalk3");
			return true;
		}
		return Super::Timer_Timer(Name);
	}
}
*/

/*
State InstructorTalk3 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(2);
		StartTimer("InstructorTalk3_Start",2,false);
		StudentsTakeNotes();
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "InstructorTalk3_Start")
		{
			PlayLSAnim("SFInstructor_Line02",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Line02")
		{
			ChangeState("Instructor2Front2");
			return true;
		}
	}
}
*/

/*
State Instructor2Front2
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		InstructorOne.PlayAnim("podium2front",1,1);
		StartTimer("Instructor2Front2",6,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Instructor2Front2")
		{
			InstructorOne.LoopAnim("frontidle",1,1);
			ChangeState("Question4");
			return true;
		}
		return Super::Timer_Timer(Name);
	}
}
*/

/*
State Question4 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("Question4_Start",2,false);
		StudentsIdle();
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Question4_Start")
		{
			PlayLSAnim("SFInstructor_ProveriteniDvera",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_ProveriteniDvera")
		{
			StudentsRaiseHands(1);
			InstructorOne.LoopAnim("frontidle",1,2);
			ChangeState("WaitForAnswer4");
			return true;
		}
	}
}
*/

/*
State WaitForAnswer4 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("WaitForAnswer4_Start",5,false);
		UpdateTestAnswers(1);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "WaitForAnswer4_Start")
		{
			UpdateTestAnswers(-1);
			InstructorOne.PlayAnim("questionPincorrect",1,2);
			PlayLSAnim("SFInstructor_InCorrect03",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Correct05")
		{
			ChangeState("Question5");
			return true;
		}
		if (Name == "SFInstructor_InCorrect03")
		{
			ChangeState("StudentAnswer4");
			return true;
		}
	}
	Function bool AGP_Hud_Custom(AAGP_HUD* NotifyActor, AActor* Instigator, FString Parms)
	{
		int32 Key = 0;
		ParseParms(Parms);
		if (ParmList[0] == "KeyPress")
		{
			Key=int(ParmList[1]);
			Log("AGP_Hud_Custom " + FString::FromInt(Key));
			UpdateTestAnswers(-1);
			if (Key == theCorrectAnswerIs)
			{
				InstructorOne.PlayAnim("questionPcorrect",1,2);
				PlayLSAnim("SFInstructor_Correct05",InstructorOne,1,512);
				CorrectCounter ++;
				bAnswer13=true;
				PlayerAnswered=true;
				StudentsLowerHands(1);
			}
			else
			{
				InstructorOne.PlayAnim("questionPincorrect",1,2);
				PlayLSAnim("SFInstructor_InCorrect03",InstructorOne,1,512);
				PlayerAnswered=false;
				StopTimer("WaitForAnswer4_Start",0);
			}
			return true;
		}
		return false;
	}
}
*/

/*
State StudentAnswer4 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("StudentAnswer4_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == "StudentAnswer4_Start") && (! PlayerAnswered))
		{
			StudentsLowerHands(1);
			PlayLSAnim("SFStudent01_Answer01",Student01,1,512);
			StudentAnswer(1);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFStudent01_Answer01")
		{
			StudentReturnsToIdle(1);
			ChangeState("TeacherAnswer4");
			return true;
		}
	}
}
*/

/*
State TeacherAnswer4 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("TeacherAnswer4_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == "TeacherAnswer4_Start") && (! PlayerAnswered))
		{
			InstructorOne.PlayAnim("questionPcorrect",1,2);
			PlayLSAnim("SFInstructor_Correct01",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Correct01")
		{
			ChangeState("Question5");
			return true;
		}
	}
}
*/

/*
State Question5 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("Question5_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Question5_Start")
		{
			InstructorOne.LoopAnim("frontidle",1,2);
			PlayLSAnim("SFInstructor_BrositeGranata",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_BrositeGranata")
		{
			StudentsRaiseHands(3);
			InstructorOne.LoopAnim("frontidle",1,2);
			ChangeState("WaitForAnswer5");
			return true;
		}
	}
}
*/

/*
State WaitForAnswer5 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("WaitForAnswer5_Start",5,false);
		UpdateTestAnswers(7);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "WaitForAnswer5_Start")
		{
			UpdateTestAnswers(-1);
			InstructorOne.PlayAnim("questionPincorrect",1,2);
			PlayLSAnim("SFInstructor_InCorrect03",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Correct07")
		{
			StudentsLowerHands(3);
			ChangeState("Question6");
			return true;
		}
		if (Name == "SFInstructor_InCorrect03")
		{
			ChangeState("StudentAnswer5");
			return true;
		}
	}
	Function bool AGP_Hud_Custom(AAGP_HUD* NotifyActor, AActor* Instigator, FString Parms)
	{
		int32 Key = 0;
		ParseParms(Parms);
		if (ParmList[0] == "KeyPress")
		{
			Key=int(ParmList[1]);
			Log("AGP_Hud_Custom " + FString::FromInt(Key));
			UpdateTestAnswers(-1);
			if (Key == theCorrectAnswerIs)
			{
				InstructorOne.PlayAnim("questionPcorrect",1,2);
				PlayLSAnim("SFInstructor_Correct07",InstructorOne,1,512);
				CorrectCounter ++;
				bAnswer10=true;
				PlayerAnswered=true;
				StudentsLowerHands(2);
			}
			else
			{
				InstructorOne.PlayAnim("questionPincorrect",1,2);
				PlayLSAnim("SFInstructor_InCorrect03",InstructorOne,1,512);
				PlayerAnswered=false;
				StopTimer("WaitForAnswer5_Start",0);
			}
			return true;
		}
		return false;
	}
}
*/

/*
State StudentAnswer5 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("StudentAnswer5_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == "StudentAnswer5_Start") && (! PlayerAnswered))
		{
			StudentsLowerHands(3);
			PlayLSAnim("SFStudent03_Answer01",Student03,1,512);
			StudentAnswer(3);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFStudent03_Answer01")
		{
			StudentReturnsToIdle(3);
			ChangeState("TeacherAnswer5");
			return true;
		}
	}
}
*/

/*
State TeacherAnswer5 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("TeacherAnswer5_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == "TeacherAnswer5_Start") && (! PlayerAnswered))
		{
			InstructorOne.PlayAnim("questionPcorrect",1,2);
			PlayLSAnim("SFInstructor_Correct07",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Correct07")
		{
			ChangeState("Question6");
			return true;
		}
	}
}
*/

/*
State Question6 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("Question6_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Question6_Start")
		{
			PlayLSAnim("SFInstructor_OkranitenitiRaiono",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_OkranitenitiRaiono")
		{
			StudentsRaiseHands(6);
			InstructorOne.LoopAnim("frontidle",1,2);
			ChangeState("WaitForAnswer6");
			return true;
		}
	}
}
*/

/*
State WaitForAnswer6 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("WaitForAnswer6_Start",5,false);
		UpdateTestAnswers(2);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "WaitForAnswer6_Start")
		{
			UpdateTestAnswers(-1);
			InstructorOne.PlayAnim("questionPincorrect",1,2);
			PlayLSAnim("SFInstructor_InCorrect03",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Correct08")
		{
			ChangeState("Instructor2Podium2");
			return true;
		}
		if (Name == "SFInstructor_InCorrect03")
		{
			ChangeState("StudentAnswer6");
			return true;
		}
	}
	Function bool AGP_Hud_Custom(AAGP_HUD* NotifyActor, AActor* Instigator, FString Parms)
	{
		int32 Key = 0;
		ParseParms(Parms);
		if (ParmList[0] == "KeyPress")
		{
			Key=int(ParmList[1]);
			Log("AGP_Hud_Custom " + FString::FromInt(Key));
			UpdateTestAnswers(-1);
			if (Key == theCorrectAnswerIs)
			{
				InstructorOne.PlayAnim("questionPcorrect",1,2);
				PlayLSAnim("SFInstructor_Correct08",InstructorOne,1,512);
				CorrectCounter ++;
				bAnswer14=true;
				PlayerAnswered=true;
				StudentsLowerHands(6);
			}
			else
			{
				InstructorOne.PlayAnim("questionPincorrect",1,2);
				PlayLSAnim("SFInstructor_InCorrect03",InstructorOne,1,512);
				PlayerAnswered=false;
				StopTimer("WaitForAnswer6_Start",0);
			}
			return true;
		}
		return false;
	}
}
*/

/*
State StudentAnswer6 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("StudentAnswer6_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == "StudentAnswer6_Start") && (! PlayerAnswered))
		{
			StudentsLowerHands(6);
			PlayLSAnim("SFStudent01_Answer01",Student01,1,512);
			StudentAnswer(6);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFStudent01_Answer01")
		{
			StudentReturnsToIdle(6);
			ChangeState("TeacherAnswer6");
			return true;
		}
	}
}
*/

/*
State TeacherAnswer6 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("TeacherAnswer6_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == "TeacherAnswer6_Start") && (! PlayerAnswered))
		{
			InstructorOne.PlayAnim("questionPcorrect",1,2);
			PlayLSAnim("SFInstructor_Correct08",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Correct08")
		{
			ChangeState("Instructor2Podium2");
			return true;
		}
	}
}
*/

/*
State Instructor2Podium2
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		InstructorOne.PlayAnim("front2podium",1,1);
		StartTimer("Instructor2Podium2",6,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Instructor2Podium2")
		{
			InstructorOne.LoopAnim("podiumidle",1,1);
			ChangeState("InstructorTalk4");
			return true;
		}
		return Super::Timer_Timer(Name);
	}
}
*/

/*
State InstructorTalk4 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("InstructorTalk4_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "InstructorTalk4_Start")
		{
			PlayLSAnim("SFInstructor_MoveOn",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_MoveOn")
		{
			ChangeState("InstructorTalk5");
			return true;
		}
	}
}
*/

/*
State InstructorTalk5 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(3);
		StartTimer("InstructorTalk5_Start",2,false);
		StudentsTakeNotes();
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "InstructorTalk5_Start")
		{
			PlayLSAnim("SFInstructor_Line03",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Line03")
		{
			ChangeState("Instructor2Front3");
			return true;
		}
	}
}
*/

/*
State Instructor2Front3
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		InstructorOne.PlayAnim("podium2front",1,1);
		StartTimer("Instructor2Front3",6,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Instructor2Front3")
		{
			InstructorOne.LoopAnim("frontidle",1,1);
			ChangeState("Question7");
			return true;
		}
		return Super::Timer_Timer(Name);
	}
}
*/

/*
State Question7 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("Question7_Start",2,false);
		StudentsIdle();
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Question7_Start")
		{
			InstructorOne.LoopAnim("frontidle",1,2);
			PlayLSAnim("SFInstructor_Fierk",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Fierk")
		{
			StudentsRaiseHands(4);
			InstructorOne.LoopAnim("frontidle",1,2);
			ChangeState("WaitForAnswer7");
			return true;
		}
	}
}
*/

/*
State WaitForAnswer7 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("WaitForAnswer7_Start",5,false);
		UpdateTestAnswers(8);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "WaitForAnswer7_Start")
		{
			UpdateTestAnswers(-1);
			InstructorOne.PlayAnim("questionPincorrect",1,2);
			PlayLSAnim("SFInstructor_InCorrect03",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Correct08")
		{
			StudentsLowerHands(4);
			ChangeState("Question8");
			return true;
		}
		if (Name == "SFInstructor_InCorrect03")
		{
			ChangeState("StudentAnswer7");
			return true;
		}
	}
	Function bool AGP_Hud_Custom(AAGP_HUD* NotifyActor, AActor* Instigator, FString Parms)
	{
		int32 Key = 0;
		ParseParms(Parms);
		if (ParmList[0] == "KeyPress")
		{
			Key=int(ParmList[1]);
			Log("AGP_Hud_Custom " + FString::FromInt(Key));
			UpdateTestAnswers(-1);
			if (Key == theCorrectAnswerIs)
			{
				InstructorOne.PlayAnim("questionPcorrect",1,2);
				PlayLSAnim("SFInstructor_Correct08",InstructorOne,1,512);
				CorrectCounter ++;
				bAnswer7=true;
				PlayerAnswered=true;
				StudentsLowerHands(4);
			}
			else
			{
				InstructorOne.PlayAnim("questionPincorrect",1,2);
				PlayLSAnim("SFInstructor_InCorrect03",InstructorOne,1,512);
				PlayerAnswered=false;
				StopTimer("WaitForAnswer7_Start",0);
			}
			return true;
		}
		return false;
	}
}
*/

/*
State StudentAnswer7 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("StudentAnswer7_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == "StudentAnswer7_Start") && (! PlayerAnswered))
		{
			StudentsLowerHands(4);
			PlayLSAnim("SFStudent04_Answer01",Student04,1,512);
			StudentAnswer(4);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFStudent04_Answer01")
		{
			StudentReturnsToIdle(4);
			InstructorOne.PlayAnim("questionRcorrect",1,2);
			ChangeState("TeacherAnswer7");
			return true;
		}
	}
}
*/

/*
State TeacherAnswer7 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("TeacherAnswer7_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == "TeacherAnswer7_Start") && (! PlayerAnswered))
		{
			PlayLSAnim("SFInstructor_Correct10",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Correct10")
		{
			ChangeState("Question8");
			return true;
		}
	}
}
*/

/*
State Question8 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("Question8_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Question8_Start")
		{
			PlayLSAnim("SFInstructor_Plof",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Plof")
		{
			StudentsRaiseHands(3);
			ChangeState("WaitForAnswer8");
			return true;
		}
	}
}
*/

/*
State WaitForAnswer8 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("WaitForAnswer8_Start",5,false);
		UpdateTestAnswers(3);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "WaitForAnswer8_Start")
		{
			UpdateTestAnswers(-1);
			InstructorOne.PlayAnim("questionPincorrect",1,2);
			PlayLSAnim("SFInstructor_InCorrect03",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Correct11")
		{
			ChangeState("Question9");
			return true;
		}
		if (Name == "SFInstructor_InCorrect03")
		{
			ChangeState("StudentAnswer8");
			return true;
		}
	}
	Function bool AGP_Hud_Custom(AAGP_HUD* NotifyActor, AActor* Instigator, FString Parms)
	{
		int32 Key = 0;
		ParseParms(Parms);
		if (ParmList[0] == "KeyPress")
		{
			Key=int(ParmList[1]);
			Log("AGP_Hud_Custom " + FString::FromInt(Key));
			UpdateTestAnswers(-1);
			if (Key == theCorrectAnswerIs)
			{
				InstructorOne.PlayAnim("questionPcorrect",1,2);
				PlayLSAnim("SFInstructor_Correct11",InstructorOne,1,512);
				CorrectCounter ++;
				bAnswer11=true;
				PlayerAnswered=true;
				StudentsLowerHands(3);
			}
			else
			{
				InstructorOne.PlayAnim("questionPincorrect",1,2);
				PlayLSAnim("SFInstructor_InCorrect03",InstructorOne,1,512);
				PlayerAnswered=false;
				StopTimer("WaitForAnswer8_Start",0);
			}
			return true;
		}
		return false;
	}
}
*/

/*
State StudentAnswer8 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("StudentAnswer8_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == "StudentAnswer8_Start") && (! PlayerAnswered))
		{
			StudentsLowerHands(3);
			PlayLSAnim("SFStudent01_Answer01",Student01,1,512);
			StudentAnswer(3);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFStudent01_Answer01")
		{
			StudentReturnsToIdle(3);
			ChangeState("TeacherAnswer8");
			return true;
		}
	}
}
*/

/*
State TeacherAnswer8 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("TeacherAnswer8_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == "TeacherAnswer8_Start") && (! PlayerAnswered))
		{
			InstructorOne.PlayAnim("questionPcorrect",1,2);
			PlayLSAnim("SFInstructor_Correct01",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Correct01")
		{
			ChangeState("Question9");
			return true;
		}
	}
}
*/

/*
State Question9 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("Question9_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Question9_Start")
		{
			InstructorOne.LoopAnim("frontidle",1,2);
			PlayLSAnim("SFInstructor_Sabat",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Sabat")
		{
			StudentsRaiseHands(5);
			ChangeState("WaitForAnswer9");
			return true;
		}
	}
}
*/

/*
State WaitForAnswer9 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("WaitForAnswer9_Start",5,false);
		UpdateTestAnswers(9);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "WaitForAnswer9_Start")
		{
			UpdateTestAnswers(-1);
			InstructorOne.PlayAnim("questionPincorrect",1,2);
			PlayLSAnim("SFInstructor_InCorrect03",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Correct08")
		{
			StudentsLowerHands(5);
			ChangeState("Instructor2Podium3");
			return true;
		}
		if (Name == "SFInstructor_InCorrect03")
		{
			ChangeState("StudentAnswer9");
			return true;
		}
	}
	Function bool AGP_Hud_Custom(AAGP_HUD* NotifyActor, AActor* Instigator, FString Parms)
	{
		int32 Key = 0;
		ParseParms(Parms);
		if (ParmList[0] == "KeyPress")
		{
			Key=int(ParmList[1]);
			Log("AGP_Hud_Custom " + FString::FromInt(Key));
			UpdateTestAnswers(-1);
			if (Key == theCorrectAnswerIs)
			{
				InstructorOne.PlayAnim("questionPcorrect",1,2);
				PlayLSAnim("SFInstructor_Correct08",InstructorOne,1,512);
				CorrectCounter ++;
				PlayerAnswered=true;
				StudentsLowerHands(5);
			}
			else
			{
				InstructorOne.PlayAnim("questionPincorrect",1,2);
				PlayLSAnim("SFInstructor_InCorrect03",InstructorOne,1,512);
				PlayerAnswered=false;
				StopTimer("WaitForAnswer9_Start",0);
			}
			return true;
		}
		return false;
	}
}
*/

/*
State StudentAnswer9 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("StudentAnswer9_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == "StudentAnswer9_Start") && (! PlayerAnswered))
		{
			StudentsLowerHands(5);
			PlayLSAnim("SFStudent05_Answer01",Student05,1,512);
			StudentAnswer(5);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFStudent05_Answer01")
		{
			StudentReturnsToIdle(5);
			InstructorOne.PlayAnim("questionLcorrect",1,2);
			ChangeState("TeacherAnswer9");
			return true;
		}
	}
}
*/

/*
State TeacherAnswer9 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("TeacherAnswer9_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == "TeacherAnswer9_Start") && (! PlayerAnswered))
		{
			PlayLSAnim("SFInstructor_Correct08",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Correct08")
		{
			ChangeState("Instructor2Podium3");
			return true;
		}
	}
}
*/

/*
State Instructor2Podium3
{
	Function BeginState()
	{
		InstructorOne.PlayAnim("front2podium",1,1);
		StartTimer("Instructor2Podium3",6,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Instructor2Podium3")
		{
			InstructorOne.LoopAnim("podiumidle",1,1);
			ChangeState("InstructorTalk6");
			return true;
		}
		return Super::Timer_Timer(Name);
	}
Begin:
	Sleep(5);
}
*/

/*
State InstructorTalk6 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(4);
		StartTimer("InstructorTalk6_Start",2,false);
		StudentsTakeNotes();
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "InstructorTalk6_Start")
		{
			PlayLSAnim("SFInstructor_Line04",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Line04")
		{
			ChangeState("Instructor2Front4");
			return true;
		}
	}
}
*/

/*
State Instructor2Front4
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		InstructorOne.PlayAnim("podium2front",1,1);
		StartTimer("Instructor2Front4",6,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Instructor2Front4")
		{
			InstructorOne.LoopAnim("frontidle",1,1);
			ChangeState("Question10");
			return true;
		}
		return Super::Timer_Timer(Name);
	}
}
*/

/*
State Question10 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("Question10_Start",2,false);
		StudentsIdle();
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Question10_Start")
		{
			PlayLSAnim("SFInstructor_ProveriteniStoroni",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_ProveriteniStoroni")
		{
			StudentsRaiseHands(6);
			InstructorOne.LoopAnim("questionPwait",1,2);
			ChangeState("WaitForAnswer10");
			return true;
		}
	}
}
*/

/*
State WaitForAnswer10 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("WaitForAnswer10_Start",20,false);
		UpdateTestAnswers(10);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "WaitForAnswer10_Start")
		{
			UpdateTestAnswers(-1);
			InstructorOne.PlayAnim("questionLcorrect",1,2);
			PlayLSAnim("SFInstructor_InCorrect03",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Correct02")
		{
			StudentsLowerHands(6);
			ChangeState("Question11");
			return true;
		}
		if (Name == "SFInstructor_InCorrect03")
		{
			ChangeState("StudentAnswer10");
			return true;
		}
	}
	Function bool AGP_Hud_Custom(AAGP_HUD* NotifyActor, AActor* Instigator, FString Parms)
	{
		int32 Key = 0;
		ParseParms(Parms);
		if (ParmList[0] == "KeyPress")
		{
			Key=int(ParmList[1]);
			Log("AGP_Hud_Custom " + FString::FromInt(Key));
			UpdateTestAnswers(-1);
			if (Key == theCorrectAnswerIs)
			{
				InstructorOne.PlayAnim("questionPcorrect",1,2);
				PlayLSAnim("SFInstructor_Correct02",InstructorOne,1,512);
				CorrectCounter ++;
				PlayerAnswered=true;
				StudentsLowerHands(6);
			}
			else
			{
				InstructorOne.PlayAnim("questionPincorrect",1,2);
				PlayLSAnim("SFInstructor_InCorrect03",InstructorOne,1,512);
				PlayerAnswered=false;
				StopTimer("WaitForAnswer10_Start",0);
			}
			return true;
		}
		return false;
	}
}
*/

/*
State StudentAnswer10 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("StudentAnswer10_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == "StudentAnswer10_Start") && (! PlayerAnswered))
		{
			StudentsLowerHands(6);
			PlayLSAnim("SFStudent06_Answer01",Student06,1,512);
			StudentAnswer(6);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if ((Name == "SFStudent06_Answer01") && (! PlayerAnswered))
		{
			StudentReturnsToIdle(6);
			InstructorOne.PlayAnim("questionLcorrect",1,2);
			ChangeState("TeacherAnswer10");
			return true;
		}
	}
}
*/

/*
State TeacherAnswer10 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("TeacherAnswer10_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == "TeacherAnswer10_Start") && (! PlayerAnswered))
		{
			PlayLSAnim("SFInstructor_Correct15",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Correct15")
		{
			ChangeState("Question11");
			return true;
		}
	}
}
*/

/*
State Question11 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("Question11_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Question11_Start")
		{
			InstructorOne.LoopAnim("frontidle",1,2);
			PlayLSAnim("SFInstructor_VragPyatnaten",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_VragPyatnaten")
		{
			StudentsRaiseHands(1);
			ChangeState("WaitForAnswer11");
			return true;
		}
	}
}
*/

/*
State WaitForAnswer11 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("WaitForAnswer11_Start",20,false);
		UpdateTestAnswers(4);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "WaitForAnswer11_Start")
		{
			UpdateTestAnswers(-1);
			InstructorOne.PlayAnim("questionPincorrect",1,2);
			PlayLSAnim("SFInstructor_InCorrect03",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Correct15")
		{
			ChangeState("Question12");
			return true;
		}
		if (Name == "SFInstructor_InCorrect03")
		{
			ChangeState("StudentAnswer11");
			return true;
		}
	}
	Function bool AGP_Hud_Custom(AAGP_HUD* NotifyActor, AActor* Instigator, FString Parms)
	{
		int32 Key = 0;
		ParseParms(Parms);
		if (ParmList[0] == "KeyPress")
		{
			Key=int(ParmList[1]);
			Log("AGP_Hud_Custom " + FString::FromInt(Key));
			UpdateTestAnswers(-1);
			if (Key == theCorrectAnswerIs)
			{
				InstructorOne.PlayAnim("questionPcorrect",1,2);
				PlayLSAnim("SFInstructor_Correct15",InstructorOne,1,512);
				CorrectCounter ++;
				bAnswer12=true;
				PlayerAnswered=true;
				StudentsLowerHands(1);
			}
			else
			{
				InstructorOne.PlayAnim("questionPincorrect",1,2);
				PlayLSAnim("SFInstructor_InCorrect03",InstructorOne,1,512);
				PlayerAnswered=false;
				StopTimer("WaitForAnswer11_Start",0);
			}
			return true;
		}
		return false;
	}
}
*/

/*
State StudentAnswer11 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("StudentAnswer11_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == "StudentAnswer11_Start") && (! PlayerAnswered))
		{
			StudentsLowerHands(1);
			PlayLSAnim("SFStudent01_Answer01",Student01,1,512);
			StudentAnswer(1);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFStudent01_Answer01")
		{
			StudentReturnsToIdle(1);
			ChangeState("TeacherAnswer11");
			return true;
		}
	}
}
*/

/*
State TeacherAnswer11 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("TeacherAnswer11_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == "TeacherAnswer11_Start") && (! PlayerAnswered))
		{
			InstructorOne.PlayAnim("questionPcorrect",1,2);
			PlayLSAnim("SFInstructor_Correct01",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Correct01")
		{
			ChangeState("Question12");
			return true;
		}
	}
}
*/

/*
State Question12 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("Question12_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Question12_Start")
		{
			InstructorOne.LoopAnim("frontidle",1,2);
			PlayLSAnim("SFInstructor_RaionoOkranit",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_RaionoOkranit")
		{
			StudentsRaiseHands(7);
			ChangeState("WaitForAnswer12");
			return true;
		}
	}
}
*/

/*
State WaitForAnswer12 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("WaitForAnswer12_Start",20,false);
		UpdateTestAnswers(11);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "WaitForAnswer12_Start")
		{
			UpdateTestAnswers(-1);
			InstructorOne.PlayAnim("questionPincorrect",1,2);
			PlayLSAnim("SFInstructor_InCorrect03",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Correct02")
		{
			StudentsLowerHands(7);
			ChangeState("InstructorTalk7");
			return true;
		}
		if (Name == "SFInstructor_InCorrect03")
		{
			ChangeState("StudentAnswer12");
			return true;
		}
	}
	Function bool AGP_Hud_Custom(AAGP_HUD* NotifyActor, AActor* Instigator, FString Parms)
	{
		int32 Key = 0;
		ParseParms(Parms);
		if (ParmList[0] == "KeyPress")
		{
			Key=int(ParmList[1]);
			Log("AGP_Hud_Custom " + FString::FromInt(Key));
			UpdateTestAnswers(-1);
			if (Key == theCorrectAnswerIs)
			{
				InstructorOne.PlayAnim("questionPcorrect",1,2);
				PlayLSAnim("SFInstructor_Correct02",InstructorOne,1,512);
				CorrectCounter ++;
				bAnswer9=true;
				PlayerAnswered=true;
				StudentsLowerHands(7);
			}
			else
			{
				InstructorOne.PlayAnim("questionPincorrect",1,2);
				PlayLSAnim("SFInstructor_InCorrect03",InstructorOne,1,512);
				PlayerAnswered=false;
				StopTimer("WaitForAnswer12_Start",0);
			}
			return true;
		}
		return false;
	}
}
*/

/*
State StudentAnswer12 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("StudentAnswer12_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == "StudentAnswer12_Start") && (! PlayerAnswered))
		{
			StudentsLowerHands(7);
			PlayLSAnim("SFStudent07_Answer01",Student07,1,512);
			StudentAnswer(7);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFStudent07_Answer01")
		{
			StudentReturnsToIdle(7);
			ChangeState("TeacherAnswer12");
			return true;
		}
	}
}
*/

/*
State TeacherAnswer12 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("TeacherAnswer12_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if ((Name == "TeacherAnswer12_Start") && (! PlayerAnswered))
		{
			InstructorOne.PlayAnim("questionPcorrect",1,2);
			PlayLSAnim("SFInstructor_Correct17",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Correct17")
		{
			ChangeState("InstructorTalk7");
			return true;
		}
	}
}
*/

/*
State InstructorTalk7 extends Lecture
{
	Function BeginState()
	{
		RememberState(GetCurrentState(),0);
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer("InstructorTalk7_Start",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "InstructorTalk7_Start")
		{
			InstructorOne.LoopAnim("frontidle",1,2);
			PlayLSAnim("SFInstructor_Line05",InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Line05")
		{
			InstructorOne.PlayAnim("front2podium",1,1);
			LectureDone=true;
			PlayerLock(false,false);
			ChangeState("FindAudioLab");
			return true;
		}
	}
}
*/

/*
State FindAudioLab
{
	Function BeginState()
	{
		Cast<AStudentController>(Controller)->bForceSit=false;
		FadeOut(2,true);
		StartTimer("LectureDoneTimer1",5);
	}
	Function bool Timer_Timer(FName Name)
	{
		AGP_Characters.NPC_MedStudent* MS = nullptr;
		if (Name == "LectureDoneTimer1")
		{
			InstructorOne.LoopAnim("DrillIdle",1,0.2);
			ForEach AllActors(ANPC_MedStudent::StaticClass(),MS)
			{
				switch(MS.Tag)
				{
					case "NPC_LanguageStudent01_01":
					case "NPC_LanguageStudent01_02":
					case "NPC_LanguageStudent01_03":
					case "NPC_LanguageStudent01_04":
					case "NPC_LanguageStudent01_05":
					case "NPC_LanguageStudent01_06":
					case "NPC_LanguageStudent01_07":
					MS.bHidden=true;
					default:
				}
				FadeIn(1,true);
				StartTimer("LectureDoneTimer2",3);
				return true;
			}
			if (Name == "LectureDoneTimer2")
			{
				PlayTip("Head over to the audio Lab","testing will begin soon",5);
				return true;
			}
			return Super::Timer_Timer(Name);
		}
	}
}
*/

/*
State BeginTest
{
	Function BeginState()
	{
		ReCaptureEvent(SeatVolumeTwo);
		StartTimer("BeginTestTimer",1,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "BeginTestTimer")
		{
			PlayTip("To mark answers, use your <fire> or","<action> buttons",5);
			ChangeState("Testing");
			return true;
		}
		return GlobalTimer(Name);
	}
}
*/

/*
State Testing
{
	Function BeginState()
	{
		iCurrentQuestion=1;
		Level.bEnableCommo=true;
		SayTestQuestion(true);
		if (bTestingHack == false)
		{
			SFLanguageExamOne.SetActive(true);
			bTestingHack=true;
			ChangeState("AudioTestCommo");
		}
	}
	Function bool AGP_Hud_Custom(AAGP_HUD* NotifyActor, AActor* Instigator, FString Parms)
	{
		int32 Key = 0;
		ParseParms(Parms);
		if (fRepeatQuestionTime > GetWorld()->GetTimeSeconds())
		{
			return false;
		}
		if (bFinishTest == true)
		{
			Level.bEnableCommo=false;
			return false;
		}
		if (ParmList[0] == "KeyPress")
		{
			Key=int(ParmList[1]);
			Log("AGP_Hud_Custom " + FString::FromInt(Key));
			fRepeatQuestionTime=(GetWorld()->GetTimeSeconds() + 1.5);
			Level.bEnableCommo=true;
			if ((Key >= 48) && (Key <= 57))
			{
				if (Key == 48)
				{
					bFinishTest=true;
					Cast<AStudentController>(Controller)->bForceSit=false;
					Level.bEnableCommo=false;
					PlayTip("To have your test graded, approach","the instructor and press <action>",5);
					SFLanguageExamOne.bHidden=true;
				}
				else
				{
					if (Key == 55)
					{
						iCurrentQuestion --;
						if (iCurrentQuestion < 1)
						{
							iCurrentQuestion=1;
						}
						SayTestQuestion(false);
					}
					else
					{
						if (Key == 56)
						{
							iCurrentQuestion ++;
							if (iCurrentQuestion > 15)
							{
								iCurrentQuestion=15;
							}
							SayTestQuestion(false);
						}
						else
						{
							if (Key == 57)
							{
								SayTestQuestion(false);
							}
						}
					}
				}
				return true;
			}
		}
		return false;
	}
	Function bool Timer_Timer(FName Name)
	{
		return GlobalTimer(Name);
	}
	Function bool SeatVolumeTwo_Trigger(AGP_Gameplay.AGP_Trigger* Trigger, AActor* Instigator)
	{
		PlayTip("When you are through with your test, approach","the instructor and press <action>",5);
		return true;
	}
	Function bool SeatVolumeTwo_UnTrigger(AGP_Gameplay.AGP_Trigger* Trigger, AActor* Instigator)
	{
		PlayTip("When you are through with your test, approach","the instructor and press <action>",5);
		return true;
	}
	Function bool InstructorTriggerTwo_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		Grade=int((SFLanguageExamOne.ScoreTest() * float(100)));
		if (Grade >= 80)
		{
			ChangeState("Eighty1Hundred");
			return true;
		}
		if (Grade >= 70)
		{
			ChangeState("SeventySeventyNine");
			return true;
		}
		if (Grade >= 60)
		{
			ChangeState("SixtySixtyNine");
			return true;
		}
		else
		{
			ChangeState("ZeroFiftyNine");
			return true;
		}
	}
}
*/

/*
State AudioTestCommo extends Testing
{
Begin:
	Sleep(1);
	bNextQuestion=false;
	SayTestQuestion(false);
	Sleep(0.1);
	if (Cast<AStudentController>(Controller)->IsSeated() == false)
	{
		bFinishTest=true;
	}
	if (bFinishTest)
	{
		JL"End"
;
	}
	else
	{
		if (bNextQuestion)
		{
			JL"Begin"
;
		}
		else
		{
			if (iOldTestPage != SFLanguageExamOne.CurrentPage)
			{
				if (iOldTestPage > SFLanguageExamOne.CurrentPage)
				{
					iCurrentQuestion=(SFLanguageExamOne.CurrentPage * 3);
				}
				else
				{
					iCurrentQuestion=((SFLanguageExamOne.CurrentPage * 3) - 2);
				}
				iOldTestPage=SFLanguageExamOne.CurrentPage;
				SayTestQuestion(true);
			}
			JL"Loop"
;
		}
	}
	Level.bEnableCommo=false;
	Log("AudioTestCommo is DONE!");
}
*/

/*
State Eighty1Hundred
{
	Function BeginState()
	{
		PlayLSAnim("SFInstructor02_Outstanding",InstructorOne,1,512);
		if (Cast<AStudentController>(Controller)->IsCheating())
		{
			PlayTip("Cheats Detected. Good job soldier,","you scored " + FString::FromInt(Grade) + "%",5);
		}
		else
		{
			PlayTip("Good job soldier,","you scored " + FString::FromInt(Grade) + "%",5);
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor02_Outstanding")
		{
			ChangeState("TestPassed");
			return true;
		}
	}
}
*/

/*
State SeventySeventyNine
{
	Function BeginState()
	{
		PlayLSAnim("SFInstructor02_Good",InstructorOne,1,512);
		if (Cast<AStudentController>(Controller)->IsCheating())
		{
			PlayTip("Cheats Detected. You passed with","" + FString::FromInt(Grade) + "%",5);
		}
		else
		{
			PlayTip("You passed with","" + FString::FromInt(Grade) + "%",5);
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor02_Good")
		{
			ChangeState("TestPassed");
			return true;
		}
	}
}
*/

/*
State SixtySixtyNine
{
	Function BeginState()
	{
		PlayLSAnim("SFInstructor02_Terrible",InstructorOne,1,512);
		if (Cast<AStudentController>(Controller)->IsCheating())
		{
			PlayTip("Cheats Detected. You Failed!","You scored" + FString::FromInt(Grade) + "%",5);
		}
		else
		{
			PlayTip("You Failed!","You scored" + FString::FromInt(Grade) + "%",5);
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor02_Terrible")
		{
			ChangeState("TestFailed");
			return true;
		}
	}
}
*/

/*
State ZeroFiftyNine
{
	Function BeginState()
	{
		PlayLSAnim("SFInstructor02_Failure",InstructorOne,1,512);
		if (Cast<AStudentController>(Controller)->IsCheating())
		{
			PlayTip("Cheats Detected. Pathetic soldier!","You scored " + FString::FromInt(Grade) + "%",5);
		}
		else
		{
			PlayTip("Pathetic soldier!","You scored " + FString::FromInt(Grade) + "%",5);
		}
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor02_Failure")
		{
			ChangeState("TestFailed");
			return true;
		}
	}
}
*/

/*
State TestPassed
{
	Function bool InstructorTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
	}
	Function BeginState()
	{
		StartTimer("BeginPassed",0.01);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "BeginPassed")
		{
			if (Cast<AStudentController>(Controller)->IsCheating())
			{
				DisplayMissionFailure("T_AA2_UI.tour_icons.hud_menu_touricon_sf","Sorry soldier.","Cheats detected, cannot complete.",128,128,7,"None");
			}
			else
			{
				DisplayMissionSuccess("T_AA2_UI.tour_icons.hud_menu_touricon_sf","Congratulations! You qualify for ","Special Forces.",128,128,7,"None");
			}
			return true;
		}
		return false;
	}
}
*/

/*
State TestFailed
{
	Function BeginState()
	{
		StartTimer("BeginFailed",2,false);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "BeginFailed")
		{
			PlayTip("Test Failed!"," Level will restart.",10);
			StartTimer("RestartTest",10);
			return true;
		}
		else
		{
			if (Name == "RestartTest")
			{
				FadeOut(2,true);
				StartTimer("RestartTestTimer",2);
				return true;
			}
			else
			{
				if (Name == "RestartTestTimer")
				{
					Controller.ConsoleCommand("reconnect");
					return true;
				}
			}
		}
		return GlobalTimer(Name);
	}
}
*/

/*
State Trouble
{
	Function BeginState()
	{
		BeginTrouble();
	}
	Function EndState()
	{
		EndTrouble();
	}
	Function BeginTrouble()
	{
	}
	Function EndTrouble()
	{
	}
	Function bool SeatTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		ChangeState(RecallState(0));
		return true;
	}
}
*/

/*
State OutOfChair1 extends Trouble
{
	Function BeginTrouble()
	{
		PlayLSAnim("SFInstructor_TakeYourSeat",InstructorOne,1,512);
		RememberState("OutOfChair2",1);
		StartTimer("Escelate",10,false);
	}
	Function EndTrouble()
	{
		StopTimer("BeginTrouble",0);
		StopTimer("Escelate",0);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Escelate")
		{
			ChangeState("OutOfChair2");
			return true;
		}
		return GlobalTimer(Name);
	}
}
*/

/*
State OutOfChair2 extends Trouble
{
	Function BeginTrouble()
	{
		PlayLSAnim("SFInstructor_Discipline2",InstructorOne,1,512);
		RememberState("Busted",1);
		StartTimer("Escelate",10,false);
	}
	Function EndTrouble()
	{
		StopTimer("BeginTrouble",0);
		StopTimer("Escelate",0);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "Escelate")
		{
			ChangeState("Busted");
			return true;
		}
		return GlobalTimer(Name);
	}
}
*/

/*
State Busted extends Trouble
{
	Function BeginTrouble()
	{
		PlayLSAnim("SFInstructor_Reprimand",InstructorOne,1,512);
		Controller.GotoState("MedicTraining_Frozen");
		FadeOut(2,true);
		PlayerLock(true,true);
		StartTimer("tmrLoadEntry",5,false);
	}
	Function EndTrouble()
	{
		StopTimer("BeginTrouble",0);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "tmrLoadEntry")
		{
			ResetLipsincAnim();
			RunConsoleCommand("open entry2");
			return true;
		}
		return GlobalTimer(Name);
	}
}
*/

/*
State CheatExamReprimand
{
	Function BeginState()
	{
		ResetLipsincAnim();
		StartTimer("CheatExamReprimandTimer1",3,false);
		FadeOut(2,true);
	}
	Function bool Timer_Timer(FName Name)
	{
		AGP_Characters.NPC_MedStudent* MS = nullptr;
		if (Name == "CheatExamReprimandTimer1")
		{
			ForEach AllActors(ANPC_MedStudent::StaticClass(),MS)
			{
				MS.bHidden=true;
			}
			StartTimer("CheatExamReprimandTimer2",3,false);
			FadeIn(1,true);
		}
		else
		{
			if (Name == "CheatExamReprimandTimer2")
			{
				PlayLSAnim("SFInstructor_Reprimand",InstructorOne,1,512);
			}
			else
			{
				if (Name == "CheatExamReprimandTimer3")
				{
					FadeIn(1,true);
					PlayerLock(true,true);
					InstructorOne.bHidden=true;
					SFFirstSergeant.bHidden=false;
					Player.SetLocation(GetActorLocation("ReprimandPlayerLoc"));
					Controller.SetRotation(GetActorRotation("ReprimandPlayerLoc"));
					SFFirstSergeant.SetLocation(GetActorLocation("ReprimandInstructorLoc"));
					SFFirstSergeant.LoopAnim("frontidle");
					PlayLSAnim("SFFirstSergeant_Reprimand1",SFFirstSergeant,1,512);
					UpdatePlayerCheaterLevel();
				}
			}
		}
		return GlobalTimer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_Reprimand")
		{
			StartTimer("CheatExamReprimandTimer3",3,false);
			FadeOut(1,true);
		}
		if (Name == "SFFirstSergeant_Reprimand1")
		{
			ResetLipsincAnim();
			RunConsoleCommand("open entry2");
		}
		return true;
	}
}
*/

/*
State Cheating
{
	Function BeginState()
	{
		StartTimer("tmrCheating_Start",0.01,false);
	}
	Function EndState()
	{
		ReCaptureEvent(Controller);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "tmrCheating_Start")
		{
			LookCount ++;
			if (LookCount == 1)
			{
				PlayLSAnim("SFInstructor_TestCheat",InstructorOne,1,512);
			}
			else
			{
				if (LookCount == 2)
				{
					PlayLSAnim("SFInstructor_Discipline2",InstructorOne,1,512);
				}
				else
				{
					ChangeState("Busted");
				}
			}
		}
		return GlobalTimer(Name);
	}
	Function bool Timer_LSAnim(FName Name)
	{
		if (Name == "SFInstructor_TestCheat")
		{
			ChangeState("Testing");
			return true;
		}
	}
}
*/

/*
State KillerCheck extends Lecture
{
	Function CheaterKiller()
	{
		AAGP_Pawn* p = nullptr;
		bool bKiller = false;
		ForEach AllActors(AAGP_Pawn::StaticClass(),p)
		{
			if (p.isDead())
			{
				bKiller=true;
			}
		}
		if (bKiller == true)
		{
			ResetLipsincAnim();
			RunConsoleCommand("open leavenworth");
		}
	}
Begin:
	Sleep(0.1);
	CheaterKiller();
	JL"Begin"
;
}
*/

/*
State GetDownExit
{
	Function BeginState()
	{
		StartTimer("GetDownExitTimer",10,false);
		StartTimer("GetDownExitFade",3,false);
		PlayerLock(true,true);
	}
	Function bool Timer_Timer(FName Name)
	{
		if (Name == "GetDownExitFade")
		{
			FadeOut(1,true);
		}
		else
		{
			if (Name == "GetDownExitTimer")
			{
				ResetLipsincAnim();
				RunConsoleCommand("open entry2");
			}
		}
		return GlobalTimer(Name);
	}
}
*/

bool AEL_CampMackall_Language::DoorTrigger_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case 'DoorTriggerOne':
		Log("DoorTrigger_UsedBy :: " + FString::FromInt(DoorTriggerOne.IsOpen()));
		return DoorTriggerOne_UsedBy(Trigger, aInstigator);
	default:
		return false;
	}
	*/

	return false;    //FAKE    /ELiZ
}

bool AEL_CampMackall_Language::DoorTriggerOne_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator)
{
	return false;    //FAKE    /ELiZ
}

bool AEL_CampMackall_Language::AGP_UseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case 'SeatTriggerOne':
		return SeatTriggerOne_UsedBy(Trigger, aInstigator);
	case 'SeatTriggerTwo':
		return SeatTriggerTwo_UsedBy(Trigger, aInstigator);
	case 'InstructorTriggerOne':
		return InstructorTriggerOne_UsedBy(Trigger, aInstigator);
	case 'InstructorTriggerTwo':
		return InstructorTriggerTwo_UsedBy(Trigger, aInstigator);
	case 'CheatExamTrigger':
		return CheatExamTrigger_UsedBy(Trigger, aInstigator);
	default:
		return false;
	}
	*/

	return false;    //FAKE    /ELiZ
}

bool AEL_CampMackall_Language::Pickup_PickedUp(APickup* NotifyActor, AActor* aInstigator, FString Parms)
{
	/*
	switch (NotifyActor.Tag)
	{
	case 'headphones':
		Log("HEADPHONES ARE NOW ON!!!!!!!");
		bHeadPhonesOn = true;
		return headphones_PickedUp(NotifyActor, aInstigator, Parms);
	default:
		return false;
	}
	*/

	return false;    //FAKE    /ELiZ
}

bool AEL_CampMackall_Language::headphones_PickedUp(APickup* NotifyActor, AActor* aInstigator, FString Parms)
{
	/*
	Log("HEADPHONES ARE NOW ON!!!!!!!");
	bHeadPhonesOn = true;
	*/

	return true;
}

bool AEL_CampMackall_Language::SeatTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return false;    //FAKE    /ELiZ
}

bool AEL_CampMackall_Language::SeatTriggerTwo_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	/*
	if (!TalkedToInstructor)
	{
		PlayTip("Talk to the Instructor", "at the front of lab.", 3);
		Cast<AStudentController>(Controller)->bForceSit = false;
		PlayerLock(false, false);
	}
	if (!bHeadPhonesOn)
	{
		PlayTip("Pickup the headphones", "on the front counter.", 3);
	}
	Log("^^ TalkedToInstructor=" + FString::FromInt(TalkedToInstructor));
	Log("^^ bHeadPhonesOn=" + FString::FromInt(bHeadPhonesOn));
	if (TalkedToInstructor && bHeadPhonesOn)
	{
		Log("Inside Taled and HEADPHONES so practice should be starting and player say down!@!@!@!@!@!@");
		Cast<AStudentController>(Controller)->bForceSit = true;
		StartTimer('audioLabSatDown', 1, false);
		HidePlayer();
		PlayerLock(true, true);
	}
	Log("Inside Taled and HEADPHONES so practice should be starting and player say down!@!@!@!@!@!@");
	Cast<AStudentController>(Controller)->bForceSit = true;
	StartTimer('audioLabSatDown', 1, false);
	HidePlayer();
	PlayerLock(true, true);
	*/

	return true;
}

bool AEL_CampMackall_Language::CheatExamTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	/*
	if (CheatExamTime > GetWorld()->GetTimeSeconds())
	{
		return false;
	}
	CheatExamTime = (GetWorld()->GetTimeSeconds() + 2);
	CheatExamCount++;
	if (CheatExamCount == 1)
	{
		PlayTip("You are about to do ", "something very dishonorable", 2);
	}
	else
	{
		if (CheatExamCount == 2)
		{
			PlayTip("Are you sure you want to cheat? ", "press the <action> on test to confirm ", 2);
		}
		else
		{
			if (CheatExamCount == 3)
			{
				ChangeState('CheatExamReprimand');
			}
		}
	}
	*/

	return true;
}

bool AEL_CampMackall_Language::AGP_Trigger_Trigger(AAGP_Trigger* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case 'SeatVolumeOne':
		return SeatVolumeOne_Trigger(Trigger, aInstigator);
	case 'SeatVolumeTwo':
		return SeatVolumeTwo_Trigger(Trigger, aInstigator);
	case 'DeskVolumeOne':
		return DeskVolumeOne_Trigger(Trigger, aInstigator);
	default:
		return false;
	}
	*/

	return false;    //FAKE    /ELiZ
}

bool AEL_CampMackall_Language::AGP_Trigger_UnTrigger(AAGP_Trigger* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case 'SeatVolumeOne':
		return SeatVolumeOne_UnTrigger(Trigger, aInstigator);
	case 'SeatVolumeTwo':
		return SeatVolumeTwo_UnTrigger(Trigger, aInstigator);
	default:
		return false;
	}
	*/

	return false;    //FAKE    /ELiZ
}

bool AEL_CampMackall_Language::SeatVolumeOne_Trigger(AAGP_Trigger* Trigger, AActor* aInstigator)
{
	return false;    //FAKE    /ELiZ
}

bool AEL_CampMackall_Language::SeatVolumeOne_UnTrigger(AAGP_Trigger* Trigger, AActor* aInstigator)
{
	return false;    //FAKE    /ELiZ
}

bool AEL_CampMackall_Language::SeatVolumeTwo_Trigger(AAGP_Trigger* Trigger, AActor* aInstigator)
{
	return false;    //FAKE    /ELiZ
}

bool AEL_CampMackall_Language::SeatVolumeTwo_UnTrigger(AAGP_Trigger* Trigger, AActor* aInstigator)
{
	return false;    //FAKE    /ELiZ
}

bool AEL_CampMackall_Language::TriggerVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case 'AudioLabTalkToInstructor':
		return AudioLabTalkToInstructor_Enter(Trigger, aInstigator);
	case 'ClassVolumeOne':
		return ClassVolumeOne_Enter(Trigger, aInstigator);
	case 'HasHeardLecture':
		return HasHeardLecture_Enter(Trigger, aInstigator);
	case 'resetvolume':
		return resetvolume_Trigger(Trigger, aInstigator);
	case 'GetDown':
		return GetDown_Trigger(Trigger, aInstigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE    /ELiZ
}

bool AEL_CampMackall_Language::ClassVolumeOne_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return false;    //FAKE    /ELiZ
}

void AEL_CampMackall_Language::PreInit()
{
	/*
	InstructorTriggerOne = Cast<AAGP_UseTrigger>(CaptureEvent('InstructorTriggerOne'));
	InstructorTriggerTwo = Cast<AAGP_UseTrigger>(CaptureEvent('InstructorTriggerTwo'));
	InstructorOne = Cast<ANPC_MedInstructor>(CaptureEvent('InstructorOne'));
	InstructorTwo = Cast<ANPC_MedInstructor>(CaptureEvent('InstructorTwo'));
	SFFirstSergeant = Cast<ANPC_MedInstructor>(CaptureEvent('SFFirstSergeant'));
	SlideProjectorOne = Cast<ASlideProjector>(CaptureEvent('SlideProjectorOne'));
	SeatTriggerOne = Cast<AAGP_UseTrigger>(CaptureEvent('SeatTriggerOne'));
	SeatTriggerTwo = Cast<AAGP_UseTrigger>(CaptureEvent('SeatTriggerTwo'));
	ClassVolumeOne = Cast<ATriggerVolume>(CaptureEvent('ClassVolumeOne'));
	TestVolumeOne = Cast<ATriggerVolume>(CaptureEvent('TestVolumeOne'));
	LeavingVolumeOne = Cast<ATriggerVolume>(CaptureEvent('LeavingVolumeOne'));
	AudioLabTrigger = Cast<ATriggerVolume>(CaptureEvent('AudioLabTrigger'));
	AudioLabTalkToInstructor = Cast<ATriggerVolume>(CaptureEvent('AudioLabTalkToInstructor'));
	HasHeardLecture = Cast<ATriggerVolume>(CaptureEvent('HasHeardLecture'));
	SeatVolumeOne = Cast<AAGP_Trigger>(CaptureEvent('SeatVolumeOne'));
	SeatVolumeTwo = Cast<AAGP_Trigger>(CaptureEvent('SeatVolumeTwo'));
	CaptureEventGroup('DeskVolumeOne');
	CaptureEventGroup('resetvolume');
	CaptureEventGroup('GetDown');
	Student01 = Cast<ANPC_MedStudent>(CaptureEvent('NPC_LanguageStudent01_01'));
	Student02 = Cast<ANPC_MedStudent>(CaptureEvent('NPC_LanguageStudent01_02'));
	Student03 = Cast<ANPC_MedStudent>(CaptureEvent('NPC_LanguageStudent01_03'));
	Student04 = Cast<ANPC_MedStudent>(CaptureEvent('NPC_LanguageStudent01_04'));
	Student05 = Cast<ANPC_MedStudent>(CaptureEvent('NPC_LanguageStudent01_05'));
	Student06 = Cast<ANPC_MedStudent>(CaptureEvent('NPC_LanguageStudent01_06'));
	Student07 = Cast<ANPC_MedStudent>(CaptureEvent('NPC_LanguageStudent01_07'));
	NPC_AudioLabStudent01_07 = Cast<ANPC_MedStudent>(CaptureEvent('NPC_AudioLabStudent01_07'));
	SFLanguageExamOne = Cast<AMedExam>(CaptureEvent('SFLanguageExamOne'));
	SFExamTwo = Cast<AMedExam>(CaptureEvent('SFExamTwo'));
	CheatExamTrigger = Cast<AAGP_UseTrigger>(CaptureEvent('CheatExamTrigger'));
	ReprimandInstructorLoc = Cast<AAGP_Location>(CaptureEvent('ReprimandInstructorLoc'));
	ReprimandPlayerLoc = Cast<AAGP_Location>(CaptureEvent('ReprimandPlayerLoc'));
	DoorTriggerOne = Cast<ADoorTrigger>(CaptureEvent('DoorTriggerOne'));
	headphones = StaticMeshActor(CaptureEvent('headphones'));
	*/
}

void AEL_CampMackall_Language::Init()
{
}

void AEL_CampMackall_Language::PostInit()
{
}

void AEL_CampMackall_Language::PostPostInit()
{
	ANPC_MedStudent* MS = nullptr;
	/*
	ReCaptureEvent(Cast<AAGP_HUD>(Controller.myHUD));
	InstructorOne.bEyeTrack = false;
	InstructorOne.LoopAnim('DrillIdle', 1, 1);
	InstructorTwo.GotoState('ProfessorEyeTrackPlayer', 'Begin');
	ForEach AllActors(ANPC_MedStudent::StaticClass(), MS)
	{
		if (MS.EyesTrack == true)
		{
			MS.GotoState('StudentEyeTrackState', 'Begin');
		}
	}
	ChangeState('EnterClass');
	Level.bEnableCommo = false;
	Level.bSkipTest = true;
	SFTestStartLocation = SFLanguageExamOne.Location;
	SFLanguageExamOne.SetActive(false);
	SFFirstSergeant.bHidden = true;
	Cast<AStudentController>(Controller)->bForceSit = true;
	DoorTriggerOne.ToggleOpen();
	headphones.bHidden = false;
	headphones.SetRotation(FRotator(1292, -14716, 32336));
	HeadPhonesStartPosition = headphones.Location;
	*/
}

bool AEL_CampMackall_Language::InstructorTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	/*
	if (LectureDone == false)
	{
		if (!bInstUseDisable)
		{
			bInstUseDisable = true;
			PlayLSAnim('SFInstructor_TakeYourSeat', InstructorOne, 1, 512);
			StartTimer('C1_TakeASeat', 2, false);
		}
	}
	else
	{
		PlayTip("Head over to the audio Lab", "testing will begin soon", 5);
	}
	*/
	return true;
}

bool AEL_CampMackall_Language::InstructorTriggerTwo_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	/*
	if (bEnteredAudioLab == true)
	{
		return false;
	}
	//ChangeState("EnterAudioLab");
	*/
	return true;
}

bool AEL_CampMackall_Language::HasHeardLecture_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return true;
	/*
	if (bClassEntered == false)
	{
		if (DoorTriggerOne.IsOpen())
		{
			DoorTriggerOne.ToggleOpen();
		}
		ChangeState('ResetLevel');
	}
	*/
	return true;
}

bool AEL_CampMackall_Language::GetDown_Trigger(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	UnCaptureEventGroup('DeskVolumeOne');
	if (GetDownTimer > GetWorld()->GetTimeSeconds())
	{
		return false;
	}
	GetDownTimer = (GetWorld()->GetTimeSeconds() + 5);
	if (GetDownCount == 0)
	{
		PlayLSAnim('SFInstructor02_Warning01', InstructorTwo, 1, 512);
	}
	else
	{
		if (GetDownCount == 1)
		{
			PlayLSAnim('SFInstructor02_Warning02', InstructorTwo, 1, 512);
		}
		else
		{
			if (GetDownCount == 2)
			{
				PlayLSAnim('SFInstructor02_Warning03', InstructorTwo, 1, 512);
			}
			else
			{
				if (GetDownCount == 3)
				{
					PlayLSAnim('SFInstructor02_Warning04', InstructorTwo, 1, 512);
					ChangeState('GetDownExit');
				}
			}
		}
	}
	GetDownCount++;
	*/
	return true;
}

bool AEL_CampMackall_Language::resetvolume_Trigger(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	if (DoorTriggerOne.IsOpen())
	{
		DoorTriggerOne.ToggleOpen();
	}
	ChangeState('ResetLevel');
	*/
	return true;
}

bool AEL_CampMackall_Language::AudioLabTalkToInstructor_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	if (bEnteredAudioLab == true)
	{
		return false;
	}
	PlayTip("Find the Instructor and ", "press the <action> key on him", 5);
	*/
	return true;
}

bool AEL_CampMackall_Language::DeskVolumeOne_Trigger(AAGP_Trigger* Trigger, AActor* aInstigator)
{
	return true;
	/*
	UnCaptureEventGroup("DeskVolumeOne");
	StartTimer("ReCaptureDesk", 3, false);
	GoofCount++;
	if (GoofCount == 1)
	{
		PlayLSAnim("SFInstructor_Discipline1", InstructorOne, 1, 512);
	}
	else
	{
		if (GoofCount == 2)
		{
			PlayLSAnim("SFInstructor_Discipline2", InstructorOne, 1, 512);
		}
		else
		{
			if (GoofCount > 2)
			{
				ChangeState("Busted");
			}
		}
	}
	*/

	return true;
}

void AEL_CampMackall_Language::ResetLipsincAnim()
{
	InstructorOne->StopLIPSincAnim();
}

bool AEL_CampMackall_Language::GlobalTimer(FName Name)
{
	if (Name == "ReCaptureDesk")
	{
		CaptureEventGroup("DeskVolumeOne");
		return true;
	}
	if (Name == "TakeASeat")
	{
		bInstUseDisable = false;
		return true;
	}
	return false;
}

bool AEL_CampMackall_Language::UpdateTestAnswers(int32 Switch)
{
	ACommoLocalMessage* CommoType = nullptr;
	/*
	CommoType = ACommoTestAnswers::StaticClass();
	Level.bEnableCommo = true;
	CommoType.Default._messagename = "Answers";
	switch (Switch)
	{
	case 0:
		CommoType.Default._Messages[0] = "Stop moving";
		CommoType.Default._Messages[1] = "Take cover";
		CommoType.Default._Messages[2] = "Grenade";
		CommoType.Default._Messages[3] = "Cover me";
		CommoType.Default._Messages[4] = "I'm Hit";
		CommoType.Default._Messages[5] = "";
		theCorrectAnswerIs = 50;
		return true;
	case 1:
		CommoType.Default._Messages[0] = "Roger";
		CommoType.Default._Messages[1] = "Get the Door";
		CommoType.Default._Messages[2] = "Frag Out";
		CommoType.Default._Messages[3] = "Ready";
		CommoType.Default._Messages[4] = "";
		theCorrectAnswerIs = 50;
		return true;
	case 2:
		CommoType.Default._Messages[0] = "Roger";
		CommoType.Default._Messages[1] = "Enemy Down";
		CommoType.Default._Messages[2] = "Secure the Area";
		CommoType.Default._Messages[3] = "Frag Out";
		CommoType.Default._Messages[4] = "";
		theCorrectAnswerIs = 51;
		return true;
	case 3:
		CommoType.Default._Messages[0] = "North";
		CommoType.Default._Messages[1] = "Up";
		CommoType.Default._Messages[2] = "Left";
		CommoType.Default._Messages[3] = "Right";
		CommoType.Default._Messages[4] = "";
		theCorrectAnswerIs = 52;
		return true;
	case 4:
		CommoType.Default._Messages[0] = "Negative";
		CommoType.Default._Messages[1] = "Enemy Spotted";
		CommoType.Default._Messages[2] = "Move Out";
		CommoType.Default._Messages[3] = "Frag Em";
		CommoType.Default._Messages[4] = "";
		theCorrectAnswerIs = 50;
		return true;
	case 5:
		CommoType.Default._Messages[0] = "Stop";
		CommoType.Default._Messages[1] = "Enemy Spotted";
		CommoType.Default._Messages[2] = "Up";
		CommoType.Default._Messages[3] = "Frag Em";
		CommoType.Default._Messages[4] = "";
		theCorrectAnswerIs = 49;
		return true;
	case 6:
		CommoType.Default._Messages[0] = "Down";
		CommoType.Default._Messages[1] = "Move Out";
		CommoType.Default._Messages[2] = "Roger";
		CommoType.Default._Messages[3] = "Cover Me";
		CommoType.Default._Messages[4] = "";
		theCorrectAnswerIs = 52;
		return true;
	case 7:
		CommoType.Default._Messages[0] = "Stop";
		CommoType.Default._Messages[1] = "Frag Out";
		CommoType.Default._Messages[2] = "Secure the Area";
		CommoType.Default._Messages[3] = "North";
		CommoType.Default._Messages[4] = "";
		theCorrectAnswerIs = 50;
		return true;
	case 8:
		CommoType.Default._Messages[0] = "Up";
		CommoType.Default._Messages[1] = "Left";
		CommoType.Default._Messages[2] = "Stop";
		CommoType.Default._Messages[3] = "North";
		CommoType.Default._Messages[4] = "";
		theCorrectAnswerIs = 49;
		return true;
	case 9:
		CommoType.Default._Messages[0] = "Right";
		CommoType.Default._Messages[1] = "Grenade";
		CommoType.Default._Messages[2] = "East";
		CommoType.Default._Messages[3] = "North";
		CommoType.Default._Messages[4] = "";
		theCorrectAnswerIs = 51;
		return true;
	case 10:
		CommoType.Default._Messages[0] = "Stop Moving";
		CommoType.Default._Messages[1] = "Enemy Spotted";
		CommoType.Default._Messages[2] = "Move Out";
		CommoType.Default._Messages[3] = "Check Your Flanks";
		CommoType.Default._Messages[4] = "";
		theCorrectAnswerIs = 52;
		return true;
	case 11:
		CommoType.Default._Messages[0] = "Area Secure";
		CommoType.Default._Messages[1] = "Frag Em";
		CommoType.Default._Messages[2] = "Negative";
		CommoType.Default._Messages[3] = "Secure the Area";
		CommoType.Default._Messages[4] = "";
		theCorrectAnswerIs = 49;
		return true;
	default:
		CommoType.Default._Messages[0] = "";
		CommoType.Default._Messages[1] = "";
		CommoType.Default._Messages[2] = "";
		CommoType.Default._Messages[3] = "";
		CommoType.Default._Messages[4] = "";
		Level.bEnableCommo = false;
		return false;
	}
	*/

	return false;    //FAKE    /ELiZ
}

void AEL_CampMackall_Language::StudentsTakeNotes()
{
	/*
	Student01.GotoState('StudentTakeNotes', 'Begin');
	Student02.GotoState('StudentTakeNotes', 'Begin');
	Student03.GotoState('StudentTakeNotes', 'Begin');
	Student04.GotoState('StudentTakeNotes', 'Begin');
	Student05.GotoState('StudentTakeNotes', 'Begin');
	Student06.GotoState('StudentTakeNotes', 'Begin');
	Student07.GotoState('StudentTakeNotes', 'Begin');
	Student01.fAnimTimer = (GetWorld()->GetTimeSeconds() + 1.3);
	Student02.fAnimTimer = (GetWorld()->GetTimeSeconds() + 0.6);
	Student03.fAnimTimer = (GetWorld()->GetTimeSeconds() + 2.1);
	Student04.fAnimTimer = (GetWorld()->GetTimeSeconds() + 1.2);
	Student05.fAnimTimer = (GetWorld()->GetTimeSeconds() + 0.3);
	Student06.fAnimTimer = (GetWorld()->GetTimeSeconds() + 1.8);
	Student07.fAnimTimer = (GetWorld()->GetTimeSeconds() + 0.9);
	*/
}

void AEL_CampMackall_Language::StudentsIdle()
{
	/*
	Student01.GotoState('StudentIdle', 'Begin');
	Student02.GotoState('StudentIdle', 'Begin');
	Student03.GotoState('StudentIdle', 'Begin');
	Student04.GotoState('StudentIdle', 'Begin');
	Student05.GotoState('StudentIdle', 'Begin');
	Student06.GotoState('StudentIdle', 'Begin');
	Student07.GotoState('StudentIdle', 'Begin');
	*/
}

void AEL_CampMackall_Language::StudentsRaiseHands(int32 Which)
{
	/*
	switch (Which)
	{
	case 1:
		//Student01.GotoState('StudentRaiseHand', 'Begin');
		//Student04.GotoState('StudentRaiseHand', 'Begin');
		//Student03.GotoState('StudentRaiseHand', 'Begin');
		break;
	case 2:
		//Student02.GotoState('StudentRaiseHand', 'Begin');
		//Student04.GotoState('StudentRaiseHand', 'Begin');
		//Student03.GotoState('StudentRaiseHand', 'Begin');
		break;
	case 3:
		//Student03.GotoState('StudentRaiseHand', 'Begin');
		//Student02.GotoState('StudentRaiseHand', 'Begin');
		//Student01.GotoState('StudentRaiseHand', 'Begin');
		break;
	case 4:
		//Student04.GotoState('StudentRaiseHand', 'Begin');
		//Student02.GotoState('StudentRaiseHand', 'Begin');
		//Student01.GotoState('StudentRaiseHand', 'Begin');
		break;
	case 5:
		//Student05.GotoState('StudentRaiseHand', 'Begin');
		//Student04.GotoState('StudentRaiseHand', 'Begin');
		//Student03.GotoState('StudentRaiseHand', 'Begin');
		break;
	case 6:
		//Student06.GotoState('StudentRaiseHand', 'Begin');
		//Student04.GotoState('StudentRaiseHand', 'Begin');
		//Student03.GotoState('StudentRaiseHand', 'Begin');
		break;
	case 7:
		//Student07.GotoState('StudentRaiseHand', 'Begin');
		//Student02.GotoState('StudentRaiseHand', 'Begin');
		//Student01.GotoState('StudentRaiseHand', 'Begin');
		break;
	default:
		break;
	}
	*/
}

void AEL_CampMackall_Language::StudentsLowerHands(int32 Which)
{
	/*
	switch (Which)
	{
	case 1:
		//Student01.GotoState('StudentIdle', 'Begin');
		//Student04.GotoState('StudentIdle', 'Begin');
		//Student03.GotoState('StudentIdle', 'Begin');
		break;
	case 2:
		//Student02.GotoState('StudentIdle', 'Begin');
		//Student04.GotoState('StudentIdle', 'Begin');
		//Student03.GotoState('StudentIdle', 'Begin');
		break;
	case 3:
		//Student03.GotoState('StudentIdle', 'Begin');
		//Student02.GotoState('StudentIdle', 'Begin');
		//Student01.GotoState('StudentIdle', 'Begin');
		break;
	case 4:
		//Student04.GotoState('StudentIdle', 'Begin');
		//Student02.GotoState('StudentIdle', 'Begin');
		//Student01.GotoState('StudentIdle', 'Begin');
		break;
	case 5:
		//Student05.GotoState('StudentIdle', 'Begin');
		//Student04.GotoState('StudentIdle', 'Begin');
		//Student03.GotoState('StudentIdle', 'Begin');
		break;
	case 6:
		//Student06.GotoState('StudentIdle', 'Begin');
		//Student04.GotoState('StudentIdle', 'Begin');
		//Student03.GotoState('StudentIdle', 'Begin');
		break;
	case 7:
		//Student07.GotoState('StudentIdle', 'Begin');
		//Student02.GotoState('StudentIdle', 'Begin');
		//Student01.GotoState('StudentIdle', 'Begin');
		break;
	default:
		break;
	}
	*/
}

void AEL_CampMackall_Language::SayTestWord(int32 Snd)
{
	AActor* SoundActor = nullptr;
	USoundBase* SoundPtr = nullptr;
	ACommoLocalMessage* CommoType = nullptr;
	/*
	if (bNoVoice == true)
	{
		return;
	}
	CommoType = ACommoShout::StaticClass();
	SoundPtr = CommoType.Default._Sounds3[Snd];
	if (SoundPtr != nullptr)
	{
		SoundActor = Spawn(AEffectLocation::StaticClass(), , , Player.Location);
		SoundActor.LifeSpan = GetSoundDuration(SoundPtr);
		SoundActor.PlaySound(SoundPtr, 0, 1, , , , false);
	}
	*/
}

void AEL_CampMackall_Language::StudentAnswer(int32 Which)
{
	switch (Which)
	{
	case 1:
		//Student01.GotoState('StudentAnswer', 'Begin');
		break;
	case 2:
		//Student02.GotoState('StudentAnswer', 'Begin');
		break;
	case 3:
		//Student03.GotoState('StudentAnswer', 'Begin');
		break;
	case 4:
		//Student04.GotoState('StudentAnswer', 'Begin');
		break;
	case 5:
		//Student05.GotoState('StudentAnswer', 'Begin');
		break;
	case 6:
		//Student06.GotoState('StudentAnswer', 'Begin');
		break;
	case 7:
		//Student07.GotoState('StudentAnswer', 'Begin');
		break;
	default:
		break;
	}
}

void AEL_CampMackall_Language::StudentReturnsToIdle(int32 Which)
{
	switch (Which)
	{
	case 1:
		//Student01.GotoState('StudentIdle', 'Begin');
		break;
	case 2:
		//Student02.GotoState('StudentIdle', 'Begin');
		break;
	case 3:
		//Student03.GotoState('StudentIdle', 'Begin');
		break;
	case 4:
		//Student04.GotoState('StudentIdle', 'Begin');
		break;
	case 5:
		//Student05.GotoState('StudentIdle', 'Begin');
		break;
	case 6:
		//Student06.GotoState('StudentIdle', 'Begin');
		break;
	case 7:
		//Student07.GotoState('StudentIdle', 'Begin');
		break;
	default:
		break;
	}
}

void AEL_CampMackall_Language::DisplayCorrectAnswer(int32 Key)
{
	ACommoLocalMessage* CommoType = nullptr;
	/*
	CommoType = ACommoTestAnswers::StaticClass();
	Level.bEnableCommo = false;
	if (theCorrectAnswerIs == 49)
	{
		sTheAnswer = CommoType.Default._Messages[0];
	}
	else
	{
		if (theCorrectAnswerIs == 50)
		{
			sTheAnswer = CommoType.Default._Messages[1];
		}
		else
		{
			if (theCorrectAnswerIs == 51)
			{
				sTheAnswer = CommoType.Default._Messages[2];
			}
			else
			{
				if (theCorrectAnswerIs == 52)
				{
					sTheAnswer = CommoType.Default._Messages[3];
				}
				else
				{
					if (theCorrectAnswerIs == 53)
					{
						sTheAnswer = CommoType.Default._Messages[4];
					}
					else
					{
						if (theCorrectAnswerIs == 54)
						{
							sTheAnswer = CommoType.Default._Messages[5];
						}
						else
						{
							sTheAnswer = "Unknown";
						}
					}
				}
			}
		}
	}
	if (theCorrectAnswerIs == Key)
	{
		PlayTip("Correct the answer was ", sTheAnswer, 0.5);
	}
	else
	{
		PlayTip("Wrong the correct answer was ", sTheAnswer, 0.5);
	}
	*/
}

void AEL_CampMackall_Language::PrepareQuestion()
{
	int32 Which = 0;
	ACommoLocalMessage* CommoType = nullptr;
	/*
	CommoType = ACommoTestAnswers::StaticClass();
	if (LastQuestion == 0)
	{
		Which = (Rand(15) + 1);
	}
	else
	{
		Which = LastQuestion;
	}
	LastQuestion = Which;
	CommoType.Default._Messages[5] = "";
	CommoType.Default._messagename = "Practice";
	Level.bEnableCommo = true;
	switch (Which)
	{
	case 1:
		CommoType.Default._Messages[0] = "Move Out";
		CommoType.Default._Messages[1] = "Enemy Spotted";
		CommoType.Default._Messages[2] = "I'm Hit";
		CommoType.Default._Messages[3] = "Secure the Area";
		theCorrectAnswerIs = 51;
		SayTestWord(24);
		break;
	case 2:
		CommoType.Default._Messages[0] = "Take Cover";
		CommoType.Default._Messages[1] = "Enemy Down";
		CommoType.Default._Messages[2] = "Frag Em";
		CommoType.Default._Messages[3] = "Check your Flanks";
		theCorrectAnswerIs = 50;
		SayTestWord(5);
		break;
	case 3:
		CommoType.Default._Messages[0] = "East";
		CommoType.Default._Messages[1] = "Down";
		CommoType.Default._Messages[2] = "Right";
		CommoType.Default._Messages[3] = "West";
		theCorrectAnswerIs = 52;
		SayTestWord(16);
		break;
	case 4:
		CommoType.Default._Messages[0] = "Frag Em";
		CommoType.Default._Messages[1] = "Enemy Down";
		CommoType.Default._Messages[2] = "Take Cover";
		CommoType.Default._Messages[3] = "Check your Flanks";
		theCorrectAnswerIs = 49;
		SayTestWord(19);
		break;
	case 5:
		CommoType.Default._Messages[0] = "Negative";
		CommoType.Default._Messages[1] = "Ready";
		CommoType.Default._Messages[2] = "Roger";
		CommoType.Default._Messages[3] = "Stop";
		theCorrectAnswerIs = 50;
		SayTestWord(23);
		break;
	case 6:
		CommoType.Default._Messages[0] = "Get the Door";
		CommoType.Default._Messages[1] = "Enemy Down";
		CommoType.Default._Messages[2] = "Move Out";
		CommoType.Default._Messages[3] = "Enemy Spotted";
		theCorrectAnswerIs = 51;
		SayTestWord(0);
		break;
	case 7:
		CommoType.Default._Messages[0] = "Up";
		CommoType.Default._Messages[1] = "North";
		CommoType.Default._Messages[2] = "East";
		CommoType.Default._Messages[3] = "Left";
		theCorrectAnswerIs = 49;
		SayTestWord(9);
		break;
	case 8:
		CommoType.Default._Messages[0] = "Roger";
		CommoType.Default._Messages[1] = "Take Cover";
		CommoType.Default._Messages[2] = "Negative";
		CommoType.Default._Messages[3] = "Stop";
		theCorrectAnswerIs = 52;
		SayTestWord(1);
		break;
	case 9:
		CommoType.Default._Messages[0] = "Enemy Spotted";
		CommoType.Default._Messages[1] = "Check your Flanks";
		CommoType.Default._Messages[2] = "Frag Out";
		CommoType.Default._Messages[3] = "Area Secure";
		theCorrectAnswerIs = 52;
		SayTestWord(6);
		break;
	case 10:
		CommoType.Default._Messages[0] = "Frag Out";
		CommoType.Default._Messages[1] = "Secure the Area";
		CommoType.Default._Messages[2] = "Frag Em";
		CommoType.Default._Messages[3] = "Get the Door";
		theCorrectAnswerIs = 49;
		SayTestWord(27);
		break;
	case 11:
		CommoType.Default._Messages[0] = "East";
		CommoType.Default._Messages[1] = "Right";
		CommoType.Default._Messages[2] = "North";
		CommoType.Default._Messages[3] = "Down";
		theCorrectAnswerIs = 50;
		SayTestWord(12);
		break;
	case 12:
		CommoType.Default._Messages[0] = "Enemy Spotted";
		CommoType.Default._Messages[1] = "Enemy Down";
		CommoType.Default._Messages[2] = "Check your Flanks";
		CommoType.Default._Messages[3] = "Move Out";
		theCorrectAnswerIs = 49;
		SayTestWord(3);
		break;
	case 13:
		CommoType.Default._Messages[0] = "Secure the Area";
		CommoType.Default._Messages[1] = "Cover Me";
		CommoType.Default._Messages[2] = "Roger";
		CommoType.Default._Messages[3] = "Get the Door";
		theCorrectAnswerIs = 52;
		SayTestWord(25);
		break;
	case 14:
		CommoType.Default._Messages[0] = "I'm Hit";
		CommoType.Default._Messages[1] = "Sniper";
		CommoType.Default._Messages[2] = "Secure the Area";
		CommoType.Default._Messages[3] = "Ready";
		theCorrectAnswerIs = 51;
		SayTestWord(28);
		break;
	case 15:
		CommoType.Default._Messages[0] = "Take Cover";
		CommoType.Default._Messages[1] = "Grenade";
		CommoType.Default._Messages[2] = "Negative";
		CommoType.Default._Messages[3] = "Sniper";
		theCorrectAnswerIs = 49;
		SayTestWord(4);
		break;
	default:
		Log("PrepareQuestion::Unknown Question ( out of range )");
		return;
	}
	*/
}

void AEL_CampMackall_Language::DisplayCorrectPageOnTest()
{
	/*
	if ((iCurrentQuestion > 3) && (iCurrentQuestion < 7))
	{
		SFLanguageExamOne.DestroyPage(SFLanguageExamOne.CurrentPage);
		SFLanguageExamOne.CurrentPage = 2;
		SFLanguageExamOne.CreatePage(SFLanguageExamOne.CurrentPage);
	}
	else
	{
		if ((iCurrentQuestion > 6) && (iCurrentQuestion < 10))
		{
			SFLanguageExamOne.DestroyPage(SFLanguageExamOne.CurrentPage);
			SFLanguageExamOne.CurrentPage = 3;
			SFLanguageExamOne.CreatePage(SFLanguageExamOne.CurrentPage);
		}
		else
		{
			if ((iCurrentQuestion > 9) && (iCurrentQuestion < 13))
			{
				SFLanguageExamOne.DestroyPage(SFLanguageExamOne.CurrentPage);
				SFLanguageExamOne.CurrentPage = 4;
				SFLanguageExamOne.CreatePage(SFLanguageExamOne.CurrentPage);
			}
			else
			{
				if (iCurrentQuestion > 12)
				{
					SFLanguageExamOne.DestroyPage(SFLanguageExamOne.CurrentPage);
					SFLanguageExamOne.CurrentPage = 5;
					SFLanguageExamOne.CreatePage(SFLanguageExamOne.CurrentPage);
				}
				else
				{
					SFLanguageExamOne.DestroyPage(SFLanguageExamOne.CurrentPage);
					SFLanguageExamOne.CurrentPage = 1;
					SFLanguageExamOne.CreatePage(SFLanguageExamOne.CurrentPage);
				}
			}
		}
	}
	*/
}

void AEL_CampMackall_Language::UpdateCorrectAnswersFromLecture()
{
	if (bAnswer7 == true)
	{
		//SFLanguageExamOne.TestPages[3].TestAnswers[0].bMarkedCorrect = true;
		//SFLanguageExamOne.TestPages[3].TestAnswers[0].Answer.SetMark(true);
	}
	if (bAnswer8 == true)
	{
		//SFLanguageExamOne.TestPages[3].TestAnswers[7].bMarkedCorrect = true;
		//SFLanguageExamOne.TestPages[3].TestAnswers[7].Answer.SetMark(true);
	}
	if (bAnswer9 == true)
	{
		//SFLanguageExamOne.TestPages[3].TestAnswers[11].bMarkedCorrect = true;
		//SFLanguageExamOne.TestPages[3].TestAnswers[11].Answer.SetMark(true);
	}
	if (bAnswer10 == true)
	{
		//SFLanguageExamOne.TestPages[4].TestAnswers[0].bMarkedCorrect = true;
		//SFLanguageExamOne.TestPages[4].TestAnswers[0].Answer.SetMark(true);
	}
	if (bAnswer11 == true)
	{
		//SFLanguageExamOne.TestPages[4].TestAnswers[5].bMarkedCorrect = true;
		//SFLanguageExamOne.TestPages[4].TestAnswers[5].Answer.SetMark(true);
	}
	if (bAnswer12 == true)
	{
		//SFLanguageExamOne.TestPages[4].TestAnswers[8].bMarkedCorrect = true;
		//SFLanguageExamOne.TestPages[4].TestAnswers[8].Answer.SetMark(true);
	}
	if (bAnswer13 == true)
	{
		//SFLanguageExamOne.TestPages[5].TestAnswers[3].bMarkedCorrect = true;
		//SFLanguageExamOne.TestPages[5].TestAnswers[3].Answer.SetMark(true);
	}
	if (bAnswer14 == true)
	{
		//SFLanguageExamOne.TestPages[5].TestAnswers[6].bMarkedCorrect = true;
		//SFLanguageExamOne.TestPages[5].TestAnswers[6].Answer.SetMark(true);
	}
	if (bAnswer15 == true)
	{
		//SFLanguageExamOne.TestPages[5].TestAnswers[8].bMarkedCorrect = true;
		//SFLanguageExamOne.TestPages[5].TestAnswers[8].Answer.SetMark(true);
	}
}

void AEL_CampMackall_Language::SayTestQuestion(bool bMessageOnly)
{
	ACommoLocalMessage* CommoType = nullptr;
	/*
	CommoType = ACommoTestAnswers::StaticClass();
	CommoType.Default._Messages[0] = "# " + FString::FromInt(iCurrentQuestion);
	CommoType.Default._Messages[1] = "";
	CommoType.Default._Messages[2] = "";
	CommoType.Default._Messages[3] = "";
	CommoType.Default._Messages[4] = "";
	CommoType.Default._Messages[5] = "";
	CommoType.Default._messagename = "Question";
	Level.bEnableCommo = true;
	if (bMessageOnly == true)
	{
		bNoVoice = true;
	}
	else
	{
		bNoVoice = false;
	}
	Log("SayTestQuestion :: " + FString::FromInt(iCurrentQuestion));
	switch (iCurrentQuestion)
	{
	case 1:
		CommoType.Default._Messages[1] = "Ya Ranenite";
		SayTestWord(24);
		break;
	case 2:
		CommoType.Default._Messages[1] = "Vrag Ranenat";
		SayTestWord(5);
		break;
	case 3:
		CommoType.Default._Messages[1] = "Ostock";
		SayTestWord(16);
		break;
	case 4:
		CommoType.Default._Messages[1] = "Brosite Oskolo";
		SayTestWord(19);
		break;
	case 5:
		CommoType.Default._Messages[1] = "Gotove";
		SayTestWord(23);
		break;
	case 6:
		CommoType.Default._Messages[1] = "Napadateniti";
		SayTestWord(0);
		break;
	case 7:
		CommoType.Default._Messages[1] = "Fierk";
		SayTestWord(9);
		break;
	case 8:
		CommoType.Default._Messages[1] = "Stoeti";
		SayTestWord(1);
		break;
	case 9:
		CommoType.Default._Messages[1] = "Raiono Okranit";
		SayTestWord(6);
		break;
	case 10:
		CommoType.Default._Messages[1] = "Brosite Granata";
		SayTestWord(27);
		break;
	case 11:
		CommoType.Default._Messages[1] = "Plof";
		SayTestWord(12);
		break;
	case 12:
		CommoType.Default._Messages[1] = "Vrag Pyatnaten";
		SayTestWord(3);
		break;
	case 13:
		CommoType.Default._Messages[1] = "Proveriteni Dvera";
		SayTestWord(25);
		break;
	case 14:
		CommoType.Default._Messages[1] = "Okraniteniti Raiono";
		SayTestWord(28);
		break;
	case 15:
		CommoType.Default._Messages[1] = "Koperti";
		SayTestWord(4);
		break;
	default:
		Log("SayTestQuestion::Unknown Question ( out of range )");
		return;
	}
	DisplayCorrectPageOnTest();
	if ((bAnswer15 == true) && (iCurrentQuestion == 15))
	{
		CommoType.Default._Messages[1] = "Credit has already been awarded";
		CommoType.Default._Messages[2] = "for class participation on question 15";
	}
	if ((bAnswer14 == true) && (iCurrentQuestion == 14))
	{
		CommoType.Default._Messages[1] = "Credit has already been awarded";
		CommoType.Default._Messages[2] = "for class participation on question 14";
	}
	if ((bAnswer13 == true) && (iCurrentQuestion == 13))
	{
		CommoType.Default._Messages[1] = "Credit has already been awarded";
		CommoType.Default._Messages[2] = "for class participation on question 13";
	}
	if ((bAnswer12 == true) && (iCurrentQuestion == 12))
	{
		CommoType.Default._Messages[1] = "Credit has already been awarded";
		CommoType.Default._Messages[2] = "for class participation on question 12";
	}
	if ((bAnswer11 == true) && (iCurrentQuestion == 11))
	{
		CommoType.Default._Messages[1] = "Credit has already been awarded";
		CommoType.Default._Messages[2] = "for class participation on question 11";
	}
	if ((bAnswer10 == true) && (iCurrentQuestion == 10))
	{
		CommoType.Default._Messages[1] = "Credit has already been awarded";
		CommoType.Default._Messages[2] = "for class participation on question 15";
	}
	if ((bAnswer9 == true) && (iCurrentQuestion == 9))
	{
		CommoType.Default._Messages[1] = "Credit has already been awarded";
		CommoType.Default._Messages[2] = "for class participation on question 15";
	}
	if ((bAnswer8 == true) && (iCurrentQuestion == 8))
	{
		CommoType.Default._Messages[1] = "Credit has already been awarded";
		CommoType.Default._Messages[2] = "for class participation on question 15";
	}
	if ((bAnswer7 == true) && (iCurrentQuestion == 7))
	{
		CommoType.Default._Messages[1] = "Credit has already been awarded";
		CommoType.Default._Messages[2] = "for class participation on question 15";
	}
	*/
}
void AEL_CampMackall_Language::UpdatePlayerCheaterLevel()
{
}
