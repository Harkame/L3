package fr.harkame.l3.poo.tp3;

import java.awt.FlowLayout;

import javax.swing.*;

public class FenFlowLayout extends JFrame
{
	private JButton[] boutons;

	public FenFlowLayout()
	{
		setSize(400, 400);
		setTitle("Fenêtre avec un FlowLayout");

		boutons = new JButton[5];
		for(int i = 0; i < boutons.length; i++)
			boutons[i] = new JButton("Bouton " + i);
		setLayout(new FlowLayout());
		for(int i = 0; i < boutons.length; i++)
			add(boutons[i]);
	}

	public static void main(String args[])
	{
		FenFlowLayout fen_flow_layout = new FenFlowLayout();
		fen_flow_layout.setVisible(true);
	}
}