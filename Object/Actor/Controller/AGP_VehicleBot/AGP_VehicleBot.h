// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Controller.h"
#include "AGP_VehicleBot.generated.h"

class AAGP_VehicleNode;

UCLASS()
class AAGP_VehicleBot : public AController
{
	GENERATED_BODY()
public:
	AAGP_VehicleBot();

	UPROPERTY()										AAGP_VehicleNode* CurIntermediate;						//var AGP_VehicleNode CurIntermediate;
	UPROPERTY()										AAGP_VehicleNode* CurDestination;						//var AGP_VehicleNode CurDestination;
	
	//From Controller
	UPROPERTY()										bool bAdvancedTactics;						//var AGP_VehicleNode CurDestination;


	void SetCurrentNode(AAGP_VehicleNode* newNode);
	void SetDestination(AAGP_VehicleNode* newNode);
	void Trigger(AActor* Other, APawn* EventInstigator);


};
