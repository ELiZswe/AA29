// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/CoolImage/CoolImage.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"

UCoolImage::UCoolImage()
{

}

void UCoolImage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i;
	InitComponent(MyController, MyOwner);
	if (Image == nullptr || NoAnims == 0)
	{
		return;
	}
	Anims.Num() = NoAnims;
	for (i = 0; i < NoAnims; i++)
	{
		ResetItem(i);
	}
	*/
}
void UCoolImage::GetPos(float Scale, float &X, float &Y)
{
	/*
	
	local float AW;
	local float AH;
	AW = ActualWidth();
	AH = ActualHeight();
	switch(Rand(2))
	{
			case 0:
				X = 0;
				Y = AH * 1.5 * FMath::FRand();
				if (Y > AH)
				{
					Y = Y - AH / 2;
				}
				break;
			case 1:
				Y = AH;
				X = AW * 1.5 * FMath::FRand();
				if (X > AW)
				{
					X = X - AW;
				}
				break;
			default:
	}
	*/
}

bool UCoolImage::DoCollisionTest(int32 i)
{
	/*
	int32 j;
	for (j = 0; j < NoAnims; j++)
	{
		if (j != i && TestCollision(i, j))
		{
			return true;
		}
	}
	*/
	return false;
}

bool UCoolImage::TestCollision(int32 i, int32 j)
{
	/*
	local float W;
	local float H;
	local float l1;
	local float l2;
	local float r1;
	local float r2;
	local float t1;
	local float t2;
	local float b1;
	local float b2;
	W = Image.MaterialUSize();
	H = Image.MaterialVSize();
	l1 = Anims[i].cX;
	t1 = Anims[i].cY;
	r1 = l1 + W * Anims[i].Scale;
	b1 = t1 + H * Anims[i].Scale;
	l2 = Anims[j].cX;
	t2 = Anims[j].cY;
	r2 = l2 + W * Anims[j].Scale;
	b2 = t2 + H * Anims[j].Scale;
	if (t1 > b2)
	{
		return false;
	}
	if (t2 > b1)
	{
		return false;
	}
	if (l1 > r2)
	{
		return false;
	}
	if (l2 > r1)
	{
		return false;
	}
	*/
	return true;
}
void UCoolImage::ResetItem(int32 i)
{
	/*
	local bool Collide;
	int32 cnt;
	Anims[i].Scale = MinScale + FMath::FRand() * MaxScale - MinScale;
	Anims[i].FadeTime = MinFadeTime + FMath::FRand() * MaxFadeTime - MinFadeTime;
	Anims[i].ResetDelay = 0;
	Anims[i].TargetAlpha = FullAlpha;
	Anims[i].Alpha = 0;
	Anims[i].TravelTime = 0.25 + 0.25 * FMath::FRand();
	Collide = true;
	if (Collide)
	{
		GetPos(Anims[i].Scale, Anims[i].cX, Anims[i].cY);
		Collide = DoCollisionTest(i);
		if (Collide)
		{
			cnt++;
			if (cnt > 20)
			{
				Anims[i].ResetDelay = 0.5;
				Anims[i].FadeTime = 0;
				Anims[i].Alpha = 0;
				Anims[i].TargetAlpha = 0;
				Collide = false;
			}
		}
	}
	*/
}
