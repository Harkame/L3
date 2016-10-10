package poo.tp7;

import java.awt.Dimension;

import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JTextField;

@SuppressWarnings("serial")
public class E4 extends JFrame
{
	private JMenuBar   j_menu_bar;
	private JMenu[]    j_menus;
	private JTextField j_text_field;
	
	public E4()
	{
		setSize(400, 200); 
		setTitle("E4");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		j_text_field = new JTextField();
		j_text_field.setPreferredSize(new Dimension(70, 30));
		j_menu_bar = new JMenuBar();
		j_menus = new JMenu[2];
		j_menus[0] = new JMenu("Fichier");
		j_menus[1] = new JMenu("Edition");
		j_text_field.setText("Yolo !");
		j_menus[0].add(new JMenuItem("Nouveau"));
		j_menus[0].add(new JMenuItem("Ouvrire"));
		j_menus[0].add(new JMenuItem("Fermer"));
		for(int index = 0; index < j_menus.length; index++)
		j_menu_bar.add(j_menus[index]);
		
		add(j_text_field, "South");
		setJMenuBar(j_menu_bar);
		setVisible(true);
	}
	
	public static void main(String [] Args)
	{
		E4 e4 = new E4();
	}
}
