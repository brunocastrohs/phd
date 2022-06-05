package solver;

import dnl.utils.text.table.TextTable;

//OBS: LEMBRAR QUE W NÃO É MULTIPLICADO POR -1, POIS O QUE É INVERTIDO
//SÃO AS CONDIÇÕES: 
//		OTIMALIDADE (SE TODOS SÃO NEGATIVOS, ENTÃO OTIMO ACHIVIED)
//		QUEM ENTRA É O MAIOR POSITIVO		

//PENDENCIAS:
// ***** OS TESTES 8 E 11 FALHAM, POIS NO FIM DA PRIMEIRA FASE, UMA VAR ARTIFICIAL
//		 AINDA ESTÁ NA BASE, PORÉM, NA SEGUNDA FASE, A SOLUÇÃO PODE SER MELHORADA
// - COEFICIENTES DE Z SEM NADA. EX: X1 + X2
// - SUPORTAR INDEXAÇÃO DUPLA

public class Simplex {

	// A VARI´VAVEL DE DECISÃO DEVE SER DENOTADA POR x
	// O INDICE DA VARIAVEL DEVE INICIAR EM 1
	// TODA RESTRIÇÃO DEVE SER UMA INEQUAÇÃO DE >=, <= OU =
	// NÃO DEVE HAVER CONSTANTES EM Z

	String modelo;

	int n;

	int m;

	boolean max;

	boolean duasFases = false;

	double tableau[][];

	/** META DATA */
	String linhasModelo[];

	int varIniciais[];

	double coefecientesZ[];

	double limitesRestricoes[];

	int colunaFolga[];

	int colunaFolgaNegativa[];

	int colunaArtificial[];

	boolean debugger = false;

	int nFolgaPositiva = 0;
	
	int nFolgaNegativa = 0;
	
	int nArtificial = 0;

	public Simplex() {
	}

	public Simplex(String m) {
		this.modelo = m;
	}
	
	public Simplex(String m, boolean d) {
		this.modelo = m;
		this.debugger = true;
	}

	void carregarLinhasModelo() {
		// carregar linhas
		modelo = modelo.replace("\r", "");
		String[] dataLine = modelo.split("\n");
		linhasModelo = modelo.split("\n");
		linhasModelo[0] = linhasModelo[0].replace(" x", " 1x").replace("-x", "-1x").replace("- x", "- 1x");

		int linhaContador = 2;
		for (int i = 2; i != dataLine.length; i++) {
			if (dataLine[i].contains("<=")) {
				linhasModelo[linhaContador] = dataLine[i];
				linhaContador++;
			}
		}

		for (int i = 2; i != dataLine.length; i++) {
			if (dataLine[i].contains(">=")) {
				linhasModelo[linhaContador] = dataLine[i];
				linhaContador++;
			}
		}

		for (int i = 2; i != dataLine.length; i++) {
			if (!dataLine[i].contains(">=") && !dataLine[i].contains("<=")) {
				linhasModelo[linhaContador] = dataLine[i];
				linhaContador++;
			}
		}

		/*if (debugger)
			for (String s : linhasModelo)
				if (!s.contains("st"))
					System.out.println(s);*/

		colunaFolga = new int[linhasModelo.length - 2];
		colunaFolgaNegativa = new int[linhasModelo.length - 2];
		colunaArtificial = new int[linhasModelo.length - 2];

	}

	void definirTipoProblema() {
		// MAX OU MIN
		max = linhasModelo[0].contains("max");
		if (debugger)
			System.out.println(max ? "\nTRATA-SE DE UM PROBLEMA DE MAX! " : "\nTRATA-SE DE UM PROBLEMA DE MIN!");

		m = linhasModelo.length - 1;

		linhasModelo[0] = linhasModelo[0].replace(max ? "max" : "min", "");
	}

	void carregarVarIniciais() {
		// VARIÁVEIS INICIAIS
		linhasModelo[0] = linhasModelo[0].replace(" ", "").replace("\t", " ");
		linhasModelo[0] += "+";
		if (debugger)
			System.out.println("\nVARIÁVEIS DE DECISÃO INICIAIS: ");

		char z[] = linhasModelo[0].toCharArray();
		for (char e : z)
			if (e == 'x')
				n++;

		varIniciais = new int[n];
		for (int i = 0; i != n; i++) {
			varIniciais[i] = i + 1;
			if (debugger)
				System.out.println("x" + (i + 1));
			linhasModelo[0] = linhasModelo[0].replace("x" + (i + 1) + "+", "+");
			linhasModelo[0] = linhasModelo[0].replace("x" + (i + 1) + "-", "-");
		}
	}

