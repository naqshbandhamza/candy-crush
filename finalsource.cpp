#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <windows.h>
#include <stdio.h>
#include "button.h"

using namespace std;

void check_all_board(int arr[][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if( !(arr[i][j]>=10 && arr[i][j] <= 25) )
				arr[i][j] = rand() % 5 + 10;
		}
	}

}


void drawboard(int arr[][9], sf::RenderWindow& win, sf::RectangleShape list[][9], sf::Sprite& sprite,sf::RectangleShape & Cursor)
{
	sf::Vector2f pos;
	pos.x = 450; pos.y = 50;

	sf::SoundBuffer buffer;
	buffer.loadFromFile("crush.wav");

	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.setVolume(100);
	sound.setPitch(1);
	//sound.play();
	bool flag = true;

	sf::Sprite candylist[9][9];
	sf::Texture textlist[9][9];

	for (int i = 0; i < 9; i++)
	{
		pos.x = 450;
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == 10)
			{
				textlist[i][j].loadFromFile("simpleRed1.png");
				candylist[i][j].setTexture(textlist[i][j]);
				candylist[i][j].setPosition(pos);
			}
			else if (arr[i][j] == 11) {
				textlist[i][j].loadFromFile("simpleYellow1.png");
				candylist[i][j].setTexture(textlist[i][j]);
				candylist[i][j].setPosition(pos);
			}
			else if (arr[i][j] == 12) {
				textlist[i][j].loadFromFile("simpleGreen1.png");
				candylist[i][j].setTexture(textlist[i][j]);
				candylist[i][j].setPosition(pos);
			}
			else if (arr[i][j] == 13) {
				textlist[i][j].loadFromFile("simpleBlue1.png");
				candylist[i][j].setTexture(textlist[i][j]);
				candylist[i][j].setPosition(pos);
			}
			else if (arr[i][j] == 14) {
				textlist[i][j].loadFromFile("simpleOrange1.png");
				candylist[i][j].setTexture(textlist[i][j]);
				candylist[i][j].setPosition(pos);
			}
			else if (arr[i][j] == 15) {
				textlist[i][j].loadFromFile("stripedRed1.png");
				candylist[i][j].setTexture(textlist[i][j]);
				candylist[i][j].setPosition(pos);
			}
			else if (arr[i][j] == 16) {
				textlist[i][j].loadFromFile("strippedYellow1.png");
				candylist[i][j].setTexture(textlist[i][j]);
				candylist[i][j].setPosition(pos);
			}
			else if (arr[i][j] == 17) {
				textlist[i][j].loadFromFile("stripedGreen1.png");
				candylist[i][j].setTexture(textlist[i][j]);
				candylist[i][j].setPosition(pos);
			}
			else if (arr[i][j] == 21) {
				textlist[i][j].loadFromFile("stripedBlue1.png");
				candylist[i][j].setTexture(textlist[i][j]);
				candylist[i][j].setPosition(pos);
			}
			else if (arr[i][j] == 22) {
				textlist[i][j].loadFromFile("stripedOrange1.png");
				candylist[i][j].setTexture(textlist[i][j]);
				candylist[i][j].setPosition(pos);
			}
			else if (arr[i][j] == 18) {
				textlist[i][j].loadFromFile("wrappedBlue1.png");
				candylist[i][j].setTexture(textlist[i][j]);
				candylist[i][j].setPosition(pos);
			}
			else if (arr[i][j] == 19) {
				textlist[i][j].loadFromFile("wrappedOrange1.png");
				candylist[i][j].setTexture(textlist[i][j]);
				candylist[i][j].setPosition(pos);
			}
			else if (arr[i][j] == 23) {
				textlist[i][j].loadFromFile("wrappedRed1.png");
				candylist[i][j].setTexture(textlist[i][j]);
				candylist[i][j].setPosition(pos);
			}
			else if (arr[i][j] == 24) {
				textlist[i][j].loadFromFile("wrappedYellow1.png");
				candylist[i][j].setTexture(textlist[i][j]);
				candylist[i][j].setPosition(pos);
			}
			else if (arr[i][j] == 25) {
				textlist[i][j].loadFromFile("wrappedGreen1.png");
				candylist[i][j].setTexture(textlist[i][j]);
				candylist[i][j].setPosition(pos);
			}
			else if (arr[i][j] == 20) {
				textlist[i][j].loadFromFile("bomb1.png");
				candylist[i][j].setTexture(textlist[i][j]);
				candylist[i][j].setPosition(pos);
			}
			else if (arr[i][j] == 99)
			{

				if (flag)
				{
					sound.play();
					flag = false;
				}
				textlist[i][j].loadFromFile("black.png");
				candylist[i][j].setTexture(textlist[i][j]);
				candylist[i][j].setPosition(pos);
			}
			pos.x += 40;
		}
		pos.y += 40;
	}

	win.clear();
	win.draw(sprite);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			win.draw(list[i][j]);
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			win.draw(candylist[i][j]);
	}
	win.draw(Cursor);
	win.display();
}

void copyarray(int arr[][9],int arr2[][9])
{
	for(int i = 0; i<9;i++)
	{
		for (int j = 0; j < 9; j++)
			arr2[i][j] = arr[i][j];
	}
}

void checksame(int arr[][9], int row, int col)
{
	while (arr[row][col] == arr[row - 1][col] || arr[row][col] == arr[row + 1][col]
		|| arr[row][col] == arr[row][col + 1] || arr[row][col] == arr[row][col - 1])
	{
		arr[row][col] = rand() % 5 + 10;
	}
}

void clearWholeCol(int col, int arr[][9],int arr2[][9])
{
	for (int i = 0; i < 9; i++)
	{
		arr2[i][col] = 99;
		arr[i][col] = rand() % 5 + 10;
		checksame(arr, i, col);
	}
}

void clearWholeRow(int arr[][9],int arr2[][9], int row)
{
	for (int j = 0; j < 9; j++)
	{
		for (int i = row; i > 0; i--)
		{
			if(i==row)
				arr2[i][j] = 99;
			arr[i][j] = arr[i - 1][j];
		}
		if (row == 0)
			arr2[0][j] == 99;
		arr[0][j] = rand() % 5 + 10;
		checksame(arr, 0, j);
	}
}

void verticalshiftandadd(int sum, int row, int col, int arr[][9],int arr2[][9], int control_up, int control_down)
{
	for (int count = 0, R = control_up - 1, R1 = control_down; count < control_down - (sum - 1); count++)
	{
		if (R1 >= control_up && R1 <= control_down)
			arr2[R1][col] = 99;
		arr[R1][col] = arr[R][col];
		R--;
		R1--;
	}
	int d = control_down - sum + 1;
	int loopsize = control_down - d + 1;
	int num = 3;

	for (int i = 0; i < loopsize; i++)
	{
		if (i >= control_up && i <= control_down)
			arr2[i][col] = 99;
		arr[i][col] = rand() % 5 + 10;
		checksame(arr, i, col);
	}
}

