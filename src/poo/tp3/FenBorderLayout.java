package poo.tp3;

import javax.swing.JButton;
import javax.swing.JFrame;

public class FenBorderLayout extends JFrame
{
	private JButton[] boutons; // tableau de 5 boutons

	public FenBorderLayout()
	{
		setSize(400, 400);
		setTitle("Fenêtre avec un BorderLayout");

		boutons = new JButton[5];
		for(int i = 0; i < boutons.length; i++)
			boutons[i] = new JButton("Bouton " + i);
		add(boutons[0]); // au centre
		add(boutons[1], "North");// ou BorderLayout.NORTH
		add(boutons[2], "South");// ou BorderLayout.SOUTH
		add(boutons[3], "East"); // ou BorderLayout.EAST
		add(boutons[4], "West"); // ou BorderLayout.WEST
	}

	public static void main(String args[])
	{
		FenBorderLayout f = new FenBorderLayout();
		f.setVisible(true);
	}
}