#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// ����ͨѶ¼�ṹ��
typedef struct {
    char name[50];
    char gender[10];
    char phone[20];
    char city[50];
    int zipCode;
} Contact;

// ����˳���ṹ��
typedef struct {
    Contact* data;
    int length;
    int maxSize;
} SeqList;

// ��������
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
        // ��ʾ�˵�
        Menu();
        printf("��ѡ�������");
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
            printf("���˳�ϵͳ\n");
            break;
        default:
            printf("��Ч��ѡ������������\n");
        }
    } while (choice);

    free(contactList.data);//�� C �����У�free ��һ����׼�⺯�����书�����ͷ�֮ǰͨ����̬�ڴ���亯�������� malloc��calloc �� realloc �ȣ���������ڴ�ռ䡣
    //����������Ҫʹ����Щ��̬������ڴ�ʱ����Ӧ�õ��� free �������黹�ڴ������ϵͳ����������ڴ�й©�����ڴ汻ռ�õ��޷��ٱ���Ч���õ��������

    return 0;
}

// ��ʼ��˳���
//�β���˳���ṹ��ָ������
void initSeqList(SeqList* list) {
    list->maxSize = 100;  // ��ʼ�趨˳����������Ϊ100
    list->data = (Contact*)malloc(list->maxSize * sizeof(Contact));
    if (list->data == NULL) {
        printf("�ڴ����ʧ�ܣ�\n");
        //��ʹ��exit(1)ʱ������ʾ������һ�ַ����״̬�루������ 1���˳���ͨ������£�״̬�� 0 ��ʾ��������������������״̬���ʾ���������ĳ�ִ�������쳣�����
        exit(1);
    }
    list->length = 0;
}

// ����ͨѶ¼��������ϵ����Ϣ���洢��˳�����
void createContacts(SeqList* list) {
    int num;
    printf("������Ҫ��ӵ���ϵ��������");
    scanf("%d", &num);

    if (list->length + num > list->maxSize) {
        printf("˳���ռ䲻�㣬�޷������ô����ϵ�ˣ�����ɾ��������ϵ�˻�����˳���������\n");
        return;
    }

    for (int i = 0; i < num; i++) {
        printf("����� %d ����ϵ�˵�������", i + 1);
        //α��������ǡ�����ڴ�����ͨ�������������ʽ�洢
        //������������data[i]�����ı��ʽ������data��ָ�룩�����ᰴ��*(data + i)�ķ�ʽ���д���
        scanf("%s", list->data[list->length].name);
        printf("�����Ա�");
        scanf("%s", list->data[list->length].gender);
        printf("����绰��");
        scanf("%s", list->data[list->length].phone);
        printf("������У�");
        scanf("%s", list->data[list->length].city);
        printf("�����ʱࣺ");
        scanf("%d", &list->data[list->length].zipCode);
        list->length++;
    }
}

// ��������ϵ�˵�˳�����
void insertContact(SeqList* list) {
    if (list->length >= list->maxSize) {
        printf("˳����������޷���������ϵ�ˡ�\n");
        return;
    }

    printf("��������ϵ�˵�������");
    scanf("%s", list->data[list->length].name);
    printf("�����Ա�");
    scanf("%s", list->data[list->length].gender);
    printf("����绰��");
    scanf("%s", list->data[list->length].phone);
    printf("������У�");
    scanf("%s", list->data[list->length].city);
    printf("�����ʱࣺ");
    scanf("%d", &list->data[list->length].zipCode);
    list->length++;
    printf("��������ϵ�˳ɹ���\n");
}
// ��ѯ��ϵ�ˣ��ɰ��������绰����в�ѯ
//ָ��������->    �ṹ�������ã�.
void searchContacts(SeqList list) {
    int searchChoice;
    char searchKey[50];

    printf("\n��ѯ��ʽѡ��\n");
    printf("1. ��������ѯ\n");
    printf("2. ���绰��ѯ\n");
    printf("3. �����в�ѯ\n");
    printf("��ѡ���ѯ��ʽ��");
    scanf("%d", &searchChoice);

    printf("�������ѯ�ؼ��֣�");
    scanf("%s", searchKey);

    switch (searchChoice) {
    case 1:
        for (int i = 0; i < list.length; i++) {
            if (strcmp(list.data[i].name, searchKey) == 0) {
                printf("������%s\n", list.data[i].name);
                printf("�Ա�%s\n", list.data[i].gender);
                printf("�绰��%s\n", list.data[i].phone);
                printf("���У�%s\n", list.data[i].city);
                printf("�ʱࣺ%d\n", list.data[i].zipCode);
                return;
            }
        }
        break;
    case 2:
        for (int i = 0; i < list.length; i++) {
            if (strcmp(list.data[i].phone, searchKey) == 0) {
                printf("������%s\n", list.data[i].name);
                printf("�Ա�%s\n", list.data[i].gender);
                printf("�绰��%s\n", list.data[i].phone);
                printf("���У�%s\n", list.data[i].city);
                printf("�ʱࣺ%d\n", list.data[i].zipCode);
                return;
            }
        }
        break;
    case 3:
        for (int i = 0; i < list.length; i++) {
            if (strcmp(list.data[i].city, searchKey) == 0) {
                printf("������%s\n", list.data[i].name);
                printf("�Ա�%s\n", list.data[i].gender);
                printf("�绰��%s\n", list.data[i].phone);
                printf("���У�%s\n", list.data[i].city);
                printf("�ʱࣺ%d\n", list.data[i].zipCode);
                return;
            }
        }
        break;
    }

    printf("δ�ҵ�ƥ�����ϵ����Ϣ��\n");
}


