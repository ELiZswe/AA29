// All the original content belonged to the US Army


#include "ScopeW_BST.h"
AScopeW_BST::AScopeW_BST()
{
	VisualFadeInTime    = 0.5;
	VisualFadeOverlay   = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_goal_fill_Mat.hud_goal_fill_Mat'"), NULL, LOAD_None, NULL);
}
