// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGP_IntVar.generated.h"

class UScriptObject;

UCLASS()
class AA29_API AAGP_IntVar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAGP_IntVar();


	UPROPERTY()								int32 _iPosition;										//var int _CurrentTargetIndex;
	UPROPERTY()								UScriptObject* _CurrentTargetIndex;						//var ScriptObject _TargetList;
	UPROPERTY()								int32 _value;											//var int _value;

	UPROPERTY()								USceneComponent* Root;
	UPROPERTY()								UTexture2D* Texture;
	UPROPERTY()								UBillboardComponent* SpriteComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void LoadEditorIcon();
};
