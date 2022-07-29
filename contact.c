#include "contact.h"

/**********************************************************************
* ��������	InitContact
* ������		ͨѶ¼�ṹ��ָ��
* �������ͣ�	void
* ���ܣ�		��ʼ��ͨѶ¼
**********************************************************************/

void InitContact(struct contact_structure* ps)
{
	ps->data = (struct people_info*)malloc(default_size * sizeof(struct people_info));
	if (ps->data == NULL)
	{
		return;
	}

	ps->size = 0; // ��ǰԪ�ظ���
	ps->capacity = default_size; // �������

	// ���ļ����Ѿ���ŵ�ͨѶ¼��Ϣ��ŵ�ͨѶ¼��
	LoadContact(ps);
}



/**********************************************************************
* ��������	CheckCapacity
* ������		ͨѶ¼�ṹ��ָ��
* �������ͣ�	void
* ���ܣ�		��⵱ǰͨѶ¼�����Ƿ����ˣ�������������ݣ����û����ʲô������
**********************************************************************/

static void CheckCapacity(struct contact_structure* ps)
{
	if (ps->size == ps->capacity) // ����
	{
		// ����
		struct people_info* ptr = (struct people_info*)realloc(ps->data, (ps->capacity + increase_size) * sizeof(struct people_info));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += increase_size; // ��ǰ�����������
		}
	}
}



/**********************************************************************
* ��������	AddContact
* ������		ͨѶ¼�ṹ��ָ��
* �������ͣ�	void
* ���ܣ�		������Ϣ
**********************************************************************/

void AddContact(struct contact_structure* ps)
{
	// ���ȼ�⵱ǰͨѶ¼����
	CheckCapacity(ps);

	// ��������
	printf("����������:>");
	scanf("%s", ps->data[ps->size].name);
	printf("����������:>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("�������Ա�:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("������绰:>");
	scanf("%s", ps->data[ps->size].tele);
	printf("�������ַ:>");
	scanf("%s", ps->data[ps->size].address);

	ps->size++;

	printf("\n��ӳɹ���\n\n");


}



/**********************************************************************
* ��������	ShowContact
* ������		ͨѶ¼�ṹ��ָ��
* �������ͣ�	void
* ���ܣ�		��ӡ��Ϣ
**********************************************************************/

void ShowContact(const struct contact_structure* ps)
{
	// �ж�ͨѶ¼�Ƿ�Ϊ��
	if (ps->size == 0)
	{
		printf("\nͨѶ¼Ϊ��\n\n");
	}
	else
	{
		// ��ӡ����
		printf("\n%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");

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
* ��������	FindByName
* ������		ͨѶ¼�ṹ��ָ�룬����Ҫ��������������
* �������ͣ�	int
* ���ܣ�		��������������Ƿ���ͨѶ¼��ڷ����±ꣻ���ڷ���-1
**********************************************************************/

// ��static ����ʹFindByName()ֻ����contact.c��ʹ�ã����Ҳ���¶��ȥ
static int FindByName(const struct contact_structure* ps, char name[])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			return i; // �ҵ���
		}
	}

	return -1; // û�ҵ�
}



/**********************************************************************
* ��������	DelContact
* ������		ͨѶ¼�ṹ��ָ��
* �������ͣ�	void
* ���ܣ�		ɾ��ָ������ϵ��
**********************************************************************/

void DelContact(struct contact_structure* ps)
{
	char del_name[30];
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", del_name);

	// ����ɾ�����˵�����
	int pos = FindByName(ps, del_name);

	// �ж�����û�ҵ�
	if (pos == -1) //û�ҵ�
	{
		printf("\nҪɾ�����˲�����\n\n");
	}
	else
	{
		// ɾ��
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1]; // �Ӻ���ǰ����
		}

		ps->size--;
		printf("\nɾ���ɹ���\n\n");
	}
}



/**********************************************************************
* ��������	SearchContact
* ������		ͨѶ¼�ṹ��ָ��
* �������ͣ�	void
* ���ܣ�		����ָ������ϵ��
**********************************************************************/

