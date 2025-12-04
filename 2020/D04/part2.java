import java.io.*; 
import java.util.*;
import java.util.regex.Pattern;

public class Day4_part2 {
	public static void pline(String line){
		System.out.println(line);
	}

	public static void pInt(int a){
		System.out.println(a);
	}

	public static boolean checkYear(String text, int low, int high){
	    String regex = "[1-9][0-9][0-9][0-9]";
	    boolean matches = Pattern.matches(regex, text);
	    if (matches) {
	    	int year = Integer.parseInt(text);
	    	if (low <= year && year <= high) return true;
	    }
	    return false;
	}

	public static boolean checkHeight(String text, int low, int high){
		text = text.split("cm", 3)[0];
		int number = Integer.parseInt(text);

		if (low <= number && number <= high) return true;
		return false;
	}

	public static boolean check(ArrayList< String > lines){
		boolean byr, iyr, eyr, hgt, hcl, ecl, pid;
		int i;
		byr = iyr = eyr = hgt = hcl = ecl = pid = false;

		for(i = 0; i < lines.size(); i++){
			String[] parts = lines.get(i).split(" ", 10);

			for(String part : parts){
				String[] div = part.split(":", 2);
				String text = div[1];
				if (div[0].equals("byr")) {
					byr = checkYear(text, 1920, 2002);
				} else if (div[0].equals("iyr")) {
					iyr = checkYear(text, 2010, 2020);
				} else if (div[0].equals("eyr")) {
					eyr = checkYear(text, 2020, 2030);
				} else if (div[0].equals("hgt")) {
					if (text.contains("cm")) {
						text = text.split("cm", 2)[0];
						hgt = checkHeight(text, 150, 193);
					} else if (text.contains("in")) {
						text = text.split("in", 2)[0];
						hgt = checkHeight(text, 59, 76);
					}
				} else if (div[0].equals("hcl")) {
					if (text.charAt(0) == '#') {
						String regex = "#([0-9]|[a-f])([0-9]|[a-f])([0-9]|[a-f])([0-9]|[a-f])([0-9]|[a-f])([0-9]|[a-f])";
	    				boolean matches = Pattern.matches(regex, text);
						if (matches) hcl = true;
					}
				} else if (div[0].equals("ecl")) {
					if (text.equals("amb") || text.equals("blu") || text.equals("brn") || text.equals("gry") || text.equals("grn") || text.equals("hzl") || text.equals("oth")) {
						ecl = true;
					}
				} else if (div[0].equals("pid")) {
					if(text.length() == 9){
						String regex = "[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]";
	    				boolean matches = Pattern.matches(regex, text);
	    				if (matches) pid = true;
					}
				}
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
				//System.out.println(lines);
				if(check(lines)) valid++;
				lines.clear();
			} else {
				lines.add(line);
			}
		}
		//System.out.println(lines);
		if(check(lines)) valid++;

		pInt(valid);
		read.close();
	}
}