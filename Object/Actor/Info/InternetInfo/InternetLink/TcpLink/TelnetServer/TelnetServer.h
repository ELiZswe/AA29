// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/TcpLink.h"
#include "TelnetServer.generated.h"

UCLASS()
class ATelnetServer : public ATcpLink
{
	GENERATED_BODY()
public:
	ATelnetServer();
};
