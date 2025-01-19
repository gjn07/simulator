#include"PLAYERandHERO.h"

// 定义变量保存当前时间
SYSTEMTIME ti;
// 引用 Windows Multimedia API
#pragma comment(lib,"Winmm.lib")//背景音乐

default_random_engine RAND0{ random_device{}() };//随机数
default_random_engine RAND1{ random_device{}() };
default_random_engine RAND2{ random_device{}() };
default_random_engine RAND3{ random_device{}() };
default_random_engine RAND4{ random_device{}() };
default_random_engine RAND5{ random_device{}() };

uniform_int_distribution<int> EDGE0(0, 100);
uniform_int_distribution<int> EDGE1(0, 12);
uniform_int_distribution<int> EDGE2(13, 25);
uniform_int_distribution<int> EDGE3(26, 38);
uniform_int_distribution<int> EDGE4(39, 50);
uniform_int_distribution<int> EDGE5(51, 58);

void startMenu()//开始界面
{
	//窗口化判断，输出开始菜单背景
	putImage(0.0, 0.0, img_startMenubk1, img_startMenubk2);
}

void pauseMenu()//暂停界面  gameStatus == 6
{
	//窗口化判断，输出开始菜单背景
	putImage(0, 0, img_pauseMenubk1, img_pauseMenubk2);
}

