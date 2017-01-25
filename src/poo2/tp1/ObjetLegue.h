#ifndef OBJETLEGUE_H_
#define OBJETLEGUE_H_

#include "Objet.h"

using namespace std;

class ObjetLegue : Objet
{
	private:
		string source;

	public:
		ObjetLegue();
		ObjetLegue(string);

		virtual ~ObjetLegue();

		virtual string get_source();
		virtual void set_source(string);

		virtual void saisie();
		virtual void affiche();
};

#endif /* OBJET_H_ */
