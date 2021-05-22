/**
* @file Player.h
* @author ����
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "cocos2d.h"
#include "./Item/Weapon.h"
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
*/
	static Player* create(const std::string& filename);


	/**
* @brief ΪPlayer�������������
* @return ���Ƿ�ɹ�
*/
	virtual bool bindPhysicsBody();


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
* @brief ����
*/
	void dodge();


	/**
* @brief �л�����
*/
	void switchWeapon();


	/**
* @brief ��ȡ��ɫ��ǰװ������������
* @return ָ���ɫ��ǰװ�������������ָ��
*/
	Weapon* getPrimaryWeaponInstance();


	/**
* @brief ��ȡ��ɫ��ǰδװ���ĸ���������
* @return ָ���ɫ��ǰδװ���ĸ����������ָ��
*/
	Weapon* getSecondaryWeaponInstance();


	/**
* @brief ��ȡ��ɫ��ǰװ�����ӵ������Ӧ���ز��ļ���
* @return ��ɫ��ǰװ�����ӵ������Ӧ���ز��ļ������ַ���
*/
	const std::string getBulletName() const;


	/**
* @brief ���½�ɫ״̬
*/
	void update(float dt);


protected:

	enum Key{W, A, S, D};

	static constexpr int stepLength_ = 4;		//��ɫ�ƶ��ٶ�

	float x_ = 50.0, y_ = 50.0f;						//��ʼĬ��λ��

	float dodgeLength_ = 40.0f;						//���ܾ���

	bool keyPressed_[4]{};								//�����״̬��true��ʾ����

	Weapon* primaryWeapon_;					//ʹ���е�����

	Weapon* secondaryWeapon_;				//������

	std::string bulletFilename;						//��ǰװ�����ӵ�

	//���������ԡ�Ѫ����buff��

};

#endif // !PLAYER_H
