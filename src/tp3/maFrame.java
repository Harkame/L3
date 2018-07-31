package tp3;

import javax.swing.*;

class MaFrame extends JFrame // classe publique ou pas : au choix
{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	// constructeur
	public MaFrame()
	{
		super(); // sinon, serait ajouté par le compilateur
		setTitle("Ma petite application");
		setSize(400, 400);
		setLocation(100, 100);
		setVisible(true);
	}

	public static void main(String[] Args)
	{

	}
}
