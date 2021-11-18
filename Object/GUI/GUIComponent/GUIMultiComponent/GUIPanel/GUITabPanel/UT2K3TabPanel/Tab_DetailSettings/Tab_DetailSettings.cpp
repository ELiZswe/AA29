// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_DetailSettings/Tab_DetailSettings.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UTab_DetailSettings::UTab_DetailSettings()
{
	UmoComboBox* DetailWorldDetail = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DetailWorldDetail->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailWorldDetail->Caption = "Texture Detail";
	//DetailWorldDetail->OnCreateComponent=DetailWorldDetail.InternalOnCreateComponent;
	DetailWorldDetail->IniOption = "ini:Engine.Engine.ViewportManager TextureDetailWorld";
	DetailWorldDetail->IniDefault = "High";
	DetailWorldDetail->Hint = "Changes how much world detail will be rendered.";
	DetailWorldDetail->WinTop = 0.1;
	DetailWorldDetail->WinLeft = 0.05;
	DetailWorldDetail->WinWidth = 0.4;
	DetailWorldDetail->WinHeight = 0.05;
	//DetailWorldDetail->OnLoadINI=Tab_DetailSettings.InternalOnLoadINI;
	//DetailWorldDetail->OnSaveINI=Tab_DetailSettings.InternalOnSaveINI;
	UmoCheckBox* DetailBlob = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	DetailBlob->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailBlob->CaptionWidth = 0.9;
	DetailBlob->Caption = "Use Blob Shadows";
	//DetailBlob->OnCreateComponent=DetailBlob.InternalOnCreateComponent;
	DetailBlob->IniOption = "@Internal";
	DetailBlob->IniDefault = "False";
	DetailBlob->Hint = "Enable blob shadows.  Recommended for low-performance PCs.";
	DetailBlob->WinTop = 0.75;
	DetailBlob->WinLeft = 0.59875;
	DetailBlob->WinWidth = 0.3;
	DetailBlob->WinHeight = 0.04;
	//DetailBlob->OnLoadINI=Tab_DetailSettings.InternalOnLoadINI;
	UmoCheckBox* DetailTrilinear = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	DetailTrilinear->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailTrilinear->CaptionWidth = 0.9;
	DetailTrilinear->Caption = "Trilinear Filtering";
	//DetailTrilinear->OnCreateComponent=DetailTrilinear.InternalOnCreateComponent;
	DetailTrilinear->IniOption = "ini:Engine.Engine.RenderDevice UseTrilinear";
	DetailTrilinear->IniDefault = "False";
	DetailTrilinear->Hint = "Enable trilinear filtering, recommended for high-performance PCs.";
	DetailTrilinear->WinTop = 0.75;
	DetailTrilinear->WinLeft = 0.1;
	DetailTrilinear->WinWidth = 0.3;
	DetailTrilinear->WinHeight = 0.04;
	//DetailTrilinear->OnLoadINI=Tab_DetailSettings.InternalOnLoadINI;
	//DetailTrilinear->OnSaveINI=Tab_DetailSettings.InternalOnSaveINI;
	UmoCheckBox* DetailDecoLayers = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	DetailDecoLayers->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailDecoLayers->CaptionWidth = 0.9;
	DetailDecoLayers->Caption = "Foliage";
	//DetailDecoLayers->OnCreateComponent=DetailDecoLayers.InternalOnCreateComponent;
	DetailDecoLayers->IniOption = "ini:Engine.Engine.ViewportManager DecoLayers";
	DetailDecoLayers->IniDefault = "True";
	DetailDecoLayers->Hint = "Enables grass and other decorative foliage.";
	DetailDecoLayers->WinTop = 0.656251;
	DetailDecoLayers->WinLeft = 0.59875;
	DetailDecoLayers->WinWidth = 0.3;
	DetailDecoLayers->WinHeight = 0.04;
	//DetailDecoLayers->OnLoadINI=Tab_DetailSettings.InternalOnLoadINI;
	//DetailDecoLayers->OnSaveINI=Tab_DetailSettings.InternalOnSaveINI;
	UmoCheckBox* DetailProjectors = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	DetailProjectors->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailProjectors->CaptionWidth = 0.9;
	DetailProjectors->Caption = "Projectors";
	//DetailProjectors->OnCreateComponent=DetailProjectors.InternalOnCreateComponent;
	DetailProjectors->IniOption = "ini:Engine.Engine.ViewportManager Projectors";
	DetailProjectors->IniDefault = "True";
	DetailProjectors->Hint = "Enables Projectors.";
	DetailProjectors->WinTop = 0.656251;
	DetailProjectors->WinLeft = 0.1;
	DetailProjectors->WinWidth = 0.3;
	DetailProjectors->WinHeight = 0.04;
	//DetailProjectors->OnLoadINI=Tab_DetailSettings.InternalOnLoadINI;
	//DetailProjectors->OnSaveINI=Tab_DetailSettings.InternalOnSaveINI;
	UmoComboBox* DetailDecalStay = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DetailDecalStay->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailDecalStay->Caption = "Decal Stay";
	//DetailDecalStay->OnCreateComponent=DetailDecalStay.InternalOnCreateComponent;
	DetailDecalStay->IniOption = "@Internal";
	DetailDecalStay->IniDefault = "Normal";
	DetailDecalStay->Hint = "Changes how long weapon scarring effects stay around.";
	DetailDecalStay->WinTop = 0.55;
	DetailDecalStay->WinLeft = 0.59875;
	DetailDecalStay->WinWidth = 0.35;
	DetailDecalStay->WinHeight = 0.06;
	//DetailDecalStay->OnLoadINI=Tab_DetailSettings.InternalOnLoadINI;
	//DetailDecalStay->OnSaveINI=Tab_DetailSettings.InternalOnSaveINI;
	UmoComboBox* DetailCharacterDetail = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DetailCharacterDetail->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailCharacterDetail->Caption = "Character Detail";
	//DetailCharacterDetail->OnCreateComponent=DetailCharacterDetail.InternalOnCreateComponent;
	DetailCharacterDetail->IniOption = "ini:Engine.Engine.ViewportManager TextureDetailPlayerSkin";
	DetailCharacterDetail->IniDefault = "High";
	DetailCharacterDetail->Hint = "Changes how much character detail will be rendered.";
	DetailCharacterDetail->WinTop = 0.1;
	DetailCharacterDetail->WinLeft = 0.55;
	DetailCharacterDetail->WinWidth = 0.4;
	DetailCharacterDetail->WinHeight = 0.05;
	//DetailCharacterDetail->OnLoadINI=Tab_DetailSettings.InternalOnLoadINI;
	//DetailCharacterDetail->OnSaveINI=Tab_DetailSettings.InternalOnSaveINI;
	UmoCheckBox* DetailDetailTextures = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	DetailDetailTextures->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailDetailTextures->CaptionWidth = 0.9;
	DetailDetailTextures->Caption = "Detail Textures";
	//DetailDetailTextures->OnCreateComponent=DetailDetailTextures.InternalOnCreateComponent;
	DetailDetailTextures->IniOption = "ini:Engine.Engine.RenderDevice DetailTextures";
	DetailDetailTextures->IniDefault = "True";
	DetailDetailTextures->Hint = "Enables detail textures.";
	DetailDetailTextures->WinTop = 0.56;
	DetailDetailTextures->WinLeft = 0.1;
	DetailDetailTextures->WinWidth = 0.3;
	DetailDetailTextures->WinHeight = 0.05;
	//DetailDetailTextures->OnLoadINI=Tab_DetailSettings.InternalOnLoadINI;
	//DetailDetailTextures->OnSaveINI=Tab_DetailSettings.InternalOnSaveINI;
	UmoCheckBox* DetailCoronas = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	DetailCoronas->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailCoronas->CaptionWidth = 0.9;
	DetailCoronas->Caption = "Coronas";
	//DetailCoronas->OnCreateComponent=DetailCoronas.InternalOnCreateComponent;
	DetailCoronas->IniOption = "ini:Engine.Engine.ViewportManager Coronas";
	DetailCoronas->IniDefault = "True";
	DetailCoronas->Hint = "Enables coronas.";
	DetailCoronas->WinTop = 0.46;
	DetailCoronas->WinLeft = 0.6;
	DetailCoronas->WinWidth = 0.3;
	DetailCoronas->WinHeight = 0.05;
	//DetailCoronas->OnLoadINI=Tab_DetailSettings.InternalOnLoadINI;
	//DetailCoronas->OnSaveINI=Tab_DetailSettings.InternalOnSaveINI;
	UmoCheckBox* DetailDynamicLighting = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	DetailDynamicLighting->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailDynamicLighting->CaptionWidth = 0.9;
	DetailDynamicLighting->Caption = "Dynamic Lighting";
	//DetailDynamicLighting->OnCreateComponent=DetailDynamicLighting.InternalOnCreateComponent;
	DetailDynamicLighting->IniOption = "ini:Engine.Engine.ViewportManager NoDynamicLights";
	DetailDynamicLighting->IniDefault = "True";
	DetailDynamicLighting->Hint = "Enables dynamic lights.";
	DetailDynamicLighting->WinTop = 0.46;
	DetailDynamicLighting->WinLeft = 0.1;
	DetailDynamicLighting->WinWidth = 0.3;
	DetailDynamicLighting->WinHeight = 0.05;
	//DetailDynamicLighting->OnLoadINI=Tab_DetailSettings.InternalOnLoadINI;
	//DetailDynamicLighting->OnSaveINI=Tab_DetailSettings.InternalOnSaveINI;
	UmoCheckBox* DetailDecals = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	DetailDecals->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailDecals->CaptionWidth = 0.9;
	DetailDecals->Caption = "Decals";
	//DetailDecals->OnCreateComponent=DetailDecals.InternalOnCreateComponent;
	DetailDecals->IniOption = "ini:Engine.Engine.ViewportManager Decals";
	DetailDecals->IniDefault = "True";
	DetailDecals->Hint = "Enables weapon scarring effects.";
	DetailDecals->WinTop = 0.36;
	DetailDecals->WinLeft = 0.6;
	DetailDecals->WinWidth = 0.3;
	DetailDecals->WinHeight = 0.05;
	//DetailDecals->OnLoadINI=Tab_DetailSettings.InternalOnLoadINI;
	//DetailDecals->OnSaveINI=Tab_DetailSettings.InternalOnSaveINI;
	UmoComboBox* DetailActorDetail = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DetailActorDetail->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailActorDetail->Caption = "World Detail";
	//DetailActorDetail->OnCreateComponent=DetailActorDetail.InternalOnCreateComponent;
	DetailActorDetail->IniOption = "@Internal";
	DetailActorDetail->IniDefault = "High";
	DetailActorDetail->Hint = "Changes the level of detail used for optional geometry and effects.";
	DetailActorDetail->WinTop = 0.2;
	DetailActorDetail->WinLeft = 0.05;
	DetailActorDetail->WinWidth = 0.4;
	DetailActorDetail->WinHeight = 0.05;
	//DetailActorDetail->OnLoadINI=Tab_DetailSettings.InternalOnLoadINI;
	//DetailActorDetail->OnSaveINI=Tab_DetailSettings.InternalOnSaveINI;
	UmoComboBox* DetailPhysics = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DetailPhysics->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailPhysics->Caption = "Physics Detail";
	//DetailPhysics->OnCreateComponent=DetailPhysics.InternalOnCreateComponent;
	DetailPhysics->IniOption = "@Internal";
	DetailPhysics->IniDefault = "High";
	DetailPhysics->Hint = "Changes the physics simulation level of detail.";
	DetailPhysics->WinTop = 0.2;
	DetailPhysics->WinLeft = 0.55;
	DetailPhysics->WinWidth = 0.4;
	DetailPhysics->WinHeight = 0.05;
	//DetailPhysics->OnLoadINI=Tab_DetailSettings.InternalOnLoadINI;
	//DetailPhysics->OnSaveINI=Tab_DetailSettings.InternalOnSaveINI;
	UmoCheckBox* DetailCharacterShadows = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	DetailCharacterShadows->ComponentJustification = EeTextAlign::TXTA_Left;
	DetailCharacterShadows->CaptionWidth = 0.9;
	DetailCharacterShadows->Caption = "Character Shadows";
	//DetailCharacterShadows->OnCreateComponent=DetailCharacterShadows.InternalOnCreateComponent;
	DetailCharacterShadows->IniOption = "@Internal";
	DetailCharacterShadows->IniDefault = "True";
	DetailCharacterShadows->Hint = "Enables character shadows.";
	DetailCharacterShadows->WinTop = 0.36;
	DetailCharacterShadows->WinLeft = 0.1;
	DetailCharacterShadows->WinWidth = 0.3;
	DetailCharacterShadows->WinHeight = 0.05;
	//DetailCharacterShadows->OnLoadINI=Tab_DetailSettings.InternalOnLoadINI;
	//DetailCharacterShadows->OnSaveINI=Tab_DetailSettings.InternalOnSaveINI;
	UGUIImage* DetailBK = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//DetailBK->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	DetailBK->ImageColor = FColor(255, 255, 255, 160);
	DetailBK->ImageStyle = EImgStyle::ISTY_Stretched;
	DetailBK->WinTop = 0.32;
	DetailBK->WinLeft = 0.021641;
	DetailBK->WinWidth = 0.9575;
	DetailBK->WinHeight = 0.52125;

	DetailLevels = { "Lowest","Lower","Low","Normal","High","Higher","Highest" };
	Controls = { DetailBK,DetailWorldDetail,DetailCharacterDetail,DetailActorDetail,DetailPhysics,DetailCharacterShadows,DetailDecals,DetailDynamicLighting,DetailCoronas,DetailDetailTextures,DetailDecalStay,DetailProjectors,DetailDecoLayers,DetailTrilinear,DetailBlob };
	WinTop = 0.15;
	WinHeight = 0.74;
}

