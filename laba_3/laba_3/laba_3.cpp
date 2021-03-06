#include "pch.h"
#include <iostream>

using namespace std;

void print(int **arr) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			if (arr[i][j] != 0)
				cout << arr[i][j];
			else cout << " ";
		cout << endl;
	}
	cout << endl;
}

int main()
{
	Cage field;
	int i, j, **arr, kod;

	arr = new int*[10];
	for (i = 0; i < 10; i++)
		arr[i] = new int[10];

	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			arr[i][j] = 0;

	field.set(arr);

	while (true) {
		cout << "1 - Add\n2 - Hod\n0 - Exit\n";
		cin >> kod;
		switch (kod) {
		case 1:
			cout << "1 - Plant\n2 - Herb\n3 - Pred\n";
			cin >> i;
			field.objekt(i);
			field.init();
			arr = field.get();
			print(arr);
			break;
		case 2:
			field.WORLD();
			field.init();
			arr = field.get();
			print(arr);
			break;
		case 0:
			return 0;
		}
	}
}