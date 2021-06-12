/**
* @file Player.h
*/

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include "./Item/PlayerWeapon/Weapon.h"
#include "Character.h"
#include "Item/PlayerWeapon/PlayerAimPoint.h"
#include <string>
#include "Const/Const.h"
#include "Item/Medkit/Medkit.h"


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
	virtual void receiveDamage(int damage);

	virtual void die();

	virtual void updateFacingStatus();
	virtual void updateWalkingStatus();

	

	void dodge();
	void DodgeAnimeStart();
	void DodgeAnime(cocos2d::Vec2 dir);
	void DodgeAnimeEnd();


	Item* getInteractItem();
	void setInteractItem(Item* interactItem);


	//�л�����
	void switchWeapon();


	// ��ȡ��ɫ��ǰװ������������
	Weapon* getPrimaryWeaponInstance();
	void setPrimaryWeaponInstance(Weapon* weapon);
	//��ȡ��ɫ��ǰδװ���ĸ���������
	Weapon* getSecondaryWeaponInstance();
	void setSecondaryWeaponInstance(Weapon* weapon);

	void abandonPrimaryWeapon();

	//��ȡ��ɫ��ǰװ�����ӵ������Ӧ���ز��ļ���
	const std::string getBulletName() const;


	int getMedkitNum();
	bool isMedkitFull();
	std::stack<Medkit*>* getMedkitBagInstance();

	void useMedkit();


	//���½�ɫ״̬
	void update(float dt);


	/*
��������ʹ��Ŀǰ������������
������
*/
	virtual void attack(cocos2d::Vec2 pos, cocos2d::Vec2 dir);

	void getAimPointInstance();
	void removeAimPoint(Weapon* weapon);

	bool isAttacking = false;


	std::vector<int> bulletStock_;

protected:

	//�ƶ�
	enum Key { W, A, S, D };
	bool keyPressed_[4]{};	
	float speedBoostFactor_ = 1;
	bool allowMove_ = true;

	//��������
	bool canDodge_ = true;
	float dodgeRate_ = 100.0f;												
	float dodgeSpeedBoost_ = 3.0f;
	float dodgeTime_ = 0.1f;

	bool superBody_ = false;

	//��������
	Item* interactItem_ = nullptr;

	//����
	Weapon* primaryWeapon_;											//ʹ���е�����
	Weapon* secondaryWeapon_;										//������
	float weaponRotation_ = 0.0f;
	float recoilRecoverBoost_ = 100;


	std::string bulletFilename_;												//��ǰװ�����ӵ�

	//ҽ�ư�
	std::stack<Medkit*> medkit_;
	int medkitMaxNum_ = MEDKIT_MAX_NUM;

	int bulletMaxNum_ = 180;
};

#endif // !__PLAYER_H__
