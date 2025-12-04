import java.io.*; 
import java.util.*;

public class Day1_part1 {
	public static void pInteger(Integer a){
		System.out.println(a);
	}

	public static void pString(String a){
		System.out.println(a);
	}

	public static void main(String[] args) {
		Scanner read = new Scanner(System.in);

		Hashtable< Integer, Integer > diff = new Hashtable< >();
		while (read.hasNextInt()) {
			int get = read.nextInt();
			Integer number = Integer.valueOf(get);
			Integer numberDiff = Integer.valueOf(2020 - get);
			if (diff.containsKey(number)) {
				numberDiff = diff.get(number);
				pInteger(number);
				pString("*");
				pInteger(numberDiff);
				pString("=");
				pInteger(number * numberDiff);
			}
			diff.put(Math.abs(numberDiff), number);
		}

		read.close();
	}
}