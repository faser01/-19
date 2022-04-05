#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>


using namespace std;

// Функция нахождения НОД
int NOD(int n1, int n2){
  int num;
  if (n1 == n2)   // если числа равны, НОД найден
    return n1;
  int d = n1 - n2; // Находим разность чисел
  if (d < 0) {      // если разность отрицательная,
     d = -d;     // меняем знак
    num = NOD(n1, d); // вызываем функцию NOD() для двух наименьших чисел
  }
  else{      // если разность n1-n2 положительная
     num = NOD(n2, d); // вызываем функцию NOD() для двух наименьших чисел
  }
    return num;
}

int resurveNumber(int x) {
    int y = 0;
    while (x) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    return y;
}

template <typename T> void showArray(T arr[], int length, int a, int b);

template <typename T> T sortArray(T arr[], int length, T a);

 template <typename T> void showArr(T array[], int length);

 template <typename T> int searchIndex(T array[], int length, T key, int begin =-1 ) {		
     for (int i = begin; i < length; i++)									
         if (array[i] == key)
             return i + 1;
     return -1;  
 }
 
 
int main() {
setlocale(LC_ALL, "Russian");
srand(time(NULL));
     int n1, n2, k, m;

    cout << "Задача на поиск наибольшего делителя\n\n";
    cout << " Введите первое число  = ";
    cin >> n1;
    cout << " Введите второе число  = ";
    cin >> n2;
    cout <<" Наибольший общий делитель = " << NOD(n1, n2)<< endl << endl;
    


    cout << "Задача 2 Перевернутое число\n";
    int x;
    cout << "Введите число: \n";
    cin >> x;
    cout << "Перевернутое число " << resurveNumber(x) << endl<< endl;
   
        
    //поиск номера элемента!
int  n;
cout << "Изначальный массив:\n";
int z1[10];
for (int i = 0; i < 10; i++) //заполнение масива 
    z1[i] = rand() % 100;
showArr(z1, 10);  //вывод массива с помощью функции
cout << "\b\b\n";
cout << "Введите искомое значение: ";
cin >> n;
cout << " Индекс :" << searchIndex(z1, 10, n) << "  \\ For User";
cout << endl;
cout << "Отсортированый массив: " << endl;
sortArray(z1,10, n);  //сортирует массив 
showArr(z1, 10);   //выводит массив
cout << endl << endl;



//Задача 4
cout << "Задача 4.\nВведите два числа : ";
cin >> k >> m;
int z2[10];
showArray(z2, 10, k, m);
cout << endl;
   
   


	return 0;
}

template <typename T> void showArr(T array[], int length) {   //функция вывода массива 
    cout << "[ ";
    for (int i = 0; i < length; i++)
        cout << array[i] << ", ";
    cout << "\b\b]\n";
}


  
void subarr(int array[], int length, int num) {
    int symIndex = searchIndex(array, length, num);  //В одной функции вызываем другую.
    if (symIndex == -1)    
        cout << "ERROR!";
    else
        for (int i = symIndex; i < length; i++)
            cout << array[i] << ", ";
           
}

template <typename T> T sortArray(T arr[], int length, T n) {
    int key = -1;
    for (int i = 0; i < length; i++)
        if (arr[i] == n) {
            key = i;
            break;
        }

    sort(arr + key + 1, arr + length);

    cout << " Введенное число = " << n << endl;
    return key;
}

template <typename T> void showArray(T arr[], int length, int x, int y) {
    cout << "[";
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % (y - x) + y;
        cout << arr[i] << ", ";
    }
    cout << "\b\b]\n";
}