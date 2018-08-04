#define EINIT  0

#define EI     7
#define EIF    8
#define ET     9
#define ETH    10
#define ETHE   11
#define ETHEN  12

#define EE     13
#define EEL    14
#define EELS   15
#define EELSE  16

#define EEN    17
#define EEND   18
#define EENDI  19
#define EENDIF 20

#define ETHR   21
#define ETHRO  22
#define ETHROW 23

#define EIN    24
#define EINT   25

#define EID    27

#define NBETAT 256

int TRANS[NBETAT][256];		/* table de transition : état suivant */
int JETON[NBETAT];		/* jeton à retourner */

int creerAfd()
{			/* Construction de l'AFD */
  int i;
  int j;			/* variables locales */
  for (i = 0; i < NBETAT; i++)
  {
    for(j=0;j<256;j++)
      TRANS[i][j] = -1; /* init vide */

    JETON[i] = 0;			/* init tous états non finaux */
  }

  class_all(EINIT, EID);

  TRANS[EINIT]['i'] = EI;
  TRANS[EINIT]['t'] = ET;
  TRANS[EINIT]['e'] = EE;

  TRANS[EI]['f']    = EIF;

  TRANS[EI]['n']    = EIN;

  TRANS[EIN]['t']   = EINT;

  TRANS[ET]   ['h'] = ETH;
  TRANS[ETH]  ['e'] = ETHE;
  TRANS[ETHE] ['n'] = ETHEN;

  TRANS[ETH]  ['r'] = ETHR;
  TRANS[ETHR] ['o'] = ETHRO;
  TRANS[ETHRO]['w'] = ETHROW;

  TRANS[EE]   ['l'] = EEL;
  TRANS[EEL]  ['s'] = EELS;
  TRANS[EELS] ['e'] = EELSE;

  TRANS[EE]   ['n'] = EEN;
  TRANS[EEN]  ['d'] = EEND;
  TRANS[EEND] ['i'] = EENDI;
  TRANS[EENDI]['f'] = EENDIF;

  TRANS[EIF] ['a']  = EID;
  TRANS[EIF] ['b']  = EID;
  TRANS[EIF] ['c']  = EIF;
  TRANS[EIF] ['d']  = EIF;

  JETON[EIF]        = 257;
  JETON[ETHEN]      = 258;
  JETON[ETHROW]     = 259;
  JETON[EENDIF]     = 260;
  JETON[EINT]       = 261;
  JETON[EID]        = 262;
}
