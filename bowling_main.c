#include "bowling_calc.h"


int main()
{
	int user_input;  // 用户输入选择
	int user_choose; // 身份输入选择

	system("clear");

	while(1)
	{
		Choose_Menu();
		//clear_output();	
		scanf("%d", &user_choose);

		switch(user_choose)
		{
			case 1:
			{
				system("clear");

				while(Is_login())
				{
					system("clear");
					printf("==================================\n");
					printf("\n输入的会员用户不存在, 请重新输入\n");
				}
				clear_output();
				User_choose();

				break;
			}
		
			case 2:
			{
				system("clear");
				
				clear_output();
					
				while(root_login());
				
				while(root_choose() != 5);

				system("clear");								
				break;	
			}
				
			case 3:
			{
				system("clear");
				printf("==================================\n");
				printf("\n感谢您的使用，期待与您的再会\n\n");
				printf("==================================\n");
				printf("输入任意键退出\n:>");
				clear_output();
				char c = getchar();
				clear_output();			
				exit(1);
				break;
			}
			default:
			{
				system("clear");
				printf("==================================\n");
				printf("\n输入的选项不对,请重新输入\n\n");
				printf("==================================\n");
				printf("输入任意键返回主菜单\n:>");
				clear_output();
				char c = getchar();
				clear_output();
				system("clear");
			}
		
		}
	}

	
return 0;
}
