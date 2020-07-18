#include <iostream>

using namespace std;

typedef struct {

	int hp, mp, attack, defense;

}Character;

int getStatus(Character input, Character item) {

	int ret = 0;

	int hp = input.hp + item.hp;
	int mp = input.mp + item.mp;
	int attack = input.attack + item.attack;
 
	if (hp < 1) hp = 1;
	if (mp < 1) mp = 1;
	if (attack < 0) attack = 0;

	ret = hp + mp * 5 
		+ attack * 2 + (input.defense + item.defense) * 2;

	return ret;
}

int main() {

	int t;
	cin >> t;

	while (t--) {

		Character ch, item;
		cin >> ch.hp >> ch.mp >> ch.attack >> ch.defense;
		cin >> item.hp >> item.mp >> item.attack >> item.defense;

		cout << getStatus(ch, item) << "\n";

	}



	return 0;
}