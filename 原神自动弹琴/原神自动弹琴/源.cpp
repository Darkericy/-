#include"Key.h"
#include"File.h"
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
		std::getline(cin, name);
		if (name == "#") {
			break;
		}
		Flie music_score(name);
		//ѭ���ж�������ļ��Ƿ���Ч��
		while (!music_score.is_open()) {
			cout << "�ļ��޷��򿪣����������룺";
			std::getline(cin, name);
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
		//��ѯ���ھ��
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
		cout << "ǰ��׼����ɣ���Ҫ������" << std::endl;
		music_score.change_speed();
		Perform p(music_score.get_speed());
		cout << "�����ʼ�� :";
		int n;
		cin >> n;
		cin.get();
		while (n < 0) {
			cout << "��������Ҫ�����0ҪС�ĵȴ�ʱ�����" << std::endl;
			cout << "�������룺";
			cin >> n;
		}
		while (n) {
			if (n > 60) {
				cout << "������Ҿ͸��������Ű�" << std::endl;
			}
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