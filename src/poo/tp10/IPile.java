package poo.tp10;

public interface IPile<A>
{
	boolean estVide();

	void empile(A a);

	A depile();

	int nbElements();

	A sommet();
}
