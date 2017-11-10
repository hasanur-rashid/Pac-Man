# include "iGraphics.h"
# include <stdlib.h>
# include <stdarg.h>
# pragma comment(lib, "Winmm.lib")
# include <Windows.h>
# include <MMSystem.h>
# include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

FILE *savedata;
int page = 0, ct = 1;
int flag_gf, flag_gfs, temp_gf = 0, cnt_gf = 0, cnt_gfs = 0, cnt_gf_f = 0, cnt_move_gf = 0, gf_x, gf_y;
int flag_li, cnt_li_f = 0, temp_li, cnt_li = 0, cnt_move_li = 0, li_x, li_y;
int flag_si, cnt_si_f = 0, temp_si, cnt_si = 0, cnt_f_si = 0, cnt_move_si = 0, si_x, si_y;
int a[20][20], score, cnt1 = 0, cnt2, b[20][20], temp, game = 0, highscore, high1 = 0, cnt_l = 3, flag_game ;
int flag = 4, x = 32, y = 32, flag_before, flag2 = 4, flag1 = 0;
int cnt_r = 1, rg_x = 320, rg_y = 288, flag_r = 0, flag_r_before, flag_r2 = 4;
char key;
char scores[10], lifes[10];
int sg_x = 576, sg_y = 576, flag_g=1, flag_s=0, flag_g_before;

int change_si_x(int cnt_move_si){
	if (cnt_move_si % 6 == 1) return 3;
	else if (cnt_move_si % 6 == 2) return 12;
	else if (cnt_move_si % 6 == 3) return 18;
	else if (cnt_move_si % 6 == 4) return 1;
	else if (cnt_move_si % 6 == 5) return 10;
	else if (cnt_move_si % 6 == 0) return 7;
}

int change_si_y(int cnt_move_si){
	if (cnt_move_si % 6 == 1) return 5;
	else if (cnt_move_si % 6 == 2) return 17;
	else if (cnt_move_si % 6 == 3) return 6;
	else if (cnt_move_si % 6 == 4) return 13;
	else if (cnt_move_si % 6 == 5) return 15;
	else if (cnt_move_si % 6 == 0) return 2;
}

int change_gf_x(int cnt_move_gf){
	if (cnt_move_gf % 4 == 1) return 5;
	else if (cnt_move_gf % 4 == 2) return 14;
	else if (cnt_move_gf % 4 == 3) return 9;
	else if (cnt_move_gf % 4 == 0) return 16;
}

int change_gf_y(int cnt_move_gf){
	if (cnt_move_gf % 4 == 1) return 10;
	else if (cnt_move_gf % 4 == 2) return 3;
	else if (cnt_move_gf % 4 == 3) return 14;
	else if (cnt_move_gf % 4 == 0) return 4;
}

int change_li_x(int cnt_move_li){
	if (cnt_move_li % 3 == 1) return 10;
	else if (cnt_move_li % 3 == 2) return 6;
	else if (cnt_move_li % 3 == 0) return 15;
}

int change_li_y(int cnt_move_li){
	if (cnt_move_li % 3 == 1) return 10;
	else if (cnt_move_li % 3 == 2) return 1;
	else if (cnt_move_li % 3 == 0) return 18;
}

void save(){
	int i, j;
	savedata = fopen("PAC_DATA_SAVE.txt", "w");
	
	for (i = 0; i < 20; i++){
		for (j = 0; j < 20; j++){
			fprintf_s(savedata, "%d ", b[i][j]);
		}
	}
	fprintf_s(savedata, "\n");

	fprintf_s(savedata, "%d", page);
	fprintf_s(savedata, "\n");

	fprintf_s(savedata, "%d", game);
	fprintf_s(savedata, "\n");

	fprintf_s(savedata, "%d", x);
	fprintf_s(savedata, "\n");

	fprintf_s(savedata, "%d", y);
	fprintf(savedata, "\n");

	fprintf_s(savedata, "%d", flag);
	fprintf_s(savedata, "\n");

	fprintf_s(savedata, "%d", flag1);
	fprintf_s(savedata, "\n");

	fprintf_s(savedata, "%d", flag2);
	fprintf_s(savedata, "\n");

	fprintf_s(savedata, "%d", ct);
	fprintf_s(savedata, "\n");

	fprintf_s(savedata, "%d", flag_before);
	fprintf_s(savedata, "\n");

	fprintf_s(savedata, "%d", sg_x);
	fprintf_s(savedata, "\n");

	fprintf_s(savedata, "%d", sg_y);
	fprintf_s(savedata, "\n");

	fprintf_s(savedata, "%d", flag_g);
	fprintf_s(savedata, "\n");

	fprintf_s(savedata, "%d", flag_g_before);
	fprintf_s(savedata, "\n");

	fprintf_s(savedata, "%d", rg_x);
	fprintf_s(savedata, "\n");

	fprintf_s(savedata, "%d", rg_y);
	fprintf_s(savedata, "\n");

	fprintf_s(savedata, "%d", flag_r);
	fprintf_s(savedata, "\n");

	fprintf_s(savedata, "%d", flag_r2);
	fprintf_s(savedata, "\n");

	fprintf_s(savedata, "%d", cnt_l);
	fprintf_s(savedata, "\n");

	fprintf_s(savedata, "%d", flag_s);
	fprintf(savedata, "\n");

	fprintf_s(savedata, "%d", score);
	fprintf_s(savedata, "\n");

	fprintf_s(savedata, "%d", highscore);
	fprintf_s(savedata, "\n");

	fprintf_s(savedata, "%d", cnt1);
	fprintf(savedata, "\n");

	fprintf_s(savedata, "%d", cnt2);
	fprintf_s(savedata, "\n");

	fprintf_s(savedata, "%d", high1);
	fprintf_s(savedata, "\n");

	fprintf_s(savedata, "%d", cnt_f_si);
	fprintf_s(savedata, "\n");

	fprintf_s(savedata, "%d", cnt_r);
	fprintf_s(savedata, "\n");

	fclose(savedata);
}

