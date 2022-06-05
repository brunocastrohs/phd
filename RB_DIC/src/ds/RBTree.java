package ds;

public class RBTree {

	private RBElement root;
	private int qtd = 0;
	private static int qtd_blacks = 0;
	private boolean reachedExternalNodes = false;
	public static RBElement sentinel;
	public static final int RED = 1;
	public static final int BLACK = 0;
	
	public RBTree() {
		sentinel = new RBElement();
		sentinel.parent = sentinel;
		sentinel.left = sentinel;
		sentinel.right = sentinel;
		root = sentinel;
	}
	
	RBElement RBRoot(){
		return this.root==sentinel?root.left:root;
	}

	void RBSetkLevel(RBElement vr) {
		
		if ( vr != sentinel) {
			vr.level = 1 + vr.parent.level;
			
			if(!reachedExternalNodes && vr.color == BLACK)
				qtd_blacks++;
			
			RBSetkLevel(vr.left);
			RBSetkLevel(vr.right);
		}else{
			if(!reachedExternalNodes){
				qtd_blacks++;
				RBSetBlackLevel(RBRoot(), true);
				sentinel.black_level = qtd_blacks; 
			}
			reachedExternalNodes = true;
			
		}
		
	}
	
	void RBSetBlackLevel(RBElement vr , boolean isFirst) {
		
		if(isFirst && vr!=sentinel){
			RBInitBlackLevel(vr);
		}
		
		if(vr!=sentinel){
			
			//vr.black_level = vr.parent.color == BLACK || vr.color == RED ? vr.parent.black_level-1:vr.parent.black_level;
			vr.black_level = vr.color == BLACK  ? vr.parent.black_level-1:vr.parent.black_level;
			RBSetBlackLevel(vr.left,false);
			RBSetBlackLevel(vr.right,false);
			
		}
		
	}
	
	void RBInitBlackLevel(RBElement vr) {
		
		if(vr!=sentinel){
			vr.black_level = qtd_blacks;
			RBInitBlackLevel(vr.left);
			RBInitBlackLevel(vr.right);
		}
		
	}
	
	void RBCheck(RBElement vr) {
		
		if ( vr != sentinel) {
			vr.level = 1 + vr.parent.level;
			System.out.println(vr);
			RBCheck(vr.left);
			RBCheck(vr.right);
		}
		
	}

	void RBPrint(RBElement vr) {
		
		RBElement s = sentinel;
		
		if (vr != s) {
			vr.level = 1 + vr.parent.level;
			RBPrint(vr.left);
			System.out.print("'"+vr.key + "' ");
			RBPrint(vr.right);
		}
		
	}

	RBElement RBMinimum(RBElement vr) {
		if (vr.left != sentinel) {
			return RBMinimum(vr.left);
		}
		return vr;
	}

	RBElement RBMaximum(RBElement vr) {
		if (vr.right != sentinel) {
			return RBMaximum(vr.right);
		}
		return vr;
	}

	RBElement RBPredecessor(RBElement vr) {

		if (vr!= sentinel && vr.left != sentinel)
			return RBMaximum(vr.left);

		RBElement y = vr.parent;

		while (y != sentinel && y.left == vr) {
			vr = y;
			y = y.parent;
		}

		return y;

	}

	RBElement RBSucessor(RBElement vr) {

		if (vr.right != sentinel)
			return RBMinimum(vr.right);

		RBElement y = vr.parent;

		while (y != sentinel && y.right == vr) {
			vr = y;
			y = y.parent;
		}

		return y;

	}

	RBElement RBSearch(RBTree T, RBElement vr) {

		if (RBRoot()!=sentinel) {

			RBElement y = RBRoot();
			
			while (y != sentinel) {
				if (y.equals(vr)) {
					return y;
				} else if (y.greaterThan(vr)) {
					y = y.left;
				} else
					y = y.right;
			}

		}

		return sentinel;
	}

	public RBElement RBSearch(RBTree T, String key) {

		RBElement vr = new RBElement(key);
		System.out.print("Buscando por '"+key+"' na RBTree...");
		if (RBRoot()!=sentinel) {

			RBElement y = RBRoot();
			while (y != sentinel) {
				if (y.equals(vr)) {
					System.out.println(" encontrada!");
					return y;
				} else if (vr.lessThan(y)) {
					y = y.left;
				} else
					y = y.right;
			}

		}
		System.out.println("não encontrada.");
		return sentinel;
	}
	
	@SuppressWarnings({ "static-access" })
	void RBLeftRotate(RBTree T, RBElement x) {
		// ok
		RBElement y = x.right;
		x.right = y.left;
		if (y.left != T.sentinel)
			y.left.parent = x;
		y.parent = x.parent;
		if (x.parent == T.sentinel)
			T.root = y;
		else if (x == x.parent.left)
			x.parent.left = y;
		else
			x.parent.right = y;
		y.left = x;
		x.parent = y;
	}

