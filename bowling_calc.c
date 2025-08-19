#include "bowling_calc.h"
// 函数


// 清理缓冲区
void clear_output(void)
{
	char c;
	while((c = getchar()) != '\n' && c != EOF);
}

// 登录选择菜单
void Choose_Menu(void)
{

	printf("==================================\n");
        printf("\n欢迎使用保龄球馆会员管理系统\n");
	printf("\n==================================\n");
        printf("\n请选择您登录的身份\n");
        printf("-- 1.我是会员 --\n");
        printf("-- 2.我是教练 --\n");
        printf("-- 3.退出系统 --\n");
        printf("\n==================================\n");
        printf("\n请输入:>");


}

// 用户登录
int User_login(void)
{
	long input;	
        printf("\n==================================\n");
        printf("\n请输入的会员卡号或手机号\n");
        printf("\n:>");


	clear_output();
	
	scanf("%ld", &input);


	FILE* fp = fopen(FILEOPEN, "rb");

	if(fp == NULL)
	{
		printf("fopen fail\n");
		exit(1);
	}
		
	user_image* u1 = malloc(sizeof(user_image));
	if(u1 == NULL)
	{
		printf("malloc fail\n");
		return 0;
	}
	

	while(fread(u1, sizeof(user_image), 1, fp) == 1)
	{
		if(u1->user_cancel == 0)
		{
			fclose(fp);
			free(u1);
			return 0;
		}
		else if(u1->card_id == input || u1->user_phone == (unsigned long)input)
		{
 			u = u1;	
			fclose(fp);
			system("clear");
			printf("============================================\n");
			printf("\n欢迎您使用保龄球会员信息查看系统\n");
			return 1;
		}
	}
	fclose(fp);
	free(u1);
	return 0;	
}

// 是否登录成功

int Is_login(void)
{
	if(User_login())
	{
		system("clear");
		return 0;
	}
	return 1;
}

// 用户菜单
void User_Menu(void)
{
	printf("\n============================================\n");
        printf("\n亲爱的会员<- %s ->您好\n", u->user_name);
        printf("\n============================================\n");
        printf("\n请选择您要进行的操作\n");
        printf("-- 1.查看个人信息 --\n");
        printf("-- 2.退出登录 --\n");
        printf("\n============================================\n");
        printf("\n请输入:>");
}

// 用户菜单操作
void User_choose(void)
{
	User_Menu();
	int choose;
	clear_output();
	scanf("%d", &choose);
	clear_output();
	switch(choose)
	{
		case 1:
		{	
			system("clear");
        		printf("\n============================================\n");
			printf("\n卡号:%d\n会员id:%d\n会员姓名:%s\n年龄:%d\n性别%s\n电话:%lu\n卡类型:%d\n到期时间:%d个月\n", u->card_id, u->user_id, u->user_name, u->user_age, u->user_sex,u->user_phone, u->card_type, u->card_date );
        		printf("\n============================================\n");
			printf("\n输入任意键返回:>");
			char c = getchar();
			system("clear");
			//clear_output();
			User_choose();	
			break;	
		}

		case 2:
		{
			system("clear");
        		printf("\n============================================\n");
			printf("\n感谢您的使用,再见!\n");
        		printf("\n============================================\n");
			printf("\n输入任意键返回到主菜单:>\n");
			free(u);
			char c = getchar();
			system("clear");
			clear_output();
			break;
		}

		default:
		{
			system("clear");
                        printf("\n============================================\n");
                        printf("\n您的输入有误, 请重新输入\n");
			//clear_output();
			User_choose();
			break;
		}
	}
}

// 管理员是否登录成功


// 管理员登录
int root_login(void)
{
	char root_zh[] = "root";
	char root_mi[] = "admin";
	char c[50];
	printf("\n============================================\n");
	printf("\n请输入您的管理员账号:\n;>");

	scanf("%s", c);

	clear_output();
	if(strcmp(c, root_zh))
	{
		system("clear");
		printf("\n============================================\n");
		printf("\n输入账号错误,重新输入\n");
		return 1;
	}

	printf("\n============================================\n");
	printf("\n请输入您的管理员密码:\n;>");

	scanf("%s", c);
	if(strcmp(c, root_mi))
	{
		system("clear");
		printf("\n============================================\n");
		printf("\n输入密码错误,重新输入\n:>");
		return 1;
	}


	return 0;
}


