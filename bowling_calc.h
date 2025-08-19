#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


// 会员结构体
typedef struct
{
	int card_id;
        int user_id;
        char user_name[50];
        int user_age;
        char user_sex[7];
        unsigned long user_phone;
        int card_type;  // 卡的类型: 1.年卡 2.季卡 3.次卡
        int card_date;
	int user_cancel; // 0.已注销 1. 活跃	
}user_image;

// 会员卡结构体

//extern user_image user[100];

extern user_image* u;
user_image* u;

// 宏定义常量
#define USERMAX 100
#define CARDMAX 100
#define FILEOPEN "./bowling_user.dat"



// 函数声明
void clear_output(void);
void Choose_Menu(void);
int User_login(void);
void User_Menu(void);
int Is_login(void);
void User_choose(void);
int root_login(void);
void root_menu(void);
int root_choose(void);
void user_add(void);
int user_cancel(void);
int user_fix(void);
int root_find(void);
