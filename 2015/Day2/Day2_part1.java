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

		int squares = 0;
		while(read.hasNext()){
			String[] sides = read.nextLine().split("x", 3);

			int l, w, h;
			l = Integer.parseInt(sides[0]);
			w = Integer.parseInt(sides[1]);
			h = Integer.parseInt(sides[2]);

			squares += 2 * l * w + 2 * w * h + 2 * h * l + Math.min(l * h, Math.min(w * h, l * w));
		}
		pInt(squares);
		read.close();
	}
}