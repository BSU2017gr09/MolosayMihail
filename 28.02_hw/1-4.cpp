//Расположить в порядке возрастания элементы массива А(N), начиная с k-го элемента.
#include <iostream>
#include <conio.h>
#include <clocale>
#include <cstdlib> 
#include <ctime>
#include <Windows.h>
#include <fstream>
using namespace std;

int* giveMemory(int N) {
	int* arr;
	try {
		arr = new int[N];
	}
	catch (...) {
		cout << "Ошибка выделения памяти под массив. Остановка..." << endl;
		system("pause");
		exit(0);
	}
	return arr;
}

int freeMemory(int* arr, int N) {
	delete[N] arr;
	return 0;
}

void initArray(int* arr, int N) {
	for (int* end = arr + N; arr < end; arr++) {
		*arr = rand() % (100); // from 0 to 9 including both
	}
	cout << "Массив проинициализирован." << endl;
}

void printArray(int* arr, int N) {
	for (int* end = arr + N; arr < end; arr++) {
		cout << *arr << ' ';
	}
	cout << endl;
}

bool IsSimple(int* a) {
	if (*a == 1 || *a == 0) return false;
	else {
		for (int i = 2; i <= *a / 2; i++) {
			if ((*a) % i == 0) return false;
		}
		return true;
	}
}

void sortOnlyPrime(int *arr, int N) {
	for (int *i = arr; i < N + arr; i++) {
		if (IsSimple(i)) {
			for (int *j = i; j < N + arr - 1; j++) {
				if (IsSimple((j + 1))) {
					if (*i >*(j + 1))
						swap(*i, *(j + 1));
				}
			}
		}
	}
}

//========== MAIN ==========

int main() {
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "Ru");

	int N = 0;
	int *arr = nullptr;
	int init_pos = 0;

	cout << "Введите длину массива для создания: " << endl;
	cin >> N;

	arr = giveMemory(N);

	initArray(arr, N);
	printArray(arr, N);

	sortOnlyPrime(arr, N);
	printArray(arr, N);

	freeMemory(arr, N);

	_getch();
	return 0;

}
