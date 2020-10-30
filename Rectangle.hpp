#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <bits/stdc++.h>
using namespace std;

template<class T>
struct Rectangle {
	pair<T,T> corner; // ����� ������ ����
	T a, b; // ����� � ������� �������
	vector<pair<T,T>> pts; // ��� �����

	//�����������
	Rectangle(pair<T,T> _c, T _a, T _b): corner(_c), a(_a), b(_b) {
		pts.push_back(_c);
		pts.push_back(pair<T,T> (_c.first + b, _c.second));
		pts.push_back(pair<T,T> (_c.first + b, _c.second + a));
		pts.push_back(pair<T,T> (_c.first, _c.second + a));
	}
};

//�����
template<class T>
ostream& operator<< (ostream& os, const Rectangle<T>& rect) {
	cout << "Rectangle[ ";
	for(auto it: rect.pts) {
		cout << it << " ";
	}
	cout << "]";
	return os;
}

//������� ��������������
template<class T>
double getArea(const Rectangle<T>& rect) {
	return rect.a * rect.b;
}

#endif