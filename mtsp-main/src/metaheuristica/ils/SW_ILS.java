package metaheuristica.ils;

import java.util.ArrayList;

import util.Cluster;
import util.InstanceMTSP;
import heuristica.Sweep;
import util.TSPInstanceReader;

public class SW_ILS {

	static int t = 0;
	static int bestSolution;

	public static int run(String path) throws Exception {
		//System.out.println("\t\t\tFIRST STEP: CLUSTERS \n");

		int[][] W = TSPInstanceReader.run(path, TSPInstanceReader.MATRIX_CARTESIAN);
		
		int points[][] = TSPInstanceReader.points;
		
		int m = 5;
		
		long t1 = System.currentTimeMillis();
		
		Sweep swp = new Sweep(points, m);

		ArrayList<Cluster> clrs = swp.optimize(W);

		InstanceMTSP instancias[] = new InstanceMTSP[clrs.size()];

		int k = 0;

		for (Cluster clr : clrs) {
			//System.out.println(clr);
			instancias[k] = InstanceMTSP.createInstance(W, clr);
			k++;
		}

		ILS ils = new ILS();
		int tours[][] = new int[k][];
		//System.out.println("**********************************************************************\n");
		//System.out.println("\t\t\t SECOND STEP: ROUTE \n\n");

		int sum = 0;
		int salesman = 1;
		for (InstanceMTSP inst : instancias) {
			
			int tour[] = ils.optimize(inst.W);
			tours[salesman-1] = new int[inst.W.length];
			//System.out.print("SALESMAN: " + salesman + "| POINTS: "+inst.n+" | TOUR: ");
			int i = 0;
			for (int e : tour){
			//	System.out.print(inst.id[e] + " ");
				tours[salesman-1][i] = inst.id[e];
				i++;
			}
			
			//System.out.print("| TOUR COST: " + ils.bestCost + " \n\n");
			sum += ils.bestCost;
			salesman++;
		}

		//System.out.println("SUM SOLUTION: " + (sum));
		
		//System.out.println("**********************************************************************\n");
		//System.out.println("\t\t\t THIRD STEP: GLOBAL SWAP \n\n");

		
		ils.m_optimize(tours, W);
		
		if(ils.bestCost < sum){
			sum = ils.bestCost;
			/*for(int [] tour:tours){
				for (int e : tour){
					System.out.print(e + " ");
				}
				System.out.println("\n");
			}*/
		}
		
		//System.out.println("**********************************************************************\n");
		//System.out.println("\t\t\t ENDING STEP: REPORT \n\n");

		//System.out.println("TIME: " + ((System.currentTimeMillis() - t1) / 1000) + "s");
		//System.out.println("SUM SOLUTION: " + (sum));
		t += (System.currentTimeMillis() - t1) / 1000;
		//TSPInstanceReader.m_validateTour(tours, W);
		return sum;
	}

	public static void main(String args[]) throws Exception {
		String path = "C:\\Users\\Bruno\\Documents\\data\\mtsp\\pr76.txt";
		//int ts = 10;
		int sum = 0;
		//do{
			sum = run(path);
			//ts--;
		//}while(ts > 0);
		System.out.println("TIME: " + t + "s");
		System.out.println("SUM SOLUTION: " + sum);
	}
	
}
