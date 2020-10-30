#include <bits/stdc++.h>
#include "Vec2.hpp"
#include "Square.hpp"
#include "Rectangle.hpp"
#include "Trapezoid.hpp"
using namespace std;

/*

Абдыкеримов Урмат Эмирбекович
Вариант 26  (квадрат прямоугольник трапеция) 

Необходимо реализовать две шаблонных функции:

Функция print печати фигур на экран std::cout  (печататься должны координаты вершин фигур). Функция должна принимать на вход std::tuple с фигурами, согласно варианту задания (минимум по одной каждого класса).
Функция square вычисления суммарной площади фигур. Функция должна принимать на вход std::tuple с фигурами, согласно варианту задания (минимум по одной каждого класса).
 

Создать программу, которая позволяет:

Создает набор фигур согласно варианту задания (как минимум по одной фигуре каждого типа с координатами типа int и координатоми типа double).
Сохраняет фигуры в std::tuple
Печатает на экран содержимое std::tuple с помощью шаблонной функции print.
Вычисляет суммарную площадь фигур в std::tuple и выводит значение на экран.


*/

// Вывод tuple с помощью variadic template
template <size_t I = 0, typename... Ts> 
typename enable_if<I == sizeof...(Ts), 
                   void>::type 
printTuple(tuple<Ts...> tup) 
{ 
    return; 
} 
  
template <size_t I = 0, typename... Ts> 
typename enable_if<(I < sizeof...(Ts)), 
                   void>::type 
printTuple(tuple<Ts...> tup) 
{ 
  cout << get<I>(tup) << endl;
  printTuple<I + 1>(tup); 
} 

//Вычисление площади с помощью variadic template
template <size_t I = 0, typename... Ts> 
typename enable_if<I == sizeof...(Ts), 
                   double>::type 
summaryArea(tuple<Ts...> tup) 
{ 
    return 0; 
} 
  
template <size_t I = 0, typename... Ts> 
typename enable_if<(I < sizeof...(Ts)), 
                   double>::type 
summaryArea(tuple<Ts...> tup) 
{ 
  return getArea(get<I> (tup)) + summaryArea<I + 1>(tup); 
}


int main() {
	int x, y, a, b, c, d;

	//Trapezoid
	cout << "Enter left-bottom corner of trapezoid" << endl;
	cin >> x >> y;
	cout << "Enter lengths of left, upper, right, bottom sides of trapezoid" << endl;
	cin >> a >> b >> c >> d;
	while(min({a, b, c, d}) <= 0 or (a + b + c) <= d) {
		cout << "Cannot form trapezoid with these lengths or one them is not positive!" << endl;
		cout << "Enter them again:" << endl;
		cin >> a >> b >> c >> d;
	}
  Trapezoid<int> trap1(Vec2<int> (x, y), a, b, c, d);
	//
	//square
  cout << "Enter left-bottom corner of square" << endl;
	cin >> x >> y;
	cout << "Enter length of square side" << endl;
	cin >> a;
	while(a <= 0) {
		cout << "a is not positive!" << endl;
		cout << "Enter it again:" << endl;
		cin >> a;
	}

  Square<int> sq1(Vec2<int> (x, y), a);
	//
	//Rectangle
  cout << "Enter left-bottom corner of Rectangle" << endl;
	cin >> x >> y;
	cout << "Enter lengths of left and upper side of rectangle" << endl;
	cin >> a >> b;
	while(min(a, b) <= 0) {
		cout << "a or b is not positive!" << endl;
		cout << "Enter them again:" << endl;
		cin >> a >> b;
	}

  Rectangle<int> rect1(Vec2<int> (x, y), a, b); 
  //

  //
  Trapezoid<double> trap2(Vec2<double> (5.5, 5.5), 3.6, 5.8, 2.9, 6.7);
  Square<double> sq2(Vec2<double> (-4.8, -6.5), 10.2);
  Rectangle<double> rect2(Vec2<double> (-20.6, 16.5), 0.2, 0.7);
  //
	
  //tuple
	auto all = make_tuple(trap1, sq1, rect1, trap2, sq2, rect2);	
	printTuple(all);
	cout << summaryArea(all) << endl;	
}