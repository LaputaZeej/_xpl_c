cmake_minimum_required(VERSION 3.21)
project(_xpl_c C)

set(CMAKE_C_STANDARD 99)

add_executable(_xpl_c
        x_swap.h
        x_swap.c
        game/Three.c
        game/Three.h
        saolei/SaoLei.c
        saolei/SaoLei.h
        Utils.c Utils.h
        #        game/ThreeGame.c
        #        saolei/SaoLeiGame.c
        #        main.c
        #        s10_28.c
        #        s10_28_01.c
        #        s11_07.c
        #        s11_09.c
        #        s11_15.c
        #        s11_17.c   #
        #        s11_18.c    # .. 36 37 38 （测试sizeof strlen）39 ..
        #        s11_21.c    # 40 41
        #        s11_22.c    # 42 43 44 45 46 47
        #        s11_22_01.c # 48 49 50 string 51 52
        #        s11_23.c    # 53
        #        s11_23_01.c # 54 55 56 57 58 59 ..63 64
        #        s11_24.c # 65 66 67 68 69
        #        s11_24_01.c #70 71 72 73 74 75
        #        s11_25.c #76 77 78 // 79 80 81
#        cprimerplus/chapter_01.c
#        cprimerplus/chapter_05.c
#        cprimerplus/s11_30.c
#        cprimerplus/s12_01.c   cprimerplus/laputa.c

#        cprimerplus/s12_05.c cprimerplus/laputa.h cprimerplus/laputa_1.c
        collections/ArrayList.h collections/ArrayList.c
#        cprimerplus/s12_05_01.c
#        cprimerplus/s12_06.c
#        cprimerplus/s12_07.c
#        cprimerplus/s12_07_01.c cprimerplus/generic_demo.c
#        cprimerplus/s12_08.c
#        cprimerplus/s12_08_1.c  collections/LinkedFilm.c collections/LinkedFilm.h
        cprimerplus/Strings.c
        collections/LinkedList.h
#        cprimerplus/s12_12.c
#        collections/LinkedList.c collections/x_Queue.c collections/x_Queue.h
        cprimerplus/s12_13.c collections/x_Tree.c collections/x_Tree.h)
