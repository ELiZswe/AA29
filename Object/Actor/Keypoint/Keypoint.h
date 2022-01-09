// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/MyEnums.h"
#include "AA29/AA29.h"
#include "Keypoint.generated.h"

class UScriptObject;
class USceneComponent;
class UBillboardComponent;

UCLASS()
class AKeypoint : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AKeypoint(const FObjectInitializer& objectInitializer);

	UPROPERTY()										USceneComponent* KeyPointRoot;
	UPROPERTY()										UBillboardComponent* SpriteComponent;
	UPROPERTY()										UTexture2D* Texture;

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;
	void LoadEditorIcon();

	//from Actor:
	void SetTarget(UScriptObject* Target);

};
