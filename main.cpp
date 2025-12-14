#include <stdio.h>
#include <stdlib.h>

//セル
struct Cell {
	int val;
	Cell* next;
};

//リスト
struct  List {
	Cell head;
	/// <summary>
	/// 値を末尾に追加
	/// </summary>
	/// <param name="endCell">末尾</param>
	/// <param name="val">値</param>
	void Create(Cell* endCell, int val) {
		//Cellのサイズ分メモリを確保
		Cell* newCell = static_cast<Cell*>(malloc(sizeof(Cell)));

		//メモリ確保失敗時は終了
		if (newCell == nullptr) {
			return;
		}

		//新しいセルに値を設定
		newCell->val = val;
		newCell->next = nullptr;//次のセルは無し

		//末尾まで移動
		while (endCell->next != nullptr) {
			endCell = endCell->next;
		}

		//末尾に先ほど作ったセルを挿入
		endCell->next = newCell;
	}
};



/// <summary>
/// リストをすべて表示
/// </summary>
/// <param name="endCell">末尾</param>
void Index(List list) {
	//リストから先頭セルをしゅおｔｋ
	Cell* endCell = &list.head;
	//先頭の値を表示
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("%d,", endCell->val);
	}
}

int main() {
	List list;
	list.head.next = nullptr;
	for (int i = 0; i < 4; i++) {
		list.Create(&list.head, i * 2);
	}

	Index(list);
	return 0;
}