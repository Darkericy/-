#pragma once
#include<fstream>
class Flie
{
public:
	Flie() = delete;
	~Flie() = default;
	Flie(std::string name) :read_name(name), speed(-1), name() {};
	Flie(const Flie&) = delete;
	Flie(Flie&&) = delete;
	Flie& operator=(const Flie&) = delete;
	Flie& operator=(Flie&&) = delete;

	//���ļ��ж�ȡ���������ٶ�
	void get_nameAspeed();

	//��ѯ�ļ��Ƿ���ȷ��
	bool is_open();

	//�����ļ�
	void change_score(std::string n);

	//�����ٶ�
	int get_speed() {
		return speed;
	}

	//���Ǹ��������ṩ�Ľӿڣ����жϵ�ǰ���ĵ���û�ж���ĩβ
	bool read(std::string& score);

	//�ж�ԭ����û�д�
	bool is_openGenshin();

	//ѯ���û��Ƿ���Ҫ���ٲ���
	void change_speed();
private:
	std::ifstream read_name;
	int speed;
	std::string name;
};