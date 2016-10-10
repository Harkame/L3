package tp3;
import javax.swing.*; 

public abstract class TP7 
{ 
	public final void Q1()
	{
		JFrame f = new JFrame(); 
		f.setTitle("Ma petite application"); 
		f.setSize(400,400) ; // par défaut la taille est (0,0) 
		f.setLocation(100,100) ; // par défaut, coin supérieur gauche écran 
		// ou bien setBounds(100,100,400,400);  
		f.setVisible(true); // sinon la fenêtre n'est pas visible
	}
	
	public final void Q2()
	{
		
	}
	
	public final void Q3()
	{
		
	}
	
	public static void main(String args[]) 
	{ 
		 JFrame j_frame = new MaFrame();
	} 
} 