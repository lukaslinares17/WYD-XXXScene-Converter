/* ------------------------------------------- */
/*     WYD XXXScene Converter - by xEviiL'     */
/* ------------------------------------------- */
/*        FAVOR NÃO REMOVER OS CRÉDITOS        */
/* ------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <locale.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/* ***** BIN FILES ***** */
#define FieldScene2_Bin		"UI/FieldScene2.Bin"
#define SelCharScene2_Bin	"UI/SelCharScene2.Bin"
#define SelServerScene2_Bin	"UI/SelServerScene2.Bin"
/* ***** TXT FILES ***** */
#define FieldScene2_Txt		"UI/FieldScene2.Txt"
#define SelCharScene2_Txt	"UI/SelCharScene2.Txt"
#define SelServerScene2_Txt	"UI/SelServerScene2.Txt"
/* **** CONSOLE MSG **** */
#define MSG_CANT_CREATE		"\nNão foi possível criar o arquivo %s!!\n"
#define MSG_CANT_READ		"\nNão foi possível localizar o arquivo %s!!\n"
#define MSG_CLOSE			"\nFechando o Conversor. Obrigado por utilizar...\n"
#define MSG_INVALID_OPTION	"\nOpção Inválida!!\n"
#define MSG_READFILE_ERROR	"\nO sistema está sendo fínalizado..\n"
/* **** FPRINTF SET **** */
#define SET_HUD				"\n[HUD]\n"
#define SET_BUTTON			"\n[Button]\n"
#define SET_UNK3			"\n[Unknown3]\n"
#define SET_SERVERLIST		"\n[ServerList]\n"
#define SET_UNK10			"\n[Unknown10]\n"
#define SET_TEXT			"\n[Text]\n"
#define SET_TEXTBOX			"\n[TextBox]\n"
#define SET_UNK15			"\n[Unknown15]\n"
#define SET_UNK16			"\n[Unknown16]\n"
/* **** FPRINTF SET **** */
#define SET_BASE_ID			"Base_ID = %d %d\n"
#define SET_HEIGHT			"Height = %d\n"
#define SET_HUD_ID			"HUD_ID = %d %d\n"
#define SET_LEFT			"Left = %d\n"
#define SET_MAXLENGHT		"MaxLength = %d\n"
#define SET_UITEXTURESETID	"UITextureSetID = %d\n"
#define SET_UNKNOWN1		"Unknown1 = %d\n"
#define SET_UNKNOWN2		"Unknown2 = %d\n"
#define SET_UNKNOWN3		"Unknown3 = %d\n"
#define SET_UNKNOWN4		"Unknown4 = %d\n"
#define SET_UNKNOWN5		"Unknown5 = %d\n"
#define SET_UNKNOWN6		"Unknown6 = %d\n"
#define SET_UNKNOWN7		"Unknown7 = %d\n"
#define SET_POSX			"PosX = %d\n"
#define SET_POSY			"PosY = %d\n"
#define SET_RADIUSCLICK		"RadiusClick = %d\n"
#define SET_SERVERNAMEX		"ServerNameSpaceX = %d\n"
#define SET_SERVERNAMEY		"ServerNameSpaceY = %d\n"
#define SET_SPACEFORCLICKX	"SpaceForClickX = %d\n"
#define SET_SPACEFORCLICKY	"SpaceForClickY = %d\n"
#define SET_STARTSCENETYPE	"StartSceneType = %d\n"
#define SET_STRINGID		"StringID = %d\n"
#define SET_TOP				"Top = %d\n"
#define SET_TRANSPARENT		"Transparent = %d\n"
#define SET_TYPE1			"Type = 1\n"
#define SET_TYPE2			"Type = 2\n"
#define SET_TYPE3			"Type = 3\n"
#define SET_TYPE6			"Type = 6\n"
#define SET_TYPE10			"Type = 10\n"
#define SET_TYPE12			"Type = 12\n"
#define SET_TYPE13			"Type = 13\n"
#define SET_TYPE15			"Type = 15\n"
#define SET_TYPE16			"Type = 15\n"
#define SET_WIDHT			"Width = %d\n"


void Console();
void TittleConsole();
void MenuConsole();
void MenuFieldScene2();
void MenuSelCharScene2();
void MenuSelServerScene2();
void CONVERT_BIN2TXT(const char* Origem, const char *Destino);
void CONVERT_TXT2BIN(const char* Origem, const char *Destino);


