// All the original content belonged to the US Army


#include "ScopeW_BST.h"
AScopeW_BST::AScopeW_BST()
{
	VisualFadeInTime    = 0.5;
	VisualFadeOverlay   = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_goal_fill.hud_goal_fill"), NULL, LOAD_None, NULL);
}
