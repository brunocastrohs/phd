package util;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.StringTokenizer;


public class TSPInstanceReader {

	public static int n = 0;
	public static int[][] D;
	public static int[][] points;
	public static final int MATRIX_INF_TRI_FILE = 0;
	public static final int MATRIX_SUP_TRI_FILE = 1;
	public static final int MATRIX_FILE = 2;
	public static final int MATRIX_ASYMMETRIC_FILE = 3;
	public static final int MATRIX_CARTESIAN = 4;
	public static int DIST_TYPE = 3;
	public static Instance inst;	
	
	public static int[][] run(String path2file, int m) throws Exception {

		BufferedReader reader;

		if (m == 0) {
			reader = new BufferedReader(new FileReader(path2file));
			n = Integer.parseInt(reader.readLine().trim());
			D = new int[n + 1][n + 1];
			readFromInferiorTriangleMatrix(reader);
		} else if (m == 1) {
			reader = new BufferedReader(new FileReader(path2file));
			n = Integer.parseInt(reader.readLine().trim());
			D = new int[n + 1][n + 1];
			readFromSuperiorTriangleMatrix(reader);
		} else if (m == 2) {
			reader = new BufferedReader(new FileReader(path2file));
			n = Integer.parseInt(reader.readLine().trim());
			D = new int[n + 1][n + 1];
			readMatrixFile(reader);
		} else if (m == 3) {
			reader = new BufferedReader(new FileReader(path2file));
			n = Integer.parseInt(reader.readLine().trim());
			D = new int[n + 1][n + 1];
			// must be adapted
			readFromIrregularMatrix(reader);
		} else if (m == 4) {
			reader = new BufferedReader(new FileReader(path2file));
			n = Integer.parseInt(reader.readLine().trim());
			D = new int[n + 1][n + 1];
			int[][] da = D;
			readFromPositions(path2file);
			da = D.clone();
			da = null;
		}

		return D;

	}

	static void readFromPositions(String path2file) throws Exception {
		inst = new Instance(path2file, true);
		D = inst.getWays();
		n = inst.getInstSize();
		
		/*BufferedReader reader = new BufferedReader(new FileReader(path2file));

		int size = Integer.parseInt(reader.readLine().trim());

		n = size;
		places = new Place[n + 1];
		// cities[](new City(0, 0, 0));
		for (int i = 1; i <= size; i++) {

			String r = reader.readLine();
			StringTokenizer token = new StringTokenizer(r, " \t");

			token.nextToken().trim();

			Double x = Double.parseDouble(token.nextToken().trim());
			Double y = Double.parseDouble(token.nextToken().trim());

			Place place = new Place(i, x, y);
			places[i] = place;
		}*/

	}

	static void readFromInferiorTriangleMatrix(BufferedReader reader) throws Exception {

		// int size = n = Integer.parseInt(reader.readLine().trim());
		int i = 0, j = 0;

		for (i = 2; i <= n; i++) {
			StringTokenizer token = new StringTokenizer(reader.readLine(), " \t");
			for (j = 1; j < i; j++) {
				D[j][i] = D[i][j] = Integer.parseInt(token.nextToken().trim());
			}
		}

	}

	static void readFromSuperiorTriangleMatrix(BufferedReader reader) throws Exception {

		// int size = n = Integer.parseInt(reader.readLine().trim());
		int i = 0, j = 0;

		for (i = 1; i < n; i++) {
			StringTokenizer token = new StringTokenizer(reader.readLine(), " \t");
			for (j = i + 1; j <= n; j++) {
				D[j][i] = D[i][j] = Integer.parseInt(token.nextToken().trim());
			}
		}

	}

	static void readMatrixFile(BufferedReader reader) throws Exception {

		int i = 0, j = 0;

		for (i = 1; i <= n; i++) {
			String line = reader.readLine();
			StringTokenizer token = new StringTokenizer(line, "  ");
			for (j = 1; j <= n; j++) {
				String t = token.nextToken().trim();
				D[j][i] = D[i][j] = Integer.parseInt(t);
			}
		}

	}

	static void readFromIrregularMatrix(BufferedReader reader) throws Exception {

		// int size = n = Integer.parseInt(reader.readLine().trim());
		int i = 0, j = 0;
		int count = 1;
		int[][] Dd = D;

		String line = reader.readLine();
		StringTokenizer token = new StringTokenizer(line, "         ");
		int nPerLine = line.split("         ").length;

		try {
			// token = new StringTokenizer(line, " \t");

			for (i = 1; i <= n; i++) {
				for (j = 1; j <= n; j++, count++) {
					String value = token.nextToken().trim();

					Dd[i][j] = Integer.parseInt(value);
					if (count == nPerLine) {
						line = reader.readLine();
						token = new StringTokenizer(line, "         ");
						count = 0;
					}
				}

				// line = reader.readLine();

				count = 1;

			}
		} catch (Exception e) {
			System.out.println("Got fried");
		}

		D = Dd;

	}

	public static void validateTour(int tour[]){
		System.out.print("Validating tour...");
		boolean validator[] = new boolean[tour.length];
		int c = 0;
		int n = tour.length-1;
		for(int e:tour){
			if(validator[e]==false){
				validator[e]=true;
				c++;
			}
			else if(validator[e]==true && e!=tour[0])
				System.out.print(" [P:"+e+"]");
		}
		System.out.println("\nN: "+n+" | TOUR ELEMENTS: "+c);
	}
	
