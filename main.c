#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>
#include "includes/ft_printf.h"

#define GREEN "\033[0;32m"
#define RED   "\033[0;31m"
#define CYAN  "\033[0;36m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

static int g_total = 0;
static int g_passed = 0;

static void run_single_test(char *name, char *input_str, int ft_ret, int og_ret)
{
    g_total++;
    if (ft_ret == og_ret)
    {
        g_passed++;
        printf("%s[OK]%s   %-28s -> ft: %d | og: %d\n", GREEN, RESET, name, ft_ret, og_ret);
    }
    else
    {
        printf("%s[KO]%s   %-28s -> ft: %d | og: %d\n", RED, RESET, name, ft_ret, og_ret);
        printf("      %s---------------------------------------------------%s\n", YELLOW, RESET);
        printf("      %s[DIAGNOSTIC] Test Failed: \"%s\"%s\n", YELLOW, name, RESET);
        printf("      %s -> Input Li T-3ta (Input) : %s%s\n", YELLOW, input_str, RESET);
        printf("      %s -> ft_printf return     : %d%s\n", YELLOW, ft_ret, RESET);
        printf("      %s -> original printf ret  : %d%s\n", YELLOW, og_ret, RESET);
        printf("      %s---------------------------------------------------%s\n", YELLOW, RESET);
    }
}

// ==========================================
// Test Suites
// ==========================================
static void test_chars(void)
{
    int ft, og;

    ft = ft_printf("%c\n", 'A'); og = printf("%c\n", 'A'); run_single_test("Char A", "'A' (Char)", ft, og);
    ft = ft_printf("%c\n", 'z'); og = printf("%c\n", 'z'); run_single_test("Char z", "'z' (Char)", ft, og);
    ft = ft_printf("%c\n", '0'); og = printf("%c\n", '0'); run_single_test("Char 0", "'0' (Char)", ft, og);
    ft = ft_printf("%c\n", '9'); og = printf("%c\n", '9'); run_single_test("Char 9", "'9' (Char)", ft, og);
    ft = ft_printf("%c\n", ' '); og = printf("%c\n", ' '); run_single_test("Char Space", "' ' (Char)", ft, og);
    ft = ft_printf("%c\n", '\t'); og = printf("%c\n", '\t'); run_single_test("Char Tab", "'\\t' (Char)", ft, og);
    ft = ft_printf("%c\n", '\n'); og = printf("%c\n", '\n'); run_single_test("Char Newline", "'\\n' (Char)", ft, og);
    ft = ft_printf("%c\n", 0); og = printf("%c\n", 0); run_single_test("Char Null byte", "0 (Null byte)", ft, og);
    ft = ft_printf("%c\n", 1); og = printf("%c\n", 1); run_single_test("Char 1", "1 (ASCII)", ft, og);
    ft = ft_printf("%c\n", 127); og = printf("%c\n", 127); run_single_test("Char 127", "127 (ASCII)", ft, og);
    ft = ft_printf("%c %c %c\n", 'a', 'b', 'c'); og = printf("%c %c %c\n", 'a', 'b', 'c'); run_single_test("Multi Char 1", "'a', 'b', 'c'", ft, og);
    ft = ft_printf("%c-%c-%c\n", 'X', 'Y', 'Z'); og = printf("%c-%c-%c\n", 'X', 'Y', 'Z'); run_single_test("Multi Char 2", "'X', 'Y', 'Z'", ft, og);
    ft = ft_printf("1%c2%c3\n", '!', '@'); og = printf("1%c2%c3\n", '!', '@'); run_single_test("Multi Char 3", "'!', '@'", ft, og);
    ft = ft_printf("%c%c%c%c\n", '1', '2', '3', '4'); og = printf("%c%c%c%c\n", '1', '2', '3', '4'); run_single_test("Multi Char 4", "'1', '2', '3', '4'", ft, og);
    ft = ft_printf("A%cB%cC\n", 65, 66); og = printf("A%cB%cC\n", 65, 66); run_single_test("Multi Char 5", "65, 66 (ASCII)", ft, og);
    ft = ft_printf("%c %c %c %c\n", '*', '#', '$', '%'); og = printf("%c %c %c %c\n", '*', '#', '$', '%'); run_single_test("Multi Char 6", "'*', '#', '$', '%'", ft, og);
    ft = ft_printf("[%c]\n", 'a'); og = printf("[%c]\n", 'a'); run_single_test("Multi Char 7", "'a' inside brackets", ft, og);
    ft = ft_printf("{%c}\n", 'z'); og = printf("{%c}\n", 'z'); run_single_test("Multi Char 8", "'z' inside braces", ft, og);
    ft = ft_printf("(%c)\n", '0'); og = printf("(%c)\n", '0'); run_single_test("Multi Char 9", "'0' inside parentheses", ft, og);
    ft = ft_printf("->%c<-\n", 'x'); og = printf("->%c<-\n", 'x'); run_single_test("Multi Char 10", "'x' with arrows", ft, og);
}