void horizontal_Index(int& start_c, int& end_c, int sumh,
	int row, int col, int arr[][9])
{
	for (int i = 0, j = col; i < sumh; i++)
	{
		if (arr[row][j] != arr[row][j - 1])
		{
			start_c = j;
			i = sumh;
		}
		if (arr[row][j] == arr[row][j - 1] && j - 1 == 0)
		{
			start_c = j - 1;
			i = sumh;
		}
		j--;
	}
	end_c = start_c + sumh - 1;
}

void vertical_index(int& start_r, int& end_r, int sumv,
	int row, int col, int arr[][9])
{
	for (int i = 0, j = row; i < sumv; i++)
	{
		if (arr[j][col] != arr[j - 1][col])
		{
			start_r = j;
			i = sumv;
		}
		if (arr[j][col] == arr[j - 1][col] && j - 1 == 0)
		{
			start_r = j - 1;
			i = sumv;
		}
		j--;
	}
	end_r = start_r + sumv - 1;
}

int choose(int num,int choice) 
{
	//when choice is 2 then wrapped candy is replaced
	//when choice is 1 stripped candy is replaced
	//when choice is 3 color bomb is returned
	//when choice is 0 a special candy is returned
	if (choice == 2)
	{
		if (num == 10)
			return 23;
		else if (num == 11)
			return 24;
		else if (num == 12)
			return 25;
		else if (num == 13)
			return 18;
		else if (num == 14)
			return 19;
	}
	else if (choice == 1)
	{
		if (num == 10)
			return 15;
		else if (num == 11)
			return 16;
		else if (num == 12)
			return 17;
		else if (num == 13)
			return 21;
		else if (num == 14)
			return 22;
	}
	else if (choice == 3)
	{
		return 20;
	}
	if (choice == 0)
	{
		if (num == 15 || num == 23)
			return 10;
		else if (num == 16 || num == 24)
			return 11;
		else if (num == 17 || num == 25)
			return 12;
		else if (num == 18 || num == 21)
			return 13;
		else if (num == 22 || num == 19)
			return 14;
	}
	if(choice==4)
	{
		if (num == 10)
			return 30;
		else if (num == 11)
			return 30;
		else if (num == 12)
			return 40;
		else if (num == 13)
			return 50;
		else if (num == 14)
			return 60;
	}
	if(choice==5)
	{
		if (num == 15 || num == 23)
			return 10;
		else if (num == 16 || num == 24)
			return 11;
		else if (num == 17 || num == 25)
			return 12;
		else if (num == 18 || num == 21)
			return 13;
		else if (num == 22 || num == 19)
			return 14;
	}
}

void burstTL(int sumv, int row, int col,int arr[][9],int arr2[][9],int sum)
{
	int start_r, end_r, temp,control;
	vertical_index(start_r, end_r, sumv, row, col, arr);
	if (sumv == sum)
	{
		temp = choose(arr[row][col],2);
		control = end_r - 1;
	}
	else
		control = end_r;
	for (int count = 0, r = start_r - 1, r1 = control; count < end_r - (sumv - 1); count++)
	{
		if(r1>=start_r && r1<=end_r)
			arr2[r1][col] = 99;
		arr[r1][col] = arr[r][col];
		r--;
		r1--;
	}
	int d = end_r - sumv + 1;
	int loopsize = end_r - d + 1;
	if (sumv == sum)
	{
		arr2[end_r][col] = temp;
		arr[end_r][col] = temp;
	}
	int num = 3;
	if (sumv == sum)
	{
		for (int count = 0; count < loopsize - 1; count++)
		{
			if (count >= start_r && count <= end_r)
				arr2[count][col] = 99;
			arr[count][col] = rand() % 5 + 10;
			checksame(arr, count, col);
		}
	}
	else 
	{
		for (int count = 0; count < loopsize; count++)
		{
			if (count >= start_r && count <= end_r)
				arr2[count][col] = 99;
			arr[count][col] = rand() % 5 + 10;
			checksame(arr, count, col);
		}
	}
}

void burstH(int sumh, int row, int col, int arr[][9],int arr2[][9])
{
	int start_c, end_c,temp,points;
	horizontal_Index(start_c, end_c,sumh,row,col,arr);

	for (int count = 0,c = start_c; count < sumh; count++) 
	{
		if(sumh>3)
			if (c == col)
			{
				if (sumh == 4)
				{
					temp = choose(arr[row][col], 1);
				}
				else if (sumh >= 5)
				{
					temp = choose(arr[row][col], 3);
				}
			}
		for (int count1 = 0,r = row; count1 < row; count1++) 
		{
			if (sumh > 3)
			{
				if (c != col)
				{
				  arr[r][c] = arr[r - 1][c];
				}
			}
			else
			{
				arr[r][c] = arr[r - 1][c];
			}
			r--;
		}
		if (sumh > 3)
		{
			if (c != col)
			{
				arr2[row][c] = 99;
				arr[0][c] = rand() % 5 + 10;
				checksame(arr, 0, c);
			}
			else
			{
				if (sumh == 4)
				{
					temp = choose(arr[row][col], 1);
				}
				else if (sumh >= 5)
				{
					temp = choose(arr[row][col], 3);
				}
				arr2[row][col] = temp;
				arr[row][col] = temp;
			}
		}
		else
		{
			arr2[row][c] = 99;
			arr[0][c] = rand() % 5 + 10;
			checksame(arr, 0, c);
		}
		c++;
	}
}

void burstV(int sumv, int row, int col, int arr[][9],int arr2[][9]) 
{
    int start_r, end_r,control,temp,points;
	vertical_index(start_r, end_r, sumv, row, col, arr);
	if (sumv == 3)
	{
		control = end_r;
	}
	else if (sumv > 3)
	{
		control = end_r - 1;
		if (sumv == 4)
		{
			temp = choose(arr[row][col], 1);
		}
		else if (sumv >= 5)
		{
			temp = choose(arr[row][col], 3);
		}
	}
		for (int count = 0, r = start_r-1,r1 = control; count < end_r-(sumv-1); count++)
		{
			if(r1>=start_r && r1<=end_r)
				arr2[r1][col] = 99;
			arr[r1][col] = arr[r][col];
			r--;
			r1--;
		}
		int d = end_r - sumv + 1;
		int loopsize = end_r - d + 1;
		int num = 3;
		if (sumv > 3)
		{
			/*if (sumv == 4)
			{
				temp = choose(arr[row][col], 1);
			}
			else if (sumv >= 5)
			{
				temp = choose(arr[row][col], 3);
			}*/
			arr2[end_r][col] = temp;
			arr[end_r][col] = temp;
			for (int i = 0; i < loopsize - 1; i++)
			{
				if (i >= start_r && i <= end_r)
					arr2[i][col] = 99;
				arr[i][col] = rand() % 5 + 10;
				checksame(arr, i, col);
			}
		}
		else 
		{
			for (int i = 0; i < loopsize; i++)
			{
				if (i >= start_r && i <= end_r)
					arr2[i][col] = 99;
				arr[i][col] = rand() % 5 + 10;
				checksame(arr, i, col);
			}
		}
}

