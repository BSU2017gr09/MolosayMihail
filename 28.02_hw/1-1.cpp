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
		*arr = rand() % (9 + 1); // from 0 to 9 including both
	}
	cout << "Массив проинициализирован случ. числами от 0 до 10." << endl;
}

void printArray(int* arr, int N) {
	for (int* end = arr + N; arr < end; arr++) {
		cout << *arr << ' ';
	}
	cout << endl;
}

void sortFromPos(int* arr, int N, int init_pos) {
	init_pos--;

	int current_min = 0;
	int* current_min_pos = nullptr;

	int* end = arr + N;

	for (int* current_pos1 = arr + init_pos; current_pos1 < end; current_pos1++) {
		for (int* current_pos2 = arr + init_pos; current_pos2 < end; current_pos2++) {
			if (arr + init_pos == current_pos2) {
				current_min = *current_pos2;
				current_min_pos = current_pos2;
			}
			else {
				if (*current_pos2 < current_min) {
					current_min_pos = current_pos2;
					current_min = *current_pos2;
				}
			}
		}

		*current_min_pos = *current_pos1;
		*current_pos1 = current_min;
		init_pos++;
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

	while (1) {

		cout << "Выберите позицию, начиная с которой элементы будут упорядочены по возрастанию: " << endl;
		cin >> init_pos;

		if ((init_pos < 0) || (init_pos >= N)) {
			cout << "Невалидный ввод." << endl;
		}
		else break;
	}

	sortFromPos(arr, N, init_pos);
	printArray(arr, N);

	freeMemory(arr, N);

	_getch();
	return 0;

}
