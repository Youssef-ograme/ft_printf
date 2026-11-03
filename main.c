#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

#define GREEN "\033[0;32m"
#define RED   "\033[0;31m"
#define CYAN  "\033[0;36m"
#define RESET "\033[0m"

static int g_total = 0;
static int g_passed = 0;

static void run_single_test(char *name, int ft_ret, int og_ret)
{
    g_total++;
    if (ft_ret == og_ret)
    {
        g_passed++;
    }
    else
    {
        printf("%s[KO]%s %s -> ft: %d | og: %d\n", RED, RESET, name, ft_ret, og_ret);
    }
}

// ==========================================
// Test Suites
// ==========================================
static void test_chars(void)
{
    run_single_test("Char A", ft_printf("%c\n", 'A'), printf("%c\n", 'A'));
    run_single_test("Char z", ft_printf("%c\n", 'z'), printf("%c\n", 'z'));
    run_single_test("Char 0", ft_printf("%c\n", '0'), printf("%c\n", '0'));
    run_single_test("Char 9", ft_printf("%c\n", '9'), printf("%c\n", '9'));
    run_single_test("Char Space", ft_printf("%c\n", ' '), printf("%c\n", ' '));
    run_single_test("Char Tab", ft_printf("%c\n", '\t'), printf("%c\n", '\t'));
    run_single_test("Char Newline", ft_printf("%c\n", '\n'), printf("%c\n", '\n'));
    run_single_test("Char Null byte", ft_printf("%c\n", 0), printf("%c\n", 0));
    run_single_test("Char 1", ft_printf("%c\n", 1), printf("%c\n", 1));
    run_single_test("Char 127", ft_printf("%c\n", 127), printf("%c\n", 127));
    run_single_test("Multi Char 1", ft_printf("%c %c %c\n", 'a', 'b', 'c'), printf("%c %c %c\n", 'a', 'b', 'c'));
    run_single_test("Multi Char 2", ft_printf("%c-%c-%c\n", 'X', 'Y', 'Z'), printf("%c-%c-%c\n", 'X', 'Y', 'Z'));
    run_single_test("Multi Char 3", ft_printf("1%c2%c3\n", '!', '@'), printf("1%c2%c3\n", '!', '@'));
    run_single_test("Multi Char 4", ft_printf("%c%c%c%c\n", '1', '2', '3', '4'), printf("%c%c%c%c\n", '1', '2', '3', '4'));
    run_single_test("Multi Char 5", ft_printf("A%cB%cC\n", 65, 66), printf("A%cB%cC\n", 65, 66));
    run_single_test("Multi Char 6", ft_printf("%c %c %c %c\n", '*', '#', '$', '%'), printf("%c %c %c %c\n", '*', '#', '$', '%'));
    run_single_test("Multi Char 7", ft_printf("[%c]\n", 'a'), printf("[%c]\n", 'a'));
    run_single_test("Multi Char 8", ft_printf("{%c}\n", 'z'), printf("{%c}\n", 'z'));
    run_single_test("Multi Char 9", ft_printf("(%c)\n", '0'), printf("(%c)\n", '0'));
    run_single_test("Multi Char 10", ft_printf("->%c<-\n", 'x'), printf("->%c<-\n", 'x'));
}

