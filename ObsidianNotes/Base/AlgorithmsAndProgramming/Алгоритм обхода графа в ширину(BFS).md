#Algorithm 
[[2022-06-21]]
# Алгорит обхода/поиска в ширину(breadth-first search)
`go wide, bird eye's view`
## Description
Вместо того, чтобы двигаться по определенному* пути ==до конца==(как [[Алгоритм ообхода графа в глубину(DFS)]]), BFS предполагает **движение вперед по одному соседу** за раз.
Чем [[Алгоритм ообхода графа в глубину(DFS)|DFS]] отличается от **BFS**? Мне нравится думать, что *DFS* идет напролом, а *BFS* не торопится, а изучает все в пределах одного шага.  
```ad-note
title: Но возникает вопрос: как узнать, каких соседей следует посетить первыми?  
  Для этого мы можем воспользоваться концепцией «первым вошел, первым вышел» (first-in-first-out, FIFO) из очереди (queue). Мы помещаем в очередь сначала ближайшую к нам вершину, затем ее непосещенных соседей, и продолжаем этот процесс, пока очередь не опустеет или пока мы не найдем искомую вершину.
```

### Пример
  
  
![](https://habrastorage.org/r/w1560/webt/-d/dk/wt/-ddkwtwgddcvzo4mbrpzeiaklm8.png)  
  
Вместо следования по пути, BFS подразумевает посещение **ближайших** к s соседей за одно *действие* (шаг), затем ==посещение соседей соседей== и так до тех пор, пока не будет обнаружено t.  
  
![](https://habrastorage.org/r/w1560/webt/1u/vb/ny/1uvbnygi83vt6bxqnmv1hbwuzyq.png)  
  
![](https://habrastorage.org/r/w1560/webt/tg/en/jq/tgenjqvsz1zipcv3obsicrhq78a.png)  
  
![](https://habrastorage.org/r/w1560/webt/tf/j9/on/tfj9on04zudfmelpbn00xeh_tpm.png)

## Реализация алгоритма
```cpp
using namespace std;

vector<int> graph[100000];
bool used[100000];      //вместо visited массив меток обычно называют used.

int main() {
    //Ввод графа...

    queue<int> q;
    q.push(0);              //в качестве начальной вершины используем 0.
    used[0] = true;

    while (!q.empty()) {
        int cur = q.front();  //извлекаем из очереди текущую вершину
        q.pop();

        //Здесь должна быть обработка текущей вершины.
        cout << "BFS at vertex " << cur + 1 << endl;

        for (int neighbor: graph[cur]) {    //добавляем всех непосещённых соседей.
            if (!used[neighbor]) {
                q.push(neighbor);
                used[neighbor] = true;
            }
        }
    }
}
```
## Заметки
Смотри подробнее: [Обход в ширину (BFS) | brestprog](https://brestprog.by/topics/bfs/)