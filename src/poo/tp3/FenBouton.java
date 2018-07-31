package poo.tp3;

import java.awt.*;
import javax.swing.*;

public class FenBouton extends JFrame
{
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