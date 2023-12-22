import java.io.*;
import java.util.*;

public class Day1_part1 {
	public static void pline(String line){
		System.out.println(line);
	}

	public static void pInt(int a){
		System.out.println(a);
	}

	public static void main(String[] args) {
		Scanner read = new Scanner(System.in);

		int floor, i;
		floor = 0;
		String action = read.nextLine();
		for(i = 0; i < action.length(); i++){
			if(action.charAt(i) == '(') floor++;
			else floor--;
		}

		pInt(floor);
		read.close();
	}
}