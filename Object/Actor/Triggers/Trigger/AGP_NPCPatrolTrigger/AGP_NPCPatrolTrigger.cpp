// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/Trigger/AGP_NPCPatrolTrigger/AGP_NPCPatrolTrigger.h"
#include "AA29/Object/Actor/NPCAICombatController/NPCAICombatController.h"

AAGP_NPCPatrolTrigger::AAGP_NPCPatrolTrigger()
{
	CollisionRadius = 20;
	CollisionHeight = 20;
	bUseCylinderCollision = true;
}

void DoTouch(AActor* Other)
{
	AController* cIterator = nullptr;
	ANPCAICombatController* npcaiccIterator = nullptr;
	int32 i = 0;
	/*
	Other = FindInstigator(Other);
	if (ReTriggerDelay > 0)
	{
		if ((Level.TimeSeconds - TriggerTime) < ReTriggerDelay)
		{
			return;
		}
		TriggerTime = Level.TimeSeconds;
	}
	TriggerEvent(Event, Self, Other.Instigator);
	if ((Pawn(Other) != nullptr) && (Pawn(Other).Controller != nullptr))
	{
		i = 0;
		if (i < 4)
		{
			if (Pawn(Other).Controller.GoalList[i] == Self)
			{
				Pawn(Other).Controller.GoalList[i] = nullptr;
			}
			else
			{
				i++;
			}
		}
	}
	if ((Message != "") && (Other.Instigator != nullptr))
	{
		Other.Instigator.ClientMessage(Message);
	}
	if (bTriggerOnceOnly)
	{
		SetCollision(false);
	}
	else
	{
		if (RepeatTriggerTime > 0)
		{
			SetTimer(RepeatTriggerTime, false);
		}
	}
	if (epcPatrolCommand == 5)
	{
		ForEach AllActors(Class'AGP.NPCAICombatController', npcaiccIterator)
		{
			if (!npcaiccIterator.bDisableCombatController)
			{
				switch (ercReserveCommand)
				{
				case 0:
					npcaiccIterator.SpawnTriggeredReinforcements(iReservePlatoonID, iReserveSquadID, iReserveFireteamID, "FollowOrders", Location);
					break;
				case 1:
					npcaiccIterator.SpawnTriggeredReinforcements(iReservePlatoonID, iReserveSquadID, iReserveFireteamID, "GotoTrigger", Location);
					break;
				case 2:
					npcaiccIterator.SpawnTriggeredReinforcements(iReservePlatoonID, iReserveSquadID, iReserveFireteamID, "GotoObjective", Location);
					break;
				default:
				}
			}
		}
		return;
	}
	for (cIterator = Level.ControllerList; cIterator != nullptr; cIterator = cIterator.nextController)
	{
		if (cIterator.IsA("NPCBaseController"))
		{
			if ((cIterator.Tag == "None") || (npcTag == cIterator.Tag))
			{
				switch (epcPatrolCommand)
				{
				case 0:
					NPCBaseController(cIterator).PatrolResumeTriggerEvent();
					break;
				case 1:
					NPCBaseController(cIterator).PatrolStartTriggerEvent();
					break;
				case 2:
					NPCBaseController(cIterator).FallBackTriggerEvent();
					break;
				case 3:
					NPCBaseController(cIterator).DefendAreaTriggerEvent(Location);
					break;
				case 4:
					NPCBaseController(cIterator).Focus = Other;
					break;
				default:
					break;
				}
			}
		}
	}
	*/
}