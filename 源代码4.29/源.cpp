#include"Key.h"
#include"Flie.h"
#include<fstream>
#include<iostream>
//F:\����\����\С����.txt
int main() {
	using std::cout;
	using std::cin;
	cout << "������������������κη�����׶�����#�ַ�����ֹ����" << std::endl;
	while (1) {
		std::string name;
		cout << "�������ļ�·����";
		cin >> name;
		if (name == "#") {
			break;
		}
		Flie music_score(name);
		while (!music_score.is_open()) {
			cout << "�ļ��޷��򿪣����������룺";
			cin >> name;
			if (name == "#") {
				break;
			}
			music_score.change_score(name);
		}
		if (!music_score.is_open()) {
			break;
		}
		try {
			music_score.get_nameAspeed();
		}
		catch (int& e) {
			break;
		}
		catch (std::string& e) {
			continue;
		}
		catch (std::exception& e) {
			cout << e.what();
			continue;
		}
		while (!music_score.is_openGenshin()) {
			cout << "��⵽ԭ��δ�򿪣���򿪺����������ַ�����";
			std::string flag;
			cin >> flag;
			if (flag[0] == '#') {
				break;
			}
		}
		if (!music_score.is_openGenshin()) {
			break;
		}
		Perform p(music_score.get_speed());
		cout << "ǰ��׼����ɣ���������࿪ʼ" << std::endl;
		int n = 3;
		while (n) {
			cout << n-- << std::endl;
			Sleep(1000);
		}
		try {
			p.play(music_score);
		}
		catch (std::exception& e) {
			cout << e.what();
			continue;
		}
	}
	return 0;
}