#define TAILLE 4

/** Type pointeur sur une structure de jeu
 */
typedef struct mm* mm;
/** Structure de jeu contenant le mot secret ainsi que le nombre d'essais
 * effectués
 */
struct mm {
  char secret[TAILLE + 1];  // mot secret stocké dans une chaine de char
  int nbessais;			/* nombre d'essai */
};
/**
 * Crèe un nouveau jeu en générant aléatoirement un nouveau mot secret
 * composé de TAILLE lettres comprises entre 0 et 9.
 * @return un pointeur sur le jeu créé dans le tas (donc à detruire !)
 */
mm mm_creer();
/**
 * Supprime un jeu en désallouant la mémoire
 * @param mm un pointeur sur la structure de jeu
 */
void mm_detruire(mm);
/**
 * teste un mot essai face au mot secret stocké dans le jeu
 * @param jeu un pointeur sur la structure de jeu
 * @param essai la chaîne de caractères proposée par le joueur humain
 * @returns un entier contenant (TAILLE+1)*nb lettres bien placées + nb lettres
 * mal placées; -1 si l'essai est erroné (nb lettres, ...)
 */
int mm_test(mm jeu, char* essai);
/** Retourne le nb d'essais déjà effectués
 * @param jeu un pointeur sur la structure de jeu
 * @returns le nombre d'essais
 */
int mm_nbessais(mm jeu);
