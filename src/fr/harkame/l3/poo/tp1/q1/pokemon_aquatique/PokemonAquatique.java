package fr.harkame.l3.poo.tp1.q1.pokemon_aquatique;

import fr.harkame.l3.poo.tp1.q1.Pokemon;

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

	@Override
	public float vitesse()
	{
		return getPoids() / 25 * nombre_nageoires;
	};

	@Override
	public String toString()
	{
		return super.toString() + nombre_nageoires + " nageoires.";
	}
}