// 管理员菜单
void root_menu(void)
{
	system("clear");
        printf("\n============================================\n");
        printf("\n管理员- 您好\n");
        printf("\n============================================\n");
        printf("\n请选择您要进行的操作\n");
        printf("-- 1.添加会员信息     --\n");
        printf("-- 2.删除会员信息 --\n");
        printf("-- 3.修改会员信息 --\n");
        printf("-- 4.查看会员信息 --\n");
        printf("-- 5.退出登录 --\n");
        printf("\n============================================\n");
        printf("\n请输入:>");

}

// 管理员选择
int root_choose(void)
{
	clear_output();
	root_menu();
	int choose;
	
	if(scanf("%d", &choose) != 1)
	{
		return 0;
	}
		
	switch(choose)
	{
		case 1:
			{
				user_add();			
				return 1;	
			}
	
		case 2:
			{
				system("clear");
				while(!user_cancel());

				return 2;
			}


		case 3:
			{
				system("clear");
				while(!user_fix());
				
				return 3;
			}
		case 4:
			{
                               	system("clear");
				while(!root_find());
				return 4;
			}

		case 5:
			{
				
				return 5;
			}


		default:
			{
			        system("clear");
                                printf("==================================\n");
                                printf("\n输入的选项不对,请重新输入\n\n");
                                printf("==================================\n");
                                printf("输入任意键返回\n:>");
                                clear_output();
                                getchar();
                                clear_output();
				return 0;
			}
	}	

}

// 检查卡号或手机号是否已存在
static int is_user_exists(int card_id, unsigned long phone) {
	FILE* fp = fopen(FILEOPEN, "rb");
	if (fp == NULL) {
		return 0; // 文件不存在视为无冲突
	}

	user_image temp;
	int exists = 0;

	while (fread(&temp, sizeof(user_image), 1, fp) == 1) {
		if (temp.card_id == card_id || temp.user_phone == phone) {
			exists = 1;
			break;
		}
	}

	fclose(fp);
	return exists;
}

// 获取下一个可用的用户ID
static int get_next_user_id() {
	FILE* fp = fopen(FILEOPEN, "rb");
	if (fp == NULL) {
		return 1001; // 初始ID
	}

	user_image last_user;
	int max_id = 1000;

	// 定位到最后一个记录
	fseek(fp, -sizeof(user_image), SEEK_END);
	if (fread(&last_user, sizeof(user_image), 1, fp) == 1) {
		max_id = last_user.user_id;
	}

	fclose(fp);
	return max_id + 1;
}

