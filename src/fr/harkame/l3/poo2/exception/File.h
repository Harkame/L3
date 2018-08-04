#ifndef SRC_POO2_EXCEPTION_FILE_H_
#define SRC_POO2_EXCEPTION_FILE_H_

#include <vector>
#include <iostream>
#include <exception>

using namespace std;

class File
{
	private:
		vector<int>* a_vector;

	public:
		File();
		virtual ~File();
		void add(int);
		void remove();
		void print();
};

#endif
