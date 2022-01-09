// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGP_IntVar.generated.h"

class UScriptObject;
class USceneComponent;
class UBillboardComponent;

UCLASS()
class AAGP_IntVar : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AAGP_IntVar();

	UPROPERTY()			int32					_value;					//var int32 _value;
	UPROPERTY()			TArray<UScriptObject*>	_TargetList;			//var UScriptObject* _TargetList[10];
	UPROPERTY()			int32					_CurrentTargetIndex;	//var int32 _CurrentTargetIndex;

	UPROPERTY()								USceneComponent* Root;
	UPROPERTY()								UTexture2D* Texture;
	UPROPERTY()								UBillboardComponent* SpriteComponent;

	int32 GetValue();
	void SetValue(int32 Value);
	void SetTarget(UScriptObject* Target);
	void Trigger(AActor* Other, APawn* EventInstigator);

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;
	void LoadEditorIcon();
};
