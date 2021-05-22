/**
* @file Player.h
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
	void dodge();


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

	static constexpr int stepLength_ = 4;								//��ɫ�ƶ��ٶ�

	float x_ = 50.0, y_ = 50.0f;												//��ʼĬ��λ��

	static constexpr float dodgeLength_ = 40.0f;					//���ܾ���

	bool keyPressed_[4]{};														//�����״̬��true��ʾ����

	Weapon* primaryWeapon_;											//ʹ���е�����

	Weapon* secondaryWeapon_;										//������

	std::string bulletFilename;												//��ǰװ�����ӵ�

	//���������ԡ�Ѫ����buff��

};

#endif // !PLAYER_H
