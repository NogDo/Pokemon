#include "DoubleBuffering.h"

DoubleBuffering::DoubleBuffering(int nBasicColor, int nWidth, int nHeight, int nFontSize)
{
	m_nScreenIndex = 0;
	m_nBasicColor = nBasicColor;
	m_nScreenWidth = nWidth;
	m_nScreenHeight = nHeight;
	m_nScreenSize = m_nScreenWidth * m_nScreenHeight;

	m_charInfo = new CHAR_INFO[m_nScreenSize];
	m_size = { (short)(m_nScreenWidth), (short)(m_nScreenHeight) };
	m_rect = { 0, 0, (short)(m_nScreenWidth - 1), (short)(m_nScreenHeight - 1) };

	m_ScreenBuffer[0] = CreateConsoleScreenBuffer(GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	m_ScreenBuffer[1] = CreateConsoleScreenBuffer(GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	m_font.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	m_font.FontWeight = 900;
	m_font.dwFontSize.Y = nFontSize;

	SetConsoleScreenBufferSize(m_ScreenBuffer[0], m_size);
	SetConsoleWindowInfo(m_ScreenBuffer[0], TRUE, &m_rect);
	SetCurrentConsoleFontEx(m_ScreenBuffer[0], NULL, &m_font);

	SetConsoleScreenBufferSize(m_ScreenBuffer[1], m_size);
	SetConsoleWindowInfo(m_ScreenBuffer[1], TRUE, &m_rect);
	SetCurrentConsoleFontEx(m_ScreenBuffer[1], NULL, &m_font);


	for (int i = 0; i < m_nScreenSize; i++)
	{
		(m_charInfo + i)->Char.UnicodeChar = ' ';
		(m_charInfo + i)->Attributes = nBasicColor + nBasicColor * 15;
	}
}

DoubleBuffering::~DoubleBuffering()
{
	CloseHandle(m_ScreenBuffer[0]);
	CloseHandle(m_ScreenBuffer[1]);

	delete[] m_charInfo;
}

/// <summary>
/// 화면 버퍼 변경
/// </summary>
void DoubleBuffering::ChangeScreen()
{
	SetConsoleActiveScreenBuffer(m_ScreenBuffer[m_nScreenIndex]);

	m_nScreenIndex = 1 - m_nScreenIndex;
}

/// <summary>
/// 화면 버퍼 지우기
/// </summary>
void DoubleBuffering::ClearScreen()
{
	for (int i = 0; i < m_nScreenSize; i++)
	{
		(m_charInfo + i)->Char.UnicodeChar = ' ';
		(m_charInfo + i)->Attributes = m_nBasicColor + m_nBasicColor * 16;
	}

	DWORD dw;
	FillConsoleOutputCharacter(m_ScreenBuffer[m_nScreenIndex], ' ', m_nScreenWidth * m_nScreenHeight, m_size, &dw);
}

/// <summary>
/// 화면 버퍼 채우기
/// </summary>
/// <param name="nStartX"></param>
/// <param name="nStartY"></param>
/// <param name="sprite"></param>
/// <param name="nSpriteWidth"></param>
/// <param name="nSpriteHeight"></param>
/// <param name="isReverse"></param>
void DoubleBuffering::FillScreen(int nStartX, int nStartY, char* sprite, int nSpriteWidth, int nSpriteHeight, bool isReverse)
{
	const int nSpriteSize = nSpriteWidth * nSpriteHeight;
	int nSpriteWidthCount, nSpriteHeightCount;
	int nCurrentPos;

	if (isReverse)
	{
		nSpriteWidthCount = nSpriteWidth - 1;
	}

	else
	{
		nSpriteWidthCount = 0;
	}
	nSpriteHeightCount = 0;


	nCurrentPos = nStartY * m_nScreenWidth + nStartX;
	for (int i = 0; i < nSpriteSize; i++)
	{
		char* str = (char*)"□";
		(m_charInfo + nCurrentPos)->Char.UnicodeChar = str[0];
		(m_charInfo + nCurrentPos + 1)->Char.UnicodeChar = str[1];

		int color = *(sprite + nSpriteWidthCount + nSpriteHeightCount * nSpriteWidth);
		(m_charInfo + nCurrentPos)->Attributes = color + color * 16;
		(m_charInfo + nCurrentPos + 1)->Attributes = color + color * 16;

		if (isReverse)
		{
			nSpriteWidthCount--;

			if (nSpriteWidthCount < 0)
			{
				nSpriteWidthCount = nSpriteWidth - 1;
				nSpriteHeightCount++;
			}

			nCurrentPos = (nStartY + nSpriteHeightCount) * m_nScreenWidth + nStartX + ((nSpriteWidth - nSpriteWidthCount - 1) * 2);
		}

		else
		{
			nSpriteWidthCount++;

			if (nSpriteWidthCount == nSpriteWidth)
			{
				nSpriteWidthCount = 0;
				nSpriteHeightCount++;
			}

			nCurrentPos = (nStartY + nSpriteHeightCount) * m_nScreenWidth + nStartX + (nSpriteWidthCount * 2);
		}
	}
}

/// <summary>
/// 화면 버퍼 채우기 색 무시기능
/// </summary>
/// <param name="nStartX"></param>
/// <param name="nStartY"></param>
/// <param name="sprite"></param>
/// <param name="nSpriteWidth"></param>
/// <param name="nSpriteHeight"></param>
/// <param name="isReverse"></param>
/// <param name="chIgnoreColor"></param>
void DoubleBuffering::FillScreen(int nStartX, int nStartY, char* sprite, int nSpriteWidth, int nSpriteHeight, bool isReverse, char chIgnoreColor)
{
	int nSpriteSize;
	int nSpriteWidthCount, nSpriteHeightCount;
	int nCurrentPos;

	if (nStartY < 0)
	{
		nSpriteSize = nSpriteWidth * (nSpriteHeight + nStartY);
		nSpriteHeightCount = nSpriteHeight - (nSpriteHeight + nStartY);
		nCurrentPos = nStartX;
	}

	else
	{
		nSpriteSize = nSpriteWidth * nSpriteHeight;
		nSpriteHeightCount = 0;
		nCurrentPos = nStartY * m_nScreenWidth + nStartX;
	}


	if (isReverse)
	{
		nSpriteWidthCount = nSpriteWidth - 1;
	}

	else
	{
		nSpriteWidthCount = 0;
	}


	for (int i = 0; i < nSpriteSize; i++)
	{
		char* str = (char*)"□";
		(m_charInfo + nCurrentPos)->Char.UnicodeChar = str[0];
		(m_charInfo + nCurrentPos + 1)->Char.UnicodeChar = str[1];


		if (*(sprite + nSpriteWidthCount + nSpriteHeightCount * nSpriteWidth) != chIgnoreColor)
		{
			int color = *(sprite + nSpriteWidthCount + nSpriteHeightCount * nSpriteWidth);
			(m_charInfo + nCurrentPos)->Attributes = color + color * 16;
			(m_charInfo + nCurrentPos + 1)->Attributes = color + color * 16;
		}


		if (isReverse)
		{
			nSpriteWidthCount--;

			if (nSpriteWidthCount < 0)
			{
				nSpriteWidthCount = nSpriteWidth - 1;
				nSpriteHeightCount++;
			}

			nCurrentPos = (nStartY + nSpriteHeightCount) * m_nScreenWidth + nStartX + ((nSpriteWidth - nSpriteWidthCount - 1) * 2);
		}

		else
		{
			nSpriteWidthCount++;

			if (nSpriteWidthCount == nSpriteWidth)
			{
				nSpriteWidthCount = 0;
				nSpriteHeightCount++;
			}
			

			if (nStartY < 0)
			{
				nCurrentPos = (nSpriteHeightCount - (nSpriteHeight - (nSpriteHeight + nStartY))) * m_nScreenWidth + nStartX + (nSpriteWidthCount * 2);
			}

			else
			{
				nCurrentPos = (nStartY + nSpriteHeightCount) * m_nScreenWidth + nStartX + (nSpriteWidthCount * 2);
			}
		}
	}
}

/// <summary>
/// 화면 버퍼 채우기 2중배열
/// </summary>
/// <param name="nStartX"></param>
/// <param name="nStartY"></param>
/// <param name="sprite"></param>
/// <param name="nEndX"></param>
/// <param name="nEndY"></param>
void DoubleBuffering::FillScreen(int nStartX, int nStartY, char** sprite, int nEndX, int nEndY)
{
	for (int i = 0; i < nEndY - nStartY; i++)
	{
		for (int j = 0; j < nEndX - nStartX; j++)
		{
			char* str = (char*)"□";
			(m_charInfo + j * 2 + i * m_nScreenWidth)->Char.UnicodeChar = str[0];
			(m_charInfo + j * 2 + i * m_nScreenWidth + 1)->Char.UnicodeChar = str[1];

			int color = *(*(sprite + i + nStartY) + j + nStartX);
			(m_charInfo + j * 2 + i * m_nScreenWidth)->Attributes = color + color * 16;
			(m_charInfo + j * 2 + i * m_nScreenWidth + 1)->Attributes = color + color * 16;
		}
	}
}

/// <summary>
/// 화면 버퍼 채우기 문자열
/// </summary>
/// <param name="nStartX"></param>
/// <param name="nStartY"></param>
/// <param name="string"></param>
/// <param name="stringSize"></param>
void DoubleBuffering::FillScreen(int nStartX, int nStartY, const char* string, int stringSize)
{
	int nCurrentPos = nStartY * m_nScreenWidth + nStartX;
	for (int i = 0; i < stringSize;)
	{
		if (string[i] != ' ')
		{
			(m_charInfo + nCurrentPos)->Char.UnicodeChar = string[i];
			(m_charInfo + nCurrentPos + 1)->Char.UnicodeChar = string[i + 1];

			(m_charInfo + nCurrentPos)->Attributes = 0 + m_nBasicColor * 16;
			(m_charInfo + nCurrentPos + 1)->Attributes = 0 + m_nBasicColor * 16;

			i += 2;
		}

		else
		{
			(m_charInfo + nCurrentPos)->Char.UnicodeChar = string[i];
			(m_charInfo + nCurrentPos + 1)->Char.UnicodeChar = string[i];

			i++;
		}

		nCurrentPos += 2;
	}
}

/// <summary>
/// 화면 버퍼 그리기
/// </summary>
void DoubleBuffering::DrawScreen()
{
	COORD pos = { 0,0 };

	WriteConsoleOutputA(m_ScreenBuffer[m_nScreenIndex], m_charInfo, m_size, pos, &m_rect);
}