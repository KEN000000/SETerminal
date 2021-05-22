/**
* @file Weapon.h
*/

#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "cocos2d.h"
#include "Item.h"

/**
*@brief ������
*/

class Weapon : public Item
{
public:

	virtual ~Weapon() = default;


	/**
* @brief ����һ��Weaponʵ��
* @param Weaponʵ����Ӧ���ز��ļ���
* @return ָ���Weaponʵ����ָ��
* @����
*/
	static Weapon* create(const std::string& filename);


	/**
*@brief ����������
* @author ����
*/
	virtual bool bindPhysicsBody() { return true; }

	
protected:


	//���������٣�������ʽ��

};

#endif // !__WEAPON_H__
