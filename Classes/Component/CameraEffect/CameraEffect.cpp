#include "cocos2d.h"
#include "CameraEffect.h"

CameraEffect* CameraEffect::create(cocos2d::Scene* scene)
{
	auto camera = new(std::nothrow) CameraEffect();
	if (camera == nullptr)
	{
		return nullptr;
	}

	auto sizeOfWin = cocos2d::Director::getInstance()->getWinSize();
	cocos2d::Camera* newCamera;
	if (scene->getCameras().empty())//在场景摄像机列表中获取场景中已有的摄像机，如果没有，就创建一个正交摄像机
	{
		newCamera = Camera::createOrthographic(sizeOfWin.width, sizeOfWin.height, 0, 1);
	}
	else
	{
		newCamera = scene->getCameras().front();
	}
	newCamera->setCameraFlag(cocos2d::CameraFlag::DEFAULT);
	newCamera->setPosition3D(cocos2d::Vec3(-sizeOfWin.width / 2, -sizeOfWin.height / 2, 0));
	newCamera->setDepth(1);
	camera->addChild(newCamera);
	camera->CameraInstance = newCamera;
	camera->OgPos = camera->getPosition();
	
	

	camera->retain();
	camera->autorelease();
	camera->schedule(CC_SCHEDULE_SELECTOR(CameraEffect::update), 0.1f);

	return camera;

}

void CameraEffect::LockPlayer(Player* player)
{
	if (player != nullptr)
	{
		player->addChild(this);		
	}
}

void CameraEffect::Shake(float Strength, int Count)
{

}

void CameraEffect::update(float dt)
{
	
}