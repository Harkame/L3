#ifndef MUSEE_H_
#define MUSEE_H_

#include<iostream>
#include<cstring>

using namespace std;

class Musee
{

	private:
		string description;

	public:
		Musee();
		Musee(string);

		virtual ~Musee();

		virtual string get_description();
		virtual void set_description(string);

		virtual void saisie();
		virtual void affiche();
};

#endif
