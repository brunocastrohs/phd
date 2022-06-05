package matheuristica.gls;

import java.util.Random;

import heuristica.HID;
import util.TSPInstanceReader;


public class GLS_L {

	public static int bestCost = 0;

	public static Individual optimize(int W[][], boolean print) {

		long t1 = System.currentTimeMillis();

		int genTotalCount = 1;

		Random roulett = new Random();

		if (print) {
			System.out.println("\n****************** GLS_L - BEGNING **********************\n\n");
			System.out.print("INITIALIZE POPULATION...");
		}

		Population_List descendentPop = initPopulation(W);

		if (print)
			System.out.println("ELITE INDIVIDUAL: " + descendentPop.best().fitness + " | TIME: "
					+ ((System.currentTimeMillis() - t1) / 1000) + "s");

		Population_List ascendentPop = new Population_List(descendentPop.size / 2 + 1);

		Individual eliteIndividual = descendentPop.best();

		do {

			boolean isFirst = true;

			// SELECTION AND CROSSOVER
			do {

				int e = 0;

				Individual p1, p2;

				e = roulett.nextInt(descendentPop.n / 2) + 1;
				p1 = isFirst ? descendentPop.extract(descendentPop.indexOfBest) : descendentPop.extract(e);
				e = roulett.nextInt(descendentPop.n) + 1;
				p2 = descendentPop.extract(e);

				Individual[] offspring = crossover(W, p1, p2, roulett);

				ascendentPop.insert(offspring[0]);
				ascendentPop.insert(offspring[1]);
				isFirst = false;
			} while (!ascendentPop.isFull());

			ascendentPop.segregatePopulation();

			Individual mutatedIndividual;

			// MUTATION
			mutatedIndividual = Mutator.maxMutate(ascendentPop.best(), W);
			ascendentPop.insert(mutatedIndividual, ascendentPop.indexOfBest);

			int i = 1;

			do {

				int op = roulett.nextInt(5) + 1;

				if (op == 1 && i != ascendentPop.indexOfBest) {
					mutatedIndividual = Mutator.medMutate(ascendentPop.get(i), W);
					ascendentPop.insert(mutatedIndividual, i);
				} else if (i != ascendentPop.indexOfBest) {
					Mutator.minMutate(ascendentPop.get(i), W);
				}

				i++;

			} while (i <= ascendentPop.highIndividualsCount);

			Individual eliteCurrent = ascendentPop.best();

			if (eliteIndividual.fitness > eliteCurrent.fitness) {
				if (print)
					System.out.println("\nGENERATION: " + genTotalCount + "| NEW BEST: " + eliteCurrent + " | TIME: "
							+ ((System.currentTimeMillis() - t1) / 1000) + "s");
				eliteIndividual = eliteCurrent;
			} else if (print)
				System.out.println("\nGENERATION: " + genTotalCount + "| NEW SOL.: " + eliteCurrent + " | TIME: "
						+ ((System.currentTimeMillis() - t1) / 1000) + "s");

			descendentPop = ascendentPop;

			ascendentPop = new Population_List(descendentPop.size / 2 + 1);

			genTotalCount++;

		} while (ascendentPop.size > 3);

		bestCost = eliteIndividual.fitness;
		if (print) {
			System.out.println("\nOVERALL BEST: " + eliteIndividual.fitness);

			System.out.println("\n\n****************** ENDING AG **********************\n\n");

			System.out.println("TIME: " + ((System.currentTimeMillis() - t1) / 1000) + "s");
		}
		return eliteIndividual;

	}

	static Population_List initPopulation(int W[][]) {

		int n = W.length;

		int popPotency = 1;

		while ((int) Math.pow(2, popPotency) <= n) {
			popPotency++;
		}

		n = (int) Math.pow(2, popPotency - 1);

		Population_List p = new Population_List(n + 1);

		for (int i = 2; i <= n; i++) {
			int[] t = HID.optimize(W, i);
			p.insert(new Individual(HID.bestCost, t));
		}

		return p;

	}

	static Individual[] crossover(int W[][], Individual parent1, Individual parent2, Random rs) {

		Individual offspring[] = new Individual[2];

		int n = W.length - 1;

		int p1 = rs.nextInt(n / 2) + 1;

		p1 = p1 == 1 ? 2 : p1;

		int p2 = p1 + (int) Math.ceil(n * 0.4);

		int gene1[] = new int[p2 - p1 + 1];

		int gene2[] = new int[p2 - p1 + 1];

		int k = 0;

		for (int i = p1; i <= p2; i++, k++) {
			gene1[k] = parent1.chromossomes[i];
			gene2[k] = parent2.chromossomes[i];
		}

		int chromossomes[] = HID.optimize(W, gene2, p1, p2);
		offspring[0] = new Individual(HID.bestCost, chromossomes);
		chromossomes = HID.optimize(W, gene1, p1, p2);
		offspring[1] = new Individual(HID.bestCost, chromossomes);

		return offspring;

	}

	public static void run(String path) throws Exception {

		int[][] D = TSPInstanceReader.run(path, TSPInstanceReader.MATRIX_CARTESIAN);

		TSPInstanceReader.validateTour(optimize(D, true).chromossomes);

	}
	
	public static void main(String[] args) throws Exception {

		String path = "C:\\Users\\Bruno\\Documents\\data\\tsp\\kroa150.txt";

		run(path);

	}

}
