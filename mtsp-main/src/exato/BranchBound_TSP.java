package exato;


public class BranchBound_TSP {

	int lower_bound = 0;
	int W[][];
	int n; 
	int best_cost = Integer.MAX_VALUE;
	int best_tour[];
	boolean inserted[];
	//VP - visit points
	int remainingVP[];
	int init_level = 0;

	public int[] optimize(int input_W[][], int seed_tour[]){
		W = input_W;
		n = W.length-1;
		inserted = new boolean[n+1];
		int current_cost = 0;
		int current_tour[] = new int[n]; 
		int old_tour[] = seed_tour.clone();
		best_tour = new int[n];
		current_tour[init_level] = seed_tour[0];
		inserted[seed_tour[0]] = true;
		remainingVP = new int[9];
		do{
			init_level++;
			current_cost += W[ seed_tour[init_level-1]][seed_tour[init_level]];
			current_tour[init_level] = seed_tour[init_level];
			inserted[seed_tour[init_level]] = true;
		}while(current_tour.length -  init_level >= remainingVP.length+2);
		
		int k = 0;
		for(int i=1;i<inserted.length;i++){
			if(!inserted[i]){
				remainingVP[k] = i;
				k++;
			}
		}
		
		lower_bound = calculate_bound(W , seed_tour);
		
		branch(init_level,current_tour, current_cost);
		
		if(best_cost == Integer.MAX_VALUE){
			return old_tour;
		}else{
			old_tour = new int[n+1];
			
			for(int i=0;i<best_tour.length;i++ )
				old_tour[i] = best_tour[i];
			old_tour[n] = old_tour[0]; 
			
			return old_tour;
		}
		
	}
	
	void branch(int current_level, int[] current_tour, int current_cost) {
		
		if (bound(current_level,current_tour,current_cost)){
			
			if (current_level == n-1) {
				int current_min_cost = current_cost + W[current_tour[n-1]][current_tour[0]]; 
				if(current_min_cost < best_cost){
					best_cost = current_min_cost;
					//printSolution(current_tour);
					best_tour = current_tour;
				}
			}else
				for (int j : remainingVP) { 
					current_tour[current_level + 1] = j;
					int new_tour[] = current_tour.clone();
					branch(current_level + 1, new_tour, current_cost+W[current_tour[current_level]][j]);
				}
		}
		
	}

	boolean bound(int current_level, int current_tour[],int current_cost) {
		
		int j=init_level;
		
		while(j<current_level){
			if(current_tour[current_level] == current_tour[j]){
				return false;
			}
			j++;
		}

		j = j == 0?j+1:j;
		
		return  current_cost/j <= lower_bound;
		
	}
	
	int calculate_bound(int W[][], int tour[]){
		
		int sum=0;
		int max_avg=0;
		int avg=0;
		int old = 0;
		int next;
		for(next=1;old < tour.length-1;next++,old++){
			sum += W[tour[old]][tour[next]];
			avg = sum/next;
			if(max_avg<avg){
				max_avg = avg;
			}
		}
		
		return max_avg;
		
	}
	
	void printSolution(int [] current_tour){
		System.out.print("Feasible solution : [");
		for (int c = 0; c != current_tour.length; c++)
			System.out.print(current_tour[c] + ",");
		System.out.print(current_tour[0]);
		System.out.print("] | cost:"+best_cost+"\n");
	}
	
}
