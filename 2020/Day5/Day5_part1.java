import java.io.*; 
import java.util.*;

public class Day5_part1 {
	public static void pline(String line){
		System.out.println(line);
	}

	public static void pInt(int a){
		System.out.println(a);
	}

	public static int binarySearch(String seats, char cond, int init, int end, int high){
		int i, mid, low;
		mid = low = 0;
		for(i = init; i < end; i++){
			char code = seats.charAt(i);
			mid = (high + low) / 2;

			if(code == cond){
				high = mid;
			} else {
				low = mid + 1;
			}
		}
		return low;
	}

	public static void main(String[] args) {
		Scanner read = new Scanner(System.in);
		int max = 0;
		while(read.hasNext()){
			String seats = read.next();
			int row, col;
			row = binarySearch(seats, 'F', 0, 7, 127);
			col = binarySearch(seats, 'L', 7, 10, 7);
			if(max < col + row * 8)
				max = col + row * 8;
		}
		pInt(max);
		read.close();
	}
}