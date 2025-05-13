#include <stdio.h>

int main() {
	int depth = 5;
	int width = 5;
	printf("\n");
	//ê[Ç≥
	for (int i = 0; i < depth; i++) {
		//ïù
		for (int j = 0; j < width + i; j++) {
			if (j < width - (i + 1)) {
				printf("-");
			} else {
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}