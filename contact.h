#pragma once

#ifndef __CONTACT_H__
#define __CONTACT_H__

// 头文件
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#pragma warning(disable : 4996)

// 功能选项
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

// 排序选项
enum SortOption
{
	sort_by_name = 11,
	sort_by_age,
	sort_by_sex
};


// 通讯录默认大小、每次增加的大小
#define default_size 3
#define increase_size 3

// 通讯录里信息结构
struct people_info
{
	char name[30];
	int age;
	char sex[5];
	char tele[12];
	char address[100];
};

// 通讯录结构
struct contact_structure
{
	struct people_info* data;
	int size; // 记录当前通讯录元素个数
	int capacity; // 当前通讯录的最大容量
};


// 声明函数
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
