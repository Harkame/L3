package poo.tp11;

import java.lang.reflect.Method;
import java.util.List;

public class E1
{

	private static List<String> list;

	private static void getMethods(int i)
	{
		Object o = list.get(i);
		Method[] methods = o.getClass().getMethods();
		for(Method m : methods)
		{
			String m_name = m.getName();
			Class m_returnType = m.getReturnType();
			Class[] m_paramTypes = m.getParameterTypes();
			for(int j = 0; j < m_paramTypes.length; j++)
				System.out.println(m_paramTypes[j].getName());
		}
	}
}