	void carregarCoefsDeZ() {
		// COEFICIENTES FUN. OBJ
		if (debugger)
			System.out.println("\nCOEFICIENTES DA FUNÇÃO OBJETIVO: ");
		coefecientesZ = new double[n];
		int c = 0;
		char[] data = linhasModelo[0].toCharArray();
		String str = "";
		for (int i = 0; i != data.length; i++) {
			if (i != 0 && (data[i] == '+' || data[i] == '-')) {
				coefecientesZ[c] = -1 * Double.parseDouble(str);
				str = data[i] == '-' ? "-" : "";
				if (debugger)
					System.out.println("x" + (c + 1) + ":" + coefecientesZ[c]);
				c++;
			} else
				str += "" + data[i];
		}
	}

	void carregarOperadoresDasRestricoes() {
		// OPERADORES
		//if (debugger)
			//System.out.println("\nOPER's: ");

		for (int i = 2; i != linhasModelo.length; i++) {
			char aux[] = linhasModelo[i].toCharArray();
			boolean buscar = true;
			for (char e : aux)
				if (e == '<' && buscar) {
				//	if (debugger)
				//		System.out.println((i - 1) + ": " + e + "=");
					buscar = false;
					n++;
					colunaFolga[i - 2] = 1;
					nFolgaPositiva++;
				} else if (e == '>' && buscar) {
				//	if (debugger)
				//		System.out.println((i - 1) + ": " + e + "=");
					buscar = false;
					n++;
					n++;
					duasFases = true;
					colunaFolgaNegativa[i - 2] = -1;
					colunaArtificial[i - 2] = 1;
					nFolgaNegativa++;
					nArtificial++;
				} else if (e == '=' && buscar) {
				//	if (debugger)
				//		System.out.println((i - 1) + ": " + e);
					buscar = false;
					n++;
					duasFases = true;
					colunaArtificial[i - 2] = 1;
					nArtificial++;
				}
		}
		tableau = new double[m][1 + n];

	}

	void carregarLimitesDasRestricoes() {
		// TERMOS INDEP. DAS RESTRIÇÕES
		if (debugger)
			System.out.println("\nLIMITES DAS RESTRIÇÕES: ");
		limitesRestricoes = new double[linhasModelo.length - 2];

		for (int i = 2; i != linhasModelo.length; i++) {
			String aux[] = linhasModelo[i].split("=");
			double val = Double.parseDouble(aux[1].replace(" ", ""));
			limitesRestricoes[i - 2] = val > 0?val:0.1f;
			if (debugger)
				System.out.println((i - 1) + ": " + aux[1]);
			linhasModelo[i] = aux[0].replace("<", "").replace(">", "").replace(" ", "").replace("\t", "");
			linhasModelo[i] += "+";
		}
	}

	void carregarCoeficientesDasRestricoes() {
		// COEFICIENTES DAS RESTRIÇÕES
		String str = "";
		if (debugger)
			System.out.println("\nCOEFICIENTES DAS RESTRIÇÕES: ");
		for (int i = 2; i != linhasModelo.length; i++) {
			char[] dataLine = linhasModelo[i].toCharArray();
			for (char d : dataLine) {
				if ((d == '+' || d == '-') && str.contains("x")) {
					String dataAux[] = str.split("x");
					int indice = Integer.parseInt(dataAux[1]);
					double v = 0;
					if (dataAux[0].equals(""))
						v = 1;
					else if (dataAux[0].equals("-"))
						v = -1;
					else
						v = Double.parseDouble(dataAux[0]);
					tableau[i - 1][indice] = v;
					str = d == '-' ? "-" : "";
					if (debugger)
						System.out.print(" x" + (indice) + ":" + v);
				} else
					str += d == ' ' ? "" : "" + d;
			}
			if (debugger)
				System.out.print("\n");
		}

		for (int i = 1; i != m; i++)
			tableau[i][0] = limitesRestricoes[i - 1];
	}

