#include "contact.h"

/**********************************************************************
* 函数名：	InitContact
* 参数：		通讯录结构体指针
* 返回类型：	void
* 功能：		初始化通讯录
**********************************************************************/

void InitContact(struct contact_structure* ps)
{
	ps->data = (struct people_info*)malloc(default_size * sizeof(struct people_info));
	if (ps->data == NULL)
	{
		return;
	}

	ps->size = 0; // 当前元素个数
	ps->capacity = default_size; // 最大容量

	// 把文件里已经存放的通讯录信息存放到通讯录中
	LoadContact(ps);
}



/**********************************************************************
* 函数名：	CheckCapacity
* 参数：		通讯录结构体指针
* 返回类型：	void
* 功能：		检测当前通讯录容量是否满了，如果满了则增容，如果没满则什么都不干
**********************************************************************/

static void CheckCapacity(struct contact_structure* ps)
{
	if (ps->size == ps->capacity) // 满了
	{
		// 增容
		struct people_info* ptr = (struct people_info*)realloc(ps->data, (ps->capacity + increase_size) * sizeof(struct people_info));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += increase_size; // 当前最大容量增加
		}
	}
}



/**********************************************************************
* 函数名：	AddContact
* 参数：		通讯录结构体指针
* 返回类型：	void
* 功能：		增加信息
**********************************************************************/

void AddContact(struct contact_structure* ps)
{
	// 首先检测当前通讯录容量
	CheckCapacity(ps);

	// 增加数据
	printf("请输入名字:>");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入年龄:>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入性别:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入电话:>");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入地址:>");
	scanf("%s", ps->data[ps->size].address);

	ps->size++;

	printf("\n添加成功！\n\n");


}



/**********************************************************************
* 函数名：	ShowContact
* 参数：		通讯录结构体指针
* 返回类型：	void
* 功能：		打印信息
**********************************************************************/

void ShowContact(const struct contact_structure* ps)
{
	// 判断通讯录是否为空
	if (ps->size == 0)
	{
		printf("\n通讯录为空\n\n");
	}
	else
	{
		// 打印标题
		printf("\n%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");

		for (size_t i = 0; i < ps->size; i++)
		{
			printf("\n%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].address);
		}
	}
}



/**********************************************************************
* 函数名：	FindByName
* 参数：		通讯录结构体指针，输入要操作的姓名数组
* 返回类型：	int
* 功能：		查找输入的姓名是否在通讯录里；在返回下标；不在返回-1
**********************************************************************/

// 加static 修饰使FindByName()只能在contact.c中使用，并且不暴露出去
static int FindByName(const struct contact_structure* ps, char name[])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			return i; // 找到了
		}
	}

	return -1; // 没找到
}



/**********************************************************************
* 函数名：	DelContact
* 参数：		通讯录结构体指针
* 返回类型：	void
* 功能：		删除指定的联系人
**********************************************************************/

void DelContact(struct contact_structure* ps)
{
	char del_name[30];
	printf("请输入要删除人的姓名:>");
	scanf("%s", del_name);

	// 查找删除的人的姓名
	int pos = FindByName(ps, del_name);

	// 判断是找没找到
	if (pos == -1) //没找到
	{
		printf("\n要删除的人不存在\n\n");
	}
	else
	{
		// 删除
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1]; // 从后往前覆盖
		}

		ps->size--;
		printf("\n删除成功！\n\n");
	}
}



/**********************************************************************
* 函数名：	SearchContact
* 参数：		通讯录结构体指针
* 返回类型：	void
* 功能：		查找指定的联系人
**********************************************************************/

void SearchContact(const struct contact_structure* ps)
{
	char search_name[30];
	printf("请输入要查找人的姓名:>");
	scanf("%s", search_name);

	int pos = FindByName(ps, search_name);
	if (pos == -1)
	{
		printf("\n要查找的人不存在\n\n");
	}
	else
	{
		// 打印标题
		printf("\n%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");

		// 打印数据
		printf("\n%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].address);

	}
}



/**********************************************************************
* 函数名：	ModifyContact
* 参数：		通讯录结构体指针
* 返回类型：	void
* 功能：		修改指定的联系人
**********************************************************************/

void ModifyContact(struct contact_structure* ps)
{
	char modify_name[30];
	printf("请输入要修改人的姓名:>");
	scanf("%s", modify_name);

	int pos = FindByName(ps, modify_name);
	if (pos == -1)
	{
		printf("\n要修改的人不存在\n\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话:>");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址:>");
		scanf("%s", ps->data[pos].address);

		printf("\n修改完成!\n\n");
	}
}



/*
	 *   比较函数
	 *
	 *前者大于后者返回 >0 的数
	 *前者等于后者返回 =0 的数
	 *前者小于后者返回 <0 的数
*/

// 比较名字
static int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct contact_structure*)e1)->data->name, ((struct contact_structure*)e2)->data->name);
}

