
package com.uam.calc;

import java.awt.Color;
import java.io.IOException;

/**
 *
 * @author a n n a
 */
public class Opciones extends javax.swing.JFrame {

    /**
     * Creates new form Opciones
     */
    public Opciones() {
        initComponents();
    }

    public static void abrirResultado()
    {
       try {
    Thread.sleep(100); 
} catch (InterruptedException e) {
    // Manejo de excepciones
}
        java.awt.EventQueue.invokeLater(new Runnable() {
         public void run() {
           new Resultado().setVisible(true);
         }
        });
    }
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel2 = new javax.swing.JPanel();
        jLabel2 = new javax.swing.JLabel();
        jPanel1 = new javax.swing.JPanel();
        Determinante = new javax.swing.JButton();
        TSA = new javax.swing.JButton();
        Identidad = new javax.swing.JButton();
        Inversa = new javax.swing.JButton();
        Transpuesta = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setBackground(new java.awt.Color(255, 255, 255));

        jPanel2.setBackground(new java.awt.Color(255, 255, 255));

        jLabel2.setFont(new java.awt.Font("SF Pro Display", 1, 24)); // NOI18N
        jLabel2.setForeground(new java.awt.Color(0, 102, 102));
        jLabel2.setText("Operaciones");

        jPanel1.setBackground(new java.awt.Color(255, 255, 255));

        Determinante.setFont(new java.awt.Font("Inter Medium", 0, 12)); // NOI18N
        Determinante.setForeground(new java.awt.Color(102, 102, 102));
        Determinante.setIcon(new javax.swing.ImageIcon("C:\\Users\\a n n a\\Documents\\UAM\\SISTEMAS\\SEMESTRE IV\\Calculadora\\calc\\ICONOS\\IMG_1448.PNG")); // NOI18N
        Determinante.setText("   Determinante");
        Determinante.setBorder(null);
        Determinante.setBorderPainted(false);
        Determinante.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        Determinante.setDefaultCapable(false);
        Determinante.setHorizontalAlignment(javax.swing.SwingConstants.LEFT);
        Determinante.setOpaque(true);
        Determinante.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                DeterminanteFocusGained(evt);
            }
        });
        Determinante.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mousePressed(java.awt.event.MouseEvent evt) {
                DeterminanteMousePressed(evt);
            }
        });
        Determinante.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                DeterminanteActionPerformed(evt);
            }
        });

        TSA.setFont(new java.awt.Font("Inter Medium", 0, 12)); // NOI18N
        TSA.setForeground(new java.awt.Color(102, 102, 102));
        TSA.setIcon(new javax.swing.ImageIcon("C:\\Users\\a n n a\\Documents\\UAM\\SISTEMAS\\SEMESTRE IV\\Calculadora\\calc\\ICONOS\\IMG_1450.PNG")); // NOI18N
        TSA.setText("   Triangular Superior");
        TSA.setBorder(null);
        TSA.setDefaultCapable(false);
        TSA.setHorizontalAlignment(javax.swing.SwingConstants.LEFT);
        TSA.setOpaque(true);
        TSA.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                TSAFocusGained(evt);
            }
        });
        TSA.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                TSAMouseClicked(evt);
            }
        });
        TSA.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                TSAActionPerformed(evt);
            }
        });

        Identidad.setFont(new java.awt.Font("Inter Medium", 0, 12)); // NOI18N
        Identidad.setForeground(new java.awt.Color(102, 102, 102));
        Identidad.setIcon(new javax.swing.ImageIcon("C:\\Users\\a n n a\\Documents\\UAM\\SISTEMAS\\SEMESTRE IV\\Calculadora\\calc\\ICONOS\\IMG_1449.PNG")); // NOI18N
        Identidad.setText("   Matriz Identidad");
        Identidad.setBorder(null);
        Identidad.setDefaultCapable(false);
        Identidad.setHorizontalAlignment(javax.swing.SwingConstants.LEFT);
        Identidad.setOpaque(true);
        Identidad.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                IdentidadFocusGained(evt);
            }
        });
        Identidad.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mousePressed(java.awt.event.MouseEvent evt) {
                IdentidadMousePressed(evt);
            }
        });
        Identidad.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                IdentidadActionPerformed(evt);
            }
        });

        Inversa.setFont(new java.awt.Font("Inter Medium", 0, 12)); // NOI18N
        Inversa.setForeground(new java.awt.Color(102, 102, 102));
        Inversa.setIcon(new javax.swing.ImageIcon("C:\\Users\\a n n a\\Documents\\UAM\\SISTEMAS\\SEMESTRE IV\\Calculadora\\calc\\ICONOS\\IMG_1451.PNG")); // NOI18N
        Inversa.setText("   Inversa");
        Inversa.setBorder(null);
        Inversa.setBorderPainted(false);
        Inversa.setDefaultCapable(false);
        Inversa.setHorizontalAlignment(javax.swing.SwingConstants.LEFT);
        Inversa.setOpaque(true);
        Inversa.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                InversaFocusGained(evt);
            }
        });
        Inversa.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mousePressed(java.awt.event.MouseEvent evt) {
                InversaMousePressed(evt);
            }
        });
        Inversa.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                InversaActionPerformed(evt);
            }
        });

        Transpuesta.setFont(new java.awt.Font("Inter Medium", 0, 12)); // NOI18N
        Transpuesta.setForeground(new java.awt.Color(102, 102, 102));
        Transpuesta.setIcon(new javax.swing.ImageIcon("C:\\Users\\a n n a\\Documents\\UAM\\SISTEMAS\\SEMESTRE IV\\Calculadora\\calc\\ICONOS\\IMG_1452.PNG")); // NOI18N
        Transpuesta.setText("   Transpuesta");
        Transpuesta.setBorder(null);
        Transpuesta.setBorderPainted(false);
        Transpuesta.setDefaultCapable(false);
        Transpuesta.setHorizontalAlignment(javax.swing.SwingConstants.LEFT);
        Transpuesta.setOpaque(true);
        Transpuesta.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                TranspuestaFocusGained(evt);
            }
        });
        Transpuesta.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                TranspuestaMouseClicked(evt);
            }
        });
        Transpuesta.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                TranspuestaActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(14, 14, 14)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(Transpuesta, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(Inversa, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(Identidad, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(TSA, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(Determinante, javax.swing.GroupLayout.PREFERRED_SIZE, 246, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(10, Short.MAX_VALUE))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(15, 15, 15)
                .addComponent(Determinante, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(TSA, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(Identidad, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(Inversa, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(Transpuesta, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(17, Short.MAX_VALUE))
        );

        jLabel1.setFont(new java.awt.Font("Inter Medium", 0, 10)); // NOI18N
        jLabel1.setForeground(new java.awt.Color(153, 153, 153));
        jLabel1.setText("Elige una de las operaciones matriciales");

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addGap(15, 15, 15)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel1)
                    .addComponent(jLabel2))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                .addGap(26, 26, 26)
                .addComponent(jLabel2)
                .addGap(2, 2, 2)
                .addComponent(jLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(0, 0, 0)
                .addComponent(jPanel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void TranspuestaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_TranspuestaActionPerformed
        Archivos.ejecutarArchivo("transpuesta.exe");
        abrirResultado();
    }//GEN-LAST:event_TranspuestaActionPerformed

    private void InversaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_InversaActionPerformed
        Archivos.ejecutarArchivo("Inversa.exe");
        abrirResultado();
    }//GEN-LAST:event_InversaActionPerformed

    private void IdentidadActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_IdentidadActionPerformed
        Archivos.ejecutarArchivo("RREF.exe");
        abrirResultado();
    }//GEN-LAST:event_IdentidadActionPerformed

    private void TSAActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_TSAActionPerformed
        Archivos.ejecutarArchivo("TSA.exe");
        abrirResultado();
    }//GEN-LAST:event_TSAActionPerformed

    private void DeterminanteActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_DeterminanteActionPerformed
        Archivos.ejecutarArchivo("determinante.exe");
        abrirResultado();
    }//GEN-LAST:event_DeterminanteActionPerformed

    private void DeterminanteMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_DeterminanteMousePressed
        Determinante.setBackground(Color.GRAY);        // TODO add your handling code here:
    }//GEN-LAST:event_DeterminanteMousePressed

    private void DeterminanteFocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_DeterminanteFocusGained
    Determinante.setBackground(Color.GRAY);        // TODO add your handling code here:
    }//GEN-LAST:event_DeterminanteFocusGained

    private void TSAFocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_TSAFocusGained
