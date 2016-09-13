package math;

import java.util.Scanner;

public final class TP1
{
	
	private static int [][] edge;
	private static int []   comp;
	
		private static void grapheRandom(int n, int m)
		{
			for(int ligne = 0; ligne < edge.length; ligne++)
			{
				for(int colonne = 0; colonne < edge[0].length; colonne++)
				{
					edge[ligne][colonne] = valeurRandom(0, n);
				}
			}
		}
		
		private void composantes(int n, int m)
		{
			for(int sommet = 0; sommet < n; sommet++)
				comp[sommet] = sommet;
			
			for(int arete = 0; arete < m; arete++)
			{ 
				if(comp[edge[arete][0]] != comp[edge[arete][1]]) //edge[][x = 0] || edge[][x = 1]
				{
					int aux = comp[edge[arete][0]];
					for(int z = 0; z < n; z++)
						if(comp[z] == aux)
							comp[z] = comp[edge[arete][1]];
				}
			}
		}
	
		private static int saisireInt(String p_message)
		{
			System.out.print(p_message);
			return new Scanner(System.in).nextInt();
		}
		
		private static int valeurRandom(int p_min, int p_max)
		{
			return (int) (Math.random() * (p_max - p_min) + p_min);
		}
		
		private static void printedge()
		{
			System.out.println("\r\nedge :");
			for(int ligne = 0; ligne < edge.length; ligne++)
				System.out.println("{" + edge[ligne][0] + "," + edge[ligne][1] + "}");
		}

		public static void main(String [] Args)
		{
			int n = saisireInt("Nombre de sommets : ");
			int m = saisireInt("Nombre d'aretes : ");
			edge = new int [m][2];
			comp = new int[n];
			
			/** Debut : Excercice 1 **/
			
			grapheRandom(n, m);
			printedge();
			
			/** Fin : Excercice 1 **/
		}
}
