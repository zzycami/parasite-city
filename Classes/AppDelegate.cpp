#include "AppDelegate.h"
#include "LoadingScene.h"
#include "WelcomeScene.h"

using namespace cocos2d;
using namespace std;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto eglView = EGLView::getInstance();

    director->setOpenGLView(eglView);
	eglView->setDesignResolutionSize(1048,629, ResolutionPolicy::SHOW_ALL);

	// set resource load resolution
    setResourceSearchResolution();
	
    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default Value* is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    // create a scene. it's an autorelease object
    //auto scene = WelcomeScene::create();
	vector<string> filenames = vector<string>();
	for (int  i= 1;  i< 33; i++){
			char buffer[50] = {0};
			sprintf(buffer, "lisa_rest%02d.png", i);
			filenames.push_back(buffer);
	}
	 LoadingScene *loadingScene = LoadingScene::createWithFilenamesAndNextScene(filenames, NULL);
    // run
	director->runWithScene(loadingScene);

    return true;
}

void AppDelegate::setResourceSearchResolution()
{
    std::vector<std::string> paths;
	paths.push_back("fonts");
    paths.push_back("images");
    paths.push_back("voices");
	paths.push_back("images/lisa_rest");
    paths.push_back("images/menu");
    paths.push_back("images/scene");
    paths.push_back("images/object");
    paths.push_back("pd_resources/Sounds");
    paths.push_back("pd_resources/Sprites");
	paths.push_back("images/hero/idle");
	paths.push_back("images/hero/run");
	paths.push_back("images/hero/squat_walk");
	paths.push_back("images/hero");
    FileUtils::getInstance()->setSearchResolutionsOrder(paths);
}



// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
