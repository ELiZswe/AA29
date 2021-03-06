// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_RememberScene.generated.h"

UCLASS()
class UDir_RememberScene : public UDirection
{
	GENERATED_BODY()
public:
	UDir_RememberScene();

	UPROPERTY()						int32		SceneIndex;			//var int32 SceneIndex;
	UPROPERTY()						FName		SceneName;			//var FName SceneName;

	void DirectionStart();
	bool ProcessParams();
};
