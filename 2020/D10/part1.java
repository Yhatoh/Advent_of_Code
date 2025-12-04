import java.io.*; 
import java.util.*;

public class Day10_part1 {
	public static void pInt(Integer a){
		System.out.println(a);
	}

	public static void pline(String a){
		System.out.println(a);
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
		Integer i, one, three;
		three = 1;
		one = 0;

		if(jolts.get(0) == 0 + 1) one++;
		else three++;

		for(i = 0; i < jolts.size() - 1; i++){
			if(jolts.get(i) == jolts.get(i + 1) - 1) one++;
			else three++;
		}
		pInt(one * three);
	}
}