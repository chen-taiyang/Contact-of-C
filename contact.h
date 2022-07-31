#pragma once

#ifndef __CONTACT_H__
#define __CONTACT_H__

// ͷ�ļ�
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#pragma warning(disable : 4996)

// ����ѡ��
enum option
{
	exit_option,	// 0
	add,	// 1
	del,
	search,
	modify,
	show,
	sort,
	save
};

// ����ѡ��
enum SortOption
{
	sort_by_name = 11,
	sort_by_age,
	sort_by_sex
};


// ͨѶ¼Ĭ�ϴ�С��ÿ�����ӵĴ�С
#define default_size 3
#define increase_size 3

// ͨѶ¼����Ϣ�ṹ
struct people_info
{
	char name[30];
	int age;
	char sex[5];
	char tele[12];
	char address[100];
};

// ͨѶ¼�ṹ
struct contact_structure
{
	struct people_info* data;
	int size; // ��¼��ǰͨѶ¼Ԫ�ظ���
	int capacity; // ��ǰͨѶ¼���������
};


// ��������
void InitContact(struct contact_structure* ps);
void AddContact(struct contact_structure* ps);
void ShowContact(const struct contact_structure* ps);
void DelContact(struct contact_structure* ps);
void SearchContact(const struct contact_structure* ps);
void ModifyContact(struct contact_structure* ps);
void SortContact(struct contact_structure* ps);
void DestoryContact(struct contact_structure* ps);
void SaveContact(struct contact_structure* ps);
void LoadContact(struct contact_structure* ps);

#endif // !__CONTACT_H__
