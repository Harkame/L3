package fr.harkame.l3.poo.tp9;

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
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

@SuppressWarnings("serial")

public class E3 extends JFrame implements KeyListener
{
	private JTextField j_text_field;
	
	  public E3()
	  {
		    setSize(300, 300);
		    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		    setLocationRelativeTo(null);
		    setLayout(new GridLayout(3, 5));
		    j_text_field = new JTextField("");
		    j_text_field.addKeyListener(this);
		    getContentPane().add(j_text_field);
		    
		    setVisible(true);
	  }
	  
	  @Override
	    public void keyPressed(KeyEvent e) {
	        j_text_field.setText(j_text_field.getText().toUpperCase());
	    }
	
	public static void main(String [] Args)
	{
		E3 e2 = new E3();
	}

	@Override
	public void keyReleased(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void keyTyped(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}
}
