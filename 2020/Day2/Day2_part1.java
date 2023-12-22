import java.io.*; 
import java.util.*;

public class Day2_part1 {
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
			String borders = read.next();
			String charact = read.next();
			String password = read.next();

			//pline(borders + " " + charact + " " + password);

			String[] bordersObtained = borders.split("-", 2);

			int atLeast = Integer.parseInt(bordersObtained[0]);
			int atMost = Integer.parseInt(bordersObtained[1]);

			char letter = charact.charAt(0);
			int i, count;
			count = 0;
			for(i = 0; i < password.length(); i++){
				if(letter == password.charAt(i))
					count++;
			}

			if(atLeast <= count && count <= atMost){
				valid++;
			}
		}

		pInt(valid);

		read.close();
	}
}