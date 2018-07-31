package poo.tp1.q1.pokemon_terrestre;

import poo.tp1.q1.Pokemon;

public abstract class PokemonTerrestre extends Pokemon
{
	private int	nombre_pattes;
	private float	taille;

	public PokemonTerrestre()
	{
		super();
		nombre_pattes = 0;
		taille = 0;
	}

	public PokemonTerrestre(String p_nom, float p_poids, int p_nombre_pattes, float p_taille)
	{
		super(p_nom, p_poids);
		nombre_pattes = p_nombre_pattes;
		taille = p_taille;
	}

	@Override
	public float vitesse()
	{
		return nombre_pattes * taille * 3;
	};

	@Override
	public String toString()
	{
		return super.toString() + nombre_pattes + " pattes, ma taille est de " + taille + "m ";
	}
}
