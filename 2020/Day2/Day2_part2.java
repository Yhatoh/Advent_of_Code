import java.io.*; 
import java.util.*;

public class Day2_part2 {
	public static void pline(String line){
		System.out.println(line);
	}

	public static void pInt(int a){
		System.out.println(a);
	}

	public static void main(String[] args) {
		Scanner read = new Scanner(System.in);

		int valid = 0;
		while(read.hasNext()){
			String positions = read.next();
			String charact = read.next();
			String password = read.next();

			//pline(positions + " " + charact + " " + password);

			String[] bordersObtained = positions.split("-", 2);

			int pos1 = Integer.parseInt(bordersObtained[0]) - 1;
			int pos2 = Integer.parseInt(bordersObtained[1]) - 1;

			char letter = charact.charAt(0);
			

			if(password.charAt(pos1) != letter && password.charAt(pos2) == letter){
				valid++;
			} else if(password.charAt(pos2) != letter && password.charAt(pos1) == letter){
				valid++;
			}
		}

		pInt(valid);

		read.close();
	}
}