void burstVH(int sumv,int sumh,int row, int col, int arr[][9],int arr2[][9]) 
{
	int start_c, end_c,start_r,end_r,s;
	horizontal_Index(start_c, end_c, sumh, row, col, arr);
	vertical_index(start_r, end_r, sumv, row, col, arr);
	for (int count = 0, i = row, j = start_c; count < sumh; count++) 
	{
		if (i == row && j == col)
			s = sumv;
		else
			s = 1;
		burstTL(s, i, j,arr,arr2,sumv);
		j++;
	}
}

int wrappedstriped(int arr[][9],int arr2[][9],int row,int col) 
{
	int row_size,col_size;
	if (col == 0 && row > 0 && row < 8)
	{
		col_size = 2;
		row_size = 3;
		for (int j = 0; j < col_size; j++)
			clearWholeCol(j, arr,arr2);
		for (int i = row, j = col + 2; j < 9; j++)
			verticalshiftandadd(3, i, j, arr,arr2, i - 1, i + 1);
	}else if(col>0 && col<8 && row>0 && row<8)
	{
		col_size = 3;
		row_size = 3;
		for (int j = col - 1; j < col + 2; j++)
			clearWholeCol(j, arr,arr2);
		int out_c = 0,control;
		while (out_c < 2) 
		{
			if (out_c == 0)
			{
				control = col - 1;
				for (int j = 0, i = row; j < control; j++)
					verticalshiftandadd(3, i, j, arr,arr2, i - 1, i + 1);
			}
			else 
			{
				control = 9;
				for(int j = col+2,i=row;j<control;j++)
					verticalshiftandadd(3, i, j, arr,arr2, i - 1, i + 1);
			}
			out_c++;
		}
	}
	else if (col == 8 && row > 0 && row < 8) 
	{
		col_size = 2;
		row_size = 3;
		for (int j = 8, count = 0; count < col_size; count++)
		{
			clearWholeCol(j, arr,arr2);
			j--;
		}
		for (int i = row, j = 0; j < 7; j++)
			verticalshiftandadd(3, i, j, arr,arr2, i - 1, i + 1);
	}
	else if ((row == 0 && col == 0) || (row == 0 && col == 8))
	{
		int i, j,control;
		col_size = 2;
		row_size = 2;
		if (col == 0)
		{
			j = 0;
			i = 2;
			control = 9;
		}else
		{
			j = 7;
			i = 0;
			control = 7;
		}
		for (int count = 0; count < col_size; count++) 
		{
			clearWholeCol(j, arr,arr2);
			j++;
		}
		int out_c = 0;
		while (out_c < row_size)
		{
			for (i; i < control; i++)
			{
				verticalshiftandadd(2, out_c, i, arr,arr2, 0, 1);
			}
			out_c++;
		}
	}
	else if ((row == 8 && col == 0)||(row == 8 && col == 8))
	{
		col_size = 2;
		row_size = 2;
		int i, j, control;
		col_size = 2;
		row_size = 2;
		if (col == 0)
		{
			j = 0;
			i = 2;
			control = 9;
		}
		else
		{
			j = 7;
			i = 0;
			control = 7;
		}
		for (int count = 0; count < col_size; count++)
		{
			clearWholeCol(j, arr,arr2);
			j++;
		}
		int out_c = 0,o = 7;
		while (out_c < row_size)
		{
			for (i; i < control; i++)
			{
				verticalshiftandadd(2, o, i, arr,arr2, 7, 8);
			}
			out_c++;
			o++;
		}
	}
	else if ((row == 0 || row == 8) && (col > 0 && col < 8)) 
    {    
	     int i, j,control_up,control_down;
	     row_size = 2;
	     col_size = 3;
		
		 if (row == 0)
			 control_up = row, control_down = row + 1;
		 else
			 control_up = row - 1, control_down = row;
		 for(i = col-1;i<col+2;i++)
		 {
			 clearWholeCol(i, arr,arr2);
		 }

		 int out_c = 0, control;
		 while (out_c < 2)
		 {
			 if (out_c == 0)
			 {
				 control = 9 - (col + 2);
				 for (int j = col-2, i = row; j >=0; j--)
					 verticalshiftandadd(2, i, j, arr,arr2, control_up,control_down);
			 }
			 else
			 {
				 control = 9;
				 for (int j = col + 2, i = row; j < control; j++)
					 verticalshiftandadd(2, i, j, arr,arr2, control_up,control_down);
			 }
			 out_c++;
		 }
	}
	return 1;
}

