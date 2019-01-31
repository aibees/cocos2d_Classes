#include "Background.h"

USING_NS_CC;
using namespace std;

Background* Background::Instance = NULL;

Background* Background::getInstance() {
	if (!Instance) {
		Instance = new Background(1);
	}
	return Instance;
}

Background::Background(int num) {
	setBG(num);
}

void Background::getList(int num) {
	string tmp = "";
	ifstream BG_List("C:/Users/JUIL/project1/Classes/Game/BG/test.txt");
	if (BG_List.fail())
		log("text file read fail");
	
	for (int i = 0; i < num; i++) {getline(BG_List, tmp);}
	//num에서 몇 번째 라인(Level)인지 input 들어온다.
	//이렇게 하면 List에 ***.png, width, height 값이 들어온다.
	stringstream ss;
	ss.str(tmp);
	for (int i = 0; i < 3; i++) {
		ss >> List[i];
	}
	//log("%s  %s  %s", List[0], List[1], List[2]);

	return;
}

CCSprite* Background::getBG_Sprite() { return BackgroundImage; }

void Background::setBG_Sprite() { 
	string tmp = "BG/";
	tmp.append(List[0]);
	BackgroundImage = CCSprite::create(tmp);
	return;
}

Vec2 Background::getSize() { return BG_Size; }

void Background::setSize() {
	int width = stoi(List[1]);
	int height = stoi(List[2]);
	BG_Size = Vec2((float)width, (float)height);
	log("in Background class -> %f || %f : bg size", BG_Size.x, BG_Size.y);
	return;
}

Vec2 Background::getPosition() { return Position; }

void Background::setPosition(Vec2 pos) {
	Position = pos;
}

void Background::setBG(int num) {
	log("setBG");
	getList(num);
	setBG_Sprite();
	setSize();
	setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2));
	return;
}
