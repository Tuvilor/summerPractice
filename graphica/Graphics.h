#pragma once

#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//=============================================================================

HWND hWnd; //������ �� ����

class Graphics
{
private:
	static HPEN hPen; //���������� ����
	static HBRUSH hBrush; //���������� �����
	static int wid, heg; //������ � ������ ���������� ������� ����
public:
	static HDC dc; //�������� ����������
	static void Set_pen(COLORREF, int); //�������� ���� (����, ������(� ��������))
	static void Set_brush(COLORREF, bool); //�������� ����� (����, 0 - ������ 1 - �������)
	static void Line(int, int, int, int); //���������� ����� (x1,y1 - ��������� �����, x2,y2 -  �������� �����)
	static void Point(int, int, COLORREF); //���������� ������ (x,y - ���������� ����� (� ��������), ����)
	static void Osi(); //���������� ���
	static int GetWid() { return wid; } //�������� ������ ���������� ������� ���� � ��������
	static int GetHeg() { return heg; } //�������� ������ ���������� ������� ���� � ��������

	static void InitGraphics(HWND); //���������������� ����������� ������
	~Graphics(); //����������
};
HBRUSH Graphics::hBrush = NULL;
HPEN Graphics::hPen = NULL;
HDC Graphics::dc = NULL;
int Graphics::wid = 1;
int Graphics::heg = 1;

void Graphics::InitGraphics(HWND hWnd)
{
	dc = GetDC(hWnd);
	RECT rect;
	GetClientRect(hWnd, &rect);
	wid = rect.right;
	heg = rect.bottom;
	Set_pen(RGB(255, 255, 255), 1);
	Set_brush(RGB(255, 255, 255), true);
}

Graphics::~Graphics()
{
	DeleteObject(hPen);
	DeleteObject(hBrush);
	ReleaseDC(hWnd, dc);
	DeleteDC(dc);
}
void Graphics::Set_pen(COLORREF col, int w)
{
	hPen = CreatePen(PS_INSIDEFRAME, w, col);
	SelectObject(dc, hPen);
}
void Graphics::Set_brush(COLORREF col, bool empty)
{
	empty ? hBrush = ::CreateSolidBrush(col) : 
			hBrush = ::CreateSolidBrush(NULL_BRUSH);
	::SelectObject(dc, hBrush);
}
void Graphics::Line(int x1, int y1, int x2, int y2)
{
	MoveToEx(dc, x1, y1, NULL);
	LineTo(dc, x2, y2);
}
void Graphics::Point(int x, int y, COLORREF col)
{
	SetPixel(dc, x, y, col);
}
void Graphics::Osi()
{
	Set_pen(RGB(80, 80, 80), 1);
	Line(0, heg / 2, wid - 1, heg / 2);
	Line(wid / 2, 0, wid / 2, heg - 1);
}


