import java.io.*; 
import java.util.*;
import java.math.BigInteger; 

public class Day3_part2 {

	public static class Grid {
		public ArrayList< String > grid = new ArrayList< String >();

		public char getCharInGreed(BigInteger x, BigInteger y){
			return this.grid.get(y.intValue()).charAt(x.intValue());
		}

		public void addLine(String line){
			this.grid.add(line);
		}

		public BigInteger getSize(){
			return BigInteger.valueOf(this.grid.size());
		}

		public BigInteger getLengthLine(BigInteger y){
			return BigInteger.valueOf(this.grid.get(y.intValue()).length());
		}
		
		public void buildGrid(){
			Scanner read = new Scanner(System.in);
			while(read.hasNext()){
				String line = read.next();
				addLine(line);
			}
			read.close();
		}
	}

	public static void pline(String line){
		System.out.println(line);
	}

	public static void pInt(BigInteger a){
		System.out.println(a);
	}

	public static BigInteger countTree(BigInteger right, BigInteger down, Grid grid){
		BigInteger x = BigInteger.valueOf(0);
		BigInteger y = BigInteger.valueOf(0);
		BigInteger trees = BigInteger.valueOf(0);

		while(y.compareTo(grid.getSize()) < 0){
			if(grid.getCharInGreed(x, y) == '#')
				trees = trees.add(BigInteger.valueOf(1));
			x = (x.add(right)).mod(grid.getLengthLine(y));
			y = y.add(down);
		}
		return trees;
	}

	public static void main(String[] args) {
		Grid grid = new Grid();
		grid.buildGrid();
		BigInteger total = countTree(BigInteger.valueOf(1), BigInteger.valueOf(1), grid);
		total = total.multiply(countTree(BigInteger.valueOf(3), BigInteger.valueOf(1), grid));
		total = total.multiply(countTree(BigInteger.valueOf(5), BigInteger.valueOf(1), grid));
		total = total.multiply(countTree(BigInteger.valueOf(7), BigInteger.valueOf(1), grid));
		total = total.multiply(countTree(BigInteger.valueOf(1), BigInteger.valueOf(2), grid));
		pInt(total);
		
	}
}