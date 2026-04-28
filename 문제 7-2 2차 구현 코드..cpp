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
		health = h;
	}
	void set_power(int p) {
		power = p;
	}
	void set_speed(int s) {
		speed = s;
	}

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
class pitcher;
//포수 기본 클래스.
class catcher : public player {
public:
	catcher() : ball_own(0) {};

	int get_own_ball() {
		return ball_own;
	}

	void ball_catch();
	friend class pitcher;
private:
	int ball_own;
};

void catcher::ball_catch() {
	std::cout << "공을 잡습니다." << std::endl;
	ball_own = 1;
	
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

	int get_ball_count() {
		return ball_count;
	}

	virtual void ball_throw(catcher& our_catcher);

private:
	int ball_speed;
	static int ball_count;

};

int pitcher::ball_count = 0;

void pitcher::ball_throw(catcher& our_catcher) {
	std::cout << "직구를 던집니다." << std::endl;
	our_catcher.ball_own = 0;
	ball_count++;
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



//다양한 투수 구현 (다형성)
class starting_pitcher : public pitcher {
public:
	starting_pitcher(int b_s) : pitcher(b_s) {};
	virtual void ball_throw(catcher& our_catcher) override;


};

void starting_pitcher::ball_throw(catcher& our_catcher) {
	std::cout << "너클볼을 던집니다." << std::endl;
}

class relief_pitcher : public pitcher {
public:
	relief_pitcher(int b_s) : pitcher(b_s) {};
	virtual void ball_throw(catcher& our_catcher) override;


};

void relief_pitcher::ball_throw(catcher& our_catcher) {
	std::cout << "슬라이더를 던집니다." << std::endl;
}


class closer : public pitcher {
public:
	closer(int b_s) : pitcher(b_s) {};
	virtual void ball_throw(catcher& our_catcher) override;


};

void closer::ball_throw(catcher& our_catcher) {
	std::cout << "포크볼을 던집니다." << std::endl;
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


	for (int i = 0; i < 5; i++) {
		our_pitcher.ball_throw(our_catcher);
		our_catcher.ball_catch();
	}

	std::cout << "포수가 가지고 있는 공의 개수: " << our_catcher.get_own_ball() << std::endl;
	
	std::cout << "투수의 총 투구 수: " << our_pitcher.get_ball_count() << std::endl;

}