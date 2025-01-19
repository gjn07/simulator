#include<iostream>
using namespace std;
#include<graphics.h>
#include<easyx.h>
#include<conio.h>
#include<Windows.h>
#include<string>
#include<stdlib.h>
#include<time.h>
#include <random>
#include <mmsystem.h>

//声明函数
void startMenu();//开始界面 gameStatus == 0
void pauseMenu();//暂停界面 gameStatus == 6
void singleGame();//单人游戏 gameStatus == 1
void freeGame();//自由游戏 gameStatus == 2
void Collections();//藏品 gameStatus == 3
void Setting();//设置 gameStatus == 4
void startup();//数据初始化
void loadPlayer();//初始化玩家
void loadHero();//初始化59个棋子
void playSound();//播放花钱的音乐
void secondDisplay();//时间
void goldDisplay(TCHAR(&num)[4], int number);//显示金币
void putImage(double x, double y, IMAGE img_bk1, IMAGE img_bk2);//输出背景图片
void groundDisplay(double x, double y, IMAGE img_bk1, IMAGE img_bk2);//输出场上棋子图片
void putEffect1(double x, double y, IMAGE img_bk1, IMAGE img_bk2);//输出特效
void putEffect2(double x, double y, IMAGE img_bk1, IMAGE img_bk2);//输出特效
void putEdge1(double x, double y, IMAGE img_bk1, IMAGE img_bk2);//输出边框
void putEdge2(double x, double y, IMAGE img_bk1, IMAGE img_bk2);//输出边框
void loadImage();//加载图片
void freshScreen();//初始化或刷新窗口大小
void show();//显示画面
void updateWithoutInput();// 与用户输入无关的更新
void updateWithInput();// 与用户输入有关的更新
void displayPopulation();//展示人口
void displayNumber();//展示概率数字
int freshProbability();//根据等级刷新的概率
void LevelUp();//提升玩家等级
void experienceDisplay();//显示经验
void checkFull();//检测备战席是否满了
bool levelupCheck(int hero);//检测是否能购买牌升级
void levelupShow(int hero);//升星检测图片
void levelUp(int hero);//检测升星
void sellSound();//卖棋子
void putSeat(int piece);//购买棋子进入备战席
void Exit();//退出游戏 gameStatus == 5
void gameover();// 游戏结束、后续处理

//全局变量
int width1 = GetSystemMetrics(SM_CXSCREEN);// 获取用户电脑屏幕尺寸1
int high1 = GetSystemMetrics(SM_CYSCREEN);
int width2 = (int)(width1 / 1.5);// 2
int high2 = (int)(high1 / 1.5);
int Width = width1;//规定程序窗口大小
int High = high1;
int mouseClick;//鼠标操作，1就是一星，2就是二星，3就是三星
int mouseMessage;//鼠标记录的信息，数据为棋子的编号
int mousePostion;//记录鼠标上次点击的棋盘位置
TCHAR second[3];//秒钟

int probability[9][5]//刷新概率 
{
	100,0,0,0,0,//1级 
	100,0,0,0,0,//2级 
	70,30,0,0,0,//3级 
	50,35,15,0,0,//4级 
	35,40,20,5,0,//5级 
	20,35,35,10,0,//6级 
	14,30,40,15,1,//7级 
	14,20,35,25,6,//8级 
	10,15,35,35,15,//9级 
};

int shopUpgrate_x1;//商店升级窗口坐标
int shopUpgrate_y1;
int shopUpgrate_x2;
int shopUpgrate_y2;
int shopFresh_x1;//商店刷新窗口坐标
int shopFresh_y1;
int shopFresh_x2;
int shopFresh_y2;
int shopHero1_x1;//商店第一个棋子的坐标
int shopHero1_y1;
int shopHero1_x2;
int shopHero1_y2;
int shopHero2_x1;//商店第二个棋子的坐标
int shopHero2_y1;
int shopHero2_x2;
int shopHero2_y2;
int shopHero3_x1;//商店第三个棋子的坐标
int shopHero3_y1;
int shopHero3_x2;
int shopHero3_y2;
int shopHero4_x1;//商店第四个棋子的坐标
int shopHero4_y1;
int shopHero4_x2;
int shopHero4_y2;
int shopHero5_x1;//商店第五个棋子的坐标
int shopHero5_y1;
int shopHero5_x2;
int shopHero5_y2;
int preparationSeat1_x1;//备战席1坐标
int preparationSeat1_y1;
int preparationSeat1_x2;
int preparationSeat1_y2;
int preparationSeat2_x1;//备战席2坐标
int preparationSeat2_y1;
int preparationSeat2_x2;
int preparationSeat2_y2;
int preparationSeat3_x1;//备战席3坐标
int preparationSeat3_y1;
int preparationSeat3_x2;
int preparationSeat3_y2;
int preparationSeat4_x1;//备战席4坐标
int preparationSeat4_y1;
int preparationSeat4_x2;
int preparationSeat4_y2;
int preparationSeat5_x1;//备战席5坐标
int preparationSeat5_y1;
int preparationSeat5_x2;
int preparationSeat5_y2;
int preparationSeat6_x1;//备战席6坐标
int preparationSeat6_y1;
int preparationSeat6_x2;
int preparationSeat6_y2;
int preparationSeat7_x1;//备战席7坐标
int preparationSeat7_y1;
int preparationSeat7_x2;
int preparationSeat7_y2;
int preparationSeat8_x1;//备战席8坐标
int preparationSeat8_y1;
int preparationSeat8_x2;
int preparationSeat8_y2;
int preparationSeat9_x1;//备战席9坐标
int preparationSeat9_y1;
int preparationSeat9_x2;
int preparationSeat9_y2;
int ground[28][4];//场上棋子坐标
int start[4];

