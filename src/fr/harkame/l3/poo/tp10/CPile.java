package fr.harkame.l3.poo.tp10;

import java.util.LinkedList;

public final class CPile<A> implements IPile<A>
{

	LinkedList<A> linked_list;

	public CPile()
	{
		linked_list = new LinkedList<A>();
	}

	@Override
	public boolean estVide()
	{
		return 0 == linked_list.size();
	}

	@Override
	public void empile(A a)
	{
		linked_list.addLast(a);
	}

	@Override
	public A depile()
	{
		return linked_list.pollLast();
	}

	@Override
	public int nbElements()
	{
		return linked_list.size();
	}

	@Override
	public A sommet()
	{
		return linked_list.pop();
	}

	@Override
	public String toString()
	{
		return linked_list.toString();
	}

	public static void main(String[] Args)
	{
		IPile<Integer> i_pile = new CPile<Integer>();
		i_pile.empile(42);
		i_pile.empile(43);
		System.out.println(i_pile.toString());
		i_pile.depile();
		System.out.println(i_pile.toString());
	}
}