enum SceneType
{
	eHud = 1,
	eButton = 2,
	eUnknown3 = 3,
	eServerName = 6,
	eUnknown10 = 10, // 0x0000000A
	eText = 12,		 // 0x0000000C
	eTextBox = 13,	 // 0x0000000D
	eUnknown15 = 15, // 0x0000000F
	eUnknown16 = 16, // 0x00000010
};

struct SceneHudEntry
{
	struct
	{
		uint16_t ID1;
		uint16_t ID2;
	} Base_ID;

	struct
	{
		uint16_t ID1;
		uint16_t ID2;
	} HUD_ID;

	int UITextureSetID;
	int PosX;
	int PosY;
	int Width;
	int Height;
	int RadiusClick;
	int Unknown1;
	int StartSceneType;
} HUD;

struct SceneButtonEntry
{
	struct
	{
		uint16_t ID1;
		uint16_t ID2;
	} Base_ID;

	struct
	{
		uint16_t ID1;
		uint16_t ID2;
	} HUD_ID;

	int UITextureSetID;
	int PosX;
	int PosY;
	int Width;
	int Height;
	int RadiusClick;
	int Unknown1;
	int StringID;
} Button;

struct SceneUnknown3Entry
{
	struct
	{
		uint16_t ID1;
		uint16_t ID2;
	} Base_ID;

	struct
	{
		uint16_t ID1;
		uint16_t ID2;
	} HUD_ID;

	int UITextureSetID;
	int Unknown1;
	int Unknown2;
	int Unknown3;
	int Unknown4;
	int Unknown5;
} Unk3;

struct SceneServerNameEntry
{
	struct
	{
		uint16_t ID1;
		uint16_t ID2;
	} Base_ID;

	struct
	{
		uint16_t ID1;
		uint16_t ID2;
	} HUD_ID;

	int UITextureSetID;
	int ServerNameSpaceX;
	int ServerNameSpaceY;
	int PosX;
	int PosY;
	int SpaceForClickX;
	int SpaceForClickY;
	int Unknown1;
	int Unknown2;
	int Unknown3;
	int StringID;
} SN;

struct SceneTextEntry
{
	struct
	{
		uint16_t ID1;
		uint16_t ID2;
	} Base_ID;

	struct
	{
		uint16_t ID1;
		uint16_t ID2;
	} HUD_ID;

	int UITextureSetID;
	int Left;
	int PosX;
	int PosY;
	int Top;
	int Unknown1;
	int Transparent;
	int Unknown2;
	int Unknown3;
	int Unknown4;
	int StringID;
} Text;

struct SceneTextBoxEntry
{
	struct
	{
		uint16_t ID1;
		uint16_t ID2;
	} Base_ID;

	struct
	{
		uint16_t ID1;
		uint16_t ID2;
	} HUD_ID;

	int UITextureSetID;
	int PosX;
	int PosY;
	int Width;
	int Height;
	int Unknown1[5];	// 5x 4 Bytes
	int MaxLength;
	int Unknown2[33]; // 33x 4 Bytes
} TextBox;

struct SceneUnknown10Entry
{
	struct
	{
		uint16_t ID1;
		uint16_t ID2;
	} Base_ID;

	struct
	{
		uint16_t ID1;
		uint16_t ID2;
	} HUD_ID;

	int PosX;
	int PosY;
	int Width;
	int Height;
	int Unknown1;
	int Unknown2;
	int Unknown3;
	int Unknown4;
	int Unknown5;
} Unk10;

struct SceneUnknown15Entry
{
	struct
	{
		uint16_t ID1;
		uint16_t ID2;
	} Base_ID;

	struct
	{
		uint16_t ID1;
		uint16_t ID2;
	} HUD_ID;

	int UITextureSetID;
	int Unknown1;
	int Unknown2;
	int Unknown3;
	int Unknown4;
} Unk15;

struct SceneUnknown16Entry
{
	struct
	{
		uint16_t ID1;
		uint16_t ID2;
	} Base_ID;

	struct
	{
		uint16_t ID1;
		uint16_t ID2;
	} HUD_ID;

	int UITextureSetID;
	int Unknown1;
	int Unknown2;
	int Unknown3;
	int Unknown4;
	int Unknown5;
	int Unknown6;
	int Unknown7;
} Unk16;

