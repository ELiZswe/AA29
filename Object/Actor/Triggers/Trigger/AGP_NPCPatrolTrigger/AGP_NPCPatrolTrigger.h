// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"
#include "AGP_NPCPatrolTrigger.generated.h"

UCLASS()
class AAGP_NPCPatrolTrigger : public ATrigger
{
	GENERATED_BODY()
public:
	AAGP_NPCPatrolTrigger();

	UPROPERTY(EditAnywhere, Category = "NPCPatrolTrigger")			EReserveCommand	ercReserveCommand;		//var(NPCPatrolTrigger) Enum EReserveCommand ercReserveCommand;
	UPROPERTY(EditAnywhere, Category = "NPCPatrolTrigger")			EPatrolCommand	epcPatrolCommand;		//var(NPCPatrolTrigger) Enum EPatrolCommand epcPatrolCommand;
	UPROPERTY(EditAnywhere, Category = "NPCPatrolTrigger")			FName			npcTag;					//var(NPCPatrolTrigger) FName npcTag;
	UPROPERTY(EditAnywhere, Category = "NPCPatrolTrigger")			int32			iReservePlatoonID;		//var(NPCPatrolTrigger) int32 iReservePlatoonID;
	UPROPERTY(EditAnywhere, Category = "NPCPatrolTrigger")			int32			iReserveSquadID;		//var(NPCPatrolTrigger) int32 iReserveSquadID;
	UPROPERTY(EditAnywhere, Category = "NPCPatrolTrigger")			int32			iReserveFireteamID;		//var(NPCPatrolTrigger) int32 iReserveFireteamID;

	void DoTouch(AActor* Other);
};
