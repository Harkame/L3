package uml.pokemon_aquatique;

import uml.TP1.q1.Pokemon;

public abstract class PokemonAquatique extends Pokemon
{
	private int nombre_nageoires;
	
	public PokemonAquatique()
	{
		super();
		nombre_nageoires = 0;
	}
	
	public PokemonAquatique(String p_nom, float p_poids, int p_nombre_nageoires)
	{
		super(p_nom, p_poids);
		nombre_nageoires = p_nombre_nageoires;
	}
	
	public float vitesse()
	{
		return getPoids() / 25 * nombre_nageoires;
	};
	
	public String toString()
	{
		return super.toString() + nombre_nageoires + " nageoires.";
	}
}
