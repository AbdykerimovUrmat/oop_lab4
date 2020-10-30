#ifndef TRAPEZOID_HPP
#define TRAPEZOID_HPP

#include <bits/stdc++.h>
#include "Vec2.hpp"

using namespace std;

//квадрат числа
template<class T>
double sqr(T val) {
	return val * val;
}

template<class T>
struct Trapezoid {
	Vec2<T> corner; // Левый нижний угол
	T a, b, c, d; // Левая, верхняя, правая, нижняя стороны
	double h; // высота трапеции
	vector<Vec2<double>> pts; // Координаты точек

	// Конструктор
	Trapezoid(Vec2<T> _cor, T _a, T _b, T _c, T _d): corner(_cor), a(_a), b(_b), c(_c), d(_d), h((double) (sqr(a)) - sqr((d - b) / 2.)) {
		pts.push_back(Vec2<double> (_cor.x, _cor.y));
		pts.push_back(Vec2<double> (_cor.x + d, _cor.y));
		pts.push_back(Vec2<double> (_cor.x + b + (d - b) / 2., _cor.y + h));
		pts.push_back(Vec2<double> (_cor.x + (d - b) / 2., _cor.y + h));
	}
};

// Вывод
template<class T>
ostream& operator<< (ostream& os, const Trapezoid<T>& trap) {
	cout << "Trapezoid[ ";
	for(auto it: trap.pts) {
		cout << it << " ";
	}
	cout << "]";
	return os;
}

//площадь
template<class T>
double getArea(const Trapezoid<T>& trap) {
	return (trap.b + trap.d) * trap.h / 2.;
}

#endif