int wrappedwrapped(int arr[][9],int arr2[][9],int r1,int c1,int r2,int c2,int choice)
{
	//choice 1 horizontal combination
	//choice 2 vertical combination
	int rc, lc,j,k,topr,botr,sum;
	if (choice == 1)
	{
			if (c1 > c2)
				rc = c1, lc = c2;
			else
				rc = c2, lc = c1;
			j = lc, topr = r1;
			for (int count = 0; count < 2; count++)
			{
				if (topr != 0)
					topr--;

				if (j!=0)
					j--;
			}
			k = rc, botr = r1;
			for (int count = 0; count < 2; count++)
			{
				if (k != 8)
					k++;
				if (botr != 8)
					botr++;
			}
			sum = (botr - topr) + 1;
		if ((r1 == 0 && c1 == 0) || (r1 == 0 && c1 == 8) || (r1 == 0 && c1 > 0 && c1 < 8)
			|| (r2 == 0 && c2 == 0) || (r2 == 0 && c2 > 0 && c2 < 8) || (r2 == 0 && c2 > 0 && c2 < 8)
			)
		{
			if (c1==0 || c2==0)
			{
				for (int count = 0; count < 4; count++)
					verticalshiftandadd(3,0,count,arr,arr2,0,2);
			}
			else if( (c1>0 && c1<8) || (c2>0 && c2<8) )
			{
				for (int count=j; count <k+1;count++)
					verticalshiftandadd(3,0,count,arr,arr2,0,2);
			}
			else
			{
				for (int count= 8; count > 4; count--)
					verticalshiftandadd(3,0,count,arr,arr2,0,2);
			}
		}
		else if ((r1>0 && r1<8 && c1 == 0) || (r1 > 0 && r1 < 8 && c1 == 8) || (r1 > 0 && r1 < 8 && c1 > 0 && c1 < 8)
			|| (r2 > 0 && r2 < 8 && c2 == 0) || (r2 > 0 && r2 < 8 && c2==8) || (r2 > 0 && r2 < 8 && c2 > 0 && c2 < 8)
			)
		{
			if (c1==0||c2==0)
			{
				for (int count=0; count<4; count++)
					verticalshiftandadd(sum,r1,count,arr,arr2,topr,botr);
			}
			else if( (c1>0 && c1<8) || (c2>0 && c2 < 8) )
			{
				for (int count=j; count<k+1;count++)
					verticalshiftandadd(sum,r1,count,arr,arr2,topr,botr);
			}
			else
			{
				for (int count=8;count>4;count--)
					verticalshiftandadd(sum,r1,count,arr,arr2,topr,botr);
			}
		}
		else if ((r1 == 8 && c1 == 0) || (r1 == 8 && c1 == 8) || (r1 == 8 && c1 > 0 && c1 < 8)
			|| (r2 == 8 && c2 == 0) || (r2 == 8 && c2 == 8) || (r2 == 8 && c2 > 0 && c2 < 8)
			)
		{
			if (c1==0 || c2==0)
			{
				for (int count=0;count<4;count++)
					verticalshiftandadd(3,r1,count,arr,arr2,6,8);
			}
			else if( (c1>0 && c1<8) || (c2 > 0 && c2 < 8) )
			{
				for (int count=j;count<k+1;count++)
					verticalshiftandadd(3,r1,count,arr,arr2,6,8);
			}
			else
			{
				for (int count=8;count>4;count--)
					verticalshiftandadd(3,r1,count,arr,arr2,6,8);
			}
		}
	}
	else if (choice == 2)
	{
		if (r1 > r2)
			topr = r2,botr = r1;
		else
			topr = r1,botr= r2;
		lc = c1,j= c1;
		for (int count = 0; count < 2; count++)
		{
			if (topr != 0)
				topr--;

			if (j != 0)
				j--;
		}
		rc= c1, k = c1;
		for (int count = 0; count < 2; count++)
		{
			if (k != 8)
				k++;
			if (botr != 8)
				botr++;
		}
		sum = (botr - topr) + 1;
		if ((r1 == 0 && c1 == 0) || (r1 == 0 && c1 == 8) || (r1 == 0 && c1 > 0 && c1 < 8)
			|| (r2 == 0 && c2 == 0) || (r2 == 0 && c2 > 0 && c2 < 8) || (r2 == 0 && c2 > 0 && c2 < 8)
			)
		{
			if (c1 == 0 || c2 == 0)
			{
				for (int count = 0; count < 3; count++)
					verticalshiftandadd(4, 0, count, arr,arr2, 0, 3);
			}
			else if ((c1 > 0 && c1 < 8) || (c2 > 0 && c2 < 8))
			{
				for (int count = j; count < k + 1; count++)
					verticalshiftandadd(4, 0, count, arr,arr2, 0, 3);
			}
			else
			{
				for (int count = 8; count > 5; count--)
					verticalshiftandadd(4, 0, count, arr,arr2, 0, 3);
			}
		}
		else if ((r1 > 0 && r1 < 8 && c1 == 0) || (r1 > 0 && r1 < 8 && c1 == 8) || (r1 > 0 && r1 < 8 && c1 > 0 && c1 < 8)
			|| (r2 > 0 && r2 < 8 && c2 == 0) || (r2 > 0 && r2 < 8 && c2 == 8) || (r2 > 0 && r2 < 8 && c2 > 0 && c2 < 8)
			)
		{
			if (c1 == 0 || c2 == 0)
			{
				for (int count = 0; count < 3; count++)
					verticalshiftandadd(sum, r1, count, arr,arr2, topr, botr);
			}
			else if ((c1 > 0 && c1 < 8) || (c2 > 0 && c2 < 8))
			{
				for (int count = j; count < k + 1; count++)
					verticalshiftandadd(sum, r1, count, arr,arr2, topr, botr);
			}
			else
			{
				for (int count = 8; count > 5; count--)
					verticalshiftandadd(sum, r1, count, arr,arr2, topr, botr);
			}
		}
		else if ((r1 == 8 && c1 == 0) || (r1 == 8 && c1 == 8) || (r1 == 8 && c1 > 0 && c1 < 8)
			|| (r2 == 8 && c2 == 0) || (r2 == 8 && c2 == 8) || (r2 == 8 && c2 > 0 && c2 < 8)
			)
		{
			if (c1 == 0 || c2 == 0)
			{
				for (int count = 0; count < 3; count++)
					verticalshiftandadd(4, r1, count, arr,arr2, 5, 8);
			}
			else if ((c1 > 0 && c1 < 8) || (c2 > 0 && c2 < 8))
			{
				for (int count = j; count < k + 1; count++)
					verticalshiftandadd(4, r1, count, arr,arr2, 5, 8);
			}
			else
			{
				for (int count = 8; count > 5; count--)
					verticalshiftandadd(4, r1, count, arr,arr2, 5, 8);
			}
		}
	}
return 1;
}