// 比较年龄
static int cmp_by_age(const void* e1, const void* e2)
{
	return ((struct contact_structure*)e1)->data->age - ((struct contact_structure*)e2)->data->age;
}

// 比较性别
static int cmp_by_sex(const void* e1, const void* e2)
{
	return strcmp(((struct contact_structure*)e1)->data->sex, ((struct contact_structure*)e2)->data->sex);
}

/**********************************************************************
* 函数名：	SortContact
* 参数：		通讯录结构体指针
* 返回类型：	void
* 功能：		排序；可根据姓名、年龄、性别排序
**********************************************************************/

void SortContact(struct contact_structure* ps)
{
	printf("*************************************\n");
	printf("******        排序选项         ******\n");
	printf("******11. 姓名           12. 年龄******\n");
	printf("******         13. 性别         ******\n");
	printf("*************************************\n");

	int single_data_size = sizeof(ps->data[0]); //每个元素大小


	int sort_option = 0;
	printf("请输入排序选项:>");
	scanf("%d", &sort_option);

	switch (sort_option)
	{
	case sort_by_name:
		qsort(ps->data, ps->size, single_data_size, cmp_by_name);
		break;
	case sort_by_age:
		qsort(ps->data, ps->size, single_data_size, cmp_by_age);
		break;
	case sort_by_sex:
		qsort(ps->data, ps->size, single_data_size, cmp_by_sex);
		break;
	default:
		printf("输入有误！");
		break;
	}

	printf("\n排序成功!\n\n");

}



/**********************************************************************
* 函数名：	DestoryContact
* 参数：		通讯录结构体指针
* 返回类型：	void
* 功能：		销毁通讯录中动态开辟的内存
**********************************************************************/

void DestoryContact(struct contact_structure* ps)
{
	free(ps->data);
	ps->data = NULL;
}



/**********************************************************************
* 函数名：	SaveContact
* 参数：		通讯录结构体指针
* 返回类型：	void
* 功能：		保存当前的通讯录
**********************************************************************/

void SaveContact(struct contact_structure* ps)
{
	FILE* pfWrite = fopen("contact.txt", "w"); // 每次重新打开程序先把旧的数据加载到初始化的数组里；写数据的时候会把旧文件的内容删除；
	if (pfWrite != NULL)
	{
		// 数据写到文件
		for (size_t i = 0; i < ps->size; i++)
		{
			fwrite(&(ps->data[i]), sizeof(struct people_info), 1, pfWrite);
		}
		fclose(pfWrite);
		pfWrite = NULL;

		printf("\n保存成功\n\n");
	}
	else
	{
		printf("\nSaveContact:%s\n", strerror(errno));
		return;
	}

}



/**********************************************************************
* 函数名：	LoadContact
* 参数：		通讯录结构体指针
* 返回类型：	void
* 功能：		从之前保存的通讯录中价加载信息
**********************************************************************/

void LoadContact(struct contact_structure* ps)
{
	struct people_info tmp = { 0 };
	FILE* pfRead = fopen("contact.txt", "r");
	if (pfRead != NULL)
	{
		// 读数据
		while (fread(&tmp, sizeof(struct people_info), 1, pfRead)) // 每次读一个；fread() 读完所有数据会返回 0 
		{
			CheckCapacity(ps); // 检查容量是否够放，不够增容；防止出现通讯录里有 5 个信息，通讯录初始只有 3 个位置
			ps->data[ps->size] = tmp;
			ps->size++;
		}

		fclose(pfRead);
		pfRead = NULL;
	}
	else
	{
		printf("\nLoadContact:%s\n", strerror(errno));
		return;
	}
}
