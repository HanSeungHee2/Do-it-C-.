#include <iostream>
#include <map>
#include <array>
#include <numbers>
using namespace std;

class player {
public:
	player() {};
	player(int h, int p, int s) : health(h), power(p), speed(s) {};

	//멤버 변수 초기화 함수.(자식 클래스에서 사용)
	void set_health(int h) {
		health = h;}
	void set_power(int p) {
		power = p;}
	void set_speed(int s) {
		speed = s;}

	//멤버 변수 반환 함수. (확인용)
	int get_health() {
		return health;
	}
	int get_power() {
		return power;
	}
	int get_speed() {
		return speed;
	}

private:
	int health;
	int power;
	int speed;
};

//포수 기본 클래스.
class catcher : public player {
public:
	catcher() {};

	void ball_catch();
};

void catcher::ball_catch() {
	std::cout << "공을 잡습니다." << std::endl;
}

//투수 기본 클래스.
class pitcher : public player {
public:
	pitcher(int b_s) : ball_speed(b_s) {};

	void set_ball_speed(int b_s) {
		ball_speed = b_s;
	}
	int get_ball_speed() {
		return ball_speed;
	}

	void ball_throw(catcher& our_catcher);

private:
	int ball_speed;
};

void pitcher::ball_throw(catcher& our_catcher) {
	std::cout << "공을 던집니다." << std::endl;
}



//타자 기본 클래스.
class batter : public player {
public:
	batter() {};

	void ball_hit();
};

void batter::ball_hit() {
	std::cout << "공을 칩니다." << std::endl;
}

//코치 기본 클래스.
class coach : public player {
public:
	coach() {};

	void coaching();
};

void coach::coaching() {
	std::cout << "지시를 내립니다." << std::endl;
}

int main() {
	coach our_coach;

	pitcher our_pitcher(150);
	batter our_batter;
	catcher our_catcher;

	//멤버 기능 확인
	std::cout << "우리팀 감독이" << " ";
	our_coach.coaching();
	std::cout << std::endl;

	std::cout << "우리팀 투수가" << " 우리팀 포수에게 " << " ";
	our_pitcher.ball_throw(our_catcher);
	std::cout << std::endl;

	std::cout << "우리팀 포수가" << " ";
	our_catcher.ball_catch();
	std::cout << std::endl;

	std::cout << "구속은 " << our_pitcher.get_ball_speed() << "km 입니다." << std::endl;

	std::cout << "우리팀 타자가" << " ";
	our_batter.ball_hit();
	std::cout << std::endl;
}