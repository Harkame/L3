package tp3;

import java.util.Scanner;
import javax.swing.*;

public class GraphConsole extends JFrame
{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public GraphConsole()
	{
		setSize(200, 200);
		setTitle("Première fenêtre");
	}

	public static void main(String args[])
	{
		GraphConsole f = new GraphConsole();
		f.setVisible(true);
		while(true)
		{
			System.out.println("nouveau titre?");
			Scanner sc = new Scanner(System.in);
			String rep = sc.nextLine();
			f.setTitle(rep);
		}
	}
}
