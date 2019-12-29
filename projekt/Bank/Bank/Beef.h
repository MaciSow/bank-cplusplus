//#ifndef USER_H
//#define USER_H
//
//#include <iostream>
//#include <string>
//#include <fstream>
//using namespace std;
//
//class User
//{
//public:
//	User() {
//		this->name = "Anonim";
//		this->surname = "";
//		this->age = 1;
//	}
//
//	User(string name, string surname, int age)
//	{
//		this->name = name;
//		this->surname = surname;
//		this->age = age;
//	}
//
//	void SayHello() {
//		cout << "My name is " << name << " " << surname << " " << age << "\n";	
//	}
//
//	void SayGodbye() {
//		cout << "goodbye" << age;
//	}
//
//	void SetName(string name1) {
//		name = name1;
//	}
//	void SetSurname(string surname) {
//		this->surname = surname;
//	}
//
//	void SetAge(int a) {
//		if (a > 0) {
//			age = a;
//		}
//		else {
//			cout << "powrot do";
//		}
//	}
//
//	static User createUserFromFile() {
//		User us;
//
//		ifstream File;
//		File.open("../user.txt", ios::in);
//
//		if (!File.is_open()) {
//			cout << "Nie ma pliku" << endl;
//			return us;
//		}
//
//		int i = 0;
//		string tmp[3];
//		string line;
//
//		while (getline(File, line)) {
//			tmp[i] = line;
//			i++;
//		}
//
//		us.SetName(tmp[0]);
//		us.SetSurname(tmp[1]);
//		us.SetAge(stoi(tmp[2]));
//
//		File.close();
//
//		return us;
//	}
//
//private:
//	string name;
//	string surname;
//	int age;
//};
//
//#endif