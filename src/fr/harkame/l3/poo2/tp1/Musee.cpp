#include "Musee.h"
#include "Objet.h"
#include "ObjetLegue.h"
//#include "ObjetSigne.h"


#define DEFAULT_DESCRIPTION "Sans_description"

Objet::Objet()
{
	descriptif = DEFAULT_DESCRIPTION;
	reference = compteur++;
}

Objet::Objet(char* p_source)
{
	descriptif = p_source;
}

Objet::~Objet()
{

}

void Objet::set_source()
{

}

string Objet::get_source()
{
	return descriptif;
}

void Objet::affiche()
{
	cout << "Reference  : "  << reference  << endl;
	cout << "Descriptif : "  << descriptif << endl;
}

void Objet::saisie()
{
	cin >> descriptif;
}

ObjetLegue::ObjetLegue() : Objet()
{

}

ObjetLegue::ObjetLegue(string test) : Objet(test)
{

}

void ObjetLegue::set_source(string test)
{

}

string ObjetLegue::get_source()
{
	return Objet::get_source();
}

void ObjetLegue::affiche()
{
}

void ObjetLegue::saisie()
{
}

int main()
{

	Objet* objet = new Objet();
	objet->saisie();
	objet->affiche();
}
