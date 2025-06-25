#include <stdio.h>
#include <stdlib.h> // memory functions
#define MOD 10007

int **alloc_matrix(int m, int n)
{
	int **a;
	// allocate memory for the pointer vector (of lines)
	a = malloc(m * sizeof(int *));
	if (a == 0) {
		fprintf(stderr, "malloc failed\n");
		return NULL;
	}
	for (int i = 0; i < m; i++) {
		*(a + i) = malloc(n * sizeof(int));
	if (a[i] == 0) {
		fprintf(stderr, "malloc failed\n");
	// free the allocated memory for the lines
	while (--i >= 0)
		free(a[i]);
	free(a);
	return NULL;
		}
	}
	return a;
}

void read_matrix(int m, int n, int **a)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", *(a + i) + j);
}


void free_matrix(int m, int **a)
{
	for (int i = 0; i < m; i++)
		free(a[i]);
	free(a);
}

// function for inserting matrices into the matrix vector

int ***include(int ***new, int *index, int **row, int **column, int m, int n)
{
	// the matrix we want to add tot he collection
	int **a = alloc_matrix(m, n);
	read_matrix(m, n, a);
	if (new)
		new = realloc(new, ((*index) + 1) * sizeof(int **));
	else
		new = malloc(sizeof(int **));
	new[*index] = a; // include the matrix

	if (*row)
		*row = realloc(*row, ((*index) + 1) * sizeof(int));
	else
		*row = malloc(sizeof(int));
	(*row)[*index] = m;

	if (*column)
		*column = realloc(*column, ((*index) + 1) * sizeof(int));
	else
		*column = malloc(sizeof(int));
	(*column)[*index] = n;

	*index = (*index) + 1; 
	return new;
}

void print_matrix(int ***new, int index, int *row, int *column)
{
	int number; // the number of the matrix we want to display
	scanf("%d", &number);
	if (number < 0 || number > index - 1) {
		printf("No matrix with the given index\n");
	} else {
		int m = row[number];
		int n = column[number];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				printf("%d ", new[number][i][j]);
			printf("\n");
		}
	}
}

void dimension(int index, int *row, int *column)
{
	int number;
	scanf("%d", &number);
	if (number < 0 || number > index - 1) {
		printf("No matrix with the given index\n");
	} else {
		int m = row[number]; // retinem dimensiunile matricei cerute
		int n = column[number];
		printf("%d %d\n", m, n);
		}
	}

// functie pentru redimensionarea unei matrice

void cut(int ***new, int index, int *row, int *column)
{
	int number, l, c;
	scanf("%d", &number); // numarul matricei pe care trebuie sa o redimensionam
	scanf("%d", &l);
	int *cutr = malloc(l * sizeof(int)); // vectorul de linii
	for (int i = 0; i < l; i++)
		scanf("%d", &cutr[i]);
	scanf("%d", &c);
	int *cutc = malloc(c * sizeof(int)); // vectorul de coloane
	for (int j = 0; j < c; j++)
		scanf("%d", &cutc[j]);
	if (number < 0 || number > index - 1) {
		printf("No matrix with the given index\n");
	} else {
		int **cut = alloc_matrix(l, c); // matricea redimensionata
		for (int i = 0; i < l; i++)
			for (int j = 0; j < c ; j++)
				cut[i][j] = new[number][cutr[i]][cutc[j]];
		free_matrix(row[number], new[number]);
		row[number] = l;
		column[number] = c;
		new[number] = cut;
	}
	free(cutr);
	free(cutc);
}

int sum_matrix(int ***new, int index, int *row, int *column)
{
	int s = 0;
	int m = row[index];
	int n = column[index];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				s = s + new[index][i][j];
				while (s < 0)
					s += MOD;
				s = s % MOD;
			}
} return s;
}

void sort_matrix(int ***new, int index, int *row, int *column)
{
	int *suma = malloc(index * sizeof(int));
	for (int i = 0; i < index; i++)
		suma[i] = sum_matrix(new, i, row, column);

	for (int i = 0; i < index - 1; i++)
		for (int j = 0; j < index - i - 1; j++)
			if (suma[j] > suma[j + 1]) {
		// interschimbarile
				int **aux = new[j + 1];
				new[j + 1] = new[j];
				new[j] = aux;
				int aux2 = row[j + 1];
				row[j + 1] = row[j];
				row[j] = aux2;

				int aux3 = column[j + 1];
				column[j + 1] = column[j];
				column[j] = aux3;

				int aux4 = suma[j + 1];
				suma[j + 1] = suma[j];
				suma[j] = aux4;
	}
	free(suma);
	}

void transpose_matrix(int ***new, int index, int *row, int *column)
{
	int number; // numarul matricei pe care trebuie sa o transpunem
	scanf("%d", &number);
	if (number < 0 || number > index - 1) {
		printf("No matrix with the given index\n");
	} else {
		int m = row[number];
		int n = column[number];
	// alocam memorie pentru matricea transpusa
	int **t = alloc_matrix(n, m);
	for (int i = 0; i < m ; i++)
		for (int j = 0 ; j < n; j++)
			t[j][i] = new[number][i][j];
	free_matrix(m, new[number]);
	row[number] = n; // modificarile in vectorii de linii si coloane
	column[number] = m;
	new[number] = t;
	}
}

