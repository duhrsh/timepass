import javax.swing.*;
import java.awt.*;

public class PopupExample {

    public static void main(String[] args) {
        // Create a new JFrame
        JFrame frame = new JFrame("Popup Example");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);
        frame.setLocationRelativeTo(null); // Center the window

        // Create a JPanel with a layout
        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());

        // Create a title label
        JLabel titleLabel = new JLabel("Welcome to Popup Example", SwingConstants.CENTER);
        titleLabel.setFont(new Font("Arial", Font.BOLD, 20));
        titleLabel.setForeground(Color.BLUE);

        // Create a JButton
        JButton button = new JButton("Click Me!");
        button.setFont(new Font("Arial", Font.PLAIN, 16));
        button.setBackground(Color.GREEN);
        button.setForeground(Color.WHITE);
        button.setFocusPainted(false); // Remove the focus border
        button.setBorder(BorderFactory.createRaisedBevelBorder()); // Raised border effect

        // Add action listener to the button
        button.addActionListener(e -> {
            // Show a popup message
            JOptionPane.showMessageDialog(frame, "Hello, this is a styled popup!", "Popup", JOptionPane.INFORMATION_MESSAGE);
        });

        // Add components to the panel
        panel.add(titleLabel, BorderLayout.NORTH);
        panel.add(button, BorderLayout.CENTER);

        // Set background color for the panel
        panel.setBackground(Color.LIGHT_GRAY);

        // Add the panel to the frame
        frame.add(panel);

        // Set frame visibility
        frame.setVisible(true);
    }
}
