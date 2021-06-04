/**
* @file Weapon.h
*/

#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "cocos2d.h"
#include "../Item.h"
#include "PlayerAimPoint.h"

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

	/*
	�趨�����Ƿ�װ��Ϊ������
	@������
	*/
	void Active(bool ActivateStatus);

	/*
	��������
	@������
	*/
	void Attack(cocos2d::Vec2 pos, cocos2d::Vec2 dir);


	/*
	��װ��
	@������
	*/
	void Reload();

	void PlayerReload();

	/*
�ָ�����������
@������
*/
	void RecoverRecoil();

	/**
*@brief ����������
* @author ����
*/
	virtual bool bindPhysicsBody() { return true; }

	virtual void interact(){}

	std::string bulletFilename_;	//������ʹ�õ��ӵ�

	std::string aimPointFilename_;  //׼������

	PlayerAimPoint* MyAimPoint;
	PlayerAimPoint* ReloadAimPoint;

	PlayerAimPoint* ActiveAimPoint;

protected:



	float ShootingSpeed = 10;//ÿ���ܹ�attack�Ĵ���

	bool CanShoot = true;

	float BulletSpeed = 2000;

	int Accuracy = 97;//1-Accuracy����ɢ�Ƕ�

	float Recoil = 10;//׼���ϵ��̶�

	float RecoilRecover = 60;//׼�ǻظ�  

	int MagazineSize = 30;//��������

	int CurrentMagazine = 30;

	float ReloadTime = 2;//��װ��ʱ��

};

#endif // !__WEAPON_H__
