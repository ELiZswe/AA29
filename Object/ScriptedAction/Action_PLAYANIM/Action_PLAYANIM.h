// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_PLAYANIM.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAction_PLAYANIM : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_PLAYANIM();

	UPROPERTY(EditAnywhere, Category = "Action")		float StartFrame;						//var(Action) float StartFrame;
	UPROPERTY(EditAnywhere, Category = "Action")		bool bLoopAnim;							//var(Action) bool bLoopAnim;
	UPROPERTY(EditAnywhere, Category = "Action")		uint8 AnimIterations;					//var(Action) byte AnimIterations;
	UPROPERTY(EditAnywhere, Category = "Action")		float AnimRate;							//var(Action) float AnimRate;
	UPROPERTY(EditAnywhere, Category = "Action")		float BlendOutTime;						//var(Action) float BlendOutTime;
	UPROPERTY(EditAnywhere, Category = "Action")		float BlendInTime;						//var(Action) float BlendInTime;
	UPROPERTY(EditAnywhere, Category = "Action")		FName BaseAnim;							//var(Action) name BaseAnim;



	bool InitActionFor(UScriptedController* C);
	void SetCurrentAnimationFor(UScriptedController* C);
	bool PawnPlayBaseAnim(UScriptedController* C, bool bFirstPlay);
	FString GetActionString();
};