void UTab_DetailSettings::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	Super::InitComponent(MyController, MyOwner);
	for (i = 0; i < Controls.Length; i++)
	{
		Controls[i].__OnChange__Delegate = InternalOnChange;
	}
	if (PlayerOwner().Level.IsDemoBuild())
	{
		for (i = 0; i < 4; i++)
		{
			moComboBox(Controls[1]).addItem(DetailLevels[i]);
		}
		for (i = 0; i < 4; i++)
		{
			moComboBox(Controls[2]).addItem(DetailLevels[i]);
		}
	}
	else
	{
		for (i = 0; i < 7; i++)
		{
			moComboBox(Controls[1]).addItem(DetailLevels[i]);
		}
		for (i = 0; i < 7; i++)
		{
			moComboBox(Controls[2]).addItem(DetailLevels[i]);
		}
	}
	moComboBox(Controls[1]).ReadOnly(true);
	moComboBox(Controls[2]).ReadOnly(true);
	moComboBox(Controls[3]).addItem(DetailLevels[3]);
	moComboBox(Controls[3]).addItem(DetailLevels[4]);
	moComboBox(Controls[3]).addItem(DetailLevels[6]);
	moComboBox(Controls[3]).ReadOnly(true);
	for (i = 2; i < 5; i++)
	{
		moComboBox(Controls[4]).addItem(DetailLevels[i]);
	}
	moComboBox(Controls[4]).ReadOnly(true);
	for (i = 2; i < 5; i++)
	{
		moComboBox(Controls[10]).addItem(DetailLevels[i]);
	}
	moComboBox(Controls[10]).ReadOnly(true);
	*/
}