static void test_strings(void)
{
    int ft, og;
    char *null_ptr = NULL;

    ft = ft_printf("%s\n", "Hello"); og = printf("%s\n", "Hello"); run_single_test("Str Hello", "\"Hello\" (String)", ft, og);
    ft = ft_printf("%s\n", ""); og = printf("%s\n", ""); run_single_test("Str Empty", "\"\" (Empty String)", ft, og);
    ft = ft_printf("%s\n", null_ptr); og = printf("%s\n", null_ptr); run_single_test("Str NULL", "NULL (char *)", ft, og);
    ft = ft_printf("%s\n", "1337 Coding School"); og = printf("%s\n", "1337 Coding School"); run_single_test("Str 1337", "\"1337 Coding School\"", ft, og);
    ft = ft_printf("%s\n", "Lorem ipsum dolor sit amet."); og = printf("%s\n", "Lorem ipsum dolor sit amet."); run_single_test("Str Long", "\"Lorem ipsum...\" (Long String)", ft, og);
    ft = ft_printf("%s\n", "\t\n\\\""); og = printf("%s\n", "\t\n\\\""); run_single_test("Str Special", "\"\\t\\n\\\\\\\"\" (Special chars)", ft, og);
    ft = ft_printf("%s %s\n", "Hello", "World"); og = printf("%s %s\n", "Hello", "World"); run_single_test("Multi Str 1", "\"Hello\", \"World\"", ft, og);
    ft = ft_printf("%s-%s\n", "42", "Khouribga"); og = printf("%s-%s\n", "42", "Khouribga"); run_single_test("Multi Str 2", "\"42\", \"Khouribga\"", ft, og);
    ft = ft_printf("[%s] [%s]\n", "test", ""); og = printf("[%s] [%s]\n", "test", ""); run_single_test("Multi Str 3", "\"test\", \"\"", ft, og);
    ft = ft_printf("%s and %s\n", "C", "Makefile"); og = printf("%s and %s\n", "C", "Makefile"); run_single_test("Multi Str 4", "\"C\", \"Makefile\"", ft, og);
    ft = ft_printf("A%sB%sC\n", "1", "2"); og = printf("A%sB%sC\n", "1", "2"); run_single_test("Multi Str 5", "\"1\", \"2\"", ft, og);
    ft = ft_printf("%s %s %s\n", "One", "Two", "Three"); og = printf("%s %s %s\n", "One", "Two", "Three"); run_single_test("Multi Str 6", "\"One\", \"Two\", \"Three\"", ft, og);
    ft = ft_printf("-> %s <-\n", "ft_printf"); og = printf("-> %s <-\n", "ft_printf"); run_single_test("Multi Str 7", "\"ft_printf\"", ft, og);
    ft = ft_printf("-%s-%s-\n", "a", "b"); og = printf("-%s-%s-\n", "a", "b"); run_single_test("Multi Str 8", "\"a\", \"b\"", ft, og);
    ft = ft_printf("%s\n", "Pointer"); og = printf("%s\n", "Pointer"); run_single_test("Multi Str 9", "\"Pointer\"", ft, og);
    ft = ft_printf("%s%s%s\n", "a", "b", "c"); og = printf("%s%s%s\n", "a", "b", "c"); run_single_test("Multi Str 10", "\"a\", \"b\", \"c\"", ft, og);
    ft = ft_printf("->%s<-\n", null_ptr); og = printf("->%s<-\n", null_ptr); run_single_test("Str with NULL 1", "->NULL<-", ft, og);
    ft = ft_printf("%s and %s\n", null_ptr, "Valid"); og = printf("%s and %s\n", null_ptr, "Valid"); run_single_test("Str with NULL 2", "NULL, \"Valid\"", ft, og);
    ft = ft_printf("%s and %s\n", "Valid", null_ptr); og = printf("%s and %s\n", "Valid", null_ptr); run_single_test("Str with NULL 3", "\"Valid\", NULL", ft, og);
    ft = ft_printf("%s\n", "a"); og = printf("%s\n", "a"); run_single_test("Str Single char", "\"a\"", ft, og);
    ft = ft_printf("%s\n", "0123456789"); og = printf("%s\n", "0123456789"); run_single_test("Str Digits", "\"0123456789\"", ft, og);
    ft = ft_printf("%s\n", "!@#$%^&*()"); og = printf("%s\n", "!@#$%^&*()"); run_single_test("Str Symbols", "\"!@#$%^&*()\"", ft, og);
    ft = ft_printf("Text: %s | Num: %s\n", "abc", "123"); og = printf("Text: %s | Num: %s\n", "abc", "123"); run_single_test("Str Mixed", "\"abc\", \"123\"", ft, og);
}

