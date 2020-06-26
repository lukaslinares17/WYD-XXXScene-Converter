/* ------------------------------------------- */
/*     WYD XXXScene Converter - by xEviiL'     */
/* ------------------------------------------- */
/*        FAVOR NÃO REMOVER OS CRÉDITOS        */
/* ------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include "Main.h"

int main()
{
	SetConsoleTitle(TEXT("WYD XXXScene Converter - by xEviiL'"));
	Console();
}

void TittleConsole()
{
	system("cls");
	printf("-------------------------------------------\n");
	printf("    WYD XXXScene Converter - by xEviiL'    \n");
	printf("-------------------------------------------\n");
}

void MenuConsole()
{
	printf("Escolha o arquivo que deseja converter\n\n");
	printf("1 - FieldScene\n");
	printf("2 - SelCharScene\n");
	printf("3 - SelServerScene\n");
	printf("4 - Sair\n\n");
	printf("Digite a opção desejada: ");
}

void MenuFieldScene2()
{
	printf("Escolha o método de conversão\n\n");
	printf("1 - FieldScene2 [BIN2TXT]\n");
	printf("2 - FieldScene2 [TXT2BIN]\n\n");
	printf("Digite a opção desejada: ");
}

void MenuSelCharScene2()
{
	printf("Escolha o método de conversão\n\n");
	printf("1 - SelCharScene2 [BIN2TXT]\n");
	printf("2 - SelCharScene2 [TXT2BIN]\n\n");
	printf("Digite a opção desejada: ");
}

void MenuSelServerScene2()
{
	printf("Escolha o método de conversão\n\n");
	printf("1 - SelServerScene2 [BIN2TXT]\n");
	printf("2 - SelServerScene2 [TXT2BIN]\n\n");
	printf("Digite a opção desejada: ");
}

void Console()
{
	setlocale(LC_ALL, "Portuguese");

	int Option, fOption;

	do
	{
		TittleConsole();
		MenuConsole();
		scanf("%d", &Option);

		switch (Option)
		{
		case 1:
			TittleConsole();
			MenuFieldScene2();
			scanf("%d", &fOption);
			switch (fOption)
			{
				case 1: CONVERT_BIN2TXT(FieldScene2_Bin, FieldScene2_Txt); break;

				case 2: CONVERT_TXT2BIN(FieldScene2_Txt, FieldScene2_Bin); break;

				default: printf(MSG_INVALID_OPTION); _getch(); break;
			}
			break;

		case 2:
			TittleConsole();
			MenuSelCharScene2();
			scanf("%d", &fOption);
			switch (fOption)
			{
				case 1: CONVERT_BIN2TXT(SelCharScene2_Bin, SelCharScene2_Txt); break;

				case 2: CONVERT_TXT2BIN(SelCharScene2_Txt, SelCharScene2_Bin); break;

				default: printf(MSG_INVALID_OPTION); _getch(); break;
			}
			break;

		case 3:
			TittleConsole();
			MenuSelServerScene2();
			scanf("%d", &fOption);
			switch (fOption)
			{
				case 1: CONVERT_BIN2TXT(SelServerScene2_Bin, SelServerScene2_Txt); break;

				case 2: CONVERT_TXT2BIN(SelServerScene2_Txt, SelServerScene2_Bin); break;

				default: printf(MSG_INVALID_OPTION); _getch(); break;
			}
			break;

		case 4:
			printf(MSG_CLOSE); _getch(); break;

		default: printf(MSG_INVALID_OPTION); _getch(); break;
		}

	} while (Option != 4);
}

void CONVERT_BIN2TXT(const char* Origem, const char *Destino)
{
	int Buffer;

	FILE *fOrigem, *fDest; // Ponteiro Para Arquivo

	if (!(fOrigem = fopen(Origem, "rb")))
	{
		printf(MSG_CANT_READ, Origem);
		printf(MSG_READFILE_ERROR);
		system("PAUSE");
		exit(1);
	}

	if (!(fDest = fopen(Destino, "w")))
	{
		printf(MSG_CANT_CREATE, Destino);
		printf(MSG_READFILE_ERROR);
		system("PAUSE");
		exit(1);
	}

	while (!feof(fOrigem))
	{
		fread(&Buffer, sizeof(int), 1, fOrigem);

		if (!feof(fOrigem))
		{
			if (Buffer == SceneType::eHud)
			{
				fread(&HUD, sizeof(SceneHudEntry), 1, fOrigem);
				fprintf(fDest, SET_HUD);
				fprintf(fDest, SET_TYPE1);
				fprintf(fDest, SET_BASE_ID, HUD.Base_ID.ID2, HUD.Base_ID.ID1);
				fprintf(fDest, SET_HUD_ID, HUD.HUD_ID.ID2, HUD.HUD_ID.ID1);
				fprintf(fDest, SET_UITEXTURESETID, HUD.UITextureSetID);
				fprintf(fDest, SET_POSX, HUD.PosX);
				fprintf(fDest, SET_POSY, HUD.PosY);
				fprintf(fDest, SET_WIDHT, HUD.Width);
				fprintf(fDest, SET_HEIGHT, HUD.Height);
				fprintf(fDest, SET_RADIUSCLICK, HUD.RadiusClick);
				fprintf(fDest, SET_UNKNOWN1, HUD.Unknown1);
				fprintf(fDest, SET_STARTSCENETYPE, HUD.StartSceneType);
			}
			if (Buffer == SceneType::eButton)
			{
				fread(&Button, sizeof(SceneButtonEntry), 1, fOrigem);
				fprintf(fDest, SET_BUTTON);
				fprintf(fDest, SET_TYPE2);
				fprintf(fDest, SET_BASE_ID, Button.Base_ID.ID2, Button.Base_ID.ID1);
				fprintf(fDest, SET_HUD_ID, Button.HUD_ID.ID2, Button.HUD_ID.ID1);
				fprintf(fDest, SET_UITEXTURESETID, Button.UITextureSetID);
				fprintf(fDest, SET_POSX, Button.PosX);
				fprintf(fDest, SET_POSY, Button.PosY);
				fprintf(fDest, SET_WIDHT, Button.Width);
				fprintf(fDest, SET_HEIGHT, Button.Height);
				fprintf(fDest, SET_RADIUSCLICK, Button.RadiusClick);
				fprintf(fDest, SET_UNKNOWN1, Button.Unknown1);
				fprintf(fDest, SET_STARTSCENETYPE, Button.StringID);
			}
			if (Buffer == SceneType::eUnknown3)
			{
				fread(&Unk3, sizeof(SceneUnknown3Entry), 1, fOrigem);
				fprintf(fDest, SET_UNK3);
				fprintf(fDest, SET_TYPE3);
				fprintf(fDest, SET_BASE_ID, Unk3.Base_ID.ID2, Unk3.Base_ID.ID1);
				fprintf(fDest, SET_HUD_ID, Unk3.HUD_ID.ID2, Unk3.HUD_ID.ID1);
				fprintf(fDest, SET_UITEXTURESETID, Unk3.UITextureSetID);
				fprintf(fDest, SET_UNKNOWN1, Unk3.Unknown1);
				fprintf(fDest, SET_UNKNOWN2, Unk3.Unknown2);
				fprintf(fDest, SET_UNKNOWN3, Unk3.Unknown3);
				fprintf(fDest, SET_UNKNOWN4, Unk3.Unknown4);
				fprintf(fDest, SET_UNKNOWN5, Unk3.Unknown5);
			}
			if (Buffer == SceneType::eServerName)
			{
				fread(&SN, sizeof(SceneServerNameEntry), 1, fOrigem);
				fprintf(fDest, SET_SERVERLIST);
				fprintf(fDest, SET_TYPE6);
				fprintf(fDest, SET_BASE_ID, SN.Base_ID.ID2, SN.Base_ID.ID1);
				fprintf(fDest, SET_HUD_ID, SN.HUD_ID.ID2, SN.HUD_ID.ID1);
				fprintf(fDest, SET_UITEXTURESETID, SN.UITextureSetID);
				fprintf(fDest, SET_SERVERNAMEX, SN.ServerNameSpaceX);
				fprintf(fDest, SET_SERVERNAMEY, SN.ServerNameSpaceY);
				fprintf(fDest, SET_POSX, SN.PosX);
				fprintf(fDest, SET_POSY, SN.PosY);
				fprintf(fDest, SET_SPACEFORCLICKX, SN.SpaceForClickX);
				fprintf(fDest, SET_SPACEFORCLICKY, SN.SpaceForClickY);
				fprintf(fDest, SET_UNKNOWN1, SN.Unknown1);
				fprintf(fDest, SET_UNKNOWN2, SN.Unknown2);
				fprintf(fDest, SET_UNKNOWN3, SN.Unknown3);
				fprintf(fDest, SET_STRINGID, SN.StringID);
			}
			if (Buffer == SceneType::eUnknown10)
			{
				fread(&Unk10, sizeof(SceneUnknown10Entry), 1, fOrigem);
				fprintf(fDest, SET_UNK10);
				fprintf(fDest, SET_TYPE10);
				fprintf(fDest, SET_BASE_ID, Unk10.Base_ID.ID2, Unk10.Base_ID.ID1);
				fprintf(fDest, SET_HUD_ID, Unk10.HUD_ID.ID2, Unk10.HUD_ID.ID1);
				//fprintf(fDest, SET_UITEXTURESETID,	Unk10.UITextureSetID);
				fprintf(fDest, SET_POSX, Unk10.PosX);
				fprintf(fDest, SET_POSY, Unk10.PosY);
				fprintf(fDest, SET_WIDHT, Unk10.Width);
				fprintf(fDest, SET_HEIGHT, Unk10.Height);
				fprintf(fDest, SET_UNKNOWN1, Unk10.Unknown1);
				fprintf(fDest, SET_UNKNOWN2, Unk10.Unknown2);
				fprintf(fDest, SET_UNKNOWN3, Unk10.Unknown3);
				fprintf(fDest, SET_UNKNOWN4, Unk10.Unknown4);
				fprintf(fDest, SET_UNKNOWN5, Unk10.Unknown5);
			}
			if (Buffer == SceneType::eText)
			{
				fread(&Text, sizeof(SceneTextEntry), 1, fOrigem);
				fprintf(fDest, SET_TEXT);
				fprintf(fDest, SET_TYPE12);
				fprintf(fDest, SET_BASE_ID, Text.Base_ID.ID2, Text.Base_ID.ID1);
				fprintf(fDest, SET_HUD_ID, Text.HUD_ID.ID2, Text.HUD_ID.ID1);
				fprintf(fDest, SET_UITEXTURESETID, Text.UITextureSetID);
				fprintf(fDest, SET_LEFT, Text.Left);
				fprintf(fDest, SET_POSX, Text.PosX);
				fprintf(fDest, SET_POSY, Text.PosY);
				fprintf(fDest, SET_TOP, Text.Top);
				fprintf(fDest, SET_UNKNOWN1, Text.Unknown1);
				fprintf(fDest, SET_TRANSPARENT, Text.Transparent);
				fprintf(fDest, SET_UNKNOWN2, Text.Unknown2);
				fprintf(fDest, SET_UNKNOWN3, Text.Unknown3);
				fprintf(fDest, SET_UNKNOWN4, Text.Unknown4);
				fprintf(fDest, SET_STRINGID, Text.StringID);
			}
			if (Buffer == SceneType::eTextBox)
			{
				fread(&TextBox, sizeof(SceneTextBoxEntry), 1, fOrigem);
				fprintf(fDest, SET_TEXTBOX);
				fprintf(fDest, SET_TYPE13);
				fprintf(fDest, SET_BASE_ID, TextBox.Base_ID.ID2, TextBox.Base_ID.ID1);
				fprintf(fDest, SET_HUD_ID, TextBox.HUD_ID.ID2, TextBox.HUD_ID.ID1);
				fprintf(fDest, SET_UITEXTURESETID, TextBox.UITextureSetID);
				fprintf(fDest, SET_POSX, TextBox.PosX);
				fprintf(fDest, SET_POSY, TextBox.PosY);
				fprintf(fDest, SET_WIDHT, TextBox.Width);
				fprintf(fDest, SET_HEIGHT, TextBox.Height);
				/* Não sei pq, mas não funcionou :x
				int i;
				for (i = 0; i < 5; i++);
				{
				fprintf(fDest, "%d", TextBox.Unknown1[i]);
				////fflush(stdin);
				}
				*/
				fprintf(fDest, "Unknown1 = %d %d %d %d %d\n", TextBox.Unknown1[0], TextBox.Unknown1[1], TextBox.Unknown1[2], TextBox.Unknown1[3], TextBox.Unknown1[4]);
				fprintf(fDest, SET_MAXLENGHT, TextBox.MaxLength);
				/* Não sei pq, mas não funcionou :x
				int i;
				for (i = 0; i < 32; i++);
				{
					fprintf(fDest, "%d", TextBox.Unknown2[i]);
					////fflush(stdin);
				}
				*/
				fprintf(fDest, "Unknown2 = %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", TextBox.Unknown2[0],
					TextBox.Unknown2[1], TextBox.Unknown2[2], TextBox.Unknown2[3], TextBox.Unknown2[4], TextBox.Unknown2[5],
					TextBox.Unknown2[6], TextBox.Unknown2[7], TextBox.Unknown2[8], TextBox.Unknown2[9], TextBox.Unknown2[10],
					TextBox.Unknown2[11], TextBox.Unknown2[12], TextBox.Unknown2[13], TextBox.Unknown2[14], TextBox.Unknown2[15],
					TextBox.Unknown2[16], TextBox.Unknown2[17], TextBox.Unknown2[18], TextBox.Unknown2[19], TextBox.Unknown2[20],
					TextBox.Unknown2[21], TextBox.Unknown2[22], TextBox.Unknown2[23], TextBox.Unknown2[24], TextBox.Unknown2[25],
					TextBox.Unknown2[26], TextBox.Unknown2[27], TextBox.Unknown2[28], TextBox.Unknown2[29], TextBox.Unknown2[30],
					TextBox.Unknown2[31], TextBox.Unknown2[32], TextBox.Unknown2[33]);
			}
			if (Buffer == SceneType::eUnknown15)
			{
				fread(&Unk15, sizeof(SceneUnknown15Entry), 1, fOrigem);
				fprintf(fDest, SET_UNK15);
				fprintf(fDest, SET_TYPE15);
				fprintf(fDest, SET_BASE_ID, Unk15.Base_ID.ID2, Unk15.Base_ID.ID1);
				fprintf(fDest, SET_HUD_ID, Unk15.HUD_ID.ID2, Unk15.HUD_ID.ID1);
				fprintf(fDest, SET_UITEXTURESETID, Unk15.UITextureSetID);
				fprintf(fDest, SET_UNKNOWN1, Unk15.Unknown1);
				fprintf(fDest, SET_UNKNOWN2, Unk15.Unknown2);
				fprintf(fDest, SET_UNKNOWN3, Unk15.Unknown3);
				fprintf(fDest, SET_UNKNOWN4, Unk15.Unknown4);
			}
			if (Buffer == SceneType::eUnknown16)
			{
				fprintf(fDest, SET_UNK16);
				fprintf(fDest, SET_TYPE16);
				fprintf(fDest, SET_BASE_ID, Unk16.Base_ID.ID2, Unk16.Base_ID.ID1);
				fprintf(fDest, SET_HUD_ID, Unk16.HUD_ID.ID2, Unk16.HUD_ID.ID1);
				fprintf(fDest, SET_UITEXTURESETID, Unk16.UITextureSetID);
				fprintf(fDest, SET_UNKNOWN1, Unk16.Unknown1);
				fprintf(fDest, SET_UNKNOWN2, Unk16.Unknown2);
				fprintf(fDest, SET_UNKNOWN3, Unk16.Unknown3);
				fprintf(fDest, SET_UNKNOWN4, Unk16.Unknown4);
				fprintf(fDest, SET_UNKNOWN5, Unk16.Unknown5);
				fprintf(fDest, SET_UNKNOWN6, Unk16.Unknown6);
				fprintf(fDest, SET_UNKNOWN7, Unk16.Unknown7);
			}
		}
	}
	fclose(fOrigem);
	fclose(fDest);
}

// Falta fazer o conversor de .TXT para .BIN
void CONVERT_TXT2BIN(const char* Origem, const char *Destino)
{

	FILE *fOrigem, *fDest; // Ponteiro Para Arquivo

	if (!(fOrigem = fopen(Origem, "r")))
	{
		printf(MSG_CANT_READ, Origem);
		printf(MSG_READFILE_ERROR);
		system("PAUSE");
		exit(1);
	}

	if (!(fDest = fopen(Destino, "wb")))
	{
		printf(MSG_CANT_CREATE, Destino);
		printf(MSG_READFILE_ERROR);
		system("PAUSE");
		exit(1);
	}

	while (!feof(fOrigem))
	{

		//fgets(&Buffer, sizeof(Buffer), fOrigem);

		if (!feof(fOrigem))
		{
			//
		}
	}
	fclose(fOrigem);
	fclose(fDest);
}
