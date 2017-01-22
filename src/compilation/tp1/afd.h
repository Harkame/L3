/**
 * @file afd.h
 * @author Michel Meynard
 * @brief DÃ©finition d'un AFD
 */
#define EINIT  0
#define EA     1
#define EAB    2
#define EABC   3
#define EB     4
#define EBD    5
#define NBETAT 6
#define EI     7
#define EIF    8
#define ET
#define ETH
#define ETHE
#define ETHEN
#define ET

int TRANS[NBETAT][256];		/* table de transition : Ã©tat suivant */
int JETON[NBETAT];		/* jeton Ã  retourner */

int creerAfd(){			/* Construction de l'AFD */
  int i;int j;			/* variables locales */
  for (i=0;i<NBETAT;i++){
    for(j=0;j<256;j++) TRANS[i][j]=-1; /* init vide */
    JETON[i]=0;			/* init tous Ã©tats non finaux */
  }
  /* Transitions de l'AFD */
  TRANS[EINIT]['a'] = EA;
  TRANS[EA]['b']    = EAB;
  TRANS[EAB]['b']   = EAB;
  TRANS[EAB]['c']   = EABC;
  TRANS[EINIT]['b'] = EB;
  TRANS[EB]['d']    = EBD;
  JETON[EA]         = JETON[EABC] = 1;
  JETON[EBD]=-1; /* Ã©tats finaux */
}