static void test_pointers(void)
{
    static int dummy = 42;
    void *ptr = &dummy;
    int ft, og;

    ft = ft_printf("%p\n", ptr); og = printf("%p\n", ptr); run_single_test("Ptr Basic", "&dummy (Valid pointer)", ft, og);
    ft = ft_printf("%p\n", NULL); og = printf("%p\n", NULL); run_single_test("Ptr NULL", "NULL pointer", ft, og);
    ft = ft_printf("%p\n", (void *)0); og = printf("%p\n", (void *)0); run_single_test("Ptr Zero", "(void *)0", ft, og);
    ft = ft_printf("%p\n", (void *)-1); og = printf("%p\n", (void *)-1); run_single_test("Ptr Max", "(void *)-1 (Max Address)", ft, og);
    ft = ft_printf("%p\n", (void *)"test"); og = printf("%p\n", (void *)"test"); run_single_test("Ptr Char", "(void *)\"test\" (String literal ptr)", ft, og);
    ft = ft_printf("%p %p\n", ptr, NULL); og = printf("%p %p\n", ptr, NULL); run_single_test("Multi Ptr 1", "ptr, NULL", ft, og);
    ft = ft_printf("%p-%p\n", NULL, ptr); og = printf("%p-%p\n", NULL, ptr); run_single_test("Multi Ptr 2", "NULL, ptr", ft, og);
    ft = ft_printf("[%p]\n", ptr); og = printf("[%p]\n", ptr); run_single_test("Multi Ptr 3", "ptr inside brackets", ft, og);
    ft = ft_printf("{%p}\n", NULL); og = printf("{%p}\n", NULL); run_single_test("Multi Ptr 4", "NULL inside braces", ft, og);
    ft = ft_printf("Addr: %p\n", ptr); og = printf("Addr: %p\n", ptr); run_single_test("Multi Ptr 5", "Addr: ptr", ft, og);
    ft = ft_printf("%p | %p\n", (void *)123, (void *)456); og = printf("%p | %p\n", (void *)123, (void *)456); run_single_test("Multi Ptr 6", "(void *)123, (void *)456", ft, og);
    ft = ft_printf("A:%p B:%p\n", ptr, ptr); og = printf("A:%p B:%p\n", ptr, ptr); run_single_test("Multi Ptr 7", "ptr, ptr", ft, og);
    ft = ft_printf("->%p<-\n", (void *)1000); og = printf("->%p<-\n", (void *)1000); run_single_test("Multi Ptr 8", "(void *)1000", ft, og);
    ft = ft_printf("%p %p %p\n", ptr, NULL, ptr); og = printf("%p %p %p\n", ptr, NULL, ptr); run_single_test("Multi Ptr 9", "ptr, NULL, ptr", ft, og);
    ft = ft_printf("Ptr: %p\n", NULL); og = printf("Ptr: %p\n", NULL); run_single_test("Multi Ptr 10", "Ptr: NULL", ft, og);
    ft = ft_printf("%p\n", (void *)42); og = printf("%p\n", (void *)42); run_single_test("Ptr Int casting", "(void *)42", ft, og);
    ft = ft_printf("%p\n", (void *)0xFF); og = printf("%p\n", (void *)0xFF); run_single_test("Ptr Hex cast", "(void *)0xFF", ft, og);
    ft = ft_printf("%p\n", (void *)1); og = printf("%p\n", (void *)1); run_single_test("Ptr Small", "(void *)1", ft, og);
}