int window = 2;//窗口
int freshshop = 1;//刷新商店
int executebk = 0;//执行刷新打断
int executefresh = 0;//执行刷新

int gameStatus = 0;//程序的状态选择
//游戏状态:0为开始菜单,1为单人游戏,2为自由游戏,3为藏品,4为设置,5为退出游戏，6为暂停

IMAGE img_startMenubk1;
IMAGE img_startMenubk2;
IMAGE img_pauseMenubk1;
IMAGE img_pauseMenubk2;
IMAGE img_singleGamebk1;
IMAGE img_freeGamebk1;
IMAGE img_freeGamebk2;
IMAGE img_singleGamebk2;
IMAGE img_Collectionsbk1;
IMAGE img_Collectionsbk2;
IMAGE img_Settingbk1;
IMAGE img_Settingbk2;
IMAGE img_mouseSurface;
IMAGE img_mouseBottom;
IMAGE img_twolevelsideSurface1;
IMAGE img_twolevelsideSurface2;
IMAGE img_twolevelsideBottom1;
IMAGE img_twolevelsideBottom2;
IMAGE img_threelevelsideSurface1;
IMAGE img_threelevelsideSurface2;
IMAGE img_threelevelsideBottom1;
IMAGE img_threelevelsideBottom2;
IMAGE img_twoleveltipSurface1;
IMAGE img_twoleveltipSurface2;
IMAGE img_twoleveltipBottom1;
IMAGE img_twoleveltipBottom2;
IMAGE img_threeleveltipSurface1;
IMAGE img_threeleveltipSurface2;
IMAGE img_threeleveltipBottom1;
IMAGE img_threeleveltipBottom2;
IMAGE img_twoleveledgeSurface1;
IMAGE img_twoleveledgeSurface2;
IMAGE img_twoleveledgeBottom1;
IMAGE img_twoleveledgeBottom2;
IMAGE img_threeleveledgeSurface1;
IMAGE img_threeleveledgeSurface2;
IMAGE img_threeleveledgeBottom1;
IMAGE img_threeleveledgeBottom2;

class Player//玩家&&电脑数据记录类,默认0为玩家，1~7为电脑人机数据
{
public:
	int goldinteger;//金币整型
	TCHAR goldcharacter[4];//金币字符型,最多支持到999
	int levelinteger[10];//等级整型
	int levelexperience;//目前所在的等级，初始为2级
	TCHAR levelcharacter[2];//等级字符型
	TCHAR levelshow[5];//经验字符型
	int shophero[5];//商店（5个）
	int shopable[5];//判断是否能够购买
	int shopempty[5];//商店判断是否为空，0为空，1为存在一星棋子
	int ground[4][7];//场上的棋子
	int groundempty[4][7];//场上的棋子判断是否为空，0为空，1为存在一星棋子，2为存在两星棋子，3为存在3星棋子
	int groundfull;//场上是否满了,如果超过等级就是满了，最大为9人口
	int preparationseat[9];//备战席
	int preparationseatempty[9];//备战席判断是否为空，0为空，1为存在一星棋子，2为存在两星棋子，3为存在3星棋子
	int preparationseatfull;//备战席是否满了
	/*
	* 场上的棋子
	* 备战席
	* 排名
	* 名字
	* 血量
	* 等级
	* 金钱
	* 商店（5个）
	* 小小英雄
	* 棋盘
	* 强化（符文强化，英雄强化）
	*
	*/
private:
}PLAYER[8];

class Hero//英雄属性
{
public:
	//int number;//编号
	string name;//名字
	IMAGE img_Face1;//定妆照
	IMAGE img_Face2;
	IMAGE img_Head1;//备战席头像
	IMAGE img_Head2;
	IMAGE img_Body1;//场上像
	IMAGE img_Body2;
	int gold;//费用
	int number;//牌的数量
	Hero() { gold = 0; number = 0; };
	/*
	* 名字
	* 羁绊（数组）有好几个嘞
	* 星级
	* 费用
	* 技能
	* 卡牌的数量
	*
	* 头像
	* 定妆照
	*
	* 血量
	* 蓝量
	* 攻击力
	* 法术强度
	* 护甲
	* 魔法抗性
	* 攻击速度
	* 攻击范围
	* 暴击几率
	* 暴击倍率
	*
	* 装备（数组）3个装备
	*
	*/
private:

}HERO[59];

//种族
//职业
//装备
//强化符文
//英雄强化

