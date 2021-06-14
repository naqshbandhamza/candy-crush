#define _WIN32_WINNT 0x0500 

#include <windows.h> 
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<cstring>

void myLine(int x1, int y1, int x2, int y2,COLORREF lineColor)
{

	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
	HPEN pen =CreatePen(PS_SOLID,2, lineColor); //2 is the width of the pen
    SelectObject(device_context,pen);
	MoveToEx(device_context,x1+250,y1,NULL);
    LineTo(device_context,x2+250, y2);
	DeleteObject(pen);

	ReleaseDC(console_handle, device_context);  
}
void myRect(int x1, int y1, int x2, int y2,COLORREF lineColor,COLORREF fillColor)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,2,lineColor); 
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(fillColor);
	SelectObject(device_context,brush);
	
	Rectangle(device_context,x1+250,y1,x2+250,y2);
	DeleteObject(pen);
	DeleteObject(brush);
	ReleaseDC(console_handle, device_context); 
}
void myEllipse(int x1, int y1, int x2, int y2,COLORREF lineColor,COLORREF fillColor)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,2,lineColor); 
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(fillColor);
	SelectObject(device_context,brush);
	Ellipse(device_context,x1+250,y1,x2+250,y2);
	DeleteObject(pen);
	DeleteObject(brush);	
	ReleaseDC(console_handle, device_context);

}

void myDrawText(int x,int y,int ht,int score,COLORREF lineColor,COLORREF fillColor)
{
	CHAR wstr[10]={'S','c','o','r','e',':'};
	int i = 9,num;
	while (score % 10 >= 10 && i>6)
	{
		num = score % 10;
		wstr[i] = num;
		score /= 10;
		i--;
	}
	wstr[6] = score;

	RECT rects;
	rects.left = x;
	rects.top = y;
	rects.right = x+ht;
	rects.bottom = y+ht;//(x,y,x+ht,y+ht);
	
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

	SetTextColor(device_context,lineColor);
	SetBkColor(device_context,fillColor);
	DrawText(device_context, wstr, -1, &rects, DT_TOP | DT_NOCLIP);

	ReleaseDC(console_handle, device_context);
  
}

void myDrawTextWithFont(int x,int y,int ht,char  str[],COLORREF lineColor,COLORREF fillColor)
{
	CHAR wstr[20]={};
	for (int i=0;i<20&&str[i];++i)
		wstr[i] = str[i];

	RECT rects;
	HFONT hFont;
	rects.left = x;
	rects.top = y;
	rects.right = x+ht;
	rects.bottom = y+ht;//(x,y,x+ht,y+ht);
	
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);
	hFont = CreateFont(ht,0,0,0,FW_DONTCARE,FALSE,TRUE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
			            CLIP_DEFAULT_PRECIS,1, VARIABLE_PITCH,TEXT("Impact"));
    SelectObject(device_context, hFont);

	SetTextColor(device_context,lineColor);
	SetBkColor(device_context,fillColor);
	DrawText(device_context,wstr,-1,&rects,DT_TOP|DT_NOCLIP);
	DeleteObject(hFont);   
	ReleaseDC(console_handle, device_context);
  
}

void mySetPixel(int x,int y,COLORREF colorVal)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);
	
	SetPixel(device_context,x,y,colorVal);
	ReleaseDC(console_handle,device_context);
}

void drawline(int x1, int y1, int x2, int y2, int choice)
{
	if (choice == 0)
	{
		for (int i = x1; i < x2; i++)
			mySetPixel(i, 0, RGB(255, 255, 255));
	}
}