void UTab_DetailSettings::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	int32 i = 0;
	bool A = false;
	bool B = false;
	if (Sender == Controls[1])
	{
		if (S == "UltraLow")
		{
			prevTextureDetail = 0;
		}
		else
		{
			if (S == "Low")
			{
				prevTextureDetail = 1;
			}
			else
			{
				if (S == "Lower")
				{
					prevTextureDetail = 2;
				}
				else
				{
					if (S == "Normal")
					{
						prevTextureDetail = 3;
					}
					else
					{
						if (S == "Higher")
						{
							prevTextureDetail = 4;
						}
						else
						{
							if (S == "High")
							{
								prevTextureDetail = 5;
							}
							else
							{
								if (S == "UltraHigh")
								{
									prevTextureDetail = 6;
								}
							}
						}
					}
				}
			}
		}
		moComboBox(Sender).SetText(DetailLevels[prevTextureDetail]);
	}
	else
	{
		if (Sender == Controls[2])
		{
			if (S == "UltraLow")
			{
				prevCharDetail = 0;
			}
			else
			{
				if (S == "Low")
				{
					prevCharDetail = 1;
				}
				else
				{
					if (S == "Lower")
					{
						prevCharDetail = 2;
					}
					else
					{
						if (S == "Normal")
						{
							prevCharDetail = 3;
						}
						else
						{
							if (S == "Higher")
							{
								prevCharDetail = 4;
							}
							else
							{
								if (S == "High")
								{
									prevCharDetail = 5;
								}
								else
								{
									if (S == "UltraHigh")
									{
										prevCharDetail = 6;
									}
								}
							}
						}
					}
				}
			}
			moComboBox(Sender).SetText(DetailLevels[prevCharDetail]);
		}
		else
		{
			if (Sender == Controls[3])
			{
				A = bool(PlayerOwner().ConsoleCommand("get ini:Engine.Engine.RenderDevice HighDetailActors"));
				B = bool(PlayerOwner().ConsoleCommand("get ini:Engine.Engine.RenderDevice SuperHighDetailActors"));
				if (B)
				{
					prevWorldDetail = 6;
				}
				else
				{
					if (A)
					{
						prevWorldDetail = 4;
					}
					else
					{
						prevWorldDetail = 3;
					}
				}
				moComboBox(Sender).SetText(DetailLevels[prevWorldDetail]);
			}
			else
			{
				if (Sender == Controls[4])
				{
					if (PlayerOwner().Level.Default.PhysicsDetailLevel == 0)
					{
						moComboBox(Sender).SetText(DetailLevels[2]);
					}
					else
					{
						if (PlayerOwner().Level.Default.PhysicsDetailLevel == 1)
						{
							moComboBox(Sender).SetText(DetailLevels[3]);
						}
						else
						{
							moComboBox(Sender).SetText(DetailLevels[4]);
						}
					}
				}
				else
				{
					if (Sender == Controls[7])
					{
						moCheckBox(Sender).Checked((!bool(S)));
					}
					else
					{
						if (Sender == Controls[10])
						{
							i = int(PlayerOwner().Level.Default.DecalStayScale);
							switch (i)
							{
							case 0:
								moComboBox(Sender).SetText(DetailLevels[2]);
								break;
							case 1:
								moComboBox(Sender).SetText(DetailLevels[3]);
								break;
							case 2:
								moComboBox(Sender).SetText(DetailLevels[4]);
								break;
							default:
							}
						}
						else
						{
							moCheckBox(Sender).Checked(bool(S));
						}
					}
				}
			}
		}
	}
	*/
}

