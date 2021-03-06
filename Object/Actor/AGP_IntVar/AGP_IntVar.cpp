// All the original content belonged to the US Army

#include "AA29/Object/Actor/AGP_IntVar/AGP_IntVar.h"
#include "Components/BillboardComponent.h"
#include "AA29/Object/ScriptObject/ScriptObject.h"

void AAGP_IntVar::LoadEditorIcon()
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

// Sets default values
AAGP_IntVar::AAGP_IntVar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//bHidden = true;
	_TargetList.SetNum(10);

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Actor.S_Actor'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();

}


void AAGP_IntVar::BeginPlay()
{
	Super::BeginPlay();
	
}


void AAGP_IntVar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 AAGP_IntVar::GetValue()
{
	return _value;
}

void AAGP_IntVar::SetValue(int32 Value)
{
	int32 Index = 0;
	_value = Value;
	for (Index = 0; Index < _CurrentTargetIndex; Index++)
	{
		/*
		if (_Target != nullptr)
		{
			_Target.update();
		}
		*/
	}
}

void AAGP_IntVar::SetTarget(UScriptObject* Target)
{
	if (_CurrentTargetIndex < 10)
	{
		_TargetList[_CurrentTargetIndex] = Target;
		_CurrentTargetIndex++;
	}
	else
	{
		//Log("AGP_IntVar::SetTarget has exceeded max number of targets.");
	}
}

void AAGP_IntVar::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	Super::Trigger(Other, EventInstigator);
	_value++;
	TriggerEvent(Event, Other, EventInstigator);
	*/
}
