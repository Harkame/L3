package tp3;

import javax.swing.JButton;
import javax.swing.JFrame;

public class FenBouton extends JFrame
{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public FenBouton()
	{
		setSize(400, 400);
		setTitle("Fenêtre à un bouton");

		JButton bouton = new JButton("Hello");
		this.add(bouton); // équivalent à add(bouton, "Center"), voir plus
						// loin
	}

	public static void main(String args[])
	{
		FenBouton f = new FenBouton();
		f.setVisible(true);
	}
}