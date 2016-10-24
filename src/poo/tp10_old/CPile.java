package poo.tp10;

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
		return false;
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
		return null;
	}

	@Override
	public String toString()
	{
		return linked_list.toString();
	}

	public static void main(String[] Args)
	{
		IPile<Integer> i_pile = new CPile<Integer>();
		System.out.println(i_pile.toString());
	}
}
