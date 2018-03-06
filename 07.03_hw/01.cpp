//Определить, сколько в строке 4-символьных слов.
//Вывести эти слова на экран.
//Заменить последнее такое слово на заданную подстроку.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <Windows.h>
#include <fstream>
using namespace std;
const int N = 100;

char* giveMemory(int N) {
	char* str;
	try {
		str = new char[N];
	}
	catch (...) {
		cout << "Ошибка выделения памяти под массив. Остановка..." << endl;
		system("pause");
		exit(0);
	}
	return str;
}

int freeMemory(char* str, int N) {
	delete[N] str;
	return 0;
}

int numberOf4SymbWords(char *str) {
	char *p = str;
	char *prev_res = str;
	char seps[6] = ", .!?"; //separators
	int current_res = 0;
	int count = 0;

	cout << "All 4symb words: " << endl;

	while (1) {
		current_res = strcspn(p, seps) + 1; //+ 1 to avoid ' ' in the string begining;
		p += current_res;

		if (p - prev_res == 5) { // counting and printing words in 4 symbols
			count++;
			for (int i = 0; i < 4; i++) { // using 4 bcz we start from 0, not from 1 like higher in the case of 5
				cout << prev_res[i];
			}
			cout << ' ';
		}

		prev_res += current_res;

		if (strlen(p) == 0) {
			cout << endl << "Quantity of 4symb words: ";
			return count;
		}
	}
}

void changeLast4SymbWord(char* str, char* sub) {
	char *p = str;
	char *prev_res = str;
	char seps[6] = ", .!?"; //separators

	char *endpart = nullptr;
	endpart = giveMemory(N); //creating string in HEAP

	int current_res = 0;
	int pos_of_last_word = 0;

	while (1) {
		current_res = strcspn(p, seps) + 1; //+ 1 to avoid ' ' in the string begining;
		p += current_res;

		if (p - prev_res == 5)
			pos_of_last_word = prev_res - str;

		prev_res += current_res;

		if (strlen(p) == 0) break;
	}

	p = str + pos_of_last_word + 5; //we adding 5 to throw out last 4symb word and get only end part of string
	strcpy(endpart, p);

	str[pos_of_last_word] = '\0';
	strcat(str, sub);
	strcat(str, " ");
	strcat(str, endpart);

	freeMemory(endpart, N); //deleting string;
}

int main() {
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "Ru");

	char *str = nullptr;
	str = giveMemory(N); //creating string in HEAP
	strcpy(str, "Great mind is not a gift. Great mind is a punishment.");

	char sub[] = "knowledge";

	cout << str << endl;
	cout << numberOf4SymbWords(str) << endl;
	changeLast4SymbWord(str, sub);

	cout << "We replace last 4symb word by word " << "\'" << sub << "\':" << endl;

	cout << str;

	freeMemory(str, N); //deleting string;
	_getch();
	return 0;
}