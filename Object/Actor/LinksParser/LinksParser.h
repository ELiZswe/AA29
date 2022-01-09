// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LinksParser.generated.h"

UCLASS()
class ALinksParser : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ALinksParser();

	UPROPERTY()											TArray<FSection> Sections;							//var array<Section> Sections;

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;



	void Init(FString FilePath);
	void GetHeaders(FString FilePath);
	void GetSections(FString FilePath);
	int32 GetHeaderIndex(FString Header);
	int32 GetIDIndex(FString Id);



};
