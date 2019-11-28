using namespace std;
class Point {
	public:
	int r;
	int c;

	Point(){ r=0; c=0; }

	Point(int row, int col){
		r = row;
		c = col;
	}

	void set(int row, int col){
		r = row;
		c = col;
	}

	Point operator+(Point& p) const{
		return Point(r+p.r, c+p.c);
	}

	Point& operator+=(const Point& p){
		r += p.r;
		c += p.c;
		return (*this);
	}

	Point operator*(int value) const{
		return Point(value*r, value*c);
	}

	bool operator==(Point p) const{
		return r==p.r&&c==p.c;
	}
};
