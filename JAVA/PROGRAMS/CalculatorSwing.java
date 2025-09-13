import javax.swing.*;
import java.awt.event.*;

@SuppressWarnings("unused")
public class CalculatorSwing 
{
    private static JTextField display;
    private static double[] num = new double[2];
    private static String[] operator = new String[1];

    public static void main(String[] args) 
    {
        JFrame frame = new JFrame("Calculator");
        display = createDisplay();

        @SuppressWarnings("unused")
        JButton[] numButtons = createNumberButtons(frame);
        createOperatorButtons(frame);

        // Frame settings
        frame.setSize(350, 400);
        frame.setLayout(null);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    private static JTextField createDisplay() 
    {
        JTextField t = new JTextField();
        t.setBounds(30, 40, 280, 30);
        t.setEditable(false);
        return t;
    }

    private static JButton[] createNumberButtons(JFrame frame) 
    {
        JButton[] nums = new JButton[10];
        for (int i = 0; i < 10; i++) 
        {
            nums[i] = new JButton(String.valueOf(i));
            final int index = i; // Effectively final for use in lambda
            nums[i].addActionListener(e -> display.setText(display.getText() + index));
            frame.add(nums[i]);
        }

        // Placing number buttons
        int x = 40, y = 100;
        for (int i = 1; i <= 9; i++) 
        {
            nums[i].setBounds(x, y, 50, 40);
            x += 60;
            if (i % 3 == 0) 
            {
                x = 40;
                y += 50;
            }
        }
        nums[0].setBounds(100, 300, 50, 40);
        return nums;
    }

    private static void createOperatorButtons(JFrame frame) 
    {
        JButton add = new JButton("+");
        JButton sub = new JButton("-");
        JButton multiply = new JButton("*");
        JButton divide = new JButton("/");
        JButton mod = new JButton("%");
        JButton dec = new JButton(".");
        JButton eq = new JButton("=");
        JButton clr = new JButton("C");

        add.setBounds(240, 100, 50, 40);
        sub.setBounds(240, 150, 50, 40);
        multiply.setBounds(240, 200, 50, 40);
        divide.setBounds(240, 250, 50, 40);
        mod.setBounds(240, 300, 50, 40);

        // Decimal, equals, and clear buttons
        dec.setBounds(40, 350, 50, 40);       
        // Decimal button at the bottom left
        eq.setBounds(100, 350, 100, 40);      
        // Equals button in the center bottom
        clr.setBounds(160, 40, 130, 40);      
        // Clear button on the top right, wider for better visibility


        // Adding action listeners to operator buttons
        add.addActionListener(e -> setOperator("+"));
        sub.addActionListener(e -> setOperator("-"));
        multiply.addActionListener(e -> setOperator("*"));
        divide.addActionListener(e -> setOperator("/"));
        mod.addActionListener(e -> setOperator("%"));
        eq.addActionListener(e -> calculateResult());
        clr.addActionListener(e -> display.setText(""));
        dec.addActionListener(e -> display.setText(display.getText() + "."));

        // Adding buttons to frame
        frame.add(add);
        frame.add(sub);
        frame.add(multiply);
        frame.add(divide);
        frame.add(mod);
        frame.add(dec);
        frame.add(eq);
        frame.add(clr);
        frame.add(display);
    }

    private static void setOperator(String op) 
    {
        num[0] = Double.parseDouble(display.getText());
        operator[0] = op;
        display.setText("");
    }

    private static void calculateResult() 
    {
        num[1] = Double.parseDouble(display.getText());
        double result = 0;

        switch (operator[0]) 
        {
            case "+" -> result = num[0] + num[1];
            case "-" -> result = num[0] - num[1];
            case "*" -> result = num[0] * num[1];
            case "/" -> {
                if (num[1] != 0) 
                {
                    result = num[0] / num[1];
                } else 
                {
                    JOptionPane.showMessageDialog(null, "Cannot divide by zero!", "Error", JOptionPane.ERROR_MESSAGE);
                    return;
                }
            }
            case "%" -> result = num[0] % num[1];
        }
        display.setText(String.valueOf(result));
    }
}