void drawboard(int arr[][9])
{

	int arr2[9][9];

	for(int i = 0,c = 0; i<9; i++)
	{
		for (int j = 0, r = 0; j < 9; j++)
		{
			arr2[r][c] = arr[i][j];
			r++;
		}
		c++;
	}
	myRect(-250, -250, 0,417, RGB(204, 153, 153), RGB(204, 153, 153));
	myRect(406, 0, 702, 420, RGB(204, 153, 153), RGB(204, 153, 153));
	char st[] = { "CANDY" }, str[] = { "CRUSH" };
	myDrawTextWithFont(50, 150, 75, st, RGB(255, 255, 255),RGB(255,204,153));
	myDrawTextWithFont(735, 150, 75, str, RGB(255, 255, 255), RGB(255, 153, 51));
	int y,x;
	for (int i = 0; i < 9; i++) 
	{
		for (int j = 0; j < 9; j++) 
		{
			if (arr2[i][j] == 10) {
				myEllipse(i * 45, j * 45, (i * 45) + 45, (j * 45) + 45, RGB(100, 100, 100), RGB(139,0,0));
			}
			else if (arr2[i][j] == 11) {
				myEllipse(i * 45, j * 45, (i * 45) + 45, (j * 45) + 45, RGB(100, 100, 100), RGB(255, 255, 0));
			}
			else if (arr2[i][j] == 12) {
				myEllipse(i * 45, j * 45, (i * 45) + 45, (j * 45) + 45, RGB(100, 100, 100), RGB(0, 255, 0));
			}
			else if (arr2[i][j] == 13) {
				myEllipse(i * 45, j * 45, (i * 45) + 45, (j * 45) + 45, RGB(100, 100, 100), RGB(0, 0, 255));
			}
			else if (arr2[i][j] == 14) {
				myEllipse(i * 45, j * 45, (i * 45) + 45, (j * 45) + 45, RGB(100, 100, 100), RGB(255,69,0));
			}
			else if (arr2[i][j] == 15) {
				y = ((j * 45) + ((j * 45) + 45));
				myEllipse(i * 45, j * 45, (i * 45) + 45, (j * 45) + 45, RGB(100, 100, 100), RGB(139, 0, 0));
				myLine(i * 45, y / 2, (i * 45) + 45, y / 2, RGB(255, 255, 255));
			}
			else if (arr2[i][j] == 16) {
				y = ((j * 45) + ((j * 45) + 45));
				myEllipse(i * 45, j * 45, (i * 45) + 45, (j * 45) + 45, RGB(100, 100, 100), RGB(255, 255, 0));
				myLine(i * 45, y / 2, (i * 45) + 45, y / 2, RGB(255, 255, 255));
				
			}
			else if (arr2[i][j] == 17) {
				y = ((j * 45) + ((j * 45) + 45));
				myEllipse(i * 45, j * 45, (i * 45) + 45, (j * 45) + 45, RGB(100, 100, 100), RGB(0, 255, 0));
				myLine(i * 45, y / 2, (i * 45) + 45, y / 2, RGB(255, 255, 255));
			}
			else if (arr2[i][j] == 21) {
				x = ((i * 45) + ((i * 45) + 45));
				myEllipse(i * 45, j * 45, (i * 45) + 45, (j * 45) + 45, RGB(100, 100, 100), RGB(0, 0, 255));
				myLine(x/2, j * 45,x/2, (j * 45) + 45, RGB(255,255,255));
			}
			else if (arr2[i][j] == 22) {
				x = ((i * 45) + ((i * 45) + 45));
				myEllipse(i * 45, j * 45, (i * 45) + 45, (j * 45) + 45, RGB(100, 100, 100), RGB(255,69, 0));
				myLine(x / 2, j * 45, x / 2, (j * 45) + 45, RGB(255, 255, 255));
			}
			else if (arr2[i][j] == 18) {
				myRect(i * 45, j * 45, (i * 45) + 45, (j * 45) + 45, RGB(100, 100, 100), RGB(0, 0, 255));
				myEllipse(i * 45, j * 45, (i * 45) + 45, (j * 45) + 45, RGB(100, 100, 100), RGB(0, 0, 255));
			}
			else if (arr2[i][j] == 19) {
				myRect(i * 45, j * 45, (i * 45) + 45, (j * 45) + 45, RGB(100, 100, 100), RGB(255,69, 0));
				myEllipse(i * 45, j * 45, (i * 45) + 45, (j * 45) + 45, RGB(100, 100, 100), RGB(255,69, 0));
			}
			else if (arr2[i][j] == 23) {
				myRect(i * 45, j * 45, (i * 45) + 45, (j * 45) + 45, RGB(100, 100, 100), RGB(139, 0, 0));
				myEllipse(i * 45, j * 45, (i * 45) + 45, (j * 45) + 45, RGB(100, 100, 100), RGB(139, 0, 0));
			}
			else if (arr2[i][j] == 24) {
				myRect(i * 45, j * 45, (i * 45) + 45, (j * 45) + 45, RGB(100, 100, 100), RGB(255, 255, 0));
				myEllipse(i * 45, j * 45, (i * 45) + 45, (j * 45) + 45, RGB(100, 100, 100), RGB(255, 255, 0));
			}
			else if (arr2[i][j] == 25) {
				myRect(i * 45, j * 45, (i * 45) + 45, (j * 45) + 45, RGB(100, 100, 100), RGB(0, 255, 0));
				myEllipse(i * 45, j * 45, (i * 45) + 45, (j * 45) + 45, RGB(100, 100, 100), RGB(0, 255, 0));
			}
			else if (arr2[i][j] == 20) {
				myEllipse(i * 45, j * 45, (i * 45) + 45, (j * 45) + 45, RGB(100, 100, 100), RGB(139, 69, 19));
			}
			else if (arr2[i][j] == 99)
			{
				myRect(i * 45, j * 45, (i * 45) + 45, (j * 45) + 45, RGB(100, 100, 100), RGB(0, 0, 0));
			}
		}
	}
}


