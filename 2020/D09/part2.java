import java.io.*; 
import java.util.*;
import java.math.BigInteger; 

public class Day9_part2 {
	public static void pInt(BigInteger a){
		System.out.println(a);
	}

	public static void pline(String a){
		System.out.println(a);
	}

	public static void subArray(BigInteger k, ArrayList< BigInteger > numbers){
		BigInteger currSum, start, i, j, one, n;
		one = BigInteger.valueOf(1);
		n = BigInteger.valueOf(numbers.size());
		currSum = numbers.get(0);
		start = BigInteger.valueOf(0);

		for(i = one; i.compareTo(n) <= 0; i = i.add(one)){
			while(currSum.compareTo(k) == 1 && start.compareTo(i.subtract(one)) == - 1){
				currSum = currSum.subtract(numbers.get(start.intValue()));
				start = start.add(one);
			}
			if(currSum.compareTo(k) == 0){
				pInt(currSum);

				BigInteger min = numbers.get(start.intValue());
				BigInteger max = numbers.get(start.intValue());
				for(j = start; j.compareTo(i.subtract(one)) <= 0; j = j.add(one)){
					if(min.compareTo(numbers.get(j.intValue())) == 1){
						min = numbers.get(j.intValue());
					}
					if(max.compareTo(numbers.get(j.intValue())) == -1){
						max = numbers.get(j.intValue());
					}
				}
				pInt(min.add(max));
				break;
			}

			if(i.compareTo(n) == -1){
				currSum = currSum.add(numbers.get(i.intValue()));
			}
		}
	}	

	public static void main(String[] args) {
		ArrayList< BigInteger > numbers = new ArrayList< BigInteger >();
		Scanner read = new Scanner(System.in);
		BigInteger invalid = BigInteger.valueOf(104054607);
		while (read.hasNextInt()) {
			BigInteger number = BigInteger.valueOf(read.nextInt());
			if(number.compareTo(invalid) != 0)
				numbers.add(number);
		}
		
		subArray(invalid, numbers);
		read.close();
	}
}