void mouseButton(int button, int state, int x, int y)
{

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        printf("%d, %d", x, y);
        if (x >= 365 && x <= 385 && y <= 132 && y >= 116 && how_many_peshka < 8)
        {
            figure_cod = 1;
            how_many_peshka++;
            if (how_many_peshka == 8) Display();
        }
        if (x >= 365 && x <= 385 && y <= 165 && y >= 150 && how_many_ladia < 2)
        {
            figure_cod = 5;
            how_many_ladia++;
            if (how_many_ladia == 2) Display();
        }
        if (x >= 365 && x <= 385 && y <= 201 && y >= 170 && how_many_ferz < 1)
        {
            figure_cod = 2;
            how_many_ferz++;
            if (how_many_ferz == 1) Display();
        }

        if (x >= 370 && x <= 390 && y <= 235 && y >= 210 && how_many_kon < 2)
        {
            figure_cod = 3;
            how_many_kon++;
            if (how_many_kon == 2) Display();
        }
        if (x >= 370 && x <= 385 && y <= 270 && y >= 240 && how_many_slon < 2)
        {
            figure_cod = 4;
            how_many_slon++;
            if (how_many_slon == 2) Display();
        }
        if (x >= 370 && x <= 385 && y <= 312 && y >= 284 && how_many_king< 1)
        {
            figure_cod = 6;
            how_many_king++;
            if (how_many_king == 1) Display();
        }


        if (x >= 417 && x <= 437 && y <= 132 && y >= 116 && how_many_peshka1 < 8)
        {
            figure_cod = 11;
            how_many_peshka1++;
            if (how_many_peshka1 == 8) Display();
        }
        if (x >= 417 && x <= 437 && y <= 165 && y >= 150 && how_many_ladia1 < 2)
        {
            figure_cod = 51;
            how_many_ladia1++;
            if (how_many_ladia1 == 2) Display();
        }
        if (x >= 417 && x <= 437 && y <= 201 && y >= 170 && how_many_ferz1 < 1)
        {
            figure_cod = 21;
            how_many_ferz1++;
            if (how_many_ferz1 == 1) Display();
        }

        if (x >= 422 && x <= 442 && y <= 235 && y >= 210 && how_many_kon1 < 2)
        {
            figure_cod = 31;
            how_many_kon1++;
            if (how_many_kon1 == 2) Display();
        }
        if (x >= 422 && x <= 437 && y <= 270 && y >= 240 && how_many_slon1 < 2)
        {
            figure_cod = 41;
            how_many_slon1++;
            if (how_many_slon1 == 2) Display();
        }
        if (x >= 422 && x <= 437 && y <= 312 && y >= 284 && how_many_king1< 1)
        {
            figure_cod = 61;
            how_many_king1++;
            if (how_many_king1 == 1) Display();
        }

        if (x <= 55 && x >= 15 && y >= 375 && y <= 415)
        {
            A = &MY_DESK[7][0];
            i = 7;
            j = 0;
            figure_cod = MY_DESK[7][0];
            MY_DESK[7][0] = 0;
        }
        if (x <= 95 && x > 55 && y >= 375 && y <= 415)
        {
            A = &MY_DESK[7][1];
            i = 7;
            j = 1;
            figure_cod = MY_DESK[7][1];
            MY_DESK[7][1] = 0;
        }
        if (x > 95 && x <= 135 && y >= 375 && y <= 415)
        {
            A = &MY_DESK[7][2];
            i = 7;
            j = 2;
            figure_cod = MY_DESK[7][2];
            MY_DESK[7][2] = 0;
        }
        if (x > 135 && x <= 175 && y >= 375 && y <= 415)
        {
            A = &MY_DESK[7][3];
            i = 7;
            j = 3;
            figure_cod = MY_DESK[7][3];
            MY_DESK[7][3] = 0;
        }
        if (x > 175 && x <= 215 && y >= 375 && y <= 415)
        {
            A = &MY_DESK[7][4];
            i = 7;
            j = 4;
            figure_cod = MY_DESK[7][4];
            MY_DESK[7][4] = 0;
        }
        if (x > 215 && x <= 255 && y >= 375 && y <= 415)
        {
            A = &MY_DESK[7][5];
            i = 7;
            j = 5;
            figure_cod = MY_DESK[7][5];
            MY_DESK[7][5] = 0;
        }
        if (x > 255 && x <= 295 && y >= 375 && y <= 415)
        {
            A = &MY_DESK[7][6];
            i = 7;
            j = 6;
            figure_cod = MY_DESK[7][6];
            MY_DESK[7][6] = 0;
        }
        if (x > 295 && x <= 335 && y >= 375 && y <= 415)
        {
            A = &MY_DESK[7][7];
            i = 7;
            j = 7;
            figure_cod = MY_DESK[7][7];
            MY_DESK[7][7] = 0;
        }
        if (x <= 55 && x >= 15 && y >= 335 && y < 375)
        {
            A = &MY_DESK[6][0];
            i = 6;
            j = 0;
            figure_cod = MY_DESK[6][0];
            MY_DESK[6][0] = 0;
        }
        if (x <= 95 && x > 55 && y >= 335 && y < 375)
        {
            A = &MY_DESK[6][1];
            i = 6;
            j = 1;
            figure_cod = MY_DESK[6][1];
            MY_DESK[6][1] = 0;
        }
        if (x > 95 && x <= 135 && y >= 335 && y < 375)
        {
            A = &MY_DESK[6][2];
            i = 6;
            j = 2;
            figure_cod = MY_DESK[6][2];
            MY_DESK[6][2] = 0;
        }
        if (x > 135 && x <= 175 && y >= 335 && y < 375)
        {
            A = &MY_DESK[6][3];
            i = 6;
            j = 3;
            figure_cod = MY_DESK[6][3];
            MY_DESK[6][3] = 0;
        }
        if (x > 175 && x <= 215 && y >= 335 && y < 375)
        {
            A = &MY_DESK[6][4];
            i = 6;
            j = 4;
            figure_cod = MY_DESK[6][4];
            MY_DESK[6][4] = 0;
        }
        if (x > 215 && x <= 255 && y >= 335 && y < 375)
        {
            A = &MY_DESK[6][5];
            i = 6;
            j = 5;
            figure_cod = MY_DESK[6][5];
            MY_DESK[6][5] = 0;
        }
        if (x > 255 && x <= 295 && y >= 335 && y < 375)
        {
            A = &MY_DESK[6][6];
            i = 6;
            j = 6;
            figure_cod = MY_DESK[6][6];
            MY_DESK[6][6] = 0;
        }
        if (x > 295 && x <= 335 && y >= 335 && y < 375)
        {
            A = &MY_DESK[6][7];
            i = 6;
            j = 7;
            figure_cod = MY_DESK[6][7];
            MY_DESK[6][7] = 0;
        }

        if (x <= 55 && x >= 15 && y > 295 && y <= 335)
        {
            A = &MY_DESK[5][0];
            i = 5;
            j = 0;
            figure_cod = MY_DESK[5][0];
            MY_DESK[5][0] = 0;
        }
        if (x <= 95 && x > 55 && y > 295 && y <= 335)
        {
            A = &MY_DESK[5][1];
            i = 5;
            j = 1;
            figure_cod = MY_DESK[5][1];
            MY_DESK[5][1] = 0;
        }
        if (x > 95 && x <= 135 && y > 295 && y <= 335)
        {
            A = &MY_DESK[5][2];
            i = 5;
            j = 2;
            figure_cod = MY_DESK[5][2];
            MY_DESK[5][2] = 0;
        }
        if (x > 135 && x <= 175 && y > 295 && y <= 335)
        {
            A = &MY_DESK[5][3];
            i = 5;
            j = 3;
            figure_cod = MY_DESK[5][3];
            MY_DESK[5][3] = 0;
        }
        if (x > 175 && x <= 215 && y > 295 && y <= 335)
        {
            A = &MY_DESK[5][4];
            i = 5;
            j = 4;
            figure_cod = MY_DESK[5][4];
            MY_DESK[5][4] = 0;
        }
        if (x > 215 && x <= 255 && y > 295 && y <= 335)
        {
            A = &MY_DESK[5][5];
            i = 5;
            j = 5;
            figure_cod = MY_DESK[5][5];
            MY_DESK[5][5] = 0;
        }
        if (x > 255 && x <= 295 && y > 295 && y <= 335)
        {
            A = &MY_DESK[5][6];
            i = 5;
            j = 6;
            figure_cod = MY_DESK[5][6];
            MY_DESK[5][6] = 0;
        }
        if (x > 295 && x <= 335 && y > 295 && y <= 335)
        {
            A = &MY_DESK[5][7];
            i = 5;
            j = 7;
            figure_cod = MY_DESK[5][7];
            MY_DESK[5][7] = 0;
        }

        if (x <= 55 && x >= 15 && y > 255 && y <= 295)
        {
            A = &MY_DESK[4][0];
            i = 4;
            j = 0;
            figure_cod = MY_DESK[4][0];
            MY_DESK[4][0] = 0;
        }
        if (x <= 95 && x > 55 && y > 255 && y <= 295)
        {
            A = &MY_DESK[4][1];
            i = 4;
            j = 1;
            figure_cod = MY_DESK[4][1];
            MY_DESK[4][1] = 0;
        }
        if (x > 95 && x <= 135 && y > 255 && y <= 295)
        {
            A = &MY_DESK[4][2];
            i = 4;
            j = 2;
            figure_cod = MY_DESK[4][2];
            MY_DESK[4][2] = 0;
        }
        if (x > 135 && x <= 175 && y > 255 && y <= 295)
        {
            A = &MY_DESK[4][3];
            i = 4;
            j = 3;
            figure_cod = MY_DESK[4][3];
            MY_DESK[4][3] = 0;
        }
        if (x > 175 && x <= 215 && y > 255 && y <= 295)
        {
            A = &MY_DESK[4][4];
            i = 4;
            j = 4;
            figure_cod = MY_DESK[4][4];
            MY_DESK[4][4] = 0;
        }
        if (x > 215 && x <= 255 && y > 255 && y <= 295)
        {
            A = &MY_DESK[4][5];
            i = 4;
            j = 5;
            figure_cod = MY_DESK[4][5];
            MY_DESK[4][5] = 0;
        }
        if (x > 255 && x <= 295 && y > 255 && y <= 295)
        {
            A = &MY_DESK[4][6];
            i = 4;
            j = 6;
            figure_cod = MY_DESK[4][6];
            MY_DESK[4][6] = 0;
        }
        if (x > 295 && x <= 335 && y > 255 && y <= 295)
        {
            A = &MY_DESK[4][7];
            i = 4;
            j = 7;
            figure_cod = MY_DESK[4][7];
            MY_DESK[4][7] = 0;
        }

        if (x <= 55 && x >= 15 && y > 215 && y <= 255)
        {
            A = &MY_DESK[3][0];
            i = 3;
            j = 0;
            figure_cod = MY_DESK[3][0];
            MY_DESK[3][0] = 0;
        }
        if (x <= 95 && x > 55 && y > 215 && y <= 255)
        {
            A = &MY_DESK[3][1];
            i = 3;
            j = 1;
            figure_cod = MY_DESK[3][1];
            MY_DESK[3][1] = 0;
        }
        if (x > 95 && x <= 135 && y > 215 && y <= 255)
        {
            A = &MY_DESK[3][2];
            i = 3;
            j = 2;
            figure_cod = MY_DESK[3][2];
            MY_DESK[3][2] = 0;
        }
        if (x > 135 && x <= 175 && y > 215 && y <= 255)
        {
            A = &MY_DESK[3][3];
            i = 3;
            j = 3;
            figure_cod = MY_DESK[3][3];
            MY_DESK[3][3] = 0;
        }
        if (x > 175 && x <= 215 && y > 215 && y <= 255)
        {
            A = &MY_DESK[3][4];
            i = 3;
            j = 4;
            figure_cod = MY_DESK[3][4];
            MY_DESK[3][4] = 0;
        }
        if (x > 215 && x <= 255 && y > 215 && y <= 255)
        {
            A = &MY_DESK[3][5];
            i = 3;
            j = 5;
            figure_cod = MY_DESK[3][5];
            MY_DESK[3][5] = 0;
        }
        if (x > 255 && x <= 295 && y > 215 && y <= 255)
        {
            A = &MY_DESK[3][6];
            i = 3;
            j = 6;
            figure_cod = MY_DESK[3][6];
            MY_DESK[3][6] = 0;
        }
        if (x > 295 && x <= 335 && y > 215 && y <= 255)
        {
            A = &MY_DESK[3][7];
            i = 3;
            j = 7;
            figure_cod = MY_DESK[3][7];
            MY_DESK[3][7] = 0;
        }

        if (x <= 55 && x >= 15 && y > 175 && y <= 215)
        {
            A = &MY_DESK[2][0];
            i = 2;
            j = 0;
            figure_cod = MY_DESK[2][0];
            MY_DESK[2][0] = 0;
        }
        if (x <= 95 && x > 55 && y > 175 && y <= 215)
        {
            A = &MY_DESK[2][1];
            i = 2;
            j = 1;
            figure_cod = MY_DESK[2][1];
            MY_DESK[2][1] = 0;
        }
        if (x > 95 && x <= 135 && y > 175 && y <= 215)
        {
            A = &MY_DESK[2][2];
            i = 2;
            j = 2;
            figure_cod = MY_DESK[2][2];
            MY_DESK[2][2] = 0;
        }
        if (x > 135 && x <= 175 && y > 175 && y <= 215)
        {
            A = &MY_DESK[2][3];
            i = 2;
            j = 3;
            figure_cod = MY_DESK[2][3];
            MY_DESK[2][3] = 0;
        }
        if (x > 175 && x <= 215 && y > 175 && y <= 215)
        {
            A = &MY_DESK[2][4];
            i = 2;
            j = 4;
            figure_cod = MY_DESK[2][4];
            MY_DESK[2][4] = 0;
        }
        if (x > 215 && x <= 255 && y > 175 && y <= 215)
        {
            A = &MY_DESK[2][5];
            i = 2;
            j = 5;
            figure_cod = MY_DESK[2][5];
            MY_DESK[2][5] = 0;
        }
        if (x > 255 && x <= 295 && y > 175 && y <= 215)
        {
            A = &MY_DESK[2][6];
            i = 2;
            j = 6;
            figure_cod = MY_DESK[2][6];
            MY_DESK[2][6] = 0;
        }
        if (x > 295 && x <= 335 && y > 175 && y <= 215)
        {
            A = &MY_DESK[2][7];
            i = 2;
            j = 7;
            figure_cod = MY_DESK[2][7];
            MY_DESK[2][7] = 0;
        }

        if (x <= 55 && x >= 15 && y > 135 && y <= 175)
        {
            A = &MY_DESK[1][0];
            i = 1;
            j = 0;
            figure_cod = MY_DESK[1][0];
            MY_DESK[1][0] = 0;
        }
        if (x <= 95 && x > 55 && y > 135 && y <= 175)
        {
            A = &MY_DESK[1][1];
            i = 1;
            j = 1;
            figure_cod = MY_DESK[1][1];
            MY_DESK[1][1] = 0;
        }
        if (x > 95 && x <= 135 && y > 135 && y <= 175)
        {
            A = &MY_DESK[1][2];
            i = 1;
            j = 2;
            figure_cod = MY_DESK[1][2];
            MY_DESK[1][2] = 0;
        }
        if (x > 135 && x <= 175 && y > 135 && y <= 175)
        {
            A = &MY_DESK[1][3];
            i = 1;
            j = 3;
            figure_cod = MY_DESK[1][3];
            MY_DESK[1][3] = 0;
        }
        if (x > 175 && x <= 215 && y > 135 && y <= 175)
        {
            A = &MY_DESK[1][4];
            i = 1;
            j = 4;
            figure_cod = MY_DESK[1][4];
            MY_DESK[1][4] = 0;
        }
        if (x > 215 && x <= 255 && y > 135 && y <= 175)
        {
            A = &MY_DESK[1][5];
            i = 1;
            j = 5;
            figure_cod = MY_DESK[1][5];
            MY_DESK[1][5] = 0;
        }
        if (x > 255 && x <= 295 && y > 135 && y <= 175)
        {
            A = &MY_DESK[1][6];
            i = 1;
            j = 6;
            figure_cod = MY_DESK[1][6];
            MY_DESK[1][6] = 0;
        }
        if (x > 295 && x <= 335 && y > 135 && y <= 175)
        {
            A = &MY_DESK[1][7];
            i = 1;
            j = 7;
            figure_cod = MY_DESK[1][7];
            MY_DESK[1][7] = 0;
        }


        if (x <= 55 && x >= 15 && y > 95 && y <= 135)
        {
            A = &MY_DESK[0][0];
            i = 0;
            j = 0;
            figure_cod = MY_DESK[0][0];
            MY_DESK[0][0] = 0;
        }
        if (x <= 95 && x > 55 && y > 95 && y <= 135)
        {
            A = &MY_DESK[0][1];
            i = 0;
            j = 1;
            figure_cod = MY_DESK[0][1];
            MY_DESK[0][1] = 0;
        }
        if (x > 95 && x <= 135 && y > 95 && y <= 135)
        {
            A = &MY_DESK[0][2];
            i = 0;
            j = 2;
            figure_cod = MY_DESK[0][2];
            MY_DESK[0][2] = 0;
        }
        if (x > 135 && x <= 175 && y > 95 && y <= 135)
        {
            A = &MY_DESK[0][3];
            i = 0;
            j = 3;
            figure_cod = MY_DESK[0][3];
            MY_DESK[0][3] = 0;
        }
        if (x > 175 && x <= 215 && y > 95 && y <= 135)
        {
            A = &MY_DESK[0][4];
            i = 0;
            j = 4;
            figure_cod = MY_DESK[0][4];
            MY_DESK[0][4] = 0;
        }
        if (x > 215 && x <= 255 && y > 95 && y <= 135)
        {
            A = &MY_DESK[0][5];
            i = 0;
            j = 5;
            figure_cod = MY_DESK[0][5];
            MY_DESK[0][5] = 0;
        }
        if (x > 255 && x <= 295 && y > 95 && y <= 135)
        {
            A = &MY_DESK[0][6];
            i = 0;
            j = 6;
            figure_cod = MY_DESK[0][6];
            MY_DESK[0][6] = 0;
        }
        if (x > 295 && x <= 335 && y > 95 && y <= 135)
        {
            A = &MY_DESK[0][7];
            i = 0;
            j = 7;
            figure_cod = MY_DESK[0][7];
            MY_DESK[0][7] = 0;
        }

    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        if (x <= 55 && x >= 15 && y >= 375 && y <= 415)
        {
            B = &MY_DESK[7][0];
            k = 7;
            l = 0;
            if (flag == 0) MY_DESK[7][0] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[7][0] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x <= 95 && x > 55 && y >= 375 && y <= 415)
        {
            B = &MY_DESK[7][1];
            k = 7;
            l = 1;
            if (flag == 0) MY_DESK[7][1] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[7][1] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 95 && x <= 135 && y >= 375 && y <= 415)
        {
            B = &MY_DESK[7][2];
            k = 7;
            l = 2;
            if (flag == 0) MY_DESK[7][2] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[7][2] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 135 && x <= 175 && y >= 375 && y <= 415)
        {
            B = &MY_DESK[7][3];
            k = 7;
            l = 3;
            if (flag == 0) MY_DESK[7][3] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[7][3] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 175 && x <= 215 && y >= 375 && y <= 415)
        {
            B = &MY_DESK[7][4];
            k = 7;
            l = 4;
            if (flag == 0) MY_DESK[7][4] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[7][4] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 215 && x <= 255 && y >= 375 && y <= 415)
        {
            B = &MY_DESK[7][5];
            k = 7;
            l = 5;
            if (flag == 0) MY_DESK[7][5] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[7][5] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 255 && x <= 295 && y >= 375 && y <= 415)
        {
            B = &MY_DESK[7][6];
            k = 7;
            l = 6;
            if (flag == 0) MY_DESK[7][6] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[7][6] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 295 && x <= 335 && y >= 375 && y <= 415)
        {
            B = &MY_DESK[7][7];
            k = 7;
            l = 7;
            if (flag == 0) MY_DESK[7][7] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[7][7] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }

        if (x <= 55 && x >= 15 && y >= 335 && y < 375)
        {
            B = &MY_DESK[6][0];
            k = 6;
            l = 0;
            if (flag == 0)MY_DESK[6][0] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[6][0] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }

        }
        if (x <= 95 && x > 55 && y >= 335 && y < 375)
        {
            B = &MY_DESK[6][1];
            k = 6;
            l = 1;
            if (flag == 0)MY_DESK[6][1] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[6][1] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 95 && x <= 135 && y >= 335 && y < 375)
        {
            B = &MY_DESK[6][2];
            k = 6;
            l = 2;
            if (flag == 0)MY_DESK[6][2] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[6][2] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 135 && x <= 175 && y >= 335 && y < 375)
        {
            B = &MY_DESK[6][3];
            k = 6;
            l = 3;
            if (flag == 0)MY_DESK[6][3] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[6][3] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 175 && x <= 215 && y >= 335 && y < 375)
        {
            B = &MY_DESK[6][4];
            k = 6;
            l = 4;
            if (flag == 0)MY_DESK[6][4] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[6][4] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 215 && x <= 255 && y >= 335 && y < 375)
        {
            B = &MY_DESK[6][5];
            k = 6;
            l = 5;
            if (flag == 0)MY_DESK[6][5] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[6][5] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 255 && x <= 295 && y >= 335 && y < 375)
        {
            B = &MY_DESK[6][6];
            k = 6;
            l = 6;
            if (flag == 0)MY_DESK[6][6] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[6][6] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 295 && x <= 335 && y >= 335 && y < 375)
        {
            B = &MY_DESK[6][7];
            k = 6;
            l = 7;
            if (flag == 0) MY_DESK[6][7] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[6][7] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }

        if (x <= 55 && x >= 15 && y > 295 && y <= 335)
        {
            B = &MY_DESK[5][0];
            k = 5;
            l = 0;
            if (flag == 0)MY_DESK[5][0] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[5][0] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x <= 95 && x > 55 && y > 295 && y <= 335)
        {
            B = &MY_DESK[5][1];
            k = 5;
            l = 1;
            if (flag == 0) MY_DESK[5][1] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[5][1] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 95 && x <= 135 && y > 295 && y <= 335)
        {
            B = &MY_DESK[5][2];
            k = 5;
            l = 2;
            if (flag == 0) MY_DESK[5][2] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[5][2] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 135 && x <= 175 && y > 295 && y <= 335)
        {
            B = &MY_DESK[5][3];
            k = 5;
            l = 3;
            if (flag == 0) MY_DESK[5][3] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[5][3] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 175 && x <= 215 && y > 295 && y <= 335)
        {
            B = &MY_DESK[5][4];
            k = 5;
            l = 4;
            if (flag == 0) MY_DESK[5][4] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[5][4] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 215 && x <= 255 && y > 295 && y <= 335)
        {
            B = &MY_DESK[5][5];
            k = 5;
            l = 5;
            if (flag == 0) MY_DESK[5][5] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[5][5] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 255 && x <= 295 && y > 295 && y <= 335)
        {
            B = &MY_DESK[5][6];
            k = 5;
            l = 6;
            if (flag == 0) MY_DESK[5][6] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[5][6] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 295 && x <= 335 && y > 295 && y <= 335)
        {
            B = &MY_DESK[5][7];
            k = 5;
            l = 7;
            if (flag == 0) MY_DESK[5][7] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[5][7] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }

        if (x <= 55 && x >= 15 && y > 255 && y <= 295)
        {
            B = &MY_DESK[4][0];
            k = 4;
            l = 0;
            if (flag == 0) MY_DESK[4][0] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[4][0] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x <= 95 && x > 55 && y > 255 && y <= 295)
        {
            B = &MY_DESK[4][1];
            k = 4;
            l = 1;
            if (flag == 0) MY_DESK[4][1] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[4][1] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 95 && x <= 135 && y > 255 && y <= 295)
        {
            B = &MY_DESK[4][2];
            k = 4;
            l = 2;
            if (flag == 0) MY_DESK[4][2] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[4][2] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 135 && x <= 175 && y > 255 && y <= 295)
        {
            B = &MY_DESK[4][3];
            k = 4;
            l = 3;
            if (flag == 0) MY_DESK[4][3] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[4][3] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 175 && x <= 215 && y > 255 && y <= 295)
        {
            B = &MY_DESK[4][4];
            k = 4;
            l = 4;
            if (flag == 0) MY_DESK[4][4] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[4][4] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 215 && x <= 255 && y > 255 && y <= 295)
        {
            B = &MY_DESK[4][5];
            k = 4;
            l = 5;
            if (flag == 0) MY_DESK[4][5] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[4][5] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 255 && x <= 295 && y > 255 && y <= 295)
        {
            B = &MY_DESK[4][6];
            k = 4;
            l = 6;
            if (flag == 0) MY_DESK[4][6] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[4][6] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 295 && x <= 335 && y > 255 && y <= 295)
        {
            B = &MY_DESK[4][7];
            k = 4;
            l = 7;
            if (flag == 0) MY_DESK[4][7] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[4][7] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }

        if (x <= 55 && x >= 15 && y > 215 && y <= 255)
        {
            B = &MY_DESK[3][0];
            k = 3;
            l = 0;
            if (flag == 0) MY_DESK[3][0] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[3][0] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x <= 95 && x > 55 && y > 215 && y <= 255)
        {
            B = &MY_DESK[3][1];
            k = 3;
            l = 1;
            if (flag == 0) MY_DESK[3][1] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[3][1] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 95 && x <= 135 && y > 215 && y <= 255)
        {
            B = &MY_DESK[3][2];
            k = 3;
            l = 2;
            if (flag == 0) MY_DESK[3][2] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[3][2] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 135 && x <= 175 && y > 215 && y <= 255)
        {
            B = &MY_DESK[3][3];
            k = 3;
            l = 3;
            if (flag == 0) MY_DESK[3][3] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[3][3] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 175 && x <= 215 && y > 215 && y <= 255)
        {
            B = &MY_DESK[3][4];
            k = 3;
            l = 4;
            if (flag == 0) MY_DESK[3][4] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[3][4] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 215 && x <= 255 && y > 215 && y <= 255)
        {
            B = &MY_DESK[3][5];
            k = 3;
            l = 5;
            if (flag == 0) MY_DESK[3][5] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[3][5] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 255 && x <= 295 && y > 215 && y <= 255)
        {
            B = &MY_DESK[3][6];
            k = 3;
            l = 6;
            if (flag == 0) MY_DESK[3][6] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[3][6] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 295 && x <= 335 && y > 215 && y <= 255)
        {
            B = &MY_DESK[3][7];
            k = 3;
            l = 7;
            if (flag == 0) MY_DESK[3][7] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[3][7] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }


        if (x <= 55 && x >= 15 && y > 175 && y <= 215)
        {
            B = &MY_DESK[2][0];
            k = 2;
            l = 0;
            if (flag == 0) MY_DESK[2][0] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[2][0] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x <= 95 && x > 55 && y > 175 && y <= 215)
        {
            B = &MY_DESK[2][1];
            k = 2;
            l = 1;
            if (flag == 0) MY_DESK[2][1] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[2][1] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 95 && x <= 135 && y > 175 && y <= 215)
        {
            B = &MY_DESK[2][2];
            k = 2;
            l = 2;
            if (flag == 0) MY_DESK[2][2] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[2][2] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 135 && x <= 175 && y > 175 && y <= 215)
        {
            B = &MY_DESK[2][3];
            k = 2;
            l = 3;
            if (flag == 0) MY_DESK[2][3] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[2][3] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 175 && x <= 215 && y > 175 && y <= 215)
        {
            B = &MY_DESK[2][4];
            k = 2;
            l = 4;
            if (flag == 0) MY_DESK[2][4] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[2][4] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 215 && x <= 255 && y > 175 && y <= 215)
        {
            B = &MY_DESK[2][5];
            k = 2;
            l = 5;
            if (flag == 0) MY_DESK[2][5] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[2][5] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 255 && x <= 295 && y > 175 && y <= 215)
        {
            B = &MY_DESK[2][6];
            k = 2;
            l = 6;
            if (flag == 0) MY_DESK[2][6] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[2][6] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 295 && x <= 335 && y > 175 && y <= 215)
        {
            B = &MY_DESK[2][7];
            k = 2;
            l = 7;
            if (flag == 0) MY_DESK[2][7] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[2][7] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }


        if (x <= 55 && x >= 15 && y > 135 && y <= 175)
        {
            B = &MY_DESK[1][0];
            k = 1;
            l = 0;
            if (flag == 0) MY_DESK[1][0] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[1][0] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x <= 95 && x > 55 && y > 135 && y <= 175)
        {
            B = &MY_DESK[1][1];
            k = 1;
            l = 1;
            if (flag == 0) MY_DESK[1][1] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[1][1] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 95 && x <= 135 && y > 135 && y <= 175)
        {
            B = &MY_DESK[1][2];
            k = 1;
            l = 2;
            if (flag == 0) MY_DESK[1][2] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[1][2] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 135 && x <= 175 && y > 135 && y <= 175)
        {
            B = &MY_DESK[1][3];
            k = 1;
            l = 3;
            if (flag == 0) MY_DESK[1][3] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[1][3] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 175 && x <= 215 && y > 135 && y <= 175)
        {
            B = &MY_DESK[1][4];
            k = 1;
            l = 4;
            if (flag == 0) MY_DESK[1][4] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[1][4] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 215 && x <= 255 && y > 135 && y <= 175)
        {
            B = &MY_DESK[1][5];
            k = 1;
            l = 5;
            if (flag == 0) MY_DESK[1][5] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[1][5] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 255 && x <= 295 && y > 135 && y <= 175)
        {
            B = &MY_DESK[1][6];
            k = 1;
            l = 6;
            if (flag == 0) MY_DESK[1][6] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[1][6] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 295 && x <= 335 && y > 135 && y <= 175)
        {
            B = &MY_DESK[1][7];
            k = 1;
            l = 7;
            if (flag == 0) MY_DESK[1][7] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[1][7] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }


        if (x <= 55 && x >= 15 && y > 95 && y <= 135)
        {
            B = &MY_DESK[0][0];
            k = 0;
            l = 0;
            if (flag == 0) MY_DESK[0][0] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[0][0] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x <= 95 && x > 55 && y > 95 && y <= 135)
        {
            B = &MY_DESK[0][1];
            k = 0;
            l = 1;
            if (flag == 0) MY_DESK[0][1] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[0][1] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 95 && x <= 135 && y > 95 && y <= 135)
        {
            B = &MY_DESK[0][2];
            k = 0;
            l = 2;
            if (flag == 0) MY_DESK[0][2] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[0][2] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 135 && x <= 175 && y > 95 && y <= 135)
        {
            B = &MY_DESK[0][3];
            k = 0;
            l = 3;
            if (flag == 0) MY_DESK[0][3] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[0][3] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 175 && x <= 215 && y > 95 && y <= 135)
        {
            B = &MY_DESK[0][4];
            k = 0;
            l = 4;
            if (flag == 0) MY_DESK[0][4] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[0][4] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 215 && x <= 255 && y > 95 && y <= 135)
        {
            B = &MY_DESK[0][5];
            k = 0;
            l = 5;
            if (flag == 0) MY_DESK[0][5] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[0][5] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 255 && x <= 295 && y > 95 && y <= 135)
        {
            B = &MY_DESK[0][6];
            k = 0;
            l = 6;
            if (flag == 0) MY_DESK[0][6] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[0][6] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        if (x > 295 && x <= 335 && y > 95 && y <= 135)
        {
            B = &MY_DESK[0][7];
            k = 0;
            l = 7;
            if (flag == 0) MY_DESK[0][7] = figure_cod;
            if (flag == 1)
            {
                if (Proverka(A, B, figure_cod) == 1)
                {
                    MY_DESK[0][7] = figure_cod;
                }
                else
                {
                    *A = figure_cod;
                    printf("\a");
                }
            }
        }
        figure_cod = 0;


    }
    Display();

}
