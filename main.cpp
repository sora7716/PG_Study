#include <stdio.h>

//状態異常のデータ
struct StatusEffectData {
	int bitMask;
	const char* name;
};

//状態異常の数
const int kStatusEffectCount = 4;

int main() {
	//プレイヤーのステータス
	int playerStatus = 5;

	//状態異常のデータ
	StatusEffectData statusEffectsData[kStatusEffectCount] = {
		{ 1 << 0, "戦闘不能状態" },
		{ 1 << 1, "毒状態" },
		{ 1 << 2, "石化状態" },
		{ 1 << 3, "眠り状態" }
	};

	//プレイヤーのステートの表示
	printf("state = %d\n", playerStatus);

	//状態以上の表示
	for (int i = 0; i < kStatusEffectCount; i++) {
		if (playerStatus & statusEffectsData[i].bitMask) {
			printf("%s\n", statusEffectsData[i].name);
		}
	}

	return 0;
}