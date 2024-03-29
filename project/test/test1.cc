#include <cstdio>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#if 0

#define NGX_INT64_LEN (sizeof("-9223372036854775808") - 1) // 注释不会影响宏展开

int main(void)
{
    float f = 1.5;
    std::cout << f << std::endl;
    std::cout << (int)f << std::endl;
    std::cout << static_cast<int>(f) << std::endl;
    printf("%d\n", f);
    printf("%b\n", f);
    printf("len = %d\n", NGX_INT64_LEN);
    /*
        我一开始以为，他这个宏展开会变成这样：
        printf("len = %d\n", (sizeof("-9223372036854775808") - 1) // 注释不会影响宏展开);
        从而 这段注释 导致 括号不匹配。但好在编译器并不是这样操作的
    */
    u_char p[256] = { 0 };
    if (p < (u_char*)-1) {
        printf("asshole\n");
        printf("%p\n", p);
        printf("%p\n", (u_char*)-1);
    }
}

#else

int main(void)
{
    struct sockaddr* sa1;
    printf("&sockaddr::sa_data = %p\n", &sockaddr::sa_data);
    printf("&sockaddr::sa_family = %p", &sockaddr::sa_family);
    struct sockaddr_in sa2;
    printf("&sockaddr_in::sin_family = %p\n", &sockaddr_in::sin_family);
    printf("&sockaddr_in::sin_addr = %p\n", &sockaddr_in::sin_addr);
    printf("&sockaddr_in::sin_port = %p\n", &sockaddr_in::sin_port);
    printf("&sockaddr_in::sin_zero = %p\n", &sockaddr_in::sin_zero);
    printf("&sockaddr_in::sin_zero = %p\n", &sockaddr_in::sin_zero);
}

#endif
