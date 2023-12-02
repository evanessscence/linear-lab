/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.uam.calc;

/**
 *
 * @author a n n a
 */
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.awt.Desktop;
import java.io.File;
/**
 *
 * @author a n n a
 */
public class Archivos {
    
    public static void guardarArchivo(String textoAGuardar, String nombreArchivo) {
        try {
            // Obtener la ruta absoluta de la carpeta de recursos
            ClassLoader classLoader = Archivos.class.getClassLoader();
            String rutaRecursos = classLoader.getResource("").getPath();

            // Concatenar la ruta de la carpeta de recursos con el nombre del archivo
            String rutaCompleta = "C:\\Users\\a n n a\\Documents\\UAM\\SISTEMAS\\SEMESTRE IV\\Calculadora\\calc\\" + nombreArchivo;

            // Crear el archivo y escribir el texto
            BufferedWriter writer = new BufferedWriter(new FileWriter(rutaCompleta));
            writer.write(textoAGuardar);
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    
    public static void ejecutarArchivo(String rutaDelArchivo) {
        try {
            // Obtener la ruta absoluta de la carpeta de recursos
            ClassLoader classLoader = Archivos.class.getClassLoader();
            String rutaRecursos = classLoader.getResource("").getPath();

            // Concatenar la ruta de la carpeta de recursos con la ruta del archivo
            String rutaCompleta = "C:\\Users\\a n n a\\Documents\\UAM\\SISTEMAS\\SEMESTRE IV\\Calculadora\\calc\\" + rutaDelArchivo;

            // Crear un objeto File y abrirlo con el programa predeterminado
            File archivo = new File(rutaCompleta);
            Desktop.getDesktop().open(archivo);
        } catch (IOException e) {
            e.printStackTrace();
            System.err.println("Error al abrir el archivo: " + rutaDelArchivo);
        }
    }
}
    
