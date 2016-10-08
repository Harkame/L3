//Daviaud Louis, L3 - Informatique, groupe C

#include "fonctionsMysterieuses.h"
#include <cstdlib>
#include <iostream>
#include <cmath>


using namespace std;

/*
	g++ ./fonctionsMysterieuses.cpp ./fonctionsMysterieuses.o -o fm; ./fm;
*/

int main()
{
	// --- F1() ---

	/*
	// f1() : k * sqrt(n), k = 3
	for (int n = 0; n < 100000; n++)
		cout << float(f1(n) / sqrt(n)) << endl; // tend vers 3


	/*
	// verification
	cout << endl << "f1()" << endl;
	for (int n = 0; n < 20; n++)
		cout << int(f1(n)) << endl;
	cout << endl << "k * sqrt(n), k = 3" << endl;
	for (int n = 0; n < 20; n++)
		cout << int(3 * sqrt(n)) << endl;
	*/

	// --- F2() ---

	/*
	// f2() : k * n^5, k = 0.1
	for (int n = 0; n < 70; n++)
		cout << ((float) ( f2(n)) /  pow(n, 5)) << endl; // tend vers 0.1
	*/

	/*
	// verification
	cout << endl << "f2()" << endl;
	for (int n = 0; n < 20; n++)
		cout << int(f2(n)) << endl;
	cout << endl << "k * n^5, k = 0.1" << endl;
	for (int n = 0; n < 20; n++)
		cout << int(0.1 * pow(n,5)) << endl;
	*/

	// --- F3() ---

	/*
	// f3() : k * n^2, k = 0.5
	for (int n = 0; n < 100; n++)
		cout << float( f3(n) / pow(n, 2)) << endl; // tend vers 0.5
	*/

	/*
	// verification
	cout << endl << "[f3]" << endl;
	for (int n = 0; n < 20; n++)
		cout << long(f3(n)) << endl;
	cout << endl << "k * n^2, k = 0.5" << endl;
	for (int n = 0; n < 20; n++)
		cout << long(0.5 * pow(n, 2)) << endl;
	*/

	// --- F4() ---

	/*
	// f4() : k * log(n), k = 2, car c'est la croissance la plus lente
	for (int n = 0; n < 10000; n++)
		cout << float(f4(n) / log(n)) << endl; // tend vers 2
	*/

	/*
	// verification
	cout << endl << "f4()" << endl;
	for (int n = 0; n < 20; n++)
		cout << int(f4(n)) << endl;
	cout << endl << "k * log(n), k = 2" << endl;
	for (int n = 0; n < 20; n++)
		cout << int(2 * log(n)) << endl;
	*/

	// --- F5() ---

	/*
	// f5() : k * 2^n, k = 10
	for (int n = 0; n < 25; n++)
		cout << f5(n) / pow(2, n) << endl; // tend vers 10
	*/

	/*
	// verification
	cout << endl << "f5()" << endl;
	for (int n = 0; n < 20; n++)
		cout << int(f5(n)) << endl;
	cout << endl << "k * 2^n, k = 10" << endl;
	for (int n = 0; n < 20; n++)
		cout << int(10 * pow(2, n))<< endl;
	*/

	// --- F6() ---

	/*
	// f6() : k * 3^n, k = 20
	for (int n = 0; n < 20; n++)
		cout << f6(n) / pow(3, n) << endl; // tend vers 20
	*/

	/*
	// verification
	cout << endl << "f6()" << endl;
	for (int n = 0; n < 20; n++)
		cout << int(f6(n)) << endl;
	cout << endl << "k * 3^n, k = 20" << endl;
	for (int n = 0; n < 20; n++)
		cout << int(20 * pow(3,n)) << endl;
	*/
}
