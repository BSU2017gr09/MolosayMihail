//Даны точки плоскости своими координатами в виде двух одномерных массивов.
//Точки плоскости рассортировать по возрастанию расстояния до прямой ax + by + c = 0.
#include <iostream>
#include <conio.h>
#include <clocale>
#include <cstdlib> 
#include <ctime>
#include <Windows.h>
#include <fstream>
using namespace std;

float* giveMemory(int N) {
	float* arr;
	try {
		arr = new float[N];
	}
	catch (...) {
		cout << "Ошибка выделения памяти под массив. Остановка..." << endl;
		system("pause");
		exit(0);
	}
	return arr;
}

int freeMemory(float* arr, int N) {
	delete[N] arr;
	return 0;
}

void initArray(float* arr, int N) {
	for (float *p = arr; p < arr + N; p++) {
		*p = rand() % 11;
	}
}

void printArray(float* arr, int N) {
	for (float* end = arr + N; arr < end; arr++) {
		cout << *arr << ' ';
	}
	cout << endl;
}

float measureDistance(float x, float y, float a, float b, float c) {
	return (abs(a * x + b * y + c) / sqrt(a * a + b * b));
}


void sortByDistance(float* XsArr, float* YsArr, int N, float a, float b, float c) {
	for (float* p = XsArr, * q = YsArr; p < XsArr + N; p++, q++) {
		for (float* m = p, * n = q; m < XsArr + N; m++, n++) {
			if (measureDistance(*p, *q, a, b, c) > measureDistance(*m, *n, a, b, c)) {
				swap(*m, *p);
				swap(*n, *q);
			}
		}
	}
}

//========== MAIN ==========

int main() {
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "Ru");

	int N = 0;
	float a = 0;
	float b = 0;
	float c = 0;
	float* XsArr = nullptr;
	float* YsArr = nullptr;

	cout << "Введите желаемое количество точек на плоскости: " << endl;
	cin >> N;

	XsArr = giveMemory(N); //contains all X coords
	YsArr = giveMemory(N); //contains all Y coords

	while (1) {

		cout << "Введите коэффициенты a, b и c: " << endl;
		cout << "a = " << endl;
		cin >> a;
		cout << "b = " << endl;
		cin >> b;
		cout << "c = " << endl;
		cin >> c;

		if ((a == 0) && (b == 0)) {
			cout << "Невалидный ввод." << endl;
		}
		else break;
	}

	initArray(XsArr, N);
	initArray(YsArr, N);

	printArray(XsArr, N);
	printArray(XsArr, N);
	cout << endl;
	sortByDistance(XsArr, YsArr, N, a, b, c);

	printArray(XsArr, N);
	printArray(XsArr, N);
	cout << endl;
	freeMemory(XsArr, N);
	freeMemory(YsArr, N);

	_getch();
	return 0;

}
