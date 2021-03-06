// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/ScriptObject.h"
#include "Direction.generated.h"

class AScreenplay;

UCLASS()
class UDirection : public UScriptObject
{
	GENERATED_BODY()
public:
	UDirection();

	UPROPERTY()										AScreenplay* _ParentScreenplay;					//var Screenplay _ParentScreenplay;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
	void Start();
	void Finish();
	void SetParentScreenplay(AScreenplay* Parent);
};