int PlainWrappedcandy(int arr[][9],int arr2[][9], int row, int col,int choice,int sumMain)
{
	if (sumMain >= 3 )
	{
		//choice 1 horizontal combination
		//choice 2 vertical combination
		int start_c, end_c, start_r, end_r, control_up = -1, control_down = -1, sum;
		if (choice == 1)
		{
			int c = -1;
			horizontal_Index(start_c, end_c, 3, row, col, arr);
			if (col == start_c)
				c = col + 2;
			else if (col == end_c)
				c = col - 2;

			if (c != -1)
			{
				for (int i = row; i > 0; i--)
				{
					if (i == row)
						arr2[i][c] = 99;
					arr[i][c] = arr[i - 1][c];
				}
				arr[0][c] = rand() % 5 + 10;
				checksame(arr, 0, col);
			}
			if ((row == 0 && col == 0) || (row == 0 && col > 0 && col < 8)
				|| (row == 0 && col == 8))
			{
				if (col == 0)
				{
					for (int j = col; j < col + 2; j++)
						verticalshiftandadd(2, row, j, arr,arr2, row, row + 1);
				}
				else if (col > 0 && col < 8)
				{
					for (int j = col - 1; j < col + 2; j++)
						verticalshiftandadd(2, row, j, arr,arr2, row, row + 1);
				}
				else
				{
					for (int j = col - 1; j < col + 1; j++)
						verticalshiftandadd(2, row, j, arr,arr2, row, row + 1);
				}
			}
			else if ((row > 0 && row < 8 && col == 0) || (row > 0 && row < 8 && col>0 && col < 8)
				|| (row > 0 && row < 8 && col == 8))
			{
				if (col == 0)
				{
					for (int j = col; j < col + 2; j++)
						verticalshiftandadd(3, row, j, arr,arr2, row - 1, row + 1);
				}
				else if (col > 0 && col < 8)
				{
					for (int j = col - 1; j < col + 2; j++)
						verticalshiftandadd(3, row, j, arr,arr2, row - 1, row + 1);
				}
				else
				{
					for (int j = col - 1; j < col + 1; j++)
						verticalshiftandadd(3, row, j, arr,arr2, row - 1, row + 1);
				}
			}
			else if ((row == 8 && col == 0) || (row == 8 && col > 0 && col < 8)
				|| (row == 8 && col == 8))
			{
				if (col == 0)
				{
					for (int j = col; j < col + 2; j++)
						verticalshiftandadd(2, row, j, arr,arr2, row - 1, row);
				}
				else if (col > 0 && col < 8)
				{
					for (int j = col - 1; j < col + 2; j++)
						verticalshiftandadd(2, row, j, arr,arr2, row - 1, row);
				}
				else
				{
					for (int j = col - 1; j < col + 1; j++)
						verticalshiftandadd(2, row, j, arr,arr2, row - 1, row);
				}
			}
		}
		else if (choice == 2)
		{
			int r = -1, control_up, control_down, sum;
			vertical_index(start_r, end_r, 3, row, col, arr);
			if (row == start_r)
			{
				control_up = row - 1;
				control_down = row + 2;
				sum = 4;
			}
			else if (row == end_r)
			{
				control_up = row - 2;
				control_down = row + 1;
				sum = 4;
			}
			else
			{
				control_up = row - 1;
				control_down = row + 1;
				sum = 3;
			}
			if ((row == 0 && col == 0) || (row == 0 && col > 0 && col < 8)
				|| (row == 0 && col == 8))
			{
				if (col == 0)
				{
					for (int j = col; j < col + 2; j++)
					{
						if (j == col)
							verticalshiftandadd(3, row, j, arr,arr2, row, row + 2);
						else
							verticalshiftandadd(2, row, j, arr,arr2, row, row + 1);
					}
				}
				else if (col > 0 && col < 8)
				{
					for (int j = col - 1; j < col + 2; j++)
					{
						if (j == col)
							verticalshiftandadd(3, row, j, arr,arr2, row, row + 2);
						else
							verticalshiftandadd(2, row, j, arr,arr2, row, row + 1);
					}
				}
				else
				{
					for (int j = col - 1; j < col + 1; j++)
					{
						if (j == col)
							verticalshiftandadd(3, row, j, arr,arr2, row, row + 2);
						else
							verticalshiftandadd(2, row, j, arr,arr2, row, row + 1);
					}
				}
			}
			else if ((row > 0 && row < 8 && col == 0) || (row > 0 && row < 8 && col > 0 && col < 8)
				|| (row > 0 && row < 8 && col == 8))
			{
				if (col == 0)
				{
					for (int j = col; j < col + 2; j++)
					{
						if (j == col)
							verticalshiftandadd(sum, row, j, arr,arr2, control_up, control_down);
						else
							verticalshiftandadd(3, row, j, arr,arr2, row - 1, row + 1);
					}
				}
				else if (col > 0 && col < 8)
				{
					for (int j = col - 1; j < col + 2; j++)
					{
						if (j == col)
							verticalshiftandadd(sum, row, j, arr,arr2, control_up, control_down);
						else
							verticalshiftandadd(3, row, j, arr,arr2, row - 1, row + 1);
					}
				}
				else
				{
					for (int j = col - 1; j < col + 1; j++)
					{
						if (j == col)
							verticalshiftandadd(sum, row, j, arr,arr2, control_up, control_down);
						else
							verticalshiftandadd(3, row, j, arr,arr2, row - 1, row + 1);
					}
				}
			}
			else if ((row == 8 && col == 0) || (row == 8 && col > 0 && col < 8)
				|| (row == 8 && col == 8))
			{
				if (col == 0)
				{
					for (int j = col; j < col + 2; j++)
					{
						if (j == col)
							verticalshiftandadd(3, row, j, arr,arr2, row - 2, row);
						else
							verticalshiftandadd(2, row, j, arr,arr2, row - 1, row);
					}
				}
				else if (col > 0 && col < 8)
				{
					for (int j = col - 1; j < col + 2; j++)
					{
						if (j == col)
							verticalshiftandadd(3, row, j, arr,arr2, row - 2, row);
						else
							verticalshiftandadd(2, row, j, arr,arr2, row - 1, row);
					}
				}
				else
				{
					for (int j = col - 1; j < col + 1; j++)
					{
						if (j == col)
							verticalshiftandadd(3, row, j, arr,arr2, row - 2, row);
						else
							verticalshiftandadd(2, row, j, arr,arr2, row - 1, row);
					}
				}
			}
		}
        else if (choice == 0)
	    {
	       if ((row == 0 && col == 0) || (row == 0 && col > 0 && col < 8)
		     || (row == 0 && col == 8))
	       {
		   if (col == 0)
		   {
			for (int j = col; j < col + 2; j++)
				verticalshiftandadd(2, row, j, arr, arr2, row, row + 1);
		   }
		   else if (col > 0 && col < 8)
		   {
			for (int j = col - 1; j < col + 2; j++)
				verticalshiftandadd(2, row, j, arr, arr2, row, row + 1);
		   }
		   else
		   {
			for (int j = col - 1; j < col + 1; j++)
				verticalshiftandadd(2, row, j, arr, arr2, row, row + 1);
		   }
	       }
	       else if ((row > 0 && row < 8 && col == 0) || (row > 0 && row < 8 && col>0 && col < 8)
		    || (row > 0 && row < 8 && col == 8))
	            {
		        if (col == 0)
		        {
			    for (int j = col; j < col + 2; j++)
				verticalshiftandadd(3, row, j, arr, arr2, row - 1, row + 1);
		        }
		        else if (col > 0 && col < 8)
		        {
			    for (int j = col - 1; j < col + 2; j++)
				verticalshiftandadd(3, row, j, arr, arr2, row - 1, row + 1);
		        }
		        else
		        {
			    for (int j = col - 1; j < col + 1; j++)
				verticalshiftandadd(3, row, j, arr, arr2, row - 1, row + 1);
		        }
	    }
	    else if ((row == 8 && col == 0) || (row == 8 && col > 0 && col < 8)
		|| (row == 8 && col == 8))
	    {
		if (col == 0)
		{
			for (int j = col; j < col + 2; j++)
				verticalshiftandadd(2, row, j, arr, arr2, row - 1, row);
		}
		else if (col > 0 && col < 8)
		{
			for (int j = col - 1; j < col + 2; j++)
				verticalshiftandadd(2, row, j, arr, arr2, row - 1, row);
		}
		else
		{
			for (int j = col - 1; j < col + 1; j++)
				verticalshiftandadd(2, row, j, arr, arr2, row - 1, row);
		}
	    }
	    }
		return 1;
	}
    else
    {
        cout << "not allowed";
        return 0;
    }
}

