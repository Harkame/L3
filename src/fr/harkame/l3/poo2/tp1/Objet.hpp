#ifndef OBJET_H_
#define OBJET_H_

using namespace std;

int compteur = 0;

class Objet
{
	private:
		string descriptif;
		int reference;

	public:
		Objet();
		Objet(char*);

		virtual ~Objet();

		virtual string get_source();
		virtual void set_source();

		virtual void affiche();
		virtual void saisie();
};

#endif
