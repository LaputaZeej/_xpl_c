//
// Created by 项鹏乐 on 2022/12/13.
//

#include "../collections/x_Tree.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char menu(void);

void add_pet(XTree *pt);

void drop_pet(XTree *pt);

void show_pet(const XTree *pt);

void find_pet(const XTree *pt);

void print_item(XItem item);

void uppercase(char *str);

extern char *s_gets(char *st, int n);


static void case01() {
    printf("case01 start...\n");
    XTree pets;
    char choice;
    XTreeInitialize(&pets);
    while ((choice = menu()) != 'q') {
        switch (choice) {
            case 'a':
                add_pet(&pets);
                break;
            case 'l':
                show_pet(&pets);
                break;
            case 'f':
                find_pet(&pets);
                break;
            case 'n':
                printf("一共%d\n", XTreeCount(&pets));
                break;
            case 'd':
                drop_pet(&pets);
                break;
            default:
                puts("选择错误");
        }
    }
    XTreeUnInitialize(&pets);
    printf("case01 end!\n");
}

int main() {
    case01();
    return 0;
}


char menu(void) {
    int ch;
    puts(" ***************** 欢迎 *****************");
    puts(" **************** 请选择 *****************");
    puts(" *****(a)添加     (l)查看列表 ************");
    puts(" *****(n)查看数量  (f)查找 ***************");
    puts(" *****(d)删除     (q)退出 ***************");
    while ((ch = getchar()) != EOF) {
        //printf("ch=%d\n", ch);
        while (getchar() != '\n')
            continue;
        ch = tolower(ch);
        //printf("2ch=%d\n", ch);
        if (strchr("alrfndq", ch) == NULL) {
            puts("只能输入 a l f n d q");
        } else {
            break;
        }
    }
    if (ch == EOF) {
        ch = 'q';
    }
    return (char) ch;
}

void add_pet(XTree *pt) {
    XItem temp;
    if (XTreeIsFull(pt)) {
        puts("满了");
    } else {
        puts("输入宠物名字>:");
        s_gets(temp.pet_name, SLEN);
        puts("输入宠物种类>:");
        s_gets(temp.pet_kind, SLEN);
        uppercase(temp.pet_kind);
        uppercase(temp.pet_name);
        XTreeAdd(pt, &temp);
    }
}

void drop_pet(XTree *pt) {
    XItem temp;
    if (XTreeIsEmpty(pt)) {
        puts("没有数据");
        return;
    }
    puts("输入宠物名字>:");
    s_gets(temp.pet_name, SLEN);
    puts("输入宠物种类>:");
    s_gets(temp.pet_kind, SLEN);
    uppercase(temp.pet_kind);
    uppercase(temp.pet_name);
    printf("删除 %s %s", temp.pet_name, temp.pet_kind);
    if (XTreeDelete(pt, &temp)) {
        puts("删除成功！");
    } else {
        puts("删除失败！");
    }
}

void show_pet(const XTree *pt) {
    if (XTreeIsEmpty(pt)) {
        puts("没有数据");
    } else {
        XTreeTraverse(pt, print_item);
    }
}

void find_pet(const XTree *pt) {
    XItem temp;
    if (XTreeIsEmpty(pt)) {
        puts("没有数据");
        return;
    }
    puts("输入宠物名字>:");
    s_gets(temp.pet_name, SLEN);
    puts("输入宠物种类>:");
    s_gets(temp.pet_kind, SLEN);
    uppercase(temp.pet_kind);
    uppercase(temp.pet_name);
    printf("查找 %s %s", temp.pet_name, temp.pet_kind);
    if (XTreeInTree(pt, &temp)) {
        printf("在！！！\n");
    } else {
        printf("不在！！！\n");
    }
}

void print_item(XItem item) {
    printf("Pet：%-19s Kind:%-19s \n", item.pet_name, item.pet_kind);
}

void uppercase(char *str) {
    while (*str) {
        *str = (char) toupper(*str);
        str++;
    }
}

