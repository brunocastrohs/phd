package heuristica;

import util.Node;

public class SweepIncomplete {

	int centroid = 0;
	
	public int[][] optimize(int [][] points, int m){
		
		int n = points.length-1;
		
		int maxElementPerCluster = maxElementPerCluster(n);
		
		Point[] list = centroid(points);
		
		return null;
	}
	
	Point[] centroid(int [][] points){
		
		Point[] list = new Point[points.length];
		
		int n = points.length-1;
		
		int avgX = 0, avgY = 0;

		for (int i=1; i< points.length;i++) {
			list[i] = new Point(i, points[i][0], points[i][1]);
			avgX += points[i][0];
			avgY += points[i][1];
		}
		
		avgX/=n;
		
		avgY/=n;
		
		int minDist = Integer.MAX_VALUE, minElement = 0;
		
		 for (int i=1; i< points.length;i++) {
				int dist = (int) Math.sqrt(Math.pow((avgX - points[i][0]),2) + Math.pow((avgY - points[i][1]),2));
				if (dist < minDist) {
					centroid = i;
					minDist = dist;
				}
			
		} 
		
		return list;
	}
	
	int maxElementPerCluster(int n){
		
		if(n == 76)
			return 20;
		else if(n == 152)
			return 40;
		else if(n == 226)
			return 50;
		else if(n == 299)
			return 70;
		else if(n == 439)
			return 100;
		else
			return 220;
			
	}
	
	
}

class Point implements Comparable<Node> {

	public int id;
	public int quadrant;
	public int x;
	public int y;
	public double angle;

	public Point(int i, int x, int y) {
		this.id = i;
		this.x = x;
		this.y = y;
	}

	public String toString() {
		return "[id:" + id + " | quadrant:" + quadrant + " | x: " + x + " | y:" + y + " | ang: " + angle + "]";
	}

	public int compareTo(Node o) {
		if (this.angle < o.angle) {
			return -1;
		} else if (o.angle == this.angle) {
			return 0;
		} else {
			return 1;
		}
	}
}