// 新增用户功能
void user_add(void) {
	system("clear");
	user_image new_user = {0};

	// 获取下一个可用ID
	new_user.user_id = get_next_user_id();
	new_user.user_cancel = 1; // 默认为活跃用户

	// 打开文件准备写入
	FILE* fp = fopen(FILEOPEN, "ab+");
	if (fp == NULL) {
		printf("无法打开用户数据文件！\n");
		return;
	}

	// 输入卡号并验证
	while (1) {
		printf("\n请输入卡号(9位数字): ");
		if (scanf("%d", &new_user.card_id) != 1) {
			printf("输入无效，请重新输入！\n");
			clear_output();
			continue;
		}

		if (new_user.card_id < 100000000 || new_user.card_id > 999999999) {
			printf("卡号长度不符合要求！\n");
			continue;
		}

		if (is_user_exists(new_user.card_id, 0)) {
			printf("该卡号已存在！\n");
			continue;
		}
		break;
	}

	// 输入姓名
	printf("\n请输入姓名: ");
	scanf("%49s", new_user.user_name);
	clear_output();

	// 输入年龄
	while (1) {
		printf("\n请输入年龄(5-100岁): ");
		if (scanf("%d", &new_user.user_age) != 1) {
			printf("输入无效，请重新输入！\n");
			clear_output();
			continue;
		}

		if (new_user.user_age < 5 || new_user.user_age > 100) {
			printf("年龄超出范围！\n");
			continue;
		}
		break;
	}

	// 输入性别
	while (1) {
		printf("\n请输入性别(男/女/保密): ");
		char sex[10];
		scanf("%9s", sex);
		clear_output();

		if (strcmp(sex, "男") == 0) {
			strcpy(new_user.user_sex, "男");
			break;
		} else if (strcmp(sex, "女") == 0) {
			strcpy(new_user.user_sex, "女");
			break;
		} else if (strcmp(sex, "保密") == 0) {
			strcpy(new_user.user_sex, "保密");
			break;
		} else {
			printf("输入无效，请重新输入！\n");
		}
	}

	// 输入手机号
	while (1) {
		printf("\n请输入手机号(11位): ");
		if (scanf("%lu", &new_user.user_phone) != 1) {
			printf("输入无效，请重新输入！\n");
			clear_output();
			continue;
		}

		if (new_user.user_phone < 10000000000 || new_user.user_phone > 19999999999) {
			printf("手机号格式不正确！\n");
			continue;
		}

		if (is_user_exists(0, new_user.user_phone)) {
			printf("该手机号已注册！\n");
			continue;
		}
		break;
	}

	// 选择卡类型
	while (1) {
		printf("\n请选择卡类型:\n");
		printf("1. 年卡(12个月)\n");
		printf("2. 季卡(3个月)\n");
		printf("3. 月卡(1个月)\n");
		printf("请选择(1-3): ");

		if (scanf("%d", &new_user.card_type) != 1) {
			printf("输入无效，请重新输入！\n");
			clear_output();
			continue;
		}

		if (new_user.card_type < 1 || new_user.card_type > 3) {
			printf("选择无效，请重新输入！\n");
			continue;
		}

		// 设置卡有效期
		if (new_user.card_type == 1) {
			new_user.card_date = 12;
		} else if (new_user.card_type == 2) {
			new_user.card_date = 3;
		} else {
			new_user.card_date = 1;
		}
		break;
	}

	// 写入文件
	if (fwrite(&new_user, sizeof(user_image), 1, fp) != 1) {
		printf("写入用户数据失败！\n");
	} else {
		printf("\n用户添加成功！\n");
		printf("会员ID: %d\n", new_user.user_id);
		printf("卡号: %d\n", new_user.card_id);
	}

	fclose(fp);

	// 等待用户确认
	printf("\n按任意键返回...");
	clear_output();
	getchar();
}


// 删除功能

int user_cancel(void)
{
        printf("\n============================================\n");
        printf("\n会员注销页面\n");
        printf("\n============================================\n");

	int input;

	printf("\n请输入你要注销的卡号\n:>");
	if(scanf("%d", &input) != 1)
	{
		system("clear");
		printf("\n输入数据无效\n");
		clear_output();
		return 0;
	}

	clear_output();
	
	user_image user;

	int isfound = 0;

	unsigned long pos;

	FILE* fp = fopen(FILEOPEN, "rb+");

	if(fp == NULL)
	{
		printf("fopen faile\n");
		return 0;
	}

	while(fread(&user, sizeof(user_image), 1, fp))
	{
		if(user.card_id == input && user.user_cancel == 1)
		{
			isfound = 1;
			break;
		}
		
		pos = ftell(fp);
	}

	if(!isfound)
	{
		system("clear");
		printf("\n所输入的用户不存在或已注销\n");
		fclose(fp);
		return 0;
	}
	
	system("clear");

        printf("\n============================================\n");
        printf("\n该会员信息如下:\n");
        printf("\n============================================\n");

	printf("卡号:%d\n", user.card_id);
	printf("用户ID:%d\n", user.user_id);
	printf("姓名:%s\n", user.user_name);
	printf("年龄:%d\n", user.user_age);
	printf("性别:%s\n", user.user_sex);
	printf("手机号:%lu\n", user.user_phone);
	printf("卡类型:%d\n", user.card_type);
	printf("用户状态:%s\n", user.user_cancel ? "活跃": "已注销");


	int isdel;
	printf("\n是否要删除该用户信息?(1.是 0.否)\n");
	
	if(scanf("%d", &isdel) != 1 || (isdel != 0 && isdel != 1))
	{
		printf("\n输入无效\n");
		clear_output();
		fclose(fp);
		return 0;
	}

	clear_output();

	if(isdel == 1)
	{
		user.user_cancel = 0;

		fseek(fp, pos, SEEK_SET);

		if(fwrite(&user, sizeof(user_image), 1, fp) == 1)
		{
			printf("\n用户注销成功\n");
		}
		else
		{
			printf("\n用户注销失败\n");
		}
	}
	fclose(fp);


	printf("\n按任意键返回\n");
	clear_output();
	getchar();
	return 1;
}



