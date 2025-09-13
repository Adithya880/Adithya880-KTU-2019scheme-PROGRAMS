import javax.swing.*;  
import java.awt.event.*;  

public class KeyExample {  
    public static void main(String[] args) {  
        JFrame frame = new JFrame("Key Press Example");  
        JTextField textField = new JTextField();  
        
        textField.setBounds(50, 50, 200, 30); // Setting text field position and size
        
        // Adding KeyListener to the text field
        textField.addKeyListener(new KeyListener() {
            public void keyPressed(KeyEvent e) {
                System.out.println("Key Pressed: " + e.getKeyChar());
            }
            public void keyReleased(KeyEvent e) {}
            public void keyTyped(KeyEvent e) {}
        });
        
        frame.add(textField); // Adding text field to the JFrame
        frame.setSize(300, 200);  
        frame.setLayout(null);  
        frame.setVisible(true);  
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
    }  
}
