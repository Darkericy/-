#include "Flie.h"
#include<iostream>
#include<Windows.h>
void Flie::get_nameAspeed() {
	std::string name;
	int speed;
	read_name >> name >> speed;
	if (speed <= 0) {
		std::cout << "�ҵĹԹԣ��ٶ�Ϊ" << speed << "����ô����" << std::endl;
		std::cout << "�����������ٰ��ٶȸ�����һ�㣬��ͷ����һ�Σ�";
		std::string e;
		throw e;
	}
	if (name.size() >= 200) {
		std::cout << "��ʲôë������������ô�ᳬ��200���ַ�����ʲôë����" << std::endl;
		std::cout << "��������";
		std::string e;
		throw e;
	}
	std::cout << "��ȷ�ϣ�" << std::endl;
	std::cout << "�������� " << name << std::endl;
	std::cout << "�����ٶȣ�" << speed << std::endl;
	std::cout << "�Ƿ���ȷ����ȷ������Y������������N��";
	char flag;
	std::cin >> flag;
	if (flag == '#') {
		int e = 0;
		throw e;
	}
	while (flag != 'N' && flag != 'Y') {
		std::cout << "ֻ����Y����N�����֪����ҪΪ�����ֵͼ������д���д�����" << std::endl;
		std::cout << "�ú����룺 ";
		std::cin >> flag;
		if (flag == '#') {
			int e = 0;
			throw e;
		}
	}
	if (flag == 'N') {
		std::runtime_error e("�Ǿʹ�ͷ���~");
		throw e;
	}
	this->name = name;
	this->speed = (60000 / speed);
}
bool Flie::is_open() {
	if (!read_name.is_open()) {
		return false;
	}
	return true;
}
void Flie::change_score(std::string n) {
	read_name.open(n);
}
bool Flie::read(std::string& score) {
	if (read_name >> score) {
		return true;
	}
	return false;
}
bool Flie::is_openGenshin() {
	if (!FindWindowA(nullptr,"ԭ��")) {
		return false;
	}
	return true;
}