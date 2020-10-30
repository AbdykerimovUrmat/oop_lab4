#ifndef TRAPEZOID_HPP
#define TRAPEZOID_HPP

#include <bits/stdc++.h>

using namespace std;

//������� �����
template<class T>
double sqr(T val) {
	return val * val;
}

template<class T>
struct Trapezoid {
	pair<T,T> corner; // ����� ������ ����
	T a, b, c, d; // �����, �������, ������, ������ �������
	double h; // ������ ��������
	vector<pair<double, double>> pts; // ���������� �����

	// �����������
	Trapezoid(pair<T, T> _cor, T _a, T _b, T _c, T _d): corner(_cor), a(_a), b(_b), c(_c), d(_d), h((double) (sqr(a)) - sqr((d - b) / 2.)) {
		pts.push_back(pair<double, double> (_cor.first, _cor.second));
		pts.push_back(pair<double, double> (_cor.first + d, _cor.second));
		pts.push_back(pair<double, double> (_cor.first + b + (d - b) / 2., _cor.second + h));
		pts.push_back(pair<double, double> (_cor.first + (d - b) / 2., _cor.second + h));
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