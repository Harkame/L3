package fr.harkame.l3.poo.tp1.q2;

public final class PetitBus extends Vehicule
{
	public PetitBus(String p_immatriculation, int p_chargement_maximum, int p_charge)
	{
		super(p_immatriculation, (float) 5, p_chargement_maximum, p_charge);
	}

	@Override
	public float vitesse()
	{
		return (float) 150;
	}
}
