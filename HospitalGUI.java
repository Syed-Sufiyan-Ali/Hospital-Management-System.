import javax.swing.*;
import javax.swing.table.*;
import java.awt.*;
import java.io.*;

// ===================== STYLED BUTTON (extend #3) =====================
class StyledButton extends JButton {
    StyledButton(String text, Color bg) {
        super(text);
        setBackground(bg);
        setForeground(Color.WHITE);
        setFont(new Font("Segoe UI", Font.BOLD, 13));
        setFocusPainted(false);
        setBorderPainted(false);
        setCursor(new Cursor(Cursor.HAND_CURSOR));
        setOpaque(true);
    }
}

// ===================== BASE PANEL (extend #2 base) =====================
abstract class BasePanel extends JPanel {
    protected static String[][] patients = new String[10][5];
    protected static int totalPatients = 0;
    protected static final String FILE = "patients.txt";

    BasePanel() {
        setBackground(new Color(245, 247, 250));
    }

    protected void loadPatients() {
        totalPatients = 0;
        try (BufferedReader br = new BufferedReader(new FileReader(FILE))) {
            String line;
            while ((line = br.readLine()) != null && totalPatients < 10) {
                String[] parts = line.split("\\|");
                if (parts.length == 5) patients[totalPatients++] = parts;
            }
        } catch (IOException e) { }
    }