int PlainStripped(int arr[][9],int arr2[][9], int row, int col,int sum, int num, int choice,int sumMain)
{
	if (sumMain >= 3)
	{
		//choice 1 horizontal combination
		//choice 2 vertical combination
		// 15,16 and 17 have horizontal stripes
		//21 and 22 have vertical stripes
		int start_r, end_r, start_c, end_c;
		if (num == 15 || num == 16
			|| num == 17)
		{
			if (choice == 1)
			{
				clearWholeRow(arr,arr2, row);
			}
			else if (choice == 2)
			{
				for (int j = 0; j < 9; j++)
				{
					if (j != col)
					{
						for (int i = row; i > 0; i--)
						{
							if(i==row)
								arr2[i][j] = 99;
							arr[i][j] = arr[i - 1][j];
						}
						arr[0][j] = rand() % 5 + 10;
						checksame(arr, 0, j);
					}
					else
						burstV(sum, row, col, arr,arr2);
				}
			}
		}
		else if (num == 21 || num == 22)
		{
			if (choice == 1)
			{
				horizontal_Index(start_c, end_c, 3, row, col, arr);
				for (int j = start_c, count = 0; count < sum; count++)
				{
					if (j != col)
					{
						for (int i = row; i > 0; i--)
						{
							if(i==row)
								arr2[i][j] = 99;
							arr[i][j] = arr[i - 1][j];
						}
						arr[0][j] = rand() % 5 + 10;
						checksame(arr, 0, j);
					}
					else
						clearWholeCol(col, arr,arr2);
					j++;
				}
			}
			else if (choice == 2)
			{
				clearWholeCol(col, arr,arr2);
			}
		}
		return 1;
	}
	else
	{
		cout << "not allowed";
		return 0;
	}
}

int burst(int arr[][9],int arr2[][9], int length, int r1, int c1,
	int r2, int c2)
{
	cout << "here in burst" << endl;
	int leftC = 0, rightC = 8, topR = 0, bottomR = 8,
		diff,term= 1,sumv = 0,sumh = 0,s = 0,num,temp;
	int out_count = 0;
	while (out_count < 2) 
	{
		int r, c;
		if (out_count == 0)
			r = r1, c = c1;
		else
			r = r2, c = c2;
		num = arr[r][c];
		if (arr[r][c] == 15 || arr[r][c] == 16 || arr[r][c] == 17 ||
			arr[r][c] == 23 || arr[r][c] == 24 || arr[r][c] == 25 ||
			arr[r][c] == 18 || arr[r][c] == 21 || arr[r][c] == 22 ||
			arr[r][c] == 19)
		{
			temp = choose(arr[r][c], 0);
			arr[r][c] = temp;
		}
		
		for (int count = 0; count < 4; count++)
		{
			if (count == 0)
			{
				diff = c - leftC;
				for (int count = 0,j = r,k = c; count < diff; count++) 
				{
					if (arr[j][k] == arr[j][k - 1]) 
					{
						k--;
						term += 1;
					}
					else
						count = diff;
				}
				sumh+=term;
				term = 1;
			}
			else if (count == 1) 
			{
				diff = rightC - c;
				for (int count = 0, j = r, k = c; count < diff; count++)
				{
					if (arr[j][k] == arr[j][k + 1])
					{
						k++;
						term += 1;
					}
					else
						count = diff;
				}
				if (sumh >= 3)
					sumh += term-1;
				else if (sumh < 3 && term >= 3)
					sumh += term-1;
				else if (sumh < 3 && term < 3 && sumh+term>=3)
					sumh+=term-1;
				term = 1;
			}
			else if (count == 2) 
			{
				diff = r - topR;
				for (int count = 0, j = r, k = c; count < diff; count++)
				{
					if (arr[j][k] == arr[j - 1][k])
					{
						j--;
						term += 1;
					}
					else
						count = diff;
				}
				sumv+=term;
				term = 1;
			}
			else if (count == 3)
			{
				diff = bottomR - r;
				for (int count = 0, j = r, k = c; count < diff; count++)
				{
					if (arr[j][k] == arr[j+1][k])
					{
						j++;
						term += 1;
					}
					else
						count = diff;
				}
				if (sumv >= 3)
					sumv += term-1;
				else if (sumv < 3 && term >= 3)
					sumv += term-1;
				else if (sumv < 3 && term < 3 && sumv+term>=3)
					sumv+= term-1;
				term = 1;
			}
		}
		if (sumh >= 3 && sumv < 3)
		{
			if ((num == 15 || num == 16 || num == 17
				|| num == 21 || num == 22)&&arr[r][c]==temp)
				s = PlainStripped(arr,arr2, r, c, sumh, num, 1,sumh);
			else if (num == 23 || num == 24 || num == 25
				|| num == 18 || num == 19)
			{
				s = PlainWrappedcandy(arr, arr2, r, c, 1, sumh);
			}
			else
			{
				cout << "here in burst h" << endl;
				burstH(sumh, r, c, arr,arr2);
				s = 1;
			}
		}
		else if (sumv >= 3 && sumh < 3)
		{
			if (num == 15 || num == 16 || num == 17
				|| num == 21 || num == 22)
				s = PlainStripped(arr,arr2, r, c, sumv, num, 2,sumv);
			else if ((num == 23 || num == 24 || num == 25
				|| num == 18 || num == 19) && arr[r][c] == temp)
			{
				s = PlainWrappedcandy(arr, arr2, r, c, 2, sumv);
			}
			else
			{
				burstV(sumv, r, c, arr,arr2);
				s = 1;
			}
		}
		else if (sumh >= 3 && sumv >= 3)
		{
			if (num == arr[r][c])
			{
				burstVH(sumv, sumh, r, c, arr,arr2);
				s = 1;
			}
			else
			{
				s = 0;
				cout << "not allowed";
			}
		}
		else
		{
			arr[r][c] = num;
		}
		sumh = 0;
		sumv = 0;
		out_count++;
	}
	return s;
}

void addnewboard(int arr[][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			arr[i][j] = rand() % 5 + 10;
			checksame(arr, i, j);
		}
	}
}


void colorbomb2x(int arr[][9],int arr2[][9])
{
	for(int i = 0;i<9;i++)
	{
		for (int j = 0; j < 9; j++)
			arr2[i][j] = 99;
	}
	addnewboard(arr);
}

void findReplace(int num, int arr[][9],sf::RenderWindow& win, sf::RectangleShape list[][9], sf::Sprite& sprite, sf::RectangleShape& Cursor)
{
	int temp;
	temp = choose(num, 5);
	for(int i = 0;i<9;i++)
	{
		for(int j = 0;j<9;j++)
		{
			if (arr[i][j] == temp)
				arr[i][j] = num;
		}
	}
	drawboard(arr, win, list, sprite,Cursor);
	Sleep(500);
}

