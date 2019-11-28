#include "Game.h"
#include <vector>
#include <iostream>
using namespace std;

Game::Game():
point(Point(0,0))
{
	row = 0;
	col = 0;
	numOfBox = 0;
	step = 0;
	push = 0;
}

Game::Game(int r, int c, int b, int start_r, int start_c):
point(Point(start_r, start_c))
{
	row = r;
	col = c;
	numOfBox = b;
	step = 0;
	push = 0;
}


void Game::initMap(int* arr, int r, int c)
{
	for (int i=0; i<r; i++){
		for (int j =0; j<c; j++){
			int m = *(arr+(i*c+j));
			if (m == BOX) {
				box.push_back(Point(i,j));
				map[i][j] = 0;
			}else map[i][j] = m;
		}
	}
}

bool Game::isWall(Point d)
{
	return map[point.r+d.r][point.c+d.c] == 1;
}


bool Game::isBox(Point d)
{
	for (int i=0; i<numOfBox; i++){
		if (box[i]==point+d) return true;
	}
	return false;
}


bool Game::canMoveBox(Point d)
{
	if ((*this).isWall(d*2)) return false;
	if ((*this).isBox(d*2)) return false;
	return true;
}


int Game::remainingBox()
{
	int cnt = 0;
	vector<Point>::iterator it;
	for (it=box.begin(); it!=box.end(); it++){
		if (map[(*it).r][(*it).c] != GOAL) cnt++;
	}
	return cnt;
}


void Game::moveBox(Point d)
{
	int i=0;
	while (!(box[i]==point+d)) i++;
	box[i] += d;
	push++;
}

void Game::moveCharacter(Point d)
{
	point += d;
	step++;
}

bool Game::isFinished()
{
	return Game::remainingBox() == 0;
}
