#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <bits/stdc++.h>


using namespace std;
template<class T>
struct Square {
	pair<T,T> corner; // Левый нижний угол
  vector<pair<T,T>> pts;// все точки
  T a; // Длина стороны квадрата

  //конструктор
  Square(const pair<T,T>&_c, const T _a): corner(_c), a(_a) {
    pts.push_back(corner);
    pts.push_back(pair<T,T>(_c.first + a, _c.second));
    pts.push_back(pair<T,T>(_c.first, _c.second + a));
    pts.push_back(pair<T,T>(_c.first + a, _c.second + a));
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