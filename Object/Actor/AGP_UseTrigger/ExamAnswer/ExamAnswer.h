// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AGP_UseTrigger/AGP_UseTrigger.h"
#include "ExamAnswer.generated.h"

class AMedExam;

UCLASS()
class AExamAnswer : public AAGP_UseTrigger
{
	GENERATED_BODY()
public:
	AExamAnswer();

	UPROPERTY(EditAnywhere)								AMedExam* MyExam;						//var MedExam MyExam;




	bool UsedBy(APawn* Other);
	void SetExam(AMedExam* Exam);
	void SetMark(bool Visible);
};
