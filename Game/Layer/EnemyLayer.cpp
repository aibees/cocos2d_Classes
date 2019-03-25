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

	for (int i = 0; i < Enemies.size(); i++) {
		Enemies[i]->setPlayerData(playerBox);
		Sprite* sp = spriteMapping[Enemies[i]->getName()];
		log("map size : %d", spriteMapping.size());
		sp->setRotation(Enemies[i]->calcRotation());
		Vec2 d = Enemies[i]->calcPosition();
		d = Vec2(Enemies[i]->getPosition().x + d.x * delta, Enemies[i]->getPosition().y + d.y * delta);
		Enemies[i]->setPosition(d);
		sp->setPosition(Enemies[i]->getPosition());
		log("%d th enemy : %f | %f", i, sp->getPosition().x, sp->getPosition().y);
	}
}

void EnemyLayer::createEnemy(float delta) {
	srand((unsigned int)time(0));
	int randomEnemy = rand()*rand() % (dataList->getEnemyListSize());
	string dir = "unit/Enemy/", tmp = "";
	tmp = dataList->getEnemyList(randomEnemy);
	Enemies.push_back(EnemyFactory::getInstance()->createEnemy(dir.append(tmp), tmp));
	Sprite* sp = Sprite::create(dir);
	sp->setName(Enemies.back()->getName());
	sp->setPosition(Enemies.back()->getPosition());
	this->addChild(sp, 0);
	spriteMapping[Enemies.back()->getName()] = sp;
	log("enemy created!!");
}