static void test_strings(void)
{
    run_single_test("Str Hello", ft_printf("%s\n", "Hello"), printf("%s\n", "Hello"));
    run_single_test("Str Empty", ft_printf("%s\n", ""), printf("%s\n", ""));
    run_single_test("Str NULL", ft_printf("%s\n", (char *)NULL), printf("%s\n", (char *)NULL));
    run_single_test("Str 1337", ft_printf("%s\n", "1337 Coding School"), printf("%s\n", "1337 Coding School"));
    run_single_test("Str Long", ft_printf("%s\n", "Lorem ipsum dolor sit amet, consectetur adipiscing elit."), printf("%s\n", "Lorem ipsum dolor sit amet, consectetur adipiscing elit."));
    run_single_test("Str Special", ft_printf("%s\n", "\t\n\\\""), printf("%s\n", "\t\n\\\""));
    run_single_test("Multi Str 1", ft_printf("%s %s\n", "Hello", "World"), printf("%s %s\n", "Hello", "World"));
    run_single_test("Multi Str 2", ft_printf("%s-%s\n", "42", "Khouribga"), printf("%s-%s\n", "42", "Khouribga"));
    run_single_test("Multi Str 3", ft_printf("[%s] [%s]\n", "test", ""), printf("[%s] [%s]\n", "test", ""));
    run_single_test("Multi Str 4", ft_printf("%s and %s\n", "C", "Makefile"), printf("%s and %s\n", "C", "Makefile"));
    run_single_test("Multi Str 5", ft_printf("A%sB%sC\n", "1", "2"), printf("A%sB%sC\n", "1", "2"));
    run_single_test("Multi Str 6", ft_printf("%s %s %s\n", "One", "Two", "Three"), printf("%s %s %s\n", "One", "Two", "Three"));
    run_single_test("Multi Str 7", ft_printf("-> %s <-\n", "ft_printf"), printf("-> %s <-\n", "ft_printf"));
    run_single_test("Multi Str 8", ft_printf("-%s-%s-\n", "a", "b"), printf("-%s-%s-\n", "a", "b"));
    run_single_test("Multi Str 9", ft_printf("%s\n", "Pointer"), printf("%s\n", "Pointer"));
    run_single_test("Multi Str 10", ft_printf("%s%s%s\n", "a", "b", "c"), printf("%s%s%s\n", "a", "b", "c"));
    run_single_test("Str with NULL 1", ft_printf("->%s<-\n", (char *)NULL), printf("->%s<-\n", (char *)NULL));
    run_single_test("Str with NULL 2", ft_printf("%s and %s\n", (char *)NULL, "Valid"), printf("%s and %s\n", (char *)NULL, "Valid"));
    run_single_test("Str with NULL 3", ft_printf("%s and %s\n", "Valid", (char *)NULL), printf("%s and %s\n", "Valid", (char *)NULL));
    run_single_test("Str Single char", ft_printf("%s\n", "a"), printf("%s\n", "a"));
    run_single_test("Str Digits", ft_printf("%s\n", "0123456789"), printf("%s\n", "0123456789"));
    run_single_test("Str Symbols", ft_printf("%s\n", "!@#$%^&*()"), printf("%s\n", "!@#$%^&*()"));
    run_single_test("Str Spaces", ft_printf("%s\n", "   "), printf("%s\n", "   "));
    run_single_test("Str Mixed", ft_printf("Text: %s | Num: %s\n", "abc", "123"), printf("Text: %s | Num: %s\n", "abc", "123"));
    run_single_test("Str Endings", ft_printf("%s -- %s\n", "End.", "Start."), printf("%s -- %s\n", "End.", "Start."));
}

static void test_pointers(void)
{
    static int dummy = 42;
    void *ptr = &dummy;

    run_single_test("Ptr Basic", ft_printf("%p\n", ptr), printf("%p\n", ptr));
    run_single_test("Ptr NULL", ft_printf("%p\n", NULL), printf("%p\n", NULL));
    run_single_test("Ptr Zero", ft_printf("%p\n", (void *)0), printf("%p\n", (void *)0));
    run_single_test("Ptr Max", ft_printf("%p\n", (void *)-1), printf("%p\n", (void *)-1));
    run_single_test("Ptr Char", ft_printf("%p\n", (void *)"test"), printf("%p\n", (void *)"test"));
    run_single_test("Multi Ptr 1", ft_printf("%p %p\n", ptr, NULL), printf("%p %p\n", ptr, NULL));
    run_single_test("Multi Ptr 2", ft_printf("%p-%p\n", NULL, ptr), printf("%p-%p\n", NULL, ptr));
    run_single_test("Multi Ptr 3", ft_printf("[%p]\n", ptr), printf("[%p]\n", ptr));
    run_single_test("Multi Ptr 4", ft_printf("{%p}\n", NULL), printf("{%p}\n", NULL));
    run_single_test("Multi Ptr 5", ft_printf("Addr: %p\n", ptr), printf("Addr: %p\n", ptr));
    run_single_test("Multi Ptr 6", ft_printf("%p | %p\n", (void *)123, (void *)456), printf("%p | %p\n", (void *)123, (void *)456));
    run_single_test("Multi Ptr 7", ft_printf("A:%p B:%p\n", ptr, ptr), printf("A:%p B:%p\n", ptr, ptr));
    run_single_test("Multi Ptr 8", ft_printf("->%p<-\n", (void *)1000), printf("->%p<-\n", (void *)1000));
    run_single_test("Multi Ptr 9", ft_printf("%p %p %p\n", ptr, NULL, ptr), printf("%p %p %p\n", ptr, NULL, ptr));
    run_single_test("Multi Ptr 10", ft_printf("Ptr: %p (nil?)\n", NULL), printf("Ptr: %p (nil?)\n", NULL));
    run_single_test("Ptr Int casting", ft_printf("%p\n", (void *)42), printf("%p\n", (void *)42));
    run_single_test("Ptr Hex cast", ft_printf("%p\n", (void *)0xFF), printf("%p\n", (void *)0xFF));
    run_single_test("Ptr Large", ft_printf("%p\n", (void *)0x7fff5fbff800), printf("%p\n", (void *)0x7fff5fbff800));
    run_single_test("Ptr Small", ft_printf("%p\n", (void *)1), printf("%p\n", (void *)1));
    run_single_test("Ptr Border", ft_printf("->%p<-\n", (void *)0x12345678), printf("->%p<-\n", (void *)0x12345678));
}