    protected void savePatients() {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(FILE))) {
            for (int i = 0; i < totalPatients; i++) {
                bw.write(String.join("|", patients[i]));
                bw.newLine();
            }
        } catch (IOException e) {
            JOptionPane.showMessageDialog(this, "Error saving!", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    abstract void refresh();
}

// ===================== VIEW PANEL =====================
class ViewPanel extends BasePanel {
    private DefaultTableModel model;
    private JLabel status;

    ViewPanel() {
        setLayout(new BorderLayout(0, 10));
        setBorder(BorderFactory.createEmptyBorder(15, 15, 15, 15));

        JLabel heading = new JLabel("All Patients");
        heading.setFont(new Font("Segoe UI", Font.BOLD, 16));
        heading.setForeground(new Color(44, 62, 80));

        String[] cols = {"Name", "Age", "Gender", "ID", "Illness"};
        model = new DefaultTableModel(cols, 0) {
            public boolean isCellEditable(int r, int c) { return false; }
        };

        JTable table = new JTable(model);
        table.setRowHeight(30);
        table.setFont(new Font("Segoe UI", Font.PLAIN, 13));
        table.getTableHeader().setFont(new Font("Segoe UI", Font.BOLD, 13));
        table.getTableHeader().setBackground(new Color(52, 73, 94));
        table.getTableHeader().setForeground(Color.WHITE);
        table.setSelectionBackground(new Color(174, 214, 241));
        table.setGridColor(new Color(220, 220, 220));

        // Alternate row colors
        table.setDefaultRenderer(Object.class, new DefaultTableCellRenderer() {
            public Component getTableCellRendererComponent(JTable t, Object v, boolean sel, boolean foc, int row, int col) {
                super.getTableCellRendererComponent(t, v, sel, foc, row, col);
                if (!sel) setBackground(row % 2 == 0 ? Color.WHITE : new Color(235, 245, 251));
                return this;
            }
        });

        status = new JLabel("  Click refresh to load patients");
        status.setFont(new Font("Segoe UI", Font.ITALIC, 12));
        status.setForeground(new Color(100, 100, 100));

        StyledButton btnRefresh = new StyledButton("Refresh", new Color(41, 128, 185));
        btnRefresh.addActionListener(e -> refresh());

        JPanel top = new JPanel(new BorderLayout());
        top.setOpaque(false);
        top.add(heading, BorderLayout.WEST);
        top.add(btnRefresh, BorderLayout.EAST);

        add(top, BorderLayout.NORTH);
        add(new JScrollPane(table), BorderLayout.CENTER);
        add(status, BorderLayout.SOUTH);

        refresh();
    }

    public void refresh() {
        loadPatients();
        model.setRowCount(0);
        for (int i = 0; i < totalPatients; i++) model.addRow(patients[i]);
        status.setText("  Total patients: " + totalPatients);
    }
}

// ===================== ADD PANEL =====================
class AddPanel extends BasePanel {
    private JTextField fName, fAge, fGender, fId, fIllness;
    private JLabel status;

    AddPanel() {
        setLayout(new BorderLayout(0, 10));
        setBorder(BorderFactory.createEmptyBorder(15, 15, 15, 15));

        JLabel heading = new JLabel("Add New Patient");
        heading.setFont(new Font("Segoe UI", Font.BOLD, 16));
        heading.setForeground(new Color(44, 62, 80));

        JPanel form = new JPanel(new GridLayout(5, 2, 10, 12));
        form.setOpaque(false);
        form.setBorder(BorderFactory.createEmptyBorder(15, 0, 15, 100));

        fName    = new JTextField(); fAge = new JTextField();
        fGender  = new JTextField(); fId  = new JTextField();
        fIllness = new JTextField();

        Font labelFont = new Font("Segoe UI", Font.BOLD, 13);
        for (JTextField f : new JTextField[]{fName, fAge, fGender, fId, fIllness}) {
            f.setFont(new Font("Segoe UI", Font.PLAIN, 13));
            f.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createLineBorder(new Color(180, 180, 180)),
                BorderFactory.createEmptyBorder(4, 6, 4, 6)));
        }

        String[] labels = {"Name:", "Age:", "Gender (M/F):", "Patient ID:", "Illness:"};
        JTextField[] fields = {fName, fAge, fGender, fId, fIllness};
        for (int i = 0; i < labels.length; i++) {
            JLabel lbl = new JLabel(labels[i]);
            lbl.setFont(labelFont);
            form.add(lbl);
            form.add(fields[i]);
        }

        status = new JLabel(" ");
        status.setFont(new Font("Segoe UI", Font.ITALIC, 12));

        StyledButton btnAdd = new StyledButton("Add Patient", new Color(39, 174, 96));
        btnAdd.setPreferredSize(new Dimension(140, 36));
        btnAdd.addActionListener(e -> addPatient());

        StyledButton btnClear = new StyledButton("Clear", new Color(149, 165, 166));
        btnClear.setPreferredSize(new Dimension(100, 36));
        btnClear.addActionListener(e -> clearFields());

        JPanel btnRow = new JPanel(new FlowLayout(FlowLayout.LEFT, 0, 0));
        btnRow.setOpaque(false);
        btnRow.add(btnAdd);
        btnRow.add(Box.createHorizontalStrut(10));
        btnRow.add(btnClear);

        add(heading, BorderLayout.NORTH);
        add(form, BorderLayout.CENTER);

        JPanel bottom = new JPanel(new BorderLayout());
        bottom.setOpaque(false);
        bottom.add(btnRow, BorderLayout.NORTH);
        bottom.add(status, BorderLayout.SOUTH);
        add(bottom, BorderLayout.SOUTH);
    }

    private void addPatient() {
        loadPatients();
        if (totalPatients >= 10) {
            setStatus("Hospital full! Max 10 patients.", new Color(192, 57, 43));
            return;
        }
        String name = fName.getText().trim(), age = fAge.getText().trim();
        String gender = fGender.getText().trim().toUpperCase();
        String id = fId.getText().trim(), illness = fIllness.getText().trim();

        if (name.isEmpty() || age.isEmpty() || gender.isEmpty() || id.isEmpty() || illness.isEmpty()) {
            setStatus("All fields are required!", new Color(192, 57, 43)); return;
        }
        for (int i = 0; i < totalPatients; i++) {
            if (patients[i][3].equals(id)) {
                setStatus("Patient ID already exists!", new Color(192, 57, 43)); return;
            }
        }
        patients[totalPatients++] = new String[]{name, age, gender, id, illness};
        savePatients();
        setStatus("Patient added successfully!", new Color(39, 174, 96));
        clearFields();
    }

    private void clearFields() {
        fName.setText(""); fAge.setText(""); fGender.setText("");
        fId.setText(""); fIllness.setText("");
    }

    private void setStatus(String msg, Color color) {
        status.setText("  " + msg);
        status.setForeground(color);
    }

    public void refresh() { }
}

// ===================== SEARCH PANEL =====================
class SearchPanel extends BasePanel {
    private DefaultTableModel model;
    private JLabel status;

