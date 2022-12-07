#include <iostream>
#include "Date.h"
using namespace std;

void print(Date A);
void validMenu(char& menu);
bool isAgree(char menu);
bool isEnterDate(char menu);
bool isChangeDate(char menu);
bool isContinue(char menu);
void changeDate(Date& A, char menu);
void menuChangeDate(Date& A, char menu);


int main(Date& A) {
	setlocale(0, "");

	while (true) {
		Date A(7, 4, 2003);
		char menu = '0';

		//Хотите ввести дату?
		if (isEnterDate(menu))
			cin >> A;
		print(A);

		//Хотите изменить дату?
		if (isChangeDate(menu)) {
			menuChangeDate(A, menu);
			print(A);
		}

		//Продолжить программу?
		if (!isContinue(menu))
			return 0;
	}
}

///////////////////////////////////////////////////////////////////////////


void menuChangeDate(Date& A, char menu) {
	menu = '0';
	//Проверка ввода
	while (menu != '1' && menu != '2') {
		cout << "\nВыберите:\n";
		cout << "  1. Изменить дату на единицу\n";
		cout << "  2. Изменить дату на n дней\n";
		cout << "-->";
		cin >> menu;
	}

	//Изменить дату на 1 (1)
	if (menu == '1')
		changeDate(A, menu);

	//Изменить дату на n дней (2)
	else if (menu == '2') {

		menu = '0';
		while (menu != '1' && menu != '2' && menu != 'r') {
			cout << "\nВыберите:\n";
			cout << "  1. Увеличить на n дней\n";
			cout << "  2. Уменьшить на n дней\n";
			cout << "  Вернуться назад - r\n";
			cout << "-->";
			cin >> menu;
		}

		if (menu == 'r')
			menuChangeDate(A, menu);

		else if (menu != 'r') {
			int n = -1;
			while (n < 0) {
				cout << "\nНа сколько дней?\n";
				cout << "-->";
				cin >> n;
			}

			if (menu == '1')
				A.dayChange(n);
			else if (menu == '2')
				A.dayChange(-n);
		}
	}
}

///////////////////////////////////////////////////////////////////////////

void changeDate(Date& A, char menu) {
	menu = '0';
	//Проверка ввода
	while (menu != '1' && menu != '2' && menu != '3' && menu != 'r') {
		cout << "\nВыберите:\n";
		cout << "  1. Изменить день\n";
		cout << "  2. Изменить месяц\n";
		cout << "  3. Изменить год\n";
		cout << "  Вернуться назад - r\n";
		cout << "-->";
		cin >> menu;
	}

	//Изменить день (1)
	if (menu == '1') {
		menu = '0';
		//Проверка ввода
		while (menu != '1' && menu != '2' && menu != 'r') {
			cout << "\nВыберите:\n";
			cout << "  1. Увеличить на 1 день\n";
			cout << "  2. Уменьшить на 1 день\n";
			cout << "  Вернуться назад - r\n";
			cout << "-->";
			cin >> menu;
		}

		if (menu == '1')
			A.dayP();

		else if (menu == '2')
			A.dayM();
		else if (menu == 'r')
			changeDate(A, menu);
	}

	//Изменить месяц (2)
	else if (menu == '2') {
		//Проверка ввода
		menu = '0';
		while (menu != '1' && menu != '2' && menu != 'r') {
			cout << "\nВыберите:\n";
			cout << "  1. Увеличить на 1 месяц\n";
			cout << "  2. Уменьшить на 1 месяц\n";
			cout << "  Вернуться назад - r\n";
			cout << "-->";
			cin >> menu;
		}

		if (menu == '1')
			A.monthP();
		else if (menu == '2')
			A.monthM();
		else if (menu == 'r')
			changeDate(A, menu);
	}

	//Изменить год (3)
	else if (menu == '3') {
		menu = '0';
		//Проверка ввода
		while (menu != '1' && menu != '2' && menu != 'r') {
			cout << "\nВыберите:\n";
			cout << "  1. Увеличить на 1 год\n";
			cout << "  2. Уменьшить на 1 год\n";
			cout << "  Вернуться назад - r\n";
			cout << "-->";
			cin >> menu;
		}

		if (menu == '1')
			A.yearP();
		else if (menu == '2')
			A.yearM();
		else if (menu == 'r')
			changeDate(A, menu);
	}

	else if (menu == 'r')
		menuChangeDate(A, menu);
}

void print(Date A) {
	cout << "\n\n" << A << "\n\n";
}

bool isEnterDate(char menu) {
	cout << "\nХотите ввести дату? (y/n)\n";
	cout << "-->";
	cin >> menu;
	return isAgree(menu);
}

bool isChangeDate(char menu) {
	cout << "\nХотите изменить дату? (y/n)\n";
	cout << "-->";
	cin >> menu;
	return isAgree(menu);
}

bool isContinue(char menu) {
	cout << "\nПродолжить? (y/n)\n";
	cout << "-->";
	cin >> menu;
	return isAgree(menu);
}

void validMenu(char& menu) {
	while (menu != 'y' && menu != 'n' && menu != 'Y' && menu != 'N') {
		cout << "\nВведите y или n:\n";
		cout << "-->";
		cin >> menu;
	}
}

bool isAgree(char menu) {
	bool agree = false;
	validMenu(menu);
	if (menu == 'y' || menu == 'Y')
		agree = true;
	return agree;
}