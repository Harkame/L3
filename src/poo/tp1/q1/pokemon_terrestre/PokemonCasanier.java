package poo.tp1.q1.pokemon_terrestre;

public final class PokemonCasanier extends PokemonTerrestre
{
	private float heure_devant_tv;

	public PokemonCasanier()
	{
		super();
		heure_devant_tv = 0;
	}

	public PokemonCasanier(String p_nom, float p_poids, int p_nombre_pattes, float p_taille,
		int p_nombre_heure_devant_tv)
	{
		super(p_nom, p_poids, p_nombre_pattes, p_taille);
		heure_devant_tv = p_nombre_heure_devant_tv;
	}

	@Override
	public String toString()
	{
		return super.toString() + "je regarde la tv " + heure_devant_tv + "h par jour";
	}
}
