using System;
using System.Linq;
using System.Collections.Generic;

namespace IdontKnow
{
    class Program
    {
        static void Main()
        {
            int seconds = int.Parse(Console.ReadLine());
            int secondsHuman = seconds % 60;
            seconds /= 60;
            int minutesHuman = seconds % 60;
            int hoursHuman = seconds / 60;
            string result = String.Concat(hoursHuman.ToString().PadLeft(2,'0'), ":", minutesHuman.ToString().PadLeft(2,'0'), ":",secondsHuman.ToString().PadLeft(2,'0'));
            Console.WriteLine(result);
        }
        static void Main1()
        {
            int lenght = int.Parse(Console.ReadLine());
            Console.WriteLine($"Вывод циклического массива длиной {lenght}");
            int lengthOfLine = Convert.ToInt32(Math.Sqrt(lenght));
            int[,] neededArr = new int[lengthOfLine, lengthOfLine];
            int upRight = lengthOfLine - 1;
            int downRight = lengthOfLine - 1;
            int upLeft = 1;
            int downLeft = 0;
            int x = 0, y = 0;
            int element = 1;
            bool onTheRight = true, onTheLeft = true;
            while (element <= lenght)
            {
                while (x < upRight && element<=lenght)
                {
                    neededArr[x, y] = element;
                    element++;
                    x++;
                }
                upRight--;
                while (y < downRight && element<=lenght)
                {
                    neededArr[x, y] = element;
                    element++;
                    y++;
                }
                downRight--;
                while (x > downLeft && element <= lenght)
                {
                    neededArr[x, y] = element;
                    element++;
                    x--;
                }
                downLeft++;
                while (y > upLeft && element <= lenght)
                {
                    neededArr[x, y] = element;
                    y--;
                    element++;
                }
                upLeft++;
            }

            for (int i = 0; i < lengthOfLine; i++)
            {
                for (int j = 0; j < lengthOfLine; j++)
                {
                    Console.Write(neededArr[j,i]+" ");
                }
                Console.WriteLine();
            }
        }
    }
}
