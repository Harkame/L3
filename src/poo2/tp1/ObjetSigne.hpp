#ifndef OBJETSIGNE_H_
#define OBJETSIGNE_H_

#include <cstring>
#include "Objet.h"

using namespace std;

class ObjetSigne : Objet
{
	private:
		string source;

	public:
		ObjetSigne();
		ObjetSigne(string);

		virtual ~ObjetSigne();

		virtual string* get_source();
		virtual void set_source(string);

		virtual void saisie();
		virtual void affiche();
};

#endif /* OBJET_H_ */
