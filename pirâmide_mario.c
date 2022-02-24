#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
        while (n < 1 || n > 8)
        {
            n = get_int("Height: ");
        }
    }
    while (n < 0);

    switch (n)
    {
        case 1:
        printf("#  #\n");
        break;
        case 2:
        printf(" #  #\n");
        printf("##  ##\n");
        break;
        case 3:
        printf("  #  #\n");
        printf(" ##  ##\n");
        printf("###  ###\n");
        break;
        case 4:
        printf("   #  #\n");
        printf("  ##  ##\n");
        printf(" ###  ###\n");
        printf("####  ####\n");
        break;
        case 5:
        printf("    #  #\n");
        printf("   ##  ##\n");
        printf("  ###  ###\n");
        printf(" ####  ####\n");
        printf("#####  #####\n");
        break;
        case 6:
        printf("     #  #\n");
        printf("    ##  ##\n");
        printf("   ###  ###\n");
        printf("  ####  ####\n");
        printf(" #####  #####\n");
        printf("######  ######\n");
        break;
        case 7:
        printf("      #  #\n");
        printf("     ##  ##\n");
        printf("    ###  ###\n");
        printf("   ####  ####\n");
        printf("  #####  #####\n");
        printf(" ######  ######\n");
        printf("#######  #######\n");
        break;
        case 8:
        printf("       #  #\n");
        printf("      ##  ##\n");
        printf("     ###  ###\n");
        printf("    ####  ####\n");
        printf("   #####  #####\n");
        printf("  ######  ######\n");
        printf(" #######  #######\n");
        printf("########  ########\n");
        break;
    }
}
