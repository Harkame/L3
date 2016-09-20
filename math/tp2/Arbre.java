package math.tp1;

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
		nombre_paires_points = nombre_points*(nombre_points - 1) / 2; // m
		points 				 = new int[nombre_points];
		edge 				 = new int[nombre_paires_points][3];
		arbre				 = new int[nombre_points - 1][2];
	}
	
	public final void pointrandom()
	{
		
	}
	
	

	public static void main(String [] Args) throws Exception
	{
		Arbre arbre = new Arbre(8);
		arbre.pointrandom();
	}
}