static int user_fix_menu(void)
{
        printf("\n============================================\n");
        printf("\n修改的项目\n");
        printf("\n============================================\n");

	int choose;
	
        printf("\n1.卡号\n");
        printf("2.姓名\n");
        printf("3.年龄\n");
        printf("4.手机号\n");
	printf("5.会员状态:\n");
	printf("其他键退出\n");
        printf("\n============================================\n");
        if(scanf("%d", &choose) != 1)
        {
                system("clear");
                printf("\n输入数据无效\n");
                clear_output();
                return 0;
        }
	
	clear_output();

	switch(choose)
	{
		case 1:
			{
				return choose;
			}
		case 2:
			{
				return choose;
			}
		case 3:
			{
				return choose;
			}
		case 4:
			{
				return choose;
			}
		case 5:
			{
				return choose;
			}
		default:
			{
        	        		system("clear");
                			printf("\n已退出\n");
                			clear_output();
              				return 0;
			}
	}
}



// 修改用户信息

int user_fix(void)
{
        printf("\n============================================\n");
        printf("\n会员信息修改页面\n");
        printf("\n============================================\n");

	unsigned long input;

	printf("\n请输入你要修改信息的卡号或手机号\n:>");
	if(scanf("%lu", &input) != 1)
	{
		system("clear");
		printf("\n输入数据无效\n");
		clear_output();
		return 0;
	}

	clear_output();
	
	user_image user;

	int isfound = 0;

	unsigned long pos;

	FILE* fp = fopen(FILEOPEN, "rb+");

	if(fp == NULL)
	{
		printf("fopen faile\n");
		return 0;
	}

	while(fread(&user, sizeof(user_image), 1, fp))
	{
		if(user.card_id == (int)input || user.user_phone == input )
		{
			isfound = 1;
			break;
		}
		
		pos = ftell(fp);
	}

	if(!isfound)
	{
		system("clear");
		printf("\n所输入的用户不存在或已注销\n");
		fclose(fp);
		return 0;
	}
	
	system("clear");

        printf("\n============================================\n");
        printf("\n该会员信息如下:\n");
        printf("\n============================================\n");

	printf("卡号:%d\n", user.card_id);
	printf("用户ID:%d\n", user.user_id);
	printf("姓名:%s\n", user.user_name);
	printf("年龄:%d\n", user.user_age);
	printf("性别:%s\n", user.user_sex);
	printf("手机号:%lu\n", user.user_phone);
	printf("卡类型:%d\n", user.card_type);
	printf("用户状态:%s\n", user.user_cancel ? "活跃": "已注销");


	int choose = user_fix_menu();
	if(choose == 0)
	{
		return 5;
	}

	int isdel;
	printf("\n是否要修改会员的信息?(1.是 0.否)\n");
	
	if(scanf("%d", &isdel) != 1 || (isdel != 0 && isdel != 1))
	{
		printf("\n输入无效\n");
		clear_output();
		fclose(fp);
		return 0;
	}

	clear_output();

	if(isdel == 1)
	{
		if(choose == 1)
		{
			// 输入卡号并验证
			while (1) {
				printf("\n请输入卡号(9位数字): ");
				if (scanf("%d", &user.card_id) != 1) {
					printf("输入无效，请重新输入！\n");
					clear_output();
					continue;
				}

				if (user.card_id < 100000000 || user.card_id > 999999999) {
					printf("卡号长度不符合要求！\n");
					continue;
				}

				if (is_user_exists(user.card_id, 0)) {
					printf("该卡号已存在！\n");
					continue;
				}
				break;
			}	
		}
		else if(choose == 2)
		{
			// 输入姓名
			printf("\n请输入姓名: ");
			scanf("%49s", user.user_name);
			clear_output();
		}
		else if(choose == 3)
		{
			// 输入年龄
			while (1) {
				printf("\n请输入年龄(5-100岁): ");
				if (scanf("%d", &user.user_age) != 1) {
					printf("输入无效，请重新输入！\n");
					clear_output();
					continue;
				}

				if (user.user_age < 5 || user.user_age > 100) {
					printf("年龄超出范围！\n");
					continue;
				}
				break;
			}

		}
		else if(choose == 4)
		{
			// 输入手机号
			while (1) {
				printf("\n请输入手机号(11位): ");
				if (scanf("%lu", &user.user_phone) != 1) {
					printf("输入无效，请重新输入！\n");
					clear_output();
					continue;
				}

				if (user.user_phone < 10000000000 || user.user_phone > 19999999999) {
					printf("手机号格式不正确！\n");
					continue;
				}

				if (is_user_exists(0, user.user_phone)) {
					printf("该手机号已注册！\n");
					continue;
				}
				break;
			}
		}
		else if(choose == 5)
		{
			while(1)
			{
				printf("\n1.改为活跃\n2.注销");
				if((scanf("%d", &user.user_cancel)) != 1)
				{
					printf("\n无效输入\n");
					clear_output();
					continue;
				}

				if(user.user_cancel != 0 && user.user_cancel != 1)
				{
					printf("\n无效输入\n");
					continue;
				}
			
			break;
			}
		}

		fseek(fp, pos, SEEK_SET);
		if(fwrite(&user, sizeof(user_image), 1, fp) == 1)
		{
			printf("\n用户信息修改成功\n");
		}
		else
		{
			printf("\n用户信息修改失败\n");
		}
	}
	fclose(fp);

        printf("\n按任意键返回\n");
        clear_output();
        getchar();
	return 1;
}

