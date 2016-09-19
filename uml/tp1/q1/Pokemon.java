package uml.TP1.q1;

public abstract class Pokemon
{
	private String nom;
	private float poids;
	
	public Pokemon()
	{
		nom = "";
		poids = 0;
	}
	
	public Pokemon(String p_nom, float p_poids)
	{
		nom = p_nom;
		poids = p_poids;
	}
	
	public abstract float vitesse();
	
	public String toString()
	{
		return "Je suis le Pokemon " + nom + " mon poids est de " + poids + " kg, ma vitesse est de " + vitesse() + " km/h j'ai ";
	}
	
	public float getPoids()
	{
		return poids;
	}
}