    SearchPanel() {
        setLayout(new BorderLayout(0, 10));
        setBorder(BorderFactory.createEmptyBorder(15, 15, 15, 15));

        JLabel heading = new JLabel("Search Patient");
        heading.setFont(new Font("Segoe UI", Font.BOLD, 16));
        heading.setForeground(new Color(44, 62, 80));

        JTextField fId = new JTextField();
        fId.setFont(new Font("Segoe UI", Font.PLAIN, 13));
        fId.setBorder(BorderFactory.createCompoundBorder(
            BorderFactory.createLineBorder(new Color(180,180,180)),
            BorderFactory.createEmptyBorder(4,6,4,6)));

        StyledButton btnSearch = new StyledButton("Search", new Color(41, 128, 185));

        JPanel searchBar = new JPanel(new BorderLayout(8, 0));
        searchBar.setOpaque(false);
        searchBar.setBorder(BorderFactory.createEmptyBorder(10, 0, 10, 0));
        JLabel lbl = new JLabel("Patient ID: ");
        lbl.setFont(new Font("Segoe UI", Font.BOLD, 13));
        searchBar.add(lbl, BorderLayout.WEST);
        searchBar.add(fId, BorderLayout.CENTER);
        searchBar.add(btnSearch, BorderLayout.EAST);

        String[] cols = {"Name", "Age", "Gender", "ID", "Illness"};
        model = new DefaultTableModel(cols, 0) {
            public boolean isCellEditable(int r, int c) { return false; }
        };
        JTable table = new JTable(model);
        table.setRowHeight(30);
        table.setFont(new Font("Segoe UI", Font.PLAIN, 13));
        table.getTableHeader().setFont(new Font("Segoe UI", Font.BOLD, 13));
        table.getTableHeader().setBackground(new Color(52, 73, 94));
        table.getTableHeader().setForeground(Color.WHITE);

        status = new JLabel("  Enter ID and press Search");
        status.setFont(new Font("Segoe UI", Font.ITALIC, 12));
        status.setForeground(new Color(100,100,100));

        btnSearch.addActionListener(e -> {
            String id = fId.getText().trim();
            if (id.isEmpty()) { status.setText("  Enter a Patient ID first!"); return; }
            loadPatients();
            model.setRowCount(0);
            boolean found = false;
            for (int i = 0; i < totalPatients; i++) {
                if (patients[i][3].equals(id)) { model.addRow(patients[i]); found = true; break; }
            }
            status.setText(found ? "  Patient found!" : "  No patient found with ID: " + id);
            status.setForeground(found ? new Color(39,174,96) : new Color(192,57,43));
        });

        JPanel top = new JPanel(new BorderLayout());
        top.setOpaque(false);
        top.add(heading, BorderLayout.NORTH);
        top.add(searchBar, BorderLayout.CENTER);

        add(top, BorderLayout.NORTH);
        add(new JScrollPane(table), BorderLayout.CENTER);
        add(status, BorderLayout.SOUTH);
    }

    public void refresh() { }
}

// ===================== DELETE PANEL =====================
class DeletePanel extends BasePanel {
    private JLabel status;

    DeletePanel() {
        setLayout(new BorderLayout(0, 10));
        setBorder(BorderFactory.createEmptyBorder(15, 15, 15, 15));

        JLabel heading = new JLabel("Delete Patient");
        heading.setFont(new Font("Segoe UI", Font.BOLD, 16));
        heading.setForeground(new Color(44, 62, 80));

        JTextField fId = new JTextField();
        fId.setFont(new Font("Segoe UI", Font.PLAIN, 13));
        fId.setBorder(BorderFactory.createCompoundBorder(
            BorderFactory.createLineBorder(new Color(180,180,180)),
            BorderFactory.createEmptyBorder(4,6,4,6)));

        StyledButton btnDelete = new StyledButton("Delete", new Color(192, 57, 43));

        JPanel row = new JPanel(new BorderLayout(8, 0));
        row.setOpaque(false);
        row.setBorder(BorderFactory.createEmptyBorder(20, 0, 10, 200));
        JLabel lbl = new JLabel("Patient ID: ");
        lbl.setFont(new Font("Segoe UI", Font.BOLD, 13));
        row.add(lbl, BorderLayout.WEST);
        row.add(fId, BorderLayout.CENTER);
        row.add(btnDelete, BorderLayout.EAST);

        status = new JLabel("  Enter ID to delete patient");
        status.setFont(new Font("Segoe UI", Font.ITALIC, 12));
        status.setForeground(new Color(100,100,100));

        btnDelete.addActionListener(e -> {
            String id = fId.getText().trim();
            if (id.isEmpty()) { status.setText("  Enter Patient ID first!"); return; }
            int confirm = JOptionPane.showConfirmDialog(this,
                "Are you sure you want to delete patient ID: " + id + "?",
                "Confirm Delete", JOptionPane.YES_NO_OPTION, JOptionPane.WARNING_MESSAGE);
            if (confirm != JOptionPane.YES_OPTION) return;

            loadPatients();
            boolean found = false;
            for (int i = 0; i < totalPatients; i++) {
                if (patients[i][3].equals(id)) {
                    for (int j = i; j < totalPatients - 1; j++) patients[j] = patients[j+1];
                    totalPatients--;
                    found = true;
                    break;
                }
            }
            if (found) {
                savePatients();
                status.setText("  Patient deleted successfully!");
                status.setForeground(new Color(39, 174, 96));
                fId.setText("");
            } else {
                status.setText("  No patient found with ID: " + id);
                status.setForeground(new Color(192, 57, 43));
            }
        });

        JPanel top = new JPanel(new BorderLayout());
        top.setOpaque(false);
        top.add(heading, BorderLayout.NORTH);
        top.add(row, BorderLayout.CENTER);

        add(top, BorderLayout.NORTH);
        add(status, BorderLayout.CENTER);
    }

