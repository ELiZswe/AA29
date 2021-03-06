// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/CoolImage/CoolImage.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"

UCoolImage::UCoolImage()
{

}

void UCoolImage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	int32 i = 0;
	Super::InitComponent(MyController, MyOwner);
	if (Image == nullptr || NoAnims == 0)
	{
		return;
	}
	Anims.SetNum(NoAnims);
	for (i = 0; i < NoAnims; i++)
	{
		ResetItem(i);
	}
}

void UCoolImage::GetPos(float Scale, float &X, float &Y)
{
	float AW = 0;
	float AH = 0;
	AW = ActualWidth(0,false);
	AH = ActualHeight(0,false);
	switch(FMath::Rand() %2)
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
			break;
	}
}

bool UCoolImage::DoCollisionTest(int32 i)
{
	int32 j = 0;
	for (j = 0; j < NoAnims; j++)
	{
		if (j != i && TestCollision(i, j))
		{
			return true;
		}
	}
	return false;
}

bool UCoolImage::TestCollision(int32 i, int32 j)
{
	float W = 0;
	float H = 0;
	float l1 = 0;
	float l2 = 0;
	float r1 = 0;
	float r2 = 0;
	float t1 = 0;
	float t2 = 0;
	float b1 = 0;
	float b2 = 0;
	/*
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
	*/
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
	return true;
}

void UCoolImage::ResetItem(int32 i)
{
	bool Collide = false;
	int32 cnt = 0;
	Anims[i].Scale = MinScale + FMath::FRand() * MaxScale - MinScale;
	Anims[i].FadeTime = MinFadeTime + FMath::FRand() * MaxFadeTime - MinFadeTime;
	Anims[i].ResetDelay = 0;
	Anims[i].TargetAlpha = FullAlpha;
	Anims[i].Alpha = 0;
	Anims[i].TravelTime = 0.25 + 0.25 * FMath::FRand();
	Collide = true;
	while (Collide)
	{
		GetPos(Anims[i].Scale, Anims[i].cX, Anims[i].cY);
		Collide = DoCollisionTest(i);
		if (Collide)
		{
			cnt++;
			if (cnt > 20)	// Setup for a reset in 1/2 a sec
			{
				Anims[i].ResetDelay = 0.5;
				Anims[i].FadeTime = 0;
				Anims[i].Alpha = 0;
				Anims[i].TargetAlpha = 0;
				Collide = false;
			}
		}
	}
}
