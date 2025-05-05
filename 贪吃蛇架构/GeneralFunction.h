#pragma once 
#include <conio.h>
#include <functional>
#include <graphics.h>
#include <Windows.h>
#include <mmsystem.h>  // Windows ��Ƶͷ�ļ�
#pragma comment(lib, "Winmm.lib") // ������Ƶ��
bool CheckButtonClick(int x, int y, const RECT& rect);
void DrawButton(const RECT& rect, COLORREF color, const TCHAR* text, bool isHover);
void DrawButton(const RECT& rect, COLORREF color, const TCHAR* text);
struct ToggleSwitch
{
    bool isOn;             // ����״̬��true=������
    int posX;              // ��������X����
    int posY;              // ��������Y����
    int trackWidth;        // �����ܿ��
    COLORREF onColor;      // ����״̬��ɫ
    COLORREF offColor;     // �ر�״̬��ɫ
};
void drawToggleSwitch(const ToggleSwitch& sw, bool isPressed);
void drawTextLabel(const TCHAR* text, int x, int y);
bool checkToggleClick(const ToggleSwitch& sw, int mouseX, int mouseY); 
void button(int x, int y, int w, int h, char *text);
bool checkIsHover(int x, int y, const RECT& rect);
void playBackMusic(bool musicOfAll);
void playSoundDie(bool musicOfDie, bool soundeEfect);
void playSoundEat(bool musicOfEat, bool soundEffect);


