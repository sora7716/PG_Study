#include <stdio.h>

int main() {
	//ê[Ç≥
	const int kDepth = 5;
	//ïù
	const int kWidth = 5;
	//ê[Ç≥
	for (int i = 0; i < kDepth; i++) {
		//ïù
		for (int j = 0; j < kWidth + i; j++) {
			if (j < kWidth - (i + 1)) {
				printf("-");
			} else {
				printf("*");
			}
		}
		//â¸çs
		printf("\n");
	}
	return 0;
}