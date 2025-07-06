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

	//選択ソート開始
	for (int i = 0; i < kListSize; i++) {
		int index = i;//検索インデックスiに設定
		for (int j = i; j < kListSize; j++) {
			if (lists[j] < lists[index]) {
				index = j;//検索インデックスをjに設定
			}
		}
		int temp = lists[index];
		lists[index] = lists[i];
		lists[i] = temp;
	}

	//ソート後のリストを出力
	printf("ソート後のリスト:");
	ListPrint(lists);
	return 0;
}