static void test_integers(void)
{
    run_single_test("Int Zero d", ft_printf("%d\n", 0), printf("%d\n", 0));
    run_single_test("Int Zero i", ft_printf("%i\n", 0), printf("%i\n", 0));
    run_single_test("Int Pos d", ft_printf("%d\n", 42), printf("%d\n", 42));
    run_single_test("Int Pos i", ft_printf("%i\n", 42), printf("%i\n", 42));
    run_single_test("Int Neg d", ft_printf("%d\n", -42), printf("%d\n", -42));
    run_single_test("Int Neg i", ft_printf("%i\n", -42), printf("%i\n", -42));
    run_single_test("Int INT_MAX", ft_printf("%d\n", INT_MAX), printf("%d\n", INT_MAX));
    run_single_test("Int INT_MIN", ft_printf("%d\n", INT_MIN), printf("%d\n", INT_MIN));
    run_single_test("Int Simple mix", ft_printf("%d %i\n", 10, -10), printf("%d %i\n", 10, -10));
    run_single_test("Int Sequence 1", ft_printf("%d, %d, %d\n", 1, 2, 3), printf("%d, %d, %d\n", 1, 2, 3));
    run_single_test("Int Sequence 2", ft_printf("%i-%i-%i\n", -1, -2, -3), printf("%i-%i-%i\n", -1, -2, -3));
    run_single_test("Int Bracket", ft_printf("[%d]\n", 1337), printf("[%d]\n", 1337));
    run_single_test("Int Brace", ft_printf("{%i}\n", -1337), printf("{%i}\n", -1337));
    run_single_test("Int Multiple 1", ft_printf("%d %d %d %d\n", 0, 1, -1, 100), printf("%d %d %d %d\n", 0, 1, -1, 100));
    run_single_test("Int Multiple 2", ft_printf("%i %i %i\n", INT_MAX, 0, INT_MIN), printf("%i %i %i\n", INT_MAX, 0, INT_MIN));
    run_single_test("Int Format 1", ft_printf("Num: %d\n", 999), printf("Num: %d\n", 999));
    run_single_test("Int Format 2", ft_printf("Val: %i\n", -999), printf("Val: %i\n", -999));
    run_single_test("Int Border 1", ft_printf("%d\n", 9), printf("%d\n", 9));
    run_single_test("Int Border 2", ft_printf("%d\n", 10), printf("%d\n", 10));
    run_single_test("Int Border 3", ft_printf("%d\n", -9), printf("%d\n", -9));
    run_single_test("Int Border 4", ft_printf("%d\n", -10), printf("%d\n", -10));
    run_single_test("Int Border 5", ft_printf("%d\n", 99), printf("%d\n", 99));
    run_single_test("Int Border 6", ft_printf("%d\n", 100), printf("%d\n", 100));
    run_single_test("Int Complex 1", ft_printf("Sum: %d + %d = %d\n", 5, 5, 10), printf("Sum: %d + %d = %d\n", 5, 5, 10));
    run_single_test("Int Complex 2", ft_printf("%d vs %i\n", 42, 42), printf("%d vs %i\n", 42, 42));
    run_single_test("Int Sub", ft_printf("%d\n", 123 - 456), printf("%d\n", 123 - 456));
    run_single_test("Int Add", ft_printf("%i\n", 123 + 456), printf("%i\n", 123 + 456));
    run_single_test("Int Long string", ft_printf("Result is %d ok?\n", 7), printf("Result is %d ok?\n", 7));
    run_single_test("Int Double neg", ft_printf("%d %d\n", -50, -60), printf("%d %d\n", -50, -60));
    run_single_test("Int Triple mix", ft_printf("%d %i %d\n", -1, 0, 1), printf("%d %i %d\n", -1, 0, 1));
}

