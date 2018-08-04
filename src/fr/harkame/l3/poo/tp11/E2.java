package fr.harkame.l3.poo.tp11;

import java.util.Scanner;

import fr.harkame.l3.poo.tp1.q1.Pokemon;
import fr.harkame.l3.poo.tp1.q1.pokemon_terrestre.PokemonCasanier;

public class E2
{
	public static Pokemon create(Class<? extends Pokemon> p_class)
		throws InstantiationException, IllegalAccessException
	{
		return p_class.newInstance();
	}

	public static void yolo(Pokemon p_pokemon) throws NoSuchMethodException, SecurityException
	{
		while(true)
		{
			// for(Method methode : p_pokemon.getClass().getMethods())
			// System.out.println(methode.toString());
			String t_commande = new Scanner(System.in).nextLine();
			System.out.println(p_pokemon.getClass().getMethod(t_commande));
		}
	}

	public static void main(String[] Args)
		throws InstantiationException, IllegalAccessException, NoSuchMethodException, SecurityException
	{
		Pokemon pokemon = create(PokemonCasanier.class);
		System.out.println(pokemon.toString());
		yolo(pokemon);
	}
}
