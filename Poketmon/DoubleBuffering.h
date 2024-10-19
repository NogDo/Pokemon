#pragma once
#include <Windows.h>
#include <iostream>

class DoubleBuffering
{
private:
	HANDLE m_ScreenBuffer[2];
	CHAR_INFO* m_charInfo;
	COORD m_size;
	SMALL_RECT m_rect;
	CONSOLE_FONT_INFOEX m_font;

	int m_nScreenIndex;
	int m_nBasicColor;
	int m_nScreenWidth;
	int m_nScreenHeight;
	int m_nScreenSize;

public:
	void ChangeScreen();
	void ClearScreen();
	void FillScreen(int nStartX, int nStartY, char* sprite, int nSpriteWidth, int nSpriteHeight, bool isReverse);
	void FillScreen(int nStartX, int nStartY, char* sprite, int nSpriteWidth, int nSpriteHeight, bool isReverse, char chIgnoreColor);
	void FillScreen(int nStartX, int nStartY, char** sprite, int nEndX, int nEndY);
	void FillScreen(int nStartX, int nStartY, const char* string, int stringSize);
	void DrawScreen();

	DoubleBuffering(int nBasicColor, int nWidth, int nHeight, int nFontSize);
	~DoubleBuffering();
};

