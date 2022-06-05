package heuristica;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

import util.Node;
import util.Cluster;

public class Sweep {

	Node nodes[];
	int n;
	int m;
	int maxElementsPerCluster;
	int centroid_id = 0;
	Random rd = new Random();
	
	public Sweep(int points[][],  int mSalesman) {

		this.n = points.length;

		this.m = mSalesman;

		this.nodes = new Node[n];

		this.maxElementsPerCluster = maxElementPerCluster(n);

		centroid(points);
		
	}
	
	int maxElementPerCluster(int n){
		n--;
		if(n == 76)
			return 19;
		else if(n == 152)
			return 39;
		else if(n == 226)
			return 49;
		else if(n == 299)
			return 69;
		else if(n == 439)
			return 99;
		else
			return 219;
			
	}

	void centroid(int [][] points){
		
		int n = points.length-1;
		
		int avgX = 0, avgY = 0;

		for (int i=1; i< points.length;i++) {
			nodes[i] = new Node(i, points[i][0], points[i][1]);
			avgX += points[i][0];
			avgY += points[i][1];
		}
		
		avgX/=n;
		
		avgY/=n;
		
		int minDist = Integer.MAX_VALUE;
		
		 for (int i=1; i< points.length;i++) {
				int dist = (int) Math.sqrt(Math.pow((avgX - points[i][0]),2) + Math.pow((avgY - points[i][1]),2));
				if (dist < minDist) {
					centroid_id = i;
					minDist = dist;
				}
		} 
		
		nodes[0] = new Node(centroid_id, points[centroid_id][0],points[centroid_id][1]); 
		 
	}

	public ArrayList<Cluster> optimize(int W[][]) {

		Node centroid = nodes[0];

		ArrayList<Node> nodeList = new ArrayList<Node>();

		for (int i = 1; i < n; i++) {

			if (i == centroid.id)
				continue;

			Node node = nodes[i];

			if (node.x >= centroid.x) {
				if (node.y >= centroid.y) {
					node.quadrant = 1;
				} else {
					node.quadrant = 4;
				}
			} else {
				if (node.y >= centroid.y) {
					node.quadrant = 2;
				} else {
					node.quadrant = 3;
				}
			}

			for (int j = 1; j < 5; j++) {
				if (node.quadrant == j) {

					double difx = Math.abs(node.x - centroid.x);
					double dify = Math.abs(node.y - centroid.y);

					if (dify != 0) {
						double tangA = (double) dify / difx;

						if (node.quadrant == 2 || node.quadrant == 4) {
							tangA = 1 / tangA;
						}
						node.angle += Math.atan(tangA);
					}

					break;
				} else {
					node.angle += Math.PI / 2;
				}
			}
			nodeList.add(node);
		}

		centroid.quadrant = 4;
		nodeList.add(centroid);
		Collections.sort(nodeList);
		int k = 1;
		
		for(int i=0; i<nodeList.size();i++){
			if(nodeList.get(i).id == 1){
				swap(nodeList, i , 0);
				centroid = nodeList.get(0);
				centroid.quadrant=0;
				centroid.angle=0;
				break;
			}
		}
		
		ArrayList<Cluster> clusters = new ArrayList<Cluster>();

		Cluster actualCluster = new Cluster(centroid);

		do {

			Node node = nodeList.get(k);

			actualCluster.add(node);

			if (actualCluster.amount == maxElementsPerCluster || k == nodeList.size()-1) {
				clusters.add(actualCluster);
				actualCluster = new Cluster(centroid);
			}

			k++;

		} while (k < nodeList.size());

		return clusters;

	}

	public static void swap(ArrayList<Node> nodeList, int x, int y){
		Node aux = nodeList.get(x);
		nodeList.set(x, nodeList.get(y));
		nodeList.set(y, aux);
	}
	
}





