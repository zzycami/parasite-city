#pragma once

#include "cocos2d.h"

using namespace cocos2d;

class LoadingLayer;

class LoadingScene : public Scene
{
public:
	LoadingScene();
	~LoadingScene();
	virtual bool initWithFilenamesAndNextScene(Vector<String*> filenames, Scene *nextScene);
	static LoadingScene*createWithFilenamesAndNextScene(Vector<String*> filenames, Scene *nextScene);

private:
	LoadingLayer* loadingLayer;
	Scene *nextScene;
	Vector<String*> filenames;
};

class LoadingLayer : public Layer
{
public:
	LoadingLayer();
	~LoadingLayer();
	virtual bool initWithFilenamesAndNextScene(Vector<String*> filenames, Scene *nextScene);
	static LoadingLayer* createWithFilenamesAndNextScene(Vector<String*> filenames, Scene *nextScene);
	void loadingCallBack(Texture2D *texture);

private:
	int totalNum;
	int loadingNum;
	LabelTTF* loadingLabel;
	Scene *nextScene;
};