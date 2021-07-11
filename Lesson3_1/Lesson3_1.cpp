// Lesson3_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <random>

#include <string>

using namespace std;

int32_t getRabdomNum(int32_t min, int32_t max)
{
    const static auto seed = chrono::system_clock::now().time_since_epoch().count();
    static  mt19937_64 generator(seed);
    uniform_int_distribution <int32_t> dis(min, max);
    return dis(generator);
}
void ArifmeticOperation()
{

    int a = 30 % 27;
    std::cout << a << std::endl; // напечатает 3
    a = 30 % 10;
    std::cout << a << std::endl; // напечатает 0
    a = 30 % 9;
    std::cout << a << std::endl; // напечатает 3
}

void IncDecOperation()
{
    int a = 10, b = 20;
    a++; // после этой строки а будет 11
    ++a; // после этой строки а будет 12
    b = a++; // b будет 12, a будет 13
    b = ++a; // b будет 14, а будет 14
}

void TernarOperation()
{
    int a = 100, b;
    b = (a > 50) ? a : -a; // b = 100, так как условие истинно (выбирается первое значение)
    std::cout << b << std::endl;
    b = (a > 150) ? a : -a; // b = -100, так как условие ложно (выбирается второе значение)
    std::cout << b << std::endl;
}
void BitOperation()
{
    int a, b = 0;
    int c = 0b0000'1111; // 15, 0xF
    a = b & c;
    std::cout << a << std::endl; // 0
    a = b | c;
    std::cout << a << std::endl; // 15
    a = b ^ c;
    std::cout << a << std::endl; // 15
    a = ~c;
    std::cout << a << std::endl; // -16 неожиданно?
    a = c << 1;
    std::cout << a << std::endl; // 30
}

void LogicOperation()
{
    int a = 10, b = 20;
    std::cout << "a=" << a << ",b=" << b << std::endl; // 0

    if (a > 0 && b > 0) // Если а > 0 и b > 0 то напечатай текст:
    {
        std::cout << "a and b > 0" << std::endl;
    }
    if (a > 0 || b > 0) // Если а > 0 или b > 0 то напечатай текст:
    {
        std::cout << "a or b > 0" << std::endl;
    }
    if (a != b) // Если а не равно b то напечатай текст:
    {
        std::cout << "a is not equal b" << std::endl;
    }
    const bool AnotEqualB = !(a == b); // true
}


int mainPtr() 
{
    int x, y, * ptr; // объявляем 3 переменные
    ptr = nullptr; // инициализируем указатель null, нулевым значением
    // на всякий случай =)
    x = -7;
    ptr = &x; // адрес переменной х записываем в переменную ptr
    y = *ptr; // Записываем в y значение на которое указывает указатель ptr
    *ptr = 3; // Записываем в ячейку (х) на которую ссылается указатель ptr число 3
    std::cout << "x = " << x << " y = " << y << endl; // вывод на экран x = 3 y = -7
    return 0;
}

struct Employee { // Новый тип данных Сотрудник
    long id; // ID сотрудника
    unsigned short age; // его возраст
    double salary; // его зарплата
};

