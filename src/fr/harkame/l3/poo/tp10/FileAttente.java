package fr.harkame.l3.poo.tp10;

import java.util.ArrayList;

public class FileAttente
{
	protected ArrayList<Personne> contenu;

	public FileAttente()
	{
		contenu = new ArrayList<Personne>();
	}

	public void entre(Personne p)
	{
		contenu.add(p);
	}

	public Personne sort()
	{
		Personne p = null;
		if(!contenu.isEmpty())
		{
			p = contenu.get(0);
			contenu.remove(0);
		}
		return p;
	}

	public boolean estVide()
	{
		return contenu.isEmpty();
	}

	public String toString()
	{
		return "" + contenu.toString();
	}
}