	public static void m_validateTour(int tours[][], int [][] W){
		System.out.print("Validating tour...");
		boolean validator[] = new boolean[W.length];
		int c = 1;
		validator[1]=true;
		int n = W.length-1;
		for(int tour[]:tours){
			if(tour!=null)
			for(int e:tour){
				if( e!=1 && validator[e]==false){
					validator[e]=true;
					c++;
				}
				else if(validator[e]==true && e!=tour[0])
					System.out.print(" [P:"+e+"]");
			}
		}
		System.out.println("\nN: "+n+" | TOURS TOTAL ELEMENTS: "+c);
	}

	public static void main(String args[]) throws Exception {
		/*
		 * String path = "C:\\Users\\Bruno\\Documents\\data\\tsp\\brazil58.txt";
		 * int[][] D = run(path, MATRIX_SUP_TRI_FILE);
		 * 
		 * double [][] S = new double[D.length][D.length];
		 * 
		 * for(int i=0;i<D.length;i++) for(int j=0;j<D.length;j++) S[i][j] =
		 * D[i][j]; // matrixToLinearModel(S);
		 */
		String path = "C:\\Users\\Bruno\\Documents\\data\\tsp\\ftv35.txt";
		int[][] D = TSPInstanceReader.run(path, TSPInstanceReader.MATRIX_ASYMMETRIC_FILE);

		// printD();

	}

	
}

class Instance {

	public Place[] places;
	private int n;
	private int D[][];
	// teaser
	public int nodes[];

	public Instance(String path2file, boolean hasIndex) throws IOException {
		readPoints(path2file, hasIndex);
		setDistanceWays();
	}

	private Place[] readPoints(String path2file, boolean hasIndex) throws IOException {

		BufferedReader reader = new BufferedReader(new FileReader(path2file));

		int size = Integer.parseInt(reader.readLine().trim());

		n = size;
		places = new Place[n + 1];
		TSPInstanceReader.points = new int[n + 1][2];
		// cities[](new City(0, 0, 0));
		for (int i = 1; i <= size; i++) {

			String r = reader.readLine();
			StringTokenizer token = new StringTokenizer(r, " \t");

			if (hasIndex)
				token.nextToken().trim();

			Double x = Double.parseDouble(token.nextToken().trim());
			Double y = Double.parseDouble(token.nextToken().trim());

			TSPInstanceReader.points[i][0] = x.intValue();
			TSPInstanceReader.points[i][1] = y.intValue();
			
			Place place = new Place(i, x, y);
			places[i] = place;
		}

		return places;
	}

	private void setDistanceWays() {

		D = new int[n + 1][n + 1];
		for (int i = 1; i < places.length; i++) {
			for (int j = i + 1; j < places.length; j++) {
				D[i][j] = Place.distance(places[i], places[j], TSPInstanceReader.DIST_TYPE);
				D[j][i] = D[i][j];
			}
		}
	}

	public int[][] getWays() {
		return D;
	}

	public int getInstSize() {
		return n;
	}

}

class Place {
	public final int gid;
	public final Double x;
	public final Double y;
	public boolean isVisited;
	public static int ATT = 1;
	public static int CEIL_2D = 2;
	public static int EUC_2D = 3;

	public Place(final int gid, final Double x, final Double y) {
		this.gid = gid;
		this.x = x;
		this.y = y;
	}

	static double dtrunc(double x) {
		int k;

		k = (int) x;
		x = (double) k;
		
		return x;
	}
	
	static public int distance(final Place city1, final Place city2, int type) {

		if(type==ATT)
			return att_distance(city1, city2);
		else if(type==CEIL_2D)
			return ceil_distance(city1, city2);
		else
			return euc_distance(city1, city2);
		
	}

	static int euc_distance(final Place city1, final Place city2)
	/*
	 * EUC_2D
	 */
	{
		double xd = city2.x - city1.x;
		double yd = city2.y - city1.y;
		double r = Math.sqrt(xd * xd + yd * yd) + 0.5;

		return (int) r;
	}

	static int ceil_distance(final Place city1, final Place city2)
	/*
	 CEIL_2D
	 */
	{
		double xd = city2.x - city1.x;
		double yd = city2.y - city1.y;
		double r = Math.sqrt(xd * xd + yd * yd);

		return (int) Math.ceil(r);
	}

	static int att_distance(final Place city1, final Place city2)
	/*
	ATT
	 */
	{
		double xd = city2.x - city1.x;
		double yd = city2.y - city1.y;
		double rij = Math.sqrt((xd * xd + yd * yd) / 10.0);
		double tij = dtrunc(rij);
		int dij;

		if (tij < rij)
			dij = (int) tij + 1;
		else
			dij = (int) tij;
		return dij;
	}

	public Place(final Place city) {
		this.gid = city.gid;
		this.x = city.x;
		this.y = city.y;
	}

	@Override
	public boolean equals(final Object o) {
		if (o instanceof Place) {
			final Place other = (Place) o;
			return gid == other.gid && x == other.x && y == other.y;
		}
		return false;
	}

	@Override
	public String toString() {
		return gid + ";  [x=" + x + "; y=" + y + "]";
	}

}