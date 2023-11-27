/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.uam.calc;


import org.apache.commons.math3.analysis.UnivariateFunction;
import net.objecthunter.exp4j.Expression;
import net.objecthunter.exp4j.ExpressionBuilder;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartFrame;
import org.jfree.chart.JFreeChart;
import org.jfree.data.xy.DefaultXYDataset;

public class Grafico {
     static void graficar(String funcion) {
        // Crear los datos de la función
        DefaultXYDataset dataset = new DefaultXYDataset();
        double[][] data = generarDatosFuncion(funcion);
        dataset.addSeries(funcion, data);

        // Crear el gráfico
        JFreeChart chart = ChartFactory.createXYLineChart(
                "Gráfico de la función", // Título del gráfico
                "x", // Etiqueta del eje x
                "f(x)", // Etiqueta del eje y
                dataset // Datos del gráfico
        );

        // Mostrar el gráfico en una ventana
        ChartFrame frame = new ChartFrame("Gráfico", chart);
        frame.pack();
        frame.setVisible(true);
    }

    // Generar los datos de la función ingresada
 private static double[][] generarDatosFuncion(String funcion) {
    int n = 100; // Número de puntos en el gráfico
    double[][] data = new double[2][n];

    Expression expression = new ExpressionBuilder(funcion)
                                .variables("x")
                                .build();

    UnivariateFunction f = new UnivariateFunction() {
        @Override
        public double value(double x) {
            expression.setVariable("x", x);
            return expression.evaluate();
        }
    };

    for (int i = 0; i < n; i++) {
        double x = i - (n / 2);
        double y = f.value(x);
        data[0][i] = x;
        data[1][i] = y;
    }

    return data;
}}
