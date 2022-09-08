
#include "Unit_Tests.h"
#include "Square_Equation.h"
#include "Comp_Eps.h"

void unit_test (double a, double b, double c, int expected_roots, double expected_x1, double expected_x2)
{
    double x1 = 0, x2 = 0;

    int roots = solve_quadratic_equation (a, b, c, &x1, &x2);

    if (((comp_eps (x1, expected_x1)) || (comp_eps(x1, expected_x2))) && ((comp_eps(x2, expected_x1)) || (comp_eps(x2, expected_x2))) && (roots == expected_roots))
    {
        $sg; printf ("Test passed\n");
    //  ^~~ TODO: Is this the entire reason for including TXLib? Could have implemented it easily yourself.
    //  Would be a better solution, since using TXLib you're giving up support for dozens of platforms,
    //  including Linux (what I use), so I can't run it.

    //  Also, if you're using TXLib, you should at least include it in your repo (as submodule or just text
    //  file, doesn't matter that much).
    }
    else
    {
        $sr; printf ("Test failed\n a = %lf, b = %lf, c = %lf,\n right x1 = %lf\n right x2 = %lf\n x1 = %lf x2 = %lf\n Right roots = %d, roots = %d\n", a, b, c, test_x1, test_x2, x1, x2, test_roots, roots);
    }
}

void unit_test_from_file (double a, double b, double c, int expected_roots, double expected_x1, double expected_x2)
{
    FILE *fp = fopen ("files_for_reading/Tests.txt", "r");

    if (!fp)
    {
        // TODO: already commented somewhere, see man errno, so you can give a more detailed error
        printf("The file did not open\n");
        return;
    }

    while (true)
    {
        int symbols_from_file = (fscanf(fp, "%lf %lf %lf %d %lf %lf", &a, &b, &c, &expected_roots, &expected_x1, &expected_x2));

        printf("%d\n", symbols_from_file);
        if (symbols_from_file == EOF)
        {
            break;
        }

        else
        {
            unit_test (a, b, c, expected_roots, expected_x1, expected_x2);
        }
    }
}
