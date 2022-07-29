# define _CRT_SECURE_NO_WARNINGS

# include "contact.h"

/**********************************通讯录*********************************************
* 1. 存放1000个好友信息（姓名、电话、性别、住址、年龄）
* 2. 增加好友信息
* 3. 删除指定姓名好友信息
* 4. 查找好友信息
* 5. 修改好友信息
* 6. 打印好友信息
* 7. 排序
* 8. 以文件形式保存，第一次运行程序会报错：LoadContact:No Such File or Directory
* 之后每次运行程序时，先从文本中加载通讯录的信息存储到 tmp 中，然后将 tmp 里的数据
* 同步到 data 中，之后保存时以 "w" 形式会把contact.txt里的信息全部删除，再写入，
* 从而实现文本中通讯录信息的更新
**************************************************************************************/


void menu()
{
	printf("*************************************\n");
	printf("******1. 增加           2. 删除******\n");
	printf("******3. 查找           4. 修改******\n");
	printf("******5. 展示           6. 排序******\n");
	printf("******7. 保存           0. exit******\n");
	printf("*************************************\n");
}

int main()
{
	// 创建通讯录
	struct contact_structure contact; //contact就是通讯录；里面有：data指针、size、capacity


	// 初始化通讯录
	InitContact(&contact);


	int input = 0;

	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);

		switch (input)
		{
		case add:
			AddContact(&contact);
			break;

		case del:
			DelContact(&contact);
			break;

		case search:
			SearchContact(&contact);
			break;

		case modify:
			ModifyContact(&contact);
			break;

		case show:
			ShowContact(&contact);
			break;

		case sort:
			printf("\n");
			SortContact(&contact);
			break;

		case save:
			SaveContact(&contact);
			break;

		case exit_option:
			// 保存
			SaveContact(&contact);
			// 销毁动态开辟的通讯录内存
			DestoryContact(&contact);
			printf("退出成功\n");
			break;

		default:
			printf("选择错误\n");
			break;
		}

	} while (input);

	return 0;
}