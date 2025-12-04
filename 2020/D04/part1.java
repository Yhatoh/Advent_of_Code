import java.io.*; 
import java.util.*;

public class Day4_part1 {
	public static void pline(String line){
		System.out.println(line);
	}

	public static void pInt(int a){
		System.out.println(a);
	}

	public static boolean check(ArrayList< String > lines){
		boolean byr, iyr, eyr, hgt, hcl, ecl, pid;
		int i;
		byr = iyr = eyr = hgt = hcl = ecl = pid = false;

		for(i = 0; i < lines.size(); i++){
			String[] parts = lines.get(i).split(" ", 10);

			for(String part : parts){
				String[] div = part.split(":", 2);
				if(div[0].equals("byr")) byr = true;
				else if(div[0].equals("iyr")) iyr = true;
				else if(div[0].equals("eyr")) eyr = true;
				else if(div[0].equals("hgt")) hgt = true;
				else if(div[0].equals("hcl")) hcl = true;
				else if(div[0].equals("ecl")) ecl = true;
				else if(div[0].equals("pid")) pid = true;
			}
		}
		if(byr && iyr && eyr && hgt && hcl && ecl && pid)
				return true;
		return false;
	}
	public static void main(String[] args) {
		Scanner read = new Scanner(System.in);

		int valid = 0;

		ArrayList< String > lines = new ArrayList< String >();
		while(read.hasNext()){
			String line = read.nextLine();
			if(line.equals("")){
				if(check(lines)) valid++;
				lines.clear();
			} else {
				lines.add(line);
			}
		}

		if(check(lines)) valid++;

		pInt(valid);
		read.close();
	}
}