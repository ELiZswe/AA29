// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIBitmap/UIBitmap.h"
#include "UIBitmapB.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIBitmapB : public UUIBitmap
{
	GENERATED_BODY()
public:
	UUIBitmapB();
	
	UPROPERTY()										FPosition _iTexDim;							//var UIBase.Position _iTexDim;

	void Draw(UCanvas* Canvas);
	void SetTextureDimensions(FPosition dim);
};