void SearchContact(const struct contact_structure* ps)
{
	char search_name[30];
	printf("������Ҫ�����˵�����:>");
	scanf("%s", search_name);

	int pos = FindByName(ps, search_name);
	if (pos == -1)
	{
		printf("\nҪ���ҵ��˲�����\n\n");
	}
	else
	{
		// ��ӡ����
		printf("\n%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");

		// ��ӡ����
		printf("\n%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].address);

	}
}



/**********************************************************************
* ��������	ModifyContact
* ������		ͨѶ¼�ṹ��ָ��
* �������ͣ�	void
* ���ܣ�		�޸�ָ������ϵ��
**********************************************************************/

void ModifyContact(struct contact_structure* ps)
{
	char modify_name[30];
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", modify_name);

	int pos = FindByName(ps, modify_name);
	if (pos == -1)
	{
		printf("\nҪ�޸ĵ��˲�����\n\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", ps->data[pos].name);
		printf("����������:>");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�:>");
		scanf("%s", ps->data[pos].sex);
		printf("������绰:>");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ:>");
		scanf("%s", ps->data[pos].address);

		printf("\n�޸����!\n\n");
	}
}



/*
	 *   �ȽϺ���
	 *
	 *ǰ�ߴ��ں��߷��� >0 ����
	 *ǰ�ߵ��ں��߷��� =0 ����
	 *ǰ��С�ں��߷��� <0 ����
*/

// �Ƚ�����
static int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct contact_structure*)e1)->data->name, ((struct contact_structure*)e2)->data->name);
}

// �Ƚ�����
static int cmp_by_age(const void* e1, const void* e2)
{
	return ((struct contact_structure*)e1)->data->age - ((struct contact_structure*)e2)->data->age;
}

// �Ƚ��Ա�
static int cmp_by_sex(const void* e1, const void* e2)
{
	return strcmp(((struct contact_structure*)e1)->data->sex, ((struct contact_structure*)e2)->data->sex);
}

/**********************************************************************
* ��������	SortContact
* ������		ͨѶ¼�ṹ��ָ��
* �������ͣ�	void
* ���ܣ�		���򣻿ɸ������������䡢�Ա�����
**********************************************************************/

void SortContact(struct contact_structure* ps)
{
	printf("*************************************\n");
	printf("******        ����ѡ��         ******\n");
	printf("******11. ����           12. ����******\n");
	printf("******         13. �Ա�         ******\n");
	printf("*************************************\n");

	int single_data_size = sizeof(ps->data[0]); //ÿ��Ԫ�ش�С


	int sort_option = 0;
	printf("����������ѡ��:>");
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
		printf("��������");
		break;
	}

	printf("\n����ɹ�!\n\n");

}



/**********************************************************************
* ��������	DestoryContact
* ������		ͨѶ¼�ṹ��ָ��
* �������ͣ�	void
* ���ܣ�		����ͨѶ¼�ж�̬���ٵ��ڴ�
**********************************************************************/

void DestoryContact(struct contact_structure* ps)
{
	free(ps->data);
	ps->data = NULL;
}



/**********************************************************************
* ��������	SaveContact
* ������		ͨѶ¼�ṹ��ָ��
* �������ͣ�	void
* ���ܣ�		���浱ǰ��ͨѶ¼
**********************************************************************/

void SaveContact(struct contact_structure* ps)
{
	FILE* pfWrite = fopen("contact.txt", "w"); // ÿ�����´򿪳����ȰѾɵ����ݼ��ص���ʼ���������д���ݵ�ʱ���Ѿ��ļ�������ɾ����
	if (pfWrite != NULL)
	{
		// ����д���ļ�
		for (size_t i = 0; i < ps->size; i++)
		{
			fwrite(&(ps->data[i]), sizeof(struct people_info), 1, pfWrite);
		}
		fclose(pfWrite);
		pfWrite = NULL;

		printf("\n����ɹ�\n\n");
	}
	else
	{
		printf("\nSaveContact:%s\n", strerror(errno));
		return;
	}

}



/**********************************************************************
* ��������	LoadContact
* ������		ͨѶ¼�ṹ��ָ��
* �������ͣ�	void
* ���ܣ�		��֮ǰ�����ͨѶ¼�мۼ�����Ϣ
**********************************************************************/

void LoadContact(struct contact_structure* ps)
{
	struct people_info tmp = { 0 };
	FILE* pfRead = fopen("contact.txt", "r");
	if (pfRead != NULL)
	{
		// ������
		while (fread(&tmp, sizeof(struct people_info), 1, pfRead)) // ÿ�ζ�һ����fread() �����������ݻ᷵�� 0 
		{
			CheckCapacity(ps); // ��������Ƿ񹻷ţ��������ݣ���ֹ����ͨѶ¼���� 5 ����Ϣ��ͨѶ¼��ʼֻ�� 3 ��λ��
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
