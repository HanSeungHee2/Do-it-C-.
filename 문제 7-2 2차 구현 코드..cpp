#include <iostream>
#include <map>
#include <array>
#include <numbers>
using namespace std;

struct item_info {;
	int price;
	int item_number;
};

class person;

class vendingMachine {
private:
	std::map<std::string, item_info> items;

public:
	vendingMachine(std::string name);
	void item_output() {};

	int get_price(std::string name) {
		return items[name].price;
	}
	int get_item_number(std::string name) {
		return items[name].item_number;
	}
}

vendingMachine::vendingMachine(const std::map<std::string, item_info>& info) {
	items = info;
}

void VendingMachine::item_output(std::string name) {

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

	vm.get_item_number("콜라");
	vm.get_item_number("사이다");
	vm.get_item_number("환타");

	vm.get_price("콜라");
	vm.get_price("사이다");
	vm.get_price("환타");
	return 0;
}
	
	
