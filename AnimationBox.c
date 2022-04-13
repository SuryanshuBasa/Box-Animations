//#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

#include"box.h"
//using namespace std;

int main()
{
	int i,k=5,n = 3;
	srand(time(0));
	box(122,26,0,0);
	box(38,24,2,1);
	box(38,24,42,1);
	box(38,24,82,1);
	getch();
	while(n--)
	{
		Sleep(500);
		boxErase(38,24,2,1);
		box(38,24,2,1);
	}
	n = 3;
	while(n--)
	{
		Sleep(500);
		boxErase(38,24,42,1);
		box(38,24,42,1);
	}
	n = 3;
	while(n--)
	{
		Sleep(500);
		boxErase(38,24,82,1);
		box(38,24,82,1);
	}
	while(k--)
	{
		i = rand() % 3;
		switch(i)
		{
			case 0:{
				animation(36,22,3,2,50);
				break;
			} 
			case 1:{
				animation(36,22,43,2,50);
				break;
			}
			case 2:{
				animation(36,22,83,2,50);
				break;
			}
		}
	}
	boxErase(38,24,2,1);
	boxErase(38,24,42,1);
	boxErase(38,24,82,1);
	for(i=0 ; i<3 ; i++)
	{
		animation(122,26,0,0,50);
		boxErase(122,26,0,0);
		Sleep(200);
		box(122,26,0,0);
	}
	boxErase(122,26,0,0);
	box(60,26,0,0);
	box(60,26,62,0);
	box(122,26,0,0);
	n = 3;
	while(n--)
	{
		i = rand() % 2;
		switch(i)
		{
			case 0:{
				animation(60,26,0,0,50);
				break;
			}
			case 1:{
				animation(60,26,62,0,50);
				break;
			}
		}
	}
	boxErase(60,26,0,0);
	boxErase(60,26,62,0);
	
	parallelAnimation(60,26,0,0,60,26,62,0,0,4);
	
	asycParallelAnimation(60,26,0,0,60,26,62,0,0,4);

	parallelAnimation(100,15,0,0,100,15,0,17,0,4);
	
	asycParallelAnimation(100,15,0,0,100,15,0,17,0,4);
	n=3;i=25;
	while(i)
	{
		threeParallelAnimation(38,24,2,1,42,1,82,1,0,1);
		i/=2;
	}
		
	
	
	gotoxy(50,15);
	printf("  T H A N K  Y O U  ");
	getch();
	return 0;
}
;



