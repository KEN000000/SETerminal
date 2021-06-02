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


	//��������¼�
	void listenToMouseEvent(cocos2d::Vec2, bool isPressed);


	//����
<<<<<<< Updated upstream
	void getInjured(int damage);
=======
	virtual void receiveDamage(int damage);
>>>>>>> Stashed changes


	//��ȡ��ɫ�Ƿ�����
	bool isAlive();

<<<<<<< Updated upstream

	//��ɫ����
	void die();

	void playMoveAnimate();

	//����
	void dodge();
=======
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
>>>>>>> Stashed changes
	
	//���ܶ���
	void DodgeAnimeStart();
	void DodgeAnime(cocos2d::Vec2 dir);
	void DodgeAnimeEnd();

<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
	//�л�����
	void switchWeapon();


	// ��ȡ��ɫ��ǰװ������������
	Weapon* getPrimaryWeaponInstance();


	//��ȡ��ɫ��ǰδװ���ĸ���������
	Weapon* getSecondaryWeaponInstance();

<<<<<<< Updated upstream

	//��ȡ��ɫ��ǰװ�����ӵ������Ӧ���ز��ļ���
	const std::string getBulletName() const;


=======
>>>>>>> Stashed changes
	//���½�ɫ״̬
	void update(float dt);


	bool isAttacking = false;

protected:

<<<<<<< Updated upstream
	cocos2d::Vec2 FacingDir;

	enum PlayerStatus{
		idle_back, 
		idle_front,
		idle_left,
		idle_right,
		walk_back,
		walk_front,
		walk_left,
		walk_right
	};

	cocos2d::Animate* walkUp;
	cocos2d::Animate* walkDown;
	cocos2d::Animate* walkLeft;
	cocos2d::Animate* walkRight;
	cocos2d::Animate* idleUp;
	cocos2d::Animate* idleDown;
	cocos2d::Animate* idleLeft;
	cocos2d::Animate* idleRight;
	cocos2d::Animate* animateBeingPlayed;

	int Status;

	int preStatus;

	enum Key{W, A, S, D};

	 int moveSpeed_ = 400;													//��ɫ�ƶ��ٶ�

	 float speedBoostFactor = 1;

	 bool allowMove = true;

	 bool canDodge = true;

	float dodgeRate_ = 100.0f;												//���ܱ���

	float dodgeSpeedBoost = 3.0f;

	float dodgeTime = 0.1f;

	bool superBody = false;

	bool keyPressed_[5]{};														//�����״̬��true��ʾ����

	int health_ = 3;																//����ֵ

	bool isAlive_ = true;														//�Ƿ���

	float shield = 0.5f;															//���׼�����

	Weapon* primaryWeapon_;											//ʹ���е�����

	Weapon* secondaryWeapon_;										//������

	std::string bulletFilename;												//��ǰװ�����ӵ�
=======
	

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
>>>>>>> Stashed changes

	//���������ԡ�Ѫ����buff��

};

#endif // !PLAYER_H