void load(){
	int i, j;
	savedata = fopen("PAC_DATA_SAVE.txt", "r");

	for (i = 0; i < 20; i++){
		for (j = 0; j < 20; j++){
			fscanf_s(savedata, "%d", &b[i][j]);
		}
	}
	
	fscanf_s(savedata, "%d", &page);

	fscanf_s(savedata, "%d", &game);

	fscanf_s(savedata, "%d", &x);

	fscanf_s(savedata, "%d", &y);

	fscanf_s(savedata, "%d", &flag);

	fscanf_s(savedata, "%d", &flag1);

	fscanf_s(savedata, "%d", &flag2);

	fscanf_s(savedata, "%d", &ct);

	fscanf_s(savedata, "%d", &flag_before);

	fscanf_s(savedata, "%d", &sg_x);

	fscanf_s(savedata, "%d", &sg_y);

	fscanf_s(savedata, "%d", &flag_g);

	fscanf_s(savedata, "%d", &flag_g_before);

	fscanf_s(savedata, "%d", &rg_x);

	fscanf_s(savedata, "%d", &rg_y);

	fscanf_s(savedata, "%d", &flag_r);

	fscanf_s(savedata, "%d", &flag_r2);

	fscanf_s(savedata, "%d", &cnt_l);

	fscanf_s(savedata, "%d", &flag_s);

	fscanf_s(savedata, "%d", &score);

	fscanf_s(savedata, "%d", &highscore);

	fscanf_s(savedata, "%d", &cnt1);

	fscanf_s(savedata, "%d", &cnt2);

	fscanf_s(savedata, "%d", &high1);

	fscanf_s(savedata, "%d", &cnt_f_si);

	fscanf_s(savedata, "%d", &cnt_r);

	fclose(savedata);
}

void ghost_freeze(){
	flag_gf = 1;
	cnt_move_gf++;
}

void life_increase(){
	flag_li = 1;
	cnt_move_li++;
}

void score_increase(){
	flag_si = 1;
	cnt_move_si++;
}

int  block_input(int i, int j){
	if ((i == 0 && j != 10) || (i == 19 && j != 10) || (j == 0 && i != 10) || (j == 19 && i != 10)) return 1;
	else if (i % 2 == 0 && i<10 && j != 1 && j != 18 && j!=10 ) return 1;
	else if (i % 2 != 0 && i>10 && j != 1 && j != 18 && j!=10 ) return 1;
	else return 3;
}

int random_flag_change( int rg_x, int rg_y, int flag_r ){
	if (rg_x / 32 == 1 && rg_y / 32 == 14 && flag_r == 3)
		return 0;
	else if (rg_x / 32 == 18 && rg_y / 32 == 9 && flag_r == 3)
		return 1;
	else if (rg_x / 32 == 18 && rg_y / 32 == 5 && flag_r == 2)
		return 1;
	else if (rg_x / 32 == 1 && rg_y / 32 == 9 && flag_r == 2)
		return 0;
	else return flag_r;
}

int pac_change(int x, int y ,int flag ){
	if ((y / 32 )== 19 && flag==2 )
		return 0;
	else if ((y/ 32) != 19 && flag == 2) 
		return y;
    if ((y / 32) == 0 && flag==3 )
		return 19*32;
	else if ((y / 32) != 0 && flag == 3) 
		return y;
	if ((x / 32) == 0 && flag==1 )
		return 19*32;
	else if ((x / 32) != 0 && flag == 1) 
		return x;
	if ((x / 32) == 19 && flag == 0)
		return 0;
	else if ((x / 32) != 19 && flag == 0)
		return x;
}

