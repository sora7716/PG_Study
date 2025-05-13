#include <stdio.h>

int main() {
	int depth = 10;
	int width = 5;
	//ê[Ç≥
	for (int i = 0;i < depth;i++) {
		//ïù
		for (int j = 0;j < width + (i + 1);j++) {
			if (j != width - (i + 1)) {
				printf("-");
			} else {
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}