int ***multiply(int ***new, int *index, int **row, int **column, int n1, int n2)
{
	if (n1 < 0 || n2 < 0 || n1 >= (*index) || n2 >= (*index)) {
		printf("No matrix with the given index\n");
	} else {
		if ((*column)[n1] != (*row)[n2]) {
			printf("Cannot perform matrix multiplication\n");
	} else {
		int **prod = alloc_matrix((*row)[n1], (*column)[n2]);
		for (int i = 0; i < (*row)[n1]; i++)
			for (int j = 0; j < (*column)[n2]; j++) {
				prod[i][j] = 0;
				for (int p = 0; p < (*row)[n2]; p++)
					prod[i][j] += ((new[n1][i][p] * new[n2][p][j]) % MOD + MOD);
			prod[i][j] %= MOD;
		}
		new = realloc(new, ((*index) + 1) * sizeof(int **));
		new[*index] = prod;

		*row = realloc(*row, ((*index) + 1) * sizeof(int));
		(*row)[*index] = (*row)[n1];

		*column = realloc(*column, ((*index) + 1) * sizeof(int));
		(*column)[*index] = (*column)[n2];

		*index = (*index) + 1; // crestem numarul de matrice
	}
	}
	return new;
}

int **power_log(int **a, int n, int pow)
{
	int **ans; // matrice unde stocam rezultatul

	if (pow == 1) {
		ans = alloc_matrix(n, n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ans[i][j] = a[i][j];
		return ans; // intoarce aceeasia matrice
	}

	if (pow % 2 == 0) {
		int **a2 = alloc_matrix(n, n);
	// am alocat spatiu pentru matricea ridicata la patrat
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				a2[i][j] = 0;
				for (int k = 0; k < n; k++) {
					a2[i][j] += (a[i][k] * a[k][j] + MOD) % MOD;
					a2[i][j] %= MOD;
				}
			}
		ans = power_log(a2, n, pow / 2);
		free_matrix(n, a2);
		return ans;
	}
	ans = power_log(a, n, pow - 1);

	int **aux = alloc_matrix(n, n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			aux[i][j] = 0;
				for (int k = 0; k < n; k++) {
					aux[i][j] += (a[i][k] * ans[k][j] + MOD) % MOD;
					aux[i][j] %= MOD;
				}
			}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans[i][j] = aux[i][j];

	free_matrix(n, aux);
	return ans;
}

void power(int ***new, int index, int *row, int *column)
{
	int number, pow;
	scanf("%d%d", &number, &pow);
	if (number < 0 || number > index - 1) {
		printf("No matrix with the given index\n");
		return;
	}
	if (pow < 0) {
		printf("Power should be positive\n");
		return;
	}
	if (row[number] != column[number]) {
		printf("Cannot perform matrix multiplication\n");
		return;
	}
	int **result = power_log(new[number], row[number], pow);
	// nu mai modificam dimensiunile
	free_matrix(row[number], new[number]);
	new[number] = result;
}

int ***memory_removal(int ***new, int *index, int **row, int **column)
{
	int number;
	scanf("%d", &number);
	if (number < 0 || number > (*index) - 1) {
		printf("No matrix with the given index\n");
	} else {
		free_matrix((*row)[number], new[number]);
		for (int i = number; i < *index - 1; i++) {
			new[i] = new[i + 1];
			(*row)[i] = (*row)[i + 1];
			(*column)[i] = (*column)[i + 1];
		}

	*index = (*index) - 1;

	new = realloc(new, (*index) * sizeof(int **));
	*row = realloc(*row, (*index) * sizeof(int));
	*column = realloc(*column, (*index) * sizeof(int));
	}
	return new;
}

void delete(int ***new, int index, int *row, int *column)
{
	for (int i = 0; i < index; i++)
		free_matrix(row[i], new[i]);
	free(new);
	free(row);
	free(column);
}

int main(void)
{
	int index = 0; // numarul matricei cu care urmeaza sa operam
	int *row = NULL; // vector ce retine numarul de linii
	int *column = NULL;
	int ***colection = NULL; // vectorul de matrice
	char q;
	int m, n, n1, n2;
	while (scanf("%c", &q)) {
		if (q == 'L') {
			scanf("%d%d", &m, &n);
			colection = include(colection, &index, &row, &column, m, n);
		} else {
			if (q == 'D') {
				dimension(index, row, column);
		} else {
			if (q == 'P') {
				print_matrix(colection, index, row, column);
		} else {
			if (q == 'C') {
				cut(colection, index, row, column);
		} else {
			if (q == 'M') {
				scanf("%d%d", &n1, &n2);
				colection = multiply(colection, &index, &row, &column, n1, n2);
		} else {
			if (q == 'O') {
				sort_matrix(colection, index, row, column);
		} else {
			if (q == 'T') {
				transpose_matrix(colection, index, row, column);
		} else {
			if (q == 'R') {
				power(colection, index, row, column);
		} else {
			if (q == 'F') {
				colection = memory_removal(colection, &index, &row, &column);
		} else {
			if (q == 'Q') {
				delete(colection, index, row, column);
			break;
		}
			printf("Unrecognized command\n");
	} } } } } } } } }
		getc(stdin); // evitam enterul
	}
	return 0;
}
