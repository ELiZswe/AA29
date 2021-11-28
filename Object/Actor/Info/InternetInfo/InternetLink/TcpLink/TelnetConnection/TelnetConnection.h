// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/TcpLink.h"
#include "TelnetConnection.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ATelnetConnection : public ATcpLink
{
	GENERATED_BODY()
public:
	ATelnetConnection();
};
