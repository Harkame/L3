package fr.harkame.l3.math.tp2;

public final class Arbre 
{
	private int nombre_points;
	private int nombre_paires_points;
	private Point [] points;
	private int [][] edge;
	private int [][] arbre;
	
	public Arbre(int p_nombre_points)
	{
		nombre_points 		 = p_nombre_points;						  // n
		nombre_paires_points = nombre_points * (nombre_points - 1) / 2; // m
		points 				 = new Point[nombre_points];
		edge 			 	 = new int[nombre_paires_points][3];
		arbre				 = new int[nombre_points - 1][2];
	}
	
	public final void genererPointsRandom()
	{
		for(int index = 0; index < points.length; index++)
		{
			points[index] = new Point();
			points[index].genererCoordonneeRandom(0, 612, 0, 792);
		}
	}
	
	/**
	 * Genere edge
	 */
	public final void distances()
	{
		int e = 0;
		for(int i = 0; i < nombre_points; i++)
			for(int j = i + 1; j < nombre_points; j++)
			{
				
				edge[e][0] = i;
				edge[e][1] = j;
				edge[e][2] = (int) Math.pow(points[j].getabscisse() - points[i].getabscisse(), 2) + (int) Math.pow(points[j].getordonnee() - points[i].getordonnee(), 2);
				e++;
			}			
	}
	
	/**
	 * Trie edge dans l'ordre croissant
	 */
	public final void tri()
	{
    	int point_a  = 0;
    	int point_b  = 0;
    	int distance = 0;
	    for (int i = 0 ; i < edge.length; i++)
	         for (int j = edge.length - 1; j > i; j--)
                if (edge[j][2] < edge[j - 1][2])
                {
                	point_a  = edge[j - 1][0];
                	point_b  = edge[j - 1][1];
                	distance = edge[j - 1][2];
                    edge[j - 1][0]  = edge[j][0];
                    edge[j - 1][1] = edge[j][1];
                    edge[j - 1][2] = edge[j][2];
                    edge[j][0] = point_a;
                    edge[j][1] = point_b;
                    edge[j][2] = distance;
                }
	}
	
	public String toString()
	{
		StringBuilder string_builder = new StringBuilder();
		string_builder.append("--- Points ---\r\n\r\n");
		for(Point point : points)
			string_builder.append(point.toString() + "\r\n");
		string_builder.append("\r\n--- Edge ---\r\n\r\n");
		for(int index = 0; index < edge.length; index++)
			string_builder.append(edge[index][0] + " - " + edge[index][1] + " - " + edge[index][2] + "\r\n");
		return string_builder.toString();
	}

	public static void aff(int [] tab)
	{
		System.out.print("[");
		for(int index = 0; index < tab.length; index++)
			System.out.print(tab[index] + " ");
		System.out.println("]");
	}

	public static void main(String [] Args) throws Exception
	{
		Arbre arbre = new Arbre(4);
		arbre.genererPointsRandom();
		arbre.distances();
		System.out.println(arbre.toString());
		arbre.tri();
		System.out.println(arbre.toString());
	}
}