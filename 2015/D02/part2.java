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

		int squares = 0;
		while(read.hasNext()){
			String[] sides = read.nextLine().split("x", 3);

			int l, w, h;
			l = Integer.parseInt(sides[0]);
			w = Integer.parseInt(sides[1]);
			h = Integer.parseInt(sides[2]);

			int min1, min2;
			min1 = 0;
			min2 = 0;

			if(l < w && l < h){
				min1 = l;
				if(w < h) min2 = w;
				else min2 = h;
			} else if(w < h){
				min1 = w;
				if(l < h) min2 = l;
				else min2 = h;
			} else {
				min1 = h;
				if(l < w) min2 = l;
				else min2 = w;
			}

			squares += 2 * min1 + 2 * min2 + l * h * w;
		}
		pInt(squares);
		read.close();
	}
}