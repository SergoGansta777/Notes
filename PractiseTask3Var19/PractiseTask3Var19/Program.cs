using System;
using System.Collections.Generic;

namespace Practise
{
    class Program
    {
        static void Main()
        {
            //Задание 3, Вариант 19
            List<string[]> list = new List<string[]>();
            var source = File.ReadAllLines(
                "/home/SergoGansta777/Документы/Ознакомительная/Ознакомительная практика, задание 3.txt");
            foreach (var line in source)
            {
                list.Add(line.TrimEnd(';').Split(", "));
            }
            //ShakerSort
            int left = 1, right = list.Count() - 1;
            bool IsSorted = false;
            while ((left < right) && !IsSorted)
            {
                IsSorted = true;
                for (int i = left; i < right; i++)
                {
                    if (int.Parse(list[i][5]) < int.Parse(list[i+1][5]))
                    {
                        var help = list[i];
                        list[i] = list[i + 1];
                        list[i + 1] = help;
                        IsSorted = false;
                    }
                }

                right--;
                for (int i = right; i > left; i--)
                {
                    if (int.Parse(list[i][5]) > int.Parse(list[i-1][5]))
                    {
                        var help = list[i];
                        list[i] = list[i - 1];
                        list[i - 1] = help;
                        IsSorted = false;
                    }
                }

                left++;

            }

            int MaxLengthOfString = list[0][3].Length;
            
            foreach (var item in list)
            {
                for (int i = 0; i < 6; i++)
                {
                    int count = 0;
                    while (count <= MaxLengthOfString - item[i].Length)
                    {
                        Console.Write(" ");
                        count++;
                    }

                    Console.Write(item[i] + " ");
                }

                Console.WriteLine();
            }

        }
    }
}