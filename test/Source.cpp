#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;
bool gameover;
int width=20, height=20;
int x, y, Fx, Fy;
enum Direction {Stop = 0, Left = 1, Down = 2, Up = 3, Right = 4};
Direction dir;

void setup(){
	srand(time(NULL));
	gameover = false;
	dir = Stop;
	x = width / 2;
	y = height / 2;
	Fx = rand() % (width-1);
	Fy = rand() % (height-1);
}

void draw() {
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
				else cout << " ";
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
		}
	}
}

void logic() {
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
	}
	while (x == Fx && y == Fy){
		srand(time(NULL));
		Fx = rand() % (width - 1);
		Fy = rand() % (height - 1);
	}
	if ((x == height - 1 || y == width - 1) || (x==0||y==0)) gameover = true;
	
}


int main() {
	setup();
	while (!gameover) {
		draw();
		input();
		logic();
		system("cls");
		if (gameover) cout << "con ga re rach";
	}
	system("pause");
	return 0;
}


