#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

class Apple
{
private:
	int mass;
	int taste;
	enum tastes
	{
		SWEET, SOUR
	};
	int color;
	enum colors
	{
		RED, GREEN
	};
	char* colors_str[2] = { "RED", "GREEN" };
	char* tastes_str[2] = { "SWEET", "SOUR" };
public:
	Apple()
	{
		mass = 0;
		taste = 0;
		color = 0;
	}

	Apple(int _mass, int _taste, int _color)
	{
		mass = _mass;
		taste = _taste;
		color = _color;
	}

	int getMass()
	{
		return mass;
	}
	char* getTaste()
	{
		return tastes_str[taste];
	}
	char* getColor()
	{
		return colors_str[color];
	}
	int getNumTaste()
	{
		return taste;
	}
	int getNumColor()
	{
		return color;
	}
};

Apple search(Apple* arr, int _chose, int quantity)
{
	int i(0);
	bool t(0);
	Apple apple;
	switch (_chose)
	{
	case 1:
		int min, max;
		cout << endl << "Введите интервал массы:" << endl << "от "; cin >> min;
		cout << "до "; cin >> max;
		if (min > max)
		{
			int temp;
			temp = min;
			min = max;
			max = temp;
		}
		for (; (i < quantity) && (!t); i++)
		{
			if ((arr[i].getMass() <= max) && (arr[i].getMass() >= min))
			{
				apple = arr[i];
				t = 1;
			}
		}
//		if (t)
//		{
//			cout << endl << "Apple " << i << ": "
//				<< arr[i - 1].getMass() << "g " << endl;
//		}
		break;
	case 2:
		int chose;
		cout << endl << "Яблоко какого вкуса искать?" << endl
			<< "1. Сладого;" << endl
			<< "2. Кислого." << endl << endl;
		cin >> chose;
		for (; (i < quantity) && (!t); i++)
		{
			if (arr[i].getNumTaste() == chose - 1)
			{
				apple = arr[i];
				t = 1;
			}
		}
//		if (t)
//		{
//			cout << endl << "Apple " << i << ": "
//				<< arr[i - 1].getTaste() << endl;
//		}
		break;
	case 3:
		cout << endl << "Яблоко какого цвета искать?" << endl
			<< "1. Красного;" << endl
			<< "2. Зеленого." << endl << endl;
		cin >> chose;
		for (; (i < quantity) && (!t); i++)
		{
			if (arr[i].getNumColor() == chose - 1)
			{
				apple = arr[i];
				t = 1;
			}
		}
//		if (t)
//		{
//			cout << endl << "Apple " << i << ": "
//				<< arr[i - 1].getColor() << endl;
//		}
		break;
	}
		return apple;
//	else
//		return 0;
//		cout << endl << "По заданным параметрам объекта не найдено." << endl;
}

void sorting(Apple* arr, int _chose, int quantity)
{
	Apple temp;
	switch (_chose)
	{
	case 1:
		for (int i(0); i < quantity - 1; i++)
		{
			for (int j(0); j < quantity - 1 - i; j++)
			{
				if (arr[j].getMass() > arr[j + 1].getMass())
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		break;
	case 2:
		for (int i(0); i < quantity - 1; i++)
		{
			for (int j(0); j < quantity - 1 - i; j++)
			{
				if (arr[j].getNumTaste() > arr[j + 1].getNumTaste())
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		break;
	case 3:
		for (int i(0); i < quantity - 1; i++)
		{
			for (int j(0); j < quantity - 1 - i; j++)
			{
				if (arr[j].getNumColor() > arr[j + 1].getNumColor())
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		break;
	}
}

int main()
{
	setlocale(0, "");
	srand(time(NULL));

	const int amt = 10;
	Apple apple[amt];
	for (int i = 0; i < amt; i++)
	{
		int m, t, c;
		m = rand() % 400 + 100;
		t = rand() % 2;
		c = rand() % 2;
		apple[i] = Apple(m, t, c);
	}

	do
	{
		system("cls");
		int chose;
		cout << "Выберите действие:" << endl
			<< "1. Поиск;" << endl
			<< "2. Сортировка;" << endl
			<< "3. Вывести массив." << endl << endl;
		cin >> chose;
		Apple temp;
		switch (chose)
		{
		case 1:
			system("cls");
			cout << "Введите номер параметра поиска:" << endl
				<< "1. По массе;" << endl
				<< "2. По вкусу;" << endl
				<< "3. По цвету." << endl << endl;
			cin >> chose;
			temp = search(apple, chose, amt);
			if (temp.getMass())
				cout << endl<< "Apple: "
				<< temp.getMass() << "g, "
				<< temp.getTaste() << ", "
				<< temp.getColor() << endl;
			else
				cout << endl << "По заданным параметрам объекта не найдено." << endl;
			break;
		case 2:
			system("cls");
			cout << "По какому параметру производить сортировку?" << endl
				<< "1. По массе;" << endl
				<< "2. По вкусу;" << endl
				<< "3. По цвету." << endl << endl;
			cin >> chose;
			sorting(apple, chose, amt);
			break;
		case 3:
			system("cls");
			for (int i(0); i < 10; i++)
			{
				cout << "Apple " << i + 1 << ": "
					<< apple[i].getMass() << "g, "
					<< apple[i].getTaste() << ", "
					<< apple[i].getColor() << endl;
			}
		}
		cout << endl << "Для выхода нажмите [esc]" << endl
			<< "Чтобы продолжить, нажмите любую другую клавишу." << endl;
	} while (_getch() != 27);

	return 0;
}