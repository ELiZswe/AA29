// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/Bot/Bot.h"
#include "AGP_Bot.generated.h"

class ANavigationPoint;
class UAI_Thought;
class APatrol;

UCLASS()
class AA29_API AAGP_Bot : public ABot
{
	GENERATED_BODY()
public:
	AAGP_Bot();

	UPROPERTY()										FName NextState;							//var name NextState;
	UPROPERTY()										bool bDumb;									//var bool bDumb;
	UPROPERTY()										UAI_Thought* NextThought;					//var AI_Thought NextThought;
	UPROPERTY()										ANavigationPoint* NextPath;					//var NavigationPoint NextPath;
	UPROPERTY()										ANavigationPoint* DestinationNode;			//var NavigationPoint DestinationNode;
	UPROPERTY()										APatrol* PatrolPath;						//var Patrol PatrolPath;

	void Arrived(AActor* Destination);
	void BeginState();
	void PostBeginPlay();
	void Think();
	void AddThought(UAI_Thought* Thought);
	void PauseState(float Time, FName NewState, FName aNextState);
	void ResumeState();
	void NotifyJumpApex();
};
