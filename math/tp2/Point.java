package math.tp1;

public final class Point
{
	private int abscisse;
	private int ordonnee;
	
	public Point()
	{
		abscisse = p_abscisse;
		ordonnee = p_ordonnee;
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
	
	private static int coordonneeRandom(int p_min, int p_max)
	{
		return (int) (Math.random() * (p_max - p_min) + p_min);
	}
	
	public static void main(String [] Args)
	{
		
	}
}
