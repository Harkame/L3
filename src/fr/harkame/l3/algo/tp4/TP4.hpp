#ifndef TP4_H
#define TP4_H

typedef int indice;
typedef int valeur;

class ArbreComplet
{
  private:
    indice indice_premier_sommet_libre;
    int    nombre_maximal_sommets;
    int*   contenu;

  public:
    /*
    * Constructeur, le nombre maximal de sommet en parametre
    */
    ArbreComplet(int);

    /*
    * Ajoute une valeur en derniere position (indice_premier_sommet_libre)
    */
    void add(valeur);

    /*
    * Enleve le sommet d'indice en parametre,
    * le remplace par la derniere valeur de l'arbre
    * et decremente indice_premier_sommet_libre de 1
    */
    void remove(indice);

    /*
    * Retourne l'indice de la racine (ici 1)
    */
    indice racine();

    /*
    * Retourne la valeur du sommet d'indice en parametre
    */
    valeur getValeur(indice);

    /*
    * Affecte la valeur en parametre au sommet d'indice
    * en parametre
    */
    void setValeur(indice, valeur);

    /*
    * Retourne l'indice du pere du sommet d'indice
    * en parametre
    */
    indice pere(indice);

    /*
    * Retourne vrai si le sommet d'indice en parametre
    * possede un fils gauche
    */
    bool possedeFilsGauche(indice);

    /*
    * Retourne vrai si le sommet d'indice en parametre
    * possede un fils droit
    */
    bool possedeFilsDroit(indice);

    /*
    * Retourne l'indice du fils gauche du sommet
    * d'indice en parametre
    */
    indice filsGauche(indice);

    /*
    * Retourne l'indice du fils droit du sommet
    * d'indice en parametre
    */
    indice filsDroit(indice);

    /*
    * Retourne l'indice du fils du sommet d'indice en parametre
    * qui a la plus petite valeur
    */
    indice filsMin(indice p_sommet);

    /*
    * Retourne l'indice du dernier sommet de l'arbre,
    * indice_premier_sommet_libre - 1
    */
    indice dernierSommet();

    /*
    * Affiche l'arbre
    */
    void print();

    /*
    * Retourne la taille de l'arbre
    */
    int taille();

    /*
    * Retourne nombre_maximal_sommets
    */
    int tailleMax()
    {
      return nombre_maximal_sommets;
    }

    /*
    * Libere la mémoire
    */
    void deleteAll();
};

class Tas : ArbreComplet
{
  private:
    /*
    * Remonte un sommet d'indice en parametre,
    * si son pere a une valeur plus petite, jusqu'au
    * maximum possible
    */
    void remonter(indice);

    /*
    * Descent un sommet d'indice en parametre,
    * si un de ces fils est plus petits,
    * jusqu'au maximum possible
    */
    void descendre(indice);

    /*
    * Descrendre avec traces
    */
    void descendreDetails(indice);

  public:
    /*
    * Constructeur, le nombre maximal de sommet en parametre
    */
    Tas(int);

    /*
    * Ajoute une valeur en derniere position,
    * et la fait remonter (si possible)
    */
    void add(valeur);

    /*
    * "Transforme" le tableau en parametre en tas
    */
    void add(int*, int);

    /*
    * Enleve le sommet d'indice en parametre,
    * le remplace par la derniere valeur de l'arbre
    * et la fait descendre (si possible)
    */
    void remove(indice);

    /*
    * Remove avec traces
    */
    void removeDetails(indice);

    /*
    * Enleve la racine et retourne sa valeur
    */
    valeur retirerMin();

    /*
    * RetirerMin avec traces
    */
    valeur retirerMinDetails();

    /*
    * Retourne un tableau trie correspondant a l'arbre representant le tas courant
    */
    int* triParTas();

    /*
    * triParTas avec traces
    */
    int* triParTasDetails();

    /*
    * Retourne la taille du tas
    */
    int taille();

    /*
    * Affiche le tas
    */
    void print();

    /*
    * Rempli le tas avec des valeurs aleatoires
    */
    void remplireRandom();

    /*
    * Libere la mémoire
    */
    void deleteAll();
};

/*
* Affiche le tableau passe en parametre
*/
void print_tableau(int* p_tableau, int p_taille);

#endif
