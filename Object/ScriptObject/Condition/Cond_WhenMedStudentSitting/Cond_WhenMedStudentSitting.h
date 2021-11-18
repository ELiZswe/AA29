// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Condition/Condition.h"
#include "Cond_WhenMedStudentSitting.generated.h"

//class AStudentController;

UCLASS()
class AA29_API UCond_WhenMedStudentSitting : public UCondition
{
	GENERATED_BODY()
public:
	UCond_WhenMedStudentSitting();

	UPROPERTY()										bool bSitting;					//var bool bSitting;
	//UPROPERTY()										AStudentController* Controller;					//var AGP.StudentController Controller;
};
