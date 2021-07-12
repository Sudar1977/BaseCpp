// Lesson5HomeWork.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
//=================================================================================================
//Функция инициализации массива
bool InitArray(double* arr, int size) // Получаем указатель на массив и его размер
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = (double)rand()/ (double)(rand()+1);
    }
    return true;
}
bool InitArray(int* arr, int size) // Получаем указатель на массив и его размер
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand(); 
	}
	return true;
}

//1. Написать функцию которая выводит массив double чисел
//на экран.Параметры функции это сам массив и его размер.
//Вызвать эту функцию из main.
void PrintMas(double* mas, int length)
{
	for (size_t i = 0; i < length-1; i++)
	{
		cout << mas[i] << ",";
	}
	cout << mas[length] <<endl;
}

void PrintMas(int* mas, int length)
{
	for (size_t i = 0; i < length; i++)
	{
		cout << mas[i] << ",";
	}
	cout << endl;
}

inline void Task1()
{
	const int size = 10;
	double mas[size];
	InitArray(mas, size);
	PrintMas(mas, size);

}
//2. Задать целочисленный массив, состоящий из элементов 0
//и 1. Например: [1, 1, 0, 0, 1, 0, 1, 1, 0, 0] .Написать функцию,
//заменяющую в принятом массиве 0 на 1, 1 на 0. Выводить
//на экран массив до изменений и после.
void Invert01(int* mas, int length)
{
	for (size_t i = 0; i < length - 1; i++)
	{
		mas[i] = mas[i] ? 0 : 1;
		//cout << mas[i] << ",";
	}

}
inline void Task2()
{
	const int size = 5;
	int mas[size] = {0,1,0,1,0};
	PrintMas(mas, size);
	Invert01(mas, size);
	PrintMas(mas, size);
}
//3. Задать пустой целочисленный массив размером 8.
//Написать функцию, которая с помощью цикла заполнит его
//значениями 1 4 7 10 13 16 19 22. Вывести массив на экран.
//Для продвинутых :
void FillArr(int* mas, int length)
{
	int num = 1;
	const int step = 3;
	for (size_t i = 0; i < length; i++)
	{
		mas[i] = num;
		num += step;
	}
}
inline void Task3()
{
	const int size = 5;
	int mas[size] = { 0,1,0,1,0 };
	FillArr(mas, size);
	PrintMas(mas, size);
}
//4. * Написать функцию, которой на вход подаётся
//одномерный массив и число n(может быть положительным,
//или отрицательным), при этом метод должен циклически
//сместить все элементы массива на n позиций.
void RotateLeft(int* mas, int length)
{
	int temp = mas[0];
	for (size_t i = 0; i < length-1; i++)
	{
		mas[i] = mas[i+1];
	}
	mas[length-1] = temp;
}
void RotateRight(int* mas, int length)
{
	int temp = mas[length-1];
	for (size_t i = length-1; i > 0; i--)
	{
		mas[i] = mas[i - 1];
	}
	mas[0] = temp;
}

void RotateMas(int* mas, int length, int shift)
{
	for (size_t i = 0; i < abs(shift); i++)
	{ 
		if (shift > 0)
			RotateRight(mas, length);
		else
			RotateLeft(mas, length);
	}
}

void Task4()
{
	const int size = 10;
	int mas[size];
	InitArray(mas, size);
	PrintMas(mas, size);
	RotateMas(mas, size, 3);
	PrintMas(mas, size);
	RotateMas(mas, size, -3);
	PrintMas(mas, size);

}
//5. * *Написать метод, в который передается не пустой
//одномерный целочисленный массив, метод должен вернуть
//истину если в массиве есть место, в котором сумма левой и
//правой части массива равны.Примеры: checkBalance([1, 1,
//1, || 2, 1]) → true, checkBalance([2, 1, 1, 2, 1]) → false,
//checkBalance([10, || 1, 2, 3, 4]) → true.Абстрактная граница
//показана символами || , эти символы в массив не входят.
int RightSum(int* mas, int length,int index)
{
	int sum = 0;
	for (size_t i = index + 1; i < length; i++)
	{
		sum += mas[i];
	}
	return sum;
}
int LeftSum(int* mas, int length, int index)
{
	int sum = 0;
	for (size_t i = 0; i <= index; i++)
	{
		sum += mas[i];
	}
	return sum;
}

bool checkBalance(int* mas, int length)
{
	for (size_t i = 0; i < length-1; i++)
	{
		if (LeftSum(mas, length,i) == RightSum(mas, length,i))
		{
			return true;
		}
	}
	return false;
}

void Task5()
{
	int mas[] = {2,1,2,1};
	const int size = sizeof(mas)/sizeof(int);

	//InitArray(mas, size);
	if (checkBalance(mas, size))
		cout << "Balanced" << endl;
	else
		cout << "Not balanced" << endl;
}

int main()
{
	Task1();
	Task2();
	Task3();
	Task4();
	Task5();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
