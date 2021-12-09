// All the original content belonged to the US Army


#include "AA29/Object/Actor/MedExam/MedExam.h"
#include "AA29/Object/Actor/AGP_UseTrigger/ExamAnswer/ExamAnswer.h"
#include "Components/BillboardComponent.h"

void AMedExam::LoadEditorIcon()
{

#if WITH_EDITORONLY_DATA
	bool UBillboardComponentExists = false;

	TArray<UObject*> ObjectArray;
	GetDefaultSubobjects(ObjectArray);
	for (UObject* ThisObject : ObjectArray)
	{
		if (ThisObject->GetName() == "Sprite")
		{
			if (Texture != NULL)
			{
				SpriteComponent = Cast<UBillboardComponent>(ThisObject);
				SpriteComponent->Sprite = Texture;
				UBillboardComponentExists = true;
			}
		}
	}
	if (!UBillboardComponentExists)
	{
		SpriteComponent = CreateDefaultSubobject<UBillboardComponent>(TEXT("Sprite"));
		SpriteComponent->Sprite = Texture;
		SpriteComponent->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
		SpriteComponent->SetWorldScale3D(FVector(4, 4, 4));
	}
#endif // WITH_EDITORONLY_DATA
}

void AMedExam::LoadMesh()
{
	UMaterialInstance* Mat;

	if (!StaticMesh)
	{
		StaticMesh->SetStaticMesh(LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/Misc/fx_misc_sheet.fx_misc_sheet'"), NULL, LOAD_None, NULL));
	}
	if (OverrideMaterials.Num() > 0)
	{
		for (int i = 0; i < OverrideMaterials.Num(); i++)
		{
			Mat = OverrideMaterials[i];
			StaticMesh->SetMaterial(i, Mat);
		}
	}
}

// Sets default values
AMedExam::AMedExam()
{


	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//bDebug = true;
	//bActive = true;
	//DrawType = 8;

	//DrawScale = 1.5;
	//DrawScale3D = (X = 1, Y = 1, Z = 14);
	//Skins(0) = Texture'AGP.Icons.White';

	OverrideMaterials.SetNum(1);
	OverrideMaterials[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/AGP/Icons/White_Mat.White_Mat'"), NULL, LOAD_None, NULL);

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform);
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Actor.S_Actor'"), NULL, LOAD_None, NULL);
	
	LoadEditorIcon();
	LoadMesh();

}

// Called when the game starts or when spawned
void AMedExam::BeginPlay()
{
	Super::BeginPlay();
	LoadMesh();
}

// Called every frame
void AMedExam::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void AMedExam::SetActive(bool Active)
{
	bActive = Active;
}
void AMedExam::LockPageTurning()
{
	bLockPageTurning = true;
}
void AMedExam::UnlockPageTurning()
{
	bLockPageTurning = false;
}
void AMedExam::HideExam()
{
	//bHidden = true;
	DestroyPage(CurrentPage);
}
void AMedExam::ShowExam()
{
	//bHidden = False;
	CreatePage(CurrentPage);
}
void AMedExam::SetPage(int32 page)
{
	//if (page < 0 || page >= TestPages.Num() || bHidden)    //Origional 
	if (page < 0 || page >= TestPages.Num())
	{
		return;
	}
	DestroyPage(CurrentPage);
	CurrentPage = page;
	CreatePage(CurrentPage);
}
void AMedExam::Destroyed()
{
	int32 i;
	int32 j;
	for (i = 0; i < TestPages.Num(); i++)
	{
		if (TestPages[i].PageNext.Answer != nullptr)
		{
			TestPages[i].PageNext.Answer->Destroy();
			TestPages[i].PageNext.Answer = nullptr;
		}
		if (TestPages[i].PagePrev.Answer != nullptr)
		{
			TestPages[i].PagePrev.Answer->Destroy();
			TestPages[i].PagePrev.Answer = nullptr;
		}
		for (j = 0; j < TestPages[i].TestAnswers.Num(); j++)
		{
			if (TestPages[i].TestAnswers[j].Answer != nullptr)
			{
				TestPages[i].TestAnswers[j].Answer->Destroy();
				TestPages[i].TestAnswers[j].Answer->Destroy();
			}
		}
	}
}
void AMedExam::PreBeginPlay()
{
	int32 i;
	int32 j;
	AActor* LT = nullptr;
	for (i = 0; i < TestPages.Num(); i++)
	{
		//LT = GetActorByTag(TestPages[i].PagePrev.LookTargetName);
		if (LT != nullptr)
		{
			//TestPages[i].PagePrev.HotSpotX = LT.Location.X - Location.X;
			//TestPages[i].PagePrev.HotSpotY = LT.Location.Y - Location.Y;
			//Log("MedExam::PreBeginPlay(): Processed " $ TestPages[i].PagePrev.LookTargetName);
		}
		else
		{
			//Log("MedExam::PreBeginPlay(): Error: Target actor with tag: " $ TestPages[i].PagePrev.LookTargetName $ " not found");
		}
		//LT = GetActorByTag(TestPages[i].PageNext.LookTargetName);
		if (LT != nullptr)
		{
			//TestPages[i].PageNext.HotSpotX = LT.Location.X - Location.X;
			//TestPages[i].PageNext.HotSpotY = LT.Location.Y - Location.Y;
			//Log("MedExam::PreBeginPlay(): Processed " $ TestPages[i].PageNext.LookTargetName);
		}
		else
		{
			//Log("MedExam::PreBeginPlay(): Error: Target actor with tag: " $ TestPages[i].PageNext.LookTargetName $ " not found");
		}
		for (j = 0; j < TestPages[i].TestAnswers.Num(); j++)
		{
			if (TestPages[i].TestAnswers[j].LookTargetName != "None")
			{
				//LT = GetActorByTag(TestPages[i].TestAnswers[j].LookTargetName);
				if (LT != nullptr)
				{
					//TestPages[i].TestAnswers[j].HotSpotX = LT.Location.X - Location.X;
					//TestPages[i].TestAnswers[j].HotSpotY = LT.Location.Y - Location.Y;
					LT->Destroy();
					//Log("MedExam::PreBeginPlay(): Processed " $ TestPages[i].TestAnswers[j].LookTargetName);
				}
				else
				{
					//Log("MedExam::PreBeginPlay(): Error: Target actor with tag: " $ TestPages[i].TestAnswers[j].LookTargetName $ " not found");
				}
			}
		}
	}
	if (TestPages.Num() != 0)
	{
		CurrentPage = 0;
		CreatePage(CurrentPage);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("MedExam::PreBeginPlay(): ERROR: No Pages Exist!!!"));
		return;
	}
}
void AMedExam::ScrollPages(bool Up)
{
	TurnPage(Up);
}
void AMedExam::TurnPage(bool Up)
{
	//if (!bActive || bLockPageTurning || bHidden)    /Origional
	if (!bActive || bLockPageTurning)
	{
		return;
	}
	if (Up)
	{
		if (CurrentPage == TestPages.Num() - 1)
		{
			return;
		}
		DestroyPage(CurrentPage);
		CurrentPage++;
		CreatePage(CurrentPage);
	}
	else
	{
		if (CurrentPage == 0)
		{
			return;
		}
		DestroyPage(CurrentPage);
		CurrentPage--;
		CreatePage(CurrentPage);
	}
}
float AMedExam::ScoreTest()
{
	int32 i;
	int32 j;
	float NumCorrect=0;
	float NumTotal=0;
	bool bMarkedCorrect;
	bool bCorrectAnswer;
	NumTotal = NumberOfQuestions;
	for (i = 0; i < TestPages.Num(); i++)
	{
		for (j = 0; j < TestPages[i].TestAnswers.Num(); j++)
		{
			bMarkedCorrect = TestPages[i].TestAnswers[j].bMarkedCorrect;
			bCorrectAnswer = TestPages[i].TestAnswers[j].bCorrectAnswer;
			if (bCorrectAnswer && bMarkedCorrect)
			{
				NumCorrect += 1;
			}
		}
	}
	return NumCorrect / NumTotal;
}
void AMedExam::ResetTest()
{
	int32 i;
	int32 j;
	for (i = 0; i < TestPages.Num(); i++)
	{
		for (j = 0; j < TestPages[i].TestAnswers.Num(); j++)
		{
			TestPages[i].TestAnswers[j].bMarkedCorrect = false;
			TestPages[i].TestAnswers[j].Answer->SetMark(false);
		}
	}
}
void AMedExam::Report(AExamAnswer* Answer)
{
	int32 i;
	if (!bActive)
	{
		return;
	}
	for (i = 0; i < TestPages.Num(); i++)
	{
		if (Answer == TestPages[i].PageNext.Answer)
		{
			DestroyPage(CurrentPage);
			CurrentPage++;
			CreatePage(CurrentPage);
			return;
		}
		else
		{
			if (Answer == TestPages[i].PagePrev.Answer)
			{
				DestroyPage(CurrentPage);
				CurrentPage--;
				CreatePage(CurrentPage);
				return;
			}
		}
	}
	MarkAnswer(Answer);
}
void AMedExam::MarkAnswer(AExamAnswer* Answer)
{
	int32 i;
	FName G;
	FName SG;
	AExamAnswer* SA = nullptr;
	i = 0;
	if (i < TestPages[CurrentPage].TestAnswers.Num())
	{
		SA = TestPages[CurrentPage].TestAnswers[i].Answer;
		if (SA == Answer)
		{
			G = TestPages[CurrentPage].TestAnswers[i].QuestionName;
			TestPages[CurrentPage].TestAnswers[i].bMarkedCorrect = true;
			TestPages[CurrentPage].TestAnswers[i].Answer->SetMark(true);
		}
		else
		{
			i++;
		}
	}
	for (i = 0; i < TestPages[CurrentPage].TestAnswers.Num(); i++)
	{
		SG = TestPages[CurrentPage].TestAnswers[i].QuestionName;
		if (SG == G && SA != TestPages[CurrentPage].TestAnswers[i].Answer)
		{
			TestPages[CurrentPage].TestAnswers[i].bMarkedCorrect = false;
			TestPages[CurrentPage].TestAnswers[i].Answer->SetMark(false);
		}
	}
	if (bDebug)
	{
		//Log("Grade: " @ ScoreTest() * 100 $ " Percent");
	}
	return;
}
void AMedExam::CreatePage(int32 PageIndex)
{
	/*
	local int i;
	local ExamAnswer A;
	local FVector NewPosition;
	if (PageIndex < 0 || PageIndex >= TestPages.Length || bHidden)
	{
		Return;
	}
	Skins[0] = TestPages[PageIndex].PageTexture;
	if (PageIndex != 0)
	{
		A = Spawn('ExamAnswer');
		NewPosition = A.Location;
		NewPosition.X += TestPages[PageIndex].PagePrev.HotSpotX;
		NewPosition.Y += TestPages[PageIndex].PagePrev.HotSpotY;
		NewPosition.Z += TestPages[PageIndex].PagePrev.HotSpotZ;
		A.HUDText = TestPages[PageIndex].PagePrev.HotSpotText;
		A.SetExam(Self);
		A.SetLocation(NewPosition);
		A.SetCollisionSize(TestPages[PageIndex].PagePrev.HotSpotRadius, TestPages[PageIndex].PagePrev.HotSpotRadius);
		if (bDebug)
		{
			A.bHidden = False;
			A.SetDrawScale(2);
		}
		TestPages[PageIndex].PagePrev.Answer = A;
	}
	if (PageIndex < TestPages.Length - 1 && TestPages.Length > 1)
	{
		A = Spawn('ExamAnswer');
		NewPosition = A.Location;
		NewPosition.X += TestPages[PageIndex].PageNext.HotSpotX;
		NewPosition.Y += TestPages[PageIndex].PageNext.HotSpotY;
		NewPosition.Z += TestPages[PageIndex].PageNext.HotSpotZ;
		A.HUDText = TestPages[PageIndex].PageNext.HotSpotText;
		A.SetExam(Self);
		A.SetLocation(NewPosition);
		A.SetCollisionSize(TestPages[PageIndex].PageNext.HotSpotRadius, TestPages[PageIndex].PageNext.HotSpotRadius);
		if (bDebug)
		{
			A.bHidden = false;
			A.SetDrawScale(2);
		}
		TestPages[PageIndex].PageNext.Answer = A;
	}
	for (i = 0; i < TestPages[PageIndex].TestAnswers.Length; i++)
	{
		A = Spawn('ExamAnswer');
		NewPosition = A.Location;
		NewPosition.X += TestPages[PageIndex].TestAnswers[i].HotSpotX;
		NewPosition.Y += TestPages[PageIndex].TestAnswers[i].HotSpotY;
		NewPosition.Z += TestPages[PageIndex].TestAnswers[i].HotSpotZ;
		A.HUDText = TestPages[PageIndex].TestAnswers[i].HotSpotText;
		A.SetExam(this);
		A.SetLocation(NewPosition);
		A.SetCollisionSize(TestPages[PageIndex].TestAnswers[i].HotSpotRadius, TestPages[PageIndex].TestAnswers[i].HotSpotRadius + 0.25);
		A.SetMark(TestPages[PageIndex].TestAnswers[i].bMarkedCorrect);
		if (bDebug)
		{
			A.bHidden = false;
		}
		TestPages[PageIndex].TestAnswers[i].Answer = A;
	}
	*/
}
void AMedExam::DestroyPage(int32 PageIndex)
{
	int32 i;
	if (PageIndex < 0 || PageIndex >= TestPages.Num())
	{
		return;
	}
	if (TestPages[PageIndex].PagePrev.Answer != nullptr)
	{
		TestPages[PageIndex].PagePrev.Answer->Destroy();
		TestPages[PageIndex].PagePrev.Answer = nullptr;
	}
	if (TestPages[PageIndex].PageNext.Answer != nullptr)
	{
		TestPages[PageIndex].PageNext.Answer->Destroy();
		TestPages[PageIndex].PageNext.Answer = nullptr;
	}
	for (i = 0; i < TestPages[PageIndex].TestAnswers.Num(); i++)
	{
		TestPages[PageIndex].TestAnswers[i].Answer->Destroy();
		TestPages[PageIndex].TestAnswers[i].Answer = nullptr;
	}
}
void AMedExam::Trigger(AActor* Other, APawn* EventInstigator)
{
	TurnPage(false);
}
void AMedExam::UnTrigger(AActor* Other, APawn* EventInstigator)
{
	TurnPage(true);
}