int flag_change(int x_p, int y_p, int x_g, int y_g ,int flag_g){
	if ((x_g > x_p) && (y_g > y_p)){
		if ((x_g - x_p) <= (y_g - y_p)) return 1;
		else if ((x_g - x_p) > (y_g - y_p)) return 3;
	}
	else if ((x_g < x_p) && (y_g > y_p)){
		if ((x_p - x_g) <= (y_g - y_p)) return 0;
		else if ((x_p - x_g) > (y_g - y_p)) return 3;
	}
	else if ((x_g > x_p) && (y_g < y_p)){
		if ((x_g - x_p) <= (y_p - y_g)) return 1;
		else if ((x_g - x_p) > (y_p - y_g)) return 2;
	}
	else if ((x_g < x_p) && (y_g < y_p)){
		if ((x_p - x_g) <= (y_p - y_g)) return 0;
		else if ((x_p - x_g) > (y_p - y_g)) return 2;
	}
	else if (x_g == x_p){
		if (y_g < y_p)return 2;
		else if (y_g > y_p)return 3;
		else if (y_g == y_p)return flag_g;
	}
	else if (y_g == y_p){
		if (x_g < x_p) return 0;
		else if (x_g > x_p) return 1;
		else if (x_g == x_p) return flag_g;
	}
}

int flag_check(int x , int y , int sg_x , int sg_y , int flag_g){
	if (flag_g == 0){
		if (y < sg_y) return 3;
		else if (y > sg_y) return 2;
	}
	else if (flag_g == 1){
		if (y < sg_y) return 3;
		else if (y > sg_y) return 2;
	}
	else if (flag_g == 2){
		if (x < sg_x) return 1;
		else if (x > sg_x) return 0;
	}
	else if (flag_g == 3){
		if (x < sg_x) return 1;
		else if (x > sg_x) return 0;
	}
}

int check_move(int rg_x, int rg_y , int flag_r){
	if (rg_x / 32 == 1 && rg_y / 32 == 1 && flag_r == 3) 
		return 0;
	else if (rg_x / 32 == 1 && rg_y / 32 == 1 && flag_r == 1)
		return 2;
	else if (rg_x / 32 == 1 && rg_y / 32 == 18 && flag_r == 2)
		return 0;
	else if (rg_x / 32 == 1 && rg_y / 32 == 18 && flag_r == 1)
		return 3;
	else if (rg_x / 32 == 18 && rg_y / 32 == 1 && flag_r == 0)
		return 2;
	else if (rg_x / 32 == 18 && rg_y / 32 == 1 && flag_r == 3)
		return 1;
	else if (rg_x / 32 == 18 && rg_y / 32 == 18 && flag_r == 2)
		return 1;
	else if (rg_x / 32 == 18 && rg_y / 32 == 18 && flag_r == 0)
		return 3;
	else if (rg_x / 32 == 18 && rg_y / 32 == 14 && flag_r == 0)
		return 3;
	else if (rg_x / 32 == 1 && rg_y / 32 == 9 && flag_r == 1)
		return 3;
	else if (rg_x / 32 == 1 && rg_y / 32 == 5 && flag_r == 1)
		return 2;
	else if (rg_x / 32 == 18 && rg_y / 32 == 9 && flag_r == 0)
		return 2;
	else if (b[(rg_y + 32) / 32][rg_x / 32] != 1){
		return 2;
	}
	else if (b[(rg_y - 32) / 32][rg_x / 32] != 1){
		return 3;
	}
	else if (b[rg_y / 32][(rg_x + 32) / 32] != 1){
		return 0;
	}
	else if (b[rg_y / 32][(rg_x - 32) / 32] != 1){
		return 1;
	}
}