	@SuppressWarnings({ "static-access" })
	void RBRightRotate(RBTree T, RBElement y) {
		//
		RBElement x = y.left;
		y.left = x.right;
		if (x.right != T.sentinel)
			x.right.parent = y;
		x.parent = y.parent;
		if (y.parent == T.sentinel)
			T.root = x;
		else if (y == y.parent.left)
			y.parent.left = x;
		else
			y.parent.right = x;
		x.right = y;
		y.parent = x;
	}

	void RBInsert(RBTree T, RBElement z) {
		
		if(RBSearch(T, z) != sentinel){
			System.out.print("\nInserindo '"+z.key+"'...");
			System.out.println("não foi possível.\nCAUSA: O elemento '"+z.key+"' já está na árvore.");
			return;
		}
		
		RBElement x = RBRoot();
		RBElement y = T.root;
		
		while (x != sentinel && x != null) {
			y = x;
			if (x.greaterThan(z)) {
				x = x.left;
			} else {
				x = x.right;
			}
		}
		
		z.parent = y;
		
		if((y == T.root && y.left == sentinel)){
			y.left = z;
		}
		else if ((y.greaterThan(z))) {
			y.left = z;
		} else {
			y.right = z;
		}
		
		qtd++;
		RBInsertFixUp(T,z);
		qtd_blacks = 0;
		reachedExternalNodes=false;
		RBSetkLevel(RBRoot());
	}

	RBElement RBInsertFixUp(RBTree tree, RBElement z) {
		RBElement y;
		z.color = RED;
		while (z.parent.color == RED) { 
			
			if (z.parent == z.parent.parent.left) {
				y = z.parent.parent.right;
				if (y.color == RED) {
					z.parent.color = BLACK;
					y.color = BLACK;
					z.parent.parent.color = RED;
					z = z.parent.parent;
				} else {
					if (z == z.parent.right) {
						z = z.parent;
						RBLeftRotate(tree, z);
					}
					z.parent.color = BLACK;
					z.parent.parent.color = RED;
					RBRightRotate(tree, z.parent.parent);
				}
			} else {
				y = z.parent.parent.left;
				if (y.color == RED) {
					z.parent.color = BLACK;
					y.color = BLACK;
					z.parent.parent.color = RED;
					z = z.parent.parent;
				} else {
					if (z == z.parent.left) {
						z = z.parent;
						RBRightRotate(tree, z);
					}
					z.parent.color = BLACK;
					z.parent.parent.color = RED;
					RBLeftRotate(tree, z.parent.parent);
				}
			}
		}
		
		if(tree.root == sentinel)
			tree.root.left.color = BLACK;
		else if(tree.root.color==RED)
			tree.root.color = BLACK;
		
		return z;

	}

	@SuppressWarnings({ "static-access" })
	RBElement RBDelete(RBTree T, RBElement z) {
		RBElement x = null;
		String k = z!=null?z.key:null;
		RBElement y = z = RBSearch(T, z);
		
		System.out.print("\nDeletando '"+k+"'...");
		
		if(z==sentinel){
			System.out.println("não foi possível.\nCAUSA: Elemento '"+k+"' não se encontra na árvore.");
			return sentinel;
		}
		
		int y_cor_original = y.color;
		if (z.left == T.sentinel) {
			x = z.right;
			RBTransplant(T, z, z.right);
		} else if (z.right == T.sentinel) {
			x = z.left;
			RBTransplant(T, z, z.left);
		} else {
			y = RBMinimum(z.right);
			y_cor_original = y.color;
			x = y.right;
			if (y.parent == z)
				x.parent = y;
			else {
				RBTransplant(T, y, y.right);
				y.right = z.right;
				y.right.parent = y;
			}
			RBTransplant(T, z, y);
			y.left = z.left;
			y.left.parent = y;
			y.color = z.color;
		}

		if (y_cor_original == BLACK)
			RBDeleteFixUp(T, x);
		
		qtd--;
		if(qtd==0){
			//sentinel = new RBElement();
			sentinel.left = sentinel;
			root = sentinel;
		}
		
		qtd_blacks = 0;
		reachedExternalNodes=false;
		T.RBSetkLevel(RBRoot());
		System.out.println("ok\n");
		System.out.println("RBPrint:");
		T.RBPrint(RBRoot());
		System.out.println("\nRBCheck:");
		T.RBCheck(RBRoot());
		
		return z;
	}

	@SuppressWarnings({ "static-access" })
	void RBTransplant(RBTree T, RBElement u, RBElement v) {
		if (u.parent == T.sentinel)
			T.root = v;
		else if (u == u.parent.left)
			u.parent.left = v;
		else
			u.parent.right = v;
		v.parent = u.parent;
	}