static void test_unsigned(void)
{
    run_single_test("Unsigned Zero", ft_printf("%u\n", 0), printf("%u\n", 0));
    run_single_test("Unsigned Pos", ft_printf("%u\n", 42), printf("%u\n", 42));
    run_single_test("Unsigned Max", ft_printf("%u\n", 4294967295U), printf("%u\n", 4294967295U));
    run_single_test("Unsigned Neg 1", ft_printf("%u\n", -1), printf("%u\n", -1));
    run_single_test("Unsigned Neg 42", ft_printf("%u\n", -42), printf("%u\n", -42));
    run_single_test("Unsigned INT_MAX", ft_printf("%u\n", INT_MAX), printf("%u\n", INT_MAX));
    run_single_test("Unsigned INT_MIN", ft_printf("%u\n", INT_MIN), printf("%u\n", INT_MIN));
    run_single_test("Multi Unsigned 1", ft_printf("%u %u\n", 0, 42), printf("%u %u\n", 0, 42));
    run_single_test("Multi Unsigned 2", ft_printf("%u-%u\n", 100, 200), printf("%u-%u\n", 100, 200));
    run_single_test("Multi Unsigned 3", ft_printf("[%u]\n", 99999), printf("[%u]\n", 99999));
    run_single_test("Multi Unsigned 4", ft_printf("{%u}\n", -123), printf("{%u}\n", -123));
    run_single_test("Multi Unsigned 5", ft_printf("%u | %u | %u\n", 1, 2, 3), printf("%u | %u | %u\n", 1, 2, 3));
    run_single_test("Unsigned Format 1", ft_printf("Unsigned: %u\n", 500), printf("Unsigned: %u\n", 500));
    run_single_test("Unsigned Format 2", ft_printf("->%u<-\n", 0), printf("->%u<-\n", 0));
    run_single_test("Unsigned Border 1", ft_printf("%u\n", 9), printf("%u\n", 9));
    run_single_test("Unsigned Border 2", ft_printf("%u\n", 10), printf("%u\n", 10));
    run_single_test("Unsigned Large 1", ft_printf("%u\n", 3000000000U), printf("%u\n", 3000000000U));
    run_single_test("Unsigned Large 2", ft_printf("%u\n", 4000000000U), printf("%u\n", 4000000000U));
    run_single_test("Unsigned Triple", ft_printf("%u %u %u\n", 10, 20, 30), printf("%u %u %u\n", 10, 20, 30));
    run_single_test("Unsigned End", ft_printf("End %u\n", 777), printf("End %u\n", 777));
}

static void test_hex(void)
{
    run_single_test("Hex Zero x", ft_printf("%x\n", 0), printf("%x\n", 0));
    run_single_test("Hex Zero X", ft_printf("%X\n", 0), printf("%X\n", 0));
    run_single_test("Hex Small x", ft_printf("%x\n", 42), printf("%x\n", 42));
    run_single_test("Hex Small X", ft_printf("%X\n", 42), printf("%X\n", 42));
    run_single_test("Hex 255 x", ft_printf("%x\n", 255), printf("%x\n", 255));
    run_single_test("Hex 255 X", ft_printf("%X\n", 255), printf("%X\n", 255));
    run_single_test("Hex 1000 x", ft_printf("%x\n", 1000), printf("%x\n", 1000));
    run_single_test("Hex 1000 X", ft_printf("%X\n", 1000), printf("%X\n", 1000));
    run_single_test("Hex Max x", ft_printf("%x\n", 4294967295U), printf("%x\n", 4294967295U));
    run_single_test("Hex Max X", ft_printf("%X\n", 4294967295U), printf("%X\n", 4294967295U));
    run_single_test("Hex Neg x", ft_printf("%x\n", -1), printf("%x\n", -1));
    run_single_test("Hex Neg X", ft_printf("%X\n", -1), printf("%X\n", -1));
    run_single_test("Multi Hex 1", ft_printf("%x %X\n", 255, 255), printf("%x %X\n", 255, 255));
    run_single_test("Multi Hex 2", ft_printf("%x-%x\n", 10, 15), printf("%x-%x\n", 10, 15));
    run_single_test("Multi Hex 3", ft_printf("[%X] [%X]\n", 10, 15), printf("[%X] [%X]\n", 10, 15));
    run_single_test("Hex Bracket", ft_printf("{%x}\n", 4096), printf("{%x}\n", 4096));
    run_single_test("Hex Brace", ft_printf("{%X}\n", 4096), printf("{%X}\n", 4096));
    run_single_test("Hex Mix 1", ft_printf("%x %x %x\n", 1, 2, 3), printf("%x %x %x\n", 1, 2, 3));
    run_single_test("Hex Mix 2", ft_printf("%X %X %X\n", 10, 20, 30), printf("%X %X %X\n", 10, 20, 30));
    run_single_test("Hex Format 1", ft_printf("Hex: %x\n", 50), printf("Hex: %x\n", 50));
    run_single_test("Hex Format 2", ft_printf("HEX: %X\n", 50), printf("HEX: %X\n", 50));
    run_single_test("Hex Border 1", ft_printf("%x\n", 9), printf("%x\n", 9));
    run_single_test("Hex Border 2", ft_printf("%x\n", 10), printf("%x\n", 10));
    run_single_test("Hex Border 3", ft_printf("%x\n", 15), printf("%x\n", 15));
    run_single_test("Hex Border 4", ft_printf("%x\n", 16), printf("%x\n", 16));
    run_single_test("Hex Large 1", ft_printf("%x\n", 0xabcdef), printf("%x\n", 0xabcdef));
    run_single_test("Hex Large 2", ft_printf("%X\n", 0xABCDEF), printf("%X\n", 0xABCDEF));
    run_single_test("Hex Triple", ft_printf("%x %X %x\n", 100, 200, 300), printf("%x %X %x\n", 100, 200, 300));
    run_single_test("Hex Prefix check", ft_printf("0x%x\n", 42), printf("0x%x\n", 42));
    run_single_test("Hex End", ft_printf("Hex ends %X\n", 12345), printf("Hex ends %X\n", 12345));
}

