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

//��������
void startMenu();//��ʼ���� gameStatus == 0
void pauseMenu();//��ͣ���� gameStatus == 6
void singleGame();//������Ϸ gameStatus == 1
void freeGame();//������Ϸ gameStatus == 2
void Collections();//��Ʒ gameStatus == 3
void Setting();//���� gameStatus == 4
void startup();//���ݳ�ʼ��
void loadPlayer();//��ʼ�����
void loadHero();//��ʼ��59������
void playSound();//���Ż�Ǯ������
void secondDisplay();//ʱ��
void goldDisplay(TCHAR(&num)[4], int number);//��ʾ���
void putImage(double x, double y, IMAGE img_bk1, IMAGE img_bk2);//�������ͼƬ
void groundDisplay(double x, double y, IMAGE img_bk1, IMAGE img_bk2);//�����������ͼƬ
void putEffect1(double x, double y, IMAGE img_bk1, IMAGE img_bk2);//�����Ч
void putEffect2(double x, double y, IMAGE img_bk1, IMAGE img_bk2);//�����Ч
void putEdge1(double x, double y, IMAGE img_bk1, IMAGE img_bk2);//����߿�
void putEdge2(double x, double y, IMAGE img_bk1, IMAGE img_bk2);//����߿�
void loadImage();//����ͼƬ
void freshScreen();//��ʼ����ˢ�´��ڴ�С
void show();//��ʾ����
void updateWithoutInput();// ���û������޹صĸ���
void updateWithInput();// ���û������йصĸ���
void displayPopulation();//չʾ�˿�
void displayNumber();//չʾ��������
int freshProbability();//���ݵȼ�ˢ�µĸ���
void LevelUp();//������ҵȼ�
void experienceDisplay();//��ʾ����
void checkFull();//��ⱸսϯ�Ƿ�����
bool levelupCheck(int hero);//����Ƿ��ܹ���������
void levelupShow(int hero);//���Ǽ��ͼƬ
void levelUp(int hero);//�������
void sellSound();//������
void putSeat(int piece);//�������ӽ��뱸սϯ
void Exit();//�˳���Ϸ gameStatus == 5
void gameover();// ��Ϸ��������������

//ȫ�ֱ���
int width1 = GetSystemMetrics(SM_CXSCREEN);// ��ȡ�û�������Ļ�ߴ�1
int high1 = GetSystemMetrics(SM_CYSCREEN);
int width2 = (int)(width1 / 1.5);// 2
int high2 = (int)(high1 / 1.5);
int Width = width1;//�涨���򴰿ڴ�С
int High = high1;
int mouseClick;//��������1����һ�ǣ�2���Ƕ��ǣ�3��������
int mouseMessage;//����¼����Ϣ������Ϊ���ӵı��
int mousePostion;//��¼����ϴε��������λ��
TCHAR second[3];//����

int probability[9][5]//ˢ�¸��� 
{
	100,0,0,0,0,//1�� 
	100,0,0,0,0,//2�� 
	70,30,0,0,0,//3�� 
	50,35,15,0,0,//4�� 
	35,40,20,5,0,//5�� 
	20,35,35,10,0,//6�� 
	14,30,40,15,1,//7�� 
	14,20,35,25,6,//8�� 
	10,15,35,35,15,//9�� 
};

