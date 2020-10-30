#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <bits/stdc++.h>
#include "Vec2.hpp"
using namespace std;

template<class T>
struct Rectangle {
	Vec2<T> corner; // левый нижний угол
	T a, b; // Ћева€ и верхн€€ стороны
	vector<Vec2<T>> pts; // все точки

	//конструктор
	Rectangle(Vec2<T> _c, T _a, T _b): corner(_c), a(_a), b(_b) {
		pts.push_back(_c);
		pts.push_back(Vec2<T> (_c.x + b, _c.y));
		pts.push_back(Vec2<T> (_c.x + b, _c.y + a));
		pts.push_back(Vec2<T> (_c.x, _c.y + a));
	}
};

//вывод
template<class T>
ostream& operator<< (ostream& os, const Rectangle<T>& rect) {
	cout << "Rectangle[ ";
	for(auto it: rect.pts) {
		cout << it << " ";
	}
	cout << "]";
	return os;
}

//площадь пр€моугольника
template<class T>
double getArea(const Rectangle<T>& rect) {
	return rect.a * rect.b;
}

#endif