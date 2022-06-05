package solver;

import dnl.utils.text.table.TextTable;
/** DUAS FASES EM QUE W É SEMPRE UMA FUNÇÃO DE MIN*/
public class SolverW {
	
	boolean max;
	
	double tableaux[][];
	
	int I[];
	
	int J[];
	
	int A[];
	
	int linhasVarArtificial[];
	
	int colunasArtificiaisInicio[];

	double cI[];
	
	double cJ[];

	int k = 0;
	
	int s = 0;
	
	int r = 0;
	
	double linha_r[];
	
	double Yrk = 0;
	
	double z0 = 0;
	
	boolean debugger = false;
	
	int nArtificial;

	public SolverW(double t[][], boolean isMax, int nArtificial, boolean d){
		
		this.debugger = d;
		this.tableaux = new double[t.length+1][t[0].length];
		
		for (int m = 0; m != t.length; m++) {
			for(int n = 0; n != t[0].length; n++){
				this.tableaux[m][n] = t[m][n];
			}
		}
		
		this.max = isMax;
		this.I = new int[t.length - 1];
		this.J = new int[t[0].length - (I.length+1)];
		this.cI = new double[I.length];
		this.cJ = new double[J.length];
		this.k = 0;
		this.s = 0;
		this.r = 0;
		this.linha_r = new double[tableaux[0].length];
		this.Yrk = 0;
		this.z0 = 0;
		this.nArtificial = nArtificial;
		linhasVarArtificial = new int[I.length];
		
		identificarBase();
		calcularW();
		
	}

	void identificarBase(){
		
		int 	contadorVA = 0;
		int 	contadorVB = I.length-1;
		int 	contadorVNB = J.length-1;
		boolean temVariavelArtificial = true;
		boolean baseCompleta = false;
		
		
		for (int n = tableaux[0].length - 1; n != 0; n--) {
			double somador = 0;
			for(int m = 1; m != tableaux.length-1 && !baseCompleta; m++){
				
				somador += tableaux[m][n]; 
				if(temVariavelArtificial && tableaux[m][n]==1.0)
					linhasVarArtificial[contadorVA] = m;
					
			}
			
			
			if(somador==1.0){
				I[contadorVB] = n;
				cI[contadorVB] = tableaux[0][n];
				contadorVB--;
				if(temVariavelArtificial){
					contadorVA++;
					temVariavelArtificial = !(contadorVA == this.nArtificial);
				}
				if(contadorVB == -1)
					baseCompleta = true;
			}else{
				temVariavelArtificial = false;
				J[contadorVNB] = n;
				cJ[contadorVNB] = tableaux[0][n];
				contadorVNB--;
			}
			
		}
		
		A = new int[contadorVA];
		
		for (int n = 0; n != A.length; n++) {
			A[n] = tableaux[0].length - (1+n); 
		}

	}
	
	void calcularW() {
		
		int i=0;
		
		for(int m = 1; m != tableaux.length-1;m++,i++)
			for(int n = 0; n != tableaux[0].length && linhasVarArtificial[i]!=0;n++)
				tableaux[tableaux.length-1][n] +=  tableaux[linhasVarArtificial[i]][n];

		for(int u = 0; u != I.length; u++)
			cI[u] = tableaux[tableaux.length-1][I[u]];
		
		for(int u = 0; u != J.length; u++)
			cJ[u] = tableaux[tableaux.length-1][J[u]];
		
	}
	
	int calcularQuemEntra() {

		int indice = -1;
		double maior = 0;
		boolean testarBland = false;
		
		for(int i=0;i != cJ.length;i++){
			
			//CRITERIO DE MIN -> SE TEM POSIT, CONTINUAR 
			boolean condicao =  cJ[i] > 0 && Math.abs(cJ[i]) > maior;  
			
			if(condicao){
				maior = Math.abs(cJ[i]);
				indice = J[i];
				testarBland = true;
			}
		}
		
		if(testarBland )
			for(int i=0;i != cJ.length;i++){
				
				// REGRA BLAND
				boolean condicao =  cJ[i] > 0 && Math.abs(cJ[i]) == maior && J[i] < indice;  
				
				if(condicao){
					maior = Math.abs(cJ[i]);
					indice = J[i]; 
				}
			}
		
		return indice;

	}
	
	int calcularQuemSai() {

		int indice = -1;
		double menor = Double.MAX_VALUE; //criterio é maior que zero
		boolean testarBland = false;
		
		for(int i=0;i != cI.length;i++){
			double calculoYrk = tableaux[i+1][0]/tableaux[i+1][k];
			if(calculoYrk < menor && calculoYrk > 0){
				menor = calculoYrk;
				indice = I[i];
				r = i+1;
				Yrk = tableaux[i+1][k];
				testarBland = true;
			}
		}
		
		//REGRA DE BLAND
		
		if(testarBland)
			for(int i=0;i != cI.length;i++){
				double calculoYrk = tableaux[i+1][0]/tableaux[i+1][k];
				if(calculoYrk == menor && I[i] < indice){
					menor = calculoYrk;
					indice = I[i];
					r = i+1;
					Yrk = tableaux[i+1][k];
				}
			}
		
		return indice;

	}

