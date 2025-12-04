import java.io.*; 
import java.util.*;

public class Day7_part1 {

	public static class Graph<T> { 
	    private Map< T, List< T > > map = new HashMap< >(); 
	  
	    public void addVertex(T s){ 
	        this.map.put(s, new LinkedList< T >()); 
	    } 

	    public void addEdge(T s, T d, boolean bidir){
	        if (!this.map.containsKey(s)) this.addVertex(s);
	        if (!this.map.containsKey(d)) this.addVertex(d); 
	  
	        this.map.get(s).add(d); 
	        if (bidir == true) this.map.get(d).add(s); 
	    } 
	  
	    public List< T > getNeighbours(T v){ 
	        return this.map.get(v);
	    } 
	  
	    public int getNeighboursCount(List< T > neighbours){
	    	return neighbours.size();
	    }

	    public T getNeighbour(List< T > neighbours, int index){
	    	return neighbours.get(index);
	    }

	    public int DFS(T v, Set< T > visited){
	    	visited.add(v);
	    	int colors = 0;

	    	List< T > neighbours = this.getNeighbours(v);
	    	for(int i = 0; i < this.getNeighboursCount(neighbours); i++){
	    		T u = this.getNeighbour(neighbours, i);
	    		if(!visited.contains(u)){
	    			colors++;
	    			colors += this.DFS(u, visited);
	    		}
	    	}
	    	return colors;
	    }

	    public int DFS(T v){
	    	Set< T > visited = new HashSet< T >();
	    	return this.DFS(v, visited);
	    }
	} 

	public static void pline(String line){
		System.out.println(line);
	}

	public static void pInt(int a){
		System.out.println(a);
	}

	public static void main(String[] args) {
		Scanner read = new Scanner(System.in);
		Graph< String > g = new Graph< String >();

		while(read.hasNext()){
			String[] bags = read.nextLine().split(" contain ");

			String[] origin = bags[0].split(" ");
			String[] destination = bags[1].split(", ");

			String bigBag = origin[0] + " " + origin[1];
			
			for(int i = 0; i < destination.length; i++){
				String[] inside = destination[i].split(" ");
				if(inside[0].equals("no")){
					break;
				}
				String bag = inside[1] + " " + inside[2];
				g.addEdge(bag, bigBag, false);
			}
		}

		pInt(g.DFS("shiny gold"));
		read.close();
	}
}