	void atualizarTableau() {

		for (int i = 0; i != coefecientesZ.length; i++) {
			tableau[0][i + 1] = coefecientesZ[i];
		}

		int colunaCount = coefecientesZ.length + 1;
		for (int m = 1; m != tableau.length; m++) {
			if (colunaFolga[m - 1] != 0) {
				tableau[m][colunaCount] = colunaFolga[m - 1];
				colunaCount++;
			}
		}

		for (int m = 1; m != tableau.length; m++) {
			if (colunaFolgaNegativa[m - 1] != 0) {
				tableau[m][colunaCount] = colunaFolgaNegativa[m - 1];
				colunaCount++;
			}
		}

		for (int m = 1; m != tableau.length; m++) {
			if (colunaArtificial[m - 1] != 0) {
				tableau[m][colunaCount] = colunaArtificial[m - 1];
				colunaCount++;
			}
		}

	}

	void imprimirSomadorDeVar(){
		if (debugger){
			System.out.println("\nQUANTIDADE DE VARIÁVEIS POR TIPO: ");
			System.out.println("Folga Positiva: "+nFolgaPositiva);
			System.out.println("Folga Negativa: "+nFolgaNegativa);
			System.out.println("Artificial: "+nArtificial+"\n");
		}
	}
	
	public void run() {

		if(this.debugger)
			System.out.println("******************** LEITURA DO MODELO ****************\n");
		
		try{
		carregarLinhasModelo();

		definirTipoProblema();

		carregarVarIniciais();

		carregarCoefsDeZ();

		carregarOperadoresDasRestricoes();

		carregarLimitesDasRestricoes();

		carregarCoeficientesDasRestricoes();

		atualizarTableau();
		
		imprimirSomadorDeVar();

		try {
			if (duasFases)
				new SolverW(tableau, max, nArtificial, this.debugger).run();
			else
				new SolverZ(tableau, max,this.debugger).run();
		} catch (Exception e) {
			System.out.println("O seu modelo está inconcistente.\nVerifique se o seu modelo está\nno padrão deste solver:\n"
					+ "- Não usar letras maiúsculas;\n"
        			+ "- Usar as palavras max ou min para designar o\ntipo do problema;\n" 
					+ "- A variável de decisão deve ser denotada\nsomente por x;\n"
					+ "- O índice da variável de decisão\n deve iniciar em 1;\n"
					+ "- Toda restrição deve ser do tipo\n >=, <= ou =;\n" 
					+ "- Não devem existir constantes na\n função objetivo;\n"
					+ "- A função objetivo deve ser toda ela \nespecificada na primeira linha;\n"
					+ "- Não são suportados variáveis\n duplamente indexadas e os operadores de\n multiplicação(*) e divisão(/).\n");
			e.printStackTrace();
		} }catch(Exception e){
			System.out.println("Ocorreu um erro na leitura do modelo.\n"
					+ "Copie e cole o modelo direto do arquivo\nfonte para a aplicação.\n"
					+ "Depois verifique se o seu modelo está\nno padrão deste solver:\n"
					+ "- Não usar letras maiúsculas;\n"
        			+ "- Usar as palavras max ou min para designar o\ntipo do problema;\n" 
					+ "- A variável de decisão deve ser denotada\n somente por x;\n"
					+ "- O índice da variável de decisão\n deve iniciar em 1;\n"
					+ "- Toda restrição deve ser do\n tipo >=, <= ou =;\n" 
					+ "- Não devem existir constantes na\n função objetivo;\n"
					+ "- A função objetivo deve ser toda ela \nespecificada na primeira linha;\n"
					+ "- Não são suportados variáveis\n duplamente indexadas e os operadores de\n multiplicação(*) e divisão(/).\n");
			e.printStackTrace();
		}
	}

	void imprimirTableaut() {

		String str[] = new String[tableau[0].length];

		for (int i = 0; i != str.length; i++)
			str[i] = i == 0 ? "z" : "x" + i;

		Object[][] saida = new Object[tableau.length][tableau[0].length];

		for (int m = 0; m != tableau.length; m++)
			for (int n = 0; n != tableau[0].length; n++)
				saida[m][n] = tableau[m][n];

		TextTable tt = new TextTable(str, saida);
		tt.printTable();

	}
	
}
