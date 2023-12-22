import java.io.*; 
import java.util.*;

public class Day3_part1 {
	public static void pline(String line){
		System.out.println(line);
	}

	public static void pInt(int a){
		System.out.println(a);
	}

	public static void main(String[] args) {
		Scanner read = new Scanner(System.in);

		int pos, trees;
		pos = 0;
		trees = 0;
		while(read.hasNext()){
			String line = read.next();
			if(line.charAt(pos) == '#')
				trees++;
			pos = (pos + 3) % line.length();
		}

		pInt(trees);

		read.close();
	}
}