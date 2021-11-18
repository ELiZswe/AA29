// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UITextButton/UITextButton.h"
#include "UIWebLink.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIWebLink : public UUITextButton
{
	GENERATED_BODY()
public:
	UUIWebLink();

	void Draw(UCanvas* Canvas);
};
