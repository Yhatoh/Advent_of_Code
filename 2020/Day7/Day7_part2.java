import java.io.*; 
import java.util.*;

public class Day7_part2 {

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

	public static class GraphWeighted< T > { 
	    private Map< T, List< Tuple< T, Integer > > > map = new HashMap< >(); 
	  
	    public void addVertex(T s){ 
	        this.map.put(s, new LinkedList< Tuple< T, Integer > >()); 
	    } 

	    public void addEdge(T s, T d, Integer w, boolean bidir){
	        if (!this.map.containsKey(s)) this.addVertex(s);
	        if (!this.map.containsKey(d)) this.addVertex(d); 
	  
	        this.map.get(s).add(new Tuple< T, Integer >(d, w)); 
	        if (bidir == true) this.map.get(d).add(new Tuple< T, Integer >(s, w)); 
	    } 
	  
	    public List< Tuple< T, Integer > > getNeighbours(T v){ 
	        return this.map.get(v);
	    } 
	  
	    public Integer getNeighboursCount(List< Tuple< T, Integer > > neighbours){
	    	return neighbours.size();
	    }

	    public Tuple< T, Integer > getNeighbour(List< Tuple< T, Integer > > neighbours, Integer index){
	    	return neighbours.get(index);
	    }

	    public Integer DFS(Tuple< T, Integer >  v, Set< T > visited){
	    	visited.add(v.getFirst());
	    	Integer colors = 0;

	    	List< Tuple< T, Integer > > neighbours = this.getNeighbours(v.getFirst());
	    	for(Integer i = 0; i < this.getNeighboursCount(neighbours); i++){
	    		Tuple< T, Integer > tuple = this.getNeighbour(neighbours, i);
	    		T u = tuple.getFirst();
	    		Integer w = tuple.getSecond();
		    	if(!u.equals("shiny gold")){
		    		colors += w;
		    		colors += w * this.DFS(tuple, visited);
	    		}
	    	}
	    	return colors;
	    }

	    public Integer DFS(Tuple< T, Integer >  v){
	    	Set< T > visited = new HashSet< T >();
	    	return this.DFS(v, visited);
	    }
	} 

	public static void pline(String line){
		System.out.println(line);
	}

	public static void pInt(Integer a){
		System.out.println(a);
	}

	public static void main(String[] args) {
		Scanner read = new Scanner(System.in);
		GraphWeighted< String > g = new GraphWeighted< String >();

		while(read.hasNext()){
			String[] bags = read.nextLine().split(" contain ");

			String[] origin = bags[0].split(" ");
			String[] destination = bags[1].split(", ");

			String bigBag = origin[0] + " " + origin[1];
			
			for(Integer i = 0; i < destination.length; i++){
				String[] inside = destination[i].split(" ");
				if(inside[0].equals("no")){
					break;
				}
				String bag = inside[1] + " " + inside[2];
				g.addEdge(bigBag, bag, Integer.parseInt(inside[0]), false);
			}
		}

		pInt(g.DFS(new Tuple< String, Integer >("shiny gold", 0)));
		read.close();
	}
}