    public void refresh() { }
}

// ===================== BILL PANEL =====================
class BillPanel extends BasePanel {
    private JLabel resultLabel;

    BillPanel() {
        setLayout(new BorderLayout(0, 10));
        setBorder(BorderFactory.createEmptyBorder(15, 15, 15, 15));

        JLabel heading = new JLabel("Generate Bill");
        heading.setFont(new Font("Segoe UI", Font.BOLD, 16));
        heading.setForeground(new Color(44, 62, 80));

        JTextField fId   = new JTextField();
        JTextField fDays = new JTextField();
        Font fieldFont = new Font("Segoe UI", Font.PLAIN, 13);
        for (JTextField f : new JTextField[]{fId, fDays}) {
            f.setFont(fieldFont);
            f.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createLineBorder(new Color(180,180,180)),
                BorderFactory.createEmptyBorder(4,6,4,6)));
        }

        JPanel form = new JPanel(new GridLayout(2, 2, 10, 12));
        form.setOpaque(false);
        form.setBorder(BorderFactory.createEmptyBorder(15, 0, 15, 200));
        Font lf = new Font("Segoe UI", Font.BOLD, 13);
        JLabel l1 = new JLabel("Patient ID:"); l1.setFont(lf);
        JLabel l2 = new JLabel("Days Admitted:"); l2.setFont(lf);
        form.add(l1); form.add(fId);
        form.add(l2); form.add(fDays);

        resultLabel = new JLabel(" ");
        resultLabel.setFont(new Font("Segoe UI", Font.BOLD, 15));
        resultLabel.setBorder(BorderFactory.createEmptyBorder(10, 0, 0, 0));

        StyledButton btnBill = new StyledButton("Generate Bill", new Color(142, 68, 173));
        btnBill.addActionListener(e -> {
            String id = fId.getText().trim(), daysStr = fDays.getText().trim();
            if (id.isEmpty() || daysStr.isEmpty()) {
                resultLabel.setText("  Fill both fields!"); resultLabel.setForeground(new Color(192,57,43)); return;
            }
            try {
                int days = Integer.parseInt(daysStr);
                loadPatients();
                String name = null;
                for (int i = 0; i < totalPatients; i++)
                    if (patients[i][3].equals(id)) { name = patients[i][0]; break; }
                if (name == null) {
                    resultLabel.setText("  Patient ID not found!");
                    resultLabel.setForeground(new Color(192,57,43)); return;
                }
                resultLabel.setText("<html><b>Patient:</b> " + name +
                    " &nbsp;|&nbsp; <b>Days:</b> " + days +
                    " &nbsp;|&nbsp; <b>Total Bill:</b> Rs. " + (days * 1000) + "</html>");
                resultLabel.setForeground(new Color(39, 174, 96));
            } catch (NumberFormatException ex) {
                resultLabel.setText("  Enter valid number for days!");
                resultLabel.setForeground(new Color(192,57,43));
            }
        });

        JPanel top = new JPanel(new BorderLayout());
        top.setOpaque(false);
        top.add(heading, BorderLayout.NORTH);
        top.add(form, BorderLayout.CENTER);

        JPanel bottom = new JPanel(new BorderLayout());
        bottom.setOpaque(false);
        bottom.add(btnBill, BorderLayout.NORTH);
        bottom.add(resultLabel, BorderLayout.CENTER);

        add(top, BorderLayout.NORTH);
        add(bottom, BorderLayout.CENTER);
    }

    public void refresh() { }
}

