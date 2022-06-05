package solver;

import dnl.utils.text.table.TextTable;

public class SolverZ {
	
	boolean max;

	double tableaux[][];
	
	int I[];
	
	int J[];

	double cI[];
	
	double cJ[];

	int k = 0;
	
	int s = 0;
	
	int r = 0;
	
	double linha_r[];
	
	double Yrk = 0;
	
	double z0 = 0;
	
	boolean debugger = false;
		
	//int as = 0;

	public SolverZ(double t[][], boolean isMax, boolean d){
		this.debugger = d;
		this.tableaux = t;
		this.max = isMax;
		this.I = new int[tableaux.length - 1];
		this.J = new int[tableaux[0].length - (I.length+1)];
		this.cI = new double[I.length];
		this.cJ = new double[J.length];
		this.k = 0;
		this.s = 0;
		this.r = 0;
		this.linha_r = new double[tableaux[0].length];
		this.Yrk = 0;
		this.z0 = 0;
		
		int j = 0;

		for (int i = I.length - 1; i != -1; i--, j++) {
			I[i]  = tableaux[0].length - (j + 1);
			cI[i] = tableaux[0][I[i]];
		}
		
		for (int i = 0; i != J.length; i++) {
			J[i] = i+1;
			cJ[i] = tableaux[0][J[i]];
		}
	}
	
	public SolverZ(double t[][],int I[], double cI[], int J[], double cJ[], boolean isMax, boolean d){
		this.tableaux = t;
		this.max = isMax;
		this.I = I;
		this.J = J;
		this.cI = cI;
		this.cJ = cJ;
		this.k = 0;
		this.s = 0;
		this.r = 0;
		this.linha_r = new double[tableaux[0].length];
		this.Yrk = 0;
		this.z0 = t[0][0];
		this.debugger =d;
		
	}

	int calcularQuemEntra() {

		int indice = -1;
		double maior = 0;
		boolean testarBland = false;
		
		for(int i=0;i != cJ.length;i++){
			//max
			
			boolean condicao = max ?
					cJ[i] < 0 && Math.abs(cJ[i]) > maior:
					cJ[i] > 0 && Math.abs(cJ[i]) > maior;
			
			if(condicao){
				maior = Math.abs(cJ[i]);
				indice = J[i];
				testarBland=true;
			}
		}
		
		if(testarBland)
			for(int i=0;i != cJ.length;i++){
				//max or min
				boolean condicao = max ?
						cJ[i] < 0 && Math.abs(cJ[i]) == maior && J[i] > indice:
						cJ[i] > 0 && Math.abs(cJ[i]) == maior && J[i] < indice;
				
				if(condicao){
					//maior = Math.abs(cJ[i]);
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
				boolean condicao = max ? 
						calculoYrk == menor && I[i] > indice:
						calculoYrk == menor && I[i] < indice;	
				if(condicao){
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
			cI[i] = tableaux[0][I[i]];
		
	}
	
	void atualizar_cJ(int entra, int sai) {

		for (int i = 0; i != J.length; i++)
			if (J[i] == sai) {
				J[i] = entra;
			}
		
		for (int i = 0; i != J.length; i++)
			cJ[i] = tableaux[0][J[i]];

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
		
		String str[] = new String[tableaux[0].length];
		
		for(int i = 0; i != str.length;i++)
			str[i] = i == 0?"z":"x"+i;
		
		Object[][] saida = new Object[tableaux.length][tableaux[0].length];
		
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
	
	boolean possuiBaseViavel(){
		//AVALIA SE A BASE VINDA DA PRIMEIRA FASE UMA VAR ARTIFICIAL COM VALOR POSITIVO
		
		for(int i : I){
			if(i>=tableaux[0].length)
				return true;
		}
		return false;
	}
	
	void run(){
				
		imprimirTableaut();
		if(this.debugger)
			imprimirSolucao();
		boolean continuarExecucao = true;
		boolean viavel = true;
		
		if(possuiBaseViavel()){
			continuarExecucao = false;
			viavel = false;
		}
		
		while(continuarExecucao){
			k = calcularQuemEntra();
			
			if(k == -1){
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
		
		if(viavel){
			System.out.println("\n\n******************** SOLUÇÃO FINAL ****************\n");
			imprimirSolucao();
			System.out.println("\n******************** FIM DA EXECUÇÃO ****************\n");
		}
		else{
			System.out.println("\n******************** FIM DA EXECUÇÃO ****************\n");
			System.out.println("O MODELO NÃO APRESENTOU UMA SOLUÇÃO VIÁVEL!");
		}
		
	}
	
}
