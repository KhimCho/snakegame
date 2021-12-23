#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

bool gameover;
int width=20, height=20;
int x, y, Fx, Fy, score = 0;
int TailX[100], TailY[100]; 
int nTail;
int speed = 200;
enum Direction {Stop = 0, Left = 1, Down = 2, Up = 3, Right = 4};
Direction dir;

void setup(){
	srand(time(NULL));
	gameover = false;
	dir = Stop;
	x = width / 2;
	y = height / 2;
	Fx = rand() % (width-1); if (Fx == 0) Fx++;
	Fy = rand() % (height-1); if (Fy == 0) Fy++;
}

void draw() {
	system("cls");
	for (int i = 0; i < width; i++) {
		if ((i == 0) || (i == width - 1)) {
			for (int j = 0; j < height; j++)
				cout << "#";
			cout << endl;
		}
		else {
			for (int j = 0; j < height; j++) {
				if ((j == 0) || (j == height - 1))
					cout << "#";
				else if (j == x && i == y) cout << 0;
				else if ((j==Fx)&&(i == Fy)) cout << "$";
				else {
					bool print = true;
					for (int k = 0; k < nTail; k++) {
						if ((TailX[k] == j) && (TailY[k] == i)) {
							cout << "o";
							print = false;
							}
						}
					if (print) cout << " ";
				}
			}
			cout << endl;
		}
	}


}
void input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			dir = Left;
			break;
		case 's':
			dir = Down;
			break;
		case 'd':
			dir = Right;
			break;
		case 'w':
			dir = Up;
			break;
		case 'x':
			gameover = true;
		}
	}
}

void logic() {
	int prevX = TailX[0];
	int prevY = TailY[0];
	int chk1 = prevX;
	int chk2 = prevY;
	int prev2X, prev2Y;

	TailX[0] = x;
	TailY[0] = y;
	for (int i = 1; i < nTail; i++) {
		prev2X = TailX[i];
		prev2Y = TailY[i];
		TailX[i] = prevX;
		TailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir){
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
	while (x == Fx && y == Fy){
		score += 10;
		nTail++;
		if (time != 0) speed -= 50;
		Fx = rand() % (width - 1); if (Fx == 0) Fx++;
		Fy = rand() % (height - 1); if (Fy == 0) Fy++;
	}
	//if ((x == height - 1 || y == width - 1) || (x==0||y==0)) gameover = true;
	if (x >= height) x = 1; else if (x == 0) x = height-1;
	if (y >= width) y = 1; else if (y == 0) y = width-1;


	if (nTail == 1) if (chk1 == x && y == chk2) gameover = true;
	if (nTail!=0) if (x == TailX[0] && y == TailY[0]) gameover = true;
	for (int k = 0; k < nTail; k++)
		if (x == TailX[k] && y == TailY[k])
			gameover = true;

}


int main() {
	setup(); 

	while (!gameover) {
		draw();
		input();
		logic();
		Sleep(speed);
		if (gameover) cout << "con ga re rach";
	}
	system("pause");
	return 0;
}


