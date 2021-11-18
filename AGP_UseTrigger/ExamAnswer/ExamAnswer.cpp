// All the original content belonged to the US Army


#include "AA29/AGP_UseTrigger/ExamAnswer/ExamAnswer.h"
#include "AA29/MedExam/MedExam.h"

AExamAnswer::AExamAnswer()
{
	//DrawType = 8;
	//DrawScale3D = (X = 7, Y = 4, Z = 7);
	//Skins(0) = Texture'T_AA2_FX.MedicTraining.PencilMark';

}



bool AExamAnswer::UsedBy(APawn* Other)
{
	if (bActive)
	{
		if (MyExam != nullptr)
		{
			MyExam->Report(this);
			return true;
		}
	}
	return false;
}
void AExamAnswer::SetExam(AMedExam* Exam)
{
	MyExam = Exam;
}
void AExamAnswer::SetMark(bool Visible)
{
	if (Visible)
	{
		//bHidden = false;
	}
	else
	{
		//bHidden = true;
	}
}