FString UTab_DetailSettings::InternalOnSaveINI(UGUIComponent* Sender)
{
	return "FAKE";   //FAKE   /ELiZ
}

void UTab_DetailSettings::InternalOnChange(UGUIComponent* Sender)
{
	/*
	FString t = "";
	FString V = "";
	bool B = false;
	bool goingUp = false;
	int32 newDetail = 0;
	if (!Controller.bCurMenuInitialized)
	{
		return;
	}
	if (Sender == Controls[1])
	{
		t = "set ini:Engine.Engine.ViewportManager TextureDetail";
		if (moComboBox(Sender).GetText() == DetailLevels[0])
		{
			V = "UltraLow";
			newDetail = 0;
		}
		else
		{
			if (moComboBox(Sender).GetText() == DetailLevels[1])
			{
				V = "Low";
				newDetail = 1;
			}
			else
			{
				if (moComboBox(Sender).GetText() == DetailLevels[2])
				{
					V = "Lower";
					newDetail = 2;
				}
				else
				{
					if (moComboBox(Sender).GetText() == DetailLevels[3])
					{
						V = "Normal";
						newDetail = 3;
					}
					else
					{
						if (moComboBox(Sender).GetText() == DetailLevels[4])
						{
							V = "Higher";
							newDetail = 4;
						}
						else
						{
							if (moComboBox(Sender).GetText() == DetailLevels[5])
							{
								V = "High";
								newDetail = 5;
							}
							else
							{
								if (moComboBox(Sender).GetText() == DetailLevels[6])
								{
									V = "UltraHigh";
									newDetail = 6;
								}
							}
						}
					}
				}
			}
		}
		PlayerOwner().ConsoleCommand(t $ "Terrain" @ V);
		PlayerOwner().ConsoleCommand(t $ "World" @ V);
		PlayerOwner().ConsoleCommand(t $ "Rendermap" @ V);
		PlayerOwner().ConsoleCommand(t $ "Lightmap" @ V);
		PlayerOwner().ConsoleCommand("flush");
		if (newDetail > prevTextureDetail)
		{
			goingUp = true;
		}
		prevTextureDetail = newDetail;
	}
	else
	{
		if (Sender == Controls[2])
		{
			t = "set ini:Engine.Engine.ViewportManager TextureDetail";
			if (moComboBox(Sender).GetText() == DetailLevels[0])
			{
				V = "UltraLow";
				newDetail = 0;
			}
			else
			{
				if (moComboBox(Sender).GetText() == DetailLevels[1])
				{
					V = "Low";
					newDetail = 1;
				}
				else
				{
					if (moComboBox(Sender).GetText() == DetailLevels[2])
					{
						V = "Lower";
						newDetail = 2;
					}
					else
					{
						if (moComboBox(Sender).GetText() == DetailLevels[3])
						{
							V = "Normal";
							newDetail = 3;
						}
						else
						{
							if (moComboBox(Sender).GetText() == DetailLevels[4])
							{
								V = "Higher";
								newDetail = 4;
							}
							else
							{
								if (moComboBox(Sender).GetText() == DetailLevels[5])
								{
									V = "High";
									newDetail = 5;
								}
								else
								{
									if (moComboBox(Sender).GetText() == DetailLevels[6])
									{
										V = "UltraHigh";
										newDetail = 6;
									}
								}
							}
						}
					}
				}
			}
			PlayerOwner().ConsoleCommand(t $ "WeaponSkin" @ V);
			PlayerOwner().ConsoleCommand(t $ "PlayerSkin" @ V);
			PlayerOwner().ConsoleCommand("flush");
			if (newDetail > prevCharDetail)
			{
				goingUp = true;
			}
			prevCharDetail = newDetail;
		}
		else
		{
			if (Sender == Controls[3])
			{
				if (moComboBox(Sender).GetText() == DetailLevels[6])
				{
					PlayerOwner().ConsoleCommand("set ini:Engine.Engine.RenderDevice HighDetailActors True");
					PlayerOwner().ConsoleCommand("set ini:Engine.Engine.RenderDevice SuperHighDetailActors True");
					PlayerOwner().Level.DetailChange(2);
					newDetail = 6;
				}
				else
				{
					if (moComboBox(Sender).GetText() == DetailLevels[4])
					{
						PlayerOwner().ConsoleCommand("set ini:Engine.Engine.RenderDevice HighDetailActors True");
						PlayerOwner().ConsoleCommand("set ini:Engine.Engine.RenderDevice SuperHighDetailActors False");
						PlayerOwner().Level.DetailChange(1);
						newDetail = 4;
					}
					else
					{
						if (moComboBox(Sender).GetText() == DetailLevels[3])
						{
							PlayerOwner().ConsoleCommand("set ini:Engine.Engine.RenderDevice HighDetailActors False");
							PlayerOwner().ConsoleCommand("set ini:Engine.Engine.RenderDevice SuperHighDetailActors False");
							PlayerOwner().Level.DetailChange(0);
							newDetail = 3;
						}
					}
				}
				if (newDetail > prevWorldDetail)
				{
					goingUp = true;
				}
				prevWorldDetail = newDetail;
			}
			else
			{
				if (Sender == Controls[4])
				{
					if (moComboBox(Sender).GetText() == DetailLevels[2])
					{
						PlayerOwner().Level.Default.PhysicsDetailLevel = 0;
					}
					else
					{
						if (moComboBox(Sender).GetText() == DetailLevels[3])
						{
							PlayerOwner().Level.Default.PhysicsDetailLevel = 1;
						}
						else
						{
							if (moComboBox(Sender).GetText() == DetailLevels[4])
							{
								PlayerOwner().Level.Default.PhysicsDetailLevel = 2;
							}
						}
					}
					PlayerOwner().Level.PhysicsDetailLevel = PlayerOwner().Level.Default.PhysicsDetailLevel;
					PlayerOwner().Level.SaveConfig();
				}
				else
				{
					if (Sender == Controls[7])
					{
						B = moCheckBox(Sender).IsChecked();
						B = (B != true);
						PlayerOwner().ConsoleCommand("set" @ Sender.IniOption @ string(B));
						if (moCheckBox(Sender).IsChecked())
						{
							goingUp = true;
						}
					}
					else
					{
						if (Sender == Controls[10])
						{
							if (moComboBox(Sender).GetText() == DetailLevels[4])
							{
								PlayerOwner().Level.Default.DecalStayScale = 2;
							}
							else
							{
								if (moComboBox(Sender).GetText() == DetailLevels[3])
								{
									PlayerOwner().Level.Default.DecalStayScale = 1;
								}
								else
								{
									if (moComboBox(Sender).GetText() == DetailLevels[2])
									{
										PlayerOwner().Level.Default.DecalStayScale = 0;
									}
								}
							}
							PlayerOwner().Level.DecalStayScale = PlayerOwner().Level.Default.DecalStayScale;
							PlayerOwner().Level.SaveConfig();
						}
						else
						{
							PlayerOwner().ConsoleCommand("set" @ Sender.IniOption @ string(moCheckBox(Sender).IsChecked()));
							if (moCheckBox(Sender).IsChecked())
							{
								goingUp = true;
							}
						}
					}
				}
			}
		}
	}
	if (goingUp && (!bExpert))
	{
		Controller.OpenMenu("XInterface.UT2PerformWarn");
	}
	if ((((((((((((((!bPlayedSound) && (!PlayerOwner().bNoMatureLanguage)) && (moComboBox(Controls[1]).GetText() == DetailLevels[6])) && (moComboBox(Controls[2]).GetText() == DetailLevels[6])) && (moComboBox(Controls[3]).GetText() == DetailLevels[6])) && (moComboBox(Controls[4]).GetText() == DetailLevels[4])) && moCheckBox(Controls[5]).IsChecked()) && moCheckBox(Controls[6]).IsChecked()) && moCheckBox(Controls[7]).IsChecked()) && moCheckBox(Controls[8]).IsChecked()) && moCheckBox(Controls[9]).IsChecked()) && (moComboBox(Controls[10]).GetText() == DetailLevels[4])) && moCheckBox(Controls[11]).IsChecked()) && moCheckBox(Controls[12]).IsChecked())
	{
		bPlayedSound = true;
	}
	*/
}
