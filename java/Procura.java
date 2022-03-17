import java.util.Arrays;

public class Procura{

	public void swap(Object [] array, int i, int j){
		Object obj = array[i];
		array[i] = array[j];
		array[j] = obj;
	}
	
	public static boolean isElem(Object [] array, Object elem){
		for(int i = 0;i<array.length;i++)
			if(elem==array[i]) return true;
		
		return false;
	}

	public static int indexOfElem(Object [] array, Object elem){
		if(isElem(array,elem))
			for(int i = 0;i<array.length;i++)
				if(elem==array[i]) return i;
		return (-1);
	}

	public static Object [] semRepetidos(Object [] array){
		Object [] aux = new Object[array.length];
		int aind = 0;
		for(int i = 0;i<array.length;i++)
			if(!isElem(aux,array[i])) aux[aind++] = array[i];

		Object [] result = new Object[aind];
		for(int i = 0;i<result.length;i++) result[i] = aux[i];
		
		return result;
	}


	public static void main(String [] args){

		Object [] a = new Object[5];
		a[0] = 'a';
		a[1] = 'a';
		a[2] = 'b';
		a[3] = 'a';
		a[4] = 'a';
		System.out.println("array -> " +Arrays.toString(a));
		Object [] noRep = semRepetidos(a);
		System.out.println("semRepetidos -> " +Arrays.toString(noRep));
	}
}
