#include "File.h"
#include "MonException.h"

File::File()
{
	a_vector = new vector<int>();
}

File::~File()
{

}

void File::add(int p_value)
{
	a_vector->push_back(p_value);
}

void File::remove()
{

	MonException mon_exception;

	if(a_vector->size() == 0)
			throw mon_exception;
	else
		a_vector->pop_back();
}

void File::print()
{
	cout << "{ ";
	for (vector<int>::const_iterator i = a_vector->begin(); i != a_vector->end(); ++i)
    cout << *i << ' ';
	cout << '}'<< endl;
}

int main()
{
	File* file = new File();
	try
	{
		file->print();
		file->add(14);
		file->print();
		file->add(47);
		file->print();
		file->remove();
		file->print();
		file->remove();
		file->print();
		file->remove();
	}
	catch(MonException& mon_exception)
	{
		cout << mon_exception.message() << endl;
	}
}
