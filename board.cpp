#include <iostream>

using namespace std;

#define ROWS 3
#define COLS 3

struct board {
	int b[ROWS][COLS];

	void set(int row, int col, int value) {
		b[row][col] = value;
	}
	int sum() {
		int total = 0;
		for(int i=0;i<ROWS;i++) {
			int tmp = sum_row(i);
			total += tmp;	
		}
		for(int i=0;i<COLS;i++) {
			int tmp = sum_col(i);
			total += tmp;
		}
		return total;
	}
	int sum_col(int index) {
		int total = 0;
		for(int i=0;i<ROWS;i++) {
			total += b[i][index];
		}
		return total;
	}
	int sum_row(int index) {
		int total = 0;
		for(int i=0;i<COLS;i++) {
			total += b[index][i];
		}	
	}
	void flip_row(int index) {
		for(int i=0;i<COLS;i++) {
			b[index][i] = b[index][i] * -1;
		}
	}
};


int main() {
	board b;
	b.set(0,0,33); b.set(0,1,30); b.set(0,2,-10);
	b.set(1,0,-16); b.set(1,1,19); b.set(1,2,9);
	b.set(2,0,-17); b.set(2,1,12); b.set(2,2,-14);

	cout << b.sum() << endl;

	b.flip_row(2);
	cout << b.sum() << endl;
}

