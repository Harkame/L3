package poo.tp9;

import java.awt.Dimension;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import java.awt.event.MouseListener;

@SuppressWarnings("serial")

public class E2 extends JFrame
{
	private static int compteur = 0;
	private JButton oui;
	private JButton naupe;
	private JTextField j_text_field;
	
	  public E2()
	  {
		    setSize(300, 300);
		    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		    setLocationRelativeTo(null);
		    setLayout(new GridLayout(3, 5));
		    oui = new JButton("Oui");
		    naupe = new JButton("naupe");
		    j_text_field = new JTextField("");
		    oui.addMouseListener(new java.awt.event.MouseAdapter()
		    {
		        public void mouseClicked(java.awt.event.MouseEvent evt)
		        {
				    JOptionPane.showMessageDialog(oui,
				    		"T@ Kliqué : " + ++compteur, 
				             "1Tïtre",
				             JOptionPane.OK_CANCEL_OPTION);
		        }
		    });
		    naupe.addMouseListener(new java.awt.event.MouseAdapter()
		    {
		    	public void mouseEntered(java.awt.event.MouseEvent evt)
		        {
				    JOptionPane.showMessageDialog(oui,
				    		"TaRace", 
				             "1Tïtre",
				             JOptionPane.OK_CANCEL_OPTION);
		        }
		    });
		    getContentPane().add(oui);
		    getContentPane().add(naupe);
		    getContentPane().add(j_text_field);
		    
		    setVisible(true);
	  }
	
	public static void main(String [] Args)
	{
		E2 e2 = new E2();
	}
}
