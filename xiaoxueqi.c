#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// 定义通讯录结构体
typedef struct {
    char name[50];
    char gender[10];
    char phone[20];
    char city[50];
    int zipCode;
} Contact;

// 定义顺序表结构体
typedef struct {
    Contact* data;
    int length;
    int maxSize;
} SeqList;

// 函数声明
void initSeqList(SeqList* list);
void createContacts(SeqList* list);
void searchContacts(SeqList list);
void insertContact(SeqList* list);
void deleteContact(SeqList* list);
void modifyContact(SeqList* list);
void displayContacts(SeqList list);
void Menu();

int main() {
    SeqList contactList;
    initSeqList(&contactList);

    int choice;
    do {
        // 显示菜单
        Menu();
        printf("请选择操作：");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            createContacts(&contactList);
            break;
        case 2:
            searchContacts(contactList);
            break;
        case 3:
            insertContact(&contactList);
            break;
        case 4:
            deleteContact(&contactList);
            break;
        case 5:
            modifyContact(&contactList);
            break;
        case 6:
            displayContacts(contactList);
            break;
        case 0:
            printf("已退出系统\n");
            break;
        default:
            printf("无效的选择，请重新输入\n");
        }
    } while (choice);

    free(contactList.data);//在 C 语言中，free 是一个标准库函数，其功能是释放之前通过动态内存分配函数（比如 malloc、calloc 或 realloc 等）所分配的内存空间。
    //当程序不再需要使用这些动态分配的内存时，就应该调用 free 函数来归还内存给操作系统，避免造成内存泄漏（即内存被占用但无法再被有效利用的情况）。

    return 0;
}

// 初始化顺序表
//形参是顺序表结构体指针类型
void initSeqList(SeqList* list) {
    list->maxSize = 100;  // 初始设定顺序表最大容量为100
    list->data = (Contact*)malloc(list->maxSize * sizeof(Contact));
    if (list->data == NULL) {
        printf("内存分配失败！\n");
        //当使用exit(1)时，它表示程序以一种非零的状态码（这里是 1）退出。通常情况下，状态码 0 表示程序正常结束，而非零状态码表示程序出现了某种错误或者异常情况。
        exit(1);
    }
    list->length = 0;
}

// 创建通讯录，输入联系人信息并存储到顺序表中
void createContacts(SeqList* list) {
    int num;
    printf("请输入要添加的联系人数量：");
    scanf("%d", &num);

    if (list->length + num > list->maxSize) {
        printf("顺序表空间不足，无法添加这么多联系人，请先删除部分联系人或扩大顺序表容量。\n");
        return;
    }

    for (int i = 0; i < num; i++) {
        printf("输入第 %d 个联系人的姓名：", i + 1);
        //伪数组分配好恰当的内存后可以通过类似数组的形式存储
        //当编译器遇到data[i]这样的表达式（其中data是指针），它会按照*(data + i)的方式进行处理。
        scanf("%s", list->data[list->length].name);
        printf("输入性别：");
        scanf("%s", list->data[list->length].gender);
        printf("输入电话：");
        scanf("%s", list->data[list->length].phone);
        printf("输入城市：");
        scanf("%s", list->data[list->length].city);
        printf("输入邮编：");
        scanf("%d", &list->data[list->length].zipCode);
        list->length++;
    }
}

// 插入新联系人到顺序表中
void insertContact(SeqList* list) {
    if (list->length >= list->maxSize) {
        printf("顺序表已满，无法插入新联系人。\n");
        return;
    }

    printf("输入新联系人的姓名：");
    scanf("%s", list->data[list->length].name);
    printf("输入性别：");
    scanf("%s", list->data[list->length].gender);
    printf("输入电话：");
    scanf("%s", list->data[list->length].phone);
    printf("输入城市：");
    scanf("%s", list->data[list->length].city);
    printf("输入邮编：");
    scanf("%d", &list->data[list->length].zipCode);
    list->length++;
    printf("插入新联系人成功。\n");
}
// 查询联系人，可按姓名、电话或城市查询
//指针类型用->    结构体类型用：.
void searchContacts(SeqList list) {
    int searchChoice;
    char searchKey[50];

    printf("\n查询方式选择：\n");
    printf("1. 按姓名查询\n");
    printf("2. 按电话查询\n");
    printf("3. 按城市查询\n");
    printf("请选择查询方式：");
    scanf("%d", &searchChoice);

    printf("请输入查询关键字：");
    scanf("%s", searchKey);

    switch (searchChoice) {
    case 1:
        for (int i = 0; i < list.length; i++) {
            if (strcmp(list.data[i].name, searchKey) == 0) {
                printf("姓名：%s\n", list.data[i].name);
                printf("性别：%s\n", list.data[i].gender);
                printf("电话：%s\n", list.data[i].phone);
                printf("城市：%s\n", list.data[i].city);
                printf("邮编：%d\n", list.data[i].zipCode);
                return;
            }
        }
        break;
    case 2:
        for (int i = 0; i < list.length; i++) {
            if (strcmp(list.data[i].phone, searchKey) == 0) {
                printf("姓名：%s\n", list.data[i].name);
                printf("性别：%s\n", list.data[i].gender);
                printf("电话：%s\n", list.data[i].phone);
                printf("城市：%s\n", list.data[i].city);
                printf("邮编：%d\n", list.data[i].zipCode);
                return;
            }
        }
        break;
    case 3:
        for (int i = 0; i < list.length; i++) {
            if (strcmp(list.data[i].city, searchKey) == 0) {
                printf("姓名：%s\n", list.data[i].name);
                printf("性别：%s\n", list.data[i].gender);
                printf("电话：%s\n", list.data[i].phone);
                printf("城市：%s\n", list.data[i].city);
                printf("邮编：%d\n", list.data[i].zipCode);
                return;
            }
        }
        break;
    }

    printf("未找到匹配的联系人信息。\n");
}


