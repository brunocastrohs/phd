package app;
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

import gui.JTextAreaOutputStream;
import solver.Simplex;

public class App extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 4115273481157888542L;
	JMenu fileMenu = new JMenu("Arquivo");
	JMenu solveMenu = new JMenu("Solver");
	JMenu helpMenu = new JMenu("Ajuda");
	JMenuItem newAction = new JMenuItem("Novo");
	JMenuItem openAction = new JMenuItem("Abrir");
	JMenuItem solveAction = new JMenuItem("Solve");
	JMenuItem debugAction = new JMenuItem("Debug");
	JMenuItem exitAction = new JMenuItem("Sair");
	JMenuItem aboutAction = new JMenuItem("Sobre");
	JMenuItem sintaxAction = new JMenuItem("Limitações e Sintaxe");
	int[] textAreaMeasures = { 30, 60 };
	final JTextArea problemArea = new JTextArea(textAreaMeasures[0], textAreaMeasures[1]);
	final JTextArea solutionArea = new JTextArea(textAreaMeasures[0], textAreaMeasures[1]);
	JButton insertButton = new JButton("Solve >>");
	
	public App() {

		/************ WINDOW ***************/
		configureWindow();

		/************ MENU ***************/

		configureMenu();

		/************ TEXT AREA ***************/

		configureCenterPanel();

	}

	public void configureWindow() {
		URL url = App.class.getResource("favicon.png");
		setIconImage(new ImageIcon(url).getImage());
		setTitle("S2F Solver");
		setSize(1000, 600);
		setLocationRelativeTo(null);
		setLayout(new FlowLayout());
		setDefaultCloseOperation(EXIT_ON_CLOSE);
	}

	public void configureMenu() {

		JMenuBar menuBar = new JMenuBar();

		setJMenuBar(menuBar);

		menuBar.add(fileMenu);
		menuBar.add(solveMenu);
		menuBar.add(helpMenu);

		newAction.setIcon(new ImageIcon(App.class.getResource("new.png")));
		openAction.setIcon(new ImageIcon(App.class.getResource("open.png")));
		solveAction.setIcon(new ImageIcon(App.class.getResource("solve.png")));
		debugAction.setIcon(new ImageIcon(App.class.getResource("debug.png")));
		exitAction.setIcon(new ImageIcon(App.class.getResource("exit.png")));
		aboutAction.setIcon(new ImageIcon(App.class.getResource("help.png")));
		sintaxAction.setIcon(new ImageIcon(App.class.getResource("help.png")));

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
		
		solveAction.addActionListener( new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
            	solutionArea.setText("");
				new Simplex(problemArea.getText()).run();                
				}
        });
		
		debugAction.addActionListener( new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
            	solutionArea.setText("");
				new Simplex(problemArea.getText(),true).run();                
				}
        });
		
		/*
		 
		  public void actionPerformed(ActionEvent event) {
				solutionArea.setText("");
				new Simplex(problemArea.getText()).run();
        		//solutionArea.setText(sol);
			}
		 
		 * */
		
		sintaxAction.addActionListener( new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
            	 final ImageIcon icon = new ImageIcon(App.class.getResource("message.png"));
            	 String msg = "Eis as restrições e limitações de uso deste solver:\n"
            			+ "- Não usar letras maiúsculas;\n"
            			+ "- Usar as palavras max ou min para designar o tipo do problema;\n" 
    					+ "- A variável de decisão deve ser denotada somente por x;\n"
    					+ "- O índice da variável de decisão deve iniciar em 1;\n"
    					+ "- Toda restrição deve ser do tipo de >=, <= ou =;\n" 
    					+ "- Não devem existir constantes na função objetivo;\n"
    					+ "- A função objetivo deve ser toda ela especificada na primeira linha;\n"
    					+ "- Não são suportadas variáveis duplamente indexadas e os operadores de multiplicação(*) e divisão(/).\n";
                 JOptionPane.showMessageDialog(null, msg, "AJUDA", JOptionPane.INFORMATION_MESSAGE, icon);
                }
        });
		
		aboutAction.addActionListener( new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
            	 final ImageIcon icon = new ImageIcon(App.class.getResource("message.png"));
            	 String msg = 
            			 "Este sistema foi desenvolvido como requisito para"
            	 		+ "\n para obter a segunda dentre as três notas"
            	 		+ "\n de avalição inerentes a disciplina de Programação Linear "
            	 		+ "\n ministrada pelo professor Marco Goldbarg junto ao  PPgSC/UFRN."
            	 		+ "\n É proibido o uso desta aplicação para fins comerciais."
            	 		+ "\nAutor: Bruno de Castro H. Silva."
            	 		+ "\nContato: bruno@crateus.ufc.br.";
                 JOptionPane.showMessageDialog(null, msg, "AJUDA", JOptionPane.INFORMATION_MESSAGE, icon);


                }
        });
		
		fileMenu.add(newAction);
		fileMenu.add(openAction);
		fileMenu.addSeparator();
		fileMenu.add(exitAction);
		solveMenu.add(solveAction);
		solveMenu.add(debugAction);
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

		problemArea.setText(" max 5x1 + 3.5x2\n" + " st\n" + "  x1 <= 150\n" + "  x2 >= 300\n" + "  1.5x1 + x2 = 400");
		JScrollPane problemPane = new JScrollPane(problemArea);
		problemArea.setFont(new Font("monospaced", Font.PLAIN, 12));
		
		solutionArea.setEditable(false);
		solutionArea.setText("");
		solutionArea.setFont(new Font("monospaced", Font.PLAIN, 12));
		JScrollPane solutionPane = new JScrollPane(solutionArea);

		JTextAreaOutputStream out = new JTextAreaOutputStream (solutionArea);
        System.setOut (new PrintStream (out));
		
		insertButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent event) {
				solutionArea.setText("");
				new Simplex(problemArea.getText()).run();
        		//solutionArea.setText(sol);
			}
		});
		
		insertButton.setSize(100, 50);

		add(problemPane);
		add(insertButton);
		add(solutionPane);
	}

	public static void main(String[] args) {

		App jFrame = new App();
		jFrame.setVisible(true); 
		
	}

}
