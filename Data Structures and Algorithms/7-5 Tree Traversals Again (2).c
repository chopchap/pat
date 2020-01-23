/* Sample Input:
 * 6
 * Push 1
 * Push 2
 * Push 3
 * Pop
 * Pop
 * Push 4
 * Pop
 * Pop
 * Push 5
 * Push 6
 * Pop
 * Pop
 * Sample Output:
 * 3 4 2 6 5 1
 */
#include <stdio.h>
#include <string.h>

#define MAXN 30

int stack[MAXN], pre[MAXN], in[MAXN], post[MAXN];

void solve(int preL, int inL, int postL, int n);        /* Recursive version */

int main()
{
	int N, i, temp, preCnt=0, inCnt=0, Cnt=0;
	char OP[5] = {0};

	scanf("%d", &N);
	for (i = 0; i < (N<<1); i++) {
		scanf("%s", OP);
		if (strcmp(OP, "Push") == 0) {
			scanf("%d", &temp);
			stack[Cnt++] = pre[preCnt++] = temp;
		} else
			in[inCnt++] = stack[--Cnt];
	}
	solve(0, 0, 0, N); 	/* Core algorithm */

	printf("%d", post[0]);
	for (i = 1; i < N; i++) printf(" %d", post[i]);
	putchar('\n');

	return 0;
}

void solve(int preL, int inL, int postL, int n)
{
	int root, i, L, R;	/* L/R to indicate left/right subtree size */

	if (n == 0) return; 	/* Stop recursion conditions */
	if (n == 1) { post[postL] = pre[preL]; return; }

	root = pre[preL];
	post[postL+n-1] = root;

	for (i = 0; i < n; i++) 	/* Find the root in in[MAXN] */
		if (in[inL+i] == root) break;

	L = i; R = n-L-1;
	solve(preL+1, inL, postL, L);
	solve(preL+L+1, inL+L+1, postL+L, R);
}
