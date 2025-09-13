import javax.swing.*;
import java.awt.event.*;

public class ButtonExample 
{
  public static void main(String[] args) 
  {
    JFrame f=new JFrame("Button Click Example");
    JButton b=new JButton("Click me!");

    b.setBounds(100,100,50,100);

    b.addActionListener(new ActionListener() 
    {
      public void actionPerformed(ActionEvent e)
      {
        System.out.println("Button Clicked");
      }
    });

    f.add(b);
    f.setSize(300,300);
    f.setVisible(true);
    f.setLayout(null);
    f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
  }
}
