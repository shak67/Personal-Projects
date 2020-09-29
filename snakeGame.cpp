
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include <conio.h>
#include <Windows.h>
using namespace std; // So "std::cout" may be abbreviated to "cout"
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;

enum eDirection{ Stop=0, Left, Right, Up, Down};
eDirection dir; // holds direction of snake

void Setup()
{
	gameOver = false;
	dir = Stop;
	x = width / 2; // dividing by two to set snake head in 
	y = height / 2; // the middle of the block  works here b/c block size is 20
	fruitX = rand() % width; // places fruit randomly
	fruitY = rand() % height;
	score = 0;
}
void Draw()
{
	system("cls"); // clears the console window
	for (int i = 0; i < width+1; i++) // setting border for wall
		cout << "+";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "+";
			if (i == y && j == x)
				cout << "O";
			else if (i == fruitY && j == fruitX)
				cout << "*";
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{

					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";

				if (j == width - 1)
					cout << "+";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < width+1; i++)
		cout << "+";
	cout << endl;
	cout << "Score:" << score << endl;
}
void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case'a':
			dir = Left;
			break;
		case'd':
			dir = Right;
			break;
		case 'w':
			dir = Up;
			break;
		case 's':
			dir = Down;
				break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}
void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case Left:
		x--;
		break;
	case Right:
		x++;
		break;
	case Up:
		y--;
		break;
	case Down:
		y++;
		break;
	default:
		break;
	}
	if (x > width || x < 0|| y> height|| y< 0)
		gameOver = true;
	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;
	}
	if (x == fruitX && y == fruitY)
	{
		nTail++;
		score += 10;
		fruitX = rand() % width; 
		fruitY = rand() % height;

	}
}
int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(10);
		// Sleep(10) is a function that will slow your game
	}
}