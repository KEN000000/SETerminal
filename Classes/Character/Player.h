/**
* @file Player.h
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "cocos2d.h"
#include "./Item/PlayerWeapon/Weapon.h"
#include "./Item/PlayerWeapon/PlayerAimPoint.h"
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

	//����׼��
	void loadAimPoint();

	//��Ӧ���̰��£��ƶ���ɫ
	void listenToKeyPress(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* unusedEvent);


	//��Ӧ�����ɿ���ֹͣ�ƶ�
	void listenToKeyRelease(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* unusedEvent);


	//��������¼�
	void listenToMouseEvent(cocos2d::Vec2, bool isPressed);


	//����
	virtual void receiveDamage(int damage);


	//��ȡ��ɫ�Ƿ�����
	bool isAlive();

	/*
	��������ʹ��Ŀǰ������������
	������
	*/
	void Attack(cocos2d::Vec2 pos, cocos2d::Vec2 dir);

	/*
	����
	������
	*/
	void dodge();


	virtual void updateFacingStatus();


	virtual void updateWalkingStatus();
	
	//���ܶ���
	void DodgeAnimeStart();
	void DodgeAnime(cocos2d::Vec2 dir);
	void DodgeAnimeEnd();


	//�л�����
	void switchWeapon();

	void getAimPointInstance();


	// ��ȡ��ɫ��ǰװ������������
	Weapon* getPrimaryWeaponInstance();


	//��ȡ��ɫ��ǰδװ���ĸ���������
	Weapon* getSecondaryWeaponInstance();

	//���½�ɫ״̬
	void update(float dt);


	bool isAttacking = false;

	float WeaponRotation = 0.0f;

protected:

	
	 
	friend class HealthBar;
	
	enum Key { W, A, S, D };

	bool keyPressed_[4]{};	

	float speedBoostFactor_ = 1;	

	bool allowMove_ = true;

	bool canDodge_ = true;

	float dodgeRate_ = 100.0f;												//���ܱ���

	float dodgeSpeedBoost_ = 3.0f;

	float dodgeTime_ = 0.1f;

	bool superBody_ = false;

	Weapon* primaryWeapon_;											//ʹ���е�����

	Weapon* secondaryWeapon_;										//������

	//���������ԡ�Ѫ����buff��
	PlayerAimPoint* ActiveAimPoint;
};

#endif // !PLAYER_H
