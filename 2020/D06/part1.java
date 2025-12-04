import java.io.*; 
import java.util.*;

public class Day6_part1 {
	public static void pline(String line){
		System.out.println(line);
	}

	public static void pInt(int a){
		System.out.println(a);
	}

	public static void main(String[] args) {
		Scanner read = new Scanner(System.in);

		Set< String > answers = new HashSet< String >(); 
		int sum = 0;
		while(read.hasNext()){
			String person = read.nextLine();
			if(person.equals("")){
				sum += answers.size();
				answers.clear();
			} else {
				for(int i = 0; i < person.length(); i++){
					answers.add(String.valueOf(person.charAt(i)));
				}
			}
		}
		pInt(sum + answers.size());
		read.close();
	}
}