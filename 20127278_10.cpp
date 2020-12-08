#include<iostream>
using namespace std;

int CountTheQueen(int n, float a[][100]) {
	int countResult = 0;
	//Tim ra max dong
	for (int i = 0; i < n; i++) {
		int maxRow = a[i][0], atCol = 0;
		for (int j = 0; j < n; j++)
			if (a[i][j] > maxRow) {
				maxRow = a[i][j];
				atCol = j;
			}
	//Kiem tra xem co phan tu nao bang max o trong dong hay ko
		bool maxRowFinal = false;
		int countMaxRow = 0;
		for (int j = 0; j < n; j++) {
			if (maxRow > a[i][j])
				countMaxRow++;
		}
		if (countMaxRow == n - 1)
			maxRowFinal = true;
	//Kiem tra xem max cua dong co phai la max cua cot hay ko
		if (maxRowFinal == true) {
			int countMaxCol = 0;
			for (int k = 0; k < n; k++)
				if (maxRow > a[k][atCol])
					countMaxCol++;
			bool isQueen = false;
			if (countMaxCol == n - 1) {
				isQueen = true;
			}
	//Kiem tra cac phan tu tren 2 duong cheo ma max di qua
		if (isQueen == true) {
				int cross1 = 1, count1 = 0, countCross = 0;
				while (atCol - cross1 >= 0 && i - cross1 >= 0) {
					if (maxRow > a[i - cross1][atCol - cross1])
						count1++;
					cross1++;
					countCross++;
				}
				int cross2 = 1, count2 = 0;
				while (atCol + cross2 <= n-1 && i - cross2 >= 0) {
					if (maxRow > a[i - cross2][atCol + cross2])
						count2++;
					cross2++;
					countCross++;
				}
				int cross3 = 1, count3 = 0;
				while (atCol - cross3 >= 0 && i + cross3 <= n-1) {
					if (maxRow > a[i + cross3][atCol - cross3])
						count3++;
					cross3++;
					countCross++;
				}
				int cross4 = 1, count4 = 0;
				while (atCol + cross4 <= n - 1 && i + cross4 <= n-1) {
					if (maxRow > a[i - cross4][atCol + cross4])
						count4++;
					cross4++;
					countCross++;
				}
				if (countCross == count1 + count2 + count3 + count4)
					countResult++;
		}
		else
			continue;
		}
		else
			continue;
	}
	return countResult;
}

void Input(int& n, float a[][100]) {
	cout << "Input row & column: ";
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	cout << "The input matrix is: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << a[i][j] << "    ";
		cout << endl;
	}
}

int main() {
	int n;
	float a[50][100];
	Input(n, a);
	int count = CountTheQueen(n, a);
	cout << "The number of Queen on the matrix is " << count;
}