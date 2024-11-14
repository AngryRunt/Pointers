#include <iostream>
using namespace std;
void pprint(int *x) //ф-я типа войд с 1 параметром (целочисленный указатель *) потому что ничего не возвращает
{
    cout << *x <<endl;
}
void lprint(int &x) // ф-я с 1 параметром (ссылка на целочисленную переменную)
{
    cout << x << endl;
}
void masPrint(int *pMas2, int N2)
{
    cout << pMas2 << endl;
    cout << pMas2[N2 - 1] << "\t" << *(pMas2 + N2 - 1) << "\t" << pMas2 + N2 - 1 <<endl;
    cout << pMas2[N2 - 2] << "\t" << *(pMas2 + N2 - 2) << "\t" << pMas2 + N2 - 2 << endl;
}
void TwoInt(int* x, int* y)
{
    *x += *x;
    *y += *y;
    cout << "Внутри TwoInt" << endl;
    cout << "x = " << *x << endl;
    cout << "y = " << *y << endl;
}
void NotTwoInt(int x, int y)
{
    x += x;
    y += y;
    cout << "Внутри NotTwoInt" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}
int main() {
    {
        int *pa; // объявили указатель
        pa = new (int); // выделили память под 1 значение типа инт
        *pa = 5; // присвоили значение по указателю
        pprint(pa);
        delete (pa); //очистили память
        pa = NULL; // указатель теперь никуда не указывает
    }
    {
        int a = 7; // объявили и инициализировали переменную
        int &la = a; // получили ссылку на значение объявленной переменной
        lprint(la); // вызвали функцию и передали в неё ссылку
        // очищать память не надо потому что переменная объявлена на стеке и будет автоматически уничтожена после выхода за пределы области видимости
    }
    {
        int N = 10;
        int *pMas = new int[10];
        for (int i = 0; i < 10; i++)
        {
            pMas[i] = i + 1;
//pMas[i] = rand() % 100 + 1;
        }
        masPrint(pMas, N);
    }

    {
        int a = 5, b = 10;
        cout << "Начальная инициализация" << endl;
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        int *pa = &a;
        int *pb = &b;
        TwoInt(pa, pb);
        cout << "После TwoInt" << endl;
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        NotTwoInt(a, b);
        cout << "После NotTwoInt" << endl;
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }

    return 0;
}
