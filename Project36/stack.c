#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_STACK_SIZE 100

char stack[MAX_STACK_SIZE];
int top = -1;

void push(char ch) {
    if (top < MAX_STACK_SIZE - 1) {
        stack[++top] = ch;
    }
}

char pop() {
    if (top > -1) {
        return stack[top--];
    }
    return;
}

int main() {
    char str[MAX_STACK_SIZE];
    printf("���ڿ��� �Է��ϼ���: ");
    fgets(str, MAX_STACK_SIZE, stdin);
    int len = strlen(str) - 1;

    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            push(tolower(str[i]));
        }
    }

    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            if (tolower(str[i]) != pop()) {
                printf("ȸ���� �ƴմϴ�.\n");
                return 0;
            }
        }
    }

    printf("ȸ���Դϴ�.\n");
    return 0;
}