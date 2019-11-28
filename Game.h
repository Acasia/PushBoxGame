#include "Point.h"
#include <vector>
using namespace std;
enum CELLS { EMPTY, WALL, BOX, GOAL, OUT };

class Game {
	public:
	Game();
	Game(int r, int c, int b, int start_r, int start_c);

	int row;
	int col;
	int numOfBox;
	Point point; //character position
	//int position[2];

	int step; //캐릭터 이동 횟수
	int push; //상자 이동 횟수
	//int remainingBox; //목적지까지 남은 박스 개수

	int map[10][10]; //2차원 배열: 벽, 목적지, 외부
	vector<Point> box; //포인트 배열: 박스 위치

	void initMap(int* arr, int r, int c);
	void initMap(int* arr, int r); //임시
	bool isWall(Point d); //벽인지 판단
	bool isBox(Point d); //박스인지 판단
	bool canMoveBox(Point d); //박스 이동여부
	void moveBox(Point d); //박스 움직이기
	void moveCharacter(Point d); //캐릭터 움직이기
	int remainingBox(); //목적지까지 남은 박스 개수

	//추가
	bool isFinished();

	/*
	bool isWall(int r, int c); //벽인지 판단
	bool isBox(int r, int c); //박스인지 판단

	bool canMoveBox(int r, int c, Point d); //박스 이동여부
	void moveBox(int r, int c, Point d); //박스 움직이기
	*/
};
