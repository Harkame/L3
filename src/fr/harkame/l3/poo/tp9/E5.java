package fr.harkame.l3.poo.tp9;

import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.Toolkit;
import java.awt.datatransfer.Clipboard;
import java.awt.datatransfer.StringSelection;

import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;
import java.awt.event.MouseListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

@SuppressWarnings("serial")

public class E5 extends JFrame implements KeyListener
{
	private JTextField j_text_field;
	private JCheckBox j_check_box;
	
	  public E5()
	  {
		  JPanel j_panel = new JPanel();

			setContentPane(j_panel);
		setSize(300, 300);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLocationRelativeTo(null);
		setLayout(new GridLayout(3, 5));
		j_text_field = new JTextField("");
		j_text_field.addKeyListener(this);
		j_check_box = new JCheckBox("Masquer ou quoi ?");
		j_check_box.addMouseListener(new java.awt.event.MouseAdapter()
		{
		    public void mouseClicked(java.awt.event.MouseEvent evt)
		    {
		    	if(j_check_box.isSelected())
		    	{
		    		String s = j_text_field.getText();
		    		remove(j_text_field);
		    		j_text_field = new JPasswordField();
		    		j_text_field.setText(s);
		    		add(j_text_field);
		  		  j_panel.updateUI();
		    	}
		    	else
		    	{
		    		String s = j_text_field.getText();
		    		remove(j_text_field);
		    		j_text_field = new JTextField();
		    		j_text_field.setText(s);
		    		add(j_text_field);
		  		  j_panel.updateUI();
		    	}
		    }
		});
		getContentPane().add(j_check_box);
		getContentPane().add(j_text_field);
		setVisible(true);
	  }
	  
	  @Override
	  public void keyPressed(KeyEvent e)
	  {
     	
	  }
	
	public static void main(String [] Args)
	{
		E5 e2 = new E5();
	}

	@Override
	public void keyReleased(KeyEvent e) {
      	
	  }

	@Override
	public void keyTyped(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}
}
