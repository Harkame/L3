package fr.harkame.l3.algo.tp1;

public abstract class TP1Q1
{
	public final static void f1(long n)
	{
		int a = 0;
		for(long indice =0; indice < n; indice++)
			a = 1;
	}
	
	public final static void f3(long n)
	{
		int a = 0;
		for(long i = 0; i < n; i++)
			for(long j = 0; j < n; j++)
				for(long k = 0; k < n; k++)
					a = 1;
	}
	
	public final static int g2(long n)
	{
		if(n == 0)
			return 1;
		else
			return g2(n - 1) + g2(n - 1);
	}
	
	public final static int g3(long n)
	{
		if(n == 0)
			return 1;
		else
			return g3(n - 1) + g3(n - 1) + g3(n - 1);
	}
	
	public static void main(String [] Args)
	{
		long n = 3l;
		System.out.println("--- Q1 : Ecrire les programmes ---");
		System.out.println("f1");
		System.out.println("	n = " + n);
		f1(n);
		System.out.println("f2");
		System.out.println("	n = " + n);
		f3(n);
		System.out.println("g2");
		System.out.println("	n = " + n);
		g2(n);
		System.out.println("g3");
		System.out.println("	n = " + n);
		g3(n);
		System.out.println("\r\n--- Q2 : Ralentissements ---");
		System.out.println("f1 sans ralentissements : Debut");
		n = 99999999l;
		System.out.println("	n = " + n);
		f1(n);
		System.out.println("f1 sans ralentissements : Fin\r\n");
		System.out.println("f3 sans ralentissements : Debut");
		n = 99l;
		System.out.println("	n = " + n);
		f3(n);
		System.out.println("f3 sans ralentissements : Fin\r\n");
		System.out.println("g2 sans ralentissement : Debut");
		n = 27l;
		System.out.println("	n = " + n);
		g2(n);
		System.out.println("g2 sans ralentissement : Fin\r\n");
		System.out.println("g3 sans ralentissement : Debut");
		n = 15l;
		System.out.println("	n = " + n);
		g3(n);
		System.out.println("g3 sans ralentissement : Fin\r\n");
		System.out.println("f1 avec ralentissement : Debut");
		n = 2111999999l;
		System.out.println("	n = " + n);
		f1(n);
		System.out.println("f1 avec ralentissement : Fin\r\n");
		System.out.println("f3 avec ralentissement : Debut");
		n = 1500l;
		System.out.println("	n = " + n);
		f3(n);
		System.out.println("f3 avec ralentissement : Fin\r\n");
		System.out.println("g2 avec ralentissement : Debut");
		n = 30l;
		System.out.println("	n = " + n);
		g2(n);
		System.out.println("g2 avec ralentissement : Fin\r\n");
		System.out.println("g3 avec ralentissement : Debut");
		n = 19l;
		System.out.println("	n = " + n);
		g3(n);
		System.out.println("g3 avec ralentissement : Fin\r\n");
		System.out.println("\r\n--- Q3 : Differences ---");
		System.out.println("f3");
		n = 1500l;
		System.out.println("	n = " + n);
		f3(n);
		System.out.println("f1 - f3");
		n = 1500l;
		System.out.println("	n = " + n);
		f1(n);
		f3(n);
		System.out.println("g2");
		n = 30l;
		System.out.println("	n = " + n);
		g2(n);
		System.out.println("f3 - g2");
		n = 30l;
		System.out.println("	n = " + n);
		f3(n);
		g2(n);
		System.out.println("g3");
		n = 20l;
		System.out.println("	n = " + n);
		g3(n);
		System.out.println("g2 - g3");
		n = 20l;
		System.out.println("	n = " + n);
		g2(n);
		g3(n);
		System.out.println("\r\nAucune difference entre l'appel d'une fonction ou de deux,\ncar la plus \"grosse\" prend le dessus sur l'autre");
	}
}
