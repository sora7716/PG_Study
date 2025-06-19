#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//名前の最大の長さ
const unsigned int kMaxTextLength = 1 << 10;

//チンチロリンの役職と倍率
typedef struct ChinchirorinProp {
	char role[kMaxTextLength];//役職
	int rate;//倍率
	int diceRoll;//賽の目
}ChinchirorinProp;

//チンチロリンの役職の添え字用の列挙型
enum ChinchirorinRoleIndex {
	kZorome,
	kPinSoro,
	kMeNoYaku,
	kSiGoRo,
	kHiFuMi,
	kNone,
};

//ゲーム内の役割
enum RoleInGame {
	kChild,
	kParent,
	kRoleInGameCount,
};

/// <summary>
/// チンチロリン
/// </summary>
/// <param name="dice">サイコロ</param>
/// <param name="roleLists">役のリスト</param>
/// <returns>チンチロリンの役職と倍率</returns>
ChinchirorinProp Chinchirorin(int* dice, const char* roleLists[]) {
	//結果
	ChinchirorinProp result = {};

	//サイコロを振る
	for (int i = 0; i < 3; i++) {
		dice[i] = rand() % 6 + 1; // 1から6の乱数を生成
	}

	//自分の出目を表示
	printf("出目は%d, %d, %d\n", dice[0], dice[1], dice[2]);

	//すべての目が同じ場合
	if (dice[0] == dice[1] && dice[0] == dice[2]) {
		//役と倍率を決定
		strcpy_s(result.role, roleLists[kZorome]);
		result.rate = 3;
		return result;
		if (dice[0] == 1) {
			//役と倍率を決定
			strcpy_s(result.role, roleLists[kPinSoro]);
			result.rate = 5;
			return result;
		}
	}

	//2つの目が同じ場合
	if (dice[0] == dice[1]) {
		//役と倍率を決定
		sprintf_s(result.role, roleLists[kMeNoYaku], dice[2]);
		result.rate = 1;
		//今の賽の目を保存
		result.diceRoll = dice[2];
		return result;
	} else if (dice[0] == dice[2]) {
		//役と倍率を決定
		sprintf_s(result.role, roleLists[kMeNoYaku], dice[1]);
		result.rate = 1;
		//今の賽の目を保存
		result.diceRoll = dice[1];
		return result;
	} else if (dice[1] == dice[2]) {
		//役と倍率を決定
		sprintf_s(result.role, roleLists[kMeNoYaku], dice[0]);
		result.rate = 1;
		//今の賽の目を保存
		result.diceRoll = dice[0];
		return result;
	}

	//4,5,6の目が出たか
	for (int i = 0; i < 3; i++) {
		//4,5,6の目が出た場合
		if (dice[i] == 4 || dice[i] == 5 || dice[i] == 6) {
			//役と倍率を決定
			strcpy_s(result.role, roleLists[kSiGoRo]);
			result.rate = 2;
		} else {
			//役と倍率を決定
			strcpy_s(result.role, roleLists[kNone]);
			result.rate = -1;
			return result;
		}
	}

	//1,2,3の目が出たか
	for (int i = 0; i < 3; i++) {
		//1,2,3の目が出た場合
		if (dice[i] == 1 || dice[i] == 2 || dice[i] == 3) {
			//役と倍率を決定
			strcpy_s(result.role, roleLists[kHiFuMi]);
			result.rate = -2;
		} else {
			//役と倍率を決定
			strcpy_s(result.role, roleLists[kNone]);
			result.rate = -1;
			return result;
		}
	}

	return result;
}

int main() {
	//名前
	char name[kMaxTextLength] = "";
	//掛け金.
	int bet = 0;
	//ランド関数の初期化
	srand(static_cast<unsigned int>(time(nullptr)));
	//サイコロ
	int dice[3] = {};
	//役職
	ChinchirorinProp chinchirorins[static_cast<int>(kRoleInGameCount)] = {};
	//役のリスト
	const char* roleLists[] = { "ゾロ目", "ピンゾロ", "%dの目","シゴロ", "ヒフミ", "役なし" };

	printf("君の名前を教えてくれないかい?\n");
	//名前の入力
	scanf_s("%s", name, kMaxTextLength);

	printf("%sくんだね。よろしく。今回はワシが親でいくよ\n\n", name);

	printf("まずは掛け金を100から10000ペリカで決めてくれ\n");
	//掛け金の入力
	scanf_s("%d", &bet);

	printf("では%sくん、サイコロを振ってくれ\n\n", name);

	printf("続行するには何かキーを押してください . . .");
	(void)getchar();//改行を読み飛ばすため
	(void)getchar();//実際の入力待ち

	//チンチロリンを行う
	chinchirorins[static_cast<int>(kChild)] = Chinchirorin(dice, roleLists);

	//今の自分の役を確認
	printf("%sだね。", chinchirorins[static_cast<int>(kChild)].role);

	//自分の役によって
	if (strcmp(chinchirorins[static_cast<int>(kChild)].role, roleLists[kNone]) != 0 && strcmp(chinchirorins[static_cast<int>(kChild)].role, roleLists[kHiFuMi]) != 0) {
		//役があり、ヒフミ以外だった場合
		printf("次はワシがサイコロを振ろう\n\n");

		printf("続行するには何かキーを押してください . . .");
		(void)getchar();//実際の入力待ち

		//チンチロリンを行う
		chinchirorins[static_cast<int>(kParent)] = Chinchirorin(dice, roleLists);

		//親の役を表示
		printf("役は%s。", (strcmp(chinchirorins[static_cast<int>(kParent)].role, roleLists[kNone]) == 0) ? "なし" : chinchirorins[static_cast<int>(kParent)].role);

		//勝敗を決める
		if (chinchirorins[static_cast<int>(kParent)].rate > chinchirorins[static_cast<int>(kChild)].rate) {
			printf("ワシの勝ちだ。%dペリカ払ってもらおう\n", bet * abs(chinchirorins[static_cast<int>(kParent)].rate));
		} else if (chinchirorins[static_cast<int>(kParent)].rate == chinchirorins[static_cast<int>(kChild)].rate) {

			//親のほうが大きかったら
			if (chinchirorins[static_cast<int>(kParent)].diceRoll > chinchirorins[static_cast<int>(kChild)].diceRoll) {
				printf("ワシの勝ちだ。%dペリカ払ってもらおう\n", bet * abs(chinchirorins[static_cast<int>(kParent)].rate));
			} else if (chinchirorins[static_cast<int>(kParent)].diceRoll == chinchirorins[static_cast<int>(kChild)].diceRoll) {
				printf("今回は引き分けだ。%dペリカ払い戻そう\n", bet);
			} else {
				printf("君の勝ちだ。%dペリカ払い戻そう\n", bet * abs(chinchirorins[static_cast<int>(kChild)].rate));
			}
		} else {
			printf("君の勝ちだ。%dペリカ払い戻そう\n", bet * abs(chinchirorins[static_cast<int>(kChild)].rate));
		}
	} else {
		//役なし、またはヒフミだった場合
		printf("この時点で君の負けだね。%dペリカ払ってもらうよ\n\n", bet * abs(chinchirorins[static_cast<int>(kChild)].rate));
	}

	return 0;
}