// ===================== MAIN APP (JFrame extend) =====================
public class HospitalGUI extends JFrame {

    HospitalGUI() {
        setTitle("Hospital Management System");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(820, 580);
        setLocationRelativeTo(null);
        setBackground(new Color(245, 247, 250));

        // ---- SIDEBAR ----
        JPanel sidebar = new JPanel();
        sidebar.setLayout(new BoxLayout(sidebar, BoxLayout.Y_AXIS));
        sidebar.setBackground(new Color(44, 62, 80));
        sidebar.setPreferredSize(new Dimension(180, 0));
        sidebar.setBorder(BorderFactory.createEmptyBorder(20, 10, 20, 10));

        JLabel appName = new JLabel("<html><center>HOSPITAL<br>SYSTEM</center></html>", SwingConstants.CENTER);
        appName.setFont(new Font("Segoe UI", Font.BOLD, 15));
        appName.setForeground(Color.WHITE);
        appName.setAlignmentX(Component.CENTER_ALIGNMENT);
        appName.setBorder(BorderFactory.createEmptyBorder(0, 0, 25, 0));

        // ---- CARD PANEL ----
        CardLayout cards = new CardLayout();
        JPanel cardPanel = new JPanel(cards);

        ViewPanel   viewPanel   = new ViewPanel();
        AddPanel    addPanel    = new AddPanel();
        SearchPanel searchPanel = new SearchPanel();
        BillPanel   billPanel   = new BillPanel();
        DeletePanel deletePanel = new DeletePanel();

        cardPanel.add(viewPanel,   "view");
        cardPanel.add(addPanel,    "add");
        cardPanel.add(searchPanel, "search");
        cardPanel.add(billPanel,   "bill");
        cardPanel.add(deletePanel, "delete");

        // Sidebar buttons
        String[][] navItems = {
            {"View Patients",  "view",   "#2980b9"},
            {"Add Patient",    "add",    "#27ae60"},
            {"Search Patient", "search", "#2980b9"},
            {"Generate Bill",  "bill",   "#8e44ad"},
            {"Delete Patient", "delete", "#c0392b"},
        };

        for (String[] item : navItems) {
            Color c = Color.decode(item[2]);
            StyledButton btn = new StyledButton(item[0], c);
            btn.setMaximumSize(new Dimension(Integer.MAX_VALUE, 40));
            btn.setAlignmentX(Component.CENTER_ALIGNMENT);
            btn.setBorder(BorderFactory.createEmptyBorder(8, 10, 8, 10));
            String key = item[1];
            btn.addActionListener(e -> { cards.show(cardPanel, key); });
            sidebar.add(btn);
            sidebar.add(Box.createVerticalStrut(8));
        }

        // Exit button at bottom
        sidebar.add(Box.createVerticalGlue());
        StyledButton btnExit = new StyledButton("Exit", new Color(80, 80, 80));
        btnExit.setMaximumSize(new Dimension(Integer.MAX_VALUE, 40));
        btnExit.setAlignmentX(Component.CENTER_ALIGNMENT);
        btnExit.addActionListener(e -> {
            int c = JOptionPane.showConfirmDialog(this, "Exit?", "Exit", JOptionPane.YES_NO_OPTION);
            if (c == JOptionPane.YES_OPTION) System.exit(0);
        });

        sidebar.add(appName);
        sidebar.add(btnExit);

        // Re-add appName at top (fix order)
        sidebar.removeAll();
        sidebar.add(appName);
        for (String[] item : navItems) {
            Color c = Color.decode(item[2]);
            StyledButton btn = new StyledButton(item[0], c);
            btn.setMaximumSize(new Dimension(Integer.MAX_VALUE, 40));
            btn.setAlignmentX(Component.CENTER_ALIGNMENT);
            btn.setBorder(BorderFactory.createEmptyBorder(8, 10, 8, 10));
            String key = item[1];
            btn.addActionListener(e -> cards.show(cardPanel, key));
            sidebar.add(btn);
            sidebar.add(Box.createVerticalStrut(8));
        }
        sidebar.add(Box.createVerticalGlue());
        sidebar.add(btnExit);

        setLayout(new BorderLayout());
        add(sidebar, BorderLayout.WEST);
        add(cardPanel, BorderLayout.CENTER);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new HospitalGUI().setVisible(true));
    }
}
