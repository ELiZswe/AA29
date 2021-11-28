// All the original content belonged to the US Army


#include "AA29/Object/Actor/Triggers/Counter/Counter.h"

ACounter::ACounter()
{
	NumToCount = 2;
	CountMessage = "Only %i more to go...";
	CompleteMessage = "Completed!";
	//Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/GamePlay/S_Counter_Mat.S_Counter_Mat'"), NULL, LOAD_None, NULL);
	bCollideActors = false;
}

void ACounter::BeginPlay()
{
	OriginalNum = NumToCount;
}

void ACounter::Reset()
{
	NumToCount = OriginalNum;
}

void ACounter::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	FString S = "";
	FString Num = "";
	int32 i = 0;
	if (NumToCount > 0)
	{
		if ((--NumToCount) == 0)
		{
			if ((bShowMessage && (CompleteMessage != "")) && (EventInstigator != None))
			{
				EventInstigator.ClientMessage(CompleteMessage);
			}
			TriggerEvent(Event, Other, EventInstigator);
		}
		else
		{
			if (bShowMessage && (CountMessage != ""))
			{
				switch (NumToCount)
				{
				case 1:
					Num = "one";
					break;
				case 2:
					Num = "two";
					break;
				case 3:
					Num = "three";
					break;
				case 4:
					Num = "four";
					break;
				case 5:
					Num = "five";
					break;
				case 6:
					Num = "six";
					break;
				default:
					Num = string(NumToCount);
					break;
				}
				S = CountMessage;
				if (InStr(S, "%i") >= 0)
				{
					i = InStr(S, "%i");
					S = Left(S, i) $ Num $ Mid(S, (i + 2));
				}
				if (EventInstigator != None)
				{
					EventInstigator.ClientMessage(S);
				}
			}
		}
	}
	*/
}