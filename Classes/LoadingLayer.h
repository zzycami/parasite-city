#pragma once

#include "cocos2d.h"

using namespace cocos2d;
using namespace std;


class LoadingLayer : public Layer
{
public:
	LoadingLayer();
	~LoadingLayer();
	virtual bool initWithFilenames(vector<string> filenames, std::function<void(void)> complete);
	static LoadingLayer* createWithFilenames(vector<string> filenames, std::function<void(void)> complete);
	void loadingCallBack(Texture2D *texture);

private:
	int totalNum;
	int loadingNum;
	LabelTTF* loadingLabel;
	std::function<void(void)> complete;
	ProgressTimer *progress;

	void initLoadingProgress();
};