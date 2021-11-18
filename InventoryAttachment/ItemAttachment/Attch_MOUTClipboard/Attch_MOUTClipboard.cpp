// All the original content belonged to the US Army


#include "Attch_MOUTClipboard.h"

AAttch_MOUTClipboard::AAttch_MOUTClipboard()
{
	AttachBone  = "LHandObject";
	StaticMesh  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/ClipboardShoothouse.ClipboardShoothouse"), NULL, LOAD_None, NULL);
	DrawScale   = 0.5;
}