/**
* @file Weapon.h
*/

#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "cocos2d.h"
#include "../Item.h"
#include "PlayerAimPoint.h"
#include "Const/Const.h"

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

	int getCurrentMagazine();
	/*
	��װ��
	@������
	*/
	void Reload();
	void Reload(std::vector<int>& BulletStock);

	void PlayerReload(std::vector<int>& BulletStock);

	void ReloadingStatusReset();

	/*
�ָ�����������
@������
*/
	void RecoverRecoil(float Boost = 1);

	/**
*@brief ����������
* @author ����
*/
	virtual bool bindPhysicsBody();

	virtual void interact();

	void flipY(float dt) { setFlippedY(true); }

	std::string bulletFilename_;	//������ʹ�õ��ӵ�

	std::string aimPointFilename_;  //׼������

	PlayerAimPoint* MyAimPoint;
	PlayerAimPoint* ReloadAimPoint;

	PlayerAimPoint* ActiveAimPoint;

	bulletType_ TypeOfBullet = bulletType_::type762;
protected:

	float ShootingSpeed = 10;//ÿ���ܹ�attack�Ĵ���

	bool CanShoot = true;

	float BulletSpeed = 2000;

	int Accuracy = 95;//1-Accuracy����ɢ�Ƕ�

	float Recoil = 30;//׼���ϵ��̶�

	float RecoilRecover = 60;//׼�ǻظ�  

	float MaxRecoil = 250;

	int MagazineSize = 30;//��������

	int CurrentMagazine = 30;

	float ReloadTime = 2;//��װ��ʱ��

};

#endif // !__WEAPON_H__
