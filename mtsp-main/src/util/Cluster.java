package util;

import java.util.ArrayList;

public class Cluster {

	public int amount;
	public ArrayList<Node> nodes;

	public Cluster() {
		nodes = new ArrayList<Node>();
	}

	public Cluster(Node n) {
		nodes = new ArrayList<Node>();
		nodes.add(n);
	}

	public void add(Node n) {
		nodes.add(n);
		amount++;
	}

	public String toString() {
		String str = "**********************************************************************\n";

		for (Node n : nodes) {
			str += n.toString() + "\n";
		}

		return str;
	}

}