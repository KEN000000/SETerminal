/**
* @file Weapon.h
*/

#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "cocos2d.h"

/**
*@brief ������
*/

class Weapon : public cocos2d::Sprite
{
public:

	/**
* @brief ����һ��Weaponʵ��
* @param Weaponʵ����Ӧ���ز��ļ���
* @return ָ���Weaponʵ����ָ��
*/
	static Weapon* create(const std::string& filename);

	
protected:

	//���������٣�������ʽ��

};

#endif // !__WEAPON_H__
