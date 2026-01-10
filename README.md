# 🐚 Minishell

A minimalist **Unix shell** implementation — as beautiful as a shell — part of the 42/1337 curriculum.

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![42](https://img.shields.io/badge/School-42-black.svg)](https://42.fr)

## 📖 Description

**Minishell** is a simplified version of bash, implementing core shell functionalities from scratch. This project provides deep understanding of how shells work: process creation, command execution, file descriptors, and signal handling.

This project teaches:
- Lexical analysis and parsing
- Process creation with `fork()`
- Program execution with `execve()`
- File descriptor manipulation
- Pipe and redirection handling
- Signal management
- Environment variable handling

## 🎯 How a Shell Works

```
┌──────────────────────────────────────────────────────────────────┐
│                         SHELL LOOP                               │
└──────────────────────────────────────────────────────────────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │    Display Prompt   │
                    │      minishell$     │
                    └─────────────────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │    Read Input       │
                    │    (readline)       │
                    └─────────────────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │    Lexer/Tokenizer  │
                    │  "ls -la | grep a"  │
                    │         ↓           │
                    │  [ls][-la][|][grep] │
                    └─────────────────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │       Parser        │
                    │   Build AST/List    │
                    │   of commands       │
                    └─────────────────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │      Expander       │
                    │   $VAR → value      │
                    │   $? → exit status  │
                    └─────────────────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │      Executor       │
                    │  fork() + execve()  │
                    │  Handle pipes/redir │
                    └─────────────────────┘
                               │
                               ▼
                         Loop back ↺
```

## ✨ Features

### Command Execution
| Feature | Description | Example |
|---------|-------------|---------|
| ✅ Simple commands | Execute binaries from PATH | `ls -la` |
| ✅ Absolute/Relative paths | Direct path execution | `/bin/ls`, `./script.sh` |
| ✅ Command not found | Error handling | `asdf` → `command not found` |

### Built-in Commands
| Builtin | Description | Example |
|---------|-------------|---------|
| `echo` | Print text (with `-n` flag) | `echo -n "hello"` |
| `cd` | Change directory | `cd /home`, `cd ..`, `cd ~` |
| `pwd` | Print working directory | `pwd` |
| `export` | Set environment variable | `export VAR=value` |
| `unset` | Remove environment variable | `unset VAR` |
| `env` | Print environment | `env` |
| `exit` | Exit shell with status | `exit 42` |

### Redirections
| Operator | Description | Example |
|----------|-------------|---------|
| `>` | Redirect output (overwrite) | `echo "hi" > file.txt` |
| `>>` | Redirect output (append) | `echo "hi" >> file.txt` |
| `<` | Redirect input | `cat < file.txt` |
| `<<` | Here-document | `cat << EOF` |

### Pipes
| Feature | Description | Example |
|---------|-------------|---------|
| `\|` | Pipe output to next command | `ls \| grep .c` |
| Multiple pipes | Chain commands | `cat file \| grep a \| wc -l` |

### Environment & Expansion
| Feature | Description | Example |
|---------|-------------|---------|
| `$VAR` | Variable expansion | `echo $HOME` |
| `$?` | Last exit status | `echo $?` |
| `' '` | Single quotes (literal) | `echo '$HOME'` → `$HOME` |
| `" "` | Double quotes (expand $) | `echo "$HOME"` → `/home/user` |

### Signal Handling
| Signal | Interactive Mode | Execution Mode |
|--------|-----------------|----------------|
| `Ctrl+C` | New prompt | Terminate command |
| `Ctrl+D` | Exit shell | EOF |
| `Ctrl+\` | Ignored | Quit command |

## 🛠️ Installation

### Prerequisites

- GCC compiler
- Make
- Readline library

```bash
# Install readline on Debian/Ubuntu
sudo apt-get install libreadline-dev

# Install readline on macOS
brew install readline
```

### Build

```bash
# Clone the repository
git clone https://github.com/seg-fault0/minishell.git
cd minishell

# Compile
make

# Clean object files
make clean

# Full clean
make fclean

# Recompile
make re
```

## 🚀 Usage

```bash
./minishell
```

### Example Session

```bash
minishell$ echo "Hello, World!"
Hello, World!
minishell$ pwd
/home/user/minishell
minishell$ cd ..
minishell$ ls -la | grep minishell
drwxr-xr-x  8 user user  4096 Jan 10 12:00 minishell
minishell$ export MY_VAR="42 is awesome"
minishell$ echo $MY_VAR
42 is awesome
minishell$ cat << EOF
> This is a
> here document
> EOF
This is a
here document
minishell$ echo $?
0
minishell$ exit
```

## 📁 Project Structure

```
minishell/
├── Makefile
├── README.md
├── includes/
│   └── minishell.h
└── srcs/
    ├── main.c
    ├── lexer/
    │   ├── lexer.c
    │   ├── tokenizer.c
    │   └── token_utils.c
    ├── parser/
    │   ├── parser.c
    │   ├── syntax_check.c
    │   └── ast_builder.c
    ├── expander/
    │   ├── expander.c
    │   ├── variable_expansion.c
    │   └── quote_handling.c
    ├── executor/
    │   ├── executor.c
    │   ├── pipe_handler.c
    │   ├── redirection.c
    │   └── path_resolver.c
    ├── builtins/
    │   ├── echo.c
    │   ├── cd.c
    │   ├── pwd.c
    │   ├── export.c
    │   ├── unset.c
    │   ├── env.c
    │   └── exit.c
    ├── signals/
    │   └── signal_handler.c
    └── utils/
        ├── error.c
        ├── free.c
        └── utils.c
```

## 🔧 Technical Implementation

### Lexer (Tokenization)

```c
// Input: "ls -la | grep .c"
// Output: Linked list of tokens

typedef enum e_token_type
{
    TOKEN_WORD,      // ls, -la, grep, .c
    TOKEN_PIPE,      // |
    TOKEN_REDIR_IN,  // <
    TOKEN_REDIR_OUT, // >
    TOKEN_HEREDOC,   // <<
    TOKEN_APPEND,    // >>
}   t_token_type;

typedef struct s_token
{
    char            *value;
    t_token_type    type;
    struct s_token  *next;
}   t_token;
```

### Parser (Command Structure)

```c
typedef struct s_cmd
{
    char            **args;      // ["ls", "-la", NULL]
    char            *infile;     // Input redirection
    char            *outfile;    // Output redirection
    int             append;      // >> flag
    char            *heredoc;    // << delimiter
    struct s_cmd    *next;       // Next command (pipe)
}   t_cmd;
```

### Execution Pipeline

```c
// For: cmd1 | cmd2 | cmd3
//
//  ┌──────┐    pipe1    ┌──────┐    pipe2    ┌──────┐
//  │ cmd1 │ ──────────► │ cmd2 │ ──────────► │ cmd3 │
//  └──────┘   [0][1]    └──────┘   [0][1]    └──────┘
//                                                │
//                                                ▼
//                                             STDOUT

void execute_pipeline(t_cmd *cmd)
{
    int pipefd[2];
    int prev_fd = STDIN_FILENO;
    
    while (cmd)
    {
        if (cmd->next)
            pipe(pipefd);
        
        pid_t pid = fork();
        if (pid == 0)
        {
            // Child process
            if (prev_fd != STDIN_FILENO)
            {
                dup2(prev_fd, STDIN_FILENO);
                close(prev_fd);
            }
            if (cmd->next)
            {
                dup2(pipefd[1], STDOUT_FILENO);
                close(pipefd[0]);
                close(pipefd[1]);
            }
            execve(cmd->path, cmd->args, env);
        }
        // Parent process
        if (prev_fd != STDIN_FILENO)
            close(prev_fd);
        if (cmd->next)
        {
            close(pipefd[1]);
            prev_fd = pipefd[0];
        }
        cmd = cmd->next;
    }
    wait_for_children();
}
```

## 🧪 Testing

### Basic Commands

```bash
# Simple execution
ls
ls -la
/bin/ls

# Builtins
echo hello world
echo -n "no newline"
pwd
cd /tmp && pwd
export TEST=123 && echo $TEST
env | grep TEST
unset TEST
```

### Redirections

```bash
# Output
echo "hello" > test.txt
cat test.txt
echo "world" >> test.txt
cat test.txt

# Input
cat < test.txt
wc -l < test.txt

# Here-document
cat << END
line 1
line 2
END
```

### Pipes

```bash
ls | wc -l
cat /etc/passwd | grep root | cut -d: -f1
echo "hello world" | tr ' ' '\n' | sort
```

### Quotes & Expansion

```bash
echo "Hello $USER"
echo 'Hello $USER'
echo "Exit status: $?"
echo "$HOME/test"
echo '$HOME/test'
```

### Edge Cases

```bash
# Empty input
(just press enter)

# Only spaces
     

# Unclosed quotes (should wait for closing)
echo "hello

# Non-existent command
asdfghjkl

# Permission denied
./non_executable_file

# Ctrl+C, Ctrl+D, Ctrl+\
```

## ⚠️ Error Handling

| Error | Message |
|-------|---------|
| Command not found | `minishell: cmd: command not found` |
| Permission denied | `minishell: ./file: Permission denied` |
| No such file | `minishell: file: No such file or directory` |
| Syntax error | `minishell: syntax error near unexpected token` |
| Too many arguments | `minishell: exit: too many arguments` |
| Numeric argument required | `minishell: exit: abc: numeric argument required` |

## 📚 Allowed Functions

| Category | Functions |
|----------|-----------|
| **Readline** | `readline`, `rl_clear_history`, `rl_on_new_line`, `rl_replace_line`, `rl_redisplay`, `add_history` |
| **Memory** | `malloc`, `free` |
| **I/O** | `printf`, `write`, `read`, `open`, `close` |
| **Process** | `fork`, `wait`, `waitpid`, `wait3`, `wait4`, `execve`, `exit` |
| **Signals** | `signal`, `sigaction`, `sigemptyset`, `sigaddset`, `kill` |
| **File** | `access`, `stat`, `lstat`, `fstat`, `unlink`, `opendir`, `readdir`, `closedir` |
| **Descriptors** | `dup`, `dup2`, `pipe` |
| **Directory** | `getcwd`, `chdir` |
| **Environment** | `getenv` |
| **Terminal** | `isatty`, `ttyname`, `ttyslot`, `ioctl`, `tcsetattr`, `tcgetattr` |
| **Error** | `strerror`, `perror` |
| **Termcap** | `tgetent`, `tgetflag`, `tgetnum`, `tgetstr`, `tgoto`, `tputs` |

## 📖 Resources

- [Bash Reference Manual](https://www.gnu.org/software/bash/manual/bash.html)
- [Writing Your Own Shell](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)
- [Shell Command Language - POSIX](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html)

## 👥 Team

| Contributor | GitHub |
|-------------|--------|
| **seg-fault0** | [@seg-fault0](https://github.com/seg-fault0) |
| **Zouhair Grir** | [@GrirZouhair](https://github.com/GrirZouhair) |

42 Intra: zogrir

## 📄 License

This project is part of the 42 school curriculum.

---

*Made with ❤️ at 42/1337*
