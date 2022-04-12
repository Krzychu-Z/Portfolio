package brrf;

import org.springframework.jdbc.core.JdbcTemplate;

import javax.sql.DataSource;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.List;
import java.util.Map;
import java.util.logging.Level;
import java.util.logging.Logger;

public class BRRF extends Thread {
    Logger logger = Logger.getLogger(BRRF.class.getName());
    private JPanel mainApp;
    private JPanel panel1;
    private JPanel setOffJPanel;
    private JPanel destJPanel;
    private JPanel algorithmJPanel;
    private JPanel timeJPanel;
    private JPanel searchJPanel;
    private JTextField setOffTextField;
    private JTextField destTextField;
    private JComboBox algorithmComboBox;
    private JFormattedTextField timeInput;
    private JButton jedziemyButton;
    private JTextArea setOffButton;
    private JTextArea destButton;
    private JTextArea algorithmButton;
    private JTextArea timeButton;
    private JComboBox comboBox1;
    private JComboBox comboBox2;
    private String[] checkStations = {"Bielsko Biała Główna", "Katowice", "Gliwice", "Racibórz", "Kędzierzyn Koźle",
    "Oświęcim", "Kraków Główny", "Kraków Podgórze"};
    boolean firstCheck = false;
    boolean secondCheck = false;

    public BRRF() {
        mainApp.setPreferredSize(new Dimension(1280, 720));
        DateFormat df = new SimpleDateFormat("HH:mm:ss");
        timeInput = new JFormattedTextField(df);

        algorithmComboBox.addItem("Optymalny");
        algorithmComboBox.addItem("Bezpośredni");
        algorithmComboBox.addItem("Komfortowy");
        algorithmComboBox.addItem("BRRF - wymaga mocnego komputera");

        jedziemyButton.addActionListener(e -> {
            for (String each : checkStations) {
                if (each.equals(setOffTextField.getText())) {
                    firstCheck = true;
                } else if (each.equals(destTextField.getText())) {
                    secondCheck = true;
                }
            }
            if (firstCheck && secondCheck){
                Results viewPanel = new Results(setOffTextField.getText(), destTextField.getText(), algorithmComboBox.getSelectedItem().toString(),
                        comboBox1.getSelectedItem().toString(), comboBox2.getSelectedItem().toString());

                JFrame frame = new JFrame("BRRF v1.0");
                frame.setContentPane(viewPanel.getResultsApp());
                frame.pack();
                frame.setVisible(true);
            } else {
                setOffTextField.setText("");
                destTextField.setText("");
            }
        });
    }

    public JComboBox getComboBox1() {
        return comboBox1;
    }

    public JComboBox getComboBox2() {
        return comboBox2;
    }

    public static void main(String[] args) {
        BRRF app = new BRRF();
        app.start();

        JFrame frame = new JFrame("BRRF v1.0");
        frame.setContentPane(app.mainApp);
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }
}