// 管理员用户查看功能

int root_find(void)
{
        printf("\n============================================\n");
        printf("\n会员信息页面\n");
        printf("\n============================================\n");

	unsigned long input;
	int isfound = 0;

	printf("\n请输入你要查找的卡号或手机号\n:>");
	if(scanf("%lu", &input) != 1)
	{
		system("clear");
		printf("\n输入数据无效\n");
		clear_output();
		return 0;
	}

	clear_output();
	
	user_image user;

	FILE* fp = fopen(FILEOPEN, "rb");

	if(fp == NULL)
	{
		printf("fopen faile\n");
		return 0;
	}

	while(fread(&user, sizeof(user_image), 1, fp) == 1)
	{
		if(user.card_id == (int)input || user.user_phone == input)
		{
			isfound = 1;
			break;
		}
		
	}

	if(!isfound)
	{
		system("clear");
		printf("查找的信息不存在\n");

		return 1;
	
	}

	fclose(fp);
	system("clear");

        printf("\n============================================\n");
        printf("\n该会员信息如下:\n");
        printf("\n============================================\n");

	printf("卡号:%d\n", user.card_id);
	printf("用户ID:%d\n", user.user_id);
	printf("姓名:%s\n", user.user_name);
	printf("年龄:%d\n", user.user_age);
	printf("性别:%s\n", user.user_sex);
	printf("手机号:%lu\n", user.user_phone);
	printf("卡类型:%d\n", user.card_type);
	printf("用户状态:%s\n", user.user_cancel ? "活跃": "已注销");
	
        printf("\n按任意键返回\n");
        clear_output();
        getchar();
        return 1;

}
