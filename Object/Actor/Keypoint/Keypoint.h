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
class AA29_API AKeypoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKeypoint(const FObjectInitializer& objectInitializer);


	//UPROPERTY(EditAnywhere, BlueprintReadWrite)		UStaticMeshComponent* StaticMesh;
	UPROPERTY()										USceneComponent* KeyPointRoot;
	UPROPERTY()										UBillboardComponent* SpriteComponent;
	UPROPERTY()										UTexture2D* Texture;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void LoadEditorIcon();

	//from Actor:
	void SetTarget(UScriptObject* Target);

};