static void test_percent(void)
{
    run_single_test("Percent Basic", ft_printf("%%\n"), printf("%%\n"));
    run_single_test("Percent Double", ft_printf("%%%%\n"), printf("%%%%\n"));
    run_single_test("Percent Triple", ft_printf("%%%%%%\n"), printf("%%%%%%\n"));
    run_single_test("Percent Text 1", ft_printf("100%%\n"), printf("100%%\n"));
    run_single_test("Percent Text 2", ft_printf("%% Complete\n"), printf("%% Complete\n"));
    run_single_test("Percent Text 3", ft_printf("Rate: 99.9%%\n"), printf("Rate: 99.9%%\n"));
    run_single_test("Percent Mix 1", ft_printf("%c%%\n", 'A'), printf("%c%%\n", 'A'));
    run_single_test("Percent Mix 2", ft_printf("%% %s\n", "test"), printf("%% %s\n", "test"));
    run_single_test("Percent Mix 3", ft_printf("%d%%\n", 50), printf("%d%%\n", 50));
    run_single_test("Percent Mix 4", ft_printf("%% %u\n", 10), printf("%% %u\n", 10));
    run_single_test("Percent Mix 5", ft_printf("%x%%\n", 15), printf("%x%%\n", 15));
    run_single_test("Percent Space", ft_printf(" %% \n"), printf(" %% \n"));
    run_single_test("Percent Bracket", ft_printf("[%%]\n"), printf("[%%]\n"));
    run_single_test("Percent Brace", ft_printf("{%%}\n"), printf("{%%}\n"));
    run_single_test("Percent Quad", ft_printf("%%%%%%%%\n"), printf("%%%%%%%%\n"));
    run_single_test("Percent Middle", ft_printf("start %% end\n"), printf("start %% end\n"));
    run_single_test("Percent Multi 1", ft_printf("%% and %%\n"), printf("%% and %%\n"));
    run_single_test("Percent Multi 2", ft_printf("%% %d %%\n", 42), printf("%% %d %%\n", 42));
    run_single_test("Percent Multi 3", ft_printf("%% %s %%\n", "hello"), printf("%% %s %%\n", "hello"));
    run_single_test("Percent Final", ft_printf("Final test%%\n"), printf("Final test%%\n"));
}

int main(void)
{
    printf("\n=========================================\n");
    printf("   %sSTARTING 160+ TESTS FOR FT_PRINTF%s    \n", CYAN, RESET);
    printf("=========================================\n\n");

    test_chars();
    test_strings();
    test_pointers();
    test_integers();
    test_unsigned();
    test_hex();
    test_percent();

    // Summary Output
    printf("\n=========================================\n");
    printf("              TEST SUMMARY               \n");
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