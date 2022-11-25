//
// Created by 项鹏乐 on 2022/10/28.
//

//void x_swap(int *a, int *b) {
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}

void x_swap(int *a, int *b) {
    *a = (*a) ^ (*b);
    *b = (*a) ^ (*b);
    *a = (*a) ^ (*b);
}


// 溢出
//void x_swap(int *a, int *b) {
//    *a=(*a)+(*b);
//    *b = (*a)-(*b);
//    *a=(*a)-(*b);
//}