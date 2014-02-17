#pragma once

#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

class LoadingLayer;

class LoadingScene : public Scene
{
public:
	LoadingScene();
	~LoadingScene();
	virtual bool initWithFilenamesAndNextScene(vector<string> filenames, Scene *nextScene);
	static LoadingScene*createWithFilenamesAndNextScene(vector<string> filenames, Scene *nextScene);

private:
	LoadingLayer* loadingLayer;
	Scene *nextScene;
	vector<string> filenames;
};

class LoadingLayer : public Layer
{
public:
	LoadingLayer();
	~LoadingLayer();
	virtual bool initWithFilenamesAndNextScene(vector<string> filenames, Scene *nextScene);
	static LoadingLayer* createWithFilenamesAndNextScene(vector<string> filenames, Scene *nextScene);
	void loadingCallBack(Texture2D *texture);

private:
	int totalNum;
	int loadingNum;
	LabelTTF* loadingLabel;
	Scene *nextScene;
};