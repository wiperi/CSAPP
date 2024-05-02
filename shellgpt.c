#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024 // 最大命令行长度
#define MAX_ARGS 128         // 最大参数数量

/* 函数声明 */
void evaluate_command_line(char* command_line);
int parse_command_line(char* command_line, char** arguments);
int is_builtin_command(char** arguments);

int main() {
    char command_line[MAX_LINE_LENGTH]; // 命令行

    while (1) {
        // 读取命令行
        printf("> ");
        fgets(command_line, MAX_LINE_LENGTH, stdin);
        if (feof(stdin))
            exit(0);

        // 评估并执行命令
        evaluate_command_line(command_line);
    }
}

/* 评估命令行 */
void evaluate_command_line(char* command_line) {
    char* arguments[MAX_ARGS];                   // 参数列表
    char modified_command_line[MAX_LINE_LENGTH]; // 修改后的命令行
    int is_background;                           // 是否在后台运行
    pid_t process_id;                            // 进程ID

    strcpy(modified_command_line, command_line);
    is_background = parse_command_line(modified_command_line, arguments);
    if (arguments[0] == NULL)
        return; // 忽略空行

    if (!is_builtin_command(arguments)) {
        if ((process_id = fork()) == 0) { // 子进程运行用户命令
            if (execvp(arguments[0], arguments) < 0) {
                printf("%s: Command not found.\n", arguments[0]);
                exit(0);
            }
        }

        /* 父进程等待前台作业结束 */
        if (!is_background) {
            int status;
            if (waitpid(process_id, &status, 0) < 0)
                perror("waitpid error");
        } else
            printf("%d %s", process_id, command_line);
    }
}

/* 解析命令行并构建参数列表 */
int parse_command_line(char* command_line, char** arguments) {
    char* delimiter;        // 指向第一个空格分隔符
    int argument_count = 0; // 参数数量
    int is_background = 0;  // 后台作业？

    command_line[strlen(command_line) - 1] = ' ';   // 将末尾的'\n'替换为空格
    while (*command_line && (*command_line == ' ')) // 忽略前导空格
        command_line++;

    /* 构建参数列表 */
    while ((delimiter = strchr(command_line, ' '))) {
        arguments[argument_count++] = command_line;
        *delimiter = '\0';
        command_line = delimiter + 1;
        while (*command_line && (*command_line == ' ')) // 忽略空格
            command_line++;
    }
    arguments[argument_count] = NULL;

    if (argument_count == 0) // 忽略空行
        return 1;

    /* 是否在后台运行作业？ */
    if ((is_background = (*arguments[argument_count - 1] == '&')) != 0)
        arguments[--argument_count] = NULL;

    return is_background;
}

/* 如果第一个参数是内置命令，执行它并返回true */
int is_builtin_command(char** arguments) {
    if (!strcmp(arguments[0], "quit")) // quit命令
        exit(0);
    if (!strcmp(arguments[0], "&")) // 忽略单个 &
        return 1;
    return 0; // 不是内置命令
}