TSA.setBackground(Color.GRAY);        // TODO add your handling code here:
    }//GEN-LAST:event_TSAFocusGained

    private void TSAMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_TSAMouseClicked
TSA.setBackground(Color.GRAY);        // TODO add your handling code here:
    }//GEN-LAST:event_TSAMouseClicked

    private void IdentidadFocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_IdentidadFocusGained
    Identidad.setBackground(Color.GRAY);        // TODO add your handling code here:
    }//GEN-LAST:event_IdentidadFocusGained

    private void IdentidadMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_IdentidadMousePressed
    Identidad.setBackground(Color.GRAY);        // TODO add your handling code here:
    }//GEN-LAST:event_IdentidadMousePressed

    private void InversaFocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_InversaFocusGained
    Inversa.setBackground(Color.GRAY);        // TODO add your handling code here:
    }//GEN-LAST:event_InversaFocusGained

    private void InversaMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_InversaMousePressed
     Inversa.setBackground(Color.GRAY);    // TODO add your handling code here:
    }//GEN-LAST:event_InversaMousePressed

    private void TranspuestaFocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_TranspuestaFocusGained
    Transpuesta.setBackground(Color.GRAY);         // TODO add your handling code here:
    }//GEN-LAST:event_TranspuestaFocusGained

    private void TranspuestaMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_TranspuestaMouseClicked
    Transpuesta.setBackground(Color.GRAY);  // TODO add your handling code here:
    }//GEN-LAST:event_TranspuestaMouseClicked

    
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Opciones.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Opciones.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Opciones.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Opciones.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Opciones().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton Determinante;
    private javax.swing.JButton Identidad;
    private javax.swing.JButton Inversa;
    private javax.swing.JButton TSA;
    private javax.swing.JButton Transpuesta;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    // End of variables declaration//GEN-END:variables
}