// ɾ����ϵ�ˣ��ɰ�������绰ɾ��
void deleteContact(SeqList* list) {
    int deleteChoice;
    char deleteKey[50];

    printf("\nɾ����ʽѡ��\n");
    printf("1. ������ɾ��\n");
    printf("2. �ɵ绰ɾ��\n");
    printf("��ѡ��ɾ����ʽ��");
    scanf("%d", &deleteChoice);

    printf("������ɾ���ؼ��֣�");
    scanf("%s", deleteKey);

    switch (deleteChoice) {
    case 1:
        for (int i = 0; i < list->length; i++) {
            if (strcmp(list->data[i].name, deleteKey) == 0) {
                for (int j = i; j < list->length - 1; j++) {
                    list->data[j] = list->data[j + 1];
                }
                list->length--;
                printf("ɾ����ϵ�˳ɹ���\n");
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
                printf("ɾ����ϵ�˳ɹ���\n");
                return;
            }
        }
        break;
    }

    printf("δ�ҵ�Ҫɾ������ϵ�ˡ�\n");
}

// �޸���ϵ����Ϣ���ɰ�������绰�޸�
void modifyContact(SeqList* list) {
    int modifyChoice;
    char modifyKey[50];

    printf("\n�޸ķ�ʽѡ��\n");
    printf("1. �������޸�\n");
    printf("2. ���绰�޸�\n");
    printf("��ѡ���޸ķ�ʽ��");
    scanf("%d", &modifyChoice);

    printf("�������޸Ĺؼ��֣�");
    scanf("%s", modifyKey);

    switch (modifyChoice) {
    case 1:
        for (int i = 0; i < list->length; i++) {
            if (strcmp(list->data[i].name, modifyKey) == 0) {
                printf("�����µ��Ա�");
                scanf("%s", list->data[i].gender);
                printf("�����µĵ绰��");
                scanf("%s", list->data[i].phone);
                printf("�����µĳ��У�");
                scanf("%s", list->data[i].city);
                printf("�����µ��ʱࣺ");
                scanf("%d", &list->data[i].zipCode);
                printf("�޸���ϵ����Ϣ�ɹ���\n");
                return;
            }
        }
        break;
    case 2:
        for (int i = 0; i < list->length; i++) {
            if (strcmp(list->data[i].phone, modifyKey) == 0) {
                printf("�����µ��Ա�");
                scanf("%s", list->data[i].gender);
                printf("�����µĵ绰��");
                scanf("%s", list->data[i].phone);
                printf("�����µĳ��У�");
                scanf("%s", list->data[i].city);
                printf("�����µ��ʱࣺ");
                scanf("%d", &list->data[i].zipCode);
                printf("�޸���ϵ����Ϣ�ɹ���\n");
                return;
            }
        }
        break;
    }

    printf("δ�ҵ�Ҫ�޸ĵ���ϵ�ˡ�\n");
}

// ��ʾ������ϵ����Ϣ
void displayContacts(SeqList list) {
    for (int i = 0; i < list.length; i++) {
        printf("������%s\n", list.data[i].name);
        printf("�Ա�%s\n", list.data[i].gender);
        printf("�绰��%s\n", list.data[i].phone);
        printf("���У�%s\n", list.data[i].city);
        printf("�ʱࣺ%d\n", list.data[i].zipCode);
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
    printf("\t\t\t*  ѧ�ţ�20236832    ���������Ӻ�    *\n");
    printf("\t\t\t*  ѧ�ţ�20235086   ��������Դ��     *\n");
    printf("\t\t\t*             ��2305-1               *\n");
    printf("\t\t\t*       ѧ��ͨѶ¼����ϵͳ           *\n");
    printf("\t\t\t*                                    *\n");
    printf("\t\t\t*                                    *\n");
    printf("\t\t\t*        [1]����ͨѶ¼               *\n");
    printf("\t\t\t*        [2]��ѯ��ϵ��               *\n");
    printf("\t\t\t*        [3]��������ϵ��             *\n");
    printf("\t\t\t*        [4]ɾ����ϵ��               *\n");
    printf("\t\t\t*        [5]�޸���ϵ����Ϣ           *\n");
    printf("\t\t\t*        [6]��ʾ������ϵ��           *\n");
    printf("\t\t\t*        [0]�˳�                     *\n");
    printf("\t\t\t*                                    *\n");
    printf("\t\t\t**************************************\n");
    printf("��ѡ��\n");
}