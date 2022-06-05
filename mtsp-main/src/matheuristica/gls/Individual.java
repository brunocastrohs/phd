package matheuristica.gls;

public class Individual {
	public int fitness;
	public int chromossomes[];
	public int avgDetour = Integer.MAX_VALUE;

	public Individual(int c) {
		fitness = c;
	}

	public Individual(int c, int s) {
		fitness = c;
		chromossomes = new int[s];
	}
	
	public Individual(int c, int[] p) {
		fitness = c;
		chromossomes = p;
	}

	public String toString() {
		return "[SP: "+chromossomes[0]+" | FIT: " + fitness+"]";
	}

}
