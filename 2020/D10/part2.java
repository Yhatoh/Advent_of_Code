import java.io.*; 
import java.util.*;
import java.math.BigInteger; 

public class Day10_part2 {
	public static void pBigInt(BigInteger a){
		System.out.println(a);
	}

	public static void pInt(Integer a){
		System.out.println(a);
	}

	public static void pline(String a){
		System.out.println(a);
	}

	public static void printMatrix(BigInteger[][] matrix, int n){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				System.out.print(matrix[i][j]);
			}
			System.out.print("\n");
		}
		System.out.print("\n");
	}

	public static void printArray(BigInteger[] array, int n){
		for(int i = 0; i < n; i++){
			System.out.print(array[i] + " ");
		}
		System.out.print("\n");
	}
	public static void main(String[] args) {
		ArrayList< Integer > jolts = new ArrayList< Integer >();
		Scanner read = new Scanner(System.in);
		
		while(read.hasNextInt()){
			Integer jolt = read.nextInt();
			jolts.add(jolt); 
		}
		read.close();

		Collections.sort(jolts);
		BigInteger[] arr = new BigInteger[jolts.size() + 1];
		int i;
		BigInteger ans, one;
		for(i = 0; i < jolts.size() + 1; i++){
			arr[i] = BigInteger.valueOf(0);
		}

		for(i = 0; i < 3; i++){
			if(0 == jolts.get(i) - 1)
				arr[i + 1] = BigInteger.valueOf(1);
			else if(0 == jolts.get(i) - 2)
				arr[i + 1] = BigInteger.valueOf(1);
			else if(0 == jolts.get(i) - 3)
				arr[i + 1] = BigInteger.valueOf(1);
		}
		for(i = 0; i < jolts.size() - 1; i++){
			if(jolts.get(i) == jolts.get(i + 1) - 1 || jolts.get(i) == jolts.get(i + 1) - 2 || jolts.get(i) == jolts.get(i + 1) - 3){
				arr[i + 1 + 1] = arr[i + 1 + 1].add(arr[i + 1]);
			}
			if(i + 2 < jolts.size() && (jolts.get(i) == jolts.get(i + 2) - 2 || jolts.get(i) == jolts.get(i + 2) - 3)){
				arr[i + 1 + 2] = arr[i + 1 + 2].add(arr[i + 1]);
			}
			if(i + 3 < jolts.size() && (jolts.get(i) == jolts.get(i + 3) - 3)){
				arr[i + 1 + 3] = arr[i + 1 + 3].add(arr[i + 1]);
			}
		}

		pBigInt(arr[jolts.size()]);
	}
}