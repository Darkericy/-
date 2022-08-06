#pragma once
#include<Windows.h>
#include<vector>
#include<string>
#include<stdexcept>
#include<unordered_set>
class Flie;
class Keyboard
{
public:
	Keyboard() :name({ 'Z','X','C','V','B','N','M','A','S','D','F','G','H','J','Q','W','E','R','T','Y','U' }) {};
	//�趨��Ļ�������
	~Keyboard() = default;
	Keyboard(const Keyboard&) = delete;
	Keyboard(Keyboard&&) = delete;
	Keyboard& operator=(const Keyboard&) = delete;
	Keyboard& operator=(Keyboard&&) = delete;

	//����������������������
	void push(char key);

	//�������ӿ�
	void three_connect(std::string group, int time);

	//�����ӿ�
	void arpeggio(std::string group);
private:
	std::unordered_set<char> name;
};
class Perform {
public:
	Perform() = delete;
	Perform(int t) :time(60000 / t), k() {};
	~Perform() = default;
	Perform(const Perform&) = delete;
	Perform(Perform&&) = delete;
	Perform& operator = (const Perform&) = delete;
	Perform& operator = (Perform&&) = delete;

	//���ຯ��
	void play(Flie& music_score);
private:
	int time;
	Keyboard k;
};