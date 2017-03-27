all: m_clear m_bison m_flex m_compil

m_bison:
	bison -ydtv tableur.y

m_flex:
	flex tableur.l;

m_compil:
	g++ ./lex.yy.c ./y.tab.c -o tableur -L.;

m_clear:
	clear; ls;
