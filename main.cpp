#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

//3x3の行列
typedef struct Matrix3x3 {
	float m[3][3];
}Matrix3x3;

//マスの位置
typedef struct Cell {
	int row;
	int col;
}Cell;

//グリッドに入れるセルの状態
enum GridCell {
	kCircle,
	kCross,
	kEmpty,
};

/// <summary>
/// グリッドの中身をリセット
/// </summary>
/// <returns>リセットしたグリッド</returns>
Matrix3x3 GridReset() {
	Matrix3x3 result = {};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			result.m[j][i] = kEmpty; // 全てのセルを空にする
		}
	}
	return result;
}

/// <summary>
/// グリッドの描画
/// </summary>
/// <param name="grid">グリッド</param>
void PrintGrid(const Matrix3x3& grid) {
	printf("-------------\n");
	for (int i = 0; i < 3; i++) {
		printf("|");
		for (int j = 0; j < 3; j++) {
			if (grid.m[j][i] == kCircle) {
				printf(" O ");//Oの出力
			} else if (grid.m[j][i] == kCross) {
				printf(" X ");//Xの出力
			} else {
				printf("   ");//空白の出力
			}
			printf("|");
		}
		printf("\n-------------\n");
	}
}

/// <summary>
/// 改行を削除
/// </summary>
/// <param name="input">入力</param>
void DeleteReturn(char* input) {
	//文字入力の冗長
	char inputBuffer = '\0';
	//改行を排除
	while ((inputBuffer = getchar()) != '\n') {
		input = &inputBuffer;
	}

}

/// <summary>
/// 有効な入力かチェック
/// </summary>
/// <returns>有効な入力かのフラグ</returns>
bool IsValidInput(char input) {
	//結果
	bool result = false;

	//数字かどうか
	if (isdigit(input)) {
		result = true;
	}

	//数字だった場合1~3の範囲内かどうか
	int num = atoi(&input);
	if (num >= 1 && num <= 3) {
		result = true;
	} else {
		result = false;
	}

	return result;
}

/// <summary>
/// 空白かどうかチェック
/// </summary>
/// <param name="grid">グリッド</param>
/// <param name="cell">マス</param>
/// <returns>空白かどうかのフラグ</returns>
bool IsGridSpace(const Matrix3x3& grid, const Cell& cell) {
	if (grid.m[cell.col - 1][cell.row - 1] == kEmpty) {
		return true;
	}
	return false;
}

/// <summary>
/// 敵の選択するマス
/// </summary>
/// <param name="grid">グリッド</param>
/// <returns>敵の行列の添え字</returns>
Cell EnemyCell(const Matrix3x3& grid) {
	//結果
	Cell result = { rand() % 3 + 1,rand() % 3 + 1 };
	if (IsGridSpace(grid, result)) {
		return result;
	}

	return EnemyCell(grid);
}

/// <summary>
/// ラインのチェック
/// </summary>
/// <param name="grid">グリッド</param>
/// <param name="gridCell">グリッドのマス</param>
/// <returns>ラインチェック</returns>
bool IsLineCheck(const Matrix3x3& grid, GridCell gridCell) {
	for (int i = 0; i < 3; i++) {
		if (grid.m[i][0] == gridCell && grid.m[i][1] == gridCell && grid.m[i][2] == gridCell) {
			return true;
		}
		if (grid.m[0][i] == gridCell && grid.m[1][i] == gridCell && grid.m[2][i] == gridCell) {
			return true;
		}
	}
	if (grid.m[0][0] == gridCell && grid.m[1][1] == gridCell && grid.m[2][2] == gridCell) {
		return true;
	}
	if (grid.m[0][2] == gridCell && grid.m[1][1] == gridCell && grid.m[2][1] == gridCell) {
		return true;
	}
	return false;
}

