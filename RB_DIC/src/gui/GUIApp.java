package gui;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.PrintStream;
import java.net.URL;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JEditorPane;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

import ds.RBTree;
import gui.JTextAreaOutputStream;

public class GUIApp extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 4115273481157888542L;
	JMenu fileMenu = new JMenu("Arquivo");
	JMenu runMenu = new JMenu("Rotinas");
	JMenu helpMenu = new JMenu("Ajuda");
	JMenuItem newAction = new JMenuItem("Novo");
	JMenuItem openAction = new JMenuItem("Abrir");
	JMenuItem exitAction = new JMenuItem("Sair");
	JMenuItem runAction = new JMenuItem("Rodar");
	JMenuItem searchAction = new JMenuItem("Buscar");
	JMenuItem aboutAction = new JMenuItem("Sobre");
	JMenuItem sintaxAction = new JMenuItem("Instruções");
	int[] textAreaMeasures = { 30, 70 };
	final JTextArea problemArea = new JTextArea(textAreaMeasures[0], textAreaMeasures[1]);
	final JTextArea solutionArea = new JTextArea(textAreaMeasures[0], textAreaMeasures[1]);
	JButton solveButton = new JButton("Rodar >>");
	RBTree T;
	
	public GUIApp() {

		/************ WINDOW ***************/
		configureWindow();

		/************ MENU ***************/

		configureMenu();

		/************ TEXT AREA ***************/

		configureCenterPanel();

	}

	public void configureWindow() {
		URL url = GUIApp.class.getResource("favicon.png");
		setIconImage(new ImageIcon(url).getImage());
		setTitle("RBTProject");
		setSize(1200, 600);
		setLocationRelativeTo(null);
		setLayout(new FlowLayout());
		setDefaultCloseOperation(EXIT_ON_CLOSE);
	}

	public void configureMenu() {

		JMenuBar menuBar = new JMenuBar();

		setJMenuBar(menuBar);

		menuBar.add(fileMenu);
		menuBar.add(runMenu);
		menuBar.add(helpMenu);

		newAction.setIcon(new ImageIcon(GUIApp.class.getResource("new.png")));
		openAction.setIcon(new ImageIcon(GUIApp.class.getResource("open.png")));
		exitAction.setIcon(new ImageIcon(GUIApp.class.getResource("exit.png")));
		aboutAction.setIcon(new ImageIcon(GUIApp.class.getResource("help.png")));
		sintaxAction.setIcon(new ImageIcon(GUIApp.class.getResource("help.png")));
		runAction.setIcon(new ImageIcon(GUIApp.class.getResource("solve.png")));
		searchAction.setIcon(new ImageIcon(GUIApp.class.getResource("debug.png")));

		newAction.addActionListener( new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                   	 problemArea.setText("");
                }
        });
		
		exitAction.addActionListener( new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                   	System.exit(0);
                }
        });
		
		configureFileChooser();
		
		sintaxAction.addActionListener( new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
            	 final ImageIcon icon = new ImageIcon(GUIApp.class.getResource("message.png"));
            	 String msg = 
            			 "Eis as instruções de uso desta aplicação:\n"
            			+ "- Arquivos importados devem estar em codificação UTF-8 (sem BOM);\n"
            			+ "- As orientações do professor devem ser seguidas na confeccção dos arquivos de entrada;\n" 
    					+ "- Cada linha deve conter uma string (vazia ou não), em seguida o caractere ';' e depois o digito 0 ou 1;\n"
    					+ "- Se uma palavra é seguida pelo digito 1, a mesma será inserida da árvore;\n"
    					+ "- Se uma palavra é seguida pelo digito 0, a mesma será removida da árvore;\n"
    					+ "- O fim do arquivo ou uma linha contendo uma String vazia indicará o fim da leitura do arquivo de entrada.\n";
                 JOptionPane.showMessageDialog(null, msg, "AJUDA", JOptionPane.INFORMATION_MESSAGE, icon);
                }
        });
		
		aboutAction.addActionListener( new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
            	 final ImageIcon icon = new ImageIcon(GUIApp.class.getResource("message.png"));
            	 String msg = 
            			 "Este sistema foi desenvolvido como requisito"
            	 		+ "\n para obter uma das notas de avalição inerentes a"
            	 		+ "\n disciplina de Estruturas de Dados e Algoritmos"
            	 		+ "\n ministrada pelo professor Bruno Motta junto ao  PPgSC/UFRN."            	
            	 		+ "\nAluno: Bruno de Castro H. Silva."
            	 		+ "\nContato: bruno@crateus.ufc.br.";
                 JOptionPane.showMessageDialog(null, msg, "AJUDA", JOptionPane.INFORMATION_MESSAGE, icon);


                }
        });
		
		
		runAction.addActionListener( new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
	            	solutionArea.setText("");
					T = new RBTree();
					T.RBInstanceReader(problemArea.getText());
                }
        });
		
		searchAction.addActionListener( new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
            		System.out.println("******************** BUSCA INICIADA ********************\n");
            		final ImageIcon icon = new ImageIcon(GUIApp.class.getResource("message.png"));
            		if(T != null){
	            		String key="";
	            		do{
	            			
	            			try{
	            				
	            				key = (String)JOptionPane.showInputDialog(null,"Entre com a chave de busca:","BUSCA",JOptionPane.INFORMATION_MESSAGE,icon,null,"");
	            				//key = JOptionPane.showInputDialog(null,"Entre com a chave de busca:");
	            				if(!key.equals("")){
		            				T.RBSearch(T, key);
		            			}
	            			}catch(Exception e){
	            				break;
	            			}
	            		}while(!key.equals(""));
	            	
            		}else{
            			System.out.println("A rotina de busca foi abortada.");
            			System.out.println("CAUSA: Árvore está vazia.");
            		}
            		System.out.println("\n******************** BUSCA ENCERRADA ********************");
            	}
            	
        });
		
		fileMenu.add(newAction);
		fileMenu.add(openAction);
		fileMenu.addSeparator();
		fileMenu.add(exitAction);
		runMenu.add(runAction);
		runMenu.add(searchAction);
		helpMenu.add(sintaxAction);
		helpMenu.add(aboutAction);
		
	}

	public void configureFileChooser() {
		 final JFileChooser fileChooser = new JFileChooser();
         final JEditorPane document = new JEditorPane();

         final JFrame f = this;
         
		 openAction.addActionListener( new ActionListener() {
             public void actionPerformed(ActionEvent ae) {
                 
            	 int result = fileChooser.showOpenDialog(f);
                 if (result==JFileChooser.APPROVE_OPTION) {
                     File file = fileChooser.getSelectedFile();
                     try {
                    	 document.setPage(file.toURI().toURL());
                    	 String aux = document.getText().toString();
                    	 problemArea.setText(aux.toString());
                     } catch(Exception e) {
                         e.printStackTrace();
                     }
                 }
                 
                 //
                 
             }
         });
	}
	
	public void configureCenterPanel() {

		String str = "teste 0\n"+
				   "abuso 1\n"+
				   "carro 1\n"+
				   "doce 1\n"+
				   "gola 1\n"+
				   "gola 0\n"+
				   "palhaço 1\n"+
				   "taturana 1\n"+
				   "pacote 1\n"+
				   "abusado 0\n"+
				   "bolha 1\n"+
				   "fussura 1";
		
		problemArea.setText(str);
		JScrollPane problemPane = new JScrollPane(problemArea);
		problemArea.setFont(new Font("monospaced", Font.PLAIN, 12));
		
		solutionArea.setEditable(false);
		solutionArea.setText("");
		solutionArea.setFont(new Font("monospaced", Font.PLAIN, 12));
		JScrollPane solutionPane = new JScrollPane(solutionArea);

		JTextAreaOutputStream out = new JTextAreaOutputStream (solutionArea);
        System.setOut (new PrintStream (out));
		
		solveButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent event) {
				solutionArea.setText("");
				T = new RBTree();
				T.RBInstanceReader(problemArea.getText());
			}
		});
		
		solveButton.setSize(100, 50);

		add(problemPane);
		add(solveButton);
		add(solutionPane);
	}

	public static void main(String[] args) {

		GUIApp jFrame = new GUIApp();
		jFrame.setVisible(true); 
		
	}

}
