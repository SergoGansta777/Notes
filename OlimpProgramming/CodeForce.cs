using System;
using System.Collections.Generic;
using System.Linq;
using System.Diagnostics;
using System.Security;

namespace OlimpTest
{
    internal class Program
    {
        static bool Function(List<long[]> coordinates,double r)
        {
            double m1 = -1 * Math.Pow(10, 8);
            double m2 = Math.Pow(10, 8);
            foreach (var item in coordinates)
            {
                double delta = Math.Abs(r - Math.Abs(item[1]));
                if (delta > r) return false;
                double h = Math.Sqrt(Math.Pow(r, 2) - Math.Pow(delta, 2));
                double x1 = Math.Abs(item[0]) - h;
                double x2 = Math.Abs(item[0]) + h;
                m1 = Math.Max(m1, x1);
                m2 = Math.Min(m2, x2);
                if (m1 > m2) return false;
            }
            return true;
        }

        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            List<long[]> coordinates = new List<long[]>();
            
            for (int i = 0; i < n; i++)
            {
                coordinates.Add(Array.ConvertAll(Console.ReadLine().Trim().Split(), long.Parse));
            }

            long count = coordinates.Where(x => x[1] <= 0).Count();
            double r1 = -1*Math.Pow(10, 15);
            double r2 = Math.Pow(10, 15);
            bool isExist = false;
            int i1 = 0;
            while (i1<200)
            {
                double c = (r1 + r2) / 2;
                if (Function(coordinates, c))
                {
                    r2 = c;
                    isExist = true;
                }
                else
                {
                    r1 = c;
                }

                i1++;
            }
            if (isExist && (count==coordinates.Count() || count==0))
            {
                Console.WriteLine(r2);
            }
            else
            {
                Console.WriteLine(-1);
            }
}
}
}
