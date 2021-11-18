// All the original content belonged to the US Army


#include "AA29/Info/LocalMessage/CommoLocalMessage/CommoHandSignal/CommoHandSignal.h"

ACommoHandSignal::ACommoHandSignal()
{
	Messaged = "signaled";
	_iNumMessages = 9;
	_Messages = {"Move out","Stop","Get down","Look this way","Ready","Double time","Affirmative","Negative","Hand Signal"};
	_fSoundVolume = 0;
	_Animations = { "SgnlMoveOutLg",	"SgnlHoldLg",	"SgnlTakeCoverLg",	"SgnlPointFwdLg",	"SgnlReadyLg",	"SgnlDoubleTimeLg",	"SgnlAffirmLg",	"SgnlNegLg" };
	_commotype = ECommoType::COMMOTYPE_Hand;
}

void ACommoHandSignal::GetSound(int32 Switch, AAA2_PlayerState* SenderPRI, AAA2_PlayerState* LocalPRI)
{
	//return None;
}