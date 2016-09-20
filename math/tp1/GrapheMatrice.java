package math.tp1;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public final class GrapheMatrice
{
	private int 	 nombre_sommets;
	private int [][] aretes;
	private int []   composantes;
	
	public GrapheMatrice()
	{
		nombre_sommets  = 0;
		aretes 			= new int [0][0];
		composantes 	= new int [0];
	}
	
	public GrapheMatrice(int p_nombre_sommets, int p_nombre_aretes) throws Exception
	{
		if((p_nombre_sommets * (p_nombre_sommets - 1) / 2 < p_nombre_aretes))
				throw new Exception("Nombre d'aretes trop eleve!");
		nombre_sommets = p_nombre_sommets;
		aretes = new int [p_nombre_aretes][2];
		composantes = new int [nombre_sommets];	
	}
	
	public GrapheMatrice(int p_nombre_sommets, int ... p_aretes)
	{
		nombre_sommets = p_nombre_sommets;
		aretes = new int [p_aretes.length][2];
		for(int ligne = 0; ligne < aretes.length; ligne += 2)
		{
			aretes[ligne][0] = p_aretes[ligne];
			aretes[ligne][1] = p_aretes[ligne + 1];
		}
		composantes = new int [nombre_sommets];	
	}
	
	private final void genererAretesRandom()
	{
		for(int ligne = 0; ligne < aretes.length; ligne++)
		{
			int t_x_random = valeurRandom(0, nombre_sommets);
			int t_y_random = valeurRandom(0, nombre_sommets);
			if(!dejaPris(t_x_random, t_y_random) && t_x_random != t_y_random)
			{
				aretes[ligne][0] = t_x_random;
				aretes[ligne][1] = t_y_random;
			}
			else
			{
				while(dejaPris(t_x_random, t_y_random) || t_x_random == t_y_random)
				{
					t_x_random = valeurRandom(0, nombre_sommets);
					t_y_random = valeurRandom(0, nombre_sommets);
				}
				aretes[ligne][0] = t_x_random;
				aretes[ligne][1] = t_y_random;
			}
		}
	}
		
	private final void genererComposantes()
	{
		for(int indice = 0; indice < nombre_sommets; indice++)
			composantes[indice] = indice;
		
		for(int ligne = 0; ligne < aretes.length; ligne++)
		{
			int x = aretes[ligne][0];
			int y = aretes[ligne][1];
			if(composantes[x] != composantes[y])
			{
				int aux = composantes[x];
				for(int z = 0; z < nombre_sommets; z++)
				{
					if(composantes[z] == aux)
						if(composantes[z] < composantes[y])
							genererComposantesMinimum(composantes[y], composantes[z]);
						else
							composantes[z] = composantes[y];
				}
			}
		}
	}
	
	private final void genererComposantesMinimum(int composantes_y, int composantes_z)
	{
		for(int i = 0; i < nombre_sommets; i++)
		{
			if(composantes[i] == composantes_y)
				composantes[i] = composantes_z;
		}
	}
	
	/**
	 * Affiche le nombre de points isoles et la taille de chacune des composantes 
	 */
	public final void ecrituretailles()
	{
		int [] compteur_composantes = new int [nombre_sommets];
		for(int index = 0; index < composantes.length; index++)
			compteur_composantes[composantes[index]]++;
		ecrituretailles_aux_points_isoles(compteur_composantes);
		ecrituretailles_aux_composantes_taille(compteur_composantes);
	}
	
	/**
	 * Affiche le nombre de points isoles, ce qui n'aparaisse qu'une fois
	 * @param p_compteur_composantes Tableau contenant le nombre de points d'apparition de chaque points
	 */
	public final void ecrituretailles_aux_points_isoles(int [] p_compteur_composantes)
	{
		int compteur_composantes_isoles = 0;
		for(int index = 0; index < p_compteur_composantes.length; index++)
			if(p_compteur_composantes[index] == 1)
				compteur_composantes_isoles++;
		System.out.println("Il y a " + compteur_composantes_isoles + " points isoles");
	} 
	
	/**
	 * Affiche le nombre de composantes de meme taille et cette derniere.
	 * @param p_compteur_composantes Tableau contenant le nombre de points d'apparition de chaque points
	 */
	public final void ecrituretailles_aux_composantes_taille(int [] p_compteur_composantes)
	{
		int compteur;
		int taille_courante = 0;
		List<Integer> l = new ArrayList<Integer>();
		for(int i = 0; i < p_compteur_composantes.length; i++)
		{
			if(p_compteur_composantes[i] > 0)
				l.add(p_compteur_composantes[i]);
			p_compteur_composantes[i] = 0;
		}
		l.sort(new Comparator<Integer>()
		{
	        @Override
	        public int compare(Integer a, Integer b)
	        {

	            return  b.compareTo(a);
	        }
	    });
		for(int index = 0; index < l.size(); index++)
		{
			System.out.println("Il y a " + " composantes de taille "+ l.get(index));
		}
	}
	
	private final int nombre_occurence(int[] p_tab, int n)
	{
		int compteur = 0;
		for(int i : p_tab)
			if(i == n)
				compteur++;
		return compteur;
	}
	
	private boolean dejaPris(int p_x, int p_y)
	{
		for(int ligne = 0; ligne < aretes.length; ligne++)
			if((aretes[ligne][0] == p_x && aretes[ligne][1] == p_y) || 
					(aretes[ligne][0] == p_y && aretes[ligne][1] == p_x))
				return true;
		return false;
	}
		
	private static int valeurRandom(int p_min, int p_max)
	{
		return (int) (Math.random() * (p_max - p_min) + p_min);
	}
	
	public String toString()
	{
		return "";
	}
	
	private final void print_aretes()
	{
		for(int ligne = 0; ligne < aretes.length; ligne++)
			System.out.println("{" + aretes[ligne][0] + "," + aretes[ligne][1] + "}");
	}
	
	private final void print_composantes()
	{
		for(int indice = 0; indice < composantes.length; indice++)
			System.out.print(composantes[indice] + ", ");
		System.out.println("");
	}
	

	public static void main(String [] Args) throws Exception
	{
		GrapheMatrice graphe_matrice = new GrapheMatrice(6, 3);
		
		graphe_matrice.genererAretesRandom();
		graphe_matrice.genererComposantes();
		graphe_matrice.print_aretes();
		System.out.println("");
		graphe_matrice.print_composantes();
		System.out.println("");
		graphe_matrice.ecrituretailles();

	}
}
