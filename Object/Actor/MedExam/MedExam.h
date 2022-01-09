// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/AA29.h"
#include "MedExam.generated.h"

class AExamAnswer;
class UBillboardComponent;
class USceneComponent;

UCLASS()
class AMedExam : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AMedExam();

	UPROPERTY()										UTexture2D* Texture;
	UPROPERTY()										USceneComponent* Root;
	UPROPERTY()										UBillboardComponent* SpriteComponent;
	UPROPERTY(EditAnywhere)							UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditAnywhere)							TArray<UMaterialInstance*> OverrideMaterials;

	UPROPERTY()										int32 CurrentPage;									//var int CurrentPage;
	UPROPERTY(EditAnywhere)							bool bLockPageTurning;								//var() bool bLockPageTurning;
	UPROPERTY(EditAnywhere)							bool bActive;										//var() bool bActive;
	UPROPERTY(EditAnywhere)							bool bDebug;										//var() bool bDebug;
	UPROPERTY(EditAnywhere)							int32 NumberOfQuestions;							//var() int NumberOfQuestions;
	UPROPERTY(EditAnywhere)							TArray<FTestPage> TestPages;						//var() array<TestPage> TestPages

protected:
	
	virtual void BeginPlay() override;
	void LoadMesh();

public:	
	
	virtual void Tick(float DeltaTime) override;
	void LoadEditorIcon();


	void SetActive(bool Active);
	void LockPageTurning();
	void UnlockPageTurning();
	void HideExam();
	void ShowExam();
	void SetPage(int32 page);
	void Destroyed();
	void PreBeginPlay();
	void ScrollPages(bool Up);
	void TurnPage(bool Up);
	float ScoreTest();
	void ResetTest();
	void Report(AExamAnswer* Answer);
	void MarkAnswer(AExamAnswer* Answer);
	void CreatePage(int32 PageIndex);
	void DestroyPage(int32 PageIndex);
	void Trigger(AActor* Other, APawn* EventInstigator);
	void UnTrigger(AActor* Other, APawn* EventInstigator);



};
