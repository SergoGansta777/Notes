﻿using System;

namespace Practice
{
    class Program
    {
        static void Main()
        {
            //Задание2, варинат 20
            Console.WriteLine("Введите значение X, причем |X| < 1: ");
            double x = double.Parse(Console.ReadLine());
            Console.WriteLine("Введите точность вычисления arcsin: ");
            double eps = double.Parse(Console.ReadLine());
            double iterOutput = IteractivAlg(x, eps);
            Console.WriteLine("Итеративный алгоритм: " + iterOutput  + " радиан или примерно " + iterOutput*(180/3.14159)+ " градусов");
            double recurOutput = RecursiveAlg(x, eps, 1 ) + x ;
            Console.WriteLine("Рекурсивный алгоритм: " + recurOutput  + " радиан или примерно " + recurOutput*(180/3.14159)+ " градусов");


        }

        static double RecursiveAlg(double x, double eps, int  n)
        {
            
            double newTerm = (Factorial(2 * n) * Math.Pow(x, 2 * n + 1)) /
                             (Math.Pow(4, n) * Math.Pow(Factorial(n), 2) * (2 * n + 1));
            if (Math.Abs(newTerm) <= eps)
            {
                return 0;
            }

            return newTerm + RecursiveAlg(x, eps, n + 1);
        }
        static double IteractivAlg(double x, double eps)
        {
            double arcsin = x;
            for (int n = 1; true; n++)
            {
                double newTerm = (Factorial(2 * n) * Math.Pow(x, 2 * n + 1)) /
                                  (Math.Pow(4, n) * Math.Pow(Factorial(n), 2) * (2 * n + 1));
                if (Math.Abs(newTerm) <= eps) 
                {
                    break;
                }
                arcsin += newTerm;
            }

            return arcsin;
        }
        static public long  Factorial(int n)
        {
            long factorial = 1;
            for (int i = 1; i <= n; i++)
                factorial *= i;

            return factorial;
        }

    }
}