// Lesson4_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <clocale> // для вызова setlocale

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_X_CENTER = SCREEN_WIDTH / 2;
const int SCREEN_Y_CENTER = SCREEN_HEIGHT / 2;
const int SPRITE_ALPHA = 53;

void mainIf()
{
    cout << "Enter random integer number: ";
    int a;
    cin >> a; // Читаем число с клавиатуры
    if (a > 0) // Если а > 0
    {
        cout << "Your number is greater zero";
    }
    else if (a < 0) // Иначе
    {
        cout << "Your number is lower than zero";
    }
    else if (a == 0)
    {
        cout << "Your number equal zero";
    }
    cout << endl;
}

int mainSwitch()
{
    setlocale(LC_ALL, "Russian"); // подключаем русский язык
    char op;
    cout << "Введите символ арифметической бинарной операции: ";
    cin >> op;
    switch (op) {
    case '+':
        cout << "Это символ операции сложения.";
        break;
    case '-':
        cout << "Это символ операции вычитания.";
        break;
    case '*':
        cout << "Это символ операции умножения.";
        break;
    case '/':
        cout << "Это символ операции деления.";
        break;
    default:
        cout << "Это что-то исключая * / + -";
    }
    cout <<  endl;
    return 0;
}

void mainFor()
{
    /*
    for (инициализация; условие; изменение)
    {
    // some your code
    }
    */
    for (int i = -10; i <= 10; i = i + 1)
    {
        std::cout << i << " ";
    }
    //Любая из 3х секций : инициализация, условие, изменение может отсутствовать :
    int i = -10;
    for (; i <= 10;)
    {
        std::cout << i << " ";
        i = i + 1;
    }
}

void mainDoWhile()
{
    int i = -10;
    while (i <= 10) // вывод списка чисел с помощью while
    {
        std::cout << i << " ";
        i++;
    }
    std::cout << std::endl << i << std::endl;
    i = -10; // сбрасываем переменную в -10
    do { // вывод списка чисел с помощью do while
        std::cout << i << " ";
        i++;
    } while (i <= 10);
}

void maine_size_t()
{
    const int size = 10;
    int arr[size] = { 10, 20, 30, 40, 50, 40, 30, 20, 10, -10 };
    int sum = 0; // Здесь будем накапливать сумму
    for (size_t index = 0; index < size; index++)
    {
        sum += arr[index];
        cout << arr[index] << " ";
    }
    cout << " sum = " << sum;
}

void maineBreakeContinue()
{
    for (size_t i = 0; i < 100; i++)
    {
        cout << i << endl;
        if (i == 5) // если i равна 5
        {
            cout << "i == 5, досрочный выход из цикла";
            break;
        }
        else // иначе
        {
            continue; // переход на проверку условия в цикле
            cout << "Этот текст не будет никогда напечатан";
        }
    }
}

void mainInsertedLoops()
{
    const size_t size = 3;
    int array[size][size][size] = { { {1,2,3}, {4,5,6}, {7,8,9} },
    { {1,2,3}, {4,5,6}, {7,8,9} },
    { {7,8,1}, {3,4,5}, {6,7,8} } };
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            for (size_t k = 0; k < size; k++)
            {
                cout << array[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int mainGoTo()
{
    int i = 0;
label1: // метка для перехода с помощью goto
    cout << i++ << endl;
    if (i < 5) // если i < 5 идем на метку label1
        goto label1;
    cout << "The end of a program" << endl;
}

int main()
{
    std::cout << "Hello World!\n";
    mainIf();
    mainSwitch();

    const size_t SIZE = 10;
    int arr[SIZE];
    for (size_t i = 0; i < SIZE; i++)
    {
        arr[i] = i + 1;
        cout << arr[i] << "*(arr+i)" << *(arr+i) << endl;
    }
    mainFor();
    mainDoWhile();
    maine_size_t();
    maineBreakeContinue();
    std::cout << '\n';
    {
        int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
        for (int n : arr) // Переменная n должна быть того же типа что и наш массив arr
        {
            std::cout << n << ' ';
        }
        std::cout << '\n'; // перевод курсора на новую строку через символ \n
    }
    {
        int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
        for (const int& n : arr) // Переменная n должна быть того же типа что и наш массив arr
        {
            std::cout << n << ' ';
        }
        std::cout << '\n'; // перевод курсора на новую строку через символ \n
    }
    enum VeryLongDataType { YES, NO, MAYBE };
    VeryLongDataType array[] = { YES, NO, MAYBE, YES, NO, MAYBE, YES, NO, MAYBE };
    for (auto n : array)
    {
        std::cout << n << ' '; // при выводе элемент enum выводится как int
    }
    std::cout << '\n';
    mainInsertedLoops();
    mainGoTo();

    return 0;

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
