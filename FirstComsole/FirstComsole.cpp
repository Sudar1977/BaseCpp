// FirstComsole.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;

// Перечисление - дни недели
enum Week { Mon, Tue, Wed, Thu, Fri, Sat, Sun };


struct Employee { // Новый тип данных Сотрудник
    long id; // ID сотрудника
    unsigned short age; // его возраст
    double salary; // его зарплата
};
enum CompanySize { CS_SMALL, CS_MIDDLE, CS_BIG }; // перечисление — размер компании

struct Company { // Новый тип данных Компания
    Employee people[30]; // Ее сотрудники (30 максимум)
    Employee director; // Директор
    CompanySize size; // Размер компании
    unsigned int PeopleNumber; // количество сотрудников
    bool isBankrupt; // Является ли компания банкротом (true / false)
};

struct TEmptyStruct
{
};

union EmployeeInfo { // Новый тип данных Информация о сотруднике
    long id; // ID сотрудника
    unsigned short age; // его возраст
    double salary; // его зарплата
};

struct MyDate {
    unsigned short Day : 5; // можно хранить 0..31
    unsigned short Month : 4; // можно хранить 0..15
    unsigned short Year : 7; // можно хранить 0..127
};

struct MyBoolean
{
    unsigned int Flag : 1; // битовый флаг
};


#include <iostream>
#include <clocale> // Для вызова функции setlocale
double var = 8.888;
int mainLocale()
{
    setlocale(LC_ALL, "Russian"); // подключаем русский язык в консоли
    int var = 1555;
    std::cout << "Локальная переменная: " << var << " Глобальная переменная: " << ::var;
    return 0;
}


int main()
{
    cout << "Hello World!\n";

    char Name[] = { 'J', 'o', 'n', '\0' }; // \0 - символ конца строки в С++
    char Name2[] = "Jon\0"; // строка это тоже массив символов
    cout << Name << " " << Name2 << endl; // выведет на экран: Jon Jon
    
    Name[0] = 'D';
    Name2[1] = 'a';
    std::cout << Name << " " << Name2 << std::endl; // выведет 14 на экран: Don Jan
    int Array[3][2] = { {1, 2}, {3, 4}, {5, 6} };
    Week work_days[4] = { Mon, Wed, Fri, Sat };
    Week holi_days[3] = { Tue, Thu, Sun };
    // Работаем с нашими массивами
    std::cout << "First work day: " << work_days[0] << std::endl;
    std::cout << "First holiday: " << holi_days[0] << std::endl;
    work_days[0] = Sun;
    holi_days[2] = Mon;

    Company comp;
    comp.director = { 125093, 45, 350'000.0 };
    comp.size = CS_MIDDLE;
    comp.PeopleNumber = 215;
    comp.people[0] = comp.director;
    comp.people[1] = { 134578, 34, 60'000.0 };

    TEmptyStruct s1;
    cout << "sizeof(s1)=" << sizeof(s1) << " sizeof(TEmptyStruct)=" << sizeof(TEmptyStruct) << endl;

    EmployeeInfo info;
    info.age = 25;
    cout << "info.salary=" << info.salary << endl; // Выведет на экран: -9.25596e+61
    cout << "info.age=" <<info.age << endl; // Выведет на экран: 25
    cout << "info.id=" << info.id << endl; // Выведет на экран: -859045863
    info.salary = 175'000.0;
    cout << "info.salary=" << info.salary << endl; // Выведет на экран: 175000
    cout << "info.age=" << info.age << endl; // Выведет на экран: 0
    cout << "info.id=" << info.id << endl; // Выведет на экран: 0

    MyDate date1 = { 31, 01, 20 };
    cout << "sizeof(date1)=" << sizeof(date1); // выведет на экран 2

    MyBoolean mybool;
    mybool.Flag = 1; // можно записать только 0 или 1 так как мы дали полю только 1 бит.
    mainLocale();

    cin.get();
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