int shopUpgrate_x1;//�̵�������������
int shopUpgrate_y1;
int shopUpgrate_x2;
int shopUpgrate_y2;
int shopFresh_x1;//�̵�ˢ�´�������
int shopFresh_y1;
int shopFresh_x2;
int shopFresh_y2;
int shopHero1_x1;//�̵��һ�����ӵ�����
int shopHero1_y1;
int shopHero1_x2;
int shopHero1_y2;
int shopHero2_x1;//�̵�ڶ������ӵ�����
int shopHero2_y1;
int shopHero2_x2;
int shopHero2_y2;
int shopHero3_x1;//�̵���������ӵ�����
int shopHero3_y1;
int shopHero3_x2;
int shopHero3_y2;
int shopHero4_x1;//�̵���ĸ����ӵ�����
int shopHero4_y1;
int shopHero4_x2;
int shopHero4_y2;
int shopHero5_x1;//�̵��������ӵ�����
int shopHero5_y1;
int shopHero5_x2;
int shopHero5_y2;
int preparationSeat1_x1;//��սϯ1����
int preparationSeat1_y1;
int preparationSeat1_x2;
int preparationSeat1_y2;
int preparationSeat2_x1;//��սϯ2����
int preparationSeat2_y1;
int preparationSeat2_x2;
int preparationSeat2_y2;
int preparationSeat3_x1;//��սϯ3����
int preparationSeat3_y1;
int preparationSeat3_x2;
int preparationSeat3_y2;
int preparationSeat4_x1;//��սϯ4����
int preparationSeat4_y1;
int preparationSeat4_x2;
int preparationSeat4_y2;
int preparationSeat5_x1;//��սϯ5����
int preparationSeat5_y1;
int preparationSeat5_x2;
int preparationSeat5_y2;
int preparationSeat6_x1;//��սϯ6����
int preparationSeat6_y1;
int preparationSeat6_x2;
int preparationSeat6_y2;
int preparationSeat7_x1;//��սϯ7����
int preparationSeat7_y1;
int preparationSeat7_x2;
int preparationSeat7_y2;
int preparationSeat8_x1;//��սϯ8����
int preparationSeat8_y1;
int preparationSeat8_x2;
int preparationSeat8_y2;
int preparationSeat9_x1;//��սϯ9����
int preparationSeat9_y1;
int preparationSeat9_x2;
int preparationSeat9_y2;
int ground[28][4];//������������
int start[4];

int window = 2;//����
int freshshop = 1;//ˢ���̵�
int executebk = 0;//ִ��ˢ�´��
int executefresh = 0;//ִ��ˢ��

int gameStatus = 0;//�����״̬ѡ��
//��Ϸ״̬:0Ϊ��ʼ�˵�,1Ϊ������Ϸ,2Ϊ������Ϸ,3Ϊ��Ʒ,4Ϊ����,5Ϊ�˳���Ϸ��6Ϊ��ͣ

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

class Player//���&&�������ݼ�¼��,Ĭ��0Ϊ��ң�1~7Ϊ�����˻�����
{
public:
	int goldinteger;//�������
	TCHAR goldcharacter[4];//����ַ���,���֧�ֵ�999
	int levelinteger[10];//�ȼ�����
	int levelexperience;//Ŀǰ���ڵĵȼ�����ʼΪ2��
	TCHAR levelcharacter[2];//�ȼ��ַ���
	TCHAR levelshow[5];//�����ַ���
	int shophero[5];//�̵꣨5����
	int shopable[5];//�ж��Ƿ��ܹ�����
	int shopempty[5];//�̵��ж��Ƿ�Ϊ�գ�0Ϊ�գ�1Ϊ����һ������
	int ground[4][7];//���ϵ�����
	int groundempty[4][7];//���ϵ������ж��Ƿ�Ϊ�գ�0Ϊ�գ�1Ϊ����һ�����ӣ�2Ϊ�����������ӣ�3Ϊ����3������
	int groundfull;//�����Ƿ�����,��������ȼ��������ˣ����Ϊ9�˿�
	int preparationseat[9];//��սϯ
	int preparationseatempty[9];//��սϯ�ж��Ƿ�Ϊ�գ�0Ϊ�գ�1Ϊ����һ�����ӣ�2Ϊ�����������ӣ�3Ϊ����3������
	int preparationseatfull;//��սϯ�Ƿ�����
	/*
	* ���ϵ�����
	* ��սϯ
	* ����
	* ����
	* Ѫ��
	* �ȼ�
	* ��Ǯ
	* �̵꣨5����
	* ССӢ��
	* ����
	* ǿ��������ǿ����Ӣ��ǿ����
	*
	*/
private:
}PLAYER[8];

class Hero//Ӣ������
{
public:
	//int number;//���
	string name;//����
	IMAGE img_Face1;//��ױ��
	IMAGE img_Face2;
	IMAGE img_Head1;//��սϯͷ��
	IMAGE img_Head2;
	IMAGE img_Body1;//������
	IMAGE img_Body2;
	int gold;//����
	int number;//�Ƶ�����
	Hero() { gold = 0; number = 0; };
	/*
	* ����
	* ����飩�кü�����
	* �Ǽ�
	* ����
	* ����
	* ���Ƶ�����
	*
	* ͷ��
	* ��ױ��
	*
	* Ѫ��
	* ����
	* ������
	* ����ǿ��
	* ����
	* ħ������
	* �����ٶ�
	* ������Χ
	* ��������
	* ��������
	*
	* װ�������飩3��װ��
	*
	*/
private:

}HERO[59];

//����
//ְҵ
//װ��
//ǿ������
//Ӣ��ǿ��

