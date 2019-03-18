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
	dataList = new DataList();
	this->schedule(schedule_selector(EnemyLayer::createEnemy), 5.0f);
	this->scheduleUpdate();
	return true;
}

void EnemyLayer::update(float delta) {
	Rect playerBox = CollisionData::getInstance()->getPlayerBox();
	for (auto it = Enemies.begin(); it != Enemies.end(); it++) {
		(*it)->setPlayerData(playerBox);
	}
}

void EnemyLayer::createEnemy(float delta) {
	srand((unsigned int)time(0));
	int randomEnemy = rand()*rand() % (dataList->getEnemyListSize());
	string dir = "Unit/Enemy", tmp = "";
	tmp = dataList->getEnemyList(randomEnemy);
}