// All the original content belonged to the US Army

#include "AA29/Object/CameraEffect/MotionBlur/MotionBlur.h"

UMotionBlur::UMotionBlur()
{
	RenderTargets.SetNum(2);
	BlurAlpha = 128;
}
