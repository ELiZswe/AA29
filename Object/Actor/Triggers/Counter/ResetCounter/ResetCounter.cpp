// All the original content belonged to the US Army


#include "AA29/Object/Actor/Triggers/Counter/ResetCounter/ResetCounter.h"


AResetCounter::AResetCounter()
{

}

void AResetCounter::Reset()
{
	OriginalNum = NumToCount;
}

void AResetCounter::MatchStarting()
{
	if (bResetAtRoundEnd)
	{
		Reset();
	}
}