static void test_integers(void)
{
    int ft, og;

    ft = ft_printf("%d\n", 0); og = printf("%d\n", 0); run_single_test("Int Zero d", "0 (Decimal)", ft, og);
    ft = ft_printf("%i\n", 0); og = printf("%i\n", 0); run_single_test("Int Zero i", "0 (Integer)", ft, og);
    ft = ft_printf("%d\n", 42); og = printf("%d\n", 42); run_single_test("Int Pos d", "42 (Decimal)", ft, og);
    ft = ft_printf("%i\n", 42); og = printf("%i\n", 42); run_single_test("Int Pos i", "42 (Integer)", ft, og);
    ft = ft_printf("%d\n", -42); og = printf("%d\n", -42); run_single_test("Int Neg d", "-42 (Decimal)", ft, og);
    ft = ft_printf("%i\n", -42); og = printf("%i\n", -42); run_single_test("Int Neg i", "-42 (Integer)", ft, og);
    ft = ft_printf("%d\n", INT_MAX); og = printf("%d\n", INT_MAX); run_single_test("Int INT_MAX", "INT_MAX (2147483647)", ft, og);
    ft = ft_printf("%d\n", INT_MIN); og = printf("%d\n", INT_MIN); run_single_test("Int INT_MIN", "INT_MIN (-2147483648)", ft, og);
    ft = ft_printf("%d %i\n", 10, -10); og = printf("%d %i\n", 10, -10); run_single_test("Int Simple mix", "10, -10", ft, og);
    ft = ft_printf("%d, %d, %d\n", 1, 2, 3); og = printf("%d, %d, %d\n", 1, 2, 3); run_single_test("Int Sequence 1", "1, 2, 3", ft, og);
    ft = ft_printf("%i-%i-%i\n", -1, -2, -3); og = printf("%i-%i-%i\n", -1, -2, -3); run_single_test("Int Sequence 2", "-1, -2, -3", ft, og);
    ft = ft_printf("[%d]\n", 1337); og = printf("[%d]\n", 1337); run_single_test("Int Bracket", "1337 inside brackets", ft, og);
    ft = ft_printf("{%i}\n", -1337); og = printf("{%i}\n", -1337); run_single_test("Int Brace", "-1337 inside braces", ft, og);
    ft = ft_printf("%d %d %d %d\n", 0, 1, -1, 100); og = printf("%d %d %d %d\n", 0, 1, -1, 100); run_single_test("Int Multiple 1", "0, 1, -1, 100", ft, og);
    ft = ft_printf("%i %i %i\n", INT_MAX, 0, INT_MIN); og = printf("%i %i %i\n", INT_MAX, 0, INT_MIN); run_single_test("Int Multiple 2", "INT_MAX, 0, INT_MIN", ft, og);
    ft = ft_printf("Num: %d\n", 999); og = printf("Num: %d\n", 999); run_single_test("Int Format 1", "Num: 999", ft, og);
    ft = ft_printf("Val: %i\n", -999); og = printf("Val: %i\n", -999); run_single_test("Int Format 2", "Val: -999", ft, og);
    ft = ft_printf("Sum: %d + %d = %d\n", 5, 5, 10); og = printf("Sum: %d + %d = %d\n", 5, 5, 10); run_single_test("Int Complex 1", "5 + 5 = 10", ft, og);
}

