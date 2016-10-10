package tp3;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

public final class Calculatrice extends JFrame  implements ActionListener
{
	private JButton[]  boutons;
	private JButton[]  operateurs;
	private JTextField resultat;
	public Calculatrice()
	{
		  setSize(400, 400); 
		  setTitle("calculatrice"); 
		   
		  boutons = new JButton[10];
		  operateurs = new JButton[5];
		  int index;
		  for(index = 0; index < boutons.length; index++)
		  {
			  boutons[index] = new JButton("" + index);
			  boutons[index].addActionListener(this);
			  add(boutons[index]);
		  }
		  operateurs[0] = new JButton(".");
		  operateurs[1] = new JButton("+");
		  operateurs[2] = new JButton("-");
		  operateurs[3] = new JButton("*");
		  operateurs[4] = new JButton("/");
		  for(index = 0; index < operateurs.length; index++)
		  {
			  operateurs[index].addActionListener(this);
			  add(operateurs[index]);
		  }
		  resultat = new JTextField();
		  resultat = new JTextField("Hello", 20);
		  add(resultat);
		  setLayout(new FlowLayout()); 
		  setVisible(true);
	}
	
	 public void actionPerformed(ActionEvent e)
    {
	        System.out.println(e.toString());
    }
	
	public static void main(String [] Args)
	{
		Calculatrice  calculatrice = new Calculatrice();
	}
}
