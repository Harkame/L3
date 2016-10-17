package poo.tp9;

import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.Toolkit;
import java.awt.datatransfer.Clipboard;
import java.awt.datatransfer.StringSelection;

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

public class E4 extends JFrame implements KeyListener
{
	private JTextField j_text_field;
	
	  public E4()
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
	  public void keyPressed(KeyEvent e)
	  {
		 switch(System.getProperty("os.name"))
		 {
			 case "Windows 7":
			 case "Windows 8":
			 case "Windows 10":
			 case "Linux":
				 if(e.isControlDown())
				     switch(e.getKeyCode())
				     {
					     case KeyEvent.VK_C:
					     case KeyEvent.VK_V:
					     case KeyEvent.VK_X:
					     case KeyEvent.VK_COPY:
					     case KeyEvent.VK_PASTE:
					    	 StringSelection selection = new StringSelection("");
					    	 Clipboard clipboard = Toolkit.getDefaultToolkit().getSystemClipboard();
					    	 clipboard.setContents(selection, selection);
					    	 System.out.println("Kéblo");
					    	 break;
				    	 
				    	 default:
				    		 j_text_field.setText(j_text_field.getText().toUpperCase());
				    		 break;
				     }
			     		break;
						 case "mac os":
							 switch(e.getKeyCode())
						     {
							     case KeyEvent.VK_META:
							     case KeyEvent.VK_COPY:
							     case KeyEvent.VK_PASTE:
							    	 StringSelection selection = new StringSelection("");
							    	 Clipboard clipboard = Toolkit.getDefaultToolkit().getSystemClipboard();
							    	 clipboard.setContents(selection, selection);
							    	 System.out.println("Kéblo");
							    	 break;
						    	 
						    	 default:
						    		 j_text_field.setText(j_text_field.getText().toUpperCase());
						    		 break;
						     }
							 break;
		 }        	
	  }
	
	public static void main(String [] Args)
	{
		E4 e2 = new E4();
	}

	@Override
	public void keyReleased(KeyEvent e) {
      	
	  }

	@Override
	public void keyTyped(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}
}
