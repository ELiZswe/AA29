// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/MasterServerLink/MasterServerLink.h"

AMasterServerLink::AMasterServerLink()
{
	LANPort = 11777;
	LANServerPort = 10777;
	MasterServerList = {
								{ "ut2004master1.epicgames.com", 28902 },
								{ "ut2004master1.epicgames.com", 28902 }
	};
	//bAlwaysTick = true;
}

//native Function Poll(int32 WaitTime);
bool AMasterServerLink::Poll(int32 WaitTime)
{
	return false;   //FAKE   /EliZ
}

void AMasterServerLink::GetMasterServer(FString &OutAddress, int32 &OutPort)
{
	int32 Index = 0;
	if (ActiveMasterServerList.Max() == 0)
	{
		for (Index = 0; Index < MasterServerList.Max(); Index++)
		{
			ActiveMasterServerList.Add(MasterServerList[Index]);
		}
	}
	Index = FMath::RandRange(0,ActiveMasterServerList.Max());
	LastMSIndex = Index;
	OutAddress = ActiveMasterServerList[Index].Address;
	OutPort = ActiveMasterServerList[Index].Port;
}
void AMasterServerLink::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Poll(0);
}
