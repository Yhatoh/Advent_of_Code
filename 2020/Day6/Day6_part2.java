import java.io.*; 
import java.util.*;

public class Day6_part2 {
	public static void pline(String line){
		System.out.println(line);
	}

	public static void pInt(int a){
		System.out.println(a);
	}

	public static void main(String[] args) {
		Scanner read = new Scanner(System.in);

		int[] answers = new int[28];
		for(int i = 0; i < 28; i++){
			answers[i] = 0;
		}
		int sum, cant;
		sum = cant = 0;
		while(read.hasNext()){
			String person = read.nextLine();
			if(person.equals("")){
				for(int i = 0; i < 28; i++){
					if(answers[i] == cant) sum++;
					answers[i] = 0;
				}
				cant = 0;
			} else {
				cant++;
				for(int i = 0; i < person.length(); i++){
					answers[person.charAt(i) - 'a']++;
				}
			}
		}

		for(int i = 0; i < 28; i++){
			if(answers[i] == cant) sum++;
			answers[i] = 0;
		}

		pInt(sum);
		read.close();
	}
}