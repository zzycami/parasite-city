#pragma once

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace std;
using namespace CocosDenshion;

typedef enum resource_type_def{
	RESOURCE_TYPE_IMAGE = 1,
	RESOURCE_TYPE_PLIST,
	RESOURCE_TYPE_VOICE,
} resource_type;

typedef struct resouce_def{
	string filename;
	resource_type type;
} resource;

class LoadingLayer : public Layer
{
public:
	LoadingLayer();
	~LoadingLayer();
	virtual bool initWithFilenames(vector<resource> resources, std::function<void(void)> complete);
	static LoadingLayer* createWithFilenames(vector<resource> resources, std::function<void(void)> complete);
	void loadingCallBack(Texture2D *texture);
    static void addConsequentTextures(const char *fmt, int count, vector<resource> &resources);

private:
	int totalNum;
	int loadingNum;
	LabelTTF* loadingLabel;
	std::function<void(void)> complete;
	ProgressTimer *progress;
	vector<resource> resources;

	void initLoadingProgress();
};