	void RBDeleteFixUp(RBTree T, RBElement x) {

		while (x != T.root && x.color == BLACK) {

			if (x == x.parent.left) {
				RBElement w = x.parent.right;
				if (w.color == RED) {
					w.color = BLACK;
					x.parent.color = RED;
					RBLeftRotate(T, x.parent);
					w = x.parent.right;
				}
				if (w.left.color == BLACK && w.right.color == BLACK) {
					w.color = RED;
					x = x.parent;
				} else if (w.right.color == BLACK) {
					w.left.color = BLACK;
					w.color = RED;
					RBRightRotate(T, w);
					w = x.parent.right;
					w.color = x.parent.color;
					x.parent.color = BLACK;
					w.right.color = BLACK;
					RBLeftRotate(T, x.parent);
					x = T.root;
				}

			} else {

				RBElement w = x.parent.left;
				if (w.color == RED) {
					w.color = BLACK;
					x.parent.color = RED;
					RBRightRotate(T, x.parent);
					w = x.parent.left;
				}
				if (w.right.color == BLACK && w.left.color == BLACK) {
					w.color = RED;
					x = x.parent;
				} else if (w.left.color == BLACK) {
					w.right.color = BLACK;
					w.color = RED;
					RBLeftRotate(T, w);
					w = x.parent.left;
					w.color = x.parent.color;
					x.parent.color = BLACK;
					w.left.color = BLACK;
					RBRightRotate(T, x.parent);
					x = T.root;
				}

			}

		}
		x.color = BLACK;
	}

	public void RBInstanceReader(String str){
		try{
		String sentences[] = str.split("\n");
		boolean isFirst = true;
		
		for(String s: sentences){
			
			String commands[] = s.split(" ");
			
			if(commands.length==2){
				if(isFirst){
					System.out.println("******************** LEITURA INICIADA ********************");
					isFirst = false;
				}
				
				if(commands[1].equals("1") && !commands[0].equals("")){
					//System.out.println("\n\n******************** INSERCAO ********************");
					RBInsert(this, new RBElement(commands[0]));
				}
				else if(commands[1].equals("0") && !commands[0].equals("")){
					RBDelete(this, new RBElement(commands[0]));
				}
				else{
					System.out.println("\n\n******************** LEITURA ENCERRADA ********************");
					return;
				}
				
			}
			
		}
		}catch(Exception e){
			System.out.println("\n\n******************** ERRO NA LEITURA ********************");
			String warn = "Ocorreu um erro na leitura da sua instância. Tente de novo,\n"
					+ "mas antes certifique-se destas restrições:\n"
					+ "- Evite caracteres especiais;\n"
					+ "- Arquivos importados devem estar em codificação UTF-8 (sem BOM);\n"
					+ "- Texto colado na área de entrada deve vir codificado em UTF-8 (sem BOM);\n"
        			+ "- As orientações do professor devem ser seguidas na confeccção dos arquivos de entrada;\n" 
					+ "- Cada linha deve conter uma string (vazia ou não), em seguida o caractere ';' e depois o digito 0 ou 1;\n"
					+ "- Se uma palavra é seguida pelo digito 1, a mesma será inserida da árvore;\n"
					+ "- Se uma palavra é seguida pelo digito 0, a mesma será removida da árvore;\n"
					+ "- O fim do arquivo ou uma linha contendo uma String vazia indicará o fim da leitura do arquivo de entrada.\n";
			System.out.println(warn);
		}
		System.out.println("\n\n******************** LEITURA ENCERRADA ********************");
		System.out.println("\n\n******************** ÁRVORE FINAL ********************");
		System.out.println("RBPrint:");
		RBPrint(RBRoot());
		System.out.println("\nRBCheck:");
		RBCheck(RBRoot());
		System.out.println("\n\n");
		
	}

	public static void main(String[] a){
		String str = 
				"xuxa 0\n"+
				"ana 1\n"+
				"bia 1\n"+
				"caio 1\n"+
				"bia 0\n"+
				"dani 1\n"+
				"bob 1\n"+
				"ana 0\n"+
				"cris 1\n"+
				"elis 1\n"+
				"xuxa 1\n"+
				"caio 1\n"+
				"zeus 1";
				
		new RBTree().RBInstanceReader(str);
	}

}

class RBElement {
	
	RBElement parent;
	RBElement left;
	RBElement right;
	String key;
	int level;
	int black_level;
	int color;

	public RBElement(String d) {
		this.key = d;
		this.color = RBTree.BLACK;
		this.parent = RBTree.sentinel;
		this.left = RBTree.sentinel;
		this.right = RBTree.sentinel;
	}

	public RBElement() {
		this.key = null;
		this.color = RBTree.BLACK;
		this.parent = RBTree.sentinel;
		this.left = RBTree.sentinel;
		this.right = RBTree.sentinel;
	}

	public boolean greaterThan(RBElement no){
		return this.key.compareTo(no.key)>0;
	}
	
	public boolean lessThan(RBElement no){
		return this.key.compareTo(no.key)<0;
	}
	
	public boolean equals(RBElement no){
		return this.key.equals(no.key);
	}
	
	public String toString() {

		return this.key == null ? "nil"
				: "(" + (parent.key == null ? "nil" : parent.key) + ", " + key + ", "
						+ (color == 1 ? "vermelho" : "preto") + ", " + black_level + ", "
						+ (left.key == null ? "nil" : left.key) + ", "
						+ (right.key == null ? "nil" : right.key) + ")";
	}
}
