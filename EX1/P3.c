#include <stdlib.h>
#include <stdio.h>

void fill(int ary[], int N, int A, int B) {
	for (int i = 0; i < N; i++) {
		if (i >= A && i <= B) ary[i] = 1;
		else if (i >= B && i <= A) ary[i] = 1;
		else ary[i] = 0;
	}
	return;
}

int main (void) {
	int N;
	printf("Array size (N): ");
	scanf("%d", &N);

	int A;
	printf("Range start (A): ");
	scanf("%d", &A);

	int B;
	printf("Range end (B): ");
	scanf("%d", &B);

	int ary[N];
	fill(ary, N, A, B);

	for (int i = 0; i < N; i++) printf("%d%s", ary[i], i < N - 1 ? " " : "\n");

	return EXIT_SUCCESS;
}