void singleGame()//单人游戏 gameStatus == 1
{
	executefresh = executebk;
	if (PLAYER[0].shopempty[0] != 0)
	{
		levelupCheck(PLAYER[0].shophero[0]);
	}
	if (PLAYER[0].shopempty[1] != 0)
	{
		levelupCheck(PLAYER[0].shophero[1]);
	}
	if (PLAYER[0].shopempty[2] != 0)
	{
		levelupCheck(PLAYER[0].shophero[2]);
	}
	if (PLAYER[0].shopempty[3] != 0)
	{
		levelupCheck(PLAYER[0].shophero[3]);
	}
	if (PLAYER[0].shopempty[4] != 0)
	{
		levelupCheck(PLAYER[0].shophero[4]);
	}
	if (executebk == 1)
	{
		putImage(0.0, 0.0, img_singleGamebk1, img_singleGamebk2);//背景

		for (int i = 0, k = 0; i < 4; i++)
			for (int j = 0; j < 7; j++)
			{
				setlinestyle(PS_SOLID, 1);
				setlinecolor(RGB(51, 135, 139));
				line(ground[k][0], ground[k][1], ground[k][2], ground[k][1]);
				line(ground[k][0], ground[k][1], ground[k][0], ground[k][3]);
				line(ground[k][0], ground[k][3], ground[k][2], ground[k][3]);
				line(ground[k][2], ground[k][1], ground[k][2], ground[k][3]);
				k++;
			}

		secondDisplay();//时间
		//商店展示
		if (PLAYER[0].shopempty[0] != 0)
		{
			putImage(0.251, 0.86, HERO[PLAYER[0].shophero[0]].img_Face1, HERO[PLAYER[0].shophero[0]].img_Face2);
			levelupCheck(PLAYER[0].shophero[0]);
		}
		if (PLAYER[0].shopempty[1] != 0)
		{
			putImage(0.355, 0.86, HERO[PLAYER[0].shophero[1]].img_Face1, HERO[PLAYER[0].shophero[1]].img_Face2);
			levelupCheck(PLAYER[0].shophero[1]);
		}
		if (PLAYER[0].shopempty[2] != 0)
		{
			putImage(0.46, 0.86, HERO[PLAYER[0].shophero[2]].img_Face1, HERO[PLAYER[0].shophero[2]].img_Face2);
			levelupCheck(PLAYER[0].shophero[2]);
		}
		if (PLAYER[0].shopempty[3] != 0)
		{
			putImage(0.565, 0.86, HERO[PLAYER[0].shophero[3]].img_Face1, HERO[PLAYER[0].shophero[3]].img_Face2);
			levelupCheck(PLAYER[0].shophero[3]);
		}
		if (PLAYER[0].shopempty[4] != 0)
		{
			putImage(0.67, 0.86, HERO[PLAYER[0].shophero[4]].img_Face1, HERO[PLAYER[0].shophero[4]].img_Face2);
			levelupCheck(PLAYER[0].shophero[4]);
		}
		if (PLAYER[0].preparationseatempty[0] != 0) putImage(0.207, 0.698, HERO[PLAYER[0].preparationseat[0]].img_Head1, HERO[PLAYER[0].preparationseat[0]].img_Head2);
		if (PLAYER[0].preparationseatempty[1] != 0) putImage(0.267, 0.698, HERO[PLAYER[0].preparationseat[1]].img_Head1, HERO[PLAYER[0].preparationseat[1]].img_Head2);
		if (PLAYER[0].preparationseatempty[2] != 0) putImage(0.327, 0.698, HERO[PLAYER[0].preparationseat[2]].img_Head1, HERO[PLAYER[0].preparationseat[2]].img_Head2);
		if (PLAYER[0].preparationseatempty[3] != 0) putImage(0.389, 0.698, HERO[PLAYER[0].preparationseat[3]].img_Head1, HERO[PLAYER[0].preparationseat[3]].img_Head2);
		if (PLAYER[0].preparationseatempty[4] != 0) putImage(0.450, 0.698, HERO[PLAYER[0].preparationseat[4]].img_Head1, HERO[PLAYER[0].preparationseat[4]].img_Head2);
		if (PLAYER[0].preparationseatempty[5] != 0) putImage(0.512, 0.698, HERO[PLAYER[0].preparationseat[5]].img_Head1, HERO[PLAYER[0].preparationseat[5]].img_Head2);
		if (PLAYER[0].preparationseatempty[6] != 0) putImage(0.572, 0.698, HERO[PLAYER[0].preparationseat[6]].img_Head1, HERO[PLAYER[0].preparationseat[6]].img_Head2);
		if (PLAYER[0].preparationseatempty[7] != 0) putImage(0.632, 0.698, HERO[PLAYER[0].preparationseat[7]].img_Head1, HERO[PLAYER[0].preparationseat[7]].img_Head2);
		if (PLAYER[0].preparationseatempty[8] != 0) putImage(0.695, 0.698, HERO[PLAYER[0].preparationseat[8]].img_Head1, HERO[PLAYER[0].preparationseat[8]].img_Head2);

		if (PLAYER[0].groundempty[0][0] != 0) groundDisplay(ground[0][0], ground[0][1], HERO[PLAYER[0].ground[0][0]].img_Body1, HERO[PLAYER[0].ground[0][0]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[0][1] != 0) groundDisplay(ground[1][0], ground[1][1], HERO[PLAYER[0].ground[0][1]].img_Body1, HERO[PLAYER[0].ground[0][1]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[0][2] != 0) groundDisplay(ground[2][0], ground[2][1], HERO[PLAYER[0].ground[0][2]].img_Body1, HERO[PLAYER[0].ground[0][2]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[0][3] != 0) groundDisplay(ground[3][0], ground[3][1], HERO[PLAYER[0].ground[0][3]].img_Body1, HERO[PLAYER[0].ground[0][3]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[0][4] != 0) groundDisplay(ground[4][0], ground[4][1], HERO[PLAYER[0].ground[0][4]].img_Body1, HERO[PLAYER[0].ground[0][4]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[0][5] != 0) groundDisplay(ground[5][0], ground[5][1], HERO[PLAYER[0].ground[0][5]].img_Body1, HERO[PLAYER[0].ground[0][5]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[0][6] != 0) groundDisplay(ground[6][0], ground[6][1], HERO[PLAYER[0].ground[0][6]].img_Body1, HERO[PLAYER[0].ground[0][6]].img_Body2);//输出场上棋子图片

		if (PLAYER[0].groundempty[1][0] != 0) groundDisplay(ground[7][0], ground[7][1], HERO[PLAYER[0].ground[1][0]].img_Body1, HERO[PLAYER[0].ground[1][0]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[1][1] != 0) groundDisplay(ground[8][0], ground[8][1], HERO[PLAYER[0].ground[1][1]].img_Body1, HERO[PLAYER[0].ground[1][1]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[1][2] != 0) groundDisplay(ground[9][0], ground[9][1], HERO[PLAYER[0].ground[1][2]].img_Body1, HERO[PLAYER[0].ground[1][2]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[1][3] != 0) groundDisplay(ground[10][0], ground[10][1], HERO[PLAYER[0].ground[1][3]].img_Body1, HERO[PLAYER[0].ground[1][3]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[1][4] != 0) groundDisplay(ground[11][0], ground[11][1], HERO[PLAYER[0].ground[1][4]].img_Body1, HERO[PLAYER[0].ground[1][4]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[1][5] != 0) groundDisplay(ground[12][0], ground[12][1], HERO[PLAYER[0].ground[1][5]].img_Body1, HERO[PLAYER[0].ground[1][5]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[1][6] != 0) groundDisplay(ground[13][0], ground[13][1], HERO[PLAYER[0].ground[1][6]].img_Body1, HERO[PLAYER[0].ground[1][6]].img_Body2);//输出场上棋子图片

		if (PLAYER[0].groundempty[2][0] != 0) groundDisplay(ground[14][0], ground[14][1], HERO[PLAYER[0].ground[2][0]].img_Body1, HERO[PLAYER[0].ground[2][0]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[2][1] != 0) groundDisplay(ground[15][0], ground[15][1], HERO[PLAYER[0].ground[2][1]].img_Body1, HERO[PLAYER[0].ground[2][1]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[2][2] != 0) groundDisplay(ground[16][0], ground[16][1], HERO[PLAYER[0].ground[2][2]].img_Body1, HERO[PLAYER[0].ground[2][2]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[2][3] != 0) groundDisplay(ground[17][0], ground[17][1], HERO[PLAYER[0].ground[2][3]].img_Body1, HERO[PLAYER[0].ground[2][3]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[2][4] != 0) groundDisplay(ground[18][0], ground[18][1], HERO[PLAYER[0].ground[2][4]].img_Body1, HERO[PLAYER[0].ground[2][4]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[2][5] != 0) groundDisplay(ground[19][0], ground[19][1], HERO[PLAYER[0].ground[2][5]].img_Body1, HERO[PLAYER[0].ground[2][5]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[2][6] != 0) groundDisplay(ground[20][0], ground[20][1], HERO[PLAYER[0].ground[2][6]].img_Body1, HERO[PLAYER[0].ground[2][6]].img_Body2);//输出场上棋子图片

		if (PLAYER[0].groundempty[3][0] != 0) groundDisplay(ground[21][0], ground[21][1], HERO[PLAYER[0].ground[3][0]].img_Body1, HERO[PLAYER[0].ground[3][0]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[3][1] != 0) groundDisplay(ground[22][0], ground[22][1], HERO[PLAYER[0].ground[3][1]].img_Body1, HERO[PLAYER[0].ground[3][1]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[3][2] != 0) groundDisplay(ground[23][0], ground[23][1], HERO[PLAYER[0].ground[3][2]].img_Body1, HERO[PLAYER[0].ground[3][2]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[3][3] != 0) groundDisplay(ground[24][0], ground[24][1], HERO[PLAYER[0].ground[3][3]].img_Body1, HERO[PLAYER[0].ground[3][3]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[3][4] != 0) groundDisplay(ground[25][0], ground[25][1], HERO[PLAYER[0].ground[3][4]].img_Body1, HERO[PLAYER[0].ground[3][4]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[3][5] != 0) groundDisplay(ground[26][0], ground[26][1], HERO[PLAYER[0].ground[3][5]].img_Body1, HERO[PLAYER[0].ground[3][5]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[3][6] != 0) groundDisplay(ground[27][0], ground[27][1], HERO[PLAYER[0].ground[3][6]].img_Body1, HERO[PLAYER[0].ground[3][6]].img_Body2);//输出场上棋子图片

		//显示星级边框
		for (int i = 0, k = 0; i < 4; i++)
			for (int j = 0; j < 7; j++)
			{
				if (PLAYER[0].groundempty[i][j] == 2)
				{
					putEdge1(ground[k][0], ground[k][1], img_twoleveledgeBottom1, img_twoleveledgeBottom2);
					putEdge2(ground[k][0], ground[k][1], img_twoleveledgeSurface1, img_twoleveledgeSurface2);
				}
				k++;
			}

		for (int i = 0, k = 0; i < 4; i++)
			for (int j = 0; j < 7; j++)
			{
				if (PLAYER[0].groundempty[i][j] == 3)
				{
					putEdge1(ground[k][0], ground[k][1], img_threeleveledgeBottom1, img_threeleveledgeBottom2);
					putEdge2(ground[k][0], ground[k][1], img_threeleveledgeSurface1, img_threeleveledgeSurface2);
				}
				k++;
			}


		if (PLAYER[0].preparationseatempty[0] == 2)
		{
			putEdge1(preparationSeat1_x1, preparationSeat1_y1, img_twolevelsideBottom1, img_twolevelsideBottom2);
			putEdge2(preparationSeat1_x1, preparationSeat1_y1, img_twolevelsideSurface1, img_twolevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[1] == 2)
		{
			putEdge1(preparationSeat2_x1, preparationSeat2_y1, img_twolevelsideBottom1, img_twolevelsideBottom2);
			putEdge2(preparationSeat2_x1, preparationSeat2_y1, img_twolevelsideSurface1, img_twolevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[2] == 2)
		{
			putEdge1(preparationSeat3_x1, preparationSeat3_y1, img_twolevelsideBottom1, img_twolevelsideBottom2);
			putEdge2(preparationSeat3_x1, preparationSeat3_y1, img_twolevelsideSurface1, img_twolevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[3] == 2)
		{
			putEdge1(preparationSeat4_x1, preparationSeat4_y1, img_twolevelsideBottom1, img_twolevelsideBottom2);
			putEdge2(preparationSeat4_x1, preparationSeat4_y1, img_twolevelsideSurface1, img_twolevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[4] == 2)
		{
			putEdge1(preparationSeat5_x1, preparationSeat5_y1, img_twolevelsideBottom1, img_twolevelsideBottom2);
			putEdge2(preparationSeat5_x1, preparationSeat5_y1, img_twolevelsideSurface1, img_twolevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[5] == 2)
		{
			putEdge1(preparationSeat6_x1, preparationSeat6_y1, img_twolevelsideBottom1, img_twolevelsideBottom2);
			putEdge2(preparationSeat6_x1, preparationSeat6_y1, img_twolevelsideSurface1, img_twolevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[6] == 2)
		{
			putEdge1(preparationSeat7_x1, preparationSeat7_y1, img_twolevelsideBottom1, img_twolevelsideBottom2);
			putEdge2(preparationSeat7_x1, preparationSeat7_y1, img_twolevelsideSurface1, img_twolevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[7] == 2)
		{
			putEdge1(preparationSeat8_x1, preparationSeat8_y1, img_twolevelsideBottom1, img_twolevelsideBottom2);
			putEdge2(preparationSeat8_x1, preparationSeat8_y1, img_twolevelsideSurface1, img_twolevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[8] == 2)
		{
			putEdge1(preparationSeat9_x1, preparationSeat9_y1, img_twolevelsideBottom1, img_twolevelsideBottom2);
			putEdge2(preparationSeat9_x1, preparationSeat9_y1, img_twolevelsideSurface1, img_twolevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[0] == 3)
		{
			putEdge1(preparationSeat1_x1, preparationSeat1_y1, img_threelevelsideBottom1, img_threelevelsideBottom2);
			putEdge2(preparationSeat1_x1, preparationSeat1_y1, img_threelevelsideSurface1, img_threelevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[1] == 3)
		{
			putEdge1(preparationSeat2_x1, preparationSeat2_y1, img_threelevelsideBottom1, img_threelevelsideBottom2);
			putEdge2(preparationSeat2_x1, preparationSeat2_y1, img_threelevelsideSurface1, img_threelevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[2] == 3)
		{
			putEdge1(preparationSeat3_x1, preparationSeat3_y1, img_threelevelsideBottom1, img_threelevelsideBottom2);
			putEdge2(preparationSeat3_x1, preparationSeat3_y1, img_threelevelsideSurface1, img_threelevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[3] == 3)
		{
			putEdge1(preparationSeat4_x1, preparationSeat4_y1, img_threelevelsideBottom1, img_threelevelsideBottom2);
			putEdge2(preparationSeat4_x1, preparationSeat4_y1, img_threelevelsideSurface1, img_threelevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[4] == 3)
		{
			putEdge1(preparationSeat5_x1, preparationSeat5_y1, img_threelevelsideBottom1, img_threelevelsideBottom2);
			putEdge2(preparationSeat5_x1, preparationSeat5_y1, img_threelevelsideSurface1, img_threelevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[5] == 3)
		{
			putEdge1(preparationSeat6_x1, preparationSeat6_y1, img_threelevelsideBottom1, img_threelevelsideBottom2);
			putEdge2(preparationSeat6_x1, preparationSeat6_y1, img_threelevelsideSurface1, img_threelevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[6] == 3)
		{
			putEdge1(preparationSeat7_x1, preparationSeat7_y1, img_threelevelsideBottom1, img_threelevelsideBottom2);
			putEdge2(preparationSeat7_x1, preparationSeat7_y1, img_threelevelsideSurface1, img_threelevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[7] == 3)
		{
			putEdge1(preparationSeat8_x1, preparationSeat8_y1, img_threelevelsideBottom1, img_threelevelsideBottom2);
			putEdge2(preparationSeat8_x1, preparationSeat8_y1, img_threelevelsideSurface1, img_threelevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[8] == 3)
		{
			putEdge1(preparationSeat9_x1, preparationSeat9_y1, img_threelevelsideBottom1, img_threelevelsideBottom2);
			putEdge2(preparationSeat9_x1, preparationSeat9_y1, img_threelevelsideSurface1, img_threelevelsideSurface2);
		}

		//显示是否能够升星
		levelupShow(PLAYER[0].shophero[0]);
		levelupShow(PLAYER[0].shophero[1]);
		levelupShow(PLAYER[0].shophero[2]);
		levelupShow(PLAYER[0].shophero[3]);
		levelupShow(PLAYER[0].shophero[4]);

		goldDisplay(PLAYER[0].goldcharacter, PLAYER[0].goldinteger);
		experienceDisplay();//显示经验
		displayPopulation();//展示人口
		displayNumber();//展示概率数字

		MOUSEMSG m;		// 定义鼠标消息
		m = GetMouseMsg();
		//图片的位置等于鼠标所在的位置
		putimage(m.x, m.y, &img_mouseBottom, SRCAND);
		putimage(m.x, m.y, &img_mouseSurface, SRCPAINT);
		executebk = 0;
	}
	if (freshshop % 2)//刷新商店
	{
		int repeat = 0;
		do {
			PLAYER[0].shophero[0] = freshProbability();
			if (HERO[PLAYER[0].shophero[0]].number == 0) repeat = 1;
			else repeat = 0;
		} while (repeat);
		HERO[PLAYER[0].shophero[0]].number--;
		repeat = 0;

		do {
			PLAYER[0].shophero[1] = freshProbability();
			if (HERO[PLAYER[0].shophero[1]].number == 0) repeat = 1;
			else repeat = 0;
		} while (repeat);
		HERO[PLAYER[0].shophero[1]].number--;
		repeat = 0;

		do {
			PLAYER[0].shophero[2] = freshProbability();
			if (HERO[PLAYER[0].shophero[2]].number == 0) repeat = 1;
			else repeat = 0;
		} while (repeat);
		HERO[PLAYER[0].shophero[2]].number--;
		repeat = 0;

		do {
			PLAYER[0].shophero[3] = freshProbability();
			if (HERO[PLAYER[0].shophero[3]].number == 0) repeat = 1;
			else repeat = 0;
		} while (repeat);
		HERO[PLAYER[0].shophero[3]].number--;
		repeat = 0;
		do {
			PLAYER[0].shophero[4] = freshProbability();
			if (HERO[PLAYER[0].shophero[4]].number == 0) repeat = 1;
			else repeat = 0;
		} while (repeat);
		HERO[PLAYER[0].shophero[4]].number--;

		//if (HERO[PLAYER[0].shophero[0]].number - 1 < 0 && HERO[PLAYER[0].shophero[1]].number - 1 >= 0 && HERO[PLAYER[0].shophero[2]].number - 1 >= 0 && HERO[PLAYER[0].shophero[3]].number - 1 >= 0 && HERO[PLAYER[0].shophero[4]].number - 1 >= 0)
		if (PLAYER[0].shopempty[0] != 0)
		{
			putImage(0.251, 0.86, HERO[PLAYER[0].shophero[0]].img_Face1, HERO[PLAYER[0].shophero[0]].img_Face2);
			levelupCheck(PLAYER[0].shophero[0]);
		}
		if (PLAYER[0].shopempty[1] != 0)
		{
			putImage(0.355, 0.86, HERO[PLAYER[0].shophero[1]].img_Face1, HERO[PLAYER[0].shophero[1]].img_Face2);
			levelupCheck(PLAYER[0].shophero[1]);
		}
		if (PLAYER[0].shopempty[2] != 0)
		{
			putImage(0.46, 0.86, HERO[PLAYER[0].shophero[2]].img_Face1, HERO[PLAYER[0].shophero[2]].img_Face2);
			levelupCheck(PLAYER[0].shophero[2]);
		}
		if (PLAYER[0].shopempty[3] != 0)
		{
			putImage(0.565, 0.86, HERO[PLAYER[0].shophero[3]].img_Face1, HERO[PLAYER[0].shophero[3]].img_Face2);
			levelupCheck(PLAYER[0].shophero[3]);
		}
		if (PLAYER[0].shopempty[4] != 0)
		{
			putImage(0.67, 0.86, HERO[PLAYER[0].shophero[4]].img_Face1, HERO[PLAYER[0].shophero[4]].img_Face2);
			levelupCheck(PLAYER[0].shophero[4]);
		}
		if (PLAYER[0].preparationseatempty[0] != 0) putImage(0.207, 0.698, HERO[PLAYER[0].preparationseat[0]].img_Head1, HERO[PLAYER[0].preparationseat[0]].img_Head2);
		if (PLAYER[0].preparationseatempty[1] != 0) putImage(0.267, 0.698, HERO[PLAYER[0].preparationseat[1]].img_Head1, HERO[PLAYER[0].preparationseat[1]].img_Head2);
		if (PLAYER[0].preparationseatempty[2] != 0) putImage(0.327, 0.698, HERO[PLAYER[0].preparationseat[2]].img_Head1, HERO[PLAYER[0].preparationseat[2]].img_Head2);
		if (PLAYER[0].preparationseatempty[3] != 0) putImage(0.389, 0.698, HERO[PLAYER[0].preparationseat[3]].img_Head1, HERO[PLAYER[0].preparationseat[3]].img_Head2);
		if (PLAYER[0].preparationseatempty[4] != 0) putImage(0.450, 0.698, HERO[PLAYER[0].preparationseat[4]].img_Head1, HERO[PLAYER[0].preparationseat[4]].img_Head2);
		if (PLAYER[0].preparationseatempty[5] != 0) putImage(0.512, 0.698, HERO[PLAYER[0].preparationseat[5]].img_Head1, HERO[PLAYER[0].preparationseat[5]].img_Head2);
		if (PLAYER[0].preparationseatempty[6] != 0) putImage(0.572, 0.698, HERO[PLAYER[0].preparationseat[6]].img_Head1, HERO[PLAYER[0].preparationseat[6]].img_Head2);
		if (PLAYER[0].preparationseatempty[7] != 0) putImage(0.632, 0.698, HERO[PLAYER[0].preparationseat[7]].img_Head1, HERO[PLAYER[0].preparationseat[7]].img_Head2);
		if (PLAYER[0].preparationseatempty[8] != 0) putImage(0.695, 0.698, HERO[PLAYER[0].preparationseat[8]].img_Head1, HERO[PLAYER[0].preparationseat[8]].img_Head2);

		if (PLAYER[0].groundempty[0][0] != 0) groundDisplay(ground[0][0], ground[0][1], HERO[PLAYER[0].ground[0][0]].img_Body1, HERO[PLAYER[0].ground[0][0]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[0][1] != 0) groundDisplay(ground[1][0], ground[1][1], HERO[PLAYER[0].ground[0][1]].img_Body1, HERO[PLAYER[0].ground[0][1]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[0][2] != 0) groundDisplay(ground[2][0], ground[2][1], HERO[PLAYER[0].ground[0][2]].img_Body1, HERO[PLAYER[0].ground[0][2]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[0][3] != 0) groundDisplay(ground[3][0], ground[3][1], HERO[PLAYER[0].ground[0][3]].img_Body1, HERO[PLAYER[0].ground[0][3]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[0][4] != 0) groundDisplay(ground[4][0], ground[4][1], HERO[PLAYER[0].ground[0][4]].img_Body1, HERO[PLAYER[0].ground[0][4]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[0][5] != 0) groundDisplay(ground[5][0], ground[5][1], HERO[PLAYER[0].ground[0][5]].img_Body1, HERO[PLAYER[0].ground[0][5]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[0][6] != 0) groundDisplay(ground[6][0], ground[6][1], HERO[PLAYER[0].ground[0][6]].img_Body1, HERO[PLAYER[0].ground[0][6]].img_Body2);//输出场上棋子图片

		if (PLAYER[0].groundempty[1][0] != 0) groundDisplay(ground[7][0], ground[7][1], HERO[PLAYER[0].ground[1][0]].img_Body1, HERO[PLAYER[0].ground[1][0]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[1][1] != 0) groundDisplay(ground[8][0], ground[8][1], HERO[PLAYER[0].ground[1][1]].img_Body1, HERO[PLAYER[0].ground[1][1]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[1][2] != 0) groundDisplay(ground[9][0], ground[9][1], HERO[PLAYER[0].ground[1][2]].img_Body1, HERO[PLAYER[0].ground[1][2]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[1][3] != 0) groundDisplay(ground[10][0], ground[10][1], HERO[PLAYER[0].ground[1][3]].img_Body1, HERO[PLAYER[0].ground[1][3]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[1][4] != 0) groundDisplay(ground[11][0], ground[11][1], HERO[PLAYER[0].ground[1][4]].img_Body1, HERO[PLAYER[0].ground[1][4]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[1][5] != 0) groundDisplay(ground[12][0], ground[12][1], HERO[PLAYER[0].ground[1][5]].img_Body1, HERO[PLAYER[0].ground[1][5]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[1][6] != 0) groundDisplay(ground[13][0], ground[13][1], HERO[PLAYER[0].ground[1][6]].img_Body1, HERO[PLAYER[0].ground[1][6]].img_Body2);//输出场上棋子图片

		if (PLAYER[0].groundempty[2][0] != 0) groundDisplay(ground[14][0], ground[14][1], HERO[PLAYER[0].ground[2][0]].img_Body1, HERO[PLAYER[0].ground[2][0]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[2][1] != 0) groundDisplay(ground[15][0], ground[15][1], HERO[PLAYER[0].ground[2][1]].img_Body1, HERO[PLAYER[0].ground[2][1]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[2][2] != 0) groundDisplay(ground[16][0], ground[16][1], HERO[PLAYER[0].ground[2][2]].img_Body1, HERO[PLAYER[0].ground[2][2]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[2][3] != 0) groundDisplay(ground[17][0], ground[17][1], HERO[PLAYER[0].ground[2][3]].img_Body1, HERO[PLAYER[0].ground[2][3]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[2][4] != 0) groundDisplay(ground[18][0], ground[18][1], HERO[PLAYER[0].ground[2][4]].img_Body1, HERO[PLAYER[0].ground[2][4]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[2][5] != 0) groundDisplay(ground[19][0], ground[19][1], HERO[PLAYER[0].ground[2][5]].img_Body1, HERO[PLAYER[0].ground[2][5]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[2][6] != 0) groundDisplay(ground[20][0], ground[20][1], HERO[PLAYER[0].ground[2][6]].img_Body1, HERO[PLAYER[0].ground[2][6]].img_Body2);//输出场上棋子图片

		if (PLAYER[0].groundempty[3][0] != 0) groundDisplay(ground[21][0], ground[21][1], HERO[PLAYER[0].ground[3][0]].img_Body1, HERO[PLAYER[0].ground[3][0]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[3][1] != 0) groundDisplay(ground[22][0], ground[22][1], HERO[PLAYER[0].ground[3][1]].img_Body1, HERO[PLAYER[0].ground[3][1]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[3][2] != 0) groundDisplay(ground[23][0], ground[23][1], HERO[PLAYER[0].ground[3][2]].img_Body1, HERO[PLAYER[0].ground[3][2]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[3][3] != 0) groundDisplay(ground[24][0], ground[24][1], HERO[PLAYER[0].ground[3][3]].img_Body1, HERO[PLAYER[0].ground[3][3]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[3][4] != 0) groundDisplay(ground[25][0], ground[25][1], HERO[PLAYER[0].ground[3][4]].img_Body1, HERO[PLAYER[0].ground[3][4]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[3][5] != 0) groundDisplay(ground[26][0], ground[26][1], HERO[PLAYER[0].ground[3][5]].img_Body1, HERO[PLAYER[0].ground[3][5]].img_Body2);//输出场上棋子图片
		if (PLAYER[0].groundempty[3][6] != 0) groundDisplay(ground[27][0], ground[27][1], HERO[PLAYER[0].ground[3][6]].img_Body1, HERO[PLAYER[0].ground[3][6]].img_Body2);//输出场上棋子图片

		//显示星级边框
		if (PLAYER[0].preparationseatempty[0] == 2)
		{
			putEdge1(preparationSeat1_x1, preparationSeat1_y1, img_twolevelsideBottom1, img_twolevelsideBottom2);
			putEdge2(preparationSeat1_x1, preparationSeat1_y1, img_twolevelsideSurface1, img_twolevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[1] == 2)
		{
			putEdge1(preparationSeat2_x1, preparationSeat2_y1, img_twolevelsideBottom1, img_twolevelsideBottom2);
			putEdge2(preparationSeat2_x1, preparationSeat2_y1, img_twolevelsideSurface1, img_twolevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[2] == 2)
		{
			putEdge1(preparationSeat3_x1, preparationSeat3_y1, img_twolevelsideBottom1, img_twolevelsideBottom2);
			putEdge2(preparationSeat3_x1, preparationSeat3_y1, img_twolevelsideSurface1, img_twolevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[3] == 2)
		{
			putEdge1(preparationSeat4_x1, preparationSeat4_y1, img_twolevelsideBottom1, img_twolevelsideBottom2);
			putEdge2(preparationSeat4_x1, preparationSeat4_y1, img_twolevelsideSurface1, img_twolevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[4] == 2)
		{
			putEdge1(preparationSeat5_x1, preparationSeat5_y1, img_twolevelsideBottom1, img_twolevelsideBottom2);
			putEdge2(preparationSeat5_x1, preparationSeat5_y1, img_twolevelsideSurface1, img_twolevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[5] == 2)
		{
			putEdge1(preparationSeat6_x1, preparationSeat6_y1, img_twolevelsideBottom1, img_twolevelsideBottom2);
			putEdge2(preparationSeat6_x1, preparationSeat6_y1, img_twolevelsideSurface1, img_twolevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[6] == 2)
		{
			putEdge1(preparationSeat7_x1, preparationSeat7_y1, img_twolevelsideBottom1, img_twolevelsideBottom2);
			putEdge2(preparationSeat7_x1, preparationSeat7_y1, img_twolevelsideSurface1, img_twolevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[7] == 2)
		{
			putEdge1(preparationSeat8_x1, preparationSeat8_y1, img_twolevelsideBottom1, img_twolevelsideBottom2);
			putEdge2(preparationSeat8_x1, preparationSeat8_y1, img_twolevelsideSurface1, img_twolevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[8] == 2)
		{
			putEdge1(preparationSeat9_x1, preparationSeat9_y1, img_twolevelsideBottom1, img_twolevelsideBottom2);
			putEdge2(preparationSeat9_x1, preparationSeat9_y1, img_twolevelsideSurface1, img_twolevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[0] == 3)
		{
			putEdge1(preparationSeat1_x1, preparationSeat1_y1, img_threelevelsideBottom1, img_threelevelsideBottom2);
			putEdge2(preparationSeat1_x1, preparationSeat1_y1, img_threelevelsideSurface1, img_threelevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[1] == 3)
		{
			putEdge1(preparationSeat2_x1, preparationSeat2_y1, img_threelevelsideBottom1, img_threelevelsideBottom2);
			putEdge2(preparationSeat2_x1, preparationSeat2_y1, img_threelevelsideSurface1, img_threelevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[2] == 3)
		{
			putEdge1(preparationSeat3_x1, preparationSeat3_y1, img_threelevelsideBottom1, img_threelevelsideBottom2);
			putEdge2(preparationSeat3_x1, preparationSeat3_y1, img_threelevelsideSurface1, img_threelevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[3] == 3)
		{
			putEdge1(preparationSeat4_x1, preparationSeat4_y1, img_threelevelsideBottom1, img_threelevelsideBottom2);
			putEdge2(preparationSeat4_x1, preparationSeat4_y1, img_threelevelsideSurface1, img_threelevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[4] == 3)
		{
			putEdge1(preparationSeat5_x1, preparationSeat5_y1, img_threelevelsideBottom1, img_threelevelsideBottom2);
			putEdge2(preparationSeat5_x1, preparationSeat5_y1, img_threelevelsideSurface1, img_threelevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[5] == 3)
		{
			putEdge1(preparationSeat6_x1, preparationSeat6_y1, img_threelevelsideBottom1, img_threelevelsideBottom2);
			putEdge2(preparationSeat6_x1, preparationSeat6_y1, img_threelevelsideSurface1, img_threelevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[6] == 3)
		{
			putEdge1(preparationSeat7_x1, preparationSeat7_y1, img_threelevelsideBottom1, img_threelevelsideBottom2);
			putEdge2(preparationSeat7_x1, preparationSeat7_y1, img_threelevelsideSurface1, img_threelevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[7] == 3)
		{
			putEdge1(preparationSeat8_x1, preparationSeat8_y1, img_threelevelsideBottom1, img_threelevelsideBottom2);
			putEdge2(preparationSeat8_x1, preparationSeat8_y1, img_threelevelsideSurface1, img_threelevelsideSurface2);
		}
		if (PLAYER[0].preparationseatempty[8] == 3)
		{
			putEdge1(preparationSeat9_x1, preparationSeat9_y1, img_threelevelsideBottom1, img_threelevelsideBottom2);
			putEdge2(preparationSeat9_x1, preparationSeat9_y1, img_threelevelsideSurface1, img_threelevelsideSurface2);
		}

		//显示是否能够升星
		levelupShow(PLAYER[0].shophero[0]);
		levelupShow(PLAYER[0].shophero[1]);
		levelupShow(PLAYER[0].shophero[2]);
		levelupShow(PLAYER[0].shophero[3]);
		levelupShow(PLAYER[0].shophero[4]);

		goldDisplay(PLAYER[0].goldcharacter, PLAYER[0].goldinteger);
		displayPopulation();//展示人口
		displayNumber();//展示概率数字
		freshshop++;
	}
}

void freeGame()//自由游戏 gameStatus == 2
{
	if (executebk == 1)
	{
		putImage(0, 0, img_freeGamebk1, img_freeGamebk2);
		putImage(0.251, 0.86, HERO[PLAYER[0].shophero[0]].img_Face1, HERO[PLAYER[0].shophero[0]].img_Face2);
		putImage(0.355, 0.86, HERO[PLAYER[0].shophero[1]].img_Face1, HERO[PLAYER[0].shophero[1]].img_Face2);
		putImage(0.46, 0.86, HERO[PLAYER[0].shophero[2]].img_Face1, HERO[PLAYER[0].shophero[2]].img_Face2);
		putImage(0.565, 0.86, HERO[PLAYER[0].shophero[3]].img_Face1, HERO[PLAYER[0].shophero[3]].img_Face2);
		putImage(0.67, 0.86, HERO[PLAYER[0].shophero[4]].img_Face1, HERO[PLAYER[0].shophero[4]].img_Face2);
		executebk = 0;
	}
}

void Collections()//藏品 gameStatus == 3
{
	putImage(0.0, 0.0, img_Collectionsbk1, img_Collectionsbk2);
}

void Setting()//设置 gameStatus == 4
{
	putImage(0, 0, img_Settingbk1, img_Settingbk2);
}

void startup()// 数据初始化	
{
	//初始化或刷新窗口大小
	freshScreen();

	//加载图片
	loadImage();
	//加载英雄
	loadHero();
	//初始化玩家
	loadPlayer();

	//播放音乐
	mciSendString(_T("open .\\music\\云顶平静bgm.mp3 alias bkmusic"), NULL, 0, NULL);//打开背景音乐
	mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);  // 循环播放

	// 获取窗口句柄
	HWND hwnd = GetHWnd();
	// 设置窗口标题文字
	SetWindowText(hwnd, _T("云顶棋子娱乐"));

	mouseClick = 0;
}

void loadPlayer()//初始化玩家
{
	//初始化商店能否购买
	PLAYER[0].shopable[0] = 1;
	PLAYER[0].shopable[1] = 1;
	PLAYER[0].shopable[2] = 1;
	PLAYER[0].shopable[3] = 1;
	PLAYER[0].shopable[4] = 1;

	//初始化经验
	PLAYER[0].levelexperience = 2;

	PLAYER[0].levelinteger[0] = 0;//1
	PLAYER[0].levelinteger[1] = 0;//2
	PLAYER[0].levelinteger[2] = 0;
	PLAYER[0].levelinteger[3] = 0;
	PLAYER[0].levelinteger[4] = 0;
	PLAYER[0].levelinteger[5] = 0;
	PLAYER[0].levelinteger[6] = 0;
	PLAYER[0].levelinteger[7] = 0;
	PLAYER[0].levelinteger[8] = 0;
	//初始化场上不满
	PLAYER[0].groundfull = 0;

	//初始化场上为空
	PLAYER[0].groundempty[0][0] = 0;
	PLAYER[0].groundempty[0][1] = 0;
	PLAYER[0].groundempty[0][2] = 0;
	PLAYER[0].groundempty[0][3] = 0;
	PLAYER[0].groundempty[0][4] = 0;
	PLAYER[0].groundempty[0][5] = 0;
	PLAYER[0].groundempty[0][6] = 0;
	PLAYER[0].groundempty[1][0] = 0;
	PLAYER[0].groundempty[1][1] = 0;
	PLAYER[0].groundempty[1][2] = 0;
	PLAYER[0].groundempty[1][3] = 0;
	PLAYER[0].groundempty[1][4] = 0;
	PLAYER[0].groundempty[1][5] = 0;
	PLAYER[0].groundempty[1][6] = 0;
	PLAYER[0].groundempty[2][0] = 0;
	PLAYER[0].groundempty[2][1] = 0;
	PLAYER[0].groundempty[2][2] = 0;
	PLAYER[0].groundempty[2][3] = 0;
	PLAYER[0].groundempty[2][4] = 0;
	PLAYER[0].groundempty[2][5] = 0;
	PLAYER[0].groundempty[2][6] = 0;
	PLAYER[0].groundempty[3][0] = 0;
	PLAYER[0].groundempty[3][1] = 0;
	PLAYER[0].groundempty[3][2] = 0;
	PLAYER[0].groundempty[3][3] = 0;
	PLAYER[0].groundempty[3][4] = 0;
	PLAYER[0].groundempty[3][5] = 0;
	PLAYER[0].groundempty[3][6] = 0;
	//初始化备战席不满
	PLAYER[0].preparationseatfull = 0;

	//初始化备战席为空
	PLAYER[0].preparationseatempty[0] = 0;
	PLAYER[0].preparationseatempty[1] = 0;
	PLAYER[0].preparationseatempty[2] = 0;
	PLAYER[0].preparationseatempty[3] = 0;
	PLAYER[0].preparationseatempty[4] = 0;
	PLAYER[0].preparationseatempty[5] = 0;
	PLAYER[0].preparationseatempty[6] = 0;
	PLAYER[0].preparationseatempty[7] = 0;
	PLAYER[0].preparationseatempty[8] = 0;

	//加载商店英雄
	PLAYER[0].shophero[0] = freshProbability();

	PLAYER[0].shophero[1] = freshProbability();

	PLAYER[0].shophero[2] = freshProbability();

	PLAYER[0].shophero[3] = freshProbability();

	PLAYER[0].shophero[4] = freshProbability();

	//初始化商店
	PLAYER[0].shopempty[0] = 1;
	PLAYER[0].shopempty[1] = 1;
	PLAYER[0].shopempty[2] = 1;
	PLAYER[0].shopempty[3] = 1;
	PLAYER[0].shopempty[4] = 1;

	//初始化金币
	PLAYER[0].goldinteger = 157;
}

void loadHero()//初始化59个棋子
{
	//棋子的数量
	HERO[0].number = 29;
	HERO[1].number = 29;
	HERO[2].number = 29;
	HERO[3].number = 29;
	HERO[4].number = 29;
	HERO[5].number = 29;
	HERO[6].number = 29;
	HERO[7].number = 29;
	HERO[8].number = 29;
	HERO[9].number = 29;
	HERO[10].number = 29;
	HERO[11].number = 29;
	HERO[12].number = 29;
	HERO[13].number = 22;
	HERO[14].number = 22;
	HERO[15].number = 22;
	HERO[16].number = 22;
	HERO[17].number = 22;
	HERO[18].number = 22;
	HERO[19].number = 22;
	HERO[20].number = 22;
	HERO[21].number = 22;
	HERO[22].number = 22;
	HERO[23].number = 22;
	HERO[24].number = 22;
	HERO[25].number = 22;
	HERO[26].number = 16;
	HERO[27].number = 16;
	HERO[28].number = 16;
	HERO[29].number = 16;
	HERO[30].number = 16;
	HERO[31].number = 16;
	HERO[32].number = 16;
	HERO[33].number = 16;
	HERO[34].number = 16;
	HERO[35].number = 16;
	HERO[36].number = 16;
	HERO[37].number = 16;
	HERO[38].number = 16;
	HERO[39].number = 12;
	HERO[40].number = 12;
	HERO[41].number = 12;
	HERO[42].number = 12;
	HERO[43].number = 12;
	HERO[44].number = 12;
	HERO[45].number = 12;
	HERO[46].number = 12;
	HERO[47].number = 12;
	HERO[48].number = 12;
	HERO[49].number = 12;
	HERO[50].number = 12;
	HERO[51].number = 10;
	HERO[52].number = 10;
	HERO[53].number = 10;
	HERO[54].number = 10;
	HERO[55].number = 10;
	HERO[56].number = 10;
	HERO[57].number = 10;
	HERO[58].number = 10;
	//棋子的价格
	HERO[0].gold = 1;
	HERO[1].gold = 1;
	HERO[2].gold = 1;
	HERO[3].gold = 1;
	HERO[4].gold = 1;
	HERO[5].gold = 1;
	HERO[6].gold = 1;
	HERO[7].gold = 1;
	HERO[8].gold = 1;
	HERO[9].gold = 1;
	HERO[10].gold = 1;
	HERO[11].gold = 1;
	HERO[12].gold = 1;
	HERO[13].gold = 2;
	HERO[14].gold = 2;
	HERO[15].gold = 2;
	HERO[16].gold = 2;
	HERO[17].gold = 2;
	HERO[18].gold = 2;
	HERO[19].gold = 2;
	HERO[20].gold = 2;
	HERO[21].gold = 2;
	HERO[22].gold = 2;
	HERO[23].gold = 2;
	HERO[24].gold = 2;
	HERO[25].gold = 2;
	HERO[26].gold = 3;
	HERO[27].gold = 3;
	HERO[28].gold = 3;
	HERO[29].gold = 3;
	HERO[30].gold = 3;
	HERO[31].gold = 3;
	HERO[32].gold = 3;
	HERO[33].gold = 3;
	HERO[34].gold = 3;
	HERO[35].gold = 3;
	HERO[36].gold = 3;
	HERO[37].gold = 3;
	HERO[38].gold = 3;
	HERO[39].gold = 4;
	HERO[40].gold = 4;
	HERO[41].gold = 4;
	HERO[42].gold = 4;
	HERO[43].gold = 4;
	HERO[44].gold = 4;
	HERO[45].gold = 4;
	HERO[46].gold = 4;
	HERO[47].gold = 4;
	HERO[48].gold = 4;
	HERO[49].gold = 4;
	HERO[50].gold = 4;
	HERO[51].gold = 5;
	HERO[52].gold = 5;
	HERO[53].gold = 5;
	HERO[54].gold = 5;
	HERO[55].gold = 5;
	HERO[56].gold = 5;
	HERO[57].gold = 5;
	HERO[58].gold = 5;
}

void playSound()//播放花钱的音乐
{
	mciSendString(_T("stop fgmusic"), NULL, 0, NULL);   // 先把前面一次的音乐停止
	mciSendString(_T("close fgmusic"), NULL, 0, NULL); // 先把前面一次的音乐关闭
	mciSendString(_T("open .\\music\\刷新商店.mp3 alias fgmusic"), NULL, 0, NULL); // 打开跳动音乐
	mciSendString(_T("play fgmusic"), NULL, 0, NULL); // 仅播放一次
}

void experienceDisplay()//显示经验
{
	double percent = 0;
	TCHAR LEVEL = 2 + '0';
	char temp[5] = "1234";
	//
	if (PLAYER[0].levelexperience == 2)
	{
		temp[0] = PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] + '0';
		temp[1] = '/';
		temp[2] = '2';
		temp[3] = NULL;
		LEVEL = 2 + '0';
		percent = (double)(PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1]) / 2;
	}
	if (PLAYER[0].levelexperience == 3)
	{
		temp[0] = PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] + '0';
		temp[1] = '/';
		temp[2] = '6';
		temp[3] = NULL;
		LEVEL = 3 + '0';
		percent = (double)(PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1]) / 6.0;
	}
	if (PLAYER[0].levelexperience == 4)
	{
		temp[0] = PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] + '0';
		temp[1] = '/';
		temp[2] = '1';
		temp[3] = '0';
		temp[4] = NULL;
		LEVEL = 4 + '0';
		percent = (double)(PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1]) / 10;
	}
	if (PLAYER[0].levelexperience == 5)
	{
		if (PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] < 10)
		{
			temp[0] = PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] + '0';
			temp[1] = '/';
			temp[2] = '2';
			temp[3] = '0';
			temp[4] = NULL;
			LEVEL = 5 + '0';
		}
		if (PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] >= 10)
		{
			temp[0] = PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] / 10 + '0';
			temp[1] = PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] % 10 + '0';
			temp[2] = '/';
			temp[3] = '2';
			temp[4] = '0';
			LEVEL = 5 + '0';
		}
		percent = (double)(PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1]) / 20;
	}
	if (PLAYER[0].levelexperience == 6)
	{
		if (PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] < 10)
		{
			temp[0] = PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] + '0';
			temp[1] = '/';
			temp[2] = '3';
			temp[3] = '6';
			temp[4] = NULL;
			LEVEL = 6 + '0';
		}
		if (PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] >= 10)
		{
			temp[0] = PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] / 10 + '0';
			temp[1] = PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] % 10 + '0';
			temp[2] = '/';
			temp[3] = '3';
			temp[4] = '6';
			LEVEL = 6 + '0';
		}
		percent = (double)(PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1]) / 36;
	}
	if (PLAYER[0].levelexperience == 7)
	{
		if (PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] < 10)
		{
			temp[0] = PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] + '0';
			temp[1] = '/';
			temp[2] = '5';
			temp[3] = '6';
			temp[4] = NULL;
			LEVEL = 7 + '0';
		}
		if (PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] >= 10)
		{
			temp[0] = PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] / 10 + '0';
			temp[1] = PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] % 10 + '0';
			temp[2] = '/';
			temp[3] = '5';
			temp[4] = '6';
			LEVEL = 7 + '0';
		}
		percent = (double)(PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1]) / 56;
		int a = 0;
	}
	if (PLAYER[0].levelexperience == 8)
	{
		if (PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] < 10)
		{
			temp[0] = PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] + '0';
			temp[1] = '/';
			temp[2] = '8';
			temp[3] = '0';
			temp[4] = NULL;
			LEVEL = 8 + '0';
		}
		if (PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] >= 10)
		{
			temp[0] = PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] / 10 + '0';
			temp[1] = PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] % 10 + '0';
			temp[2] = '/';
			temp[3] = '8';
			temp[4] = '0';
			LEVEL = 8 + '0';
		}
		percent = (double)(PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1]) / 80;
	}
	if (PLAYER[0].levelexperience == 9)
	{
		temp[0] = NULL;
		LEVEL = 9 + '0';
		percent = 1.0;
	}
	for (int i = 0; i < 5; i++) PLAYER[0].levelshow[i] = temp[i];
	//sprintf_s(temp, "%d", number);
	if (window == 2)
	{
		settextstyle(12, 0, _T("Arial"), 0, 0, 400, FALSE, FALSE, FALSE);
		setbkmode(TRANSPARENT);
		outtextxy((int)(width2 * 0.213), (int)(high2 * 0.824), PLAYER[0].levelshow);
		settextstyle(15, 0, _T("Arial"), 0, 0, 999, FALSE, FALSE, FALSE);
		setbkmode(TRANSPARENT);
		settextcolor(RGB(240, 230, 210));
		outtextxy((int)(width2 * 0.145), (int)(high2 * 0.815), LEVEL);
		outtextxy((int)(width2 * 0.152), (int)(high2 * 0.815), _T("级"));
		setlinestyle(PS_SOLID, 3);
		setlinecolor(RGB(156, 247, 255));
		int x1, y1, x2, y2;
		x1 = (int)(width2 * 0.14375);
		y1 = (int)(high2 * 0.8472);
		x2 = (int)(width2 * 0.14375) + (int)((width2 * 0.0953) * percent);
		y2 = (int)(high2 * 0.847222);
		line(x1, y1, x2, y2);

	}
	if (window == 0 || window == 1)
	{
		settextcolor(RGB(177, 216, 218));
		settextstyle(15, 0, _T("Arial"), 0, 0, 600, FALSE, FALSE, FALSE);
		setbkmode(TRANSPARENT);
		outtextxy((int)(width1 * 0.213), (int)(high1 * 0.824), PLAYER[0].levelshow);
		settextstyle(23, 0, _T("Arial"), 0, 0, 999, FALSE, FALSE, FALSE);
		setbkmode(TRANSPARENT);
		settextcolor(RGB(240, 230, 210));
		outtextxy((int)(width1 * 0.145), (int)(high1 * 0.815), LEVEL);
		outtextxy((int)(width1 * 0.152), (int)(high1 * 0.815), _T("级"));
		setlinestyle(PS_SOLID, 3);
		setlinecolor(RGB(156, 247, 255));
		int x1, y1, x2, y2;
		x1 = (int)(width1 * 0.14375);
		y1 = (int)(high1 * 0.8472);
		x2 = (int)(width1 * 0.14375) + (int)((width1 * 0.0953) * percent);
		y2 = (int)(high1 * 0.847222);
		line(x1, y1, x2, y2);
	}
}

void secondDisplay()//时间
{
	//时间
	GetLocalTime(&ti);//获取本地实时时间
	second[0] = ti.wSecond / 10 + 48;
	second[1] = ti.wSecond % 10 + 48;
	second[2] = NULL;
	if (window == 0 || window == 1)settextstyle(20, 0, _T("Arial"), 0, 0, 750, FALSE, FALSE, FALSE);
	if (window == 2)settextstyle(13, 0, _T("Arial"), 0, 0, 750, FALSE, FALSE, FALSE);
	setbkmode(TRANSPARENT);
	settextcolor(RGB(205, 190, 145));
	outtextxy((int)(Width * 0.597), (int)(High * 0.0094), second);
}

void goldDisplay(TCHAR(&num)[4], int number)//显示金币
{
	char temp[4];
	sprintf_s(temp, "%d", number);
	for (int i = 0; i < 4; i++)	num[i] = temp[i];
	if (window == 2)
	{
		//putimage((int)(width2 * 0.458), (int)(high2 * 0.815), (int)(width2 * 0.021), (int)(high2 * 0.028), &img_singleGamebk2, (int)(width2 * 0.458), (int)(high2 * 0.815));
		settextstyle(15, 0, _T("Arial"), 0, 0, 600, FALSE, FALSE, FALSE);
		setbkmode(TRANSPARENT);
		settextcolor(RGB(240, 230, 210));
		outtextxy((int)(width2 * 0.457), (int)(high2 * 0.816), num);
	}
	if (window == 0 || window == 1)
	{
		//putimage((int)(width1 * 0.458), (int)(high1 * 0.815), (int)(width1 * 0.021), (int)(high1 * 0.028), &img_singleGamebk1, (int)(width1 * 0.458), (int)(high1 * 0.815));
		settextstyle(23, 0, _T("Arial"), 0, 0, 500, FALSE, FALSE, FALSE);
		setbkmode(TRANSPARENT);
		settextcolor(RGB(240, 230, 210));
		outtextxy((int)(width1 * 0.455), (int)(high1 * 0.816), num);
	}
}

void putImage(double x, double y, IMAGE img_bk1, IMAGE img_bk2)//输出背景图片
{
	if (window == 2) putimage((int)(width2 * x), (int)(high2 * y), &img_bk2);
	if (window == 0 || window == 1) putimage((int)(width1 * x), (int)(high1 * y), &img_bk1);
}

void groundDisplay(double x, double y, IMAGE img_bk1, IMAGE img_bk2)//输出场上棋子图片
{
	if (window == 2) putimage((int)(x), (int)(y), &img_bk2);
	if (window == 0 || window == 1) putimage((int)(x), (int)(y), &img_bk1);
}

void putEffect1(double x, double y, IMAGE img_bk1, IMAGE img_bk2)//输出特效
{
	if (window == 2) putimage((int)(width2 * x), (int)(high2 * y), &img_bk2, SRCAND);
	if (window == 0 || window == 1) putimage((int)(width1 * x), (int)(high1 * y), &img_bk1, SRCAND);
}

void putEffect2(double x, double y, IMAGE img_bk1, IMAGE img_bk2)//输出特效
{
	if (window == 2) putimage((int)(width2 * x), (int)(high2 * y), &img_bk2, SRCPAINT);
	if (window == 0 || window == 1) putimage((int)(width1 * x), (int)(high1 * y), &img_bk1, SRCPAINT);
}

void putEdge1(double x, double y, IMAGE img_bk1, IMAGE img_bk2)//输出边框
{
	if (window == 2) putimage((int)x, (int)y, &img_bk2, SRCAND);
	if (window == 0 || window == 1) putimage((int)x, (int)y, &img_bk1, SRCAND);
}

void putEdge2(double x, double y, IMAGE img_bk1, IMAGE img_bk2)//输出边框
{
	if (window == 2) putimage((int)x, (int)y, &img_bk2, SRCPAINT);
	if (window == 0 || window == 1) putimage((int)x, (int)y, &img_bk1, SRCPAINT);
}

void loadImage()//加载图片
{
	//加载场上英雄头像
	loadimage(&HERO[0].img_Body1, _T(".\\herobody\\1加里奥.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[0].img_Body2, _T(".\\herobody\\1加里奥.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[1].img_Body1, _T(".\\herobody\\2凯尔.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[1].img_Body2, _T(".\\herobody\\2凯尔.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[2].img_Body1, _T(".\\herobody\\3艾希.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[2].img_Body2, _T(".\\herobody\\3艾希.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[3].img_Body1, _T(".\\herobody\\4普朗克.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[3].img_Body2, _T(".\\herobody\\4普朗克.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[4].img_Body1, _T(".\\herobody\\5布里茨.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[4].img_Body2, _T(".\\herobody\\5布里茨.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[5].img_Body1, _T(".\\herobody\\6雷克顿.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[5].img_Body2, _T(".\\herobody\\6雷克顿.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[6].img_Body1, _T(".\\herobody\\7孙悟空.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[6].img_Body2, _T(".\\herobody\\7孙悟空.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[7].img_Body1, _T(".\\herobody\\8内瑟斯.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[7].img_Body2, _T(".\\herobody\\8内瑟斯.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[8].img_Body1, _T(".\\herobody\\9波比.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[8].img_Body2, _T(".\\herobody\\9波比.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[9].img_Body1, _T(".\\herobody\\10泰隆.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[9].img_Body2, _T(".\\herobody\\10泰隆.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[10].img_Body1, _T(".\\herobody\\11拉克丝.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[10].img_Body2, _T(".\\herobody\\11拉克丝.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[11].img_Body1, _T(".\\herobody\\12璐璐.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[11].img_Body2, _T(".\\herobody\\12璐璐.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[12].img_Body1, _T(".\\herobody\\13塞拉斯.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[12].img_Body2, _T(".\\herobody\\13塞拉斯.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[13].img_Body1, _T(".\\herobody\\14安妮.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[13].img_Body2, _T(".\\herobody\\14安妮.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[14].img_Body1, _T(".\\herobody\\15希维尔.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[14].img_Body2, _T(".\\herobody\\15希维尔.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[15].img_Body1, _T(".\\herobody\\16墨菲特.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[15].img_Body2, _T(".\\herobody\\16墨菲特.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[16].img_Body1, _T(".\\herobody\\17李青.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[16].img_Body2, _T(".\\herobody\\17李青.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[17].img_Body1, _T(".\\herobody\\18伊泽瑞尔.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[17].img_Body2, _T(".\\herobody\\18伊泽瑞尔.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[18].img_Body1, _T(".\\herobody\\19菲欧娜.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[18].img_Body2, _T(".\\herobody\\19菲欧娜.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[19].img_Body1, _T(".\\herobody\\20德莱文.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[19].img_Body2, _T(".\\herobody\\20德莱文.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[20].img_Body1, _T(".\\herobody\\21亚索.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[20].img_Body2, _T(".\\herobody\\21亚索.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[21].img_Body1, _T(".\\herobody\\22卡密尔.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[21].img_Body2, _T(".\\herobody\\22卡密尔.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[22].img_Body1, _T(".\\herobody\\23金克丝.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[22].img_Body2, _T(".\\herobody\\23金克丝.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[23].img_Body1, _T(".\\herobody\\24蔚.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[23].img_Body2, _T(".\\herobody\\24蔚.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[24].img_Body1, _T(".\\herobody\\25悠米.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[24].img_Body2, _T(".\\herobody\\25悠米.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[25].img_Body1, _T(".\\herobody\\26芮尔.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[25].img_Body2, _T(".\\herobody\\26芮尔.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[26].img_Body1, _T(".\\herobody\\27乐芙兰.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[26].img_Body2, _T(".\\herobody\\27乐芙兰.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[27].img_Body1, _T(".\\herobody\\28阿利斯塔.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[27].img_Body2, _T(".\\herobody\\28阿利斯塔.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[28].img_Body1, _T(".\\herobody\\29贾克斯.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[28].img_Body2, _T(".\\herobody\\29贾克斯.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[29].img_Body1, _T(".\\herobody\\30科加斯.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[29].img_Body2, _T(".\\herobody\\30科加斯.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[30].img_Body1, _T(".\\herobody\\31拉莫斯.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[30].img_Body2, _T(".\\herobody\\31拉莫斯.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[31].img_Body1, _T(".\\herobody\\32娑娜.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[31].img_Body2, _T(".\\herobody\\32娑娜.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[32].img_Body1, _T(".\\herobody\\33薇恩.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[32].img_Body2, _T(".\\herobody\\33薇恩.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[33].img_Body1, _T(".\\herobody\\34锐雯.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[33].img_Body2, _T(".\\herobody\\34锐雯.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[34].img_Body1, _T(".\\herobody\\35佐伊.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[34].img_Body2, _T(".\\herobody\\35佐伊.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[35].img_Body1, _T(".\\herobody\\36卡莎.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[35].img_Body2, _T(".\\herobody\\36卡莎.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[36].img_Body1, _T(".\\herobody\\37维克兹.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[36].img_Body2, _T(".\\herobody\\37维克兹.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[37].img_Body1, _T(".\\herobody\\38赛娜.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[37].img_Body2, _T(".\\herobody\\38赛娜.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[38].img_Body1, _T(".\\herobody\\39尼菈.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[38].img_Body2, _T(".\\herobody\\39尼菈.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[39].img_Body1, _T(".\\herobody\\40索拉卡.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[39].img_Body2, _T(".\\herobody\\40索拉卡.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[40].img_Body1, _T(".\\herobody\\41厄运小姐.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[40].img_Body2, _T(".\\herobody\\41厄运小姐.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[41].img_Body1, _T(".\\herobody\\42瑟庄妮.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[41].img_Body2, _T(".\\herobody\\42瑟庄妮.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[42].img_Body1, _T(".\\herobody\\43索尔.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[42].img_Body2, _T(".\\herobody\\43索尔.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[43].img_Body1, _T(".\\herobody\\44扎克.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[43].img_Body2, _T(".\\herobody\\44扎克.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[44].img_Body1, _T(".\\herobody\\45塔莉垭.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[44].img_Body2, _T(".\\herobody\\45塔莉垭.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[45].img_Body1, _T(".\\herobody\\46卑尔维斯.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[45].img_Body2, _T(".\\herobody\\46卑尔维斯.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[46].img_Body1, _T(".\\herobody\\47佛耶戈.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[46].img_Body2, _T(".\\herobody\\47佛耶戈.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[47].img_Body1, _T(".\\herobody\\48劫.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[47].img_Body2, _T(".\\herobody\\48劫.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[48].img_Body1, _T(".\\herobody\\49艾克.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[48].img_Body2, _T(".\\herobody\\49艾克.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[49].img_Body1, _T(".\\herobody\\50莎弥拉.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[49].img_Body2, _T(".\\herobody\\50莎弥拉.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[50].img_Body1, _T(".\\herobody\\51瑟提.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[50].img_Body2, _T(".\\herobody\\51瑟提.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[51].img_Body1, _T(".\\herobody\\52厄加特.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[51].img_Body2, _T(".\\herobody\\52厄加特.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[52].img_Body1, _T(".\\herobody\\53费德提克.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[52].img_Body2, _T(".\\herobody\\53费德提克.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[53].img_Body1, _T(".\\herobody\\54努努.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[53].img_Body2, _T(".\\herobody\\54努努.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[54].img_Body1, _T(".\\herobody\\55迦娜.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[54].img_Body2, _T(".\\herobody\\55迦娜.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[55].img_Body1, _T(".\\herobody\\56莫德凯撒.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[55].img_Body2, _T(".\\herobody\\56莫德凯撒.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[56].img_Body1, _T(".\\herobody\\57蕾欧娜.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[56].img_Body2, _T(".\\herobody\\57蕾欧娜.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[57].img_Body1, _T(".\\herobody\\58辛德拉.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[57].img_Body2, _T(".\\herobody\\58辛德拉.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&HERO[58].img_Body1, _T(".\\herobody\\59厄斐琉斯.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&HERO[58].img_Body2, _T(".\\herobody\\59厄斐琉斯.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	//加载备战席
	loadimage(&HERO[0].img_Head1, _T(".\\herohead\\1加里奥.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[0].img_Head2, _T(".\\herohead\\1加里奥.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[1].img_Head1, _T(".\\herohead\\2凯尔.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[1].img_Head2, _T(".\\herohead\\2凯尔.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[2].img_Head1, _T(".\\herohead\\3艾希.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[2].img_Head2, _T(".\\herohead\\3艾希.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[3].img_Head1, _T(".\\herohead\\4普朗克.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[3].img_Head2, _T(".\\herohead\\4普朗克.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[4].img_Head1, _T(".\\herohead\\5布里茨.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[4].img_Head2, _T(".\\herohead\\5布里茨.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[5].img_Head1, _T(".\\herohead\\6雷克顿.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[5].img_Head2, _T(".\\herohead\\6雷克顿.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[6].img_Head1, _T(".\\herohead\\7孙悟空.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[6].img_Head2, _T(".\\herohead\\7孙悟空.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[7].img_Head1, _T(".\\herohead\\8内瑟斯.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[7].img_Head2, _T(".\\herohead\\8内瑟斯.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[8].img_Head1, _T(".\\herohead\\9波比.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[8].img_Head2, _T(".\\herohead\\9波比.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[9].img_Head1, _T(".\\herohead\\10泰隆.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[9].img_Head2, _T(".\\herohead\\10泰隆.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[10].img_Head1, _T(".\\herohead\\11拉克丝.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[10].img_Head2, _T(".\\herohead\\11拉克丝.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[11].img_Head1, _T(".\\herohead\\12璐璐.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[11].img_Head2, _T(".\\herohead\\12璐璐.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[12].img_Head1, _T(".\\herohead\\13塞拉斯.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[12].img_Head2, _T(".\\herohead\\13塞拉斯.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[13].img_Head1, _T(".\\herohead\\14安妮.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[13].img_Head2, _T(".\\herohead\\14安妮.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[14].img_Head1, _T(".\\herohead\\15希维尔.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[14].img_Head2, _T(".\\herohead\\15希维尔.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[15].img_Head1, _T(".\\herohead\\16墨菲特.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[15].img_Head2, _T(".\\herohead\\16墨菲特.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[16].img_Head1, _T(".\\herohead\\17李青.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[16].img_Head2, _T(".\\herohead\\17李青.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[17].img_Head1, _T(".\\herohead\\18伊泽瑞尔.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[17].img_Head2, _T(".\\herohead\\18伊泽瑞尔.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[18].img_Head1, _T(".\\herohead\\19菲欧娜.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[18].img_Head2, _T(".\\herohead\\19菲欧娜.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[19].img_Head1, _T(".\\herohead\\20德莱文.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[19].img_Head2, _T(".\\herohead\\20德莱文.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[20].img_Head1, _T(".\\herohead\\21亚索.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[20].img_Head2, _T(".\\herohead\\21亚索.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[21].img_Head1, _T(".\\herohead\\22卡密尔.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[21].img_Head2, _T(".\\herohead\\22卡密尔.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[22].img_Head1, _T(".\\herohead\\23金克丝.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[22].img_Head2, _T(".\\herohead\\23金克丝.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[23].img_Head1, _T(".\\herohead\\24蔚.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[23].img_Head2, _T(".\\herohead\\24蔚.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[24].img_Head1, _T(".\\herohead\\25悠米.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[24].img_Head2, _T(".\\herohead\\25悠米.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[25].img_Head1, _T(".\\herohead\\26芮尔.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[25].img_Head2, _T(".\\herohead\\26芮尔.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[26].img_Head1, _T(".\\herohead\\27乐芙兰.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[26].img_Head2, _T(".\\herohead\\27乐芙兰.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[27].img_Head1, _T(".\\herohead\\28阿利斯塔.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[27].img_Head2, _T(".\\herohead\\28阿利斯塔.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[28].img_Head1, _T(".\\herohead\\29贾克斯.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[28].img_Head2, _T(".\\herohead\\29贾克斯.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[29].img_Head1, _T(".\\herohead\\30科加斯.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[29].img_Head2, _T(".\\herohead\\30科加斯.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[30].img_Head1, _T(".\\herohead\\31拉莫斯.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[30].img_Head2, _T(".\\herohead\\31拉莫斯.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[31].img_Head1, _T(".\\herohead\\32娑娜.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[31].img_Head2, _T(".\\herohead\\32娑娜.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[32].img_Head1, _T(".\\herohead\\33薇恩.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[32].img_Head2, _T(".\\herohead\\33薇恩.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[33].img_Head1, _T(".\\herohead\\34锐雯.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[33].img_Head2, _T(".\\herohead\\34锐雯.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[34].img_Head1, _T(".\\herohead\\35佐伊.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[34].img_Head2, _T(".\\herohead\\35佐伊.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[35].img_Head1, _T(".\\herohead\\36卡莎.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[35].img_Head2, _T(".\\herohead\\36卡莎.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[36].img_Head1, _T(".\\herohead\\37维克兹.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[36].img_Head2, _T(".\\herohead\\37维克兹.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[37].img_Head1, _T(".\\herohead\\38赛娜.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[37].img_Head2, _T(".\\herohead\\38赛娜.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[38].img_Head1, _T(".\\herohead\\39尼菈.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[38].img_Head2, _T(".\\herohead\\39尼菈.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[39].img_Head1, _T(".\\herohead\\40索拉卡.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[39].img_Head2, _T(".\\herohead\\40索拉卡.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[40].img_Head1, _T(".\\herohead\\41厄运小姐.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[40].img_Head2, _T(".\\herohead\\41厄运小姐.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[41].img_Head1, _T(".\\herohead\\42瑟庄妮.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[41].img_Head2, _T(".\\herohead\\42瑟庄妮.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[42].img_Head1, _T(".\\herohead\\43索尔.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[42].img_Head2, _T(".\\herohead\\43索尔.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[43].img_Head1, _T(".\\herohead\\44扎克.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[43].img_Head2, _T(".\\herohead\\44扎克.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[44].img_Head1, _T(".\\herohead\\45塔莉垭.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[44].img_Head2, _T(".\\herohead\\45塔莉垭.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[45].img_Head1, _T(".\\herohead\\46卑尔维斯.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[45].img_Head2, _T(".\\herohead\\46卑尔维斯.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[46].img_Head1, _T(".\\herohead\\47佛耶戈.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[46].img_Head2, _T(".\\herohead\\47佛耶戈.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[47].img_Head1, _T(".\\herohead\\48劫.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[47].img_Head2, _T(".\\herohead\\48劫.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[48].img_Head1, _T(".\\herohead\\49艾克.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[48].img_Head2, _T(".\\herohead\\49艾克.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[49].img_Head1, _T(".\\herohead\\50莎弥拉.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[49].img_Head2, _T(".\\herohead\\50莎弥拉.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[50].img_Head1, _T(".\\herohead\\51瑟提.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[50].img_Head2, _T(".\\herohead\\51瑟提.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[51].img_Head1, _T(".\\herohead\\52厄加特.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[51].img_Head2, _T(".\\herohead\\52厄加特.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[52].img_Head1, _T(".\\herohead\\53费德提克.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[52].img_Head2, _T(".\\herohead\\53费德提克.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[53].img_Head1, _T(".\\herohead\\54努努.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[53].img_Head2, _T(".\\herohead\\54努努.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[54].img_Head1, _T(".\\herohead\\55迦娜.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[54].img_Head2, _T(".\\herohead\\55迦娜.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[55].img_Head1, _T(".\\herohead\\56莫德凯撒.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[55].img_Head2, _T(".\\herohead\\56莫德凯撒.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[56].img_Head1, _T(".\\herohead\\57蕾欧娜.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[56].img_Head2, _T(".\\herohead\\57蕾欧娜.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[57].img_Head1, _T(".\\herohead\\58辛德拉.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[57].img_Head2, _T(".\\herohead\\58辛德拉.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&HERO[58].img_Head1, _T(".\\herohead\\59厄斐琉斯.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&HERO[58].img_Head2, _T(".\\herohead\\59厄斐琉斯.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));

	//加载effect
	loadimage(&img_mouseSurface, _T(".\\effect\\鼠标表图.png"), (int)(width1 * 0.021), (int)(high1 * 0.037));
	loadimage(&img_mouseBottom, _T(".\\effect\\鼠标底图.png"), (int)(width1 * 0.021), (int)(high1 * 0.037));

	loadimage(&img_twolevelsideSurface1, _T(".\\effect\\二星边框表图.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&img_twolevelsideSurface2, _T(".\\effect\\二星边框表图.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&img_twolevelsideBottom1, _T(".\\effect\\二星边框底图.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&img_twolevelsideBottom2, _T(".\\effect\\二星边框底图.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&img_threelevelsideSurface1, _T(".\\effect\\三星边框表图.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&img_threelevelsideSurface2, _T(".\\effect\\三星边框表图.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&img_threelevelsideBottom1, _T(".\\effect\\三星边框底图.png"), (int)(width1 * 0.03125), (int)(high1 * 0.0556));
	loadimage(&img_threelevelsideBottom2, _T(".\\effect\\三星边框底图.png"), (int)(width2 * 0.03125), (int)(high2 * 0.0556));
	loadimage(&img_twoleveltipSurface1, _T(".\\effect\\二星提示表图.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&img_twoleveltipSurface2, _T(".\\effect\\二星提示表图.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&img_twoleveltipBottom1, _T(".\\effect\\二星提示底图.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&img_twoleveltipBottom2, _T(".\\effect\\二星提示底图.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&img_threeleveltipSurface1, _T(".\\effect\\三星提示表图.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&img_threeleveltipSurface2, _T(".\\effect\\三星提示表图.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&img_threeleveltipBottom1, _T(".\\effect\\三星提示底图.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&img_threeleveltipBottom2, _T(".\\effect\\三星提示底图.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&img_twoleveledgeSurface1, _T(".\\effect\\二星边框表图.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&img_twoleveledgeSurface2, _T(".\\effect\\二星边框表图.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&img_twoleveledgeBottom1, _T(".\\effect\\二星边框底图.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&img_twoleveledgeBottom2, _T(".\\effect\\二星边框底图.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&img_threeleveledgeSurface1, _T(".\\effect\\三星边框表图.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&img_threeleveledgeSurface2, _T(".\\effect\\三星边框表图.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));
	loadimage(&img_threeleveledgeBottom1, _T(".\\effect\\三星边框底图.png"), (int)(width1 * 0.047396), (int)(high1 * 0.035185));
	loadimage(&img_threeleveledgeBottom2, _T(".\\effect\\三星边框底图.png"), (int)(width2 * 0.047396), (int)(high2 * 0.035185));

	//加载HERO
	loadimage(&HERO[0].img_Face1, _T(".\\hero\\1加里奥.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[0].img_Face2, _T(".\\hero\\1加里奥.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[1].img_Face1, _T(".\\hero\\2凯尔.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[1].img_Face2, _T(".\\hero\\2凯尔.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[2].img_Face1, _T(".\\hero\\3艾希.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[2].img_Face2, _T(".\\hero\\3艾希.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[3].img_Face1, _T(".\\hero\\4普朗克.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[3].img_Face2, _T(".\\hero\\4普朗克.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[4].img_Face1, _T(".\\hero\\5布里茨.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[4].img_Face2, _T(".\\hero\\5布里茨.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[5].img_Face1, _T(".\\hero\\6雷克顿.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[5].img_Face2, _T(".\\hero\\6雷克顿.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[6].img_Face1, _T(".\\hero\\7孙悟空.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[6].img_Face2, _T(".\\hero\\7孙悟空.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[7].img_Face1, _T(".\\hero\\8内瑟斯.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[7].img_Face2, _T(".\\hero\\8内瑟斯.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[8].img_Face1, _T(".\\hero\\9波比.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[8].img_Face2, _T(".\\hero\\9波比.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[9].img_Face1, _T(".\\hero\\10泰隆.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[9].img_Face2, _T(".\\hero\\10泰隆.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[10].img_Face1, _T(".\\hero\\11拉克丝.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[10].img_Face2, _T(".\\hero\\11拉克丝.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[11].img_Face1, _T(".\\hero\\12璐璐.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[11].img_Face2, _T(".\\hero\\12璐璐.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[12].img_Face1, _T(".\\hero\\13塞拉斯.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[12].img_Face2, _T(".\\hero\\13塞拉斯.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[13].img_Face1, _T(".\\hero\\14安妮.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[13].img_Face2, _T(".\\hero\\14安妮.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[14].img_Face1, _T(".\\hero\\15希维尔.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[14].img_Face2, _T(".\\hero\\15希维尔.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[15].img_Face1, _T(".\\hero\\16墨菲特.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[15].img_Face2, _T(".\\hero\\16墨菲特.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[16].img_Face1, _T(".\\hero\\17李青.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[16].img_Face2, _T(".\\hero\\17李青.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[17].img_Face1, _T(".\\hero\\18伊泽瑞尔.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[17].img_Face2, _T(".\\hero\\18伊泽瑞尔.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[18].img_Face1, _T(".\\hero\\19菲欧娜.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[18].img_Face2, _T(".\\hero\\19菲欧娜.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[19].img_Face1, _T(".\\hero\\20德莱文.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[19].img_Face2, _T(".\\hero\\20德莱文.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[20].img_Face1, _T(".\\hero\\21亚索.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[20].img_Face2, _T(".\\hero\\21亚索.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[21].img_Face1, _T(".\\hero\\22卡密尔.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[21].img_Face2, _T(".\\hero\\22卡密尔.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[22].img_Face1, _T(".\\hero\\23金克丝.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[22].img_Face2, _T(".\\hero\\23金克丝.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[23].img_Face1, _T(".\\hero\\24蔚.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[23].img_Face2, _T(".\\hero\\24蔚.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[24].img_Face1, _T(".\\hero\\25悠米.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[24].img_Face2, _T(".\\hero\\25悠米.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[25].img_Face1, _T(".\\hero\\26芮尔.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[25].img_Face2, _T(".\\hero\\26芮尔.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[26].img_Face1, _T(".\\hero\\27乐芙兰.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[26].img_Face2, _T(".\\hero\\27乐芙兰.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[27].img_Face1, _T(".\\hero\\28阿利斯塔.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[27].img_Face2, _T(".\\hero\\28阿利斯塔.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[28].img_Face1, _T(".\\hero\\29贾克斯.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[28].img_Face2, _T(".\\hero\\29贾克斯.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[29].img_Face1, _T(".\\hero\\30科加斯.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[29].img_Face2, _T(".\\hero\\30科加斯.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[30].img_Face1, _T(".\\hero\\31拉莫斯.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[30].img_Face2, _T(".\\hero\\31拉莫斯.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[31].img_Face1, _T(".\\hero\\32娑娜.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[31].img_Face2, _T(".\\hero\\32娑娜.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[32].img_Face1, _T(".\\hero\\33薇恩.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[32].img_Face2, _T(".\\hero\\33薇恩.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[33].img_Face1, _T(".\\hero\\34锐雯.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[33].img_Face2, _T(".\\hero\\34锐雯.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[34].img_Face1, _T(".\\hero\\35佐伊.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[34].img_Face2, _T(".\\hero\\35佐伊.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[35].img_Face1, _T(".\\hero\\36卡莎.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[35].img_Face2, _T(".\\hero\\36卡莎.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[36].img_Face1, _T(".\\hero\\37维克兹.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[36].img_Face2, _T(".\\hero\\37维克兹.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[37].img_Face1, _T(".\\hero\\38赛娜.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[37].img_Face2, _T(".\\hero\\38赛娜.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[38].img_Face1, _T(".\\hero\\39尼菈.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[38].img_Face2, _T(".\\hero\\39尼菈.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[39].img_Face1, _T(".\\hero\\40索拉卡.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[39].img_Face2, _T(".\\hero\\40索拉卡.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[40].img_Face1, _T(".\\hero\\41厄运小姐.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[40].img_Face2, _T(".\\hero\\41厄运小姐.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[41].img_Face1, _T(".\\hero\\42瑟庄妮.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[41].img_Face2, _T(".\\hero\\42瑟庄妮.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[42].img_Face1, _T(".\\hero\\43索尔.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[42].img_Face2, _T(".\\hero\\43索尔.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[43].img_Face1, _T(".\\hero\\44扎克.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[43].img_Face2, _T(".\\hero\\44扎克.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[44].img_Face1, _T(".\\hero\\45塔莉垭.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[44].img_Face2, _T(".\\hero\\45塔莉垭.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[45].img_Face1, _T(".\\hero\\46卑尔维斯.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[45].img_Face2, _T(".\\hero\\46卑尔维斯.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[46].img_Face1, _T(".\\hero\\47佛耶戈.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[46].img_Face2, _T(".\\hero\\47佛耶戈.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[47].img_Face1, _T(".\\hero\\48劫.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[47].img_Face2, _T(".\\hero\\48劫.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[48].img_Face1, _T(".\\hero\\49艾克.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[48].img_Face2, _T(".\\hero\\49艾克.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[49].img_Face1, _T(".\\hero\\50莎弥拉.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[49].img_Face2, _T(".\\hero\\50莎弥拉.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[50].img_Face1, _T(".\\hero\\51瑟提.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[50].img_Face2, _T(".\\hero\\51瑟提.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[51].img_Face1, _T(".\\hero\\52厄加特.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[51].img_Face2, _T(".\\hero\\52厄加特.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[52].img_Face1, _T(".\\hero\\53费德提克.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[52].img_Face2, _T(".\\hero\\53费德提克.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[53].img_Face1, _T(".\\hero\\54努努.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[53].img_Face2, _T(".\\hero\\54努努.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[54].img_Face1, _T(".\\hero\\55迦娜.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[54].img_Face2, _T(".\\hero\\55迦娜.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[55].img_Face1, _T(".\\hero\\56莫德凯撒.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[55].img_Face2, _T(".\\hero\\56莫德凯撒.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[56].img_Face1, _T(".\\hero\\57蕾欧娜.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[56].img_Face2, _T(".\\hero\\57蕾欧娜.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[57].img_Face1, _T(".\\hero\\58辛德拉.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[57].img_Face2, _T(".\\hero\\58辛德拉.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));
	loadimage(&HERO[58].img_Face1, _T(".\\hero\\59厄斐琉斯.png"), (int)(width1 * 0.098), (int)(high1 * 0.13));
	loadimage(&HERO[58].img_Face2, _T(".\\hero\\59厄斐琉斯.png"), (int)(width2 * 0.098), (int)(high2 * 0.13));

	//加载background
	loadimage(&img_startMenubk1, _T(".\\background\\startMenubk.png"), width1, high1);
	loadimage(&img_startMenubk2, _T(".\\background\\startMenubk.png"), width2, high2);
	loadimage(&img_pauseMenubk1, _T(".\\background\\pauseMenubk.png"), width1, high1);
	loadimage(&img_pauseMenubk2, _T(".\\background\\pauseMenubk.png"), width2, high2);
	loadimage(&img_singleGamebk1, _T(".\\background\\singleGamebk.png"), width1, high1);
	loadimage(&img_singleGamebk2, _T(".\\background\\singleGamebk.png"), width2, high2);
	loadimage(&img_freeGamebk1, _T(".\\background\\freeGamebk.png"), width1, high1);
	loadimage(&img_freeGamebk2, _T(".\\background\\freeGamebk.png"), width2, high2);
	loadimage(&img_Collectionsbk1, _T(".\\background\\Collectionsbk.png"), width1, high1);
	loadimage(&img_Collectionsbk2, _T(".\\background\\Collectionsbk.png"), width2, high2);
	loadimage(&img_Settingbk1, _T(".\\background\\Settingbk.png"), width1, high1);
	loadimage(&img_Settingbk2, _T(".\\background\\Settingbk.png"), width2, high2);
}

void freshScreen()//初始化或刷新窗口大小
{
	if (window == 0 || window == 1)
	{
		Width = width1;// 规定游戏画面尺寸
		High = high1;
	}
	if (window == 2)
	{
		Width = width2;
		High = high2;
	}
	initgraph(Width, High);
	if (window == 0)
	{
		HWND hwndfs = GetHWnd();//全屏
		SetWindowLong(hwndfs, GWL_STYLE, GetWindowLong(hwndfs, GWL_STYLE) - WS_CAPTION);
		MoveWindow(hwndfs, 0, 0, Width, High, TRUE);
	}

	start[0] = (int)(Width * 0.8521);//商店升级窗口坐标
	start[1] = (int)(High * 0.82222);
	start[2] = (int)(Width * 0.98125);
	start[3] = (int)(High * 0.99259);

	shopUpgrate_x1 = (int)(Width * 0.143);//商店升级窗口坐标
	shopUpgrate_y1 = (int)(High * 0.859);
	shopUpgrate_x2 = (int)(Width * 0.242);
	shopUpgrate_y2 = (int)(High * 0.92);
	shopFresh_x1 = (int)(Width * 0.143);//商店刷新窗口坐标
	shopFresh_y1 = (int)(High * 0.93);
	shopFresh_x2 = (int)(Width * 0.242);
	shopFresh_y2 = (int)(High * 0.99);
	shopHero1_x1 = (int)(Width * 0.251);//商店判定坐标0.251, 0.86
	shopHero1_y1 = (int)(High * 0.86);
	shopHero1_x2 = (int)(Width * 0.349);
	shopHero1_y2 = (int)(High * 0.99);
	shopHero2_x1 = (int)(Width * 0.355);//商店第二个棋子的坐标
	shopHero2_y1 = (int)(High * 0.86);
	shopHero2_x2 = (int)(Width * 0.454);
	shopHero2_y2 = (int)(High * 0.99);
	shopHero3_x1 = (int)(Width * 0.46);//商店第三个棋子的坐标
	shopHero3_y1 = (int)(High * 0.86);
	shopHero3_x2 = (int)(Width * 0.558);
	shopHero3_y2 = (int)(High * 0.99);
	shopHero4_x1 = (int)(Width * 0.565);//商店第四个棋子的坐标
	shopHero4_y1 = (int)(High * 0.86);
	shopHero4_x2 = (int)(Width * 0.663);
	shopHero4_y2 = (int)(High * 0.99);
	shopHero5_x1 = (int)(Width * 0.68);//商店第五个棋子的坐标
	shopHero5_y1 = (int)(High * 0.86);
	shopHero5_x2 = (int)(Width * 0.768);
	shopHero5_y2 = (int)(High * 0.99);
	preparationSeat1_x1 = (int)(Width * 0.207);//备战席1坐标
	preparationSeat1_y1 = (int)(High * 0.698);
	preparationSeat1_x2 = (int)(Width * 0.238);
	preparationSeat1_y2 = (int)(High * 0.754);
	preparationSeat2_x1 = (int)(Width * 0.267);//备战席2坐标
	preparationSeat2_y1 = (int)(High * 0.698);
	preparationSeat2_x2 = (int)(Width * 0.29825);
	preparationSeat2_y2 = (int)(High * 0.754);
	preparationSeat3_x1 = (int)(Width * 0.327);//备战席3坐标
	preparationSeat3_y1 = (int)(High * 0.698);
	preparationSeat3_x2 = (int)(Width * 0.35825);
	preparationSeat3_y2 = (int)(High * 0.754);
	preparationSeat4_x1 = (int)(Width * 0.389);//备战席4坐标		
	preparationSeat4_y1 = (int)(High * 0.698);
	preparationSeat4_x2 = (int)(Width * 0.4202);
	preparationSeat4_y2 = (int)(High * 0.754);
	preparationSeat5_x1 = (int)(Width * 0.450);//备战席5坐标
	preparationSeat5_y1 = (int)(High * 0.698);
	preparationSeat5_x2 = (int)(Width * 0.48125);
	preparationSeat5_y2 = (int)(High * 0.754);
	preparationSeat6_x1 = (int)(Width * 0.512);//备战席6坐标
	preparationSeat6_y1 = (int)(High * 0.698);
	preparationSeat6_x2 = (int)(Width * 0.54325);
	preparationSeat6_y2 = (int)(High * 0.754);
	preparationSeat7_x1 = (int)(Width * 0.572);//备战席7坐标	
	preparationSeat7_y1 = (int)(High * 0.698);
	preparationSeat7_x2 = (int)(Width * 0.60325);
	preparationSeat7_y2 = (int)(High * 0.754);
	preparationSeat8_x1 = (int)(Width * 0.632);//备战席8坐标
	preparationSeat8_y1 = (int)(High * 0.698);
	preparationSeat8_x2 = (int)(Width * 0.668);
	preparationSeat8_y2 = (int)(High * 0.754);
	preparationSeat9_x1 = (int)(Width * 0.695);//备战席9坐标
	preparationSeat9_y1 = (int)(High * 0.698);
	preparationSeat9_x2 = (int)(Width * 0.73);
	preparationSeat9_y2 = (int)(High * 0.754);

	//场上棋子坐标
	ground[0][0] = (int)(Width * 0.2703);
	ground[0][1] = (int)(High * 0.3963);
	ground[0][2] = (int)(Width * 0.3167);
	ground[0][3] = (int)(High * 0.4315);
	ground[1][0] = (int)(Width * 0.329688);
	ground[1][1] = (int)(High * 0.3963);
	ground[1][2] = (int)(Width * 0.37656);
	ground[1][3] = (int)(High * 0.4315);
	ground[2][0] = (int)(Width * 0.38906);
	ground[2][1] = (int)(High * 0.3963);
	ground[2][2] = (int)(Width * 0.43646);
	ground[2][3] = (int)(High * 0.4315);
	ground[3][0] = (int)(Width * 0.44844);
	ground[3][1] = (int)(High * 0.3963);
	ground[3][2] = (int)(Width * 0.49635);
	ground[3][3] = (int)(High * 0.4315);
	ground[4][0] = (int)(Width * 0.50781);
	ground[4][1] = (int)(High * 0.3963);
	ground[4][2] = (int)(Width * 0.55625);
	ground[4][3] = (int)(High * 0.4315);
	ground[5][0] = (int)(Width * 0.56719);
	ground[5][1] = (int)(High * 0.3963);
	ground[5][2] = (int)(Width * 0.61615);
	ground[5][3] = (int)(High * 0.4315);
	ground[6][0] = (int)(Width * 0.62656);
	ground[6][1] = (int)(High * 0.3963);
	ground[6][2] = (int)(Width * 0.67604);
	ground[6][3] = (int)(High * 0.4315);

	ground[7][0] = (int)(Width * 0.29323);
	ground[7][1] = (int)(High * 0.460185);
	ground[7][2] = (int)(Width * 0.34062);
	ground[7][3] = (int)(High * 0.49815);
	ground[8][0] = (int)(Width * 0.354688);
	ground[8][1] = (int)(High * 0.460185);
	ground[8][2] = (int)(Width * 0.403125);
	ground[8][3] = (int)(High * 0.49815);
	ground[9][0] = (int)(Width * 0.4161458);
	ground[9][1] = (int)(High * 0.460185);
	ground[9][2] = (int)(Width * 0.4651);
	ground[9][3] = (int)(High * 0.49815);
	ground[10][0] = (int)(Width * 0.47708);
	ground[10][1] = (int)(High * 0.460185);
	ground[10][2] = (int)(Width * 0.5276);
	ground[10][3] = (int)(High * 0.49815);
	ground[11][0] = (int)(Width * 0.5401);
	ground[11][1] = (int)(High * 0.460185);
	ground[11][2] = (int)(Width * 0.58958);
	ground[11][3] = (int)(High * 0.49815);
	ground[12][0] = (int)(Width * 0.60208);
	ground[12][1] = (int)(High * 0.460185);
	ground[12][2] = (int)(Width * 0.65052);
	ground[12][3] = (int)(High * 0.49815);
	ground[13][0] = (int)(Width * 0.66406);
	ground[13][1] = (int)(High * 0.460185);
	ground[13][2] = (int)(Width * 0.71198);
	ground[13][3] = (int)(High * 0.49815);

	ground[14][0] = (int)(Width * 0.254167);
	ground[14][1] = (int)(High * 0.52963);
	ground[14][2] = (int)(Width * 0.303125);
	ground[14][3] = (int)(High * 0.57037);
	ground[15][0] = (int)(Width * 0.317188);
	ground[15][1] = (int)(High * 0.52963);
	ground[15][2] = (int)(Width * 0.367188);
	ground[15][3] = (int)(High * 0.57037);
	ground[16][0] = (int)(Width * 0.38073);
	ground[16][1] = (int)(High * 0.52963);
	ground[16][2] = (int)(Width * 0.43021);
	ground[16][3] = (int)(High * 0.57037);
	ground[17][0] = (int)(Width * 0.44428);
	ground[17][1] = (int)(High * 0.52963);
	ground[17][2] = (int)(Width * 0.49531);
	ground[17][3] = (int)(High * 0.57037);
	ground[18][0] = (int)(Width * 0.5104167);
	ground[18][1] = (int)(High * 0.52963);
	ground[18][2] = (int)(Width * 0.560938);
	ground[18][3] = (int)(High * 0.57037);
	ground[19][0] = (int)(Width * 0.572917);
	ground[19][1] = (int)(High * 0.52963);
	ground[19][2] = (int)(Width * 0.62447);
	ground[19][3] = (int)(High * 0.57037);
	ground[20][0] = (int)(Width * 0.63802);
	ground[20][1] = (int)(High * 0.52963);
	ground[20][2] = (int)(Width * 0.6875);
	ground[20][3] = (int)(High * 0.57037);

	ground[21][0] = (int)(Width * 0.2776);
	ground[21][1] = (int)(High * 0.60463);
	ground[21][2] = (int)(Width * 0.329167);
	ground[21][3] = (int)(High * 0.64722);
	ground[22][0] = (int)(Width * 0.34323);
	ground[22][1] = (int)(High * 0.60463);
	ground[22][2] = (int)(Width * 0.395833);
	ground[22][3] = (int)(High * 0.64722);
	ground[23][0] = (int)(Width * 0.4104167);
	ground[23][1] = (int)(High * 0.60463);
	ground[23][2] = (int)(Width * 0.46198);
	ground[23][3] = (int)(High * 0.64722);
	ground[24][0] = (int)(Width * 0.47656);
	ground[24][1] = (int)(High * 0.60463);
	ground[24][2] = (int)(Width * 0.529167);
	ground[24][3] = (int)(High * 0.64722);
	ground[25][0] = (int)(Width * 0.54375);
	ground[25][1] = (int)(High * 0.60463);
	ground[25][2] = (int)(Width * 0.59427);
	ground[25][3] = (int)(High * 0.64722);
	ground[26][0] = (int)(Width * 0.609375);
	ground[26][1] = (int)(High * 0.60463);
	ground[26][2] = (int)(Width * 0.66094);
	ground[26][3] = (int)(High * 0.64722);
	ground[27][0] = (int)(Width * 0.67708);
	ground[27][1] = (int)(High * 0.60463);
	ground[27][2] = (int)(Width * 0.72604);
	ground[27][3] = (int)(High * 0.64722);
}

void show()// 显示画面
{
	//游戏状态:0为开始菜单,1为单人游戏,2为自由游戏,3为藏品,4为设置,5为退出游戏，6为暂停
	if (gameStatus == 0)// 初始菜单界面
		startMenu(); // 初始菜单界面
	if (gameStatus == 1)
		singleGame();//单人游戏
	if (gameStatus == 2)
		freeGame();//自由游戏
	if (gameStatus == 3)
		Collections();//藏品
	if (gameStatus == 4)
		Setting();//设置
	if (gameStatus == 5)
		Exit();//退出游戏
	if (gameStatus == 6)
		singleGame();//暂停
}

void updateWithoutInput()// 与用户输入无关的更新
{

}

void updateWithInput()// 与用户输入有关的更新
{
	ExMessage m;		// 定义鼠标消息
	m = getmessage(EX_MOUSE | EX_KEY);
	switch (m.message)
	{
		case WM_MOUSEMOVE: 
			checkFull();//检测备战席是否满了
			break;
		case WM_LBUTTONUP:
			//棋子的移动
			if (gameStatus == 0)
			{
				if (m.x >= start[0] && m.x <= start[2] && m.y >= start[1] && m.y <= start[3])
				{
					gameStatus = 1;
				}
			}
			if (gameStatus == 1 || gameStatus == 2)//棋子的移动
			{
				//棋盘
				//1
				if (m.x >= ground[0][0] && m.x <= ground[0][2] && m.y >= ground[0][1] && m.y <= ground[0][3])
				{
					if (!PLAYER[0].groundempty[0][0] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[0][0] = mouseClick;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
						PLAYER[0].ground[0][0] = mouseMessage;
					}
					else if (!PLAYER[0].groundempty[0][0] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[0][0] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[0][0];
						hero = PLAYER[0].ground[0][0];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[0][0] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[0][0] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[0][0] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[0][0] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[0][0] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[0][0];
						mouseMessage = PLAYER[0].ground[0][0];
						mousePostion = 1;
					}
				}
				//2
				if (m.x >= ground[1][0] && m.x <= ground[1][2] && m.y >= ground[1][1] && m.y <= ground[1][3])
				{
					if (!PLAYER[0].groundempty[0][1] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[0][1] = mouseClick;
						PLAYER[0].ground[0][1] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[0][1] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[0][1] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[0][1];
						hero = PLAYER[0].ground[0][1];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[0][1] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[0][1] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[0][1] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[0][1] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[0][1] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[0][1];
						mouseMessage = PLAYER[0].ground[0][1];
						mousePostion = 2;
					}
				}
				//3
				if (m.x >= ground[2][0] && m.x <= ground[2][2] && m.y >= ground[2][1] && m.y <= ground[2][3])
				{
					if (!PLAYER[0].groundempty[0][2] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[0][2] = mouseClick;
						PLAYER[0].ground[0][2] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[0][2] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					if (PLAYER[0].groundempty[0][2] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[0][2];
						hero = PLAYER[0].ground[0][2];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[0][2] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[0][2] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[0][2] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[0][2] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					if (PLAYER[0].groundempty[0][2] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[0][2];
						mouseMessage = PLAYER[0].ground[0][2];
						mousePostion = 3;
					}
				}
				//4
				if (m.x >= ground[3][0] && m.x <= ground[3][2] && m.y >= ground[3][1] && m.y <= ground[3][3])
				{
					if (!PLAYER[0].groundempty[0][3] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[0][3] = mouseClick;
						PLAYER[0].ground[0][3] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[0][3] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[0][3] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[0][3];
						hero = PLAYER[0].ground[0][3];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[0][3] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[0][3] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[0][3] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[0][3] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[0][3] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[0][3];
						mouseMessage = PLAYER[0].ground[0][3];
						mousePostion = 4;
					}
				}
				//5
				if (m.x >= ground[4][0] && m.x <= ground[4][2] && m.y >= ground[4][1] && m.y <= ground[4][3])
				{
					if (!PLAYER[0].groundempty[0][4] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[0][4] = mouseClick;
						PLAYER[0].ground[0][4] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[0][4] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[0][4] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[0][4];
						hero = PLAYER[0].ground[0][4];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[0][4] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[0][4] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[0][4] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[0][4] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[0][4] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[0][4];
						mouseMessage = PLAYER[0].ground[0][4];
						mousePostion = 5;
					}
				}
				//6
				if (m.x >= ground[5][0] && m.x <= ground[5][2] && m.y >= ground[5][1] && m.y <= ground[5][3])
				{
					if (!PLAYER[0].groundempty[0][5] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[0][5] = mouseClick;
						PLAYER[0].ground[0][5] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[0][5] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[0][5] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[0][5];
						hero = PLAYER[0].ground[0][5];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[0][5] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[0][5] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[0][5] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[0][5] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[0][5] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[0][5];
						mouseMessage = PLAYER[0].ground[0][5];
						mousePostion = 6;
					}
				}
				//7
				if (m.x >= ground[6][0] && m.x <= ground[6][2] && m.y >= ground[6][1] && m.y <= ground[6][3])
				{
					if (!PLAYER[0].groundempty[0][6] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[0][6] = mouseClick;
						PLAYER[0].ground[0][6] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[0][6] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[0][6] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[0][6];
						hero = PLAYER[0].ground[0][6];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[0][6] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[0][6] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[0][6] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[0][6] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[0][6] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[0][6];
						mouseMessage = PLAYER[0].ground[0][6];
						mousePostion = 7;
					}
				}
				//8
				if (m.x >= ground[7][0] && m.x <= ground[7][2] && m.y >= ground[7][1] && m.y <= ground[7][3])
				{
					if (!PLAYER[0].groundempty[1][0] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[1][0] = mouseClick;
						PLAYER[0].ground[1][0] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[1][0] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[1][0] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[1][0];
						hero = PLAYER[0].ground[1][0];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[1][0] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[1][0] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[1][0] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[1][0] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[1][0] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[1][0];
						mouseMessage = PLAYER[0].ground[1][0];
						mousePostion = 8;
					}
				}
				//9
				if (m.x >= ground[8][0] && m.x <= ground[8][2] && m.y >= ground[8][1] && m.y <= ground[8][3])
				{
					if (!PLAYER[0].groundempty[1][1] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[1][1] = mouseClick;
						PLAYER[0].ground[1][1] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[1][1] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[1][1] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[1][1];
						hero = PLAYER[0].ground[1][1];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[1][1] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[1][1] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[1][1] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[1][1] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[1][1] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[1][1];
						mouseMessage = PLAYER[0].ground[1][1];
						mousePostion = 9;
					}
				}
				//10
				if (m.x >= ground[9][0] && m.x <= ground[9][2] && m.y >= ground[9][1] && m.y <= ground[9][3])
				{
					if (!PLAYER[0].groundempty[1][2] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[1][2] = mouseClick;
						PLAYER[0].ground[1][2] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[1][2] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[1][2] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[1][2];
						hero = PLAYER[0].ground[1][2];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[1][2] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[1][2] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[1][2] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[1][2] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[1][2] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[1][2];
						mouseMessage = PLAYER[0].ground[1][2];
						mousePostion = 10;
					}
				}
				//11
				if (m.x >= ground[10][0] && m.x <= ground[10][2] && m.y >= ground[10][1] && m.y <= ground[10][3])
				{
					if (!PLAYER[0].groundempty[1][3] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[1][3] = mouseClick;
						PLAYER[0].ground[1][3] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[1][3] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[1][3] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[1][3];
						hero = PLAYER[0].ground[1][3];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[1][3] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[1][3] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[1][3] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[1][3] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[1][3] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[1][3];
						mouseMessage = PLAYER[0].ground[1][3];
						mousePostion = 11;
					}
				}
				//12
				if (m.x >= ground[11][0] && m.x <= ground[11][2] && m.y >= ground[11][1] && m.y <= ground[11][3])
				{
					if (!PLAYER[0].groundempty[1][4] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[1][4] = mouseClick;
						PLAYER[0].ground[1][4] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[1][4] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[1][4] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[1][4];
						hero = PLAYER[0].ground[1][4];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[1][4] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[1][4] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[1][4] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[1][4] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[1][4] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[1][4];
						mouseMessage = PLAYER[0].ground[1][4];
						mousePostion = 12;
					}
				}
				//13
				if (m.x >= ground[12][0] && m.x <= ground[12][2] && m.y >= ground[12][1] && m.y <= ground[12][3])
				{
					if (!PLAYER[0].groundempty[1][5] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[1][5] = mouseClick;
						PLAYER[0].ground[1][5] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[1][5] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[1][5] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[1][5];
						hero = PLAYER[0].ground[1][5];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[1][5] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[1][5] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[1][5] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[1][5] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[1][5] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[1][5];
						mouseMessage = PLAYER[0].ground[1][5];
						mousePostion = 13;
					}
				}
				//14
				if (m.x >= ground[13][0] && m.x <= ground[13][2] && m.y >= ground[13][1] && m.y <= ground[13][3])
				{
					if (!PLAYER[0].groundempty[1][6] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[1][6] = mouseClick;
						PLAYER[0].ground[1][6] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[1][6] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[1][6] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[1][6];
						hero = PLAYER[0].ground[1][6];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[1][6] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[1][6] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[1][6] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[1][6] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[1][6] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[1][6];
						mouseMessage = PLAYER[0].ground[1][6];
						mousePostion = 14;
					}
				}
				//15
				if (m.x >= ground[14][0] && m.x <= ground[14][2] && m.y >= ground[14][1] && m.y <= ground[14][3])
				{
					if (!PLAYER[0].groundempty[2][0] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[2][0] = mouseClick;
						PLAYER[0].ground[2][0] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[2][0] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[2][0] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[2][0];
						hero = PLAYER[0].ground[2][0];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[2][0] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[2][0] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[2][0] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[2][0] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[2][0] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[2][0];
						mouseMessage = PLAYER[0].ground[2][0];
						mousePostion = 15;
					}
				}
				//16
				if (m.x >= ground[15][0] && m.x <= ground[15][2] && m.y >= ground[15][1] && m.y <= ground[15][3])
				{
					if (!PLAYER[0].groundempty[2][1] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[2][1] = mouseClick;
						PLAYER[0].ground[2][1] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[2][1] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[2][1] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[2][1];
						hero = PLAYER[0].ground[2][1];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[2][1] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[2][1] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[2][1] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[2][1] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[2][1] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[2][1];
						mouseMessage = PLAYER[0].ground[2][1];
						mousePostion = 16;
					}
				}
				//17
				if (m.x >= ground[16][0] && m.x <= ground[16][2] && m.y >= ground[16][1] && m.y <= ground[16][3])
				{
					if (!PLAYER[0].groundempty[2][2] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[2][2] = mouseClick;
						PLAYER[0].ground[2][2] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[2][2] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[2][2] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[2][2];
						hero = PLAYER[0].ground[2][2];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[2][2] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[2][2] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[2][2] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[2][2] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[2][2] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[2][2];
						mouseMessage = PLAYER[0].ground[2][2];
						mousePostion = 17;
					}
				}
				//18
				if (m.x >= ground[17][0] && m.x <= ground[17][2] && m.y >= ground[17][1] && m.y <= ground[17][3])
				{
					if (!PLAYER[0].groundempty[2][3] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[2][3] = mouseClick;
						PLAYER[0].ground[2][3] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[2][3] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[2][3] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[2][3];
						hero = PLAYER[0].ground[2][3];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[2][3] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[2][3] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[2][3] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[2][3] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[2][3] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[2][3];
						mouseMessage = PLAYER[0].ground[2][3];
						mousePostion = 18;
					}
				}
				//19
				if (m.x >= ground[18][0] && m.x <= ground[18][2] && m.y >= ground[18][1] && m.y <= ground[18][3])
				{
					if (!PLAYER[0].groundempty[2][4] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[2][4] = mouseClick;
						PLAYER[0].ground[2][4] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[2][4] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[2][4] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[2][4];
						hero = PLAYER[0].ground[2][4];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[2][4] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[2][4] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[2][4] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[2][4] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[2][4] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[2][4];
						mouseMessage = PLAYER[0].ground[2][4];
						mousePostion = 19;
					}
				}
				//20
				if (m.x >= ground[19][0] && m.x <= ground[19][2] && m.y >= ground[19][1] && m.y <= ground[19][3])
				{
					if (!PLAYER[0].groundempty[2][5] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[2][5] = mouseClick;
						PLAYER[0].ground[2][5] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[2][5] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[2][5] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[2][5];
						hero = PLAYER[0].ground[2][5];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[2][5] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[2][5] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[2][5] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[2][5] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[2][5] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[2][5];
						mouseMessage = PLAYER[0].ground[2][5];
						mousePostion = 20;
					}
				}
				//21
				if (m.x >= ground[20][0] && m.x <= ground[20][2] && m.y >= ground[20][1] && m.y <= ground[20][3])
				{
					if (!PLAYER[0].groundempty[2][6] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[2][6] = mouseClick;
						PLAYER[0].ground[2][6] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[2][6] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[2][6] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[2][6];
						hero = PLAYER[0].ground[2][6];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[2][6] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[2][6] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[2][6] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[2][6] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[2][6] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[2][6];
						mouseMessage = PLAYER[0].ground[2][6];
						mousePostion = 21;
					}
				}
				//22
				if (m.x >= ground[21][0] && m.x <= ground[21][2] && m.y >= ground[21][1] && m.y <= ground[21][3])
				{
					if (!PLAYER[0].groundempty[3][0] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[3][0] = mouseClick;
						PLAYER[0].ground[3][0] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[3][0] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[3][0] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[3][0];
						hero = PLAYER[0].ground[3][0];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[3][0] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[3][0] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[3][0] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[3][0] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[3][0] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[3][0];
						mouseMessage = PLAYER[0].ground[3][0];
						mousePostion = 22;
					}
				}
				//23
				if (m.x >= ground[22][0] && m.x <= ground[22][2] && m.y >= ground[22][1] && m.y <= ground[22][3])
				{
					if (!PLAYER[0].groundempty[3][1] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[3][1] = mouseClick;
						PLAYER[0].ground[3][1] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[3][1] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[3][1] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[3][1];
						hero = PLAYER[0].ground[3][1];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[3][1] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[3][1] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[3][1] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[3][1] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[3][1] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[3][1];
						mouseMessage = PLAYER[0].ground[3][1];
						mousePostion = 23;
					}
				}
				//24
				if (m.x >= ground[23][0] && m.x <= ground[23][2] && m.y >= ground[23][1] && m.y <= ground[23][3])
				{
					if (!PLAYER[0].groundempty[3][2] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[3][2] = mouseClick;
						PLAYER[0].ground[3][2] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[3][2] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[3][2] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[3][2];
						hero = PLAYER[0].ground[3][2];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[3][2] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[3][2] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[3][2] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[3][2] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[3][2] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[3][2];
						mouseMessage = PLAYER[0].ground[3][2];
						mousePostion = 24;
					}
				}
				//25
				if (m.x >= ground[24][0] && m.x <= ground[24][2] && m.y >= ground[24][1] && m.y <= ground[24][3])
				{
					if (!PLAYER[0].groundempty[3][3] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[3][3] = mouseClick;
						PLAYER[0].ground[3][3] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[3][3] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[3][3] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[3][3];
						hero = PLAYER[0].ground[3][3];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[3][3] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[3][3] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[3][3] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[3][3] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[3][3] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[3][3];
						mouseMessage = PLAYER[0].ground[3][3];
						mousePostion = 25;
					}
				}
				//26
				if (m.x >= ground[25][0] && m.x <= ground[25][2] && m.y >= ground[25][1] && m.y <= ground[25][3])
				{
					if (!PLAYER[0].groundempty[3][4] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[3][4] = mouseClick;
						PLAYER[0].ground[3][4] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[3][4] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[3][4] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[3][4];
						hero = PLAYER[0].ground[3][4];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[3][4] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[3][4] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[3][4] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[3][4] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[3][4] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[3][4];
						mouseMessage = PLAYER[0].ground[3][4];
						mousePostion = 26;
					}
				}
				//27
				if (m.x >= ground[26][0] && m.x <= ground[26][2] && m.y >= ground[26][1] && m.y <= ground[26][3])
				{
					if (!PLAYER[0].groundempty[3][5] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[3][5] = mouseClick;
						PLAYER[0].ground[3][5] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[3][5] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[3][5] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[3][5];
						hero = PLAYER[0].ground[3][5];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[3][5] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[3][5] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[3][5] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[3][5] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[3][5] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[3][5];
						mouseMessage = PLAYER[0].ground[3][5];
						mousePostion = 27;
					}
				}
				//28
				if (m.x >= ground[27][0] && m.x <= ground[27][2] && m.y >= ground[27][1] && m.y <= ground[27][3])
				{
					if (!PLAYER[0].groundempty[3][6] && mouseClick != 0 && PLAYER[0].groundfull != 1)//棋盘为空，把棋子放到这
					{
						PLAYER[0].groundempty[3][6] = mouseClick;
						PLAYER[0].ground[3][6] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (!PLAYER[0].groundempty[3][6] && mouseClick != 0 && PLAYER[0].groundfull == 1)
					{
						mouseClick = 1;
					}
					else if (PLAYER[0].groundempty[3][6] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].groundempty[3][6];
						hero = PLAYER[0].ground[3][6];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].groundempty[3][6] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].ground[3][6] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].ground[3][6] = PLAYER[0].ground[row][column];
							PLAYER[0].groundempty[3][6] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].groundempty[3][6] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].groundempty[3][6];
						mouseMessage = PLAYER[0].ground[3][6];
						mousePostion = 28;
					}
				}
			}
			if (gameStatus == 1 || gameStatus == 2)
			{
				//备战席
				//29
				if (m.x >= preparationSeat1_x1 && m.x <= preparationSeat1_x2 && m.y >= preparationSeat1_y1 && m.y <= preparationSeat1_y2)
				{
					if (!PLAYER[0].preparationseatempty[0] && mouseClick != 0)//棋盘为空，把棋子放到这
					{
						PLAYER[0].preparationseatempty[0] = mouseClick;
						PLAYER[0].preparationseat[0] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (PLAYER[0].preparationseatempty[0] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].preparationseatempty[0];
						hero = PLAYER[0].preparationseat[0];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[0] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].preparationseat[0] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].preparationseat[0] = PLAYER[0].ground[row][column];
							PLAYER[0].preparationseatempty[0] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].preparationseatempty[0] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].preparationseatempty[0];
						mouseMessage = PLAYER[0].preparationseat[0];
						mousePostion = 29;
					}
				}
				//30
				if (m.x >= preparationSeat2_x1 && m.x <= preparationSeat2_x2 && m.y >= preparationSeat2_y1 && m.y <= preparationSeat2_y2)
				{
					if (!PLAYER[0].preparationseatempty[1] && mouseClick != 0)//棋盘为空，把棋子放到这
					{
						PLAYER[0].preparationseatempty[1] = mouseClick;
						PLAYER[0].preparationseat[1] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (PLAYER[0].preparationseatempty[1] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].preparationseatempty[1];
						hero = PLAYER[0].preparationseat[1];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[1] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].preparationseat[1] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].preparationseat[1] = PLAYER[0].ground[row][column];
							PLAYER[0].preparationseatempty[1] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].preparationseatempty[1] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].preparationseatempty[1];
						mouseMessage = PLAYER[0].preparationseat[1];
						mousePostion = 30;
					}
				}
				//31
				if (m.x >= preparationSeat3_x1 && m.x <= preparationSeat3_x2 && m.y >= preparationSeat3_y1 && m.y <= preparationSeat3_y2)
				{
					if (!PLAYER[0].preparationseatempty[2] && mouseClick != 0)//棋盘为空，把棋子放到这
					{
						PLAYER[0].preparationseatempty[2] = mouseClick;
						PLAYER[0].preparationseat[2] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (PLAYER[0].preparationseatempty[2] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].preparationseatempty[2];
						hero = PLAYER[0].preparationseat[2];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[2] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].preparationseat[2] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].preparationseat[2] = PLAYER[0].ground[row][column];
							PLAYER[0].preparationseatempty[2] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].preparationseatempty[2] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].preparationseatempty[2];
						mouseMessage = PLAYER[0].preparationseat[2];
						mousePostion = 31;
					}
				}
				//32
				if (m.x >= preparationSeat4_x1 && m.x <= preparationSeat4_x2 && m.y >= preparationSeat4_y1 && m.y <= preparationSeat4_y2)
				{
					if (!PLAYER[0].preparationseatempty[3] && mouseClick != 0)//棋盘为空，把棋子放到这
					{
						PLAYER[0].preparationseatempty[3] = mouseClick;
						PLAYER[0].preparationseat[3] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					else if (PLAYER[0].preparationseatempty[3] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].preparationseatempty[3];
						hero = PLAYER[0].preparationseat[3];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[3] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].preparationseat[3] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].preparationseat[3] = PLAYER[0].ground[row][column];
							PLAYER[0].preparationseatempty[3] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					else if (PLAYER[0].preparationseatempty[3] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].preparationseatempty[3];
						mouseMessage = PLAYER[0].preparationseat[3];
						mousePostion = 32;
					}
				}
				//33
				if (m.x >= preparationSeat5_x1 && m.x <= preparationSeat5_x2 && m.y >= preparationSeat5_y1 && m.y <= preparationSeat5_y2)
				{
					if (!PLAYER[0].preparationseatempty[4] && mouseClick != 0)//棋盘为空，把棋子放到这
					{
						PLAYER[0].preparationseatempty[4] = mouseClick;
						PLAYER[0].preparationseat[4] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					if (PLAYER[0].preparationseatempty[4] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].preparationseatempty[4];
						hero = PLAYER[0].preparationseat[4];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[4] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].preparationseat[4] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].preparationseat[4] = PLAYER[0].ground[row][column];
							PLAYER[0].preparationseatempty[4] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					if (PLAYER[0].preparationseatempty[4] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].preparationseatempty[4];
						mouseMessage = PLAYER[0].preparationseat[4];
						mousePostion = 33;
					}
				}
				//34
				if (m.x >= preparationSeat6_x1 && m.x <= preparationSeat6_x2 && m.y >= preparationSeat6_y1 && m.y <= preparationSeat6_y2)
				{
					if (!PLAYER[0].preparationseatempty[5] && mouseClick != 0)//棋盘为空，把棋子放到这
					{
						PLAYER[0].preparationseatempty[5] = mouseClick;
						PLAYER[0].preparationseat[5] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					if (PLAYER[0].preparationseatempty[5] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].preparationseatempty[5];
						hero = PLAYER[0].preparationseat[5];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[5] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].preparationseat[5] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].preparationseat[5] = PLAYER[0].ground[row][column];
							PLAYER[0].preparationseatempty[5] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					if (PLAYER[0].preparationseatempty[5] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].preparationseatempty[5];
						mouseMessage = PLAYER[0].preparationseat[5];
						mousePostion = 34;
					}
				}
				//35
				if (m.x >= preparationSeat7_x1 && m.x <= preparationSeat7_x2 && m.y >= preparationSeat7_y1 && m.y <= preparationSeat7_y2)
				{
					if (!PLAYER[0].preparationseatempty[6] && mouseClick != 0)//棋盘为空，把棋子放到这
					{
						PLAYER[0].preparationseatempty[6] = mouseClick;
						PLAYER[0].preparationseat[6] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					if (PLAYER[0].preparationseatempty[6] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].preparationseatempty[6];
						hero = PLAYER[0].preparationseat[6];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[6] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].preparationseat[6] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].preparationseat[6] = PLAYER[0].ground[row][column];
							PLAYER[0].preparationseatempty[6] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					if (PLAYER[0].preparationseatempty[6] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].preparationseatempty[6];
						mouseMessage = PLAYER[0].preparationseat[6];
						mousePostion = 35;
					}
				}
				//36
				if (m.x >= preparationSeat8_x1 && m.x <= preparationSeat8_x2 && m.y >= preparationSeat8_y1 && m.y <= preparationSeat8_y2)
				{
					if (!PLAYER[0].preparationseatempty[7] && mouseClick != 0)//棋盘为空，把棋子放到这
					{
						PLAYER[0].preparationseatempty[7] = mouseClick;
						PLAYER[0].preparationseat[7] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					if (PLAYER[0].preparationseatempty[7] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].preparationseatempty[7];
						hero = PLAYER[0].preparationseat[7];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[7] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].preparationseat[7] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].preparationseat[7] = PLAYER[0].ground[row][column];
							PLAYER[0].preparationseatempty[7] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					if (PLAYER[0].preparationseatempty[7] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].preparationseatempty[7];
						mouseMessage = PLAYER[0].preparationseat[7];
						mousePostion = 36;
					}
				}
				//37
				if (m.x >= preparationSeat9_x1 && m.x <= preparationSeat9_x2 && m.y >= preparationSeat9_y1 && m.y <= preparationSeat9_y2)
				{
					if (!PLAYER[0].preparationseatempty[8] && mouseClick != 0)//棋盘为空，把棋子放到这
					{
						PLAYER[0].preparationseatempty[8] = mouseClick;
						PLAYER[0].preparationseat[8] = mouseMessage;
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[i - 1] = 0;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].groundempty[row][column] = 0;
						}
						mouseClick = 0;
					}
					if (PLAYER[0].preparationseatempty[8] && mouseClick != 0)//棋盘不为空，把棋子双方棋子交换
					{
						mouseClick = 0;
						int level;
						int hero;
						level = PLAYER[0].preparationseatempty[8];
						hero = PLAYER[0].preparationseat[8];
						if (mousePostion - 28 > 0)
						{
							int i = mousePostion - 28;
							PLAYER[0].preparationseatempty[8] = PLAYER[0].preparationseatempty[i - 1];
							PLAYER[0].preparationseat[8] = PLAYER[0].preparationseat[i - 1];
							PLAYER[0].preparationseatempty[i - 1] = level;
							PLAYER[0].preparationseat[i - 1] = hero;
						}
						if (mousePostion - 28 <= 0)
						{
							int row = mousePostion / 7;
							if (mousePostion == 7) row = 0;
							if (mousePostion == 14) row = 1;
							if (mousePostion == 21) row = 2;
							if (mousePostion == 28) row = 3;
							int column = (mousePostion - 1) % 7;
							PLAYER[0].preparationseat[8] = PLAYER[0].ground[row][column];
							PLAYER[0].preparationseatempty[8] = PLAYER[0].groundempty[row][column];
							PLAYER[0].ground[row][column] = hero;
							PLAYER[0].groundempty[row][column] = level;
						}
					}
					if (PLAYER[0].preparationseatempty[8] && mouseClick == 0)//棋盘不为空，选中棋子进行移动
					{
						mouseClick = 1;
						mouseClick = PLAYER[0].preparationseatempty[8];
						mouseMessage = PLAYER[0].preparationseat[8];
						mousePostion = 37;
					}
				}

				// 按下鼠标左键，行动
				if (PLAYER[0].goldinteger > 0 && (PLAYER[0].preparationseatfull != 1 || (levelupCheck(PLAYER[0].shophero[0]) || levelupCheck(PLAYER[0].shophero[1]) || levelupCheck(PLAYER[0].shophero[2]) || levelupCheck(PLAYER[0].shophero[3]) || levelupCheck(PLAYER[0].shophero[4]))))//刷新D
				{
					if (m.x >= shopHero1_x1 && m.x <= shopHero1_x2 && m.y >= shopHero1_y1 && m.y <= shopHero1_y2 && PLAYER[0].shopempty[0] && PLAYER[0].goldinteger - HERO[PLAYER[0].shophero[0]].gold >= 0 && PLAYER[0].shopable[0])
					{
						playSound();//播放花钱的音乐
						PLAYER[0].goldinteger -= HERO[PLAYER[0].shophero[0]].gold;
						if (levelupCheck(PLAYER[0].shophero[0])) levelUp(PLAYER[0].shophero[0]);//检测升星
						else putSeat(PLAYER[0].shophero[0]);
						PLAYER[0].shopempty[0] = 0;
					}
					if (m.x >= shopHero2_x1 && m.x <= shopHero2_x2 && m.y >= shopHero2_y1 && m.y <= shopHero2_y2 && PLAYER[0].shopempty[1] && PLAYER[0].goldinteger - HERO[PLAYER[0].shophero[1]].gold >= 0 && PLAYER[0].shopable[1])
					{
						playSound();//播放花钱的音乐
						PLAYER[0].goldinteger -= HERO[PLAYER[0].shophero[1]].gold;
						if (levelupCheck(PLAYER[0].shophero[1])) levelUp(PLAYER[0].shophero[1]);//检测升星
						else putSeat(PLAYER[0].shophero[1]);
						PLAYER[0].shopempty[1] = 0;
					}
					if (m.x >= shopHero3_x1 && m.x <= shopHero3_x2 && m.y >= shopHero3_y1 && m.y <= shopHero3_y2 && PLAYER[0].shopempty[2] && PLAYER[0].goldinteger - HERO[PLAYER[0].shophero[2]].gold >= 0 && PLAYER[0].shopable[2])
					{
						playSound();//播放花钱的音乐
						PLAYER[0].goldinteger -= HERO[PLAYER[0].shophero[2]].gold;
						if (levelupCheck(PLAYER[0].shophero[2])) levelUp(PLAYER[0].shophero[2]);//检测升星
						else putSeat(PLAYER[0].shophero[2]);
						PLAYER[0].shopempty[2] = 0;
					}
					if (m.x >= shopHero4_x1 && m.x <= shopHero4_x2 && m.y >= shopHero4_y1 && m.y <= shopHero4_y2 && PLAYER[0].shopempty[3] && PLAYER[0].goldinteger - HERO[PLAYER[0].shophero[3]].gold >= 0 && PLAYER[0].shopable[3])
					{
						playSound();//播放花钱的音乐
						PLAYER[0].goldinteger -= HERO[PLAYER[0].shophero[3]].gold;
						if (levelupCheck(PLAYER[0].shophero[3])) levelUp(PLAYER[0].shophero[3]);//检测升星
						else putSeat(PLAYER[0].shophero[3]);
						PLAYER[0].shopempty[3] = 0;
					}
					if (m.x >= shopHero5_x1 && m.x <= shopHero5_x2 && m.y >= shopHero5_y1 && m.y <= shopHero5_y2 && PLAYER[0].shopempty[4] && PLAYER[0].goldinteger - HERO[PLAYER[0].shophero[4]].gold >= 0 && PLAYER[0].shopable[4])
					{
						playSound();//播放花钱的音乐
						PLAYER[0].goldinteger -= HERO[PLAYER[0].shophero[4]].gold;
						if (levelupCheck(PLAYER[0].shophero[4])) levelUp(PLAYER[0].shophero[4]);//检测升星
						else putSeat(PLAYER[0].shophero[4]);
						PLAYER[0].shopempty[4] = 0;
					}
					executebk = 1;
				}
				
				//升级F
				if (PLAYER[0].goldinteger - 4 >= 0 && (gameStatus == 1 || gameStatus == 2))
				{
					if (m.x >= shopUpgrate_x1 && m.x <= shopUpgrate_x2 && m.y >= shopUpgrate_y1 && m.y <= shopUpgrate_y2)
					{
						if (PLAYER[0].goldinteger - 4 >= 0 && PLAYER[0].levelexperience < 9)
						{
							mciSendString(_T("stop fgmusic"), NULL, 0, NULL);   // 先把前面一次的音乐停止
							mciSendString(_T("close fgmusic"), NULL, 0, NULL); // 先把前面一次的音乐关闭
							mciSendString(_T("open .\\music\\升级.mp3 alias fgmusic"), NULL, 0, NULL); // 打开跳动音乐
							mciSendString(_T("play fgmusic"), NULL, 0, NULL); // 仅播放一次
							//PlaySound(_T(".\\music\\升级.mp3"), NULL, SND_FILENAME | SND_ASYNC);
							if (PLAYER[0].levelinteger[7] == 78) PLAYER[0].goldinteger -= 2;
							else PLAYER[0].goldinteger -= 4;
							LevelUp();//提升玩家等级
							executebk = 1;
						}
						
					}
				}
				
				//刷新D
				if (PLAYER[0].goldinteger - 2 >= 0 && (gameStatus == 1 || gameStatus == 2))
				{
					if (m.x >= shopFresh_x1 && m.x <= shopFresh_x2 && m.y >= shopFresh_y1 && m.y <= shopFresh_y2)
					{
						if (PLAYER[0].goldinteger - 2 >= 0)
						{
							if (PLAYER[0].shopempty[0] == 1)HERO[PLAYER[0].shophero[0]].number += 1;
							if (PLAYER[0].shopempty[1] == 1)HERO[PLAYER[0].shophero[1]].number += 1;
							if (PLAYER[0].shopempty[2] == 1)HERO[PLAYER[0].shophero[2]].number += 1;
							if (PLAYER[0].shopempty[3] == 1)HERO[PLAYER[0].shophero[3]].number += 1;
							if (PLAYER[0].shopempty[4] == 1)HERO[PLAYER[0].shophero[4]].number += 1;
							playSound();//播放花钱的音乐
							freshshop++;
							PLAYER[0].goldinteger -= 2;
							//刷新牌
							PLAYER[0].shopempty[0] = 1;
							PLAYER[0].shopempty[1] = 1;
							PLAYER[0].shopempty[2] = 1;
							PLAYER[0].shopempty[3] = 1;
							PLAYER[0].shopempty[4] = 1;
							executebk = 1;
						}
						
					}
				}
				
			}
			break;
		case WM_RBUTTONUP:
			// 按下鼠标右键，行动
			if (PLAYER[0].goldinteger + 100 < 1000) PLAYER[0].goldinteger += 45;
			executebk = 1;
			break;
		case WM_KEYUP:
			char input;
			input = m.ch;
			if (input == 27) // ESC键的ACSII码为27
			{
				exit(0);
			}
			if (input == 32)//空格
			{
				if (window == 1) window = 2;
				else if (window == 2)window = 0;
				else window = 1;
				executebk = 1;
				freshScreen();//初始化或刷新窗口大小
			}
			//D或d,刷新商店
			if ((input == 68 || input == 100) && (gameStatus == 1 || gameStatus == 2))
			{
				if (PLAYER[0].goldinteger - 2 >= 0)
				{
					if (PLAYER[0].shopempty[0] == 1)HERO[PLAYER[0].shophero[0]].number += 1;
					if (PLAYER[0].shopempty[1] == 1)HERO[PLAYER[0].shophero[1]].number += 1;
					if (PLAYER[0].shopempty[2] == 1)HERO[PLAYER[0].shophero[2]].number += 1;
					if (PLAYER[0].shopempty[3] == 1)HERO[PLAYER[0].shophero[3]].number += 1;
					if (PLAYER[0].shopempty[4] == 1)HERO[PLAYER[0].shophero[4]].number += 1;
					playSound();//播放花钱的音乐
					freshshop++;
					PLAYER[0].goldinteger -= 2;
					//刷新牌
					PLAYER[0].shopempty[0] = 1;
					PLAYER[0].shopempty[1] = 1;
					PLAYER[0].shopempty[2] = 1;
					PLAYER[0].shopempty[3] = 1;
					PLAYER[0].shopempty[4] = 1;
					executebk = 1;
				}
			}
			//e或E,卖出
			if ((input == 69 || input == 101) && (gameStatus == 1 || gameStatus == 2))
			{
				MOUSEMSG m2 = GetMouseMsg();		// 定义鼠标消息
				if (m2.x >= preparationSeat1_x1 && m2.x <= preparationSeat1_x2 && m2.y >= preparationSeat1_y1 && m2.y <= preparationSeat1_y2 && PLAYER[0].preparationseatempty[0] != 0)
				{
					if (PLAYER[0].preparationseatfull == 1) PLAYER[0].preparationseatfull = 0;
					sellSound();//卖棋子
					int price = HERO[PLAYER[0].preparationseat[0]].gold;
					if (PLAYER[0].preparationseatempty[0] == 2) price = HERO[PLAYER[0].preparationseat[0]].gold * 3;
					if (PLAYER[0].preparationseatempty[0] == 3) price = HERO[PLAYER[0].preparationseat[0]].gold * 9;
					PLAYER[0].goldinteger += price;
					int num = 1;
					if (PLAYER[0].preparationseatempty[0] == 2) num = 3;
					if (PLAYER[0].preparationseatempty[0] == 3) num = 9;
					HERO[PLAYER[0].preparationseat[0]].number += num;
					PLAYER[0].preparationseatempty[0] = 0;
				}
				if (m2.x >= preparationSeat2_x1 && m2.x <= preparationSeat2_x2 && m2.y >= preparationSeat2_y1 && m.y <= preparationSeat2_y2 && PLAYER[0].preparationseatempty[1] != 0)
				{
					if (PLAYER[0].preparationseatfull == 1) PLAYER[0].preparationseatfull = 0;
					sellSound();//卖棋子
					int price = HERO[PLAYER[0].preparationseat[1]].gold;
					if (PLAYER[0].preparationseatempty[1] == 2) price = HERO[PLAYER[0].preparationseat[1]].gold * 3;
					if (PLAYER[0].preparationseatempty[1] == 3) price = HERO[PLAYER[0].preparationseat[1]].gold * 9;
					PLAYER[0].goldinteger += price;
					int num = 1;
					if (PLAYER[0].preparationseatempty[1] == 2) num = 3;
					if (PLAYER[0].preparationseatempty[1] == 3) num = 9;
					HERO[PLAYER[0].preparationseat[1]].number += num;
					PLAYER[0].preparationseatempty[1] = 0;
				}
				if (m2.x >= preparationSeat3_x1 && m2.x <= preparationSeat3_x2 && m2.y >= preparationSeat3_y1 && m.y <= preparationSeat3_y2 && PLAYER[0].preparationseatempty[2] != 0)
				{
					if (PLAYER[0].preparationseatfull == 1) PLAYER[0].preparationseatfull = 0;
					sellSound();//卖棋子
					int price = HERO[PLAYER[0].preparationseat[2]].gold;
					if (PLAYER[0].preparationseatempty[2] == 2) price = HERO[PLAYER[0].preparationseat[2]].gold * 3;
					if (PLAYER[0].preparationseatempty[2] == 3) price = HERO[PLAYER[0].preparationseat[2]].gold * 9;
					PLAYER[0].goldinteger += price;
					int num = 1;
					if (PLAYER[0].preparationseatempty[2] == 2) num = 3;
					if (PLAYER[0].preparationseatempty[2] == 3) num = 9;
					HERO[PLAYER[0].preparationseat[2]].number += num;
					PLAYER[0].preparationseatempty[2] = 0;
				}
				if (m2.x >= preparationSeat4_x1 && m2.x <= preparationSeat4_x2 && m2.y >= preparationSeat4_y1 && m.y <= preparationSeat4_y2 && PLAYER[0].preparationseatempty[3] != 0)
				{
					if (PLAYER[0].preparationseatfull == 1) PLAYER[0].preparationseatfull = 0;
					sellSound();//卖棋子
					int price = HERO[PLAYER[0].preparationseat[3]].gold;
					if (PLAYER[0].preparationseatempty[8] == 2) price = HERO[PLAYER[0].preparationseat[3]].gold * 3;
					if (PLAYER[0].preparationseatempty[8] == 3) price = HERO[PLAYER[0].preparationseat[3]].gold * 9;
					PLAYER[0].goldinteger += price;
					int num = 1;
					if (PLAYER[0].preparationseatempty[3] == 2) num = 3;
					if (PLAYER[0].preparationseatempty[3] == 3) num = 9;
					HERO[PLAYER[0].preparationseat[3]].number += num;
					PLAYER[0].preparationseatempty[3] = 0;
				}
				if (m2.x >= preparationSeat5_x1 && m2.x <= preparationSeat5_x2 && m2.y >= preparationSeat5_y1 && m.y <= preparationSeat5_y2 && PLAYER[0].preparationseatempty[4] != 0)
				{
					if (PLAYER[0].preparationseatfull == 1) PLAYER[0].preparationseatfull = 0;
					sellSound();//卖棋子
					int price = HERO[PLAYER[0].preparationseat[4]].gold;
					if (PLAYER[0].preparationseatempty[8] == 2) price = HERO[PLAYER[0].preparationseat[4]].gold * 3;
					if (PLAYER[0].preparationseatempty[8] == 3) price = HERO[PLAYER[0].preparationseat[4]].gold * 9;
					PLAYER[0].goldinteger += price;
					int num = 1;
					if (PLAYER[0].preparationseatempty[4] == 2) num = 3;
					if (PLAYER[0].preparationseatempty[4] == 3) num = 9;
					HERO[PLAYER[0].preparationseat[4]].number += num;
					PLAYER[0].preparationseatempty[4] = 0;
				}
				if (m2.x >= preparationSeat6_x1 && m2.x <= preparationSeat6_x2 && m2.y >= preparationSeat6_y1 && m.y <= preparationSeat6_y2 && PLAYER[0].preparationseatempty[5] != 0)
				{
					if (PLAYER[0].preparationseatfull == 1) PLAYER[0].preparationseatfull = 0;
					sellSound();//卖棋子
					int price = HERO[PLAYER[0].preparationseat[5]].gold;
					if (PLAYER[0].preparationseatempty[8] == 2) price = HERO[PLAYER[0].preparationseat[5]].gold * 3;
					if (PLAYER[0].preparationseatempty[8] == 3) price = HERO[PLAYER[0].preparationseat[5]].gold * 9;
					PLAYER[0].goldinteger += price;
					int num = 1;
					if (PLAYER[0].preparationseatempty[5] == 2) num = 3;
					if (PLAYER[0].preparationseatempty[5] == 3) num = 9;
					HERO[PLAYER[0].preparationseat[5]].number += num;
					PLAYER[0].preparationseatempty[5] = 0;
				}
				if (m2.x >= preparationSeat7_x1 && m2.x <= preparationSeat7_x2 && m2.y >= preparationSeat7_y1 && m.y <= preparationSeat7_y2 && PLAYER[0].preparationseatempty[6] != 0)
				{
					if (PLAYER[0].preparationseatfull == 1) PLAYER[0].preparationseatfull = 0;
					sellSound();//卖棋子
					int price = HERO[PLAYER[0].preparationseat[6]].gold;
					if (PLAYER[0].preparationseatempty[8] == 2) price = HERO[PLAYER[0].preparationseat[6]].gold * 3;
					if (PLAYER[0].preparationseatempty[8] == 3) price = HERO[PLAYER[0].preparationseat[6]].gold * 9;
					PLAYER[0].goldinteger += price;					int num = 1;
					if (PLAYER[0].preparationseatempty[6] == 2) num = 3;
					if (PLAYER[0].preparationseatempty[6] == 3) num = 9;
					HERO[PLAYER[0].preparationseat[6]].number += num;
					PLAYER[0].preparationseatempty[6] = 0;
				}
				if (m2.x >= preparationSeat8_x1 && m2.x <= preparationSeat8_x2 && m2.y >= preparationSeat8_y1 && m.y <= preparationSeat8_y2 && PLAYER[0].preparationseatempty[7] != 0)
				{
					if (PLAYER[0].preparationseatfull == 1) PLAYER[0].preparationseatfull = 0;
					sellSound();//卖棋子
					int price = HERO[PLAYER[0].preparationseat[7]].gold;
					if (PLAYER[0].preparationseatempty[8] == 2) price = HERO[PLAYER[0].preparationseat[7]].gold * 3;
					if (PLAYER[0].preparationseatempty[8] == 3) price = HERO[PLAYER[0].preparationseat[7]].gold * 9;
					PLAYER[0].goldinteger += price;
					int num = 1;
					if (PLAYER[0].preparationseatempty[7] == 2) num = 3;
					if (PLAYER[0].preparationseatempty[7] == 3) num = 9;
					HERO[PLAYER[0].preparationseat[7]].number += num;
					PLAYER[0].preparationseatempty[7] = 0;
				}
				if (m2.x >= preparationSeat9_x1 && m2.x <= preparationSeat9_x2 && m2.y >= preparationSeat9_y1 && m.y <= preparationSeat9_y2 && PLAYER[0].preparationseatempty[8] != 0)
				{
					if (PLAYER[0].preparationseatfull == 1) PLAYER[0].preparationseatfull = 0;
					sellSound();//卖棋子
					int price = HERO[PLAYER[0].preparationseat[8]].gold;
					if (PLAYER[0].preparationseatempty[8] == 2) price = HERO[PLAYER[0].preparationseat[8]].gold * 3;
					if (PLAYER[0].preparationseatempty[8] == 3) price = HERO[PLAYER[0].preparationseat[8]].gold * 9;
					PLAYER[0].goldinteger += price;
					int num = 1;
					if (PLAYER[0].preparationseatempty[8] == 2) num = 3;
					if (PLAYER[0].preparationseatempty[8] == 3) num = 9;
					HERO[PLAYER[0].preparationseat[8]].number += num;
					PLAYER[0].preparationseatempty[8] = 0;
				}
				//卖出场上的棋子
				for (int i = 0, k = 0; i < 4; i++)
				{
					for (int j = 0; j < 7; j++)
					{
						if (m.x >= ground[k][0] && m.x <= ground[k][2] && m.y >= ground[k][1] && m.y <= ground[k][3] && PLAYER[0].groundempty[i][j] != 0)
						{
							sellSound();//卖棋子音效
							int price = HERO[PLAYER[0].ground[i][j]].gold;
							if (PLAYER[0].groundempty[i][j] == 2) price = HERO[PLAYER[0].ground[i][j]].gold * 3;
							if (PLAYER[0].groundempty[i][j] == 3) price = HERO[PLAYER[0].ground[i][j]].gold * 9;
							PLAYER[0].goldinteger += price;
							int num = 1;
							if (PLAYER[0].groundempty[i][j] == 2) num = 3;
							if (PLAYER[0].groundempty[i][j] == 3) num = 9;
							HERO[PLAYER[0].ground[i][j]].number += num;
							PLAYER[0].groundempty[i][j] = 0;
						}
						k++;
					}
				}
				executebk = 1;
			}
			//f或F,升级
			if ((input == 70 || input == 102) && (gameStatus == 1 || gameStatus == 2))
			{
				if (PLAYER[0].goldinteger - 4 >= 0 && PLAYER[0].levelexperience < 9)
				{
					mciSendString(_T("stop fgmusic"), NULL, 0, NULL);   // 先把前面一次的音乐停止
					mciSendString(_T("close fgmusic"), NULL, 0, NULL); // 先把前面一次的音乐关闭
					mciSendString(_T("open .\\music\\升级.mp3 alias fgmusic"), NULL, 0, NULL); // 打开跳动音乐
					mciSendString(_T("play fgmusic"), NULL, 0, NULL); // 仅播放一次
					PlaySound(_T(".\\music\\升级.mp3"), NULL, SND_FILENAME | SND_ASYNC);
					if (PLAYER[0].levelinteger[7] == 78) PLAYER[0].goldinteger -= 2;
					else PLAYER[0].goldinteger -= 4;
					LevelUp();//提升玩家等级
					executebk = 1;
				}
				
			}
			if (input == '0')//开始菜单
			{
				gameStatus = 0;
			}
			if (input == '1')//单人游戏
			{
				gameStatus = 1;
				executebk = 1;
			}
			if (input == '2')//自由游戏
			{
				gameStatus = 2;
				executebk = 1;
			}
			if (input == '3')//藏品
			{
				gameStatus = 3;
				executebk = 1;
			}
			if (input == '4')//设置

			{
				gameStatus = 4;
				executebk = 1;
			}
			if (input == '5')//退出游戏
			{
				gameStatus = 5;
			}
			break;
		default:
			cout << endl;
			break;
	}
}

void displayPopulation()//展示人口
{
	TCHAR population[6];
	int num = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 7; j++)
			if (PLAYER[0].groundempty[i][j] != 0) num++;
	population[0] = 38;
	population[1] = ' ';
	population[2] = num + '0';
	population[3] = '/';
	population[4] = PLAYER[0].levelexperience + '0';
	population[5] = NULL;
	settextstyle(100, 0, _T("Arial"), 0, 0, 600, FALSE, FALSE, FALSE);
	setbkmode(TRANSPARENT);
	settextcolor(RGB(77, 226, 255));
	outtextxy((int)(Width * 0.38), (int)(High * 0.24), population);
}

void displayNumber()//展示概率数字
{
	TCHAR two[5][5];
	TCHAR three[5][5];
	TCHAR four[5][5];
	TCHAR five[5][5];
	TCHAR six[5][5];
	TCHAR seven[5][5];
	TCHAR eight[5][5];
	TCHAR nine[5][5];
	if (PLAYER[0].levelexperience == 2)
	{
		two[0][0] = '1';
		two[0][1] = '0';
		two[0][2] = '0';
		two[0][3] = '%';
		two[0][4] = NULL;
		two[1][0] = '0';
		two[1][1] = '%';
		two[1][2] = NULL;
		two[1][3] = NULL;
		two[1][4] = NULL;
		two[2][0] = '0';
		two[2][1] = '%';
		two[2][2] = NULL;
		two[2][3] = NULL;
		two[2][4] = NULL;
		two[3][0] = '0';
		two[3][1] = '%';
		two[3][2] = NULL;
		two[3][3] = NULL;
		two[3][4] = NULL;
		two[4][0] = '0';
		two[4][1] = '%';
		two[4][2] = NULL;
		two[4][3] = NULL;
		two[4][4] = NULL;
	}
	if (PLAYER[0].levelexperience == 3)
	{
		three[0][0] = '7';
		three[0][1] = '0';
		three[0][2] = '%';
		three[0][3] = NULL;
		three[0][4] = NULL;
		three[1][0] = '3';
		three[1][1] = '0';
		three[1][2] = '%';
		three[1][3] = NULL;
		three[1][4] = NULL;
		three[2][0] = '0';
		three[2][1] = '%';
		three[2][2] = NULL;
		three[2][3] = NULL;
		three[2][4] = NULL;
		three[3][0] = '0';
		three[3][1] = '%';
		three[3][2] = NULL;
		three[3][3] = NULL;
		three[3][4] = NULL;
		three[4][0] = '0';
		three[4][1] = '%';
		three[4][2] = NULL;
		three[4][3] = NULL;
		three[4][4] = NULL;
	}
	if (PLAYER[0].levelexperience == 4)
	{
		four[0][0] = '5';
		four[0][1] = '0';
		four[0][2] = '%';
		four[0][3] = NULL;
		four[0][4] = NULL;
		four[1][0] = '3';
		four[1][1] = '5';
		four[1][2] = '%';
		four[1][3] = NULL;
		four[1][4] = NULL;
		four[2][0] = '1';
		four[2][1] = '5';
		four[2][2] = '%';
		four[2][3] = NULL;
		four[2][4] = NULL;
		four[3][0] = '0';
		four[3][1] = '%';
		four[3][2] = NULL;
		four[3][3] = NULL;
		four[3][4] = NULL;
		four[4][0] = '0';
		four[4][1] = '%';
		four[4][2] = NULL;
		four[4][3] = NULL;
		four[4][4] = NULL;
	}
	if (PLAYER[0].levelexperience == 5)
	{
		five[0][0] = '3';
		five[0][1] = '5';
		five[0][2] = '%';
		five[0][3] = NULL;
		five[0][4] = NULL;
		five[1][0] = '4';
		five[1][1] = '0';
		five[1][2] = '%';
		five[1][3] = NULL;
		five[1][4] = NULL;
		five[2][0] = '2';
		five[2][1] = '0';
		five[2][2] = '%';
		five[2][3] = NULL;
		five[2][4] = NULL;
		five[3][0] = '5';
		five[3][1] = '%';
		five[3][2] = NULL;
		five[3][3] = NULL;
		five[3][4] = NULL;
		five[4][0] = '0';
		five[4][1] = '%';
		five[4][2] = NULL;
		five[4][3] = NULL;
		five[4][4] = NULL;
	}
	if (PLAYER[0].levelexperience == 6)
	{
		six[0][0] = '2';
		six[0][1] = '0';
		six[0][2] = '%';
		six[0][3] = NULL;
		six[0][4] = NULL;
		six[1][0] = '3';
		six[1][1] = '5';
		six[1][2] = '%';
		six[1][3] = NULL;
		six[1][4] = NULL;
		six[2][0] = '3';
		six[2][1] = '5';
		six[2][2] = '%';
		six[2][3] = NULL;
		six[2][4] = NULL;
		six[3][0] = '1';
		six[3][1] = '0';
		six[3][2] = '%';
		six[3][3] = NULL;
		six[3][4] = NULL;
		six[4][0] = '0';
		six[4][1] = '%';
		six[4][2] = NULL;
		six[4][3] = NULL;
		six[4][4] = NULL;
	}
	if (PLAYER[0].levelexperience == 7)
	{
		seven[0][0] = '1';
		seven[0][1] = '4';
		seven[0][2] = '%';
		seven[0][3] = NULL;
		seven[0][4] = NULL;
		seven[1][0] = '3';
		seven[1][1] = '0';
		seven[1][2] = '%';
		seven[1][3] = NULL;
		seven[1][4] = NULL;
		seven[2][0] = '4';
		seven[2][1] = '0';
		seven[2][2] = '%';
		seven[2][3] = NULL;
		seven[2][4] = NULL;
		seven[3][0] = '1';
		seven[3][1] = '5';
		seven[3][2] = '%';
		seven[3][3] = NULL;
		seven[3][4] = NULL;
		seven[4][0] = '1';
		seven[4][1] = '%';
		seven[4][2] = NULL;
		seven[4][3] = NULL;
		seven[4][4] = NULL;
	}
	if (PLAYER[0].levelexperience == 8)
	{
		eight[0][0] = '1';
		eight[0][1] = '4';
		eight[0][2] = '%';
		eight[0][3] = NULL;
		eight[0][4] = NULL;
		eight[1][0] = '2';
		eight[1][1] = '0';
		eight[1][2] = '%';
		eight[1][3] = NULL;
		eight[1][4] = NULL;
		eight[2][0] = '3';
		eight[2][1] = '5';
		eight[2][2] = '%';
		eight[2][3] = NULL;
		eight[2][4] = NULL;
		eight[3][0] = '2';
		eight[3][1] = '5';
		eight[3][2] = '%';
		eight[3][3] = NULL;
		eight[3][4] = NULL;
		eight[4][0] = '6';
		eight[4][1] = '%';
		eight[4][2] = NULL;
		eight[4][3] = NULL;
		eight[4][4] = NULL;
	}
	if (PLAYER[0].levelexperience == 9)
	{
		nine[0][0] = '1';
		nine[0][1] = '0';
		nine[0][2] = '%';
		nine[0][3] = NULL;
		nine[0][4] = NULL;
		nine[1][0] = '1';
		nine[1][1] = '5';
		nine[1][2] = '%';
		nine[1][3] = NULL;
		nine[1][4] = NULL;
		nine[2][0] = '3';
		nine[2][1] = '5';
		nine[2][2] = '%';
		nine[2][3] = NULL;
		nine[2][4] = NULL;
		nine[3][0] = '3';
		nine[3][1] = '5';
		nine[3][2] = '%';
		nine[3][3] = NULL;
		nine[3][4] = NULL;
		nine[4][0] = '1';
		nine[4][1] = '5';
		nine[4][2] = '%';
		nine[4][3] = NULL;
		nine[4][4] = NULL;
	}
	//展示
	if (window == 0 || window == 1)
	{
		if (PLAYER[0].levelexperience == 2)
		{
			settextstyle(15, 0, _T("Arial"), 0, 0, 600, FALSE, FALSE, FALSE);
			setbkmode(TRANSPARENT);
			settextcolor(RGB(155, 150, 136));
			outtextxy((int)(width1 * 0.2599), (int)(high1 * 0.82778), two[0]);
			settextcolor(RGB(60, 180, 87));
			outtextxy((int)(width1 * 0.289), (int)(high1 * 0.82778), two[1]);
			settextcolor(RGB(52, 191, 251));
			outtextxy((int)(width1 * 0.31927), (int)(high1 * 0.82778), two[2]);
			settextcolor(RGB(196, 18, 188));
			outtextxy((int)(width1 * 0.34896), (int)(high1 * 0.82778), two[3]);
			settextcolor(RGB(252, 144, 0));
			outtextxy((int)(width1 * 0.37813), (int)(high1 * 0.82778), two[4]);
		}
		if (PLAYER[0].levelexperience == 3)
		{
			settextstyle(15, 0, _T("Arial"), 0, 0, 600, FALSE, FALSE, FALSE);
			setbkmode(TRANSPARENT);
			settextcolor(RGB(155, 150, 136));
			outtextxy((int)(width1 * 0.2599), (int)(high1 * 0.82778), three[0]);
			settextcolor(RGB(60, 180, 87));
			outtextxy((int)(width1 * 0.289), (int)(high1 * 0.82778), three[1]);
			settextcolor(RGB(52, 191, 251));
			outtextxy((int)(width1 * 0.31927), (int)(high1 * 0.82778), three[2]);
			settextcolor(RGB(196, 18, 188));
			outtextxy((int)(width1 * 0.34896), (int)(high1 * 0.82778), three[3]);
			settextcolor(RGB(252, 144, 0));
			outtextxy((int)(width1 * 0.37813), (int)(high1 * 0.82778), three[4]);
		}
		if (PLAYER[0].levelexperience == 4)
		{
			settextstyle(15, 0, _T("Arial"), 0, 0, 600, FALSE, FALSE, FALSE);
			setbkmode(TRANSPARENT);
			settextcolor(RGB(155, 150, 136));
			outtextxy((int)(width1 * 0.2599), (int)(high1 * 0.82778), four[0]);
			settextcolor(RGB(60, 180, 87));
			outtextxy((int)(width1 * 0.289), (int)(high1 * 0.82778), four[1]);
			settextcolor(RGB(52, 191, 251));
			outtextxy((int)(width1 * 0.31927), (int)(high1 * 0.82778), four[2]);
			settextcolor(RGB(196, 18, 188));
			outtextxy((int)(width1 * 0.34896), (int)(high1 * 0.82778), four[3]);
			settextcolor(RGB(252, 144, 0));
			outtextxy((int)(width1 * 0.37813), (int)(high1 * 0.82778), four[4]);
		}
		if (PLAYER[0].levelexperience == 5)
		{
			settextstyle(15, 0, _T("Arial"), 0, 0, 600, FALSE, FALSE, FALSE);
			setbkmode(TRANSPARENT);
			settextcolor(RGB(155, 150, 136));
			outtextxy((int)(width1 * 0.2599), (int)(high1 * 0.82778), five[0]);
			settextcolor(RGB(60, 180, 87));
			outtextxy((int)(width1 * 0.289), (int)(high1 * 0.82778), five[1]);
			settextcolor(RGB(52, 191, 251));
			outtextxy((int)(width1 * 0.31927), (int)(high1 * 0.82778), five[2]);
			settextcolor(RGB(196, 18, 188));
			outtextxy((int)(width1 * 0.34896), (int)(high1 * 0.82778), five[3]);
			settextcolor(RGB(252, 144, 0));
			outtextxy((int)(width1 * 0.37813), (int)(high1 * 0.82778), five[4]);
		}
		if (PLAYER[0].levelexperience == 6)
		{
			settextstyle(15, 0, _T("Arial"), 0, 0, 600, FALSE, FALSE, FALSE);
			setbkmode(TRANSPARENT);
			settextcolor(RGB(155, 150, 136));
			outtextxy((int)(width1 * 0.2599), (int)(high1 * 0.82778), six[0]);
			settextcolor(RGB(60, 180, 87));
			outtextxy((int)(width1 * 0.289), (int)(high1 * 0.82778), six[1]);
			settextcolor(RGB(52, 191, 251));
			outtextxy((int)(width1 * 0.31927), (int)(high1 * 0.82778), six[2]);
			settextcolor(RGB(196, 18, 188));
			outtextxy((int)(width1 * 0.34896), (int)(high1 * 0.82778), six[3]);
			settextcolor(RGB(252, 144, 0));
			outtextxy((int)(width1 * 0.37813), (int)(high1 * 0.82778), six[4]);
		}
		if (PLAYER[0].levelexperience == 7)
		{
			settextstyle(15, 0, _T("Arial"), 0, 0, 600, FALSE, FALSE, FALSE);
			setbkmode(TRANSPARENT);
			settextcolor(RGB(155, 150, 136));
			outtextxy((int)(width1 * 0.2599), (int)(high1 * 0.82778), seven[0]);
			settextcolor(RGB(60, 180, 87));
			outtextxy((int)(width1 * 0.289), (int)(high1 * 0.82778), seven[1]);
			settextcolor(RGB(52, 191, 251));
			outtextxy((int)(width1 * 0.31927), (int)(high1 * 0.82778), seven[2]);
			settextcolor(RGB(196, 18, 188));
			outtextxy((int)(width1 * 0.34896), (int)(high1 * 0.82778), seven[3]);
			settextcolor(RGB(252, 144, 0));
			outtextxy((int)(width1 * 0.37813), (int)(high1 * 0.82778), seven[4]);
		}
		if (PLAYER[0].levelexperience == 8)
		{
			settextstyle(15, 0, _T("Arial"), 0, 0, 600, FALSE, FALSE, FALSE);
			setbkmode(TRANSPARENT);
			settextcolor(RGB(155, 150, 136));
			outtextxy((int)(width1 * 0.2599), (int)(high1 * 0.82778), eight[0]);
			settextcolor(RGB(60, 180, 87));
			outtextxy((int)(width1 * 0.289), (int)(high1 * 0.82778), eight[1]);
			settextcolor(RGB(52, 191, 251));
			outtextxy((int)(width1 * 0.31927), (int)(high1 * 0.82778), eight[2]);
			settextcolor(RGB(196, 18, 188));
			outtextxy((int)(width1 * 0.34896), (int)(high1 * 0.82778), eight[3]);
			settextcolor(RGB(252, 144, 0));
			outtextxy((int)(width1 * 0.37813), (int)(high1 * 0.82778), eight[4]);
		}
		if (PLAYER[0].levelexperience == 9)
		{
			settextstyle(15, 0, _T("Arial"), 0, 0, 600, FALSE, FALSE, FALSE);
			setbkmode(TRANSPARENT);
			settextcolor(RGB(155, 150, 136));
			outtextxy((int)(width1 * 0.2599), (int)(high1 * 0.82778), nine[0]);
			settextcolor(RGB(60, 180, 87));
			outtextxy((int)(width1 * 0.289), (int)(high1 * 0.82778), nine[1]);
			settextcolor(RGB(52, 191, 251));
			outtextxy((int)(width1 * 0.31927), (int)(high1 * 0.82778), nine[2]);
			settextcolor(RGB(196, 18, 188));
			outtextxy((int)(width1 * 0.34896), (int)(high1 * 0.82778), nine[3]);
			settextcolor(RGB(252, 144, 0));
			outtextxy((int)(width1 * 0.37813), (int)(high1 * 0.82778), nine[4]);
		}
	}
	if (window == 2)
	{
		if (PLAYER[0].levelexperience == 2)
		{
			settextstyle(10, 0, _T("Arial"), 0, 0, 500, FALSE, FALSE, FALSE);
			setbkmode(TRANSPARENT);
			settextcolor(RGB(155, 150, 136));
			outtextxy((int)(width2 * 0.2599), (int)(high2 * 0.82778), two[0]);
			settextcolor(RGB(60, 180, 87));
			outtextxy((int)(width2 * 0.289), (int)(high2 * 0.82778), two[1]);
			settextcolor(RGB(52, 191, 251));
			outtextxy((int)(width2 * 0.31927), (int)(high2 * 0.82778), two[2]);
			settextcolor(RGB(196, 18, 188));
			outtextxy((int)(width2 * 0.34896), (int)(high2 * 0.82778), two[3]);
			settextcolor(RGB(252, 144, 0));
			outtextxy((int)(width2 * 0.37813), (int)(high2 * 0.82778), two[4]);
		}
		if (PLAYER[0].levelexperience == 3)
		{
			settextstyle(10, 0, _T("Arial"), 0, 0, 500, FALSE, FALSE, FALSE);
			setbkmode(TRANSPARENT);
			settextcolor(RGB(155, 150, 136));
			outtextxy((int)(width2 * 0.2599), (int)(high2 * 0.82778), three[0]);
			settextcolor(RGB(60, 180, 87));
			outtextxy((int)(width2 * 0.289), (int)(high2 * 0.82778), three[1]);
			settextcolor(RGB(52, 191, 251));
			outtextxy((int)(width2 * 0.31927), (int)(high2 * 0.82778), three[2]);
			settextcolor(RGB(196, 18, 188));
			outtextxy((int)(width2 * 0.34896), (int)(high2 * 0.82778), three[3]);
			settextcolor(RGB(252, 144, 0));
			outtextxy((int)(width2 * 0.37813), (int)(high2 * 0.82778), three[4]);
		}
		if (PLAYER[0].levelexperience == 4)
		{
			settextstyle(10, 0, _T("Arial"), 0, 0, 500, FALSE, FALSE, FALSE);
			setbkmode(TRANSPARENT);
			settextcolor(RGB(155, 150, 136));
			outtextxy((int)(width2 * 0.2599), (int)(high2 * 0.82778), four[0]);
			settextcolor(RGB(60, 180, 87));
			outtextxy((int)(width2 * 0.289), (int)(high2 * 0.82778), four[1]);
			settextcolor(RGB(52, 191, 251));
			outtextxy((int)(width2 * 0.31927), (int)(high2 * 0.82778), four[2]);
			settextcolor(RGB(196, 18, 188));
			outtextxy((int)(width2 * 0.34896), (int)(high2 * 0.82778), four[3]);
			settextcolor(RGB(252, 144, 0));
			outtextxy((int)(width2 * 0.37813), (int)(high2 * 0.82778), four[4]);
		}
		if (PLAYER[0].levelexperience == 5)
		{
			settextstyle(10, 0, _T("Arial"), 0, 0, 500, FALSE, FALSE, FALSE);
			setbkmode(TRANSPARENT);
			settextcolor(RGB(155, 150, 136));
			outtextxy((int)(width2 * 0.2599), (int)(high2 * 0.82778), five[0]);
			settextcolor(RGB(60, 180, 87));
			outtextxy((int)(width2 * 0.289), (int)(high2 * 0.82778), five[1]);
			settextcolor(RGB(52, 191, 251));
			outtextxy((int)(width2 * 0.31927), (int)(high2 * 0.82778), five[2]);
			settextcolor(RGB(196, 18, 188));
			outtextxy((int)(width2 * 0.34896), (int)(high2 * 0.82778), five[3]);
			settextcolor(RGB(252, 144, 0));
			outtextxy((int)(width2 * 0.37813), (int)(high2 * 0.82778), five[4]);
		}
		if (PLAYER[0].levelexperience == 6)
		{
			settextstyle(10, 0, _T("Arial"), 0, 0, 500, FALSE, FALSE, FALSE);
			setbkmode(TRANSPARENT);
			settextcolor(RGB(155, 150, 136));
			outtextxy((int)(width2 * 0.2599), (int)(high2 * 0.82778), six[0]);
			settextcolor(RGB(60, 180, 87));
			outtextxy((int)(width2 * 0.289), (int)(high2 * 0.82778), six[1]);
			settextcolor(RGB(52, 191, 251));
			outtextxy((int)(width2 * 0.31927), (int)(high2 * 0.82778), six[2]);
			settextcolor(RGB(196, 18, 188));
			outtextxy((int)(width2 * 0.34896), (int)(high2 * 0.82778), six[3]);
			settextcolor(RGB(252, 144, 0));
			outtextxy((int)(width2 * 0.37813), (int)(high2 * 0.82778), six[4]);
		}
		if (PLAYER[0].levelexperience == 7)
		{
			settextstyle(10, 0, _T("Arial"), 0, 0, 500, FALSE, FALSE, FALSE);
			setbkmode(TRANSPARENT);
			settextcolor(RGB(155, 150, 136));
			outtextxy((int)(width2 * 0.2599), (int)(high2 * 0.82778), seven[0]);
			settextcolor(RGB(60, 180, 87));
			outtextxy((int)(width2 * 0.289), (int)(high2 * 0.82778), seven[1]);
			settextcolor(RGB(52, 191, 251));
			outtextxy((int)(width2 * 0.31927), (int)(high2 * 0.82778), seven[2]);
			settextcolor(RGB(196, 18, 188));
			outtextxy((int)(width2 * 0.34896), (int)(high2 * 0.82778), seven[3]);
			settextcolor(RGB(252, 144, 0));
			outtextxy((int)(width2 * 0.37813), (int)(high2 * 0.82778), seven[4]);
		}
		if (PLAYER[0].levelexperience == 8)
		{
			settextstyle(10, 0, _T("Arial"), 0, 0, 500, FALSE, FALSE, FALSE);
			setbkmode(TRANSPARENT);
			settextcolor(RGB(155, 150, 136));
			outtextxy((int)(width2 * 0.2599), (int)(high2 * 0.82778), eight[0]);
			settextcolor(RGB(60, 180, 87));
			outtextxy((int)(width2 * 0.289), (int)(high2 * 0.82778), eight[1]);
			settextcolor(RGB(52, 191, 251));
			outtextxy((int)(width2 * 0.31927), (int)(high2 * 0.82778), eight[2]);
			settextcolor(RGB(196, 18, 188));
			outtextxy((int)(width2 * 0.34896), (int)(high2 * 0.82778), eight[3]);
			settextcolor(RGB(252, 144, 0));
			outtextxy((int)(width2 * 0.37813), (int)(high2 * 0.82778), eight[4]);
		}
		if (PLAYER[0].levelexperience == 9)
		{
			settextstyle(10, 0, _T("Arial"), 0, 0, 500, FALSE, FALSE, FALSE);
			setbkmode(TRANSPARENT);
			settextcolor(RGB(155, 150, 136));
			outtextxy((int)(width2 * 0.2599), (int)(high2 * 0.82778), nine[0]);
			settextcolor(RGB(60, 180, 87));
			outtextxy((int)(width2 * 0.289), (int)(high2 * 0.82778), nine[1]);
			settextcolor(RGB(52, 191, 251));
			outtextxy((int)(width2 * 0.31927), (int)(high2 * 0.82778), nine[2]);
			settextcolor(RGB(196, 18, 188));
			outtextxy((int)(width2 * 0.34896), (int)(high2 * 0.82778), nine[3]);
			settextcolor(RGB(252, 144, 0));
			outtextxy((int)(width2 * 0.37813), (int)(high2 * 0.82778), nine[4]);
		}
	}

}

int freshProbability()//根据等级刷新的概率
{
	int number = EDGE0(RAND0);
	if (PLAYER[0].levelexperience == 2)
	{
		if (number < probability[1][0])
		{
			return EDGE1(RAND1);
		}
	}
	if (PLAYER[0].levelexperience == 3)
	{
		if (number < probability[2][0])
		{
			return EDGE1(RAND1);
		}
		else if (number >= probability[2][0])
		{
			return EDGE2(RAND2);
		}
	}
	if (PLAYER[0].levelexperience == 4)
	{
		if (number < probability[3][0])
		{
			return EDGE1(RAND1);
		}
		else if (number < probability[3][0] + probability[3][1])
		{
			return EDGE2(RAND2);
		}
		else
		{
			return EDGE3(RAND3);
		}
	}
	if (PLAYER[0].levelexperience == 5)
	{
		if (number < probability[4][0])
		{
			return EDGE1(RAND1);
		}
		else if (number < probability[4][0] + probability[4][1])
		{
			return EDGE2(RAND2);
		}
		else if (number < probability[4][0] + probability[4][1] + probability[4][2])
		{
			return EDGE3(RAND3);
		}
		else return EDGE4(RAND4);
	}
	if (PLAYER[0].levelexperience == 6)
	{
		if (number < probability[5][0])
		{
			return EDGE1(RAND1);
		}
		else if (number < probability[5][0] + probability[5][1])
		{
			return EDGE2(RAND2);
		}
		else if (number < probability[5][0] + probability[5][1] + probability[5][2])
		{
			return EDGE3(RAND3);
		}
		else return EDGE4(RAND4);
	}
	if (PLAYER[0].levelexperience == 7)
	{
		if (number < probability[6][0])
		{
			return EDGE1(RAND1);
		}
		else if (number < probability[6][0] + probability[6][1])
		{
			return EDGE2(RAND2);
		}
		else if (number < probability[6][0] + probability[6][1] + probability[6][2])
		{
			return EDGE3(RAND3);
		}
		else if (number < probability[6][0] + probability[6][1] + probability[6][2] + probability[6][2])
		{
			return EDGE4(RAND4);
		}
		else return EDGE5(RAND5);
	}
	if (PLAYER[0].levelexperience == 8)
	{
		if (number < probability[7][0])
		{
			return EDGE1(RAND1);
		}
		else if (number < probability[7][0] + probability[7][1])
		{
			return EDGE2(RAND2);
		}
		else if (number < probability[7][0] + probability[7][1] + probability[7][2])
		{
			return EDGE3(RAND3);
		}
		else if (number < probability[7][0] + probability[7][1] + probability[7][2] + probability[7][2])
		{
			return EDGE4(RAND4);
		}
		else return EDGE5(RAND5);
	}
	if (PLAYER[0].levelexperience == 9)
	{
		if (number < probability[8][0])
		{
			return EDGE1(RAND1);
		}
		else if (number < probability[8][0] + probability[8][1])
		{
			return EDGE2(RAND2);
		}
		else if (number < probability[8][0] + probability[8][1] + probability[8][2])
		{
			return EDGE3(RAND3);
		}
		else if (number < probability[8][0] + probability[8][1] + probability[8][2] + probability[8][2])
		{
			return EDGE4(RAND4);
		}
		else return EDGE5(RAND5);
	}

}

void LevelUp()//提升玩家等级
{
	int num = 4;
	if (PLAYER[0].levelexperience == 2)
	{
		while (PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] < 2 && num != 0)
		{
			PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1]++;
			num--;
		}
		if (num > 0) PLAYER[0].levelexperience++;
	}
	if (PLAYER[0].levelexperience == 3)
	{
		while (PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] < 6 && num != 0)
		{
			PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1]++;
			num--;
		}
		if (num > 0) PLAYER[0].levelexperience++;
	}
	if (PLAYER[0].levelexperience == 4)
	{
		while (PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] < 10 && num != 0)
		{
			PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1]++;
			num--;
		}
		if (num > 0) PLAYER[0].levelexperience++;
	}
	if (PLAYER[0].levelexperience == 5)
	{
		while (PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] < 20 && num != 0)
		{
			PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1]++;
			num--;
		}
		if (num > 0) PLAYER[0].levelexperience++;
	}
	if (PLAYER[0].levelexperience == 6)
	{
		while (PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] < 36 && num != 0)
		{
			PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1]++;
			num--;
		}
		if (num > 0) PLAYER[0].levelexperience++;
	}
	if (PLAYER[0].levelexperience == 7)
	{
		while (PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] < 56 && num != 0)
		{
			PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1]++;
			num--;
		}
		if (num > 0) PLAYER[0].levelexperience++;
	}
	if (PLAYER[0].levelexperience == 8)
	{
		while (PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] < 80 && num != 0)
		{
			PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1]++;
			num--;
		}
		if (num > 0) PLAYER[0].levelexperience++;
	}
	if (num == 0 && PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] == 2 && PLAYER[0].levelexperience == 2) PLAYER[0].levelexperience++;
	if (num == 0 && PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] == 6 && PLAYER[0].levelexperience == 3) PLAYER[0].levelexperience++;
	if (num == 0 && PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] == 10 && PLAYER[0].levelexperience == 4) PLAYER[0].levelexperience++;
	if (num == 0 && PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] == 20 && PLAYER[0].levelexperience == 5) PLAYER[0].levelexperience++;
	if (num == 0 && PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] == 36 && PLAYER[0].levelexperience == 6) PLAYER[0].levelexperience++;
	if (num == 0 && PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] == 56 && PLAYER[0].levelexperience == 7) PLAYER[0].levelexperience++;
	if (num == 0 && PLAYER[0].levelinteger[PLAYER[0].levelexperience - 1] == 80 && PLAYER[0].levelexperience == 8) PLAYER[0].levelexperience++;
}

void checkFull()//检测备战席和棋盘上是否满了
{
	PLAYER[0].preparationseatfull = 1;
	for (int i = 0; i < 9; i++)
	{
		if (PLAYER[0].preparationseatempty[i] == 0) PLAYER[0].preparationseatfull = 0;
	}
	int num = 0;//记录场上的棋子
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 7; j++)
			if (PLAYER[0].groundempty[i][j] != 0) num++;
	if (num >= PLAYER[0].levelexperience) PLAYER[0].groundfull = 1;
	else PLAYER[0].groundfull = 0;

	if (PLAYER[0].preparationseatfull == 1)
	{
		PLAYER[0].shopable[0] = 0;
		PLAYER[0].shopable[1] = 0;
		PLAYER[0].shopable[2] = 0;
		PLAYER[0].shopable[3] = 0;
		PLAYER[0].shopable[4] = 0;
	}
	if (PLAYER[0].preparationseatfull == 0)
	{
		PLAYER[0].shopable[0] = 1;
		PLAYER[0].shopable[1] = 1;
		PLAYER[0].shopable[2] = 1;
		PLAYER[0].shopable[3] = 1;
		PLAYER[0].shopable[4] = 1;
	}
	levelupCheck(PLAYER[0].shophero[0]);
	levelupCheck(PLAYER[0].shophero[1]);
	levelupCheck(PLAYER[0].shophero[2]);
	levelupCheck(PLAYER[0].shophero[3]);
	levelupCheck(PLAYER[0].shophero[4]);
}

bool levelupCheck(int hero)//检测是否能购买牌升级二星
{
	int num1 = 0;
	int num2 = 0;
	int k = 0;
	if (k == 0)//检测三星
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (PLAYER[0].ground[i][j] == hero && PLAYER[0].groundempty[i][j] == 2) num2++;
				k++;
			}
		}
		for (int i = 0; i < 9; i++)
		{
			if (PLAYER[0].preparationseat[i] == hero && PLAYER[0].preparationseatempty[i] == 2) num2++;
			k++;
		}
	}
	k = 0;
	if (k == 0)//检测二星
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (PLAYER[0].ground[i][j] == hero && PLAYER[0].groundempty[i][j] == 1) num1++;
				k++;
			}
		}
		for (int i = 0; i < 9; i++)
		{
			if (PLAYER[0].preparationseat[i] == hero && PLAYER[0].preparationseatempty[i] == 1) num1++;
			k++;
		}
	}
	if (num1 == 2 && num2 != 2)
	{
		for (int i = 0; i < 5; i++)
			if (PLAYER[0].shophero[i] == hero && PLAYER[0].preparationseatfull == 1)
				PLAYER[0].shopable[i] = 1;
		return true;
	}
	else if (num1 == 2 && num2 == 2)
	{
		for (int i = 0; i < 5; i++)
			if (PLAYER[0].shophero[i] == hero && PLAYER[0].preparationseatfull == 1)
				PLAYER[0].shopable[i] = 1;
		return true;
	}
	else return false;
}

void levelupShow(int hero)//升星检测图片
{
	int num1 = 0;
	int num2 = 0;
	int k = 0;
	if (k == 0)//检测三星
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (PLAYER[0].ground[i][j] == hero && PLAYER[0].groundempty[i][j] == 2) num2++;
				k++;
			}
		}
		for (int i = 0; i < 9; i++)
		{
			if (PLAYER[0].preparationseat[i] == hero && PLAYER[0].preparationseatempty[i] == 2) num2++;
			k++;
		}
	}
	k = 0;
	if (k == 0)//检测二星
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (PLAYER[0].ground[i][j] == hero && PLAYER[0].groundempty[i][j] == 1) num1++;
				k++;
			}
		}
		for (int i = 0; i < 9; i++)
		{
			if (PLAYER[0].preparationseat[i] == hero && PLAYER[0].preparationseatempty[i] == 1) num1++;
			k++;
		}
	}
	if (num1 == 2 && num2 != 2)
	{
		int i = 0;
		for (; i < 5; i++)
		{
			if (hero == PLAYER[0].shophero[i] && PLAYER[0].shopempty[i] != 0) break;
		}
		if (i == 0 && PLAYER[0].shopempty[0])
		{
			putEffect1(0.251, 0.86, img_twoleveltipBottom1, img_twoleveltipBottom2);
			putEffect2(0.251, 0.86, img_twoleveltipSurface1, img_twoleveltipSurface2);
		}
		if (i == 1 && PLAYER[0].shopempty[1])
		{
			putEffect1(0.355, 0.86, img_twoleveltipBottom1, img_twoleveltipBottom2);
			putEffect2(0.355, 0.86, img_twoleveltipSurface1, img_twoleveltipSurface2);
		}
		if (i == 2 && PLAYER[0].shopempty[2])
		{
			putEffect1(0.46, 0.86, img_twoleveltipBottom1, img_twoleveltipBottom2);
			putEffect2(0.46, 0.86, img_twoleveltipSurface1, img_twoleveltipSurface2);
		}
		if (i == 3 && PLAYER[0].shopempty[3])
		{
			putEffect1(0.565, 0.86, img_twoleveltipBottom1, img_twoleveltipBottom2);
			putEffect2(0.565, 0.86, img_twoleveltipSurface1, img_twoleveltipSurface2);
		}
		if (i == 4 && PLAYER[0].shopempty[4])
		{
			putEffect1(0.67, 0.86, img_twoleveltipBottom1, img_twoleveltipBottom2);
			putEffect2(0.67, 0.86, img_twoleveltipSurface1, img_twoleveltipSurface2);
		}
	}
	else if (num1 == 2 && num2 == 2)
	{
		int i = 0;
		for (; i < 5; i++)
		{
			if (hero == PLAYER[0].shophero[i] && PLAYER[0].shopempty[i] != 0) break;
		}
		if (i == 0 && PLAYER[0].shopempty[0])
		{
			putEffect1(0.251, 0.86, img_threeleveltipBottom1, img_threeleveltipBottom2);
			putEffect2(0.251, 0.86, img_threeleveltipSurface1, img_threeleveltipSurface2);
		}
		if (i == 1 && PLAYER[0].shopempty[1])
		{
			putEffect1(0.355, 0.86, img_threeleveltipBottom1, img_threeleveltipBottom2);
			putEffect2(0.355, 0.86, img_threeleveltipSurface1, img_threeleveltipSurface2);
		}
		if (i == 2 && PLAYER[0].shopempty[2])
		{
			putEffect1(0.46, 0.86, img_threeleveltipBottom1, img_threeleveltipBottom2);
			putEffect2(0.46, 0.86, img_threeleveltipSurface1, img_threeleveltipSurface2);
		}
		if (i == 3 && PLAYER[0].shopempty[3])
		{
			putEffect1(0.565, 0.86, img_threeleveltipBottom1, img_threeleveltipBottom2);
			putEffect2(0.565, 0.86, img_threeleveltipSurface1, img_threeleveltipSurface2);
		}
		if (i == 4 && PLAYER[0].shopempty[4])
		{
			putEffect1(0.67, 0.86, img_threeleveltipBottom1, img_threeleveltipBottom2);
			putEffect2(0.67, 0.86, img_threeleveltipSurface1, img_threeleveltipSurface2);
		}
	}
}

void levelUp(int hero)//检测升星
{
	int num1 = 0;
	int num2 = 0;
	int k = 0;
	if (k == 0)//检测是否存在升星棋子
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (PLAYER[0].ground[i][j] == hero && PLAYER[0].groundempty[i][j] == 1) num1++;
				k++;
			}
		}
		for (int i = 0; i < 9; i++)
		{
			if (PLAYER[0].preparationseat[i] == hero && PLAYER[0].preparationseatempty[i] == 1) num1++;
			k++;
		}
	}
	k = 0;
	if (k == 0)//检测是否存在升星棋子
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (PLAYER[0].ground[i][j] == hero && PLAYER[0].groundempty[i][j] == 2) num2++;
				k++;
			}
		}
		for (int i = 0; i < 9; i++)
		{
			if (PLAYER[0].preparationseat[i] == hero && PLAYER[0].preparationseatempty[i] == 2) num2++;
			k++;
		}
	}
	//两星升级
	int execute1 = 0;
	int execute2 = 0;
	if (num1 == 2 && num2 != 2)
	{
		mciSendString(_T("stop fgmusic"), NULL, 0, NULL);   // 先把前面一次的音乐停止
		mciSendString(_T("close fgmusic"), NULL, 0, NULL); // 先把前面一次的音乐关闭
		mciSendString(_T("open .\\music\\两星.mp3 alias fgmusic"), NULL, 0, NULL); // 打开跳动音乐
		mciSendString(_T("play fgmusic"), NULL, 0, NULL); // 仅播放一次
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (PLAYER[0].ground[i][j] == hero && PLAYER[0].groundempty[i][j] == 1 && !execute1)
				{
					PLAYER[0].groundempty[i][j]++;
					execute1 = 1;
					num1--;
				}
				if (PLAYER[0].ground[i][j] == hero && PLAYER[0].groundempty[i][j] == 1 && num1 > 0 && !execute2)
				{
					PLAYER[0].groundempty[i][j] = 0;
					num1--;
				}
			}
		}
		execute1 = 0;
		execute2 = 0;
		for (int i = 0; i < 9; i++)
		{
			if (num1 < 2)
			{
				if (PLAYER[0].preparationseat[i] == hero && PLAYER[0].preparationseatempty[i] == 1 && num1 > 0)
				{
					PLAYER[0].preparationseatempty[i] = 0;
					num1--;
				}
			}
			if (num1 == 2)
			{
				if (PLAYER[0].preparationseat[i] == hero && PLAYER[0].preparationseatempty[i] == 1 && num1 > 0 && !execute2)
				{
					if (PLAYER[0].preparationseat[i] == hero && PLAYER[0].preparationseatempty[i] == 1 && !execute1)
					{
						PLAYER[0].preparationseatempty[i]++;
						execute1 = 1;
						num1--;
					}
					else
					{
						PLAYER[0].preparationseatempty[i] = 0;
						num1--;
					}
				}
			}
		}
	}
	//三星升级
	execute1 = 0;
	execute2 = 0;
	if (num1 == 2 && num2 == 2)
	{
		mciSendString(_T("stop fgmusic"), NULL, 0, NULL);   // 先把前面一次的音乐停止
		mciSendString(_T("close fgmusic"), NULL, 0, NULL); // 先把前面一次的音乐关闭
		mciSendString(_T("open .\\music\\三星.mp3 alias fgmusic"), NULL, 0, NULL); // 打开跳动音乐
		mciSendString(_T("play fgmusic"), NULL, 0, NULL); // 仅播放一次

		//两个二星的去掉
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (PLAYER[0].ground[i][j] == hero && PLAYER[0].groundempty[i][j] == 2 && !execute1)
				{
					PLAYER[0].groundempty[i][j]++;
					execute1 = 1;
					num2--;
				}
				if (PLAYER[0].ground[i][j] == hero && PLAYER[0].groundempty[i][j] == 2 && num2 > 0 && !execute2)
				{
					PLAYER[0].groundempty[i][j] = 0;
					num2--;
				}
			}
		}
		execute1 = 0;
		execute2 = 0;
		for (int i = 0; i < 9; i++)
		{
			if (num2 < 2)
			{
				if (PLAYER[0].preparationseat[i] == hero && PLAYER[0].preparationseatempty[i] == 2 && num2 > 0)
				{
					PLAYER[0].preparationseatempty[i] = 0;
					num2--;
				}
			}
			if (num2 == 2)
			{
				if (PLAYER[0].preparationseat[i] == hero && PLAYER[0].preparationseatempty[i] == 2 && num2 > 0 && !execute2)
				{
					if (PLAYER[0].preparationseat[i] == hero && PLAYER[0].preparationseatempty[i] == 2 && !execute1)
					{
						PLAYER[0].preparationseatempty[i]++;
						execute1 = 1;
						num2--;
					}
					else
					{
						PLAYER[0].preparationseatempty[i] = 0;
						num2--;
					}
				}
			}
		}
		//两个一星的去掉
		execute1 = 0;
		execute2 = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (PLAYER[0].ground[i][j] == hero && PLAYER[0].groundempty[i][j] == 1 && num1 > 0 && !execute2)
				{
					PLAYER[0].groundempty[i][j] = 0;
					num1--;
				}
			}
		}
		execute1 = 0;
		execute2 = 0;
		for (int i = 0; i < 9; i++)
		{
			if (num1 < 2)
			{
				if (PLAYER[0].preparationseat[i] == hero && PLAYER[0].preparationseatempty[i] == 1 && num1 > 0)
				{
					PLAYER[0].preparationseatempty[i] = 0;
					num1--;
				}
			}
			if (num1 == 2)
			{
				if (PLAYER[0].preparationseat[i] == hero && PLAYER[0].preparationseatempty[i] == 1 && num1 > 0 && !execute2)
				{
					PLAYER[0].preparationseatempty[i] = 0;
					num1--;
				}
			}
		}
	}
}

void sellSound()//卖棋子
{
	mciSendString(_T("stop fgmusic"), NULL, 0, NULL);   // 先把前面一次的音乐停止
	mciSendString(_T("close fgmusic"), NULL, 0, NULL); // 先把前面一次的音乐关闭
	mciSendString(_T("open .\\music\\卖.mp3 alias fgmusic"), NULL, 0, NULL); // 打开跳动音乐
	mciSendString(_T("play fgmusic"), NULL, 0, NULL); // 仅播放一次
}

void putSeat(int piece)//购买棋子进入备战席
{
	int i;
	for (i = 0; i < 9; i++)
	{
		if (PLAYER[0].preparationseatempty[i] == 0)
		{
			PLAYER[0].preparationseat[i] = piece;
			PLAYER[0].preparationseatempty[i] = 1;
			break;
		}
	}
	if (i == 8) PLAYER[0].preparationseatfull = 1;
}

void Exit()//退出游戏 gameStatus == 5
{
	gameover();//游戏结束、后续处理
	exit(0);
}

void gameover()
{
	EndBatchDraw();
	//getch();
	closegraph();
}

int main()
{
	startup();//数据初始化	
	while (1)//游戏循环执行
	{
		show();//显示画面
		updateWithoutInput();//与用户输入无关的更新
		updateWithInput();//与用户输入有关的更新
	}
}