void bombpluswrapped(int arr[][9],int arr2[][9],int num,int row,int col, sf::RenderWindow& win, sf::RectangleShape list[][9], sf::Sprite& sprite,sf::RectangleShape& Cursor)
{
	findReplace(num, arr, win, list, sprite,Cursor);
	copyarray(arr, arr2);
	drawboard(arr2,win, list, sprite,Cursor);
	Sleep(500);
	PlainWrappedcandy(arr, arr2, row, col, 0, 3);
}

int bombplusstripped(int arr[][9],int arr2[][9],int num ,sf::RenderWindow& win, sf::RectangleShape list[][9], sf::Sprite& sprite, sf::RectangleShape& Cursor)
{
	findReplace(num, arr, win, list, sprite,Cursor);
	copyarray(arr, arr2);
	if (num == 15 || num == 16 || num == 17)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (arr[i][j] == num)
				{
					clearWholeRow(arr, arr2, i);
					drawboard(arr2, win, list, sprite,Cursor);
					Sleep(500);
					copyarray(arr, arr2);
					j = 9;
				}
			}
		}
	}else
	{
		for (int j = 0; j < 9; j++)
		{
			for (int i = 0; i < 9; i++)
			{
				if (arr[i][j] == num)
				{
					clearWholeCol(j, arr, arr2);
					drawboard(arr2, win, list, sprite,Cursor);
					Sleep(500);
					copyarray(arr, arr2);
					i = 9;
				}
			}
		}
	}
	return 1;
}

void colorbombplusplain(int arr[][9],int arr2[][9],int num,int r,int c, sf::RenderWindow& win, sf::RectangleShape list[][9], sf::Sprite& sprite,sf::RectangleShape& Cursor)
{
	for(int i = 0;i<9;i++)
	{
		for(int j = 0;j<9;j++)
		{
			if (arr[i][j] == num || i==r && j==c)
			{
				burstH(1, i, j, arr, arr2);
				drawboard(arr2, win, list, sprite,Cursor);
				Sleep(500);
				copyarray(arr, arr2);
			}
		}
	}
}

void swap(int r1, int c1,int r2,int c2,int arr[][9],int arr2[][9],int &moves, sf::RenderWindow& win, sf::RectangleShape list[][9], sf::Sprite& sprite, sf::RectangleShape& Cursor)
{
	int check,temp;
	if ((r1 + 1 == r2 && c1 == c2) || (r2 + 1 == r1 && c1 == c2)
		|| (r1 == r2 && c1 + 1 == c2) || (r1 == r2 && c2 + 1 == c1)
		|| (r1 - 1 == r2 && c1 == c2) || (r2 - 1 == r1 && c1 == c2)
		|| (r1 == r2 && c1 - 1 == c2) || (r1 == r2 && c2 - 1 == c1))
	{
		temp = arr[r1][c1];
		arr[r1][c1] = arr[r2][c2];
		arr[r2][c2] = temp;
		
		arr2[r1][c1] = arr2[r2][c2];
		arr2[r2][c2] = temp;

		if (((arr[r1][c1] == 15 || arr[r1][c1] == 16 || arr[r1][c1] == 17
			|| arr[r1][c1] == 21 || arr[r1][c1] == 22) && (arr[r2][c2] == 23
				|| arr[r2][c2] == 24 || arr[r2][c2] == 25 || arr[r2][c2] == 18
				|| arr[r2][c2] == 19)) || ((arr[r1][c1] == 23 || arr[r1][c1] == 24
					|| arr[r1][c1] == 25 || arr[r1][c1] == 18 || arr[r1][c1] == 19)
					&& (arr[r2][c2] == 15 || arr[r2][c2] == 16 || arr[r2][c2] == 17
						|| arr[r2][c2] == 21 || arr[r2][c2] == 22)))
			check = wrappedstriped(arr,arr2, r1, c1);
		else if ((arr[r1][c1] == 23 || arr[r1][c1] == 24 || arr[r1][c1] == 25 || arr[r1][c1] == 18 || arr[r1][c1] == 19)
			&& (arr[r2][c2] == 19 || arr[r2][c2] == 18 || arr[r2][c2] == 25 || arr[r2][c2] == 24 || arr[r2][c2] == 23))
		{
			if (r1 == r2)
				check = wrappedwrapped(arr,arr2, r1, c1, r2, c2, 1);
			else
				check = wrappedwrapped(arr,arr2, r1, c1, r2, c2, 2);
		}
		else if (arr[r1][c1] == 20 && arr[r2][c2] == 20)
		{
			colorbomb2x(arr,arr2);
			check = 1;
		}
		else if(arr[r1][c1]==20 &&(arr[r2][c2] == 15 || arr[r2][c2] == 16 || arr[r2][c2] == 17
			|| arr[r2][c2] == 21 || arr[r2][c2] == 22) || (arr[r1][c1] == 15 || arr[r1][c1] == 16 || arr[r1][c1] == 17
			|| arr[r1][c1] == 21 || arr[r1][c1] == 22) && arr[r2][c2] == 20)
		{
			if (arr[r1][c1] == 20)
				check = bombplusstripped(arr, arr2, arr[r2][c2] ,win, list, sprite,Cursor);
			else
				check = bombplusstripped(arr, arr2, arr[r1][c1] ,win, list, sprite,Cursor);
		}
		else if (arr[r1][c1] == 20 && (arr[r2][c2] == 10 || arr[r2][c2] == 11 || arr[r2][c2] == 12
			|| arr[r2][c2] == 13 || arr[r2][c2] == 14) || (arr[r1][c1] == 10 || arr[r1][c1] == 11 || arr[r1][c1] == 12
				|| arr[r1][c1] == 13 || arr[r1][c1] == 14) && arr[r2][c2] == 20)
		{
			if (arr[r1][c1] == 20)
				colorbombplusplain(arr,arr2,arr[r2][c2],r1,c1, win, list,sprite,Cursor);
			else
				colorbombplusplain(arr, arr2, arr[r1][c1],r2,c2 ,win, list, sprite,Cursor);
			check = 1;
		}else if(arr[r1][c1] == 20 && (arr[r2][c2] == 23 || arr[r2][c2] == 24 || arr[r2][c2] == 25
			|| arr[r2][c2] == 18 || arr[r2][c2] == 19) || (arr[r1][c1] == 23 || arr[r1][c1] == 24 || arr[r1][c1] == 25
				|| arr[r1][c1] == 18 || arr[r1][c1] == 19) && arr[r2][c2] == 20)
		{
			if (arr[r1][c1] == 20)
				bombpluswrapped(arr, arr2, arr[r2][c2], r2, c2 ,win, list, sprite,Cursor);
			else
				bombpluswrapped(arr, arr2, arr[r1][c1], r1, c1 ,win, list, sprite,Cursor);
			check = 1;
		}
		else
			check = burst(arr,arr2, 9,r1,c1,r2,c2);
		if (check==1) 
		{
			moves -= 1;
			cout << "swap allowed, changes are being made"<<endl;
			Sleep(1000);
		}
		else
		{
			temp = arr[r1][c1];
			arr[r1][c1] = arr[r2][c2];
			arr[r2][c2] = temp;
			
			arr2[r1][c1] = arr2[r2][c2];
			arr2[r2][c2] = temp;

			cout << "reverse swap cause of burst fail"<<endl;
			Sleep(500);
		}
	}
	else
		cout << "invalid swap" << endl;
	
}