// 删除联系人，可按姓名或电话删除
void deleteContact(SeqList* list) {
    int deleteChoice;
    char deleteKey[50];

    printf("\n删除方式选择：\n");
    printf("1. 按姓名删除\n");
    printf("2. 由电话删除\n");
    printf("请选择删除方式：");
    scanf("%d", &deleteChoice);

    printf("请输入删除关键字：");
    scanf("%s", deleteKey);

    switch (deleteChoice) {
    case 1:
        for (int i = 0; i < list->length; i++) {
            if (strcmp(list->data[i].name, deleteKey) == 0) {
                for (int j = i; j < list->length - 1; j++) {
                    list->data[j] = list->data[j + 1];
                }
                list->length--;
                printf("删除联系人成功。\n");
                return;
            }
        }
        break;
    case 2:
        for (int i = 0; i < list->length; i++) {
            if (strcmp(list->data[i].phone, deleteKey) == 0) {
                for (int j = i; j < list->length - 1; j++) {
                    list->data[j] = list->data[j + 1];
                }
                list->length--;
                printf("删除联系人成功。\n");
                return;
            }
        }
        break;
    }

    printf("未找到要删除的联系人。\n");
}

// 修改联系人信息，可按姓名或电话修改
void modifyContact(SeqList* list) {
    int modifyChoice;
    char modifyKey[50];

    printf("\n修改方式选择：\n");
    printf("1. 按姓名修改\n");
    printf("2. 按电话修改\n");
    printf("请选择修改方式：");
    scanf("%d", &modifyChoice);

    printf("请输入修改关键字：");
    scanf("%s", modifyKey);

    switch (modifyChoice) {
    case 1:
        for (int i = 0; i < list->length; i++) {
            if (strcmp(list->data[i].name, modifyKey) == 0) {
                printf("输入新的性别：");
                scanf("%s", list->data[i].gender);
                printf("输入新的电话：");
                scanf("%s", list->data[i].phone);
                printf("输入新的城市：");
                scanf("%s", list->data[i].city);
                printf("输入新的邮编：");
                scanf("%d", &list->data[i].zipCode);
                printf("修改联系人信息成功。\n");
                return;
            }
        }
        break;
    case 2:
        for (int i = 0; i < list->length; i++) {
            if (strcmp(list->data[i].phone, modifyKey) == 0) {
                printf("输入新的性别：");
                scanf("%s", list->data[i].gender);
                printf("输入新的电话：");
                scanf("%s", list->data[i].phone);
                printf("输入新的城市：");
                scanf("%s", list->data[i].city);
                printf("输入新的邮编：");
                scanf("%d", &list->data[i].zipCode);
                printf("修改联系人信息成功。\n");
                return;
            }
        }
        break;
    }

    printf("未找到要修改的联系人。\n");
}

// 显示所有联系人信息
void displayContacts(SeqList list) {
    for (int i = 0; i < list.length; i++) {
        printf("姓名：%s\n", list.data[i].name);
        printf("性别：%s\n", list.data[i].gender);
        printf("电话：%s\n", list.data[i].phone);
        printf("城市：%s\n", list.data[i].city);
        printf("邮编：%d\n", list.data[i].zipCode);
        printf("\n");
    }
}
void Menu()
{
    printf("\n");
    system("pause");
    system("cls");
    printf("\n");
    printf("\t\t\t**************************************\n");
    printf("\t\t\t*                                    *\n");
    printf("\t\t\t*  学号：20236832    姓名：银子豪    *\n");
    printf("\t\t\t*  学号：20235086   姓名：刘源泽     *\n");
    printf("\t\t\t*             方2305-1               *\n");
    printf("\t\t\t*       学生通讯录管理系统           *\n");
    printf("\t\t\t*                                    *\n");
    printf("\t\t\t*                                    *\n");
    printf("\t\t\t*        [1]创建通讯录               *\n");
    printf("\t\t\t*        [2]查询联系人               *\n");
    printf("\t\t\t*        [3]插入新联系人             *\n");
    printf("\t\t\t*        [4]删除联系人               *\n");
    printf("\t\t\t*        [5]修改联系人信息           *\n");
    printf("\t\t\t*        [6]显示所有联系人           *\n");
    printf("\t\t\t*        [0]退出                     *\n");
    printf("\t\t\t*                                    *\n");
    printf("\t\t\t**************************************\n");
    printf("请选择：\n");
}