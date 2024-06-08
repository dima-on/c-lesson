#include <iostream>

using namespace std;

void firstlesson();
void switch_case_sk();
void random_num();

#include <string>
void string_lesson();

void for_lesson();
void array_lesson();
void memory_array();
void pointer_lesson();

#include <fstream>
void file_W_R();

void struct_lesson();
void enum_lesson();

#include <cmath>
void cmath_lesson();

void create_class();
void friend_function();
void friend_class();
void perent_class();
void template_function();
void template_class();

int main() {
	return 0;
}

void firstlesson() {
	//first lesson:
		setlocale(LC_ALL, "RU");
		std::cout << "hello word\n";
		std::cout << "привет";

	//second lesson:
		int num = 0;
		std::cin >> num;
		std::cout << "hi " << num;
	// or = ||
	// and = &&
}

void switch_case_sk() {
	int num = 0;
	switch (num) {

	case 5:
		num = 6; break;

	case 10:
		num = 1; break;

	default:
		num = 0;
		break;

	}
}

void random_num() {
	srand(time(NULL));
	// 1 = start
	// 20 = end
	int res = 1 + rand() % 20;
}

void string_lesson() {
	int num1 = 10;
	string s = "hi";
	s += " " + to_string(num1);
}

void for_lesson() {
	for (int i = 0; i < 10; i++) {
			cout << i;
	}

	// do выполняется даже если цыкл не верный 
	int k = 100;
	do {
		k -= 10;
		cout << k << " ";
	} while (k <= 90 && k > 0);
}

void array_lesson() {
	int num[3] = {1, 5, 2};
	

	int matrix[3][2] = 
	{
		{10, 2},
		{2, 3},
		{3, 4} 
	};
}

void memory_array() {
	int* arr = new int[3];
	arr[2] = 10;
	cout << arr[2];
	delete[] arr;
}

void pointer_lesson() {
	int num[] = { 100, 23, 12, 84 };
	int* ptr_num = &num[0];

	int min = *ptr_num;
	for (int i = 0; i < 4; i++) {
		if (*(ptr_num + i) < min) {
			min = *(ptr_num + i);
		}
	}
	cout << min;
}

void file_W_R() {
	ofstream file1("test.txt", ios_base::out);
	if (file1.is_open()) {
		cout << "dff";
		file1 << "hiii";
		file1.close();
	}

	ifstream file("test.txt");
	if (file.is_open()) {
		string test;
		file >> test;
		cout << test;
		file.close();
	}
}

struct Point
{
	int x, y;
};
struct Tree
{
	int num;
	string name;
	bool is_be;
	float hp;

	Point place;

	void get_info() {
		cout << num << " " << is_be << " " << hp;
	}

	string get_full() {
		string s;
		s = to_string(num) + " " + to_string(is_be) + " " + to_string(hp);
		return s;
	}
};
void struct_lesson() {
	Tree test_struct;
	test_struct.hp = 13.12;
	test_struct.is_be = true;
	test_struct.name = "Dima";
	test_struct.get_info();
	test_struct.place.x = 10;
	cout << test_struct.get_full();
}

enum Gun;
struct have_gun
{
	Gun gun_in_hands;
	void print_gun() {
		cout << gun_in_hands;
	}
};
enum Gun {
	ak_47,
	mini_gun,
	rocket
};
void enum_lesson() {
	have_gun st;
	st.gun_in_hands = Gun::mini_gun;
	st.print_gun();
}

void cmath_lesson() {
	//степень
	pow(2, 3);

	//модуль
	abs(-3);

	//sin cos
	sin(30);
	cos(30);

	//коринь
	sqrt(16);

	//округление
	ceil(1.5f);
	floor(1.5f);
	round(1.4f);

}

class Buildings {
private:
	int year;
	float hight;
	string name;

public:

	Buildings(string name_data, float hight_data, int year_data) {
		this->name = name_data;
		this->hight = hight_data;
		this->year = year_data;
	}
	~Buildings() {
		cout << "\n" << "del";
	}

	void get_info() {
		string info = to_string(this->year) + " " + to_string(this->hight) + " " + this->name;
		cout << info;
	}
};
void create_class() {
	Buildings school("dtl", 125.5f, 31);
	school.get_info();
}

class Car;
class Person {
private:
	string name;
public:
	Person(string name) {
		this->name = name;
	}
	~Person() {

	}
	friend void info_car(Car& car, Person& person);
};
class Car {
private:
	string name;
public:

	Car(string name) {
		this->name = name;
	}
	~Car() {

	}
	friend void info_car(Car& car, Person& person);

};
void info_car(Car& car, Person& person) {
	cout << car.name << " " << person.name;
}
void friend_function() {
	


	Person per("Dima");
	Car porche("porche");


	info_car(porche, per);
}

class New_Person;
class Dog {
private: 
	int hp = 100;
public:
	friend class New_Person;
};
class New_Person {
public:

	int damDog(Dog& dog, int Dam) {
		dog.hp -= Dam;
		return dog.hp;
	}
};
void friend_class() {
	Dog emma;
	New_Person dima;
	cout << dima.damDog(emma, 50);
}

class PC {
private:
	string OC;
	int year;

public:
	PC(string OC, int year) {
		this->OC = OC;
		this->year = year;
	}
	void get_bais_info() {
		cout << OC << " " << year;
	}

};
class Laptop : public PC {
private:
	int size;
public:
	Laptop(string OC, int year, int size) : PC(OC, year) {
		this->size = size;
	}
	void get_bais_info() {
		PC::get_bais_info();
		cout << " " << size;
	}
};
void perent_class() {
	Laptop comp("Windows", 2015, 20);
	PC mac("mac", 2020);
	mac.get_bais_info();
	comp.get_bais_info();
}

template<typename T, typename K>
void print(T word, K yer) {
	cout << word << " " << yer << "\n";
}
void template_function() {
	print<int, string>(1, "ds");
	print<float, string>(1.5f, "ht");
	print<string, int>("ddad", 1);
}

template<class T>
class Tem {
private:
	T lab;
public:
	Tem(T lab) {
		this->lab = lab;
	}
};
void template_class(){
	Tem<int> oclock(1);

}