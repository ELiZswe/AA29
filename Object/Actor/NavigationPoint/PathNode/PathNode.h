// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "PathNode.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API APathNode : public ANavigationPoint
{
	GENERATED_BODY()
public:
	APathNode();

	UPROPERTY(EditAnywhere)													ENodeType NodeType;									//var() ENodeType NodeType;
	UPROPERTY(EditAnywhere)													bool Sprint;										//var() bool Sprint;
	UPROPERTY()																int32 CoverTaken;										//var int CoverTaken;
	UPROPERTY()																AController* cControllerUsingNode;								//var Controller cControllerUsingNode;


};
