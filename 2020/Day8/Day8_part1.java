import java.io.*; 
import java.util.*;

public class Day8_part1 {

	public static class Tuple< T , T2 >{
		private T first;
		private T2 second;

		Tuple(T first, T2 second){
			this.first = first;
			this.second = second;
		}

		public T getFirst(){
			return this.first;
		}

		public void setFirst(T first){
			this.first = first;
		}

		public T2 getSecond(){
			return this.second;
		}

		public void setSecond(T2 second){
			this.second = second;
		}
	}

	public static void pline(String line){
		System.out.println(line);
	}

	public static void pInt(Integer a){
		System.out.println(a);
	}

	public static Integer runCode(ArrayList< Integer > visited, ArrayList< Tuple< String, Integer > > instructions){
		Integer i = 0;
		Integer acc = 0;
		while(i < instructions.size()){
			if(visited.get(i) == 1) break;

			visited.set(i, 1);
			Tuple< String, Integer > instruction = instructions.get(i);
			String action = instruction.getFirst();
			Integer value = instruction.getSecond();
			if(action.equals("acc")){
				acc += value;
				i++;
			} else if(action.equals("jmp")) {
				i += value;
			} else {
				i++;
			}
		}
		return acc;
	}
	
	public static void main(String[] args) {
		ArrayList< Integer > visited = new ArrayList< Integer >();
		ArrayList< Tuple< String, Integer > > instructions =  new ArrayList< Tuple< String, Integer > >();

		Scanner read = new Scanner(System.in);
		while(read.hasNext()){
			String[] line = read.nextLine().split(" ", 2);
			String instruction = line[0];
			boolean sign = true;
			if(line[1].charAt(0) == '+') sign = false;
			Integer value = (sign ? -1 : 1) * Integer.parseInt(line[1].substring(1));

			instructions.add(new Tuple< String, Integer >(instruction, value));
			visited.add(0);
		}
		read.close();

		pInt(runCode(visited, instructions));
	}
}