// LAB_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <iomanip>
#include <climits>
#define perm(i,j);
using namespace std;
bool Permutation(int* perm)
{
	const int n = 4;
	int i = 0, j = 0;
	/*int perm[];*/
	int t = perm[j];
	perm[j] = perm[i];
	perm[i] = t;
	/* int perm[n];*/
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			/*int i = n - 1;*/
			while (--i >= 0 && perm[i] > perm[i + 1]);
	if (i == -1)
		return false;
	for (int j = i + 1, k = n - 1; j < k; j++, k--)
		perm(j, k);
	/*int j = i + 1;*/
	while (perm[i] < perm[j])
		j++;
	perm(i, j);
	return true;
}
const int V = 6;
//алгоритм Дейкстры
void Dijkstra(int GR[V][V], int st)   // граф G=[V][V]
{
	int distance[V], count, index, i, u, m = st + 1; // 2 массива:логический visited – для хранения информации о посещенных вершинах и численный distance
	bool visited[V];
	for (i = 0; i < V; i++)
	{
		distance[i] = INT_MAX; visited[i] = false;
	}
	distance[st] = 0; //В качестве исходного пункта выбирается вершина st и ей приписывается нулевой путь : distance[st] = 0
	for (count = 0; count < V - 1; count++)
	{
		int min = INT_MAX;
		for (i = 0; i < V; i++)
			if (!visited[i] && distance[i] <= min)
			{
				min = distance[i]; index = i;
			}
		u = index;
		visited[u] = true;
		for (i = 0; i < V; i++)
			if (!visited[i] && GR[u][i] && distance[u] != INT_MAX &&
				distance[u] + GR[u][i] < distance[i])
				distance[i] = distance[u] + GR[u][i];
	}
	cout << "Стоимость пути из начальной вершины до остальных:\t\n";
	for (i = 0; i < V; i++) if (distance[i] != INT_MAX)
		cout << m << " > " << i + 1 << " = " << distance[i] << endl;
	else cout << m << " > " << i + 1 << " = " << "маршрут недоступен" << endl;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int start, GR[V][V] = {
	{0, 1, 4, 0, 2, 0},
	{0, 0, 0, 9, 0, 0},
	{4, 0, 0, 7, 0, 0},
	{0, 9, 7, 0, 0, 2},
	{0, 0, 0, 0, 0, 8},
	{0, 0, 0, 0, 0, 0} };
	cout << "Начальная вершина >> "; cin >> start;
	Dijkstra(GR, start - 1);
	Permutation(0);
	system("pause>>void");
}

