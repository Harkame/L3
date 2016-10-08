package math.tp1;

import java.util.HashMap;
import java.util.Map;

public final class GrapheMatrice
{
	private int 	 nombre_sommets;
	private int [][] aretes;
	private int []   composantes;
		
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
		for(int index = 0; index < aretes.length; index += 2)
		{
			aretes[index][0] = p_aretes[index];
			aretes[index][1] = p_aretes[index + 1];
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
	
	private final void genererComposantesOpti()
	{
		
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
		HashMap<Integer, Integer> hash_map = new HashMap<Integer, Integer>();
		for(int index = 0; index < composantes.length; index++)
		{
			if(hash_map.get(composantes[index]) == null)
				hash_map.put(composantes[index], 1);
			else
				hash_map.put(composantes[index], hash_map.get(composantes[index]) + 1);
		}
		ecrituretailles_aux_points_isoles(hash_map);
		ecrituretailles_aux_composantes_taille(hash_map);
	}
	
	/**
	 * Affiche le nombre de points isoles, ce qui n'aparaisse qu'une fois
	 * @param p_compteur_composantes Tableau contenant le nombre de points d'apparition de chaque points
	 */
	public final void ecrituretailles_aux_points_isoles(HashMap<Integer, Integer> p_hash_map)
	{
		int compteur_points_isoles = 0;
		for (Map.Entry<Integer,Integer> e : p_hash_map.entrySet())
			if(e.getValue().equals(1))
				compteur_points_isoles++;
		System.out.println("Il y a " + compteur_points_isoles + " points isoles");
	} 
	
	/**
	 * Affiche le nombre de composantes de meme taille et cette derniere.
	 * @param p_compteur_composantes Tableau contenant le nombre de points d'apparition de chaque points
	 */
	public final void ecrituretailles_aux_composantes_taille(HashMap<Integer, Integer> p_hash_map)
	{
		HashMap<Integer, Integer> compteur_composantes = new HashMap<Integer, Integer>();
		for (Map.Entry<Integer,Integer> e : p_hash_map.entrySet())
			if(e.getValue() > 1)
				if(compteur_composantes.get(e.getValue()) == null)
					compteur_composantes.put(e.getValue(), 1);
				else
					compteur_composantes.put(e.getValue(), compteur_composantes.get(e.getValue()) + 1);
		for (Map.Entry<Integer,Integer> e : compteur_composantes.entrySet())
			System.out.println("Il y a " + e.getValue() + " composantes de taille " + e.getKey());
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
		StringBuilder string_builder = new StringBuilder();
		string_builder.append("[Aretes]\r\n");
		for(int indice = 0; indice < aretes.length; indice++)
			string_builder.append("{" + aretes[indice][0] + "," + aretes[indice][1] + "}\r\n");
		string_builder.append("\r\n");
		string_builder.append("[Composantes]\r\n");
		for(int indice = 0; indice < composantes.length; indice++)
			string_builder.append(composantes[indice] + ", ");
		string_builder.append("\r\n");
		return string_builder.toString();
	}

	public static void main(String [] Args) throws Exception
	{
		GrapheMatrice graphe_matrice = new GrapheMatrice(6, 3);
		
		graphe_matrice.genererAretesRandom();
		graphe_matrice.genererComposantes();
		System.out.println(graphe_matrice.toString());
		graphe_matrice.ecrituretailles();

	}
}
