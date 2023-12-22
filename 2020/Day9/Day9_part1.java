import java.io.*; 
import java.util.*;

public class Day9_part1 {
	public static void pInt(Integer a){
		System.out.println(a);
	}

	public static void pline(String a){
		System.out.println(a);
	}

	public static Boolean twoNumbers(Integer k, ArrayList< Integer > numbers){
		Hashtable< Integer, Integer > diff = new Hashtable< >();
		Integer i;
		for(i = 0; i < numbers.size(); i++){
			Integer number = numbers.get(i);
			Integer numberDiff = Integer.valueOf(k - number);
			if (diff.containsKey(number)) {
				return true;
			}
			diff.put(Math.abs(numberDiff), number);
		}
		return false;
	}	

	public static void main(String[] args) {
		Integer i = 0;
		ArrayList< Integer > numbers = new ArrayList< Integer >();
		Scanner read = new Scanner(System.in);
		while (read.hasNextInt() && i < 25) {
			Integer number = Integer.valueOf(read.nextInt());
			numbers.add(number);
			i++;
		}
		while (read.hasNextInt()) {
			Integer number = Integer.valueOf(read.nextInt());
			
			if(!twoNumbers(number, numbers)){
				pInt(number);
				break;
			}
			numbers.remove(0);
			numbers.add(number);
		}


		read.close();
	}
}