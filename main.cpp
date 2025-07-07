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
/// マージソート
/// </summary>
/// <param name="lists">リスト</param>
/// <param name="left">左端</param>
/// <param name="right">右端</param>
void MargeSort(int* lists, int left, int right) {
	int temp[kListSize] = {}; //一時保存用の配列

	if (left < right) {
		//真ん中を求める
		int mid = (left + right) / 2;

		//左側をソート
		MargeSort(lists, left, mid); 

		//右側をソート
		MargeSort(lists, mid + 1, right); 

		//左側の値を一時保存
		for (int i = mid; i >= left; i--) {
			temp[i] = lists[i]; 
		}

		//右側の値を一時保存
		for (int i = mid + 1; i <= right; i++) {
			temp[right - (i - (mid + 1))] = lists[i];
		}

		//左側のインデックス	
		int leftIndex = left; 
		//右側のインデックス
		int rightIndex = right;

		for (int i = left; i <= right; i++) {
			if (temp[leftIndex] < temp[rightIndex]) {
				//左側の値をリストに代入
				lists[i] = temp[leftIndex];
				leftIndex++;
			} else {
				//右側の値をリストに代入
				lists[i] = temp[rightIndex];
				rightIndex--;
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

	//マージソートを実行
	MargeSort(lists, 0, kListSize - 1); 

	//ソート後のリストを出力
	printf("ソート後のリスト:");
	ListPrint(lists);
	return 0;
}