import java.io.*; 
import java.util.*;

public class Day1_part2 {
	public static void pInteger(Integer a){
		System.out.println(a);
	}

	public static void pString(String a){
		System.out.println(a);
	}

	public static void main(String[] args) {
		Scanner read = new Scanner(System.in);

		ArrayList< Integer > list = new ArrayList< Integer >();
		while (read.hasNextInt()) {
			int get = read.nextInt();
			Integer number = Integer.valueOf(get);
			list.add(number);
		}

		int i, j;
		for(i = 0; i < list.size() - 2; i++){
			Hashtable< Integer, Integer > diff = new Hashtable< >();
			Integer sum = 2020 - list.get(i);
			for(j = i + 1; j < list.size(); j++){
				Integer numberDiff = Integer.valueOf(sum - list.get(j));
				if (diff.containsKey(numberDiff)) {
					pInteger(list.get(i));
					pString("*");
					pInteger(list.get(j));
					pString("*");
					pInteger(sum - list.get(j));
					pString("=");
					pInteger(list.get(i) * list.get(j) * (sum - list.get(j)));
				}
				diff.put(list.get(j), sum);
			}
		}
		read.close();
	}
}