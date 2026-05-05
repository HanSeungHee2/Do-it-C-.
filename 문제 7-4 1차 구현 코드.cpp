#include <iostream>
#include <map>
#include <array>
#include <numbers>
#include <random>
#include <algorithm>
using namespace std;

class player {
private:
	int hp = 100;
	int power = 10;
public:
	player(int h, int p) : hp(h), power(p) {};

	int get_hp() { return hp; };
	int get_power() { return power; };
	void attack(monster& target_monster) {
		int damage = power;
		target_monster.get_damage(damage);
	}
	void get_hp_damage(int _damage){
		hp -= _damage;
	}
	void get_power_damage(int _damage) {
		power -= _damage;
	}
};

class monster : protected player {
public:
	monster(int h, int p) : player(h, p) {}

	int get_hp() { return hp; };
	int get_power() { return power; };

	virtual void get_damage(int _damage);
	void attack(player& target_player) {};
	virtual void attack_special(player& target_player);
};

class monster_c : protected monster{
private:
	static int total_count;
public:
	monster_c(int h, int p) : monster(h, p) {}
	virtual void attack_special(player& target_player) override;
	virtual void get_damage(int _damage) override;
	int get_total_count() { return total_count; }
};

int monster_c::total_count = 0;

void monster_c::get_damage(int _damage) {
	if (2 <= total_count % 60) {
		hp -= _damage;
	}
	
	total_count++;
}

void monster_c::attack_special(player& target_player) {
	int hp_damage = power;
	int power_damage = power;
	target_player.get_hp_damage(hp_damage);
	target_player.get_power_damage(power_damage);
}

int main() {
	player player1(200, 300);
	monster_c boss_monster(30000, 1);

	while (boss_monster.get_hp() > 0 && player1.get_hp() > 0) {
		player1.attack(boss_monster);
		boss_monster.attack_special(player1);
		boss_monster.total_count++;

		std::cout << "count: " << boss_monster.get_total_count() << ", boss_hp: " << boss_monster.get_hp() << std::endl;
		std::cout << std::endl;
	}
}