int main() 
{
	sf::RenderWindow win(sf::VideoMode(1200, 700), "My window");

	sf::Sprite mainbackground;
	sf::Texture text;
	text.loadFromFile("bg.png");
	mainbackground.setTexture(text);
	sf::Texture candy;
	candy.loadFromFile("simpleRed1.png");
	sf::Sprite spritecandy;
	spritecandy.setTexture(candy);
	sf::Vector2f cpos;
	cpos.x = 450; cpos.y = 50;
	sf::RectangleShape Cursor;
	Cursor.setSize(sf::Vector2f(40, 40));
	Cursor.setFillColor(sf::Color::Transparent);
	Cursor.setOutlineColor(sf::Color::White);
	Cursor.setOutlineThickness(3);
	sf::RectangleShape list[9][9];
	sf::Vector2f pos;
	pos.x = 450; pos.y = 50;
	Cursor.setPosition(cpos);
	spritecandy.setPosition(pos);
	for (int i = 0; i < 9; i++)
	{
		pos.x = 450;
		for (int j = 0; j < 9; j++)
		{
			list[i][j].setSize(sf::Vector2f(40, 40));
			list[i][j].setFillColor(sf::Color::Black);
			list[i][j].setOutlineColor(sf::Color::White);
			list[i][j].setOutlineThickness(1);
			list[i][j].setPosition(pos.x, pos.y);
			pos.x += 40;
		}
		pos.y += 40;
	}
	
	sf::Font* font1;
	font1 = new sf::Font();
	font1->loadFromFile("WithsandDemoRegular.ttf");
	sf::Font font2;
	font2.loadFromFile("WithsandDemoRegular.ttf");
	button loadnewgame(450, 200, 400, 70, font1, font2, "New Game", sf::Color(51, 0, 102), sf::Color(224, 224, 224), sf::Color::Transparent);
	button loadprevgame(450, 500, 400, 70, font1, font2,  "load prev Game", sf::Color(51, 0, 102), sf::Color(224, 224, 224), sf::Color::Transparent);

	bool otherflag = false;

	int moves = 20,score = 0, target = 0;
	int r1=-1, c1=-1, r2=-1, c2=-1;
	srand(time(NULL));
	const int row = 9, col = 9;
	int arr[row][col];
	int arr2[row][col];
	ifstream read;
	ofstream write;
	int choice=-1;
	cout << "Menu" << endl;
	cout << "a) for new game enter 1:" << endl;
    cout<< "b) to load the previous game enter 2:"<<endl;
	bool gameflag = true;
	while (win.isOpen())
	{
		sf::Event event;
		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				win.close();
			}

			if (loadnewgame.isPressed())
				choice = 1;
			if (loadprevgame.isPressed())
				choice = 2;
		}

		//cin >> choice;

		if (gameflag)
		{
			while (choice != -1 && choice != 0 && moves > 0)
			{
				if (choice == 1)
				{
					addnewboard(arr);
				}
				if (choice == 2)
				{
					read.open("save.txt");
					while (!read.eof())
					{
						for (int i = 0; i < row; i++)
						{
							for (int j = 0; j < col; j++)
							{
								read >> arr[i][j];
							}
						}
					}
					read.close();
				}
				if (arr[0][0] >= 10)
				{
					//drawboard(arr, win, list, mainbackground, Cursor);
					
					r1 = 1; c1 = 0; r2 = 7; c2 = 0;
				}
				else
				{
					cout << "no game saved before" << endl;
				}
				while (r1 != -1 && r2 != -1 && c1 != -1 && c2 != -1)
				{

					while (win.pollEvent(event))
					{
						if (event.type == sf::Event::Closed)
						{
							r1 = -1;
							choice = -1;
							gameflag = false;
							write.open("save.txt");
							for (int i = 0; i < row; i++)
							{
								for (int j = 0; j < col; j++)
								{
									write << arr[i][j] << " ";
								}
								write << endl;
							}
							cout << "data saved successfully" << endl;
							win.close();
						}
						if (event.type == sf::Event::KeyPressed)
						{
							if (event.key.code == sf::Keyboard::Up)
							{
								if (list[0][0].getPosition().y <= Cursor.getPosition().y - 40)
								{
									cpos.y -= 40;
									Cursor.setPosition(cpos);
								}
							}
							if (event.key.code == sf::Keyboard::Down)
							{
								if (list[8][0].getPosition().y >= Cursor.getPosition().y + 40)
								{
									cpos.y += 40;
									Cursor.setPosition(cpos);
								}
							}
							if (event.key.code == sf::Keyboard::Right)
							{
								if (list[0][8].getPosition().x >= Cursor.getPosition().x + 40)
								{
									cpos.x += 40;
									Cursor.setPosition(cpos);
								}
							}
							if (event.key.code == sf::Keyboard::Left)
							{
								if (list[0][0].getPosition().x <= Cursor.getPosition().x - 40)
								{
									cpos.x -= 40;
									Cursor.setPosition(cpos);
								}
							}
							if (event.key.code == sf::Keyboard::Return)
							{
								for (int i = 0; i < 9; i++)
								{
									bool flag = false;
									for (int j = 0; j < 9; j++)
									{
										if (list[i][j].getPosition() == cpos)
										{
											if (r1 == -3 && c1 == -3)
											{
												r1 = i;
												c1 = j;
											}
											else if (r2 == -3 && c2 == -3)
											{
												r2 = i;
												c2 = j;
												
											}
											flag = true;
											break;
										}
									}
									if (flag)
										break;
								}
							}
						}
					}
					
					if (r1 != -3 && r2 != -3 && c1 != -3 && c2 != -3)
					{
						copyarray(arr, arr2);
						swap(r1, c1, r2, c2, arr, arr2, moves, win, list, mainbackground, Cursor);
						check_all_board(arr);
						r1 = r2 = c1 = c2 = -3;
						drawboard(arr2, win, list, mainbackground, Cursor);

						Sleep(500);
					}
					drawboard(arr, win, list, mainbackground, Cursor);
				}
			}
		}
		win.clear();
		win.draw(mainbackground);
		sf::Mouse mos;
		loadnewgame.render(&win);
		sf::Vector2i mpos = mos.getPosition();
		loadnewgame.update(sf::Vector2f(mpos.x, mpos.y), win);
		loadprevgame.render(&win);
		mpos = mos.getPosition();
		loadprevgame.update(sf::Vector2f(mpos.x, mpos.y), win);
		win.display();
	}
}