	void atualizar_r() {

		for(int n = 0; n<tableaux[0].length;n++)
			tableaux[r][n] = tableaux[r][n]/ Yrk;

	}
	
	void atualizar_cI(int entra, int sai) {

		for (int i = 0; i != I.length; i++)
			if (I[i] == sai) {
				I[i] = entra;
			}

		for (int i = 0; i != I.length; i++)
			cI[i] = tableaux[tableaux.length-1][I[i]];
		
	}
	
	void atualizar_cJ(int entra, int sai) {

		for (int i = 0; i != J.length; i++)
			if (J[i] == sai) {
				J[i] = entra;
			}
		
		for (int i = 0; i != J.length; i++)
			cJ[i] = tableaux[tableaux.length-1][J[i]];

	}
	
	void atualizar_tableau() {

		double y[][] = new double[tableaux.length][tableaux[0].length];
		
		for(int m = 0; m<tableaux.length;m++)
			for(int n = 0; n<tableaux[0].length;n++)
				if(m != r)
					y[m][n] = (tableaux[r][n] * (-1 * tableaux[m][k]));
		
		
		for(int m = 0; m<tableaux.length;m++)
			for(int n = 0; n<tableaux[0].length;n++)
				if(m != r)
					tableaux[m][n] = tableaux[m][n] + y[m][n]; 
			
		
			
		z0 = tableaux[0][0];

	}

	void imprimirTableaut(){
		
		Object[][] saida = new Object[tableaux.length+1][tableaux[0].length];
		String str[] = new String[tableaux[0].length];
	
		for(int i = 0; i != str.length;i++){
			str[i] = i == 0?"z":"x"+i;
			saida[saida.length-1][i] = i == 0?"w":"x"+i; 
		}
		
		
		for(int m=0;m!=tableaux.length;m++)
			for(int n=0;n!=tableaux[0].length;n++)
				saida[m][n] = tableaux[m][n];
				
		TextTable tt = new TextTable(str,saida);                                                         
		tt.printTable();
		
	}
	
	void imprimirSolucao(){
		
		System.out.println("\nÓTIMO: "+z0);
		
		System.out.println("VB: ");
		
		for(int i = 0; i != I.length;i++)
			System.out.println(" x"+I[i] +" = "+ tableaux[i+1][0]);
		
		System.out.println("VNB: ");
		
		for(int i = 0; i != J.length;i++)
			System.out.println(" x"+J[i] +" = "+ 0);
			
	}
	
	double[][] produzirTableauPrimeiraFase(){
		
		double t[][] = new double[tableaux.length-1][tableaux[0].length-A.length];
		
		for(int m=0; m != t.length;m++)
			for(int n=0; n!=t[0].length;n++)
				t[m][n] = tableaux[m][n];
		
		for(int n=0; n!=I.length;n++){
			cI[n] = tableaux[0][I[n]];
		}
		
		int [] data_J = new int[this.J.length-A.length];
		double data_cJ[] = new double[data_J.length];
		
		
		int i=0;
		for(int n=0; n!=this.J.length && i != data_J.length;n++){
			boolean ehArtificial = false;
			int l = this.J[n];
			for(int k=0; k!=A.length && !ehArtificial;k++){
				ehArtificial = l == A[k];
			}	
			if(!ehArtificial){
				data_J[i] = l;
				i++;
			}
		}
		
		this.J = data_J;
		
		for(int n=0; n!=data_J.length;n++){
			data_cJ[n] = t[0][data_J[n]];
		}
		
		this.cJ = data_cJ;
		
		return t;
		
	}
	
	void run(){
		
		System.out.println("******************** 1ª FASE ****************\n");
		
		imprimirTableaut();
		
		if(this.debugger)
			imprimirSolucao();
		
		boolean continuarExecucao = true;
		
		while(continuarExecucao){
			
			//1ª condicao de parada - var artificiais fora da base
			
			//2ª condicao de parada - critério de otimalidade. Por ser de min, todos os
			//valores em w tem de ser menores ou iguais a zero
			k = calcularQuemEntra();
			
			if(k == -1){
				//System.out.println("Critério de parada Zj - Cj resultou em valores menores que zero.");
				continuarExecucao = false;
				break;
			}
			
			s = calcularQuemSai();
			
			if(s == -1){
				System.out.println("\n"+new String("O problema possuí soluções ilimitadas.").toUpperCase());
				continuarExecucao = false;
				break;
			}	
			
			atualizar_r();

			atualizar_tableau();
			
			atualizar_cI(k, s);
			
			atualizar_cJ(s,k);
			
			imprimirTableaut();
			
			if(this.debugger)
				imprimirSolucao();
		
		}
		
		System.out.println("\n******************** 2ª FASE ****************\n");
		SolverZ sp = new SolverZ(produzirTableauPrimeiraFase(),I,cI,J,cJ, max, this.debugger);
		
		sp.run();
		
	}
	
}
