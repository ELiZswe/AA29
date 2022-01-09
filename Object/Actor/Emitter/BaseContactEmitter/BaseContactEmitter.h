// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/AA2_Emitter.h"
#include "BaseContactEmitter.generated.h"

UCLASS()
class ABaseContactEmitter : public AAA2_Emitter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)													USceneComponent* Root;
	UPROPERTY()																UTexture2D* Texture;

public:	
	
	ABaseContactEmitter();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;
	void LoadEditorIcon();
};
