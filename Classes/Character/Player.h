/**
* @file Player.h
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "cocos2d.h"
#include "./Item/PlayerWeapon/Weapon.h"
#include "Character.h"
#include <string>

/**
*@brief ��ɫ��
*/

class Player : public Character
{
public:

	//����һ��Playerʵ��
	static Player* create(const std::string& filename);


	//ΪPlayer�������������
	virtual bool bindPhysicsBody();


	//��Ӧ���̰��£��ƶ���ɫ
	void listenToKeyPress(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* unusedEvent);


	//��Ӧ�����ɿ���ֹͣ�ƶ�
	void listenToKeyRelease(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* unusedEvent);


	//����
	void getInjured(int damage);


	//��ȡ��ɫ�Ƿ�����
	bool isAlive();


	//��ɫ����
	void die();


	//����
	void dodge();
	
	//���ܶ���
	void DodgeAnimeStart();
	void DodgeAnime(cocos2d::Vec2 dir);
	void DodgeAnimeEnd();

	//�л�����
	void switchWeapon();


	// ��ȡ��ɫ��ǰװ������������
	Weapon* getPrimaryWeaponInstance();


	//��ȡ��ɫ��ǰδװ���ĸ���������
	Weapon* getSecondaryWeaponInstance();


	//��ȡ��ɫ��ǰװ�����ӵ������Ӧ���ز��ļ���
	const std::string getBulletName() const;


	//���½�ɫ״̬
	void update(float dt);


protected:

	enum Key{W, A, S, D};

	 int moveSpeed_ = 400;													//��ɫ�ƶ��ٶ�

	 float speedBoostFactor = 1;

	 bool allowMove = true;

	 bool canDodge = true;

	float dodgeRate_ = 100.0f;												//���ܱ���

	float dodgeSpeedBoost = 3.0f;

	float dodgeTime = 0.1f;

	bool superBody = false;

	bool keyPressed_[4]{};														//�����״̬��true��ʾ����

	int health_ = 3;																//����ֵ

	bool isAlive_ = true;														//�Ƿ���

	float shield = 0.5f;															//���׼�����

	Weapon* primaryWeapon_;											//ʹ���е�����

	Weapon* secondaryWeapon_;										//������

	std::string bulletFilename;												//��ǰװ�����ӵ�

	//���������ԡ�Ѫ����buff��

};

#endif // !PLAYER_H
