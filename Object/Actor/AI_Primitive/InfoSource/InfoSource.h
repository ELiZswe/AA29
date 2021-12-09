// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/AI_Primitive.h"
#include "InfoSource.generated.h"

class AMentalModel;

UCLASS()
class AA29_API AInfoSource : public AAI_Primitive
{
	GENERATED_BODY()
public:
	AInfoSource();
	UPROPERTY()														AMentalModel* _mm;								//var MentalModel _mm;

	void setMentalModel(AMentalModel* pmm);
	void see(AActor* Seen, APawn* me);
	void HEAR(AActor* heard, APawn* me, float Loudness, bool surprised);
	void comm(AActor* told, APawn* me);
};
