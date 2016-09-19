package uml.pokemon_terrestre;

public final class PokemonSportifs extends PokemonTerrestre
{
	private int nombre_battements;
	
	public PokemonSportifs()
	{
		super();
		nombre_battements = 0;
	}
	
	public PokemonSportifs(String p_nom, float p_poids, int p_nombre_pattes, float p_taille, int p_nombre_battements)
	{
		super(p_nom, p_poids, p_nombre_pattes, p_taille);
		nombre_battements = p_nombre_battements;
	}
	
	public String toString()
	{
		return super.toString() + "ma fréquence cardiaque est de " + nombre_battements + " pulsation(s) a la minute"; 
	}
}
