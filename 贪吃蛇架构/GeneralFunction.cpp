#include "GeneralFunction.h"
bool CheckButtonClick(int x, int y, const RECT& rect)
{
    return x >= rect.left && x <= rect.right &&
        y >= rect.top && y <= rect.bottom;
}

void DrawButton(const RECT& rect, COLORREF color, const TCHAR* text)
{
    setfillcolor(color);
    fillrectangle(rect.left, rect.top, rect.right, rect.bottom);
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy((rect.left + rect.right) / 2 - textwidth(text) / 2,
        (rect.top + rect.bottom) / 2 - textheight(text) / 2,
        text);
}

void DrawButton(const RECT& rect, COLORREF color, const TCHAR* text, bool isHover)
{
    // ������ͣʱ�����ű������Ŵ�110%��
    const float scale = isHover ? 1.1f : 1.0f;

    // ����ԭʼ��ť���ĵ�
    const int centerX = (rect.left + rect.right) / 2;
    const int centerY = (rect.top + rect.bottom) / 2;

    // �������ź�Ŀ��
    const int originalWidth = rect.right - rect.left;
    const int originalHeight = rect.bottom - rect.top;
    const int scaledWidth = static_cast<int>(originalWidth * scale);
    const int scaledHeight = static_cast<int>(originalHeight * scale);

    // �������ź���¾��Σ��������ĵ㲻�䣩
    const int newLeft = centerX - scaledWidth / 2;
    const int newTop = centerY - scaledHeight / 2;
    const int newRight = newLeft + scaledWidth;
    const int newBottom = newTop + scaledHeight;

    // �������ź�İ�ť����
    setfillcolor(color);
    fillrectangle(newLeft, newTop, newRight, newBottom);

    // ���ƾ������֣��������ź�ľ��Σ�
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(
        newLeft + (scaledWidth - textwidth(text)) / 2,
        newTop + (scaledHeight - textheight(text)) / 2,
        text
    );
}

// ���Ƶ������ؿؼ�
void drawToggleSwitch(const ToggleSwitch& sw, bool isPressed) {
    // ���ƻ��챳��
    setfillcolor(RGB(220, 220, 220));
    solidroundrect(sw.posX - sw.trackWidth / 2, sw.posY - 12,
        sw.posX + sw.trackWidth / 2, sw.posY + 12, 16, 16);

    // ���㻬��λ�ã���ƽ�����ɣ�
    int knobX = 0;
    if (isPressed)
    {
         knobX = sw.posX + sw.trackWidth / 2 - 16;
         setfillcolor(sw.onColor);
         solidcircle(knobX, sw.posY, 14);
    }
    else
    {
         knobX = sw.posX - sw.trackWidth / 2 + 16;
         setfillcolor(sw.offColor);
         solidcircle(knobX, sw.posY, 14);
    }
    /*int knobX = sw.isOn ?
        (sw.posX + sw.trackWidth / 2 - 16) :
        (sw.posX - sw.trackWidth / 2 + 16);*/

    // ���ƻ���
    /*setfillcolor(sw.isOn ? sw.onColor : sw.offColor);
    solidcircle(knobX, sw.posY, 14);*/

    // ��Ӹ߹�Ч��
    setlinecolor(WHITE);
    circle(knobX, sw.posY, 14);
}

// �������ֱ�ǩ
void drawTextLabel(const TCHAR* text, int x, int y) {
    settextcolor(YELLOW);
    settextstyle(30, 0, ("΢���ź�"));
    setbkmode(TRANSPARENT);
    outtextxy(x, y - 15, text);
}

// �������Ƿ�����������
bool checkToggleClick(const ToggleSwitch& sw, int mouseX, int mouseY) {
    // ��չ������򣨻�������ɵ����
    return (mouseX >= sw.posX - sw.trackWidth / 2 - 10) &&
        (mouseX <= sw.posX + sw.trackWidth / 2 + 10) &&
        (mouseY >= sw.posY - 24) &&
        (mouseY <= sw.posY + 24);
}

void button(int x, int y, int w, int h, char* text)
{
	setbkmode(TRANSPARENT);
	setfillcolor(GREEN);
	fillroundrect(x, y, x + w, y + h, 10, 10);
	// ����ַ�����MBCS �ַ�����
	char s1[10] = "����";
	settextstyle(30, 0, s1);

	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;

	outtextxy(tx, ty, text);

}


bool checkIsHover(int x, int y, const RECT& rect)
{
    return (x >= rect.left && x <= rect.right &&
        y >= rect.top && y <= rect.bottom);
}
void playBackMusic(bool musicOfAll)
{
    if (musicOfAll)
    {
        mciSendString("open ../GameMaterials/backmusic.wav", 0, 0, 0);
        mciSendString("play ../GameMaterials/backmusic.wav", 0, 0, 0);
    }

}
void playSoundDie(bool soundeEfect)
{
    if (soundeEfect)
    {
        mciSendString("open ../GameMaterials/deathsound.wav", 0, 0, 0);
        mciSendString("play ../GameMaterials/deathsound.wav", 0, 0, 0);
    }

}
void playSoundEat( bool soundEffect)
{
    if (soundEffect)
    {
        mciSendString("open ../GameMaterials/eatsound.mp3", 0, 0, 0);
        mciSendString("play ../GameMaterials/eatsound.mp3", 0, 0, 0);
    }

}



