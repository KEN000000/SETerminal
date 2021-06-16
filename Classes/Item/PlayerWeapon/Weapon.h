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

	int getAccuracy();
	void setAccuracy(int accuracy);

	float getRecoil();
	void setRecoil(float recoil);

	float getRecoiRecoverl();
	void setRecoilRecover(float recoilRecover);

	float getReloadTime();
	void setReloadTime(float reloadTime);

	int getMagazineSize();
	void setMagazineSize(int magSize);

	/**
* @brief ����һ��Weaponʵ��
* @param Weaponʵ����Ӧ���ز��ļ���
* @return ָ���Weaponʵ����ָ��
* @����
*/
	static Weapon* create(const std::string& filename);
	static Weapon* create(weaponType_ type);
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

	void Reset();
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

	PlayerAimPoint* getMyAimPoint();
	void setMyAimPoint(PlayerAimPoint*);

	PlayerAimPoint* getReloadAimPoint();
	void setReloadAimPoint(PlayerAimPoint*);

	std::string bulletFilename_;	//������ʹ�õ��ӵ�

	std::string aimPointFilename_;  //׼������

	PlayerAimPoint* ActiveAimPoint;

	bulletType_ TypeOfBullet = bulletType_::type762;

	float BulletDamage = 12;

	float BulletSpeed = 2000;



protected:

	int Accuracy = 95;//1-Accuracy����ɢ�Ƕ�

	float Recoil = 15;//׼���ϵ��̶�

	float RecoilRecover = 60;//׼�ǻظ�  

	int MagazineSize = 30;//��������

	float ReloadTime = 2;//��װ��ʱ��

	float ShootingSpeed = 10;//ÿ���ܹ�attack�Ĵ���

	bool CanShoot = true;

	float MaxRecoil = 250;

	int CurrentMagazine = 30;

	PlayerAimPoint* MyAimPoint;
	PlayerAimPoint* ReloadAimPoint;

};

#endif // !__WEAPON_H__
