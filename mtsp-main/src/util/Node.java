package util;

public class Node implements Comparable<Node> {

	public int id;
	public int quadrant;
	public int x;
	public int y;
	public double angle;

	public Node(int i, int x, int y) {
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