static void test_unsigned(void)
{
    int ft, og;

    ft = ft_printf("%u\n", 0); og = printf("%u\n", 0); run_single_test("Unsigned Zero", "0 (Unsigned)", ft, og);
    ft = ft_printf("%u\n", 42); og = printf("%u\n", 42); run_single_test("Unsigned Pos", "42 (Unsigned)", ft, og);
    ft = ft_printf("%u\n", 4294967295U); og = printf("%u\n", 4294967295U); run_single_test("Unsigned Max", "4294967295U (UINT_MAX)", ft, og);
    ft = ft_printf("%u\n", -1); og = printf("%u\n", -1); run_single_test("Unsigned Neg 1", "-1 cast to unsigned", ft, og);
    ft = ft_printf("%u\n", -42); og = printf("%u\n", -42); run_single_test("Unsigned Neg 42", "-42 cast to unsigned", ft, og);
    ft = ft_printf("%u\n", INT_MAX); og = printf("%u\n", INT_MAX); run_single_test("Unsigned INT_MAX", "INT_MAX as unsigned", ft, og);
    ft = ft_printf("%u %u\n", 0, 42); og = printf("%u %u\n", 0, 42); run_single_test("Multi Unsigned 1", "0, 42", ft, og);
    ft = ft_printf("[%u]\n", 99999); og = printf("[%u]\n", 99999); run_single_test("Multi Unsigned 3", "99999 inside brackets", ft, og);
    ft = ft_printf("{%u}\n", -123); og = printf("{%u}\n", -123); run_single_test("Multi Unsigned 4", "-123 inside braces", ft, og);
    ft = ft_printf("Unsigned: %u\n", 500); og = printf("Unsigned: %u\n", 500); run_single_test("Unsigned Format 1", "Unsigned: 500", ft, og);
}

static void test_hex(void)
{
    int ft, og;

    ft = ft_printf("%x\n", 0); og = printf("%x\n", 0); run_single_test("Hex Zero x", "0 (Lowercase hex)", ft, og);
    ft = ft_printf("%X\n", 0); og = printf("%X\n", 0); run_single_test("Hex Zero X", "0 (Uppercase hex)", ft, og);
    ft = ft_printf("%x\n", 42); og = printf("%x\n", 42); run_single_test("Hex Small x", "42 (Hex lowercase)", ft, og);
    ft = ft_printf("%X\n", 42); og = printf("%X\n", 42); run_single_test("Hex Small X", "42 (Hex uppercase)", ft, og);
    ft = ft_printf("%x\n", 255); og = printf("%x\n", 255); run_single_test("Hex 255 x", "255 (Hex lowercase)", ft, og);
    ft = ft_printf("%X\n", 255); og = printf("%X\n", 255); run_single_test("Hex 255 X", "255 (Hex uppercase)", ft, og);
    ft = ft_printf("%x\n", 4294967295U); og = printf("%x\n", 4294967295U); run_single_test("Hex Max x", "UINT_MAX (Hex lowercase)", ft, og);
    ft = ft_printf("%X\n", 4294967295U); og = printf("%X\n", 4294967295U); run_single_test("Hex Max X", "UINT_MAX (Hex uppercase)", ft, og);
    ft = ft_printf("%x\n", -1); og = printf("%x\n", -1); run_single_test("Hex Neg x", "-1 as hex lowercase", ft, og);
    ft = ft_printf("%x %X\n", 255, 255); og = printf("%x %X\n", 255, 255); run_single_test("Multi Hex 1", "255 (lower & upper)", ft, og);
    ft = ft_printf("Hex: %x\n", 50); og = printf("Hex: %x\n", 50); run_single_test("Hex Format 1", "Hex: 50", ft, og);
    ft = ft_printf("0x%x\n", 42); og = printf("0x%x\n", 42); run_single_test("Hex Prefix check", "0x42", ft, og);
}

