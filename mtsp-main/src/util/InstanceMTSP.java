package util;

public class InstanceMTSP {
	public int W[][];
	public int id[];
	public int n;
	
	public InstanceMTSP(int[][] INST, int[] id) {
		this.W = INST;
		this.id = id;
		this.n = id.length-1;
	}
	
	static public InstanceMTSP createInstance(int[][] W, Cluster clr) {

		int n = clr.nodes.size() + 1;

		int INST[][] = new int[n][n];

		int id[] = new int[n];

		for (int i = 1; i < n; i++) {
			for (int j = 1; j < n; j++) {
				INST[i][j] = W[clr.nodes.get(i - 1).id][clr.nodes.get(j - 1).id];
			}
			id[i] = clr.nodes.get(i - 1).id;
		}

		InstanceMTSP ist = new InstanceMTSP(INST, id);

		return ist;
	}
	
}