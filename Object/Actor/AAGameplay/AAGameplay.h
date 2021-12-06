// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/AA29.h"
#include "AAGameplay.generated.h"

class UBillboardComponent;
class USceneComponent;

UCLASS()
class AA29_API AAAGameplay : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAAGameplay();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)			TArray<FTagAttachment> TagAttachments;					//var() array<TagAttachment> TagAttachments;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)			TArray<FAttachObject> Attachments;						//var() array<AttachObject> Attachments;

	UPROPERTY()											UTexture2D* Texture;
	UPROPERTY()											UStaticMeshComponent* StaticMesh;
	UPROPERTY()											USkeletalMeshComponent* SkeletalMesh;
	UPROPERTY()											UBillboardComponent* SpriteComponent;
	UPROPERTY()											USceneComponent* Root;
	UPROPERTY()                                         EDrawType DrawType;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void PostBeginPlay();
	void SetAttachments();
	void LoadEditorIcon();
	void LoadMesh();
};
