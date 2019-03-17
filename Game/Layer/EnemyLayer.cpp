#include "EnemyLayer.h"

USING_NS_CC;

Layer* EnemyLayer::createLayer() {
	Layer* enemyLayer = EnemyLayer::create();
	return enemyLayer;
}

bool EnemyLayer::init() {
	if (!Layer::create())
		return false;

	this->scheduleUpdate();
	return true;
}

void EnemyLayer::update(float delta) {
	Rect playerBox = CollisionData::getInstance()->getPlayerBox();
	for (auto it = Enemies.begin(); it != Enemies.end(); it++) {
		(*it).get
	}
}