/* 
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//printf("flag_gfn : %d\n", flag_gfn);
	if (page == 0){
		int cnt_text=0;
		char str[40] = "Click anywhere to play .....";
		iShowBMP(0, 0, "pac_front.bmp");
		if (cnt_text % 20 == 0){
			iSetcolor(0, 0, 255);
			iText(10, 12, str, GLUT_BITMAP_TIMES_ROMAN_24);
		}
		cnt_text++;
	}
	if (page == 1){
		iSetcolor(255, 255, 255);
		iFilledRectangle(0, 0, 640, 736);
		iShowBMP(10, 410, "pac_front2.bmp");
		iShowBMP(10, 0, "pac4.bmp");
		iShowBMP(220, 50, "pac2.bmp");
		iShowBMP(420, 50, "pac1.bmp");
		iShowBMP(200, 300, "start.bmp");
		iShowBMP(136, 300, "start_logo.bmp");
	}
	if (page == 3){
		char str3[40], str4[40];
		iSetcolor(255, 255, 255);
		iFilledRectangle(0, 0, 640, 736);
		if (game == 1)
			iShowBMP(50, 50, "lose.bmp");
		if (game == 2)
			iShowBMP(50, 50, "win.bmp");
		if (score == highscore)
			iShowBMP(530, 290, "trophy.bmp");
		iShowBMP(295, 280, "your_score.bmp");
		sprintf_s(str3, "%d", score);
		iSetcolor(0, 0, 0);
		iText(483, 308, str3, GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP(290, 220, "high_score.bmp");
		sprintf_s(str4, "%d", highscore);
		iSetcolor(0, 0, 0);
		iText(478, 243, str4, GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP(20, 420, "pac_last.bmp");
		iShowBMP(295, 50, "exit.bmp");
		iShowBMP(300, 140, "restart.bmp");
	}
	if (page == 4){
		iSetcolor(255, 255, 255);
		iFilledRectangle(400,250 ,240 ,156);
		iShowBMP(410, 260, "save.bmp");
		iShowBMP(410, 332, "new.bmp");
	}
	if (page == 2){
		iClear();
		ct++;
		//printf("flag_gfn : %d\n", flag_gfn);
		//place your drawing codes here	
		int i, j, b_x, b_y, b_r, b_c;
		if (flag1 == 0){
			for (i = 0; i < 20; i++){
				for (j = 0; j < 20; j++){
					if ((y / 32) == i && (x / 32) == j){
						a[i][j] = 2;
					}
					else a[i][j] = block_input(i, j);
					if (a[i][j] == 3) cnt1++;
				}
			}
			flag1++;

			for (i = 0; i < 20; i++){
				for (j = 0; j < 20; j++){
					b[i][j] = a[i][j];
				}
			}
		}
		if (flag_gf == 1 && game != 3 ){
			gf_x = change_gf_x(cnt_move_gf);
			gf_y = change_gf_y(cnt_move_gf);
			if (y / 32 == gf_x && x / 32 == gf_y){
				flag_gfs = 1;
				flag_gf = 0;
				cnt_gf_f = 1;
			}
			else{
				if (cnt_gf == 0){
					temp_gf = b[gf_x][gf_y]; 
					b[gf_x][gf_y] = 4;
				}
			}
			cnt_gf++;
			if (cnt_gf % 100 == 0 && flag_gf==1 ){
				flag_gf = 0;
				b[gf_x][gf_y] = temp_gf;
				cnt_gf = 0;
			}
			if (flag_gf == 0) cnt_gf = 0;
		}
		if (flag_gfs == 1){
			cnt_gfs++;
			if (cnt_gfs % 100 == 0) flag_gfs = 0;
		}
		if (flag_li == 1 && game != 3){
			li_x = change_li_x(cnt_move_li);
			li_y = change_li_y(cnt_move_li);
			if (y / 32 == li_x && x / 32 == li_y){
				cnt_l++;
				cnt_li_f = 1;
				flag_li = 0;
			}
			else {
				if (cnt_li == 0){
					temp_li = b[li_x][li_y];
					b[li_x][li_y] = 5;
				}
			}
			cnt_li++;
			if (cnt_li % 150 == 0 && flag_li == 1){
				b[li_x][li_y] = temp_li;
				flag_li = 0;
				cnt_li = 0;
			}
			if (flag_li == 0) cnt_li = 0;
		}
		if (flag_si == 1 && game != 3){
			si_x = change_si_x(cnt_move_si);
			si_y = change_si_y(cnt_move_si);
			if (y / 32 == si_x && x / 32 == si_y){
				score += 100;
				cnt_si_f = 1;
				flag_si = 0;
				cnt_f_si++;
			}
			else {
				if (cnt_si == 0){
					temp_si = b[si_x][si_y];
					b[si_x][si_y] = 6;
				}
			}
			cnt_si++;
			if (cnt_si % 50 == 0 && flag_si == 1){
				b[si_x][si_y] = temp_si;
				flag_si = 0;
				cnt_si = 0;
			}
			if (flag_si == 0) cnt_si = 0;
		}
		for (i = 0, b_y = 0; i < 20; i++){
			for (j = 0, b_x = 0; j < 20; j++){
				if (b[i][j] == 1) iShowBMP(b_x, b_y, "block.bmp");
				else if (b[i][j] == 2) iShowBMP(b_x, b_y, "pac_start.bmp");
				else if (b[i][j] == 3) iShowBMP(b_x, b_y, "food.bmp");
				else if (b[i][j] == 0) iShowBMP(b_x, b_y, "pac_blank.bmp");
				else if (b[i][j] == 4) iShowBMP(b_x, b_y, "ghost_freeze.bmp");
				else if (b[i][j] == 5) iShowBMP(b_x, b_y, "black.bmp");
				else if (b[i][j] == 6) iShowBMP(b_x, b_y, "mango.bmp");
				b_x += 32;
			}
			b_y += 32;
		}
		if (flag_gfs != 1){
			iShowBMP(sg_x, sg_y, "search_ghost.bmp");
			iShowBMP(rg_x, rg_y, "random_ghost.bmp");
		}
		else if (flag_gfs == 1){
			iShowBMP(sg_x, sg_y, "freeze_ghost.bmp");
			iShowBMP(rg_x, rg_y, "freeze_ghost.bmp");
		}
		// SEARCH GHOST COLLISSION DETECTION:
		if (((((x - sg_x) == 32 && flag == 1 && flag_g == 0) || (x == sg_x)) && y == sg_y) || ((((sg_x - x) == 32 && flag == 0 && flag_g == 1) || (sg_x == x)) && y == sg_y) || ((((y - sg_y) == 32 && flag == 3 && flag_g == 2) || (y == sg_y)) && x == sg_x) || ((((sg_y - y) == 32 && flag == 2 && flag_g == 3) || (sg_y == y)) && x == sg_x)){
			b[y / 32][x / 32] = 0;
			x = 32; y = 32; sg_x = 576; sg_y = 576; rg_x = 320; rg_y = 288;
			b[1][1] = 2;
			flag = 4; flag_g = 1; flag_r = 0; flag2 = 4; flag_gfs = 0;
			cnt_l--;
			PlaySound(TEXT("pacman_eatghost.wav"), NULL, SND_ASYNC);
		}
		// RANDOM GHOST COLLISSION DETECTION:
		if (((((x - rg_x) == 32 && flag == 1 && flag_r == 0) || (x == rg_x)) && y == rg_y) || ((((rg_x - x) == 32 && flag == 0 && flag_r == 1) || (rg_x == x)) && y == rg_y) || ((((y - rg_y) == 32 && flag == 3 && flag_r == 2) || (y == rg_y)) && x == rg_x) || ((((rg_y - y) == 32 && flag == 2 && flag_r == 3) || (rg_y == y)) && x == rg_x)){
			b[y / 32][x / 32] = 0;
			x = 32; y = 32; sg_x = 576; sg_y = 576; rg_x = 320; rg_y = 288;
			b[1][1] = 2;
			flag = 4; flag_g = 1; flag_r = 0; flag2 = 4; flag_gfs = 0;
			cnt_l--;
			PlaySound(TEXT("pacman_eatghost.wav"), NULL, SND_ASYNC);
		}

		iSetcolor(256, 256, 256);
		iFilledRectangle(0, 640, 640, 96);
		iShowBMP(10, 650, "s.bmp");
		iShowBMP(42, 650, "c.bmp");
		iShowBMP(74, 650, "o.bmp");
		iShowBMP(106, 650, "r.bmp");
		iShowBMP(138, 650, "e.bmp");
		iShowBMP(170, 650, "colon.bmp");
		iShowBMP(180, 680, "pac_man_logo.bmp");
		iShowBMP(570, 670, "quit_button.bmp");
		if (game == 3){
			iShowBMP(506, 670, "play_logo.bmp");
		}
		else{
			iShowBMP(506, 670, "pause_logo.bmp");
		}
		iShowBMP(420, 650, "life.bmp");
		char str5[5] = "=";
		iSetcolor(256, 0, 0);
		iText(455, 655, str5, GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf_s(lifes, "%d", cnt_l);
		iSetcolor(256, 0, 0);
		iText(470, 655, lifes, GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf_s(scores, "%d", score);
		iSetcolor(256, 0, 0);
		iText(202, 658, scores, GLUT_BITMAP_TIMES_ROMAN_24);
		if (score == ((cnt1 * 15) + (cnt_f_si * 100))) {
			game = 2;
			if (high1 == 0){
				highscore = score;
			}
			if (score > highscore){
				highscore = score;
			}
			iShowBMP(64, 64, "pac_win.bmp");
			if (flag_s == 0){
				PlaySound(TEXT("pacman_intermission.wav"), NULL, SND_ASYNC);
				flag_s = 1;
			}
		}
		if (cnt_l == 0){
			iShowBMP(64, 64, "pac_game_over.bmp");
			if (high1 == 0){
				highscore = score;
			}
			if (score > highscore){
				highscore = score;
			}
			game = 1;
			if (flag_s == 0){
				PlaySound(TEXT("pacman_death.wav"), NULL, SND_ASYNC);
				flag_s = 1;
			}
		}
		if (game == 0)flag_game = 0;
		else if (game == 3)flag_game = 1;
		if (game == 0){

			//RANDOM GHOST ALGO:
			if (flag_gfs != 1){
				flag_r = random_flag_change(rg_x, rg_y, flag_r);
				if (flag_r == 0 && ct % 2 == 0){
					if (b[rg_y / 32][(rg_x + 32) / 32] == 1 && rg_x != 608) {
						flag_r2 = check_move(rg_x, rg_y, flag_r);
						flag_r = 4;
					}
					else{
						rg_x = pac_change(rg_x, rg_y, flag_r);
						rg_x += 32;
					}
				}
				else if (flag_r == 1 && ct % 2 == 0){
					if (b[rg_y / 32][(rg_x - 32) / 32] == 1 && rg_x != 0) {
						flag_r2 = check_move(rg_x, rg_y, flag_r);
						flag_r = 4;
					}
					else{
						rg_x = pac_change(rg_x, rg_y, flag_r);
						rg_x -= 32;
					}
				}
				else if (flag_r == 2 && ct % 2 == 0){
					if (b[(rg_y + 32) / 32][rg_x / 32] == 1 && rg_y != 608){
						flag_r2 = check_move(rg_x, rg_y, flag_r);
						flag_r = 4;
					}
					else{
						rg_y = pac_change(rg_x, rg_y, flag_r);
						rg_y += 32;
					}
				}
				else if (flag_r == 3 && ct % 2 == 0){
					if (b[(rg_y - 32) / 32][rg_x / 32] == 1 && rg_y != 0){
						flag_r2 = check_move(rg_x, rg_y, flag_r);
						flag_r = 4;
					}
					else{
						rg_y = pac_change(rg_x, rg_y, flag_r);
						rg_y -= 32;
					}
				}
				if (flag_r == 4 && ct % 2 == 0){
					flag_r = flag_r2;
					if (flag_r == 0){
						rg_x = pac_change(rg_x, rg_y, flag_r);
						rg_x += 32;
					}
					else if (flag_r == 1){
						rg_x = pac_change(rg_x, rg_y, flag_r);
						rg_x -= 32;
					}
					else if (flag_r == 2){
						rg_y = pac_change(rg_x, rg_y, flag_r);
						rg_y += 32;
					}
					else if (flag_r == 3){
						rg_y = pac_change(rg_x, rg_y, flag_r);
						rg_y -= 32;
					}
				}

				//SEARCH GHOST ALGO:

				flag_g_before = flag_g;

				if (flag_g == 0 && ct % 2 == 0){
					if (b[sg_y / 32][(sg_x + 32) / 32] == 1 && sg_x != 608) {
						flag_g = 4;
					}
					else{
						sg_x = pac_change(sg_x, sg_y, flag_g);
						sg_x += 32;
					}
				}
				else if (flag_g == 1 && ct % 2 == 0){
					if (b[sg_y / 32][(sg_x - 32) / 32] == 1 && sg_x != 0) {
						flag_g = 4;
					}
					else{
						sg_x = pac_change(sg_x, sg_y, flag_g);
						sg_x -= 32;
					}
				}
				else if (flag_g == 2 && ct % 2 == 0){
					if (b[(sg_y + 32) / 32][sg_x / 32] == 1 && sg_y != 608){
						flag_g = 4;
					}
					else{
						sg_y = pac_change(sg_x, sg_y, flag_g);
						sg_y += 32;
					}
				}
				else if (flag_g == 3 && ct % 2 == 0){
					if (b[(sg_y - 32) / 32][sg_x / 32] == 1 && sg_y != 0){
						flag_g = 4;
					}
					else{
						sg_y = pac_change(sg_x, sg_y, flag_g);
						sg_y -= 32;
					}
				}
				if (flag_g == 4 && ct % 2 == 0){
					flag_g = flag_check(x, y, sg_x, sg_y, flag_g_before);
					if (flag_g == 0){
						sg_x = pac_change(sg_x, sg_y, flag_g);
						sg_x += 32;
					}
					else if (flag_g == 1){
						sg_x = pac_change(sg_x, sg_y, flag_g);
						sg_x -= 32;
					}
					else if (flag_g == 2){
						sg_y = pac_change(sg_x, sg_y, flag_g);
						sg_y += 32;
					}
					else if (flag_g == 3){
						sg_y = pac_change(sg_x, sg_y, flag_g);
						sg_y -= 32;
					}
				}
			}

			//PACMAN MOVE ALGO:

			if ((flag2 == 2) && (b[(y + 32) / 32][x / 32] != 1)){
				flag = 2;
				flag2 = 4;
			}
			else if ((flag2 == 3) && (b[(y - 32) / 32][x / 32] != 1)){
				flag = 3;
				flag2 = 4;
			}
			else if ((flag2 == 0) && (b[y / 32][(x + 32) / 32] != 1)){
				flag = 0;
				flag2 = 4;
			}
			else if ((flag2 == 1) && (b[y / 32][(x - 32) / 32] != 1)){
				flag = 1;
				flag2 = 4;
			}


			if (flag != 4) flag_before = flag;
			if (flag == 0 && ct % 2 == 0){
				if (b[y / 32][(x + 32) / 32] == 1 && x != 608) {
					flag = 4;
				}
				else{
					x = pac_change(x, y, flag);
					if (ct % 2 == 0) iShowBMP(x, y, "pac_right.bmp");
					if (x == 0) {
						if (b[y / 32][0] == 3) {
							cnt2++;
							if (ct % 4 == 0)
								PlaySound(TEXT("pacman_chomp.wav"), NULL, SND_ASYNC);
						}
						temp = b[y / 32][0];
						b[y / 32][0] = b[y / 32][19];
						b[y / 32][19] = 0;
					}
					x += 32;
					if (x > 0) {
						if (b[y / 32][x / 32] == 3) {
							cnt2++;
							if (ct % 4 == 0)
								PlaySound(TEXT("pacman_chomp.wav"), NULL, SND_ASYNC);
						}
						temp = b[y / 32][x / 32];
						b[y / 32][x / 32] = b[y / 32][(x - 32) / 32];
						if (flag_gfs == 1 && cnt_gf_f == 1){
							b[y / 32][(x - 32) / 32] = temp_gf;
							cnt_gf_f = 0;
							temp_gf = 0;
						}
						else if (cnt_li_f == 1){
							b[y / 32][(x - 32) / 32] = temp_li;
							cnt_li_f = 0;
							temp_li = 0;
						}
						else if (cnt_si_f == 1){
							b[y / 32][(x - 32) / 32] = temp_si;
							cnt_si_f = 0;
							temp_si = 0;
						}
						else b[y / 32][(x - 32) / 32] = 0;
					}
				}
			}
			else if (flag == 1 && ct % 2 == 0)
			{
				if (b[y / 32][(x - 32) / 32] == 1 && x != 0){
					flag = 4;
				}
				else{
					x = pac_change(x, y, flag);
					if (ct % 2 == 0) iShowBMP(x, y, "pac_left.bmp");
					if (x == 608) {
						if (b[y / 32][19] == 3){
							cnt2++;
							if (ct % 4 == 0)
								PlaySound(TEXT("pacman_chomp.wav"), NULL, SND_ASYNC);
						}
						temp = b[y / 32][19];
						b[y / 32][19] = b[y / 32][0];
						b[y / 32][0] = 0;
					}
					x -= 32;
					if (x < 608) {
						if (b[y / 32][x / 32] == 3){
							cnt2++;
							if (ct % 4 == 0)
								PlaySound(TEXT("pacman_chomp.wav"), NULL, SND_ASYNC);
						}
						temp = b[y / 32][x / 32];
						b[y / 32][x / 32] = b[y / 32][(x + 32) / 32];
						if (flag_gfs == 1 && cnt_gf_f == 1){
							b[y / 32][(x + 32) / 32] = temp_gf;
							cnt_gf_f = 0;
							temp_gf = 0;
						}
						else if (cnt_li_f == 1){
							b[y / 32][(x + 32) / 32] = temp_li;
							cnt_li_f = 0;
							temp_li = 0;
						}
						else if (cnt_si_f == 1){
							b[y / 32][(x + 32) / 32] = temp_si;
							cnt_si_f = 0;
							temp_si = 0;
						}
						else b[y / 32][(x + 32) / 32] = 0;
					}
				}
			}
			else if (flag == 2 && ct % 2 == 0)
			{
				if (b[(y + 32) / 32][x / 32] == 1 && y != 608){
					flag = 4;
				}
				else{
					y = pac_change(x, y, flag);
					if (ct % 2 == 0) iShowBMP(x, y, "pac_up.bmp");
					if (y == 0) {
						if (b[0][x / 32] == 3){
							cnt2++;
							if (ct % 4 == 0)
								PlaySound(TEXT("pacman_chomp.wav"), NULL, SND_ASYNC);
						}
						temp = b[0][x / 32];
						b[0][x / 32] = b[19][x / 32];
						b[19][x / 32] = 0;
					}
					y += 32;
					if (y > 0) {
						if (b[y / 32][x / 32] == 3){
							cnt2++;
							if (ct % 4 == 0)
								PlaySound(TEXT("pacman_chomp.wav"), NULL, SND_ASYNC);
						}
						temp = b[y / 32][x / 32];
						b[y / 32][x / 32] = b[(y - 32) / 32][x / 32];
						if (flag_gfs == 1 && cnt_gf_f == 1){
							b[(y - 32) / 32][x / 32] = temp_gf;
							cnt_gf_f = 0;
							temp_gf = 0;
						}
						else if (cnt_li_f == 1){
							b[(y - 32) / 32][x / 32] = temp_li;
							cnt_li_f = 0;
							temp_li = 0;
						}
						else if (cnt_si_f == 1){
							b[(y - 32) / 32][x / 32] = temp_si;
							cnt_si_f = 0;
							temp_si = 0;
						}
						else b[(y - 32) / 32][x / 32] = 0;
					}
				}
			}
			else if (flag == 3 && ct % 2 == 0)
			{
				if (b[(y - 32) / 32][x / 32] == 1 && y != 0) {
					flag = 4;
				}
				else {
					y = pac_change(x, y, flag);
					if (ct % 2 == 0) iShowBMP(x, y, "pac_down.bmp");
					if (y == 608) {
						if (b[19][x / 32] == 3) {
							cnt2++;
							if (ct % 4 == 0)
								PlaySound(TEXT("pacman_chomp.wav"), NULL, SND_ASYNC);
						}
						temp = b[19][x / 32];
						b[19][x / 32] = b[0][x / 32];
						b[0][x / 32] = 0;
					}
					y -= 32;
					if (y < 608) {
						if (b[y / 32][x / 32] == 3) {
							cnt2++;
							if (ct % 4 == 0)
								PlaySound(TEXT("pacman_chomp.wav"), NULL, SND_ASYNC);
						}
						temp = b[y / 32][x / 32];
						b[y / 32][x / 32] = b[(y + 32) / 32][x / 32];
						if (flag_gfs == 1 && cnt_gf_f == 1){
							b[(y + 32) / 32][x / 32] = temp_gf;
							cnt_gf_f = 0;
							temp_gf = 0;
						}
						else if ( cnt_li_f == 1){
							b[(y + 32) / 32][x / 32] = temp_li;
							cnt_li_f = 0;
							temp_li = 0;
						}
						else if (cnt_si_f == 1){
							b[(y + 32) / 32][x / 32] = temp_si;
							cnt_si_f = 0;
							temp_si = 0;
						}
						else b[(y + 32) / 32][x / 32] = 0;
					}
				}
			}

			//printf("flag_g before change :%d\n", flag_g);
			flag_g = flag_change(x, y, sg_x, sg_y, flag_g);
			//printf("pac_x:%d pac_y:%d ghost_x:%d ghost_y:%d flag:%d flag2:%d flag_before:%d \n",x, y,sg_x, sg_y, flag, flag2, flag_before);
			score = (cnt_f_si * 100) + (cnt2 * 15);
		}
	}

}

/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		if (page == 0 && mx < 640 && my < 736){
			page = 1;
		}
		else if (page == 1 && mx >= 136 && mx <= 400 && my >= 300 && my <= 364){
			page = 4;
		}
		else if (page == 4 && mx >= 410 && mx <= 610 && my >= 260 && my <= 324){
			//page = 2;
			load();
		}
		else if (page == 4 && mx >= 410 && mx <= 610 && my >= 332 && my <= 396){
			page = 2;
		}
		else if (page == 2 && (game == 1 || game == 2) && mx < 640 && my < 736){
			page = 3;
		}
		else if (page == 2 && mx >= 506 && mx <= 570 && my >= 670 && my <= 734){
			if ( flag_game == 0) game = 3;
			else if (flag_game == 1)game = 0;
		}
		else if (page == 2 && mx >= 570 && mx <= 634 && my >= 670 && my <= 734 ){
			save();
			exit(0);
		}
		else if (page == 3 && mx >= 300 && mx <= 500 && my >= 140 && my <= 204){
			page = 2;
			game = 0, high1 = 1, flag = 4, sg_x = 576, sg_y = 576, score = 0, cnt1 = 0, cnt2 = 0, x = 32, y = 32, cnt_l = 3, cnt_r = 1, rg_x = 320, rg_y = 288, flag_r = 0, flag1 = 0, flag_g = 1, flag_r2 = 4, flag_s = 0, ct = 1, flag_gf = 0, flag_gfs = 0, cnt_gf = 0, flag_li = 0, cnt_li = 0, flag_si = 0, cnt_si = 0, cnt_f_si = 0;
		}
		else if (page == 3 && mx >= 295 && mx <= 495 && my >= 50 && my <= 114){
			exit(0);
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.	
*/
void iKeyboard(unsigned char key)
{
	/*if(key == 'q')
	{
		exit(0);
	}*/
	if (key == 'w'){
		if (b[(y + 32) / 32][x / 32] == 1){
			flag = 4;
		}
		else
			flag = 2;
		if (flag == 4){
			flag = flag_before;
			flag2 = 2;
		}
	}
	if (key == 's'){
		if (b[(y - 32) / 32][x / 32] == 1) {
			flag = 4;
		}
		else 
			flag = 3;
		if (flag == 4){
			flag = flag_before;
			flag2 = 3;
		}
	}
	if (key == 'a'){
		if (b[y / 32][(x - 32) / 32] == 1){
			flag = 4;
		}
		else 
			flag = 1;
		if (flag == 4){
			flag = flag_before;
			flag2 = 1;
		}
	}
	if (key == 'd'){
		if (b[y / 32][(x + 32) / 32] == 1) {
			flag = 4;
		}
		else 
			flag = 0;
		if (flag == 4){
			flag = flag_before;
			flag2 = 0;
		}
	}
	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here. 	
	iSettimer(20000,ghost_freeze);
	iSettimer(50000, life_increase);
	iSettimer(10000, score_increase);
	if (page == 0){
		iInitialize(640, 736, "Pac-man");
	}
	if (page == 1){
		iInitialize(640, 736, "Pac-man");
	}
	if (page == 2){
		iInitialize(640, 736, "Pac-man");
	}
	if (page == 3){
		iInitialize(640, 736, "Pac-man");
	}
	if (page == 5){
		iInitialize(640, 736, "Pac-man");
	}
	return 0;
}	