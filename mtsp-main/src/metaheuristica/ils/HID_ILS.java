package metaheuristica.ils;

import java.util.ArrayList;

import util.Cluster;
import util.InstanceMTSP;
import heuristica.HID;
import util.TSPInstanceReader;

public class HID_ILS {

	static int t = 0;
	
	static int bestCost = 0;
	
	public static int run(String path) throws Exception {
		
		long t1 = System.currentTimeMillis();
		
		int m = 4;
		
		System.out.println("\t\t\tFIRST STEP: CLUSTERS \n");

		int[][] W = TSPInstanceReader.run(path, TSPInstanceReader.MATRIX_CARTESIAN);
		
		int tours[][] = new int[m][];
		int cost = 0; 
		tours[0] = HID.m_optimize(W, 19, true);
		cost += HID.bestCost;
		System.out.println("COST: "+ HID.bestCost);
		tours[1] = HID.m_optimize(W, 19, false);
		cost += HID.bestCost;
		System.out.println("COST: "+ HID.bestCost);
		tours[2] = HID.m_optimize(W, 19, false);
		cost += HID.bestCost;
		System.out.println("COST: "+ HID.bestCost);
		tours[3] = HID.m_optimize(W, 18, false);
		cost += HID.bestCost;
		System.out.println("COST: "+ HID.bestCost);
		
		System.out.println("TOTAL COST: "+ cost);
		System.out.println("AVG: "+ cost/4);
				
		System.out.println("**********************************************************************\n");
		
		System.out.println("\t\t\t SECOND STEP: ROUTE \n\n");

		int sum = 0;
		
		int salesman = 1;
		
		ILS ils = new ILS();
		
		
		for (int tour[] : tours) {
			
			tour = ils.optimize(tour, W);
			
			tours[salesman-1] = new int[tour.length];
			
			System.out.print("SALESMAN: " + salesman + "| POINTS: "+(tour.length-1)+" | TOUR: ");
			
			for (int e : tour){
				System.out.print(e + " ");
			}
			
			System.out.print("| TOUR COST: " + ils.bestCost + " \n\n");
			sum += ils.bestCost;
			tours[salesman-1] = tour;
			salesman++;
		}

		System.out.println("**********************************************************************\n");
		System.out.println("\t\t\t THIRD STEP: GLOBAL SWAP \n\n");

		
		ils.m_optimize(tours, W);
		
		if(ils.bestCost < sum){
			sum = ils.bestCost;
			for(int [] tour:tours){
				for (int e : tour){
					System.out.print(e + " ");
				}
				System.out.println("\n");
			}
		}
		
		System.out.println("**********************************************************************\n");
		System.out.println("\t\t\t ENDING STEP: REPORT \n\n");

		
		System.out.println("SUM SOLUTION: " + (sum));
		System.out.println("TIME: " + ((System.currentTimeMillis() - t1) / 1000) + "s");
		t += (System.currentTimeMillis() - t1) / 1000;
		TSPInstanceReader.m_validateTour(tours, W);
		return sum;
	}

	public static void main(String args[]) throws Exception {
		String path = "C:\\Users\\Bruno\\Documents\\data\\mtsp\\pr76.txt";
		run(path);
	}
	
}
