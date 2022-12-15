//
// Created by 项鹏乐 on 2022/12/8.
//

#define TSIZE 45
#define FMAX 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct film {
    char title[TSIZE]; // 片名
    int rating;         // 评级
};

extern char *s_gets(char str[], int lim);

void case01() {
    struct film movies[FMAX];
    int i = 0;
    int j;
    puts("输入片名:>");
    while (i < FMAX && s_gets(movies[i].title, TSIZE) != NULL && movies[i].title[0] != '\0') {
        puts("输入评级（0-10）:>");
        scanf("%d", &movies[i++].rating);
        while (getchar() != '\n') {
            continue;
        }
        puts("输入下一个片名,空结束:>");
    }
    if (i == 0) {
        printf("没有输入");
    } else {
        printf("输入内容：\n");
    }
    for (j = 0; j < i; j++) {
        printf("电影 片名：%s 评级：%d\n", movies[j].title, movies[j].rating);
    }
    printf("结束");
}

struct film_linked {
    char title[TSIZE];
    int rating;
    struct film_linked *next;
};

typedef struct film_linked FILM;


void case02() {

    FILM *head = NULL;
    struct film_linked *prev, *current;

    char input[TSIZE];
    puts("输入片名>:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0') {
        current = (FILM *) malloc(sizeof(FILM));
        if (head == NULL) {
            head = current;
        } else {
            prev->next = current;
        }
        current->next = NULL;
        strcpy(current->title, input);
        puts("输入评级（0-10）:>");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;
        puts("输入下一个片名,空结束:>");
        prev = current;
    }

    if (head == NULL) {
        printf("没有输入");
    } else {
        printf("输入内容：\n");
    }

    current = head;
    while (current != NULL) {
        printf("电影 片名：%s 评级：%d\n", current->title, current->rating);
        current = current->next;
    }

    current = head;
    while (current != NULL) {
        current = head;
        head = current->next;
        free(current);
    }
    printf("end..... \n");
}

#include "../collections/LinkedFilm.h"

void showmovies(Item item) {
    printf("电影 片名：%s 评级：%d\n", item.title, item.rating);
}

void case03() {
    LikedList moves;
    Item temp;
    // 初始化
    LinkedInitialize(&moves);
    if (LinkedListIsFull(&moves)) {
        fprintf(stderr, "列表已满\n");
        exit(1);
    }
    // 获取用户输入并存储
    puts("请输入标题>:");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0') {
        puts("输入评级（0-10）>:");
        scanf("%d", &(temp.rating));
        while (getchar() != '\n')
            continue;
        if (LinkedListAdd(temp, &moves) == false) {
            fprintf(stderr, "添加失败\n");
            break;
        }
        if (LinkedListIsFull(&moves)) {
            puts("列表已满！\n");
            break;
        }
        puts("继续输入标题,输入空结束>:");
    }

    if (LinkedListIsEmpty(&moves)) {
        printf("没有数据\n");
    } else {
        printf("数据展示：\n");
        LinkedListTraverse(&moves, showmovies);
    }
    printf("你输入了%d个电影\n", LinkedListCount(&moves));

    // 清理
    LinkedListClear(&moves);
    printf("再见");

}

void case04() {
    LikedList moves ;
    Item item;
    LinkedInitialize(&moves);
    for (int i = 0; i < 10; ++i) {
        sprintf(item.title,"名称->%d",i);
        item.rating = i%10;
        LinkedListAdd(item,&moves);
    }
    if (LinkedListIsEmpty(&moves)){
        printf("没有数据\n");
    }else{
        printf("数据暂时：\n");
        LinkedListTraverse(&moves,showmovies);
    }
    printf("数量：%d\n", LinkedListCount(&moves));
    LinkedListClear(&moves);
    printf("bye\n");

}

int main() {
    case04();
    case03();
//    case02();

//    case01();

    return 0;
}