/// <summary>
/// 勝者をチェック
/// </summary>
/// <param name="grid">グリッド</param>
/// <returns>勝者</returns>
GridCell WinnerCheker(const Matrix3x3& grid) {
	if (IsLineCheck(grid, kCircle)) {
		return kCircle;//Oの勝利
	} else if (IsLineCheck(grid, kCross)) {
		return kCross;//Xの勝利
	}
	return kEmpty;//勝者なし
}

/// <summary>
/// 数字の入力
/// </summary>
/// <param name="label">ラベル</param>
/// <returns></returns>
int InputNumber(const char* label) {
	char inputNum = '\0';
	//行の入力
	while (true) {
		//行を選択
		printf("%s（1～3）->", label);
		inputNum = getchar();
		//改行を削除
		DeleteReturn(&inputNum);
		//有効な範囲かどうか
		if (!IsValidInput(inputNum)) {
			printf("有効な値を入力してください\n");
			continue;
		} else {
			break;
		}
	}
	//値を整数にする
	return atoi(&inputNum);
}

/// <summary>
/// プレイヤーの入力
/// </summary>
/// <param name="name">プレイヤーの名前</param>
/// <returns>行列の番号</returns>
Cell InputPlayer(const char* name) {
	Cell result = {};
	printf("%s\n", name);
	result.row = InputNumber("行");
	result.col = InputNumber("列");
	return result;
}

/// <summary>
/// 空白をチェック
/// </summary>
/// <param name="grid">グリッド</param>
/// <returns>空白かどうかのフラグ</returns>
bool IsBlank(const Matrix3x3& grid) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid.m[i][j] == kEmpty) {
				return true;
			}
		}
	}
	return false;
}
int main() {
	//グリッドの初期化
	Matrix3x3 grid = {};
	//グリッドをリセット
	grid = GridReset();
	//入力された文字
	char inputNum = '\0';
	//行列
	Cell cell = {};
	//ランド関数の初期化
	srand(static_cast<unsigned int>(time(nullptr)));

	//ゲーム開始
	printf("〇×ゲーム スタート！\n");
	printf("=========================\n");
	while (true) {
		//空白がなくなったら
		if (IsBlank(grid)) {
			break;
		}

		//プレイヤー1の入力
		cell = InputPlayer("あなた");

		//空白かどうか
		if (IsGridSpace(grid, cell) && (cell.row > 0 && cell.col > 0)) {
			//空白だった場合選択したセルに〇をセット
			grid.m[cell.col - 1][cell.row - 1] = kCircle;
			//グリッドの出力
			PrintGrid(grid);
			//何行目に書いたか
			printf("%d行%d列にOをかいた！\n", cell.row, cell.col);
			printf("-------------------------\n");
		} else {
			printf("もうすでに入力されているマスです。\n");
			printf("もう一度入力してください\n");
			continue;
		}


		//相手のターン
		//敵のマスを選択
		cell = EnemyCell(grid);

		printf("相手(コンピュータ)\n");
		//敵の入力
		grid.m[cell.col - 1][cell.row - 1] = kCross;
		//グリッドの出力
		PrintGrid(grid);
		//何行目に書いたか
		printf("%d行%d列にXをかいた！\n", cell.row, cell.col);
		printf("-------------------------\n");

		//勝利者のチェック
		GridCell gridCell = WinnerCheker(grid);

		//勝利者がいるかどうか
		if (gridCell != kEmpty) {
			if (gridCell == kCircle) {
				printf("あなたの勝利\n");
			} else {
				printf("相手の勝利\n");
			}
			//ゲームを終了するかどうか
			printf("ゲームを続けますか？(0:終了,それ以外の場合ループ):");
			char isFinish = '\0';
			isFinish = getchar();
			DeleteReturn(&isFinish);
			if (isFinish == 0) {
				break;
			} else {
				//グリッドをリセット
				grid = GridReset();
				//ゲーム開始
				printf("〇×ゲーム スタート！\n");
				printf("=========================\n");
			}
		}
	}
	printf("ゲーム終了\n");
	return 0;
}