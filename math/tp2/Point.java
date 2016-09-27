package math.tp1;

public final class Point
{
	private int abscisse;
	private int ordonnee;
	
	public Point()
	{
		abscisse = 0;
		ordonnee = 0;
	}
	
	public Point(int p_abscisse, int p_ordonnee)
	{
		abscisse = p_abscisse;
		ordonnee = p_ordonnee;
	}
	
	public final int getabscisse()
	{
		return abscisse;
	}
	
	public final int getordonnee()
	{
		return ordonnee;
	}
	
	public final void genererCoordonneeRandom(int p_min, int p_max)
	{
		abscisse = coordonneeRandom(p_min, p_max);
		ordonnee = coordonneeRandom(p_min, p_max);
	}
	
	public final void genererCoordonneeRandom(int p_abcisse_min, int p_abscisse_max, int p_ordonnee_min, int p_ordonnee_max)
	{
		abscisse = coordonneeRandom(p_abcisse_min, p_abscisse_max);
		ordonnee = coordonneeRandom(p_ordonnee_min, p_ordonnee_max);
	}
	
	private static int coordonneeRandom(int p_min, int p_max)
	{
		return (int) (Math.random() * (p_max - p_min) + p_min);
	}
	
	public String toString()
	{
		return "{" + abscisse + ", " + ordonnee + "}";
	}
	
	public static void main(String [] Args)
	{
		Point point = new Point();
		point.genererCoordonneeRandom(0, 612, 0, 792);
		System.out.println(point.toString());
	}
}
