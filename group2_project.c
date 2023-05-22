#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

void print_instructions(void);
void play_game(void);
void shuffle(void);
void print_table(void);
void print_quit(void);
int get_index_to_be_swapped(int direction);
int swap_numbers(int swap_index);
void set_empty_index(void);
int check_if_puzzle_is_complete();
void print_success();
void print_error(int error_code);
void clear_error(void);
void data_saving();
void print_number_of_moves();
void print_data();

const int QUIT_KEY = 27;
const int ARROW_PREFIX_CHAR_1 = 224, ARROW_PREFIX_CHAR_2 = 0;
const int UP = 72, LEFT = 75, RIGHT = 77, DOWN = 80;
const int BOX_SIZE = 4;
const int INVALID_KEY = -1, INVALID_MOVE = -2;

int EmptyBoxIndex = 15;
int Numbers[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
int NoOfMoves;

int BOX_H_SPACE = 3;
int BOX_V_SPACE = 1;

int TOP_LEFT = 218;
int TOP_RIGHT = 191;
int BOTTOM_LEFT = 192;
int BOTTOM_RIGHT = 217;
int SLP_LINE = 196;
int STA_LINE = 179;
int LEFT_T = 195;
int RIGHT_T = 180;
int TOP_T = 194;
int BOTTOM_T = 193;
int JUNCTION = 197;

int main(void)
{
    system("CLS");
    system("color 3F");
    printf("\t\t\t\t\t ******WELCOME*******\n");
    printf("* To start the game press any key\n");
    printf("* To check the saved scores press S/s\n");
    printf("* To Exit press Escape key\n");
    printf("\n\tChoose your option -\n ");
    char start = getch();
    if (start == 224 || start == 0)
    {
        getch();
    }
    if (start == QUIT_KEY)
    {
        return 0;
    }
    else if (start == 'S' || start == 's')
    {
        print_data();
        printf("\n\n* Press Escape key to exit\n* Press any key to go back to main menu");
        int back = getch();
        if (back == 224 || back == 0)
        {
            getch();
        }
        if (back == QUIT_KEY)
        {
            return 0;
        }
        else
        {
            main();
        }
    }
    else
    {
        system("CLS");
        print_instructions();
        int ch = getch();
        if (ch == 224 || ch == 0)
        {
            getch();
        }
        system("CLS");
        shuffle();
        set_empty_index();
        print_table();
        play_game();
    }
}

void print_instructions()
{
    print_table();

    printf(" \n\n    INSTRUCTIONS TO PLAY THE GAME\n\n");

    printf("* This is the correct position of puzzle. Once you start the game you will get a shuffled position of the puzzle\n");
    printf("* Use the arrow keys and move the blocks and try to set the puzzle back to its original position\n");
    printf("* You can Quit the game any time by pressing Escape key\n");
    printf("\n\tPress any key to start the game");
}

void play_game()
{
    int ch = 0;
    while (ch != QUIT_KEY)
    {
        ch = getch();
        if (ch == QUIT_KEY)
        {
            print_quit();
            break;
        }
        else if (ch == ARROW_PREFIX_CHAR_1 || ch == ARROW_PREFIX_CHAR_2)
        {
            ch = getch();

            int swap_index = get_index_to_be_swapped(ch);

            if (swap_index < 0)
            {
                print_error(swap_index);
            }
            else
            {
                swap_numbers(swap_index);
                print_table();
                NoOfMoves++;
                print_number_of_moves();

                int success = check_if_puzzle_is_complete();
                if (success == 1)
                {
                    print_success();
                    printf("\n\n\nDo you want to save your score ? If yes press Y/y or else press any key to continue - ");
                    char save_score = getch();
                    printf("\n");
                    if (save_score == 'Y' || save_score == 'y')
                    {
                        data_saving();
                    }
                    printf("\n\n\n* If you want to play again press P/p\n* To show saved scores press S/s\n* To exit press Escape key\n* To go back to main menu press any other key");
                    char what_next = getch();
                    if (what_next == 'P' || what_next == 'p')
                    {
                        system("CLS");
                        NoOfMoves = 0;
                        shuffle();
                        set_empty_index();
                        print_table();
                        play_game();
                    }
                    else if (what_next == 'S' || what_next == 's')
                    {
                        printf("\n\n");
                        print_data();
                        printf("\n\n");
                        printf("* Press escape key to exit\n* Press any key to go back to main menu");
                        int menu = getch();
                        if (menu == 224 || menu == 0)
                        {
                            getch();
                        }
                        if (menu == QUIT_KEY)
                        {
                            break;
                        }
                        else
                        {
                            main();
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            print_error(INVALID_KEY);
        }
    }
}

void set_empty_index(void)
{
    int i;
    for (i = 0; i <= 15; i++)
    {
        if (Numbers[i] == 0)
        {
            EmptyBoxIndex = i;
            break;
        }
    }
}

int get_index_to_be_swapped(int direction)
{

    if (direction == DOWN)
    {
        if (EmptyBoxIndex / BOX_SIZE == 0)
        {
            return INVALID_MOVE;
        }
        else
        {
            return EmptyBoxIndex - BOX_SIZE;
        }
    }
    else if (direction == UP)
    {
        if (EmptyBoxIndex / BOX_SIZE == (BOX_SIZE - 1))
        {
            return INVALID_MOVE;
        }
        else
        {
            return EmptyBoxIndex + BOX_SIZE;
        }
    }
    else if (direction == RIGHT)
    {
        if (EmptyBoxIndex % BOX_SIZE == 0)
        {
            return INVALID_MOVE;
        }
        else
        {
            return EmptyBoxIndex - 1;
        }
    }
    else if (direction == LEFT)
    {
        if (EmptyBoxIndex % BOX_SIZE == (BOX_SIZE - 1))
        {
            return INVALID_MOVE;
        }
        else
        {
            return EmptyBoxIndex + 1;
        }
    }
    else
    {
        return INVALID_KEY;
    }
}

int swap_numbers(int swap_index)
{
    Numbers[EmptyBoxIndex] = Numbers[swap_index];
    Numbers[swap_index] = 0;
    EmptyBoxIndex = swap_index;
}

void shuffle(void)
{
    int i;
    time_t t;
    srand((unsigned)time(&t));
    int directions[4] = {UP, DOWN, LEFT, RIGHT};

    for (i = 0; i < 5000; i++)
    {
        int dir = rand() % 4;
        dir = directions[dir];
        int swap_for_shuffling = get_index_to_be_swapped(dir);
        if (swap_for_shuffling >= 0)
        {
            swap_numbers(swap_for_shuffling);
        }
    }
}

void print_success()
{
    COORD d;
    d.X = 50;
    d.Y = 15;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h, d);
    printf("Hurray! You made it in %d Moves ", NoOfMoves);
}

void print_error(int error_code)
{
    COORD d;
    d.X = 50;
    d.Y = 15;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h, d);
    if (error_code == INVALID_KEY)
    {
        printf("Invalid Key ");
    }
    else
    {
        printf("Invalid Move");
    }
}

void print_quit()
{
    COORD e;
    e.X = 50;
    e.Y = 15;

    HANDLE f = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(f, e);
    printf("                  ", NoOfMoves);
    COORD d;
    d.X = 50;
    d.Y = 17;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h, d);
    printf("You Quit! Complete the puzzle next time");
}

int check_if_puzzle_is_complete()
{
    int i;
    for (i = 0; i < BOX_SIZE * BOX_SIZE - 1; i++)
    {

        if (Numbers[i] != i + 1)
        {
            return 0;
        }
    }
    return 1;
}

void print_number_of_moves()
{
    COORD d;
    d.X = 50;
    d.Y = 15;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h, d);
    printf("Moves - %d    ", NoOfMoves);
}

void draw_line(int line_char, int left_edge, int right_edge, int column_separator)
{
    int last_column = BOX_SIZE - 1;
    printf("%c", left_edge);
    for (int col = 0; col < BOX_SIZE; col++)
    {
        for (int j = 0; j < (BOX_H_SPACE * 2) + 2; j++)
        {
            printf("%c", line_char);
        }

        if (col == last_column)
        {
            printf("%c", right_edge);
        }
        else
        {
            printf("%c", column_separator);
        }
    }
    printf("\n");
}

void print_table()
{
    COORD d;
    d.X = 0;
    d.Y = 0;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h, d);
    int last_row = BOX_SIZE - 1;

    draw_line(SLP_LINE, TOP_LEFT, TOP_RIGHT, TOP_T);
    for (int row = 0; row < BOX_SIZE; row++)
    {
        for (int i = 0; i < BOX_V_SPACE; i++)
        {
            draw_line(' ', STA_LINE, STA_LINE, STA_LINE);
        }

        printf("%c", STA_LINE);
        for (int col = 0; col < BOX_SIZE; col++)
        {

            for (int i = 0; i < BOX_H_SPACE; i++)
            {
                printf(" ");
            }

            int index = row * BOX_SIZE + col;
            if (Numbers[index] == 0)
            {
                printf("%2c", ' ');
            }
            else
            {
                printf("%2d", Numbers[index]);
            }

            for (int i = 0; i < BOX_H_SPACE; i++)
            {
                printf(" ");
            }
            printf("%c", STA_LINE);
        }
        printf("\n");

        for (int i = 0; i < BOX_V_SPACE; i++)
        {
            draw_line(' ', STA_LINE, STA_LINE, STA_LINE);
        }

        if (row == last_row)
        {
            draw_line(SLP_LINE, BOTTOM_LEFT, BOTTOM_RIGHT, BOTTOM_T);
        }
        else
        {
            draw_line(SLP_LINE, LEFT_T, RIGHT_T, JUNCTION);
        }
    }
}

void data_saving()
{
    char name[20];
    printf("Enter the name - ");
    scanf("\n");
    scanf("%[^\n]s", name);

    FILE *data;
    data = fopen("scores.txt", "a");

    fprintf(data, "%s\t\t%d Moves\n", name, NoOfMoves);
    fclose(data);
}

void print_data()
{
    char print_name;
    FILE *data;
    data = fopen("scores.txt", "r");
    while (!feof(data))
    {
        fread(&print_name, sizeof(print_name), 1, data);
        printf("%c", print_name);
    }
    fclose(data);
}