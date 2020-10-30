import javax.swing.*;
import java.awt.*;

public class BorderLayoutEx extends JFrame {
	public BorderLayoutEx() {
		setTitle("Open Challenge 9");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new BorderLayout());
		JPanel pn = new JPanel() {
			@Override
			public Dimension getPreferredSize() {
				return new Dimension(300, 40);
			};
		};
		pn.setLayout(new FlowLayout());
		pn.setBackground(Color.GRAY);
		
		pn.add(new JButton("Open"));
		pn.add(new JButton("Read"));
		pn.add(new JButton("Close"));
		c.add(pn, BorderLayout.NORTH);

		setSize(300, 300);
		setVisible(true);
		
		JPanel pd = new JPanel() {
			@Override
			public Dimension getPreferredSize() {
				return new Dimension(300, 40);
			};
		};
		pd.setLayout(null);
		JLabel hello = new JLabel("Hello");
		hello.setLocation(120, 100);
		hello.setSize(300, 30);
		pd.add(hello, BorderLayout.CENTER);
		JLabel java = new JLabel("java");
		java.setLocation(30, 180);
		java.setSize(300, 30);
		pd.add(java, BorderLayout.CENTER);
		JLabel love = new JLabel("Love");
		love.setLocation(130, 50);
		love.setSize(300, 30);
		pd.add(love, BorderLayout.CENTER);
		c.add(pd);
		
		setSize(300, 300);
		setVisible(true);
	}
	public static void main(String [] args) {
		new BorderLayoutEx();
	}
}
