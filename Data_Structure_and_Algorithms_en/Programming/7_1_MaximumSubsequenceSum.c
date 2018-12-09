/* Sample Input:
 * 10
 * -10 1 2 3 4 -5 -23 3 7 -21
 * Sample Output:
 * 10 1 4
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXK 100000
typedef struct OutNode *PtrToOutNode;
struct OutNode {
	int first, last;
	int MaxSum;
};

PtrToOutNode MaxSubseqSum4(int A[], int N);

int main()
{
	int K, i, a[MAXK];
	PtrToOutNode out;

	scanf("%d", &K);
	for (i = 0; i < K; i++)
		scanf("%d", &a[i]);
	out = MaxSubseqSum4(a, K);

	if (out->MaxSum >= 0)
		printf("%d %d %d\n", out->MaxSum, a[out->first], a[out->last]);
	else
		printf("%d %d %d\n", 0, a[0], a[K-1]);
	free(out);
	return 0;
}

PtrToOutNode MaxSubseqSum4(int A[], int N)
{
	/* Set MaxSum as -1 in case of all K numbers are negative except '0' */
	int ThisSum=0, MaxSum=-1, Diff=0, i;
	PtrToOutNode out = (PtrToOutNode) malloc(sizeof(struct OutNode));

	out->first = out->last = out->MaxSum = 0;
	for (i = 0; i < N; i++) {
		ThisSum += A[i];
		if (ThisSum > MaxSum) {
			MaxSum = ThisSum;
			/* When ThisSum>MaxSum, the last member of max subsequence must 
			 * be i (which is the current processed node), then find the first
			 * element according to the difference between them */
			out->last = i;
			out->first = out->last - Diff;
			Diff++;
		} else if (ThisSum < 0) {
			ThisSum = 0, Diff = 0;
		} else 	/* ThisSum equals to MaxSum, difference+1 */
			Diff++;
	}
	out->MaxSum = MaxSum;
	return out;
}
