import javax.swing.*;  
import java.awt.event.*;  

public class MouseExample {  
    public static void main(String[] args) {  
        JFrame frame = new JFrame("Mouse Click Example");  
        JLabel label = new JLabel("Click me");  

        label.setBounds(100, 100, 100, 50); // Setting label position and size

        // Adding MouseListener to the label
        label.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                System.out.println("Label clicked at X: " + e.getX() + ", Y: " + e.getY());
            }
        });
        
        frame.add(label); // Adding label to the JFrame
        frame.setSize(300, 300);  
        frame.setLayout(null);  
        frame.setVisible(true);  
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
    }  
}
