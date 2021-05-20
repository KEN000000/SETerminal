/**
* @file Player.h
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "cocos2d.h"
#include "Weapon.h"
#include <string>

/**
*@brief ��ɫ��
*/

class Player : public cocos2d::Sprite
{
public:

	/**
* @brief ����һ��Playerʵ��
* @param Playerʵ����Ӧ���ز��ļ���
* @return ָ���Playerʵ����ָ��
*/
	static Player* create(const std::string& filename);


	/**
* @brief ��Ӧ���̰��£��ƶ���ɫ
* @param ���¼�����
*/
	void listenToKeyPress(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* unusedEvent);


	/**
* @brief ��Ӧ�����ɿ���ֹͣ�ƶ�
* @param �ɿ�������
*/
	void listenToKeyRelease(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* unusedEvent);


	/**
* @brief ��ȡ��ɫ��ǰװ������������
* @return ָ���ɫ��ǰװ�������������ָ��
*/
	Weapon* getWeaponInstance();


	/**
* @brief ��ȡ��ɫ��ǰװ�����ӵ������Ӧ���ز��ļ���
* @return ��ɫ��ǰװ�����ӵ������Ӧ���ز��ļ������ַ���
*/
	const std::string getBulletName();


	/**
* @brief ���½�ɫ״̬
*/
	void update(float dt);


protected:

	enum Key{W, A, S, D};

	static constexpr int stepLength_ = 4;		//��ɫ�ƶ��ٶ�

	float x_ = 50.0, y_ = 50.0f;						//��ʼĬ��λ��

	bool keyPressed_[4]{};								//�����״̬��true��ʾ����

	Weapon* weapon_;									//��ǰװ��������

	std::string bulletFilename;						//��ǰװ�����ӵ�

	//���������ԡ�Ѫ����buff��

};

#endif // !PLAYER_H
