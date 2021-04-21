/*Згенерувати цілочисельну матрицю Q (p x n), яка містить як додатні, так і від’ємні елементи із діапазону [-90, 90]. Серед рядків матриці, що містять від’ємні елементи 
на головній діагоналі, знайти "особливий" елемент матриці, вважаючи "особливим" елемент, сума цифр якого є максимальною.На основі зміненої матриці Q створити масив рядків K, 
кожен рядок якого - це послідовність, розділених пробілом, подвоєних чисел відповідного рядка матриці Q. У кожному рядку отриманого масиву рядків K видалити усі символи, 
що не є цифрами чи пробілом.
*/

#include<iostream>
#include<iomanip>
#include<ctime>
#include<string>
#include<cmath>

using namespace std;

int** createM(int p, int n);
void showM(int** Q, int p, int n);
int* find(int** Q, int p, int n, int& kilk);
void showmas(int* mas, int kilk);
int* rownumb(int** Q, int p, int n, int& kilk);
int* speciall(int** Q, int* mas1, int* mas2, int p, int n, int kilk);

int main()
{
	int p, n, kilk = 0, kilk1 = 0;
	cout << "Enter p: "; cin >> p;
	cout << "Enter n: "; cin >> n;
	int** Q = createM(p, n);
	showM(Q, p, n);
	int* mas = find(Q, p, n, kilk);
	showmas(mas, kilk);
	int* mas1 = rownumb(Q, p, n, kilk1);
	showmas(mas1, kilk1);
	int* mas2 = speciall(Q, mas, mas1, p, n, kilk);
	showmas(mas2, kilk1);
}

int** createM(int p, int n)
{
	srand(time(NULL));
	int** Q = new int* [p];
	for (int i = 0; i < p; i++)
	{
		Q[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			Q[i][j] = rand() % 181 - 90;
		}
	}
	return Q;
}

void showM(int** Q, int p, int n)
{
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(5) << Q[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int* find(int** Q, int p, int n, int& kilk)
{
	int* mas = new int[p];
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i == j) && (Q[i][i] < 0))
			{
				mas[kilk] = Q[i][j];
				kilk++;
			}
		}
	}
	return mas;
}

void showmas(int* mas, int kilk)
{
	for (int i = 0; i < kilk; i++)
	{
		cout << setw(5) << mas[i];
	}
	cout << endl;
}

int* rownumb(int** Q, int p, int n, int& kilk)
{
	int* mas = new int[p];
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i == j) && (Q[i][j] < 0))
			{
				mas[kilk] = i + 1;
				kilk++;
			}
		}
	}
	return mas;
}

int* speciall(int** Q, int* mas1, int* mas2, int p, int n, int kilk)
{
	int* mas = new int[kilk];
	int MAX;
	for (int i = 0; i < kilk; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			int elem = abs(Q[mas2[i] - 1][j]);
			while (elem != 0)
			{
				int a = elem % 10;
				sum += a;
				elem = elem / 10;
			}
			MAX = sum;
			break;
		}
		for (int j = 0; j < n; j++)
		{
			int sum1 = 0;
			int elem1 = abs(Q[mas2[i] - 1][j]);
			while (elem1 != 0)
			{
				int a = elem1 % 10;
				sum1 += a;
				elem1 = elem1 / 10;
			}
			int MAX1 = sum1;
			if (MAX1 >= MAX)
			{
				MAX = MAX1;
			}
			else continue;
		}
		mas[i] = MAX;
	}
	return mas;
}
