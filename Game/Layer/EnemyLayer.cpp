#include "EnemyLayer.h"

USING_NS_CC;
using namespace std;

Layer* EnemyLayer::createLayer() {
	Layer* enemyLayer = EnemyLayer::create();
	return enemyLayer;
}

bool EnemyLayer::init() {
	if (!Layer::create())
		return false;
	log("Enemylayer init");
	dataList = new DataList();
	this->schedule(schedule_selector(EnemyLayer::createEnemy), 5.0f);
	this->scheduleUpdate();
	return true;
}

void EnemyLayer::update(float delta) {
	Rect playerBox = CollisionData::getInstance()->getPlayerBox();
	int cnt = 0;
	for (auto obj : Enemies) {
		if () { // new object that puts no sprite
			continue;
		}

	}
}

void EnemyLayer::createEnemy(float delta) {
	srand((unsigned int)time(0));
	int randomEnemy = rand()*rand() % (dataList->getEnemyListSize());
	string dir = "Unit/Enemy/", tmp = "";
	tmp = dataList->getEnemyList(randomEnemy);
	Enemies.push_back(EnemyFactory::getInstance()->createEnemy(tmp));
	log("enemy created!!");
}