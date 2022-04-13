	#include<stdio.h>
	#include<conio.h>
	#include<windows.h>
		
		
	void gotoxy(int x , int y)
	{
		COORD c;
		c.X=x;
		c.Y=y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
	}
	void SetColor(int ForgC)
		{
			WORD wColor;
			
			HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_SCREEN_BUFFER_INFO csbi;
			
			if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
			{	                 
				 wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
				 SetConsoleTextAttribute(hStdOut, wColor);
			}
			return;
		}


	void box (int len , int bre , int x , int y)
	{
		int i;
		for(i=0 ; i<len ; i++)
		{
			gotoxy(x+i,y);
			printf("%c",205);
			gotoxy(x+i,y+bre);
			printf("%c",205);
		}
		for(i=0 ; i< bre ; i++)
		{
			gotoxy(x,y+i);
			printf("%c",186);
			gotoxy(x+len,y+i);
			printf("%c",186);	
		}
		gotoxy(x+len,y);
		printf("%c",187);
		gotoxy(x+len,y+bre);
		printf("%c",188);
		gotoxy(x,y);
		printf("%c",201);
		gotoxy(x,y+bre);
		printf("%c",200);
	}
	
	void boxErase(int len , int bre , int x , int y)
	{
		int i;
		for(i=0 ; i<len ; i++)
		{
			gotoxy(x+i,y);
			printf(" ");
			gotoxy(x+i,y+bre);
			printf(" ");
		}
		for(i=0 ; i< bre ; i++)
		{
			gotoxy(x,y+i);
			printf(" ");
			gotoxy(x+len,y+i);
			printf(" ");	
		}
		gotoxy(x+len,y);
		printf(" ");
		gotoxy(x+len,y+bre);
		printf(" ");
		gotoxy(x,y);
		printf(" ");
		gotoxy(x,y+bre);
		printf(" ");
	}
		
	void animation(int len , int bre ,int x , int y , int time)
	{
		int i,p=0;
		int m = len , n = bre,z;
		int X = x , Y = y;

		for(i=0 ; m > 2 && n > 2 ; i++)
		{
			m = m - p;
			n = n - p;
			box(m,n,X,Y);
			//gotoxy(100,2+i);
			//printf("%2d %2d %2d %2d %2d",m,n,p,X,Y);
			++X;
			++Y;
			p = 2;
			Sleep(time);
		}
		 X--;
		 Y--;
		 for(i=0 ; n <= bre ; i++)
		 {
			boxErase(m,n,X,Y);
			//gotoxy(120,2+i);
			//printf("%2d %2d %2d %2d %2d",m,n,p,X,Y);
			m = m + 2;
			n = n + 2;
			--X;
			--Y;
			Sleep(time);
		 }
	}
	void parallelAnimation(int len1 , int bre1 , int x1 , int y1 , int len2 , int bre2  , int x2 , int y2 , int time , int var)
	{
		int ref1 = bre1 , ref2 = bre2;
		
		box(len1 , bre1 , x1 , y1);
		box(len2 , bre2 , x2 , y2);

		while(var--)
		{
			while(len1 > 2 && bre1 > 2 && len2 > 2 && bre2 > 2)
			{
				len1-=2;bre1-=2;len2-=2;bre2-=2;
				x1++;y1++;x2++;y2++;
				box(len1 , bre1 , x1 , y1);
				box(len2 , bre2 , x2 , y2);	
				Sleep(time);
			}
		
			while(bre1 <= ref1 && bre2 <= ref2)
			{
				boxErase(len1 , bre1 , x1 , y1);
				boxErase(len2 , bre2 , x2 , y2);
				len1+=2;bre1+=2;len2+=2;bre2+=2;
				x1--;y1--;x2--;y2--;
				Sleep(time);
			}
		}
	}
	void asycParallelAnimation(int len1 , int bre1 , int x1 , int y1 , int len2 , int bre2  , int x2 , int y2 , int time , int var)
	{
		int ref1 = bre1 , ref2 = bre2;
		
		box(len1 , bre1 , x1 , y1);
		box(len2 , bre2 , x2 , y2);
		
		while(len1 > 2 && bre1 > 2)
		{
			len1-=2; bre1-=2;
			x1++;y1++;
			box(len1,bre1,x1,y1);
		}
		
		while(var--)
		{
			while(bre1 <= ref1 && (len2 > 2 && bre2 > 2))
			{
				len2-=2;bre2-=2;x2++;y2++;
				box(len2 , bre2 , x2 , y2);
				boxErase(len1 , bre1 , x1 , y1);
				len1+=2;bre1+=2;x1--;y1--;
				Sleep(time);
			}
				
			while(bre2 <= ref2 && (len1 > 2 && bre1 > 2))
			{
				len1-=2;bre1-=2;x1++;y1++;
				box(len1 , bre1 , x1 , y1);
				boxErase(len2 , bre2 , x2 , y2);
				len2+=2;bre2+=2;x2--;y2--;
				Sleep(time);
			}	
		}
		
		while(bre1 <= ref1)
		{
			boxErase(len1,bre1,x1,y1);
			len1+=2;bre1+=2;x1--;y1--;
		}
		boxErase(len2 , bre2 , x2 , y2);		
	}
	void threeParallelAnimation(int len , int bre , int x1 , int y1 , int x2 , int y2 , int x3 , int y3 , int time , int var)
	{
		int ref = bre;
		box(len , bre , x1 , y1);
		box(len , bre , x2 , y2);
		box(len , bre , x3 , y3);
		
		while(var--)
		{
			while(len > 2 && bre > 2)
			{
				len-=2; bre-=2;
				x1++;y1++;x2++;y2++;x3++;y3++;
				box(len,bre,x1,y1);
				box(len,bre,x2,y2);
				box(len,bre,x3,y3);
				Sleep(time);
			}
			while(bre <= ref)
			{
				boxErase(len,bre,x1,y1);
				boxErase(len,bre,x2,y2);
				boxErase(len,bre,x3,y3);
				len+=2;bre+=2;
				x1--;y1--;x2--;y2--;x3--;y3--;
				Sleep(time);
			} 
		}
	}
	
