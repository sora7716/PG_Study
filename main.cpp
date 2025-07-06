#include <stdio.h>
//最大桁数
const int kMaxDigits = 16;

//数字を格納する構造体
typedef struct Digit {
	char c_str[kMaxDigits];
	int nums[kMaxDigits];
	int bitNum;
}Digit;

/// <summary>
/// n進数に変換
/// </summary>
/// <param name="inputNum">変換対象</param>
/// <param name="n">n進数</param>
/// <returns>n進数に変換</returns>
Digit ConvertDigits(int inputNum, int n) {
	Digit result = {};
	//変換
	for (int i = 0; inputNum > 0; i++) {
		//2進数に変換して格納
		result.nums[i] = inputNum % n;
		if (result.nums[i] < 10) {
			//文字列に変換
			result.c_str[i] = result.nums[i] + '0';
		} else {
			result.c_str[i] = (result.nums[i] % 10) + 'A';
		}
		inputNum /= n; //次の桁へ進むために2で割る
		//どれくらい計算したか
		result.bitNum++;
	}
	return result;
}

/// <summary>
/// 文字列として与えられた数字を出力します。
/// </summary>
/// <param name="digits">数字</param>
void PrintDigits(const Digit& digits) {
	//出力
	for (int i = digits.bitNum - 1; i >= 0; i--) {
		printf("%c", digits.c_str[i]);
	}

}

/// <summary>
/// 入力関数のバッファをクリアする
/// </summary>
void ClearInputBuffer() {
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF) {}
}

int main() {
	//入力される数字
	int inputNum = 0;
	//n進数のnの部分
	int base = 0;
	//n進数変換した結果を保存する
	Digit digits = {};
	//終了フラグ
	int isFinish = -1;

	//ループの開始
	while (true) {

		//変換したい値を入力(10進数で)
		while (true) {
			printf("10進数を入力:");
			int result = scanf_s("%d", &inputNum);
			ClearInputBuffer(); //入力バッファをクリア

			//入力された値が正しいかを確認
			if (result != 1) {
				printf("正しい10進数を入力してください。\n");
			} else {
				break;
			}
		}

		//変換したいn進数のnの部分を入力
		while (true) {
			printf("N進数に変換Nに当てはめる数字を入力:");
			int result = scanf_s("%d", &base);
			ClearInputBuffer(); //入力バッファをクリア

			//入力された値が正しいかを確認
			//入力された値が正しいかを確認
			if (result != 1) {
				printf("正しい数字を入力してください。\n");
			} else {
				break;
			}
		}

		//n進数に変換
		digits = ConvertDigits(inputNum, base);
		//入力されたn進数に変換
		printf(" %d進数", base);
		//n進数を出力
		PrintDigits(digits);

		//続けるかを確認
		while (true) {
			printf("\n続ける場合は0、終了する場合は1を入力: ");
			//終了フラグが1ならば終了
			int result = scanf_s("%d", &isFinish);
			ClearInputBuffer();//入力バッファをクリア
			//数字が入力されたかを確認
			if (result != 1) {
				printf("0か1を入力してください。\n");
			} else {
				//選択された数字と違う値が入った場合
				if (isFinish > 1) {
					printf("0か1を入力してください。\n");
				} else {
					break;
				}
			}
		}

		//終了フラグが1ならば終了
		if (isFinish == 1) {
			break;
		}
	}
	return 0;
}
