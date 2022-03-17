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
	
		System.out.println(Arrays.toString(aux));

		Object [] result = new Object[aind];
		for(int i = 0;i<result.length;i++) result[i] = aux[i];
		
		return result;
	}

	public static Object [] onlyRepetidos(Object [] array){
		Object[] semRepetidos = semRepetidos(array);
		Object [] aux = new Object[array.length-semRepetidos.length];
		int i = 0;
		for(int j = 0;j<array.length;j++){
			while(j<semRepetidos.length)
				if(array[j]!=semRepetidos[j]) aux[i++] = array[j];
			aux[j] = array[j];
		}
		
		return aux;
	}


	public static void main(String [] args){

		// Swap
		// isElem
		// IndexOfElem
		// SemRepetidos
		// Repetidos

		Object [] a = new Object[3];
		a[0] = 'a';
		a[1] = 'b';
		a[2] = 'a';
		System.out.println("array -> " +Arrays.toString(a));
		Object [] noRep = semRepetidos(a);
		System.out.println("semRepetidos -> " +Arrays.toString(noRep));
		Object [] onlyRep = onlyRepetidos(a);
		System.out.println("onlyRepetidos -> " +Arrays.toString(onlyRep));
	}
}
