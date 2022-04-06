#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N, M, helpMax , resultIn, resultSum;
    string resultPath="";
    cout << "Составление плана сокровищницы... " << endl;
    cout << "Введите количество комнат вдоль восточной стены(колчество строчек в таблице): ";
    cin >> N;
    cout << "Введите количество комнат вдоль северной стены(колчество столбцов в таблице): ";
    cin >> M;
    cout << "Заполнение плана ценностью сокровищ: ";
    int plane[N][M+2];
    for(int i = 0; i < N; i++) //Заполнение массива
    { 
        if(i>0)cout<< "Новая строчка:";
        for(int j = 1; j < M+1; j++)
        {
            cin >> plane[i][j];
        }
        
    }
    for(int i=0; i<N;i++) //Добавление границ в виде нулей
    {
        plane[i][0]=0;
        plane[i][M+1]=0;
    }
    cout << "Готово." << " Полученный план: " <<endl; //Вывод карты для просмотра плана
    for(int i = 0; i < N; i++)
    {
        for(int j = 1; j < M+1; j++)
        {
           cout << plane[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Поиск оптимального пути..." << endl; //Подсчет возможных значений
    for(int i=N-2; i>=0;i--)
    {
        for(int j = 1; j <= M; j++)
        {
            helpMax=max(plane[i][j] + plane[i+1][j-1], plane[i][j] + plane[i+1][j]);
            plane[i][j]=max(helpMax, plane[i][j]+plane[i+1][j+1]);
        }
    }
    
    resultSum = plane[0][1];
    resultIn = 1;
    for(int j = 2; j < M+1; j++)//Определение значения максимально благоприятного исхода и номер первой комнаты(считается с 1)
    {
        if(plane[0][j]>resultSum){
            resultSum = plane[0][j];
            resultIn=j;
        }
    }

    int i = 1,j=resultIn;
    while(i<N)//Запись пути
    {
        if(plane[i][j-1]>=plane[i][j] && plane[i][j-1]>plane[i][j+1]){
            resultPath+="W";
            j--;
        }else if(plane[i][j-1]<=plane[i][j] && plane[i][j]>=plane[i][j+1]){
            resultPath+="S";
        }else if(plane[i][j+1]>=plane[i][j] && plane[i][j-1]<plane[i][j+1]){
            resultPath+="E";
            j++;
        }
        i++;
    }

    if(resultPath == "") resultPath = "Можно никуда дальше не идти";
    cout << "Итоговый вывод: " << resultIn << ", " << resultPath << ", " << resultSum << endl;

    cout << endl << "For debug: " << endl;
    for(int i = 0; i < N; i++)
    {
        for(int j = 1; j < M+1; j++)
        {
           cout << plane[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}