package poo.tp1.q2;

public abstract class Vehicule
{
	private String	immatriculation;
	private float	poids;
	private float	chargement_maximum;
	private float	charge;

	public Vehicule()
	{
		immatriculation = "";
		poids = 0;
		chargement_maximum = 0;
		charge = 0;
	}

	public Vehicule(String p_immatriculation, float p_poids, float p_chargement_maximum, float p_charge)
	{
		immatriculation = p_immatriculation;
		poids = p_poids;
		chargement_maximum = p_chargement_maximum;
		charge = p_charge;
	}

	public float getCharge()
	{
		return charge;
	}

	public abstract float vitesse();
}
