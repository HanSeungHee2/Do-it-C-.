#include <iostream>
#include <map>
#include <array>
#include <numbers>
#include <random>
#include <algorithm>
using namespace std;

class monster {
private:
	std::array<int, 10> attack_route;

	std::array<std::array<int, 10>, 10> attack_objects{};
public:
	monster(std::array<int, 10> attack_obj_route) : attack_objects{} {
		std::copy(attack_obj_route.begin(),
			attack_obj_route.end(), attack_route.begin());

		set_attack_route();
	};

	void set_attack_route() {
		for (int i = 0; i < 10; ++i) {
			attack_objects[i][attack_route[i]] = 1;
		}
	}

	void print_attack_object() {
		std::cout << "Attack objects: " << std::endl;

		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				{
					std::cout << attack_objects[i][j] << " ";
				}
			}
			std::cout << std::endl;
		}
	}
	//공격 물체의 위치[배열]를 반환.
	std::array<std::array<int, 10>, 10>& getattackobjects() {
		return attack_objects;
	}
};

class player {
private:
	std::array<int, 10> attack_route_player{};
public:
	player(std::array<int, 10> attack_player_route) {
		std::copy(attack_player_route.begin(),
			attack_player_route.end(), attack_route_player.begin());
	};
	void attack(monster& m) {
		for (int i = 0; i < 10; i++) {
			m.getattackobjects()[i][attack_route_player[i]] = 0;
		}
	}

	void print_attack_object() {
		std::cout << "Player_attack routes: " << std::endl;

		for (int i = 0; i < 10; ++i) {
			std::cout << attack_route_player[i] << " ";
		}
	}
};

int main() {
	mt19937_64 mt_rand;
	random_device rd;

	std::array<int, 10> attack_route;
	std::array<int, 10> attack_player_route;

	for (int i = 0; i < 10; ++i) {
		attack_route[i] = mt_rand() % 10;
		attack_player_route[i] = mt_rand() % 10;
		std::cout << attack_route[i] << " ";
	}

	monster fly_monster(attack_route);
	player player1(attack_player_route);

	std::cout << "몬스터의 공격 경로: " << std::endl;

	fly_monster.print_attack_object();

	std::cout << "플레이어의 공격 경로: " << std::endl;
	player1.print_attack_object();
	player1.attack(fly_monster);

	std::cout << "유효했던 공격 경로: " << std::endl;

	fly_monster.print_attack_object();
	}