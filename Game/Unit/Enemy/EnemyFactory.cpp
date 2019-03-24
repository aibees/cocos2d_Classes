#include "EnemyFactory.h"
#include "SmallGun.h"

using namespace std;

EnemyFactory* EnemyFactory::Instance = NULL;

EnemyFactory::EnemyFactory() {

}

EnemyFactory * EnemyFactory::getInstance() {
	if (!Instance) {
		Instance = new EnemyFactory();
	}
	return Instance;
}

Enemy* EnemyFactory::createEnemy(string filename) {
	if (filename == "SmallGun.png") {
		return new SmallGun(filename);
	}
}