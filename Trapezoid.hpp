#ifndef TRAPEZOID_HPP
#define TRAPEZOID_HPP

#include <bits/stdc++.h>
#include "Vec2.hpp"

using namespace std;

//������� �����
template<class T>
double sqr(T val) {
	return val * val;
}

template<class T>
struct Trapezoid {
	Vec2<T> corner; // ����� ������ ����
	T a, b, c, d; // �����, �������, ������, ������ �������
	double h; // ������ ��������
	vector<Vec2<double>> pts; // ���������� �����

	// �����������
	Trapezoid(Vec2<T> _cor, T _a, T _b, T _c, T _d): corner(_cor), a(_a), b(_b), c(_c), d(_d), h((double) (sqr(a)) - sqr((d - b) / 2.)) {
		pts.push_back(Vec2<double> (_cor.x, _cor.y));
		pts.push_back(Vec2<double> (_cor.x + d, _cor.y));
		pts.push_back(Vec2<double> (_cor.x + b + (d - b) / 2., _cor.y + h));
		pts.push_back(Vec2<double> (_cor.x + (d - b) / 2., _cor.y + h));
	}
};

// �����
template<class T>
ostream& operator<< (ostream& os, const Trapezoid<T>& trap) {
	cout << "Trapezoid[ ";
	for(auto it: trap.pts) {
		cout << it << " ";
	}
	cout << "]";
	return os;
}

//�������
template<class T>
double getArea(const Trapezoid<T>& trap) {
	return (trap.b + trap.d) * trap.h / 2.;
}

#endif