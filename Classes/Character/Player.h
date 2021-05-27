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

	/**
* @brief ����һ��Playerʵ��
* @param Playerʵ����Ӧ���ز��ļ���
* @return ָ���Playerʵ����ָ��
* @author ����
*/
	static Player* create(const std::string& filename);


	/**
* @brief ΪPlayer�������������
* @return ���Ƿ�ɹ�
* @author ����
*/
	virtual bool bindPhysicsBody();


	/**
* @brief ��Ӧ���̰��£��ƶ���ɫ
* @param ���¼�����
* @author ����
*/
	void listenToKeyPress(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* unusedEvent);


	/**
* @brief ��Ӧ�����ɿ���ֹͣ�ƶ�
* @param �ɿ�������
* @author ����
*/
	void listenToKeyRelease(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* unusedEvent);


	/**
* @brief ����
* @author ����
*/
	void getInjured(int damage);


	/**
* @brief ��ȡ��ɫ�Ƿ�����
* @return ���״̬
* @author ����
*/
	bool isAlive();


	/**
* @brief ��ɫ����
* @author ����
*/
	void die();


	/**
* @brief ����
* @author ����
*/	
	void dodge();
	
	//���ܶ���
	void DodgeAnimeStart();
	void DodgeAnime(cocos2d::Vec2 dir);
	void DodgeAnimeEnd();

	/**
* @brief �л�����
* @author ����
*/
	void switchWeapon();


	/**
* @brief ��ȡ��ɫ��ǰװ������������
* @return ָ���ɫ��ǰװ�������������ָ��
* @author ����
*/
	Weapon* getPrimaryWeaponInstance();


	/**
* @brief ��ȡ��ɫ��ǰδװ���ĸ���������
* @return ָ���ɫ��ǰδװ���ĸ����������ָ��
* @author ����
*/
	Weapon* getSecondaryWeaponInstance();


	/**
* @brief ��ȡ��ɫ��ǰװ�����ӵ������Ӧ���ز��ļ���
* @return ��ɫ��ǰװ�����ӵ������Ӧ���ز��ļ������ַ���
* @author ����
*/
	const std::string getBulletName() const;


	/**
* @brief ���½�ɫ״̬
* @author ����
*/
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
