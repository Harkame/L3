package poo.tp2;

public final class ListeChainee
{
	private Node root;
	
	public ListeChainee()
	{
		root = new Node();
	}
	
	public ListeChainee(String p_nom)
	{
		root = new Node(p_nom);
	}
		
	public final int size()
	{
			return size_aux(root);
	}
	
	private final int size_aux(Node p_node)
	{
		if(p_node.successeur == null)
			return 1;
		else
			return 1 + size_aux(p_node.successeur);
	}
	
	public final Node get(int p_index)
	{
		return get_aux(root, p_index - 1);
	}
	
	private final Node get_aux(Node p_node, int p_compteur)
	{
		if(p_compteur == 0)
			return p_node;
		else
			return get_aux(p_node.successeur, p_compteur - 1);
			
	}
	
	private final void add(String p_nom)
	{
		get(size()).successeur = new Node(p_nom);
	}
	
	private final void addDebut(String p_nom)
	{
		Node t_node = new Node(p_nom, root);
		assert(t_node.size() == root.size() + 1);
		//assert(t_node.size() == root.size() + 0);
		//assert(t_node.size() == root.size() + 2);
		root = t_node;
	}
	
	public final String toString()
	{
		return root.toString();
	}
	
	public final ListeChainee reverse()
	{
		ListeChainee liste_chainee = new ListeChainee(root.getnom());
		Node node = root.getsuccesseur();
		while(node != null)
		{
			liste_chainee.addDebut(node.getnom());
			node = node.getsuccesseur();
		}
		return liste_chainee;
	}
	
	public static void main(String [] Args)
	{
		ListeChainee liste_chainee = new ListeChainee("A");
		liste_chainee.add("B");
		liste_chainee.add("C");
		liste_chainee.add("D");
		liste_chainee.addDebut("E");
		System.out.println(liste_chainee.size());
		System.out.println(liste_chainee.toString());
		liste_chainee.reverse();
		ListeChainee liste_chainee_reverse = liste_chainee.reverse();
		System.out.println(liste_chainee_reverse);
	}
	
	private final class Node 
	{
		private String nom;
		private Node successeur;
		
		public Node()
		{
			nom 	   = "";
			successeur = null;
		}
		
		public Node(String p_nom)
		{
			nom 	   = p_nom;
			successeur = null;
		}
		
		public Node(String p_nom, Node p_successeur)
		{
			nom 	   = p_nom;
			successeur = p_successeur;
		}
		
		public final int size()
		{
				return size_aux(this);
		}
		
		private final int size_aux(Node p_node)
		{
			if(p_node.successeur == null)
				return 1;
			else
				return 1 + size_aux(p_node.successeur);
		}
		
		public String toString()
		{
			if(successeur == null)
				return "[Nom : " + nom + "] --> //";
			else
				return "[Nom : " + nom + "] --> " + successeur.toString();
		}
		
		public String getnom()
		{
			return nom;
		}
		
		public Node getsuccesseur()
		{
			return successeur;
		}
	}
}