int mainStructPtr() {
    Employee em1 = { 1234567, 30, 17'000.0 }; // переменная Сотрудник
    Employee* ptrEm = &em1; // настроем указатель на переменную em1;
    (*ptrEm).age = 31; // обновим в структуре поле age
    ptrEm->id = 9876543; // обновим в структуре поле id
    ptrEm->salary += 10'000;

    return 0;
}

int mainArrayPtr() {
    int Array[5], * pArr;
    pArr = &Array[0]; // адрес нулевого элемента сохраняем в указателе pArr
    *pArr = 10; // изменяем первый элемент массива
    pArr = pArr + 1; // увеличиваем указатель на 1 (чтоб указывал на 2й элемент массива)
    *pArr = 20; // изменяем второй элемент массива
    pArr += 1; // увеличиваем указатель на 1 (чтоб указывал на 3й элемент массива)
    *pArr = 30; // меняем третий элемент массива
    pArr++; // увеличиваем указатель на 1 с помощью операции инкремент
    *pArr = 40; // меняем четвертый элемент массива
    pArr = &Array[4]; // настраиваем на пятый элемент массива
    *pArr = 50; // меняем пятый элемент массива через указатель
    cout << Array[0] << endl << Array[1] << endl << Array[2] << endl << Array[3] << endl << Array[4] << endl;
    return 0;
}

int mainArrayPtrIndex() {
    int Array[5];
    int* pArr = NULL; // в старых проектах вы можете встретить NULL при инициализации указателей
    // но после стандарта C++11 рекомендуется использовать nullptr
    pArr = &Array[0]; // адрес нулевого элемента сохраняем в указателе pArr
    pArr[0] = 10; // изменяем первый элемент массива
    pArr[1] = 20; // изменяем второй элемент массива
    pArr[2] = 30; // меняем третий элемент массива
    pArr[3] = 40; // меняем четвертый элемент массива
    pArr[4] = 50; // меняем пятый элемент массива через указатель
    cout << Array[0] << endl << Array[1] << endl << Array[2] << endl << Array[3] << endl << Array[4] << endl;
    return 0;
}

void ConstantPointer()
{
    //1. Указатель на константные данные
    {
        int a, b;
        const int* ptr = &a;
        //*ptr = 10; // ОШИБКА компиляции нельзя менять константные данные
        ptr = &b; // но можно менять сам адрес на который указывает указатель
    }
    //2. Константный указатель(нельзя менять сам указатель, но можно менять данные)
    {
        int a, b;
        int* const ptr = &a;
        *ptr = 20; // записали в переменную а 20
        //ptr = &b; // ОШИБКА компиляции (нельзя менять константный указатель)
    }
    //3. Константный указатель на константные данные
    {
        int a, b;
        const int* const ptr = &a;
        //*ptr = 10; // ОШИБКА компиляции нельзя менять константные данные
        //ptr = &b; // ОШИБКА компиляции (нельзя менять константный указатель)
    }
}

void reference()
{
    int a = 1000;
    int& refA = a; // ссылка на переменную а
    refA = 20; // изменяем переменную а через ссылку на нее
    // не требуется * как с указателями
    std::cout << a << endl; // вывод на экран 20
}

void Pointer2Pointer()
{
    int a = 77;
    int* ptrA = &a;
    int** ppA = &ptrA;
    *ptrA = 88;
    std::cout << a << std::endl; // 88
    **ppA = 99;
    std::cout << a << std::endl; // 99
}

extern int a; // говорим что будем использовать переменную а из другого модуля
extern float b; // хотим иметь доступ к b из другой единицы трансляции

extern const int A; // говорим что будем использовать константу а из другого модуля
extern const float B; // хотим иметь доступ к b из другой единицы трансляции

void  cast()
{
    int a = 20, b = 30;
    float c = b / a;
    std::cout << c <<endl; // вывод на экран 1
    c = static_cast <float> (b) / a; // static_cast один из 4 операторов
    // приведения типа в С++
    std::cout << c << endl; // вывод на экран 1.5
    //2. Или можно использовать С - Style cast из языка С :
    c = float(b) / a; // или можно вот так (float)
    std::cout << c << endl; // вывод на экран 1.5

}

int mainString()
{
    string name, message; // Очень удобный тип данных string в отличии от char str [255]
    cout << "Hi, guy! Enter your name: ";
    cin >> name; // Считываем с клавиатуры имя пользователя
    message = "Have a good day, " + name; // такие строки можно даже складывать
    message[0] = '1';
    cout << message << endl; // Выводим на экран сообщение
    return 0;
}

void RvalueLvalue()
{
    int a, b=1;
    a = b; // и а и b это lvalue так как имеют
    // конкретное место в RAM (на стеке или в сегменте данных) для хранения значения
    a = 100; // 100 это rvalue, временное значение
    // (нет своего места в памяти в которое мы можем записать что-то другое).
}
int main()
{
    srand(time(0));
    std::cout << "Hello World!\n";
    int a = rand() %100;

    ArifmeticOperation();
    BitOperation();
    LogicOperation();
    TernarOperation();
    mainPtr();

    cout << a << endl;
    int& rB = a;//ссылка на а
    rB = 100;
    cout << a << endl;

    int* pC = &a;//указатель на а 
    *pC = 200;
    cout << a << endl;


    const size_t index = 10;
    int array[index];

    mainStructPtr();
    mainArrayPtr();
    int* a_null = NULL;
    int* a_nullptr = nullptr; 

    mainArrayPtrIndex();
    ConstantPointer();
    reference();
    Pointer2Pointer();
    cast();
    mainString();
    RvalueLvalue();

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
