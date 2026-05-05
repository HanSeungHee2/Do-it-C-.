#include <iostream>
#include <map>
#include <array>
#include <numbers>
#include <random>
#include <algorithm>
using namespace std;

class character {
protected:
	int hp;
	int power;
public:
	character(int h, int p) : hp(h), power(p) {};
	int get_hp() { return hp; }
	int get_power() { return power; }

};

class monster;  // ⭐ 전방 선언 (**********)

class player : public character {
public:
	player(int h, int p) : character(h, p) {};

	void get_hp_damage(int _damage) {
		hp -= _damage;
	}

	void get_power_damage(int _damage) {
		power -= _damage;
	}

	void attack(monster* target_monster); // 선언만. (아직 몬스터 클래스가 정의가 안되었다.)
};
class monster : public character {
public:
	monster(int h, int p) : character(h, p) {};

	virtual void get_damage(int _damage) = 0;

	void attack(player* target_player) {
		int damage = power;
		target_player->get_hp_damage(damage);
	}

	virtual void attack_special(player* target_player) = 0;
};

void player::attack(monster* target_monster) {
	int damage = power;
	target_monster->get_damage(damage);
}

class monster_c : public monster {
private:
	static int total_count;
public:
	monster_c(int h, int p) : monster(h, p) {}
	virtual void get_damage(int _damage) override;
	virtual void attack_special(player* target_player) override;

	void set_total_count() {
		total_count++;
	}

	int get_total_count() {
		return total_count;
	}
};


int monster_c::total_count = 0;

void monster_c::get_damage(int _damage) {
	if (total_count % 60 >= 2) {
		hp -= _damage;
	}
}

void monster_c::attack_special(player* target_player) {
	int hp_damage = power;
	int power_damage = power;
	target_player->get_hp_damage(hp_damage);
	target_player->get_power_damage(power_damage);
}

int main() {
	player player1(200, 300);
	monster_c boss_monster(30000, 1);

	while (boss_monster.get_hp() > 0 && player1.get_hp() > 0) {
		std::cout << "count: " << boss_monster.get_total_count() << ", ";
		player1.attack(&boss_monster);
		boss_monster.attack_special(&player1);
		boss_monster.set_total_count();

		std::cout << "boss_hp: " << boss_monster.get_hp() << std::endl;
		std::cout << std::endl;
	}
}