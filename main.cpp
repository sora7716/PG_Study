#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//リストの要素数
const int kListSize = 10;

//リストの出力
void ListPrint(int* lists) {
	for (int i = 0; i < kListSize; i++) {
		printf("%d,", lists[i]);
	}
	printf("\n");
}

/// <summary>
/// バブルソート
/// </summary>
/// <param name="lists">リスト</param>
void BubbleSort(int *lists) {
	//バブルソート開始
	for (int i = 0; i < kListSize; i++) {
		for (int j = kListSize - 1; j > i; j--) {
			if (lists[j - 1] > lists[j]) {
				int temp = lists[j - 1];
				lists[j - 1] = lists[j];
				lists[j] = temp;
			}
		}
	}
}

int main() {
	//ランド関数の初期化
	srand(static_cast<unsigned int>(time(nullptr)));
	//ソートするリスト
	int lists[kListSize] = {};
	//リストの初期化
	for (int i = 0; i < kListSize; i++) {
		lists[i] = rand() % 100; // 0〜99の乱数を生成
	}
	//ソート前のリストを出力
	printf("ソート前のリスト:");
	ListPrint(lists);

	//バブルソートを実行
	BubbleSort(lists);

	//ソート後のリストを出力
	printf("ソート後のリスト:");
	ListPrint(lists);
	return 0;
}