static void test_percent(void)
{
    int ft, og;

    ft = ft_printf("%%\n"); og = printf("%%\n"); run_single_test("Percent Basic", "\"%%\"", ft, og);
    ft = ft_printf("%%%%\n"); og = printf("%%%%\n"); run_single_test("Percent Double", "\"%%%%\"", ft, og);
    ft = ft_printf("100%%\n"); og = printf("100%%\n"); run_single_test("Percent Text 1", "\"100%%\"", ft, og);
    ft = ft_printf("%c%%\n", 'A'); og = printf("%c%%\n", 'A'); run_single_test("Percent Mix 1", "'A', '%%'", ft, og);
    ft = ft_printf("%% %s\n", "test"); og = printf("%% %s\n", "test"); run_single_test("Percent Mix 2", "\"%%\", \"test\"", ft, og);
    ft = ft_printf("%d%%\n", 50); og = printf("%d%%\n", 50); run_single_test("Percent Mix 3", "50, \"%%\"", ft, og);
    ft = ft_printf("[%%]\n"); og = printf("[%%]\n"); run_single_test("Percent Bracket", "\"[%%]\"", ft, og);
}


static void test_write_error(void)
{
    int saved_stdout;
    int full_fd;
    int ft;

    fflush(stdout);
    saved_stdout = dup(STDOUT_FILENO);
    full_fd = open("/dev/full", O_WRONLY);
    if (saved_stdout == -1 || full_fd == -1)
    {
        printf("%s[SKIP]%s   Write error test (cannot access /dev/full)\n",
            YELLOW, RESET);
        if (saved_stdout != -1)
            close(saved_stdout);
        if (full_fd != -1)
            close(full_fd);
        return;
    }
    if (dup2(full_fd, STDOUT_FILENO) == -1)
    {
        printf("%s[SKIP]%s   Write error test (dup2 failed)\n", YELLOW, RESET);
        close(saved_stdout);
        close(full_fd);
        return;
    }
    close(full_fd);

    ft = ft_printf("This write should fail\n");

    fflush(stdout);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);

    run_single_test("Write error returns -1", "\"This write should fail\"",
        ft, -1);
}

static void test_edge_cases(void)
{
    int ft, og;
    char *empty_str = "";

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-security"
#pragma GCC diagnostic ignored "-Wformat-zero-length"
    ft = ft_printf(empty_str); og = printf(empty_str); 
#pragma GCC diagnostic pop

    run_single_test("Empty format string", "empty_str (\"\")", ft, og);
    ft = ft_printf("%d%d%d\n", 1, 2, 3); og = printf("%d%d%d\n", 1, 2, 3); run_single_test("Multiple consecutive ints", "1, 2, 3", ft, og);
    ft = ft_printf("%s%c%d%%\n", "Test", 'X', 100); og = printf("%s%c%d%%\n", "Test", 'X', 100); run_single_test("Mixed complex flags", "\"Test\", 'X', 100, \"%%\"", ft, og);
}

int main(void)
{
    printf("\n=========================================\n");
    printf("   %sSTARTING FT_PRINTF TESTS%s      \n", CYAN, RESET);
    printf("=========================================\n\n");

    test_chars();
    test_strings();
    test_pointers();
    test_integers();
    test_unsigned();
    test_hex();
    test_percent();
    test_write_error();
    test_edge_cases();

    // Summary Output
    printf("\n=========================================\n");
    printf("            TEST SUMMARY                 \n");
    printf("=========================================\n");
    printf("Total Tests Run : %d\n", g_total);
    if (g_passed == g_total)
    {
        printf("Result          : %sALL %d TESTS PASSED! [OK]%s\n", GREEN, g_total, RESET);
    }
    else
    {
        printf("Result          : %s%d PASSED / %d FAILED [KO]%s\n", RED, g_passed, g_total - g_passed, RESET);
    }
    printf("=========================================\n\n");

    return (0);
}