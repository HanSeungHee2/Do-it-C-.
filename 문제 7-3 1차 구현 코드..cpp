#include <iostream>
#include <map>
#include <array>
#include <numbers>
using namespace std;

struct item_info {
	;
	int price;
	int item_number;
};

class vendingMachine {
private:
	std::map<std::string, item_info> items;

public:
	vendingMachine(const std::map<std::string, item_info>& info);

	void item_output(std::string name);

	int get_price(std::string name) {
		return items[name].price;
	}
	int get_item_number(std::string name) {
		return items[name].item_number;
	}
};

vendingMachine::vendingMachine(const std::map<std::string, item_info>& info) {
	items = info;
}

void vendingMachine::item_output(std::string name) {

	std::cout << name << "이 출력되었습니다." << std::endl;

	items[name].item_number--;
}

int main() {
	std::map<std::string, item_info> info = {
		{"콜라", {1000, 5}},
		{"사이다", {1200, 3}},
		{"환타", {1100, 4}}
	};
	vendingMachine vm(info);

	vm.item_output("콜라");
	vm.item_output("사이다");
	vm.item_output("환타");

	std::cout << "콜라 남은 개수: " << vm.get_item_number("콜라") << std::endl;
	std::cout << "사이다 남은 개수: " << vm.get_item_number("사이다") << std::endl;
	std::cout << "환타 남은 개수: " << vm.get_item_number("환타") << std::endl;

	std::cout << "콜라 가격: " << vm.get_price("콜라") << std::endl;
	std::cout << "사이다 가격: " << vm.get_price("사이다") << std::endl;
	std::cout << "환타 가격: " << vm.get_price("환타") << std::endl;
	return 0;
}
