# define _CRT_SECURE_NO_WARNINGS

# include "contact.h"

/**********************************ͨѶ¼*********************************************
* 1. ���1000��������Ϣ���������绰���Ա�סַ�����䣩
* 2. ���Ӻ�����Ϣ
* 3. ɾ��ָ������������Ϣ
* 4. ���Һ�����Ϣ
* 5. �޸ĺ�����Ϣ
* 6. ��ӡ������Ϣ
* 7. ����
* 8. ���ļ���ʽ���棬��һ�����г���ᱨ��LoadContact:No Such File or Directory
* ֮��ÿ�����г���ʱ���ȴ��ı��м���ͨѶ¼����Ϣ�洢�� tmp �У�Ȼ�� tmp �������
* ͬ���� data �У�֮�󱣴�ʱ�� "w" ��ʽ���contact.txt�����Ϣȫ��ɾ������д�룬
* �Ӷ�ʵ���ı���ͨѶ¼��Ϣ�ĸ���
**************************************************************************************/


void menu()
{
	printf("*************************************\n");
	printf("******1. ����           2. ɾ��******\n");
	printf("******3. ����           4. �޸�******\n");
	printf("******5. չʾ           6. ����******\n");
	printf("******7. ����           0. exit******\n");
	printf("*************************************\n");
}

int main()
{
	// ����ͨѶ¼
	struct contact_structure contact; //contact����ͨѶ¼�������У�dataָ�롢size��capacity


	// ��ʼ��ͨѶ¼
	InitContact(&contact);


	int input = 0;

	do
	{
		menu();
		printf("��ѡ��>");
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
			// ����
			SaveContact(&contact);
			// ���ٶ�̬���ٵ�ͨѶ¼�ڴ�
			DestoryContact(&contact);
			printf("�˳��ɹ�\n");
			break;

		default:
			printf("ѡ�����\n");
			break;
		}

	} while (input);

	return 0;
}