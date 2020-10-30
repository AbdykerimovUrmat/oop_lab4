#ifndef VEC2_HPP
#define VEC2_HPP

#include <bits/stdc++.h>
using namespace std;


//точка
template<class T>
struct Vec2 {
  T x, y; // координаты

 	// Конструктор
  Vec2(T _x, T _y): x(_x), y(_y) {};
};

//Вывод
template<class T>
ostream& operator<< (ostream& os, const Vec2<T>& pt) {
  cout << "{" << pt.x << ", " << pt.y << "}";
  return os;
}

#endif