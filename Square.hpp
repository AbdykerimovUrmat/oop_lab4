#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <bits/stdc++.h>
#include "Vec2.hpp"


using namespace std;
template<class T>
struct Square {
	Vec2<T> corner; // Левый нижний угол
  vector<Vec2<T>> pts;// все точки
  T a; // Длина стороны квадрата

  //конструктор
  Square(const Vec2<T>&_c, const T _a): corner(_c), a(_a) {
    pts.push_back(corner);
    pts.push_back(Vec2<T>(_c.x + a, _c.y));
    pts.push_back(Vec2<T>(_c.x, _c.y + a));
    pts.push_back(Vec2<T>(_c.x + a, _c.y + a));
  }
};

// вывод
template<class T>
ostream& operator<< (ostream &os, const Square<T>& sq) {
  cout << "Square[ ";
  for(auto it: sq.pts) {
    cout << it << " ";
  }
  cout << "]";
  return os;
}

//площадь
template<class T>
double getArea(Square<T> sq) {
	return sq.a * sq.a;
}
#endif