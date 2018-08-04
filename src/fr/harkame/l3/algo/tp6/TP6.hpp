#ifndef TP6_H
#define TP6_H

#include <iostream>

using namespace std;

typedef int valeur;

class Sommet;

typedef Sommet* AB;

class Sommet
{
private:
    valeur racine;
    AB pere, fils_gauche, fils_droit;
    bool FGP;
    int hauteur, balanceGmoinsD;
    void print_aux();

public:
    /**
     * Constructeur d'un sommet de taille minimal, avec initialisation de la racine.
     */
    Sommet(valeur);

    /**
     * Constructeur par recopie.
     */
    Sommet(Sommet&);

    /**
     * Ajoute un fils gauche, la racine est en parametre.
     */
    void add_fils_gauche(valeur);

    /**
     * Ajoute un fils gauche, une arborescence.
     */
    void add_fils_gauche(AB);

    /**
    * Ajoute un fils droit, une arborescence.
    */
    void add_fils_droit(valeur);

    /**
     * Ajoute un fils droit, une arborescence.
     */
    void add_fils_droit(AB);

    /**
     * Supprime le fils gauche, mets le pointeur a NULL.
     */
    void remove_fils_gauche();

    /**
     * Supprime le fils droit, mets le pointeur a NULL.
     */
    void remove_fils_droit();

    /**
     * Indique si le sommet courant est une feuille
     *
     * @return True Si les fils gauche et droit sont NULL.
     */
    bool est_feuille();

    /**
     * Remplace le pere de l'arborescence courrante par l'arborescence en parametre.
     * Remplace egalement un des fils de l'arborescence pere par la nouvelle arborescence en parametre, selon l'attribut FDG.'
     */
    void replace_pere(AB);

    /**
     * Getter de FGP
     * @return True Si le sommet courrant est le fils gauche de son pere
     */
    bool get_FGP();

    /**
     * Getter de pere
     * @return Sommet Le pere du sommet courrant
     */
    AB get_pere();

    /**
     * Affiche l'arborescence au format : $RACINE ( $FILS_GAUCHE (...) $ FILS_DROIT (...)).
     */
    void print();

    AB plus_petit();

    AB rechercher_valeur(valeur);

    void inserer_valeur(valeur);

    friend std::string* TikzRecursAB(int ligne,int gauche, int droite, int numeroPere, int typeFils, AB Ar);
};

void SortieLatex(AB);
#endif
