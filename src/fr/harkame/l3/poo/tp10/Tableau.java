package fr.harkame.l3.poo.tp10;

import java.util.Arrays;

public class Tableau
{

	private int[] T;

	public Tableau(int... p_T)
	{
		T = p_T;
	}

	public void triBulles()
	{
		int i = T.length - 2;
		boolean ech = true;
		while(i >= 2 && ech)
		{
			ech = false;
			for(int j = 0; j <= i; j++)
				if(T[j] > T[j + 1])
				{
					int aux = T[j];
					T[j] = T[j + 1];
					T[j + 1] = aux;
					ech = true;
				}
			i--;
		}
	}

	public void affiche()
	{
		for(int i = 0; i < T.length; i++)
			System.out.print(T[i] + " ");
		System.out.println();
	}

	public static void main(String[] Args)
	{
		Tableau obj = new Tableau(42, 75, 36, 9, 12, 13);
		obj.affiche();
		obj.triBulles();
		obj.affiche();
	}
}
