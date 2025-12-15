#include <iostream>
#include <string>
#include <limits>
#include "ProcessList.h"
#include <locale>
using namespace std;
PCB input()
{
	PCB p;
	cout << "Ввод данных" << endl;
	cout << "ID: ";
	cin >> p.processID;
	cout << "Имя: ";
	cin.ignore();
	getline(cin, p.processName);
	cout << "Статус: ";
	getline(cin, p.processStatus);
	cout << "Счетчик: ";
	cin >> p.commandCounter;
	cout << "10 регистров(вводить через пробел): ";
	for (int i = 0; i < 10; i++)
	{
		cin >> p.cpuRegisters[i];
	}
	return p;
}
int main()
{
	setlocale(LC_ALL, "RU");
	ProcessList list;
	int choice;
	cout << "Система управления процессами" << endl;
	do
	{
		cout << "МЕНЮ" << endl;
		cout << "1. Добавить процесс" << endl;
		cout << "2. Удалить процесс" << endl;
		cout << "3. Показать все процессы" << endl;
		cout << "4. Выход" << endl;
		cout << "Выбор: ";
		if (!(cin >> choice))
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Ошибка ввода" << endl;
			continue;

		}
		switch (choice)
		{
		case 1:
		{
			PCB p = input();
			if (list.insert(p))
			{
				cout << "Добавлен" << endl;
			}
			else
			{
				cout << "Ошибка" << endl;
			}
			cin.ignore(1000, '\n');
			break;
		}
		case 2:
		{
			int pid;
			cout << "Введите ID процесса для удаления" << endl;
			if (!(cin >> pid))
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Ошибка ввода" << endl;
				break;
			}
			if (list.remove(pid))
			{
				cout << "Процесс с ID " << pid << " удалён!" << endl;
			}
			else
			{
				cout << "Процесс с ID " << pid << " не найден!" << endl;
			}

			cin.ignore(1000, '\n');
			break;
		}
		case 3:
		{
			cout << "Список процессов" << endl;
			list.printList();
			break;
		}
		case 4:
		{
			cout << "Выход из программы";
			break;
		}
		default:
		{
			cout << "Неверный выбор" << endl;
			cin.ignore(1000, '\n');
		}
		}
	} 
	while (choice != 4);
return 0;
}
