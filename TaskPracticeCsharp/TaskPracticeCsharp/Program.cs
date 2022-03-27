using System;

namespace Practice
{
    class Program
    {
        static void Main()
        {
            //Номер 1,варинат 23
            Console.WriteLine("Введите N: ");
            int N = int.Parse(Console.ReadLine());
            for (int i = 0; i < N; i++)
            {
                int number = int.Parse(Console.ReadLine());
                ProcedureTask((number));
                Console.Write("Работа функции: ");
                int function = FunctionTask(number);
                if (function == 0)
                {
                    Console.WriteLine("Число не простое");
                }
                else
                {
                    Console.WriteLine($"Сумма цифр числа равна " + function);
                }
                
            }

        }

        public static int FunctionTask(int number)
        {
            if (!IsPrime(number)) return 0;
            int sum = 0;
            while (number != 0)
            {

                sum += number % 10;
                number /= 10;
            }

            return sum;

        }
        public static void ProcedureTask(int number)
        {
            Console.Write("Результат работы процедуры: ");
            int output = number;
            if (IsPrime(number))
            {
                
                int sum = 0;
                while (number != 0)
                {

                    sum += number % 10;
                    number /= 10;
                }

                Console.WriteLine($"{output} -  простое число, сумма цифр равна {sum}");
            }
            else
            {
                Console.WriteLine($"{output} - не простое число.");
            }
        }
        public static bool IsPrime(int n)
        {
            if (n<=1) return false;
            for (int i = 2; i <= 11; i++)
            {
                if ((i != n && n % i == 0) || n % Math.Sqrt(n) == 0) return false;
            }

            return true;
        }
    }
}