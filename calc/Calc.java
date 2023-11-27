/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.uam.calc;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import com.formdev.flatlaf.FlatLightLaf;
/**
 *
 * @author a n n a
 */
public class Calc {
    public static void main(String[] args) {
  try {
            UIManager.setLookAndFeel(new FlatLightLaf());
        } catch (UnsupportedLookAndFeelException e) {
            e.printStackTrace();
        }
       
      java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new splashArt().setVisible(true);
            }
        });
    }
}
