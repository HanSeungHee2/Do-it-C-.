// ConsoleApplication4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>



int main() {

	char str[] = "Hello";
	char *str_ptr = str;

	std::cout << "str_ptr: " << str_ptr << std::endl; //str_ptr: 배열주소 
	//배열 주소가 나오지않는다. str_ptr은 시작메모리주소를 저장하는 포인터변수지만 char *형식의 데이터이다.
	//컴파일러에서 std::cout으로 char형식 포인터 변수를 출력할때는 문자열로 출력한다. 즉 시작 메모리주소를 보고
	// /0(끝 신호)가 나올때까지 출력하는 거로 해석한다.
	//즉 형변환이 필요한데 이는 (변경 형식)str_ptr로 하면된다.

	//ex:

	std::cout << "void* str_ptr: " << (void*)str_ptr << std::endl; //str_ptr: 배열주소

	std::cout << "*str_ptr: " << *str_ptr << std::endl; //*str_ptr: H (맞음. 
	// str_ptr은 str의 시작메모리를 저장하는 포인터변수임 이를 역참조하면 시작문자인 H가 나온다.)
	

	int int_val = 10;
	int* int_ptr = &int_val;
	
	std::cout << "int_ptr: " << int_ptr << std::endl; //int_ptr: 배열주소 (맞다.)
	std::cout << "*int_ptr: " << *int_ptr << std::endl; //*int_ptr: 10 (맞다.)

}