#include <stdio.h>
/* input: n = 5, w = {5, 6, 10, 11, 16}, W = 21
   Sum of Subsets: {5,6,10}, {5,16}, {10,11} */

typedef int index;
int n = 5;
int w[5] = { 5, 6, 10, 11, 16 };
int W = 21;

int cnt = 0;

int promising(index i, int weight, int total);
void sumofsubsets(index i, int weight, int total, int include[]);

int main(void) {
	int include[5] = { 0 };
	printf("Sum of Subsets\n--------------\n");
	sumofsubsets(0, 0, W, include);
	printf("Total call: %d", cnt);
	return 0;
}

void sumofsubsets(index i, int weight, int total, int include []) {
	if (promising(i, weight, total)) {
		if (weight == W) { //합이 21이면
			printf(" { ");
			for (int j = 0; j < 5; j++)
				if (include[j])
					printf("%d ", w[j]);
			printf("}\n");
		}
		else if (i < 5) { /* out of range 방지용 조건 */
			/* 숫자를 추가함 */
			include[i] = 1;
			sumofsubsets(i + 1, weight + w[i], total - w[i], include); //숫자를 추가했으므로 weight와 total의 값 변화
			/* 숫자를 추가하지 않음 */
			include[i] = 0;
			sumofsubsets(i + 1, weight, total, include); //숫자를 추가하지 않았으므로 weight과 total 값 변화 없음
		}
	}
}

int promising(index i, int weight, int total) {
	cnt++;
	return (weight + total >= W) && (weight == W || weight + w[i] <= W);
} /* 해당 원소가 유망한가? = Subset에 추가될 가능성이 있는 원소인가? */
