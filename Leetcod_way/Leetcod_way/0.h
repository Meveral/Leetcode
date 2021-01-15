#pragma once
#include"MeveralUse_HeadersUsual.h"
using namespace std;

/****************************************
*virtual table :

class class_B {
public:
	int a{ 1  };
	int b{ 10 };
	virtual void do_A() { cout << "This is do_A"<< endl; };
	virtual void do_B() { cout << "This is do_B" << endl; };
	char c;
};

typedef void(*func)();
	class_B te;

	int* _vptr =(int*)(&te);
	cout << "class_B的虚表地址：	\t" << _vptr << endl;

	int* _p_1th_func =(int*)*_vptr;
	cout << "第一个虚函数地址：		\t" << _p_1th_func << endl;

	int* _p_2th_func = ((int*)*_vptr + 1);
	cout << "第二个虚函数地址：		\t" << _p_2th_func << endl;

	func _1th_vfunc = func(*_p_1th_func);
	cout << "第一个虚函数：			\t";
	_1th_vfunc();

	func _2th_vfunc = func(*_p_2th_func);
	cout << "第二个虚函数：			\t";
	_2th_vfunc();
***************************************/
