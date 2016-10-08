package poo.tp1.q2.copy;

public final class CamionCiterne extends Vehicule
{
	
	public CamionCiterne(String p_immatriculation, int p_chargement_maximum, int p_charge)
	{
		super(p_immatriculation, 3, 10, p_charge);
	}

	@Override
	public float vitesse() {
		if(getCharge() == 0)
			return 130;
		else if(getCharge() > 0 && getCharge() <= 1)
			return 110;
		else if(getCharge() > 1 && getCharge() <= 4)
			return 90;
		else
			return 80;
			
	}
}
