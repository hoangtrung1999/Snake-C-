/* If (this_code_run == true) 
it's_creator's_name = "Nguyen Hoang Trung";
	else
it's_creator's_name = "Undefine";
I'm a game programmer , contact me :v 
facebook.com/hoangtrung1999
facebook.com/COmbOstudios
*/
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <conio.h>
#include <iostream>
#include "console.h"
#include <time.h>
#include <Windows.h>

#define Height 80 
#define Width 13
#define Length 69
using namespace std;

enum TrangThai {Up , Down , Left , Right};

struct Toado
{
	int x;
	int y;
};

struct Snake
{
	Toado dot[Length];//
	int n;//so dot
	TrangThai tt;
};

struct Fruit
{
	Toado td;


};

void MakeSnake( Snake &snake  , Fruit &fr )
{
	snake.n = 1;
	snake.dot[0].x = 18;
	snake.dot[0].y = 7;
	snake.tt = Right;
	
	fr.td.x = 10;
	fr.td.y = 10;
}

void ShowSnake (Snake snake , Fruit fr)
{
	clrscr();
	//
	TextColor(2);
	for ( int i = 0 ; i < Width ; i++ ) //  Oy
	{
		if ( i == 0 || i == Width-1  )
		{
			for ( int j = 0 ; j < Height ; j++ ) //  Ox
			{
					
					cout<<(char) 4;
			}
		}
		else 
		{
			for ( int k = 0 ; k < Height ; k++)
			{
				if ( k == 0 || k == Height -1)
				{
					cout<<(char) 4;
				}
				else
				{	
					cout<<" ";
				}
			
			}
			cout<<"\n";
		}
	}
	//
	TextColor(7);
	for (int i = 0 ; i < snake.n; i++)
	{
		gotoXY(snake.dot[i].x , snake.dot[i].y);
		if ( i == 0 )
		{
			putchar(1);
		}
		else
		{
			putchar (4);
		}
	}

	TextColor(18);
	gotoXY(fr.td.x , fr.td.y);
	cout<<"U";
}
//
void MoveSnake (Snake &snake)
{
	for (int i = snake.n -1 ; i > 0 ; i--)
		snake.dot[i] = snake.dot[i-1];

	if(_kbhit())
	{
		int key = _getch();
		
		if(key == 'w' || key == 'W')
			
			snake.tt = Up;
		

		else if(key == 'a' || key == 'A')
		
			snake.tt = Left;
		
		else if(key == 's' || key == 'S')
		
			snake.tt = Down;
		
		else if(key == 'd' || key == 'D')
		
			snake.tt = Right;
	
	}


	if(snake.tt == Up)
	
		snake.dot[0].y--;
	
	else if(snake.tt == Down)
	
		snake.dot[0].y++;
	
	else if(snake.tt == Left)
	
		snake.dot[0].x--;
	
	else if(snake.tt == Right)
	
		snake.dot[0].x++;
	

}
//
void Solve (Snake &snake , Fruit &fr , int *p)
{
	if ( snake.dot[0].x == fr.td.x &&
		snake.dot[0].y == fr.td.y)
	{
		*p = *p +1 ;
		snake.n++;
		for (int i = 1; i < snake.n ; i++)
		{
			snake.dot[i] = snake.dot[i-1];
		}

		if (snake.tt == Up)
		{
			snake.dot[0].y--;
		}
		else if (snake.tt == Down)
		{
			snake.dot[0].y++;
		}
		else if (snake.tt == Right)
		{
			snake.dot[0].x++;
		}
		else if (snake.tt == Left)
		{
			snake.dot[0].x--;
		}
		fr.td.x = (rand() % Height);
		fr.td.y = (rand() % Width);
	}

	

}
//

int main()
{
	int Score = 0;
	int *p = &Score;
	BOOL isTouch = false;

	srand(time(NULL));
	
	Snake snake;
	Fruit fr;
	MakeSnake(snake , fr);
	while (isTouch == false)
	{
	//check lose
	for ( int i = 1 ; i <= snake.n ; i++ )
	{
		
			if ( snake.dot[i].x == snake.dot[0].x 
				&& snake.dot[i].y == snake.dot[0].y)
			{
				clrscr();
				isTouch = true;
			}

	}
	if ( snake.dot[0].x == 0 || snake.dot[0].x == Height
		|| snake.dot[0].y == 0 || snake.dot[0].y == Width)
	{
		isTouch = true;
	}
	//
	ShowSnake(snake, fr);
	
	//
	MoveSnake(snake);

	//
	Solve(snake , fr , &Score );
	Sleep(100);
	}

	clrscr();
	cout<<"You Lose\n";
	cout<<"Your Score: "<<Score<<endl;

	return 0;
	_getch();
}