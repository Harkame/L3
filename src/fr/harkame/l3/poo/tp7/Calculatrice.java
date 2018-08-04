package fr.harkame.l3.poo.tp7;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener; 
import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
  
@SuppressWarnings("serial")
public final class Calculatrice extends JFrame
{
	private   JPanel container 	    = new JPanel();
	String[]  tab_string 		    = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", ".", "=", "/", "*", "-", "+"};
	JButton[] tab_button 		    = new JButton[tab_string.length];
	private   JLabel ecran 		    = new JLabel();
	private   Dimension dim 	    = new Dimension(50, 40);
	private   Dimension dim2 	    = new Dimension(50, 31);
	private   double chiffre1;
	private   boolean clicOperateur = false, update = false;
	private   String operateur 	    = "";
  
	public Calculatrice()
	{
		this.setSize(240, 260);
		this.setTitle("Calculatrice");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setLocationRelativeTo(null);
		this.setResizable(false);
		initComposant();
		this.setContentPane(container);
		this.setVisible(true);
	}
      
private void initComposant()
{
	Font police = new Font("Arial", Font.BOLD, 20);
	ecran = new JLabel("0");
	ecran.setFont(police);
	ecran.setHorizontalAlignment(JLabel.RIGHT);
	ecran.setPreferredSize(new Dimension(220, 20));
	JPanel operateur = new JPanel();      
	operateur.setPreferredSize(new Dimension(55, 220));
	JPanel chiffre = new JPanel();
	chiffre.setPreferredSize(new Dimension(165, 220));
	JPanel panEcran = new JPanel();
	panEcran.setPreferredSize(new Dimension(220, 30));

	for(int i = 0; i < tab_string.length; i++)
	{
		tab_button[i] = new JButton(tab_string[i]);
		tab_button[i].setPreferredSize(dim);
		switch(i)
		{
			case 11 :
				tab_button[i].addActionListener(new EgalListener());
				chiffre.add(tab_button[i]);
			break;
			case 13 :
				tab_button[i].addActionListener(new PlusListener());
				operateur.add(tab_button[i]);
			break;
			case 14 :
				tab_button[i].addActionListener(new MoinsListener());
				operateur.add(tab_button[i]);
			break;	
			case 15 :	
				tab_button[i].addActionListener(new MultiListener());
				operateur.add(tab_button[i]);
			break;
			case 16 :
				tab_button[i].addActionListener(new DivListener());
				operateur.add(tab_button[i]);
			break;
			default :
				chiffre.add(tab_button[i]);
				tab_button[i].addActionListener(new ChiffreListener());
			break;
		}
	}
    panEcran.add(ecran);
    panEcran.setBorder(BorderFactory.createLineBorder(Color.black));
    container.add(panEcran,  BorderLayout.NORTH);
    container.add(chiffre,   BorderLayout.CENTER);
    container.add(operateur, BorderLayout.EAST);
  }

private void calcul()
{
	if(operateur.equals("+"))
	{
		chiffre1 = chiffre1 + 
		Double.valueOf(ecran.getText()).doubleValue();
		ecran.setText(String.valueOf(chiffre1));
	}
	if(operateur.equals("-"))
	{
		chiffre1 = chiffre1 - 
		Double.valueOf(ecran.getText()).doubleValue();
		ecran.setText(String.valueOf(chiffre1));
	}          
	if(operateur.equals("*"))
	{
		chiffre1 = chiffre1 * 
		Double.valueOf(ecran.getText()).doubleValue();
		ecran.setText(String.valueOf(chiffre1));
	}     
	if(operateur.equals("/"))
	{
		try
		{
			chiffre1 = chiffre1 / 
			Double.valueOf(ecran.getText()).doubleValue();
			ecran.setText(String.valueOf(chiffre1));
		}
		catch(ArithmeticException e)
		{
			ecran.setText("0");
		}
	}
}

  class ChiffreListener implements ActionListener
  {
	  public void actionPerformed(ActionEvent action_event)
	  {
		  String str = ((JButton)action_event.getSource()).getText();
		  if(update)
			  update = false;
		  else
			  if(!ecran.getText().equals("0"))
				  str = ecran.getText() + str;	
		  ecran.setText(str);
	  }
  }

  class EgalListener implements ActionListener
  {
	  public void actionPerformed(ActionEvent action_event)
	  {
		  calcul();
		  update = true;
		  clicOperateur = false;
	  }
  }

	class PlusListener implements ActionListener
	{
		public void actionPerformed(ActionEvent action_event)
		{
			if(clicOperateur)
			{
				calcul();
				ecran.setText(String.valueOf(chiffre1));
			}
			else
			{
				chiffre1 = Double.valueOf(ecran.getText()).doubleValue();
				clicOperateur = true;
			}
			operateur = "+";
			update = true;
		}
	}

	class MoinsListener implements ActionListener
	{
		public void actionPerformed(ActionEvent arg0)
		{
			if(clicOperateur)
			{
				calcul();
				ecran.setText(String.valueOf(chiffre1));
			}
			else
			{
				chiffre1 = Double.valueOf(ecran.getText()).doubleValue();
				clicOperateur = true;
			}
			operateur = "-";
			update = true;
		}
  }

	class MultiListener implements ActionListener
	{
		public void actionPerformed(ActionEvent arg0)
		{
			if(clicOperateur){
			calcul();
			ecran.setText(String.valueOf(chiffre1));
			}
			else
			{
				chiffre1 = Double.valueOf(ecran.getText()).doubleValue();
				clicOperateur = true;
			}
			operateur = "*";
			update = true;
		}
	}
	
	class DivListener implements ActionListener
	{
		public void actionPerformed(ActionEvent arg0)
		{
			if(clicOperateur)
			{
				calcul();
				ecran.setText(String.valueOf(chiffre1));
			}
			else
			{
				chiffre1 = Double.valueOf(ecran.getText()).doubleValue();
				clicOperateur = true;
			}
			operateur = "/";
			update = true;
		}
	}
  
	public static void main(String [] Args)
	{
		Calculatrice calculatrice = new Calculatrice();
	}
}