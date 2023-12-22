import java.io.*;
import java.util.*;
import javafx.util.Pair; 

public class Day3_part1 {

	public static void pline(String line){
		System.out.println(line);
	}

	public static void pInt(int a){
		System.out.println(a);
	}

	public static void main(String[] args) {
		Scanner read = new Scanner(System.in);
		String moves = read.nextLine();
		read.close();

		Set< String > houses = new HashSet< String >();
		Pair< Integer, Integer > house = new Pair< Integer, Integer >(0, 0);
		houses.add(house);
		for(int i = 0; i < moves.length(); i++){
			int x = house.getKey();
			int y = house.getValue();
			if(moves.charAt(i) == '>') x++;
			else if(moves.charAt(i) == '^') y++;
			else if(moves.charAt(i) == '<') x--;
			else y--;
			Pair< Integer, Integer > temp = new Pair< Integer, Integer >(x, y);
			houses.add(temp);
			house = temp;
		}
		pInt(houses.size());
	}
}